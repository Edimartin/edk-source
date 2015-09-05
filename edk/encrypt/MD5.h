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

#ifdef printMessages
#warning "    Compiling MD5"
#endif

#pragma once
#include "../TypeVars.h"
#include <stdio.h>
#ifndef __cplusplus
#include <stdlib.h>
#endif
#include <string.h>

namespace edk{
namespace encrypt{
class MD5{
public:
    MD5();
    ~MD5();

    //processa o MD5
    static bool md5(edk::uchar8 *pass, edk::uint32 size, edk::uchar8 *dest);
    static edk::uchar8* md5(edk::uchar8 *pass, edk::uint32 size);
};
}//end namespace encrypt
}//end namespace edk

#endif // MD5_H
