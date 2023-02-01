#ifndef EDK_GU_GLSL_H
#define EDK_GU_GLSL_H

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
#warning "Inside GU_GLSL"
#endif

//add the GLEW before openGL
#if defined(_WIN32) || defined(__linux__)
#include <GL/glew.h>
//#include <GL/glext.h>
#define USING_GLEW
#elif defined(__APPLE__)
#include <OpenGL/glew.h>
#include <OpenGL/glext.h>
#define USING_GLEW
#endif

#include "../TypeVars.h"
#include "../DebugFile.h"
#include "../TypeVec2.h"
#include "../TypeVec3.h"
#include "../TypeVec4.h"

#ifdef printMessages
#warning "    Compiling GU_GLSL"
#endif

//Defines
#define GU_GLSL_OK 0 //OK
#define GU_GLSL_ERROR_NO_GU 1  //No GraphicUnity
//this error is only with open
#ifdef USING_GLEW
#define GLEW_ERROR_GL_10 2  //need openGL 1.1
#define GLEW_ERROR_GLX_11 3 //need openGL 1.2
#endif

#define GU_GLSL_fragment_program 11u
#define GU_GLSL_vertex_program   12u
#define GU_GLSL_geometry_program 13u

#define GU_GLSL_FRAGMENT_SHADER 0x8B30
#define GU_GLSL_VERTEX_SHADER 0x8B31

#define GU_SHADER_TYPE 0x8B4F
#define GU_DELETE_STATUS 0x8B80
#define GU_COMPILE_STATUS 0x8B81
#define GU_INFO_LOG_LENGTH 0x8B84
#define GU_SHADER_SOURCE_LENGTH 0x8B88

#define GU_LINK_STATUS 0x8B82
#define GU_VALIDATE_STATUS 0x8B83
#define GU_ATTACHED_SHADERS 0x8B85
#define GU_ACTIVE_ATTRIBUTES 0x8B89
#define GU_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GU_ACTIVE_UNIFORMS 0x8B86
#define GU_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87

//Textures
#define GU_TEXTURE0				    0x84C0
#define GU_TEXTURE1				    0x84C1
#define GU_TEXTURE2				    0x84C2
#define GU_TEXTURE3				    0x84C3
#define GU_TEXTURE4				    0x84C4
#define GU_TEXTURE5				    0x84C5
#define GU_TEXTURE6				    0x84C6
#define GU_TEXTURE7				    0x84C7
#define GU_TEXTURE8				    0x84C8
#define GU_TEXTURE9				    0x84C9
#define GU_TEXTURE10				0x84CA
#define GU_TEXTURE11				0x84CB
#define GU_TEXTURE12				0x84CC
#define GU_TEXTURE13				0x84CD
#define GU_TEXTURE14				0x84CE
#define GU_TEXTURE15				0x84CF
#define GU_TEXTURE16				0x84D0
#define GU_TEXTURE17				0x84D1
#define GU_TEXTURE18				0x84D2
#define GU_TEXTURE19				0x84D3
#define GU_TEXTURE20				0x84D4
#define GU_TEXTURE21				0x84D5
#define GU_TEXTURE22				0x84D6
#define GU_TEXTURE23				0x84D7
#define GU_TEXTURE24				0x84D8
#define GU_TEXTURE25				0x84D9
#define GU_TEXTURE26				0x84DA
#define GU_TEXTURE27				0x84DB
#define GU_TEXTURE28				0x84DC
#define GU_TEXTURE29				0x84DD
#define GU_TEXTURE30				0x84DE
#define GU_TEXTURE31				0x84DF

//FRAMEBUFFER
#define GU_FRAMEBUFFER                          0x8D40
#define GU_READ_FRAMEBUFFER                     0x8CA8
#define GU_DRAW_FRAMEBUFFER                     0x8CA9
#define GU_COLOR_ATTACHMENT0                    0x8CE0
#define GU_COLOR_ATTACHMENT1                    0x8CE1
#define GU_COLOR_ATTACHMENT2                    0x8CE2
#define GU_COLOR_ATTACHMENT3                    0x8CE3
#define GU_COLOR_ATTACHMENT4                    0x8CE4
#define GU_COLOR_ATTACHMENT5                    0x8CE5
#define GU_COLOR_ATTACHMENT6                    0x8CE6
#define GU_COLOR_ATTACHMENT7                    0x8CE7
#define GU_COLOR_ATTACHMENT8                    0x8CE8
#define GU_COLOR_ATTACHMENT9                    0x8CE9
#define GU_COLOR_ATTACHMENT10                   0x8CEA
#define GU_COLOR_ATTACHMENT11                   0x8CEB
#define GU_COLOR_ATTACHMENT12                   0x8CEC
#define GU_COLOR_ATTACHMENT13                   0x8CED
#define GU_COLOR_ATTACHMENT14                   0x8CEE
#define GU_COLOR_ATTACHMENT15                   0x8CEF
#define GU_DEPTH_ATTACHMENT                     0x8D00
#define GU_STENCIL_ATTACHMENT                   0x8D20
#define GU_FRAMEBUFFER_COMPLETE                 0x8CD5
#define GU_FRAMEBUFFER_INCOMPLETE_ATTACHMENT    0x8CD6
#define GU_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GU_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER   0x8CDB
#define GU_FRAMEBUFFER_INCOMPLETE_READ_BUFFER   0x8CDC
#define GU_FRAMEBUFFER_UNSUPPORTED              0x8CDD

#define GU_STENCIL_INDEX GL_STENCIL_INDEX
#define GU_DEPTH_COMPONENT GL_DEPTH_COMPONENT
#define GU_DEPTH_STENCIL GL_DEPTH_STENCIL
#define GU_RED GL_RED
#define GU_GREEN GL_GREEN
#define GU_BLUE GL_BLUE
#define GU_RG GL_RG
#define GU_RGB GL_RGB
#define GU_RGBA GL_RGBA
#define GU_BGR GL_BGR
#define GU_BGRA GL_BGRA

namespace edk{
class GU_GLSL{
    public:
    //construtor
    GU_GLSL();

    //destrutor
    ~GU_GLSL();
    //start the shaderLib
    static edk::int32 guShaderInit();
    //return true if have init the glut
    static bool guShaderInitiate();

    static bool guStartShader(edk::int32 shade);
    static edk::uint32 guCreateShader(edk::uint32 type);
    static void guDeleteShader(edk::uint32 id);
    //Set the shader source to the shader program
    static bool guShaderSource(edk::uint32 id, edk::uint8 *data,  edk::uint32 length);
    //Compile the shader source
    static void guCompileShader(edk::uint32 id);
    static void guGetShaderiv(edk::uint32 shader,  edk::uint32 pname,  edk::int32 *params);
    static void guGetProgramiv(edk::uint32 program, edk::uint32 pname,  edk::int32 *params);
    static void guGetShaderInfoLog(edk::uint32 shader,  edk::int32 maxLength,  edk::int32 *length,  edk::char8 *infoLog);
    static void guGetProgramInfoLog(edk::uint32 program,  edk::int32 maxLength,  edk::int32 *length,  edk::char8 *infoLog);
    //shader program
    static edk::uint32 guCreateProgram();
    static bool guProgramUseShader(edk::uint32 id,edk::uint32 shaderId);
    static void guProgramRemoveShader(edk::uint32 id,edk::uint32 shaderId);
    static void guDeleteProgram(edk::uint32 id);
    static void guLinkProgram(edk::uint32 shaderID);
    static void guUseProgram(edk::uint32 shaderID);

    static void guData1i32(edk::int32 id,edk::int32 d0);
    static void guData2i32(edk::int32 id,edk::vec2i32 d);
    static void guData2i32(edk::int32 id,edk::int32 d0,edk::int32 d1);
    static void guData3i32(edk::int32 id,edk::vec3i32 d);
    static void guData3i32(edk::int32 id,edk::int32 d0,edk::int32 d1,edk::int32 d2);
    static void guData4i32(edk::int32 id,edk::vec4i32 d);
    static void guData4i32(edk::int32 id,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3);

    static void guData1f32(edk::int32 id,edk::float32 d0);
    static void guData2f32(edk::int32 id,edk::vec2f32 d);
    static void guData2f32(edk::int32 id,edk::float32 d0,edk::float32 d1);
    static void guData3f32(edk::int32 id,edk::vec3f32 d);
    static void guData3f32(edk::int32 id,edk::float32 d0,edk::float32 d1,edk::float32 d2);
    static void guData4f32(edk::int32 id,edk::vec4f32 d);
    static void guData4f32(edk::int32 id,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3);

    //MATRICES
    static void guMatrix2f32(edk::int32 id,edk::float32* mat);
    static void guMatrix3f32(edk::int32 id,edk::float32* mat);
    static void guMatrix4f32(edk::int32 id,edk::float32* mat);

    //format
    //GU_STENCIL_INDEX
    //GU_DEPTH_COMPONENT
    //GU_DEPTH_STENCIL
    //GU_RED
    //GU_GREEN
    //GU_BLUE
    //GU_RG
    //GU_RGB
    //GU_RGBA
    //GU_BGR
    //GU_BGRA
    static bool guReadTexture(edk::uint32 ID,edk::uint32 format, const edk::classID  data);
    //matrix
    //glUniformMatrix2fv
/*
    static void guVertexData1i32(edk::int32 id,edk::int32 d0);
    static void guVertexData2i32(edk::int32 id,edk::vec2i32 d);
    static void guVertexData2i32(edk::int32 id,edk::int32 d0,edk::int32 d1);
    static void guVertexData3i32(edk::int32 id,edk::vec3i32 d);
    static void guVertexData3i32(edk::int32 id,edk::int32 d0,edk::int32 d1,edk::int32 d2);
    static void guVertexData4i32(edk::int32 id,edk::vec4i32 d);
    static void guVertexData4i32(edk::int32 id,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3);
*/
    static void guVertexData1f32(edk::int32 id,edk::float32 d0);
    static void guVertexData2f32(edk::int32 id,edk::vec2f32 d);
    static void guVertexData2f32(edk::int32 id,edk::float32 d0,edk::float32 d1);
    static void guVertexData3f32(edk::int32 id,edk::vec3f32 d);
    static void guVertexData3f32(edk::int32 id,edk::float32 d0,edk::float32 d1,edk::float32 d2);
    static void guVertexData4f32(edk::int32 id,edk::vec4f32 d);
    static void guVertexData4f32(edk::int32 id,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3);

    //return the data location
    static edk::int32 guGetDataLocation(edk::uint32 program, const edk::char8 *name);
    static edk::int32 guGetDataLocation(edk::uint32 program, edk::char8* name);
    //return the bertexData location
    static edk::int32 guGetVertexDataLocation(edk::uint32 program, const edk::char8 *name);
    static edk::int32 guGetVertexDataLocation(edk::uint32 program, edk::char8* name);

    //Errors
    static edk::char8* guGetErrorString(edk::int32 error);
    //static edk::char8* glewGetString(edk::int32 version);

    //Set the active texture to use
    static void guActiveTexture(edk::uint32 texture);

    //FRAMEBUFFERS
    //alloc frameBuffer
    static edk::uint32 guAllocFrameBuffer(edk::uint32 type);
    //use FrameBuffer
    static void guUseFrameBuffer(edk::uint32 target,edk::uint32 ID);
    //delete the frameBuffer
    static void guDeleteFrameBuffer(edk::uint32 ID);
    //use the frameBuffer to the texture
    static void guFrameBufferTexture(edk::uint32 target, edk::uint32 attachment, edk::uint32 texture, edk::uint32 mipmapLevel);
    //Set list of drawBuffers
    static bool guSetDrawBuffers(edk::uint32 size,const edk::uint32 *buffers);
    //set one drawBuffer
    static bool guSetDrawBuffer(edk::uint32 buffer);
    //Check frameBuffer
    static edk::uint32 guCheckFramebufferStatus(edk::uint32 target);
    static bool guCheckFrameBufferOK(edk::uint32 target);

    //STRING
    //GL_SHADING_LANGUAGE_VERSION
    //Returns a version or release number for the shading language of the form
    static edk::char8* guGetVersion();

private:
    static bool initiate;
};
}//end namespace edk

#endif // GU_GLSL_H
