#ifndef EDK_STRING_H
#define EDK_STRING_H

/*
Library C++ String - Manipulate char vectors.
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
#pragma message "Inside String"
#endif

#pragma once
#include "TypeVars.h"
#include "TypeSize2.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "./BinaryConverter.h"

#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>
//windows.h para clipboard
#include <tchar.h>
#include <windows.h>
#if defined(_MSC_VER)
//
//Getch on Visual C
int edkGetch(void);
//Kbhit on Visual C
int edkKbhit(void);
#endif

#elif defined(__linux__) || defined(__APPLE__)
//
//includes para a getch no linux
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

//Getch no linux
int edkGetch(void);
//Kbhit no linux
int edkKbhit(void);
#endif

#ifdef printMessages
#pragma message "    Compiling String"
#endif

namespace edk {
class TTY{
public:
    TTY();
    ~TTY();

    bool initTerminal();
    bool resetTerminal();
private:
    bool haveInit;
};

class String {

public:
    //TTY to construct and destruct
    static edk::TTY tty;

    static edk::float32 strToFloat32(const edk::char8 *str);

    static edk::float32 strToFloat32(edk::char8 *str);

    static edk::int64 strToInt64(edk::char8 *str);

    static edk::int64 strToInt64(const edk::char8 *str);

    static edk::float64 strToFloat64(edk::char8 *str);

    static edk::float64 strToFloat64(const char *str);

    static bool strToVecInt8(edk::char8* str,edk::int8* vec,edk::uint32 size);

    static bool strToVecInt16(edk::char8* str,edk::int16* vec,edk::uint32 size);

    static bool strToVecInt32(edk::char8* str,edk::int32* vec,edk::uint32 size);

    static bool strToVecInt64(edk::char8* str,edk::int64* vec,edk::uint32 size);

    static bool strToVecUint8(edk::char8* str,edk::uint8* vec,edk::uint32 size);

    static bool strToVecUint16(edk::char8* str,edk::uint16* vec,edk::uint32 size);

    static bool strToVecUint32(edk::char8* str,edk::uint32* vec,edk::uint32 size);

    static bool strToVecUint64(edk::char8* str,edk::uint64* vec,edk::uint32 size);

    static bool strToVecfloat32(edk::char8* str,edk::float32* vec,edk::uint32 size);

    static bool strToVecfloat64(edk::char8* str,edk::float64* vec,edk::uint32 size);

    static edk::int32 strToInt32(edk::char8 *str);

    static edk::int32 strToInt32(const edk::char8 *str);

#if defined(_WIN32) || defined(_WIN64)
    //Convert String to TCHAR from Windows
    static TCHAR* strToTCHAR(const edk::char8* str);
    static TCHAR* strToTCHAR(edk::char8* str);
#endif

    //str32ToStr convert a vector with 32bit characters to a string UTF8
    static bool str32ToUtf8(edk::char32 *str32,edk::char8* str);
    static bool str32ToUtf8(edk::char32 *str32,edk::uint32 size,edk::char8* str);
    static bool str32ToUtf8(const edk::char32 *str32,edk::char8* str);
    static bool str32ToUtf8(const edk::char32 *str32,edk::uint32 size,edk::char8* str);
    static bool str32ToUtf8(edk::char32 *str32,const edk::char8* str);
    static bool str32ToUtf8(edk::char32 *str32,edk::uint32 size,const edk::char8* str);
    static bool str32ToUtf8(const edk::char32 *str32,const edk::char8* str);
    static bool str32ToUtf8(const edk::char32 *str32,edk::uint32 size,const edk::char8* str);
    //str32ToStr convert a vector with 32bit characters to a string UTF8 and return it as a new string
    static edk::char8* str32ToUtf8(edk::char32 *str32,edk::uint32 size);
    static edk::char8* str32ToUtf8(const edk::char32 *str32,edk::uint32 size);
    static edk::char8* str32ToUtf8(edk::char32 *str32);
    static edk::char8* str32ToUtf8(const edk::char32 *str32);
    //return the size of characters using 32 bits per character
    static edk::uint32 str32Size(edk::char32 *str);
    static edk::uint32 str32Size(const edk::char32 *str);
    //return the size of a vector with 32bit charaters
    static edk::uint32 str32ToUtf8Size(edk::char32 *str32,edk::uint32 size);
    static edk::uint32 str32ToUtf8Size(const edk::char32 *str32,edk::uint32 size);
    //convert utf8 to ascii
    static bool utf8ToStr(edk::char8 *utf8,edk::uint32 size,edk::char8 *str);
    static bool utf8ToStr(const edk::char8 *utf8,edk::uint32 size,edk::char8 *str);
    static edk::char8* utf8ToStr(edk::char8 *utf8,edk::uint32 size);
    static edk::char8* utf8ToStr(const edk::char8 *utf8,edk::uint32 size);
    static edk::char8* utf8ToStr(edk::char8 *utf8);
    static edk::char8* utf8ToStr(const edk::char8 *utf8);
    //return the size of a utf8 string
    static edk::uint32 utf8Size(edk::char8 *utf8);
    static edk::uint32 utf8Size(const edk::char8 *utf8);
    static edk::uint32 utf8WordSize(edk::char8 *utf8);
    static edk::uint32 utf8WordSize(const edk::char8 *utf8);
    static edk::uint32 utf8WordSize(edk::char8 *utf8,edk::uint32* jump);
    static edk::uint32 utf8WordSize(const edk::char8 *utf8,edk::uint32* jump);
    static edk::uint32 utf8WordSize(edk::char8 *utf8,edk::uint32 limit,edk::uint32* jump);
    static edk::uint32 utf8WordSize(const edk::char8 *utf8,edk::uint32 limit,edk::uint32* jump);
    static edk::uint32 utf8LineCount(edk::char8 *utf8,edk::uint32 limit);
    static edk::uint32 utf8LineCount(const edk::char8 *utf8,edk::uint32 limit);
    static edk::uint32 utf8LineSize(edk::char8 *utf8,edk::uint32 limit);
    static edk::uint32 utf8LineSize(const edk::char8 *utf8,edk::uint32 limit);
    static edk::uint32 utf8LineSize(edk::char8 *utf8,edk::uint32 limit,edk::uint32* jump);
    static edk::uint32 utf8LineSize(const edk::char8 *utf8,edk::uint32 limit,edk::uint32* jump);
    //return the position of a string where the line starts
    static edk::char8* utf8LinePosition(edk::char8 *utf8,edk::uint32 limit,edk::uint32 linePosition);
    static edk::char8* utf8LinePosition(const edk::char8 *utf8,edk::uint32 limit,edk::uint32 linePosition);
    //get the size of utf8 bytes in a character
    static edk::uint8 utf8Bytes(edk::char8 *utf8);
    static edk::uint8 utf8Bytes(const edk::char8 *utf8);
    //convert a utf8 character to uint32
    static edk::uint32 utf8ToUint32(edk::char8 *utf8);
    static edk::uint32 utf8ToUint32(const edk::char8 *utf8);

    //ASCII to UTF8
    static bool asciiToUtf8(edk::char8* src,edk::char8* dest);
    static bool asciiToUtf8(const edk::char8* src,edk::char8* dest);
    static edk::char8* asciiToUtf8(edk::char8* src);
    static edk::char8* asciiToUtf8(const edk::char8* src);
    //ASCII to UTF8 Size
    static edk::uint32 asciiToUtf8Size(edk::char8* src);
    static edk::uint32 asciiToUtf8Size(const edk::char8* src);

    //UTF8 to ASCII
    static bool utf8ToAscii(edk::char8* src,edk::char8* dest);
    static bool utf8ToAscii(const edk::char8* src,edk::char8* dest);
    static edk::char8* utf8ToAscii(edk::char8* src);
    static edk::char8* utf8ToAscii(const edk::char8* src);
    //UTF8 to ASCII size
    static edk::uint32 utf8ToAsciiSize(edk::char8* src);
    static edk::uint32 utf8ToAsciiSize(const edk::char8* src);

    static edk::uint32 int32ToStrSize(edk::int32 value);

    static edk::uint32 int64ToStrSize(edk::int64 value);

    static edk::char8* int32ToStr(edk::int32 value);

    static edk::char8* int32ToStr(edk::int32 value,edk::uint32 digits);

    static edk::char8* int64ToStr(edk::int64 value);

    static edk::char8* int64ToStr(edk::int64 value,edk::uint32 digits);

    static bool int32ToStr(edk::int32 value,edk::char8* dest);

    static bool int32ToStr(edk::int32 value,edk::char8* dest,edk::uint32 digits);

    static bool int64ToStr(edk::int64 value,edk::char8* dest);

    static bool int64ToStr(edk::int64 value,edk::char8* dest,edk::uint32 digits);

    static edk::char8* vecInt8toStr(edk::int8* vec,edk::uint32 size);

    static edk::char8* vecInt16toStr(edk::int16* vec,edk::uint32 size);

    static edk::char8* vecInt32toStr(edk::int32* vec,edk::uint32 size);

    static edk::char8* vecInt64toStr(edk::int64* vec,edk::uint32 size);

    static edk::char8* vecUint8toStr(edk::uint8* vec,edk::uint32 size);

    static edk::char8* vecUint16toStr(edk::uint16* vec,edk::uint32 size);

    static edk::char8* vecUint32toStr(edk::uint32* vec,edk::uint32 size);

    static edk::char8* vecUint64toStr(edk::uint64* vec,edk::uint32 size);

    static edk::char8* vecfloat32toStr(edk::float32* vec,edk::uint32 size);

    static edk::char8* vecfloat64toStr(edk::float64* vec,edk::uint32 size);

    static edk::uint32 sizeOfInt32(edk::int32 value);

    static edk::uint32 sizeOfInt64(edk::int64 value);

    static edk::uint32 sizeOfFloat32(edk::float32 value);

    static edk::uint32 sizeOfFloat64(edk::float64 value);

    static edk::char8* float32ToStr(edk::float32 value);

    static bool float32ToStr(edk::float32 value,edk::char8* dest);

    static edk::char8* float32ToStr(edk::float32 value, edk::uint32 digits);

    static bool float32ToStr(edk::float32 value,edk::char8* dest,edk::uint32 digits);

    static edk::char8* float64ToStr(edk::float64 value, edk::uint32 digits);

    static bool float64ToStr(edk::float64 value,edk::char8* dest, edk::uint32 digits);

    static edk::char8* uint32ToStr(edk::uint32 value);

    static edk::char8* uint32ToStr(edk::uint32 value,edk::uint32 digits);

    static bool uint32ToStr(edk::uint32 value,edk::char8* dest);

    static bool uint32ToStr(edk::uint32 value,edk::char8* dest,edk::uint32 digits);

    static edk::char8* uint64ToStr(edk::uint64 value);

    static edk::char8* uint64ToStr(edk::uint64 value,edk::uint32 digits);

    static bool uint64ToStr(edk::uint64 value,edk::char8* dest);

    static bool uint64ToStr(edk::uint64 value,edk::char8* dest,edk::uint32 digits);

    static edk::char8* strCat(edk::char8 *str1, edk::char8 *str2);

    static edk::char8* strCat(edk::char8 *str1, const edk::char8 *str2);

    static edk::char8* strCat(const edk::char8 *str1, edk::char8 *str2);

    static edk::char8* strCat(const edk::char8 *str1, const edk::char8 *str2);

    static edk::char8* strCatMulti(edk::char8 *str, ...);

    static edk::char8* strCatMulti(const edk::char8 *str, ...);

    static bool strCompare(edk::char8 *str1, edk::char8 *str2);

    static bool strCompare(const edk::char8 *str1, edk::char8 *str2);
    static bool strCompare(edk::char8 *str1, const edk::char8 *str2);

    static bool strCompare(const edk::char8 *str1, const edk::char8 *str2);

    static bool strCompareBeggin(edk::char8 *beggin, edk::char8 *str);

    static bool strCompareBeggin(const edk::char8 *beggin, edk::char8 *str);
    static bool strCompareBeggin(edk::char8 *beggin, const edk::char8 *str);

    static bool strCompareBeggin(const edk::char8 *beggin, const edk::char8 *str);

    static bool strCompareEnd(edk::char8 *end, edk::char8 *str);

    static bool strCompareEnd(const edk::char8 *end, edk::char8 *str);
    static bool strCompareEnd(edk::char8 *end, const edk::char8 *str);

    static bool strCompareEnd(const edk::char8 *end, const edk::char8 *str);

    //Compare string removing some characters with filter
    static bool strCompareWithFilter(edk::char8 *str1, edk::char8 *str2,edk::char8 *filter);
    static bool strCompareWithFilter(edk::char8 *str1, edk::char8 *str2,const edk::char8 *filter);
    static bool strCompareWithFilter(const edk::char8 *str1, const edk::char8 *str2,const edk::char8 *filter);
    static bool strCompareWithFilter(const edk::char8 *str1, const edk::char8 *str2,edk::char8 *filter);
    static bool strCompareWithFilter(edk::char8 *str1, const edk::char8 *str2,const edk::char8 *filter);
    static bool strCompareWithFilter(edk::char8 *str1, const edk::char8 *str2,edk::char8 *filter);
    static bool strCompareWithFilter(const edk::char8 *str1, edk::char8 *str2,const edk::char8 *filter);
    static bool strCompareWithFilter(const edk::char8 *str1, edk::char8 *str2,edk::char8 *filter);

    //return true if a string is inside the other string
    static edk::char8* strInside(edk::char8 *str, edk::char8 *compare);
    static edk::char8* strInside(const edk::char8 *str, edk::char8 *compare);
    static edk::char8* strInside(edk::char8 *str, const edk::char8 *compare);
    static edk::char8* strInside(const edk::char8 *str, const edk::char8 *compare);
    static edk::char8* strHaveInside(edk::char8 *str, edk::char8 *compare);
    static edk::char8* strHaveInside(const edk::char8 *str, edk::char8 *compare);
    static edk::char8* strHaveInside(edk::char8 *str, const edk::char8 *compare);
    static edk::char8* strHaveInside(const edk::char8 *str, const edk::char8 *compare);

    //return true if the first string is bigger than the second string
    static bool strBiggerStr(edk::char8 *str1, edk::char8 *str2);
    static bool strBiggerStr(const edk::char8 *str1, edk::char8 *str2);
    static bool strBiggerStr(edk::char8 *str1, const edk::char8 *str2);
    static bool strBiggerStr(const edk::char8 *str1, const edk::char8 *str2);

    static edk::uint64 strSize(edk::char8 *str);

    static edk::uint64 strSize(const edk::char8 *str);

    static edk::uint64 strSizeWithBackslashSpace(edk::char8 *str);

    static edk::uint64 strSizeWithBackslashSpace(const edk::char8 *str);

    static edk::uint64 strSizeWithFilter(edk::char8 *str,edk::char8* filter);
    static edk::uint64 strSizeWithFilter(edk::char8 *str,const edk::char8 *filter);
    static edk::uint64 strSizeWithFilter(const edk::char8 *str,edk::char8* filter);
    static edk::uint64 strSizeWithFilter(const edk::char8 *str,const edk::char8 *filter);

    static edk::uint64 strSizeWithLimit(edk::char8 *str,edk::char8* limit);
    static edk::uint64 strSizeWithLimit(edk::char8 *str,const edk::char8 *limit);
    static edk::uint64 strSizeWithLimit(const edk::char8 *str,edk::char8* limit);
    static edk::uint64 strSizeWithLimit(const edk::char8 *str,const edk::char8 *limit);

    static edk::uint64 strWordSize(edk::char8 *str);

    static edk::uint64 strWordSize(const edk::char8 *str);

    static edk::uint64 strWordSizeWithFilter(edk::char8 *str,edk::char8* filter);
    static edk::uint64 strWordSizeWithFilter(edk::char8 *str,const edk::char8 *filter);
    static edk::uint64 strWordSizeWithFilter(const edk::char8 *str,edk::char8* filter);
    static edk::uint64 strWordSizeWithFilter(const edk::char8 *str,const edk::char8 *filter);

    static edk::uint64 strLineSize(edk::char8 *str);

    static edk::uint64 strLineSize(const edk::char8 *str);

    static edk::uint64 strLineSizeWithFilter(edk::char8 *str,edk::char8* filter);
    static edk::uint64 strLineSizeWithFilter(edk::char8 *str,const edk::char8 *filter);
    static edk::uint64 strLineSizeWithFilter(const edk::char8 *str,edk::char8* filter);
    static edk::uint64 strLineSizeWithFilter(const edk::char8 *str,const edk::char8 *filter);

    static bool strCut(edk::char8 *str,edk::char8 *dest, edk::char8 limit, bool use=false);

    static bool strCut(const edk::char8 *str,edk::char8 *dest, edk::char8 limit, bool use=false);

    static edk::char8* strCut(edk::char8 *str, edk::char8 limit, bool use=false);

    static edk::char8* strCut(const edk::char8 *str, edk::char8 limit, bool use=false);

    static bool strCut(edk::char8 limit, edk::char8 *str, edk::char8 *dest, bool use=false);

    static bool strCut(edk::char8 limit, const edk::char8 *str, edk::char8 *dest, bool use=false);

    static edk::char8* strCut(edk::char8 limit, edk::char8 *str, bool use=false);

    static edk::char8* strCut(edk::char8 limit, const edk::char8 *str, bool use=false);

    static bool strCut(edk::char8 *str,edk::char8 *dest, edk::char8 start, edk::char8 end, bool use=false);

    static bool strCut(const edk::char8 *str,edk::char8 *dest, edk::char8 start, edk::char8 end, bool use=false);

    static char8* strCut(edk::char8 *str, edk::char8 start, edk::char8 end, bool use=false);

    static char8* strCut(const edk::char8 *str, edk::char8 start, edk::char8 end, bool use=false);

    static bool strInvert(edk::char8 *str);

    static bool strInvert(const edk::char8 *str);

    static edk::uint64 stringHaveChar(char8 *str,edk::char8 value);

    static edk::uint64 stringHaveChar(const char *str,edk::char8 value);

    static edk::uint64 stringHaveChar(char8 *str,edk::uint64 size,edk::char8 value);

    static edk::uint64 stringHaveChar(const char *str,edk::uint64 size,edk::char8 value);

    static bool consoleKeyPressed();

    static edk::char8 consoleReadKey();

    static edk::char8* consoleReadString();

    static edk::char8* consoleReadStringNoPrint();

    static edk::char8* consoleReadPassword();

    static void consoleClear();

    //return the console size
    static edk::size2ui32 consoleGetSize();

    static edk::char8* strCopy(edk::char8 *str);

    static edk::char8* strCopy(const edk::char8 *str);

    static edk::char8* strCopyLine(edk::char8 *str);

    static edk::char8* strCopyLine(const edk::char8 *str);

    static edk::char8* strCopyWord(edk::char8 *str);

    static edk::char8* strCopyWord(const edk::char8 *str);

    static edk::char8* strCopyWithBackslashSpace(edk::char8 *str);

    static edk::char8* strCopyWithBackslashSpace(const edk::char8 *str);

    //remove a filter from string
    static edk::char8* strCopyWithFilter(edk::char8 *str,edk::char8 *filter);
    static edk::char8* strCopyWithFilter(const edk::char8 *str,edk::char8 *filter);
    static edk::char8* strCopyWithFilter(edk::char8 *str,const edk::char8 *filter);
    static edk::char8* strCopyWithFilter(const edk::char8 *str,const edk::char8 *filter);

    static edk::char8* clipboardRead();

    static bool clipboardWrite(edk::char8 *str);

    static bool clipboardWrite(const edk::char8 *str);

    static bool clipboardClean();

    //filter string accent's
    static edk::char8 filterAccent(const edk::char8* str);
    static edk::char8 filterAccent(edk::char8* str);
    static edk::char8 filterAccent(const edk::char8* str,edk::uint8* jump);
    static edk::char8 filterAccent(edk::char8* str,edk::uint8* jump);
    //get size with filter
    static edk::uint32 strSizeFilterAccent(const edk::char8* str);
    static edk::uint32 strSizeFilterAccent(edk::char8* str);
    //copy with filter
    static edk::char8* strCopyFilterAccent(const edk::char8* str);
    static edk::char8* strCopyFilterAccent(edk::char8* str);

    //return the file name from a string
    static edk::char8* strFileName(edk::char8* str);
    static edk::char8* strFileName(const edk::char8* str);
    static bool strFileName(edk::char8* str,edk::char8* dest);
    static bool strFileName(const edk::char8* str,edk::char8* dest);
    //return the folder name from a string
    static edk::char8* strFolderName(edk::char8* str);
    static edk::char8* strFolderName(const edk::char8* str);
    static bool strFolderName(edk::char8* str,edk::char8* dest);
    static bool strFolderName(const edk::char8* str,edk::char8* dest);

    //BASE64
    //encode
    //return the encode result size
    static edk::uint64 base64EncodeSize(edk::uint64 size);
    //convert the vector to base64 receiving the pre alloc string
    static bool base64Encode(edk::uint8* vec,edk::uint64 size,edk::char8* dest);
    static bool base64Encode(edk::char8* str,edk::uint64 size,edk::char8* dest);
    static bool base64Encode(const edk::char8* str,edk::uint64 size,edk::char8* dest);
    //convert the vector to base64 new string
    static edk::char8* base64Encode(edk::uint8* vec,edk::uint64 size);
    static edk::char8* base64Encode(edk::char8* str,edk::uint64 size);
    static edk::char8* base64Encode(const edk::char8* str,edk::uint64 size);
    //decode
    //convert a base64 to a pre alloc vector
    static edk::uint64 base64DecodeSize(edk::char8* str);
    static bool base64Decode(edk::char8* str,edk::uint8* dest);
    static bool base64Decode(const edk::char8* str,edk::uint8* dest);

    //convert the uri to utf8 to be used by http servers
    static edk::uint64 uriUnescapeSize(edk::char8* str);
    static edk::uint64 uriUnescapeSize(const edk::char8* str);
    static bool uriUnescape(edk::char8* str,edk::char8* dest);
    static bool uriUnescape(const edk::char8* str,edk::char8* dest);
    static bool uriUnescape(edk::char8* str,const edk::char8* dest);
    static bool uriUnescape(const edk::char8* str,const edk::char8* dest);
    static edk::char8* uriUnescape(edk::char8* str);
    static edk::char8* uriUnescape(const edk::char8* str);
private:
    static edk::char8* int32ToMinusStr(edk::int32 value);
    static bool int32ToMinusStr(edk::int32 value,edk::char8* dest);

    static edk::char8* int64ToMinusStr(edk::int64 value);
    static bool int64ToMinusStr(edk::int64 value,edk::char8* dest);

    //copy the number to the string
    static bool copyInt32ToStr(edk::int32 value,edk::char8* str,edk::int32 size);

    static bool copyInt64ToStr(edk::int64 value,edk::char8* str,edk::int32 size);
};

}//End of namespace edk

#endif // edk_String_h
