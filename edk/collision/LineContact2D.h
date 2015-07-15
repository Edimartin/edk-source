#ifndef EDK_COLLISIONS_LINE2D_H
#define EDK_COLLISIONS_LINE2D_H

/*
Library LineCollider2D - Teste collision between a line and other types
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
#warning "Inside LineContact2D"
#endif

#pragma once
#include "MathCollision.h"
#include "Vecs2f32.h"
#include "../shape/Vertex2D.h"
#include "../shape/Line2D.h"
#include "../shape/Circle2D.h"
#include "../shape/Polygon2D.h"

#ifdef printMessages
#warning "    Compiling LineContact2D"
#endif

namespace edk{
namespace collision{
class LineContact2D{
    public:
        LineContact2D();
        virtual ~LineContact2D();

        //Contacts
        //point
        static bool contactPoint(edk::vec2f32 point,edk::shape::Line2D test);
        //line
        static edk::collision::Vecs2f32 contactLine(edk::shape::Line2D line,edk::shape::Line2D test);
        //Circle
        static edk::collision::Vecs2f32 contactCircle(edk::shape::Circle2D circle,edk::shape::Line2D test);
        //polygon
        static edk::collision::Vecs2f32 contactPolygon(edk::shape::Polygon2D polygon,edk::shape::Line2D test);

    protected:
    private:
};
}//end namesoace collision
}//end namespace edk

#endif // LINECOLLIDER2D_H
