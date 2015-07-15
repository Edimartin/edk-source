#ifndef WHEELJOINT2D_H
#define WHEELJOINT2D_H

#pragma once
#include "Joint2D.h"
#include "../TypeDefines.h"

/*
                                                        edk::vec2f32 direction, edk::float32 frequency, edk::float32 dampingRatio,
                                                        edk::float32 maxTorque,edk::float32 speed,
                                                        bool collide
*/

namespace edk{
namespace physics2D{
class WheelJoint2D : public edk::physics2D::Joint2D{
public:
    WheelJoint2D(bool collide=false);

    //set motor
    void setMotor(edk::float32 maxTorque,edk::float32 speed);
    //remove type
    void removeType();
    //GETERS
    edk::uint8 getWheelType();
    edk::float32 getMaxTorque();
    edk::float32 getSpeed();

    //draw the joint in debug mode
    virtual void draw(edk::size2f32 size,edk::color3f32 color);

    //add an vector
    edk::vec2f32 direction;
    edk::float32 frequency;
    edk::float32 dampingRatio;
private:
    edk::float32 maxTorque;
    edk::float32 speed;
    edk::uint8 WheelType;
};
}
}

#endif // WHEELJOINT2D_H
