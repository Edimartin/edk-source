#ifndef EDK_WATCH_TIME_H
#define EDK_WATCH_TIME_H

/*
Library C++ TIME - Load the processor clock
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
#pragma message "Inside Time"
#endif

#pragma once
#include "../TypeVars.h"
//Time.h
#include <time.h>
//to get current time in milliseconds
#include <sys/timeb.h>

#include <stdio.h>
#include <string.h>

//Windows.h to the Sleep function
#ifdef _WIN32 //Windows 32bits
#pragma once
#include <windows.h>
#include <winbase.h>
//#include <pthread_time.h>
#elif _WIN64//Windows 64bits
#pragma once
#include <windows.h>
#include <winbase.h>
//#include <pthread_time.h>
#elif __linux__//Linux
#pragma once
//linux use the unistd
#include <unistd.h>
#include <sys/time.h>
#elif __APPLE__//MacOS
#pragma once
//To Find
#include <unistd.h>
#include <sys/time.h>
#endif

#include "../DebugFile.h"

#ifdef printMessages
#pragma message "    Compiling Time"
#endif

/*

    int tm_sec;    // seconds after the minute (0 to 61)
    int tm_min;    // minutes after the hour (0 to 59)
    int tm_hour;   // hours since midnight (0 to 23)
    int tm_mday;   // day of the month (1 to 31)
    int tm_mon;    // months since January (0 to 11)
    int tm_year;   // years since 1900
    int tm_wday;   // days since Sunday (0 to 6 Sunday=0)
    int tm_yday;   // days since January 1 (0 to 365)
    int tm_isdst;  // Daylight Savings Time

*/

namespace edk {
namespace watch {

//define the string name
#define SIZE_EDK_WATCH_TIME_STRING sizeof("YYYY-MM-DD ss:mm:hh 4294967295         ")

//multiplication to get float

#if defined(_WIN32) || defined(_WIN64)
const edk::float32 microsecond =.000001f;
const edk::uint32 second =1000000;

#elif defined(__linux__) || defined(__APPLE__)
const edk::float32 microsecond =.000001f;
const edk::uint32 second =1000000;
#endif
/*
#elif defined(__linux__) || defined(__APPLE__)
const edk::float32 millisecond =.000001f;
const edk::uint32 second =1000000;
#endif
*/

class Time {

public:

    Time();
    ~Time();

    void Constructor(bool runFather=true);

    void start();

    void remove(edk::uint32 microseconds);
    void removeSeconds(edk::float32 seconds);

    void increase(edk::uint32 microseconds);
    void increaseSeconds(edk::float32 seconds);

    edk::uint32 getMicroseconds();
    static edk::uint32 getMicrosecondsReal();

    //return the seconds in float
    edk::float32 getSeconds();

    //test if occur overflow
    bool overflowOccurred();

    edk::float32 getEstimativeFrame();

    //save the distance
    void saveDistance();
    //paste the distance
    void pasteDistance();

    static void sleepProcessMiliseconds(edk::uint32 Milliseconds);
    static void sleepProcessMicroseconds(edk::uint32 Microseconds);

    //get seconds since epoch
    static edk::uint64 getTimeSinceEpoch();

    static edk::uint64 getTimeSinceEpoch(edk::uint8 hour,edk::uint8 minute,edk::uint8 second,edk::uint8 dayOfMonth,edk::uint8 month,edk::uint32 year);

    void clockLoadGMTime();

    void clockLoadGMTime(edk::uint64 timeSinceEpoch);

    void clockLoadLocalTime();

    void clockLoadLocalTime(edk::uint64 timeSinceEpoch);

    edk::uint32 clockGetMillisecond();

    edk::uint8 clockGetSecond();

    edk::uint8 clockGetMinute();

    edk::uint8 clockGetHour();

    edk::uint8 clockGetDayOfMonth();

    edk::uint8 clockGetDayOfWeek();

    edk::uint32 clockGetDayOfYear();

    edk::uint8 clockGetMonth();

    edk::uint32 clockGetYear();

    edk::int32 clockGetGMTOff();

    edk::char8* clockGetTimezoneAbreviation();

    //functions to generate a string
    static edk::uint32 strSizeof();
    bool clockWriteStr(edk::char8* str);
    bool clockLoadStr();
    edk::char8* clockGetStr();
    void clockPrintStr();

private:

    //get day of the year
    static edk::uint32 getDayOfYear(edk::uint8 dayOfMonth,edk::uint8 month,edk::uint32 year);
    static bool isBisext(edk::uint32 year);

    //clean the str
    inline void cleanStr(){
        memset(this->str,0u,SIZE_EDK_WATCH_TIME_STRING);edkEnd();
    }


#if defined(_WIN32) || defined(_WIN64)
    //Windows
    LARGE_INTEGER PCFreq;
#endif
    //save the startTime
    edk::uint32 timeStart;
    //save the timeDistance to pause the clock
    edk::uint32 saveTimeDistance;

#if defined(__linux__) || defined(__APPLE__)
    static edk::uint32 linuxSecond;
#endif

    static edk::uint8 monthDays[12u];

    static bool templateConstructNeed;

    //set if occur overflow
    bool overflow;

    //string to write the time
    edk::char8 str[SIZE_EDK_WATCH_TIME_STRING];

    //
#ifdef _MSC_VER
    struct tm systemClock;
#else
    struct tm * systemClock;
#endif
    //to get the curent time in miliseconds
    struct timeb tmb;
private:
    edk::classID classThis;
};

}//End of namespace edk::ptr
}//End of namespace edk

#endif // edk_ptr_Time_h
