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
