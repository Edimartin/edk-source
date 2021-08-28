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
