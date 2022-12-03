#include "Random.h"

/*
Library C++ Random - Generate random numbers using a static mathematic function
Copyright 2013 Eduardo Moura Sales Martins (edimartin@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
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
    return ((edk::float32)edk::Random::getRandNumber() / 0xFFFFFFFF);
}
