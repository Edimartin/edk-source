#include "EncoderJPEG.h"

edk::codecs::EncoderJPEG::EncoderJPEG()
{
    //ctor
}

edk::codecs::EncoderJPEG::~EncoderJPEG()
{
    //dtor
}

//process the encoder
bool edk::codecs::EncoderJPEG::encode(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality){
    //process the father encoder
    if(edk::codecs::EncoderImage::encode(frame,size,channels,quality)){
        //test if the channels can be writed in jpeg
        if(channels == 1u || channels == 3u){
            bool ret=false;
            //Process the libJpeg Encoder
            jpeg_compress_struct cinfo;
            jpeg_error_mgr jerr;
            //cria o encoder
            jpeg_create_compress(&cinfo);
            //carrega o ponteiro de erros
            cinfo.err = jpeg_std_error(&jerr);
            cinfo.image_width = size.width; 	/* image width and height, in pixels */
            cinfo.image_height = size.height;
            cinfo.input_components = channels;		/* # of color components per pixel */
            switch(channels){
            case 1u:
                cinfo.in_color_space = JCS_GRAYSCALE;/* colorspace of input image */
                break;
            case 3u:
                cinfo.in_color_space = JCS_RGB; 	/* colorspace of input image */
                break;
            }
            //seta o dado
            jpeg_set_defaults(&cinfo);
            //seta a qualidade
            jpeg_set_quality(&cinfo, quality, TRUE);

            //seta o destino
            jpeg_mem_dest(&cinfo,
                          edk::codecs::CodecImage::getEncodedPosition(),
                          (long unsigned int*)edk::codecs::CodecImage::getEncodedSizePosition()
                          );

            //inicia a compressao
            jpeg_start_compress(&cinfo, TRUE);
            //carrega o ponteiro do frame
            unsigned char* temp = frame;
            if (temp){
                unsigned int row_stride = size.width * channels;
                while (cinfo.next_scanline < cinfo.image_height) {
                    jpeg_write_scanlines(&cinfo, &temp, 1);
                    //incrementa o temp
                    temp+=row_stride;
                }
            }

            //
            //finaliza o encoder
            jpeg_finish_compress(&cinfo);

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

            //remove o encoder
            jpeg_destroy_compress(&cinfo);

            return ret;
        }
    }
    return false;
}
bool edk::codecs::EncoderJPEG::encode(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality){
    return this->encode(frame,edk::size2ui32(width,height),channels,quality);
}
