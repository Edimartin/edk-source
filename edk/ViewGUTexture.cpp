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

#ifdef printMessages
#pragma message "            Inside ViewGUTexture.cpp"
#endif

edk::int64 edk::ViewGUTexture::nameCounter=1uL;

edk::char8 uniformLUTStrings[materialTextureCount][32u] = {
    "iChannel0",
    "iChannelLUT1",
    "iChannelLUT2",
    "iChannelLUT3",
    "iChannelLUT4",
    "iChannelLUT5",
    "iChannelLUT6",
    "iChannelLUT7",
    "iChannelLUT8",
    "iChannelLUT9",
    "iChannelLUT10",
    "iChannelLUT11",
    "iChannelLUT12",
    "iChannelLUT13",
    "iChannelLUT14",
    "iChannelLUT15",
    "iChannelLUT16",
    "iChannelLUT17",
    "iChannelLUT18",
    "iChannelLUT19",
    "iChannelLUT20",
    "iChannelLUT21",
    "iChannelLUT22",
    "iChannelLUT23",
    "iChannelLUT24",
    "iChannelLUT25",
    "iChannelLUT26",
    "iChannelLUT27",
    "iChannelLUT28",
    "iChannelLUT29",
    "iChannelLUT30",
    "iChannelLUT31",
};

const char* LUT_FsSrc = R"(
                        //LUT FRAG GLSL
                        #version 330 core
                        uniform vec2      iResolution;
                        uniform sampler2D iChannel0;
                        uniform sampler3D iChannelLUT1;

                        void main(){
                            vec2 fragCoord = gl_FragCoord.xy;
                            vec2 uv = fragCoord.xy/iResolution.xy;
                            //uv.y = (uv.y * - 1.0)+1.0;
                            vec4 img = texture(iChannel0,uv);
                            vec4 lut = texture(iChannelLUT1,img.rgb);
                        gl_FragColor = vec4(lut.rgb, 1.0);
                        }
                        )";

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
        this->material.Constructor();
        this->lut.Constructor();

        this->material.setAmbient(1.f,1.f,1.f,1.f);
        this->material.setDiffuse(1.f,1.f,1.f,1.f);
        this->material.setEmission(1.f,1.f,1.f,1.f);

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
        this->material.Constructor();
        this->lut.Constructor();

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
        this->material.Destructor();
        this->lut.Destructor();
    }
    edk::ViewGU::Destructor();
}

//print the uniform values
void edk::ViewGUTexture::printUniformTextures(){
    printf("\nUniforms:");
    for(edk::uint8 i=0u;i<materialTextureCount;i++){
        printf("\n    %s",uniformLUTStrings[i]);fflush(stdout);
    }
}

//load the shader
bool edk::ViewGUTexture::loadShader(){
    this->shader.start();
    this->shader.deleteProgram();
    this->shader.deleteShaders();
    if(this->shader.loadShaderFromMemory("lut.frag",(edk::uint8*)LUT_FsSrc,edk::String::strSize(LUT_FsSrc),EDK_SHADER_FRAGMENT)){
        //printf("\n%u %s %s LOAD FRAGMENT OK",__LINE__,__FILE__,__func__);fflush(stdout);
        if(this->shader.createProgram("lut.prog")){
            //printf("\n%u %s %s CREATE PROGRAM OK",__LINE__,__FILE__,__func__);fflush(stdout);
        }
        else{
            printf("\n%u %s %s CREATE PROGRAM ERROR: %s",__LINE__,__FILE__,__func__
                   ,this->shader.getCompilationLog()
                   );fflush(stdout);
        }
    }
    else{
        printf("\n%u %s %s LOAD FRAGMENT ERROR: %s",__LINE__,__FILE__,__func__
               ,this->shader.getCompilationLog()
               );fflush(stdout);
    }
    return false;
}

//set the new size of the texture
bool edk::ViewGUTexture::setTextureSize(edk::size2ui32 size){
    return this->render.createRender(size,GU_LINEAR);
}
bool edk::ViewGUTexture::setTextureSize(edk::uint32 width,edk::uint32 height){
    //
    return this->setTextureSize(edk::size2ui32(width,height));
}
//return the textureSize
edk::size2ui32 edk::ViewGUTexture::getTextureSize(){
    return this->render.getSize().widthHeight();
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

        //update the shader uniforms

        //set the camera position
        edk::GU::guUseMatrix(GU_PROJECTION);
        //Load the identity
        edk::GU::guLoadIdentity();
        //Set the ortho camera
        edk::GU::guUseOrtho(0,1,0,1,-1,1);

        //set the matrix before draw the scene
        edk::GU::guUseMatrix(GU_MODELVIEW);

        //start the material
        this->material.drawStartWithMultiTexture();

        //set the texture
        edk::GU::guUseTexture2D(this->render.getID());

        //render the polygon
        //iResolution
        this->shader.setData2f("iResolution",this->frame.size.width,this->frame.size.height);
        this->shader.updateData("iResolution");
        this->shader.setData1i(uniformLUTStrings[0],0);
        this->shader.updateData(uniformLUTStrings[0]);
        for(edk::uint8 i=1u;i<materialTextureCount;i++){
            if(this->material.haveTexture(i)){
                this->shader.setData1i(uniformLUTStrings[i],i);
                this->shader.updateData(uniformLUTStrings[i]);
            }
        }

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

        this->material.drawEndWithTexture();

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

//LUT3D
bool edk::ViewGUTexture::newLutTextureFromFile(const edk::char8* fileName,edk::uint32 position){
    return this->newLutTextureFromFile((edk::char8*) fileName,position);
}
bool edk::ViewGUTexture::newLutTextureFromFile(edk::char8* fileName,edk::uint32 position){
    if(position>0u){
        if(this->lut.loadFrom(fileName)){
            //create the texture
            edk::Image3D img;
            if(this->lut.writeToImage(&img)){
                //set the image name
                edk::char8* strValue = edk::String::uint64ToStr(edk::ViewGUTexture::nameCounter);
                if(strValue){
                    edk::char8* name = edk::String::strCat("lutTexture_",strValue);
                    if(name){
                        img.setName(name);
                        free(name);
                    }
                    free(strValue);
                }
                if(this->material.newTextureAndDraw(&img,position,GU_LINEAR,GU_LINEAR)){
                    img.deleteImage();
                    return true;
                }
                img.deleteImage();
            }
        }
    }
    return false;
}
