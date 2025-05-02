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

#if defined(EDK_USE_BOX2D)
edk::physics2D::World2D::MyContactListener::MyContactListener(){
    this->classThis=NULL;
    this->Constructor();
}
edk::physics2D::World2D::MyContactListener::MyContactListener(edk::physics2D::World2D* world){
    this->classThis=NULL;
    this->Constructor(world);
}
edk::physics2D::World2D::MyContactListener::~MyContactListener(){
    this->Destructor();
}

void edk::physics2D::World2D::MyContactListener::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;
        this->cleaningWorld=false;
        this->world = NULL;
    }
}
void edk::physics2D::World2D::MyContactListener::Constructor(edk::physics2D::World2D* world){
    if(this->classThis!=this){
        this->classThis=this;
        this->cleaningWorld=false;
        this->world = world;
    }
}
void edk::physics2D::World2D::MyContactListener::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
}

void edk::physics2D::World2D::MyContactListener::BeginContact(b2Contact* contact){
    if(this->cleaningWorld){

        return;
    }

    //printf("\nContact Begin %u"
    //       ,contact
    //       );

    //en begin the contact will really be enabled
    contact->SetReallyEnabled(true);
    b2Body* bodyA = contact->GetFixtureA()->GetBody();
    b2Body* bodyB = contact->GetFixtureB()->GetBody();

    //test if have the One of the Bodys in treeRemove
    if(this->world->treeDeleted.haveElement((edk::physics2D::PhysicObject2D*)bodyA->GetUserData().pointer)
            ||
            this->world->treeDeleted.haveElement((edk::physics2D::PhysicObject2D*)bodyB->GetUserData().pointer)
            ){
        //disable the contact
        contact->SetEnabled(false);
        contact->SetReallyEnabled(false);
        return;
    }

    edk::uint64 shapeA = (edk::uint64)contact->GetFixtureA()->GetUserData().pointer;
    edk::uint64 shapeB = (edk::uint64)contact->GetFixtureB()->GetUserData().pointer;
    edk::uint8 count = contact->GetManifold()->pointCount;
    if(count){
        //get the contact
        edk::physics2D::Contact2D* contactTemp = this->world->treeConcacts.getContact(contact,bodyA,bodyB);
        if(!contactTemp){
            contactTemp = this->world->treeSensorConcacts.getContact(contact,bodyA,bodyB);
        }

        //test if the two objecs are on the same group
        edk::physics2D::PhysicObject2D* objectA = (edk::physics2D::PhysicObject2D*)bodyA->GetUserData().pointer;
        edk::physics2D::PhysicObject2D* objectB = (edk::physics2D::PhysicObject2D*)bodyB->GetUserData().pointer;

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
                contactTemp = new edk::physics2D::Contact2D(contact,bodyA,bodyB);
                if(objectA->isSensor() || objectB->isSensor()){
                    //add the contactTemp on the tree
                    if(!this->world->treeSensorConcacts.add(contactTemp)){
                        //delete contactTemp
                        delete contactTemp;
                        contactTemp=NULL;
                    }
                }
                else{
                    //add the contactTemp on the tree
                    if(!this->world->treeConcacts.add(contactTemp)){
                        //delete contactTemp
                        delete contactTemp;
                        contactTemp=NULL;
                    }
                }
            }
            else{
                contactTemp->enableContact();
            }
            if(contactTemp){
                //update the values
                contactTemp->objectA = (edk::physics2D::PhysicObject2D*)bodyA->GetUserData().pointer;
                contactTemp->objectB = (edk::physics2D::PhysicObject2D*)bodyB->GetUserData().pointer;
                contactTemp->shapeA = shapeA;
                contactTemp->shapeB = shapeB;
                //
                contactTemp->objectA->setLinearVelocity(bodyA->GetLinearVelocity().x * this->percentOut,bodyA->GetLinearVelocity().y * this->percentOut);
                contactTemp->objectA->setAngularVelocity(bodyA->GetAngularVelocity() * (180.f / b2_pi));
                contactTemp->objectB->setLinearVelocity(bodyB->GetLinearVelocity().x * this->percentOut,bodyB->GetLinearVelocity().y * this->percentOut);
                contactTemp->objectB->setAngularVelocity(bodyB->GetAngularVelocity() * (180.f / b2_pi));
                contactTemp->velocityA = contactTemp->objectA->getSpeed();
                contactTemp->velocityB = contactTemp->objectB->getSpeed();
                contactTemp->objectAWorldPosition.x = bodyA->GetPosition().x;
                contactTemp->objectAWorldPosition.y = bodyA->GetPosition().y;
                contactTemp->objectAWorldAngle = bodyA->GetAngle();
                contactTemp->objectBWorldPosition.x = bodyB->GetPosition().x;
                contactTemp->objectBWorldPosition.y = bodyB->GetPosition().y;
                contactTemp->objectBWorldAngle = bodyB->GetAngle();
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
                    contactTemp->worldPositions.set(i,edk::vec2f32(point.x * this->percentOut,point.y * this->percentOut));

                    //get objectA position
                    vertex = edk::Math::rotatePlus(contactTemp->worldPositions.get(i)-contactTemp->objectA->position,
                                                   contactTemp->objectA->angle * -1.f
                                                   );
                    if(contactTemp->objectA->size.width){
                        vertex.x/=contactTemp->objectA->size.width;
                    }
                    if(contactTemp->objectA->size.height){
                        vertex.y/=contactTemp->objectA->size.height;
                    }
                    contactTemp->objectAPositions.set(i,vertex);
                    //get objectB position
                    vertex = edk::Math::rotatePlus(contactTemp->worldPositions.get(i)-contactTemp->objectB->position,
                                                   contactTemp->objectB->angle * -1.f
                                                   );
                    if(contactTemp->objectB->size.width){
                        vertex.x/=contactTemp->objectB->size.width;
                    }
                    if(contactTemp->objectB->size.height){
                        vertex.y/=contactTemp->objectB->size.height;
                    }
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
                    contact->SetEnabled(false);
                    contact->SetReallyEnabled(false);
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
                    contact->SetEnabled(false);
                    contact->SetReallyEnabled(false);
                }
                //Test if the lineA collide in one side
                else if(contactTemp->objectA->physicMesh.selectedIsLine()){
                    if(!contactTemp->objectB->physicMesh.selectedIsLine()){
                        //just test if the object is up the contact
                        switch(contactTemp->objectA->physicMesh.selectedGetCollisionID()){
                        case edk::shape::collisionUP:
                            if(contactTemp->objectB->position.y>=contactTemp->worldPositions.get(0u).y){
                                this->world->physicsContactBegin(contactTemp);
                                if(!contactTemp->isEnabled()){
                                    contact->SetEnabled(false);
                                    contact->SetReallyEnabled(false);
                                }
                            }
                            else{
                                if(this->world->treeConcacts.remove((contactTemp))
                                        || this->world->treeSensorConcacts.remove((contactTemp))
                                        ){
                                    delete (contactTemp);
                                }
                            }
                            break;
                        case edk::shape::collisionDOWN:
                            if(contactTemp->objectB->position.y<contactTemp->worldPositions.get(0u).y){
                                this->world->physicsContactBegin(contactTemp);
                                if(!contactTemp->isEnabled()){
                                    contact->SetEnabled(false);
                                    contact->SetReallyEnabled(false);
                                }
                            }
                            else{
                                if(this->world->treeConcacts.remove((contactTemp))
                                        || this->world->treeSensorConcacts.remove((contactTemp))
                                        ){
                                    delete (contactTemp);
                                }
                            }
                            break;
                        default:
                            this->world->physicsContactBegin(contactTemp);
                            if(!contactTemp->isEnabled()){
                                contact->SetEnabled(false);
                                contact->SetReallyEnabled(false);
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
                            if(contactTemp->objectA->position.y>=contactTemp->worldPositions.get(0u).y){
                                this->world->physicsContactBegin(contactTemp);
                                if(!contactTemp->isEnabled()){
                                    contact->SetEnabled(false);
                                    contact->SetReallyEnabled(false);
                                }
                            }
                            else{
                                if(this->world->treeConcacts.remove((contactTemp))
                                        || this->world->treeSensorConcacts.remove((contactTemp))
                                        ){
                                    delete (contactTemp);
                                }
                            }
                            break;
                        case edk::shape::collisionDOWN:
                            if(contactTemp->objectA->position.y<contactTemp->worldPositions.get(0u).y){
                                this->world->physicsContactBegin(contactTemp);
                                if(!contactTemp->isEnabled()){
                                    contact->SetEnabled(false);
                                    contact->SetReallyEnabled(false);
                                }
                            }
                            else{
                                if(this->world->treeConcacts.remove((contactTemp))
                                        || this->world->treeSensorConcacts.remove((contactTemp))
                                        ){
                                    delete (contactTemp);
                                }
                            }
                            break;
                        default:
                            this->world->physicsContactBegin(contactTemp);
                            if(!contactTemp->isEnabled()){
                                contact->SetEnabled(false);
                                contact->SetReallyEnabled(false);
                            }
                            break;
                        }
                    }
                }
                else{
                    //this->world->contactbegin(contactTemp);
                    this->world->physicsContactBegin(contactTemp);
                    if(!contactTemp->isEnabled()){
                        contact->SetEnabled(false);
                        contact->SetReallyEnabled(false);
                    }
                }
            }
        }
        else{
            if(contactTemp){
                if(this->world->treeConcacts.remove((contactTemp))
                        || this->world->treeSensorConcacts.remove((contactTemp))
                        ){
                    delete (contactTemp);
                }
            }
        }
    }

}
#endif


#if defined(EDK_USE_BOX2D)
void edk::physics2D::World2D::MyContactListener::EndContact(b2Contact* contact){
    if(this->cleaningWorld){

        return;
    }

    //printf("\nContact END %u"
    //       ,contact
    //       );

    //find contact
    b2Body* bodyA = contact->GetFixtureA()->GetBody();
    b2Body* bodyB = contact->GetFixtureB()->GetBody();

    //test if have the One of the Bodys in treeRemove
    if(this->world->treeDeleted.haveElement((edk::physics2D::PhysicObject2D*)bodyA->GetUserData().pointer)
            ||
            this->world->treeDeleted.haveElement((edk::physics2D::PhysicObject2D*)bodyB->GetUserData().pointer)
            ){
        //remove from sensors tree
        edk::physics2D::Contact2D* contactTemp = this->world->treeConcacts.getContact(contact,bodyA,bodyB);
        if(!contactTemp){
            contactTemp = this->world->treeSensorConcacts.getContact(contact,bodyA,bodyB);
        }
        if(contactTemp){
            //disable the contact
            contact->SetEnabled(false);
            contact->SetReallyEnabled(false);
            //remove contactTemp from the tree
            this->world->treeConcacts.remove(contactTemp);
            this->world->treeSensorConcacts.remove(contactTemp);
            //delete contactTemp
            delete contactTemp;
        }
        return;
    }

    edk::physics2D::Contact2D* contactTemp = this->world->treeConcacts.getContact(contact,bodyA,bodyB);
    if(!contactTemp){
        contactTemp = this->world->treeSensorConcacts.getContact(contact,bodyA,bodyB);
    }
    if(contactTemp){
        contactTemp->objectA->setLinearVelocity(bodyA->GetLinearVelocity().x * this->percentOut,bodyA->GetLinearVelocity().y * this->percentOut);
        contactTemp->objectA->setAngularVelocity(bodyA->GetAngularVelocity() * (180.f / b2_pi));
        contactTemp->objectB->setLinearVelocity(bodyB->GetLinearVelocity().x * this->percentOut,bodyB->GetLinearVelocity().y * this->percentOut);
        contactTemp->objectB->setAngularVelocity(bodyB->GetAngularVelocity() * (180.f / b2_pi));
        contactTemp->velocityA = contactTemp->objectA->getSpeed();
        contactTemp->velocityB = contactTemp->objectB->getSpeed();
        contactTemp->objectAWorldPosition.x = bodyA->GetPosition().x;
        contactTemp->objectAWorldPosition.y = bodyA->GetPosition().y;
        contactTemp->objectAWorldAngle = bodyA->GetAngle();
        contactTemp->objectBWorldPosition.x = bodyB->GetPosition().x;
        contactTemp->objectBWorldPosition.y = bodyB->GetPosition().y;
        contactTemp->objectBWorldAngle = bodyB->GetAngle();
        //update the positions
        edk::uint8 count = contact->GetManifold()->pointCount;
        b2Vec2 point;
        edk::vec2f32 vertex;
        b2WorldManifold worldManifold;
        contact->GetWorldManifold(&worldManifold);

        for(edk::uint32 i=0u;i<count;i++){
            //copy the point to the worldPosition

            point = worldManifold.points[i];
            contactTemp->worldPositions.set(i,edk::vec2f32(point.x * this->percentOut,point.y * this->percentOut));

            //get objectA position
            vertex = edk::Math::rotatePlus(contactTemp->worldPositions.get(i)-contactTemp->objectA->position,
                                           contactTemp->objectA->angle * -1.f
                                           );
            if(contactTemp->objectA->size.width){
                vertex.x/=contactTemp->objectA->size.width;
            }
            if(contactTemp->objectA->size.height){
                vertex.y/=contactTemp->objectA->size.height;
            }
            contactTemp->objectAPositions.set(i,vertex);
            //get objectB position
            vertex = edk::Math::rotatePlus(contactTemp->worldPositions.get(i)-contactTemp->objectB->position,
                                           contactTemp->objectB->angle * -1.f
                                           );
            if(contactTemp->objectB->size.width){
                vertex.x/=contactTemp->objectB->size.width;
            }
            if(contactTemp->objectB->size.height){
                vertex.y/=contactTemp->objectB->size.height;
            }
            contactTemp->objectBPositions.set(i,vertex);
        }

        //process the contactEnd

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
            contact->SetEnabled(false);
            contact->SetReallyEnabled(false);
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
            contact->SetEnabled(false);
            contact->SetReallyEnabled(false);
        }
        else{
            //this->world->contactEnd(contactTemp);
            this->world->physicsContactEnd(contactTemp);
            if(!contactTemp->isEnabled()){
                contact->SetEnabled(false);
                contact->SetReallyEnabled(false);
            }
        }

        //remove contactTemp from the tree
        this->world->treeConcacts.remove(contactTemp);
        this->world->treeSensorConcacts.remove(contactTemp);
        //delete contactTemp
        delete contactTemp;
    }
}
#endif


#if defined(EDK_USE_BOX2D)

void edk::physics2D::World2D::MyContactListener::PreSolve(b2Contact* contact, const b2Manifold*){
    if(this->cleaningWorld){

        return;
    }

    //printf("\nContact PreSolve %u"
    //       ,contact
    //       );

    //find contact
    b2Body* bodyA = contact->GetFixtureA()->GetBody();
    b2Body* bodyB = contact->GetFixtureB()->GetBody();

    //test if have the One of the Bodys in treeRemove
    if(this->world->treeDeleted.haveElement((edk::physics2D::PhysicObject2D*)bodyA->GetUserData().pointer)
            ||
            this->world->treeDeleted.haveElement((edk::physics2D::PhysicObject2D*)bodyB->GetUserData().pointer)
            ){
        //disable the contact
        contact->SetEnabled(false);
        contact->SetReallyEnabled(false);
        return;
    }

    edk::physics2D::Contact2D* contactTemp = this->world->treeConcacts.getContact(contact,bodyA,bodyB);
    if(!contactTemp){
        contactTemp = this->world->treeSensorConcacts.getContact(contact,bodyA,bodyB);
    }
    if(contactTemp){
        if(!contactTemp->isEnabled()){
            contact->SetEnabled(false);
            contact->SetReallyEnabled(false);
            return;
        }
        contactTemp->objectA->setLinearVelocity(bodyA->GetLinearVelocity().x * this->percentOut,bodyA->GetLinearVelocity().y * this->percentOut);
        contactTemp->objectA->setAngularVelocity(bodyA->GetAngularVelocity() * (180.f / b2_pi));
        contactTemp->objectB->setLinearVelocity(bodyB->GetLinearVelocity().x * this->percentOut,bodyB->GetLinearVelocity().y * this->percentOut);
        contactTemp->objectB->setAngularVelocity(bodyB->GetAngularVelocity() * (180.f / b2_pi));
        contactTemp->velocityA = contactTemp->objectA->getSpeed();
        contactTemp->velocityB = contactTemp->objectB->getSpeed();
        contactTemp->objectAWorldPosition.x = bodyA->GetPosition().x;
        contactTemp->objectAWorldPosition.y = bodyA->GetPosition().y;
        contactTemp->objectAWorldAngle = bodyA->GetAngle();
        contactTemp->objectBWorldPosition.x = bodyB->GetPosition().x;
        contactTemp->objectBWorldPosition.y = bodyB->GetPosition().y;
        contactTemp->objectBWorldAngle = bodyB->GetAngle();
        //update the positions
        edk::uint8 count = contact->GetManifold()->pointCount;
        b2Vec2 point;
        edk::vec2f32 vertex;
        b2WorldManifold worldManifold;
        contact->GetWorldManifold(&worldManifold);
        for(edk::uint32 i=0u;i<count;i++){
            //copy the point to the worldPosition

            point = worldManifold.points[i];
            contactTemp->worldPositions.set(i,edk::vec2f32(point.x * this->percentOut,point.y * this->percentOut));

            //get objectA position
            vertex = edk::Math::rotatePlus(contactTemp->worldPositions.get(i)-contactTemp->objectA->position,
                                           contactTemp->objectA->angle * -1.f
                                           );
            if(contactTemp->objectA->size.width){
                vertex.x/=contactTemp->objectA->size.width;
            }
            if(contactTemp->objectA->size.height){
                vertex.y/=contactTemp->objectA->size.height;
            }
            contactTemp->objectAPositions.set(i,vertex);
            //get objectB position
            vertex = edk::Math::rotatePlus(contactTemp->worldPositions.get(i)-contactTemp->objectB->position,
                                           contactTemp->objectB->angle * -1.f
                                           );
            if(contactTemp->objectB->size.width){
                vertex.x/=contactTemp->objectB->size.width;
            }
            if(contactTemp->objectB->size.height){
                vertex.y/=contactTemp->objectB->size.height;
            }
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
                contact->SetReallyEnabled(false);
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
                contact->SetReallyEnabled(false);
            }
            else{
                //this->world->contactKeepBegin(contactTemp);
                this->world->physicsContactKeepBegin(contactTemp);
                if(!contactTemp->isEnabled()){
                    contact->SetEnabled(false);
                    contact->SetReallyEnabled(false);
                }
            }
        }
        else{
            contact->SetEnabled(false);
            contact->SetReallyEnabled(false);
        }
    }
    else{
        contact->SetEnabled(false);
        contact->SetReallyEnabled(false);
    }
}

#endif



#if defined(EDK_USE_BOX2D)
void edk::physics2D::World2D::MyContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse){
    if(this->cleaningWorld){

        return;
    }

    //printf("\nContact PostSolve impulses %u tangent %.2f normal %.2f"
    //       ,impulse->count
    //       ,impulse->tangentImpulses[0u]
    //       ,impulse->normalImpulses[0u]
    //       );

    //find contact
    b2Body* bodyA = contact->GetFixtureA()->GetBody();
    b2Body* bodyB = contact->GetFixtureB()->GetBody();

    //test if have the One of the Bodys in treeRemove
    if(this->world->treeDeleted.haveElement((edk::physics2D::PhysicObject2D*)bodyA->GetUserData().pointer)
            ||
            this->world->treeDeleted.haveElement((edk::physics2D::PhysicObject2D*)bodyB->GetUserData().pointer)
            ){
        //remove from sensors tree
        edk::physics2D::Contact2D* contactTemp = this->world->treeConcacts.getContact(contact,bodyA,bodyB);
        if(!contactTemp){
            contactTemp = this->world->treeSensorConcacts.getContact(contact,bodyA,bodyB);
        }
        if(contactTemp){
            //disable the contact
            contact->SetEnabled(false);
            contact->SetReallyEnabled(false);
            //remove contactTemp from the tree
            this->world->treeConcacts.remove(contactTemp);
            this->world->treeSensorConcacts.remove(contactTemp);
            //delete contactTemp
            delete contactTemp;
        }
        return;
    }

    edk::physics2D::Contact2D* contactTemp = this->world->treeConcacts.getContact(contact,bodyA,bodyB);
    if(!contactTemp){
        contactTemp = this->world->treeSensorConcacts.getContact(contact,bodyA,bodyB);
    }
    if(contactTemp){
        contactTemp->objectA->setLinearVelocity(bodyA->GetLinearVelocity().x * this->percentOut,bodyA->GetLinearVelocity().y * this->percentOut);
        contactTemp->objectA->setAngularVelocity(bodyA->GetAngularVelocity() * (180.f / b2_pi));
        contactTemp->objectB->setLinearVelocity(bodyB->GetLinearVelocity().x * this->percentOut,bodyB->GetLinearVelocity().y * this->percentOut);
        contactTemp->objectB->setAngularVelocity(bodyB->GetAngularVelocity() * (180.f / b2_pi));
        contactTemp->velocityA = contactTemp->objectA->getSpeed();
        contactTemp->velocityB = contactTemp->objectB->getSpeed();
        contactTemp->objectAWorldPosition.x = bodyA->GetPosition().x;
        contactTemp->objectAWorldPosition.y = bodyA->GetPosition().y;
        contactTemp->objectAWorldAngle = bodyA->GetAngle();
        contactTemp->objectBWorldPosition.x = bodyB->GetPosition().x;
        contactTemp->objectBWorldPosition.y = bodyB->GetPosition().y;
        contactTemp->objectBWorldAngle = bodyB->GetAngle();
        //update the positions
        edk::uint8 count = contact->GetManifold()->pointCount;
        b2Vec2 point;
        edk::vec2f32 vertex;
        b2WorldManifold worldManifold;
        contact->GetWorldManifold(&worldManifold);

        for(edk::uint32 i=0u;i<count;i++){
            //copy the point to the worldPosition

            point = worldManifold.points[i];
            contactTemp->worldPositions.set(i,edk::vec2f32(point.x * this->percentOut,point.y * this->percentOut));

            //get objectA position
            vertex = edk::Math::rotatePlus(contactTemp->worldPositions.get(i)-contactTemp->objectA->position,
                                           contactTemp->objectA->angle * -1.f
                                           );
            if(contactTemp->objectA->size.width){
                vertex.x/=contactTemp->objectA->size.width;
            }
            if(contactTemp->objectA->size.height){
                vertex.y/=contactTemp->objectA->size.height;
            }
            contactTemp->objectAPositions.set(i,vertex);
            //get objectB position
            vertex = edk::Math::rotatePlus(contactTemp->worldPositions.get(i)-contactTemp->objectB->position,
                                           contactTemp->objectB->angle * -1.f
                                           );
            if(contactTemp->objectB->size.width){
                vertex.x/=contactTemp->objectB->size.width;
            }
            if(contactTemp->objectB->size.height){
                vertex.y/=contactTemp->objectB->size.height;
            }
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
                if(!contactTemp->isEnabled()){
                    contact->SetEnabled(false);
                    contact->SetReallyEnabled(false);
                }
            }
        }
    }
}
#endif


#if defined(EDK_USE_BOX2D)
#endif


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
bool edk::physics2D::World2D::ObjectsJointsTree::firstBiggerSecond(edk::physics2D::World2D::ObjectJointsTree* first,
                                                                   edk::physics2D::World2D::ObjectJointsTree* second
                                                                   ){
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
bool edk::physics2D::World2D::ObjectsJointsTree::firstEqualSecond(edk::physics2D::World2D::ObjectJointsTree* first,
                                                                  edk::physics2D::World2D::ObjectJointsTree* second
                                                                  ){
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

edk::physics2D::World2D::World2D():
    #if defined(EDK_USE_BOX2D)
    world(b2Vec2(0,0)),treeStatic(),treeKinematic(),treeDynamic()
  ,treeDeleted(&this->world,this),
    #endif
    treeNew(this),treeLinearVelocity(this)
  ,treeAngularVelocity(this),treeConcacts(),treeSensorConcacts()
  #if defined(EDK_USE_BOX2D)
  ,contacts(this)
  #endif
{
    this->classThis=NULL;
    this->Constructor();
}
edk::physics2D::World2D::~World2D(){
    this->Destructor();
}

void edk::physics2D::World2D::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        this->clock.Constructor();
        this->beginContacs.Constructor();
        this->keepBeginContacs.Constructor();
        this->keepEndContacs.Constructor();
        this->endContacs.Constructor();
        this->sensorBeginContacs.Constructor();
        this->sensorKeepContacs.Constructor();
        this->sensorEndContacs.Constructor();
        this->treeCallbacks.Constructor();
#if defined(EDK_USE_BOX2D)
        this->treeStatic.Constructor();
        this->treeKinematic.Constructor();
        this->treeDynamic.Constructor();
        this->treeDeleted.Constructor(&this->world,this);
#endif
        this->treeNew.Constructor(this);
        this->treeLinearVelocity.Constructor(this);
        this->treeAngularVelocity.Constructor(this);
        this->treeConcacts.Constructor();
        this->treeSensorConcacts.Constructor();
#if defined(EDK_USE_BOX2D)
        this->contacts.Constructor(this);
        this->treeJoint.Constructor();
#endif
        this->treeJointObjects.Constructor();

        this->setMeterDistance(1.f);
        //set the initial gravity
        this->setGravity(edk::vec2f32(0.f,-9.8f));

#if defined(EDK_USE_BOX2D)
        this->world.SetContactListener(&this->contacts);
#endif

        this->clockStart();
        this->clockScale=1.f;

        this->runNextStep=false;
        this->paused=false;
    }
}
void edk::physics2D::World2D::Destructor(){
    if(this->classThis==this){
        edk::uint32 size = 0u;
#if defined(EDK_USE_BOX2D)
        b2Body* body=NULL;
        this->contacts.cleaningWorld=true;
#endif

        this->beginContacs.cleanContacts();
        this->keepBeginContacs.cleanContacts();
        this->keepEndContacs.cleanContacts();
        this->endContacs.cleanContacts();
        this->sensorBeginContacs.cleanContacts();
        this->sensorKeepContacs.cleanContacts();
        this->sensorEndContacs.cleanContacts();

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

        size = this->treeSensorConcacts.getSize();
        for(edk::uint32 i=0u;i<size;i++){
            edk::physics2D::Contact2D* temp = this->treeSensorConcacts.getElementInPosition(i);
            if(temp){
                delete temp;
            }
        }
        this->treeSensorConcacts.clean();

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
#if defined(EDK_USE_BOX2D)
        //destroy joints
        size = this->treeJoint.size();
        b2Joint *joint;
        edk::physics2D::Joint2D* edkJoint;
        for(edk::uint32 i=0u;i<size;i++){
            joint = this->treeJoint.getB2JointInPosition(i);
            if(joint){
                edkJoint = (edk::physics2D::Joint2D*)joint->GetUserData().pointer;
                this->world.DestroyJoint(joint);
                if(edkJoint){
                    delete edkJoint;
                }
            }
        }
        this->treeJoint.clean();

        //destroy static
        size = this->treeStatic.size();
        for(edk::uint32 i=0u;i<size;i++){
            body = this->treeStatic.getBodyInPosition(i);
            if(body){
                if(this->runNextStep){
                    //save the object on the deleted tree
                    //body->GetUserData().pointer = 0;
                    this->treeDeleted.add((edk::physics2D::PhysicObject2D*)body->GetUserData().pointer);
                }
                else{
                    this->world.DestroyBody(body);
                }
            }
        }
        this->treeStatic.clean();
        //destroy kinematic
        size = this->treeKinematic.size();
        for(edk::uint32 i=0u;i<size;i++){
            body = this->treeKinematic.getBodyInPosition(i);
            if(body){
                if(this->runNextStep){
                    //save the object on the deleted tree
                    //body->GetUserData().pointer = 0;
                    this->treeDeleted.add((edk::physics2D::PhysicObject2D*)body->GetUserData().pointer);
                }
                else{
                    this->world.DestroyBody(body);
                }
            }
        }
        this->treeKinematic.clean();
        //destroy dynamic
        size = this->treeDynamic.size();
        for(edk::uint32 i=0u;i<size;i++){
            body = this->treeDynamic.getBodyInPosition(i);
            if(body){
                if(this->runNextStep){
                    //save the object on the deleted tree
                    //body->GetUserData().pointer = 0;
                    this->treeDeleted.add((edk::physics2D::PhysicObject2D*)body->GetUserData().pointer);
                }
                else{
                    this->world.DestroyBody(body);
                }
            }
        }
        this->treeDynamic.clean();
#endif

        this->clock.Destructor();
        this->beginContacs.Destructor();
        this->keepBeginContacs.Destructor();
        this->keepEndContacs.Destructor();
        this->endContacs.Destructor();
        this->sensorBeginContacs.Destructor();
        this->sensorKeepContacs.Destructor();
        this->sensorEndContacs.Destructor();
        this->treeCallbacks.Destructor();
#if defined(EDK_USE_BOX2D)
        this->treeStatic.Destructor();
        this->treeKinematic.Destructor();
        this->treeDynamic.Destructor();
        this->treeDeleted.Destructor();
#endif
        this->treeNew.Destructor();
        this->treeLinearVelocity.Destructor();
        this->treeAngularVelocity.Destructor();
        this->treeConcacts.Destructor();
        this->treeSensorConcacts.Destructor();
#if defined(EDK_USE_BOX2D)
        this->contacts.Destructor();
        this->treeJoint.Destructor();
#endif
        this->treeJointObjects.Destructor();
    }
}

#if defined(EDK_USE_BOX2D)
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
        case edk::TypeObject2DStatic:
            return this->treeStatic.getBody(object);
            //break;
        case edk::TypeObject2DKinematic:
            return this->treeKinematic.getBody(object);
            //break;
        case edk::TypeObject2DDynamic:
            return this->treeDynamic.getBody(object);
            //break;
        default:
            break;
        }
    }
    return NULL;
}
#endif

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
        #if defined(EDK_USE_BOX2D)
                                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
        #else
                                            0.f
        #endif
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
#if defined(EDK_USE_BOX2D)
            b2Joint* boxJoint = NULL;
#endif
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
                    if(object!=objectJointsATemp->getPointerA()){
                        objectTemp=objectJointsATemp->getPointerA();
                    }
                    else{
                        if(object!=objectJointsATemp->getPointerB()){
                            objectTemp=objectJointsATemp->getPointerB();
                        }
                    }
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

#if defined(EDK_USE_BOX2D)
                                        //remove joint from box2D
                                        boxJoint = this->treeJoint.getJoint(joint);
                                        if(boxJoint){
                                            this->treeJoint.removeJoint(boxJoint);
                                            //destroy the joint
                                            this->world.DestroyJoint(boxJoint);
                                            boxJoint=NULL;
                                        }
#endif

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

#if defined(EDK_USE_BOX2D)
                            boxJoint = this->treeJoint.getJoint(joint);
                            if(boxJoint){
                                this->treeJoint.removeJoint(boxJoint);
                                //destroy the joint
                                this->world.DestroyJoint(boxJoint);
                                boxJoint=NULL;
                            }
#endif

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
    //test if have this objects in the tree
    if(!this->beginContacs.haveContact(contact->objectA,contact->objectB)){
        //add the new contact into the tree
        this->beginContacs.addContact(contact->objectA,contact->objectB);
    }
    else{
        //else set the contact to aready have it
        contact->areadyContacted=true;
    }

    this->contact2DBegin(contact);
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->contact2DBegin(contact);
    }
}
void edk::physics2D::World2D::physicsContactEnd(edk::physics2D::Contact2D* contact){
    //test if have this objects in the tree
    if(!this->endContacs.haveContact(contact->objectA,contact->objectB)){
        //add the new contact into the tree
        this->endContacs.addContact(contact->objectA,contact->objectB);
    }
    else{
        //else set the contact to aready have it
        contact->areadyContacted=true;
    }

    this->contact2DEnd(contact);
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->contact2DEnd(contact);
    }
}
void edk::physics2D::World2D::physicsContactKeepBegin(edk::physics2D::Contact2D* contact){
    //test if have this objects in the tree
    if(!this->keepBeginContacs.haveContact(contact->objectA,contact->objectB)){
        //add the new contact into the tree
        this->keepBeginContacs.addContact(contact->objectA,contact->objectB);
    }
    else{
        //else set the contact to aready have it
        contact->areadyContacted=true;
    }

    this->contact2DKeepBegin(contact);
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->contact2DKeepBegin(contact);
    }
}
void edk::physics2D::World2D::physicsContactKeepEnd(edk::physics2D::Contact2D* contact){
    //test if have this objects in the tree
    if(!this->keepEndContacs.haveContact(contact->objectA,contact->objectB)){
        //add the new contact into the tree
        this->keepEndContacs.addContact(contact->objectA,contact->objectB);
    }
    else{
        //else set the contact to aready have it
        contact->areadyContacted=true;
    }

    this->contact2DKeepEnd(contact);
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->contact2DKeepEnd(contact);
    }
}
//contact sensors
void edk::physics2D::World2D::physicsSensorBegin(edk::physics2D::Contact2D* contact){
    //test if have this objects in the tree
    if(!this->sensorBeginContacs.haveContact(contact->objectA,contact->objectB)){
        //add the new contact into the tree
        this->sensorBeginContacs.addContact(contact->objectA,contact->objectB);
    }
    else{
        //else set the contact to aready have it
        contact->areadyContacted=true;
    }

    this->sensor2DBegin(contact);
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->sensor2DBegin(contact);
    }
}
void edk::physics2D::World2D::physicsSensorEnd(edk::physics2D::Contact2D* contact){
    //test if have this objects in the tree
    if(!this->sensorEndContacs.haveContact(contact->objectA,contact->objectB)){
        //add the new contact into the tree
        this->sensorEndContacs.addContact(contact->objectA,contact->objectB);
    }
    else{
        //else set the contact to aready have it
        contact->areadyContacted=true;
    }

    this->sensor2DEnd(contact);
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->sensor2DEnd(contact);
    }
}
void edk::physics2D::World2D::physicsSensorKeeping(edk::physics2D::Contact2D* contact){
    //test if have this objects in the tree
    if(!this->sensorKeepContacs.haveContact(contact->objectA,contact->objectB)){
        //add the new contact into the tree
        this->sensorKeepContacs.addContact(contact->objectA,contact->objectB);
    }
    else{
        //else set the contact to aready have it
        contact->areadyContacted=true;
    }

    this->sensor2DKeeping(contact);
    //run the callbacks
    edk::uint32 size = this->treeCallbacks.size();
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->sensor2DKeeping(contact);
    }
}

//Set the gravity
void edk::physics2D::World2D::setGravity(edk::vec2f32 gravity){
    this->gravity=gravity * this->percentIn;
    //update the world gravity
#if defined(EDK_USE_BOX2D)
    this->world.SetGravity(b2Vec2(this->gravity.x,this->gravity.y));
#endif
}
void edk::physics2D::World2D::setGravity(edk::float32 x,edk::float32 y){
    this->setGravity(edk::vec2f32 (x,y));
}
//set the percent
void edk::physics2D::World2D::setMeterDistance(edk::float32 meter){
    //
    this->percentOut = meter;
    this->percentIn = 1/this->percentOut;

#if defined(EDK_USE_BOX2D)
    //update the tree's
    this->contacts.percentIn = this->percentIn;
    this->contacts.percentOut = this->percentOut;
    treeStatic.percentIn = this->percentIn;
    treeStatic.percentOut = this->percentOut;
    treeKinematic.percentIn = this->percentIn;
    treeKinematic.percentOut = this->percentOut;
    treeDynamic.percentIn = this->percentIn;
    treeDynamic.percentOut = this->percentOut;
#endif
}
void edk::physics2D::World2D::setMeterDistance(edk::uint8 meter){
    return this->setMeterDistance((edk::float32)meter);
}
void edk::physics2D::World2D::setMeterDistance(edk::uint16 meter){
    return this->setMeterDistance((edk::float32)meter);
}
void edk::physics2D::World2D::setMeterDistance(edk::uint32 meter){
    return this->setMeterDistance((edk::float32)meter);
}
void edk::physics2D::World2D::setMeterDistance(edk::uint64 meter){
    return this->setMeterDistance((edk::float32)meter);
}
edk::float32 edk::physics2D::World2D::getMeterDistance(){
    return this->percentOut;
}

//Add a Object to the world
bool edk::physics2D::World2D::addObject(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        bool ret=true;

        //test if is running the simulation
        if(this->runNextStep){
            //then add the object in to a tree to be added after the nextStep
            this->treeNew.add(object);
            return ret;
        }

#if defined(EDK_USE_BOX2D)
        //create the box2D object
        b2BodyDef objectDef;

        //b2_staticBody
        //b2_kinematicBody
        //b2_dynamicBody

        switch(object->getType()){
        case edk::TypeObject2DStatic:
            objectDef.type = b2_staticBody;
            break;
        case edk::TypeObject2DKinematic:
            objectDef.type = b2_kinematicBody;
            break;
        case edk::TypeObject2DDynamic:
            objectDef.type = b2_dynamicBody;
            break;
        default:
            objectDef.type = (b2BodyType)-1;
            break;
        }

        objectDef.fixedRotation=object->fixedRotation;

        //In the new version of box2D the userData will be setted in objectDef
        objectDef.userData.pointer = (uintptr_t)object;

        //objectDef.fixedRotation = false;

        b2Body* objectBody = this->world.CreateBody(&objectDef);
        if(objectBody){
            objectBody->SetTransform( b2Vec2(object->position.x*this->percentIn,object->position.y*this->percentIn),object->angle / (180.f / b2_pi) );

            //objectBody->SetUserData(object);
            //update the set user data in bodyDef for the new box2D version
            //read the polygons
            edk::uint32 size = object->physicMesh.getPolygonSize();
            if(size){
                b2Vec2 vertexs[b2_maxPolygonVertices];
                ret=false;
#if _WIN64 || __x86_64__ || __ppc64__
#if defined(edkCPPversion17)
                for(edk::uint64 i=0u;i<size;i++){
#else
                for(register edk::uint64 i=0u;i<size;i++){
#endif
#else
#if defined(edkCPPversion17)
                for(edk::uint32 i=0u;i<size;i++){
#else
                for(register edk::uint32 i=0u;i<size;i++){
#endif
#endif
                    //select the polygon
                    if(object->physicMesh.selectPolygon(i)){
                        edk::size2f32 scale = object->physicMesh.selectedGetScale() * object->size * this->percentIn;
                        edk::vec2f32 translate;
                        translate.x = object->physicMesh.selectedGetTranslate().x * object->size.width * this->percentIn;
                        translate.y = object->physicMesh.selectedGetTranslate().y * object->size.height * this->percentIn;
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
                            fixture.userData.pointer = (uintptr_t)i;
                            objectShape.m_p.Set(translate.x,
                                                translate.y
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
                                vertex1 = edk::Math::rotate(vertex1,
                                                            edk::Math::getAngle(vertex1)
                                                            +
                                                            object->physicMesh.selectedGetAngle()
                                                            );
                                //Translate
                                vertex1+=translate;
                                //process the line
                                vertex2.x = (object->physicMesh.selectedGetVertexPosition(0u).x * scale.width);
                                vertex2.y = (object->physicMesh.selectedGetVertexPosition(0u).y * scale.height);
                                //rotate
                                vertex2 = edk::Math::rotate(vertex2,
                                                            edk::Math::getAngle(vertex2)
                                                            +
                                                            object->physicMesh.selectedGetAngle()
                                                            );
                                //Translate
                                vertex2+=translate;

                                //set the line
                                //removed the old box2D
                                //change it to the new box2D
                                // These are the edge vertices
                                objectShape.m_vertex1=b2Vec2 (vertex1.x, vertex1.y);
                                objectShape.m_vertex2=b2Vec2 (vertex2.x, vertex2.y);
                                // Optional adjacent vertices. These are used for smooth collision.
                                objectShape.m_vertex0=b2Vec2 (vertex1.x, vertex1.y);
                                objectShape.m_vertex3=b2Vec2 (vertex2.x, vertex2.y);




                                b2FixtureDef fixture;
                                fixture.userData.pointer = (uintptr_t)i;
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
                                fixture.userData.pointer = (uintptr_t)i;

                                edk::uint32 vCount=object->physicMesh.selectedGetVertexCount();
                                //it's a polygon
                                if(vCount>b2_maxPolygonVertices){
                                    vCount = b2_maxPolygonVertices;
                                }
                                edk::vec2f32 vertex;
                                for(edk::uint32 p=0u;p<vCount;p++){
                                    vertex.x = (object->physicMesh.selectedGetVertexPosition(p).x * scale.width);
                                    vertex.y = (object->physicMesh.selectedGetVertexPosition(p).y * scale.height);
                                    vertex = edk::Math::rotate(vertex,
                                                               edk::Math::getAngle(vertex)
                                                               +
                                                               object->physicMesh.selectedGetAngle()
                                                               );
                                    vertexs[p].x = vertex.x + translate.x;
                                    vertexs[p].y = vertex.y + translate.y;
                                }
                                objectShape.CreateChain(vertexs,vCount,vertexs[vCount-2u],vertexs[1u]);
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
                            fixture.userData.pointer = (uintptr_t)i;

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
                                rectVec[0u] = vec2f32((object->physicMesh.selectedGetVertexPosition(0u).x * scale.width),
                                                      (object->physicMesh.selectedGetVertexPosition(0u).y * scale.height)
                                                      );
                                rectVec[1u] = vec2f32((object->physicMesh.selectedGetVertexPosition(1u).x * scale.width),
                                                      (object->physicMesh.selectedGetVertexPosition(1u).y * scale.height)
                                                      );
                                //it's a rectangle
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
                                        rectSize.width*=-1.f;
                                    }
                                    if(rectSize.height<0.f){
                                        rectSize.height*=-1.f;
                                    }
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
                                    vertex = edk::Math::rotate(vertex,
                                                               edk::Math::getAngle(vertex)
                                                               +
                                                               object->physicMesh.selectedGetAngle()
                                                               ) + translate;
                                    vertexs[0u].x = vertex.x;
                                    vertexs[0u].y = vertex.y;

                                    vertex.x = rectVec[1u].x;
                                    vertex.y = rectVec[0u].y;
                                    //rotate
                                    vertex = edk::Math::rotate(vertex,
                                                               edk::Math::getAngle(vertex)
                                                               +
                                                               object->physicMesh.selectedGetAngle()
                                                               ) + translate;
                                    vertexs[1u].x = vertex.x;
                                    vertexs[1u].y = vertex.y;

                                    vertex.x = rectVec[1u].x;
                                    vertex.y = rectVec[1u].y;
                                    //rotate
                                    vertex = edk::Math::rotate(vertex,
                                                               edk::Math::getAngle(vertex)
                                                               +
                                                               object->physicMesh.selectedGetAngle()
                                                               ) + translate;
                                    vertexs[2u].x = vertex.x;
                                    vertexs[2u].y = vertex.y;

                                    vertex.x = rectVec[0u].x;
                                    vertex.y = rectVec[1u].y;
                                    //rotate
                                    vertex = edk::Math::rotate(vertex,
                                                               edk::Math::getAngle(vertex)
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
                                if(vCount>b2_maxPolygonVertices){
                                    vCount = b2_maxPolygonVertices;
                                }
                                edk::vec2f32 vertex;
                                for(edk::uint32 p=0u;p<vCount;p++){
                                    vertex.x = (object->physicMesh.selectedGetVertexPosition(p).x * scale.width);
                                    vertex.y = (object->physicMesh.selectedGetVertexPosition(p).y * scale.height);
                                    //vertexs[p].x = (object->physicMesh.selectedGetVertexPosition(p).x * scale.width) + translate.x;
                                    //vertexs[p].y = (object->physicMesh.selectedGetVertexPosition(p).y * scale.height) + translate.y;
                                    vertex = edk::Math::rotate(vertex,
                                                               edk::Math::getAngle(vertex)
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
            else{
                ret=false;
            }

            //tets if ret true
            if(ret){
                //add the object in the type tree
                //b2_staticBody
                //b2_kinematicBody
                //b2_dynamicBody
                switch(objectBody->GetType()){
                case b2_staticBody:
                    if(!this->treeStatic.addBody(object,objectBody)){
                        //destroy the body
                        if(this->runNextStep){
                            //save the object on the deleted tree
                            //objectBody->GetUserData().pointer = 0;
                            this->treeDeleted.add((edk::physics2D::PhysicObject2D*)objectBody->GetUserData().pointer);
                        }
                        else{
                            this->world.DestroyBody(objectBody);
                        }
                        ret=false;
                    }
                    break;
                case b2_kinematicBody:
                    if(!this->treeKinematic.addBody(object,objectBody)){
                        //destroy the body
                        if(this->runNextStep){
                            //save the object on the deleted tree
                            //objectBody->GetUserData().pointer = 0;
                            this->treeDeleted.add((edk::physics2D::PhysicObject2D*)objectBody->GetUserData().pointer);
                        }
                        else{
                            this->world.DestroyBody(objectBody);
                        }
                        ret=false;
                    }
                    break;
                case b2_dynamicBody:
                    if(!this->treeDynamic.addBody(object,objectBody)){
                        //destroy the body
                        if(this->runNextStep){
                            //save the object on the deleted tree
                            //objectBody->GetUserData().pointer = 0;
                            this->treeDeleted.add((edk::physics2D::PhysicObject2D*)objectBody->GetUserData().pointer);
                        }
                        else{
                            this->world.DestroyBody(objectBody);
                        }
                        ret=false;
                    }
                    break;
                default:
                    //destroy the object
                    if(this->runNextStep){
                        //save the object on the deleted tree
                        objectBody->GetUserData().pointer = 0;
                        this->treeDeleted.add((edk::physics2D::PhysicObject2D*)objectBody->GetUserData().pointer);
                    }
                    else{
                        this->world.DestroyBody(objectBody);
                    }
                    ret=false;
                }
            }
            else{
                //delete the object
                if(this->runNextStep){
                    //save the object on the deleted tree
                    objectBody->GetUserData().pointer = 0;
                    this->treeDeleted.add((edk::physics2D::PhysicObject2D*)objectBody->GetUserData().pointer);
                }
                else{
                    this->world.DestroyBody(objectBody);
                }
            }
        }
        return ret;
#endif
    }
    return false;
}

//remove the object from the world
bool edk::physics2D::World2D::removeObject(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        if(this->haveObject(object)){
            if(this->runNextStep){
#if defined(EDK_USE_BOX2D)
                this->treeDeleted.add((edk::physics2D::PhysicObject2D*)object);
#endif
                return true;
            }
            //remove all the object joints
            this->removeObjectJoints(object);
#if defined(EDK_USE_BOX2D)
            //load the box2D object
            b2Body* temp=NULL;
            /*
            switch(object->getType()){
            case edk::TypeObject2DStatic:
                temp = this->treeStatic.getBody(object);
                if(temp){
                    this->treeStatic.removeBody(temp);
                }
                break;
            case edk::TypeObject2DDynamic:
                temp = this->treeDynamic.getBody(object);
                if(temp){
                    this->treeDynamic.removeBody(temp);
                }
                break;
            case edk::TypeObject2DKinematic:
                temp = this->treeKinematic.getBody(object);
                if(temp){
                    this->treeKinematic.removeBody(temp);
                }
                break;
            default:
                break;
            }
*/
            temp = this->treeStatic.getBody(object);
            if(temp){
                this->treeStatic.removeBody(temp);
            }
            else{
                temp = this->treeDynamic.getBody(object);
                if(temp){
                    this->treeDynamic.removeBody(temp);
                }
                else{
                    temp = this->treeKinematic.getBody(object);
                    if(temp){
                        this->treeKinematic.removeBody(temp);
                    }
                }
            }
            if(temp){
                this->treeDeleted.add((edk::physics2D::PhysicObject2D*)object);
                this->world.DestroyBody(temp);
                this->treeDeleted.remove((edk::physics2D::PhysicObject2D*)object);
                return true;
            }
#endif
        }
        else{
            //;else test if aready have the object inside the treeDelete
            if(!this->runNextStep){
#if defined(EDK_USE_BOX2D)
                b2Body* temp=NULL;
                temp = this->treeStatic.getBody(object);
                if(temp){
                    this->treeStatic.removeBody(temp);
                    this->treeDeleted.add((edk::physics2D::PhysicObject2D*)object);
                    this->world.DestroyBody(temp);
                    this->treeDeleted.remove((edk::physics2D::PhysicObject2D*)object);
                    return true;
                }
                else{
                    temp = this->treeDynamic.getBody(object);
                    if(temp){
                        this->treeDynamic.removeBody(temp);
                        this->treeDeleted.add((edk::physics2D::PhysicObject2D*)object);
                        this->world.DestroyBody(temp);
                        this->treeDeleted.remove((edk::physics2D::PhysicObject2D*)object);
                        return true;
                    }
                    else{
                        temp = this->treeKinematic.getBody(object);
                        if(temp){
                            this->treeKinematic.removeBody(temp);
                            this->treeDeleted.add((edk::physics2D::PhysicObject2D*)object);
                            this->world.DestroyBody(temp);
                            this->treeDeleted.remove((edk::physics2D::PhysicObject2D*)object);
                            return true;
                        }
                    }
                }
#endif
            }
        }
    }
    return false;
}
//remove all objects
void edk::physics2D::World2D::removeAllObjects(){
#if defined(EDK_USE_BOX2D)
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
            if(this->runNextStep){
                //save the object on the deleted tree
                //temp->GetUserData().pointer = 0;
                this->treeDeleted.add((edk::physics2D::PhysicObject2D*)temp->GetUserData().pointer);
            }
            else{
                tempObject = (edk::physics2D::PhysicObject2D*) temp->GetUserData().pointer;
                if(tempObject){
                    //remove the joints
                    this->removeObjectJoints(tempObject);
                }
                if(!this->treeStatic.removeBody(temp)){
                    count++;
                }
                this->treeDeleted.add((edk::physics2D::PhysicObject2D*)temp);
                this->world.DestroyBody(temp);
                this->treeDeleted.remove((edk::physics2D::PhysicObject2D*)temp);
            }
        }
        else{
            count++;
        }
    }
    //remove static objects
    size = this->treeKinematic.size();
    for(edk::uint32 i=0u;i<size;i++){
        //load the object
        temp = this->treeKinematic.getBodyInPosition(count);
        if(temp){
            //
            if(this->runNextStep){
                //save the object on the deleted tree
                //temp->GetUserData().pointer = 0;
                this->treeDeleted.add((edk::physics2D::PhysicObject2D*)temp->GetUserData().pointer);
            }
            else{
                tempObject =  (edk::physics2D::PhysicObject2D*)temp->GetUserData().pointer;
                if(tempObject){
                    //remove the joints
                    this->removeObjectJoints(tempObject);
                }
                if(!this->treeKinematic.removeBody(temp)){
                    count++;
                }
                this->treeDeleted.add((edk::physics2D::PhysicObject2D*)temp);
                this->world.DestroyBody(temp);
                this->treeDeleted.remove((edk::physics2D::PhysicObject2D*)temp);
            }
        }
        else{
            count++;
        }
    }
    this->treeKinematic.clean();
    //remove static objects
    size = this->treeDynamic.size();
    for(edk::uint32 i=0u;i<size;i++){
        //load the object
        temp = this->treeDynamic.getBodyInPosition(count);
        if(temp){
            //
            if(this->runNextStep){
                //save the object on the deleted tree
                //temp->GetUserData().pointer = 0;
                this->treeDeleted.add((edk::physics2D::PhysicObject2D*)temp->GetUserData().pointer);
            }
            else{
                tempObject =  (edk::physics2D::PhysicObject2D*)temp->GetUserData().pointer;
                if(tempObject){
                    //remove the joints
                    this->removeObjectJoints(tempObject);
                }
                if(!this->treeDynamic.removeBody(temp)){
                    count++;
                }
                this->treeDeleted.add((edk::physics2D::PhysicObject2D*)temp);
                this->world.DestroyBody(temp);
                this->treeDeleted.remove((edk::physics2D::PhysicObject2D*)temp);
            }
        }
        else{
            count++;
        }
    }
    this->treeDynamic.clean();
#endif
}
//test if have the object
bool edk::physics2D::World2D::haveObject(edk::physics2D::PhysicObject2D* object){
    if(object){
#if defined(EDK_USE_BOX2D)
        if(this->treeDeleted.haveElement(object)){
            return false;
        }
#endif
        /*
        //test the objectType
        switch(object->getType()){
        case edk::TypeObject2DStatic:
#if defined(EDK_USE_BOX2D)
            return this->treeStatic.haveBody(object);
#endif
            break;
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            return this->treeDynamic.haveBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            return this->treeKinematic.haveBody(object);
#endif
            break;
        default:
            break;
        }
*/

#if defined(EDK_USE_BOX2D)
        if(this->treeStatic.haveBody(object)){
            return true;
        }
        else if(this->treeDynamic.haveBody(object)){
            return true;
        }
        else if(this->treeKinematic.haveBody(object)){
            return true;
        }
#endif
    }
    return false;
}
//get Objects
edk::uint32 edk::physics2D::World2D::getStaticObjectsSize(){
#if defined(EDK_USE_BOX2D)
    return this->treeStatic.size();
#else
    return 0u;
#endif
}
edk::physics2D::PhysicObject2D* edk::physics2D::World2D::getStaticObjectInPosition(edk::uint32
                                                                                   #if defined(EDK_USE_BOX2D)
                                                                                   position
                                                                                   #endif
                                                                                   ){
#if defined(EDK_USE_BOX2D)
    b2Body* body = this->treeStatic.getBodyInPosition(position);
    if(body){
        if(body->GetUserData().pointer){
            return (edk::physics2D::PhysicObject2D*)body->GetUserData().pointer;
        }
    }
#endif
    return NULL;
}
edk::uint32 edk::physics2D::World2D::getDynamicObjectsSize(){
#if defined(EDK_USE_BOX2D)
    return this->treeDynamic.size();
#else
    return 0u;
#endif
}
edk::physics2D::PhysicObject2D* edk::physics2D::World2D::getDynamicObjectInPosition(edk::uint32
                                                                                    #if defined(EDK_USE_BOX2D)
                                                                                    position
                                                                                    #endif
                                                                                    ){
#if defined(EDK_USE_BOX2D)
    b2Body* body = this->treeDynamic.getBodyInPosition(position);
    if(body){
        if(body->GetUserData().pointer){
            return (edk::physics2D::PhysicObject2D*)body->GetUserData().pointer;
        }
    }
#endif
    return NULL;
}
edk::uint32 edk::physics2D::World2D::getKinematicObjectsSize(){
#if defined(EDK_USE_BOX2D)
    return this->treeKinematic.size();
#else
    return 0u;
#endif
}
edk::physics2D::PhysicObject2D* edk::physics2D::World2D::getKinematicObjectInPosition(edk::uint32
                                                                                      #if defined(EDK_USE_BOX2D)
                                                                                      position
                                                                                      #endif
                                                                                      ){
#if defined(EDK_USE_BOX2D)
    b2Body* body = this->treeKinematic.getBodyInPosition(position);
    if(body){
        if(body->GetUserData().pointer){
            return (edk::physics2D::PhysicObject2D*)body->GetUserData().pointer;
        }
    }
#endif
    return NULL;
}

//update the object position in the world
bool edk::physics2D::World2D::updateObjectVelocity(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
#if defined(EDK_USE_BOX2D)
        if(this->treeDeleted.haveElement(object)){
            return false;
        }
#endif
        //load the box2D object
#if defined(EDK_USE_BOX2D)
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DStatic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeStatic.getBody(object);
#endif
            break;
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            if(object->haveSettedAngularVelocity()){
                temp->SetAngularVelocity((edk::float32)object->getAngularVelocity() / (180.f / b2_pi));
            }
            if(object->haveSettedLinearVelocity()){
                temp->SetLinearVelocity(b2Vec2(object->getLinearVelocity().x * this->percentIn,object->getLinearVelocity().y * this->percentIn));
            }
            return true;
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectLinearVelocity(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
#if defined(EDK_USE_BOX2D)
        if(this->treeDeleted.haveElement(object)){
            return false;
        }
#endif
        //test if is running the simulation
        if(this->runNextStep){
            //then add the object in to a tree to be added after the nextStep
            this->treeLinearVelocity.add(object);
            return true;
        }
#if defined(EDK_USE_BOX2D)
        //load the box2D object
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DStatic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeStatic.getBody(object);
#endif
            break;
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            if(object->haveSettedLinearVelocity()){
                temp->SetLinearVelocity(b2Vec2(object->getLinearVelocity().x * this->percentIn,object->getLinearVelocity().y * this->percentIn));
            }
            return true;
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectAngularVelocity(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
#if defined(EDK_USE_BOX2D)
        if(this->treeDeleted.haveElement(object)){
            return false;
        }
#endif
        //test if is running the simulation
        if(this->runNextStep){
            //then add the object in to a tree to be added after the nextStep
            this->treeAngularVelocity.add(object);
            return true;
        }
#if defined(EDK_USE_BOX2D)
        //load the box2D object
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DStatic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeStatic.getBody(object);
#endif
            break;
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            if(object->haveSettedAngularVelocity()){
                temp->SetAngularVelocity((edk::float32)object->getAngularVelocity() / (180.f / b2_pi));
            }
            return true;
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::cleanObjectVelocity(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
#if defined(EDK_USE_BOX2D)
        if(this->treeDeleted.haveElement(object)){
            return false;
        }
#endif
#if defined(EDK_USE_BOX2D)
        //load the box2D object
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DStatic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeStatic.getBody(object);
#endif
            break;
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            temp->SetLinearVelocity(b2Vec2(0.f,0.f));

            return true;
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectStatus(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
#if defined(EDK_USE_BOX2D)
        if(this->treeDeleted.haveElement(object)){
            return false;
        }
#endif
#if defined(EDK_USE_BOX2D)
        //load the box2D object
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DStatic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeStatic.getBody(object);
#endif
            break;
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            b2Fixture* fixture = temp->GetFixtureList();
            if(fixture){
                fixture->SetDensity(object->physicMesh.getPolygonDensity(0u));
                fixture->SetFriction(object->physicMesh.getPolygonFriction(0u));
                fixture->SetRestitution(object->physicMesh.getPolygonRestitution(0u));
            }
            return true;
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectPosition(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
#if defined(EDK_USE_BOX2D)
        if(this->treeDeleted.haveElement(object)){
            return false;
        }
#endif
#if defined(EDK_USE_BOX2D)
        //load the box2D object
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DStatic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeStatic.getBody(object);
#endif
            break;
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            temp->ApplyUpdatePosition(b2Vec2(object->position.x,object->position.y));
            temp->SetAwake(true);
            temp->SetLinearVelocity(b2Vec2(object->position.x - temp->GetPosition().x
                                           ,object->position.y - temp->GetPosition().y
                                           )
                                    );
            return true;
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectPositionX(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
#if defined(EDK_USE_BOX2D)
        if(this->treeDeleted.haveElement(object)){
            return false;
        }
#endif
#if defined(EDK_USE_BOX2D)
        //load the box2D object
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DStatic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeStatic.getBody(object);
#endif
            break;
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            temp->ApplyUpdatePositionX(object->position.x);
            temp->SetAwake(true);
            temp->SetLinearVelocity(b2Vec2(object->position.x - temp->GetPosition().x
                                           ,temp->GetLinearVelocity().y
                                           )
                                    );
            return true;
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectPositionY(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
#if defined(EDK_USE_BOX2D)
        if(this->treeDeleted.haveElement(object)){
            return false;
        }
#endif
#if defined(EDK_USE_BOX2D)
        //load the box2D object
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DStatic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeStatic.getBody(object);
#endif
            break;
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            temp->ApplyUpdatePositionY(object->position.y);
            temp->SetAwake(true);
            temp->SetLinearVelocity(b2Vec2(temp->GetLinearVelocity().x,
                                           object->position.y - temp->GetPosition().y
                                           )
                                    );
            object->setLinearVelocity(temp->GetLinearVelocity().x,
                                      object->position.y - temp->GetPosition().y);
            return true;
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectSyncronizePosition(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
#if defined(EDK_USE_BOX2D)
        if(this->treeDeleted.haveElement(object)){
            return false;
        }
#endif
#if defined(EDK_USE_BOX2D)
        //load the box2D object
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DStatic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeStatic.getBody(object);
#endif
            break;
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            temp->ApplySynchronizePosition();
            temp->SetAwake(true);
            return true;
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectSyncronizePositionX(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
#if defined(EDK_USE_BOX2D)
        if(this->treeDeleted.haveElement(object)){
            return false;
        }
#endif
#if defined(EDK_USE_BOX2D)
        //load the box2D object
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DStatic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeStatic.getBody(object);
#endif
            break;
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            temp->ApplySynchronizePositionX();
            temp->SetAwake(true);
            return true;
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectSyncronizePositionY(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
#if defined(EDK_USE_BOX2D)
        if(this->treeDeleted.haveElement(object)){
            return false;
        }
#endif
#if defined(EDK_USE_BOX2D)
        //load the box2D object
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DStatic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeStatic.getBody(object);
#endif
            break;
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            temp->ApplySynchronizePositionY();
            temp->SetAwake(true);
            return true;
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectAngle(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
#if defined(EDK_USE_BOX2D)
        if(this->treeDeleted.haveElement(object)){
            return false;
        }
#endif
#if defined(EDK_USE_BOX2D)
        //load the box2D object
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DStatic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeStatic.getBody(object);
#endif
            break;
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            temp->ApplyUpdateAngle(object->angle);
            temp->SetAngularVelocity(object->angle - temp->GetAngle());
            temp->SetAwake(true);
            return true;
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectPositionAndAngle(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
#if defined(EDK_USE_BOX2D)
        if(this->treeDeleted.haveElement(object)){
            return false;
        }
#endif
        //load the box2D object
#if defined(EDK_USE_BOX2D)
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DStatic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeStatic.getBody(object);
#endif
            break;
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            temp->ApplyUpdatePosition(b2Vec2(object->position.x,object->position.y));
            temp->SetLinearVelocity(b2Vec2(0.f//object->position.x - temp->GetPosition().x
                                           ,0.f//object->position.y - temp->GetPosition().y
                                           )
                                    );
            temp->ApplyUpdateAngle(object->angle);
            temp->SetAngularVelocity(0.f/*object->angle - temp->GetAngle()*/);
            temp->SetAwake(true);
            return true;
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectPositionXAndAngle(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
#if defined(EDK_USE_BOX2D)
        if(this->treeDeleted.haveElement(object)){
            return false;
        }
#endif
        //load the box2D object
#if defined(EDK_USE_BOX2D)
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DStatic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeStatic.getBody(object);
#endif
            break;
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            temp->ApplyUpdatePositionY(object->position.y);
            temp->SetLinearVelocity(b2Vec2(temp->GetLinearVelocity().x,
                                           object->position.y - temp->GetPosition().y
                                           )
                                    );
            temp->ApplyUpdateAngle(object->angle);
            temp->SetAngularVelocity(object->angle - temp->GetAngle());
            temp->SetAwake(true);
            return true;
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::updateObjectPositionYAndAngle(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
#if defined(EDK_USE_BOX2D)
        if(this->treeDeleted.haveElement(object)){
            return false;
        }
#endif
#if defined(EDK_USE_BOX2D)
        //load the box2D object
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DStatic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeStatic.getBody(object);
#endif
            break;
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            temp->ApplyUpdatePositionY(object->position.y);
            temp->SetLinearVelocity(b2Vec2(temp->GetLinearVelocity().x,
                                           object->position.y - temp->GetPosition().y
                                           )
                                    );
            temp->ApplyUpdateAngle(object->angle);
            temp->SetAngularVelocity(object->angle - temp->GetAngle());
            temp->SetAwake(true);
            return true;
        }
#endif
    }
    return false;
}
//move the object to a position
bool edk::physics2D::World2D::moveObject(edk::physics2D::PhysicObject2D* object,edk::vec2f32 move){
    //test the object
    if(object){
        //move the pbject
        object->position+=move * this->percentIn;
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
        object->position=position * this->percentIn;
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
#if defined(EDK_USE_BOX2D)
        b2Body* temp=NULL;
        temp = this->treeDynamic.getBody(object);
        if(temp){
            object->canSleep=true;
            temp->SetAwake(false);
            return true;
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::unsleepObject(edk::physics2D::PhysicObject2D* object){
    //test the object
    if(object){
        //load the box2D object
#if defined(EDK_USE_BOX2D)
        b2Body* temp=NULL;
        temp = this->treeDynamic.getBody(object);
        if(temp){
            temp->SetAwake(true);
            return true;
        }
#endif
    }
    return false;
}

//Add a force to the object
bool edk::physics2D::World2D::setLinearVelocity(edk::physics2D::PhysicObject2D* object,
                                                edk::vec2f32
                                                #if defined(EDK_USE_BOX2D)
                                                vector
                                                #endif
                                                ){
    //test the object
    if(object){
        //load the box2D object
#if defined(EDK_USE_BOX2D)
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            temp->SetLinearVelocity(b2Vec2(vector.x * this->percentIn,vector.y * this->percentIn));
            return true;
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::setLinearVelocity(edk::physics2D::PhysicObject2D* object,edk::float32 x, edk::float32 y){
    return this->setLinearVelocity(object,edk::vec2f32(x,y));
}
bool edk::physics2D::World2D::setAngularVelocity(edk::physics2D::PhysicObject2D* object,
                                                 edk::float32
                                                 #if defined(EDK_USE_BOX2D)
                                                 angle
                                                 #endif
                                                 ){
    //test the object
    if(object){
        //load the box2D object
#if defined(EDK_USE_BOX2D)
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            temp->SetAngularVelocity(angle / (180.f / b2_pi));
            return true;
        }
#endif
    }
    return false;
}
//Apply forces
bool edk::physics2D::World2D::applyForce(edk::physics2D::PhysicObject2D* object,
                                         edk::vec2f32
                                         #if defined(EDK_USE_BOX2D)
                                         force
                                         #endif
                                         ,
                                         edk::vec2f32
                                         #if defined(EDK_USE_BOX2D)
                                         position
                                         #endif
                                         ,
                                         bool
                                         #if defined(EDK_USE_BOX2D)
                                         wake
                                         #endif
                                         ){
    //test the object
    if(object){
        //load the box2D object
#if defined(EDK_USE_BOX2D)
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            temp->ApplyForce(b2Vec2(force.x * this->percentIn,force.y * this->percentIn),
                             b2Vec2(position.x * this->percentIn,position.y * this->percentIn),
                             wake
                             );
            return true;
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::applyLinearImpulse(edk::physics2D::PhysicObject2D* object,
                                                 edk::vec2f32
                                                 #if defined(EDK_USE_BOX2D)
                                                 impulse
                                                 #endif
                                                 ,
                                                 edk::vec2f32
                                                 #if defined(EDK_USE_BOX2D)
                                                 position
                                                 #endif
                                                 ,
                                                 bool
                                                 #if defined(EDK_USE_BOX2D)
                                                 wake
                                                 #endif
                                                 ){
    //test the object
    if(object){
        //load the box2D object
#if defined(EDK_USE_BOX2D)
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            temp->ApplyLinearImpulse(b2Vec2(impulse.x * this->percentIn,impulse.y * this->percentIn),b2Vec2(position.x * this->percentIn,position.y * this->percentIn),wake);
            return true;
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::applyAngularImpulse(edk::physics2D::PhysicObject2D* object,
                                                  edk::float32
                                                  #if defined(EDK_USE_BOX2D)
                                                  angle
                                                  #endif
                                                  ,
                                                  bool
                                                  #if defined(EDK_USE_BOX2D)
                                                  wake
                                                  #endif
                                                  ){
    //test the object
    if(object){
        //load the box2D object
#if defined(EDK_USE_BOX2D)
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            temp->ApplyAngularImpulse(angle / (180.f / b2_pi),
                                      wake
                                      );
            return true;
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::applyTorque(edk::physics2D::PhysicObject2D* object,
                                          edk::float32
                                          #if defined(EDK_USE_BOX2D)
                                          torque
                                          #endif
                                          ,
                                          bool
                                          #if defined(EDK_USE_BOX2D)
                                          wake
                                          #endif
                                          ){
    //test the object
    if(object){
#if defined(EDK_USE_BOX2D)
        //load the box2D object
        b2Body* temp=NULL;
#endif
        switch(object->getType()){
        case edk::TypeObject2DDynamic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeDynamic.getBody(object);
#endif
            break;
        case edk::TypeObject2DKinematic:
#if defined(EDK_USE_BOX2D)
            temp = this->treeKinematic.getBody(object);
#endif
            break;
        default:
            break;
        }
#if defined(EDK_USE_BOX2D)
        if(temp){
            temp->ApplyTorque(torque * this->percentIn,wake);
            return true;
        }
#endif
    }
    return false;
}

//process the next step
void edk::physics2D::World2D::nextStep(edk::float32
                                       #if defined(EDK_USE_BOX2D)
                                       timeStep
                                       #endif
                                       ,
                                       edk::int32
                                       #if defined(EDK_USE_BOX2D)
                                       velocityIterations
                                       #endif
                                       ,
                                       edk::int32
                                       #if defined(EDK_USE_BOX2D)
                                       positionIterations
                                       #endif
                                       ){
    if(!this->paused){
        //save the nextSpet
        this->runNextStep = true;
#if defined(EDK_USE_BOX2D)
        this->world.Step(timeStep,velocityIterations,positionIterations);

        {
            edk::uint32 size = this->treeSensorConcacts.size();
            edk::physics2D::Contact2D* contactTemp;
            edk::physics2D::StaticSensor2D* sensor;
            for(edk::uint32 i=0u;i<size;i++){
                contactTemp = this->treeSensorConcacts.getElementInPosition(i);
                if(contactTemp->isEnabled()){
                    if(!this->treeDeleted.haveElement(contactTemp->objectA)){
                        //test if the objectA is a sensor
                        if(contactTemp->objectA->isSensor()){
                            //load the sensor
                            sensor = (edk::physics2D::StaticSensor2D*)contactTemp->objectA;
                            //test if the sensor have objects
                            if(sensor->getActivateSize()){
                                //test if have the object in the sensor tree
                                if(sensor->haveActivateObject(contactTemp->objectB)){
                                    //this->world->sensorEnd(contactTemp);
                                    this->physicsSensorKeeping(contactTemp);
                                }
                            }
                            else{
                                //test if the object is in the sensor
                                //this->world->sensorEnd(contactTemp);
                                this->physicsSensorKeeping(contactTemp);
                            }
                        }
                        else{
                            if(!this->treeDeleted.haveElement(contactTemp->objectB)){
                                if(contactTemp->objectB->isSensor()){
                                    //load the sensor
                                    sensor = (edk::physics2D::StaticSensor2D*)contactTemp->objectB;
                                    //test if the sensor have objects
                                    if(sensor->getActivateSize()){
                                        //test if have the object in the sensor tree
                                        if(sensor->haveActivateObject(contactTemp->objectA)){
                                            //this->world->sensorEnd(contactTemp);
                                            this->physicsSensorKeeping(contactTemp);
                                        }
                                    }
                                    else{
                                        //test if the object is in the sensor
                                        //this->world->sensorEnd(contactTemp);
                                        this->physicsSensorKeeping(contactTemp);
                                    }
                                }
                            }
                        }
                    }
                    else if(!this->treeDeleted.haveElement(contactTemp->objectB)){
                        if(contactTemp->objectB->isSensor()){
                            //load the sensor
                            sensor = (edk::physics2D::StaticSensor2D*)contactTemp->objectB;
                            //test if the sensor have objects
                            if(sensor->getActivateSize()){
                                //test if have the object in the sensor tree
                                if(sensor->haveActivateObject(contactTemp->objectA)){
                                    //this->world->sensorEnd(contactTemp);
                                    this->physicsSensorKeeping(contactTemp);
                                }
                            }
                            else{
                                //test if the object is in the sensor
                                //this->world->sensorEnd(contactTemp);
                                this->physicsSensorKeeping(contactTemp);
                            }
                        }
                    }
                }
            }
        }
#endif

        this->runNextStep = false;

        //clean the treeObjectContacts
        this->beginContacs.cleanContacts();
        this->keepBeginContacs.cleanContacts();
        this->keepEndContacs.cleanContacts();
        this->endContacs.cleanContacts();
        this->sensorBeginContacs.cleanContacts();
        this->sensorKeepContacs.cleanContacts();
        this->sensorEndContacs.cleanContacts();

        //create new objects
        this->treeNew.print();
        this->treeNew.clean();
        //update the linear velocity of the object
        this->treeLinearVelocity.render();
        this->treeLinearVelocity.clean();
        //update the angular velocity of the object
        this->treeAngularVelocity.update();
        this->treeAngularVelocity.clean();

#if defined(EDK_USE_BOX2D)
        //remove the bodys
        this->treeDeleted.update();
        this->treeDeleted.clean();

        //update the kinematic objects
        this->treeKinematic.update();
        this->treeDynamic.update();
        this->treeJoint.update();
#endif
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
    return this->treeConcacts.getSize() + this->treeSensorConcacts.getSize();
}
//return the contact
edk::physics2D::Contact2D* edk::physics2D::World2D::getContact(edk::uint32 position){
    edk::physics2D::Contact2D* ret = this->treeConcacts.getElementInPosition(position);
    if(!ret){
        return this->treeSensorConcacts.getElementInPosition(position - this->treeConcacts.size());
    }
    return ret;
}


//joints
//MOUSE
edk::physics2D::MouseJoint2D* edk::physics2D::World2D::createMouseJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                        edk::vec2f32
                                                                        #if defined(EDK_USE_BOX2D)
                                                                        positionA
                                                                        #endif
                                                                        ,
                                                                        edk::vec2f32 positionB
                                                                        ){
    //test the object
    if(objectA){
        //test the objectType
        if(objectA->getType()!=edk::TypeObject2DStatic){
            //create a ground body
            edk::physics2D::KinematicObject2D* ground = new edk::physics2D::KinematicObject2D;
            if(ground){
                edk::shape::Rectangle2D rect;
                rect.setPivoToCenter();
                ground->physicMesh.addPolygon(rect);

                ground->position=positionB;

                if(this->addObject(ground)){
                    //


#if defined(EDK_USE_BOX2D)
                    //load the objects
                    b2Body* bodyA = this->getBody(ground);
                    b2Body* bodyB = this->getBody(objectA);


                    //create the joint
                    if(bodyA && bodyB){
                        edk::physics2D::MouseJoint2D *edkJoint = NULL;
                        //create the revolute def
                        b2MouseJointDef jointDef;
                        jointDef.collideConnected=false;
                        jointDef.bodyA = bodyA;
                        jointDef.bodyB = bodyB;
                        //jointDef.target = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);

                        //create the edkJoint
                        edkJoint = new edk::physics2D::MouseJoint2D(false);
                        if(edkJoint){
                            //in the new version of box2D the userData are setted in jointDef
                            jointDef.userData.pointer = (uintptr_t)edkJoint;

                            edkJoint->objectA = ground;
                            edkJoint->objectB = objectA;
                            edkJoint->positionA = positionA;
                            edkJoint->positionB = 0.f;
                            edkJoint->worldPositionA
                                    =
                                    edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
                                    ;
                            edkJoint->positionB = positionB;

                            //create the edkJoint
                            if(this->addJoint(edkJoint)){
                                //
                                b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                                if(joint){
                                    b2MouseJoint* mouseJoint = (b2MouseJoint*)joint;
                                    mouseJoint->SetTarget(b2Vec2(positionB.x,positionB.y));
                                    //removed from the old box2D version. In the new box2D version the userData is in JointDef
                                    //joint->SetUserData(edkJoint);
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

#endif
                    this->removeObject(ground);
                }
                delete ground;
            }
        }
    }
    return NULL;
}
edk::physics2D::MouseJoint2D* edk::physics2D::World2D::createMouseJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                        edk::vec2f32
                                                                        #if defined(EDK_USE_BOX2D)
                                                                        worldPosition
                                                                        #endif
                                                                        ){
    //test the object
    if(objectA){
#if defined(EDK_USE_BOX2D)
        return this->createMouseJoint(objectA,
                                      edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                      worldPosition
                                      );
#endif
    }
    return NULL;
}

//REVOLUTE
edk::physics2D::RevoluteJoint2D* edk::physics2D::World2D::createRevoluteJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                              edk::vec2f32
                                                                              #if defined(EDK_USE_BOX2D)
                                                                              positionA
                                                                              #endif
                                                                              ,
                                                                              edk::physics2D::PhysicObject2D* objectB,
                                                                              edk::vec2f32
                                                                              #if defined(EDK_USE_BOX2D)
                                                                              positionB
                                                                              #endif
                                                                              ,
                                                                              bool
                                                                              #if defined(EDK_USE_BOX2D)
                                                                              collide
                                                                              #endif
                                                                              ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::TypeObject2DStatic || objectB->getType()!=edk::TypeObject2DStatic){
#if defined(EDK_USE_BOX2D)

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
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);

                //create the edkJoint
                edkJoint = new edk::physics2D::RevoluteJoint2D(collide);
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;

                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
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
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);
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

#endif
        }
    }
    return NULL;
}
edk::physics2D::RevoluteJoint2D* edk::physics2D::World2D::createRevoluteJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                              edk::physics2D::PhysicObject2D* objectB,
                                                                              edk::vec2f32
                                                                              #if defined(EDK_USE_BOX2D)
                                                                              worldPosition
                                                                              #endif
                                                                              ,
                                                                              bool
                                                                              #if defined(EDK_USE_BOX2D)
                                                                              collide
                                                                              #endif
                                                                              ){
    //test the object
    if(objectA && objectB){
#if defined(EDK_USE_BOX2D)
        return this->createRevoluteJoint(objectA,
                                         edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                         objectB,
                                         edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                         collide
                                         );
#endif
    }
    return NULL;
}
edk::physics2D::RevoluteJoint2D* edk::physics2D::World2D::createRevoluteAngleJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                                   edk::vec2f32
                                                                                   #if defined(EDK_USE_BOX2D)
                                                                                   positionA
                                                                                   #endif
                                                                                   ,
                                                                                   edk::physics2D::PhysicObject2D* objectB,
                                                                                   edk::vec2f32
                                                                                   #if defined(EDK_USE_BOX2D)
                                                                                   positionB
                                                                                   #endif
                                                                                   ,
                                                                                   edk::float32
                                                                                   #if defined(EDK_USE_BOX2D)
                                                                                   lowerAngle
                                                                                   #endif
                                                                                   ,
                                                                                   edk::float32
                                                                                   #if defined(EDK_USE_BOX2D)
                                                                                   upperAngle
                                                                                   #endif
                                                                                   ,
                                                                                   bool
                                                                                   #if defined(EDK_USE_BOX2D)
                                                                                   collide
                                                                                   #endif
                                                                                   ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::TypeObject2DStatic || objectB->getType()!=edk::TypeObject2DStatic){
#if defined(EDK_USE_BOX2D)

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
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);

                jointDef.lowerAngle = (lowerAngle / 180.f) * b2_pi;
                jointDef.upperAngle = (upperAngle/ 180.f) * b2_pi;
                jointDef.enableLimit=true;



                //create the edkJoint
                edkJoint = new edk::physics2D::RevoluteJoint2D(collide);
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;

                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA = edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA);
                    edkJoint->positionB = positionB;

                    //angle Joint
                    edkJoint->setAngle(lowerAngle,upperAngle);

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                        if(joint){
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);
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

#endif
        }
    }
    return NULL;
}
edk::physics2D::RevoluteJoint2D* edk::physics2D::World2D::createRevoluteAngleJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,
                                                                                   edk::vec2f32
                                                                                   #if defined(EDK_USE_BOX2D)
                                                                                   worldPosition
                                                                                   #endif
                                                                                   ,
                                                                                   edk::float32
                                                                                   #if defined(EDK_USE_BOX2D)
                                                                                   lowerAngle
                                                                                   #endif
                                                                                   ,
                                                                                   edk::float32
                                                                                   #if defined(EDK_USE_BOX2D)
                                                                                   upperAngle
                                                                                   #endif
                                                                                   ,
                                                                                   bool
                                                                                   #if defined(EDK_USE_BOX2D)
                                                                                   collide
                                                                                   #endif
                                                                                   ){
    //test the object
    if(objectA && objectB){
#if defined(EDK_USE_BOX2D)
        return this->createRevoluteAngleJoint(objectA,
                                              edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                              objectB,
                                              edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                              lowerAngle,upperAngle,
                                              collide
                                              );
#endif
    }
    return NULL;
}
edk::physics2D::RevoluteJoint2D* edk::physics2D::World2D::createRevoluteMotorJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                                   edk::vec2f32
                                                                                   #if defined(EDK_USE_BOX2D)
                                                                                   positionA
                                                                                   #endif
                                                                                   ,
                                                                                   edk::physics2D::PhysicObject2D* objectB,
                                                                                   edk::vec2f32
                                                                                   #if defined(EDK_USE_BOX2D)
                                                                                   positionB
                                                                                   #endif
                                                                                   ,
                                                                                   edk::float32
                                                                                   #if defined(EDK_USE_BOX2D)
                                                                                   maxTorque
                                                                                   #endif
                                                                                   ,
                                                                                   edk::float32
                                                                                   #if defined(EDK_USE_BOX2D)
                                                                                   speed
                                                                                   #endif
                                                                                   ,
                                                                                   bool
                                                                                   #if defined(EDK_USE_BOX2D)
                                                                                   collide
                                                                                   #endif
                                                                                   ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::TypeObject2DStatic || objectB->getType()!=edk::TypeObject2DStatic){
            //load the objects
#if defined(EDK_USE_BOX2D)
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
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);

                jointDef.maxMotorTorque = maxTorque;
                jointDef.motorSpeed = speed;
                jointDef.enableMotor=true;



                //create the edkJoint
                edkJoint = new edk::physics2D::RevoluteJoint2D(collide);
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;

                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
                            ;
                    edkJoint->positionB = positionB;

                    //set motor
                    edkJoint->setMotor(maxTorque,speed);

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                        if(joint){
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);
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

#endif
        }
    }
    return NULL;
}
edk::physics2D::RevoluteJoint2D* edk::physics2D::World2D::createRevoluteMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,
                                                                                   edk::vec2f32
                                                                                   #if defined(EDK_USE_BOX2D)
                                                                                   worldPosition
                                                                                   #endif
                                                                                   ,
                                                                                   edk::float32
                                                                                   #if defined(EDK_USE_BOX2D)
                                                                                   maxTorque
                                                                                   #endif
                                                                                   ,
                                                                                   edk::float32
                                                                                   #if defined(EDK_USE_BOX2D)
                                                                                   speed
                                                                                   #endif
                                                                                   ,
                                                                                   bool
                                                                                   #if defined(EDK_USE_BOX2D)
                                                                                   collide
                                                                                   #endif
                                                                                   ){
    //test the object
    if(objectA && objectB){
#if defined(EDK_USE_BOX2D)
        return this->createRevoluteMotorJoint(objectA,
                                              edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                              objectB,
                                              edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                              maxTorque,speed,
                                              collide
                                              );
#endif
    }
    return NULL;
}
//PRISMATIC
edk::physics2D::PrismaticJoint2D* edk::physics2D::World2D::createPrismaticJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                                edk::vec2f32
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                positionA
                                                                                #endif
                                                                                ,
                                                                                edk::physics2D::PhysicObject2D* objectB,
                                                                                edk::vec2f32
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                positionB
                                                                                #endif
                                                                                ,
                                                                                edk::vec2f32
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                direction
                                                                                #endif
                                                                                ,
                                                                                edk::float32
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                lowerDistance
                                                                                #endif
                                                                                ,
                                                                                edk::float32
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                upperDistance
                                                                                #endif
                                                                                ,
                                                                                bool
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                collide
                                                                                #endif
                                                                                ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::TypeObject2DStatic || objectB->getType()!=edk::TypeObject2DStatic){
#if defined(EDK_USE_BOX2D)

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
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);
                jointDef.localAxisA = b2Vec2(direction.x * this->percentIn,direction.y * this->percentIn);
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
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;

                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
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
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);
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

#endif
        }
    }
    return NULL;
}
edk::physics2D::PrismaticJoint2D* edk::physics2D::World2D::createPrismaticJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,
                                                                                edk::vec2f32
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                worldPosition
                                                                                #endif
                                                                                ,
                                                                                edk::vec2f32
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                direction
                                                                                #endif
                                                                                ,
                                                                                edk::float32
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                lowerDistance
                                                                                #endif
                                                                                ,
                                                                                edk::float32
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                upperDistance
                                                                                #endif
                                                                                ,
                                                                                bool
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                collide
                                                                                #endif
                                                                                ){
    //test the object
    if(objectA && objectB){
#if defined(EDK_USE_BOX2D)
        return this->createPrismaticJoint(objectA,
                                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                          objectB,
                                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                          direction,lowerDistance,upperDistance,
                                          collide
                                          );
#endif
    }
    return NULL;
}
edk::physics2D::PrismaticJoint2D* edk::physics2D::World2D::createPrismaticJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                                edk::vec2f32
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                positionA
                                                                                #endif
                                                                                ,
                                                                                edk::physics2D::PhysicObject2D* objectB,
                                                                                edk::vec2f32
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                positionB
                                                                                #endif
                                                                                ,
                                                                                edk::float32
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                angle
                                                                                #endif
                                                                                ,
                                                                                edk::float32
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                lowerDistance
                                                                                #endif
                                                                                ,
                                                                                edk::float32
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                upperDistance
                                                                                #endif
                                                                                ,
                                                                                bool
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                collide
                                                                                #endif
                                                                                ){
    //test the object
    if(objectA && objectB){
#if defined(EDK_USE_BOX2D)
        return this->createPrismaticJoint(objectA,positionA,
                                          objectB,positionB,
                                          edk::Math::rotate(edk::vec2f32(1,0),angle),lowerDistance,upperDistance,
                                          collide
                                          );
#endif
    }
    return NULL;
}
edk::physics2D::PrismaticJoint2D* edk::physics2D::World2D::createPrismaticJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,
                                                                                edk::vec2f32
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                worldPosition
                                                                                #endif
                                                                                ,
                                                                                edk::float32
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                angle
                                                                                #endif
                                                                                ,
                                                                                edk::float32
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                lowerDistance
                                                                                #endif
                                                                                ,
                                                                                edk::float32
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                upperDistance
                                                                                #endif
                                                                                ,
                                                                                bool
                                                                                #if defined(EDK_USE_BOX2D)
                                                                                collide
                                                                                #endif
                                                                                ){
    //test the object
    if(objectA && objectB){
#if defined(EDK_USE_BOX2D)
        return this->createPrismaticJoint(objectA,
                                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                          objectB,
                                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                          edk::Math::rotate(edk::vec2f32(1,0),angle),lowerDistance,upperDistance,
                                          collide
                                          );
#endif
    }
    return NULL;
}
edk::physics2D::PrismaticJoint2D* edk::physics2D::World2D::createPrismaticMotorJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                                     edk::vec2f32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     positionA
                                                                                     #endif
                                                                                     ,
                                                                                     edk::physics2D::PhysicObject2D* objectB,
                                                                                     edk::vec2f32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     positionB
                                                                                     #endif
                                                                                     ,
                                                                                     edk::vec2f32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     direction
                                                                                     #endif
                                                                                     ,
                                                                                     edk::float32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     lowerDistance
                                                                                     #endif
                                                                                     ,
                                                                                     edk::float32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     upperDistance
                                                                                     #endif
                                                                                     ,
                                                                                     edk::float32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     maxForce
                                                                                     #endif
                                                                                     ,
                                                                                     edk::float32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     speed
                                                                                     #endif
                                                                                     ,
                                                                                     bool
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     collide
                                                                                     #endif
                                                                                     ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::TypeObject2DStatic || objectB->getType()!=edk::TypeObject2DStatic){
#if defined(EDK_USE_BOX2D)

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
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);
                jointDef.localAxisA = b2Vec2(direction.x * this->percentIn,direction.y * this->percentIn);
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
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;

                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
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
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);
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

#endif
        }
    }
    return NULL;
}
edk::physics2D::PrismaticJoint2D* edk::physics2D::World2D::createPrismaticMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,
                                                                                     edk::vec2f32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     worldPosition
                                                                                     #endif
                                                                                     ,
                                                                                     edk::vec2f32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     direction
                                                                                     #endif
                                                                                     ,
                                                                                     edk::float32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     lowerDistance
                                                                                     #endif
                                                                                     ,
                                                                                     edk::float32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     upperDistance
                                                                                     #endif
                                                                                     ,
                                                                                     edk::float32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     maxForce
                                                                                     #endif
                                                                                     ,
                                                                                     edk::float32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     speed
                                                                                     #endif
                                                                                     ,
                                                                                     bool
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     collide
                                                                                     #endif
                                                                                     ){
    //test the object
    if(objectA && objectB){
#if defined(EDK_USE_BOX2D)
        return this->createPrismaticMotorJoint(objectA,
                                               edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                               objectB,
                                               edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                               direction,lowerDistance,upperDistance,
                                               maxForce,speed,
                                               collide
                                               );
#endif
    }
    return NULL;
}
edk::physics2D::PrismaticJoint2D* edk::physics2D::World2D::createPrismaticMotorJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                                     edk::vec2f32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     positionA
                                                                                     #endif
                                                                                     ,
                                                                                     edk::physics2D::PhysicObject2D* objectB,
                                                                                     edk::vec2f32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     positionB
                                                                                     #endif
                                                                                     ,
                                                                                     edk::float32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     angle
                                                                                     #endif
                                                                                     ,
                                                                                     edk::float32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     lowerDistance
                                                                                     #endif
                                                                                     ,
                                                                                     edk::float32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     upperDistance
                                                                                     #endif
                                                                                     ,
                                                                                     edk::float32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     maxForce
                                                                                     #endif
                                                                                     ,
                                                                                     edk::float32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     speed
                                                                                     #endif
                                                                                     ,
                                                                                     bool
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     collide
                                                                                     #endif
                                                                                     ){
    //test the object
    if(objectA && objectB){
#if defined(EDK_USE_BOX2D)
        return this->createPrismaticMotorJoint(objectA,positionA,
                                               objectB,positionB,
                                               edk::Math::rotate(edk::vec2f32(1,0),angle),lowerDistance,upperDistance,
                                               maxForce,speed,
                                               collide
                                               );
#endif
    }
    return NULL;
}
edk::physics2D::PrismaticJoint2D* edk::physics2D::World2D::createPrismaticMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,
                                                                                     edk::vec2f32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     worldPosition
                                                                                     #endif
                                                                                     ,
                                                                                     edk::float32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     angle
                                                                                     #endif
                                                                                     ,
                                                                                     edk::float32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     lowerDistance
                                                                                     #endif
                                                                                     ,
                                                                                     edk::float32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     upperDistance
                                                                                     #endif
                                                                                     ,
                                                                                     edk::float32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     maxForce
                                                                                     #endif
                                                                                     ,
                                                                                     edk::float32
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     speed
                                                                                     #endif
                                                                                     ,
                                                                                     bool
                                                                                     #if defined(EDK_USE_BOX2D)
                                                                                     collide
                                                                                     #endif
                                                                                     ){
    //test the object
    if(objectA && objectB){
#if defined(EDK_USE_BOX2D)
        return this->createPrismaticMotorJoint(objectA,
                                               edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                               objectB,
                                               edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                               edk::Math::rotate(edk::vec2f32(1,0),angle),lowerDistance,upperDistance,
                                               maxForce,speed,
                                               collide
                                               );
#endif
    }
    return NULL;
}

//DISTANCE
edk::physics2D::DistanceJoint2D* edk::physics2D::World2D::createDistanceJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                              edk::vec2f32
                                                                              #if defined(EDK_USE_BOX2D)
                                                                              positionA
                                                                              #endif
                                                                              ,
                                                                              edk::physics2D::PhysicObject2D* objectB,
                                                                              edk::vec2f32
                                                                              #if defined(EDK_USE_BOX2D)
                                                                              positionB
                                                                              #endif
                                                                              ,
                                                                              edk::float32
                                                                              #if defined(EDK_USE_BOX2D)
                                                                              distance
                                                                              #endif
                                                                              ,
                                                                              bool
                                                                              #if defined(EDK_USE_BOX2D)
                                                                              collide
                                                                              #endif
                                                                              ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::TypeObject2DStatic || objectB->getType()!=edk::TypeObject2DStatic){
#if defined(EDK_USE_BOX2D)

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
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);
                jointDef.length = distance;

                //removed frequency in new box2D

                //create the edkJoint
                edkJoint = new edk::physics2D::DistanceJoint2D(collide);
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;

                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
                            ;
                    edkJoint->positionB = positionB;
                    edkJoint->worldPositionB
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectB,positionB)
                            ;

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                        if(joint){
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);
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

#endif
        }
    }
    return NULL;
}
edk::physics2D::DistanceJoint2D* edk::physics2D::World2D::createDistanceJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                              edk::vec2f32
                                                                              #if defined(EDK_USE_BOX2D)
                                                                              worldPositionA
                                                                              #endif
                                                                              ,
                                                                              edk::physics2D::PhysicObject2D* objectB,
                                                                              edk::vec2f32
                                                                              #if defined(EDK_USE_BOX2D)
                                                                              worldPositionB
                                                                              #endif
                                                                              ,
                                                                              bool
                                                                              #if defined(EDK_USE_BOX2D)
                                                                              collide
                                                                              #endif
                                                                              ){
    //test the object
    if(objectA && objectB){
#if defined(EDK_USE_BOX2D)
        return this->createDistanceJoint(objectA,
                                         edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPositionA),
                                         objectB,
                                         edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPositionB),
                                         edk::Math::module(edk::Math::pythagoras(worldPositionA - worldPositionB)),
                                         collide
                                         );
#endif
    }
    return NULL;
}
//PULLEY
edk::physics2D::PulleyJoint2D* edk::physics2D::World2D::createPulleyJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                          edk::vec2f32
                                                                          #if defined(EDK_USE_BOX2D)
                                                                          positionA
                                                                          #endif
                                                                          ,
                                                                          edk::vec2f32
                                                                          #if defined(EDK_USE_BOX2D)
                                                                          pulleyPositionA
                                                                          #endif
                                                                          ,
                                                                          edk::physics2D::PhysicObject2D* objectB,
                                                                          edk::vec2f32
                                                                          #if defined(EDK_USE_BOX2D)
                                                                          positionB
                                                                          #endif
                                                                          ,
                                                                          edk::vec2f32
                                                                          #if defined(EDK_USE_BOX2D)
                                                                          pulleyPositionB
                                                                          #endif
                                                                          ,
                                                                          edk::float32
                                                                          #if defined(EDK_USE_BOX2D)
                                                                          lenghtA
                                                                          #endif
                                                                          ,
                                                                          edk::float32
                                                                          #if defined(EDK_USE_BOX2D)
                                                                          lenghtB
                                                                          #endif
                                                                          ,
                                                                          bool
                                                                          #if defined(EDK_USE_BOX2D)
                                                                          collide
                                                                          #endif
                                                                          ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::TypeObject2DStatic || objectB->getType()!=edk::TypeObject2DStatic){
#if defined(EDK_USE_BOX2D)

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
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);

                jointDef.groundAnchorA = b2Vec2((pulleyPositionA.x * this->percentIn) + (objectA->position.x * this->percentIn),(pulleyPositionA.y * this->percentIn) + (objectA->position.y * this->percentIn));
                jointDef.groundAnchorB = b2Vec2((pulleyPositionB.x * this->percentIn) + (objectB->position.x * this->percentIn),(pulleyPositionB.y * this->percentIn) + (objectB->position.y * this->percentIn));

                jointDef.lengthA = lenghtA;
                jointDef.lengthB = lenghtB;

                //create the edkJoint
                edkJoint = new edk::physics2D::PulleyJoint2D(collide);
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;

                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
                            ;
                    edkJoint->positionB = positionB;
                    edkJoint->worldPositionB
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectB,positionB)
                            ;
                    edkJoint->pulleyPositionA
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,pulleyPositionA)
                            ;
                    edkJoint->pulleyPositionB
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectB,pulleyPositionB)
                            ;


                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                        if(joint){
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);
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

#endif
        }
    }
    return NULL;
}
edk::physics2D::PulleyJoint2D* edk::physics2D::World2D::createPulleyJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                          edk::vec2f32
                                                                          #if defined(EDK_USE_BOX2D)
                                                                          positionA
                                                                          #endif
                                                                          ,
                                                                          edk::vec2f32
                                                                          #if defined(EDK_USE_BOX2D)
                                                                          pulleyPositionA
                                                                          #endif
                                                                          ,
                                                                          edk::physics2D::PhysicObject2D* objectB,
                                                                          edk::vec2f32
                                                                          #if defined(EDK_USE_BOX2D)
                                                                          positionB
                                                                          #endif
                                                                          ,
                                                                          edk::vec2f32
                                                                          #if defined(EDK_USE_BOX2D)
                                                                          pulleyPositionB
                                                                          #endif
                                                                          ,
                                                                          bool
                                                                          #if defined(EDK_USE_BOX2D)
                                                                          collide
                                                                          #endif
                                                                          ){
    //test the object
    if(objectA && objectB){
#if defined(EDK_USE_BOX2D)
        return this->createPulleyJoint(objectA,positionA, pulleyPositionA,
                                       objectB,positionB, pulleyPositionB,
                                       edk::Math::module(edk::Math::pythagoras(pulleyPositionA-positionA)),
                                       edk::Math::module(edk::Math::pythagoras(pulleyPositionB-positionB)),
                                       collide
                                       );
#endif
    }
    return NULL;
}
edk::physics2D::PulleyJoint2D* edk::physics2D::World2D::createPulleyWorldJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                               edk::vec2f32
                                                                               #if defined(EDK_USE_BOX2D)
                                                                               worldPositionA
                                                                               #endif
                                                                               ,
                                                                               edk::vec2f32
                                                                               #if defined(EDK_USE_BOX2D)
                                                                               pulleyWorldPositionA
                                                                               #endif
                                                                               ,
                                                                               edk::physics2D::PhysicObject2D* objectB,
                                                                               edk::vec2f32
                                                                               #if defined(EDK_USE_BOX2D)
                                                                               worldPositionB
                                                                               #endif
                                                                               ,
                                                                               edk::vec2f32
                                                                               #if defined(EDK_USE_BOX2D)
                                                                               pulleyWorldPositionB
                                                                               #endif
                                                                               ,
                                                                               edk::float32
                                                                               #if defined(EDK_USE_BOX2D)
                                                                               lenghtA
                                                                               #endif
                                                                               ,
                                                                               edk::float32
                                                                               #if defined(EDK_USE_BOX2D)
                                                                               lenghtB
                                                                               #endif
                                                                               ,
                                                                               bool
                                                                               #if defined(EDK_USE_BOX2D)
                                                                               collide
                                                                               #endif
                                                                               ){
    //test the object
    if(objectA && objectB){
#if defined(EDK_USE_BOX2D)
        createPulleyJoint(objectA,
                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPositionA),
                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,pulleyWorldPositionA),
                          objectB,
                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPositionB),
                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,pulleyWorldPositionB),
                          lenghtA,lenghtB,
                          collide
                          );
#endif
    }
    return NULL;
}
edk::physics2D::PulleyJoint2D* edk::physics2D::World2D::createPulleyWorldJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                               edk::vec2f32
                                                                               #if defined(EDK_USE_BOX2D)
                                                                               worldPositionA
                                                                               #endif
                                                                               ,
                                                                               edk::vec2f32
                                                                               #if defined(EDK_USE_BOX2D)
                                                                               pulleyWorldPositionA
                                                                               #endif
                                                                               ,
                                                                               edk::physics2D::PhysicObject2D* objectB,
                                                                               edk::vec2f32
                                                                               #if defined(EDK_USE_BOX2D)
                                                                               worldPositionB
                                                                               #endif
                                                                               ,
                                                                               edk::vec2f32
                                                                               #if defined(EDK_USE_BOX2D)
                                                                               pulleyWorldPositionB
                                                                               #endif
                                                                               ,
                                                                               bool
                                                                               #if defined(EDK_USE_BOX2D)
                                                                               collide
                                                                               #endif
                                                                               ){
    //test the object
    if(objectA && objectB){
#if defined(EDK_USE_BOX2D)
        createPulleyJoint(objectA,
                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPositionA),
                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,pulleyWorldPositionA),
                          objectB,
                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPositionB),
                          edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,pulleyWorldPositionB),
                          collide
                          );
#endif
    }
    return NULL;
}
//WHEEL
edk::physics2D::WheelJoint2D* edk::physics2D::World2D::createWheelJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                        edk::vec2f32
                                                                        #if defined(EDK_USE_BOX2D)
                                                                        positionA
                                                                        #endif
                                                                        ,
                                                                        edk::physics2D::PhysicObject2D* objectB,
                                                                        edk::vec2f32
                                                                        #if defined(EDK_USE_BOX2D)
                                                                        positionB
                                                                        #endif
                                                                        ,
                                                                        edk::vec2f32
                                                                        #if defined(EDK_USE_BOX2D)
                                                                        direction
                                                                        #endif
                                                                        ,
                                                                        bool
                                                                        #if defined(EDK_USE_BOX2D)
                                                                        collide
                                                                        #endif
                                                                        ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::TypeObject2DStatic || objectB->getType()!=edk::TypeObject2DStatic){
#if defined(EDK_USE_BOX2D)

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
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);

                jointDef.localAxisA = b2Vec2(direction.x * this->percentIn,direction.y * this->percentIn);
                jointDef.localAxisA.Normalize();

                //removed frequency in new box2D
                //removed dampingRatio in new box2D

                //create the edkJoint
                edkJoint = new edk::physics2D::WheelJoint2D(collide);
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;

                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
                            ;
                    edkJoint->positionB = positionB;

                    edkJoint->direction = direction;

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                        if(joint){
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);
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

#endif
        }
    }
    return NULL;
}

edk::physics2D::WheelJoint2D* edk::physics2D::World2D::createWheelJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,
                                                                        edk::vec2f32
                                                                        #if defined(EDK_USE_BOX2D)
                                                                        worldPosition
                                                                        #endif
                                                                        ,
                                                                        edk::vec2f32
                                                                        #if defined(EDK_USE_BOX2D)
                                                                        direction
                                                                        #endif
                                                                        ,
                                                                        bool
                                                                        #if defined(EDK_USE_BOX2D)
                                                                        collide
                                                                        #endif
                                                                        ){
    //test the object
    if(objectA && objectB){
#if defined(EDK_USE_BOX2D)
        return this->createWheelJoint(objectA,
                                      edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                      objectB,
                                      edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                      direction,
                                      collide
                                      );
#endif
    }
    return NULL;
}
edk::physics2D::WheelJoint2D* edk::physics2D::World2D::createWheelMotorJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                             edk::vec2f32
                                                                             #if defined(EDK_USE_BOX2D)
                                                                             positionA
                                                                             #endif
                                                                             ,
                                                                             edk::physics2D::PhysicObject2D* objectB,
                                                                             edk::vec2f32
                                                                             #if defined(EDK_USE_BOX2D)
                                                                             positionB
                                                                             #endif
                                                                             ,
                                                                             edk::vec2f32
                                                                             #if defined(EDK_USE_BOX2D)
                                                                             direction
                                                                             #endif
                                                                             ,
                                                                             edk::float32
                                                                             #if defined(EDK_USE_BOX2D)
                                                                             maxTorque
                                                                             #endif
                                                                             ,
                                                                             edk::float32
                                                                             #if defined(EDK_USE_BOX2D)
                                                                             speed
                                                                             #endif
                                                                             ,
                                                                             bool
                                                                             #if defined(EDK_USE_BOX2D)
                                                                             collide
                                                                             #endif
                                                                             ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::TypeObject2DStatic || objectB->getType()!=edk::TypeObject2DStatic){
#if defined(EDK_USE_BOX2D)

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
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);

                jointDef.localAxisA = b2Vec2(direction.x * this->percentIn,direction.y * this->percentIn);
                jointDef.localAxisA.Normalize();

                //removed frequency in new box2D
                //removed dampingRatio in new box2D

                jointDef.maxMotorTorque = maxTorque;
                jointDef.motorSpeed = speed;
                jointDef.enableMotor=true;

                //create the edkJoint
                edkJoint = new edk::physics2D::WheelJoint2D(collide);
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;

                    edkJoint->objectA = objectA;
                    edkJoint->objectB = objectB;
                    edkJoint->positionA = positionA;
                    edkJoint->worldPositionA
                            =
                            edk::physics2D::World2D::JointTreeObject::getJointWorldPosition(objectA,positionA)
                            ;
                    edkJoint->positionB = positionB;

                    edkJoint->direction = direction;

                    //create the edkJoint
                    if(this->addJoint(edkJoint)){
                        //
                        b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                        if(joint){
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);
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

#endif
        }
    }
    return NULL;
}
edk::physics2D::WheelJoint2D* edk::physics2D::World2D::createWheelMotorJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,
                                                                             edk::vec2f32
                                                                             #if defined(EDK_USE_BOX2D)
                                                                             worldPosition
                                                                             #endif
                                                                             ,
                                                                             edk::vec2f32
                                                                             #if defined(EDK_USE_BOX2D)
                                                                             direction
                                                                             #endif
                                                                             ,
                                                                             edk::float32
                                                                             #if defined(EDK_USE_BOX2D)
                                                                             maxTorque
                                                                             #endif
                                                                             ,
                                                                             edk::float32
                                                                             #if defined(EDK_USE_BOX2D)
                                                                             speed
                                                                             #endif
                                                                             ,
                                                                             bool
                                                                             #if defined(EDK_USE_BOX2D)
                                                                             collide
                                                                             #endif
                                                                             ){
    //test the object
    if(objectA && objectB){
#if defined(EDK_USE_BOX2D)
        return this->createWheelMotorJoint(objectA,
                                           edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                           objectB,
                                           edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                           direction,
                                           maxTorque,speed,
                                           collide
                                           );
#endif
    }
    return NULL;
}

//WELD
edk::physics2D::Joint2D* edk::physics2D::World2D::createWeldJoint(edk::physics2D::PhysicObject2D* objectA,
                                                                  edk::vec2f32
                                                                  #if defined(EDK_USE_BOX2D)
                                                                  positionA
                                                                  #endif
                                                                  ,
                                                                  edk::physics2D::PhysicObject2D* objectB,
                                                                  edk::vec2f32
                                                                  #if defined(EDK_USE_BOX2D)
                                                                  positionB
                                                                  #endif
                                                                  ,
                                                                  bool
                                                                  #if defined(EDK_USE_BOX2D)
                                                                  collide
                                                                  #endif
                                                                  ){
    //test the object
    if(objectA && objectB){
        //test the objectType
        if(objectA->getType()!=edk::TypeObject2DStatic || objectB->getType()!=edk::TypeObject2DStatic){
#if defined(EDK_USE_BOX2D)

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
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);

                //create the edkJoint
                if((edkJoint = this->addJoint(objectA,positionA,objectB,positionB))){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;

                    b2Joint* joint = (b2Joint*) this->world.CreateJoint(&jointDef);
                    if(joint){
                        //removed from the old box2D version. In the new box2D version the userData is in JointDef
                        //joint->SetUserData(edkJoint);
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

#endif
        }
    }
    return NULL;
}

edk::physics2D::Joint2D* edk::physics2D::World2D::createWeldJoint(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB,
                                                                  edk::vec2f32
                                                                  #if defined(EDK_USE_BOX2D)
                                                                  worldPosition
                                                                  #endif
                                                                  ,
                                                                  bool
                                                                  #if defined(EDK_USE_BOX2D)
                                                                  collide
                                                                  #endif
                                                                  ){
    //test the object
    if(objectA && objectB){
#if defined(EDK_USE_BOX2D)
        return this->createWeldJoint(objectA,
                                     edk::physics2D::World2D::JointTreeObject::getJointPosition(objectA,worldPosition),
                                     objectB,
                                     edk::physics2D::World2D::JointTreeObject::getJointPosition(objectB,worldPosition),
                                     collide
                                     );
#endif
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
        if(objectA->getType()!=edk::TypeObject2DStatic || objectB->getType()!=edk::TypeObject2DStatic){
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
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);

                jointDef.maxLength = maxLength;

                //create the edkJoint
                edkJoint = new edk::physics2D::RopeJoint2D(collide);
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;

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
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);
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
                                                   edk::Math::module(edk::Math::pythagoras(worldPositionA - worldPositionB)),
                                                   collide
                                                   );
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
        if(objectA->getType()!=edk::TypeObject2DStatic || objectB->getType()!=edk::TypeObject2DStatic){
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
                jointDef.localAnchorA = b2Vec2(positionA.x * this->percentIn,positionA.y * this->percentIn);
                jointDef.localAnchorB = b2Vec2(positionB.x * this->percentIn,positionB.y * this->percentIn);

                jointDef.distance = distance;

                //create the edkJoint
                edkJoint = new edk::physics2D::RopeJoint2D(collide);
                if(edkJoint){
                    //in the new version of box2D the userData are setted in jointDef
                    jointDef.userData.pointer = (uintptr_t)edkJoint;

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
                            //removed from the old box2D version. In the new box2D version the userData is in JointDef
                            //joint->SetUserData(edkJoint);
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

#if defined(EDK_USE_BOX2D)

        //get the b2joint
        b2Joint* boxJoint = this->treeJoint.getJoint(joint);
        if(boxJoint){
            this->treeJoint.removeJoint(boxJoint);

            //destroy the joint
            this->world.DestroyJoint(boxJoint);

            if(joint->getType() == EDK_REVOLUTE_JOINT){
                //delete the ground
                if(this->removeObject(joint->objectA)){
                    delete joint->objectA;
                }
            }
            //delete the joint
            delete joint;
            return true;
        }

#endif
    }
    return false;
}
//destroy joint with the object
bool edk::physics2D::World2D::destroyObjectJoints(edk::physics2D::PhysicObject2D* object){
    return this->removeObjectJoints(object);
}
//return the joint
edk::physics2D::Joint2D* edk::physics2D::World2D::getJointInPosition(edk::uint32
                                                                     #if defined(EDK_USE_BOX2D)
                                                                     position
                                                                     #endif
                                                                     ){
#if defined(EDK_USE_BOX2D)
    if(this->treeJoint.size()){
        //return the joint
        return this->treeJoint.getJointInPosition(position);
    }
#endif
    return NULL;
}
//get Joint Type
edk::uint8 edk::physics2D::World2D::getJointTypeInPosition(edk::uint32 position){
    edk::physics2D::Joint2D* joint = this->getJointInPosition(position);
    if(joint){
        return joint->getType();
    }
    return 0u;
}

//return the joints count
edk::uint32 edk::physics2D::World2D::getJointSize(){
#if defined(EDK_USE_BOX2D)
    return this->treeJoint.size();
#else
    return 0u;
#endif
}

//update the joints
bool edk::physics2D::World2D::setMotorJointMaxTorque(edk::physics2D::Joint2D* joint,
                                                     edk::float32
                                                     #if defined(EDK_USE_BOX2D)
                                                     maxTorque
                                                     #endif
                                                     ){
    //text the joint
    if(joint){
        //load the b2joint
#if defined(EDK_USE_BOX2D)

        b2Joint *boxJoint = this->treeJoint.getJoint(joint);
        if(boxJoint){
            switch(boxJoint->GetType()){
            case e_revoluteJoint:
                //
            {
                b2RevoluteJoint* temp = (b2RevoluteJoint*)boxJoint;
                temp->SetMaxMotorTorque(maxTorque * this->percentIn);
                return true;
            }
            case e_motorJoint:
                //
            {
                b2MotorJoint* temp = (b2MotorJoint*)boxJoint;
                temp->SetMaxTorque(maxTorque * this->percentIn);
                return true;
            }
            default:
                break;
            }//end switch
        }

#endif
    }
    return false;
}
bool edk::physics2D::World2D::setMotorJointSpeed(edk::physics2D::Joint2D* joint,
                                                 edk::float32
                                                 #if defined(EDK_USE_BOX2D)
                                                 speed
                                                 #endif
                                                 ){
    //text the joint
    if(joint){
#if defined(EDK_USE_BOX2D)
        //load the b2joint
        b2Joint *boxJoint = this->treeJoint.getJoint(joint);
        if(boxJoint){
            switch(boxJoint->GetType()){
            case e_revoluteJoint:
                //
            {
                b2RevoluteJoint* temp = (b2RevoluteJoint*)boxJoint;
                temp->SetMotorSpeed(speed * this->percentIn);
                return true;
            }
            default:
                break;
            }//end switch
        }
#endif
    }
    return false;
}
//Set the torque and speed
bool edk::physics2D::World2D::setMotorJointTorqueAndSpeed(edk::physics2D::Joint2D* joint,
                                                          edk::float32
                                                          #if defined(EDK_USE_BOX2D)
                                                          maxTorque
                                                          #endif
                                                          ,
                                                          edk::float32
                                                          #if defined(EDK_USE_BOX2D)
                                                          speed
                                                          #endif
                                                          ){
    //text the joint
    if(joint){
#if defined(EDK_USE_BOX2D)
        //load the b2joint
        b2Joint *boxJoint = this->treeJoint.getJoint(joint);
        if(boxJoint){
            switch(boxJoint->GetType()){
            case e_revoluteJoint:
                //
            {
                b2RevoluteJoint* temp = (b2RevoluteJoint*)boxJoint;
                temp->SetMaxMotorTorque(maxTorque * this->percentIn);
                temp->SetMotorSpeed(speed * this->percentIn);
                return true;
            }
            default:
                break;
            }//end switch
        }
#endif
    }
    return false;
}
//Return the joints
edk::float32 edk::physics2D::World2D::getRevoluteJointAngle(edk::physics2D::Joint2D* joint){
    //text the joint
    if(joint){
#if defined(EDK_USE_BOX2D)
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
#endif
    }
    return 0.f;
}
edk::float32 edk::physics2D::World2D::getMotorJointTorque(edk::physics2D::Joint2D* joint){
    //text the joint
    if(joint){
#if defined(EDK_USE_BOX2D)
        //load the b2joint
        b2Joint *boxJoint = this->treeJoint.getJoint(joint);
        if(boxJoint){
            switch(boxJoint->GetType()){
            case e_revoluteJoint:
                //
            {
                b2RevoluteJoint* temp = (b2RevoluteJoint*)boxJoint;
                return temp->GetMaxMotorTorque() * this->percentOut;
            }
            default:
                break;
            }//end switch
        }
#endif
    }
    return 0.f;
}
edk::float32 edk::physics2D::World2D::getMotorJointSpeed(edk::physics2D::Joint2D* joint){
    //text the joint
    if(joint){
#if defined(EDK_USE_BOX2D)
        //load the b2joint
        b2Joint *boxJoint = this->treeJoint.getJoint(joint);
        if(boxJoint){
            switch(boxJoint->GetType()){
            case e_revoluteJoint:
                //
            {
                b2RevoluteJoint* temp = (b2RevoluteJoint*)boxJoint;
                return temp->GetMotorSpeed() * this->percentOut;
            }
            default:
                break;
            }//end switch
        }
#endif
    }
    return 0.f;
}
//set the mouse target
bool edk::physics2D::World2D::setMouseJointTarget(edk::physics2D::MouseJoint2D* mouseJoint,
                                                  edk::vec2f32
                                                  #if defined(EDK_USE_BOX2D)
                                                  target
                                                  #endif
                                                  ){
    if(mouseJoint){
#if defined(EDK_USE_BOX2D)
        //get the b2Jointt
        b2Joint *boxJoint = this->treeJoint.getJoint(mouseJoint);
        if(boxJoint){
            switch(boxJoint->GetType()){
            case e_mouseJoint:
                //
            {
                b2MouseJoint* temp = (b2MouseJoint*)boxJoint;
                temp->SetTarget(b2Vec2(target.x,target.y));
                return true;
            }
            default:
                break;
            }//end switch
        }
#endif
    }
    return false;
}
bool edk::physics2D::World2D::setMouseJointTarget(edk::physics2D::MouseJoint2D* mouseJoint,edk::float32 x,edk::float32 y){
    return this->setMouseJointTarget(mouseJoint,edk::vec2f32(x,y));
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
                        if(xml->addSelectedNextChild("meter")){
                            if(xml->selectChild("meter")){
                                xml->setSelectedString(this->getMeterDistance());
                                xml->selectFather();
                            }
                        }
#if defined(EDK_USE_BOX2D)
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
                                        object = (edk::physics2D::PhysicObject2D*)body->GetUserData().pointer;
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
                                        object = (edk::physics2D::PhysicObject2D*)body->GetUserData().pointer;
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
                                        object = (edk::physics2D::PhysicObject2D*)body->GetUserData().pointer;
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

#endif
                        ret=true;
                        xml->selectFather();
                    }
                }
                free(name);
            }
            free(nameID);
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
                    if(xml->selectChild("meter")){
                        this->setMeterDistance(xml->getSelectedStringAsFloat32());
                        xml->selectFather();
                    }
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
                free(name);
            }
            free(nameID);
        }
        return ret;
    }
    return false;
}
