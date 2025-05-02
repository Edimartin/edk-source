#include "DecoderImage.h"

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

edk::codecs::DecoderImage::DecoderImage(){
    this->classThis=NULL;
    this->Constructor();
}

edk::codecs::DecoderImage::~DecoderImage(){
    this->Destructor();
}

void edk::codecs::DecoderImage::Constructor(){
    edk::codecs::CodecImage::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->file.Constructor();
    }
}
void edk::codecs::DecoderImage::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class

        this->file.Destructor();
    }
    edk::codecs::CodecImage::Destructor();
}

//process the decoder
bool edk::codecs::DecoderImage::decode(edk::uint8* encoded,edk::uint32 size){
    //test the encoded
    if(encoded && size){
        //return true
        return true;
    }
    return false;
}
bool edk::codecs::DecoderImage::decode(const unsigned char* encoded,edk::uint32 size){
    return this->decode((edk::uint8*) encoded, size);
}

//decode from file
bool edk::codecs::DecoderImage::decodeFromFile(const edk::char8* fileName){
    return this->decodeFromFile((edk::char8*) fileName);
}
bool edk::codecs::DecoderImage::decodeFromFile(edk::char8* fileName){
    //open the file
    if(this->file.openBinFile(fileName)){
        bool ret=false;
        //read the size of the file
        edk::uint32 fileSize = this->file.getFileSize();
        if(fileSize){
            //alloc the encoded
            if(edk::codecs::CodecImage::newFrameEncoded(fileSize)){
                //read the encoded
                if(this->file.readBin(edk::codecs::CodecImage::getEncoded(),edk::codecs::CodecImage::getEncodedSize())){
                    //process the decoder
                    if(this->decode(edk::codecs::CodecImage::getEncoded(),edk::codecs::CodecImage::getEncodedSize())){
                        if(edk::codecs::CodecImage::getFrame() &&
                                edk::codecs::CodecImage::getFrameWidth() &&
                                edk::codecs::CodecImage::getFrameHeight()
                                ){
                            ret=true;
                        }
                    }
                }
                //delete the frameEncoded
                edk::codecs::CodecImage::deleteEncoded();
            }
        }
        this->file.closeFile();
        return ret;
    }
    return false;
}

//Return the frame
edk::uint8* edk::codecs::DecoderImage::getFrame(){
    return edk::codecs::CodecImage::getFrame();
}
edk::size2ui32 edk::codecs::DecoderImage::getFrameSize(){
    return edk::codecs::CodecImage::getFrameSize();
}
edk::uint32 edk::codecs::DecoderImage::getFrameWidth(){
    return edk::codecs::CodecImage::getFrameWidth();
}
edk::uint32 edk::codecs::DecoderImage::getFrameHeight(){
    return edk::codecs::CodecImage::getFrameHeight();
}
edk::uint32 edk::codecs::DecoderImage::getFrameChannels(){
    return edk::codecs::CodecImage::getFrameChannels();
}
//delete the frame
void edk::codecs::DecoderImage::deleteFrame(){
    edk::codecs::CodecImage::deleteFrame();
}
//clean the frame
edk::uint8* edk::codecs::DecoderImage::cleanFrame(){
    return edk::codecs::CodecImage::cleanFrame();
}
