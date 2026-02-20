#include "ColorShow2d.h"

/*
ColorShow2d - ColorShow for the GUI 2D library
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

edk::gui2d::ColorShow2d::ColorShow2d(){
    this->classThis=NULL;
    this->Constructor();
}
edk::gui2d::ColorShow2d::~ColorShow2d(){
    this->Destructor();
}

void edk::gui2d::ColorShow2d::Constructor(){
    edk::gui2d::ObjectGui2d::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->typeGUI = edk::gui2d::gui2dTypeColorShow;
        this->type=edk::TypeObject2DColorShow;
    }
}
void edk::gui2d::ColorShow2d::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
    }
}

bool edk::gui2d::ColorShow2d::setColorRGB(edk::color3f32 colorRGB){
    return this->setColorRGBA(edk::color4f32(colorRGB.r,colorRGB.g,colorRGB.b,1.f));
}
bool edk::gui2d::ColorShow2d::setColorR(edk::float32 r){
    edk::shape::Mesh2D* mesh = this->objColor.getMesh(0u);
    if(mesh){
        return mesh->setPolygonColorR(0u,r);
    }
    return false;
}
bool edk::gui2d::ColorShow2d::setColorG(edk::float32 g){
    edk::shape::Mesh2D* mesh = this->objColor.getMesh(0u);
    if(mesh){
        return mesh->setPolygonColorG(0u,g);
    }
    return false;
}
bool edk::gui2d::ColorShow2d::setColorB(edk::float32 b){
    edk::shape::Mesh2D* mesh = this->objColor.getMesh(0u);
    if(mesh){
        return mesh->setPolygonColorB(0u,b);
    }
    return false;
}
bool edk::gui2d::ColorShow2d::setColorRGBA(edk::color4f32 colorRGBA){
    edk::shape::Mesh2D* mesh = this->objColor.getMesh(0u);
    if(mesh){
        return mesh->setPolygonColor(0u,colorRGBA);
    }
    return false;
}
bool edk::gui2d::ColorShow2d::setColorA(edk::float32 a){
    edk::shape::Mesh2D* mesh = this->objColor.getMesh(0u);
    if(mesh){
        return mesh->setPolygonColorA(0u,a);
    }
    return false;
}

//load the button textures and meshes
bool edk::gui2d::ColorShow2d::load(){
    if(edk::gui2d::ObjectGui2d::load()){
        edk::shape::Mesh2D* mesh = this->objColor.newMesh(0u);
        if(mesh){
            edk::shape::Rectangle2D rect;
            rect.setPivoToCenter();
            rect.setPolygonColor(0.f,0.f,0.f,1.f);
            mesh->addPolygon(rect);
        }
        return true;
    }
    return false;
}
void edk::gui2d::ColorShow2d::unload(){
    this->objColor.clean();
    this->obj.unload();
    edk::gui2d::ObjectGui2d::unload();
}
void edk::gui2d::ColorShow2d::update(){
    edk::gui2d::ObjectGui2d::update();
    edk::rectf32 rectInside = this->getInsideRect();
    this->objColor.position = this->position;
    this->objColor.size = rectInside.size;
}

//XML
bool edk::gui2d::ColorShow2d::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;

        //write the object type
        if(edk::gui2d::ObjectGui2d::writeToXML(xml,id)){
            //create the nameID
            edk::char8* nameID = edk::String::int64ToStr(id);
            if(nameID){
                //concat
                edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_COLORSHOW,nameID);
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
bool edk::gui2d::ColorShow2d::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(edk::gui2d::ObjectGui2d::readFromXML(xml,id)){
            if(nameID){
                //concat
                edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_COLORSHOW,nameID);
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
bool edk::gui2d::ColorShow2d::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    if(xml && pack){
        bool ret=false;
        if(edk::gui2d::ObjectGui2d::readFromXMLFromPack(pack,xml,id)){
            //create the nameID
            edk::char8* nameID = edk::String::int64ToStr(id);
            if(nameID){
                //concat
                edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_COLORSHOW,nameID);
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
void edk::gui2d::ColorShow2d::draw(){
    edk::gui2d::ObjectGui2d::draw();
    this->objColor.drawWithoutMaterial();
}
void edk::gui2d::ColorShow2d::drawSelection(){
    edk::gui2d::ObjectGui2d::drawSelection();
}

////click to select an polygon inside the object
//void edk::gui2d::ColorShow2D::clickStart(edk::uint32,edk::vec2f32){
//}
//void edk::gui2d::ColorShow2D::clickMove(edk::uint32,edk::vec2f32,bool){
//}
//void edk::gui2d::ColorShow2D::clickEnd(edk::uint32,edk::vec2f32,bool,bool){
//}

//clone the gui object from
bool edk::gui2d::ColorShow2d::cloneFrom(edk::gui2d::ObjectGui2d* obj){
    if(edk::gui2d::ObjectGui2d::cloneFrom(obj)){
        if(obj->getTypeGUI() == edk::gui2d::gui2dTypeColorShow){
            edk::gui2d::ColorShow2d* colorShow = (edk::gui2d::ColorShow2d*)obj;
        }
        return true;
    }
    return false;
}
bool edk::gui2d::ColorShow2d::cloneFrom(edk::gui2d::ColorShow2d* obj){
    return this->cloneFrom((edk::gui2d::ObjectGui2d*)obj);
}

