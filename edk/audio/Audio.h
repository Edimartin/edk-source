#ifndef EDK_AUDIO_H
#define EDK_AUDIO_H

/*
Library Audio - Play audio using SFML
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
#pragma message "Inside Audio"
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
#pragma message "    Compiling Audio"
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
        virtual bool open(const edk::char8* name);
        virtual bool open(edk::char8* name);
        virtual bool openFromMemory(const edk::char8* name,edk::classID vector,edk::uint32 size);
        virtual bool openFromMemory(edk::char8* name,edk::classID vector,edk::uint32 size);
        virtual bool openFromPack(edk::pack::FilePackage* pack,const edk::char8* name);
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
