#include "DebugFile.h"

/*
Library C++ DebugFile - Write debug messages in a file
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

//the file is inline
//edk::File edk::DebugFile::file;

edk::uint64 EDKArrayVectorFreeCounter=0u;

edk::DebugFile::DebugFile(){
    //
}
edk::DebugFile::~DebugFile(){
    //
}

#if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
#else
#endif

bool edk::DebugFile::newFile(const edk::char8* name){
    return edk::DebugFile::newFile((edk::char8*) name);
}
bool edk::DebugFile::newFile(edk::char8*
                             #if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
                             name
                             #endif
                             ){
#if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
    printf("\n%u %s %s edk::File == %lu name == '%s'",__LINE__,__FILE__,__func__,(edk::uint64)&edk::DebugFile::file,name);fflush(stdout);
    //create the file
    if(edk::DebugFile::file.createAndOpenTextFile(name)){
        return true;
    }
#endif
    return false;
}

void edk::DebugFile::closeFile(){
#if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
    edk::DebugFile::file.closeFile();
#endif
}
