#include "PhysicObject2D.h"

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

edk::physics2D::PhysicObject2D::PhysicObject2D(){
    this->fixedRotation=false;
    this->canSleep=true;
    this->isObjectSensor=false;

    this->speed=0.f;
    this->linearVelocity = edk::vec2f32(0,0);
    this->linearVelocitySetted=false;
    this->angularVelocity=0.f;
    this->angularVelocitySetted=false;
    this->direction = edk::vec2f32(0,0);
    this->physType=0u;
}
edk::physics2D::PhysicObject2D::~PhysicObject2D(){
    if(!this->canDeleteObject){
        //set the mesh to not delete
        this->physicMesh.cantDeleteList();
        this->animationPosition.cantDeleteGroup();
        this->animationRotation.cantDeleteGroup();
        this->treeCollisionGroups.cantDestruct();
        this->treeNotCollisionGroups.cantDestruct();
        edk::Object2D::cantDeleteObject2D();
    }
}

//set the lonearVelocity
void edk::physics2D::PhysicObject2D::setLinearVelocity(edk::vec2f32 velocity){
    //set linear velocity
    this->linearVelocity = velocity;
    //calculate the speed
    this->speed = edk::Math::pythagoras2f(this->linearVelocity);
    //get the direction
    this->direction = edk::Math::normalise2f(this->linearVelocity);
    this->linearVelocitySetted=true;
}
void edk::physics2D::PhysicObject2D::setLinearVelocity(edk::float32 x,edk::float32 y){
    this->setLinearVelocity(edk::vec2f32(x,y));
}
void edk::physics2D::PhysicObject2D::setAngularVelocity(edk::float32 angle){
    this->angularVelocity = angle;
    this->angularVelocitySetted=true;
}
//remove all meshes
void edk::physics2D::PhysicObject2D::cleanMeshes(){
    edk::Object2D::cleanMeshes();
    this->physicMesh.cleanPolygons();
}
void edk::physics2D::PhysicObject2D::cleanMesh(){
    edk::Object2D::cleanMeshes();
}

//return the speed
edk::float32 edk::physics2D::PhysicObject2D::getSpeed(){
    return this->speed;
}
//return the direction
edk::vec2f32 edk::physics2D::PhysicObject2D::getDirection(){
    return this->direction;
}
//rturn the linearVelocity
edk::vec2f32 edk::physics2D::PhysicObject2D::getLinearVelocity(){
    this->linearVelocitySetted=false;
    edk::vec2f32 ret = this->linearVelocity;
    this->linearVelocity = edk::vec2f32(0,0);
    return ret;
}
//return if set the linearVelocity
bool edk::physics2D::PhysicObject2D::haveSettedLinearVelocity(){
    if(this->linearVelocitySetted){
        this->linearVelocitySetted=false;
        return true;
    }
    return false;
}
//return the angular velocity
edk::float32 edk::physics2D::PhysicObject2D::getAngularVelocity(){
    this->angularVelocitySetted=false;
    edk::float32 ret = this->angularVelocity;
    this->angularVelocity = 0.f;
    return ret;
}
//return if set angular velocoty
bool edk::physics2D::PhysicObject2D::haveSettedAngularVelocity(){
    if(this->angularVelocitySetted){
        this->angularVelocitySetted=false;
        return true;
    }
    return false;
}
void edk::physics2D::PhysicObject2D::removeAllMesh(){
    this->cleanMesh();
}

//get the bodyType
edk::uint8 edk::physics2D::PhysicObject2D::getType(){
    return this->physType;
}

//return if it's a sensor
bool edk::physics2D::PhysicObject2D::isSensor(){
    return this->isObjectSensor;
}

//add a group
bool edk::physics2D::PhysicObject2D::addCollisionGroup(edk::uint32 id){
    //remove from notCollisionGroup
    this->removeNotCollisionGroup(id);
    if(id){
        return this->treeCollisionGroups.add(id);
    }
    return false;
}
bool edk::physics2D::PhysicObject2D::addNotCollisionGroup(edk::uint32 id){
    //remove from collision group
    this->removeCollisionGroup(id);
    if(id){
        return this->treeNotCollisionGroups.add(id);
    }
    return false;
}
bool edk::physics2D::PhysicObject2D::removeCollisionGroup(edk::uint32 id){
    return this->treeCollisionGroups.remove(id);
}
bool edk::physics2D::PhysicObject2D::removeNotCollisionGroup(edk::uint32 id){
    return this->treeNotCollisionGroups.remove(id);
}
void edk::physics2D::PhysicObject2D::cleanCollisionGroups(){
    this->treeCollisionGroups.clean();
}
void edk::physics2D::PhysicObject2D::cleanNotCollisionGroups(){
    this->treeNotCollisionGroups.clean();
}
void edk::physics2D::PhysicObject2D::cleanAllGroups(){
    this->cleanCollisionGroups();
    this->cleanNotCollisionGroups();
}
bool edk::physics2D::PhysicObject2D::haveCollisionGroup(edk::uint32 id){
    return this->treeCollisionGroups.haveElement(id);
}
bool edk::physics2D::PhysicObject2D::haveNotCollisionGroup(edk::uint32 id){
    return this->treeNotCollisionGroups.haveElement(id);
}
edk::uint32 edk::physics2D::PhysicObject2D::getCollisionGroupInPosition(edk::uint32 position){
    return this->treeCollisionGroups.getElementInPosition(position);
}
edk::uint32 edk::physics2D::PhysicObject2D::getNotCollisionGroupInPosition(edk::uint32 position){
    return this->treeNotCollisionGroups.getElementInPosition(position);
}
//get group size
edk::uint32 edk::physics2D::PhysicObject2D::getCollisionGroupSize(){
    return this->treeCollisionGroups.size();
}
edk::uint32 edk::physics2D::PhysicObject2D::getNotCollisionGroupSize(){
    return this->treeNotCollisionGroups.size();
}

void edk::physics2D::PhysicObject2D::drawWirePhysics(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    this->physicMesh.drawWirePolygons();

    edk::GU::guPopMatrix();
}

//update all animations
bool edk::physics2D::PhysicObject2D::updateAnimations(){

    bool ret=false;
    //bool success;
    //test if are playing the animations
    if(this->animationPosition.isPlaying()){
        //set the X and Y
        this->animationPosition.setX(this->position.x);
        this->animationPosition.setY(this->position.y);
        //
        this->animationPosition.updateClockAnimation();

        //get X and Y
        this->position = edk::vec2f32(this->animationPosition.getX(),
                                      this->animationPosition.getY()
                                      );
        ret=true;
    }
    if(this->animationRotation.isPlaying()){
        //set the angle
        this->animationRotation.setX(this->angle);
        //update
        this->animationRotation.updateClockAnimation();
        //get the new X
        this->angle = this->animationRotation.getX();
        ret=true;
    }
    this->updateMeshAnimations();
    return ret;
}

//XML
bool edk::physics2D::PhysicObject2D::writeToXML(edk::XML* xml,edk::uint32 id,bool connected){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"physicObject_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //set the string
                        if(connected){
                            xml->setSelectedString("true");
                        }
                        //write object
                        edk::Object2D::writeToXML(xml,id);
                        //write type
                        edk::char8* temp;
                        edk::char8* nameTemp;
                        edk::char8* iTemp;
                        temp = edk::String::int32ToStr(this->getType());
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"type",temp);
                            delete[] temp;
                        }
                        //write sensor
                        if(this->isSensor()){
                            xml->addSelectedNextAttribute("sensor","true");
                        }
                        else{
                            xml->addSelectedNextAttribute("sensor","false");
                        }
                        //write fixedRot
                        if(this->fixedRotation){
                            xml->addSelectedNextAttribute("fixedRot","true");
                        }
                        else{
                            xml->addSelectedNextAttribute("fixedRot","false");
                        }
                        //write canSleep
                        if(this->canSleep){
                            xml->addSelectedNextAttribute("canSleep","true");
                        }
                        else{
                            xml->addSelectedNextAttribute("canSleep","false");
                        }
                        //write the mesh
                        this->physicMesh.writeToXML(xml,0u);
                        edk::uint32 size = 0u;
                        //write collision groups
                        if(xml->addSelectedNextChild("collision")){
                            if(xml->selectChild("collision")){
                                size = this->treeCollisionGroups.size();
                                for(edk::uint32 i= 0u;i<size;i++){
                                    temp = edk::String::int64ToStr(this->treeCollisionGroups.getElementInPosition(i));
                                    if(temp){
                                        iTemp = edk::String::int64ToStr(i);
                                        if(iTemp){
                                            nameTemp = edk::String::strCat((edk::char8*)"c",iTemp);
                                            if(nameTemp){
                                                xml->addSelectedNextAttribute(nameTemp,temp);
                                                delete[] nameTemp;
                                            }
                                            delete[] iTemp;
                                        }
                                        delete[] temp;
                                    }
                                }
                                xml->selectFather();
                            }
                        }
                        //write notCollision groups
                        if(xml->addSelectedNextChild("notCollision")){
                            if(xml->selectChild("notCollision")){
                                size = this->treeCollisionGroups.size();
                                for(edk::uint32 i= 0u;i<size;i++){
                                    temp = edk::String::int64ToStr(this->treeCollisionGroups.getElementInPosition(i));
                                    if(temp){
                                        iTemp = edk::String::int64ToStr(i);
                                        if(iTemp){
                                            nameTemp = edk::String::strCat((edk::char8*)"n",iTemp);
                                            if(nameTemp){
                                                xml->addSelectedNextAttribute(nameTemp,temp);
                                                delete[] nameTemp;
                                            }
                                            delete[] iTemp;
                                        }
                                        delete[] temp;
                                    }
                                }
                                xml->selectFather();
                            }
                        }
                        //write physics animations
                        this->animationPosition.writeToXML(xml,0u);
                        this->animationRotation.writeToXML(xml,1u);

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
bool edk::physics2D::PhysicObject2D::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"physicObject_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    edk::char8* nameTemp;
                    edk::char8* iTemp;
                    this->physicMesh.cleanPolygons();
                    //read the object
                    edk::Object2D::readFromXML(xml,id);
                    //read type
                    this->physType = edk::String::strToInt32(xml->getSelectedAttributeValueByName("type"));
                    //read sensor
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("sensor"),(edk::char8*)"true")) this->isObjectSensor=true;
                    else this->isObjectSensor=false;
                    //read fixedRot
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("fixedRot"),(edk::char8*)"true")) this->fixedRotation=true;
                    else this->fixedRotation=false;
                    //read canSleep
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("canSleep"),(edk::char8*)"true")) this->canSleep=true;
                    else this->canSleep=false;
                    //read mesh
                    this->physicMesh.readFromXML(xml,0u);
                    //read collisionGroup
                    this->treeCollisionGroups.clean();
                    if(xml->selectChild("collision")){
                        edk::uint32 i=0u;
                        bool cont=true;
                        do{
                            iTemp = edk::String::int64ToStr(i);
                            if(iTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"c",iTemp);
                                if(nameTemp){
                                    if(xml->haveSelectedAttribute(nameTemp)){
                                        //read the value
                                        this->treeCollisionGroups.add(edk::String::strToInt64(xml->getSelectedAttributeValueByName(nameTemp)));
                                    }
                                    else cont=false;
                                    delete[] nameTemp;
                                }
                                delete[] iTemp;
                            }
                            i++;
                        }while(cont);
                        xml->selectFather();
                    }
                    //read notCollisionGroup
                    this->treeNotCollisionGroups.clean();
                    if(xml->selectChild("notCollision")){
                        edk::uint32 i=0u;
                        bool cont=true;
                        do{
                            iTemp = edk::String::int64ToStr(i);
                            if(iTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"n",iTemp);
                                if(nameTemp){
                                    if(xml->haveSelectedAttribute(nameTemp)){
                                        //read the value
                                        this->treeNotCollisionGroups.add(edk::String::strToInt64(xml->getSelectedAttributeValueByName(nameTemp)));
                                    }
                                    else cont=false;
                                    delete[] nameTemp;
                                }
                                delete[] iTemp;
                            }
                            i++;
                        }while(cont);
                        xml->selectFather();
                    }
                    //write physics animations
                    this->animationPosition.readFromXML(xml,0u);
                    this->animationRotation.readFromXML(xml,1u);

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
bool edk::physics2D::PhysicObject2D::readFromXMLisSensor(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"physicObject_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //read sensor
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("sensor"),(edk::char8*)"true"))
                        ret=true;
                    else
                        ret=false;
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
