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
#pragma message "            Inside EncoderH264.cpp"
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
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::codecs::EncoderH264::~EncoderH264(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::codecs::EncoderH264::Constructor(bool runFather){
    if(runFather){
        edk::codecs::EncoderVideo::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;
#ifdef EDK_USE_OPENH264
        this->encoder=NULL;edkEnd();
        this->version = WelsGetCodecVersion();edkEnd();
#else
        edkPrintf("You must define EDK_USE_OPENH264 before use");edkEnd();
#endif
    }
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
                this->param.iUsageType = CAMERA_VIDEO_REAL_TIME;edkEnd();
                this->param.iPicWidth = size.width;edkEnd();
                this->param.iPicHeight = size.height;edkEnd();
                this->param.iTargetBitrate = rand() + 1;edkEnd(); // !=0
                // Force a bitrate of at least w*h/50, otherwise we will only get skipped frames
                /*
                this->param.iTargetBitrate = WELS_CLIP3 (this->param.iTargetBitrate,
                                                         this->param.iPicWidth * this->param.iPicHeight / 50, 100000000);edkEnd();
                int32_t iLevelMaxBitrate = WelsCommon::g_ksLevelLimits[LEVEL_5_0 - 1].uiMaxBR * CpbBrNalFactor;edkEnd();
                if(this->param.iTargetBitrate > iLevelMaxBitrate){
                    this->param.iTargetBitrate = iLevelMaxBitrate;edkEnd();
                    }
                */

                this->param.iTargetBitrate = 50000;

                this->param.iRCMode = RC_BITRATE_MODE;edkEnd();
                //use the FPS
                this->param.fMaxFrameRate = (edk::float32)1/fps;edkEnd(); //!=0

                //start the encoder
                if(!encoder->Initialize(&param)){
                    this->setNextKeyframe();edkEnd();
                    return true;
                }
            }
        }
#else
        edkPrintf("You must define EDK_USE_OPENH264 before use");edkEnd();
#endif
        //finish encoder
        edk::codecs::EncoderVideo::finishEncoder();edkEnd();
    }
    return false;
}
bool edk::codecs::EncoderH264::startEncoder(edk::uint32 width, edk::uint32 height, edk::uint32 fps){
    return this->startEncoder(edk::size2ui32(width,height),fps);
}

//process the encoder
bool edk::codecs::EncoderH264::encode(edk::uint8* frame,edk::uint8 channels){
    if(edk::codecs::EncoderVideo::encode(frame,channels)){
#ifdef EDK_USE_OPENH264
        if(this->encoder){
            //clean the encoded
            this->writeEncoded(NULL,0);edkEnd();
            edk::int32 iLayerSize = 0;
            edk::int32 iNalIdx = 0;
            //draw the frame
            if(this->drawFrame(frame,channels)){
                this->pic.iColorFormat = videoFormatI420;

                this->pic.uiTimeStamp = 0;
                this->pic.iPicWidth = this->getFrameSize().width;edkEnd();
                this->pic.iPicHeight = this->getFrameSize().height;edkEnd();
                this->pic.iPicWidth = VALID_SIZE (pic.iPicWidth);edkEnd();
                this->pic.iPicHeight = VALID_SIZE (pic.iPicHeight);edkEnd();
                //passa as proporcoes de cada canal pela largura
                this->pic.iStride[3] = 0u;edkEnd();
                this->pic.iStride[0] = this->getFrameSize().width;edkEnd();
                this->pic.iStride[1] = pic.iStride[2] = pic.iStride[0] >> 1;edkEnd();

                this->pic.pData[0u] = this->getFrameY();edkEnd();
                this->pic.pData[1u] = this->getFrameU();edkEnd();
                this->pic.pData[2u] = this->getFrameV();edkEnd();
                this->pic.pData[3u] = NULL;edkEnd();

                //clean the fbi
                memset (&this->sFbi, 0, sizeof (SFrameBSInfo));edkEnd();

                if(this->isNextKeyframe()){
                    this->encoder->ForceIntraFrame(true);edkEnd();
                }
                else{
                    int32_t iTraceLevel = WELS_LOG_QUIET;
                    this->encoder->SetOption(ENCODER_OPTION_IDR_INTERVAL, &iTraceLevel);
                }

                if(!this->encoder->EncodeFrame(&this->pic,&this->sFbi)){
                    SLayerBSInfo* pLayerBsInfo = NULL;edkEnd();
                    //test if can copy the encoded
                    if((edk::int32)this->getSpaceEncodedSize() < this->sFbi.iFrameSizeInBytes){
                        //alloc the frame encoded
                        this->newSpaceEncoded(this->sFbi.iFrameSizeInBytes+1u);edkEnd();
                    }
                    if((edk::int32)this->getSpaceEncodedSize() > this->sFbi.iFrameSizeInBytes){
                        for(edk::uint32 i=0u;i<(edk::uint32)this->sFbi.iLayerNum;i++){
                            //
                            pLayerBsInfo = &sFbi.sLayerInfo[i];edkEnd();
                            if(pLayerBsInfo != NULL){

                                iLayerSize = 0;
                                iNalIdx = pLayerBsInfo->iNalCount - 1;edkEnd();
                                //increment the layer size
                                do{
                                    iLayerSize += pLayerBsInfo->pNalLengthInByte[iNalIdx];edkEnd();
                                    -- iNalIdx;edkEnd();
                                }while (iNalIdx >= 0);edkEnd();

                                //copy the layer
                                this->appendEncoded(pLayerBsInfo->pBsBuf,iLayerSize);edkEnd();
                            }
                        }
                        return true;
                    }
                }
            }
        }
#else
        edkPrintf("You must define EDK_USE_OPENH264 before use");edkEnd();
#endif
    }
    return false;
}

//finish the encoder
void edk::codecs::EncoderH264::finishEncoder(){
    edk::codecs::EncoderVideo::finishEncoder();edkEnd();

#ifdef EDK_USE_OPENH264
    if(this->encoder){
        //unitialize
        this->encoder->Uninitialize();edkEnd();
    }

    WelsDestroySVCEncoder(this->encoder);edkEnd();
    this->encoder=NULL;edkEnd();
#else
    edkPrintf("You must define EDK_USE_OPENH264 before use");edkEnd();
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
    edkPrintf("You must define EDK_USE_OPENH264 before use");edkEnd();
#endif
    return false;
}

