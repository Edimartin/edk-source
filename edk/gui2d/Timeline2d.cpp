#include "Timeline2d.h"

/*
Timeline2d - Show a Rectangle 2d for in GUI 2D library
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
#pragma message "            Inside Timeline2d.cpp"
#endif

edk::gui2d::Timeline2d::Timeline2d(){
    this->classThis=NULL;
    this->Constructor();
}
edk::gui2d::Timeline2d::~Timeline2d(){
    this->Destructor();
}

void edk::gui2d::Timeline2d::Constructor(){
    edk::gui2d::ObjectGui2d::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->colorBackLight = edk::color3f32(0.75f,0.75f,0.75f);
        this->colorBackDark = edk::color3f32(0.25f,0.25f,0.25f);
        this->typeGUI = edk::gui2d::gui2dTypeTimeline;
        this->type=edk::TypeObject2DTimeline;
        this->timeStart=0.f;
        this->timeEnd=100.f;
        this->camStart=-50.f;
        this->camEnd=150.f;
        this->setSlices(10u);

        this->inlineUpdateCameraLenght();
    }
}
void edk::gui2d::Timeline2d::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
    }
}

//SETTERS
bool edk::gui2d::Timeline2d::setSlices(edk::uint32 slices){
    if(slices){
        this->worldSlices = slices;
        this->worldPercent=1.f/(edk::float32)slices;
        return true;
    }
    this->worldSlices = 10u;
    this->worldPercent=1.f/(edk::float32)slices;
    return false;
}

//load the button textures and meshes
bool edk::gui2d::Timeline2d::load(){
    if(edk::gui2d::ObjectGui2d::load()){
        //set the border width
        this->setBorderSize(0.01f);

        edk::shape::Mesh2D* mesh = NULL;
        //objBack
        mesh = this->objBack.newMesh(0u);
        if(mesh){
            edk::shape::Rectangle2D rect;
            rect.setPivoToCenter();
            mesh->addPolygon(rect);
        }
        this->inlineSetObjColor(&this->objBack,this->colorBackDark);
        //objFront
        mesh = this->objFront.newMesh(0u);
        if(mesh){
            edk::shape::Rectangle2D rect;
            rect.setPivoToCenter();
            mesh->addPolygon(rect);
        }
        this->inlineSetObjColor(&this->objFront,this->colorBackLight);
        return true;
    }
    return false;
}
void edk::gui2d::Timeline2d::unload(){
    edk::gui2d::ObjectGui2d::unload();
    this->objBack.clean();
}
void edk::gui2d::Timeline2d::update(){
    edk::gui2d::ObjectGui2d::update();
    edk::rectf32 rectInside;
    rectInside = this->getInsideRectPositionAndSize();
    this->objBack.position = rectInside.origin;
    this->objBack.size = rectInside.size;
    bool success=true;
    this->objFront.unhide();
    //update the objFront
    edk::float32 percentStart,percentEnd;
    if(this->timeStart<this->camEnd){
        if(this->timeStart<this->camStart){
            percentStart=0.f;
        }
        else{
            if(edk::Math::equal(0.f,this->camLenght)){
                percentStart=0.f;
            }
            else{
                percentStart=(this->timeStart-this->camStart)/this->camLenght;
            }
        }
    }
    else{
        //else error
        this->objFront.hide();
        success=false;
    }
    if(this->timeEnd>this->camStart){
        if(this->timeEnd>this->camEnd){
            percentEnd=1.f;
        }
        else{
            if(edk::Math::equal(0.f,this->camLenght)){
                percentEnd=0.f;
            }
            else{
                percentEnd=(this->timeEnd-this->camStart)/this->camLenght;
            }
        }
    }
    else{
        //else error
        this->objFront.hide();
        success=false;
    }

    if(success){
        //set object width positions
        rectInside = this->getInsideRectPoints();
        percentStart = ((rectInside.size.width - rectInside.origin.x)*percentStart)+rectInside.origin.x;
        percentEnd = ((rectInside.size.width - rectInside.origin.x)*percentEnd)+rectInside.origin.x;
        rectInside.origin.x = percentStart;
        rectInside.size.width = percentEnd;
        rectInside.convertIntoPositionAndSize();
        this->objFront.position = rectInside.origin;
        this->objFront.size = rectInside.size;
    }
}

//XML
bool edk::gui2d::Timeline2d::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;

        //write the object type
        if(edk::gui2d::ObjectGui2d::writeToXML(xml,id)){
            //create the nameID
            edk::char8* nameID = edk::String::int64ToStr(id);
            if(nameID){
                //concat
                edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_TIMELINE,nameID);
                if(name){
                    //create the name
                    if(xml->addSelectedNextChild(name)){
                        if(xml->selectChild(name)){
                            //WRITE

                            ret=true;
                            xml->selectFather();
                        }
                    }
                    free(name);
                }
                free(nameID);
            }
        }
        return ret;
    }
    return false;
}
bool edk::gui2d::Timeline2d::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(edk::gui2d::ObjectGui2d::readFromXML(xml,id)){
            if(nameID){
                //concat
                edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_TIMELINE,nameID);
                if(name){
                    //create the name
                    if(xml->selectChild(name)){
                        //READ

                        ret=true;
                        xml->selectFather();
                    }
                    free(name);
                }
                free(nameID);
            }
        }
        return ret;
    }
    return false;
}
bool edk::gui2d::Timeline2d::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    if(xml && pack){
        bool ret=false;
        if(edk::gui2d::ObjectGui2d::readFromXMLFromPack(pack,xml,id)){
            //create the nameID
            edk::char8* nameID = edk::String::int64ToStr(id);
            if(nameID){
                //concat
                edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_TIMELINE,nameID);
                if(name){
                    //create the name
                    if(xml->selectChild(name)){
                        //READ

                        ret=true;
                        xml->selectFather();
                    }
                    free(name);
                }
                free(nameID);
            }
        }
        return ret;
    }
    return false;
}

//draw the button
void edk::gui2d::Timeline2d::draw(){
    edk::gui2d::ObjectGui2d::draw();
    this->objBack.draw();
    this->objFront.draw();

    //calculte the lines
    edk::rectf32 rectInside;
    edk::float32 increment=0.f;
    edk::float32 worldIncrement=0.f;
    edk::float32 worldPosition=0.f;
    edk::float32 worldPercentNew=this->worldPercent;

    //test if need ajust the percent
    if(this->camLenght<(this->worldSlices*DEF_EDK_WORLD_SLICES_PERCENT)){
        worldPercentNew = 1.f/(edk::float32)(this->worldSlices*DEF_EDK_WORLD_SLICES_PERCENT);
    }

    rectInside = this->getInsideRectPoints();

    //draw a line in the beginning of the timeline
    edk::float32 position = 0;
    position = (edk::float32)((edk::int32)this->camStart);
    if(position>0.f){
        position+=1.f;
    }
    if(position<this->camEnd){
        //draw the line
        worldPosition = ((rectInside.size.width - rectInside.origin.x)*
                         ((position - this->camStart)/this->camLenght))
                + rectInside.origin.x;

        increment = worldPercentNew;
        increment = (edk::float32)((edk::int32)(increment * this->camLenght));
        increment+=1.f;
        worldIncrement = ((rectInside.size.width - rectInside.origin.x)*
                          (increment/this->camLenght));
        for(;worldPosition<rectInside.size.width;
            worldPosition+=worldIncrement,position+=increment
            ){
            edk::GU::guColor3f32(0.f,0.f,0.f);
            edk::GU::guBegin(GU_LINES);
            edk::GU::guVertex2f32(worldPosition,rectInside.origin.y);
            edk::GU::guVertex2f32(worldPosition,rectInside.size.height);
            edk::GU::guEnd();
        }

    }
}
void edk::gui2d::Timeline2d::drawSelection(){
    edk::gui2d::ObjectGui2d::drawSelection();
}

//click to select an polygon inside the object
void edk::gui2d::Timeline2d::clickStart(edk::uint32,edk::vec2f32){
    //
}
void edk::gui2d::Timeline2d::clickMove(edk::uint32,edk::vec2f32,bool){
    //
}
void edk::gui2d::Timeline2d::clickEnd(edk::uint32,edk::vec2f32,bool,bool){
    //
}
void edk::gui2d::Timeline2d::mouseScrollVertical(edk::uint32,edk::int32 scroll,bool mouseInside){
    if(mouseInside){
        scroll*=-1;
        //zoom on the camera
        edk::float32 saveStart=this->camStart,saveEnd=this->camEnd;
        edk::float32 newLenght = (this->camLenght*(0.05f*scroll))*0.5f;
        this->camStart-=newLenght;
        this->camEnd+=newLenght;
        if(this->camEnd<(this->camStart+1.f)){
            this->camStart = saveStart;
            this->camEnd=saveEnd;
        }
        this->inlineUpdateCameraLenght();
    }
}
void edk::gui2d::Timeline2d::mouseScrollHorizontal(edk::uint32,edk::int32 scroll,bool mouseInside){
    if(mouseInside){
        //zoom on the camera
        edk::float32 newLenght = (this->camLenght*(0.05f*scroll))*0.5f;
        this->camStart+=newLenght;
        this->camEnd+=newLenght;
        this->inlineUpdateCameraLenght();
    }
}

//clone the gui object from
bool edk::gui2d::Timeline2d::cloneFrom(edk::gui2d::ObjectGui2d* obj){
    if(edk::gui2d::ObjectGui2d::cloneFrom(obj)){
        if(obj->getTypeGUI() == edk::gui2d::gui2dTypeRect){
            //
        }
        return true;
    }
    return false;
}
bool edk::gui2d::Timeline2d::cloneFrom(edk::gui2d::Timeline2d* obj){
    return this->cloneFrom((edk::gui2d::ObjectGui2d*)obj);
}
