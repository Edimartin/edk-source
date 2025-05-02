#include "VideoEDK.h"

/*
Library Audio - Play video using openH264
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

edk::video::VideoEDK::VideoEDK(edk::video::EDKcodecName codec){
    this->classThis=NULL;
    this->Constructor(codec);
}
edk::video::VideoEDK::~VideoEDK(){
    this->Destructor();
}

//remove the last coded
void edk::video::VideoEDK::removeCodec(){
    if(*this->haveEnc){
        this->finishEncoder();
    }
    if(*this->haveDec){
        this->finishDecoder();
    }
}

//CODEC FUNCTIONS
//H264
bool edk::video::VideoEDK::startEncoderH264(edk::uint32 width,
                                            edk::uint32 height,
                                            edk::uint32 channels,
                                            edk::float32 fps
                                            ){
    if(channels==3u){
        this->haveEncH264 = this->encH264.startEncoder(width,height,(edk::uint32)fps);
        return this->haveEncH264;
    }
    return false;
}
bool edk::video::VideoEDK::encodeFrameH264(edk::uint8* vector,
                                           edk::uint64 lenght,
                                           edk::uint8 channels,
                                           edk::MemoryBuffer<edk::uint8>* bufferWrite,
                                           bool keyFrame
                                           ){
    if(this->haveEncH264){
        if(vector && lenght && channels && bufferWrite){
            //encode the frame
            if(keyFrame){
                this->encH264.setNextKeyframe();
            }
            if(this->encH264.encode(vector,channels)){
                //read the encoded
                return bufferWrite->pushToBuffer(this->encH264.getEncoded(),this->encH264.getEncodedUsedSize());
            }
        }
    }
    return false;
}
void edk::video::VideoEDK::finishEncoderH264(){
    this->haveEncH264=false;
    this->encH264.finishEncoder();
}
bool edk::video::VideoEDK::startDecoderH264(){
    this->frameIDH264=0u;
    this->haveDecH264 = this->decH264.startDecoder(1024u*1024u*3u);
    return this->haveDecH264;
}
bool edk::video::VideoEDK::canDecodeFrameH264(edk::uint32 frameID){
    if(frameID <= this->frameIDH264){
        this->frameIDH264++;
        return true;
    }
    return false;
}
bool edk::video::VideoEDK::decodeFrameH264(edk::MemoryBuffer<edk::uint8>* bufferRead,
                                           edk::uint32* width,
                                           edk::uint32* height,
                                           edk::uint8* channels
                                           ){
    if(this->haveDecH264){
        this->mutDecoder.lock();
        if(bufferRead && width && height && channels){
            //
            if(this->decH264.decode((edk::uint8*)bufferRead->getPointer(),bufferRead->size())){
                *width = this->decH264.getFrameWidth();
                *height = this->decH264.getFrameHeight();
                *channels = this->decH264.getFrameChannels();
                if(*width && *height && *channels){
                    this->mutDecoder.unlock();
                    return true;
                }
            }
        }
        this->mutDecoder.unlock();
    }
    return false;
}
bool edk::video::VideoEDK::copyDecodedFrameH264(edk::MemoryBuffer<edk::uint8>* bufferDest){
    if(this->haveDecH264){
        if(bufferDest){
            if(this->decH264.getFrame()
                    && this->decH264.getFrameWidth()
                    && this->decH264.getFrameHeight()
                    && this->decH264.getFrameChannels()
                    ){
                return bufferDest->pushToBuffer(this->decH264.getFrame(),
                                                this->decH264.getFrameWidth()
                                                * this->decH264.getFrameHeight()
                                                * this->decH264.getFrameChannels()
                                                );
            }
        }
    }
    return false;
}
void edk::video::VideoEDK::finishDecoderH264(){
    this->frameIDH264=0u;
    this->haveDecH264=false;
    this->decH264.finishDecoder();
}
//JPEG
bool edk::video::VideoEDK::startEncoderJPEG(edk::uint32 width,
                                            edk::uint32 height,
                                            edk::uint32 channels,
                                            edk::float32 /*fps*/
                                            ){
    if(channels==3u && width && height){
        return this->haveEncJPEG=true;
    }
    return false;
}
bool edk::video::VideoEDK::encodeFrameJPEG(edk::uint8* vector,
                                           edk::uint64 lenght,
                                           edk::uint8 channels,
                                           edk::MemoryBuffer<edk::uint8>* bufferWrite,
                                           bool /*keyFrame*/
                                           ){
    if(vector && lenght && channels && bufferWrite){
        //encode the frame
        this->mutDecoder.lock();
        if(this->encJPEG.encode(vector,
                                this->getWidth(),
                                this->getHeight(),
                                this->getChannels(),
                                90u
                                )
                ){
            //read the encoded
            this->mutDecoder.unlock();
            return bufferWrite->pushToBuffer(this->encJPEG.getEncoded(),this->encJPEG.getEncodedSize());
        }
        this->mutDecoder.unlock();
    }
    return false;
}
void edk::video::VideoEDK::finishEncoderJPEG(){
    this->haveEncJPEG=false;
}
bool edk::video::VideoEDK::startDecoderJPEG(){
    return this->haveDecJPEG=true;
}
bool edk::video::VideoEDK::canDecodeFrameJPEG(edk::uint32 /*frameID*/){
    return true;
}
bool edk::video::VideoEDK::decodeFrameJPEG(edk::MemoryBuffer<edk::uint8>* bufferRead,
                                           edk::uint32* width,
                                           edk::uint32* height,
                                           edk::uint8* channels
                                           ){
    if(bufferRead && width && height && channels){
        //
        if(this->decJPEG.decode((edk::uint8*)bufferRead->getPointer(),bufferRead->size())){
            *width = this->decJPEG.getFrameWidth();
            *height = this->decJPEG.getFrameHeight();
            *channels = this->decJPEG.getFrameChannels();
            if(*width && *height && *channels){
                return true;
            }
        }
    }
    return false;
}
bool edk::video::VideoEDK::copyDecodedFrameJPEG(edk::MemoryBuffer<edk::uint8>* bufferDest){
    if(bufferDest){
        if(this->decJPEG.getFrame()
                && this->decJPEG.getFrameWidth()
                && this->decJPEG.getFrameHeight()
                && this->decJPEG.getFrameChannels()
                ){
            return bufferDest->pushToBuffer(this->decJPEG.getFrame(),
                                            this->decJPEG.getFrameWidth()
                                            * this->decJPEG.getFrameHeight()
                                            * this->decJPEG.getFrameChannels()
                                            );
        }
    }
    return false;
}
void edk::video::VideoEDK::finishDecoderJPEG(){
    this->haveDecJPEG=false;
}
//RGB
bool edk::video::VideoEDK::startEncoderRGB(edk::uint32 width,
                                           edk::uint32 height,
                                           edk::uint32 channels,
                                           edk::float32 /*fps*/
                                           ){
    if(channels==3u && width && height){
        return this->haveEncRGB=true;
    }
    return false;
}
bool edk::video::VideoEDK::encodeFrameRGB(edk::uint8* vector,
                                          edk::uint64 lenght,
                                          edk::uint8 channels,
                                          edk::MemoryBuffer<edk::uint8>* bufferWrite,
                                          bool /*keyFrame*/
                                          ){
    if(vector && lenght && channels && bufferWrite){
        //encode the frame
        bufferWrite->pushToBuffer(vector,lenght);
        return true;
    }
    return false;
}
void edk::video::VideoEDK::finishEncoderRGB(){
    this->haveEncRGB=false;
}
bool edk::video::VideoEDK::startDecoderRGB(){
    return this->haveDecRGB=true;
}
bool edk::video::VideoEDK::canDecodeFrameRGB(edk::uint32 /*frameID*/){
    return true;
}
bool edk::video::VideoEDK::decodeFrameRGB(edk::MemoryBuffer<edk::uint8>* bufferRead,
                                          edk::uint32* width,
                                          edk::uint32* height,
                                          edk::uint8* channels
                                          ){
    if(bufferRead && width && height && channels){
        if(true){
            *width = this->getWidth();
            *height = this->getHeight();
            *channels = 3u;
            if(*width && *height && *channels){
                this->bufferRGB.cleanWrite();
                this->bufferRGB.pushToBuffer((edk::uint8*)bufferRead->getPointer(),bufferRead->getSize());

                return true;
            }
        }
    }
    return false;
}
bool edk::video::VideoEDK::copyDecodedFrameRGB(edk::MemoryBuffer<edk::uint8>* bufferDest){
    if(bufferDest){
        bufferDest->pushToBuffer((edk::uint8*)this->bufferRGB.getPointer(),this->bufferRGB.getSize());
        return true;
    }
    return false;
}
void edk::video::VideoEDK::finishDecoderRGB(){
    this->haveDecRGB=false;
}

void edk::video::VideoEDK::writeHeader(edk::File* file){
    this->headerEDK.fps = this->getFPS();
    this->headerEDK.timeIncrement = this->getTimeIncrement();
    //write the header
    file->writeBin((edk::uint8*)VIDEO_EDK_HEADER_NAME,sizeof(VIDEO_EDK_HEADER_NAME));
    file->writeBin((edk::uint8*)&this->headerEDK,sizeof(this->headerEDK));
}
bool edk::video::VideoEDK::readHeader(edk::File* file){
    if(file->isOpened()){
        //read the header
        edk::char8 headerName[sizeof(VIDEO_EDK_HEADER_NAME)+1u];
        edkMemSet(&headerName,0u,sizeof(headerName));
        file->readBin((edk::uint8*)&headerName,sizeof(VIDEO_EDK_HEADER_NAME));
        if(edk::String::strCompare(headerName,VIDEO_EDK_HEADER_NAME)){
            if(file->readBin((edk::uint8*)&this->headerEDK,sizeof(this->headerEDK))){
                //set the codec for the file
                this->useCodec((edk::video::EDKcodecName)this->headerEDK.codec);
                return true;
            }
        }
    }
    return false;
}
//start the encoder
bool edk::video::VideoEDK::startEncoder(edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::float32 fps){
    return (this->*functionStartEncoder)(width,height,channels,fps);
}
//encode a frame
bool edk::video::VideoEDK::encodeFrame(edk::uint8* vector,
                                       edk::uint64 lenght,
                                       edk::uint8 channels,
                                       edk::MemoryBuffer<edk::uint8>* bufferWrite,
                                       bool keyFrame
                                       ){
    return (this->*functionEncodeFrame)(vector,
                                        lenght,
                                        channels,
                                        bufferWrite,
                                        keyFrame);
}
//finish the encoder
void edk::video::VideoEDK::finishEncoder(){
    return (this->*functionFinishEncoder)();
}
//start the decoder
bool edk::video::VideoEDK::startDecoder(){
    return (this->*functionStartDecoder)();
}
//decode a frame
bool edk::video::VideoEDK::decodeFrame(edk::MemoryBuffer<edk::uint8>* bufferRead,
                                       edk::uint32* width,
                                       edk::uint32* height,
                                       edk::uint8* channels
                                       ){
    return (this->*functionDecodeFrame)(bufferRead,
                                        width,
                                        height,
                                        channels
                                        );
}
//decode a frame
bool edk::video::VideoEDK::canDecodeFrame(edk::uint32 frameID){
    return (this->*functionCanDecodeFrame)(frameID);
}
//decode a frame
bool edk::video::VideoEDK::copyDecodedFrame(edk::MemoryBuffer<edk::uint8>* bufferDest){
    return (this->*functionCopyDecodedFrame)(bufferDest);
}
//finish the decoder
void edk::video::VideoEDK::finishDecoder(){
    return (this->*functionFinishDecoder)();
}

void edk::video::VideoEDK::Constructor(edk::video::EDKcodecName codec){
    edk::Video::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->headerEDK.fps = 0.f;
        this->headerEDK.timeIncrement = 0.f;
        this->size=0u;
        this->frameIDH264=0u;

        this->encH264.Constructor();
        this->decH264.Constructor();
        this->encJPEG.Constructor();
        this->decJPEG.Constructor();

        this->haveEncNOTHING=false;
        this->haveDecNOTHING=false;
        this->haveEncJPEG=false;
        this->haveDecJPEG=false;
        this->haveEncH264=false;
        this->haveDecH264=false;
        this->haveEncRGB=false;
        this->haveDecRGB=false;

        this->bufferRGB.Constructor();

        this->useCodec(codec);
    }
}
void edk::video::VideoEDK::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;

        this->encH264.Destructor();
        this->decH264.Destructor();
        this->encJPEG.Destructor();
        this->decJPEG.Destructor();
        this->bufferRGB.Destructor();
    }
    edk::Video::Destructor();
}

//set use a codec
bool edk::video::VideoEDK::useCodec(edk::video::EDKcodecName codec){
    switch(codec){
    case edk::video::edkCodecH264:
        this->functionStartEncoder=&edk::video::VideoEDK::startEncoderH264;
        this->functionEncodeFrame=&edk::video::VideoEDK::encodeFrameH264;
        this->functionFinishEncoder=&edk::video::VideoEDK::finishEncoderH264;
        this->functionStartDecoder=&edk::video::VideoEDK::startDecoderH264;
        this->functionCanDecodeFrame=&edk::video::VideoEDK::canDecodeFrameH264;
        this->functionDecodeFrame=&edk::video::VideoEDK::decodeFrameH264;
        this->functionCopyDecodedFrame=&edk::video::VideoEDK::copyDecodedFrameH264;
        this->functionFinishDecoder=&edk::video::VideoEDK::finishDecoderH264;
        this->haveEnc=&this->haveEncH264;
        this->haveDec=&this->haveDecH264;
        this->headerEDK.codec=edk::video::edkCodecH264;
        return true;
        break;
    case edk::video::edkCodecJPEGvideo:
        this->functionStartEncoder=&edk::video::VideoEDK::startEncoderJPEG;
        this->functionEncodeFrame=&edk::video::VideoEDK::encodeFrameJPEG;
        this->functionFinishEncoder=&edk::video::VideoEDK::finishEncoderJPEG;
        this->functionStartDecoder=&edk::video::VideoEDK::startDecoderJPEG;
        this->functionCanDecodeFrame=&edk::video::VideoEDK::canDecodeFrameJPEG;
        this->functionDecodeFrame=&edk::video::VideoEDK::decodeFrameJPEG;
        this->functionCopyDecodedFrame=&edk::video::VideoEDK::copyDecodedFrameJPEG;
        this->functionFinishDecoder=&edk::video::VideoEDK::finishDecoderJPEG;
        this->haveEnc=&this->haveEncJPEG;
        this->haveDec=&this->haveDecJPEG;
        this->headerEDK.codec=edk::video::edkCodecJPEGvideo;
        return true;
        break;
    case edk::video::edkCodecRGB:
        this->functionStartEncoder=&edk::video::VideoEDK::startEncoderRGB;
        this->functionEncodeFrame=&edk::video::VideoEDK::encodeFrameRGB;
        this->functionFinishEncoder=&edk::video::VideoEDK::finishEncoderRGB;
        this->functionStartDecoder=&edk::video::VideoEDK::startDecoderRGB;
        this->functionCanDecodeFrame=&edk::video::VideoEDK::canDecodeFrameRGB;
        this->functionDecodeFrame=&edk::video::VideoEDK::decodeFrameRGB;
        this->functionCopyDecodedFrame=&edk::video::VideoEDK::copyDecodedFrameRGB;
        this->functionFinishDecoder=&edk::video::VideoEDK::finishDecoderRGB;
        this->haveEnc=&this->haveEncRGB;
        this->haveDec=&this->haveDecRGB;
        this->headerEDK.codec=edk::video::edkCodecRGB;
        return true;
        break;
    default:
        this->functionStartEncoder=&edk::video::VideoEDK::startEncoderNOTHING;
        this->functionEncodeFrame=&edk::video::VideoEDK::encodeFrameNOTHING;
        this->functionFinishEncoder=&edk::video::VideoEDK::finishEncoderNOTHING;
        this->functionStartDecoder=&edk::video::VideoEDK::startDecoderNOTHING;
        this->functionCanDecodeFrame=&edk::video::VideoEDK::canDecodeFrameNOTHING;
        this->functionDecodeFrame=&edk::video::VideoEDK::decodeFrameNOTHING;
        this->functionCopyDecodedFrame=&edk::video::VideoEDK::copyDecodedFrameNOTHING;
        this->functionFinishDecoder=&edk::video::VideoEDK::finishDecoder;
        this->haveEnc=&this->haveEncNOTHING;
        this->haveDec=&this->haveDecNOTHING;
        this->headerEDK.codec=edk::video::edkCodecNothing;
        break;
    }
    return false;
}
