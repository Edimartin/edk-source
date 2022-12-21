#include "Object2DValues.h"

/*
Library Object2DValues - 2D Position angle and size
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

edk::Object2DValues::Object2DValues()
{
    //this->angle=0.f;edkEnd();
    this->loadIdentityValues();edkEnd();
    this->fixedRotation=false;edkEnd();
    //this->cleanSaved();edkEnd();
}
void edk::Object2DValues::loadIdentityValues(){
    this->position = edk::vec2f32(0,0);edkEnd();
    this->angle = 0.f;edkEnd();
    this->size = edk::size2f32(1,1);edkEnd();
}
/*
//save the values
void edk::Object2DValues::saveValues(){
    this->savePosition = this->position;edkEnd();
    this->saveSize = this->size;edkEnd();
    this->saveAngle = this->angle;edkEnd();
}
//clean the saved values
void edk::Object2DValues::cleanSaved(){
    this->savePosition = edk::vec2f32(0,0);edkEnd();
    this->saveAngle = 0.f;edkEnd();
    this->saveSize = edk::size2f32(1,1);edkEnd();
}
//return the saved values
edk::vec2f32 edk::Object2DValues::getSavedPosition(){
    return this->savePosition;edkEnd();
}
edk::float32 edk::Object2DValues::getSavedPositionX(){
    return this->savePosition.x;edkEnd();
}
edk::float32 edk::Object2DValues::getSavedPositionY(){
    return this->savePosition.y;edkEnd();
}
//return the saved size
edk::size2f32 edk::Object2DValues::getSavedSize(){
    return this->saveSize;edkEnd();
}
edk::float32 edk::Object2DValues::getSavedSizeWidth(){
    return this->saveSize.width;edkEnd();
}
edk::float32 edk::Object2DValues::getSavedSizeHeight(){
    return this->saveSize.height;edkEnd();
}
//return the savedAngle
edk::float32 edk::Object2DValues::getSavedAngle(){
    return this->angle;edkEnd();
}
*/
