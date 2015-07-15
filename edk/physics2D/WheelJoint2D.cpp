#include "WheelJoint2D.h"

edk::physics2D::WheelJoint2D::WheelJoint2D(bool collide)
    : edk::physics2D::Joint2D(collide)
{
    this->type = EDK_WHEEL_JOINT;
    this->removeType();
}

//set motor
void edk::physics2D::WheelJoint2D::setMotor(edk::float32 maxTorque,edk::float32 speed){
    this->maxTorque = maxTorque;
    this->speed = speed;
    this->WheelType = EDK_JOINT_MOTOR;
}
//remove type
void edk::physics2D::WheelJoint2D::removeType(){
    this->WheelType = 0u;
}
//GETERS
edk::uint8 edk::physics2D::WheelJoint2D::getWheelType(){
    return this->WheelType;
}
edk::float32 edk::physics2D::WheelJoint2D::getMaxTorque(){
    return this->getMaxTorque();
}
edk::float32 edk::physics2D::WheelJoint2D::getSpeed(){
    return this->speed;
}
//draw the joint in debug mode
void edk::physics2D::WheelJoint2D::draw(edk::size2f32,edk::color3f32 color){
    edk::GU::guColor3f32(color);
    edk::GU::guPushMatrix();
    edk::GU::guBegin(GU_LINE_STRIP);
    //
    edk::GU::guVertex2f32(this->objectA->position.x,this->objectA->position.y);
    edk::GU::guVertex2f32(this->objectB->position.x,this->objectB->position.y);
    edk::GU::guVertex2f32(this->worldPositionA.x,this->worldPositionA.y);
    edk::GU::guEnd();
    edk::GU::guPopMatrix();
}
