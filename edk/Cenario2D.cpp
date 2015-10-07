#include "Cenario2D.h"

edk::Cenario2D::Cenario2D(){
    //
    this->world.addContactCallback(this);
    this->cleanSelectedTileMap();
    this->actions.setReadXMLActionFunction(&edk::Cenario2D::readXMLAction);
}
edk::Cenario2D::~Cenario2D(){
    //
    this->world.removeContactCallback(this);
    this->deleteAllLevels();
    this->tileSet.deleteTiles();
    this->actions.clean();
}

//Function to read the actions
edk::Action* edk::Cenario2D::readXMLAction(edk::classID thisPointer,edk::uint32 actionCode){
    switch(actionCode){
    case 1u:
    {
        //ActionPosition
        return new edk::Cenario2D::ActionObjectSetPosition((edk::Cenario2D*)thisPointer,0,0,edk::vec2f32(0,0));
    }
    case 2u:
    {
        //ActionMove
        return new edk::Cenario2D::ActionObjectMove((edk::Cenario2D*)thisPointer,0,0,0,edk::vec2f32(0,0));
    }
    case 3u:
    {
        //ActionSetSize
        return new edk::Cenario2D::ActionObjectSetSize((edk::Cenario2D*)thisPointer,0,0,edk::size2f32(0,0));
    }
    case 4u:
    {
        //ActionSize
        return new edk::Cenario2D::ActionObjectScale((edk::Cenario2D*)thisPointer,0,0,0,edk::size2f32(0,0));
    }
    case 5u:
    {
        //ActionSetAngle
        return new edk::Cenario2D::ActionObjectSetAngle((edk::Cenario2D*)thisPointer,0,0,0);
    }
    case 6u:
    {
        //ActionAngle
        return new edk::Cenario2D::ActionObjectRotate((edk::Cenario2D*)thisPointer,0,0,0,0);
    }
    case 7u:
    {
        //ActionMeshName
        return new edk::Cenario2D::ActionObjectMeshName((edk::Cenario2D*)thisPointer,0,0,0,NULL,false);
    }
    case 8u:
    {
        //ActionMeshStop
        return new edk::Cenario2D::ActionObjectMeshStop((edk::Cenario2D*)thisPointer,0,0,0);
    }
    }
    return new edk::ActionZero();
}

//XML
bool edk::Cenario2D::TreeObjDepth::writeToXML(edk::XML* xml,edk::uint32 id,bool isPhysics){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Objects_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //
                        edk::char8* temp;
                        edk::char8* nameTemp;
                        edk::char8* idTemp;
                        edk::uint32 size = this->size();
                        //write the size
                        temp = edk::String::int64ToStr(size);
                        if(temp){
                            //write the size
                            xml->setSelectedString(temp);
                            delete[] temp;
                        }
                        edk::Cenario2D::ObjClass* objClass;
                        if(isPhysics){
                            edk::physics2D::PhysicObject2D* physObj=NULL;
                            for(edk::uint32 i=0u;i<size;i++){
                                objClass = this->getElementInPosition(i);
                                if(objClass){
                                    idTemp = edk::String::int64ToStr(i);
                                    if(idTemp){
                                        nameTemp = edk::String::strCat((edk::char8*)"obj_",idTemp);
                                        if(nameTemp){
                                            if(xml->addSelectedNextChild(nameTemp)){
                                                if(xml->selectChild(nameTemp)){
                                                    //add attributes
                                                    temp = edk::String::float32ToStr(objClass->depth);
                                                    if(temp){
                                                        xml->setSelectedString(temp);
                                                        delete[] temp;
                                                    }
                                                    //write the object
                                                    if((physObj = (edk::physics2D::PhysicObject2D*)objClass->getObject())){
                                                        //
                                                        physObj->writeToXML(xml,i);
                                                    }
                                                    xml->selectFather();
                                                }
                                            }
                                            delete[] nameTemp;
                                        }
                                        delete []idTemp;
                                    }
                                }
                            }
                        }
                        else{
                            edk::Object2D* obj=NULL;
                            for(edk::uint32 i=0u;i<size;i++){
                                objClass = this->getElementInPosition(i);
                                if(objClass){
                                    idTemp = edk::String::int64ToStr(i);
                                    if(idTemp){
                                        nameTemp = edk::String::strCat((edk::char8*)"obj_",idTemp);
                                        if(nameTemp){
                                            if(xml->addSelectedNextChild(nameTemp)){
                                                if(xml->selectChild(nameTemp)){
                                                    //add attributes
                                                    temp = edk::String::float32ToStr(objClass->depth);
                                                    if(temp){
                                                        xml->setSelectedString(temp);
                                                        delete[] temp;
                                                    }
                                                    //write the object
                                                    if((obj=objClass->getObject())){
                                                        //
                                                        obj->writeToXML(xml,i);
                                                    }
                                                    xml->selectFather();
                                                }
                                            }
                                            delete[] nameTemp;
                                        }
                                        delete []idTemp;
                                    }
                                }
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
bool edk::Cenario2D::TreeObjDepth::readFromXML(edk::XML* xml,edk::uint32 id,bool isPhysics){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Objects_",nameID);
            if(name){
                //
                //create the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* temp;
                    //read the object size
                    edk::uint32 size = 0u;
                    temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                    if(temp){
                        size = edk::String::strToInt64(temp);
                        delete[] temp;
                    }
                    if(size){
                        edk::char8* nameTemp;
                        edk::char8* idTemp;
                        edk::float32 depth;
                        if(isPhysics){
                            //load the objects
                            edk::physics2D::PhysicObject2D* obj;
                            for(edk::uint32 i=0u;i<size;i++){
                                depth = 0.f;
                                idTemp = edk::String::int64ToStr(i);
                                if(idTemp){
                                    nameTemp = edk::String::strCat((edk::char8*)"obj_",idTemp);
                                    if(nameTemp){
                                        if(xml->selectChild(nameTemp)){
                                            //read the depth
                                            depth=0u;
                                            temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                                            if(temp){
                                                depth = edk::String::strToFloat32(temp);
                                                delete[] temp;
                                            }
                                            //create the object
                                            if(edk::physics2D::PhysicObject2D::readFromXMLisSensor(xml,i)){
                                                //
                                                obj = new edk::physics2D::StaticSensor2D;
                                            }
                                            else{
                                                obj = new edk::physics2D::PhysicObject2D;
                                            }
                                            if(obj){
                                                //read the object
                                                if(obj->readFromXML(xml,i)){
                                                    //add the object
                                                    if(!this->addObject(true,(edk::Object2D*)obj,depth)){
                                                        //else delete the object
                                                        delete obj;
                                                    }
                                                    obj->playMeshAnimations();
                                                    obj->animationPosition.playForward();
                                                    obj->animationRotation.playForward();
                                                    obj->animationSize.playForward();
                                                }
                                                else{
                                                    delete obj;
                                                }
                                            }

                                            xml->selectFather();
                                        }
                                    }
                                }
                            }
                        }
                        else{
                            //load the objects
                            edk::Object2D* obj;
                            for(edk::uint32 i=0u;i<size;i++){
                                depth = 0.f;
                                idTemp = edk::String::int64ToStr(i);
                                if(idTemp){
                                    nameTemp = edk::String::strCat((edk::char8*)"obj_",idTemp);
                                    if(nameTemp){
                                        if(xml->selectChild(nameTemp)){
                                            //read the depth
                                            depth=0u;
                                            temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                                            if(temp){
                                                depth = edk::String::strToFloat32(temp);
                                                delete[] temp;
                                            }
                                            //create the object
                                            obj = new edk::Object2D;
                                            if(obj){
                                                //read the object
                                                if(obj->readFromXML(xml,i)){
                                                    //add the object
                                                    if(!this->addObject(true,obj,depth)){
                                                        //else delete the object
                                                        delete obj;
                                                    }
                                                    obj->playMeshAnimations();
                                                    obj->animationPosition.playForward();
                                                    obj->animationRotation.playForward();
                                                    obj->animationSize.playForward();
                                                }
                                                else{
                                                    delete obj;
                                                }
                                            }
                                            xml->selectFather();
                                        }
                                    }
                                }
                            }
                        }
                    }
                    //
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

//XML
bool edk::Cenario2D::LevelObj::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Level_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //test witch type o level
                        if(this->objs){
                            //write the string
                            xml->setSelectedString("objs");
                            this->objs->writeToXML(xml,0u);
                        }
                        else if(this->objsPhys){
                            //write the string
                            xml->setSelectedString("objsPhys");
                            this->objsPhys->writeToXML(xml,0u,true);
                        }
                        else if(this->tileMap){
                            //write the string
                            xml->setSelectedString("tileMap");
                            //write tileMap
                            this->tileMap->writeToXML(xml,0u);
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
bool edk::Cenario2D::LevelObj::readFromXML(edk::XML* xml,edk::uint32 id,edk::tiles::TileSet2D* tileSet,edk::physics2D::World2D* world){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Level_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* temp;

                    //delete if have some
                    if(this->haveSome()){
                        //delete the some
                        if(this->objs){
                            //read the objects
                            delete this->objs;
                        }
                        else if(this->objsPhys){
                            //read the objects
                            delete this->objsPhys;
                        }
                        else if(this->tileMap){
                            //read the objects
                            delete this->tileMap;
                        }
                    }

                    //test the string
                    temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                    if(temp){
                        if(edk::String::strCompare(temp,"objs")){
                            //read the objects
                            this->objs = new edk::Cenario2D::TreeObjDepth;
                            if(this->objs){
                                if(!this->objs->readFromXML(xml,0u)){
                                    delete this->objs;
                                    this->clean();
                                }
                            }
                        }
                        else if(edk::String::strCompare(temp,"objsPhys")){
                            //read the physics objects
                            this->objsPhys = new edk::Cenario2D::TreePhysObjDepth(world);
                            if(this->objsPhys){
                                if(!this->objsPhys->readFromXML(xml,0u,true)){
                                    delete this->objsPhys;
                                    this->clean();
                                }
                            }
                        }
                        else if(edk::String::strCompare(temp,"tileMap")){
                            //read the tileMap

                            this->tileMap = new edk::tiles::TileMap2D(tileSet);
                            if(this->tileMap){
                                if(this->tileMap->readFromXML(xml,0u)){
                                    //Set the tileSet and tileMap
                                    this->tileMap->setWorld(world);
                                }
                                else{
                                    delete this->tileMap;
                                    this->clean();
                                }
                            }
                        }
                        delete[] temp;
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

//ACTIONS
edk::Cenario2D::ActionObjectZero::ActionObjectZero(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth){
    this->cenario = cenario;
    this->levelPosition = levelPosition;
    this->depth = depth;
}
//write to XML
bool edk::Cenario2D::ActionObjectZero::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write levelPosition
                    xml->addSelectedNextAttribute("levelPosition",this->levelPosition);
                    //write depth
                    xml->addSelectedNextAttribute("depth",this->depth);

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
bool edk::Cenario2D::ActionObjectZero::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read levelPosition
                    this->levelPosition = edk::String::strToInt64(xml->getSelectedAttributeValueByName("levelPosition"));
                    //read depth
                    this->depth = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("depth"));

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
edk::uint32 edk::Cenario2D::ActionObjectZero::getLevelPosition(){
    return this->levelPosition;
}
edk::float32 edk::Cenario2D::ActionObjectZero::getDepth(){
    return this->depth;
}
edk::Cenario2D::ActionObjectZeroDuration::ActionObjectZeroDuration(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth,edk::float32 duration)
    :ActionObjectZero(cenario,levelPosition,depth)
{
    this->duration=duration;
}
bool edk::Cenario2D::ActionObjectZeroDuration::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::Cenario2D::ActionObjectZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write duration
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
bool edk::Cenario2D::ActionObjectZeroDuration::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    edk::Cenario2D::ActionObjectZero::readFromXML(xml,id);
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
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

edk::float32 edk::Cenario2D::ActionObjectZeroDuration::getDuration(){
    return this->duration;
}
edk::Cenario2D::ActionObjectSetPosition::ActionObjectSetPosition(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth, edk::vec2f32 position)
    :ActionObjectZero(cenario,levelPosition,depth)
{
    this->position = position;
    this->code = 1u;
}
//run action function
void edk::Cenario2D::ActionObjectSetPosition::runAction(){
    //load the object from the cenario
    edk::Object2D* temp = this->cenario->getObject(this->levelPosition,this->depth);
    if(temp){
        temp->position = this->position;
    }
}
//write to XML
bool edk::Cenario2D::ActionObjectSetPosition::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::Cenario2D::ActionObjectZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write position
                    xml->addSelectedNextAttribute("positionX",this->position.x);
                    xml->addSelectedNextAttribute("positionY",this->position.y);

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
bool edk::Cenario2D::ActionObjectSetPosition::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    edk::Cenario2D::ActionObjectZero::readFromXML(xml,id);
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read position
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
edk::vec2f32 edk::Cenario2D::ActionObjectSetPosition::getPosition(){
    return this->position;
}
edk::Cenario2D::ActionObjectMove::ActionObjectMove(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth,edk::float32 duration, edk::vec2f32 position)
    :ActionObjectZeroDuration(cenario,levelPosition,depth,duration)
{
    this->position=position;
    this->code = 2u;
}
//run action function
void edk::Cenario2D::ActionObjectMove::runAction(){
    edk::Object2D* temp = this->cenario->getObject(this->levelPosition,this->depth);
    if(temp){
        temp->animationPosition.cleanAnimations();
        temp->animationPosition.addFirstInterpolationLine(0u,temp->position.x,temp->position.y,this->duration,this->position.x,this->position.y);
        temp->animationPosition.playForward();
        this->cenario->setObjectAnimated(this->levelPosition,this->depth);
    }
}
//write to XML
bool edk::Cenario2D::ActionObjectMove::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::Cenario2D::ActionObjectZeroDuration::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write position
                    xml->addSelectedNextAttribute("positionX",this->position.x);
                    xml->addSelectedNextAttribute("positionY",this->position.y);

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
bool edk::Cenario2D::ActionObjectMove::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    edk::Cenario2D::ActionObjectZeroDuration::readFromXML(xml,id);
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read position
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
edk::vec2f32 edk::Cenario2D::ActionObjectMove::getPosition(){
    return this->position;
}
edk::Cenario2D::ActionObjectSetSize::ActionObjectSetSize(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth, edk::size2f32 size)
    :ActionObjectZero(cenario,levelPosition,depth)
{
    this->size = size;
    this->code = 3u;
}
//run action function
void edk::Cenario2D::ActionObjectSetSize::runAction(){
    //load the object from the cenario
    edk::Object2D* temp = this->cenario->getObject(this->levelPosition,this->depth);
    if(temp){
        temp->size = this->size;
    }
}
//write to XML
bool edk::Cenario2D::ActionObjectSetSize::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::Cenario2D::ActionObjectZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write size
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
bool edk::Cenario2D::ActionObjectSetSize::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    edk::Cenario2D::ActionObjectZero::readFromXML(xml,id);
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read size
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
edk::size2f32 edk::Cenario2D::ActionObjectSetSize::getSize(){
    return this->size;
}
edk::Cenario2D::ActionObjectScale::ActionObjectScale(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth,edk::float32 duration, edk::size2f32 size)
    :ActionObjectZeroDuration(cenario,levelPosition,depth,duration)
{
    this->size = size;
    this->code = 4u;
}
//run action function
void edk::Cenario2D::ActionObjectScale::runAction(){
    edk::Object2D* temp = this->cenario->getObject(this->levelPosition,this->depth);
    if(temp){
        temp->animationSize.cleanAnimations();
        temp->animationSize.addFirstInterpolationLine(0u,temp->size.width,temp->size.height,this->duration,this->size.width,this->size.height);
        temp->animationSize.playForward();
        this->cenario->setObjectAnimated(this->levelPosition,this->depth);
    }
}
//write to XML
bool edk::Cenario2D::ActionObjectScale::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::Cenario2D::ActionObjectZeroDuration::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write size
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
bool edk::Cenario2D::ActionObjectScale::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    edk::Cenario2D::ActionObjectZeroDuration::readFromXML(xml,id);
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read size
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
edk::size2f32 edk::Cenario2D::ActionObjectScale::getSize(){
    return this->size;
}
edk::Cenario2D::ActionObjectSetAngle::ActionObjectSetAngle(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth, edk::float32 angle)
    :ActionObjectZero(cenario,levelPosition,depth)
{
    this->angle=angle;
    this->code = 5u;
}
//run action function
void edk::Cenario2D::ActionObjectSetAngle::runAction(){
    //load the object from the cenario
    edk::Object2D* temp = this->cenario->getObject(this->levelPosition,this->depth);
    if(temp){
        temp->angle = this->angle;
    }
}
//write to XML
bool edk::Cenario2D::ActionObjectSetAngle::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::Cenario2D::ActionObjectZero::writeToXML(xml,id)){
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
bool edk::Cenario2D::ActionObjectSetAngle::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    edk::Cenario2D::ActionObjectZero::readFromXML(xml,id);
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
edk::float32 edk::Cenario2D::ActionObjectSetAngle::getAngle(){
    return this->angle;
}
edk::Cenario2D::ActionObjectRotate::ActionObjectRotate(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth,edk::float32 duration, edk::float32 angle)
    :ActionObjectZeroDuration(cenario,levelPosition,depth,duration)
{
    this->angle=angle;
    this->code = 6u;
}
//run action function
void edk::Cenario2D::ActionObjectRotate::runAction(){
    edk::Object2D* temp = this->cenario->getObject(this->levelPosition,this->depth);
    if(temp){
        temp->animationRotation.cleanAnimations();
        temp->animationRotation.addFirstInterpolationLine(0u,temp->angle,this->duration,this->angle);
        temp->animationRotation.playForward();
        this->cenario->setObjectAnimated(this->levelPosition,this->depth);
    }
}
//write to XML
bool edk::Cenario2D::ActionObjectRotate::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::Cenario2D::ActionObjectZeroDuration::writeToXML(xml,id)){
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
bool edk::Cenario2D::ActionObjectRotate::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    edk::Cenario2D::ActionObjectZeroDuration::readFromXML(xml,id);
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
//return the code
edk::float32 edk::Cenario2D::ActionObjectRotate::getAngle(){
    return this->angle;
}
edk::Cenario2D::ActionObjectMeshName::ActionObjectMeshName(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id, edk::char8* name,bool loop){
    this->cenario = cenario;
    this->levelPosition = levelPosition;
    this->depth=depth;
    this->id = id;
    edk::Name::setName(name);
    this->loop=loop;
    this->code = 7u;
}
//run action function
void edk::Cenario2D::ActionObjectMeshName::runAction(){
    edk::Object2D* temp = this->cenario->getObject(this->levelPosition,this->depth);
    if(temp){
        //load the mesh
        edk::shape::Mesh2D* mesh = temp->getMesh(this->id);
        if(mesh){
            mesh->selectedAnimationSetLoop(this->loop);
            mesh->selectedAnimationPlayNameForward(this->name());
        }
    }
}
//write to XML
bool edk::Cenario2D::ActionObjectMeshName::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::ActionName::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
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
bool edk::Cenario2D::ActionObjectMeshName::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    //read the code
                    if(edk::String::strCompare("loopOn",xml->getSelectedString())){
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
edk::uint32 edk::Cenario2D::ActionObjectMeshName::getLevelPosition(){
    return this->levelPosition;
}
edk::float32 edk::Cenario2D::ActionObjectMeshName::getDepth(){
    return this->depth;
}
edk::uint32 edk::Cenario2D::ActionObjectMeshName::getId(){
    return this->id;
}
bool edk::Cenario2D::ActionObjectMeshName::getLoop(){
    return this->loop;
}
edk::Cenario2D::ActionObjectMeshStop::ActionObjectMeshStop(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id)
    :edk::Cenario2D::ActionObjectZero(cenario,levelPosition,depth)
{
    this->id = id;
    this->code = 8u;
}
//run action function
void edk::Cenario2D::ActionObjectMeshStop::runAction(){
    edk::Object2D* temp = this->cenario->getObject(this->levelPosition,this->depth);
    if(temp){
        //load the mesh
        edk::shape::Mesh2D* mesh = temp->getMesh(this->id);
        if(mesh){
            mesh->selectedAnimationStop();
        }
    }
}
//write to XML
bool edk::Cenario2D::ActionObjectMeshStop::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::Cenario2D::ActionObjectZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
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
bool edk::Cenario2D::ActionObjectMeshStop::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    edk::Cenario2D::ActionObjectZero::readFromXML(xml,id);
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read ID
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

//get levels less position
edk::uint32 edk::Cenario2D::getLevelsLessPosition(){
    //test all the objects
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* temp = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->levels[i];
        if(temp){
            //test if dont have the object
            if(!temp->haveSome()){
                //return i
                return i++;
            }
        }
    }
    //else return the size
    return size+1u;
}
//Add a object to the level
bool edk::Cenario2D::addObjectToLevel(edk::Object2D* obj,edk::Object2D* objPhys,edk::uint32 levelPosition,edk::float64 depth,bool created){
    if(levelPosition){
        levelPosition--;
        //test the object
        if(obj || objPhys){
            //test if dont have the level
            if(!this->levels.havePos(levelPosition)){
                //create the levels
                edk::uint32 newSize = levelPosition - this->levels.size() + 1u;
                //create the levelObjects
                edk::Cenario2D::LevelObj* temp = NULL;
                for(edk::uint32 i=0u;i<newSize;i++){
                    temp = new edk::Cenario2D::LevelObj();
                    if(temp){
                        this->levels.pushBack(temp);
                    }
                    else{
                        return false;
                    }
                }
            }
            //test if have the level position
            if(this->levels.havePos(levelPosition)){

                if(obj){
                    //load the level
                    edk::Cenario2D::LevelObj* temp = this->levels[levelPosition];
                    if(temp){
                        bool canCreate=false;
                        if(temp->haveSome()){
                            if(temp->objs){
                                canCreate=true;
                            }
                        }
                        else{
                            //else create a new objs tree
                            temp->objs = new edk::Cenario2D::TreeObjDepth;
                            if(temp->objs){
                                canCreate=true;
                            }
                        }
                        if(canCreate){
                            //add the object
                            if(temp->objs->addObject(created,obj,depth)){
                                //return true
                                return true;
                            }
                            else{
                                //else delete the tree if it's clear
                                if(!temp->objs->size()){
                                    delete temp->objs;
                                    temp->clean();
                                }
                            }
                        }
                    }
                }

                else if(objPhys){
                    //load the level
                    edk::Cenario2D::LevelObj* temp = this->levels[levelPosition];
                    if(temp){
                        bool canCreate=false;
                        if(temp->haveSome()){
                            if(temp->objsPhys){
                                canCreate=true;
                            }
                        }
                        else{
                            //else create a new objs tree
                            temp->objsPhys = new edk::Cenario2D::TreePhysObjDepth(&this->world);
                            if(temp->objsPhys){
                                canCreate=true;
                            }
                        }
                        if(canCreate){
                            //add the object
                            if(temp->objsPhys->addObject(created,objPhys,depth)){
                                //return true
                                return true;
                            }
                            else{
                                //else delete the tree if it's clear
                                if(!temp->objsPhys->size()){
                                    delete temp->objsPhys;
                                    temp->clean();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
//return the higher level in Objects
edk::float64 edk::Cenario2D::getHigherLevel(edk::uint32 levelPosition){
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            //load the level
            edk::Cenario2D::LevelObj* temp = this->levels[levelPosition];
            if(temp){
                if(temp->haveSome()){
                    if(temp->objs){
                        return temp->objs->getLastLevel();
                    }
                    if(temp->objsPhys){
                        return temp->objsPhys->getLastLevel();
                    }
                }
            }
        }
    }
    return -1.0;
}
//get objectString for Joint
bool edk::Cenario2D::getPhysicsObjectLevelDepth(edk::Object2D* obj,edk::uint32* level,edk::float32* depth){
    //
    if(obj){
        //find object in levels
        edk::uint32 levelSize = this->levels.size();
        edk::Cenario2D::LevelObj* levelObj;
        edk::Cenario2D::ObjClass* physObj;
        for(edk::uint32 i=0u;i<levelSize;i++){
            *level=i;
            levelObj = this->levels[i];
            if(levelObj){
                if(levelObj->objsPhys){
                    //find the object
                    edk::uint32 objSize = levelObj->objsPhys->size();
                    for(edk::uint32 j=0u;j<objSize;j++){
                        //test the object
                        physObj = levelObj->objsPhys->getElementInPosition(j);
                        if(physObj){
                            if(obj == physObj->getObject()){
                                *depth = physObj->depth;
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
//XML
bool edk::Cenario2D::PhysicsPosition::writeToXML(edk::XML* xml,bool id){
    if(xml){
        bool ret=false;
        edk::char8* name = NULL;
        if(id)
            name = (edk::char8*)"objectA";
        else
            name = (edk::char8*)"objectB";
        //create the name
        if(xml->addSelectedNextChild(name)){
            if(xml->selectChild(name)){
                ret=true;
                edk::char8* temp = NULL;

                //write the level type
                switch(this->levelID){
                case EDK_LEVEL_OBJ_PHYSICS:
                    //write the string
                    xml->setSelectedString("OBJ_PHYSICS");
                    //write the level
                    temp = edk::String::uint32ToStr(this->level);
                    if(temp){
                        xml->addSelectedNextAttribute((edk::char8*)"level",temp);
                        delete[] temp;
                    }
                    temp = edk::String::float32ToStr(this->depth);
                    if(temp){
                        xml->addSelectedNextAttribute((edk::char8*)"depth",temp);
                        delete[] temp;
                    }
                    break;
                case EDK_LEVEL_TILE_MAP:
                    xml->setSelectedString("TILE_MAP");
                    //write the level
                    temp = edk::String::uint32ToStr(this->level);
                    if(temp){
                        xml->addSelectedNextAttribute((edk::char8*)"level",temp);
                        delete[] temp;
                    }
                    temp = edk::String::uint32ToStr(this->mapPosition.x);
                    if(temp){
                        xml->addSelectedNextAttribute((edk::char8*)"mapX",temp);
                        delete[] temp;
                    }
                    temp = edk::String::uint32ToStr(this->mapPosition.y);
                    if(temp){
                        xml->addSelectedNextAttribute((edk::char8*)"mapY",temp);
                        delete[] temp;
                    }
                    //
                    break;
                case EDK_LEVEL_NOTHING:
                default:
                    ret=false;
                }
                xml->selectFather();
            }
        }
        return ret;
    }
    return false;
}
bool edk::Cenario2D::PhysicsPosition::readFromXML(edk::XML* xml,bool id){
    if(xml){
        bool ret=false;
        edk::char8* name = NULL;
        if(id)
            name = (edk::char8*)"objectA";
        else
            name = (edk::char8*)"objectB";
        //create the name
        if(xml->selectChild(name)){
            edk::char8 filter[3u] = {9u,'\n',0u};
            edk::char8* temp;
            ret=true;
            //Test the levetID
            temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
            if(temp){
                if(edk::String::strCompare((edk::char8*)"OBJ_PHYSICS",temp)){
                    //
                    this->levelID = EDK_LEVEL_OBJ_PHYSICS;
                    //read the level
                    this->level = edk::String::strToInt64(xml->getSelectedAttributeValueByName("level"));
                    //read depth
                    this->depth = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("depth"));
                }
                else if(edk::String::strCompare((edk::char8*)"TILE_MAP",temp)){
                    //
                    this->levelID = EDK_LEVEL_TILE_MAP;
                    //read the level
                    this->level = edk::String::strToInt64(xml->getSelectedAttributeValueByName("level"));
                    //read the tileMap position
                    this->mapPosition = edk::vec2ui32((edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("mapX")),
                                                      (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("mapY"))
                                                      );
                }
                else{
                    this->levelID = EDK_LEVEL_NOTHING;
                    ret=false;
                }
                delete[] temp;
            }
            xml->selectFather();
        }
        return ret;
    }
    return false;
}
bool edk::Cenario2D::getPhysicsLevelObject(edk::Object2D* obj,edk::Cenario2D::PhysicsPosition* objLevel){
    if(obj && objLevel){
        //find the object in levels
        edk::uint32 levelSize = this->levels.size();
        edk::Cenario2D::LevelObj* levelObj;
        edk::Cenario2D::ObjClass* physObj;
        edk::physics2D::PhysicObject2D* physicObject = (edk::physics2D::PhysicObject2D*)obj;
        for(edk::uint32 i=0u;i<levelSize;i++){
            objLevel->level = i;
            levelObj = this->levels[i];
            if(levelObj){
                if(levelObj->objsPhys){
                    //find the object
                    edk::uint32 objSize = levelObj->objsPhys->size();
                    for(edk::uint32 j=0u;j<objSize;j++){
                        //test the object
                        physObj = levelObj->objsPhys->getElementInPosition(j);
                        if(physObj){
                            if(obj == physObj->getObject()){
                                objLevel->depth = physObj->depth;
                                objLevel->levelID = EDK_LEVEL_OBJ_PHYSICS;
                                return true;
                            }
                        }
                    }
                }
                //test if it's a tileMap
                else if(levelObj->tileMap){
                    //test if have the object
                    if(levelObj->tileMap->havePhysicObject(physicObject)){
                        //return the position
                        objLevel->mapPosition = levelObj->tileMap->getPhysicObjectPosition(physicObject);
                        objLevel->levelID = EDK_LEVEL_TILE_MAP;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
edk::physics2D::PhysicObject2D* edk::Cenario2D::getPhysicsObjectInLevel(edk::Cenario2D::PhysicsPosition objLevel){
    //load the level
    if(objLevel.level < this->levels.size()){
        edk::Cenario2D::LevelObj* level = this->levels[objLevel.level];
        if(level){
            //test the ID
            switch(objLevel.levelID){
            case EDK_LEVEL_OBJ_PHYSICS:
                //test the level
                if(level->objsPhys){
                    //get the object
                    return (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectFromDepth(objLevel.depth);
                }
                break;
            case EDK_LEVEL_TILE_MAP:
                //test the level
                if(level->tileMap){
                    //get the object
                    return level->tileMap->getPhysicTile(objLevel.mapPosition);
                }
                break;
            }
        }
    }
    return NULL;
}

//CALLBACKS
void edk::Cenario2D::contact2DBegin(edk::physics2D::Contact2D*){
    //
}
void edk::Cenario2D::contact2DEnd(edk::physics2D::Contact2D*){
    //
}
void edk::Cenario2D::contact2DKeepBegin(edk::physics2D::Contact2D*){
    //
}
void edk::Cenario2D::contact2DKeepEnd(edk::physics2D::Contact2D*){
    //
}
//contact sensors
void edk::Cenario2D::sensor2DBegin(edk::physics2D::Contact2D*){
    //
}
void edk::Cenario2D::sensor2DEnd(edk::physics2D::Contact2D*){
    //
}
void edk::Cenario2D::sensor2DKeeping(edk::physics2D::Contact2D*){
    //
}
//CALLBACKS TILE
void edk::Cenario2D::contact2DTileBegin(edk::tiles::tileContact2D,edk::physics2D::Contact2D*){
    //
}
void edk::Cenario2D::contact2DTileEnd(edk::tiles::tileContact2D,edk::physics2D::Contact2D*){
    //
}
void edk::Cenario2D::contact2DTileKeepBegin(edk::tiles::tileContact2D,edk::physics2D::Contact2D*){
    //
}
void edk::Cenario2D::contact2DTileKeepEnd(edk::tiles::tileContact2D,edk::physics2D::Contact2D*){
    //
}
//contact sensors
void edk::Cenario2D::sensor2DTileBegin(edk::tiles::tileContact2D,edk::physics2D::Contact2D*){
    //
}
void edk::Cenario2D::sensor2DTileEnd(edk::tiles::tileContact2D,edk::physics2D::Contact2D*){
    //
}
void edk::Cenario2D::sensor2DTileKeeping(edk::tiles::tileContact2D,edk::physics2D::Contact2D*){
    //
}

//TILEMAP
edk::tiles::TileMap2D* edk::Cenario2D::newTileMapInPosition(edk::uint32 position,edk::size2ui32 size){
    if(position){
        position--;
        //test if dont have the position
        if(!this->levels.havePos(position)){
            edk::uint32 newSize = position - this->levels.size() + 1u;
            //create the levelObjects
            edk::Cenario2D::LevelObj* temp = NULL;
            for(edk::uint32 i=0u;i<newSize;i++){
                temp = new edk::Cenario2D::LevelObj();
                if(temp){
                    this->levels.pushBack(temp);
                }
                else{
                    return NULL;
                }
            }
        }

        //Now test if have the position
        if(this->levels.havePos(position)){
            edk::Cenario2D::LevelObj* temp = this->levels[position];
            if(temp){
                bool canCreate=false;
                if(temp->haveSome()){
                    if(temp->tileMap){
                        //delete tileMap
                        delete temp->tileMap;
                        temp->clean();
                        canCreate=true;
                    }
                }
                else{
                    canCreate=true;
                }
                if(canCreate){
                    temp->tileMap = new edk::tiles::TileMap2D(&this->tileSet);
                    if(temp->tileMap){
                        if(temp->tileMap->newTileMap(size)){
                            //Set the tileSet and tileMap
                            temp->tileMap->setTileSet(&this->tileSet);
                            temp->tileMap->setWorld(&this->world);
                            return temp->tileMap;
                        }
                        delete temp->tileMap;
                        temp->clean();
                    }
                }
            }
        }
    }
    return NULL;
}
edk::tiles::TileMap2D* edk::Cenario2D::newTileMapInPosition(edk::uint32 position,edk::uint32 width,edk::uint32 height){
    //
    return newTileMapInPosition(position,edk::size2ui32(width,height));
}
edk::uint32 edk::Cenario2D::newTileMap(edk::size2ui32 size){
    edk::uint32 position = this->getLevelsLessPosition();
    if(this->newTileMapInPosition(position,size)){
        //return the position
        return position;
    }
    return 0u;
}
edk::uint32 edk::Cenario2D::newTileMap(edk::uint32 width,edk::uint32 height){
    return this->newTileMap(edk::size2ui32(width,height));
}
edk::uint32 edk::Cenario2D::getTileMapID(edk::tiles::TileMap2D* tileMap){
    if(tileMap){
        edk::uint32 size = this->levels.size();
        edk::Cenario2D::LevelObj* temp = NULL;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->levels[i];
            if(temp){
                if(temp->tileMap == tileMap){
                    return i++;
                }
            }
        }
    }
    return 0u;
}
edk::tiles::TileMap2D* edk::Cenario2D::getTileMap(edk::uint32 position){
    //test the position
    if(position){
        position--;
        //test if the position is inside the stack
        if(this->levels.havePos(position)){
            edk::Cenario2D::LevelObj* temp = this->levels[position];
            if(temp){
                if(temp->tileMap){
                    return temp->tileMap;
                }
            }
        }
    }
    return NULL;
}
bool edk::Cenario2D::deleteTileMap(edk::tiles::TileMap2D* tileMap){
    return this->deleteTileMap(this->getTileMapID(tileMap));
}
bool edk::Cenario2D::deleteTileMap(edk::uint32 position){
    //test the position
    if(position){
        position--;
        //test if the position is inside the stack
        if(this->levels.havePos(position)){
            edk::Cenario2D::LevelObj* temp = this->levels[position];
            if(temp){
                if(temp->tileMap){
                    delete temp->tileMap;
                    temp->clean();
                    return true;
                }
            }
        }
    }
    return false;
}
void edk::Cenario2D::deleteAllTileMaps(){
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* temp = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->levels[i];
        if(temp){
            if(temp->tileMap){
                delete temp->tileMap;
                temp->clean();
            }
        }
    }
}

//tileMapFunctions
void edk::Cenario2D::cleanSelectedTileMap(){
    this->mapSelected=NULL;
}
//select the map
bool edk::Cenario2D::selectTileMap(edk::uint32 position){
    this->mapSelected = this->getTileMap(position);
    if(this->mapSelected) return true;
    return false;
}
//set a tile in the tileMap
bool edk::Cenario2D::selectedTileMapSetTile(edk::uint32 tileID,edk::vec2ui32 position){
    if(this->mapSelected){
        //
        return this->mapSelected->setTile(tileID,position);
    }
    return false;
}
bool edk::Cenario2D::selectedTileMapSetTile(edk::uint32 tileID,edk::uint32 positionX,edk::uint32 positionY){
    if(this->mapSelected){
        //
        return this->mapSelected->setTile(tileID,positionX,positionY);
    }
    return false;
}
//set the tileMap position
bool  edk::Cenario2D::selectedTileMapSetPosition(edk::vec2f32 position){
    if(this->mapSelected){
        //
        this->mapSelected->setPosition(position);
        return true;
    }
    return false;
}
bool  edk::Cenario2D::selectedTileMapSetPosition(edk::float32 positionX,edk::float32 positionY){
    if(this->mapSelected){
        //
        this->mapSelected->setPosition(positionX,positionY);
        return true;
    }
    return false;
}
edk::vec2f32 edk::Cenario2D::selectedTileMapGetTileWorldPosition(edk::vec2f32 position){
    if(this->mapSelected){
        //
        return this->mapSelected->getTileWorldPosition(position);
    }
    return edk::vec2f32();
}
edk::vec2f32 edk::Cenario2D::selectedTileMapGetTileWorldPosition(edk::uint32 positionX,edk::uint32 positionY){
    if(this->mapSelected){
        //
        return this->mapSelected->getTileWorldPosition(positionX,positionY);
    }
    return edk::vec2f32();
}
//Set scale the map
bool edk::Cenario2D::selectedTileMapSetScaleMap(edk::size2f32 scale){
    if(this->mapSelected){
        //
        return this->mapSelected->setScaleMap(scale);
    }
    return false;
}
bool edk::Cenario2D::selectedTileMapSetScaleMap(edk::float32 width,edk::float32 height ){
    if(this->mapSelected){
        //
        return this->mapSelected->setScaleMap(width,height);
    }
    return false;
}
//delete physicObjects
bool  edk::Cenario2D::selectedTileDeletePhysicsTiles(){
    if(this->mapSelected){
        //
        this->mapSelected->deletePhysicsTiles();
        return true;
    }
    return false;
}
bool edk::Cenario2D::selectedTileDeletePhysicTile(edk::vec2ui32 position){
    if(this->mapSelected){
        //
        return this->mapSelected->deletePhysicTile(position);
    }
    return false;
}
bool edk::Cenario2D::selectedTileDeletePhysicTile(edk::uint32 positionX,edk::uint32 positionY){
    if(this->mapSelected){
        //
        return this->mapSelected->deletePhysicTile(positionX,positionY);
    }
    return false;
}
//add physics tiles
bool edk::Cenario2D::selectedTileLoadPhysicsTiles(){
    if(this->mapSelected){
        //
        return this->mapSelected->loadPhysicsTiles();
    }
    return false;
}
bool edk::Cenario2D::selectedTileLoadPhysicTile(edk::vec2ui32 position){
    if(this->mapSelected){
        //
        this->mapSelected->loadPhysicTile(position);
        return true;
    }
    return false;
}
bool edk::Cenario2D::selectedTileLoadPhysicTile(edk::uint32 positionX,edk::uint32 positionY){
    if(this->mapSelected){
        //
        this->mapSelected->loadPhysicTile(positionX,positionY);
        return true;
    }
    return false;
}

//OBJECTS
//add a object to the tree
edk::Object2D* edk::Cenario2D::newObject(edk::uint32 levelPosition){
    return this->newObject(levelPosition,this->getHigherLevel(levelPosition) + 1.0);
}
edk::Object2D* edk::Cenario2D::newObject(edk::uint32 levelPosition,edk::float32 depth){
    if(levelPosition){
        edk::Object2D* obj = new edk::Object2D;
        if(obj){
            if(this->addObjectToLevel(obj,NULL,levelPosition,depth,true)){
                return obj;
            }
            delete obj;
        }
    }
    return NULL;
}
bool edk::Cenario2D::addObject(edk::uint32 levelPosition,edk::Object2D* obj){
    //test the object
    return this->addObject(levelPosition,obj,this->getHigherLevel(levelPosition)+1.0);
}
bool edk::Cenario2D::addObject(edk::uint32 levelPosition,edk::Object2D* obj,edk::float32 depth){
    //test the object
    if(levelPosition){
        if(obj){
            return this->addObjectToLevel(obj,NULL,levelPosition,depth,false);
        }
    }
    return false;
}
bool edk::Cenario2D::addObjectCreated(edk::uint32 levelPosition,edk::Object2D* obj){
    //test the object
    return this->addObjectCreated(levelPosition,obj,this->getHigherLevel(levelPosition)+1.0);
}
bool edk::Cenario2D::addObjectCreated(edk::uint32 levelPosition,edk::Object2D* obj,edk::float32 depth){
    //test the object
    if(levelPosition){
        if(obj){
            return this->addObjectToLevel(obj,NULL,levelPosition,depth,true);
        }
    }
    return false;
}
//get the object
edk::Object2D* edk::Cenario2D::getObject(edk::uint32 levelPosition,edk::float32 depth){
    //test if have the position
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];
            if(level){
                if(level->objs){
                    return level->objs->getObjectFromDepth(depth);
                }
            }
        }
    }
    return NULL;
}
edk::Object2D* edk::Cenario2D::getObject(edk::uint32 levelPosition,edk::uint32 position){
    //test if have the position
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];
            if(level){
                if(level->objs){
                    return level->objs->getObjectInPosition(position);
                }
            }
        }
    }
    return NULL;
}
//get the objectDepth
edk::float32 edk::Cenario2D::getObjectDepth(edk::uint32 levelPosition,edk::uint32 position){
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level = this->levels[levelPosition];
            if(level){
                if(level->objs){
                    return level->objs->getObjectDepthInPosition(position);
                }
            }
        }
    }
    return 0.f;
}
edk::float32 edk::Cenario2D::getObjectDepth(edk::uint32 levelPosition,edk::Object2D* obj){
    if(obj){
        //load the level
        if(levelPosition){
            levelPosition--;
            if(this->levels.havePos(levelPosition)){
                edk::Cenario2D::LevelObj* level =this->levels[levelPosition];
                if(level){
                    if(level->objs){
                        return level->objs->getObjectDepth(obj);
                    }
                }
            }
        }
    }
    return 0.f;
}

//delete the object
bool edk::Cenario2D::deleteObject(edk::uint32 levelPosition,edk::Object2D* obj){
    if(obj){
        //load the level
        if(levelPosition){
            levelPosition--;
            if(this->levels.havePos(levelPosition)){
                edk::Cenario2D::LevelObj* level =this->levels[levelPosition];
                if(level){
                    //remove object from tree
                    this->treeAnim.remove(obj);
                    if(level->objs){
                        bool ret = level->objs->deleteObj(obj);
                        if(!level->objs->size()){
                            delete level->objs;
                            level->clean();
                        }
                        return ret;
                    }
                }
            }
        }
    }
    return false;
}
void edk::Cenario2D::deleteAllObjects(edk::uint32 levelPosition){
    //load the level
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];
            if(level){
                if(level->objs){
                    edk::uint32 size = level->objs->size();
                    for(edk::uint32 i=0u;i<size;i++){
                        this->treeAnim.remove(level->objs->getObjectInPosition(0u));
                        level->objs->deleteObjInPosition(0u);
                    }
                }
            }
        }
    }
}
void edk::Cenario2D::deleteAllObjects(){
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* level = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        level = this->levels[i];
        if(level){
            if(level->objs){
                this->deleteAllObjects(i+1u);
                level->clean();
            }
        }
    }
}
//dont delete the object
bool edk::Cenario2D::removeObject(edk::uint32 levelPosition,edk::Object2D* obj){
    if(obj){
        //load the level
        if(levelPosition){
            levelPosition--;
            if(this->levels.havePos(levelPosition)){
                edk::Cenario2D::LevelObj* level =this->levels[levelPosition];
                if(level){
                    //remove object from tree
                    this->treeAnim.remove(obj);
                    if(level->objs){
                        bool ret = level->objs->removeObj(obj);
                        if(!level->objs->size()){
                            delete level->objs;
                            level->clean();
                        }
                        return ret;
                    }
                }
            }
        }
    }
    return false;
}
//set object to be animated
bool edk::Cenario2D::setObjectAnimated(edk::uint32 levelPosition,edk::Object2D* obj){
    //test the level position
    if(levelPosition){
        levelPosition--;
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels[levelPosition];
        if(level){
            //test if have objects
            if(level->objs){
                //load the object
                edk::Object2D* temp = level->objs->getObject(obj);
                if(temp){
                    //add the object to the animation tree
                    if(this->treeAnim.haveElement(temp)){
                        return true;
                    }
                    else{
                        return this->treeAnim.add(temp);
                    }
                }
            }
        }
    }
    return false;
}
bool edk::Cenario2D::setObjectAnimated(edk::uint32 levelPosition,edk::uint32 position){
    //test the level position
    if(levelPosition){
        levelPosition--;
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels[levelPosition];
        if(level){
            //test if have objects
            if(level->objs){
                //load the object
                edk::Object2D* temp = level->objs->getObjectInPosition(position);
                if(temp){
                    //add the object to the animation tree
                    if(this->treeAnim.haveElement(temp)){
                        return true;
                    }
                    else{
                        return this->treeAnim.add(temp);
                    }
                }
            }
        }
    }
    return false;
}
bool edk::Cenario2D::setObjectAnimated(edk::uint32 levelPosition,edk::float32 depth){
    //test the level position
    if(levelPosition){
        levelPosition--;
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels[levelPosition];
        if(level){
            //test if have objects
            if(level->objs){
                //load the object
                edk::Object2D* temp = level->objs->getObjectFromDepth(depth);
                if(temp){
                    //add the object to the animation tree
                    if(this->treeAnim.haveElement(temp)){
                        return true;
                    }
                    else{
                        return this->treeAnim.add(temp);
                    }
                }
            }
        }
    }
    return false;
}

//OBJECTS_PHYSICS
//add a object to the tree
edk::physics2D::PhysicObject2D* edk::Cenario2D::newPhysicObject(edk::uint32 levelPosition,edk::physics::bodyType physicType){
    return this->newPhysicObject(levelPosition,physicType,this->getHigherLevel(levelPosition) + 1.0);
}
edk::physics2D::PhysicObject2D* edk::Cenario2D::newPhysicObject(edk::uint32 levelPosition,edk::physics::bodyType physicType,edk::float32 depth){
    if(levelPosition){
        edk::physics2D::PhysicObject2D* obj = NULL;
        switch(physicType){
        case edk::physics::StaticBody:
            obj = new edk::physics2D::StaticObject2D;
            break;
        case edk::physics::KinematicBody:
            obj = new edk::physics2D::KinematicObject2D;
            break;
        case edk::physics::DynamicBody:
            obj = new edk::physics2D::DynamicObject2D;
            break;
        }
        if(obj){
            if(this->addObjectToLevel(NULL,(edk::Object2D*)obj,levelPosition,depth,true)){
                return obj;
            }
            delete obj;
        }
    }
    return NULL;
}
edk::physics2D::PhysicObject2D* edk::Cenario2D::newPhysicSensor(edk::uint32 levelPosition,edk::physics::bodyType physicType){
    return this->newPhysicSensor(levelPosition,physicType,this->getHigherLevel(levelPosition) + 1.0);
}
edk::physics2D::PhysicObject2D* edk::Cenario2D::newPhysicSensor(edk::uint32 levelPosition,edk::physics::bodyType physicType,edk::float32 depth){
    if(levelPosition){
        edk::physics2D::PhysicObject2D* obj = NULL;
        switch(physicType){
        case edk::physics::StaticBody:
            obj = new edk::physics2D::StaticSensor2D;
            break;
        case edk::physics::DynamicBody:
        case edk::physics::KinematicBody:
            obj = new edk::physics2D::KinematicSensor2D;
            break;
        }
        if(obj){
            if(this->addObjectToLevel(NULL,(edk::Object2D*)obj,levelPosition,depth,true)){
                return obj;
            }
            delete obj;
        }
    }
    return NULL;
}
bool edk::Cenario2D::addPhysicObject(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj){
    return this->addPhysicObject(levelPosition,obj,this->getHigherLevel(levelPosition) + 1.0);
}
bool edk::Cenario2D::addPhysicObject(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj,edk::float32 depth){
    if(obj){
        return this->addObjectToLevel(NULL,(edk::Object2D*)obj,levelPosition,depth,false);
    }
    return false;
}
bool edk::Cenario2D::addPhysicObjectCreated(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj){
    return this->addPhysicObjectCreated(levelPosition,obj,this->getHigherLevel(levelPosition) + 1.0);
}
bool edk::Cenario2D::addPhysicObjectCreated(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj,edk::float32 depth){
    if(obj){
        return this->addObjectToLevel(NULL,(edk::Object2D*)obj,levelPosition,depth,true);
    }
    return false;
}
bool edk::Cenario2D::addPhysicSensor(edk::uint32 levelPosition,edk::physics2D::StaticSensor2D* sensor){
    return this->addPhysicObject(levelPosition,sensor);
}
bool edk::Cenario2D::addPhysicSensor(edk::uint32 levelPosition,edk::physics2D::StaticSensor2D* sensor,edk::float32 depth){
    return this->addPhysicObject(levelPosition,sensor,depth);
}
bool edk::Cenario2D::addPhysicSensorCreated(edk::uint32 levelPosition,edk::physics2D::StaticSensor2D* sensor){
    return this->addPhysicObjectCreated(levelPosition,sensor);
}
bool edk::Cenario2D::addPhysicSensorCreated(edk::uint32 levelPosition,edk::physics2D::StaticSensor2D* sensor,edk::float32 depth){
    return this->addPhysicObjectCreated(levelPosition,sensor,depth);
}
//get the object
edk::physics2D::PhysicObject2D* edk::Cenario2D::getPhysicObject(edk::uint32 levelPosition,edk::float32 depth){
    if(levelPosition){
        levelPosition--;
        //test if have the position
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];
            if(level){
                if(level->objsPhys){
                    return (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectFromDepth(depth);
                }
            }
        }
    }
    return NULL;
}
edk::physics2D::PhysicObject2D* edk::Cenario2D::getPhysicObject(edk::uint32 levelPosition,edk::uint32 position){
    if(levelPosition){
        levelPosition--;
        //test if have the position
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];
            if(level){
                if(level->objsPhys){
                    return (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(position);
                }
            }
        }
    }
    return NULL;
}
//return the depth of the physic object
edk::float32 edk::Cenario2D::getPhysicObjectDepth(edk::uint32 levelPosition,edk::uint32 position){
    if(levelPosition){
        levelPosition--;
        //test if have the position
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];
            if(level){
                if(level->objsPhys){
                    return level->objsPhys->getObjectDepthInPosition(position);
                }
            }
        }
    }
    return 0.f;
}
edk::float32 edk::Cenario2D::getPhysicObjectDepth(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj){
    if(levelPosition){
        levelPosition--;
        //test if have the position
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];
            if(level){
                if(level->objsPhys){
                    return level->objsPhys->getObjectDepth(obj);
                }
            }
        }
    }
    return 0.f;
}

//load the physicsObjects
bool edk::Cenario2D::loadPhysicObjectToWorld(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj){
    if(levelPosition){
        levelPosition--;
        //test if have the level
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level = this->levels[levelPosition];
            if(level){
                if(level->objsPhys){
                    if(level->objsPhys->haveObject((edk::Object2D*)obj)){
                        //add the object to the world
                        return this->world.addObject(obj);
                    }
                }
            }
        }
    }
    return false;
}
bool edk::Cenario2D::loadPhysicObjectsToWorld(edk::uint32 levelPosition){
    if(levelPosition){
        levelPosition--;
        //test if have the level
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level = this->levels[levelPosition];
            if(level){
                if(level->objsPhys){
                    edk::uint32 size = level->objsPhys->size();
                    edk::physics2D::PhysicObject2D* temp = NULL;
                    for(edk::uint32 i=0u;i<size;i++){
                        temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(i);
                        this->world.removeObject(temp);
                        this->world.addObject(temp);
                    }
                    return true;
                }
                else if(level->tileMap){
                    return level->tileMap->loadPhysicsTiles();
                }
            }
        }
    }
    return false;
}
void edk::Cenario2D::loadPhysicObjectsToWorld(){
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* level=NULL;
    for(edk::uint32 i=0u;i<size;i++){
        level = this->levels[i];
        if(level){
            if(level->objsPhys){
                edk::uint32 size = level->objsPhys->size();
                edk::physics2D::PhysicObject2D* temp = NULL;
                for(edk::uint32 j=0u;j<size;j++){
                    temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(j);
                    this->world.removeObject(temp);
                    this->world.addObject(temp);
                }
            }
            else if(level->tileMap){
                level->tileMap->loadPhysicsTiles();
            }
        }
    }
}

//delete the object
bool edk::Cenario2D::deletePhysicObject(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj){
    if(levelPosition){
        levelPosition--;
        //load the level
        if(obj){
            if(this->levels.havePos(levelPosition)){
                edk::Cenario2D::LevelObj* level =this->levels[levelPosition];
                if(level){
                    if(level->objsPhys){
                        //remove from world
                        this->world.removeObject(obj);
                        bool ret = level->objsPhys->deleteObj((edk::Object2D*)obj);
                        if(!level->objsPhys->size()){
                            //remove from world
                            delete level->objsPhys;
                            level->clean();
                        }
                        return ret;
                    }
                }
            }
        }
    }
    return false;
}
void edk::Cenario2D::deleteAllPhysicObjects(edk::uint32 levelPosition){
    if(levelPosition){
        levelPosition--;
        //load the level
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];
            if(level){
                if(level->objsPhys){
                    edk::uint32 size = level->objsPhys->size();
                    for(edk::uint32 i=0u;i<size;i++){
                        //remove from worlf
                        this->world.removeObject((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(0u));
                        level->objsPhys->deleteObjInPosition(0u);
                    }
                }
            }
        }
    }
}
void edk::Cenario2D::deleteAllPhysicObjects(){
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* level = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        level = this->levels[i];
        if(level){
            if(level->objsPhys){
                //remove the objPhys from world
                edk::uint32 sizePhys = level->objsPhys->size();
                for(edk::uint32 j=0u;j<sizePhys;j++){
                    this->world.removeObject((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(j));
                }
                delete level->objsPhys;
                level->clean();
            }
        }
    }
}
//remove the object
bool edk::Cenario2D::removePhysicObject(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj){
    if(levelPosition){
        levelPosition--;
        //load the level
        if(obj){
            if(this->levels.havePos(levelPosition)){
                edk::Cenario2D::LevelObj* level =this->levels[levelPosition];
                if(level){
                    if(level->objsPhys){
                        //remove from world
                        this->world.removeObject(obj);
                        bool ret = level->objsPhys->removeObj((edk::Object2D*)obj);
                        if(!level->objsPhys->size()){
                            //remove from world
                            delete level->objsPhys;
                            level->clean();
                        }
                        return ret;
                    }
                }
            }
        }
    }
    return false;
}

//DELETE ALL LEVELS
void edk::Cenario2D::deleteLevel(edk::uint32 levelPosition){
    if(levelPosition){
        levelPosition--;
        //load the level
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];
            if(level){
                if(level->tileMap){
                    delete level->tileMap;
                }
                if(level->objs){
                    this->deleteAllObjects(levelPosition);
                }
                if(level->objsPhys){
                    //remove the objPhys from world
                    edk::uint32 sizePhys = level->objsPhys->size();
                    for(edk::uint32 j=0u;j<sizePhys;j++){
                        this->world.removeObject((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(j));
                    }
                    delete level->objsPhys;
                }
                level->clean();
            }
        }
    }
}
void edk::Cenario2D::deleteAllLevels(){
    edk::uint32 size = this->levels.size();
    if(size){
        this->treeAnim.clean();
        edk::Cenario2D::LevelObj* level = NULL;
        for(edk::uint32 i=0u;i<size;i++){
            level = this->levels[i];
            if(level){
                if(level->tileMap){
                    delete level->tileMap;
                }
                if(level->objs){
                    this->deleteAllObjects(i+1u);
                }
                if(level->objsPhys){
                    //remove the objPhys from world
                    edk::uint32 sizePhys = level->objsPhys->size();
                    for(edk::uint32 j=0u;j<sizePhys;j++){
                        this->world.removeObject((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(j));
                    }
                    delete level->objsPhys;
                }
                level->clean();
                delete level;
            }
        }
    }
    this->levels.clean();
}

//World
void edk::Cenario2D::worldSetClockScale(edk::float32 scale){
    this->world.setClockScale(scale);
}
//clockStart
void edk::Cenario2D::worldClockStart(){
    this->world.clockStart();
}

//ACTIONS
//play actions
void edk::Cenario2D::playForwardActions(){
    this->actions.playForward();
}
void edk::Cenario2D::playForwardInActions(edk::float32 second){
    this->actions.playForwardIn(second);
}
//void edk::Cenario2D::playRewind();
//void edk::Cenario2D::playRewindIn(edk::float32 second);
void edk::Cenario2D::pauseActions(){
    this->actions.pause();
}
void edk::Cenario2D::stopActions(){
    this->actions.stop();
}
//set loop
void edk::Cenario2D::setLoopActions(bool loop){
    this->actions.setLoop(loop);
}
void edk::Cenario2D::loopOnActions(){
    this->actions.loopOn();
}
void edk::Cenario2D::loopOffActions(){
    this->actions.loopOff();
}

//return if are playing
bool edk::Cenario2D::isPlayingActions(){
    return this->actions.isPlaying();
}
bool edk::Cenario2D::isPausedActions(){
    return this->actions.isPaused();
}
//update actions
void edk::Cenario2D::updateActions(){
    this->actions.update();
}
//remove actions
void edk::Cenario2D::removeAllActions(){
    this->actions.clean();
}
bool edk::Cenario2D::removeActionSecond(edk::float32 second){
    return this->actions.removeSecond(second);
}
//Add zero action
bool edk::Cenario2D::actionZero(edk::float32 second){
    return this->actions.addZeroAction(second);
}
//add position action
bool edk::Cenario2D::actionObjectSetPosition(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::vec2f32 position){
    return this->actions.addAction(second,new edk::Cenario2D::ActionObjectSetPosition(this,levelPosition,depth,position));
}
bool edk::Cenario2D::actionObjectSetPosition(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::float32 x,edk::float32 y){
    return this->actionObjectSetPosition(second,levelPosition,depth,edk::vec2f32(x,y));
}
//add move action
bool edk::Cenario2D::actionObjectMove(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::vec2f32 position){
    if(this->actions.addAction(second,new edk::Cenario2D::ActionObjectMove(this,levelPosition,depth,duration,position))){
        this->actions.addZeroAction(second+duration);
        return true;
    }
    return false;
}
bool edk::Cenario2D::actionObjectMove(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::float32 x,edk::float32 y){
    return this->actionObjectMove(second,duration,levelPosition,depth,edk::vec2f32(x,y));
}
bool edk::Cenario2D::actionObjectMoveTo(edk::float32 start,edk::float32 end,edk::uint32 levelPosition,edk::float32 depth,edk::vec2f32 position){
    return this->actionObjectMove(start,end-start,levelPosition,depth,position);
}
bool edk::Cenario2D::actionObjectMoveTo(edk::float32 start,edk::float32 end,edk::uint32 levelPosition,edk::float32 depth,edk::float32 x,edk::float32 y){
    return this->actionObjectMove(start,end-start,levelPosition,depth,edk::vec2f32(x,y));
}
//add Size action
bool edk::Cenario2D::actionObjectSetSize(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::size2f32 size){
    return this->actions.addAction(second,new edk::Cenario2D::ActionObjectSetSize(this,levelPosition,depth,size));
}
bool edk::Cenario2D::actionObjectSetSize(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::float32 width,edk::float32 height){
    return actionObjectSetSize(second,levelPosition,depth,edk::size2f32(width,height));
}
bool edk::Cenario2D::actionObjectSetSize(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::float32 size){
    return this->actionObjectSetSize(second,levelPosition,depth,size,size);
}
//add scale action
bool edk::Cenario2D::actionObjectScale(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::size2f32 size){
    if(this->actions.addAction(second,new edk::Cenario2D::ActionObjectScale(this,levelPosition,depth,duration,size))){
        this->actions.addZeroAction(second+duration);
        return true;
    }
    return false;
}
bool edk::Cenario2D::actionObjectScale(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::float32 width,edk::float32 height){
    return this->actionObjectScale(second,duration,levelPosition,depth,edk::size2f32(width,height));
}
bool edk::Cenario2D::actionObjectScale(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::float32 size){
    return this->actionObjectScale(second,duration,levelPosition,depth,size,size);
}
bool edk::Cenario2D::actionObjectScaleTo(edk::float32 start,edk::float32 end,edk::uint32 levelPosition,edk::float32 depth,edk::size2f32 size){
    return this->actionObjectScale(start,end-start,levelPosition,depth,size);
}
bool edk::Cenario2D::actionObjectScaleTo(edk::float32 start,edk::float32 end,edk::uint32 levelPosition,edk::float32 depth,edk::float32 width,edk::float32 height){
    return this->actionObjectScale(start,end-start,levelPosition,depth,width,height);
}
bool edk::Cenario2D::actionObjectScaleTo(edk::float32 start,edk::float32 end,edk::uint32 levelPosition,edk::float32 depth,edk::float32 size){
    return this->actionObjectScale(start,end-start,levelPosition,depth,size);
}
//add angle action
bool edk::Cenario2D::actionObjectSetAngle(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::float32 angle){
    return this->actions.addAction(second,new edk::Cenario2D::ActionObjectSetAngle(this,levelPosition,depth,angle));
}
//add angle action
bool edk::Cenario2D::actionObjectRotateFor(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::float32 angle){
    if(this->actions.addAction(second,new edk::Cenario2D::ActionObjectRotate(this,levelPosition,depth,duration,angle))){
        this->actions.addZeroAction(second+duration);
        return true;
    }
    return false;
}
bool edk::Cenario2D::actionObjectRotateTo(edk::float32 start,edk::float32 end,edk::uint32 levelPosition,edk::float32 depth,edk::float32 angle){
    return this->actionObjectRotateFor(start,end-start,levelPosition,depth,angle);
}
//MESH SPRITE SHEET
bool edk::Cenario2D::actionObjectPlayName(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id,edk::char8* name,bool loop){
    return this->actions.addAction(second,new edk::Cenario2D::ActionObjectMeshName(this,levelPosition,depth,id,name,loop));
}
bool edk::Cenario2D::actionObjectPlayName(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id,const char* name,bool loop){
    return this->actionObjectPlayName(second,levelPosition,depth,id,(edk::char8*)name,loop);
}
bool edk::Cenario2D::actionObjectPlayNameFor(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id,edk::char8* name){
    if(this->actions.addAction(second,new edk::Cenario2D::ActionObjectMeshName(this,levelPosition,depth,id,name,true))){
        this->actions.addAction(second+duration,new edk::Cenario2D::ActionObjectMeshStop(this,levelPosition,depth,id));
        return true;
    }
    return false;
}
bool edk::Cenario2D::actionObjectPlayNameFor(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id,const char* name){
    return this->actionObjectPlayNameFor(second,duration,levelPosition,depth,id,(edk::char8*) name);
}


//update the physics and collisions
void edk::Cenario2D::updatePhysics(edk::int32 velocityIterations, edk::int32 positionIterations){
    //
    this->world.nextStep(velocityIterations, positionIterations);
}
//update animations
bool edk::Cenario2D::updateAnimation(edk::uint32 position){
    //test if have the level
    if(this->levels.havePos(position)){
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels[position];
        if(level){
            if(level->objs){
                level->objs->update();
            }
            if(level->objsPhys){
                level->objsPhys->update();
            }
        }
        //update the tileSet
        this->tileSet.updateAnimations();
        return true;
    }
    return false;
}
void edk::Cenario2D::updateAnimations(){
    /*
    //update the levels
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj * level=NULL;
    for(edk::uint32 i=0;i<size;i++){
        level = this->levels[i];
        if(level){
            if(level->objs){
                level->objs->update();
            }
            if(level->objsPhys){
                level->objsPhys->update();
            }
        }
    }
    */
    this->treeAnim.update();
    //update the tileSet
    this->tileSet.updateAnimations();
}
//draw the cenario with all the objects
void edk::Cenario2D::draw(){
    //draw the levels
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* level=NULL;
    for(edk::uint32 i=0u;i<size;i++){
        level=this->levels[i];
        if(level){
            level->draw();
        }
    }
}
bool edk::Cenario2D::drawLevel(edk::uint32 levelPosition){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level=this->levels[levelPosition];
            level->draw();
            return true;
        }
    }
    return false;
}
void edk::Cenario2D::drawSelection(){
    //draw the levels
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* level=NULL;
    for(edk::uint32 i=0u;i<size;i++){
        level=this->levels[i];
        if(level){
            level->drawSelection(i+1u);
        }
    }
}
bool edk::Cenario2D::drawSelectionLevel(edk::uint32 levelPosition){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level=this->levels[levelPosition];
            level->drawSelection(levelPosition+1u);
            return true;
        }
    }
    return false;
}

//SHOW/HIDE LEVEL
bool edk::Cenario2D::hideLevel(edk::uint32 levelPosition){
    return this->setShowLevel(levelPosition,false);
}
bool edk::Cenario2D::showLevel(edk::uint32 levelPosition){
    return this->setShowLevel(levelPosition,true);
}
bool edk::Cenario2D::setShowLevel(edk::uint32 levelPosition,bool show){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level=this->levels[levelPosition];
            level->show = show;
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::getShowLevel(edk::uint32 levelPosition){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level=this->levels[levelPosition];
            return level->show;
        }
    }
    return false;
}

//get level type
edk::uint8 edk::Cenario2D::getLevelType(edk::uint32 levelPosition){
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];
            if(level){
                if(level->objs){
                    return EDK_LEVEL_OBJ;
                }
                if(level->objsPhys){
                    return EDK_LEVEL_OBJ_PHYSICS;
                }
                if(level->tileMap){
                    return EDK_LEVEL_TILE_MAP;
                }
            }
        }
    }
    return 0u;
}
//test if have the level
bool edk::Cenario2D::haveLevel(edk::uint32 levelPosition){
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];
            if(level){
                return level->haveSome();
            }
        }
    }
    return false;
}
//return the levelSize
edk::uint32 edk::Cenario2D::getLevelSize(){
    return this->levels.size();
}
//move the level to back
bool edk::Cenario2D::moveLevelBack(edk::uint32 levelPosition){
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            return this->levels.bringPositionMinusOne(levelPosition);
        }
    }
    return false;
}
bool edk::Cenario2D::moveLevelFront(edk::uint32 levelPosition){
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            return this->levels.bringPositionPlusOne(levelPosition);
        }
    }
    return false;
}

//XML
bool edk::Cenario2D::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Cenario_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //write the tileSet
                        this->tileSet.writeToXML(xml,0u);

                        //add levels
                        edk::char8* temp;
                        edk::char8* nameTemp;
                        edk::char8* idTemp;

                        //write the levels
                        edk::uint32 size = this->levels.size();
                        temp = edk::String::int64ToStr(size);
                        if(temp){
                            //add levels
                            if(xml->addSelectedNextChild("levels")){
                                if(xml->selectChild("levels")){
                                    xml->setSelectedString(temp);
                                    edk::Cenario2D::LevelObj* level;
                                    for(edk::uint32 i=0u;i<size;i++){
                                        //load the level
                                        level = this->levels[i];
                                        if(level){
                                            level->writeToXML(xml,i);
                                        }
                                    }
                                    xml->selectFather();
                                }
                            }
                            delete[] temp;
                        }

                        //JOINTS
                        if(xml->addSelectedNextChild("joints")){
                            if(xml->selectChild("joints")){
                                size = this->world.getJointSize();
                                temp = edk::String::int64ToStr(size);
                                if(temp){
                                    xml->setSelectedString(temp);
                                    delete[] temp;
                                }
                                edk::uint8 jointType;
                                edk::physics2D::Joint2D* joint;
                                edk::physics2D::RevoluteJoint2D* revoluteJoint;
                                edk::physics2D::DistanceJoint2D* distanceJoint;
                                edk::physics2D::PrismaticJoint2D* prismaticJoint;
                                edk::physics2D::PulleyJoint2D* pulleyJoint;
                                edk::physics2D::WheelJoint2D* wheelJoint;
                                edk::physics2D::RopeJoint2D* ropeJoint;
                                edk::Cenario2D::PhysicsPosition objectA;
                                edk::Cenario2D::PhysicsPosition objectB;
                                for(edk::uint32 i=0u;i<size;i++){
                                    //test if have the joint in position
                                    if((joint = this->world.getJointInPosition(i))){
                                        //load the object
                                        if(this->getPhysicsLevelObject(joint->objectA,&objectA)){
                                            if(this->getPhysicsLevelObject(joint->objectB,&objectB)){
                                                idTemp = edk::String::int64ToStr(i);
                                                if(idTemp){
                                                    nameTemp = edk::String::strCat((edk::char8*)"joint_",idTemp);
                                                    if(nameTemp){
                                                        //create the xmlNode
                                                        if(xml->addSelectedNextChild(nameTemp)){
                                                            if(xml->selectChild(nameTemp)){
                                                                jointType = this->world.getJointTypeInPosition(i);
                                                                temp = edk::String::int64ToStr(jointType);
                                                                if(temp){
                                                                    xml->setSelectedString(temp);
                                                                    delete[] temp;
                                                                }
                                                                //Write the object
                                                                objectA.writeToXML(xml,true);
                                                                objectB.writeToXML(xml,false);

                                                                temp = edk::String::float32ToStr(joint->worldPositionA.x);
                                                                if(temp){
                                                                    xml->addSelectedNextAttribute((edk::char8*)"worldPositionAX",temp);
                                                                    delete[] temp;
                                                                }
                                                                temp = edk::String::float32ToStr(joint->worldPositionA.y);
                                                                if(temp){
                                                                    xml->addSelectedNextAttribute((edk::char8*)"worldPositionAY",temp);
                                                                    delete[] temp;
                                                                }
                                                                //Positions
                                                                temp = edk::String::float32ToStr(joint->positionA.x);
                                                                if(temp){
                                                                    xml->addSelectedNextAttribute((edk::char8*)"positionAX",temp);
                                                                    delete[] temp;
                                                                }
                                                                temp = edk::String::float32ToStr(joint->positionA.y);
                                                                if(temp){
                                                                    xml->addSelectedNextAttribute((edk::char8*)"positionAY",temp);
                                                                    delete[] temp;
                                                                }
                                                                temp = edk::String::float32ToStr(joint->positionB.x);
                                                                if(temp){
                                                                    xml->addSelectedNextAttribute((edk::char8*)"positionBX",temp);
                                                                    delete[] temp;
                                                                }
                                                                temp = edk::String::float32ToStr(joint->positionB.y);
                                                                if(temp){
                                                                    xml->addSelectedNextAttribute((edk::char8*)"positionBY",temp);
                                                                    delete[] temp;
                                                                }

                                                                //collide
                                                                if(joint->getCollide()){
                                                                    xml->addSelectedNextAttribute("collide","true");
                                                                }

                                                                switch(jointType){
                                                                case EDK_JOINT:
                                                                    //
                                                                    //xml->setSelectedString("JOINT");
                                                                    break;
                                                                case EDK_REVOLUTE_JOINT:
                                                                    //
                                                                    //xml->setSelectedString("REVOLUTE_JOINT");
                                                                    revoluteJoint = (edk::physics2D::RevoluteJoint2D*)this->world.getJointInPosition(i);
                                                                    //test the revoluteType
                                                                    switch(revoluteJoint->getRevoluteType()){
                                                                    case EDK_JOINT_ANGLE:
                                                                        xml->addSelectedNextAttribute("type","ANGLE");
                                                                        temp = edk::String::float32ToStr(revoluteJoint->getLowerAngle());
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"lowerAngle",temp);
                                                                            delete[] temp;
                                                                        }
                                                                        temp = edk::String::float32ToStr(revoluteJoint->getUpperAngle());
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"upperAngle",temp);
                                                                            delete[] temp;
                                                                        }
                                                                        break;
                                                                    case EDK_JOINT_MOTOR:
                                                                        xml->addSelectedNextAttribute("type","MOTOR");
                                                                        temp = edk::String::float32ToStr(revoluteJoint->getMaxTorque());
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"maxTorque",temp);
                                                                            delete[] temp;
                                                                        }
                                                                        temp = edk::String::float32ToStr(revoluteJoint->getSpeed());
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"speed",temp);
                                                                            delete[] temp;
                                                                        }
                                                                        break;
                                                                    default:
                                                                        xml->addSelectedNextAttribute("type","NORMAL");
                                                                    }
                                                                    break;
                                                                case EDK_PRISMATIC_JOINT:
                                                                    //
                                                                    //xml->setSelectedString("PRISMATIC_JOINT");
                                                                    prismaticJoint = (edk::physics2D::PrismaticJoint2D*)this->world.getJointInPosition(i);
                                                                    //write direction
                                                                    temp = edk::String::float32ToStr(prismaticJoint->direction.x);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"directionX",temp);
                                                                        delete[] temp;
                                                                    }
                                                                    temp = edk::String::float32ToStr(prismaticJoint->direction.y);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"directionY",temp);
                                                                        delete[] temp;
                                                                    }
                                                                    //test the Type
                                                                    if(prismaticJoint->getPrismaticType() == EDK_JOINT_MOTOR){
                                                                        xml->addSelectedNextAttribute("type","MOTOR");
                                                                        temp = edk::String::float32ToStr(prismaticJoint->getMaxForce());
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"maxForce",temp);
                                                                            delete[] temp;
                                                                        }
                                                                        temp = edk::String::float32ToStr(prismaticJoint->getSpeed());
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"speed",temp);
                                                                            delete[] temp;
                                                                        }
                                                                    }
                                                                    temp = edk::String::float32ToStr(prismaticJoint->lowerDistance);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"lowerDistance",temp);
                                                                        delete[] temp;
                                                                    }
                                                                    temp = edk::String::float32ToStr(prismaticJoint->upperDistance);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"upperDistance",temp);
                                                                        delete[] temp;
                                                                    }
                                                                    break;
                                                                case EDK_PULLEY_JOINT:
                                                                    //
                                                                    //xml->setSelectedString("PULLEY_JOINT");
                                                                    pulleyJoint = (edk::physics2D::PulleyJoint2D*)this->world.getJointInPosition(i);
                                                                    //write pulleyPositions
                                                                    temp = edk::String::float32ToStr(pulleyJoint->pulleyPositionA.x);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"pulleyPositionAX",temp);
                                                                        delete[] temp;
                                                                    }
                                                                    temp = edk::String::float32ToStr(pulleyJoint->pulleyPositionA.y);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"pulleyPositionAY",temp);
                                                                        delete[] temp;
                                                                    }
                                                                    temp = edk::String::float32ToStr(pulleyJoint->pulleyPositionB.x);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"pulleyPositionBX",temp);
                                                                        delete[] temp;
                                                                    }
                                                                    temp = edk::String::float32ToStr(pulleyJoint->pulleyPositionB.y);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"pulleyPositionBY",temp);
                                                                        delete[] temp;
                                                                    }
                                                                    temp = edk::String::float32ToStr(pulleyJoint->lenghtA);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"lenghtA",temp);
                                                                        delete[] temp;
                                                                    }
                                                                    temp = edk::String::float32ToStr(pulleyJoint->lenghtB);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"lenghtB",temp);
                                                                        delete[] temp;
                                                                    }
                                                                case EDK_DISTANCE_JOINT:
                                                                    //
                                                                    //xml->setSelectedString("DISTANCE_JOINT");
                                                                    distanceJoint = (edk::physics2D::DistanceJoint2D*)this->world.getJointInPosition(i);
                                                                    temp = edk::String::float32ToStr(distanceJoint->worldPositionB.x);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"worldPositionBX",temp);
                                                                        delete[] temp;
                                                                    }
                                                                    temp = edk::String::float32ToStr(distanceJoint->worldPositionB.y);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"worldPositionBY",temp);
                                                                        delete[] temp;
                                                                    }
                                                                    //distance
                                                                    temp = edk::String::float32ToStr(distanceJoint->distance);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"distance",temp);
                                                                        delete[] temp;
                                                                    }
                                                                    break;
                                                                case EDK_WHEEL_JOINT:
                                                                    //
                                                                    //xml->setSelectedString("WHEEL_JOINT");
                                                                    wheelJoint = (edk::physics2D::WheelJoint2D*)this->world.getJointInPosition(i);
                                                                    //write direction
                                                                    temp = edk::String::float32ToStr(wheelJoint->direction.x);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"directionX",temp);
                                                                        delete[] temp;
                                                                    }
                                                                    temp = edk::String::float32ToStr(wheelJoint->direction.y);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"directionY",temp);
                                                                        delete[] temp;
                                                                    }
                                                                    //test the Type
                                                                    if(wheelJoint->getWheelType() == EDK_JOINT_MOTOR){
                                                                        xml->addSelectedNextAttribute("type","MOTOR");
                                                                        temp = edk::String::float32ToStr(wheelJoint->getMaxTorque());
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"maxTorque",temp);
                                                                            delete[] temp;
                                                                        }
                                                                        temp = edk::String::float32ToStr(wheelJoint->getSpeed());
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"speed",temp);
                                                                            delete[] temp;
                                                                        }
                                                                    }
                                                                    temp = edk::String::float32ToStr(wheelJoint->frequency);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"frequency",temp);
                                                                        delete[] temp;
                                                                    }
                                                                    temp = edk::String::float32ToStr(wheelJoint->dampingRatio);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"dampingRatio",temp);
                                                                        delete[] temp;
                                                                    }
                                                                    break;
                                                                case EDK_ROPE_JOINT:
                                                                    //
                                                                    //xml->setSelectedString("ROPE_JOINT");
                                                                    ropeJoint = (edk::physics2D::RopeJoint2D*)this->world.getJointInPosition(i);
                                                                    //
                                                                    temp = edk::String::float32ToStr(ropeJoint->worldPositionB.x);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"worldPositionBX",temp);
                                                                        delete[] temp;
                                                                    }
                                                                    temp = edk::String::float32ToStr(ropeJoint->worldPositionB.y);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"worldPositionBY",temp);
                                                                        delete[] temp;
                                                                    }
                                                                    temp = edk::String::float32ToStr(ropeJoint->maxLength);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"maxLength",temp);
                                                                        delete[] temp;
                                                                    }
                                                                    break;
                                                                }
                                                                xml->selectFather();
                                                            }
                                                        }
                                                        delete[] nameTemp;
                                                    }
                                                    delete[] idTemp;
                                                }
                                            }
                                        }
                                    }
                                }
                                xml->selectFather();
                            }
                        }

                        //ACTIONS
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
bool edk::Cenario2D::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Cenario_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* nameTemp;
                    edk::char8* idTemp;
                    edk::char8* temp;

                    //read tileSet
                    this->tileSet.readFromXML(xml,0u);
                    //read the levels
                    if(xml->selectChild("levels")){

                        this->deleteAllLevels();
                        edk::uint32 size = 0u;

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            delete[] temp;
                        }
                        edk::Cenario2D::LevelObj* level;
                        for(edk::uint32 i=0u;i<size;i++){
                            //load the level
                            level = new edk::Cenario2D::LevelObj;
                            if(level){
                                //add the level to the tree
                                this->levels.pushBack(level);
                                level->readFromXML(xml,i,&this->tileSet,&this->world);
                            }
                        }
                        this->loadPhysicObjectsToWorld();
                        xml->selectFather();
                    }

                    //JOINTS
                    if(xml->selectChild("joints")){
                        edk::uint32 size = 0u;
                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            delete[] temp;
                        }
                        //object vectors
                        bool collide;
                        edk::vec2f32 worldPosition;
                        edk::vec2f32 positionA;
                        edk::vec2f32 positionB;
                        for(edk::uint32 i = 0u;i<size;i++){
                            collide=false;
                            edk::Cenario2D::PhysicsPosition objectA;
                            edk::Cenario2D::PhysicsPosition objectB;
                            idTemp = edk::String::int64ToStr(i);
                            if(idTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"joint_",idTemp);
                                if(nameTemp){
                                    //create the xmlNode
                                    if(xml->selectChild(nameTemp)){
                                        //read the type
                                        edk::uint8 jointType = 0u;
                                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                                        if(temp){
                                            jointType = edk::String::strToInt32(temp);
                                            delete[] temp;
                                        }
                                        //read the objects
                                        objectA.readFromXML(xml,true);
                                        objectB.readFromXML(xml,false);
                                        //ret collide
                                        if(xml->getSelectedAttributeValueByName("collide")){
                                            collide=true;
                                        }
                                        //getWorldPosition
                                        worldPosition = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionAX")),
                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionAY")));
                                        positionA = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionAX")),
                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionAY")));
                                        positionB = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionBX")),
                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionBY")));

                                        switch(jointType){
                                        case EDK_JOINT:
                                            //add the joint
                                            //                                            this->world.createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                        this->getPhysicsObjectInLevel(objectB),
                                            //                                                                        worldPosition,
                                            //                                                                        collide
                                            //                                                                        );
                                            this->world.createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        collide
                                                                        );
                                            break;
                                        case EDK_REVOLUTE_JOINT:
                                            //test the revoluteType
                                            if(edk::String::strCompare(xml->getSelectedAttributeValueByName("type"),"ANGLE")){
                                                //"lowerAngle"
                                                //"upperAngle"
                                                //                                                this->world.createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                     worldPosition,
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerAngle")),
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperAngle")),
                                                //                                                                                     collide
                                                //                                                                                     );
                                                this->world.createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                     positionA,
                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                                                     positionB,
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerAngle")),
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperAngle")),
                                                                                     collide
                                                                                     );
                                            }
                                            else if(edk::String::strCompare(xml->getSelectedAttributeValueByName("type"),"MOTOR")){
                                                //"maxTorque"
                                                //"speed"
                                                //                                                this->world.createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                     worldPosition,
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                     collide
                                                //                                                                                     );
                                                this->world.createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                     positionA,
                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                                                     positionB,
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                     collide
                                                                                     );
                                            }
                                            else if(edk::String::strCompare(xml->getSelectedAttributeValueByName("type"),"NORMAL")){
                                                //
                                                //                                                this->world.createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                worldPosition,
                                                //                                                                                collide
                                                //                                                                                );
                                                this->world.createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                positionA,
                                                                                this->getPhysicsObjectInLevel(objectB),
                                                                                positionB,
                                                                                collide
                                                                                );
                                            }
                                            break;
                                        case EDK_DISTANCE_JOINT:
                                            //create distanceJoint
                                            //                                            this->world.createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                            worldPosition,
                                            //                                                                            this->getPhysicsObjectInLevel(objectB),
                                            //                                                                            edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBX")),
                                            //                                                                                         edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBY"))
                                            //                                                                                         ),
                                            //                                                                            collide);
                                            this->world.createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                                                            positionA,
                                                                            this->getPhysicsObjectInLevel(objectB),
                                                                            positionB,
                                                                            edk::String::strToFloat32(xml->getSelectedAttributeValueByName("distance")),
                                                                            collide);
                                            break;
                                        case EDK_PRISMATIC_JOINT:
                                            //test the Type
                                            if(edk::String::strCompare(xml->getSelectedAttributeValueByName("type"),"MOTOR")){
                                                //"maxTorque"
                                                //"speed"
                                                //                                                this->world.createPrismaticMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                      this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                      worldPosition,
                                                //                                                                                      edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                                   ),
                                                //                                                                                      edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerDistance")),
                                                //                                                                                      edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperDistance")),
                                                //                                                                                      edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxForce")),
                                                //                                                                                      edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                      collide
                                                //                                                                                      );
                                                this->world.createPrismaticMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                      positionA,
                                                                                      this->getPhysicsObjectInLevel(objectB),
                                                                                      positionB,
                                                                                      edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                                   ),
                                                                                      edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerDistance")),
                                                                                      edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperDistance")),
                                                                                      edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxForce")),
                                                                                      edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                      collide
                                                                                      );
                                            }
                                            else{
                                                //"lowerAngle"
                                                //"upperAngle"
                                                //"directionX"
                                                //"directionY"
                                                //                                                this->world.createPrismaticJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                 this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                 worldPosition,
                                                //                                                                                 edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                              ),
                                                //                                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerDistance")),
                                                //                                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperDistance")),
                                                //                                                                                 collide
                                                //                                                                                 );
                                                this->world.createPrismaticJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                 positionA,
                                                                                 this->getPhysicsObjectInLevel(objectB),
                                                                                 positionB,
                                                                                 edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                              ),
                                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerDistance")),
                                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperDistance")),
                                                                                 collide
                                                                                 );
                                            }
                                            break;
                                        case EDK_PULLEY_JOINT:
                                            //
                                            //                                            this->world.createPulleyWorldJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                               worldPosition,
                                            //                                                                               edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pulleyPositionAX")),
                                            //                                                                                            edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pulleyPositionAY"))
                                            //                                                                                            ),
                                            //                                                                               this->getPhysicsObjectInLevel(objectB),
                                            //                                                                               edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBX")),
                                            //                                                                                            edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBY"))
                                            //                                                                                            ),
                                            //                                                                               edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pulleyPositionBX")),
                                            //                                                                                            edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pulleyPositionBY"))
                                            //                                                                                            ),
                                            //                                                                               collide
                                            //                                                                               );
                                            this->world.createPulleyJoint(this->getPhysicsObjectInLevel(objectA),
                                                                          positionA,
                                                                          edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pulleyPositionAX")),
                                                                                       edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pulleyPositionAY"))
                                                                                       ),
                                                                          this->getPhysicsObjectInLevel(objectB),
                                                                          positionB,
                                                                          edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pulleyPositionBX")),
                                                                                       edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pulleyPositionBY"))
                                                                                       ),
                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lenghtA")),
                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lenghtB")),
                                                                          collide
                                                                          );
                                            break;
                                        case EDK_WHEEL_JOINT:
                                            //
                                            if(edk::String::strCompare(xml->getSelectedAttributeValueByName("type"),"MOTOR")){
                                                //
                                                //                                                this->world.createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                  this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                  worldPosition,
                                                //                                                                                  edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                               ),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("frequency")),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("dampingRatio")),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                  collide
                                                //                                                                                  );
                                                this->world.createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                  positionA,
                                                                                  this->getPhysicsObjectInLevel(objectB),
                                                                                  positionB,
                                                                                  edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                               ),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("frequency")),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("dampingRatio")),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                  collide
                                                                                  );
                                            }
                                            else{
                                                //
                                                //                                                this->world.createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                             this->getPhysicsObjectInLevel(objectB),
                                                //                                                                             worldPosition,
                                                //                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                          ),
                                                //                                                                             edk::String::strToFloat32(xml->getSelectedAttributeValueByName("frequency")),
                                                //                                                                             edk::String::strToFloat32(xml->getSelectedAttributeValueByName("dampingRatio")),
                                                //                                                                             collide
                                                //                                                                             );
                                                this->world.createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                                             positionA,
                                                                             this->getPhysicsObjectInLevel(objectB),
                                                                             positionB,
                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                          ),
                                                                             edk::String::strToFloat32(xml->getSelectedAttributeValueByName("frequency")),
                                                                             edk::String::strToFloat32(xml->getSelectedAttributeValueByName("dampingRatio")),
                                                                             collide
                                                                             );
                                            }
                                            break;
                                        case EDK_ROPE_JOINT:
                                            //
                                            //                                            this->world.createRopeJointWorldPositions(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                                      worldPosition,
                                            //                                                                                      this->getPhysicsObjectInLevel(objectB),
                                            //                                                                                      edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                            //                                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                            //                                                                                                   ),
                                            //                                                                                      edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
                                            //                                                                                      collide
                                            //                                                                                      );
                                            this->world.createRopeJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
                                                                        collide
                                                                        );
                                            break;
                                        }
                                    }
                                    delete[] nameTemp;
                                }
                                delete[] idTemp;
                            }
                        }
                    }

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
