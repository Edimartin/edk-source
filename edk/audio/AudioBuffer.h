#ifndef EDK_AUDIOBUFFER_H
#define EDK_AUDIOBUFFER_H

/*
Library AudioBuffer - Load an entire audio file
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
#pragma message "Inside AudioBuffer"
#endif

#pragma once
#include "../File.h"
#include "../String.h"
#include <SFML/Audio.hpp>
#include "../Object.h"
#include "../pack/FilePackage.h"
#include "../thread/Mutex.h"

#ifdef printMessages
#pragma message "    Compiling AudioBuffer"
#endif

/* LIB

-lsfml-audio

*/

namespace edk{
class AudioBuffer : public edk::ObjectWithName{
public:
    AudioBuffer();
    virtual ~AudioBuffer();

    void Constructor();
    void Destructor();

    //LOAD
    //load the buffer from a file
    bool loadBufferFromFile(const edk::char8* name);
    bool loadBufferFromFile(edk::char8* name);
    bool loadBufferFromMemory(const edk::char8* name,edk::classID vector,edk::uint32 size);
    bool loadBufferFromMemory(edk::char8* name,edk::classID vector,edk::uint32 size);
    bool loadBufferFromPack(edk::pack::FilePackage* pack,const edk::char8* name);
    bool loadBufferFromPack(edk::pack::FilePackage* pack,edk::char8* name);

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
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // AUDIOBUFFER_H
