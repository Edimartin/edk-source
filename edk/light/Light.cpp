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
    this->classThis=NULL; 
    this->Constructor();
}
edk::light::Light::~Light(){
    this->Destructor();
}

void edk::light::Light::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;
        this->clean(); 
        this->on = false; 
    }
}
void edk::light::Light::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
}

void edk::light::Light::updateDirection(){
    this->direction[0u] = this->lightDirection[0u] - this->position[0u]; 
    this->direction[1u] = this->lightDirection[1u] - this->position[1u]; 
    this->direction[2u] = this->lightDirection[2u] - this->position[2u]; 
    this->direction[3u] = 1.f; 
}
//clean the light
void edk::light::Light::clean(){
    this->position[0u] = 0.f; 
    this->position[1u] = 0.f; 
    this->position[2u] = 1.f; 
    this->position[3u] = 1.f; 

    this->diffuse[0u] = 1.f; 
    this->diffuse[1u] = 1.f; 
    this->diffuse[2u] = 1.f; 
    this->diffuse[3u] = 1.f; 

    this->ambient[0u] = 0.f; 
    this->ambient[1u] = 0.f; 
    this->ambient[2u] = 0.f; 
    this->ambient[3u] = 1.f; 

    this->specular[0u] = 1.f; 
    this->specular[1u] = 1.f; 
    this->specular[2u] = 1.f; 
    this->specular[3u] = 1.f; 

    this->setDirection(0.f,0.f,0.f); 

    this->exponent=1.f; 
    this->cutoff=180.f; 
    this->constantAttenuation=1.f; 
    this->linearAttenuation=0.0f; 
    this->quadraticAttenuation=0.0;
}
//Set Vectors
void edk::light::Light::setPosition(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    this->position[0u] = x; 
    this->position[1u] = y; 
    this->position[2u] = z; 
    this->position[3u] = w; 
    this->updateDirection(); 
}
void edk::light::Light::setPosition(edk::float32 x,edk::float32 y,edk::float32 z){
    this->position[0u] = x; 
    this->position[1u] = y; 
    this->position[2u] = z; 
    this->updateDirection(); 
}
void edk::light::Light::setPosition(edk::float32 x,edk::float32 y){
    this->position[0u] = x; 
    this->position[1u] = y; 
    this->updateDirection(); 
}
void edk::light::Light::setPosition(edk::vec4f32 position){
    return this->setPosition(position.x,position.y,position.z,position.w); 
}
void edk::light::Light::setPosition(edk::vec3f32 position){
    return this->setPosition(position.x,position.y,position.z); 
}
void edk::light::Light::setPosition(edk::vec2f32 position){
    return this->setPosition(position.x,position.y); 
}
void edk::light::Light::setDirection(edk::float32 x,edk::float32 y,edk::float32 z){
    this->lightDirection[0u] = x; 
    this->lightDirection[1u] = y; 
    this->lightDirection[2u] = z; 
    this->lightDirection[3u] = 1.f; 
    this->updateDirection(); 
}
void edk::light::Light::setDirection(edk::float32 x,edk::float32 y){
    this->lightDirection[0u] = x; 
    this->lightDirection[1u] = y; 
    this->lightDirection[3u] = 1.f; 
    this->updateDirection(); 
}
void edk::light::Light::setDirection(edk::vec3f32 direction){
    return this->setDirection(direction.x,direction.y,direction.z); 
}
void edk::light::Light::setDirection(edk::vec2f32 direction){
    return this->setDirection(direction.x,direction.y); 
}
//Spot Values
void edk::light::Light::setExponent(edk::float32 exponent){
    this->exponent = exponent; 
}
void edk::light::Light::setCutoff(edk::float32 cutoff){
    this->cutoff=cutoff; 
}
void edk::light::Light::setConstantAttenuation(edk::float32 constantAttenuation){
    this->constantAttenuation=constantAttenuation; 
}
void edk::light::Light::setLinearAttenuation(edk::float32 linearAttenuation){
    this->linearAttenuation=linearAttenuation; 
}
void edk::light::Light::setQuadraticAttenuation(edk::float32 quadraticAttenuation){
    this->quadraticAttenuation=quadraticAttenuation; 
}

//get Position
edk::float32 edk::light::Light::getPositionX(){
    return this->position[0u]; 
}
edk::float32 edk::light::Light::getPositionY(){
    return this->position[1u]; 
}
edk::float32 edk::light::Light::getPositionZ(){
    return this->position[2u]; 
}
edk::float32 edk::light::Light::getPositionW(){
    return this->position[3u]; 
}
edk::vec2f32 edk::light::Light::getPosition2f(){
    return edk::vec2f32(this->position[0u],this->position[1u]); 
}
edk::vec3f32 edk::light::Light::getPosition3f(){
    return edk::vec3f32(this->position[0u],this->position[1u],this->position[2u]); 
}
edk::vec4f32 edk::light::Light::getPosition4f(){
    return edk::vec4f32(this->position[0u],this->position[1u],this->position[2u],this->position[3u]); 
}
edk::float32 edk::light::Light::getDirectionX(){
    return this->direction[0u]; 
}
edk::float32 edk::light::Light::getDirectionY(){
    return this->direction[1u]; 
}
edk::float32 edk::light::Light::getDirectionZ(){
    return this->direction[2u]; 
}
edk::float32 edk::light::Light::getDirectionW(){
    return this->direction[3u]; 
}
edk::vec2f32 edk::light::Light::getDirection2f(){
    return edk::vec2f32(this->direction[0u],this->direction[1u]); 
}
edk::vec3f32 edk::light::Light::getDirection3f(){
    return edk::vec3f32(this->direction[0u],this->direction[1u],this->direction[2u]); 
}
edk::vec4f32 edk::light::Light::getDirection4f(){
    return edk::vec4f32(this->direction[0u],this->direction[1u],this->direction[2u],this->direction[3u]); 
}

//Spot Values
edk::float32 edk::light::Light::getExponent(){
    return this->exponent; 
}
edk::float32 edk::light::Light::getCutoff(){
    return this->cutoff; 
}
edk::float32 edk::light::Light::getConstantAttenuation(){
    return this->constantAttenuation; 
}
edk::float32 edk::light::Light::getLinearAttenuation(){
    return this->linearAttenuation; 
}
edk::float32 edk::light::Light::getQuadraticAttenuation(){
    return this->quadraticAttenuation; 
}

//Set Colors
void edk::light::Light::setAmbient(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->ambient[0u] = r; this->ambient[1u] = g; this->ambient[2u] = b; this->ambient[3u] = a; 
}
void edk::light::Light::setAmbient(edk::float32 r,edk::float32 g,edk::float32 b){
    return this->setAmbient(r,g,b,1.f); 
}
void edk::light::Light::setAmbient(edk::color4f32 color){
    return this->setAmbient(color.r,color.g,color.b,color.a); 
}
void edk::light::Light::setAmbient(edk::color3f32 color){
    return this->setAmbient(color.r,color.g,color.b); 
}
void edk::light::Light::setDiffuse(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->diffuse[0u] = r; this->diffuse[1u] = g; this->diffuse[2u] = b; this->diffuse[3u] = a; 
}
void edk::light::Light::setDiffuse(edk::float32 r,edk::float32 g,edk::float32 b){
    return this->setDiffuse(r,g,b,1.f); 
}
void edk::light::Light::setDiffuse(edk::color4f32 color){
    return this->setDiffuse(color.r,color.g,color.b,color.a); 
}
void edk::light::Light::setDiffuse(edk::color3f32 color){
    return this->setDiffuse(color.r,color.g,color.b); 
}
void edk::light::Light::setSpecular(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->specular[0u] = r; this->specular[1u] = g; this->specular[2u] = b; this->specular[3u] = a; 
}
void edk::light::Light::setSpecular(edk::float32 r,edk::float32 g,edk::float32 b){
    return this->setSpecular(r,g,b,1.f); 
}
void edk::light::Light::setSpecular(edk::color4f32 color){
    return this->setSpecular(color.r,color.g,color.b,color.a); 
}
void edk::light::Light::setSpecular(edk::color3f32 color){
    return this->setSpecular(color.r,color.g,color.b); 
}

edk::float32 edk::light::Light::getAmbientR(){
    return this->ambient[0u]; 
}
edk::float32 edk::light::Light::getAmbientG(){
    return this->ambient[1u]; 
}
edk::float32 edk::light::Light::getAmbientB(){
    return this->ambient[2u]; 
}
edk::float32 edk::light::Light::getAmbientA(){
    return this->ambient[3u]; 
}
edk::float32 edk::light::Light::getDiffuseR(){
    return this->diffuse[0u]; 
}
edk::float32 edk::light::Light::getDiffuseG(){
    return this->diffuse[1u]; 
}
edk::float32 edk::light::Light::getDiffuseB(){
    return this->diffuse[2u]; 
}
edk::float32 edk::light::Light::getDiffuseA(){
    return this->diffuse[3u]; 
}
edk::float32 edk::light::Light::getSpecularR(){
    return this->specular[0u]; 
}
edk::float32 edk::light::Light::getSpecularG(){
    return this->specular[1u]; 
}
edk::float32 edk::light::Light::getSpecularB(){
    return this->specular[2u]; 
}
edk::float32 edk::light::Light::getSpecularA(){
    return this->specular[3u]; 
}

//DRAW THE LIGH USING THE LIGHT NUMBER
void edk::light::Light::draw(edk::uint32 lightNumber){
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_POSITION,this->position); 
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_DIFFUSE,this->diffuse); 
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_AMBIENT,this->ambient); 
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_SPECULAR,this->specular); 
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_SPOT_DIRECTION,this->direction); 
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_SPOT_EXPONENT,this->exponent); 
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_SPOT_CUTOFF,this->cutoff); 
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_CONSTANT_ATTENUATION,this->constantAttenuation); 
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_LINEAR_ATTENUATION,this->linearAttenuation); 
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_QUADRATIC_ATTENUATION,this->quadraticAttenuation); 
}
//draw the pivo
void edk::light::Light::drawPivo(edk::float32 size,edk::color3f32 color){
    edk::GU::guPushMatrix(); 
    //add translate
    edk::GU::guTranslate3f32(this->position[0u],this->position[1u],this->position[2u]); 
    //add scale
    edk::GU::guScale3f32(edk::size3f32(size,size,size)); 

    //lineSize
    edk::GU::guLineWidth(3); 

    //set the colors
    edk::GU::guColor3f32(color); 
    //draw the lines
    edk::GU::guBegin(GU_LINES); 
    //LINE 1
    edk::GU::guVertex3f32(-0.5f,-0.5f,0.f); 
    edk::GU::guVertex3f32( 0.5f, 0.5f,0.f); 
    //LINE 2
    edk::GU::guVertex3f32(-0.5f, 0.5f,0.f); 
    edk::GU::guVertex3f32( 0.5f,-0.5f,0.f); 
    //LINE 3
    edk::GU::guVertex3f32(0.0f, 0.5f,-0.5f); 
    edk::GU::guVertex3f32(0.0f,-0.5f, 0.5f); 
    //LINE 4
    edk::GU::guVertex3f32(0.0f, 0.5f, 0.5f); 
    edk::GU::guVertex3f32(0.0f,-0.5f,-0.5f); 
    edk::GU::guEnd(); 

    //lineSize
    edk::GU::guLineWidth(1); 

    //
    edk::GU::guPopMatrix(); 
}
void edk::light::Light::drawPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    this->drawPivo(size,edk::color3f32(r,g,b));
}
