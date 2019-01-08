#ifndef PACKAGEGROUP_H
#define PACKAGEGROUP_H

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

#ifdef printMessages
#warning "Inside PackageGroup"
#endif

#pragma once
#include "Package.h"
#include "../vector/BinaryTree.h"

#ifdef printMessages
#warning "    Compiling PackageGroup"
#endif

namespace edk{
namespace network{
class PackageGroup{
public:
    PackageGroup();
    ~PackageGroup();
    //set the packSize
    void setPackSize(edk::uint32 packSize);

    //Add the vector to generate the packages
    bool addVector(edk::classID vec,edk::uint32 size,edk::uint32 id,edk::uint32 packSize=0u);
    //delete the vector
    void deleteVector();

    //return the vector
    edk::uint8* getVector();
    edk::uint32 getVectorSize();
    //return the ID
    edk::uint32 getID();

    //start cleaning the tree
    void addPackageBegin();
    //add a package
    bool addPackage(edk::classID vec,edk::uint32 size);
    //end the add packages
    bool addPackageEnd();

    //test if the packages reach the end
    bool isPackagesFull();

    //test if have a vector in the position
    bool haveVector(edk::uint32 position);
    //get a vector in the group
    edk::classID getVector(edk::uint32 position);
    edk::uint32 getVectorSize(edk::uint32 position);
    edk::uint32 getPackageID(edk::uint32 position);

    //clean the group
    void cleanGroup();

    //get the tree size
    edk::uint32 getPackages();
    //get the total size of packagess
    edk::uint32 getTotalPackages();

    //read the package size
    static edk::uint32 readPackageSize(edk::classID vec);

private:
    //packages tree
    class PackageTree:public edk::vector::BinaryTree<edk::network::Package*>{
    public:
        PackageTree();
        ~PackageTree();
        //compare if the value is bigger
        bool firstBiggerSecond(edk::network::Package* first,edk::network::Package* second);
        bool firstEqualSecond(edk::network::Package* first,edk::network::Package* second);
        //get the pachage
        edk::network::Package* getPackage(edk::uint32 id);
    }tree;

    edk::uint8* data;
    edk::uint32 dataSize;
    //number total of packages
    edk::uint32 totalSize;
    //save the package ID
    edk::uint32 id;
};
}//end namespace network
}//end namespace edk

#endif // PACKAGEGROUP_H
