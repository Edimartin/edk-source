#include "RetroViewTileEdit.h"

/*
Library C++ RetroViewTileEdit - View used to Edit RetroTiles in EDK
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
#pragma message "            Inside RetroViewTileEdit.cpp"
#endif

edk::retro::RetroViewTileEdit::RetroViewTileEdit(){
    this->classThis=NULL;
    this->Constructor();
}
edk::retro::RetroViewTileEdit::~RetroViewTileEdit(){
    this->Destructor();
}

void edk::retro::RetroViewTileEdit::Constructor(){
    edk::ViewGU2D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::retro::RetroViewTileEdit::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
    }
    edk::ViewGU2D::Destructor();
}

void edk::retro::RetroViewTileEdit::resize(edk::rectf32 outsideViewOrigin){}
void edk::retro::RetroViewTileEdit::load(edk::rectf32 outsideViewOrigin){}
void edk::retro::RetroViewTileEdit::unload(){}
void edk::retro::RetroViewTileEdit::update(edk::WindowEvents* events){}
void edk::retro::RetroViewTileEdit::pause(){}
void edk::retro::RetroViewTileEdit::unpause(){}
void edk::retro::RetroViewTileEdit::drawScene(edk::rectf32 outsideViewOrigin){}
