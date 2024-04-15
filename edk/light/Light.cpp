#include "Light.h"

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
#pragma message "            Inside Light.cpp"
#endif

edk::light::Light::Light(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::light::Light::~Light(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::light::Light::Constructor(bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;
        this->clean();edkEnd();
        this->on = false;edkEnd();
    }
}

void edk::light::Light::updateDirection(){
    this->direction[0u] = this->lightDirection[0u] - this->position[0u];edkEnd();
    this->direction[1u] = this->lightDirection[1u] - this->position[1u];edkEnd();
    this->direction[2u] = this->lightDirection[2u] - this->position[2u];edkEnd();
    this->direction[3u] = 1.f;edkEnd();
}
//clean the light
void edk::light::Light::clean(){
    this->position[0u] = 0.f;edkEnd();
    this->position[1u] = 0.f;edkEnd();
    this->position[2u] = 1.f;edkEnd();
    this->position[3u] = 1.f;edkEnd();

    this->diffuse[0u] = 1.f;edkEnd();
    this->diffuse[1u] = 1.f;edkEnd();
    this->diffuse[2u] = 1.f;edkEnd();
    this->diffuse[3u] = 1.f;edkEnd();

    this->ambient[0u] = 0.f;edkEnd();
    this->ambient[1u] = 0.f;edkEnd();
    this->ambient[2u] = 0.f;edkEnd();
    this->ambient[3u] = 1.f;edkEnd();

    this->specular[0u] = 1.f;edkEnd();
    this->specular[1u] = 1.f;edkEnd();
    this->specular[2u] = 1.f;edkEnd();
    this->specular[3u] = 1.f;edkEnd();

    this->setDirection(0.f,0.f,0.f);edkEnd();

    this->exponent=1.f;edkEnd();
    this->cutoff=180.f;edkEnd();
    this->constantAttenuation=1.f;edkEnd();
    this->linearAttenuation=0.0f;edkEnd();
    this->quadraticAttenuation=0.0;
}
//Set Vectors
void edk::light::Light::setPosition(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    this->position[0u] = x;edkEnd();
    this->position[1u] = y;edkEnd();
    this->position[2u] = z;edkEnd();
    this->position[3u] = w;edkEnd();
    this->updateDirection();edkEnd();
}
void edk::light::Light::setPosition(edk::float32 x,edk::float32 y,edk::float32 z){
    this->position[0u] = x;edkEnd();
    this->position[1u] = y;edkEnd();
    this->position[2u] = z;edkEnd();
    this->updateDirection();edkEnd();
}
void edk::light::Light::setPosition(edk::float32 x,edk::float32 y){
    this->position[0u] = x;edkEnd();
    this->position[1u] = y;edkEnd();
    this->updateDirection();edkEnd();
}
void edk::light::Light::setPosition(edk::vec4f32 position){
    return this->setPosition(position.x,position.y,position.z,position.w);edkEnd();
}
void edk::light::Light::setPosition(edk::vec3f32 position){
    return this->setPosition(position.x,position.y,position.z);edkEnd();
}
void edk::light::Light::setPosition(edk::vec2f32 position){
    return this->setPosition(position.x,position.y);edkEnd();
}
void edk::light::Light::setDirection(edk::float32 x,edk::float32 y,edk::float32 z){
    this->lightDirection[0u] = x;edkEnd();
    this->lightDirection[1u] = y;edkEnd();
    this->lightDirection[2u] = z;edkEnd();
    this->lightDirection[3u] = 1.f;edkEnd();
    this->updateDirection();edkEnd();
}
void edk::light::Light::setDirection(edk::float32 x,edk::float32 y){
    this->lightDirection[0u] = x;edkEnd();
    this->lightDirection[1u] = y;edkEnd();
    this->lightDirection[3u] = 1.f;edkEnd();
    this->updateDirection();edkEnd();
}
void edk::light::Light::setDirection(edk::vec3f32 direction){
    return this->setDirection(direction.x,direction.y,direction.z);edkEnd();
}
void edk::light::Light::setDirection(edk::vec2f32 direction){
    return this->setDirection(direction.x,direction.y);edkEnd();
}
//Spot Values
void edk::light::Light::setExponent(edk::float32 exponent){
    this->exponent = exponent;edkEnd();
}
void edk::light::Light::setCutoff(edk::float32 cutoff){
    this->cutoff=cutoff;edkEnd();
}
void edk::light::Light::setConstantAttenuation(edk::float32 constantAttenuation){
    this->constantAttenuation=constantAttenuation;edkEnd();
}
void edk::light::Light::setLinearAttenuation(edk::float32 linearAttenuation){
    this->linearAttenuation=linearAttenuation;edkEnd();
}
void edk::light::Light::setQuadraticAttenuation(edk::float32 quadraticAttenuation){
    this->quadraticAttenuation=quadraticAttenuation;edkEnd();
}

//get Position
edk::float32 edk::light::Light::getPositionX(){
    return this->position[0u];edkEnd();
}
edk::float32 edk::light::Light::getPositionY(){
    return this->position[1u];edkEnd();
}
edk::float32 edk::light::Light::getPositionZ(){
    return this->position[2u];edkEnd();
}
edk::float32 edk::light::Light::getPositionW(){
    return this->position[3u];edkEnd();
}
edk::vec2f32 edk::light::Light::getPosition2f(){
    return edk::vec2f32(this->position[0u],this->position[1u]);edkEnd();
}
edk::vec3f32 edk::light::Light::getPosition3f(){
    return edk::vec3f32(this->position[0u],this->position[1u],this->position[2u]);edkEnd();
}
edk::vec4f32 edk::light::Light::getPosition4f(){
    return edk::vec4f32(this->position[0u],this->position[1u],this->position[2u],this->position[3u]);edkEnd();
}
edk::float32 edk::light::Light::getDirectionX(){
    return this->direction[0u];edkEnd();
}
edk::float32 edk::light::Light::getDirectionY(){
    return this->direction[1u];edkEnd();
}
edk::float32 edk::light::Light::getDirectionZ(){
    return this->direction[2u];edkEnd();
}
edk::float32 edk::light::Light::getDirectionW(){
    return this->direction[3u];edkEnd();
}
edk::vec2f32 edk::light::Light::getDirection2f(){
    return edk::vec2f32(this->direction[0u],this->direction[1u]);edkEnd();
}
edk::vec3f32 edk::light::Light::getDirection3f(){
    return edk::vec3f32(this->direction[0u],this->direction[1u],this->direction[2u]);edkEnd();
}
edk::vec4f32 edk::light::Light::getDirection4f(){
    return edk::vec4f32(this->direction[0u],this->direction[1u],this->direction[2u],this->direction[3u]);edkEnd();
}

//Spot Values
edk::float32 edk::light::Light::getExponent(){
    return this->exponent;edkEnd();
}
edk::float32 edk::light::Light::getCutoff(){
    return this->cutoff;edkEnd();
}
edk::float32 edk::light::Light::getConstantAttenuation(){
    return this->constantAttenuation;edkEnd();
}
edk::float32 edk::light::Light::getLinearAttenuation(){
    return this->linearAttenuation;edkEnd();
}
edk::float32 edk::light::Light::getQuadraticAttenuation(){
    return this->quadraticAttenuation;edkEnd();
}

//Set Colors
void edk::light::Light::setAmbient(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->ambient[0u] = r;edkEnd();this->ambient[1u] = g;edkEnd();this->ambient[2u] = b;edkEnd();this->ambient[3u] = a;edkEnd();
}
void edk::light::Light::setAmbient(edk::float32 r,edk::float32 g,edk::float32 b){
    return this->setAmbient(r,g,b,1.f);edkEnd();
}
void edk::light::Light::setAmbient(edk::color4f32 color){
    return this->setAmbient(color.r,color.g,color.b,color.a);edkEnd();
}
void edk::light::Light::setAmbient(edk::color3f32 color){
    return this->setAmbient(color.r,color.g,color.b);edkEnd();
}
void edk::light::Light::setDiffuse(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->diffuse[0u] = r;edkEnd();this->diffuse[1u] = g;edkEnd();this->diffuse[2u] = b;edkEnd();this->diffuse[3u] = a;edkEnd();
}
void edk::light::Light::setDiffuse(edk::float32 r,edk::float32 g,edk::float32 b){
    return this->setDiffuse(r,g,b,1.f);edkEnd();
}
void edk::light::Light::setDiffuse(edk::color4f32 color){
    return this->setDiffuse(color.r,color.g,color.b,color.a);edkEnd();
}
void edk::light::Light::setDiffuse(edk::color3f32 color){
    return this->setDiffuse(color.r,color.g,color.b);edkEnd();
}
void edk::light::Light::setSpecular(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->specular[0u] = r;edkEnd();this->specular[1u] = g;edkEnd();this->specular[2u] = b;edkEnd();this->specular[3u] = a;edkEnd();
}
void edk::light::Light::setSpecular(edk::float32 r,edk::float32 g,edk::float32 b){
    return this->setSpecular(r,g,b,1.f);edkEnd();
}
void edk::light::Light::setSpecular(edk::color4f32 color){
    return this->setSpecular(color.r,color.g,color.b,color.a);edkEnd();
}
void edk::light::Light::setSpecular(edk::color3f32 color){
    return this->setSpecular(color.r,color.g,color.b);edkEnd();
}

edk::float32 edk::light::Light::getAmbientR(){
    return this->ambient[0u];edkEnd();
}
edk::float32 edk::light::Light::getAmbientG(){
    return this->ambient[1u];edkEnd();
}
edk::float32 edk::light::Light::getAmbientB(){
    return this->ambient[2u];edkEnd();
}
edk::float32 edk::light::Light::getAmbientA(){
    return this->ambient[3u];edkEnd();
}
edk::float32 edk::light::Light::getDiffuseR(){
    return this->diffuse[0u];edkEnd();
}
edk::float32 edk::light::Light::getDiffuseG(){
    return this->diffuse[1u];edkEnd();
}
edk::float32 edk::light::Light::getDiffuseB(){
    return this->diffuse[2u];edkEnd();
}
edk::float32 edk::light::Light::getDiffuseA(){
    return this->diffuse[3u];edkEnd();
}
edk::float32 edk::light::Light::getSpecularR(){
    return this->specular[0u];edkEnd();
}
edk::float32 edk::light::Light::getSpecularG(){
    return this->specular[1u];edkEnd();
}
edk::float32 edk::light::Light::getSpecularB(){
    return this->specular[2u];edkEnd();
}
edk::float32 edk::light::Light::getSpecularA(){
    return this->specular[3u];edkEnd();
}

//DRAW THE LIGH USING THE LIGHT NUMBER
void edk::light::Light::draw(edk::uint32 lightNumber){
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_POSITION,this->position);edkEnd();
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_DIFFUSE,this->diffuse);edkEnd();
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_AMBIENT,this->ambient);edkEnd();
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_SPECULAR,this->specular);edkEnd();
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_SPOT_DIRECTION,this->direction);edkEnd();
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_SPOT_EXPONENT,this->exponent);edkEnd();
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_SPOT_CUTOFF,this->cutoff);edkEnd();
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_CONSTANT_ATTENUATION,this->constantAttenuation);edkEnd();
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_LINEAR_ATTENUATION,this->linearAttenuation);edkEnd();
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_QUADRATIC_ATTENUATION,this->quadraticAttenuation);edkEnd();
}
//draw the pivo
void edk::light::Light::drawPivo(edk::float32 size,edk::color3f32 color){

    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position[0u],this->position[1u],this->position[2u]);edkEnd();
    //add scale
    edk::GU::guScale3f32(edk::size3f32(size,size,size));edkEnd();

    //lineSize
    edk::GU::guLineWidth(3);edkEnd();

    //set the colors
    edk::GU::guColor3f32(color);edkEnd();
    //draw the lines
    edk::GU::guBegin(GU_LINES);edkEnd();
    //LINE 1
    edk::GU::guVertex3f32(-0.5f,-0.5f,0.f);edkEnd();
    edk::GU::guVertex3f32( 0.5f, 0.5f,0.f);edkEnd();
    //LINE 2
    edk::GU::guVertex3f32(-0.5f, 0.5f,0.f);edkEnd();
    edk::GU::guVertex3f32( 0.5f,-0.5f,0.f);edkEnd();
    //LINE 3
    edk::GU::guVertex3f32(0.0f, 0.5f,-0.5f);edkEnd();
    edk::GU::guVertex3f32(0.0f,-0.5f, 0.5f);edkEnd();
    //LINE 4
    edk::GU::guVertex3f32(0.0f, 0.5f, 0.5f);edkEnd();
    edk::GU::guVertex3f32(0.0f,-0.5f,-0.5f);edkEnd();
    edk::GU::guEnd();edkEnd();

    //lineSize
    edk::GU::guLineWidth(1);edkEnd();

    //
    edk::GU::guPopMatrix();edkEnd();
}
void edk::light::Light::drawPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    this->drawPivo(size,edk::color3f32(r,g,b));
}
