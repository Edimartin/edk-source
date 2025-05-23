#include "DecoderH264.h"

/*
Library C++ DecoderH264 - Decode a frame to H264
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
#pragma message "            Inside DecoderH264.cpp"
#endif

edk::codecs::DecoderH264::DecoderH264(){
    this->classThis=NULL;
    this->Constructor();
}
edk::codecs::DecoderH264::~DecoderH264(){
    this->Destructor();
}

void edk::codecs::DecoderH264::Constructor(){
    edk::codecs::DecoderVideo::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
#ifdef EDK_USE_OPENH264
        this->decoder=NULL;
        this->version = WelsGetCodecVersion();
#else
        edkPrintf("You must define EDK_USE_OPENH264 before use");
#endif
    }
}
void edk::codecs::DecoderH264::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
    edk::codecs::DecoderVideo::Destructor();
}

//convert the frame with border
bool edk::codecs::DecoderH264::i420TorgbWithBorder(edk::uint8* y,edk::uint8* u,edk::uint8* v,edk::size2ui32 size,edk::uint8* rgb,edk::uint32 border){
    if(rgb && size.width && size.height && y && u && v){
        edk::float32 r,g,b;
#if defined(edkCPPversion17)
        edk::uint32 i=0u;
        edk::uint32 j=0u;
#else
        register edk::uint32 i=0u;
        register edk::uint32 j=0u;
#endif
        edk::uint32 borderFour = border>>1u;
        //the image is aways width and height even
        for(i=0u;i<size.height;i+=2u){
            for(j=0u;j<size.width;j+=2u){
                r = *y + 1.4075 *                        (*v - 128) ;
                g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                b = *y + 1.7790 * (*u - 128);
                if(r<0){
                    r=0;
                }
                else if(r>255){
                    r=255;
                }
                if(g<0){
                    g=0;
                }
                else if(g>255){
                    g=255;
                }
                if(b<0){
                    b=0;
                }
                else if(b>255){
                    b=255;
                }

                rgb[0u]=(edk::uint8)r;
                rgb[1u]=(edk::uint8)g;
                rgb[2u]=(edk::uint8)b;

                //increment the rgb and y
                rgb+=3u;
                y++;

                r = *y + 1.4075 *                        (*v - 128) ;
                g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                b = *y + 1.7790 * (*u - 128);
                if(r<0){
                    r=0;
                }
                else if(r>255){
                    r=255;
                }
                if(g<0){
                    g=0;
                }
                else if(g>255){
                    g=255;
                }
                if(b<0){
                    b=0;
                }
                else if(b>255){
                    b=255;
                }

                rgb[0u]=(edk::uint8)r;
                rgb[1u]=(edk::uint8)g;
                rgb[2u]=(edk::uint8)b;

                //increment the rgb and y
                rgb+=3u;
                y++;
                //increment the u v
                u++;
                v++;
            }
            //remove the y border
            y+=border;
            //decrement the uv
            u-=size.width>>1;
            v-=size.width>>1;
            for(j=0u;j<size.width;j+=2u){
                r = *y + 1.4075 *                        (*v - 128) ;
                g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                b = *y + 1.7790 * (*u - 128);
                if(r<0){
                    r=0;
                }
                else if(r>255){
                    r=255;
                }
                if(g<0){
                    g=0;
                }
                else if(g>255){
                    g=255;
                }
                if(b<0){
                    b=0;
                }
                else if(b>255){
                    b=255;
                }

                rgb[0u]=(edk::uint8)r;
                rgb[1u]=(edk::uint8)g;
                rgb[2u]=(edk::uint8)b;

                //increment the rgb and the y
                rgb+=3u;
                y++;

                r = *y + 1.4075 *                        (*v - 128) ;
                g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                b = *y + 1.7790 * (*u - 128);
                if(r<0){
                    r=0;
                }
                else if(r>255){
                    r=255;
                }
                if(g<0){
                    g=0;
                }
                else if(g>255){
                    g=255;
                }
                if(b<0){
                    b=0;
                }
                else if(b>255){
                    b=255;
                }

                rgb[0u]=(edk::uint8)r;
                rgb[1u]=(edk::uint8)g;
                rgb[2u]=(edk::uint8)b;

                //increment the rgb and the y
                rgb+=3u;
                y++;
                //increment the u v
                u++;
                v++;
            }
            //remove the y border
            y+=border;
            //remove the uv border
            u+=borderFour;
            v+=borderFour;
        }
        return true;
    }
    return false;
}

//start the encoder
bool edk::codecs::DecoderH264::startDecoder(edk::uint32 spaceDecodeSize){
    if(edk::codecs::DecoderVideo::startDecoder(spaceDecodeSize)){
#ifdef EDK_USE_OPENH264
        if(!WelsCreateDecoder(&this->decoder)){
            if(this->decoder){
                //initialize the openH264 decoder
                memset(&this->param,0,sizeof(this->param));

                {
                    this->param.sVideoProperty.size = sizeof (param.sVideoProperty);
                    this->param.pFileNameRestructed=NULL;
                    //this->param.eOutputColorFormat = videoFormatI420;
                    this->pic.iColorFormat = videoFormatI420;
                    this->param.uiCpuLoad = rand() % 100;
                    this->param.uiTargetDqLayer = rand() % 100;
                    this->param.eEcActiveIdc = (ERROR_CON_IDC) (rand() & 7);
                    this->param.sVideoProperty.size = sizeof (SVideoProperty);
                    this->param.sVideoProperty.eVideoBsType = (VIDEO_BITSTREAM_TYPE) (rand() % 3);
                }

                //inicializa o decoder
                if(!this->decoder->Initialize(&this->param)){
                    //
                    return true;
                }
            }
        }
#else
        edkPrintf("You must define EDK_USE_OPENH264 before use");
#endif
    }
    return false;
}

//process the decoder
bool edk::codecs::DecoderH264::decode(edk::uint8* encoded,edk::uint32 size){
    if(edk::codecs::DecoderVideo::decode(encoded,size)){
#ifdef EDK_USE_OPENH264
        if(this->decoder){
            edk::uint32 width=0u,height=0u,border=0u;

            //clean the buffer info
            memset(&this->m_sBufferInfo, 0, sizeof (SBufferInfo));
            //process the decode

            if(!decoder->DecodeFrameNoDelay(encoded, size, this->pic.pData, &this->m_sBufferInfo)){

                //if(!decoder->DecodeFrame2(this->getEncoded(), this->getEncodedUsedSize(), this->pic.pData, &this->m_sBufferInfo)){

                if(m_sBufferInfo.iBufferStatus == 1){
                    //copy the frame
                    width = m_sBufferInfo.UsrData.sSystemBuffer.iWidth;
                    height = m_sBufferInfo.UsrData.sSystemBuffer.iHeight;

                    //get the border
                    border = m_sBufferInfo.UsrData.sSystemBuffer.iStride[0u] - width;
                    //create the frame RGB
                    if(this->newFrame(width,height,3u)){
                        //convert the i420 frame for RGB
                        this->i420TorgbWithBorder(pic.pData[0u],pic.pData[1u],pic.pData[2u],edk::size2ui32(width,height),this->getFrame(),border);
                        return true;
                    }
                }
            }
        }
#else
        edkPrintf("You must define EDK_USE_OPENH264 before use");
#endif
    }
    return false;
}

//finish the encoder
void edk::codecs::DecoderH264::finishDecoder(){
    //
    edk::codecs::DecoderVideo::finishDecoder();
#ifdef EDK_USE_OPENH264
    if(this->decoder){
        //unitialize
        this->decoder->Uninitialize();
    }

    WelsDestroyDecoder(this->decoder);
    this->decoder = NULL;
#else
    edkPrintf("You must define EDK_USE_OPENH264 before use");
#endif
}

//return true if have load the encoder
bool edk::codecs::DecoderH264::haveInitialized(){
#ifdef EDK_USE_OPENH264
    if(this->decoder){
        //unitialize
        return true;
    }
#else
    edkPrintf("You must define EDK_USE_OPENH264 before use");
#endif
    return false;
}


