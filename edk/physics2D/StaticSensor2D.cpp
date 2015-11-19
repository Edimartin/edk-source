#include "StaticSensor2D.h"

edk::physics2D::StaticSensor2D::StaticSensor2D()
{
    this->isObjectSensor=true;
    this->physType = edk::physics::StaticBody;
}
edk::physics2D::StaticSensor2D::~StaticSensor2D(){
    this->tree.clean();
}

//get the bodyType
/*
edk::uint8 edk::physics2D::StaticSensor2D::getType(){
    return edk::physics::StaticBody;
}
//return if it's a sensor
bool edk::physics2D::StaticSensor2D::isSensor(){
    return true;
}
*/
//Objects to activate the sensor
//add
bool edk::physics2D::StaticSensor2D::addActivateObject(edk::physics2D::PhysicObject2D* object){
    return this->tree.add(object);
}
//remove
bool edk::physics2D::StaticSensor2D::removeActivateObject(edk::physics2D::PhysicObject2D* object){
    return this->tree.remove(object);
}
//clean the activateObject
void edk::physics2D::StaticSensor2D::cleanActivateObjects(){
    this->tree.clean();
}
//test if have the object
bool edk::physics2D::StaticSensor2D::haveActivateObject(edk::physics2D::PhysicObject2D* object){
    return this->tree.haveElement(object);
}
//getSize
edk::uint32 edk::physics2D::StaticSensor2D::getActivateSize(){
    return this->tree.size();
}
