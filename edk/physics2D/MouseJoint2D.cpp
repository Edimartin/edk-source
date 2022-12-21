#include "MouseJoint2D.h"

/*
Library MouseJoint2D - Physics mouse joints used with PhysicsObjects
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

edk::physics2D::MouseJoint2D::MouseJoint2D(bool collide)
    :
      edk::physics2D::Joint2D(collide)
{
    this->type = EDK_REVOLUTE_JOINT;edkEnd();
}

//draw the joint in debug mode
void edk::physics2D::MouseJoint2D::draw(edk::size2f32 size,edk::color3f32 color){
    //
    size*=0.5;edkEnd();
    edk::GU::guColor3f32(color);edkEnd();
    edk::GU::guPushMatrix();edkEnd();
    edk::GU::guBegin(GU_LINES);edkEnd();
    //draw the first line
    edk::GU::guVertex2f32(this->worldPositionA.x - size.width,this->worldPositionA.y + size.height);edkEnd();
    edk::GU::guVertex2f32(this->worldPositionA.x + size.width,this->worldPositionA.y - size.height);edkEnd();
    //draw the second line
    edk::GU::guVertex2f32(this->worldPositionA.x + size.width,this->worldPositionA.y + size.height);edkEnd();
    edk::GU::guVertex2f32(this->worldPositionA.x - size.width,this->worldPositionA.y - size.height);edkEnd();
    edk::GU::guEnd();edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
