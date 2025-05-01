#ifndef EDK_TEXTURE2DRENDER_H
#define EDK_TEXTURE2DRENDER_H

/*
Library Texture2DRender -
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
#pragma message "Inside Texture2DRender"
#endif

#pragma once
#include "GU/GU.h"
#include "Texture2D.h"

#ifdef printMessages
#pragma message "    Compiling Texture2DRender"
#endif

namespace edk{
class Texture2DRender: public edk::Texture2D{
public:
    Texture2DRender();
    virtual ~Texture2DRender();

    void Constructor();
    void Destructor();

    //Load the renderTexture
    bool createRender(edk::size2ui32 size,edk::uint32 filter = GU_NEAREST);
    bool createRender(edk::uint32 width,edk::uint32 height,edk::uint32 filter = GU_NEAREST);
    bool createRender(edk::int32 width,edk::int32 height,edk::uint32 filter = GU_NEAREST);
    //delete render
    void deleteRender();

    //return the ID
    edk::uint32 getBufferID();

    //use this frameBuffer
    void useThisBuffer();
    //dont use frameBuffer
    static void dontUseFrameBuffer();
    //dont use this frameBuffer
    void dontUseThisFrameBuffer();

protected:
private:
    //framebuffer
    edk::uint32 frameBuffer;
    //depthBuffer
    edk::uint32 depthBuffer;

    //delete the frameBuffer
    void deleteFrameBuffer();

    //load the frameBuffer
    bool loadFrameBuffer();
private:
    edk::classID classThis;
};
}//end namespace

#endif // TEXTURE2DRENDER_H
