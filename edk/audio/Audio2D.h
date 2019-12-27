#ifndef EDK_AUDIO2D_H
#define EDK_AUDIO2D_H

/*
Library Audio2D - edk::Audio in a 2D World
Copyright (C) 2013 Eduardo Moura Sales Martins
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
#warning "Inside Audio2D"
#endif

#pragma once
#include "../TypeVec2.h"
#include "Audio.h"

#ifdef printMessages
#warning "    Compiling Audio2D"
#endif

namespace edk{
class Audio2D : public edk::Audio{
    public:
        Audio2D();
        virtual ~Audio2D();

        //OPEN
        bool open(const char* name);
        bool open(edk::char8* name);
        bool openFromMemory(const char* name,edk::classID vector,edk::uint32 size);
        bool openFromMemory(edk::char8* name,edk::classID vector,edk::uint32 size);
        bool openFromPack(edk::pack::FilePackage* pack,const char* name);
        bool openFromPack(edk::pack::FilePackage* pack,edk::char8* name);

        //Set the listener position
        static void setListenerPosition2D(edk::vec2f32 position);
        //Set the listener lookAt
        static void setListenerLookAt2D(edk::vec2f32 lookAt);

        //SETERS
        //Set the position of the audio in the cene
        bool setPosition2D(edk::vec2f32 position);
        //set if are using the listener
        bool useListener(bool use);

        //GETERS
        //return if are using the listener
        bool usingListener();
    protected:
    private:
    //save if are using the listener
    bool haveListener;
    //save the audio position
    edk::vec2f32 position;
};
}//end namespace edk

#endif // AUDIO2D_H
