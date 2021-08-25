#include "Text2D.h"

/*
Text2D - Simple Text for the GUI 2D library
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
edk::gui2d::Text2D::Text2D(){
    edk::gui2d::ObjectGui2d::setBorderSize(0.01f);
}
edk::gui2d::Text2D::~Text2D(){
    //
}

//get the type
edk::gui2d::gui2dTypes edk::gui2d::Text2D::getType(){
    return edk::gui2d::gui2dTypeText;
}

//load the button textures and meshes
bool edk::gui2d::Text2D::load(){
    if(edk::gui2d::ObjectGui2d::load()){
        //set the border size
        return true;
    }
    return false;
}
void edk::gui2d::Text2D::unload(){
    edk::gui2d::ObjectGui2d::unload();
}
void edk::gui2d::Text2D::update(){
    edk::gui2d::ObjectGui2d::update();
}

//set border size
bool edk::gui2d::Text2D::setBorderSize(edk::float32){
    return false;
}

//draw the button
void edk::gui2d::Text2D::draw(){
    this->drawStart();
    if(this->text.haveText() && this->drawText){
        //
        this->text.draw(edk::color4f32(0,0,0,1));
    }
    this->drawEnd();
}
