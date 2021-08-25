#ifndef PACKAGEGROUP_H
#define PACKAGEGROUP_H

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
