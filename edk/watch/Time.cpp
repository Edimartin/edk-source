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


//get day of the year
edk::uint32 edk::watch::Time::getDayOfYear(edk::uint8 dayOfMonth,edk::uint8 month,edk::uint32 year){
    edk::uint32 ret = 0u;
    if(month<12){
        ret = dayOfMonth;
        for(edk::uint8 i=0u;i<month;i++){
            ret += edk::watch::Time::monthDays[i];
        }
        //test if need add the bisext year day
        if(month>2u){
            //calculate if add the bisext day
            if(edk::watch::Time::isBisext(year)){
                ret++;
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
    overflow=false;

#if defined(_WIN32) || defined(_WIN64)
    this->timeStart = edk::watch::Time::getMicrosecondsReal();
#elif defined(__linux__) || defined(__APPLE__)
    this->timeStart = edk::watch::Time::getMicrosecondsReal();
#endif
}
void edk::watch::Time::remove(edk::uint32 microseconds){
    //Remove milliseconds from the cronometer just add milliseconds in the timeStart
    this->timeStart += microseconds;
}
void edk::watch::Time::removeSeconds(edk::float32 seconds){
    if(seconds>0.f)
        this->remove((edk::uint32)(edk::watch::second * seconds));
}

void edk::watch::Time::increase(uint32 microseconds){
    if(microseconds<=this->timeStart){
        this->timeStart -= microseconds;
    }
    else{
        //
        this->timeStart = 0xFFFFFFFF-(microseconds-this->timeStart);
    }
}
void edk::watch::Time::increaseSeconds(edk::float32 seconds){
    if(seconds>0.f)
        this->increase((edk::uint32)(edk::watch::second * seconds));
}

edk::uint32 edk::watch::Time::getMicroseconds(){
#if defined(_WIN32) || defined(_WIN64)
    //Windows
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    edk::uint32 temp = (edk::uint32)(li.QuadPart * 1000000 / this->PCFreq.QuadPart );
    return (temp - this->timeStart);
#elif defined(__linux__) || defined(__APPLE__)
    edk::uint32 temp = edk::watch::Time::getMicrosecondsReal();
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

edk::uint32 edk::watch::Time::getMicrosecondsReal(){
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

//return the seconds in float
edk::float32 edk::watch::Time::getSeconds(){
    return this->getMicroseconds() * edk::watch::microsecond;
}

//test if occur overflow
bool edk::watch::Time::overflowOccurred(){
    this->getMicroseconds();
    return this->overflow;
}

edk::float32 edk::watch::Time::getEstimativeFrame(){
    edk::uint32 mili=this->getMicroseconds();
    if(mili>0u)
        return (edk::watch::second/(edk::float32)mili);
    return 0.0f;
}

//save the distance
void edk::watch::Time::saveDistance(){
    this->saveTimeDistance = this->getMicroseconds();
}
//paste the distance
void edk::watch::Time::pasteDistance(){
    this->timeStart-=this->saveTimeDistance;
    this->saveTimeDistance=0u;
}

void edk::watch::Time::sleepProcessMiliseconds(edk::uint32 Milliseconds){
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

#if defined(_WIN32) || defined(_WIN64)
void edk::watch::Time::sleepProcessMicroseconds(edk::uint32){
    //error. cant find microsleep in Windows
#elif defined(__linux__)//Linux
void edk::watch::Time::sleepProcessMicroseconds(edk::uint32 Microseconds){
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
edk::uint64 edk::watch::Time::getTimeSinceEpoch(){
    return (edk::uint64) time(NULL);
}

edk::uint64 edk::watch::Time::getTimeSinceEpoch(edk::uint8 hour,edk::uint8 minute,edk::uint8 second,edk::uint8 dayOfMonth,edk::uint8 month,edk::uint32 year){
    if(year>1970)year-=1970;
    if(dayOfMonth)dayOfMonth--;
    if(month)month--;
    edk::uint64 ret = (edk::uint64)second
            + ((edk::uint64)minute * 60u)
            + ((edk::uint64)hour * 3600u)
            + ((edk::uint64)edk::watch::Time::getDayOfYear(dayOfMonth,month,year) * 86400)
            + ((edk::uint64)(year) * 31536000)
            + (((edk::uint64)(year) / 4) * 86400)
            ;
    //
    return ret;
}

void edk::watch::Time::clockLoadGMTime(){
    return this->clockLoadGMTime(edk::watch::Time::getTimeSinceEpoch());
}

void edk::watch::Time::clockLoadGMTime(edk::uint64 timeSinceEpoch){
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

void edk::watch::Time::clockLoadLocalTime(){
    return this->clockLoadLocalTime((edk::uint64) time(NULL));
}

void edk::watch::Time::clockLoadLocalTime(edk::uint64 timeSinceEpoch){
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

edk::uint32 edk::watch::Time::clockGetMillisecond(){
    //set the struct
    ftime(&tmb);
    //return the time
    return tmb.millitm;
}

edk::uint8 edk::watch::Time::clockGetSecond(){
#ifdef _MSC_VER
    return systemClock.tm_sec;
#else
    if(systemClock)
        return systemClock->tm_sec;
    return 0u;
#endif
}

edk::uint8 edk::watch::Time::clockGetMinute(){
#ifdef _MSC_VER
    return systemClock.tm_min;
#else
    if(systemClock)
        return systemClock->tm_min;
    return 0u;
#endif
}

edk::uint8 edk::watch::Time::clockGetHour(){
#ifdef _MSC_VER
    return systemClock.tm_hour;
#else
    if(systemClock)
        return systemClock->tm_hour;
    return 0u;
#endif
}

edk::uint8 edk::watch::Time::clockGetDayOfMonth(){
#ifdef _MSC_VER
    return systemClock.tm_mday;
#else
    if(systemClock)
        return systemClock->tm_mday;
    return 0u;
#endif
}

edk::uint8 edk::watch::Time::clockGetDayOfWeek(){
#ifdef _MSC_VER
    return systemClock.tm_wday+1u;
#else
    if(systemClock)
        return systemClock->tm_wday+1u;
    return 0u;
#endif
}

edk::uint32 edk::watch::Time::clockGetDayOfYear(){
#ifdef _MSC_VER
    return systemClock.tm_yday+1u;
#else
    if(systemClock)
        return systemClock->tm_yday+1u;
    return 0u;
#endif
}

edk::uint8 edk::watch::Time::clockGetMonth(){
#ifdef _MSC_VER
    return systemClock.tm_mon+1u;
#else
    if(systemClock)
        return systemClock->tm_mon+1u;
    return 0u;
#endif
}

edk::uint32 edk::watch::Time::clockGetYear(){
#ifdef _MSC_VER
    return systemClock.tm_year+1900u;
#else
    if(systemClock)
        return systemClock->tm_year+1900u;
    return 0u;
#endif
}

edk::int32 edk::watch::Time::clockGetGMTOff(){

#if defined(__WIN32__) || defined(__WIN64__)
        return 0u;
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

edk::char8* edk::watch::Time::clockGetTimezoneAbreviation(){
#if defined(__WIN32__) || defined(__WIN64__)
        return 0u;
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
