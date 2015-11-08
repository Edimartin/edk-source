#ifndef PARTICLESLINE2D_H
#define PARTICLESLINE2D_H

/*
Biblioteca C++ ParticlesLine2D - Manage a particle system generated in a line
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
#warning "Inside ParticlesLine2D"
#endif

#pragma once
#include "ParticlesPoint2D.h"

#ifdef printMessages
#warning "    Compiling ParticlesLine2D"
#endif

namespace edk{
namespace animation{
class ParticlesLine2D : public edk::animation::ParticlesPoint2D{
public:
    ParticlesLine2D();

    //set the points
    void setP1(edk::vec2f32 point);
    void setP1(edk::float32 px,edk::float32 py);
    void setP2(edk::vec2f32 point);
    void setP2(edk::float32 px,edk::float32 py);
    void setPoints(edk::vec2f32 p1,edk::vec2f32 p2);
    void setPoints(edk::float32 p1x,edk::float32 p1y,edk::float32 p2x,edk::float32 p2y);

    //draw the angles vector
    virtual void drawAngles(edk::float32 size,edk::color3f32 color);
protected:
    //get the position
    virtual edk::vec2f32 newPosition();
private:
    edk::vec2f32 point1,point2;
};
}//end namespace animation
}//end namespace edk

#endif // PARTICLESLINE2D_H
