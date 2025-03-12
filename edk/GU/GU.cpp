#include "GU.h"

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
#pragma message "            Inside GU.cpp"
#endif

#if defined(__linux__)
class GU_RUN_ENVIROMENT_MESA{
public:
    GU_RUN_ENVIROMENT_MESA(){putenv((edk::char8*)"MESA_HW_ACCEL_SELECT=0");}
}guMesaEnviromentSetter;
#endif

//global variables
//GU_MODELVIEW
//GU_PROJECTION
//GU_TEXTURE
edk::uint32 matrixMode = GU_FALSE;
bool edk::GU::templateConstructNeed=true;
edk::uint32 edk::GU::initiate=0u;
edk::uint32 edk::GU::ID=0u;
edk::vector::Queue<edk::GU::TextureClass> edk::GU::genTextures(50u);
edk::GU::Texture_Tree edk::GU::treeTextures;
edk::multi::Mutex edk::GU::mutGetMipmaps;
edk::vector::Queue<edk::uint32> edk::GU::delTextures;
//threads mut
edk::multi::Mutex edk::GU::mutGetTextures;
edk::multi::Mutex edk::GU::mutDelTextures;
edk::vector::Queue<edk::GU::MipmapClass> edk::GU::genMipmaps;
//a boolean if can still running load the texture
bool edk::GU::canLoadTexture=true;

//construtor
edk::GU::GU(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

//destrutor
edk::GU::~GU(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::GU::Constructor(bool /*runFather*/){
    //
    if(this->classThis!=this){
        this->classThis=this;
        if(edk::GU::templateConstructNeed){
            edk::GU::genTextures.Constructor(50u);
            edk::GU::treeTextures.Constructor();
            edk::GU::mutGetMipmaps.Constructor();
            edk::GU::delTextures.Constructor();
            edk::GU::mutGetTextures.Constructor();
            edk::GU::mutDelTextures.Constructor();
            edk::GU::genMipmaps.Constructor();
            edk::GU::templateConstructNeed=false;
        }
    }
}

void edk::GU::setCantLoadTextures(){
    edk::GU::mutGetTextures.lock();
    edk::GU::canLoadTexture=false;
    edk::GU::mutGetTextures.unlock();
}
void edk::GU::setCanLoadTextures(){
    edk::GU::mutGetTextures.lock();
    edk::GU::canLoadTexture=true;
    edk::GU::mutGetTextures.unlock();
}

//print the ID
void edk::GU::guPrintID(edk::uint32 cap){
    switch(cap){
    case GU_BLEND:
        printf("\nCAP == GU_BLEND");fflush(stdout);
        break;
    case GU_FALSE:
        printf("\nCAP == GU_FALSE");fflush(stdout);
        break;
    case GU_TRUE:
        printf("\nCAP == GU_TRUE ");fflush(stdout);
        break;
    case GU_MODELVIEW:
        printf("\nCAP == GU_MODELVIEW");fflush(stdout);
        break;
    case GU_PROJECTION:
        printf("\nCAP == GU_PROJECTION ");fflush(stdout);
        break;
    case GU_TEXTURE:
        printf("\nCAP == GU_TEXTURE");fflush(stdout);
        break;
    case GU_LUMINANCE:
        printf("\nCAP == GU_LUMINANCE");fflush(stdout);
        break;
    case GU_LUMINANCE_ALPHA:
        printf("\nCAP == GU_LUMINANCE_ALPHA");fflush(stdout);
        break;
    case GU_COLOR_BUFFER_BIT:
        printf("\nCAP == GU_COLOR_BUFFER_BIT ");fflush(stdout);
        break;
    case GU_DEPTH_BUFFER_BIT:
        printf("\nCAP == GU_DEPTH_BUFFER_BIT ");fflush(stdout);
        break;
    case GU_ACCUM_BUFFER_BIT:
        printf("\nCAP == GU_ACCUM_BUFFER_BIT ");fflush(stdout);
        break;
    case GU_STENCIL_BUFFER_BIT:
        printf("\nCAP == GU_STENCIL_BUFFER_BIT ");fflush(stdout);
        break;
    case GU_SRC_COLOR:
        printf("\nCAP == GU_SRC_COLOR");fflush(stdout);
        break;
    case GU_ONE_MINUS_SRC_COLOR:
        printf("\nCAP == GU_ONE_MINUS_SRC_COLOR");fflush(stdout);
        break;
    case GU_SRC_ALPHA:
        printf("\nCAP == GU_SRC_ALPHA");fflush(stdout);
        break;
    case GU_ONE_MINUS_SRC_ALPHA:
        printf("\nCAP == GU_ONE_MINUS_SRC_ALPHA");fflush(stdout);
        break;
    case GU_DST_ALPHA:
        printf("\nCAP == GU_DST_ALPHA");fflush(stdout);
        break;
    case GU_ONE_MINUS_DST_ALPHA:
        printf("\nCAP == GU_ONE_MINUS_DST_ALPHA");fflush(stdout);
        break;
    case GU_DST_COLOR:
        printf("\nCAP == GU_DST_COLOR");fflush(stdout);
        break;
    case GU_ONE_MINUS_DST_COLOR:
        printf("\nCAP == GU_ONE_MINUS_DST_COLOR");fflush(stdout);
        break;
    case GU_SRC_ALPHA_SATURATE:
        printf("\nCAP == GU_SRC_ALPHA_SATURATE ");fflush(stdout);
        break;
    case GU_CONSTANT_COLOR:
        printf("\nCAP == GU_CONSTANT_COLOR ");fflush(stdout);
        break;
    case GU_ONE_MINUS_CONSTANT_COLOR:
        printf("\nCAP == GU_ONE_MINUS_CONSTANT_COLOR ");fflush(stdout);
        break;
    case GU_CONSTANT_ALPHA:
        printf("\nCAP == GU_CONSTANT_ALPHA ");fflush(stdout);
        break;
    case GU_ONE_MINUS_CONSTANT_ALPHA:
        printf("\nCAP == GU_ONE_MINUS_CONSTANT_ALPHA ");fflush(stdout);
        break;
    case GU_LINE_LOOP:
        printf("\nCAP == GU_LINE_LOOP");fflush(stdout);
        break;
    case GU_LINE_STRIP:
        printf("\nCAP == GU_LINE_STRIP ");fflush(stdout);
        break;
    case GU_TRIANGLES:
        printf("\nCAP == GU_TRIANGLES");fflush(stdout);
        break;
    case GU_TRIANGLE_STRIP:
        printf("\nCAP == GU_TRIANGLE_STRIP ");fflush(stdout);
        break;
    case GU_TRIANGLE_FAN:
        printf("\nCAP == GU_TRIANGLE_FAN ");fflush(stdout);
        break;
    case GU_QUADS:
        printf("\nCAP == GU_QUADS");fflush(stdout);
        break;
    case GU_QUAD_STRIP:
        printf("\nCAP == GU_QUAD_STRIP ");fflush(stdout);
        break;
    case GU_POLYGON:
        printf("\nCAP == GU_POLYGON");fflush(stdout);
        break;
    case GU_LESS:
        printf("\nCAP == GU_LESS ");fflush(stdout);
        break;
    case GU_EQUAL:
        printf("\nCAP == GU_EQUAL");fflush(stdout);
        break;
    case GU_LEQUAL:
        printf("\nCAP == GU_LEQUAL ");fflush(stdout);
        break;
    case GU_GREATER:
        printf("\nCAP == GU_GREATER");fflush(stdout);
        break;
    case GU_NOTEQUAL:
        printf("\nCAP == GU_NOTEQUAL ");fflush(stdout);
        break;
    case GU_GEQUAL:
        printf("\nCAP == GU_GEQUAL ");fflush(stdout);
        break;
    case GU_ALWAYS:
        printf("\nCAP == GU_ALWAYS ");fflush(stdout);
        break;
    case GU_DEPTH_TEST:
        printf("\nCAP == GU_DEPTH_TEST ");fflush(stdout);
        break;
    case GU_LIGHTING:
        printf("\nCAP == GU_LIGHTING ");fflush(stdout);
        break;
    case GU_LIGHT1:
        printf("\nCAP == GU_LIGHT1 ");fflush(stdout);
        break;
    case GU_LIGHT2:
        printf("\nCAP == GU_LIGHT2 ");fflush(stdout);
        break;
    case GU_LIGHT3:
        printf("\nCAP == GU_LIGHT3 ");fflush(stdout);
        break;
    case GU_LIGHT4:
        printf("\nCAP == GU_LIGHT4 ");fflush(stdout);
        break;
    case GU_LIGHT5:
        printf("\nCAP == GU_LIGHT5 ");fflush(stdout);
        break;
    case GU_LIGHT6:
        printf("\nCAP == GU_LIGHT6 ");fflush(stdout);
        break;
    case GU_LIGHT7:
        printf("\nCAP == GU_LIGHT7 ");fflush(stdout);
        break;
    case GU_AMBIENT:
        printf("\nCAP == GU_AMBIENT");fflush(stdout);
        break;
    case GU_DIFFUSE:
        printf("\nCAP == GU_DIFFUSE");fflush(stdout);
        break;
    case GU_SPECULAR:
        printf("\nCAP == GU_SPECULAR ");fflush(stdout);
        break;
    case GU_POSITION:
        printf("\nCAP == GU_POSITION ");fflush(stdout);
        break;
    case GU_SPOT_DIRECTION:
        printf("\nCAP == GU_SPOT_DIRECTION ");fflush(stdout);
        break;
    case GU_SPOT_EXPONENT:
        printf("\nCAP == GU_SPOT_EXPONENT");fflush(stdout);
        break;
    case GU_SPOT_CUTOFF:
        printf("\nCAP == GU_SPOT_CUTOFF");fflush(stdout);
        break;
    case GU_CONSTANT_ATTENUATION:
        printf("\nCAP == GU_CONSTANT_ATTENUATION ");fflush(stdout);
        break;
    case GU_LINEAR_ATTENUATION:
        printf("\nCAP == GU_LINEAR_ATTENUATION ");fflush(stdout);
        break;
    case GU_QUADRATIC_ATTENUATION:
        printf("\nCAP == GU_QUADRATIC_ATTENUATION");fflush(stdout);
        break;
    case GU_SHADE_MODEL:
        printf("\nCAP == GU_SHADE_MODEL");fflush(stdout);
        break;
    case GU_FLAT:
        printf("\nCAP == GU_FLAT ");fflush(stdout);
        break;
    case GU_SMOOTH:
        printf("\nCAP == GU_SMOOTH ");fflush(stdout);
        break;
    case GU_COLOR_MATERIAL:
        printf("\nCAP == GU_COLOR_MATERIAL ");fflush(stdout);
        break;
    case GU_COLOR_MATERIAL_FACE:
        printf("\nCAP == GU_COLOR_MATERIAL_FACE");fflush(stdout);
        break;
    case GU_COLOR_MATERIAL_PARAMETER:
        printf("\nCAP == GU_COLOR_MATERIAL_PARAMETER ");fflush(stdout);
        break;
    case GU_FRONT:
        printf("\nCAP == GU_FRONT");fflush(stdout);
        break;
    case GU_BACK:
        printf("\nCAP == GU_BACK ");fflush(stdout);
        break;
    case GU_FRONT_AND_BACK:
        printf("\nCAP == GU_FRONT_AND_BACK ");fflush(stdout);
        break;
    case GU_SHININESS:
        printf("\nCAP == GU_SHININESS");fflush(stdout);
        break;
    case GU_EMISSION:
        printf("\nCAP == GU_EMISSION ");fflush(stdout);
        break;
    case GU_AMBIENT_AND_DIFFUSE:
        printf("\nCAP == GU_AMBIENT_AND_DIFFUSE");fflush(stdout);
        break;
    case GU_FEEDBACK:
        printf("\nCAP == GU_FEEDBACK ");fflush(stdout);
        break;
    case GU_RENDER:
        printf("\nCAP == GU_RENDER ");fflush(stdout);
        break;
    case GU_SELECT:
        printf("\nCAP == GU_SELECT ");fflush(stdout);
        break;
    case GU_TEXTURE_1D:
        printf("\nCAP == GU_TEXTURE_1D ");fflush(stdout);
        break;
    case GU_TEXTURE_2D:
        printf("\nCAP == GU_TEXTURE_2D ");fflush(stdout);
        break;
    case GU_TEXTURE_3D:
        printf("\nCAP == GU_TEXTURE_3D ");fflush(stdout);
        break;
    case GU_TEXTURE_ENV_COLOR:
        printf("\nCAP == GU_TEXTURE_ENV_COLOR");fflush(stdout);
        break;
    case GU_TEXTURE_BORDER_COLOR:
        printf("\nCAP == GU_TEXTURE_BORDER_COLOR ");fflush(stdout);
        break;
    case GU_TEXTURE_WIDTH:
        printf("\nCAP == GU_TEXTURE_WIDTH");fflush(stdout);
        break;
    case GU_TEXTURE_HEIGHT:
        printf("\nCAP == GU_TEXTURE_HEIGHT ");fflush(stdout);
        break;
    case GU_TEXTURE_BORDER:
        printf("\nCAP == GU_TEXTURE_BORDER ");fflush(stdout);
        break;
    case GU_TEXTURE_RED_SIZE:
        printf("\nCAP == GU_TEXTURE_RED_SIZE ");fflush(stdout);
        break;
    case GU_TEXTURE_GREEN_SIZE:
        printf("\nCAP == GU_TEXTURE_GREEN_SIZE ");fflush(stdout);
        break;
    case GU_TEXTURE_BLUE_SIZE:
        printf("\nCAP == GU_TEXTURE_BLUE_SIZE");fflush(stdout);
        break;
    case GU_TEXTURE_ALPHA_SIZE:
        printf("\nCAP == GU_TEXTURE_ALPHA_SIZE ");fflush(stdout);
        break;
    case GU_TEXTURE_LUMINANCE_SIZE:
        printf("\nCAP == GU_TEXTURE_LUMINANCE_SIZE ");fflush(stdout);
        break;
    case GU_TEXTURE_INTENSITY_SIZE:
        printf("\nCAP == GU_TEXTURE_INTENSITY_SIZE ");fflush(stdout);
        break;
    case GU_NEAREST_MIPMAP_NEAREST:
        printf("\nCAP == GU_NEAREST_MIPMAP_NEAREST ");fflush(stdout);
        break;
    case GU_NEAREST_MIPMAP_LINEAR:
        printf("\nCAP == GU_NEAREST_MIPMAP_LINEAR");fflush(stdout);
        break;
    case GU_LINEAR_MIPMAP_NEAREST:
        printf("\nCAP == GU_LINEAR_MIPMAP_NEAREST");fflush(stdout);
        break;
    case GU_LINEAR_MIPMAP_LINEAR:
        printf("\nCAP == GU_LINEAR_MIPMAP_LINEAR ");fflush(stdout);
        break;
    case GU_NEAREST:
        printf("\nCAP == GU_NEAREST");fflush(stdout);
        break;
    case GU_LINEAR:
        printf("\nCAP == GU_LINEAR ");fflush(stdout);
        break;
    case GU_REPEAT:
        printf("\nCAP == GU_REPEAT ");fflush(stdout);
        break;
    case GU_CLAMP:
        printf("\nCAP == GU_CLAMP");fflush(stdout);
        break;
    }
}

//init the GU
void edk::GU::guOpen(){
    edk::GU_GLSL::mut.lock();
    edk::GU::initiate++;
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guClose(){
    edk::GU_GLSL::mut.lock();
    if(edk::GU::initiate){
        edk::GU::initiate--;
    }
    edk::GU_GLSL::mut.unlock();
}

//Color
void edk::GU::guColor3f32(edk::color3f32 color){
    edk::GU_GLSL::mut.lock();
    glColor3f(color.r,color.g,color.b);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guColor3f64(edk::color3f64 color){
    edk::GU_GLSL::mut.lock();
    glColor3d(color.r,color.g,color.b);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guColor3f32(edk::float32 r,edk::float32 g,edk::float32 b){
    edk::GU_GLSL::mut.lock();
    glColor3f(r,g,b);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guColor3f64(edk::float64 r,edk::float64 g,edk::float64 b){
    edk::GU_GLSL::mut.lock();
    glColor3d(r,g,b);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guColor4f32(edk::color4f32 color){
    edk::GU_GLSL::mut.lock();
    glColor4f(color.r,color.g,color.b,color.a);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guColor4f64(edk::color4f64 color){
    edk::GU_GLSL::mut.lock();
    glColor4d(color.r,color.g,color.b,color.a);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guColor4f32(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    edk::GU_GLSL::mut.lock();
    glColor4f(r,g,b,a);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guColor4f64(edk::float64 r,edk::float64 g,edk::float64 b,edk::float64 a){
    edk::GU_GLSL::mut.lock();
    glColor4d(r,g,b,a);
    edk::GU_GLSL::mut.unlock();
}

//clear dome buffer
void edk::GU::guClear(edk::uint32 mask){
    edk::GU_GLSL::mut.lock();
    glClear(mask);
    edk::GU_GLSL::mut.unlock();
}

//return the openGL matrix are using
bool edk::GU::guUsingMatrix(edk::uint32 mode){
    return (matrixMode==mode);
}
//set the usingMatrix
void edk::GU::guUseMatrix(edk::uint32 mode){
    //test if aready using the matrix
    if(mode!=matrixMode && mode!=GU_FALSE){
        edk::GU_GLSL::mut.lock();
        //then set the matrixMode
        glMatrixMode(mode);
        edk::GU_GLSL::mut.unlock();
    }
}
//load the identity matrix
void edk::GU::guLoadIdentity(){
    edk::GU_GLSL::mut.lock();
    glLoadIdentity();
    edk::GU_GLSL::mut.unlock();
}
//Push Matrix
void edk::GU::guPushMatrix(){
    edk::GU_GLSL::mut.lock();
    glPushMatrix();
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guPopMatrix(){
    edk::GU_GLSL::mut.lock();
    glPopMatrix();
    edk::GU_GLSL::mut.unlock();
}
//setViewport
void edk::GU::guSetViewport(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
    edk::GU_GLSL::mut.lock();
    glViewport(x,y,width,height);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guSetViewportRect(edk::rectui32 rect){
    edk::GU_GLSL::mut.lock();
    glViewport(rect.origin.x,rect.origin.y,rect.size.width,rect.size.height);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guLookAt(edk::float64 eyeX, edk::float64 eyeY, edk::float64 eyeZ, edk::float64 centerX, edk::float64 centerY, edk::float64 centerZ, edk::float64 upX, edk::float64 upY, edk::float64 upZ){
    edk::GU_GLSL::mut.lock();
    gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guLookAt(edk::float32 eyeX, edk::float32 eyeY, edk::float32 eyeZ, edk::float32 centerX, edk::float32 centerY, edk::float32 centerZ, edk::float32 upX, edk::float32 upY, edk::float32 upZ){
    edk::GU_GLSL::mut.lock();
    gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guUseOrtho(edk::float32 a, edk::float32 b, edk::float32 c, edk::float32 d, edk::float32 e, edk::float32 f){
    edk::GU_GLSL::mut.lock();
    glOrtho(a,b,c,d,e,f);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guUsePerspective(edk::float32 a, edk::float32 b, edk::float32 c, edk::float32 d){
    edk::GU_GLSL::mut.lock();
    gluPerspective(a, b, c, d);
    edk::GU_GLSL::mut.unlock();
}

//Create a textures
edk::uint32 edk::GU::guAllocTexture2D(edk::uint32 width, edk::uint32 height, edk::uint32 mode, edk::uint32 filter, const edk::classID  data){
    //test if it's NOT the main thread
    if(edk::GU::initiate){
        if(mode==GU_RGB || mode==GU_RGBA || mode==GU_LUMINANCE || mode==GU_LUMINANCE_ALPHA){
            if(edk::multi::Thread::isThisThreadMain()){
                edk::GU_GLSL::mutBeginEnd.lock();
                edk::GU_GLSL::mut.lock();
                edk::uint32 ID=0u;
                //Create the texture name
                glGenTextures(1u,&ID);
                //
                //test the ID
                if(ID){
                    //Set using texture
                    glBindTexture(GL_TEXTURE_2D,ID);
                    //Copy the texture
                    glTexImage2D(GL_TEXTURE_2D,
                                 0,
                                 mode,
                                 width,
                                 height,
                                 0,
                                 mode,
                                 GL_UNSIGNED_BYTE,
                                 data
                                 );

                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

                    if(filter == GU_NEAREST_MIPMAP_LINEAR || filter == GU_NEAREST_MIPMAP_NEAREST || filter == GU_LINEAR_MIPMAP_LINEAR || filter == GU_LINEAR_MIPMAP_NEAREST){
                        //load the mipmap
                        //glGenerateMipmap(GL_TEXTURE_2D);
                    }

                    //Clean use texture
                    glBindTexture(GL_TEXTURE_2D, 0u);
                }
                edk::GU_GLSL::mut.unlock();
                edk::GU_GLSL::mutBeginEnd.unlock();
                //return the ID
                return ID;
            }
            else{
#if __x86_64__ || __ppc64__
                edk::uint64 threadID = edk::multi::Thread::getThisThreadID();
#else
                edk::uint32 threadID = edk::multi::Thread::getThisThreadID();
#endif
                if(threadID){
                    //generate the TextureClass
                    edk::GU::TextureClass tex;
                    tex.width=width;
                    tex.height=height;
                    tex.mode=mode;
                    tex.filter=filter;
                    tex.data=data;
                    tex.threadID = threadID;

                    edk::uint32 ret=0u;

                    edk::GU::mutGetTextures.lock();
                    //add the tex in to the queue
                    edk::GU::genTextures.pushBack(tex);
                    edk::GU::mutGetTextures.unlock();

                    bool run=true;
                    //wait to get the texture ID
                    while(run){
                        edk::GU::mutGetTextures.lock();
                        //test if have some textures in the tree
                        if(edk::GU::treeTextures.size()){
                            //tes if have the texture inside the tree
                            if(edk::GU::treeTextures.haveTextureByThread(threadID)){
                                //get the texture
                                tex = edk::GU::treeTextures.getTextureByThread(threadID);
                                edk::GU::treeTextures.remove(tex);
                                ret=tex.id;
                                run=false;
                            }
                        }
                        //test if can't load the texture
                        if(!edk::GU::canLoadTexture){
                            if(ret){
                                edk::GU::guDeleteTexture(ret);
                            }
                            ret=0u;
                            run=false;
                        }
                        edk::GU::mutGetTextures.unlock();
                        if(run){
                            //sleep this thread
                            edk::watch::Time::sleepProcessMiliseconds(1u);
                        }
                    }
                    return ret;
                }
            }
        }
    }
    return 0u;
}
edk::uint32 edk::GU::guAllocTexture3D(edk::uint32 width, edk::uint32 height, edk::uint32 depth, edk::uint32 mode, edk::uint32 filter, const edk::classID  data){
    //test if it's NOT the main thread
    if(edk::GU::initiate){
        if(mode==GU_RGB || mode==GU_RGBA || mode==GU_LUMINANCE || mode==GU_LUMINANCE_ALPHA){
            if(edk::multi::Thread::isThisThreadMain()){
                edk::GU_GLSL::mutBeginEnd.lock();
                edk::GU_GLSL::mut.lock();
                edk::uint32 ID=0u;
                //Create the texture name
                glGenTextures(1u,&ID);
                //
                //test the ID
                if(ID){
                    //Set using texture
                    glBindTexture(GL_TEXTURE_3D,ID);

                    //Copy the texture
                    glTexImage3D(GL_TEXTURE_3D,
                                 0,
                                 mode,
                                 width,
                                 height,
                                 depth,
                                 0,
                                 mode,
                                 GL_UNSIGNED_BYTE,
                                 data
                                 );


                    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, filter);
                    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, filter);
                    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_REPEAT);

                    if(filter == GU_NEAREST_MIPMAP_LINEAR || filter == GU_NEAREST_MIPMAP_NEAREST || filter == GU_LINEAR_MIPMAP_LINEAR || filter == GU_LINEAR_MIPMAP_NEAREST){
                        //load the mipmap
                        //glGenerateMipmap(GL_TEXTURE_3D);
                    }

                    //Clean use texture
                    glBindTexture(GL_TEXTURE_3D, 0u);
                }
                edk::GU_GLSL::mut.unlock();
                edk::GU_GLSL::mutBeginEnd.unlock();
                //return the ID
                return ID;
            }
            else{
#if __x86_64__ || __ppc64__
                edk::uint64 threadID = edk::multi::Thread::getThisThreadID();
#else
                edk::uint32 threadID = edk::multi::Thread::getThisThreadID();
#endif
                if(threadID){
                    //generate the TextureClass
                    edk::GU::TextureClass tex;
                    tex.width=width;
                    tex.height=height;
                    tex.depth=depth;
                    tex.mode=mode;
                    tex.filter=filter;
                    tex.data=data;
                    tex.threadID = threadID;

                    edk::uint32 ret=0u;

                    edk::GU::mutGetTextures.lock();
                    //add the tex in to the queue
                    edk::GU::genTextures.pushBack(tex);
                    edk::GU::mutGetTextures.unlock();

                    bool run=true;
                    //wait to get the texture ID
                    while(run){
                        edk::GU::mutGetTextures.lock();
                        //test if have some textures in the tree
                        if(edk::GU::treeTextures.size()){
                            //tes if have the texture inside the tree
                            if(edk::GU::treeTextures.haveTextureByThread(threadID)){
                                //get the texture
                                tex = edk::GU::treeTextures.getTextureByThread(threadID);
                                edk::GU::treeTextures.remove(tex);
                                ret=tex.id;
                                run=false;
                            }
                        }
                        //test if can't load the texture
                        if(!edk::GU::canLoadTexture){
                            if(ret){
                                edk::GU::guDeleteTexture(ret);
                            }
                            ret=0u;
                            run=false;
                        }
                        edk::GU::mutGetTextures.unlock();
                        if(run){
                            //sleep this thread
                            edk::watch::Time::sleepProcessMiliseconds(1u);
                        }
                    }
                    return ret;
                }
            }
        }
    }
    return 0u;
}
//generate the mipmap from texture
void edk::GU::guGenerateMipmap(edk::uint32 ID){
    //test if it's NOT the main thread
    if(edk::GU::initiate){
        if(edk::multi::Thread::isThisThreadMain()){
            edk::GU_GLSL::mutBeginEnd.lock();
            edk::GU_GLSL::mut.lock();
            //Set using texture
            glBindTexture(GL_TEXTURE_2D,ID);
            //generate the mipmap
            glGenerateMipmap(GL_TEXTURE_2D);
            //Clean use texture
            glBindTexture(GL_TEXTURE_2D, 0u);
            edk::GU_GLSL::mut.unlock();
            edk::GU_GLSL::mutBeginEnd.unlock();
        }
        else{
#if __x86_64__ || __ppc64__
            edk::uint64 threadID = edk::multi::Thread::getThisThreadID();
#else
            edk::uint32 threadID = edk::multi::Thread::getThisThreadID();
#endif
            if(threadID){
                //generate the MipmapClass
                edk::GU::MipmapClass tex;
                tex.ID=ID;
                tex.threadID = threadID;

                edk::GU::mutGetMipmaps.lock();
                //add the tex in to the queue
                edk::GU::genMipmaps.pushBack(tex);
                edk::GU::mutGetMipmaps.unlock();
            }
        }
    }
}
bool edk::GU::guDrawToTexture2D(edk::uint32 ID,edk::uint32 width, edk::uint32 height, edk::uint32 mode, edk::uint32 filter, const edk::classID  data){
    //test the mode
    if(edk::GU::initiate&&(mode==GU_RGB || mode==GU_RGBA || mode==GU_LUMINANCE || mode==GU_LUMINANCE_ALPHA)){
        //test the ID
        if(ID){
            edk::GU_GLSL::mutBeginEnd.lock();
            edk::GU_GLSL::mut.lock();
            //Set using texture
            glBindTexture(GL_TEXTURE_2D,ID);
            //Copy the texture
            glTexImage2D(GL_TEXTURE_2D,
                         0,
                         mode,
                         width,
                         height,
                         0,
                         mode,
                         GL_UNSIGNED_BYTE,
                         data
                         );
            /*
            glTexImage2D(GLenum  target,
                          GLint  level,
                          GLint  internalFormat,
                          GLsizei  width,
                          GLsizei  height,
                          GLint  border,
                          GLenum  format,
                          GLenum  type,
                          const GLvoid *  data
                          );
                          */

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

            if(filter == GU_NEAREST_MIPMAP_LINEAR || filter == GU_NEAREST_MIPMAP_NEAREST || filter == GU_LINEAR_MIPMAP_LINEAR || filter == GU_LINEAR_MIPMAP_NEAREST){
                //load the mipmap
                //glGenerateMipmap(GL_TEXTURE_2D);
            }

            //Clean use texture
            glBindTexture(GL_TEXTURE_2D, 0u);
            edk::GU_GLSL::mut.unlock();
            edk::GU_GLSL::mutBeginEnd.unlock();

            return true;
        }
    }
    return false;
}
bool edk::GU::guDrawToTexture2DAndGenerateMipmap(edk::uint32 ID,edk::uint32 width, edk::uint32 height, edk::uint32 mode, edk::uint32 filter, const edk::classID  data){
    //test the mode
    if(edk::GU::initiate&&(mode==GU_RGB || mode==GU_RGBA || mode==GU_LUMINANCE || mode==GU_LUMINANCE_ALPHA)){
        //test the ID
        if(ID){
            edk::GU_GLSL::mutBeginEnd.lock();
            edk::GU_GLSL::mut.lock();
            //Set using texture
            glBindTexture(GL_TEXTURE_2D,ID);
            //Copy the texture
            glTexImage2D(GL_TEXTURE_2D,
                         0,
                         mode,
                         width,
                         height,
                         0,
                         mode,
                         GL_UNSIGNED_BYTE,
                         data
                         );
            /*
            glTexImage2D(GLenum  target,
                          GLint  level,
                          GLint  internalFormat,
                          GLsizei  width,
                          GLsizei  height,
                          GLint  border,
                          GLenum  format,
                          GLenum  type,
                          const GLvoid *  data
                          );
                          */

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

            //generate mipmap
            glGenerateMipmap(GL_TEXTURE_2D);

            //Clean use texture
            glBindTexture(GL_TEXTURE_2D, 0u);
            edk::GU_GLSL::mut.unlock();
            edk::GU_GLSL::mutBeginEnd.unlock();

            return true;
        }
    }
    return false;
}
bool edk::GU::guDrawPBOToTexture2D(edk::uint32 ID,edk::uint32 pbo,edk::uint32 width, edk::uint32 height, edk::uint32 mode, edk::uint32 filter, const edk::classID  data){
    //test the mode
    if(edk::GU::initiate&&(mode==GU_RGB || mode==GU_RGBA || mode==GU_LUMINANCE || mode==GU_LUMINANCE_ALPHA)){
        //test the ID
        if(ID){
            edk::GU_GLSL::mutBeginEnd.lock();
            edk::GU_GLSL::mut.lock();
            //Set using texture
            glBindTexture(GL_TEXTURE_2D,ID);

            edk::uint32 channels = 3u;
            switch (mode) {
            case GU_LUMINANCE:
                channels = 1u;
                break;
            case GU_LUMINANCE_ALPHA:
                channels = 2u;
                break;
            case GU_RGB:
                channels = 3u;
                break;
            case GU_RGBA:
                channels = 4u;
                break;
            }
            edk::GU_GLSL::guUseBuffer(GU_PIXEL_UNPACK_BUFFER,pbo);
            edk::GU_GLSL::guBufferData(GU_PIXEL_UNPACK_BUFFER,width*height*channels,NULL,GU_STREAM_DRAW);
            edk::classID ptr = edk::GU_GLSL::guMapBuffer(GU_PIXEL_UNPACK_BUFFER, GU_WRITE_ONLY);
            if(ptr){
                memcpy(ptr, data, width*height*channels);
            }

            edk::GU_GLSL::guUseBuffer(GU_PIXEL_UNPACK_BUFFER,pbo);
            //clean map buffer
            edk::GU_GLSL::guUnmapBuffer(GU_PIXEL_UNPACK_BUFFER);
            //Copy the texture
            glTexSubImage2D(GL_TEXTURE_2D,
                            0,
                            0,
                            0,
                            width,
                            height,
                            mode,
                            GL_UNSIGNED_BYTE,
                            NULL
                            );
            //clean use buffer
            edk::GU_GLSL::guDontUseBuffer(GU_PIXEL_UNPACK_BUFFER);
            //Clean use texture
            glBindTexture(GL_TEXTURE_2D, 0u);
            edk::GU_GLSL::mut.unlock();
            edk::GU_GLSL::mutBeginEnd.unlock();

            return true;
        }
    }
    return false;
}
bool edk::GU::guDrawPBOToTexture2DAndGenerateMipmap(edk::uint32 pbo,edk::uint32 ID,edk::uint32 width, edk::uint32 height, edk::uint32 mode, edk::uint32 filter, const edk::classID  data){
    //test the mode
    if(edk::GU::initiate&&(mode==GU_RGB || mode==GU_RGBA || mode==GU_LUMINANCE || mode==GU_LUMINANCE_ALPHA)){
        //test the ID
        if(ID){
            edk::GU_GLSL::mutBeginEnd.lock();
            edk::GU_GLSL::mut.lock();
            //Set using texture
            glBindTexture(GL_TEXTURE_2D,ID);

            edk::uint32 channels = 3u;
            switch (mode) {
            case GU_LUMINANCE:
                channels = 1u;
                break;
            case GU_LUMINANCE_ALPHA:
                channels = 2u;
                break;
            case GU_RGB:
                channels = 3u;
                break;
            case GU_RGBA:
                channels = 4u;
                break;
            }
            edk::GU_GLSL::guUseBuffer(GU_PIXEL_UNPACK_BUFFER,pbo);
            edk::GU_GLSL::guBufferData(GU_PIXEL_UNPACK_BUFFER,width*height*channels,NULL,GU_STREAM_DRAW);
            edk::classID ptr = edk::GU_GLSL::guMapBuffer(GU_PIXEL_UNPACK_BUFFER, GU_WRITE_ONLY);
            if(ptr){
                memcpy(ptr, data, width*height*channels);
            }

            edk::GU_GLSL::guUseBuffer(GU_PIXEL_UNPACK_BUFFER,pbo);
            //clean map buffer
            edk::GU_GLSL::guUnmapBuffer(GU_PIXEL_UNPACK_BUFFER);
            //Copy the texture
            glTexSubImage2D(GL_TEXTURE_2D,
                            0,
                            0,
                            0,
                            width,
                            height,
                            mode,
                            GL_UNSIGNED_BYTE,
                            NULL
                            );
            //clean use buffer
            edk::GU_GLSL::guDontUseBuffer(GU_PIXEL_UNPACK_BUFFER);

            //generate mipmap
            glGenerateMipmap(GL_TEXTURE_2D);

            //Clean use texture
            glBindTexture(GL_TEXTURE_2D, 0u);
            edk::GU_GLSL::mut.unlock();
            edk::GU_GLSL::mutBeginEnd.unlock();

            return true;
        }
    }
    return false;
}
//mode
//GU_RGB
//GU_RGBA
//GU_LUMINANCE
//GU_LUMINANCE_ALPHA
//filter
//GU_NEAREST
//GU_LINEAR
bool edk::GU::guDrawToTexture3D(edk::uint32 ID,edk::uint32 width, edk::uint32 height, edk::uint32 depth, edk::uint32 mode, edk::uint32 filter, const edk::classID  data){
    //test the mode
    if(edk::GU::initiate&&(mode==GU_RGB || mode==GU_RGBA || mode==GU_LUMINANCE || mode==GU_LUMINANCE_ALPHA)){
        //test the ID
        if(ID){
            edk::GU_GLSL::mutBeginEnd.lock();
            edk::GU_GLSL::mut.lock();
            //Set using texture
            glBindTexture(GL_TEXTURE_3D,ID);
            //Copy the texture
            glTexImage3D(GL_TEXTURE_3D,
                         0,
                         mode,
                         width,
                         height,
                         depth,
                         0,
                         mode,
                         GL_UNSIGNED_BYTE,
                         data
                         );
            /*
            glTexImage3D(GLenum  target,
                          GLint  level,
                          GLint  internalFormat,
                          GLsizei  width,
                          GLsizei  height,
                          GLsizei  depth,
                          GLint  border,
                          GLenum  format,
                          GLenum  type,
                          const GLvoid *  data
                          );
                          */

            glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, filter);
            glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, filter);
            glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_REPEAT);

            if(filter == GU_NEAREST_MIPMAP_LINEAR || filter == GU_NEAREST_MIPMAP_NEAREST || filter == GU_LINEAR_MIPMAP_LINEAR || filter == GU_LINEAR_MIPMAP_NEAREST){
                //load the mipmap
                //glGenerateMipmap(GL_TEXTURE_2D);
            }

            //Clean use texture
            glBindTexture(GL_TEXTURE_3D, 0u);
            edk::GU_GLSL::mut.unlock();
            edk::GU_GLSL::mutBeginEnd.unlock();

            return true;
        }
    }
    return false;
}
bool edk::GU::guDrawToTexture3DAndGenerateMipmap(edk::uint32 ID,edk::uint32 width, edk::uint32 height, edk::uint32 depth, edk::uint32 mode, edk::uint32 filter, const edk::classID  data){
    //test the mode
    if(edk::GU::initiate&&(mode==GU_RGB || mode==GU_RGBA || mode==GU_LUMINANCE || mode==GU_LUMINANCE_ALPHA)){
        //test the ID
        if(ID){
            edk::GU_GLSL::mutBeginEnd.lock();
            edk::GU_GLSL::mut.lock();
            //Set using texture
            glBindTexture(GL_TEXTURE_3D,ID);
            //Copy the texture
            glTexImage3D(GL_TEXTURE_3D,
                         0,
                         mode,
                         width,
                         height,
                         depth,
                         0,
                         mode,
                         GL_UNSIGNED_BYTE,
                         data
                         );
            /*
            glTexImage3D(GLenum  target,
                          GLint  level,
                          GLint  internalFormat,
                          GLsizei  width,
                          GLsizei  height,
                          GLsizei  depth,
                          GLint  border,
                          GLenum  format,
                          GLenum  type,
                          const GLvoid *  data
                          );
                          */

            glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, filter);
            glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, filter);
            glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_REPEAT);

            //generate mipmap
            glGenerateMipmap(GL_TEXTURE_3D);

            //Clean use texture
            glBindTexture(GL_TEXTURE_3D, 0u);
            edk::GU_GLSL::mut.unlock();
            edk::GU_GLSL::mutBeginEnd.unlock();

            return true;
        }
    }
    return false;
}

//delete texture
void edk::GU::guDeleteTexture(edk::uint32 ID){
    if(edk::GU::initiate){
        if(edk::multi::Thread::isThisThreadMain()){
            edk::GU_GLSL::mutBeginEnd.lock();
            edk::GU_GLSL::mut.lock();
            glDeleteTextures(1u,&ID);
            edk::GU_GLSL::mut.unlock();
            edk::GU_GLSL::mutBeginEnd.unlock();
        }
        else{
            //
            edk::GU::mutGetTextures.lock();
            //add the tex in to the queue
            edk::GU::delTextures.pushBack(ID);
            edk::GU::mutGetTextures.unlock();
        }
    }
}

void edk::GU::guBlendFunc( edk::uint32 sfactor, edk::uint32 dfactor ){
    if(edk::GU::initiate){
        edk::GU_GLSL::mut.lock();
        glBlendFunc( sfactor, dfactor );
        edk::GU_GLSL::mut.unlock();
    }
}
//ENABLE_DISABLE
void edk::GU::guEnable( edk::uint32 cap ){
    if(edk::GU::initiate){
        edk::GU_GLSL::mut.lock();
        glEnable(cap);
        edk::GU_GLSL::mut.unlock();
    }
}
void edk::GU::guDisable( edk::uint32 cap ){
    if(edk::GU::initiate){
        edk::GU_GLSL::mut.lock();
        glDisable(cap);
        edk::GU_GLSL::mut.unlock();
    }
}
//disable all lights
void edk::GU::guDisableAllLights(){
    for(edk::uint32 i=GU_LIGHT0;i<=GU_LIGHT7;i++){
        edk::GU::guDisable(i);
    }
}

//TRANSFORMATIONS
//rotation
/*

void guRotated( edk::GUdouble angle, edk::GUdouble x, edk::GUdouble y, edk::GUdouble z );
void guRotatef( edk::GUfloat angle, edk::GUfloat x, edk::GUfloat y, edk::GUfloat z );
void guScaled( edk::GUdouble x, edk::GUdouble y, edk::GUdouble z );
void guScalef( edk::GUfloat x, edk::GUfloat y, edk::GUfloat z );
void guTranslated( edk::GUdouble x, edk::GUdouble y, edk::GUdouble z );
void guTranslatef( edk::GUfloat x, edk::GUfloat y, edk::GUfloat z );

*/
void edk::GU::guRotate3f32( edk::float32 angle, edk::vec3f32 vec){
    //
    edk::GU::guRotate3f32( angle, vec.x, vec.y, vec.z );
}
void edk::GU::guRotate3f32( edk::float32 angle, edk::float32 x, edk::float32 y, edk::float32 z ){
    //
    edk::GU_GLSL::mut.lock();
    glRotatef( angle, x, y, z );
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guRotate3f64( edk::float64 angle, edk::vec3f64 vec){
    //
    edk::GU::guRotate3f64( angle, vec.x, vec.y, vec.z );
}
void edk::GU::guRotate3f64( edk::float64 angle, edk::float64 x, edk::float64 y, edk::float64 z ){
    //
    edk::GU_GLSL::mut.lock();
    glRotated( angle, x, y, z );
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guRotateXf32(edk::float32 angle){
    //
    edk::GU::guRotate3f32( angle, 1.0f, 0.0f, 0.0f );
}
void edk::GU::guRotateXf64(edk::float64 angle){
    //
    edk::GU::guRotate3f64( angle, 1.0, 0.0, 0.0 );
}
void edk::GU::guRotateYf32(edk::float32 angle){
    //
    edk::GU::guRotate3f32( angle, 0.0f, 1.0f, 0.0f );
}
void edk::GU::guRotateYf64(edk::float64 angle){
    //
    edk::GU::guRotate3f64( angle, 0.0, 1.0, 0.0 );
}
void edk::GU::guRotateZf32(edk::float32 angle){
    //
    edk::GU::guRotate3f32( angle, 0.0f, 0.0f, 1.0f );
}
void edk::GU::guRotateZf64(edk::float64 angle){
    //
    edk::GU::guRotate3f64( angle, 0.0, 0.0, 1.0 );
}
//scale
void edk::GU::guScale3f32( edk::size3f32 size ){
    //
    edk::GU::guScale3f32( size.width, size.height, size.length );
}
void edk::GU::guScale3f32( edk::float32 x, edk::float32 y, edk::float32 z ){
    //
    edk::GU_GLSL::mut.lock();
    glScalef(x,y,z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guScale3f64( edk::size3f64 size ){
    //
    edk::GU::guScale3f64( size.width, size.height, size.length );
}
void edk::GU::guScale3f64( edk::float64 x, edk::float64 y, edk::float64 z ){
    //
    edk::GU_GLSL::mut.lock();
    glScaled(x,y,z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guScale2f32( edk::size2f32 size ){
    //
    edk::GU::guScale2f32( size.width, size.height);
}
void edk::GU::guScale2f32( edk::float32 x, edk::float32 y){
    //
    edk::GU_GLSL::mut.lock();
    glScalef(x,y,1.0f);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guScale2f64( edk::size2f64 size ){
    //
    edk::GU::guScale2f64( size.width, size.height);
}
void edk::GU::guScale2f64( edk::float64 x, edk::float64 y){
    //
    edk::GU_GLSL::mut.lock();
    glScaled(x,y,1.0);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guScaleXf32( edk::float64 x){
    //
    edk::GU::guScale3f32( x, 1.0f, 1.0f);
}
void edk::GU::guScaleXf64( edk::float64 x){
    //
    edk::GU::guScale3f64( x, 1.0, 1.0);
}
void edk::GU::guScaleYf32( edk::float64 y){
    //
    edk::GU::guScale3f32( 1.0f, y, 1.0f);
}
void edk::GU::guScaleYf64( edk::float64 y){
    //
    edk::GU::guScale3f64( 1.0, y, 1.0);
}
void edk::GU::guScaleZf32( edk::float64 z){
    //
    edk::GU::guScale3f32( 1.0f, 1.0f, z);
}
void edk::GU::guScaleZf64( edk::float64 z){
    //
    edk::GU::guScale3f64( 1.0, 1.0, z);
}
//translate
void edk::GU::guTranslate3f32( edk::vec3f32 vec){
    //
    edk::GU::guTranslate3f32( vec.x, vec.y, vec.z );
}
void edk::GU::guTranslate3f32( edk::float32 x, edk::float32 y, edk::float32 z ){
    //
    edk::GU_GLSL::mut.lock();
    glTranslatef(x,y,z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guTranslate3f64( edk::vec3f64 vec){
    //
    edk::GU::guTranslate3f64( vec.x, vec.y, vec.z );
}
void edk::GU::guTranslate3f64( edk::float64 x, edk::float64 y, edk::float64 z ){
    //
    edk::GU_GLSL::mut.lock();
    glTranslated(x,y,z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guTranslate2f32( edk::vec2f32 vec ){
    //
    edk::GU::guTranslate2f32( vec.x, vec.y );
}
void edk::GU::guTranslate2f32( edk::float32 x, edk::float32 y ){
    //
    edk::GU_GLSL::mut.lock();
    glTranslatef(x,y,0.0f);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guTranslate2f64( edk::vec2f64 vec ){
    //
    edk::GU::guTranslate2f64( vec.x, vec.y );
}
void edk::GU::guTranslate2f64( edk::float64 x, edk::float64 y ){
    //
    edk::GU_GLSL::mut.lock();
    glTranslated(x,y,0.0);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guTranslateXf32( edk::float32 x ){
    //
    edk::GU::guTranslate3f32(x,0.0f,0.0f);
}
void edk::GU::guTranslateXf64( edk::float64 x ){
    //
    edk::GU::guTranslate3f64(x,0.0,0.0);
}
void edk::GU::guTranslateYf32( edk::float32 y ){
    //
    edk::GU::guTranslate3f32(0.0f,y,0.0f);
}
void edk::GU::guTranslateYf64( edk::float64 y ){
    //
    edk::GU::guTranslate3f64(0.0,y,0.0);
}
void edk::GU::guTranslateZf32( edk::float32 z ){
    //
    edk::GU::guTranslate3f32(0.0f,0.0f,z);
}
void edk::GU::guTranslateZf64( edk::float64 z ){
    //
    edk::GU::guTranslate3f64(0.0,0.0,z);
}
//SIZES
void edk::GU::guPointSize(edk::float32 size){
    edk::GU_GLSL::mut.lock();
    glPointSize(size);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guPointSize(edk::float64 size){
    edk::GU_GLSL::mut.lock();
    glPointSize(size);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guPointSize(edk::int8 size){
    edk::GU_GLSL::mut.lock();
    glPointSize((edk::float32)size);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guPointSize(edk::int16 size){
    edk::GU_GLSL::mut.lock();
    glPointSize((edk::float32)size);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guPointSize(edk::int32 size){
    edk::GU_GLSL::mut.lock();
    glPointSize((edk::float32)size);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guPointSize(edk::int64 size){
    edk::GU_GLSL::mut.lock();
    glPointSize((edk::float32)size);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guPointSize(edk::uint8 size){
    edk::GU_GLSL::mut.lock();
    glPointSize((edk::float32)size);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guPointSize(edk::uint16 size){
    edk::GU_GLSL::mut.lock();
    glPointSize((edk::float32)size);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guPointSize(edk::uint32 size){
    edk::GU_GLSL::mut.lock();
    glPointSize((edk::float32)size);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guPointSize(edk::uint64 size){
    edk::GU_GLSL::mut.lock();
    glPointSize((edk::float32)size);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guLineWidth(edk::float32 size){
    edk::GU_GLSL::mut.lock();
    glLineWidth(size);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guLineWidth(edk::float64 size){
    edk::GU_GLSL::mut.lock();
    glLineWidth(size);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guLineWidth(edk::int8 size){
    edk::GU_GLSL::mut.lock();
    glLineWidth((edk::float32)size);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guLineWidth(edk::int16 size){
    edk::GU_GLSL::mut.lock();
    glLineWidth((edk::float32)size);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guLineWidth(edk::int32 size){
    edk::GU_GLSL::mut.lock();
    glLineWidth((edk::float32)size);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guLineWidth(edk::int64 size){
    edk::GU_GLSL::mut.lock();
    glLineWidth((edk::float32)size);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guLineWidth(edk::uint8 size){
    edk::GU_GLSL::mut.lock();
    glLineWidth((edk::float32)size);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guLineWidth(edk::uint16 size){
    edk::GU_GLSL::mut.lock();
    glLineWidth((edk::float32)size);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guLineWidth(edk::uint32 size){
    edk::GU_GLSL::mut.lock();
    glLineWidth((edk::float32)size);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guLineWidth(edk::uint64 size){
    edk::GU_GLSL::mut.lock();
    glLineWidth((edk::float32)size);
    edk::GU_GLSL::mut.unlock();
}
//DRAW functions
void edk::GU::guBegin(edk::uint32 mode){
    edk::GU_GLSL::mutBeginEnd.lock();
    glBegin( mode );
}
void edk::GU::guEnd(){
    glEnd();
    edk::GU_GLSL::mutBeginEnd.unlock();
}
void edk::GU::guVertex2f32(edk::vec2f32 vec){
    edk::GU_GLSL::mut.lock();
    glVertex2f(vec.x,vec.y);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertex2f64(edk::vec2f64 vec){
    edk::GU_GLSL::mut.lock();
    glVertex2d(vec.x,vec.y);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertex2f32(edk::float32 x,edk::float32 y){
    edk::GU_GLSL::mut.lock();
    glVertex2f(x,y);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertex2f64(edk::float64 x,edk::float64 y){
    edk::GU_GLSL::mut.lock();
    glVertex2d(x,y);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertex3f32(edk::vec3f32 vec){
    edk::GU_GLSL::mut.lock();
    glVertex3f(vec.x,vec.y,vec.z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertex3f64(edk::vec3f64 vec){
    edk::GU_GLSL::mut.lock();
    glVertex3d(vec.x,vec.y,vec.z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertex3f32(edk::float32 x,edk::float32 y,edk::float32 z){
    edk::GU_GLSL::mut.lock();
    glVertex3f(x,y,z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertex3f64(edk::float64 x,edk::float64 y,edk::float64 z){
    edk::GU_GLSL::mut.lock();
    glVertex3d(x,y,z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertex4f32(edk::vec4f32 vec){
    edk::GU_GLSL::mut.lock();
    glVertex4f(vec.x,vec.y,vec.z,vec.w);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertex4f64(edk::vec4f64 vec){
    edk::GU_GLSL::mut.lock();
    glVertex4d(vec.x,vec.y,vec.z,vec.w);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertex4f32(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    edk::GU_GLSL::mut.lock();
    glVertex4f(x,y,z,w);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertex4f64(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 w){
    edk::GU_GLSL::mut.lock();
    glVertex4d(x,y,z,w);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertexNormal3f32(edk::vec3f32 vec){
    edk::GU_GLSL::mut.lock();
    glNormal3f(vec.x,vec.y,vec.z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertexNormal3f64(edk::vec3f64 vec){
    edk::GU_GLSL::mut.lock();
    glNormal3d(vec.x,vec.y,vec.z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertexNormal3f32(edk::float32 x,edk::float32 y,edk::float32 z){
    edk::GU_GLSL::mut.lock();
    glNormal3f(x,y,z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertexNormal3f64(edk::float64 x,edk::float64 y,edk::float64 z){
    edk::GU_GLSL::mut.lock();
    glNormal3d(x,y,z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertexCurve2Lines(edk::shape::Curve2D curve,edk::uint32 cuts){
    edk::float32 increment = 1.f/(cuts+2u);
    edk::vec2f32 point1,point2;
    edk::float32 percent1 = 0.f;
    for(edk::float32 percent2 = increment;percent1<1.f;percent1=percent2,percent2+=increment){
        point1 = curve.getPoint(percent1);
        point2 = curve.getPoint(percent2);
        edk::GU::guVertex2f32(point1.x,point1.y);
        edk::GU::guVertex2f32(point2.x,point2.y);
    }
    point1 = curve.getPoint(percent1);
    point2 = curve.getPoint(1.f);
    edk::GU::guVertex2f32(point1.x,point1.y);
    edk::GU::guVertex2f32(point2.x,point2.y);
}
void edk::GU::guVertexCurve3Lines(edk::shape::Curve3D curve,edk::uint32 cuts){
    edk::float32 increment = 1.f/(cuts+2u);
    edk::vec3f32 point1,point2;
    edk::float32 percent1 = 0.f;
    for(edk::float32 percent2 = increment;percent1<1.f;percent1=percent2,percent2+=increment){
        point1 = curve.getPoint(percent1);
        point2 = curve.getPoint(percent2);
        edk::GU::guVertex3f32(point1.x,point1.y,point1.z);
        edk::GU::guVertex3f32(point2.x,point2.y,point2.z);
    }
    point1 = curve.getPoint(percent1);
    point2 = curve.getPoint(1.f);
    edk::GU::guVertex3f32(point1.x,point1.y,point1.z);
    edk::GU::guVertex3f32(point2.x,point2.y,point2.z);
}
void edk::GU::guVertexCurve2LineStrip(edk::shape::Curve2D curve,edk::uint32 cuts){
    edk::float32 increment = 1.f/(cuts+2u);
    edk::vec2f32 point;
    for(edk::float32 percent = 0.f;percent<=1.f;percent+=increment){
        point = curve.getPoint(percent);
        edk::GU::guVertex2f32(point.x,point.y);
    }
    point = curve.getPoint(1.f);
    edk::GU::guVertex2f32(point.x,point.y);
}
void edk::GU::guVertexCurve3LineStrip(edk::shape::Curve3D curve,edk::uint32 cuts){
    edk::float32 increment = 1.f/(cuts+2u);
    edk::vec3f32 point;
    for(edk::float32 percent = 0.f;percent<=1.f;percent+=increment){
        point = curve.getPoint(percent);
        edk::GU::guVertex3f32(point.x,point.y,point.z);
    }
    point = curve.getPoint(1.f);
    edk::GU::guVertex3f32(point.x,point.y,point.z);
}
void edk::GU::guVertexCurve2Lines(edk::shape::Bezier2D curve,edk::uint32 cuts){
    edk::float32 increment = 1.f/(cuts+2u);
    edk::vec2f32 point1,point2;
    edk::float32 percent1 = 0.f;
    for(edk::float32 percent2 = increment;percent1<1.f;percent1=percent2,percent2+=increment){
        point1 = curve.getPoint(percent1);
        point2 = curve.getPoint(percent2);
        edk::GU::guVertex2f32(point1.x,point1.y);
        edk::GU::guVertex2f32(point2.x,point2.y);
    }
    point1 = curve.getPoint(percent1);
    point2 = curve.getPoint(1.f);
    edk::GU::guVertex2f32(point1.x,point1.y);
    edk::GU::guVertex2f32(point2.x,point2.y);
}
void edk::GU::guVertexCurve3Lines(edk::shape::Bezier3D curve,edk::uint32 cuts){
    edk::float32 increment = 1.f/(cuts+2u);
    edk::vec3f32 point1,point2;
    edk::float32 percent1 = 0.f;
    for(edk::float32 percent2 = increment;percent1<1.f;percent1=percent2,percent2+=increment){
        point1 = curve.getPoint(percent1);
        point2 = curve.getPoint(percent2);
        edk::GU::guVertex3f32(point1.x,point1.y,point1.z);
        edk::GU::guVertex3f32(point2.x,point2.y,point2.z);
    }
    point1 = curve.getPoint(percent1);
    point2 = curve.getPoint(1.f);
    edk::GU::guVertex3f32(point1.x,point1.y,point1.z);
    edk::GU::guVertex3f32(point2.x,point2.y,point2.z);
}
void edk::GU::guVertexCurve2LineStrip(edk::shape::Bezier2D curve,edk::uint32 cuts){
    edk::float32 increment = 1.f/(cuts+2u);
    edk::vec2f32 point;
    for(edk::float32 percent = 0.f;percent<=1.f;percent+=increment){
        point = curve.getPoint(percent);
        edk::GU::guVertex2f32(point.x,point.y);
    }
    point = curve.getPoint(1.f);
    edk::GU::guVertex2f32(point.x,point.y);
}
void edk::GU::guVertexCurve3LineStrip(edk::shape::Bezier3D curve,edk::uint32 cuts){
    edk::float32 increment = 1.f/(cuts+2u);
    edk::vec3f32 point;
    for(edk::float32 percent = 0.f;percent<=1.f;percent+=increment){
        point = curve.getPoint(percent);
        edk::GU::guVertex3f32(point.x,point.y,point.z);
    }
    point = curve.getPoint(1.f);
    edk::GU::guVertex3f32(point.x,point.y,point.z);
}
void edk::GU::guVertexCurve2Lines(edk::shape::Catmull2D curve,edk::uint32 cuts){
    edk::float32 increment = 1.f/(cuts+2u);
    edk::vec2f32 point1,point2;
    edk::float32 percent1 = 0.f;
    for(edk::float32 percent2 = increment;percent1<1.f;percent1=percent2,percent2+=increment){
        point1 = curve.getPoint(percent1);
        point2 = curve.getPoint(percent2);
        edk::GU::guVertex2f32(point1.x,point1.y);
        edk::GU::guVertex2f32(point2.x,point2.y);
    }
    point1 = curve.getPoint(percent1);
    point2 = curve.getPoint(1.f);
    edk::GU::guVertex2f32(point1.x,point1.y);
    edk::GU::guVertex2f32(point2.x,point2.y);
}
void edk::GU::guVertexCurve3Lines(edk::shape::Catmull3D curve,edk::uint32 cuts){
    edk::float32 increment = 1.f/(cuts+2u);
    edk::vec3f32 point1,point2;
    edk::float32 percent1 = 0.f;
    for(edk::float32 percent2 = increment;percent1<1.f;percent1=percent2,percent2+=increment){
        point1 = curve.getPoint(percent1);
        point2 = curve.getPoint(percent2);
        edk::GU::guVertex3f32(point1.x,point1.y,point1.z);
        edk::GU::guVertex3f32(point2.x,point2.y,point2.z);
    }
    point1 = curve.getPoint(percent1);
    point2 = curve.getPoint(1.f);
    edk::GU::guVertex3f32(point1.x,point1.y,point1.z);
    edk::GU::guVertex3f32(point2.x,point2.y,point2.z);
}
void edk::GU::guVertexCurve2LineStrip(edk::shape::Catmull2D curve,edk::uint32 cuts){
    edk::float32 increment = 1.f/(cuts+2u);
    edk::vec2f32 point;
    for(edk::float32 percent = 0.f;percent<=1.f;percent+=increment){
        point = curve.getPoint(percent);
        edk::GU::guVertex2f32(point.x,point.y);
    }
    point = curve.getPoint(1.f);
    edk::GU::guVertex2f32(point.x,point.y);
}
void edk::GU::guVertexCurve3LineStrip(edk::shape::Catmull3D curve,edk::uint32 cuts){
    edk::float32 increment = 1.f/(cuts+2u);
    edk::vec3f32 point;
    for(edk::float32 percent = 0.f;percent<=1.f;percent+=increment){
        point = curve.getPoint(percent);
        edk::GU::guVertex3f32(point.x,point.y,point.z);
    }
    point = curve.getPoint(1.f);
    edk::GU::guVertex3f32(point.x,point.y,point.z);
}
void edk::GU::guVertexCurve2Lines(edk::shape::Hermite2D curve,edk::uint32 cuts){
    edk::float32 increment = 1.f/(cuts+2u);
    edk::vec2f32 point1,point2;
    edk::float32 percent1 = 0.f;
    for(edk::float32 percent2 = increment;percent1<1.f;percent1=percent2,percent2+=increment){
        point1 = curve.getPoint(percent1);
        point2 = curve.getPoint(percent2);
        edk::GU::guVertex2f32(point1.x,point1.y);
        edk::GU::guVertex2f32(point2.x,point2.y);
    }
    point1 = curve.getPoint(percent1);
    point2 = curve.getPoint(1.f);
    edk::GU::guVertex2f32(point1.x,point1.y);
    edk::GU::guVertex2f32(point2.x,point2.y);
}
void edk::GU::guVertexCurve3Lines(edk::shape::Hermite3D curve,edk::uint32 cuts){
    edk::float32 increment = 1.f/(cuts+2u);
    edk::vec3f32 point1,point2;
    edk::float32 percent1 = 0.f;
    for(edk::float32 percent2 = increment;percent1<1.f;percent1=percent2,percent2+=increment){
        point1 = curve.getPoint(percent1);
        point2 = curve.getPoint(percent2);
        edk::GU::guVertex3f32(point1.x,point1.y,point1.z);
        edk::GU::guVertex3f32(point2.x,point2.y,point2.z);
    }
    point1 = curve.getPoint(percent1);
    point2 = curve.getPoint(1.f);
    edk::GU::guVertex3f32(point1.x,point1.y,point1.z);
    edk::GU::guVertex3f32(point2.x,point2.y,point2.z);
}
void edk::GU::guVertexCurve2LineStrip(edk::shape::Hermite2D curve,edk::uint32 cuts){
    edk::float32 increment = 1.f/(cuts+2u);
    edk::vec2f32 point;
    for(edk::float32 percent = 0.f;percent<=1.f;percent+=increment){
        point = curve.getPoint(percent);
        edk::GU::guVertex2f32(point.x,point.y);
    }
    point = curve.getPoint(1.f);
    edk::GU::guVertex2f32(point.x,point.y);
}
void edk::GU::guVertexCurve3LineStrip(edk::shape::Hermite3D curve,edk::uint32 cuts){
    edk::float32 increment = 1.f/(cuts+2u);
    edk::vec3f32 point;
    for(edk::float32 percent = 0.f;percent<=1.f;percent+=increment){
        point = curve.getPoint(percent);
        edk::GU::guVertex3f32(point.x,point.y,point.z);
    }
    point = curve.getPoint(1.f);
    edk::GU::guVertex3f32(point.x,point.y,point.z);
}

// LIGHTING
void edk::GU::guShadeModel( edk::uint32 model ){
    edk::GU_GLSL::mut.lock();
    glShadeModel(model);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guLightf32( edk::uint32 light, edk::uint32 pname, edk::float32 param ){
    edk::GU_GLSL::mut.lock();
    glLightf(light,pname,param);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guLighti32( edk::uint32 light, edk::uint32 pname, edk::int32 param ){
    edk::GU_GLSL::mut.lock();
    glLighti(light,pname,param);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guLightfv32( edk::uint32 light, edk::uint32 pname, const edk::float32 *params ){
    edk::GU_GLSL::mut.lock();
    glLightfv(light,pname,params);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guLightiv32( edk::uint32 light, edk::uint32 pname, const edk::int32 *params ){
    edk::GU_GLSL::mut.lock();
    glLightiv(light,pname,params);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guGetLightfv32( edk::uint32 light, edk::uint32 pname, edk::float32 *params ){
    edk::GU_GLSL::mut.lock();
    glGetLightfv(light,pname,params);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guGetLightiv32( edk::uint32 light, edk::uint32 pname, edk::int32 *params ){
    edk::GU_GLSL::mut.lock();
    glGetLightiv(light,pname,params);
    edk::GU_GLSL::mut.unlock();
}

//MATERIAL
void edk::GU::guMaterialf32( edk::uint32 face, edk::uint32 pname, edk::float32 param ){
    edk::GU_GLSL::mut.lock();
    glMaterialf(face,pname,param);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guMateriali32( edk::uint32 face, edk::uint32 pname, edk::int32 param ){
    edk::GU_GLSL::mut.lock();
    glMateriali(face,pname,param);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guMaterialfv32( edk::uint32 face, edk::uint32 pname, const edk::float32 *params ){
    edk::GU_GLSL::mut.lock();
    glMaterialfv(face,pname,params);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guMaterialiv32( edk::uint32 face, edk::uint32 pname, const edk::int32 *params ){
    edk::GU_GLSL::mut.lock();
    glMaterialiv(face,pname,params);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guGetMaterialfv32( edk::uint32 face, edk::uint32 pname, edk::float32 *params ){
    edk::GU_GLSL::mut.lock();
    glGetMaterialfv(face,pname,params);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guGetMaterialiv32( edk::uint32 face, edk::uint32 pname, edk::int32 *params ){
    edk::GU_GLSL::mut.lock();
    glGetMaterialiv(face,pname,params);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guColorMaterial( edk::uint32 face, edk::uint32 mode ){
    edk::GU_GLSL::mut.lock();
    glColorMaterial(face,mode);
    edk::GU_GLSL::mut.unlock();
}

//DEPTH
void edk::GU::guDepthFunc(edk::uint32 func){
    edk::GU_GLSL::mut.lock();
    glDepthFunc( func );
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guDepthRange( edk::float64 near_val, edk::float64 far_val ){
    edk::GU_GLSL::mut.lock();
    glDepthRange(near_val,far_val);
    edk::GU_GLSL::mut.unlock();
}

//TEXTURE
void edk::GU::guUseTexture(edk::uint32 target, edk::uint32 texture){
    edk::GU_GLSL::mutBeginEnd.lock();
    edk::GU_GLSL::mut.lock();
    glBindTexture( target, texture );
    edk::GU_GLSL::mut.unlock();
    edk::GU_GLSL::mutBeginEnd.unlock();
}
void edk::GU::guUseTexture1D(edk::uint32 texture){
    edk::GU_GLSL::mutBeginEnd.lock();
    edk::GU_GLSL::mut.lock();
    glBindTexture( GU_TEXTURE_1D, texture );
    edk::GU_GLSL::mut.unlock();
    edk::GU_GLSL::mutBeginEnd.unlock();
}
void edk::GU::guUseTexture2D(edk::uint32 texture){
    edk::GU_GLSL::mutBeginEnd.lock();
    edk::GU_GLSL::mut.lock();
    glBindTexture( GU_TEXTURE_2D, texture );
    edk::GU_GLSL::mut.unlock();
    edk::GU_GLSL::mutBeginEnd.unlock();
}
void edk::GU::guUseTexture3D(edk::uint32 texture){
    edk::GU_GLSL::mutBeginEnd.lock();
    edk::GU_GLSL::mut.lock();
    glBindTexture( GU_TEXTURE_3D, texture );
    edk::GU_GLSL::mut.unlock();
    edk::GU_GLSL::mutBeginEnd.unlock();
}
void edk::GU::guVertexTex1f32(edk::float32 n){
    edk::GU_GLSL::mut.lock();
    glTexCoord1f(n);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertexTex1f64(edk::float64 n){
    edk::GU_GLSL::mut.lock();
    glTexCoord1d(n);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertexTex2f32(edk::vec2f32 vec){
    edk::GU_GLSL::mut.lock();
    glTexCoord2f(vec.x,vec.y);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertexTex2f64(edk::vec2f64 vec){
    edk::GU_GLSL::mut.lock();
    glTexCoord2d(vec.x,vec.y);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertexTex2f32(edk::float32 x,edk::float32 y){
    edk::GU_GLSL::mut.lock();
    glTexCoord2f(x,y);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertexTex2f64(edk::float64 x,edk::float64 y){
    edk::GU_GLSL::mut.lock();
    glTexCoord2d(x,y);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertexTex3f32(edk::vec3f32 vec){
    edk::GU_GLSL::mut.lock();
    glTexCoord3f(vec.x,vec.y,vec.z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertexTex3f64(edk::vec3f64 vec){
    edk::GU_GLSL::mut.lock();
    glTexCoord3d(vec.x,vec.y,vec.z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertexTex3f32(edk::float32 x,edk::float32 y,edk::float32 z){
    edk::GU_GLSL::mut.lock();
    glTexCoord3f(x,y,z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertexTex3f64(edk::float64 x,edk::float64 y,edk::float64 z){
    edk::GU_GLSL::mut.lock();
    glTexCoord3d(x,y,z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertexTex4f32(edk::vec4f32 vec){
    edk::GU_GLSL::mut.lock();
    glTexCoord4f(vec.x,vec.y,vec.z,vec.w);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertexTex4f64(edk::vec4f64 vec){
    edk::GU_GLSL::mut.lock();
    glTexCoord4d(vec.x,vec.y,vec.z,vec.w);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertexTex4f32(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    edk::GU_GLSL::mut.lock();
    glTexCoord4f(x,y,z,w);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU::guVertexTex4f64(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 w){
    edk::GU_GLSL::mut.lock();
    glTexCoord4d(x,y,z,w);
    edk::GU_GLSL::mut.unlock();
}

//LINES
void edk::GU::guDrawCurve2Lines(edk::shape::Curve2D curve,edk::uint32 cuts){
    edk::GU::guBegin(GU_LINES);
    edk::GU::guVertexCurve2Lines(curve,cuts);
    edk::GU::guEnd();
}
void edk::GU::guDrawCurve3Lines(edk::shape::Curve3D curve,edk::uint32 cuts){
    edk::GU::guBegin(GU_LINES);
    edk::GU::guVertexCurve3Lines(curve,cuts);
    edk::GU::guEnd();
}
void edk::GU::guDrawCurve2LineStrip(edk::shape::Curve2D curve,edk::uint32 cuts){
    edk::GU::guBegin(GU_LINE_STRIP);
    edk::GU::guVertexCurve2LineStrip(curve,cuts);
    edk::GU::guEnd();
}
void edk::GU::guDrawCurve3LineStrip(edk::shape::Curve3D curve,edk::uint32 cuts){
    edk::GU::guBegin(GU_LINE_STRIP);
    edk::GU::guVertexCurve3LineStrip(curve,cuts);
    edk::GU::guEnd();
}
void edk::GU::guDrawCurve2Lines(edk::shape::Bezier2D curve,edk::uint32 cuts){
    edk::GU::guBegin(GU_LINES);
    edk::GU::guVertexCurve2Lines(curve,cuts);
    edk::GU::guEnd();
}
void edk::GU::guDrawCurve3Lines(edk::shape::Bezier3D curve,edk::uint32 cuts){
    edk::GU::guBegin(GU_LINES);
    edk::GU::guVertexCurve3Lines(curve,cuts);
    edk::GU::guEnd();
}
void edk::GU::guDrawCurve2LineStrip(edk::shape::Bezier2D curve,edk::uint32 cuts){
    edk::GU::guBegin(GU_LINE_STRIP);
    edk::GU::guVertexCurve2LineStrip(curve,cuts);
    edk::GU::guEnd();
}
void edk::GU::guDrawCurve3LineStrip(edk::shape::Bezier3D curve,edk::uint32 cuts){
    edk::GU::guBegin(GU_LINE_STRIP);
    edk::GU::guVertexCurve3LineStrip(curve,cuts);
    edk::GU::guEnd();
}
void edk::GU::guDrawCurve2Lines(edk::shape::Catmull2D curve,edk::uint32 cuts){
    edk::GU::guBegin(GU_LINES);
    edk::GU::guVertexCurve2Lines(curve,cuts);
    edk::GU::guEnd();
}
void edk::GU::guDrawCurve3Lines(edk::shape::Catmull3D curve,edk::uint32 cuts){
    edk::GU::guBegin(GU_LINES);
    edk::GU::guVertexCurve3Lines(curve,cuts);
    edk::GU::guEnd();
}
void edk::GU::guDrawCurve2LineStrip(edk::shape::Catmull2D curve,edk::uint32 cuts){
    edk::GU::guBegin(GU_LINE_STRIP);
    edk::GU::guVertexCurve2LineStrip(curve,cuts);
    edk::GU::guEnd();
}
void edk::GU::guDrawCurve3LineStrip(edk::shape::Catmull3D curve,edk::uint32 cuts){
    edk::GU::guBegin(GU_LINE_STRIP);
    edk::GU::guVertexCurve3LineStrip(curve,cuts);
    edk::GU::guEnd();
}
void edk::GU::guDrawCurve2Lines(edk::shape::Hermite2D curve,edk::uint32 cuts){
    edk::GU::guBegin(GU_LINES);
    edk::GU::guVertexCurve2Lines(curve,cuts);
    edk::GU::guEnd();
}
void edk::GU::guDrawCurve3Lines(edk::shape::Hermite3D curve,edk::uint32 cuts){
    edk::GU::guBegin(GU_LINES);
    edk::GU::guVertexCurve3Lines(curve,cuts);
    edk::GU::guEnd();
}
void edk::GU::guDrawCurve2LineStrip(edk::shape::Hermite2D curve,edk::uint32 cuts){
    edk::GU::guBegin(GU_LINE_STRIP);
    edk::GU::guVertexCurve2LineStrip(curve,cuts);
    edk::GU::guEnd();
}
void edk::GU::guDrawCurve3LineStrip(edk::shape::Hermite3D curve,edk::uint32 cuts){
    edk::GU::guBegin(GU_LINE_STRIP);
    edk::GU::guVertexCurve3LineStrip(curve,cuts);
    edk::GU::guEnd();
}

//cullFace
void edk::GU::guCullFace(edk::uint32 mode){
    glCullFace(mode);
}

//SELET BUFFER
//alloc the buffer
bool edk::GU::guSetSelectionBuffer(edk::uint32 size,edk::uint32* vector){
    if(vector && size){
        edk::GU_GLSL::mut.lock();
        glSelectBuffer(size,vector);
        edk::GU_GLSL::mut.unlock();
        return true;
    }
    return false;
}
//Set renderMode
edk::int32 edk::GU::guRenderMode( edk::uint32 mode){
    edk::int32 ret;
    edk::GU_GLSL::mut.lock();
    ret = glRenderMode(mode);
    edk::GU_GLSL::mut.unlock();
    return ret;
}
//init the names
void edk::GU::guInitNames(){
    edk::GU_GLSL::mut.lock();
    glInitNames();
    edk::GU_GLSL::mut.unlock();
}
//push a name
void edk::GU::guPushName(edk::uint32 id){
    edk::GU_GLSL::mut.lock();
    glPushName(id);
    edk::GU_GLSL::mut.unlock();
}
//load a name
void edk::GU::guLoadName(edk::uint32 id){
    edk::GU_GLSL::mut.lock();
    glLoadName(id);
    edk::GU_GLSL::mut.unlock();
}
//pop some name
void edk::GU::guPopName(){
    edk::GU_GLSL::mut.lock();
    glPopName();
    edk::GU_GLSL::mut.unlock();
}

//set the pickMatrix
void edk::GU::guPickMatrix(edk::float64  x,  edk::float64  y,  edk::float64  delX,  edk::float64  delY){
    GLint viewport[4];
    edk::GU_GLSL::mut.lock();
    glGetIntegerv(GL_VIEWPORT, viewport);
    gluPickMatrix(x,y,delX,delY,viewport);
    edk::GU_GLSL::mut.unlock();
}

//STRING
//GL_VENDOR
//Returns the company responsible for this GL implementation
edk::char8* edk::GU::guGetVendor(){
    edk::char8* ret;
    edk::GU_GLSL::mut.lock();
    ret = (edk::char8*)glGetString(GL_VENDOR);
    edk::GU_GLSL::mut.unlock();
    return ret;
}
//GL_RENDERER
//Returns the name of the renderer
edk::char8* edk::GU::guGetRenderer(){
    edk::char8* ret;
    edk::GU_GLSL::mut.lock();
    ret = (edk::char8*)glGetString(GL_RENDERER);
    edk::GU_GLSL::mut.unlock();
    return ret;
}
//GL_VERSION
//Returns a version or release number of the form
edk::char8* edk::GU::guGetVersion(){
    edk::char8* ret;
    edk::GU_GLSL::mut.lock();
    ret = (edk::char8*)glGetString(GL_VERSION);
    edk::GU_GLSL::mut.unlock();
    return ret;
}
//GL_EXTENSIONS
//Returns a space-separated list of supported extensions to GL.
edk::char8* edk::GU::guGetExtensions(){
    edk::char8* ret;
    edk::GU_GLSL::mut.lock();
    ret = (edk::char8*)glGetString(GL_EXTENSIONS);
    edk::GU_GLSL::mut.unlock();
    return ret;
}

//run function to load the textures from other threads
bool edk::GU::guUpdateLoadTextures(){
    edk::GU::guUpdateDeleteTextures();
    bool ret=false;
    //test if it's the main thread
    edk::GU::mutGetTextures.lock();
    edk::uint32 size = edk::GU::genTextures.size();
    edk::GU::mutGetTextures.unlock();
    if(size){
        if(edk::multi::Thread::isThisThreadMain()){
            if(size>2u){
                size=2u;
            }
            edk::GU::TextureClass tex;
            for(edk::uint32 i=0u;i<size;i++){
                //get the tex
                edk::GU::mutGetTextures.lock();
                tex = edk::GU::genTextures.popFront();
                if(!edk::GU::canLoadTexture){
                    tex.id = 0u;
                    edk::GU::treeTextures.add(tex);
                    edk::GU::mutGetTextures.unlock();
                    continue;
                }
                else{
                    edk::GU::mutGetTextures.unlock();
                }
                //load the texture
                if(tex.depth){
                    tex.id = edk::GU::guAllocTexture3D(tex.width,tex.height,tex.depth,tex.mode,tex.filter,tex.data);
                }
                else{
                    tex.id = edk::GU::guAllocTexture2D(tex.width,tex.height,tex.mode,tex.filter,tex.data);
                }

                edk::GU::mutGetTextures.lock();
                if(!edk::GU::canLoadTexture){
                    edk::GU::mutGetTextures.unlock();
                    edk::GU::guDeleteTexture(tex.id);
                    tex.id = 0u;
                }
                else{
                    edk::GU::mutGetTextures.unlock();
                }

                edk::GU::mutGetTextures.lock();
                //add the tex into the tree
                edk::GU::treeTextures.add(tex);
                edk::GU::mutGetTextures.unlock();
            }
        }
        ret=true;
    }
    //test if it's the main thread
    edk::GU::mutGetMipmaps.lock();
    size = edk::GU::genMipmaps.size();
    edk::GU::mutGetMipmaps.unlock();
    if(size){
        if(edk::multi::Thread::isThisThreadMain()){
            if(size>2u){
                size=2u;
            }
            edk::GU::MipmapClass tex;
            for(edk::uint32 i=0u;i<size;i++){
                //get the tex
                edk::GU::mutGetMipmaps.lock();
                tex = edk::GU::genMipmaps.popFront();
                if(!edk::GU::canLoadTexture){
                    edk::GU::mutGetTextures.unlock();
                    continue;
                }
                else{
                    edk::GU::mutGetTextures.unlock();
                }
                //load the texture
                edk::GU::guGenerateMipmap(tex.ID);
            }
        }
        ret=true;
    }
    return ret;
}
bool edk::GU::guUpdateDeleteTextures(){
    //test if it's the main thread
    edk::GU::mutDelTextures.lock();
    edk::uint32 size = edk::GU::delTextures.size();
    edk::GU::mutDelTextures.unlock();
    if(size){
        if(edk::multi::Thread::isThisThreadMain()){
            if(size>2u){
                size=2u;
            }
            edk::uint32 ID=0u;
            for(edk::uint32 i=0u;i<size;i++){
                //get the tex
                edk::GU::mutDelTextures.lock();
                ID = edk::GU::delTextures.popFront();
                edk::GU::guDeleteTexture(ID);
                edk::GU::mutDelTextures.unlock();
            }
            return true;
        }
    }
    return false;
}
