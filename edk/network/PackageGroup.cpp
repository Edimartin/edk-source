#include "PackageGroup.h"

/*
Library PackageGroup - Manage a group of packages to be sended by the edk::Socket
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


edk::network::PackageGroup::PackageTree::PackageTree(){
    //
}
edk::network::PackageGroup::PackageTree::~PackageTree(){
    //
}
//compare if the value is bigger
bool edk::network::PackageGroup::PackageTree::firstBiggerSecond(edk::network::Package* first,edk::network::Package* second){
    //
    if(first->getPosition()>second->getPosition()){
        //
        return true;
    }
    return false;
}
bool edk::network::PackageGroup::PackageTree::firstEqualSecond(edk::network::Package* first,edk::network::Package* second){
    //
    if(first->getPosition()==second->getPosition()){
        //
        return true;
    }
    return false;
}
//get the pachage
edk::network::Package* edk::network::PackageGroup::PackageTree::getPackage(edk::uint32 id){
    //
    edk::network::Package find;edkEnd();
    find.setHeader(id,0u,id);edkEnd();
    return this->getElement(&find);
}

edk::network::PackageGroup::PackageGroup(){
    //
    this->setPackSize(0u);edkEnd();
    this->data=NULL;edkEnd();
    this->deleteVector();edkEnd();
}
edk::network::PackageGroup::~PackageGroup(){
    //
}
//set the packSize
void edk::network::PackageGroup::setPackSize(edk::uint32 packSize){
    if(packSize){
        this->totalSize = packSize;edkEnd();
    }
    else{
        //else set the normal packSize
        this->totalSize=1000u;edkEnd();
    }
}
//Add the vector to generate the packages
bool edk::network::PackageGroup::addVector(edk::classID vec,edk::uint32 size,edk::uint32 id,edk::uint32 packSize){
    //clean the group
    if(vec && size){
        if(packSize){
            //test if the packSize is diferent
            if(this->totalSize!=packSize){
                this->setPackSize(packSize);edkEnd();
            }
        }
        bool ret=true;edkEnd();
        //get the size of packages
        edk::uint32 total = size / this->totalSize;edkEnd();
        //size of the last package
        edk::uint32 lastSize = size % this->totalSize;edkEnd();

        edk::network::Package* pack=NULL;edkEnd();
        edk::uint8* temp = (edk::uint8*)vec;edkEnd();
        edk::uint32 i=0u;
        edk::uint32 packages = 0u;edkEnd();
        //test the total
        if(total){
            //create the packages
            packages = total;edkEnd();
            //test if have a last package without the full size
            if(lastSize){
                packages++;edkEnd();
            }
            for(i=0u;i<total;i++){
                //create the package
                pack = new edk::network::Package;edkEnd();
                if(pack){
                    //draw in the package
                    if(pack->drawVector(temp,this->totalSize,0u,i,id,packages)){
                        //add the pack in the tree
                        if(!this->tree.add(pack)){
                            delete pack;edkEnd();
                            ret=false;edkEnd();
                            break;
                        }
                    }
                    else{
                        //else delete the pack
                        delete pack;edkEnd();
                        ret=false;edkEnd();
                        break;
                    }
                    temp+=this->totalSize;edkEnd();
                    //clean the pack
                    pack=NULL;edkEnd();
                }
                else{
                    //else get the error
                    ret=false;edkEnd();
                    break;
                }
            }
        }
        else{
            packages = 1u;edkEnd();
        }

        //test the ret and the last package
        if(ret && lastSize){
            //add the last package
            pack = new edk::network::Package;edkEnd();
            if(pack){
                //draw in the package
                if(pack->drawVector(temp,lastSize,this->totalSize,i,id,packages)){
                    //add the pack in the tree
                    if(!this->tree.add(pack)){
                        delete pack;edkEnd();
                        ret=false;edkEnd();
                    }
                }
                else{
                    //else delete the pack
                    delete pack;edkEnd();
                    ret=false;edkEnd();
                }
                pack=NULL;edkEnd();
            }
            else{
                ret=false;edkEnd();
            }
        }
        //if ret is false;edkEnd(); clean the group
        if(!ret){
            this->cleanGroup();edkEnd();
        }
        return ret;
    }
    return false;
}
//delete the vector
void edk::network::PackageGroup::deleteVector(){
    if(this->data){
        free(this->data);edkEnd();
    }
    this->data=NULL;edkEnd();
    this->dataSize=0u;
    this->id=0u;
}

//return the vector
edk::uint8* edk::network::PackageGroup::getVector(){
    return this->data;edkEnd();
}

edk::uint32 edk::network::PackageGroup::getVectorSize(){
    return this->dataSize;edkEnd();
}
//return the ID
edk::uint32 edk::network::PackageGroup::getID(){
    return this->id;edkEnd();
}

//add a package
void edk::network::PackageGroup::addPackageBegin(){
    this->cleanGroup();edkEnd();
    this->deleteVector();edkEnd();
}
bool edk::network::PackageGroup::addPackage(edk::classID vec,edk::uint32 size){
    //test the package
    if(vec && size){
        //test if the pack is the first
        if(!this->tree.size()){
            //test if the package is broked
            if(!edk::network::Package::headerIsBroken(vec)){
                //then save the data
                this->totalSize = edk::network::Package::getHeaderPackages(vec);edkEnd();
                if(totalSize){
                    //save the ID
                    this->id = edk::network::Package::getHeaderId(vec);edkEnd();
                }
                else{
                    edkEnd();
                    return false;
                }
            }
            else{
                edkEnd();
                return false;
            }
        }
        else{
            //else compare the new package with the data
            if(!edk::network::Package::headerIsBroken(vec)){
                //test if the header is diferent
                if(this->totalSize!=edk::network::Package::getHeaderPackages(vec)
                        ||
                        this->id!=edk::network::Package::getHeaderId(vec)
                        )
                    //then return false
                    return false;
            }
            else{
                edkEnd();
                return false;
            }
        }
        //create a new package
        edk::network::Package* pack = new edk::network::Package;edkEnd();

        if(pack){
            //then set the header
            if(pack->addPackage(vec,size)){
                //add the pack on the tree
                if(this->tree.add(pack)){
                    return true;
                }
            }
            delete pack;edkEnd();
        }
    }
    return false;
}
//end the add packages
bool edk::network::PackageGroup::addPackageEnd(){
    //test if the packages are full
    if(this->isPackagesFull()){
        bool ret=true;edkEnd();
        //load the packages size
        edk::uint32 size=0u;
        edk::network::Package* pack=NULL;edkEnd();
        for(edk::uint32 i =0u;i<this->tree.size();i++){
            //load the package
            pack = this->tree.getElementInPosition(i);edkEnd();
            if(pack){
                //increment the size
                size+=pack->getPackageSize();edkEnd();
            }
            else{
                //else clean the size and break
                size=0u;
                ret=false;edkEnd();
                break;
            }
        }

        //test the size
        if(size){
            //create the new vector with the size
            this->deleteVector();edkEnd();
            this->dataSize = size;edkEnd();
            this->data = (edk::uint8*)malloc(sizeof(edk::uint8) * (this->dataSize));edkEnd();
            if(this->data){
                edk::uint32 dataPosition=0u;
                //copy the vectors to the data
                for(edk::uint32 i =0u;i<this->tree.size();i++){
                    //load the package
                    pack = this->tree.getElementInPosition(i);edkEnd();
                    if(pack){
                        //increment the size
                        memcpy(&this->data[dataPosition],pack->getPackageVector(),pack->getPackageSize());edkEnd();
                        //increment dataPosition
                        dataPosition+=pack->getPackageSize();edkEnd();
                    }
                    else{
                        ret=false;edkEnd();
                        break;
                    }
                }
                //test if the ret are false
                if(!ret){
                    //delete the vector
                    this->deleteVector();edkEnd();
                }
            }
            else{
                ret=false;edkEnd();
                this->deleteVector();edkEnd();
            }
        }

        //delete the packages
        this->cleanGroup();edkEnd();
        return ret;
    }
    return false;
}

//test if the packages reach the end
bool edk::network::PackageGroup::isPackagesFull(){
    //test if have totalPackages
    if(this->totalSize){
        //test if on the tree are que total
        if(this->tree.size()==this->totalSize){
            return true;
        }
    }
    return false;
}

//test if have a vector in the position
bool edk::network::PackageGroup::haveVector(edk::uint32 position){
    //test the position
    if(position < this->tree.size()){
        //return if have the vector
        if(this->tree.getElementInPosition(position)){
            return true;
        }
    }
    return false;
}
//get a vector in the group
edk::classID edk::network::PackageGroup::getVector(edk::uint32 position){
    //test the position
    if(position < this->tree.size()){
        //return the vector
        edk::network::Package* pack = this->tree.getElementInPosition(position);edkEnd();
        if(pack){
            return pack->getVec();edkEnd();
        }
    }
    return NULL;
}
edk::uint32 edk::network::PackageGroup::getVectorSize(edk::uint32 position){
    //test the position
    if(position < this->tree.size()){
        //return the vector
        edk::network::Package* pack = this->tree.getElementInPosition(position);edkEnd();
        if(pack){
            return pack->getVecSize();edkEnd();
        }
    }
    return 0u;edkEnd();
}
edk::uint32 edk::network::PackageGroup::getPackageID(edk::uint32 position){
    //test the position
    if(position < this->tree.size()){
        //return the vector
        edk::network::Package* pack = this->tree.getElementInPosition(position);edkEnd();
        if(pack){
            return pack->getID();edkEnd();
        }
    }
    return 0u;edkEnd();
}

//clean the group
void edk::network::PackageGroup::cleanGroup(){
    //delete all packages in the tree
    edk::network::Package* temp=NULL;edkEnd();
    for(register edk::uint32 i=0u;i<this->tree.size();i++){
        temp = this->tree.getElementInPosition(i);edkEnd();
        if(temp){
            delete temp;edkEnd();
        }
        temp=NULL;edkEnd();
    }
    this->tree.clean();edkEnd();
}

//get the tree size
edk::uint32 edk::network::PackageGroup::getPackages(){
    return this->tree.size();edkEnd();
}
//get the total size of packagess
edk::uint32 edk::network::PackageGroup::getTotalPackages(){
    //test if have some package
    if(this->tree.size()){
        //get the first package
        edk::network::Package* pack = this->tree.getElementInPosition(0u);edkEnd();
        if(pack){
            //get the number of packages
            return pack->getPackages();edkEnd();
        }
    }
    return 0u;edkEnd();
}

//read the package size
edk::uint32 edk::network::PackageGroup::readPackageSize(edk::classID vec){
    //test the vector
    if(vec){
        //get the header
        return edk::network::Package::getHeaderFullSize(vec);edkEnd();
    }
    return 0u;edkEnd();
}
