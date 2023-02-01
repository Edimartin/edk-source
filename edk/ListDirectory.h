#ifndef LISTDIRECTORY_H
#define LISTDIRECTORY_H

/*
Library C++ ListDirectory - List files and folders inside a directory
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
#warning "Inside ListDirectory"
#endif

#pragma once
#include <stdio.h>
#include "TypeVars.h"
#include "DebugFile.h"
#include "String.h"
#include <sys/stat.h>
#include <dirent.h>

#ifdef printMessages
#warning "    Compiling ListDirectory"
#endif

namespace edk{
class ListDirectory{
public:
    ListDirectory();
    ~ListDirectory();

    //start listing the folders and files in a directory received by function parameter
    bool run(edk::char8* directory);
    bool run(const edk::char8* directory);

    virtual void listFile(edk::char8* name,edk::uint64 lastModify,edk::uint64 size)=0;
    virtual void listFolder(edk::char8* name,edk::uint64 lastModify,edk::uint64 size)=0;
};
}//end namespace

#endif // LISTDIRECTORY_H
