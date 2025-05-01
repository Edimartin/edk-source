#include "RectangleContact.h"

/*
Library RectangleContact - Teste collision between a rectangle and other types
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
#pragma message "            Inside RectangleContact.cpp"
#endif

edk::collision::RectangleContact::RectangleContact(){
    this->classThis=NULL;
    this->Constructor();
}

edk::collision::RectangleContact::~RectangleContact(){
    this->Destructor();
}

void edk::collision::RectangleContact::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::collision::RectangleContact::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
}

//CONTACTS
bool edk::collision::RectangleContact::contactPoint(edk::vec2f32 point, edk::shape::Rectangle2D rectangle){
    //
    return edk::collision::MathCollision::boundingContact2D(point,
                                                            rectangle.getVertexPosition(0u) ,
                                                            rectangle.getVertexPosition(1u)
                                                            );
}
