#ifndef LISTDIRECTORY_H
#define LISTDIRECTORY_H

/*
Library C++ ListDirectory - List files and folders inside a directory
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
#warning "Inside ListDirectory"
#endif

#pragma once
#include <stdio.h>
#include "TypeVars.h"
#include "String.h"
#include <sys/stat.h>
#include <dirent.h>

#ifdef printMessages
#warning "    Compiling ListDirectory"
#endif

namespace edk{
class ListDirectory{
public:
    ListDirectory();
    ~ListDirectory();

    //start listing the folders and files in a directory received by function parameter
    bool run(edk::char8* directory);
    bool run(const edk::char8* directory);

    virtual void listFile(edk::char8* name,edk::uint64 lastModify,edk::uint64 size)=0;
    virtual void listFolder(edk::char8* name,edk::uint64 lastModify,edk::uint64 size)=0;
};
}//end namespace

#endif // LISTDIRECTORY_H
