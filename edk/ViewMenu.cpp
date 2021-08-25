#include "ViewMenu.h"

/*
Library C++ edkViewMenu - Viewport used to show a Menu sprite in the background
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

#include "edkImages/EDKmenuTemplateTexture.h"

edk::ViewMenu::ViewMenu(){
    //
    this->borderSize = 25.f;
    this->loadSpriteFromMemory(EDKmenuTemplateTextureName,EDKmenuTemplateTexture,EDKmenuTemplateTextureSize);
}
edk::ViewMenu::~ViewMenu(){
    //
}

//set borderSize
bool edk::ViewMenu::setBorderSize(edk::uint32 size){
    if(size){
        this->borderSize = size;
        return true;
    }
    this->borderSize = 25.f;
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
void edk::ViewMenu::drawPolygon(rectf32){
    //test the rect
    if(this->rectMenuSave!=this->frame){
        this->borderTemp=this->borderSize;
        //load the rect size
        edk::size2f32 sizeTemp = edk::size2f32(this->frame.size * 0.5f);
        //save the rect
        this->rectMenuSave = this->frame;

        //set the camera rect
        this->cam.setRect(0,0,this->frame.size.width,this->frame.size.height);
        //test the smaller size
        if(sizeTemp.width < sizeTemp.height){
            //width
            if(this->borderTemp>sizeTemp.width){
                this->borderTemp = sizeTemp.width;
            }
        }
        else{
            //height
            if(this->borderTemp>sizeTemp.height){
                this->borderTemp = sizeTemp.height;
            }
        }
    }

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
    edk::GU::guVertex3f32(0.f, this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.5f);
    edk::GU::guVertex3f32(this->borderTemp, this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 1.0f);
    edk::GU::guVertex3f32(this->borderTemp, 0.f, 0.f);

    //rect2
    edk::GU::guVertexTex2f32(0.f, 0.5f);
    edk::GU::guVertex3f32(0.f, this->frame.size.height - this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.f, 0.f);
    edk::GU::guVertex3f32(0.f, this->frame.size.height, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.f);
    edk::GU::guVertex3f32(this->borderTemp, this->frame.size.height, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.5f);
    edk::GU::guVertex3f32(this->borderTemp, this->frame.size.height - this->borderTemp, 0.f);

    //rect3
    edk::GU::guVertexTex2f32(0.5f, 0.5f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderTemp, this->frame.size.height - this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderTemp, this->frame.size.height, 0.f);

    edk::GU::guVertexTex2f32(1.0f, 0.f);
    edk::GU::guVertex3f32(this->frame.size.width, this->frame.size.height, 0.f);

    edk::GU::guVertexTex2f32(1.0f, 0.5f);
    edk::GU::guVertex3f32(this->frame.size.width, this->frame.size.height - this->borderTemp, 0.f);

    //rect4
    edk::GU::guVertexTex2f32(0.5f, 1.f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderTemp, 0.f, 0.f);


    edk::GU::guVertexTex2f32(0.5f, 0.5f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderTemp, this->borderTemp, 0.f);


    edk::GU::guVertexTex2f32(1.f, 0.5f);
    edk::GU::guVertex3f32(this->frame.size.width, this->borderTemp, 0.f);


    edk::GU::guVertexTex2f32(1.f, 1.f);
    edk::GU::guVertex3f32(this->frame.size.width, 0.f, 0.f);



    //rect1
    edk::GU::guVertexTex2f32(0.f, 0.515f);
    edk::GU::guVertex3f32(0.f, this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.f, 0.515f);
    edk::GU::guVertex3f32(0.f, this->frame.size.height-this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.495f);
    edk::GU::guVertex3f32(this->borderTemp, this->frame.size.height-this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.495);
    edk::GU::guVertex3f32(this->borderTemp, this->borderTemp, 0.f);

    //rect2
    edk::GU::guVertexTex2f32(0.515f, 0.5f);
    edk::GU::guVertex3f32(this->borderTemp, this->frame.size.height - this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.515f, 0.f);
    edk::GU::guVertex3f32(this->borderTemp, this->frame.size.height, 0.f);

    edk::GU::guVertexTex2f32(0.495f, 0.f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderTemp, this->frame.size.height, 0.f);

    edk::GU::guVertexTex2f32(0.495f, 0.5f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderTemp, this->frame.size.height - this->borderTemp, 0.f);

    //rect3
    edk::GU::guVertexTex2f32(0.5f, 0.515f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderTemp, this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.515f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderTemp, this->frame.size.height - this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(1.f, 0.495f);
    edk::GU::guVertex3f32(this->frame.size.width, this->frame.size.height - this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(1.f, 0.495f);
    edk::GU::guVertex3f32(this->frame.size.width, this->borderTemp, 0.f);

    //rect4
    edk::GU::guVertexTex2f32(0.515f, 1.f);
    edk::GU::guVertex3f32(this->borderTemp, 0.f, 0.f);

    edk::GU::guVertexTex2f32(0.515f, 0.5f);
    edk::GU::guVertex3f32(this->borderTemp, this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.495f, 0.5f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderTemp, this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.495f, 1.f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderTemp, 0.f, 0.f);


    //CENTER
    edk::GU::guVertexTex2f32(0.495f, 0.515f);
    edk::GU::guVertex3f32(this->borderTemp, this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.495f, 0.495f);
    edk::GU::guVertex3f32(this->borderTemp, this->frame.size.height-this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.515f, 0.495f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderTemp, this->frame.size.height-this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.515f, 0.515f);
    edk::GU::guVertex3f32(this->frame.size.width-this->borderTemp, this->borderTemp, 0.f);


    edk::GU::guEnd();

    edk::GU::guUseTexture2D(0u);
    edk::GU::guDisable(GU_TEXTURE_2D);
}
