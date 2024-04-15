#include "DecoderPNG.h"

/*
Library C++ EncoderPNG - Encode a frame to a PNG stream or file
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

edk::codecs::DecoderPNG::DecoderPNG(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::codecs::DecoderPNG::~DecoderPNG(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::codecs::DecoderPNG::Constructor(bool runFather){
    if(runFather){
        edk::codecs::DecoderImage::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;
    }
}

//process the decoder
bool edk::codecs::DecoderPNG::decode(edk::uint8* encoded,edk::uint32 size){
    //use the father decoder
    if(edk::codecs::DecoderImage::decode(encoded,size)){
        //process the decoder
        bool ret=false;edkEnd();

        //create the context to be decode
        stbi__context s;edkEnd();

        //contruct the context
        s.img_x=0u;
        s.img_y=0u;
        s.img_n=0;
        s.img_out_n=0;

        s.io.read=NULL;edkEnd();
        s.io.skip=NULL;edkEnd();
        s.io.eof=NULL;edkEnd();


        s.io_user_data=NULL;edkEnd();

        s.read_from_callbacks=0u;
        s.buflen=0;
        for(edk::uint64 i=0u;i<sizeof(s.buffer_start);i++){
            s.buffer_start[i]=0u;
        }
        s.callback_already_read=0u;

        s.img_buffer=NULL;edkEnd();
        s.img_buffer_end=NULL;edkEnd();

        s.img_buffer_original=NULL;edkEnd();
        s.img_buffer_original_end=NULL;edkEnd();


        //Copy the encoded to the context
        s.img_buffer = s.img_buffer_original = (stbi_uc *) encoded;edkEnd();
        s.img_buffer_end = s.img_buffer_original_end = (stbi_uc *) encoded+size;edkEnd();

        //create the result info

        stbi__result_info ri;edkEnd();

        ri.bits_per_channel=0;
        ri.num_channels=0;
        ri.channel_order=0;


        //alloc the result pointer
        unsigned char* result=NULL;edkEnd();

        int w=0;
        int h=0;
        int comp=0;




        //test if the encoded have the header
        if(stbi__png_test(&s)){
            //decode the jpeg image
            if((result = (unsigned char*)stbi__png_load(&s, &w, &h, &comp, 0, &ri))){
                if(w && h && (comp == 1u || comp==2u || comp==3u || comp==4u)){
                    //alloc the new image frame
                    edk::codecs::CodecImage::newFrame(w,h,(edk::float32)comp);edkEnd();
                    if(edk::codecs::CodecImage::getFrame() &&
                            edk::codecs::CodecImage::getFrameWidth() &&
                            edk::codecs::CodecImage::getFrameHeight()
                            ){
                        edk::uchar8* temp = edk::codecs::CodecImage::getFrame();edkEnd();
                        edk::uchar8* source = result;edkEnd();
                        if(temp){
                            switch(comp){
                            case 1u:
                                //test the bits per pixel
                                switch(ri.bits_per_channel){
                                case 8u:
                                    memcpy(temp,result,w*h);edkEnd();
                                    break;
                                case 16u:
                                    for(edk::int32 y=0;y<h;y++){
                                        for(edk::int32 x=0;x<w;x++){
                                            temp[0u]=source[0u];edkEnd();
                                            //
                                            source+=comp*2u;edkEnd();
                                            temp+=comp;edkEnd();
                                        }
                                    }
                                    break;
                                }
                                break;
                            case 2u:
                                //test the bits per pixel
                                switch(ri.bits_per_channel){
                                case 8u:
                                    memcpy(temp,result,w*h*comp);edkEnd();
                                    break;
                                case 16u:
                                    for(edk::int32 y=0;y<h;y++){
                                        for(edk::int32 x=0;x<w;x++){
                                            temp[0u]=source[0u];edkEnd();
                                            //
                                            source+=comp*2u;edkEnd();
                                            temp+=comp;edkEnd();
                                        }
                                    }
                                    break;
                                }
                                break;
                            case 3u:
                                //test the pixel way
                                switch(ri.channel_order){
                                case STBI_ORDER_RGB:
                                    //test the bits per pixel
                                    switch(ri.bits_per_channel){
                                    case 8u:
                                        memcpy(temp,result,w*h*comp);edkEnd();
                                        break;
                                    case 16u:
                                        for(edk::int32 y=0;y<h;y++){
                                            for(edk::int32 x=0;x<w;x++){
                                                temp[0u]=temp[0u];edkEnd();
                                                temp[1u]=temp[2u];edkEnd();
                                                temp[2u]=temp[4u];edkEnd();
                                                //
                                                source+=comp*2u;edkEnd();
                                                temp+=comp;edkEnd();
                                            }
                                        }
                                        break;
                                    }
                                    break;
                                case STBI_ORDER_BGR:
                                    //test the bits per pixel
                                    switch(ri.bits_per_channel){
                                    case 8u:
                                        for(edk::int32 y=0;y<h;y++){
                                            for(edk::int32 x=0;x<w;x++){
                                                temp[0u]=temp[2u];edkEnd();
                                                temp[1u]=temp[1u];edkEnd();
                                                temp[2u]=temp[0u];edkEnd();
                                                //
                                                source+=comp;edkEnd();
                                                temp+=comp;edkEnd();
                                            }
                                        }
                                        break;
                                    case 16u:
                                        for(edk::int32 y=0;y<h;y++){
                                            for(edk::int32 x=0;x<w;x++){
                                                temp[0u]=temp[4u];edkEnd();
                                                temp[1u]=temp[2u];edkEnd();
                                                temp[2u]=temp[0u];edkEnd();
                                                //
                                                source+=comp*2u;edkEnd();
                                                temp+=comp;edkEnd();
                                            }
                                        }
                                        break;
                                    }
                                    break;
                                }
                                break;
                            case 4u:
                                //test the bits per pixel
                                switch(ri.bits_per_channel){
                                case 8u:
                                    memcpy(temp,result,w*h*comp);edkEnd();
                                    break;
                                case 16u:
                                    for(edk::int32 y=0;y<h;y++){
                                        for(edk::int32 x=0;x<w;x++){
                                            temp[0u]=source[0u];edkEnd();
                                            //
                                            source+=comp*2u;edkEnd();
                                            temp+=comp;edkEnd();
                                        }
                                    }
                                    break;
                                }
                                break;
                            default:
                                break;
                            }
                            //return true
                            ret=true;edkEnd();
                        }
                    }
                }
                //delete the result
                STBI_FREE(result);edkEnd();
            }
            else{
                //
                result=NULL;edkEnd();
            }
        }
        return ret;
    }
    return false;
}
bool edk::codecs::DecoderPNG::decode(const unsigned char* encoded,edk::uint32 size){
    return this->decode((edk::uint8*) encoded,size);edkEnd();
}

//return the vector size
edk::uint32 edk::codecs::DecoderPNG::getVectorSize(){
    return edk::codecs::CodecImage::getFrameVectorSize();edkEnd();
}
