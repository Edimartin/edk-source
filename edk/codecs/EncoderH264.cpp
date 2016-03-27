#include "EncoderH264.h"

/*
Library C++ EncoderH264 - Encode a frame to H264
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#ifdef printMessages
#warning "            Inside EncoderH264.cpp"
#endif

#ifdef EDK_USE_OPENH264
#define MB_SIZE (16)
#define MAX_WIDTH (3840)
#define MAX_HEIGHT (2160)
#define VALID_SIZE(iSize) (((iSize)>16)?(iSize):16)
#define MEM_VARY_SIZE (512)
#define IMAGE_VARY_SIZE (512)
#define TEST_FRAMES (30)

#define NAL_HEADER_BYTES (4)
#define NAL_TYPE (0x0F)
#define SPS_NAL_TYPE (7)
#define PPS_NAL_TYPE (8)
#define SUBSETSPS_NAL_TYPE (15)
#define GET_NAL_TYPE(pNalStart) (*(pNalStart+NAL_HEADER_BYTES) & NAL_TYPE)
#define IS_PARASET(iNalType) ((iNalType==SPS_NAL_TYPE) || (iNalType==PPS_NAL_TYPE) || (iNalType==SUBSETSPS_NAL_TYPE))
#endif

edk::codecs::EncoderH264::EncoderH264(){
    //
#ifdef EDK_USE_OPENH264
    this->encoder=NULL;
    this->version = WelsGetCodecVersion();
#else
        edk_printDebug("You must define EDK_USE_OPENH264 before use");
#endif
}
edk::codecs::EncoderH264::~EncoderH264(){
    //
}

//start the encoder
bool edk::codecs::EncoderH264::startEncoder(edk::size2ui32 size, edk::uint32 fps){
    if(edk::codecs::EncoderVideo::startEncoder(size, fps)){
        //start the encoder
#ifdef EDK_USE_OPENH264
        if(!WelsCreateSVCEncoder(&this->encoder)){
            if(this->encoder){
                //
                //start the parameters
                this->param.iUsageType = CAMERA_VIDEO_REAL_TIME;
                this->param.iPicWidth = size.width;
                this->param.iPicHeight = size.height;
                this->param.iTargetBitrate = rand() + 1; // !=0
                // Force a bitrate of at least w*h/50, otherwise we will only get skipped frames
                this->param.iTargetBitrate = WELS_CLIP3 (this->param.iTargetBitrate,
                                                         this->param.iPicWidth * this->param.iPicHeight / 50, 100000000);
                int32_t iLevelMaxBitrate = WelsCommon::g_ksLevelLimits[LEVEL_5_0 - 1].uiMaxBR * CpbBrNalFactor;
                if (this->param.iTargetBitrate > iLevelMaxBitrate)
                    this->param.iTargetBitrate = iLevelMaxBitrate;

                this->param.iRCMode = RC_BITRATE_MODE;
                //use the FPS
                this->param.fMaxFrameRate = fps; //!=0

                //start the encoder
                if(!encoder->Initialize(&param)){
                    this->setNextkeyframe();
                    return true;
                }
            }
        }
#else
        edk_printDebug("You must define EDK_USE_OPENH264 before use");
#endif
        //finish encoder
        edk::codecs::EncoderVideo::finishEncoder();
    }
    return false;
}

//process the encoder
bool edk::codecs::EncoderH264::encode(edk::uint8* frame,edk::uint8 channels){
    if(edk::codecs::EncoderVideo::encode(frame,channels)){
#ifdef EDK_USE_OPENH264
        if(this->encoder){
            //clean the encoded
            this->writeEncoded(NULL,0);
            int iLayerSize = 0;
            int iNalIdx = 0;
            //draw the frame
            if(this->drawFrame(frame,channels)){
                this->pic.iColorFormat = videoFormatI420;

                this->pic.uiTimeStamp = 0;
                this->pic.iPicWidth = this->getFrameSize().width;
                this->pic.iPicHeight = this->getFrameSize().height;
                this->pic.iPicWidth = VALID_SIZE (pic.iPicWidth);
                this->pic.iPicHeight = VALID_SIZE (pic.iPicHeight);
                //passa as proporcoes de cada canal pela largura
                this->pic.iStride[3] = 0u;
                this->pic.iStride[0] = this->getFrameSize().width;
                this->pic.iStride[1] = pic.iStride[2] = pic.iStride[0] >> 1;

                this->pic.pData[0u] = this->getFrameY();
                this->pic.pData[1u] = this->getFrameU();
                this->pic.pData[2u] = this->getFrameV();
                this->pic.pData[3u] = NULL;

                //clean the fbi
                memset (&this->sFbi, 0, sizeof (SFrameBSInfo));

                if(this->isNextKeyframe()){
                    printf("\nFORCE NEXT");fflush(stdout);
                    encoder->ForceIntraFrame(true);
                }

                if(!encoder->EncodeFrame(&this->pic,&this->sFbi)){
                    SLayerBSInfo* pLayerBsInfo = NULL;
                    //test if can copy the encoded
                    if((int)this->getSpaceEncodedSize() < this->sFbi.iFrameSizeInBytes){
                        //alloc the frame encoded
                        this->newSpaceEncoded(this->sFbi.iFrameSizeInBytes+1u);
                    }
                    if((int)this->getSpaceEncodedSize() > this->sFbi.iFrameSizeInBytes){
                        for(edk::uint32 i=0u;i<(edk::uint32)this->sFbi.iLayerNum;i++){
                            //
                            pLayerBsInfo = &sFbi.sLayerInfo[i];
                            if (pLayerBsInfo != NULL){

                                iLayerSize = 0;
                                iNalIdx = pLayerBsInfo->iNalCount - 1;
                                //increment the layer size
                                do{
                                    iLayerSize += pLayerBsInfo->pNalLengthInByte[iNalIdx];
                                    -- iNalIdx;
                                }while (iNalIdx >= 0);

                                //copy the layer
                                this->appendEncoded(pLayerBsInfo->pBsBuf,iLayerSize);
                            }
                        }
                        return true;
                    }
                }
            }
        }
#else
        edk_printDebug("You must define EDK_USE_OPENH264 before use");
#endif
    }
    return false;
}

//finish the encoder
void edk::codecs::EncoderH264::finishEncoder(){
    edk::codecs::EncoderVideo::finishEncoder();

#ifdef EDK_USE_OPENH264
    //unitialize
    this->encoder->Uninitialize();

    WelsDestroySVCEncoder(this->encoder);
    this->encoder=NULL;
#else
        edk_printDebug("You must define EDK_USE_OPENH264 before use");
#endif
}

