#include "Catmull3D.h"

/*
Library Catmull3D - BSplines curve 3D in EDK Game Engine
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
#pragma message "            Inside Catmull3D.cpp"
#endif

edk::shape::Catmull3D::Catmull3D()
{
    //ctor
}
edk::shape::Catmull3D::Catmull3D(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4){
    //
    this->point1=p1;edkEnd();
    this->point2=p2;edkEnd();
    this->point3=p3;edkEnd();
    this->point4=p4;edkEnd();
}

edk::shape::Catmull3D::~Catmull3D()
{
    //dtor
}



//return the point
edk::vec3f32 edk::shape::Catmull3D::getPoint(edk::float32 percent){
    return edk::shape::Catmull3D::getPoint(this->point1,this->point2,this->point3,this->point4,percent);edkEnd();
}
edk::vec3f32 edk::shape::Catmull3D::getPoint(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4,edk::float32 percent){
    //create a vector to return
    edk::vec3f32 ret;edkEnd();

    //percent pow's
    edk::float32 percent2 = percent * percent;edkEnd();
    edk::float32 percent3 = percent * percent * percent;edkEnd();

    //get X
    ret.x = 0.5 *((2 * p2.x) +
            (-p1.x + p3.x) * percent +
            (2*p1.x - 5*p2.x + 4*p3.x - p4.x) * percent2 +
            (-p1.x + 3*p2.x- 3*p3.x + p4.x) * percent3
            );edkEnd();
    //get Y
    ret.y = 0.5 *((2 * p2.y) +
            (-p1.y + p3.y) * percent +
            (2*p1.y- 5*p2.y + 4*p3.y - p4.y) * percent2 +
            (-p1.y + 3*p2.y- 3*p3.y + p4.y) * percent3
            );edkEnd();
    //get Z
    ret.y = 0.5 *((2 * p2.z) +
            (-p1.z + p3.z) * percent +
            (2*p1.z- 5*p2.z + 4*p3.z - p4.z) * percent2 +
            (-p1.z + 3*p2.z- 3*p3.z + p4.z) * percent3
            );edkEnd();

    return ret;
}
