#ifndef EDK_TEXTURE2DFILE_H
#define EDK_TEXTURE2DFILE_H

/*
Library Texture2DFile - Load a 2D Image to a texture
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
#warning "Inside Texture2DFile"
#endif

#pragma once
#include "GU/GU.h"
#include "Image2D.h"
#include "Types.h"
#include "String.h"
#include "Object.h"
#include "Texture2D.h"

#ifdef printMessages
#warning "    Compiling Texture2DFile"
#endif

/*LIB LINUX

-lsfml-graphics
-lGL
-lGLU

*/

/*LIB WINDOWS 32

-lsfml-graphics
-lopengl32
-lglu32

*/

/*

Texture2D open a 2DImage and load to videoBoard

*/


#if defined(__arch64__) || defined(_LP64)
    //64 BITS
#else
    //32 BITS
#endif

namespace edk{
class Texture2DFile: public edk::Texture2D{
    public:
        Texture2DFile();
        Texture2DFile(edk::char8 *textureFileName);
        Texture2DFile(const char *textureFileName);
        ~Texture2DFile();

        //LOAD
        bool loadFromFile(edk::char8 *fileName,edk::uint32 filter = GU_NEAREST);
        bool loadFromFile(const char *fileName,edk::uint32 filter = GU_NEAREST);
        //LOAD from memory
        bool loadFromMemory(edk::uint8* image,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
        //SERT from memory
        bool setFromMemory(edk::char8 *fileName,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 filter = GU_NEAREST);
        bool setFromMemory(const edk::char8 *fileName,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 filter = GU_NEAREST);

    protected:
    private:
    //Image to have texture
    edk::Image2D image;
};
}//endNamespace

#endif // TEXTURE2D_H
