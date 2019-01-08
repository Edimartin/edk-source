#ifndef PHYSICSMESH2D_H
#define PHYSICSMESH2D_H

/*
Library PhysicMesh - Mesh for box2D in EDK
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
#warning "Inside PhysicsMesh2D"
#endif

#pragma once
#include "../shape/Polygon2DList.h"

#ifdef printMessages
#warning "    Compiling PhysicsMesh2D"
#endif

namespace edk{
namespace physics2D{
class PhysicsMesh2D : public edk::shape::Polygon2DList{
public:
    PhysicsMesh2D();
    //ADD
    //add a polygon to the phisics mesh
    edk::uint32 addPolygon(edk::shape::Polygon2D polygon);

private:
    //tree to sabe the vertex in convex order
    class ConvexTree:public edk::vector::BinaryTree<edk::vec3f32*>{
    public:
        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::vec3f32* first,edk::vec3f32* second){
            if(first->z>second->z){
                return true;
            }
            /*
            else if(first->z == 90.f){
                if(first->z==second->z
                        &&
                        first->x<second->x){
                    return true;
                }
                else if(first->z==second->z
                        &&
                        first->x==second->x
                        &&
                        first->y<second->y){
                    return true;
                }
            }
            else{
                if(first->z==second->z
                        &&
                        first->x>second->x){
                    return true;
                }
                else if(first->z==second->z
                        &&
                        first->x==second->x
                        &&
                        first->y>second->y){
                    return true;
                }
            }
            */
            return false;
        }
        virtual bool firstEqualSecond(edk::vec3f32* first,edk::vec3f32* second){
            //
            if(first->x==second->x
                    &&
                    first->y==second->y
                    &&
                    first->z==second->z){
                return true;
            }
            return false;
        }
    };
};
}
}

#endif // PHYSICSMESH_H
