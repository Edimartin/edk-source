#ifndef EDK_SHD_SHADER_H
#define EDK_SHD_SHADER_H

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
#pragma message "Inside Shader"
#endif

#pragma once
#include "../GU/GU_GLSL.h"
#include "../Object.h"
#include "../File.h"
#include "../String.h"

#ifdef printMessages
#pragma message "    Compiling Shader"
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

    void Constructor();
    void Destructor();

    //read the shaderType in a name
    static edk::shd::shaderType readType(edk::char8* name);

    //function from the tutorial http://marcinbugala.blogspot.com.br/2013/01/hello-world-in-opengl-3.html
    bool checkCompilationStatus(edk::uint32 id);

    //load the shader
    bool loadShaderFromMemory(edk::uint8* shader, edk::uint32 size, edk::shd::shaderType type);
    bool loadShaderFromFile(const edk::char8* name);
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
    edk::int32 id;
    //shaderType
    edk::shd::shaderType type;
    //compike log
    edk::char8* log;
private:
    edk::classID classThis;
};
}//end namespace shd
}//end namespace edk

#endif // SHADER_H
