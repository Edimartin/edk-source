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

bool edk::Cenario2D::templateConstructNeed=true;
edk::physics2D::World2D edk::Cenario2D::worldTemplate;

edk::Cenario2D::Cenario2D():
    treeAnimPhys(&edk::Cenario2D::worldTemplate)
{
    this->world=NULL;
    this->classThis=NULL;
    this->Constructor(&edk::Cenario2D::worldTemplate);
}
edk::Cenario2D::Cenario2D(edk::physics2D::World2D* world):
    treeAnimPhys(world)
{
    this->world=NULL;
    this->classThis=NULL;
    this->Constructor(world);
}
edk::Cenario2D::~Cenario2D(){
    this->Destructor();
}

void edk::Cenario2D::Constructor(){
    edk::Object2DValues::Constructor();
    edk::physics2D::ContactCallback2D::Constructor();
    edk::tiles::tileCallback::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->tileSet.Constructor();
        this->actions.Constructor();
        this->mutContinue.Constructor();
        this->calls.Constructor();
        this->treeAnim.Constructor();
        this->treeAnimPhys.Constructor(&edk::Cenario2D::worldTemplate);
        this->levels.Constructor();
        this->minimunObjectsInQuads=1u;

        //init the templates
        if(edk::Cenario2D::templateConstructNeed){
            edk::Cenario2D::worldTemplate.Constructor();
            edk::Cenario2D::templateConstructNeed=false;
        }
        this->setCanContinueFalse();
        this->world=NULL;
        this->cenarioHaveCreateWorld=false;
        this->clean();
    }
}
void edk::Cenario2D::Constructor(edk::physics2D::World2D* world){
    edk::Object2DValues::Constructor();
    edk::physics2D::ContactCallback2D::Constructor();
    edk::tiles::tileCallback::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->tileSet.Constructor();
        this->actions.Constructor();
        this->mutContinue.Constructor();
        this->calls.Constructor();
        this->treeAnim.Constructor();
        this->treeAnimPhys.Constructor(world);
        this->levels.Constructor();
        this->minimunObjectsInQuads=1u;

        //init the templates
        if(edk::Cenario2D::templateConstructNeed){
            edk::Cenario2D::worldTemplate.Constructor();
            edk::Cenario2D::templateConstructNeed=false;
        }
        this->world=NULL;
        this->cenarioHaveCreateWorld=false;
        this->clean();
        this->setWorld(world);
    }
}
void edk::Cenario2D::Destructor(){
    //can destruct the class
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->clean();
        this->world->removeContactCallback(this);

        this->deleteWorld();

        this->tileSet.Destructor();
        this->actions.Destructor();
        this->mutContinue.Destructor();
        this->calls.Destructor();
        this->treeAnim.Destructor();
        this->treeAnimPhys.Destructor();
        this->levels.Destructor();
        edk::Cenario2D::worldTemplate.Destructor();

    }
    edk::Object2DValues::Destructor();
    edk::physics2D::ContactCallback2D::Destructor();
    edk::tiles::tileCallback::Destructor();
}

//delete the world
void edk::Cenario2D::deleteWorld(){
    if(this->cenarioHaveCreateWorld){
        if(this->world){
            this->world->removeContactCallback(this);
            delete this->world;
            this->world=NULL;
            this->setWorld(NULL);
            this->cenarioHaveCreateWorld=false;
        }
    }
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
//transformBeggin
void edk::Cenario2D::transformBeggin(){
    edk::GU::guPushMatrix();
    //set the translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
}
void edk::Cenario2D::transformEnd(){
    edk::GU::guPopMatrix();
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
                            free(temp);
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
                                                        free(temp);
                                                    }
                                                    //write the object
                                                    if((physObj = (edk::physics2D::PhysicObject2D*)objClass->getObject())){
                                                        //
                                                        physObj->writeToXML(xml,i);
                                                    }
                                                    xml->selectFather();
                                                }
                                            }
                                            free(nameTemp);
                                        }
                                        free(idTemp);
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
                                                        free(temp);
                                                    }
                                                    //write the object
                                                    if((obj=objClass->getObject())){
                                                        //
                                                        obj->writeToXML(xml,i);
                                                    }
                                                    xml->selectFather();
                                                }
                                            }
                                            free(nameTemp);
                                        }
                                        free(idTemp);
                                    }
                                }
                            }
                        }
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
                        free(temp);
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
                                                free(temp);
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
                                                    obj->animationPosition.playForwardAllTracks();
                                                    obj->animationRotation.playForward();
                                                    obj->animationSize.playForward();
                                                }
                                                else{
                                                    delete obj;
                                                }
                                            }

                                            xml->selectFather();
                                        }
                                        free(nameTemp);
                                    }
                                    free(idTemp);
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
                                                free(temp);
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
                                                    obj->animationPosition.playForwardAllTracks();
                                                    obj->animationRotation.playForward();
                                                    obj->animationSize.playForward();
                                                }
                                                else{
                                                    delete obj;
                                                }
                                            }
                                            xml->selectFather();
                                        }
                                        free(nameTemp);
                                    }
                                    free(idTemp);
                                }
                            }
                        }
                    }
                    //
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
bool edk::Cenario2D::TreeObjDepth::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id,bool isPhysics){
    if(xml && pack){
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
                        free(temp);
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
                                                free(temp);
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
                                                if(obj->readFromXMLFromPack(pack,xml,i)){
                                                    //add the object
                                                    if(!this->addObject(true,(edk::Object2D*)obj,depth)){
                                                        //else delete the object
                                                        delete obj;
                                                    }
                                                    obj->playMeshAnimations();
                                                    obj->animationPosition.playForwardAllTracks();
                                                    obj->animationRotation.playForward();
                                                    obj->animationSize.playForward();
                                                }
                                                else{
                                                    delete obj;
                                                }
                                            }

                                            xml->selectFather();
                                        }
                                        free(nameTemp);
                                    }
                                    free(idTemp);
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
                                                free(temp);
                                            }
                                            //create the object
                                            obj = new edk::Object2D;
                                            if(obj){
                                                //read the object
                                                if(obj->readFromXMLFromPack(pack,xml,i)){
                                                    //add the object
                                                    if(!this->addObject(true,obj,depth)){
                                                        //else delete the object
                                                        delete obj;
                                                    }
                                                    obj->playMeshAnimations();
                                                    obj->animationPosition.playForwardAllTracks();
                                                    obj->animationRotation.playForward();
                                                    obj->animationSize.playForward();
                                                }
                                                else{
                                                    delete obj;
                                                }
                                            }
                                            xml->selectFather();
                                        }
                                        free(nameTemp);
                                    }
                                    free(idTemp);
                                }
                            }
                        }
                    }
                    //
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
                free(name);
            }
            free(nameID);
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
                                this->quadObjs = new edk::Cenario2D::QuadObjs(this->calls);
                                if(this->quadObjs){
                                    if(!this->objs->readFromXML(xml,0u)){
                                        delete this->quadObjs;
                                        delete this->objs;
                                        this->clean();
                                    }
                                }
                                else{
                                    delete this->objs;
                                }
                            }
                        }
                        else if(edk::String::strCompare(temp,"objsPhys")){
                            //read the physics objects
                            this->objsPhys = new edk::Cenario2D::TreePhysObjDepth(world);
                            if(this->objsPhys){
                                this->quadPhysicObjs = new edk::Cenario2D::QuadPhyicObjs(world,this->calls);
                                if(quadPhysicObjs){
                                    if(!this->objsPhys->readFromXML(xml,0u,true)){
                                        delete this->quadPhysicObjs;
                                        delete this->objsPhys;
                                        this->clean();
                                    }
                                }
                                else{
                                    delete this->objsPhys;
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
                        free(temp);
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
bool edk::Cenario2D::LevelObj::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id,edk::tiles::TileSet2D* tileSet,edk::physics2D::World2D* world){
    if(xml && pack){
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
                                this->quadObjs = new edk::Cenario2D::QuadObjs(this->calls);
                                if(this->quadObjs){
                                    if(!this->objs->readFromXMLFromPack(pack,xml,0u)){
                                        delete this->quadObjs;
                                        delete this->objs;
                                        this->clean();
                                    }
                                }
                                else{
                                    delete this->objs;
                                }
                            }
                        }
                        else if(edk::String::strCompare(temp,"objsPhys")){
                            //read the physics objects
                            this->objsPhys = new edk::Cenario2D::TreePhysObjDepth(world);
                            if(this->objsPhys){
                                this->quadPhysicObjs = new edk::Cenario2D::QuadPhyicObjs(world,this->calls);
                                if(quadPhysicObjs){
                                    if(!this->objsPhys->readFromXMLFromPack(pack,xml,0u,true)){
                                        delete this->quadPhysicObjs;
                                        delete this->objsPhys;
                                        this->clean();
                                    }
                                }
                                else{
                                    delete this->objsPhys;
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
                        free(temp);
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
                free(name);
            }
            free(number);
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
                free(name);
            }
            free(number);
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
                free(name);
            }
            free(number);
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
                free(name);
            }
            free(number);
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
                free(name);
            }
            free(number);
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
                free(name);
            }
            free(number);
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
        temp->animationPosition.cleanTracks();
        edk::uint32 track = temp->animationPosition.newTrack();
        temp->animationPosition.addFirstInterpolationLine(track,0u,temp->position.x,temp->position.y,this->duration,this->position.x,this->position.y);
        temp->animationPosition.playForwardAllTracks();
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
                free(name);
            }
            free(number);
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
                free(name);
            }
            free(number);
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
                free(name);
            }
            free(number);
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
                free(name);
            }
            free(number);
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
                free(name);
            }
            free(number);
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
                free(name);
            }
            free(number);
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
                free(name);
            }
            free(number);
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
                free(name);
            }
            free(number);
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
                free(name);
            }
            free(number);
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
                free(name);
            }
            free(number);
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
                free(name);
            }
            free(number);
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
                free(name);
            }
            free(number);
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
                free(name);
            }
            free(number);
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
                free(name);
            }
            free(number);
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
        temp = this->levels.get(i);
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
                    temp = new edk::Cenario2D::LevelObj(&this->calls);
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
                    edk::Cenario2D::LevelObj* temp = this->levels.get(levelPosition);
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
                                temp->quadObjs = new edk::Cenario2D::QuadObjs(&this->calls);
                                if(temp->quadObjs){
                                    canCreate=true;
                                }
                                else{
                                    delete temp->objs;
                                    temp->objs=NULL;
                                }
                            }
                        }
                        if(canCreate){
                            //add the object
                            if(temp->objs->addObject(created,obj,depth)){
                                //generate the quads
                                temp->generateLevelRect();
                                temp->addObjectsToQuad(this->minimunObjectsInQuads);
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
                    edk::Cenario2D::LevelObj* temp = this->levels.get(levelPosition);
                    if(temp){
                        bool canCreate=false;
                        if(temp->haveSome()){
                            if(temp->objsPhys){
                                canCreate=true;
                            }
                        }
                        else{
                            //else create a new objs tree
                            temp->objsPhys = new edk::Cenario2D::TreePhysObjDepth(this->world);
                            if(temp->objsPhys){
                                temp->quadPhysicObjs = new edk::Cenario2D::QuadPhyicObjs(this->world,&this->calls);
                                if(temp->quadPhysicObjs){
                                    canCreate=true;
                                }
                                else{
                                    delete temp->objsPhys;
                                    temp->objsPhys=NULL;
                                }
                            }
                        }
                        if(canCreate){
                            //add the object
                            if(temp->objsPhys->addObject(created,objPhys,depth)){
                                //generate the quads
                                temp->generateLevelRect();
                                temp->addObjectsToQuad(this->minimunObjectsInQuads);
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
            edk::Cenario2D::LevelObj* temp = this->levels.get(levelPosition);
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
            levelObj = this->levels.get(i);
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
        if(id){
            name = (edk::char8*)"objectA";
        }
        else{
            name = (edk::char8*)"objectB";
        }
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
                        free(temp);
                    }
                    temp = edk::String::float32ToStr(this->depth);
                    if(temp){
                        xml->addSelectedNextAttribute((edk::char8*)"depth",temp);
                        free(temp);
                    }
                    break;
                case EDK_LEVEL_TILE_MAP:
                    xml->setSelectedString("TILE_MAP");
                    //write the level
                    temp = edk::String::uint32ToStr(this->level);
                    if(temp){
                        xml->addSelectedNextAttribute((edk::char8*)"level",temp);
                        free(temp);
                    }
                    temp = edk::String::uint32ToStr(this->mapPosition.x);
                    if(temp){
                        xml->addSelectedNextAttribute((edk::char8*)"mapX",temp);
                        free(temp);
                    }
                    temp = edk::String::uint32ToStr(this->mapPosition.y);
                    if(temp){
                        xml->addSelectedNextAttribute((edk::char8*)"mapY",temp);
                        free(temp);
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
        if(id){
            name = (edk::char8*)"objectA";
        }
        else{
            name = (edk::char8*)"objectB";
        }
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
                free(temp);
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
            levelObj = this->levels.get(i);
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
        edk::Cenario2D::LevelObj* level = this->levels.get(objLevel.level);
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

void edk::Cenario2D::clean(){
    if(this->world){
        this->world->removeContactCallback(this);
    }
    this->setWorld(NULL);
    this->calls.clean();
    this->deleteAllLevels();
    this->tileSet.deleteTiles();
    this->actions.clean();
    //
    this->cleanSelectedTileMap();
    this->actions.setReadXMLActionFunction(&edk::Cenario2D::readXMLAction);
}

//set the world
bool edk::Cenario2D::setWorld(edk::physics2D::World2D* world){
    //delete the last world
    this->deleteWorld();
    //
    if(world){
        this->world=world;
        this->world->addContactCallback(this);
        return true;
    }
    this->world=&edk::Cenario2D::worldTemplate;
    this->world->addContactCallback(this);
    return false;
}
bool edk::Cenario2D::newWorld(){
    this->deleteWorld();
    //create the new world
    this->world = new edk::physics2D::World2D;
    if(this->world){
        this->cenarioHaveCreateWorld=true;
        return true;
    }
    else{
        //else just set the world;
        this->setWorld(NULL);
    }
    return false;
}
edk::physics2D::World2D* edk::Cenario2D::getWorldTemplate(){
    return &edk::Cenario2D::worldTemplate;
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
                temp = new edk::Cenario2D::LevelObj(&this->calls);
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
            edk::Cenario2D::LevelObj* temp = this->levels.get(position);
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
                            temp->tileMap->setWorld(this->world);
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
            temp = this->levels.get(i);
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
            edk::Cenario2D::LevelObj* temp = this->levels.get(position);
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
            edk::Cenario2D::LevelObj* temp = this->levels.get(position);
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
        temp = this->levels.get(i);
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
    if(this->mapSelected){ return true;}
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
edk::vec2f32 edk::Cenario2D::selectedTileMapGetTileWorldPosition(edk::vec2ui32 position){
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
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
            if(level){
                if(level->objs){
                    return level->objs->getObjectFromDepth(depth);
                }
            }
        }
    }
    return NULL;
}
edk::Object2D* edk::Cenario2D::getObjectInPosition(edk::uint32 levelPosition,edk::uint32 position){
    //test if have the position
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
            if(level){
                if(level->objs){
                    return level->objs->getObjectInPosition(position);
                }
            }
        }
    }
    return NULL;
}
edk::uint32 edk::Cenario2D::getObjectPosition(edk::uint32 levelPosition,edk::Object2D* obj){
    if(obj){
        //load the level
        if(levelPosition){
            levelPosition--;
            if(this->levels.havePos(levelPosition)){
                edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
                if(level){
                    if(level->objs){
                        return level->objs->getObjectPosition(obj);
                    }
                }
            }
        }
    }
    return 0u;
}
edk::uint32 edk::Cenario2D::getObjectPositionFromDepth(edk::uint32 levelPosition,edk::float32 depth){
    //test if have the position
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
            if(level){
                if(level->objs){
                    return level->objs->getObjectPositionFromDepth(depth);
                }
            }
        }
    }
    return 0u;
}
//get the objectDepth
edk::float32 edk::Cenario2D::getObjectDepthInPosition(edk::uint32 levelPosition,edk::uint32 position){
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level = this->levels.get(levelPosition);
            if(level){
                if(level->objs){
                    return level->objs->getObjectDepthInPosition(position);
                }
            }
        }
    }
    return 0.f;
}
edk::float32 edk::Cenario2D::getObjectDepthInPosition(edk::uint32 levelPosition,edk::Object2D* obj){
    if(obj){
        //load the level
        if(levelPosition){
            levelPosition--;
            if(this->levels.havePos(levelPosition)){
                edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
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
                edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
                if(level){
                    //remove object from tree
                    this->treeAnim.remove(obj);
                    if(level->objs){
                        bool ret = level->objs->deleteObj(obj);
                        if(!level->objs->size()){
                            delete level->objs;
                            level->objs=NULL;
                            level->clean();
                            level->cleanLevelQuads();
                        }
                        else{

                            //generate the quads
                            level->generateLevelRect();
                            level->addObjectsToQuad(this->minimunObjectsInQuads);

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
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
            if(level){
                if(level->objs){
                    if(level->quadObjs){
                        delete level->quadObjs;
                        level->quadObjs=NULL;
                    }
                    edk::uint32 size = level->objs->size();
                    for(edk::uint32 i=0u;i<size;i++){
                        this->treeAnim.remove(level->objs->getObjectInPosition(0u));
                        level->objs->deleteObjInPosition(0u);
                    }
                    delete level->objs;
                    level->objs=NULL;
                    level->clean();
                }
            }
        }
    }
}
void edk::Cenario2D::deleteAllObjects(){
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* level = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        level = this->levels.get(i);
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
                edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
                if(level){
                    //remove object from tree
                    this->treeAnim.remove(obj);
                    if(level->objs){
                        edk::Cenario2D::ObjClass* temp = level->objs->getObjectClassFromObject(obj);
                        if(temp){
                            level->quadObjs->remove(temp);
                            bool ret = level->objs->removeObj(obj);
                            if(!level->objs->size()){
                                if(level->quadObjs){
                                    delete level->quadObjs;
                                    level->quadObjs=NULL;
                                }
                                delete level->objs;
                                level->objs=NULL;
                                level->clean();
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
        levelPosition--;
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels.get(levelPosition);
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
        edk::Cenario2D::LevelObj* level = this->levels.get(levelPosition);
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
        edk::Cenario2D::LevelObj* level = this->levels.get(levelPosition);
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
//remove object from be animated
bool edk::Cenario2D::removeObjectAnimated(edk::uint32 levelPosition,edk::Object2D* obj){
    //test the level position
    if(levelPosition){
        levelPosition--;
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels.get(levelPosition);
        if(level){
            //test if have objects
            if(level->objs){
                //load the object
                edk::Object2D* temp = level->objs->getObject(obj);
                if(temp){
                    //add the object to the animation tree
                    if(this->treeAnim.haveElement(temp)){
                        return this->treeAnim.remove(temp);
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
        levelPosition--;
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels.get(levelPosition);
        if(level){
            //test if have objects
            if(level->objs){
                //load the object
                edk::Object2D* temp = level->objs->getObjectInPosition(position);
                if(temp){
                    //add the object to the animation tree
                    if(this->treeAnim.haveElement(temp)){
                        return this->treeAnim.remove(temp);
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
        levelPosition--;
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels.get(levelPosition);
        if(level){
            //test if have objects
            if(level->objs){
                //load the object
                edk::Object2D* temp = level->objs->getObjectFromDepth(depth);
                if(temp){
                    //add the object to the animation tree
                    if(this->treeAnim.haveElement(temp)){
                        return this->treeAnim.remove(temp);
                    }
                }
            }
        }
    }
    return false;
}

//OBJECTS_PHYSICS
//add a object to the tree
edk::physics2D::PhysicObject2D* edk::Cenario2D::newPhysicObject(edk::uint32 levelPosition,edk::TypeObject physicType){
    return this->newPhysicObject(levelPosition,physicType,this->getHigherLevel(levelPosition) + 1.0);
}
edk::physics2D::PhysicObject2D* edk::Cenario2D::newPhysicObject(edk::uint32 levelPosition,edk::TypeObject physicType,edk::float32 depth){
    if(levelPosition){
        edk::physics2D::PhysicObject2D* obj = NULL;
        switch(physicType){
        case edk::TypeObject2DStatic:
            obj = new edk::physics2D::StaticObject2D;
            break;
        case edk::TypeObject2DKinematic:
            obj = new edk::physics2D::KinematicObject2D;
            break;
        case edk::TypeObject2DDynamic:
            obj = new edk::physics2D::DynamicObject2D;
            break;
        default:
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
edk::physics2D::PhysicObject2D* edk::Cenario2D::newPhysicSensor(edk::uint32 levelPosition,edk::TypeObject physicType){
    return this->newPhysicSensor(levelPosition,physicType,this->getHigherLevel(levelPosition) + 1.0);
}
edk::physics2D::PhysicObject2D* edk::Cenario2D::newPhysicSensor(edk::uint32 levelPosition,edk::TypeObject physicType,edk::float32 depth){
    if(levelPosition){
        edk::physics2D::PhysicObject2D* obj = NULL;
        switch(physicType){
        case edk::TypeObject2DStatic:
            obj = new edk::physics2D::StaticSensor2D;
            break;
        case edk::TypeObject2DDynamic:
        case edk::TypeObject2DKinematic:
            obj = new edk::physics2D::KinematicSensor2D;
            break;
        default:
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
//change the objects physics to sensors
bool edk::Cenario2D::changePhysicsToSensor(edk::uint32 levelPosition){
    bool ret=false;
    if(levelPosition){
        levelPosition--;
        //test if have the position
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
            if(level){
                if(level->objsPhys){
                    edk::physics2D::PhysicObject2D* temp;
                    edk::physics2D::PhysicObject2D tempClone;
                    edk::uint32 size = level->objsPhys->size();
                    edk::TypeObject type;
                    edk::float32 depth;
                    bool canClone=false;
                    for(edk::uint32 i=0u;i<size;i++){
                        temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(i);
                        if(temp){
                            depth = level->objsPhys->getObjectDepthInPosition(i);
                            switch(temp->getType()){
                            case edk::TypeObject2DDynamic:
                                canClone=true;
                                type=edk::TypeObject2DDynamic;
                                break;
                            case edk::TypeObject2DStatic:
                                canClone=true;
                                type=edk::TypeObject2DStatic;
                                break;
                            case edk::TypeObject2DKinematic:
                                canClone=true;
                                type=edk::TypeObject2DKinematic;
                                break;
                            default:
                                canClone=false;
                                break;
                            }
                            if(canClone){
                                if(tempClone.cloneFrom(temp)){
                                    //delete the object
                                    this->deletePhysicObject(levelPosition+1u,temp);
                                    //create a new sensor
                                    temp = this->newPhysicSensor(levelPosition+1u,type,depth);
                                    if(temp){
                                        temp->cloneFrom(&tempClone);
                                        ret=true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ret;
}
//get the object
edk::physics2D::PhysicObject2D* edk::Cenario2D::getPhysicObject(edk::uint32 levelPosition,edk::float32 depth){
    if(levelPosition){
        levelPosition--;
        //test if have the position
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
            if(level){
                if(level->objsPhys){
                    return (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectFromDepth(depth);
                }
            }
        }
    }
    return NULL;
}
edk::physics2D::PhysicObject2D* edk::Cenario2D::getPhysicObjectInPosition(edk::uint32 levelPosition,edk::uint32 position){
    if(levelPosition){
        levelPosition--;
        //test if have the position
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
            if(level){
                if(level->objsPhys){
                    return (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(position);
                }
            }
        }
    }
    return NULL;
}
edk::uint32 edk::Cenario2D::getPhysicObjectPosition(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj){
    if(levelPosition){
        levelPosition--;
        //test if have the position
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
            if(level){
                if(level->objsPhys){
                    return level->objsPhys->getObjectPosition(obj);
                }
            }
        }
    }
    return 0u;
}
edk::uint32 edk::Cenario2D::getPhysicObjectPositionFromDepth(edk::uint32 levelPosition,edk::float32 depth){
    if(levelPosition){
        levelPosition--;
        //test if have the position
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
            if(level){
                if(level->objsPhys){
                    return level->objsPhys->getObjectPositionFromDepth(depth);
                }
            }
        }
    }
    return 0u;
}
//return the depth of the physic object
edk::float32 edk::Cenario2D::getPhysicObjectDepth(edk::uint32 levelPosition,edk::uint32 position){
    if(levelPosition){
        levelPosition--;
        //test if have the position
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
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
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
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
            edk::Cenario2D::LevelObj* level = this->levels.get(levelPosition);
            if(level){
                if(level->objsPhys){
                    if(level->objsPhys->haveObject((edk::Object2D*)obj)){
                        //add the object to the world
                        return this->world->addObject(obj);
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
            edk::Cenario2D::LevelObj* level = this->levels.get(levelPosition);
            if(level){
                if(level->objsPhys){
                    edk::uint32 size = level->objsPhys->size();
                    edk::physics2D::PhysicObject2D* temp = NULL;
                    for(edk::uint32 i=0u;i<size;i++){
                        temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(i);
                        this->world->removeObject(temp);
                        this->world->addObject(temp);
                    }
                    return true;
                }
                else if(level->tileMap){
                    bool ret = false;
                    if(level->tileMap->loadPhysicsTilesStaticMerged()){
                        ret=true;
                    }
                    if(level->tileMap->loadPhysicsTilesKinematicAndDynamic()){
                        ret=true;
                    }
                    return ret;
                }
            }
        }
    }
    return false;
}
bool edk::Cenario2D::loadPhysicObjectsToWorld(){
    bool ret = false;
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* level=NULL;
    for(edk::uint32 i=0u;i<size;i++){
        level = this->levels.get(i);
        if(level){
            if(level->objsPhys){
                edk::uint32 size = level->objsPhys->size();
                edk::physics2D::PhysicObject2D* temp = NULL;
                for(edk::uint32 j=0u;j<size;j++){
                    temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(j);
                    this->world->removeObject(temp);
                    this->world->addObject(temp);
                }
                ret = true;
            }
            else if(level->tileMap){
                level->tileMap->loadPhysicsTilesStaticMerged();
                level->tileMap->loadPhysicsTilesKinematicAndDynamic();
            }
        }
    }
    return ret;
}
//unload the physicsObjects from the world
bool edk::Cenario2D::unloadPhysicObjectFromWorld(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj){
    if(levelPosition){
        levelPosition--;
        //load the level
        if(obj){
            if(this->levels.havePos(levelPosition)){
                edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
                if(level){
                    if(level->objsPhys){
                        this->treeAnimPhys.remove(obj);
                        //remove from world
                        this->world->removeObject(obj);
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
        levelPosition--;
        //load the level
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
            if(level){
                if(level->objsPhys){
                    edk::uint32 size = level->objsPhys->size();
                    for(edk::uint32 i=0u;i<size;i++){
                        this->treeAnimPhys.remove((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(i));
                        //remove from worlf
                        this->world->removeObject((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(i));
                    }
                    return true;
                }
            }
        }
    }
    return false;
}
bool edk::Cenario2D::unloadPhysicObjectsFromWorld(){
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* level = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        level = this->levels.get(i);
        if(level){
            if(level->objsPhys){
                //remove the objPhys from world
                edk::uint32 sizePhys = level->objsPhys->size();
                for(edk::uint32 j=0u;j<sizePhys;j++){
                    this->world->removeObject((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(j));
                }
            }
            return true;
        }
    }
    return false;
}

//delete the object
bool edk::Cenario2D::deletePhysicObject(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj){
    if(levelPosition){
        levelPosition--;
        //load the level
        if(obj){
            if(this->levels.havePos(levelPosition)){
                edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
                if(level){
                    if(level->objsPhys){
                        this->treeAnimPhys.remove(obj);
                        //remove from world
                        this->world->removeObject(obj);
                        bool ret = level->objsPhys->deleteObj((edk::Object2D*)obj);
                        if(!level->objsPhys->size()){
                            //remove from world
                            delete level->objsPhys;
                            level->objsPhys=NULL;
                            if(level->quadPhysicObjs){
                                delete level->quadPhysicObjs;
                                level->quadPhysicObjs=NULL;
                            }
                            level->clean();
                        }
                        else{

                            //generate the quads
                            level->generateLevelRect();
                            level->addObjectsToQuad(this->minimunObjectsInQuads);

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
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
            if(level){
                if(level->objsPhys){
                    edk::uint32 size = level->objsPhys->size();
                    for(edk::uint32 i=0u;i<size;i++){
                        this->treeAnimPhys.remove((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(0u));
                        //remove from worlf
                        this->world->removeObject((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(0u));
                        level->objsPhys->deleteObjInPosition(0u);
                    }
                    level->cleanLevelQuads();
                }
            }
        }
    }
}
void edk::Cenario2D::deleteAllPhysicObjects(){
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* level = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        level = this->levels.get(i);
        if(level){
            if(level->objsPhys){
                if(level->quadPhysicObjs){
                    delete level->quadPhysicObjs;
                    level->quadPhysicObjs=NULL;
                }
                //remove the objPhys from world
                edk::uint32 sizePhys = level->objsPhys->size();
                for(edk::uint32 j=0u;j<sizePhys;j++){
                    this->world->removeObject((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(j));
                }
                delete level->objsPhys;
                level->objsPhys=NULL;
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
                edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
                if(level){
                    if(level->objsPhys){
                        this->treeAnimPhys.remove(obj);
                        //remove from world
                        this->world->removeObject(obj);
                        edk::Cenario2D::ObjClass* temp = level->objsPhys->getObjectClassFromObject((edk::Object2D*)obj);
                        if(temp){
                            level->quadPhysicObjs->remove(temp);
                            bool ret = level->objsPhys->removeObj(obj);
                            if(!level->objsPhys->size()){
                                //remove from world
                                if(level->quadPhysicObjs){
                                    delete level->quadPhysicObjs;
                                    level->quadPhysicObjs=NULL;
                                }
                                delete level->objsPhys;
                                level->objsPhys=NULL;
                                level->clean();
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
        levelPosition--;
        //load the level
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
            if(level){
                if(level->objsPhys){
                    edk::uint32 size = level->objsPhys->size();
                    edk::physics2D::PhysicObject2D* temp;
                    for(edk::uint32 i=0u;i<size;i++){
                        temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(i);
                        if(temp){
                            this->world->removeObject(temp);
                        }
                    }
                    return true;
                }
                else if(level->tileMap){
                    level->tileMap->deletePhysicsTiles();
                }
            }
        }
    }
    return false;
}
void edk::Cenario2D::removePhysicObjects(){
    edk::uint32 levelSize = this->levels.size();
    edk::uint32 size = 0u;
    edk::Cenario2D::LevelObj* level=NULL;
    for(edk::uint32 i=0u;i<levelSize;i++){
        level =this->levels.get(i);
        if(level){
            if(level->objsPhys){
                size = level->objsPhys->size();
                edk::physics2D::PhysicObject2D* temp;
                for(edk::uint32 i=0u;i<size;i++){
                    temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(i);
                    if(temp){
                        this->world->removeObject(temp);
                    }
                }
            }
            else if(level->tileMap){
                level->tileMap->deletePhysicsTiles();
            }
        }
    }
}
//set physic object to be animated
bool edk::Cenario2D::setPhysicObjectAnimated(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj){
    //test the level position
    if(levelPosition){
        levelPosition--;
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels.get(levelPosition);
        if(level){
            //test if have objects
            if(level->objsPhys){
                //load the object
                edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObject(obj);
                if(temp){
                    if(temp->getType() == edk::TypeObject2DStatic
                            ||
                            temp->getType() == edk::TypeObject2DDynamic
                            ||
                            temp->getType() == edk::TypeObject2DKinematic
                            ){
                        //add the object to the animation tree
                        if(this->treeAnimPhys.haveElement(temp)){
                            return true;
                        }
                        else{
                            return this->treeAnimPhys.add(temp);
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
        levelPosition--;
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels.get(levelPosition);
        if(level){
            //test if have objects
            if(level->objsPhys){
                //load the object
                edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(position);
                if(temp){
                    if(temp->getType() == edk::TypeObject2DKinematic){
                        //add the object to the animation tree
                        if(this->treeAnimPhys.haveElement(temp)){
                            return true;
                        }
                        else{
                            return this->treeAnimPhys.add(temp);
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
        levelPosition--;
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels.get(levelPosition);
        if(level){
            //test if have objects
            if(level->objsPhys){
                //load the object
                edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectFromDepth(depth);
                if(temp){
                    if(temp->getType() == edk::TypeObject2DKinematic){
                        //add the object to the animation tree
                        if(this->treeAnimPhys.haveElement(temp)){
                            return true;
                        }
                        else{
                            return this->treeAnimPhys.add(temp);
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
        levelPosition--;
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels.get(levelPosition);
        if(level){
            //test if have objects
            if(level->objsPhys){
                //load the object
                edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObject(obj);
                if(temp){
                    if(temp->getType() == edk::TypeObject2DStatic
                            ||
                            temp->getType() == edk::TypeObject2DDynamic
                            ||
                            temp->getType() == edk::TypeObject2DKinematic
                            ){
                        //add the object to the animation tree
                        if(this->treeAnimPhys.haveElement(temp)){
                            return this->treeAnimPhys.remove(temp);
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
        levelPosition--;
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels.get(levelPosition);
        if(level){
            //test if have objects
            if(level->objsPhys){
                //load the object
                edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(position);
                if(temp){
                    if(temp->getType() == edk::TypeObject2DKinematic){
                        //add the object to the animation tree
                        if(this->treeAnimPhys.haveElement(temp)){
                            return this->treeAnimPhys.remove(temp);
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
        levelPosition--;
        //load the level
        edk::Cenario2D::LevelObj* level = this->levels.get(levelPosition);
        if(level){
            //test if have objects
            if(level->objsPhys){
                //load the object
                edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectFromDepth(depth);
                if(temp){
                    if(temp->getType() == edk::TypeObject2DKinematic){
                        //add the object to the animation tree
                        if(this->treeAnimPhys.haveElement(temp)){
                            return this->treeAnimPhys.remove(temp);
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
        levelPosition--;
        //load the level
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
            if(level){
                if(level->tileMap){
                    delete level->tileMap;
                    level->tileMap=NULL;
                }
                if(level->objs){
                    this->deleteAllObjects(levelPosition+1u);
                }
                if(level->objsPhys){
                    if(level->quadPhysicObjs){
                        delete level->quadPhysicObjs;
                        level->quadPhysicObjs=NULL;
                    }
                    //remove the objPhys from world
                    edk::uint32 sizePhys = level->objsPhys->size();
                    for(edk::uint32 j=0u;j<sizePhys;j++){
                        this->world->removeObject((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(j));
                    }
                    delete level->objsPhys;
                    level->objsPhys=NULL;
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
        this->treeAnimPhys.clean();
        edk::Cenario2D::LevelObj* level = NULL;
        for(edk::uint32 i=0u;i<size;i++){
            level = this->levels.get(i);
            if(level){
                if(level->tileMap){
                    delete level->tileMap;
                    level->tileMap=NULL;
                }
                if(level->objs){
                    this->deleteAllObjects(i+1u);
                }
                if(level->objsPhys){
                    if(level->quadPhysicObjs){
                        delete level->quadPhysicObjs;
                        level->quadPhysicObjs=NULL;
                    }
                    //remove the objPhys from world
                    edk::uint32 sizePhys = level->objsPhys->size();
                    for(edk::uint32 j=0u;j<sizePhys;j++){
                        this->world->removeObject((edk::physics2D::PhysicObject2D*)level->objsPhys->getObjectInPosition(j));
                    }
                    delete level->objsPhys;
                    level->objsPhys=NULL;
                }
                level->clean();
                delete level;
            }
        }
    }
    this->levels.clean();
}

//add a callback
bool edk::Cenario2D::addCallback(edk::Cenario2DCallback* callback){
    return this->calls.add(callback);
}
bool edk::Cenario2D::removeCallback(edk::Cenario2DCallback* callback){
    return this->calls.remove(callback);
}

//World
void edk::Cenario2D::worldSetClockScale(edk::float32 scale){
    this->world->setClockScale(scale);
}
//clockStart
void edk::Cenario2D::worldClockStart(){
    this->world->clockStart();
}

//ACTIONS
//play actions
void edk::Cenario2D::playForwardActions(){
    this->actions.playForward();
}
void edk::Cenario2D::playForwardActions(edk::float32 updateSeconds){
    this->actions.playForward(updateSeconds);
}
void edk::Cenario2D::playForwardInActions(edk::float32 second){
    this->actions.playForwardIn(second);
}
void edk::Cenario2D::playForwardInActions(edk::float32 second,edk::float32 updateSeconds){
    this->actions.playForwardIn(second,updateSeconds);
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
void edk::Cenario2D::updateActions(edk::float32 seconds){
    this->actions.update(seconds);
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
bool edk::Cenario2D::actionObjectPlayName(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id,const edk::char8* name,bool loop){
    return this->actionObjectPlayName(second,levelPosition,depth,id,(edk::char8*)name,loop);
}
bool edk::Cenario2D::actionObjectPlayNameFor(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id,edk::char8* name){
    if(this->actions.addAction(second,new edk::Cenario2D::ActionObjectMeshName(this,levelPosition,depth,id,name,true))){
        this->actions.addAction(second+duration,new edk::Cenario2D::ActionObjectMeshStop(this,levelPosition,depth,id));
        return true;
    }
    return false;
}
bool edk::Cenario2D::actionObjectPlayNameFor(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id,const edk::char8* name){
    return this->actionObjectPlayNameFor(second,duration,levelPosition,depth,id,(edk::char8*) name);
}


//update the physics and collisions
void edk::Cenario2D::updatePhysics(edk::int32 velocityIterations, edk::int32 positionIterations){
    //
    this->world->nextStep(velocityIterations, positionIterations);
}
void edk::Cenario2D::updatePhysics(edk::float32 seconds, edk::int32 velocityIterations, edk::int32 positionIterations){
    //
    this->world->nextStep(seconds,velocityIterations, positionIterations);
}
//update the quads (update selection in quadtree)
void edk::Cenario2D::updateQuadsInsideRect(edk::rectf32 rect){
    //draw the levels
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* level=NULL;
    //this->transformBeggin();
    for(edk::uint32 i=0u;i<size;i++){
        level=this->levels.get(i);
        if(level){
            level->updateQuads(rect,i+1u);
        }
    }
    //this->transformEnd();
}
void edk::Cenario2D::updateQuadsInsideRectPoints(edk::rectf32 rect){
    //draw the levels
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* level=NULL;
    //this->transformBeggin();
    for(edk::uint32 i=0u;i<size;i++){
        level=this->levels.get(i);
        if(level){
            level->updateQuadsInsideRectPoints(rect,i+1u);
        }
    }
    //this->transformEnd();
}
bool edk::Cenario2D::updateLevelQuadsInsideRect(edk::uint32 levelPosition,edk::rectf32 rect){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            //this->transformBeggin();
            edk::Cenario2D::LevelObj* level=this->levels.get(levelPosition);
            level->updateQuads(rect,levelPosition+1u);
            //this->transformEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::updateLevelQuadsInsideRectPoints(edk::uint32 levelPosition,edk::rectf32 rect){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            //this->transformBeggin();
            edk::Cenario2D::LevelObj* level=this->levels.get(levelPosition);
            level->updateQuadsInsideRectPoints(rect,levelPosition+1u);
            //this->transformEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::updateLevelsQuadsInsideRect(edk::uint32 startPosition,edk::uint32 endPosition,edk::rectf32 rect){
    bool ret=true;
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;
        endPosition--;
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;
            }
            else{
                startPosition = endPosition = 0u;
            }
            ret=false;
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;
            ret=false;
        }
        edk::Cenario2D::LevelObj* level=NULL;
        //daw the rects
        //this->transformBeggin();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels.get(i);
            if(level){
                level->updateQuads(rect,i+1u);
            }
        }
        //this->transformEnd();
        return ret;
    }
    return false;
}
bool edk::Cenario2D::updateLevelsQuadsInsideRectPoints(edk::uint32 startPosition,edk::uint32 endPosition,edk::rectf32 rect){
    bool ret=true;
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;
        endPosition--;
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;
            }
            else{
                startPosition = endPosition = 0u;
            }
            ret=false;
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;
            ret=false;
        }
        edk::Cenario2D::LevelObj* level=NULL;
        //daw the rects
        //this->transformBeggin();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels.get(i);
            if(level){
                level->updateQuadsInsideRectPoints(rect,i+1u);
            }
        }
        //this->transformEnd();
        return ret;
    }
    return false;
}
//update animations
bool edk::Cenario2D::updateAnimation(edk::uint32 position){
    //test if have the level
    if(position){
        position--;
        if(this->levels.havePos(position)){
            //load the level
            edk::Cenario2D::LevelObj* level = this->levels.get(position);
            if(level){
                if(level->objs){
                    level->objs->loadSeconds();
                    level->objs->update();
                }
                if(level->objsPhys){
                    level->objsPhys->loadSeconds();
                    level->objsPhys->update();
                }
            }
            //update the tileSet
            this->tileSet.updateAnimations();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::updateAnimation(edk::uint32 position,edk::float32 seconds){
    //test if have the level
    if(position){
        position--;
        if(this->levels.havePos(position)){
            //load the level
            edk::Cenario2D::LevelObj* level = this->levels.get(position);
            if(level){
                if(level->objs){
                    level->objs->setSeconds(seconds);
                    level->objs->update();
                    level->objs->loadSeconds();
                }
                if(level->objsPhys){
                    level->objsPhys->setSeconds(seconds);
                    level->objsPhys->update();
                    level->objsPhys->loadSeconds();
                }
            }
            //update the tileSet
            this->tileSet.updateAnimations(seconds);
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::updateAnimations(){
    this->treeAnim.loadSeconds();
    this->treeAnim.update();
    this->treeAnimPhys.loadSeconds();
    this->treeAnimPhys.update();
    //update the tileSet
    this->tileSet.updateAnimations();
    return true;
}
bool edk::Cenario2D::updateAnimations(edk::float32 seconds){
    this->treeAnim.setSeconds(seconds);
    this->treeAnim.update();
    this->treeAnim.loadSeconds();
    this->treeAnimPhys.setSeconds(seconds);
    this->treeAnimPhys.update();
    this->treeAnimPhys.loadSeconds();
    //update the tileSet
    this->tileSet.updateAnimations(seconds);
    return true;
}

//generate the level quads
bool edk::Cenario2D::generateQuads(){
    //draw the levels
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* level=NULL;
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            level=this->levels.get(i);
            if(level){
                level->generateLevelRect();
                level->addObjectsToQuad(this->minimunObjectsInQuads);
            }
        }
        return true;
    }
    return false;
}
bool edk::Cenario2D::generateLevelQuads(edk::uint32 levelPosition){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level=this->levels.get(levelPosition);
            if(level){
                level->generateLevelRect();
                level->addObjectsToQuad(this->minimunObjectsInQuads);
                return true;
            }
        }
    }
    return false;
}

//draw the cenario with all the objects
void edk::Cenario2D::draw(){
    //draw the levels
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* level=NULL;
    this->transformBeggin();
    for(edk::uint32 i=0u;i<size;i++){
        level=this->levels.get(i);
        if(level){
            level->draw();
        }
    }
    this->transformEnd();
}
void edk::Cenario2D::drawWire(){
    //draw the levels
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* level=NULL;
    this->transformBeggin();
    for(edk::uint32 i=0u;i<size;i++){
        level=this->levels.get(i);
        if(level){
            level->drawWire();
        }
    }
    this->transformEnd();
}
void edk::Cenario2D::drawQuads(){
    //draw the levels
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* level=NULL;
    this->transformBeggin();
    for(edk::uint32 i=0u;i<size;i++){
        level=this->levels.get(i);
        if(level){
            level->drawQuads();
        }
    }
    this->transformEnd();
}
void edk::Cenario2D::drawBoxes(){
    //draw the levels
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* level=NULL;
    this->transformBeggin();
    for(edk::uint32 i=0u;i<size;i++){
        level=this->levels.get(i);
        if(level){
            level->drawBoxes();
        }
    }
    this->transformEnd();
}
void edk::Cenario2D::drawInsideRect(edk::rectf32 rect){
    //draw the levels
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* level=NULL;
    this->transformBeggin();
    for(edk::uint32 i=0u;i<size;i++){
        level=this->levels.get(i);
        if(level){
            level->drawInsideRect(rect,i+1u);
        }
    }
    this->transformEnd();
}
void edk::Cenario2D::drawInsideRectPoints(edk::rectf32 rect){
    //draw the levels
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* level=NULL;
    this->transformBeggin();
    for(edk::uint32 i=0u;i<size;i++){
        level=this->levels.get(i);
        if(level){
            level->drawWireInsideRectPoints(rect,i+1u);
        }
    }
    this->transformEnd();
}
bool edk::Cenario2D::drawLevel(edk::uint32 levelPosition){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            this->transformBeggin();
            edk::Cenario2D::LevelObj* level=this->levels.get(levelPosition);
            level->draw();
            this->transformEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::drawLevelWire(edk::uint32 levelPosition){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            this->transformBeggin();
            edk::Cenario2D::LevelObj* level=this->levels.get(levelPosition);
            level->drawWire();
            this->transformEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::drawLevelQuads(edk::uint32 levelPosition){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            this->transformBeggin();
            edk::Cenario2D::LevelObj* level=this->levels.get(levelPosition);
            level->drawQuads();
            this->transformEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::drawLevelQuadsPolygons(edk::uint32 levelPosition){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            this->transformBeggin();
            edk::Cenario2D::LevelObj* level=this->levels.get(levelPosition);
            level->drawQuads();
            this->transformEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::drawLevelBoxes(edk::uint32 levelPosition){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            this->transformBeggin();
            edk::Cenario2D::LevelObj* level=this->levels.get(levelPosition);
            level->drawBoxes();
            this->transformEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::drawLevelInsideRect(edk::uint32 levelPosition,edk::rectf32 rect){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            this->transformBeggin();
            edk::Cenario2D::LevelObj* level=this->levels.get(levelPosition);
            level->drawInsideRect(rect,levelPosition+1u);
            this->transformEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::drawLevelInsideRectPoints(edk::uint32 levelPosition,edk::rectf32 rect){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            this->transformBeggin();
            edk::Cenario2D::LevelObj* level=this->levels.get(levelPosition);
            level->drawInsideRectPoints(rect,levelPosition+1u);
            this->transformEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::drawLevelWireInsideRect(edk::uint32 levelPosition,edk::rectf32 rect){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            this->transformBeggin();
            edk::Cenario2D::LevelObj* level=this->levels.get(levelPosition);
            level->drawWireInsideRect(rect,levelPosition+1u);
            this->transformEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::drawLevelWireInsideRectPoints(edk::uint32 levelPosition,edk::rectf32 rect){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            this->transformBeggin();
            edk::Cenario2D::LevelObj* level=this->levels.get(levelPosition);
            level->drawWireInsideRectPoints(rect,levelPosition+1u);
            this->transformEnd();
            return true;
        }
    }
    return false;
}
//draw levels from start and end
bool edk::Cenario2D::drawLevels(edk::uint32 startPosition,edk::uint32 endPosition){
    bool ret=true;
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;
        endPosition--;
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;
            }
            else{
                startPosition = endPosition = 0u;
            }
            ret=false;
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;
            ret=false;
        }
        edk::Cenario2D::LevelObj* level=NULL;
        //daw the rects
        this->transformBeggin();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels.get(i);
            if(level){
                level->draw();
            }
        }
        this->transformEnd();
        return ret;
    }
    return false;
}
bool edk::Cenario2D::drawLevelsWire(edk::uint32 startPosition,edk::uint32 endPosition){
    bool ret=true;
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;
        endPosition--;
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;
            }
            else{
                startPosition = endPosition = 0u;
            }
            ret=false;
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;
            ret=false;
        }
        edk::Cenario2D::LevelObj* level=NULL;
        //daw the rects
        this->transformBeggin();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels.get(i);
            if(level){
                level->drawWire();
            }
        }
        this->transformEnd();
        return ret;
    }
    return false;
}
bool edk::Cenario2D::drawLevelsQuads(edk::uint32 startPosition,edk::uint32 endPosition){
    bool ret=true;
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;
        endPosition--;
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;
            }
            else{
                startPosition = endPosition = 0u;
            }
            ret=false;
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;
            ret=false;
        }
        edk::Cenario2D::LevelObj* level=NULL;
        //daw the rects
        this->transformBeggin();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels.get(i);
            if(level){
                level->drawQuads();
            }
        }
        this->transformEnd();
        return ret;
    }
    return false;
}
bool edk::Cenario2D::drawLevelsBoxes(edk::uint32 startPosition,edk::uint32 endPosition){
    bool ret=true;
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;
        endPosition--;
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;
            }
            else{
                startPosition = endPosition = 0u;
            }
            ret=false;
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;
            ret=false;
        }
        edk::Cenario2D::LevelObj* level=NULL;
        //daw the rects
        this->transformBeggin();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels.get(i);
            if(level){
                level->drawBoxes();
            }
        }
        this->transformEnd();
        return ret;
    }
    return false;
}
bool edk::Cenario2D::drawLevelsInsideRect(edk::uint32 startPosition,edk::uint32 endPosition,edk::rectf32 rect){
    bool ret=true;
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;
        endPosition--;
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;
            }
            else{
                startPosition = endPosition = 0u;
            }
            ret=false;
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;
            ret=false;
        }
        edk::Cenario2D::LevelObj* level=NULL;
        //daw the rects
        this->transformBeggin();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels.get(i);
            if(level){
                level->drawInsideRect(rect,i+1u);
            }
        }
        this->transformEnd();
        return ret;
    }
    return false;
}
bool edk::Cenario2D::drawLevelsInsideRectPoints(edk::uint32 startPosition,edk::uint32 endPosition,edk::rectf32 rect){
    bool ret=true;
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;
        endPosition--;
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;
            }
            else{
                startPosition = endPosition = 0u;
            }
            ret=false;
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;
            ret=false;
        }
        edk::Cenario2D::LevelObj* level=NULL;
        //daw the rects
        this->transformBeggin();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels.get(i);
            if(level){
                level->drawInsideRectPoints(rect,i+1u);
            }
        }
        this->transformEnd();
        return ret;
    }
    return false;
}
bool edk::Cenario2D::drawLevelsWireInsideRect(edk::uint32 startPosition,edk::uint32 endPosition,edk::rectf32 rect){
    bool ret=true;
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;
        endPosition--;
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;
            }
            else{
                startPosition = endPosition = 0u;
            }
            ret=false;
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;
            ret=false;
        }
        edk::Cenario2D::LevelObj* level=NULL;
        //daw the rects
        this->transformBeggin();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels.get(i);
            if(level){
                level->drawWireInsideRect(rect,i+1u);
            }
        }
        this->transformEnd();
        return ret;
    }
    return false;
}
bool edk::Cenario2D::drawLevelsWireInsideRectPoints(edk::uint32 startPosition,edk::uint32 endPosition,edk::rectf32 rect){
    bool ret=true;
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;
        endPosition--;
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;
            }
            else{
                startPosition = endPosition = 0u;
            }
            ret=false;
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;
            ret=false;
        }
        edk::Cenario2D::LevelObj* level=NULL;
        //daw the rects
        this->transformBeggin();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels.get(i);
            if(level){
                level->drawWireInsideRectPoints(rect,i+1u);
            }
        }
        this->transformEnd();
        return ret;
    }
    return false;
}
void edk::Cenario2D::drawSelection(){
    edk::uint32 size = this->levels.size();
    edk::Cenario2D::LevelObj* level=NULL;
    this->transformBeggin();
    for(edk::uint32 i=0u;i<size;i++){
        level=this->levels.get(i);
        if(level){
            level->drawSelection(i+1u);
        }
    }
    this->transformEnd();
}
bool edk::Cenario2D::drawSelectionLevel(edk::uint32 levelPosition){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            this->transformBeggin();
            edk::Cenario2D::LevelObj* level=this->levels.get(levelPosition);
            level->drawSelection(levelPosition+1u);
            this->transformEnd();
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::drawSelectionLevels(edk::uint32 startPosition,edk::uint32 endPosition){
    bool ret=true;
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;
        endPosition--;
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;
            }
            else{
                startPosition = endPosition = 0u;
            }
            ret=false;
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;
            ret=false;
        }
        edk::Cenario2D::LevelObj* level=NULL;
        //daw the rects
        this->transformBeggin();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels.get(i);
            if(level){
                level->drawSelection(i+1u);
            }
        }
        this->transformEnd();
        return ret;
    }
    return false;
}
bool edk::Cenario2D::drawSelectionLevelsInsideRect(edk::uint32 startPosition,edk::uint32 endPosition,edk::rectf32 rect){
    bool ret=true;
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;
        endPosition--;
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;
            }
            else{
                startPosition = endPosition = 0u;
            }
            ret=false;
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;
            ret=false;
        }
        edk::Cenario2D::LevelObj* level=NULL;
        //daw the rects
        this->transformBeggin();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels.get(i);
            if(level){
                level->drawSelectionInsideRect(rect,i+1u);
            }
        }
        this->transformEnd();
        return ret;
    }
    return false;
}
bool edk::Cenario2D::drawSelectionLevelsInsideRectPoints(edk::uint32 startPosition,edk::uint32 endPosition,edk::rectf32 rect){
    bool ret=true;
    //find the positions
    if(startPosition && endPosition && startPosition<=endPosition){
        startPosition--;
        endPosition--;
        //test if have the positions
        if(!this->levels.havePos(startPosition)){
            //set the start and end to the last
            if(this->levels.getSize()){
                startPosition = endPosition = this->levels.getSize()-1u;
            }
            else{
                startPosition = endPosition = 0u;
            }
            ret=false;
        }
        else if(!this->levels.havePos(endPosition)){
            //set the end to the last
            endPosition = this->levels.getSize()-1u;
            ret=false;
        }
        edk::Cenario2D::LevelObj* level=NULL;
        //daw the rects
        this->transformBeggin();
        for(edk::uint32 i=startPosition;i<=endPosition;i++){
            level=this->levels.get(i);
            if(level){
                level->drawSelectionInsideRectPoints(rect,i+1u);
            }
        }
        this->transformEnd();
        return ret;
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
            edk::Cenario2D::LevelObj* level=this->levels.get(levelPosition);
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
            edk::Cenario2D::LevelObj* level=this->levels.get(levelPosition);
            return level->show;
        }
    }
    return false;
}

//CAN_SELECT/CANT_SELECT LEVEL
bool edk::Cenario2D::cantSelectLevel(edk::uint32 levelPosition){
    return this->setCanSelectLevel(levelPosition,false);
}
bool edk::Cenario2D::canSelectLevel(edk::uint32 levelPosition){
    return this->setCanSelectLevel(levelPosition,true);
}
bool edk::Cenario2D::setCanSelectLevel(edk::uint32 levelPosition,bool canSelect){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level=this->levels.get(levelPosition);
            level->canSelect = canSelect;
            return true;
        }
    }
    return false;
}
bool edk::Cenario2D::getCanSelectLevel(edk::uint32 levelPosition){
    //draw the levelPosition
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level=this->levels.get(levelPosition);
            return level->canSelect;
        }
    }
    return false;
}

//get level type
edk::uint8 edk::Cenario2D::getLevelType(edk::uint32 levelPosition){
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
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
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
            if(level){
                return level->haveSome();
            }
        }
    }
    return false;
}
//return the levelSize
edk::uint32 edk::Cenario2D::getLevelsSize(){
    return this->levels.size();
}
edk::uint32 edk::Cenario2D::getLevelSize(edk::uint32 levelPosition){
    //test the level
    if(levelPosition){
        levelPosition--;
        //test if have the level
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
            if(level){
                if(level->objs){
                    return level->objs->size();
                }
                if(level->objsPhys){
                    return level->objsPhys->size();
                }
            }
        }
    }
    return 0u;
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

//set level translate
bool edk::Cenario2D::setLevelPosition(edk::uint32 levelPosition,edk::vec2f32 position){
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
            if(level){
                level->transform.position = position;
                return true;
            }
        }
    }
    return false;
}
bool edk::Cenario2D::setLevelPosition(edk::uint32 levelPosition,edk::float32 x,edk::float32 y){
    return setLevelPosition(levelPosition,edk::vec2f32(x,y));
}
//set level rotate angle
bool edk::Cenario2D::setLevelAngle(edk::uint32 levelPosition,edk::float32 angle){
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
            if(level){
                level->transform.angle = angle;
                return true;
            }
        }
    }
    return false;
}
//set level size
bool edk::Cenario2D::setLevelSize(edk::uint32 levelPosition,edk::size2f32 size){
    if(levelPosition){
        levelPosition--;
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
            if(level){
                level->transform.size = size;
                return true;
            }
        }
    }
    return false;
}
bool edk::Cenario2D::setLevelSize(edk::uint32 levelPosition,edk::float32 width,edk::float32 height){
    //
    return this->setLevelSize(levelPosition,edk::size2f32(width,height));
}

//set the level alpha by setting the alpha channel in all objects
bool edk::Cenario2D::setLevelAlpha(edk::uint32 levelPosition,edk::float32 alpha){
    if(levelPosition){
        levelPosition--;
        //load the level
        if(this->levels.havePos(levelPosition)){
            edk::Cenario2D::LevelObj* level =this->levels.get(levelPosition);
            if(level){
                if(level->objsPhys){
                    //set the alpha value in all objects
                    edk::uint32 size = level->objsPhys->size();
                    edk::uint32 sizeMesh;
                    edk::Object2D* obj;
                    edk::shape::Mesh2D* mesh;
                    for(edk::uint32 i=0u;i<size;i++){
                        obj = level->objsPhys->getObjectInPosition(i);
                        if(obj){
                            sizeMesh = obj->getMeshSize();
                            for(edk::uint32 j=0u;j<sizeMesh;j++){
                                mesh = obj->getMesh(j);
                                if(mesh){
                                    mesh->material.setDiffuse(mesh->material.getDiffuse().r,
                                                              mesh->material.getDiffuse().g,
                                                              mesh->material.getDiffuse().b,
                                                              alpha
                                                              );
                                    mesh->material.setEmission(mesh->material.getEmission().r,
                                                               mesh->material.getEmission().g,
                                                               mesh->material.getEmission().b,
                                                               alpha
                                                               );
                                }
                            }
                        }
                    }
                    return true;
                }
                else if(level->objs){
                    //set the alpha value in all objects
                    edk::uint32 size = level->objs->size();
                    edk::uint32 sizeMesh;
                    edk::Object2D* obj;
                    edk::shape::Mesh2D* mesh;
                    for(edk::uint32 i=0u;i<size;i++){
                        obj = level->objs->getObjectInPosition(i);
                        if(obj){
                            sizeMesh = obj->getMeshSize();
                            for(edk::uint32 j=0u;j<sizeMesh;j++){
                                mesh = obj->getMesh(j);
                                if(mesh){
                                    mesh->material.setDiffuse(mesh->material.getDiffuse().r,
                                                              mesh->material.getDiffuse().g,
                                                              mesh->material.getDiffuse().b,
                                                              alpha
                                                              );
                                    mesh->material.setEmission(mesh->material.getEmission().r,
                                                               mesh->material.getEmission().g,
                                                               mesh->material.getEmission().b,
                                                               alpha
                                                               );
                                }
                            }
                        }
                    }
                    return true;
                }
            }
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
                        if(xml->addSelectedNextChild("meters")){
                            if(xml->selectChild("meters")){
                                xml->setSelectedString(this->world->getMeterDistance());
                                xml->selectFather();
                            }
                        }

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
                                        level = this->levels.get(i);
                                        if(level){
                                            level->writeToXML(xml,i);
                                        }
                                    }
                                    xml->selectFather();
                                }
                            }
                            free(temp);
                        }

                        //JOINTS
                        if(xml->addSelectedNextChild("joints")){
                            if(xml->selectChild("joints")){
                                size = this->world->getJointSize();
                                temp = edk::String::int64ToStr(size);
                                if(temp){
                                    xml->setSelectedString(temp);
                                    free(temp);
                                }
                                edk::uint8 jointType;
                                edk::physics2D::Joint2D* joint;
                                edk::physics2D::RevoluteJoint2D* revoluteJoint;
                                edk::physics2D::DistanceJoint2D* distanceJoint;
                                edk::physics2D::PrismaticJoint2D* prismaticJoint;
                                edk::physics2D::PulleyJoint2D* pulleyJoint;
                                edk::physics2D::WheelJoint2D* wheelJoint;
                                //REMOVE IN NEW BOX2D
                                //edk::physics2D::RopeJoint2D* ropeJoint;
                                edk::Cenario2D::PhysicsPosition objectA;
                                edk::Cenario2D::PhysicsPosition objectB;
                                for(edk::uint32 i=0u;i<size;i++){
                                    //test if have the joint in position
                                    if((joint = this->world->getJointInPosition(i))){
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
                                                                jointType = this->world->getJointTypeInPosition(i);
                                                                temp = edk::String::int64ToStr(jointType);
                                                                if(temp){
                                                                    xml->setSelectedString(temp);
                                                                    free(temp);
                                                                }
                                                                //Write the object
                                                                objectA.writeToXML(xml,true);
                                                                objectB.writeToXML(xml,false);

                                                                temp = edk::String::float32ToStr(joint->worldPositionA.x);
                                                                if(temp){
                                                                    xml->addSelectedNextAttribute((edk::char8*)"worldPositionAX",temp);
                                                                    free(temp);
                                                                }
                                                                temp = edk::String::float32ToStr(joint->worldPositionA.y);
                                                                if(temp){
                                                                    xml->addSelectedNextAttribute((edk::char8*)"worldPositionAY",temp);
                                                                    free(temp);
                                                                }
                                                                //Positions
                                                                temp = edk::String::float32ToStr(joint->positionA.x);
                                                                if(temp){
                                                                    xml->addSelectedNextAttribute((edk::char8*)"positionAX",temp);
                                                                    free(temp);
                                                                }
                                                                temp = edk::String::float32ToStr(joint->positionA.y);
                                                                if(temp){
                                                                    xml->addSelectedNextAttribute((edk::char8*)"positionAY",temp);
                                                                    free(temp);
                                                                }
                                                                temp = edk::String::float32ToStr(joint->positionB.x);
                                                                if(temp){
                                                                    xml->addSelectedNextAttribute((edk::char8*)"positionBX",temp);
                                                                    free(temp);
                                                                }
                                                                temp = edk::String::float32ToStr(joint->positionB.y);
                                                                if(temp){
                                                                    xml->addSelectedNextAttribute((edk::char8*)"positionBY",temp);
                                                                    free(temp);
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
                                                                    revoluteJoint = (edk::physics2D::RevoluteJoint2D*)this->world->getJointInPosition(i);
                                                                    //test the revoluteType
                                                                    switch(revoluteJoint->getRevoluteType()){
                                                                    case EDK_JOINT_ANGLE:
                                                                        xml->addSelectedNextAttribute("type","ANGLE");
                                                                        temp = edk::String::float32ToStr(revoluteJoint->getLowerAngle());
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"lowerAngle",temp);
                                                                            free(temp);
                                                                        }
                                                                        temp = edk::String::float32ToStr(revoluteJoint->getUpperAngle());
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"upperAngle",temp);
                                                                            free(temp);
                                                                        }
                                                                        break;
                                                                    case EDK_JOINT_MOTOR:
                                                                        xml->addSelectedNextAttribute("type","MOTOR");
                                                                        temp = edk::String::float32ToStr(revoluteJoint->getMaxTorque());
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"maxTorque",temp);
                                                                            free(temp);
                                                                        }
                                                                        temp = edk::String::float32ToStr(revoluteJoint->getSpeed());
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"speed",temp);
                                                                            free(temp);
                                                                        }
                                                                        break;
                                                                    default:
                                                                        xml->addSelectedNextAttribute("type","NORMAL");
                                                                    }
                                                                    break;
                                                                case EDK_PRISMATIC_JOINT:
                                                                    //
                                                                    //xml->setSelectedString("PRISMATIC_JOINT");
                                                                    prismaticJoint = (edk::physics2D::PrismaticJoint2D*)this->world->getJointInPosition(i);
                                                                    //write direction
                                                                    temp = edk::String::float32ToStr(prismaticJoint->direction.x);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"directionX",temp);
                                                                        free(temp);
                                                                    }
                                                                    temp = edk::String::float32ToStr(prismaticJoint->direction.y);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"directionY",temp);
                                                                        free(temp);
                                                                    }
                                                                    //test the Type
                                                                    if(prismaticJoint->getPrismaticType() == EDK_JOINT_MOTOR){
                                                                        xml->addSelectedNextAttribute("type","MOTOR");
                                                                        temp = edk::String::float32ToStr(prismaticJoint->getMaxForce());
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"maxForce",temp);
                                                                            free(temp);
                                                                        }
                                                                        temp = edk::String::float32ToStr(prismaticJoint->getSpeed());
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"speed",temp);
                                                                            free(temp);
                                                                        }
                                                                    }
                                                                    temp = edk::String::float32ToStr(prismaticJoint->lowerDistance);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"lowerDistance",temp);
                                                                        free(temp);
                                                                    }
                                                                    temp = edk::String::float32ToStr(prismaticJoint->upperDistance);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"upperDistance",temp);
                                                                        free(temp);
                                                                    }
                                                                    break;
                                                                case EDK_PULLEY_JOINT:
                                                                    //
                                                                    //xml->setSelectedString("PULLEY_JOINT");
                                                                    pulleyJoint = (edk::physics2D::PulleyJoint2D*)this->world->getJointInPosition(i);
                                                                    //write pulleyPositions
                                                                    temp = edk::String::float32ToStr(pulleyJoint->pulleyPositionA.x);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"pulleyPositionAX",temp);
                                                                        free(temp);
                                                                    }
                                                                    temp = edk::String::float32ToStr(pulleyJoint->pulleyPositionA.y);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"pulleyPositionAY",temp);
                                                                        free(temp);
                                                                    }
                                                                    temp = edk::String::float32ToStr(pulleyJoint->pulleyPositionB.x);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"pulleyPositionBX",temp);
                                                                        free(temp);
                                                                    }
                                                                    temp = edk::String::float32ToStr(pulleyJoint->pulleyPositionB.y);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"pulleyPositionBY",temp);
                                                                        free(temp);
                                                                    }
                                                                    temp = edk::String::float32ToStr(pulleyJoint->lenghtA);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"lenghtA",temp);
                                                                        free(temp);
                                                                    }
                                                                    temp = edk::String::float32ToStr(pulleyJoint->lenghtB);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"lenghtB",temp);
                                                                        free(temp);
                                                                    }
                                                                    break;
                                                                case EDK_DISTANCE_JOINT:
                                                                    //
                                                                    //xml->setSelectedString("DISTANCE_JOINT");
                                                                    distanceJoint = (edk::physics2D::DistanceJoint2D*)this->world->getJointInPosition(i);
                                                                    temp = edk::String::float32ToStr(distanceJoint->worldPositionB.x);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"worldPositionBX",temp);
                                                                        free(temp);
                                                                    }
                                                                    temp = edk::String::float32ToStr(distanceJoint->worldPositionB.y);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"worldPositionBY",temp);
                                                                        free(temp);
                                                                    }
                                                                    //distance
                                                                    temp = edk::String::float32ToStr(distanceJoint->distance);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"distance",temp);
                                                                        free(temp);
                                                                    }
                                                                    break;
                                                                case EDK_WHEEL_JOINT:
                                                                    //
                                                                    //xml->setSelectedString("WHEEL_JOINT");
                                                                    wheelJoint = (edk::physics2D::WheelJoint2D*)this->world->getJointInPosition(i);
                                                                    //write direction
                                                                    temp = edk::String::float32ToStr(wheelJoint->direction.x);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"directionX",temp);
                                                                        free(temp);
                                                                    }
                                                                    temp = edk::String::float32ToStr(wheelJoint->direction.y);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"directionY",temp);
                                                                        free(temp);
                                                                    }
                                                                    //test the Type
                                                                    if(wheelJoint->getWheelType() == EDK_JOINT_MOTOR){
                                                                        xml->addSelectedNextAttribute("type","MOTOR");
                                                                        temp = edk::String::float32ToStr(wheelJoint->getMaxTorque());
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"maxTorque",temp);
                                                                            free(temp);
                                                                        }
                                                                        temp = edk::String::float32ToStr(wheelJoint->getSpeed());
                                                                        if(temp){
                                                                            xml->addSelectedNextAttribute((edk::char8*)"speed",temp);
                                                                            free(temp);
                                                                        }
                                                                    }
                                                                    break;
                                                                    //REMOVE IN NEW BOX2D
                                                                    /*
                                                                case EDK_ROPE_JOINT:
                                                                    //
                                                                    //xml->setSelectedString("ROPE_JOINT");
                                                                    ropeJoint = (edk::physics2D::RopeJoint2D*)this->world->getJointInPosition(i);
                                                                    //
                                                                    temp = edk::String::float32ToStr(ropeJoint->worldPositionB.x);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"worldPositionBX",temp);
                                                                        free(temp);
                                                                    }
                                                                    temp = edk::String::float32ToStr(ropeJoint->worldPositionB.y);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"worldPositionBY",temp);
                                                                        free(temp);
                                                                    }
                                                                    temp = edk::String::float32ToStr(ropeJoint->maxLength);
                                                                    if(temp){
                                                                        xml->addSelectedNextAttribute((edk::char8*)"maxLength",temp);
                                                                        free(temp);
                                                                    }
                                                                    break;
                                                                */
                                                                }
                                                                xml->selectFather();
                                                            }
                                                        }
                                                        free(nameTemp);
                                                    }
                                                    free(idTemp);
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
                free(name);
            }
            free(nameID);
        }
        return ret;
    }
    return false;
}
bool edk::Cenario2D::writeToXML(const edk::char8* fileName,edk::uint32 id){
    return this->writeToXML((edk::char8*) fileName,id);
}
bool edk::Cenario2D::writeToXML(edk::char8* fileName,edk::uint32 id){
    //load the XML file
    if(fileName){
        edk::XML xml;
        if(this->writeToXML(&xml,id)){
            //
            return xml.saveToFile(fileName);
        }
    }
    return false;
}
//read from XML
bool edk::Cenario2D::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        this->setCanContinueTrue();
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

                    if(xml->selectChild("meters")){
                        this->world->setMeterDistance(xml->getSelectedStringAsFloat32());
                        xml->selectFather();
                    }

                    //test if can't continue
                    if(this->ifCantContinue()){free(name); free(nameID); return false;}

                    //read tileSet
                    this->tileSet.readFromXML(xml,0u);

                    //test if can't continue
                    if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                    //read the levels
                    if(xml->selectChild("levels")){

                        this->deleteAllLevels();
                        edk::uint32 size = 0u;

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            free(temp);
                        }
                        edk::Cenario2D::LevelObj* level;
                        for(edk::uint32 i=0u;i<size;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                            //load the level
                            level = new edk::Cenario2D::LevelObj(&this->calls);
                            if(level){
                                //add the level to the tree
                                this->levels.pushBack(level);
                                level->readFromXML(xml,i,&this->tileSet,this->world);
                            }
                        }

                        //test if can't continue
                        if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                        this->loadPhysicObjectsToWorld();
                        xml->selectFather();
                    }

                    //JOINTS
                    if(xml->selectChild("joints")){
                        edk::uint32 size = 0u;
                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            free(temp);
                        }
                        //object vectors
                        bool collide;
                        edk::vec2f32 worldPosition;
                        edk::vec2f32 positionA;
                        edk::vec2f32 positionB;
                        for(edk::uint32 i = 0u;i<size;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

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
                                            free(temp);
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
                                            //                                            this->world->createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                        this->getPhysicsObjectInLevel(objectB),
                                            //                                                                        worldPosition,
                                            //                                                                        collide
                                            //                                                                        );
                                            this->world->createWeldJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                     worldPosition,
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerAngle")),
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperAngle")),
                                                //                                                                                     collide
                                                //                                                                                     );
                                                this->world->createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                     worldPosition,
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                     collide
                                                //                                                                                     );
                                                this->world->createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                worldPosition,
                                                //                                                                                collide
                                                //                                                                                );
                                                this->world->createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                 positionA,
                                                                                 this->getPhysicsObjectInLevel(objectB),
                                                                                 positionB,
                                                                                 collide
                                                                                 );
                                            }
                                            break;
                                        case EDK_DISTANCE_JOINT:
                                            //create distanceJoint
                                            //                                            this->world->createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                            worldPosition,
                                            //                                                                            this->getPhysicsObjectInLevel(objectB),
                                            //                                                                            edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBX")),
                                            //                                                                                         edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBY"))
                                            //                                                                                         ),
                                            //                                                                            collide);
                                            this->world->createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createPrismaticMotorJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                this->world->createPrismaticMotorJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createPrismaticJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                 this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                 worldPosition,
                                                //                                                                                 edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                              ),
                                                //                                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerDistance")),
                                                //                                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperDistance")),
                                                //                                                                                 collide
                                                //                                                                                 );
                                                this->world->createPrismaticJoint(this->getPhysicsObjectInLevel(objectA),
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
                                            //                                            this->world->createPulleyWorldJoint(this->getPhysicsObjectInLevel(objectA),
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
                                            this->world->createPulleyJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                  this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                  worldPosition,
                                                //                                                                                  edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                               ),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                  collide
                                                //                                                                                  );
                                                this->world->createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                   positionA,
                                                                                   this->getPhysicsObjectInLevel(objectB),
                                                                                   positionB,
                                                                                   edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                                edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                                ),
                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                   collide
                                                                                   );
                                            }
                                            else{
                                                //
                                                //                                                this->world->createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                             this->getPhysicsObjectInLevel(objectB),
                                                //                                                                             worldPosition,
                                                //                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                          ),
                                                //                                                                             collide
                                                //                                                                             );
                                                this->world->createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                                              positionA,
                                                                              this->getPhysicsObjectInLevel(objectB),
                                                                              positionB,
                                                                              edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                           edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                           ),
                                                                              collide
                                                                              );
                                            }
                                            break;
                                        case EDK_ROPE_JOINT:
                                            //
                                            //                                            this->world->createRopeJointWorldPositions(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                                      worldPosition,
                                            //                                                                                      this->getPhysicsObjectInLevel(objectB),
                                            //                                                                                      edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                            //                                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                            //                                                                                                   ),
                                            //                                                                                      edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
                                            //                                                                                      collide
                                            //                                                                                      );
                                            //REMOVED IN NEW BOX2D
                                            /*
                                            this->world->createRopeJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
                                                                        collide
                                                                        );
                                            */
                                            break;
                                        }
                                    }
                                    free(nameTemp);
                                }
                                free(idTemp);
                            }
                        }
                    }

                    //test if can't continue
                    if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                    //ACTIONS
                    this->actions.readFromXML(xml,0u,this);

                    ret=true;
                    xml->selectFather();

                    //generate the quadtree position and size
                    {
                        edk::uint32 size = this->levels.size();
                        edk::Cenario2D::LevelObj* level=NULL;
                        for(edk::uint32 i=0u;i<size;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                            level=this->levels.get(i);
                            if(level){
                                level->generateLevelRect();
                                level->addObjectsToQuad(this->minimunObjectsInQuads);
                            }
                        }
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
bool edk::Cenario2D::readFromXML(const edk::char8* fileName,edk::uint32 id){
    return this->readFromXML((edk::char8*) fileName,id);
}
bool edk::Cenario2D::readFromXML(edk::char8* fileName,edk::uint32 id){
    //load the XML file
    if(fileName){
        this->setCanContinueTrue();
        edk::XML xml;
        if(xml.loadFile(fileName)){
            //load the cenario from the XML file

            //test if can't continue
            if(this->ifCantContinue()){return false;}

            return this->readFromXML(&xml,id);
        }
    }
    return false;
}
bool edk::Cenario2D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    if(xml && pack){
        this->setCanContinueTrue();
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

                    if(xml->selectChild("meters")){
                        this->world->setMeterDistance(xml->getSelectedStringAsFloat32());
                        xml->selectFather();
                    }

                    //test if can't continue
                    if(this->ifCantContinue()){free(name); free(nameID); return false;}

                    //read tileSet
                    this->tileSet.readFromXMLFromPack(pack,xml,0u);

                    //test if can't continue
                    if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                    //read the levels
                    if(xml->selectChild("levels")){

                        this->deleteAllLevels();
                        edk::uint32 size = 0u;

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            free(temp);
                        }
                        edk::Cenario2D::LevelObj* level;
                        for(edk::uint32 i=0u;i<size;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                            //load the level
                            level = new edk::Cenario2D::LevelObj(&this->calls);
                            if(level){
                                //add the level to the tree
                                this->levels.pushBack(level);
                                level->readFromXMLFromPack(pack,xml,i,&this->tileSet,this->world);
                            }
                        }

                        //test if can't continue
                        if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                        this->loadPhysicObjectsToWorld();
                        xml->selectFather();
                    }

                    //JOINTS
                    if(xml->selectChild("joints")){
                        edk::uint32 size = 0u;
                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            free(temp);
                        }
                        //object vectors
                        bool collide;
                        edk::vec2f32 worldPosition;
                        edk::vec2f32 positionA;
                        edk::vec2f32 positionB;
                        for(edk::uint32 i = 0u;i<size;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

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
                                            free(temp);
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
                                            //                                            this->world->createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                        this->getPhysicsObjectInLevel(objectB),
                                            //                                                                        worldPosition,
                                            //                                                                        collide
                                            //                                                                        );
                                            this->world->createWeldJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                     worldPosition,
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerAngle")),
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperAngle")),
                                                //                                                                                     collide
                                                //                                                                                     );
                                                this->world->createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                     worldPosition,
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                     collide
                                                //                                                                                     );
                                                this->world->createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                worldPosition,
                                                //                                                                                collide
                                                //                                                                                );
                                                this->world->createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                 positionA,
                                                                                 this->getPhysicsObjectInLevel(objectB),
                                                                                 positionB,
                                                                                 collide
                                                                                 );
                                            }
                                            break;
                                        case EDK_DISTANCE_JOINT:
                                            //create distanceJoint
                                            //                                            this->world->createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                            worldPosition,
                                            //                                                                            this->getPhysicsObjectInLevel(objectB),
                                            //                                                                            edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBX")),
                                            //                                                                                         edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBY"))
                                            //                                                                                         ),
                                            //                                                                            collide);
                                            this->world->createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createPrismaticMotorJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                this->world->createPrismaticMotorJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createPrismaticJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                 this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                 worldPosition,
                                                //                                                                                 edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                              ),
                                                //                                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerDistance")),
                                                //                                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperDistance")),
                                                //                                                                                 collide
                                                //                                                                                 );
                                                this->world->createPrismaticJoint(this->getPhysicsObjectInLevel(objectA),
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
                                            //                                            this->world->createPulleyWorldJoint(this->getPhysicsObjectInLevel(objectA),
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
                                            this->world->createPulleyJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                  this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                  worldPosition,
                                                //                                                                                  edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                               ),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                  collide
                                                //                                                                                  );
                                                this->world->createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                   positionA,
                                                                                   this->getPhysicsObjectInLevel(objectB),
                                                                                   positionB,
                                                                                   edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                                edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                                ),
                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                   collide
                                                                                   );
                                            }
                                            else{
                                                //
                                                //                                                this->world->createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                             this->getPhysicsObjectInLevel(objectB),
                                                //                                                                             worldPosition,
                                                //                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                          ),
                                                //                                                                             collide
                                                //                                                                             );
                                                this->world->createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                                              positionA,
                                                                              this->getPhysicsObjectInLevel(objectB),
                                                                              positionB,
                                                                              edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                           edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                           ),
                                                                              collide
                                                                              );
                                            }
                                            break;
                                        case EDK_ROPE_JOINT:
                                            //
                                            //                                            this->world->createRopeJointWorldPositions(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                                      worldPosition,
                                            //                                                                                      this->getPhysicsObjectInLevel(objectB),
                                            //                                                                                      edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                            //                                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                            //                                                                                                   ),
                                            //                                                                                      edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
                                            //                                                                                      collide
                                            //                                                                                      );
                                            //REMOVED IN NEW BOX2D
                                            /*
                                            this->world->createRopeJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
                                                                        collide
                                                                        );
                                            */
                                            break;
                                        }
                                    }
                                    free(nameTemp);
                                }
                                free(idTemp);
                            }
                        }
                    }

                    //test if can't continue
                    if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                    //ACTIONS
                    this->actions.readFromXML(xml,0u,this);

                    ret=true;
                    xml->selectFather();

                    //generate the quadtree position and size
                    {
                        edk::uint32 size = this->levels.size();
                        edk::Cenario2D::LevelObj* level=NULL;
                        for(edk::uint32 i=0u;i<size;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                            level=this->levels.get(i);
                            if(level){
                                level->generateLevelRect();
                                level->addObjectsToQuad(this->minimunObjectsInQuads);
                            }
                        }
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
bool edk::Cenario2D::readFromXMLFromPack(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 id){
    return this->readFromXMLFromPack(pack,(edk::char8*) fileName,id);
}
bool edk::Cenario2D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 id){
    //load the XML file
    if(fileName && pack){
        this->setCanContinueTrue();
        edk::XML xml;

        if(edk::multi::Thread::isThisThreadMain()){
            while(true){
                //test if can tryLock
                if(pack->mutex.tryLock()){
                    //it lock
                    break;
                }
                else{
                    //else load textures from other threads
                    edk::GU::guUpdateLoadTextures();
                    edk::GU_GLSL::guUpdateCreateShaders();
                }
            }
        }
        else{
            pack->mutex.lock();
        }

        if(pack->readFileToBuffer(fileName)){
            if(xml.loadFromMemory(pack->getBuffer(),pack->getBufferSize())){
                pack->mutex.unlock();
                //load the cenario from the XML file

                //test if can't continue
                if(this->ifCantContinue()){return false;}

                return this->readFromXMLFromPack(pack,&xml,id);
            }
            else{
                pack->mutex.unlock();
            }
        }
        else{
            pack->mutex.unlock();
        }
    }
    return false;
}
//read level from XML
bool edk::Cenario2D::readLevelFromXML(edk::XML* xml,edk::uint32 level,edk::uint32 id){
    if(xml && level){
        this->setCanContinueTrue();
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

                    //read the levels
                    if(xml->selectChild("levels")){

                        //this->deleteAllLevels();
                        edk::uint32 size = 0u;

                        edk::uint32 levelsSize = level;
                        level--;

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            free(temp);
                        }
                        edk::Cenario2D::LevelObj* levelTemp;
                        //test if the size is smaller
                        if(size<levelsSize){
                            return false;
                        }
                        //just load the levels
                        for(edk::uint32 i=0u;i<levelsSize;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                            //load the levelTemp
                            levelTemp = this->levels.get(i);
                            if(levelTemp){
                                //test if the levelTemp position is the level
                                if(i == level){
                                    this->deleteLevel(i+1);
                                    levelTemp->readFromXML(xml,i,&this->tileSet,this->world);
                                }
                            }
                            else{
                                levelTemp = new edk::Cenario2D::LevelObj(&this->calls);
                                if(levelTemp){
                                    //add the levelTemp to the tree
                                    this->levels.pushBack(levelTemp);
                                    //test if the levelTemp position is the level
                                    if(i == level){
                                        levelTemp->readFromXML(xml,i,&this->tileSet,this->world);
                                    }
                                }
                            }
                        }

                        //test if can't continue
                        if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                        this->loadPhysicObjectsToWorld();
                        xml->selectFather();
                    }

                    //JOINTS
                    if(xml->selectChild("joints")){
                        edk::uint32 size = 0u;
                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            free(temp);
                        }
                        //object vectors
                        bool collide;
                        edk::vec2f32 worldPosition;
                        edk::vec2f32 positionA;
                        edk::vec2f32 positionB;
                        for(edk::uint32 i = 0u;i<size;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

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
                                            free(temp);
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
                                            //                                            this->world->createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                        this->getPhysicsObjectInLevel(objectB),
                                            //                                                                        worldPosition,
                                            //                                                                        collide
                                            //                                                                        );
                                            this->world->createWeldJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                     worldPosition,
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerAngle")),
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperAngle")),
                                                //                                                                                     collide
                                                //                                                                                     );
                                                this->world->createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                     worldPosition,
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                     collide
                                                //                                                                                     );
                                                this->world->createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                worldPosition,
                                                //                                                                                collide
                                                //                                                                                );
                                                this->world->createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                 positionA,
                                                                                 this->getPhysicsObjectInLevel(objectB),
                                                                                 positionB,
                                                                                 collide
                                                                                 );
                                            }
                                            break;
                                        case EDK_DISTANCE_JOINT:
                                            //create distanceJoint
                                            //                                            this->world->createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                            worldPosition,
                                            //                                                                            this->getPhysicsObjectInLevel(objectB),
                                            //                                                                            edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBX")),
                                            //                                                                                         edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBY"))
                                            //                                                                                         ),
                                            //                                                                            collide);
                                            this->world->createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createPrismaticMotorJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                this->world->createPrismaticMotorJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createPrismaticJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                 this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                 worldPosition,
                                                //                                                                                 edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                              ),
                                                //                                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerDistance")),
                                                //                                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperDistance")),
                                                //                                                                                 collide
                                                //                                                                                 );
                                                this->world->createPrismaticJoint(this->getPhysicsObjectInLevel(objectA),
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
                                            //                                            this->world->createPulleyWorldJoint(this->getPhysicsObjectInLevel(objectA),
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
                                            this->world->createPulleyJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                  this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                  worldPosition,
                                                //                                                                                  edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                               ),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                  collide
                                                //                                                                                  );
                                                this->world->createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                   positionA,
                                                                                   this->getPhysicsObjectInLevel(objectB),
                                                                                   positionB,
                                                                                   edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                                edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                                ),
                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                   collide
                                                                                   );
                                            }
                                            else{
                                                //
                                                //                                                this->world->createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                             this->getPhysicsObjectInLevel(objectB),
                                                //                                                                             worldPosition,
                                                //                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                          ),
                                                //                                                                             collide
                                                //                                                                             );
                                                this->world->createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                                              positionA,
                                                                              this->getPhysicsObjectInLevel(objectB),
                                                                              positionB,
                                                                              edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                           edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                           ),
                                                                              collide
                                                                              );
                                            }
                                            break;
                                        case EDK_ROPE_JOINT:
                                            //
                                            //                                            this->world->createRopeJointWorldPositions(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                                      worldPosition,
                                            //                                                                                      this->getPhysicsObjectInLevel(objectB),
                                            //                                                                                      edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                            //                                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                            //                                                                                                   ),
                                            //                                                                                      edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
                                            //                                                                                      collide
                                            //                                                                                      );
                                            //REMOVED IN NEW BOX2D
                                            /*
                                            this->world->createRopeJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
                                                                        collide
                                                                        );
                                            */
                                            break;
                                        }
                                    }
                                    free(nameTemp);
                                }
                                free(idTemp);
                            }
                        }
                    }

                    ret=true;
                    xml->selectFather();

                    //test if can't continue
                    if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                    //generate the quadtree position and size
                    {
                        edk::Cenario2D::LevelObj* levelTemp=NULL;
                        {
                            levelTemp=this->levels.get(level);
                            if(levelTemp){
                                levelTemp->generateLevelRect();
                                levelTemp->addObjectsToQuad(this->minimunObjectsInQuads);
                            }
                        }
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
bool edk::Cenario2D::readLevelFromXML(const edk::char8* fileName,edk::uint32 level,edk::uint32 id){
    return this->readLevelFromXML((edk::char8*) fileName,level,id);
}
bool edk::Cenario2D::readLevelFromXML(edk::char8* fileName,edk::uint32 level,edk::uint32 id){
    //load the XML file
    if(fileName){
        this->setCanContinueTrue();
        edk::XML xml;
        if(xml.loadFile(fileName)){
            //load the cenario from the XML file

            //test if can't continue
            if(this->ifCantContinue()){return false;}

            return this->readLevelFromXML(&xml,level,id);
        }
    }
    return false;
}
bool edk::Cenario2D::readLevelFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 level,edk::uint32 id){
    if(xml && pack && level){
        this->setCanContinueTrue();
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

                    //read the levels
                    if(xml->selectChild("levels")){

                        //this->deleteAllLevels();
                        edk::uint32 size = 0u;
                        edk::uint32 levelsSize = level;
                        level--;

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            free(temp);
                        }
                        edk::Cenario2D::LevelObj* levelTemp;
                        //test if the size is smaller
                        if(size<levelsSize){
                            free(name); free(nameID); return false;
                        }
                        //just load the levels
                        for(edk::uint32 i=0u;i<levelsSize;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                            //load the levelTemp
                            levelTemp = this->levels.get(i);
                            if(levelTemp){
                                //test if the levelTemp position is the level
                                if(i == level){
                                    this->deleteLevel(i+1);
                                    levelTemp->readFromXMLFromPack(pack,xml,i,&this->tileSet,this->world);
                                }
                            }
                            else{
                                levelTemp = new edk::Cenario2D::LevelObj(&this->calls);
                                if(levelTemp){
                                    //add the levelTemp to the tree
                                    this->levels.pushBack(levelTemp);
                                    //test if the levelTemp position is the level
                                    if(i == level){
                                        levelTemp->readFromXMLFromPack(pack,xml,i,&this->tileSet,this->world);
                                    }
                                }
                            }
                        }

                        //test if can't continue
                        if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                        this->loadPhysicObjectsToWorld();
                        xml->selectFather();
                    }

                    //JOINTS
                    if(xml->selectChild("joints")){
                        edk::uint32 size = 0u;
                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            free(temp);
                        }
                        //object vectors
                        bool collide;
                        edk::vec2f32 worldPosition;
                        edk::vec2f32 positionA;
                        edk::vec2f32 positionB;
                        for(edk::uint32 i = 0u;i<size;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

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
                                            free(temp);
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
                                            //                                            this->world->createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                        this->getPhysicsObjectInLevel(objectB),
                                            //                                                                        worldPosition,
                                            //                                                                        collide
                                            //                                                                        );
                                            this->world->createWeldJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                     worldPosition,
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerAngle")),
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperAngle")),
                                                //                                                                                     collide
                                                //                                                                                     );
                                                this->world->createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                     worldPosition,
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                     collide
                                                //                                                                                     );
                                                this->world->createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                worldPosition,
                                                //                                                                                collide
                                                //                                                                                );
                                                this->world->createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                 positionA,
                                                                                 this->getPhysicsObjectInLevel(objectB),
                                                                                 positionB,
                                                                                 collide
                                                                                 );
                                            }
                                            break;
                                        case EDK_DISTANCE_JOINT:
                                            //create distanceJoint
                                            //                                            this->world->createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                            worldPosition,
                                            //                                                                            this->getPhysicsObjectInLevel(objectB),
                                            //                                                                            edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBX")),
                                            //                                                                                         edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBY"))
                                            //                                                                                         ),
                                            //                                                                            collide);
                                            this->world->createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createPrismaticMotorJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                this->world->createPrismaticMotorJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createPrismaticJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                 this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                 worldPosition,
                                                //                                                                                 edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                              ),
                                                //                                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerDistance")),
                                                //                                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperDistance")),
                                                //                                                                                 collide
                                                //                                                                                 );
                                                this->world->createPrismaticJoint(this->getPhysicsObjectInLevel(objectA),
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
                                            //                                            this->world->createPulleyWorldJoint(this->getPhysicsObjectInLevel(objectA),
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
                                            this->world->createPulleyJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                  this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                  worldPosition,
                                                //                                                                                  edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                               ),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                  collide
                                                //                                                                                  );
                                                this->world->createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                   positionA,
                                                                                   this->getPhysicsObjectInLevel(objectB),
                                                                                   positionB,
                                                                                   edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                                edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                                ),
                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                   collide
                                                                                   );
                                            }
                                            else{
                                                //
                                                //                                                this->world->createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                             this->getPhysicsObjectInLevel(objectB),
                                                //                                                                             worldPosition,
                                                //                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                          ),
                                                //                                                                             collide
                                                //                                                                             );
                                                this->world->createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                                              positionA,
                                                                              this->getPhysicsObjectInLevel(objectB),
                                                                              positionB,
                                                                              edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                           edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                           ),
                                                                              collide
                                                                              );
                                            }
                                            break;
                                        case EDK_ROPE_JOINT:
                                            //
                                            //                                            this->world->createRopeJointWorldPositions(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                                      worldPosition,
                                            //                                                                                      this->getPhysicsObjectInLevel(objectB),
                                            //                                                                                      edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                            //                                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                            //                                                                                                   ),
                                            //                                                                                      edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
                                            //                                                                                      collide
                                            //                                                                                      );
                                            //REMOVED IN NEW BOX2D
                                            /*
                                            this->world->createRopeJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
                                                                        collide
                                                                        );
                                            */
                                            break;
                                        }
                                    }
                                    free(nameTemp);
                                }
                                free(idTemp);
                            }
                        }
                    }

                    ret=true;
                    xml->selectFather();

                    //test if can't continue
                    if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                    //generate the quadtree position and size
                    {
                        edk::Cenario2D::LevelObj* levelTemp=NULL;
                        {
                            levelTemp=this->levels.get(level);
                            if(levelTemp){
                                levelTemp->generateLevelRect();
                                levelTemp->addObjectsToQuad(this->minimunObjectsInQuads);
                            }
                        }
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
bool edk::Cenario2D::readLevelFromXMLFromPack(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 level,edk::uint32 id){
    return this->readLevelFromXMLFromPack(pack,(edk::char8*) fileName,level,id);
}
bool edk::Cenario2D::readLevelFromXMLFromPack(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 level,edk::uint32 id){
    //load the XML file
    if(fileName && pack){
        this->setCanContinueTrue();
        edk::XML xml;

        if(edk::multi::Thread::isThisThreadMain()){
            while(true){
                //test if can tryLock
                if(pack->mutex.tryLock()){
                    //it lock
                    break;
                }
                else{
                    //else load textures from other threads
                    edk::GU::guUpdateLoadTextures();
                    edk::GU_GLSL::guUpdateCreateShaders();
                }
            }
        }
        else{
            pack->mutex.lock();
        }

        if(pack->readFileToBuffer(fileName)){
            if(xml.loadFromMemory(pack->getBuffer(),pack->getBufferSize())){
                pack->mutex.unlock();
                //load the cenario from the XML file

                //test if can't continue
                if(this->ifCantContinue()){return false;}

                return this->readLevelFromXMLFromPack(pack,&xml,level,id);
            }
            else{
                pack->mutex.unlock();
            }
        }
        else{
            pack->mutex.unlock();
        }
    }
    return false;
}
//read levels from XML
bool edk::Cenario2D::readLevelsFromXML(edk::XML* xml,edk::uint32 levelStart,edk::uint32 levelEnd,edk::uint32 id){
    if(xml && levelStart && levelEnd){
        this->setCanContinueTrue();
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

                    //read the levels
                    if(xml->selectChild("levels")){

                        //this->deleteAllLevels();
                        edk::uint32 size = 0u;

                        edk::uint32 levelsSize = levelEnd;
                        levelEnd--;

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            free(temp);
                        }
                        edk::Cenario2D::LevelObj* levelTemp;
                        //test if the size is smaller
                        if(size<levelStart){
                            free(name); free(nameID); return false;
                        }
                        levelStart--;
                        //just load the levels
                        for(edk::uint32 i=0u;i<levelsSize;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                            //load the levelTemp
                            levelTemp = this->levels.get(i);
                            if(levelTemp){
                                //test if the levelTemp position is the level
                                if(i >= levelStart && i <= levelEnd){
                                    this->deleteLevel(i+1);
                                    levelTemp->readFromXML(xml,i,&this->tileSet,this->world);
                                }
                            }
                            else{
                                levelTemp = new edk::Cenario2D::LevelObj(&this->calls);
                                if(levelTemp){
                                    //add the levelTemp to the tree
                                    this->levels.pushBack(levelTemp);
                                    //test if the levelTemp position is the level
                                    if(i >= levelStart && i <= levelEnd){
                                        levelTemp->readFromXML(xml,i,&this->tileSet,this->world);
                                    }
                                }
                            }
                        }

                        //test if can't continue
                        if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                        this->loadPhysicObjectsToWorld();
                        xml->selectFather();
                    }

                    //JOINTS
                    if(xml->selectChild("joints")){
                        edk::uint32 size = 0u;
                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            free(temp);
                        }
                        //object vectors
                        bool collide;
                        edk::vec2f32 worldPosition;
                        edk::vec2f32 positionA;
                        edk::vec2f32 positionB;
                        for(edk::uint32 i = 0u;i<size;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

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
                                            free(temp);
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
                                            //                                            this->world->createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                        this->getPhysicsObjectInLevel(objectB),
                                            //                                                                        worldPosition,
                                            //                                                                        collide
                                            //                                                                        );
                                            this->world->createWeldJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                     worldPosition,
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerAngle")),
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperAngle")),
                                                //                                                                                     collide
                                                //                                                                                     );
                                                this->world->createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                     worldPosition,
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                     collide
                                                //                                                                                     );
                                                this->world->createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                worldPosition,
                                                //                                                                                collide
                                                //                                                                                );
                                                this->world->createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                 positionA,
                                                                                 this->getPhysicsObjectInLevel(objectB),
                                                                                 positionB,
                                                                                 collide
                                                                                 );
                                            }
                                            break;
                                        case EDK_DISTANCE_JOINT:
                                            //create distanceJoint
                                            //                                            this->world->createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                            worldPosition,
                                            //                                                                            this->getPhysicsObjectInLevel(objectB),
                                            //                                                                            edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBX")),
                                            //                                                                                         edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBY"))
                                            //                                                                                         ),
                                            //                                                                            collide);
                                            this->world->createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createPrismaticMotorJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                this->world->createPrismaticMotorJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createPrismaticJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                 this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                 worldPosition,
                                                //                                                                                 edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                              ),
                                                //                                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerDistance")),
                                                //                                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperDistance")),
                                                //                                                                                 collide
                                                //                                                                                 );
                                                this->world->createPrismaticJoint(this->getPhysicsObjectInLevel(objectA),
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
                                            //                                            this->world->createPulleyWorldJoint(this->getPhysicsObjectInLevel(objectA),
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
                                            this->world->createPulleyJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                  this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                  worldPosition,
                                                //                                                                                  edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                               ),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                  collide
                                                //                                                                                  );
                                                this->world->createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                   positionA,
                                                                                   this->getPhysicsObjectInLevel(objectB),
                                                                                   positionB,
                                                                                   edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                                edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                                ),
                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                   collide
                                                                                   );
                                            }
                                            else{
                                                //
                                                //                                                this->world->createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                             this->getPhysicsObjectInLevel(objectB),
                                                //                                                                             worldPosition,
                                                //                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                          ),
                                                //                                                                             collide
                                                //                                                                             );
                                                this->world->createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                                              positionA,
                                                                              this->getPhysicsObjectInLevel(objectB),
                                                                              positionB,
                                                                              edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                           edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                           ),
                                                                              collide
                                                                              );
                                            }
                                            break;
                                        case EDK_ROPE_JOINT:
                                            //
                                            //                                            this->world->createRopeJointWorldPositions(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                                      worldPosition,
                                            //                                                                                      this->getPhysicsObjectInLevel(objectB),
                                            //                                                                                      edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                            //                                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                            //                                                                                                   ),
                                            //                                                                                      edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
                                            //                                                                                      collide
                                            //                                                                                      );
                                            //REMOVED IN NEW BOX2D
                                            /*
                                            this->world->createRopeJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
                                                                        collide
                                                                        );
                                            */
                                            break;
                                        }
                                    }
                                    free(nameTemp);
                                }
                                free(idTemp);
                            }
                        }
                    }

                    ret=true;
                    xml->selectFather();

                    //test if can't continue
                    if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                    //generate the quadtree position and size
                    for(edk::uint32 i=levelStart;i<=levelEnd;i++){
                        edk::Cenario2D::LevelObj* levelTemp=NULL;
                        {
                            if(i >= levelStart && i <= levelEnd){
                                levelTemp=this->levels.get(i);
                                if(levelTemp){
                                    levelTemp->generateLevelRect();
                                    levelTemp->addObjectsToQuad(this->minimunObjectsInQuads);
                                }
                            }
                        }
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
bool edk::Cenario2D::readLevelsFromXML(const edk::char8* fileName,edk::uint32 levelStart,edk::uint32 levelEnd,edk::uint32 id){
    return this->readLevelsFromXML((edk::char8*) fileName,levelStart,levelEnd,id);
}
bool edk::Cenario2D::readLevelsFromXML(edk::char8* fileName,edk::uint32 levelStart,edk::uint32 levelEnd,edk::uint32 id){
    //load the XML file
    if(fileName){
        this->setCanContinueTrue();
        edk::XML xml;
        if(xml.loadFile(fileName)){
            //load the cenario from the XML file

            //test if can't continue
            if(this->ifCantContinue()){return false;}

            return this->readLevelsFromXML(&xml,levelStart,levelEnd,id);
        }
    }
    return false;
}
bool edk::Cenario2D::readLevelsFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 levelStart,edk::uint32 levelEnd,edk::uint32 id){
    if(xml && pack && levelStart && levelEnd){
        this->setCanContinueTrue();
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

                    //read the levels
                    if(xml->selectChild("levels")){

                        //this->deleteAllLevels();
                        edk::uint32 size = 0u;
                        edk::uint32 levelsSize = levelEnd;
                        levelEnd--;

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            free(temp);
                        }
                        edk::Cenario2D::LevelObj* levelTemp;
                        //test if the size is smaller
                        if(size<levelStart){
                            free(name); free(nameID); return false;
                        }
                        levelStart--;
                        //just load the levels
                        for(edk::uint32 i=0u;i<levelsSize;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                            //load the levelTemp
                            levelTemp = this->levels.get(i);
                            if(levelTemp){
                                //test if the levelTemp position is the level
                                if(i >= levelStart && i <= levelEnd){
                                    this->deleteLevel(i+1);
                                    levelTemp->readFromXMLFromPack(pack,xml,i,&this->tileSet,this->world);
                                }
                            }
                            else{
                                levelTemp = new edk::Cenario2D::LevelObj(&this->calls);
                                if(levelTemp){
                                    //add the levelTemp to the tree
                                    this->levels.pushBack(levelTemp);
                                    //test if the levelTemp position is the level
                                    if(i >= levelStart && i <= levelEnd){
                                        levelTemp->readFromXMLFromPack(pack,xml,i,&this->tileSet,this->world);
                                    }
                                }
                            }
                        }

                        //test if can't continue
                        if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                        this->loadPhysicObjectsToWorld();
                        xml->selectFather();
                    }

                    //JOINTS
                    if(xml->selectChild("joints")){
                        edk::uint32 size = 0u;
                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            free(temp);
                        }
                        //object vectors
                        bool collide;
                        edk::vec2f32 worldPosition;
                        edk::vec2f32 positionA;
                        edk::vec2f32 positionB;
                        for(edk::uint32 i = 0u;i<size;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

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
                                            free(temp);
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
                                            //                                            this->world->createWeldJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                        this->getPhysicsObjectInLevel(objectB),
                                            //                                                                        worldPosition,
                                            //                                                                        collide
                                            //                                                                        );
                                            this->world->createWeldJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                     worldPosition,
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerAngle")),
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperAngle")),
                                                //                                                                                     collide
                                                //                                                                                     );
                                                this->world->createRevoluteAngleJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                     this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                     worldPosition,
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                     edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                     collide
                                                //                                                                                     );
                                                this->world->createRevoluteMotorJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                worldPosition,
                                                //                                                                                collide
                                                //                                                                                );
                                                this->world->createRevoluteJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                 positionA,
                                                                                 this->getPhysicsObjectInLevel(objectB),
                                                                                 positionB,
                                                                                 collide
                                                                                 );
                                            }
                                            break;
                                        case EDK_DISTANCE_JOINT:
                                            //create distanceJoint
                                            //                                            this->world->createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                            worldPosition,
                                            //                                                                            this->getPhysicsObjectInLevel(objectB),
                                            //                                                                            edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBX")),
                                            //                                                                                         edk::String::strToFloat32(xml->getSelectedAttributeValueByName("worldPositionBY"))
                                            //                                                                                         ),
                                            //                                                                            collide);
                                            this->world->createDistanceJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createPrismaticMotorJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                this->world->createPrismaticMotorJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createPrismaticJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                 this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                 worldPosition,
                                                //                                                                                 edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                              ),
                                                //                                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("lowerDistance")),
                                                //                                                                                 edk::String::strToFloat32(xml->getSelectedAttributeValueByName("upperDistance")),
                                                //                                                                                 collide
                                                //                                                                                 );
                                                this->world->createPrismaticJoint(this->getPhysicsObjectInLevel(objectA),
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
                                            //                                            this->world->createPulleyWorldJoint(this->getPhysicsObjectInLevel(objectA),
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
                                            this->world->createPulleyJoint(this->getPhysicsObjectInLevel(objectA),
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
                                                //                                                this->world->createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                                  this->getPhysicsObjectInLevel(objectB),
                                                //                                                                                  worldPosition,
                                                //                                                                                  edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                               ),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                //                                                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                //                                                                                  collide
                                                //                                                                                  );
                                                this->world->createWheelMotorJoint(this->getPhysicsObjectInLevel(objectA),
                                                                                   positionA,
                                                                                   this->getPhysicsObjectInLevel(objectB),
                                                                                   positionB,
                                                                                   edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                                edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                                ),
                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxTorque")),
                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("speed")),
                                                                                   collide
                                                                                   );
                                            }
                                            else{
                                                //
                                                //                                                this->world->createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                //                                                                             this->getPhysicsObjectInLevel(objectB),
                                                //                                                                             worldPosition,
                                                //                                                                             edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                //                                                                                          edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                //                                                                                          ),
                                                //                                                                             collide
                                                //                                                                             );
                                                this->world->createWheelJoint(this->getPhysicsObjectInLevel(objectA),
                                                                              positionA,
                                                                              this->getPhysicsObjectInLevel(objectB),
                                                                              positionB,
                                                                              edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                                                                           edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                                                                           ),
                                                                              collide
                                                                              );
                                            }
                                            break;
                                        case EDK_ROPE_JOINT:
                                            //
                                            //                                            this->world->createRopeJointWorldPositions(this->getPhysicsObjectInLevel(objectA),
                                            //                                                                                      worldPosition,
                                            //                                                                                      this->getPhysicsObjectInLevel(objectB),
                                            //                                                                                      edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionX")),
                                            //                                                                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("directionY"))
                                            //                                                                                                   ),
                                            //                                                                                      edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
                                            //                                                                                      collide
                                            //                                                                                      );
                                            //REMOVED IN NEW BOX2D
                                            /*
                                            this->world->createRopeJoint(this->getPhysicsObjectInLevel(objectA),
                                                                        positionA,
                                                                        this->getPhysicsObjectInLevel(objectB),
                                                                        positionB,
                                                                        edk::String::strToFloat32(xml->getSelectedAttributeValueByName("maxLength")),
                                                                        collide
                                                                        );
                                            */
                                            break;
                                        }
                                    }
                                    free(nameTemp);
                                }
                                free(idTemp);
                            }
                        }
                    }

                    ret=true;
                    xml->selectFather();

                    //test if can't continue
                    if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                    //generate the quadtree position and size
                    for(edk::uint32 i=levelStart;i<=levelEnd;i++){
                        if(i >= levelStart && i <= levelEnd){
                            edk::Cenario2D::LevelObj* levelTemp=NULL;
                            {
                                levelTemp=this->levels.get(i);
                                if(levelTemp){
                                    levelTemp->generateLevelRect();
                                    levelTemp->addObjectsToQuad(this->minimunObjectsInQuads);
                                }
                            }
                        }
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
bool edk::Cenario2D::readLevelsFromXMLFromPack(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 levelStart,edk::uint32 levelEnd,edk::uint32 id){
    return this->readLevelsFromXMLFromPack(pack,(edk::char8*) fileName,levelStart,levelEnd,id);
}
bool edk::Cenario2D::readLevelsFromXMLFromPack(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 levelStart,edk::uint32 levelEnd,edk::uint32 id){
    //load the XML file
    if(fileName && pack){
        this->setCanContinueTrue();
        edk::XML xml;

        if(edk::multi::Thread::isThisThreadMain()){
            while(true){
                //test if can tryLock
                if(pack->mutex.tryLock()){
                    //it lock
                    break;
                }
                else{
                    //else load textures from other threads
                    edk::GU::guUpdateLoadTextures();
                    edk::GU_GLSL::guUpdateCreateShaders();
                }
            }
        }
        else{
            pack->mutex.lock();
        }

        if(pack->readFileToBuffer(fileName)){
            if(xml.loadFromMemory(pack->getBuffer(),pack->getBufferSize())){
                pack->mutex.unlock();
                //load the cenario from the XML file

                //test if can't continue
                if(this->ifCantContinue()){return false;}

                return this->readLevelsFromXMLFromPack(pack,&xml,levelStart,levelEnd,id);
            }
            else{
                pack->mutex.unlock();
            }
        }
        else{
            pack->mutex.unlock();
        }
    }
    return false;
}
//read from XML without load physics objects in to the world
bool edk::Cenario2D::readFromXMLWithoutLoadPhysics(edk::XML* xml,edk::uint32 id){
    if(xml){
        this->setCanContinueTrue();
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
                    //edk::char8* nameTemp;
                    //edk::char8* idTemp;
                    edk::char8* temp;

                    if(xml->selectChild("meters")){
                        this->world->setMeterDistance(xml->getSelectedStringAsFloat32());
                        xml->selectFather();
                    }

                    //test if can't continue
                    if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                    //read tileSet
                    this->tileSet.readFromXML(xml,0u);
                    //read the levels
                    if(xml->selectChild("levels")){

                        this->deleteAllLevels();
                        edk::uint32 size = 0u;

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            free(temp);
                        }
                        edk::Cenario2D::LevelObj* level;
                        for(edk::uint32 i=0u;i<size;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                            //load the level
                            level = new edk::Cenario2D::LevelObj(&this->calls);
                            if(level){
                                //add the level to the tree
                                this->levels.pushBack(level);
                                level->readFromXML(xml,i,&this->tileSet,this->world);
                            }
                        }
                        //this->loadPhysicObjectsToWorld();
                        xml->selectFather();
                    }

                    //test if can't continue
                    if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                    //ACTIONS
                    this->actions.readFromXML(xml,0u,this);

                    ret=true;
                    xml->selectFather();

                    //generate the quadtree position and size
                    {
                        edk::uint32 size = this->levels.size();
                        edk::Cenario2D::LevelObj* level=NULL;
                        for(edk::uint32 i=0u;i<size;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                            level=this->levels.get(i);
                            if(level){
                                level->generateLevelRect();
                                level->addObjectsToQuad(this->minimunObjectsInQuads);
                            }
                        }
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
bool edk::Cenario2D::readFromXMLWithoutLoadPhysics(const edk::char8* fileName,edk::uint32 id){
    return this->readFromXMLWithoutLoadPhysics((edk::char8*) fileName,id);
}
bool edk::Cenario2D::readFromXMLWithoutLoadPhysics(edk::char8* fileName,edk::uint32 id){
    //load the XML file
    if(fileName){
        this->setCanContinueTrue();
        edk::XML xml;
        if(xml.loadFile(fileName)){
            //load the cenario from the XML file

            //test if can't continue
            if(this->ifCantContinue()){return false;}

            return this->readFromXMLWithoutLoadPhysics(&xml,id);
        }
    }
    return false;
}
bool edk::Cenario2D::readFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    if(xml && pack){
        this->setCanContinueTrue();
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
                    //edk::char8* nameTemp;
                    //edk::char8* idTemp;
                    edk::char8* temp;

                    if(xml->selectChild("meters")){
                        this->world->setMeterDistance(xml->getSelectedStringAsFloat32());
                        xml->selectFather();
                    }

                    //test if can't continue
                    if(this->ifCantContinue()){free(name); free(nameID); return false;}

                    //read tileSet
                    this->tileSet.readFromXMLFromPack(pack,xml,0u);
                    //read the levels
                    if(xml->selectChild("levels")){

                        this->deleteAllLevels();
                        edk::uint32 size = 0u;

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            free(temp);
                        }
                        edk::Cenario2D::LevelObj* level;
                        for(edk::uint32 i=0u;i<size;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                            //load the level
                            level = new edk::Cenario2D::LevelObj(&this->calls);
                            if(level){
                                //add the level to the tree
                                this->levels.pushBack(level);
                                level->readFromXMLFromPack(pack,xml,i,&this->tileSet,this->world);
                            }
                        }
                        //this->loadPhysicObjectsToWorld();
                        xml->selectFather();
                    }

                    //test if can't continue
                    if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                    //ACTIONS
                    this->actions.readFromXML(xml,0u,this);

                    ret=true;
                    xml->selectFather();

                    //generate the quadtree position and size
                    {
                        edk::uint32 size = this->levels.size();
                        edk::Cenario2D::LevelObj* level=NULL;
                        for(edk::uint32 i=0u;i<size;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                            level=this->levels.get(i);
                            if(level){
                                level->generateLevelRect();
                                level->addObjectsToQuad(this->minimunObjectsInQuads);
                            }
                        }
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
bool edk::Cenario2D::readFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 id){
    return this->readFromXMLFromPackWithoutLoadPhysics(pack,(edk::char8*) fileName,id);
}
bool edk::Cenario2D::readFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 id){
    //load the XML file
    if(fileName && pack){
        this->setCanContinueTrue();
        edk::XML xml;

        if(edk::multi::Thread::isThisThreadMain()){
            while(true){
                //test if can tryLock
                if(pack->mutex.tryLock()){
                    //it lock
                    break;
                }
                else{
                    //else load textures from other threads
                    edk::GU::guUpdateLoadTextures();
                    edk::GU_GLSL::guUpdateCreateShaders();
                }
            }
        }
        else{
            pack->mutex.lock();
        }

        if(pack->readFileToBuffer(fileName)){
            if(xml.loadFromMemory(pack->getBuffer(),pack->getBufferSize())){
                pack->mutex.unlock();
                //load the cenario from the XML file

                //test if can't continue
                if(this->ifCantContinue()){return false;}

                return this->readFromXMLFromPackWithoutLoadPhysics(pack,&xml,id);
            }
            else{
                pack->mutex.unlock();
            }
        }
        else{
            pack->mutex.unlock();
        }
    }
    return false;
}
//read level from XML without load physics objects in to the world
bool edk::Cenario2D::readLevelFromXMLWithoutLoadPhysics(edk::XML* xml,edk::uint32 level,edk::uint32 id){
    if(xml && level){
        this->setCanContinueTrue();
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
                    //edk::char8* nameTemp;
                    //edk::char8* idTemp;
                    edk::char8* temp;

                    //read the levels
                    if(xml->selectChild("levels")){

                        //this->deleteAllLevels();
                        edk::uint32 size = 0u;

                        edk::uint32 levelsSize = level;
                        level--;

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            free(temp);
                        }
                        edk::Cenario2D::LevelObj* levelTemp;
                        //test if the size is smaller
                        if(size<levelsSize){
                            free(name); free(nameID); return false;
                        }
                        //just load the levels
                        for(edk::uint32 i=0u;i<levelsSize;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                            //load the levelTemp
                            levelTemp = this->levels.get(i);
                            if(levelTemp){
                                //test if the levelTemp position is the level
                                if(i == level){
                                    this->deleteLevel(i+1u);
                                    levelTemp->readFromXML(xml,i,&this->tileSet,this->world);
                                }
                            }
                            else{
                                //create the new level
                                levelTemp = new edk::Cenario2D::LevelObj(&this->calls);
                                if(levelTemp){
                                    //add the levelTemp to the tree
                                    this->levels.pushBack(levelTemp);
                                    if(i == level){
                                        levelTemp->readFromXML(xml,i,&this->tileSet,this->world);
                                    }
                                }
                            }
                        }
                        //this->loadPhysicObjectsToWorld();
                        xml->selectFather();
                    }

                    ret=true;
                    xml->selectFather();

                    //test if can't continue
                    if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                    //generate the quadtree position and size
                    {
                        edk::Cenario2D::LevelObj* levelTemp=NULL;
                        {
                            levelTemp=this->levels.get(level);
                            if(levelTemp){
                                levelTemp->generateLevelRect();
                                levelTemp->addObjectsToQuad(this->minimunObjectsInQuads);
                            }
                        }
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
bool edk::Cenario2D::readLevelFromXMLWithoutLoadPhysics(const edk::char8* fileName,edk::uint32 level,edk::uint32 id){
    return this->readLevelFromXMLWithoutLoadPhysics((edk::char8*) fileName,level,id);
}
bool edk::Cenario2D::readLevelFromXMLWithoutLoadPhysics(edk::char8* fileName,edk::uint32 level,edk::uint32 id){
    //load the XML file
    if(fileName){
        this->setCanContinueTrue();
        edk::XML xml;
        if(xml.loadFile(fileName)){
            //load the cenario from the XML file

            //test if can't continue
            if(this->ifCantContinue()){this->deleteAllLevels();return false;}

            return this->readLevelFromXMLWithoutLoadPhysics(&xml,level,id);
        }
    }
    return false;
}
bool edk::Cenario2D::readLevelFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 level,edk::uint32 id){
    if(xml && pack && level){
        this->setCanContinueTrue();
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
                    //edk::char8* nameTemp;
                    //edk::char8* idTemp;
                    edk::char8* temp;

                    //read the levels
                    if(xml->selectChild("levels")){

                        //this->deleteAllLevels();
                        edk::uint32 size = 0u;

                        edk::uint32 levelsSize = level;
                        level--;

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            free(temp);
                        }
                        edk::Cenario2D::LevelObj* levelTemp;
                        //test if the size is smaller
                        if(size<levelsSize){
                            free(name); free(nameID); return false;
                        }
                        //just load the levels
                        for(edk::uint32 i=0u;i<levelsSize;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                            //load the levelTemp
                            levelTemp = this->levels.get(i);
                            if(levelTemp){
                                //test if the levelTemp position is the level
                                if(i == level){
                                    this->deleteLevel(i+1);
                                    levelTemp->readFromXMLFromPack(pack,xml,i,&this->tileSet,this->world);
                                }
                            }
                            else{
                                levelTemp = new edk::Cenario2D::LevelObj(&this->calls);
                                if(levelTemp){
                                    //add the levelTemp to the tree
                                    this->levels.pushBack(levelTemp);
                                    //test if the levelTemp position is the level
                                    if(i == level){
                                        levelTemp->readFromXMLFromPack(pack,xml,i,&this->tileSet,this->world);
                                    }
                                }
                            }
                        }
                        //this->loadPhysicObjectsToWorld();
                        xml->selectFather();
                    }

                    ret=true;
                    xml->selectFather();

                    //test if can't continue
                    if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                    //generate the quadtree position and size
                    {
                        edk::Cenario2D::LevelObj* levelTemp=NULL;
                        {
                            levelTemp=this->levels.get(level);
                            if(levelTemp){
                                levelTemp->generateLevelRect();
                                levelTemp->addObjectsToQuad(this->minimunObjectsInQuads);
                            }
                        }
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
bool edk::Cenario2D::readLevelFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 level,edk::uint32 id){
    return this->readLevelFromXMLFromPackWithoutLoadPhysics(pack,(edk::char8*) fileName,level,id);
}
bool edk::Cenario2D::readLevelFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 level,edk::uint32 id){
    //load the XML file
    if(fileName && pack){
        this->setCanContinueTrue();
        edk::XML xml;

        if(edk::multi::Thread::isThisThreadMain()){
            while(true){
                //test if can tryLock
                if(pack->mutex.tryLock()){
                    //it lock
                    break;
                }
                else{
                    //else load textures from other threads
                    edk::GU::guUpdateLoadTextures();
                    edk::GU_GLSL::guUpdateCreateShaders();
                }
            }
        }
        else{
            pack->mutex.lock();
        }

        if(pack->readFileToBuffer(fileName)){
            if(xml.loadFromMemory(pack->getBuffer(),pack->getBufferSize())){
                pack->mutex.unlock();
                //load the cenario from the XML file

                //test if can't continue
                if(this->ifCantContinue()){this->deleteAllLevels();return false;}

                return this->readLevelFromXMLFromPackWithoutLoadPhysics(pack,&xml,level,id);
            }
            else{
                pack->mutex.unlock();
            }
        }
        else{
            pack->mutex.unlock();
        }
    }
    return false;
}
//read levels from XML without load physics objects in to the world
bool edk::Cenario2D::readLevelsFromXMLWithoutLoadPhysics(edk::XML* xml,edk::uint32 levelStart,edk::uint32 levelEnd,edk::uint32 id){
    if(xml && levelStart && levelEnd){
        this->setCanContinueTrue();
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
                    //edk::char8* nameTemp;
                    //edk::char8* idTemp;
                    edk::char8* temp;

                    //read the levels
                    if(xml->selectChild("levels")){

                        //this->deleteAllLevels();
                        edk::uint32 size = 0u;

                        edk::uint32 levelsSize = levelEnd;
                        levelEnd--;

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            free(temp);
                        }
                        edk::Cenario2D::LevelObj* levelTemp;
                        //test if the size is smaller
                        if(size<levelStart){
                            free(name); free(nameID); return false;
                        }
                        levelStart--;
                        //just load the levels
                        for(edk::uint32 i=0u;i<levelsSize;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                            //load the levelTemp
                            levelTemp = this->levels.get(i);
                            if(levelTemp){
                                //test if the levelTemp position is the level
                                if(i >= levelStart && i <= levelEnd){
                                    this->deleteLevel(i+1u);
                                    levelTemp->readFromXML(xml,i,&this->tileSet,this->world);
                                }
                            }
                            else{
                                //create the new level
                                levelTemp = new edk::Cenario2D::LevelObj(&this->calls);
                                if(levelTemp){
                                    //add the levelTemp to the tree
                                    this->levels.pushBack(levelTemp);
                                    if(i >= levelStart && i <= levelEnd){
                                        levelTemp->readFromXML(xml,i,&this->tileSet,this->world);
                                    }
                                }
                            }
                        }
                        //this->loadPhysicObjectsToWorld();
                        xml->selectFather();
                    }

                    ret=true;
                    xml->selectFather();

                    //test if can't continue
                    if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                    //generate the quadtree position and size
                    for(edk::uint32 i=levelStart;i<=levelEnd;i++){
                        if(i >= levelStart && i <= levelEnd){
                            edk::Cenario2D::LevelObj* levelTemp=NULL;
                            {
                                levelTemp=this->levels.get(i);
                                if(levelTemp){
                                    levelTemp->generateLevelRect();
                                    levelTemp->addObjectsToQuad(this->minimunObjectsInQuads);
                                }
                            }
                        }
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
bool edk::Cenario2D::readLevelsFromXMLWithoutLoadPhysics(const edk::char8* fileName,edk::uint32 levelStart,edk::uint32 levelEnd,edk::uint32 id){
    return this->readLevelsFromXMLWithoutLoadPhysics((edk::char8*) fileName,levelStart,levelEnd,id);
}
bool edk::Cenario2D::readLevelsFromXMLWithoutLoadPhysics(edk::char8* fileName,edk::uint32 levelStart,edk::uint32 levelEnd,edk::uint32 id){
    //load the XML file
    if(fileName){
        this->setCanContinueTrue();
        edk::XML xml;
        if(xml.loadFile(fileName)){
            //load the cenario from the XML file

            //test if can't continue
            if(this->ifCantContinue()){this->deleteAllLevels();return false;}

            return this->readLevelsFromXMLWithoutLoadPhysics(&xml,levelStart,levelEnd,id);
        }
    }
    return false;
}
bool edk::Cenario2D::readLevelsFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 levelStart,edk::uint32 levelEnd,edk::uint32 id){
    if(xml && pack && levelStart && levelEnd){
        this->setCanContinueTrue();
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
                    //edk::char8* nameTemp;
                    //edk::char8* idTemp;
                    edk::char8* temp;

                    //read the levels
                    if(xml->selectChild("levels")){

                        //this->deleteAllLevels();
                        edk::uint32 size = 0u;

                        edk::uint32 levelsSize = levelEnd;
                        levelEnd--;

                        temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                        if(temp){
                            size = edk::String::strToInt64(temp);
                            free(temp);
                        }
                        edk::Cenario2D::LevelObj* levelTemp;
                        //test if the size is smaller
                        if(size<levelStart){
                            free(name); free(nameID); return false;
                        }
                        levelStart--;
                        //just load the levels
                        for(edk::uint32 i=0u;i<levelsSize;i++){

                            //test if can't continue
                            if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                            //load the levelTemp
                            levelTemp = this->levels.get(i);
                            if(levelTemp){
                                //test if the levelTemp position is the level
                                if(i >= levelStart && i <= levelEnd){
                                    this->deleteLevel(i+1);
                                    levelTemp->readFromXMLFromPack(pack,xml,i,&this->tileSet,this->world);
                                }
                            }
                            else{
                                levelTemp = new edk::Cenario2D::LevelObj(&this->calls);
                                if(levelTemp){
                                    //add the levelTemp to the tree
                                    this->levels.pushBack(levelTemp);
                                    //test if the levelTemp position is the level
                                    if(i >= levelStart && i <= levelEnd){
                                        levelTemp->readFromXMLFromPack(pack,xml,i,&this->tileSet,this->world);
                                    }
                                }
                            }
                        }
                        //this->loadPhysicObjectsToWorld();
                        xml->selectFather();
                    }

                    ret=true;
                    xml->selectFather();

                    //test if can't continue
                    if(this->ifCantContinue()){this->deleteAllLevels();free(name); free(nameID); return false;}

                    //generate the quadtree position and size
                    for(edk::uint32 i=levelStart;i<=levelEnd;i++){
                        if(i >= levelStart && i <= levelEnd){
                            edk::Cenario2D::LevelObj* levelTemp=NULL;
                            {
                                levelTemp=this->levels.get(i);
                                if(levelTemp){
                                    levelTemp->generateLevelRect();
                                    levelTemp->addObjectsToQuad(this->minimunObjectsInQuads);
                                }
                            }
                        }
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
bool edk::Cenario2D::readLevelsFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 levelStart,edk::uint32 levelEnd,edk::uint32 id){
    return this->readLevelsFromXMLFromPackWithoutLoadPhysics(pack,(edk::char8*) fileName,levelStart,levelEnd,id);
}
bool edk::Cenario2D::readLevelsFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 levelStart,edk::uint32 levelEnd,edk::uint32 id){
    //load the XML file
    if(fileName && pack){
        this->setCanContinueTrue();
        edk::XML xml;

        if(edk::multi::Thread::isThisThreadMain()){
            while(true){
                //test if can tryLock
                if(pack->mutex.tryLock()){
                    //it lock
                    break;
                }
                else{
                    //else load textures from other threads
                    edk::GU::guUpdateLoadTextures();
                    edk::GU_GLSL::guUpdateCreateShaders();
                }
            }
        }
        else{
            pack->mutex.lock();
        }

        if(pack->readFileToBuffer(fileName)){
            if(xml.loadFromMemory(pack->getBuffer(),pack->getBufferSize())){
                pack->mutex.unlock();
                //load the cenario from the XML file

                //test if can't continue
                if(this->ifCantContinue()){this->deleteAllLevels();return false;}

                return this->readLevelsFromXMLFromPackWithoutLoadPhysics(pack,&xml,levelStart,levelEnd,id);
            }
            else{
                pack->mutex.unlock();
            }
        }
        else{
            pack->mutex.unlock();
        }
    }
    return false;
}
//Without id
bool edk::Cenario2D::writeToXML(edk::XML* xml){
    return this->writeToXML(xml,0u);
}
bool edk::Cenario2D::writeToXML(const edk::char8* fileName){
    return this->writeToXML(fileName,0u);
}
bool edk::Cenario2D::writeToXML(edk::char8* fileName){
    return this->writeToXML(fileName,0u);
}
//read from XML
bool edk::Cenario2D::readFromXML(edk::XML* xml){
    return this->readFromXML(xml,0u);
}
bool edk::Cenario2D::readFromXML(const edk::char8* fileName){
    return this->readFromXML(fileName,0u);
}
bool edk::Cenario2D::readFromXML(edk::char8* fileName){
    return this->readFromXML(fileName,0u);
}
bool edk::Cenario2D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml){
    return this->readFromXMLFromPack(pack,xml,0u);
}
bool edk::Cenario2D::readFromXMLFromPack(edk::pack::FilePackage* pack,const edk::char8* fileName){
    return this->readFromXMLFromPack(pack,fileName,0u);
}
bool edk::Cenario2D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::char8* fileName){
    return this->readFromXMLFromPack(pack,fileName,0u);
}
//read level from XML
bool edk::Cenario2D::readLevelFromXML(edk::XML* xml,edk::uint32 level){
    return this->readLevelFromXML(xml,0u,level);
}
bool edk::Cenario2D::readLevelFromXML(const edk::char8* fileName,edk::uint32 level){
    return this->readLevelFromXML(fileName,level,0u);
}
bool edk::Cenario2D::readLevelFromXML(edk::char8* fileName,edk::uint32 level){
    return this->readLevelFromXML(fileName,level,0u);
}
bool edk::Cenario2D::readLevelFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 level){
    return this->readLevelFromXMLFromPack(pack,xml,level,0u);
}
bool edk::Cenario2D::readLevelFromXMLFromPack(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 level){
    return this->readLevelFromXMLFromPack(pack,fileName,level,0u);
}
bool edk::Cenario2D::readLevelFromXMLFromPack(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 level){
    return this->readLevelFromXMLFromPack(pack,fileName,level,0u);
}
//read levels from XML
bool edk::Cenario2D::readLevelsFromXML(edk::XML* xml,edk::uint32 levelStart,edk::uint32 levelEnd){
    return this->readLevelsFromXML(xml,0u,levelStart,levelEnd);
}
bool edk::Cenario2D::readLevelsFromXML(const edk::char8* fileName,edk::uint32 levelStart,edk::uint32 levelEnd){
    return this->readLevelsFromXML(fileName,levelStart,levelEnd,0u);
}
bool edk::Cenario2D::readLevelsFromXML(edk::char8* fileName,edk::uint32 levelStart,edk::uint32 levelEnd){
    return this->readLevelsFromXML(fileName,levelStart,levelEnd,0u);
}
bool edk::Cenario2D::readLevelsFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 levelStart,edk::uint32 levelEnd){
    return this->readLevelsFromXMLFromPack(pack,xml,levelStart,levelEnd,0u);
}
bool edk::Cenario2D::readLevelsFromXMLFromPack(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 levelStart,edk::uint32 levelEnd){
    return this->readLevelsFromXMLFromPack(pack,fileName,levelStart,levelEnd,0u);
}
bool edk::Cenario2D::readLevelsFromXMLFromPack(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 levelStart,edk::uint32 levelEnd){
    return this->readLevelsFromXMLFromPack(pack,fileName,levelStart,levelEnd,0u);
}
//read from XML without load physics objects in to the world
bool edk::Cenario2D::readFromXMLWithoutLoadPhysics(edk::XML* xml){
    return this->readFromXMLWithoutLoadPhysics(xml,0u);
}
bool edk::Cenario2D::readFromXMLWithoutLoadPhysics(const edk::char8* fileName){
    return this->readFromXMLWithoutLoadPhysics(fileName,0u);
}
bool edk::Cenario2D::readFromXMLWithoutLoadPhysics(edk::char8* fileName){
    return this->readFromXMLWithoutLoadPhysics(fileName,0u);
}
bool edk::Cenario2D::readFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::XML* xml){
    return this->readFromXMLFromPackWithoutLoadPhysics(pack,xml,0u);
}
bool edk::Cenario2D::readFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,const edk::char8* fileName){
    return this->readFromXMLFromPackWithoutLoadPhysics(pack,fileName,0u);
}
bool edk::Cenario2D::readFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::char8* fileName){
    return this->readFromXMLFromPackWithoutLoadPhysics(pack,fileName,0u);
}
//read level from XML without load physics objects in to the world
bool edk::Cenario2D::readLevelFromXMLWithoutLoadPhysics(edk::XML* xml,edk::uint32 level){
    return this->readLevelFromXMLWithoutLoadPhysics(xml,level,0u);
}
bool edk::Cenario2D::readLevelFromXMLWithoutLoadPhysics(const edk::char8* fileName,edk::uint32 level){
    return this->readLevelFromXMLWithoutLoadPhysics(fileName,level,0u);
}
bool edk::Cenario2D::readLevelFromXMLWithoutLoadPhysics(edk::char8* fileName,edk::uint32 level){
    return this->readLevelFromXMLWithoutLoadPhysics(fileName,level,0u);
}
bool edk::Cenario2D::readLevelFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 level){
    return this->readLevelFromXMLFromPackWithoutLoadPhysics(pack,xml,level,0u);
}
bool edk::Cenario2D::readLevelFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 level){
    return this->readLevelFromXMLFromPackWithoutLoadPhysics(pack,fileName,level,0u);
}
bool edk::Cenario2D::readLevelFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 level){
    return this->readLevelFromXMLFromPackWithoutLoadPhysics(pack,fileName,level,0u);
}
//read levels from XML without load physics objects in to the world
bool edk::Cenario2D::readLevelsFromXMLWithoutLoadPhysics(edk::XML* xml,edk::uint32 levelStart,edk::uint32 levelEnd){
    return this->readLevelsFromXMLWithoutLoadPhysics(xml,levelStart,levelEnd,0u);
}
bool edk::Cenario2D::readLevelsFromXMLWithoutLoadPhysics(const edk::char8* fileName,edk::uint32 levelStart,edk::uint32 levelEnd){
    return this->readLevelsFromXMLWithoutLoadPhysics(fileName,levelStart,levelEnd,0u);
}
bool edk::Cenario2D::readLevelsFromXMLWithoutLoadPhysics(edk::char8* fileName,edk::uint32 levelStart,edk::uint32 levelEnd){
    return this->readLevelsFromXMLWithoutLoadPhysics(fileName,levelStart,levelEnd,0u);
}
bool edk::Cenario2D::readLevelsFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 levelStart,edk::uint32 levelEnd){
    return this->readLevelsFromXMLFromPackWithoutLoadPhysics(pack,xml,levelStart,levelEnd,0u);
}
bool edk::Cenario2D::readLevelsFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 levelStart,edk::uint32 levelEnd){
    return this->readLevelsFromXMLFromPackWithoutLoadPhysics(pack,fileName,levelStart,levelEnd,0u);
}
bool edk::Cenario2D::readLevelsFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 levelStart,edk::uint32 levelEnd){
    return this->readLevelsFromXMLFromPackWithoutLoadPhysics(pack,fileName,levelStart,levelEnd,0u);
}

bool edk::Cenario2D::setMinimunObjectsInQuads(edk::uint32 minimunObjectsInQuads){
    if(minimunObjectsInQuads){
        this->minimunObjectsInQuads=minimunObjectsInQuads;
        return true;
    }
    this->minimunObjectsInQuads=1u;
    return false;
}
edk::uint32 edk::Cenario2D::getMinimunObjectsInQuads(){
    return this->minimunObjectsInQuads;
}

//set it cant continue loading the cenario
void edk::Cenario2D::cantContinueReading(){
    this->setCanContinueFalse();
}
