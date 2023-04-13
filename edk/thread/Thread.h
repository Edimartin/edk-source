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
#pragma message "Inside Thread"
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
#pragma message "    Compiling Thread"
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

    Thread(edk::classID (*threadFunction)(edk::classID), edk::classID parameter);

    virtual ~Thread();

    bool start(edk::classID (threadFunction)(edk::classID), edk::classID parameter);

    bool start(edk::classID (threadFunction)(edk::classID));

    bool startIn(edk::classID (threadFunction)(edk::classID), edk::classID parameter, edk::uint32 core);

    bool startIn(edk::classID (threadFunction)(edk::classID), edk::uint32 core);

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
    static inline edk::uint64 getMainThreadID(){return edk::multi::Thread::mainID;}
    static inline bool setMainThreadID(edk::uint64 id){
        if(id){
            edk::multi::Thread::mainID = id;
            return true;
        }
        return false;
    }
#else
    static edk::uint32 getThisThreadID();
    static inline edk::uint32 getMainThreadID(){return edk::multi::Thread::mainID;}
    static inline bool setMainThreadID(edk::uint32 id){
        if(id){
            edk::multi::Thread::mainID = id;
            return true;
        }
        return false;
    }
#endif
    //test if this thread is the main thread
    static inline bool isThisThreadMain(){if(edk::multi::Thread::mainID == edk::multi::Thread::getThisThreadID())return true;return false;}
    //save the main thread
    static inline bool saveThisThreadMain(){return edk::multi::Thread::setMainThreadID(edk::multi::Thread::getThisThreadID());}

    //return the thread core
    static edk::uint32 getThisThreadCore();

    //return the number of cores in the system
    static edk::uint32 numberOfCores();
    static edk::uint32 getNumberOfCores();


protected:

    void cleanThread();

    /**
     *  Pointer of the parameter of the function.
     */
    void* funcParameter;

private:

    /**
     *  Pointer of the user function. Seted on Start.
     */
    void* (*threadFunc)(void*);

    //number of cores on the system
    static edk::uint32 cores;

    //main thread ID
#if __x86_64__ || __ppc64__
    static edk::uint64 mainID;
#else
    static edk::uint32 mainID;
#endif

protected:
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

/* //TEMPORARY I HOPE TO FIX IT IN THE FUTURE

//EDKThreadClassFunc
#ifdef WIN32
DWORD WINAPI edkThreadClassFunc(void*id);
#elif defined WIN64
//WINDOWS 64
DWORD WINAPI edkThreadClassFunc(void*id);
#elif defined __linux__
//LINUX
void* edkThreadClassFunc(void*id);
#elif defined __APPLE__
//MAC OS
void* edkThreadClassFunc(void*id);
#endif




//Use a class template
template <typename typeTemplate>
class ThreadClass : public edk::multi::Thread{
public:
    ThreadClass(){
        this->cleanThread();edkEnd();
    }

    ThreadClass(edk::classID (typeTemplate::*threadClassFunc)(edk::classID), edk::classID parameter){
        this->cleanThread();edkEnd();
        this->start(threadClassFunc, parameter);edkEnd();
    }

    ~ThreadClass(){
        //Kill the Thread
        this->kill();edkEnd();
    }

    bool start(edk::classID (typeTemplate::*threadClassFunc)(edk::classID), edk::classID parameter){
        //kill the previous thread
        this->kill();edkEnd();

        //test if the function is true
        if(threadClassFunc){
            //set the parameters
            //copy the function
            this->threadClassFunc=threadClassFunc;edkEnd();
            //copy the parameter
            this->funcParameter=parameter;edkEnd();

            //WINDOWS 32
#ifdef WIN32
            DWORD flag;edkEnd();
            this->threadID = CreateThread(NULL, //
                                          (DWORD)NULL,        //
                                          edkThreadClassFunc, // função da thread
                                          (void*)this,        // parâmetro da thread
                                          (DWORD)NULL,        //
                                          &flag);edkEnd();
            //test if create the thread
            if(this->threadID!=(HANDLE)0u){
#elif defined WIN64
            //WINDOWS 64
            DWORD flag;edkEnd();
            this->threadID = CreateThread(NULL, //
                                          (DWORD)NULL,        //
                                          edkThreadClassFunc, // função da thread
                                          (void*)this,        // parâmetro da thread
                                          (DWORD)NULL,        //
                                          &flag);edkEnd();
            //test if create the thread
            if(this->threadID!=(HANDLE)0u){
#elif defined __linux__
            //LINUX
            pthread_attr_t attr;edkEnd();
            pthread_attr_init(&attr);edkEnd();
            //crate the thread

            pthread_create(&this->threadID,
                           &attr,
                           edkThreadClassFunc,
                           (void*)this);edkEnd();
            //test if create the thread
            if(this->threadID!=(pthread_t)0u){
#elif defined __APPLE__
            //APPLE
#endif
            //then return true;
            return true;
        }
    }

    //clean
    this->cleanThread();edkEnd();
    //else he clean the func
    this->threadClassFunc=NULL;edkEnd();
    return false;
}

bool start(edk::classID (typeTemplate::*threadClassFunc)(edk::classID)){
    return this->start(threadClassFunc,(void*)NULL);edkEnd();
}

bool startIn(edk::classID (typeTemplate::*threadClassFunc)(edk::classID), edk::classID parameter, edk::uint32 core){
    //kill the previous thread
    this->kill();edkEnd();

    //test if the function is true and if the core exist
    if(threadClassFunc && core<this->cores){
        //WINDOWS 32

        //set the parameters
        //copy the function
        this->threadFunc=threadClassFunc;edkEnd();
        //copy the parameter
        this->funcParameter=parameter;edkEnd();
        //crate the thread

#ifdef WIN32
        DWORD flag;edkEnd();
        this->threadID = CreateThread(NULL, //
                                      (DWORD)NULL,        //
                                      edkThreadClassFunc, // função da thread
                                      (void*)this,        // parâmetro da thread
                                      (DWORD)NULL,        //
                                      &flag);edkEnd();
        //test if create the thread
        if(this->threadID!=(HANDLE)0u){
            DWORD_PTR mask = core;edkEnd();
            SetThreadAffinityMask(this->threadID, mask);edkEnd();
#elif defined WIN64
        //WINDOWS 64
        DWORD flag;edkEnd();
        this->threadID = CreateThread(NULL, //
                                      (DWORD)NULL,        //
                                      edkThreadClassFunc, // função da thread
                                      (void*)this,        // parâmetro da thread
                                      (DWORD)NULL,        //
                                      &flag);edkEnd();
        //test if create the thread
        if(this->threadID!=(HANDLE)0u){
            DWORD_PTR mask = core;edkEnd();
            SetThreadAffinityMask(this->threadID, mask);edkEnd();
#elif defined __linux__
        //LINUX
        pthread_attr_t attr;edkEnd();
        CPU_SET(core, &this->cpus);edkEnd();
        //start the attribute
        pthread_attr_init(&attr);edkEnd();
        //set the core on the attribute
        pthread_attr_setaffinity_np(&attr, sizeof(cpu_set_t), &this->cpus);edkEnd();
        //set affinity
        pthread_create(&this->threadID,
                       &attr,
                       edkThreadClassFunc,
                       (void*)this);edkEnd();
        //test if create the thread
        if(this->threadID!=(pthread_t)0u){
#elif defined __APPLE__
        //APPLE
#endif
        //then return true;
        return true;
    }
}

//clean
this->cleanThread();edkEnd();
//else he clean the func
this->threadFunc=NULL;edkEnd();
return false;
}

bool startIn(edk::classID (typeTemplate::*threadClassFunc)(edk::classID), edk::uint32 core){
    return this->startIn(threadClassFunc, NULL, core);edkEnd();
}

bool runClassFunc(){
    if(this->threadClassFunc){
        //test if have parameter
        if(this->funcParameter){
            //then he cant run the function
            ((*this).*(this->threadClassFunc))((void*)this->funcParameter);edkEnd();
        }
        else{
            //then he cant run the function
            ((*this).*(this->threadClassFunc))((void*)NULL);edkEnd();
        }
        //clean the function
        this->threadClassFunc=NULL;edkEnd();
        this->funcParameter=NULL;edkEnd();

        //return true;
        return true;
    }
    //else return false
    return false;
}
private:
//Pointer of the user function. Setted on Start.
edk::classID (typeTemplate::*threadClassFunc)(edk::classID);
};
*/
} // End of namespace multi
} // End of namespace edk

/*

//EDKThreadClassFunc
template <typename typeTemplate>
#ifdef WIN32
DWORD WINAPI edkThreadClassFunc(void*id){
    //test if have a threadClassFunc
    if(id){
        //then convert the pointer
        edk::multi::ThreadClass<typeTemplate>* temp = (edk::multi::ThreadClass<typeTemplate>*)id;edkEnd();

        //run the function
        temp->runClassFunc();edkEnd();
    }
    return (DWORD)NULL;edkEnd();
}
#elif defined WIN64
//WINDOWS 64
DWORD WINAPI edkThreadClassFunc(void*id){
    //test if have a threadClassFunc
    if(id){
        //then convert the pointer
        edk::multi::ThreadClass<typeTemplate>* temp = (edk::multi::ThreadClass<typeTemplate>*)id;edkEnd();

        //run the function
        temp->runClassFunc();edkEnd();
    }
    return (DWORD)NULL;edkEnd();
}
#elif defined __linux__
//LINUX
void* edkThreadClassFunc(void*id){
    //test if have a threadClassFunc
    if(id){
        //then convert the pointer
        edk::multi::ThreadClass<typeTemplate>* temp = (edk::multi::ThreadClass<typeTemplate>*)id;edkEnd();

        //run the function
        temp->runClassFunc();edkEnd();
    }
    return (void*)NULL;edkEnd();
}
#elif defined __APPLE__
//MAC OS
void* edkThreadClassFunc(void*id){
    //test if have a threadClassFunc
    if(id){
        //then convert the pointer
        edk::multi::ThreadClass<typeTemplate>* temp = (edk::multi::ThreadClass<typeTemplate>*)id;edkEnd();

        //run the function
        temp->runClassFunc();edkEnd();
    }
    return (void*)NULL;edkEnd();
}
#endif
*/
#endif // edk_Thread_h
