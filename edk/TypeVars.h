#ifndef EDK_TYPEVARS_H
#define EDK_TYPEVARS_H

#pragma once
#include <stdio.h>

/*
Library C++ TypeVars - Data types used in EDK engine.
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
#warning "Inside TypesVars"
#endif

#ifdef printMessages
#warning "    Compiling TypesVars"
#endif

/*TYPES USED BY EDK ENGINE*/
namespace edk{
	//
    typedef void* classID;

    typedef unsigned int    typeID;

    typedef unsigned char socketType;

    typedef signed   char          int8;
    typedef unsigned char          uint8;
    typedef signed   short int     int16;
    typedef unsigned short int     uint16;

    typedef float                  float32;
    typedef double                 float64;

    typedef int                    int32;
    typedef unsigned int           uint32;
	#if defined(__arch64__) || defined(_LP64)
    typedef signed long int        int64;
    typedef unsigned long int      uint64;
	#else
    typedef signed long long int   int64;
    typedef unsigned long long int uint64;
	#endif

    typedef /*signed*/   char          char8;
    typedef unsigned char          uchar8;
    typedef /*signed*/   short int     char16;
    typedef unsigned short int     uchar16;

    typedef int                    char32;
    typedef unsigned int           uchar32;
	#if defined(__arch64__) || defined(_LP64)
    typedef signed long int        char64;
    typedef unsigned long int      uchar64;
	#else
    typedef signed long int        char64;
    typedef unsigned long long int uchar64;
	#endif

}//end namespace

#include <stdarg.h>

//MARCROS

//Need a class to remove the nothing warning
namespace edk{
class NothingClass{
public:
    inline static void edk_nothing(){}
    //write to vprintf with the line, file and function names
    inline static void edk_lffprint(edk::uint32 line, const edk::char8* fileName, const edk::char8* funcName, const edk::char8* str,...){
        if(fileName && funcName && str){
            printf("\n[%06u] (%10s) %10s():",line,fileName,funcName);
            va_list args;
            va_start (args, str);
            vprintf (str, args);
            va_end (args);
            fflush(stdout);
        }
    }
};
}

#define edkPrintf(str,args...) \
    edk::NothingClass::edk_lffprint(__LINE__,__FILE__,__func__,str,##args); \
    edk::NothingClass::edk_nothing()
/*
#if defined(EDK_DEBUGGER)
#define edkEnd() printf("\n%u %s %s",__LINE__,__FILE__,__func__); \
    fflush(stdout)
#else
#define edkEnd() edk::NothingClass::edk_nothing()
#endif
*/

#endif // TYPEVARS_H
