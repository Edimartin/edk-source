#ifndef EDK_LIGHT_LIGHT_H
#define EDK_LIGHT_LIGHT_H

/*
Library Light - Control GU lights on the EDK Game Engine
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
#pragma message "Inside Light"
#endif

#pragma once
#include "../TypeVars.h"
#include "../GU/GU.h"
#include "../DebugFile.h"
#include <string.h>

#ifdef printMessages
#pragma message "    Compiling Light"
#endif

#define EDK_LIGHT_LIMIT 8u

namespace edk{
namespace light{
class Light{
public:
    Light();
    virtual ~Light();
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

    edk::float32 getAmbientR();
    edk::float32 getAmbientG();
    edk::float32 getAmbientB();
    edk::float32 getAmbientA();
    edk::float32 getDiffuseR();
    edk::float32 getDiffuseG();
    edk::float32 getDiffuseB();
    edk::float32 getDiffuseA();
    edk::float32 getSpecularR();
    edk::float32 getSpecularG();
    edk::float32 getSpecularB();
    edk::float32 getSpecularA();

    //DRAW THE LIGH USING THE LIGHT NUMBER
    virtual void draw(edk::uint32 lightNumber);
    //draw the pivo
    virtual void drawPivo(edk::float32 size,edk::color3f32 color);
    virtual void drawPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b);
    void print(){
        printf("\nAmbiant %.2f %.2f %.2f %.2f"
               ,this->ambient[0u]
               ,this->ambient[1u]
               ,this->ambient[2u]
               ,this->ambient[3u]
               );edkEnd();
    }

    //Operator =
    edk::light::Light operator = (edk::light::Light newLight){
        memcpy(this->position,newLight.position,sizeof(this->position));edkEnd();
        memcpy(this->diffuse,newLight.diffuse,sizeof(this->diffuse));edkEnd();
        memcpy(this->ambient,newLight.ambient,sizeof(this->ambient));edkEnd();
        memcpy(this->specular,newLight.specular,sizeof(this->specular));edkEnd();
        memcpy(this->direction,newLight.direction,sizeof(this->direction));edkEnd();
        this->exponent = newLight.exponent;edkEnd();
        this->cutoff = newLight.cutoff;edkEnd();
        this->constantAttenuation = newLight.constantAttenuation;edkEnd();
        this->linearAttenuation = newLight.linearAttenuation;edkEnd();
        this->quadraticAttenuation = newLight.quadraticAttenuation;edkEnd();
        return newLight;edkEnd();
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
    edk::float32 direction[4u]; //GU_SPOT_DIRECTION (0.0, 0.0, -1.0) (x, y, z) direction of spotlight
    edk::float32 lightDirection[4u]; //Direction minus position
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
    void setDirection(edk::float32 x,edk::float32 y,edk::float32 z);
    void setDirection(edk::float32 x,edk::float32 y);
    void setDirection(edk::vec3f32 direction);
    void setDirection(edk::vec2f32 direction);
    //Spot Values
    void setExponent(edk::float32 exponent);
    void setCutoff(edk::float32 cutoff);
    void setConstantAttenuation(edk::float32 constantAttenuation);
    void setLinearAttenuation(edk::float32 linearAttenuation);
    void setQuadraticAttenuation(edk::float32 quadraticAttenuation);

    //get Position
    edk::float32 getPositionX();
    edk::float32 getPositionY();
    edk::float32 getPositionZ();
    edk::float32 getPositionW();
    edk::vec2f32 getPosition2f();
    edk::vec3f32 getPosition3f();
    edk::vec4f32 getPosition4f();
    edk::float32 getDirectionX();
    edk::float32 getDirectionY();
    edk::float32 getDirectionZ();
    edk::float32 getDirectionW();
    edk::vec2f32 getDirection2f();
    edk::vec3f32 getDirection3f();
    edk::vec4f32 getDirection4f();

    //Spot Values
    edk::float32 getExponent();
    edk::float32 getCutoff();
    edk::float32 getConstantAttenuation();
    edk::float32 getLinearAttenuation();
    edk::float32 getQuadraticAttenuation();
private:
    void updateDirection();
};
}//end namespace light
}//end namespace edk

#endif // Light_H
