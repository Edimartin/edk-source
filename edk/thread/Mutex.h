#ifndef MUTEX_H
#define MUTEX_H

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

#ifdef printMessages
#warning "Inside Mutex"
#endif

#pragma once
#include "./Thread.h"


namespace edk {
namespace multi{
class Mutex{
public:
    Mutex();
    ~Mutex();

    //lock this mutex to another don't run the code
    void lock();
    //unlock this mutex
    void unlock();
    //try lock the mutex (if true it's locked)
    bool tryLock();
private:

#if defined( WIN32) || defined( WIN64)
    //
    HANDLE mut;
#endif
#if defined(__linux__)/*LINUX*/ || defined(__APPLE__)//MAC OS
    pthread_mutex_t mut;
#endif
};
}//end namespace multi
}//end namespace edk

#endif // MUTEX_H
