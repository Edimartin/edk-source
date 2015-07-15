#include "Texture2DRender.h"

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
#warning "            Inside Texture2DRender.cpp"
#endif

edk::Texture2DRender::Texture2DRender()
{
    //ctor
    this->frameBuffer=0u;
    this->depthBuffer=0u;
    edk::GU_GLSL::guShaderInit();
}

edk::Texture2DRender::~Texture2DRender()
{
    this->deleteRender();
}

//delete the frameBuffer
void edk::Texture2DRender::deleteFrameBuffer(){
    //test if have a frameBuffer
    if(this->frameBuffer){
        //
        edk::GU_GLSL::guDeleteFrameBuffer(this->frameBuffer);
    }
    this->frameBuffer=0u;
}

//load the frameBuffer
bool edk::Texture2DRender::loadFrameBuffer(){
    //test if load GLSL
    if(edk::GU_GLSL::guShaderInitiate()){
        //delete the last frameBuffer
        this->deleteFrameBuffer();

        //alloc the new frameBuffer
        if((this->frameBuffer = edk::GU_GLSL::guAllocFrameBuffer(GU_FRAMEBUFFER))){
            //
            return true;
        }
    }
    //else return false
    return false;
}

//Load the renderTexture
bool edk::Texture2DRender::createRender(edk::size2ui32 size){
    //first load make the texture
    if(this->createTexture(size.width, size.height, GU_RGB, NULL)){
        //create the buffer
        if(this->loadFrameBuffer()){
            this->useThisBuffer();
            //set rendered texture
            edk::GU_GLSL::guFrameBufferTexture(GU_FRAMEBUFFER,GU_COLOR_ATTACHMENT0,this->getID(),0u);
            // Set the list of draw buffers.
            edk::GU_GLSL::guSetDrawBuffer(GU_COLOR_ATTACHMENT0);
            if(edk::GU_GLSL::guCheckFrameBufferOK(GU_FRAMEBUFFER)){
                edk::Texture2DRender::dontUseFrameBuffer();
                //return true
                return true;
            }
            edk::Texture2DRender::dontUseFrameBuffer();
            this->deleteFrameBuffer();
        }
        //else delete the texture
        this->deleteTexture();
    }
    //else return false
    return false;
}
//return the ID
edk::uint32 edk::Texture2DRender::getBufferID(){
    return this->frameBuffer;
}
//use this buffer
void edk::Texture2DRender::useThisBuffer(){
    edk::GU_GLSL::guUseFrameBuffer(GU_FRAMEBUFFER,this->frameBuffer);
}
//dont use frameBuffer
void edk::Texture2DRender::dontUseFrameBuffer(){
    edk::GU_GLSL::guUseFrameBuffer(GU_FRAMEBUFFER,0u);
}

bool edk::Texture2DRender::createRender(edk::uint32 width,edk::uint32 height){
    //
    return this->createRender(edk::size2ui32(width,height));
}
bool edk::Texture2DRender::createRender(edk::int32 width,edk::int32 height){
    //
    return this->createRender(edk::size2ui32((edk::uint32)width,(edk::uint32)height));
}
//delete render
void edk::Texture2DRender::deleteRender(){
    this->deleteFrameBuffer();
    this->deleteTexture();
}
