#ifndef EDK_AUDIO2D_H
#define EDK_AUDIO2D_H

/*
Library Audio2D - edk::Audio in a 2D World
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
#pragma message "Inside Audio2D"
#endif

#pragma once
#include "../TypeVec2.h"
#include "Audio.h"

#ifdef printMessages
#pragma message "    Compiling Audio2D"
#endif

namespace edk{
class Audio2D : public edk::Audio{
public:
    Audio2D();
    virtual ~Audio2D();

    void Constructor();
    void Destructor();

    //OPEN
    bool open(const edk::char8* name);
    bool open(edk::char8* name);
    bool openFromMemory(const edk::char8* name,edk::classID vector,edk::uint32 size);
    bool openFromMemory(edk::char8* name,edk::classID vector,edk::uint32 size);
    bool openFromPack(edk::pack::FilePackage* pack,const edk::char8* name);
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
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // AUDIO2D_H
