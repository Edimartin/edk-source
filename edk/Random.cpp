#include "Random.h"

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
#warning "            Inside Random.cpp"
#endif

#define edkRandom(n){((n * 1109518245) + 12345)}

edk::uint32 edk::Random::seed = 1u;

edk::Random::Random(){
    //
}

edk::Random::~Random(){
    //
}

//set the seed
void edk::Random::setSeed(edk::uint32 seed){
    //
    edk::Random::seed = seed;
}

//load the seed
edk::uint32 edk::Random::loadSeed(){
    //load from clock
    edk::uint32 seed = edk::watch::Time::getMicrosecondsReal();
    edk::Random::setSeed(seed);
    return seed;
}
//return the seed value
edk::uint32 edk::Random::getSeed(){
    return edk::Random::seed;
}
//get the rand number
edk::uint32 edk::Random::getRandNumber(){
    return ((edk::Random::seed = edkRandom(edk::Random::seed)));
}
edk::uint32 edk::Random::getRandNumber(edk::uint32 limit){
    return edk::Random::getRandNumber()%limit;
}
//4294967295
edk::float32 edk::Random::getRandPercent(){
    return ((edk::float32)edk::Random::getRandNumber() / 4294967295u)*2.f;
}
