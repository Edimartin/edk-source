#include "EncoderHDR.h"

/*
Library C++ EncoderHDR - Encode a frame to a HDRi stream or file
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
#pragma message "            Inside EncoderHDR.cpp"
#endif


edk::codecs::EncoderHDR::EncoderHDR(){
this->classThis=NULL;
this->Constructor();
}
edk::codecs::EncoderHDR::~EncoderHDR(){
    this->Destructor();
}
void edk::codecs::EncoderHDR::Constructor(){
    edk::codecs::EncoderImage::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->stack.Constructor();
    }
}
void edk::codecs::EncoderHDR::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->deleteEncoded();

        this->stack.Destructor();
    }
    edk::codecs::EncoderImage::Destructor();
}

//Functions to write the data
void edk::codecs::EncoderHDR::startWriteData(){
    //
    this->stack.clean(10000u);
}
void edk::codecs::EncoderHDR::writeData(void *data, edk::uint32 size){
    edk::uint8* temp = (edk::uint8*)data;
    for(edk::uint32 i=0u;i<size;i++){
        //copy the bytes
        this->stack.pushBack(temp[i]);
    }
}
bool edk::codecs::EncoderHDR::endWriteData(){
    bool ret=false;
    //create the buffer with the size of the stack
    if(this->newFrameEncoded(this->stack.size())){
        edk::uint8* temp = edk::codecs::CodecImage::getEncoded();
        if(temp){
            this->stack.copyToVector(temp);
            ret=true;
        }
    }

    //clean the stack
    this->stack.clean();
    return ret;
}

inline void edk::codecs::EncoderHDR::hdr_write_func(void *context, void *data, int size){
    if(context){
        edk::codecs::EncoderHDR* encoder = (edk::codecs::EncoderHDR*)context;
        encoder->writeData(data,(edk::uint32)size);
    }
}

//process the encoder
bool edk::codecs::EncoderHDR::encode(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality){
    this->deleteEncoded();
    //process the father encoder
    if(edk::codecs::EncoderImage::encode(frame,size,channels,quality)){
        //test if the channels can be writed in jpeg
        if(channels == 1u || channels == 3u){
            bool ret=false;
            //
            stbi__write_context s;

            s.func=NULL;
            s.context=NULL;
            s.buf_used=0;

            //contruct the context
            for(edk::uint64 i=0u;i<sizeof(s.buffer);i++){
                s.buffer[i]=0u;
            }

            //Set the fuunction and ontext
            s.func = (void (*)(void*, void*, int))&this->hdr_write_func;
            s.context = this;

            //start write the stack
            this->startWriteData();

            if(stbi_write_hdr_core(&s, (int) size.width, (int) size.height, (int)channels, (float*) frame)){
                //
                if(!this->endWriteData()){
                    this->cleanEncoded();
                }
            }
            else{
                //start write the data just to clean the stack
                this->startWriteData();
            }

            //calcula o tamanho do vetor
            if(this->getEncodedSize() && this->getEncoded()){
                //retorna true
                ret=true;
            }
            else{
                if(this->getEncodedSize()){
                    this->deleteEncoded();
                }
            }

            return ret;
        }
    }
    return false;
}
bool edk::codecs::EncoderHDR::encode(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality){
    return this->encode(frame,edk::size2ui32(width,height),channels,quality);
}
//delete the encoded
void edk::codecs::EncoderHDR::deleteEncoded(){
    if(this->getEncoded()){
        //jpeg_destroy_compress(&this->cinfo);
        this->cleanEncoded();
    }
}

