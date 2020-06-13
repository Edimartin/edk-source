#include "Mutex.h"

/*
Library C++ Mutex - Mutex fot threads.
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

edk::multi::Mutex::Mutex(){
#if defined( WIN32) || defined( WIN64)
    this->mut = CreateMutex( NULL, FALSE, NULL);
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
    if(this->mut)
        CloseHandle(this->mut);
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
    pthread_mutex_destroy(&this->mut);
#endif
}
//lock this mutex to another don't run the code
void edk::multi::Mutex::lock(){
#if defined( WIN32) || defined( WIN64)
    WaitForSingleObject(this->mut,INFINITE);
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
    pthread_mutex_lock(&this->mut);
#endif
}
//unlock this mutex
void edk::multi::Mutex::unlock(){
#if defined( WIN32) || defined( WIN64)
    ReleaseMutex(this->mut);
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
    pthread_mutex_unlock(&this->mut);
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
