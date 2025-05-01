#include "Package.h"

/*
Library Package - Package to be sended by the edk::Socket
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

edk::network::Package::Package(){
    this->classThis=NULL; 
    this->Constructor();
}
edk::network::Package::~Package(){
    this->Destructor();
}

void edk::network::Package::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        this->header.clean(); 

        this->vec=NULL; 
        this->headerSize = (edk::uint32)(sizeof(edk::network::Package::PackHeader)); 
        this->vectorSize=0u;
    }
}
void edk::network::Package::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->deleteVector();
    }
}

//create a new package
bool edk::network::Package::newVector(edk::uint32 size){
    //delete the lastPackage
    this->deleteVector(); 
    if(size){
        this->header.size=0u;
        this->vectorSize = size; 
        //create a new vec
        this->vec = (edk::uint8*)malloc(sizeof(edk::uint8) * (this->vectorSize + this->headerSize)); 
        if(this->vec){
            //update the header
            this->updateVector(); 
            return true;
        }
    }
    return false;
}
//update the header to the vector
bool edk::network::Package::updateVector(){
    //test if have a vector
    if(this->vec){
        //copy the header
        memcpy(this->vec,&this->header,this->headerSize); 
        return true;
    }
    return false;
}

//delete the vector
void edk::network::Package::deleteVector(){
    if(this->vec){
        free(this->vec); 
    }
    this->vec=NULL; 
    //clean the header
    this->header.size=0u;
    this->vectorSize=0u;
}
//copy a vector to the package
bool edk::network::Package::drawVector(edk::classID vec,edk::uint32 size,edk::uint32 vecSize){
    //test the vec and size
    if(vec && size){
        //test if the new package don't have the same size of the last package
        if(vecSize){
            if(this->vectorSize != vecSize){
                //create a new vec
                this->newVector(size); 
            }
        }
        else{
            if(this->vectorSize != size){
                //create a new vec
                this->newVector(size); 
            }
        }
        //test the package
        if(this->vec && this->vectorSize && size<=this->vectorSize){
            this->header.size = size; 
            //copy the data to the vector
            //TODO: ERROR memcpy
            memcpy(&this->vec[this->headerSize],vec,this->header.size); 
            this->updateVector(); 
            return true;
        }
    }
    return false;
}
bool edk::network::Package::drawVector(edk::classID vec,edk::uint32 size,edk::uint32 vecSize,edk::uint32 position,edk::uint32 id,edk::uint32 total){
    //set the header
    this->setHeader(position,id,total); 
    return this->drawVector(vec,size,vecSize); 
}
//add the vector with the header
bool edk::network::Package::addPackage(edk::classID vec,edk::uint32 size){
    //test the vec and size
    if(vec && size && size>this->headerSize+1u){
        edk::uint8* temp = (edk::uint8*)vec; 
        edk::network::Package::PackHeader header; 
        //load the header
        memcpy(&header,temp,this->headerSize); 
        //test if it's not bloken
        if(!header.isBroken()){
            //copy the vector
            return this->drawVector(&temp[this->headerSize],header.size,size-this->headerSize,header.position,header.id,header.packages); 
        }
    }
    return false;
}
//set the package header
void edk::network::Package::setHeader(edk::uint32 position,edk::uint32 id,edk::uint32 total){
    //set the header
    this->header.id = id; 
    this->header.position = position; 
    this->header.packages = total; 
    //update the header
    this->updateVector(); 
}
void edk::network::Package::setHeader(edk::classID vec){
    //create a headerTemp
    edk::network::Package::PackHeader header; 
    if(!header.isBroken()){
        memcpy(&header,vec,this->headerSize); 
        this->setHeader(header.position,header.id,header.packages); 
    }
}
//return the id of the packet
edk::uint32 edk::network::Package::getID(){
    return this->header.id; 
}
//return the id of the packet
edk::uint32 edk::network::Package::getPosition(){
    return this->header.position; 
}
//get the total number of packages
edk::uint32 edk::network::Package::getPackages(){
    return this->header.packages; 
}
//return the size of the package
edk::uint32 edk::network::Package::getPackageSize(){
    return this->header.size; 
}

//return the vector
edk::uint8* edk::network::Package::getVec(){
    return this->vec; 
}
edk::uint8* edk::network::Package::getPackageVector(){
    if(this->vec){
        return &this->vec[this->headerSize]; 
    }
    return NULL;
}

edk::uint32 edk::network::Package::getVecSize(){
    return this->headerSize + this->vectorSize; 
}

//test if the header is broked
bool edk::network::Package::headerIsBroken(edk::classID vec){
    //test the vec
    if(vec){
        //copy the header
        edk::network::Package::PackHeader header; 
        memcpy(&header,vec,sizeof(edk::network::Package::PackHeader)); 
        //test if it's broken
        return header.isBroken(); 
    }
    return false;
}
//get the full size by the header
edk::uint32 edk::network::Package::getHeaderFullSize(edk::classID vec){
    //test the vec
    if(vec){
        //copy the header
        edk::network::Package::PackHeader header; 
        memcpy(&header,vec,sizeof(edk::network::Package::PackHeader)); 
        return header.size + sizeof(edk::network::Package::PackHeader); 
    }
    return 0u; 
}
//get the position by the header
edk::uint32 edk::network::Package::getHeaderPosition(edk::classID vec){
    //test the vec
    if(vec){
        //copy the header
        edk::network::Package::PackHeader header; 
        memcpy(&header,vec,sizeof(edk::network::Package::PackHeader)); 
        return header.position; 
    }
    return 0u; 
}
//get the ID by the header
edk::uint32 edk::network::Package::getHeaderId(edk::classID vec){
    //test the vec
    if(vec){
        //copy the header
        edk::network::Package::PackHeader header; 
        memcpy(&header,vec,sizeof(edk::network::Package::PackHeader)); 
        return header.id; 
    }
    return 0u; 
}
//get the packages by the header
edk::uint32 edk::network::Package::getHeaderPackages(edk::classID vec){
    //test the vec
    if(vec){
        //copy the header
        edk::network::Package::PackHeader header; 
        memcpy(&header,vec,sizeof(edk::network::Package::PackHeader)); 
        return header.packages; 
    }
    return 0u; 
}
