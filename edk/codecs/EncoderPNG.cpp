#include "EncoderPNG.h"

/*
Library C++ EncoderPNG - Encode a frame to a JPEG stream or file
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
#pragma message "            Inside EncoderPNG.cpp"
#endif

edk::codecs::EncoderPNG::EncoderPNG(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::codecs::EncoderPNG::~EncoderPNG(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->deleteEncoded();edkEnd();
    }
}

void edk::codecs::EncoderPNG::Constructor(bool runFather){
    if(runFather){
        edk::codecs::EncoderImage::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;
    }
}

//process the encoder
bool edk::codecs::EncoderPNG::encode(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32){
    this->deleteEncoded();edkEnd();
    //process the father encoder
    if(edk::codecs::EncoderImage::encode(frame,size,channels,1u)){
        //test if the channels can be writed in jpeg
        if(channels == 1u || channels == 2u || channels == 3u || channels == 4u){
            bool ret=false;edkEnd();

            edk::uchar8 *png=NULL;edkEnd();
            edk::int32 len;edkEnd();
            if((png = stbi_write_png_to_mem((const edk::uchar8 *) frame, 0, (edk::int32) size.width, (edk::int32) size.height, (edk::int32)channels, &len))){
                //create the image and copy the png buffer
                if(len){
                    if(this->newFrameEncoded(len)){
                        //copy the bytes
                        memcpy(this->getEncoded(),png,this->getEncodedSize());edkEnd();
                    }
                    else{
                        ret=false;edkEnd();
                    }
                }
                else{
                    ret=false;edkEnd();
                }
                //delete the PNG
                STBI_FREE(png);edkEnd();
            }
            else{
                //return false;
                ret=false;edkEnd();
            }

            //calcula o tamanho do vetor
            if(this->getEncodedSize() && this->getEncoded()){
                //retorna true
                ret=true;edkEnd();
            }
            else{
                if(this->getEncodedSize()){
                    this->deleteEncoded();edkEnd();
                }
            }

            return ret;
        }
    }
    return false;
}
bool edk::codecs::EncoderPNG::encode(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality){
    return this->encode(frame,edk::size2ui32(width,height),channels,quality);edkEnd();
}
//delete the encoded
void edk::codecs::EncoderPNG::deleteEncoded(){
    if(this->getEncoded()){
        //jpeg_destroy_compress(&this->cinfo);edkEnd();
        this->cleanEncoded();edkEnd();
    }
}
