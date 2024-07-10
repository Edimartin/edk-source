#ifndef PACKAGE_H
#define PACKAGE_H

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

#ifdef printMessages
#pragma message "Inside Package"
#endif

#pragma once
#include "../TypeVars.h"
#include "../DebugFile.h"
#include <stdio.h>
#include <string.h>

#ifdef printMessages
#pragma message "    Compiling Package"
#endif

namespace edk{
namespace network{
class Package{
public:
    Package();
    virtual ~Package();

    void Constructor(bool runFather=true);

    //delete the vector
    void deleteVector();
    //copy a vector to the package
    bool drawVector(edk::classID vec,edk::uint32 size,edk::uint32 vecSize=0u);
    bool drawVector(edk::classID vec,edk::uint32 size,edk::uint32 vecSize,edk::uint32 position,edk::uint32 id,edk::uint32 total);
    //add the vector with the header
    bool addPackage(edk::classID vec,edk::uint32 size);
    //set the package header
    void setHeader(edk::uint32 position,edk::uint32 id,edk::uint32 total);
    void setHeader(edk::classID vec);

    //return the id of the packet
    edk::uint32 getID();
    //return the position of the packet
    edk::uint32 getPosition();
    //get the total number of packages
    edk::uint32 getPackages();
    //return the size of the package
    edk::uint32 getPackageSize();
    //return the vector
    edk::uint8* getVec();
    edk::uint8* getPackageVector();
    edk::uint32 getVecSize();

    //test if the header is broked
    static bool headerIsBroken(edk::classID vec);
    //get the full size by the header
    static edk::uint32 getHeaderFullSize(edk::classID vec);
    //get the position by the header
    static edk::uint32 getHeaderPosition(edk::classID vec);
    //get the ID by the header
    static edk::uint32 getHeaderId(edk::classID vec);
    //get the packages by the header
    static edk::uint32 getHeaderPackages(edk::classID vec);

private:
    class PackHeader{
    public:
        PackHeader(){this->clean();edkEnd();}
        //static value to test broken packages
        edk::uint64 broke;
        edk::uint32 size;//size of the package without the header
        edk::uint32 id;//number of the packet
        edk::uint32 position;//number of the packet
        edk::uint32 packages;//number of all packets
        //test if is a valid package
        bool isBroken(){
            if(this->broke == 0xAA9966557BDE8421){
                return false;
            }
            return true;
        }
        //clean the header
        void clean(){this->size=0u;edkEnd();this->id=0u;edkEnd();this->position=0u;edkEnd();this->packages=0u;edkEnd();this->broke = 0xAA9966557BDE8421;edkEnd();}
    }header;
    //vector
    edk::uint8 *vec;
    //size if the vector
    edk::uint32 vectorSize;
    //size of the header
    edk::uint32 headerSize;

    //create a new package
    bool newVector(edk::uint32 size);
    //update the header to the vector
    bool updateVector();
private:
    edk::classID classThis;
};
}//end namespace network
}//end namespace edk

#endif // PACKAGE_H
