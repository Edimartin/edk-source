#ifndef FILETOH_H
#define FILETOH_H

/*
Library FileToH - Write a bin file to a H header
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
#warning "Inside FileToH"
#endif

#pragma once
#include "string.h"
//include file
#include "DebugFile.h"

#ifdef printMessages
#warning "    Compiling FileToH"
#endif

namespace edk{
class FileToH{
public:
    FileToH();
    static bool writeToFile(edk::char8* fileName,edk::uint32 lineSize);
    static bool writeToFile(const edk::char8* fileName,edk::uint32 lineSize);
    static bool writeToEDKFile(edk::char8* fileName,edk::uint32 lineSize);
    static bool writeToEDKFile(const edk::char8* fileName,edk::uint32 lineSize);
//private:
    //read the name without the extension
    static edk::char8* readFileName(edk::char8* fileName);
};
}//edn namespace edk

#endif // FILETOH_H
