#ifndef EDK_TEXTURE2D_H
#define EDK_TEXTURE2D_H

/*
Library Texture2D - 2D Textures in GU
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
#pragma message "Inside Texture2D"
#endif

#pragma once
#include "Types.h"
#include "String.h"
#include "GU/GU.h"
#include "Object.h"

#ifdef printMessages
#pragma message "    Compiling Texture2D"
#endif

/*LIB LINUX

-lsfml-graphics
-lGL
-lGLU

*/

/*LIB WINDOWS 32

-lsfml-graphics
-lopengl32
-lglu32

*/

//defines
#define EDK_LUMINANCE 1u
#define EDK_LUMINANCE_ALPHA 2u
#define EDK_RGB  3u
#define EDK_RGBA 4u


//Render to Texture

namespace edk{
class Texture2D: public edk::ObjectWithName{
public:
    Texture2D();
    virtual ~Texture2D();

    void Constructor();
    void Destructor();

    //alloc the textureObject
    //MODE
    //        GU_RGB
    //        GU_RGBA
    //        GU_LUMINANCE
    //        GU_LUMINANCE_ALPHA
    //FILTER
    //        GU_NEAREST
    //        GU_LINEAR
    bool createTexture(edk::uint32 width,
                       edk::uint32 height,
                       edk::uint32 mode,
                       const edk::classID  data = NULL,
                       edk::uint32 minFilter = GU_NEAREST,
                       edk::uint32 magFilter = GU_LINEAR
            );
    bool createTextureWithPBODraw(edk::uint32 width,
                                  edk::uint32 height,
                                  edk::uint32 mode,
                                  const edk::classID  data = NULL,
                                  edk::uint32 minFilter = GU_NEAREST,
                                  edk::uint32 magFilter = GU_LINEAR
            );
    bool createTextureWithPBORead(edk::uint32 width,
                                  edk::uint32 height,
                                  edk::uint32 mode,
                                  const edk::classID  data = NULL,
                                  edk::uint32 minFilter = GU_NEAREST,
                                  edk::uint32 magFilter = GU_LINEAR
            );
    bool createTextureRepeat(edk::uint32 width,
                             edk::uint32 height,
                             edk::uint32 mode,
                             const edk::classID  data = NULL,
                             edk::uint32 minFilter = GU_NEAREST,
                             edk::uint32 magFilter = GU_LINEAR
            );
    bool createTextureRepeatWithPBODraw(edk::uint32 width,
                                        edk::uint32 height,
                                        edk::uint32 mode,
                                        const edk::classID  data = NULL,
                                        edk::uint32 minFilter = GU_NEAREST,
                                        edk::uint32 magFilter = GU_LINEAR
            );
    bool createTextureRepeatWithPBORead(edk::uint32 width,
                                        edk::uint32 height,
                                        edk::uint32 mode,
                                        const edk::classID  data = NULL,
                                        edk::uint32 minFilter = GU_NEAREST,
                                        edk::uint32 magFilter = GU_LINEAR
            );
    //draw to the texture
    bool drawToTexture(const edk::classID  data);
    bool drawToTextureRepeat(const edk::classID  data);
    //FILTER
    //        GU_NEAREST
    //        GU_LINEAR
    bool drawToTexture(const edk::classID  data, edk::uint32 minFilter = GU_LINEAR, edk::uint32 magFilter = GU_LINEAR);
    bool drawToTextureRepeat(const edk::classID  data, edk::uint32 minFilter = GU_LINEAR, edk::uint32 magFilter = GU_LINEAR);
    //read the texture

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
    bool readFromTexture(const edk::classID  data,edk::uint32 format = GU_RGB);
    bool readFromTextureRepeat(const edk::classID  data,edk::uint32 format = GU_RGB);

    //GETTERS
    //return the textureID
    edk::uint32 getID();
    //return the texturePBO
    edk::uint32 getPBO();
    size2ui32 getSize();
    //EDK_LUMINANCE 1u
    //EDK_LUMINANCE_ALPHA 2u
    //EDK_RGB  3u
    //EDK_RGBA 4u
    edk::uint32 getModeEDK();
    //GU_RGB
    //GU_RGBA
    //GU_LUMINANCE
    //GU_LUMINANCE_ALPHA
    edk::uint32 getModeGU();
    uint32 width();
    uint32 height();
    edk::uint32 textureID();

    //DELETE
    //remove the texture
    void deleteTexture();
    //delete the ID
    static void deleteTextureID(edk::uint32 id);


    //Super Class Functions
    //retain
    edk::Texture2D* retainObject(edk::Texture2D** pointer);
    //release
    bool releaseObject(edk::Texture2D** pointer);

    //Save the object
    void saveObject(ObjectWithName** pointer);

    //Clean the object
    void cleanObject(ObjectWithName** pointer);
protected:
private:
    //Texture ID
    edk::uint32 textureId;
    //Texture ID
    edk::uint32 pbo;
    //tamanho do sprite
    edk::size2ui32 size;
    //save the mode
    edk::uint32 mode;
    edk::uint32 minFilter;
    edk::uint32 magFilter;
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // TEXTURE2DRENDER_H
