#include "ViewText.h"

/*
Library C++ Text - Render Text using ViewGu2D in EDK Game Engine
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#ifdef printMessages
#warning "            Inside ViewText.cpp"
#endif

edk::ViewText::ViewText()
{
    this->textLine=0u;
    this->saveLine=0u;
    this->cleanString();
}
edk::ViewText::~ViewText()
{
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
        this->camera.setRect(0.f,
                             0.f - (this->textLine - 1u),
                             this->rectSave.size.width / (this->rectSave.size.height / this->textLine),
                             1 + (this->textLine - 1u)
                             );
        }
        else if(this->frame.size.height){
            //update the camera size
            this->camera.setRect(0,
                                 0,
                                 this->frame.size.width/this->frame.size.height,
                                 1
                                 );
        }
        else{
            //update the camera size
            this->camera.setRect(0,
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
bool edk::ViewText::createString(const char* string){
    return this->createString((edk::char8*) string);
}

//clean the string
void edk::ViewText::cleanString(){
    this->text.createStringMap(" ");
}
