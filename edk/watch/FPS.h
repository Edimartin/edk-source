#ifndef EDK_WATCH_FPS_H
#define EDK_WATCH_FPS_H

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

} /* End of namespace edk::ptr */
} /* End of namespace edk */

#endif // edk_ptr_FPS_h
