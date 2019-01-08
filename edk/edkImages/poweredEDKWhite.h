#ifndef poweredEDKWhite_H
#define poweredEDKWhite_H

/*
Library C++ poweredEDKColor - Image with powered by edk technology for be used in background in white.
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
#warning "Inside poweredEDKColor"
#endif

#pragma once
#include "../TypeVars.h"

#ifdef printMessages
#warning "    Compiling poweredEDKColor"
#endif

namespace edk{
class poweredEDKWhite{
public:
    static edk::uint32 size;
    static edk::char8 name[20u];
    static edk::uchar8 vec[81722u];
};
}

#endif
