#ifndef PHYSICSMESH2D_H
#define PHYSICSMESH2D_H

/*
Library PhysicMesh - Mesh for box2D in EDK
Copyright 2013 Eduardo Moura Sales Martins (edimartin@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
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
