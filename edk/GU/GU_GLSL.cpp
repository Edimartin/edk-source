#include "GU_GLSL.h"

/*
Library GU_GLSL - Add shaders to the GU
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
#warning "            Inside GU_GLSL.cpp"
#endif

bool edk::GU_GLSL::initiate=false;

//construtor
edk::GU_GLSL::GU_GLSL(){
    //
}
//destrutor
edk::GU_GLSL::~GU_GLSL(){
    //
}

//start the shaderLib
edk::int32 edk::GU_GLSL::guShaderInit(){
    edk::int32 ret = GU_GLSL_OK;
    if(!edk::GU_GLSL::initiate){
        if((ret = glewInit()) == GU_GLSL_OK){
            edk::GU_GLSL::initiate=true;
        }
    }
    return ret;
}
//return true if have init the glut
bool edk::GU_GLSL::guShaderInitiate(){
    return edk::GU_GLSL::initiate;
}

bool edk::GU_GLSL::guStartShader(edk::int32 shade){
    switch(shade){
        case GU_GLSL_fragment_program:
            //
            return glewGetExtension("GL_ARB_fragment_program");
            break;
        case GU_GLSL_vertex_program:
            //
            return glewGetExtension("GL_ARB_vertex_program");
            break;
        case GU_GLSL_geometry_program:
            //
            return glewGetExtension("GL_ARB_geometry_program");
            break;
    }
    //else return false
    return false;
}
edk::uint32 edk::GU_GLSL::guCreateShader(edk::uint32 type){return glCreateShader(type);}
void edk::GU_GLSL::guDeleteShader(edk::uint32 id){glDeleteShader(id);}
bool edk::GU_GLSL::guShaderSource(edk::uint32 id, edk::uint8 *data,  edk::uint32 length){
    //
    if(id && data && length){
        //set the shaderSource
        glShaderSource(id,  1u,  (const char**)(&data),  (const GLint*)&length);
        //return true
        return true;
    }
    //else return false
    return false;
}
void edk::GU_GLSL::guCompileShader(edk::uint32 id){glCompileShader(id);}
void edk::GU_GLSL::guGetShaderiv(edk::uint32 shader,  edk::uint32 pname,  edk::int32 *params){glGetShaderiv(shader,  pname,  params);}
void edk::GU_GLSL::guGetProgramiv(edk::uint32 program, edk::uint32 pname,  edk::int32 *params){glGetProgramiv(program,  pname,  params);}
void edk::GU_GLSL::guGetShaderInfoLog(edk::uint32 shader,  edk::int32 maxLength,  edk::int32 *length,  edk::char8 *infoLog){
    glGetShaderInfoLog(shader,  maxLength,  length,  (GLchar*)infoLog);
}
void edk::GU_GLSL::guGetProgramInfoLog(edk::uint32 program,  edk::int32 maxLength,  edk::int32 *length,  edk::char8 *infoLog){
    glGetProgramInfoLog(program,  maxLength,  length,  (GLchar*)infoLog);
}
//shader program
edk::uint32 edk::GU_GLSL::guCreateProgram(){return glCreateProgram();}
bool edk::GU_GLSL::guProgramUseShader(edk::uint32 id,edk::uint32 shaderId){glAttachShader(id,shaderId); return true;}
void edk::GU_GLSL::guProgramRemoveShader(edk::uint32 id,edk::uint32 shaderId){glDetachShader(id,shaderId);}
void edk::GU_GLSL::guDeleteProgram(edk::uint32 id){glDeleteProgram(id);}
void edk::GU_GLSL::guLinkProgram(edk::uint32 shaderID){glLinkProgram(shaderID);}
void edk::GU_GLSL::guUseProgram(edk::uint32 shaderID){glUseProgram(shaderID);}

void edk::GU_GLSL::guData1i32(edk::int32 id,edk::int32 d0){glUniform1i(id,d0);}
void edk::GU_GLSL::guData2i32(edk::int32 id,edk::vec2i32 d){glUniform2i(id,d.x,d.y);}
void edk::GU_GLSL::guData2i32(edk::int32 id,edk::int32 d0,edk::int32 d1){glUniform2i(id,d0,d1);}
void edk::GU_GLSL::guData3i32(edk::int32 id,edk::vec3i32 d){glUniform3i(id,d.x,d.y,d.z);}
void edk::GU_GLSL::guData3i32(edk::int32 id,edk::int32 d0,edk::int32 d1,edk::int32 d2){glUniform3i(id,d0,d1,d2);}
void edk::GU_GLSL::guData4i32(edk::int32 id,edk::vec4i32 d){glUniform4i(id,d.x,d.y,d.z,d.w);}
void edk::GU_GLSL::guData4i32(edk::int32 id,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3){glUniform4i(id,d0,d1,d2,d3);}

void edk::GU_GLSL::guData1f32(edk::int32 id,edk::float32 d0){glUniform1f(id,d0);}
void edk::GU_GLSL::guData2f32(edk::int32 id,edk::vec2f32 d){glUniform2f(id,d.x,d.y);}
void edk::GU_GLSL::guData2f32(edk::int32 id,edk::float32 d0,edk::float32 d1){glUniform2f(id,d0,d1);}
void edk::GU_GLSL::guData3f32(edk::int32 id,edk::vec3f32 d){glUniform3f(id,d.x,d.y,d.z);}
void edk::GU_GLSL::guData3f32(edk::int32 id,edk::float32 d0,edk::float32 d1,edk::float32 d2){glUniform3f(id,d0,d1,d2);}
void edk::GU_GLSL::guData4f32(edk::int32 id,edk::vec4f32 d){glUniform4f(id,d.x,d.y,d.z,d.w);}
void edk::GU_GLSL::guData4f32(edk::int32 id,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3){glUniform4f(id,d0,d1,d2,d3);}
/*
void edk::GU_GLSL::guVertexData1i32(edk::int32 id,edk::int32 d0){glVertexAttrib1i(id,d0);}
void edk::GU_GLSL::guVertexData2i32(edk::int32 id,edk::vec2i32 d){glVertexAttrib2i(id,d.x,d.y);}
void edk::GU_GLSL::guVertexData2i32(edk::int32 id,edk::int32 d0,edk::int32 d1){glVertexAttrib2i(id,d0,d1);}
void edk::GU_GLSL::guVertexData3i32(edk::int32 id,edk::vec3i32 d){glVertexAttrib3i(id,d.x,d.y,d.z);}
void edk::GU_GLSL::guVertexData3i32(edk::int32 id,edk::int32 d0,edk::int32 d1,edk::int32 d2){glVertexAttrib3i(id,d0,d1,d2);}
void edk::GU_GLSL::guVertexData4i32(edk::int32 id,edk::vec4i32 d){glVertexAttrib4i(id,d.x,d.y,d.z,d.w);}
void edk::GU_GLSL::guVertexData4i32(edk::int32 id,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3){glVertexAttrib4i(id,d0,d1,d2,d3);}
*/
void edk::GU_GLSL::guVertexData1f32(edk::int32 id,edk::float32 d0){glVertexAttrib1f(id,d0);}
void edk::GU_GLSL::guVertexData2f32(edk::int32 id,edk::vec2f32 d){glVertexAttrib2f(id,d.x,d.y);}
void edk::GU_GLSL::guVertexData2f32(edk::int32 id,edk::float32 d0,edk::float32 d1){glVertexAttrib2f(id,d0,d1);}
void edk::GU_GLSL::guVertexData3f32(edk::int32 id,edk::vec3f32 d){glVertexAttrib3f(id,d.x,d.y,d.z);}
void edk::GU_GLSL::guVertexData3f32(edk::int32 id,edk::float32 d0,edk::float32 d1,edk::float32 d2){glVertexAttrib3f(id,d0,d1,d2);}
void edk::GU_GLSL::guVertexData4f32(edk::int32 id,edk::vec4f32 d){glVertexAttrib4f(id,d.x,d.y,d.z,d.w);}
void edk::GU_GLSL::guVertexData4f32(edk::int32 id,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3){glVertexAttrib4f(id,d0,d1,d2,d3);}

//return the data location
edk::int32 edk::GU_GLSL::guGetDataLocation(edk::uint32 program, const char *name){return glGetUniformLocation(program,name);}
edk::int32 edk::GU_GLSL::guGetDataLocation(edk::uint32 program, edk::char8* name){return glGetUniformLocation(program,(const char*)name);}
//return the vertexData location
edk::int32 edk::GU_GLSL::guGetVertexDataLocation(edk::uint32 program, const char *name){return glGetAttribLocation(program,name);}
edk::int32 edk::GU_GLSL::guGetVertexDataLocation(edk::uint32 program, edk::char8* name){return glGetAttribLocation(program,(const char*)name);}

//Errors
edk::char8* edk::GU_GLSL::guGetErrorString(edk::int32 error){return (edk::char8*)glewGetErrorString(error);}
//glewGetString(GLEW_VERSION)
//edk::char8* edk::GU_GLSL::glewGetString(edk::int32 version){return (edk::char8*)glewGetString(version);}

//If it crash. Dont forget to init the shader
void edk::GU_GLSL::guActiveTexture(edk::uint32 texture){
    //if(edk::GU_GLSL::initiate)    
    glActiveTexture(texture);
}

//FRAMEBUFFERS
//alloc frameBuffer
edk::uint32 edk::GU_GLSL::guAllocFrameBuffer(edk::uint32 type){
    edk::uint32 ret = 0u;
    if(type == GU_FRAMEBUFFER || type == GU_DRAW_FRAMEBUFFER || type == GU_READ_FRAMEBUFFER){
        glGenFramebuffers(1, &ret);
        if(ret){
            glBindFramebuffer(type, ret);
        }
    }
    return ret;
}
//use FrameBuffer
void edk::GU_GLSL::guUseFrameBuffer(edk::uint32 target,edk::uint32 ID){glBindFramebuffer(target, ID);}
//delete the frameBuffer
void edk::GU_GLSL::guDeleteFrameBuffer(edk::uint32 ID){glDeleteFramebuffers(1u,&ID);}
//use the frameBuffer to the texture
void edk::GU_GLSL::guFrameBufferTexture(edk::uint32 target, edk::uint32 attachment, edk::uint32 texture, edk::uint32 mipmapLevel){glFramebufferTexture(target,attachment,texture,mipmapLevel);}
//Set list of drawBuffers
bool edk::GU_GLSL::guSetDrawBuffers(edk::uint32 size,const edk::uint32 *buffers){
    if(size && buffers){
        glDrawBuffers(size,buffers);
        return true;
    }
    return false;
}
//set one drawBuffer
bool edk::GU_GLSL::guSetDrawBuffer(edk::uint32 buffer){
    edk::uint32 buffers[1u] = {buffer};
    return edk::GU_GLSL::guSetDrawBuffers(1u,buffers);
}
//Check frameBuffer
edk::uint32 edk::GU_GLSL::guCheckFramebufferStatus(edk::uint32 target){return glCheckFramebufferStatus(target);}
bool edk::GU_GLSL::guCheckFrameBufferOK(edk::uint32 target){
    if(edk::GU_GLSL::guCheckFramebufferStatus(target) == GU_FRAMEBUFFER_COMPLETE){
        return true;
    }
    return false;
}

//STRING
//GL_SHADING_LANGUAGE_VERSION
//Returns a version or release number for the shading language of the form
edk::char8* edk::GU_GLSL::guGetVersion(){glGetString(GL_SHADING_LANGUAGE_VERSION);}