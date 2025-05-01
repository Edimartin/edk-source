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
#define edkEven(n) ((n<<((sizeof(n)*8u)-1u))==0u)

edk::uint32 edk::Random::seedStatic = 1u;

edk::Random::Random(){
    this->classThis=NULL;
    this->Constructor();
}
edk::Random::Random(edk::uint32 seed){
    this->classThis=NULL;
    this->Constructor(seed);
}

edk::Random::~Random(){
    this->Destructor();
}

void edk::Random::Constructor(){
    //
    if(this->classThis!=this){
        this->classThis=this;
        this->clean();
    }
}
void edk::Random::Constructor(edk::uint32 seed){
    //
    if(this->classThis!=this){
        this->classThis=this;
        this->clean();
        this->setSeed(seed);
    }
}
void edk::Random::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
}

void edk::Random::clean(){
    this->seed=1u;
}

//static functions
//set the seed
void edk::Random::setStaticSeed(edk::uint32 seed){
    //
    edk::Random::seedStatic = seed;
}

//load the seed
edk::uint32 edk::Random::loadStaticSeed(){
    //load from clock
    edk::uint32 seed = edk::watch::Time::getMicrosecondsReal();
    edk::Random::setStaticSeed(seed);
    return seed;
}
//return the seed value
edk::uint32 edk::Random::getStaticSeed(){
    return edk::Random::seedStatic;
}
//get the rand number
edk::uint32 edk::Random::getStaticRandNumber(){
    return ((edk::Random::seedStatic = edkRandom(edk::Random::seedStatic)));
}
edk::uint32 edk::Random::getStaticRandNumber(edk::uint32 limit){
    if(limit){
        return edk::Random::getStaticRandNumber()%limit;
    }
    return 0u;
}
edk::uint32 edk::Random::getStaticRandNumberDifferent(edk::uint32 value){
    edk::uint32 ret;
    edk::uint8 counter=0u;
    do{
        ret = edk::Random::getStaticRandNumber();
        if(counter>10){
            ret++;
            edk::Random::setStaticSeed(ret);
            break;
        }
        counter++;
    }while(ret==value);
    return ret;
}
edk::uint32 edk::Random::getStaticRandNumberDifferent(edk::uint32 value,edk::uint32 div){
    edk::uint32 ret;
    edk::uint32 temp;
    edk::uint8 counter=0u;
    do{
        temp = edk::Random::getStaticRandNumber();
        ret = temp%div;
        if(counter>10){
            temp++;
            edk::Random::setStaticSeed(temp);
            ret = temp%div;
            break;
        }
        counter++;
    }while(ret==value);
    return ret;
}
//4294967295
edk::float32 edk::Random::getStaticRandPercent(){
    return ((edk::float32)edk::Random::getStaticRandNumber() / 0xFFFFFFFF);
}
//get the boolean rand
bool edk::Random::getStaticRandBoolean(){
    edk::uint8 value = edk::Random::getStaticRandNumber(8u);
    switch(value){
    case 0u:
        return true;
        break;
    case 1u:
        return false;
        break;
    case 2u:
        return true;
        break;
    case 3u:
        return true;
        break;
    case 4u:
        return false;
        break;
    case 5u:
        return false;
        break;
    case 6u:
        return false;
        break;
    case 7u:
        return true;
        break;
    default:
        return false;
        break;
    }
    return false;
}

//object functions
//set the seed
void edk::Random::setSeed(edk::uint32 seed){
    //
    this->seed = seed;
}

//load the seed
edk::uint32 edk::Random::loadSeed(){
    //load from clock
    edk::uint32 seed = edk::watch::Time::getMicrosecondsReal();
    this->setSeed(seed);
    return seed;
}
//return the seed value
edk::uint32 edk::Random::getSeed(){
    return this->seed;
}
//get the rand number
edk::uint32 edk::Random::getRandNumber(){
    return ((this->seed = edkRandom(this->seed)));
}
edk::uint32 edk::Random::getRandNumber(edk::uint32 div){
    if(div){
        return this->getRandNumber()%div;
    }
    return 0u;
}
edk::uint32 edk::Random::getRandNumberDifferent(edk::uint32 value){
    edk::uint32 ret;
    edk::uint8 counter=0u;
    do{
        ret = this->getRandNumber();
        if(counter>10){
            ret++;
            this->setSeed(ret);
            break;
        }
        counter++;
    }while(ret==value);
    return ret;
}
edk::uint32 edk::Random::getRandNumberDifferent(edk::uint32 value,edk::uint32 div){
    edk::uint32 ret;
    edk::uint32 temp;
    edk::uint8 counter=0u;
    do{
        this->seed*=edk::watch::Time::getMicrosecondsReal();
        temp = this->getRandNumber();
        ret = temp%div;
        if(counter>10){
            temp++;
            this->setSeed(temp);
            ret = temp%div;
            break;
        }
        counter++;
    }while(ret==value);
    return ret;
}
//4294967295
edk::float32 edk::Random::getRandPercent(){
    return ((edk::float32)this->getRandNumber() / 0xFFFFFFFF);
}
//get the boolean rand
bool edk::Random::getRandBoolean(){
    edk::uint8 value = this->getRandNumber(8u);
    switch(value){
    case 0u:
        return true;
        break;
    case 1u:
        return false;
        break;
    case 2u:
        return true;
        break;
    case 3u:
        return true;
        break;
    case 4u:
        return false;
        break;
    case 5u:
        return false;
        break;
    case 6u:
        return false;
        break;
    case 7u:
        return true;
        break;
    default:
        return false;
        break;
    }
    return false;
}
