#include "KinematicSensor2D.h"

edk::physics2D::KinematicSensor2D::KinematicSensor2D()
{
}

//get the bodyType
edk::uint8 edk::physics2D::KinematicSensor2D::getType(){
    return edk::physics::KinematicBody;
}