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
    this->classThis=NULL;
    this->Constructor(size);
}
edk::ViewGUTexture::ViewGUTexture(edk::uint32 width,edk::uint32 height){
    this->classThis=NULL;
    this->Constructor(width,height);
}
edk::ViewGUTexture::~ViewGUTexture(){
    this->Destructor();
}

void edk::ViewGUTexture::Constructor(edk::size2ui32 size){
    edk::ViewGU::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->shader.Constructor();
        this->render.Constructor();
        this->renderCamera.Constructor();

        //load the texture
        this->render.createRender(size);
    }
}
void edk::ViewGUTexture::Constructor(edk::uint32 width,edk::uint32 height){
    edk::ViewGU::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->shader.Constructor();
        this->render.Constructor();
        this->renderCamera.Constructor();

        this->render.createRender(width,height);
    }
}
void edk::ViewGUTexture::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        //delete render
        this->render.deleteRender();

        this->shader.Destructor();
        this->render.Destructor();
        this->renderCamera.Destructor();
    }
    edk::ViewGU::Destructor();
}

//set the new size of the texture
bool edk::ViewGUTexture::setTextureSize(edk::size2ui32 size){
    return this->render.createRender(size,GU_NEAREST);
}
bool edk::ViewGUTexture::setTextureSize(edk::uint32 width,edk::uint32 height){
    //
    return this->setTextureSize(edk::size2ui32(width,height));
}
//return the textureSize
edk::size2ui32 edk::ViewGUTexture::getTextureSize(){
    return this->render.getSize();
}
edk::uint32 edk::ViewGUTexture::getTextureWidth(){
    return this->render.getSize().width;
}
edk::uint32 edk::ViewGUTexture::getTextureHeight(){
    return this->render.getSize().height;
}
//return the texture mode
edk::uint32 edk::ViewGUTexture::getTextureModeEDK(){
    return this->render.getModeEDK();
}
edk::uint32 edk::ViewGUTexture::getTextureModeGU(){
    return this->render.getModeGU();
}

void edk::ViewGUTexture::draw(rectf32 outsideViewOrigin){
    //test if it's not hided
    if(!this->hide){
        //test if are using the modelView
        if(!edk::GU::guUsingMatrix(GU_MODELVIEW)){
            edk::GU::guUseMatrix(GU_MODELVIEW);
        }

        //use the renderBuffer
        this->render.useThisBuffer();

        //draw bufferViewPort
        edk::GU::guSetViewport(0u
                               ,0u
                               ,this->render.getSize().width
                               ,this->render.getSize().height
                               );
        edk::GU::guColor4f32(this->backgroundColor);
        //set backGround Color

        //draw the viewCamera
        this->drawCamera();

        //draw the polygon in the view
        this->drawPolygon(outsideViewOrigin);

        //remove the renderBuffer
        edk::Texture2DRender::dontUseFrameBuffer();





        //Now draw the scene with the texture
        //Then draw
        this->drawViewport(outsideViewOrigin);
        //
        edk::GU::guColor3f32(1,1,1);

        //use the shader program
        this->shader.useThisShader();

        //set the camera position
        edk::GU::guUseMatrix(GU_PROJECTION);
        //Load the identity
        edk::GU::guLoadIdentity();
        //Set the ortho camera
        edk::GU::guUseOrtho(0,1,0,1,-1,1);

        //set the matrix before draw the scene
        edk::GU::guUseMatrix(GU_MODELVIEW);
        //use texture
        edk::GU::guEnable(GU_TEXTURE_2D);
        //set the texture
        edk::GU::guUseTexture2D(this->render.getID());

        //render the polygon

        //Draw a quadrangle
        edk::GU::guBegin(GU_QUADS);
        edk::GU::guVertexTex2f32(0.f, 0.f);
        edk::GU::guVertex3f32(0.f, 0.f, 0.f);

        edk::GU::guVertexTex2f32(0.f, 1.f);
        edk::GU::guVertex3f32(0.f, 1.f, 0.f);

        edk::GU::guVertexTex2f32(1.f, 1.f);
        edk::GU::guVertex3f32(1.f, 1.f, 0.f);

        edk::GU::guVertexTex2f32(1.f, 0.f);
        edk::GU::guVertex3f32(1.f, 0.f, 0.f);
        edk::GU::guEnd();

        edk::GU::guUseTexture2D(0u);

        edk::GU::guDisable(GU_TEXTURE_2D);

        //remove the shader program
        this->shader.useNoShader();

        //remove the buffer
        this->render.dontUseFrameBuffer();

        this->drawViewInside();
    }
}
//read from the texture
bool edk::ViewGUTexture::read(const edk::classID  data,edk::uint32 format){
    return this->render.readFromTexture(data,format);
}
