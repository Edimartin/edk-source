#include "ColorPicker2d.h"

/*
ColorPicker2d - ColorPicker for the GUI 2D library
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
#pragma message "            Inside ColorPicker2d.cpp"
#endif

edk::gui2d::ColorPicker2d::ColorPicker2d(){
    this->classThis=NULL;
    this->Constructor();
}
edk::gui2d::ColorPicker2d::~ColorPicker2d(){
    this->Destructor();
}

void edk::gui2d::ColorPicker2d::Constructor(){
    edk::gui2d::ObjectGui2d::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->typeGUI = edk::gui2d::gui2dTypeColorPicker;

        this->type=edk::TypeObject2DColorPicker;
    }
}
void edk::gui2d::ColorPicker2d::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
    }
}

//load the button textures and meshes
bool edk::gui2d::ColorPicker2d::load(){
    if(edk::gui2d::ObjectGui2d::load()){

        //create the mesh
        edk::shape::Mesh2D* mesh = this->objColor.newMesh(0u);
        if(mesh){
            //edk::shape::Rectangle2D rect;
            //rect.setPivoToCenter();
            //rect.setPolygonColor(1.f,0.f,0.f,1.0f);
            //mesh->addPolygon(rect);

            edk::shape::Quadrangle2D quad1;

            //FRAME1
            quad1.setVertexPosition(0u,
                                    ((1.f/6.f)*0.f)-0.5f,
                                    0.f-0.5f
                                    );
            quad1.setVertexColor(0u,1.f,0.f,0.f,
                                 1.f);
            quad1.setVertexPosition(1u,
                                    ((1.f/6.f)*1.f)-0.5f,
                                    0.f-0.5f
                                    );
            quad1.setVertexColor(1u,1.f,1.f,0.f,
                                 1.f);
            quad1.setVertexPosition(2u,
                                    ((1.f/6.f)*1.f)-0.5f,
                                    1.f-0.5f
                                    );
            quad1.setVertexColor(2u,1.f,1.f,0.f,
                                 1.f);
            quad1.setVertexPosition(3u,
                                    ((1.f/6.f)*0.f)-0.5f,
                                    1.f-0.5f
                                    );
            quad1.setVertexColor(3u,1.f,0.f,0.f,
                                 1.f);
            mesh->addPolygon(quad1);

            //FRAME2
            quad1.setVertexPosition(0u,
                                    ((1.f/6.f)*1.f)-0.5f,
                                    0.f-0.5f
                                    );
            quad1.setVertexColor(0u,1.f,1.f,0.f,
                                 1.f);
            quad1.setVertexPosition(1u,
                                    ((1.f/6.f)*2.f)-0.5f,
                                    0.f-0.5f
                                    );
            quad1.setVertexColor(1u,0.f,1.f,0.f,
                                 1.f);
            quad1.setVertexPosition(2u,
                                    ((1.f/6.f)*2.f)-0.5f,
                                    1.f-0.5f
                                    );
            quad1.setVertexColor(2u,0.f,1.f,0.f,
                                 1.f);
            quad1.setVertexPosition(3u,
                                    ((1.f/6.f)*1.f)-0.5f,
                                    1.f-0.5f
                                    );
            quad1.setVertexColor(3u,1.f,1.f,0.f,
                                 1.f);
            mesh->addPolygon(quad1);

            //FRAME3
            quad1.setVertexPosition(0u,
                                    ((1.f/6.f)*2.f)-0.5f,
                                    0.f-0.5f
                                    );
            quad1.setVertexColor(0u,0.f,1.f,0.f,
                                 1.f);
            quad1.setVertexPosition(1u,
                                    ((1.f/6.f)*3.f)-0.5f,
                                    0.f-0.5f
                                    );
            quad1.setVertexColor(1u,0.f,1.f,1.f,
                                 1.f);
            quad1.setVertexPosition(2u,
                                    ((1.f/6.f)*3.f)-0.5f,
                                    1.f-0.5f
                                    );
            quad1.setVertexColor(2u,0.f,1.f,1.f,
                                 1.f);
            quad1.setVertexPosition(3u,
                                    ((1.f/6.f)*2.f)-0.5f,
                                    1.f-0.5f
                                    );
            quad1.setVertexColor(3u,0.f,1.f,0.f,
                                 1.f);
            mesh->addPolygon(quad1);

            //FRAME4
            quad1.setVertexPosition(0u,
                                    ((1.f/6.f)*3.f)-0.5f,
                                    0.f-0.5f
                                    );
            quad1.setVertexColor(0u,0.f,1.f,1.f,
                                 1.f);
            quad1.setVertexPosition(1u,
                                    ((1.f/6.f)*4.f)-0.5f,
                                    0.f-0.5f
                                    );
            quad1.setVertexColor(1u,0.f,0.f,1.f,
                                 1.f);
            quad1.setVertexPosition(2u,
                                    ((1.f/6.f)*4.f)-0.5f,
                                    1.f-0.5f
                                    );
            quad1.setVertexColor(2u,0.f,0.f,1.f,
                                 1.f);
            quad1.setVertexPosition(3u,
                                    ((1.f/6.f)*3.f)-0.5f,
                                    1.f-0.5f
                                    );
            quad1.setVertexColor(3u,0.f,1.f,1.f,
                                 1.f);
            mesh->addPolygon(quad1);

            //FRAME5
            quad1.setVertexPosition(0u,
                                    ((1.f/6.f)*4.f)-0.5f,
                                    0.f-0.5f
                                    );
            quad1.setVertexColor(0u,0.f,0.f,1.f,
                                 1.f);
            quad1.setVertexPosition(1u,
                                    ((1.f/6.f)*5.f)-0.5f,
                                    0.f-0.5f
                                    );
            quad1.setVertexColor(1u,1.f,0.f,1.f,
                                 1.f);
            quad1.setVertexPosition(2u,
                                    ((1.f/6.f)*5.f)-0.5f,
                                    1.f-0.5f
                                    );
            quad1.setVertexColor(2u,1.f,0.f,1.f,
                                 1.f);
            quad1.setVertexPosition(3u,
                                    ((1.f/6.f)*4.f)-0.5f,
                                    1.f-0.5f
                                    );
            quad1.setVertexColor(3u,0.f,0.f,1.f,
                                 1.f);
            mesh->addPolygon(quad1);

            //FRAME6
            quad1.setVertexPosition(0u,
                                    ((1.f/6.f)*5.f)-0.5f,
                                    0.f-0.5f
                                    );
            quad1.setVertexColor(0u,1.f,0.f,1.f,
                                 1.f);
            quad1.setVertexPosition(1u,
                                    ((1.f/6.f)*6.f)-0.5f,
                                    0.f-0.5f
                                    );
            quad1.setVertexColor(1u,1.f,0.f,0.f,
                                 1.f);
            quad1.setVertexPosition(2u,
                                    ((1.f/6.f)*6.f)-0.5f,
                                    1.f-0.5f
                                    );
            quad1.setVertexColor(2u,1.f,0.f,0.f,
                                 1.f);
            quad1.setVertexPosition(3u,
                                    ((1.f/6.f)*5.f)-0.5f,
                                    1.f-0.5f
                                    );
            quad1.setVertexColor(3u,1.f,0.f,1.f,
                                 1.f);
            mesh->addPolygon(quad1);






            //LIGHT
            quad1.setVertexPosition(0u,
                                    0.f-0.5f,
                                    0.f-0.5f
                                    );
            quad1.setVertexColor(0u,0.f,0.f,0.f,
                                 1.f);
            quad1.setVertexPosition(1u,
                                    1.f-0.5f,
                                    0.f-0.5f
                                    );
            quad1.setVertexColor(1u,0.f,0.f,0.f,
                                 1.f);
            quad1.setVertexPosition(2u,
                                    1.f-0.5f,
                                    0.5f-0.5f
                                    );
            quad1.setVertexColor(2u,0.f,0.f,0.f,
                                 0.f);
            quad1.setVertexPosition(3u,
                                    0.f-0.5f,
                                    0.5f-0.5f
                                    );
            quad1.setVertexColor(3u,0.f,0.f,0.f,
                                 0.f);
            mesh->addPolygon(quad1);
            quad1.setVertexPosition(0u,
                                    0.f-0.5f,
                                    0.5f-0.5f
                                    );
            quad1.setVertexColor(0u,1.f,1.f,1.f,
                                 0.f);
            quad1.setVertexPosition(1u,
                                    1.f-0.5f,
                                    0.5f-0.5f
                                    );
            quad1.setVertexColor(1u,1.f,1.f,1.f,
                                 0.f);
            quad1.setVertexPosition(2u,
                                    1.f-0.5f,
                                    1.f-0.5f
                                    );
            quad1.setVertexColor(2u,1.f,1.f,1.f,
                                 1.f);
            quad1.setVertexPosition(3u,
                                    0.f-0.5f,
                                    1.f-0.5f
                                    );
            quad1.setVertexColor(3u,1.f,1.f,1.f,
                                 1.f);
            mesh->addPolygon(quad1);
        }
        return true;
    }
    return false;
}
void edk::gui2d::ColorPicker2d::unload(){
    this->objColor.clean();
    this->obj.unload();
    edk::gui2d::ObjectGui2d::unload();
}
void edk::gui2d::ColorPicker2d::update(){
    edk::gui2d::ObjectGui2d::update();
    edk::rectf32 rectInside = this->getInsideRect();
    this->objColor.position = this->position;
    this->objColor.size = rectInside.size;
}

//XML
bool edk::gui2d::ColorPicker2d::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;

        //write the object type
        if(edk::gui2d::ObjectGui2d::writeToXML(xml,id)){
            //create the nameID
            edk::char8* nameID = edk::String::int64ToStr(id);
            if(nameID){
                //concat
                edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_COLORPICKER,nameID);
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
bool edk::gui2d::ColorPicker2d::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(edk::gui2d::ObjectGui2d::readFromXML(xml,id)){
            if(nameID){
                //concat
                edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_COLORPICKER,nameID);
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
bool edk::gui2d::ColorPicker2d::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    if(xml && pack){
        bool ret=false;
        if(edk::gui2d::ObjectGui2d::readFromXMLFromPack(pack,xml,id)){
            //create the nameID
            edk::char8* nameID = edk::String::int64ToStr(id);
            if(nameID){
                //concat
                edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_COLORPICKER,nameID);
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
void edk::gui2d::ColorPicker2d::draw(){
    edk::gui2d::ObjectGui2d::draw();
    this->objColor.drawWithoutMaterial();
}
void edk::gui2d::ColorPicker2d::drawSelection(){
    edk::gui2d::ObjectGui2d::drawSelection();
}

//clone the gui object from
bool edk::gui2d::ColorPicker2d::cloneFrom(edk::gui2d::ObjectGui2d* obj){
    if(edk::gui2d::ObjectGui2d::cloneFrom(obj)){
        if(obj->getTypeGUI() == edk::gui2d::gui2dTypeColorPicker){
            edk::gui2d::ColorPicker2d* colorPick = (edk::gui2d::ColorPicker2d*)obj;
        }
        return true;
    }
    return false;
}
bool edk::gui2d::ColorPicker2d::cloneFrom(edk::gui2d::ColorPicker2d* obj){
    return this->cloneFrom((edk::gui2d::ObjectGui2d*)obj);
}

