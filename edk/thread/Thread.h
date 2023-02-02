#ifndef EDK_THREAD_H
#define EDK_THREAD_H

/*
Library C++ Thread - Multi-threading controller.
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
#warning "Inside Thread"
#endif

#pragma once
#include "../TypeVars.h"

//pThread
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
    #include <pthread.h>
    #include <sys/wait.h>
    //linux use the unistd
    #include <unistd.h>
#endif

//windows thread
#if defined(WIN32) || defined(WIN64) //Windows
#include <windows.h>
#endif

#include "../DebugFile.h"

#ifdef printMessages
#warning "    Compiling Thread"
#endif

/*LIB LINUX

-lpthread

*/

/*

FUNCTION SAMPLE
void* function(void* id){
    //
}

*/


namespace edk {
namespace multi{
class Thread {

 public:

    Thread();

    Thread(classID (*threadFunction)(classID), classID parameter);

    ~Thread();

    bool start(classID (threadFunction)(classID), classID parameter);

    bool start(classID (threadFunction)(classID));

    bool startIn(classID (threadFunction)(classID), classID parameter, edk::uint32 core);

    bool startIn(classID (threadFunction)(classID), edk::uint32 core);

    //change the threadCore
    bool changeCore(edk::uint32 core);

    bool runFunc();

    bool isAlive();

    bool waitEnd(uint64 milliseconds);

    bool waitEnd();

    bool kill();

    static void killThisThread();

    static void killAllThreads();

    //return the thread id
#if __x86_64__ || __ppc64__
    static edk::uint64 getThisThreadID();
#else
    static edk::uint32 getThisThreadID();
#endif

    //return the thread core
    static edk::uint32 getThisThreadCore();

    //return the number of cores in the system
    static edk::uint32 numberOfCores();
    static edk::uint32 getNumberOfCores();


 private:

    void cleanThread();


    /**
     *  Pointer of the user function. Seted on Start.
     */
    void* (*threadFunc)(void*);

    /**
     *  Pointer of the parameter of the function.
     */
    void* funcParameter;

    //number of cores on the system
    static edk::uint32 cores;

    /**
     *  The Thread ID. Number edk::uint32 with a diferent type in diferent librarys.
     */
    #if defined( WIN32) || defined( WIN64)
    HANDLE threadID;
    #endif
    #if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
    pthread_t threadID;
    //thread cpus to affinity
    cpu_set_t cpus;
    #endif
};
} /* End of namespace multi */
} /* End of namespace edk */

#endif // edk_Thread_h
