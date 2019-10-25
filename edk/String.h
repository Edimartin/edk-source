#ifndef EDK_STRING_H
#define EDK_STRING_H

/*
Library C++ String - Manipulate char vectors.
Copyright (C) 1013 Eduardo Moura Sales Martins
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

#ifdef printMessages
#warning "Inside String"
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
#warning "    Compiling String"
#endif

namespace edk {

class String {

public:

    static edk::float32 strToFloat32(const char *str);

    static edk::float32 strToFloat32(char8 *str);

    static int64 strToInt64(char8 *str);

    static int64 strToInt64(const char *str);

    static edk::float64 strToFloat64(char8 *str);

    static edk::float64 strToFloat64(const char *str);

    static bool strToVecInt8(edk::char8* str,edk::int8* vec,edk::uint32 size);

    static bool strToVecInt16(edk::char8* str,edk::int16* vec,edk::uint32 size);

    static bool strToVecInt32(edk::char8* str,edk::int32* vec,edk::uint32 size);

    static bool strToVecInt64(edk::char8* str,edk::int64* vec,edk::uint32 size);

    static bool strToVecUint8(edk::char8* str,edk::uint8* vec,edk::uint32 size);

    static bool strToVecUint16(edk::char8* str,edk::uint16* vec,edk::uint32 size);

    static bool strToVecUint32(edk::char8* str,edk::uint32* vec,edk::uint32 size);

    static bool strToVecUint64(edk::char8* str,edk::uint64* vec,edk::uint32 size);

    static int32 strToInt32(char8 *str);

    static int32 strToInt32(const char *str);

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
    //get the size of utf8 bytes in a character
    static edk::uint8 utf8Bytes(edk::char8 *utf8);
    static edk::uint8 utf8Bytes(const edk::char8 *utf8);
    //convert a utf8 character to uint8
    static edk::uint32 utf8ToUint32(edk::char8 *utf8);
    static edk::uint32 utf8ToUint32(const edk::char8 *utf8);

    static char8* int32ToStr(int32 value);

    static char8* int64ToStr(int64 value);

    static char8* vecInt8toStr(edk::int8* vec,edk::uint32 size);

    static char8* vecInt16toStr(edk::int16* vec,edk::uint32 size);

    static char8* vecInt32toStr(edk::int32* vec,edk::uint32 size);

    static char8* vecInt64toStr(edk::int64* vec,edk::uint32 size);

    static char8* vecUint8toStr(edk::uint8* vec,edk::uint32 size);

    static char8* vecUint16toStr(edk::uint16* vec,edk::uint32 size);

    static char8* vecUint32toStr(edk::uint32* vec,edk::uint32 size);

    static char8* vecUint64toStr(edk::uint64* vec,edk::uint32 size);

    static edk::uint32 sizeOfInt32(int32 value);

    static edk::uint32 sizeOfInt64(int64 value);

    static char8* float32ToStr(edk::float32 value);

    static char8* float32ToStr(edk::float32 value, int32 digits);

    static char8* float64ToStr(edk::float64 value, int32 digits);

    static char8* uint32ToStr(uint32 value);

    static char8* uint64ToStr(uint64 value);

    static char8* strCat(char8 *str1, char8 *str2);

    static char8* strCat(char8 *str1, const char *str2);

    static char8* strCat(const char *str1, char8 *str2);

    static char8* strCat(const char *str1, const char *str2);

    static char8* strCatMulti(char8 *str, ...);

    static char8* strCatMulti(const char *str, ...);

    static bool strCompare(char8 *str1, char8 *str2);

    static bool strCompare(const char *str1, char8 *str2);
    static bool strCompare(char8 *str1, const char *str2);

    static bool strCompare(const char *str1, const char *str2);

    //Compare string removing some characters with filter
    static bool strCompareWithFilter(char8 *str1, char8 *str2,char8 *filter);
    static bool strCompareWithFilter(char8 *str1, char8 *str2,const char *filter);
    static bool strCompareWithFilter(const char *str1, const char *str2,const char *filter);
    static bool strCompareWithFilter(const char *str1, const char *str2,char8 *filter);
    static bool strCompareWithFilter(char8 *str1, const char *str2,const char *filter);
    static bool strCompareWithFilter(char8 *str1, const char *str2,char8 *filter);
    static bool strCompareWithFilter(const char *str1, char8 *str2,const char *filter);
    static bool strCompareWithFilter(const char *str1, char8 *str2,char8 *filter);

    //return true if a string is inside the other string
    static edk::char8* strInside(char8 *str, char8 *compare);
    static edk::char8* strInside(const char8 *str, char8 *compare);
    static edk::char8* strInside(char8 *str, const char8 *compare);
    static edk::char8* strInside(const char8 *str, const char8 *compare);

    //return true if the first string is bigger than the second string
    static bool strBiggerStr(char8 *str1, char8 *str2);
    static bool strBiggerStr(const char8 *str1, char8 *str2);
    static bool strBiggerStr(char8 *str1, const char8 *str2);
    static bool strBiggerStr(const char8 *str1, const char8 *str2);

    static uint64 strSize(char8 *str);

    static uint64 strSize(const char *str);

    static uint64 strSizeWithFilter(char8 *str,edk::char8* filter);
    static uint64 strSizeWithFilter(char8 *str,const char *filter);
    static uint64 strSizeWithFilter(const char *str,edk::char8* filter);
    static uint64 strSizeWithFilter(const char *str,const char *filter);

    static uint64 strWordSize(char8 *str);

    static uint64 strWordSize(const char *str);

    static uint64 strWordSizeWithFilter(char8 *str,edk::char8* filter);
    static uint64 strWordSizeWithFilter(char8 *str,const char *filter);
    static uint64 strWordSizeWithFilter(const char *str,edk::char8* filter);
    static uint64 strWordSizeWithFilter(const char *str,const char *filter);

    static bool strCut(char8 *str,char8 *dest, char8 limit, bool use=false);

    static bool strCut(const char8 *str,char8 *dest, char8 limit, bool use=false);

    static char8* strCut(char8 *str, char8 limit, bool use=false);

    static char8* strCut(const char *str, char8 limit, bool use=false);

    static bool strCut(char8 limit, char8 *str, char8 *dest, bool use=false);

    static bool strCut(char8 limit, const char *str, char8 *dest, bool use=false);

    static char8* strCut(char8 limit, char8 *str, bool use=false);

    static char8* strCut(char8 limit, const char *str, bool use=false);

    static bool strCut(char8 *str,char8 *dest, char8 start, char8 end, bool use=false);

    static bool strCut(const char *str,char8 *dest, char8 start, char8 end, bool use=false);

    static char8* strCut(char8 *str, char8 start, char8 end, bool use=false);

    static char8* strCut(const char *str, char8 start, char8 end, bool use=false);

    static bool strInvert(char8 *str);

    static bool strInvert(const char *str);

    static edk::uint64 stringHaveChar(char8 *str,edk::char8 value);

    static edk::uint64 stringHaveChar(const char *str,edk::char8 value);

    static edk::uint64 stringHaveChar(char8 *str,edk::uint64 size,edk::char8 value);

    static edk::uint64 stringHaveChar(const char *str,edk::uint64 size,edk::char8 value);

    static bool consoleKeyPressed();

    static char8 consoleReadKey();

    static char8* consoleReadString();

    static void consoleClear();

    //return the console size
    static edk::size2ui32 consoleGetSize();

    static char8* strCopy(char8 *str);

    static char8* strCopy(const char *str);

    //remove a filter from string
    static edk::char8* strCopyWithFilter(char8 *str,char8 *filter);
    static edk::char8* strCopyWithFilter(const char *str,char8 *filter);
    static edk::char8* strCopyWithFilter(char8 *str,const char *filter);
    static edk::char8* strCopyWithFilter(const char *str,const char *filter);

    static char8* clipboardRead();

    static bool clipboardWrite(char8 *str);

    static bool clipboardWrite(const char *str);

    static bool clipboardClean();

    //filter string accent's
    static edk::char8 filterAccent(const char* str);
    static edk::char8 filterAccent(edk::char8* str);
    static edk::char8 filterAccent(const char* str,edk::uint8* jump);
    static edk::char8 filterAccent(edk::char8* str,edk::uint8* jump);
    //get size with filter
    static edk::uint32 strSizeFilterAccent(const char* str);
    static edk::uint32 strSizeFilterAccent(edk::char8* str);
    //copy with filter
    static edk::char8* strCopyFilterAccent(const char* str);
    static edk::char8* strCopyFilterAccent(edk::char8* str);

    //return the file name from a string
    static edk::char8* strFileName(edk::char8* str);
    static edk::char8* strFileName(const edk::char8* str);
    static bool strFileName(edk::char8* str,edk::char8* dest);
    static bool strFileName(const edk::char8* str,edk::char8* dest);
private:
    static char8* int32ToMinusStr(int32 value);

    static char8* int64ToMinusStr(int64 value);

    //copy the number to the string
    static bool copyInt32ToStr(edk::int32 value,edk::char8* str,int32 size);

    static bool copyInt64ToStr(edk::int64 value,edk::char8* str,int32 size);
};

} /* End of namespace edk */

#endif // edk_String_h
