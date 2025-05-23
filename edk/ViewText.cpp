#include "ViewText.h"

/*
Library C++ Text - Render Text using ViewGu2D in EDK Game Engine
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
#pragma message "            Inside ViewText.cpp"
#endif

edk::ViewText::ViewText(){
    this->classThis=NULL;
    this->Constructor();
}
edk::ViewText::~ViewText(){
    this->Destructor();
}

void edk::ViewText::Constructor(){
    edk::ViewGU2D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->text.Constructor();

        this->textLine=0u;
        this->saveLine=0u;
        this->text.setColor(0.f,0.f,0.f,1.f);
        this->cleanString();

        //set the text to black color
        this->text.setColor(0.f,0.f,0.f,1.f);
    }
}
void edk::ViewText::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class

        this->text.Destructor();
    }
    edk::ViewGU2D::Destructor();
}

//draw the GU scene

void edk::ViewText::drawScene(edk::rectf32){
    //test if the rect is diferent than frame
    if(this->frame!=this->rectSave
            ||
            this->saveLine!=this->textLine){
        //then rect receive frame
        this->rectSave=this->frame;

        if(this->textLine){
            //resize the camera
            this->camera.setRectPoints(0.f,
                                 0.f - (this->textLine - 1u),
                                 this->rectSave.size.width / (this->rectSave.size.height / this->textLine),
                                 1 + (this->textLine - 1u)
                                 );
        }
        else if(this->frame.size.height){
            //update the camera size
            this->camera.setRectPoints(0,
                                 0,
                                 this->frame.size.width/this->frame.size.height,
                                 1
                                 );
        }
        else{
            //update the camera size
            this->camera.setRectPoints(0,
                                 0,
                                 1,
                                 1
                                 );
        }
        this->saveLine = this->textLine;
    }
    this->text.draw();
}
void edk::ViewText::load(edk::rectf32){
    //this->text.setPosition(0,0);
}
void edk::ViewText::unload(){
    //
}
void edk::ViewText::update(edk::WindowEvents*){
    this->text.updateAnimations();
}
void edk::ViewText::update(edk::WindowEvents*,edk::float32 seconds){
    this->text.updateAnimations(seconds);
}

//createString
bool edk::ViewText::createString(edk::char8* string){
    if(this->text.createStringMap(string)){
        //set the new position
        this->textLine = this->text.getMapSizeHeight();
        this->text.setPosition(0.5f,0.5f - (this->textLine-1));
        return true;
    }
    return false;
}
bool edk::ViewText::createString(const edk::char8* string){
    return this->createString((edk::char8*) string);
}

//load the font image
bool edk::ViewText::loadFontImage(edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter,edk::color4f32 color){
    return this->text.loadFontImage(name,minFilter,magFilter,color);
}
bool edk::ViewText::loadFontImage(const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter,edk::color4f32 color){
    return this->text.loadFontImage(name,minFilter,magFilter,color);
}

//set the color
void edk::ViewText::setColor(edk::color4f32 color){
    this->text.setColor(color);
}
void edk::ViewText::setColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->text.setColor(r,g,b,a);
}
void edk::ViewText::setAlpha(edk::float32 value){
    this->text.setAlpha(value);
}
void edk::ViewText::setColor(edk::color4ui8 color){
    this->text.setColor(color);
}
void edk::ViewText::setColor(edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
    this->text.setColor(r,g,b,a);
}
void edk::ViewText::setAlpha(edk::uint8 value){
    this->text.setAlpha(value);
}

//update the width
void edk::ViewText::updateWidth(){
    if(this->text.getMapSizeHeight()){
        this->frame.size.width = (
                    (
                        (this->text.getMapSizeWidth() / this->text.getMapSizeHeight())
                        * this->frame.size.height
                        )
                    * this->text.getMapScaleWidth()
                    )
                ;
    }
}
void edk::ViewText::setScale(edk::size2f32 scale){
    this->text.setScale(scale);
}
void edk::ViewText::setScale(edk::float32 width,edk::float32 height){
    this->text.setScale(width,height);
}

//clean the string
void edk::ViewText::cleanString(){
    this->text.createStringMap(" ");
}
