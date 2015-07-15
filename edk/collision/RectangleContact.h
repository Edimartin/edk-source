#ifndef EDK_COLLISIONS_RECTANGLE_H
#define EDK_COLLISIONS_RECTANGLE_H

/*
Library RectangleCollider2D - Teste collision between a rectangle and other types
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
#warning "Inside RectangleContact"
#endif

#pragma once
#include "../TypeVec2.h"
#include "MathCollision.h"
#include "../shape/Rectangle2D.h"

#ifdef printMessages
#warning "    Compiling RectangleContact"
#endif

namespace edk{
namespace collision{
class RectangleContact{
    public:
        RectangleContact();
        virtual ~RectangleContact();

        //CONTACTS
        static bool contactPoint(edk::vec2f32 point, edk::shape::Rectangle2D rectangle);
    protected:
    private:
};
}//end namespace collision
}//end namespace edk

#endif // RECTANGLE_H
