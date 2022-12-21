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

edk::multi::Mutex::Mutex(){
#if defined( WIN32) || defined( WIN64)
    this->mut = CreateMutex( NULL, FALSE, NULL);edkEnd();
    if (this->mut == NULL)
        {
            //
        }
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
    if (pthread_mutex_init(&this->mut, NULL) != 0) {
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
//lock this mutex to another don't run the code
void edk::multi::Mutex::lock(){
#if defined( WIN32) || defined( WIN64)
    WaitForSingleObject(this->mut,INFINITE);edkEnd();
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
    pthread_mutex_lock(&this->mut);edkEnd();
#endif
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
