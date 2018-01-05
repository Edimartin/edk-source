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

#include <stdio.h>

#include "edk/watch/FPS.h"
#include "edk/String.h"
#include "edk/thread/Thread.h"

//Thread function to run the thread inside
edk::classID threadFunction(edk::classID n){
    //FPS controller
    edk::watch::FPS fps;
    //read the FPS number from the pointer
    edk::uint32 fpsNumber = *(edk::uint32*)n;
    //set the FPS number
    fps.setFPS(fpsNumber);
    printf("\nThread %lu setFPS %u"
           ,edk::multi::Thread::getThisThreadID()
           ,fpsNumber
           );fflush(stdout);
    while(true){
        printf("\nThread %lu running in %u"
               ,edk::multi::Thread::getThisThreadID()
               ,edk::multi::Thread::getThisThreadCore()
               );fflush(stdout);
        //wait for the FPS setted by the pointer
        fps.waitForFPS();

    }
    return NULL;
}

int main(){
    //create two threads
    edk::multi::Thread t1,t2;
    //set the first FPS
    edk::uint32 n=15u;
    //Run the first thread on the first core
    if(t1.startIn(threadFunction,&n,0u)){
        printf("\nThread 1 started");fflush(stdout);
    }
    //set the FPS to the second thread
    n=30u;
    //run the second thread on the second core
    edk::watch::Time::sleepProcessMiliseconds(1000);
    if(t2.startIn(threadFunction,&n,1u)){
        printf("\nThread 2 started");fflush(stdout);
    }

    //wait until escape pressed to kill the threads
    while(true){
        if(edk::String::consoleKeyPressed())if(edk::String::consoleReadKey()==27){
            break;
        }
    }

    //wait for the threads to ends for 1000 milliseconds
    printf("\nWait for thread 1 end");fflush(stdout);
    t1.waitEnd(1000);
    if(t1.isAlive()){
        //kill the thread
        printf("\nKill thread 1");fflush(stdout);
        t1.kill();
    }

    printf("\nWait for thread 2 end");fflush(stdout);
    t2.waitEnd(1000);
    if(t2.isAlive()){
        //kill the thread
        printf("\nKill thread 1");fflush(stdout);
        t2.kill();
    }

    printf("\n\n");fflush(stdout);
    return 0;
}
