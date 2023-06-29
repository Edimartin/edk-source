#ifndef MEMORYBUFFER_H
#define MEMORYBUFFER_H

/*
Library C++ MemoryBuffer - Use a buffer in RAM memory
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
#pragma message "Inside MemoryBuffer"
#endif

#pragma once
#include "DebugFile.h"
#include "TypeVars.h"
#include "String.h"

#ifdef printMessages
#pragma message "    Compiling MemoryBuffer"
#endif

namespace edk{
class MemoryBuffer{
public:
    MemoryBuffer();
    ~MemoryBuffer();

    //clean the buffer
    void clean();

    //save some bytes in the buffer
    bool writeToBuffer(edk::uint8* vector,edk::uint64 size);

    //return the buffer pointer
    edk::classID getPointer();
    edk::classID pointer();
    //return the size of the buffer writed
    edk::uint64 getSize();
    edk::uint64 size();
private:
    //buffer memory
    edk::uint8* buffer;
    edk::uint64 bufferSize;
    edk::uint64 bufferWritedSize;
};
}//end namespace edk

#endif // MEMORYBUFFER_H
