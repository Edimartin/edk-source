#ifndef EDK_LIGHT_LIGHT_H
#define EDK_LIGHT_LIGHT_H

/*
Library Light - Control GU lights on the EDK Game Engine
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
#warning "Inside Light"
#endif

#pragma once
#include "../TypeVars.h"
#include "../GU/GU.h"
#include <string.h>

#ifdef printMessages
#warning "    Compiling Light"
#endif

#define EDK_LIGHT_LIMIT 8u

namespace edk{
namespace light{
class Light{
public:
    Light();
    //clean the light
    void clean();
    //Set Colors
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
    //DRAW THE LIGH USING THE LIGHT NUMBER
    virtual void draw(edk::uint32 lightNumber);
    //draw the pivo
    virtual void drawPivo(edk::float32 size,edk::color3f32 color);
    void print(){
        printf("\nAmbiant %.2f %.2f %.2f %.2f"
               ,this->ambient[0u]
               ,this->ambient[1u]
               ,this->ambient[2u]
               ,this->ambient[3u]
               );
    }

    //get Position
    edk::float32 getPositionX();
    edk::float32 getPositionY();
    edk::float32 getPositionZ();
    edk::vec2f32 getPosition2f();
    edk::vec3f32 getPosition3f();
    edk::float32 getDirectionX();
    edk::float32 getDirectionY();
    edk::float32 getDirectionZ();
    edk::vec2f32 getDirection2f();
    edk::vec3f32 getDirection3f();

    //Operator =
    edk::light::Light operator = (edk::light::Light newLight){
        edk::int32 sizeofVecF = sizeof(this->position);
        memcpy(this->position,newLight.position,sizeofVecF);
        memcpy(this->diffuse,newLight.diffuse,sizeofVecF);
        memcpy(this->ambient,newLight.ambient,sizeofVecF);
        memcpy(this->specular,newLight.specular,sizeofVecF);
        sizeofVecF = sizeof(this->direction);
        memcpy(this->direction,newLight.direction,sizeofVecF);
        this->exponent = newLight.exponent;
        this->cutoff = newLight.cutoff;
        this->constantAttenuation = newLight.constantAttenuation;
        this->linearAttenuation = newLight.linearAttenuation;
        this->quadraticAttenuation = newLight.quadraticAttenuation;
        return newLight;
    }
    //set light on off
    bool on;

protected:
    //light parameters
    //Position
    edk::float32 position[4u]; //GU_POSITION (0.0, 0.0, 1.0, 0.0) (x, y, z, w) position of light
    edk::float32 diffuse[4u];  //GU_DIFFUSE (1.0, 1.0, 1.0, 1.0) diffuse RGBA intensity of light
    edk::float32 ambient[4u];  //GU_AMBIENT (0.0, 0.0, 0.0, 1.0) ambient RGBA intensity of light
    edk::float32 specular[4u]; //GU_SPECULAR (1.0, 1.0, 1.0, 1.0) specular RGBA intensity of light
    edk::float32 direction[3u]; //GU_SPOT_DIRECTION (0.0, 0.0, -1.0) (x, y, z) direction of spotlight
    edk::float32 exponent; //GU_SPOT_EXPONENT 0.0 spotlight exponent
    edk::float32 cutoff; //GU_SPOT_CUTOFF 180.0 spotlight cutoff angle
    edk::float32 constantAttenuation; //GU_CONSTANT_ATTENUATION 1.0 constant attenuation factor
    edk::float32 linearAttenuation; //GU_LINEAR_ATTENUATION 0.0 linear attenuation factor
    edk::float32 quadraticAttenuation; //GU_QUADRATIC_ATTENUATION 0.0 quadratic attenuation factor
    //Set Vectors
    void setPosition(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w);
    void setPosition(edk::float32 x,edk::float32 y,edk::float32 z);
    void setPosition(edk::float32 x,edk::float32 y);
    void setPosition(edk::vec4f32 position);
    void setPosition(edk::vec3f32 position);
    void setPosition(edk::vec2f32 position);
    void setDirection(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w);
    void setDirection(edk::float32 x,edk::float32 y,edk::float32 z);
    void setDirection(edk::float32 x,edk::float32 y);
    void setDirection(edk::vec4f32 direction);
    void setDirection(edk::vec3f32 direction);
    void setDirection(edk::vec2f32 direction);
    //Spot Values
    void setExponent(edk::float32 exponent);
    void setCutoff(edk::float32 cutoff);
    void setConstantAttenuation(edk::float32 constantAttenuation);
    void setLinearAttenuation(edk::float32 linearAttenuation);
    void setQuadraticAttenuation(edk::float32 quadraticAttenuation);
};
}//end namespace light
}//end namespace edk

#endif // Light_H
