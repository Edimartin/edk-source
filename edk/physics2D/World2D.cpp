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
    this->world = NULL;edkEnd();
}
edk::physics2D::World2D::MyContactListener::MyContactListener(edk::physics2D::World2D* world){
    //
    this->world = world;edkEnd();
}
void edk::physics2D::World2D::MyContactListener::BeginContact(b2Contact* contact){
    /*
    printf("\nContact Begin %u"
           ,contact
           );edkEnd();
*/
    b2Body* bodyA = contact->GetFixtureA()->GetBody();edkEnd();
    b2Body* bodyB = contact->GetFixtureB()->GetBody();edkEnd();

    //test if have the One of the Bodys in treeRemove
    if(this->world->treeDeleted.haveElement(bodyA)
            ||
            this->world->treeDeleted.haveElement(bodyB)
            ){
        //disable the contact
        contact->SetEnabled(false);edkEnd();
        return;edkEnd();
    }

    edk::uint64 shapeA = (edk::uint64)contact->GetFixtureA()->GetUserData().pointer;edkEnd();
    edk::uint64 shapeB = (edk::uint64)contact->GetFixtureB()->GetUserData().pointer;edkEnd();
    edk::uint8 count = contact->GetManifold()->pointCount;edkEnd();
    if(count){
        //get the contact
        edk::physics2D::Contact2D* contactTemp = this->world->treeConcacts.getContact(contact);edkEnd();

        //test if the two objecs are on the same group
        edk::physics2D::PhysicObject2D* objectA = (edk::physics2D::PhysicObject2D*)bodyA->GetUserData().pointer;edkEnd();
        edk::physics2D::PhysicObject2D* objectB = (edk::physics2D::PhysicObject2D*)bodyB->GetUserData().pointer;edkEnd();

        bool thisContinue=true;edkEnd();
        if(objectA->getNotCollisionGroupSize() && objectB->getNotCollisionGroupSize()){
            //test if B have A group
            edk::uint32 size = objectA->getNotCollisionGroupSize();edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                if(objectB->haveNotCollisionGroup(objectA->getNotCollisionGroupInPosition(i))){
                    //then continue
                    thisContinue=false;edkEnd();
                    break;
                }
            }
        }
        if(objectA->getCollisionGroupSize() && objectB->getCollisionGroupSize()){
            thisContinue=false;edkEnd();
            //test if B have A group
            edk::uint32 size = objectA->getCollisionGroupSize();edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                if(objectB->haveCollisionGroup(objectA->getCollisionGroupInPosition(i))){
                    //then continue
                    thisContinue=true;edkEnd();
                    break;
                }
            }
        }
        if(thisContinue){
            if(!contactTemp){
                //create the new contact
                contactTemp = new edk::physics2D::Contact2D(contact);edkEnd();
                //add the contactTemp on the tree
                if(!this->world->treeConcacts.add(contactTemp)){
                    //delete contactTemp
                    delete contactTemp;edkEnd();
                    contactTemp=NULL;edkEnd();
                }
            }
            if(contactTemp){
                if(!contactTemp->isEnabled()){
                    contact->SetEnabled(false);edkEnd();
                    return;edkEnd();
                }
                //update the values
                contactTemp->objectA = (edk::physics2D::PhysicObject2D*)bodyA->GetUserData().pointer;edkEnd();
                contactTemp->objectB = (edk::physics2D::PhysicObject2D*)bodyB->GetUserData().pointer;edkEnd();
                contactTemp->shapeA = shapeA;edkEnd();
                contactTemp->shapeB = shapeB;edkEnd();
                //
                contactTemp->objectA->setLinearVelocity(bodyA->GetLinearVelocity().x * this->percentOut,bodyA->GetLinearVelocity().y * this->percentOut);edkEnd();
                contactTemp->objectA->setAngularVelocity(bodyA->GetAngularVelocity() * (180.f / b2_pi));edkEnd();
                contactTemp->objectB->setLinearVelocity(bodyB->GetLinearVelocity().x * this->percentOut,bodyB->GetLinearVelocity().y * this->percentOut);edkEnd();
                contactTemp->objectB->setAngularVelocity(bodyB->GetAngularVelocity() * (180.f / b2_pi));edkEnd();
                contactTemp->velocityA = contactTemp->objectA->getSpeed();edkEnd();
                contactTemp->velocityB = contactTemp->objectB->getSpeed();edkEnd();
                //
                contactTemp->worldPositions.createArray(count);edkEnd();
                contactTemp->objectAPositions.createArray(count);edkEnd();
                contactTemp->objectBPositions.createArray(count);edkEnd();
                contactTemp->impulses.createArray(count);edkEnd();
                contactTemp->points = count;edkEnd();

                //select the polygon
                contactTemp->objectA->physicMesh.selectPolygon(contactTemp->shapeA);edkEnd();
                contactTemp->objectB->physicMesh.selectPolygon(contactTemp->shapeB);edkEnd();

                //get the world manifold to get the points
                b2WorldManifold worldManifold;edkEnd();
                contact->GetWorldManifold(&worldManifold);edkEnd();
                b2Vec2 point;edkEnd();
                edk::vec2f32 vertex;edkEnd();
                for(edk::uint32 i=0u;i<count;i++){
                    //copy the point to the worldPosition

                    point = worldManifold.points[i];edkEnd();
                    contactTemp->worldPositions.set(i,edk::vec2f32(point.x * this->percentOut,point.y * this->percentOut));edkEnd();

                    //get objectA position
                    vertex = edk::Math::rotatePlus(contactTemp->worldPositions[i]-contactTemp->objectA->position,
                                                   contactTemp->objectA->angle * -1.f
                                                   );edkEnd();
                    if(contactTemp->objectA->size.width){
                        vertex.x/=contactTemp->objectA->size.width;edkEnd();
                    }
                    if(contactTemp->objectA->size.height){
                        vertex.y/=contactTemp->objectA->size.height;edkEnd();
                    }
                    contactTemp->objectAPositions.set(i,vertex);edkEnd();
                    //get objectB position
                    vertex = edk::Math::rotatePlus(contactTemp->worldPositions[i]-contactTemp->objectB->position,
                                                   contactTemp->objectB->angle * -1.f
                                                   );edkEnd();
                    if(contactTemp->objectB->size.width){
                        vertex.x/=contactTemp->objectB->size.width;edkEnd();
                    }
                    if(contactTemp->objectB->size.height){
                        vertex.y/=contactTemp->objectB->size.height;edkEnd();
                    }
                    contactTemp->objectBPositions.set(i,vertex);edkEnd();
                    contactTemp->impulses.set(i,0.f);edkEnd();
                }

                //test if the objectA is a sensor
                if(contactTemp->objectA->isSensor()){
                    //load the sensor
                    edk::physics2D::StaticSensor2D* sensor = (edk::physics2D::StaticSensor2D*)contactTemp->objectA;edkEnd();
                    //test if the sensor have objects
                    if(sensor->getActivateSize()){
                        //test if have the object in the sensor tree
                        if(sensor->haveActivateObject(contactTemp->objectB)){
                            //this->world->sensorBegin(contactTemp);edkEnd();
                            this->world->physicsSensorBegin(contactTemp);edkEnd();
                        }
                    }
                    else{
                        //test if the object is in the sensor
                        //this->world->sensorBegin(contactTemp);edkEnd();
                        this->world->physicsSensorBegin(contactTemp);edkEnd();
                    }
                }
                else if(contactTemp->objectB->isSensor()){
                    //load the sensor
                    edk::physics2D::StaticSensor2D* sensor = (edk::physics2D::StaticSensor2D*)contactTemp->objectB;edkEnd();
                    //test if the sensor have objects
                    if(sensor->getActivateSize()){
                        //test if have the object in the sensor tree
                        if(sensor->haveActivateObject(contactTemp->objectA)){
                            //this->world->sensorBegin(contactTemp);edkEnd();
                            this->world->physicsSensorBegin(contactTemp);edkEnd();
                        }
                    }
                    else{
                        //test if the object is in the sensor
                        //this->world->sensorBegin(contactTemp);edkEnd();
                        this->world->physicsSensorBegin(contactTemp);edkEnd();
                    }
                }
                //Test if the lineA collide in one side
                else if(contactTemp->objectA->physicMesh.selectedIsLine()){
                    if(!contactTemp->objectB->physicMesh.selectedIsLine()){
                        //just test if the object is up the contact
                        switch(contactTemp->objectA->physicMesh.selectedGetCollisionID()){
                        case edk::shape::collisionUP:
                            if(contactTemp->objectB->position.y>=contactTemp->worldPositions[0u].y){
                                this->world->physicsContactBegin(contactTemp);edkEnd();
                                if(!contactTemp->isEnabled()){
                                    contact->SetEnabled(false);edkEnd();
                                }
                            }
                            else{
                                if(this->world->treeConcacts.remove((contactTemp))){
                                    delete (contactTemp);edkEnd();
                                }
                            }
                            break;
                        case edk::shape::collisionDOWN:
                            if(contactTemp->objectB->position.y<contactTemp->worldPositions[0u].y){
                                this->world->physicsContactBegin(contactTemp);edkEnd();
                                if(!contactTemp->isEnabled()){
                                    contact->SetEnabled(false);edkEnd();
                                }
                            }
                            else{
                                if(this->world->treeConcacts.remove((contactTemp))){
                                    delete (contactTemp);edkEnd();
                                }
                            }
                            break;
                        default:
                            this->world->physicsContactBegin(contactTemp);edkEnd();
                            if(!contactTemp->isEnabled()){
                                contact->SetEnabled(false);edkEnd();
                            }
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
                                this->world->physicsContactBegin(contactTemp);edkEnd();
                                if(!contactTemp->isEnabled()){
                                    contact->SetEnabled(false);edkEnd();
                                }
                            }
                            else{
                                if(this->world->treeConcacts.remove((contactTemp))){
                                    delete (contactTemp);edkEnd();
                                }
                            }
                            break;
                        case edk::shape::collisionDOWN:
                            if(contactTemp->objectA->position.y<contactTemp->worldPositions[0u].y){
                                this->world->physicsContactBegin(contactTemp);edkEnd();
                                if(!contactTemp->isEnabled()){
                                    contact->SetEnabled(false);edkEnd();
                                }
                            }
                            else{
                                if(this->world->treeConcacts.remove((contactTemp))){
                                    delete (contactTemp);edkEnd();
                                }
                            }
                            break;
                        default:
                            this->world->physicsContactBegin(contactTemp);edkEnd();
                            if(!contactTemp->isEnabled()){
                                contact->SetEnabled(false);edkEnd();
                            }
                            break;
                        }
                    }
                }
                else{
                    //this->world->contactbegin(contactTemp);edkEnd();
                    this->world->physicsContactBegin(contactTemp);edkEnd();
                    if(!contactTemp->isEnabled()){
                        contact->SetEnabled(false);edkEnd();
                    }
                }
            }
        }
        else{
            if(contactTemp){
                if(this->world->treeConcacts.remove((contactTemp))){
                    delete (contactTemp);edkEnd();
                }
            }
        }
    }
}
void edk::physics2D::World2D::MyContactListener::EndContact(b2Contact* contact){
    /*
    printf("\nContact END %u"
           ,contact
           );edkEnd();
*/
    //find contact
    b2Body* bodyA = contact->GetFixtureA()->GetBody();edkEnd();
    b2Body* bodyB = contact->GetFixtureB()->GetBody();edkEnd();

    //test if have the One of the Bodys in treeRemove
    if(this->world->treeDeleted.haveElement(bodyA)
            ||
            this->world->treeDeleted.haveElement(bodyB)
            ){
        //disable the contact
        contact->SetEnabled(false);edkEnd();
        return;edkEnd();
    }

    edk::physics2D::Contact2D* contactTemp = this->world->treeConcacts.getContact(contact);edkEnd();
    if(contactTemp){
        contactTemp->objectA->setLinearVelocity(bodyA->GetLinearVelocity().x * this->percentOut,bodyA->GetLinearVelocity().y * this->percentOut);edkEnd();
        contactTemp->objectA->setAngularVelocity(bodyA->GetAngularVelocity() * (180.f / b2_pi));edkEnd();
        contactTemp->objectB->setLinearVelocity(bodyB->GetLinearVelocity().x * this->percentOut,bodyB->GetLinearVelocity().y * this->percentOut);edkEnd();
        contactTemp->objectB->setAngularVelocity(bodyB->GetAngularVelocity() * (180.f / b2_pi));edkEnd();
        contactTemp->velocityA = contactTemp->objectA->getSpeed();edkEnd();
        contactTemp->velocityB = contactTemp->objectB->getSpeed();edkEnd();
        //update the positions
        edk::uint8 count = contact->GetManifold()->pointCount;edkEnd();
        b2Vec2 point;edkEnd();
        edk::vec2f32 vertex;edkEnd();
        b2WorldManifold worldManifold;edkEnd();
        contact->GetWorldManifold(&worldManifold);edkEnd();

        for(edk::uint32 i=0u;i<count;i++){
            //copy the point to the worldPosition

            point = worldManifold.points[i];edkEnd();
            contactTemp->worldPositions.set(i,edk::vec2f32(point.x * this->percentOut,point.y * this->percentOut));edkEnd();

            //get objectA position
            vertex = edk::Math::rotatePlus(contactTemp->worldPositions[i]-contactTemp->objectA->position,
                                           contactTemp->objectA->angle * -1.f
                                           );edkEnd();
            if(contactTemp->objectA->size.width){
                vertex.x/=contactTemp->objectA->size.width;edkEnd();
            }
            if(contactTemp->objectA->size.height){
                vertex.y/=contactTemp->objectA->size.height;edkEnd();
            }
            contactTemp->objectAPositions.set(i,vertex);edkEnd();
            //get objectB position
            vertex = edk::Math::rotatePlus(contactTemp->worldPositions[i]-contactTemp->objectB->position,
                                           contactTemp->objectB->angle * -1.f
                                           );edkEnd();
            if(contactTemp->objectB->size.width){
                vertex.x/=contactTemp->objectB->size.width;edkEnd();
            }
            if(contactTemp->objectB->size.height){
                vertex.y/=contactTemp->objectB->size.height;edkEnd();
            }
            contactTemp->objectBPositions.set(i,vertex);edkEnd();
        }

        //process the contactEnd

        //test if the objectA is a sensor
        if(contactTemp->objectA->isSensor()){
            //load the sensor
            edk::physics2D::StaticSensor2D* sensor = (edk::physics2D::StaticSensor2D*)contactTemp->objectA;edkEnd();
            //test if the sensor have objects
            if(sensor->getActivateSize()){
                //test if have the object in the sensor tree
                if(sensor->haveActivateObject(contactTemp->objectB)){
                    //this->world->sensorEnd(contactTemp);edkEnd();
                    this->world->physicsSensorEnd(contactTemp);edkEnd();
                }
            }
            else{
                //test if the object is in the sensor
                //this->world->sensorEnd(contactTemp);edkEnd();
                this->world->physicsSensorEnd(contactTemp);edkEnd();
            }
        }
        else if(contactTemp->objectB->isSensor()){
            //load the sensor
            edk::physics2D::StaticSensor2D* sensor = (edk::physics2D::StaticSensor2D*)contactTemp->objectB;edkEnd();
            //test if the sensor have objects
            if(sensor->getActivateSize()){
                //test if have the object in the sensor tree
                if(sensor->haveActivateObject(contactTemp->objectA)){
                    //this->world->sensorEnd(contactTemp);edkEnd();
                    this->world->physicsSensorEnd(contactTemp);edkEnd();
                }
            }
            else{
                //test if the object is in the sensor
                //this->world->sensorEnd(contactTemp);edkEnd();
                this->world->physicsSensorEnd(contactTemp);edkEnd();
            }
        }
        else{
            //this->world->contactEnd(contactTemp);edkEnd();
            this->world->physicsContactEnd(contactTemp);edkEnd();
        }

        //remove contactTemp from the tree
        this->world->treeConcacts.remove(contactTemp);edkEnd();
        //delete contactTemp
        delete contactTemp;edkEnd();
    }
}
void edk::physics2D::World2D::MyContactListener::PreSolve(b2Contact* contact, const b2Manifold*){
    /*
    printf("\nContact PreSolve %u"
           ,contact
           );edkEnd();
*/
    //find contact
    b2Body* bodyA = contact->GetFixtureA()->GetBody();edkEnd();
    b2Body* bodyB = contact->GetFixtureB()->GetBody();edkEnd();

    //test if have the One of the Bodys in treeRemove
    if(this->world->treeDeleted.haveElement(bodyA)
            ||
            this->world->treeDeleted.haveElement(bodyB)
            ){
        //disable the contact
        contact->SetEnabled(false);edkEnd();
        return;edkEnd();
    }

    edk::physics2D::Contact2D* contactTemp = this->world->treeConcacts.getContact(contact);edkEnd();
    if(contactTemp){
        if(!contactTemp->isEnabled()){
            contact->SetEnabled(false);edkEnd();
            return;edkEnd();
        }
        contactTemp->objectA->setLinearVelocity(bodyA->GetLinearVelocity().x * this->percentOut,bodyA->GetLinearVelocity().y * this->percentOut);edkEnd();
        contactTemp->objectA->setAngularVelocity(bodyA->GetAngularVelocity() * (180.f / b2_pi));edkEnd();
        contactTemp->objectB->setLinearVelocity(bodyB->GetLinearVelocity().x * this->percentOut,bodyB->GetLinearVelocity().y * this->percentOut);edkEnd();
        contactTemp->objectB->setAngularVelocity(bodyB->GetAngularVelocity() * (180.f / b2_pi));edkEnd();
        contactTemp->velocityA = contactTemp->objectA->getSpeed();edkEnd();
        contactTemp->velocityB = contactTemp->objectB->getSpeed();edkEnd();
        //update the positions
        edk::uint8 count = contact->GetManifold()->pointCount;edkEnd();
        b2Vec2 point;edkEnd();
        edk::vec2f32 vertex;edkEnd();
        b2WorldManifold worldManifold;edkEnd();
        contact->GetWorldManifold(&worldManifold);edkEnd();
        for(edk::uint32 i=0u;i<count;i++){
            //copy the point to the worldPosition

            point = worldManifold.points[i];edkEnd();
            contactTemp->worldPositions.set(i,edk::vec2f32(point.x * this->percentOut,point.y * this->percentOut));edkEnd();

            //get objectA position
            vertex = edk::Math::rotatePlus(contactTemp->worldPositions[i]-contactTemp->objectA->position,
                                           contactTemp->objectA->angle * -1.f
                                           );edkEnd();
            if(contactTemp->objectA->size.width){
                vertex.x/=contactTemp->objectA->size.width;edkEnd();
            }
            if(contactTemp->objectA->size.height){
                vertex.y/=contactTemp->objectA->size.height;edkEnd();
            }
            contactTemp->objectAPositions.set(i,vertex);edkEnd();
            //get objectB position
            vertex = edk::Math::rotatePlus(contactTemp->worldPositions[i]-contactTemp->objectB->position,
                                           contactTemp->objectB->angle * -1.f
                                           );edkEnd();
            if(contactTemp->objectB->size.width){
                vertex.x/=contactTemp->objectB->size.width;edkEnd();
            }
            if(contactTemp->objectB->size.height){
                vertex.y/=contactTemp->objectB->size.height;edkEnd();
            }
            contactTemp->objectBPositions.set(i,vertex);edkEnd();
        }


        if(contactTemp->isEnabled()){
            //test if the objectA is a sensor
            if(contactTemp->objectA->isSensor()){
                //load the sensor
                edk::physics2D::StaticSensor2D* sensor = (edk::physics2D::StaticSensor2D*)contactTemp->objectA;edkEnd();
                //test if the sensor have objects
                if(sensor->getActivateSize()){
                    //test if have the object in the sensor tree
                    if(sensor->haveActivateObject(contactTemp->objectB)){
                        //this->world->sensorKeeping(contactTemp);edkEnd();
                        this->world->physicsSensorKeeping(contactTemp);edkEnd();
                    }
                }
                else{
                    //test if the object is in the sensor
                    //this->world->sensorKeeping(contactTemp);edkEnd();
                    this->world->physicsSensorKeeping(contactTemp);edkEnd();
                }
                contact->SetEnabled(false);edkEnd();
            }
            else if(contactTemp->objectB->isSensor()){
                //load the sensor
                edk::physics2D::StaticSensor2D* sensor = (edk::physics2D::StaticSensor2D*)contactTemp->objectB;edkEnd();
                //test if the sensor have objects
                if(sensor->getActivateSize()){
                    //test if have the object in the sensor tree
                    if(sensor->haveActivateObject(contactTemp->objectA)){
                        //this->world->sensorKeeping(contactTemp);edkEnd();
                        this->world->physicsSensorKeeping(contactTemp);edkEnd();
                    }
                }
                else{
                    //test if the object is in the sensor
                    //this->world->sensorKeeping(contactTemp);edkEnd();
                    this->world->physicsSensorKeeping(contactTemp);edkEnd();
                }
                contact->SetEnabled(false);edkEnd();
            }
            else{
                //this->world->contactKeepBegin(contactTemp);edkEnd();
                this->world->physicsContactKeepBegin(contactTemp);edkEnd();
                if(!contactTemp->isEnabled()){
                    contact->SetEnabled(false);edkEnd();
                }
            }
        }
        else{
            contact->SetEnabled(false);edkEnd();
        }
    }
    else{
        contact->SetEnabled(false);edkEnd();
    }
}
void edk::physics2D::World2D::MyContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse){
    /*
    printf("\nContact PostSolve impulses %u tangent %.2f normal %.2f"
           ,impulse->count
           ,impulse->tangentImpulses[0u]
           ,impulse->normalImpulses[0u]
           );edkEnd();
*/
    //find contact
    b2Body* bodyA = contact->GetFixtureA()->GetBody();edkEnd();
    b2Body* bodyB = contact->GetFixtureB()->GetBody();edkEnd();

    //test if have the One of the Bodys in treeRemove
    if(this->world->treeDeleted.haveElement(bodyA)
            ||
            this->world->treeDeleted.haveElement(bodyB)
            ){
        //disable the contact
        contact->SetEnabled(false);edkEnd();
        return;edkEnd();
    }

    edk::physics2D::Contact2D* contactTemp = this->world->treeConcacts.getContact(contact);edkEnd();
    if(contactTemp){
        contactTemp->objectA->setLinearVelocity(bodyA->GetLinearVelocity().x * this->percentOut,bodyA->GetLinearVelocity().y * this->percentOut);edkEnd();
        contactTemp->objectA->setAngularVelocity(bodyA->GetAngularVelocity() * (180.f / b2_pi));edkEnd();
        contactTemp->objectB->setLinearVelocity(bodyB->GetLinearVelocity().x * this->percentOut,bodyB->GetLinearVelocity().y * this->percentOut);edkEnd();
        contactTemp->objectB->setAngularVelocity(bodyB->GetAngularVelocity() * (180.f / b2_pi));edkEnd();
        contactTemp->velocityA = contactTemp->objectA->getSpeed();edkEnd();
        contactTemp->velocityB = contactTemp->objectB->getSpeed();edkEnd();
        //update the positions
        edk::uint8 count = contact->GetManifold()->pointCount;edkEnd();
        b2Vec2 point;edkEnd();
        edk::vec2f32 vertex;edkEnd();
        b2WorldManifold worldManifold;edkEnd();
        contact->GetWorldManifold(&worldManifold);edkEnd();

        for(edk::uint32 i=0u;i<count;i++){
            //copy the point to the worldPosition

            point = worldManifold.points[i];edkEnd();
            contactTemp->worldPositions.set(i,edk::vec2f32(point.x * this->percentOut,point.y * this->percentOut));edkEnd();

            //get objectA position
            vertex = edk::Math::rotatePlus(contactTemp->worldPositions[i]-contactTemp->objectA->position,
                                           contactTemp->objectA->angle * -1.f
                                           );edkEnd();
            if(contactTemp->objectA->size.width){
                vertex.x/=contactTemp->objectA->size.width;edkEnd();
            }
            if(contactTemp->objectA->size.height){
                vertex.y/=contactTemp->objectA->size.height;edkEnd();
            }
            contactTemp->objectAPositions.set(i,vertex);edkEnd();
            //get objectB position
            vertex = edk::Math::rotatePlus(contactTemp->worldPositions[i]-contactTemp->objectB->position,
                                           contactTemp->objectB->angle * -1.f
                                           );edkEnd();
            if(contactTemp->objectB->size.width){
                vertex.x/=contactTemp->objectB->size.width;edkEnd();
            }
            if(contactTemp->objectB->size.height){
                vertex.y/=contactTemp->objectB->size.height;edkEnd();
            }
            contactTemp->objectBPositions.set(i,vertex);edkEnd();
        }

        //Update impulsess
        for(edk::uint32 i=0u;i<count;i++){
            contactTemp->impulses.set(i,impulse->normalImpulses[i]);edkEnd();
        }
        count = impulse->count;edkEnd();


        if(contactTemp->isEnabled()){
            //test if the objectA is a sensor
            if(!contactTemp->objectA->isSensor()
                    &&
                    !contactTemp->objectB->isSensor()){
                //this->world->contactKeepEnd(contactTemp);edkEnd();
                this->world->physicsContactKeepEnd(contactTemp);edkEnd();
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
            return this->add(joint);edkEnd();
        }
    }
    return false;
}
//return the joint in the position
edk::physics2D::Joint2D* edk::physics2D::World2D::ObjectJointsTree::getJointInPosition(edk::uint32 position){
    return this->getElementInPosition(position);edkEnd();
}

//return the size of the joint
edk::uint32 edk::physics2D::World2D::ObjectJointsTree::getSize(){
    return this->size();edkEnd();
}

//remove joint
bool edk::physics2D::World2D::ObjectJointsTree::removeJoint(edk::physics2D::Joint2D* joint){
    return this->remove(joint);edkEnd();
}
//remove joint in position
bool edk::physics2D::World2D::ObjectJointsTree::removeJointInPosition(edk::uint32 position){
    return this->remove(this->getJointInPosition(position));edkEnd();
}

//clean the joints
void edk::physics2D::World2D::ObjectJointsTree::cleanJoints(){
    this->clean();edkEnd();
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
            return this->add(joint);edkEnd();
        }
    }
    return false;
}
//return the joint
edk::physics2D::World2D::ObjectJointsTree* edk::physics2D::World2D::ObjectsJointsTree::getJoint(edk::physics2D::PhysicObject2D* object){
    //create the find joint
    edk::physics2D::World2D::ObjectJointsTree find(object,pointer);edkEnd();
    /*
    find.objectA = object;edkEnd();
    find.objectB = pointer;edkEnd();
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
    edk::physics2D::World2D::ObjectJointsTree find(object,pointer);edkEnd();
    /*
    find.objectA = object;edkEnd();
    find.objectB = pointer;edkEnd();
    */
    return this->remove(&find);
}

bool edk::physics2D::World2D::ObjectsJointsTree::removeJoint(edk::physics2D::World2D::ObjectJointsTree* joint){
    return this->remove(joint);
}
//clean the joints
void edk::physics2D::World2D::ObjectsJointsTree::cleanJoints(){
    this->clean();edkEnd();
}

//return the pointer
edk::physics2D::PhysicObject2D* edk::physics2D::World2D::ObjectsJointsTree::getPointer(){
    return this->pointer;edkEnd();
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
    : world(b2Vec2(0,0)),contacts(this),treeDeleted(&this->world),
      treeNew(this),treeLinearVelocity(this),treeAngularVelocity(this){
    this->setMeterDistance(1.f);edkEnd();
    //set the initial gravity
    this->setGravity(edk::vec2f32(0.f,-9.8f));edkEnd();
    this->world.SetContactListener(&this->contacts);edkEnd();

    this->clockStart();edkEnd();
    this->clockScale=1.f;edkEnd();

    this->runNextStep=false;edkEnd();
    this->paused=false;edkEnd();
}
edk::physics2D::World2D::~World2D(){
    //
    edk::uint32 size = 0u;edkEnd();
    b2Body* body=NULL;edkEnd();

    this->beginContacs.clean();edkEnd();
    this->keepBeginContacs.clean();edkEnd();
    this->keepEndContacs.clean();edkEnd();
    this->endContacs.clean();edkEnd();
    this->sensorBeginContacs.clean();edkEnd();
    this->sensorKeepContacs.clean();edkEnd();
    this->sensorEndContacs.clean();edkEnd();

    this->treeCallbacks.clean();edkEnd();

    //destroy treeContacts
    size = this->treeConcacts.getSize();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        edk::physics2D::Contact2D* temp = this->treeConcacts.getElementInPosition(i);edkEnd();
        if(temp){
            delete temp;edkEnd();
        }
    }
    this->treeConcacts.clean();edkEnd();

    //destroy objectJoints
    size = this->treeJointObjects.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        //load the tree
        edk::physics2D::World2D::ObjectsJointsTree* treeTemp = this->treeJointObjects.getElementInPosition(i);edkEnd();
        if(treeTemp){
            edk::physics2D::World2D::ObjectJointsTree* treeTemps = treeTemp->getJointInPosition(i);edkEnd();
            if(treeTemps){
                treeTemp->cleanJoints();edkEnd();
                delete treeTemps;edkEnd();
            }
            treeTemp->cleanJoints();edkEnd();
            delete treeTemp;edkEnd();
        }
    }
    this->treeJointObjects.clean();edkEnd();
    //destroy joints
    size = this->treeJoint.size();edkEnd();
    b2Joint *joint;edkEnd();
    edk::physics2D::Joint2D* edkJoint;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        joint = this->treeJoint.getB2JointInPosition(i);edkEnd();
        if(joint){
            edkJoint = (edk::physics2D::Joint2D*)joint->GetUserData().pointer;edkEnd();
            this->world.DestroyJoint(joint);edkEnd();
            if(edkJoint){
                delete edkJoint;edkEnd();
            }
        }
    }
    this->treeJoint.clean();edkEnd();

    //destroy static
    size = this->treeStatic.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        body = this->treeStatic.getBodyInPosition(i);edkEnd();
        if(body){
            if(this->runNextStep){
                //save the object on the deleted tree
                body->GetUserData().pointer = 0;
                this->treeDeleted.add(body);edkEnd();
            }
            else{
                this->world.DestroyBody(body);edkEnd();
            }
        }
    }
    this->treeStatic.clean();edkEnd();
    //destroy kinematic
    size = this->treeKinematic.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        body = this->treeKinematic.getBodyInPosition(i);edkEnd();
        if(body){
            if(this->runNextStep){
                //save the object on the deleted tree
                body->GetUserData().pointer = 0;
                this->treeDeleted.add(body);edkEnd();
            }
            else{
                this->world.DestroyBody(body);edkEnd();
            }
        }
    }
    this->treeKinematic.clean();edkEnd();
    //destroy dynamic
    size = this->treeDynamic.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        body = this->treeDynamic.getBodyInPosition(i);edkEnd();
        if(body){
            if(this->runNextStep){
                //save the object on the deleted tree
                body->GetUserData().pointer = 0;
                this->treeDeleted.add(body);edkEnd();
            }
            else{
                this->world.DestroyBody(body);edkEnd();
            }
        }
    }
    this->treeDynamic.clean();edkEnd();
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
    edk::vec2f32 ret;edkEnd();
    //translate
    ret  = worldPosition - object->position;edkEnd();
    //and rotate the worldPosition
    if(object->angle){
        ret = edk::Math::rotate2f(ret,object->angle * -1);edkEnd();
    }
    return ret;
}
//return the joint position in the world
edk::vec2f32 edk::physics2D::World2D::getJointWorldPosition(edk::physics2D::PhysicObject2D* object,edk::vec2f32 jointPosition){
    edk::vec2f32 ret;edkEnd();
    //and rotate the worldPosition
    if(object->angle){
        //rotate
        ret = edk::Math::rotate2f(jointPosition,object->angle);edkEnd();
        //translate
        ret+=object->position;edkEnd();
    }
    else{
        //translate
        ret = jointPosition + object->position;edkEnd();
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
        edk::physics2D::World2D::ObjectsJointsTree* treeA = this->treeJointObjects.getTreeJoint(objectA);edkEnd();

        //test if dont have the object
        if(!treeA){
            //else create a new treeA
            treeA = new edk::physics2D::World2D::ObjectsJointsTree(objectA);edkEnd();
            if(treeA){
                //add the treeA in the tree
                if(!this->treeJointObjects.add(treeA)){
                    //else delete treeA
                    delete treeA;edkEnd();
                    treeA=NULL;edkEnd();
                }
            }
        }
        //now test if have the object
        if(treeA){
            //load the second objectTREE
            edk::physics2D::World2D::ObjectsJointsTree* treeB = this->treeJointObjects.getTreeJoint(objectB);edkEnd();
            //test if dont have the object
            if(!treeB){
                //else create a new treeB
                treeB = new edk::physics2D::World2D::ObjectsJointsTree(objectB);edkEnd();
                if(treeB){
                    //add the treeB in the tree
                    if(!this->treeJointObjects.add(treeB)){
                        //else delete treeB
                        delete treeB;edkEnd();
                        treeB=NULL;edkEnd();
                    }
                }
            }
            //now test if have the object
            if(treeB){



                //load the treeAB
                edk::physics2D::World2D::ObjectJointsTree* treeAB = treeA->getJoint(objectB);edkEnd();
                //test if load the tree
                if(!treeAB){
                    //create the new tree
                    treeAB = new edk::physics2D::World2D::ObjectJointsTree(objectA,objectB);edkEnd();
                    if(treeAB){
                        if(!treeA->addJoint(treeAB)){
                            delete treeAB;edkEnd();
                            treeAB=NULL;edkEnd();
                        }
                    }
                }
                if(treeAB){
                    //load the treeBA
                    edk::physics2D::World2D::ObjectJointsTree* treeBA = treeB->getJoint(objectA);edkEnd();
                    //test if load the tree
                    if(!treeBA){
                        //create the new tree
                        treeBA = new edk::physics2D::World2D::ObjectJointsTree(objectB,objectA);edkEnd();
                        if(treeBA){
                            if(!treeB->addJoint(treeBA)){
                                delete treeBA;edkEnd();
                                treeBA=NULL;edkEnd();
                            }
                        }
                    }
                    if(treeBA){


                        //create the joint
                        edk::physics2D::Joint2D* joint = new edk::physics2D::Joint2D;edkEnd();
                        if(joint){
                            //set the objects
                            joint->objectA = objectA;edkEnd();
                            joint->objectB = objectB;edkEnd();

                            //add the joint in the two trees
                            if(treeAB->addJoint(joint)){
                                //
                                if(treeBA->addJoint(joint)
                                        ||
                                        treeBA == treeAB){
                                    //get WorldPosition
                                    joint->positionA = positionA;edkEnd();
                                    joint->worldPositionA
                                            =
                                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
                                            ;edkEnd();
                                    joint->positionB = positionB;edkEnd();
                                    /*
                                    joint->worldPositionB
                                            =
                                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectB,positionB)
                                            ;edkEnd();
*/

                                    //return the joint
                                    return joint;edkEnd();
                                }

                                //remove the joint
                                treeAB->removeJoint(joint);edkEnd();
                            }


                            //delete the joint
                            delete joint;edkEnd();
                            joint=NULL;edkEnd();
                        }



                        //delete the treeBA
                        if(!treeBA->getSize()){
                            //remove from the tree
                            treeA->removeJoint(treeBA);edkEnd();
                            delete treeBA;edkEnd();
                        }
                    }



                    //delete the treeAB
                    if(!treeAB->getSize()){
                        //remove from the tree
                        treeA->removeJoint(treeAB);edkEnd();
                        delete treeAB;edkEnd();
                    }
                }



                //test if the treeB have size zero
                if(!treeB->getSize()){
                    //then remove and delete treeB
                    this->treeJointObjects.remove(treeB);edkEnd();
                    delete treeB;edkEnd();
                }
            }


            //test if the treeOA have size zero
            if(!treeA->getSize()){
                //then remove and delete treeA
                this->treeJointObjects.remove(treeA);edkEnd();
                delete treeA;edkEnd();
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
            edk::physics2D::World2D::ObjectsJointsTree* treeA = this->treeJointObjects.getTreeJoint(joint->objectA);edkEnd();

            //test if dont have the object
            if(!treeA){
                //else create a new treeA
                treeA = new edk::physics2D::World2D::ObjectsJointsTree(joint->objectA);edkEnd();
                if(treeA){
                    //add the treeA in the tree
                    if(!this->treeJointObjects.add(treeA)){
                        //else delete treeA
                        delete treeA;edkEnd();
                        treeA=NULL;edkEnd();
                    }
                }
            }
            //now test if have the object
            if(treeA){
                //load the second objectTREE
                edk::physics2D::World2D::ObjectsJointsTree* treeB = this->treeJointObjects.getTreeJoint(joint->objectB);edkEnd();
                //test if dont have the object
                if(!treeB){
                    //else create a new treeB
                    treeB = new edk::physics2D::World2D::ObjectsJointsTree(joint->objectB);edkEnd();
                    if(treeB){
                        //add the treeB in the tree
                        if(!this->treeJointObjects.add(treeB)){
                            //else delete treeB
                            delete treeB;edkEnd();
                            treeB=NULL;edkEnd();
                        }
                    }
                }
                //now test if have the object
                if(treeB){



                    //load the treeAB
                    edk::physics2D::World2D::ObjectJointsTree* treeAB = treeA->getJoint(joint->objectB);edkEnd();
                    //test if load the tree
                    if(!treeAB){
                        //create the new tree
                        treeAB = new edk::physics2D::World2D::ObjectJointsTree(joint->objectA,joint->objectB);edkEnd();
                        if(treeAB){
                            if(!treeA->addJoint(treeAB)){
                                delete treeAB;edkEnd();
                                treeAB=NULL;edkEnd();
                            }
                        }
                    }
                    if(treeAB){
                        //load the treeBA
                        edk::physics2D::World2D::ObjectJointsTree* treeBA = treeB->getJoint(joint->objectA);edkEnd();
                        //test if load the tree
                        if(!treeBA){
                            //create the new tree
                            treeBA = new edk::physics2D::World2D::ObjectJointsTree(joint->objectB,joint->objectA);edkEnd();
                            if(treeBA){
                                if(!treeB->addJoint(treeBA)){
                                    delete treeBA;edkEnd();
                                    treeBA=NULL;edkEnd();
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
                                treeAB->removeJoint(joint);edkEnd();


                                //delete the joint
                                delete joint;edkEnd();
                                joint=NULL;edkEnd();
                            }



                            //delete the treeBA
                            if(!treeBA->getSize()){
                                //remove from the tree
                                treeA->removeJoint(treeBA);edkEnd();
                                delete treeBA;edkEnd();
                            }
                        }



                        //delete the treeAB
                        if(!treeAB->getSize()){
                            //remove from the tree
                            treeA->removeJoint(treeAB);edkEnd();
                            delete treeAB;edkEnd();
                        }
                    }



                    //test if the treeB have size zero
                    if(!treeB->getSize()){
                        //then remove and delete treeB
                        this->treeJointObjects.remove(treeB);edkEnd();
                        delete treeB;edkEnd();
                    }
                }


                //test if the treeOA have size zero
                if(!treeA->getSize()){
                    //then remove and delete treeA
                    this->treeJointObjects.remove(treeA);edkEnd();
                    delete treeA;edkEnd();
                }
            }
        }
    }
    return false;
}

//remove joint
bool edk::physics2D::World2D::removeObjectJoints(edk::physics2D::PhysicObject2D* object){
    if(object){
        edk::physics2D::World2D::ObjectsJointsTree* objectsJointsATemp = this->treeJointObjects.getTreeJoint(object);edkEnd();
        if(objectsJointsATemp){
            //
            edk::uint32 size = objectsJointsATemp->getSize();edkEnd();
            edk::uint32 sizeJ = 0u;edkEnd();
            edk::physics2D::Joint2D* joint = NULL;edkEnd();
            b2Joint* boxJoint = NULL;edkEnd();
            edk::physics2D::World2D::ObjectsJointsTree* objectsJointsBTemp=NULL;edkEnd();
            edk::physics2D::World2D::ObjectJointsTree* objectJointsATemp=NULL;edkEnd();
            edk::physics2D::World2D::ObjectJointsTree* objectJointsBTemp=NULL;edkEnd();
            //objectTemp
            edk::physics2D::PhysicObject2D* objectTemp=NULL;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){

                //load the tree of the joint
                objectJointsATemp = objectsJointsATemp->getJointInPosition(i);edkEnd();
                if(objectJointsATemp){
                    //delete joint in the other object
                    if(object!=objectJointsATemp->getPointerA()){
                        objectTemp=objectJointsATemp->getPointerA();edkEnd();
                    }
                    else{
                        if(object!=objectJointsATemp->getPointerB()){
                            objectTemp=objectJointsATemp->getPointerB();edkEnd();
                        }
                    }
                    if(objectTemp){
                        //find the object
                        objectsJointsBTemp = this->treeJointObjects.getTreeJoint(objectTemp);edkEnd();
                        if(objectsJointsBTemp){
                            //load the tree with the two objects
                            objectJointsBTemp = objectsJointsBTemp->getJoint(object);edkEnd();
                            if(objectJointsBTemp){
                                //
                                sizeJ = objectJointsBTemp->getSize();edkEnd();
                                for(edk::uint32 j=0u;j<sizeJ;j++){
                                    //load the joints
                                    joint = objectJointsBTemp->getJointInPosition(j);edkEnd();
                                    if(joint){
                                        //objectJointsBTemp->removeJoint(joint);edkEnd();

                                        //remove joint from box2D
                                        boxJoint = this->treeJoint.getJoint(joint);edkEnd();
                                        if(boxJoint){
                                            this->treeJoint.removeJoint(boxJoint);edkEnd();
                                            //destroy the joint
                                            this->world.DestroyJoint(boxJoint);edkEnd();
                                            boxJoint=NULL;edkEnd();
                                        }

                                        //delete joint;edkEnd();
                                        joint=NULL;edkEnd();
                                    }
                                }
                                sizeJ=0u;


                                //remove the objectJoints from the tree
                                objectsJointsBTemp->removeJoint(objectJointsBTemp);edkEnd();
                                //delete
                                objectJointsBTemp->cleanJoints();edkEnd();
                                delete objectJointsBTemp;edkEnd();
                                objectJointsBTemp = NULL;edkEnd();
                            }

                        }
                    }

                    //
                    sizeJ = objectJointsATemp->getSize();edkEnd();
                    for(edk::uint32 j=0u;j<sizeJ;j++){
                        //load the joints
                        joint = objectJointsATemp->getJointInPosition(j);edkEnd();
                        if(joint){
                            //objectJointsATemp->removeJoint(joint);edkEnd();
                            //remove joint from box2D

                            boxJoint = this->treeJoint.getJoint(joint);edkEnd();
                            if(boxJoint){
                                this->treeJoint.removeJoint(boxJoint);edkEnd();
                                //destroy the joint
                                this->world.DestroyJoint(boxJoint);edkEnd();
                                boxJoint=NULL;edkEnd();
                            }

                            delete joint;edkEnd();
                            joint=NULL;edkEnd();
                        }
                    }
                    sizeJ=0u;

                    //objectsJointsATemp->removeJoint(objectJointsATemp);edkEnd();
                    //delete objectJointsTemp
                    objectJointsATemp->cleanJoints();edkEnd();
                    delete objectJointsATemp;edkEnd();
                    objectJointsATemp = NULL;edkEnd();
                }
            }

            objectsJointsATemp->cleanJoints();edkEnd();

            //remove the treeJoints
            this->treeJointObjects.remove(objectsJointsATemp);edkEnd();

            return true;
        }
    }
    return false;
}

//contact functions
void edk::physics2D::World2D::physicsContactBegin(edk::physics2D::Contact2D* contact){
    //test if have this objects in the tree
    if(!this->beginContacs.haveElement(contact->objectA,contact->objectB)){
        //add the new contact into the tree
        this->beginContacs.add(contact->objectA,contact->objectB);edkEnd();
    }
    else{
        //else set the contact to aready have it
        contact->areadyContacted=true;edkEnd();
    }

    this->contact2DBegin(contact);edkEnd();
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->contact2DBegin(contact);edkEnd();
    }
}
void edk::physics2D::World2D::physicsContactEnd(edk::physics2D::Contact2D* contact){
    //test if have this objects in the tree
    if(!this->endContacs.haveElement(contact->objectA,contact->objectB)){
        //add the new contact into the tree
        this->endContacs.add(contact->objectA,contact->objectB);edkEnd();
    }
    else{
        //else set the contact to aready have it
        contact->areadyContacted=true;edkEnd();
    }

    this->contact2DEnd(contact);edkEnd();
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->contact2DEnd(contact);edkEnd();
    }
}
void edk::physics2D::World2D::physicsContactKeepBegin(edk::physics2D::Contact2D* contact){
    //test if have this objects in the tree
    if(!this->keepBeginContacs.haveElement(contact->objectA,contact->objectB)){
        //add the new contact into the tree
        this->keepBeginContacs.add(contact->objectA,contact->objectB);edkEnd();
    }
    else{
        //else set the contact to aready have it
        contact->areadyContacted=true;edkEnd();
    }

    this->contact2DKeepBegin(contact);edkEnd();
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->contact2DKeepBegin(contact);edkEnd();
    }
}
void edk::physics2D::World2D::physicsContactKeepEnd(edk::physics2D::Contact2D* contact){
    //test if have this objects in the tree
    if(!this->keepEndContacs.haveElement(contact->objectA,contact->objectB)){
        //add the new contact into the tree
        this->keepEndContacs.add(contact->objectA,contact->objectB);edkEnd();
    }
    else{
        //else set the contact to aready have it
        contact->areadyContacted=true;edkEnd();
    }

    this->contact2DKeepEnd(contact);edkEnd();
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->contact2DKeepEnd(contact);edkEnd();
    }
}
//contact sensors
void edk::physics2D::World2D::physicsSensorBegin(edk::physics2D::Contact2D* contact){
    //test if have this objects in the tree
    if(!this->sensorBeginContacs.haveElement(contact->objectA,contact->objectB)){
        //add the new contact into the tree
        this->sensorBeginContacs.add(contact->objectA,contact->objectB);edkEnd();
    }
    else{
        //else set the contact to aready have it
        contact->areadyContacted=true;edkEnd();
    }

    this->sensor2DBegin(contact);edkEnd();
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->sensor2DBegin(contact);edkEnd();
    }
}
void edk::physics2D::World2D::physicsSensorEnd(edk::physics2D::Contact2D* contact){
    //test if have this objects in the tree
    if(!this->sensorEndContacs.haveElement(contact->objectA,contact->objectB)){
        //add the new contact into the tree
        this->sensorEndContacs.add(contact->objectA,contact->objectB);edkEnd();
    }
    else{
        //else set the contact to aready have it
        contact->areadyContacted=true;edkEnd();
    }

    this->sensor2DEnd(contact);edkEnd();
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->sensor2DEnd(contact);edkEnd();
    }
}
void edk::physics2D::World2D::physicsSensorKeeping(edk::physics2D::Contact2D* contact){
    //test if have this objects in the tree
    if(!this->sensorKeepContacs.haveElement(contact->objectA,contact->objectB)){
        //add the new contact into the tree
        this->sensorKeepContacs.add(contact->objectA,contact->objectB);edkEnd();
    }
    else{
        //else set the contact to aready have it
        contact->areadyContacted=true;edkEnd();
    }

    this->sensor2DKeeping(contact);edkEnd();
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->sensor2DKeeping(contact);edkEnd();
    }
}

//Set the gravity
void edk::physics2D::World2D::setGravity(edk::vec2f32 gravity){
    this->gravity=gravity * this->percentIn;edkEnd();
    //update the world gravity
    this->world.SetGravity(b2Vec2(this->gravity.x,this->gravity.y));edkEnd();
}
void edk::physics2D::World2D::setGravity(edk::float32 x,edk::float32 y){
    this->setGravity(edk::vec2f32 (x,y));edkEnd();
}
//set the percent
void edk::physics2D::World2D::setMeterDistance(edk::float32 meter){
    //
    this->percentOut = meter;edkEnd();
    this->percentIn = 1/this->percentOut;edkEnd();

    //update the tree's
    this->contacts.percentIn = this->percentIn;edkEnd();
    this->contacts.percentOut = this->percentOut;edkEnd();
    treeStatic.percentIn = this->percentIn;edkEnd();
    treeStatic.percentOut = this->percentOut;edkEnd();
    treeKinematic.percentIn = this->percentIn;edkEnd();
    treeKinematic.percentOut = this->percentOut;edkEnd();
    treeDynamic.percentIn = this->percentIn;edkEnd();
    treeDynamic.percentOut = this->percentOut;edkEnd();
}
void edk::physics2D::World2D::setMeterDistance(edk::uint8 meter){
    return this->setMeterDistance((edk::float32)meter);edkEnd();
}
void edk::physics2D::World2D::setMeterDistance(edk::uint16 meter){
    return this->setMeterDistance((edk::float32)meter);edkEnd();
}
void edk::physics2D::World2D::setMeterDistance(edk::uint32 meter){
    return this->setMeterDistance((edk::float32)meter);edkEnd();
}
void edk::physics2D::World2D::setMeterDistance(edk::uint64 meter){
    return this->setMeterDistance((edk::float32)meter);edkEnd();
}
edk::float32 edk::physics2D::World2D::getMeterDistance(){
    return this->percentOut;edkEnd();
}

//Add a Object to the world
bool edk::physics2D::World2D::addObject(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        bool ret=true;edkEnd();

        //test if is running the simulation
        if(this->runNextStep){
            //then add the object in to a tree to be added after the nextStep
            this->treeNew.add(object);edkEnd();
            return ret;
        }

        //create the box2D object
        b2BodyDef objectDef;edkEnd();
        /*
        objectDef.angle = object->angle / (180.f / b2_pi);edkEnd();
        objectDef.position = b2Vec2(object->position.x,object->position.y);edkEnd();
        */

        objectDef.type = (b2BodyType)object->getType();edkEnd();
        objectDef.fixedRotation=object->fixedRotation;edkEnd();

        //In the new version of box2D the userData will be setted in objectDef
        objectDef.userData.pointer = (uintptr_t)object;edkEnd();

        //objectDef.fixedRotation = false;edkEnd();

        b2Body* objectBody = this->world.CreateBody(&objectDef);edkEnd();
        if(objectBody){
            objectBody->SetTransform( b2Vec2(object->position.x*this->percentIn,object->position.y*this->percentIn),object->angle / (180.f / b2_pi) );edkEnd();


            //objectBody->SetUserData(object);edkEnd();
            //update the set user data in bodyDef for the new box2D version
            //read the polygons
            edk::uint32 size = object->physicMesh.getPolygonSize();edkEnd();
            if(size){
                b2Vec2 vertexs[b2_maxPolygonVertices];edkEnd();
                ret=false;edkEnd();
#if _WIN64 || __x86_64__ || __ppc64__
                for(register edk::uint64 i=0u;i<size;i++){
#else
                for(register edk::uint32 i=0u;i<size;i++){
#endif
                    //select the polygon
                    if(object->physicMesh.selectPolygon(i)){
                        edk::size2f32 scale = object->physicMesh.selectedGetScale() * object->size * this->percentIn;edkEnd();
                        edk::vec2f32 translate /*= object->physicMesh.selectedGetTranslate() * object->physicMesh.selectedGetScale()*/;edkEnd();
                        translate.x = object->physicMesh.selectedGetTranslate().x * object->size.width * this->percentIn;edkEnd();
                        translate.y = object->physicMesh.selectedGetTranslate().y * object->size.height * this->percentIn;edkEnd();
                        //translate.x = object->physicMesh.selectedGetTranslate().x * object->physicMesh.selectedGetScale().width;edkEnd();
                        //translate.y = object->physicMesh.selectedGetTranslate().y * object->physicMesh.selectedGetScale().height;edkEnd();
                        for(edk::uint32 i=0u;i<b2_maxPolygonVertices;i++){
                            vertexs[i].x=0.f;edkEnd();
                            vertexs[i].y=0.f;edkEnd();
                        }
                        //printf("\nVertex Count %u",object->physicMesh.selectedGetVertexCount());edkEnd();
                        //test if the polygon is a circle
                        if(object->physicMesh.selectedIsCircle()){
                            //then use the shape as a circle
                            b2CircleShape objectShape;edkEnd();
                            b2FixtureDef fixture;edkEnd();
                            // Check windows
                            fixture.userData.pointer = (uintptr_t)i;edkEnd();
                            objectShape.m_p.Set(translate.x/* * scale.width*/,
                                                translate.y/* * scale.height*/
                                                );edkEnd();
                            objectShape.m_radius = scale.width * object->physicMesh.selectedGetCircleRadius();edkEnd();

                            fixture.density = object->physicMesh.selectedGetDensity();edkEnd();
                            fixture.friction = object->physicMesh.selectedGetFriction();edkEnd();
                            fixture.restitution = object->physicMesh.selectedGetRestitution();edkEnd();
                            //create a fixture to the body
                            fixture.shape = &objectShape;edkEnd();
                            objectBody->CreateFixture(&fixture);edkEnd();
                            ret=true;edkEnd();
                        }
                        else if(object->physicMesh.selectedIsLine()){
                            //







                            //LINES
                            //test if is one line or a chain
                            if(object->physicMesh.selectedGetVertexCount() == 2u){
                                b2EdgeShape objectShape;edkEnd();

                                //load the vertex
                                edk::vec2f32 vertex1;edkEnd();
                                edk::vec2f32 vertex2;edkEnd();

                                //Scale
                                vertex1.x = (object->physicMesh.selectedGetVertexPosition(0u).x * scale.width);edkEnd();
                                vertex1.y = (object->physicMesh.selectedGetVertexPosition(0u).y * scale.height);edkEnd();
                                //rotate
                                vertex1 = edk::Math::rotate(vertex1,
                                                            edk::Math::getAngle(vertex1)
                                                            +
                                                            object->physicMesh.selectedGetAngle()
                                                            );edkEnd();
                                //Translate
                                vertex1+=translate;edkEnd();
                                //process the line
                                vertex2.x = (object->physicMesh.selectedGetVertexPosition(0u).x * scale.width);edkEnd();
                                vertex2.y = (object->physicMesh.selectedGetVertexPosition(0u).y * scale.height);edkEnd();
                                //rotate
                                vertex2 = edk::Math::rotate(vertex2,
                                                            edk::Math::getAngle(vertex2)
                                                            +
                                                            object->physicMesh.selectedGetAngle()
                                                            );edkEnd();
                                //Translate
                                vertex2+=translate;edkEnd();

                                //set the line
                                //removed the old box2D
                                /*
                                objectShape.Set(b2Vec2 (vertex1.x, vertex1.y),
                                                b2Vec2 (vertex2.x, vertex2.y)
                                                );edkEnd();
                                */
                                //change it to the new box2D
                                // These are the edge vertices
                                objectShape.m_vertex1=b2Vec2 (vertex1.x, vertex1.y);edkEnd();
                                objectShape.m_vertex2=b2Vec2 (vertex2.x, vertex2.y);edkEnd();
                                // Optional adjacent vertices. These are used for smooth collision.
                                objectShape.m_vertex0=b2Vec2 (vertex1.x, vertex1.y);edkEnd();
                                objectShape.m_vertex3=b2Vec2 (vertex2.x, vertex2.y);edkEnd();




                                b2FixtureDef fixture;edkEnd();
                                fixture.userData.pointer = (uintptr_t)i;edkEnd();
                                fixture.density = object->physicMesh.selectedGetDensity();edkEnd();
                                fixture.friction = object->physicMesh.selectedGetFriction();edkEnd();
                                fixture.restitution = object->physicMesh.selectedGetRestitution();edkEnd();

                                //create a fixture to the body
                                fixture.shape = &objectShape;edkEnd();
                                objectBody->CreateFixture(&fixture);edkEnd();
                                ret=true;edkEnd();
                            }
                            else if(object->physicMesh.selectedGetVertexCount()>2u){
                                //
                                b2ChainShape objectShape;edkEnd();
                                b2FixtureDef fixture;edkEnd();
                                fixture.userData.pointer = (uintptr_t)i;edkEnd();

                                edk::uint32 vCount=object->physicMesh.selectedGetVertexCount();edkEnd();
                                //it's a polygon
                                if(vCount>b2_maxPolygonVertices){
                                    vCount = b2_maxPolygonVertices;edkEnd();
                                }
                                edk::vec2f32 vertex;edkEnd();
                                for(edk::uint32 p=0u;p<vCount;p++){
                                    /*
                                printf("\n%.2f %.2f",(object->physicMesh.selectedGetVertexPosition(p).x * scale.width) + translate.x,
                                       (object->physicMesh.selectedGetVertexPosition(p).y * scale.height) + translate.y
                                       );edkEnd();
*/
                                    vertex.x = (object->physicMesh.selectedGetVertexPosition(p).x * scale.width);edkEnd();
                                    vertex.y = (object->physicMesh.selectedGetVertexPosition(p).y * scale.height);edkEnd();
                                    vertex = edk::Math::rotate(vertex,
                                                               edk::Math::getAngle(vertex)
                                                               +
                                                               object->physicMesh.selectedGetAngle()
                                                               );edkEnd();
                                    vertexs[p].x = vertex.x + translate.x;edkEnd();
                                    vertexs[p].y = vertex.y + translate.y;edkEnd();
                                }
                                objectShape.CreateChain(vertexs,vCount,vertexs[vCount-2u],vertexs[1u]);edkEnd();
                                //then delete the vertexs

                                fixture.density = object->physicMesh.selectedGetDensity();edkEnd();
                                fixture.friction = object->physicMesh.selectedGetFriction();edkEnd();
                                fixture.restitution = object->physicMesh.selectedGetRestitution();edkEnd();

                                //create a fixture to the body
                                fixture.shape = &objectShape;edkEnd();
                                objectBody->CreateFixture(&fixture);edkEnd();
                                ret=true;edkEnd();
                            }











                        }
                        else{
                            //Else use the shape as polygon
                            b2PolygonShape objectShape;edkEnd();
                            b2FixtureDef fixture;edkEnd();
                            fixture.userData.pointer = (uintptr_t)i;edkEnd();

                            if(object->physicMesh.selectedGetVertexCount() == 2u){
                                //load the rectSize
                                edk::size2f32 rectSize = edk::size2f32((object->physicMesh.selectedGetVertexPosition(1u).x * scale.width)
                                                                       -
                                                                       (object->physicMesh.selectedGetVertexPosition(0u).x * scale.width)
                                                                       ,
                                                                       (object->physicMesh.selectedGetVertexPosition(1u).y * scale.height)
                                                                       -
                                                                       (object->physicMesh.selectedGetVertexPosition(0u).y * scale.height)
                                                                       );edkEnd();
                                edk::vec2f32 rectVec[2u];edkEnd();
                                rectVec[0u] = vec2f32((object->physicMesh.selectedGetVertexPosition(0u).x * scale.width)/* + translate.x*/,
                                                      (object->physicMesh.selectedGetVertexPosition(0u).y * scale.height)/* + translate.y*/
                                                      );edkEnd();
                                rectVec[1u] = vec2f32((object->physicMesh.selectedGetVertexPosition(1u).x * scale.width)/* + translate.x*/,
                                                      (object->physicMesh.selectedGetVertexPosition(1u).y * scale.height)/* + translate.y*/
                                                      );edkEnd();
                                //it's a rectangle
                                /*
                            printf("\nRECT");edkEnd();
                            printf("\n%.2f %.2f",rectVec[0u].x,rectVec[0u].y);edkEnd();
                            printf("\n%.2f %.2f",rectVec[1u].x,rectVec[1u].y);edkEnd();
                            printf("\nsize %.2f %.2f",rectSize.width,rectSize.height);edkEnd();
                            printf("\ntranslate %.2f %.2f",object->physicMesh.selectedGetTranslate().x,object->physicMesh.selectedGetTranslate().y);edkEnd();
                            printf("\nAngle %.2f",object->physicMesh.selectedGetAngle());edkEnd();
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
                                    if(rectSize.width<0.f){
                                        rectSize.width*=-1.f;edkEnd();
                                    }
                                    if(rectSize.height<0.f){
                                        rectSize.height*=-1.f;edkEnd();
                                    }
                                    objectShape.SetAsBox(rectSize.width*0.5f,
                                                         rectSize.height*0.5f,
                                                         b2Vec2(0,0),
                                                         object->physicMesh.selectedGetAngle()/ (180.f / b2_pi)
                                                         );edkEnd();
                                }
                                else{
                                    edk::vec2f32 vertex;edkEnd();
                                    //Else create the polygon

                                    vertex.x = rectVec[0u].x;edkEnd();
                                    vertex.y = rectVec[0u].y;edkEnd();
                                    //rotate
                                    vertex = edk::Math::rotate(vertex,
                                                               edk::Math::getAngle(vertex)
                                                               +
                                                               object->physicMesh.selectedGetAngle()
                                                               ) + translate;edkEnd();
                                    vertexs[0u].x = vertex.x;edkEnd();
                                    vertexs[0u].y = vertex.y;edkEnd();

                                    vertex.x = rectVec[1u].x;edkEnd();
                                    vertex.y = rectVec[0u].y;edkEnd();
                                    //rotate
                                    vertex = edk::Math::rotate(vertex,
                                                               edk::Math::getAngle(vertex)
                                                               +
                                                               object->physicMesh.selectedGetAngle()
                                                               ) + translate;edkEnd();
                                    vertexs[1u].x = vertex.x;edkEnd();
                                    vertexs[1u].y = vertex.y;edkEnd();

                                    vertex.x = rectVec[1u].x;edkEnd();
                                    vertex.y = rectVec[1u].y;edkEnd();
                                    //rotate
                                    vertex = edk::Math::rotate(vertex,
                                                               edk::Math::getAngle(vertex)
                                                               +
                                                               object->physicMesh.selectedGetAngle()
                                                               ) + translate;edkEnd();
                                    vertexs[2u].x = vertex.x;edkEnd();
                                    vertexs[2u].y = vertex.y;edkEnd();

                                    vertex.x = rectVec[0u].x;edkEnd();
                                    vertex.y = rectVec[1u].y;edkEnd();
                                    //rotate
                                    vertex = edk::Math::rotate(vertex,
                                                               edk::Math::getAngle(vertex)
                                                               +
                                                               object->physicMesh.selectedGetAngle()
                                                               ) + translate;edkEnd();
                                    vertexs[3u].x = vertex.x;edkEnd();
                                    vertexs[3u].y = vertex.y;edkEnd();

                                    //add the vertexs in the shape
                                    objectShape.Set(vertexs,4u);edkEnd();
                                    //then delete the vertexs
                                }

                                fixture.density = object->physicMesh.selectedGetDensity();edkEnd();
                                fixture.friction = object->physicMesh.selectedGetFriction();edkEnd();
                                fixture.restitution = object->physicMesh.selectedGetRestitution();edkEnd();
                                //create a fixture to the body
                                fixture.shape = &objectShape;edkEnd();
                                objectBody->CreateFixture(&fixture);edkEnd();
                                ret=true;edkEnd();
                            }
                            else if(object->physicMesh.selectedGetVertexCount() > 2u){
                                edk::uint32 vCount=object->physicMesh.selectedGetVertexCount();edkEnd();
                                //it's a polygon
                                if(vCount>b2_maxPolygonVertices){
                                    vCount = b2_maxPolygonVertices;edkEnd();
                                }
                                edk::vec2f32 vertex;edkEnd();
                                for(edk::uint32 p=0u;p<vCount;p++){
                                    /*
                                printf("\n%.2f %.2f",(object->physicMesh.selectedGetVertexPosition(p).x * scale.width) + translate.x,
                                       (object->physicMesh.selectedGetVertexPosition(p).y * scale.height) + translate.y
                                       );edkEnd();
*/
                                    vertex.x = (object->physicMesh.selectedGetVertexPosition(p).x * scale.width);edkEnd();
                                    vertex.y = (object->physicMesh.selectedGetVertexPosition(p).y * scale.height);edkEnd();
                                    //vertexs[p].x = (object->physicMesh.selectedGetVertexPosition(p).x * scale.width) + translate.x;edkEnd();
                                    //vertexs[p].y = (object->physicMesh.selectedGetVertexPosition(p).y * scale.height) + translate.y;edkEnd();
                                    vertex = edk::Math::rotate(vertex,
                                                               edk::Math::getAngle(vertex)
                                                               +
                                                               object->physicMesh.selectedGetAngle()
                                                               );edkEnd();
                                    vertexs[p].x = vertex.x + translate.x;edkEnd();
                                    vertexs[p].y = vertex.y + translate.y;edkEnd();
                                }
                                objectShape.Set(vertexs,vCount);edkEnd();
                                //then delete the vertexs

                                fixture.density = object->physicMesh.selectedGetDensity();edkEnd();
                                fixture.friction = object->physicMesh.selectedGetFriction();edkEnd();
                                fixture.restitution = object->physicMesh.selectedGetRestitution();edkEnd();

                                //create a fixture to the body
                                fixture.shape = &objectShape;edkEnd();
                                objectBody->CreateFixture(&fixture);edkEnd();
                                ret=true;edkEnd();
                            }

                        }
                    }
                }
            }
            else{
                ret=false;edkEnd();
            }

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
                        if(this->runNextStep){
                            //save the object on the deleted tree
                            objectBody->GetUserData().pointer = 0;
                            this->treeDeleted.add(objectBody);edkEnd();
                        }
                        else{
                            this->world.DestroyBody(objectBody);edkEnd();
                        }
                        ret=false;edkEnd();
                    }
                    break;
                case b2_kinematicBody:
                    if(!this->treeKinematic.addBody(object,objectBody)){
                        //destroy the body
                        if(this->runNextStep){
                            //save the object on the deleted tree
                            objectBody->GetUserData().pointer = 0;
                            this->treeDeleted.add(objectBody);edkEnd();
                        }
                        else{
                            this->world.DestroyBody(objectBody);edkEnd();
                        }
                        ret=false;edkEnd();
                    }
                    break;
                case b2_dynamicBody:
                    if(!this->treeDynamic.addBody(object,objectBody)){
                        //destroy the body
                        if(this->runNextStep){
                            //save the object on the deleted tree
                            objectBody->GetUserData().pointer = 0;
                            this->treeDeleted.add(objectBody);edkEnd();
                        }
                        else{
                            this->world.DestroyBody(objectBody);edkEnd();
                        }
                        ret=false;edkEnd();
                    }
                    break;
                default:
                    //destroy the object
                    if(this->runNextStep){
                        //save the object on the deleted tree
                        objectBody->GetUserData().pointer = 0;
                        this->treeDeleted.add(objectBody);edkEnd();
                    }
                    else{
                        this->world.DestroyBody(objectBody);edkEnd();
                    }
                    ret=false;edkEnd();
                }
            }
            else{
                //delete the object
                if(this->runNextStep){
                    //save the object on the deleted tree
                    objectBody->GetUserData().pointer = 0;
                    this->treeDeleted.add(objectBody);edkEnd();
                }
                else{
                    this->world.DestroyBody(objectBody);edkEnd();
                }
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
        if(this->haveObject(object)){
            //remove all the object joints
            this->removeObjectJoints(object);edkEnd();
            //load the box2D object
            b2Body* temp=NULL;edkEnd();
            switch(object->getType()){
            case edk::physics::StaticBody:
                temp = this->treeStatic.getBody(object);edkEnd();
                if(temp){
                    this->treeStatic.removeBody(temp);edkEnd();
                }
                break;
            case edk::physics::DynamicBody:
                temp = this->treeDynamic.getBody(object);edkEnd();
                if(temp){
                    this->treeDynamic.removeBody(temp);edkEnd();
                }
                break;
            case edk::physics::KinematicBody:
                temp = this->treeKinematic.getBody(object);edkEnd();
                if(temp){
                    this->treeKinematic.removeBody(temp);edkEnd();
                }
                break;
            }
            if(temp){
                if(this->runNextStep){
                    //save the object on the deleted tree
                    temp->GetUserData().pointer = 0;
                    this->treeDeleted.add(temp);edkEnd();
                }
                else{
                    this->world.DestroyBody(temp);edkEnd();
                }
                return true;
            }
        }
    }
    return false;
}
//remove all objects
void edk::physics2D::World2D::removeAllObjects(){
    b2Body* temp=NULL;edkEnd();
    edk::physics2D::PhysicObject2D* tempObject=NULL;edkEnd();
    edk::uint32 count=0u;
    edk::uint32 size = 0u;edkEnd();
    //remove static objects
    size = this->treeStatic.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        //load the object
        temp = this->treeStatic.getBodyInPosition(count);edkEnd();
        if(temp){
            //
            tempObject = (edk::physics2D::PhysicObject2D*) temp->GetUserData().pointer;edkEnd();
            if(tempObject){
                //remove the joints
                this->removeObjectJoints(tempObject);edkEnd();
            }
            if(!this->treeStatic.removeBody(temp)){
                count++;edkEnd();
            }
            if(this->runNextStep){
                //save the object on the deleted tree
                temp->GetUserData().pointer = 0;
                this->treeDeleted.add(temp);edkEnd();
            }
            else{
                this->world.DestroyBody(temp);edkEnd();
            }
        }
        else{
            count++;edkEnd();
        }
    }
    //remove static objects
    size = this->treeKinematic.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        //load the object
        temp = this->treeKinematic.getBodyInPosition(count);edkEnd();
        if(temp){
            //
            tempObject =  (edk::physics2D::PhysicObject2D*)temp->GetUserData().pointer;edkEnd();
            if(tempObject){
                //remove the joints
                this->removeObjectJoints(tempObject);edkEnd();
            }
            if(!this->treeKinematic.removeBody(temp)){
                count++;edkEnd();
            }
            if(this->runNextStep){
                //save the object on the deleted tree
                temp->GetUserData().pointer = 0;
                this->treeDeleted.add(temp);edkEnd();
            }
            else{
                this->world.DestroyBody(temp);edkEnd();
            }
        }
        else{
            count++;edkEnd();
        }
    }
    this->treeKinematic.clean();edkEnd();
    //remove static objects
    size = this->treeDynamic.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        //load the object
        temp = this->treeDynamic.getBodyInPosition(count);edkEnd();
        if(temp){
            //
            tempObject =  (edk::physics2D::PhysicObject2D*)temp->GetUserData().pointer;edkEnd();
            if(tempObject){
                //remove the joints
                this->removeObjectJoints(tempObject);edkEnd();
            }
            if(!this->treeDynamic.removeBody(temp)){
                count++;edkEnd();
            }
            if(this->runNextStep){
                //save the object on the deleted tree
                temp->GetUserData().pointer = 0;
                this->treeDeleted.add(temp);edkEnd();
            }
            else{
                this->world.DestroyBody(temp);edkEnd();
            }
        }
        else{
            count++;edkEnd();
        }
    }
    this->treeDynamic.clean();edkEnd();
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
    return this->treeStatic.size();edkEnd();
}
edk::physics2D::PhysicObject2D* edk::physics2D::World2D::getStaticObjectInPosition(edk::uint32 position){
    b2Body* body = this->treeStatic.getBodyInPosition(position);edkEnd();
    if(body){
        if(body->GetUserData().pointer){
            return (edk::physics2D::PhysicObject2D*)body->GetUserData().pointer;edkEnd();
        }
    }
    return NULL;
}
edk::uint32 edk::physics2D::World2D::getDynamicObjectsSize(){
    return this->treeDynamic.size();edkEnd();
}
edk::physics2D::PhysicObject2D* edk::physics2D::World2D::getDynamicObjectInPosition(edk::uint32 position){
    b2Body* body = this->treeDynamic.getBodyInPosition(position);edkEnd();
    if(body){
        if(body->GetUserData().pointer){
            return (edk::physics2D::PhysicObject2D*)body->GetUserData().pointer;edkEnd();
        }
    }
    return NULL;
}
edk::uint32 edk::physics2D::World2D::getKinematicObjectsSize(){
    return this->treeKinematic.size();edkEnd();
}
edk::physics2D::PhysicObject2D* edk::physics2D::World2D::getKinematicObjectInPosition(edk::uint32 position){
    b2Body* body = this->treeKinematic.getBodyInPosition(position);edkEnd();
    if(body){
        if(body->GetUserData().pointer){
            return (edk::physics2D::PhysicObject2D*)body->GetUserData().pointer;edkEnd();
        }
    }
    return NULL;
}

//update the object position in the world
bool edk::physics2D::World2D::updateObjectVelocity(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);edkEnd();
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            if(object->haveSettedAngularVelocity()){
                temp->SetAngularVelocity((edk::float32)object->getAngularVelocity() / (180.f / b2_pi));edkEnd();
            }
            if(object->haveSettedLinearVelocity()){
                temp->SetLinearVelocity(b2Vec2(object->getLinearVelocity().x * this->percentIn,object->getLinearVelocity().y * this->percentIn));edkEnd();
            }
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectLinearVelocity(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //test if is running the simulation
        if(this->runNextStep){
            //then add the object in to a tree to be added after the nextStep
            this->treeLinearVelocity.add(object);edkEnd();
            return true;
        }

        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);edkEnd();
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            if(object->haveSettedLinearVelocity()){
                temp->SetLinearVelocity(b2Vec2(object->getLinearVelocity().x * this->percentIn,object->getLinearVelocity().y * this->percentIn));edkEnd();
            }
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectAngularVelocity(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //test if is running the simulation
        if(this->runNextStep){
            //then add the object in to a tree to be added after the nextStep
            this->treeAngularVelocity.add(object);edkEnd();
            return true;
        }
        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);edkEnd();
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            if(object->haveSettedAngularVelocity()){
                temp->SetAngularVelocity((edk::float32)object->getAngularVelocity() / (180.f / b2_pi));edkEnd();
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
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);edkEnd();
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            temp->SetLinearVelocity(b2Vec2(0.f,0.f));edkEnd();

            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectStatus(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);edkEnd();
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            b2Fixture* fixture = temp->GetFixtureList();edkEnd();
            if(fixture){
                fixture->SetDensity(object->physicMesh.getPolygonDensity(0u));edkEnd();
                fixture->SetFriction(object->physicMesh.getPolygonFriction(0u));edkEnd();
                fixture->SetRestitution(object->physicMesh.getPolygonRestitution(0u));edkEnd();
            }
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectPosition(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);edkEnd();
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            temp->ApplyUpdatePosition(b2Vec2(object->position.x,object->position.y));edkEnd();
            temp->SetAwake(true);edkEnd();
            temp->SetLinearVelocity(b2Vec2(object->position.x - temp->GetPosition().x
                                           ,object->position.y - temp->GetPosition().y
                                           )
                                    );edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectPositionX(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);edkEnd();
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            temp->ApplyUpdatePositionX(object->position.x);edkEnd();
            temp->SetAwake(true);edkEnd();
            temp->SetLinearVelocity(b2Vec2(object->position.x - temp->GetPosition().x
                                           ,temp->GetLinearVelocity().y
                                           )
                                    );edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectPositionY(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);edkEnd();
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            temp->ApplyUpdatePositionY(object->position.y);edkEnd();
            temp->SetAwake(true);edkEnd();
            temp->SetLinearVelocity(b2Vec2(temp->GetLinearVelocity().x,
                                           object->position.y - temp->GetPosition().y
                                           )
                                    );edkEnd();
            object->setLinearVelocity(temp->GetLinearVelocity().x,
                                      object->position.y - temp->GetPosition().y);edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectSyncronizePosition(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);edkEnd();
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            temp->ApplySynchronizePosition();edkEnd();
            temp->SetAwake(true);edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectSyncronizePositionX(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);edkEnd();
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            temp->ApplySynchronizePositionX();edkEnd();
            temp->SetAwake(true);edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectSyncronizePositionY(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);edkEnd();
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            temp->ApplySynchronizePositionY();edkEnd();
            temp->SetAwake(true);edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectAngle(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);edkEnd();
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            temp->ApplyUpdateAngle(object->angle);edkEnd();
            temp->SetAngularVelocity(object->angle - temp->GetAngle());edkEnd();
            temp->SetAwake(true);edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectPositionAndAngle(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);edkEnd();
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            temp->ApplyUpdatePosition(b2Vec2(object->position.x,object->position.y));edkEnd();
            temp->SetLinearVelocity(b2Vec2(object->position.x - temp->GetPosition().x
                                           ,object->position.y - temp->GetPosition().y
                                           )
                                    );edkEnd();
            temp->ApplyUpdateAngle(object->angle);edkEnd();
            temp->SetAngularVelocity(object->angle - temp->GetAngle());edkEnd();
            temp->SetAwake(true);edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectPositionXAndAngle(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);edkEnd();
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            temp->ApplyUpdatePositionY(object->position.y);edkEnd();
            temp->SetLinearVelocity(b2Vec2(temp->GetLinearVelocity().x,
                                           object->position.y - temp->GetPosition().y
                                           )
                                    );edkEnd();
            temp->ApplyUpdateAngle(object->angle);edkEnd();
            temp->SetAngularVelocity(object->angle - temp->GetAngle());edkEnd();
            temp->SetAwake(true);edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectPositionYAndAngle(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::StaticBody:
            temp = this->treeStatic.getBody(object);edkEnd();
            break;
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            temp->ApplyUpdatePositionY(object->position.y);edkEnd();
            temp->SetLinearVelocity(b2Vec2(temp->GetLinearVelocity().x,
                                           object->position.y - temp->GetPosition().y
                                           )
                                    );edkEnd();
            temp->ApplyUpdateAngle(object->angle);edkEnd();
            temp->SetAngularVelocity(object->angle - temp->GetAngle());edkEnd();
            temp->SetAwake(true);edkEnd();
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
        object->position+=move * this->percentIn;edkEnd();
        return this->updateObjectVelocity(object);edkEnd();
    }
    return false;
}
bool edk::physics2D::World2D::moveObject(edk::physics2D::PhysicObject2D* object,edk::float32 x,edk::float32 y){
    return this->moveObject(object,edk::vec2f32(x,y));edkEnd();
}
bool edk::physics2D::World2D::moveObjectToPosition(edk::physics2D::PhysicObject2D* object,edk::vec2f32 position){
    //test the object
    if(object){
        //move the pbject
        object->position=position * this->percentIn;edkEnd();
        return this->updateObjectVelocity(object);edkEnd();
    }
    return false;
}
bool edk::physics2D::World2D::moveObjectToPosition(edk::physics2D::PhysicObject2D* object,edk::float32 positionX,edk::float32 positionY){
    return this->moveObjectToPosition(object,edk::vec2f32(positionX,positionY));edkEnd();
}
//rotate the object
bool edk::physics2D::World2D::rotateObject(edk::physics2D::PhysicObject2D* object,edk::float32 angle){
    //test the object
    if(object){
        //move the pbject
        object->angle+=angle;edkEnd();
        //while(object->angle>360.f)object->angle-=360.f;edkEnd();
        //while(object->angle<0.f)object->angle+=360.f;edkEnd();
        return this->updateObjectVelocity(object);edkEnd();
    }
    return false;
}
bool edk::physics2D::World2D::rotateObjectToAngle(edk::physics2D::PhysicObject2D* object,edk::float32 angle){
    //test the object
    if(object){
        //move the pbject
        object->angle=angle;edkEnd();
        //while(object->angle>360.f)object->angle-=360.f;edkEnd();
        //while(object->angle<0.f)object->angle+=360.f;edkEnd();
        return this->updateObjectVelocity(object);edkEnd();
    }
    return false;
}
//Put a object to sleep
bool edk::physics2D::World2D::sleepObject(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        temp = this->treeDynamic.getBody(object);edkEnd();
        if(temp){
            object->canSleep=true;edkEnd();
            temp->SetAwake(false);edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::unsleepObject(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        temp = this->treeDynamic.getBody(object);edkEnd();
        if(temp){
            temp->SetAwake(true);edkEnd();
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
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            temp->SetLinearVelocity(b2Vec2(vector.x * this->percentIn,vector.y * this->percentIn));edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::setAngularVelocity(edk::physics2D::PhysicObject2D* object,edk::float32 angle){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            temp->SetAngularVelocity(angle / (180.f / b2_pi));edkEnd();
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
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            temp->ApplyForce(b2Vec2(force.x * this->percentIn,force.y * this->percentIn),
                             b2Vec2(position.x * this->percentIn,position.y * this->percentIn),
                             wake
                             );edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::applyLinearImpulse(edk::physics2D::PhysicObject2D* object,edk::vec2f32 impulse, edk::vec2f32 position,bool wake){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            temp->ApplyLinearImpulse(b2Vec2(impulse.x * this->percentIn,impulse.y * this->percentIn),b2Vec2(position.x * this->percentIn,position.y * this->percentIn),wake);edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::applyAngularImpulse(edk::physics2D::PhysicObject2D* object,edk::float32 angle,bool wake){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            temp->ApplyAngularImpulse(angle / (180.f / b2_pi),
                                      wake
                                      );edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::physics2D::World2D::applyTorque(edk::physics2D::PhysicObject2D* object,edk::float32 torque,bool wake){
    //test the object
    if(object){
        //load the box2D object
        b2Body* temp=NULL;edkEnd();
        switch(object->getType()){
        case edk::physics::DynamicBody:
            temp = this->treeDynamic.getBody(object);edkEnd();
            break;
        case edk::physics::KinematicBody:
            temp = this->treeKinematic.getBody(object);edkEnd();
            break;
        }
        if(temp){
            temp->ApplyTorque(torque * this->percentIn,wake);edkEnd();
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
        this->runNextStep = true;edkEnd();
        this->world.Step(timeStep,velocityIterations,positionIterations);edkEnd();
        this->runNextStep = false;edkEnd();

        //clean the treeObjectContacts
        this->beginContacs.clean();edkEnd();
        this->keepBeginContacs.clean();edkEnd();
        this->keepEndContacs.clean();edkEnd();
        this->endContacs.clean();edkEnd();
        this->sensorBeginContacs.clean();edkEnd();
        this->sensorKeepContacs.clean();edkEnd();
        this->sensorEndContacs.clean();edkEnd();

        //create new objects
        this->treeNew.print();edkEnd();
        this->treeNew.clean();edkEnd();
        //update the linear velocity of the object
        this->treeLinearVelocity.render();edkEnd();
        this->treeLinearVelocity.clean();edkEnd();
        //update the angular velocity of the object
        this->treeAngularVelocity.update();edkEnd();
        this->treeAngularVelocity.clean();edkEnd();

        //update the kinematic objects
        this->treeKinematic.update();edkEnd();
        this->treeDynamic.update();edkEnd();
        this->treeJoint.update();edkEnd();

        //remove the bodys
        this->treeDeleted.update();edkEnd();
        this->treeDeleted.clean();edkEnd();
    }
}
//next spet with clock
void edk::physics2D::World2D::nextStep(edk::int32 velocityIterations, edk::int32 positionIterations){
    //get the clock
    this->nextStep(this->clock.getMicroseconds() * edk::watch::microsecond * this->clockScale,
                   velocityIterations,
                   positionIterations);edkEnd();

    //then clean the clock
    this->clockStart();edkEnd();
}
//pause the world steps
void edk::physics2D::World2D::pauseStepOn(){
    //test if is NOT paused
    if(!this->paused){
        //save the clock
        this->clock.saveDistance();edkEnd();
        this->paused=true;edkEnd();
    }
}
void edk::physics2D::World2D::pauseStepOff(){
    //test if is Paused
    if(this->paused){
        //start the clock and paste the distance
        this->clockStart();edkEnd();
        this->clock.pasteDistance();edkEnd();
        this->paused=false;edkEnd();
    }
}

//reset the clock
void edk::physics2D::World2D::clockStart(){
    this->clock.start();edkEnd();
}
//set clockScale
void edk::physics2D::World2D::setClockScale(edk::float32 clockScale){
    this->clockScale = clockScale;edkEnd();
}


//return the size of contacts
edk::uint32 edk::physics2D::World2D::getContactSize(){
    return this->treeConcacts.getSize();edkEnd();
}
//return the contact
edk::physics2D::Contact2D* edk::physics2D::World2D::getContact(edk::uint32 position){
    return this->treeConcacts.getElementInPosition(position);edkEnd();
}


//joints
//MOUSE
edk::physics2D::MouseJoint2D* edk::physics2D::World2D::createMouseJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,edk::vec2f32 positionB){
    //test the object
    if(objectA){
        //test the objectType
        if(objectA->getType()!=edk::physics::StaticBody){
            //create a ground body
            edk::physics2D::KinematicObject2D* ground = new edk::physics2D::KinematicObject2D;edkEnd();
            if(ground){
                edk::shape::Rectangle2D rect;edkEnd();
                rect.setPivoToCenter();edkEnd();
                ground->physicMesh.addPolygon(rect);edkEnd();

                ground->position=positionB;edkEnd();

                if(this->addObject(ground)){
                    //


                    //load the objects
                    b2Body* bodyA = this->getBody(ground);edkEnd();
                    b2Body* bodyB = this->getBody(objectA);edkEnd();

                    //create the joint
                    if(bodyA && bodyB){
                        edk::physics2D::MouseJoint2D *edkJoint = NULL;edkEnd();
                        //create the revolute def
                        b2MouseJointDef jointDef;edkEnd();
                        jointDef.collideConnected=false;edkEnd();
                        jointDef.bodyA = bodyA;edkEnd();
                        jointDef.bodyB = bodyB;edkEnd();
                        //jointDef.target = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);edkEnd();

                        //create the edkJoint
                        edkJoint = new edk::physics2D::MouseJoint2D(false);edkEnd();
                        if(edkJoint){
                            //in the new version of box2D the userData are setted in jointDef
                            jointDef.userData.pointer = (uintptr_t)edkJoint;edkEnd();

                            edkJoint->objectA = ground;edkEnd();
                            edkJoint->objectB = objectA;edkEnd();
                            edkJoint->positionA = positionA;edkEnd();
                            edkJoint->positionB = 0.f;edkEnd();
                            edkJoint->worldPositionA
                                    =
                                    edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
                                    ;edkEnd();
                            edkJoint->positionB = positionB;edkEnd();

                            //create the edkJoint
                            if(this->addJoint(edkJoint)){
                                //
                                b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);edkEnd();
                                if(joint){
                                    b2MouseJoint* mouseJoint = (b2MouseJoint*)joint;edkEnd();
                                    mouseJoint->SetTarget(b2Vec2(positionB.x,positionB.y));edkEnd();
                                    //removed from the old box2D version. In the new box2D version the userData is in JointDef
                                    //joint->SetUserData(edkJoint);edkEnd();
                                    //add the joint in the tree
                                    if(this->treeJoint.addJoint(edkJoint,joint)){
                                        return edkJoint;edkEnd();
                                    }
                                    //else destroy the joint
                                    this->world.DestroyJoint(joint);edkEnd();
                                }
                                this->destroyJoint(edkJoint);edkEnd();
                            }
                        }
                    }
                    this->removeObject(ground);edkEnd();
                }
                delete ground;edkEnd();
            }
        }
    }
    return NULL;
}
edk::physics2D::MouseJoint2D* edk::physics2D::World2D::createMouseJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 worldPosition){
    //test the object
    if(objectA){
        return this->createMouseJoint(objectA,
                                      edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                      worldPosition
                                      );edkEnd();
    }
    return NULL;
}

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
            b2Body* bodyA = this->getBody(objectA);edkEnd();
            b2Body* bodyB = this->getBody(objectB);edkEnd();

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::RevoluteJoint2D *edkJoint = NULL;edkEnd();
                //create the revolute def
                b2RevoluteJointDef jointDef;edkEnd();
                jointDef.collideConnected=collide;edkEnd();
                jointDef.bodyA = bodyA;edkEnd();
                jointDef.bodyB = bodyB;edkEnd();
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);edkEnd();
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);edkEnd();

                //create the edkJoint
                edkJoint = new edk::physics2D::RevoluteJoint2D(collide);edkEnd();
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;edkEnd();

                    edkJoint->objectA = objectA;edkEnd();
                    edkJoint->objectB = objectB;edkEnd();
                    edkJoint->positionA = positionA;edkEnd();
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
                            ;edkEnd();
                    edkJoint->positionB = positionB;edkEnd();
                    /*
                    edkJoint->worldPositionB
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectB,positionB)
                            ;edkEnd();
*/

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);edkEnd();
                        if(joint){
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);edkEnd();
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;edkEnd();
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);edkEnd();
                        }
                        this->destroyJoint(edkJoint);edkEnd();
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
                                         edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                         objectB,
                                         edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                         collide
                                         );edkEnd();
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
            b2Body* bodyA = this->getBody(objectA);edkEnd();
            b2Body* bodyB = this->getBody(objectB);edkEnd();

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::RevoluteJoint2D *edkJoint = NULL;edkEnd();
                //create the revolute def
                b2RevoluteJointDef jointDef;edkEnd();
                jointDef.collideConnected=collide;edkEnd();
                jointDef.bodyA = bodyA;edkEnd();
                jointDef.bodyB = bodyB;edkEnd();
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);edkEnd();
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);edkEnd();

                jointDef.lowerAngle = (lowerAngle / 180.f) * b2_pi;edkEnd();
                jointDef.upperAngle = (upperAngle/ 180.f) * b2_pi;edkEnd();
                jointDef.enableLimit=true;edkEnd();



                //create the edkJoint
                edkJoint = new edk::physics2D::RevoluteJoint2D(collide);edkEnd();
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;edkEnd();

                    edkJoint->objectA = objectA;edkEnd();
                    edkJoint->objectB = objectB;edkEnd();
                    edkJoint->positionA = positionA;edkEnd();
                    edkJoint->worldPositionA = edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA);edkEnd();
                    edkJoint->positionB = positionB;edkEnd();

                    //angle Joint
                    edkJoint->setAngle(lowerAngle,upperAngle);edkEnd();

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);edkEnd();
                        if(joint){
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);edkEnd();
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;edkEnd();
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);edkEnd();
                        }
                        this->destroyJoint(edkJoint);edkEnd();
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
                                              edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                              objectB,
                                              edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                              lowerAngle,upperAngle,
                                              collide
                                              );edkEnd();
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
            b2Body* bodyA = this->getBody(objectA);edkEnd();
            b2Body* bodyB = this->getBody(objectB);edkEnd();

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::RevoluteJoint2D *edkJoint = NULL;edkEnd();
                //create the revolute def
                b2RevoluteJointDef jointDef;edkEnd();
                jointDef.collideConnected=collide;edkEnd();
                jointDef.bodyA = bodyA;edkEnd();
                jointDef.bodyB = bodyB;edkEnd();
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);edkEnd();
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);edkEnd();

                jointDef.maxMotorTorque = maxTorque;edkEnd();
                jointDef.motorSpeed = speed;edkEnd();
                jointDef.enableMotor=true;edkEnd();



                //create the edkJoint
                edkJoint = new edk::physics2D::RevoluteJoint2D(collide);edkEnd();
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;edkEnd();

                    edkJoint->objectA = objectA;edkEnd();
                    edkJoint->objectB = objectB;edkEnd();
                    edkJoint->positionA = positionA;edkEnd();
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
                            ;edkEnd();
                    edkJoint->positionB = positionB;edkEnd();

                    //set motor
                    edkJoint->setMotor(maxTorque,speed);edkEnd();

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);edkEnd();
                        if(joint){
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);edkEnd();
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;edkEnd();
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);edkEnd();
                        }
                        this->destroyJoint(edkJoint);edkEnd();
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
                                              edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                              objectB,
                                              edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                              maxTorque,speed,
                                              collide
                                              );edkEnd();
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
            b2Body* bodyA = this->getBody(objectA);edkEnd();
            b2Body* bodyB = this->getBody(objectB);edkEnd();

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::PrismaticJoint2D *edkJoint = NULL;edkEnd();
                //create the revolute def
                b2PrismaticJointDef jointDef;edkEnd();
                jointDef.collideConnected=collide;edkEnd();
                jointDef.bodyA = bodyA;edkEnd();
                jointDef.bodyB = bodyB;edkEnd();
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);edkEnd();
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);edkEnd();
                jointDef.localAxisA = b2Vec2(direction.x * this->percentIn,direction.y * this->percentIn);edkEnd();
                jointDef.localAxisA.Normalize();edkEnd();
                if(upperDistance > lowerDistance){
                    //enable distance
                    jointDef.lowerTranslation = lowerDistance;edkEnd();
                    jointDef.upperTranslation = upperDistance;edkEnd();
                    jointDef.enableLimit=true;edkEnd();
                }

                //create the edkJoint
                edkJoint = new edk::physics2D::PrismaticJoint2D(collide);edkEnd();
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;edkEnd();

                    edkJoint->objectA = objectA;edkEnd();
                    edkJoint->objectB = objectB;edkEnd();
                    edkJoint->positionA = positionA;edkEnd();
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
                            ;edkEnd();
                    edkJoint->positionB = positionB;edkEnd();

                    edkJoint->direction = direction;edkEnd();

                    //Set Angle
                    edkJoint->upperDistance = upperDistance;edkEnd();
                    edkJoint->lowerDistance = lowerDistance;edkEnd();

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);edkEnd();
                        if(joint){
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);edkEnd();
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;edkEnd();
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);edkEnd();
                        }
                        this->destroyJoint(edkJoint);edkEnd();
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
                                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                          objectB,
                                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                          direction,lowerDistance,upperDistance,
                                          collide
                                          );edkEnd();
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
                                          edk::Math::rotate(edk::vec2f32(1,0),angle),lowerDistance,upperDistance,
                                          collide
                                          );edkEnd();
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
                                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                          objectB,
                                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                          edk::Math::rotate(edk::vec2f32(1,0),angle),lowerDistance,upperDistance,
                                          collide
                                          );edkEnd();
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
            b2Body* bodyA = this->getBody(objectA);edkEnd();
            b2Body* bodyB = this->getBody(objectB);edkEnd();

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::PrismaticJoint2D *edkJoint = NULL;edkEnd();
                //create the revolute def
                b2PrismaticJointDef jointDef;edkEnd();
                jointDef.collideConnected=collide;edkEnd();
                jointDef.bodyA = bodyA;edkEnd();
                jointDef.bodyB = bodyB;edkEnd();
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);edkEnd();
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);edkEnd();
                jointDef.localAxisA = b2Vec2(direction.x * this->percentIn,direction.y * this->percentIn);edkEnd();
                jointDef.localAxisA.Normalize();edkEnd();
                if(upperDistance > lowerDistance){
                    //enable distance
                    jointDef.lowerTranslation = lowerDistance;edkEnd();
                    jointDef.upperTranslation = upperDistance;edkEnd();
                    jointDef.enableLimit=true;edkEnd();
                }
                jointDef.maxMotorForce = maxForce;edkEnd();
                jointDef.motorSpeed = speed;edkEnd();
                jointDef.enableMotor=true;edkEnd();

                //create the edkJoint
                edkJoint = new edk::physics2D::PrismaticJoint2D(collide);edkEnd();
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;edkEnd();

                    edkJoint->objectA = objectA;edkEnd();
                    edkJoint->objectB = objectB;edkEnd();
                    edkJoint->positionA = positionA;edkEnd();
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
                            ;edkEnd();
                    edkJoint->positionB = positionB;edkEnd();

                    edkJoint->direction = direction;edkEnd();

                    //Set Angle
                    edkJoint->lowerDistance = lowerDistance;edkEnd();
                    edkJoint->upperDistance = upperDistance;edkEnd();
                    //Set motor as the last because the joint will return motor type
                    edkJoint->setForce(maxForce,speed);edkEnd();

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);edkEnd();
                        if(joint){
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);edkEnd();
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;edkEnd();
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);edkEnd();
                        }
                        this->destroyJoint(edkJoint);edkEnd();
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
                                               edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                               objectB,
                                               edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                               direction,lowerDistance,upperDistance,
                                               maxForce,speed,
                                               collide
                                               );edkEnd();
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
                                               edk::Math::rotate(edk::vec2f32(1,0),angle),lowerDistance,upperDistance,
                                               maxForce,speed,
                                               collide
                                               );edkEnd();
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
                                               edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                               objectB,
                                               edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                               edk::Math::rotate(edk::vec2f32(1,0),angle),lowerDistance,upperDistance,
                                               maxForce,speed,
                                               collide
                                               );edkEnd();
    }
    return NULL;
}

//DISTANCE
edk::physics2D::DistanceJoint2D* edk::physics2D::World2D::createDistanceJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                              edk::vec2f32 positionA,
                                                                              edk::physics2D::PhysicObject2D* objectB,
                                                                              edk::vec2f32 positionB,
                                                                              edk::float32 distance,
                                                                              bool collide
                                                                              ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::physics::StaticBody || objectB->getType()!=edk::physics::StaticBody){
            //load the objects
            b2Body* bodyA = this->getBody(objectA);edkEnd();
            b2Body* bodyB = this->getBody(objectB);edkEnd();

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::DistanceJoint2D *edkJoint = NULL;edkEnd();
                //create the revolute def
                b2DistanceJointDef jointDef;edkEnd();
                jointDef.collideConnected=collide;edkEnd();
                jointDef.bodyA = bodyA;edkEnd();
                jointDef.bodyB = bodyB;edkEnd();
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);edkEnd();
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);edkEnd();
                jointDef.length = distance;edkEnd();

                //removed frequency in new box2D

                //create the edkJoint
                edkJoint = new edk::physics2D::DistanceJoint2D(collide);edkEnd();
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;edkEnd();

                    edkJoint->objectA = objectA;edkEnd();
                    edkJoint->objectB = objectB;edkEnd();
                    edkJoint->positionA = positionA;edkEnd();
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
                            ;edkEnd();
                    edkJoint->positionB = positionB;edkEnd();
                    edkJoint->worldPositionB
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectB,positionB)
                            ;edkEnd();

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);edkEnd();
                        if(joint){
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);edkEnd();
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;edkEnd();
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);edkEnd();
                        }
                        this->destroyJoint(edkJoint);edkEnd();
                    }
                }
            }
        }
    }
    return NULL;
}
edk::physics2D::DistanceJoint2D* edk::physics2D::World2D::createDistanceJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 worldPositionA,
                                                                              edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPositionB,
                                                                              bool collide
                                                                              ){
    //test the object
    if(objectA && objectB){
        return this->createDistanceJoint(objectA,
                                         edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPositionA),
                                         objectB,
                                         edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPositionB),
                                         edk::Math::module(edk::Math::pythagoras(worldPositionA - worldPositionB)),
                                         collide
                                         );edkEnd();
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
            b2Body* bodyA = this->getBody(objectA);edkEnd();
            b2Body* bodyB = this->getBody(objectB);edkEnd();

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::PulleyJoint2D *edkJoint = NULL;edkEnd();
                //create the revolute def
                b2PulleyJointDef jointDef;edkEnd();
                jointDef.collideConnected=collide;edkEnd();
                jointDef.bodyA = bodyA;edkEnd();
                jointDef.bodyB = bodyB;edkEnd();
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);edkEnd();
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);edkEnd();

                jointDef.groundAnchorA = b2Vec2((pulleyPositionA.x * this->percentIn) + (objectA->position.x * this->percentIn),(pulleyPositionA.y * this->percentIn) + (objectA->position.y * this->percentIn));edkEnd();
                jointDef.groundAnchorB = b2Vec2((pulleyPositionB.x * this->percentIn) + (objectB->position.x * this->percentIn),(pulleyPositionB.y * this->percentIn) + (objectB->position.y * this->percentIn));edkEnd();

                jointDef.lengthA = lenghtA;edkEnd();
                jointDef.lengthB = lenghtB;edkEnd();

                //create the edkJoint
                edkJoint = new edk::physics2D::PulleyJoint2D(collide);edkEnd();
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;edkEnd();

                    edkJoint->objectA = objectA;edkEnd();
                    edkJoint->objectB = objectB;edkEnd();
                    edkJoint->positionA = positionA;edkEnd();
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
                            ;edkEnd();
                    edkJoint->positionB = positionB;edkEnd();
                    edkJoint->worldPositionB
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectB,positionB)
                            ;edkEnd();
                    edkJoint->pulleyPositionA
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,pulleyPositionA)
                            ;edkEnd();
                    edkJoint->pulleyPositionB
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectB,pulleyPositionB)
                            ;edkEnd();


                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);edkEnd();
                        if(joint){
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);edkEnd();
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;edkEnd();
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);edkEnd();
                        }
                        this->destroyJoint(edkJoint);edkEnd();
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
                                       edk::Math::module(edk::Math::pythagoras(pulleyPositionA-positionA)),
                                       edk::Math::module(edk::Math::pythagoras(pulleyPositionB-positionB)),
                                       collide
                                       );edkEnd();
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
                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPositionA),
                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,pulleyWorldPositionA),
                          objectB,
                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPositionB),
                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,pulleyWorldPositionB),
                          lenghtA,lenghtB,
                          collide
                          );edkEnd();
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
                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPositionA),
                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,pulleyWorldPositionA),
                          objectB,
                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPositionB),
                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,pulleyWorldPositionB),
                          collide
                          );edkEnd();
    }
    return NULL;
}
//WHEEL
edk::physics2D::WheelJoint2D* edk::physics2D::World2D::createWheelJoint(edk::physics2D::PhysicObject2D* objectA,edk::vec2f32 positionA,
                                                                        edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 positionB,
                                                                        edk::vec2f32 direction,
                                                                        bool collide
                                                                        ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::physics::StaticBody || objectB->getType()!=edk::physics::StaticBody){
            //load the objects
            b2Body* bodyA = this->getBody(objectA);edkEnd();
            b2Body* bodyB = this->getBody(objectB);edkEnd();

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::WheelJoint2D *edkJoint = NULL;edkEnd();
                //create the revolute def
                b2WheelJointDef jointDef;edkEnd();
                jointDef.collideConnected=collide;edkEnd();
                jointDef.bodyA = bodyA;edkEnd();
                jointDef.bodyB = bodyB;edkEnd();
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);edkEnd();
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);edkEnd();

                jointDef.localAxisA = b2Vec2(direction.x * this->percentIn,direction.y * this->percentIn);edkEnd();
                jointDef.localAxisA.Normalize();edkEnd();

                //removed frequency in new box2D
                //removed dampingRatio in new box2D

                //create the edkJoint
                edkJoint = new edk::physics2D::WheelJoint2D(collide);edkEnd();
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;edkEnd();

                    edkJoint->objectA = objectA;edkEnd();
                    edkJoint->objectB = objectB;edkEnd();
                    edkJoint->positionA = positionA;edkEnd();
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
                            ;edkEnd();
                    edkJoint->positionB = positionB;edkEnd();

                    edkJoint->direction = direction;edkEnd();

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);edkEnd();
                        if(joint){
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);edkEnd();
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;edkEnd();
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);edkEnd();
                        }
                        this->destroyJoint(edkJoint);edkEnd();
                    }
                }
            }
        }
    }
    return NULL;
}

edk::physics2D::WheelJoint2D* edk::physics2D::World2D::createWheelJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,edk::vec2f32 worldPosition,
                                                                        edk::vec2f32 direction,
                                                                        bool collide
                                                                        ){
    //test the object
    if(objectA && objectB){
        return this->createWheelJoint(objectA,
                                      edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                      objectB,
                                      edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                      direction,
                                      collide
                                      );edkEnd();
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
        //test the objectType
        if(objectA->getType()!=edk::physics::StaticBody || objectB->getType()!=edk::physics::StaticBody){
            //load the objects
            b2Body* bodyA = this->getBody(objectA);edkEnd();
            b2Body* bodyB = this->getBody(objectB);edkEnd();

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::WheelJoint2D *edkJoint = NULL;edkEnd();
                //create the revolute def
                b2WheelJointDef jointDef;edkEnd();
                jointDef.collideConnected=collide;edkEnd();
                jointDef.bodyA = bodyA;edkEnd();
                jointDef.bodyB = bodyB;edkEnd();
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);edkEnd();
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);edkEnd();

                jointDef.localAxisA = b2Vec2(direction.x * this->percentIn,direction.y * this->percentIn);edkEnd();
                jointDef.localAxisA.Normalize();edkEnd();

                //removed frequency in new box2D
                //removed dampingRatio in new box2D

                jointDef.maxMotorTorque = maxTorque;edkEnd();
                jointDef.motorSpeed = speed;edkEnd();
                jointDef.enableMotor=true;edkEnd();

                //create the edkJoint
                edkJoint = new edk::physics2D::WheelJoint2D(collide);edkEnd();
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;edkEnd();

                    edkJoint->objectA = objectA;edkEnd();
                    edkJoint->objectB = objectB;edkEnd();
                    edkJoint->positionA = positionA;edkEnd();
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
                            ;edkEnd();
                    edkJoint->positionB = positionB;edkEnd();

                    edkJoint->direction = direction;edkEnd();

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);edkEnd();
                        if(joint){
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);edkEnd();
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;edkEnd();
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);edkEnd();
                        }
                        this->destroyJoint(edkJoint);edkEnd();
                    }
                }
            }
        }
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
        return this->createWheelMotorJoint(objectA,
                                           edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                           objectB,
                                           edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                           direction,
                                           maxTorque,speed,
                                           collide
                                           );edkEnd();
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
            b2Body* bodyA = this->getBody(objectA);edkEnd();
            b2Body* bodyB = this->getBody(objectB);edkEnd();

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::Joint2D *edkJoint = NULL;edkEnd();
                //create the revolute def
                b2WeldJointDef jointDef;edkEnd();
                jointDef.collideConnected=collide;edkEnd();
                jointDef.bodyA = bodyA;edkEnd();
                jointDef.bodyB = bodyB;edkEnd();
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);edkEnd();
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);edkEnd();

                //create the edkJoint
                if((edkJoint = this->addJoint(objectA,positionA,objectB,positionB))){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;edkEnd();

                    b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);edkEnd();
                    if(joint){
                        //removed from the old box2D version. In the new box2D version the userData is in JointDef
                        //joint->SetUserData(edkJoint);edkEnd();
                        //add the joint in the tree
                        if(this->treeJoint.addJoint(edkJoint,joint)){
                            return edkJoint;edkEnd();
                        }
                        //else destroy the joint
                        this->world.DestroyJoint(joint);edkEnd();
                    }
                    this->destroyJoint(edkJoint);edkEnd();
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
                                     edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                     objectB,
                                     edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                     collide
                                     );edkEnd();
    }
    return NULL;
}
//ROPE //REMOVED FROM NEW BOX2D
/*
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
            b2Body* bodyA = this->getBody(objectA);edkEnd();
            b2Body* bodyB = this->getBody(objectB);edkEnd();

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::RopeJoint2D *edkJoint = NULL;edkEnd();
                //create the revolute def
                b2RopeJointDef jointDef;edkEnd();
                jointDef.collideConnected=collide;edkEnd();
                jointDef.bodyA = bodyA;edkEnd();
                jointDef.bodyB = bodyB;edkEnd();
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);edkEnd();
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);edkEnd();

                jointDef.maxLength = maxLength;edkEnd();

                //create the edkJoint
                edkJoint = new edk::physics2D::RopeJoint2D(collide);edkEnd();
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;edkEnd();

                    edkJoint->objectA = objectA;edkEnd();
                    edkJoint->objectB = objectB;edkEnd();
                    edkJoint->positionA = positionA;edkEnd();
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectA,positionA)
                            ;edkEnd();
                    edkJoint->positionB = positionB;edkEnd();
                    edkJoint->worldPositionB
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectB,positionB)
                            ;edkEnd();
                    edkJoint->maxLength = maxLength;edkEnd();

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);edkEnd();
                        if(joint){
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);edkEnd();
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;edkEnd();
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);edkEnd();
                        }
                        this->destroyJoint(edkJoint);edkEnd();
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
                                     );edkEnd();
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
                                                   edk::Math::module(edk::Math::pythagoras(worldPositionA - worldPositionB)),
                                                   collide
                                                   );edkEnd();
    }
    return NULL;
}
*/
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
            b2Body* bodyA = this->getBody(objectA);edkEnd();
            b2Body* bodyB = this->getBody(objectB);edkEnd();

            //create the joint
            if(bodyA && bodyB){
                edk::physics2D::RopeJoint2D *edkJoint = NULL;edkEnd();
                //create the revolute def
                b2GearJointDef jointDef;edkEnd();
                jointDef.collideConnected=collide;edkEnd();
                jointDef.bodyA = bodyA;edkEnd();
                jointDef.bodyB = bodyB;edkEnd();
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);edkEnd();
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);edkEnd();

                jointDef.distance = distance;edkEnd();

                //create the edkJoint
                edkJoint = new edk::physics2D::RopeJoint2D(collide);edkEnd();
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;edkEnd();

                    edkJoint->objectA = objectA;edkEnd();
                    edkJoint->objectB = objectB;edkEnd();
                    edkJoint->positionA = positionA;edkEnd();
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectA,positionA)
                            ;edkEnd();
                    edkJoint->positionB = positionB;edkEnd();
                    edkJoint->worldPositionB
                            =
                            edk::physics2D::World2D::JointTree::getJointWorldPosition(objectB,positionB)
                            ;edkEnd();

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);edkEnd();
                        if(joint){
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);edkEnd();
                            //add the joint in the tree
                            if(this->treeJoint.addJoint(edkJoint,joint)){
                                return edkJoint;edkEnd();
                            }
                            //else destroy the joint
                            this->world.DestroyJoint(joint);edkEnd();
                        }
                        this->destroyJoint(edkJoint);edkEnd();
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
        edk::physics2D::World2D::ObjectsJointsTree* treeTemp = this->treeJointObjects.getTreeJoint(joint->objectA);edkEnd();
        edk::physics2D::World2D::ObjectJointsTree* objectJointsTemp = NULL;edkEnd();
        if(treeTemp){
            //load the tree objectJoints
            objectJointsTemp = treeTemp->getJoint(joint->objectB);edkEnd();
            if(objectJointsTemp){
                //remove the joint
                objectJointsTemp->removeJoint(joint);edkEnd();
                if(!objectJointsTemp->getSize()){
                    treeTemp->removeJoint(objectJointsTemp);edkEnd();
                    objectJointsTemp->cleanJoints();edkEnd();
                    delete objectJointsTemp;edkEnd();
                    objectJointsTemp=NULL;edkEnd();
                }
            }
        }
        treeTemp = this->treeJointObjects.getTreeJoint(joint->objectB);edkEnd();
        if(treeTemp){
            //load the tree objectJoints
            objectJointsTemp = treeTemp->getJoint(joint->objectA);edkEnd();
            if(objectJointsTemp){
                //remove the joint
                objectJointsTemp->removeJoint(joint);edkEnd();
                if(!objectJointsTemp->getSize()){
                    treeTemp->removeJoint(objectJointsTemp);edkEnd();
                    objectJointsTemp->cleanJoints();edkEnd();
                    delete objectJointsTemp;edkEnd();
                    objectJointsTemp=NULL;edkEnd();
                }
            }
        }

        //get the b2joint
        b2Joint* boxJoint = this->treeJoint.getJoint(joint);edkEnd();
        if(boxJoint){
            this->treeJoint.removeJoint(boxJoint);edkEnd();

            //destroy the joint
            this->world.DestroyJoint(boxJoint);edkEnd();

            if(joint->getType() == EDK_REVOLUTE_JOINT){
                //delete the ground
                if(this->removeObject(joint->objectA)){
                    delete joint->objectA;edkEnd();
                }
            }
            //delete the joint
            delete joint;edkEnd();
            return true;
        }
    }
    return false;
}
//destroy joint with the object
bool edk::physics2D::World2D::destroyObjectJoints(edk::physics2D::PhysicObject2D* object){
    return this->removeObjectJoints(object);edkEnd();
}
//return the joint
edk::physics2D::Joint2D* edk::physics2D::World2D::getJointInPosition(edk::uint32 position){
    if(this->treeJoint.size()){
        //return the joint
        return this->treeJoint.getJointInPosition(position);edkEnd();
    }
    return NULL;
}
//get Joint Type
edk::uint8 edk::physics2D::World2D::getJointTypeInPosition(edk::uint32 position){
    edk::physics2D::Joint2D* joint = this->getJointInPosition(position);edkEnd();
    if(joint){
        return joint->getType();edkEnd();
    }
    return 0u;edkEnd();
}

//return the joints count
edk::uint32 edk::physics2D::World2D::getJointSize(){
    return this->treeJoint.size();edkEnd();
}

//update the joints
bool edk::physics2D::World2D::setMotorJointMaxTorque(edk::physics2D::Joint2D* joint,edk::float32 maxTorque){
    //text the joint
    if(joint){
        //load the b2joint
        b2Joint *boxJoint = this->treeJoint.getJoint(joint);edkEnd();
        if(boxJoint){
            switch(boxJoint->GetType()){
            case e_revoluteJoint:
                //
            {
                b2RevoluteJoint* temp = (b2RevoluteJoint*)boxJoint;edkEnd();
                temp->SetMaxMotorTorque(maxTorque * this->percentIn);edkEnd();
                return true;
            }
            case e_motorJoint:
                //
            {
                b2MotorJoint* temp = (b2MotorJoint*)boxJoint;edkEnd();
                temp->SetMaxTorque(maxTorque * this->percentIn);edkEnd();
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
        b2Joint *boxJoint = this->treeJoint.getJoint(joint);edkEnd();
        if(boxJoint){
            switch(boxJoint->GetType()){
            case e_revoluteJoint:
                //
            {
                b2RevoluteJoint* temp = (b2RevoluteJoint*)boxJoint;edkEnd();
                temp->SetMotorSpeed(speed * this->percentIn);edkEnd();
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
        b2Joint *boxJoint = this->treeJoint.getJoint(joint);edkEnd();
        if(boxJoint){
            switch(boxJoint->GetType()){
            case e_revoluteJoint:
                //
            {
                b2RevoluteJoint* temp = (b2RevoluteJoint*)boxJoint;edkEnd();
                temp->SetMaxMotorTorque(maxTorque * this->percentIn);edkEnd();
                temp->SetMotorSpeed(speed * this->percentIn);edkEnd();
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
        b2Joint *boxJoint = this->treeJoint.getJoint(joint);edkEnd();
        if(boxJoint){
            switch(boxJoint->GetType()){
            case e_revoluteJoint:
                //
            {
                b2RevoluteJoint* temp = (b2RevoluteJoint*)boxJoint;edkEnd();
                return temp->GetJointAngle();edkEnd();
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
        b2Joint *boxJoint = this->treeJoint.getJoint(joint);edkEnd();
        if(boxJoint){
            switch(boxJoint->GetType()){
            case e_revoluteJoint:
                //
            {
                b2RevoluteJoint* temp = (b2RevoluteJoint*)boxJoint;edkEnd();
                return temp->GetMaxMotorTorque() * this->percentOut;edkEnd();
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
        b2Joint *boxJoint = this->treeJoint.getJoint(joint);edkEnd();
        if(boxJoint){
            switch(boxJoint->GetType()){
            case e_revoluteJoint:
                //
            {
                b2RevoluteJoint* temp = (b2RevoluteJoint*)boxJoint;edkEnd();
                return temp->GetMotorSpeed() * this->percentOut;edkEnd();
            }
            default:
                break;
            }//end switch
        }
    }
    return 0.f;
}
//set the mouse target
bool edk::physics2D::World2D::setMouseJointTarget(edk::physics2D::MouseJoint2D* mouseJoint,edk::vec2f32 target){
    if(mouseJoint){
        //get the b2Jointt
        b2Joint *boxJoint = this->treeJoint.getJoint(mouseJoint);edkEnd();
        if(boxJoint){
            switch(boxJoint->GetType()){
            case e_mouseJoint:
                //
            {
                b2MouseJoint* temp = (b2MouseJoint*)boxJoint;edkEnd();
                temp->SetTarget(b2Vec2(target.x,target.y));edkEnd();
                return true;
            }
            default:
                break;
            }//end switch
        }
    }
    return false;
}
bool edk::physics2D::World2D::setMouseJointTarget(edk::physics2D::MouseJoint2D* mouseJoint,edk::float32 x,edk::float32 y){
    return this->setMouseJointTarget(mouseJoint,edk::vec2f32(x,y));edkEnd();
}

//contact functions
void edk::physics2D::World2D::contact2DBegin(edk::physics2D::Contact2D*){
    /*
    printf("\nWorld2D Begin Position %.2f %.2f"
           ,contact->worldPositions[0u].x
           ,contact->worldPositions[0u].y
           );edkEnd();
*/
}
void edk::physics2D::World2D::contact2DEnd(edk::physics2D::Contact2D*){
    /*
    printf("\nWorld2D End Position %.2f %.2f"
           ,contact->worldPositions[0u].x
           ,contact->worldPositions[0u].y
           );edkEnd();
*/
}
void edk::physics2D::World2D::contact2DKeepBegin(edk::physics2D::Contact2D*){
    /*
    printf("\nWorld2D Begin Keep Position %.2f %.2f"
           ,contact->worldPositions[0u].x
           ,contact->worldPositions[0u].y
           );edkEnd();
*/
}
void edk::physics2D::World2D::contact2DKeepEnd(edk::physics2D::Contact2D*){
    /*
    printf("\nWorld2D End Keep Position %.2f %.2f"
           ,contact->worldPositions[0u].x
           ,contact->worldPositions[0u].y
           );edkEnd();
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
        return this->treeCallbacks.add(callback);edkEnd();
    }
    return false;
}
bool edk::physics2D::World2D::removeContactCallback(edk::physics2D::ContactCallback2D* callback){
    //test the callback
    if(callback){
        //add the callback to the tree
        return this->treeCallbacks.remove(callback);edkEnd();
    }
    return false;
}

//XML
bool edk::physics2D::World2D::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"physWorld_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        if(xml->addSelectedNextChild("meter")){
                            if(xml->selectChild("meter")){
                                xml->setSelectedString(this->getMeterDistance());edkEnd();
                                xml->selectFather();edkEnd();
                            }
                        }
                        //WRITE
                        edk::physics2D::World2D::TreeObjectID treeIdStatic;edkEnd();
                        edk::physics2D::World2D::TreeObjectID treeIdDynamic;edkEnd();
                        edk::physics2D::World2D::TreeObjectID treeIdKinematic;edkEnd();
                        //save static objects
                        edk::uint32 size = 0u;edkEnd();
                        edk::physics2D::PhysicObject2D* object;edkEnd();
                        b2Body* body;edkEnd();
                        if(xml->addSelectedNextChild("static")){
                            if(xml->selectChild("static")){
                                size = this->treeStatic.size();edkEnd();
                                //save the objects
                                for(edk::uint32 i=0u;i<size;i++){
                                    body = this->treeStatic.getBodyInPosition(i);edkEnd();
                                    if(body){
                                        object = (edk::physics2D::PhysicObject2D*)body->GetUserData().pointer;edkEnd();
                                        if(object){
                                            object->writeToXML(xml,i,true);edkEnd();
                                            //add the if to the tree
                                            treeIdStatic.addObject(object,i);edkEnd();
                                        }
                                    }
                                }
                                xml->selectFather();edkEnd();
                            }
                        }
                        if(xml->addSelectedNextChild("dynamic")){
                            if(xml->selectChild("dynamic")){
                                size = this->treeDynamic.size();edkEnd();
                                //save the objects
                                for(edk::uint32 i=0u;i<size;i++){
                                    body = this->treeDynamic.getBodyInPosition(i);edkEnd();
                                    if(body){
                                        object = (edk::physics2D::PhysicObject2D*)body->GetUserData().pointer;edkEnd();
                                        if(object){
                                            object->writeToXML(xml,i,true);edkEnd();
                                            //add the if to the tree
                                            treeIdDynamic.addObject(object,i);edkEnd();
                                        }
                                    }
                                }
                                xml->selectFather();edkEnd();
                            }
                        }
                        if(xml->addSelectedNextChild("kinematic")){
                            if(xml->selectChild("kinematic")){
                                size = this->treeKinematic.size();edkEnd();
                                //save the objects
                                for(edk::uint32 i=0u;i<size;i++){
                                    body = this->treeKinematic.getBodyInPosition(i);edkEnd();
                                    if(body){
                                        object = (edk::physics2D::PhysicObject2D*)body->GetUserData().pointer;edkEnd();
                                        if(object){
                                            object->writeToXML(xml,i,true);edkEnd();
                                            //add the if to the tree
                                            treeIdKinematic.addObject(object,i);edkEnd();
                                        }
                                    }
                                }
                                xml->selectFather();edkEnd();
                            }
                        }
                        ret=true;edkEnd();
                        xml->selectFather();edkEnd();
                    }
                }
                delete[] name;edkEnd();
            }
            delete[] nameID;edkEnd();
        }
        return ret;
    }
    return false;
}
bool edk::physics2D::World2D::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"physWorld_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //READ
                    if(xml->selectChild("meter")){
                        this->setMeterDistance(xml->getSelectedStringAsFloat32());edkEnd();
                        xml->selectFather();edkEnd();
                    }
                    edk::physics2D::PhysicObject2D* object=NULL;edkEnd();
                    edk::uint32 i=0u;
                    if(xml->selectChild("static")){
                        do{
                            object = new edk::physics2D::PhysicObject2D;edkEnd();
                            if(object){
                                //read the object
                                if(object->readFromXML(xml,i)){
                                    //add the object
                                    if(!this->addObject(object)){
                                        //delete object
                                        delete object;edkEnd();
                                        object=NULL;edkEnd();
                                    }
                                }
                                else{
                                    //delete object
                                    delete object;edkEnd();
                                    object=NULL;edkEnd();
                                }
                            }
                        }while(object);edkEnd();
                        xml->selectFather();edkEnd();
                    }
                    if(xml->selectChild("dynamic")){
                        do{
                            object = new edk::physics2D::PhysicObject2D;edkEnd();
                            if(object){
                                //read the object
                                if(object->readFromXML(xml,i)){
                                    //add the object
                                    if(!this->addObject(object)){
                                        //delete object
                                        delete object;edkEnd();
                                        object=NULL;edkEnd();
                                    }
                                }
                                else{
                                    //delete object
                                    delete object;edkEnd();
                                    object=NULL;edkEnd();
                                }
                            }
                        }while(object);edkEnd();
                        xml->selectFather();edkEnd();
                    }
                    if(xml->selectChild("kimematic")){
                        do{
                            object = new edk::physics2D::PhysicObject2D;edkEnd();
                            if(object){
                                //read the object
                                if(object->readFromXML(xml,i)){
                                    //add the object
                                    if(!this->addObject(object)){
                                        //delete object
                                        delete object;edkEnd();
                                        object=NULL;edkEnd();
                                    }
                                }
                                else{
                                    //delete object
                                    delete object;edkEnd();
                                    object=NULL;edkEnd();
                                }
                            }
                        }while(object);edkEnd();
                        xml->selectFather();edkEnd();
                    }

                    ret=true;edkEnd();
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] nameID;edkEnd();
        }
        return ret;
    }
    return false;
}
