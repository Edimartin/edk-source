#ifndef EDK_SHD_GLSL_H
#define EDK_SHD_GLSL_H

/*
Library GLSL - Load GLSL Shaders
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
#warning "Inside GLSL"
#endif

//include dataList
#include "DataList.h"
#include "Shader.h"
#include "../String.h"
#include "../vector/Stack.h"

#ifdef printMessages
#warning "    Compiling GLSL"
#endif

namespace edk{
namespace shd{
//use the dataList in the shader
class GLSL:public edk::shd::DataList{
    public:
        GLSL();
        virtual ~GLSL();

        //create a new data
        bool newData(edk::char8* name);

        //start the shaderLib
        bool start();

        //tests the programInfoLog
        bool checkCompilationStatus(edk::uint32 id);

        //LOAD
        //load a shader from a file
        bool loadShaderFromFile(const char* name);
        bool loadShaderFromFile(edk::char8* name);
        //load the shader from memory
        bool loadShaderFromMemory(const char* name,edk::uint8* data,edk::uint32 size,edk::shd::shaderType type);
        bool loadShaderFromMemory(edk::char8* name,edk::uint8* data,edk::uint32 size,edk::shd::shaderType type);

        //create the shaderProgram
        bool createProgram(const char* name);
        bool createProgram(edk::char8* name);

        //delete the shaderProgram
        void deleteProgram();
        //delete the shaders
        void deleteShaders();
        //delete the log
        void deleteLog();
        //return the log
        edk::char8* getCompilationLog();

        //Use this shader
        void useThisShader();
        //remove the shader from the use
        void dontUseThisShader();
        //dont use the shader
        static void useNoShader();

        //GETERS
        bool usingGLSL();
        bool usingFragment();
        bool usingVertex();
        bool usingGeometry();
        bool haveProgram();
    protected:
    private:
    //shaderClass
    class shaderLink: public edk::vector::Name{
        public:
        shaderLink();
        shaderLink(edk::char8* name);
        ~shaderLink();
        //release the shader
        void deleteShader();
        bool loadFileShader(edk::char8* name);
        bool loadMemoryShader(edk::char8* name,edk::uint8* data,edk::uint32 size,edk::shd::shaderType type);
        //get the log
        edk::char8* getCompilationLog();
        //delete the log
        void deleteLog();
        edk::uint32 id;
        //position of the shader
        edk::float32 position;
        //save if attach the shader to the program
        bool attach;
        //save the log
        edk::char8* log;
    };
    //program ID
    edk::uint32 id;
    //compike log
    edk::char8* log;

    class TreeShader:public edk::vector::BinaryTree<edk::shd::GLSL::shaderLink*>{
    public:
        TreeShader();
        //compare if the value is bigger
        bool firstBiggerSecond(edk::shd::GLSL::shaderLink* first,edk::shd::GLSL::shaderLink* second);
        bool firstEqualSecond(edk::shd::GLSL::shaderLink* first,edk::shd::GLSL::shaderLink* second);
        //add the shader
        bool addShader(edk::shd::GLSL::shaderLink* shader);
        //remove the shader
        bool removeShader(edk::shd::GLSL::shaderLink* shader);
        //get the shader by the name
        edk::shd::GLSL::shaderLink* getShaderByName(edk::char8* name);
        //cleanShaders
        void cleanShaders();
    private:
        edk::vector::NameTree treeNames;
        edk::float32 lastPosition;
    }tree;
};
}//end namespace shd
}//end namespace edk

#endif // GLSL_H
