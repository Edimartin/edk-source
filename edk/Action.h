#ifndef ACTION_H
#define ACTION_H

/*
Library C++ Action - Set Actions and CounterActions to the Game Engine
Copyright (C) 2013 Eduardo Moura Sales Martins
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
#warning "Inside Action"
#endif

#ifdef printMessages
#warning "    Compiling Action"
#endif

#pragma once
#include "TypeVars.h"
#include "vector/BinaryTree.h"

namespace edk{
//This is an Action. You can use this class to save actions to animation or ctrl+z.
class Action{
public:
    Action(){}
    virtual ~Action(){}

    //run action function
    virtual void runAction()=0;
    //run a counter action used for ctrl+z
    virtual void runCounterAction()=0;

    //return the code
    virtual edk::uint64 getCode()=0;
};
class ActionZero: public edk::Action{
public:
    ActionZero(){}
    virtual ~ActionZero(){}

    //run action function
    virtual void runAction(){}
    //run a counter action used for ctrl+z
    virtual void runCounterAction(){}

    //return the code
    virtual edk::uint64 getCode(){
        return 0u;
    }
};
//Action with names
}//end namespace edk

#endif // ACTION_H
