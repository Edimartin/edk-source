#ifndef EDK_WATCH_FPS_H
#define EDK_WATCH_FPS_H

/*
Library C++ FPS - Control frames per second.
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
#warning "Inside FPS"
#endif

#pragma once
#include "../TypeVars.h"
#include "Time.h"

#ifdef printMessages
#warning "    Compiling FPS"
#endif

namespace edk {
namespace watch {

class FPS {

 public:

    FPS();

    FPS(uint32 fps);

    void start();

    void setFPS(uint32 fps);

    bool waitForFPS();

    edk::uint32 getFPS(){return frames;}


 private:

    /**
     *  FPS user a clock to control the how much time are the FPS.
     */
    edk::watch::Time clock;

    /**
     *  The frames set how much times the code will be processed in one second.
     */
    edk::uint32 frames;
};

} /* End of namespace watch */
} /* End of namespace edk */

#endif // edk_ptr_FPS_h
