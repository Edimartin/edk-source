#ifndef EDK_SHAPE_LINE2D_H
#define EDK_SHAPE_LINE2D_H

/*
Library Line2D - Draw a 2D line in EDK Game Engine
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
#warning "Inside Line2D"
#endif

//Include the polygon
#pragma once
#include "../TypeVec2.h"
#include "Vertex2D.h"

#ifdef printMessages
#warning "    Compiling Line2D"
#endif

namespace edk{
namespace shape{
class Line2D{
    public:
        Line2D();
        Line2D(edk::vec2f32 start,edk::vec2f32 end);
        virtual ~Line2D();
        //line Vectex's
        edk::shape::Vertex2D start,end;

        //print the line
        void print();
        //Draw the line
        void draw();
    protected:
    private:
};
}//end namespace shape
}//end namespace edk

#endif // LINE2D_H
