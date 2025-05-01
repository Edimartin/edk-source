#ifndef EDK_SHD_GLSL_H
#define EDK_SHD_GLSL_H

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
#pragma message "Inside GLSL"
#endif

#pragma once
//include dataList
#include "DataList.h"
#include "Shader.h"
#include "../String.h"
#include "../vector/Stack.h"

#ifdef printMessages
#pragma message "    Compiling GLSL"
#endif

namespace edk{
namespace shd{
//use the dataList in the shader
class GLSL:public edk::shd::DataList{
public:
    GLSL();
    virtual ~GLSL();

    void Constructor();
    void Destructor();

    //create a new data
    bool newData(edk::char8* name);

    //start the shaderLib
    bool start();

    //tests the programInfoLog
    bool checkCompilationStatus(edk::uint32 id);

    //LOAD
    //load a shader from a file
    bool loadShaderFromFile(const edk::char8* name);
    bool loadShaderFromFile(edk::char8* name);
    //load the shader from memory
    bool loadShaderFromMemory(const edk::char8* name,edk::uint8* data,edk::uint32 size,edk::shd::shaderType type);
    bool loadShaderFromMemory(edk::char8* name,edk::uint8* data,edk::uint32 size,edk::shd::shaderType type);

    //create the shaderProgram
    bool createProgram(const edk::char8* name);
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

    //enable or disable the shader
    bool enableProgram();
    void disableProgram();
    bool isProgramEnable();

    //GETERS
    bool usingGLSL();
    bool usingFragment();
    bool usingVertex();
    bool usingGeometry();
    bool haveProgram();
protected:
private:
    //shaderClass
    class shaderLink: public edk::Name{
    public:
        shaderLink();
        shaderLink(edk::char8* name);
        virtual ~shaderLink();

        void Constructor();
        void Constructor(edk::char8* name);
        void Destructor();

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
    private:
        edk::classID classThis;
    };
    //program ID
    edk::uint32 id;
    edk::uint32 idTemp;
    //save if the shader are enabled
    bool enable;

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
private:
    edk::classID classThis;
};
}//end namespace shd
}//end namespace edk

#endif // GLSL_H
