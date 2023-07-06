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
#pragma message "Inside File"
#endif

#pragma once
#include "String.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "NameClass.h"

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
#include <sys/ioctl.h>
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
#include <sys/ioctl.h>
#ifdef __GNUC__
#ifdef __cplusplus
//G++
#else
//GCC
#endif
#endif
#endif

#ifdef printMessages
#pragma message "    Compiling File"
#endif

namespace edk{
class File{
public:
    File();
    ~File();

    edk::uint64 getFileSize();

    bool openTextFile(edk::char8 *name);

    bool openTextFile(const edk::char8 *name);

    bool openBinFile(edk::char8 *name);

    bool openBinFile(const edk::char8 *name);

    bool openEndTextFile(edk::char8 *name);

    bool openEndTextFile(const edk::char8 *name);

    bool openEndBinFile(edk::char8 *name);

    bool openEndBinFile(const edk::char8 *name);

    //PIPE
    bool openPipe(edk::char8 *name);
    bool openPipe(const edk::char8 *name);

    void closeFile();

    static bool deleteFile(edk::char8 *name);

    static bool deleteFile(const edk::char8 *name);

    bool deleteFile();

    static bool renameFile(edk::char8 *oldName, edk::char8 *newName);

    static bool renameFile(const edk::char8 *oldName, const edk::char8 *newName);

    static bool createFile(edk::char8 *name);

    static bool createFile(const edk::char8 *name);

    //return true if is a file
    static bool isFile(edk::char8 *name);
    static bool isFile(const edk::char8 *name);

    bool createAndOpenTextFile(edk::char8 *name);

    bool createAndOpenTextFile(const edk::char8 *name);

    bool createAndOpenBinFile(edk::char8 *name);

    bool createAndOpenBinFile(const edk::char8 *name);

    //PIPE
    bool createAndOpenPipe(edk::char8* name);
    bool createAndOpenPipe(const edk::char8* name);

    static bool fileExist(edk::char8 *name);

    static bool fileExist(const edk::char8 *name);

    //test if the folder exist in the computer
    static bool folderExist(edk::char8 *name);
    static bool folderExist(const edk::char8 *name);

    bool readEnd();
    bool endOfFile();

    bool writeText(edk::char8 c);

    bool writeText(edk::char8 *str);

    bool writeText(const edk::char8 *str);

    bool writeText(edk::int8 n);

    bool writeText(edk::uint8 n);

    bool writeText(edk::int16 n);

    bool writeText(edk::uint16 n);

    bool writeText(edk::int32 n);

    bool writeText(edk::uint32 n);

    bool writeText(edk::int64 n);

    bool writeText(edk::uint64 n);

    bool writeText(edk::float32 f);

    bool writeText(edk::float32 f,edk::uint8 digits);

    bool writeText(edk::float64 f);

    bool writeText(edk::float64 f,edk::uint8 digits);

    bool writeBin(edk::classID w, edk::uint32 size);

    bool writeBin(edk::char8 c);

    bool writeBin(edk::char8 *str);

    bool writeBin(const edk::char8 *str);

    bool writeBin(edk::int8 n);

    bool writeBin(edk::int8 *n);

    bool writeBin(edk::uint8 n);

    bool writeBin(edk::uint8 *n);

    bool writeBin(edk::int16 n);

    bool writeBin(edk::int16 *n);

    bool writeBin(edk::uint16 n);

    bool writeBin(edk::uint16 *n);

    bool writeBin(edk::int32 n);

    bool writeBin(edk::int32 *n);

    bool writeBin(edk::uint32 n);

    bool writeBin(edk::uint32 *n);

    bool writeBin(edk::float32 f);

    bool writeBin(edk::float32 *f);

    bool writeBin(edk::uint64 n);

    bool writeBin(edk::uint64 *n);

    bool writeBin(edk::int64 n);

    bool writeBin(edk::int64 *n);

    bool writeBin(edk::float64 f);

    bool writeBin(edk::float64 *f);

    bool writeBin(bool b);

    bool writeBin(bool *b);

    edk::char8 readTextChar();

    edk::char8* readTextString(edk::uint32 limit, bool use = false);

    edk::char8* readTextString(edk::uint64 limit, bool use = false);

    edk::char8* readTextString(edk::uint8 limit = 0u, bool use = false);

    edk::char8* readTextString(edk::char8 limit, bool use = false);

    edk::char8* readTextString(edk::char8 *limits, bool use = false);

    edk::char8* readTextString(const edk::char8 *limits, bool use = false);

    //read to a string
    bool readTextString(edk::char8 *str,edk::uint64 size);

    edk::int32 readTextInt();

    edk::uint32 readTextUInt();

    edk::float32 readTextFloat();

    edk::classID readBin(edk::uint64 size);

    edk::uint64 readBin(edk::classID vec,edk::uint64 size);

    edk::char8 readBinChar();

    edk::char8* readBinString(edk::char64 size);

    edk::char8* readBinString(edk::char8 limit, bool use = false);

    edk::char8* readBinString(edk::char8 *limits, bool use = false);

    edk::char8* readBinString(const edk::char8 *limits, bool use = false);

    //read to a string
    edk::uint64 readBinString(edk::char8 *str,edk::uint64 size);

    edk::int8 readBinInt8();

    edk::int8* readBinInt8(edk::int64 size);

    edk::uint8 readBinUInt8();

    edk::uint8* readBinUint8(edk::uint64 size);

    edk::int16 readBinInt16();

    edk::int16* readBinInt16(edk::int16 size);

    edk::uint16 readBinUInt16();

    edk::uint16* readBinUint16(edk::uint16 size);

    edk::int32 readBinInt32();

    edk::int32* readBinInt32(edk::int64 size);

    edk::uint32 readBinUInt32();

    edk::uint32* readBinUint32(edk::uint64 size);

    edk::int64 readBinInt64();

    edk::int64* readBinInt64(edk::int64 size);

    edk::uint64 readBinUInt64();

    edk::uint64* readBinUint64(edk::uint64 size);

    edk::float32 readBinFloat();

    edk::float32* readBinFloat(edk::int64 size);

    edk::int64 readBinLongInt();

    edk::int64* readBinLongInt(edk::int64 size);

    edk::char8* getName();

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
//Class fileStream to read some stream from a file
class FileStream{
public:
    FileStream();
    ~FileStream();

    bool openFileStream(edk::char8* name);
    bool openFileStream(const edk::char8* name);
    bool openFileStreamNonBlock(edk::char8* name);
    bool openFileStreamNonBlock(const edk::char8* name);
    void closeFileStream();

    edk::int64 readVec(edk::classID vec,edk::uint64 size);
    edk::int64 readVec(edk::classID vec,edk::uint32 size);
    edk::char8 readChar8();
    edk::uchar8 readUChar8();
    edk::int8 readInt8();
    edk::uint8 readUInt8();
    edk::int16 readInt16();
    edk::uint16 readUInt16();
    edk::int32 readInt32();
    edk::uint32 readUInt32();
    edk::float32 readFloat32();
    edk::float64 readFloat64();

    edk::int32 ioControl(edk::uint32 __request,void* value);

    edk::char8* getName();

    bool isOpened();
private:
    edk::int32 arq;
    edk::Name name;
};

}//End of namespace edk

#endif // edk_File_h
