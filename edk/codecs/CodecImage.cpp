#include "CodecImage.h"

edk::codecs::CodecImage::CodecImage(){
    //printf("\nCodecImage Construtor");fflush(stdout);
    this->frame=NULL;
    this->encoded=NULL;
    this->frameSize = edk::size2ui32(0u,0u);
    this->encodedSize = 0u;
    this->encodedQuality = 0u;
    this->frameChannels = 0.f;
    this->vectorFrameSize=0u;
}

edk::codecs::CodecImage::~CodecImage(){
    //printf("\nCodecImage Destrutor");fflush(stdout);
    //delete the vectors
    this->deleteEncoded();
    this->deleteFrame();
}

//create a new frame
bool edk::codecs::CodecImage::newFrame(edk::size2ui32 size,edk::uint8 channels){
    //test the size of the image
    if(size.width && size.height && channels){
        //test if the size of the image is diferent then the last size
        if(this->frameSize.width == size.width &&
           this->frameSize.height == size.height &&
           this->frameChannels == channels
           ){
            //return true if have the vector
            if(this->frame) return true;
        }
        //else create a new frame

        //first delete the last frame
        this->deleteFrame();

        //set the size of the vector frame
        this->vectorFrameSize = (edk::uint32)(size.width * size.height * channels);

        //create the new frame
        if(this->vectorFrameSize){
            if( ( this->frame = new edk::uint8[this->vectorFrameSize] ) ){
                //save the new size
                this->frameSize = size;
                this->frameChannels = channels;
                //return true
                return true;
            }
        }
    }
    //else delete the frame
    this->deleteFrame();
    //else return false
    return false;
}
bool edk::codecs::CodecImage::newFrame(edk::uint32 width,edk::uint32 height,edk::uint8 channels){
    return this->newFrame(edk::size2ui32(width,height),channels);
}
//delete the frame
void edk::codecs::CodecImage::deleteFrame(){
    //test if have the frame
    if(this->frame){
        delete[] this->frame;
        this->frame=NULL;
    }
    //clean the size
    this->frameSize = edk::size2ui32(0u,0u);
    this->frameChannels=0.f;
    this->vectorFrameSize=0u;
}
//alloc a new frameEncoded
bool edk::codecs::CodecImage::newFrameEncoded(edk::uint32 size){
    //test the size of the frameEncoded
    if(size){
        //test if the size is are the same
        if(this->encodedSize == size){
            //return true if have the encoded
            if(this->encoded) return true;
        }
        //else delete the last encoded
        this->deleteEncoded();

        //create a new encoded
        if((this->encoded = new edk::uint8[size])){
            //save the encodedSize
            this->encodedSize = size;
            return true;
        }
    }
    //else delete the encoded
    this->deleteEncoded();
    return false;
}
//delete the encoded
void edk::codecs::CodecImage::deleteEncoded(){
    //test if have the encoded
    if(this->encoded){
        delete[] this->encoded;
        this->encoded=NULL;
    }
    //clean the size
    this->encodedSize = 0u;
}

//draw a image in the frame
bool edk::codecs::CodecImage::drawFrame(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels){
    //create a new frame
    if(this->newFrame(size,channels)){
        //copy the frame
        memcpy(this->frame,frame,this->vectorFrameSize);
        //then return true
        return true;
    }
    return false;
}
bool edk::codecs::CodecImage::drawFrame(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels){
    return this->drawFrame(frame,edk::size2ui32(width,height),channels);
}
//set the quality
bool edk::codecs::CodecImage::setQuality(edk::uint32 quality){
    //clean the quality
    this->encodedQuality=1u;
    if(quality){
        this->encodedQuality=quality;
        return true;
    }
    return false;
}
//get the frames
edk::uint8* edk::codecs::CodecImage::getFrame(){
    return this->frame;
}
edk::uint8* edk::codecs::CodecImage::getEncoded(){
    return this->encoded;
}
edk::uint8** edk::codecs::CodecImage::getEncodedPosition(){
    return &this->encoded;
}

//clean the pointers
edk::uint8* edk::codecs::CodecImage::cleanFrame(){
    edk::uint8* ret = this->frame;

    this->frame=NULL;
    //clean the size
    this->frameSize = edk::size2ui32(0u,0u);
    this->frameChannels=0u;
    this->vectorFrameSize=0u;

    return ret;
}
edk::uint8* edk::codecs::CodecImage::cleanEncoded(){
    edk::uint8* ret = this->encoded;

    this->frame=NULL;
    //clean the size
    this->encodedSize = 0u;

    return ret;
}

//return the size of the frame
edk::size2ui32 edk::codecs::CodecImage::getFrameSize(){
    return this->frameSize;
}
edk::uint32 edk::codecs::CodecImage::getFrameWidth(){
    return this->frameSize.width;
}
edk::uint32 edk::codecs::CodecImage::getFrameHeight(){
    return this->frameSize.height;
}
edk::uint32 edk::codecs::CodecImage::getFrameChannels(){
    return this->frameChannels;
}
edk::uint32 edk::codecs::CodecImage::getFrameVectorSize(){
    return this->vectorFrameSize;
}
//return the size of the encoded
edk::uint32 edk::codecs::CodecImage::getEncodedSize(){
    return this->encodedSize;
}
edk::uint32* edk::codecs::CodecImage::getEncodedSizePosition(){
    return &this->encodedSize;
}
edk::uint32 edk::codecs::CodecImage::getQuality(){
    return this->encodedQuality;
}
