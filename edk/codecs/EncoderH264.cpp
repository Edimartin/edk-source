#include "EncoderH264.h"

/*
Library C++ EncoderH264 - Encode a frame to H264
Copyright 2013 Eduardo Moura Sales Martins (edimartin@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
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
                /*
                this->param.iTargetBitrate = WELS_CLIP3 (this->param.iTargetBitrate,
                                                         this->param.iPicWidth * this->param.iPicHeight / 50, 100000000);
                int32_t iLevelMaxBitrate = WelsCommon::g_ksLevelLimits[LEVEL_5_0 - 1].uiMaxBR * CpbBrNalFactor;
                if (this->param.iTargetBitrate > iLevelMaxBitrate)
                    this->param.iTargetBitrate = iLevelMaxBitrate;
                */

                this->param.iTargetBitrate = 50000;

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
            edk::int32 iLayerSize = 0;
            edk::int32 iNalIdx = 0;
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
                    encoder->ForceIntraFrame(true);
                }

                if(!encoder->EncodeFrame(&this->pic,&this->sFbi)){
                    SLayerBSInfo* pLayerBsInfo = NULL;
                    //test if can copy the encoded
                    if((edk::int32)this->getSpaceEncodedSize() < this->sFbi.iFrameSizeInBytes){
                        //alloc the frame encoded
                        this->newSpaceEncoded(this->sFbi.iFrameSizeInBytes+1u);
                    }
                    if((edk::int32)this->getSpaceEncodedSize() > this->sFbi.iFrameSizeInBytes){
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
    if(this->encoder){
        //unitialize
        this->encoder->Uninitialize();
    }

    WelsDestroySVCEncoder(this->encoder);
    this->encoder=NULL;
#else
        edk_printDebug("You must define EDK_USE_OPENH264 before use");
#endif
}

//return true if have load the encoder
bool edk::codecs::EncoderH264::haveInitialized(){
#ifdef EDK_USE_OPENH264
    if(this->encoder){
        //unitialize
        return true;
    }
#else
        edk_printDebug("You must define EDK_USE_OPENH264 before use");
#endif
    return false;
}

