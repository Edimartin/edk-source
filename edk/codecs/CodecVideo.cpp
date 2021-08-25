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
#warning "            Inside CodecVideo.cpp"
#endif

edk::codecs::CodecVideo::CodecVideo(){
    this->usingEncodedSize=0u;
    this->Y=NULL;
    this->U=NULL;
    this->V=NULL;
    this->sizeY=0u;
    this->sizeU=0u;
    this->sizeV=0u;
    this->nexKeyframe=false;
}
edk::codecs::CodecVideo::~CodecVideo(){
    //
    this->deleteFrame();
    this->deleteSpaceEncoded();
}

//create a new frame
bool edk::codecs::CodecVideo::newFrame(edk::size2ui32 size,edk::uint8 channels){
    return edk::codecs::CodecImage::newFrame(size,channels);
}
bool edk::codecs::CodecVideo::newFrame(edk::uint32 width,edk::uint32 height,edk::uint8 channels){
    return edk::codecs::CodecImage::newFrame(width,height,channels);
}
//create a new frame
bool edk::codecs::CodecVideo::newFrameYUV(edk::size2ui32 size){
    //delete the last frame
    this->deleteFrame();
    //alloc the frame
    if(size.width && size.height){
        this->frameSize = size;
        //alloc the YUV
        this->sizeY = size.width*size.height;
        this->Y = new edk::uint8[this->sizeY];
        if(this->Y){
            this->sizeU = this->sizeY>>1u;
            this->U = new edk::uint8[this->sizeU];
            if(this->U){
                this->sizeV = this->sizeU;
                this->V = new edk::uint8[this->sizeV];
                if(this->V){
                    return true;
                }
                //else clean the size
                this->sizeV=0u;
                //delete U;
                this->sizeU=0u;
                delete[] this->U;
                this->U=NULL;
            }
            //else delete Y;
            this->sizeY=0u;
            delete[] this->Y;
            this->Y=NULL;
        }
        //delete the frame
        edk::codecs::CodecImage::deleteFrame();
    }
    return false;
}
bool edk::codecs::CodecVideo::newFrameYUV(edk::uint32 width,edk::uint32 height){
    return this->newFrameYUV(edk::size2ui32(width,height));
}
//delete the frame
void edk::codecs::CodecVideo::deleteFrame(){
    //delete the channels
    if(this->Y) delete[] this->Y;
    this->Y=NULL;
    this->sizeY=0u;
    if(this->U) delete[] this->U;
    this->U=NULL;
    this->sizeU=0u;
    if(this->V) delete[] this->V;
    this->V=NULL;
    this->sizeV=0u;
    edk::codecs::CodecImage::deleteFrame();
}
//alloc a new frameEncoded
bool edk::codecs::CodecVideo::newSpaceEncoded(edk::uint32 size){
    this->usingEncodedSize=0u;
    return edk::codecs::CodecImage::newFrameEncoded(size);
}
//delete the encoded
void edk::codecs::CodecVideo::deleteSpaceEncoded(){
    this->usingEncodedSize=0u;
    return edk::codecs::CodecImage::deleteEncoded();
}

#include "EncoderJPEG.h"

//draw an image in the frame
bool edk::codecs::CodecVideo::drawFrame(edk::uint8* frame,edk::uint8 channels){
    //test if have the frame
    if(this->frameSize.width && this->frameSize.height && channels){
        //convert the image
        switch(channels){
        case 1u:
            return edk::codecs::CodecImage::grayToi240(frame,edk::size2ui32(this->frameSize.width,this->frameSize.height),this->Y,this->U,this->V);
        case 3u:
            return edk::codecs::CodecImage::rgbToi240(frame,edk::size2ui32(this->frameSize.width,this->frameSize.height),this->Y,this->U,this->V);
        }
    }
    return false;
}

//write in the frame encoded
bool edk::codecs::CodecVideo::writeEncoded(edk::uint8* frame,edk::uint32 size){
    this->usingEncodedSize=0u;
    if(frame && size && edk::codecs::CodecImage::getEncoded()){
        edk::uint32* encodedSize = edk::codecs::CodecImage::getEncodedSizePosition();
        edk::uint32 saveSize = *encodedSize;
        if(size<*encodedSize){
            //write the frame
            *encodedSize = size;
            bool ret = edk::codecs::CodecImage::writeEncoded(frame);
            *encodedSize = saveSize;
            if(ret){
                //save the encodedSize
                this->usingEncodedSize = size;
            }
            return ret;
        }
    }
    return false;
}
bool edk::codecs::CodecVideo::appendEncoded(edk::uint8* frame,edk::uint32 size){
    edk::uint8 * encoded = edk::codecs::CodecImage::getEncoded();
    if(frame && size && encoded){
        edk::uint32* encodedSize = edk::codecs::CodecImage::getEncodedSizePosition();
        if(size<(encodedSize[0u] - this->usingEncodedSize)){
            //write the frame
            memcpy(&encoded[this->usingEncodedSize],frame,size);
            this->usingEncodedSize+=size;
            return true;
        }
    }
    printf(" NOTOK %u",this->usingEncodedSize);fflush(stdout);
    return false;
}

//set the quality
bool edk::codecs::CodecVideo::setQuality(edk::uint32 quality){
    return edk::codecs::CodecImage::setQuality(quality);
}
//set the next is keyFrame
void edk::codecs::CodecVideo::setNextkeyframe(){
    this->nexKeyframe=true;
}
//return true if the next is keyframe
bool edk::codecs::CodecVideo::isNextKeyframe(){
    bool ret = this->nexKeyframe;
    this->nexKeyframe=false;
    return ret;
}

//get the frames
edk::uint8* edk::codecs::CodecVideo::getFrame(){
    return edk::codecs::CodecImage::getFrame();
}
edk::uint8* edk::codecs::CodecVideo::getEncoded(){
    return edk::codecs::CodecImage::getEncoded();
}
edk::uint8** edk::codecs::CodecVideo::getEncodedPosition(){
    return edk::codecs::CodecImage::getEncodedPosition();
}
edk::uint8* edk::codecs::CodecVideo::getFrameY(){
    return this->Y;
}
edk::uint8* edk::codecs::CodecVideo::getFrameU(){
    return this->U;
}
edk::uint8* edk::codecs::CodecVideo::getFrameV(){
    return this->V;
}

//clean the pointers
edk::uint8* edk::codecs::CodecVideo::cleanFrame(){
    return edk::codecs::CodecImage::cleanFrame();
}
bool edk::codecs::CodecVideo::cleanYUV(edk::uint8** Y,edk::uint8** U,edk::uint8** V){
    if(Y&&U&&V&&this->Y&&this->U&&this->V){
        *Y=this->Y;
        *U=this->U;
        *V=this->V;
        this->Y=NULL;
        this->U=NULL;
        this->V=NULL;
        this->sizeY=0u;
        this->sizeU=0u;
        this->sizeV=0u;
        return true;
    }
    return false;
}
edk::uint8* edk::codecs::CodecVideo::cleanEncoded(){
    this->usingEncodedSize=0u;
    return edk::codecs::CodecImage::cleanEncoded();
}

//return the size of the frame
edk::size2ui32 edk::codecs::CodecVideo::getFrameSize(){
    return edk::codecs::CodecImage::getFrameSize();
}
edk::uint32 edk::codecs::CodecVideo::getFrameWidth(){
    //
    return edk::codecs::CodecImage::getFrameWidth();
}
edk::uint32 edk::codecs::CodecVideo::getFrameHeight(){
    //
    return edk::codecs::CodecImage::getFrameHeight();
}
edk::uint32 edk::codecs::CodecVideo::getFrameChannels(){
    //
    return edk::codecs::CodecImage::getFrameChannels();
}
edk::uint32 edk::codecs::CodecVideo::getFrameVectorSize(){
    //
    return edk::codecs::CodecImage::getFrameVectorSize();
}
edk::uint32 edk::codecs::CodecVideo::getFrameYSize(){
    //
    return edk::codecs::CodecImage::getFrameWidth() * edk::codecs::CodecImage::getFrameHeight();
}
edk::uint32 edk::codecs::CodecVideo::getFrameUSize(){
    //
    return edk::codecs::CodecImage::getFrameWidth()>>1u * edk::codecs::CodecImage::getFrameHeight()>>1u;
}
edk::uint32 edk::codecs::CodecVideo::getFrameVSize(){
    //
    return edk::codecs::CodecImage::getFrameWidth()>>1u * edk::codecs::CodecImage::getFrameHeight()>>1u;
}
//return the size of the encoded
edk::uint32 edk::codecs::CodecVideo::getSpaceEncodedSize(){
    return edk::codecs::CodecImage::getEncodedSize();
}
edk::uint32 edk::codecs::CodecVideo::getEncodedUsedSize(){
    return this->usingEncodedSize;
}
edk::uint32 edk::codecs::CodecVideo::getQuality(){
    //
    return edk::codecs::CodecImage::getQuality();
}
