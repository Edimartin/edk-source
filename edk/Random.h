#ifndef RANDOM_H
#define RANDOM_H

/*
Library C++ Random - Generate random numbers using a static mathematic function
Copyright (C) 1013 Eduardo Moura Sales Martins
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
#warning "Inside Random"
#endif

#pragma once
#include "watch/Time.h"

#ifdef printMessages
#warning "    Compiling Random"
#endif

namespace edk{
class Random{
public:
    Random();
    ~Random();

    //set the seed
    static void setSeed(edk::uint32 seed);
    //load the seed
    static edk::uint32 loadSeed();
    //return the seed value
    static edk::uint32 getSeed();
    //get the rand number
    static edk::uint32 getRandNumber();
    static edk::uint32 getRandNumber(edk::uint32 div);
    static edk::float32 getRandPercent();

private:
    //save the seed
    static edk::uint32 seed;
};
}//end namespace edk

#endif // RANDOM_H
