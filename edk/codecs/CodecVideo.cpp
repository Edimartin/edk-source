#include "CodecVideo.h"

/*
Library C++ codecs - Set the parameters use for the video codecs
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
#pragma message "            Inside CodecVideo.cpp"
#endif

edk::codecs::CodecVideo::CodecVideo(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::codecs::CodecVideo::~CodecVideo(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->deleteFrame();edkEnd();
        this->deleteSpaceEncoded();edkEnd();
    }
}

void edk::codecs::CodecVideo::Constructor(bool runFather){
    if(runFather){
        edk::codecs::CodecImage::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;
        this->usingEncodedSize=0u;
        this->Y=NULL;edkEnd();
        this->U=NULL;edkEnd();
        this->V=NULL;edkEnd();
        this->sizeY=0u;
        this->sizeU=0u;
        this->sizeV=0u;
        this->nexKeyframe=false;edkEnd();
    }
}

//create a new frame
bool edk::codecs::CodecVideo::newFrame(edk::size2ui32 size,edk::uint8 channels){
    return edk::codecs::CodecImage::newFrame(size,channels);edkEnd();
}
bool edk::codecs::CodecVideo::newFrame(edk::uint32 width,edk::uint32 height,edk::uint8 channels){
    return edk::codecs::CodecImage::newFrame(width,height,channels);edkEnd();
}
//create a new frame
bool edk::codecs::CodecVideo::newFrameYUV(edk::size2ui32 size){
    //delete the last frame
    this->deleteFrame();edkEnd();
    //alloc the frame
    if(size.width && size.height){
        this->frameSize = size;edkEnd();
        //alloc the YUV
        this->sizeY = size.width*size.height;edkEnd();
        this->Y = (edk::uint8*)malloc(sizeof(edk::uint8) * (this->sizeY));edkEnd();
        if(this->Y){
            this->sizeU = this->sizeY>>1u;edkEnd();
            this->U = (edk::uint8*)malloc(sizeof(edk::uint8) * (this->sizeU));edkEnd();
            if(this->U){
                this->sizeV = this->sizeU;edkEnd();
                this->V = (edk::uint8*)malloc(sizeof(edk::uint8) * (this->sizeV));edkEnd();
                if(this->V){
                    return true;
                }
                //else clean the size
                this->sizeV=0u;
                //delete U;edkEnd();
                this->sizeU=0u;
                free(this->U);edkEnd();
                this->U=NULL;edkEnd();
            }
            //else delete Y;edkEnd();
            this->sizeY=0u;
            free(this->Y);edkEnd();
            this->Y=NULL;edkEnd();
        }
        //delete the frame
        edk::codecs::CodecImage::deleteFrame();edkEnd();
    }
    return false;
}
bool edk::codecs::CodecVideo::newFrameYUV(edk::uint32 width,edk::uint32 height){
    return this->newFrameYUV(edk::size2ui32(width,height));edkEnd();
}
//delete the frame
void edk::codecs::CodecVideo::deleteFrame(){
    //delete the channels
    if(this->Y){
        free(this->Y);edkEnd();
    }
    this->Y=NULL;edkEnd();
    this->sizeY=0u;
    if(this->U){
        free(this->U);edkEnd();
    }
    this->U=NULL;edkEnd();
    this->sizeU=0u;
    if(this->V){
        free(this->V);edkEnd();
    }
    this->V=NULL;edkEnd();
    this->sizeV=0u;
    edk::codecs::CodecImage::deleteFrame();edkEnd();
}
//alloc a new frameEncoded
bool edk::codecs::CodecVideo::newSpaceEncoded(edk::uint32 size){
    this->usingEncodedSize=0u;
    return edk::codecs::CodecImage::newFrameEncoded(size);edkEnd();
}
//delete the encoded
void edk::codecs::CodecVideo::deleteSpaceEncoded(){
    this->usingEncodedSize=0u;
    return edk::codecs::CodecImage::deleteEncoded();edkEnd();
}

#include "EncoderJPEG.h"

//draw an image in the frame
bool edk::codecs::CodecVideo::drawFrame(edk::uint8* frame,edk::uint8 channels){
    //test if have the frame
    if(this->frameSize.width && this->frameSize.height && channels){
        //convert the image
        switch(channels){
        case 1u:
            return edk::codecs::CodecImage::grayToi420(frame,edk::size2ui32(this->frameSize.width,this->frameSize.height),this->Y,this->U,this->V);
        case 3u:
            return edk::codecs::CodecImage::rgbToi420(frame,edk::size2ui32(this->frameSize.width,this->frameSize.height),this->Y,this->U,this->V);
        }
    }
    return false;
}

//write in the frame encoded
bool edk::codecs::CodecVideo::writeEncoded(edk::uint8* frame,edk::uint32 size){
    this->usingEncodedSize=0u;
    if(frame && size && edk::codecs::CodecImage::getEncoded()){
        edk::uint32* encodedSize = edk::codecs::CodecImage::getEncodedSizePosition();edkEnd();
        edk::uint32 saveSize = *encodedSize;edkEnd();
        if(size<*encodedSize){
            //write the frame
            *encodedSize = size;edkEnd();
            bool ret = edk::codecs::CodecImage::writeEncoded(frame);edkEnd();
            *encodedSize = saveSize;edkEnd();
            if(ret){
                //save the encodedSize
                this->usingEncodedSize = size;edkEnd();
            }
            return ret;
        }
    }
    return false;
}
bool edk::codecs::CodecVideo::appendEncoded(edk::uint8* frame,edk::uint32 size){
    edk::uint8 * encoded = edk::codecs::CodecImage::getEncoded();edkEnd();
    if(frame && size && encoded){
        edk::uint32* encodedSize = edk::codecs::CodecImage::getEncodedSizePosition();edkEnd();
        if(size<(encodedSize[0u] - this->usingEncodedSize)){
            //write the frame
            memcpy(&encoded[this->usingEncodedSize],frame,size);edkEnd();
            this->usingEncodedSize+=size;edkEnd();
            return true;
        }
    }
    printf(" NOTOK %u",this->usingEncodedSize);edkEnd();
    return false;
}

//set the quality
bool edk::codecs::CodecVideo::setQuality(edk::uint32 quality){
    return edk::codecs::CodecImage::setQuality(quality);edkEnd();
}
//set the next is keyFrame
void edk::codecs::CodecVideo::setNextKeyframe(){
    this->nexKeyframe=true;edkEnd();
}
//return true if the next is keyframe
bool edk::codecs::CodecVideo::isNextKeyframe(){
    bool ret = this->nexKeyframe;edkEnd();
    this->nexKeyframe=false;edkEnd();
    return ret;
}

//get the frames
edk::uint8* edk::codecs::CodecVideo::getFrame(){
    return edk::codecs::CodecImage::getFrame();edkEnd();
}
edk::uint8* edk::codecs::CodecVideo::getEncoded(){
    return edk::codecs::CodecImage::getEncoded();edkEnd();
}
edk::uint8** edk::codecs::CodecVideo::getEncodedPosition(){
    return edk::codecs::CodecImage::getEncodedPosition();edkEnd();
}
edk::uint8* edk::codecs::CodecVideo::getFrameY(){
    return this->Y;edkEnd();
}
edk::uint8* edk::codecs::CodecVideo::getFrameU(){
    return this->U;edkEnd();
}
edk::uint8* edk::codecs::CodecVideo::getFrameV(){
    return this->V;edkEnd();
}

//clean the pointers
edk::uint8* edk::codecs::CodecVideo::cleanFrame(){
    return edk::codecs::CodecImage::cleanFrame();edkEnd();
}
bool edk::codecs::CodecVideo::cleanYUV(edk::uint8** Y,edk::uint8** U,edk::uint8** V){
    if(Y&&U&&V&&this->Y&&this->U&&this->V){
        *Y=this->Y;edkEnd();
        *U=this->U;edkEnd();
        *V=this->V;edkEnd();
        this->Y=NULL;edkEnd();
        this->U=NULL;edkEnd();
        this->V=NULL;edkEnd();
        this->sizeY=0u;
        this->sizeU=0u;
        this->sizeV=0u;
        return true;
    }
    return false;
}
edk::uint8* edk::codecs::CodecVideo::cleanEncoded(){
    this->usingEncodedSize=0u;
    return edk::codecs::CodecImage::cleanEncoded();edkEnd();
}

//return the size of the frame
edk::size2ui32 edk::codecs::CodecVideo::getFrameSize(){
    return edk::codecs::CodecImage::getFrameSize();edkEnd();
}
edk::uint32 edk::codecs::CodecVideo::getFrameWidth(){
    //
    return edk::codecs::CodecImage::getFrameWidth();edkEnd();
}
edk::uint32 edk::codecs::CodecVideo::getFrameHeight(){
    //
    return edk::codecs::CodecImage::getFrameHeight();edkEnd();
}
edk::uint32 edk::codecs::CodecVideo::getFrameChannels(){
    //
    return edk::codecs::CodecImage::getFrameChannels();edkEnd();
}
edk::uint32 edk::codecs::CodecVideo::getFrameVectorSize(){
    //
    return edk::codecs::CodecImage::getFrameVectorSize();edkEnd();
}
edk::uint32 edk::codecs::CodecVideo::getFrameYSize(){
    //
    return edk::codecs::CodecImage::getFrameWidth() * edk::codecs::CodecImage::getFrameHeight();edkEnd();
}
edk::uint32 edk::codecs::CodecVideo::getFrameUSize(){
    //
    return edk::codecs::CodecImage::getFrameWidth()>>1u * edk::codecs::CodecImage::getFrameHeight()>>1u;edkEnd();
}
edk::uint32 edk::codecs::CodecVideo::getFrameVSize(){
    //
    return edk::codecs::CodecImage::getFrameWidth()>>1u * edk::codecs::CodecImage::getFrameHeight()>>1u;edkEnd();
}
//return the size of the encoded
edk::uint32 edk::codecs::CodecVideo::getSpaceEncodedSize(){
    return edk::codecs::CodecImage::getEncodedSize();edkEnd();
}
edk::uint32 edk::codecs::CodecVideo::getEncodedUsedSize(){
    return this->usingEncodedSize;edkEnd();
}
edk::uint32 edk::codecs::CodecVideo::getQuality(){
    //
    return edk::codecs::CodecImage::getQuality();edkEnd();
}
