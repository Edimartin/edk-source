#ifndef EDK_SHD_DATA_H
#define EDK_SHD_DATA_H

/*
Library DATA - Control datas in the edk shaders
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
#warning "Inside Data"
#endif

#pragma once
//use the types
#include "../TypeVars.h"
#include "../TypeVec2.h"
#include "../TypeVec3.h"
#include "../TypeVec4.h"
//put the data in a stack
#include "../vector/Stack.h"
//use the string just to copy the name
#include "../String.h"

//The data use GU_GLSL
#include "../GU/GU_GLSL.h"

#include "../vector/BinaryTree.h"

#ifdef printMessages
#warning "    Compiling Data"
#endif

namespace edk{
namespace shd{
class Data: public edk::vector::Name{
    public:
        Data();
        virtual ~Data();
        //data stack
        edk::vector::Stack<edk::int32> ints;
        edk::vector::Stack<edk::float32> floats;
        //ID of the data
        edk::int32 ID;

        //setaData GLint
        void setData1i(edk::int32 d0);
        void setData2i(edk::int32 d0,edk::int32 d1);
        void setData2i(edk::vec2i32 datas);
        void setData3i(edk::int32 d0,edk::int32 d1,edk::int32 d2);
        void setData3i(edk::vec3i32 datas);
        void setData4i(edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3);
        void setData4i(edk::vec4i32 datas);

        //setaData GLfloat
        void setData1f(edk::float32 d0);
        void setData2f(edk::float32 d0,edk::float32 d1);
        void setData2f(edk::vec2f32 datas);
        void setData3f(edk::float32 d0,edk::float32 d1,edk::float32 d2);
        void setData3f(edk::vec3f32 datas);
        void setData4f(edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3);
        void setData4f(edk::vec4f32 datas);

        //Send the data to the shader
        bool updateData();
    protected:
    private:
        //set using data int or float
        //true == int; false == float;
        bool useData;

        //clean the ints
        void cleanInts();
        //clean the floats
        void cleanFloats();
};
}//end namespace shd
}//end namespace edk

#endif // DATA_H
