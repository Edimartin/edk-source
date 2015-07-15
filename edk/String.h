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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

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

    static double strToFloat64(char8 *str);

    static double strToFloat64(const char *str);

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

    static char8* float64ToStr(double value, int32 digits);

    static char8* uint32ToStr(uint32 value);

    static char8* strCat(char8 *str1, char8 *str2);

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

    static uint64 strSize(char8 *str);

    static uint64 strSize(const char *str);

    static uint64 strSizeWithFilter(char8 *str,edk::char8* filter);
    static uint64 strSizeWithFilter(char8 *str,const char *filter);
    static uint64 strSizeWithFilter(const char *str,edk::char8* filter);
    static uint64 strSizeWithFilter(const char *str,const char *filter);

    static char8* strCut(char8 *str, char8 limit, bool use);

    static char8* strCut(const char *str, char8 limit, bool use);

    static char8* strCut(char8 limit, char8 *str, bool use);

    static char8* strCut(char8 limit, const char *str, bool use);

    static char8* strCut(char8 *str, char8 start, char8 end);

    static char8* strCut(const char *str, char8 start, char8 end);

    static bool strInvert(char8 *str);

    static bool strInvert(const char *str);

    static edk::uint32 stringHaveChar(char8 *str,edk::char8 value);

    static edk::uint32 stringHaveChar(const char *str,edk::char8 value);

    static edk::uint32 stringHaveChar(char8 *str,edk::uint64 size,edk::char8 value);

    static edk::uint32 stringHaveChar(const char *str,edk::uint64 size,edk::char8 value);

    static bool consoleKeyPressed();

    static char8 consoleReadKey();

    static char8* consoleReadString();

    static void consoleClear();

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
private:
    static char8* int32ToMinusStr(int32 value);

    static char8* int64ToMinusStr(int64 value);

    //copy the number to the string
    static bool copyInt32ToStr(edk::int32 value,edk::char8* str,int32 size);

    static bool copyInt64ToStr(edk::int64 value,edk::char8* str,int32 size);
};

} /* End of namespace edk */

#endif // edk_String_h
