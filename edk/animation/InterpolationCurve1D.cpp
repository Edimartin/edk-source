#include "InterpolationCurve1D.h"

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
#warning "            Inside InterpolationCurve1D.cpp"
#endif

edk::animation::InterpolationCurve1D::InterpolationCurve1D()
{
    //ctor
}

edk::animation::InterpolationCurve1D::~InterpolationCurve1D()
{
    //dtor
}

/*
//SETERS
//set the start frame
void edk::animation::InterpolationCurve1D::setStart(edk::animation::Frame1D frame){
    //set the start
    this->start = frame;

    //test if start is after the point1
    if(this->start>this->point1){
        //then set the point to one second after the start
        return this->setStart(edk::animation::Frame1D(this->start.second + 1u,this->point1.x));
    }
    else{
        //else update the distance
        this->updateDistance();
    }
}
//set the end frame
bool edk::animation::InterpolationCurve1D::setEnd(edk::animation::Frame1D frame){
    //test if the end are after the point2
    if(frame>this->point2){
        //then he set the end
        this->end=frame;
        //return true
        return true;
    }

    //else return false
    return false;
}
//set the point1 of the curve
bool edk::animation::InterpolationCurve1D::setX1(edk::animation::Frame1D frame){
    //test if the frame are after the start
    if(frame>this->start){
        //set the frame
        this->point1=frame;

        //test if the point1 are after the point2
        if(this->point1>this->point2){
            //then set the point2 to one second after the point1
            return this->setX2(edk::animation::Frame1D(this->point1.second+1u,this->point2.x));
        }
    }
    else{
        //update the distance
        this->updateDistance();
    }
    //else return true
    return false;
}
//set the point2 of the curve
bool edk::animation::InterpolationCurve1D::setX2(edk::animation::Frame1D frame){
    //test if the frame are after the start
    if(frame>this->point1){
        //set the frame
        this->point2=frame;

        //test if the point1 are after the point2
        if(this->point2>this->end){
            //then set the point2 to one second after the point1
            return this->setEnd(edk::animation::Frame1D(this->point2.second+1u,this->end.x));
        }
    }
    else{
        //update the distance
        this->updateDistance();
    }
    //else return true
    return false;
}

//GETERS
//return the point
edk::animation::Frame1D edk::animation::InterpolationCurve1D::getX1(){
    //return the point
    return this->point1;
}
//return the point
edk::animation::Frame1D edk::animation::InterpolationCurve1D::getX2(){
    //return the point
    return this->point2;
}
*/
