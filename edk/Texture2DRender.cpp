#include "Texture2DRender.h"

/*
Library Texture2DRender -
Copyright (C) 2013 Eduardo Moura Sales Martins
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
#pragma message "            Inside Texture2DRender.cpp"
#endif

edk::Texture2DRender::Texture2DRender()
{
    //ctor
    this->frameBuffer=0u;
    this->depthBuffer=0u;
    edk::GU_GLSL::guShaderInit();edkEnd();
}

edk::Texture2DRender::~Texture2DRender()
{
    this->deleteRender();edkEnd();
}

//delete the frameBuffer
void edk::Texture2DRender::deleteFrameBuffer(){
    //test if have a frameBuffer
    if(this->frameBuffer){
        //
        edk::GU_GLSL::guDeleteFrameBuffer(this->frameBuffer);edkEnd();
    }
    this->frameBuffer=0u;
}

//load the frameBuffer
bool edk::Texture2DRender::loadFrameBuffer(){
    //test if load GLSL
    if(edk::GU_GLSL::guShaderInitiate()){
        //delete the last frameBuffer
        this->deleteFrameBuffer();edkEnd();

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
    if(this->createTexture(size.width, size.height, EDK_RGB, NULL)){
        //create the buffer
        if(this->loadFrameBuffer()){
            this->useThisBuffer();edkEnd();
            //set rendered texture
            edk::GU_GLSL::guFrameBufferTexture(GU_FRAMEBUFFER,GU_COLOR_ATTACHMENT0,this->getID(),0u);edkEnd();
            // Set the list of draw buffers.
            edk::GU_GLSL::guSetDrawBuffer(GU_COLOR_ATTACHMENT0);edkEnd();
            if(edk::GU_GLSL::guCheckFrameBufferOK(GU_FRAMEBUFFER)){
                edk::Texture2DRender::dontUseFrameBuffer();edkEnd();
                //return true
                return true;
            }
            edk::Texture2DRender::dontUseFrameBuffer();edkEnd();
            this->deleteFrameBuffer();edkEnd();
        }
        //else delete the texture
        this->deleteTexture();edkEnd();
    }
    //else return false
    return false;
}
//return the ID
edk::uint32 edk::Texture2DRender::getBufferID(){
    return this->frameBuffer;edkEnd();
}
//use this buffer
void edk::Texture2DRender::useThisBuffer(){
    edk::GU_GLSL::guUseFrameBuffer(GU_FRAMEBUFFER,this->frameBuffer);edkEnd();
}
//dont use frameBuffer
void edk::Texture2DRender::dontUseFrameBuffer(){
    edk::GU_GLSL::guUseFrameBuffer(GU_FRAMEBUFFER,0u);edkEnd();
}

bool edk::Texture2DRender::createRender(edk::uint32 width,edk::uint32 height){
    //
    return this->createRender(edk::size2ui32(width,height));edkEnd();
}
bool edk::Texture2DRender::createRender(edk::int32 width,edk::int32 height){
    //
    return this->createRender(edk::size2ui32((edk::uint32)width,(edk::uint32)height));edkEnd();
}
//delete render
void edk::Texture2DRender::deleteRender(){
    this->deleteFrameBuffer();edkEnd();
    this->deleteTexture();edkEnd();
}
