#ifndef edk_File_h
#define edk_File_h

/*
Library File - Read and Write Files using C ANSI
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#pragma once
#include "String.h"
#include <stdio.h>
#include <string.h>

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

namespace edk {

class File {

 public:

    File();

    ~File();

    uint64 getFileSize();

    bool openTextFile(char8 *name);

    bool openTextFile(const char *name);

    bool openBinFile(char8 *name);

    bool openBinFile(const char *name);

    bool openEndTextFile(char8 *name);

    bool openEndTextFile(const char *name);

    bool openEndBinFile(char8 *name);

    bool openEndBinFile(const char *name);

    //PIPE
    bool openPipe(char8 *name);
    bool openPipe(const char *name);

    void closeFile();

    static bool deleteFile(char8 *name);

    static bool deleteFile(const char *name);

    bool deleteFile();

    static bool renameFile(char8 *oldName, char8 *newName);

    static bool renameFile(const char *oldName, const char *newName);

    static bool createFile(char8 *name);

    static bool createFile(const char *name);

    bool createAndOpenTextFile(char8 *name);

    bool createAndOpenTextFile(const char *name);

    bool createAndOpenBinFile(char8 *name);

    bool createAndOpenBinFile(const char *name);

    //PIPE
    bool createAndOpenPipe(char8* name);
    bool createAndOpenPipe(const char* name);

    static bool fileExist(char8 *name);

    static bool fileExist(const char *name);

    bool readEnd();
    bool endOfFile();

    bool writeText(char8 c);

    bool writeText(char8 *str);

    bool writeText(const char *str);

    bool writeText(int32 n);

    bool writeText(uint32 n);

    bool writeText(edk::float32 f);

    bool writeBin(classID w, edk::uint32 size);

    bool writeBin(char8 c);

    bool writeBin(char8 *str);

    bool writeBin(const char *str);

    bool writeBin(int32 n);

    bool writeBin(int32 *n);

    bool writeBin(uint32 n);

    bool writeBin(uint32 *n);

    bool writeBin(edk::float32 f);

    bool writeBin(edk::float32 *f);

    bool writeBin(int64 n);

    bool writeBin(int64 *n);

    char8 readTextChar();

    char8* readTextString(edk::uint32 limit, bool use = false);

    char8* readTextString(edk::uint64 limit, bool use = false);

    char8* readTextString(edk::uint8 limit = 0u, bool use = false);

    char8* readTextString(char8 limit, bool use = false);

    char8* readTextString(char8 *limits, bool use = false);

    char8* readTextString(const char *limits, bool use = false);

    int32 readTextInt();

    uint32 readTextUInt();

    edk::float32 readTextFloat();

    classID readBin(uint64 size);

    bool readBin(classID vec,uint64 size);

    char8 readBinChar();

    char8* readBinString(char64 size);

    char8* readBinString(char8 limit, bool use = false);

    char8* readBinString(char8 *limits, bool use = false);

    char8* readBinString(const char *limits, bool use = false);

    int32 readBinInt32();

    int32* readBinInt32(int64 size);

    uint32 readBinUInt32();

    uint32* readBinUint32(uint64 size);

    edk::float32 readBinFloat();

    float* readBinFloat(int64 size);

    int64 readBinLongInt();

    int64* readBinLongInt(int64 size);

    char8* getName();

    //SEEK the file
    bool seek(edk::uint32 bytes);
    bool seek(edk::uint64 bytes);
    bool seek(edk::int32 bytes);
    bool seek(edk::int64 bytes);
    bool seekStart();
    bool seekStart(edk::uint32 bytes);
    bool seekStart(edk::uint64 bytes);
    bool seekEnd();
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
