#ifndef MD5_H
#define MD5_H

/*
Library C++ MD5 - Encrypt string in MD5
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
#warning "Inside MD5"
#endif

#pragma once
#include "../TypeVars.h"
#include <stdio.h>
#ifndef __cplusplus
#include <stdlib.h>
#endif
#include <string.h>
#include "../String.h"
#include "../File.h"

#ifdef printMessages
#warning "    Compiling MD5"
#endif

namespace edk{
namespace encrypt{
class MD5{
public:
    MD5();
    ~MD5();

    //processa o MD5
    static bool convertTo(edk::char8 *pass, edk::uint32 size, edk::char8 *dest);
    static bool convertTo(const edk::char8 *pass, edk::uint32 size, edk::char8 *dest);
    static bool convertTo(edk::char8 *pass, edk::char8 *dest);
    static bool convertTo(const edk::char8 *pass, edk::char8 *dest);
    static bool convertFileTo(edk::File* file, edk::char8 *dest);
    static bool convertFileTo(edk::char8 *fileName, edk::char8 *dest);
    static bool convertFileTo(const edk::char8 *fileName, edk::char8 *dest);
    static bool convertTo(edk::char8 *pass, edk::uint32 size, edk::uint8 dest[16u]);
    static bool convertTo(const edk::char8 *pass, edk::uint32 size, edk::uint8 dest[16u]);
    static bool convertTo(edk::char8 *pass, edk::uint8 dest[16u]);
    static bool convertTo(const edk::char8 *pass, edk::uint8 dest[16u]);
    static bool convertFileTo(edk::File* file, edk::uint8 dest[16u]);
    static bool convertFileTo(edk::char8 *fileName, edk::uint8 dest[16u]);
    static bool convertFileTo(const edk::char8 *fileName, edk::uint8 dest[16u]);
    static edk::char8* convert(edk::char8 *pass, edk::uint32 size);
    static edk::char8* convert(const edk::char8 *pass, edk::uint32 size);
    static edk::char8* convert(edk::char8 *pass);
    static edk::char8* convert(const edk::char8 *pass);
    static edk::char8* convertFile(edk::File* file);
    static edk::char8* convertFile(edk::char8 *fileName);
    static edk::char8* convertFile(const edk::char8 *fileName);
};
}//end namespace encrypt
}//end namespace edk

#endif // MD5_H
