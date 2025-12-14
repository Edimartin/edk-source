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

edk::multi::Thread::TreeThreads edk::multi::Thread::treeThreads;

//load the number of cores
#if defined(WIN32) || defined(WIN64)
edk::uint32 getWindowsCores(){
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    return sysinfo.dwNumberOfProcessors;
}
edk::uint32 edk::multi::Thread::cores=getWindowsCores();
#elif defined __linux__
edk::uint32 edk::multi::Thread::cores=sysconf(_SC_NPROCESSORS_ONLN);
#elif defined __APPLE__
edk::uint32 getMacCores(){
    int nm[2];
    size_t len = 4;
    uint32_t count;

    nm[0] = CTL_HW;  nm[1] = HW_AVAILCPU;
    sysctl(nm, 2, &count, &len, NULL, 0);

    if(count < 1){
        nm[1] = HW_NCPU;
        sysctl(nm, 2, &count, &len, NULL, 0);
        if(count < 1){
            count = 1;

        }
    }
    return count;
}
edk::uint32 edk::multi::Thread::cores=getMacCores(); 
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

        temp->kill();
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
void edk::multi::Thread::cleanThread(){
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

    edk::multi::Thread::treeThreads.Constructor();

    edk::multi::Thread::treeThreads.remove(this);
}

bool edk::multi::Thread::templateConstructNeed=true;

edk::uint64 edk::multi::Thread::mainID=0u;

edk::multi::Thread edkTHREADTEMPLATE;

edk::multi::Thread::Thread(){
    this->classThis=NULL;
    this->Constructor();
}

edk::multi::Thread::Thread(edk::classID (*threadFunction)(edk::classID), edk::classID parameter){
    this->classThis=NULL;
    this->Constructor(threadFunction,parameter);
}

edk::multi::Thread::~Thread(){
    this->Destructor();
}

void edk::multi::Thread::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;
        if(edk::multi::Thread::templateConstructNeed){
#if defined(WIN32) || defined(WIN64)
            edk::multi::Thread::cores=getWindowsCores();
#elif defined __linux__
            edk::multi::Thread::cores=sysconf(_SC_NPROCESSORS_ONLN);
#elif defined __APPLE__
            edk::multi::Thread::cores=getMacCores();
#endif
            edk::multi::Thread::templateConstructNeed=false;
        }
        //get the mainThread ID
        if(!edk::multi::Thread::mainID){
            edk::multi::Thread::mainID = edk::multi::Thread::getThisThreadID();
        }
        this->cleanThread();
    }
}
void edk::multi::Thread::Constructor(edk::classID (*threadFunction)(edk::classID), edk::classID parameter){
    if(this->classThis!=this){
        this->classThis=this;
        this->cleanThread();
        this->start(threadFunction, parameter);
    }
}
void edk::multi::Thread::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        //Kill the Thread
        this->kill();
    }
}

bool edk::multi::Thread::start(edk::classID (threadFunction)(edk::classID), edk::classID parameter){
    //kill the previous thread
    this->kill();

    //test if the function is true
    if(threadFunction){
        //set the parameters
        //copy the function
        this->threadFunc=threadFunction;
        //copy the parameter
        this->funcParameter=parameter;

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
        //crate the thread

        pthread_create(&this->threadID,
                       &attr,
                       edkThreadFunc,
                       (void*)this);
        //test if create the thread
        if(this->threadID!=(pthread_t)0u){
#elif defined __APPLE__
        //APPLE
#endif
        edk::multi::Thread::treeThreads.add(this);
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

bool edk::multi::Thread::start(edk::classID (threadFunction)(edk::classID)){
    return this->start(threadFunction,(void*)NULL);
}

bool edk::multi::Thread::startIn(edk::classID (threadFunction)(edk::classID), edk::classID parameter, edk::uint32 core){
    //kill the previous thread
    this->kill();

    //test if the function is true and if the core exist
    if(threadFunction && core<this->cores){
        //WINDOWS 32

        //set the parameters
        //copy the function
        this->threadFunc=threadFunction;
        //copy the parameter
        this->funcParameter=parameter;
        //crate the thread

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
        //set affinity
        pthread_create(&this->threadID,
                       &attr,
                       edkThreadFunc,
                       (void*)this);
        //test if create the thread
        if(this->threadID!=(pthread_t)0u){
#elif defined __APPLE__
        //APPLE
#endif
        //then return true;
        edk::multi::Thread::treeThreads.add(this);
        return true;
    }
}

//clean
this->cleanThread(); 
//else he clean the func
this->threadFunc=NULL; 
return false;
}

bool edk::multi::Thread::startIn(edk::classID (threadFunction)(edk::classID), edk::uint32 core){
    return this->startIn(threadFunction, NULL, core);
}

//change the threadCore
bool edk::multi::Thread::changeCore(edk::uint32 core){
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

bool edk::multi::Thread::runFunc(){
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

bool edk::multi::Thread::waitEnd(){
    bool ret=false;
    //WINDOWS 32
#ifdef WIN32
    if(this->threadID){
        //Then wait for the thread
        WaitForSingleObject(this->threadID, INFINITE);
        //then return true
        ret = true;
    }
#elif defined WIN64
    //WINDOWS 64
    if(this->threadID){
        //Then wait for the thread
        WaitForSingleObject(this->threadID, INFINITE);
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

bool edk::multi::Thread::kill(){
    bool ret = false;
    //WINDOWS 32
#ifdef WIN32
    if(this->threadID){
        /*
        DWORD exitCode;
        //Finish the thread
        if(GetExitCodeThread(this->threadID,&exitCode) != 0){
            ExitThread(exitCode);
            CloseHandle(this->threadID);
        }
        else{
*/
        TerminateThread(this->threadID
                        ,(DWORD)NULL
                        );
        /*
        }
*/
        ret=true;
        edk::multi::Thread::treeThreads.remove(this);
    }
    //clean ID
    this->threadID=(HANDLE)0u;
#elif defined WIN64
    //WINDOWS 64
    if(this->threadID){
        /*
        DWORD exitCode;
        //Finish the thread
        if(GetExitCodeThread(this->threadID,&exitCode) != 0){
            ExitThread(exitCode);
            CloseHandle(this->threadID);
        }
        else{
*/
        TerminateThread(this->threadID
                        ,(DWORD)NULL
                        );
        /*
        }
*/
        ret=true;
        edk::multi::Thread::treeThreads.remove(this);
    }
#elif defined __linux__
    //LINUX
    if(this->threadID){
        //Cancel the thread
        pthread_kill(this->threadID,0u);
        pthread_cancel(this->threadID);
        //pthread_attr_destroy(&attr);
        //Finish the thread
        ret=true;
        edk::multi::Thread::treeThreads.remove(this);
    }
#endif
    //clean
    this->cleanThread();

    //return true or false
    return ret;
}

void edk::multi::Thread::killThisThread(){
    //WINDOWS 32
#ifdef WIN32
    //Finish the thread
    DWORD exitCode;

    //Finish the thread
    if(GetExitCodeThread(NULL,&exitCode) != 0){
        ExitThread(exitCode);
        CloseHandle(NULL);
    }
    else{
        TerminateThread(NULL
                        ,(DWORD)NULL
                        );
    }
#elif defined WIN64
    //WINDOWS 64
    //Finish the thread
    DWORD exitCode;

    //Finish the thread
    if(GetExitCodeThread(NULL,&exitCode) != 0){
        ExitThread(exitCode);
        CloseHandle(NULL);
    }
    else{
        TerminateThread(NULL
                        ,(DWORD)NULL
                        );
    }
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

void edk::multi::Thread::killAllThreads(){
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
edk::uint64 edk::multi::Thread::getThreadID(){
    return (edk::uint64)this->threadID;
}
edk::uint64 edk::multi::Thread::getThisThreadID(){
#if WIN64
    return GetCurrentThreadId();
#elif __linux__
    return pthread_self();
#endif
}
#else
//get the thread id
edk::uint32 edk::multi::Thread::getThreadID(){
    return (edk::uint32)this->threadID;
}
edk::uint32 edk::multi::Thread::getThisThreadID(){
#if WIN32
    return GetCurrentThreadId();
#elif __linux__
    return pthread_self();
#endif
}
#endif

//return the thread core
edk::uint32 edk::multi::Thread::getThisThreadCore(){
#if defined(WIN32) || defined(WIN64)
    return 0;
#elif __linux__
    return sched_getcpu();
#endif
}

//return the number of cores in the system
edk::uint32 edk::multi::Thread::numberOfCores(){
    return edk::multi::Thread::cores;
}
edk::uint32 edk::multi::Thread::getNumberOfCores(){
    return edk::multi::Thread::cores;
}
