#ifndef AUDIOLIST_H
#define AUDIOLIST_H

/*
Library AudioBuffer - List of Audios used in the gameEngine
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
#pragma message "Inside AudioList"
#endif

#pragma once
#include "AudioBuffer.h"
#include "../vector/BinaryTree.h"
#include "../Object.h"
#include "../pack/FilePackage.h"

#ifdef printMessages
#pragma message "    Compiling AudioList"
#endif

namespace edk{
class AudioList{
    public:
        AudioList();
        virtual ~AudioList();

        //LOAD
        //Load the audio. If are loaded, just return the
        bool loadAudio(const edk::char8* name, edk::AudioBuffer** retainAudio);
        bool loadAudio(edk::char8* name, edk::AudioBuffer** retainAudio);
        bool loadAudioFromMemory(const edk::char8* name,edk::classID vector,edk::uint32 size, edk::AudioBuffer** retainAudio);
        bool loadAudioFromMemory(edk::char8* name,edk::classID vector,edk::uint32 size, edk::AudioBuffer** retainAudio);
        bool loadAudioFromPack(edk::pack::FilePackage* pack,const edk::char8* name, edk::AudioBuffer** retainAudio);
        bool loadAudioFromPack(edk::pack::FilePackage* pack,edk::char8* name, edk::AudioBuffer** retainAudio);
        //remove audio. Release the audio file
        bool removeAudio(edk::AudioBuffer** retainAudio);
        //delete the audioBuffer
        void deleteAudio(edk::AudioBuffer* retainAudio);

    protected:
    private:
};
}//and namespace edk

#endif // AUDIOLIST_H
