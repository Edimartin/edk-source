#ifndef OPENLAMP_H
#define OPENLAMP_H

/*
Library C++ OpenLamp - Core functions to the openLamp software to change luminance image to normalMap
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
#warning "Inside OpenLamp"
#endif

#pragma once
#include "TypeColor.h"
#include "Image2D.h"
#include "Math.h"

#ifdef printMessages
#warning "    Compiling OpenLamp"
#endif

namespace edk{
class OpenLamp{
public:
    OpenLamp();

    //convert one pixel
    static edk::color3ui8 pixelToNormal(edk::uint8 up,edk::uint8 down,edk::uint8 left,edk::uint8 right,edk::uint8 front);
    static edk::color3ui8 pixelToNormal(edk::uint8 up,edk::uint8 down,edk::uint8 left,edk::uint8 right);
    //convert the vector
    static bool vectorToNormal(edk::uint8* up,edk::uint8 upChannels,
                               edk::uint8* down,edk::uint8 downChannels,
                               edk::uint8* left,edk::uint8 leftChannels,
                               edk::uint8* right,edk::uint8 rightChannels,
                               edk::uint8* front,edk::uint8 frontChannels,
                               edk::uint8* normal,edk::uint32 pixelsSize
                               );
    static bool imageToNormal(edk::Image2D* up,edk::Image2D* down,edk::Image2D* left,edk::Image2D* right,edk::Image2D* front,edk::Image2D* normal);
};
}//end namespace edk

#endif // OPENLAMP_H
