#ifndef EDK_MATERIAL_MATERIAL_H
#define EDK_MATERIAL_MATERIAL_H

/*
Library Material - Mateiral used in objects on Edk Engine
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

//http://iphonedevelopment.blogspot.com.br/2009/05/opengl-es-from-ground-up-part-5-living.html

#ifdef printMessages
#pragma message "Inside Material"
#endif

#pragma once
#include "../Texture2DList.h"
#include "../GU/GU.h"
#include "../GU/GU_GLSL.h"
#include "../xml/XML.h"
#include "../pack/FilePackage.h"
#include <stdio.h>

#ifdef printMessages
#pragma message "    Compiling Material"
#endif

namespace edk{
namespace material{
class Material{
    //Define the textureCount
#define materialTextureCount 32u
public:
    Material();
    virtual ~Material();

    void Constructor(bool runFather=true);

    //create a new texture
    bool newTexture(edk::char8* name,edk::size2ui32 size,edk::uint8 position=0u,edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    bool newTexture(const edk::char8* name,edk::size2ui32 size,edk::uint8 position=0u,edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    bool newTexture(edk::char8* name,edk::uint32 width,edk::uint32 height,edk::uint8 position=0u,edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    bool newTexture(const edk::char8* name,edk::uint32 width,edk::uint32 height,edk::uint8 position=0u,edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    bool newTextureWithPBODraw(edk::char8* name,edk::size2ui32 size,edk::uint8 position,edk::uint32 mode,edk::uint32 filter);
    bool newTextureWithPBODraw(const edk::char8* name,edk::size2ui32 size,edk::uint8 position,edk::uint32 mode,edk::uint32 filter);
    bool newTextureWithPBODraw(edk::char8* name,edk::uint32 width,edk::uint32 height,edk::uint8 position,edk::uint32 mode,edk::uint32 filter);
    bool newTextureWithPBODraw(const edk::char8* name,edk::uint32 width,edk::uint32 height,edk::uint8 position,edk::uint32 mode,edk::uint32 filter);
    //create a new texture passing the buffer
    bool newTextureAndDraw(edk::char8* name,edk::size2ui32 size,edk::uint8* image,edk::uint8 position=0u,edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    bool newTextureAndDraw(const edk::char8* name,edk::size2ui32 size,edk::uint8* image,edk::uint8 position=0u,edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    bool newTextureAndDraw(edk::char8* name,edk::uint32 width,edk::uint32 height,edk::uint8* image,edk::uint8 position=0u,edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    bool newTextureAndDraw(const edk::char8* name,edk::uint32 width,edk::uint32 height,edk::uint8* image,edk::uint8 position=0u,edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    bool newTextureAndDraw(edk::Image2D* image,edk::uint8 position=0u,edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    bool newTextureAndDrawWithPBODraw(edk::char8* name,edk::size2ui32 size,edk::uint8* image,edk::uint8 position,edk::uint32 mode,edk::uint32 filter);
    bool newTextureAndDrawWithPBODraw(const edk::char8* name,edk::size2ui32 size,edk::uint8* image,edk::uint8 position,edk::uint32 mode,edk::uint32 filter);
    bool newTextureAndDrawWithPBODraw(edk::char8* name,edk::uint32 width,edk::uint32 height,edk::uint8* image,edk::uint8 position,edk::uint32 mode,edk::uint32 filter);
    bool newTextureAndDrawWithPBODraw(const edk::char8* name,edk::uint32 width,edk::uint32 height,edk::uint8* image,edk::uint8 position,edk::uint32 mode,edk::uint32 filter);
    bool newTextureAndDrawWithPBODraw(edk::Image2D* image,edk::uint8 position,edk::uint32 mode,edk::uint32 filter);

    //load the texture
    //filter
    //GU_NEAREST
    //GU_LINEAR
    //GU_NEAREST_MIPMAP_NEAREST
    //GU_NEAREST_MIPMAP_LINEAR
    //GU_LINEAR_MIPMAP_NEAREST
    //GU_LINEAR_MIPMAP_LINEAR
    bool loadTexture(edk::char8* name,edk::uint8 position=0u,edk::uint32 filter = GU_NEAREST);
    bool loadTexture(const edk::char8* name,edk::uint8 position=0u,edk::uint32 filter = GU_NEAREST);
    bool loadTextureFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint8 position=0u,edk::uint32 filter = GU_NEAREST);
    bool loadTextureFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint8 position=0u,edk::uint32 filter = GU_NEAREST);
    bool loadTextureFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint8 position=0u,edk::uint32 filter = GU_NEAREST);
    bool loadTextureFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint8 position=0u,edk::uint32 filter = GU_NEAREST);
    //set the texture
    bool setTextureFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint8 position=0u,edk::uint32 filter = GU_NEAREST);
    bool setTextureFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint8 position=0u,edk::uint32 filter = GU_NEAREST);
    bool setTextureFromMemory(edk::Image2D* image,edk::uint8 position=0u,edk::uint32 filter = GU_NEAREST);
    //draw into a texture
    bool drawToTexture(edk::char8* name,edk::uint8* image,edk::uint32 filter = GU_NEAREST);
    bool drawToTexture(const edk::char8* name,edk::uint8* image,edk::uint32 filter = GU_NEAREST);
    bool drawToTexture(edk::Image2D* image,edk::uint32 filter = GU_NEAREST);

    //SETERS
    void setAmbient(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setAmbient(edk::float32 r,edk::float32 g,edk::float32 b);
    void setAmbient(edk::color4f32 color);
    void setAmbient(edk::color3f32 color);
    void setAmbientA(edk::float32 a);
    void setDiffuse(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setDiffuse(edk::float32 r,edk::float32 g,edk::float32 b);
    void setDiffuse(edk::color4f32 color);
    void setDiffuse(edk::color3f32 color);
    void setDiffuseA(edk::float32 a);
    void setSpecular(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setSpecular(edk::float32 r,edk::float32 g,edk::float32 b);
    void setSpecular(edk::color4f32 color);
    void setSpecular(edk::color3f32 color);
    void setSpecularA(edk::float32 a);
    void setEmission(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setEmission(edk::float32 r,edk::float32 g,edk::float32 b);
    void setEmission(edk::color4f32 color);
    void setEmission(edk::color3f32 color);
    void setEmissionA(edk::float32 a);
    void setShininess(edk::float32 shininess);

    //GETERS
    edk::color4f32 getAmbient();
    edk::color4f32 getDiffuse();
    edk::color4f32 getSpecular();
    edk::color4f32 getEmission();
    edk::float32 getShininess();

    //GETERS
    edk::uint32 getTexture(edk::uint8 position);
    //return the name of the texture
    edk::char8* getTextureName(edk::uint8 position);
    //return the size of the texture
    edk::size2ui32 getTextureSize(edk::uint8 position);
    edk::uint32 getTextureWidth(edk::uint8 position);
    edk::uint32 getTextureHeight(edk::uint8 position);

    //remove the texture
    bool removeTexture(edk::uint8 position);
    void removeAllTextures();
    //delete the texture
    bool deleteTexture(edk::uint8 position);

    //test if have texture
    bool haveTexture();
    bool haveTexture(edk::uint8 position);
    bool haveOneTexture();

    //DRAW
    //draw the material
    void drawStart();
    void drawEnd();
    void drawNoTexture();
    void drawStartWithOneTexture();
    void drawStartWithOneTexture(edk::uint32 position);
    void drawStartWithMultiTexture();
    void drawEndWithTexture();

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id);

    //TEMP
    void printTexture(edk::uint8 position);
    void printTextures();
    void printMaterial();

    bool cloneFrom(Material *mat){
        if(mat){
            edk::uint32 texTemp[materialTextureCount];edkEnd();
            //copy the textures
            for(edk::uint8 i=0u;i<materialTextureCount;i++){
                texTemp[i] = this->textures[i];edkEnd();
                //set the new texture
                this->textures[i] = mat->textures[i];edkEnd();
                //retain the texture
                if(this->textures[i]){
                    this->list.retainTexture(this->textures[i]);edkEnd();
                }
            }
            //release the old textures
            for(edk::uint8 i=0u;i<materialTextureCount;i++){
                if(texTemp[i]){
                    this->list.removeTexture(texTemp[i]);edkEnd();
                }
            }
            //copy tge vectors
            edk::uint32 sizeOf = sizeof(this->ambient);edkEnd();
            memcpy(this->ambient,mat->ambient,sizeOf);edkEnd();
            memcpy(this->diffuse,mat->diffuse,sizeOf);edkEnd();
            memcpy(this->specular,mat->specular,sizeOf);edkEnd();
            memcpy(this->emission,mat->emission,sizeOf);edkEnd();
            this->shininess = mat->shininess;edkEnd();
            this->countTextures = mat->countTextures;edkEnd();
            return true;
        }
        return false;
    }
private:
    Material operator =(Material mat){
        edk::uint32 texTemp[materialTextureCount];edkEnd();
        //copy the textures
        for(edk::uint8 i=0u;i<materialTextureCount;i++){
            texTemp[i] = this->textures[i];edkEnd();
            //set the new texture
            this->textures[i] = mat.textures[i];edkEnd();
            //retain the texture
            if(this->textures[i]){
                this->list.retainTexture(this->textures[i]);edkEnd();
            }
        }
        //release the old textures
        for(edk::uint8 i=0u;i<materialTextureCount;i++){
            if(texTemp[i]){
                this->list.removeTexture(texTemp[i]);edkEnd();
            }
        }
        //copy tge vectors
        edk::uint32 sizeOf = sizeof(this->ambient);edkEnd();
        memcpy(this->ambient,mat.ambient,sizeOf);edkEnd();
        memcpy(this->diffuse,mat.diffuse,sizeOf);edkEnd();
        memcpy(this->specular,mat.specular,sizeOf);edkEnd();
        memcpy(this->emission,mat.emission,sizeOf);edkEnd();
        this->shininess = mat.shininess;edkEnd();
        this->countTextures = mat.countTextures;edkEnd();
        return mat;edkEnd();
    }
protected:
    //draw the material parameters
    void useMaterialParameters();
    //COLORS
    edk::float32 ambient[4u];
    edk::float32 diffuse[4u];
    edk::float32 specular[4u];
    edk::float32 emission[4u];
    edk::float32 shininess;
    //textures in the mesh
    edk::uint32 textures[materialTextureCount];
private:
    //count the textures
    edk::uint8 countTextures;
    //textureList
    edk::Texture2DList list;
private:
    edk::classID classThis;
};
}//end namespace material
}//end namespace edk

#endif // MATERIAL_H

