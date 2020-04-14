#ifndef EDK_MATERIAL_MATERIAL_H
#define EDK_MATERIAL_MATERIAL_H

/*
Library Material - Mateiral used in objects on Edk Engine
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

//http://iphonedevelopment.blogspot.com.br/2009/05/opengl-es-from-ground-up-part-5-living.html

#ifdef printMessages
#warning "Inside Material"
#endif

#pragma once
#include "../Texture2DList.h"
#include "../GU/GU.h"
#include "../GU/GU_GLSL.h"
#include "../xml/XML.h"
#include "../pack/FilePackage.h"
#include <stdio.h>

#ifdef printMessages
#warning "    Compiling Material"
#endif

namespace edk{
namespace material{
class Material{
    //Define the textureCount
#define materialTextureCount 32u
public:
    Material();
    ~Material();

    //load the texture
    //filter
    //GU_NEAREST
    //GU_LINEAR
    //GU_NEAREST_MIPMAP_NEAREST
    //GU_NEAREST_MIPMAP_LINEAR
    //GU_LINEAR_MIPMAP_NEAREST
    //GU_LINEAR_MIPMAP_LINEAR
    bool loadTexture(edk::char8* name,edk::uint8 position=0u,edk::uint32 filter = GU_NEAREST);
    bool loadTexture(const char* name,edk::uint8 position=0u,edk::uint32 filter = GU_NEAREST);
    bool loadTextureFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint8 position=0u,edk::uint32 filter = GU_NEAREST);
    bool loadTextureFromMemory(const char* name,edk::uint8* image,edk::uint32 size,edk::uint8 position=0u,edk::uint32 filter = GU_NEAREST);
    bool loadTextureFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint8 position=0u,edk::uint32 filter = GU_NEAREST);
    bool loadTextureFromPack(edk::pack::FilePackage* pack,const char* name,edk::uint8 position=0u,edk::uint32 filter = GU_NEAREST);
    //set the texture
    bool setTextureFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint8 position=0u,edk::uint32 filter = GU_NEAREST);
    bool setTextureFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint8 position=0u,edk::uint32 filter = GU_NEAREST);
    bool setTextureFromMemory(edk::Image2D* image,edk::uint8 position=0u,edk::uint32 filter = GU_NEAREST);

    //SETERS
    void setAmbient(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setAmbient(edk::float32 r,edk::float32 g,edk::float32 b);
    void setAmbient(edk::color4f32 color);
    void setAmbient(edk::color3f32 color);
    void setDiffuse(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setDiffuse(edk::float32 r,edk::float32 g,edk::float32 b);
    void setDiffuse(edk::color4f32 color);
    void setDiffuse(edk::color3f32 color);
    void setSpecular(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setSpecular(edk::float32 r,edk::float32 g,edk::float32 b);
    void setSpecular(edk::color4f32 color);
    void setSpecular(edk::color3f32 color);
    void setEmission(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setEmission(edk::float32 r,edk::float32 g,edk::float32 b);
    void setEmission(edk::color4f32 color);
    void setEmission(edk::color3f32 color);
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

    //set to cantDelete
    void cantDelete();

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXMLWithPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id);

    //TEMP
    void printTexture(edk::uint8 position);
    void printAmbient();

    Material operator =(Material mat){
        edk::uint32 texTemp[materialTextureCount];
        //copy the textures
        for(edk::uint8 i=0u;i<materialTextureCount;i++){
            texTemp[i] = this->textures[i];
            //set the new texture
            this->textures[i] = mat.textures[i];
            //retain the texture
            if(this->textures[i]){
                this->list.retainTexture(this->textures[i]);
            }
        }
        //release the old textures
        for(edk::uint8 i=0u;i<materialTextureCount;i++){
            if(texTemp[i]){
                this->list.removeTexture(texTemp[i]);
            }
        }
        //copy tge vectors
        edk::uint32 sizeOf = sizeof(this->ambient);
        memcpy(this->ambient,mat.ambient,sizeOf);
        memcpy(this->diffuse,mat.diffuse,sizeOf);
        memcpy(this->specular,mat.specular,sizeOf);
        memcpy(this->emission,mat.emission,sizeOf);
        this->shininess = mat.shininess;
        this->countTextures = mat.countTextures;
        //set to dont delete the textures in the destructor
        mat.cantDelete();
        this->cantDelete();
        return mat;
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
    //can delete
    bool canDelete;
};
}//end namespace material
}//end namespace edk

#endif // MATERIAL_H

