#include "StaticObject2D.h"

/*
Library StaticObject2D - Static Objects in physics2D
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

edk::physics2D::StaticObject2D::StaticObject2D(){
    this->classThis=NULL;
    this->Constructor();
}
edk::physics2D::StaticObject2D::~StaticObject2D(){
    this->Destructor();
}

void edk::physics2D::StaticObject2D::Constructor(){
    edk::physics2D::PhysicObject2D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        this->type=edk::TypeObject2DStatic;
    }
}
void edk::physics2D::StaticObject2D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
    edk::physics2D::PhysicObject2D::Destructor();
}
