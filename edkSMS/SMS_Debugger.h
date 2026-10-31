#ifndef SMS_DEBUGGER_H
#define SMS_DEBUGGER_H

/*
Library C++ SMS_Debugger - Debugger to write a string into memory in SMS. Use the Emulicious.jar compiler.
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
#pragma message "Inside SMS_Debugger"
#endif

#ifdef printMessages
#pragma message "    Compiling SMS_Debugger"
#endif

#pragma once
#include "SMS_TypeVars.h"


//activate the debugger
//#define SMS_DEBUG



#ifdef SMS_DEBUG
#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#endif

#ifdef SMS_DEBUG
#if !defined(__GNUC__) && !defined(__clang__)
static int16 posB;
static char bufferDebug[512];
#endif
static void sms_debugClean(){
#if !defined(__GNUC__) && !defined(__clang__)
    posB=0u;
    memset(bufferDebug,0u,sizeof(bufferDebug));
#endif
}

// Macro para PC / Desktop (GCC/Clang)
#if defined(__GNUC__) || defined(__clang__)
    #define sms_printfLine(formato, ...) \
        do { \
            printf("[%d]: " formato, __LINE__, ##__VA_ARGS__); \
            fflush(stdout); \
        } while(0)
#else
    // Macro para o Sega Master System (z88dk / sccz80)
    // Ela limpa o buffer, insere a linha e depois concatena a formatação enviada
    #define sms_printfLine(formato, ...) \
        do { \
            sms_debugClean(); \
            posB += sprintf(&bufferDebug[posB], "[%d]: ", __LINE__); \
            posB += sprintf(&bufferDebug[posB], formato, ##__VA_ARGS__); \
        } while(0)
#endif

// Macro para PC / Desktop (GCC/Clang)
#if defined(__GNUC__) || defined(__clang__)
    #define sms_printf(formato, ...) \
        do { \
            printf("[%d]: " formato, linha, ##__VA_ARGS__); \
            fflush(stdout); \
        } while(0)
#else
    // Macro para o Sega Master System (z88dk / sccz80)
    // Ela limpa o buffer, insere a linha e depois concatena a formatação enviada
    #define sms_printf(formato, ...) \
        do { \
            posB += sprintf(&bufferDebug[posB], formato, ##__VA_ARGS__); \
        } while(0)
#endif

#else
    // Se o DEBUG estiver desligado, a macro vira fumaça e não ocupa espaço na ROM
    #define sms_printfLine(formato, ...)
    #define sms_printf(formato, ...)
    #define sms_debugClean()
#endif

#endif // SMS_DEBUGGER_H
