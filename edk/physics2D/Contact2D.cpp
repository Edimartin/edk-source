#include "Contact2D.h"

/*
Library Contact2D - Physics Contacts used in the World2D
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

edk::physics2D::Contact2D::Contact2D(edk::classID pointer){
    //
    this->contactPointer=pointer;
    this->objectA=NULL;
    this->objectB=NULL;
    this->shapeA=0u;
    this->shapeB=0u;
    this->velocityA=0.f;
    this->velocityB=0.f;
    this->points = 0u;
    this->enabled = true;
    this->areadyContacted=false;
}
edk::uint8 edk::physics2D::Contact2D::getMaxPoints(){
    return EDK_MAX_CONTACTS_POINTS;
}

//return the contactPointer
edk::classID edk::physics2D::Contact2D::getContactPointer(){
    return this->contactPointer;
}

//disable the contact
void edk::physics2D::Contact2D::disableContact(){
    this->enabled=false;
}
void edk::physics2D::Contact2D::enableContact(){
    this->enabled=true;
}
void edk::physics2D::Contact2D::setEnabled(bool enabled){
    this->enabled=enabled;
}
bool edk::physics2D::Contact2D::isEnabled(){
    return this->enabled;
}
//return true if aready have a contact with the same objects
bool edk::physics2D::Contact2D::haveAreadyContact(){
    return this->areadyContacted;
}
