#ifndef SHA256_H
#define SHA256_H

/*
Library C++ SHA256 - Encrypt string in SHA256
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
#warning "Inside SHA256"
#endif

#pragma once
#include <stdio.h>
#include "../TypeVars.h"
#ifndef __cplusplus
#include <stdlib.h>
#endif
#include "../String.h"
#include "../DebugFile.h"
#include "../TypeDefines.h"

#ifdef printMessages
#warning "    Compiling SHA256"
#endif

namespace edk{
namespace encrypt{
class SHA256{
public:
    SHA256();
    ~SHA256();

    //process the SHA256
    static bool convertTo(edk::char8 *pass, edk::uint32 size, edk::char8 *dest);
    static bool convertTo(const edk::char8 *pass, edk::uint32 size, edk::char8 *dest);
    static bool convertTo(edk::char8 *pass, edk::char8 *dest);
    static bool convertTo(const edk::char8 *pass, edk::char8 *dest);
    static bool convertFileTo(edk::File* file, edk::char8 *dest);
    static bool convertFileTo(edk::char8 *fileName, edk::char8 *dest);
    static bool convertFileTo(const edk::char8 *fileName, edk::char8 *dest);
    static bool convertTo(edk::char8 *pass, edk::uint32 size, edk::uint8 dest[32u]);
    static bool convertTo(const edk::char8 *pass, edk::uint32 size, edk::uint8 dest[32u]);
    static bool convertTo(edk::char8 *pass, edk::uint8 dest[32u]);
    static bool convertTo(const edk::char8 *pass, edk::uint8 dest[32u]);
    static bool convertFileTo(edk::File* file, edk::uint8 dest[32u]);
    static bool convertFileTo(edk::char8 *fileName, edk::uint8 dest[32u]);
    static bool convertFileTo(const edk::char8 *fileName, edk::uint8 dest[32u]);
    static edk::char8* convert(edk::char8 *pass, edk::uint32 size);
    static edk::char8* convert(const edk::char8 *pass, edk::uint32 size);
    static edk::char8* convert(edk::char8 *pass);
    static edk::char8* convert(const edk::char8 *pass);
    static edk::char8* convertFile(edk::File* file);
    static edk::char8* convertFile(edk::char8 *fileName);
    static edk::char8* convertFile(const edk::char8 *fileName);
};
}//end namespace encrypt
}//end namespace edk

#endif // SHA256_H
