#include "Shader.h"

/*
Library Shader - Use Shaders in Edk
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
#warning "            Inside Shader.cpp"
#endif

edk::shd::Shader::Shader()
{
    //ctor
    this->id=0u;
    this->type=EDK_SHADER_NONE;edkEnd();
    this->log=NULL;edkEnd();
}
edk::shd::Shader::~Shader()
{
    //dtor
    this->deleteShader();edkEnd();
    //delete the log
    this->deleteLog();edkEnd();
}

//read the shaderType in a name
edk::shd::shaderType edk::shd::Shader::readType(edk::char8* name){
    //count the name
    edk::uint32 size = edk::String::strSize(name);edkEnd();
    //test the size
    if(size>5u){
        //test if its a vertex
        if(edk::String::strCompare(&name[size-5u],(edk::char8*)".vert")){
            //then return vertex
            return EDK_SHADER_VERTEX;edkEnd();
        }
        else if(edk::String::strCompare(&name[size-5u],(edk::char8*)".frag")){
            //then return fragment
            return EDK_SHADER_FRAGMENT;edkEnd();
        }
    }
    //else return none
    return EDK_SHADER_NONE;edkEnd();
}

bool edk::shd::Shader::checkCompilationStatus(edk::uint32 id){
    this->deleteLog();edkEnd();
    edk::int32 status = 0;

    //get the status
    edk::GU_GLSL::guGetShaderiv(id, GU_COMPILE_STATUS, &status);edkEnd();
    if(status == 0){
        //status is error
        edk::int32 infologLength = 0;
        edk::int32 charsWritten  = 0;
        //load the information lenght
        edk::GU_GLSL::guGetShaderiv(id, GU_INFO_LOG_LENGTH, &infologLength);edkEnd();
        //if the information lenght is true
        if(infologLength > 0){
            //alloca the string
            this->log = new edk::char8[infologLength];edkEnd();
            if(this->log == NULL){
                printf( "ERROR: Could not allocate InfoLog buffer");edkEnd();
                return false;
            }
            edk::GU_GLSL::guGetShaderInfoLog(id, infologLength, &charsWritten, this->log);edkEnd();
            if(infologLength > 1){
/*
                printf("\nLOG: %s"
                ,this->log
                );edkEnd();
*/
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


//load the shader
bool edk::shd::Shader::loadShaderFromMemory(edk::uint8* shader, edk::uint32 size, edk::shd::shaderType type){
    //test if the memory and the size are alloc
    if(shader && size){
        //then test the shaderType
        switch(type){
            case EDK_SHADER_VERTEX:
                //
                this->id=edk::GU_GLSL::guCreateShader(GU_GLSL_VERTEX_SHADER);edkEnd();
                break;
            case EDK_SHADER_FRAGMENT:
                //
                this->id=edk::GU_GLSL::guCreateShader(GU_GLSL_FRAGMENT_SHADER);edkEnd();
                break;
            case EDK_SHADER_GEOMETRY:
                ///TODO: ADD THE GEOMETRY SHADER IN THE FUTURE
                break;
        }
        if(this->id){
            //create the shaderID
            //now set the shader data
            if(edk::GU_GLSL::guShaderSource(this->id,shader,size)){
                //compile the shader
                edk::GU_GLSL::guCompileShader(this->id);edkEnd();
                //check if compile OK
                if(this->checkCompilationStatus(this->id)){

                    //return true
                    return true;
                }
            }
            //else delete the shader
            this->deleteShader();edkEnd();
        }
    }
    //else return false
    return false;
}
bool edk::shd::Shader::loadShaderFromFile(const edk::char8* name){
    //
    return this->loadShaderFromFile((edk::char8*) name);edkEnd();
}
bool edk::shd::Shader::loadShaderFromFile(edk::char8* name){
    //
    bool ret=false;edkEnd();
    //test if the file exist
    edk::File shader;edkEnd();
    edk::shd::shaderType type = edk::shd::Shader::readType(name);edkEnd();
    //set the shaderName
    if(this->setName(name)){
        //read the shaderType
        if(shader.openBinFile(name)){
            //get the fileSize
            edk::uint64 size = shader.getFileSize();edkEnd();
            if(size){
                //copy the shader
                edk::uint8* data = (edk::uint8*)shader.readBin(size);edkEnd();
                if(data){
                    //load shaderFromMemory
                    ret = this->loadShaderFromMemory(data,size,type);edkEnd();

                    //delete the data
                    delete data;edkEnd();
                }
            }
        }
    }
    //else return false
    return ret;
}

//return true if the shader is loaded
bool edk::shd::Shader::haveShader(){
    //
    return (bool)this->id;edkEnd();
}
//return the log
edk::char8* edk::shd::Shader::getCompileLog(){
    //
    return this->log;edkEnd();
}

//delete the shader
void edk::shd::Shader::deleteShader(){
    //test if have the shader
    if(this->haveShader()){
        //then delete the shader
        edk::GU_GLSL::guDeleteShader(this->id);edkEnd();
    }
    this->id=0u;
}
//delete the log
void edk::shd::Shader::deleteLog(){
    //test if have a log
    if(this->log){
        delete this->log;edkEnd();
    }
    this->log=NULL;edkEnd();
}
//clean the log
void edk::shd::Shader::dontDeleteLog(){
    this->log=NULL;edkEnd();
}

//get the shaderID
edk::uint32 edk::shd::Shader::getShaderID(){return this->id;edkEnd();}
//get shaderType
edk::shd::shaderType edk::shd::Shader::getShaderType(){return this->type;edkEnd();}
