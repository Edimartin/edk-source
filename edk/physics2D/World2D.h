#ifndef WORLD2D_H
#define WORLD2D_H

/*
Library World2D - Physics World2D
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
#pragma message "Inside ContactCallback2D"
#endif

#pragma once
#ifndef EDK_NO_BOX2D
#ifndef EDK_USE_BOX2D
#define EDK_USE_BOX2D
//#pragma message "EDK WARNING: As default EDK use Box2D, If you don't want use 2D physics you can define EDK_NO_BOX2D"
#endif
#endif

#include "../TypeDefines.h"
#if defined(EDK_USE_BOX2D)
#include "../../box2d/box2d.h"
#endif
#include "../TypeVars.h"
#include "../TypeVec2.h"
#include "PhysicObject2D.h"
#include "StaticSensor2D.h"
#include "KinematicSensor2D.h"
#include "DynamicObject2D.h"
#include "PrismaticJoint2D.h"
#include "Contact2D.h"
#include "../Math.h"
#include "../vector/BinaryTree.h"
#include "Joint2D.h"
#include "MouseJoint2D.h"
#include "RevoluteJoint2D.h"
#include "DistanceJoint2D.h"
#include "PrismaticJoint2D.h"
#include "PulleyJoint2D.h"
#include "WheelJoint2D.h"
#include "TreeContactObjects.h"
//REMOVE IN NEW BOX2D
//#include "RopeJoint2D.h"

#define angleDistLimit 10
#define positionDistLimit 10

#ifdef printMessages
#pragma message "    Compiling ContactCallback2D"
#endif

namespace edk{
namespace physics2D{
//Animation abstract to callback
class ContactCallback2D{
public:
    ContactCallback2D(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~ContactCallback2D(){
        this->Destructor();
    }

    void Constructor(){
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
        }
    }

    virtual void contact2DBegin(edk::physics2D::Contact2D*){}
    virtual void contact2DEnd(edk::physics2D::Contact2D*){}
    virtual void contact2DKeepBegin(edk::physics2D::Contact2D*){}
    virtual void contact2DKeepEnd(edk::physics2D::Contact2D*){}
    //contact sensors
    virtual void sensor2DBegin(edk::physics2D::Contact2D*){}
    virtual void sensor2DEnd(edk::physics2D::Contact2D*){}
    virtual void sensor2DKeeping(edk::physics2D::Contact2D*){}
private:
    edk::classID classThis;
};

class World2D{
public:
    World2D();
    virtual ~World2D();

    void Constructor();
    void Destructor();

    //Set the gravity
    void setGravity(edk::vec2f32 gravity);
    void setGravity(edk::float32 x,edk::float32 y);
    //set the percent
    void setMeterDistance(edk::float32 meter);
    void setMeterDistance(edk::uint8 meter);
    void setMeterDistance(edk::uint16 meter);
    void setMeterDistance(edk::uint32 meter);
    void setMeterDistance(edk::uint64 meter);
    edk::float32 getMeterDistance();

    //Add a Object to the world
    bool addObject(edk::physics2D::PhysicObject2D* object);
    //remove the object from the world
    bool removeObject(edk::physics2D::PhysicObject2D* object);
    //remove all objects
    void removeAllObjects();
    //test if have the object
    bool haveObject(edk::physics2D::PhysicObject2D* object);
    //get Objects
    edk::uint32 getStaticObjectsSize();
    edk::physics2D::PhysicObject2D* getStaticObjectInPosition(edk::uint32 position);
    edk::uint32 getDynamicObjectsSize();
    edk::physics2D::PhysicObject2D* getDynamicObjectInPosition(edk::uint32 position);
    edk::uint32 getKinematicObjectsSize();
    edk::physics2D::PhysicObject2D* getKinematicObjectInPosition(edk::uint32 position);

    //update the object position in the world
    bool updateObjectVelocity(edk::physics2D::PhysicObject2D* object);
    bool updateObjectLinearVelocity(edk::physics2D::PhysicObject2D* object);
    bool updateObjectAngularVelocity(edk::physics2D::PhysicObject2D* object);
    bool cleanObjectVelocity(edk::physics2D::PhysicObject2D* object);
    bool updateObjectStatus(edk::physics2D::PhysicObject2D* object);
    bool updateObjectPosition(edk::physics2D::PhysicObject2D* object);
    bool updateObjectPositionX(edk::physics2D::PhysicObject2D* object);
    bool updateObjectPositionY(edk::physics2D::PhysicObject2D* object);
    bool updateObjectSyncronizePosition(edk::physics2D::PhysicObject2D* object);
    bool updateObjectSyncronizePositionX(edk::physics2D::PhysicObject2D* object);
    bool updateObjectSyncronizePositionY(edk::physics2D::PhysicObject2D* object);
    bool updateObjectAngle(edk::physics2D::PhysicObject2D* object);
    bool updateObjectPositionAndAngle(edk::physics2D::PhysicObject2D* object);
    bool updateObjectPositionXAndAngle(edk::physics2D::PhysicObject2D* object);
    bool updateObjectPositionYAndAngle(edk::physics2D::PhysicObject2D* object);
    //move the object to a position
    bool moveObject(edk::physics2D::PhysicObject2D* object,edk::vec2f32 move);
    bool moveObject(edk::physics2D::PhysicObject2D* object,edk::float32 x,edk::float32 y);
    bool moveObjectToPosition(edk::physics2D::PhysicObject2D* object,edk::vec2f32 position);
    bool moveObjectToPosition(edk::physics2D::PhysicObject2D* object,edk::float32 positionX,edk::float32 positionY);
    //rotate the object
    bool rotateObject(edk::physics2D::PhysicObject2D* object,edk::float32 angle);
    bool rotateObjectToAngle(edk::physics2D::PhysicObject2D* object,edk::float32 angle);
    //Put a object to sleep
    bool sleepObject(edk::physics2D::PhysicObject2D* object);
    bool unsleepObject(edk::physics2D::PhysicObject2D* object);
    //Add a force to the object
    bool setLinearVelocity(edk::physics2D::PhysicObject2D* object,edk::vec2f32 vector);
    bool setLinearVelocity(edk::physics2D::PhysicObject2D* object,edk::float32 x, edk::float32 y);
    bool setAngularVelocity(edk::physics2D::PhysicObject2D* object,edk::float32 angle);
    //Apply forces
    bool applyForce(edk::physics2D::PhysicObject2D* object,edk::vec2f32 force, edk::vec2f32 position,bool wake);
    bool applyLinearImpulse(edk::physics2D::PhysicObject2D* object,edk::vec2f32 impulse, edk::vec2f32 position,bool wake);
    bool applyAngularImpulse(edk::physics2D::PhysicObject2D* object,edk::float32 angle,bool wake);
    bool applyTorque(edk::physics2D::PhysicObject2D* object,edk::float32 torque,bool wake);

    //process the next step
    void nextStep(edk::float32 timeStep, edk::int32 velocityIterations, edk::int32 positionIterations);
    //next spet with clock
    void nextStep(edk::int32 velocityIterations, edk::int32 positionIterations);
    //pause the world steps
    void pauseStepOn();
    void pauseStepOff();

    //reset the clock
    void clockStart();
    //set clockScale
    void setClockScale(edk::float32 clockScale);


    //return the size of contacts
    edk::uint32 getContactSize();
    //return the contact
    edk::physics2D::Contact2D* getContact(edk::uint32 position);

    /*
    BOX 2D JOINTS

    DistanceJoint OK
    FrictionJoint
    GearJoint
    MotorJoint OK
    MouseJoint OK
    PrismaticJoint OK
    PulleyJoint OK
    RevoluteJoint OK
    WeldJoint OK
    WheelJoint OK
    */


    //joints
    //MOUSE
    edk::physics2D::MouseJoint2D* createMouseJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,edk::vec2f32 positionB);
    edk::physics2D::MouseJoint2D* createMouseJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 worldPosition);

    //REVOLUTE
    edk::physics2D::RevoluteJoint2D* createRevoluteJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                         edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                         bool collide=false
            );
    edk::physics2D::RevoluteJoint2D* createRevoluteJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                         bool collide=false
            );
    edk::physics2D::RevoluteJoint2D* createRevoluteAngleJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                              edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                              edk::float32 lowerAngle,edk::float32 upperAngle,
                                                              bool collide=false
            );
    edk::physics2D::RevoluteJoint2D* createRevoluteAngleJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                              edk::float32 lowerAngle,edk::float32 upperAngle,
                                                              bool collide=false
            );
    edk::physics2D::RevoluteJoint2D* createRevoluteMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                              edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                              edk::float32 maxTorque,edk::float32 speed,
                                                              bool collide=false
            );
    edk::physics2D::RevoluteJoint2D* createRevoluteMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                              edk::float32 maxTorque,edk::float32 speed,
                                                              bool collide=false
            );
    //PRISMATIC
    edk::physics2D::PrismaticJoint2D* createPrismaticJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                           edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                           edk::vec2f32 direction, edk::float32 lowerDistance, edk::float32 upperDistance,
                                                           bool collide=false
            );
    edk::physics2D::PrismaticJoint2D* createPrismaticJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                           edk::vec2f32 direction, edk::float32 lowerDistance, edk::float32 upperDistance,
                                                           bool collide=false
            );
    edk::physics2D::PrismaticJoint2D* createPrismaticJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                           edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                           edk::float32 angle, edk::float32 lowerDistance, edk::float32 upperDistance,
                                                           bool collide=false
            );
    edk::physics2D::PrismaticJoint2D* createPrismaticJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                           edk::float32 angle, edk::float32 lowerDistance, edk::float32 upperDistance,
                                                           bool collide=false
            );
    edk::physics2D::PrismaticJoint2D* createPrismaticMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                                edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                                edk::vec2f32 direction, edk::float32 lowerDistance, edk::float32 upperDistance,
                                                                edk::float32 maxForce,edk::float32 speed,
                                                                bool collide=false
            );
    edk::physics2D::PrismaticJoint2D* createPrismaticMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                                edk::vec2f32 direction, edk::float32 lowerDistance, edk::float32 upperDistance,
                                                                edk::float32 maxForce,edk::float32 speed,
                                                                bool collide=false
            );
    edk::physics2D::PrismaticJoint2D* createPrismaticMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                                edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                                edk::float32 angle, edk::float32 lowerDistance, edk::float32 upperDistance,
                                                                edk::float32 maxForce,edk::float32 speed,
                                                                bool collide=false
            );
    edk::physics2D::PrismaticJoint2D* createPrismaticMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                                edk::float32 angle, edk::float32 lowerDistance, edk::float32 upperDistance,
                                                                edk::float32 maxForce,edk::float32 speed,
                                                                bool collide=false
            );
    //DISTANCE
    edk::physics2D::DistanceJoint2D* createDistanceJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                         edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                         edk::float32 distance,
                                                         bool collide=false
            );
    edk::physics2D::DistanceJoint2D* createDistanceJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 worldPositionA,
                                                         edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPositionB,
                                                         bool collide=false
            );
    //PULLEY
    edk::physics2D::PulleyJoint2D* createPulleyJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA, edk::vec2f32 pulleyPositionA,
                                                     edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB, edk::vec2f32 pulleyPositionB,
                                                     edk::float32 lenghtA,edk::float32 lenghtB,
                                                     bool collide=false
            );
    edk::physics2D::PulleyJoint2D* createPulleyJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA, edk::vec2f32 pulleyPositionA,
                                                     edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB, edk::vec2f32 pulleyPositionB,
                                                     bool collide=false
            );
    edk::physics2D::PulleyJoint2D* createPulleyWorldJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 worldPositionA, edk::vec2f32 pulleyWorldPositionA,
                                                          edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPositionB, edk::vec2f32 pulleyWorldPositionB,
                                                          edk::float32 lenghtA,edk::float32 lenghtB,
                                                          bool collide=false
            );
    edk::physics2D::PulleyJoint2D* createPulleyWorldJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 worldPositionA, edk::vec2f32 pulleyWorldPositionA,
                                                          edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPositionB, edk::vec2f32 pulleyWorldPositionB,
                                                          bool collide=false
            );
    //WHEEL
    edk::physics2D::WheelJoint2D* createWheelJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                   edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                   edk::vec2f32 direction,
                                                   bool collide=false
            );
    edk::physics2D::WheelJoint2D* createWheelJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                   edk::vec2f32 direction,
                                                   bool collide=false
            );
    edk::physics2D::WheelJoint2D* createWheelMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                        edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                        edk::vec2f32 direction,
                                                        edk::float32 maxTorque,edk::float32 speed,
                                                        bool collide=false
            );
    edk::physics2D::WheelJoint2D* createWheelMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                        edk::vec2f32 direction,
                                                        edk::float32 maxTorque,edk::float32 speed,
                                                        bool collide=false
            );
    //WELD
    edk::physics2D::Joint2D* createWeldJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                             edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                             bool collide=false
            );
    edk::physics2D::Joint2D* createWeldJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                             bool collide=false
            );
    //ROPE //REMOVED FROM NEW BOX2D
    /*
    edk::physics2D::RopeJoint2D* createRopeJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                 edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                 edk::float32 maxLength,
                                                 bool collide=false
                                                 );
    edk::physics2D::RopeJoint2D* createRopeJointWorldPositions(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 worldPositionA,
                                                               edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPositionB,
                                                               edk::float32 maxLength,
                                                               bool collide=false
                                                               );
    edk::physics2D::RopeJoint2D* createRopeJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 worldPositionA,
                                                 edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPositionB,
                                                 bool collide=false
                                                 );
    */
    //GEAR
    /*
    edk::physics2D::RopeJoint2D* createGearJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                 edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                 edk::float32 distance,
                                                 bool collide=false
                                                 );
*/

    //destroy the joint
    bool destroyJoint(edk::physics2D::Joint2D* joint);
    bool inline deleteJoint(edk::physics2D::Joint2D* joint){return this->destroyJoint(joint);}
    //destroy joint with the object
    bool destroyObjectJoints(edk::physics2D::PhysicObject2D* object);
    //return the joint
    edk::physics2D::Joint2D* getJointInPosition(edk::uint32 position);
    //get Joint Type
    edk::uint8 getJointTypeInPosition(edk::uint32 position);
    //return the joints count
    edk::uint32 getJointSize();


    //update the joints
    bool setMotorJointMaxTorque(edk::physics2D::Joint2D* joint,edk::float32 maxTorque);
    bool setMotorJointSpeed(edk::physics2D::Joint2D* joint,edk::float32 speed);
    //Set the torque and speed
    bool setMotorJointTorqueAndSpeed(edk::physics2D::Joint2D* joint,edk::float32 maxTorque,edk::float32 speed);
    //Return the joints
    edk::float32 getRevoluteJointAngle(edk::physics2D::Joint2D* joint);
    edk::float32 getMotorJointTorque(edk::physics2D::Joint2D* joint);
    edk::float32 getMotorJointSpeed(edk::physics2D::Joint2D* joint);
    //set the mouse target
    bool setMouseJointTarget(edk::physics2D::MouseJoint2D* mouseJoint,edk::vec2f32 target);
    bool setMouseJointTarget(edk::physics2D::MouseJoint2D* mouseJoint,edk::float32 x,edk::float32 y);


    //contact functions
    virtual void contact2DBegin(edk::physics2D::Contact2D* contact);
    virtual void contact2DEnd(edk::physics2D::Contact2D* contact);
    virtual void contact2DKeepBegin(edk::physics2D::Contact2D* contact);
    virtual void contact2DKeepEnd(edk::physics2D::Contact2D* contact);
    //contact sensors
    virtual void sensor2DBegin(edk::physics2D::Contact2D* contact);
    virtual void sensor2DEnd(edk::physics2D::Contact2D* contact);
    virtual void sensor2DKeeping(edk::physics2D::Contact2D* contact);

    //Add contactCallback
    bool addContactCallback(edk::physics2D::ContactCallback2D* callback);
    bool removeContactCallback(edk::physics2D::ContactCallback2D* callback);

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

private:
    //world percent to have bigger objects in the engine but smaller objects in the physics world
    edk::float32 percentIn;
    edk::float32 percentOut;

    edk::vec2f32 gravity;

    //clock
    edk::watch::Time clock;
    edk::float32 clockScale;

    //save if it's running the nextStep
    bool runNextStep;
    bool paused;

#if defined(EDK_USE_BOX2D)
    //Box2D
    b2World world;
#endif

    //TREE WITH OBJECTS IN CONTACT
    edk::physics2D::TreeContactObjects beginContacs;
    edk::physics2D::TreeContactObjects keepBeginContacs;
    edk::physics2D::TreeContactObjects keepEndContacs;
    edk::physics2D::TreeContactObjects endContacs;
    edk::physics2D::TreeContactObjects sensorBeginContacs;
    edk::physics2D::TreeContactObjects sensorKeepContacs;
    edk::physics2D::TreeContactObjects sensorEndContacs;

#if defined(EDK_USE_BOX2D)
    //return the body
    b2Body* getBody(edk::physics2D::PhysicObject2D* object);
#endif

    //Add a joint to the trees
    edk::physics2D::Joint2D* addJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                      edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB
                                      );
    bool addJoint(edk::physics2D::Joint2D* joint);
    //remove joint
    bool removeObjectJoints(edk::physics2D::PhysicObject2D* object);

    //contact functions
    void physicsContactBegin(edk::physics2D::Contact2D* contact);
    void physicsContactEnd(edk::physics2D::Contact2D* contact);
    void physicsContactKeepBegin(edk::physics2D::Contact2D* contact);
    void physicsContactKeepEnd(edk::physics2D::Contact2D* contact);
    //contact sensors
    void physicsSensorBegin(edk::physics2D::Contact2D* contact);
    void physicsSensorEnd(edk::physics2D::Contact2D* contact);
    void physicsSensorKeeping(edk::physics2D::Contact2D* contact);

    //contactTree
    edk::vector::BinaryTree<edk::physics2D::ContactCallback2D*> treeCallbacks;

#if defined(EDK_USE_BOX2D)
    //class to save the object
    class ObjectTree{
    public:
        ObjectTree(edk::physics2D::PhysicObject2D* object,b2Body* body){
            this->classThis=NULL;
            this->Constructor(object,body);
        }
        virtual ~ObjectTree(){
            this->Destructor();
        }

        void Constructor(edk::physics2D::PhysicObject2D* object,b2Body* body){
            if(this->classThis!=this){
                this->classThis=this;
                this->object=object;
                this->body=body;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
            }
        }
        edk::physics2D::PhysicObject2D* object;
        b2Body* body;
    private:
        edk::classID classThis;
    };
    //Physics TREE
    class treeObjects:public edk::vector::BinaryTree<ObjectTree*>{
    public:
        treeObjects(){}
        ~treeObjects(){
            this->cleanAllBodys();
        }

        void cleanAllBodys(){
            edk::uint32 size = this->size();
            ObjectTree* temp;
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->getElementInPosition(i);
                if(temp){
                    delete temp;
                }
            }
            this->clean();
        }

        //compare if the value is bigger
        bool firstBiggerSecond(ObjectTree* first,ObjectTree* second){
            //
            if(first->object>second->object){
                //
                return true;
            }
            return false;
        }
        bool firstEqualSecond(ObjectTree* first,ObjectTree* second){
            //
            if(first->object==second->object){
                //
                return true;
            }
            return false;
        }
        //UPDATE
        virtual void updateElement(ObjectTree* value){
            if(value->body){
                //update the value
                edk::physics2D::PhysicObject2D* obj = (edk::physics2D::PhysicObject2D*)value->body->GetUserData().pointer;
                if(obj){
                    obj->position.x = value->body->GetPosition().x * this->percentOut;
                    obj->position.y = value->body->GetPosition().y * this->percentOut;
                    if(!obj->fixedRotation){
                        obj->angle = value->body->GetAngle() * (180.f / b2_pi);
                    }
                    obj->setLinearVelocity(value->body->GetLinearVelocity().x * this->percentOut,value->body->GetLinearVelocity().y);
                    obj->getLinearVelocity();
                    obj->setAngularVelocity(value->body->GetAngularVelocity() * (180.f / b2_pi));
                    obj->getAngularVelocity();
                    //test if can sleep
                    if(!obj->canSleep && obj->getType()==edk::TypeObject2DDynamic){
                        //set awake to true
                        value->body->SetAwake(true);
                    }

                    //clean the use of fixed positions
                    value->body->cleanUpdates();
                }
            }
        }
        //return the body
        inline b2Body* getBody(edk::physics2D::PhysicObject2D* obj){
            if(obj){
                edk::physics2D::World2D::ObjectTree find(obj,NULL);
                edk::physics2D::World2D::ObjectTree* temp = this->getElement(&find);
                if(temp){
                    return temp->body;
                }
            }
            return NULL;
        }
        //return the body in the position
        inline b2Body* getBodyInPosition(edk::uint32 position){
            edk::physics2D::World2D::ObjectTree* temp = this->getElementInPosition(position);
            if(temp){
                return temp->body;
            }
            return NULL;
        }
        inline bool haveBody(edk::physics2D::PhysicObject2D* obj){
            if(obj){
                edk::physics2D::World2D::ObjectTree find(obj,NULL);
                return this->haveElement(&find);
            }
            return false;
        }
        //add the body
        bool addBody(edk::physics2D::PhysicObject2D* object,b2Body* body){
            //load the object
            edk::physics2D::World2D::ObjectTree* temp = new edk::physics2D::World2D::ObjectTree(object,body);
            if(temp){
                //add the new temp
                if(this->add(temp)){
                    //return true
                    return true;
                }
                //else delete temp
                delete temp;
            }
            return false;
        }
        //remove Body
        bool removeBody(b2Body* body){
            //
            if(body){
                edk::physics2D::World2D::ObjectTree find((edk::physics2D::PhysicObject2D*)body->GetUserData().pointer,body);
                edk::physics2D::World2D::ObjectTree* temp = this->getElement(&find);
                if(temp){
                    if(this->remove(temp)){
                        delete temp;
                        return true;
                    }
                }
            }
            return false;
        }
        edk::float32 percentIn;
        edk::float32 percentOut;
    }treeStatic,treeKinematic,treeDynamic;

    //deletedTree
    class DeletedTree: public edk::vector::BinaryTree<edk::physics2D::PhysicObject2D*>{
    public:
        DeletedTree(b2World* world,edk::physics2D::World2D* worldEDK){
            this->classThis=NULL;
            this->Constructor(world,worldEDK);
        }
        virtual ~DeletedTree(){
            this->Destructor();
        }

        void Constructor(b2World* world,edk::physics2D::World2D* worldEDK){
            edk::vector::BinaryTree<edk::physics2D::PhysicObject2D*>::Constructor();
            if(this->classThis!=this){
                this->classThis=this;
                this->world = world;
                this->worldEDK=worldEDK;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
            }
            edk::vector::BinaryTree<edk::physics2D::PhysicObject2D*>::Destructor();
        }
        void updateElement(edk::physics2D::PhysicObject2D* value){
            //update the value
            if(value){
                //this->world->DestroyBody(value);
                this->worldEDK->removeObject(value);
            }
        }
        //Box2D
        b2World* world;
    private:
        edk::physics2D::World2D* worldEDK;
    private:
        edk::classID classThis;
    }treeDeleted;
#endif

    //newTree
    class NewTree: public edk::vector::BinaryTree<edk::physics2D::PhysicObject2D*>{
    public:
        NewTree(edk::physics2D::World2D* world){
            this->classThis=NULL;
            this->Constructor(world);
        }
        virtual ~NewTree(){
            this->Destructor();
        }

        void Constructor(edk::physics2D::World2D* world){
            edk::vector::BinaryTree<edk::physics2D::PhysicObject2D*>::Constructor();
            if(this->classThis!=this){
                this->classThis=this;
                this->world = world;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
            }
            edk::vector::BinaryTree<edk::physics2D::PhysicObject2D*>::Destructor();
        }
        //NEW OBJECT
        virtual void printElement(edk::physics2D::PhysicObject2D* value){
            if(!this->world->runNextStep){
                this->world->addObject(value);
            }
        }
        //SET LINEAR VELOCITY
        virtual void renderElement(edk::physics2D::PhysicObject2D* value){
            if(!this->world->runNextStep){
                this->world->updateObjectLinearVelocity(value);
            }
        }
        //SET ANGULAR VELOCITY
        void updateElement(edk::physics2D::PhysicObject2D* value){
            if(!this->world->runNextStep){
                this->world->updateObjectAngularVelocity(value);
            }
        }
        //edkWorld
        edk::physics2D::World2D* world;
    private:
        edk::classID classThis;
    }treeNew,treeLinearVelocity,treeAngularVelocity;

    //ContactTree
    class TreeConcacts:public edk::vector::BinaryTree<edk::physics2D::Contact2D*>{
    public:
        TreeConcacts(){}
        //compare if the value is bigger
        bool firstBiggerSecond(edk::physics2D::Contact2D* first,edk::physics2D::Contact2D* second){
            //
            if(first->getContactPointer()>second->getContactPointer()){
                //
                return true;
            }
            else if(first->getContactPointer()==second->getContactPointer()){
                if(first->getContactBodyA()>second->getContactBodyA()){
                    //
                    return true;
                }
                else if(first->getContactBodyA()==second->getContactBodyA()){
                    if(first->getContactBodyB()>second->getContactBodyB()){
                        //
                        return true;
                    }
                }
            }
            return false;
        }
        bool firstEqualSecond(edk::physics2D::Contact2D* first,edk::physics2D::Contact2D* second){
            //
            if(first->getContactPointer()==second->getContactPointer()
                    && first->getContactBodyA()==second->getContactBodyA()
                    && first->getContactBodyB()==second->getContactBodyB()
                    ){
                //
                return true;
            }
            return false;
        }
        //return the contact
        inline edk::physics2D::Contact2D* getContact(edk::classID pointer,
                                                     edk::classID pointerBodyA,
                                                     edk::classID pointerBodyB
                                                     ){
            edk::physics2D::Contact2D* ret=NULL;
            edk::physics2D::Contact2D find(pointer,pointerBodyA,pointerBodyB);
            ret=this->getElement(&find);
            if(ret){
                return ret;
            }
            edk::physics2D::Contact2D find2(pointer,pointerBodyB,pointerBodyA);
            return this->getElement(&find2);
        }
    }treeConcacts,treeSensorConcacts;

#if defined(EDK_USE_BOX2D)
    class MyContactListener : public b2ContactListener {
    public:
        MyContactListener();
        MyContactListener(edk::physics2D::World2D* world);
        virtual ~MyContactListener();

        void Constructor();
        void Constructor(edk::physics2D::World2D* world);
        void Destructor();

        void BeginContact(b2Contact* contact);
        void EndContact(b2Contact* contact);
        void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
        void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
        edk::physics2D::World2D* world;
        edk::float32 percentIn;
        edk::float32 percentOut;
        bool cleaningWorld;
    private:
        edk::classID classThis;
    }contacts;



    //class to save the joint
    class JointTreeObject{
    public:
        JointTreeObject(edk::physics2D::Joint2D* joint,b2Joint* boxJoint){
            this->classThis=NULL;
            this->Constructor(joint,boxJoint);
        }
        virtual ~JointTreeObject(){
            this->Destructor();
        }

        void Constructor(edk::physics2D::Joint2D* joint,b2Joint* boxJoint){
            if(this->classThis!=this){
                this->classThis=this;
                this->joint=joint; this->boxJoint=boxJoint;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
            }
        }
        edk::physics2D::Joint2D* joint;
        b2Joint* boxJoint;

        //return the world position on the body for the joint
        static edk::vec2f32 getJointPosition(edk::physics2D::PhysicObject2D* object,edk::vec2f32 worldPosition){
            edk::vec2f32 ret;
            //translate
            ret  = worldPosition - object->position;
            //and rotate the worldPosition
            if(object->angle){
                ret = edk::Math::rotate(ret,object->angle * -1);
            }
            return ret;
        }

        //return the joint position in the world
        static edk::vec2f32 getJointWorldPosition(edk::physics2D::PhysicObject2D* object,edk::vec2f32 jointPosition){
            edk::vec2f32 ret;
            //and rotate the worldPosition
            if(object->angle){
                //rotate
                ret = edk::Math::rotatePlus(jointPosition,object->angle);
                //translate
                ret+=object->position;
            }
            else{
                //translate
                ret = jointPosition + object->position;
            }
            return ret;
        }
    private:
        edk::classID classThis;
    };

    //Joint Tree
    class TreeJoint:public edk::vector::BinaryTree<edk::physics2D::World2D::JointTreeObject*>{
    public:
        //compare if the value is bigger
        bool firstBiggerSecond(edk::physics2D::World2D::JointTreeObject* first,edk::physics2D::World2D::JointTreeObject* second){
            if(first->joint>second->joint){
                return true;
            }
            return false;
        }
        bool firstEqualSecond(edk::physics2D::World2D::JointTreeObject* first,edk::physics2D::World2D::JointTreeObject* second){
            if(first->joint==second->joint){
                return true;
            }
            return false;
        }
        bool haveJoint(edk::physics2D::Joint2D* joint){
            if(joint){
                edk::physics2D::World2D::JointTreeObject find(joint,NULL);
                return this->haveElement(&find);
            }
            return false;
        }
        //return the joint
        b2Joint* getJoint(edk::physics2D::Joint2D* joint){
            if(joint){
                edk::physics2D::World2D::JointTreeObject find(joint,NULL);
                edk::physics2D::World2D::JointTreeObject* temp = this->getElement(&find);
                if(temp){
                    return temp->boxJoint;
                }
            }
            return NULL;
        }
        bool addJoint(edk::physics2D::Joint2D* joint,b2Joint* boxJoint){
            //create the joint
            edk::physics2D::World2D::JointTreeObject* temp = new edk::physics2D::World2D::JointTreeObject(joint,boxJoint);
            if(temp){
                //set the boxJoint
                if(this->add(temp)){
                    //return true
                    return true;
                }
                //else delete the temp
                delete temp;
            }
            return false;
        }
        //remove the joint
        bool removeJoint(b2Joint* joint){
            if(joint){
                edk::physics2D::World2D::JointTreeObject find((edk::physics2D::Joint2D*)joint->GetUserData().pointer,joint);
                edk::physics2D::World2D::JointTreeObject* temp = this->getElement(&find);
                if(temp){
                    if(this->remove(temp)){
                        delete temp;
                        return true;
                    }
                }
            }
            return false;
        }
        //return the joint in the position
        b2Joint* getB2JointInPosition(edk::uint32 position){
            edk::physics2D::World2D::JointTreeObject* temp = this->getElementInPosition(position);
            if(temp){
                return temp->boxJoint;
            }
            return NULL;
        }
        edk::physics2D::Joint2D* getJointInPosition(edk::uint32 position){
            edk::physics2D::World2D::JointTreeObject* temp = this->getElementInPosition(position);
            if(temp){
                if(temp->joint){
                    return temp->joint;
                }
            }
            return NULL;
        }
        //UPDATE
        virtual void updateElement(edk::physics2D::World2D::JointTreeObject* value){
            if(value->joint && value->boxJoint){
                if(value->joint->objectA
                        &&
                        value->joint->objectB
                        ){
                    //load the worldPosition
                    value->joint->worldPositionA =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(value->joint->objectA,
                                                                                            value->joint->positionA
                                                                                            );

                    switch(value->joint->getType()){
                    case EDK_PULLEY_JOINT:
                    case EDK_DISTANCE_JOINT:
                    {
                        edk::physics2D::DistanceJoint2D* temp = (edk::physics2D::DistanceJoint2D*)value->joint;
                        temp->worldPositionB =
                                edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(value->joint->objectB,
                                                                                                value->joint->positionB
                                                                                                );
                    }
                        break;
                        //
                    }
                }
            }
        }
    }treeJoint;
#endif

    class ObjectJointsTree:private edk::vector::BinaryTree<edk::physics2D::Joint2D*>{
    public:
        ObjectJointsTree(edk::physics2D::PhysicObject2D* objA,edk::physics2D::PhysicObject2D* objB){
            this->pointerA = objA;
            this->pointerB = objB;
        }
        //Add a joint
        bool addJoint(edk::physics2D::Joint2D* joint);
        //return the joint in the position
        inline edk::physics2D::Joint2D* getJointInPosition(edk::uint32 position);
        //return the size of the joint
        edk::uint32 getSize();
        //remove joint
        bool removeJoint(edk::physics2D::Joint2D* joint);
        //remove joint in position
        bool removeJointInPosition(edk::uint32 position);
        //clean the joints
        void cleanJoints();
        //return the pointer
        edk::physics2D::PhysicObject2D* getPointerA(){return this->pointerA;}
        edk::physics2D::PhysicObject2D* getPointerB(){return this->pointerB;}
    private:
        //save the objectPointer
        edk::physics2D::PhysicObject2D* pointerA;
        edk::physics2D::PhysicObject2D* pointerB;
    };

    //ObjectTree for joints
    class ObjectsJointsTree:private edk::vector::BinaryTree<edk::physics2D::World2D::ObjectJointsTree*>{
    public:
        ObjectsJointsTree(edk::physics2D::PhysicObject2D* obj):pointer(obj){}

        //add a joint
        bool addJoint(edk::physics2D::World2D::ObjectJointsTree* joint);
        //return the joint
        inline edk::physics2D::World2D::ObjectJointsTree* getJoint(edk::physics2D::PhysicObject2D* object);
        //return the joint in the position
        inline edk::physics2D::World2D::ObjectJointsTree* getJointInPosition(edk::uint32 position);
        //return the size of the joint
        edk::uint32 getSize();
        //remove joint
        bool removeJoint(edk::physics2D::PhysicObject2D* object);
        bool removeJoint(edk::physics2D::World2D::ObjectJointsTree* joint);
        //clean the joints
        void cleanJoints();

        //return the pointer
        edk::physics2D::PhysicObject2D* getPointer();

    private:
        //compare if the value is bigger
        bool firstBiggerSecond(edk::physics2D::World2D::ObjectJointsTree* first,edk::physics2D::World2D::ObjectJointsTree* second);
        bool firstEqualSecond(edk::physics2D::World2D::ObjectJointsTree* first,edk::physics2D::World2D::ObjectJointsTree* second);
    private:
        //save the objectPointer
        edk::physics2D::PhysicObject2D* pointer;
    };

    //Binary Tree
    class TreeJointObjects:public edk::vector::BinaryTree<ObjectsJointsTree*>{
    public:
        //compare if the value is bigger
        virtual bool firstBiggerSecond(ObjectsJointsTree* first,ObjectsJointsTree* second){
            if(first->getPointer()>second->getPointer()){
                return true;
            }
            return false;
        }
        virtual bool firstEqualSecond(ObjectsJointsTree* first,ObjectsJointsTree* second){
            if(first->getPointer()==second->getPointer()){
                return true;
            }
            return false;
        }
        //return one tree
        inline ObjectsJointsTree* getTreeJoint(edk::physics2D::PhysicObject2D* object){
            ObjectsJointsTree find(object);
            return this->getElement(&find);
        }

    }treeJointObjects;

    //TREE to save the joints
    class ObjectIDs{
    public:
        ObjectIDs(){
            this->classThis=NULL;
            this->Constructor();
        }
        ObjectIDs(edk::physics2D::PhysicObject2D* object,edk::uint32 id){
            this->classThis=NULL;
            this->Constructor(object,id);
        }
        virtual ~ObjectIDs(){
            this->Destructor();
        }

        void Constructor(){
            if(this->classThis!=this){
                this->classThis=this;
                this->object=NULL;
                this->id = 0u;
            }
        }
        void Constructor(edk::physics2D::PhysicObject2D* object,edk::uint32 id){
            if(this->classThis!=this){
                this->classThis=this;
                this->object=object;
                this->id = id;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
            }
        }

        edk::physics2D::PhysicObject2D* object;
        edk::uint32 id;
    private:
        edk::classID classThis;
    };
    //tree
    class TreeObjectID : edk::vector::BinaryTree<edk::physics2D::World2D::ObjectIDs*>{
    public:
        TreeObjectID(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~TreeObjectID(){
            this->Destructor();
        }

        void Constructor(){
            edk::vector::BinaryTree<edk::physics2D::World2D::ObjectIDs*>::Constructor();
            if(this->classThis!=this){
                this->classThis=this;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
                this->removeAllObjects();
            }
            edk::vector::BinaryTree<edk::physics2D::World2D::ObjectIDs*>::Destructor();
        }
        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::physics2D::World2D::ObjectIDs* first,edk::physics2D::World2D::ObjectIDs* second){
            if(first->object>second->object){
                //
                return true;
            }
            return false;
        }
        virtual bool firstEqualSecond(edk::physics2D::World2D::ObjectIDs* first,edk::physics2D::World2D::ObjectIDs* second){
            //
            if(first->object==second->object){
                //
                return true;
            }
            return false;
        }
        //Print
        virtual void printElement(edk::physics2D::World2D::ObjectIDs* value){
            //update the value
            value++;
        }
        //UPDATE
        virtual void updateElement(edk::physics2D::World2D::ObjectIDs* value){
            //update the value
            value++;
        }
        //Add object with id
        bool addObject(edk::physics2D::PhysicObject2D* object,edk::uint32 id){
            //load the object
            edk::physics2D::World2D::ObjectIDs* temp = this->getClass(object);
            if(!temp){
                //create a new ObjectID's
                temp = new edk::physics2D::World2D::ObjectIDs(object,id);
                if(temp){
                    //add the class to the tree
                    if(this->add(temp)){
                        return true;
                    }
                    delete temp;
                }
            }
            return false;
        }
        //test if have the object
        bool haveObject(edk::physics2D::PhysicObject2D* object){
            return (bool)this->getClass(object);
        }
        //return the ID
        edk::uint32 getObjectID(edk::physics2D::PhysicObject2D* object){
            //load the object
            edk::physics2D::World2D::ObjectIDs* temp = this->getClass(object);
            if(temp){
                //return the id
                return temp->id;
            }
            return 0u;
        }
        //remove object
        bool removeObject(edk::physics2D::PhysicObject2D* object){
            //load the object
            edk::physics2D::World2D::ObjectIDs* temp = this->getClass(object);
            if(temp){
                if(this->remove(temp)){
                    //
                    delete temp;
                    return true;
                }
            }
            return false;
        }
        //remove all objects
        void removeAllObjects(){
            edk::uint32 size = 0u;
            for(edk::uint32 i=0u;i<size;i++){
                edk::physics2D::World2D::ObjectIDs* temp = this->getElementInPosition(i);
                if(temp){
                    delete temp;
                }
            }
            this->clean();
        }

    private:
        edk::physics2D::World2D::ObjectIDs* getClass(edk::physics2D::PhysicObject2D* object){
            edk::physics2D::World2D::ObjectIDs find(object,0u);
            return this->getElement(&find);
        }
    private:
        edk::classID classThis;
    };
private:
    edk::classID classThis;
};
}
}

#endif // WORLD2D_H
