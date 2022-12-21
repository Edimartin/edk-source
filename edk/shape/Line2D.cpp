#include "Line2D.h"

/*
Library Line2D - Draw a 2D line in EDK Game Engine
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
#warning "            Inside Line2D.cpp"
#endif

edk::shape::Line2D::Line2D(){
    //
}
edk::shape::Line2D::Line2D(edk::vec2f32 start,edk::vec2f32 end){
    //
    this->start.position=start;edkEnd();
    this->end.position=end;edkEnd();
}

edk::shape::Line2D::~Line2D(){
    //
}

//print the line
void edk::shape::Line2D::print(){
    //
    printf("\nLine");edkEnd();
}
//Draw the line
void edk::shape::Line2D::draw(){
    //
    this->start.draw();edkEnd();
    this->end.draw();edkEnd();
}
