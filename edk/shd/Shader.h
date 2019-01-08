#ifndef EDK_SHD_SHADER_H
#define EDK_SHD_SHADER_H

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
#warning "Inside Shader"
#endif

#pragma once
#include "../GU/GU_GLSL.h"
#include "../Object.h"
#include "../File.h"
#include "../String.h"

#ifdef printMessages
#warning "    Compiling Shader"
#endif

namespace edk{
namespace shd{

typedef edk::uint8 shaderType;

#define EDK_SHADER_NONE     0x000
#define EDK_SHADER_VERTEX   0x001
#define EDK_SHADER_FRAGMENT 0x002
#define EDK_SHADER_GEOMETRY 0x003

class Shader: public edk::ObjectWithName{
    public:
        Shader();
        virtual ~Shader();

        //read the shaderType in a name
        static edk::shd::shaderType readType(edk::char8* name);

        //function from the tutorial http://marcinbugala.blogspot.com.br/2013/01/hello-world-in-opengl-3.html
        bool checkCompilationStatus(edk::uint32 id);

        //load the shader
        bool loadShaderFromMemory(edk::uint8* shader, edk::uint32 size, edk::shd::shaderType type);
        bool loadShaderFromFile(const char* name);
        bool loadShaderFromFile(edk::char8* name);

        //return true if the shader is loaded
        bool haveShader();
        //return the log
        edk::char8* getCompileLog();

        //delete the shader
        void deleteShader();
        //delete the log
        void deleteLog();
        //clean the log
        void dontDeleteLog();

        //get the shaderID
        edk::uint32 getShaderID();
        //get shaderType
        edk::shd::shaderType getShaderType();
    protected:
    private:
    edk::uint32 id;
    //shaderType
    edk::shd::shaderType type;
    //compike log
    edk::char8* log;
};
}//end namespace shd
}//end namespace edk

#endif // SHADER_H
