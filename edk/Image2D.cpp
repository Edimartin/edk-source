#include "Image2D.h"

/*
Library Image2D - Load a 2D Image using SFML
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#ifdef printMessages
#warning "            Inside Image2D.cpp"
#endif

namespace edk {




Image2D::Image2D()
{
    //ctor
    this->imageName=NULL;
    this->imageFileName=NULL;
    this->vec = NULL;
    this->channels=0u;
}

Image2D::Image2D(char8 *imageFileName)
{
    //clean all
    this->imageName=NULL;
    this->imageFileName=NULL;
    this->vec = NULL;
    this->channels=0u;
    //load the image
    this->loadFromFile(imageFileName);
}

Image2D::Image2D(const char *imageFileName)
{
    //clean all
    this->imageName=NULL;
    this->imageFileName=NULL;
    this->vec = NULL;
    this->channels=0u;
    //load the image
    this->loadFromFile(imageFileName);
}

Image2D::~Image2D()
{
    //dtor
    this->deleteImage();
    //    this->deleteName();
    //    this->deleteFileName();
}


//Private
//imageFileNameFunctions
void edk::Image2D::setFileName(edk::char8* imageFileName){
    //delete the lastFileName
    this->deleteFileName();

    //test if the new imageFileName is alloc
    if(imageFileName){
        //then copy the imageFileName
        this->imageFileName = edk::String::strCopy(imageFileName);
    }
}
void edk::Image2D::setFileName(const char* imageFileName){
    //
    this->setFileName((edk::char8*) imageFileName);
}
void edk::Image2D::deleteFileName(){
    //test if have a imageFileName
    if(this->haveFileName()){
        //delete the imageFileName
        delete[] this->imageFileName;
    }
    this->imageFileName=NULL;
}
//discover the imageType
edk::uint8 Image2D::getStreamType(edk::uint8* encoded){
    //test the stream encoded
    if(encoded){
        //test if are JPEG
        if(encoded[0u] == 0xFF){
            if(encoded[1u] == 0xD8){
                //return JPEG
                return EDK_CODEC_JPEG;
            }
        }
        else{
            if(encoded[0u] == 0x89){
                if(encoded[1u] == 0x50){
                    if(encoded[2u] == 0x4E){
                        if(encoded[3u] == 0x47){
                            return EDK_CODEC_PNG;
                        }
                    }
                }
            }
        }
    }
    return EDK_CODEC_NO;
}
//discover the nameType
edk::uint8 Image2D::getNameType(edk::char8* name){
    //test the fileName
    if(name){
        //get the fileSize
        edk::uint32 size = edk::String::strSize(name);
        if(size>sizeof(".xxxx")){
            //go to the last character
            edk::char8* str = &name[size-1u];
            if(*str == 'g'){
                str--;
                if(*str == 'e'){
                    //
                    str--;
                    if(*str == 'p'){
                        //
                        str--;
                        if(*str == 'j'){
                            //
                            str--;
                            if(*str == '.'){
                                //it's a JPEG name
                                return EDK_CODEC_JPEG;
                            }
                        }
                    }
                }
                else if(*str == 'p'){
                    //
                    str--;
                    if(*str == 'j'){
                        //
                        str--;
                        if(*str == '.'){
                            //it's a JPEG name
                            return EDK_CODEC_JPEG;
                        }
                    }
                }
                else if(*str == 'n'){
                    //test if it's png
                    str--;
                    if(*str == 'p'){
                        //
                        str--;
                        if(*str == '.'){
                            //it's a PNG name
                            return EDK_CODEC_PNG;
                        }
                    }
                }
            }
            else if(*str == 'G'){
                str--;
                if(*str == 'E'){
                    //
                    str--;
                    if(*str == 'P'){
                        //
                        str--;
                        if(*str == 'J'){
                            //
                            str--;
                            if(*str == '.'){
                                //it's a JPEG name
                                return EDK_CODEC_JPEG;
                            }
                        }
                    }
                }
                else if(*str == 'P'){
                    //
                    str--;
                    if(*str == 'J'){
                        //
                        str--;

                        if(*str == '.'){
                            //it's a JPEG name
                            return EDK_CODEC_JPEG;
                        }
                    }
                }
                else if(*str == 'N'){
                    //test if it's png
                    str--;
                    if(*str == 'P'){
                        //
                        str--;
                        if(*str == '.'){
                            //it's a PNG name
                            return EDK_CODEC_PNG;
                        }
                    }
                }
            }
        }
    }
    return EDK_CODEC_NO;
}


//create a new Image
bool Image2D::newImage(edk::char8 *imageName,edk::size2ui32 size,edk::uint8 channels){
    //delete the last image
    this->deleteImage();
    //test the new image
    if(imageName&&size.width&&size.height&&channels&&channels<=4u){
        //set the name
        if(this->setName(imageName)){
            //set the size
            this->size = size;
            this->channels=channels;
            edk::uint32 imageSize = size.width*size.height;
            //create the new vector
            this->vec = new edk::uint8[imageSize * this->channels];
            if(this->vec){
                //return true
                return true;
            }
        }
    }
    this->deleteImage();
    return false;
}
bool Image2D::newImage(edk::char8 *imageName,edk::uint32 width,edk::uint32 height,edk::uint8 channels){
    return this->newImage(imageName,edk::size2ui32(width,height),channels);
}
bool Image2D::newImage(const char *imageName,edk::size2ui32 size,edk::uint8 channels){
    return this->newImage((edk::char8 *)imageName,size,channels);
}
bool Image2D::newImage(const char *imageName,edk::uint32 width,edk::uint32 height,edk::uint8 channels){
    return this->newImage((edk::char8 *)imageName,width,height,channels);
}

bool Image2D::loadFromFile(char8 *imageFileName)
{
    //open the file
    edk::File file;
    if(file.openBinFile(imageFileName)){
        if(file.getFileSize()){
            bool ret=false;
            //copy the file
            edk::uint8* fileVector = new edk::uint8[file.getFileSize()];
            if(fileVector){
                //copy the file
                if(file.readBin(fileVector,file.getFileSize())){
                    //process the decoder
                    ret = this->loadFromMemory(fileVector,file.getFileSize());
                }
                delete[] fileVector;
                //test if neet delete the name
                if(ret){
                    if(!this->setName(imageFileName)){
                        ret=false;
                    }
                }
            }
            return ret;
        }
    }
    //delete the last image
    this->deleteImage();
    //delete the imageFileName
    this->deleteFileName();
    //else return false
    return false;
}

bool Image2D::loadFromFile(const char *imageFileName){
    return this->loadFromFile((edk::char8*)imageFileName);
}

bool Image2D::loadFromFileToRGBA(char8 *imageFileName){
    //open the file
    edk::File file;
    if(file.openBinFile(imageFileName)){
        if(file.getFileSize()){
            bool ret=false;
            //copy the file
            edk::uint8* fileVector = new edk::uint8[file.getFileSize()];
            if(fileVector){
                //copy the file
                if(file.readBin(fileVector,file.getFileSize())){
                    //process the decoder
                    ret = this->loadFromMemoryToRGBA(fileVector,file.getFileSize());
                }
                delete[] fileVector;
                //test if neet delete the name
                if(ret){
                    if(!this->setName(imageFileName)){
                        ret=false;
                    }
                }
            }
            return ret;
        }
    }
    //delete the last image
    this->deleteImage();
    //delete the imageFileName
    this->deleteFileName();
    //else return false
    return false;
}

bool Image2D::loadFromFileToRGBA(const char *imageFileName){
    return this->loadFromFileToRGBA((edk::char8*)imageFileName);
}

bool Image2D::loadFromMemory(uint8 *image, edk::uint32 vecSize){
    //delete the vector
    this->deleteImage();
    //this->deleteName();
    if(image && vecSize){
        edk::uint8 type = this->getStreamType(image);
        switch(type){
        case EDK_CODEC_JPEG:
        {
            //decode using jpegCodec
            edk::codecs::DecoderJPEG decoder;
            if(decoder.decode(image,vecSize)){
                this->vec = decoder.getFrame();
                if(vec){
                    //get size
                    this->size = edk::size2ui32(decoder.getFrameWidth(),decoder.getFrameHeight());//2.0
                    //get channels
                    this->channels = decoder.getFrameChannels();
                    decoder.cleanFrame();
                    return true;
                }
            }
        }
            break;
        case EDK_CODEC_PNG:
        {
            //alloc a new image
            sf::Image imageTemp;
            //open the file
            if(imageTemp.loadFromMemory( image,vecSize )){
                //Get the image size
                //this->size = edk::size2ui32(this->imageTemp->GetWidth(),this->imageTemp->GetHeight());1.6
                this->size = edk::size2ui32(imageTemp.getSize().x,imageTemp.getSize().y);//2.0
                //set the channels
                this->channels=4u;
                //alloc the new image
                this->vec = new edk::uint8[this->size.width * this->size.height * 4u];
                if(this->vec){
                    //copy the image vector
                    memcpy(this->vec,imageTemp.getPixelsPtr(),this->size.width * this->size.height * 4u);
                    //copy the imageFileName
                    this->setFileName(this->imageFileName);
                    return true;
                }
            }
            else{
                //else remove the image
                this->deleteImage();
            }
        }
            break;
        }
    }
    return false;
}

bool Image2D::loadFromMemoryToRGBA(uint8 *image, edk::uint32 vecSize){
    //delete the vector
    this->deleteImage();
    //this->deleteName();
    if(image && vecSize){
        edk::uint8 type = this->getStreamType(image);

#ifdef _WIN64
        type = EDK_CODEC_PNG;
#endif // WIN64_

        switch(type){
        case EDK_CODEC_JPEG:
        {
            //decode using jpegCodec
            edk::codecs::DecoderJPEG decoder;
            if(decoder.decode(image,vecSize)){
                edk::uint32 imageSize = decoder.getFrameWidth()*decoder.getFrameHeight();
                if(imageSize){
                    this->vec = new edk::uint8[imageSize*4u];
                    //get channels
                    this->channels = decoder.getFrameChannels();
                    if(this->channels==1u || this->channels == 3u){
                        if(vec){
                            //get size
                            this->size = edk::size2ui32(decoder.getFrameWidth(),decoder.getFrameHeight());
                            //Convert the frame to RGBA
                            edk::uint8* rgbaTemp = this->vec;
                            edk::uint8* frameTemp = decoder.getFrame();
                            switch(this->channels){
                            case 1:
                                for(edk::uint32 i=0u;i<imageSize;i++){
                                    rgbaTemp[0u] = frameTemp[0u];
                                    rgbaTemp[1u] = frameTemp[0u];
                                    rgbaTemp[2u] = frameTemp[0u];
                                    rgbaTemp[3u] = 255;
                                    rgbaTemp+=4u;
                                    frameTemp+=1u;
                                }
                                decoder.deleteFrame();
                                this->channels=4u;
                                return true;
                            case 3:
                                for(edk::uint32 i=0u;i<imageSize;i++){
                                    rgbaTemp[0u] = frameTemp[0u];
                                    rgbaTemp[1u] = frameTemp[1u];
                                    rgbaTemp[2u] = frameTemp[2u];
                                    rgbaTemp[3u] = 255;
                                    rgbaTemp+=4u;
                                    frameTemp+=3u;
                                }
                                decoder.deleteFrame();
                                this->channels=4u;
                                return true;
                            }
                            delete vec;
                        }
                    }
                }
            }
        }
            break;
        case EDK_CODEC_PNG:
        {
            //alloc a new image
            sf::Image imageTemp;
            //open the file
            if(imageTemp.loadFromMemory( image,vecSize )){
                //Get the image size
                //this->size = edk::size2ui32(this->imageTemp->GetWidth(),this->imageTemp->GetHeight());1.6
                this->size = edk::size2ui32(imageTemp.getSize().x,imageTemp.getSize().y);//2.0
                //set the channels
                this->channels=4u;
                //alloc the new image
                this->vec = new edk::uint8[this->size.width * this->size.height * 4u];
                if(this->vec){
                    //copy the image vector
                    memcpy(this->vec,imageTemp.getPixelsPtr(),this->size.width * this->size.height * 4u);
                    //copy the imageFileName
                    this->setFileName(imageFileName);
                    return true;
                }
            }
            else{
                //else remove the image
                this->deleteImage();
            }
        }
            break;
        }
    }
    return false;
}

//save the image
bool Image2D::saveToFile(edk::char8 *fileName){
    //test if have image
    if(this->haveImage()){
        bool deleteTempName=false;
        bool ret=false;

        //get the name type
        edk::uint8 nameType = getNameType(fileName);

        //test the channels
        switch(this->getChannels()){
        case 1u:
        case 3u:
            //save jpeg
            if(!fileName){
                fileName = edk::String::strCat(this->getName(),(edk::char8*)".jpg");
                deleteTempName = true;
                nameType = EDK_CODEC_JPEG;
            }
            if(fileName){
                switch(nameType){
                case EDK_CODEC_NO:
                    //concatenate .jpg with the name
                    fileName = edk::String::strCat(fileName,(edk::char8*)".jpg");
                    deleteTempName = true;
                case EDK_CODEC_JPEG:
                {
                    //save the encoder
                    edk::codecs::EncoderJPEG encoder;
                    ret = encoder.encodeToFile(this->vec,this->size.width,this->size.height,this->channels,100,fileName);
                    if(deleteTempName)
                        delete[] fileName;
                    break;
                }
                case EDK_CODEC_PNG:
                {
                    //use sf::image
                    sf::Image encoder;
                    encoder.create(this->size.width,this->size.height,sf::Color::White);
                    edk::uint8* temp = this->vec;
                    //copy the pixels
                    for(edk::uint32 y=0u;y<this->size.height;y++){
                        for(edk::uint32 x=0u;x<this->size.width;x++){
                            encoder.setPixel(x,y,sf::Color(temp[0u],
                                             temp[1u],
                                    temp[2u],
                                    255u
                                    )
                                    );
                            temp+=3u;
                        }
                    }
                    //save the image
                    ret = encoder.saveToFile(std::string((const char*)fileName));
                    if(deleteTempName)
                        delete[] fileName;
                    break;
                }
                }
            }
            break;
        case 4u:
            //save jpeg
            if(!fileName){
                fileName = edk::String::strCat(this->getName(),(edk::char8*)".png");
                deleteTempName = true;
                nameType = EDK_CODEC_PNG;
            }
            if(fileName){
                switch(nameType){
                case EDK_CODEC_NO:
                    //concatenate .jpg with the name
                    fileName = edk::String::strCat(fileName,(edk::char8*)".png");
                    deleteTempName = true;
                case EDK_CODEC_JPEG:
                    ret=false;
                    break;
                case EDK_CODEC_PNG:
                {
                    //use sf::image
                    sf::Image encoder;
                    encoder.create(this->size.width,this->size.height,sf::Color::White);
                    edk::uint8* temp = this->vec;
                    //copy the pixels
                    for(edk::uint32 y=0u;y<this->size.height;y++){
                        for(edk::uint32 x=0u;x<this->size.width;x++){
                            encoder.setPixel(x,y,sf::Color(temp[0u],
                                             temp[1u],
                                    temp[2u],
                                    temp[3u]
                                    )
                                    );
                            temp+=4u;
                        }
                    }
                    //save the image
                    ret = encoder.saveToFile(std::string((const char*)fileName));
                    if(deleteTempName)
                        delete[] fileName;
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
bool Image2D::saveToFile(const char *fileName){
    return this->saveToFile((edk::char8 *)fileName);
}

bool Image2D::setName(char8 *imageName)
{
    //delete the last imageName
    this->deleteName();

    //test if the new imageName is alloc
    if(imageName){
        //then copy the imageName
        return (bool)(this->imageName = edk::String::strCopy(imageName));
    }
    //else return false
    return false;
}

bool Image2D::setName(const char *imageName)
{
    return this->setName((edk::char8*) imageName);
}

//draw on the image
bool Image2D::draw(edk::uint8* pixels){
    if(pixels && this->haveImage()){
        memcpy(this->vec,pixels,this->getWidth()*this->getHeight()*this->getChannels());
        return true;
    }
    return false;
}

size2ui32 Image2D::getSize()
{
    //test if have a image
    return this->size;
}

uint32 Image2D::getWidth(){
    return this->getSize().width;
}

uint32 Image2D::getHeight(){
    return this->getSize().height;
}

uint32 Image2D::width()
{
    return this->getSize().width;
}

uint32 Image2D::height()
{
    return this->getSize().height;
}
//return the channels of the image
edk::uint8 Image2D::getChannels(){
    return this->channels;
}

bool Image2D::haveImage()
{
    return (bool)this->vec;
}

bool Image2D::haveName()
{
    return (bool)this->imageName;
}

bool Image2D::haveFileName()
{
    return (bool)this->imageFileName;
}

char8* Image2D::getName()
{
    return this->imageName;
}

char8* Image2D::name()
{
    return this->getName();
}

char8* Image2D::getFileName()
{
    return this->imageFileName;
}

char8* Image2D::fileName()
{
    return this->getFileName();
}

//return the pixels of the image to use in videoBoard
edk::uint8* Image2D::getPixels(){
    //test if open the image
    if(this->haveImage()){
        //then return the pointer
        return this->vec;
    }
    //else return false
    return NULL;
}

void Image2D::deleteImage()
{
    //testa se possui uma image
    if(this->haveImage()){
        //
        delete[] this->vec;
    }
    this->vec=NULL;
    //clean the channels
    this->channels=0u;
    //clean the size
    this->size = edk::size2ui32(0u,0u);

    //delete the imageNames
    this->deleteName();
    this->deleteFileName();
}

void Image2D::deleteName()
{
    //
    if(this->haveName()){
        //
        delete[] this->imageName;
    }
    this->imageName=NULL;
}

//Convertions
//RGB to HSV
edk::color3f32 Image2D::rgbTohsv(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::codecs::CodecImage::rgbTohsv(r,g,b);
}
edk::color3f32 Image2D::rgbTohsv(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbTohsv(rgb.r,rgb.g,rgb.b);
}
edk::color3f32 Image2D::rgbTohsv(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbTohsv(rgba.r,rgba.g,rgba.b);
}
edk::uint8 Image2D::rgbToV(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::codecs::CodecImage::rgbToV(r,g,b);
}
edk::uint8 Image2D::rgbToV(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbToV(rgb.r,rgb.g,rgb.b);
}
edk::uint8 Image2D::rgbaToV(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbToV(rgba.r,rgba.g,rgba.b);
}
//vector
bool Image2D::rgbToV(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbToV(vector,size,dest);
}
edk::uint8* Image2D::rgbToV(edk::uint8* vector,edk::size2ui32 size){
    return edk::codecs::CodecImage::rgbToV(vector,size);
}
bool Image2D::rgbToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbToV(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* Image2D::rgbToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbToV(vector,edk::size2ui32(width,height));
}
bool Image2D::rgbaToV(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbaToV(vector,size,dest);
}
edk::uint8* Image2D::rgbaToV(edk::uint8* vector,edk::size2ui32 size){
    return edk::codecs::CodecImage::rgbaToV(vector,size);
}
bool Image2D::rgbaToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbaToV(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* Image2D::rgbaToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbaToV(vector,edk::size2ui32(width,height));
}
//HSV to RGB
edk::color3ui8 Image2D::hsvTorgb(edk::float32 h,edk::float32 s,edk::float32 v){
    return edk::codecs::CodecImage::hsvTorgb(h,s,v);
}
edk::color3ui8 Image2D::hsvTorgb(edk::color3f32 hsv){
    return edk::codecs::CodecImage::hsvTorgb(hsv.r,hsv.g,hsv.b);
}
//RGB to HSL
edk::color3f32 Image2D::rgbTohsl(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::codecs::CodecImage::rgbTohsl(r,g,b);
}
edk::color3f32 Image2D::rgbTohsl(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbTohsl(rgb.r,rgb.g,rgb.b);
}
edk::color3f32 Image2D::rgbaTohsl(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbTohsl(rgba.r,rgba.g,rgba.b);
}
edk::float32 Image2D::rgbToL(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::codecs::CodecImage::rgbToL(r,g,b);
}
edk::float32 Image2D::rgbToL(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbToL(rgb.r,rgb.g,rgb.b);
}
edk::float32 Image2D::rgbaToL(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbToL(rgba.r,rgba.g,rgba.b);
}
edk::uint8 Image2D::rgbToLui8(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::codecs::CodecImage::rgbToLui8(r,g,b);
}
edk::uint8 Image2D::rgbToLui8(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbToLui8(rgb.r,rgb.g,rgb.b);
}
edk::uint8 Image2D::rgbaToLui8(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbToLui8(rgba.r,rgba.g,rgba.b);
}
//vector
bool Image2D::rgbToLui8(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbToLui8(vector,size,dest);
}
edk::uint8* Image2D::rgbToLui8(edk::uint8* vector,edk::size2ui32 size){
    return edk::codecs::CodecImage::rgbToLui8(vector,size);
}
bool Image2D::rgbToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbToLui8(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* Image2D::rgbToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbToLui8(vector,edk::size2ui32(width,height));
}
bool Image2D::rgbaToLui8(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbaToLui8(vector,size,dest);
}
edk::uint8* Image2D::rgbaToLui8(edk::uint8* vector,edk::size2ui32 size){
    return edk::codecs::CodecImage::rgbaToLui8(vector,size);
}
bool Image2D::rgbaToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbaToLui8(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* Image2D::rgbaToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbaToLui8(vector,edk::size2ui32(width,height));
}
edk::color3ui8 Image2D::hslTorgb(edk::float32 h,edk::float32 s,edk::float32 l){
    return edk::codecs::CodecImage::hslTorgb(h,s,l);
}
edk::color3ui8 Image2D::hslTorgb(edk::color3f32 hsl){
    return edk::codecs::CodecImage::hslTorgb(hsl.r,hsl.g,hsl.b);
}
//RGB to RGBA
edk::color4ui8 Image2D::rgbTorgba(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::color4ui8(r,g,b,(edk::uint8)255u);
}
edk::color4ui8 Image2D::rgbTorgba(edk::color3ui8 rgb){
    return edk::Image2D::rgbTorgba(rgb.r,rgb.g,rgb.b);
}
edk::color4f32 Image2D::rgbTorgba(edk::float32 r,edk::float32 g,edk::float32 b){
    return edk::color4f32(r,g,b,1.f);
}
edk::color4f32 Image2D::rgbTorgba(edk::color3f32 rgb){
    return edk::Image2D::rgbTorgba(rgb.r,rgb.g,rgb.b);
}
//vector
bool Image2D::rgbTorgba(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    if(vector && dest && size.width && size.height){
        for(edk::uint32 y=0u;y<size.height;y++){
            for(edk::uint32 x=0u;x<size.width;x++){
                //copy the channels and add the fourth as 255u
                dest[0u] = vector[0u];
                dest[1u] = vector[1u];
                dest[2u] = vector[2u];
                dest[3u] = 255u;
                //increment the vectors
                vector+=3u;
                dest+=4u;
            }
        }
        return true;
    }
    return false;
}
edk::uint8* Image2D::rgbTorgba(edk::uint8* vector,edk::size2ui32 size){
    if(size.width && size.height){
        edk::uint8* ret = new edk::uint8[size.width*size.height*4u];
        if(ret){
            if (edk::Image2D::rgbTorgba(vector,size,ret)){
                return ret;
            }
            delete[] ret;
        }
    }
    return NULL;
}
bool Image2D::rgbTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::Image2D::rgbTorgba(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* Image2D::rgbTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::Image2D::rgbTorgba(vector,edk::size2ui32(width,height));
}
//LA to RGBA
edk::color4ui8 Image2D::laTorgba(edk::uint8 l,edk::uint8 a){
    return edk::color4ui8(l,l,l,a);
}
edk::color4f32 Image2D::laTorgba(edk::float32 l,edk::float32 a){
    return edk::color4f32(l,l,l,a);
}
//vector
bool Image2D::laTorgba(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    if(vector && dest && size.width && size.height){
        for(edk::uint32 y=0u;y<size.height;y++){
            for(edk::uint32 x=0u;x<size.width;x++){
                //copy the channels
                dest[0u] = vector[0u];
                dest[1u] = vector[0u];
                dest[2u] = vector[0u];
                dest[3u] = vector[1u];
                //increment the vectors
                vector+=2u;
                dest+=4u;
            }
        }
        return true;
    }
    return false;
}
edk::uint8* Image2D::laTorgba(edk::uint8* vector,edk::size2ui32 size){
    if(size.width && size.height){
        edk::uint8* ret = new edk::uint8[size.width*size.height*4u];
        if(ret){
            if (edk::Image2D::laTorgba(vector,size,ret)){
                return ret;
            }
            delete[] ret;
        }
    }
    return NULL;
}
bool Image2D::laTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::Image2D::laTorgba(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* Image2D::laTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::Image2D::laTorgba(vector,edk::size2ui32(width,height));
}
//L to RGBA
edk::color4ui8 Image2D::lTorgba(edk::uint8 l){
    return edk::color4ui8(l,l,l,(edk::uint8)255u);
}
edk::color4f32 Image2D::lTorgba(edk::float32 l){
    return edk::color4f32(l,l,l,1.f);
}
bool Image2D::lTorgba(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    if(vector && dest && size.width && size.height){
        for(edk::uint32 y=0u;y<size.height;y++){
            for(edk::uint32 x=0u;x<size.width;x++){
                //copy the channels
                dest[0u] = vector[0u];
                dest[1u] = vector[0u];
                dest[2u] = vector[0u];
                dest[3u] = 255u;
                //increment the vectors
                vector+=2u;
                dest+=4u;
            }
        }
        return true;
    }
    return false;
}
edk::uint8* Image2D::lTorgba(edk::uint8* vector,edk::size2ui32 size){
    if(size.width && size.height){
        edk::uint8* ret = new edk::uint8[size.width*size.height*4u];
        if(ret){
            if (edk::Image2D::lTorgba(vector,size,ret)){
                return ret;
            }
            delete[] ret;
        }
    }
    return NULL;
}
bool Image2D::lTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::Image2D::lTorgba(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* Image2D::lTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::Image2D::lTorgba(vector,edk::size2ui32(width,height));
}

} /* End of namespace edk */
