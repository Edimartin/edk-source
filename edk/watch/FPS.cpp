#include "FPS.h"

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

#ifdef WIN32
    //Windows 32
#elif WIN64
    //Windows 64
#elif __linux__
    //Linux
#elif __APPLE__
    //MacOS
#endif


edk::watch::FPS::FPS(){
    //clean the FPS
    this->setFPS(0u);
    this->start();
}

edk::watch::FPS::FPS(uint32 fps){
    //set the new FPS
    this->setFPS(fps);
    this->start();
}

void edk::watch::FPS::start(){
    //clear the clock
    clock.start();
}

void edk::watch::FPS::setFPS(uint32 fps){
    //test if the FPS is not zero
    if(fps){
        //then set the fps
        this->frames = fps;
    }
    else{
        //else set the fps with one
        this->frames=0u;
    }
}

bool edk::watch::FPS::waitForFPS(){
    bool ret=false;
    if(this->frames){
        //calculate the remainder microsecons to get one second
        register edk::int32 wait=(edk::uint32)(((1.0f/(edk::float32)frames))*edk::watch::second) - clock.getMicroseconds();
        if(wait>0){
            //If the distance bigger than zero. He need wait.
        //Windows sleep millisecons
        #if defined(_WIN32) || defined(_WIN64)
            clock.sleepProcessMiliseconds(wait*0.001);
        #else
            clock.sleepProcessMicroseconds(wait);
        #endif

            ret=true;
        }

        //after this he can start a new time count
        start();
    }
    return ret;
}
