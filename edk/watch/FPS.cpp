#include "FPS.h"

/*
Library C++ FPS - Control frames per second.
Copyright (C) 1013 Eduardo Moura Sales Martins
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

#ifdef WIN32
    //Windows 32
#elif WIN64
    //Windows 64
#elif __linux__
    //Linux
#elif __APPLE__
    //MacOS
#endif

namespace edk {
namespace watch {




FPS::FPS(){
    //clean the FPS
    this->setFPS(0u);
    this->start();
}

FPS::FPS(uint32 fps){
    //set the new FPS
    this->setFPS(fps);
    this->start();
}

void FPS::start(){
    //clear the clock
    clock.start();
}

void FPS::setFPS(uint32 fps){
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

bool FPS::waitForFPS(){
    bool ret=false;
    if(this->frames){
        //calculate the remainder microsecons to get one second
        register edk::int32 wait=(edk::uint32)(((1.0f/(float)frames))*edk::watch::second) - clock.getMicroseconds();
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

} /* End of namespace edk::ptr */
} /* End of namespace edk */
