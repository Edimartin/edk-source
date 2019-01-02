#include "LUT3D.h"

edk::LUT3D::LUT3D(){
    //
    this->cube=NULL;
    this->size=0u;
    this->imageSize = 0u;
}
edk::LUT3D::~LUT3D(){
    //
    this->deleteTable();
}
//calculate the imageSize
edk::size2ui32 edk::LUT3D::calcImageSize(edk::uint16 size){
    edk::uint32 vecSize = size*size*size;
    edk::uint32 result = (edk::uint32)edk::Math::squareRootInt64(vecSize);
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
        //test if the size is different
        edk::uint8 pair = size%2u;
        if(!pair){
            if(size!=this->size){
                //test the size
                if(size<=256 && size>1u){
                    //delete the table and create a new one
                    this->deleteTable();
                    //
                    this->size = size;
                    this->imageSize = this->calcImageSize(this->size);

                    //create a new table
                    this->cube = new edk::color3ui8**[this->size];
                    if(this->cube){
                        //clean the values
                        for(edk::uint16 r = 0u;r<this->size;r++){
                            this->cube[r] = NULL;
                        }
                        //
                        for(edk::uint16 r = 0u;r<this->size;r++){
                            this->cube[r] = new edk::color3ui8*[this->size];
                            if(this->cube[r]){
                                //clean the values
                                for(edk::uint16 g = 0u;g<this->size;g++){
                                    this->cube[r][g] = NULL;
                                }
                                for(edk::uint16 g = 0u;g<this->size;g++){
                                    this->cube[r][g] = new edk::color3ui8[this->size];
                                    if(!this->cube[r][g]){
                                        //delete all anothers
                                        for(edk::uint16 gd = 0u;gd<g;gd++){
                                            if(this->cube[r][gd]){
                                                delete[] this->cube[r][gd];
                                                this->cube[r][gd]=NULL;
                                            }
                                        }
                                        //delete the r
                                        delete[] this->cube[r];
                                        this->cube[r] = NULL;
                                        break;
                                    }
                                }
                            }
                            if(!this->cube[r]){
                                //else delete
                                for(edk::uint16 rd = 0u;rd<r;rd++){
                                    if(this->cube[rd]){
                                        //delete all inside
                                        for(edk::uint16 g = 0u;g<this->size;g++){
                                            if(this->cube[rd][g]){
                                                delete[] this->cube[rd][g];
                                                this->cube[rd][g]=NULL;
                                            }
                                        }
                                        delete[] this->cube[rd];
                                        this->cube[rd] = NULL;
                                    }
                                }
                                //delete the cube
                                delete[] this->cube;
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
    }
    //delete the table
    return false;
}
//delete the table
bool edk::LUT3D::deleteTable(){
    if(this->cube && this->size){
        for(edk::uint16 r = 0u;r<size;r++){
            for(edk::uint16 g = 0u;g<size;g++){
                delete[] this->cube[r][g];
            }
            delete[] this->cube[r];
        }
        delete[] this->cube;
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
        for(edk::uint16 r = 0u;r<size;r++){
            for(edk::uint16 g = 0u;g<size;g++){
                for(edk::uint16 b = 0u;b<size;b++){
                    value = r * multiply;
                    if(value>=255)value=255;
                    this->cube[r][g][b].r = value;
                    value = g * multiply;
                    if(value>=255)value=255;
                    this->cube[r][g][b].g = value;
                    value = b * multiply;
                    if(value>=255)value=255;
                    this->cube[r][g][b].b = value;
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
        for(edk::uint16 r = 0u;r<size;r++){
            for(edk::uint16 g = 0u;g<size;g++){
                for(edk::uint16 b = 0u;b<size;b++){
                    printf("\n[%u][%u][%u] == (%u,%u,%u)"
                           ,r
                           ,g
                           ,b
                           ,this->cube[r][g][b].r
                           ,this->cube[r][g][b].g
                           ,this->cube[r][g][b].b
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
            for(edk::uint16 b = 0u;b<size;b++){
                for(edk::uint16 g = 0u;g<size;g++){
                    for(edk::uint16 r = 0u;r<size;r++){
                        //get the value percent
                        percent = this->cube[r][g][b].r/255.f;
                        file.writeText(percent);
                        file.writeText(" ");
                        percent = this->cube[r][g][b].g/255.f;
                        file.writeText(percent);
                        file.writeText(" ");
                        percent = this->cube[r][g][b].b/255.f;
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
//bool edk::LUT3D::loadFrom(edk::char8* fileName){
//    //
//    edk::File file;
//    if(file.openTextFile(fileName)){
//        //read the lines
//        file.closeFile();
//    }
//    return false;
//}
//bool edk::LUT3D::loadFrom(const edk::char8* fileName){
//    return this->loadFrom((edk::char8*) fileName);
//}
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
                    for(edk::uint16 b = 0u;b<size;b++){
                        for(edk::uint16 g = 0u;g<size;g++){
                            for(edk::uint16 r = 0u;r<size;r++){
                                //get the value percent
                                vec[0u] = this->cube[r][g][b].r;
                                vec[1u] = this->cube[r][g][b].g;
                                vec[2u] = this->cube[r][g][b].b;
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
                                for(edk::uint16 b = 0u;b<size;b++){
                                    for(edk::uint16 g = 0u;g<size;g++){
                                        for(edk::uint16 r = 0u;r<size;r++){
                                            //get the value percent
                                            this->cube[r][g][b].r = vec[0u];
                                            this->cube[r][g][b].g = vec[1u];
                                            this->cube[r][g][b].b = vec[2u];
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

