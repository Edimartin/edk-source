#include "EncoderImage.h"

/*
Library C++ codecs - Set the parameters use for the image encoder
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
#warning "            Inside EncoderImage.cpp"
#endif

edk::codecs::EncoderImage::EncoderImage()
//: edk::codecs::CodecImage()
{
    //printf("\nEncoderImage Construtor");edkEnd();fflush(stdout);edkEnd();
}

edk::codecs::EncoderImage::~EncoderImage()
{
    //printf("\nEncoderImage Destrutor");edkEnd();fflush(stdout);edkEnd();
    this->deleteEncoded();edkEnd();
}

//process the encoder
bool edk::codecs::EncoderImage::encode(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality){
    //test the frame and the size
    if(frame && size.width && size.height && quality && channels){
        return true;
    }
    return false;
}
bool edk::codecs::EncoderImage::encode(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality){
    return this->encode(frame,edk::size2ui32(width,height),channels,quality);edkEnd();
}
bool edk::codecs::EncoderImage::encode(const unsigned char* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality){
    return this->encode((edk::uint8*) frame,size,channels,quality);edkEnd();
}
bool edk::codecs::EncoderImage::encode(const unsigned char* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality){
    return this->encode((edk::uint8*) frame,width,height,channels,quality);edkEnd();
}

//process the encoder and save to a file
bool edk::codecs::EncoderImage::encodeToFile(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality,const edk::char8* fileName){
    return this->encodeToFile(frame,size,channels,quality,(edk::char8*) fileName);edkEnd();
}
bool edk::codecs::EncoderImage::encodeToFile(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality,edk::char8* fileName){
    //test the frame and the size
    if(frame && size.width && size.height && fileName && quality){
        bool ret = false;edkEnd();
        //create the file
        if(this->file.createAndOpenBinFile(fileName)){
            //process the encoder
            if(this->encode(frame,size,channels,quality)){
                if(edk::codecs::CodecImage::getEncoded() && edk::codecs::CodecImage::getEncodedSize()){
                    //write the encoded in the file
                    this->file.writeBin(this->getEncoded(),this->getEncodedSize());edkEnd();
                    //delete the encoded
                    this->deleteEncoded();edkEnd();
                    //return true
                    ret=true;edkEnd();
                }
            }

            //close the file
            this->file.closeFile();edkEnd();
        }
        return ret;
    }
    return false;
}
bool edk::codecs::EncoderImage::encodeToFile(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality,const edk::char8* fileName){
    return this->encodeToFile(frame,width,height,channels,quality,(edk::char8*) fileName);edkEnd();
}
bool edk::codecs::EncoderImage::encodeToFile(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality,edk::char8* fileName){
    return this->encodeToFile(frame,edk::size2ui32(width,height),channels,quality,fileName);edkEnd();
}

bool edk::codecs::EncoderImage::encodeToFile(const unsigned char* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality,const edk::char8* fileName){
    return this->encodeToFile((edk::uint8*) frame,size,channels,quality,fileName);edkEnd();
}
bool edk::codecs::EncoderImage::encodeToFile(const unsigned char* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality,edk::char8* fileName){
    return this->encodeToFile((edk::uint8*) frame,size,channels,quality,fileName);edkEnd();
}
bool edk::codecs::EncoderImage::encodeToFile(const unsigned char* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality,const edk::char8* fileName){
    return this->encodeToFile((edk::uint8*) frame,width,height,channels,quality,fileName);edkEnd();
}
bool edk::codecs::EncoderImage::encodeToFile(const unsigned char* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality,edk::char8* fileName){
    return this->encodeToFile((edk::uint8*) frame,width,height,channels,quality,fileName);edkEnd();
}

//return the frame encoded
edk::uint8* edk::codecs::EncoderImage::getEncoded(){
    return edk::codecs::CodecImage::getEncoded();edkEnd();
}
edk::uint32 edk::codecs::EncoderImage::getEncodedSize(){
    return edk::codecs::CodecImage::getEncodedSize();edkEnd();
}
//delete the encoded
void edk::codecs::EncoderImage::deleteEncoded(){
    edk::codecs::CodecImage::deleteEncoded();edkEnd();
}
