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
#pragma message "            Inside ViewScrollBar.cpp"
#endif

#include "edkImages/EDKmenuTemplateTexture.h"

edk::ViewScrollBar::ViewScrollBar(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::ViewScrollBar::~ViewScrollBar(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::ViewScrollBar::Constructor(bool runFather){
    if(runFather){
        edk::ViewController::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;

        this->background.Constructor();edkEnd();
        this->foreground.Constructor();edkEnd();

        this->backgroundColor.a = 0.f;edkEnd();
    }
}

void edk::ViewScrollBar::updateFrames(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::ViewScrollBar::ForegroundButton::ForegroundButton(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

//set size
edk::ViewScrollBar::ForegroundButton::~ForegroundButton(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::ViewScrollBar::ForegroundButton::Constructor(bool runFather){
    if(runFather){
        edk::ViewGU2D::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;
        this->sizeObject = edk::size2f32(1,1);edkEnd();
        this->borderSize = 25;edkEnd();
        this->loadSpriteFromMemory(EDKmenuTemplateTextureName,EDKmenuTemplateTexture,EDKmenuTemplateTextureSize,GU_LINEAR);edkEnd();
        this->mouseHolded=false;edkEnd();
    }
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
                                             );edkEnd();
        this->setPosition(edk::vec2f32(distance.x+this->saveObjectPosition.x,(distance.y*-1)+this->saveObjectPosition.y));edkEnd();
    }
    else{
        this->saveMousePos = edk::vec2f32(events->mousePosWorld.x,events->mousePosWorld.y);edkEnd();
        this->saveObjectPosition = this->polygonRect.origin;edkEnd();
    }

    //update the color
    if(this->backgroundColor.a){
        this->backgroundColor.a = 0.f;edkEnd();
    }
}
void edk::ViewScrollBar::ForegroundButton::updateFrame(){

    this->borderTemp=this->borderSize;edkEnd();

    this->polygonRect.size = this->frame.size * this->sizeObject;edkEnd();

    //load the rect size
    edk::size2f32 sizeTemp = edk::size2f32(this->polygonRect.size * 0.5f);edkEnd();

    //set the camera rect
    this->camera.setRect(0,0,this->frame.size.width,this->frame.size.height);edkEnd();
    //test the smaller size
    if(sizeTemp.width < sizeTemp.height){
        //width
        if(this->borderTemp>sizeTemp.width){
            this->borderTemp = sizeTemp.width;edkEnd();
        }
    }
    else{
        //height
        if(this->borderTemp>sizeTemp.height){
            this->borderTemp = sizeTemp.height;edkEnd();
        }
    }
}

//Events
void edk::ViewScrollBar::ForegroundButton::eventMousePressed(edk::vec2f32 point,edk::uint32 button){
    if(button == edk::mouse::left){
        //
        point.y = (point.y*-1.f)+this->frame.size.height;edkEnd();
        if(point.x > this->polygonRect.origin.x
                &&
                point.y > this->polygonRect.origin.y
                &&
                point.x < this->polygonRect.origin.x+this->polygonRect.size.width
                &&
                point.y < this->polygonRect.origin.y+this->polygonRect.size.height
                ){
            this->mouseHolded=true;edkEnd();
        }
        else{
            if(point.x>this->polygonRect.origin.x + this->polygonRect.size.width){
                if(point.y>this->polygonRect.origin.y + this->polygonRect.size.height){
                    //go + +
                    this->setPosition(edk::vec2f32(this->polygonRect.origin.x + this->polygonRect.size.width,
                                                   this->polygonRect.origin.y + this->polygonRect.size.height
                                                   ));edkEnd();
                }
                else if(point.y<this->polygonRect.origin.y){
                    //go + -
                    this->setPosition(edk::vec2f32(this->polygonRect.origin.x + this->polygonRect.size.width,
                                                   this->polygonRect.origin.y - this->polygonRect.size.height
                                                   ));edkEnd();
                }
                else{
                    //go + (0)
                    this->setPositionX(this->polygonRect.origin.x + this->polygonRect.size.width);edkEnd();
                }
            }
            else if(point.x<this->polygonRect.origin.x){
                if(point.y>this->polygonRect.origin.y + this->polygonRect.size.height){
                    //go - +
                    this->setPosition(edk::vec2f32(this->polygonRect.origin.x - this->polygonRect.size.width,
                                                   this->polygonRect.origin.y + this->polygonRect.size.height
                                                   ));edkEnd();
                }
                else if(point.y<this->polygonRect.origin.y){
                    //go - -
                    this->setPosition(edk::vec2f32(this->polygonRect.origin.x - this->polygonRect.size.width,
                                                   this->polygonRect.origin.y - this->polygonRect.size.height
                                                   ));edkEnd();
                }
                else{
                    //go - (0)
                    this->setPositionX(this->polygonRect.origin.x - this->polygonRect.size.width);edkEnd();
                }
            }
            else{
                if(point.y>this->polygonRect.origin.y + this->polygonRect.size.height){
                    //go (0) +
                    this->setPositionY(this->polygonRect.origin.y + this->polygonRect.size.height);edkEnd();
                }
                else if(point.y<this->polygonRect.origin.y){
                    //go (0) -
                    this->setPositionY(this->polygonRect.origin.y - this->polygonRect.size.height);edkEnd();
                }
            }
        }
    }
}
void edk::ViewScrollBar::ForegroundButton::eventMouseReleased(edk::vec2f32 ,edk::uint32 button){
    if(button == edk::mouse::left){
        //
        this->mouseHolded=false;edkEnd();
    }
}

//draw the GU scene
void edk::ViewScrollBar::ForegroundButton::drawScene(rectf32){
    edk::GU::guColor4f32(colorObject);edkEnd();
    //draw the polygon with UV Map
    edk::GU::guUseMatrix(GU_MODELVIEW);edkEnd();

    //texture
    edk::GU::guEnable(GU_TEXTURE_2D);edkEnd();

    edk::GU::guUseTexture2D(this->spriteCode);edkEnd();

    edk::GU::guTranslate2f32(this->polygonRect.origin);edkEnd();

    //Draw a quadrangle
    edk::GU::guBegin(GU_QUADS);edkEnd();


    //rect1
    edk::GU::guVertexTex2f32(0.0f, 1.0f);edkEnd();
    edk::GU::guVertex3f32(0.f, 0.f, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.0f, 0.5f);edkEnd();
    edk::GU::guVertex3f32(0.f, this->borderTemp, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.5f, 0.5f);edkEnd();
    edk::GU::guVertex3f32(this->borderTemp, this->borderTemp, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.5f, 1.0f);edkEnd();
    edk::GU::guVertex3f32(this->borderTemp, 0.f, 0.f);edkEnd();

    //rect2
    edk::GU::guVertexTex2f32(0.f, 0.5f);edkEnd();
    edk::GU::guVertex3f32(0.f, this->polygonRect.size.height - this->borderTemp, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.f, 0.f);edkEnd();
    edk::GU::guVertex3f32(0.f, this->polygonRect.size.height, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.5f, 0.f);edkEnd();
    edk::GU::guVertex3f32(this->borderTemp, this->polygonRect.size.height, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.5f, 0.5f);edkEnd();
    edk::GU::guVertex3f32(this->borderTemp, this->polygonRect.size.height - this->borderTemp, 0.f);edkEnd();

    //rect3
    edk::GU::guVertexTex2f32(0.5f, 0.5f);edkEnd();
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->polygonRect.size.height - this->borderTemp, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.5f, 0.f);edkEnd();
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->polygonRect.size.height, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(1.0f, 0.f);edkEnd();
    edk::GU::guVertex3f32(this->polygonRect.size.width, this->polygonRect.size.height, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(1.0f, 0.5f);edkEnd();
    edk::GU::guVertex3f32(this->polygonRect.size.width, this->polygonRect.size.height - this->borderTemp, 0.f);edkEnd();

    //rect4
    edk::GU::guVertexTex2f32(0.5f, 1.f);edkEnd();
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, 0.f, 0.f);edkEnd();


    edk::GU::guVertexTex2f32(0.5f, 0.5f);edkEnd();
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->borderTemp, 0.f);edkEnd();


    edk::GU::guVertexTex2f32(1.f, 0.5f);edkEnd();
    edk::GU::guVertex3f32(this->polygonRect.size.width, this->borderTemp, 0.f);edkEnd();


    edk::GU::guVertexTex2f32(1.f, 1.f);edkEnd();
    edk::GU::guVertex3f32(this->polygonRect.size.width, 0.f, 0.f);edkEnd();



    //rect1
    edk::GU::guVertexTex2f32(0.f, 0.515f);edkEnd();
    edk::GU::guVertex3f32(0.f, this->borderTemp, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.f, 0.515f);edkEnd();
    edk::GU::guVertex3f32(0.f, this->polygonRect.size.height-this->borderTemp, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.5f, 0.495f);edkEnd();
    edk::GU::guVertex3f32(this->borderTemp, this->polygonRect.size.height-this->borderTemp, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.5f, 0.495);edkEnd();
    edk::GU::guVertex3f32(this->borderTemp, this->borderTemp, 0.f);edkEnd();

    //rect2
    edk::GU::guVertexTex2f32(0.515f, 0.5f);edkEnd();
    edk::GU::guVertex3f32(this->borderTemp, this->polygonRect.size.height - this->borderTemp, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.515f, 0.f);edkEnd();
    edk::GU::guVertex3f32(this->borderTemp, this->polygonRect.size.height, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.495f, 0.f);edkEnd();
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->polygonRect.size.height, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.495f, 0.5f);edkEnd();
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->polygonRect.size.height - this->borderTemp, 0.f);edkEnd();

    //rect3
    edk::GU::guVertexTex2f32(0.5f, 0.515f);edkEnd();
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->borderTemp, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.5f, 0.515f);edkEnd();
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->polygonRect.size.height - this->borderTemp, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(1.f, 0.495f);edkEnd();
    edk::GU::guVertex3f32(this->polygonRect.size.width, this->polygonRect.size.height - this->borderTemp, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(1.f, 0.495f);edkEnd();
    edk::GU::guVertex3f32(this->polygonRect.size.width, this->borderTemp, 0.f);edkEnd();

    //rect4
    edk::GU::guVertexTex2f32(0.515f, 1.f);edkEnd();
    edk::GU::guVertex3f32(this->borderTemp, 0.f, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.515f, 0.5f);edkEnd();
    edk::GU::guVertex3f32(this->borderTemp, this->borderTemp, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.495f, 0.5f);edkEnd();
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->borderTemp, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.495f, 1.f);edkEnd();
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, 0.f, 0.f);edkEnd();


    //CENTER
    edk::GU::guVertexTex2f32(0.495f, 0.515f);edkEnd();
    edk::GU::guVertex3f32(this->borderTemp, this->borderTemp, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.495f, 0.495f);edkEnd();
    edk::GU::guVertex3f32(this->borderTemp, this->polygonRect.size.height-this->borderTemp, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.515f, 0.495f);edkEnd();
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->polygonRect.size.height-this->borderTemp, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.515f, 0.515f);edkEnd();
    edk::GU::guVertex3f32(this->polygonRect.size.width-this->borderTemp, this->borderTemp, 0.f);edkEnd();

    edk::GU::guEnd();edkEnd();

    edk::GU::guUseTexture2D(0u);edkEnd();
    edk::GU::guDisable(GU_TEXTURE_2D);edkEnd();
}

//set the borderSize
bool edk::ViewScrollBar::ForegroundButton::setBorderSize(edk::float32 size){
    if(size){
        this->borderSize = size;edkEnd();
        return true;
    }
    this->borderSize = 25.f;edkEnd();
    return false;
}
//set color
void edk::ViewScrollBar::ForegroundButton::setColor(edk::color4f32 color){
    this->colorObject = color;edkEnd();
}
//set the size
bool edk::ViewScrollBar::ForegroundButton::setSize(edk::size2f32 size){
    //
    if(size.width>0.f && size.height>0.f
            &&
            size.width<=1.f && size.height<=1.f
            ){
        //set the size
        this->sizeObject = size;edkEnd();
        this->polygonRect.size = this->frame.size * this->sizeObject;edkEnd();
        //set the percent
        this->setPercent(this->getPercent());edkEnd();
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
        this->polygonRect.origin.x = 0.f;edkEnd();
    }
    //test if is bigger than the size
    else if(x > this->frame.size.width - this->polygonRect.size.width){
        //then the position receive the limit
        this->polygonRect.origin.x = this->frame.size.width - this->polygonRect.size.width;edkEnd();
    }
    else{
        //else just set the position
        this->polygonRect.origin.x = x;edkEnd();
    }
}
void edk::ViewScrollBar::ForegroundButton::setPositionY(edk::float32 y){
    //Y
    //test if minus zero
    if(y<0.f){
        //position receive zero
        this->polygonRect.origin.y = 0.f;edkEnd();
    }
    //test if is bigger than the size
    else if(y > this->frame.size.height - this->polygonRect.size.height){
        //then the position receive the limit
        this->polygonRect.origin.y = this->frame.size.height - this->polygonRect.size.height;edkEnd();
    }
    else{
        //else just set the position
        this->polygonRect.origin.y = y;edkEnd();
    }
}

void edk::ViewScrollBar::ForegroundButton::setPosition(edk::vec2f32 position){
    this->setPositionX(position.x);edkEnd();
    this->setPositionY(position.y);edkEnd();
}

//Set the percent
void edk::ViewScrollBar::ForegroundButton::setPercent(edk::vec2f32 percent){
    this->setPercent(percent.x,percent.y);edkEnd();
}
void edk::ViewScrollBar::ForegroundButton::setPercent(edk::float32 x,edk::float32 y){
    //invert the y
    y=(y*-1.f)+1.f;edkEnd();
    this->setPositionX((this->frame.size.width - (this->sizeObject.width*this->frame.size.width))*x);edkEnd();
    this->setPositionY((this->frame.size.height - (this->sizeObject.height*this->frame.size.height))*y);edkEnd();
}
void edk::ViewScrollBar::ForegroundButton::setPercentX(edk::float32 x){
    //set the y position
    this->setPositionX((this->frame.size.width - this->polygonRect.size.width)*x);edkEnd();
}
void edk::ViewScrollBar::ForegroundButton::setPercentY(edk::float32 y){
    //invert the y
    y=(y*-1.f)+1.f;edkEnd();
    //set the y position
    this->setPositionY((this->frame.size.height - this->polygonRect.size.height)*y);edkEnd();
}

//return the percent
edk::float32 edk::ViewScrollBar::ForegroundButton::getPercentX(){
    //test the polygon position
    edk::float32 div = (this->frame.size.width - this->polygonRect.size.width);edkEnd();
    if(div){
        return this->polygonRect.origin.x / div;edkEnd();
    }
    return div;edkEnd();
}
edk::float32 edk::ViewScrollBar::ForegroundButton::getPercentY(){
    edk::float32 div = (this->frame.size.height - this->polygonRect.size.height);edkEnd();
    if(div){
        return ((this->polygonRect.origin.y / div)*-1.f)+1.f;edkEnd();
    }
    return div;edkEnd();
}
edk::vec2f32 edk::ViewScrollBar::ForegroundButton::getPercent(){
    return edk::vec2f32(this->getPercentX(),this->getPercentY());edkEnd();
}
//return if the mouse is holded
bool edk::ViewScrollBar::ForegroundButton::isMouseHolded(){
    return this->mouseHolded;edkEnd();
}

void edk::ViewScrollBar::load(rectf32){
    //
    this->rectScrollSave = edk::rectf32(0,0,0,0);edkEnd();
    //add the button
    edk::ViewController::addSubview(&this->background);edkEnd();
    edk::ViewController::addSubview(&this->foreground);edkEnd();
}
void edk::ViewScrollBar::unload(){
    edk::ViewController::removeSubview(&this->background);edkEnd();
    edk::ViewController::removeSubview(&this->foreground);edkEnd();
}
void edk::ViewScrollBar::update(edk::WindowEvents*){
    this->updateFrames();edkEnd();
    //update color
    if(this->backgroundColor.a){
        //copy the backgroundColor to the button
        this->background.backgroundColor = this->backgroundColor;edkEnd();
        //clean the backgroundColor
        this->backgroundColor.a = 0.f;edkEnd();
    }
}
bool edk::ViewScrollBar::addSubview(edk::View *){return false;}

//set the border
void edk::ViewScrollBar::setBorderSize(edk::uint32 size){
    this->background.setBorderSize(size);edkEnd();
    this->foreground.setBorderSize(size);edkEnd();
}

//set the size
void edk::ViewScrollBar::setForegroundSize(edk::size2f32 size){
    this->updateFrames();edkEnd();
    this->foreground.setSize(size);edkEnd();
}
void edk::ViewScrollBar::setForegroundSize(edk::float32 width,edk::float32 height){
    this->updateFrames();edkEnd();
    this->setForegroundSize(edk::size2f32(width,height));edkEnd();
}
//Set the percent
void edk::ViewScrollBar::setPercent(edk::vec2f32 percent){
    this->updateFrames();edkEnd();
    this->foreground.setPercent(percent);edkEnd();
}
void edk::ViewScrollBar::setPercent(edk::float32 x,edk::float32 y){
    this->updateFrames();edkEnd();
    this->foreground.setPercent(x,y);edkEnd();
}
void edk::ViewScrollBar::setPercentX(edk::float32 x){
    this->updateFrames();edkEnd();
    this->foreground.setPercentX(x);edkEnd();
}
void edk::ViewScrollBar::setPercentY(edk::float32 y){
    this->updateFrames();edkEnd();
    this->foreground.setPercentY(y);edkEnd();
}

//set the color
void edk::ViewScrollBar::setBackColor(edk::color3f32 color){
    this->setBackColor(edk::color4f32(color.r,color.g,color.b,1.f));edkEnd();
}
void edk::ViewScrollBar::setBackColor(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setBackColor(edk::color4f32(r,g,b,1.f));edkEnd();
}
void edk::ViewScrollBar::setBackColor(edk::color4f32 color){
    //this->backgroundColor = edk::color4f32(0,0,0,0);edkEnd();
    this->background.backgroundColor = color;edkEnd();
}
void edk::ViewScrollBar::setBackColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setBackColor(edk::color4f32(r,g,b,a));edkEnd();
}
void edk::ViewScrollBar::setFrontColor(edk::color3f32 color){
    this->setFrontColor(edk::color4f32(color.r,color.g,color.b,1.f));edkEnd();
}
void edk::ViewScrollBar::setFrontColor(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setFrontColor(edk::color4f32(r,g,b,1.f));edkEnd();
}
void edk::ViewScrollBar::setFrontColor(edk::color4f32 color){
    this->foreground.setColor(color);edkEnd();
}
void edk::ViewScrollBar::setFrontColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setFrontColor(edk::color4f32(r,g,b,a));edkEnd();
}

//return the percent
edk::float32 edk::ViewScrollBar::getPercentX(){
    return this->foreground.getPercentX();edkEnd();
}
edk::float32 edk::ViewScrollBar::getPercentY(){
    return this->foreground.getPercentY();edkEnd();
}
edk::vec2f32 edk::ViewScrollBar::getPercent(){
    return this->foreground.getPercent();edkEnd();
}
//return true if the scroll is selected
bool edk::ViewScrollBar::isSelected(){
    return this->foreground.isMouseHolded();edkEnd();
}

//get the scrollColor
edk::color4f32 edk::ViewScrollBar::getBackColor(){
    return this->background.backgroundColor;edkEnd();
}
edk::color4f32 edk::ViewScrollBar::getFrontColor(){
    return this->foreground.backgroundColor;edkEnd();
}

//return true if the mouse is inside
bool edk::ViewScrollBar::isMouseInside(){
    return this->foreground.isMouseInside() || this->background.isMouseInside();edkEnd();
}
