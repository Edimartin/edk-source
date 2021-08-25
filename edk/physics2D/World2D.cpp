#include "World2D.h"

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
edk::physics2D::World2D::MyContactListener::MyContactListener(){
    //
    this->world = NULL;
}
edk::physics2D::World2D::MyContactListener::MyContactListener(edk::physics2D::World2D* world){
    //
    this->world = world;
}
void edk::physics2D::World2D::MyContactListener::BeginContact(b2Contact* contact){
    /*
    printf("\nContact Begin %u"
           ,contact
           );fflush(stdout);
*/
    b2Body* bodyA = contact->GetFixtureA()->GetBody();
    b2Body* bodyB = contact->GetFixtureB()->GetBody();
    edk::uint64 shapeA = (edk::uint64)contact->GetFixtureA()->GetUserData();
    edk::uint64 shapeB = (edk::uint64)contact->GetFixtureB()->GetUserData();
    edk::uint8 count = contact->GetManifold()->pointCount;
    if(count){
        //get the contact
        edk::physics2D::Contact2D* contactTemp = this->world->treeConcacts.getContact(contact);

        //test if the two objecs are on the same group
        edk::physics2D::PhysicObject2D* objectA = (edk::physics2D::PhysicObject2D*)bodyA->GetUserData();
        edk::physics2D::PhysicObject2D* objectB = (edk::physics2D::PhysicObject2D*)bodyB->GetUserData();

        bool thisContinue=true;
        if(objectA->getNotCollisionGroupSize() && objectB->getNotCollisionGroupSize()){
            //test if B have A group
            edk::uint32 size = objectA->getNotCollisionGroupSize();
            for(edk::uint32 i=0u;i<size;i++){
                if(objectB->haveNotCollisionGroup(objectA->getNotCollisionGroupInPosition(i))){
                    //then continue
                    thisContinue=false;
                    break;
                }
            }
        }
        if(objectA->getCollisionGroupSize() && objectB->getCollisionGroupSize()){
            thisContinue=false;
            //test if B have A group
            edk::uint32 size = objectA->getCollisionGroupSize();
            for(edk::uint32 i=0u;i<size;i++){
                if(objectB->haveCollisionGroup(objectA->getCollisionGroupInPosition(i))){
                    //then continue
                    thisContinue=true;
                    break;
                }
            }
        }
        if(thisContinue){
            if(!contactTemp){
                //create the new contact
                contactTemp = new edk::physics2D::Contact2D(contact);
                //add the contactTemp on the tree
                if(!this->world->treeConcacts.add(contactTemp)){
                    //delete contactTemp
                    delete contactTemp;
                    contactTemp=NULL;
                }
            }
            if(contactTemp){
                //update the values
                contactTemp->objectA = (edk::physics2D::PhysicObject2D*)bodyA->GetUserData();
                contactTemp->objectB = (edk::physics2D::PhysicObject2D*)bodyB->GetUserData();
                contactTemp->shapeA = shapeA;
                contactTemp->shapeB = shapeB;
                //
                contactTemp->objectA->setLinearVelocity(bodyA->GetLinearVelocity().x,bodyA->GetLinearVelocity().y);
                contactTemp->objectA->setAngularVelocity(bodyA->GetAngularVelocity() * (180.f / b2_pi));
                contactTemp->objectB->setLinearVelocity(bodyB->GetLinearVelocity().x,bodyB->GetLinearVelocity().y);
                contactTemp->objectB->setAngularVelocity(bodyB->GetAngularVelocity() * (180.f / b2_pi));
                contactTemp->velocityA = contactTemp->objectA->getSpeed();
                contactTemp->velocityB = contactTemp->objectB->getSpeed();
                //
                contactTemp->worldPositions.createArray(count);
                contactTemp->objectAPositions.createArray(count);
                contactTemp->objectBPositions.createArray(count);
                contactTemp->impulses.createArray(count);
                contactTemp->points = count;

                //select the polygon
                contactTemp->objectA->physicMesh.selectPolygon(contactTemp->shapeA);
                contactTemp->objectB->physicMesh.selectPolygon(contactTemp->shapeB);

                //get the world manifold to get the points
                b2WorldManifold worldManifold;
                contact->GetWorldManifold(&worldManifold);
                b2Vec2 point;
                edk::vec2f32 vertex;
                for(edk::uint32 i=0u;i<count;i++){
                    //copy the point to the worldPosition

                    point = worldManifold.points[i];
                    contactTemp->worldPositions.set(i,edk::vec2f32(point.x,point.y));

                    //get objectA position
                    vertex = edk::Math::rotatePlus2f(contactTemp->worldPositions[i]-contactTemp->objectA->position,
                                                     contactTemp->objectA->angle * -1.f
                                                     );
                    if(contactTemp->objectA->size.width) vertex.x/=contactTemp->objectA->size.width;
                    if(contactTemp->objectA->size.height) vertex.y/=contactTemp->objectA->size.height;
                    contactTemp->objectAPositions.set(i,vertex);
                    //get objectB position
                    vertex = edk::Math::rotatePlus2f(contactTemp->worldPositions[i]-contactTemp->objectB->position,
                                                     contactTemp->objectB->angle * -1.f
                                                     );
                    if(contactTemp->objectB->size.width)vertex.x/=contactTemp->objectB->size.width;
                    if(contactTemp->objectB->size.height)vertex.y/=contactTemp->objectB->size.height;
                    contactTemp->objectBPositions.set(i,vertex);
                    contactTemp->impulses.set(i,0.f);
                }

                //test if the objectA is a sensor
                if(contactTemp->objectA->isSensor()){
                    //load the sensor
                    edk::physics2D::StaticSensor2D* sensor = (edk::physics2D::StaticSensor2D*)contactTemp->objectA;
                    //test if the sensor have objects
                    if(sensor->getActivateSize()){
                        //test if have the object in the sensor tree
                        if(sensor->haveActivateObject(contactTemp->objectB)){
                            //this->world->sensorBegin(contactTemp);
                            this->world->physicsSensorBegin(contactTemp);
                        }
                    }
                    else{
                        //test if the object is in the sensor
                        //this->world->sensorBegin(contactTemp);
                        this->world->physicsSensorBegin(contactTemp);
                    }
                }
                else if(contactTemp->objectB->isSensor()){
                    //load the sensor
                    edk::physics2D::StaticSensor2D* sensor = (edk::physics2D::StaticSensor2D*)contactTemp->objectB;
                    //test if the sensor have objects
                    if(sensor->getActivateSize()){
                        //test if have the object in the sensor tree
                        if(sensor->haveActivateObject(contactTemp->objectA)){
                            //this->world->sensorBegin(contactTemp);
                            this->world->physicsSensorBegin(contactTemp);
                        }
                    }
                    else{
                        //test if the object is in the sensor
                        //this->world->sensorBegin(contactTemp);
                        this->world->physicsSensorBegin(contactTemp);
                    }
                }
                //Test if the lineA collide in one side
                else if(contactTemp->objectA->physicMesh.selectedIsLine()){
                    if(!contactTemp->objectB->physicMesh.selectedIsLine()){
                        //just test if the object is up the contact
                        switch(contactTemp->objectA->physicMesh.selectedGetCollisionID()){
                        case edk::shape::collisionUP:
                            if(contactTemp->objectB->position.y>=contactTemp->worldPositions[0u].y){
                                this->world->physicsContactBegin(contactTemp);
                            }
                            else{
                                if(this->world->treeConcacts.remove((contactTemp))){
                                    delete (contactTemp);
                                }
                            }
                            break;
                        case edk::shape::collisionDOWN:
                            if(contactTemp->objectB->position.y<contactTemp->worldPositions[0u].y){
                                this->world->physicsContactBegin(contactTemp);
                            }
                            else{
                                if(this->world->treeConcacts.remove((contactTemp))){
                                    delete (contactTemp);
                                }
                            }
                            break;
                        default:
                            this->world->physicsContactBegin(contactTemp);
                            break;
                        }
                    }
                }
                //Test if the lineB collide in one side
                else if(contactTemp->objectB->physicMesh.selectedIsLine()){
                    if(!contactTemp->objectB->physicMesh.selectedIsLine()){
                        //just test if the object is up the contact
                        switch(contactTemp->objectB->physicMesh.selectedGetCollisionID()){
                        case edk::shape::collisionUP:
                            if(contactTemp->objectA->position.y>=contactTemp->worldPositions[0u].y){
                                this->world->physicsContactBegin(contactTemp);
                            }
                            else{
                                if(this->world->treeConcacts.remove((contactTemp))){
                                    delete (contactTemp);
                                }
                            }
                            break;
                        case edk::shape::collisionDOWN:
                            if(contactTemp->objectA->position.y<contactTemp->worldPositions[0u].y){
                                this->world->physicsContactBegin(contactTemp);
                            }
                            else{
                                if(this->world->treeConcacts.remove((contactTemp))){
                                    delete (contactTemp);
                                }
                            }
                            break;
                        default:
                            this->world->physicsContactBegin(contactTemp);
                            break;
                        }
                    }
                }
                else{
                    //this->world->contactbegin(contactTemp);
                    this->world->physicsContactBegin(contactTemp);
                }
            }
        }
        else{
            if(contactTemp){
                if(this->world->treeConcacts.remove((contactTemp))){
                    delete (contactTemp);
                }
            }
        }
    }
}
void edk::physics2D::World2D::MyContactListener::EndContact(b2Contact* contact){
    /*
    printf("\nContact END %u"
           ,contact
           );fflush(stdout);
*/
    //find contact
    b2Body* bodyA = contact->GetFixtureA()->GetBody();
    b2Body* bodyB = contact->GetFixtureB()->GetBody();
    edk::physics2D::Contact2D* contactTemp = this->world->treeConcacts.getContact(contact);
    if(contactTemp){
        contactTemp->objectA->setLinearVelocity(bodyA->GetLinearVelocity().x,bodyA->GetLinearVelocity().y);
        contactTemp->objectA->setAngularVelocity(bodyA->GetAngularVelocity() * (180.f / b2_pi));
        contactTemp->objectB->setLinearVelocity(bodyB->GetLinearVelocity().x,bodyB->GetLinearVelocity().y);
        contactTemp->objectB->setAngularVelocity(bodyB->GetAngularVelocity() * (180.f / b2_pi));
        contactTemp->velocityA = contactTemp->objectA->getSpeed();
        contactTemp->velocityB = contactTemp->objectB->getSpeed();
        //update the positions
        edk::uint8 count = contact->GetManifold()->pointCount;
        b2Vec2 point;
        edk::vec2f32 vertex;
        b2WorldManifold worldManifold;
        contact->GetWorldManifold(&worldManifold);

        for(edk::uint32 i=0u;i<count;i++){
            //copy the point to the worldPosition

            point = worldManifold.points[i];
            contactTemp->worldPositions.set(i,edk::vec2f32(point.x,point.y));

            //get objectA position
            vertex = edk::Math::rotatePlus2f(contactTemp->worldPositions[i]-contactTemp->objectA->position,
                                             contactTemp->objectA->angle * -1.f
                                             );
            if(contactTemp->objectA->size.width) vertex.x/=contactTemp->objectA->size.width;
            if(contactTemp->objectA->size.height) vertex.y/=contactTemp->objectA->size.height;
            contactTemp->objectAPositions.set(i,vertex);
            //get objectB position
            vertex = edk::Math::rotatePlus2f(contactTemp->worldPositions[i]-contactTemp->objectB->position,
                                             contactTemp->objectB->angle * -1.f
                                             );
            if(contactTemp->objectB->size.width) vertex.x/=contactTemp->objectB->size.width;
            if(contactTemp->objectB->size.height) vertex.y/=contactTemp->objectB->size.height;
            contactTemp->objectBPositions.set(i,vertex);
        }

        //process the contactEnd

        //if(contactTemp->isEnabled()){
            //test if the objectA is a sensor
            if(contactTemp->objectA->isSensor()){
                //load the sensor
                edk::physics2D::StaticSensor2D* sensor = (edk::physics2D::StaticSensor2D*)contactTemp->objectA;
                //test if the sensor have objects
                if(sensor->getActivateSize()){
                    //test if have the object in the sensor tree
                    if(sensor->haveActivateObject(contactTemp->objectB)){
                        //this->world->sensorEnd(contactTemp);
                        this->world->physicsSensorEnd(contactTemp);
                    }
                }
                else{
                    //test if the object is in the sensor
                    //this->world->sensorEnd(contactTemp);
                    this->world->physicsSensorEnd(contactTemp);
                }
            }
            else if(contactTemp->objectB->isSensor()){
                //load the sensor
                edk::physics2D::StaticSensor2D* sensor = (edk::physics2D::StaticSensor2D*)contactTemp->objectB;
                //test if the sensor have objects
                if(sensor->getActivateSize()){
                    //test if have the object in the sensor tree
                    if(sensor->haveActivateObject(contactTemp->objectA)){
                        //this->world->sensorEnd(contactTemp);
                        this->world->physicsSensorEnd(contactTemp);
                    }
                }
                else{
                    //test if the object is in the sensor
                    //this->world->sensorEnd(contactTemp);
                    this->world->physicsSensorEnd(contactTemp);
                }
            }
            else{
                //this->world->contactEnd(contactTemp);
                this->world->physicsContactEnd(contactTemp);
            }
        //}

        //remove contactTemp from the tree
        this->world->treeConcacts.remove(contactTemp);
        //delete contactTemp
        delete contactTemp;
    }
}
void edk::physics2D::World2D::MyContactListener::PreSolve(b2Contact* contact, const b2Manifold*){
    /*
    printf("\nContact PreSolve %u"
           ,contact
           );fflush(stdout);
*/
    //find contact
    b2Body* bodyA = contact->GetFixtureA()->GetBody();
    b2Body* bodyB = contact->GetFixtureB()->GetBody();
    edk::physics2D::Contact2D* contactTemp = this->world->treeConcacts.getContact(contact);
    if(contactTemp){
        contactTemp->objectA->setLinearVelocity(bodyA->GetLinearVelocity().x,bodyA->GetLinearVelocity().y);
        contactTemp->objectA->setAngularVelocity(bodyA->GetAngularVelocity() * (180.f / b2_pi));
        contactTemp->objectB->setLinearVelocity(bodyB->GetLinearVelocity().x,bodyB->GetLinearVelocity().y);
        contactTemp->objectB->setAngularVelocity(bodyB->GetAngularVelocity() * (180.f / b2_pi));
        contactTemp->velocityA = contactTemp->objectA->getSpeed();
        contactTemp->velocityB = contactTemp->objectB->getSpeed();
        //update the positions
        edk::uint8 count = contact->GetManifold()->pointCount;
        b2Vec2 point;
        edk::vec2f32 vertex;
        b2WorldManifold worldManifold;
        contact->GetWorldManifold(&worldManifold);
        for(edk::uint32 i=0u;i<count;i++){
            //copy the point to the worldPosition

            point = worldManifold.points[i];
            contactTemp->worldPositions.set(i,edk::vec2f32(point.x,point.y));

            //get objectA position
            vertex = edk::Math::rotatePlus2f(contactTemp->worldPositions[i]-contactTemp->objectA->position,
                                             contactTemp->objectA->angle * -1.f
                                             );
            if(contactTemp->objectA->size.width) vertex.x/=contactTemp->objectA->size.width;
            if(contactTemp->objectA->size.height) vertex.y/=contactTemp->objectA->size.height;
            contactTemp->objectAPositions.set(i,vertex);
            //get objectB position
            vertex = edk::Math::rotatePlus2f(contactTemp->worldPositions[i]-contactTemp->objectB->position,
                                             contactTemp->objectB->angle * -1.f
                                             );
            if(contactTemp->objectB->size.width) vertex.x/=contactTemp->objectB->size.width;
            if(contactTemp->objectB->size.height) vertex.y/=contactTemp->objectB->size.height;
            contactTemp->objectBPositions.set(i,vertex);
        }


        if(contactTemp->isEnabled()){
            //test if the objectA is a sensor
            if(contactTemp->objectA->isSensor()){
                //load the sensor
                edk::physics2D::StaticSensor2D* sensor = (edk::physics2D::StaticSensor2D*)contactTemp->objectA;
                //test if the sensor have objects
                if(sensor->getActivateSize()){
                    //test if have the object in the sensor tree
                    if(sensor->haveActivateObject(contactTemp->objectB)){
                        //this->world->sensorKeeping(contactTemp);
                        this->world->physicsSensorKeeping(contactTemp);
                    }
                }
                else{
                    //test if the object is in the sensor
                    //this->world->sensorKeeping(contactTemp);
                    this->world->physicsSensorKeeping(contactTemp);
                }
                contact->SetEnabled(false);
            }
            else if(contactTemp->objectB->isSensor()){
                //load the sensor
                edk::physics2D::StaticSensor2D* sensor = (edk::physics2D::StaticSensor2D*)contactTemp->objectB;
                //test if the sensor have objects
                if(sensor->getActivateSize()){
                    //test if have the object in the sensor tree
                    if(sensor->haveActivateObject(contactTemp->objectA)){
                        //this->world->sensorKeeping(contactTemp);
                        this->world->physicsSensorKeeping(contactTemp);
                    }
                }
                else{
                    //test if the object is in the sensor
                    //this->world->sensorKeeping(contactTemp);
                    this->world->physicsSensorKeeping(contactTemp);
                }
                contact->SetEnabled(false);
            }
            else{
                //this->world->contactKeepBegin(contactTemp);
                this->world->physicsContactKeepBegin(contactTemp);
                contact->SetEnabled(contactTemp->isEnabled());
            }
        }
        else{
            contact->SetEnabled(false);
        }
    }
    else{
        contact->SetEnabled(false);
    }
}
void edk::physics2D::World2D::MyContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse){
    /*
    printf("\nContact PostSolve impulses %u tangent %.2f normal %.2f"
           ,impulse->count
           ,impulse->tangentImpulses[0u]
           ,impulse->normalImpulses[0u]
           );fflush(stdout);
*/
    //find contact
    b2Body* bodyA = contact->GetFixtureA()->GetBody();
    b2Body* bodyB = contact->GetFixtureB()->GetBody();
    edk::physics2D::Contact2D* contactTemp = this->world->treeConcacts.getContact(contact);
    if(contactTemp){
        contactTemp->objectA->setLinearVelocity(bodyA->GetLinearVelocity().x,bodyA->GetLinearVelocity().y);
        contactTemp->objectA->setAngularVelocity(bodyA->GetAngularVelocity() * (180.f / b2_pi));
        contactTemp->objectB->setLinearVelocity(bodyB->GetLinearVelocity().x,bodyB->GetLinearVelocity().y);
        contactTemp->objectB->setAngularVelocity(bodyB->GetAngularVelocity() * (180.f / b2_pi));
        contactTemp->velocityA = contactTemp->objectA->getSpeed();
        contactTemp->velocityB = contactTemp->objectB->getSpeed();
        //update the positions
        edk::uint8 count = contact->GetManifold()->pointCount;
        b2Vec2 point;
        edk::vec2f32 vertex;
        b2WorldManifold worldManifold;
        contact->GetWorldManifold(&worldManifold);

        for(edk::uint32 i=0u;i<count;i++){
            //copy the point to the worldPosition

            point = worldManifold.points[i];
            contactTemp->worldPositions.set(i,edk::vec2f32(point.x,point.y));

            //get objectA position
            vertex = edk::Math::rotatePlus2f(contactTemp->worldPositions[i]-contactTemp->objectA->position,
                                             contactTemp->objectA->angle * -1.f
                                             );
            if(contactTemp->objectA->size.width) vertex.x/=contactTemp->objectA->size.width;
            if(contactTemp->objectA->size.height) vertex.y/=contactTemp->objectA->size.height;
            contactTemp->objectAPositions.set(i,vertex);
            //get objectB position
            vertex = edk::Math::rotatePlus2f(contactTemp->worldPositions[i]-contactTemp->objectB->position,
                                             contactTemp->objectB->angle * -1.f
                                             );
            if(contactTemp->objectB->size.width) vertex.x/=contactTemp->objectB->size.width;
            if(contactTemp->objectB->size.height) vertex.y/=contactTemp->objectB->size.height;
            contactTemp->objectBPositions.set(i,vertex);
        }

        //Update impulsess
        for(edk::uint32 i=0u;i<count;i++){
            contactTemp->impulses.set(i,impulse->normalImpulses[i]);
        }
        count = impulse->count;


        if(contactTemp->isEnabled()){
            //test if the objectA is a sensor
            if(!contactTemp->objectA->isSensor()
                    &&
                    !contactTemp->objectB->isSensor()){
                //this->world->contactKeepEnd(contactTemp);
                this->world->physicsContactKeepEnd(contactTemp);
            }
        }
    }
}


//Add a joint
bool edk::physics2D::World2D::ObjectJointsTree::addJoint(edk::physics2D::Joint2D* joint){
    //test the joint
    if(joint){
        //test the objects
        if((joint->objectA==this->pointerA
            &&
            joint->objectB==this->pointerB)
                ||
                (joint->objectA==this->pointerB
                 &&
                 joint->objectB==this->pointerA)
                ){
            //add the joint
            return this->add(joint);
        }
    }
    return false;
}
//return the joint in the position
edk::physics2D::Joint2D* edk::physics2D::World2D::ObjectJointsTree::getJointInPosition(edk::uint32 position){
    return this->getElementInPosition(position);
}

//return the size of the joint
edk::uint32 edk::physics2D::World2D::ObjectJointsTree::getSize(){
    return this->size();
}

//remove joint
bool edk::physics2D::World2D::ObjectJointsTree::removeJoint(edk::physics2D::Joint2D* joint){
    return this->remove(joint);
}
//remove joint in position
bool edk::physics2D::World2D::ObjectJointsTree::removeJointInPosition(edk::uint32 position){
    return this->remove(this->getJointInPosition(position));
}

//clean the joints
void edk::physics2D::World2D::ObjectJointsTree::cleanJoints(){
    this->clean();
}


//add a joint
bool edk::physics2D::World2D::ObjectsJointsTree::addJoint(edk::physics2D::World2D::ObjectJointsTree* joint){
    //test the joint
    if(joint){
        //test if the joint have the pointer
        if(joint->getPointerA()==this->pointer
                ||
                joint->getPointerB()==this->pointer){
            //add the joint
            return this->add(joint);
        }
    }
    return false;
}
//return the joint
edk::physics2D::World2D::ObjectJointsTree* edk::physics2D::World2D::ObjectsJointsTree::getJoint(edk::physics2D::PhysicObject2D* object){
    //create the find joint
    edk::physics2D::World2D::ObjectJointsTree find(object,pointer);
    /*
    find.objectA = object;
    find.objectB = pointer;
    */
    return this->getElement(&find);
}
//return the joint in the position
edk::physics2D::World2D::ObjectJointsTree* edk::physics2D::World2D::ObjectsJointsTree::getJointInPosition(edk::uint32 position){
    return this->getElementInPosition(position);
}
//return the size of the joint
edk::uint32 edk::physics2D::World2D::ObjectsJointsTree::getSize(){
    return this->size();
}
//remove joint
bool edk::physics2D::World2D::ObjectsJointsTree::removeJoint(edk::physics2D::PhysicObject2D* object){
    edk::physics2D::World2D::ObjectJointsTree find(object,pointer);
    /*
    find.objectA = object;
    find.objectB = pointer;
    */
    return this->remove(&find);
}

bool edk::physics2D::World2D::ObjectsJointsTree::removeJoint(edk::physics2D::World2D::ObjectJointsTree* joint){
    return this->remove(joint);
}
//clean the joints
void edk::physics2D::World2D::ObjectsJointsTree::cleanJoints(){
    this->clean();
}

//return the pointer
edk::physics2D::PhysicObject2D* edk::physics2D::World2D::ObjectsJointsTree::getPointer(){
    return this->pointer;
}

//compare if the value is bigger
bool edk::physics2D::World2D::ObjectsJointsTree::firstBiggerSecond(edk::physics2D::World2D::ObjectJointsTree* first,edk::physics2D::World2D::ObjectJointsTree* second){
    if(first->getPointerA()==this->pointer){
        if(second->getPointerA()==this->pointer){
            //B B
            if(first->getPointerB()>second->getPointerB()){
                return true;
            }
        }
        else if(second->getPointerB()==this->pointer){
            //B A
            if(first->getPointerB()>second->getPointerA()){
                return true;
            }
        }
    }
    else if(first->getPointerB()==this->pointer){
        if(second->getPointerA()==this->pointer){
            //A B
            if(first->getPointerA()>second->getPointerB()){
                return true;
            }
        }
        else if(second->getPointerB()==this->pointer){
            //A A
            if(first->getPointerA()>second->getPointerA()){
                return true;
            }
        }
    }
    return false;
}
bool edk::physics2D::World2D::ObjectsJointsTree::firstEqualSecond(edk::physics2D::World2D::ObjectJointsTree* first,edk::physics2D::World2D::ObjectJointsTree* second){
    if(first->getPointerA()==this->pointer){
        if(second->getPointerA()==this->pointer){
            //B B
            if(first->getPointerB()==second->getPointerB()){
                return true;
            }
        }
        else if(second->getPointerB()==this->pointer){
            //B A
            if(first->getPointerB()==second->getPointerA()){
                return true;
            }
        }
    }
    else if(first->getPointerB()==this->pointer){
        if(second->getPointerA()==this->pointer){
            //A B
            if(first->getPointerA()==second->getPointerB()){
                return true;
            }
        }
        else if(second->getPointerB()==this->pointer){
            //A A
            if(first->getPointerA()==second->getPointerA()){
                return true;
            }
        }
    }
    return false;
}

edk::physics2D::World2D::World2D()
    : world(b2Vec2(0,0)),contacts(this),treeDeleted(&this->world){
    //set the initial gravity
    this->setGravity(edk::vec2f32(0.f,-9.8f));
    this->world.SetContactListener(&this->contacts);

    this->clockStart();
    this->clockScale=1.f;

    this->runNextStep=false;
    this->paused=false;
}
edk::physics2D::World2D::~World2D(){
    //
    edk::uint32 size = 0u;
    b2Body* body=NULL;

    this->treeCallbacks.clean();

    //destroy treeContacts
    size = this->treeConcacts.getSize();
    for(edk::uint32 i=0u;i<size;i++){
        edk::physics2D::Contact2D* temp = this->treeConcacts.getElementInPosition(i);
        if(temp){
            delete temp;
        }
    }
    this->treeConcacts.clean();

    //destroy objectJoints
    size = this->treeJointObjects.size();
    for(edk::uint32 i=0u;i<size;i++){
        //load the tree
        edk::physics2D::World2D::ObjectsJointsTree* treeTemp = this->treeJointObjects.getElementInPosition(i);
        if(treeTemp){
            edk::physics2D::World2D::ObjectJointsTree* treeTemps = treeTemp->getJointInPosition(i);
            if(treeTemps){
                treeTemp->cleanJoints();
                delete treeTemps;
            }
            treeTemp->cleanJoints();
            delete treeTemp;
        }
    }
    this->treeJointObjects.clean();
    //destroy joints
    size = this->treeJoint.size();
    b2Joint *joint;
    edk::physics2D::Joint2D* edkJoint;
    for(edk::uint32 i=0u;i<size;i++){
        joint = this->treeJoint.getB2JointInPosition(i);
        if(joint){
            edkJoint = (edk::physics2D::Joint2D*)joint->GetUserData();
            if(edkJoint) delete edkJoint;
            this->world.DestroyJoint(joint);
        }
    }
    this->treeJoint.clean();

    //destroy static
    size = this->treeStatic.size();
    for(edk::uint32 i=0u;i<size;i++){
        body = this->treeStatic.getBodyInPosition(i);
        if(body){
            if(this->runNextStep)
                //save the object on the deleted tree
                this->treeDeleted.add(body);
            else
                this->world.DestroyBody(body);
        }
    }
    this->treeStatic.clean();
    //destroy kinematic
    size = this->treeKinematic.size();
    for(edk::uint32 i=0u;i<size;i++){
        body = this->treeKinematic.getBodyInPosition(i);
        if(body){
            if(this->runNextStep)
                //save the object on the deleted tree
                this->treeDeleted.add(body);
            else
                this->world.DestroyBody(body);
        }
    }
    this->treeKinematic.clean();
    //destroy dynamic
    size = this->treeDynamic.size();
    for(edk::uint32 i=0u;i<size;i++){
        body = this->treeDynamic.getBodyInPosition(i);
        if(body){
            if(this->runNextStep)
                //save the object on the deleted tree
                this->treeDeleted.add(body);
            else
                this->world.DestroyBody(body);
        }
    }
    this->treeDynamic.clean();
}

//return the body
b2Body* edk::physics2D::World2D::getBody(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //test the objectType
        /*
            StaticBody
            KinematicBody
            DynamicBody
*/
        switch(object->getType()){
        case edk::physics::StaticBody:
            return this->treeStatic.getBody(object);
            //break;
        case edk::physics::KinematicBody:
            return this->treeKinematic.getBody(object);
            //break;
        case edk::physics::DynamicBody:
            return this->treeDynamic.getBody(object);
            //break;
        }
    }
    return NULL;
}

/*
//return the world position on the body for the joint
edk::vec2f32 edk::physics2D::World2D::getJointPosition(edk::physics2D::PhysicObject2D* object,edk::vec2f32 worldPosition){
    edk::vec2f32 ret;
    //translate
    ret  = worldPosition - object->position;
    //and rotate the worldPosition
    if(object->angle){
        ret = edk::Math::rotate2f(ret,object->angle * -1);
    }
    return ret;
}
//return the joint position in the world
edk::vec2f32 edk::physics2D::World2D::getJointWorldPosition(edk::physics2D::PhysicObject2D* object,edk::vec2f32 jointPosition){
    edk::vec2f32 ret;
    //and rotate the worldPosition
    if(object->angle){
        //rotate
        ret = edk::Math::rotate2f(jointPosition,object->angle);
        //translate
        ret+=object->position;
    }
    else{
        //translate
        ret = jointPosition + object->position;
    }
    return ret;
}
*/
//Add a joint to the trees
edk::physics2D::Joint2D* edk::physics2D::World2D::addJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                           edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB
                                                           ){
    //test the objects
    if(objectA && objectB){
        //load the first objectTREE
        edk::physics2D::World2D::ObjectsJointsTree* treeA = this->treeJointObjects.getTreeJoint(objectA);

        //test if dont have the object
        if(!treeA){
            //else create a new treeA
            treeA = new edk::physics2D::World2D::ObjectsJointsTree(objectA);
            if(treeA){
                //add the treeA in the tree
                if(!this->treeJointObjects.add(treeA)){
                    //else delete treeA
                    delete treeA;
                    treeA=NULL;
                }
            }
        }
        //now test if have the object
        if(treeA){
            //load the second objectTREE
            edk::physics2D::World2D::ObjectsJointsTree* treeB = this->treeJointObjects.getTreeJoint(objectB);
            //test if dont have the object
            if(!treeB){
                //else create a new treeB
                treeB = new edk::physics2D::World2D::ObjectsJointsTree(objectB);
                if(treeB){
                    //add the treeB in the tree
                    if(!this->treeJointObjects.add(treeB)){
                        //else delete treeB
                        delete treeB;
                        treeB=NULL;
                    }
                }
            }
            //now test if have the object
            if(treeB){



                //load the treeAB
                edk::physics2D::World2D::ObjectJointsTree* treeAB = treeA->getJoint(objectB);
                //test if load the tree
                if(!treeAB){
                    //create the new tree
                    treeAB = new edk::physics2D::World2D::ObjectJointsTree(objectA,objectB);
                    if(treeAB){
                        if(!treeA->addJoint(treeAB)){
                            delete treeAB;
                            treeAB=NULL;
                        }
                    }
                }
                if(treeAB){
                    //load the treeBA
                    edk::physics2D::World2D::ObjectJointsTree* treeBA = treeB->getJoint(objectA);
                    //test if load the tree
                    if(!treeBA){
                        //create the new tree
                        treeBA = new edk::physics2D::World2D::ObjectJointsTree(objectB,objectA);
                        if(treeBA){
                            if(!treeB->addJoint(treeBA)){
                                delete treeBA;
                                treeBA=NULL;
                            }
                        }
                    }
                    if(treeBA){


                        //create the joint
                        edk::physics2D::Joint2D* joint = new edk::physics2D::Joint2D;
                        if(joint){
                            //set the objects
                            joint->objectA = objectA;
                            joint->objectB = objectB;

                            //add the joint in the two trees
                            if(treeAB->addJoint(joint)){
                                //
                                if(treeBA->addJoint(joint)
                                        ||
                                        treeBA == treeAB){
                                    //get WorldPosition
                                    joint->positionA = positionA;
                                    joint->worldPositionA
                                            =
                                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectA,positionA)
                                            ;
                                    joint->positionB = positionB;
                                    /*
                                    joint->worldPositionB
                                            =
                                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectB,positionB)
                                            ;
*/

                                    //return the joint
                                    return joint;
                                }

                                //remove the joint
                                treeAB->removeJoint(joint);
                            }


                            //delete the joint
                            delete joint;
                            joint=NULL;
                        }



                        //delete the treeBA
                        if(!treeBA->getSize()){
                            //remove from the tree
                            treeA->removeJoint(treeBA);
                            delete treeBA;
                        }
                    }



                    //delete the treeAB
                    if(!treeAB->getSize()){
                        //remove from the tree
                        treeA->removeJoint(treeAB);
                        delete treeAB;
                    }
                }



                //test if the treeB have size zero
                if(!treeB->getSize()){
                    //then remove and delete treeB
                    this->treeJointObjects.remove(treeB);
                    delete treeB;
                }
            }


            //test if the treeOA have size zero
            if(!treeA->getSize()){
                //then remove and delete treeA
                this->treeJointObjects.remove(treeA);
                delete treeA;
            }
        }
    }
    return NULL;
}
bool edk::physics2D::World2D::addJoint(edk::physics2D::Joint2D* joint){
    //
    if(joint){
        //test the objects
        if(joint->objectA && joint->objectB){
            //load the first objectTREE
            edk::physics2D::World2D::ObjectsJointsTree* treeA = this->treeJointObjects.getTreeJoint(joint->objectA);

            //test if dont have the object
            if(!treeA){
                //else create a new treeA
                treeA = new edk::physics2D::World2D::ObjectsJointsTree(joint->objectA);
                if(treeA){
                    //add the treeA in the tree
                    if(!this->treeJointObjects.add(treeA)){
                        //else delete treeA
                        delete treeA;
                        treeA=NULL;
                    }
                }
            }
            //now test if have the object
            if(treeA){
                //load the second objectTREE
                edk::physics2D::World2D::ObjectsJointsTree* treeB = this->treeJointObjects.getTreeJoint(joint->objectB);
                //test if dont have the object
                if(!treeB){
                    //else create a new treeB
                    treeB = new edk::physics2D::World2D::ObjectsJointsTree(joint->objectB);
                    if(treeB){
                        //add the treeB in the tree
                        if(!this->treeJointObjects.add(treeB)){
                            //else delete treeB
                            delete treeB;
                            treeB=NULL;
                        }
                    }
                }
                //now test if have the object
                if(treeB){



                    //load the treeAB
                    edk::physics2D::World2D::ObjectJointsTree* treeAB = treeA->getJoint(joint->objectB);
                    //test if load the tree
                    if(!treeAB){
                        //create the new tree
                        treeAB = new edk::physics2D::World2D::ObjectJointsTree(joint->objectA,joint->objectB);
                        if(treeAB){
                            if(!treeA->addJoint(treeAB)){
                                delete treeAB;
                                treeAB=NULL;
                            }
                        }
                    }
                    if(treeAB){
                        //load the treeBA
                        edk::physics2D::World2D::ObjectJointsTree* treeBA = treeB->getJoint(joint->objectA);
                        //test if load the tree
                        if(!treeBA){
                            //create the new tree
                            treeBA = new edk::physics2D::World2D::ObjectJointsTree(joint->objectB,joint->objectA);
                            if(treeBA){
                                if(!treeB->addJoint(treeBA)){
                                    delete treeBA;
                                    treeBA=NULL;
                                }
                            }
                        }
                        if(treeBA){



                            //add the joint in the two trees
                            if(treeAB->addJoint(joint)){
                                //
                                if(treeBA->addJoint(joint)
                                        ||
                                        treeBA == treeAB){
                                    //return true
                                    return true;
                                }

                                //remove the joint
                                treeAB->removeJoint(joint);


                                //delete the joint
                                delete joint;
                                joint=NULL;
                            }



                            //delete the treeBA
                            if(!treeBA->getSize()){
                                //remove from the tree
                                treeA->removeJoint(treeBA);
                                delete treeBA;
                            }
                        }



                        //delete the treeAB
                        if(!treeAB->getSize()){
                            //remove from the tree
                            treeA->removeJoint(treeAB);
                            delete treeAB;
                        }
                    }



                    //test if the treeB have size zero
                    if(!treeB->getSize()){
                        //then remove and delete treeB
                        this->treeJointObjects.remove(treeB);
                        delete treeB;
                    }
                }


                //test if the treeOA have size zero
                if(!treeA->getSize()){
                    //then remove and delete treeA
                    this->treeJointObjects.remove(treeA);
                    delete treeA;
                }
            }
        }
    }
    return false;
}

//remove joint
bool edk::physics2D::World2D::removeObjectJoints(edk::physics2D::PhysicObject2D* object){
    if(object){
        edk::physics2D::World2D::ObjectsJointsTree* objectsJointsATemp = this->treeJointObjects.getTreeJoint(object);
        if(objectsJointsATemp){
            //
            edk::uint32 size = objectsJointsATemp->getSize();
            edk::uint32 sizeJ = 0u;
            edk::physics2D::Joint2D* joint = NULL;
            b2Joint* boxJoint = NULL;
            edk::physics2D::World2D::ObjectsJointsTree* objectsJointsBTemp=NULL;
            edk::physics2D::World2D::ObjectJointsTree* objectJointsATemp=NULL;
            edk::physics2D::World2D::ObjectJointsTree* objectJointsBTemp=NULL;
            //objectTemp
            edk::physics2D::PhysicObject2D* objectTemp=NULL;
            for(edk::uint32 i=0u;i<size;i++){

                //load the tree of the joint
                objectJointsATemp = objectsJointsATemp->getJointInPosition(i);
                if(objectJointsATemp){
                    //delete joint in the other object
                    if(object!=objectJointsATemp->getPointerA()) objectTemp=objectJointsATemp->getPointerA();
                    else if(object!=objectJointsATemp->getPointerB()) objectTemp=objectJointsATemp->getPointerB();
                    if(objectTemp){
                        //find the object
                        objectsJointsBTemp = this->treeJointObjects.getTreeJoint(objectTemp);
                        if(objectsJointsBTemp){
                            //load the tree with the two objects
                            objectJointsBTemp = objectsJointsBTemp->getJoint(object);
                            if(objectJointsBTemp){
                                //
                                sizeJ = objectJointsBTemp->getSize();
                                for(edk::uint32 j=0u;j<sizeJ;j++){
                                    //load the joints
                                    joint = objectJointsBTemp->getJointInPosition(j);
                                    if(joint){
                                        //objectJointsBTemp->removeJoint(joint);

                                        //remove joint from box2D
                                        boxJoint = this->treeJoint.getJoint(joint);
                                        if(boxJoint){
                                            this->treeJoint.removeJoint(boxJoint);
                                            //destroy the joint
                                            this->world.DestroyJoint(boxJoint);
                                            boxJoint=NULL;
                                        }

                                        //delete joint;
                                        joint=NULL;
                                    }
                                }
                                sizeJ=0u;


                                //remove the objectJoints from the tree
                                objectsJointsBTemp->removeJoint(objectJointsBTemp);
                                //delete
                                objectJointsBTemp->cleanJoints();
                                delete objectJointsBTemp;
                                objectJointsBTemp = NULL;
                            }

                        }
                    }

                    //
                    sizeJ = objectJointsATemp->getSize();
                    for(edk::uint32 j=0u;j<sizeJ;j++){
                        //load the joints
                        joint = objectJointsATemp->getJointInPosition(j);
                        if(joint){
                            //objectJointsATemp->removeJoint(joint);
                            //remove joint from box2D

                            boxJoint = this->treeJoint.getJoint(joint);
                            if(boxJoint){
                                this->treeJoint.removeJoint(boxJoint);
                                //destroy the joint
                                this->world.DestroyJoint(boxJoint);
                                boxJoint=NULL;
                            }

                            delete joint;
                            joint=NULL;
                        }
                    }
                    sizeJ=0u;

                    //objectsJointsATemp->removeJoint(objectJointsATemp);
                    //delete objectJointsTemp
                    objectJointsATemp->cleanJoints();
                    delete objectJointsATemp;
                    objectJointsATemp = NULL;
                }
            }

            objectsJointsATemp->cleanJoints();

            //remove the treeJoints
            this->treeJointObjects.remove(objectsJointsATemp);

            return true;
        }
    }
    return false;
}

//contact functions
void edk::physics2D::World2D::physicsContactBegin(edk::physics2D::Contact2D* contact){
    this->contact2DBegin(contact);
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->contact2DBegin(contact);
    }
}
void edk::physics2D::World2D::physicsContactEnd(edk::physics2D::Contact2D* contact){
    this->contact2DEnd(contact);
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->contact2DEnd(contact);
    }
}
void edk::physics2D::World2D::physicsContactKeepBegin(edk::physics2D::Contact2D* contact){
    this->contact2DKeepBegin(contact);
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->contact2DKeepBegin(contact);
    }
}
void edk::physics2D::World2D::physicsContactKeepEnd(edk::physics2D::Contact2D* contact){
    this->contact2DKeepEnd(contact);
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->contact2DKeepEnd(contact);
    }
}
//contact sensors
void edk::physics2D::World2D::physicsSensorBegin(edk::physics2D::Contact2D* contact){
    this->sensor2DBegin(contact);
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->sensor2DBegin(contact);
    }
}
void edk::physics2D::World2D::physicsSensorEnd(edk::physics2D::Contact2D* contact){
    this->sensor2DEnd(contact);
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->sensor2DEnd(contact);
    }
}
void edk::physics2D::World2D::physicsSensorKeeping(edk::physics2D::Contact2D* contact){
    this->sensor2DKeeping(contact);
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->sensor2DKeeping(contact);
    }
}

//Set the gravity
void edk::physics2D::World2D::setGravity(edk::vec2f32 gravity){
    this->gravity=gravity;
    //update the world gravity
    this->world.SetGravity(b2Vec2(this->gravity.x,this->gravity.y));
}
void edk::physics2D::World2D::setGravity(edk::float32 x,edk::float32 y){
    this->setGravity(edk::vec2f32 (x,y));
}

//Add a Object to the world
bool edk::physics2D::World2D::addObject(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        bool ret=true;
        //create the box2D object
        b2BodyDef objectDef;
        /*
        objectDef.angle = object->angle / (180.f / b2_pi);
        objectDef.position = b2Vec2(object->position.x,object->position.y);
        */

        objectDef.type = (b2BodyType)object->getType();
        objectDef.fixedRotation=object->fixedRotation;

        //objectDef.fixedRotation = false;

        b2Body* objectBody = this->world.CreateBody(&objectDef);
        if(objectBody){
            objectBody->SetTransform( b2Vec2(object->position.x,object->position.y),object->angle / (180.f / b2_pi) );


            objectBody->SetUserData(object);
            //read the polygons
            edk::uint32 size = object->physicMesh.getPolygonSize();
            if(size){
                b2Vec2 vertexs[b2_maxPolygonVertices];
                ret=false;
#if _WIN64 || __x86_64__ || __ppc64__
                for(register edk::uint64 i=0u;i<size;i++){
#else
                for(register edk::uint32 i=0u;i<size;i++){
#endif
                    //select the polygon
                    if(object->physicMesh.selectPolygon(i)){
                        edk::size2f32 scale = object->physicMesh.selectedGetScale() * object->size;
                        edk::vec2f32 translate /*= object->physicMesh.selectedGetTranslate() * object->physicMesh.selectedGetScale()*/;
                        translate.x = object->physicMesh.selectedGetTranslate().x * object->size.width;
                        translate.y = object->physicMesh.selectedGetTranslate().y * object->size.height;
                        //translate.x = object->physicMesh.selectedGetTranslate().x * object->physicMesh.selectedGetScale().width;
                        //translate.y = object->physicMesh.selectedGetTranslate().y * object->physicMesh.selectedGetScale().height;
                        for(edk::uint32 i=0u;i<b2_maxPolygonVertices;i++){
                            vertexs[i].x=0.f;
                            vertexs[i].y=0.f;
                        }
                        //printf("\nVertex Count %u",object->physicMesh.selectedGetVertexCount());
                        //test if the polygon is a circle
                        if(object->physicMesh.selectedIsCircle()){
                            //then use the shape as a circle
                            b2CircleShape objectShape;
                            b2FixtureDef fixture;
                            // Check windows
                            fixture.userData = (void*)i;
                            objectShape.m_p.Set(translate.x/* * scale.width*/,
                                                translate.y/* * scale.height*/
                                                );
                            objectShape.m_radius = scale.width * object->physicMesh.selectedGetCircleRadius();

                            fixture.density = object->physicMesh.selectedGetDensity();
                            fixture.friction = object->physicMesh.selectedGetFriction();
                            fixture.restitution = object->physicMesh.selectedGetRestitution();
                            //create a fixture to the body
                            fixture.shape = &objectShape;
                            objectBody->CreateFixture(&fixture);
                            ret=true;
                        }
                        else if(object->physicMesh.selectedIsLine()){
                            //







                            //LINES
                            //test if is one line or a chain
                            if(object->physicMesh.selectedGetVertexCount() == 2u){
                                b2EdgeShape objectShape;

                                //load the vertex
                                edk::vec2f32 vertex1;
                                edk::vec2f32 vertex2;

                                //Scale
                                vertex1.x = (object->physicMesh.selectedGetVertexPosition(0u).x * scale.width);
                                vertex1.y = (object->physicMesh.selectedGetVertexPosition(0u).y * scale.height);
                                //rotate
                                vertex1 = edk::Math::rotate2f(vertex1,
                                                              edk::Math::getAngle2f(vertex1)
                                                              +
                                                              object->physicMesh.selectedGetAngle()
                                                              );
                                //Translate
                                vertex1+=translate;
                                //process the line
                                vertex2.x = (object->physicMesh.selectedGetVertexPosition(0u).x * scale.width);
                                vertex2.y = (object->physicMesh.selectedGetVertexPosition(0u).y * scale.height);
                                //rotate
                                vertex2 = edk::Math::rotate2f(vertex2,
                                                              edk::Math::getAngle2f(vertex2)
                                                              +
                                                              object->physicMesh.selectedGetAngle()
                                                              );
                                //Translate
                                vertex2+=translate;

                                //set the line
                                objectShape.Set(b2Vec2 (vertex1.x, vertex1.y),
                                                b2Vec2 (vertex2.x, vertex2.y)
                                                );

                                b2FixtureDef fixture;
                                fixture.userData = (void*)i;
                                fixture.density = object->physicMesh.selectedGetDensity();
                                fixture.friction = object->physicMesh.selectedGetFriction();
                                fixture.restitution = object->physicMesh.selectedGetRestitution();

                                //create a fixture to the body
                                fixture.shape = &objectShape;
                                objectBody->CreateFixture(&fixture);
                                ret=true;
                            }
                            else if(object->physicMesh.selectedGetVertexCount()>2u){
                                //
                                b2ChainShape objectShape;
                                b2FixtureDef fixture;
                                fixture.userData = (void*)i;

                                edk::uint32 vCount=object->physicMesh.selectedGetVertexCount();
                                //it's a polygon
                                if(vCount>b2_maxPolygonVertices)
                                    vCount = b2_maxPolygonVertices;
                                edk::vec2f32 vertex;
                                for(edk::uint32 p=0u;p<vCount;p++){
                                    /*
                                printf("\n%.2f %.2f",(object->physicMesh.selectedGetVertexPosition(p).x * scale.width) + translate.x,
                                       (object->physicMesh.selectedGetVertexPosition(p).y * scale.height) + translate.y
                                       );
*/
                                    vertex.x = (object->physicMesh.selectedGetVertexPosition(p).x * scale.width);
                                    vertex.y = (object->physicMesh.selectedGetVertexPosition(p).y * scale.height);
                                    vertex = edk::Math::rotate2f(vertex,
                                                                 edk::Math::getAngle2f(vertex)
                                                                 +
                                                                 object->physicMesh.selectedGetAngle()
                                                                 );
                                    vertexs[p].x = vertex.x + translate.x;
                                    vertexs[p].y = vertex.y + translate.y;
                                }
                                objectShape.CreateChain(vertexs,vCount);
                                //then delete the vertexs

                                fixture.density = object->physicMesh.selectedGetDensity();
                                fixture.friction = object->physicMesh.selectedGetFriction();
                                fixture.restitution = object->physicMesh.selectedGetRestitution();

                                //create a fixture to the body
                                fixture.shape = &objectShape;
                                objectBody->CreateFixture(&fixture);
                                ret=true;
                            }











                        }
                        else{
                            //Else use the shape as polygon
                            b2PolygonShape objectShape;
                            b2FixtureDef fixture;
                            fixture.userData = (void*)i;

                            if(object->physicMesh.selectedGetVertexCount() == 2u){
                                //load the rectSize
                                edk::size2f32 rectSize = edk::size2f32((object->physicMesh.selectedGetVertexPosition(1u).x * scale.width)
                                                                       -
                                                                       (object->physicMesh.selectedGetVertexPosition(0u).x * scale.width)
                                                                       ,
                                                                       (object->physicMesh.selectedGetVertexPosition(1u).y * scale.height)
                                                                       -
                                                                       (object->physicMesh.selectedGetVertexPosition(0u).y * scale.height)
                                                                       );
                                edk::vec2f32 rectVec[2u];
                                rectVec[0u] = vec2f32((object->physicMesh.selectedGetVertexPosition(0u).x * scale.width)/* + translate.x*/,
                                                      (object->physicMesh.selectedGetVertexPosition(0u).y * scale.height)/* + translate.y*/
                                                      );
                                rectVec[1u] = vec2f32((object->physicMesh.selectedGetVertexPosition(1u).x * scale.width)/* + translate.x*/,
                                                      (object->physicMesh.selectedGetVertexPosition(1u).y * scale.height)/* + translate.y*/
                                                      );
                                //it's a rectangle
                                /*
                            printf("\nRECT");
                            printf("\n%.2f %.2f",rectVec[0u].x,rectVec[0u].y);
                            printf("\n%.2f %.2f",rectVec[1u].x,rectVec[1u].y);
                            printf("\nsize %.2f %.2f",rectSize.width,rectSize.height);
                            printf("\ntranslate %.2f %.2f",object->physicMesh.selectedGetTranslate().x,object->physicMesh.selectedGetTranslate().y);
                            printf("\nAngle %.2f",object->physicMesh.selectedGetAngle());
*/
                                //test if the size is a real rect
                                if(rectVec[0u].x == rectVec[1u].x*-1.f
                                        &&
                                        rectVec[0u].y == rectVec[1u].y*-1.f
                                        &&
                                        !object->physicMesh.selectedGetTranslate().x
                                        &&
                                        !object->physicMesh.selectedGetTranslate().y
                                        &&
                                        !object->physicMesh.selectedGetAngle()
                                        ){
                                    //Set as box
                                    if(rectSize.width<0.f)
                                        rectSize.width*=-1.f;
                                    if(rectSize.height<0.f)
                                        rectSize.height*=-1.f;
                                    objectShape.SetAsBox(rectSize.width*0.5f,
                                                         rectSize.height*0.5f,
                                                         b2Vec2(0,0),
                                                         object->physicMesh.selectedGetAngle()/ (180.f / b2_pi)
                                                         );
                                }
                                else{
                                    edk::vec2f32 vertex;
                                    //Else create the polygon

                                    vertex.x = rectVec[0u].x;
                                    vertex.y = rectVec[0u].y;
                                    //rotate
                                    vertex = edk::Math::rotate2f(vertex,
                                                                 edk::Math::getAngle2f(vertex)
                                                                 +
                                                                 object->physicMesh.selectedGetAngle()
                                                                 ) + translate;
                                    vertexs[0u].x = vertex.x;
                                    vertexs[0u].y = vertex.y;

                                    vertex.x = rectVec[1u].x;
                                    vertex.y = rectVec[0u].y;
                                    //rotate
                                    vertex = edk::Math::rotate2f(vertex,
                                                                 edk::Math::getAngle2f(vertex)
                                                                 +
                                                                 object->physicMesh.selectedGetAngle()
                                                                 ) + translate;
                                    vertexs[1u].x = vertex.x;
                                    vertexs[1u].y = vertex.y;

                                    vertex.x = rectVec[1u].x;
                                    vertex.y = rectVec[1u].y;
                                    //rotate
                                    vertex = edk::Math::rotate2f(vertex,
                                                                 edk::Math::getAngle2f(vertex)
                                                                 +
                                                                 object->physicMesh.selectedGetAngle()
                                                                 ) + translate;
                                    vertexs[2u].x = vertex.x;
                                    vertexs[2u].y = vertex.y;

                                    vertex.x = rectVec[0u].x;
                                    vertex.y = rectVec[1u].y;
                                    //rotate
                                    vertex = edk::Math::rotate2f(vertex,
                                                                 edk::Math::getAngle2f(vertex)
                                                                 +
                                                                 object->physicMesh.selectedGetAngle()
                                                                 ) + translate;
                                    vertexs[3u].x = vertex.x;
                                    vertexs[3u].y = vertex.y;

                                    //add the vertexs in the shape
                                    objectShape.Set(vertexs,4u);
                                    //then delete the vertexs
                                }

                                fixture.density = object->physicMesh.selectedGetDensity();
                                fixture.friction = object->physicMesh.selectedGetFriction();
                                fixture.restitution = object->physicMesh.selectedGetRestitution();
                                //create a fixture to the body
                                fixture.shape = &objectShape;
                                objectBody->CreateFixture(&fixture);
                                ret=true;
                            }
                            else if(object->physicMesh.selectedGetVertexCount() > 2u){
                                edk::uint32 vCount=object->physicMesh.selectedGetVertexCount();
                                //it's a polygon
                                if(vCount>b2_maxPolygonVertices)
                                    vCount = b2_maxPolygonVertices;
                                edk::vec2f32 vertex;
                                for(edk::uint32 p=0u;p<vCount;p++){
                                    /*
                                printf("\n%.2f %.2f",(object->physicMesh.selectedGetVertexPosition(p).x * scale.width) + translate.x,
                                       (object->physicMesh.selectedGetVertexPosition(p).y * scale.height) + translate.y
                                       );
*/
                                    vertex.x = (object->physicMesh.selectedGetVertexPosition(p).x * scale.width);
                                    vertex.y = (object->physicMesh.selectedGetVertexPosition(p).y * scale.height);
                                    //vertexs[p].x = (object->physicMesh.selectedGetVertexPosition(p).x * scale.width) + translate.x;
                                    //vertexs[p].y = (object->physicMesh.selectedGetVertexPosition(p).y * scale.height) + translate.y;
                                    vertex = edk::Math::rotate2f(vertex,
                                                                 edk::Math::getAngle2f(vertex)
                                                                 +
                                                                 object->physicMesh.selectedGetAngle()
                                                                 );
                                    vertexs[p].x = vertex.x + translate.x;
                                    vertexs[p].y = vertex.y + translate.y;
                                }
                                objectShape.Set(vertexs,vCount);
                                //then delete the vertexs

                                fixture.density = object->physicMesh.selectedGetDensity();
                                fixture.friction = object->physicMesh.selectedGetFriction();
                                fixture.restitution = object->physicMesh.selectedGetRestitution();

                                //create a fixture to the body
                                fixture.shape = &objectShape;
                                objectBody->CreateFixture(&fixture);
                                ret=true;
                            }

                        }
                    }
                }
            }
            else ret=false;

            //tets if ret true
            if(ret){
                //add the object in the type tree
                /*
                b2_staticBody
                b2_kinematicBody
                b2_dynamicBody
                */
                switch(objectBody->GetType()){
                case b2_staticBody:
                    if(!this->treeStatic.addBody(object,objectBody)){
                        //destroy the body
                        if(this->runNextStep)
                            //save the object on the deleted tree
                            this->treeDeleted.add(objectBody);
                        else
                            this->world.DestroyBody(objectBody);
                        ret=false;
                    }
                    break;
                case b2_kinematicBody:
                    if(!this->treeKinematic.addBody(object,objectBody)){
                        //destroy the body
                        if(this->runNextStep)
                            //save the object on the deleted tree
                            this->treeDeleted.add(objectBody);
                        else
                            this->world.DestroyBody(objectBody);
                        ret=false;
                    }
                    break;
                case b2_dynamicBody:
                    if(!this->treeDynamic.addBody(object,objectBody)){
                        //destroy the body
                        if(this->runNextStep)
                            //save the object on the deleted tree
                            this->treeDeleted.add(objectBody);
                        else
                            this->world.DestroyBody(objectBody);
                        ret=false;
                    }
                    break;
                default:
                    //destroy the object
                    if(this->runNextStep)
                        //save the object on the deleted tree
                        this->treeDeleted.add(objectBody);
                    else
                        this->world.DestroyBody(objectBody);
                    ret=false;
                }
            }
            else{
                //delete the object
                if(this->runNextStep)
                    //save the object on the deleted tree
                    this->treeDeleted.add(objectBody);
                else
                    this->world.DestroyBody(objectBody);
            }
        }
        return ret;
    }
    return false;
}

//remove the object from the world
bool edk::physics2D::World2D::removeObject(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //remove all the object joints
        this->removeObjectJoints(object);
        //load the box2D object
        b2Body* temp=NULL;
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);
            if(temp) this->treeStatic.removeBody(temp);
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);
            if(temp) this->treeDynamic.removeBody(temp);
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);
            if(temp) this->treeKinematic.removeBody(temp);
            break;
        }
        if(temp){
            if(this->runNextStep)
                //save the object on the deleted tree
                this->treeDeleted.add(temp);
            else
                this->world.DestroyBody(temp);
            return true;
        }
    }
    return false;
}
//remove all objects
void edk::physics2D::World2D::removeAllObjects(){
    b2Body* temp=NULL;
    edk::physics2D::PhysicObject2D* tempObject=NULL;
    edk::uint32 count=0u;
    edk::uint32 size = 0u;
    //remove static objects
    size = this->treeStatic.size();
    for(edk::uint32 i=0u;i<size;i++){
        //load the object
        temp = this->treeStatic.getBodyInPosition(count);
        if(temp){
            //
            tempObject = (edk::physics2D::PhysicObject2D*) temp->GetUserData();
            if(tempObject){
                //remove the joints
                this->removeObjectJoints(tempObject);
            }
            if(!this->treeStatic.removeBody(temp))count++;
            if(this->runNextStep)
                //save the object on the deleted tree
                this->treeDeleted.add(temp);
            else
                this->world.DestroyBody(temp);
        }
        else count++;
    }
    //remove static objects
    size = this->treeKinematic.size();
    for(edk::uint32 i=0u;i<size;i++){
        //load the object
        temp = this->treeKinematic.getBodyInPosition(count);
        if(temp){
            //
            tempObject =  (edk::physics2D::PhysicObject2D*)temp->GetUserData();
            if(tempObject){
                //remove the joints
                this->removeObjectJoints(tempObject);
            }
            if(!this->treeKinematic.removeBody(temp))count++;
            if(this->runNextStep)
                //save the object on the deleted tree
                this->treeDeleted.add(temp);
            else
                this->world.DestroyBody(temp);
        }
        else count++;
    }
    this->treeKinematic.clean();
    //remove static objects
    size = this->treeDynamic.size();
    for(edk::uint32 i=0u;i<size;i++){
        //load the object
        temp = this->treeDynamic.getBodyInPosition(count);
        if(temp){
            //
            tempObject =  (edk::physics2D::PhysicObject2D*)temp->GetUserData();
            if(tempObject){
                //remove the joints
                this->removeObjectJoints(tempObject);
            }
            if(!this->treeDynamic.removeBody(temp))count++;
            if(this->runNextStep)
                //save the object on the deleted tree
                this->treeDeleted.add(temp);
            else
                this->world.DestroyBody(temp);
        }
        else count++;
    }
    this->treeDynamic.clean();
}
//test if have the object
bool edk::physics2D::World2D::haveObject(edk::physics2D::PhysicObject2D* object){
    if(object){
        //test the objectType
        switch(object->getType()){
        case edk::physics::StaticBody:
            return this->treeStatic.haveBody(object);
        case edk::physics::DynamicBody:
            return this->treeDynamic.haveBody(object);
        case edk::physics::KinematicBody:
            return this->treeKinematic.haveBody(object);
        }
    }
    return false;
}
//get Objects
edk::uint32 edk::physics2D::World2D::getStaticObjectsSize(){
    return this->treeStatic.size();
}
edk::physics2D::PhysicObject2D* edk::physics2D::World2D::getStaticObjectInPosition(edk::uint32 position){
    b2Body* body = this->treeStatic.getBodyInPosition(position);
    if(body){
        if(body->GetUserData()){
            return (edk::physics2D::PhysicObject2D*)body->GetUserData();
        }
    }
    return NULL;
}
edk::uint32 edk::physics2D::World2D::getDynamicObjectsSize(){
    return this->treeDynamic.size();
}
edk::physics2D::PhysicObject2D* edk::physics2D::World2D::getDynamicObjectInPosition(edk::uint32 position){
    b2Body* body = this->treeDynamic.getBodyInPosition(position);
    if(body){
        if(body->GetUserData()){
            return (edk::physics2D::PhysicObject2D*)body->GetUserData();
        }
    }
    return NULL;
}
edk::uint32 edk::physics2D::World2D::getKinematicObjectsSize(){
    return this->treeKinematic.size();
}
edk::physics2D::PhysicObject2D* edk::physics2D::World2D::getKinematicObjectInPosition(edk::uint32 position){
    b2Body* body = this->treeKinematic.getBodyInPosition(position);
    if(body){
        if(body->GetUserData()){
            return (edk::physics2D::PhysicObject2D*)body->GetUserData();
        }
    }
    return NULL;
}

//update the object position in the world
bool edk::physics2D::World2D::updateObjectVelocity(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);
            break;
        }
        if(temp){
            if(object->haveSettedAngularVelocity()){
                temp->SetAngularVelocity((edk::float32)object->getAngularVelocity() / (180.f / b2_pi));
            }
            if(object->haveSettedLinearVelocity()){
                temp->SetLinearVelocity(b2Vec2(object->getLinearVelocity().x,object->getLinearVelocity().y));
            }
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectLinearVelocity(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);
            break;
        }
        if(temp){
            if(object->haveSettedLinearVelocity()){
                temp->SetLinearVelocity(b2Vec2(object->getLinearVelocity().x,object->getLinearVelocity().y));
            }
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectAngularVelocity(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);
            break;
        }
        if(temp){
            if(object->haveSettedAngularVelocity()){
                temp->SetAngularVelocity((edk::float32)object->getAngularVelocity() / (180.f / b2_pi));
            }
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::cleanObjectVelocity(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);
            break;
        }
        if(temp){
            temp->SetLinearVelocity(b2Vec2(0.f,0.f));

            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectStatus(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);
            break;
        }
        if(temp){
            b2Fixture* fixture = temp->GetFixtureList();
            if(fixture){
                fixture->SetDensity(object->physicMesh.getPolygonDensity(0u));
                fixture->SetFriction(object->physicMesh.getPolygonFriction(0u));
                fixture->SetRestitution(object->physicMesh.getPolygonRestitution(0u));
            }
            return true;
        }
    }
    return false;
}
//move the object to a position
bool edk::physics2D::World2D::moveObject(edk::physics2D::PhysicObject2D* object,edk::vec2f32 move){
    //test the object
    if(object){
        //move the pbject
        object->position+=move;
        return this->updateObjectVelocity(object);
    }
    return false;
}
bool edk::physics2D::World2D::moveObject(edk::physics2D::PhysicObject2D* object,edk::float32 x,edk::float32 y){
    return this->moveObject(object,edk::vec2f32(x,y));
}
bool edk::physics2D::World2D::moveObjectToPosition(edk::physics2D::PhysicObject2D* object,edk::vec2f32 position){
    //test the object
    if(object){
        //move the pbject
        object->position=position;
        return this->updateObjectVelocity(object);
    }
    return false;
}
bool edk::physics2D::World2D::moveObjectToPosition(edk::physics2D::PhysicObject2D* object,edk::float32 positionX,edk::float32 positionY){
    return this->moveObjectToPosition(object,edk::vec2f32(positionX,positionY));
}
//rotate the object
bool edk::physics2D::World2D::rotateObject(edk::physics2D::PhysicObject2D* object,edk::float32 angle){
    //test the object
    if(object){
        //move the pbject
        object->angle+=angle;
        //while(object->angle>360.f)object->angle-=360.f;
        //while(object->angle<0.f)object->angle+=360.f;
        return this->updateObjectVelocity(object);
    }
    return false;
}
bool edk::physics2D::World2D::rotateObjectToAngle(edk::physics2D::PhysicObject2D* object,edk::float32 angle){
    //test the object
    if(object){
        //move the pbject
        object->angle=angle;
        //while(object->angle>360.f)object->angle-=360.f;
        //while(object->angle<0.f)object->angle+=360.f;
        return this->updateObjectVelocity(object);
    }
    return false;
}
//Put a object to sleep
bool edk::physics2D::World2D::sleepObject(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;
        temp = this->treeDynamic.getBody(object);
        if(temp){
            object->canSleep=true;
            temp->SetAwake(false);
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::unsleepObject(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;
        temp = this->treeDynamic.getBody(object);
        if(temp){
            temp->SetAwake(true);
            return true;
        }
    }
    return false;
}

//Add a force to the object
bool edk::physics2D::World2D::setLinearVelocity(edk::physics2D::PhysicObject2D* object,edk::vec2f32 vector){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;
        switch(object->getType()){
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);
            break;
        }
        if(temp){
            temp->SetLinearVelocity(b2Vec2(vector.x,vector.y));
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::setAngularVelocity(edk::physics2D::PhysicObject2D* object,edk::float32 angle){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;
        switch(object->getType()){
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);
            break;
        }
        if(temp){
            temp->SetAngularVelocity(angle / (180.f / b2_pi));
            return true;
        }
    }
    return false;
}
//Apply forces
bool edk::physics2D::World2D::applyForce(edk::physics2D::PhysicObject2D* object,edk::vec2f32 force, edk::vec2f32 position, bool wake){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;
        switch(object->getType()){
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);
            break;
        }
        if(temp){
            temp->ApplyForce(b2Vec2(force.x,force.y),
                             b2Vec2(position.x,position.y),
                             wake
                             );
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::applyLinearImpulse(edk::physics2D::PhysicObject2D* object,edk::vec2f32 impulse, edk::vec2f32 position,bool wake){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;
        switch(object->getType()){
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);
            break;
        }
        if(temp){
            temp->ApplyLinearImpulse(b2Vec2(impulse.x,impulse.y),b2Vec2(position.x,position.y),wake);
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::applyAngularImpulse(edk::physics2D::PhysicObject2D* object,edk::float32 angle,bool wake){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;
        switch(object->getType()){
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);
            break;
        }
        if(temp){
            temp->ApplyAngularImpulse(angle / (180.f / b2_pi),
                                      wake
                                      );
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::applyTorque(edk::physics2D::PhysicObject2D* object,edk::float32 torque,bool wake){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;
        switch(object->getType()){
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);
            break;
        }
        if(temp){
            temp->ApplyTorque(torque,wake);
            return true;
        }
    }
    return false;
}

//process the next step
void edk::physics2D::World2D::nextStep(edk::float32 timeStep,
                                       edk::int32 velocityIterations,
                                       edk::int32 positionIterations){
    if(!this->paused){
        //save the nextSpet
        this->runNextStep = true;
        this->world.Step(timeStep,velocityIterations,positionIterations);
        this->runNextStep = false;

        //remove the bodys
        this->treeDeleted.update();
        this->treeDeleted.clean();

        //update the kinematic objects
        this->treeKinematic.update();
        this->treeDynamic.update();
        this->treeJoint.update();
    }
}
//next spet with clock
void edk::physics2D::World2D::nextStep(edk::int32 velocityIterations, edk::int32 positionIterations){
    //get the clock
    this->nextStep(this->clock.getMicroseconds() * edk::watch::microsecond * this->clockScale,
                   velocityIterations,
                   positionIterations);

    //then clean the clock
    this->clockStart();
}
//pause the world steps
void edk::physics2D::World2D::pauseStepOn(){
    //test if is NOT paused
    if(!this->paused){
        //save the clock
        this->clock.saveDistance();
        this->paused=true;
    }
}
void edk::physics2D::World2D::pauseStepOff(){
    //test if is Paused
    if(this->paused){
        //start the clock and paste the distance
        this->clockStart();
        this->clock.pasteDistance();
        this->paused=false;
    }
}

//reset the clock
void edk::physics2D::World2D::clockStart(){
    this->clock.start();
}
//set clockScale
void edk::physics2D::World2D::setClockScale(edk::float32 clockScale){
    this->clockScale = clockScale;
}


//return the size of contacts
edk::uint32 edk::physics2D::World2D::getContactSize(){
    return this->treeConcacts.getSize();
}
//return the contact
edk::physics2D::Contact2D* edk::physics2D::World2D::getContact(edk::uint32 position){
    return this->treeConcacts.getElementInPosition(position);
}


//joints
//REVOLUTE
edk::physics2D::RevoluteJoint2D* edk::physics2D::World2D::createRevoluteJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                                              edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                                              bool collide
                                                                              ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::physics::StaticBody || objectB->getType()!=edk::physics::StaticBody){
            //load the objects
            b2Body* bodyA = this->getBody(objectA);
            b2Body* bodyB = this->getBody(objectB);

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::RevoluteJoint2D *edkJoint = NULL;
                //create the revolute def
                b2RevoluteJointDef jointDef;
                jointDef.collideConnected=collide;
                jointDef.bodyA = bodyA;
                jointDef.bodyB = bodyB;
                jointDef.localAnchorA = b2Vec2(positionA.x,positionA.y);
                jointDef.localAnchorB = b2Vec2(positionB.x,positionB.y);

                //create the edkJoint
                edkJoint = new edk::physics2D::RevoluteJoint2D(collide);
                if(edkJoint){
                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectA,positionA)
                            ;
                    edkJoint->positionB = positionB;
                    /*
                    edkJoint->worldPositionB
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectB,positionB)
                            ;
*/

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                        if(joint){
                            joint->SetUserData(edkJoint);
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);
                        }
                        this->destroyJoint(edkJoint);
                    }
                }
            }
        }
    }
    return NULL;
}
edk::physics2D::RevoluteJoint2D* edk::physics2D::World2D::createRevoluteJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                              edk::physics2D::PhysicObject2D* objectB,
                                                                              edk::vec2f32 worldPosition,
                                                                              bool collide
                                                                              ){
    //test the object
    if(objectA && objectB){
        return this->createRevoluteJoint(objectA,
                                         edk::physics2D::World2D::JointTree::getJointPosition(objectA,worldPosition),
                                         objectB,
                                         edk::physics2D::World2D::JointTree::getJointPosition(objectB,worldPosition),
                                         collide
                                         );
    }
    return NULL;
}
edk::physics2D::RevoluteJoint2D* edk::physics2D::World2D::createRevoluteAngleJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                                                   edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                                                   edk::float32 lowerAngle,edk::float32 upperAngle,
                                                                                   bool collide
                                                                                   ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::physics::StaticBody || objectB->getType()!=edk::physics::StaticBody){
            //load the objects
            b2Body* bodyA = this->getBody(objectA);
            b2Body* bodyB = this->getBody(objectB);

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::RevoluteJoint2D *edkJoint = NULL;
                //create the revolute def
                b2RevoluteJointDef jointDef;
                jointDef.collideConnected=collide;
                jointDef.bodyA = bodyA;
                jointDef.bodyB = bodyB;
                jointDef.localAnchorA = b2Vec2(positionA.x,positionA.y);
                jointDef.localAnchorB = b2Vec2(positionB.x,positionB.y);

                jointDef.lowerAngle = (lowerAngle / 180.f) * b2_pi;
                jointDef.upperAngle = (upperAngle/ 180.f) * b2_pi;
                jointDef.enableLimit=true;



                //create the edkJoint
                edkJoint = new edk::physics2D::RevoluteJoint2D(collide);
                if(edkJoint){
                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA = edk::physics2D::World2D::JointTree::getJointWorldPosition(objectA,positionA);
                    edkJoint->positionB = positionB;

                    //angle Joint
                    edkJoint->setAngle(lowerAngle,upperAngle);

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                        if(joint){
                            joint->SetUserData(edkJoint);
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);
                        }
                        this->destroyJoint(edkJoint);
                    }
                }
            }
        }
    }
    return NULL;
}
edk::physics2D::RevoluteJoint2D* edk::physics2D::World2D::createRevoluteAngleJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                                                   edk::float32 lowerAngle,edk::float32 upperAngle,
                                                                                   bool collide
                                                                                   ){
    //test the object
    if(objectA && objectB){
        return this->createRevoluteAngleJoint(objectA,
                                              edk::physics2D::World2D::JointTree::getJointPosition(objectA,worldPosition),
                                              objectB,
                                              edk::physics2D::World2D::JointTree::getJointPosition(objectB,worldPosition),
                                              lowerAngle,upperAngle,
                                              collide
                                              );
    }
    return NULL;
}
edk::physics2D::RevoluteJoint2D* edk::physics2D::World2D::createRevoluteMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                                                   edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                                                   edk::float32 maxTorque,edk::float32 speed,
                                                                                   bool collide
                                                                                   ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::physics::StaticBody || objectB->getType()!=edk::physics::StaticBody){
            //load the objects
            b2Body* bodyA = this->getBody(objectA);
            b2Body* bodyB = this->getBody(objectB);

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::RevoluteJoint2D *edkJoint = NULL;
                //create the revolute def
                b2RevoluteJointDef jointDef;
                jointDef.collideConnected=collide;
                jointDef.bodyA = bodyA;
                jointDef.bodyB = bodyB;
                jointDef.localAnchorA = b2Vec2(positionA.x,positionA.y);
                jointDef.localAnchorB = b2Vec2(positionB.x,positionB.y);

                jointDef.maxMotorTorque = maxTorque;
                jointDef.motorSpeed = speed;
                jointDef.enableMotor=true;



                //create the edkJoint
                edkJoint = new edk::physics2D::RevoluteJoint2D(collide);
                if(edkJoint){
                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectA,positionA)
                            ;
                    edkJoint->positionB = positionB;

                    //set motor
                    edkJoint->setMotor(maxTorque,speed);

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                        if(joint){
                            joint->SetUserData(edkJoint);
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);
                        }
                        this->destroyJoint(edkJoint);
                    }
                }
            }
        }
    }
    return NULL;
}
edk::physics2D::RevoluteJoint2D* edk::physics2D::World2D::createRevoluteMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                                                   edk::float32 maxTorque,edk::float32 speed,
                                                                                   bool collide
                                                                                   ){
    //test the object
    if(objectA && objectB){
        return this->createRevoluteMotorJoint(objectA,
                                              edk::physics2D::World2D::JointTree::getJointPosition(objectA,worldPosition),
                                              objectB,
                                              edk::physics2D::World2D::JointTree::getJointPosition(objectB,worldPosition),
                                              maxTorque,speed,
                                              collide
                                              );
    }
    return NULL;
}
//PRISMATIC
edk::physics2D::PrismaticJoint2D* edk::physics2D::World2D::createPrismaticJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                                                edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                                                edk::vec2f32 direction,
                                                                                edk::float32 lowerDistance,
                                                                                edk::float32 upperDistance,
                                                                                bool collide
                                                                                ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::physics::StaticBody || objectB->getType()!=edk::physics::StaticBody){
            //load the objects
            b2Body* bodyA = this->getBody(objectA);
            b2Body* bodyB = this->getBody(objectB);

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::PrismaticJoint2D *edkJoint = NULL;
                //create the revolute def
                b2PrismaticJointDef jointDef;
                jointDef.collideConnected=collide;
                jointDef.bodyA = bodyA;
                jointDef.bodyB = bodyB;
                jointDef.localAnchorA = b2Vec2(positionA.x,positionA.y);
                jointDef.localAnchorB = b2Vec2(positionB.x,positionB.y);
                jointDef.localAxisA = b2Vec2(direction.x,direction.y);
                jointDef.localAxisA.Normalize();
                if(upperDistance > lowerDistance){
                    //enable distance
                    jointDef.lowerTranslation = lowerDistance;
                    jointDef.upperTranslation = upperDistance;
                    jointDef.enableLimit=true;
                }

                //create the edkJoint
                edkJoint = new edk::physics2D::PrismaticJoint2D(collide);
                if(edkJoint){
                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectA,positionA)
                            ;
                    edkJoint->positionB = positionB;

                    edkJoint->direction = direction;

                    //Set Angle
                    edkJoint->upperDistance = upperDistance;
                    edkJoint->lowerDistance = lowerDistance;

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                        if(joint){
                            joint->SetUserData(edkJoint);
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);
                        }
                        this->destroyJoint(edkJoint);
                    }
                }
            }
        }
    }
    return NULL;
}
edk::physics2D::PrismaticJoint2D* edk::physics2D::World2D::createPrismaticJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                                                edk::vec2f32 direction,
                                                                                edk::float32 lowerDistance,
                                                                                edk::float32 upperDistance,
                                                                                bool collide
                                                                                ){
    //test the object
    if(objectA && objectB){
        return this->createPrismaticJoint(objectA,
                                          edk::physics2D::World2D::JointTree::getJointPosition(objectA,worldPosition),
                                          objectB,
                                          edk::physics2D::World2D::JointTree::getJointPosition(objectB,worldPosition),
                                          direction,lowerDistance,upperDistance,
                                          collide
                                          );
    }
    return NULL;
}
edk::physics2D::PrismaticJoint2D* edk::physics2D::World2D::createPrismaticJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                                                edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                                                edk::float32 angle, edk::float32 lowerDistance, edk::float32 upperDistance,
                                                                                bool collide
                                                                                ){
    //test the object
    if(objectA && objectB){
        return this->createPrismaticJoint(objectA,positionA,
                                          objectB,positionB,
                                          edk::Math::rotate2f(edk::vec2f32(1,0),angle),lowerDistance,upperDistance,
                                          collide
                                          );
    }
    return NULL;
}
edk::physics2D::PrismaticJoint2D* edk::physics2D::World2D::createPrismaticJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                                                edk::float32 angle, edk::float32 lowerDistance, edk::float32 upperDistance,
                                                                                bool collide
                                                                                ){
    //test the object
    if(objectA && objectB){
        return this->createPrismaticJoint(objectA,
                                          edk::physics2D::World2D::JointTree::getJointPosition(objectA,worldPosition),
                                          objectB,
                                          edk::physics2D::World2D::JointTree::getJointPosition(objectB,worldPosition),
                                          edk::Math::rotate2f(edk::vec2f32(1,0),angle),lowerDistance,upperDistance,
                                          collide
                                          );
    }
    return NULL;
}
edk::physics2D::PrismaticJoint2D* edk::physics2D::World2D::createPrismaticMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                                                     edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                                                     edk::vec2f32 direction, edk::float32 lowerDistance, edk::float32 upperDistance,
                                                                                     edk::float32 maxForce,edk::float32 speed,
                                                                                     bool collide
                                                                                     ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::physics::StaticBody || objectB->getType()!=edk::physics::StaticBody){
            //load the objects
            b2Body* bodyA = this->getBody(objectA);
            b2Body* bodyB = this->getBody(objectB);

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::PrismaticJoint2D *edkJoint = NULL;
                //create the revolute def
                b2PrismaticJointDef jointDef;
                jointDef.collideConnected=collide;
                jointDef.bodyA = bodyA;
                jointDef.bodyB = bodyB;
                jointDef.localAnchorA = b2Vec2(positionA.x,positionA.y);
                jointDef.localAnchorB = b2Vec2(positionB.x,positionB.y);
                jointDef.localAxisA = b2Vec2(direction.x,direction.y);
                jointDef.localAxisA.Normalize();
                if(upperDistance > lowerDistance){
                    //enable distance
                    jointDef.lowerTranslation = lowerDistance;
                    jointDef.upperTranslation = upperDistance;
                    jointDef.enableLimit=true;
                }
                jointDef.maxMotorForce = maxForce;
                jointDef.motorSpeed = speed;
                jointDef.enableMotor=true;

                //create the edkJoint
                edkJoint = new edk::physics2D::PrismaticJoint2D(collide);
                if(edkJoint){
                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectA,positionA)
                            ;
                    edkJoint->positionB = positionB;

                    edkJoint->direction = direction;

                    //Set Angle
                    edkJoint->lowerDistance = lowerDistance;
                    edkJoint->upperDistance = upperDistance;
                    //Set motor as the last because the joint will return motor type
                    edkJoint->setForce(maxForce,speed);

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                        if(joint){
                            joint->SetUserData(edkJoint);
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);
                        }
                        this->destroyJoint(edkJoint);
                    }
                }
            }
        }
    }
    return NULL;
}
edk::physics2D::PrismaticJoint2D* edk::physics2D::World2D::createPrismaticMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                                                     edk::vec2f32 direction, edk::float32 lowerDistance, edk::float32 upperDistance,
                                                                                     edk::float32 maxForce,edk::float32 speed,
                                                                                     bool collide
                                                                                     ){
    //test the object
    if(objectA && objectB){
        return this->createPrismaticMotorJoint(objectA,
                                               edk::physics2D::World2D::JointTree::getJointPosition(objectA,worldPosition),
                                               objectB,
                                               edk::physics2D::World2D::JointTree::getJointPosition(objectB,worldPosition),
                                               direction,lowerDistance,upperDistance,
                                               maxForce,speed,
                                               collide
                                               );
    }
    return NULL;
}
edk::physics2D::PrismaticJoint2D* edk::physics2D::World2D::createPrismaticMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                                                     edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                                                     edk::float32 angle, edk::float32 lowerDistance, edk::float32 upperDistance,
                                                                                     edk::float32 maxForce,edk::float32 speed,
                                                                                     bool collide
                                                                                     ){
    //test the object
    if(objectA && objectB){
        return this->createPrismaticMotorJoint(objectA,positionA,
                                               objectB,positionB,
                                               edk::Math::rotate2f(edk::vec2f32(1,0),angle),lowerDistance,upperDistance,
                                               maxForce,speed,
                                               collide
                                               );
    }
    return NULL;
}
edk::physics2D::PrismaticJoint2D* edk::physics2D::World2D::createPrismaticMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                                                     edk::float32 angle, edk::float32 lowerDistance, edk::float32 upperDistance,
                                                                                     edk::float32 maxForce,edk::float32 speed,
                                                                                     bool collide
                                                                                     ){
    //test the object
    if(objectA && objectB){
        return this->createPrismaticMotorJoint(objectA,
                                               edk::physics2D::World2D::JointTree::getJointPosition(objectA,worldPosition),
                                               objectB,
                                               edk::physics2D::World2D::JointTree::getJointPosition(objectB,worldPosition),
                                               edk::Math::rotate2f(edk::vec2f32(1,0),angle),lowerDistance,upperDistance,
                                               maxForce,speed,
                                               collide
                                               );
    }
    return NULL;
}

//DISTANCE
edk::physics2D::DistanceJoint2D* edk::physics2D::World2D::createDistanceJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                              edk::vec2f32 positionA,
                                                                              edk::physics2D::PhysicObject2D* objectB,
                                                                              edk::vec2f32 positionB,
                                                                              edk::float32 frequency,edk::float32 distance,
                                                                              bool collide
                                                                              ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::physics::StaticBody || objectB->getType()!=edk::physics::StaticBody){
            //load the objects
            b2Body* bodyA = this->getBody(objectA);
            b2Body* bodyB = this->getBody(objectB);

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::DistanceJoint2D *edkJoint = NULL;
                //create the revolute def
                b2DistanceJointDef jointDef;
                jointDef.collideConnected=collide;
                jointDef.bodyA = bodyA;
                jointDef.bodyB = bodyB;
                jointDef.localAnchorA = b2Vec2(positionA.x,positionA.y);
                jointDef.localAnchorB = b2Vec2(positionB.x,positionB.y);
                jointDef.length = distance;

                jointDef.frequencyHz = frequency;

                //create the edkJoint
                edkJoint = new edk::physics2D::DistanceJoint2D(collide);
                if(edkJoint){
                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectA,positionA)
                            ;
                    edkJoint->positionB = positionB;
                    edkJoint->worldPositionB
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectB,positionB)
                            ;

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                        if(joint){
                            joint->SetUserData(edkJoint);
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);
                        }
                        this->destroyJoint(edkJoint);
                    }
                }
            }
        }
    }
    return NULL;
}
edk::physics2D::DistanceJoint2D* edk::physics2D::World2D::createDistanceJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 worldPositionA,
                                                                              edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPositionB,
                                                                              edk::float32 frequency,
                                                                              bool collide
                                                                              ){
    //test the object
    if(objectA && objectB){
        return this->createDistanceJoint(objectA,
                                         edk::physics2D::World2D::JointTree::getJointPosition(objectA,worldPositionA),
                                         objectB,
                                         edk::physics2D::World2D::JointTree::getJointPosition(objectB,worldPositionB),
                                         frequency,
                                         edk::Math::moduleFloat(edk::Math::pythagoras2f(worldPositionA - worldPositionB)),
                                         collide
                                         );
    }
    return NULL;
}
//PULLEY
edk::physics2D::PulleyJoint2D* edk::physics2D::World2D::createPulleyJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA, edk::vec2f32 pulleyPositionA,
                                                                          edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB, edk::vec2f32 pulleyPositionB,
                                                                          edk::float32 lenghtA,edk::float32 lenghtB,
                                                                          bool collide
                                                                          ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::physics::StaticBody || objectB->getType()!=edk::physics::StaticBody){
            //load the objects
            b2Body* bodyA = this->getBody(objectA);
            b2Body* bodyB = this->getBody(objectB);

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::PulleyJoint2D *edkJoint = NULL;
                //create the revolute def
                b2PulleyJointDef jointDef;
                jointDef.collideConnected=collide;
                jointDef.bodyA = bodyA;
                jointDef.bodyB = bodyB;
                jointDef.localAnchorA = b2Vec2(positionA.x,positionA.y);
                jointDef.localAnchorB = b2Vec2(positionB.x,positionB.y);

                jointDef.groundAnchorA = b2Vec2(pulleyPositionA.x + objectA->position.x,pulleyPositionA.y + objectA->position.y);
                jointDef.groundAnchorB = b2Vec2(pulleyPositionB.x + objectB->position.x,pulleyPositionB.y + objectB->position.y);

                jointDef.lengthA = lenghtA;
                jointDef.lengthB = lenghtB;

                //create the edkJoint
                edkJoint = new edk::physics2D::PulleyJoint2D(collide);
                if(edkJoint){
                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectA,positionA)
                            ;
                    edkJoint->positionB = positionB;
                    edkJoint->worldPositionB
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectB,positionB)
                            ;
                    edkJoint->pulleyPositionA
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectA,pulleyPositionA)
                            ;
                    edkJoint->pulleyPositionB
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectB,pulleyPositionB)
                            ;


                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                        if(joint){
                            joint->SetUserData(edkJoint);
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);
                        }
                        this->destroyJoint(edkJoint);
                    }
                }
            }
        }
    }
    return NULL;
}
edk::physics2D::PulleyJoint2D* edk::physics2D::World2D::createPulleyJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA, edk::vec2f32 pulleyPositionA,
                                                                          edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB, edk::vec2f32 pulleyPositionB,
                                                                          bool collide
                                                                          ){
    //test the object
    if(objectA && objectB){
        return this->createPulleyJoint(objectA,positionA, pulleyPositionA,
                                       objectB,positionB, pulleyPositionB,
                                       edk::Math::moduleFloat(edk::Math::pythagoras2f(pulleyPositionA-positionA)),
                                       edk::Math::moduleFloat(edk::Math::pythagoras2f(pulleyPositionB-positionB)),
                                       collide
                                       );
    }
    return NULL;
}
edk::physics2D::PulleyJoint2D* edk::physics2D::World2D::createPulleyWorldJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 worldPositionA, edk::vec2f32 pulleyWorldPositionA,
                                                                               edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPositionB, edk::vec2f32 pulleyWorldPositionB,
                                                                               edk::float32 lenghtA,edk::float32 lenghtB,
                                                                               bool collide
                                                                               ){
    //test the object
    if(objectA && objectB){
        createPulleyJoint(objectA,
                          edk::physics2D::World2D::JointTree::getJointPosition(objectA,worldPositionA),
                          edk::physics2D::World2D::JointTree::getJointPosition(objectA,pulleyWorldPositionA),
                          objectB,
                          edk::physics2D::World2D::JointTree::getJointPosition(objectB,worldPositionB),
                          edk::physics2D::World2D::JointTree::getJointPosition(objectB,pulleyWorldPositionB),
                          lenghtA,lenghtB,
                          collide
                          );
    }
    return NULL;
}
edk::physics2D::PulleyJoint2D* edk::physics2D::World2D::createPulleyWorldJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 worldPositionA, edk::vec2f32 pulleyWorldPositionA,
                                                                               edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPositionB, edk::vec2f32 pulleyWorldPositionB,
                                                                               bool collide
                                                                               ){
    //test the object
    if(objectA && objectB){
        createPulleyJoint(objectA,
                          edk::physics2D::World2D::JointTree::getJointPosition(objectA,worldPositionA),
                          edk::physics2D::World2D::JointTree::getJointPosition(objectA,pulleyWorldPositionA),
                          objectB,
                          edk::physics2D::World2D::JointTree::getJointPosition(objectB,worldPositionB),
                          edk::physics2D::World2D::JointTree::getJointPosition(objectB,pulleyWorldPositionB),
                          collide
                          );
    }
    return NULL;
}
//WHEEL
edk::physics2D::WheelJoint2D* edk::physics2D::World2D::createWheelJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                                        edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                                        edk::vec2f32 direction, edk::float32 frequency, edk::float32 dampingRatio,
                                                                        bool collide
                                                                        ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::physics::StaticBody || objectB->getType()!=edk::physics::StaticBody){
            //load the objects
            b2Body* bodyA = this->getBody(objectA);
            b2Body* bodyB = this->getBody(objectB);

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::WheelJoint2D *edkJoint = NULL;
                //create the revolute def
                b2WheelJointDef jointDef;
                jointDef.collideConnected=collide;
                jointDef.bodyA = bodyA;
                jointDef.bodyB = bodyB;
                jointDef.localAnchorA = b2Vec2(positionA.x,positionA.y);
                jointDef.localAnchorB = b2Vec2(positionB.x,positionB.y);

                jointDef.localAxisA = b2Vec2(direction.x,direction.y);
                jointDef.localAxisA.Normalize();

                jointDef.frequencyHz = frequency;
                jointDef.dampingRatio = dampingRatio;

                //create the edkJoint
                edkJoint = new edk::physics2D::WheelJoint2D(collide);
                if(edkJoint){
                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectA,positionA)
                            ;
                    edkJoint->positionB = positionB;

                    edkJoint->direction = direction;

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                        if(joint){
                            joint->SetUserData(edkJoint);
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);
                        }
                        this->destroyJoint(edkJoint);
                    }
                }
            }
        }
    }
    return NULL;
}
edk::physics2D::WheelJoint2D* edk::physics2D::World2D::createWheelJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                                        edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                                        edk::vec2f32 direction,
                                                                        bool collide
                                                                        ){
    //test the object
    if(objectA && objectB){
        return this->createWheelJoint(objectA,positionA,
                                      objectB,positionB,
                                      direction,1, 1,
                                      collide
                                      );
    }
    return NULL;
}

edk::physics2D::WheelJoint2D* edk::physics2D::World2D::createWheelJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                                        edk::vec2f32 direction, edk::float32 frequency, edk::float32 dampingRatio,
                                                                        bool collide
                                                                        ){
    //test the object
    if(objectA && objectB){
        return this->createWheelJoint(objectA,
                                      edk::physics2D::World2D::JointTree::getJointPosition(objectA,worldPosition),
                                      objectB,
                                      edk::physics2D::World2D::JointTree::getJointPosition(objectB,worldPosition),
                                      direction,frequency, dampingRatio,
                                      collide
                                      );
    }
    return NULL;
}
edk::physics2D::WheelJoint2D* edk::physics2D::World2D::createWheelJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                                        edk::vec2f32 direction,
                                                                        bool collide
                                                                        ){
    //test the object
    if(objectA && objectB){
        return this->createWheelJoint(objectA,objectB,worldPosition,
                                      direction,1, 1,
                                      collide
                                      );
    }
    return NULL;
}
edk::physics2D::WheelJoint2D* edk::physics2D::World2D::createWheelMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                                             edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                                             edk::vec2f32 direction, edk::float32 frequency, edk::float32 dampingRatio,
                                                                             edk::float32 maxTorque,edk::float32 speed,
                                                                             bool collide
                                                                             ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::physics::StaticBody || objectB->getType()!=edk::physics::StaticBody){
            //load the objects
            b2Body* bodyA = this->getBody(objectA);
            b2Body* bodyB = this->getBody(objectB);

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::WheelJoint2D *edkJoint = NULL;
                //create the revolute def
                b2WheelJointDef jointDef;
                jointDef.collideConnected=collide;
                jointDef.bodyA = bodyA;
                jointDef.bodyB = bodyB;
                jointDef.localAnchorA = b2Vec2(positionA.x,positionA.y);
                jointDef.localAnchorB = b2Vec2(positionB.x,positionB.y);

                jointDef.localAxisA = b2Vec2(direction.x,direction.y);
                jointDef.localAxisA.Normalize();

                jointDef.frequencyHz = frequency;
                jointDef.dampingRatio = dampingRatio;

                jointDef.maxMotorTorque = maxTorque;
                jointDef.motorSpeed = speed;
                jointDef.enableMotor=true;

                //create the edkJoint
                edkJoint = new edk::physics2D::WheelJoint2D(collide);
                if(edkJoint){
                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectA,positionA)
                            ;
                    edkJoint->positionB = positionB;

                    edkJoint->direction = direction;

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                        if(joint){
                            joint->SetUserData(edkJoint);
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);
                        }
                        this->destroyJoint(edkJoint);
                    }
                }
            }
        }
    }
    return NULL;
}
edk::physics2D::WheelJoint2D* edk::physics2D::World2D::createWheelMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                                             edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                                             edk::vec2f32 direction,
                                                                             edk::float32 maxTorque,edk::float32 speed,
                                                                             bool collide
                                                                             ){
    //test the object
    if(objectA && objectB){
        return this->createWheelMotorJoint(objectA,positionA,
                                           objectB,positionB,
                                           direction,1, 1,
                                           maxTorque,speed,
                                           collide
                                           );
    }
    return NULL;
}
edk::physics2D::WheelJoint2D* edk::physics2D::World2D::createWheelMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                                             edk::vec2f32 direction, edk::float32 frequency, edk::float32 dampingRatio,
                                                                             edk::float32 maxTorque,edk::float32 speed,
                                                                             bool collide
                                                                             ){
    //test the object
    if(objectA && objectB){
        return this->createWheelMotorJoint(objectA,
                                           edk::physics2D::World2D::JointTree::getJointPosition(objectA,worldPosition),
                                           objectB,
                                           edk::physics2D::World2D::JointTree::getJointPosition(objectB,worldPosition),
                                           direction,frequency, dampingRatio,
                                           maxTorque,speed,
                                           collide
                                           );
    }
    return NULL;
}
edk::physics2D::WheelJoint2D* edk::physics2D::World2D::createWheelMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                                             edk::vec2f32 direction,
                                                                             edk::float32 maxTorque,edk::float32 speed,
                                                                             bool collide
                                                                             ){
    //test the object
    if(objectA && objectB){
        return this->createWheelMotorJoint(objectA,objectB,worldPosition,
                                           direction,1, 1,
                                           maxTorque,speed,
                                           collide
                                           );
    }
    return NULL;
}

//WELD
edk::physics2D::Joint2D* edk::physics2D::World2D::createWeldJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                                  edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                                  bool collide
                                                                  ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::physics::StaticBody || objectB->getType()!=edk::physics::StaticBody){
            //load the objects
            b2Body* bodyA = this->getBody(objectA);
            b2Body* bodyB = this->getBody(objectB);

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::Joint2D *edkJoint = NULL;
                //create the revolute def
                b2WeldJointDef jointDef;
                jointDef.collideConnected=collide;
                jointDef.bodyA = bodyA;
                jointDef.bodyB = bodyB;
                jointDef.localAnchorA = b2Vec2(positionA.x,positionA.y);
                jointDef.localAnchorB = b2Vec2(positionB.x,positionB.y);

                //create the edkJoint
                if((edkJoint = this->addJoint(objectA,positionA,objectB,positionB))){
                    //
                    b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                    if(joint){
                        joint->SetUserData(edkJoint);
                        //add the joint in the tree
                        if(this->treeJoint.addJoint(edkJoint,joint)){
                            return edkJoint;
                        }
                        //else destroy the joint
                        this->world.DestroyJoint(joint);
                    }
                    this->destroyJoint(edkJoint);
                }
            }
        }
    }
    return NULL;
}

edk::physics2D::Joint2D* edk::physics2D::World2D::createWeldJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                                  bool collide
                                                                  ){
    //test the object
    if(objectA && objectB){
        return this->createWeldJoint(objectA,
                                     edk::physics2D::World2D::JointTree::getJointPosition(objectA,worldPosition),
                                     objectB,
                                     edk::physics2D::World2D::JointTree::getJointPosition(objectB,worldPosition),
                                     collide
                                     );
    }
    return NULL;
}
//ROPE
edk::physics2D::RopeJoint2D* edk::physics2D::World2D::createRopeJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                                      edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                                      edk::float32 maxLength,
                                                                      bool collide
                                                                      ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::physics::StaticBody || objectB->getType()!=edk::physics::StaticBody){
            //load the objects
            b2Body* bodyA = this->getBody(objectA);
            b2Body* bodyB = this->getBody(objectB);

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::RopeJoint2D *edkJoint = NULL;
                //create the revolute def
                b2RopeJointDef jointDef;
                jointDef.collideConnected=collide;
                jointDef.bodyA = bodyA;
                jointDef.bodyB = bodyB;
                jointDef.localAnchorA = b2Vec2(positionA.x,positionA.y);
                jointDef.localAnchorB = b2Vec2(positionB.x,positionB.y);

                jointDef.maxLength = maxLength;

                //create the edkJoint
                edkJoint = new edk::physics2D::RopeJoint2D(collide);
                if(edkJoint){
                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectA,positionA)
                            ;
                    edkJoint->positionB = positionB;
                    edkJoint->worldPositionB
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectB,positionB)
                            ;
                    edkJoint->maxLength = maxLength;

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                        if(joint){
                            joint->SetUserData(edkJoint);
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);
                        }
                        this->destroyJoint(edkJoint);
                    }
                }
            }
        }
    }
    return NULL;
}
edk::physics2D::RopeJoint2D* edk::physics2D::World2D::createRopeJointWorldPositions(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 worldPositionA,
                                                                                    edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPositionB,
                                                                                    edk::float32 maxLength,
                                                                                    bool collide
                                                                                    ){
    //test the object
    if(objectA && objectB){
        return this->createRopeJoint(objectA,
                                     edk::physics2D::World2D::JointTree::getJointPosition(objectA,worldPositionA),
                                     objectB,
                                     edk::physics2D::World2D::JointTree::getJointPosition(objectB,worldPositionB),
                                     maxLength,
                                     collide
                                     );
    }
    return NULL;
}
edk::physics2D::RopeJoint2D* edk::physics2D::World2D::createRopeJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 worldPositionA,
                                                                      edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPositionB,
                                                                      bool collide
                                                                      ){
    //test the object
    if(objectA && objectB){
        return this->createRopeJointWorldPositions(objectA,
                                                   worldPositionA,
                                                   objectB,
                                                   worldPositionB,
                                                   edk::Math::moduleFloat(edk::Math::pythagoras2f(worldPositionA - worldPositionB)),
                                                   collide
                                                   );
    }
    return NULL;
}
//GEAR
/*
edk::physics2D::RopeJoint2D* edk::physics2D::World2D::createGearJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                                      edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                                      edk::float32 distance,
                                                                      bool collide
                                                                      ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::physics::StaticBody || objectB->getType()!=edk::physics::StaticBody){
            //load the objects
            b2Body* bodyA = this->getBody(objectA);
            b2Body* bodyB = this->getBody(objectB);

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::RopeJoint2D *edkJoint = NULL;
                //create the revolute def
                b2GearJointDef jointDef;
                jointDef.collideConnected=collide;
                jointDef.bodyA = bodyA;
                jointDef.bodyB = bodyB;
                jointDef.localAnchorA = b2Vec2(positionA.x,positionA.y);
                jointDef.localAnchorB = b2Vec2(positionB.x,positionB.y);

                jointDef.distance = distance;

                //create the edkJoint
                edkJoint = new edk::physics2D::RopeJoint2D(collide);
                if(edkJoint){
                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectA,positionA)
                            ;
                    edkJoint->positionB = positionB;
                    edkJoint->worldPositionB
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectB,positionB)
                            ;

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                        if(joint){
                            joint->SetUserData(edkJoint);
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);
                        }
                        this->destroyJoint(edkJoint);
                    }
                }
            }
        }
    }
    return NULL;
}
*/

//destroy the joint
bool edk::physics2D::World2D::destroyJoint(edk::physics2D::Joint2D* joint){
    if(joint){
        //remove the joint from the objects
        edk::physics2D::World2D::ObjectsJointsTree* treeTemp = this->treeJointObjects.getTreeJoint(joint->objectA);
        edk::physics2D::World2D::ObjectJointsTree* objectJointsTemp = NULL;
        if(treeTemp){
            //load the tree objectJoints
            objectJointsTemp = treeTemp->getJoint(joint->objectB);
            if(objectJointsTemp){
                //remove the joint
                objectJointsTemp->removeJoint(joint);
                if(!objectJointsTemp->getSize()){
                    treeTemp->removeJoint(objectJointsTemp);
                    objectJointsTemp->cleanJoints();
                    delete objectJointsTemp;
                    objectJointsTemp=NULL;
                }
            }
        }
        treeTemp = this->treeJointObjects.getTreeJoint(joint->objectB);
        if(treeTemp){
            //load the tree objectJoints
            objectJointsTemp = treeTemp->getJoint(joint->objectA);
            if(objectJointsTemp){
                //remove the joint
                objectJointsTemp->removeJoint(joint);
                if(!objectJointsTemp->getSize()){
                    treeTemp->removeJoint(objectJointsTemp);
                    objectJointsTemp->cleanJoints();
                    delete objectJointsTemp;
                    objectJointsTemp=NULL;
                }
            }
        }

        //get the b2joint
        b2Joint* boxJoint = this->treeJoint.getJoint(joint);
        if(boxJoint){
            this->treeJoint.removeJoint(boxJoint);

            //destroy the joint
            this->world.DestroyJoint(boxJoint);
            //delete the joint
            delete joint;
            return true;
        }
    }
    return false;
}
//destroy joint with the object
bool edk::physics2D::World2D::destroyObjectJoints(edk::physics2D::PhysicObject2D* object){
    return this->removeObjectJoints(object);
}
//return the joint
edk::physics2D::Joint2D* edk::physics2D::World2D::getJointInPosition(edk::uint32 position){
    if(this->treeJoint.size()){
        //return the joint
        return this->treeJoint.getJointInPosition(position);
    }
    return NULL;
}
//get Joint Type
edk::uint8 edk::physics2D::World2D::getJointTypeInPosition(edk::uint32 position){
    edk::physics2D::Joint2D* joint = this->getJointInPosition(position);
    if(joint) return joint->getType();
    return 0u;
}

//return the joints count
edk::uint32 edk::physics2D::World2D::getJointSize(){
    return this->treeJoint.size();
}

//update the joints
bool edk::physics2D::World2D::setMotorJointMaxTorque(edk::physics2D::Joint2D* joint,edk::float32 maxTorque){
    //text the joint
    if(joint){
        //load the b2joint
        b2Joint *boxJoint = this->treeJoint.getJoint(joint);
        if(boxJoint){
            switch(boxJoint->GetType()){
            case e_revoluteJoint:
                //
            {
                b2RevoluteJoint* temp = (b2RevoluteJoint*)boxJoint;
                temp->SetMaxMotorTorque(maxTorque);
                return true;
            }
            case e_motorJoint:
                //
            {
                b2MotorJoint* temp = (b2MotorJoint*)boxJoint;
                temp->SetMaxTorque(maxTorque);
                return true;
            }
            default:
                break;
            }//end switch
        }
    }
    return false;
}
bool edk::physics2D::World2D::setMotorJointSpeed(edk::physics2D::Joint2D* joint,edk::float32 speed){
    //text the joint
    if(joint){
        //load the b2joint
        b2Joint *boxJoint = this->treeJoint.getJoint(joint);
        if(boxJoint){
            switch(boxJoint->GetType()){
            case e_revoluteJoint:
                //
            {
                b2RevoluteJoint* temp = (b2RevoluteJoint*)boxJoint;
                temp->SetMotorSpeed(speed);
                return true;
            }
            default:
                break;
            }//end switch
        }
    }
    return false;
}
//Set the torque and speed
bool edk::physics2D::World2D::setMotorJointTorqueAndSpeed(edk::physics2D::Joint2D* joint,edk::float32 maxTorque,edk::float32 speed){
    //text the joint
    if(joint){
        //load the b2joint
        b2Joint *boxJoint = this->treeJoint.getJoint(joint);
        if(boxJoint){
            switch(boxJoint->GetType()){
            case e_revoluteJoint:
                //
            {
                b2RevoluteJoint* temp = (b2RevoluteJoint*)boxJoint;
                temp->SetMaxMotorTorque(maxTorque);
                temp->SetMotorSpeed(speed);
                return true;
            }
            default:
                break;
            }//end switch
        }
    }
    return false;
}
//Return the joints
edk::float32 edk::physics2D::World2D::getRevoluteJointAngle(edk::physics2D::Joint2D* joint){
    //text the joint
    if(joint){
        //load the b2joint
        b2Joint *boxJoint = this->treeJoint.getJoint(joint);
        if(boxJoint){
            switch(boxJoint->GetType()){
            case e_revoluteJoint:
                //
            {
                b2RevoluteJoint* temp = (b2RevoluteJoint*)boxJoint;
                return temp->GetJointAngle();
            }
            default:
                break;
            }//end switch
        }
    }
    return 0.f;
}
edk::float32 edk::physics2D::World2D::getMotorJointTorque(edk::physics2D::Joint2D* joint){
    //text the joint
    if(joint){
        //load the b2joint
        b2Joint *boxJoint = this->treeJoint.getJoint(joint);
        if(boxJoint){
            switch(boxJoint->GetType()){
            case e_revoluteJoint:
                //
            {
                b2RevoluteJoint* temp = (b2RevoluteJoint*)boxJoint;
                return temp->GetMaxMotorTorque();
            }
            default:
                break;
            }//end switch
        }
    }
    return 0.f;
}
edk::float32 edk::physics2D::World2D::getMotorJointSpeed(edk::physics2D::Joint2D* joint){
    //text the joint
    if(joint){
        //load the b2joint
        b2Joint *boxJoint = this->treeJoint.getJoint(joint);
        if(boxJoint){
            switch(boxJoint->GetType()){
            case e_revoluteJoint:
                //
            {
                b2RevoluteJoint* temp = (b2RevoluteJoint*)boxJoint;
                return temp->GetMotorSpeed();
            }
            default:
                break;
            }//end switch
        }
    }
    return 0.f;
}

//contact functions
void edk::physics2D::World2D::contact2DBegin(edk::physics2D::Contact2D*){
    /*
    printf("\nWorld2D Begin Position %.2f %.2f"
           ,contact->worldPositions[0u].x
           ,contact->worldPositions[0u].y
           );
*/
}
void edk::physics2D::World2D::contact2DEnd(edk::physics2D::Contact2D*){
    /*
    printf("\nWorld2D End Position %.2f %.2f"
           ,contact->worldPositions[0u].x
           ,contact->worldPositions[0u].y
           );
*/
}
void edk::physics2D::World2D::contact2DKeepBegin(edk::physics2D::Contact2D*){
    /*
    printf("\nWorld2D Begin Keep Position %.2f %.2f"
           ,contact->worldPositions[0u].x
           ,contact->worldPositions[0u].y
           );
*/
}
void edk::physics2D::World2D::contact2DKeepEnd(edk::physics2D::Contact2D*){
    /*
    printf("\nWorld2D End Keep Position %.2f %.2f"
           ,contact->worldPositions[0u].x
           ,contact->worldPositions[0u].y
           );
*/
}
//contact sensors
void edk::physics2D::World2D::sensor2DBegin(edk::physics2D::Contact2D* ){
    //
}
void edk::physics2D::World2D::sensor2DEnd(edk::physics2D::Contact2D* ){
    //
}
void edk::physics2D::World2D::sensor2DKeeping(edk::physics2D::Contact2D* ){
    //
}

//Add contactCallback
bool edk::physics2D::World2D::addContactCallback(edk::physics2D::ContactCallback2D* callback){
    //test the callback
    if(callback){
        //add the callback to the tree
        return this->treeCallbacks.add(callback);
    }
    return false;
}
bool edk::physics2D::World2D::removeContactCallback(edk::physics2D::ContactCallback2D* callback){
    //test the callback
    if(callback){
        //add the callback to the tree
        return this->treeCallbacks.remove(callback);
    }
    return false;
}

//XML
bool edk::physics2D::World2D::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"physWorld_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //WRITE
                        edk::physics2D::World2D::TreeObjectID treeIdStatic;
                        edk::physics2D::World2D::TreeObjectID treeIdDynamic;
                        edk::physics2D::World2D::TreeObjectID treeIdKinematic;
                        //save static objects
                        edk::uint32 size = 0u;
                        edk::physics2D::PhysicObject2D* object;
                        b2Body* body;
                        if(xml->addSelectedNextChild("static")){
                            if(xml->selectChild("static")){
                                size = this->treeStatic.size();
                                //save the objects
                                for(edk::uint32 i=0u;i<size;i++){
                                    body = this->treeStatic.getBodyInPosition(i);
                                    if(body){
                                        object = (edk::physics2D::PhysicObject2D*)body->GetUserData();
                                        if(object){
                                            object->writeToXML(xml,i,true);
                                            //add the if to the tree
                                            treeIdStatic.addObject(object,i);
                                        }
                                    }
                                }
                                xml->selectFather();
                            }
                        }
                        if(xml->addSelectedNextChild("dynamic")){
                            if(xml->selectChild("dynamic")){
                                size = this->treeDynamic.size();
                                //save the objects
                                for(edk::uint32 i=0u;i<size;i++){
                                    body = this->treeDynamic.getBodyInPosition(i);
                                    if(body){
                                        object = (edk::physics2D::PhysicObject2D*)body->GetUserData();
                                        if(object){
                                            object->writeToXML(xml,i,true);
                                            //add the if to the tree
                                            treeIdDynamic.addObject(object,i);
                                        }
                                    }
                                }
                                xml->selectFather();
                            }
                        }
                        if(xml->addSelectedNextChild("kinematic")){
                            if(xml->selectChild("kinematic")){
                                size = this->treeKinematic.size();
                                //save the objects
                                for(edk::uint32 i=0u;i<size;i++){
                                    body = this->treeKinematic.getBodyInPosition(i);
                                    if(body){
                                        object = (edk::physics2D::PhysicObject2D*)body->GetUserData();
                                        if(object){
                                            object->writeToXML(xml,i,true);
                                            //add the if to the tree
                                            treeIdKinematic.addObject(object,i);
                                        }
                                    }
                                }
                                xml->selectFather();
                            }
                        }
                        ret=true;
                        xml->selectFather();
                    }
                }
                delete[] name;
            }
            delete[] nameID;
        }
        return ret;
    }
    return false;
}
bool edk::physics2D::World2D::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"physWorld_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //READ
                    edk::physics2D::PhysicObject2D* object=NULL;
                    edk::uint32 i=0u;
                    if(xml->selectChild("static")){
                        do{
                            object = new edk::physics2D::PhysicObject2D;
                            if(object){
                                //read the object
                                if(object->readFromXML(xml,i)){
                                    //add the object
                                    if(!this->addObject(object)){
                                        //delete object
                                        delete object;
                                        object=NULL;
                                    }
                                }
                                else{
                                    //delete object
                                    delete object;
                                    object=NULL;
                                }
                            }
                        }while(object);
                        xml->selectFather();
                    }
                    if(xml->selectChild("dynamic")){
                        do{
                            object = new edk::physics2D::PhysicObject2D;
                            if(object){
                                //read the object
                                if(object->readFromXML(xml,i)){
                                    //add the object
                                    if(!this->addObject(object)){
                                        //delete object
                                        delete object;
                                        object=NULL;
                                    }
                                }
                                else{
                                    //delete object
                                    delete object;
                                    object=NULL;
                                }
                            }
                        }while(object);
                        xml->selectFather();
                    }
                    if(xml->selectChild("kimematic")){
                        do{
                            object = new edk::physics2D::PhysicObject2D;
                            if(object){
                                //read the object
                                if(object->readFromXML(xml,i)){
                                    //add the object
                                    if(!this->addObject(object)){
                                        //delete object
                                        delete object;
                                        object=NULL;
                                    }
                                }
                                else{
                                    //delete object
                                    delete object;
                                    object=NULL;
                                }
                            }
                        }while(object);
                        xml->selectFather();
                    }

                    ret=true;
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] nameID;
        }
        return ret;
    }
    return false;
}
