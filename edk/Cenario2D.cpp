#include "Cenario2D.h"

/*
Library C++ Cenario2D - 2D Cenario to draw objects, physic objects and tilemaps
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

edk::Cenario2D::Cenario2D():
    treeAnimPhys(&this->world)
{
    //
    this->world.addContactCallback(this);edkEnd();
    this->cleanSelectedTileMap();edkEnd();
    this->actions.setReadXMLActionFunction(&edk::Cenario2D::readXMLAction);edkEnd();
}
edk::Cenario2D::~Cenario2D(){
    //
    this->calls.clean();edkEnd();
    this->world.removeContactCallback(this);edkEnd();
    this->deleteAllLevels();edkEnd();
    this->tileSet.deleteTiles();edkEnd();
    this->actions.clean();edkEnd();
}

//Function to read the actions
edk::Action* edk::Cenario2D::readXMLAction(edk::classID thisPointer,edk::uint32 actionCode){
    switch(actionCode){
    case 1u:
    {
        //ActionPosition
        return new edk::Cenario2D::ActionObjectSetPosition((edk::Cenario2D*)thisPointer,0,0,edk::vec2f32(0,0));edkEnd();
    }
    case 2u:
    {
        //ActionMove
        return new edk::Cenario2D::ActionObjectMove((edk::Cenario2D*)thisPointer,0,0,0,edk::vec2f32(0,0));edkEnd();
    }
    case 3u:
    {
        //ActionSetSize
        return new edk::Cenario2D::ActionObjectSetSize((edk::Cenario2D*)thisPointer,0,0,edk::size2f32(0,0));edkEnd();
    }
    case 4u:
    {
        //ActionSize
        return new edk::Cenario2D::ActionObjectScale((edk::Cenario2D*)thisPointer,0,0,0,edk::size2f32(0,0));edkEnd();
    }
    case 5u:
    {
        //ActionSetAngle
        return new edk::Cenario2D::ActionObjectSetAngle((edk::Cenario2D*)thisPointer,0,0,0);edkEnd();
    }
    case 6u:
    {
        //ActionAngle
        return new edk::Cenario2D::ActionObjectRotate((edk::Cenario2D*)thisPointer,0,0,0,0);edkEnd();
    }
    case 7u:
    {
        //ActionMeshName
        return new edk::Cenario2D::ActionObjectMeshName((edk::Cenario2D*)thisPointer,0,0,0,NULL,false);edkEnd();
    }
    case 8u:
    {
        //ActionMeshStop
        return new edk::Cenario2D::ActionObjectMeshStop((edk::Cenario2D*)thisPointer,0,0,0);edkEnd();
    }
    }
    return new edk::ActionZero();edkEnd();
}
//transformBeggin
void edk::Cenario2D::transformBeggin(){
    edk::GU::guPushMatrix();edkEnd();
    //set the translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
}
void edk::Cenario2D::transformEnd(){
    edk::GU::guPopMatrix();edkEnd();
}

//XML
bool edk::Cenario2D::TreeObjDepth::writeToXML(edk::XML* xml,edk::uint32 id,bool isPhysics){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Objects_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //
                        edk::char8* temp;edkEnd();
                        edk::char8* nameTemp;edkEnd();
                        edk::char8* idTemp;edkEnd();
                        edk::uint32 size = this->size();edkEnd();
                        //write the size
                        temp = edk::String::int64ToStr(size);edkEnd();
                        if(temp){
                            //write the size
                            xml->setSelectedString(temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        edk::Cenario2D::ObjClass* objClass;edkEnd();
                        if(isPhysics){
                            edk::physics2D::PhysicObject2D* physObj=NULL;edkEnd();
                            for(edk::uint32 i=0u;i<size;i++){
                                objClass = this->getElementInPosition(i);edkEnd();
                                if(objClass){
                                    idTemp = edk::String::int64ToStr(i);edkEnd();
                                    if(idTemp){
                                        nameTemp = edk::String::strCat((edk::char8*)"obj_",idTemp);edkEnd();
                                        if(nameTemp){
                                            if(xml->addSelectedNextChild(nameTemp)){
                                                if(xml->selectChild(nameTemp)){
                                                    //add attributes
                                                    temp = edk::String::float32ToStr(objClass->depth);edkEnd();
                                                    if(temp){
                                                        xml->setSelectedString(temp);edkEnd();
                                                        delete[] temp;edkEnd();
                                                    }
                                                    //write the object
                                                    if((physObj = (edk::physics2D::PhysicObject2D*)objClass->getObject())){
                                                        //
                                                        physObj->writeToXML(xml,i);edkEnd();
                                                    }
                                                    xml->selectFather();edkEnd();
                                                }
                                            }
                                            delete[] nameTemp;edkEnd();
                                        }
                                        delete []idTemp;edkEnd();
                                    }
                                }
                            }
                        }
                        else{
                            edk::Object2D* obj=NULL;edkEnd();
                            for(edk::uint32 i=0u;i<size;i++){
                                objClass = this->getElementInPosition(i);edkEnd();
                                if(objClass){
                                    idTemp = edk::String::int64ToStr(i);edkEnd();
                                    if(idTemp){
                                        nameTemp = edk::String::strCat((edk::char8*)"obj_",idTemp);edkEnd();
                                        if(nameTemp){
                                            if(xml->addSelectedNextChild(nameTemp)){
                                                if(xml->selectChild(nameTemp)){
                                                    //add attributes
                                                    temp = edk::String::float32ToStr(objClass->depth);edkEnd();
                                                    if(temp){
                                                        xml->setSelectedString(temp);edkEnd();
                                                        delete[] temp;edkEnd();
                                                    }
                                                    //write the object
                                                    if((obj=objClass->getObject())){
                                                        //
                                                        obj->writeToXML(xml,i);edkEnd();
                                                    }
                                                    xml->selectFather();edkEnd();
                                                }
                                            }
                                            delete[] nameTemp;edkEnd();
                                        }
                                        delete []idTemp;edkEnd();
                                    }
                                }
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
bool edk::Cenario2D::TreeObjDepth::readFromXML(edk::XML* xml,edk::uint32 id,bool isPhysics){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Objects_",nameID);edkEnd();
            if(name){
                //
                //create the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* temp;edkEnd();
                    //read the object size
                    edk::uint32 size = 0u;edkEnd();
                    temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                    if(temp){
                        size = edk::String::strToInt64(temp);edkEnd();
                        delete[] temp;edkEnd();
                    }
                    if(size){
                        edk::char8* nameTemp;edkEnd();
                        edk::char8* idTemp;edkEnd();
                        edk::float32 depth;edkEnd();
                        if(isPhysics){
                            //load the objects
                            edk::physics2D::PhysicObject2D* obj;edkEnd();
                            for(edk::uint32 i=0u;i<size;i++){
                                depth = 0.f;edkEnd();
                                idTemp = edk::String::int64ToStr(i);edkEnd();
                                if(idTemp){
                                    nameTemp = edk::String::strCat((edk::char8*)"obj_",idTemp);edkEnd();
                                    if(nameTemp){
                                        if(xml->selectChild(nameTemp)){
                                            //read the depth
                                            depth=0u;
                                            temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                                            if(temp){
                                                depth = edk::String::strToFloat32(temp);edkEnd();
                                                delete[] temp;edkEnd();
                                            }
                                            //create the object
                                            if(edk::physics2D::PhysicObject2D::readFromXMLisSensor(xml,i)){
                                                //
                                                obj = new edk::physics2D::StaticSensor2D;edkEnd();
                                            }
                                            else{
                                                obj = new edk::physics2D::PhysicObject2D;edkEnd();
                                            }
                                            if(obj){
                                                //read the object
                                                if(obj->readFromXML(xml,i)){
                                                    //add the object
                                                    if(!this->addObject(true,(edk::Object2D*)obj,depth)){
                                                        //else delete the object
                                                        delete obj;edkEnd();
                                                    }
                                                    obj->playMeshAnimations();edkEnd();
                                                    obj->animationPosition.playForwardAllTracks();edkEnd();
                                                    obj->animationRotation.playForward();edkEnd();
                                                    obj->animationSize.playForward();edkEnd();
                                                }
                                                else{
                                                    delete obj;edkEnd();
                                                }
                                            }

                                            xml->selectFather();edkEnd();
                                        }
                                        delete[] nameTemp;edkEnd();
                                    }
                                    delete[] idTemp;edkEnd();
                                }
                            }
                        }
                        else{
                            //load the objects
                            edk::Object2D* obj;edkEnd();
                            for(edk::uint32 i=0u;i<size;i++){
                                depth = 0.f;edkEnd();
                                idTemp = edk::String::int64ToStr(i);edkEnd();
                                if(idTemp){
                                    nameTemp = edk::String::strCat((edk::char8*)"obj_",idTemp);edkEnd();
                                    if(nameTemp){
                                        if(xml->selectChild(nameTemp)){
                                            //read the depth
                                            depth=0u;
                                            temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                                            if(temp){
                                                depth = edk::String::strToFloat32(temp);edkEnd();
                                                delete[] temp;edkEnd();
                                            }
                                            //create the object
                                            obj = new edk::Object2D;edkEnd();
                                            if(obj){
                                                //read the object
                                                if(obj->readFromXML(xml,i)){
                                                    //add the object
                                                    if(!this->addObject(true,obj,depth)){
                                                        //else delete the object
                                                        delete obj;edkEnd();
                                                    }
                                                    obj->playMeshAnimations();edkEnd();
                                                    obj->animationPosition.playForwardAllTracks();edkEnd();
                                                    obj->animationRotation.playForward();edkEnd();
                                                    obj->animationSize.playForward();edkEnd();
                                                }
                                                else{
                                                    delete obj;edkEnd();
                                                }
                                            }
                                            xml->selectFather();edkEnd();
                                        }
                                        delete[] nameTemp;edkEnd();
                                    }
                                    delete [] idTemp;edkEnd();
                                }
                            }
                        }
                    }
                    //
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
bool edk::Cenario2D::TreeObjDepth::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id,bool isPhysics){
    if(xml && pack){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Objects_",nameID);edkEnd();
            if(name){
                //
                //create the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* temp;edkEnd();
                    //read the object size
                    edk::uint32 size = 0u;edkEnd();
                    temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                    if(temp){
                        size = edk::String::strToInt64(temp);edkEnd();
                        delete[] temp;edkEnd();
                    }
                    if(size){
                        edk::char8* nameTemp;edkEnd();
                        edk::char8* idTemp;edkEnd();
                        edk::float32 depth;edkEnd();
                        if(isPhysics){
                            //load the objects
                            edk::physics2D::PhysicObject2D* obj;edkEnd();
                            for(edk::uint32 i=0u;i<size;i++){
                                depth = 0.f;edkEnd();
                                idTemp = edk::String::int64ToStr(i);edkEnd();
                                if(idTemp){
                                    nameTemp = edk::String::strCat((edk::char8*)"obj_",idTemp);edkEnd();
                                    if(nameTemp){
                                        if(xml->selectChild(nameTemp)){
                                            //read the depth
                                            depth=0u;
                                            temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                                            if(temp){
                                                depth = edk::String::strToFloat32(temp);edkEnd();
                                                delete[] temp;edkEnd();
                                            }
                                            //create the object
                                            if(edk::physics2D::PhysicObject2D::readFromXMLisSensor(xml,i)){
                                                //
                                                obj = new edk::physics2D::StaticSensor2D;edkEnd();
                                            }
                                            else{
                                                obj = new edk::physics2D::PhysicObject2D;edkEnd();
                                            }
                                            if(obj){
                                                //read the object
                                                if(obj->readFromXMLFromPack(pack,xml,i)){
                                                    //add the object
                                                    if(!this->addObject(true,(edk::Object2D*)obj,depth)){
                                                        //else delete the object
                                                        delete obj;edkEnd();
                                                    }
                                                    obj->playMeshAnimations();edkEnd();
                                                    obj->animationPosition.playForwardAllTracks();edkEnd();
                                                    obj->animationRotation.playForward();edkEnd();
                                                    obj->animationSize.playForward();edkEnd();
                                                }
                                                else{
                                                    delete obj;edkEnd();
                                                }
                                            }

                                            xml->selectFather();edkEnd();
                                        }
                                        delete[] nameTemp;edkEnd();
                                    }
                                    delete[] idTemp;edkEnd();
                                }
                            }
                        }
                        else{
                            //load the objects
                            edk::Object2D* obj;edkEnd();
                            for(edk::uint32 i=0u;i<size;i++){
                                depth = 0.f;edkEnd();
                                idTemp = edk::String::int64ToStr(i);edkEnd();
                                if(idTemp){
                                    nameTemp = edk::String::strCat((edk::char8*)"obj_",idTemp);edkEnd();
                                    if(nameTemp){
                                        if(xml->selectChild(nameTemp)){
                                            //read the depth
                                            depth=0u;
                                            temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                                            if(temp){
                                                depth = edk::String::strToFloat32(temp);edkEnd();
                                                delete[] temp;edkEnd();
                                            }
                                            //create the object
                                            obj = new edk::Object2D;edkEnd();
                                            if(obj){
                                                //read the object
                                                if(obj->readFromXMLFromPack(pack,xml,i)){
                                                    //add the object
                                                    if(!this->addObject(true,obj,depth)){
                                                        //else delete the object
                                                        delete obj;edkEnd();
                                                    }
                                                    obj->playMeshAnimations();edkEnd();
                                                    obj->animationPosition.playForwardAllTracks();edkEnd();
                                                    obj->animationRotation.playForward();edkEnd();
                                                    obj->animationSize.playForward();edkEnd();
                                                }
                                                else{
                                                    delete obj;edkEnd();
                                                }
                                            }
                                            xml->selectFather();edkEnd();
                                        }
                                        delete[] nameTemp;edkEnd();
                                    }
                                    delete [] idTemp;edkEnd();
                                }
                            }
                        }
                    }
                    //
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

//XML
bool edk::Cenario2D::LevelObj::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Level_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //test witch type o level
                        if(this->objs){
                            //write the string
                            xml->setSelectedString("objs");edkEnd();
                            this->objs->writeToXML(xml,0u);edkEnd();
                        }
                        else if(this->objsPhys){
                            //write the string
                            xml->setSelectedString("objsPhys");edkEnd();
                            this->objsPhys->writeToXML(xml,0u,true);edkEnd();
                        }
                        else if(this->tileMap){
                            //write the string
                            xml->setSelectedString("tileMap");edkEnd();
                            //write tileMap
                            this->tileMap->writeToXML(xml,0u);edkEnd();
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
bool edk::Cenario2D::LevelObj::readFromXML(edk::XML* xml,edk::uint32 id,edk::tiles::TileSet2D* tileSet,edk::physics2D::World2D* world){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Level_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* temp;edkEnd();

                    //delete if have some
                    if(this->haveSome()){
                        //delete the some
                        if(this->objs){
                            //read the objects
                            delete this->objs;edkEnd();
                        }
                        else if(this->objsPhys){
                            //read the objects
                            delete this->objsPhys;edkEnd();
                        }
                        else if(this->tileMap){
                            //read the objects
                            delete this->tileMap;edkEnd();
                        }
                    }

                    //test the string
                    temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                    if(temp){
                        if(edk::String::strCompare(temp,"objs")){
                            //read the objects
                            this->objs = new edk::Cenario2D::TreeObjDepth;edkEnd();
                            if(this->objs){
                                this->quadObjs = new edk::Cenario2D::QuadObjs(this->calls);edkEnd();
                                if(this->quadObjs){
                                    if(!this->objs->readFromXML(xml,0u)){
                                        delete this->quadObjs;edkEnd();
                                        delete this->objs;edkEnd();
                                        this->clean();edkEnd();
                                    }
                                }
                                else{
                                    delete this->objs;edkEnd();
                                }
                            }
                        }
                        else if(edk::String::strCompare(temp,"objsPhys")){
                            //read the physics objects
                            this->objsPhys = new edk::Cenario2D::TreePhysObjDepth(world);edkEnd();
                            if(this->objsPhys){
                                this->quadPhysicObjs = new edk::Cenario2D::QuadPhyicObjs(world,this->calls);edkEnd();
                                if(quadPhysicObjs){
                                    if(!this->objsPhys->readFromXML(xml,0u,true)){
                                        delete this->quadPhysicObjs;edkEnd();
                                        delete this->objsPhys;edkEnd();
                                        this->clean();edkEnd();
                                    }
                                }
                                else{
                                    delete this->objsPhys;edkEnd();
                                }
                            }
                        }
                        else if(edk::String::strCompare(temp,"tileMap")){
                            //read the tileMap

                            this->tileMap = new edk::tiles::TileMap2D(tileSet);edkEnd();
                            if(this->tileMap){
                                if(this->tileMap->readFromXML(xml,0u)){
                                    //Set the tileSet and tileMap
                                    this->tileMap->setWorld(world);edkEnd();
                                }
                                else{
                                    delete this->tileMap;edkEnd();
                                    this->clean();edkEnd();
                                }
                            }
                        }
                        delete[] temp;edkEnd();
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
bool edk::Cenario2D::LevelObj::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id,edk::tiles::TileSet2D* tileSet,edk::physics2D::World2D* world){
    if(xml && pack){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Level_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* temp;edkEnd();

                    //delete if have some
                    if(this->haveSome()){
                        //delete the some
                        if(this->objs){
                            //read the objects
                            delete this->objs;edkEnd();
                        }
                        else if(this->objsPhys){
                            //read the objects
                            delete this->objsPhys;edkEnd();
                        }
                        else if(this->tileMap){
                            //read the objects
                            delete this->tileMap;edkEnd();
                        }
                    }

                    //test the string
                    temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                    if(temp){
                        if(edk::String::strCompare(temp,"objs")){
                            //read the objects
                            this->objs = new edk::Cenario2D::TreeObjDepth;edkEnd();
                            if(this->objs){
                                this->quadObjs = new edk::Cenario2D::QuadObjs(this->calls);edkEnd();
                                if(this->quadObjs){
                                    if(!this->objs->readFromXMLFromPack(pack,xml,0u)){
                                        delete this->quadObjs;edkEnd();
                                        delete this->objs;edkEnd();
                                        this->clean();edkEnd();
                                    }
                                }
                                else{
                                    delete this->objs;edkEnd();
                                }
                            }
                        }
                        else if(edk::String::strCompare(temp,"objsPhys")){
                            //read the physics objects
                            this->objsPhys = new edk::Cenario2D::TreePhysObjDepth(world);edkEnd();
                            if(this->objsPhys){
                                this->quadPhysicObjs = new edk::Cenario2D::QuadPhyicObjs(world,this->calls);edkEnd();
                                if(quadPhysicObjs){
                                    if(!this->objsPhys->readFromXMLFromPack(pack,xml,0u,true)){
                                        delete this->quadPhysicObjs;edkEnd();
                                        delete this->objsPhys;edkEnd();
                                        this->clean();edkEnd();
                                    }
                                }
                                else{
                                    delete this->objsPhys;edkEnd();
                                }
                            }
                        }
                        else if(edk::String::strCompare(temp,"tileMap")){
                            //read the tileMap

                            this->tileMap = new edk::tiles::TileMap2D(tileSet);edkEnd();
                            if(this->tileMap){
                                if(this->tileMap->readFromXML(xml,0u)){
                                    //Set the tileSet and tileMap
                                    this->tileMap->setWorld(world);edkEnd();
                                }
                                else{
                                    delete this->tileMap;edkEnd();
                                    this->clean();edkEnd();
                                }
                            }
                        }
                        delete[] temp;edkEnd();
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

//ACTIONS
edk::Cenario2D::ActionObjectZero::ActionObjectZero(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth){
    this->cenario = cenario;edkEnd();
    this->levelPosition = levelPosition;edkEnd();
    this->depth = depth;edkEnd();
}
//write to XML
bool edk::Cenario2D::ActionObjectZero::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write levelPosition
                    xml->addSelectedNextAttribute("levelPosition",this->levelPosition);edkEnd();
                    //write depth
                    xml->addSelectedNextAttribute("depth",this->depth);edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
//read XML
bool edk::Cenario2D::ActionObjectZero::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read levelPosition
                    this->levelPosition = edk::String::strToInt64(xml->getSelectedAttributeValueByName("levelPosition"));edkEnd();
                    //read depth
                    this->depth = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("depth"));edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
edk::uint32 edk::Cenario2D::ActionObjectZero::getLevelPosition(){
    return this->levelPosition;edkEnd();
}
edk::float32 edk::Cenario2D::ActionObjectZero::getDepth(){
    return this->depth;edkEnd();
}
edk::Cenario2D::ActionObjectZeroDuration::ActionObjectZeroDuration(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth,edk::float32 duration)
    :ActionObjectZero(cenario,levelPosition,depth)
{
    this->duration=duration;edkEnd();
}
bool edk::Cenario2D::ActionObjectZeroDuration::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    if(edk::Cenario2D::ActionObjectZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write duration
                    xml->addSelectedNextAttribute("duration",this->duration);edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
//read XML
bool edk::Cenario2D::ActionObjectZeroDuration::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    edk::Cenario2D::ActionObjectZero::readFromXML(xml,id);edkEnd();
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read duration
                    this->duration = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("duration"));edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}

edk::float32 edk::Cenario2D::ActionObjectZeroDuration::getDuration(){
    return this->duration;edkEnd();
}
edk::Cenario2D::ActionObjectSetPosition::ActionObjectSetPosition(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth, edk::vec2f32 position)
    :ActionObjectZero(cenario,levelPosition,depth)
{
    this->position = position;edkEnd();
    this->code = 1u;edkEnd();
}
//run action function
void edk::Cenario2D::ActionObjectSetPosition::runAction(){
    //load the object from the cenario
    edk::Object2D* temp = this->cenario->getObject(this->levelPosition,this->depth);edkEnd();
    if(temp){
        temp->position = this->position;edkEnd();
    }
}
//write to XML
bool edk::Cenario2D::ActionObjectSetPosition::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    if(edk::Cenario2D::ActionObjectZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write position
                    xml->addSelectedNextAttribute("positionX",this->position.x);edkEnd();
                    xml->addSelectedNextAttribute("positionY",this->position.y);edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
//read XML
bool edk::Cenario2D::ActionObjectSetPosition::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    edk::Cenario2D::ActionObjectZero::readFromXML(xml,id);edkEnd();
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read position
                    this->position.x = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionX"));edkEnd();
                    this->position.y = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionY"));edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
//GET
edk::vec2f32 edk::Cenario2D::ActionObjectSetPosition::getPosition(){
    return this->position;edkEnd();
}
edk::Cenario2D::ActionObjectMove::ActionObjectMove(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth,edk::float32 duration, edk::vec2f32 position)
    :ActionObjectZeroDuration(cenario,levelPosition,depth,duration)
{
    this->position=position;edkEnd();
    this->code = 2u;edkEnd();
}
//run action function
void edk::Cenario2D::ActionObjectMove::runAction(){
    edk::Object2D* temp = this->cenario->getObject(this->levelPosition,this->depth);edkEnd();
    if(temp){
        temp->animationPosition.cleanTracks();edkEnd();
        edk::uint32 track = temp->animationPosition.newTrack();edkEnd();
        temp->animationPosition.addFirstInterpolationLine(track,0u,temp->position.x,temp->position.y,this->duration,this->position.x,this->position.y);edkEnd();
        temp->animationPosition.playForwardAllTracks();edkEnd();
        this->cenario->setObjectAnimated(this->levelPosition,this->depth);edkEnd();
    }
}
//write to XML
bool edk::Cenario2D::ActionObjectMove::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    if(edk::Cenario2D::ActionObjectZeroDuration::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write position
                    xml->addSelectedNextAttribute("positionX",this->position.x);edkEnd();
                    xml->addSelectedNextAttribute("positionY",this->position.y);edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
//read XML
bool edk::Cenario2D::ActionObjectMove::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    edk::Cenario2D::ActionObjectZeroDuration::readFromXML(xml,id);edkEnd();
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read position
                    this->position.x = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionX"));edkEnd();
                    this->position.y = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionY"));edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
//GET
edk::vec2f32 edk::Cenario2D::ActionObjectMove::getPosition(){
    return this->position;edkEnd();
}
edk::Cenario2D::ActionObjectSetSize::ActionObjectSetSize(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth, edk::size2f32 size)
    :ActionObjectZero(cenario,levelPosition,depth)
{
    this->size = size;edkEnd();
    this->code = 3u;edkEnd();
}
//run action function
void edk::Cenario2D::ActionObjectSetSize::runAction(){
    //load the object from the cenario
    edk::Object2D* temp = this->cenario->getObject(this->levelPosition,this->depth);edkEnd();
    if(temp){
        temp->size = this->size;edkEnd();
    }
}
//write to XML
bool edk::Cenario2D::ActionObjectSetSize::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    if(edk::Cenario2D::ActionObjectZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write size
                    xml->addSelectedNextAttribute("width",this->size.width);edkEnd();
                    xml->addSelectedNextAttribute("height",this->size.height);edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
//read XML
bool edk::Cenario2D::ActionObjectSetSize::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    edk::Cenario2D::ActionObjectZero::readFromXML(xml,id);edkEnd();
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read size
                    this->size.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("width"));edkEnd();
                    this->size.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("height"));edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
//GET
edk::size2f32 edk::Cenario2D::ActionObjectSetSize::getSize(){
    return this->size;edkEnd();
}
edk::Cenario2D::ActionObjectScale::ActionObjectScale(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth,edk::float32 duration, edk::size2f32 size)
    :ActionObjectZeroDuration(cenario,levelPosition,depth,duration)
{
    this->size = size;edkEnd();
    this->code = 4u;edkEnd();
}
//run action function
void edk::Cenario2D::ActionObjectScale::runAction(){
    edk::Object2D* temp = this->cenario->getObject(this->levelPosition,this->depth);edkEnd();
    if(temp){
        temp->animationSize.cleanAnimations();edkEnd();
        temp->animationSize.addFirstInterpolationLine(0u,temp->size.width,temp->size.height,this->duration,this->size.width,this->size.height);edkEnd();
        temp->animationSize.playForward();edkEnd();
        this->cenario->setObjectAnimated(this->levelPosition,this->depth);edkEnd();
    }
}
//write to XML
bool edk::Cenario2D::ActionObjectScale::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    if(edk::Cenario2D::ActionObjectZeroDuration::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write size
                    xml->addSelectedNextAttribute("width",this->size.width);edkEnd();
                    xml->addSelectedNextAttribute("height",this->size.height);edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
//read XML
bool edk::Cenario2D::ActionObjectScale::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    edk::Cenario2D::ActionObjectZeroDuration::readFromXML(xml,id);edkEnd();
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read size
                    this->size.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("width"));edkEnd();
                    this->size.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("height"));edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
//GET
edk::size2f32 edk::Cenario2D::ActionObjectScale::getSize(){
    return this->size;edkEnd();
}
edk::Cenario2D::ActionObjectSetAngle::ActionObjectSetAngle(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth, edk::float32 angle)
    :ActionObjectZero(cenario,levelPosition,depth)
{
    this->angle=angle;edkEnd();
    this->code = 5u;edkEnd();
}
//run action function
void edk::Cenario2D::ActionObjectSetAngle::runAction(){
    //load the object from the cenario
    edk::Object2D* temp = this->cenario->getObject(this->levelPosition,this->depth);edkEnd();
    if(temp){
        temp->angle = this->angle;edkEnd();
    }
}
//write to XML
bool edk::Cenario2D::ActionObjectSetAngle::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    if(edk::Cenario2D::ActionObjectZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write angle
                    xml->addSelectedNextAttribute("angle",this->angle);edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
//read XML
bool edk::Cenario2D::ActionObjectSetAngle::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    edk::Cenario2D::ActionObjectZero::readFromXML(xml,id);edkEnd();
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read angle
                    this->angle = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("angle"));edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
//GET
edk::float32 edk::Cenario2D::ActionObjectSetAngle::getAngle(){
    return this->angle;edkEnd();
}
edk::Cenario2D::ActionObjectRotate::ActionObjectRotate(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth,edk::float32 duration, edk::float32 angle)
    :ActionObjectZeroDuration(cenario,levelPosition,depth,duration)
{
    this->angle=angle;edkEnd();
    this->code = 6u;edkEnd();
}
//run action function
void edk::Cenario2D::ActionObjectRotate::runAction(){
    edk::Object2D* temp = this->cenario->getObject(this->levelPosition,this->depth);edkEnd();
    if(temp){
        temp->animationRotation.cleanAnimations();edkEnd();
        temp->animationRotation.addFirstInterpolationLine(0u,temp->angle,this->duration,this->angle);edkEnd();
        temp->animationRotation.playForward();edkEnd();
        this->cenario->setObjectAnimated(this->levelPosition,this->depth);edkEnd();
    }
}
//write to XML
bool edk::Cenario2D::ActionObjectRotate::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    if(edk::Cenario2D::ActionObjectZeroDuration::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write angle
                    xml->addSelectedNextAttribute("angle",this->angle);edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
//read XML
bool edk::Cenario2D::ActionObjectRotate::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    edk::Cenario2D::ActionObjectZeroDuration::readFromXML(xml,id);edkEnd();
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read angle
                    this->angle = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("angle"));edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
//return the code
edk::float32 edk::Cenario2D::ActionObjectRotate::getAngle(){
    return this->angle;edkEnd();
}
edk::Cenario2D::ActionObjectMeshName::ActionObjectMeshName(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id, edk::char8* name,bool loop){
    this->cenario = cenario;edkEnd();
    this->levelPosition = levelPosition;edkEnd();
    this->depth=depth;edkEnd();
    this->id = id;edkEnd();
    edk::Name::setName(name);edkEnd();
    this->loop=loop;edkEnd();
    this->code = 7u;edkEnd();
}
//run action function
void edk::Cenario2D::ActionObjectMeshName::runAction(){
    edk::Object2D* temp = this->cenario->getObject(this->levelPosition,this->depth);edkEnd();
    if(temp){
        //load the mesh
        edk::shape::Mesh2D* mesh = temp->getMesh(this->id);edkEnd();
        if(mesh){
            mesh->selectedAnimationSetLoop(this->loop);edkEnd();
            mesh->selectedAnimationPlayNameForward(this->name());edkEnd();
        }
    }
}
//write to XML
bool edk::Cenario2D::ActionObjectMeshName::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    if(edk::ActionName::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    if(this->loop){
                        xml->setSelectedString("loopOn");edkEnd();
                    }
                    else{
                        xml->setSelectedString("loopOff");edkEnd();
                    }

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
//read XML
bool edk::Cenario2D::ActionObjectMeshName::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    edk::ActionName::readFromXML(xml,id);edkEnd();
    this->id = 7u;edkEnd();
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read the code
                    if(edk::String::strCompare("loopOn",xml->getSelectedString())){
                        this->loop=true;edkEnd();
                    }
                    else{
                        this->loop=false;edkEnd();
                    }

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
//GET
edk::uint32 edk::Cenario2D::ActionObjectMeshName::getLevelPosition(){
    return this->levelPosition;edkEnd();
}
edk::float32 edk::Cenario2D::ActionObjectMeshName::getDepth(){
    return this->depth;edkEnd();
}
edk::uint32 edk::Cenario2D::ActionObjectMeshName::getId(){
    return this->id;edkEnd();
}
bool edk::Cenario2D::ActionObjectMeshName::getLoop(){
    return this->loop;edkEnd();
}
edk::Cenario2D::ActionObjectMeshStop::ActionObjectMeshStop(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id)
    :edk::Cenario2D::ActionObjectZero(cenario,levelPosition,depth)
{
    this->id = id;edkEnd();
    this->code = 8u;edkEnd();
}
//run action function
void edk::Cenario2D::ActionObjectMeshStop::runAction(){
    edk::Object2D* temp = this->cenario->getObject(this->levelPosition,this->depth);edkEnd();
    if(temp){
        //load the mesh
        edk::shape::Mesh2D* mesh = temp->getMesh(this->id);edkEnd();
        if(mesh){
            mesh->selectedAnimationStop();edkEnd();
        }
    }
}
//write to XML
bool edk::Cenario2D::ActionObjectMeshStop::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    if(edk::Cenario2D::ActionObjectZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    xml->addSelectedNextAttribute("id",this->id);edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}
//read XML
bool edk::Cenario2D::ActionObjectMeshStop::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    edk::Cenario2D::ActionObjectZero::readFromXML(xml,id);edkEnd();
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read ID
                    this->id = edk::String::strToInt64(xml->getSelectedAttributeValueByName("id"));edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] number;edkEnd();
        }
    }
    return ret;
}

//get levels less position
edk::uint32 edk::Cenario2D::getLevelsLessPosition(){
    //test all the objects
    edk::uint32 size = this->levels.size();edkEnd();
    edk::Cenario2D::LevelObj* temp = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->levels[i];edkEnd();
        if(temp){
            //test if dont have the object
            if(!temp->haveSome()){
                //return i
                return i++;edkEnd();
            }
        }
    }
    //else return the size
    return size+1u;edkEnd();
}
//Add a object to the level
bool edk::Cenario2D::addObjectToLevel(edk::Object2D* obj,edk::Object2D* objPhys,edk::uint32 levelPosition,edk::float64 depth,bool created){
    if(levelPosition){
        levelPosition--;edkEnd();
        //test the object
        if(obj || objPhys){
            //test if dont have the level
            if(!this->levels.havePos(levelPosition)){
                //create the levels
                edk::uint32 newSize = levelPosition - this->levels.size() + 1u;edkEnd();
                //create the levelObjects
                edk::Cenario2D::LevelObj* temp = NULL;edkEnd();
                for(edk::uint32 i=0u;i<newSize;i++){
                    temp = new edk::Cenario2D::LevelObj(&this->calls);edkEnd();
                    if(temp){
                        this->levels.pushBack(temp);edkEnd();
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
                    edk::Cenario2D::LevelObj* temp = this->levels[levelPosition];edkEnd();
                    if(temp){
                        bool canCreate=false;edkEnd();
                        if(temp->haveSome()){
                            if(temp->objs){
                                canCreate=true;edkEnd();
                            }
                        }
                        else{
                            //else create a new objs tree
                            temp->objs = new edk::Cenario2D::TreeObjDepth;edkEnd();
                            if(temp->objs){
                                temp->quadObjs = new edk::Cenario2D::QuadObjs(&this->calls);edkEnd();
                                if(temp->quadObjs){
                                    canCreate=true;edkEnd();
                                }
                                else{
                                    delete temp->objs;edkEnd();
                                    temp->objs=NULL;edkEnd();
                                }
                            }
                        }
                        if(canCreate){
                            //add the object
                            if(temp->objs->addObject(created,obj,depth)){
                                //add the object into the quad
                                edk::Cenario2D::ObjClass* tempClass = temp->objs->getObjectClassFromObject(obj);edkEnd();
                                temp->quadObjs->add(tempClass);edkEnd();
                                //return true
                                return true;
                            }
                            else{
                                //else delete the tree if it's clear
                                if(!temp->objs->size()){
                                    delete temp->objs;edkEnd();
                                    temp->clean();edkEnd();
                                }
                            }
                        }
                    }
                }

                else if(objPhys){
                    //load the level
                    edk::Cenario2D::LevelObj* temp = this->levels[levelPosition];edkEnd();
                    if(temp){
                        bool canCreate=false;edkEnd();
                        if(temp->haveSome()){
                            if(temp->objsPhys){
                                canCreate=true;edkEnd();
                            }
                        }
                        else{
                            //else create a new objs tree
                            temp->objsPhys = new edk::Cenario2D::TreePhysObjDepth(&this->world);edkEnd();
                            if(temp->objsPhys){
                                temp->quadPhysicObjs = new edk::Cenario2D::QuadPhyicObjs(&this->world,&this->calls);edkEnd();
                                if(temp->quadPhysicObjs){
                                    canCreate=true;edkEnd();
                                }
                                else{
                                    delete temp->objsPhys;edkEnd();
                                    temp->objsPhys=NULL;edkEnd();
                                }
                            }
                        }
                        if(canCreate){
                            //add the object
                            if(temp->objsPhys->addObject(created,objPhys,depth)){
                                //add the object into the quad
                                edk::Cenario2D::ObjClass* tempClass = temp->objsPhys->getObjectClassFromObject(obj);edkEnd();
                                if(temp){
                                    temp->quadPhysicObjs->add(tempClass);edkEnd();
                                }
                                //return true
                                return true;
                            }
                            else{
                                //else delete the tree if it's clear
                                if(!temp->objsPhys->size()){
                                    delete temp->objsPhys;edkEnd();
                                    temp->clean();edkEnd();
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
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            //load the level
            edk::Cenario2D::LevelObj* temp = this->levels[levelPosition];edkEnd();
            if(temp){
                if(temp->haveSome()){
                    if(temp->objs){
                        return temp->objs->getLastLevel();edkEnd();
                    }
                    if(temp->objsPhys){
                        return temp->objsPhys->getLastLevel();edkEnd();
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
        edk::uint32 levelSize = this->levels.size();edkEnd();
        edk::Cenario2D::LevelObj* levelObj;edkEnd();
        edk::Cenario2D::ObjClass* physObj;edkEnd();
        for(edk::uint32 i=0u;i<levelSize;i++){
            *level=i;edkEnd();
            levelObj = this->levels[i];edkEnd();
            if(levelObj){
                if(levelObj->objsPhys){
                    //find the object
                    edk::uint32 objSize = levelObj->objsPhys->size();edkEnd();
                    for(edk::uint32 j=0u;j<objSize;j++){
                        //test the object
                        physObj = levelObj->objsPhys->getElementInPosition(j);edkEnd();
                        if(physObj){
                            if(obj == physObj->getObject()){
                                *depth = physObj->depth;edkEnd();
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
        bool ret=false;edkEnd();
        edk::char8* name = NULL;edkEnd();
        if(id){
            name = (edk::char8*)"objectA";edkEnd();
        }
        else{
            name = (edk::char8*)"objectB";edkEnd();
        }
        //create the name
        if(xml->addSelectedNextChild(name)){
            if(xml->selectChild(name)){
                ret=true;edkEnd();
                edk::char8* temp = NULL;edkEnd();

                //write the level type
                switch(this->levelID){
                case EDK_LEVEL_OBJ_PHYSICS:
                    //write the string
                    xml->setSelectedString("OBJ_PHYSICS");edkEnd();
                    //write the level
                    temp = edk::String::uint32ToStr(this->level);edkEnd();
                    if(temp){
                        xml->addSelectedNextAttribute((edk::char8*)"level",temp);edkEnd();
                        delete[] temp;edkEnd();
                    }
                    temp = edk::String::float32ToStr(this->depth);edkEnd();
                    if(temp){
                        xml->addSelectedNextAttribute((edk::char8*)"depth",temp);edkEnd();
                        delete[] temp;edkEnd();
                    }
                    break;edkEnd();
                case EDK_LEVEL_TILE_MAP:
                    xml->setSelectedString("TILE_MAP");edkEnd();
                    //write the level
                    temp = edk::String::uint32ToStr(this->level);edkEnd();
                    if(temp){
                        xml->addSelectedNextAttribute((edk::char8*)"level",temp);edkEnd();
                        delete[] temp;edkEnd();
                    }
                    temp = edk::String::uint32ToStr(this->mapPosition.x);edkEnd();
                    if(temp){
                        xml->addSelectedNextAttribute((edk::char8*)"mapX",temp);edkEnd();
                        delete[] temp;edkEnd();
                    }
                    temp = edk::String::uint32ToStr(this->mapPosition.y);edkEnd();
                    if(temp){
                        xml->addSelectedNextAttribute((edk::char8*)"mapY",temp);edkEnd();
                        delete[] temp;edkEnd();
                    }
                    //
                    break;edkEnd();
                case EDK_LEVEL_NOTHING:
                default:
                    ret=false;edkEnd();
                }
                xml->selectFather();edkEnd();
            }
        }
        return ret;
    }
    return false;
}
bool edk::Cenario2D::PhysicsPosition::readFromXML(edk::XML* xml,bool id){
    if(xml){
        bool ret=false;edkEnd();
        edk::char8* name = NULL;edkEnd();
        if(id){
            name = (edk::char8*)"objectA";edkEnd();
        }
        else{
            name = (edk::char8*)"objectB";edkEnd();
        }
        //create the name
        if(xml->selectChild(name)){
            edk::char8 filter[3u] = {9u,'\n',0u};
            edk::char8* temp;edkEnd();
            ret=true;edkEnd();
            //Test the levetID
            temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
            if(temp){
                if(edk::String::strCompare((edk::char8*)"OBJ_PHYSICS",temp)){
                    //
                    this->levelID = EDK_LEVEL_OBJ_PHYSICS;edkEnd();
                    //read the level
                    this->level = edk::String::strToInt64(xml->getSelectedAttributeValueByName("level"));edkEnd();
                    //read depth
                    this->depth = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("depth"));edkEnd();
                }
                else if(edk::String::strCompare((edk::char8*)"TILE_MAP",temp)){
                    //
                    this->levelID = EDK_LEVEL_TILE_MAP;edkEnd();
                    //read the level
                    this->level = edk::String::strToInt64(xml->getSelectedAttributeValueByName("level"));edkEnd();
                    //read the tileMap position
                    this->mapPosition = edk::vec2ui32((edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("mapX")),
                                                      (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("mapY"))
                                                      );edkEnd();
                }
                else{
                    this->levelID = EDK_LEVEL_NOTHING;edkEnd();
                    ret=false;edkEnd();
                }
                delete[] temp;edkEnd();
            }
            xml->selectFather();edkEnd();
        }
        return ret;
    }
    return false;
}
bool edk::Cenario2D::getPhysicsLevelObject(edk::Object2D* obj,edk::Cenario2D::PhysicsPosition* objLevel){
    if(obj && objLevel){
        //find the object in levels
        edk::uint32 levelSize = this->levels.size();edkEnd();
        edk::Cenario2D::LevelObj* levelObj;edkEnd();
        edk::Cenario2D::ObjClass* physObj;edkEnd();
        edk::physics2D::PhysicObject2D* physicObject = (edk::physics2D::PhysicObject2D*)obj;edkEnd();
        for(edk::uint32 i=0u;i<levelSize;i++){
            objLevel->level = i;edkEnd();
            levelObj = this->levels[i];edkEnd();
            if(levelObj){
                if(levelObj->objsPhys){
                    //find the object
                    edk::uint32 objSize = levelObj->objsPhys->size();edkEnd();
                    for(edk::uint32 j=0u;j<objSize;j++){
                        //test the object
                        physObj = levelObj->objsPhys->getElementInPosition(j);edkEnd();
                        if(physObj){
                            if(obj == physObj->getObject()){
                                objLevel->depth = physObj->depth;edkEnd();
                                objLevel->levelID = EDK_LEVEL_OBJ_PHYSICS;edkEnd();
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
                        objLevel->mapPosition = levelObj->tileMap->getPhysicObjectPosition(physicObject);edkEnd();
                        objLevel->levelID = EDK_LEVEL_TILE_MAP;edkEnd();
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
        edk::Cenario2D::LevelObj* level = this->levels[objLevel.level];edkEnd();
        if(level){
            //test the ID
            switch(objLevel.levelID){
            case EDK_LEVEL_OBJ_PHYSICS:
                //test the level
                if(level->objsPhys){
                    //get the object
                    return (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectFromDepth(objLevel.depth);edkEnd();
                }
                break;edkEnd();
            case EDK_LEVEL_TILE_MAP:
                //test the level
                if(level->tileMap){
                    //get the object
                    return level->tileMap->getPhysicTile(objLevel.mapPosition);edkEnd();
                }
                break;edkEnd();
            }
        }
    }
    return NULL;edkEnd();
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
        position--;edkEnd();
        //test if dont have the position
        if(!this->levels.havePos(position)){
            edk::uint32 newSize = position - this->levels.size() + 1u;edkEnd();
            //create the levelObjects
            edk::Cenario2D::LevelObj* temp = NULL;edkEnd();
            for(edk::uint32 i=0u;i<newSize;i++){
                temp = new edk::Cenario2D::LevelObj(&this->calls);edkEnd();
                if(temp){
                    this->levels.pushBack(temp);edkEnd();
                }
                else{
                    return NULL;edkEnd();
                }
            }
        }

        //Now test if have the position
        if(this->levels.havePos(position)){
            edk::Cenario2D::LevelObj* temp = this->levels[position];edkEnd();
            if(temp){
                bool canCreate=false;edkEnd();
                if(temp->haveSome()){
                    if(temp->tileMap){
                        //delete tileMap
                        delete temp->tileMap;edkEnd();
                        temp->clean();edkEnd();
                        canCreate=true;edkEnd();
                    }
                }
                else{
                    canCreate=true;edkEnd();
                }
                if(canCreate){
                    temp->tileMap = new edk::tiles::TileMap2D(&this->tileSet);edkEnd();
                    if(temp->tileMap){
                        if(temp->tileMap->newTileMap(size)){
                            //Set the tileSet and tileMap
                            temp->tileMap->setTileSet(&this->tileSet);edkEnd();
                            temp->tileMap->setWorld(&this->world);edkEnd();
                            return temp->tileMap;edkEnd();
                        }
                        delete temp->tileMap;edkEnd();
                        temp->clean();edkEnd();
                    }
                }
            }
        }
    }
    return NULL;edkEnd();
}
edk::tiles::TileMap2D* edk::Cenario2D::newTileMapInPosition(edk::uint32 position,edk::uint32 width,edk::uint32 height){
    //
    return newTileMapInPosition(position,edk::size2ui32(width,height));edkEnd();
}
edk::uint32 edk::Cenario2D::newTileMap(edk::size2ui32 size){
    edk::uint32 position = this->getLevelsLessPosition();edkEnd();
    if(this->newTileMapInPosition(position,size)){
        //return the position
        return position;edkEnd();
    }
    return 0u;edkEnd();
}
edk::uint32 edk::Cenario2D::newTileMap(edk::uint32 width,edk::uint32 height){
    return this->newTileMap(edk::size2ui32(width,height));edkEnd();
}
edk::uint32 edk::Cenario2D::getTileMapID(edk::tiles::TileMap2D* tileMap){
    if(tileMap){
        edk::uint32 size = this->levels.size();edkEnd();
        edk::Cenario2D::LevelObj* temp = NULL;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->levels[i];edkEnd();
            if(temp){
                if(temp->tileMap == tileMap){
                    return i++;edkEnd();
                }
            }
        }
    }
    return 0u;edkEnd();
}
edk::tiles::TileMap2D* edk::Cenario2D::getTileMap(edk::uint32 position){
    //test the position
    if(position){
        position--;edkEnd();
        //test if the position is inside the stack
        if(this->levels.havePos(position)){
            edk::Cenario2D::LevelObj* temp = this->levels[position];edkEnd();
            if(temp){
                if(temp->tileMap){
                    return temp->tileMap;edkEnd();
                }
            }
        }
    }
    return NULL;edkEnd();
}
bool edk::Cenario2D::deleteTileMap(edk::tiles::TileMap2D* tileMap){
    return this->deleteTileMap(this->getTileMapID(tileMap));edkEnd();
}
bool edk::Cenario2D::deleteTileMap(edk::uint32 position){
    //test the position
    if(position){
        position--;edkEnd();
        //test if the position is inside the stack
        if(this->levels.havePos(position)){
            edk::Cenario2D::LevelObj* temp = this->levels[position];edkEnd();
            if(temp){
                if(temp->tileMap){
                    delete temp->tileMap;edkEnd();
                    temp->clean();edkEnd();
                    return true;
                }
            }
        }
    }
    return false;
}
void edk::Cenario2D::deleteAllTileMaps(){
    edk::uint32 size = this->levels.size();edkEnd();
    edk::Cenario2D::LevelObj* temp = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->levels[i];edkEnd();
        if(temp){
            if(temp->tileMap){
                delete temp->tileMap;edkEnd();
                temp->clean();edkEnd();
            }
        }
    }
}

//tileMapFunctions
void edk::Cenario2D::cleanSelectedTileMap(){
    this->mapSelected=NULL;edkEnd();
}
//select the map
bool edk::Cenario2D::selectTileMap(edk::uint32 position){
    this->mapSelected = this->getTileMap(position);edkEnd();
    if(this->mapSelected){ return true;}
    return false;
}
//set a tile in the tileMap
bool edk::Cenario2D::selectedTileMapSetTile(edk::uint32 tileID,edk::vec2ui32 position){
    if(this->mapSelected){
        //
        return this->mapSelected->setTile(tileID,position);edkEnd();
    }
    return false;
}
bool edk::Cenario2D::selectedTileMapSetTile(edk::uint32 tileID,edk::uint32 positionX,edk::uint32 positionY){
    if(this->mapSelected){
        //
        return this->mapSelected->setTile(tileID,positionX,positionY);edkEnd();
    }
    return false;
}
//set the tileMap position
bool  edk::Cenario2D::selectedTileMapSetPosition(edk::vec2f32 position){
    if(this->mapSelected){
        //
        this->mapSelected->setPosition(position);edkEnd();
        return true;
    }
    return false;
}
bool  edk::Cenario2D::selectedTileMapSetPosition(edk::float32 positionX,edk::float32 positionY){
    if(this->mapSelected){
        //
        this->mapSelected->setPosition(positionX,positionY);edkEnd();
        return true;
    }
    return false;
}
edk::vec2f32 edk::Cenario2D::selectedTileMapGetTileWorldPosition(edk::vec2ui32 position){
    if(this->mapSelected){
        //
        return this->mapSelected->getTileWorldPosition(position);edkEnd();
    }
    return edk::vec2f32();edkEnd();
}
edk::vec2f32 edk::Cenario2D::selectedTileMapGetTileWorldPosition(edk::uint32 positionX,edk::uint32 positionY){
    if(this->mapSelected){
        //
        return this->mapSelected->getTileWorldPosition(positionX,positionY);edkEnd();
    }
    return edk::vec2f32();edkEnd();
}
//Set scale the map
bool edk::Cenario2D::selectedTileMapSetScaleMap(edk::size2f32 scale){
    if(this->mapSelected){
        //
        return this->mapSelected->setScaleMap(scale);edkEnd();
    }
    return false;
}
bool edk::Cenario2D::selectedTileMapSetScaleMap(edk::float32 width,edk::float32 height ){
    if(this->mapSelected){
        //
        return this->mapSelected->setScaleMap(width,height);edkEnd();
    }
    return false;
}
//delete physicObjects
bool  edk::Cenario2D::selectedTileDeletePhysicsTiles(){
    if(this->mapSelected){
        //
        this->mapSelected->deletePhysicsTiles();edkEnd();
        return true;
    }
    return false;
}
bool edk::Cenario2D::selectedTileDeletePhysicTile(edk::vec2ui32 position){
    if(this->mapSelected){
        //
        return this->mapSelected->deletePhysicTile(position);edkEnd();
    }
    return false;
}
bool edk::Cenario2D::selectedTileDeletePhysicTile(edk::uint32 positionX,edk::uint32 positionY){
    if(this->mapSelected){
        //
        return this->mapSelected->deletePhysicTile(positionX,positionY);edkEnd();
    }
    return false;
}
//add physics tiles
bool edk::Cenario2D::selectedTileLoadPhysicsTiles(){
    if(this->mapSelected){
        //
        return this->mapSelected->loadPhysicsTiles();edkEnd();
    }
    return false;
}
bool edk::Cenario2D::selectedTileLoadPhysicTile(edk::vec2ui32 position){
    if(this->mapSelected){
        //
        this->mapSelected->loadPhysicTile(position);edkEnd();
        return true;
    }
    return false;
}
bool edk::Cenario2D::selectedTileLoadPhysicTile(edk::uint32 positionX,edk::uint32 positionY){
    if(this->mapSelected){
        //
        this->mapSelected->loadPhysicTile(positionX,positionY);edkEnd();
        return true;
    }
    return false;
}

//OBJECTS
//add a object to the tree
edk::Object2D* edk::Cenario2D::newObject(edk::uint32 levelPosition){
    return this->newObject(levelPosition,this->getHigherLevel(levelPosition) + 1.0);edkEnd();
}
edk::Object2D* edk::Cenario2D::newObject(edk::uint32 levelPosition,edk::float32 depth){
    if(levelPosition){
        edk::Object2D* obj = new edk::Object2D;edkEnd();
        if(obj){
            if(this->addObjectToLevel(obj,NULL,levelPosition,depth,true)){
                return obj;edkEnd();
            }
            delete obj;edkEnd();
        }
    }
    return NULL;edkEnd();
}
bool edk::Cenario2D::addObject(edk::uint32 levelPosition,edk::Object2D* obj){
    //test the object
    return this->addObject(levelPosition,obj,this->getHigherLevel(levelPosition)+1.0);edkEnd();
}
bool edk::Cenario2D::addObject(edk::uint32 levelPosition,edk::Object2D* obj,edk::float32 depth){
    //test the object
    if(levelPosition){
        if(obj){
            return this->addObjectToLevel(obj,NULL,levelPosition,depth,false);edkEnd();
        }
    }
    return false;
}
bool edk::Cenario2D::addObjectCreated(edk::uint32 levelPosition,edk::Object2D* obj){
    //test the object
    return this->addObjectCreated(levelPosition,obj,this->getHigherLevel(levelPosition)+1.0);edkEnd();
}
bool edk::Cenario2D::addObjectCreated(edk::uint32 levelPosition,edk::Object2D* obj,edk::float32 depth){
    //test the object
    if(levelPosition){
        if(obj){
            return this->addObjectToLevel(obj,NULL,levelPosition,depth,true);edkEnd();
        }
    }
    return false;
}
//get the object
edk::Object2D* edk::Cenario2D::getObject(edk::uint32 levelPosition,edk::float32 depth){
    //test if have the position
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
            if(level){
                if(level->objs){
                    return level->objs->getObjectFromDepth(depth);edkEnd();
                }
            }
        }
    }
    return NULL;edkEnd();
}
edk::Object2D* edk::Cenario2D::getObjectInPosition(edk::uint32 levelPosition,edk::uint32 position){
    //test if have the position
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
            if(level){
                if(level->objs){
                    return level->objs->getObjectInPosition(position);edkEnd();
                }
            }
        }
    }
    return NULL;edkEnd();
}
//get the objectDepth
edk::float32 edk::Cenario2D::getObjectDepth(edk::uint32 levelPosition,edk::uint32 position){
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level = this->levels[levelPosition];edkEnd();
            if(level){
                if(level->objs){
                    return level->objs->getObjectDepthInPosition(position);edkEnd();
                }
            }
        }
    }
    return 0.f;edkEnd();
}
edk::float32 edk::Cenario2D::getObjectDepth(edk::uint32 levelPosition,edk::Object2D* obj){
    if(obj){
        //load the level
        if(levelPosition){
            levelPosition--;edkEnd();
            if(this->levels.havePos(levelPosition)){
                edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
                if(level){
                    if(level->objs){
                        return level->objs->getObjectDepth(obj);edkEnd();
                    }
                }
            }
        }
    }
    return 0.f;edkEnd();
}

//delete the object
bool edk::Cenario2D::deleteObject(edk::uint32 levelPosition,edk::Object2D* obj){
    if(obj){
        //load the level
        if(levelPosition){
            levelPosition--;edkEnd();
            if(this->levels.havePos(levelPosition)){
                edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
                if(level){
                    //remove object from tree
                    this->treeAnim.remove(obj);edkEnd();
                    if(level->objs){
                        bool ret = level->objs->deleteObj(obj);edkEnd();
                        if(!level->objs->size()){
                            delete level->objs;edkEnd();
                            level->clean();edkEnd();
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
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
            if(level){
                if(level->objs){
                    if(level->quadObjs){
                        delete level->quadObjs;edkEnd();
                    }
                    edk::uint32 size = level->objs->size();edkEnd();
                    for(edk::uint32 i=0u;i<size;i++){
                        this->treeAnim.remove(level->objs->getObjectInPosition(0u));edkEnd();
                        level->objs->deleteObjInPosition(0u);edkEnd();
                    }
                    delete level->objs;edkEnd();
                    level->clean();edkEnd();
                }
            }
        }
    }
}
void edk::Cenario2D::deleteAllObjects(){
    edk::uint32 size = this->levels.size();edkEnd();
    edk::Cenario2D::LevelObj* level = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        level = this->levels[i];edkEnd();
        if(level){
            if(level->objs){
                this->deleteAllObjects(i+1u);edkEnd();
                level->clean();edkEnd();
            }
        }
    }
}
//dont delete the object
bool edk::Cenario2D::removeObject(edk::uint32 levelPosition,edk::Object2D* obj){
    if(obj){
        //load the level
        if(levelPosition){
            levelPosition--;edkEnd();
            if(this->levels.havePos(levelPosition)){
                edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
                if(level){
                    //remove object from tree
                    this->treeAnim.remove(obj);edkEnd();
                    if(level->objs){
                        edk::Cenario2D::ObjClass* temp = level->objs->getObjectClassFromObject(obj);edkEnd();
                        if(temp){
                            level->quadObjs->remove(temp);edkEnd();
                            bool ret = level->objs->remove(temp);edkEnd();
                            if(!level->objs->size()){
                                if(level->quadObjs){
                                    delete level->quadObjs;edkEnd();
                                }
                                delete level->objs;edkEnd();
                                level->clean();edkEnd();
                            }
                            return ret;
                        }
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
        levelPosition--;edkEnd();
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels[levelPosition];edkEnd();
        if(level){
            //test if have objects
            if(level->objs){
                //load the object
                edk::Object2D* temp = level->objs->getObject(obj);edkEnd();
                if(temp){
                    //add the object to the animation tree
                    if(this->treeAnim.haveElement(temp)){
                        return true;
                    }
                    else{
                        return this->treeAnim.add(temp);edkEnd();
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
        levelPosition--;edkEnd();
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels[levelPosition];edkEnd();
        if(level){
            //test if have objects
            if(level->objs){
                //load the object
                edk::Object2D* temp = level->objs->getObjectInPosition(position);edkEnd();
                if(temp){
                    //add the object to the animation tree
                    if(this->treeAnim.haveElement(temp)){
                        return true;
                    }
                    else{
                        return this->treeAnim.add(temp);edkEnd();
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
        levelPosition--;edkEnd();
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels[levelPosition];edkEnd();
        if(level){
            //test if have objects
            if(level->objs){
                //load the object
                edk::Object2D* temp = level->objs->getObjectFromDepth(depth);edkEnd();
                if(temp){
                    //add the object to the animation tree
                    if(this->treeAnim.haveElement(temp)){
                        return true;
                    }
                    else{
                        return this->treeAnim.add(temp);edkEnd();
                    }
                }
            }
        }
    }
    return false;
}
//remove object from be animated
bool edk::Cenario2D::removeObjectAnimated(edk::uint32 levelPosition,edk::Object2D* obj){
    //test the level position
    if(levelPosition){
        levelPosition--;edkEnd();
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels[levelPosition];edkEnd();
        if(level){
            //test if have objects
            if(level->objs){
                //load the object
                edk::Object2D* temp = level->objs->getObject(obj);edkEnd();
                if(temp){
                    //add the object to the animation tree
                    if(this->treeAnim.haveElement(temp)){
                        return this->treeAnim.remove(temp);edkEnd();
                    }
                }
            }
        }
    }
    return false;
}
bool edk::Cenario2D::removeObjectAnimated(edk::uint32 levelPosition,edk::uint32 position){
    //test the level position
    if(levelPosition){
        levelPosition--;edkEnd();
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels[levelPosition];edkEnd();
        if(level){
            //test if have objects
            if(level->objs){
                //load the object
                edk::Object2D* temp = level->objs->getObjectInPosition(position);edkEnd();
                if(temp){
                    //add the object to the animation tree
                    if(this->treeAnim.haveElement(temp)){
                        return this->treeAnim.remove(temp);edkEnd();
                    }
                }
            }
        }
    }
    return false;
}
bool edk::Cenario2D::removeObjectAnimated(edk::uint32 levelPosition,edk::float32 depth){
    //test the level position
    if(levelPosition){
        levelPosition--;edkEnd();
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels[levelPosition];edkEnd();
        if(level){
            //test if have objects
            if(level->objs){
                //load the object
                edk::Object2D* temp = level->objs->getObjectFromDepth(depth);edkEnd();
                if(temp){
                    //add the object to the animation tree
                    if(this->treeAnim.haveElement(temp)){
                        return this->treeAnim.remove(temp);edkEnd();
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
    return this->newPhysicObject(levelPosition,physicType,this->getHigherLevel(levelPosition) + 1.0);edkEnd();
}
edk::physics2D::PhysicObject2D* edk::Cenario2D::newPhysicObject(edk::uint32 levelPosition,edk::physics::bodyType physicType,edk::float32 depth){
    if(levelPosition){
        edk::physics2D::PhysicObject2D* obj = NULL;edkEnd();
        switch(physicType){
        case edk::physics::StaticBody:
            obj = new edk::physics2D::StaticObject2D;edkEnd();
            break;edkEnd();
        case edk::physics::KinematicBody:
            obj = new edk::physics2D::KinematicObject2D;edkEnd();
            break;edkEnd();
        case edk::physics::DynamicBody:
            obj = new edk::physics2D::DynamicObject2D;edkEnd();
            break;edkEnd();
        }
        if(obj){
            if(this->addObjectToLevel(NULL,(edk::Object2D*)obj,levelPosition,depth,true)){
                return obj;edkEnd();
            }
            delete obj;edkEnd();
        }
    }
    return NULL;edkEnd();
}
edk::physics2D::PhysicObject2D* edk::Cenario2D::newPhysicSensor(edk::uint32 levelPosition,edk::physics::bodyType physicType){
    return this->newPhysicSensor(levelPosition,physicType,this->getHigherLevel(levelPosition) + 1.0);edkEnd();
}
edk::physics2D::PhysicObject2D* edk::Cenario2D::newPhysicSensor(edk::uint32 levelPosition,edk::physics::bodyType physicType,edk::float32 depth){
    if(levelPosition){
        edk::physics2D::PhysicObject2D* obj = NULL;edkEnd();
        switch(physicType){
        case edk::physics::StaticBody:
            obj = new edk::physics2D::StaticSensor2D;edkEnd();
            break;edkEnd();
        case edk::physics::DynamicBody:
        case edk::physics::KinematicBody:
            obj = new edk::physics2D::KinematicSensor2D;edkEnd();
            break;edkEnd();
        }
        if(obj){
            if(this->addObjectToLevel(NULL,(edk::Object2D*)obj,levelPosition,depth,true)){
                return obj;edkEnd();
            }
            delete obj;edkEnd();
        }
    }
    return NULL;edkEnd();
}
bool edk::Cenario2D::addPhysicObject(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj){
    return this->addPhysicObject(levelPosition,obj,this->getHigherLevel(levelPosition) + 1.0);edkEnd();
}
bool edk::Cenario2D::addPhysicObject(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj,edk::float32 depth){
    if(obj){
        return this->addObjectToLevel(NULL,(edk::Object2D*)obj,levelPosition,depth,false);edkEnd();
    }
    return false;
}
bool edk::Cenario2D::addPhysicObjectCreated(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj){
    return this->addPhysicObjectCreated(levelPosition,obj,this->getHigherLevel(levelPosition) + 1.0);edkEnd();
}
bool edk::Cenario2D::addPhysicObjectCreated(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj,edk::float32 depth){
    if(obj){
        return this->addObjectToLevel(NULL,(edk::Object2D*)obj,levelPosition,depth,true);edkEnd();
    }
    return false;
}
bool edk::Cenario2D::addPhysicSensor(edk::uint32 levelPosition,edk::physics2D::StaticSensor2D* sensor){
    return this->addPhysicObject(levelPosition,sensor);edkEnd();
}
bool edk::Cenario2D::addPhysicSensor(edk::uint32 levelPosition,edk::physics2D::StaticSensor2D* sensor,edk::float32 depth){
    return this->addPhysicObject(levelPosition,sensor,depth);edkEnd();
}
bool edk::Cenario2D::addPhysicSensorCreated(edk::uint32 levelPosition,edk::physics2D::StaticSensor2D* sensor){
    return this->addPhysicObjectCreated(levelPosition,sensor);edkEnd();
}
bool edk::Cenario2D::addPhysicSensorCreated(edk::uint32 levelPosition,edk::physics2D::StaticSensor2D* sensor,edk::float32 depth){
    return this->addPhysicObjectCreated(levelPosition,sensor,depth);edkEnd();
}
//get the object
edk::physics2D::PhysicObject2D* edk::Cenario2D::getPhysicObject(edk::uint32 levelPosition,edk::float32 depth){
    if(levelPosition){
        levelPosition--;edkEnd();
        //test if have the position
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
            if(level){
                if(level->objsPhys){
                    return (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectFromDepth(depth);edkEnd();
                }
            }
        }
    }
    return NULL;edkEnd();
}
edk::physics2D::PhysicObject2D* edk::Cenario2D::getPhysicObjectInPosition(edk::uint32 levelPosition,edk::uint32 position){
    if(levelPosition){
        levelPosition--;edkEnd();
        //test if have the position
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
            if(level){
                if(level->objsPhys){
                    return (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(position);edkEnd();
                }
            }
        }
    }
    return NULL;edkEnd();
}
//return the depth of the physic object
edk::float32 edk::Cenario2D::getPhysicObjectDepth(edk::uint32 levelPosition,edk::uint32 position){
    if(levelPosition){
        levelPosition--;edkEnd();
        //test if have the position
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
            if(level){
                if(level->objsPhys){
                    return level->objsPhys->getObjectDepthInPosition(position);edkEnd();
                }
            }
        }
    }
    return 0.f;edkEnd();
}
edk::float32 edk::Cenario2D::getPhysicObjectDepth(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj){
    if(levelPosition){
        levelPosition--;edkEnd();
        //test if have the position
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
            if(level){
                if(level->objsPhys){
                    return level->objsPhys->getObjectDepth(obj);edkEnd();
                }
            }
        }
    }
    return 0.f;edkEnd();
}

//load the physicsObjects
bool edk::Cenario2D::loadPhysicObjectToWorld(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj){
    if(levelPosition){
        levelPosition--;edkEnd();
        //test if have the level
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level = this->levels[levelPosition];edkEnd();
            if(level){
                if(level->objsPhys){
                    if(level->objsPhys->haveObject((edk::Object2D*)obj)){
                        //add the object to the world
                        return this->world.addObject(obj);edkEnd();
                    }
                }
            }
        }
    }
    return false;
}
bool edk::Cenario2D::loadPhysicObjectsToWorld(edk::uint32 levelPosition){
    if(levelPosition){
        levelPosition--;edkEnd();
        //test if have the level
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level = this->levels[levelPosition];edkEnd();
            if(level){
                if(level->objsPhys){
                    edk::uint32 size = level->objsPhys->size();edkEnd();
                    edk::physics2D::PhysicObject2D* temp = NULL;edkEnd();
                    for(edk::uint32 i=0u;i<size;i++){
                        temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(i);edkEnd();
                        this->world.removeObject(temp);edkEnd();
                        this->world.addObject(temp);edkEnd();
                    }
                    return true;
                }
                else if(level->tileMap){
                    bool ret = false;edkEnd();
                    if(level->tileMap->loadPhysicsTilesStaticMerged()){
                        ret=true;edkEnd();
                    }
                    if(level->tileMap->loadPhysicsTilesKinematicAndDynamic()){
                        ret=true;edkEnd();
                    }
                    return ret;
                }
            }
        }
    }
    return false;
}
bool edk::Cenario2D::loadPhysicObjectsToWorld(){
    bool ret = false;edkEnd();
    edk::uint32 size = this->levels.size();edkEnd();
    edk::Cenario2D::LevelObj* level=NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        level = this->levels[i];edkEnd();
        if(level){
            if(level->objsPhys){
                edk::uint32 size = level->objsPhys->size();edkEnd();
                edk::physics2D::PhysicObject2D* temp = NULL;edkEnd();
                for(edk::uint32 j=0u;j<size;j++){
                    temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(j);edkEnd();
                    this->world.removeObject(temp);edkEnd();
                    this->world.addObject(temp);edkEnd();
                }
                ret = true;edkEnd();
            }
            else if(level->tileMap){
                level->tileMap->loadPhysicsTilesStaticMerged();edkEnd();
                level->tileMap->loadPhysicsTilesKinematicAndDynamic();edkEnd();
            }
        }
    }
    return ret;
}
//unload the physicsObjects from the world
bool edk::Cenario2D::unloadPhysicObjectFromWorld(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj){
    if(levelPosition){
        levelPosition--;edkEnd();
        //load the level
        if(obj){
            if(this->levels.havePos(levelPosition)){
                edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
                if(level){
                    if(level->objsPhys){
                        this->treeAnimPhys.remove(obj);edkEnd();
                        //remove from world
                        this->world.removeObject(obj);edkEnd();
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool edk::Cenario2D::unloadPhysicObjectsFromWorld(edk::uint32 levelPosition){
    if(levelPosition){
        levelPosition--;edkEnd();
        //load the level
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
            if(level){
                if(level->objsPhys){
                    edk::uint32 size = level->objsPhys->size();edkEnd();
                    for(edk::uint32 i=0u;i<size;i++){
                        this->treeAnimPhys.remove((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(i));edkEnd();
                        //remove from worlf
                        this->world.removeObject((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(i));edkEnd();
                    }
                }
            }
        }
    }
}
bool edk::Cenario2D::unloadPhysicObjectsFromWorld(){
    edk::uint32 size = this->levels.size();edkEnd();
    edk::Cenario2D::LevelObj* level = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        level = this->levels[i];edkEnd();
        if(level){
            if(level->objsPhys){
                //remove the objPhys from world
                edk::uint32 sizePhys = level->objsPhys->size();edkEnd();
                for(edk::uint32 j=0u;j<sizePhys;j++){
                    this->world.removeObject((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(j));edkEnd();
                }
            }
        }
    }
}

//delete the object
bool edk::Cenario2D::deletePhysicObject(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj){
    if(levelPosition){
        levelPosition--;edkEnd();
        //load the level
        if(obj){
            if(this->levels.havePos(levelPosition)){
                edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
                if(level){
                    if(level->objsPhys){
                        this->treeAnimPhys.remove(obj);edkEnd();
                        //remove from world
                        this->world.removeObject(obj);edkEnd();
                        bool ret = level->objsPhys->deleteObj((edk::Object2D*)obj);edkEnd();
                        if(!level->objsPhys->size()){
                            //remove from world
                            delete level->objsPhys;edkEnd();
                            if(level->quadPhysicObjs){
                                delete level->quadPhysicObjs;edkEnd();
                            }
                            level->clean();edkEnd();
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
        levelPosition--;edkEnd();
        //load the level
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
            if(level){
                if(level->objsPhys){
                    edk::uint32 size = level->objsPhys->size();edkEnd();
                    for(edk::uint32 i=0u;i<size;i++){
                        this->treeAnimPhys.remove((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(0u));edkEnd();
                        //remove from worlf
                        this->world.removeObject((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(0u));edkEnd();
                        level->objsPhys->deleteObjInPosition(0u);edkEnd();
                    }
                }
            }
        }
    }
}
void edk::Cenario2D::deleteAllPhysicObjects(){
    edk::uint32 size = this->levels.size();edkEnd();
    edk::Cenario2D::LevelObj* level = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        level = this->levels[i];edkEnd();
        if(level){
            if(level->objsPhys){
                if(level->quadPhysicObjs){
                    delete level->quadPhysicObjs;edkEnd();
                }
                //remove the objPhys from world
                edk::uint32 sizePhys = level->objsPhys->size();edkEnd();
                for(edk::uint32 j=0u;j<sizePhys;j++){
                    this->world.removeObject((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(j));edkEnd();
                }
                delete level->objsPhys;edkEnd();
                level->clean();edkEnd();
            }
        }
    }
}
//remove the object
bool edk::Cenario2D::removePhysicObject(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj){
    if(levelPosition){
        levelPosition--;edkEnd();
        //load the level
        if(obj){
            if(this->levels.havePos(levelPosition)){
                edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
                if(level){
                    if(level->objsPhys){
                        this->treeAnimPhys.remove(obj);edkEnd();
                        //remove from world
                        this->world.removeObject(obj);edkEnd();
                        edk::Cenario2D::ObjClass* temp = level->objsPhys->getObjectClassFromObject((edk::Object2D*)obj);edkEnd();
                        if(temp){
                            level->quadPhysicObjs->remove(temp);edkEnd();
                            bool ret = level->objsPhys->remove(temp);edkEnd();
                            if(!level->objsPhys->size()){
                                //remove from world
                                if(level->quadPhysicObjs){
                                    delete level->quadPhysicObjs;edkEnd();
                                }
                                delete level->objsPhys;edkEnd();
                                level->clean();edkEnd();
                            }
                            return ret;
                        }
                    }
                }
            }
        }
    }
    return false;
}
bool edk::Cenario2D::removePhysicObjects(edk::uint32 levelPosition){
    if(levelPosition){
        levelPosition--;edkEnd();
        //load the level
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
            if(level){
                if(level->objsPhys){
                    edk::uint32 size = level->objsPhys->size();edkEnd();
                    edk::physics2D::PhysicObject2D* temp;edkEnd();
                    for(edk::uint32 i=0u;i<size;i++){
                        temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(i);edkEnd();
                        if(temp){
                            this->world.removeObject(temp);edkEnd();
                        }
                    }
                    return true;
                }
                else if(level->tileMap){
                    level->tileMap->deletePhysicsTiles();edkEnd();
                }
            }
        }
    }
    return false;
}
void edk::Cenario2D::removePhysicObjects(){
    edk::uint32 levelSize = this->levels.size();edkEnd();
    edk::uint32 size = 0u;edkEnd();
    edk::Cenario2D::LevelObj* level=NULL;edkEnd();
    for(edk::uint32 i=0u;i<levelSize;i++){
        level =this->levels[i];edkEnd();
        if(level){
            if(level->objsPhys){
                size = level->objsPhys->size();edkEnd();
                edk::physics2D::PhysicObject2D* temp;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(i);edkEnd();
                    if(temp){
                        this->world.removeObject(temp);edkEnd();
                    }
                }
            }
            else if(level->tileMap){
                level->tileMap->deletePhysicsTiles();edkEnd();
            }
        }
    }
}
//set physic object to be animated
bool edk::Cenario2D::setPhysicObjectAnimated(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj){
    //test the level position
    if(levelPosition){
        levelPosition--;edkEnd();
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels[levelPosition];edkEnd();
        if(level){
            //test if have objects
            if(level->objsPhys){
                //load the object
                edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObject(obj);edkEnd();
                if(temp){
                    if(temp->getType() == edk::physics::StaticBody
                            ||
                            temp->getType() == edk::physics::DynamicBody
                            ||
                            temp->getType() == edk::physics::KinematicBody
                            ){
                        //add the object to the animation tree
                        if(this->treeAnimPhys.haveElement(temp)){
                            return true;
                        }
                        else{
                            return this->treeAnimPhys.add(temp);edkEnd();
                        }
                    }
                }
            }
        }
    }
    return false;
}
bool edk::Cenario2D::setPhysicObjectAnimated(edk::uint32 levelPosition,edk::uint32 position){
    //test the level position
    if(levelPosition){
        levelPosition--;edkEnd();
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels[levelPosition];edkEnd();
        if(level){
            //test if have objects
            if(level->objsPhys){
                //load the object
                edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(position);edkEnd();
                if(temp){
                    if(temp->getType() == edk::physics::KinematicBody){
                        //add the object to the animation tree
                        if(this->treeAnimPhys.haveElement(temp)){
                            return true;
                        }
                        else{
                            return this->treeAnimPhys.add(temp);edkEnd();
                        }
                    }
                }
            }
        }
    }
    return false;
}
bool edk::Cenario2D::setPhysicObjectAnimated(edk::uint32 levelPosition,edk::float32 depth){
    //test the level position
    if(levelPosition){
        levelPosition--;edkEnd();
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels[levelPosition];edkEnd();
        if(level){
            //test if have objects
            if(level->objsPhys){
                //load the object
                edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectFromDepth(depth);edkEnd();
                if(temp){
                    if(temp->getType() == edk::physics::KinematicBody){
                        //add the object to the animation tree
                        if(this->treeAnimPhys.haveElement(temp)){
                            return true;
                        }
                        else{
                            return this->treeAnimPhys.add(temp);edkEnd();
                        }
                    }
                }
            }
        }
    }
    return false;
}
//remove physic object from be animated
bool edk::Cenario2D::removePhysicObjectAnimated(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj){
    //test the level position
    if(levelPosition){
        levelPosition--;edkEnd();
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels[levelPosition];edkEnd();
        if(level){
            //test if have objects
            if(level->objsPhys){
                //load the object
                edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObject(obj);edkEnd();
                if(temp){
                    if(temp->getType() == edk::physics::StaticBody
                            ||
                            temp->getType() == edk::physics::DynamicBody
                            ||
                            temp->getType() == edk::physics::KinematicBody
                            ){
                        //add the object to the animation tree
                        if(this->treeAnimPhys.haveElement(temp)){
                            return this->treeAnimPhys.remove(temp);edkEnd();
                        }
                    }
                }
            }
        }
    }
    return false;
}
bool edk::Cenario2D::removePhysicObjectAnimated(edk::uint32 levelPosition,edk::uint32 position){
    //test the level position
    if(levelPosition){
        levelPosition--;edkEnd();
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels[levelPosition];edkEnd();
        if(level){
            //test if have objects
            if(level->objsPhys){
                //load the object
                edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(position);edkEnd();
                if(temp){
                    if(temp->getType() == edk::physics::KinematicBody){
                        //add the object to the animation tree
                        if(this->treeAnimPhys.haveElement(temp)){
                            return this->treeAnimPhys.remove(temp);edkEnd();
                        }
                    }
                }
            }
        }
    }
    return false;
}
bool edk::Cenario2D::removePhysicObjectAnimated(edk::uint32 levelPosition,edk::float32 depth){
    //test the level position
    if(levelPosition){
        levelPosition--;edkEnd();
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels[levelPosition];edkEnd();
        if(level){
            //test if have objects
            if(level->objsPhys){
                //load the object
                edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectFromDepth(depth);edkEnd();
                if(temp){
                    if(temp->getType() == edk::physics::KinematicBody){
                        //add the object to the animation tree
                        if(this->treeAnimPhys.haveElement(temp)){
                            return this->treeAnimPhys.remove(temp);edkEnd();
                        }
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
        levelPosition--;edkEnd();
        //load the level
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
            if(level){
                if(level->tileMap){
                    delete level->tileMap;edkEnd();
                }
                if(level->objs){
                    this->deleteAllObjects(levelPosition+1u);edkEnd();
                }
                if(level->objsPhys){
                    if(level->quadPhysicObjs){
                        delete level->quadPhysicObjs;edkEnd();
                    }
                    //remove the objPhys from world
                    edk::uint32 sizePhys = level->objsPhys->size();edkEnd();
                    for(edk::uint32 j=0u;j<sizePhys;j++){
                        this->world.removeObject((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(j));edkEnd();
                    }
                    delete level->objsPhys;edkEnd();
                }
                level->clean();edkEnd();
            }
        }
    }
}
void edk::Cenario2D::deleteAllLevels(){
    edk::uint32 size = this->levels.size();edkEnd();
    if(size){
        this->treeAnim.clean();edkEnd();
        this->treeAnimPhys.clean();edkEnd();
        edk::Cenario2D::LevelObj* level = NULL;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            level = this->levels[i];edkEnd();
            if(level){
                if(level->tileMap){
                    delete level->tileMap;edkEnd();
                }
                if(level->objs){
                    this->deleteAllObjects(i+1u);edkEnd();
                }
                if(level->objsPhys){
                    if(level->quadPhysicObjs){
                        delete level->quadPhysicObjs;edkEnd();
                    }
                    //remove the objPhys from world
                    edk::uint32 sizePhys = level->objsPhys->size();edkEnd();
                    for(edk::uint32 j=0u;j<sizePhys;j++){
                        this->world.removeObject((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(j));edkEnd();
                    }
                    delete level->objsPhys;edkEnd();
                }
                level->clean();edkEnd();
                delete level;edkEnd();
            }
        }
    }
    this->levels.clean();edkEnd();
}

//add a callback
bool edk::Cenario2D::addCallback(edk::Cenario2DCallback* callback){
    return this->calls.add(callback);edkEnd();
}
bool edk::Cenario2D::removeCallback(edk::Cenario2DCallback* callback){
    return this->calls.remove(callback);edkEnd();
}

//World
void edk::Cenario2D::worldSetClockScale(edk::float32 scale){
    this->world.setClockScale(scale);edkEnd();
}
//clockStart
void edk::Cenario2D::worldClockStart(){
    this->world.clockStart();edkEnd();
}

//ACTIONS
//play actions
void edk::Cenario2D::playForwardActions(){
    this->actions.playForward();edkEnd();
}
void edk::Cenario2D::playForwardActions(edk::float32 updateSeconds){
    this->actions.playForward(updateSeconds);edkEnd();
}
void edk::Cenario2D::playForwardInActions(edk::float32 second){
    this->actions.playForwardIn(second);edkEnd();
}
void edk::Cenario2D::playForwardInActions(edk::float32 second,edk::float32 updateSeconds){
    this->actions.playForwardIn(second,updateSeconds);edkEnd();
}
//void edk::Cenario2D::playRewind();edkEnd();
//void edk::Cenario2D::playRewindIn(edk::float32 second);edkEnd();
void edk::Cenario2D::pauseActions(){
    this->actions.pause();edkEnd();
}
void edk::Cenario2D::stopActions(){
    this->actions.stop();edkEnd();
}
//set loop
void edk::Cenario2D::setLoopActions(bool loop){
    this->actions.setLoop(loop);edkEnd();
}
void edk::Cenario2D::loopOnActions(){
    this->actions.loopOn();edkEnd();
}
void edk::Cenario2D::loopOffActions(){
    this->actions.loopOff();edkEnd();
}

//return if are playing
bool edk::Cenario2D::isPlayingActions(){
    return this->actions.isPlaying();edkEnd();
}
bool edk::Cenario2D::isPausedActions(){
    return this->actions.isPaused();edkEnd();
}
//update actions
void edk::Cenario2D::updateActions(){
    this->actions.update();edkEnd();
}
void edk::Cenario2D::updateActions(edk::float32 seconds){
    this->actions.update(seconds);edkEnd();
}
//remove actions
void edk::Cenario2D::removeAllActions(){
    this->actions.clean();edkEnd();
}
bool edk::Cenario2D::removeActionSecond(edk::float32 second){
    return this->actions.removeSecond(second);edkEnd();
}
//Add zero action
bool edk::Cenario2D::actionZero(edk::float32 second){
    return this->actions.addZeroAction(second);edkEnd();
}
//add position action
bool edk::Cenario2D::actionObjectSetPosition(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::vec2f32 position){
    return this->actions.addAction(second,new edk::Cenario2D::ActionObjectSetPosition(this,levelPosition,depth,position));edkEnd();
}
bool edk::Cenario2D::actionObjectSetPosition(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::float32 x,edk::float32 y){
    return this->actionObjectSetPosition(second,levelPosition,depth,edk::vec2f32(x,y));edkEnd();
}
//add move action
bool edk::Cenario2D::actionObjectMove(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::vec2f32 position){
    if(this->actions.addAction(second,new edk::Cenario2D::ActionObjectMove(this,levelPosition,depth,duration,position))){
        this->actions.addZeroAction(second+duration);edkEnd();
        return true;
    }
    return false;
}
bool edk::Cenario2D::actionObjectMove(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::float32 x,edk::float32 y){
    return this->actionObjectMove(second,duration,levelPosition,depth,edk::vec2f32(x,y));edkEnd();
}
bool edk::Cenario2D::actionObjectMoveTo(edk::float32 start,edk::float32 end,edk::uint32 levelPosition,edk::float32 depth,edk::vec2f32 position){
    return this->actionObjectMove(start,end-start,levelPosition,depth,position);edkEnd();
}
bool edk::Cenario2D::actionObjectMoveTo(edk::float32 start,edk::float32 end,edk::uint32 levelPosition,edk::float32 depth,edk::float32 x,edk::float32 y){
    return this->actionObjectMove(start,end-start,levelPosition,depth,edk::vec2f32(x,y));edkEnd();
}
//add Size action
bool edk::Cenario2D::actionObjectSetSize(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::size2f32 size){
    return this->actions.addAction(second,new edk::Cenario2D::ActionObjectSetSize(this,levelPosition,depth,size));edkEnd();
}
bool edk::Cenario2D::actionObjectSetSize(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::float32 width,edk::float32 height){
    return actionObjectSetSize(second,levelPosition,depth,edk::size2f32(width,height));edkEnd();
}
bool edk::Cenario2D::actionObjectSetSize(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::float32 size){
    return this->actionObjectSetSize(second,levelPosition,depth,size,size);edkEnd();
}
//add scale action
bool edk::Cenario2D::actionObjectScale(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::size2f32 size){
    if(this->actions.addAction(second,new edk::Cenario2D::ActionObjectScale(this,levelPosition,depth,duration,size))){
        this->actions.addZeroAction(second+duration);edkEnd();
        return true;
    }
    return false;
}
bool edk::Cenario2D::actionObjectScale(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::float32 width,edk::float32 height){
    return this->actionObjectScale(second,duration,levelPosition,depth,edk::size2f32(width,height));edkEnd();
}
bool edk::Cenario2D::actionObjectScale(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::float32 size){
    return this->actionObjectScale(second,duration,levelPosition,depth,size,size);edkEnd();
}
bool edk::Cenario2D::actionObjectScaleTo(edk::float32 start,edk::float32 end,edk::uint32 levelPosition,edk::float32 depth,edk::size2f32 size){
    return this->actionObjectScale(start,end-start,levelPosition,depth,size);edkEnd();
}
bool edk::Cenario2D::actionObjectScaleTo(edk::float32 start,edk::float32 end,edk::uint32 levelPosition,edk::float32 depth,edk::float32 width,edk::float32 height){
    return this->actionObjectScale(start,end-start,levelPosition,depth,width,height);edkEnd();
}
bool edk::Cenario2D::actionObjectScaleTo(edk::float32 start,edk::float32 end,edk::uint32 levelPosition,edk::float32 depth,edk::float32 size){
    return this->actionObjectScale(start,end-start,levelPosition,depth,size);edkEnd();
}
//add angle action
bool edk::Cenario2D::actionObjectSetAngle(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::float32 angle){
    return this->actions.addAction(second,new edk::Cenario2D::ActionObjectSetAngle(this,levelPosition,depth,angle));edkEnd();
}
//add angle action
bool edk::Cenario2D::actionObjectRotateFor(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::float32 angle){
    if(this->actions.addAction(second,new edk::Cenario2D::ActionObjectRotate(this,levelPosition,depth,duration,angle))){
        this->actions.addZeroAction(second+duration);edkEnd();
        return true;
    }
    return false;
}
bool edk::Cenario2D::actionObjectRotateTo(edk::float32 start,edk::float32 end,edk::uint32 levelPosition,edk::float32 depth,edk::float32 angle){
    return this->actionObjectRotateFor(start,end-start,levelPosition,depth,angle);edkEnd();
}
//MESH SPRITE SHEET
bool edk::Cenario2D::actionObjectPlayName(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id,edk::char8* name,bool loop){
    return this->actions.addAction(second,new edk::Cenario2D::ActionObjectMeshName(this,levelPosition,depth,id,name,loop));edkEnd();
}
bool edk::Cenario2D::actionObjectPlayName(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id,const edk::char8* name,bool loop){
    return this->actionObjectPlayName(second,levelPosition,depth,id,(edk::char8*)name,loop);edkEnd();
}
bool edk::Cenario2D::actionObjectPlayNameFor(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id,edk::char8* name){
    if(this->actions.addAction(second,new edk::Cenario2D::ActionObjectMeshName(this,levelPosition,depth,id,name,true))){
        this->actions.addAction(second+duration,new edk::Cenario2D::ActionObjectMeshStop(this,levelPosition,depth,id));edkEnd();
        return true;
    }
    return false;
}
bool edk::Cenario2D::actionObjectPlayNameFor(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id,const edk::char8* name){
    return this->actionObjectPlayNameFor(second,duration,levelPosition,depth,id,(edk::char8*) name);edkEnd();
}


//update the physics and collisions
void edk::Cenario2D::updatePhysics(edk::int32 velocityIterations, edk::int32 positionIterations){
    //
    this->world.nextStep(velocityIterations, positionIterations);edkEnd();
}
void edk::Cenario2D::updatePhysics(edk::float32 seconds, edk::int32 velocityIterations, edk::int32 positionIterations){
    //
    this->world.nextStep(seconds,velocityIterations, positionIterations);edkEnd();
}
//update the quads (update selection in quadtree)
void edk::Cenario2D::updateQuadsInsideRect(edk::rectf32 rect){
    //draw the levels
    edk::uint32 size = this->levels.size();edkEnd();
    edk::Cenario2D::LevelObj* level=NULL;edkEnd();
    //this->transformBeggin();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        level=this->levels[i];edkEnd();
        if(level){
            level->updateQuads(rect,i+1u);edkEnd();
        }
    }
    //this->transformEnd();edkEnd();
}
bool edk::Cenario2D::updateLevelQuadsInsideRect(edk::uint32 levelPosition,edk::rectf32 rect){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            //this->transformBeggin();edkEnd();
            edk::Cenario2D::LevelObj* level=this->levels[levelPosition];edkEnd();
            level->updateQuads(rect,levelPosition+1u);edkEnd();
            //this->transformEnd();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::updateLevelsQuadsInsideRect(edk::uint32 startPosition,edk::uint32 endPosition,edk::rectf32 rect){
    bool ret=true;edkEnd();
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;edkEnd();
        endPosition--;edkEnd();
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;edkEnd();
            }
            else{
                startPosition = endPosition = 0u;edkEnd();
            }
            ret=false;edkEnd();
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;edkEnd();
            ret=false;edkEnd();
        }
        edk::Cenario2D::LevelObj* level=NULL;edkEnd();
        //daw the rects
        //this->transformBeggin();edkEnd();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels[i];edkEnd();
            if(level){
                level->updateQuads(rect,i+1u);edkEnd();
            }
        }
        //this->transformEnd();edkEnd();
        return ret;
    }
    return false;
}
//update animations
bool edk::Cenario2D::updateAnimation(edk::uint32 position){
    //test if have the level
    if(position){
        position--;edkEnd();
        if(this->levels.havePos(position)){
            //load the level
            edk::Cenario2D::LevelObj* level = this->levels[position];edkEnd();
            if(level){
                if(level->objs){
                    level->objs->loadSeconds();edkEnd();
                    level->objs->update();edkEnd();
                }
                if(level->objsPhys){
                    level->objsPhys->loadSeconds();edkEnd();
                    level->objsPhys->update();edkEnd();
                }
            }
            //update the tileSet
            this->tileSet.updateAnimations();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::updateAnimation(edk::uint32 position,edk::float32 seconds){
    //test if have the level
    if(position){
        position--;edkEnd();
        if(this->levels.havePos(position)){
            //load the level
            edk::Cenario2D::LevelObj* level = this->levels[position];edkEnd();
            if(level){
                if(level->objs){
                    level->objs->setSeconds(seconds);edkEnd();
                    level->objs->update();edkEnd();
                    level->objs->loadSeconds();edkEnd();
                }
                if(level->objsPhys){
                    level->objsPhys->setSeconds(seconds);edkEnd();
                    level->objsPhys->update();edkEnd();
                    level->objsPhys->loadSeconds();edkEnd();
                }
            }
            //update the tileSet
            this->tileSet.updateAnimations(seconds);edkEnd();
            return true;
        }
    }
    return false;
}
void edk::Cenario2D::updateAnimations(){
    this->treeAnim.loadSeconds();edkEnd();
    this->treeAnim.update();edkEnd();
    this->treeAnimPhys.loadSeconds();edkEnd();
    this->treeAnimPhys.update();edkEnd();
    //update the tileSet
    this->tileSet.updateAnimations();edkEnd();
}
void edk::Cenario2D::updateAnimations(edk::float32 seconds){
    this->treeAnim.setSeconds(seconds);edkEnd();
    this->treeAnim.update();edkEnd();
    this->treeAnim.loadSeconds();edkEnd();
    this->treeAnimPhys.setSeconds(seconds);edkEnd();
    this->treeAnimPhys.update();edkEnd();
    this->treeAnimPhys.loadSeconds();edkEnd();
    //update the tileSet
    this->tileSet.updateAnimations(seconds);edkEnd();
}
//draw the cenario with all the objects
void edk::Cenario2D::draw(){
    //draw the levels
    edk::uint32 size = this->levels.size();edkEnd();
    edk::Cenario2D::LevelObj* level=NULL;edkEnd();
    this->transformBeggin();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        level=this->levels[i];edkEnd();
        if(level){
            level->draw();edkEnd();
        }
    }
    this->transformEnd();edkEnd();
}
void edk::Cenario2D::drawWire(){
    //draw the levels
    edk::uint32 size = this->levels.size();edkEnd();
    edk::Cenario2D::LevelObj* level=NULL;edkEnd();
    this->transformBeggin();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        level=this->levels[i];edkEnd();
        if(level){
            level->drawWire();edkEnd();
        }
    }
    this->transformEnd();edkEnd();
}
void edk::Cenario2D::drawQuads(){
    //draw the levels
    edk::uint32 size = this->levels.size();edkEnd();
    edk::Cenario2D::LevelObj* level=NULL;edkEnd();
    this->transformBeggin();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        level=this->levels[i];edkEnd();
        if(level){
            level->drawQuads();edkEnd();
        }
    }
    this->transformEnd();edkEnd();
}
void edk::Cenario2D::drawBoxes(){
    //draw the levels
    edk::uint32 size = this->levels.size();edkEnd();
    edk::Cenario2D::LevelObj* level=NULL;edkEnd();
    this->transformBeggin();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        level=this->levels[i];edkEnd();
        if(level){
            level->drawBoxes();edkEnd();
        }
    }
    this->transformEnd();edkEnd();
}
void edk::Cenario2D::drawInsideRect(edk::rectf32 rect){
    //draw the levels
    edk::uint32 size = this->levels.size();edkEnd();
    edk::Cenario2D::LevelObj* level=NULL;edkEnd();
    this->transformBeggin();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        level=this->levels[i];edkEnd();
        if(level){
            level->drawInsideRect(rect,i+1u);edkEnd();
        }
    }
    this->transformEnd();edkEnd();
}
bool edk::Cenario2D::drawLevel(edk::uint32 levelPosition){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            this->transformBeggin();edkEnd();
            edk::Cenario2D::LevelObj* level=this->levels[levelPosition];edkEnd();
            level->draw();edkEnd();
            this->transformEnd();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::drawLevelWire(edk::uint32 levelPosition){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            this->transformBeggin();edkEnd();
            edk::Cenario2D::LevelObj* level=this->levels[levelPosition];edkEnd();
            level->drawWire();edkEnd();
            this->transformEnd();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::drawLevelQuads(edk::uint32 levelPosition){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            this->transformBeggin();edkEnd();
            edk::Cenario2D::LevelObj* level=this->levels[levelPosition];edkEnd();
            level->drawQuads();edkEnd();
            this->transformEnd();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::drawLevelBoxes(edk::uint32 levelPosition){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            this->transformBeggin();edkEnd();
            edk::Cenario2D::LevelObj* level=this->levels[levelPosition];edkEnd();
            level->drawBoxes();edkEnd();
            this->transformEnd();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::drawLevelInsideRect(edk::uint32 levelPosition,edk::rectf32 rect){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            this->transformBeggin();edkEnd();
            edk::Cenario2D::LevelObj* level=this->levels[levelPosition];edkEnd();
            level->drawInsideRect(rect,levelPosition+1u);edkEnd();
            this->transformEnd();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::drawLevelWireInsideRect(edk::uint32 levelPosition,edk::rectf32 rect){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            this->transformBeggin();edkEnd();
            edk::Cenario2D::LevelObj* level=this->levels[levelPosition];edkEnd();
            level->drawWireInsideRect(rect,levelPosition+1u);edkEnd();
            this->transformEnd();edkEnd();
            return true;
        }
    }
    return false;
}
//draw levels from start and end
bool edk::Cenario2D::drawLevels(edk::uint32 startPosition,edk::uint32 endPosition){
    bool ret=true;edkEnd();
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;edkEnd();
        endPosition--;edkEnd();
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;edkEnd();
            }
            else{
                startPosition = endPosition = 0u;edkEnd();
            }
            ret=false;edkEnd();
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;edkEnd();
            ret=false;edkEnd();
        }
        edk::Cenario2D::LevelObj* level=NULL;edkEnd();
        //daw the rects
        this->transformBeggin();edkEnd();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels[i];edkEnd();
            if(level){
                level->draw();edkEnd();
            }
        }
        this->transformEnd();edkEnd();
        return ret;
    }
    return false;
}
bool edk::Cenario2D::drawLevelsWire(edk::uint32 startPosition,edk::uint32 endPosition){
    bool ret=true;edkEnd();
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;edkEnd();
        endPosition--;edkEnd();
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;edkEnd();
            }
            else{
                startPosition = endPosition = 0u;edkEnd();
            }
            ret=false;edkEnd();
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;edkEnd();
            ret=false;edkEnd();
        }
        edk::Cenario2D::LevelObj* level=NULL;edkEnd();
        //daw the rects
        this->transformBeggin();edkEnd();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels[i];edkEnd();
            if(level){
                level->drawWire();edkEnd();
            }
        }
        this->transformEnd();edkEnd();
        return ret;
    }
    return false;
}
bool edk::Cenario2D::drawLevelsQuads(edk::uint32 startPosition,edk::uint32 endPosition){
    bool ret=true;edkEnd();
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;edkEnd();
        endPosition--;edkEnd();
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;edkEnd();
            }
            else{
                startPosition = endPosition = 0u;edkEnd();
            }
            ret=false;edkEnd();
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;edkEnd();
            ret=false;edkEnd();
        }
        edk::Cenario2D::LevelObj* level=NULL;edkEnd();
        //daw the rects
        this->transformBeggin();edkEnd();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels[i];edkEnd();
            if(level){
                level->drawQuads();edkEnd();
            }
        }
        this->transformEnd();edkEnd();
        return ret;
    }
    return false;
}
bool edk::Cenario2D::drawLevelsBoxes(edk::uint32 startPosition,edk::uint32 endPosition){
    bool ret=true;edkEnd();
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;edkEnd();
        endPosition--;edkEnd();
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;edkEnd();
            }
            else{
                startPosition = endPosition = 0u;edkEnd();
            }
            ret=false;edkEnd();
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;edkEnd();
            ret=false;edkEnd();
        }
        edk::Cenario2D::LevelObj* level=NULL;edkEnd();
        //daw the rects
        this->transformBeggin();edkEnd();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels[i];edkEnd();
            if(level){
                level->drawBoxes();edkEnd();
            }
        }
        this->transformEnd();edkEnd();
        return ret;
    }
    return false;
}
bool edk::Cenario2D::drawLevelsInsideRect(edk::uint32 startPosition,edk::uint32 endPosition,edk::rectf32 rect){
    bool ret=true;edkEnd();
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;edkEnd();
        endPosition--;edkEnd();
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;edkEnd();
            }
            else{
                startPosition = endPosition = 0u;edkEnd();
            }
            ret=false;edkEnd();
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;edkEnd();
            ret=false;edkEnd();
        }
        edk::Cenario2D::LevelObj* level=NULL;edkEnd();
        //daw the rects
        this->transformBeggin();edkEnd();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels[i];edkEnd();
            if(level){
                level->drawInsideRect(rect,i+1u);edkEnd();
            }
        }
        this->transformEnd();edkEnd();
        return ret;
    }
    return false;
}
bool edk::Cenario2D::drawLevelsWireInsideRect(edk::uint32 startPosition,edk::uint32 endPosition,edk::rectf32 rect){
    bool ret=true;edkEnd();
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;edkEnd();
        endPosition--;edkEnd();
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;edkEnd();
            }
            else{
                startPosition = endPosition = 0u;edkEnd();
            }
            ret=false;edkEnd();
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;edkEnd();
            ret=false;edkEnd();
        }
        edk::Cenario2D::LevelObj* level=NULL;edkEnd();
        //daw the rects
        this->transformBeggin();edkEnd();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels[i];edkEnd();
            if(level){
                level->drawWireInsideRect(rect,i+1u);edkEnd();
            }
        }
        this->transformEnd();edkEnd();
        return ret;
    }
    return false;
}
void edk::Cenario2D::drawSelection(){
    edk::uint32 size = this->levels.size();edkEnd();
    edk::Cenario2D::LevelObj* level=NULL;edkEnd();
    this->transformBeggin();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        level=this->levels[i];edkEnd();
        if(level){
            level->drawSelection(i+1u);edkEnd();
        }
    }
    this->transformEnd();edkEnd();
}
bool edk::Cenario2D::drawSelectionLevel(edk::uint32 levelPosition){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            this->transformBeggin();edkEnd();
            edk::Cenario2D::LevelObj* level=this->levels[levelPosition];edkEnd();
            level->drawSelection(levelPosition+1u);edkEnd();
            this->transformEnd();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::drawSelectionLevels(edk::uint32 startPosition,edk::uint32 endPosition){
    bool ret=true;edkEnd();
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;edkEnd();
        endPosition--;edkEnd();
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;edkEnd();
            }
            else{
                startPosition = endPosition = 0u;edkEnd();
            }
            ret=false;edkEnd();
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;edkEnd();
            ret=false;edkEnd();
        }
        edk::Cenario2D::LevelObj* level=NULL;edkEnd();
        //daw the rects
        this->transformBeggin();edkEnd();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels[i];edkEnd();
            if(level){
                level->drawSelection(i+1u);edkEnd();
            }
        }
        this->transformEnd();edkEnd();
        return ret;
    }
    return false;
}
bool edk::Cenario2D::drawSelectionLevelsInsideRect(edk::uint32 startPosition,edk::uint32 endPosition,edk::rectf32 rect){
    bool ret=true;edkEnd();
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;edkEnd();
        endPosition--;edkEnd();
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;edkEnd();
            }
            else{
                startPosition = endPosition = 0u;edkEnd();
            }
            ret=false;edkEnd();
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;edkEnd();
            ret=false;edkEnd();
        }
        edk::Cenario2D::LevelObj* level=NULL;edkEnd();
        //daw the rects
        this->transformBeggin();edkEnd();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels[i];edkEnd();
            if(level){
                level->drawSelectionInsideRect(rect,i+1u);edkEnd();
            }
        }
        this->transformEnd();edkEnd();
        return ret;
    }
    return false;
}

//SHOW/HIDE LEVEL
bool edk::Cenario2D::hideLevel(edk::uint32 levelPosition){
    return this->setShowLevel(levelPosition,false);edkEnd();
}
bool edk::Cenario2D::showLevel(edk::uint32 levelPosition){
    return this->setShowLevel(levelPosition,true);edkEnd();
}
bool edk::Cenario2D::setShowLevel(edk::uint32 levelPosition,bool show){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level=this->levels[levelPosition];edkEnd();
            level->show = show;edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::getShowLevel(edk::uint32 levelPosition){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level=this->levels[levelPosition];edkEnd();
            return level->show;edkEnd();
        }
    }
    return false;
}

//get level type
edk::uint8 edk::Cenario2D::getLevelType(edk::uint32 levelPosition){
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
            if(level){
                if(level->objs){
                    return EDK_LEVEL_OBJ;edkEnd();
                }
                if(level->objsPhys){
                    return EDK_LEVEL_OBJ_PHYSICS;edkEnd();
                }
                if(level->tileMap){
                    return EDK_LEVEL_TILE_MAP;edkEnd();
                }
            }
        }
    }
    return 0u;edkEnd();
}
//test if have the level
bool edk::Cenario2D::haveLevel(edk::uint32 levelPosition){
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
            if(level){
                return level->haveSome();edkEnd();
            }
        }
    }
    return false;
}
//return the levelSize
edk::uint32 edk::Cenario2D::getLevelsSize(){
    return this->levels.size();edkEnd();
}
edk::uint32 edk::Cenario2D::getLevelSize(edk::uint32 levelPosition){
    //test the level
    if(levelPosition){
        levelPosition--;edkEnd();
        //test if have the level
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
            if(level){
                if(level->objs){
                    return level->objs->size();edkEnd();
                }
                if(level->objsPhys){
                    return level->objsPhys->size();edkEnd();
                }
            }
        }
    }
    return 0u;edkEnd();
}
//move the level to back
bool edk::Cenario2D::moveLevelBack(edk::uint32 levelPosition){
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            return this->levels.bringPositionMinusOne(levelPosition);edkEnd();
        }
    }
    return false;
}
bool edk::Cenario2D::moveLevelFront(edk::uint32 levelPosition){
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            return this->levels.bringPositionPlusOne(levelPosition);edkEnd();
        }
    }
    return false;
}

//set level translate
bool edk::Cenario2D::setLevelPosition(edk::uint32 levelPosition,edk::vec2f32 position){
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
            if(level){
                level->transform.position = position;edkEnd();
                return true;
            }
        }
    }
    return false;
}
bool edk::Cenario2D::setLevelPosition(edk::uint32 levelPosition,edk::float32 x,edk::float32 y){
    return setLevelPosition(levelPosition,edk::vec2f32(x,y));edkEnd();
}
//set level rotate angle
bool edk::Cenario2D::setLevelAngle(edk::uint32 levelPosition,edk::float32 angle){
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
            if(level){
                level->transform.angle = angle;edkEnd();
                return true;
            }
        }
    }
    return false;
}
//set level size
bool edk::Cenario2D::setLevelSize(edk::uint32 levelPosition,edk::size2f32 size){
    if(levelPosition){
        levelPosition--;edkEnd();
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels[levelPosition];edkEnd();
            if(level){
                level->transform.size = size;edkEnd();
                return true;
            }
        }
    }
    return false;
}
bool edk::Cenario2D::setLevelSize(edk::uint32 levelPosition,edk::float32 width,edk::float32 height){
    //
    return this->setLevelSize(levelPosition,edk::size2f32(width,height));edkEnd();
}

//XML
bool edk::Cenario2D::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Cenario_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        if(xml->addSelectedNextChild("meters")){
                            if(xml->selectChild("meters")){
                                xml->setSelectedString(this->world.getMeterDistance());edkEnd();
                                xml->selectFather();edkEnd();
                            }
                        }

                        //write the tileSet
                        this->tileSet.writeToXML(xml,0u);edkEnd();

                        //add levels
                        edk::char8* temp;edkEnd();
                        edk::char8* nameTemp;edkEnd();
                        edk::char8* idTemp;edkEnd();

                        //write the levels
                        edk::uint32 size = this->levels.size();edkEnd();
                        temp = edk::String::int64ToStr(size);edkEnd();
                        if(temp){
                            //add levels
                            if(xml->addSelectedNextChild("levels")){
                                if(xml->selectChild("levels")){
                                    xml->setSelectedString(temp);edkEnd();
                                    edk::Cenario2D::LevelObj* level;edkEnd();
                                    for(edk::uint32 i=0u;i<size;i++){
                                        //load the level
                                        level = this->levels[i];edkEnd();
                                        if(level){
                                            level->writeToXML(xml,i);edkEnd();
                                        }
                                    }
                                    xml->selectFather();edkEnd();
                                }
                            }
                            delete[] temp;edkEnd();
                        }

                        //JOINTS
                        if(xml->addSelectedNextChild("joints")){
                            if(xml->selectChild("joints")){
                                size = this->world.getJointSize();edkEnd();
                                temp = edk::String::int64ToStr(size);edkEnd();
                                if(temp){
                                    xml->setSelectedString(temp);edkEnd();
                                    delete[] temp;edkEnd();
                                }
                                edk::uint8 jointType;edkEnd();
                                edk::physics2D::Joint2D* joint;edkEnd();
                                edk::physics2D::RevoluteJoint2D* revoluteJoint;edkEnd();
                                edk::physics2D::DistanceJoint2D* distanceJoint;edkEnd();
                                edk::physics2D::PrismaticJoint2D* prismaticJoint;edkEnd();
                                edk::physics2D::PulleyJoint2D* pulleyJoint;edkEnd();
                                edk::physics2D::WheelJoint2D* wheelJoint;edkEnd();
                                //REMOVE IN NEW BOX2D
                                //edk::physics2D::RopeJoint2D* ropeJoint;edkEnd();
                                edk::Cenario2D::PhysicsPosition objectA;edkEnd();
                                edk::Cenario2D::PhysicsPosition objectB;edkEnd();
                                for(edk::uint32 i=0u;i<size;i++){
                                    //test if have the joint in position
                                    if((joint = this->world.getJointInPosition(i))){
                                        //load the object
                                        if(this->getPhysicsLevelObject(joint->objectA,&objectA)){
                                            if(this->getPhysicsLevelObject(joint->objectB,&objectB)){
                                                idTemp = edk::String::int64ToStr(i);edkEnd();
                                                if(idTemp){
                                                    nameTemp = edk::String::strCat((edk::char8*)"joint_",idTemp);edkEnd();
                                                    if(nameTemp){
                                                        //create the xmlNode
                                                        if(xml->addSelectedNextChild(nameTemp)){
                                                            if(xml->selectChild(nameTemp)){
                                                                jointType = this->world.getJointTypeInPosition(i);edkEnd();
                                                                temp = edk::String::int64ToStr(jointType);edkEnd();
                                                                if(temp){
                                                                    xml->setSelectedString(temp);edkEnd();
                                                                    delete[] temp;edkEnd();
                                                                }
                                                                //Write the object
                                                                objectA.writeToXML(xml,true);edkEnd();
                                                                objectB.writeToXML(xml,false);edkEnd();

                                                                temp = edk::String::float32ToStr(joint->worldPositionA.x);edkEnd();
                                                                if(temp){
                                                                    xml->addSelectedNextAttribute((edk::char8*)"worldPositionAX",temp);edkEnd();
                                                                    delete[] temp;edkEnd();
                                                                }
                                                                temp = edk::String::float32ToStr(joint->worldPositionA.y);edkEnd();
                                                                if(temp){
                                                                    xml->addSelectedNextAttribute((edk::char8*)"worldPositionAY",temp);edkEnd();
                                                                    delete[] temp;edkEnd();
                                                                }
                                                                //Positions
                                                                temp = edk::String::float32ToStr(joint->positionA.x);edkEnd();
                                                                if(temp){
                                                                    xml->addSelectedNextAttribute((edk::char8*)"positionAX",temp);edkEnd();
                                                                    delete[] temp;edkEnd();
                                                                }
                                                                temp = edk::String::float32ToStr(joint->positionA.y);edkEnd();
                                                                if(temp){
                                                                    xml->addSelectedNextAttribute((edk::char8*)"positionAY",temp);edkEnd();
                                                                    delete[] temp;edkEnd();
                                                                }
                                                                temp = edk::String::float32ToStr(joint->positionB.x);edkEnd();
                                                                if(temp){
                                                                    xml->addSelectedNextAttribute((edk::char8*)"positionBX",temp);edkEnd();
                                                                    delete[] temp;edkEnd();
                                                                }
                                                                temp = edk::String::float32ToStr(joint->positionB.y);edkEnd();
                                                                if(temp){
                                                                    xml->addSelectedNextAttribute((edk::char8*)"positionBY",temp);edkEnd();
                                                                    delete[] temp;edkEnd();
                                                                }

                                                                //collide
                                                                if(joint->getCollide()){
                                                                    xml->addSelectedNextAttribute("collide","true");edkEnd();
                                                                }

                                                                switch(jointType){
                                                                case EDK_JOINT:
                                                                    //
                                                                    //xml->setSelectedString("JOINT");edkEnd();
                                                                    break;edkEnd();
                                                                case EDK_REVOLUTE_JOINT:
                                                                    //
                                                                    //xml->setSelectedString("REVOLUTE_JOINT");edkEnd();
                                                                    revoluteJoint = (edk::physics2D::RevoluteJoint2D*)this->world.getJointInPosition(i);edkEnd();
                                                                    //test the revoluteType
                                                                    switch(revoluteJoint->getRevoluteType()){
                                                                    case EDK_JOINT_ANGLE:
                                                                        xml->addSelectedNextAttribute("type","ANGLE");edkEnd();
                                                                        temp = edk::String::float32ToStr(revoluteJoint->getLowerAngle());edkEnd();
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"lowerAngle",temp);edkEnd();
                                                                            delete[] temp;edkEnd();
                                                                        }
                                                                        temp = edk::String::float32ToStr(revoluteJoint->getUpperAngle());edkEnd();
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"upperAngle",temp);edkEnd();
                                                                            delete[] temp;edkEnd();
                                                                        }
                                                                        break;edkEnd();
                                                                    case EDK_JOINT_MOTOR:
                                                                        xml->addSelectedNextAttribute("type","MOTOR");edkEnd();
                                                                        temp = edk::String::float32ToStr(revoluteJoint->getMaxTorque());edkEnd();
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"maxTorque",temp);edkEnd();
                                                                            delete[] temp;edkEnd();
                                                                        }
                                                                        temp = edk::String::float32ToStr(revoluteJoint->getSpeed());edkEnd();
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"speed",temp);edkEnd();
                                                                            delete[] temp;edkEnd();
                                                                        }
                                                                        break;edkEnd();
                                                                    default:
                                                                        xml->addSelectedNextAttribute("type","NORMAL");edkEnd();
                                                                    }
                                                                    break;edkEnd();
                                                                case EDK_PRISMATIC_JOINT:
                                                                    //
                                                                    //xml->setSelectedString("PRISMATIC_JOINT");edkEnd();
                                                                    prismaticJoint = (edk::physics2D::PrismaticJoint2D*)this->world.getJointInPosition(i);edkEnd();
                                                                    //write direction
                                                                    temp = edk::String::float32ToStr(prismaticJoint->direction.x);edkEnd();
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"directionX",temp);edkEnd();
                                                                        delete[] temp;edkEnd();
                                                                    }
                                                                    temp = edk::String::float32ToStr(prismaticJoint->direction.y);edkEnd();
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"directionY",temp);edkEnd();
                                                                        delete[] temp;edkEnd();
                                                                    }
                                                                    //test the Type
                                                                    if(prismaticJoint->getPrismaticType() == EDK_JOINT_MOTOR){
                                                                        xml->addSelectedNextAttribute("type","MOTOR");edkEnd();
                                                                        temp = edk::String::float32ToStr(prismaticJoint->getMaxForce());edkEnd();
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"maxForce",temp);edkEnd();
                                                                            delete[] temp;edkEnd();
                                                                        }
                                                                        temp = edk::String::float32ToStr(prismaticJoint->getSpeed());edkEnd();
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"speed",temp);edkEnd();
                                                                            delete[] temp;edkEnd();
                                                                        }
                                                                    }
                                                                    temp = edk::String::float32ToStr(prismaticJoint->lowerDistance);edkEnd();
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"lowerDistance",temp);edkEnd();
                                                                        delete[] temp;edkEnd();
                                                                    }
                                                                    temp = edk::String::float32ToStr(prismaticJoint->upperDistance);edkEnd();
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"upperDistance",temp);edkEnd();
                                                                        delete[] temp;edkEnd();
                                                                    }
                                                                    break;edkEnd();
                                                                case EDK_PULLEY_JOINT:
                                                                    //
                                                                    //xml->setSelectedString("PULLEY_JOINT");edkEnd();
                                                                    pulleyJoint = (edk::physics2D::PulleyJoint2D*)this->world.getJointInPosition(i);edkEnd();
                                                                    //write pulleyPositions
                                                                    temp = edk::String::float32ToStr(pulleyJoint->pulleyPositionA.x);edkEnd();
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"pulleyPositionAX",temp);edkEnd();
                                                                        delete[] temp;edkEnd();
                                                                    }
                                                                    temp = edk::String::float32ToStr(pulleyJoint->pulleyPositionA.y);edkEnd();
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"pulleyPositionAY",temp);edkEnd();
                                                                        delete[] temp;edkEnd();
                                                                    }
                                                                    temp = edk::String::float32ToStr(pulleyJoint->pulleyPositionB.x);edkEnd();
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"pulleyPositionBX",temp);edkEnd();
                                                                        delete[] temp;edkEnd();
                                                                    }
                                                                    temp = edk::String::float32ToStr(pulleyJoint->pulleyPositionB.y);edkEnd();
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"pulleyPositionBY",temp);edkEnd();
                                                                        delete[] temp;edkEnd();
                                                                    }
                                                                    temp = edk::String::float32ToStr(pulleyJoint->lenghtA);edkEnd();
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"lenghtA",temp);edkEnd();
                                                                        delete[] temp;edkEnd();
                                                                    }
                                                                    temp = edk::String::float32ToStr(pulleyJoint->lenghtB);edkEnd();
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"lenghtB",temp);edkEnd();
                                                                        delete[] temp;edkEnd();
                                                                    }
                                                                case EDK_DISTANCE_JOINT:
                                                                    //
                                                                    //xml->setSelectedString("DISTANCE_JOINT");edkEnd();
                                                                    distanceJoint = (edk::physics2D::DistanceJoint2D*)this->world.getJointInPosition(i);edkEnd();
                                                                    temp = edk::String::float32ToStr(distanceJoint->worldPositionB.x);edkEnd();
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"worldPositionBX",temp);edkEnd();
                                                                        delete[] temp;edkEnd();
                                                                    }
                                                                    temp = edk::String::float32ToStr(distanceJoint->worldPositionB.y);edkEnd();
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"worldPositionBY",temp);edkEnd();
                                                                        delete[] temp;edkEnd();
                                                                    }
                                                                    //distance
                                                                    temp = edk::String::float32ToStr(distanceJoint->distance);edkEnd();
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"distance",temp);edkEnd();
                                                                        delete[] temp;edkEnd();
                                                                    }
                                                                    break;edkEnd();
                                                                case EDK_WHEEL_JOINT:
                                                                    //
                                                                    //xml->setSelectedString("WHEEL_JOINT");edkEnd();
                                                                    wheelJoint = (edk::physics2D::WheelJoint2D*)this->world.getJointInPosition(i);edkEnd();
                                                                    //write direction
                                                                    temp = edk::String::float32ToStr(wheelJoint->direction.x);edkEnd();
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"directionX",temp);edkEnd();
                                                                        delete[] temp;edkEnd();
                                                                    }
                                                                    temp = edk::String::float32ToStr(wheelJoint->direction.y);edkEnd();
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"directionY",temp);edkEnd();
                                                                        delete[] temp;edkEnd();
                                                                    }
                                                                    //test the Type
                                                                    if(wheelJoint->getWheelType() == EDK_JOINT_MOTOR){
                                                                        xml->addSelectedNextAttribute("type","MOTOR");edkEnd();
                                                                        temp = edk::String::float32ToStr(wheelJoint->getMaxTorque());edkEnd();
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"maxTorque",temp);edkEnd();
                                                                            delete[] temp;edkEnd();
                                                                        }
                                                                        temp = edk::String::float32ToStr(wheelJoint->getSpeed());edkEnd();
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"speed",temp);edkEnd();
                                                                            delete[] temp;edkEnd();
                                                                        }
                                                                    }
                                                                    break;edkEnd();
                                                                    //REMOVE IN NEW BOX2D
                                                                    /*
                                                                case EDK_ROPE_JOINT:
                                                                    //
                                                                    //xml->setSelectedString("ROPE_JOINT");edkEnd();
                                                                    ropeJoint = (edk::physics2D::RopeJoint2D*)this->world.getJointInPosition(i);edkEnd();
                                                                    //
                                                                    temp = edk::String::float32ToStr(ropeJoint->worldPositionB.x);edkEnd();
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"worldPositionBX",temp);edkEnd();
                                                                        delete[] temp;edkEnd();
                                                                    }
                                                                    temp = edk::String::float32ToStr(ropeJoint->worldPositionB.y);edkEnd();
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"worldPositionBY",temp);edkEnd();
                                                                        delete[] temp;edkEnd();
                                                                    }
                                                                    temp = edk::String::float32ToStr(ropeJoint->maxLength);edkEnd();
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"maxLength",temp);edkEnd();
                                                                        delete[] temp;edkEnd();
                                                                    }
                                                                    break;edkEnd();
                                                                */
                                                                }
                                                                xml->selectFather();edkEnd();
                                                            }
                                                        }
                                                        delete[] nameTemp;edkEnd();
                                                    }
                                                    delete[] idTemp;edkEnd();
                                                }
                                            }
                                        }
                                    }
                                }
                                xml->selectFather();edkEnd();
                            }
                        }

                        //ACTIONS
                        this->actions.writeToXML(xml,0u);edkEnd();

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
bool edk::Cenario2D::writeToXML(const edk::char8* fileName,edk::uint32 id){
    return this->writeToXML((edk::char8*) fileName,id);edkEnd();
}
bool edk::Cenario2D::writeToXML(edk::char8* fileName,edk::uint32 id){
    //load the XML file
    if(fileName){
        edk::XML xml;edkEnd();
        if(this->writeToXML(&xml,id)){
            //
            return xml.saveToFile(fileName);edkEnd();
        }
    }
    return false;
}
//read from XML
bool edk::Cenario2D::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Cenario_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* nameTemp;edkEnd();
                    edk::char8* idTemp;edkEnd();
                    edk::char8* temp;edkEnd();

                    if(xml->selectChild("meters")){
                        this->world.setMeterDistance(xml->getSelectedStringAsFloat32());edkEnd();
                        xml->selectFather();edkEnd();
                    }

                    //read tileSet
                    this->tileSet.readFromXML(xml,0u);edkEnd();
                    //read the levels
                    if(xml->selectChild("levels")){

                        this->deleteAllLevels();edkEnd();
                        edk::uint32 size = 0u;edkEnd();

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                        if(temp){
                            size = edk::String::strToInt64(temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        edk::Cenario2D::LevelObj* level;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            //load the level
                            level = new edk::Cenario2D::LevelObj(&this->calls);edkEnd();
                            if(level){
                                //add the level to the tree
                                this->levels.pushBack(level);edkEnd();
                                level->readFromXML(xml,i,&this->tileSet,&this->world);edkEnd();
                            }
                        }
                        this->loadPhysicObjectsToWorld();edkEnd();
                        xml->selectFather();edkEnd();
                    }

                    //JOINTS
                    if(xml->selectChild("joints")){
                        edk::uint32 size = 0u;edkEnd();
                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                        if(temp){
                            size = edk::String::strToInt64(temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        //object vectors
                        bool collide;edkEnd();
                        edk::vec2f32 worldPosition;edkEnd();
                        edk::vec2f32 positionA;edkEnd();
                        edk::vec2f32 positionB;edkEnd();
                        for(edk::uint32 i = 0u;i<size;i++){
                            collide=false;edkEnd();
                            edk::Cenario2D::PhysicsPosition objectA;edkEnd();
                            edk::Cenario2D::PhysicsPosition objectB;edkEnd();
                            idTemp = edk::String::int64ToStr(i);edkEnd();
                            if(idTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"joint_",idTemp);edkEnd();
                                if(nameTemp){
                                    //create the xmlNode
                                    if(xml->selectChild(nameTemp)){
                                        //read the type
                                        edk::uint8 jointType = 0u;edkEnd();
                                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                                        if(temp){
                                            jointType = edk::String::strToInt32(temp);edkEnd();
                                            delete[] temp;edkEnd();
                                        }
                                        //read the objects
                                        objectA.readFromXML(xml,true);edkEnd();
                                        objectB.readFromXML(xml,false);edkEnd();
                                        //ret collide
                                        if(xml->getSelectedAttributeValueByName("collide")){
                                            collide=true;edkEnd();
                                        }
                                        //getWorldPosition
                                        worldPosition = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionAX")),
                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionAY")));edkEnd();
                                        positionA = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionAX")),
                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionAY")));edkEnd();
                                        positionB = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionBX")),
                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionBY")));edkEnd();

                                        switch(jointType){
                                        case EDK_JOINT:
                                            //add the joint
                                            //                                            this->world.createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                        this->getPhysicsObjectInLevel(objectB),
                                            //                                                                        worldPosition,
                                            //                                                                        collide
                                            //                                                                        );edkEnd();
                                            this->world.createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        collide
                                                                        );edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                     );edkEnd();
                                                this->world.createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                     positionA,
                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                                                     positionB,
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerAngle")),
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperAngle")),
                                                                                     collide
                                                                                     );edkEnd();
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
                                                //                                                                                     );edkEnd();
                                                this->world.createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                     positionA,
                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                                                     positionB,
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                     collide
                                                                                     );edkEnd();
                                            }
                                            else if(edk::String::strCompare(xml->getSelectedAttributeValueByName("type"),"NORMAL")){
                                                //
                                                //                                                this->world.createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                worldPosition,
                                                //                                                                                collide
                                                //                                                                                );edkEnd();
                                                this->world.createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                positionA,
                                                                                this->getPhysicsObjectInLevel(objectB),
                                                                                positionB,
                                                                                collide
                                                                                );edkEnd();
                                            }
                                            break;edkEnd();
                                        case EDK_DISTANCE_JOINT:
                                            //create distanceJoint
                                            //                                            this->world.createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                            worldPosition,
                                            //                                                                            this->getPhysicsObjectInLevel(objectB),
                                            //                                                                            edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBX")),
                                            //                                                                                         edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBY"))
                                            //                                                                                         ),
                                            //                                                                            collide);edkEnd();
                                            this->world.createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                                                            positionA,
                                                                            this->getPhysicsObjectInLevel(objectB),
                                                                            positionB,
                                                                            edk::String::strToFloat32(xml->getSelectedAttributeValueByName("distance")),
                                                                            collide);edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                      );edkEnd();
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
                                                                                      );edkEnd();
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
                                                //                                                                                 );edkEnd();
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
                                                                                 );edkEnd();
                                            }
                                            break;edkEnd();
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
                                            //                                                                               );edkEnd();
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
                                                                          );edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                  collide
                                                //                                                                                  );edkEnd();
                                                this->world.createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                  positionA,
                                                                                  this->getPhysicsObjectInLevel(objectB),
                                                                                  positionB,
                                                                                  edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                               ),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                  collide
                                                                                  );edkEnd();
                                            }
                                            else{
                                                //
                                                //                                                this->world.createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                             this->getPhysicsObjectInLevel(objectB),
                                                //                                                                             worldPosition,
                                                //                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                          ),
                                                //                                                                             collide
                                                //                                                                             );edkEnd();
                                                this->world.createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                                             positionA,
                                                                             this->getPhysicsObjectInLevel(objectB),
                                                                             positionB,
                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                          ),
                                                                             collide
                                                                             );edkEnd();
                                            }
                                            break;edkEnd();
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
                                            //                                                                                      );edkEnd();
                                            //REMOVED IN NEW BOX2D
                                            /*
                                            this->world.createRopeJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
                                                                        collide
                                                                        );edkEnd();
                                            */
                                            break;edkEnd();
                                        }
                                    }
                                    delete[] nameTemp;edkEnd();
                                }
                                delete[] idTemp;edkEnd();
                            }
                        }
                    }

                    //ACTIONS
                    this->actions.readFromXML(xml,0u,this);edkEnd();

                    ret=true;edkEnd();
                    xml->selectFather();edkEnd();

                    //generate the quadtree position and size
                    {
                        edk::uint32 size = this->levels.size();edkEnd();
                        edk::Cenario2D::LevelObj* level=NULL;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            level=this->levels[i];edkEnd();
                            if(level){
                                level->generateLevelRect();edkEnd();
                                level->addObjectsToQuad();edkEnd();
                            }
                        }
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
bool edk::Cenario2D::readFromXML(const edk::char8* fileName,edk::uint32 id){
    return this->readFromXML((edk::char8*) fileName,id);edkEnd();
}
bool edk::Cenario2D::readFromXML(edk::char8* fileName,edk::uint32 id){
    //load the XML file
    if(fileName){
        edk::XML xml;edkEnd();
        if(xml.loadFile(fileName)){
            //load the cenario from the XML file
            return this->readFromXML(&xml,id);edkEnd();
        }
    }
    return false;
}
bool edk::Cenario2D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    if(xml && pack){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Cenario_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* nameTemp;edkEnd();
                    edk::char8* idTemp;edkEnd();
                    edk::char8* temp;edkEnd();

                    if(xml->selectChild("meters")){
                        this->world.setMeterDistance(xml->getSelectedStringAsFloat32());edkEnd();
                        xml->selectFather();edkEnd();
                    }

                    //read tileSet
                    this->tileSet.readFromXMLFromPack(pack,xml,0u);edkEnd();
                    //read the levels
                    if(xml->selectChild("levels")){

                        this->deleteAllLevels();edkEnd();
                        edk::uint32 size = 0u;edkEnd();

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                        if(temp){
                            size = edk::String::strToInt64(temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        edk::Cenario2D::LevelObj* level;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            //load the level
                            level = new edk::Cenario2D::LevelObj(&this->calls);edkEnd();
                            if(level){
                                //add the level to the tree
                                this->levels.pushBack(level);edkEnd();
                                level->readFromXMLFromPack(pack,xml,i,&this->tileSet,&this->world);edkEnd();
                            }
                        }
                        this->loadPhysicObjectsToWorld();edkEnd();
                        xml->selectFather();edkEnd();
                    }

                    //JOINTS
                    if(xml->selectChild("joints")){
                        edk::uint32 size = 0u;edkEnd();
                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                        if(temp){
                            size = edk::String::strToInt64(temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        //object vectors
                        bool collide;edkEnd();
                        edk::vec2f32 worldPosition;edkEnd();
                        edk::vec2f32 positionA;edkEnd();
                        edk::vec2f32 positionB;edkEnd();
                        for(edk::uint32 i = 0u;i<size;i++){
                            collide=false;edkEnd();
                            edk::Cenario2D::PhysicsPosition objectA;edkEnd();
                            edk::Cenario2D::PhysicsPosition objectB;edkEnd();
                            idTemp = edk::String::int64ToStr(i);edkEnd();
                            if(idTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"joint_",idTemp);edkEnd();
                                if(nameTemp){
                                    //create the xmlNode
                                    if(xml->selectChild(nameTemp)){
                                        //read the type
                                        edk::uint8 jointType = 0u;edkEnd();
                                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                                        if(temp){
                                            jointType = edk::String::strToInt32(temp);edkEnd();
                                            delete[] temp;edkEnd();
                                        }
                                        //read the objects
                                        objectA.readFromXML(xml,true);edkEnd();
                                        objectB.readFromXML(xml,false);edkEnd();
                                        //ret collide
                                        if(xml->getSelectedAttributeValueByName("collide")){
                                            collide=true;edkEnd();
                                        }
                                        //getWorldPosition
                                        worldPosition = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionAX")),
                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionAY")));edkEnd();
                                        positionA = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionAX")),
                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionAY")));edkEnd();
                                        positionB = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionBX")),
                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionBY")));edkEnd();

                                        switch(jointType){
                                        case EDK_JOINT:
                                            //add the joint
                                            //                                            this->world.createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                        this->getPhysicsObjectInLevel(objectB),
                                            //                                                                        worldPosition,
                                            //                                                                        collide
                                            //                                                                        );edkEnd();
                                            this->world.createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        collide
                                                                        );edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                     );edkEnd();
                                                this->world.createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                     positionA,
                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                                                     positionB,
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerAngle")),
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperAngle")),
                                                                                     collide
                                                                                     );edkEnd();
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
                                                //                                                                                     );edkEnd();
                                                this->world.createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                     positionA,
                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                                                     positionB,
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                     collide
                                                                                     );edkEnd();
                                            }
                                            else if(edk::String::strCompare(xml->getSelectedAttributeValueByName("type"),"NORMAL")){
                                                //
                                                //                                                this->world.createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                worldPosition,
                                                //                                                                                collide
                                                //                                                                                );edkEnd();
                                                this->world.createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                positionA,
                                                                                this->getPhysicsObjectInLevel(objectB),
                                                                                positionB,
                                                                                collide
                                                                                );edkEnd();
                                            }
                                            break;edkEnd();
                                        case EDK_DISTANCE_JOINT:
                                            //create distanceJoint
                                            //                                            this->world.createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                            worldPosition,
                                            //                                                                            this->getPhysicsObjectInLevel(objectB),
                                            //                                                                            edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBX")),
                                            //                                                                                         edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBY"))
                                            //                                                                                         ),
                                            //                                                                            collide);edkEnd();
                                            this->world.createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                                                            positionA,
                                                                            this->getPhysicsObjectInLevel(objectB),
                                                                            positionB,
                                                                            edk::String::strToFloat32(xml->getSelectedAttributeValueByName("distance")),
                                                                            collide);edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                      );edkEnd();
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
                                                                                      );edkEnd();
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
                                                //                                                                                 );edkEnd();
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
                                                                                 );edkEnd();
                                            }
                                            break;edkEnd();
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
                                            //                                                                               );edkEnd();
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
                                                                          );edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                  collide
                                                //                                                                                  );edkEnd();
                                                this->world.createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                  positionA,
                                                                                  this->getPhysicsObjectInLevel(objectB),
                                                                                  positionB,
                                                                                  edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                               ),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                  collide
                                                                                  );edkEnd();
                                            }
                                            else{
                                                //
                                                //                                                this->world.createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                             this->getPhysicsObjectInLevel(objectB),
                                                //                                                                             worldPosition,
                                                //                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                          ),
                                                //                                                                             collide
                                                //                                                                             );edkEnd();
                                                this->world.createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                                             positionA,
                                                                             this->getPhysicsObjectInLevel(objectB),
                                                                             positionB,
                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                          ),
                                                                             collide
                                                                             );edkEnd();
                                            }
                                            break;edkEnd();
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
                                            //                                                                                      );edkEnd();
                                            //REMOVED IN NEW BOX2D
                                            /*
                                            this->world.createRopeJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
                                                                        collide
                                                                        );edkEnd();
                                            */
                                            break;edkEnd();
                                        }
                                    }
                                    delete[] nameTemp;edkEnd();
                                }
                                delete[] idTemp;edkEnd();
                            }
                        }
                    }

                    //ACTIONS
                    this->actions.readFromXML(xml,0u,this);edkEnd();

                    ret=true;edkEnd();
                    xml->selectFather();edkEnd();

                    //generate the quadtree position and size
                    {
                        edk::uint32 size = this->levels.size();edkEnd();
                        edk::Cenario2D::LevelObj* level=NULL;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            level=this->levels[i];edkEnd();
                            if(level){
                                level->generateLevelRect();edkEnd();
                                level->addObjectsToQuad();edkEnd();
                            }
                        }
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
bool edk::Cenario2D::readFromXMLFromPack(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 id){
    return this->readFromXMLFromPack(pack,(edk::char8*) fileName,id);edkEnd();
}
bool edk::Cenario2D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 id){
    //load the XML file
    if(fileName && pack){
        edk::XML xml;edkEnd();
        if(pack->readFileToBuffer(fileName)){
            if(xml.loadFromMemory(pack->getBuffer(),pack->getBufferSize())){
                //load the cenario from the XML file
                return this->readFromXMLFromPack(pack,&xml,id);edkEnd();
            }
        }
    }
    return false;
}
//read level from XML
bool edk::Cenario2D::readLevelFromXML(edk::XML* xml,edk::uint32 level,edk::uint32 id){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Cenario_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* nameTemp;edkEnd();
                    edk::char8* idTemp;edkEnd();
                    edk::char8* temp;edkEnd();

                    if(xml->selectChild("meters")){
                        this->world.setMeterDistance(xml->getSelectedStringAsFloat32());edkEnd();
                        xml->selectFather();edkEnd();
                    }

                    //read tileSet
                    this->tileSet.readFromXML(xml,0u);edkEnd();
                    //read the levels
                    if(xml->selectChild("levels")){

                        //this->deleteAllLevels();edkEnd();
                        edk::uint32 size = 0u;edkEnd();
                        edk::uint32 levelsSize = this->levels.size();edkEnd();
                        edk::uint32 size1 = 0u;edkEnd();
                        edk::uint32 size2 = 0u;edkEnd();

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                        if(temp){
                            size = edk::String::strToInt64(temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        edk::Cenario2D::LevelObj* levelTemp;edkEnd();
                        //test if the size is smaller
                        if(size<levelsSize){
                            //size<levelsSize
                            size1=size;edkEnd();
                            size2=size1;edkEnd();
                        }
                        else if(size==levelsSize){
                            //size==levelsSize
                            size1=size;edkEnd();
                            size2=size1;edkEnd();
                        }
                        else{
                            //size>levelsSize
                            size1=levelsSize;edkEnd();
                            size2=size;edkEnd();
                        }
                        //just load the levels
                        for(edk::uint32 i=0u;i<size1;i++){
                            //load the levelTemp
                            levelTemp = this->levels.get(i);edkEnd();
                            if(levelTemp){
                                //test if the levelTemp position is the level
                                if(i == level){
                                    this->deleteLevel(i+1);edkEnd();
                                    levelTemp->readFromXML(xml,i,&this->tileSet,&this->world);edkEnd();
                                }
                            }
                        }
                        //create the levels
                        for(edk::uint32 i=size1;i<size2;i++){
                            //load the levelTemp
                            levelTemp = new edk::Cenario2D::LevelObj(&this->calls);edkEnd();
                            if(levelTemp){
                                //add the levelTemp to the tree
                                this->levels.pushBack(levelTemp);edkEnd();
                                //test if the levelTemp position is the level
                                if(i == level){
                                    levelTemp->readFromXML(xml,i,&this->tileSet,&this->world);edkEnd();
                                }
                            }
                        }
                        this->loadPhysicObjectsToWorld();edkEnd();
                        xml->selectFather();edkEnd();
                    }

                    //JOINTS
                    if(xml->selectChild("joints")){
                        edk::uint32 size = 0u;edkEnd();
                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                        if(temp){
                            size = edk::String::strToInt64(temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        //object vectors
                        bool collide;edkEnd();
                        edk::vec2f32 worldPosition;edkEnd();
                        edk::vec2f32 positionA;edkEnd();
                        edk::vec2f32 positionB;edkEnd();
                        for(edk::uint32 i = 0u;i<size;i++){
                            collide=false;edkEnd();
                            edk::Cenario2D::PhysicsPosition objectA;edkEnd();
                            edk::Cenario2D::PhysicsPosition objectB;edkEnd();
                            idTemp = edk::String::int64ToStr(i);edkEnd();
                            if(idTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"joint_",idTemp);edkEnd();
                                if(nameTemp){
                                    //create the xmlNode
                                    if(xml->selectChild(nameTemp)){
                                        //read the type
                                        edk::uint8 jointType = 0u;edkEnd();
                                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                                        if(temp){
                                            jointType = edk::String::strToInt32(temp);edkEnd();
                                            delete[] temp;edkEnd();
                                        }
                                        //read the objects
                                        objectA.readFromXML(xml,true);edkEnd();
                                        objectB.readFromXML(xml,false);edkEnd();
                                        //ret collide
                                        if(xml->getSelectedAttributeValueByName("collide")){
                                            collide=true;edkEnd();
                                        }
                                        //getWorldPosition
                                        worldPosition = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionAX")),
                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionAY")));edkEnd();
                                        positionA = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionAX")),
                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionAY")));edkEnd();
                                        positionB = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionBX")),
                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionBY")));edkEnd();

                                        switch(jointType){
                                        case EDK_JOINT:
                                            //add the joint
                                            //                                            this->world.createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                        this->getPhysicsObjectInLevel(objectB),
                                            //                                                                        worldPosition,
                                            //                                                                        collide
                                            //                                                                        );edkEnd();
                                            this->world.createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        collide
                                                                        );edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                     );edkEnd();
                                                this->world.createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                     positionA,
                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                                                     positionB,
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerAngle")),
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperAngle")),
                                                                                     collide
                                                                                     );edkEnd();
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
                                                //                                                                                     );edkEnd();
                                                this->world.createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                     positionA,
                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                                                     positionB,
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                     collide
                                                                                     );edkEnd();
                                            }
                                            else if(edk::String::strCompare(xml->getSelectedAttributeValueByName("type"),"NORMAL")){
                                                //
                                                //                                                this->world.createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                worldPosition,
                                                //                                                                                collide
                                                //                                                                                );edkEnd();
                                                this->world.createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                positionA,
                                                                                this->getPhysicsObjectInLevel(objectB),
                                                                                positionB,
                                                                                collide
                                                                                );edkEnd();
                                            }
                                            break;edkEnd();
                                        case EDK_DISTANCE_JOINT:
                                            //create distanceJoint
                                            //                                            this->world.createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                            worldPosition,
                                            //                                                                            this->getPhysicsObjectInLevel(objectB),
                                            //                                                                            edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBX")),
                                            //                                                                                         edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBY"))
                                            //                                                                                         ),
                                            //                                                                            collide);edkEnd();
                                            this->world.createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                                                            positionA,
                                                                            this->getPhysicsObjectInLevel(objectB),
                                                                            positionB,
                                                                            edk::String::strToFloat32(xml->getSelectedAttributeValueByName("distance")),
                                                                            collide);edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                      );edkEnd();
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
                                                                                      );edkEnd();
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
                                                //                                                                                 );edkEnd();
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
                                                                                 );edkEnd();
                                            }
                                            break;edkEnd();
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
                                            //                                                                               );edkEnd();
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
                                                                          );edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                  collide
                                                //                                                                                  );edkEnd();
                                                this->world.createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                  positionA,
                                                                                  this->getPhysicsObjectInLevel(objectB),
                                                                                  positionB,
                                                                                  edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                               ),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                  collide
                                                                                  );edkEnd();
                                            }
                                            else{
                                                //
                                                //                                                this->world.createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                             this->getPhysicsObjectInLevel(objectB),
                                                //                                                                             worldPosition,
                                                //                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                          ),
                                                //                                                                             collide
                                                //                                                                             );edkEnd();
                                                this->world.createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                                             positionA,
                                                                             this->getPhysicsObjectInLevel(objectB),
                                                                             positionB,
                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                          ),
                                                                             collide
                                                                             );edkEnd();
                                            }
                                            break;edkEnd();
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
                                            //                                                                                      );edkEnd();
                                            //REMOVED IN NEW BOX2D
                                            /*
                                            this->world.createRopeJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
                                                                        collide
                                                                        );edkEnd();
                                            */
                                            break;edkEnd();
                                        }
                                    }
                                    delete[] nameTemp;edkEnd();
                                }
                                delete[] idTemp;edkEnd();
                            }
                        }
                    }

                    //ACTIONS
                    this->actions.readFromXML(xml,0u,this);edkEnd();

                    ret=true;edkEnd();
                    xml->selectFather();edkEnd();

                    //generate the quadtree position and size
                    {
                        edk::uint32 size = this->levels.size();edkEnd();
                        edk::Cenario2D::LevelObj* level=NULL;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            level=this->levels[i];edkEnd();
                            if(level){
                                level->generateLevelRect();edkEnd();
                                level->addObjectsToQuad();edkEnd();
                            }
                        }
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
bool edk::Cenario2D::readLevelFromXML(const edk::char8* fileName,edk::uint32 level,edk::uint32 id){
    return this->readLevelFromXML((edk::char8*) fileName,level,id);edkEnd();
}
bool edk::Cenario2D::readLevelFromXML(edk::char8* fileName,edk::uint32 level,edk::uint32 id){
    //load the XML file
    if(fileName){
        edk::XML xml;edkEnd();
        if(xml.loadFile(fileName)){
            //load the cenario from the XML file
            return this->readLevelFromXML(&xml,level,id);edkEnd();
        }
    }
    return false;
}
bool edk::Cenario2D::readLevelFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 level,edk::uint32 id){
    if(xml && pack){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Cenario_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* nameTemp;edkEnd();
                    edk::char8* idTemp;edkEnd();
                    edk::char8* temp;edkEnd();

                    if(xml->selectChild("meters")){
                        this->world.setMeterDistance(xml->getSelectedStringAsFloat32());edkEnd();
                        xml->selectFather();edkEnd();
                    }

                    //read tileSet
                    this->tileSet.readFromXMLFromPack(pack,xml,0u);edkEnd();
                    //read the levels
                    if(xml->selectChild("levels")){

                        //this->deleteAllLevels();edkEnd();
                        edk::uint32 size = 0u;edkEnd();
                        edk::uint32 levelsSize = this->levels.size();edkEnd();
                        edk::uint32 size1 = 0u;edkEnd();
                        edk::uint32 size2 = 0u;edkEnd();

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                        if(temp){
                            size = edk::String::strToInt64(temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        edk::Cenario2D::LevelObj* levelTemp;edkEnd();
                        //test if the size is smaller
                        if(size<levelsSize){
                            //size<levelsSize
                            size1=size;edkEnd();
                            size2=size1;edkEnd();
                        }
                        else if(size==levelsSize){
                            //size==levelsSize
                            size1=size;edkEnd();
                            size2=size1;edkEnd();
                        }
                        else{
                            //size>levelsSize
                            size1=levelsSize;edkEnd();
                            size2=size;edkEnd();
                        }
                        //just load the levels
                        for(edk::uint32 i=0u;i<size1;i++){
                            //load the levelTemp
                            levelTemp = this->levels.get(i);edkEnd();
                            if(levelTemp){
                                //test if the levelTemp position is the level
                                if(i == level){
                                    this->deleteLevel(i+1);edkEnd();
                                    levelTemp->readFromXMLFromPack(pack,xml,i,&this->tileSet,&this->world);edkEnd();
                                }
                            }
                        }
                        //create the levels
                        for(edk::uint32 i=size1;i<size2;i++){
                            //load the levelTemp
                            levelTemp = new edk::Cenario2D::LevelObj(&this->calls);edkEnd();
                            if(levelTemp){
                                //add the levelTemp to the tree
                                this->levels.pushBack(levelTemp);edkEnd();
                                //test if the levelTemp position is the level
                                if(i == level){
                                    levelTemp->readFromXMLFromPack(pack,xml,i,&this->tileSet,&this->world);edkEnd();
                                }
                            }
                        }
                        this->loadPhysicObjectsToWorld();edkEnd();
                        xml->selectFather();edkEnd();
                    }

                    //JOINTS
                    if(xml->selectChild("joints")){
                        edk::uint32 size = 0u;edkEnd();
                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                        if(temp){
                            size = edk::String::strToInt64(temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        //object vectors
                        bool collide;edkEnd();
                        edk::vec2f32 worldPosition;edkEnd();
                        edk::vec2f32 positionA;edkEnd();
                        edk::vec2f32 positionB;edkEnd();
                        for(edk::uint32 i = 0u;i<size;i++){
                            collide=false;edkEnd();
                            edk::Cenario2D::PhysicsPosition objectA;edkEnd();
                            edk::Cenario2D::PhysicsPosition objectB;edkEnd();
                            idTemp = edk::String::int64ToStr(i);edkEnd();
                            if(idTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"joint_",idTemp);edkEnd();
                                if(nameTemp){
                                    //create the xmlNode
                                    if(xml->selectChild(nameTemp)){
                                        //read the type
                                        edk::uint8 jointType = 0u;edkEnd();
                                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                                        if(temp){
                                            jointType = edk::String::strToInt32(temp);edkEnd();
                                            delete[] temp;edkEnd();
                                        }
                                        //read the objects
                                        objectA.readFromXML(xml,true);edkEnd();
                                        objectB.readFromXML(xml,false);edkEnd();
                                        //ret collide
                                        if(xml->getSelectedAttributeValueByName("collide")){
                                            collide=true;edkEnd();
                                        }
                                        //getWorldPosition
                                        worldPosition = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionAX")),
                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionAY")));edkEnd();
                                        positionA = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionAX")),
                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionAY")));edkEnd();
                                        positionB = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionBX")),
                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionBY")));edkEnd();

                                        switch(jointType){
                                        case EDK_JOINT:
                                            //add the joint
                                            //                                            this->world.createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                        this->getPhysicsObjectInLevel(objectB),
                                            //                                                                        worldPosition,
                                            //                                                                        collide
                                            //                                                                        );edkEnd();
                                            this->world.createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        collide
                                                                        );edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                     );edkEnd();
                                                this->world.createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                     positionA,
                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                                                     positionB,
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerAngle")),
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperAngle")),
                                                                                     collide
                                                                                     );edkEnd();
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
                                                //                                                                                     );edkEnd();
                                                this->world.createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                     positionA,
                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                                                     positionB,
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                     collide
                                                                                     );edkEnd();
                                            }
                                            else if(edk::String::strCompare(xml->getSelectedAttributeValueByName("type"),"NORMAL")){
                                                //
                                                //                                                this->world.createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                worldPosition,
                                                //                                                                                collide
                                                //                                                                                );edkEnd();
                                                this->world.createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                positionA,
                                                                                this->getPhysicsObjectInLevel(objectB),
                                                                                positionB,
                                                                                collide
                                                                                );edkEnd();
                                            }
                                            break;edkEnd();
                                        case EDK_DISTANCE_JOINT:
                                            //create distanceJoint
                                            //                                            this->world.createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                            worldPosition,
                                            //                                                                            this->getPhysicsObjectInLevel(objectB),
                                            //                                                                            edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBX")),
                                            //                                                                                         edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBY"))
                                            //                                                                                         ),
                                            //                                                                            collide);edkEnd();
                                            this->world.createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                                                            positionA,
                                                                            this->getPhysicsObjectInLevel(objectB),
                                                                            positionB,
                                                                            edk::String::strToFloat32(xml->getSelectedAttributeValueByName("distance")),
                                                                            collide);edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                      );edkEnd();
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
                                                                                      );edkEnd();
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
                                                //                                                                                 );edkEnd();
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
                                                                                 );edkEnd();
                                            }
                                            break;edkEnd();
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
                                            //                                                                               );edkEnd();
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
                                                                          );edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                  collide
                                                //                                                                                  );edkEnd();
                                                this->world.createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                  positionA,
                                                                                  this->getPhysicsObjectInLevel(objectB),
                                                                                  positionB,
                                                                                  edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                               ),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                  collide
                                                                                  );edkEnd();
                                            }
                                            else{
                                                //
                                                //                                                this->world.createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                             this->getPhysicsObjectInLevel(objectB),
                                                //                                                                             worldPosition,
                                                //                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                          ),
                                                //                                                                             collide
                                                //                                                                             );edkEnd();
                                                this->world.createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                                             positionA,
                                                                             this->getPhysicsObjectInLevel(objectB),
                                                                             positionB,
                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                          ),
                                                                             collide
                                                                             );edkEnd();
                                            }
                                            break;edkEnd();
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
                                            //                                                                                      );edkEnd();
                                            //REMOVED IN NEW BOX2D
                                            /*
                                            this->world.createRopeJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
                                                                        collide
                                                                        );edkEnd();
                                            */
                                            break;edkEnd();
                                        }
                                    }
                                    delete[] nameTemp;edkEnd();
                                }
                                delete[] idTemp;edkEnd();
                            }
                        }
                    }

                    //ACTIONS
                    this->actions.readFromXML(xml,0u,this);edkEnd();

                    ret=true;edkEnd();
                    xml->selectFather();edkEnd();

                    //generate the quadtree position and size
                    {
                        edk::uint32 size = this->levels.size();edkEnd();
                        edk::Cenario2D::LevelObj* level=NULL;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            level=this->levels[i];edkEnd();
                            if(level){
                                level->generateLevelRect();edkEnd();
                                level->addObjectsToQuad();edkEnd();
                            }
                        }
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
bool edk::Cenario2D::readLevelFromXMLFromPack(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 level,edk::uint32 id){
    return this->readLevelFromXMLFromPack(pack,(edk::char8*) fileName,level,id);edkEnd();
}
bool edk::Cenario2D::readLevelFromXMLFromPack(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 level,edk::uint32 id){
    //load the XML file
    if(fileName && pack){
        edk::XML xml;edkEnd();
        if(pack->readFileToBuffer(fileName)){
            if(xml.loadFromMemory(pack->getBuffer(),pack->getBufferSize())){
                //load the cenario from the XML file
                return this->readLevelFromXMLFromPack(pack,&xml,level,id);edkEnd();
            }
        }
    }
    return false;
}
//read from XML without load physics objects in to the world
bool edk::Cenario2D::readFromXMLWithoutLoadPhysics(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Cenario_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* nameTemp;edkEnd();
                    edk::char8* idTemp;edkEnd();
                    edk::char8* temp;edkEnd();

                    if(xml->selectChild("meters")){
                        this->world.setMeterDistance(xml->getSelectedStringAsFloat32());edkEnd();
                        xml->selectFather();edkEnd();
                    }

                    //read tileSet
                    this->tileSet.readFromXML(xml,0u);edkEnd();
                    //read the levels
                    if(xml->selectChild("levels")){

                        this->deleteAllLevels();edkEnd();
                        edk::uint32 size = 0u;edkEnd();

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                        if(temp){
                            size = edk::String::strToInt64(temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        edk::Cenario2D::LevelObj* level;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            //load the level
                            level = new edk::Cenario2D::LevelObj(&this->calls);edkEnd();
                            if(level){
                                //add the level to the tree
                                this->levels.pushBack(level);edkEnd();
                                level->readFromXML(xml,i,&this->tileSet,&this->world);edkEnd();
                            }
                        }
                        //this->loadPhysicObjectsToWorld();edkEnd();
                        xml->selectFather();edkEnd();
                    }
                    /*
                    //JOINTS
                    if(xml->selectChild("joints")){
                        edk::uint32 size = 0u;edkEnd();
                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                        if(temp){
                            size = edk::String::strToInt64(temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        //object vectors
                        bool collide;edkEnd();
                        edk::vec2f32 worldPosition;edkEnd();
                        edk::vec2f32 positionA;edkEnd();
                        edk::vec2f32 positionB;edkEnd();
                        for(edk::uint32 i = 0u;i<size;i++){
                            collide=false;edkEnd();
                            edk::Cenario2D::PhysicsPosition objectA;edkEnd();
                            edk::Cenario2D::PhysicsPosition objectB;edkEnd();
                            idTemp = edk::String::int64ToStr(i);edkEnd();
                            if(idTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"joint_",idTemp);edkEnd();
                                if(nameTemp){
                                    //create the xmlNode
                                    if(xml->selectChild(nameTemp)){
                                        //read the type
                                        edk::uint8 jointType = 0u;edkEnd();
                                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                                        if(temp){
                                            jointType = edk::String::strToInt32(temp);edkEnd();
                                            delete[] temp;edkEnd();
                                        }
                                        //read the objects
                                        objectA.readFromXML(xml,true);edkEnd();
                                        objectB.readFromXML(xml,false);edkEnd();
                                        //ret collide
                                        if(xml->getSelectedAttributeValueByName("collide")){
                                            collide=true;edkEnd();
                                        }
                                        //getWorldPosition
                                        worldPosition = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionAX")),
                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionAY")));edkEnd();
                                        positionA = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionAX")),
                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionAY")));edkEnd();
                                        positionB = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionBX")),
                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionBY")));edkEnd();

                                        switch(jointType){
                                        case EDK_JOINT:
                                            //add the joint
                                            //                                            this->world.createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                        this->getPhysicsObjectInLevel(objectB),
                                            //                                                                        worldPosition,
                                            //                                                                        collide
                                            //                                                                        );edkEnd();
                                            this->world.createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        collide
                                                                        );edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                     );edkEnd();
                                                this->world.createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                     positionA,
                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                                                     positionB,
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerAngle")),
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperAngle")),
                                                                                     collide
                                                                                     );edkEnd();
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
                                                //                                                                                     );edkEnd();
                                                this->world.createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                     positionA,
                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                                                     positionB,
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                     collide
                                                                                     );edkEnd();
                                            }
                                            else if(edk::String::strCompare(xml->getSelectedAttributeValueByName("type"),"NORMAL")){
                                                //
                                                //                                                this->world.createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                worldPosition,
                                                //                                                                                collide
                                                //                                                                                );edkEnd();
                                                this->world.createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                positionA,
                                                                                this->getPhysicsObjectInLevel(objectB),
                                                                                positionB,
                                                                                collide
                                                                                );edkEnd();
                                            }
                                            break;edkEnd();
                                        case EDK_DISTANCE_JOINT:
                                            //create distanceJoint
                                            //                                            this->world.createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                            worldPosition,
                                            //                                                                            this->getPhysicsObjectInLevel(objectB),
                                            //                                                                            edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBX")),
                                            //                                                                                         edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBY"))
                                            //                                                                                         ),
                                            //                                                                            collide);edkEnd();
                                            this->world.createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                                                            positionA,
                                                                            this->getPhysicsObjectInLevel(objectB),
                                                                            positionB,
                                                                            edk::String::strToFloat32(xml->getSelectedAttributeValueByName("distance")),
                                                                            collide);edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                      );edkEnd();
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
                                                                                      );edkEnd();
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
                                                //                                                                                 );edkEnd();
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
                                                                                 );edkEnd();
                                            }
                                            break;edkEnd();
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
                                            //                                                                               );edkEnd();
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
                                                                          );edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                  collide
                                                //                                                                                  );edkEnd();
                                                this->world.createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                  positionA,
                                                                                  this->getPhysicsObjectInLevel(objectB),
                                                                                  positionB,
                                                                                  edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                               ),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                  collide
                                                                                  );edkEnd();
                                            }
                                            else{
                                                //
                                                //                                                this->world.createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                             this->getPhysicsObjectInLevel(objectB),
                                                //                                                                             worldPosition,
                                                //                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                          ),
                                                //                                                                             collide
                                                //                                                                             );edkEnd();
                                                this->world.createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                                             positionA,
                                                                             this->getPhysicsObjectInLevel(objectB),
                                                                             positionB,
                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                          ),
                                                                             collide
                                                                             );edkEnd();
                                            }
                                            break;edkEnd();
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
                                            //                                                                                      );edkEnd();
                                            //REMOVED IN NEW BOX2D

//                                            this->world.createRopeJoint(this->getPhysicsObjectInLevel(objectA),
//                                                                        positionA,
//                                                                        this->getPhysicsObjectInLevel(objectB),
//                                                                        positionB,
//                                                                        edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
//                                                                        collide
//                                                                        );edkEnd();

                                            break;edkEnd();
                                        }
                                    }
                                    delete[] nameTemp;edkEnd();
                                }
                                delete[] idTemp;edkEnd();
                            }
                        }
                    }
*/
                    //ACTIONS
                    this->actions.readFromXML(xml,0u,this);edkEnd();

                    ret=true;edkEnd();
                    xml->selectFather();edkEnd();

                    //generate the quadtree position and size
                    {
                        edk::uint32 size = this->levels.size();edkEnd();
                        edk::Cenario2D::LevelObj* level=NULL;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            level=this->levels[i];edkEnd();
                            if(level){
                                level->generateLevelRect();edkEnd();
                                level->addObjectsToQuad();edkEnd();
                            }
                        }
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
bool edk::Cenario2D::readFromXMLWithoutLoadPhysics(const edk::char8* fileName,edk::uint32 id){
    return this->readFromXMLWithoutLoadPhysics((edk::char8*) fileName,id);edkEnd();
}
bool edk::Cenario2D::readFromXMLWithoutLoadPhysics(edk::char8* fileName,edk::uint32 id){
    //load the XML file
    if(fileName){
        edk::XML xml;edkEnd();
        if(xml.loadFile(fileName)){
            //load the cenario from the XML file
            return this->readFromXMLWithoutLoadPhysics(&xml,id);edkEnd();
        }
    }
    return false;
}
bool edk::Cenario2D::readFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    if(xml && pack){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Cenario_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* nameTemp;edkEnd();
                    edk::char8* idTemp;edkEnd();
                    edk::char8* temp;edkEnd();

                    if(xml->selectChild("meters")){
                        this->world.setMeterDistance(xml->getSelectedStringAsFloat32());edkEnd();
                        xml->selectFather();edkEnd();
                    }

                    //read tileSet
                    this->tileSet.readFromXMLFromPack(pack,xml,0u);edkEnd();
                    //read the levels
                    if(xml->selectChild("levels")){

                        this->deleteAllLevels();edkEnd();
                        edk::uint32 size = 0u;edkEnd();

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                        if(temp){
                            size = edk::String::strToInt64(temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        edk::Cenario2D::LevelObj* level;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            //load the level
                            level = new edk::Cenario2D::LevelObj(&this->calls);edkEnd();
                            if(level){
                                //add the level to the tree
                                this->levels.pushBack(level);edkEnd();
                                level->readFromXMLFromPack(pack,xml,i,&this->tileSet,&this->world);edkEnd();
                            }
                        }
                        //this->loadPhysicObjectsToWorld();edkEnd();
                        xml->selectFather();edkEnd();
                    }
                    /*
                    //JOINTS
                    if(xml->selectChild("joints")){
                        edk::uint32 size = 0u;edkEnd();
                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                        if(temp){
                            size = edk::String::strToInt64(temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        //object vectors
                        bool collide;edkEnd();
                        edk::vec2f32 worldPosition;edkEnd();
                        edk::vec2f32 positionA;edkEnd();
                        edk::vec2f32 positionB;edkEnd();
                        for(edk::uint32 i = 0u;i<size;i++){
                            collide=false;edkEnd();
                            edk::Cenario2D::PhysicsPosition objectA;edkEnd();
                            edk::Cenario2D::PhysicsPosition objectB;edkEnd();
                            idTemp = edk::String::int64ToStr(i);edkEnd();
                            if(idTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"joint_",idTemp);edkEnd();
                                if(nameTemp){
                                    //create the xmlNode
                                    if(xml->selectChild(nameTemp)){
                                        //read the type
                                        edk::uint8 jointType = 0u;edkEnd();
                                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                                        if(temp){
                                            jointType = edk::String::strToInt32(temp);edkEnd();
                                            delete[] temp;edkEnd();
                                        }
                                        //read the objects
                                        objectA.readFromXML(xml,true);edkEnd();
                                        objectB.readFromXML(xml,false);edkEnd();
                                        //ret collide
                                        if(xml->getSelectedAttributeValueByName("collide")){
                                            collide=true;edkEnd();
                                        }
                                        //getWorldPosition
                                        worldPosition = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionAX")),
                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionAY")));edkEnd();
                                        positionA = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionAX")),
                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionAY")));edkEnd();
                                        positionB = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionBX")),
                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionBY")));edkEnd();

                                        switch(jointType){
                                        case EDK_JOINT:
                                            //add the joint
                                            //                                            this->world.createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                        this->getPhysicsObjectInLevel(objectB),
                                            //                                                                        worldPosition,
                                            //                                                                        collide
                                            //                                                                        );edkEnd();
                                            this->world.createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        collide
                                                                        );edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                     );edkEnd();
                                                this->world.createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                     positionA,
                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                                                     positionB,
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerAngle")),
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperAngle")),
                                                                                     collide
                                                                                     );edkEnd();
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
                                                //                                                                                     );edkEnd();
                                                this->world.createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                     positionA,
                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                                                     positionB,
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                     collide
                                                                                     );edkEnd();
                                            }
                                            else if(edk::String::strCompare(xml->getSelectedAttributeValueByName("type"),"NORMAL")){
                                                //
                                                //                                                this->world.createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                worldPosition,
                                                //                                                                                collide
                                                //                                                                                );edkEnd();
                                                this->world.createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                positionA,
                                                                                this->getPhysicsObjectInLevel(objectB),
                                                                                positionB,
                                                                                collide
                                                                                );edkEnd();
                                            }
                                            break;edkEnd();
                                        case EDK_DISTANCE_JOINT:
                                            //create distanceJoint
                                            //                                            this->world.createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                            worldPosition,
                                            //                                                                            this->getPhysicsObjectInLevel(objectB),
                                            //                                                                            edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBX")),
                                            //                                                                                         edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBY"))
                                            //                                                                                         ),
                                            //                                                                            collide);edkEnd();
                                            this->world.createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                                                            positionA,
                                                                            this->getPhysicsObjectInLevel(objectB),
                                                                            positionB,
                                                                            edk::String::strToFloat32(xml->getSelectedAttributeValueByName("distance")),
                                                                            collide);edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                      );edkEnd();
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
                                                                                      );edkEnd();
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
                                                //                                                                                 );edkEnd();
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
                                                                                 );edkEnd();
                                            }
                                            break;edkEnd();
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
                                            //                                                                               );edkEnd();
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
                                                                          );edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                  collide
                                                //                                                                                  );edkEnd();
                                                this->world.createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                  positionA,
                                                                                  this->getPhysicsObjectInLevel(objectB),
                                                                                  positionB,
                                                                                  edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                               ),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                  collide
                                                                                  );edkEnd();
                                            }
                                            else{
                                                //
                                                //                                                this->world.createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                             this->getPhysicsObjectInLevel(objectB),
                                                //                                                                             worldPosition,
                                                //                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                          ),
                                                //                                                                             collide
                                                //                                                                             );edkEnd();
                                                this->world.createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                                             positionA,
                                                                             this->getPhysicsObjectInLevel(objectB),
                                                                             positionB,
                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                          ),
                                                                             collide
                                                                             );edkEnd();
                                            }
                                            break;edkEnd();
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
                                            //                                                                                      );edkEnd();
                                            //REMOVED IN NEW BOX2D

//                                            this->world.createRopeJoint(this->getPhysicsObjectInLevel(objectA),
//                                                                        positionA,
//                                                                        this->getPhysicsObjectInLevel(objectB),
//                                                                        positionB,
//                                                                        edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
//                                                                        collide
//                                                                        );edkEnd();

                                            break;edkEnd();
                                        }
                                    }
                                    delete[] nameTemp;edkEnd();
                                }
                                delete[] idTemp;edkEnd();
                            }
                        }
                    }
*/
                    //ACTIONS
                    this->actions.readFromXML(xml,0u,this);edkEnd();

                    ret=true;edkEnd();
                    xml->selectFather();edkEnd();

                    //generate the quadtree position and size
                    {
                        edk::uint32 size = this->levels.size();edkEnd();
                        edk::Cenario2D::LevelObj* level=NULL;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            level=this->levels[i];edkEnd();
                            if(level){
                                level->generateLevelRect();edkEnd();
                                level->addObjectsToQuad();edkEnd();
                            }
                        }
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
bool edk::Cenario2D::readFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 id){
    return this->readFromXMLFromPackWithoutLoadPhysics(pack,(edk::char8*) fileName,id);edkEnd();
}
bool edk::Cenario2D::readFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 id){
    //load the XML file
    if(fileName && pack){
        edk::XML xml;edkEnd();
        if(pack->readFileToBuffer(fileName)){
            if(xml.loadFromMemory(pack->getBuffer(),pack->getBufferSize())){
                //load the cenario from the XML file
                return this->readFromXMLFromPackWithoutLoadPhysics(pack,&xml,id);edkEnd();
            }
        }
    }
    return false;
}
//read level from XML without load physics objects in to the world
bool edk::Cenario2D::readLevelFromXMLWithoutLoadPhysics(edk::XML* xml,edk::uint32 level,edk::uint32 id){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Cenario_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* nameTemp;edkEnd();
                    edk::char8* idTemp;edkEnd();
                    edk::char8* temp;edkEnd();

                    if(xml->selectChild("meters")){
                        this->world.setMeterDistance(xml->getSelectedStringAsFloat32());edkEnd();
                        xml->selectFather();edkEnd();
                    }

                    //read tileSet
                    this->tileSet.readFromXML(xml,0u);edkEnd();
                    //read the levels
                    if(xml->selectChild("levels")){

                        //this->deleteAllLevels();edkEnd();
                        edk::uint32 size = 0u;edkEnd();
                        edk::uint32 levelsSize = this->levels.size();edkEnd();
                        edk::uint32 size1 = 0u;edkEnd();
                        edk::uint32 size2 = 0u;edkEnd();

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                        if(temp){
                            size = edk::String::strToInt64(temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        edk::Cenario2D::LevelObj* levelTemp;edkEnd();
                        //test if the size is smaller
                        if(size<levelsSize){
                            //size<levelsSize
                            size1=size;edkEnd();
                            size2=size1;edkEnd();
                        }
                        else if(size==levelsSize){
                            //size==levelsSize
                            size1=size;edkEnd();
                            size2=size1;edkEnd();
                        }
                        else{
                            //size>levelsSize
                            size1=levelsSize;edkEnd();
                            size2=size;edkEnd();
                        }
                        //just load the levels
                        for(edk::uint32 i=0u;i<size1;i++){
                            //load the levelTemp
                            levelTemp = this->levels.get(i);edkEnd();
                            if(levelTemp){
                                //test if the levelTemp position is the level
                                if(i == level){
                                    this->deleteLevel(i+1);edkEnd();
                                    levelTemp->readFromXML(xml,i,&this->tileSet,&this->world);edkEnd();
                                }
                            }
                        }
                        //create the levels
                        for(edk::uint32 i=size1;i<size2;i++){
                            //load the levelTemp
                            levelTemp = new edk::Cenario2D::LevelObj(&this->calls);edkEnd();
                            if(levelTemp){
                                //add the levelTemp to the tree
                                this->levels.pushBack(levelTemp);edkEnd();
                                //test if the levelTemp position is the level
                                if(i == level){
                                    levelTemp->readFromXML(xml,i,&this->tileSet,&this->world);edkEnd();
                                }
                            }
                        }
                        //this->loadPhysicObjectsToWorld();edkEnd();
                        xml->selectFather();edkEnd();
                    }
                    /*
                    //JOINTS
                    if(xml->selectChild("joints")){
                        edk::uint32 size = 0u;edkEnd();
                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                        if(temp){
                            size = edk::String::strToInt64(temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        //object vectors
                        bool collide;edkEnd();
                        edk::vec2f32 worldPosition;edkEnd();
                        edk::vec2f32 positionA;edkEnd();
                        edk::vec2f32 positionB;edkEnd();
                        for(edk::uint32 i = 0u;i<size;i++){
                            collide=false;edkEnd();
                            edk::Cenario2D::PhysicsPosition objectA;edkEnd();
                            edk::Cenario2D::PhysicsPosition objectB;edkEnd();
                            idTemp = edk::String::int64ToStr(i);edkEnd();
                            if(idTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"joint_",idTemp);edkEnd();
                                if(nameTemp){
                                    //create the xmlNode
                                    if(xml->selectChild(nameTemp)){
                                        //read the type
                                        edk::uint8 jointType = 0u;edkEnd();
                                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                                        if(temp){
                                            jointType = edk::String::strToInt32(temp);edkEnd();
                                            delete[] temp;edkEnd();
                                        }
                                        //read the objects
                                        objectA.readFromXML(xml,true);edkEnd();
                                        objectB.readFromXML(xml,false);edkEnd();
                                        //ret collide
                                        if(xml->getSelectedAttributeValueByName("collide")){
                                            collide=true;edkEnd();
                                        }
                                        //getWorldPosition
                                        worldPosition = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionAX")),
                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionAY")));edkEnd();
                                        positionA = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionAX")),
                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionAY")));edkEnd();
                                        positionB = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionBX")),
                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionBY")));edkEnd();

                                        switch(jointType){
                                        case EDK_JOINT:
                                            //add the joint
                                            //                                            this->world.createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                        this->getPhysicsObjectInLevel(objectB),
                                            //                                                                        worldPosition,
                                            //                                                                        collide
                                            //                                                                        );edkEnd();
                                            this->world.createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        collide
                                                                        );edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                     );edkEnd();
                                                this->world.createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                     positionA,
                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                                                     positionB,
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerAngle")),
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperAngle")),
                                                                                     collide
                                                                                     );edkEnd();
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
                                                //                                                                                     );edkEnd();
                                                this->world.createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                     positionA,
                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                                                     positionB,
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                     collide
                                                                                     );edkEnd();
                                            }
                                            else if(edk::String::strCompare(xml->getSelectedAttributeValueByName("type"),"NORMAL")){
                                                //
                                                //                                                this->world.createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                worldPosition,
                                                //                                                                                collide
                                                //                                                                                );edkEnd();
                                                this->world.createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                positionA,
                                                                                this->getPhysicsObjectInLevel(objectB),
                                                                                positionB,
                                                                                collide
                                                                                );edkEnd();
                                            }
                                            break;edkEnd();
                                        case EDK_DISTANCE_JOINT:
                                            //create distanceJoint
                                            //                                            this->world.createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                            worldPosition,
                                            //                                                                            this->getPhysicsObjectInLevel(objectB),
                                            //                                                                            edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBX")),
                                            //                                                                                         edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBY"))
                                            //                                                                                         ),
                                            //                                                                            collide);edkEnd();
                                            this->world.createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                                                            positionA,
                                                                            this->getPhysicsObjectInLevel(objectB),
                                                                            positionB,
                                                                            edk::String::strToFloat32(xml->getSelectedAttributeValueByName("distance")),
                                                                            collide);edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                      );edkEnd();
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
                                                                                      );edkEnd();
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
                                                //                                                                                 );edkEnd();
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
                                                                                 );edkEnd();
                                            }
                                            break;edkEnd();
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
                                            //                                                                               );edkEnd();
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
                                                                          );edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                  collide
                                                //                                                                                  );edkEnd();
                                                this->world.createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                  positionA,
                                                                                  this->getPhysicsObjectInLevel(objectB),
                                                                                  positionB,
                                                                                  edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                               ),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                  collide
                                                                                  );edkEnd();
                                            }
                                            else{
                                                //
                                                //                                                this->world.createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                             this->getPhysicsObjectInLevel(objectB),
                                                //                                                                             worldPosition,
                                                //                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                          ),
                                                //                                                                             collide
                                                //                                                                             );edkEnd();
                                                this->world.createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                                             positionA,
                                                                             this->getPhysicsObjectInLevel(objectB),
                                                                             positionB,
                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                          ),
                                                                             collide
                                                                             );edkEnd();
                                            }
                                            break;edkEnd();
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
                                            //                                                                                      );edkEnd();
                                            //REMOVED IN NEW BOX2D

//                                            this->world.createRopeJoint(this->getPhysicsObjectInLevel(objectA),
//                                                                        positionA,
//                                                                        this->getPhysicsObjectInLevel(objectB),
//                                                                        positionB,
//                                                                        edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
//                                                                        collide
//                                                                        );edkEnd();

                                            break;edkEnd();
                                        }
                                    }
                                    delete[] nameTemp;edkEnd();
                                }
                                delete[] idTemp;edkEnd();
                            }
                        }
                    }
*/
                    //ACTIONS
                    this->actions.readFromXML(xml,0u,this);edkEnd();

                    ret=true;edkEnd();
                    xml->selectFather();edkEnd();

                    //generate the quadtree position and size
                    {
                        edk::uint32 size = this->levels.size();edkEnd();
                        edk::Cenario2D::LevelObj* level=NULL;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            level=this->levels[i];edkEnd();
                            if(level){
                                level->generateLevelRect();edkEnd();
                                level->addObjectsToQuad();edkEnd();
                            }
                        }
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
bool edk::Cenario2D::readLevelFromXMLWithoutLoadPhysics(const edk::char8* fileName,edk::uint32 level,edk::uint32 id){
    return this->readLevelFromXMLWithoutLoadPhysics((edk::char8*) fileName,level,id);edkEnd();
}
bool edk::Cenario2D::readLevelFromXMLWithoutLoadPhysics(edk::char8* fileName,edk::uint32 level,edk::uint32 id){
    //load the XML file
    if(fileName){
        edk::XML xml;edkEnd();
        if(xml.loadFile(fileName)){
            //load the cenario from the XML file
            return this->readLevelFromXMLWithoutLoadPhysics(&xml,level,id);edkEnd();
        }
    }
    return false;
}
bool edk::Cenario2D::readLevelFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 level,edk::uint32 id){
    if(xml && pack){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"Cenario_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* nameTemp;edkEnd();
                    edk::char8* idTemp;edkEnd();
                    edk::char8* temp;edkEnd();

                    if(xml->selectChild("meters")){
                        this->world.setMeterDistance(xml->getSelectedStringAsFloat32());edkEnd();
                        xml->selectFather();edkEnd();
                    }

                    //read tileSet
                    this->tileSet.readFromXMLFromPack(pack,xml,0u);edkEnd();
                    //read the levels
                    if(xml->selectChild("levels")){

                        //this->deleteAllLevels();edkEnd();
                        edk::uint32 size = 0u;edkEnd();
                        edk::uint32 levelsSize = this->levels.size();edkEnd();
                        edk::uint32 size1 = 0u;edkEnd();
                        edk::uint32 size2 = 0u;edkEnd();

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                        if(temp){
                            size = edk::String::strToInt64(temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        edk::Cenario2D::LevelObj* levelTemp;edkEnd();
                        //test if the size is smaller
                        if(size<levelsSize){
                            //size<levelsSize
                            size1=size;edkEnd();
                            size2=size1;edkEnd();
                        }
                        else if(size==levelsSize){
                            //size==levelsSize
                            size1=size;edkEnd();
                            size2=size1;edkEnd();
                        }
                        else{
                            //size>levelsSize
                            size1=levelsSize;edkEnd();
                            size2=size;edkEnd();
                        }
                        //just load the levels
                        for(edk::uint32 i=0u;i<size1;i++){
                            //load the levelTemp
                            levelTemp = this->levels.get(i);edkEnd();
                            if(levelTemp){
                                //test if the levelTemp position is the level
                                if(i == level){
                                    this->deleteLevel(i+1);edkEnd();
                                    levelTemp->readFromXMLFromPack(pack,xml,i,&this->tileSet,&this->world);edkEnd();
                                }
                            }
                        }
                        //create the levels
                        for(edk::uint32 i=size1;i<size2;i++){
                            //load the levelTemp
                            levelTemp = new edk::Cenario2D::LevelObj(&this->calls);edkEnd();
                            if(levelTemp){
                                //add the levelTemp to the tree
                                this->levels.pushBack(levelTemp);edkEnd();
                                //test if the levelTemp position is the level
                                if(i == level){
                                    levelTemp->readFromXMLFromPack(pack,xml,i,&this->tileSet,&this->world);edkEnd();
                                }
                            }
                        }
                        //this->loadPhysicObjectsToWorld();edkEnd();
                        xml->selectFather();edkEnd();
                    }
                    /*
                    //JOINTS
                    if(xml->selectChild("joints")){
                        edk::uint32 size = 0u;edkEnd();
                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                        if(temp){
                            size = edk::String::strToInt64(temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        //object vectors
                        bool collide;edkEnd();
                        edk::vec2f32 worldPosition;edkEnd();
                        edk::vec2f32 positionA;edkEnd();
                        edk::vec2f32 positionB;edkEnd();
                        for(edk::uint32 i = 0u;i<size;i++){
                            collide=false;edkEnd();
                            edk::Cenario2D::PhysicsPosition objectA;edkEnd();
                            edk::Cenario2D::PhysicsPosition objectB;edkEnd();
                            idTemp = edk::String::int64ToStr(i);edkEnd();
                            if(idTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"joint_",idTemp);edkEnd();
                                if(nameTemp){
                                    //create the xmlNode
                                    if(xml->selectChild(nameTemp)){
                                        //read the type
                                        edk::uint8 jointType = 0u;edkEnd();
                                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                                        if(temp){
                                            jointType = edk::String::strToInt32(temp);edkEnd();
                                            delete[] temp;edkEnd();
                                        }
                                        //read the objects
                                        objectA.readFromXML(xml,true);edkEnd();
                                        objectB.readFromXML(xml,false);edkEnd();
                                        //ret collide
                                        if(xml->getSelectedAttributeValueByName("collide")){
                                            collide=true;edkEnd();
                                        }
                                        //getWorldPosition
                                        worldPosition = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionAX")),
                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionAY")));edkEnd();
                                        positionA = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionAX")),
                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionAY")));edkEnd();
                                        positionB = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionBX")),
                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionBY")));edkEnd();

                                        switch(jointType){
                                        case EDK_JOINT:
                                            //add the joint
                                            //                                            this->world.createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                        this->getPhysicsObjectInLevel(objectB),
                                            //                                                                        worldPosition,
                                            //                                                                        collide
                                            //                                                                        );edkEnd();
                                            this->world.createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        collide
                                                                        );edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                     );edkEnd();
                                                this->world.createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                     positionA,
                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                                                     positionB,
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerAngle")),
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperAngle")),
                                                                                     collide
                                                                                     );edkEnd();
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
                                                //                                                                                     );edkEnd();
                                                this->world.createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                     positionA,
                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                                                     positionB,
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                     collide
                                                                                     );edkEnd();
                                            }
                                            else if(edk::String::strCompare(xml->getSelectedAttributeValueByName("type"),"NORMAL")){
                                                //
                                                //                                                this->world.createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                worldPosition,
                                                //                                                                                collide
                                                //                                                                                );edkEnd();
                                                this->world.createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                positionA,
                                                                                this->getPhysicsObjectInLevel(objectB),
                                                                                positionB,
                                                                                collide
                                                                                );edkEnd();
                                            }
                                            break;edkEnd();
                                        case EDK_DISTANCE_JOINT:
                                            //create distanceJoint
                                            //                                            this->world.createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                            worldPosition,
                                            //                                                                            this->getPhysicsObjectInLevel(objectB),
                                            //                                                                            edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBX")),
                                            //                                                                                         edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBY"))
                                            //                                                                                         ),
                                            //                                                                            collide);edkEnd();
                                            this->world.createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                                                            positionA,
                                                                            this->getPhysicsObjectInLevel(objectB),
                                                                            positionB,
                                                                            edk::String::strToFloat32(xml->getSelectedAttributeValueByName("distance")),
                                                                            collide);edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                      );edkEnd();
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
                                                                                      );edkEnd();
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
                                                //                                                                                 );edkEnd();
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
                                                                                 );edkEnd();
                                            }
                                            break;edkEnd();
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
                                            //                                                                               );edkEnd();
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
                                                                          );edkEnd();
                                            break;edkEnd();
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
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                  collide
                                                //                                                                                  );edkEnd();
                                                this->world.createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                  positionA,
                                                                                  this->getPhysicsObjectInLevel(objectB),
                                                                                  positionB,
                                                                                  edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                               ),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                  collide
                                                                                  );edkEnd();
                                            }
                                            else{
                                                //
                                                //                                                this->world.createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                             this->getPhysicsObjectInLevel(objectB),
                                                //                                                                             worldPosition,
                                                //                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                          ),
                                                //                                                                             collide
                                                //                                                                             );edkEnd();
                                                this->world.createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                                             positionA,
                                                                             this->getPhysicsObjectInLevel(objectB),
                                                                             positionB,
                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                          ),
                                                                             collide
                                                                             );edkEnd();
                                            }
                                            break;edkEnd();
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
                                            //                                                                                      );edkEnd();
                                            //REMOVED IN NEW BOX2D

//                                            this->world.createRopeJoint(this->getPhysicsObjectInLevel(objectA),
//                                                                        positionA,
//                                                                        this->getPhysicsObjectInLevel(objectB),
//                                                                        positionB,
//                                                                        edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
//                                                                        collide
//                                                                        );edkEnd();

                                            break;edkEnd();
                                        }
                                    }
                                    delete[] nameTemp;edkEnd();
                                }
                                delete[] idTemp;edkEnd();
                            }
                        }
                    }
*/
                    //ACTIONS
                    this->actions.readFromXML(xml,0u,this);edkEnd();

                    ret=true;edkEnd();
                    xml->selectFather();edkEnd();

                    //generate the quadtree position and size
                    {
                        edk::uint32 size = this->levels.size();edkEnd();
                        edk::Cenario2D::LevelObj* level=NULL;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            level=this->levels[i];edkEnd();
                            if(level){
                                level->generateLevelRect();edkEnd();
                                level->addObjectsToQuad();edkEnd();
                            }
                        }
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
bool edk::Cenario2D::readLevelFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 level,edk::uint32 id){
    return this->readLevelFromXMLFromPackWithoutLoadPhysics(pack,(edk::char8*) fileName,level,id);edkEnd();
}
bool edk::Cenario2D::readLevelFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 level,edk::uint32 id){
    //load the XML file
    if(fileName && pack){
        edk::XML xml;edkEnd();
        if(pack->readFileToBuffer(fileName)){
            if(xml.loadFromMemory(pack->getBuffer(),pack->getBufferSize())){
                //load the cenario from the XML file
                return this->readLevelFromXMLFromPackWithoutLoadPhysics(pack,&xml,level,id);edkEnd();
            }
        }
    }
    return false;
}
//Without id
bool edk::Cenario2D::writeToXML(edk::XML* xml){
    return this->writeToXML(xml,0u);edkEnd();
}
bool edk::Cenario2D::writeToXML(const edk::char8* fileName){
    return this->writeToXML(fileName,0u);edkEnd();
}
bool edk::Cenario2D::writeToXML(edk::char8* fileName){
    return this->writeToXML(fileName,0u);edkEnd();
}
//read from XML
bool edk::Cenario2D::readFromXML(edk::XML* xml){
    return this->readFromXML(xml,0u);edkEnd();
}
bool edk::Cenario2D::readFromXML(const edk::char8* fileName){
    return this->readFromXML(fileName,0u);edkEnd();
}
bool edk::Cenario2D::readFromXML(edk::char8* fileName){
    return this->readFromXML(fileName,0u);edkEnd();
}
bool edk::Cenario2D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml){
    return this->readFromXMLFromPack(pack,xml,0u);edkEnd();
}
bool edk::Cenario2D::readFromXMLFromPack(edk::pack::FilePackage* pack,const edk::char8* fileName){
    return this->readFromXMLFromPack(pack,fileName,0u);edkEnd();
}
bool edk::Cenario2D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::char8* fileName){
    return this->readFromXMLFromPack(pack,fileName,0u);edkEnd();
}
//read level from XML
bool edk::Cenario2D::readLevelFromXML(edk::XML* xml,edk::uint32 level){
    return this->readLevelFromXML(xml,0u,level);edkEnd();
}
bool edk::Cenario2D::readLevelFromXML(const edk::char8* fileName,edk::uint32 level){
    return this->readLevelFromXML(fileName,level,0u);edkEnd();
}
bool edk::Cenario2D::readLevelFromXML(edk::char8* fileName,edk::uint32 level){
    return this->readLevelFromXML(fileName,level,0u);edkEnd();
}
bool edk::Cenario2D::readLevelFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 level){
    return this->readLevelFromXMLFromPack(pack,xml,level,0u);edkEnd();
}
bool edk::Cenario2D::readLevelFromXMLFromPack(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 level){
    return this->readLevelFromXMLFromPack(pack,fileName,level,0u);edkEnd();
}
bool edk::Cenario2D::readLevelFromXMLFromPack(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 level){
    return this->readLevelFromXMLFromPack(pack,fileName,level,0u);edkEnd();
}
//read from XML without load physics objects in to the world
bool edk::Cenario2D::readFromXMLWithoutLoadPhysics(edk::XML* xml){
    return this->readFromXMLWithoutLoadPhysics(xml,0u);edkEnd();
}
bool edk::Cenario2D::readFromXMLWithoutLoadPhysics(const edk::char8* fileName){
    return this->readFromXMLWithoutLoadPhysics(fileName,0u);edkEnd();
}
bool edk::Cenario2D::readFromXMLWithoutLoadPhysics(edk::char8* fileName){
    return this->readFromXMLWithoutLoadPhysics(fileName,0u);edkEnd();
}
bool edk::Cenario2D::readFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::XML* xml){
    return this->readFromXMLFromPackWithoutLoadPhysics(pack,xml,0u);edkEnd();
}
bool edk::Cenario2D::readFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,const edk::char8* fileName){
    return this->readFromXMLFromPackWithoutLoadPhysics(pack,fileName,0u);edkEnd();
}
bool edk::Cenario2D::readFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::char8* fileName){
    return this->readFromXMLFromPackWithoutLoadPhysics(pack,fileName,0u);edkEnd();
}
//read level from XML without load physics objects in to the world
bool edk::Cenario2D::readLevelFromXMLWithoutLoadPhysics(edk::XML* xml,edk::uint32 level){
    return this->readLevelFromXMLWithoutLoadPhysics(xml,level,0u);edkEnd();
}
bool edk::Cenario2D::readLevelFromXMLWithoutLoadPhysics(const edk::char8* fileName,edk::uint32 level){
    return this->readLevelFromXMLWithoutLoadPhysics(fileName,level,0u);edkEnd();
}
bool edk::Cenario2D::readLevelFromXMLWithoutLoadPhysics(edk::char8* fileName,edk::uint32 level){
    return this->readLevelFromXMLWithoutLoadPhysics(fileName,level,0u);edkEnd();
}
bool edk::Cenario2D::readLevelFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 level){
    return this->readLevelFromXMLFromPackWithoutLoadPhysics(pack,xml,level,0u);edkEnd();
}
bool edk::Cenario2D::readLevelFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 level){
    return this->readLevelFromXMLFromPackWithoutLoadPhysics(pack,fileName,level,0u);edkEnd();
}
bool edk::Cenario2D::readLevelFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 level){
    return this->readLevelFromXMLFromPackWithoutLoadPhysics(pack,fileName,level,0u);edkEnd();
}
