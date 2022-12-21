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
#warning "            Inside GLSL.cpp"
#endif

//shaderTree
edk::ObjectNameTree shaderTree;


edk::shd::GLSL::shaderLink::shaderLink(){
    //
    this->position = 0.f;edkEnd();
    this->id=0u;
    this->attach=false;edkEnd();
    this->log=NULL;edkEnd();
}
edk::shd::GLSL::shaderLink::shaderLink(edk::char8* name){
    //set the name
    edk::Name::setName(name);edkEnd();
}
edk::shd::GLSL::shaderLink::~shaderLink(){
    //delete the shader
    this->deleteShader();edkEnd();
}
//release the shader
void edk::shd::GLSL::shaderLink::deleteShader(){
    this->deleteLog();edkEnd();
    //test if have one shaderID
    if(this->id){
        //test if have the shader on the tree
        edk::shd::Shader find;edkEnd();
        find.setName(this->getName());edkEnd();
        if(shaderTree.haveElement(&find)){
            //then release the shader
            shaderTree.releaseElement(&find,(edk::ObjectWithName**)&this->id);edkEnd();
        }
        this->cleanName();edkEnd();
        this->id=0u;
    }
}
bool edk::shd::GLSL::shaderLink::loadFileShader(edk::char8* name){
    //release the last shader
    this->deleteShader();edkEnd();
    //test the name
    if(name){
        //test if have the shader
        edk::shd::Shader find;edkEnd();
        find.setName(name);edkEnd();
        edk::shd::Shader* temp = (edk::shd::Shader*)shaderTree.getElement(&find);edkEnd();
        if(!temp){
            //load the shader
            temp=new edk::shd::Shader();edkEnd();
            if(temp){
                //load the shader
                if(temp->loadShaderFromFile(name)){
                    //then test the shader ID
                    if(temp->getShaderID()){
                        if(this->setName(temp->getName())){
                            //then add the shader to the tree
                            if(shaderTree.addElement((edk::ObjectWithName*)temp,(edk::ObjectWithName**)&this->id)){
                                //set the id
                                this->id=temp->getShaderID();edkEnd();
                                //return true
                                return true;
                            }
                            //else remove the name
                            this->cleanName();edkEnd();
                        }
                    }
                }
                //test if have the log
                if(temp->getCompileLog()){
                    //save the log
                    this->log = temp->getCompileLog();edkEnd();
                    temp->dontDeleteLog();edkEnd();
                }
                //then delete the shader
                delete temp;edkEnd();
            }
            temp=NULL;edkEnd();
        }
        else{
            //else get the shader name and id
            if(temp->getName() && temp->getShaderID()){
                //save the id and name
                this->id=temp->getShaderID();edkEnd();
                this->setName(temp->getName());edkEnd();
                //retain the shader
                temp->retainObject((edk::ObjectWithName**)&this->id);edkEnd();
                return true;
            }
        }
    }
    //else return false
    return false;
}
bool edk::shd::GLSL::shaderLink::loadMemoryShader(edk::char8* name,edk::uint8* data,edk::uint32 size,edk::shd::shaderType type){
    //release the last shader
    this->deleteShader();edkEnd();
    //test the name
    if(name){
        //test if have the shader
        edk::shd::Shader find;edkEnd();
        find.setName(this->getName());edkEnd();
        edk::shd::Shader* temp = (edk::shd::Shader*)shaderTree.getElement(&find);edkEnd();
        if(!temp){
            //load the shader
            temp=new edk::shd::Shader();edkEnd();
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
                                    temp->retainObject((edk::ObjectWithName**)&this->id);edkEnd();
                                    //set the id
                                    this->id=temp->getShaderID();edkEnd();
                                    //return true
                                    return true;
                                }
                                //else remove the name
                                this->cleanName();edkEnd();
                            }
                        }
                    }
                }
                //test if have the log
                if(temp->getCompileLog()){
                    //save the log
                    this->log = temp->getCompileLog();edkEnd();
                    temp->dontDeleteLog();edkEnd();
                }
                //else delete the shader
                delete temp;edkEnd();
            }
            temp=NULL;edkEnd();
        }
        else{
            //else get the shader name and id
            if(temp->getName() && temp->getShaderID()){
                //save the id and name
                this->id=temp->getShaderID();edkEnd();
                this->setName(temp->getName());edkEnd();
                //retain the shader
                temp->retainObject((edk::ObjectWithName**)&this->id);edkEnd();
                return true;
            }
        }
    }
    //else return false
    return false;
}
//get the log
edk::char8* edk::shd::GLSL::shaderLink::getCompilationLog(){
    edk::char8* ret = this->log;edkEnd();
    //clean the log
    this->log = NULL;edkEnd();
    return ret;
}
//delete the log
void edk::shd::GLSL::shaderLink::deleteLog(){
    if(this->log){
        delete[] this->log;edkEnd();
    }
    this->log = NULL;edkEnd();
}

edk::shd::GLSL::TreeShader::TreeShader(){
    //
    this->lastPosition = 0.f;edkEnd();
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
            shader->position = this->lastPosition;edkEnd();
            //add the shader to the tree
            if(this->add(shader)){
                if(this->treeNames.add((edk::Name*)shader)){
                    //increment last position
                    this->lastPosition += 0.1f;edkEnd();
                    return true;
                }
                this->remove(shader);edkEnd();
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
            this->remove(shader);edkEnd();
            this->treeNames.remove((edk::Name*)shader);edkEnd();
            return true;
        }
    }
    return false;
}
//get the shader by the name
edk::shd::GLSL::shaderLink* edk::shd::GLSL::TreeShader::getShaderByName(edk::char8* name){
    return (edk::shd::GLSL::shaderLink*)this->treeNames.getElementByName(name);edkEnd();
}
//cleanShaders
void edk::shd::GLSL::TreeShader::cleanShaders(){
    this->clean();edkEnd();
    this->treeNames.clean();edkEnd();
}

edk::shd::GLSL::GLSL()
{
    //ctor
    this->id=0u;
    this->log=NULL;edkEnd();
}

edk::shd::GLSL::~GLSL()
{
    this->deleteLog();edkEnd();
    //delete the program
    this->deleteProgram();edkEnd();
    //delete the shaders
    this->deleteShaders();edkEnd();
}

//start the lib
bool libStarted=false;
//save if load the shaders
bool fragmentLoaded=false,vertexLoaded=false,geometryLoaded=false;

//create a new data
bool edk::shd::GLSL::newData(edk::char8* name){
    //test if have one shaderProgram
    if(this->id){
        //add the new data
        if(edk::shd::DataList::newData(name)){
            this->useThisShader();edkEnd();
            //load the data
            if(this->setDataID(name,edk::GU_GLSL::guGetDataLocation(this->id, name))){
                //return true
                return true;
            }
            else{
                //else delete the data
                this->deleteData(name);edkEnd();
            }
        }
    }
    return false;
}
//start the shaderLib
bool edk::shd::GLSL::start(){
    if(!this->usingGLSL()){
        //then start the lib
        edk::int32 error = edk::GU_GLSL::guShaderInit();edkEnd();
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
        libStarted=true;edkEnd();
        fragmentLoaded=true;edkEnd();
        vertexLoaded=true;edkEnd();
        if(edk::GU_GLSL::guStartShader(GU_GLSL_geometry_program)){
            //
            geometryLoaded=true;edkEnd();
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
    this->deleteLog();edkEnd();
    edk::int32 status = 0;

    //get the status
    edk::GU_GLSL::guGetProgramiv(id, GU_LINK_STATUS, &status);edkEnd();
    if (status == 0) {
        //status is error
        edk::int32 infologLength = 0;
        edk::int32 charsWritten  = 0;
        //load the information lenght
        edk::GU_GLSL::guGetProgramiv(id, GU_INFO_LOG_LENGTH, &infologLength);edkEnd();
        //if the information lenght is true
        if (infologLength > 0)
        {
            //alloca the string
            this->log = new edk::char8[infologLength];edkEnd();
            if (this->log == NULL)
            {
                printf( "ERROR: Could not allocate InfoLog buffer");edkEnd();
                return false;
            }
            edk::GU_GLSL::guGetProgramInfoLog(id, infologLength, &charsWritten, this->log);edkEnd();
            if(infologLength>1){
                printf("\nLOG: %s"
                       ,this->log
                       );edkEnd();
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
    return this->loadShaderFromFile((edk::char8*) name);edkEnd();
}
bool edk::shd::GLSL::loadShaderFromFile(edk::char8* name){
    this->deleteLog();edkEnd();
    if(this->usingGLSL()){
        //test if dont have the shader in localTree
        edk::shd::GLSL::shaderLink* temp;edkEnd();
        if(!(temp = this->tree.getShaderByName(name))){
            //create a temp
            temp = new edk::shd::GLSL::shaderLink();edkEnd();
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
                            temp->attach=true;edkEnd();
                        }
                        //add the shader on the tree
                        if(this->tree.addShader(temp)){
                            return true;
                        }
                        //else detach the shader and delete the temp
                        edk::GU_GLSL::guProgramRemoveShader(this->id,temp->id);edkEnd();
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
            this->log = temp->getCompilationLog();edkEnd();
            delete temp;edkEnd();
        }
    }
    //else return false
    return false;
}
bool edk::shd::GLSL::loadShaderFromMemory(const edk::char8* name,edk::uint8* data,edk::uint32 size,edk::shd::shaderType type){
    //
    return this->loadShaderFromMemory((edk::char8*) name,data,size,type);edkEnd();
}
bool edk::shd::GLSL::loadShaderFromMemory(edk::char8* name,edk::uint8* data,edk::uint32 size,edk::shd::shaderType type){
    this->deleteLog();edkEnd();
    if(this->usingGLSL()){
        //test the data, name and size
        if(name && data && size){
            //test if dont have the shader in localTree
            edk::shd::GLSL::shaderLink* temp;edkEnd();
            if(!(temp = this->tree.getShaderByName(name))){
                //create a temp
                temp = new edk::shd::GLSL::shaderLink();edkEnd();
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
                                temp->attach=true;edkEnd();
                            }
                            //add the shader on the tree
                            if(this->tree.addShader(temp)){

                                return true;
                            }
                            //else detach the shader and delete the temp
                            edk::GU_GLSL::guProgramRemoveShader(this->id,temp->id);edkEnd();
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
                this->log = temp->getCompilationLog();edkEnd();
                delete temp;edkEnd();
            }
        }
    }
    //else return false
    return false;
}
//create the shaderProgram
bool edk::shd::GLSL::createProgram(const edk::char8* name){
    return this->createProgram((edk::char8*) name);edkEnd();
}
bool edk::shd::GLSL::createProgram(edk::char8* name){
    //delete the lastProgram
    this->deleteProgram();edkEnd();
    //test if can use shader
    if(this->usingGLSL()){
        //set the shaderName
        if(this->setName(name)){
            //create the program
            this->id = edk::GU_GLSL::guCreateProgram();edkEnd();
            //test if create the program
            if(this->id){
                //test if aready have shaders
                edk::uint32 size = this->tree.size();edkEnd();
                if(size){
                    //the attach the shaders
                    edk::shd::GLSL::shaderLink* temp=NULL;edkEnd();
                    for(edk::uint32 i=0u;i<size;i++){
                        //test if have the shader
                        if((temp = (edk::shd::GLSL::shaderLink*)this->tree.getElementInPosition(i))){
                            //test if have the id
                            if(temp->id){
                                //attach
                                if(edk::GU_GLSL::guProgramUseShader(this->id,temp->id)){
                                    temp->attach=true;edkEnd();
                                }
                                //get the log
                                this->checkCompilationStatus(this->id);edkEnd();
                            }
                            else{
                                //remove the shader
                                this->tree.removeShader(temp);edkEnd();
                                delete temp;edkEnd();
                            }
                        }
                    }
                }
                //link the program
                edk::GU_GLSL::guLinkProgram(this->id);edkEnd();
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
            edk::uint32 size = this->tree.size();edkEnd();
            edk::shd::GLSL::shaderLink* temp=NULL;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                if((temp = this->tree.getElementInPosition(i))){
                    //test if have the id
                    if(temp->id){
                        //dettach
                        edk::GU_GLSL::guProgramRemoveShader(this->id,temp->id);edkEnd();
                    }
                    temp->attach=false;edkEnd();
                }
            }
            //delete the program
            edk::GU_GLSL::guDeleteProgram(this->id);edkEnd();
        }
        //delete the name
        this->deleteName();edkEnd();
    }
    this->id=0u;
}
//delete the shaders
void edk::shd::GLSL::deleteShaders(){
    edk::uint32 size = this->tree.size();edkEnd();
    edk::shd::GLSL::shaderLink* temp=NULL;edkEnd();
    edk::uint32 position=0u;
    if(this->id){
        //delete all the shaders removing from the program
        for(edk::uint32 i=0u;i<size;i++){
            if((temp = this->tree.getElementInPosition(i))){
                //test if have the id
                if(temp->id){
                    //detach
                    edk::GU_GLSL::guProgramRemoveShader(this->id,temp->id);edkEnd();
                }
                if(!this->tree.removeShader(temp)){
                    position++;edkEnd();
                }
                //delete the shader
                delete temp;edkEnd();
            }
        }
    }
    else{
        //else just delete the shaders
        for(edk::uint32 i=0u;i<size;i++){
            if((temp = this->tree.getElementInPosition(position))){
                if(!this->tree.removeShader(temp)){
                    position++;edkEnd();
                }
                //delete the shader
                delete temp;edkEnd();
            }
        }
    }
    //the clean the tree
    this->tree.cleanShaders();edkEnd();
}
//delete the log
void edk::shd::GLSL::deleteLog(){
    //
    if(this->log){
        delete this->log;edkEnd();
    }
    this->log=NULL;edkEnd();
}
//return the log
edk::char8* edk::shd::GLSL::getCompilationLog(){
    return this->log;edkEnd();
}

//Use this shader
void edk::shd::GLSL::useThisShader(){
    //test if can use shader
    if(this->usingGLSL()){
        //use the shader
        edk::GU_GLSL::guUseProgram(this->id);edkEnd();
    }
}
//remove the shader from the use
void edk::shd::GLSL::dontUseThisShader(){
    //test if can use shader
    if(this->usingGLSL()){
        //use the shader
        edk::GU_GLSL::guUseProgram(0u);edkEnd();
    }
}
//dont use the shader
void edk::shd::GLSL::useNoShader(){
    //
    if(libStarted){
        //
        edk::GU_GLSL::guUseProgram(0u);edkEnd();
    }
}

//GETERS
bool edk::shd::GLSL::usingGLSL(){return libStarted;edkEnd();}
bool edk::shd::GLSL::usingFragment(){return fragmentLoaded;edkEnd();}
bool edk::shd::GLSL::usingVertex(){return vertexLoaded;edkEnd();}
bool edk::shd::GLSL::usingGeometry(){return geometryLoaded;edkEnd();}
bool edk::shd::GLSL::haveProgram(){return (bool)this->id;edkEnd();}
