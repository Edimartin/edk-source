#include "GLSL.h"

/*
Library GLSL - Load GLSL Shaders
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
#pragma message "            Inside GLSL.cpp"
#endif

//shaderTree
edk::ObjectNameTree shaderTree;


edk::shd::GLSL::shaderLink::shaderLink(){
    this->classThis=NULL;
    this->Constructor();
}
edk::shd::GLSL::shaderLink::shaderLink(edk::char8* name){
    this->classThis=NULL;
    this->Constructor(name);
}
edk::shd::GLSL::shaderLink::~shaderLink(){
    this->Destructor();
}

void edk::shd::GLSL::shaderLink::Constructor(){
    edk::Name::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        this->position = 0.f;
        this->id=0u;
        this->attach=false;
        this->log=NULL;
    }
}
void edk::shd::GLSL::shaderLink::Constructor(edk::char8* name){
    edk::Name::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        edk::Name::setName(name);
    }
}
void edk::shd::GLSL::shaderLink::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        //delete the shader
        this->deleteShader();
    }
    edk::Name::Destructor();
}

//release the shader
void edk::shd::GLSL::shaderLink::deleteShader(){
    this->deleteLog();
    //test if have one shaderID
    if(this->id){
        //test if have the shader on the tree
        edk::shd::Shader find;
        find.setName(this->getName());
        if(shaderTree.haveElement(&find)){
            //then release the shader
            shaderTree.releaseElement(&find,(edk::ObjectWithName**)&this->id);
        }
        this->cleanName();
        this->id=0u;
    }
}
bool edk::shd::GLSL::shaderLink::loadFileShader(edk::char8* name){
    //release the last shader
    this->deleteShader();
    //test the name
    if(name){
        //test if have the shader
        edk::shd::Shader find;
        find.setName(name);
        edk::shd::Shader* temp = (edk::shd::Shader*)shaderTree.getElement(&find);
        if(!temp){
            //load the shader
            temp=new edk::shd::Shader();
            if(temp){
                //load the shader
                if(temp->loadShaderFromFile(name)){
                    //then test the shader ID
                    if(temp->getShaderID()){
                        if(this->setName(temp->getName())){
                            //then add the shader to the tree
                            if(shaderTree.addElement((edk::ObjectWithName*)temp,(edk::ObjectWithName**)&this->id)){
                                //set the id
                                this->id=temp->getShaderID();
                                //return true
                                return true;
                            }
                            //else remove the name
                            this->cleanName();
                        }
                    }
                }
                //test if have the log
                if(temp->getCompileLog()){
                    //save the log
                    this->log = temp->getCompileLog();
                    temp->dontDeleteLog();
                }
                //then delete the shader
                delete temp;
            }
            temp=NULL;
        }
        else{
            //else get the shader name and id
            if(temp->getName() && temp->getShaderID()){
                //save the id and name
                this->id=temp->getShaderID();
                this->setName(temp->getName());
                //retain the shader
                temp->retainObject((edk::ObjectWithName**)&this->id);
                return true;
            }
        }
    }
    //else return false
    return false;
}
bool edk::shd::GLSL::shaderLink::loadMemoryShader(edk::char8* name,edk::uint8* data,edk::uint32 size,edk::shd::shaderType type){
    //release the last shader
    this->deleteShader();
    //test the name
    if(name){
        //test if have the shader
        edk::shd::Shader find;
        find.setName(this->getName());
        edk::shd::Shader* temp = (edk::shd::Shader*)shaderTree.getElement(&find);
        if(!temp){
            //load the shader
            temp=new edk::shd::Shader();
            if(temp){
                //load the shader
                if(temp->setName(name)){
                    if(temp->loadShaderFromMemory(data,size,type)){
                        //then test the shader ID
                        if(temp->getShaderID()){
                            if(this->setName(temp->getName())){
                                //then add the shader to the tree
                                if(shaderTree.addElement((edk::ObjectWithName*)temp,(edk::ObjectWithName**)&this->id)){
                                    //retain the shader
                                    temp->retainObject((edk::ObjectWithName**)&this->id);
                                    //set the id
                                    this->id=temp->getShaderID();
                                    //return true
                                    return true;
                                }
                                //else remove the name
                                this->cleanName();
                            }
                        }
                    }
                }
                //test if have the log
                if(temp->getCompileLog()){
                    //save the log
                    this->log = temp->getCompileLog();
                    temp->dontDeleteLog();
                }
                //else delete the shader
                delete temp;
            }
            temp=NULL;
        }
        else{
            //else get the shader name and id
            if(temp->getName() && temp->getShaderID()){
                //save the id and name
                this->id=temp->getShaderID();
                this->setName(temp->getName());
                //retain the shader
                temp->retainObject((edk::ObjectWithName**)&this->id);
                return true;
            }
        }
    }
    //else return false
    return false;
}
//get the log
edk::char8* edk::shd::GLSL::shaderLink::getCompilationLog(){
    edk::char8* ret = this->log;
    //clean the log
    this->log = NULL;
    return ret;
}
//delete the log
void edk::shd::GLSL::shaderLink::deleteLog(){
    if(this->log){
        free(this->log);
    }
    this->log = NULL;
}

edk::shd::GLSL::TreeShader::TreeShader(){
    //
    this->lastPosition = 0.f;
}
//compare if the value is bigger
bool edk::shd::GLSL::TreeShader::firstBiggerSecond(edk::shd::GLSL::shaderLink* first,edk::shd::GLSL::shaderLink* second){
    if(first&&second){
        if(first->position>second->position){
            return true;
        }
    }
    return false;
}
bool edk::shd::GLSL::TreeShader::firstEqualSecond(edk::shd::GLSL::shaderLink* first,edk::shd::GLSL::shaderLink* second){
    if(first&&second){
        if(first->position==second->position){
            return true;
        }
    }
    return false;
}
//add the shader
bool edk::shd::GLSL::TreeShader::addShader(edk::shd::GLSL::shaderLink* shader){
    if(shader){
        //test if dont have the shader in treeName
        if(!this->treeNames.haveElement((edk::Name*)shader)){
            //set the shader position
            shader->position = this->lastPosition;
            //add the shader to the tree
            if(this->add(shader)){
                if(this->treeNames.add((edk::Name*)shader)){
                    //increment last position
                    this->lastPosition += 0.1f;
                    return true;
                }
                this->remove(shader);
            }
        }
    }
    return false;
}
//remove the shader
bool edk::shd::GLSL::TreeShader::removeShader(edk::shd::GLSL::shaderLink* shader){
    if(shader){
        //test if have the shader
        if(this->treeNames.haveElement((edk::Name*)shader)){
            //remove the shader from the two trees
            this->remove(shader);
            this->treeNames.remove((edk::Name*)shader);
            return true;
        }
    }
    return false;
}
//get the shader by the name
edk::shd::GLSL::shaderLink* edk::shd::GLSL::TreeShader::getShaderByName(edk::char8* name){
    return (edk::shd::GLSL::shaderLink*)this->treeNames.getElementByName(name);
}
//cleanShaders
void edk::shd::GLSL::TreeShader::cleanShaders(){
    this->clean();
    this->treeNames.clean();
}

edk::shd::GLSL::GLSL(){
    this->classThis=NULL;
    this->Constructor();
}

edk::shd::GLSL::~GLSL(){
    this->Destructor();
}

void edk::shd::GLSL::Constructor(){
    edk::shd::DataList::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->tree.Constructor();

        this->id=0u;
        this->idTemp=0u;
        this->enable=true;
        this->log=NULL;
    }
}
void edk::shd::GLSL::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->deleteLog();
        //delete the program
        this->deleteProgram();
        //delete the shaders
        this->deleteShaders();
    }
    edk::shd::DataList::Destructor();
}

//start the lib
bool libStarted=false;
//save if load the shaders
bool fragmentLoaded=false,vertexLoaded=false,geometryLoaded=false;

//create a new data
bool edk::shd::GLSL::newData(edk::char8* name){
    //test if have one shaderProgram
    if(this->idTemp){
        //add the new data
        if(edk::shd::DataList::newData(name)){
            this->useThisShader();
            //load the data
            if(this->setDataID(name,edk::GU_GLSL::guGetDataLocation(this->idTemp, name))){
                //return true
                return true;
            }
            else{
                //else delete the data
                this->deleteData(name);
            }
        }
    }
    return false;
}
//start the shaderLib
bool edk::shd::GLSL::start(){
    if(!this->usingGLSL()){
        //then start the lib
        edk::int32 error = edk::GU_GLSL::guShaderInit();
        if(error != GU_GLSL_OK){
            //
            return false;
        }

        if(!edk::GU_GLSL::guStartShader(GU_GLSL_fragment_program)){
            //
            return false;
        }
        if(!edk::GU_GLSL::guStartShader(GU_GLSL_vertex_program)){
            //
            return false;
        }
        //set use shader
        libStarted=true;
        fragmentLoaded=true;
        vertexLoaded=true;
        if(edk::GU_GLSL::guStartShader(GU_GLSL_geometry_program)){
            //
            geometryLoaded=true;
        }
        //return true
        return true;
    }
    else{
        //else return true
        return true;
    }
    //only for
    return false;
}

//tests the programInfoLog
bool edk::shd::GLSL::checkCompilationStatus(edk::uint32 id){
    this->deleteLog();
    edk::int32 status = 0;

    //get the status
    edk::GU_GLSL::guGetProgramiv(id, GU_LINK_STATUS, &status);
    if(status == 0){
        //status is error
        edk::int32 infologLength = 0;
        edk::int32 charsWritten  = 0;
        //load the information lenght
        edk::GU_GLSL::guGetProgramiv(id, GU_INFO_LOG_LENGTH, &infologLength);
        //if the information lenght is true
        if(infologLength > 0){
            //alloca the string
            this->log = (edk::char8*)malloc(sizeof(edk::char8) * (infologLength));
            if(this->log == NULL){
                printf( "ERROR: Could not allocate InfoLog buffer");
                return false;
            }
            edk::GU_GLSL::guGetProgramInfoLog(id, infologLength, &charsWritten, this->log);
            if(infologLength>1){
                printf("\nLOG: %s"
                       ,this->log
                       );
            }
            else{
                //
                return true;
            }
        }
    }
    else{
        //
        return true;
    }
    //return false;
    return false;
}

//LOAD
//load a shader from a file
bool edk::shd::GLSL::loadShaderFromFile(const edk::char8* name){
    return this->loadShaderFromFile((edk::char8*) name);
}
bool edk::shd::GLSL::loadShaderFromFile(edk::char8* name){
    this->deleteLog();
    if(this->usingGLSL()){
        //test if dont have the shader in localTree
        edk::shd::GLSL::shaderLink* temp;
        if(!(temp = this->tree.getShaderByName(name))){
            //create a temp
            temp = new edk::shd::GLSL::shaderLink();
        }
        //else test test if have temp
        if(temp){
            //test if temp dont have one id
            if(!temp->id){
                //then load the shader
                if(temp->loadFileShader(name)){
                    //test if have the program
                    if(this->id){
                        //attach the shader
                        if(edk::GU_GLSL::guProgramUseShader(this->id,temp->id)){
                            temp->attach=true;
                        }
                        //add the shader on the tree
                        if(this->tree.addShader(temp)){
                            return true;
                        }
                        //else detach the shader and delete the temp
                        edk::GU_GLSL::guProgramRemoveShader(this->id,temp->id);
                    }
                    else{
                        //just add to the tree
                        if(this->tree.addShader(temp)){
                            return true;
                        }
                    }
                }
            }
            else{
                //return true
                return true;
            }
            //test if have the log
            this->log = temp->getCompilationLog();
            delete temp;
        }
    }
    //else return false
    return false;
}
bool edk::shd::GLSL::loadShaderFromMemory(const edk::char8* name,edk::uint8* data,edk::uint32 size,edk::shd::shaderType type){
    //
    return this->loadShaderFromMemory((edk::char8*) name,data,size,type);
}
bool edk::shd::GLSL::loadShaderFromMemory(edk::char8* name,edk::uint8* data,edk::uint32 size,edk::shd::shaderType type){
    this->deleteLog();
    if(this->usingGLSL()){
        //test the data, name and size
        if(name && data && size){
            //test if dont have the shader in localTree
            edk::shd::GLSL::shaderLink* temp;
            if(!(temp = this->tree.getShaderByName(name))){
                //create a temp
                temp = new edk::shd::GLSL::shaderLink();
            }
            //else test test if have temp
            if(temp){
                //test if temp dont have one id
                if(!temp->id){
                    //then load the shader
                    if(temp->loadMemoryShader(name,data,size,type)){
                        //test if have the program
                        if(this->id){
                            //attach the shader
                            if(edk::GU_GLSL::guProgramUseShader(this->id,temp->id)){
                                temp->attach=true;
                            }
                            //add the shader on the tree
                            if(this->tree.addShader(temp)){

                                return true;
                            }
                            //else detach the shader and delete the temp
                            edk::GU_GLSL::guProgramRemoveShader(this->id,temp->id);
                        }
                        else{
                            //just add to the tree
                            if(this->tree.addShader(temp)){
                                return true;
                            }
                        }
                    }
                }
                else{
                    //return true
                    return true;
                }
                //test if have the log
                this->log = temp->getCompilationLog();
                delete temp;
            }
        }
    }
    //else return false
    return false;
}
//create the shaderProgram
bool edk::shd::GLSL::createProgram(const edk::char8* name){
    return this->createProgram((edk::char8*) name);
}
bool edk::shd::GLSL::createProgram(edk::char8* name){
    //delete the lastProgram
    this->deleteProgram();
    //test if can use shader
    if(this->usingGLSL()){
        //set the shaderName
        if(this->setName(name)){
            //create the program
            this->id = edk::GU_GLSL::guCreateProgram();
            //test if create the program
            if(this->id){
                if(this->enable){
                    this->idTemp=id;
                }
                //test if aready have shaders
                edk::uint32 size = this->tree.size();
                if(size){
                    //the attach the shaders
                    edk::shd::GLSL::shaderLink* temp=NULL;
                    for(edk::uint32 i=0u;i<size;i++){
                        //test if have the shader
                        if((temp = (edk::shd::GLSL::shaderLink*)this->tree.getElementInPosition(i))){
                            //test if have the id
                            if(temp->id){
                                //attach
                                if(edk::GU_GLSL::guProgramUseShader(this->id,temp->id)){
                                    temp->attach=true;
                                }
                                //get the log
                                this->checkCompilationStatus(this->id);
                            }
                            else{
                                //remove the shader
                                this->tree.removeShader(temp);
                                delete temp;
                            }
                        }
                    }
                }
                //link the program
                edk::GU_GLSL::guLinkProgram(this->id);
                //then return true
                return true;
            }
        }
    }
    //else return false
    return false;
}

//delete the shaderProgram
void edk::shd::GLSL::deleteProgram(){
    //test if can use shader
    if(this->usingGLSL()){
        //test if have a shaderProgram
        if(this->id){
            //remove all the shaders from the program
            edk::uint32 size = this->tree.size();
            edk::shd::GLSL::shaderLink* temp=NULL;
            for(edk::uint32 i=0u;i<size;i++){
                if((temp = this->tree.getElementInPosition(i))){
                    //test if have the id
                    if(temp->id){
                        //dettach
                        edk::GU_GLSL::guProgramRemoveShader(this->id,temp->id);
                    }
                    temp->attach=false;
                }
            }
            //delete the program
            edk::GU_GLSL::guDeleteProgram(this->id);
        }
        //delete the name
        this->deleteName();
    }
    this->id=0u;
    this->idTemp=0u;
}
//delete the shaders
void edk::shd::GLSL::deleteShaders(){
    edk::uint32 size = this->tree.size();
    edk::shd::GLSL::shaderLink* temp=NULL;
    edk::uint32 position=0u;
    if(this->id){
        //delete all the shaders removing from the program
        for(edk::uint32 i=0u;i<size;i++){
            if((temp = this->tree.getElementInPosition(i))){
                //test if have the id
                if(temp->id){
                    //detach
                    edk::GU_GLSL::guProgramRemoveShader(this->id,temp->id);
                }
                if(!this->tree.removeShader(temp)){
                    position++;
                }
                //delete the shader
                delete temp;
            }
        }
    }
    else{
        //else just delete the shaders
        for(edk::uint32 i=0u;i<size;i++){
            if((temp = this->tree.getElementInPosition(position))){
                if(!this->tree.removeShader(temp)){
                    position++;
                }
                //delete the shader
                delete temp;
            }
        }
    }
    //the clean the tree
    this->tree.cleanShaders();
}
//delete the log
void edk::shd::GLSL::deleteLog(){
    //
    if(this->log){
        delete this->log;
    }
    this->log=NULL;
}
//return the log
edk::char8* edk::shd::GLSL::getCompilationLog(){
    return this->log;
}

//Use this shader
void edk::shd::GLSL::useThisShader(){
    //test if can use shader
    if(this->usingGLSL()){
        //use the shader
        edk::GU_GLSL::guUseProgram(this->idTemp);
    }
}
//remove the shader from the use
void edk::shd::GLSL::dontUseThisShader(){
    //test if can use shader
    if(this->usingGLSL()){
        //use the shader
        edk::GU_GLSL::guUseProgram(0u);
    }
}
//dont use the shader
void edk::shd::GLSL::useNoShader(){
    //
    if(libStarted){
        //
        edk::GU_GLSL::guUseProgram(0u);
    }
}

//enable or disable the shader
bool edk::shd::GLSL::enableProgram(){
    this->enable=true;
    this->idTemp=this->id;
    return this->haveProgram();
}
void edk::shd::GLSL::disableProgram(){
    this->enable=false;
    this->idTemp=0u;
}
bool edk::shd::GLSL::isProgramEnable(){
    return this->enable;
}

//GETERS
bool edk::shd::GLSL::usingGLSL(){return libStarted; }
bool edk::shd::GLSL::usingFragment(){return fragmentLoaded; }
bool edk::shd::GLSL::usingVertex(){return vertexLoaded; }
bool edk::shd::GLSL::usingGeometry(){return geometryLoaded; }
bool edk::shd::GLSL::haveProgram(){return (bool)this->id; }
