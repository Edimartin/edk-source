#ifndef FILETOH_H
#define FILETOH_H

/*
Library FileToH - Write a bin file to a H header
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
#warning "Inside FileToH"
#endif

#pragma once
//include file
#include "File.h"
#include "string.h"

#ifdef printMessages
#warning "    Compiling FileToH"
#endif

namespace edk{
class FileToH{
public:
    FileToH();
    static bool writeToFile(edk::char8* fileName,edk::uint32 lineSize);
    static bool writeToFile(const edk::char8* fileName,edk::uint32 lineSize);
    static bool writeToEDKFile(edk::char8* fileName,edk::uint32 lineSize);
    static bool writeToEDKFile(const edk::char8* fileName,edk::uint32 lineSize);
//private:
    //read the name without the extension
    static edk::char8* readFileName(edk::char8* fileName);
};
}//edn namespace edk

#endif // FILETOH_H
