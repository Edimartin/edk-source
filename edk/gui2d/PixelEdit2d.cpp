#include "PixelEdit2d.h"

/*
PixelEdit2d - Edit pixels image in the GUI 2D library
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
#pragma message "            Inside PixelsEdit2d.cpp"
#endif

#define EditorBackImage "PixelEditorBackground.image"
#define EditorBackDark  0x55
#define EditorBackLight 0xAA

edk::Image2D edk::gui2d::PixelEdit2d::imgBack;
edk::uint32 edk::gui2d::PixelEdit2d::counterBack=0u;
edk::uint32 edk::gui2d::PixelEdit2d::uvBack=2u;

edk::gui2d::PixelEdit2d::PixelEdit2d(){
    this->classThis=NULL;
    this->Constructor();
}
edk::gui2d::PixelEdit2d::~PixelEdit2d(){
    this->Destructor();
}


void edk::gui2d::PixelEdit2d::Constructor(){
    edk::gui2d::ObjectGui2d::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->typeGUI = edk::gui2d::gui2dTypePixelEdit;
        this->type=edk::TypeObject2DPixelEdit;

        if(!edk::gui2d::PixelEdit2d::counterBack){
            if(edk::gui2d::PixelEdit2d::imgBack.newImage(EditorBackImage,4u,4u,3u,1u)){
                edk::gui2d::PixelEdit2d::imgBack.drawPosition(0u,0u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::gui2d::PixelEdit2d::imgBack.drawPosition(1u,0u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::gui2d::PixelEdit2d::imgBack.drawPosition(0u,1u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::gui2d::PixelEdit2d::imgBack.drawPosition(1u,1u,EditorBackDark,EditorBackDark,EditorBackDark);

                edk::gui2d::PixelEdit2d::imgBack.drawPosition(2u,0u,EditorBackLight,EditorBackLight,EditorBackLight);
                edk::gui2d::PixelEdit2d::imgBack.drawPosition(3u,0u,EditorBackLight,EditorBackLight,EditorBackLight);
                edk::gui2d::PixelEdit2d::imgBack.drawPosition(2u,1u,EditorBackLight,EditorBackLight,EditorBackLight);
                edk::gui2d::PixelEdit2d::imgBack.drawPosition(3u,1u,EditorBackLight,EditorBackLight,EditorBackLight);

                edk::gui2d::PixelEdit2d::imgBack.drawPosition(0u,2u,EditorBackLight,EditorBackLight,EditorBackLight);
                edk::gui2d::PixelEdit2d::imgBack.drawPosition(1u,2u,EditorBackLight,EditorBackLight,EditorBackLight);
                edk::gui2d::PixelEdit2d::imgBack.drawPosition(0u,3u,EditorBackLight,EditorBackLight,EditorBackLight);
                edk::gui2d::PixelEdit2d::imgBack.drawPosition(1u,3u,EditorBackLight,EditorBackLight,EditorBackLight);

                edk::gui2d::PixelEdit2d::imgBack.drawPosition(2u,2u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::gui2d::PixelEdit2d::imgBack.drawPosition(3u,2u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::gui2d::PixelEdit2d::imgBack.drawPosition(2u,3u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::gui2d::PixelEdit2d::imgBack.drawPosition(3u,3u,EditorBackDark,EditorBackDark,EditorBackDark);
                edk::gui2d::PixelEdit2d::counterBack++;
            }
        }
        else{
            edk::gui2d::PixelEdit2d::counterBack++;
        }
        this->setBackgroundUV(2u);
    }
}
void edk::gui2d::PixelEdit2d::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;

        if(edk::gui2d::PixelEdit2d::counterBack){
            edk::gui2d::PixelEdit2d::counterBack--;
            if(!edk::gui2d::PixelEdit2d::counterBack){
                edk::gui2d::PixelEdit2d::imgBack.deleteImage();
            }
        }
    }
}

//SETTERS
bool edk::gui2d::PixelEdit2d::setBackgroundUV(edk::uint32 uv){
    if(uv>=2u){
        this->uvSize = uv;
        return true;
    }
    this->uvSize = 2u;
    return false;
}

//load the button textures and meshes
bool edk::gui2d::PixelEdit2d::load(){
    if(edk::gui2d::ObjectGui2d::load()){
        edk::shape::Mesh2D* mesh = NULL;
        mesh = this->objBack.newMesh();
        if(mesh){
            edk::shape::Rectangle2D rect;
            rect.setPivoToCenter();
            mesh->addPolygon(rect);

            edk::GU::guSetTexturesWrap(GU_REPEAT);
            mesh->material.setTextureFromMemory(&edk::gui2d::PixelEdit2d::imgBack,
                                                0u,
                                                GU_NEAREST,
                                                GU_NEAREST
                                                );
            edk::GU::guSetTexturesWrap(0u);
        }

        ////////////////////////////////////////////
        this->setBackgroundUV(4u);
        ////////////////////////////////////////////
        return true;
    }
    return false;
}
void edk::gui2d::PixelEdit2d::unload(){
    this->objBack.clean();
    edk::gui2d::ObjectGui2d::unload();
}
void edk::gui2d::PixelEdit2d::update(){
    edk::gui2d::ObjectGui2d::update();
    edk::rectf32 rectInside = this->getInsideRect();
    this->objBack.position = this->position;
    this->objBack.size = rectInside.size;
}

//XML
bool edk::gui2d::PixelEdit2d::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;

        //write the object type
        if(edk::gui2d::ObjectGui2d::writeToXML(xml,id)){
            //create the nameID
            edk::char8* nameID = edk::String::int64ToStr(id);
            if(nameID){
                //concat
                edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_PIXELEDIT,nameID);
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
bool edk::gui2d::PixelEdit2d::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(edk::gui2d::ObjectGui2d::readFromXML(xml,id)){
            if(nameID){
                //concat
                edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_PIXELEDIT,nameID);
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
bool edk::gui2d::PixelEdit2d::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    if(xml && pack){
        bool ret=false;
        if(edk::gui2d::ObjectGui2d::readFromXMLFromPack(pack,xml,id)){
            //create the nameID
            edk::char8* nameID = edk::String::int64ToStr(id);
            if(nameID){
                //concat
                edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_PIXELEDIT,nameID);
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
void edk::gui2d::PixelEdit2d::draw(){
    edk::gui2d::ObjectGui2d::draw();

    //test if need change the uv
    if(edk::gui2d::PixelEdit2d::uvBack!=this->uvSize){
        edk::gui2d::PixelEdit2d::uvBack=this->uvSize;
        //change the polygon UV
        edk::shape::Mesh2D* mesh = this->objBack.getMesh(0u);
        if(mesh){
            mesh->selectPolygon(0u);
            mesh->selectedSetVertexUV(1u,
                                      edk::gui2d::PixelEdit2d::uvBack*0.5f,
                                      edk::gui2d::PixelEdit2d::uvBack*0.5f
                                      );
        }
    }
    this->objBack.draw();
}
void edk::gui2d::PixelEdit2d::drawSelection(){
    edk::gui2d::ObjectGui2d::drawSelection();
}

////click to select an polygon inside the object
//void edk::gui2d::PixelsEdit2d::clickStart(edk::uint32,edk::vec2f32){
//}
//void edk::gui2d::PixelsEdit2d::clickMove(edk::uint32,edk::vec2f32,bool){
//}
//void edk::gui2d::PixelsEdit2d::clickEnd(edk::uint32,edk::vec2f32,bool,bool){
//}

//clone the gui object from
bool edk::gui2d::PixelEdit2d::cloneFrom(edk::gui2d::ObjectGui2d* obj){
    if(edk::gui2d::ObjectGui2d::cloneFrom(obj)){
        if(obj->getTypeGUI() == edk::gui2d::gui2dTypePixelEdit){
            edk::gui2d::PixelEdit2d* pixelEditor = (edk::gui2d::PixelEdit2d*)obj;
        }
        return true;
    }
    return false;
}
bool edk::gui2d::PixelEdit2d::cloneFrom(edk::gui2d::PixelEdit2d* obj){
    return this->cloneFrom((edk::gui2d::ObjectGui2d*)obj);
}

