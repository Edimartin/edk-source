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
#warning "            Inside EncoderJPEG.cpp"
#endif

edk::codecs::EncoderJPEG::EncoderJPEG()
{
    //ctor
}

edk::codecs::EncoderJPEG::~EncoderJPEG()
{
    //dtor
    this->deleteEncoded();
}

//process the encoder
bool edk::codecs::EncoderJPEG::encode(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality){
    this->deleteEncoded();
    //process the father encoder
    if(edk::codecs::EncoderImage::encode(frame,size,channels,quality)){
        //test if the channels can be writed in jpeg
        if(channels == 1u || channels == 3u){
            bool ret=false;
            //cria o encoder
            jpeg_create_compress(&this->cinfo);
            //carrega o ponteiro de erros
            this->cinfo.err = jpeg_std_error(&jerr);
            this->cinfo.image_width = size.width; 	/* image width and height, in pixels */
            this->cinfo.image_height = size.height;
            this->cinfo.input_components = channels;		/* # of color components per pixel */
            switch(channels){
            case 1u:
                this->cinfo.in_color_space = JCS_GRAYSCALE;/* colorspace of input image */
                break;
            case 3u:
                this->cinfo.in_color_space = JCS_RGB; 	/* colorspace of input image */
                break;
            }
            //seta o dado
            jpeg_set_defaults(&this->cinfo);
            //seta a qualidade
            jpeg_set_quality(&this->cinfo, quality, TRUE);

#ifdef __x86_64
			//seta o destino
            jpeg_mem_dest(&this->cinfo,
                          edk::codecs::CodecImage::getEncodedPosition(),
                          (unsigned long int*)(edk::uint64*)edk::codecs::CodecImage::getEncodedSizePosition()
                          );
#else
			//seta o destino
            jpeg_mem_dest(&this->cinfo,
                          edk::codecs::CodecImage::getEncodedPosition(),
                          (unsigned long int*)(edk::uint64*)edk::codecs::CodecImage::getEncodedSizePosition()
                          );
#endif
            

            //inicia a compressao
            jpeg_start_compress(&this->cinfo, TRUE);
            //carrega o ponteiro do frame
            unsigned char* temp = frame;
            if (temp){
                edk::uint32 row_stride = size.width * channels;
                while (this->cinfo.next_scanline < this->cinfo.image_height) {
                    jpeg_write_scanlines(&this->cinfo, &temp, 1);
                    //incrementa o temp
                    temp+=row_stride;
                }
            }

            //
            //finaliza o encoder
            jpeg_finish_compress(&this->cinfo);

            //calcula o tamanho do vetor
            if (this->getEncodedSize() && this->getEncoded()){
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
bool edk::codecs::EncoderJPEG::encode(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality){
    return this->encode(frame,edk::size2ui32(width,height),channels,quality);
}
//delete the encoded
void edk::codecs::EncoderJPEG::deleteEncoded(){
    if(this->getEncoded()){
        jpeg_destroy_compress(&this->cinfo);
        this->cleanEncoded();
    }
}
