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
#warning "            Inside Image2D.cpp"
#endif

edk::Image2D::Image2D(){
    //ctor
    this->imageName=NULL;
    this->imageFileName=NULL;
    this->vec = NULL;
    this->colors = NULL;
    this->channels=0u;
    this->palette=NULL;
    this->paletteSize=0u;
    this->bytesPerColors=0u;
}

edk::Image2D::Image2D(char8 *imageFileName){
    //clean all
    this->imageName=NULL;
    this->imageFileName=NULL;
    this->vec = NULL;
    this->colors = NULL;
    this->channels=0u;
    this->palette=NULL;
    this->paletteSize=0u;
    this->bytesPerColors=0u;
    //load the image
    this->loadFromFile(imageFileName);
}

edk::Image2D::Image2D(const char *imageFileName){
    //clean all
    this->imageName=NULL;
    this->imageFileName=NULL;
    this->vec = NULL;
    this->colors = NULL;
    this->channels=0u;
    this->palette=NULL;
    this->paletteSize=0u;
    this->bytesPerColors=0u;
    //load the image
    this->loadFromFile(imageFileName);
}

edk::Image2D::~Image2D(){
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
void edk::Image2D::setFileName(const edk::char8* imageFileName){
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
edk::uint8 edk::Image2D::getStreamType(edk::uint8* encoded){
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
edk::uint8 edk::Image2D::getNameType(edk::char8* name){
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
bool edk::Image2D::newImage(edk::char8 *imageName,edk::size2ui32 size,edk::uint8 channels){
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
bool edk::Image2D::newImage(edk::char8 *imageName,edk::uint32 width,edk::uint32 height,edk::uint8 channels){
    return this->newImage(imageName,edk::size2ui32(width,height),channels);
}
bool edk::Image2D::newImage(const edk::char8 *imageName,edk::size2ui32 size,edk::uint8 channels){
    return this->newImage((edk::char8 *)imageName,size,channels);
}
bool edk::Image2D::newImage(const edk::char8 *imageName,edk::uint32 width,edk::uint32 height,edk::uint8 channels){
    return this->newImage((edk::char8 *)imageName,width,height,channels);
}

//create a new image with a palette
bool edk::Image2D::newImage(edk::char8 *imageName,edk::size2ui32 size,edk::uint8 channels,edk::uint32 paletteSize){
    //delete the last image
    this->deleteImage();
    //test the new image
    if(imageName&&size.width&&size.height&&paletteSize&&channels&&channels<=4u){
        //set the name
        if(this->setName(imageName)){
            //set the size
            this->size = size;
            //clean the channels
            this->channels=channels;
            //create the palette
            this->palette=new edk::uint8[paletteSize * this->channels];
            if(this->palette){
                this->paletteSize=paletteSize;

                edk::uint32 imageSize = size.width*size.height;

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
                this->colors = new edk::uint8[imageSize * this->bytesPerColors];
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
bool edk::Image2D::newImage(edk::char8 *imageName,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 paletteSize){
    return this->newImage(imageName,edk::size2ui32(width,height),channels,paletteSize);
}
bool edk::Image2D::newImage(const edk::char8 *imageName,edk::size2ui32 size,edk::uint8 channels,edk::uint32 paletteSize){
    return this->newImage((edk::char8 *)imageName,size,channels,paletteSize);
}
bool edk::Image2D::newImage(const edk::char8 *imageName,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 paletteSize){
    return this->newImage((edk::char8 *)imageName,width,height,channels,paletteSize);
}

bool edk::Image2D::loadFromFile(char8 *imageFileName)
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

bool edk::Image2D::loadFromFile(const char *imageFileName){
    return this->loadFromFile((edk::char8*)imageFileName);
}

bool edk::Image2D::loadFromFileToRGBA(char8 *imageFileName){
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

bool edk::Image2D::loadFromFileToRGBA(const char *imageFileName){
    return this->loadFromFileToRGBA((edk::char8*)imageFileName);
}

bool edk::Image2D::loadFromMemory(uint8 *image, edk::uint32 vecSize){
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
                    this->size = edk::size2ui32(decoder.getFrameWidth(),decoder.getFrameHeight());
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
            //decode using jpegCodec
            edk::codecs::DecoderPNG decoder;
            if(decoder.decode(image,vecSize)){
                this->vec = decoder.getFrame();
                if(vec){
                    //get size
                    this->size = edk::size2ui32(decoder.getFrameWidth(),decoder.getFrameHeight());
                    //get channels
                    this->channels = decoder.getFrameChannels();
                    decoder.cleanFrame();
                    return true;
                }
            }
        }
            break;
        }
    }
    return false;
}

bool edk::Image2D::loadFromMemoryToRGBA(uint8 *image, edk::uint32 vecSize){
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
            //decode using jpegCodec
            edk::codecs::DecoderPNG decoder;
            if(decoder.decode(image,vecSize)){
                edk::uint32 imageSize = decoder.getFrameWidth()*decoder.getFrameHeight();
                if(imageSize){
                    this->vec = new edk::uint8[imageSize*4u];
                    //get channels
                    this->channels = decoder.getFrameChannels();
                    if(this->channels==1u || this->channels==2u || this->channels == 3u){
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
                            case 2:
                                for(edk::uint32 i=0u;i<imageSize;i++){
                                    rgbaTemp[0u] = frameTemp[0u];
                                    rgbaTemp[1u] = frameTemp[0u];
                                    rgbaTemp[2u] = frameTemp[0u];
                                    rgbaTemp[3u] = frameTemp[1u];
                                    rgbaTemp+=4u;
                                    frameTemp+=2u;
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
                    else if(this->channels==4u){
                        //The image aready have 4 channels
                        if(vec){
                            this->size = edk::size2ui32(decoder.getFrameWidth(),decoder.getFrameHeight());
                            //just copy the frame in to the vec
                            memcpy(this->vec,decoder.getFrame(),imageSize*4u);
                            decoder.deleteFrame();
                            this->channels=4u;
                            return true;
                        }
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
    edk::uint32 width = this->getWidth();
    edk::uint32 height = this->getHeight();
    edk::uint8 channels = this->getChannels();
    edk::uint8 bytes = this->bytesPerColors;
    edk::uint8* palette = this->palette;
    edk::uint32 paletteSize = this->paletteSize;

    if(this->haveImage() && width && height && channels && this->haveColors() && bytes && palette && paletteSize){
        //delete the last vector
        if(this->vec){
            delete[] this->vec;
        }
        //create a new vec
        this->vec = new edk::uint8[width*height*channels];
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
                break;
            case 2u:
            {
                //
                edk::uint16 colorID;
                //copy the colors into pixels
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
                break;
            case 3u:
            {
                //
                edk::uint32 colorID;
                //copy the colors into pixels
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
                break;
            case 4u:
            {
                //
                edk::uint32 colorID;
                //copy the colors into pixels
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
        bool deleteTempName=false;
        bool ret=false;

        //get the name type
        edk::uint8 nameType = getNameType(fileName);

        //test the channels
        switch(this->getChannels()){
        case 2u:
            //save jpeg
            if(!fileName){
                fileName = edk::String::strCat(this->getName(),(edk::char8*)".png");
                deleteTempName = true;
                nameType = EDK_CODEC_JPEG;
            }
            if(fileName){
                switch(nameType){
                case EDK_CODEC_NO:
                    //concatenate .png with the name
                    fileName = edk::String::strCat(fileName,(edk::char8*)".png");
                    deleteTempName = true;
                case EDK_CODEC_PNG:
                {
                    //save the encoder
                    edk::codecs::EncoderPNG encoder;
                    ret = encoder.encodeToFile(this->vec,this->size.width,this->size.height,this->channels,9,fileName);
                    if(deleteTempName)
                        delete[] fileName;
                    break;
                }
                case EDK_CODEC_JPEG:
                {
                    ret = false;
                    if(deleteTempName)
                        delete[] fileName;
                    break;
                }
                }
            }
            break;
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
                    ret = encoder.encodeToFile(this->vec,this->size.width,this->size.height,this->channels,90,fileName);
                    if(deleteTempName)
                        delete[] fileName;
                    break;
                }
                case EDK_CODEC_PNG:
                {
                    //save the encoder
                    edk::codecs::EncoderPNG encoder;
                    ret = encoder.encodeToFile(this->vec,this->size.width,this->size.height,this->channels,9,fileName);
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
                {
                    //concatenate .jpg with the name
                    fileName = edk::String::strCat(fileName,(edk::char8*)".png");
                    deleteTempName = true;
                }
                case EDK_CODEC_PNG:
                {
                    //save the encoder
                    edk::codecs::EncoderPNG encoder;
                    ret = encoder.encodeToFile(this->vec,this->size.width,this->size.height,this->channels,9,fileName);
                    if(deleteTempName)
                        delete[] fileName;
                    break;
                }
                case EDK_CODEC_JPEG:
                {
                    //create a new image and convert the frame to rgb
                    edk::uint8* temp = new edk::uint8[this->size.width * this->size.height * 3u];
                    if(temp){
                        //convert the image
                        if(edk::Image2D::imageClone(this->vec,this->size.width,this->size.height,this->channels,
                                                    temp,this->size.width,this->size.height,3u,
                                                    0u,0u
                                                    )){
                            //save the image as JPEG
                            edk::codecs::EncoderJPEG encoder;
                            ret = encoder.encodeToFile(temp,this->size.width,this->size.height,3u,90,fileName);
                        }
                        delete[] temp;
                    }
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
bool edk::Image2D::saveToFile(const char *fileName){
    return this->saveToFile((edk::char8 *)fileName);
}

bool edk::Image2D::setName(char8 *imageName)
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

bool edk::Image2D::setName(const char *imageName)
{
    return this->setName((edk::char8*) imageName);
}

//draw on the image
bool edk::Image2D::draw(edk::uint8* pixels){
    if(pixels && this->haveImage()){
        memcpy(this->vec,pixels,this->getWidth()*this->getHeight()*this->getChannels());
        return true;
    }
    return false;
}
//draw a color in the image vector
bool edk::Image2D::drawPosition(edk::vec2ui32 position,edk::uint8* color){
    if(position.x < this->getWidth() && position.y<this->getHeight() && color){
        edk::uint32 i = (position.x + (position.y*this->getHeight())) * this->channels;
        memcpy(&this->vec[i],color,this->channels);
        return true;
    }
    return false;
}
bool edk::Image2D::drawPosition(edk::vec2ui32 position,edk::uint8 g){
    edk::uint8 color[4u] = {g,1u,0u,0u};
    return this->drawPosition(position,(edk::uint8*)&color);
}
bool edk::Image2D::drawPosition(edk::vec2ui32 position,edk::uint8 g,edk::uint8 a){
    edk::uint8 color[4u] = {g,a,0u,0u};
    return this->drawPosition(position,(edk::uint8*)&color);
}
bool edk::Image2D::drawPosition(edk::vec2ui32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b){
    edk::uint8 color[4u] = {r,g,b,1u};
    return this->drawPosition(position,(edk::uint8*)&color);
}
bool edk::Image2D::drawPosition(edk::vec2ui32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
    edk::uint8 color[4u] = {r,g,b,a};
    return this->drawPosition(position,(edk::uint8*)&color);
}
bool edk::Image2D::drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint8* color){
    return this->drawPosition(edk::vec2ui32(positionX,positionY),color);
}
bool edk::Image2D::drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint8 g){
    return this->drawPosition(edk::vec2ui32(positionX,positionY),g);
}
bool edk::Image2D::drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint8 g,edk::uint8 a){
    return this->drawPosition(edk::vec2ui32(positionX,positionY),g,a);
}
bool edk::Image2D::drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return this->drawPosition(edk::vec2ui32(positionX,positionY),r,g,b);
}
bool edk::Image2D::drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
    return this->drawPosition(edk::vec2ui32(positionX,positionY),r,g,b,a);
}
//draw the colors on the palette. The user need to know the size of the palette multiply by channel size
bool edk::Image2D::drawPalette(edk::uint8* colors){
    if(colors && this->havePalette()){
        memcpy(this->colors,colors,this->getWidth()*this->getHeight()*this->getChannels());
        return true;
    }
    return false;
}
//draw a color in palette position
bool edk::Image2D::drawPalettePosition(edk::uint32 position,edk::uint8* color){
    if(position < this->paletteSize && color && this->palette){
        //set the color
        memcpy(&this->palette[position],color,this->channels);
        return true;
    }
    return false;
}
bool edk::Image2D::drawPalettePosition(edk::uint32 position,edk::uint8 g){
    edk::uint8 color[4u] = {g,1u,0u,0u};
    return this->drawPalettePosition(position,(edk::uint8*)&color);
}
bool edk::Image2D::drawPalettePosition(edk::uint32 position,edk::uint8 g,edk::uint8 a){
    edk::uint8 color[4u] = {g,a,0u,0u};
    return this->drawPalettePosition(position,(edk::uint8*)&color);
}
bool edk::Image2D::drawPalettePosition(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b){
    edk::uint8 color[4u] = {r,g,b,1u};
    return this->drawPalettePosition(position,(edk::uint8*)&color);
}
bool edk::Image2D::drawPalettePosition(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
    edk::uint8 color[4u] = {r,g,b,a};
    return this->drawPalettePosition(position,(edk::uint8*)&color);
}
//draw the colorIDs in the image using the palette positions. The user need to know the colors size which is the paletteSize multiply by bytesPerColor
bool edk::Image2D::drawColors(edk::uint8* colors){
    if(this->colors && colors && this->getWidth() && getHeight() && this->getBytesPerColor()){
        memcpy(this->colors,colors,this->getWidth()*this->getHeight()*this->getBytesPerColor());
        return true;
    }
    return false;
}
//draw a color position from the palette in colors vector.
bool edk::Image2D::drawColorsPosition(edk::vec2ui32 position,edk::uint8* colorID){
    if(position.x < this->getWidth() && position.y<this->getHeight() && colorID){
        edk::uint32 i = (position.x + (position.y*this->getHeight())) * this->bytesPerColors;
        memcpy(&this->colors[i],colorID,this->bytesPerColors);
        return true;
    }
    return false;
}
bool edk::Image2D::drawColorsPosition(edk::vec2ui32 position,edk::uint8 colorID){
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
bool edk::Image2D::drawColorsPosition(edk::vec2ui32 position,edk::uint16 colorID){
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
bool edk::Image2D::drawColorsPosition(edk::vec2ui32 position,edk::uint32 colorID){
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
    return this->size;
}

edk::uint32 edk::Image2D::getWidth(){
    return this->getSize().width;
}

edk::uint32 edk::Image2D::getHeight(){
    return this->getSize().height;
}

edk::uint32 edk::Image2D::width()
{
    return this->getSize().width;
}

edk::uint32 edk::Image2D::height()
{
    return this->getSize().height;
}
//return the channels of the image
edk::uint8 edk::Image2D::getChannels(){
    return this->channels;
}
//return the bytes per color to set the color values with the palette positions.
edk::uint8 edk::Image2D::getBytesPerColor(){
    return this->bytesPerColors;
}

edk::uint32 edk::Image2D::getPaletteSize(){
    return this->paletteSize;
}
//get the vector size
edk::uint32 edk::Image2D::getPixelsLenght(){
    return this->getWidth() * this->getHeight() * this->getChannels();
}
//get the palette size
edk::uint32 edk::Image2D::getPaletteLenght(){
    return this->getPaletteSize() * this->getChannels();
}
//get the colors lenght returh the colors vector lenght with the palette ID's
edk::uint32 edk::Image2D::getColorsLenght(){
    return this->getBytesPerColor() * this->getWidth() * this->getHeight();
}

bool edk::Image2D::haveImage()
{
    return (bool)this->vec;
}

bool edk::Image2D::haveColors(){
    return (bool)this->colors;
}

bool edk::Image2D::havePalette(){
    return (bool)this->palette;
}

bool edk::Image2D::haveName()
{
    return (bool)this->imageName;
}

bool edk::Image2D::haveFileName()
{
    return (bool)this->imageFileName;
}

edk::char8* edk::Image2D::getName()
{
    return this->imageName;
}

edk::char8* edk::Image2D::name()
{
    return this->getName();
}

edk::char8* edk::Image2D::getFileName()
{
    return this->imageFileName;
}

edk::char8* edk::Image2D::fileName()
{
    return this->getFileName();
}

//return the pixels of the image to use in videoBoard
edk::uint8* edk::Image2D::getPixels(){
    //test if open the image
    if(this->haveImage()){
        //then return the pointer
        return this->vec;
    }
    //else return false
    return NULL;
}
//return the colors vector with all the palette codes
edk::uint8* edk::Image2D::getColors(){
    //test if open the image
    if(this->haveColors()){
        //then return the pointer
        return this->colors;
    }
    //else return false
    return NULL;
}

void edk::Image2D::deleteImage()
{
    //test if have an image
    if(this->haveImage()){
        //
        delete[] this->vec;
    }
    this->vec=NULL;
    //test if have a palette
    if(this->havePalette()){
        //
        delete[] this->palette;
    }
    this->palette=NULL;
    this->paletteSize=0u;
    this->bytesPerColors=0u;
    //clean the channels
    this->channels=0u;
    //clean the size
    this->size = edk::size2ui32(0u,0u);

    //delete the imageNames
    this->deleteName();
    this->deleteFileName();
}

void edk::Image2D::deleteName()
{
    //
    if(this->haveName()){
        //
        delete[] this->imageName;
    }
    this->imageName=NULL;
}

//process the flip image in Y
bool edk::Image2D::flipImageY(){
    return edk::Image2D::flipY(this->vec,this->size.width,this->size.height,this->channels);
    /*
    //test if have the image
    if(this->vec && this->size.width && this->size.height && this->channels){
        //get the line size
        edk::uint32 size = this->size.width * this->channels;
        //alloc a buffer to save the lines
        edk::uint8* line = new edk::uint8[size];
        if(line){
            //set the pointers
            edk::uint8 *start = this->vec,*end=this->vec + (size * this->height()) - size;
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
            delete[] line;

            return true;
        }
    }
    */
}

//Convertions
//RGB to HSV
edk::color3f32 edk::Image2D::rgbTohsv(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::codecs::CodecImage::rgbTohsv(r,g,b);
}
edk::color3f32 edk::Image2D::rgbTohsv(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbTohsv(rgb.r,rgb.g,rgb.b);
}
edk::color3f32 edk::Image2D::rgbTohsv(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbTohsv(rgba.r,rgba.g,rgba.b);
}
edk::uint8 edk::Image2D::rgbToV(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::codecs::CodecImage::rgbToV(r,g,b);
}
edk::uint8 edk::Image2D::rgbToV(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbToV(rgb.r,rgb.g,rgb.b);
}
edk::uint8 edk::Image2D::rgbaToV(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbToV(rgba.r,rgba.g,rgba.b);
}
//vector
bool edk::Image2D::rgbToV(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbToV(vector,size,dest);
}
edk::uint8* edk::Image2D::rgbToV(edk::uint8* vector,edk::size2ui32 size){
    return edk::codecs::CodecImage::rgbToV(vector,size);
}
bool edk::Image2D::rgbToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbToV(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* edk::Image2D::rgbToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbToV(vector,edk::size2ui32(width,height));
}
bool edk::Image2D::rgbaToV(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbaToV(vector,size,dest);
}
edk::uint8* edk::Image2D::rgbaToV(edk::uint8* vector,edk::size2ui32 size){
    return edk::codecs::CodecImage::rgbaToV(vector,size);
}
bool edk::Image2D::rgbaToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbaToV(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* edk::Image2D::rgbaToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbaToV(vector,edk::size2ui32(width,height));
}
//HSV to RGB
edk::color3ui8 edk::Image2D::hsvTorgb(edk::float32 h,edk::float32 s,edk::float32 v){
    return edk::codecs::CodecImage::hsvTorgb(h,s,v);
}
edk::color3ui8 edk::Image2D::hsvTorgb(edk::color3f32 hsv){
    return edk::codecs::CodecImage::hsvTorgb(hsv.r,hsv.g,hsv.b);
}
//RGB to HSL
edk::color3f32 edk::Image2D::rgbTohsl(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::codecs::CodecImage::rgbTohsl(r,g,b);
}
edk::color3f32 edk::Image2D::rgbTohsl(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbTohsl(rgb.r,rgb.g,rgb.b);
}
edk::color3f32 edk::Image2D::rgbaTohsl(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbTohsl(rgba.r,rgba.g,rgba.b);
}
edk::float32 edk::Image2D::rgbToL(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::codecs::CodecImage::rgbToL(r,g,b);
}
edk::float32 edk::Image2D::rgbToL(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbToL(rgb.r,rgb.g,rgb.b);
}
edk::float32 edk::Image2D::rgbaToL(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbToL(rgba.r,rgba.g,rgba.b);
}
edk::uint8 edk::Image2D::rgbToLui8(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::codecs::CodecImage::rgbToLui8(r,g,b);
}
edk::uint8 edk::Image2D::rgbToLui8(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbToLui8(rgb.r,rgb.g,rgb.b);
}
edk::uint8 edk::Image2D::rgbaToLui8(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbToLui8(rgba.r,rgba.g,rgba.b);
}
//vector
bool edk::Image2D::rgbToLui8(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbToLui8(vector,size,dest);
}
edk::uint8* edk::Image2D::rgbToLui8(edk::uint8* vector,edk::size2ui32 size){
    return edk::codecs::CodecImage::rgbToLui8(vector,size);
}
bool edk::Image2D::rgbToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbToLui8(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* edk::Image2D::rgbToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbToLui8(vector,edk::size2ui32(width,height));
}
bool edk::Image2D::rgbaToLui8(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbaToLui8(vector,size,dest);
}
edk::uint8* edk::Image2D::rgbaToLui8(edk::uint8* vector,edk::size2ui32 size){
    return edk::codecs::CodecImage::rgbaToLui8(vector,size);
}
bool edk::Image2D::rgbaToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbaToLui8(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* edk::Image2D::rgbaToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbaToLui8(vector,edk::size2ui32(width,height));
}
edk::color3ui8 edk::Image2D::hslTorgb(edk::float32 h,edk::float32 s,edk::float32 l){
    return edk::codecs::CodecImage::hslTorgb(h,s,l);
}
edk::color3ui8 edk::Image2D::hslTorgb(edk::color3f32 hsl){
    return edk::codecs::CodecImage::hslTorgb(hsl.r,hsl.g,hsl.b);
}
//RGB to RGBA
edk::color4ui8 edk::Image2D::rgbTorgba(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::color4ui8(r,g,b,(edk::uint8)255u);
}
edk::color4ui8 edk::Image2D::rgbTorgba(edk::color3ui8 rgb){
    return edk::Image2D::rgbTorgba(rgb.r,rgb.g,rgb.b);
}
edk::color4f32 edk::Image2D::rgbTorgba(edk::float32 r,edk::float32 g,edk::float32 b){
    return edk::color4f32(r,g,b,1.f);
}
edk::color4f32 edk::Image2D::rgbTorgba(edk::color3f32 rgb){
    return edk::Image2D::rgbTorgba(rgb.r,rgb.g,rgb.b);
}
//vector
bool edk::Image2D::rgbTorgba(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
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
edk::uint8* edk::Image2D::rgbTorgba(edk::uint8* vector,edk::size2ui32 size){
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
bool edk::Image2D::rgbTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::Image2D::rgbTorgba(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* edk::Image2D::rgbTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::Image2D::rgbTorgba(vector,edk::size2ui32(width,height));
}
//LA to RGBA
edk::color4ui8 edk::Image2D::laTorgba(edk::uint8 l,edk::uint8 a){
    return edk::color4ui8(l,l,l,a);
}
edk::color4f32 edk::Image2D::laTorgba(edk::float32 l,edk::float32 a){
    return edk::color4f32(l,l,l,a);
}
//vector
bool edk::Image2D::laTorgba(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
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
edk::uint8* edk::Image2D::laTorgba(edk::uint8* vector,edk::size2ui32 size){
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
bool edk::Image2D::laTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::Image2D::laTorgba(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* edk::Image2D::laTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::Image2D::laTorgba(vector,edk::size2ui32(width,height));
}
//L to RGBA
edk::color4ui8 edk::Image2D::lTorgba(edk::uint8 l){
    return edk::color4ui8(l,l,l,(edk::uint8)255u);
}
edk::color4f32 edk::Image2D::lTorgba(edk::float32 l){
    return edk::color4f32(l,l,l,1.f);
}
bool edk::Image2D::lTorgba(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
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
edk::uint8* edk::Image2D::lTorgba(edk::uint8* vector,edk::size2ui32 size){
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
bool edk::Image2D::lTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::Image2D::lTorgba(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* edk::Image2D::lTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::Image2D::lTorgba(vector,edk::size2ui32(width,height));
}

//flip pixels
bool edk::Image2D::flipY(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 channels){
    if(vector && width && height && channels){
        //get the line size
        edk::uint32 size = width * channels;
        //alloc a buffer to save the lines
        edk::uint8* line = new edk::uint8[size];
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
            delete[] line;

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
            dest+=positionY*dWidth * dChannels;
            for(edk::uint32 y = 0u;y<height;y++){
                dest+=positionX * dChannels;
                //copy the channels
                if(channels==1u){
                    if(dChannels==1u){
                        //1 1
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];
                            //increment the vectors
                            dest+=dChannels;
                            vector+=channels;
                        }
                    }
                    else if(dChannels==2u){
                        //1 2
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];
                            dest[1u] = 255u;
                            //increment the vectors
                            dest+=dChannels;
                            vector+=channels;
                        }
                    }
                    else if(dChannels==3u){
                        //1 3
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];
                            dest[2u] = vector[0u];
                            dest[3u] = vector[0u];
                            //increment the vectors
                            dest+=dChannels;
                            vector+=channels;
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
                            dest+=dChannels;
                            vector+=channels;
                        }
                    }
                }
                else if(channels==2u){
                    if(dChannels==1u){
                        //2 1 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];
                            //increment the vectors
                            dest+=dChannels;
                            vector+=channels;
                        }
                    }
                    else if(dChannels==2u){
                        //2 2 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];
                            dest[1u] = vector[1u];
                            //increment the vectors
                            dest+=dChannels;
                            vector+=channels;
                        }
                    }
                    else if(dChannels==3u){
                        //2 3 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];
                            dest[1u] = vector[0u];
                            dest[2u] = vector[0u];
                            //increment the vectors
                            dest+=dChannels;
                            vector+=channels;
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
                            dest+=dChannels;
                            vector+=channels;
                        }
                    }
                }
                else if(channels==3u){
                    if(dChannels==1u){
                        //3 1
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = edk::Image2D::rgbToL(vector[0u],vector[1u],vector[2u]);
                            //increment the vectors
                            dest+=dChannels;
                            vector+=channels;
                        }
                    }
                    else if(dChannels==2u){
                        //3 2 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = edk::Image2D::rgbToL(vector[0u],vector[1u],vector[2u]);
                            dest[1u] = 255;
                            //increment the vectors
                            dest+=dChannels;
                            vector+=channels;
                        }
                    }
                    else if(dChannels==3u){
                        //3 3
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = vector[0u];
                            dest[1u] = vector[1u];
                            dest[2u] = vector[2u];
                            //increment the vectors
                            dest+=dChannels;
                            vector+=channels;
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
                            dest+=dChannels;
                            vector+=channels;
                        }
                    }
                }
                else if(channels==4u){
                    if(dChannels==1u){
                        //4 1
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = edk::Image2D::rgbToL(vector[0u],vector[1u],vector[2u]);
                            //increment the vectors
                            dest+=dChannels;
                            vector+=channels;
                        }
                    }
                    else if(dChannels==2u){
                        //4 2 transparent
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = edk::Image2D::rgbToL(vector[0u],vector[1u],vector[2u]);
                            dest[1u] = vector[1u];
                            //increment the vectors
                            dest+=dChannels;
                            vector+=channels;
                        }
                    }
                    else if(dChannels==3u){
                        //4 3
                        for(edk::uint32 x = 0u;x<width;x++){
                            dest[0u] = edk::Image2D::rgbToL(vector[0u],vector[1u],vector[2u]);
                            //increment the vectors
                            dest+=dChannels;
                            vector+=channels;
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
                            dest+=dChannels;
                            vector+=channels;
                        }
                    }
                }
                dest+=(dWidth - width - positionX) * dChannels;
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
        if(image->vec && image->channels && image->size.width && image->size.height && image->imageName){
            //test if the characteristics are equal
            if(!(this->vec && image->channels == this->channels && image->size == this->size)){
                //else delete the last image
                this->deleteImage();
                //create a new vec with the vecSize
                if(!this->newImage(image->name(),image->size.width,image->size.height,image->channels)){
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
            if(this->vec && this->size.width && this->size.height && this->channels){
                //clean the image setting all zeros
                memcpy(this->vec,image->vec,this->size.width * this->size.height * this->channels);
                return true;
            }
        }
    }
    //if don't have an image delete the last image
    this->deleteImage();
    return false;
}
bool edk::Image2D::newFrom(edk::Image2D* image){
    if(image){
        //test if the image exist
        if(image->vec && image->channels && image->size.width && image->size.height && image->imageName){
            //test if the characteristics are equal
            if(!(this->vec && image->channels == this->channels && image->size == this->size)){
                //else delete the last image
                this->deleteImage();
                //create a new vec with the vecSize
                if(!this->newImage(image->name(),image->size.width,image->size.height,image->channels)){
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
            if(this->vec && this->size.width && this->size.height && this->channels){
                //clean the image setting all zeros
                memset(this->vec,0u,this->size.width * this->size.height * this->channels);
                return true;
            }
        }
    }
    //if don't have an image delete the last image
    this->deleteImage();
    return false;
}
