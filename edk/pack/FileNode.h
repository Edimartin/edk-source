#ifndef FILENODE_H
#define FILENODE_H

/*
FileNode - Node used in FilePackage with the Name, position and size of the file inside the package.
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
#warning "Inside pack::FileNode"
#endif

#pragma once
#include "../NameClass.h"
#include "../TypeVars.h"
#include "../DebugFile.h"
#include "../File.h"

#ifdef printMessages
#warning "    Compiling pack::FileNode"
#endif

namespace edk{
namespace pack{
class FilePackage;
class FileNode{
public:
    FileNode();
    virtual ~FileNode();

    friend edk::pack::FilePackage;

    //set the fileName
    bool setFileName(edk::char8* str);
    bool setFileName(const edk::char8* str);
    //return the fileName
    edk::char8* getFileName();
    edk::char8* getStrName();
    //clean the name
    void cleanName();
    void clean();

    void setPosition(edk::uint64 position);
    edk::uint64 getPosition();
    void setFileSize(edk::uint64 fileSize);
    edk::uint64 getFileSize();

    //return the size of the node
    edk::uint64 getSize();
    edk::uint64 size();

    //return true if this fileNode is bigger then the other node
    bool biggerThan(edk::pack::FileNode* node);
    bool equalThan(edk::pack::FileNode* node);

    void print();

    //write the node to the file
    bool writeFile(edk::File* file);
    bool readFile(edk::File* file);
private:
    edk::Name str;
    edk::Name fileName;
    edk::uint64 position;
    edk::uint64 fileSize;
    //MD5 code from the file
    edk::uint8 md5[16u];
    //clean the md5 code
    void cleanMD5();
    //compare the md5
    bool compareMD5(edk::uint8 md5[16u]);
    //print the md5
    void printMD5(edk::uint8 md5[16u]);
};
}
}

#endif // FILENODE_H
