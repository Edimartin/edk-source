#include "FontSet.h"

/*
Library FontSet - Tile Set for Font Images
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

edk::fonts::FontSet::FontSet(edk::uint32 filter){
    //
    this->filter=filter;
}
edk::fonts::FontSet::~FontSet(){
    this->deleteImage();
}

//load the font
bool edk::fonts::FontSet::loadFontImage(const char* image,edk::uint32 filter,edk::color4f32 color){
    return this->loadFontImage((edk::char8*) image,filter,color);
}

bool edk::fonts::FontSet::loadFontImage(edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    this->deleteImage();
    edk::tiles::TileSet2D::Tile2Positions2D ret = this->tileSet.loadImageTiles(image,16u,16u,filter,color);
    if(ret.first==1u && ret.last==256u){
        if(this->name.setName(image)){
            this->filter = filter;
            return true;
        }
    }
    this->deleteImage();
    return false;
}

bool edk::fonts::FontSet::loadFontImageFromMemory(const char* name,
                                                  edk::uint8* image,
                                                  edk::uint32 size,
                                                  edk::uint32 filter,
                                                  edk::color4f32 color
        ){
    return this->loadFontImageFromMemory((edk::char8*) name,image,size,filter,color);
}

bool edk::fonts::FontSet::loadFontImageFromMemory(edk::char8* name,
                                                  edk::uint8* image,
                                                  edk::uint32 size,
                                                  edk::uint32 filter,
                                                  edk::color4f32 color
        ){
    this->deleteImage();
    edk::tiles::TileSet2D::Tile2Positions2D ret = this->tileSet.loadImageTilesFromMemory(name,image,size,16u,16u,filter,color);
    if(ret.first==1u && ret.last==256u){
        if(this->name.setName(name)){
            this->filter = filter;
            return true;
        }
    }
    this->deleteImage();
    return false;
}

//delete image
void edk::fonts::FontSet::deleteImage(){
    this->tileSet.deleteTiles();
    this->name.cleanName();
}

//get the tileset
edk::tiles::TileSet2D* edk::fonts::FontSet::getTileSet(){
    return &this->tileSet;
}
//return the filter
edk::uint32 edk::fonts::FontSet::getFilter(){
    return this->filter;
}

//setName
bool edk::fonts::FontSet::setName(const char* name){
    return this->setName((edk::char8*) name);
}
bool edk::fonts::FontSet::setName(edk::char8* name){
    this->deleteImage();
    return this->name.setName(name);
}
//test the names
bool edk::fonts::FontSet::nameBiggerThan(const char* name){
    return this->nameBiggerThan((edk::char8*) name);
}
bool edk::fonts::FontSet::nameBiggerThan(edk::char8* name){
    return this->name.nameBiggerThan(name);
}
bool edk::fonts::FontSet::nameEqualThan(const char* name){
    return this->nameEqualThan((edk::char8*) name);
}
bool edk::fonts::FontSet::nameEqualThan(edk::char8* name){
    return this->name.nameEqual(name);
}
//get the name
edk::char8* edk::fonts::FontSet::getName(){
    return this->name.getName();
}

edk::fonts::fontSetList::FontRetain::FontRetain(edk::uint32 filter)
    :set(filter)
{
    this->retains=0u;
}
edk::fonts::fontSetList::FontRetain::~FontRetain(){
    this->retains=0u;
}
//retain release
void edk::fonts::fontSetList::FontRetain::retain(){
    this->retains++;
}
bool edk::fonts::fontSetList::FontRetain::release(){
    if(this->retains){
        this->retains--;
        return true;
    }
    return false;
}
//test if have no retains
bool edk::fonts::fontSetList::FontRetain::haveNoRetains(){
    if(this->retains)
        return false;
    return true;
}

//getFontSet
edk::fonts::fontSetList::FontRetain* edk::fonts::fontSetList::TreeFont::getFontSetByImage(edk::char8* image,edk::uint32 filter){
    edk::fonts::fontSetList::FontRetain find(filter);
    find.set.setName(image);
    return this->getElement(&find);
}
//compare if the value is bigger
bool edk::fonts::fontSetList::TreeFont::firstBiggerSecond(edk::fonts::fontSetList::FontRetain* first,edk::fonts::fontSetList::FontRetain* second){
    if(first && second){
        if(first->set.getFilter() > second->set.getFilter()){
            return first->set.nameBiggerThan(second->set.getName());
        }
        else if(first->set.getFilter() == second->set.getFilter()){
            return first->set.nameBiggerThan(second->set.getName());
        }
    }
    return false;
}
bool edk::fonts::fontSetList::TreeFont::firstEqualSecond(edk::fonts::fontSetList::FontRetain* first,edk::fonts::fontSetList::FontRetain* second){
    if(first && second){
        if(first->set.getFilter() == second->set.getFilter()){
            return first->set.nameEqualThan(second->set.getName());
        }
    }
    return false;
}
//UPDATE
void edk::fonts::fontSetList::TreeFont::updateElement(edk::fonts::fontSetList::FontRetain* value){
    //update the value
    value++;
}

//load the font
edk::fonts::FontSet* edk::fonts::fontSetList::TreeFont::loadFontImage(edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    if(image){
        //find the image
        edk::fonts::fontSetList::FontRetain* ret = this->getFontSetByImage(image,filter);
        if(ret){
            //then retain
            ret->retain();
            return &ret->set;
        }
        else{
            //else create the new fontSet
            ret = new edk::fonts::fontSetList::FontRetain;
            if(ret){
                if(ret->set.loadFontImage(image,filter,color)){
                    //add the fontRet to the tree
                    if(this->add(ret)){
                        ret->retain();
                        return &ret->set;
                    }
                }
                delete ret;
            }
        }
    }
    return NULL;
}
edk::fonts::FontSet* edk::fonts::fontSetList::TreeFont::loadFontImageFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter,edk::color4f32 color){
    if(image){
        //find the image
        edk::fonts::fontSetList::FontRetain* ret = this->getFontSetByImage(name,filter);
        if(ret){
            //then retain
            ret->retain();
            return &ret->set;
        }
        else{
            //else create the new fontSet
            ret = new edk::fonts::fontSetList::FontRetain;
            if(ret){
                if(ret->set.loadFontImageFromMemory(name,image,size,filter,color)){
                    //add the fontRet to the tree
                    if(this->add(ret)){
                        ret->retain();
                        return &ret->set;
                    }
                }
                delete ret;
            }
        }
    }
    return NULL;
}

//remove image
bool edk::fonts::fontSetList::TreeFont::removeImage(edk::char8* image,edk::uint32 filter){
    if(image){
        //test if have the image
        edk::fonts::fontSetList::FontRetain* ret = this->getFontSetByImage(image,filter);
        if(ret){
            //release
            ret->release();
            //test if have no retains
            if(ret->haveNoRetains()){
                //delete the ret
                if(this->remove(ret)){
                    delete ret;
                }
            }
            return true;
        }
    }
    return false;
}
//remove FontSet
bool edk::fonts::fontSetList::TreeFont::removeFontSet(edk::fonts::FontSet* set){
    //test set
    if(set){
        //remove the set
        this->removeImage(set->getName(),set->getFilter());
    }
    return false;
}
//delete all fontSet
void edk::fonts::fontSetList::TreeFont::deleteAllFontSet(){
    edk::uint32 size = this->getSize();
    edk::fonts::fontSetList::FontRetain* temp = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        //
        temp = this->getElementInPosition(i);
        if(temp) delete temp;
    }
    this->clean();
}

edk::fonts::fontSetList::TreeFont edk::fonts::fontSetList::tree;
//static treeFonts
edk::fonts::fontSetList::fontSetList(){
    //
}
edk::fonts::fontSetList::~fontSetList(){
    //
}
//load the fontSet
edk::fonts::FontSet* edk::fonts::fontSetList::createFontSet(edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    return edk::fonts::fontSetList::tree.loadFontImage(image,filter,color);
}
//load the fontSet
edk::fonts::FontSet* edk::fonts::fontSetList::createFontSetFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter,edk::color4f32 color){
    return edk::fonts::fontSetList::tree.loadFontImageFromMemory(name,image,size,filter,color);
}

//remove fontSet
bool edk::fonts::fontSetList::removeFontSetByName(edk::char8* image,edk::uint32 filter){
    return edk::fonts::fontSetList::tree.removeImage(image,filter);
}
//remove fontSet
bool edk::fonts::fontSetList::removeFontSet(edk::fonts::FontSet* set){
    return edk::fonts::fontSetList::tree.removeFontSet(set);
}
//delete all Fonts
void edk::fonts::fontSetList::deleteAllFonts(){
    edk::fonts::fontSetList::tree.deleteAllFontSet();
}