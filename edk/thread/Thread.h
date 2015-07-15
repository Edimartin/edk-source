#ifndef EDK_THREAD_H
#define EDK_THREAD_H

/*
Library C++ Thread - Multi-threading controller.
Copyright (C) 1012 Eduardo Moura Sales Martins
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

    bool runFunc();

    bool isAlive();

    bool waitEnd(uint64 milliseconds);

    bool waitEnd();

    bool kill();

    static void killThisThread();

    static void killAllThreads();


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

    /**
     *  The Thread ID. Number edk::uint32 with a diferent type in diferent librarys.
     */
    #if defined( WIN32) || defined( WIN64)
    HANDLE threadID;
    #endif
    #if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
    pthread_t threadID;
    #endif
};
} /* End of namespace multi */
} /* End of namespace edk */

#endif // edk_Thread_h
