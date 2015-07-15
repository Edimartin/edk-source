#ifndef EDK_TEXTURE2DFILE_H
#define EDK_TEXTURE2DFILE_H

/*
Library Texture2DFile - Load a 2D Image to a texture
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

    protected:
    private:
    //Image to have texture
    edk::Image2D image;
};
}//endNamespace

#endif // TEXTURE2D_H
