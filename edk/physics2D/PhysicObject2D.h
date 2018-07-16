#ifndef PHYSICOBJECT2D_H
#define PHYSICOBJECT2D_H

/*
Library PhysicObject2D - Object used in 2D physics engine for EDK
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#pragma once
#include "../Object2D.h"
#include "../Math.h"
#include "../TypeDefines.h"
#include "PhysicsMesh2D.h"
#include "../animation/Path2DGroup.h"

namespace edk{
namespace physics2D{
class PhysicObject2D : public edk::Object2D{
public:
    PhysicObject2D();
    ~PhysicObject2D();
    //physics meshs
    edk::physics2D::PhysicsMesh2D physicMesh;

    //set the lonearVelocity
    void setLinearVelocity(edk::vec2f32 velocity);
    void setLinearVelocity(edk::float32 x,edk::float32 y);
    void setAngularVelocity(edk::float32 angle);
    //remove all meshes
    void cleanMeshes();
    void cleanMesh();

    //return the speed
    edk::float32 getSpeed();
    //return the direction
    edk::vec2f32 getDirection();
    //return the linearVelocity
    edk::vec2f32 getLinearVelocity();
    //return if set the linearVelocity
    bool haveSettedLinearVelocity();
    //return the angular velocity
    edk::float32 getAngularVelocity();
    //return if set angular velocoty
    bool haveSettedAngularVelocity();

    void removeAllMesh();

    //get the bodyType
    virtual edk::uint8 getType();

    //return if it's a sensor
    virtual bool isSensor();

    //add a group
    bool addCollisionGroup(edk::uint32 id);
    bool addNotCollisionGroup(edk::uint32 id);
    bool removeCollisionGroup(edk::uint32 id);
    bool removeNotCollisionGroup(edk::uint32 id);
    void cleanCollisionGroups();
    void cleanNotCollisionGroups();
    void cleanAllGroups();
    bool haveCollisionGroup(edk::uint32 id);
    bool haveNotCollisionGroup(edk::uint32 id);
    edk::uint32 getCollisionGroupInPosition(edk::uint32 position);
    edk::uint32 getNotCollisionGroupInPosition(edk::uint32 position);
    //get group size
    edk::uint32 getCollisionGroupSize();
    edk::uint32 getNotCollisionGroupSize();

    void drawWirePhysics();

    //update all animations
    virtual bool updateAnimations();

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id,bool connected=false);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);
    static bool readFromXMLisSensor(edk::XML* xml,edk::uint32 id);

    virtual bool cloneFrom(edk::physics2D::PhysicObject2D* obj);

    //set if the body canSleep
    bool canSleep;

    //animarion position
    edk::animation::Path2DGroup animationPosition;
    bool wasAnimatingPosition;
    //Animation rotation
    edk::animation::Path1DGroup animationRotation;
    bool wasAnimatingRotation;
private:
    virtual edk::physics2D::PhysicObject2D operator=(edk::physics2D::PhysicObject2D obj){
        //copy the object
        this->cloneFrom(&obj);
        //copy the mesh
        //this->physicMesh=obj.physicMesh;
        this->physicMesh.cloneFrom(&obj.physicMesh);
        this->canSleep = obj.canSleep;
        this->fixedRotation = obj.fixedRotation;
        //this->animationPosition = obj.animationPosition;
        this->animationPosition.cloneFrom(&obj.animationPosition);
        //this->animationRotation = obj.animationRotation;
        this->animationRotation.cloneFrom(&obj.animationRotation);
        obj.cantDeleteObject2D();
        return obj;
    }

protected:
    //speed of the object
    edk::float32 speed;
    //body direction
    edk::vec2f32 direction;
    //linear velocity
    edk::vec2f32 linearVelocity;
    edk::float32 angularVelocity;
    bool linearVelocitySetted;
    bool angularVelocitySetted;
    bool isObjectSensor;
    edk::uint32 physType;

    edk::vector::BinaryTree<edk::uint32> treeCollisionGroups;
    edk::vector::BinaryTree<edk::uint32> treeNotCollisionGroups;
};
}//end namespace physics
}//end namespace edk

#endif // PHYSICOBJECT2D_H
