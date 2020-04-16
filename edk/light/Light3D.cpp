#include "Light3D.h"

edk::light::Light3D::Light3D(){
    //
}
edk::light::Light3D::~Light3D(){
    //
}

//Set Vectors
void edk::light::Light3D::setPosition(edk::float32 x,edk::float32 y,edk::float32 z){
    edk::light::Light::setPosition(x,y,z);
}
void edk::light::Light3D::setPosition(edk::float32 x,edk::float32 y){
    edk::light::Light::setPosition(x,y);
}
void edk::light::Light3D::setPosition(edk::vec3f32 position){
    edk::light::Light::setPosition(position);
}
void edk::light::Light3D::setPosition(edk::vec2f32 position){
    edk::light::Light::setPosition(position);
}
void edk::light::Light3D::setDirection(edk::float32 x,edk::float32 y,edk::float32 z){
    edk::light::Light::setDirection(x,y,z);
}
void edk::light::Light3D::setDirection(edk::float32 x,edk::float32 y){
    edk::light::Light::setDirection(x,y);
}
void edk::light::Light3D::setDirection(edk::vec3f32 direction){
    edk::light::Light::setDirection(direction);
}
void edk::light::Light3D::setDirection(edk::vec2f32 direction){
    edk::light::Light::setDirection(direction);
}
//Spot Values
void edk::light::Light3D::setExponent(edk::float32 exponent){
    edk::light::Light::setExponent(exponent);
}
void edk::light::Light3D::setCutoff(edk::float32 cutoff){
    edk::light::Light::setCutoff(cutoff);
}
void edk::light::Light3D::setConstantAttenuation(edk::float32 constantAttenuation){
    edk::light::Light::setConstantAttenuation(constantAttenuation);
}
void edk::light::Light3D::setLinearAttenuation(edk::float32 linearAttenuation){
    edk::light::Light::setLinearAttenuation(linearAttenuation);
}
void edk::light::Light3D::setQuadraticAttenuation(edk::float32 quadraticAttenuation){
    edk::light::Light::setQuadraticAttenuation(quadraticAttenuation);
}

//get Position
edk::float32 edk::light::Light3D::getPositionX(){
    return edk::light::Light::getPositionX();
}
edk::float32 edk::light::Light3D::getPositionY(){
    return edk::light::Light::getPositionY();
}
edk::float32 edk::light::Light3D::getPositionZ(){
    return edk::light::Light::getPositionZ();
}
edk::vec2f32 edk::light::Light3D::getPosition2f(){
    return edk::light::Light::getPosition2f();
}
edk::vec3f32 edk::light::Light3D::getPosition3f(){
    return edk::light::Light::getPosition3f();
}
edk::float32 edk::light::Light3D::getDirectionX(){
    return edk::light::Light::getDirectionX();
}
edk::float32 edk::light::Light3D::getDirectionY(){
    return edk::light::Light::getDirectionY();
}
edk::float32 edk::light::Light3D::getDirectionZ(){
    return edk::light::Light::getDirectionZ();
}
edk::vec2f32 edk::light::Light3D::getDirection2f(){
    return edk::light::Light::getDirection2f();
}
edk::vec3f32 edk::light::Light3D::getDirection3f(){
    return edk::light::Light::getDirection3f();
}

//Spot Values
edk::float32 edk::light::Light3D::getExponent(){
    return edk::light::Light::getExponent();
}
edk::float32 edk::light::Light3D::getCutoff(){
    return edk::light::Light::getCutoff();
}
edk::float32 edk::light::Light3D::getConstantAttenuation(){
    return edk::light::Light::getConstantAttenuation();
}
edk::float32 edk::light::Light3D::getLinearAttenuation(){
    return edk::light::Light::getLinearAttenuation();
}
edk::float32 edk::light::Light3D::getQuadraticAttenuation(){
    return edk::light::Light::getQuadraticAttenuation();
}
