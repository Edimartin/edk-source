#include "Mutex.h"

/*
Library C++ Mutex - Mutex fot threads.
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



#if defined(EDK_MUTEX_PRINT_DEBUG)
edk::DebugLineFile edk::multi::Mutex::debugFile;
#if defined( WIN32) || defined( WIN64)
HANDLE edk::multi::Mutex::mutDebug;
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
pthread_mutex_t edk::multi::Mutex::mutDebug;
#endif
#endif

edk::multi::Mutex::Mutex(){
#if defined( WIN32) || defined( WIN64)
    this->mut = CreateMutex( NULL, FALSE, NULL);edkEnd();
    if(this->mut == NULL){
        //
    }
#endif
#if defined(__linux__) || defined(__APPLE__)//MAC OS
    if(pthread_mutex_init(&this->mut, NULL) != 0){
        //
    }
#endif
}
edk::multi::Mutex::~Mutex(){
#if defined( WIN32) || defined( WIN64)
    if(this->mut){
        CloseHandle(this->mut);edkEnd();
    }
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
    pthread_mutex_destroy(&this->mut);edkEnd();
#endif
}

//set the debugFile Name
bool edk::multi::Mutex::createDebugFile(const edk::char8* name){
    return edk::multi::Mutex::createDebugFile((edk::char8*) name);
}
bool edk::multi::Mutex::createDebugFile(edk::char8* name){
    if(name){
#if defined(EDK_MUTEX_PRINT_DEBUG)
        bool ret=false;
#if defined( WIN32) || defined( WIN64)
        WaitForSingleObject(edk::multi::Mutex::mutDebug,INFINITE);edkEnd();
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
        pthread_mutex_lock(&edk::multi::Mutex::mutDebug);edkEnd();
#endif
        edk::multi::Mutex::debugFile.closeFile();
        ret = edk::multi::Mutex::debugFile.createFile(name);
#if defined( WIN32) || defined( WIN64)
        ReleaseMutex(edk::multi::Mutex::mutDebug);edkEnd();
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
        pthread_mutex_unlock(&edk::multi::Mutex::mutDebug);edkEnd();
#endif
        return ret;
#else
        return true;
#endif
    }
    return false;
}
//close the debug file to not write the file
void edk::multi::Mutex::closeDebugFile(){
#if defined(EDK_MUTEX_PRINT_DEBUG)
#if defined( WIN32) || defined( WIN64)
    WaitForSingleObject(edk::multi::Mutex::mutDebug,INFINITE);edkEnd();
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
    pthread_mutex_lock(&edk::multi::Mutex::mutDebug);edkEnd();
#endif
    edk::multi::Mutex::debugFile.closeFile();
#if defined( WIN32) || defined( WIN64)
    ReleaseMutex(edk::multi::Mutex::mutDebug);edkEnd();
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
    pthread_mutex_unlock(&edk::multi::Mutex::mutDebug);edkEnd();
#endif
#endif
}

//lock this mutex to another don't run the code
void edk::multi::Mutex::lock(){
#if defined( WIN32) || defined( WIN64)
    WaitForSingleObject(this->mut,INFINITE);edkEnd();
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
    pthread_mutex_lock(&this->mut);edkEnd();
#endif
}
#if defined(EDK_MUTEX_PRINT_DEBUG)
void edk::multi::Mutex::lock(edk::char8* text,edk::int32 line,edk::char8* file,edk::char8* function){
    edk::multi::Mutex::writeDebug((edk::char8*)text?(edk::char8*)text:(edk::char8*)"NULL",
                                  (edk::char8*)__func__,
                                  line,
                                  (edk::char8*)(edk::char8*)file?(edk::char8*)(edk::char8*)file:(edk::char8*)(edk::char8*)"FILE NULL",
                                  (edk::char8*)function?(edk::char8*)function:(edk::char8*)"FUNCTION NULL"
                                                        );
#else
void edk::multi::Mutex::lock(edk::char8*,edk::int32,edk::char8*,edk::char8*){
#endif
    this->lock();
#if defined(EDK_MUTEX_PRINT_DEBUG)
    edk::char8* newText = edk::String::strCat(text?text:"NULL","    OK");
    if(newText){
        edk::multi::Mutex::writeDebug((edk::char8*)newText,
                                      (edk::char8*)__func__,
                                      line,
                                      (edk::char8*)file?(edk::char8*)file:(edk::char8*)"FILE NULL",
                                      (edk::char8*)function?(edk::char8*)function:(edk::char8*)"FUNCTION NULL"
                                                            );
        free(newText);
    }
    else{
        edk::multi::Mutex::writeDebug((edk::char8*)text?(edk::char8*)text:(edk::char8*)"NULL",
                                      (edk::char8*)__func__,
                                      line,
                                      (edk::char8*)file?(edk::char8*)file:(edk::char8*)"FILE NULL",
                                      (edk::char8*)function?(edk::char8*)function:(edk::char8*)"FUNCTION NULL"
                                                            );
    }
#endif
}
void edk::multi::Mutex::lock(const edk::char8* text,edk::int32 line,const edk::char8* file,const edk::char8* function){
    edk::multi::Mutex::lock((edk::char8*) text,line,(edk::char8*) file,(edk::char8*) function);
}
//unlock this mutex
void edk::multi::Mutex::unlock(){
#if defined( WIN32) || defined( WIN64)
    ReleaseMutex(this->mut);edkEnd();
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
    pthread_mutex_unlock(&this->mut);edkEnd();
#endif
}
#if defined(EDK_MUTEX_PRINT_DEBUG)
void edk::multi::Mutex::unlock(edk::char8* text,edk::int32 line,edk::char8* file,edk::char8* function){
    edk::multi::Mutex::writeDebug((edk::char8*)text?(edk::char8*)text:(edk::char8*)"NULL",
                                  (edk::char8*)__func__,
                                  line,
                                  (edk::char8*)file?(edk::char8*)file:(edk::char8*)"FILE NULL",
                                  (edk::char8*)function?(edk::char8*)function:(edk::char8*)"FUNCTION NULL"
                                                        );
#else
void edk::multi::Mutex::unlock(edk::char8*,edk::int32,edk::char8*,edk::char8*){
#endif
    this->unlock();
#if defined(EDK_MUTEX_PRINT_DEBUG)
    edk::char8* newText = edk::String::strCat(text?text:"NULL","    OK");
    if(newText){
        edk::multi::Mutex::writeDebug((edk::char8*)newText,
                                      (edk::char8*)__func__,
                                      line,
                                      (edk::char8*)file?(edk::char8*)file:(edk::char8*)"FILE NULL",
                                      (edk::char8*)function?(edk::char8*)function:(edk::char8*)"FUNCTION NULL"
                                                            );
        free(newText);
    }
    else{
        edk::multi::Mutex::writeDebug((edk::char8*)text?(edk::char8*)text:(edk::char8*)"NULL",
                                      (edk::char8*)__func__,
                                      line,
                                      (edk::char8*)file?(edk::char8*)file:(edk::char8*)"FILE NULL",
                                      (edk::char8*)function?(edk::char8*)function:(edk::char8*)"FUNCTION NULL"
                                                            );
    }
#endif
}
void edk::multi::Mutex::unlock(const edk::char8* text,edk::int32 line,const edk::char8* file,const edk::char8* function){
    edk::multi::Mutex::unlock((edk::char8*) text,line,(edk::char8*) file,(edk::char8*) function);
}
//try lock the mutex (if true it's locked)
bool edk::multi::Mutex::tryLock(){
#if defined( WIN32) || defined( WIN64)
    if(!WaitForSingleObject(this->mut,0u)){
        return true;
    }
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
    if(!pthread_mutex_trylock(&this->mut)){
        return true;
    }
#endif
    return false;
}
#if defined(EDK_MUTEX_PRINT_DEBUG)
bool edk::multi::Mutex::tryLock(edk::char8* text,edk::int32 line,edk::char8* file,edk::char8* function){
    edk::multi::Mutex::writeDebug((edk::char8*)text?(edk::char8*)text:(edk::char8*)"NULL",
                                  (edk::char8*)__func__,
                                  line,
                                  (edk::char8*)file?(edk::char8*)file:(edk::char8*)"FILE NULL",
                                  (edk::char8*)function?(edk::char8*)function:(edk::char8*)"FUNCTION NULL"
                                                        );
#else
bool edk::multi::Mutex::tryLock(edk::char8*,edk::int32,edk::char8*,edk::char8*){
#endif
    bool ret = this->tryLock();
#if defined(EDK_MUTEX_PRINT_DEBUG)
    edk::char8* newText = edk::String::strCatMulti(text?text:"NULL",ret?"    OK":"    NOTOK",NULL);
    if(newText){
        edk::multi::Mutex::writeDebug((edk::char8*)newText,
                                      (edk::char8*)__func__,
                                      line,
                                      (edk::char8*)file?(edk::char8*)file:(edk::char8*)"FILE NULL",
                                      (edk::char8*)function?(edk::char8*)function:(edk::char8*)"FUNCTION NULL"
                                                            );
        free(newText);
    }
    else{
        edk::multi::Mutex::writeDebug((edk::char8*)text?(edk::char8*)text:(edk::char8*)"NULL",
                                      (edk::char8*)__func__,
                                      line,
                                      (edk::char8*)file?(edk::char8*)file:(edk::char8*)"FILE NULL",
                                      (edk::char8*)function?(edk::char8*)function:(edk::char8*)"FUNCTION NULL"
                                                            );
    }
#endif
    return ret;
}
bool edk::multi::Mutex::tryLock(const edk::char8* text,edk::int32 line,const edk::char8* file,const edk::char8* function){
    return edk::multi::Mutex::tryLock((edk::char8*) text,line,(edk::char8*) file,(edk::char8*) function);
}
