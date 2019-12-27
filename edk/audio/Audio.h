#ifndef EDK_AUDIO_H
#define EDK_AUDIO_H

/*
Library Audio - Play audio using SFML
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
#warning "Inside Audio"
#endif

#pragma once
#include "../File.h"
#include <SFML/Audio.hpp>
#include "../String.h"
//Use the AudioList
#include "AudioList.h"
#include "../TypeDefines.h"
#include "../pack/FilePackage.h"

#ifdef printMessages
#warning "    Compiling Audio"
#endif

/*LIBS

-lsfml-audio

*/

namespace edk{
//Audio Status Type
typedef edk::uint32    AudioStatus;
//Class
class Audio{
    public:
        Audio();
        virtual ~Audio();

        //OPEN
        virtual bool open(const char* name);
        virtual bool open(edk::char8* name);
        virtual bool openFromMemory(const char* name,edk::classID vector,edk::uint32 size);
        virtual bool openFromMemory(edk::char8* name,edk::classID vector,edk::uint32 size);
        virtual bool openFromPack(edk::pack::FilePackage* pack,const char* name);
        virtual bool openFromPack(edk::pack::FilePackage* pack,edk::char8* name);
        void close();

        //SETERS
        //Set the second to start read the audio
        bool setSecond(edk::float32 second);
        //Set if audio reproduce looping
        void setLoop(bool loop);
        void loopOn();
        void loopOff();
        //set the audio volume
        void setVolume(edk::float32 volume);
        //Set the audio reproduction speed
        void setSpeed(edk::float32 speed);

        //GETERS
        //return the status of the audio
        edk::AudioStatus getStatus();
        //return the second of the audio process
        edk::float32 getSecond();
        //return if are loping the audio
        bool getLoop();
        //return the audio volume
        edk::float32 getVolume();
        //return the speed of audio processing
        edk::float32 getSpeed();
        //get the audioChannels
        edk::uint32 getChannels();
        //retoena a duracao do audio
        edk::float32 getDuration();
        //return true if is playing
        bool isPlaying();
        //return true if is paused
        bool isPaused();
        //return true if is stopped
        bool isStopped();

        //test if have audio
        bool haveAudio();

        //INTERACT
        //Play
        bool play();
        bool playInSecond(edk::float32 second);
        //Stop
        bool stop();
        //Pause
        bool pause();
        bool pauseOn();
        bool pauseOff();

        //INCREMENT DECREMENT
        //increment the volume
        void volumeUp(edk::float32 volume);
        //decrement the volume
        void volumeDown(edk::float32 volume);

        //increment the speed
        void speedUp(edk::float32 speed);
        //decrement the speed
        void speedDown(edk::float32 speed);
    protected:
        //Possui o buffer de audio da SFML
        //sf::SoundBuffer *buffer;
        edk::AudioBuffer* buffer;
        //E possui o manipulador de audio
        sf::Sound *sound;
        //audio list to load the buffer
        edk::AudioList list;
    private:
};
}//end namespace edk

#endif // AUDIO_H
