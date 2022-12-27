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
    this->cube=NULL;edkEnd();
    this->size=0u;
    this->imageSize = 0u;edkEnd();
}
edk::LUT3D::~LUT3D(){
    //
    this->deleteTable();edkEnd();
}
//calculate the imageSize
edk::size2ui32 edk::LUT3D::calcImageSize(edk::uint16 size){
    edk::uint32 vecSize = size*size*size;edkEnd();
    edk::uint32 result = (edk::uint32)edk::Math::squareRoot(vecSize);edkEnd();
    edk::uint8 increment=0u;
    if(vecSize%result){
        increment=1u;edkEnd();
    }
    edk::size2ui32 ret = edk::size2ui32(result,(vecSize/result) + increment);edkEnd();
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
                this->deleteTable();edkEnd();
                //
                this->size = size;edkEnd();
                this->imageSize = this->calcImageSize(this->size);edkEnd();

                //create a new table
                this->cube = new edk::color3ui8**[this->size];edkEnd();
                if(this->cube){
                    //clean the values
                    for(edk::uint16 x = 0u;x<this->size;x++){
                        this->cube[x] = NULL;edkEnd();
                    }
                    //
                    for(edk::uint16 x = 0u;x<this->size;x++){
                        this->cube[x] = new edk::color3ui8*[this->size];edkEnd();
                        if(this->cube[x]){
                            //clean the values
                            for(edk::uint16 y = 0u;y<this->size;y++){
                                this->cube[x][y] = NULL;edkEnd();
                            }
                            for(edk::uint16 y = 0u;y<this->size;y++){
                                this->cube[x][y] = new edk::color3ui8[this->size];edkEnd();
                                if(!this->cube[x][y]){
                                    //delete all anothers
                                    for(edk::uint16 yd = 0u;yd<y;yd++){
                                        if(this->cube[x][yd]){
                                            delete[] this->cube[x][yd];edkEnd();
                                            this->cube[x][yd]=NULL;edkEnd();
                                        }
                                    }
                                    //delete the r
                                    delete[] this->cube[x];edkEnd();
                                    this->cube[x] = NULL;edkEnd();
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
                                            delete[] this->cube[xd][y];edkEnd();
                                            this->cube[xd][y]=NULL;edkEnd();
                                        }
                                    }
                                    delete[] this->cube[xd];edkEnd();
                                    this->cube[xd] = NULL;edkEnd();
                                }
                            }
                            //delete the cube
                            delete[] this->cube;edkEnd();
                            this->cube=NULL;edkEnd();
                            this->size = 0u;edkEnd();
                            this->imageSize = 0u;edkEnd();
                            break;
                        }
                    }
                }
            }
        }
        //test if have the table
        if(this->cube){
            //
            return this->cleanTable();edkEnd();
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
                delete[] this->cube[x][y];edkEnd();
            }
            delete[] this->cube[x];edkEnd();
        }
        delete[] this->cube;edkEnd();
        this->cube = NULL;edkEnd();
        this->size = 0u;edkEnd();
        this->imageSize = 0u;edkEnd();
        return true;
    }
    this->cube = NULL;edkEnd();
    this->size = 0u;edkEnd();
    this->imageSize = 0u;edkEnd();
    return false;
}
//clean the table values
bool edk::LUT3D::cleanTable(){
    //test if have the table
    edk::uint16 multiply = 256/(this->size - 1);edkEnd();
    edk::uint16 value = 0u;edkEnd();
    if(this->cube && this->size){
        for(edk::uint16 x = 0u;x<size;x++){
            for(edk::uint16 y = 0u;y<size;y++){
                for(edk::uint16 z = 0u;z<size;z++){
                    value = x * multiply;edkEnd();
                    if(value>=255){
                        value=255;edkEnd();
                    }
                    this->cube[x][y][z].r = value;edkEnd();
                    value = y * multiply;edkEnd();
                    if(value>=255){
                        value=255;edkEnd();
                    }
                    this->cube[x][y][z].g = value;edkEnd();
                    value = z * multiply;edkEnd();
                    if(value>=255){
                        value=255;edkEnd();
                    }
                    this->cube[x][y][z].b = value;edkEnd();
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
               );edkEnd();
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
                           );edkEnd();
                }
            }
        }
        return true;
    }
    return false;
}

//return the size of the table. As a cube it only need return one value
edk::uint16 edk::LUT3D::getSize(){
    return this->size;edkEnd();
}
//return the vector size
edk::uint32 edk::LUT3D::getVectorSize(){
    return (edk::uint32)this->size*this->size*this->size;edkEnd();
}
//return the size of the image in pixels
edk::size2ui32 edk::LUT3D::getImageSize(){
    return this->imageSize;edkEnd();
}
edk::uint32 edk::LUT3D::getImageWidth(){
    return this->imageSize.width;edkEnd();
}
edk::uint32 edk::LUT3D::getImageHeight(){
    return this->imageSize.height;edkEnd();
}

//save the table into a .cube file
bool edk::LUT3D::saveTo(edk::char8* fileName){
    //create the file
    edk::File file;edkEnd();
    if(file.createAndOpenTextFile(fileName)){
        //Write the fileTitle
        file.writeText("TITLE \"");edkEnd();
        file.writeText(fileName);edkEnd();
        file.writeText("\"\n");edkEnd();

        //write the size of the file
        file.writeText("LUT_3D_SIZE ");edkEnd();
        file.writeText(this->size);edkEnd();
        file.writeText("\n");edkEnd();
        edk::float32 percent=0.f;edkEnd();
        if(this->cube && this->size){
            for(edk::uint16 z = 0u;z<size;z++){
                for(edk::uint16 y = 0u;y<size;y++){
                    for(edk::uint16 x = 0u;x<size;x++){
                        //get the value percent
                        percent = this->cube[x][y][z].r/255.f;edkEnd();
                        file.writeText(percent);edkEnd();
                        file.writeText(" ");edkEnd();
                        percent = this->cube[x][y][z].g/255.f;edkEnd();
                        file.writeText(percent);edkEnd();
                        file.writeText(" ");edkEnd();
                        percent = this->cube[x][y][z].b/255.f;edkEnd();
                        file.writeText(percent);edkEnd();
                        file.writeText("\n");edkEnd();
                    }
                }
            }
            file.closeFile();edkEnd();
            return true;
        }
        file.closeFile();edkEnd();
    }
    return false;
}
bool edk::LUT3D::saveTo(const edk::char8* fileName){
    return this->saveTo((edk::char8*) fileName);edkEnd();
}
//load from file
bool edk::LUT3D::loadFrom(edk::char8* fileName){
    bool ret = false;edkEnd();
    edk::File file;edkEnd();
    if(file.openTextFile(fileName)){
        edk::char8* line = NULL;edkEnd();
        edk::uint32 size = 0u;edkEnd();
        edk::char8* title = NULL;edkEnd();
        edk::char8* sizeTableStr = NULL;edkEnd();
        edk::uint32 sizeTable = 0u;edkEnd();
        //read the first part
        while(!file.endOfFile() && file.isOpened()){
            //read the line
            line = file.readTextString("\n",false);edkEnd();
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
                                                                line[size-1u]='\0';edkEnd();
                                                                //read the title
                                                                title = edk::String::strCopy(&line[7u]);edkEnd();
                                                            }
                                                            else{
                                                                //else close the file
                                                                file.closeFile();edkEnd();
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
                                                                                sizeTableStr = edk::String::strCopy(&line[12u]);edkEnd();
                                                                                if(sizeTableStr){
                                                                                    //read the sizeTableStr
                                                                                    sizeTable = edk::String::strToInt32(sizeTableStr);edkEnd();
                                                                                }
                                                                            }
                                                                            else{
                                                                                //else close the file
                                                                                file.closeFile();edkEnd();
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
                delete[] line;edkEnd();

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
                edk::uint32 position2 = 0u;edkEnd();
                edk::uint32 position3 = 0u;edkEnd();
                edk::float32 percent=0.f;edkEnd();
                bool haveEnd = false;edkEnd();
                //read the values
                for(edk::uint16 z = 0u;z<this->size;z++){
                    for(edk::uint16 y = 0u;y<this->size;y++){
                        for(edk::uint16 x = 0u;x<this->size;x++){
                            //get the value percent
                            //test if the file is opened and are not in the end of the file
                            while(file.isOpened() && !file.endOfFile()){
                                //read the line
                                line = file.readTextString("\n",false);edkEnd();
                                if(line){
                                    //test the string size
                                    if((size = edk::String::strSize(line))){
                                        //test if is NOT a comment
                                        if(*line!='#'){
                                            //read the values

                                            if((position2 = edk::String::stringHaveChar(line,' '))){
                                                //read the x
                                                percent = edk::String::strToFloat32(line);edkEnd();
                                                this->cube[x][y][z].r = (edk::uint8)(percent*255.f)+1u;edkEnd();
                                                if((position3 = edk::String::stringHaveChar(&line[position2],' '))){
                                                    //
                                                    position3 += position2;edkEnd();
                                                    //read the y
                                                    percent = edk::String::strToFloat32(&line[position2]);edkEnd();
                                                    this->cube[x][y][z].g = (edk::uint8)(percent*255.f)+1u;edkEnd();
                                                    //read the z
                                                    percent = edk::String::strToFloat32(&line[position3]);edkEnd();
                                                    this->cube[x][y][z].b = (edk::uint8)(percent*255.f)+1u;edkEnd();
                                                }
                                                else{
                                                    haveEnd=true;edkEnd();
                                                }
                                            }
                                            else{
                                                haveEnd=true;edkEnd();
                                            }
                                        }
                                        //delete the line readed
                                        delete[] line;edkEnd();
                                        break;
                                    }

                                    //delete the line readed
                                    delete[] line;edkEnd();
                                }
                            }
                            if(!file.isOpened() || file.endOfFile()){
                                haveEnd=true;edkEnd();
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
                        ret = true;edkEnd();
                        break;
                    }
                }
            }
        }

        //delete the title
        if(title){
            delete[] title;edkEnd();
        }
        if(sizeTableStr){
            delete[] sizeTableStr;edkEnd();
        }

        //test if is not returning true
        if(!ret){
            //delete the table
            this->deleteTable();edkEnd();
        }

        //read the lines
        file.closeFile();edkEnd();
    }
    return ret;
}
bool edk::LUT3D::loadFrom(const edk::char8* fileName){
    return this->loadFrom((edk::char8*) fileName);edkEnd();
}
//save to an image file
bool edk::LUT3D::saveToImage(edk::char8* fileName){
    if(this->cube && this->size){
        //test the fileName
        if(fileName){
            //create the image
            edk::Image2D image;edkEnd();
            edk::uint8* vec = NULL;edkEnd();
            if(image.newImage(fileName,this->getImageSize(),3u)){
                if((vec = image.getPixels())){
                    //copy the pixels
                    for(edk::uint16 z = 0u;z<size;z++){
                        for(edk::uint16 y = 0u;y<size;y++){
                            for(edk::uint16 x = 0u;x<size;x++){
                                //get the value percent
                                vec[0u] = this->cube[x][y][z].r;edkEnd();
                                vec[1u] = this->cube[x][y][z].g;edkEnd();
                                vec[2u] = this->cube[x][y][z].b;edkEnd();
                                vec+=3u;edkEnd();
                            }
                        }
                    }
                    //save the image
                    if(image.saveToFile(fileName)){
                        image.deleteImage();edkEnd();
                        return true;
                    }
                }
                image.deleteImage();edkEnd();
            }
        }
    }
    return false;
}
bool edk::LUT3D::saveToImage(const edk::char8* fileName){
    return this->saveToImage((edk::char8*) fileName);edkEnd();
}
//load from an imageFile
bool edk::LUT3D::loadFromImage(edk::uint16 size,edk::char8* fileName){
    //create the new table
    if(this->newTable(size)){
        if(this->cube && this->size){
            //test the fileName
            if(fileName){
                //load the imageFile
                edk::Image2D image;edkEnd();
                edk::uint8* vec = NULL;edkEnd();
                edk::uint8 channels = 0u;edkEnd();
                if(image.loadFromFile(fileName)){
                    if((vec = image.getPixels())){
                        //get the channels
                        channels = image.getChannels();edkEnd();
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
                                            this->cube[x][y][z].r = vec[0u];edkEnd();
                                            this->cube[x][y][z].g = vec[1u];edkEnd();
                                            this->cube[x][y][z].b = vec[2u];edkEnd();
                                            vec+=channels;edkEnd();
                                        }
                                    }
                                }
                                image.deleteImage();edkEnd();
                                return true;
                            }
                        }
                    }
                    image.deleteImage();edkEnd();
                }
            }
        }
        //else delete the table
        this->deleteTable();edkEnd();
    }
    return false;
}
bool edk::LUT3D::loadFromImage(edk::uint16 size,const edk::char8* fileName){
    return this->loadFromImage(size,(edk::char8*) fileName);edkEnd();
}

