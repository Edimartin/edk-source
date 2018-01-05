/*
Library EDK - How to use Extensible Development Kit
Copyright (C) 2013 Eduardo Moura Sales Martins
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
