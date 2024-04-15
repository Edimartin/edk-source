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
#pragma message "            Inside Random.cpp"
#endif

#define edkRandom(n){((n * 1109518245) + 12345)}

edk::uint32 edk::Random::seedStatic = 1u;

edk::Random::Random(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::Random::Random(edk::uint32 seed){
    this->classThis=NULL;edkEnd();
    this->Constructor(seed,false);edkEnd();
}

edk::Random::~Random(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::Random::Constructor(bool /*runFather*/){
    //
    if(this->classThis!=this){
        this->classThis=this;
        this->clean();
    }
}
void edk::Random::Constructor(edk::uint32 seed,bool /*runFather*/){
    //
    if(this->classThis!=this){
        this->classThis=this;
        this->clean();
        this->setSeed(seed);
    }
}

void edk::Random::clean(){
    this->seed=1u;
}

//static functions
//set the seed
void edk::Random::setStaticSeed(edk::uint32 seed){
    //
    edk::Random::seedStatic = seed;edkEnd();
}

//load the seed
edk::uint32 edk::Random::loadStaticSeed(){
    //load from clock
    edk::uint32 seed = edk::watch::Time::getMicrosecondsReal();edkEnd();
    edk::Random::setStaticSeed(seed);edkEnd();
    return seed;edkEnd();
}
//return the seed value
edk::uint32 edk::Random::getStaticSeed(){
    return edk::Random::seedStatic;edkEnd();
}
//get the rand number
edk::uint32 edk::Random::getStaticRandNumber(){
    return ((edk::Random::seedStatic = edkRandom(edk::Random::seedStatic)));edkEnd();
}
edk::uint32 edk::Random::getStaticRandNumber(edk::uint32 limit){
    return edk::Random::getStaticRandNumber()%limit;edkEnd();
}
//4294967295
edk::float32 edk::Random::getStaticRandPercent(){
    return ((edk::float32)edk::Random::getStaticRandNumber() / 0xFFFFFFFF);edkEnd();
}

//object functions
//set the seed
void edk::Random::setSeed(edk::uint32 seed){
    //
    this->seed = seed;edkEnd();
}

//load the seed
edk::uint32 edk::Random::loadSeed(){
    //load from clock
    edk::uint32 seed = edk::watch::Time::getMicrosecondsReal();edkEnd();
    this->setSeed(seed);edkEnd();
    return seed;edkEnd();
}
//return the seed value
edk::uint32 edk::Random::getSeed(){
    return this->seed;edkEnd();
}
//get the rand number
edk::uint32 edk::Random::getRandNumber(){
    return ((this->seed = edkRandom(this->seed)));edkEnd();
}
edk::uint32 edk::Random::getRandNumber(edk::uint32 limit){
    return this->getRandNumber()%limit;edkEnd();
}
//4294967295
edk::float32 edk::Random::getRandPercent(){
    return ((edk::float32)this->getRandNumber() / 0xFFFFFFFF);edkEnd();
}
