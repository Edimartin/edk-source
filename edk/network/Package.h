#ifndef PACKAGE_H
#define PACKAGE_H

/*
Library Package - Package to be sended by the edk::Socket
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

#pragma once
#include "../TypeVars.h"
#include <stdio.h>
#include <string.h>

namespace edk{
namespace network{
class Package{
public:
    Package();
    ~Package();

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
    //get the position by the header
    static edk::uint32 getHeaderPosition(edk::classID vec);
    //get the ID by the header
    static edk::uint32 getHeaderId(edk::classID vec);
    //get the packages by the header
    static edk::uint32 getHeaderPackages(edk::classID vec);

private:
    class PackHeader{
    public:
        PackHeader(){this->clean();}
        //static value to test broken packages
        edk::uint64 broke;
        edk::uint32 size;//size of the package without the header
        edk::uint32 id;//number of the packet
        edk::uint32 position;//number of the packet
        edk::uint32 packages;//number of all packets
        //test if is a valid package
        bool isBroken(){
            if(this->broke == 0xAA9966557BDE8421) return false;
            return true;
        }
        //clean the header
        void clean(){this->size=0u;this->id=0u;this->position=0u;this->packages=0u;this->broke = 0xAA9966557BDE8421;}
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
};
}//end namespace network
}//end namespace edk

#endif // PACKAGE_H
