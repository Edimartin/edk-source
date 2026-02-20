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

//create the object to draw
void edk::gui2d::ColorPicker2d::createColor(){
    this->objColor.clean();
    this->objColor2.clean();
    switch(this->typeColor){
    case edk::gui2d::colorTypeRGB:
        /*
    {
        //create the mesh
        edk::shape::Mesh2D* mesh = this->objColor.newMesh(0u);
        if(mesh){
            edk::shape::Quadrangle2D quad;

            //FRAME1
            quad.setVertexPosition(0u,
                                   ((1.f/6.f)*0.f)-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(0u,1.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(1u,
                                   ((1.f/6.f)*1.f)-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(1u,1.f,1.f,0.f,
                                1.f);
            quad.setVertexPosition(2u,
                                   ((1.f/6.f)*1.f)-0.5f,
                                   1.f-0.5f
                                   );
            quad.setVertexColor(2u,1.f,1.f,0.f,
                                1.f);
            quad.setVertexPosition(3u,
                                   ((1.f/6.f)*0.f)-0.5f,
                                   1.f-0.5f
                                   );
            quad.setVertexColor(3u,1.f,0.f,0.f,
                                1.f);
            mesh->addPolygon(quad);

            //FRAME2
            quad.setVertexPosition(0u,
                                   ((1.f/6.f)*1.f)-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(0u,1.f,1.f,0.f,
                                1.f);
            quad.setVertexPosition(1u,
                                   ((1.f/6.f)*2.f)-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(1u,0.f,1.f,0.f,
                                1.f);
            quad.setVertexPosition(2u,
                                   ((1.f/6.f)*2.f)-0.5f,
                                   1.f-0.5f
                                   );
            quad.setVertexColor(2u,0.f,1.f,0.f,
                                1.f);
            quad.setVertexPosition(3u,
                                   ((1.f/6.f)*1.f)-0.5f,
                                   1.f-0.5f
                                   );
            quad.setVertexColor(3u,1.f,1.f,0.f,
                                1.f);
            mesh->addPolygon(quad);

            //FRAME3
            quad.setVertexPosition(0u,
                                   ((1.f/6.f)*2.f)-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(0u,0.f,1.f,0.f,
                                1.f);
            quad.setVertexPosition(1u,
                                   ((1.f/6.f)*3.f)-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(1u,0.f,1.f,1.f,
                                1.f);
            quad.setVertexPosition(2u,
                                   ((1.f/6.f)*3.f)-0.5f,
                                   1.f-0.5f
                                   );
            quad.setVertexColor(2u,0.f,1.f,1.f,
                                1.f);
            quad.setVertexPosition(3u,
                                   ((1.f/6.f)*2.f)-0.5f,
                                   1.f-0.5f
                                   );
            quad.setVertexColor(3u,0.f,1.f,0.f,
                                1.f);
            mesh->addPolygon(quad);

            //FRAME4
            quad.setVertexPosition(0u,
                                   ((1.f/6.f)*3.f)-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(0u,0.f,1.f,1.f,
                                1.f);
            quad.setVertexPosition(1u,
                                   ((1.f/6.f)*4.f)-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(1u,0.f,0.f,1.f,
                                1.f);
            quad.setVertexPosition(2u,
                                   ((1.f/6.f)*4.f)-0.5f,
                                   1.f-0.5f
                                   );
            quad.setVertexColor(2u,0.f,0.f,1.f,
                                1.f);
            quad.setVertexPosition(3u,
                                   ((1.f/6.f)*3.f)-0.5f,
                                   1.f-0.5f
                                   );
            quad.setVertexColor(3u,0.f,1.f,1.f,
                                1.f);
            mesh->addPolygon(quad);

            //FRAME5
            quad.setVertexPosition(0u,
                                   ((1.f/6.f)*4.f)-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(0u,0.f,0.f,1.f,
                                1.f);
            quad.setVertexPosition(1u,
                                   ((1.f/6.f)*5.f)-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(1u,1.f,0.f,1.f,
                                1.f);
            quad.setVertexPosition(2u,
                                   ((1.f/6.f)*5.f)-0.5f,
                                   1.f-0.5f
                                   );
            quad.setVertexColor(2u,1.f,0.f,1.f,
                                1.f);
            quad.setVertexPosition(3u,
                                   ((1.f/6.f)*4.f)-0.5f,
                                   1.f-0.5f
                                   );
            quad.setVertexColor(3u,0.f,0.f,1.f,
                                1.f);
            mesh->addPolygon(quad);

            //FRAME6
            quad.setVertexPosition(0u,
                                   ((1.f/6.f)*5.f)-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(0u,1.f,0.f,1.f,
                                1.f);
            quad.setVertexPosition(1u,
                                   ((1.f/6.f)*6.f)-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(1u,1.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(2u,
                                   ((1.f/6.f)*6.f)-0.5f,
                                   1.f-0.5f
                                   );
            quad.setVertexColor(2u,1.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(3u,
                                   ((1.f/6.f)*5.f)-0.5f,
                                   1.f-0.5f
                                   );
            quad.setVertexColor(3u,1.f,0.f,1.f,
                                1.f);
            mesh->addPolygon(quad);






            //LIGHT
            quad.setVertexPosition(0u,
                                   0.f-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(0u,0.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(1u,
                                   1.f-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(1u,0.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(2u,
                                   1.f-0.5f,
                                   0.5f-0.5f
                                   );
            quad.setVertexColor(2u,0.f,0.f,0.f,
                                0.f);
            quad.setVertexPosition(3u,
                                   0.f-0.5f,
                                   0.5f-0.5f
                                   );
            quad.setVertexColor(3u,0.f,0.f,0.f,
                                0.f);
            mesh->addPolygon(quad);
            quad.setVertexPosition(0u,
                                   0.f-0.5f,
                                   0.5f-0.5f
                                   );
            quad.setVertexColor(0u,1.f,1.f,1.f,
                                0.f);
            quad.setVertexPosition(1u,
                                   1.f-0.5f,
                                   0.5f-0.5f
                                   );
            quad.setVertexColor(1u,1.f,1.f,1.f,
                                0.f);
            quad.setVertexPosition(2u,
                                   1.f-0.5f,
                                   1.f-0.5f
                                   );
            quad.setVertexColor(2u,1.f,1.f,1.f,
                                1.f);
            quad.setVertexPosition(3u,
                                   0.f-0.5f,
                                   1.f-0.5f
                                   );
            quad.setVertexColor(3u,1.f,1.f,1.f,
                                1.f);
            mesh->addPolygon(quad);
        }
    }
        */
        break;
    case edk::gui2d::colorTypeHLV:
    {
        //create the mesh
        edk::shape::Mesh2D* mesh = this->objColor.newMesh(0u);
        if(mesh){
            edk::shape::Quadrangle2D quad;

            //FRAME1
            quad.setVertexPosition(0u,
                                   EDK_GUI2D_HUE_PERCENT_BEGIN_X-0.5f,
                                   ((1.f/6.f)*0.f)-0.5f
                                   );
            quad.setVertexColor(0u,1.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(1u,
                                   EDK_GUI2D_HUE_PERCENT_BEGIN_X-0.5f,
                                   ((1.f/6.f)*1.f)-0.5f
                                   );
            quad.setVertexColor(1u,1.f,1.f,0.f,
                                1.f);
            quad.setVertexPosition(2u,
                                   EDK_GUI2D_HUE_PERCENT_END_X-0.5f,
                                   ((1.f/6.f)*1.f)-0.5f
                                   );
            quad.setVertexColor(2u,1.f,1.f,0.f,
                                1.f);
            quad.setVertexPosition(3u,
                                   EDK_GUI2D_HUE_PERCENT_END_X-0.5f,
                                   ((1.f/6.f)*0.f)-0.5f
                                   );
            quad.setVertexColor(3u,1.f,0.f,0.f,
                                1.f);
            mesh->addPolygon(quad);

            //FRAME2
            quad.setVertexPosition(0u,
                                   EDK_GUI2D_HUE_PERCENT_BEGIN_X-0.5f,
                                   ((1.f/6.f)*1.f)-0.5f
                                   );
            quad.setVertexColor(0u,1.f,1.f,0.f,
                                1.f);
            quad.setVertexPosition(1u,
                                   EDK_GUI2D_HUE_PERCENT_BEGIN_X-0.5f,
                                   ((1.f/6.f)*2.f)-0.5f
                                   );
            quad.setVertexColor(1u,0.f,1.f,0.f,
                                1.f);
            quad.setVertexPosition(2u,
                                   EDK_GUI2D_HUE_PERCENT_END_X-0.5f,
                                   ((1.f/6.f)*2.f)-0.5f
                                   );
            quad.setVertexColor(2u,0.f,1.f,0.f,
                                1.f);
            quad.setVertexPosition(3u,
                                   EDK_GUI2D_HUE_PERCENT_END_X-0.5f,
                                   ((1.f/6.f)*1.f)-0.5f
                                   );
            quad.setVertexColor(3u,1.f,1.f,0.f,
                                1.f);
            mesh->addPolygon(quad);

            //FRAME3
            quad.setVertexPosition(0u,
                                   EDK_GUI2D_HUE_PERCENT_BEGIN_X-0.5f,
                                   ((1.f/6.f)*2.f)-0.5f
                                   );
            quad.setVertexColor(0u,0.f,1.f,0.f,
                                1.f);
            quad.setVertexPosition(1u,
                                   EDK_GUI2D_HUE_PERCENT_BEGIN_X-0.5f,
                                   ((1.f/6.f)*3.f)-0.5f
                                   );
            quad.setVertexColor(1u,0.f,1.f,1.f,
                                1.f);
            quad.setVertexPosition(2u,
                                   EDK_GUI2D_HUE_PERCENT_END_X-0.5f,
                                   ((1.f/6.f)*3.f)-0.5f
                                   );
            quad.setVertexColor(2u,0.f,1.f,1.f,
                                1.f);
            quad.setVertexPosition(3u,
                                   EDK_GUI2D_HUE_PERCENT_END_X-0.5f,
                                   ((1.f/6.f)*2.f)-0.5f
                                   );
            quad.setVertexColor(3u,0.f,1.f,0.f,
                                1.f);
            mesh->addPolygon(quad);

            //FRAME4
            quad.setVertexPosition(0u,
                                   EDK_GUI2D_HUE_PERCENT_BEGIN_X-0.5f,
                                   ((1.f/6.f)*3.f)-0.5f
                                   );
            quad.setVertexColor(0u,0.f,1.f,1.f,
                                1.f);
            quad.setVertexPosition(1u,
                                   EDK_GUI2D_HUE_PERCENT_BEGIN_X-0.5f,
                                   ((1.f/6.f)*4.f)-0.5f
                                   );
            quad.setVertexColor(1u,0.f,0.f,1.f,
                                1.f);
            quad.setVertexPosition(2u,
                                   EDK_GUI2D_HUE_PERCENT_END_X-0.5f,
                                   ((1.f/6.f)*4.f)-0.5f
                                   );
            quad.setVertexColor(2u,0.f,0.f,1.f,
                                1.f);
            quad.setVertexPosition(3u,
                                   EDK_GUI2D_HUE_PERCENT_END_X-0.5f,
                                   ((1.f/6.f)*3.f)-0.5f
                                   );
            quad.setVertexColor(3u,0.f,1.f,1.f,
                                1.f);
            mesh->addPolygon(quad);

            //FRAME5
            quad.setVertexPosition(0u,
                                   EDK_GUI2D_HUE_PERCENT_BEGIN_X-0.5f,
                                   ((1.f/6.f)*4.f)-0.5f
                                   );
            quad.setVertexColor(0u,0.f,0.f,1.f,
                                1.f);
            quad.setVertexPosition(1u,
                                   EDK_GUI2D_HUE_PERCENT_BEGIN_X-0.5f,
                                   ((1.f/6.f)*5.f)-0.5f
                                   );
            quad.setVertexColor(1u,1.f,0.f,1.f,
                                1.f);
            quad.setVertexPosition(2u,
                                   EDK_GUI2D_HUE_PERCENT_END_X-0.5f,
                                   ((1.f/6.f)*5.f)-0.5f
                                   );
            quad.setVertexColor(2u,1.f,0.f,1.f,
                                1.f);
            quad.setVertexPosition(3u,
                                   EDK_GUI2D_HUE_PERCENT_END_X-0.5f,
                                   ((1.f/6.f)*4.f)-0.5f
                                   );
            quad.setVertexColor(3u,0.f,0.f,1.f,
                                1.f);
            mesh->addPolygon(quad);

            //FRAME6
            quad.setVertexPosition(0u,
                                   EDK_GUI2D_HUE_PERCENT_BEGIN_X-0.5f,
                                   ((1.f/6.f)*5.f)-0.5f
                                   );
            quad.setVertexColor(0u,1.f,0.f,1.f,
                                1.f);
            quad.setVertexPosition(1u,
                                   EDK_GUI2D_HUE_PERCENT_BEGIN_X-0.5f,
                                   ((1.f/6.f)*6.f)-0.5f
                                   );
            quad.setVertexColor(1u,1.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(2u,
                                   EDK_GUI2D_HUE_PERCENT_END_X-0.5f,
                                   ((1.f/6.f)*6.f)-0.5f
                                   );
            quad.setVertexColor(2u,1.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(3u,
                                   EDK_GUI2D_HUE_PERCENT_END_X-0.5f,
                                   ((1.f/6.f)*5.f)-0.5f
                                   );
            quad.setVertexColor(3u,1.f,0.f,1.f,
                                1.f);
            mesh->addPolygon(quad);
        }

        mesh = this->objColor2.newMesh(0u);
        if(mesh){
            edk::shape::Quadrangle2D quad;

            //FRAME1
            quad.setVertexPosition(0u,
                                   EDK_GUI2D_SATURATION_PERCENT_BEGIN_X-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(0u,0.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(1u,
                                   EDK_GUI2D_SATURATION_PERCENT_BEGIN_X-0.5f,
                                   1.f-0.5f
                                   );
            quad.setVertexColor(1u,1.f,1.f,1.f,
                                1.f);
            quad.setVertexPosition(2u,
                                   EDK_GUI2D_SATURATION_PERCENT_END_X-0.5f,
                                   1.f-0.5f
                                   );
            quad.setVertexColor(2u,1.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(3u,
                                   EDK_GUI2D_SATURATION_PERCENT_END_X-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(3u,0.f,0.f,0.f,
                                1.f);
            mesh->addPolygon(quad);
        }
    }
    default:
        break;
    }
}

void edk::gui2d::ColorPicker2d::processClick(edk::vec2f32 position,bool start){
    if(start){
        this->controllingHue=false;
        this->controllingSaturation=false;
    }
    edk::rectf32 rect = edk::rectf32(this->objColor.position.x,
                                     this->objColor.position.y,
                                     this->objColor.size.width,
                                     this->objColor.size.height
                                     );
    edk::rectf32 rectTemp;
    edk::float32 percentX=0.f,percentY=0.f;
    rect.convertIntoPoints();
    if(position.x >= rect.origin.x
            && position.y >= rect.origin.y
            && position.x < rect.size.width
            && position.y < rect.size.height
            ){
        switch(this->typeColor){
        case edk::gui2d::colorTypeRGB:
            break;
        case edk::gui2d::colorTypeHLV:
            //test if the mouse is inside the hue value
            rectTemp = rect;
            rectTemp.origin.x = ((rect.size.width - rect.origin.x) * EDK_GUI2D_HUE_PERCENT_BEGIN_X)
                    + rect.origin.x;
            rectTemp.size.width = ((rect.size.width - rect.origin.x) * EDK_GUI2D_HUE_PERCENT_END_X)
                    + rect.origin.x;
            if(position.x >= rectTemp.origin.x
                    && position.x < rectTemp.size.width
                    ){
                if(start || this->controllingHue){
                    //INSIDE HUE
                    percentX=0.5f;
                    percentY = (position.y - rect.origin.y) / (this->objColor.size.height);
                    this->valueHue=percentY*360.f;
                    edk::color3ui8 color8 = edk::Image2D::hsvTorgb(this->valueHue,1.f,1.0);
                    edk::color3f32 color32;
                    color32.r = (edk::float32)color8.r/255.f;
                    color32.g = (edk::float32)color8.g/255.f;
                    color32.b = (edk::float32)color8.b/255.f;

                    //update the color in saturation and value
                    this->updatePolygonColorValue(color32);

                    if(start){
                        //
                        this->controllingHue=true;
                    }
                }
            }
            else{
                //else test the value/saturation polygon
                rectTemp.origin.x = ((rect.size.width - rect.origin.x) * EDK_GUI2D_SATURATION_PERCENT_BEGIN_X)
                        + rect.origin.x;
                rectTemp.size.width = ((rect.size.width - rect.origin.x) * EDK_GUI2D_SATURATION_PERCENT_END_X)
                        + rect.origin.x;
                if(position.x >= rectTemp.origin.x
                        && position.x < rectTemp.size.width
                        ){
                    //INSIDE SATURATION/VALUE
                    if(start || this->controllingSaturation){
                        //
                        this->valueSaturation = (position.x - rectTemp.origin.x) / (rectTemp.size.width-rectTemp.origin.x);
                        this->valueValue = (position.y - rectTemp.origin.y) / (rectTemp.size.height-rectTemp.origin.y);
                        if(start){
                            //
                            this->controllingSaturation=true;
                        }
                    }
                }
            }

            break;
        default:
            break;
        }
    }
}
bool edk::gui2d::ColorPicker2d::updatePolygonColorValue(edk::color3f32 color32){
    edk::shape::Mesh2D *mesh = this->objColor2.getMesh(0u);
    if(mesh){
        return mesh->setVertexColor(0u,2u,color32.r,color32.g,color32.b,1.f);
    }
    return false;
}

void edk::gui2d::ColorPicker2d::Constructor(){
    edk::gui2d::ObjectGui2d::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->typeGUI = edk::gui2d::gui2dTypeColorPicker;
        this->type=edk::TypeObject2DColorPicker;
        this->controllingHue=false;
        this->controllingSaturation=false;
        this->valueHue=360.f;
        this->valueSaturation=1.f;
        this->valueValue=1.f;
    }
}
void edk::gui2d::ColorPicker2d::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
    }
}

//set the draw type
bool edk::gui2d::ColorPicker2d::setColorType(edk::gui2d::ColorType type){
    bool ret=false;
    switch(type){
    case edk::gui2d::colorTypeRGB:
        this->typeColor = type;
        ret=true;
        break;
    case edk::gui2d::colorTypeHLV:
        this->typeColor = type;
        ret=true;
        break;
    default:
        this->typeColor = edk::gui2d::colorTypeHLV;
        break;
    }
    this->createColor();
    return ret;
}

//return the color picked
edk::color3ui8 edk::gui2d::ColorPicker2d::getColorRGB8(){
    return edk::Image2D::hsvTorgb(this->valueHue,this->valueSaturation,this->valueValue);
}
edk::color3f32 edk::gui2d::ColorPicker2d::getColorRGB32(){
    edk::color3ui8 color8 = this->getColorRGB8();
    return edk::color3f32((edk::float32)color8.r/255.f,
                          (edk::float32)color8.g/255.f,
                          (edk::float32)color8.b/255.f
                          );
}

//load the button textures and meshes
bool edk::gui2d::ColorPicker2d::load(){
    this->controllingHue=false;
    this->controllingSaturation=false;
    this->valueHue=360.f;
    this->valueSaturation=1.f;
    this->valueValue=1.f;
    if(edk::gui2d::ObjectGui2d::load()){
        this->setColorType(edk::gui2d::colorTypeHLV);
        return true;
    }
    return false;
}
void edk::gui2d::ColorPicker2d::unload(){
    this->controllingHue=false;
    this->controllingSaturation=false;
    this->valueHue=360.f;
    this->valueSaturation=1.f;
    this->valueValue=1.f;
    this->objColor.clean();
    this->objColor2.clean();
    this->obj.unload();
    edk::gui2d::ObjectGui2d::unload();
}
void edk::gui2d::ColorPicker2d::update(){
    edk::gui2d::ObjectGui2d::update();
    edk::rectf32 rectInside = this->getInsideRect();
    this->objColor.position = this->position;
    this->objColor.size = rectInside.size;
    this->objColor2.position = this->position;
    this->objColor2.size = rectInside.size;
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
    this->objColor2.drawWithoutMaterial();
}
void edk::gui2d::ColorPicker2d::drawSelection(){
    edk::gui2d::ObjectGui2d::drawSelection();
}

//click to select an polygon inside the object
void edk::gui2d::ColorPicker2d::clickStart(edk::uint32,edk::vec2f32 position){
    this->processClick(position,true);
}
void edk::gui2d::ColorPicker2d::clickMove(edk::uint32,edk::vec2f32 position,bool){
    this->processClick(position,false);
}
void edk::gui2d::ColorPicker2d::clickEnd(edk::uint32,edk::vec2f32 position,bool,bool){
    this->processClick(position,false);
    this->controllingHue=false;
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

