#include "Time.h"

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

#ifdef _WIN32
//Windows 32
#elif _WIN64
//Windows 64
#elif __linux__
//Linux
#elif __APPLE__
//MacOS
#endif

#if defined(__linux__) || defined(__APPLE__)
edk::uint32 edk::watch::Time::linuxSecond = 1000000u;
#endif


edk::uint8 edk::watch::Time::monthDays[12u]={31,28,31,30,31,30,31,31,30,31,30,31};


edk::watch::Time::Time(){
    this->cleanStr();edkEnd();
    this->timeStart=0u;edkEnd();
    this->saveTimeDistance=0u;edkEnd();
#if defined(WIN32) || defined(WIN64)
    this->systemClock=NULL;edkEnd();
    QueryPerformanceFrequency(&this->PCFreq);edkEnd();
    if(this->PCFreq.QuadPart==0){
        this->PCFreq.QuadPart=1;edkEnd();
    }
#endif
    //start the new clock
    this->start();edkEnd();
    //load the time
    this->clockLoadLocalTime();edkEnd();
}
edk::watch::Time::~Time(){
    this->cleanStr();edkEnd();
}


//get day of the year
edk::uint32 edk::watch::Time::getDayOfYear(edk::uint8 dayOfMonth,edk::uint8 month,edk::uint32 year){
    edk::uint32 ret = 0u;edkEnd();
    if(month<12){
        ret = dayOfMonth;edkEnd();
        for(edk::uint8 i=0u;i<month;i++){
            ret += edk::watch::Time::monthDays[i];edkEnd();
        }
        //test if need add the bisext year day
        if(month>2u){
            //calculate if add the bisext day
            if(edk::watch::Time::isBisext(year)){
                ret++;edkEnd();
            }
        }
    }
    return ret;
}
bool edk::watch::Time::isBisext(edk::uint32 year){
    if(!(year%4u) && (year%100u)){
        return true;
    }
    return false;
}



void edk::watch::Time::start(){
    //clean the clock
    overflow=false;edkEnd();

#if defined(_WIN32) || defined(_WIN64)
    this->timeStart = edk::watch::Time::getMicrosecondsReal();edkEnd();
#elif defined(__linux__) || defined(__APPLE__)
    this->timeStart = edk::watch::Time::getMicrosecondsReal();edkEnd();
#endif
}
void edk::watch::Time::remove(edk::uint32 microseconds){
    //Remove milliseconds from the cronometer just add milliseconds in the timeStart
    this->timeStart += microseconds;edkEnd();
}
void edk::watch::Time::removeSeconds(edk::float32 seconds){
    if(seconds>0.f){
        this->remove((edk::uint32)(edk::watch::second * seconds));edkEnd();
    }
}

void edk::watch::Time::increase(uint32 microseconds){
    if(microseconds<=this->timeStart){
        this->timeStart -= microseconds;edkEnd();
    }
    else{
        //
        this->timeStart = 0xFFFFFFFF-(microseconds-this->timeStart);edkEnd();
    }
}
void edk::watch::Time::increaseSeconds(edk::float32 seconds){
    if(seconds>0.f){
        this->increase((edk::uint32)(edk::watch::second * seconds));edkEnd();
    }
}

edk::uint32 edk::watch::Time::getMicroseconds(){
#if defined(_WIN32) || defined(_WIN64)
    //Windows
    LARGE_INTEGER li;edkEnd();
    QueryPerformanceCounter(&li);edkEnd();
    edk::uint32 temp = (edk::uint32)(li.QuadPart * 1000000 / this->PCFreq.QuadPart );edkEnd();
    return (temp - this->timeStart);edkEnd();
#elif defined(__linux__) || defined(__APPLE__)
    edk::uint32 temp = edk::watch::Time::getMicrosecondsReal();edkEnd();
    if(this->timeStart>temp){
        //occur overflow
        this->overflow=true;edkEnd();
        return (0xFFFFFFFF - this->timeStart) + temp;edkEnd();
    }
    else{
        return (temp - this->timeStart);edkEnd();
    }
#endif
    return 0.0f;edkEnd();
}

edk::uint32 edk::watch::Time::getMicrosecondsReal(){
#if defined(_WIN32) || defined(_WIN64)
    //Windows
    LARGE_INTEGER li, freq;edkEnd();
    QueryPerformanceFrequency(&freq);edkEnd();
    QueryPerformanceCounter(&li);edkEnd();
    return (edk::uint32)(li.QuadPart * 1000000 / freq.QuadPart );edkEnd();
#elif defined(__linux__) || defined(__APPLE__)
    //MacOS
    //Get the clockTime
    struct timeval getTime;edkEnd();
    gettimeofday(&getTime, NULL);edkEnd();
    //printf("\ngetTime %u timeStart %u",this->getTime.tv_usec,this->timeStart.tv_usec);edkEnd();
    edk::uint32 temp = (edk::uint32)((getTime.tv_usec+(getTime.tv_sec*linuxSecond))/**0.1*/);edkEnd();
    return temp;edkEnd();
#endif
    return 0.0f;edkEnd();
}

//return the seconds in float
edk::float32 edk::watch::Time::getSeconds(){
    return this->getMicroseconds() * edk::watch::microsecond;edkEnd();
}

//test if occur overflow
bool edk::watch::Time::overflowOccurred(){
    this->getMicroseconds();edkEnd();
    return this->overflow;edkEnd();
}

edk::float32 edk::watch::Time::getEstimativeFrame(){
    edk::uint32 mili=this->getMicroseconds();edkEnd();
    if(mili>0u){
        return (edk::watch::second/(edk::float32)mili);edkEnd();
    }
    return 0.0f;edkEnd();
}

//save the distance
void edk::watch::Time::saveDistance(){
    this->saveTimeDistance = this->getMicroseconds();edkEnd();
}
//paste the distance
void edk::watch::Time::pasteDistance(){
    this->timeStart-=this->saveTimeDistance;edkEnd();
    this->saveTimeDistance=0u;
}

void edk::watch::Time::sleepProcessMiliseconds(edk::uint32 Milliseconds){
#if defined(_WIN32) || defined(_WIN64)
    //
    Sleep(Milliseconds);edkEnd();
#elif defined(__linux__)//Linux
    //
    edk::int64 seconds=0;
    //converte os segundos apenas se os mesmos existirem
    if(Milliseconds>=1000){
        seconds = Milliseconds*0.001;edkEnd();
    }
    edk::int64 nanoseconds = (Milliseconds%1000)*1000000u;edkEnd();
    //usleep(Milliseconds*1000);edkEnd();
    struct timespec temp = {seconds, nanoseconds};
    nanosleep(&temp, NULL);edkEnd();
#elif __APPLE__//MacOS
    //To Find
#endif
}

#if defined(_WIN32) || defined(_WIN64)
void edk::watch::Time::sleepProcessMicroseconds(edk::uint32){
    //error. cant find microsleep in Windows
#elif defined(__linux__)//Linux
void edk::watch::Time::sleepProcessMicroseconds(edk::uint32 Microseconds){
    //
    edk::int32 seconds=0;
    //converte os segundos apenas se os mesmos existirem
    if(Microseconds>=1000000){
        seconds = (edk::float32)Microseconds/edk::watch::second;edkEnd();
    }
    edk::int32 nanoseconds = (Microseconds%edk::watch::second)*1000;
    struct timespec temp = {seconds, nanoseconds};
    nanosleep(&temp, NULL);edkEnd();
#elif __APPLE__//MacOS
    //To Find
#endif
    return;edkEnd();
}

//get seconds since epoch
edk::uint64 edk::watch::Time::getTimeSinceEpoch(){
    return (edk::uint64) time(NULL);edkEnd();
}

edk::uint64 edk::watch::Time::getTimeSinceEpoch(edk::uint8 hour,edk::uint8 minute,edk::uint8 second,edk::uint8 dayOfMonth,edk::uint8 month,edk::uint32 year){
    if(year>1970){
        year-=1970;edkEnd();
    }
    if(dayOfMonth){
        dayOfMonth--;edkEnd();
    }
    if(month){
        month--;edkEnd();
    }
    edk::uint64 ret = (edk::uint64)second
            + ((edk::uint64)minute * 60u)
            + ((edk::uint64)hour * 3600u)
            + ((edk::uint64)edk::watch::Time::getDayOfYear(dayOfMonth,month,year) * 86400)
            + ((edk::uint64)(year) * 31536000)
            + (((edk::uint64)(year) / 4) * 86400)
            ;edkEnd();
    //
    return ret;
}

void edk::watch::Time::clockLoadGMTime(){
    return this->clockLoadGMTime(edk::watch::Time::getTimeSinceEpoch());edkEnd();
}

void edk::watch::Time::clockLoadGMTime(edk::uint64 timeSinceEpoch){
    time_t rawtime = (time_t)timeSinceEpoch;edkEnd();
    //get localTime
#ifdef _MSC_VER
    //systemClock = gmtime_s ( &rawtime );edkEnd();
    ///TODO:gmTime esta dando crash na aplicação
    gmtime_s(&systemClock,&rawtime);edkEnd();
#else
    this->systemClock = gmtime ( &rawtime );edkEnd();
#endif
}

void edk::watch::Time::clockLoadLocalTime(){
    return this->clockLoadLocalTime((edk::uint64) time(NULL));edkEnd();
}

void edk::watch::Time::clockLoadLocalTime(edk::uint64 timeSinceEpoch){
    time_t rawtime = (time_t)timeSinceEpoch;edkEnd();
    //get localTime
#ifdef _MSC_VER
    //systemClock = gmtime_s ( &rawtime );edkEnd();
    ///TODO:gmTime esta dando crash na aplicação
    gmtime_s(&systemClock,&rawtime);edkEnd();
#else
    this->systemClock = localtime ( &rawtime );edkEnd();
#endif
}

edk::uint32 edk::watch::Time::clockGetMillisecond(){
    //set the struct
    ftime(&tmb);edkEnd();
    //return the time
    return tmb.millitm;edkEnd();
}

edk::uint8 edk::watch::Time::clockGetSecond(){
#ifdef _MSC_VER
    return systemClock.tm_sec;edkEnd();
#else
    if(systemClock){
        return systemClock->tm_sec;edkEnd();
    }
    return 0u;edkEnd();
#endif
}

edk::uint8 edk::watch::Time::clockGetMinute(){
#ifdef _MSC_VER
    return systemClock.tm_min;edkEnd();
#else
    if(systemClock){
        return systemClock->tm_min;edkEnd();
    }
    return 0u;edkEnd();
#endif
}

edk::uint8 edk::watch::Time::clockGetHour(){
#ifdef _MSC_VER
    return systemClock.tm_hour;edkEnd();
#else
    if(systemClock){
        return systemClock->tm_hour;edkEnd();
    }
    return 0u;edkEnd();
#endif
}

edk::uint8 edk::watch::Time::clockGetDayOfMonth(){
#ifdef _MSC_VER
    return systemClock.tm_mday;edkEnd();
#else
    if(systemClock){
        return systemClock->tm_mday;edkEnd();
    }
    return 0u;edkEnd();
#endif
}

edk::uint8 edk::watch::Time::clockGetDayOfWeek(){
#ifdef _MSC_VER
    return systemClock.tm_wday+1u;edkEnd();
#else
    if(systemClock){
        return systemClock->tm_wday+1u;edkEnd();
    }
    return 0u;edkEnd();
#endif
}

edk::uint32 edk::watch::Time::clockGetDayOfYear(){
#ifdef _MSC_VER
    return systemClock.tm_yday+1u;edkEnd();
#else
    if(systemClock){
        return systemClock->tm_yday+1u;edkEnd();
    }
    return 0u;edkEnd();
#endif
}

edk::uint8 edk::watch::Time::clockGetMonth(){
#ifdef _MSC_VER
    return systemClock.tm_mon+1u;edkEnd();
#else
    if(systemClock){
        return systemClock->tm_mon+1u;edkEnd();
    }
    return 0u;edkEnd();
#endif
}

edk::uint32 edk::watch::Time::clockGetYear(){
#ifdef _MSC_VER
    return systemClock.tm_year+1900u;edkEnd();
#else
    if(systemClock){
        return systemClock->tm_year+1900u;edkEnd();
    }
    return 0u;edkEnd();
#endif
}

edk::int32 edk::watch::Time::clockGetGMTOff(){

#if defined(__WIN32__) || defined(__WIN64__)
        return 0u;edkEnd();
#else
    if(systemClock){
# ifdef	__USE_MISC
        return systemClock->tm_gmtoff;edkEnd();
# else
        return systemClock->__tm_gmtoff;edkEnd();
# endif
    }
    return 0u;edkEnd();
#endif
}

edk::char8* edk::watch::Time::clockGetTimezoneAbreviation(){
#if defined(__WIN32__) || defined(__WIN64__)
        return 0u;edkEnd();
#else
    if(systemClock){
# ifdef	__USE_MISC
        return (edk::char8*)systemClock->tm_zone;edkEnd();
# else
        return (edk::char8*)systemClock->__tm_zone;edkEnd();
# endif
    }
    return NULL;edkEnd();
#endif
}

//functions to generate a string
edk::uint32 edk::watch::Time::strSizeof(){
    return SIZE_EDK_WATCH_TIME_STRING;edkEnd();
}
bool edk::watch::Time::clockWriteStr(edk::char8* str){
    if(str){
        sprintf(str,"%04u-%02u-%02u %02u:%02u:%02u %10u"
                ,this->clockGetYear()
                ,this->clockGetMonth()
                ,this->clockGetDayOfMonth()
                ,this->clockGetSecond()
                ,this->clockGetMinute()
                ,this->clockGetHour()
                ,this->clockGetMillisecond()
                );edkEnd();
        return true;
    }
    return false;
}
bool edk::watch::Time::clockLoadStr(){
    this->cleanStr();edkEnd();
    return this->clockWriteStr(this->str);edkEnd();
}
edk::char8* edk::watch::Time::clockGetStr(){
    return this->str;edkEnd();
}
void edk::watch::Time::clockPrintStr(){
    this->clockLoadStr();edkEnd();
    //write the string
    printf("%s",this->str);edkEnd();fflush(stdout);edkEnd();
}
