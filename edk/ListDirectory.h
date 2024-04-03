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
#pragma message "Inside ListDirectory"
#endif

#pragma once
#include <stdio.h>
#include "TypeVars.h"
#include "String.h"
#include <sys/stat.h>
#include <dirent.h>
#include "DebugFile.h"
#include "vector/Stack.h"
#include "NameClass.h"

#ifdef printMessages
#pragma message "    Compiling ListDirectory"
#endif

namespace edk{
class ListDirectory{
public:
    ListDirectory();
    ~ListDirectory();

    void clean();

    //start listing the folders and files in a directory received by function parameter
    bool run(edk::char8* directory);
    bool run(const edk::char8* directory);
    bool runFilesOnly(edk::char8* directory);
    bool runFilesOnly(const edk::char8* directory);
    bool runFoldersOnly(edk::char8* directory);
    bool runFoldersOnly(const edk::char8* directory);

    //get files
    edk::uint32 getFilesSize();
    edk::char8* getFileName(edk::uint32 position);
    edk::uint64 getFileLastModify(edk::uint32 position);
    edk::uint64 getFileSize(edk::uint32 position);
    void cleanFiles();
    //get folders
    edk::uint32 getFoldersSize();
    edk::char8* getFolderName(edk::uint32 position);
    edk::uint64 getFolderLastModify(edk::uint32 position);
    edk::uint64 getFolderSize(edk::uint32 position);
    void cleanFolders();

    virtual void listFile(edk::char8* name,edk::uint64 lastModify,edk::uint64 size);
    virtual void listFolder(edk::char8* name,edk::uint64 lastModify,edk::uint64 size);
private:
    //class to read the files and folders
    class FileOrFolders{
    public:
        FileOrFolders(){
            this->lastModify = this->size = 0u;
        }
        FileOrFolders(edk::char8* name,edk::uint64 lastModify,edk::uint64 size){
            this->lastModify = lastModify;
            this->size = size;
            this->name.setName(name);
        }
        ~FileOrFolders(){
            this->name.cleanName();
        }
        edk::ListDirectory::FileOrFolders operator=(edk::ListDirectory::FileOrFolders name){
            this->name.clone(name.name);
            this->lastModify = name.lastModify;
            this->size = name.size;
            name.name.cantDelete();
            return name;
        }
        edk::Name name;
        edk::uint64 lastModify;
        edk::uint64 size;
    };
    //stack for files and folders
    edk::vector::Stack<edk::ListDirectory::FileOrFolders*> files;
    edk::vector::Stack<edk::ListDirectory::FileOrFolders*> folders;
};
}//end namespace

#endif // LISTDIRECTORY_H
