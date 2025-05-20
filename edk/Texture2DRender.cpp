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

edk::Texture2DRender::Texture2DRender(){
    this->classThis=NULL;
    this->Constructor();
}

edk::Texture2DRender::~Texture2DRender(){
    this->Destructor();
}

void edk::Texture2DRender::Constructor(){
    edk::Texture2D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        this->frameBuffer=0u;
        this->depthBuffer=0u;
        edk::GU_GLSL::guShaderInit();
    }
}
void edk::Texture2DRender::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->deleteRender();
    }
    edk::Texture2D::Destructor();
    //edk::GU_GLSL::Destructor();
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
    if(edk::GU_GLSL::guShaderInitiated()){
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
bool edk::Texture2DRender::createRender(edk::size2ui32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    //first load make the texture
    if(this->createTexture(size.width, size.height, EDK_RGB, NULL,minFilter,magFilter)){
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
//use this frameBuffer
void edk::Texture2DRender::useThisBuffer(){
    edk::GU_GLSL::guUseFrameBuffer(GU_FRAMEBUFFER,this->frameBuffer);
}
//dont use frameBuffer
void edk::Texture2DRender::dontUseFrameBuffer(){
    edk::GU_GLSL::guUseFrameBuffer(GU_FRAMEBUFFER,0u);
}
//dont use this frameBuffer
void edk::Texture2DRender::dontUseThisFrameBuffer(){
    edk::Texture2DRender::dontUseFrameBuffer();
}

bool edk::Texture2DRender::createRender(edk::uint32 width,edk::uint32 height,edk::uint32 minFilter,edk::uint32 magFilter){
    //
    return this->createRender(edk::size2ui32(width,height),minFilter,magFilter);
}
bool edk::Texture2DRender::createRender(edk::int32 width,edk::int32 height,edk::uint32 minFilter,edk::uint32 magFilter){
    //
    return this->createRender(edk::size2ui32((edk::uint32)width,(edk::uint32)height),minFilter,magFilter);
}
//delete render
void edk::Texture2DRender::deleteRender(){
    this->deleteFrameBuffer();
    this->deleteTexture();
}
