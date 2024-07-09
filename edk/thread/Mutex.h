#ifndef MUTEX_H
#define MUTEX_H

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

#ifdef printMessages
#pragma message "Inside Mutex"
#endif

#pragma once
#include "./Thread.h"
#if defined(EDK_MUTEX_PRINT_DEBUG)
#include "../DebugLineFile.h"
#endif


namespace edk {
namespace multi{
class MutexDisable{
public:
    MutexDisable(){this->classThis=NULL;this->Constructor(false);edkEnd();}
    virtual ~MutexDisable(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){edkEnd();}
        if(this->classThis!=this){
            this->classThis=this;
        }
    }

    //lock this mutex to another don't run the code
    inline void lock(){}
    //unlock this mutex
    inline void unlock(){}
    //try lock the mutex (if true it's locked)
    inline bool tryLock(){return false;}
private:
    edk::classID classThis;
};
class Mutex : public edk::multi::MutexDisable{
public:
    Mutex();
    virtual ~Mutex();

    void Constructor(bool runFather=true);

    //set the debugFile Name
    static bool createDebugFile(const edk::char8* name);
    static bool createDebugFile(edk::char8* name);
    //close the debug file to not write the file
    static void closeDebugFile();

    //lock this mutex to another don't run the code
    virtual void lock();
    virtual void lock(edk::char8* text,edk::int32 line,edk::char8* file,edk::char8* function);
    virtual void lock(const edk::char8* text,edk::int32 line,const edk::char8* file,const edk::char8* function);
    //unlock this mutex
    virtual void unlock();
    virtual void unlock(edk::char8* text,edk::int32 line,edk::char8* file,edk::char8* function);
    virtual void unlock(const edk::char8* text,edk::int32 line,const edk::char8* file,const edk::char8* function);
    //try lock the mutex (if true it's locked)
    virtual bool tryLock();
    virtual bool tryLock(edk::char8* text,edk::int32 line,edk::char8* file,edk::char8* function);
    virtual bool tryLock(const edk::char8* text,edk::int32 line,const edk::char8* file,const edk::char8* function);
private:
#if defined( WIN32) || defined( WIN64)
    //
    HANDLE mut;
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
    pthread_mutex_t mut;
#endif

#if defined(EDK_MUTEX_PRINT_DEBUG)
    static edk::DebugLineFile debugFile;
#if defined( WIN32) || defined( WIN64)
    //
    static HANDLE mutDebug;
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
    static pthread_mutex_t mutDebug;
#endif

    //write some command in the debugFile
    inline void writeDebug(edk::char8* text,edk::char8* mutFunction,edk::int32 line,edk::char8* file,edk::char8* function){
        if(text && line && function && mutFunction){
            //create the debugString
            edk::char8* newLine = edk::String::int32ToStr(line);
            if(newLine){
                //create strings for this class and thread ID
                edk::char8* thisStr = edk::String::uint64ToStr((edk::uint64)this);
                if(thisStr){
                    edk::char8* id = edk::String::uint64ToStr((edk::uint64)edk::multi::Thread::getThisThreadID());
                    if(id){
                        //create the string
                        edk::char8* str = edk::String::strCatMulti("\n",newLine," ",file," thread(",id,") this[",thisStr,"] ",function," ",mutFunction," ",text,NULL);
                        if(str){
                            //write this string into the file
#if defined( WIN32) || defined( WIN64)
                            WaitForSingleObject(edk::multi::Mutex::mutDebug,INFINITE);edkEnd();
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
                            pthread_mutex_lock(&edk::multi::Mutex::mutDebug);edkEnd();
#endif
                            edk::multi::Mutex::debugFile.writeDebug(str);
#if defined( WIN32) || defined( WIN64)
                            ReleaseMutex(edk::multi::Mutex::mutDebug);edkEnd();
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
                            pthread_mutex_unlock(&edk::multi::Mutex::mutDebug);edkEnd();
#endif
                            free(str);
                        }
                        free(id);
                    }
                    free(thisStr);
                }
                free(newLine);
            }
        }
    }
    inline void writeDebug(const edk::char8* text,edk::char8* mutFunction,edk::int32 line,const edk::char8* file,const edk::char8* function){
        this->writeDebug((edk::char8*) text,(edk::char8*) mutFunction,line,(edk::char8*) file,(edk::char8*) function);
    }
    inline void writeDebug(edk::char8* text,edk::char8* mutFunction){
        if(text){
            //write this string into the file

            //create the string
            edk::char8* str = edk::String::strCatMulti("\n",mutFunction," ",text,NULL);
            if(str){
#if defined( WIN32) || defined( WIN64)
                WaitForSingleObject(edk::multi::Mutex::mutDebug,INFINITE);edkEnd();
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
                pthread_mutex_lock(&edk::multi::Mutex::mutDebug);edkEnd();
#endif
                edk::multi::Mutex::debugFile.writeDebug("\n");
                edk::multi::Mutex::debugFile.writeDebug(mutFunction);
                edk::multi::Mutex::debugFile.writeDebug(" ");
                edk::multi::Mutex::debugFile.writeDebug(text);
#if defined( WIN32) || defined( WIN64)
                ReleaseMutex(edk::multi::Mutex::mutDebug);edkEnd();
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
                pthread_mutex_unlock(&edk::multi::Mutex::mutDebug);edkEnd();
#endif
            }
        }
    }
    inline void writeDebug(const edk::char8* text,edk::char8* mutFunction){
        this->writeDebug((edk::char8*) text,(edk::char8*) mutFunction);
    }
    static bool templateConstructNeed;
#endif
private:
    edk::classID classThis;
};
}//end namespace multi
}//end namespace edk

#endif // MUTEX_H
