#ifndef EDK_TEXTURE2DRENDER_H
#define EDK_TEXTURE2DRENDER_H

/*
Library Texture2DRender -
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
#warning "Inside Texture2DRender"
#endif

#pragma once
#include "GU/GU.h"
#include "Texture2D.h"

#ifdef printMessages
#warning "    Compiling Texture2DRender"
#endif

namespace edk{
class Texture2DRender: public edk::Texture2D{
    public:
        Texture2DRender();
        virtual ~Texture2DRender();

        //Load the renderTexture
        bool createRender(edk::size2ui32 size);
        bool createRender(edk::uint32 width,edk::uint32 height);
        bool createRender(edk::int32 width,edk::int32 height);
        //delete render
        void deleteRender();

        //return the ID
        edk::uint32 getBufferID();

        //use this buffer
        void useThisBuffer();
        //dont use frameBuffer
        static void dontUseFrameBuffer();

    protected:
    private:
    //framebuffer
    edk::uint32 frameBuffer;
    //depthBuffer
    edk::uint32 depthBuffer;

    //delete the frameBuffer
    void deleteFrameBuffer();

    //load the frameBuffer
    bool loadFrameBuffer();
};
}//end namespace

#endif // TEXTURE2DRENDER_H
