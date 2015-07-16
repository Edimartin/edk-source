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

bool Image2D::loadFromFile(const char *imageFileName)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000189A begin
{
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

// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000189A end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element
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
        //test the channels
        switch(this->getChannels()){
        case 1u:
        case 3u:
            //save jpeg
            if(!fileName){
                fileName = edk::String::strCat(this->getName(),(edk::char8*)".jpg");
                deleteTempName = true;
            }
            if(fileName){
                //save the encoder
                edk::codecs::EncoderJPEG encoder;
                ret = encoder.encodeToFile(this->vec,this->size.width,this->size.height,this->channels,100,fileName);
                if(deleteTempName)
                    delete[] fileName;
            }
            break;
        case 4u:
            //save jpeg
            if(!fileName){
                fileName = edk::String::strCat(this->getName(),(edk::char8*)".jpg");
                deleteTempName = true;
            }
            if(fileName){
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
    edk::color3f32 hsv;
    edk::float32 min, max, delta;

    min = r < g ? r : g;
    min = min  < b ? min  : b;

    max = r > g ? r : g;
    max = max  > b ? max  : b;

    hsv.b = max/255; // v
    //hsv.b = max*0.003921569; // v


    delta = max - min;
    if( max > 0.f ) { // NOTE: if Max is == 0, this divide would cause a crash
        hsv.g = (delta / max);// s
    } else {
        // if max is 0, then r = g = b = 0
        // s = 0, v is undefined
        hsv.g = 0.f; // s
        hsv.r = 0.f;//NAN; // h its now undefined
        return hsv;
    }

    if(delta){
        if( r >= max )                        // > is bogus, just keeps compilor happy
            hsv.r = ( g - b ) / delta;        // between yellow & magenta
        else
            if( g >= max )
                hsv.r = 2.0 + ( b - r ) / delta;  // between cyan & yellow
            else
                hsv.r = 4.0 + ( r - g ) / delta;  // between magenta & cyan

        hsv.r *= 60.0;                              // degrees

        if( hsv.r  < 0.0 )
            hsv.r  += 360.0;
    }
    else
        hsv.r=0.f;

    return hsv;
}
edk::color3f32 Image2D::rgbTohsv(edk::color3ui8 rgb){
    return edk::Image2D::rgbTohsv(rgb.r,rgb.g,rgb.b);
}
edk::color3f32 Image2D::rgbTohsv(edk::color4ui8 rgba){
    return edk::Image2D::rgbTohsv(rgba.r,rgba.g,rgba.b);
}
edk::uint8 Image2D::rgbToV(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    edk::uint8 max;

    max = r > g ? r : g;
    max = max  > b ? max  : b;

    return max; // v
}
edk::uint8 Image2D::rgbToV(edk::color3ui8 rgb){
    return edk::Image2D::rgbToV(rgb.r,rgb.g,rgb.b);
}
edk::uint8 Image2D::rgbaToV(edk::color4ui8 rgba){
    return edk::Image2D::rgbToV(rgba.r,rgba.g,rgba.b);
}
//vector
bool Image2D::rgbToV(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    if(vector && size.width && size.height && dest){
        edk::uint32 vecSize = size.width * size.height;
        for(edk::uint32 i=0u;i<vecSize;i++){
            *dest = edk::Image2D::rgbToV(vector[0u],vector[1u],vector[2u]);

            vector+=3u;
            dest++;
        }
        return true;
    }
    return false;
}
edk::uint8* Image2D::rgbToV(edk::uint8* vector,edk::size2ui32 size){
    if(vector && size.width && size.height){
        edk::uint32 vecSize = size.width * size.height;
        //create the return
        edk::uint8* ret = new edk::uint8[vecSize];
        if(ret){
            if(edk::Image2D::rgbToV(vector,size,ret)){
                return ret;
            }
            //
            delete[] ret;
        }
    }
    return NULL;
}
bool Image2D::rgbToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::Image2D::rgbToV(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* Image2D::rgbToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::Image2D::rgbToV(vector,edk::size2ui32(width,height));
}
bool Image2D::rgbaToV(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    if(vector && size.width && size.height && dest){
        edk::uint32 vecSize = size.width * size.height;
        for(edk::uint32 i=0u;i<vecSize;i++){
            *dest = edk::Image2D::rgbToV(vector[0u],vector[1u],vector[2u]);

            vector+=4u;
            dest++;
        }
        return true;
    }
    return false;
}
edk::uint8* Image2D::rgbaToV(edk::uint8* vector,edk::size2ui32 size){
    if(vector && size.width && size.height){
        edk::uint32 vecSize = size.width * size.height;
        //create the return
        edk::uint8* ret = new edk::uint8[vecSize];
        if(ret){
            if(edk::Image2D::rgbaToV(vector,size,ret)){
                return ret;
            }
            //
            delete[] ret;
        }
    }
    return NULL;
}
bool Image2D::rgbaToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::Image2D::rgbaToV(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* Image2D::rgbaToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::Image2D::rgbaToV(vector,edk::size2ui32(width,height));
}
//HSV to RGB
edk::color3ui8 Image2D::hsvTorgb(edk::float32 h,edk::float32 s,edk::float32 v){
    edk::color3ui8 rgb;

    v*=255;

    edk::float64      hh, p, q, t, ff;
    edk::int64        i;

    if(s <= 0.0) {       // < is bogus, just shuts up warnings
        rgb.r = v;
        rgb.g = v;
        rgb.b = v;
        return rgb;
    }
    hh = h;
    if(hh >= 360.0) hh = 0.0;
    hh /= 60.0;
    i = (edk::int64)hh;
    ff = hh - i;
    p = v * (1.0 -  s);
    q = v * (1.0 - (s * ff));
    t = v * (1.0 - (s * (1.0 - ff)));

    switch(i) {
    case 0:
        rgb.r = v;
        rgb.g = t;
        rgb.b = p;
        break;
    case 1:
        rgb.r = q;
        rgb.g = v;
        rgb.b = p;
        break;
    case 2:
        rgb.r = p;
        rgb.g = v;
        rgb.b = t;
        break;

    case 3:
        rgb.r = p;
        rgb.g = q;
        rgb.b = v;
        break;
    case 4:
        rgb.r = t;
        rgb.g = p;
        rgb.b = v;
        break;
    case 5:
    default:
        rgb.r = v;
        rgb.g = p;
        rgb.b = q;
        break;
    }

    return rgb;
}
edk::color3ui8 Image2D::hsvTorgb(edk::color3f32 hsv){
    return edk::Image2D::hsvTorgb(hsv.r,hsv.g,hsv.b);
}
//RGB to HSL
edk::color3f32 Image2D::rgbTohsl(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    edk::color3f32 hsl;
    edk::float32 dr = r/255.f,dg = g/255.f,db = b/255.f;
    edk::float64 min, max;

    min = dr < dg ? dr : dg;
    min = min  < db ? min  : db;

    max = dr > dg ? dr : dg;
    max = max  > db ? max  : db;

    hsl.b = (max + min) / 2.f; // l

    if(max == min){
        hsl.r = hsl.g= 0; // achromatic
    }else{
        edk::float64  delta = max - min;
        hsl.g = hsl.b > 0.5f ? delta / (2.f - max - min) : delta / (max + min);

        if(delta){
            if(max==dr){
                hsl.r = (dg - db) / delta + (dg < db ? 6.f : 0.f);
            }
            else if(max==dg)
                hsl.r = (db - dr) / delta + 2.f;
            else if(max==db)
                hsl.r = (dr - dg) / delta + 4.f;

            hsl.r/= 6.f;
            //hsl.r*=360.f;
        }
        else{
            hsl.r=0.f;
        }
    }
    return hsl;
}
edk::color3f32 Image2D::rgbTohsl(edk::color3ui8 rgb){
    return edk::Image2D::rgbTohsl(rgb.r,rgb.g,rgb.b);
}
edk::color3f32 Image2D::rgbaTohsl(edk::color4ui8 rgba){
    return edk::Image2D::rgbTohsl(rgba.r,rgba.g,rgba.b);
}
edk::float32 Image2D::rgbToL(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    //
    edk::float32 dr = r/255.f,dg = g/255.f,db = b/255.f;
    edk::float32 min, max;

    min = dr < dg ? dr : dg;
    min = min  < db ? min  : db;

    max = dr > dg ? dr : dg;
    max = max  > db ? max  : db;

    return (max + min) / 2.f; // l
}
edk::float32 Image2D::rgbToL(edk::color3ui8 rgb){
    return edk::Image2D::rgbToL(rgb.r,rgb.g,rgb.b);
}
edk::float32 Image2D::rgbaToL(edk::color4ui8 rgba){
    return edk::Image2D::rgbToL(rgba.r,rgba.g,rgba.b);
}
edk::uint8 Image2D::rgbToLui8(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return (edk::uint8)(edk::Image2D::rgbToL(r,g,b) * 255.f);
}
edk::uint8 Image2D::rgbToLui8(edk::color3ui8 rgb){
    return edk::Image2D::rgbToLui8(rgb.r,rgb.g,rgb.b);
}
edk::uint8 Image2D::rgbaToLui8(edk::color4ui8 rgba){
    return edk::Image2D::rgbToLui8(rgba.r,rgba.g,rgba.b);
}
//vector
bool Image2D::rgbToLui8(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    if(vector && size.width && size.height && dest){
        edk::uint32 vecSize = size.width * size.height;
        for(edk::uint32 i=0u;i<vecSize;i++){
            *dest = edk::Image2D::rgbToLui8(vector[0u],vector[1u],vector[2u]);

            vector+=3u;
            dest++;
        }
        return true;
    }
    return false;
}
edk::uint8* Image2D::rgbToLui8(edk::uint8* vector,edk::size2ui32 size){
    if(vector && size.width && size.height){
        edk::uint32 vecSize = size.width * size.height;
        //create the return
        edk::uint8* ret = new edk::uint8[vecSize];
        if(ret){
            if(edk::Image2D::rgbToLui8(vector,size,ret)){
                return ret;
            }
            //
            delete[] ret;
        }
        ret=NULL;
    }
    return NULL;
}
bool Image2D::rgbToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::Image2D::rgbToLui8(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* Image2D::rgbToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::Image2D::rgbToLui8(vector,edk::size2ui32(width,height));
}
bool Image2D::rgbaToLui8(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    if(vector && size.width && size.height && dest){
        edk::uint32 vecSize = size.width * size.height;
        for(edk::uint32 i=0u;i<vecSize;i++){
            *dest = edk::Image2D::rgbToLui8(vector[0u],vector[1u],vector[2u]);

            vector+=4u;
            dest++;
        }
        return true;
    }
    return false;
}
edk::uint8* Image2D::rgbaToLui8(edk::uint8* vector,edk::size2ui32 size){
    if(vector && size.width && size.height){
        edk::uint32 vecSize = size.width * size.height;
        //create the return
        edk::uint8* ret = new edk::uint8[vecSize];
        if(ret){
            if(edk::Image2D::rgbaToLui8(vector,size,ret)){
                return ret;
            }
            //
            delete[] ret;
        }
        ret=NULL;
    }
    return NULL;
}
bool Image2D::rgbaToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::Image2D::rgbaToLui8(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* Image2D::rgbaToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::Image2D::rgbaToLui8(vector,edk::size2ui32(width,height));
}
//HSL to RGB
edk::float32 EDKhue2rgb(edk::float32 p, edk::float32 q, edk::float32 t){
    if(t < 0.f) t += 1.f;
    if(t > 1.f) t -= 1.f;
    if(t < 1.f/6.f) return p + (q - p) * 6.f * t;
    if(t < 1.f/2.f) return q;
    if(t < 2.f/3.f) return p + (q - p) * (2.f/3.f - t) * 6.f;
    return p;
}
edk::color3ui8 Image2D::hslTorgb(edk::float32 h,edk::float32 s,edk::float32 l){

    edk::float32 r,g,b;


    if(s == 0.f){
        r = g = b = l; // achromatic
    }else{
        edk::float32 q = l < 0.5f ? l * (1.f + s) : l + s - l * s;
        edk::float32 p = 2.f * l - q;
        r = EDKhue2rgb(p, q, h + (1.f/3.f));
        g = EDKhue2rgb(p, q, h);
        b = EDKhue2rgb(p, q, h - (1.f/3.f));
    }
    edk::color3ui8 rgb((edk::uint8)(r*255.f),
                       (edk::uint8)(g*255.f),
                       (edk::uint8)(b*255.f)
                       );
/*
    if((r-rgb.r)>0.5f){
        rgb.r++;
    }
    if((g-rgb.g)>0.5f){
        rgb.g++;
    }
    if((b-rgb.b)>0.5f){
        rgb.b++;
    }
*/
    return rgb;
}
edk::color3ui8 Image2D::hslTorgb(edk::color3f32 hsl){
    return edk::Image2D::hslTorgb(hsl.r,hsl.g,hsl.b);
}

} /* End of namespace edk */
