#ifndef EDKSMS_TYPEVARS_H
#define EDKSMS_TYPEVARS_H

/*
Library C++ SMS_TypeVars - Data types used in EDK engine SMS.
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
#pragma message "Inside SMS_TypesVars"
#endif

#ifdef printMessages
#pragma message "    Compiling SMS_TypesVars"
#endif

#pragma once
#include <stdio.h>
#include <stdbool.h>


#ifdef __SDCC
#include <arch/sms/SMSlib.h>
#endif

#if defined(__SDCC) && defined(__SDCC_z80)
#include <arch/sms/SMSlib.h>
#endif

#if !defined(__GNUC__) && !defined(__clang__)
#include <arch/sms/SMSlib.h>
#endif


typedef void* classID;

typedef unsigned int    typeID;

typedef signed   char          int8;
typedef unsigned char          uint8;
typedef signed   short int     int16;
typedef unsigned short int     uint16;

typedef int                    int32;
typedef unsigned int           uint32;

typedef /*signed*/   char      char8;
typedef unsigned char          uchar8;
typedef /*signed*/   short int char16;
typedef unsigned short int     uchar16;

typedef int                    char32;
typedef unsigned int           uchar32;

//MARCROS

#define EDK_SMS_SCREEN_WIDTH 256
#define EDK_SMS_SCREEN_HEIGHT 192
#define EDK_SMS_SCREEN_HEIGHT2 224
#define EDK_SMS_BACKGROUND_WIDTH 32
#define EDK_SMS_BACKGROUND_HEIGHT 24
#define EDK_SMS_BACKGROUND_HEIGHT2 28
#define EDK_SMS_TILE_SIZE 8u



#endif // SMS_TYPEVARS_H
