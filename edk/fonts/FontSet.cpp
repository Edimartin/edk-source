#include "FontSet.h"

/*
Library FontSet - Tile Set for Font Images
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

edk::fonts::FontSet::FontSet(edk::uint32 filter){
    this->classThis=NULL;edkEnd();
    this->Constructor(filter,false);edkEnd();
}
edk::fonts::FontSet::~FontSet(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->deleteImage();edkEnd();
    }
}

void edk::fonts::FontSet::Constructor(edk::uint32 filter,bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;

        this->tileSet.Constructor();edkEnd();
        this->name.Constructor();edkEnd();

        this->filter=filter;edkEnd();
    }
}

//load the font
bool edk::fonts::FontSet::loadFontImage(const edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    edkEnd();
    return this->loadFontImage((edk::char8*) image,filter,color);
}

bool edk::fonts::FontSet::loadFontImage(edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    this->deleteImage();edkEnd();
    edk::tiles::TileSet2D::Tile2Positions2D ret = this->tileSet.loadImageTiles(image,16u,16u,filter,color);edkEnd();
    if(ret.first==1u && ret.last==256u){
        if(this->name.setName(image)){
            this->filter = filter;edkEnd();
            return true;
        }
    }
    this->deleteImage();edkEnd();
    return false;
}

bool edk::fonts::FontSet::loadFontImageFromMemory(const edk::char8* name,
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
    this->deleteImage();edkEnd();
    edk::tiles::TileSet2D::Tile2Positions2D ret = this->tileSet.loadImageTilesFromMemory(name,image,size,16u,16u,filter,color);edkEnd();
    if(ret.first==1u && ret.last==256u){
        if(this->name.setName(name)){
            this->filter = filter;edkEnd();
            return true;
        }
    }
    this->deleteImage();edkEnd();
    return false;
}

bool edk::fonts::FontSet::loadFontImageFromPack(edk::pack::FilePackage* pack,const edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    return this->loadFontImageFromPack(pack,(edk::char8*) image,filter,color);
}
bool edk::fonts::FontSet::loadFontImageFromPack(edk::pack::FilePackage* pack,edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    this->deleteImage();edkEnd();
    edk::tiles::TileSet2D::Tile2Positions2D ret = this->tileSet.loadImageTilesFromPack(pack,image,16u,16u,filter,color);edkEnd();
    if(ret.first==1u && ret.last==256u){
        if(this->name.setName(image)){
            this->filter = filter;edkEnd();
            return true;
        }
    }
    this->deleteImage();edkEnd();
    return false;
}

//delete image
void edk::fonts::FontSet::deleteImage(){
    this->tileSet.deleteTiles();edkEnd();
    this->name.cleanName();edkEnd();
}

//get the tileset
edk::tiles::TileSet2D* edk::fonts::FontSet::getTileSet(){
    edkEnd();
    return &this->tileSet;
}
//return the filter
edk::uint32 edk::fonts::FontSet::getFilter(){
    edkEnd();
    return this->filter;
}

//setName
bool edk::fonts::FontSet::setName(const edk::char8* name){
    return this->setName((edk::char8*) name);
}
bool edk::fonts::FontSet::setName(edk::char8* name){
    this->deleteImage();edkEnd();
    return this->name.setName(name);
}
//test the names
bool edk::fonts::FontSet::nameBiggerThan(const edk::char8* name){
    return this->nameBiggerThan((edk::char8*) name);
}
bool edk::fonts::FontSet::nameBiggerThan(edk::char8* name){
    return this->name.nameBiggerThan(name);
}
bool edk::fonts::FontSet::nameEqualThan(const edk::char8* name){
    return this->nameEqualThan((edk::char8*) name);
}
bool edk::fonts::FontSet::nameEqualThan(edk::char8* name){
    return this->name.nameEqual(name);
}
//get the name
edk::char8* edk::fonts::FontSet::getName(){
    return this->name.getName();edkEnd();
}

edk::fonts::fontSetList::FontRetain::FontRetain(edk::uint32 filter)
    :set(filter)
{
    this->classThis=NULL;edkEnd();
    this->Constructor(filter,false);edkEnd();
}
edk::fonts::fontSetList::FontRetain::~FontRetain(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->retains=0u;
    }
}

void edk::fonts::fontSetList::FontRetain::Constructor(edk::uint32 filter,bool runFather){
    if(this->classThis!=this){
        this->classThis=this;

        this->set.Constructor(filter,runFather);

        this->retains=0u;
    }
}

//retain release
void edk::fonts::fontSetList::FontRetain::retain(){
    this->retains++;edkEnd();
}
bool edk::fonts::fontSetList::FontRetain::release(){
    if(this->retains){
        this->retains--;edkEnd();
        return true;
    }
    return false;
}
//test if have no retains
bool edk::fonts::fontSetList::FontRetain::haveNoRetains(){
    if(this->retains){
        return false;
    }
    return true;
}

//getFontSet
edk::fonts::fontSetList::FontRetain* edk::fonts::fontSetList::TreeFont::getFontSetByImage(edk::char8* image,edk::uint32 filter){
    edk::fonts::fontSetList::FontRetain find(filter);edkEnd();
    find.set.setName(image);edkEnd();
    return this->getElement(&find);
}
//compare if the value is bigger
bool edk::fonts::fontSetList::TreeFont::firstBiggerSecond(edk::fonts::fontSetList::FontRetain* first,edk::fonts::fontSetList::FontRetain* second){
    if(first && second){
        if(first->set.getFilter() > second->set.getFilter()){
            edkEnd();
            return first->set.nameBiggerThan(second->set.getName());
        }
        else if(first->set.getFilter() == second->set.getFilter()){
            edkEnd();
            return first->set.nameBiggerThan(second->set.getName());
        }
    }
    edkEnd();
    return false;
}
bool edk::fonts::fontSetList::TreeFont::firstEqualSecond(edk::fonts::fontSetList::FontRetain* first,edk::fonts::fontSetList::FontRetain* second){
    if(first && second){
        if(first->set.getFilter() == second->set.getFilter()){
            edkEnd();
            return first->set.nameEqualThan(second->set.getName());
        }
    }
    edkEnd();
    return false;
}
//UPDATE
void edk::fonts::fontSetList::TreeFont::updateElement(edk::fonts::fontSetList::FontRetain* value){
    //update the value
    value++;edkEnd();
}

//load the font
edk::fonts::FontSet* edk::fonts::fontSetList::TreeFont::loadFontImage(edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    if(image){
        //find the image
        edk::fonts::fontSetList::FontRetain* ret = this->getFontSetByImage(image,filter);edkEnd();
        if(ret){
            //then retain
            ret->retain();edkEnd();
            return &ret->set;
        }
        else{
            //else create the new fontSet
            ret = new edk::fonts::fontSetList::FontRetain;edkEnd();
            if(ret){
                if(ret->set.loadFontImage(image,filter,color)){
                    //add the fontRet to the tree
                    if(this->add(ret)){
                        ret->retain();edkEnd();
                        return &ret->set;
                    }
                }
                delete ret;edkEnd();
            }
        }
    }
    return NULL;
}
edk::fonts::FontSet* edk::fonts::fontSetList::TreeFont::loadFontImageFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter,edk::color4f32 color){
    if(image){
        //find the image
        edk::fonts::fontSetList::FontRetain* ret = this->getFontSetByImage(name,filter);edkEnd();
        if(ret){
            //then retain
            ret->retain();edkEnd();
            return &ret->set;
        }
        else{
            //else create the new fontSet
            ret = new edk::fonts::fontSetList::FontRetain;edkEnd();
            if(ret){
                if(ret->set.loadFontImageFromMemory(name,image,size,filter,color)){
                    //add the fontRet to the tree
                    if(this->add(ret)){
                        ret->retain();edkEnd();
                        return &ret->set;
                    }
                }
                delete ret;edkEnd();
            }
        }
    }
    return NULL;
}
edk::fonts::FontSet* edk::fonts::fontSetList::TreeFont::loadFontImageFromPack(edk::pack::FilePackage* pack,edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    if(image && pack){
        //find the image
        edk::fonts::fontSetList::FontRetain* ret = this->getFontSetByImage(image,filter);edkEnd();
        if(ret){
            //then retain
            ret->retain();edkEnd();
            return &ret->set;
        }
        else{
            //else create the new fontSet
            ret = new edk::fonts::fontSetList::FontRetain;edkEnd();
            if(ret){
                if(ret->set.loadFontImageFromPack(pack,image,filter,color)){
                    //add the fontRet to the tree
                    if(this->add(ret)){
                        ret->retain();edkEnd();
                        return &ret->set;
                    }
                }
                delete ret;edkEnd();
            }
        }
    }
    return NULL;
}

//remove image
bool edk::fonts::fontSetList::TreeFont::removeImage(edk::char8* image,edk::uint32 filter){
    if(image){
        //test if have the image
        edk::fonts::fontSetList::FontRetain* ret = this->getFontSetByImage(image,filter);edkEnd();
        if(ret){
            //release
            ret->release();edkEnd();
            //test if have no retains
            if(ret->haveNoRetains()){
                //delete the ret
                if(this->remove(ret)){
                    delete ret;edkEnd();
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
        this->removeImage(set->getName(),set->getFilter());edkEnd();
    }
    return false;
}
//delete all fontSet
void edk::fonts::fontSetList::TreeFont::deleteAllFontSet(){
    edk::uint32 size = this->getSize();edkEnd();
    edk::fonts::fontSetList::FontRetain* temp = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        //
        temp = this->getElementInPosition(i);edkEnd();
        if(temp){
            delete temp;edkEnd();
        }
    }
    this->clean();edkEnd();
}

edk::fonts::fontSetList::TreeFont edk::fonts::fontSetList::tree;
bool edk::fonts::fontSetList::templateConstructNeed=true;
//static treeFonts
edk::fonts::fontSetList::fontSetList(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::fonts::fontSetList::~fontSetList(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::fonts::fontSetList::Constructor(bool runFather){
    if(runFather){edkEnd();}
    if(this->classThis!=this){
        this->classThis=this;

        if(edk::fonts::fontSetList::templateConstructNeed){
            edk::fonts::fontSetList::tree.Constructor();
            edk::fonts::fontSetList::templateConstructNeed=false;
        }
    }
}

//load the fontSet
edk::fonts::FontSet* edk::fonts::fontSetList::createFontSet(edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    return edk::fonts::fontSetList::tree.loadFontImage(image,filter,color);
}
//load the fontSet
edk::fonts::FontSet* edk::fonts::fontSetList::createFontSetFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter,edk::color4f32 color){
    return edk::fonts::fontSetList::tree.loadFontImageFromMemory(name,image,size,filter,color);
}
//load the fontSet
edk::fonts::FontSet* edk::fonts::fontSetList::createFontSetFromPack(edk::pack::FilePackage* pack,edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    return edk::fonts::fontSetList::tree.loadFontImageFromPack(pack,image,filter,color);
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
    edk::fonts::fontSetList::tree.deleteAllFontSet();edkEnd();
}
