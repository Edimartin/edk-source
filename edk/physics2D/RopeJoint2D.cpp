#include "RopeJoint2D.h"

edk::physics2D::RopeJoint2D::RopeJoint2D(bool collide)
    :
        edk::physics2D::Joint2D(collide)
{
    this->type = EDK_ROPE_JOINT;
    this->maxLength = 0.f;
}

//draw the joint in debug mode
void edk::physics2D::RopeJoint2D::draw(edk::size2f32,edk::color3f32 color){
    edk::GU::guColor3f32(color);
    edk::GU::guPushMatrix();
    edk::GU::guBegin(GU_LINES);
    //the line
/*
    edk::GU::guVertex2f32(this->worldPositionA.x,this->worldPositionA.y);
    edk::GU::guVertex2f32(this->worldPositionB.x,this->worldPositionB.y);
*/
    temp=edk::Math::rotate2f(this->positionA,this->objectA->angle);
    edk::GU::guVertex2f32(this->objectA->position.x + (temp.x),
                          this->objectA->position.y + (temp.y)
                          );
    temp=edk::Math::rotate2f(this->positionB,this->objectB->angle);
    edk::GU::guVertex2f32(this->objectB->position.x + (temp.x),
                          this->objectB->position.y + (temp.y)
                          );

    edk::GU::guEnd();
    edk::GU::guPopMatrix();
}
