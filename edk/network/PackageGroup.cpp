#include "PackageGroup.h"

/*
Library PackageGroup - Manage a group of packages to be sended by the edk::Socket
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
    edk::network::Package find;
    find.setHeader(id,0u,id);
    return this->getElement(&find);
}

edk::network::PackageGroup::PackageGroup(){
    //
    this->setPackSize(0u);
    this->data=NULL;
    this->deleteVector();
}
edk::network::PackageGroup::~PackageGroup(){
    //
}
//set the packSize
void edk::network::PackageGroup::setPackSize(edk::uint32 packSize){
    if(packSize){
        this->totalSize = packSize;
    }
    else{
        //else set the normal packSize
        this->totalSize=1000u;
    }
}
//Add the vector to generate the packages
bool edk::network::PackageGroup::addVector(edk::classID vec,edk::uint32 size,edk::uint32 id,edk::uint32 packSize){
    //clean the group
    if(vec && size){
        if(packSize){
            //test if the packSize is diferent
            if(this->totalSize!=packSize)
                this->setPackSize(packSize);
        }
        bool ret=true;
        //get the size of packages
        edk::uint32 total = size / this->totalSize;
        //size of the last package
        edk::uint32 lastSize = size % this->totalSize;

        edk::network::Package* pack=NULL;
        edk::uint8* temp = (edk::uint8*)vec;
        edk::uint32 i=0u;
        edk::uint32 packages = 0u;
        //test the total
        if(total){
            //create the packages
            packages = total;
            //test if have a last package without the full size
            if(lastSize)
                packages++;
            for(i=0u;i<total;i++){
                //create the package
                pack = new edk::network::Package;
                if(pack){
                    //draw in the package
                    if(pack->drawVector(temp,this->totalSize,0u,i,id,packages)){
                        //add the pack in the tree
                        if(!this->tree.add(pack)){
                            delete pack;
                            ret=false;
                            break;
                        }
                    }
                    else{
                        //else delete the pack
                        delete pack;
                        ret=false;
                        break;
                    }
                    temp+=this->totalSize;
                    //clean the pack
                    pack=NULL;
                }
                else{
                    //else get the error
                    ret=false;
                    break;
                }
            }
        }
        else{
            packages = 1u;
        }

        //test the ret and the last package
        if(ret && lastSize){
            //add the last package
            pack = new edk::network::Package;
            if(pack){
                //draw in the package
                if(pack->drawVector(temp,lastSize,this->totalSize,i,id,packages)){
                    //add the pack in the tree
                    if(!this->tree.add(pack)){
                        delete pack;
                        ret=false;
                    }
                }
                else{
                    //else delete the pack
                    delete pack;
                    ret=false;
                }
                pack=NULL;
            }
            else{
                ret=false;
            }
        }
        //if ret is false; clean the group
        if(!ret)
            this->cleanGroup();
        return ret;
    }
    return false;
}
//delete the vector
void edk::network::PackageGroup::deleteVector(){
    if(this->data){
        delete[] this->data;
    }
    this->data=NULL;
    this->dataSize=0u;
    this->id=0u;
}

//return the vector
edk::uint8* edk::network::PackageGroup::getVector(){
    return this->data;
}

edk::uint32 edk::network::PackageGroup::getVectorSize(){
    return this->dataSize;
}
//return the ID
edk::uint32 edk::network::PackageGroup::getID(){
    return this->id;
}

//add a package
void edk::network::PackageGroup::addPackageBegin(){
    this->cleanGroup();
    this->deleteVector();
}
bool edk::network::PackageGroup::addPackage(edk::classID vec,edk::uint32 size){
    //test the package
    if(vec && size){
        //test if the pack is the first
        if(!this->tree.size()){
            //test if the package is broked
            if(!edk::network::Package::headerIsBroken(vec)){
                //then save the data
                this->totalSize = edk::network::Package::getHeaderPackages(vec);
                if(totalSize){
                    //save the ID
                    this->id = edk::network::Package::getHeaderId(vec);
                }
                else return false;
            }
            else return false;
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
            else return false;
        }
        //create a new package
        edk::network::Package* pack = new edk::network::Package;

        if(pack){
            //then set the header
            if(pack->addPackage(vec,size)){
                //add the pack on the tree
                if(this->tree.add(pack)){
                    return true;
                }
            }
            delete pack;
        }
    }
    return false;
}
//end the add packages
bool edk::network::PackageGroup::addPackageEnd(){
    //test if the packages are full
    if(this->isPackagesFull()){
        bool ret=true;
        //load the packages size
        edk::uint32 size=0u;
        edk::network::Package* pack=NULL;
        for(edk::uint32 i =0u;i<this->tree.size();i++){
            //load the package
            pack = this->tree.getElementInPosition(i);
            if(pack){
                //increment the size
                size+=pack->getPackageSize();
            }
            else{
                //else clean the size and break
                size=0u;
                ret=false;
                break;
            }
        }

        //test the size
        if(size){
            //create the new vector with the size
            this->deleteVector();
            this->dataSize = size;
            this->data = new edk::uint8[this->dataSize];
            if(this->data){
                edk::uint32 dataPosition=0u;
                //copy the vectors to the data
                for(edk::uint32 i =0u;i<this->tree.size();i++){
                    //load the package
                    pack = this->tree.getElementInPosition(i);
                    if(pack){
                        //increment the size
                        memcpy(&this->data[dataPosition],pack->getPackageVector(),pack->getPackageSize());
                        //increment dataPosition
                        dataPosition+=pack->getPackageSize();
                    }
                    else{
                        ret=false;
                        break;
                    }
                }
                //test if the ret are false
                if(!ret){
                    //delete the vector
                    this->deleteVector();
                }
            }
            else{
                ret=false;
                this->deleteVector();
            }
        }

        //delete the packages
        this->cleanGroup();
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
        edk::network::Package* pack = this->tree.getElementInPosition(position);
        if(pack){
            return pack->getVec();
        }
    }
    return NULL;
}
edk::uint32 edk::network::PackageGroup::getVectorSize(edk::uint32 position){
    //test the position
    if(position < this->tree.size()){
        //return the vector
        edk::network::Package* pack = this->tree.getElementInPosition(position);
        if(pack){
            return pack->getVecSize();
        }
    }
    return 0u;
}
edk::uint32 edk::network::PackageGroup::getPackageID(edk::uint32 position){
    //test the position
    if(position < this->tree.size()){
        //return the vector
        edk::network::Package* pack = this->tree.getElementInPosition(position);
        if(pack){
            return pack->getID();
        }
    }
    return 0u;
}

//clean the group
void edk::network::PackageGroup::cleanGroup(){
    //delete all packages in the tree
    edk::network::Package* temp=NULL;
    for(register edk::uint32 i=0u;i<this->tree.size();i++){
        temp = this->tree.getElementInPosition(i);
        if(temp){
            delete temp;
        }
        temp=NULL;
    }
    this->tree.clean();
}

//get the tree size
edk::uint32 edk::network::PackageGroup::getPackages(){
    return this->tree.size();
}
//get the total size of packagess
edk::uint32 edk::network::PackageGroup::getTotalPackages(){
    //test if have some package
    if(this->tree.size()){
        //get the first package
        edk::network::Package* pack = this->tree.getElementInPosition(0u);
        if(pack){
            //get the number of packages
            return pack->getPackages();
        }
    }
    return 0u;
}

//read the package size
edk::uint32 edk::network::PackageGroup::readPackageSize(edk::classID vec){
    //test the vector
    if(vec){
        //get the header
        return edk::network::Package::getHeaderFullSize(vec);
    }
    return 0u;
}
