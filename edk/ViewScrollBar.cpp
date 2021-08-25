#include "ViewScrollBar.h"

/*
Library C++ ViewScrollBar - Show a scroolBar in the screen
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
#warning "            Inside ViewScrollBar.cpp"
#endif

#include "edkImages/EDKmenuTemplateTexture.h"

edk::ViewScrollBar::ViewScrollBar()
{
    this->backgroundColor.a = 0.f;
}
edk::ViewScrollBar::~ViewScrollBar()
{
}
void edk::ViewScrollBar::updateFrames(){
    //test the rectScroll
    if(this->rectScrollSave!=this->frame){
        this->rectScrollSave = this->frame;
        //save the percent
        edk::vec2f32 percent = this->foreground.getPercent();
        //update the button
        this->background.frame.size = this->rectScrollSave.size;
        this->foreground.frame.size = this->rectScrollSave.size;
        this->foreground.updateFrame();
        //update the percent
        this->foreground.setPercent(percent);
    }
}

edk::ViewScrollBar::ForegroundButton::ForegroundButton(){
    //
    this->sizeObject = edk::size2f32(1,1);
    this->borderSize = 25;
    this->loadSpriteFromMemory(EDKmenuTemplateTextureName,EDKmenuTemplateTexture,EDKmenuTemplateTextureSize,GU_LINEAR);
    this->mouseHolded=false;
}
//set size
edk::ViewScrollBar::ForegroundButton::~ForegroundButton(){
    //
}

void edk::ViewScrollBar::ForegroundButton::load(rectf32){
    //
}
void edk::ViewScrollBar::ForegroundButton::unload(){
    //
}
void edk::ViewScrollBar::ForegroundButton::update(edk::WindowEvents* events){
    //test the mouse
    if(this->mouseHolded){
        //calculate the distance between the mouse
        edk::vec2f32 distance = edk::vec2f32(events->mousePosWorld.x -this->saveMousePos.x,
                                             events->mousePosWorld.y -this->saveMousePos.y
                                             );
        this->setPosition(edk::vec2f32(distance.x+this->saveObjectPosition.x,(distance.y*-1)+this->saveObjectPosition.y));
    }
    else{
        this->saveMousePos = edk::vec2f32(events->mousePosWorld.x,events->mousePosWorld.y);
        this->saveObjectPosition = this->polygonRect.origin;
    }

    //update the color
    if(this->backgroundColor.a){
        this->backgroundColor.a = 0.f;
    }
}
void edk::ViewScrollBar::ForegroundButton::updateFrame(){

    this->borderTemp=this->borderSize;

    this->polygonRect.size = this->frame.size * this->sizeObject;

    //load the rect size
    edk::size2f32 sizeTemp = edk::size2f32(this->polygonRect.size * 0.5f);

    //set the camera rect
    this->camera.setRect(0,0,this->frame.size.width,this->frame.size.height);
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

//Events
void edk::ViewScrollBar::ForegroundButton::eventMousePressed(edk::vec2f32 point,edk::uint32 button){
    if(button == edk::mouse::left){
        //
        point.y = (point.y*-1.f)+this->frame.size.height;
        if(point.x > this->polygonRect.origin.x
                &&
                point.y > this->polygonRect.origin.y
                &&
                point.x < this->polygonRect.origin.x+this->polygonRect.size.width
                &&
                point.y < this->polygonRect.origin.y+this->polygonRect.size.height
                )
            this->mouseHolded=true;
        else{
            if(point.x>this->polygonRect.origin.x + this->polygonRect.size.width){
                if(point.y>this->polygonRect.origin.y + this->polygonRect.size.height){
                    //go + +
                    this->setPosition(edk::vec2f32(this->polygonRect.origin.x + this->polygonRect.size.width,
                                                   this->polygonRect.origin.y + this->polygonRect.size.height
                                                   ));
                }
                else if(point.y<this->polygonRect.origin.y){
                    //go + -
                    this->setPosition(edk::vec2f32(this->polygonRect.origin.x + this->polygonRect.size.width,
                                                   this->polygonRect.origin.y - this->polygonRect.size.height
                                                   ));
                }
                else{
                    //go + (0)
                    this->setPositionX(this->polygonRect.origin.x + this->polygonRect.size.width);
                }
            }
            else if(point.x<this->polygonRect.origin.x){
                if(point.y>this->polygonRect.origin.y + this->polygonRect.size.height){
                    //go - +
                    this->setPosition(edk::vec2f32(this->polygonRect.origin.x - this->polygonRect.size.width,
                                                   this->polygonRect.origin.y + this->polygonRect.size.height
                                                   ));
                }
                else if(point.y<this->polygonRect.origin.y){
                    //go - -
                    this->setPosition(edk::vec2f32(this->polygonRect.origin.x - this->polygonRect.size.width,
                                                   this->polygonRect.origin.y - this->polygonRect.size.height
                                                   ));
                }
                else{
                    //go - (0)
                    this->setPositionX(this->polygonRect.origin.x - this->polygonRect.size.width);
                }
            }
            else{
                if(point.y>this->polygonRect.origin.y + this->polygonRect.size.height){
                    //go (0) +
                    this->setPositionY(this->polygonRect.origin.y + this->polygonRect.size.height);
                }
                else if(point.y<this->polygonRect.origin.y){
                    //go (0) -
                    this->setPositionY(this->polygonRect.origin.y - this->polygonRect.size.height);
                }
            }
        }
    }
}
void edk::ViewScrollBar::ForegroundButton::eventMouseReleased(edk::vec2f32 ,edk::uint32 button){
    if(button == edk::mouse::left){
        //
        this->mouseHolded=false;
    }
}

//draw the GU scene
void edk::ViewScrollBar::ForegroundButton::drawScene(rectf32){
    edk::GU::guColor4f32(colorObject);
    //draw the polygon with UV Map
    edk::GU::guUseMatrix(GU_MODELVIEW);

    //texture
    edk::GU::guEnable(GU_TEXTURE_2D);

    edk::GU::guUseTexture2D(this->spriteCode);

    edk::GU::guTranslate2f32(this->polygonRect.origin);

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
    edk::GU::guVertex3f32(0.f, this->polygonRect.size.height - this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.f, 0.f);
    edk::GU::guVertex3f32(0.f, this->polygonRect.size.height, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.f);
    edk::GU::guVertex3f32(this->borderTemp, this->polygonRect.size.height, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.5f);
    edk::GU::guVertex3f32(this->borderTemp, this->polygonRect.size.height - this->borderTemp, 0.f);

    //rect3
    edk::GU::guVertexTex2f32(0.5f, 0.5f);
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->polygonRect.size.height - this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.f);
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->polygonRect.size.height, 0.f);

    edk::GU::guVertexTex2f32(1.0f, 0.f);
    edk::GU::guVertex3f32(this->polygonRect.size.width, this->polygonRect.size.height, 0.f);

    edk::GU::guVertexTex2f32(1.0f, 0.5f);
    edk::GU::guVertex3f32(this->polygonRect.size.width, this->polygonRect.size.height - this->borderTemp, 0.f);

    //rect4
    edk::GU::guVertexTex2f32(0.5f, 1.f);
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, 0.f, 0.f);


    edk::GU::guVertexTex2f32(0.5f, 0.5f);
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->borderTemp, 0.f);


    edk::GU::guVertexTex2f32(1.f, 0.5f);
    edk::GU::guVertex3f32(this->polygonRect.size.width, this->borderTemp, 0.f);


    edk::GU::guVertexTex2f32(1.f, 1.f);
    edk::GU::guVertex3f32(this->polygonRect.size.width, 0.f, 0.f);



    //rect1
    edk::GU::guVertexTex2f32(0.f, 0.515f);
    edk::GU::guVertex3f32(0.f, this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.f, 0.515f);
    edk::GU::guVertex3f32(0.f, this->polygonRect.size.height-this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.495f);
    edk::GU::guVertex3f32(this->borderTemp, this->polygonRect.size.height-this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.495);
    edk::GU::guVertex3f32(this->borderTemp, this->borderTemp, 0.f);

    //rect2
    edk::GU::guVertexTex2f32(0.515f, 0.5f);
    edk::GU::guVertex3f32(this->borderTemp, this->polygonRect.size.height - this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.515f, 0.f);
    edk::GU::guVertex3f32(this->borderTemp, this->polygonRect.size.height, 0.f);

    edk::GU::guVertexTex2f32(0.495f, 0.f);
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->polygonRect.size.height, 0.f);

    edk::GU::guVertexTex2f32(0.495f, 0.5f);
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->polygonRect.size.height - this->borderTemp, 0.f);

    //rect3
    edk::GU::guVertexTex2f32(0.5f, 0.515f);
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.5f, 0.515f);
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->polygonRect.size.height - this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(1.f, 0.495f);
    edk::GU::guVertex3f32(this->polygonRect.size.width, this->polygonRect.size.height - this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(1.f, 0.495f);
    edk::GU::guVertex3f32(this->polygonRect.size.width, this->borderTemp, 0.f);

    //rect4
    edk::GU::guVertexTex2f32(0.515f, 1.f);
    edk::GU::guVertex3f32(this->borderTemp, 0.f, 0.f);

    edk::GU::guVertexTex2f32(0.515f, 0.5f);
    edk::GU::guVertex3f32(this->borderTemp, this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.495f, 0.5f);
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.495f, 1.f);
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, 0.f, 0.f);


    //CENTER
    edk::GU::guVertexTex2f32(0.495f, 0.515f);
    edk::GU::guVertex3f32(this->borderTemp, this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.495f, 0.495f);
    edk::GU::guVertex3f32(this->borderTemp, this->polygonRect.size.height-this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.515f, 0.495f);
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->polygonRect.size.height-this->borderTemp, 0.f);

    edk::GU::guVertexTex2f32(0.515f, 0.515f);
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->borderTemp, 0.f);

    edk::GU::guEnd();

    edk::GU::guUseTexture2D(0u);
    edk::GU::guDisable(GU_TEXTURE_2D);
}

//set the borderSize
bool edk::ViewScrollBar::ForegroundButton::setBorderSize(edk::float32 size){
    if(size){
        this->borderSize = size;
        return true;
    }
    this->borderSize = 25.f;
    return false;
}
//set color
void edk::ViewScrollBar::ForegroundButton::setColor(edk::color4f32 color){
    this->colorObject = color;
}
//set the size
bool edk::ViewScrollBar::ForegroundButton::setSize(edk::size2f32 size){
    //
    if(size.width>0.f && size.height>0.f
            &&
            size.width<=1.f && size.height<=1.f
            ){
        //set the size
        this->sizeObject = size;
        this->polygonRect.size = this->frame.size * this->sizeObject;
        //set the percent
        this->setPercent(this->getPercent());
        return true;
    }
    return false;
}
//set position
void edk::ViewScrollBar::ForegroundButton::setPositionX(edk::float32 x){
    //X
    //test if minus zero
    if(x<0.f){
        //position receive zero
        this->polygonRect.origin.x = 0.f;
    }
    //test if is bigger than the size
    else if(x > this->frame.size.width - this->polygonRect.size.width){
        //then the position receive the limit
        this->polygonRect.origin.x = this->frame.size.width - this->polygonRect.size.width;
    }
    else{
        //else just set the position
        this->polygonRect.origin.x = x;
    }
}
void edk::ViewScrollBar::ForegroundButton::setPositionY(edk::float32 y){
    //Y
    //test if minus zero
    if(y<0.f){
        //position receive zero
        this->polygonRect.origin.y = 0.f;
    }
    //test if is bigger than the size
    else if(y > this->frame.size.height - this->polygonRect.size.height){
        //then the position receive the limit
        this->polygonRect.origin.y = this->frame.size.height - this->polygonRect.size.height;
    }
    else{
        //else just set the position
        this->polygonRect.origin.y = y;
    }
}

void edk::ViewScrollBar::ForegroundButton::setPosition(edk::vec2f32 position){
    this->setPositionX(position.x);
    this->setPositionY(position.y);
}

//Set the percent
void edk::ViewScrollBar::ForegroundButton::setPercent(edk::vec2f32 percent){
    this->setPercent(percent.x,percent.y);
}
void edk::ViewScrollBar::ForegroundButton::setPercent(edk::float32 x,edk::float32 y){
    //invert the y
    y=(y*-1.f)+1.f;
    this->setPositionX((this->frame.size.width - (this->sizeObject.width*this->frame.size.width))*x);
    this->setPositionY((this->frame.size.height - (this->sizeObject.height*this->frame.size.height))*y);
}
void edk::ViewScrollBar::ForegroundButton::setPercentX(edk::float32 x){
    //set the y position
    this->setPositionX((this->frame.size.width - this->polygonRect.size.width)*x);
}
void edk::ViewScrollBar::ForegroundButton::setPercentY(edk::float32 y){
    //invert the y
    y=(y*-1.f)+1.f;
    //set the y position
    this->setPositionY((this->frame.size.height - this->polygonRect.size.height)*y);
}

//return the percent
edk::float32 edk::ViewScrollBar::ForegroundButton::getPercentX(){
    //test the polygon position
    edk::float32 div = (this->frame.size.width - this->polygonRect.size.width);
    if(div)
        return this->polygonRect.origin.x / div;
    return div;
}
edk::float32 edk::ViewScrollBar::ForegroundButton::getPercentY(){
    edk::float32 div = (this->frame.size.height - this->polygonRect.size.height);
    if(div)
        return ((this->polygonRect.origin.y / div)*-1.f)+1.f;
    return div;
}
edk::vec2f32 edk::ViewScrollBar::ForegroundButton::getPercent(){
    return edk::vec2f32(this->getPercentX(),this->getPercentY());
}
//return if the mouse is holded
bool edk::ViewScrollBar::ForegroundButton::isMouseHolded(){
    return this->mouseHolded;
}

void edk::ViewScrollBar::load(rectf32){
    //
    this->rectScrollSave = edk::rectf32(0,0,0,0);
    //add the button
    edk::ViewController::addSubview(&this->background);
    edk::ViewController::addSubview(&this->foreground);
}
void edk::ViewScrollBar::unload(){
    edk::ViewController::removeSubview(&this->background);
    edk::ViewController::removeSubview(&this->foreground);
}
void edk::ViewScrollBar::update(edk::WindowEvents*){
    this->updateFrames();
    //update color
    if(this->backgroundColor.a){
        //copy the backgroundColor to the button
        this->background.backgroundColor = this->backgroundColor;
        //clean the backgroundColor
        this->backgroundColor.a = 0.f;
    }
}
bool edk::ViewScrollBar::addSubview(edk::View *){return false;}

//set the border
void edk::ViewScrollBar::setBorderSize(edk::uint32 size){
    this->background.setBorderSize(size);
    this->foreground.setBorderSize(size);
}

//set the size
void edk::ViewScrollBar::setForegroundSize(edk::size2f32 size){
    this->updateFrames();
    this->foreground.setSize(size);
}
void edk::ViewScrollBar::setForegroundSize(edk::float32 width,edk::float32 height){
    this->updateFrames();
    this->setForegroundSize(edk::size2f32(width,height));
}
//Set the percent
void edk::ViewScrollBar::setPercent(edk::vec2f32 percent){
    this->updateFrames();
    this->foreground.setPercent(percent);
}
void edk::ViewScrollBar::setPercent(edk::float32 x,edk::float32 y){
    this->updateFrames();
    this->foreground.setPercent(x,y);
}
void edk::ViewScrollBar::setPercentX(edk::float32 x){
    this->updateFrames();
    this->foreground.setPercentX(x);
}
void edk::ViewScrollBar::setPercentY(edk::float32 y){
    this->updateFrames();
    this->foreground.setPercentY(y);
}

//set the color
void edk::ViewScrollBar::setBackColor(edk::color3f32 color){
    this->setBackColor(edk::color4f32(color.r,color.g,color.b,1.f));
}
void edk::ViewScrollBar::setBackColor(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setBackColor(edk::color4f32(r,g,b,1.f));
}
void edk::ViewScrollBar::setBackColor(edk::color4f32 color){
    //this->backgroundColor = edk::color4f32(0,0,0,0);
    this->background.backgroundColor = color;
}
void edk::ViewScrollBar::setBackColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setBackColor(edk::color4f32(r,g,b,a));
}
void edk::ViewScrollBar::setFrontColor(edk::color3f32 color){
    this->setFrontColor(edk::color4f32(color.r,color.g,color.b,1.f));
}
void edk::ViewScrollBar::setFrontColor(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setFrontColor(edk::color4f32(r,g,b,1.f));
}
void edk::ViewScrollBar::setFrontColor(edk::color4f32 color){
    this->foreground.setColor(color);
}
void edk::ViewScrollBar::setFrontColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setFrontColor(edk::color4f32(r,g,b,a));
}

//return the percent
edk::float32 edk::ViewScrollBar::getPercentX(){
    return this->foreground.getPercentX();
}
edk::float32 edk::ViewScrollBar::getPercentY(){
    return this->foreground.getPercentY();
}
edk::vec2f32 edk::ViewScrollBar::getPercent(){
    return this->foreground.getPercent();
}
//return true if the scroll is selected
bool edk::ViewScrollBar::isSelected(){
    return this->foreground.isMouseHolded();
}

//get the scrollColor
edk::color4f32 edk::ViewScrollBar::getBackColor(){
    return this->background.backgroundColor;
}
edk::color4f32 edk::ViewScrollBar::getFrontColor(){
    return this->foreground.backgroundColor;
}

//return true if the mouse is inside
bool edk::ViewScrollBar::isMouseInside(){
    return this->foreground.isMouseInside() || this->background.isMouseInside();
}
