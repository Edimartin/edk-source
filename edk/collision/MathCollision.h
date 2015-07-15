#ifndef EDK_COLLISIONS_MATHCOLLISION_H
#define EDK_COLLISIONS_MATHCOLLISION_H

/*
Library MathCollision - Math functions to test collisions
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
#warning "Inside MathCollision"
#endif

#pragma once
#include "../TypeVec2.h"
#include "../Math.h"
#include "Vecs2f32.h"
#include "../shape/Polygon2D.h"

#ifdef printMessages
#warning "    Compiling MathCollision"
#endif

namespace edk{
namespace collision{
class MathCollision: public edk::Math{
    public:
        MathCollision();
        virtual ~MathCollision();

        //BOUNDING BOX
        static bool boundingContact3D(edk::vec3f32 point,edk::vec3f32 vec1,edk::vec3f32 vec2);
        static bool boundingContact2D(edk::vec2f32 point,edk::vec2f32 vec1,edk::vec2f32 vec2);

        //POINT STRAIGHT
        static bool pointStraigh2D(edk::vec2f32 point,vec2f32 lineStart,vec2f32 lineEnd);
        static edk::collision::Vecs2f32 straightStraight2D(vec2f32 line1Start,vec2f32 line1End,
                                                           vec2f32 line2Start,vec2f32 line2End
                                                           );
        static edk::collision::Vecs2f32 straightCircle2D(edk::vec2f32 lineStart,edk::vec2f32 lineEnd,edk::vec2f32 circlePosition,edk::float32 circleRadius);
        //static edk::collision::Vecs3f32 straightSphere3D(edk::vec3f32 lineStart,edk::vec3f32 lineEnd,edk::vec3f32 circlePosition,edk::float32 circleRadius);


        //POLYGON POINT
        static bool polygonPoint(edk::shape::Polygon2D polygon, edk::vec2f32 point);
    protected:
    private:
};
}//end namespace collision
}//end namespace edk

#endif // MATHCOLLISION2D_H
