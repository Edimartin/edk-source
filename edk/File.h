#ifndef edk_File_h
#define edk_File_h

/*
Library File - Read and Write Files using C ANSI
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
#warning "Inside File"
#endif

#pragma once
#include "String.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#ifdef _WIN32
    //Windows 32
    #ifdef _MSC_VER
        //Visual C
    #endif
    #ifdef __GNUC__
        #ifdef __cplusplus
            //G++
        #else
            //GCC
        #endif
    #endif
#endif
#ifdef _WIN64
    //Windows 64
    #ifdef _MSC_VER
        //Visual C
    #endif
    #ifdef __GNUC__
        #ifdef __cplusplus
            //G++
        #else
            //GCC
        #endif
    #endif
#endif
#ifdef __linux__
    //LINUX
    #ifdef __GNUC__
        #ifdef __cplusplus
            //G++
        #else
            //GCC
        #endif
    #endif
#endif
#ifdef __APPLE__
    //MACOS
    #ifdef __GNUC__
        #ifdef __cplusplus
            //G++
        #else
            //GCC
        #endif
    #endif
#endif

//#include "String.h"

#ifdef printMessages
#warning "    Compiling File"
#endif

namespace edk {

class File {

 public:

    File();

    ~File();

    uint64 getFileSize();

    bool openTextFile(char8 *name);

    bool openTextFile(const edk::char8 *name);

    bool openBinFile(char8 *name);

    bool openBinFile(const edk::char8 *name);

    bool openEndTextFile(char8 *name);

    bool openEndTextFile(const edk::char8 *name);

    bool openEndBinFile(char8 *name);

    bool openEndBinFile(const edk::char8 *name);

    //PIPE
    bool openPipe(char8 *name);
    bool openPipe(const edk::char8 *name);

    void closeFile();

    static bool deleteFile(char8 *name);

    static bool deleteFile(const edk::char8 *name);

    bool deleteFile();

    static bool renameFile(char8 *oldName, char8 *newName);

    static bool renameFile(const edk::char8 *oldName, const edk::char8 *newName);

    static bool createFile(char8 *name);

    static bool createFile(const edk::char8 *name);

    //return true if is a file
    static bool isFile(edk::char8 *name);
    static bool isFile(const edk::char8 *name);

    bool createAndOpenTextFile(char8 *name);

    bool createAndOpenTextFile(const edk::char8 *name);

    bool createAndOpenBinFile(char8 *name);

    bool createAndOpenBinFile(const edk::char8 *name);

    //PIPE
    bool createAndOpenPipe(char8* name);
    bool createAndOpenPipe(const edk::char8* name);

    static bool fileExist(char8 *name);

    static bool fileExist(const edk::char8 *name);

    bool readEnd();
    bool endOfFile();

    bool writeText(char8 c);

    bool writeText(char8 *str);

    bool writeText(const edk::char8 *str);

    bool writeText(int8 n);

    bool writeText(uint8 n);

    bool writeText(int16 n);

    bool writeText(uint16 n);

    bool writeText(int32 n);

    bool writeText(uint32 n);

    bool writeText(int64 n);

    bool writeText(uint64 n);

    bool writeText(edk::float32 f);

    bool writeText(edk::float64 f);

    bool writeBin(classID w, edk::uint32 size);

    bool writeBin(char8 c);

    bool writeBin(char8 *str);

    bool writeBin(const edk::char8 *str);

    bool writeBin(int8 n);

    bool writeBin(int8 *n);

    bool writeBin(uint8 n);

    bool writeBin(uint8 *n);

    bool writeBin(int16 n);

    bool writeBin(int16 *n);

    bool writeBin(uint16 n);

    bool writeBin(uint16 *n);

    bool writeBin(int32 n);

    bool writeBin(int32 *n);

    bool writeBin(uint32 n);

    bool writeBin(uint32 *n);

    bool writeBin(edk::float32 f);

    bool writeBin(edk::float32 *f);

    bool writeBin(edk::uint64 n);

    bool writeBin(edk::uint64 *n);

    bool writeBin(int64 n);

    bool writeBin(int64 *n);

    bool writeBin(edk::float64 f);

    bool writeBin(edk::float64 *f);

    bool writeBin(bool b);

    bool writeBin(bool *b);

    char8 readTextChar();

    char8* readTextString(edk::uint32 limit, bool use = false);

    char8* readTextString(edk::uint64 limit, bool use = false);

    char8* readTextString(edk::uint8 limit = 0u, bool use = false);

    char8* readTextString(char8 limit, bool use = false);

    char8* readTextString(char8 *limits, bool use = false);

    char8* readTextString(const edk::char8 *limits, bool use = false);

    //read to a string
    bool readTextString(char8 *str,edk::uint64 size);

    int32 readTextInt();

    uint32 readTextUInt();

    edk::float32 readTextFloat();

    classID readBin(uint64 size);

    edk::uint64 readBin(classID vec,uint64 size);

    char8 readBinChar();

    char8* readBinString(char64 size);

    char8* readBinString(char8 limit, bool use = false);

    char8* readBinString(char8 *limits, bool use = false);

    char8* readBinString(const edk::char8 *limits, bool use = false);

    //read to a string
    edk::uint64 readBinString(char8 *str,edk::uint64 size);

    int8 readBinInt8();

    int8* readBinInt8(int64 size);

    uint8 readBinUInt8();

    uint8* readBinUint8(uint64 size);

    int16 readBinInt16();

    int16* readBinInt16(int16 size);

    uint16 readBinUInt16();

    uint16* readBinUint16(uint16 size);

    int32 readBinInt32();

    int32* readBinInt32(int64 size);

    uint32 readBinUInt32();

    uint32* readBinUint32(uint64 size);

    int64 readBinInt64();

    int64* readBinInt64(int64 size);

    uint64 readBinUInt64();

    uint64* readBinUint64(uint64 size);

    edk::float32 readBinFloat();

    edk::float32* readBinFloat(int64 size);

    int64 readBinLongInt();

    int64* readBinLongInt(int64 size);

    char8* getName();

    //SEEK the file
    bool seek(edk::uint32 bytes);
    bool seek(edk::uint64 bytes);
    bool seek(edk::int32 bytes);
    bool seek(edk::int64 bytes);
    bool seekStart();
    bool seekStart64();
    bool seekStart(edk::uint32 bytes);
    bool seekStart(edk::uint64 bytes);
    bool seekEnd();
    bool seekEnd64();
    bool seekEnd(edk::int32 bytes);
    bool seekEnd(edk::int64 bytes);
    //return this current position
    edk::uint32 getSeek32();
    edk::uint64 getSeek64();

    //flush the file
    bool flush();

    bool isOpened();

 private:
    //Read the string from the file
    edk::char8* readStringFromTheFile(FILE* arq,edk::char8 limit,edk::uint32 count,bool use = false);
    edk::char8* readStringFromTheFile(FILE* arq,edk::char8* limits,edk::uint32 count,bool use = false);
    edk::char8* readStringFromTheBinFile(FILE* arq,edk::char8 limit,edk::uint32 count,bool use = false);
    edk::char8* readStringFromTheBinFile(FILE* arq,edk::char8* limits,edk::uint32 count,bool use = false);


     //Pointer to the FILE.
    FILE* arq;


    //size of the file.
    edk::uint64 size;


    //name of the file.
    edk::char8 *name;
};

} /* End of namespace edk */

#endif // edk_File_h
