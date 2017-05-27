#include "Time.h"

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

#ifdef _WIN32
//Windows 32
#elif _WIN64
//Windows 64
#elif __linux__
//Linux
#elif __APPLE__
//MacOS
#endif

namespace edk {
namespace watch {


#if defined(__linux__) || defined(__APPLE__)
edk::uint32 edk::watch::Time::linuxSecond = 1000000u;
#endif


Time::Time(){
    this->timeStart=0u;
    this->saveTimeDistance=0u;
#if defined(WIN32) || defined(WIN64)
    this->systemClock=NULL;
    QueryPerformanceFrequency(&this->PCFreq);
    if(this->PCFreq.QuadPart==0){
        this->PCFreq.QuadPart=1;
    }
#endif
    //start the new clock
    this->start();
    //load the time
    this->clockLoadLocalTime();
}



void Time::start(){
    //clean the clock
    overflow=false;

#if defined(_WIN32) || defined(_WIN64)
    this->timeStart = edk::watch::Time::getMicrosecondsReal();
#elif defined(__linux__) || defined(__APPLE__)
    this->timeStart = edk::watch::Time::getMicrosecondsReal();
#endif
}
void Time::remove(uint32 microseconds){
    //Remove milliseconds from the cronometer just add milliseconds in the timeStart
    this->timeStart += microseconds;
}

uint32 Time::getMicroseconds(){
#if defined(_WIN32) || defined(_WIN64)
    //Windows
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    edk::uint32 temp = (edk::uint32)(li.QuadPart * 1000000 / this->PCFreq.QuadPart );
    return (temp - this->timeStart);
#elif defined(__linux__) || defined(__APPLE__)
    edk::uint32 temp = this->getMicrosecondsReal();
    if(this->timeStart>temp){
        //occur overflow
        this->overflow=true;
        return (0xFFFFFFFF - this->timeStart) + temp;
    }
    else{
        return (temp - this->timeStart);
    }
#endif
    return 0.0f;
}

edk::uint32 Time::getMicrosecondsReal(){
#if defined(_WIN32) || defined(_WIN64)
    //Windows
    LARGE_INTEGER li, freq;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&li);
    return (edk::uint32)(li.QuadPart * 1000000 / freq.QuadPart );
#elif defined(__linux__) || defined(__APPLE__)
    //MacOS
    //Get the clockTime
    struct timeval getTime;
    gettimeofday(&getTime, NULL);
    //printf("\ngetTime %u timeStart %u",this->getTime.tv_usec,this->timeStart.tv_usec);
    edk::uint32 temp = (edk::uint32)((getTime.tv_usec+(getTime.tv_sec*linuxSecond))/**0.1*/);
    return temp;
#endif
    return 0.0f;
}

//test if occur overflow
bool Time::overflowOccurred(){
    this->getMicroseconds();
    return this->overflow;
}

edk::float32 Time::getEstimativeFrame(){
    edk::uint32 mili=this->getMicroseconds();
    if(mili>0u)
        return (edk::watch::second/(edk::float32)mili);
    return 0.0f;
}

//save the distance
void Time::saveDistance(){
    this->saveTimeDistance = this->getMicroseconds();
}
//paste the distance
void Time::pasteDistance(){
    this->timeStart-=this->saveTimeDistance;
    this->saveTimeDistance=0u;
}

void Time::sleepProcessMiliseconds(uint32 Milliseconds){
#if defined(_WIN32) || defined(_WIN64)
    //
    Sleep(Milliseconds);
#elif defined(__linux__)//Linux
    //
    edk::int64 seconds=0;
    //converte os segundos apenas se os mesmos existirem
    if(Milliseconds>=1000){
        seconds = Milliseconds*0.001;
    }
    edk::int64 nanoseconds = (Milliseconds%1000)*1000000u;
    //usleep(Milliseconds*1000);
    struct timespec temp = {seconds, nanoseconds};
    nanosleep(&temp, NULL);
#elif __APPLE__//MacOS
    //To Find
#endif
}

void Time::sleepProcessMicroseconds(uint32 Microseconds){
#if defined(_WIN32) || defined(_WIN64)
    //error. cant find microsleep in Windows
#elif defined(__linux__)//Linux
    //
    edk::int32 seconds=0;
    //converte os segundos apenas se os mesmos existirem
    if(Microseconds>=1000000){
        seconds = (edk::float32)Microseconds/edk::watch::second;
    }
    edk::int32 nanoseconds = (Microseconds%edk::watch::second)*1000;
    struct timespec temp = {seconds, nanoseconds};
    nanosleep(&temp, NULL);
#elif __APPLE__//MacOS
    //To Find
#endif
    return;
}

//get seconds since epoch
edk::uint64 Time::getTimeSinceEpoch(){
    return (edk::uint64) time(NULL);
}

void Time::clockLoadGMTime(){
    this->clockLoadGMTime((edk::uint64) time(NULL));
}

void Time::clockLoadGMTime(edk::uint64 timeSinceEpoch){
    time_t rawtime = (time_t)timeSinceEpoch;
    //get localTime
#ifdef _MSC_VER
    //systemClock = gmtime_s ( &rawtime );
    ///TODO:gmTime esta dando crash na aplicação
    gmtime_s(&systemClock,&rawtime);
#else
    this->systemClock = gmtime ( &rawtime );
#endif
}

void Time::clockLoadLocalTime(){
    this->clockLoadLocalTime((edk::uint64) time(NULL));
}

void Time::clockLoadLocalTime(edk::uint64 timeSinceEpoch){
    time_t rawtime = (time_t)timeSinceEpoch;
    //get localTime
#ifdef _MSC_VER
    //systemClock = gmtime_s ( &rawtime );
    ///TODO:gmTime esta dando crash na aplicação
    gmtime_s(&systemClock,&rawtime);
#else
    this->systemClock = localtime ( &rawtime );
#endif
}

uint32 Time::clockGetMillisecond(){
    //set the struct
    ftime(&tmb);
    //return the time
    return tmb.millitm;
}

uint8 Time::clockGetSecond(){
#ifdef _MSC_VER
    return systemClock.tm_sec;
#else
    if(systemClock)
        return systemClock->tm_sec;
    return 0u;
#endif
}

uint8 Time::clockGetMinute(){
#ifdef _MSC_VER
    return systemClock.tm_min;
#else
    if(systemClock)
        return systemClock->tm_min;
    return 0u;
#endif
}

uint8 Time::clockGetHour(){
#ifdef _MSC_VER
    return systemClock.tm_hour;
#else
    if(systemClock)
        return systemClock->tm_hour;
    return 0u;
#endif
}

uint8 Time::clockGetDayOfMonth(){
#ifdef _MSC_VER
    return systemClock.tm_mday;
#else
    if(systemClock)
        return systemClock->tm_mday;
    return 0u;
#endif
}

uint8 Time::clockGetDayOfWeek(){
#ifdef _MSC_VER
    return systemClock.tm_wday+1u;
#else
    if(systemClock)
        return systemClock->tm_wday+1u;
    return 0u;
#endif
}

uint32 Time::clockGetDayOfYear(){
#ifdef _MSC_VER
    return systemClock.tm_yday+1u;
#else
    if(systemClock)
        return systemClock->tm_yday+1u;
    return 0u;
#endif
}

uint8 Time::clockGetMonth(){
#ifdef _MSC_VER
    return systemClock.tm_mon+1u;
#else
    if(systemClock)
        return systemClock->tm_mon+1u;
    return 0u;
#endif
}

uint32 Time::clockGetYear(){
#ifdef _MSC_VER
    return systemClock.tm_year+1900u;
#else
    if(systemClock)
        return systemClock->tm_year+1900u;
    return 0u;
#endif
}

edk::int32 Time::clockGetGMTOff(){

#ifdef _MSC_VER
# ifdef	__USE_MISC
        return systemClock.tm_gmtoff;
# else
        return systemClock.__tm_gmtoff;
# endif
#else
    if(systemClock)
# ifdef	__USE_MISC
        return systemClock->tm_gmtoff;
# else
        return systemClock->__tm_gmtoff;
# endif
    return 0u;
#endif
}

edk::char8* Time::clockGetTimezoneAbreviation(){
#ifdef _MSC_VER
# ifdef	__USE_MISC
        return (edk::char8*)systemClock.tm_zone;
# else
        return (edk::char8*)systemClock.__tm_zone;
# endif
#else
    if(systemClock)
# ifdef	__USE_MISC
        return (edk::char8*)systemClock->tm_zone;
# else
        return (edk::char8*)systemClock->__tm_zone;
# endif
    return NULL;
#endif
}

} /* End of namespace edk::ptr */
} /* End of namespace edk */
