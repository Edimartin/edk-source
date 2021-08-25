#include "DecoderJPEG.h"

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

edk::codecs::DecoderJPEG::DecoderJPEG()
{
    //ctor
}

edk::codecs::DecoderJPEG::~DecoderJPEG()
{
    //dtor
}

//process the decoder
bool edk::codecs::DecoderJPEG::decode(edk::uint8* encoded,edk::uint32 size){
    //use the father decoder
    if(edk::codecs::DecoderImage::decode(encoded,size)){
        //process the decoder
        bool ret=false;

		//estrutura libjpeg
		jpeg_decompress_struct cinfo;
		jpeg_error_mgr jerr;
		jpeg_create_decompress(&cinfo);
		//
		cinfo.err = jpeg_std_error(&jerr);
		//copia os dados para o cinfo
		jpeg_mem_src(&cinfo, encoded, size);
		if (jpeg_read_header(&cinfo, TRUE)==1){
			//conseguiu ler da memoria
			//inicia a decodificacao
			jpeg_start_decompress(&cinfo);
			//testa o tamanho da imagem decodificada
			if (cinfo.output_width && cinfo.output_height && cinfo.output_components){
				//entao carrega um novo frame
				edk::codecs::CodecImage::newFrame(cinfo.output_width,cinfo.output_height,(edk::float32)cinfo.output_components);
				//testa se possui o frame e o seu tamanho
				if (edk::codecs::CodecImage::getFrame() &&
                    edk::codecs::CodecImage::getFrameWidth() &&
                    edk::codecs::CodecImage::getFrameHeight()
                    ){
					//copia os dados convertendo para YUV
					//ret = RGBtoYUV(,this->width,this->height,this->frame);
					unsigned char* temp = edk::codecs::CodecImage::getFrame();
                    edk::uint32 row_stride = edk::codecs::CodecImage::getFrameWidth() * cinfo.output_components;
					//printf("Error decoding the input file\n");
					while (cinfo.output_scanline < cinfo.output_height){
						//
						jpeg_read_scanlines(&cinfo, (JSAMPARRAY)(&temp), 1);
						temp+=row_stride;
					}
					//retorna true
					ret=true;
				}
			}
			//finaliza o decoder
			jpeg_finish_decompress(&cinfo);
		}
		else{
            //header error
		}
		//remove o decoder
		jpeg_destroy_decompress(&cinfo);

		return ret;
    }
    return false;
}
bool edk::codecs::DecoderJPEG::decode(const unsigned char* encoded,edk::uint32 size){
    return this->decode((edk::uint8*) encoded,size);
}

//return the vector size
edk::uint32 edk::codecs::DecoderJPEG::getVectorSize(){
    return edk::codecs::CodecImage::getFrameVectorSize();
}
