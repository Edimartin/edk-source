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
#pragma message "Inside Texture2DFile"
#endif

#pragma once
#include "GU/GU.h"
#include "Image2D.h"
#include "Types.h"
#include "String.h"
#include "Object.h"
#include "Texture2D.h"
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
#include "DebugLineFile.h"
#endif

#ifdef printMessages
#pragma message "    Compiling Texture2DFile"
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
    virtual ~Texture2DFile();

    void Constructor();
    void Constructor(edk::char8 *textureFileName);
    void Constructor(const char *textureFileName);
    void Destructor();

    //set the debugFile Name
    static bool createDebugFile(const edk::char8* name);
    static bool createDebugFile(edk::char8* name);
    //close the debug file to not write the file
    static void closeDebugFile();

    //LOAD
    bool loadFromFile(edk::char8 *fileName,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadFromFile(const char *fileName,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //LOAD from memory
    bool loadFromMemory(edk::uint8* image,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //SERT from memory
    bool setFromMemory(edk::uint8* image,
                       edk::uint32 width,
                       edk::uint32 height,
                       edk::uint32 channels,
                       edk::uint32 minFilter = GU_LINEAR,
                       edk::uint32 magFilter = GU_NEAREST
            );
    //LOAD
    bool loadFromFileRepeat(edk::char8 *fileName,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadFromFileRepeat(const char *fileName,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //LOAD from memory
    bool loadFromMemoryRepeat(edk::uint8* image,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //SERT from memory
    bool setFromMemoryRepeat(edk::uint8* image,
                             edk::uint32 width,
                             edk::uint32 height,
                             edk::uint32 channels,
                             edk::uint32 minFilter = GU_LINEAR,
                             edk::uint32 magFilter = GU_NEAREST
            );

protected:
private:
    //Image to have texture
    edk::Image2D image;
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
    static edk::DebugLineFile debugFile;
    static edk::multi::Mutex debugMut;
    static bool templateConstructNeed;
#endif

#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
    //write some command in the debugFile
    inline void writeDebug(edk::char8* text,edk::int32 line,edk::char8* file,edk::char8* function){
        edk::Texture2DFile::debugMut.lock();
        edk::Texture2DFile::debugFile.writeDebug(text,line,file,function);
        edk::Texture2DFile::debugMut.unlock();
    }
    inline void writeDebug(const edk::char8* text,edk::int32 line,const edk::char8* file,const edk::char8* function){
        this->writeDebug((edk::char8*) text,line,(edk::char8*) file,(edk::char8*) function);
    }
#endif
private:
    edk::classID classThis;
};
}//endNamespace

#endif // TEXTURE2D_H
