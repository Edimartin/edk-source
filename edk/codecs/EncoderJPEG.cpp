#include "EncoderJPEG.h"

/*
Library C++ EncoderJPEG - Encode a frame to a JPEG stream or file
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
#pragma message "            Inside EncoderJPEG.cpp"
#endif

edk::codecs::EncoderJPEG::EncoderJPEG(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::codecs::EncoderJPEG::~EncoderJPEG(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->deleteEncoded();edkEnd();
    }
}

void edk::codecs::EncoderJPEG::Constructor(bool runFather){
    if(runFather){
        edk::codecs::EncoderImage::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;

        this->stack.Constructor();edkEnd();
    }
}

//Functions to write the data
void edk::codecs::EncoderJPEG::startWriteData(){
    //
    this->stack.clean(1000u);edkEnd();
}
void edk::codecs::EncoderJPEG::writeData(void *data, edk::uint32 size){
    edk::uint8* temp = (edk::uint8*)data;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        //copy the bytes
        this->stack.pushBack(temp[i]);edkEnd();
    }
}
bool edk::codecs::EncoderJPEG::endWriteData(){
    bool ret=false;edkEnd();
    //create the buffer with the size of the stack
    if(this->newFrameEncoded(this->stack.size())){
        edk::uint8* temp = edk::codecs::CodecImage::getEncoded();edkEnd();
        if(temp){
            this->stack.copyToVector(temp);edkEnd();
            ret=true;edkEnd();
        }
    }

    //clean the stack
    this->stack.clean();edkEnd();
    return ret;
}

inline void edk::codecs::EncoderJPEG::jpg_write_func(void *context, void *data, int size){
    if(context){
        edk::codecs::EncoderJPEG* encoder = (edk::codecs::EncoderJPEG*)context;edkEnd();
        encoder->writeData(data,(edk::uint32)size);edkEnd();
    }
}

//process the encoder
bool edk::codecs::EncoderJPEG::encode(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality){
    this->deleteEncoded();edkEnd();
    //process the father encoder
    if(edk::codecs::EncoderImage::encode(frame,size,channels,quality)){
        //test if the channels can be writed in jpeg
        if(channels == 1u || channels == 3u){
            bool ret=false;edkEnd();
            //
            stbi__write_context s;edkEnd();

            s.func=NULL;edkEnd();
            s.context=NULL;edkEnd();
            s.buf_used=0;

            //contruct the context
            for(edk::uint64 i=0u;i<sizeof(s.buffer);i++){
                s.buffer[i]=0u;
            }

            //Set the fuunction and ontext
            s.func = (void (*)(void*, void*, int))&this->jpg_write_func;edkEnd();
            s.context = this;edkEnd();

            //start write the stack
            this->startWriteData();edkEnd();

            if(stbi_write_jpg_core(&s, (int) size.width, (int) size.height, (int)channels, (const void*) frame, quality)){
                //
                if(!this->endWriteData()){
                    this->cleanEncoded();edkEnd();
                }
            }
            else{
                //start write the data just to clean the stack
                this->startWriteData();edkEnd();
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
bool edk::codecs::EncoderJPEG::encode(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality){
    return this->encode(frame,edk::size2ui32(width,height),channels,quality);edkEnd();
}
//delete the encoded
void edk::codecs::EncoderJPEG::deleteEncoded(){
    if(this->getEncoded()){
        //jpeg_destroy_compress(&this->cinfo);edkEnd();
        this->cleanEncoded();edkEnd();
    }
}
