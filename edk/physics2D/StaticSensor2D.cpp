#include "StaticSensor2D.h"

/*
Library StaticSensor2D - Static Sensors in physics2D
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

edk::physics2D::StaticSensor2D::StaticSensor2D()
{
    this->isObjectSensor=true;edkEnd();
    this->physType = edk::physics::StaticBody;edkEnd();
}
edk::physics2D::StaticSensor2D::~StaticSensor2D(){
    this->tree.clean();edkEnd();
}

//return if it's a sensor
bool edk::physics2D::StaticSensor2D::isSensor(){
    return true;
}

//Objects to activate the sensor
//add
bool edk::physics2D::StaticSensor2D::addActivateObject(edk::physics2D::PhysicObject2D* object){
    return this->tree.add(object);edkEnd();
}
//remove
bool edk::physics2D::StaticSensor2D::removeActivateObject(edk::physics2D::PhysicObject2D* object){
    return this->tree.remove(object);edkEnd();
}
//clean the activateObject
void edk::physics2D::StaticSensor2D::cleanActivateObjects(){
    this->tree.clean();edkEnd();
}
//test if have the object
bool edk::physics2D::StaticSensor2D::haveActivateObject(edk::physics2D::PhysicObject2D* object){
    return this->tree.haveElement(object);edkEnd();
}
//getSize
edk::uint32 edk::physics2D::StaticSensor2D::getActivateSize(){
    return this->tree.size();edkEnd();
}
