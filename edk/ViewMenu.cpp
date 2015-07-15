#include "ViewMenu.h"

/*
Library C++ edkViewMenu - Viewport used to show a Menu sprite in the background
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

//MENU
edk::uint32 EDKMenuTemplateTextureSize = 771u;
edk::char8 EDKMenuTemplateTextureName[27u] = "EDKmenuTemplateTexture.png";
edk::uchar8 EDKMenuTextureTemplate[771] = {
    137,80,78,71,13,10,26,10,0,0,0,13 \
    ,73,72,68,82,0,0,0,20,0,0,0 \
    ,20,8,6,0,0,0,141,137,29,13,0 \
    ,0,0,4,115,66,73,84,8,8,8,8 \
    ,124,8,100,136,0,0,0,9,112,72,89 \
    ,115,0,0,13,215,0,0,13,215,1,66 \
    ,40,155,120,0,0,0,25,116,69,88,116 \
    ,83,111,102,116,119,97,114,101,0,119,119 \
    ,119,46,105,110,107,115,99,97,112,101,46 \
    ,111,114,103,155,238,60,26,0,0,2,128 \
    ,73,68,65,84,56,141,181,149,49,75,244 \
    ,72,24,199,255,153,144,24,147,184,198,48 \
    ,141,17,228,84,196,194,54,47,150,98,229 \
    ,39,176,190,175,112,111,125,245,245,247,13 \
    ,142,171,45,175,178,89,87,172,132,192,106 \
    ,183,39,75,20,23,221,101,25,98,12,201 \
    ,24,51,76,158,43,94,86,56,239,93,110 \
    ,229,184,95,255,252,152,121,134,255,127,12 \
    ,34,194,71,78,79,79,77,206,249,177,109 \
    ,219,177,235,186,177,101,89,49,0,40,165 \
    ,18,41,101,210,52,77,34,132,56,59,57 \
    ,57,209,31,103,141,143,194,243,243,243,189 \
    ,181,181,181,223,57,231,7,65,16,192,243 \
    ,60,104,253,109,206,52,77,84,85,133,60 \
    ,207,33,132,184,122,126,126,254,241,232,232 \
    ,232,207,121,66,227,226,226,226,167,205,205 \
    ,205,95,162,40,90,174,235,26,89,150,161 \
    ,44,203,191,9,125,223,71,24,134,112,28 \
    ,7,79,79,79,175,15,15,15,63,31,30 \
    ,30,254,10,224,155,136,136,64,68,232,245 \
    ,122,95,71,163,17,41,165,40,77,83,234 \
    ,247,251,52,153,76,72,74,73,51,164,148 \
    ,52,153,76,168,223,239,83,154,166,164,148 \
    ,162,209,104,68,189,94,239,235,204,3,34 \
    ,66,183,219,221,75,211,84,42,165,104,48 \
    ,24,208,237,237,45,105,173,105,30,90,107 \
    ,26,14,135,52,24,12,102,7,144,221,110 \
    ,119,143,136,96,238,239,239,155,27,27,27 \
    ,127,108,111,111,255,240,248,248,8,34,194 \
    ,238,238,46,12,195,248,199,99,189,239,198 \
    ,48,16,134,33,138,162,64,81,20,136,162 \
    ,200,42,203,242,203,229,229,229,111,140,115 \
    ,126,204,57,63,168,235,26,47,47,47,216 \
    ,217,217,153,43,250,200,214,214,22,138,162 \
    ,64,93,215,224,156,31,112,206,143,153,109 \
    ,219,113,16,4,200,178,12,235,235,235,96 \
    ,140,45,44,52,12,3,81,20,33,203,50 \
    ,4,65,0,219,182,99,230,186,110,236,121 \
    ,30,202,178,68,167,211,89,88,54,163,211 \
    ,233,160,44,75,120,158,7,215,117,99,102 \
    ,89,86,172,181,134,214,26,203,203,203,159 \
    ,22,46,45,45,161,109,91,104,173,97,89 \
    ,86,188,248,253,22,132,41,165,18,211,52 \
    ,97,154,38,94,95,95,63,45,120,123,123 \
    ,3,99,12,166,105,66,41,149,48,41,101 \
    ,82,85,21,124,223,71,81,20,159,22,22 \
    ,69,1,223,247,81,85,21,164,148,9,107 \
    ,154,38,201,243,28,97,24,98,60,30,163 \
    ,109,219,133,101,68,132,241,120,140,48,12 \
    ,145,231,57,154,166,73,152,16,226,76,8 \
    ,113,229,56,14,86,87,87,113,119,119,183 \
    ,176,240,254,254,30,43,43,43,112,28,7 \
    ,66,136,43,33,196,217,119,163,55,28,14 \
    ,169,109,219,185,209,107,219,150,210,52,253 \
    ,110,244,230,150,195,245,245,53,77,167,83 \
    ,170,235,250,93,84,215,53,77,167,83,186 \
    ,185,185,153,91,14,11,213,215,108,175,140 \
    ,177,127,173,175,255,181,96,223,249,47,95 \
    ,192,95,84,95,59,173,45,222,233,47,0 \
    ,0,0,0,73,69,78,68,174,66,96,130 \
};

edk::ViewMenu::ViewMenu(){
    //
    this->borderSize = 50.f;
    this->loadSpriteFromMemory(EDKMenuTemplateTextureName,EDKMenuTextureTemplate,EDKMenuTemplateTextureSize);
}
//set borderSize
bool edk::ViewMenu::setBorderSize(edk::uint32 size){
    if(size){
        this->borderSize = size;
        return true;
    }
    this->borderSize = 50.f;
    return false;
}
//return the inside frame
edk::rectui32 edk::ViewMenu::getInsideFrame(){
    edk::rectui32 ret(0u,
                      0u,
                      (edk::uint32)(this->frame.size.width - this->borderSize*2.f),
                      (edk::uint32)(this->frame.size.height - this->borderSize*2.f)
                      );
    return ret;
}
//return the size inside
edk::size2ui32 edk::ViewMenu::getInsideSize(){
    return edk::size2ui32((edk::uint32)(this->frame.size.width - this->borderSize*2.f),
                          (edk::uint32)(this->frame.size.height - this->borderSize*2.f)
                          );
}

//draw
void edk::ViewMenu::draw(rectf32 outsideViewOrigin){
    //remove the border to the next view
/*
    edk::ViewSpriteController::draw(
                rectf32(outsideViewOrigin.origin.x + this->borderSize,
                        outsideViewOrigin.origin.y + this->borderSize,
                        outsideViewOrigin.size.width - this->borderSize,
                        outsideViewOrigin.size.height - this->borderSize
                        )
                );
*/
    edk::ViewSpriteController::draw(outsideViewOrigin);
}

//draw the polygon on the scene
void edk::ViewMenu::drawPolygon(rectf32 outsideViewOrigin){
    this->cam.setRect(0,0,this->frame.size.width,this->frame.size.height);
    this->cam.draw();
    //draw the polygon with UV Map
    edk::GU::guUseMatrix(GU_MODELVIEW);

    //texture
    edk::GU::guEnable(GU_TEXTURE_2D);

    edk::GU::guUseTexture2D(this->spriteCode);

    //Draw a quadrangle
    edk::GU::guBegin(GU_QUADS);

    //rect1
    edk::GU::guVertexTex2f32(0.0f, 1.0f);
    edk::GU::guVertex3f32(0.f, 0.f, 0.f);

    edk::GU::guVertexTex2f32(0.0f, 0.5f);
    edk::GU::guVertex3f32(0.f, this->borderSize, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.5f);
    edk::GU::guVertex3f32(this->borderSize, this->borderSize, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 1.0f);
    edk::GU::guVertex3f32(this->borderSize, 0.f, 0.f);

    //rect2
    edk::GU::guVertexTex2f32(0.f, 0.5f);
    edk::GU::guVertex3f32(0.f, this->frame.size.height - this->borderSize, 0.f);

    edk::GU::guVertexTex2f32(0.f, 0.f);
    edk::GU::guVertex3f32(0.f, this->frame.size.height, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.f);
    edk::GU::guVertex3f32(this->borderSize, this->frame.size.height, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.5f);
    edk::GU::guVertex3f32(this->borderSize, this->frame.size.height - this->borderSize, 0.f);

    //rect3
    edk::GU::guVertexTex2f32(0.5f, 0.5f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderSize, this->frame.size.height - this->borderSize, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderSize, this->frame.size.height, 0.f);

    edk::GU::guVertexTex2f32(1.0f, 0.f);
    edk::GU::guVertex3f32(this->frame.size.width, this->frame.size.height, 0.f);

    edk::GU::guVertexTex2f32(1.0f, 0.5f);
    edk::GU::guVertex3f32(this->frame.size.width, this->frame.size.height - this->borderSize, 0.f);

    //rect4
    edk::GU::guVertexTex2f32(0.5f, 1.f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderSize, 0.f, 0.f);


    edk::GU::guVertexTex2f32(0.5f, 0.5f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderSize, this->borderSize, 0.f);


    edk::GU::guVertexTex2f32(1.f, 0.5f);
    edk::GU::guVertex3f32(this->frame.size.width, this->borderSize, 0.f);


    edk::GU::guVertexTex2f32(1.f, 1.f);
    edk::GU::guVertex3f32(this->frame.size.width, 0.f, 0.f);



    //rect1
    edk::GU::guColor3f32(1,1,1);
    edk::GU::guVertexTex2f32(0.f, 0.515f);
    edk::GU::guVertex3f32(0.f, this->borderSize, 0.f);

    edk::GU::guColor3f32(1,1,1);
    edk::GU::guVertexTex2f32(0.f, 0.515f);
    edk::GU::guVertex3f32(0.f, this->frame.size.height-this->borderSize, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.495f);
    edk::GU::guVertex3f32(this->borderSize, this->frame.size.height-this->borderSize, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.495);
    edk::GU::guVertex3f32(this->borderSize, this->borderSize, 0.f);

    //rect2
    edk::GU::guVertexTex2f32(0.515f, 0.5f);
    edk::GU::guVertex3f32(this->borderSize, this->frame.size.height - this->borderSize, 0.f);

    edk::GU::guVertexTex2f32(0.515f, 0.f);
    edk::GU::guVertex3f32(this->borderSize, this->frame.size.height, 0.f);

    edk::GU::guVertexTex2f32(0.495f, 0.f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderSize, this->frame.size.height, 0.f);

    edk::GU::guVertexTex2f32(0.495f, 0.5f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderSize, this->frame.size.height - this->borderSize, 0.f);

    //rect3
    edk::GU::guVertexTex2f32(0.5f, 0.515f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderSize, this->borderSize, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.515f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderSize, this->frame.size.height - this->borderSize, 0.f);

    edk::GU::guVertexTex2f32(1.f, 0.495f);
    edk::GU::guVertex3f32(this->frame.size.width, this->frame.size.height - this->borderSize, 0.f);

    edk::GU::guVertexTex2f32(1.f, 0.495f);
    edk::GU::guVertex3f32(this->frame.size.width, this->borderSize, 0.f);

    //rect4
    edk::GU::guVertexTex2f32(0.515f, 1.f);
    edk::GU::guVertex3f32(this->borderSize, 0.f, 0.f);

    edk::GU::guVertexTex2f32(0.515f, 0.5f);
    edk::GU::guVertex3f32(this->borderSize, this->borderSize, 0.f);

    edk::GU::guVertexTex2f32(0.495f, 0.5f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderSize, this->borderSize, 0.f);

    edk::GU::guVertexTex2f32(0.495f, 1.f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderSize, 0.f, 0.f);


    //CENTER
    edk::GU::guVertexTex2f32(0.495f, 0.515f);
    edk::GU::guVertex3f32(this->borderSize, this->borderSize, 0.f);

    edk::GU::guVertexTex2f32(0.495f, 0.495f);
    edk::GU::guVertex3f32(this->borderSize, this->frame.size.height-this->borderSize, 0.f);

    edk::GU::guVertexTex2f32(0.515f, 0.495f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderSize, this->frame.size.height-this->borderSize, 0.f);

    edk::GU::guVertexTex2f32(0.515f, 0.515f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderSize, this->borderSize, 0.f);


    edk::GU::guEnd();

    edk::GU::guUseTexture2D(0u);
    edk::GU::guDisable(GU_TEXTURE_2D);
}
