#ifndef RANDOM_H
#define RANDOM_H

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
