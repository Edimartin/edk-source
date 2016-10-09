#ifndef EDK_WATCH_TIME_H
#define EDK_WATCH_TIME_H

/*
Library C++ TIME - Load the processor clock
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
#warning "Inside Time"
#endif

#pragma once
#include "../TypeVars.h"
//Time.h
#include <time.h>
//to get current time in milliseconds
#include <sys/timeb.h>

/*TEMP*/
#include <stdio.h>

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

#ifdef printMessages
#warning "    Compiling Time"
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

    void start();

    void remove(uint32 microseconds);

    uint32 getMicroseconds();
    static uint32 getMicrosecondsReal();

    //test if occur overflow
    bool overflowOccurred();

    edk::float32 getEstimativeFrame();

    //save the distance
    void saveDistance();
    //paste the distance
    void pasteDistance();

    static void sleepProcessMiliseconds(uint32 Milliseconds);
    static void sleepProcessMicroseconds(uint32 Microseconds);

    void clockLoadTime();

    uint32 clockGetMillisecond();

    uint8 clockGetSecond();

    uint8 clockGetMinute();

    uint8 clockGetHour();

    uint8 clockGetDayOfMont();

    uint8 clockGetDayOfWeek();

    uint32 clockGetDayOfYear();

    uint8 clockGetMonth();

    uint32 clockGetYear();


 private:

    /**
     *  asave the time to count after the timeStart
     */
     //update the startTime
     void updateStartTime();

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

    //set if occur overflow
    bool overflow;

    //
#ifdef _MSC_VER
    struct tm systemClock;
#else
    struct tm * systemClock;
#endif
    //to get the curent time in miliseconds
    struct timeb tmb;
};

} /* End of namespace edk::ptr */
} /* End of namespace edk */

#endif // edk_ptr_Time_h
