#ifndef EDK_ANIMATION_INTERPOLATIONCURVE1D_H
#define EDK_ANIMATION_INTERPOLATIONCURVE1D_H

/*
Library C++ InterpolationCurveGroup1D - Manage one or more interpolationCurves with one value in Edk Game Engine
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
#warning "Inside InterpolationCurve1D"
#endif

#pragma once
#include "InterpolationLine1D.h"

#ifdef printMessages
#warning "    Compiling InterpolationCurve1D"
#endif

namespace edk{
namespace animation{
class InterpolationCurve1D: private edk::animation::InterpolationLine1D{
    public:
        InterpolationCurve1D();
        virtual ~InterpolationCurve1D();
/*
        //SETERS
        //set the start frame
        void setStart(edk::animation::Frame1D frame);
        //set the end frame
        bool setEnd(edk::animation::Frame1D frame);
        //set the point1 of the curve
        bool setX1(edk::animation::Frame1D frame);
        //set the point2 of the curve
        bool setX2(edk::animation::Frame1D frame);

        //GETERS
        //return the point
        edk::animation::Frame1D getX1();
        //return the point
        edk::animation::Frame1D getX2();
    protected:
    private:
    //points of the curve
    edk::animation::Frame1D point1,point2;
    */
};
}//end namespace animation
}//end namespace edk

#endif // InterpolationCurve1D_H
