#include "EncoderImage.h"

edk::codecs::EncoderImage::EncoderImage()
//: edk::codecs::CodecImage()
{
    //printf("\nEncoderImage Construtor");fflush(stdout);
}

edk::codecs::EncoderImage::~EncoderImage()
{
    //printf("\nEncoderImage Destrutor");fflush(stdout);
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
    return this->encode(frame,edk::size2ui32(width,height),channels,quality);
}
bool edk::codecs::EncoderImage::encode(const unsigned char* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality){
    return this->encode((edk::uint8*) frame,size,channels,quality);
}
bool edk::codecs::EncoderImage::encode(const unsigned char* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality){
    return this->encode((edk::uint8*) frame,width,height,channels,quality);
}

//process the encoder and save to a file
bool edk::codecs::EncoderImage::encodeToFile(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality,const char* fileName){
    return this->encodeToFile(frame,size,channels,quality,(edk::char8*) fileName);
}
bool edk::codecs::EncoderImage::encodeToFile(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality,edk::char8* fileName){
    //test the frame and the size
    if(frame && size.width && size.height && fileName && quality){
        bool ret = false;
        //create the file
        if(this->file.createAndOpenBinFile(fileName)){
            //process the encoder
            if(this->encode(frame,size,channels,quality)){
                if(edk::codecs::CodecImage::getEncoded() && edk::codecs::CodecImage::getEncodedSize()){
                    //write the encoded in the file
                    this->file.writeBin(this->getEncoded(),this->getEncodedSize());
                    //delete the encoded
                    this->deleteEncoded();
                    //return true
                    ret=true;
                }
            }

            //close the file
            this->file.closeFile();
        }
        return ret;
    }
    return false;
}
bool edk::codecs::EncoderImage::encodeToFile(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality,const char* fileName){
    return this->encodeToFile(frame,width,height,channels,quality,(edk::char8*) fileName);
}
bool edk::codecs::EncoderImage::encodeToFile(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality,edk::char8* fileName){
    return this->encodeToFile(frame,edk::size2ui32(width,height),channels,quality,fileName);
}

bool edk::codecs::EncoderImage::encodeToFile(const unsigned char* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality,const char* fileName){
    return this->encodeToFile((edk::uint8*) frame,size,channels,quality,fileName);
}
bool edk::codecs::EncoderImage::encodeToFile(const unsigned char* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality,edk::char8* fileName){
    return this->encodeToFile((edk::uint8*) frame,size,channels,quality,fileName);
}
bool edk::codecs::EncoderImage::encodeToFile(const unsigned char* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality,const char* fileName){
    return this->encodeToFile((edk::uint8*) frame,width,height,channels,quality,fileName);
}
bool edk::codecs::EncoderImage::encodeToFile(const unsigned char* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality,edk::char8* fileName){
    return this->encodeToFile((edk::uint8*) frame,width,height,channels,quality,fileName);
}

//return the frame encoded
edk::uint8* edk::codecs::EncoderImage::getEncoded(){
    return edk::codecs::CodecImage::getEncoded();
}
edk::uint32 edk::codecs::EncoderImage::getEncodedSize(){
    return edk::codecs::CodecImage::getEncodedSize();
}
//delete the encoded
void edk::codecs::EncoderImage::deleteEncoded(){
    edk::codecs::CodecImage::deleteEncoded();
}