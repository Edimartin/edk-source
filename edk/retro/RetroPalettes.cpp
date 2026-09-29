#include "RetroPalettes.h"
/*
Library C++ RetroPalettes - Save retro palettes in EDK
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
#pragma message "            Inside RetroPalettes.cpp"
#endif

edk::retro::RetroPalettes::RetroPalettes(){
    this->classThis=NULL;
    this->Constructor();
}
edk::retro::RetroPalettes::~RetroPalettes(){
    this->Destructor();
}

void edk::retro::RetroPalettes::Constructor(){
    edk::vector::BinaryTree<edk::retro::RetroPalette*>::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::retro::RetroPalettes::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        this->clean();
    }
    edk::vector::BinaryTree<edk::retro::RetroPalette*>::Destructor();
}
//compare if the value is bigger
bool edk::retro::RetroPalettes::firstBiggerSecond(edk::retro::RetroPalette* first,edk::retro::RetroPalette* second){
    //
    if(first>second){
        //
        return true;
    }
    return false;
}
//compare if the value is equal
bool edk::retro::RetroPalettes::firstEqualSecond(edk::retro::RetroPalette* first,edk::retro::RetroPalette* second){
    //
    if(first==second){
        //
        return true;
    }
    return false;
}

//delete all palettes
void edk::retro::RetroPalettes::clean(){
    edk::uint32 size = this->size();
    edk::retro::RetroPalette* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->getElementInPosition(i);
        if(temp){
            delete temp;
        }
    }
    edk::vector::BinaryTree<edk::retro::RetroPalette*>::clean();
}

//new palette
edk::retro::RetroPalette* edk::retro::RetroPalettes::newPalette(edk::uint32 size,edk::uint8 channels,edk::uint8 bytesPerChannel){
    if(size && channels && bytesPerChannel){
        edk::retro::RetroPalette* temp = new edk::retro::RetroPalette();
        if(temp){
            //create the new palette
            if(temp->newPalette(size,channels,bytesPerChannel)){
                if(this->add(temp)){
                    return temp;
                }
            }
            delete temp;
        }
    }
    return NULL;
}
edk::retro::RetroPalette* edk::retro::RetroPalettes::newPaletteFromVector(edk::uint8* palette,
                                                                          edk::uint32 size,
                                                                          edk::uint8 channels,
                                                                          edk::uint8 bytesPerChannel
                                                                          ){
    if(palette && size && channels && bytesPerChannel){
        edk::retro::RetroPalette* temp = new edk::retro::RetroPalette();
        if(temp){
            //create the new palette
            if(temp->copyPalette(palette,size,channels,bytesPerChannel)){
                if(this->add(temp)){
                    return temp;
                }
            }
            delete temp;
        }
    }
    return NULL;
}
bool edk::retro::RetroPalettes::deletePalette(edk::retro::RetroPalette* palette){
    if(this->haveElement(palette)){
        //remove
        if(this->remove(palette)){
            delete palette;
            return true;
        }
    }
    return false;
}
bool edk::retro::RetroPalettes::deletePaletteInPosition(edk::uint32 position){
    return this->deletePalette(this->getElementInPosition(position));
}
