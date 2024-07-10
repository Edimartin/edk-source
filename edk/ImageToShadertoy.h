#ifndef IMAGETOSHADER_H
#define IMAGETOSHADER_H

/*
Library ImageToShadertoy - Write an image into a frag shadertoy
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
#pragma message "Inside ImageToShader"
#endif

#pragma once
//include file
#include "File.h"
#include "string.h"
#include "FileToH.h"
#include "Image2D.h"

#ifdef printMessages
#pragma message "    Compiling ImageToShader"
#endif

namespace edk{
class ImageToShadertoy : private edk::FileToH{
public:
    ImageToShadertoy();
    virtual ~ImageToShadertoy();

    void Constructor(bool runFather=true);
    //
    static bool writeToFile(edk::char8* imageName,edk::uint32 lineSize);
    static bool writeToFile(const edk::char8* imageName,edk::uint32 lineSize);
    static bool writeToEDKFile(edk::char8* imageName,edk::uint32 lineSize);
    static bool writeToEDKFile(const edk::char8* imageName,edk::uint32 lineSize);
private:
    edk::classID classThis;
};
}

#endif // IMAGETOSHADER_H
