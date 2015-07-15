#ifndef EDK_AUDIOBUFFER_H
#define EDK_AUDIOBUFFER_H

/*
Library AudioBuffer - Load an entire audio file
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
#warning "Inside AudioBuffer"
#endif

#pragma once
#include "../File.h"
#include "../String.h"
#include <SFML/Audio.hpp>
#include "../Object.h"

#ifdef printMessages
#warning "    Compiling AudioBuffer"
#endif

/* LIB

-lsfml-audio

*/

namespace edk{
class AudioBuffer : public edk::ObjectWithName{
    public:
        AudioBuffer();
        virtual ~AudioBuffer();

        //LOAD
        //load the buffer from a file
        bool loadBufferFromFile(const char* name);
        bool loadBufferFromFile(edk::char8* name);

        //DELETE
        //delete the buffer
        void deleteBuffer();

        //GETER
        //return the buffer pointer
        sf::SoundBuffer* getBufferPointer();
        //return the channels
        edk::uint32 getChannels();
        //return the audio duration
        edk::float32 getDuration();
    protected:
    private:
        //Possui o buffer de audio da SFML
        sf::SoundBuffer* buffer;
};
}//end namespace edk

#endif // AUDIOBUFFER_H
