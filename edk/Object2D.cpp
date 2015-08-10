#include "Object2D.h"

/*
Library Object2D - Object in the 2D world.
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

#ifdef printMessages
#warning "            Inside Object2D.cpp"
#endif

edk::Object2D::Object2D(){
    //
    this->selected=NULL;
    //rotation
    this->angle=0.0f;
    //Scale
    this->size = edk::size2f32(1.f,1.f);
    this->canDeleteObject=true;
    this->actions.setReadXMLActionFunction(&edk::Object2D::readXMLAction);
}

edk::Object2D::~Object2D(){
    this->actions.cleanReadXMLActionFunction();
    //dtor
    if(this->canDeleteObject){
        this->cleanMeshes();
    }
    else{
        this->meshes.cantDestroy();
        this->meshes.cantDeleteMeshes();
        this->animationPosition.cantDeleteGroup();
        this->animationRotation.cantDeleteGroup();
        this->animationSize.cantDeleteGroup();
        this->actions.cantDeleteGroup();
    }
    this->canDeleteObject=true;
}

//Function to read the actions
edk::Action* edk::Object2D::readXMLAction(edk::classID thisPointer,edk::uint32 actionCode){
    switch(actionCode){
    case 1u:
    {
        //ActionPosition
        return new edk::Object2D::ActionPosition((edk::Object2D*)thisPointer,edk::vec2f32(0,0));
        break;
    }
    case 2u:
    {
        //ActionMove
        return new edk::Object2D::ActionMove((edk::Object2D*)thisPointer,0,edk::vec2f32(0,0));
        break;
    }
    case 3u:
    {
        //ActionSetSize
        return new edk::Object2D::ActionSetSize((edk::Object2D*)thisPointer,edk::size2f32(1,1));
        break;
    }
    case 4u:
    {
        //ActionSize
        return new edk::Object2D::ActionSize((edk::Object2D*)thisPointer,0,edk::size2f32(1,1));
        break;
    }
    case 5u:
    {
        //ActionSetAngle
        return new edk::Object2D::ActionSetAngle((edk::Object2D*)thisPointer,0);
        break;
    }
    case 6u:
    {
        //ActionAngle
        return new edk::Object2D::ActionAngle((edk::Object2D*)thisPointer,0,0);
        break;
    }
    case 7u:
    {
        //ActionMeshName
        return new edk::Object2D::ActionMeshName((edk::Object2D*)thisPointer,0,NULL,false);
        break;
    }
    case 8u:
    {
        //ActionMeshStop
        return new edk::Object2D::ActionMeshStop((edk::Object2D*)thisPointer,0);
        break;
    }
    }
    return new edk::ActionZero();
}

//Actions
edk::Object2D::ActionPosition::ActionPosition(edk::Object2D* object, edk::vec2f32 position){
    this->position=position;
    this->object=object;
    this->code = 1u;
}
//run action function
void edk::Object2D::ActionPosition::runAction(){
    this->object->position = this->position;
}
//write to XML
bool edk::Object2D::ActionPosition::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write the position
                    xml->addSelectedNextAttribute("positionX",this->position.x);
                    xml->addSelectedNextAttribute("positionY",this->position.y);

                    ret=true;
                    //select father
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] number;
        }
    }
    return ret;
}
//read XML
bool edk::Object2D::ActionPosition::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read the position
                    this->position.x = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionX"));
                    this->position.y = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionY"));

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] number;
        }
    }
    return ret;
}
//GET
edk::vec2f32 edk::Object2D::ActionPosition::getPosition(){
    return this->position;
}
edk::Object2D::ActionMove::ActionMove(edk::Object2D* object,edk::float32 duration, edk::vec2f32 position){
    this->position=position;
    this->duration = duration;
    this->object=object;
    this->code = 2u;
}
//run action function
void edk::Object2D::ActionMove::runAction(){
    this->object->animationPosition.cleanAnimations();
    this->object->animationPosition.addFirstInterpolationLine(0,this->object->position.x,this->object->position.y,this->duration,this->position.x,this->position.y);
    this->object->animationPosition.playForward();
}
//write to XML
bool edk::Object2D::ActionMove::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write the position
                    xml->addSelectedNextAttribute("positionX",this->position.x);
                    xml->addSelectedNextAttribute("positionY",this->position.y);
                    //write the duration
                    xml->addSelectedNextAttribute("duration",this->duration);

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] number;
        }
    }
    return ret;
}
//read XML
bool edk::Object2D::ActionMove::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read the position
                    this->position.x = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionX"));
                    this->position.y = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionY"));
                    //read duration
                    this->duration = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("duration"));

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] number;
        }
    }
    return ret;
}
//GET
edk::vec2f32 edk::Object2D::ActionMove::getPosition(){
    return this->position;
}
edk::float32 edk::Object2D::ActionMove::getDuration(){
    return this->duration;
}
edk::Object2D::ActionSetSize::ActionSetSize(edk::Object2D* object, edk::size2f32 size){
    this->object=object;
    this->size=size;
    this->code = 3u;
}
//run action function
void edk::Object2D::ActionSetSize::runAction(){
    this->object->size = this->size;
}
//write to XML
bool edk::Object2D::ActionSetSize::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write the size
                    xml->addSelectedNextAttribute("width",this->size.width);
                    xml->addSelectedNextAttribute("height",this->size.height);

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] number;
        }
    }
    return ret;
}
//read XML
bool edk::Object2D::ActionSetSize::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read the code
                    this->size.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("width"));
                    this->size.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("height"));

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] number;
        }
    }
    return ret;
}
//GET
edk::size2f32 edk::Object2D::ActionSetSize::getSize(){
    return this->size;
}
edk::Object2D::ActionSize::ActionSize(edk::Object2D* object,edk::float32 duration, edk::size2f32 size){
    this->size=size;
    this->duration = duration;
    this->object=object;
    this->code = 4u;
}
//run action function
void edk::Object2D::ActionSize::runAction(){
    this->object->animationSize.cleanAnimations();
    this->object->animationSize.addFirstInterpolationLine(0,this->object->size.width,this->object->size.height,this->duration,this->size.width,this->size.height);
    this->object->animationSize.playForward();
}
//write to XML
bool edk::Object2D::ActionSize::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write the size
                    xml->addSelectedNextAttribute("width",this->size.width);
                    xml->addSelectedNextAttribute("height",this->size.height);
                    //write the duration
                    xml->addSelectedNextAttribute("duration",this->duration);

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] number;
        }
    }
    return ret;
}
//read XML
bool edk::Object2D::ActionSize::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read the code
                    this->size.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("width"));
                    this->size.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("height"));
                    //read the duration
                    this->duration = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("duration"));

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] number;
        }
    }
    return ret;
}
//GET
edk::size2f32 edk::Object2D::ActionSize::getSize(){
    return this->size;
}
edk::float32 edk::Object2D::ActionSize::getDuration(){
    return this->duration;
}
edk::Object2D::ActionSetAngle::ActionSetAngle(edk::Object2D* object, edk::float32 angle){
    this->object = object;
    this->angle = angle;
    this->code = 5u;
}
//run action function
void edk::Object2D::ActionSetAngle::runAction(){
    this->object->angle = this->angle;
}
//write to XML
bool edk::Object2D::ActionSetAngle::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write angle
                    xml->addSelectedNextAttribute("angle",this->angle);

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] number;
        }
    }
    return ret;
}
//read XML
bool edk::Object2D::ActionSetAngle::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read angle
                    this->angle = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("angle"));

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] number;
        }
    }
    return ret;
}
//GET
edk::float32 edk::Object2D::ActionSetAngle::getAngle(){
    return this->angle;
}
edk::Object2D::ActionAngle::ActionAngle(edk::Object2D* object,edk::float32 duration, edk::float32 angle){
    this->object = object;
    this->duration = duration;
    this->angle = angle;
    this->code = 6u;
}
//run action function
void edk::Object2D::ActionAngle::runAction(){
    this->object->animationRotation.cleanAnimations();
    this->object->animationRotation.addFirstInterpolationLine(0,this->object->angle,this->duration,this->angle);
    this->object->animationRotation.playForward();
}
//write to XML
bool edk::Object2D::ActionAngle::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write angle
                    xml->addSelectedNextAttribute("angle",this->angle);
                    //write the duration
                    xml->addSelectedNextAttribute("duration",this->duration);

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] number;
        }
    }
    return ret;
}
//read XML
bool edk::Object2D::ActionAngle::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read angle
                    this->angle = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("angle"));
                    //read duratio
                    this->duration = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("duration"));

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] number;
        }
    }
    return ret;
}
//GET
edk::float32 edk::Object2D::ActionAngle::getAngle(){
    return this->angle;
}
edk::float32 edk::Object2D::ActionAngle::getDuration(){
    return this->duration;
}
edk::Object2D::ActionMeshName::ActionMeshName(edk::Object2D* object,edk::uint32 id, edk::char8* name,bool loop){
    this->object=object;
    this->loop = loop;
    this->id = id;
    this->setName(name);
    this->code = 7u;
}
//run action function
void edk::Object2D::ActionMeshName::runAction(){
    //load the mesh
    edk::shape::Mesh2D* mesh = this->object->getMesh(this->id);
    if(mesh){
        mesh->selectedAnimationSetLoop(this->loop);
        mesh->selectedAnimationPlayNameForward(this->name());
    }
}
//write to XML
bool edk::Object2D::ActionMeshName::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::ActionName::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write the loop
                    if(this->loop){
                        xml->setSelectedString("loopOn");
                    }
                    else{
                        xml->setSelectedString("loopOff");
                    }

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] number;
        }
    }
    return ret;
}
//read XML
bool edk::Object2D::ActionMeshName::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    edk::ActionName::readFromXML(xml,id);
    this->id = 7u;
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read the loop
                    if(edk::String::strCompare((edk::char8*)"loopOn",xml->getSelectedString())){
                        this->loop=true;
                    }
                    else{
                        this->loop=false;
                    }

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] number;
        }
    }
    return ret;
}
//GET
edk::uint32 edk::Object2D::ActionMeshName::getId(){
    return this->id;
}
bool edk::Object2D::ActionMeshName::getLoop(){
    return this->loop;
}
edk::Object2D::ActionMeshStop::ActionMeshStop(edk::Object2D* object,edk::uint32 id){
    this->object=object;
    this->id = id;
    this->code = 8u;
}
//run action function
void edk::Object2D::ActionMeshStop::runAction(){
    //load the mesh
    edk::shape::Mesh2D* mesh = this->object->getMesh(this->id);
    if(mesh){
        mesh->selectedAnimationStop();
    }
}
//write to XML
bool edk::Object2D::ActionMeshStop::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write the ID
                    xml->addSelectedNextAttribute("id",this->id);

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] number;
        }
    }
    return ret;
}
//read XML
bool edk::Object2D::ActionMeshStop::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read the id
                    this->id = edk::String::strToInt64(xml->getSelectedAttributeValueByName("id"));

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] number;
        }
    }
    return ret;
}
//GET
edk::uint32 edk::Object2D::ActionMeshStop::getId(){
    return this->id;
}

//Add a list to the Object2D
edk::uint32 edk::Object2D::addMesh(edk::shape::Mesh2D* mesh){
    //test if the list exist
    if(mesh){
        edk::uint32 ret = 0u;
        //then add the mesh to the list
        ret = this->meshes.pushBackMesh(mesh,false);
        if(ret<this->meshes.size()){
            //test if select the first
            if(this->meshes.size()==1u) this->selectMesh(0u);
            return ret;
        }
    }

    //else return falses
    return 0u;
}
//create a new mesh and add to the meshs stack
edk::shape::Mesh2D* edk::Object2D::newMesh(edk::uint32* position){
    return this->meshes.pushNewMesh(position);
}
//remove a polygonlist
bool edk::Object2D::removeMesh(edk::uint32 position){
    //remove the mesh
    return this->meshes.removeMesh(position);
}
//remove all meshes
void edk::Object2D::cleanMeshes(){
    this->cleanSelected();
    this->meshes.removeAllMeshes();
}

//Select the polygonList
bool edk::Object2D::selectMesh(edk::uint32 position){
    //free the selected
    this->cleanSelected();
    if((this->selected = this->meshes.getMesh(position))){
        return true;
    }
    //else return false
    return false;
}
//return the selected textureID
edk::uint32 edk::Object2D::selectedGetTextureID(edk::uint8 number){
    //test if have one selected mesh
    if(this->selected){
        //return the number
        return this->selected->material.getTexture(number);
    }
    //else return false
    return false;
}
//free the selected
void edk::Object2D::cleanSelected(){
    //
    this->selected=NULL;
}
//return the number of meshs
edk::uint32 edk::Object2D::getMeshSize(){
    return this->meshes.size();
}
//return the mesh pointer
edk::shape::Mesh2D* edk::Object2D::getMesh(edk::uint32 position){
    return this->meshes.getMesh(position);
}
//remove all meshes
void edk::Object2D::removeAllMesh(){
    this->cleanMeshes();
}
//set the polygonsColor
bool edk::Object2D::setPolygonColor(edk::uint32 position,edk::color4f32 color){
    if(this->meshes.getMesh(position)){
        this->meshes.getMesh(position)->setPolygonsColor(color);
    }
    return false;
}
bool edk::Object2D::setPolygonColor(edk::uint32 position,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setPolygonColor(position,edk::color4f32(r,g,b,a));
}

void edk::Object2D::setPolygonsColor(edk::color4f32 color){
    edk::uint32 size = this->meshes.size();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColor(color);
        }
    }
}
void edk::Object2D::setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setPolygonsColor(edk::color4f32(r,g,b,a));
}

//LIGHT
//EDK_LIGHT_LIMIT
bool edk::Object2D::setLight(edk::uint32 position,edk::light::Light light){
    if(position<EDK_LIGHT_LIMIT){
        this->lights[position] = light;
        return true;
    }
    return false;
}
bool edk::Object2D::cleanLight(edk::uint32 position){
    if(position<EDK_LIGHT_LIMIT){
        //
        this->lights[position].clean();
        return true;
    }
    return false;
}
bool edk::Object2D::lightOn(edk::uint32 position){
    if(position<EDK_LIGHT_LIMIT){
        //add the light on the tree
        this->lights[position].on=true;
        return true;
    }
    return false;
}
bool edk::Object2D::lightOff(edk::uint32 position){
    if(position<EDK_LIGHT_LIMIT){
        //remove the position from the tree
        this->lights[position].on=false;
        return true;
    }
    return false;
}

//play all mesh animations
void edk::Object2D::playMeshAnimations(){
    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh2D* mesh;
    for(edk::uint32 i=0u;i<size;i++){
        mesh = this->meshes.getMesh(i);
        if(mesh){
            edk::uint32 polySize = mesh->getPolygonSize();
            for(edk::uint32 j=0u;j<polySize;j++){
                mesh->selectAnimationFramesFromPolygon(j);
                mesh->selectedAnimationPlayForward();
            }
        }
    }
}
bool edk::Object2D::playMeshAnimations(edk::uchar32 position){
    edk::shape::Mesh2D* mesh = this->meshes.getMesh(position);
    if(mesh){
        edk::uint32 polySize = mesh->getPolygonSize();
        for(edk::uint32 j=0u;j<polySize;j++){
            mesh->selectAnimationFramesFromPolygon(j);
            mesh->selectedAnimationPlayForward();
        }
        return true;
    }
    return false;
}
//pause polygons animations
void edk::Object2D::pauseMeshAnimations(){
    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh2D* mesh;
    for(edk::uint32 i=0u;i<size;i++){
        mesh = this->meshes.getMesh(i);
        if(mesh){
            edk::uint32 polySize = mesh->getPolygonSize();
            for(edk::uint32 j=0u;j<polySize;j++){
                mesh->selectAnimationFramesFromPolygon(j);
                mesh->selectedAnimationPause();
            }
        }
    }
}
bool edk::Object2D::pauseMeshAnimations(edk::uchar32 position){
    edk::shape::Mesh2D* mesh = this->meshes.getMesh(position);
    if(mesh){
        edk::uint32 polySize = mesh->getPolygonSize();
        for(edk::uint32 j=0u;j<polySize;j++){
            mesh->selectAnimationFramesFromPolygon(j);
            mesh->selectedAnimationPause();
        }
        return true;
    }
    return false;
}
//update mesh animations
void edk::Object2D::updateMeshAnimations(){
    //
    //update mesh animations
    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh2D *mesh;
    for(edk::uint32 i=0u;i<size;i++){
        mesh = this->meshes.getMesh(i);
        if(mesh){
            mesh->updateFramesAnimations();
        }
    }
}
bool edk::Object2D::updateMeshAnimations(edk::uchar32 position){
    edk::shape::Mesh2D* mesh = this->meshes.getMesh(position);
    if(mesh){
        edk::uint32 polySize = mesh->getPolygonSize();
        for(edk::uint32 j=0u;j<polySize;j++){
            mesh->selectAnimationFramesFromPolygon(j);
            mesh->updateFramesAnimations();
        }
        return true;
    }
    return false;
}

//update all animations
bool edk::Object2D::updateAnimations(){
    bool ret=false;
    bool success;
    //test if are playing the animations
    if(this->animationPosition.isPlaying()){
        //
        this->animationPosition.updateClockAnimation();
        edk::vec2f32 posTemp;
        posTemp.x = this->animationPosition.getClockX(&success);
        if(success){
            posTemp.y = this->animationPosition.getClockY(&success);
            if(success){
                //set the value
                this->position = posTemp;
                ret=true;
            }
        }
    }
    if(this->animationRotation.isPlaying()){
        //
        this->animationRotation.updateClockAnimation();
        edk::float32 angleTemp = this->animationRotation.getClockX(&success);
        if(success){
            //set the value
            this->angle = angleTemp;
            ret=true;
        }
    }
    if(this->animationSize.isPlaying()){
        //
        this->animationSize.updateClockAnimation();
        edk::size2f32 sizeTemp;
        sizeTemp.width = this->animationSize.getClockX(&success);
        if(success){
            sizeTemp.height = this->animationSize.getClockY(&success);
            if(success){
                //set the value
                this->size = sizeTemp;
                ret=true;
            }
        }
    }
    this->updateMeshAnimations();
    return ret;
}

//ACTIONS
//play actions
void edk::Object2D::playForwardActions(){
    this->actions.playForward();
}
void edk::Object2D::playForwardInActions(edk::float32 second){
    this->actions.playForwardIn(second);
}
void edk::Object2D::pauseActions(){
    this->actions.pause();
}
void edk::Object2D::stopActions(){
    this->actions.stop();
}
//set loop
void edk::Object2D::setLoopActions(bool loop){
    this->actions.setLoop(loop);
}
void edk::Object2D::loopOnActions(){
    this->actions.loopOn();
}
void edk::Object2D::loopOffActions(){
    this->actions.loopOff();
}

//return if are playing
bool edk::Object2D::isPlayingActions(){
    return this->actions.isPlaying();
}
bool edk::Object2D::isPausedActions(){
    return this->actions.isPaused();
}
//update actions
void edk::Object2D::updateActions(){
    this->actions.update();
}
//remove actions
void edk::Object2D::removeAllActions(){
    this->actions.clean();
}
bool edk::Object2D::removeActionSecond(edk::float32 second){
    this->actions.removeSecond(second);
}
//Add zero action
bool edk::Object2D::actionZero(edk::float32 second){
    return this->actions.addAction(second,new edk::ActionZero);
}
//add move action
bool edk::Object2D::actionSetPosition(edk::float32 second,edk::vec2f32 position){
    return this->actions.addAction(second,new edk::Object2D::ActionPosition(this,position));
}
bool edk::Object2D::actionSetPosition(edk::float32 second,edk::float32 x,edk::float32 y){
    return this->actionSetPosition(second,edk::vec2f32(x,y));
}
//add move action
bool edk::Object2D::actionMove(edk::float32 second,edk::float32 duration, edk::vec2f32 position){
    //create the action
    if (this->actions.addAction(second,new edk::Object2D::ActionMove(this,duration,position))){
        this->actions.addZeroAction(second+duration);
        return true;
    }
    return false;
}
bool edk::Object2D::actionMove(edk::float32 second,edk::float32 duration, edk::float32 x,edk::float32 y){
    return this->actionMove(second,duration, edk::vec2f32(x,y));
}
bool edk::Object2D::actionMoveTo(edk::float32 start,edk::float32 end, edk::vec2f32 position){
    return this->actionMove(start,end-start, position);
}
bool edk::Object2D::actionMoveTo(edk::float32 start,edk::float32 end, edk::float32 x,edk::float32 y){
    return this->actionMove(start,end-start,x,y);
}
//add scale action
bool edk::Object2D::actionSetSize(edk::float32 second,edk::size2f32 size){
    //create the action
    return this->actions.addAction(second,new edk::Object2D::ActionSetSize(this,size));
}
bool edk::Object2D::actionSetSize(edk::float32 second,edk::float32 width,edk::float32 height){
    return this->actionSetSize(second,edk::size2f32(width,height));
}
bool edk::Object2D::actionSetSize(edk::float32 second,edk::float32 size){
    return this->actionSetSize(second,size,size);
}
//add scale action
bool edk::Object2D::actionScale(edk::float32 second,edk::float32 duration, edk::size2f32 size){
    //create the action
    if (this->actions.addAction(second,new edk::Object2D::ActionSize(this,duration,size))){
        this->actions.addZeroAction(second+duration);
        return true;
    }
    return false;
}
bool edk::Object2D::actionScale(edk::float32 second,edk::float32 duration, edk::float32 width,edk::float32 height){
    return this->actionScale(second,duration, edk::size2f32( width,height));
}
bool edk::Object2D::actionScale(edk::float32 second,edk::float32 duration, edk::float32 size){
    return this->actionScale(second,duration, size,size);
}
bool edk::Object2D::actionScaleTo(edk::float32 start,edk::float32 end, edk::size2f32 size){
    return this->actionScale(start,end-start, size);
}
bool edk::Object2D::actionScaleTo(edk::float32 start,edk::float32 end, edk::float32 width,edk::float32 height){
    return this->actionScale(start,end-start, width,height);
}
bool edk::Object2D::actionScaleTo(edk::float32 start,edk::float32 end, edk::float32 size){
    return this->actionScale(start,end-start, size);
}
//add angle action
bool edk::Object2D::actionSetAngle(edk::float32 second,edk::float32 angle){
    return this->actions.addAction(second,new edk::Object2D::ActionSetAngle(this,angle));
}
//add angle action
bool edk::Object2D::actionRotateFor(edk::float32 second,edk::float32 duration, edk::float32 angle){
    if(this->actions.addAction(second,new edk::Object2D::ActionAngle(this,duration,angle))){
        this->actions.addZeroAction(second);
        return true;
    }
    return false;
}
bool edk::Object2D::actionRotateTo(edk::float32 start,edk::float32 end, edk::float32 angle){
    return this->actionRotateFor(start,end-start, angle);
}
//MESH SPRITE SHEET
bool edk::Object2D::actionPlayName(edk::float32 second,edk::uint32 id,edk::char8* name,bool loop){
    //
    return this->actions.addAction(second,new edk::Object2D::ActionMeshName(this,id,name,loop));
}
bool edk::Object2D::actionPlayName(edk::float32 second,edk::uint32 id,const char* name,bool loop){
    //
    return actionPlayName(second,id,(edk::char8*)name,loop);
}
bool edk::Object2D::actionPlayNameFor(edk::float32 second,edk::float32 duration,edk::uint32 id,edk::char8* name){
    if(this->actions.addAction(second,new edk::Object2D::ActionMeshName(this,id,name,true))){
        //add the stop action
        this->actions.addAction(second+duration,new edk::Object2D::ActionMeshStop(this,id));
        return true;
    }
    return false;
}
bool edk::Object2D::actionPlayNameFor(edk::float32 second,edk::float32 duration,edk::uint32 id,const char* name){
    return this->actionPlayNameFor(second,duration,id,(edk::char8*)name);
}

//DRAW
//print the mesh
void edk::Object2D::print(){
    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh2D* mesh;
    //print all polygonList
    for(edk::uint32 i=0u;i<size;i++){
        //
        mesh = this->meshes.getMesh(i);
        if(mesh){
            //
            printf("\nMESH %u"
                   ,i
                   );
            mesh->print();
        }
    }
}
//draw the mesh
void edk::Object2D::draw(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    /*
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_POSITION,this->position);
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_SPOT_DIRECTION,this->direction);


    edk::light::Light lights[EDK_LIGHT_LIMIT];
    edk::vec2f32 lightPositions[EDK_LIGHT_LIMIT];
    edk::vec2f32 lightDirections[EDK_LIGHT_LIMIT];
    */

    edk::GU::guEnable(GU_LIGHTING);
    //glEnable(GL_RESCALE_NORMAL);

    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    bool haveLight=false;

    {
        edk::vec2f32 temp;
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);
                this->lights[i].draw(i);
                this->lightIsOn[i] = true;

                //translate pivo
                this->lightPositions[i][0u] = this->lights[i].getPositionX() + this->pivo.x;
                this->lightPositions[i][1u] = this->lights[i].getPositionY() + this->pivo.y;
                this->lightPositions[i][2u] = this->lights[i].getPositionZ();
                this->lightPositions[i][3u] = 1.f;

                this->lightDirections[i][0u] = this->lights[i].getDirectionX() + this->pivo.x;
                this->lightDirections[i][1u] = this->lights[i].getDirectionY() + this->pivo.y;
                this->lightDirections[i][2u] = this->lights[i].getDirectionZ();
                this->lightDirections[i][3u] = 1.f;

                //translate
                this->lightPositions[i][0u] -= this->position.x;
                this->lightPositions[i][1u] -= this->position.y;

                this->lightDirections[i][0u] -= this->position.x;
                this->lightDirections[i][1u] -= this->position.y;

                //scale
                this->lightPositions[i][0u] *= (1.f/this->size.width);
                this->lightPositions[i][1u] *= (1.f/this->size.height);

                this->lightDirections[i][0u] *= (1.f/this->size.width);
                this->lightDirections[i][1u] *= (1.f/this->size.height);

                //rotate
                temp = edk::Math::rotatePlus2f(edk::vec2f32(this->lightPositions[i][0u],this->lightPositions[i][1u])
                        ,this->angle*-1.f
                        );
                this->lightPositions[i][0u] = temp.x;
                this->lightPositions[i][1u] = temp.y;

                temp = edk::Math::rotatePlus2f(edk::vec2f32(this->lightDirections[i][0u],this->lightDirections[i][1u])
                        ,this->angle*-1.f
                        );
                this->lightDirections[i][0u] = temp.x;
                this->lightDirections[i][1u] = temp.y;


                edk::GU::guLightfv32(GU_LIGHT0+i,GU_POSITION,this->lightPositions[i]);
                edk::GU::guLightfv32(GU_LIGHT0+i,GU_SPOT_DIRECTION,this->lightDirections[i]);

                haveLight=true;

            }
            else{
                this->lightIsOn[i] = false;
                edk::GU::guDisable(GU_LIGHT0+i);
            }
        }
    }

    edk::shape::Mesh2D* mesh;
    if(haveLight){
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    mesh->drawOneTextureWithLight(&this->lightPositions,&this->lightDirections,&this->lightIsOn);
                }
                else{
                    mesh->drawMultiTextureWithLight(&this->lightPositions,&this->lightDirections,&this->lightIsOn);
                }
            }
        }
    }
    else{
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    mesh->drawOneTexture();
                }
                else{
                    mesh->drawMultiTexture();
                }
            }
        }
    }
    //glEnable(GL_RESCALE_NORMAL);
    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
}
void edk::Object2D::drawWithoutMaterial(){
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

    edk::shape::Mesh2D* mesh;
    //print all polygonList
    for(edk::uint32 i=this->meshes.size();i>0u;i--){
        //
        mesh = this->meshes.getMesh(i-1u);
        if(mesh){
            mesh->drawOneTexture();
        }
    }
    edk::GU::guPopMatrix();
}
void edk::Object2D::drawWithoutMaterialWithLight(){
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

    bool haveLight=false;

    {
        edk::vec2f32 temp;
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);
                this->lights[i].draw(i);
                this->lightIsOn[i] = true;

                //translate pivo
                this->lightPositions[i][0u] = this->lights[i].getPositionX() + this->pivo.x;
                this->lightPositions[i][1u] = this->lights[i].getPositionY() + this->pivo.y;
                this->lightPositions[i][2u] = this->lights[i].getPositionZ();
                this->lightPositions[i][3u] = 1.f;

                this->lightDirections[i][0u] = this->lights[i].getDirectionX() + this->pivo.x;
                this->lightDirections[i][1u] = this->lights[i].getDirectionY() + this->pivo.y;
                this->lightDirections[i][2u] = this->lights[i].getDirectionZ();
                this->lightDirections[i][3u] = 1.f;

                //translate
                this->lightPositions[i][0u] -= this->position.x;
                this->lightPositions[i][1u] -= this->position.y;

                this->lightDirections[i][0u] -= this->position.x;
                this->lightDirections[i][1u] -= this->position.y;

                //scale
                this->lightPositions[i][0u] *= (1.f/this->size.width);
                this->lightPositions[i][1u] *= (1.f/this->size.height);

                this->lightDirections[i][0u] *= (1.f/this->size.width);
                this->lightDirections[i][1u] *= (1.f/this->size.height);

                //rotate
                temp = edk::Math::rotatePlus2f(edk::vec2f32(this->lightPositions[i][0u],this->lightPositions[i][1u])
                        ,this->angle*-1.f
                        );
                this->lightPositions[i][0u] = temp.x;
                this->lightPositions[i][1u] = temp.y;

                temp = edk::Math::rotatePlus2f(edk::vec2f32(this->lightDirections[i][0u],this->lightDirections[i][1u])
                        ,this->angle*-1.f
                        );
                this->lightDirections[i][0u] = temp.x;
                this->lightDirections[i][1u] = temp.y;


                edk::GU::guLightfv32(GU_LIGHT0+i,GU_POSITION,this->lightPositions[i]);
                edk::GU::guLightfv32(GU_LIGHT0+i,GU_SPOT_DIRECTION,this->lightDirections[i]);

                haveLight=true;

            }
            else{
                this->lightIsOn[i] = false;
                edk::GU::guDisable(GU_LIGHT0+i);
            }
        }
    }

    edk::shape::Mesh2D* mesh;
    if(haveLight){
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);
            if(mesh){
                mesh->drawOneTextureWithLight(&this->lightPositions,&this->lightDirections,&this->lightIsOn);
            }
        }
    }
    else{
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);
            if(mesh){
                mesh->drawOneTexture();
            }
        }
    }
    edk::GU::guPopMatrix();
}
void edk::Object2D::drawWire(){
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

    edk::shape::Mesh2D* mesh;
    //print all polygonList
    for(edk::uint32 i=this->meshes.size();i>0u;i--){
        //
        mesh = this->meshes.getMesh(i-1u);
        if(mesh){
            mesh->drawWirePolygons();
        }
    }
    edk::GU::guPopMatrix();
}

//draw the pivo
void edk::Object2D::drawPivo(edk::float32 size,edk::color3f32 color){
    //
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add scale
    edk::GU::guScale2f32(edk::size2f32(size,size));

    //lineSize
    edk::GU::guLineWidth(3);

    //set the colors
    edk::GU::guColor3f32(color);
    //draw the lines
    edk::GU::guBegin(GU_LINES);
    //LINE 1
    edk::GU::guVertex2f32(-0.5f,-0.5f);
    edk::GU::guVertex2f32( 0.5f, 0.5f);
    //LINE 2
    edk::GU::guVertex2f32(-0.5f, 0.5f);
    edk::GU::guVertex2f32( 0.5f,-0.5f);
    edk::GU::guEnd();

    //lineSize
    edk::GU::guLineWidth(1);

    //
    edk::GU::guPopMatrix();
}

//XML
bool edk::Object2D::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"object_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //WRITE
                        //write the mesh
                        edk::uint32 size = this->meshes.size();
                        edk::shape::Mesh2D* mesh;
                        for(edk::uint32 i=0u;i<size;i++){
                            mesh = this->meshes.getMesh(i);
                            if(mesh){
                                mesh->writeToXML(xml,i);
                            }
                        }

                        //write pivo
                        edk::char8* temp=NULL;
                        temp = edk::String::float32ToStr(this->pivo.x);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"pivoX",temp);
                            delete[] temp;
                        }
                        temp = edk::String::float32ToStr(this->pivo.y);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"pivoY",temp);
                            delete[] temp;
                        }

                        //write objectValues
                        //position
                        temp = edk::String::float32ToStr(this->position.x);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"positionX",temp);
                            delete[] temp;
                        }
                        temp = edk::String::float32ToStr(this->position.y);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"positionY",temp);
                            delete[] temp;
                        }
                        //size
                        temp = edk::String::float32ToStr(this->size.width);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"sizeW",temp);
                            delete[] temp;
                        }
                        temp = edk::String::float32ToStr(this->size.height);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"sizeH",temp);
                            delete[] temp;
                        }
                        //angle
                        temp = edk::String::float32ToStr(this->angle);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"angle",temp);
                            delete[] temp;
                        }

                        //write animations
                        this->animationPosition.writeToXML(xml,0u);
                        this->animationRotation.writeToXML(xml,1u);
                        this->animationSize.writeToXML(xml,2u);

                        //write the actins
                        this->actions.writeToXML(xml,0u);

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
bool edk::Object2D::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"object_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    this->cleanMeshes();
                    //read mesh
                    edk::shape::Mesh2D* mesh;
                    edk::uint32 count=0u;
                    edk::uint32 position=0u;
                    do{
                        mesh = this->newMesh(&position);
                        if(mesh){
                            if(!mesh->readFromXML(xml,count)){
                                this->removeMesh(position);
                                mesh=NULL;
                            }
                        }
                        count++;
                    }while(mesh);
                    //read pivo
                    this->pivo = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoX")),
                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoY"))
                                              );
                    //read the object values
                    //position
                    this->position = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionX")),
                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionY"))
                                                  );
                    //size
                    this->size = edk::size2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeW")),
                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeH"))
                                               );
                    //angle
                    this->angle = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("angle"));

                    //write animations
                    this->animationPosition.readFromXML(xml,0u);
                    this->animationRotation.readFromXML(xml,1u);
                    this->animationSize.readFromXML(xml,2u);

                    //ACTIONS
                    this->actions.readFromXML(xml,0u,this);

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

//cant delete
void edk::Object2D::cantDeleteObject2D(){
    this->canDeleteObject=false;
}
