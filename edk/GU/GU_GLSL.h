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
#pragma message "Inside GU_GLSL"
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

//include the mutex
#include "edk/vector/Queue.h"
#include "edk/vector/BinaryTree.h"
#include "edk/watch/Time.h"
#include "edk/thread/Mutex.h"

#include "../TypeVars.h"
#include "../TypeVec2.h"
#include "../TypeVec3.h"
#include "../TypeVec4.h"

#ifdef printMessages
#pragma message "    Compiling GU_GLSL"
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

#define GU_GLSL_FRAGMENT_SHADER GL_FRAGMENT_SHADER
#define GU_GLSL_VERTEX_SHADER   GL_VERTEX_SHADER

#define GU_SHADER_TYPE          GL_SHADER_TYPE
#define GU_DELETE_STATUS        GL_DELETE_STATUS
#define GU_COMPILE_STATUS       GL_COMPILE_STATUS
#define GU_INFO_LOG_LENGTH      GL_INFO_LOG_LENGTH
#define GU_SHADER_SOURCE_LENGTH GL_SHADER_SOURCE_LENGTH

#define GU_LINK_STATUS                 GL_LINK_STATUS
#define GU_VALIDATE_STATUS             GL_VALIDATE_STATUS
#define GU_ATTACHED_SHADERS            GL_ATTACHED_SHADERS
#define GU_ACTIVE_ATTRIBUTES           GL_ACTIVE_ATTRIBUTES
#define GU_ACTIVE_ATTRIBUTE_MAX_LENGTH GL_ACTIVE_ATTRIBUTE_MAX_LENGTH
#define GU_ACTIVE_UNIFORMS             GL_ACTIVE_UNIFORMS
#define GU_ACTIVE_UNIFORM_MAX_LENGTH   GL_ACTIVE_UNIFORM_MAX_LENGTH

//Textures
#define GU_TEXTURE0				    GL_TEXTURE0
#define GU_TEXTURE1				    GL_TEXTURE1
#define GU_TEXTURE2				    GL_TEXTURE2
#define GU_TEXTURE3				    GL_TEXTURE3
#define GU_TEXTURE4				    GL_TEXTURE4
#define GU_TEXTURE5				    GL_TEXTURE5
#define GU_TEXTURE6				    GL_TEXTURE6
#define GU_TEXTURE7				    GL_TEXTURE7
#define GU_TEXTURE8				    GL_TEXTURE8
#define GU_TEXTURE9				    GL_TEXTURE9
#define GU_TEXTURE10				GL_TEXTURE10
#define GU_TEXTURE11				GL_TEXTURE11
#define GU_TEXTURE12				GL_TEXTURE12
#define GU_TEXTURE13				GL_TEXTURE13
#define GU_TEXTURE14				GL_TEXTURE14
#define GU_TEXTURE15				GL_TEXTURE15
#define GU_TEXTURE16				GL_TEXTURE16
#define GU_TEXTURE17				GL_TEXTURE17
#define GU_TEXTURE18				GL_TEXTURE18
#define GU_TEXTURE19				GL_TEXTURE19
#define GU_TEXTURE20				GL_TEXTURE20
#define GU_TEXTURE21				GL_TEXTURE21
#define GU_TEXTURE22				GL_TEXTURE22
#define GU_TEXTURE23				GL_TEXTURE23
#define GU_TEXTURE24				GL_TEXTURE24
#define GU_TEXTURE25				GL_TEXTURE25
#define GU_TEXTURE26				GL_TEXTURE26
#define GU_TEXTURE27				GL_TEXTURE27
#define GU_TEXTURE28				GL_TEXTURE28
#define GU_TEXTURE29				GL_TEXTURE29
#define GU_TEXTURE30				GL_TEXTURE30
#define GU_TEXTURE31				GL_TEXTURE31

//FRAMEBUFFER
#define GU_FRAMEBUFFER                               GL_FRAMEBUFFER
#define GU_READ_FRAMEBUFFER                          GL_READ_FRAMEBUFFER
#define GU_DRAW_FRAMEBUFFER                          GL_DRAW_FRAMEBUFFER
#define GU_COLOR_ATTACHMENT0                         GL_COLOR_ATTACHMENT0
#define GU_COLOR_ATTACHMENT1                         GL_COLOR_ATTACHMENT1
#define GU_COLOR_ATTACHMENT2                         GL_COLOR_ATTACHMENT2
#define GU_COLOR_ATTACHMENT3                         GL_COLOR_ATTACHMENT3
#define GU_COLOR_ATTACHMENT4                         GL_COLOR_ATTACHMENT4
#define GU_COLOR_ATTACHMENT5                         GL_COLOR_ATTACHMENT5
#define GU_COLOR_ATTACHMENT6                         GL_COLOR_ATTACHMENT6
#define GU_COLOR_ATTACHMENT7                         GL_COLOR_ATTACHMENT7
#define GU_COLOR_ATTACHMENT8                         GL_COLOR_ATTACHMENT8
#define GU_COLOR_ATTACHMENT9                         GL_COLOR_ATTACHMENT9
#define GU_COLOR_ATTACHMENT10                        GL_COLOR_ATTACHMENT10
#define GU_COLOR_ATTACHMENT11                        GL_COLOR_ATTACHMENT11
#define GU_COLOR_ATTACHMENT12                        GL_COLOR_ATTACHMENT12
#define GU_COLOR_ATTACHMENT13                        GL_COLOR_ATTACHMENT13
#define GU_COLOR_ATTACHMENT14                        GL_COLOR_ATTACHMENT14
#define GU_COLOR_ATTACHMENT15                        GL_COLOR_ATTACHMENT15
#define GU_DEPTH_ATTACHMENT                          GL_DEPTH_ATTACHMENT
#define GU_STENCIL_ATTACHMENT                        GL_STENCIL_ATTACHMENT
#define GU_FRAMEBUFFER_COMPLETE                      GL_FRAMEBUFFER_COMPLETE
#define GU_FRAMEBUFFER_INCOMPLETE_ATTACHMENT         GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
#define GU_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
#define GU_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER        GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER
#define GU_FRAMEBUFFER_INCOMPLETE_READ_BUFFER        GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER
#define GU_FRAMEBUFFER_UNSUPPORTED                   GL_FRAMEBUFFER_UNSUPPORTED

//BUFFER
#define GU_ARRAY_BUFFER                              GL_ARRAY_BUFFER
#define GU_ATOMIC_COUNTER_BUFFER                     GL_ATOMIC_COUNTER_BUFFER
#define GU_COPY_READ_BUFFER                          GL_COPY_READ_BUFFER
#define GU_COPY_WRITE_BUFFER                         GL_COPY_WRITE_BUFFER
#define GU_DISPATCH_INDIRECT_BUFFER                  GL_DISPATCH_INDIRECT_BUFFER
#define GU_DRAW_INDIRECT_BUFFER                      GL_DRAW_INDIRECT_BUFFER
#define GU_ELEMENT_ARRAY_BUFFER                      GL_ELEMENT_ARRAY_BUFFER
#define GU_PIXEL_PACK_BUFFER                         GL_PIXEL_PACK_BUFFER
#define GU_PIXEL_UNPACK_BUFFER                       GL_PIXEL_UNPACK_BUFFER
#define GU_QUERY_BUFFER                              GL_QUERY_BUFFER
#define GU_SHADER_STORAGE_BUFFER                     GL_SHADER_STORAGE_BUFFER
#define GU_TEXTURE_BUFFER                            GL_TEXTURE_BUFFER
#define GU_TRANSFORM_FEEDBACK_BUFFER                 GL_TRANSFORM_FEEDBACK_BUFFER
#define GU_UNIFORM_BUFFER                            GL_UNIFORM_BUFFER

#define GU_STREAM_DRAW                               GL_STREAM_DRAW
#define GU_STREAM_READ                               GL_STREAM_READ
#define GU_STREAM_COPY                               GL_STREAM_COPY
#define GU_STATIC_DRAW                               GL_STATIC_DRAW
#define GU_STATIC_READ                               GL_STATIC_READ
#define GU_STATIC_COPY                               GL_STATIC_COPY
#define GU_DYNAMIC_DRAW                              GL_DYNAMIC_DRAW
#define GU_DYNAMIC_READ                              GL_DYNAMIC_READ
#define GU_DYNAMIC_COPY                              GL_DYNAMIC_COPY

#define GU_STENCIL_INDEX                             GL_STENCIL_INDEX
#define GU_DEPTH_COMPONENT                           GL_DEPTH_COMPONENT
#define GU_DEPTH_STENCIL                             GL_DEPTH_STENCIL
#define GU_RED                                       GL_RED
#define GU_GREEN                                     GL_GREEN
#define GU_BLUE                                      GL_BLUE
#define GU_RG                                        GL_RG
#define GU_RGB                                       GL_RGB
#define GU_RGBA                                      GL_RGBA
#define GU_BGR                                       GL_BGR
#define GU_BGRA                                      GL_BGRA

#define GU_COLOR_ARRAY                               GL_COLOR_ARRAY
#define GU_EDGE_FLAG_ARRAY                           GL_EDGE_FLAG_ARRAY
#define GU_FOG_COORD_ARRAY                           GL_FOG_COORD_ARRAY
#define GU_INDEX_ARRAY                               GL_INDEX_ARRAY
#define GU_NORMAL_ARRAY                              GL_NORMAL_ARRAY
#define GU_SECONDARY_COLOR_ARRAY                     GL_SECONDARY_COLOR_ARRAY
#define GU_TEXTURE_COORD_ARRAY                       GL_TEXTURE_COORD_ARRAY
#define GU_VERTEX_ARRAY                              GL_VERTEX_ARRAY

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
    static bool guShaderInitiated();

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

    //BUFFERS
    /* type
    GU_ARRAY_BUFFER
    GU_ATOMIC_COUNTER_BUFFER
    GU_COPY_READ_BUFFER
    GU_COPY_WRITE_BUFFER
    GU_DISPATCH_INDIRECT_BUFFER
    GU_DRAW_INDIRECT_BUFFER
    GU_ELEMENT_ARRAY_BUFFER
    GU_PIXEL_PACK_BUFFER
    GU_PIXEL_UNPACK_BUFFER
    GU_QUERY_BUFFER
    GU_SHADER_STORAGE_BUFFER
    GU_TEXTURE_BUFFER
    GU_TRANSFORM_FEEDBACK_BUFFER
    GU_UNIFORM_BUFFER
*/
    //alloc Buffer
    static edk::uint32 guAllocBuffer(edk::uint32 type);
    /* type
    GU_ARRAY_BUFFER
    GU_ATOMIC_COUNTER_BUFFER
    GU_COPY_READ_BUFFER
    GU_COPY_WRITE_BUFFER
    GU_DISPATCH_INDIRECT_BUFFER
    GU_DRAW_INDIRECT_BUFFER
    GU_ELEMENT_ARRAY_BUFFER
    GU_PIXEL_PACK_BUFFER
    GU_PIXEL_UNPACK_BUFFER
    GU_QUERY_BUFFER
    GU_SHADER_STORAGE_BUFFER
    GU_TEXTURE_BUFFER
    GU_TRANSFORM_FEEDBACK_BUFFER
    GU_UNIFORM_BUFFER
*/
    //use Buffer
    static void guUseBuffer(edk::uint32 type,edk::uint32 ID);
    /* type
    GU_ARRAY_BUFFER
    GU_ATOMIC_COUNTER_BUFFER
    GU_COPY_READ_BUFFER
    GU_COPY_WRITE_BUFFER
    GU_DISPATCH_INDIRECT_BUFFER
    GU_DRAW_INDIRECT_BUFFER
    GU_ELEMENT_ARRAY_BUFFER
    GU_PIXEL_PACK_BUFFER
    GU_PIXEL_UNPACK_BUFFER
    GU_QUERY_BUFFER
    GU_SHADER_STORAGE_BUFFER
    GU_TEXTURE_BUFFER
    GU_TRANSFORM_FEEDBACK_BUFFER
    GU_UNIFORM_BUFFER
*/
    //do not use Buffer
    static void guDontUseBuffer(edk::uint32 type);
    static void guDontUseAllBuffer();
    //delete the Buffer
    static void guDeleteBuffer(edk::uint32 ID);
    /* type
    GU_ARRAY_BUFFER
    GU_ATOMIC_COUNTER_BUFFER
    GU_COPY_READ_BUFFER
    GU_COPY_WRITE_BUFFER
    GU_DISPATCH_INDIRECT_BUFFER
    GU_DRAW_INDIRECT_BUFFER
    GU_ELEMENT_ARRAY_BUFFER
    GU_PIXEL_PACK_BUFFER
    GU_PIXEL_UNPACK_BUFFER
    GU_QUERY_BUFFER
    GU_SHADER_STORAGE_BUFFER
    GU_TEXTURE_BUFFER
    GU_TRANSFORM_FEEDBACK_BUFFER
    GU_UNIFORM_BUFFER
*/

    /*
    GU_STREAM_DRAW
    GU_STREAM_READ
    GU_STREAM_COPY
    GU_STATIC_DRAW
    GU_STATIC_READ
    GU_STATIC_COPY
    GU_DYNAMIC_DRAW
    GU_DYNAMIC_READ
    GU_DYNAMIC_COPY
*/
    //add the buffer in to the vbo
    static bool guBufferData(edk::uint32 type, edk::uint64 size, const edk::classID data, edk::uint32 usage);
    /*
    GU_COLOR_ARRAY
    GU_EDGE_FLAG_ARRAY
    GU_FOG_COORD_ARRAY
    GU_INDEX_ARRAY
    GU_NORMAL_ARRAY
    GU_SECONDARY_COLOR_ARRAY
    GU_TEXTURE_COORD_ARRAY
    GU_VERTEX_ARRAY
*/
    //enable the state
    static void guEnableClientState(edk::uint32 cap);
    /*
    GU_COLOR_ARRAY
    GU_EDGE_FLAG_ARRAY
    GU_FOG_COORD_ARRAY
    GU_INDEX_ARRAY
    GU_NORMAL_ARRAY
    GU_SECONDARY_COLOR_ARRAY
    GU_TEXTURE_COORD_ARRAY
    GU_VERTEX_ARRAY
*/
    //disable the state
    static void guDisableClientState(edk::uint32 cap);

    //Use a TextCoord from a pointer
    static void guTexCoordPointer1i16(edk::uint64 position);
    static void guTexCoordPointer2i16(edk::uint64 position);
    static void guTexCoordPointer3i16(edk::uint64 position);
    static void guTexCoordPointer4i16(edk::uint64 position);
    static void guTexCoordPointer1i32(edk::uint64 position);
    static void guTexCoordPointer2i32(edk::uint64 position);
    static void guTexCoordPointer3i32(edk::uint64 position);
    static void guTexCoordPointer4i32(edk::uint64 position);
    static void guTexCoordPointer1f32(edk::uint64 position);
    static void guTexCoordPointer2f32(edk::uint64 position);
    static void guTexCoordPointer3f32(edk::uint64 position);
    static void guTexCoordPointer4f32(edk::uint64 position);
    static void guTexCoordPointer1f64(edk::uint64 position);
    static void guTexCoordPointer2f64(edk::uint64 position);
    static void guTexCoordPointer3f64(edk::uint64 position);
    static void guTexCoordPointer4f64(edk::uint64 position);

    static void guColorPointer3ui8(edk::uint64 position);
    static void guColorPointer4ui8(edk::uint64 position);
    static void guColorPointer3i8(edk::uint64 position);
    static void guColorPointer4i8(edk::uint64 position);
    static void guColorPointer3ui16(edk::uint64 position);
    static void guColorPointer4ui16(edk::uint64 position);
    static void guColorPointer3i16(edk::uint64 position);
    static void guColorPointer4i16(edk::uint64 position);
    static void guColorPointer3ui32(edk::uint64 position);
    static void guColorPointer4ui32(edk::uint64 position);
    static void guColorPointer3i32(edk::uint64 position);
    static void guColorPointer4i32(edk::uint64 position);
    static void guColorPointer3f32(edk::uint64 position);
    static void guColorPointer4f32(edk::uint64 position);
    static void guColorPointer3f64(edk::uint64 position);
    static void guColorPointer4f64(edk::uint64 position);

    //use a Normal from a pointer
    static void guNormalPointerI8(edk::uint64 position);
    static void guNormalPointerI16(edk::uint64 position);
    static void guNormalPointerI32(edk::uint64 position);
    static void guNormalPointerF32(edk::uint64 position);
    static void guNormalPointerF64(edk::uint64 position);

    //use a vertex from a pointer
    static void guVertexPointer2i16(edk::uint64 position);
    static void guVertexPointer2i32(edk::uint64 position);
    static void guVertexPointer2f32(edk::uint64 position);
    static void guVertexPointer2f64(edk::uint64 position);
    static void guVertexPointer3i16(edk::uint64 position);
    static void guVertexPointer3i32(edk::uint64 position);
    static void guVertexPointer3f32(edk::uint64 position);
    static void guVertexPointer3f64(edk::uint64 position);
    static void guVertexPointer4i16(edk::uint64 position);
    static void guVertexPointer4i32(edk::uint64 position);
    static void guVertexPointer4f32(edk::uint64 position);
    static void guVertexPointer4f64(edk::uint64 position);

    /*
    //mode
    GU_POINTS
    GU_LINE_STRIP
    GU_LINE_LOOP
    GU_LINES
    GU_LINE_STRIP_ADJACENCY
    GU_LINES_ADJACENCY
    GU_TRIANGLE_STRIP
    GU_TRIANGLE_FAN
    GU_TRIANGLES
    GU_TRIANGLE_STRIP_ADJACENCY
    GU_TRIANGLES_ADJACENCY
    GU_PATCHES
*/
    //draw the array from a pointer
    static void guDrawArrays(edk::uint32 mode,edk::int32 first,edk::uint64 count);

    //Check Buffer
    //static edk::uint32 guCheckBufferStatus(edk::uint32 type);
    //static bool guCheckBufferOK(edk::uint32 type);

    //FRAMEBUFFERS
    /*
    GU_FRAMEBUFFER
    GU_DRAW_FRAMEBUFFER
    GU_READ_FRAMEBUFFER
*/
    //alloc frameBuffer
    static edk::uint32 guAllocFrameBuffer(edk::uint32 type);
    //use FrameBuffer
    static void guUseFrameBuffer(edk::uint32 type,edk::uint32 ID);
    //do not use FrameBuffer
    static void guDontUseFrameBuffer(edk::uint32 type);
    static void guDontUseAllFrameBuffer();
    //delete the frameBuffer
    static void guDeleteFrameBuffer(edk::uint32 ID);
    //use the frameBuffer to the texture
    static void guFrameBufferTexture(edk::uint32 target, edk::uint32 attachment, edk::uint32 texture, edk::uint32 mipmapLevel);
    //Set list of drawBuffers
    static bool guSetDrawBuffers(edk::uint32 size,const edk::uint32 *buffers);
    //set one drawBuffer
    static bool guSetDrawBuffer(edk::uint32 buffer);
    //Check frameBuffer
    static edk::uint32 guCheckFrameBufferStatus(edk::uint32 target);
    static bool guCheckFrameBufferOK(edk::uint32 target);

    //RENDERBUFFERS
    //alloc renderBuffer
    static edk::uint32 guAllocRenderBuffer();
    //use RenderBuffer
    static void guUseRenderBuffer(edk::uint32 ID);
    //do not use RenderBuffer
    static void guDontUseRenderBuffer();
    //delete the RenderBuffer
    static void guDeleteRenderBuffer(edk::uint32 ID);
    //use the RenderBuffer to the texture
    //static void guRenderBufferTexture(edk::uint32 type, edk::uint32 attachment, edk::uint32 texture, edk::uint32 mipmapLevel);
    //Check RenderBuffer
    //static edk::uint32 guCheckRenderbufferStatus(edk::uint32 type);
    //static bool guCheckRenderBufferOK(edk::uint32 type);

    //STRING
    //GL_SHADING_LANGUAGE_VERSION
    //Returns a version or release number for the shading language of the form
    static edk::char8* guGetVersion();

#if defined(_WIN32) || defined(_WIN64)
    //Windows
    static edk::multi::MutexDisable mut;
#endif
#ifdef __linux__
    //LINUX
    static edk::multi::Mutex mut;
#endif
    static edk::multi::Mutex mutBeginEnd;

private:
    static bool initiate;
};
}//end namespace edk

#endif // GU_GLSL_H
