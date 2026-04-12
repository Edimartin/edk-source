#include "Image3D.h"

/*
Library Image3D - Create a 3D Image in EDK
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
#pragma message "            Inside Image3D.cpp"
#endif

edk::Image3D::Image3D(){
    this->classThis=NULL;
    this->Constructor();
}

edk::Image3D::~Image3D(){
    this->Destructor();
}

void edk::Image3D::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;
        //ctor
        this->imageName=NULL;
        this->imageFileName=NULL;
        this->vec = NULL;
        this->colors = NULL;
        this->channelsValue=0u;
        this->palette=NULL;
        this->paletteSize=0u;
        this->bytesPerColors=0u;
        this->bytesPerChannel=0u;
    }
}

void edk::Image3D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->clean();
    }
}

void edk::Image3D::clean(){
    this->deleteImage();
}

//Private
//imageFileNameFunctions
void edk::Image3D::setFileName(edk::char8* imageFileName){
    //delete the lastFileName
    this->deleteFileName();

    //test if the new imageFileName is alloc
    if(imageFileName){
        //then copy the imageFileName
        this->imageFileName = edk::String::strCopy(imageFileName);
    }
}
void edk::Image3D::setFileName(const edk::char8* imageFileName){
    //
    this->setFileName((edk::char8*) imageFileName);
}
void edk::Image3D::deleteFileName(){
    //test if have a imageFileName
    if(this->haveFileName()){
        //delete the imageFileName
        free(this->imageFileName);
    }
    this->imageFileName=NULL;
}
//discover the imageType
edk::uint8 edk::Image3D::getStreamType(edk::uint8* encoded){
    //test the stream encoded
    if(encoded){
        //test if are JPEG
        if(encoded[0u] == 0xFF){
            if(encoded[1u] == 0xD8){
                //return JPEG
                return EDK_CODEC_JPEG;
            }
        }
        else if(encoded[0u] == 0x89){
            if(encoded[1u] == 0x50){
                if(encoded[2u] == 0x4E){
                    if(encoded[3u] == 0x47){
                        return EDK_CODEC_PNG;
                    }
                }
            }
        }
        else{
            if(encoded[0u] == '#'){
                if(encoded[1u] == '?'){
                    if(encoded[2u] == 'R'){
                        if(encoded[3u] == 'A'){
                            if(encoded[4u] == 'D'){
                                if(encoded[5u] == 'I'){
                                    if(encoded[6u] == 'A'){
                                        if(encoded[7u] == 'N'){
                                            if(encoded[8u] == 'C'){
                                                if(encoded[9u] == 'E'){
                                                    if(encoded[10u] == 10u){
                                                        return EDK_CODEC_HDR;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return EDK_CODEC_NO;
}
//discover the nameType
edk::uint8 edk::Image3D::getNameType(edk::char8* name){
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
            else if(*str == 'r'){
                str--;
                if(*str == 'd'){
                    //test if it's png
                    str--;
                    if(*str == 'h'){
                        //
                        str--;
                        if(*str == '.'){
                            //it's a PNG name
                            return EDK_CODEC_HDR;
                        }
                    }
                }
            }
        }
    }
    return EDK_CODEC_NO;
}


//create a new Image
bool edk::Image3D::newImage(edk::char8 *imageName,
                            edk::size3ui32 size,
                            edk::uint8 channels,
                            edk::uint8 bytesPerChannel
                            ){
    //delete the last image
    this->deleteImage();
    //test the new image
    if(imageName&&size.width&&size.height&&size.length&&channels&&channels<=4u&&bytesPerChannel&&bytesPerChannel<=4u){
        //set the name
        if(this->setName(imageName)){
            //set the size
            this->size = size;
            this->channelsValue=channels;
            this->bytesPerChannel=bytesPerChannel;
            edk::uint32 imageSize = size.width*size.height*size.length;
            //create the new vector
            this->vec = (edk::uint8*)malloc(sizeof(edk::uint8) * (imageSize * this->channelsValue * this->bytesPerChannel));
            if(this->vec){
                //return true
                return true;
            }
        }
    }
    this->deleteImage();
    return false;
}
bool edk::Image3D::newImage(edk::char8 *imageName,
                            edk::uint32 width,
                            edk::uint32 height,
                            edk::uint32 length,
                            edk::uint8 channels,
                            edk::uint8 bytesPerPixels
                            ){
    return this->newImage(imageName,edk::size3ui32(width,height,length),channels,bytesPerPixels);
}
bool edk::Image3D::newImage(const edk::char8 *imageName,
                            edk::size3ui32 size,
                            edk::uint8 channels,
                            edk::uint8 bytesPerPixels
                            ){
    return this->newImage((edk::char8 *)imageName,size,channels,bytesPerPixels);
}
bool edk::Image3D::newImage(const edk::char8 *imageName,
                            edk::uint32 width,
                            edk::uint32 height,
                            edk::uint32 length,
                            edk::uint8 channels,
                            edk::uint8 bytesPerPixels){
    return this->newImage((edk::char8 *)imageName,width,height,length,channels,bytesPerPixels);
}

//create a new image with a palette
bool edk::Image3D::newImage(edk::char8 *imageName,
                            edk::size3ui32 size,
                            edk::uint8 channels,
                            edk::uint32 paletteSize,
                            edk::uint8 bytesPerChannel
                            ){
    if(!paletteSize){
        return this->newImage(imageName,size,channels,1u);
    }
    //delete the last image
    this->deleteImage();
    //test the new image
    if(imageName&&size.width&&size.height&&size.length&&paletteSize&&channels&&channels<=4u&&bytesPerChannel&&bytesPerChannel<=4u){
        //set the name
        if(this->setName(imageName)){
            //set the size
            this->size = size;
            //clean the channels
            this->channelsValue=channels;
            this->bytesPerChannel=bytesPerChannel;
            //create the palette
            this->palette= (edk::uint8*)malloc(sizeof(edk::uint8) * (paletteSize * this->channelsValue * this->bytesPerChannel));
            if(this->palette){
                this->paletteSize=paletteSize;

                edk::uint32 imageSize = size.width*size.height*size.length;

                //calculate the bits per pixel
                if(this->paletteSize<=0xFF){
                    this->bytesPerColors=1u;
                }
                else if(this->paletteSize<=0xFFFF){
                    this->bytesPerColors=2u;
                }
                else if(this->paletteSize<=0xFFFFFF){
                    this->bytesPerColors=3u;
                }
                else if(this->paletteSize<=0xFFFFFFFF){
                    this->bytesPerColors=4u;
                }

                //create the new vector
                this->colors = (edk::uint8*)malloc(sizeof(edk::uint8) * (imageSize * this->bytesPerColors));
                if(this->colors){
                    memset(this->colors,0u,imageSize * this->bytesPerColors);
                    //return true
                    return true;
                }
            }
        }
    }
    this->deleteImage();
    return false;
}
bool edk::Image3D::newImage(edk::char8 *imageName,
                            edk::uint32 width,
                            edk::uint32 height,
                            edk::uint32 length,
                            edk::uint8 channels,
                            edk::uint32 paletteSize,
                            edk::uint8 bytesPerPixels
                            ){
    return this->newImage(imageName,edk::size3ui32(width,height,length),channels,paletteSize,bytesPerPixels);
}
bool edk::Image3D::newImage(const edk::char8 *imageName,
                            edk::size3ui32 size,
                            edk::uint8 channels,
                            edk::uint32 paletteSize,
                            edk::uint8 bytesPerPixels
                            ){
    return this->newImage((edk::char8 *)imageName,size,channels,paletteSize,bytesPerPixels);
}
bool edk::Image3D::newImage(const edk::char8 *imageName,
                            edk::uint32 width,
                            edk::uint32 height,
                            edk::uint32 length,
                            edk::uint8 channels,
                            edk::uint32 paletteSize,
                            edk::uint8 bytesPerPixels
                            ){
    return this->newImage((edk::char8 *)imageName,width,height,length,channels,paletteSize,bytesPerPixels);
}

//function used to generate the pixels from colors palette
bool edk::Image3D::generatePixelsFromColors(){
    //test if have the image
    edk::uint32 width = this->getWidth();
    edk::uint32 height = this->getHeight();
    edk::uint32 length = this->getLength();
    edk::uint8 channels = this->getChannels();
    edk::uint8 bytes = this->bytesPerColors;
    edk::uint8* palette = this->palette;
    edk::uint32 paletteSize = this->paletteSize;

    if(this->haveImage() && width && height && length && channels && this->haveColors() && bytes && palette && paletteSize){
        //delete the last vector
        if(this->vec){
            free(this->vec);
        }
        //create a new vec
        this->vec = (edk::uint8*)malloc(sizeof(edk::uint8) * (width*height*length*channels) * bytes);
        //create the new vec to set the pixels
        if(this->vec){
            //copy the colors in to pixels
            //pixel vector
            edk::uint8* vector = this->vec;
            //color id vector
            edk::uint8* colors = this->colors;
            //color id vector
            //edk::uint8* color = NULL;

            switch(bytes){
            case 1u:
            {
                //color id
                edk::uint8 colorID;
                //copy the colors into pixels
                for(edk::uint32 z=0u;z<length;z++){
                    for(edk::uint32 y=0u;y<height;y++){
                        for(edk::uint32 x=0u;x<width;x++){
                            mempcpy(&colorID,colors,sizeof(colorID));
                            if(colorID < paletteSize){
                                //convert the color ID to the pixel channel
                                memcpy(vector,&palette[colorID*channels],channels);
                            }
                            //increment the vectors and colors
                            vector+=channels;
                            colors+=bytes;
                        }
                    }
                }
            }
                break;
            case 2u:
            {
                //
                edk::uint16 colorID;
                //copy the colors into pixels
                for(edk::uint32 z=0u;z<length;z++){
                    for(edk::uint32 y=0u;y<height;y++){
                        for(edk::uint32 x=0u;x<width;x++){
                            mempcpy(&colorID,colors,sizeof(colorID));
                            if(colorID < paletteSize){
                                //convert the color ID to the pixel channel
                                memcpy(vector,&palette[colorID*channels],channels);
                            }
                            //increment the vectors and colors
                            vector+=channels;
                            colors+=bytes;
                        }
                    }
                }
            }
                break;
            case 3u:
            {
                //
                edk::uint32 colorID;
                //copy the colors into pixels
                for(edk::uint32 z=0u;z<length;z++){
                    for(edk::uint32 y=0u;y<height;y++){
                        for(edk::uint32 x=0u;x<width;x++){
                            mempcpy(&colorID,colors,/*sizeof(colorID)*/3u);
                            if(colorID < paletteSize){
                                //convert the color ID to the pixel channel
                                memcpy(vector,&palette[colorID*channels],channels);
                            }
                            //increment the vectors and colors
                            vector+=channels;
                            colors+=bytes;
                        }
                    }
                }
            }
                break;
            case 4u:
            {
                //
                edk::uint32 colorID;
                //copy the colors into pixels
                for(edk::uint32 z=0u;z<length;z++){
                    for(edk::uint32 y=0u;y<height;y++){
                        for(edk::uint32 x=0u;x<width;x++){
                            mempcpy(&colorID,colors,sizeof(colorID));
                            if(colorID < paletteSize){
                                //convert the color ID to the pixel channel
                                memcpy(vector,&palette[colorID*channels],channels);
                            }
                            //increment the vectors and colors
                            vector+=channels;
                            colors+=bytes;
                        }
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

bool edk::Image3D::setName(char8 *imageName)
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

bool edk::Image3D::setName(const char *imageName)
{
    return this->setName((edk::char8*) imageName);
}

//draw on the image
bool edk::Image3D::draw(edk::uint8* pixels){
    if(pixels && this->haveImage()){
        memcpy(this->vec,pixels,this->getWidth()*this->getHeight()*this->getLength()*this->getChannels());
        return true;
    }
    return false;
}
//clean the image with an color
bool edk::Image3D::drawColorPointer(edk::uint8* color,edk::uint8 channels){
    if(color && this->vec && channels && channels<=4u){
        edk::uint32 imageSize = this->getWidth() * this->getHeight() * this->getLength();
        edk::uint8* vecTemp = this->vec;
        switch(this->channelsValue){
        case 1:
            if(this->vec){
                for(edk::uint32 i=0u;i<imageSize;i++){
                    vecTemp[0u] = color[0u];
                    vecTemp+=1u;
                }
                return true;
            }
            break;
        case 2:
            if(this->vec){
                if(channels == 1u){
                    for(edk::uint32 i=0u;i<imageSize;i++){
                        vecTemp[0u] = color[0u];
                        vecTemp+=2u;
                    }
                }
                else{
                    for(edk::uint32 i=0u;i<imageSize;i++){
                        vecTemp[0u] = color[0u];
                        vecTemp[1u] = color[1u];
                        vecTemp+=2u;
                    }
                }
                return true;
            }
            break;
        case 3:
            if(this->vec){
                if(channels <= 2u){
                    for(edk::uint32 i=0u;i<imageSize;i++){
                        vecTemp[0u] = color[0u];
                        vecTemp[1u] = color[1u];
                        vecTemp+=3u;
                    }
                }
                else{
                    for(edk::uint32 i=0u;i<imageSize;i++){
                        vecTemp[0u] = color[0u];
                        vecTemp[1u] = color[1u];
                        vecTemp[2u] = color[2u];
                        vecTemp+=3u;
                    }
                }
                return true;
            }
            break;
        case 4:
            if(this->vec){
                if(channels <= 3u){
                    for(edk::uint32 i=0u;i<imageSize;i++){
                        vecTemp[0u] = color[0u];
                        vecTemp[1u] = color[1u];
                        vecTemp[2u] = color[2u];
                        vecTemp+=4u;
                    }
                }
                else{
                    for(edk::uint32 i=0u;i<imageSize;i++){
                        vecTemp[0u] = color[0u];
                        vecTemp[1u] = color[1u];
                        vecTemp[2u] = color[2u];
                        vecTemp[3u] = color[3u];
                        vecTemp+=4u;
                    }
                }
                return true;
            }
            break;
        }
    }
    return false;
}
bool edk::Image3D::drawColor(edk::uint8 r){
    edk::uint8 color=r;
    return this->drawColorPointer(&color,sizeof(color));
}
bool edk::Image3D::drawColor(edk::uint8 r,edk::uint8 g){
    edk::uint8 color[2u]={r,g};
    return this->drawColorPointer(color,sizeof(color));
}
bool edk::Image3D::drawColor(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    edk::uint8 color[3u]={r,g,b};
    return this->drawColorPointer(color,sizeof(color));
}
bool edk::Image3D::drawColor(edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
    edk::uint8 color[4u]={r,g,b,a};
    return this->drawColorPointer(color,sizeof(color));
}
bool edk::Image3D::drawColorBlack(){
    switch(this->channelsValue){
    case 1u:
        return this->drawColor(0u);
        break;
    case 2u:
        return this->drawColor(0u,255u);
        break;
    case 3u:
        return this->drawColor(0u,0u,0u);
        break;
    case 4u:
        return this->drawColor(0u,0u,0u,255u);
        break;
    }
    return false;
}
bool edk::Image3D::drawColorWhite(){
    return this->drawColor(255u,255u,255u,255u);
}
//draw a color in the image vector
bool edk::Image3D::drawPosition(edk::vec3ui32 position,edk::uint8* color){
    if(position.x < this->getWidth() && position.y<this->getHeight() && position.z<this->getLength() && color){
        memcpy(&this->vec[(position.x + (position.y*this->getHeight()) + (position.z*this->getLength())) * this->channelsValue],color,this->channelsValue);
        return true;
    }
    return false;
}
bool edk::Image3D::drawPosition(edk::vec3ui32 position,edk::uint8 g){
    edk::uint8 color[4u] = {g,1u,0u,0u};
    return this->drawPosition(position,(edk::uint8*)&color);
}
bool edk::Image3D::drawPosition(edk::vec3ui32 position,edk::uint8 g,edk::uint8 a){
    edk::uint8 color[4u] = {g,a,0u,0u};
    return this->drawPosition(position,(edk::uint8*)&color);
}
bool edk::Image3D::drawPosition(edk::vec3ui32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b){
    edk::uint8 color[4u] = {r,g,b,1u};
    return this->drawPosition(position,(edk::uint8*)&color);
}
bool edk::Image3D::drawPosition(edk::vec3ui32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
    edk::uint8 color[4u] = {r,g,b,a};
    return this->drawPosition(position,(edk::uint8*)&color);
}
bool edk::Image3D::drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 positionZ,edk::uint8* color){
    return this->drawPosition(edk::vec3ui32(positionX,positionY,positionZ),color);
}
bool edk::Image3D::drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 positionZ,edk::uint8 g){
    return this->drawPosition(edk::vec3ui32(positionX,positionY,positionZ),g);
}
bool edk::Image3D::drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 positionZ,edk::uint8 g,edk::uint8 a){
    return this->drawPosition(edk::vec3ui32(positionX,positionY,positionZ),g,a);
}
bool edk::Image3D::drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 positionZ,edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return this->drawPosition(edk::vec3ui32(positionX,positionY,positionZ),r,g,b);
}
bool edk::Image3D::drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 positionZ,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
    return this->drawPosition(edk::vec3ui32(positionX,positionY,positionZ),r,g,b,a);
}
bool edk::Image3D::drawPosition(edk::uint32 position,edk::uint8* color){
    if(position < (this->getWidth()*this->getHeight()*this->getLength()) && color){
        memcpy(&this->vec[position * this->channelsValue],color,this->channelsValue);
        return true;
    }
    return false;
}
bool edk::Image3D::drawPosition(edk::uint32 position,edk::uint8 g){
    edk::uint8 color[4u] = {g,1u,0u,0u};
    return this->drawPosition(position,(edk::uint8*)&color);
}
bool edk::Image3D::drawPosition(edk::uint32 position,edk::uint8 g,edk::uint8 a){
    edk::uint8 color[4u] = {g,a,0u,0u};
    return this->drawPosition(position,(edk::uint8*)&color);
}
bool edk::Image3D::drawPosition(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b){
    edk::uint8 color[4u] = {r,g,b,1u};
    return this->drawPosition(position,(edk::uint8*)&color);
}
bool edk::Image3D::drawPosition(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
    edk::uint8 color[4u] = {r,g,b,a};
    return this->drawPosition(position,(edk::uint8*)&color);
}
//draw the colors on the palette. The user need to know the size of the palette multiply by channel size
bool edk::Image3D::drawPalette(edk::uint8* colors){
    if(colors && this->havePalette()){
        memcpy(this->colors,colors,this->getWidth()*this->getHeight()*this->getLength()*this->getChannels());
        return true;
    }
    return false;
}
//draw a color in palette position
bool edk::Image3D::drawPalettePosition(edk::uint32 position,edk::uint8* color){
    if(position < this->paletteSize && color && this->palette){
        //set the color
        memcpy(&this->palette[position],color,this->channelsValue);
        return true;
    }
    return false;
}
bool edk::Image3D::drawPalettePosition(edk::uint32 position,edk::uint8 g){
    edk::uint8 color[4u] = {g,1u,0u,0u};
    return this->drawPalettePosition(position,(edk::uint8*)&color);
}
bool edk::Image3D::drawPalettePosition(edk::uint32 position,edk::uint8 g,edk::uint8 a){
    edk::uint8 color[4u] = {g,a,0u,0u};
    return this->drawPalettePosition(position,(edk::uint8*)&color);
}
bool edk::Image3D::drawPalettePosition(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b){
    edk::uint8 color[4u] = {r,g,b,1u};
    return this->drawPalettePosition(position,(edk::uint8*)&color);
}
bool edk::Image3D::drawPalettePosition(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
    edk::uint8 color[4u] = {r,g,b,a};
    return this->drawPalettePosition(position,(edk::uint8*)&color);
}
//draw the colorIDs in the image using the palette positions. The user need to know the colors size which is the paletteSize multiply by bytesPerColor
bool edk::Image3D::drawColors(edk::uint8* colors){
    if(this->colors && colors && this->getWidth() && getHeight() && getLength() && this->getBytesPerColor()){
        memcpy(this->colors,colors,this->getWidth()*this->getHeight()*this->getLength()*this->getBytesPerColor());
        return true;
    }
    return false;
}
//draw a color position from the palette in colors vector.
bool edk::Image3D::drawColorsPosition(edk::vec3ui32 position,edk::uint8* colorID){
    if(position.x < this->getWidth() && position.y<this->getHeight() && position.z<this->getLength() && colorID){
        edk::uint32 i = (position.x + (position.y*this->getHeight()) + (position.z*this->getLength())) * this->bytesPerColors;
        memcpy(&this->colors[i],colorID,this->bytesPerColors);
        return true;
    }
    return false;
}
bool edk::Image3D::drawColorsPosition(edk::vec3ui32 position,edk::uint8 colorID){
    switch(this->bytesPerColors){
    case 1u:
    {
        edk::uint8 color = colorID;
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
bool edk::Image3D::drawColorsPosition(edk::vec3ui32 position,edk::uint16 colorID){
    switch(this->bytesPerColors){
    case 1u:
    {
        edk::uint8 color = (edk::uint8)colorID;
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
bool edk::Image3D::drawColorsPosition(edk::vec3ui32 position,edk::uint32 colorID){
    switch(this->bytesPerColors){
    case 1u:
    {
        edk::uint8 color = (edk::uint8)colorID;
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
bool edk::Image3D::drawColorsPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 positionZ,edk::uint8* colorID){
    return this->drawColorsPosition(edk::vec3ui32(positionX,positionY,positionZ),colorID);
}
bool edk::Image3D::drawColorsPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 positionZ,edk::uint8 colorID){
    return this->drawColorsPosition(edk::vec3ui32(positionX,positionY,positionZ),colorID);
}
bool edk::Image3D::drawColorsPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 positionZ,edk::uint16 colorID){
    return this->drawColorsPosition(edk::vec3ui32(positionX,positionY,positionZ),colorID);
}
bool edk::Image3D::drawColorsPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 positionZ,edk::uint32 colorID){
    return this->drawColorsPosition(edk::vec3ui32(positionX,positionY,positionZ),colorID);
}

edk::size3ui32 edk::Image3D::getSize()
{
    //test if have a image
    return this->size;
}

edk::uint32 edk::Image3D::getWidth(){
    return this->getSize().width;
}

edk::uint32 edk::Image3D::getHeight(){
    return this->getSize().height;
}

edk::uint32 edk::Image3D::getLength(){
    return this->getSize().length;
}

edk::uint32 edk::Image3D::width()
{
    return this->getSize().width;
}

edk::uint32 edk::Image3D::height()
{
    return this->getSize().height;
}

edk::uint32 edk::Image3D::length(){
    return this->getSize().length;
}
//return the channels of the image
edk::uint8 edk::Image3D::getChannels(){
    return this->channelsValue;
}
edk::uint8 edk::Image3D::channels(){
    return this->channelsValue;
}
//return the bytes per color to set the color values with the palette positions.
edk::uint8 edk::Image3D::getBytesPerColor(){
    return this->bytesPerColors;
}
//return the bytes per pixel to have different images from normal RGB to RHB HDR
edk::uint8 edk::Image3D::getBytesPerChannel(){
    return this->bytesPerChannel;
}
//return the number of colors on the palette
edk::uint32 edk::Image3D::getPaletteSize(){
    return this->paletteSize;
}
//get the vector size
edk::uint32 edk::Image3D::getPixelsLenght(){
    return this->getWidth() * this->getHeight() * this->getLength() * this->getChannels();
}
//get the palette size
edk::uint32 edk::Image3D::getPaletteLenght(){
    return this->getPaletteSize() * this->getChannels();
}
//get the colors length returh the colors vector length with the palette ID's
edk::uint32 edk::Image3D::getColorsLenght(){
    return this->getBytesPerColor() * this->getWidth() * this->getHeight() * this->getLength();
}

bool edk::Image3D::haveImage()
{
    return (bool)this->vec;
}

bool edk::Image3D::haveColors(){
    return (bool)this->colors;
}

bool edk::Image3D::havePalette(){
    return (bool)this->palette;
}

bool edk::Image3D::haveName()
{
    return (bool)this->imageName;
}

bool edk::Image3D::haveFileName()
{
    return (bool)this->imageFileName;
}

edk::char8* edk::Image3D::getName()
{
    return this->imageName;
}

edk::char8* edk::Image3D::name()
{
    return this->getName();
}

edk::char8* edk::Image3D::getFileName()
{
    return this->imageFileName;
}

edk::char8* edk::Image3D::fileName()
{
    return this->getFileName();
}

//return the pixels of the image to use in videoBoard
edk::uint8* edk::Image3D::getPixels(){
    //test if open the image
    if(this->haveImage()){
        //then return the pointer
        return this->vec;
    }
    //else return false
    return NULL;
}
edk::uint8 edk::Image3D::getPixelR(edk::vec3ui32 position){
    edk::uint8 ret=0u;
    if(position.x<this->getWidth()
            && position.y<this->getHeight()
            && position.z<this->getLength()
            && (this->getChannels() == 3u || this->getChannels() == 4u)
            ){
        ret = this->vec[(((position.y*this->getWidth())
                          + position.x) * this->getChannels())
                + 0u
                ];
    }
    return ret;
}
edk::uint8 edk::Image3D::getPixelR(edk::uint32 x,edk::uint32 y,edk::uint32 z){
    return this->getPixelR(edk::vec3ui32(x,y,z));
}
edk::uint8 edk::Image3D::getPixelG(edk::vec3ui32 position){
    edk::uint8 ret=0u;
    if(position.x<this->getWidth()
            && position.y<this->getHeight()
            && position.z<this->getLength()
            && (this->getChannels() == 3u || this->getChannels() == 4u)
            ){
        ret = this->vec[(((position.y*this->getWidth())
                          + position.x) * this->getChannels())
                + 1u
                ];
    }
    return ret;
}
edk::uint8 edk::Image3D::getPixelG(edk::uint32 x,edk::uint32 y,edk::uint32 z){
    return this->getPixelG(edk::vec3ui32(x,y,z));
}
edk::uint8 edk::Image3D::getPixelB(edk::vec3ui32 position){
    edk::uint8 ret=0u;
    if(position.x<this->getWidth()
            && position.y<this->getHeight()
            && position.z<this->getLength()
            && (this->getChannels() == 3u || this->getChannels() == 4u)
            ){
        ret = this->vec[(((position.y*this->getWidth())
                          + position.x) * this->getChannels())
                + 2u
                ];
    }
    return ret;
}
edk::uint8 edk::Image3D::getPixelB(edk::uint32 x,edk::uint32 y,edk::uint32 z){
    return this->getPixelB(edk::vec3ui32(x,y,z));
}
edk::uint8 edk::Image3D::getPixelGray(edk::vec3ui32 position){
    edk::uint8 ret=0u;
    if(position.x<this->getWidth()
            && position.y<this->getHeight()
            && position.z<this->getLength()
            && (this->getChannels() == 1u || this->getChannels() == 2u)
            ){
        ret = this->vec[(((position.y*this->getWidth())
                          + position.x) * this->getChannels())
                + 0u
                ];
    }
    return ret;
}
edk::uint8 edk::Image3D::getPixelGray(edk::uint32 x,edk::uint32 y,edk::uint32 z){
    return this->getPixelGray(edk::vec3ui32(x,y,z));
}
edk::uint8 edk::Image3D::getPixelA(edk::vec3ui32 position){
    edk::uint8 ret=0u;
    if(position.x<this->getWidth()
            && position.y<this->getHeight()
            && position.z<this->getLength()
            && (this->getChannels() == 2u || this->getChannels() == 4u)
            ){
        ret = this->vec[(((position.y*this->getWidth())
                          + position.x) * this->getChannels())
                + this->getChannels()-1u
                ];
    }
    return ret;
}
edk::uint8 edk::Image3D::getPixelA(edk::uint32 x,edk::uint32 y,edk::uint32 z){
    return this->getPixelA(edk::vec3ui32(x,y,z));
}
edk::color3ui8 edk::Image3D::getPixelRGB(edk::vec3ui32 position){
    edk::color3ui8 ret;
    ret.r=0u;
    ret.g=0u;
    ret.b=0u;
    if(position.x<this->getWidth()
            && position.y<this->getHeight()
            && position.z<this->getLength()
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
edk::color3ui8 edk::Image3D::getPixelRGB(edk::uint32 x,edk::uint32 y,edk::uint32 z){
    return this->getPixelRGB(edk::vec3ui32(x,y,z));
}
edk::color4ui8 edk::Image3D::getPixelRGBA(edk::vec3ui32 position){
    edk::color4ui8 ret;
    ret.r=0u;
    ret.g=0u;
    ret.b=0u;
    ret.a=0u;
    if(position.x<this->getWidth()
            && position.y<this->getHeight()
            && position.z<this->getLength()
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
edk::color4ui8 edk::Image3D::getPixelRGBA(edk::uint32 x,edk::uint32 y,edk::uint32 z){
    return this->getPixelRGBA(edk::vec3ui32(x,y,z));
}
//return the colors vector with all the palette codes
edk::uint8* edk::Image3D::getColors(){
    //test if open the image
    if(this->haveColors()){
        //then return the pointer
        return this->colors;
    }
    //else return false
    return NULL;
}

//convert the image pixels
bool edk::Image3D::calculateAlpha(edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB){
    if(this->haveImage() && this->getChannels()==4u){
        return edk::Image3D::rgbaToAlpha(this->getPixels(),this->getSize()
                                         ,compareR,compareG,compareB
                                         );
    }
    return false;
}
bool edk::Image3D::calculateAlpha(edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB,edk::uint8 min,edk::uint8 max){
    if(this->haveImage() && this->getChannels()==4u){
        return edk::Image3D::rgbaToAlpha(this->getPixels(),this->getSize()
                                         ,compareR,compareG,compareB
                                         ,min,max
                                         );
    }
    return false;
}
bool edk::Image3D::calculateAlpha(edk::color3ui8 compareRGB){
    if(this->haveImage() && this->getChannels()==4u){
        return edk::Image3D::rgbaToAlpha(this->getPixels(),this->getSize()
                                         ,compareRGB
                                         );
    }
    return false;
}
bool edk::Image3D::calculateAlpha(edk::color3ui8 compareRGB,edk::uint8 min,edk::uint8 max){
    if(this->haveImage() && this->getChannels()==4u){
        return edk::Image3D::rgbaToAlpha(this->getPixels(),this->getSize()
                                         ,compareRGB,min,max
                                         );
    }
    return false;
}

void edk::Image3D::deleteImage()
{
    //test if have an image
    if(this->haveImage()){
        //
        free(this->vec);
    }
    this->vec=NULL;
    //test if have a palette
    if(this->havePalette()){
        //
        free(this->palette);
    }
    this->palette=NULL;
    this->paletteSize=0u;
    this->bytesPerColors=0u;
    //clean the channels
    this->channelsValue=0u;
    //clean the size
    this->size = edk::size3ui32(0u,0u,0u);

    //delete the imageNames
    this->deleteName();
    this->deleteFileName();
}

void edk::Image3D::deleteName()
{
    //
    if(this->haveName()){
        //
        free(this->imageName);
    }
    this->imageName=NULL;
}

//process the flip image in Y
bool edk::Image3D::flipImageY(){
    return edk::Image3D::flipY(this->vec,this->size.width,this->size.height,this->size.length,this->channelsValue,this->bytesPerChannel);
}

//Compare with other image
edk::uint64 edk::Image3D::compareToUint64(edk::Image3D* compare){
    edk::float64 ret = 0xFFFFFFFFFFFFFFFF;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->length() == compare->length()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image3D::cmpToUint64(this->getPixels(),
                                             this->width(),
                                             this->height(),
                                             this->length(),
                                             compare->getPixels(),
                                             this->channels(),
                                             this->getBytesPerChannel()
                                             );
        }
    }
    return ret;
}
edk::float64 edk::Image3D::compareToFloat64(edk::Image3D* compare){
    edk::float64 ret = -1.f;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->length() == compare->length()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image3D::cmpToFloat64(this->getPixels(),
                                              this->width(),
                                              this->height(),
                                              this->length(),
                                              compare->getPixels(),
                                              this->channels(),
                                              this->getBytesPerChannel()
                                              );
        }
    }
    return ret;
}
edk::float64 edk::Image3D::compareLeftToFloat64(edk::Image3D* compare,edk::uint32 length){
    edk::float64 ret = -1.f;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->length() == compare->length()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image3D::cmpLeftToFloat64(this->getPixels(),
                                                  this->width(),
                                                  this->height(),
                                                  length,
                                                  compare->getPixels(),
                                                  this->channels(),
                                                  this->getBytesPerChannel()
                                                  );
        }
    }
    return ret;
}
edk::float64 edk::Image3D::compareRightToFloat64(edk::Image3D* compare,edk::uint32 length){
    edk::float64 ret = -1.f;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->length() == compare->length()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image3D::cmpRightToFloat64(this->getPixels(),
                                                   this->width(),
                                                   this->height(),
                                                   length,
                                                   compare->getPixels(),
                                                   this->channels(),
                                                   this->getBytesPerChannel()
                                                   );
        }
    }
    return ret;
}
edk::float64 edk::Image3D::compareUpToFloat64(edk::Image3D* compare,edk::uint32 length){
    edk::float64 ret = -1.f;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->length() == compare->length()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image3D::cmpUpToFloat64(this->getPixels(),
                                                this->width(),
                                                this->height(),
                                                length,
                                                compare->getPixels(),
                                                this->channels(),
                                                this->getBytesPerChannel()
                                                );
        }
    }
    return ret;
}
edk::float64 edk::Image3D::compareDownToFloat64(edk::Image3D* compare,edk::uint32 length){
    edk::float64 ret = -1.f;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->length() == compare->length()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image3D::cmpDownToFloat64(this->getPixels(),
                                                  this->width(),
                                                  this->height(),
                                                  length,
                                                  compare->getPixels(),
                                                  this->channels(),
                                                  this->getBytesPerChannel()
                                                  );
        }
    }
    return ret;
}
//compare dockable with other image
edk::float64 edk::Image3D::compareDockableLeftToFloat64(edk::Image3D* compare,edk::uint32 length){
    edk::float64 ret = -1.f;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->length() == compare->length()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image3D::cmpDkbleLeftToFloat64(this->getPixels(),
                                                       this->width(),
                                                       this->height(),
                                                       length,
                                                       compare->getPixels(),
                                                       this->channels(),
                                                       this->getBytesPerChannel()
                                                       );
        }
    }
    return ret;
}
edk::float64 edk::Image3D::compareDockableRightToFloat64(edk::Image3D* compare,edk::uint32 length){
    edk::float64 ret = -1.f;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->length() == compare->length()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image3D::cmpDkbleRightToFloat64(this->getPixels(),
                                                        this->width(),
                                                        this->height(),
                                                        length,
                                                        compare->getPixels(),
                                                        this->channels(),
                                                        this->getBytesPerChannel()
                                                        );
        }
    }
    return ret;
}
edk::float64 edk::Image3D::compareDockableUpToFloat64(edk::Image3D* compare,edk::uint32 length){
    edk::float64 ret = -1.f;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->length() == compare->length()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image3D::cmpDkbleUpToFloat64(this->getPixels(),
                                                     this->width(),
                                                     this->height(),
                                                     length,
                                                     compare->getPixels(),
                                                     this->channels(),
                                                     this->getBytesPerChannel()
                                                     );
        }
    }
    return ret;
}
edk::float64 edk::Image3D::compareDockableDownToFloat64(edk::Image3D* compare,edk::uint32 length){
    edk::float64 ret = -1.f;
    //comapre if the two are equal
    if(compare){
        if(this->width() == compare->width()
                && this->height() == compare->height()
                && this->length() == compare->length()
                && this->channels() == compare->channels()
                && this->getPixels()
                && compare->getPixels()
                ){
            return edk::Image3D::cmpDkbleDownToFloat64(this->getPixels(),
                                                       this->width(),
                                                       this->height(),
                                                       length,
                                                       compare->getPixels(),
                                                       this->channels(),
                                                       this->getBytesPerChannel()
                                                       );
        }
    }
    return ret;
}

//Convertions
//RGB to HSV
edk::color3f32 edk::Image3D::rgbTohsv(edk::uint8 /*r*/,edk::uint8 /*g*/,edk::uint8 /*b*/){
    return edk::color3f32();
    //return edk::codecs::CodecImage::rgbTohsv(r,g,b);
}
edk::color3f32 edk::Image3D::rgbTohsv(edk::color3ui8 /*rgb*/){
    return edk::color3f32();
    //return edk::codecs::CodecImage::rgbTohsv(rgb.r,rgb.g,rgb.b);
}
edk::color3f32 edk::Image3D::rgbTohsv(edk::color4ui8 /*rgba*/){
    return edk::color3f32();
    //return edk::codecs::CodecImage::rgbTohsv(rgba.r,rgba.g,rgba.b);
}
edk::uint8 edk::Image3D::rgbToV(edk::uint8 /*r*/,edk::uint8 /*g*/,edk::uint8 /*b*/){
    return 0u;
    //return edk::codecs::CodecImage::rgbToV(r,g,b);
}
edk::uint8 edk::Image3D::rgbToV(edk::color3ui8 /*rgb*/){
    return 0u;
    //return edk::codecs::CodecImage::rgbToV(rgb.r,rgb.g,rgb.b);
}
edk::uint8 edk::Image3D::rgbaToV(edk::color4ui8 /*rgba*/){
    return 0u;
    //return edk::codecs::CodecImage::rgbToV(rgba.r,rgba.g,rgba.b);
}
//RGB to A
edk::uint8 edk::Image3D::rgbToA(edk::uint8 /*r*/,edk::uint8 /*g*/,edk::uint8 /*b*/
                                ,edk::uint8 /*compareR*/,edk::uint8 /*compareG*/,edk::uint8 /*compareB*/
                                ){
    return 0u;
    //return edk::codecs::CodecImage::rgbToA(r,g,b,compareR,compareG,compareB);
}
edk::uint8 edk::Image3D::rgbToA(edk::uint8 /*r*/,edk::uint8 /*g*/,edk::uint8 /*b*/
                                ,edk::uint8 /*compareR*/,edk::uint8 /*compareG*/,edk::uint8 /*compareB*/
                                ,edk::uint8 /*min*/,edk::uint8 /*max*/
                                ){
    return 0u;
    //return edk::codecs::CodecImage::rgbToA(r,g,b,compareR,compareG,compareB,min,max);
}
edk::uint8 edk::Image3D::rgbToA(edk::color3ui8 /*rgb*/,edk::color3ui8 /*compareRGB*/){
    return 0u;
    //return edk::codecs::CodecImage::rgbToA(rgb,compareRGB);
}
edk::uint8 edk::Image3D::rgbToA(edk::color3ui8 /*rgb*/,edk::color3ui8 /*compareRGB*/,edk::uint8 /*min*/,edk::uint8 /*max*/){
    return 0u;
    //return edk::codecs::CodecImage::rgbToA(rgb,compareRGB,min,max);
}
//RGBA to A
edk::uint8 edk::Image3D::rgbaToA(edk::color4ui8 /*rgba*/,edk::color3ui8 /*compareRGB*/){
    return 0u;
    //return edk::codecs::CodecImage::rgbaToA(rgba,compareRGB);
}
edk::uint8 edk::Image3D::rgbaToA(edk::color4ui8 /*rgba*/,edk::color3ui8 /*compareRGB*/,edk::uint8 /*min*/,edk::uint8 /*max*/){
    return 0u;
    //return edk::codecs::CodecImage::rgbaToA(rgba,compareRGB,min,max);
}
//vector
bool edk::Image3D::rgbToV(edk::uint8* /*vector*/,edk::size3ui32 /*size*/,edk::uint8* /*dest*/){
    return false;
    //return edk::codecs::CodecImage::rgbToV(vector,size,dest);
}
edk::uint8* edk::Image3D::rgbToV(edk::uint8* /*vector*/,edk::size3ui32 /*size*/){
    return NULL;
}
bool edk::Image3D::rgbToV(edk::uint8* /*vector*/,edk::uint32 /*width*/,edk::uint32 /*height*/,edk::uint32 /*length*/,edk::uint8* /*dest*/){
    return false;
}
edk::uint8* edk::Image3D::rgbToV(edk::uint8* /*vector*/,edk::uint32 /*width*/,edk::uint32 /*height*/,edk::uint32 /*length*/){
    return NULL;
}
bool edk::Image3D::rgbaToV(edk::uint8* /*vector*/,edk::size3ui32 /*size*/,edk::uint8* /*dest*/){
    return false;
}
edk::uint8* edk::Image3D::rgbaToV(edk::uint8* /*vector*/,edk::size3ui32 /*size*/){
    return NULL;
}
bool edk::Image3D::rgbaToV(edk::uint8* /*vector*/,edk::uint32 /*width*/,edk::uint32 /*height*/,edk::uint32 /*length*/,edk::uint8* /*dest*/){
    return false;
}
edk::uint8* edk::Image3D::rgbaToV(edk::uint8* /*vector*/,edk::uint32 /*width*/,edk::uint32 /*height*/,edk::uint32 /*length*/){
    return NULL;
}
//RGB to Alpha
bool edk::Image3D::rgbaToAlpha(edk::uint8* /*vector*/,edk::size3ui32 /*size*/
                               ,edk::uint8 /*compareR*/,edk::uint8 /*compareG*/,edk::uint8 /*compareB*/
                               ){
    return false;
}
bool edk::Image3D::rgbaToAlpha(edk::uint8* /*vector*/,edk::size3ui32 /*size*/
                               ,edk::uint8 /*compareR*/,edk::uint8 /*compareG*/,edk::uint8 /*compareB*/
                               ,edk::uint8 /*min*/,edk::uint8 /*max*/
                               ){
    return false;
}
bool edk::Image3D::rgbaToAlpha(edk::uint8* /*vector*/,edk::size3ui32 /*size*/
                               ,edk::color3ui8 /*compareRGB*/
                               ){
    return false;
}
bool edk::Image3D::rgbaToAlpha(edk::uint8* /*vector*/,edk::size3ui32 /*size*/
                               ,edk::color3ui8 /*compareRGB*/
                               ,edk::uint8 /*min*/,edk::uint8 /*max*/
                               ){
    return false;
}
bool edk::Image3D::rgbaToAlpha(edk::uint8* /*vector*/,edk::uint32 /*width*/,edk::uint32 /*height*/,edk::uint32 /*length*/
                               ,edk::uint8 /*compareR*/,edk::uint8 /*compareG*/,edk::uint8 /*compareB*/
                               ){
    return false;
}
bool edk::Image3D::rgbaToAlpha(edk::uint8* /*vector*/,edk::uint32 /*width*/,edk::uint32 /*height*/,edk::uint32 /*length*/
                               ,edk::uint8 /*compareR*/,edk::uint8 /*compareG*/,edk::uint8 /*compareB*/
                               ,edk::uint8 /*min*/,edk::uint8 /*max*/
                               ){
    return false;
}
bool edk::Image3D::rgbaToAlpha(edk::uint8* /*vector*/,edk::uint32 /*width*/,edk::uint32 /*height*/,edk::uint32 /*length*/
                               ,edk::color3ui8 /*compareRGB*/
                               ){
    return false;
}
bool edk::Image3D::rgbaToAlpha(edk::uint8* /*vector*/,edk::uint32 /*width*/,edk::uint32 /*height*/,edk::uint32 /*length*/
                               ,edk::color3ui8 /*compareRGB*/
                               ,edk::uint8 /*min*/,edk::uint8 /*max*/
                               ){
    return false;
}
//HSV to RGB
edk::color3ui8 edk::Image3D::hsvTorgb(edk::float32 /*h*/,edk::float32 /*s*/,edk::float32 /*v*/){
    return edk::color3ui8();
}
edk::color3ui8 edk::Image3D::hsvTorgb(edk::color3f32 /*hsv*/){
    return edk::color3ui8();
}
//RGB to HSL
edk::color3f32 edk::Image3D::rgbTohsl(edk::uint8 /*r*/,edk::uint8 /*g*/,edk::uint8 /*b*/){
    return edk::color3f32();
}
edk::color3f32 edk::Image3D::rgbTohsl(edk::color3ui8 /*rgb*/){
    return edk::color3f32();
}
edk::color3f32 edk::Image3D::rgbaTohsl(edk::color4ui8 /*rgba*/){
    return edk::color3f32();
}
edk::float32 edk::Image3D::rgbToL(edk::uint8 /*r*/,edk::uint8 /*g*/,edk::uint8 /*b*/){
    return 0.f;
}
edk::float32 edk::Image3D::rgbToL(edk::color3ui8 /*rgb*/){
    return 0.f;
}
edk::float32 edk::Image3D::rgbaToL(edk::color4ui8 /*rgba*/){
    return 0.f;
}
edk::uint8 edk::Image3D::rgbToLui8(edk::uint8 /*r*/,edk::uint8 /*g*/,edk::uint8 /*b*/){
    return 0u;
}
edk::uint8 edk::Image3D::rgbToLui8(edk::color3ui8 /*rgb*/){
    return 0u;
}
edk::uint8 edk::Image3D::rgbaToLui8(edk::color4ui8 /*rgba*/){
    return 0u;
}
//vector
bool edk::Image3D::rgbToLui8(edk::uint8* /*vector*/,edk::size3ui32 /*size*/,edk::uint8* /*dest*/){
    return false;
}
edk::uint8* edk::Image3D::rgbToLui8(edk::uint8* /*vector*/,edk::size3ui32 /*size*/){
    return NULL;
}
bool edk::Image3D::rgbToLui8(edk::uint8* /*vector*/,edk::uint32 /*width*/,edk::uint32 /*height*/,edk::uint32 /*length*/,edk::uint8* /*dest*/){
    return false;
}
edk::uint8* edk::Image3D::rgbToLui8(edk::uint8* /*vector*/,edk::uint32 /*width*/,edk::uint32 /*height*/,edk::uint32 /*length*/){
    return NULL;
}
bool edk::Image3D::rgbaToLui8(edk::uint8* /*vector*/,edk::size3ui32 /*size*/,edk::uint8* /*dest*/){
    return false;
}
edk::uint8* edk::Image3D::rgbaToLui8(edk::uint8* /*vector*/,edk::size3ui32 /*size*/){
    return NULL;
}
bool edk::Image3D::rgbaToLui8(edk::uint8* /*vector*/,edk::uint32 /*width*/,edk::uint32 /*height*/,edk::uint32 /*length*/,edk::uint8* /*dest*/){
    return false;
}
edk::uint8* edk::Image3D::rgbaToLui8(edk::uint8* /*vector*/,edk::uint32 /*width*/,edk::uint32 /*height*/,edk::uint32 /*length*/){
    return NULL;
}
edk::color3ui8 edk::Image3D::hslTorgb(edk::float32 /*h*/,edk::float32 /*s*/,edk::float32 /*l*/){
    return edk::color3ui8();
}
edk::color3ui8 edk::Image3D::hslTorgb(edk::color3f32 /*hsl*/){
    return edk::color3ui8();
}
//RGB to RGBA
edk::color4ui8 edk::Image3D::rgbTorgba(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::color4ui8(r,g,b,(edk::uint8)255u);
}
edk::color4ui8 edk::Image3D::rgbTorgba(edk::color3ui8 rgb){
    return edk::Image3D::rgbTorgba(rgb.r,rgb.g,rgb.b);
}
edk::color4f32 edk::Image3D::rgbTorgba(edk::float32 r,edk::float32 g,edk::float32 b){
    return edk::color4f32(r,g,b,1.f);
}
edk::color4f32 edk::Image3D::rgbTorgba(edk::color3f32 rgb){
    return edk::Image3D::rgbTorgba(rgb.r,rgb.g,rgb.b);
}
//vector
bool edk::Image3D::rgbTorgba(edk::uint8* vector,edk::size3ui32 size,edk::uint8* dest){
    if(vector && dest && size.width && size.height && size.length){
        for(edk::uint32 z=0u;z<size.length;z++){
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
        }
        return true;
    }
    return false;
}
edk::uint8* edk::Image3D::rgbTorgba(edk::uint8* vector,edk::size3ui32 size){
    if(size.width && size.height && size.length){
        edk::uint8* ret = (edk::uint8*)malloc(sizeof(edk::uint8) * (size.width*size.height*size.length*4u));
        if(ret){
            if(edk::Image3D::rgbTorgba(vector,size,ret)){
                return ret;
            }
            free(ret);
        }
    }
    return NULL;
}
bool edk::Image3D::rgbTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length,edk::uint8* dest){
    return edk::Image3D::rgbTorgba(vector,edk::size3ui32(width,height,length),dest);
}
edk::uint8* edk::Image3D::rgbTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length){
    return edk::Image3D::rgbTorgba(vector,edk::size3ui32(width,height,length));
}
//LA to RGBA
edk::color4ui8 edk::Image3D::laTorgba(edk::uint8 l,edk::uint8 a){
    return edk::color4ui8(l,l,l,a);
}
edk::color4f32 edk::Image3D::laTorgba(edk::float32 l,edk::float32 a){
    return edk::color4f32(l,l,l,a);
}
//vector
bool edk::Image3D::laTorgba(edk::uint8* vector,edk::size3ui32 size,edk::uint8* dest){
    if(vector && dest && size.width && size.height && size.length){
        for(edk::uint32 z=0u;z<size.length;z++){
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
        }
        return true;
    }
    return false;
}
edk::uint8* edk::Image3D::laTorgba(edk::uint8* vector,edk::size3ui32 size){
    if(size.width && size.height && size.length){
        edk::uint8* ret = (edk::uint8*)malloc(sizeof(edk::uint8) * (size.width*size.height*size.length*4u));
        if(ret){
            if(edk::Image3D::laTorgba(vector,size,ret)){
                return ret;
            }
            free(ret);
        }
    }
    return NULL;
}
bool edk::Image3D::laTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length,edk::uint8* dest){
    return edk::Image3D::laTorgba(vector,edk::size3ui32(width,height,length),dest);
}
edk::uint8* edk::Image3D::laTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length){
    return edk::Image3D::laTorgba(vector,edk::size3ui32(width,height,length));
}
//L to RGBA
edk::color4ui8 edk::Image3D::lTorgba(edk::uint8 l){
    return edk::color4ui8(l,l,l,(edk::uint8)255u);
}
edk::color4f32 edk::Image3D::lTorgba(edk::float32 l){
    return edk::color4f32(l,l,l,1.f);
}
bool edk::Image3D::lTorgba(edk::uint8* vector,edk::size3ui32 size,edk::uint8* dest){
    if(vector && dest && size.width && size.height && size.length){
        for(edk::uint32 z=0u;z<size.length;z++){
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
        }
        return true;
    }
    return false;
}
edk::uint8* edk::Image3D::lTorgba(edk::uint8* vector,edk::size3ui32 size){
    if(size.width && size.height && size.length){
        edk::uint8* ret = (edk::uint8*)malloc(sizeof(edk::uint8) * (size.width*size.height*size.length*4u));
        if(ret){
            if(edk::Image3D::lTorgba(vector,size,ret)){
                return ret;
            }
            free(ret);
        }
    }
    return NULL;
}
bool edk::Image3D::lTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length,edk::uint8* dest){
    return edk::Image3D::lTorgba(vector,edk::size3ui32(width,height,length),dest);
}
edk::uint8* edk::Image3D::lTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length){
    return edk::Image3D::lTorgba(vector,edk::size3ui32(width,height,length));
}
//compare
edk::uint64 edk::Image3D::cmpToUint64(edk::uint8* vector,
                                      edk::uint32 width,
                                      edk::uint32 height,
                                      edk::uint32 length,
                                      edk::uint8* compare,
                                      edk::uint8 channels,
                                      edk::uint8 bytesPerChannel
                                      ){
    edk::uint64 ret = 0xFFFFFFFFFFFFFFFF;
    if(vector && compare && width && height && length && channels && bytesPerChannel){
        edk::uint32 size = width * height * length * channels * bytesPerChannel;
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
edk::float64 edk::Image3D::cmpToFloat64(edk::uint8* vector,
                                        edk::uint32 width,
                                        edk::uint32 height,
                                        edk::uint32 length,
                                        edk::uint8* compare,
                                        edk::uint8 channels,
                                        edk::uint8 bytesPerChannel
                                        ){
    edk::float64 ret = -1.f;
    if(vector && compare && width && height && length && channels && bytesPerChannel){
        edk::int32 cmp;
        edk::uint64 cmpLine=0u,cmpLineColor;
        edk::float64 div = 0.f;
        if(width){
            div = (edk::float64)width+0.001f;
        }
        else{
            div = (edk::float64)width;
        }
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
                    vector+=1u*bytesPerChannel;
                    compare+=1u*bytesPerChannel;
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
                    vector+=2u*bytesPerChannel;
                    compare+=2u*bytesPerChannel;
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
                    vector+=3u*bytesPerChannel;
                    compare+=3u*bytesPerChannel;
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
                    vector+=4u*bytesPerChannel;
                    compare+=4u*bytesPerChannel;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        }
        ret/=(edk::float64)height;
    }
    return ret;
}
edk::float64 edk::Image3D::cmpLeftToFloat64(edk::uint8* vector,
                                            edk::uint32 width,
                                            edk::uint32 height,
                                            edk::uint32 length,
                                            edk::uint8* compare,
                                            edk::uint8 channels,
                                            edk::uint8 bytesPerChannel
                                            ){
    edk::float64 ret = -1.f;
    if(vector && compare && width && height && channels && length && length<=width){
        edk::int32 cmp;
        edk::uint64 cmpLine=0u,cmpLineColor;
        edk::float64 div = 0.f;
        if(length){
            div = (edk::float64)length+0.001f;
        }
        else{
            div = (edk::float64)length;
        }
        edk::uint32 increment = width - length;
        ret=0.;
        switch(channels){
        case 1u:
            for(edk::uint32 y=0u;y<height;y++){
                for(edk::uint32 x=0u;x<length;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmpLine+=cmpLineColor/1;
                    //increment
                    compare+=1u*bytesPerChannel;
                    vector+=1u*bytesPerChannel;
                }
                compare+=1u* increment;
                vector+=1u* increment;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 2u:
            for(edk::uint32 y=0u;y<height;y++){
                for(edk::uint32 x=0u;x<length;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/2;
                    //increment
                    compare+=2u*bytesPerChannel;
                    vector+=2u*bytesPerChannel;
                }
                compare+=2u* increment;
                vector+=2u* increment;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 3u:
            for(edk::uint32 y=0u;y<height;y++){
                for(edk::uint32 x=0u;x<length;x++){
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
                    compare+=3u*bytesPerChannel;
                    vector+=3u*bytesPerChannel;
                }
                compare+=3u* increment;
                vector+=3u* increment;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 4u:
            for(edk::uint32 y=0u;y<height;y++){
                for(edk::uint32 x=0u;x<length;x++){
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
                    compare+=4u*bytesPerChannel;
                    vector+=4u*bytesPerChannel;
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
edk::float64 edk::Image3D::cmpRightToFloat64(edk::uint8* vector,
                                             edk::uint32 width,
                                             edk::uint32 height,
                                             edk::uint32 length,
                                             edk::uint8* compare,
                                             edk::uint8 channels,
                                             edk::uint8 bytesPerChannel
                                             ){
    edk::float64 ret = -1.f;
    if(vector
            && compare
            && width
            && height
            && channels
            && bytesPerChannel
            && length
            && length<=width
            ){
        edk::int32 cmp;
        edk::uint64 cmpLine=0u,cmpLineColor;
        edk::float64 div = 0.f;
        if(length){
            div = (edk::float64)length+0.001f;
        }
        else{
            div = (edk::float64)length;
        }
        edk::uint32 increment = width - length;
        ret=0.;
        switch(channels){
        case 1u:
            for(edk::uint32 y=0u;y<height;y++){
                compare+=1u* increment;
                vector+=1u* increment;
                for(edk::uint32 x=0u;x<length;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmpLine+=cmpLineColor/1;
                    //increment
                    compare+=1u*bytesPerChannel;
                    vector+=1u*bytesPerChannel;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 2u:
            for(edk::uint32 y=0u;y<height;y++){
                compare+=2u* increment;
                vector+=2u* increment;
                for(edk::uint32 x=0u;x<length;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/2;
                    //increment
                    compare+=2u*bytesPerChannel;
                    vector+=2u*bytesPerChannel;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 3u:
            for(edk::uint32 y=0u;y<height;y++){
                compare+=3u* increment;
                vector+=3u* increment;
                for(edk::uint32 x=0u;x<length;x++){
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
                    compare+=3u*bytesPerChannel;
                    vector+=3u*bytesPerChannel;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 4u:
            for(edk::uint32 y=0u;y<height;y++){
                compare+=4u* increment;
                vector+=4u* increment;
                for(edk::uint32 x=0u;x<length;x++){
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
                    compare+=4u*bytesPerChannel;
                    vector+=4u*bytesPerChannel;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        }
        ret/=(edk::float64)height;
    }
    return ret;
}
edk::float64 edk::Image3D::cmpUpToFloat64(edk::uint8* vector,
                                          edk::uint32 width,
                                          edk::uint32 height,
                                          edk::uint32 length,
                                          edk::uint8* compare,
                                          edk::uint8 channels,
                                          edk::uint8 bytesPerChannel
                                          ){
    edk::float64 ret = -1.f;
    if(vector
            && compare
            && width
            && height
            && channels
            && bytesPerChannel
            && length
            && length<=height){
        edk::int32 cmp;
        edk::uint64 cmpLine=0u,cmpLineColor;
        edk::float64 div = 0.f;
        if(width){
            div = (edk::float64)width+0.001f;
        }
        else{
            div = (edk::float64)width;
        }
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
                    compare+=1u*bytesPerChannel;
                    vector+=1u*bytesPerChannel;
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
                    compare+=2u*bytesPerChannel;
                    vector+=2u*bytesPerChannel;
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
                    compare+=3u*bytesPerChannel;
                    vector+=3u*bytesPerChannel;
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
                    compare+=4u*bytesPerChannel;
                    vector+=4u*bytesPerChannel;
                }
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        }
        ret/=(edk::float64)height;
    }
    return ret;
}
edk::float64 edk::Image3D::cmpDownToFloat64(edk::uint8* vector,
                                            edk::uint32 width,
                                            edk::uint32 height,
                                            edk::uint32 length,
                                            edk::uint8* compare,
                                            edk::uint8 channels,
                                            edk::uint8 bytesPerChannel
                                            ){
    edk::float64 ret = -1.f;
    if(vector
            && compare
            && width
            && height
            && channels
            && bytesPerChannel
            && length
            && length<=height
            ){
        edk::int32 cmp;
        edk::uint64 cmpLine=0u,cmpLineColor;
        edk::float64 div = 0.f;
        if(width){
            div = (edk::float64)width+0.001f;
        }
        else{
            div = (edk::float64)width;
        }
        edk::uint32 increment = height - length;
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
                    compare+=1u*bytesPerChannel;
                    vector+=1u*bytesPerChannel;
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
                    compare+=2u*bytesPerChannel;
                    vector+=2u*bytesPerChannel;
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
                    compare+=3u*bytesPerChannel;
                    vector+=3u*bytesPerChannel;
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
                    compare+=4u*bytesPerChannel;
                    vector+=4u*bytesPerChannel;
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
edk::float64 edk::Image3D::cmpDkbleLeftToFloat64(edk::uint8* vector,
                                                 edk::uint32 width,
                                                 edk::uint32 height,
                                                 edk::uint32 length,
                                                 edk::uint8* compare,
                                                 edk::uint8 channels,
                                                 edk::uint8 bytesPerChannel
                                                 ){
    edk::float64 ret = -1.f;
    if(vector
            && compare
            && width
            && height
            && channels
            && bytesPerChannel
            && length
            && length<=width
            ){
        edk::int32 cmp;
        edk::uint64 cmpLine=0u,cmpLineColor;
        edk::float64 div = 0.f;
        if(length){
            div = (edk::float64)length+0.001f;
        }
        else{
            div = (edk::float64)length;
        }
        edk::uint32 increment = width - length;
        ret=0.;
        switch(channels){
        case 1u:
            for(edk::uint32 y=0u;y<height;y++){
                //increment until the compare line in Y
                compare+=1u * increment;
                vector+=1u* length;
                for(edk::uint32 x=0u;x<length;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmpLine+=cmpLineColor/1;
                    //increment
                    compare+=1u*bytesPerChannel;
                    vector-=1u*bytesPerChannel;
                }
                vector+=1u* width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 2u:
            for(edk::uint32 y=0u;y<height;y++){
                //increment until the compare line in Y
                compare+=2u * increment;
                vector+=2u* length;
                for(edk::uint32 x=0u;x<length;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/2;
                    //increment
                    compare+=2u*bytesPerChannel;
                    vector-=2u*bytesPerChannel;
                }
                vector+=2u* width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 3u:
            for(edk::uint32 y=0u;y<height;y++){
                //increment until the compare line in Y
                compare+=3u * increment;
                vector+=3u* length;
                for(edk::uint32 x=0u;x<length;x++){
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
                    compare+=3u*bytesPerChannel;
                    vector-=3u*bytesPerChannel;
                }
                vector+=3u* width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 4u:
            for(edk::uint32 y=0u;y<height;y++){
                //increment until the compare line in Y
                compare+=4u * increment;
                vector+=4u* length;
                for(edk::uint32 x=0u;x<length;x++){
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
                    compare+=4u*bytesPerChannel;
                    vector-=4u*bytesPerChannel;
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
edk::float64 edk::Image3D::cmpDkbleRightToFloat64(edk::uint8* vector,
                                                  edk::uint32 width,
                                                  edk::uint32 height,
                                                  edk::uint32 length,
                                                  edk::uint8* compare,
                                                  edk::uint8 channels,
                                                  edk::uint8 bytesPerChannel
                                                  ){
    edk::float64 ret = -1.f;
    if(vector
            && compare
            && width
            && height
            && channels
            && bytesPerChannel
            && length
            && length<=width
            ){
        edk::int32 cmp;
        edk::uint64 cmpLine=0u,cmpLineColor;
        edk::float64 div = 0.f;
        if(length){
            div = (edk::float64)length+0.001f;
        }
        else{
            div = (edk::float64)length;
        }
        edk::uint32 increment = width - length;
        ret=0.;
        switch(channels){
        case 1u:
            for(edk::uint32 y=0u;y<height;y++){
                //increment until the compare line in Y
                vector+=1u * increment;
                compare+=1u* length;
                for(edk::uint32 x=0u;x<length;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmpLine+=cmpLineColor/1;
                    //increment
                    vector+=1u*bytesPerChannel;
                    compare-=1u*bytesPerChannel;
                }
                compare+=1u* width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 2u:
            for(edk::uint32 y=0u;y<height;y++){
                //increment until the compare line in Y
                vector+=2u * increment;
                compare+=2u* length;
                for(edk::uint32 x=0u;x<length;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmp = (edk::int16)compare[1u] - (edk::int16)vector[1u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor+=cmp;
                    cmpLine+=cmpLineColor/2;
                    //increment
                    vector+=2u*bytesPerChannel;
                    compare-=2u*bytesPerChannel;
                }
                compare+=2u* width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 3u:
            for(edk::uint32 y=0u;y<height;y++){
                //increment until the compare line in Y
                vector+=3u * increment;
                compare+=3u* length;
                for(edk::uint32 x=0u;x<length;x++){
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
                    vector+=3u*bytesPerChannel;
                    compare-=3u*bytesPerChannel;
                }
                compare+=3u* width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 4u:
            for(edk::uint32 y=0u;y<height;y++){
                //increment until the compare line in Y
                vector+=4u * increment;
                compare+=4u* length;
                for(edk::uint32 x=0u;x<length;x++){
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
                    vector+=4u*bytesPerChannel;
                    compare-=4u*bytesPerChannel;
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
edk::float64 edk::Image3D::cmpDkbleUpToFloat64(edk::uint8* vector,
                                               edk::uint32 width,
                                               edk::uint32 height,
                                               edk::uint32 length,
                                               edk::uint8* compare,
                                               edk::uint8 channels,
                                               edk::uint8 bytesPerChannel
                                               ){
    edk::float64 ret = -1.f;
    if(vector
            && compare
            && width
            && height
            && channels
            && length
            && length<=height
            ){
        edk::int32 cmp;
        edk::uint64 cmpLine=0u,cmpLineColor;
        edk::float64 div = 0.f;
        if(width){
            div = (edk::float64)width+0.001f;
        }
        else{
            div = (edk::float64)width;
        }
        edk::uint32 increment = height - length;
        ret=0.;
        switch(channels){
        case 1u:
            compare+=1u * increment*width;
            vector+=1u * length*width;
            for(edk::uint32 y=0u;y<height;y++){
                vector-=1u * width;
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmpLine+=cmpLineColor/1;
                    //increment
                    compare+=1u*bytesPerChannel;
                    vector+=1u*bytesPerChannel;
                }
                vector-=1u * width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 2u:
            compare+=2u * increment*width;
            vector+=2u * length*width;
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
                    compare+=2u*bytesPerChannel;
                    vector+=2u*bytesPerChannel;
                }
                vector-=2u * width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 3u:
            compare+=3u * increment*width;
            vector+=3u * length*width;
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
                    compare+=3u*bytesPerChannel;
                    vector+=3u*bytesPerChannel;
                }
                vector-=3u * width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 4u:
            compare+=4u * increment*width;
            vector+=4u * length*width;
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
                    compare+=4u*bytesPerChannel;
                    vector+=4u*bytesPerChannel;
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
edk::float64 edk::Image3D::cmpDkbleDownToFloat64(edk::uint8* vector,
                                                 edk::uint32 width,
                                                 edk::uint32 height,
                                                 edk::uint32 length,
                                                 edk::uint8* compare,
                                                 edk::uint8 channels,
                                                 edk::uint8 bytesPerChannel
                                                 ){
    edk::float64 ret = -1.f;
    if(vector
            && compare
            && width
            && height
            && channels
            && length
            && length<=height
            ){
        edk::int32 cmp;
        edk::uint64 cmpLine=0u,cmpLineColor;
        edk::float64 div = 0.f;
        if(width){
            div = (edk::float64)width+0.001f;
        }
        else{
            div = (edk::float64)width;
        }
        edk::uint32 increment = height - length;
        ret=0.;
        switch(channels){
        case 1u:
            vector+=1u * increment*width;
            compare+=1u * length*width;
            for(edk::uint32 y=0u;y<height;y++){
                compare-=1u * width;
                for(edk::uint32 x=0u;x<width;x++){
                    cmp = (edk::int16)compare[0u] - (edk::int16)vector[0u];
                    if(cmp<0){cmp*=-1;}
                    cmpLineColor=cmp;
                    cmpLine+=cmpLineColor/1;
                    //increment
                    vector+=1u*bytesPerChannel;
                    compare+=1u*bytesPerChannel;
                }
                compare-=1u * width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 2u:
            vector+=2u * increment*width;
            compare+=2u * length*width;
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
                    vector+=2u*bytesPerChannel;
                    compare+=2u*bytesPerChannel;
                }
                compare-=2u * width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 3u:
            vector+=3u * increment*width;
            compare+=3u * length*width;
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
                    vector+=3u*bytesPerChannel;
                    compare+=3u*bytesPerChannel;
                }
                compare-=3u * width;
                ret+=(edk::float64)cmpLine/div;
            }
            break;
        case 4u:
            vector+=4u * increment*width;
            compare+=4u * length*width;
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
                    vector+=4u*bytesPerChannel;
                    compare+=4u*bytesPerChannel;
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
bool edk::Image3D::flipY(edk::uint8* vector,
                         edk::uint32 width,
                         edk::uint32 height,
                         edk::uint32 length,
                         edk::uint32 channels,
                         edk::uint8 bytesPerChannel
                         ){
    if(vector
            && width
            && height
            && length
            && channels
            && bytesPerChannel
            ){
        //get the line size
        edk::uint32 size = width * channels * bytesPerChannel;
        //alloc a buffer to save the lines
        edk::uint8* line = (edk::uint8*)malloc(sizeof(edk::uint8) * (size));
        if(line){
            //set the pointers
            edk::uint8 *start = vector,*end=vector + (size * height) - size;
            //go trow the lines copying
            while (start<end){
                //save the end
                memcpy(line,end,size);
                //copy the start to the end
                memcpy(end,start,size);
                //copy the line to the start
                memcpy(start,line,size);

                //increment start and decrment the end to meet in the middle
                start+=size;
                end-=size;
            }
            free(line);

            return true;
        }
    }
    return false;
}

bool edk::Image3D::imageClone(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length,edk::uint32 channels,edk::uint32 bytesPerChannes,
                              edk::uint8* dest,edk::uint32 dWidth,edk::uint32 dHeight,edk::uint32 dLength,edk::uint32 dChannels,edk::uint32 dBytesPerChannes,
                              edk::uint32 positionX,edk::uint32 positionY
                              ){
    //test the vectors
    if(vector && width && height && length && channels && bytesPerChannes
            && dest && dWidth && dHeight && dLength && dChannels && dBytesPerChannes
            && bytesPerChannes == dBytesPerChannes
            ){
        //test if can position the image inside the dest
        if(positionX <= dWidth - width && positionY <= dHeight - height){
            //then copy the image
            dest+=positionY*dWidth * dChannels * dBytesPerChannes;
            for(edk::uint32 y = 0u;y<height;y++){
                dest+=positionX * dChannels * dBytesPerChannes;
                //copy the channels
                if(channels==1u){
                    if(dChannels==1u){
                        //1 1
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];
                            //increment the vectors
                            dest+=dChannels*dBytesPerChannes;
                            vector+=channels*bytesPerChannes;
                        }
                    }
                    else if(dChannels==2u){
                        //1 2
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];
                            dest[1u] = 255u;
                            //increment the vectors
                            dest+=dChannels*dBytesPerChannes;
                            vector+=channels*bytesPerChannes;
                        }
                    }
                    else if(dChannels==3u){
                        //1 3
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];
                            dest[2u] = vector[0u];
                            dest[3u] = vector[0u];
                            //increment the vectors
                            dest+=dChannels*dBytesPerChannes;
                            vector+=channels*bytesPerChannes;
                        }
                    }
                    else if(dChannels==4u){
                        //1 4 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];
                            dest[2u] = vector[0u];
                            dest[3u] = vector[0u];
                            dest[4u] = 255u;
                            //increment the vectors
                            dest+=dChannels*dBytesPerChannes;
                            vector+=channels*bytesPerChannes;
                        }
                    }
                }
                else if(channels==2u){
                    if(dChannels==1u){
                        //2 1 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];
                            //increment the vectors
                            dest+=dChannels*dBytesPerChannes;
                            vector+=channels*bytesPerChannes;
                        }
                    }
                    else if(dChannels==2u){
                        //2 2 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];
                            dest[1u] = vector[1u];
                            //increment the vectors
                            dest+=dChannels*dBytesPerChannes;
                            vector+=channels*bytesPerChannes;
                        }
                    }
                    else if(dChannels==3u){
                        //2 3 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];
                            dest[1u] = vector[0u];
                            dest[2u] = vector[0u];
                            //increment the vectors
                            dest+=dChannels*dBytesPerChannes;
                            vector+=channels*bytesPerChannes;
                        }
                    }
                    else if(dChannels==4u){
                        //2 4 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];
                            dest[1u] = vector[0u];
                            dest[2u] = vector[0u];
                            dest[4u] = vector[1u];
                            //increment the vectors
                            dest+=dChannels*dBytesPerChannes;
                            vector+=channels*bytesPerChannes;
                        }
                    }
                }
                else if(channels==3u){
                    if(dChannels==1u){
                        //3 1
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = edk::Image3D::rgbToL(vector[0u],vector[1u],vector[2u]);
                            //increment the vectors
                            dest+=dChannels*dBytesPerChannes;
                            vector+=channels*bytesPerChannes;
                        }
                    }
                    else if(dChannels==2u){
                        //3 2 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = edk::Image3D::rgbToL(vector[0u],vector[1u],vector[2u]);
                            dest[1u] = 255;
                            //increment the vectors
                            dest+=dChannels*dBytesPerChannes;
                            vector+=channels*bytesPerChannes;
                        }
                    }
                    else if(dChannels==3u){
                        //3 3
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];
                            dest[1u] = vector[1u];
                            dest[2u] = vector[2u];
                            //increment the vectors
                            dest+=dChannels*dBytesPerChannes;
                            vector+=channels*bytesPerChannes;
                        }
                    }
                    else if(dChannels==4u){
                        //3 4 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];
                            dest[1u] = vector[1u];
                            dest[2u] = vector[2u];
                            dest[1u] = 255;
                            //increment the vectors
                            dest+=dChannels*dBytesPerChannes;
                            vector+=channels*bytesPerChannes;
                        }
                    }
                }
                else if(channels==4u){
                    if(dChannels==1u){
                        //4 1
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = edk::Image3D::rgbToL(vector[0u],vector[1u],vector[2u]);
                            //increment the vectors
                            dest+=dChannels*dBytesPerChannes;
                            vector+=channels*bytesPerChannes;
                        }
                    }
                    else if(dChannels==2u){
                        //4 2 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = edk::Image3D::rgbToL(vector[0u],vector[1u],vector[2u]);
                            dest[1u] = vector[1u];
                            //increment the vectors
                            dest+=dChannels*dBytesPerChannes;
                            vector+=channels*bytesPerChannes;
                        }
                    }
                    else if(dChannels==3u){
                        //4 3
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = edk::Image3D::rgbToL(vector[0u],vector[1u],vector[2u]);
                            //increment the vectors
                            dest+=dChannels*dBytesPerChannes;
                            vector+=channels*bytesPerChannes;
                        }
                    }
                    else if(dChannels==4u){
                        //4 4 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];
                            dest[1u] = vector[1u];
                            dest[2u] = vector[2u];
                            dest[3u] = vector[3u];
                            //increment the vectors
                            dest+=dChannels*dBytesPerChannes;
                            vector+=channels*bytesPerChannes;
                        }
                    }
                }
                dest+=(dWidth - width - positionX) * dChannels * dBytesPerChannes;
            }
            //then return true
            return true;
        }
    }
    return false;
}

bool edk::Image3D::cloneFrom(edk::Image3D* image){
    if(image){
        //test if the image exist
        if(image->vec && image->channelsValue && image->size.width && image->size.height && image->size.length && image->imageName){
            //test if the characteristics are equal
            if(!(this->vec
                 && image->channelsValue == this->channelsValue
                 && image->bytesPerChannel == this->bytesPerChannel
                 && image->size == this->size
                 )){
                //else delete the last image
                this->deleteImage();
                //create a new vec with the vecSize
                if(!this->newImage(image->name(),image->size.width,image->size.height,image->size.length,image->channelsValue,image->bytesPerChannel)){
                    //return false because it can't create a new image
                    return false;
                }
            }
            else{
                //set the image name
                if(!this->setName(image->name())){
                    //if it cant set. Delete the last image and return false
                    this->deleteImage();
                    return false;
                }
            }
            //test if create the image
            if(this->vec
                    && this->size.width
                    && this->size.height
                    && this->size.length
                    && this->channelsValue
                    && this->bytesPerChannel
                    ){
                //clean the image setting all zeros
                memcpy(this->vec,image->vec,this->size.width * this->size.height * this->size.length * this->channelsValue * this->bytesPerChannel);
                return true;
            }
        }
    }
    //if don't have an image delete the last image
    this->deleteImage();
    return false;
}
bool edk::Image3D::newFrom(edk::Image3D* image){
    if(image){
        //test if the image exist
        if(image->vec
                && image->channelsValue
                && image->bytesPerChannel
                && image->size.width
                && image->size.height
                && image->size.length
                && image->imageName
                ){
            //test if the characteristics are equal
            if(!(this->vec
                 && image->channelsValue == this->channelsValue
                 && image->bytesPerChannel == this->bytesPerChannel
                 && image->size == this->size
                 )){
                //else delete the last image
                this->deleteImage();
                //create a new vec with the vecSize
                if(!this->newImage(image->name(),image->size.width,image->size.height,image->size.length,image->channelsValue,image->bytesPerChannel)){
                    //return false because it can't create a new image
                    return false;
                }
            }
            else{
                //set the image name
                if(!this->setName(image->name())){
                    //if it cant set. Delete the last image and return false
                    this->deleteImage();
                    return false;
                }
            }
            //test if create the image
            if(this->vec && this->size.width && this->size.height && this->size.length && this->channelsValue && this->bytesPerChannel){
                //clean the image setting all zeros
                memset(this->vec,0u,this->size.width * this->size.height * this->size.length * this->channelsValue * this->bytesPerChannel);
                return true;
            }
        }
    }
    //if don't have an image delete the last image
    this->deleteImage();
    return false;
}

//copy one image into nother image
bool edk::Image3D::copyImageToImage(edk::uint8* copy,
                                    edk::size3ui32 sizeCopy,
                                    edk::uint8* dest,
                                    edk::size3ui32 sizeDest,
                                    edk::vec3ui32 position,
                                    edk::uint32 channels,
                                    edk::uint8 bytesPerChannel
                                    ){
    if(copy && dest && channels && bytesPerChannel
            && sizeCopy.height && sizeCopy.width && sizeCopy.length
            && sizeDest.height && sizeDest.width && sizeDest.length
            //
            && sizeCopy.width<=(sizeDest.width-position.x)
            && sizeCopy.height<=(sizeDest.height-position.y)
            && sizeCopy.length<=(sizeDest.length-position.z)
            ){
        //can copy the image
        for(edk::uint32 y=0u;y<position.y;y++){
            dest+=sizeDest.width * channels * bytesPerChannel;
        }
        for(edk::uint32 y=0u;y<sizeCopy.height;y++){
            dest+=position.x*channels*bytesPerChannel;
            edkMemCpy(dest,copy,sizeCopy.width*channels*bytesPerChannel);
            copy+=sizeCopy.width*channels*bytesPerChannel;
            dest+=(sizeDest.width-position.x)*channels*bytesPerChannel;
        }
        return true;
    }
    return false;
}
bool edk::Image3D::copyImageToImage(edk::uint8* copy,
                                    edk::uint32 copySizeW,edk::uint32 copySizeH,edk::uint32 copySizeL,
                                    edk::uint8* dest,
                                    edk::uint32 destSizeW,edk::uint32 destSizeH,edk::uint32 destSizeL,
                                    edk::uint32 posX,edk::uint32 posY,edk::uint32 posZ,
                                    edk::uint32 channels,
                                    edk::uint8 bytesPerChannel
                                    ){
    return copyImageToImage(copy,
                            edk::size3ui32(copySizeW,copySizeH,copySizeL),
                            dest,
                            edk::size3ui32(destSizeW,destSizeH,destSizeL),
                            edk::vec3ui32(posX,posY,posZ),
                            channels,
                            bytesPerChannel
                            );
}
bool edk::Image3D::copyImageToImage(edk::Image3D* copy,edk::Image3D* dest,edk::vec3ui32 position){
    if(copy && dest){
        if(copy->getChannels() == dest->getChannels()
                && copy->getBytesPerChannel() == dest->getBytesPerChannel()
                ){
            return edk::Image3D::copyImageToImage(copy->getPixels(),
                                                  copy->getSize(),
                                                  dest->getPixels(),
                                                  dest->getSize(),
                                                  position,
                                                  dest->getChannels()
                                                  ,dest->getBytesPerChannel()
                                                  );
        }
    }
    return false;
}
bool edk::Image3D::copyImageToImage(edk::Image3D* copy,edk::Image3D* dest,edk::uint32 posX,edk::uint32 posY,edk::uint32 posZ){
    return edk::Image3D::copyImageToImage(copy,dest,edk::vec3ui32(posX,posY,posZ));
}

