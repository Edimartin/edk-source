#include "Thread.h"

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
#warning "            Inside Thread.cpp"
#endif

namespace edk {
namespace multi {


/**
     *  Thread class to create just one thread per time.
     *  @author EDIMARTIN MARTINS
     *  @version 0.9
     */

//load the number of cores
#if defined(WIN32) || defined(WIN64)
edk::uint32 getWindowsCores(){
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    return sysinfo.dwNumberOfProcessors;
}
edk::uint32 Thread::cores=getWindowsCores();
#elif defined __linux__
edk::uint32 Thread::cores=sysconf(_SC_NPROCESSORS_ONLN);
#elif defined __APPLE__
edk::uint32 getMacCores(){
    int nm[2];
    size_t len = 4;
    uint32_t count;

    nm[0] = CTL_HW; nm[1] = HW_AVAILCPU;
    sysctl(nm, 2, &count, &len, NULL, 0);

    if(count < 1) {
        nm[1] = HW_NCPU;
        sysctl(nm, 2, &count, &len, NULL, 0);
        if(count < 1) { count = 1; }
    }
    return count;
}
edk::uint32 Thread::cores=getMacCores();
#endif

//EDKThreadFunc
#ifdef WIN32
DWORD WINAPI edkThreadFunc(void*id){
    //test if have a threadFunc
    if(id){
        //then convert the pointer
        edk::multi::Thread* temp = (edk::multi::Thread*)id;

        //run the function
        temp->runFunc();
    }
    return (DWORD)NULL;
}
#elif defined WIN64
//WINDOWS 64
DWORD WINAPI edkThreadFunc(void*id){
    //test if have a threadFunc
    if(id){
        //then convert the pointer
        edk::multi::Thread* temp = (edk::multi::Thread*)id;

        //run the function
        temp->runFunc();
    }
    return (DWORD)NULL;
}
#elif defined __linux__
//LINUX
void* edkThreadFunc(void*id){
    //test if have a threadFunc
    if(id){
        //then convert the pointer
        edk::multi::Thread* temp = (edk::multi::Thread*)id;

        //run the function
        temp->runFunc();
    }
    return (void*)NULL;
}
#elif defined __APPLE__
//MAC OS
void* edkThreadFunc(void*id){
    //test if have a threadFunc
    if(id){
        //then convert the pointer
        edk::multi::Thread* temp = (edk::multi::Thread*)id;

        //run the function
        temp->runFunc();
    }
    return (void*)NULL;
}
#endif


/**
     *  Clean all the thread class atributes variables.
     */
void Thread::cleanThread(){
    //
#ifdef WIN32
    //clean ID
    this->threadID=(HANDLE)0u;
#elif defined WIN64
    //clean ID
    this->threadID=(HANDLE)0u;
#elif defined __linux__
    //clean ID
    this->threadID=0u;
    //clean the core
    CPU_ZERO(&this->cpus);
#elif defined __APPLE__
    //clean ID
    this->threadID=0u;
#endif

    //Clean Functions
    this->threadFunc=NULL;
    this->funcParameter=(void*)NULL;
}



Thread::Thread(){
    this->cleanThread();
}

Thread::Thread(classID (*threadFunction)(classID), classID parameter){
    this->cleanThread();
    this->start(threadFunction, parameter);
}

Thread::~Thread(){
    //Kill the Thread
    this->kill();
}

bool Thread::start(classID (threadFunction)(classID), classID parameter){
    //kill the previous thread
    this->kill();

    //test if the function is true
    if(threadFunction){
        //WINDOWS 32
#ifdef WIN32
        DWORD flag;
        this->threadID = CreateThread(NULL, //
                                      (DWORD)NULL,        //
                                      edkThreadFunc,     // função da thread
                                      (void*)this,        // parâmetro da thread
                                      (DWORD)NULL,        //
                                      &flag);
        //test if create the thread
        if(this->threadID!=(HANDLE)0u){
#elif defined WIN64
        //WINDOWS 64
        DWORD flag;
        this->threadID = CreateThread(NULL, //
                                      (DWORD)NULL,        //
                                      edkThreadFunc,     // função da thread
                                      (void*)this,        // parâmetro da thread
                                      (DWORD)NULL,        //
                                      &flag);
        //test if create the thread
        if(this->threadID!=(HANDLE)0u){
#elif defined __linux__
        //LINUX
        pthread_attr_t attr;
        pthread_attr_init(&attr);

        //set the parameters
        //copy the function
        this->threadFunc=threadFunction;
        //copy the parameter
        this->funcParameter=parameter;
        //crate the thread

        pthread_create(&threadID,
                       &attr,
                       edkThreadFunc,
                       (void*)this);
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
    this->cleanThread();
    //else he clean the func
    this->threadFunc=NULL;
    return false;
}

bool Thread::start(classID (threadFunction)(classID)){
    return this->start(threadFunction,(void*)NULL);
}

bool Thread::startIn(classID (threadFunction)(classID), classID parameter, edk::uint32 core){

    //kill the previous thread
    this->kill();

    //test if the function is true and if the core exist
    if(threadFunction && core<this->cores){
        //WINDOWS 32
#ifdef WIN32
        DWORD flag;
        this->threadID = CreateThread(NULL, //
                                      (DWORD)NULL,        //
                                      edkThreadFunc,     // função da thread
                                      (void*)this,        // parâmetro da thread
                                      (DWORD)NULL,        //
                                      &flag);
        //test if create the thread
        if(this->threadID!=(HANDLE)0u){
            DWORD_PTR mask = core;
            SetThreadAffinityMask(this->threadID, mask);
#elif defined WIN64
        //WINDOWS 64
        DWORD flag;
        this->threadID = CreateThread(NULL, //
                                      (DWORD)NULL,        //
                                      edkThreadFunc,     // função da thread
                                      (void*)this,        // parâmetro da thread
                                      (DWORD)NULL,        //
                                      &flag);
        //test if create the thread
        if(this->threadID!=(HANDLE)0u){
            DWORD_PTR mask = core;
            SetThreadAffinityMask(this->threadID, mask);
#elif defined __linux__
        //LINUX
        pthread_attr_t attr;
        CPU_SET(core, &this->cpus);
        //start the attribute
        pthread_attr_init(&attr);
        //set the core on the attribute
        pthread_attr_setaffinity_np(&attr, sizeof(cpu_set_t), &this->cpus);

        //set the parameters
        //copy the function
        this->threadFunc=threadFunction;
        //copy the parameter
        this->funcParameter=parameter;
        //crate the thread

        //set affinity
        pthread_create(&threadID,
                       &attr,
                       edkThreadFunc,
                       (void*)this);
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
    this->cleanThread();
    //else he clean the func
    this->threadFunc=NULL;
    return false;
}

bool Thread::startIn(classID (threadFunction)(classID), edk::uint32 core){
    return this->startIn(threadFunction, NULL, core);
}

//change the threadCore
bool Thread::changeCore(edk::uint32 core){
    //test if have the core
    if(core<this->cores){
#ifdef WIN32
        //test if create the thread
        if(this->threadID!=(HANDLE)0u){
            DWORD_PTR mask = core;
            if(SetThreadAffinityMask(this->threadID, mask)){
                return true;
            }
#elif defined WIN64
        //WINDOWS 64
        //test if create the thread
        if(this->threadID!=(HANDLE)0u){
            DWORD_PTR mask = core;
            if(SetThreadAffinityMask(this->threadID, mask)){
                return true;
            }
#elif defined __linux__
        //test if have the thread
        if(this->threadID!=(pthread_t)0u){
            CPU_ZERO(&this->cpus);
            CPU_SET(core, &this->cpus);
            //set the core
            if(!pthread_setaffinity_np(this->threadID,sizeof(cpu_set_t), &this->cpus)){
                return true;
            }
#elif defined __APPLE__
        //APPLE
#endif
        }
    }
return false;
}

bool Thread::runFunc(){
    if(this->threadFunc){
        //test if have parameter
        if(this->funcParameter){
            //then he cant run the function
            this->threadFunc((void*)this->funcParameter);
        }
        else{
            //then he cant run the function
            this->threadFunc((void*)NULL);
        }
        //clean the function
        this->threadFunc=NULL;
        this->funcParameter=NULL;

        //return true;
        return true;
    }
    //else return false
    return false;
}

bool Thread::isAlive(){
    //WINDOWS 32
#ifdef WIN32
    if(this->threadID){
        //Then wait for the thread
        if(WaitForSingleObject(threadID, 0u) == WAIT_TIMEOUT){
            //thread still alive return true
            return true;
        }
    }
#elif defined WIN64
    //WINDOWS 64
    if(this->threadID){
        //Then wait for the thread
        if(WaitForSingleObject(threadID, 0u) == WAIT_TIMEOUT){
            //thread still alive return true
            return true;
        }
    }
#elif defined __linux__
    //WINDOWS 64
    if(this->threadID){
        //Then wait for the thread
        if(pthread_kill(this->threadID, 0u)!=3u){
            //thread still alive return true
            return true;
        }
    }
#elif defined __APPLE__
    //APPLE
#endif
    //else return false;
    return false;
}

bool Thread::waitEnd(uint64 milliseconds){
    //WINDOWS 32
#ifdef WIN32
    if(this->threadID){
        //Then wait for the thread
        if(WaitForSingleObject(threadID, milliseconds) == WAIT_TIMEOUT){
            //thread still alive then
            return true;
        }
    }
#elif defined WIN64
    //WINDOWS 64
    if(this->threadID){
        //Then wait for the thread
        if(WaitForSingleObject(threadID, milliseconds) == WAIT_TIMEOUT){
            //thread still alive then
            return true;
        }
    }
#elif defined __linux__//Linux
    //first he sleep
    usleep(milliseconds*1000);
    //test if thread still alive
    if(this->isAlive()){
        //
        return true;
    }
#elif __APPLE__
    //APPLE
#endif

    //clean
    this->cleanThread();

    //else return false;
    return false;
}

bool Thread::waitEnd(){
    bool ret=false;
    //WINDOWS 32
#ifdef WIN32
    if(this->threadID){
        //Then wait for the thread
        WaitForSingleObject(threadID, INFINITE);
        //then return true
        ret = true;
    }
#elif defined WIN64
    //WINDOWS 64
    if(this->threadID){
        //Then wait for the thread
        WaitForSingleObject(threadID, INFINITE);
        //then return true
        ret = true;
    }
#elif defined __linux__
    //LINUX
    if(this->threadID){
        //then wait the end of the thread
        pthread_join(this->threadID,NULL);
        //then return true
        ret = true;
    }
#elif defined __APPLE__
    //APPLE
#endif
    //clean
    this->cleanThread();

    //return true or false
    return ret;
}

bool Thread::kill(){
    bool ret = false;
    //WINDOWS 32
#ifdef WIN32
    if(this->threadID){
        //Finish the thread
        TerminateThread(this->threadID
                        ,(DWORD)NULL
                        );
        ret=true;
    }
    //clean ID
    this->threadID=(HANDLE)0u;
#elif defined WIN64
    //WINDOWS 64
    if(this->threadID){
        //Finish the thread
        TerminateThread(this->threadID
                        ,(DWORD)NULL
                        );
        ret=true;
    }
#elif defined __linux__
    //LINUX
    if(this->threadID){
        //Cancel the thread
        pthread_cancel(this->threadID);
        //pthread_attr_destroy(&attr);
        //Finish the thread
        ret=true;
    }
#endif
    //clean
    this->cleanThread();

    //return true or false
    return ret;
}

void Thread::killThisThread(){
    //WINDOWS 32
#ifdef WIN32
    //Finish the thread
    TerminateThread(NULL
                    ,(DWORD)NULL
                    );
#elif defined WIN64
    //WINDOWS 64
    //Finish the thread
    TerminateThread(NULL
                    ,(DWORD)NULL
                    );
#elif defined __linux__
    //LINUX
    //Exit the process
    pthread_exit(NULL);
#elif defined __linux__
    //APPLE
    //Exit the process
    pthread_exit(NULL);
#endif
}

void Thread::killAllThreads(){
    //WINDOWS 32
#ifdef WIN32
    /*
    //Finish the thread
    TerminateThread(NULL
                    ,(DWORD)NULL
                    );
    */
#elif defined WIN64
    //WINDOWS 64
    /*
    //Finish the thread
    TerminateThread(NULL
                    ,(DWORD)NULL
                    );
    */
#elif defined __linux__
    //LINUX
    //Exit the process
    pthread_cancel((pthread_t)NULL);
#elif defined __linux__
    //APPLE
    //Exit the process
    pthread_cancel((pthread_t)NULL);
#endif
}
#if __x86_64__ || __ppc64__
//get the thread id
edk::uint64 Thread::getThisThreadID(){
#if WIN64
    return GetCurrentThreadId();
#elif __linux__
    return pthread_self();
#endif
}
#else
//get the thread id
edk::uint32 Thread::getThisThreadID(){
#if WIN32
    return GetCurrentThreadId();
#elif __linux__
    return pthread_self();
#endif
}
#endif

//return the thread core
edk::uint32 Thread::getThisThreadCore(){
#if defined(WIN32) || defined(WIN64)
    return 0;
#elif __linux__
    return sched_getcpu();
#endif
}

edk::uint32 Thread::numberOfCores(){
    return edk::multi::Thread::cores;
}
}

} /* End of namespace edk */
