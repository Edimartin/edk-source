#ifndef PHYSICOBJECT2D_H
#define PHYSICOBJECT2D_H

/*
Library PhysicObject2D - Object used in 2D physics engine for EDK
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
#pragma message "Inside PhysicObject2D"
#endif

#pragma once
#include "../Object2D.h"
#include "../Math.h"
#include "../TypeDefines.h"
#include "PhysicsMesh2D.h"
#include "../animation/Path2DGroup.h"

#ifdef printMessages
#pragma message "    Compiling PhysicObject2D"
#endif

namespace edk{
namespace physics2D{
class PhysicObject2D : public edk::Object2D{
public:
    PhysicObject2D();
    ~PhysicObject2D();
    //physics meshs
    edk::physics2D::PhysicsMesh2D physicMesh;

    //clean the obect
    virtual void clean();

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

    //function to calculate physicBoundingBox
    bool calculatePhysicBoundingBox();
    bool calculatePhysicBoundingBox(edk::vector::Matrix<edk::float32,3,3>* transformMat);
    bool generatePhysicBoundingBox();
    bool generatePhysicBoundingBox(edk::vector::Matrix<edk::float32,3,3>* transformMat);
    //return a copy of the physicBoundingBox
    edk::rectf32 getPhysicBoundingBox();

    void removeAllMesh();

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

    void drawPhysics();
    void drawWirePhysics();
    void drawPolygonPhysics(edk::uint32 position);
    void drawPolygonWirePhysics(edk::uint32 position);

    //update all animations
    virtual bool updateAnimations();
    virtual bool updateAnimations(edk::float32 seconds);

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id,bool connected=false);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id);
    static bool readFromXMLisSensor(edk::XML* xml,edk::uint32 id);

    //clone the physics mesh from mesh in a position
    bool clonePhysicsMeshFromMeshPosition(edk::uint32 position);

    virtual bool cloneFrom(edk::physics2D::PhysicObject2D* obj);

    virtual bool cloneFrom(edk::Object2D* obj);

    //set if the body canSleep
    bool canSleep;
private:
    edk::rectf32 physicBoundingBox;
    //transform matrices
    edk::vector::Matrix<edk::float32,3u,3u> physicMatrixPosition;
    edk::vector::Matrix<edk::float32,3u,3u> physicMatrixPivo;
    edk::vector::Matrix<edk::float32,3u,3u> physicMatrixAngle;
    edk::vector::Matrix<edk::float32,3u,3u> physicMatrixSize;
    edk::vector::Matrix<edk::float32,3,3> physicMatrixTransform;

    virtual edk::physics2D::PhysicObject2D operator=(edk::physics2D::PhysicObject2D obj){
        //copy the object
        this->cloneFrom(&obj);edkEnd();
        //copy the mesh
        //this->physicMesh=obj.physicMesh;edkEnd();
        this->physicMesh.cloneFrom(&obj.physicMesh);edkEnd();
        this->canSleep = obj.canSleep;edkEnd();
        this->fixedRotation = obj.fixedRotation;edkEnd();
        //this->animationPosition = obj.animationPosition;edkEnd();
        this->animationPosition.cloneFrom(&obj.animationPosition);edkEnd();
        //this->animationRotation = obj.animationRotation;edkEnd();
        this->animationRotation.cloneFrom(&obj.animationRotation);edkEnd();
        obj.cantDeleteObject2D();edkEnd();
        return obj;edkEnd();
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

    edk::vector::BinaryTree<edk::uint32> treeCollisionGroups;
    edk::vector::BinaryTree<edk::uint32> treeNotCollisionGroups;
};
}//end namespace physics
}//end namespace edk

#endif // PHYSICOBJECT2D_H
