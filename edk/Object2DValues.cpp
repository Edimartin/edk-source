#include "Object2DValues.h"

edk::Object2DValues::Object2DValues()
{
    //this->angle=0.f;
    this->loadIdentityValues();
    this->fixedRotation=false;
    //this->cleanSaved();
}
void edk::Object2DValues::loadIdentityValues(){
    this->position = edk::vec2f32(0,0);
    this->angle = 0.f;
    this->size = edk::size2f32(1,1);
}
/*
//save the values
void edk::Object2DValues::saveValues(){
    this->savePosition = this->position;
    this->saveSize = this->size;
    this->saveAngle = this->angle;
}
//clean the saved values
void edk::Object2DValues::cleanSaved(){
    this->savePosition = edk::vec2f32(0,0);
    this->saveAngle = 0.f;
    this->saveSize = edk::size2f32(1,1);
}
//return the saved values
edk::vec2f32 edk::Object2DValues::getSavedPosition(){
    return this->savePosition;
}
edk::float32 edk::Object2DValues::getSavedPositionX(){
    return this->savePosition.x;
}
edk::float32 edk::Object2DValues::getSavedPositionY(){
    return this->savePosition.y;
}
//return the saved size
edk::size2f32 edk::Object2DValues::getSavedSize(){
    return this->saveSize;
}
edk::float32 edk::Object2DValues::getSavedSizeWidth(){
    return this->saveSize.width;
}
edk::float32 edk::Object2DValues::getSavedSizeHeight(){
    return this->saveSize.height;
}
//return the savedAngle
edk::float32 edk::Object2DValues::getSavedAngle(){
    return this->angle;
}
*/
