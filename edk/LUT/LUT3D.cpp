#include "LUT3D.h"

/*
Library C++ LUT - Create, save and load LUT (Look Up Table) 3D
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

edk::LUT3D::LUT3D(){
    //
    this->classThis=NULL;
    this->Constructor();
}
edk::LUT3D::~LUT3D(){
    this->Destructor();
}

void edk::LUT3D::Constructor(){
    //
    if(this->classThis!=this){
        this->classThis=this;
        this->cube=NULL;
        this->size=0u;
        this->imageSize = 0u;
    }
}
void edk::LUT3D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->deleteTable();
    }
}

//calculate the imageSize
edk::size2ui32 edk::LUT3D::calcImageSize(edk::uint16 size){
    edk::uint32 vecSize = size*size*size;
    edk::uint32 result = (edk::uint32)edk::Math::squareRoot(vecSize);
    edk::uint8 increment=0u;
    if(vecSize%result){
        increment=1u;
    }
    edk::size2ui32 ret = edk::size2ui32(result,(vecSize/result) + increment);
    return ret;
}

//create a new table
bool edk::LUT3D::newTable(edk::uint16 size){
    //test the size
    if(size){
        if(size!=this->size){
            //test the size
            if(size<=256 && size>1u){
                //delete the table and create a new one
                this->deleteTable();
                //
                this->size = size;
                this->imageSize = this->calcImageSize(this->size);

                //create a new table
                this->cube = (edk::color3ui8***)malloc(sizeof(edk::color3ui8**)*this->size);
                if(this->cube){
                    //clean the values
                    for(edk::uint16 x = 0u;x<this->size;x++){
                        this->cube[x] = NULL;
                    }
                    //
                    for(edk::uint16 x = 0u;x<this->size;x++){
                        this->cube[x] = (edk::color3ui8**)malloc(sizeof(edk::color3ui8*)*this->size);
                        if(this->cube[x]){
                            //clean the values
                            for(edk::uint16 y = 0u;y<this->size;y++){
                                this->cube[x][y] = NULL;
                            }
                            for(edk::uint16 y = 0u;y<this->size;y++){
                                this->cube[x][y] = (edk::color3ui8*)malloc(sizeof(edk::color3ui8)*this->size);
                                if(!this->cube[x][y]){
                                    //delete all anothers
                                    for(edk::uint16 yd = 0u;yd<y;yd++){
                                        if(this->cube[x][yd]){
                                            free(this->cube[x][yd]);
                                            this->cube[x][yd]=NULL;
                                        }
                                    }
                                    //delete the r
                                    free(this->cube[x]);
                                    this->cube[x] = NULL;
                                    break;
                                }
                            }
                        }
                        if(!this->cube[x]){
                            //else delete
                            for(edk::uint16 xd = 0u;xd<x;xd++){
                                if(this->cube[xd]){
                                    //delete all inside
                                    for(edk::uint16 y = 0u;y<this->size;y++){
                                        if(this->cube[xd][y]){
                                            free(this->cube[xd][y]);
                                            this->cube[xd][y]=NULL;
                                        }
                                    }
                                    free(this->cube[xd]);
                                    this->cube[xd] = NULL;
                                }
                            }
                            //delete the cube
                            free(this->cube);
                            this->cube=NULL;
                            this->size = 0u;
                            this->imageSize = 0u;
                            break;
                        }
                    }
                }
            }
        }
        //test if have the table
        if(this->cube){
            //
            return this->cleanTable();
        }
    }
    //delete the table
    return false;
}
//delete the table
bool edk::LUT3D::deleteTable(){
    if(this->cube && this->size){
        for(edk::uint16 x = 0u;x<size;x++){
            for(edk::uint16 y = 0u;y<size;y++){
                free(this->cube[x][y]);
            }
            free(this->cube[x]);
        }
        free(this->cube);
        this->cube = NULL;
        this->size = 0u;
        this->imageSize = 0u;
        return true;
    }
    this->cube = NULL;
    this->size = 0u;
    this->imageSize = 0u;
    return false;
}
//clean the table values
bool edk::LUT3D::cleanTable(){
    //test if have the table
    edk::uint16 multiply = 256/(this->size - 1);
    edk::uint16 value = 0u;
    if(this->cube && this->size){
        for(edk::uint16 x = 0u;x<size;x++){
            for(edk::uint16 y = 0u;y<size;y++){
                for(edk::uint16 z = 0u;z<size;z++){
                    value = x * multiply;
                    if(value>=255){
                        value=255;
                    }
                    this->cube[x][y][z].r = value;
                    value = y * multiply;
                    if(value>=255){
                        value=255;
                    }
                    this->cube[x][y][z].g = value;
                    value = z * multiply;
                    if(value>=255){
                        value=255;
                    }
                    this->cube[x][y][z].b = value;
                }
            }
        }
        return true;
    }
    return false;
}
//print the table for debug
bool edk::LUT3D::printTable(){
    //test if have the table
    if(this->cube && this->size){
        printf("\nTable size %u (%u)"
               ,this->getSize()
               ,this->getVectorSize()
               );
        for(edk::uint16 x = 0u;x<size;x++){
            for(edk::uint16 y = 0u;y<size;y++){
                for(edk::uint16 z = 0u;z<size;z++){
                    printf("\n[%u][%u][%u] == (%u,%u,%u)"
                           ,x
                           ,y
                           ,z
                           ,this->cube[x][y][z].r
                           ,this->cube[x][y][z].g
                           ,this->cube[x][y][z].b
                           );
                }
            }
        }
        return true;
    }
    return false;
}

//return the size of the table. As a cube it only need return one value
edk::uint16 edk::LUT3D::getSize(){
    return this->size;
}
//return the vector size
edk::uint32 edk::LUT3D::getVectorSize(){
    return (edk::uint32)this->size*this->size*this->size;
}
//return the size of the image in pixels
edk::size2ui32 edk::LUT3D::getImageSize(){
    return this->imageSize;
}
edk::uint32 edk::LUT3D::getImageWidth(){
    return this->imageSize.width;
}
edk::uint32 edk::LUT3D::getImageHeight(){
    return this->imageSize.height;
}

//save the table into a .cube file
bool edk::LUT3D::saveTo(edk::char8* fileName){
    //create the file
    edk::File file;
    if(file.createAndOpenTextFile(fileName)){
        //Write the fileTitle
        file.writeText("TITLE \"");
        file.writeText(fileName);
        file.writeText("\"\n");

        //write the size of the file
        file.writeText("LUT_3D_SIZE ");
        file.writeText(this->size);
        file.writeText("\n");
        edk::float32 percent=0.f;
        if(this->cube && this->size){
            for(edk::uint16 z = 0u;z<size;z++){
                for(edk::uint16 y = 0u;y<size;y++){
                    for(edk::uint16 x = 0u;x<size;x++){
                        //get the value percent
                        percent = this->cube[x][y][z].r/255.f;
                        file.writeText(percent);
                        file.writeText(" ");
                        percent = this->cube[x][y][z].g/255.f;
                        file.writeText(percent);
                        file.writeText(" ");
                        percent = this->cube[x][y][z].b/255.f;
                        file.writeText(percent);
                        file.writeText("\n");
                    }
                }
            }
            file.closeFile();
            return true;
        }
        file.closeFile();
    }
    return false;
}
bool edk::LUT3D::saveTo(const edk::char8* fileName){
    return this->saveTo((edk::char8*) fileName);
}
//load from file
bool edk::LUT3D::loadFrom(edk::char8* fileName){
    bool ret = false;
    edk::File file;
    if(file.openTextFile(fileName)){
        edk::char8* line = NULL;
        edk::uint32 size = 0u;
        edk::char8* title = NULL;
        edk::char8* sizeTableStr = NULL;
        edk::uint32 sizeTable = 0u;
        //read the first part
        while(!file.endOfFile() && file.isOpened()){
            //read the line
            line = file.readTextString("\n",false);
            if(line){
                //test the string size
                if((size = edk::String::strSize(line))){
                    //test if is NOT a comment
                    if(*line!='#'){
                        //test if it's a TITLE
                        if(size>sizeof("TITLE \"\"")){
                            //test if it's a TITLE
                            if(line[0u]=='T'){
                                if(line[1u]=='I'){
                                    if(line[2u]=='T'){
                                        if(line[3u]=='L'){
                                            if(line[4u]=='E'){
                                                if(line[5u]==' '){
                                                    if(line[6u]=='"'){
                                                        if(line[size-1u]=='"'){
                                                            if(!title){
                                                                line[size-1u]='\0';
                                                                //read the title
                                                                title = edk::String::strCopy(&line[7u]);
                                                            }
                                                            else{
                                                                //else close the file
                                                                file.closeFile();
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
                        //test if it's a LUT_3D_SIZE
                        if(size>sizeof("LUT_3D_SIZE ")){
                            if(line[0u]=='L'){
                                if(line[1u]=='U'){
                                    if(line[2u]=='T'){
                                        if(line[3u]=='_'){
                                            if(line[4u]=='3'){
                                                if(line[5u]=='D'){
                                                    if(line[6u]=='_'){
                                                        if(line[7u]=='S'){
                                                            if(line[8u]=='I'){
                                                                if(line[9u]=='Z'){
                                                                    if(line[10u]=='E'){
                                                                        if(line[11u]==' '){
                                                                            //test if dont have the tableSize
                                                                            if(!sizeTableStr){
                                                                                //12u
                                                                                //read the sizeTableStr
                                                                                sizeTableStr = edk::String::strCopy(&line[12u]);
                                                                                if(sizeTableStr){
                                                                                    //read the sizeTableStr
                                                                                    sizeTable = edk::String::strToInt32(sizeTableStr);
                                                                                }
                                                                            }
                                                                            else{
                                                                                //else close the file
                                                                                file.closeFile();
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
                        }
                    }
                }
                //delete the line
                free(line);

                //test if have the title and the sizeTableStr
                if(title && sizeTableStr){
                    //break
                    break;
                }
            }
        }

        //test if have the title and the size
        if(title && sizeTableStr && sizeTable && file.isOpened()){
            //create the new table
            if(this->newTable(sizeTable)){
                edk::uint32 position2 = 0u;
                edk::uint32 position3 = 0u;
                edk::float32 percent=0.f;
                bool haveEnd = false;
                //read the values
                for(edk::uint16 z = 0u;z<this->size;z++){
                    for(edk::uint16 y = 0u;y<this->size;y++){
                        for(edk::uint16 x = 0u;x<this->size;x++){
                            //get the value percent
                            //test if the file is opened and are not in the end of the file
                            while(file.isOpened() && !file.endOfFile()){
                                //read the line
                                line = file.readTextString("\n",false);
                                if(line){
                                    //test the string size
                                    if((size = edk::String::strSize(line))){
                                        //test if is NOT a comment
                                        if(*line!='#'){
                                            //read the values

                                            if((position2 = edk::String::stringHaveChar(line,' '))){
                                                //read the x
                                                percent = edk::String::strToFloat32(line);
                                                this->cube[x][y][z].r = (edk::uint8)(percent*255.f)+1u;
                                                if((position3 = edk::String::stringHaveChar(&line[position2],' '))){
                                                    //
                                                    position3 += position2;
                                                    //read the y
                                                    percent = edk::String::strToFloat32(&line[position2]);
                                                    this->cube[x][y][z].g = (edk::uint8)(percent*255.f)+1u;
                                                    //read the z
                                                    percent = edk::String::strToFloat32(&line[position3]);
                                                    this->cube[x][y][z].b = (edk::uint8)(percent*255.f)+1u;
                                                }
                                                else{
                                                    haveEnd=true;
                                                }
                                            }
                                            else{
                                                haveEnd=true;
                                            }
                                        }
                                        //delete the line readed
                                        free(line);
                                        break;
                                    }

                                    //delete the line readed
                                    free(line);
                                }
                            }
                            if(!file.isOpened() || file.endOfFile()){
                                haveEnd=true;
                            }
                            if(haveEnd){
                                break;
                            }
                        }
                        if(haveEnd){
                            break;
                        }
                    }
                    if(haveEnd){
                        break;
                    }

                    //test if copy all the values
                    if(z>=this->size-1u){
                        //return true
                        ret = true;
                        break;
                    }
                }
            }
        }

        //delete the title
        if(title){
            free(title);
        }
        if(sizeTableStr){
            free(sizeTableStr);
        }

        //test if is not returning true
        if(!ret){
            //delete the table
            this->deleteTable();
        }

        //read the lines
        file.closeFile();
    }
    return ret;
}
bool edk::LUT3D::loadFrom(const edk::char8* fileName){
    return this->loadFrom((edk::char8*) fileName);
}
//save to an image file
bool edk::LUT3D::saveToImage(edk::char8* fileName){
    if(this->cube && this->size){
        //test the fileName
        if(fileName){
            //create the image
            edk::Image2D image;
            edk::uint8* vec = NULL;
            if(image.newImage(fileName,this->getImageSize(),3u)){
                if((vec = image.getPixels())){
                    //copy the pixels
                    for(edk::uint16 z = 0u;z<size;z++){
                        for(edk::uint16 y = 0u;y<size;y++){
                            for(edk::uint16 x = 0u;x<size;x++){
                                //get the value percent
                                vec[0u] = this->cube[x][y][z].r;
                                vec[1u] = this->cube[x][y][z].g;
                                vec[2u] = this->cube[x][y][z].b;
                                vec+=3u;
                            }
                        }
                    }
                    //save the image
                    if(image.saveToFile(fileName)){
                        image.deleteImage();
                        return true;
                    }
                }
                image.deleteImage();
            }
        }
    }
    return false;
}
bool edk::LUT3D::saveToImage(const edk::char8* fileName){
    return this->saveToImage((edk::char8*) fileName);
}
//load from an imageFile
bool edk::LUT3D::loadFromImage(edk::uint16 size,edk::char8* fileName){
    //create the new table
    if(this->newTable(size)){
        if(this->cube && this->size){
            //test the fileName
            if(fileName){
                //load the imageFile
                edk::Image2D image;
                edk::uint8* vec = NULL;
                edk::uint8 channels = 0u;
                if(image.loadFromFile(fileName)){
                    if((vec = image.getPixels())){
                        //get the channels
                        channels = image.getChannels();
                        if(channels==3u || channels==4u){
                            if(this->imageSize.width == image.getWidth()
                                    &&
                                    this->imageSize.height == image.getHeight()
                                    ){
                                //copy the pixels
                                for(edk::uint16 z = 0u;z<size;z++){
                                    for(edk::uint16 y = 0u;y<size;y++){
                                        for(edk::uint16 x = 0u;x<size;x++){
                                            //get the value percent
                                            this->cube[x][y][z].r = vec[0u];
                                            this->cube[x][y][z].g = vec[1u];
                                            this->cube[x][y][z].b = vec[2u];
                                            vec+=channels;
                                        }
                                    }
                                }
                                image.deleteImage();
                                return true;
                            }
                        }
                    }
                    image.deleteImage();
                }
            }
        }
        //else delete the table
        this->deleteTable();
    }
    return false;
}
bool edk::LUT3D::loadFromImage(edk::uint16 size,const edk::char8* fileName){
    return this->loadFromImage(size,(edk::char8*) fileName);
}

