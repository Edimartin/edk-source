#include "GU_GLSL.h"

/*
Library GU_GLSL - Add shaders to the GU
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
#pragma message "            Inside GU_GLSL.cpp"
#endif

bool edk::GU_GLSL::initiate=false;
#if defined(_WIN32) || defined(_WIN64)
//Windows
edk::multi::MutexDisable edk::GU_GLSL::mut;
#endif
#ifdef __linux__
//LINUX
edk::multi::Mutex edk::GU_GLSL::mut;
#endif
edk::multi::Mutex edk::GU_GLSL::mutBeginEnd;

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
        edk::GU_GLSL::mut.lock();
        if((ret = glewInit()) == GU_GLSL_OK){
            edk::GU_GLSL::initiate=true;
        }
        edk::GU_GLSL::mut.unlock();
    }
    return ret;
}
//return true if have init the glut
bool edk::GU_GLSL::guShaderInitiated(){
    return edk::GU_GLSL::initiate;
}

bool edk::GU_GLSL::guStartShader(edk::int32 shade){
    bool ret;
    switch(shade){
    case GU_GLSL_fragment_program:
        //
        edk::GU_GLSL::mut.lock();
        ret = glewGetExtension("GL_ARB_fragment_program");
        edk::GU_GLSL::mut.unlock();
        break;
    case GU_GLSL_vertex_program:
        //
        edk::GU_GLSL::mut.lock();
        ret = glewGetExtension("GL_ARB_vertex_program");
        edk::GU_GLSL::mut.unlock();
        break;
    case GU_GLSL_geometry_program:
        //
        edk::GU_GLSL::mut.lock();
        ret = glewGetExtension("GL_ARB_geometry_program");
        edk::GU_GLSL::mut.unlock();
        break;
    }
    //else return false
    return ret;
}
edk::uint32 edk::GU_GLSL::guCreateShader(edk::uint32 type){
    edk::uint32 ret = 0u;
    edk::GU_GLSL::mut.lock();
    ret = glCreateShader(type);
    edk::GU_GLSL::mut.unlock();
    return ret;
}
void edk::GU_GLSL::guDeleteShader(edk::uint32 id){
    edk::GU_GLSL::mut.lock();
    glDeleteShader(id);
    edk::GU_GLSL::mut.unlock();
}
bool edk::GU_GLSL::guShaderSource(edk::uint32 id, edk::uint8 *data,  edk::uint32 length){
    //
    if(id && data && length){
        //set the shaderSource
        edk::GU_GLSL::mut.lock();
        glShaderSource(id,  1u,  (const edk::char8**)(&data),  (const GLint*)&length);
        edk::GU_GLSL::mut.unlock();
        //return true
        return true;
    }
    //else return false
    return false;
}
void edk::GU_GLSL::guCompileShader(edk::uint32 id){
    edk::GU_GLSL::mut.lock();
    glCompileShader(id);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guGetShaderiv(edk::uint32 shader,  edk::uint32 pname,  edk::int32 *params){
    edk::GU_GLSL::mut.lock();
    glGetShaderiv(shader,  pname,  params);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guGetProgramiv(edk::uint32 program, edk::uint32 pname,  edk::int32 *params){
    edk::GU_GLSL::mut.lock();
    glGetProgramiv(program,  pname,  params);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guGetShaderInfoLog(edk::uint32 shader,  edk::int32 maxLength,  edk::int32 *length,  edk::char8 *infoLog){
    edk::GU_GLSL::mut.lock();
    glGetShaderInfoLog(shader,  maxLength,  length,  (GLchar*)infoLog);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guGetProgramInfoLog(edk::uint32 program,  edk::int32 maxLength,  edk::int32 *length,  edk::char8 *infoLog){
    edk::GU_GLSL::mut.lock();
    glGetProgramInfoLog(program,  maxLength,  length,  (GLchar*)infoLog);
    edk::GU_GLSL::mut.unlock();
}
//shader program
edk::uint32 edk::GU_GLSL::guCreateProgram(){
    edk::uint32 ret;
    edk::GU_GLSL::mut.lock();
    ret = glCreateProgram();
    edk::GU_GLSL::mut.unlock();
    return ret;
}
bool edk::GU_GLSL::guProgramUseShader(edk::uint32 id,edk::uint32 shaderId){
    edk::GU_GLSL::mut.lock();
    glAttachShader(id,shaderId);
    edk::GU_GLSL::mut.unlock();
    return true;
}
void edk::GU_GLSL::guProgramRemoveShader(edk::uint32 id,edk::uint32 shaderId){
    edk::GU_GLSL::mut.lock();
    glDetachShader(id,shaderId);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guDeleteProgram(edk::uint32 id){
    edk::GU_GLSL::mut.lock();
    glDeleteProgram(id);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guLinkProgram(edk::uint32 shaderID){
    edk::GU_GLSL::mut.lock();
    glLinkProgram(shaderID);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guUseProgram(edk::uint32 shaderID){
    edk::GU_GLSL::mut.lock();
    glUseProgram(shaderID);
    edk::GU_GLSL::mut.unlock();
}

void edk::GU_GLSL::guData1i32(edk::int32 id,edk::int32 d0){
    edk::GU_GLSL::mut.lock();
    glUniform1i(id,d0);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData2i32(edk::int32 id,edk::vec2i32 d){
    edk::GU_GLSL::mut.lock();
    glUniform2i(id,d.x,d.y);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData2i32(edk::int32 id,edk::int32 d0,edk::int32 d1){
    edk::GU_GLSL::mut.lock();
    glUniform2i(id,d0,d1);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData3i32(edk::int32 id,edk::vec3i32 d){
    edk::GU_GLSL::mut.lock();
    glUniform3i(id,d.x,d.y,d.z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData3i32(edk::int32 id,edk::int32 d0,edk::int32 d1,edk::int32 d2){
    edk::GU_GLSL::mut.lock();
    glUniform3i(id,d0,d1,d2);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData4i32(edk::int32 id,edk::vec4i32 d){
    edk::GU_GLSL::mut.lock();
    glUniform4i(id,d.x,d.y,d.z,d.w);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData4i32(edk::int32 id,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3){
    edk::GU_GLSL::mut.lock();
    glUniform4i(id,d0,d1,d2,d3);
    edk::GU_GLSL::mut.unlock();
}

void edk::GU_GLSL::guData1f32(edk::int32 id,edk::float32 d0){
    edk::GU_GLSL::mut.lock();
    glUniform1f(id,d0);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData2f32(edk::int32 id,edk::vec2f32 d){
    edk::GU_GLSL::mut.lock();
    glUniform2f(id,d.x,d.y);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData2f32(edk::int32 id,edk::float32 d0,edk::float32 d1){
    edk::GU_GLSL::mut.lock();
    glUniform2f(id,d0,d1);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData3f32(edk::int32 id,edk::vec3f32 d){
    edk::GU_GLSL::mut.lock();
    glUniform3f(id,d.x,d.y,d.z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData3f32(edk::int32 id,edk::float32 d0,edk::float32 d1,edk::float32 d2){
    edk::GU_GLSL::mut.lock();
    glUniform3f(id,d0,d1,d2);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData4f32(edk::int32 id,edk::vec4f32 d){
    edk::GU_GLSL::mut.lock();
    glUniform4f(id,d.x,d.y,d.z,d.w);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData4f32(edk::int32 id,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3){
    edk::GU_GLSL::mut.lock();
    glUniform4f(id,d0,d1,d2,d3);
    edk::GU_GLSL::mut.unlock();
}

//MATRICES
void edk::GU_GLSL::guMatrix2f32(edk::int32 id,edk::float32* mat){
    edk::GU_GLSL::mut.lock();
    glUniformMatrix2fv(id,1u, false,mat);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guMatrix3f32(edk::int32 id,edk::float32* mat){
    edk::GU_GLSL::mut.lock();
    glUniformMatrix3fv(id,1u, false,mat);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guMatrix4f32(edk::int32 id,edk::float32* mat){
    edk::GU_GLSL::mut.lock();
    glUniformMatrix4fv(id,1u, false,mat);
    edk::GU_GLSL::mut.unlock();
}

bool edk::GU_GLSL::guReadTexture(edk::uint32 ID,edk::uint32 format,const edk::classID  data){
    //test the ID
    if(ID){
        edk::GU_GLSL::mut.lock();
        //Set using texture
        glBindTexture(GL_TEXTURE_2D,ID);
        //
        glGetTexImage(GL_TEXTURE_2D,
                      0u,
                      format,
                      GL_UNSIGNED_BYTE,
                      data
                      );
        //Clean use texture
        glBindTexture(GL_TEXTURE_2D, 0u);
        edk::GU_GLSL::mut.unlock();
        return true;
    }
    return false;
}
/*
void edk::GU_GLSL::guVertexData1i32(edk::int32 id,edk::int32 d0){glVertexAttrib1i(id,d0);}
void edk::GU_GLSL::guVertexData2i32(edk::int32 id,edk::vec2i32 d){glVertexAttrib2i(id,d.x,d.y);}
void edk::GU_GLSL::guVertexData2i32(edk::int32 id,edk::int32 d0,edk::int32 d1){glVertexAttrib2i(id,d0,d1);}
void edk::GU_GLSL::guVertexData3i32(edk::int32 id,edk::vec3i32 d){glVertexAttrib3i(id,d.x,d.y,d.z);}
void edk::GU_GLSL::guVertexData3i32(edk::int32 id,edk::int32 d0,edk::int32 d1,edk::int32 d2){glVertexAttrib3i(id,d0,d1,d2);}
void edk::GU_GLSL::guVertexData4i32(edk::int32 id,edk::vec4i32 d){glVertexAttrib4i(id,d.x,d.y,d.z,d.w);}
void edk::GU_GLSL::guVertexData4i32(edk::int32 id,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3){glVertexAttrib4i(id,d0,d1,d2,d3);}
*/
void edk::GU_GLSL::guVertexData1f32(edk::int32 id,edk::float32 d0){
    edk::GU_GLSL::mut.lock();
    glVertexAttrib1f(id,d0);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexData2f32(edk::int32 id,edk::vec2f32 d){
    edk::GU_GLSL::mut.lock();
    glVertexAttrib2f(id,d.x,d.y);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexData2f32(edk::int32 id,edk::float32 d0,edk::float32 d1){
    edk::GU_GLSL::mut.lock();
    glVertexAttrib2f(id,d0,d1);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexData3f32(edk::int32 id,edk::vec3f32 d){
    edk::GU_GLSL::mut.lock();
    glVertexAttrib3f(id,d.x,d.y,d.z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexData3f32(edk::int32 id,edk::float32 d0,edk::float32 d1,edk::float32 d2){
    edk::GU_GLSL::mut.lock();
    glVertexAttrib3f(id,d0,d1,d2);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexData4f32(edk::int32 id,edk::vec4f32 d){
    edk::GU_GLSL::mut.lock();
    glVertexAttrib4f(id,d.x,d.y,d.z,d.w);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexData4f32(edk::int32 id,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3){
    edk::GU_GLSL::mut.lock();
    glVertexAttrib4f(id,d0,d1,d2,d3);
    edk::GU_GLSL::mut.unlock();
}

//return the data location
edk::int32 edk::GU_GLSL::guGetDataLocation(edk::uint32 program, const edk::char8 *name){
    edk::int32 ret;
    edk::GU_GLSL::mut.lock();
    ret = glGetUniformLocation(program,name);
    edk::GU_GLSL::mut.unlock();
    return ret;
}
edk::int32 edk::GU_GLSL::guGetDataLocation(edk::uint32 program, edk::char8* name){
    edk::int32 ret;
    edk::GU_GLSL::mut.lock();
    ret = glGetUniformLocation(program,(const edk::char8*)name);
    edk::GU_GLSL::mut.unlock();
    return ret;
}
//return the vertexData location
edk::int32 edk::GU_GLSL::guGetVertexDataLocation(edk::uint32 program, const edk::char8 *name){
    edk::int32 ret;
    edk::GU_GLSL::mut.lock();
    ret = glGetAttribLocation(program,name);
    edk::GU_GLSL::mut.unlock();
    return ret;
}
edk::int32 edk::GU_GLSL::guGetVertexDataLocation(edk::uint32 program, edk::char8* name){
    edk::int32 ret;
    edk::GU_GLSL::mut.lock();
    ret = glGetAttribLocation(program,(const edk::char8*)name);
    edk::GU_GLSL::mut.unlock();
    return ret;
}

//Errors
edk::char8* edk::GU_GLSL::guGetErrorString(edk::int32 error){
    edk::char8* ret;
    edk::GU_GLSL::mut.lock();
    ret = (edk::char8*)glewGetErrorString(error);
    edk::GU_GLSL::mut.unlock();
    return ret;
}
//glewGetString(GLEW_VERSION)
//edk::char8* edk::GU_GLSL::glewGetString(edk::int32 version){return (edk::char8*)glewGetString(version);}

//If it crash. Dont forget to init the shader
void edk::GU_GLSL::guActiveTexture(edk::uint32 texture){
    //if(edk::GU_GLSL::initiate){
    edk::GU_GLSL::mut.lock();
    glActiveTexture(texture);
    edk::GU_GLSL::mut.unlock();
    //}
}

//BUFFERS
//alloc Buffer
edk::uint32 edk::GU_GLSL::guAllocBuffer(edk::uint32 type){
    edk::uint32 ret = 0u;
    if(edk::GU_GLSL::guShaderInitiated() &&
            (
                type == GU_ARRAY_BUFFER
                || type == GU_ATOMIC_COUNTER_BUFFER
                || type == GU_COPY_READ_BUFFER
                || type == GU_COPY_WRITE_BUFFER
                || type == GU_DISPATCH_INDIRECT_BUFFER
                || type == GU_DRAW_INDIRECT_BUFFER
                || type == GU_ELEMENT_ARRAY_BUFFER
                || type == GU_PIXEL_PACK_BUFFER
                || type == GU_PIXEL_UNPACK_BUFFER
                || type == GU_QUERY_BUFFER
                || type == GU_SHADER_STORAGE_BUFFER
                || type == GU_TEXTURE_BUFFER
                || type == GU_TRANSFORM_FEEDBACK_BUFFER
                || type == GU_UNIFORM_BUFFER
                )
            ){
        edk::GU_GLSL::mut.lock();
        glGenBuffers(1, &ret);
        if(ret){
            glBindBuffer(type, ret);
        }
        edk::GU_GLSL::mut.unlock();
    }
    return ret;
}
//use Buffer
void edk::GU_GLSL::guUseBuffer(edk::uint32 type,edk::uint32 ID){
    edk::GU_GLSL::mut.lock();
    glBindBuffer(type, ID);
    edk::GU_GLSL::mut.unlock();
}
//do not use Buffer
void edk::GU_GLSL::guDontUseBuffer(edk::uint32 type){
    edk::GU_GLSL::mut.lock();
    glBindBuffer(type, 0u);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guDontUseAllBuffer(){
    edk::GU_GLSL::mut.lock();
    glBindBuffer(GU_FRAMEBUFFER,0u);
    glBindBuffer(GU_DRAW_FRAMEBUFFER,0u);
    glBindBuffer(GU_READ_FRAMEBUFFER,0u);
    edk::GU_GLSL::mut.unlock();
}
//delete the Buffer
void edk::GU_GLSL::guDeleteBuffer(edk::uint32 ID){
    edk::GU_GLSL::mut.lock();
    glDeleteBuffers(1u,&ID);
    edk::GU_GLSL::mut.unlock();
}
//add the buffer in to the vbo
bool edk::GU_GLSL::guBufferData(edk::uint32 type, edk::uint64 size, const edk::classID data, edk::uint32 usage){
    if(data && size){
        edk::GU_GLSL::mut.lock();
        glBufferData(type, size, data,usage);
        edk::GU_GLSL::mut.unlock();
        return true;
    }
    return false;
}
void edk::GU_GLSL::guEnableClientState(edk::uint32 cap){
    edk::GU_GLSL::mut.lock();
    glEnableClientState(cap);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guDisableClientState(edk::uint32 cap){
    edk::GU_GLSL::mut.lock();
    glDisableClientState(cap);
    edk::GU_GLSL::mut.unlock();
}

//Use a TextCoord from a pointer
void edk::GU_GLSL::guTexCoordPointer1i16(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(1, GL_SHORT,16,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer2i16(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(2, GL_SHORT,16,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer3i16(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(3, GL_SHORT,16,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer4i16(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(4, GL_SHORT,16,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer1i32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(1, GL_INT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer2i32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(2, GL_INT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer3i32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(3, GL_INT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer4i32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(4, GL_INT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer1f32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(1, GL_FLOAT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer2f32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(2, GL_FLOAT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer3f32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(3, GL_FLOAT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer4f32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(4, GL_FLOAT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer1f64(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(1, GL_DOUBLE,64,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer2f64(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(2, GL_DOUBLE,64,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer3f64(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(3, GL_DOUBLE,64,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer4f64(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(4, GL_DOUBLE,64,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}


void edk::GU_GLSL::guColorPointer3ui8(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glColorPointer(3, GL_UNSIGNED_BYTE,8,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer4ui8(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glColorPointer(4, GL_UNSIGNED_BYTE,8,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer3i8(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glColorPointer(3, GL_BYTE,8,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer4i8(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glColorPointer(4, GL_BYTE,8,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer3ui16(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glColorPointer(3, GL_UNSIGNED_SHORT,16,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer4ui16(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glColorPointer(4, GL_UNSIGNED_SHORT,16,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer3i16(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glColorPointer(3, GL_SHORT,16,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer4i16(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glColorPointer(4, GL_SHORT,16,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer3ui32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glColorPointer(3, GL_UNSIGNED_INT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer4ui32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glColorPointer(4, GL_UNSIGNED_INT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer3i32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glColorPointer(3, GL_INT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer4i32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glColorPointer(4, GL_INT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer3f32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glColorPointer(3, GL_FLOAT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer4f32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glColorPointer(4, GL_FLOAT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer3f64(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glColorPointer(3, GL_DOUBLE,64,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer4f64(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glColorPointer(4, GL_DOUBLE,64,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}

//use a Normal from a pointer
void edk::GU_GLSL::guNormalPointerI8(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glNormalPointer(GL_BYTE,8,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guNormalPointerI16(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glNormalPointer(GL_SHORT,16,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guNormalPointerI32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glNormalPointer(GL_INT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guNormalPointerF32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glNormalPointer(GL_FLOAT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guNormalPointerF64(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glNormalPointer(GL_DOUBLE,64,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}

//use a vertex from a pointer
void edk::GU_GLSL::guVertexPointer2i16(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(2, GL_SHORT,16,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer2i32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(2, GL_INT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer2f32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(2, GL_FLOAT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer2f64(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(2, GL_DOUBLE,64,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer3i16(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(3, GL_SHORT,16,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer3i32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(3, GL_INT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer3f32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(3, GL_FLOAT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer3f64(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(3, GL_DOUBLE,64,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer4i16(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(4, GL_SHORT,16,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer4i32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(4, GL_INT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer4f32(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(4, GL_FLOAT,32,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer4f64(edk::uint64 position){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(4, GL_DOUBLE,64,(edk::classID)position);
    edk::GU_GLSL::mut.unlock();
}

//draw the array from a pointer
void edk::GU_GLSL::guDrawArrays(edk::uint32 mode,edk::int32 first,edk::uint64 count){
    edk::GU_GLSL::mut.lock();
    glDrawArrays(mode,first,count);
    edk::GU_GLSL::mut.unlock();
}

//Check Buffer
//edk::uint32 edk::GU_GLSL::guCheckBufferStatus(edk::uint32 type){
//    edk::uint32 ret;
//    edk::GU_GLSL::mut.lock();
//    ret = glCheckBufferStatus(type);
//    edk::GU_GLSL::mut.unlock();
//    return ret;
//}
//bool edk::GU_GLSL::guCheckBufferOK(edk::uint32 type){
//    if(edk::GU_GLSL::guCheckBufferStatus(type) == GU_FRAMEBUFFER_COMPLETE){
//        return true;
//    }
//    return false;
//}

//FRAMEBUFFERS
//alloc frameBuffer
edk::uint32 edk::GU_GLSL::guAllocFrameBuffer(edk::uint32 type){
    edk::uint32 ret = 0u;
    if(type == GU_FRAMEBUFFER || type == GU_DRAW_FRAMEBUFFER || type == GU_READ_FRAMEBUFFER){
        edk::GU_GLSL::mut.lock();
        glGenFramebuffers(1, &ret);
        if(ret){
            glBindFramebuffer(type, ret);
        }
        edk::GU_GLSL::mut.unlock();
    }
    return ret;
}
//use FrameBuffer
void edk::GU_GLSL::guUseFrameBuffer(edk::uint32 type,edk::uint32 ID){
    edk::GU_GLSL::mut.lock();
    glBindFramebuffer(type, ID);
    edk::GU_GLSL::mut.unlock();
}
//do not use FrameBuffer
void edk::GU_GLSL::guDontUseFrameBuffer(edk::uint32 type){
    edk::GU_GLSL::mut.lock();
    glBindFramebuffer(type, 0u);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guDontUseAllFrameBuffer(){
    edk::GU_GLSL::mut.lock();
    glBindFramebuffer(GU_FRAMEBUFFER,0u);
    glBindFramebuffer(GU_DRAW_FRAMEBUFFER,0u);
    glBindFramebuffer(GU_READ_FRAMEBUFFER,0u);
    edk::GU_GLSL::mut.unlock();
}
//delete the frameBuffer
void edk::GU_GLSL::guDeleteFrameBuffer(edk::uint32 ID){
    edk::GU_GLSL::mut.lock();
    glDeleteFramebuffers(1u,&ID);
    edk::GU_GLSL::mut.unlock();
}
//use the frameBuffer to the texture
void edk::GU_GLSL::guFrameBufferTexture(edk::uint32 target, edk::uint32 attachment, edk::uint32 texture, edk::uint32 mipmapLevel){
    edk::GU_GLSL::mut.lock();
    glFramebufferTexture(target,attachment,texture,mipmapLevel);
    edk::GU_GLSL::mut.unlock();
}
//Set list of drawBuffers
bool edk::GU_GLSL::guSetDrawBuffers(edk::uint32 size,const edk::uint32 *buffers){
    if(size && buffers){
        edk::GU_GLSL::mut.lock();
        glDrawBuffers(size,buffers);
        edk::GU_GLSL::mut.unlock();
        return true;
    }
    return false;
}
//set one drawBuffer
bool edk::GU_GLSL::guSetDrawBuffer(edk::uint32 buffer){
    edk::uint32 buffers[1u] = {buffer};
    bool ret;
    ret = edk::GU_GLSL::guSetDrawBuffers(1u,buffers);
    return ret;
}
//Check frameBuffer
edk::uint32 edk::GU_GLSL::guCheckFrameBufferStatus(edk::uint32 target){
    edk::uint32 ret;
    edk::GU_GLSL::mut.lock();
    ret = glCheckFramebufferStatus(target);
    edk::GU_GLSL::mut.unlock();
    return ret;
}
bool edk::GU_GLSL::guCheckFrameBufferOK(edk::uint32 target){
    if(edk::GU_GLSL::guCheckFrameBufferStatus(target) == GU_FRAMEBUFFER_COMPLETE){
        return true;
    }
    return false;
}



//RENDERBUFFERS
//alloc renderBuffer
edk::uint32 edk::GU_GLSL::guAllocRenderBuffer(){
    edk::uint32 ret = 0u;
    edk::GU_GLSL::mut.lock();
    glGenRenderbuffers(1, &ret);
    if(ret){
        glBindRenderbuffer(GL_RENDERBUFFER, ret);
    }
    edk::GU_GLSL::mut.unlock();
    return ret;
}
//use RenderBuffer
void edk::GU_GLSL::guUseRenderBuffer(edk::uint32 ID){
    edk::GU_GLSL::mut.lock();
    glBindRenderbuffer(GL_RENDERBUFFER, ID);
    edk::GU_GLSL::mut.unlock();
}
//do not use RenderBuffer
void edk::GU_GLSL::guDontUseRenderBuffer(){
    edk::GU_GLSL::mut.lock();
    glBindRenderbuffer(GL_RENDERBUFFER, 0u);
    edk::GU_GLSL::mut.unlock();
}
//delete the RenderBuffer
void edk::GU_GLSL::guDeleteRenderBuffer(edk::uint32 ID){
    edk::GU_GLSL::mut.lock();
    glDeleteRenderbuffers(1u,&ID);
    edk::GU_GLSL::mut.unlock();
}
//use the RenderBuffer to the texture
//void edk::GU_GLSL::guRenderBufferTexture(edk::uint32 type, edk::uint32 attachment, edk::uint32 texture, edk::uint32 mipmapLevel){
//    edk::GU_GLSL::mut.lock();
//    glRenderbufferTexture(type,attachment,texture,mipmapLevel);
//    edk::GU_GLSL::mut.unlock();
//}
//Check RenderBuffer
//edk::uint32 edk::GU_GLSL::guCheckRenderbufferStatus(edk::uint32 type){
//    edk::uint32 ret;
//    edk::GU_GLSL::mut.lock();
//    ret = glCheckRenderbufferStatus(type);
//    edk::GU_GLSL::mut.unlock();
//    return ret;
//}
//bool edk::GU_GLSL::guCheckRenderBufferOK(edk::uint32 type){
//    if(edk::GU_GLSL::guCheckRenderBufferStatus(type) == GU_FRAMEBUFFER_COMPLETE){
//        return true;
//    }
//    return false;
//}

//STRING
//GL_SHADING_LANGUAGE_VERSION
//Returns a version or release number for the shading language of the form
edk::char8* edk::GU_GLSL::guGetVersion(){
    edk::char8* ret;
    edk::GU_GLSL::mut.lock();
    ret = (edk::char8*)glGetString(GL_SHADING_LANGUAGE_VERSION);
    edk::GU_GLSL::mut.unlock();
    return ret;
}
