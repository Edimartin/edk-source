#include "ViewGUTexture.h"

/*
Library C++ ViewGUTexture - View to write the scene in a texture.
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

edk::ViewGUTexture::ViewGUTexture(edk::size2ui32 size){
    //load the texture
    this->render.createRender(size);edkEnd();
}
edk::ViewGUTexture::ViewGUTexture(edk::uint32 width,edk::uint32 height){
    //
    this->render.createRender(width,height);edkEnd();
}
edk::ViewGUTexture::~ViewGUTexture(){
    //delete render
    this->render.deleteRender();edkEnd();
}

//set the new size of the texture
bool edk::ViewGUTexture::setTextureSize(edk::size2ui32 size){
    return this->render.createRender(size);edkEnd();
}
bool edk::ViewGUTexture::setTextureSize(edk::uint32 width,edk::uint32 height){
    //
    return this->setTextureSize(edk::size2ui32(width,height));edkEnd();
}
//return the textureSize
edk::size2ui32 edk::ViewGUTexture::getTextureSize(){
    return this->render.getSize();edkEnd();
}
edk::uint32 edk::ViewGUTexture::getTextureWidth(){
    return this->render.getSize().width;edkEnd();
}
edk::uint32 edk::ViewGUTexture::getTextureHeight(){
    return this->render.getSize().height;edkEnd();
}
//return the texture mode
edk::uint32 edk::ViewGUTexture::getTextureModeEDK(){
    return this->render.getModeEDK();edkEnd();
}
edk::uint32 edk::ViewGUTexture::getTextureModeGU(){
    return this->render.getModeGU();edkEnd();
}

void edk::ViewGUTexture::draw(rectf32 outsideViewOrigin){
    //test if it's not hided
    if(!this->hide){
        //test if are using the modelView
        if(!edk::GU::guUsingMatrix(GU_MODELVIEW)){
            edk::GU::guUseMatrix(GU_MODELVIEW);edkEnd();
        }

        //use the renderBuffer
        this->render.useThisBuffer();edkEnd();

        //draw bufferViewPort
        edk::GU::guSetViewport(0u
                             ,0u
                             ,this->render.getSize().width
                             ,this->render.getSize().height
                             );edkEnd();
        edk::GU::guColor4f32(this->backgroundColor);edkEnd();
        //set backGround Color

        //draw the viewCamera
        this->drawCamera();edkEnd();

        //draw the polygon in the view
        this->drawPolygon(outsideViewOrigin);edkEnd();

        //remove the renderBuffer
        edk::Texture2DRender::dontUseFrameBuffer();edkEnd();





        //Now draw the scene with the texture
        //Then draw
        this->drawViewport(outsideViewOrigin);edkEnd();
        //
        edk::GU::guColor3f32(1,1,1);edkEnd();

        //use the shader program
        this->shader.useThisShader();edkEnd();

        //set the camera position
        edk::GU::guUseMatrix(GU_PROJECTION);edkEnd();
        //Load the identity
        edk::GU::guLoadIdentity();edkEnd();
        //Set the ortho camera
        edk::GU::guUseOrtho(0,1,0,1,-1,1);edkEnd();

        //set the matrix before draw the scene
        edk::GU::guUseMatrix(GU_MODELVIEW);edkEnd();
        //use texture
        edk::GU::guEnable(GU_TEXTURE_2D);edkEnd();
        //set the texture
        edk::GU::guUseTexture2D(this->render.getID());edkEnd();

        //render the polygon

        //Draw a quadrangle
        edk::GU::guBegin(GU_QUADS);edkEnd();
            edk::GU::guVertexTex2f32(0.f, 0.f);edkEnd();
            edk::GU::guVertex3f32(0.f, 0.f, 0.f);edkEnd();

            edk::GU::guVertexTex2f32(0.f, 1.f);edkEnd();
            edk::GU::guVertex3f32(0.f, 1.f, 0.f);edkEnd();

            edk::GU::guVertexTex2f32(1.f, 1.f);edkEnd();
            edk::GU::guVertex3f32(1.f, 1.f, 0.f);edkEnd();

            edk::GU::guVertexTex2f32(1.f, 0.f);edkEnd();
            edk::GU::guVertex3f32(1.f, 0.f, 0.f);edkEnd();
        edk::GU::guEnd();edkEnd();

        edk::GU::guUseTexture2D(0u);edkEnd();

        edk::GU::guDisable(GU_TEXTURE_2D);edkEnd();

        //remove the shader program
        this->shader.useNoShader();edkEnd();

        //remove the buffer
        this->render.dontUseFrameBuffer();edkEnd();

        this->drawViewInside();edkEnd();
    }
}
//read from the texture
bool edk::ViewGUTexture::read(const edk::classID  data,edk::uint32 format){
    return this->render.readFromTexture(data,format);edkEnd();
}
