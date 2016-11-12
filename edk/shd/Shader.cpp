#include "Shader.h"

/*
Library Shader - Use Shaders in Edk
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
#warning "            Inside Shader.cpp"
#endif

edk::shd::Shader::Shader()
{
    //ctor
    this->id=0u;
    this->type=EDK_SHADER_NONE;
    this->log=NULL;
}
edk::shd::Shader::~Shader()
{
    //dtor
    this->deleteShader();
    //delete the log
    this->deleteLog();
}

//read the shaderType in a name
edk::shd::shaderType edk::shd::Shader::readType(edk::char8* name){
    //count the name
    edk::uint32 size = edk::String::strSize(name);
    //test the size
    if(size>5u){
        //test if its a vertex
        if(edk::String::strCompare(&name[size-5u],(edk::char8*)".vert")){
            //then return vertex
            return EDK_SHADER_VERTEX;
        }
        else if(edk::String::strCompare(&name[size-5u],(edk::char8*)".frag")){
            //then return fragment
            return EDK_SHADER_FRAGMENT;
        }
    }
    //else return none
    return EDK_SHADER_NONE;
}

bool edk::shd::Shader::checkCompilationStatus(edk::uint32 id) {
    this->deleteLog();
    edk::int32 status = 0;

    //get the status
    edk::GU_GLSL::guGetShaderiv(id, GU_COMPILE_STATUS, &status);
    if (status == 0) {
        //status is error
        edk::int32 infologLength = 0;
        edk::int32 charsWritten  = 0;
        //load the information lenght
        edk::GU_GLSL::guGetShaderiv(id, GU_INFO_LOG_LENGTH, &infologLength);
        //if the information lenght is true
        if (infologLength > 0)
        {
            //alloca the string
            this->log = new edk::char8[infologLength];
            if (this->log == NULL)
            {
                printf( "ERROR: Could not allocate InfoLog buffer");
                return false;
            }
            edk::GU_GLSL::guGetShaderInfoLog(id, infologLength, &charsWritten, this->log);
            if(infologLength > 1){
/*
                printf("\nLOG: %s"
                ,this->log
                );fflush(stdout);
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
                this->id=edk::GU_GLSL::guCreateShader(GU_GLSL_VERTEX_SHADER);
                break;
            case EDK_SHADER_FRAGMENT:
                //
                this->id=edk::GU_GLSL::guCreateShader(GU_GLSL_FRAGMENT_SHADER);
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
                edk::GU_GLSL::guCompileShader(this->id);
                //check if compile OK
                if(this->checkCompilationStatus(this->id)){

                    //return true
                    return true;
                }
            }
            //else delete the shader
            this->deleteShader();
        }
    }
    //else return false
    return false;
}
bool edk::shd::Shader::loadShaderFromFile(const char* name){
    //
    return this->loadShaderFromFile((edk::char8*) name);
}
bool edk::shd::Shader::loadShaderFromFile(edk::char8* name){
    //
    bool ret=false;
    //test if the file exist
    edk::File shader;
    edk::shd::shaderType type = edk::shd::Shader::readType(name);
    //set the shaderName
    if(this->setName(name)){
        //read the shaderType
        if(shader.openBinFile(name)){
            //get the fileSize
            edk::uint64 size = shader.getFileSize();
            if(size){
                //copy the shader
                edk::uint8* data = (edk::uint8*)shader.readBin(size);
                if(data){
                    //load shaderFromMemory
                    ret = this->loadShaderFromMemory(data,size,type);

                    //delete the data
                    delete data;
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
    return (bool)this->id;
}
//return the log
edk::char8* edk::shd::Shader::getCompileLog(){
    //
    return this->log;
}

//delete the shader
void edk::shd::Shader::deleteShader(){
    //test if have the shader
    if(this->haveShader()){
        //then delete the shader
        edk::GU_GLSL::guDeleteShader(this->id);
    }
    this->id=0u;
}
//delete the log
void edk::shd::Shader::deleteLog(){
    //test if have a log
    if(this->log)
        delete this->log;
    this->log=NULL;
}
//clean the log
void edk::shd::Shader::dontDeleteLog(){
    this->log=NULL;
}

//get the shaderID
edk::uint32 edk::shd::Shader::getShaderID(){return this->id;}
//get shaderType
edk::shd::shaderType edk::shd::Shader::getShaderType(){return this->type;}
