#ifndef FILENODE_H
#define FILENODE_H

/*
FileNode - Node used in FilePackage with the Name, position and size of the file inside the package.
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
#warning "Inside pack::FileNode"
#endif

#pragma once
#include "../NameClass.h"
#include "../TypeVars.h"
#include "../File.h"

#ifdef printMessages
#warning "    Compiling pack::FileNode"
#endif

namespace edk{
namespace pack{
class FileNode{
public:
    FileNode();
    virtual ~FileNode();

    //set the fileName
    bool setFileName(edk::char8* str);
    bool setFileName(const edk::char8* str);
    //return the fileName
    edk::char8* getFileName();
    edk::char8* getStrName();
    //clean the name
    void cleanName();
    void clean();

    void setPosition(edk::uint64 position);
    edk::uint64 getPosition();
    void setFileSize(edk::uint64 fileSize);
    edk::uint64 getFileSize();

    //return the size of the node
    edk::uint64 getSize();
    edk::uint64 size();

    //return true if this fileNode is bigger then the other node
    bool biggerThan(edk::pack::FileNode* node);
    bool equalThan(edk::pack::FileNode* node);

    void print();

    //write the node to the file
    bool writeFile(edk::File* file);
    bool readFile(edk::File* file);
private:
    edk::Name str;
    edk::Name fileName;
    edk::uint64 position;
    edk::uint64 fileSize;
};
}
}

#endif // FILENODE_H
