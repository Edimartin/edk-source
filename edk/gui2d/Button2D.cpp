#include "Button2D.h"

/*
Button - Button for the GUI 2D library
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
#pragma message "            Inside Button2D.cpp"
#endif

edk::gui2d::Button2D::Button2D(){
    this->classThis=NULL; 
    this->Constructor();
}
edk::gui2d::Button2D::~Button2D(){
    this->Destructor();
}

void edk::gui2d::Button2D::Constructor(){
        edk::gui2d::ObjectGui2d::Constructor(); 
    if(this->classThis!=this){
        this->classThis=this;

        this->typeGUI = edk::gui2d::gui2dTypeButton;
        this->type=edk::TypeObject2DButton;
        this->obj.setBorderSize(0.25f); 
    }
}
void edk::gui2d::Button2D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        //clean the meshes
        this->unload();
    }
    edk::gui2d::ObjectGui2d::Destructor();
}

//load the button textures and meshes
bool edk::gui2d::Button2D::load(){
    if(edk::gui2d::ObjectGui2d::load()){
        return true;
    }
    return false;
}
void edk::gui2d::Button2D::unload(){
    edk::gui2d::ObjectGui2d::unload(); 
}
void edk::gui2d::Button2D::update(){
    edk::gui2d::ObjectGui2d::update(); 
}

//set border size
bool edk::gui2d::Button2D::setBorderSize(edk::float32 size){
    return this->obj.setBorderSize(size); 
}

//draw the button
void edk::gui2d::Button2D::draw(){
    edk::gui2d::ObjectGui2d::draw(); 
}

