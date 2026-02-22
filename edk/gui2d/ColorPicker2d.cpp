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
    this->objColor1.clean();
    this->objColor2.clean();
    this->objColor3.clean();
    this->objController1.clean();
    this->objController2.clean();
    this->objController3.clean();
    this->objColorFinal.clean();
    switch(this->typeColor){
    case edk::gui2d::colorTypeRGB:
    {
        edk::shape::Mesh2D* mesh = this->objColor1.newMesh(0u);
        if(mesh){
            edk::shape::Quadrangle2D quad;

            //FRAME R
            //LEFT
            quad.setVertexPosition(0u,
                                   0.f-0.5f,
                                   EDK_GUI2D_SHOW_R_BEGIN_Y-0.5f
                                   );
            quad.setVertexColor(0u,0.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(1u,
                                   0.f-0.5f,
                                   EDK_GUI2D_SHOW_R_END_Y-0.5f
                                   );
            quad.setVertexColor(1u,0.f,0.f,0.f,
                                1.f);
            //RUGHT
            quad.setVertexPosition(2u,
                                   1.f-0.5f,
                                   EDK_GUI2D_SHOW_R_END_Y-0.5f
                                   );
            quad.setVertexColor(2u,1.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(3u,
                                   1.f-0.5f,
                                   EDK_GUI2D_SHOW_R_BEGIN_Y-0.5f
                                   );
            quad.setVertexColor(3u,1.f,0.f,0.f,
                                1.f);
            mesh->addPolygon(quad);
            //FRAME G
            //LEFT
            quad.setVertexPosition(0u,
                                   0.f-0.5f,
                                   EDK_GUI2D_SHOW_G_BEGIN_Y-0.5f
                                   );
            quad.setVertexColor(0u,0.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(1u,
                                   0.f-0.5f,
                                   EDK_GUI2D_SHOW_G_END_Y-0.5f
                                   );
            quad.setVertexColor(1u,0.f,0.f,0.f,
                                1.f);
            //RUGHT
            quad.setVertexPosition(2u,
                                   1.f-0.5f,
                                   EDK_GUI2D_SHOW_G_END_Y-0.5f
                                   );
            quad.setVertexColor(2u,0.f,1.f,0.f,
                                1.f);
            quad.setVertexPosition(3u,
                                   1.f-0.5f,
                                   EDK_GUI2D_SHOW_G_BEGIN_Y-0.5f
                                   );
            quad.setVertexColor(3u,0.f,1.f,0.f,
                                1.f);
            mesh->addPolygon(quad);
            //FRAME B
            //LEFT
            quad.setVertexPosition(0u,
                                   0.f-0.5f,
                                   EDK_GUI2D_SHOW_B_BEGIN_Y-0.5f
                                   );
            quad.setVertexColor(0u,0.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(1u,
                                   0.f-0.5f,
                                   EDK_GUI2D_SHOW_B_END_Y-0.5f
                                   );
            quad.setVertexColor(1u,0.f,0.f,0.f,
                                1.f);
            //RUGHT
            quad.setVertexPosition(2u,
                                   1.f-0.5f,
                                   EDK_GUI2D_SHOW_B_END_Y-0.5f
                                   );
            quad.setVertexColor(2u,0.f,0.f,1.f,
                                1.f);
            quad.setVertexPosition(3u,
                                   1.f-0.5f,
                                   EDK_GUI2D_SHOW_B_BEGIN_Y-0.5f
                                   );
            quad.setVertexColor(3u,0.f,0.f,1.f,
                                1.f);
            mesh->addPolygon(quad);
        }
        mesh = this->objColorFinal.newMesh(0u);
        if(mesh){
            edk::shape::Quadrangle2D quad;

            //FRAME1
            quad.setVertexPosition(0u,
                                   EDK_GUI2D_SATURATION_PERCENT_BEGIN_X-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(0u,1.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(1u,
                                   EDK_GUI2D_SATURATION_PERCENT_BEGIN_X-0.5f,
                                   EDK_GUI2D_SHOW_PERCENT_END_Y-0.5f
                                   );
            quad.setVertexColor(1u,1.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(2u,
                                   1.f-0.5f,
                                   EDK_GUI2D_SHOW_PERCENT_END_Y-0.5f
                                   );
            quad.setVertexColor(2u,1.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(3u,
                                   1.f-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(3u,1.f,0.f,0.f,
                                1.f);
            mesh->addPolygon(quad);
        }
        edk::color3f32 rgb32 = this->getColorRGB32();
        //R
        mesh = this->objController1.newMesh(0u);
        if(mesh){
            edk::shape::Rectangle2D rect;
            rect.setVertexPosition(0u,
                                   (rgb32.r - 0.01f)-0.5f,
                                   EDK_GUI2D_SHOW_R_BEGIN_Y-0.5f
                                   );
            rect.setVertexPosition(1u,
                                   (rgb32.r + 0.01f)-0.5f,
                                   EDK_GUI2D_SHOW_R_END_Y-0.5f
                                   );
            rect.setPolygonColor(0.f,0.f,0.f,1.f);
            mesh->addPolygon(rect);
            rect.setVertexPosition(0u,
                                   (rgb32.r - 0.005f)-0.5f,
                                   EDK_GUI2D_SHOW_R_BEGIN_Y-0.5f
                                   );
            rect.setVertexPosition(1u,
                                   (rgb32.r + 0.005f)-0.5f,
                                   EDK_GUI2D_SHOW_R_END_Y-0.5f
                                   );
            rect.setPolygonColor(1.f,1.f,1.f,1.f);
            mesh->addPolygon(rect);
        }
        //G
        mesh = this->objController2.newMesh(0u);
        if(mesh){
            edk::shape::Rectangle2D rect;
            rect.setVertexPosition(0u,
                                   (rgb32.g - 0.01f)-0.5f,
                                   EDK_GUI2D_SHOW_G_BEGIN_Y-0.5f
                                   );
            rect.setVertexPosition(1u,
                                   (rgb32.g + 0.01f)-0.5f,
                                   EDK_GUI2D_SHOW_G_END_Y-0.5f
                                   );
            rect.setPolygonColor(0.f,0.f,0.f,1.f);
            mesh->addPolygon(rect);
            rect.setVertexPosition(0u,
                                   (rgb32.g - 0.005f)-0.5f,
                                   EDK_GUI2D_SHOW_G_BEGIN_Y-0.5f
                                   );
            rect.setVertexPosition(1u,
                                   (rgb32.g + 0.005f)-0.5f,
                                   EDK_GUI2D_SHOW_G_END_Y-0.5f
                                   );
            rect.setPolygonColor(1.f,1.f,1.f,1.f);
            mesh->addPolygon(rect);
        }
        //B
        mesh = this->objController3.newMesh(0u);
        if(mesh){
            edk::shape::Rectangle2D rect;
            rect.setVertexPosition(0u,
                                   (rgb32.b - 0.01f)-0.5f,
                                   EDK_GUI2D_SHOW_B_BEGIN_Y-0.5f
                                   );
            rect.setVertexPosition(1u,
                                   (rgb32.b + 0.01f)-0.5f,
                                   EDK_GUI2D_SHOW_B_END_Y-0.5f
                                   );
            rect.setPolygonColor(0.f,0.f,0.f,1.f);
            mesh->addPolygon(rect);
            rect.setVertexPosition(0u,
                                   (rgb32.b - 0.005f)-0.5f,
                                   EDK_GUI2D_SHOW_B_BEGIN_Y-0.5f
                                   );
            rect.setVertexPosition(1u,
                                   (rgb32.b + 0.005f)-0.5f,
                                   EDK_GUI2D_SHOW_B_END_Y-0.5f
                                   );
            rect.setPolygonColor(1.f,1.f,1.f,1.f);
            mesh->addPolygon(rect);
        }
    }
        break;
    case edk::gui2d::colorTypeHSV:
    {
        //create the mesh
        edk::shape::Mesh2D* mesh = this->objColor1.newMesh(0u);
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
                                   EDK_GUI2D_SATURATION_PERCENT_BEGIN_Y-0.5f
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
                                   EDK_GUI2D_SATURATION_PERCENT_BEGIN_Y-0.5f
                                   );
            quad.setVertexColor(3u,0.f,0.f,0.f,
                                1.f);
            mesh->addPolygon(quad);
        }

        mesh = this->objColorFinal.newMesh(0u);
        if(mesh){
            edk::shape::Quadrangle2D quad;

            //FRAME1
            quad.setVertexPosition(0u,
                                   EDK_GUI2D_SATURATION_PERCENT_BEGIN_X-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(0u,1.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(1u,
                                   EDK_GUI2D_SATURATION_PERCENT_BEGIN_X-0.5f,
                                   EDK_GUI2D_SHOW_PERCENT_END_Y-0.5f
                                   );
            quad.setVertexColor(1u,1.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(2u,
                                   EDK_GUI2D_SATURATION_PERCENT_END_X-0.5f,
                                   EDK_GUI2D_SHOW_PERCENT_END_Y-0.5f
                                   );
            quad.setVertexColor(2u,1.f,0.f,0.f,
                                1.f);
            quad.setVertexPosition(3u,
                                   EDK_GUI2D_SATURATION_PERCENT_END_X-0.5f,
                                   0.f-0.5f
                                   );
            quad.setVertexColor(3u,1.f,0.f,0.f,
                                1.f);
            mesh->addPolygon(quad);
        }
        //H
        mesh = this->objController1.newMesh(0u);
        edk::float32 percent = this->channelHue/360.f;
        if(mesh){
            edk::shape::Rectangle2D rect;
            rect.setVertexPosition(0u,
                                   EDK_GUI2D_HUE_PERCENT_BEGIN_X-0.5f,
                                   (percent - 0.01f)-0.5f
                                   );
            rect.setVertexPosition(1u,
                                   EDK_GUI2D_HUE_PERCENT_END_X-0.5f,
                                   (percent + 0.01f)-0.5f
                                   );
            rect.setPolygonColor(0.f,0.f,0.f,1.f);
            mesh->addPolygon(rect);
            rect.setVertexPosition(0u,
                                   EDK_GUI2D_HUE_PERCENT_BEGIN_X-0.5f,
                                   (percent - 0.005f)-0.5f
                                   );
            rect.setVertexPosition(1u,
                                   EDK_GUI2D_HUE_PERCENT_END_X-0.5f,
                                   (percent + 0.005f)-0.5f
                                   );
            rect.setPolygonColor(1.f,1.f,1.f,1.f);
            mesh->addPolygon(rect);
        }
        //S
        mesh = this->objController2.newMesh(0u);
        edk::float32 percentSize = 1.f-EDK_GUI2D_SATURATION_PERCENT_BEGIN_Y;
        percent = (this->channelValue * percentSize) + EDK_GUI2D_SATURATION_PERCENT_BEGIN_Y;
        if(mesh){
            edk::shape::Rectangle2D rect;
            rect.setVertexPosition(0u,
                                   EDK_GUI2D_SATURATION_PERCENT_BEGIN_X -0.5f,
                                   (percent - 0.01f)-0.5f
                                   );
            rect.setVertexPosition(1u,
                                   EDK_GUI2D_SATURATION_PERCENT_END_X-0.5f,
                                   (percent + 0.01f)-0.5f
                                   );
            rect.setPolygonColor(0.f,0.f,0.f,1.f);
            mesh->addPolygon(rect);
            rect.setVertexPosition(0u,
                                   EDK_GUI2D_SATURATION_PERCENT_BEGIN_X-0.5f,
                                   (percent - 0.005f)-0.5f
                                   );
            rect.setVertexPosition(1u,
                                   EDK_GUI2D_SATURATION_PERCENT_END_X-0.5f,
                                   (percent + 0.005f)-0.5f
                                   );
            rect.setPolygonColor(1.f,1.f,1.f,1.f);
            mesh->addPolygon(rect);
        }
        //S
        mesh = this->objController3.newMesh(0u);
        percentSize = EDK_GUI2D_SATURATION_PERCENT_END_X-EDK_GUI2D_SATURATION_PERCENT_BEGIN_X;
        percent = (this->channelSaturation * percentSize) + EDK_GUI2D_SATURATION_PERCENT_BEGIN_X;
        if(mesh){
            edk::shape::Rectangle2D rect;
            rect.setVertexPosition(0u,
                                   (percent - 0.01f)-0.5f,
                                   EDK_GUI2D_SATURATION_PERCENT_BEGIN_Y -0.5f
                                   );
            rect.setVertexPosition(1u,
                                   (percent + 0.01f)-0.5f,
                                   1.f-0.5f
                                   );
            rect.setPolygonColor(0.f,0.f,0.f,1.f);
            mesh->addPolygon(rect);
            rect.setVertexPosition(0u,
                                   (percent - 0.005f)-0.5f,
                                   EDK_GUI2D_SATURATION_PERCENT_BEGIN_Y -0.5f
                                   );
            rect.setVertexPosition(1u,
                                   (percent + 0.005f)-0.5f,
                                   1.f-0.5f
                                   );
            rect.setPolygonColor(1.f,1.f,1.f,1.f);
            mesh->addPolygon(rect);
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
        this->controllingR=false;
        this->controllingG=false;
        this->controllingB=false;
    }
    edk::rectf32 rect = edk::rectf32(this->objColor1.position.x,
                                     this->objColor1.position.y,
                                     this->objColor1.size.width,
                                     this->objColor1.size.height
                                     );
    edk::rectf32 rectTemp;
    edk::float32 percent=0.f;
    rect.convertIntoPoints();
    if(position.x >= rect.origin.x
            && position.y >= rect.origin.y
            && position.x < rect.size.width
            && position.y < rect.size.height
            ){
        switch(this->typeColor){
        case edk::gui2d::colorTypeRGB:
            //test if the mouse is inside the hue value
            rectTemp = rect;
            rectTemp.origin.y = ((rect.size.height - rect.origin.y) * EDK_GUI2D_SHOW_R_BEGIN_Y)
                    + rect.origin.y;
            rectTemp.size.height = ((rect.size.height - rect.origin.y) * EDK_GUI2D_SHOW_R_END_Y)
                    + rect.origin.y;
            if(position.y >= rectTemp.origin.y
                    && position.y < rectTemp.size.height
                    ){
                if(start || this->controllingR){
                    //INSIDE HUE
                    percent = (position.x - rect.origin.x) / (this->objColor1.size.width);
                    //change the rgb color
                    edk::color3f32 rgb32 = this->getColorRGB32();
                    rgb32.r = percent;

                    this->setColorRGB32(rgb32);

                    if(start){
                        this->controllingR=true;
                    }
                }
            }
            else{
                rectTemp.origin.y = ((rect.size.height - rect.origin.y) * EDK_GUI2D_SHOW_G_BEGIN_Y)
                        + rect.origin.y;
                rectTemp.size.height = ((rect.size.height - rect.origin.y) * EDK_GUI2D_SHOW_G_END_Y)
                        + rect.origin.y;
                if(position.y >= rectTemp.origin.y
                        && position.y < rectTemp.size.height
                        ){
                    if(start || this->controllingG){
                        //INSIDE HUE
                        percent = (position.x - rect.origin.x) / (this->objColor2.size.width);
                        //change the rgb color
                        edk::color3f32 rgb32 = this->getColorRGB32();
                        rgb32.g = percent;

                        this->setColorRGB32(rgb32);

                        if(start){
                            this->controllingG=true;
                        }
                    }
                }
                else{
                    rectTemp.origin.y = ((rect.size.height - rect.origin.y) * EDK_GUI2D_SHOW_B_BEGIN_Y)
                            + rect.origin.y;
                    rectTemp.size.height = ((rect.size.height - rect.origin.y) * EDK_GUI2D_SHOW_B_END_Y)
                            + rect.origin.y;
                    if(position.y >= rectTemp.origin.y
                            && position.y < rectTemp.size.height
                            ){
                        if(start || this->controllingB){
                            //INSIDE HUE
                            percent = (position.x - rect.origin.x) / (this->objColor3.size.width);
                            //change the rgb color
                            edk::color3f32 rgb32 = this->getColorRGB32();
                            rgb32.b = percent;

                            this->setColorRGB32(rgb32);

                            if(start){
                                this->controllingB=true;
                            }
                        }
                    }
                }
            }
            break;
        case edk::gui2d::colorTypeHSV:
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
                    percent = (position.y - rect.origin.y) / (this->objColor1.size.height);
                    this->channelHue=percent*360.f;

                    //update the color in saturation and value
                    this->setColorHSV32(this->channelHue,this->channelSaturation,this->channelValue);

                    if(start){
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
                rectTemp.origin.y = ((rect.size.height - rect.origin.y) * EDK_GUI2D_SATURATION_PERCENT_BEGIN_Y)
                        + rect.origin.y;
                if(position.x >= rectTemp.origin.x
                        && position.x < rectTemp.size.width
                        && position.y >= rectTemp.origin.y
                        ){
                    //INSIDE SATURATION/VALUE
                    if(start || this->controllingSaturation){
                        //
                        this->channelSaturation = (position.x - rectTemp.origin.x) / (rectTemp.size.width-rectTemp.origin.x);
                        this->channelValue = (position.y - rectTemp.origin.y) / (rectTemp.size.height-rectTemp.origin.y);

                        this->setColorHSV32(this->channelHue,this->channelSaturation,this->channelValue);

                        if(start){
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
    bool ret = true;
    edk::shape::Mesh2D *mesh = this->objColor2.getMesh(0u);
    if(mesh){
        if(!mesh->setVertexColor(0u,2u,color32.r,color32.g,color32.b,1.f)){
            ret = false;
        }
    }
    //H
    mesh = this->objController1.getMesh(0u);
    edk::float32 percent = this->channelHue/360.f;
    if(mesh){
        mesh->setVertexPositionY(0u,0u,(percent - 0.01f)-0.5f);
        mesh->setVertexPositionY(0u,1u,(percent + 0.01f)-0.5f);
        mesh->setVertexPositionY(1u,0u,(percent - 0.005f)-0.5f);
        mesh->setVertexPositionY(1u,1u,(percent + 0.005f)-0.5f);
    }
    //S
    mesh = this->objController2.getMesh(0u);
    edk::float32 percentSize = 1.f-EDK_GUI2D_SATURATION_PERCENT_BEGIN_Y;
    percent = (this->channelValue * percentSize) + EDK_GUI2D_SATURATION_PERCENT_BEGIN_Y;
    if(mesh){
        mesh->setVertexPositionY(0u,0u,(percent - 0.01f)-0.5f);
        mesh->setVertexPositionY(0u,1u,(percent + 0.01f)-0.5f);
        mesh->setVertexPositionY(1u,0u,(percent - 0.005f)-0.5f);
        mesh->setVertexPositionY(1u,1u,(percent + 0.005f)-0.5f);
    }
    //S
    mesh = this->objController3.getMesh(0u);
    percentSize = EDK_GUI2D_SATURATION_PERCENT_END_X-EDK_GUI2D_SATURATION_PERCENT_BEGIN_X;
    percent = (this->channelSaturation * percentSize) + EDK_GUI2D_SATURATION_PERCENT_BEGIN_X;
    if(mesh){
        mesh->setVertexPositionX(0u,0u,(percent - 0.01f)-0.5f);
        mesh->setVertexPositionX(0u,1u,(percent + 0.01f)-0.5f);
        mesh->setVertexPositionX(1u,0u,(percent - 0.005f)-0.5f);
        mesh->setVertexPositionX(1u,1u,(percent + 0.005f)-0.5f);
    }
    return ret;
}

bool edk::gui2d::ColorPicker2d::updatePolygonColorRGB(edk::color3f32 color32){
    bool ret = true;
    edk::shape::Mesh2D *mesh = NULL;
    mesh = this->objColor1.getMesh(0u);
    if(mesh){
        //R
        //LEFT
        if(!mesh->setVertexColor(0u,0u,0.f,color32.g,color32.b,1.f)){
            ret=false;
        }
        if(!mesh->setVertexColor(0u,1u,0.f,color32.g,color32.b,1.f)
                ){
            ret=false;
        }
        //RIGHT
        if(!mesh->setVertexColor(0u,2u,1.f,color32.g,color32.b,1.f)
                ){
            ret=false;
        }
        if(!mesh->setVertexColor(0u,3u,1.f,color32.g,color32.b,1.f)){
            ret=false;
        }
        //G
        //LEFT
        if(!mesh->setVertexColor(1u,0u,color32.r,0.f,color32.b,1.f)){
            ret=false;
        }
        if(!mesh->setVertexColor(1u,1u,color32.r,0.f,color32.b,1.f)
                ){
            ret=false;
        }
        //RIGHT
        if(!mesh->setVertexColor(1u,2u,color32.r,1.f,color32.b,1.f)){
            ret=false;
        }
        if(!mesh->setVertexColor(1u,3u,color32.r,1.f,color32.b,1.f)
                ){
            ret=false;
        }
        //B
        //LEFT
        if(!mesh->setVertexColor(2u,0u,color32.r,color32.g,0.f,1.f)){
            ret=false;
        }
        if(!mesh->setVertexColor(2u,1u,color32.r,color32.g,0.f,1.f)
                ){
            ret=false;
        }
        //RIGHT
        if(!mesh->setVertexColor(2u,2u,color32.r,color32.g,1.f,1.f)){
            ret=false;
        }
        if(!mesh->setVertexColor(2u,3u,color32.r,color32.g,1.f,1.f)
                ){
            ret=false;
        }
        //R
        mesh = this->objController1.getMesh(0u);
        if(mesh){
            mesh->setVertexPositionX(0u,0u,(color32.r - 0.01f)-0.5f);
            mesh->setVertexPositionX(0u,1u,(color32.r + 0.01f)-0.5f);
            mesh->setVertexPositionX(1u,0u,(color32.r - 0.005f)-0.5f);
            mesh->setVertexPositionX(1u,1u,(color32.r + 0.005f)-0.5f);
        }
        //G
        mesh = this->objController2.getMesh(0u);
        if(mesh){
            mesh->setVertexPositionX(0u,0u,(color32.g - 0.01f)-0.5f);
            mesh->setVertexPositionX(0u,1u,(color32.g + 0.01f)-0.5f);
            mesh->setVertexPositionX(1u,0u,(color32.g - 0.005f)-0.5f);
            mesh->setVertexPositionX(1u,1u,(color32.g + 0.005f)-0.5f);
        }
        //B
        mesh = this->objController3.getMesh(0u);
        if(mesh){
            mesh->setVertexPositionX(0u,0u,(color32.b - 0.01f)-0.5f);
            mesh->setVertexPositionX(0u,1u,(color32.b + 0.01f)-0.5f);
            mesh->setVertexPositionX(1u,0u,(color32.b - 0.005f)-0.5f);
            mesh->setVertexPositionX(1u,1u,(color32.b + 0.005f)-0.5f);
        }
    }
    return ret;
}

bool edk::gui2d::ColorPicker2d::updateShowColor(edk::color3f32 color32){
    edk::shape::Mesh2D* mesh = this->objColorFinal.getMesh(0u);
    if(mesh){
        return mesh->setPolygonsColor(color32);
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
        this->controllingR=false;
        this->controllingG=false;
        this->controllingB=false;
        this->channelHue=360.f;
        this->channelSaturation=1.f;
        this->channelValue=1.f;
        this->channelR = 1.f;
        this->channelG = 0.f;
        this->channelB = 0.f;
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
    case edk::gui2d::colorTypeHSV:
        this->typeColor = type;
        ret=true;
        break;
    default:
        this->typeColor = edk::gui2d::colorTypeHSV;
        break;
    }
    this->createColor();
    return ret;
}

//return the color picked
edk::color3ui8 edk::gui2d::ColorPicker2d::getColorRGB8(){
    switch(this->typeColor){
    case edk::gui2d::colorTypeRGB:
        return edk::color3ui8((edk::uint8)(this->channelR*255.f),
                              (edk::uint8)(this->channelG*255.f),
                              (edk::uint8)(this->channelB*255.f)
                              );
        break;
    case edk::gui2d::colorTypeHSV:
        return edk::Image2D::hsvTorgb(this->channelHue,this->channelSaturation,this->channelValue);
        break;
    default:
        break;
    }
    return edk::color3ui8(0u,0u,0u);
}
edk::color3f32 edk::gui2d::ColorPicker2d::getColorRGB32(){
    switch(this->typeColor){
    case edk::gui2d::colorTypeRGB:
        return edk::color3f32(this->channelR,
                              this->channelG,
                              this->channelB
                              );
        break;
    case edk::gui2d::colorTypeHSV:
    {
        edk::color3ui8 color8 = this->getColorRGB8();
        return edk::color3f32((edk::float32)color8.r/255.f,
                              (edk::float32)color8.g/255.f,
                              (edk::float32)color8.b/255.f
                              );
    }
        break;
    default:
        break;
    }
    return edk::color3f32(0.f,0.f,0.f);
}

bool edk::gui2d::ColorPicker2d::setColorRGB32(edk::color3f32 color){
    bool ret=true;
    edk::color3ui8 newColor8 = edk::color3ui8((edk::uint8)(color.r*255.f),
                                              (edk::uint8)(color.g*255.f),
                                              (edk::uint8)(color.b*255.f)
                                              );
    edk::color3f32 newColor= edk::Image2D::rgbTohsv(newColor8);
    this->channelHue = newColor.r;
    this->channelSaturation = newColor.g;
    this->channelValue = newColor.b;

    switch(this->typeColor){
    case edk::gui2d::colorTypeRGB:
    {
        this->channelR=color.r;
        this->channelG=color.g;
        this->channelB=color.b;
        //update the RGB polygon
        if(!this->updatePolygonColorRGB(color)){
            ret=false;
        }
    }
        break;
    case edk::gui2d::colorTypeHSV:
    {
        //update the saturation/value polygon
        edk::color3ui8 color8 = edk::Image2D::hsvTorgb(this->channelHue,1.f,1.0);
        edk::color3f32 color32;
        this->channelR = color32.r = (edk::float32)color8.r/255.f;
        this->channelG = color32.g = (edk::float32)color8.g/255.f;
        this->channelB = color32.b = (edk::float32)color8.b/255.f;
        if(!this->updatePolygonColorValue(color32)){
            ret=false;
        }
    }
        break;
    default:
        break;
    }

    if(!this->updateShowColor(color)){
        ret=false;
    }

    //update color positions

    return ret;
}
bool edk::gui2d::ColorPicker2d::setColorRGB32(edk::float32 r,edk::float32 g,edk::float32 b){
    return this->setColorRGB32(edk::color3f32(r,g,b));
}
bool edk::gui2d::ColorPicker2d::setColorHSV32(edk::color3f32 color){
    bool ret=true;
    this->channelHue = color.r;
    this->channelSaturation = color.g;
    this->channelValue = color.b;


    //update the color in saturation and value
    switch(this->typeColor){
    case edk::gui2d::colorTypeRGB:
    {
        //update the RGB polygon
        edk::color3ui8 color8 = edk::Image2D::hsvTorgb(this->channelHue,this->channelSaturation,this->channelValue);
        edk::color3f32 color32;
        this->channelR = color32.r = (edk::float32)color8.r/255.f;
        this->channelG = color32.g = (edk::float32)color8.g/255.f;
        this->channelB = color32.b = (edk::float32)color8.b/255.f;
        if(!this->updatePolygonColorRGB(color32)){
            ret=false;
        }
    }
        break;
    case edk::gui2d::colorTypeHSV:
    {
        //update the saturation/value polygon
        edk::color3ui8 color8 = edk::Image2D::hsvTorgb(this->channelHue,this->channelSaturation,this->channelValue);
        edk::color3f32 color32;
        this->channelR = color32.r = (edk::float32)color8.r/255.f;
        this->channelG = color32.g = (edk::float32)color8.g/255.f;
        this->channelB = color32.b = (edk::float32)color8.b/255.f;
        color8 = edk::Image2D::hsvTorgb(this->channelHue,1.f,1.0);
        color32.r = (edk::float32)color8.r/255.f;
        color32.g = (edk::float32)color8.g/255.f;
        color32.b = (edk::float32)color8.b/255.f;
        if(!this->updatePolygonColorValue(color32)){
            ret=false;
        }
    }
        break;
    default:
        break;
    }

    edk::color3f32 newColor;
    newColor.r = this->channelR;
    newColor.g = this->channelG;
    newColor.b = this->channelB;

    if(!this->updateShowColor(newColor)){
        ret=false;
    }

    //update color positions

    return ret;
}
bool edk::gui2d::ColorPicker2d::setColorHSV32(edk::float32 h,edk::float32 s,edk::float32 v){
    return this->setColorHSV32(edk::color3f32(h,s,v));
}

//load the button textures and meshes
bool edk::gui2d::ColorPicker2d::load(){
    this->controllingHue=false;
    this->controllingSaturation=false;
    this->controllingR=false;
    this->controllingG=false;
    this->controllingB=false;
    this->channelHue=360.f;
    this->channelSaturation=1.f;
    this->channelValue=1.f;
    this->channelR = 1.f;
    this->channelG = 0.f;
    this->channelB = 0.f;
    if(edk::gui2d::ObjectGui2d::load()){
        this->setColorType(edk::gui2d::colorTypeHSV);
        //this->setColorType(edk::gui2d::colorTypeRGB);
        this->setColorRGB32(0.f,0.f,0.f);
        return true;
    }
    return false;
}
void edk::gui2d::ColorPicker2d::unload(){
    this->controllingHue=false;
    this->controllingSaturation=false;
    this->controllingR=false;
    this->controllingG=false;
    this->controllingB=false;
    this->channelHue=360.f;
    this->channelSaturation=1.f;
    this->channelValue=1.f;
    this->channelR = 1.f;
    this->channelG = 0.f;
    this->channelB = 0.f;
    this->objColor1.clean();
    this->objColor2.clean();
    this->objColor3.clean();
    this->objController1.clean();
    this->objController2.clean();
    this->objController3.clean();
    this->objColorFinal.clean();
    this->obj.unload();
    edk::gui2d::ObjectGui2d::unload();
}
void edk::gui2d::ColorPicker2d::update(){
    edk::gui2d::ObjectGui2d::update();
    edk::rectf32 rectInside = this->getInsideRect();
    this->objColor1.position = this->position;
    this->objColor1.size = rectInside.size;
    this->objColor2.position = this->position;
    this->objColor2.size = rectInside.size;
    this->objColor3.position = this->position;
    this->objColor3.size = rectInside.size;
    this->objController1.position = this->position;
    this->objController1.size = rectInside.size;
    this->objController2.position = this->position;
    this->objController2.size = rectInside.size;
    this->objController3.position = this->position;
    this->objController3.size = rectInside.size;
    this->objColorFinal.position = this->position;
    this->objColorFinal.size = rectInside.size;
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
    this->objColor1.drawWithoutMaterial();
    this->objColor2.drawWithoutMaterial();
    this->objColor3.drawWithoutMaterial();
    this->objController1.drawWithoutMaterial();
    this->objController2.drawWithoutMaterial();
    this->objController3.drawWithoutMaterial();
    this->objColorFinal.drawWithoutMaterial();
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
    this->controllingSaturation=false;
    this->controllingR=false;
    this->controllingG=false;
    this->controllingB=false;
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

