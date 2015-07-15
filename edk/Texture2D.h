#ifndef EDK_TEXTURE2D_H
#define EDK_TEXTURE2D_H

/*
Library Texture2D - 2D Textures in GU
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
#warning "Inside Texture2D"
#endif

#pragma once
#include "Types.h"
#include "String.h"
#include "GU/GU.h"
#include "Object.h"

#ifdef printMessages
#warning "    Compiling Texture2D"
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

//defines
#define EDK_RGB  1u
#define EDK_RGBA 2u


//Render to Texture

namespace edk{
class Texture2D: public edk::ObjectWithName{
    public:
        Texture2D();
        virtual ~Texture2D();

        //alloc the textureObject
//        GU_RGB
//        GU_RGBA
//        GU_LUMINANCE
//        GU_LUMINANCE_ALPHA
        bool createTexture(edk::uint32 width, edk::uint32 height, edk::uint32 mode, const edk::classID  data = 0u, edk::uint32 filter = GU_NEAREST);
        //draw to the texture
        bool drawToTexture(const edk::classID  data);
        bool drawToTexture(const edk::classID  data, edk::uint32 filter = GU_NEAREST);

        //GETTERS
        //return the textureID
        edk::uint32 getID();
        size2ui32 getSize();
        uint32 width();
        uint32 height();
        edk::uint32 textureID();

        //DELETE
        //remove the texture
        void deleteTexture();
        //delete the ID
        static void deleteTextureID(edk::uint32 id);


        //Super Class Functions
        //retain
        edk::Texture2D* retainObject(edk::Texture2D** pointer);
        //release
        bool releaseObject(edk::Texture2D** pointer);

        //Save the object
        void saveObject(ObjectWithName** pointer);

        //Clean the object
        void cleanObject(ObjectWithName** pointer);
    protected:
    private:
    //Texture ID
    edk::uint32 textureId;
    //tamanho do sprite
    edk::size2ui32 size;
    //save the mode
    edk::uint32 mode;
    edk::uint32 filter;
};
}//end namespace edk

#endif // TEXTURE2DRENDER_H
