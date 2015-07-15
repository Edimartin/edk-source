#include "DecoderImage.h"

edk::codecs::DecoderImage::DecoderImage()
{
    //ctor
}

edk::codecs::DecoderImage::~DecoderImage()
{
    //dtor
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
bool edk::codecs::DecoderImage::decodeFromFile(const char* fileName){
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
