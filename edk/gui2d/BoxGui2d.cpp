#include "BoxGui2d.h"

/*
BoxGui2d - Box for use objects inside a menu in the GUI 2D library
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

edk::gui2d::BoxGui2d::BoxGui2d(){
    this->classThis=NULL;
    this->Constructor();
}
edk::gui2d::BoxGui2d::~BoxGui2d(){
    this->Destructor();
}

void edk::gui2d::BoxGui2d::Constructor(){
    edk::gui2d::ObjectGui2d::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->nextsBack.Constructor();
        this->nextsFore.Constructor();

        this->textScale = this->getTextTemplateScale();
        this->canCleanText=true;
    }
}
void edk::gui2d::BoxGui2d::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->removeAllSubObjectsBackground();

        this->nextsBack.Destructor();
        this->nextsFore.Destructor();
    }
    edk::gui2d::ObjectGui2d::Destructor();
}

//Add a subObject in to the nexes
bool edk::gui2d::BoxGui2d::addSubObjectBackground(edk::Object2DValues* object){
    //test the object
    if(object){
        edk::uint32 size = this->nextsBack.size();
        this->nextsBack.pushBack(object);
        if(size<this->nextsBack.size()){
            return true;
        }
    }
    return false;
}
//remove the usbObject
bool edk::gui2d::BoxGui2d::removeSubObjectBackground(edk::Object2DValues* object){
    //test the object
    if(object){
        //find the object inside the nexes
        edk::uint32 size = this->nextsBack.size();
        for(edk::uint32 i=0u;i<size;i++){
            //test the object inside the nexts
            if(this->nextsBack.get(i)==object){
                //put the object into the end of the stack
                if(this->nextsBack.bringPositionTo(i,this->nextsBack.size()-1u)){
                    //remove the last
                    return this->nextsBack.popBack();
                }
            }
        }
    }
    return false;
}
void edk::gui2d::BoxGui2d::removeAllSubObjectsBackground(){
    this->nextsBack.clean();
}
bool edk::gui2d::BoxGui2d::addSubObjectForeground(edk::Object2DValues* object){
    //test the object
    if(object){
        return this->nextsFore.pushBack(object);
    }
    return false;
}
//remove the usbObject
bool edk::gui2d::BoxGui2d::removeSubObjectForeground(edk::Object2DValues* object){
    //test the object
    if(object){
        //find the object inside the nexes
        edk::uint32 size = this->nextsFore.size();
        for(edk::uint32 i=0u;i<size;i++){
            //test the object inside the nexts
            if(this->nextsFore.get(i)==object){
                //put the object into the end of the stack
                if(this->nextsFore.bringPositionTo(i,this->nextsFore.size()-1u)){
                    //remove the last
                    return this->nextsFore.popBack();
                }
            }
        }
    }
    return false;
}
void edk::gui2d::BoxGui2d::removeAllSubObjectsForeground(){
    this->nextsFore.clean();
}

bool edk::gui2d::BoxGui2d::removeSubObject(edk::Object2DValues* object){
    bool ret=false;
    if(this->removeSubObjectBackground(object)){
        ret = true;
    }
    if(this->removeSubObjectForeground(object)){
        ret = true;
    }
    return ret;
}
void edk::gui2d::BoxGui2d::removeAllSubObjects(){
    this->removeAllSubObjectsBackground();
    this->removeAllSubObjectsForeground();
}

//create a map
bool edk::gui2d::BoxGui2d::createMap(edk::size2ui32 size){
    //first create the new map
    if(this->text.createMap(size)){
        //then return true
        this->textScale = this->getTextTemplateScale();
        return true;
    }
    return false;
}
bool edk::gui2d::BoxGui2d::createMap(edk::uint32 width,edk::uint32 height){
    return this->createMap(edk::size2ui32(width,height));
}
//create a map with only the height size and the scale
bool edk::gui2d::BoxGui2d::createMapHeight(edk::uint32 height,edk::float32 scaleWidth,edk::float32 scaleHeight){
    return this->createMapHeight(height,edk::size2f32(scaleWidth,scaleHeight));
}
bool edk::gui2d::BoxGui2d::createMapHeight(edk::uint32 height,edk::size2f32 scale){
    if(height){
        edk::size2f32 size = this->getInsideRect().size;
        //calculate the text width
        edk::uint32 width = (edk::uint32)((size.width / size.height) / (scale.width / (scale.height * height)));
        if(width){
            //create the map
            bool ret = this->createMap(width,height);
            if(ret){
                this->textScale = scale;
                return true;
            }
        }
    }
    return false;
}
bool edk::gui2d::BoxGui2d::createMapHeight(edk::uint32 height){
    return createMapHeight(height,this->getTextTemplateScale());
}

bool edk::gui2d::BoxGui2d::writeText(const edk::char8* text){
    return this->writeText((edk::char8*) text);
}
bool edk::gui2d::BoxGui2d::writeText(edk::char8* text){
    return this->writeText(text,this->textScale);
}
bool edk::gui2d::BoxGui2d::writeText(const edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight){
    return this->writeText((edk::char8*) text,scaleWidth,scaleHeight);
}
bool edk::gui2d::BoxGui2d::writeText(edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight){
    return this->writeText(text,edk::size2f32(scaleWidth,scaleHeight));
}
bool edk::gui2d::BoxGui2d::writeText(const edk::char8* text,edk::size2f32 scale){
    return writeText((edk::char8*) text,scale);
}
bool edk::gui2d::BoxGui2d::writeText(edk::char8* text,edk::size2f32 scale){
    //test if have create a stringMap
    if(this->text.haveText()){
        this->text.writeString(text,0u,0u,this->text.getMapSizeWidth());

        //test if the scale is different
        if(scale!=this->textSize || true){
            //calculate the scale
            this->calculateTextScale(scale);
        }
        return true;
    }
    //write the new text in the old style
    this->canCleanText=false;
    return edk::gui2d::ObjectGui2d::writeText(text,scale);
}
void edk::gui2d::BoxGui2d::cleanText(){
    if(this->canCleanText){
        //clean the text
        this->text.cleanSpaces();
    }
    this->canCleanText=true;
}
void edk::gui2d::BoxGui2d::deleteText(){
    edk::gui2d::ObjectGui2d::cleanText();
}

void edk::gui2d::BoxGui2d::update(){
    //update the nexes
    edk::uint32 size = this->nextsBack.size();
    edk::Object2DValues* temp;
    for(edk::uint32 i=0u;i<size;i++){
        //test the object inside the nexts
        temp = this->nextsBack.get(i);
        if(temp){
            temp->updateAnimations();
        }
    }
    edk::gui2d::ObjectGui2d::update();
    //update the nexes
    size = this->nextsFore.size();
    for(edk::uint32 i=0u;i<size;i++){
        //test the object inside the nexts
        temp = this->nextsFore.get(i);
        if(temp){
            temp->updateAnimations();
        }
    }
}

//draw the button
void edk::gui2d::BoxGui2d::draw(){
    this->drawStart();
    this->drawObject();
    this->drawSprite();
    this->drawEnd();

    //draw this and draw the nexes
    edk::uint32 size = this->nextsBack.size();
    edk::Object2DValues* temp;
    for(edk::uint32 i=0u;i<size;i++){
        //test the object inside the nexts
        temp = this->nextsBack.get(i);
        if(temp){
            temp->draw();
        }
    }

    this->drawStart();
    this->drawTextFont();
    this->drawTextFontWire();
    this->drawEnd();

    //draw this and draw the nexes
    size = this->nextsFore.size();
    for(edk::uint32 i=0u;i<size;i++){
        //test the object inside the nexts
        temp = this->nextsFore.get(i);
        if(temp){
            temp->draw();
        }
    }

}
void edk::gui2d::BoxGui2d::drawSelection(){
    this->drawStart();
    this->drawObjectSelection();
    this->drawEnd();

    //draw this and draw the nexes
    edk::uint32 size = this->nextsBack.size();
    edk::Object2DValues* temp;
    for(edk::uint32 i=0u;i<size;i++){
        //test the object inside the nexts
        temp = this->nextsBack.get(i);
        if(temp){
            temp->draw();
        }
    }
    //draw this and draw the nexes
    size = this->nextsFore.size();
    for(edk::uint32 i=0u;i<size;i++){
        //test the object inside the nexts
        temp = this->nextsFore.get(i);
        if(temp){
            temp->draw();
        }
    }
}
