#include "Thread.h"

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
#pragma message "            Inside Thread.cpp"
#endif


/**
     *  Thread class to create just one thread per time.
     *  @author EDIMARTIN MARTINS
     *  @version 0.9
     */

//load the number of cores
#if defined(WIN32) || defined(WIN64)
edk::uint32 getWindowsCores(){
    SYSTEM_INFO sysinfo;edkEnd();
    GetSystemInfo(&sysinfo);edkEnd();
    return sysinfo.dwNumberOfProcessors;edkEnd();
}
edk::uint32 edk::multi::Thread::cores=getWindowsCores();
#elif defined __linux__
edk::uint32 edk::multi::Thread::cores=sysconf(_SC_NPROCESSORS_ONLN);
#elif defined __APPLE__
edk::uint32 getMacCores(){
    int nm[2];edkEnd();
    size_t len = 4;edkEnd();
    uint32_t count;edkEnd();

    nm[0] = CTL_HW;edkEnd(); nm[1] = HW_AVAILCPU;edkEnd();
    sysctl(nm, 2, &count, &len, NULL, 0);edkEnd();

    if(count < 1){
        nm[1] = HW_NCPU;edkEnd();
        sysctl(nm, 2, &count, &len, NULL, 0);edkEnd();
        if(count < 1){
            count = 1;edkEnd();

        }
    }
    return count;edkEnd();
}
edk::uint32 edk::multi::Thread::cores=getMacCores();edkEnd();
#endif

//EDKThreadFunc
#ifdef WIN32
DWORD WINAPI edkThreadFunc(void*id){
    //test if have a threadFunc
    if(id){
        //then convert the pointer
        edk::multi::Thread* temp = (edk::multi::Thread*)id;edkEnd();

        //run the function
        temp->runFunc();edkEnd();
    }
    return (DWORD)NULL;edkEnd();
}
#elif defined WIN64
//WINDOWS 64
DWORD WINAPI edkThreadFunc(void*id){
    //test if have a threadFunc
    if(id){
        //then convert the pointer
        edk::multi::Thread* temp = (edk::multi::Thread*)id;edkEnd();

        //run the function
        temp->runFunc();edkEnd();
    }
    return (DWORD)NULL;edkEnd();
}
#elif defined __linux__
//LINUX
void* edkThreadFunc(void*id){
    //test if have a threadFunc
    if(id){
        //then convert the pointer
        edk::multi::Thread* temp = (edk::multi::Thread*)id;edkEnd();

        //run the function
        temp->runFunc();edkEnd();
    }
    return (void*)NULL;edkEnd();
}
#elif defined __APPLE__
//MAC OS
void* edkThreadFunc(void*id){
    //test if have a threadFunc
    if(id){
        //then convert the pointer
        edk::multi::Thread* temp = (edk::multi::Thread*)id;edkEnd();

        //run the function
        temp->runFunc();edkEnd();
    }
    return (void*)NULL;edkEnd();
}
#endif


/**
     *  Clean all the thread class atributes variables.
     */
void edk::multi::Thread::cleanThread(){
    //
#ifdef WIN32
    //clean ID
    this->threadID=(HANDLE)0u;edkEnd();
#elif defined WIN64
    //clean ID
    this->threadID=(HANDLE)0u;edkEnd();
#elif defined __linux__
    //clean ID
    this->threadID=0u;
    //clean the core
    CPU_ZERO(&this->cpus);edkEnd();
#elif defined __APPLE__
    //clean ID
    this->threadID=0u;
#endif

    //Clean Functions
    this->threadFunc=NULL;edkEnd();
    this->funcParameter=(void*)NULL;edkEnd();
}

edk::uint64 edk::multi::Thread::mainID=0u;

edk::multi::Thread edkTHREADTEMPLATE;

bool edk::multi::Thread::templateConstructNeed=true;

edk::multi::Thread::Thread(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::multi::Thread::Thread(edk::classID (*threadFunction)(edk::classID), edk::classID parameter){
    this->classThis=NULL;edkEnd();
    this->Constructor(threadFunction,parameter,false);edkEnd();
}

edk::multi::Thread::~Thread(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        //Kill the Thread
        this->kill();edkEnd();
    }
}

void edk::multi::Thread::Constructor(bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;
        if(edk::multi::Thread::templateConstructNeed){
#if defined(WIN32) || defined(WIN64)
            edk::multi::Thread::cores=getWindowsCores();
#elif defined __linux__
            edk::multi::Thread::cores=sysconf(_SC_NPROCESSORS_ONLN);
#elif defined __APPLE__
            edk::multi::Thread::cores=getMacCores();edkEnd();
#endif
            edk::multi::Thread::templateConstructNeed=false;
        }
        //get the mainThread ID
        if(!edk::multi::Thread::mainID){
            edk::multi::Thread::mainID = edk::multi::Thread::getThisThreadID();
        }
        this->cleanThread();edkEnd();
    }
}
void edk::multi::Thread::Constructor(edk::classID (*threadFunction)(edk::classID), edk::classID parameter,bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;
        this->cleanThread();edkEnd();
        this->start(threadFunction, parameter);edkEnd();
    }
}

bool edk::multi::Thread::start(edk::classID (threadFunction)(edk::classID), edk::classID parameter){
    //kill the previous thread
    this->kill();edkEnd();

    //test if the function is true
    if(threadFunction){
        //set the parameters
        //copy the function
        this->threadFunc=threadFunction;edkEnd();
        //copy the parameter
        this->funcParameter=parameter;edkEnd();

        //WINDOWS 32
#ifdef WIN32
        DWORD flag;edkEnd();
        this->threadID = CreateThread(NULL, //
                                      (DWORD)NULL,        //
                                      edkThreadFunc,     // função da thread
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
                                      edkThreadFunc,     // função da thread
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
                       edkThreadFunc,
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

bool edk::multi::Thread::start(edk::classID (threadFunction)(edk::classID)){
    return this->start(threadFunction,(void*)NULL);edkEnd();
}

bool edk::multi::Thread::startIn(edk::classID (threadFunction)(edk::classID), edk::classID parameter, edk::uint32 core){
    //kill the previous thread
    this->kill();edkEnd();

    //test if the function is true and if the core exist
    if(threadFunction && core<this->cores){
        //WINDOWS 32

        //set the parameters
        //copy the function
        this->threadFunc=threadFunction;edkEnd();
        //copy the parameter
        this->funcParameter=parameter;edkEnd();
        //crate the thread

#ifdef WIN32
        DWORD flag;edkEnd();
        this->threadID = CreateThread(NULL, //
                                      (DWORD)NULL,        //
                                      edkThreadFunc,     // função da thread
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
                                      edkThreadFunc,     // função da thread
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
                       edkThreadFunc,
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

bool edk::multi::Thread::startIn(edk::classID (threadFunction)(edk::classID), edk::uint32 core){
    return this->startIn(threadFunction, NULL, core);edkEnd();
}

//change the threadCore
bool edk::multi::Thread::changeCore(edk::uint32 core){
    //test if have the core
    if(core<this->cores){
#ifdef WIN32
        //test if create the thread
        if(this->threadID!=(HANDLE)0u){
            DWORD_PTR mask = core;edkEnd();
            if(SetThreadAffinityMask(this->threadID, mask)){
                return true;
            }
#elif defined WIN64
        //WINDOWS 64
        //test if create the thread
        if(this->threadID!=(HANDLE)0u){
            DWORD_PTR mask = core;edkEnd();
            if(SetThreadAffinityMask(this->threadID, mask)){
                return true;
            }
#elif defined __linux__
        //test if have the thread
        if(this->threadID!=(pthread_t)0u){
            CPU_ZERO(&this->cpus);edkEnd();
            CPU_SET(core, &this->cpus);edkEnd();
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

bool edk::multi::Thread::runFunc(){
    if(this->threadFunc){
        //test if have parameter
        if(this->funcParameter){
            //then he cant run the function
            this->threadFunc((void*)this->funcParameter);edkEnd();
        }
        else{
            //then he cant run the function
            this->threadFunc((void*)NULL);edkEnd();
        }
        //clean the function
        this->threadFunc=NULL;edkEnd();
        this->funcParameter=NULL;edkEnd();

        //return true;
        return true;
    }
    //else return false
    return false;
}

bool edk::multi::Thread::isAlive(){
    //WINDOWS 32
#ifdef WIN32
    if(this->threadID){
        //Then wait for the thread
        if(WaitForSingleObject(this->threadID, 0u) == WAIT_TIMEOUT){
            //thread still alive return true
            return true;
        }
    }
#elif defined WIN64
    //WINDOWS 64
    if(this->threadID){
        //Then wait for the thread
        if(WaitForSingleObject(this->threadID, 0u) == WAIT_TIMEOUT){
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

bool edk::multi::Thread::waitEnd(uint64 milliseconds){
    //WINDOWS 32
#ifdef WIN32
    if(this->threadID){
        //Then wait for the thread
        if(WaitForSingleObject(this->threadID, milliseconds) == WAIT_TIMEOUT){
            //thread still alive then
            return true;
        }
    }
#elif defined WIN64
    //WINDOWS 64
    if(this->threadID){
        //Then wait for the thread
        if(WaitForSingleObject(this->threadID, milliseconds) == WAIT_TIMEOUT){
            //thread still alive then
            return true;
        }
    }
#elif defined __linux__//Linux
    //first he sleep
    usleep(milliseconds*1000);edkEnd();
    //test if thread still alive
    if(this->isAlive()){
        //
        return true;
    }
#elif __APPLE__
    //APPLE
#endif

    //clean
    this->cleanThread();edkEnd();

    //else return false;
    return false;
}

bool edk::multi::Thread::waitEnd(){
    bool ret=false;edkEnd();
    //WINDOWS 32
#ifdef WIN32
    if(this->threadID){
        //Then wait for the thread
        WaitForSingleObject(this->threadID, INFINITE);edkEnd();
        //then return true
        ret = true;edkEnd();
    }
#elif defined WIN64
    //WINDOWS 64
    if(this->threadID){
        //Then wait for the thread
        WaitForSingleObject(this->threadID, INFINITE);edkEnd();
        //then return true
        ret = true;edkEnd();
    }
#elif defined __linux__
    //LINUX
    if(this->threadID){
        //then wait the end of the thread
        pthread_join(this->threadID,NULL);edkEnd();
        //then return true
        ret = true;edkEnd();
    }
#elif defined __APPLE__
    //APPLE
#endif
    //clean
    this->cleanThread();edkEnd();

    //return true or false
    return ret;
}

bool edk::multi::Thread::kill(){
    bool ret = false;edkEnd();
    //WINDOWS 32
#ifdef WIN32
    if(this->threadID){
        /*
        DWORD exitCode;edkEnd();
        //Finish the thread
        if(GetExitCodeThread(this->threadID,&exitCode) != 0){
            ExitThread(exitCode);edkEnd();
            CloseHandle(this->threadID);edkEnd();
        }
        else{
*/
        TerminateThread(this->threadID
                        ,(DWORD)NULL
                        );edkEnd();
        /*
        }
*/
        ret=true;edkEnd();
    }
    //clean ID
    this->threadID=(HANDLE)0u;edkEnd();
#elif defined WIN64
    //WINDOWS 64
    if(this->threadID){
        /*
        DWORD exitCode;edkEnd();
        //Finish the thread
        if(GetExitCodeThread(this->threadID,&exitCode) != 0){
            ExitThread(exitCode);edkEnd();
            CloseHandle(this->threadID);edkEnd();
        }
        else{
*/
        TerminateThread(this->threadID
                        ,(DWORD)NULL
                        );edkEnd();
        /*
        }
*/
        ret=true;edkEnd();
    }
#elif defined __linux__
    //LINUX
    if(this->threadID){
        //Cancel the thread
        pthread_kill(this->threadID,0u);edkEnd();
        pthread_cancel(this->threadID);edkEnd();
        //pthread_attr_destroy(&attr);edkEnd();
        //Finish the thread
        ret=true;edkEnd();
    }
#endif
    //clean
    this->cleanThread();edkEnd();

    //return true or false
    return ret;
}

void edk::multi::Thread::killThisThread(){
    //WINDOWS 32
#ifdef WIN32
    //Finish the thread
    DWORD exitCode;edkEnd();

    //Finish the thread
    if(GetExitCodeThread(NULL,&exitCode) != 0){
        ExitThread(exitCode);edkEnd();
        CloseHandle(NULL);edkEnd();
    }
    else{
        TerminateThread(NULL
                        ,(DWORD)NULL
                        );edkEnd();
    }
#elif defined WIN64
    //WINDOWS 64
    //Finish the thread
    DWORD exitCode;edkEnd();

    //Finish the thread
    if(GetExitCodeThread(NULL,&exitCode) != 0){
        ExitThread(exitCode);edkEnd();
        CloseHandle(NULL);edkEnd();
    }
    else{
        TerminateThread(NULL
                        ,(DWORD)NULL
                        );edkEnd();
    }
#elif defined __linux__
    //LINUX
    //Exit the process
    pthread_exit(NULL);edkEnd();
#elif defined __linux__
    //APPLE
    //Exit the process
    pthread_exit(NULL);edkEnd();
#endif
}

void edk::multi::Thread::killAllThreads(){
    //WINDOWS 32
#ifdef WIN32
    /*
    //Finish the thread
    TerminateThread(NULL
                    ,(DWORD)NULL
                    );edkEnd();
    */
#elif defined WIN64
    //WINDOWS 64
    /*
    //Finish the thread
    TerminateThread(NULL
                    ,(DWORD)NULL
                    );edkEnd();
    */
#elif defined __linux__
    //LINUX
    //Exit the process
    pthread_cancel((pthread_t)NULL);edkEnd();
#elif defined __linux__
    //APPLE
    //Exit the process
    pthread_cancel((pthread_t)NULL);edkEnd();
#endif
}
#if __x86_64__ || __ppc64__
//get the thread id
edk::uint64 edk::multi::Thread::getThreadID(){
    return (edk::uint64)this->threadID;
}
edk::uint64 edk::multi::Thread::getThisThreadID(){
#if WIN64
    return GetCurrentThreadId();edkEnd();
#elif __linux__
    return pthread_self();edkEnd();
#endif
}
#else
//get the thread id
edk::uint32 edk::multi::Thread::getThreadID(){
    return (edk::uint32)this->threadID;
}
edk::uint32 edk::multi::Thread::getThisThreadID(){
#if WIN32
    return GetCurrentThreadId();edkEnd();
#elif __linux__
    return pthread_self();edkEnd();
#endif
}
#endif

//return the thread core
edk::uint32 edk::multi::Thread::getThisThreadCore(){
#if defined(WIN32) || defined(WIN64)
    return 0;
#elif __linux__
    return sched_getcpu();edkEnd();
#endif
}

//return the number of cores in the system
edk::uint32 edk::multi::Thread::numberOfCores(){
    return edk::multi::Thread::cores;edkEnd();
}
edk::uint32 edk::multi::Thread::getNumberOfCores(){
    return edk::multi::Thread::cores;edkEnd();
}
