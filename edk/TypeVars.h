#ifndef EDK_TYPEVARS_H
#define EDK_TYPEVARS_H

#pragma once
#include <stdio.h>

/*
Library C++ TypeVars - Data types used in EDK engine.
Copyright (C) 2012 Eduardo Moura Sales Martins
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
#warning "Inside TypesVars"
#endif

#ifdef printMessages
#warning "    Compiling TypesVars"
#endif

/*TYPES USED BY EDK ENGINE*/
namespace edk{
	//
    typedef void* classID;

	typedef unsigned int    typeID;

    typedef unsigned char socketType;

	typedef signed   char          int8;
	typedef unsigned char          uint8;
	typedef signed   short int     int16;
	typedef unsigned short int     uint16;

	typedef float                  float32;
	typedef double                 float64;

	typedef int                    int32;
	typedef unsigned int           uint32;
	#if defined(__arch64__) || defined(_LP64)
	typedef signed long int        int64;
	typedef unsigned long int      uint64;
	#else
    typedef signed long long int   int64;
	typedef unsigned long long int uint64;
	#endif

    typedef /*signed*/   char          char8;
    typedef unsigned char          uchar8;
    typedef /*signed*/   short int     char16;
	typedef unsigned short int     uchar16;

	typedef int                    char32;
	typedef unsigned int           uchar32;
	#if defined(__arch64__) || defined(_LP64)
	typedef signed long int        char64;
	typedef unsigned long int      uchar64;
	#else
	typedef signed long int        char64;
	typedef unsigned long long int uchar64;
	#endif

}//end namespace

#endif // TYPEVARS_H
