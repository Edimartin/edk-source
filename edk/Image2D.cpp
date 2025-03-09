#include "Image2D.h"

/*
Library Image2D - Load a 2D Image using SFML
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
#pragma message "            Inside Image2D.cpp"
#endif

edk::Image2D::Image2D(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::Image2D::Image2D(char8 *imageFileName){
    this->classThis=NULL;edkEnd();
    this->Constructor(imageFileName,false);edkEnd();
}

edk::Image2D::Image2D(const char *imageFileName){
    this->classThis=NULL;edkEnd();
    this->Constructor(imageFileName,false);edkEnd();
}

edk::Image2D::~Image2D(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->clean();edkEnd();
    }
}

void edk::Image2D::Constructor(bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;
        //ctor
        this->imageName=NULL;edkEnd();
        this->imageFileName=NULL;edkEnd();
        this->vec = NULL;edkEnd();
        this->colors = NULL;edkEnd();
        this->channelsValue=0u;edkEnd();
        this->palette=NULL;edkEnd();
        this->paletteSize=0u;edkEnd();
        this->bytesPerColors=0u;edkEnd();
    }
}

void edk::Image2D::Constructor(char8 *imageFileName,bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;edkEnd();
        //clean all
        this->imageName=NULL;edkEnd();
        this->imageFileName=NULL;edkEnd();
        this->vec = NULL;edkEnd();
        this->colors = NULL;edkEnd();
        this->channelsValue=0u;edkEnd();
        this->palette=NULL;edkEnd();
        this->paletteSize=0u;edkEnd();
        this->bytesPerColors=0u;edkEnd();
        //load the image
        this->loadFromFile(imageFileName);edkEnd();
    }
}

void edk::Image2D::Constructor(const char *imageFileName,bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;edkEnd();
        //clean all
        this->imageName=NULL;edkEnd();
        this->imageFileName=NULL;edkEnd();
        this->vec = NULL;edkEnd();
        this->colors = NULL;edkEnd();
        this->channelsValue=0u;edkEnd();
        this->palette=NULL;edkEnd();
        this->paletteSize=0u;edkEnd();
        this->bytesPerColors=0u;edkEnd();
        //load the image
        this->loadFromFile(imageFileName);edkEnd();
    }
}

void edk::Image2D::clean(){
    this->deleteImage();edkEnd();
}


//Private
//imageFileNameFunctions
void edk::Image2D::setFileName(edk::char8* imageFileName){
    //delete the lastFileName
    this->deleteFileName();edkEnd();

    //test if the new imageFileName is alloc
    if(imageFileName){
        //then copy the imageFileName
        this->imageFileName = edk::String::strCopy(imageFileName);edkEnd();
    }
}
void edk::Image2D::setFileName(const edk::char8* imageFileName){
    //
    this->setFileName((edk::char8*) imageFileName);edkEnd();
}
void edk::Image2D::deleteFileName(){
    //test if have a imageFileName
    if(this->haveFileName()){
        //delete the imageFileName
        free(this->imageFileName);edkEnd();
    }
    this->imageFileName=NULL;edkEnd();
}
//discover the imageType
edk::uint8 edk::Image2D::getStreamType(edk::uint8* encoded){
    //test the stream encoded
    if(encoded){
        //test if are JPEG
        if(encoded[0u] == 0xFF){
            if(encoded[1u] == 0xD8){
                //return JPEG
                return EDK_CODEC_JPEG;edkEnd();
            }
        }
        else{
            if(encoded[0u] == 0x89){
                if(encoded[1u] == 0x50){
                    if(encoded[2u] == 0x4E){
                        if(encoded[3u] == 0x47){
                            return EDK_CODEC_PNG;edkEnd();
                        }
                    }
                }
            }
        }
    }
    return EDK_CODEC_NO;edkEnd();
}
//discover the nameType
edk::uint8 edk::Image2D::getNameType(edk::char8* name){
    //test the fileName
    if(name){
        //get the fileSize
        edk::uint32 size = edk::String::strSize(name);edkEnd();
        if(size>sizeof(".xxxx")){
            //go to the last character
            edk::char8* str = &name[size-1u];edkEnd();
            if(*str == 'g'){
                str--;edkEnd();
                if(*str == 'e'){
                    //
                    str--;edkEnd();
                    if(*str == 'p'){
                        //
                        str--;edkEnd();
                        if(*str == 'j'){
                            //
                            str--;edkEnd();
                            if(*str == '.'){
                                //it's a JPEG name
                                return EDK_CODEC_JPEG;edkEnd();
                            }
                        }
                    }
                }
                else if(*str == 'p'){
                    //
                    str--;edkEnd();
                    if(*str == 'j'){
                        //
                        str--;edkEnd();
                        if(*str == '.'){
                            //it's a JPEG name
                            return EDK_CODEC_JPEG;edkEnd();
                        }
                    }
                }
                else if(*str == 'n'){
                    //test if it's png
                    str--;edkEnd();
                    if(*str == 'p'){
                        //
                        str--;edkEnd();
                        if(*str == '.'){
                            //it's a PNG name
                            return EDK_CODEC_PNG;edkEnd();
                        }
                    }
                }
            }
            else if(*str == 'G'){
                str--;edkEnd();
                if(*str == 'E'){
                    //
                    str--;edkEnd();
                    if(*str == 'P'){
                        //
                        str--;edkEnd();
                        if(*str == 'J'){
                            //
                            str--;edkEnd();
                            if(*str == '.'){
                                //it's a JPEG name
                                return EDK_CODEC_JPEG;edkEnd();
                            }
                        }
                    }
                }
                else if(*str == 'P'){
                    //
                    str--;edkEnd();
                    if(*str == 'J'){
                        //
                        str--;edkEnd();

                        if(*str == '.'){
                            //it's a JPEG name
                            return EDK_CODEC_JPEG;edkEnd();
                        }
                    }
                }
                else if(*str == 'N'){
                    //test if it's png
                    str--;edkEnd();
                    if(*str == 'P'){
                        //
                        str--;edkEnd();
                        if(*str == '.'){
                            //it's a PNG name
                            return EDK_CODEC_PNG;edkEnd();
                        }
                    }
                }
            }
        }
    }
    return EDK_CODEC_NO;edkEnd();
}


//create a new Image
bool edk::Image2D::newImage(edk::char8 *imageName,edk::size2ui32 size,edk::uint8 channels){
    //delete the last image
    this->deleteImage();edkEnd();
    //test the new image
    if(imageName&&size.width&&size.height&&channels&&channels<=4u){
        //set the name
        if(this->setName(imageName)){
            //set the size
            this->size = size;edkEnd();
            this->channelsValue=channels;edkEnd();
            edk::uint32 imageSize = size.width*size.height;edkEnd();
            //create the new vector
            this->vec = (edk::uint8*)malloc(sizeof(edk::uint8) * (imageSize * this->channelsValue));edkEnd();
            if(this->vec){
                //return true
                return true;
            }
        }
    }
    this->deleteImage();edkEnd();
    return false;
}
bool edk::Image2D::newImage(edk::char8 *imageName,edk::uint32 width,edk::uint32 height,edk::uint8 channels){
    return this->newImage(imageName,edk::size2ui32(width,height),channels);edkEnd();
}
bool edk::Image2D::newImage(const edk::char8 *imageName,edk::size2ui32 size,edk::uint8 channels){
    return this->newImage((edk::char8 *)imageName,size,channels);edkEnd();
}
bool edk::Image2D::newImage(const edk::char8 *imageName,edk::uint32 width,edk::uint32 height,edk::uint8 channels){
    return this->newImage((edk::char8 *)imageName,width,height,channels);edkEnd();
}

//create a new image with a palette
bool edk::Image2D::newImage(edk::char8 *imageName,edk::size2ui32 size,edk::uint8 channels,edk::uint32 paletteSize){
    if(!paletteSize){
        return this->newImage(imageName,size,channels);
    }
    //delete the last image
    this->deleteImage();edkEnd();
    //test the new image
    if(imageName&&size.width&&size.height&&paletteSize&&channels&&channels<=4u){
        //set the name
        if(this->setName(imageName)){
            //set the size
            this->size = size;edkEnd();
            //clean the channels
            this->channelsValue=channels;edkEnd();
            //create the palette
            this->palette= (edk::uint8*)malloc(sizeof(edk::uint8) * (paletteSize * this->channelsValue));edkEnd();
            if(this->palette){
                this->paletteSize=paletteSize;edkEnd();

                edk::uint32 imageSize = size.width*size.height;edkEnd();

                //calculate the bits per pixel
                if(this->paletteSize<=0xFF){
                    this->bytesPerColors=1u;edkEnd();
                }
                else if(this->paletteSize<=0xFFFF){
                    this->bytesPerColors=2u;edkEnd();
                }
                else if(this->paletteSize<=0xFFFFFF){
                    this->bytesPerColors=3u;edkEnd();
                }
                else if(this->paletteSize<=0xFFFFFFFF){
                    this->bytesPerColors=4u;edkEnd();
                }

                //create the new vector
                this->colors = (edk::uint8*)malloc(sizeof(edk::uint8) * (imageSize * this->bytesPerColors));edkEnd();
                if(this->colors){
                    memset(this->colors,0u,imageSize * this->bytesPerColors);edkEnd();
                    //return true
                    return true;
                }
            }
        }
    }
    this->deleteImage();edkEnd();
    return false;
}
bool edk::Image2D::newImage(edk::char8 *imageName,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 paletteSize){
    return this->newImage(imageName,edk::size2ui32(width,height),channels,paletteSize);edkEnd();
}
bool edk::Image2D::newImage(const edk::char8 *imageName,edk::size2ui32 size,edk::uint8 channels,edk::uint32 paletteSize){
    return this->newImage((edk::char8 *)imageName,size,channels,paletteSize);edkEnd();
}
bool edk::Image2D::newImage(const edk::char8 *imageName,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 paletteSize){
    return this->newImage((edk::char8 *)imageName,width,height,channels,paletteSize);edkEnd();
}

bool edk::Image2D::loadFromFile(char8 *imageFileName)
{
    //open the file
    edk::File file;edkEnd();
    if(file.openBinFile(imageFileName)){
        if(file.getFileSize()){
            bool ret=false;edkEnd();
            //copy the file
            edk::uint8* fileVector = (edk::uint8*)malloc(sizeof(edk::uint8) * (file.getFileSize()));edkEnd();
            if(fileVector){
                //copy the file
                if(file.readBin(fileVector,file.getFileSize())){
                    //process the decoder
                    ret = this->loadFromMemory(fileVector,file.getFileSize());edkEnd();
                }
                free(fileVector);edkEnd();
                //test if neet delete the name
                if(ret){
                    if(!this->setName(imageFileName)){
                        ret=false;edkEnd();
                    }
                }
            }
            return ret;
        }
    }
    //delete the last image
    this->deleteImage();edkEnd();
    //delete the imageFileName
    this->deleteFileName();edkEnd();
    //else return false
    return false;
}

bool edk::Image2D::loadFromFile(const char *imageFileName){
    return this->loadFromFile((edk::char8*)imageFileName);edkEnd();
}

bool edk::Image2D::loadFromFileToRGB(char8 *imageFileName){
    //open the file
    edk::File file;edkEnd();
    if(file.openBinFile(imageFileName)){
        if(file.getFileSize()){
            bool ret=false;edkEnd();
            //copy the file
            edk::uint8* fileVector = (edk::uint8*)malloc(sizeof(edk::uint8) * (file.getFileSize()));edkEnd();
            if(fileVector){
                //copy the file
                if(file.readBin(fileVector,file.getFileSize())){
                    //process the decoder
                    ret = this->loadFromMemoryToRGB(fileVector,file.getFileSize());edkEnd();
                }
                free(fileVector);edkEnd();
                //test if neet delete the name
                if(ret){
                    if(!this->setName(imageFileName)){
                        ret=false;edkEnd();
                    }
                }
            }
            return ret;
        }
    }
    //delete the last image
    this->deleteImage();edkEnd();
    //delete the imageFileName
    this->deleteFileName();edkEnd();
    //else return false
    return false;
}

bool edk::Image2D::loadFromFileToRGB(const char *imageFileName){
    return this->loadFromFileToRGB((edk::char8*)imageFileName);edkEnd();
}

bool edk::Image2D::loadFromFileToRGBA(char8 *imageFileName){
    //open the file
    edk::File file;edkEnd();
    if(file.openBinFile(imageFileName)){
        if(file.getFileSize()){
            bool ret=false;edkEnd();
            //copy the file
            edk::uint8* fileVector = (edk::uint8*)malloc(sizeof(edk::uint8) * (file.getFileSize()));edkEnd();
            if(fileVector){
                //copy the file
                if(file.readBin(fileVector,file.getFileSize())){
                    //process the decoder
                    ret = this->loadFromMemoryToRGBA(fileVector,file.getFileSize());edkEnd();
                }
                free(fileVector);edkEnd();
                //test if neet delete the name
                if(ret){
                    if(!this->setName(imageFileName)){
                        ret=false;edkEnd();
                    }
                }
            }
            return ret;
        }
    }
    //delete the last image
    this->deleteImage();edkEnd();
    //delete the imageFileName
    this->deleteFileName();edkEnd();
    //else return false
    return false;
}

bool edk::Image2D::loadFromFileToRGBA(const char *imageFileName){
    return this->loadFromFileToRGBA((edk::char8*)imageFileName);edkEnd();
}

bool edk::Image2D::loadFromMemory(uint8 *image, edk::uint32 vecSize){
    //delete the vector
    this->deleteImage();edkEnd();
    //this->deleteName();edkEnd();
    if(image && vecSize){
        edk::uint8 type = this->getStreamType(image);edkEnd();
        switch(type){
        case EDK_CODEC_JPEG:
        {
            //decode using jpegCodec
            edk::codecs::DecoderJPEG decoder;edkEnd();
            if(decoder.decode(image,vecSize)){
                this->vec = decoder.getFrame();edkEnd();
                if(this->vec){
                    //get size
                    this->size = edk::size2ui32(decoder.getFrameWidth(),decoder.getFrameHeight());edkEnd();
                    //get channels
                    this->channelsValue = decoder.getFrameChannels();edkEnd();
                    decoder.cleanFrame();edkEnd();
                    return true;
                }
            }
        }
            break;
        case EDK_CODEC_PNG:
        {
            //decode using jpegCodec
            edk::codecs::DecoderPNG decoder;edkEnd();
            if(decoder.decode(image,vecSize)){
                this->vec = decoder.getFrame();edkEnd();
                if(this->vec){
                    //get size
                    this->size = edk::size2ui32(decoder.getFrameWidth(),decoder.getFrameHeight());edkEnd();
                    //get channels
                    this->channelsValue = decoder.getFrameChannels();edkEnd();
                    decoder.cleanFrame();edkEnd();
                    return true;
                }
            }
        }
            break;
        }
    }
    return false;
}

bool edk::Image2D::loadFromMemoryToRGB(uint8 *image, edk::uint32 vecSize){
    //delete the vector
    this->deleteImage();edkEnd();
    //this->deleteName();edkEnd();
    if(image && vecSize){
        edk::uint8 type = this->getStreamType(image);edkEnd();

        switch(type){
        case EDK_CODEC_JPEG:
        {
            //decode using jpegCodec
            edk::codecs::DecoderJPEG decoder;edkEnd();
            if(decoder.decode(image,vecSize)){
                edk::uint32 imageSize = decoder.getFrameWidth()*decoder.getFrameHeight();edkEnd();
                if(imageSize){
                    this->vec = (edk::uint8*)malloc(sizeof(edk::uint8) * (imageSize*3u));edkEnd();
                    if(this->vec){
                        //get channels
                        this->channelsValue = decoder.getFrameChannels();edkEnd();
                        if(this->channelsValue==1u || this->channelsValue == 3u){
                            //get size
                            this->size = edk::size2ui32(decoder.getFrameWidth(),decoder.getFrameHeight());edkEnd();
                            //Convert the frame to RGBA
                            edk::uint8* rgbaTemp = this->vec;edkEnd();
                            edk::uint8* frameTemp = decoder.getFrame();edkEnd();
                            switch(this->channelsValue){
                            case 1:
                                for(edk::uint32 i=0u;i<imageSize;i++){
                                    rgbaTemp[0u] = frameTemp[0u];edkEnd();
                                    rgbaTemp[1u] = frameTemp[0u];edkEnd();
                                    rgbaTemp[2u] = frameTemp[0u];edkEnd();
                                    rgbaTemp+=3u;edkEnd();
                                    frameTemp+=1u;edkEnd();
                                }
                                decoder.deleteFrame();edkEnd();
                                this->channelsValue=3u;edkEnd();
                                return true;
                            case 3:
                                if(this->vec){
                                    this->size = edk::size2ui32(decoder.getFrameWidth(),decoder.getFrameHeight());edkEnd();
                                    //just copy the frame in to the vec
                                    memcpy(this->vec,decoder.getFrame(),imageSize*3u);edkEnd();
                                    decoder.deleteFrame();edkEnd();
                                    this->channelsValue=3u;edkEnd();
                                    return true;
                                }
                            }
                        }
                        free(this->vec);edkEnd();
                        this->vec=NULL;edkEnd();
                    }
                }
            }
        }
            break;
        case EDK_CODEC_PNG:
        {
            //decode using jpegCodec
            edk::codecs::DecoderPNG decoder;edkEnd();
            if(decoder.decode(image,vecSize)){
                edk::uint32 imageSize = decoder.getFrameWidth()*decoder.getFrameHeight();edkEnd();
                if(imageSize){
                    this->vec = (edk::uint8*)malloc(sizeof(edk::uint8) * (imageSize*3u));edkEnd();
                    if(this->vec){
                        //get channels
                        this->channelsValue = decoder.getFrameChannels();edkEnd();
                        if(this->channelsValue==1u || this->channelsValue==2u || this->channelsValue == 4u){
                            //get size
                            this->size = edk::size2ui32(decoder.getFrameWidth(),decoder.getFrameHeight());edkEnd();
                            //Convert the frame to RGBA
                            edk::uint8* rgbaTemp = this->vec;edkEnd();
                            edk::uint8* frameTemp = decoder.getFrame();edkEnd();
                            switch(this->channelsValue){
                            case 1:
                                for(edk::uint32 i=0u;i<imageSize;i++){
                                    rgbaTemp[0u] = frameTemp[0u];edkEnd();
                                    rgbaTemp[1u] = frameTemp[0u];edkEnd();
                                    rgbaTemp[2u] = frameTemp[0u];edkEnd();
                                    rgbaTemp+=3u;edkEnd();
                                    frameTemp+=1u;edkEnd();
                                }
                                decoder.deleteFrame();edkEnd();
                                this->channelsValue=3u;edkEnd();
                                return true;
                            case 2:
                                for(edk::uint32 i=0u;i<imageSize;i++){
                                    rgbaTemp[0u] = frameTemp[0u];edkEnd();
                                    rgbaTemp[1u] = frameTemp[0u];edkEnd();
                                    rgbaTemp[2u] = frameTemp[0u];edkEnd();
                                    rgbaTemp+=3u;edkEnd();
                                    frameTemp+=2u;edkEnd();
                                }
                                decoder.deleteFrame();edkEnd();
                                this->channelsValue=3u;edkEnd();
                                return true;
                            case 4:
                                for(edk::uint32 i=0u;i<imageSize;i++){
                                    rgbaTemp[0u] = frameTemp[0u];edkEnd();
                                    rgbaTemp[1u] = frameTemp[1u];edkEnd();
                                    rgbaTemp[2u] = frameTemp[2u];edkEnd();
                                    rgbaTemp+=3u;edkEnd();
                                    frameTemp+=4u;edkEnd();
                                }
                                decoder.deleteFrame();edkEnd();
                                this->channelsValue=3u;edkEnd();
                                return true;
                            }
                        }
                        else if(this->channelsValue==3u){
                            //The image aready have 3 channels
                            if(this->vec){
                                this->size = edk::size2ui32(decoder.getFrameWidth(),decoder.getFrameHeight());edkEnd();
                                //just copy the frame in to the vec
                                memcpy(this->vec,decoder.getFrame(),imageSize*3u);edkEnd();
                                decoder.deleteFrame();edkEnd();
                                this->channelsValue=3u;edkEnd();
                                return true;
                            }
                        }
                    }
                }
                free(this->vec);edkEnd();
                this->vec=NULL;edkEnd();
            }
        }
            break;
        }
    }
    return false;
}

bool edk::Image2D::loadFromMemoryToRGBA(uint8 *image, edk::uint32 vecSize){
    //delete the vector
    this->deleteImage();edkEnd();
    //this->deleteName();edkEnd();
    if(image && vecSize){
        edk::uint8 type = this->getStreamType(image);edkEnd();

        switch(type){
        case EDK_CODEC_JPEG:
        {
            //decode using jpegCodec
            edk::codecs::DecoderJPEG decoder;edkEnd();
            if(decoder.decode(image,vecSize)){
                edk::uint32 imageSize = decoder.getFrameWidth()*decoder.getFrameHeight();edkEnd();
                if(imageSize){
                    this->vec = (edk::uint8*)malloc(sizeof(edk::uint8) * (imageSize*4u));edkEnd();
                    if(this->vec){
                        //get channels
                        this->channelsValue = decoder.getFrameChannels();edkEnd();
                        if(this->channelsValue==1u || this->channelsValue == 3u){
                            //get size
                            this->size = edk::size2ui32(decoder.getFrameWidth(),decoder.getFrameHeight());edkEnd();
                            //Convert the frame to RGBA
                            edk::uint8* rgbaTemp = this->vec;edkEnd();
                            edk::uint8* frameTemp = decoder.getFrame();edkEnd();
                            switch(this->channelsValue){
                            case 1:
                                for(edk::uint32 i=0u;i<imageSize;i++){
                                    rgbaTemp[0u] = frameTemp[0u];edkEnd();
                                    rgbaTemp[1u] = frameTemp[0u];edkEnd();
                                    rgbaTemp[2u] = frameTemp[0u];edkEnd();
                                    rgbaTemp[3u] = 255u;edkEnd();
                                    rgbaTemp+=4u;edkEnd();
                                    frameTemp+=1u;edkEnd();
                                }
                                decoder.deleteFrame();edkEnd();
                                this->channelsValue=4u;edkEnd();
                                return true;
                            case 3:
                                for(edk::uint32 i=0u;i<imageSize;i++){
                                    rgbaTemp[0u] = frameTemp[0u];edkEnd();
                                    rgbaTemp[1u] = frameTemp[1u];edkEnd();
                                    rgbaTemp[2u] = frameTemp[2u];edkEnd();
                                    rgbaTemp[3u] = 255u;edkEnd();
                                    rgbaTemp+=4u;edkEnd();
                                    frameTemp+=3u;edkEnd();
                                }
                                decoder.deleteFrame();edkEnd();
                                this->channelsValue=4u;edkEnd();
                                return true;
                            }
                        }
                        delete this->vec;edkEnd();
                        this->vec=NULL;edkEnd();
                    }
                }
            }
        }
            break;
        case EDK_CODEC_PNG:
        {
            //decode using jpegCodec
            edk::codecs::DecoderPNG decoder;edkEnd();
            if(decoder.decode(image,vecSize)){
                edk::uint32 imageSize = decoder.getFrameWidth()*decoder.getFrameHeight();edkEnd();
                if(imageSize){
                    this->vec = (edk::uint8*)malloc(sizeof(edk::uint8) * (imageSize*4u));edkEnd();
                    if(this->vec){
                        //get channels
                        this->channelsValue = decoder.getFrameChannels();edkEnd();
                        if(this->channelsValue==1u || this->channelsValue==2u || this->channelsValue == 3u){
                            //get size
                            this->size = edk::size2ui32(decoder.getFrameWidth(),decoder.getFrameHeight());edkEnd();
                            //Convert the frame to RGBA
                            edk::uint8* rgbaTemp = this->vec;edkEnd();
                            edk::uint8* frameTemp = decoder.getFrame();edkEnd();
                            switch(this->channelsValue){
                            case 1:
                                for(edk::uint32 i=0u;i<imageSize;i++){
                                    rgbaTemp[0u] = frameTemp[0u];edkEnd();
                                    rgbaTemp[1u] = frameTemp[0u];edkEnd();
                                    rgbaTemp[2u] = frameTemp[0u];edkEnd();
                                    rgbaTemp[3u] = 255u;edkEnd();
                                    rgbaTemp+=4u;edkEnd();
                                    frameTemp+=1u;edkEnd();
                                }
                                decoder.deleteFrame();edkEnd();
                                this->channelsValue=4u;edkEnd();
                                return true;
                            case 2:
                                for(edk::uint32 i=0u;i<imageSize;i++){
                                    rgbaTemp[0u] = frameTemp[0u];edkEnd();
                                    rgbaTemp[1u] = frameTemp[0u];edkEnd();
                                    rgbaTemp[2u] = frameTemp[0u];edkEnd();
                                    rgbaTemp[3u] = frameTemp[1u];edkEnd();
                                    rgbaTemp+=4u;edkEnd();
                                    frameTemp+=2u;edkEnd();
                                }
                                decoder.deleteFrame();edkEnd();
                                this->channelsValue=4u;edkEnd();
                                return true;
                            case 3:
                                for(edk::uint32 i=0u;i<imageSize;i++){
                                    rgbaTemp[0u] = frameTemp[0u];edkEnd();
                                    rgbaTemp[1u] = frameTemp[1u];edkEnd();
                                    rgbaTemp[2u] = frameTemp[2u];edkEnd();
                                    rgbaTemp[3u] = 255u;edkEnd();
                                    rgbaTemp+=4u;edkEnd();
                                    frameTemp+=3u;edkEnd();
                                }
                                decoder.deleteFrame();edkEnd();
                                this->channelsValue=4u;edkEnd();
                                return true;
                            }
                        }
                        else if(this->channelsValue==4u){
                            //The image aready have 4 channels
                            if(this->vec){
                                this->size = edk::size2ui32(decoder.getFrameWidth(),decoder.getFrameHeight());edkEnd();
                                //just copy the frame in to the vec
                                memcpy(this->vec,decoder.getFrame(),imageSize*4u);edkEnd();
                                decoder.deleteFrame();edkEnd();
                                this->channelsValue=4u;edkEnd();
                                return true;
                            }
                        }
                        delete this->vec;edkEnd();
                        this->vec=NULL;edkEnd();
                    }
                }
            }
        }
            break;
        }
    }
    return false;
}

//function used to generate the pixels from colors palette
bool edk::Image2D::generatePixelsFromColors(){
    //test if have the image
    edk::uint32 width = this->getWidth();edkEnd();
    edk::uint32 height = this->getHeight();edkEnd();
    edk::uint8 channels = this->getChannels();edkEnd();
    edk::uint8 bytes = this->bytesPerColors;edkEnd();
    edk::uint8* palette = this->palette;edkEnd();
    edk::uint32 paletteSize = this->paletteSize;edkEnd();

    if(this->haveImage() && width && height && channels && this->haveColors() && bytes && palette && paletteSize){
        //delete the last vector
        if(this->vec){
            free(this->vec);edkEnd();
        }
        //create a new vec
        this->vec = (edk::uint8*)malloc(sizeof(edk::uint8) * (width*height*channels));edkEnd();
        //create the new vec to set the pixels
        if(this->vec){
            //copy the colors in to pixels
            //pixel vector
            edk::uint8* vector = this->vec;edkEnd();
            //color id vector
            edk::uint8* colors = this->colors;edkEnd();
            //color id vector
            //edk::uint8* color = NULL;edkEnd();

            switch(bytes){
            case 1u:
            {
                //color id
                edk::uint8 colorID;edkEnd();
                //copy the colors into pixels
                for(edk::uint32 y=0u;y<height;y++){
                    for(edk::uint32 x=0u;x<width;x++){
                        mempcpy(&colorID,colors,sizeof(colorID));edkEnd();
                        if(colorID < paletteSize){
                            //convert the color ID to the pixel channel
                            memcpy(vector,&palette[colorID*channels],channels);edkEnd();
                        }
                        //increment the vectors and colors
                        vector+=channels;edkEnd();
                        colors+=bytes;edkEnd();
                    }
                }
            }
                break;
            case 2u:
            {
                //
                edk::uint16 colorID;edkEnd();
                //copy the colors into pixels
                for(edk::uint32 y=0u;y<height;y++){
                    for(edk::uint32 x=0u;x<width;x++){
                        mempcpy(&colorID,colors,sizeof(colorID));edkEnd();
                        if(colorID < paletteSize){
                            //convert the color ID to the pixel channel
                            memcpy(vector,&palette[colorID*channels],channels);edkEnd();
                        }
                        //increment the vectors and colors
                        vector+=channels;edkEnd();
                        colors+=bytes;edkEnd();
                    }
                }
            }
                break;
            case 3u:
            {
                //
                edk::uint32 colorID;edkEnd();
                //copy the colors into pixels
                for(edk::uint32 y=0u;y<height;y++){
                    for(edk::uint32 x=0u;x<width;x++){
                        mempcpy(&colorID,colors,/*sizeof(colorID)*/3u);edkEnd();
                        if(colorID < paletteSize){
                            //convert the color ID to the pixel channel
                            memcpy(vector,&palette[colorID*channels],channels);edkEnd();
                        }
                        //increment the vectors and colors
                        vector+=channels;edkEnd();
                        colors+=bytes;edkEnd();
                    }
                }
            }
                break;
            case 4u:
            {
                //
                edk::uint32 colorID;edkEnd();
                //copy the colors into pixels
                for(edk::uint32 y=0u;y<height;y++){
                    for(edk::uint32 x=0u;x<width;x++){
                        mempcpy(&colorID,colors,sizeof(colorID));edkEnd();
                        if(colorID < paletteSize){
                            //convert the color ID to the pixel channel
                            memcpy(vector,&palette[colorID*channels],channels);edkEnd();
                        }
                        //increment the vectors and colors
                        vector+=channels;edkEnd();
                        colors+=bytes;edkEnd();
                    }
                }
            }
                break;
            default:
                return false;
            }
            return true;
        }
    }
    return false;
}

//save the image
bool edk::Image2D::saveToFile(edk::char8 *fileName){
    //test if have image
    if(this->haveImage()){
        bool deleteTempName=false;edkEnd();
        bool ret=false;edkEnd();

        //get the name type
        edk::uint8 nameType = getNameType(fileName);edkEnd();

        //test the channels
        switch(this->getChannels()){
        case 2u:
            //save jpeg
            if(!fileName){
                fileName = edk::String::strCat(this->getName(),(edk::char8*)".png");edkEnd();
                deleteTempName = true;edkEnd();
                nameType = EDK_CODEC_JPEG;edkEnd();
            }
            if(fileName){
                if(nameType==EDK_CODEC_NO){
                    nameType=EDK_CODEC_PNG;
                    //concatenate .png with the name
                    fileName = edk::String::strCat(fileName,(edk::char8*)".png");edkEnd();
                    deleteTempName = true;edkEnd();
                }
                switch(nameType){
                case EDK_CODEC_PNG:
                {
                    //save the encoder
                    edk::codecs::EncoderPNG encoder;edkEnd();
                    ret = encoder.encodeToFile(this->vec,this->size.width,this->size.height,this->channelsValue,9,fileName);edkEnd();
                    if(deleteTempName){
                        free(fileName);edkEnd();
                    }
                    break;
                }
                case EDK_CODEC_JPEG:
                {
                    ret = false;edkEnd();
                    if(deleteTempName){
                        free(fileName);edkEnd();
                    }
                    break;
                }
                }
            }
            break;
        case 1u:
        case 3u:
            //save jpeg
            if(!fileName){
                fileName = edk::String::strCat(this->getName(),(edk::char8*)".jpg");edkEnd();
                deleteTempName = true;edkEnd();
                nameType = EDK_CODEC_JPEG;edkEnd();
            }
            if(fileName){
                if(nameType==EDK_CODEC_NO){
                    nameType=EDK_CODEC_PNG;
                    //concatenate .jpg with the name
                    fileName = edk::String::strCat(fileName,(edk::char8*)".jpg");edkEnd();
                    deleteTempName = true;edkEnd();
                }
                switch(nameType){
                case EDK_CODEC_JPEG:
                {
                    //save the encoder
                    edk::codecs::EncoderJPEG encoder;edkEnd();
                    ret = encoder.encodeToFile(this->vec,this->size.width,this->size.height,this->channelsValue,90,fileName);edkEnd();
                    if(deleteTempName){
                        free(fileName);edkEnd();
                    }
                    break;
                }
                case EDK_CODEC_PNG:
                {
                    //save the encoder
                    edk::codecs::EncoderPNG encoder;edkEnd();
                    ret = encoder.encodeToFile(this->vec,this->size.width,this->size.height,this->channelsValue,9,fileName);edkEnd();
                    if(deleteTempName){
                        free(fileName);edkEnd();
                    }
                    break;
                }
                }
            }
            break;
        case 4u:
            //save jpeg
            if(!fileName){
                fileName = edk::String::strCat(this->getName(),(edk::char8*)".png");edkEnd();
                deleteTempName = true;edkEnd();
                nameType = EDK_CODEC_PNG;edkEnd();
            }
            if(fileName){
                if(nameType==EDK_CODEC_NO){
                    nameType=EDK_CODEC_PNG;
                    //concatenate .jpg with the name
                    fileName = edk::String::strCat(fileName,(edk::char8*)".png");edkEnd();
                    deleteTempName = true;edkEnd();
                }
                switch(nameType){
                case EDK_CODEC_PNG:
                {
                    //save the encoder
                    edk::codecs::EncoderPNG encoder;edkEnd();
                    ret = encoder.encodeToFile(this->vec,this->size.width,this->size.height,this->channelsValue,9,fileName);edkEnd();
                    if(deleteTempName){
                        free(fileName);edkEnd();
                    }
                    break;
                }
                case EDK_CODEC_JPEG:
                {
                    //create a new image and convert the frame to rgb
                    edk::uint8* temp = (edk::uint8*)malloc(sizeof(edk::uint8) * (this->size.width * this->size.height * 3u));edkEnd();
                    if(temp){
                        //convert the image
                        if(edk::Image2D::imageClone(this->vec,this->size.width,this->size.height,this->channelsValue,
                                                    temp,this->size.width,this->size.height,3u,
                                                    0u,0u
                                                    )){
                            //save the image as JPEG
                            edk::codecs::EncoderJPEG encoder;edkEnd();
                            ret = encoder.encodeToFile(temp,this->size.width,this->size.height,3u,90,fileName);edkEnd();
                        }
                        free(temp);edkEnd();
                    }
                    if(deleteTempName){
                        free(fileName);edkEnd();
                    }
                    break;
                }
                }
            }
            break;
        }
        return ret;
    }
    return false;
}
bool edk::Image2D::saveToFile(const char *fileName){
    return this->saveToFile((edk::char8 *)fileName);edkEnd();
}

bool edk::Image2D::setName(char8 *imageName)
{
    //delete the last imageName
    this->deleteName();edkEnd();

    //test if the new imageName is alloc
    if(imageName){
        //then copy the imageName
        return (bool)(this->imageName = edk::String::strCopy(imageName));edkEnd();
    }
    //else return false
    return false;
}

bool edk::Image2D::setName(const char *imageName)
{
    return this->setName((edk::char8*) imageName);edkEnd();
}

//draw on the image
bool edk::Image2D::draw(edk::uint8* pixels){
    if(pixels && this->haveImage()){
        memcpy(this->vec,pixels,this->getWidth()*this->getHeight()*this->getChannels());edkEnd();
        return true;
    }
    return false;
}
//draw a color in the image vector
bool edk::Image2D::drawPosition(edk::vec2ui32 position,edk::uint8* color){
    if(position.x < this->getWidth() && position.y<this->getHeight() && color){
        memcpy(&this->vec[(position.x + (position.y*this->getHeight())) * this->channelsValue],color,this->channelsValue);edkEnd();
        return true;
    }
    return false;
}
bool edk::Image2D::drawPosition(edk::vec2ui32 position,edk::uint8 g){
    edk::uint8 color[4u] = {g,1u,0u,0u};
    return this->drawPosition(position,(edk::uint8*)&color);edkEnd();
}
bool edk::Image2D::drawPosition(edk::vec2ui32 position,edk::uint8 g,edk::uint8 a){
    edk::uint8 color[4u] = {g,a,0u,0u};
    return this->drawPosition(position,(edk::uint8*)&color);edkEnd();
}
bool edk::Image2D::drawPosition(edk::vec2ui32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b){
    edk::uint8 color[4u] = {r,g,b,1u};
    return this->drawPosition(position,(edk::uint8*)&color);edkEnd();
}
bool edk::Image2D::drawPosition(edk::vec2ui32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
    edk::uint8 color[4u] = {r,g,b,a};
    return this->drawPosition(position,(edk::uint8*)&color);edkEnd();
}
bool edk::Image2D::drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint8* color){
    return this->drawPosition(edk::vec2ui32(positionX,positionY),color);edkEnd();
}
bool edk::Image2D::drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint8 g){
    return this->drawPosition(edk::vec2ui32(positionX,positionY),g);edkEnd();
}
bool edk::Image2D::drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint8 g,edk::uint8 a){
    return this->drawPosition(edk::vec2ui32(positionX,positionY),g,a);edkEnd();
}
bool edk::Image2D::drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return this->drawPosition(edk::vec2ui32(positionX,positionY),r,g,b);edkEnd();
}
bool edk::Image2D::drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
    return this->drawPosition(edk::vec2ui32(positionX,positionY),r,g,b,a);edkEnd();
}
bool edk::Image2D::drawPosition(edk::uint32 position,edk::uint8* color){
    if(position < (this->getWidth()*this->getHeight()) && color){
        memcpy(&this->vec[position * this->channelsValue],color,this->channelsValue);edkEnd();
        return true;
    }
    return false;
}
bool edk::Image2D::drawPosition(edk::uint32 position,edk::uint8 g){
    edk::uint8 color[4u] = {g,1u,0u,0u};
    return this->drawPosition(position,(edk::uint8*)&color);edkEnd();
}
bool edk::Image2D::drawPosition(edk::uint32 position,edk::uint8 g,edk::uint8 a){
    edk::uint8 color[4u] = {g,a,0u,0u};
    return this->drawPosition(position,(edk::uint8*)&color);edkEnd();
}
bool edk::Image2D::drawPosition(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b){
    edk::uint8 color[4u] = {r,g,b,1u};
    return this->drawPosition(position,(edk::uint8*)&color);edkEnd();
}
bool edk::Image2D::drawPosition(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
    edk::uint8 color[4u] = {r,g,b,a};
    return this->drawPosition(position,(edk::uint8*)&color);edkEnd();
}
//draw the colors on the palette. The user need to know the size of the palette multiply by channel size
bool edk::Image2D::drawPalette(edk::uint8* colors){
    if(colors && this->havePalette()){
        memcpy(this->colors,colors,this->getWidth()*this->getHeight()*this->getChannels());edkEnd();
        return true;
    }
    return false;
}
//draw a color in palette position
bool edk::Image2D::drawPalettePosition(edk::uint32 position,edk::uint8* color){
    if(position < this->paletteSize && color && this->palette){
        //set the color
        memcpy(&this->palette[position],color,this->channelsValue);edkEnd();
        return true;
    }
    return false;
}
bool edk::Image2D::drawPalettePosition(edk::uint32 position,edk::uint8 g){
    edk::uint8 color[4u] = {g,1u,0u,0u};
    return this->drawPalettePosition(position,(edk::uint8*)&color);edkEnd();
}
bool edk::Image2D::drawPalettePosition(edk::uint32 position,edk::uint8 g,edk::uint8 a){
    edk::uint8 color[4u] = {g,a,0u,0u};
    return this->drawPalettePosition(position,(edk::uint8*)&color);edkEnd();
}
bool edk::Image2D::drawPalettePosition(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b){
    edk::uint8 color[4u] = {r,g,b,1u};
    return this->drawPalettePosition(position,(edk::uint8*)&color);edkEnd();
}
bool edk::Image2D::drawPalettePosition(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
    edk::uint8 color[4u] = {r,g,b,a};
    return this->drawPalettePosition(position,(edk::uint8*)&color);edkEnd();
}
//draw the colorIDs in the image using the palette positions. The user need to know the colors size which is the paletteSize multiply by bytesPerColor
bool edk::Image2D::drawColors(edk::uint8* colors){
    if(this->colors && colors && this->getWidth() && getHeight() && this->getBytesPerColor()){
        memcpy(this->colors,colors,this->getWidth()*this->getHeight()*this->getBytesPerColor());edkEnd();
        return true;
    }
    return false;
}
//draw a color position from the palette in colors vector.
bool edk::Image2D::drawColorsPosition(edk::vec2ui32 position,edk::uint8* colorID){
    if(position.x < this->getWidth() && position.y<this->getHeight() && colorID){
        edk::uint32 i = (position.x + (position.y*this->getHeight())) * this->bytesPerColors;edkEnd();
        memcpy(&this->colors[i],colorID,this->bytesPerColors);edkEnd();
        return true;
    }
    return false;
}
bool edk::Image2D::drawColorsPosition(edk::vec2ui32 position,edk::uint8 colorID){
    switch(this->bytesPerColors){
    case 1u:
    {
        edk::uint8 color = colorID;edkEnd();
        return this->drawColorsPosition(position,(edk::uint8*)&color);
    }
    case 2u:
    {
        edk::uint8 color[2u] = {0u,colorID};
        return this->drawColorsPosition(position,(edk::uint8*)&color);
    }
    case 3u:
    {
        edk::uint8 color[3u] = {0u,0u,colorID};
        return this->drawColorsPosition(position,(edk::uint8*)&color);
    }
    case 4u:
    {
        edk::uint8 color[4u] = {0u,0u,0u,colorID};
        return this->drawColorsPosition(position,(edk::uint8*)&color);
    }
    }
    return false;
}
bool edk::Image2D::drawColorsPosition(edk::vec2ui32 position,edk::uint16 colorID){
    switch(this->bytesPerColors){
    case 1u:
    {
        edk::uint8 color = (edk::uint8)colorID;edkEnd();
        return this->drawColorsPosition(position,(edk::uint8*)&color);
    }
    case 2u:
    {
        edk::uint8 color[2u] = {((edk::uint8*)&colorID)[0u],((edk::uint8*)&colorID)[1u]};
        return this->drawColorsPosition(position,(edk::uint8*)&color);
    }
    case 3u:
    {
        edk::uint8 color[3u] = {0u,((edk::uint8*)&colorID)[0u],((edk::uint8*)&colorID)[1u]};
        return this->drawColorsPosition(position,(edk::uint8*)&color);
    }
    case 4u:
    {
        edk::uint8 color[4u] = {0u,0u,((edk::uint8*)&colorID)[0u],((edk::uint8*)&colorID)[1u]};
        return this->drawColorsPosition(position,(edk::uint8*)&color);
    }
    }
    return false;
}
bool edk::Image2D::drawColorsPosition(edk::vec2ui32 position,edk::uint32 colorID){
    switch(this->bytesPerColors){
    case 1u:
    {
        edk::uint8 color = (edk::uint8)colorID;edkEnd();
        return this->drawColorsPosition(position,(edk::uint8*)&color);
    }
    case 2u:
    {
        edk::uint8 color[2u] = {((edk::uint8*)&colorID)[2u],((edk::uint8*)&colorID)[3u]};
        return this->drawColorsPosition(position,(edk::uint8*)&color);
    }
    case 3u:
    {
        edk::uint8 color[3u] = {((edk::uint8*)&colorID)[1u],((edk::uint8*)&colorID)[2u],((edk::uint8*)&colorID)[3u]};
        return this->drawColorsPosition(position,(edk::uint8*)&color);
    }
    case 4u:
    {
        edk::uint8 color[4u] = {((edk::uint8*)&colorID)[0u],((edk::uint8*)&colorID)[1u],((edk::uint8*)&colorID)[2u],((edk::uint8*)&colorID)[3u]};
        return this->drawColorsPosition(position,(edk::uint8*)&color);
    }
    }
    return false;
}
bool edk::Image2D::drawColorsPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint8* colorID){
    return this->drawColorsPosition(edk::vec2ui32(positionX,positionY),colorID);
}
bool edk::Image2D::drawColorsPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint8 colorID){
    return this->drawColorsPosition(edk::vec2ui32(positionX,positionY),colorID);
}
bool edk::Image2D::drawColorsPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint16 colorID){
    return this->drawColorsPosition(edk::vec2ui32(positionX,positionY),colorID);
}
bool edk::Image2D::drawColorsPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 colorID){
    return this->drawColorsPosition(edk::vec2ui32(positionX,positionY),colorID);
}

edk::size2ui32 edk::Image2D::getSize()
{
    //test if have a image
    return this->size;edkEnd();
}

edk::uint32 edk::Image2D::getWidth(){
    return this->getSize().width;edkEnd();
}

edk::uint32 edk::Image2D::getHeight(){
    return this->getSize().height;edkEnd();
}

edk::uint32 edk::Image2D::width()
{
    return this->getSize().width;edkEnd();
}

edk::uint32 edk::Image2D::height()
{
    return this->getSize().height;edkEnd();
}
//return the channels of the image
edk::uint8 edk::Image2D::getChannels(){
    return this->channelsValue;
}
edk::uint8 edk::Image2D::channels(){
    return this->channelsValue;
}
//return the bytes per color to set the color values with the palette positions.
edk::uint8 edk::Image2D::getBytesPerColor(){
    return this->bytesPerColors;edkEnd();
}

edk::uint32 edk::Image2D::getPaletteSize(){
    return this->paletteSize;edkEnd();
}
//get the vector size
edk::uint32 edk::Image2D::getPixelsLenght(){
    return this->getWidth() * this->getHeight() * this->getChannels();edkEnd();
}
//get the palette size
edk::uint32 edk::Image2D::getPaletteLenght(){
    return this->getPaletteSize() * this->getChannels();edkEnd();
}
//get the colors lenght returh the colors vector lenght with the palette ID's
edk::uint32 edk::Image2D::getColorsLenght(){
    return this->getBytesPerColor() * this->getWidth() * this->getHeight();edkEnd();
}

bool edk::Image2D::haveImage()
{
    return (bool)this->vec;edkEnd();
}

bool edk::Image2D::haveColors(){
    return (bool)this->colors;edkEnd();
}

bool edk::Image2D::havePalette(){
    return (bool)this->palette;edkEnd();
}

bool edk::Image2D::haveName()
{
    return (bool)this->imageName;edkEnd();
}

bool edk::Image2D::haveFileName()
{
    return (bool)this->imageFileName;edkEnd();
}

edk::char8* edk::Image2D::getName()
{
    return this->imageName;edkEnd();
}

edk::char8* edk::Image2D::name()
{
    return this->getName();edkEnd();
}

edk::char8* edk::Image2D::getFileName()
{
    return this->imageFileName;edkEnd();
}

edk::char8* edk::Image2D::fileName()
{
    return this->getFileName();edkEnd();
}

//return the pixels of the image to use in videoBoard
edk::uint8* edk::Image2D::getPixels(){
    //test if open the image
    if(this->haveImage()){
        //then return the pointer
        return this->vec;edkEnd();
    }
    //else return false
    return NULL;
}
edk::uint8 edk::Image2D::getPixelR(edk::vec2ui32 position){
    edk::uint8 ret=0u;
    if(position.x<this->getWidth()
            && position.y<this->getHeight()
            && (this->getChannels() == 3u || this->getChannels() == 4u)
            ){
        ret = this->vec[(((position.y*this->getWidth())
                          + position.x) * this->getChannels())
                + 0u
                ];
    }
    return ret;
}
edk::uint8 edk::Image2D::getPixelR(edk::uint32 x,edk::uint32 y){
    return this->getPixelR(edk::vec2ui32(x,y));
}
edk::uint8 edk::Image2D::getPixelG(edk::vec2ui32 position){
    edk::uint8 ret=0u;
    if(position.x<this->getWidth()
            && position.y<this->getHeight()
            && (this->getChannels() == 3u || this->getChannels() == 4u)
            ){
        ret = this->vec[(((position.y*this->getWidth())
                          + position.x) * this->getChannels())
                + 1u
                ];
    }
    return ret;
}
edk::uint8 edk::Image2D::getPixelG(edk::uint32 x,edk::uint32 y){
    return this->getPixelG(edk::vec2ui32(x,y));
}
edk::uint8 edk::Image2D::getPixelB(edk::vec2ui32 position){
    edk::uint8 ret=0u;
    if(position.x<this->getWidth()
            && position.y<this->getHeight()
            && (this->getChannels() == 3u || this->getChannels() == 4u)
            ){
        ret = this->vec[(((position.y*this->getWidth())
                          + position.x) * this->getChannels())
                + 2u
                ];
    }
    return ret;
}
edk::uint8 edk::Image2D::getPixelB(edk::uint32 x,edk::uint32 y){
    return this->getPixelB(edk::vec2ui32(x,y));
}
edk::uint8 edk::Image2D::getPixelGray(edk::vec2ui32 position){
    edk::uint8 ret=0u;
    if(position.x<this->getWidth()
            && position.y<this->getHeight()
            && (this->getChannels() == 1u || this->getChannels() == 2u)
            ){
        ret = this->vec[(((position.y*this->getWidth())
                          + position.x) * this->getChannels())
                + 0u
                ];
    }
    return ret;
}
edk::uint8 edk::Image2D::getPixelGray(edk::uint32 x,edk::uint32 y){
    return this->getPixelGray(edk::vec2ui32(x,y));
}
edk::uint8 edk::Image2D::getPixelA(edk::vec2ui32 position){
    edk::uint8 ret=0u;
    if(position.x<this->getWidth()
            && position.y<this->getHeight()
            && (this->getChannels() == 2u || this->getChannels() == 4u)
            ){
        ret = this->vec[(((position.y*this->getWidth())
                          + position.x) * this->getChannels())
                + this->getChannels()-1u
                ];
    }
    return ret;
}
edk::uint8 edk::Image2D::getPixelA(edk::uint32 x,edk::uint32 y){
    return this->getPixelA(edk::vec2ui32(x,y));
}
edk::color3ui8 edk::Image2D::getPixelRGB(edk::vec2ui32 position){
    edk::color3ui8 ret;
    ret.r=0u;
    ret.g=0u;
    ret.b=0u;
    if(position.x<this->getWidth()
            && position.y<this->getHeight()
            && (this->getChannels() == 3u || this->getChannels() == 4u)
            ){
        edk::uint32 newPosition = (((position.y*this->getWidth())
                                    + position.x) * this->getChannels());
        ret.r = this->vec[newPosition + 0u];
        ret.g = this->vec[newPosition + 1u];
        ret.b = this->vec[newPosition + 2u];
    }
    return ret;
}
edk::color3ui8 edk::Image2D::getPixelRGB(edk::uint32 x,edk::uint32 y){
    return this->getPixelRGB(edk::vec2ui32(x,y));
}
edk::color4ui8 edk::Image2D::getPixelRGBA(edk::vec2ui32 position){
    edk::color4ui8 ret;
    ret.r=0u;
    ret.g=0u;
    ret.b=0u;
    ret.a=0u;
    if(position.x<this->getWidth()
            && position.y<this->getHeight()
            && this->getChannels() == 4u
            ){
        edk::uint32 newPosition = (((position.y*this->getWidth()) + position.x) * this->getChannels());
        ret.r = this->vec[newPosition + 0u];
        ret.g = this->vec[newPosition + 1u];
        ret.b = this->vec[newPosition + 2u];
        ret.a = this->vec[newPosition + 3u];
    }
    return ret;
}
edk::color4ui8 edk::Image2D::getPixelRGBA(edk::uint32 x,edk::uint32 y){
    return this->getPixelRGBA(edk::vec2ui32(x,y));
}
//return the colors vector with all the palette codes
edk::uint8* edk::Image2D::getColors(){
    //test if open the image
    if(this->haveColors()){
        //then return the pointer
        return this->colors;edkEnd();
    }
    //else return false
    return NULL;
}

//convert the image pixels
bool edk::Image2D::calculateAlpha(edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB){
    if(this->haveImage() && this->getChannels()==4u){
        return edk::Image2D::rgbaToAlpha(this->getPixels(),this->getSize()
                                         ,compareR,compareG,compareB
                                         );
    }
    return false;
}
bool edk::Image2D::calculateAlpha(edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB,edk::uint8 min,edk::uint8 max){
    if(this->haveImage() && this->getChannels()==4u){
        return edk::Image2D::rgbaToAlpha(this->getPixels(),this->getSize()
                                         ,compareR,compareG,compareB
                                         ,min,max
                                         );
    }
    return false;
}
bool edk::Image2D::calculateAlpha(edk::color3ui8 compareRGB){
    if(this->haveImage() && this->getChannels()==4u){
        return edk::Image2D::rgbaToAlpha(this->getPixels(),this->getSize()
                                         ,compareRGB
                                         );
    }
    return false;
}
bool edk::Image2D::calculateAlpha(edk::color3ui8 compareRGB,edk::uint8 min,edk::uint8 max){
    if(this->haveImage() && this->getChannels()==4u){
        return edk::Image2D::rgbaToAlpha(this->getPixels(),this->getSize()
                                         ,compareRGB,min,max
                                         );
    }
    return false;
}

void edk::Image2D::deleteImage()
{
    //test if have an image
    if(this->haveImage()){
        //
        free(this->vec);edkEnd();
    }
    this->vec=NULL;edkEnd();
    //test if have a palette
    if(this->havePalette()){
        //
        free(this->palette);edkEnd();
    }
    this->palette=NULL;edkEnd();
    this->paletteSize=0u;
    this->bytesPerColors=0u;
    //clean the channels
    this->channelsValue=0u;
    //clean the size
    this->size = edk::size2ui32(0u,0u);edkEnd();

    //delete the imageNames
    this->deleteName();edkEnd();
    this->deleteFileName();edkEnd();
}

void edk::Image2D::deleteName()
{
    //
    if(this->haveName()){
        //
        free(this->imageName);edkEnd();
    }
    this->imageName=NULL;edkEnd();
}

//process the flip image in Y
bool edk::Image2D::flipImageY(){
    return edk::Image2D::flipY(this->vec,this->size.width,this->size.height,this->channelsValue);edkEnd();
    /*
    //test if have the image
    if(this->vec && this->size.width && this->size.height && this->channels){
        //get the line size
        edk::uint32 size = this->size.width * this->channels;edkEnd();
        //alloc a buffer to save the lines
        edk::uint8* line = (edk::uint8*)malloc(sizeof(edk::uint8) * (size));edkEnd();
        if(line){
            //set the pointers
            edk::uint8 *start = this->vec,*end=this->vec + (size * this->height()) - size;edkEnd();
            //go trow the lines copying
            while (start<end){
                //save the end
                memcpy(line,end,size);edkEnd();
                //copy the start to the end
                memcpy(end,start,size);edkEnd();
                //copy the line to the start
                memcpy(start,line,size);edkEnd();

                //increment start and decrment the end to meet in the middle
                start+=size;edkEnd();
                end-=size;edkEnd();
            }
            free(line);edkEnd();

            return true;
        }
    }
    */
}

//Compare with other image
edk::uint64 edk::Image2D::compareToUint64(edk::Image2D* compare){
    edk::float64 ret = 0xFFFFFFFFFFFFFFFF;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image2D::cmpToUint64(this->getPixels(),this->width(),this->height(),compare->getPixels(),this->channels());
        }
    }
    return ret;
}
edk::float64 edk::Image2D::compareToFloat64(edk::Image2D* compare){
    edk::float64 ret = -1.f;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image2D::cmpToFloat64(this->getPixels(),this->width(),this->height(),compare->getPixels(),this->channels());
        }
    }
    return ret;
}
edk::float64 edk::Image2D::compareLeftToFloat64(edk::Image2D* compare,edk::uint32 lenght){
    edk::float64 ret = -1.f;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image2D::cmpLeftToFloat64(this->getPixels(),this->width(),this->height(),lenght,compare->getPixels(),this->channels());
        }
    }
    return ret;
}
edk::float64 edk::Image2D::compareRightToFloat64(edk::Image2D* compare,edk::uint32 lenght){
    edk::float64 ret = -1.f;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image2D::cmpRightToFloat64(this->getPixels(),this->width(),this->height(),lenght,compare->getPixels(),this->channels());
        }
    }
    return ret;
}
edk::float64 edk::Image2D::compareUpToFloat64(edk::Image2D* compare,edk::uint32 lenght){
    edk::float64 ret = -1.f;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image2D::cmpUpToFloat64(this->getPixels(),this->width(),this->height(),lenght,compare->getPixels(),this->channels());
        }
    }
    return ret;
}
edk::float64 edk::Image2D::compareDownToFloat64(edk::Image2D* compare,edk::uint32 lenght){
    edk::float64 ret = -1.f;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image2D::cmpDownToFloat64(this->getPixels(),this->width(),this->height(),lenght,compare->getPixels(),this->channels());
        }
    }
    return ret;
}
//compare dockable with other image
edk::float64 edk::Image2D::compareDockableLeftToFloat64(edk::Image2D* compare,edk::uint32 lenght){
    edk::float64 ret = -1.f;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image2D::cmpDkbleLeftToFloat64(this->getPixels(),this->width(),this->height(),lenght,compare->getPixels(),this->channels());
        }
    }
    return ret;
}
edk::float64 edk::Image2D::compareDockableRightToFloat64(edk::Image2D* compare,edk::uint32 lenght){
    edk::float64 ret = -1.f;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image2D::cmpDkbleRightToFloat64(this->getPixels(),this->width(),this->height(),lenght,compare->getPixels(),this->channels());
        }
    }
    return ret;
}
edk::float64 edk::Image2D::compareDockableUpToFloat64(edk::Image2D* compare,edk::uint32 lenght){
    edk::float64 ret = -1.f;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image2D::cmpDkbleUpToFloat64(this->getPixels(),this->width(),this->height(),lenght,compare->getPixels(),this->channels());
        }
    }
    return ret;
}
edk::float64 edk::Image2D::compareDockableDownToFloat64(edk::Image2D* compare,edk::uint32 lenght){
    edk::float64 ret = -1.f;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image2D::cmpDkbleDownToFloat64(this->getPixels(),this->width(),this->height(),lenght,compare->getPixels(),this->channels());
        }
    }
    return ret;
}

//Convertions
//RGB to HSV
edk::color3f32 edk::Image2D::rgbTohsv(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::codecs::CodecImage::rgbTohsv(r,g,b);edkEnd();
}
edk::color3f32 edk::Image2D::rgbTohsv(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbTohsv(rgb.r,rgb.g,rgb.b);edkEnd();
}
edk::color3f32 edk::Image2D::rgbTohsv(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbTohsv(rgba.r,rgba.g,rgba.b);edkEnd();
}
edk::uint8 edk::Image2D::rgbToV(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::codecs::CodecImage::rgbToV(r,g,b);edkEnd();
}
edk::uint8 edk::Image2D::rgbToV(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbToV(rgb.r,rgb.g,rgb.b);edkEnd();
}
edk::uint8 edk::Image2D::rgbaToV(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbToV(rgba.r,rgba.g,rgba.b);edkEnd();
}
//RGB to A
edk::uint8 edk::Image2D::rgbToA(edk::uint8 r,edk::uint8 g,edk::uint8 b
                                ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                                ){
    return edk::codecs::CodecImage::rgbToA(r,g,b,compareR,compareG,compareB);
}
edk::uint8 edk::Image2D::rgbToA(edk::uint8 r,edk::uint8 g,edk::uint8 b
                                ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                                ,edk::uint8 min,edk::uint8 max
                                ){
    return edk::codecs::CodecImage::rgbToA(r,g,b,compareR,compareG,compareB,min,max);
}
edk::uint8 edk::Image2D::rgbToA(edk::color3ui8 rgb,edk::color3ui8 compareRGB){
    return edk::codecs::CodecImage::rgbToA(rgb,compareRGB);
}
edk::uint8 edk::Image2D::rgbToA(edk::color3ui8 rgb,edk::color3ui8 compareRGB,edk::uint8 min,edk::uint8 max){
    return edk::codecs::CodecImage::rgbToA(rgb,compareRGB,min,max);
}
//RGBA to A
edk::uint8 edk::Image2D::rgbaToA(edk::color4ui8 rgba,edk::color3ui8 compareRGB){
    return edk::codecs::CodecImage::rgbaToA(rgba,compareRGB);
}
edk::uint8 edk::Image2D::rgbaToA(edk::color4ui8 rgba,edk::color3ui8 compareRGB,edk::uint8 min,edk::uint8 max){
    return edk::codecs::CodecImage::rgbaToA(rgba,compareRGB,min,max);
}
//vector
bool edk::Image2D::rgbToV(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbToV(vector,size,dest);edkEnd();
}
edk::uint8* edk::Image2D::rgbToV(edk::uint8* vector,edk::size2ui32 size){
    return edk::codecs::CodecImage::rgbToV(vector,size);edkEnd();
}
bool edk::Image2D::rgbToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbToV(vector,edk::size2ui32(width,height),dest);edkEnd();
}
edk::uint8* edk::Image2D::rgbToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbToV(vector,edk::size2ui32(width,height));edkEnd();
}
bool edk::Image2D::rgbaToV(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbaToV(vector,size,dest);edkEnd();
}
edk::uint8* edk::Image2D::rgbaToV(edk::uint8* vector,edk::size2ui32 size){
    return edk::codecs::CodecImage::rgbaToV(vector,size);edkEnd();
}
bool edk::Image2D::rgbaToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbaToV(vector,edk::size2ui32(width,height),dest);edkEnd();
}
edk::uint8* edk::Image2D::rgbaToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbaToV(vector,edk::size2ui32(width,height));edkEnd();
}
//RGB to Alpha
bool edk::Image2D::rgbaToAlpha(edk::uint8* vector,edk::size2ui32 size
                               ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                               ){
    return edk::codecs::CodecImage::rgbaToAlpha(vector,size,compareR,compareG,compareB);
}
bool edk::Image2D::rgbaToAlpha(edk::uint8* vector,edk::size2ui32 size
                               ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                               ,edk::uint8 min,edk::uint8 max
                               ){
    return edk::codecs::CodecImage::rgbaToAlpha(vector,size,compareR,compareG,compareB,min,max);
}
bool edk::Image2D::rgbaToAlpha(edk::uint8* vector,edk::size2ui32 size
                               ,edk::color3ui8 compareRGB
                               ){
    return edk::codecs::CodecImage::rgbaToAlpha(vector,size,compareRGB);
}
bool edk::Image2D::rgbaToAlpha(edk::uint8* vector,edk::size2ui32 size
                               ,edk::color3ui8 compareRGB
                               ,edk::uint8 min,edk::uint8 max
                               ){
    return edk::codecs::CodecImage::rgbaToAlpha(vector,size,compareRGB,min,max);
}
bool edk::Image2D::rgbaToAlpha(edk::uint8* vector,edk::uint32 width,edk::uint32 height
                               ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                               ){
    return edk::codecs::CodecImage::rgbaToAlpha(vector,width,height,compareR,compareG,compareB);
}
bool edk::Image2D::rgbaToAlpha(edk::uint8* vector,edk::uint32 width,edk::uint32 height
                               ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                               ,edk::uint8 min,edk::uint8 max
                               ){
    return edk::codecs::CodecImage::rgbaToAlpha(vector,width,height,compareR,compareG,compareB,min,max);
}
bool edk::Image2D::rgbaToAlpha(edk::uint8* vector,edk::uint32 width,edk::uint32 height
                               ,edk::color3ui8 compareRGB
                               ){
    return edk::codecs::CodecImage::rgbaToAlpha(vector,width,height,compareRGB);
}
bool edk::Image2D::rgbaToAlpha(edk::uint8* vector,edk::uint32 width,edk::uint32 height
                               ,edk::color3ui8 compareRGB
                               ,edk::uint8 min,edk::uint8 max
                               ){
    return edk::codecs::CodecImage::rgbaToAlpha(vector,width,height,compareRGB,min,max);
}
//HSV to RGB
edk::color3ui8 edk::Image2D::hsvTorgb(edk::float32 h,edk::float32 s,edk::float32 v){
    return edk::codecs::CodecImage::hsvTorgb(h,s,v);edkEnd();
}
edk::color3ui8 edk::Image2D::hsvTorgb(edk::color3f32 hsv){
    return edk::codecs::CodecImage::hsvTorgb(hsv.r,hsv.g,hsv.b);edkEnd();
}
//RGB to HSL
edk::color3f32 edk::Image2D::rgbTohsl(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::codecs::CodecImage::rgbTohsl(r,g,b);edkEnd();
}
edk::color3f32 edk::Image2D::rgbTohsl(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbTohsl(rgb.r,rgb.g,rgb.b);edkEnd();
}
edk::color3f32 edk::Image2D::rgbaTohsl(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbTohsl(rgba.r,rgba.g,rgba.b);edkEnd();
}
edk::float32 edk::Image2D::rgbToL(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::codecs::CodecImage::rgbToL(r,g,b);edkEnd();
}
edk::float32 edk::Image2D::rgbToL(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbToL(rgb.r,rgb.g,rgb.b);edkEnd();
}
edk::float32 edk::Image2D::rgbaToL(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbToL(rgba.r,rgba.g,rgba.b);edkEnd();
}
edk::uint8 edk::Image2D::rgbToLui8(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::codecs::CodecImage::rgbToLui8(r,g,b);edkEnd();
}
edk::uint8 edk::Image2D::rgbToLui8(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbToLui8(rgb.r,rgb.g,rgb.b);edkEnd();
}
edk::uint8 edk::Image2D::rgbaToLui8(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbToLui8(rgba.r,rgba.g,rgba.b);edkEnd();
}
//vector
bool edk::Image2D::rgbToLui8(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbToLui8(vector,size,dest);edkEnd();
}
edk::uint8* edk::Image2D::rgbToLui8(edk::uint8* vector,edk::size2ui32 size){
    return edk::codecs::CodecImage::rgbToLui8(vector,size);edkEnd();
}
bool edk::Image2D::rgbToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbToLui8(vector,edk::size2ui32(width,height),dest);edkEnd();
}
edk::uint8* edk::Image2D::rgbToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbToLui8(vector,edk::size2ui32(width,height));edkEnd();
}
bool edk::Image2D::rgbaToLui8(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbaToLui8(vector,size,dest);edkEnd();
}
edk::uint8* edk::Image2D::rgbaToLui8(edk::uint8* vector,edk::size2ui32 size){
    return edk::codecs::CodecImage::rgbaToLui8(vector,size);edkEnd();
}
bool edk::Image2D::rgbaToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbaToLui8(vector,edk::size2ui32(width,height),dest);edkEnd();
}
edk::uint8* edk::Image2D::rgbaToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbaToLui8(vector,edk::size2ui32(width,height));edkEnd();
}
edk::color3ui8 edk::Image2D::hslTorgb(edk::float32 h,edk::float32 s,edk::float32 l){
    return edk::codecs::CodecImage::hslTorgb(h,s,l);edkEnd();
}
edk::color3ui8 edk::Image2D::hslTorgb(edk::color3f32 hsl){
    return edk::codecs::CodecImage::hslTorgb(hsl.r,hsl.g,hsl.b);edkEnd();
}
//RGB to RGBA
edk::color4ui8 edk::Image2D::rgbTorgba(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::color4ui8(r,g,b,(edk::uint8)255u);edkEnd();
}
edk::color4ui8 edk::Image2D::rgbTorgba(edk::color3ui8 rgb){
    return edk::Image2D::rgbTorgba(rgb.r,rgb.g,rgb.b);edkEnd();
}
edk::color4f32 edk::Image2D::rgbTorgba(edk::float32 r,edk::float32 g,edk::float32 b){
    return edk::color4f32(r,g,b,1.f);edkEnd();
}
edk::color4f32 edk::Image2D::rgbTorgba(edk::color3f32 rgb){
    return edk::Image2D::rgbTorgba(rgb.r,rgb.g,rgb.b);edkEnd();
}
//vector
bool edk::Image2D::rgbTorgba(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    if(vector && dest && size.width && size.height){
        for(edk::uint32 y=0u;y<size.height;y++){
            for(edk::uint32 x=0u;x<size.width;x++){
                //copy the channels and add the fourth as 255u
                dest[0u] = vector[0u];edkEnd();
                dest[1u] = vector[1u];edkEnd();
                dest[2u] = vector[2u];edkEnd();
                dest[3u] = 255u;edkEnd();
                //increment the vectors
                vector+=3u;edkEnd();
                dest+=4u;edkEnd();
            }
        }
        return true;
    }
    return false;
}
edk::uint8* edk::Image2D::rgbTorgba(edk::uint8* vector,edk::size2ui32 size){
    if(size.width && size.height){
        edk::uint8* ret = (edk::uint8*)malloc(sizeof(edk::uint8) * (size.width*size.height*4u));edkEnd();
        if(ret){
            if(edk::Image2D::rgbTorgba(vector,size,ret)){
                return ret;
            }
            free(ret);edkEnd();
        }
    }
    return NULL;
}
bool edk::Image2D::rgbTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::Image2D::rgbTorgba(vector,edk::size2ui32(width,height),dest);edkEnd();
}
edk::uint8* edk::Image2D::rgbTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::Image2D::rgbTorgba(vector,edk::size2ui32(width,height));edkEnd();
}
//LA to RGBA
edk::color4ui8 edk::Image2D::laTorgba(edk::uint8 l,edk::uint8 a){
    return edk::color4ui8(l,l,l,a);edkEnd();
}
edk::color4f32 edk::Image2D::laTorgba(edk::float32 l,edk::float32 a){
    return edk::color4f32(l,l,l,a);edkEnd();
}
//vector
bool edk::Image2D::laTorgba(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    if(vector && dest && size.width && size.height){
        for(edk::uint32 y=0u;y<size.height;y++){
            for(edk::uint32 x=0u;x<size.width;x++){
                //copy the channels
                dest[0u] = vector[0u];edkEnd();
                dest[1u] = vector[0u];edkEnd();
                dest[2u] = vector[0u];edkEnd();
                dest[3u] = vector[1u];edkEnd();
                //increment the vectors
                vector+=2u;edkEnd();
                dest+=4u;edkEnd();
            }
        }
        return true;
    }
    return false;
}
edk::uint8* edk::Image2D::laTorgba(edk::uint8* vector,edk::size2ui32 size){
    if(size.width && size.height){
        edk::uint8* ret = (edk::uint8*)malloc(sizeof(edk::uint8) * (size.width*size.height*4u));edkEnd();
        if(ret){
            if(edk::Image2D::laTorgba(vector,size,ret)){
                return ret;
            }
            free(ret);edkEnd();
        }
    }
    return NULL;
}
bool edk::Image2D::laTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::Image2D::laTorgba(vector,edk::size2ui32(width,height),dest);edkEnd();
}
edk::uint8* edk::Image2D::laTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::Image2D::laTorgba(vector,edk::size2ui32(width,height));edkEnd();
}
//L to RGBA
edk::color4ui8 edk::Image2D::lTorgba(edk::uint8 l){
    return edk::color4ui8(l,l,l,(edk::uint8)255u);edkEnd();
}
edk::color4f32 edk::Image2D::lTorgba(edk::float32 l){
    return edk::color4f32(l,l,l,1.f);edkEnd();
}
bool edk::Image2D::lTorgba(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    if(vector && dest && size.width && size.height){
        for(edk::uint32 y=0u;y<size.height;y++){
            for(edk::uint32 x=0u;x<size.width;x++){
                //copy the channels
                dest[0u] = vector[0u];edkEnd();
                dest[1u] = vector[0u];edkEnd();
                dest[2u] = vector[0u];edkEnd();
                dest[3u] = 255u;edkEnd();
                //increment the vectors
                vector+=2u;edkEnd();
                dest+=4u;edkEnd();
            }
        }
        return true;
    }
    return false;
}
edk::uint8* edk::Image2D::lTorgba(edk::uint8* vector,edk::size2ui32 size){
    if(size.width && size.height){
        edk::uint8* ret = (edk::uint8*)malloc(sizeof(edk::uint8) * (size.width*size.height*4u));edkEnd();
        if(ret){
            if(edk::Image2D::lTorgba(vector,size,ret)){
                return ret;
            }
            free(ret);edkEnd();
        }
    }
    return NULL;
}
bool edk::Image2D::lTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::Image2D::lTorgba(vector,edk::size2ui32(width,height),dest);edkEnd();
}
edk::uint8* edk::Image2D::lTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::Image2D::lTorgba(vector,edk::size2ui32(width,height));edkEnd();
}
//compare
edk::uint64 edk::Image2D::cmpToUint64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* compare,edk::uint8 channels){
    edk::uint64 ret = 0xFFFFFFFFFFFFFFFF;
    if(vector && compare && width && height && channels){
        edk::uint32 size = width * height * channels;
        edk::int32 cmp=0;
        ret=0u;
        for(edk::uint32 i=0u;i<size;i++){
            cmp = (edk::int16)*compare - (edk::int16)*vector;
            if(cmp<0){
                cmp*=-1;
            }
            ret+=cmp;
        }
    }
    return ret;
}
edk::float64 edk::Image2D::cmpToFloat64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* compare,edk::uint8 channels){
    edk::float64 ret = -1.f;
    if(vector && compare && width && height && channels){
        edk::int32 cmp;
        edk::uint64 cmpLine=0u,cmpLineColor;
        edk::float64 div = (edk::float64)width;
        ret=0.;
        switch(channels){
        case 1u:
            for(edk::uint32 y=0u;y<height;y++){
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmpLine+=cmpLineColor/1;
                    //increment
                    vector+=1u;
                    compare+=1u;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 2u:
            for(edk::uint32 y=0u;y<height;y++){
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/2;
                    //increment
                    vector+=2u;
                    compare+=2u;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 3u:
            for(edk::uint32 y=0u;y<height;y++){
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[2u] - (edk::int16)vector[2u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/3;
                    //increment
                    vector+=3u;
                    compare+=3u;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 4u:
            for(edk::uint32 y=0u;y<height;y++){
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[2u] - (edk::int16)vector[2u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[3u] - (edk::int16)vector[3u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/4;
                    //increment
                    vector+=4u;
                    compare+=4u;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        }
        ret/=(edk::float64)height;
    }
    return ret;
}
edk::float64 edk::Image2D::cmpLeftToFloat64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 lenght,edk::uint8* compare,edk::uint8 channels){
    edk::float64 ret = -1.f;
    if(vector && compare && width && height && channels && lenght && lenght<=width){
        edk::int32 cmp;
        edk::uint64 cmpLine=0u,cmpLineColor;
        edk::float64 div = (edk::float64)lenght;
        edk::uint32 increment = width - lenght;
        ret=0.;
        switch(channels){
        case 1u:
            for(edk::uint32 y=0u;y<height;y++){
                for(edk::uint32 x=0u;x<lenght;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmpLine+=cmpLineColor/1;
                    //increment
                    compare+=1u;
                    vector+=1u;
                }
                compare+=1u* increment;
                vector+=1u* increment;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 2u:
            for(edk::uint32 y=0u;y<height;y++){
                for(edk::uint32 x=0u;x<lenght;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/2;
                    //increment
                    compare+=2u;
                    vector+=2u;
                }
                compare+=2u* increment;
                vector+=2u* increment;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 3u:
            for(edk::uint32 y=0u;y<height;y++){
                for(edk::uint32 x=0u;x<lenght;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[2u] - (edk::int16)vector[2u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/3;
                    //increment
                    compare+=3u;
                    vector+=3u;
                }
                compare+=3u* increment;
                vector+=3u* increment;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 4u:
            for(edk::uint32 y=0u;y<height;y++){
                for(edk::uint32 x=0u;x<lenght;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[2u] - (edk::int16)vector[2u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[3u] - (edk::int16)vector[3u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/4;
                    //increment
                    compare+=4u;
                    vector+=4u;
                }
                compare+=4u* increment;
                vector+=4u* increment;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        }
        ret/=(edk::float64)height;
    }
    return ret;
}
edk::float64 edk::Image2D::cmpRightToFloat64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 lenght,edk::uint8* compare,edk::uint8 channels){
    edk::float64 ret = -1.f;
    if(vector && compare && width && height && channels && lenght && lenght<=width){
        edk::int32 cmp;
        edk::uint64 cmpLine=0u,cmpLineColor;
        edk::float64 div = (edk::float64)lenght;
        edk::uint32 increment = width - lenght;
        ret=0.;
        switch(channels){
        case 1u:
            for(edk::uint32 y=0u;y<height;y++){
                compare+=1u* increment;
                vector+=1u* increment;
                for(edk::uint32 x=0u;x<lenght;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmpLine+=cmpLineColor/1;
                    //increment
                    compare+=1u;
                    vector+=1u;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 2u:
            for(edk::uint32 y=0u;y<height;y++){
                compare+=2u* increment;
                vector+=2u* increment;
                for(edk::uint32 x=0u;x<lenght;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/2;
                    //increment
                    compare+=2u;
                    vector+=2u;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 3u:
            for(edk::uint32 y=0u;y<height;y++){
                compare+=3u* increment;
                vector+=3u* increment;
                for(edk::uint32 x=0u;x<lenght;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[2u] - (edk::int16)vector[2u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/3;
                    //increment
                    compare+=3u;
                    vector+=3u;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 4u:
            for(edk::uint32 y=0u;y<height;y++){
                compare+=4u* increment;
                vector+=4u* increment;
                for(edk::uint32 x=0u;x<lenght;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[2u] - (edk::int16)vector[2u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[3u] - (edk::int16)vector[3u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/4;
                    //increment
                    compare+=4u;
                    vector+=4u;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        }
        ret/=(edk::float64)height;
    }
    return ret;
}
edk::float64 edk::Image2D::cmpUpToFloat64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 lenght,edk::uint8* compare,edk::uint8 channels){
    edk::float64 ret = -1.f;
    if(vector && compare && width && height && channels && lenght && lenght<=height){
        edk::int32 cmp;
        edk::uint64 cmpLine=0u,cmpLineColor;
        edk::float64 div = (edk::float64)width;
        ret=0.;
        switch(channels){
        case 1u:
            for(edk::uint32 y=0u;y<height;y++){
                vector-=1u * width;
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmpLine+=cmpLineColor/1;
                    //increment
                    compare+=1u;
                    vector+=1u;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 2u:
            for(edk::uint32 y=0u;y<height;y++){
                vector-=2u * width;
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/2;
                    //increment
                    compare+=2u;
                    vector+=2u;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 3u:
            for(edk::uint32 y=0u;y<height;y++){
                vector-=3u * width;
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[2u] - (edk::int16)vector[2u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/3;
                    //increment
                    compare+=3u;
                    vector+=3u;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 4u:
            for(edk::uint32 y=0u;y<height;y++){
                vector-=4u * width;
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[2u] - (edk::int16)vector[2u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[3u] - (edk::int16)vector[3u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/4;
                    //increment
                    compare+=4u;
                    vector+=4u;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        }
        ret/=(edk::float64)height;
    }
    return ret;
}
edk::float64 edk::Image2D::cmpDownToFloat64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 lenght,edk::uint8* compare,edk::uint8 channels){
    edk::float64 ret = -1.f;
    if(vector && compare && width && height && channels && lenght && lenght<=height){
        edk::int32 cmp;
        edk::uint64 cmpLine=0u,cmpLineColor;
        edk::float64 div = (edk::float64)width;
        edk::uint32 increment = height - lenght;
        ret=0.;
        switch(channels){
        case 1u:
            compare+=1u * increment*width;
            vector+=1u * increment*width;
            for(edk::uint32 y=0u;y<height;y++){
                vector-=1u * width;
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmpLine+=cmpLineColor/1;
                    //increment
                    compare+=1u;
                    vector+=1u;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 2u:
            compare+=1u * increment*width;
            vector+=1u * increment*width;
            for(edk::uint32 y=0u;y<height;y++){
                vector-=2u * width;
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/2;
                    //increment
                    compare+=2u;
                    vector+=2u;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 3u:
            compare+=1u * increment*width;
            vector+=1u * increment*width;
            for(edk::uint32 y=0u;y<height;y++){
                vector-=3u * width;
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[2u] - (edk::int16)vector[2u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/3;
                    //increment
                    compare+=3u;
                    vector+=3u;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 4u:
            compare+=1u * increment*width;
            vector+=1u * increment*width;
            for(edk::uint32 y=0u;y<height;y++){
                vector-=4u * width;
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[2u] - (edk::int16)vector[2u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[3u] - (edk::int16)vector[3u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/4;
                    //increment
                    compare+=4u;
                    vector+=4u;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        }
        ret/=(edk::float64)height;
    }
    return ret;
}
//compare dockable
edk::float64 edk::Image2D::cmpDkbleLeftToFloat64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 lenght,edk::uint8* compare,edk::uint8 channels){
    edk::float64 ret = -1.f;
    if(vector && compare && width && height && channels && lenght && lenght<=width){
        edk::int32 cmp;
        edk::uint64 cmpLine=0u,cmpLineColor;
        edk::float64 div = (edk::float64)lenght;
        edk::uint32 increment = width - lenght;
        ret=0.;
        switch(channels){
        case 1u:
            for(edk::uint32 y=0u;y<height;y++){
                //increment until the compare line in Y
                compare+=1u * increment;
                vector+=1u* lenght;
                for(edk::uint32 x=0u;x<lenght;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmpLine+=cmpLineColor/1;
                    //increment
                    compare+=1u;
                    vector-=1u;
                }
                vector+=1u* width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 2u:
            for(edk::uint32 y=0u;y<height;y++){
                //increment until the compare line in Y
                compare+=2u * increment;
                vector+=2u* lenght;
                for(edk::uint32 x=0u;x<lenght;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/2;
                    //increment
                    compare+=2u;
                    vector-=2u;
                }
                vector+=2u* width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 3u:
            for(edk::uint32 y=0u;y<height;y++){
                //increment until the compare line in Y
                compare+=3u * increment;
                vector+=3u* lenght;
                for(edk::uint32 x=0u;x<lenght;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[2u] - (edk::int16)vector[2u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/3;
                    //increment
                    compare+=3u;
                    vector-=3u;
                }
                vector+=3u* width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 4u:
            for(edk::uint32 y=0u;y<height;y++){
                //increment until the compare line in Y
                compare+=4u * increment;
                vector+=4u* lenght;
                for(edk::uint32 x=0u;x<lenght;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[2u] - (edk::int16)vector[2u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[3u] - (edk::int16)vector[3u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/4;
                    //increment
                    compare+=4u;
                    vector-=4u;
                }
                vector+=4u* width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        }
        ret/=(edk::float64)height;
    }
    return ret;
}
edk::float64 edk::Image2D::cmpDkbleRightToFloat64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 lenght,edk::uint8* compare,edk::uint8 channels){
    edk::float64 ret = -1.f;
    if(vector && compare && width && height && channels && lenght && lenght<=width){
        edk::int32 cmp;
        edk::uint64 cmpLine=0u,cmpLineColor;
        edk::float64 div = (edk::float64)lenght;
        edk::uint32 increment = width - lenght;
        ret=0.;
        switch(channels){
        case 1u:
            for(edk::uint32 y=0u;y<height;y++){
                //increment until the compare line in Y
                vector+=1u * increment;
                compare+=1u* lenght;
                for(edk::uint32 x=0u;x<lenght;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmpLine+=cmpLineColor/1;
                    //increment
                    vector+=1u;
                    compare-=1u;
                }
                compare+=1u* width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 2u:
            for(edk::uint32 y=0u;y<height;y++){
                //increment until the compare line in Y
                vector+=2u * increment;
                compare+=2u* lenght;
                for(edk::uint32 x=0u;x<lenght;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/2;
                    //increment
                    vector+=2u;
                    compare-=2u;
                }
                compare+=2u* width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 3u:
            for(edk::uint32 y=0u;y<height;y++){
                //increment until the compare line in Y
                vector+=3u * increment;
                compare+=3u* lenght;
                for(edk::uint32 x=0u;x<lenght;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[2u] - (edk::int16)vector[2u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/3;
                    //increment
                    vector+=3u;
                    compare-=3u;
                }
                compare+=3u* width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 4u:
            for(edk::uint32 y=0u;y<height;y++){
                //increment until the compare line in Y
                vector+=4u * increment;
                compare+=4u* lenght;
                for(edk::uint32 x=0u;x<lenght;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[2u] - (edk::int16)vector[2u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[3u] - (edk::int16)vector[3u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/4;
                    //increment
                    vector+=4u;
                    compare-=4u;
                }
                compare+=4u* width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        }
        ret/=(edk::float64)height;
    }
    return ret;
}
edk::float64 edk::Image2D::cmpDkbleUpToFloat64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 lenght,edk::uint8* compare,edk::uint8 channels){
    edk::float64 ret = -1.f;
    if(vector && compare && width && height && channels && lenght && lenght<=height){
        edk::int32 cmp;
        edk::uint64 cmpLine=0u,cmpLineColor;
        edk::float64 div = (edk::float64)width;
        edk::uint32 increment = height - lenght;
        ret=0.;
        switch(channels){
        case 1u:
            compare+=1u * increment*width;
            vector+=1u * lenght*width;
            for(edk::uint32 y=0u;y<height;y++){
                vector-=1u * width;
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmpLine+=cmpLineColor/1;
                    //increment
                    compare+=1u;
                    vector+=1u;
                }
                vector-=1u * width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 2u:
            compare+=2u * increment*width;
            vector+=2u * lenght*width;
            for(edk::uint32 y=0u;y<height;y++){
                vector-=2u * width;
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/2;
                    //increment
                    compare+=2u;
                    vector+=2u;
                }
                vector-=2u * width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 3u:
            compare+=3u * increment*width;
            vector+=3u * lenght*width;
            for(edk::uint32 y=0u;y<height;y++){
                vector-=3u * width;
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[2u] - (edk::int16)vector[2u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/3;
                    //increment
                    compare+=3u;
                    vector+=3u;
                }
                vector-=3u * width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 4u:
            compare+=4u * increment*width;
            vector+=4u * lenght*width;
            for(edk::uint32 y=0u;y<height;y++){
                vector-=4u * width;
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[2u] - (edk::int16)vector[2u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[3u] - (edk::int16)vector[3u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/4;
                    //increment
                    compare+=4u;
                    vector+=4u;
                }
                vector-=4u * width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        }
        ret/=(edk::float64)height;
    }
    return ret;
}
edk::float64 edk::Image2D::cmpDkbleDownToFloat64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 lenght,edk::uint8* compare,edk::uint8 channels){
    edk::float64 ret = -1.f;
    if(vector && compare && width && height && channels && lenght && lenght<=height){
        edk::int32 cmp;
        edk::uint64 cmpLine=0u,cmpLineColor;
        edk::float64 div = (edk::float64)width;
        edk::uint32 increment = height - lenght;
        ret=0.;
        switch(channels){
        case 1u:
            vector+=1u * increment*width;
            compare+=1u * lenght*width;
            for(edk::uint32 y=0u;y<height;y++){
                compare-=1u * width;
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmpLine+=cmpLineColor/1;
                    //increment
                    vector+=1u;
                    compare+=1u;
                }
                compare-=1u * width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 2u:
            vector+=2u * increment*width;
            compare+=2u * lenght*width;
            for(edk::uint32 y=0u;y<height;y++){
                compare-=2u * width;
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/2;
                    //increment
                    vector+=2u;
                    compare+=2u;
                }
                compare-=2u * width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 3u:
            vector+=3u * increment*width;
            compare+=3u * lenght*width;
            for(edk::uint32 y=0u;y<height;y++){
                compare-=3u * width;
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[2u] - (edk::int16)vector[2u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/3;
                    //increment
                    vector+=3u;
                    compare+=3u;
                }
                compare-=3u * width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 4u:
            vector+=4u * increment*width;
            compare+=4u * lenght*width;
            for(edk::uint32 y=0u;y<height;y++){
                compare-=4u * width;
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[2u] - (edk::int16)vector[2u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmp = (edk::int16)compare[3u] - (edk::int16)vector[3u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/4;
                    //increment
                    vector+=4u;
                    compare+=4u;
                }
                compare-=4u * width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        }
        ret/=(edk::float64)height;
    }
    return ret;
}

//flip pixels
bool edk::Image2D::flipY(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 channels){
    if(vector && width && height && channels){
        //get the line size
        edk::uint32 size = width * channels;edkEnd();
        //alloc a buffer to save the lines
        edk::uint8* line = (edk::uint8*)malloc(sizeof(edk::uint8) * (size));edkEnd();
        if(line){
            //set the pointers
            edk::uint8 *start = vector,*end=vector + (size * height) - size;edkEnd();
            //go trow the lines copying
            while (start<end){
                //save the end
                memcpy(line,end,size);edkEnd();
                //copy the start to the end
                memcpy(end,start,size);edkEnd();
                //copy the line to the start
                memcpy(start,line,size);edkEnd();

                //increment start and decrment the end to meet in the middle
                start+=size;edkEnd();
                end-=size;edkEnd();
            }
            free(line);edkEnd();

            return true;
        }
    }
    return false;
}

bool edk::Image2D::imageClone(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 channels,
                              edk::uint8* dest,edk::uint32 dWidth,edk::uint32 dHeight,edk::uint32 dChannels,
                              edk::uint32 positionX,edk::uint32 positionY
                              ){
    //test the vectors
    if(vector && width && height && channels && dest && dWidth && dHeight && dChannels){
        //test if can position the image inside the dest
        if(positionX <= dWidth - width && positionY <= dHeight - height){
            //then copy the image
            dest+=positionY*dWidth * dChannels;edkEnd();
            for(edk::uint32 y = 0u;y<height;y++){
                dest+=positionX * dChannels;edkEnd();
                //copy the channels
                if(channels==1u){
                    if(dChannels==1u){
                        //1 1
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];edkEnd();
                            //increment the vectors
                            dest+=dChannels;edkEnd();
                            vector+=channels;edkEnd();
                        }
                    }
                    else if(dChannels==2u){
                        //1 2
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];edkEnd();
                            dest[1u] = 255u;edkEnd();
                            //increment the vectors
                            dest+=dChannels;edkEnd();
                            vector+=channels;edkEnd();
                        }
                    }
                    else if(dChannels==3u){
                        //1 3
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];edkEnd();
                            dest[2u] = vector[0u];edkEnd();
                            dest[3u] = vector[0u];edkEnd();
                            //increment the vectors
                            dest+=dChannels;edkEnd();
                            vector+=channels;edkEnd();
                        }
                    }
                    else if(dChannels==4u){
                        //1 4 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];edkEnd();
                            dest[2u] = vector[0u];edkEnd();
                            dest[3u] = vector[0u];edkEnd();
                            dest[4u] = 255u;edkEnd();
                            //increment the vectors
                            dest+=dChannels;edkEnd();
                            vector+=channels;edkEnd();
                        }
                    }
                }
                else if(channels==2u){
                    if(dChannels==1u){
                        //2 1 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];edkEnd();
                            //increment the vectors
                            dest+=dChannels;edkEnd();
                            vector+=channels;edkEnd();
                        }
                    }
                    else if(dChannels==2u){
                        //2 2 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];edkEnd();
                            dest[1u] = vector[1u];edkEnd();
                            //increment the vectors
                            dest+=dChannels;edkEnd();
                            vector+=channels;edkEnd();
                        }
                    }
                    else if(dChannels==3u){
                        //2 3 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];edkEnd();
                            dest[1u] = vector[0u];edkEnd();
                            dest[2u] = vector[0u];edkEnd();
                            //increment the vectors
                            dest+=dChannels;edkEnd();
                            vector+=channels;edkEnd();
                        }
                    }
                    else if(dChannels==4u){
                        //2 4 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];edkEnd();
                            dest[1u] = vector[0u];edkEnd();
                            dest[2u] = vector[0u];edkEnd();
                            dest[4u] = vector[1u];edkEnd();
                            //increment the vectors
                            dest+=dChannels;edkEnd();
                            vector+=channels;edkEnd();
                        }
                    }
                }
                else if(channels==3u){
                    if(dChannels==1u){
                        //3 1
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = edk::Image2D::rgbToL(vector[0u],vector[1u],vector[2u]);edkEnd();
                            //increment the vectors
                            dest+=dChannels;edkEnd();
                            vector+=channels;edkEnd();
                        }
                    }
                    else if(dChannels==2u){
                        //3 2 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = edk::Image2D::rgbToL(vector[0u],vector[1u],vector[2u]);edkEnd();
                            dest[1u] = 255;edkEnd();
                            //increment the vectors
                            dest+=dChannels;edkEnd();
                            vector+=channels;edkEnd();
                        }
                    }
                    else if(dChannels==3u){
                        //3 3
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];edkEnd();
                            dest[1u] = vector[1u];edkEnd();
                            dest[2u] = vector[2u];edkEnd();
                            //increment the vectors
                            dest+=dChannels;edkEnd();
                            vector+=channels;edkEnd();
                        }
                    }
                    else if(dChannels==4u){
                        //3 4 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];edkEnd();
                            dest[1u] = vector[1u];edkEnd();
                            dest[2u] = vector[2u];edkEnd();
                            dest[1u] = 255;edkEnd();
                            //increment the vectors
                            dest+=dChannels;edkEnd();
                            vector+=channels;edkEnd();
                        }
                    }
                }
                else if(channels==4u){
                    if(dChannels==1u){
                        //4 1
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = edk::Image2D::rgbToL(vector[0u],vector[1u],vector[2u]);edkEnd();
                            //increment the vectors
                            dest+=dChannels;edkEnd();
                            vector+=channels;edkEnd();
                        }
                    }
                    else if(dChannels==2u){
                        //4 2 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = edk::Image2D::rgbToL(vector[0u],vector[1u],vector[2u]);edkEnd();
                            dest[1u] = vector[1u];edkEnd();
                            //increment the vectors
                            dest+=dChannels;edkEnd();
                            vector+=channels;edkEnd();
                        }
                    }
                    else if(dChannels==3u){
                        //4 3
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = edk::Image2D::rgbToL(vector[0u],vector[1u],vector[2u]);edkEnd();
                            //increment the vectors
                            dest+=dChannels;edkEnd();
                            vector+=channels;edkEnd();
                        }
                    }
                    else if(dChannels==4u){
                        //4 4 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];edkEnd();
                            dest[1u] = vector[1u];edkEnd();
                            dest[2u] = vector[2u];edkEnd();
                            dest[3u] = vector[3u];edkEnd();
                            //increment the vectors
                            dest+=dChannels;edkEnd();
                            vector+=channels;edkEnd();
                        }
                    }
                }
                dest+=(dWidth - width - positionX) * dChannels;edkEnd();
            }
            //then return true
            return true;
        }
    }
    return false;
}

bool edk::Image2D::cloneFrom(edk::Image2D* image){
    if(image){
        //test if the image exist
        if(image->vec && image->channelsValue && image->size.width && image->size.height && image->imageName){
            //test if the characteristics are equal
            if(!(this->vec && image->channelsValue == this->channelsValue && image->size == this->size)){
                //else delete the last image
                this->deleteImage();edkEnd();
                //create a new vec with the vecSize
                if(!this->newImage(image->name(),image->size.width,image->size.height,image->channelsValue)){
                    //return false because it can't create a new image
                    return false;
                }
            }
            else{
                //set the image name
                if(!this->setName(image->name())){
                    //if it cant set. Delete the last image and return false
                    this->deleteImage();edkEnd();
                    return false;
                }
            }
            //test if create the image
            if(this->vec && this->size.width && this->size.height && this->channelsValue){
                //clean the image setting all zeros
                memcpy(this->vec,image->vec,this->size.width * this->size.height * this->channelsValue);edkEnd();
                return true;
            }
        }
    }
    //if don't have an image delete the last image
    this->deleteImage();edkEnd();
    return false;
}
bool edk::Image2D::newFrom(edk::Image2D* image){
    if(image){
        //test if the image exist
        if(image->vec && image->channelsValue && image->size.width && image->size.height && image->imageName){
            //test if the characteristics are equal
            if(!(this->vec && image->channelsValue == this->channelsValue && image->size == this->size)){
                //else delete the last image
                this->deleteImage();edkEnd();
                //create a new vec with the vecSize
                if(!this->newImage(image->name(),image->size.width,image->size.height,image->channelsValue)){
                    //return false because it can't create a new image
                    return false;
                }
            }
            else{
                //set the image name
                if(!this->setName(image->name())){
                    //if it cant set. Delete the last image and return false
                    this->deleteImage();edkEnd();
                    return false;
                }
            }
            //test if create the image
            if(this->vec && this->size.width && this->size.height && this->channelsValue){
                //clean the image setting all zeros
                memset(this->vec,0u,this->size.width * this->size.height * this->channelsValue);edkEnd();
                return true;
            }
        }
    }
    //if don't have an image delete the last image
    this->deleteImage();edkEnd();
    return false;
}
