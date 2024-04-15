#ifndef CONSOLETERMINAL_H
#define CONSOLETERMINAL_H

/*
Library C++ Console Terminal to I/O in terminal
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
#pragma message "Inside ConsoleTerminal"
#endif

#pragma once
#include "TypeDefines.h"
#include "TypeVars.h"
#include "TypeSize2.h"
#include "TypeVec2.h"
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
#pragma message "    Compiling ConsoleTerminal"
#endif

namespace edk {
class TTY{
public:
    TTY();
    ~TTY();

    void Constructor(bool runFather=true);

    bool initTerminal();
    bool resetTerminal();
private:
    bool haveInit;
private:
    edk::classID classThis;
};
class ConsoleTerminal{
public:
    ConsoleTerminal();
    ~ConsoleTerminal();

    void Constructor(bool runFather=true);

    static void push();

    static void pop();

    static void gotoXY(edk::uint32 x,edk::uint32 y);

    static edk::vec2ui32 getPosition();
    inline static edk::vec2ui32 getXY(){
        return edk::ConsoleTerminal::getPosition();
    }
    inline static edk::uint32 getX(){
        return edk::ConsoleTerminal::getXY().x;
    }
    inline static edk::uint32 getY(){
        return edk::ConsoleTerminal::getXY().y;
    }


    static edk::size2ui32 getWidth();
    static edk::size2ui32 getHeight();

    static bool keyPressed();

    static edk::char8 readKey();

    static edk::char8* readString();

    static edk::char8* readStringNoPrint();

    static edk::char8* readPassword();

    static void clear();

    //return the console size
    static edk::size2ui32 getSize();

private:
    //TTY to construct and destruct
    static edk::TTY tty;
    static bool templateConstructNeed;
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // CONSOLETERMINAL_H
