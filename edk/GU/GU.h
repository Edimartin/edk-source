#ifndef EDK_GU_H
#define EDK_GU_H

/*
Library GU - Graphic Unit to draw polygons in the video board
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
#pragma message "Inside GU"
#endif

#pragma once
//include the SHD before GU
#include "../GU/GU_GLSL.h"

#if defined(_WIN32) || defined(_WIN64) || defined(__linux__)
#include <GL/gl.h>
#include <GL/glu.h>
#elif defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
//#include <X11/X.h>
//#include <X11/keysym.h>
#endif

#include "../TypeVars.h"
#include "../TypeVec2.h"
#include "../TypeVec3.h"
#include "../TypeColor.h"
#include "../TypeRect.h"
#include "../TypeSize2.h"
#include "../TypeSize3.h"

#include <stdlib.h>

#ifdef printMessages
#pragma message "    Compiling GU"
#endif

/*LIBS WINDOWS

-lgl
-lglu
-lglew

*/

/*LIBS LINUX

-lGL
-lGLU
-lGLEW

*/

/*LIBS MAC

-framework OpenGL
-framework CocoamodelViewProjMatrixLoc

*/

//
//DEFINES GU
#define GU_FALSE                                GL_FALSE
#define GU_TRUE                                 GL_TRUE
#define GU_MODELVIEW                            GL_MODELVIEW
#define GU_PROJECTION                           GL_PROJECTION
#define GU_TEXTURE                              GL_TEXTURE
//#define GU_RGB                                GL_RGB
//#define GU_RGBA                               GL_RGBA
#define GU_LUMINANCE                            GL_LUMINANCE
#define GU_LUMINANCE_ALPHA                      GL_LUMINANCE_ALPHA

#define GU_COLOR_BUFFER_BIT                     GL_COLOR_BUFFER_BIT
#define GU_DEPTH_BUFFER_BIT                     GL_DEPTH_BUFFER_BIT
#define GU_ACCUM_BUFFER_BIT                     GL_ACCUM_BUFFER_BIT
#define GU_STENCIL_BUFFER_BIT                   GL_STENCIL_BUFFER_BIT
#define GU_CULL_FACE                            GL_CULL_FACE

// Blending
#define GU_BLEND                                GL_BLEND
#define GU_ZERO                                 GL_ZERO
#define GU_ONE                                  GL_ONE
#define GU_SRC_COLOR                            GL_SRC_COLOR
#define GU_ONE_MINUS_SRC_COLOR                  GL_ONE_MINUS_SRC_COLOR
#define GU_SRC_ALPHA                            GL_SRC_ALPHA
#define GU_ONE_MINUS_SRC_ALPHA                  GL_ONE_MINUS_SRC_ALPHA
#define GU_DST_ALPHA                            GL_DST_ALPHA
#define GU_ONE_MINUS_DST_ALPHA                  GL_ONE_MINUS_DST_ALPHA
#define GU_DST_COLOR                            GL_DST_COLOR
#define GU_ONE_MINUS_DST_COLOR                  GL_ONE_MINUS_DST_COLOR
#define GU_SRC_ALPHA_SATURATE                   GL_SRC_ALPHA_SATURATE
#define GU_CONSTANT_COLOR                       GL_CONSTANT_COLOR
#define GU_ONE_MINUS_CONSTANT_COLOR             GL_ONE_MINUS_CONSTANT_COLOR
#define GU_CONSTANT_ALPHA                       GL_CONSTANT_ALPHA
#define GU_ONE_MINUS_CONSTANT_ALPHA             GL_ONE_MINUS_CONSTANT_ALPHA

// Primitives
#define GU_POINTS                               GL_POINTS
#define GU_LINES                                GL_LINES
#define GU_LINE_STRIP_ADJACENCY                 GL_LINE_STRIP_ADJACENCY
#define GU_LINES_ADJACENCY                      GL_LINES_ADJACENCY
#define GU_LINE_LOOP                            GL_LINE_LOOP
#define GU_LINE_STRIP                           GL_LINE_STRIP
#define GU_TRIANGLES                            GL_TRIANGLES
#define GU_TRIANGLE_STRIP_ADJACENCY             GL_TRIANGLE_STRIP_ADJACENCY
#define GU_TRIANGLES_ADJACENCY                  GL_TRIANGLES_ADJACENCY
#define GU_PATCHES                              GL_PATCHES
#define GU_TRIANGLE_STRIP                       GL_TRIANGLE_STRIP
#define GU_TRIANGLE_FAN                         GL_TRIANGLE_FAN
#define GU_QUADS                                GL_QUADS
#define GU_QUAD_STRIP                           GL_QUAD_STRIP
#define GU_POLYGON                              GL_POLYGON

// Depth buffer
#define GU_NEVER                                GL_NEVER
#define GU_LESS                                 GL_LESS
#define GU_EQUAL                                GL_EQUAL
#define GU_LEQUAL                               GL_LEQUAL
#define GU_GREATER                              GL_GREATER
#define GU_NOTEQUAL                             GL_NOTEQUAL
#define GU_GEQUAL                               GL_GEQUAL
#define GU_ALWAYS                               GL_ALWAYS
#define GU_DEPTH_TEST                           GL_DEPTH_TEST

// Lighting
#define GU_LIGHTING                             GL_LIGHTING
#define GU_LIGHT0                               GL_LIGHT0
#define GU_LIGHT1                               GL_LIGHT1
#define GU_LIGHT2                               GL_LIGHT2
#define GU_LIGHT3                               GL_LIGHT3
#define GU_LIGHT4                               GL_LIGHT4
#define GU_LIGHT5                               GL_LIGHT5
#define GU_LIGHT6                               GL_LIGHT6
#define GU_LIGHT7                               GL_LIGHT7
#define GU_AMBIENT                              GL_AMBIENT
#define GU_DIFFUSE                              GL_DIFFUSE
#define GU_SPECULAR                             GL_SPECULAR
#define GU_POSITION                             GL_POSITION
#define GU_SPOT_DIRECTION                       GL_SPOT_DIRECTION
#define GU_SPOT_EXPONENT                        GL_SPOT_EXPONENT
#define GU_SPOT_CUTOFF                          GL_SPOT_CUTOFF
#define GU_CONSTANT_ATTENUATION                 GL_CONSTANT_ATTENUATION
#define GU_LINEAR_ATTENUATION                   GL_LINEAR_ATTENUATION
#define GU_QUADRATIC_ATTENUATION                GL_QUADRATIC_ATTENUATION
#define GU_SHADE_MODEL                          GL_SHADE_MODEL
#define GU_FLAT                                 GL_FLAT
#define GU_SMOOTH                               GL_SMOOTH
#define GU_COLOR_MATERIAL                       GL_COLOR_MATERIAL
#define GU_COLOR_MATERIAL_FACE                  GL_COLOR_MATERIAL_FACE
#define GU_COLOR_MATERIAL_PARAMETER             GL_COLOR_MATERIAL_PARAMETER
#define GU_FRONT                                GL_FRONT
#define GU_BACK                                 GL_BACK
#define GU_FRONT_AND_BACK                       GL_FRONT_AND_BACK
#define GU_SHININESS                            GL_SHININESS
#define GU_EMISSION                             GL_EMISSION
#define GU_AMBIENT_AND_DIFFUSE                  GL_AMBIENT_AND_DIFFUSE

// Render
#define GU_FEEDBACK                             GL_FEEDBACK
#define GU_RENDER                               GL_RENDER
#define GU_SELECT                               GL_SELECT

// Texture mapping
#define GU_TEXTURE_1D                           GL_TEXTURE_1D
#define GU_TEXTURE_2D                           GL_TEXTURE_2D
#define GU_TEXTURE_3D                           GL_TEXTURE_3D
#define GU_TEXTURE_ENV_COLOR                    GL_TEXTURE_ENV_COLOR
#define GU_TEXTURE_BORDER_COLOR                 GL_TEXTURE_BORDER_COLOR
#define GU_TEXTURE_WIDTH                        GL_TEXTURE_WIDTH
#define GU_TEXTURE_HEIGHT                       GL_TEXTURE_HEIGHT
#define GU_TEXTURE_BORDER                       GL_TEXTURE_BORDER
#define GU_TEXTURE_RED_SIZE                     GL_TEXTURE_RED_SIZE
#define GU_TEXTURE_GREEN_SIZE                   GL_TEXTURE_GREEN_SIZE
#define GU_TEXTURE_BLUE_SIZE                    GL_TEXTURE_BLUE_SIZE
#define GU_TEXTURE_ALPHA_SIZE                   GL_TEXTURE_ALPHA_SIZE
#define GU_TEXTURE_LUMINANCE_SIZE               GL_TEXTURE_LUMINANCE_SIZE
#define GU_TEXTURE_INTENSITY_SIZE               GL_TEXTURE_INTENSITY_SIZE
#define GU_NEAREST_MIPMAP_NEAREST               GL_NEAREST_MIPMAP_NEAREST
#define GU_NEAREST_MIPMAP_LINEAR                GL_NEAREST_MIPMAP_LINEAR
#define GU_LINEAR_MIPMAP_NEAREST                GL_LINEAR_MIPMAP_NEAREST
#define GU_LINEAR_MIPMAP_LINEAR                 GL_LINEAR_MIPMAP_LINEAR
//TEXTURE FILTER
#define GU_NEAREST                              GL_NEAREST
#define GU_LINEAR                               GL_LINEAR

#define GU_REPEAT                               GL_REPEAT
#define GU_CLAMP                                GL_CLAMP

//library
namespace edk{
class GU{
public:
    //construtor
    GU();

    //destrutor
    ~GU();

    static void setCantLoadTextures();
    static void setCanLoadTextures();

    //print the ID
    static void guPrintID(edk::uint32 cap);

    //init the GU
    static void guOpen();
    static void guClose();

    //Color
    static void guColor3f32(edk::color3f32 color);
    static void guColor3f64(edk::color3f64 color);
    static void guColor3f32(edk::float32 r,edk::float32 g,edk::float32 b);
    static void guColor3f64(edk::float64 r,edk::float64 g,edk::float64 b);
    static void guColor4f32(edk::color4f32 color);
    static void guColor4f64(edk::color4f64 color);
    static void guColor4f32(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    static void guColor4f64(edk::float64 r,edk::float64 g,edk::float64 b,edk::float64 a);

    //clear dome buffer
    //mask
    //GU_COLOR_BUFFER_BIT
    //GU_DEPTH_BUFFER_BIT
    //GU_ACCUM_BUFFER_BIT
    //GU_STENCIL_BUFFER_BIT
    static void guClear( edk::uint32 mask );

    //return the openGL matrix are using
    //mode
    //GU_MODELVIEW
    //GU_PROJECTION
    //GU_TEXTURE
    static bool guUsingMatrix(edk::uint32 mode);

    //set the usingMatrix
    //mode
    //GU_MODELVIEW
    //GU_PROJECTION
    //GU_TEXTURE
    static void guUseMatrix(edk::uint32 mode);

    //load the identity matrix
    static void guLoadIdentity();

    //Push Matrix
    static void guPushMatrix();
    static void guPopMatrix();

    //setViewport
    static void guSetViewport(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height);
    static void guSetViewportRect(edk::rectui32 rect);

    //setThe camera
    static void guLookAt(edk::float64 eyeX, edk::float64 eyeY, edk::float64 eyeZ, edk::float64 centerX, edk::float64 centerY, edk::float64 centerZ, edk::float64 upX, edk::float64 upY, edk::float64 upZ);
    static void guLookAt(edk::float32 eyeX, edk::float32 eyeY, edk::float32 eyeZ, edk::float32 centerX, edk::float32 centerY, edk::float32 centerZ, edk::float32 upX, edk::float32 upY, edk::float32 upZ);
    static void guUseOrtho(edk::float32 left, edk::float32 right, edk::float32 botton, edk::float32 top, edk::float32 near, edk::float32 far);
    static void guUsePerspective(edk::float32 fovy, edk::float32 aspect, edk::float32 near, edk::float32 far);

    //create a texture
    //mode
    //GU_RGB
    //GU_RGBA
    //GU_LUMINANCE
    //GU_LUMINANCE_ALPHA
    //filter
    //GU_NEAREST
    //GU_LINEAR
    //GU_NEAREST_MIPMAP_NEAREST
    //GU_NEAREST_MIPMAP_LINEAR
    //GU_LINEAR_MIPMAP_NEAREST
    //GU_LINEAR_MIPMAP_LINEAR
    static edk::uint32 guAllocTexture2D(edk::uint32 width, edk::uint32 height, edk::uint32 mode, edk::uint32 filter, const edk::classID  data);
    //Draw to texture
    //mode
    //GU_RGB
    //GU_RGBA
    //GU_LUMINANCE
    //GU_LUMINANCE_ALPHA
    //filter
    //GU_NEAREST
    //GU_LINEAR
    static bool guDrawToTexture(edk::uint32 ID,edk::uint32 width, edk::uint32 height, edk::uint32 mode, edk::uint32 filter, const edk::classID  data);
    //delete texture
    static void guDeleteTexture(edk::uint32 ID);

    //BLEND
    static void guBlendFunc( edk::uint32 sfactor, edk::uint32 dfactor );

    //ENABLE_DISABLE
    static void guEnable( edk::uint32 cap );
    static void guDisable( edk::uint32 cap );
    //disable all lights
    static void guDisableAllLights();

    //TRANSFORMATIONS
    //rotation
    static void guRotate3f32( edk::float32 angle, edk::vec3f32 vec);
    static void guRotate3f32( edk::float32 angle, edk::float32 x, edk::float32 y, edk::float32 z );
    static void guRotate3f64( edk::float64 angle, edk::vec3f64 vec);
    static void guRotate3f64( edk::float64 angle, edk::float64 x, edk::float64 y, edk::float64 z );
    static void guRotateXf32(edk::float32 angle);
    static void guRotateXf64(edk::float64 angle);
    static void guRotateYf32(edk::float32 angle);
    static void guRotateYf64(edk::float64 angle);
    static void guRotateZf32(edk::float32 angle);
    static void guRotateZf64(edk::float64 angle);
    //scale
    static void guScale3f32( edk::size3f32 size );
    static void guScale3f32( edk::float32 x, edk::float32 y, edk::float32 z );
    static void guScale3f64( edk::size3f64 size );
    static void guScale3f64( edk::float64 x, edk::float64 y, edk::float64 z );
    static void guScale2f32( edk::size2f32 size );
    static void guScale2f32( edk::float32 x, edk::float32 y);
    static void guScale2f64( edk::size2f64 size );
    static void guScale2f64( edk::float64 x, edk::float64 y);
    static void guScaleXf32( edk::float64 x);
    static void guScaleXf64( edk::float64 x);
    static void guScaleYf32( edk::float64 y);
    static void guScaleYf64( edk::float64 y);
    static void guScaleZf32( edk::float64 z);
    static void guScaleZf64( edk::float64 z);
    //translate
    static void guTranslate3f32( edk::vec3f32 vec);
    static void guTranslate3f32( edk::float32 x, edk::float32 y, edk::float32 z );
    static void guTranslate3f64( edk::vec3f64 vec);
    static void guTranslate3f64( edk::float64 x, edk::float64 y, edk::float64 z );
    static void guTranslate2f32( edk::vec2f32 vec);
    static void guTranslate2f32( edk::float32 x, edk::float32 y );
    static void guTranslate2f64( edk::vec2f64 vec);
    static void guTranslate2f64( edk::float64 x, edk::float64 y );
    static void guTranslateXf32( edk::float32 x );
    static void guTranslateXf64( edk::float64 x );
    static void guTranslateYf32( edk::float32 y );
    static void guTranslateYf64( edk::float64 y );
    static void guTranslateZf32( edk::float32 z );
    static void guTranslateZf64( edk::float64 z );

    //SIZES
    static void guPointSize(edk::float32 size);
    static void guPointSize(edk::float64 size);
    static void guPointSize(edk::int8 size);
    static void guPointSize(edk::int16 size);
    static void guPointSize(edk::int32 size);
    static void guPointSize(edk::int64 size);
    static void guPointSize(edk::uint8 size);
    static void guPointSize(edk::uint16 size);
    static void guPointSize(edk::uint32 size);
    static void guPointSize(edk::uint64 size);
    static void guLineWidth(edk::float32 size);
    static void guLineWidth(edk::float64 size);
    static void guLineWidth(edk::int8 size);
    static void guLineWidth(edk::int16 size);
    static void guLineWidth(edk::int32 size);
    static void guLineWidth(edk::int64 size);
    static void guLineWidth(edk::uint8 size);
    static void guLineWidth(edk::uint16 size);
    static void guLineWidth(edk::uint32 size);
    static void guLineWidth(edk::uint64 size);
    //DRAW functions
    //mode
    //GU_POINTS
    //GU_LINES
    //GU_LINE_LOOP
    //GU_LINE_STRIP
    //GU_TRIANGLES
    //GU_TRIANGLE_STRIP
    //GU_TRIANGLE_FAN
    //GU_QUADS
    //GU_QUAD_STRIP
    //GU_POLYGON
    static void guBegin(edk::uint32 mode);
    static void guEnd();
    static void guVertex2f32(edk::vec2f32 vec);
    static void guVertex2f64(edk::vec2f64 vec);
    static void guVertex2f32(edk::float32 x,edk::float32 y);
    static void guVertex2f64(edk::float64 x,edk::float64 y);
    static void guVertex3f32(edk::vec3f32 vec);
    static void guVertex3f64(edk::vec3f64 vec);
    static void guVertex3f32(edk::float32 x,edk::float32 y,edk::float32 z);
    static void guVertex3f64(edk::float64 x,edk::float64 y,edk::float64 z);
    static void guVertex4f32(edk::vec4f32 vec);
    static void guVertex4f64(edk::vec4f64 vec);
    static void guVertex4f32(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w);
    static void guVertex4f64(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 w);
    static void guVertexNormal3f32(edk::vec3f32 vec);
    static void guVertexNormal3f64(edk::vec3f64 vec);
    static void guVertexNormal3f32(edk::float32 x,edk::float32 y,edk::float32 z);
    static void guVertexNormal3f64(edk::float64 x,edk::float64 y,edk::float64 z);

    // LIGHTING
    //modeL:
    //GU_FLAT
    //GU_SMOOTH
    static void guShadeModel( edk::uint32 model );
    static void guLightf32( edk::uint32 light, edk::uint32 pname, edk::float32 param );
    static void guLighti32( edk::uint32 light, edk::uint32 pname, edk::int32 param );
    static void guLightfv32( edk::uint32 light, edk::uint32 pname, const edk::float32 *params );
    static void guLightiv32( edk::uint32 light, edk::uint32 pname, const edk::int32 *params );
    static void guGetLightfv32( edk::uint32 light, edk::uint32 pname, edk::float32 *params );
    static void guGetLightiv32( edk::uint32 light, edk::uint32 pname, edk::int32 *params );

    //MATERIAL
    static void guMaterialf32( edk::uint32 face, edk::uint32 pname, edk::float32 param );
    static void guMateriali32( edk::uint32 face, edk::uint32 pname, edk::int32 param );
    static void guMaterialfv32( edk::uint32 face, edk::uint32 pname, const edk::float32 *params );
    static void guMaterialiv32( edk::uint32 face, edk::uint32 pname, const edk::int32 *params );
    static void guGetMaterialfv32( edk::uint32 face, edk::uint32 pname, edk::float32 *params );
    static void guGetMaterialiv32( edk::uint32 face, edk::uint32 pname, edk::int32 *params );
    //face:
    //GU_FRONT
    //GU_BACK
    //GU_FRONT_AND_BACK
    //mode:
    //GU_EMISSION
    //GU_AMBIENT
    //GU_DIFFUSE
    //GU_SPECULAR
    //GU_AMBIENT_AND_DIFFUSE
    static void guColorMaterial( edk::uint32 face, edk::uint32 mode );

    //DEPTH
    static void guDepthFunc(edk::uint32 func);
    static void guDepthRange( edk::float64 near_val, edk::float64 far_val );

    //TEXTURE
    //target
    //GU_TEXTURE_1D
    //GU_TEXTURE_2D
    //GU_TEXTURE_3D
    static void guUseTexture(edk::uint32 target, edk::uint32 texture);
    //select te texture
    static void guUseTexture1D(edk::uint32 texture);
    static void guUseTexture2D(edk::uint32 texture);
    static void guUseTexture3D(edk::uint32 texture);
    static void guVertexTex1f32(edk::float32 n);
    static void guVertexTex1f64(edk::float64 n);
    static void guVertexTex2f32(edk::vec2f32 vec);
    static void guVertexTex2f64(edk::vec2f64 vec);
    static void guVertexTex2f32(edk::float32 x,edk::float32 y);
    static void guVertexTex2f64(edk::float64 x,edk::float64 y);
    static void guVertexTex3f32(edk::vec3f32 vec);
    static void guVertexTex3f64(edk::vec3f64 vec);
    static void guVertexTex3f32(edk::float32 x,edk::float32 y,edk::float32 z);
    static void guVertexTex3f64(edk::float64 x,edk::float64 y,edk::float64 z);
    static void guVertexTex4f32(edk::vec4f32 vec);
    static void guVertexTex4f64(edk::vec4f64 vec);
    static void guVertexTex4f32(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w);
    static void guVertexTex4f64(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 w);

    //cullFace
    static void guCullFace(edk::uint32 mode);

    //SELET BUFFER
    //alloc the buffer
    static bool guSetSelectionBuffer(edk::uint32 size,edk::uint32* vector);
    //Set renderMode
    //mode:
    //GU_RENDER
    //GU_SELECT
    //GU_FEEDBACK
    static edk::int32 guRenderMode( edk::uint32 mode);
    //init the names
    static void guInitNames();
    //push a name
    static void guPushName(edk::uint32 id);
    //load a name
    static void guLoadName(edk::uint32 id);
    //pop some name
    static void guPopName();
    //get the viewport specification
    //set the pickMatrix
    static void guPickMatrix(edk::float64  x,  edk::float64  y,  edk::float64  delX,  edk::float64  delY);

    //STRING
    //GL_VENDOR
    //Returns the company responsible for this GL implementation
    static edk::char8* guGetVendor();
    //GL_RENDERER
    //Returns the name of the renderer
    static edk::char8* guGetRenderer();
    //GL_VERSION
    //Returns a version or release number of the form
    static edk::char8* guGetVersion();
    //GL_EXTENSIONS
    //Returns a space-separated list of supported extensions to GL.
    static edk::char8* guGetExtensions();

    //run function to load the textures from other threads
    static bool guUpdateLoadTextures();

private:
    static edk::uint32 initiate;
    static edk::uint32 ID;
    //threads mut
    static edk::multi::Mutex mutGetTextures;
    //a boolean if can still running load the texture
    static bool canLoadTexture;

    class TextureClass{
    public:
        TextureClass(){this->width=0u; this->height=0u; this->mode=0u; this->filter=0u; this->data=0u;this->threadID = 0u;this->id = 0u;}
        ~TextureClass(){}
        edk::GU::TextureClass operator=(edk::GU::TextureClass tex){
            this->width = tex.width;
            this->height = tex.height;
            this->mode = tex.mode;
            this->filter = tex.filter;
            this->data = tex.data;
            this->threadID = tex.threadID;
            this->id = tex.id;
            return *this;
        }
        inline bool operator==(edk::GU::TextureClass tex){
            return (this->threadID == tex.threadID);
        }
        inline bool operator>(edk::GU::TextureClass tex){
            return (this->threadID > tex.threadID);
        }
        inline bool operator<(edk::GU::TextureClass tex){
            return (this->threadID < tex.threadID);
        }
        edk::uint32 width; edk::uint32 height; edk::uint32 mode; edk::uint32 filter; edk::classID  data;
        edk::uint32 id;
#if __x86_64__ || __ppc64__
        edk::uint64 threadID;
#else
        edk::uint32 threadID;
#endif
    };
    static edk::vector::Queue<edk::GU::TextureClass> genTextures;

    class Texture_Tree : public edk::vector::BinaryTree<edk::GU::TextureClass>{
    public:
        Texture_Tree(){}
        ~Texture_Tree(){}
        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::GU::TextureClass first,edk::GU::TextureClass second){
            if(first.threadID>second.threadID){return true;}
            return false;
        }
        //compare if the value is equal
        virtual bool firstEqualSecond(edk::GU::TextureClass first,edk::GU::TextureClass second){
            if(first.threadID==second.threadID){return true;}
            return false;
        }
        //get a TexureClass by ID
#if __x86_64__ || __ppc64__
        edk::GU::TextureClass getTextureByThread(edk::uint64 threadID){
#else
        edk::GU::TextureClass getTextureByThread(edk::uint32 threadID){
#endif
            edk::GU::TextureClass temp;
            temp.threadID = threadID;
            return this->getElement(temp);
        }
        //return true if have a texture by thread ID
#if __x86_64__ || __ppc64__
        bool haveTextureByThread(edk::uint64 ID){
#else
        bool haveTextureByThread(edk::uint32 ID){
#endif
            edk::GU::TextureClass temp;
            temp.threadID = ID;
            return this->haveElement(temp);
        }
    };
    static edk::GU::Texture_Tree treeTextures;
};
}//end namespace





#endif // GU_H
