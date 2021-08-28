/*
Library EDK - How to use Extensible Development Kit
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

#include "edk/watch/Time.h"
#include "edk/watch/FPS.h"

#include "edk/String.h"

//get month
const edk::char8* getMonth(edk::uint32 month){
    switch (month){
    case 1:
        return "January    ";
    case 2:
        return "February   ";
    case 3:
        return "March      ";
    case 4:
        return "April      ";
    case 5:
        return "May        ";
    case 6:
        return "June       ";
    case 7:
        return "July       ";
    case 8:
        return "August     ";
    case 9:
        return "September  ";
    case 10:
        return "October    ";
    case 11:
        return "November   ";
    case 12:
        return "December   ";
    }
    return     "month_error";
}
//get weekDay
const edk::char8* getWeekDay(edk::uint32 weekDay){
    switch (weekDay){
    case 1:
        return "Monday   ";
    case 2:
        return "Tuesday  ";
    case 3:
        return "Wednesday";
    case 4:
        return "Thursday ";
    case 5:
        return "Friday   ";
    case 6:
        return "Saturday ";
    case 7:
        return "Sunday   ";
    }
    return     "day_error";
}

int main(){
    bool looping;
    unsigned int counter=0u;
    unsigned int FPSPrint=0u;
    edk::watch::Time clock;
    edk::watch::Time fpsController;
    fpsController.start();

    clock.start();
    fpsController.start();
    looping=true;
    counter = 0u;
    FPSPrint = 0u;

    looping=true;

    while(looping){
        edk::String::consoleClear();
        //load the OS time
        clock.clockLoadLocalTime();
        printf("\nLocalTime %s %s %u_%u_%u %u:%u:%u %04u %d %s"
               ,getWeekDay(clock.clockGetDayOfWeek())
               ,getMonth(clock.clockGetMonth())
               ,clock.clockGetYear()
               ,clock.clockGetMonth()
               ,clock.clockGetDayOfMonth()
               ,clock.clockGetHour()
               ,clock.clockGetMinute()
               ,clock.clockGetSecond()
               ,clock.clockGetMillisecond()
               ,clock.clockGetGMTOff()
               ,clock.clockGetTimezoneAbreviation()
               );fflush(stdout);
        //load the GMT Time
        clock.clockLoadGMTime();
        printf("\nGMTime    %s %s %u_%u_%u %u:%u:%u %04u %d %s"
               ,getWeekDay(clock.clockGetDayOfWeek())
               ,getMonth(clock.clockGetMonth())
               ,clock.clockGetYear()
               ,clock.clockGetMonth()
               ,clock.clockGetDayOfMonth()
               ,clock.clockGetHour()
               ,clock.clockGetMinute()
               ,clock.clockGetSecond()
               ,clock.clockGetMillisecond()
               ,clock.clockGetGMTOff()
               ,clock.clockGetTimezoneAbreviation()
               );fflush(stdout);

        printf("\nPress any key to continue"
               );fflush(stdout);

        //sleep miliseconds
        edk::watch::Time::sleepProcessMiliseconds(33);
        if(edk::String::consoleKeyPressed()){
            edk::String::consoleReadKey();
            looping=false;
        }
    }

    looping=true;
    while(looping){
        edk::String::consoleClear();
        printf("\nTime EDK_Clock == %u OS_Clock %u FPS == %u\nPress 'c' or 'C' to clean the EDK_Clock\nPress escape to continue"
               ,clock.getMicroseconds()
               ,edk::watch::Time::getMicrosecondsReal()
               ,FPSPrint
               );fflush(stdout);
        //test the fps controller
        if(fpsController.getMicroseconds()>edk::watch::second){
            fpsController.start();
            FPSPrint = counter;
            counter=1u;
        }
        else{
            //else incremente counter
            counter++;
        }
        //get key pressed
        if(edk::String::consoleKeyPressed()){
            switch(edk::String::consoleReadKey()){
            case 'c':
            case 'C':
                clock.start();
                break;
            case 27:
                looping=false;
                break;
            }
        }
    }

    clock.start();
    fpsController.start();
    edk::watch::FPS fps;
    fps.setFPS(30);
    looping=true;
    counter = 0u;
    FPSPrint = 0u;
    while(looping){
        printf("\nPress escape to finish: Time EDK_Clock == %u FPS %u"
               ,clock.getMicroseconds()
               ,FPSPrint
               );fflush(stdout);
        //test the fps controller
        if(fpsController.getMicroseconds()>edk::watch::second){
            fpsController.start();
            FPSPrint = counter;
            counter=1u;
            printf("update FPS");fflush(stdout);
        }
        else{
            //else incremente counter
            counter++;
        }
        //get key pressed
        if(edk::String::consoleKeyPressed()){
            switch(edk::String::consoleReadKey()){
            case 27:
                looping=false;
                break;
            }
        }
        //sleep to wait for the FPS
        fps.waitForFPS();
    }

    printf("\n\n");fflush(stdout);
    return 0;
}
