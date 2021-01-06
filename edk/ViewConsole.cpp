#include "ViewConsole.h"

/*
Library C++ edkViewConsole - Console Viewport to write text like a DOS Console or Linux Terminal
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

edk::ViewConsole::ViewConsole(){
    //
    this->newConsole(mapSizeX,mapSizeY);
}
edk::ViewConsole::~ViewConsole(){
    //
}
//draw the polygon on the scene
void edk::ViewConsole::runDrawScene(edk::rectf32 outsideViewOrigin){
    edk::ViewGU::runDrawScene(outsideViewOrigin);

    //draw the back and map
    this->back.drawWithoutMaterial();
    this->map.draw();
}

//set the map size
bool edk::ViewConsole::newConsole(edk::size2ui32 size){
    //
    this->map.deleteMap();
    if(size.width && size.height){
        //clean the new map
        if(this->map.createMap(mapSizeX,mapSizeY)){
            //set scale and position to fit in the screen
            this->map.setScale(1.0f/mapSizeX,1.0f/mapSizeY);
            this->map.setPosition(0.5 * this->map.getMapScaleWidth()
                                  ,0.5f * this->map.getMapScaleHeight()
                                  );

            if(this->back.createMap(mapSizeX,mapSizeY)){
                this->back.setColor(1.f,1.f,1.f,1.f);
                this->back.setScale(1.0f/mapSizeX,1.0f/mapSizeY);
                this->back.setPosition(0.5 * this->map.getMapScaleWidth()
                                       ,0.5f * this->map.getMapScaleHeight()
                                       );
                for(edk::uint32 y=0u;y<mapSizeY;y++){
                    for(edk::uint32 x=0u;x<mapSizeX;x++){
                        this->back.writeChar(' ',x,y);
                    }
                }
                return true;
            }

            this->map.deleteMap();
        }
    }
    return false;
}
bool edk::ViewConsole::newConsole(edk::uint32 width,edk::uint32 height){
    return this->newConsole(edk::size2ui32(width,height));
}

//Write a position
bool edk::ViewConsole::writeChar(edk::char8 c,edk::uint32 x,edk::uint32 y){
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8 c,edk::vec2f32 position){
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(edk::char8* c,edk::uint32 x,edk::uint32 y){
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8* c,edk::vec2f32 position){
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,edk::uint32 x,edk::uint32 y){
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,edk::vec2f32 position){
    return this->map.writeChar(c,position);
}

bool edk::ViewConsole::writeChar(edk::char8 c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB,
                                 edk::float32 colorA
                                 ){
    this->map.writeColor(colorR,colorG,colorB,colorA,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8 c,
                                 edk::vec2f32 position,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB,
                                 edk::float32 colorA
                                 ){
    this->map.writeColor(colorR,colorG,colorB,colorA,position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(edk::char8* c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB,
                                 edk::float32 colorA
                                 ){
    this->map.writeColor(colorR,colorG,colorB,colorA,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8* c,
                                 edk::vec2f32 position,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB,
                                 edk::float32 colorA
                                 ){
    this->map.writeColor(colorR,colorG,colorB,colorA,position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB,
                                 edk::float32 colorA
                                 ){
    this->map.writeColor(colorR,colorG,colorB,colorA,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,
                                 edk::vec2f32 position,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB,
                                 edk::float32 colorA
                                 ){
    this->map.writeColor(colorR,colorG,colorB,colorA,position);
    return this->map.writeChar(c,position);
}

bool edk::ViewConsole::writeChar(edk::char8 c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB
                                 ){
    this->map.writeColor(colorR,colorG,colorB,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8 c,
                                 edk::vec2f32 position,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB
                                 ){
    this->map.writeColor(colorR,colorG,colorB,position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(edk::char8* c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB
                                 ){
    this->map.writeColor(colorR,colorG,colorB,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8* c,
                                 edk::vec2f32 position,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB
                                 ){
    this->map.writeColor(colorR,colorG,colorB,position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB
                                 ){
    this->map.writeColor(colorR,colorG,colorB,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,
                                 edk::vec2f32 position,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB
                                 ){
    this->map.writeColor(colorR,colorG,colorB,position);
    return this->map.writeChar(c,position);
}

bool edk::ViewConsole::writeChar(edk::char8 c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::color3f32 color
                                 ){
    this->map.writeColor(color,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8 c,
                                 edk::vec2f32 position,
                                 edk::color3f32 color
                                 ){
    this->map.writeColor(color,position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(edk::char8* c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::color3f32 color
                                 ){
    this->map.writeColor(color,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8* c,
                                 edk::vec2f32 position,
                                 edk::color3f32 color
                                 ){
    this->map.writeColor(color,position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::color3f32 color
                                 ){
    this->map.writeColor(color,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,
                                 edk::vec2f32 position,
                                 edk::color3f32 color
                                 ){
    this->map.writeColor(color,position);
    return this->map.writeChar(c,position);
}

bool edk::ViewConsole::writeChar(edk::char8 c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::color4f32 color
                                 ){
    this->map.writeColor(color,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8 c,
                                 edk::vec2f32 position,
                                 edk::color4f32 color
                                 ){
    this->map.writeColor(color,position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(edk::char8* c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::color4f32 color
                                 ){
    this->map.writeColor(color,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8* c,
                                 edk::vec2f32 position,
                                 edk::color4f32 color
                                 ){
    this->map.writeColor(color,position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::color4f32 color
                                 ){
    this->map.writeColor(color,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,
                                 edk::vec2f32 position,
                                 edk::color4f32 color
                                 ){
    this->map.writeColor(color,position);
    return this->map.writeChar(c,position);
}

bool edk::ViewConsole::writeChar(edk::char8 c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB,
                                 edk::float32 colorA,
                                 edk::float32 backgroundColorR,
                                 edk::float32 backgroundColorG,
                                 edk::float32 backgroundColorB,
                                 edk::float32 backgroundColorA
                                 ){
    this->back.writeColor(backgroundColorR,backgroundColorG,backgroundColorB,backgroundColorA,x,y);
    this->map.writeColor(colorR,colorG,colorB,colorA,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8 c,
                                 edk::vec2f32 position,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB,
                                 edk::float32 colorA,
                                 edk::float32 backgroundColorR,
                                 edk::float32 backgroundColorG,
                                 edk::float32 backgroundColorB,
                                 edk::float32 backgroundColorA
                                 ){
    this->back.writeColor(backgroundColorR,backgroundColorG,backgroundColorB,backgroundColorA,position);
    this->map.writeColor(colorR,colorG,colorB,colorA,position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(edk::char8* c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB,
                                 edk::float32 colorA,
                                 edk::float32 backgroundColorR,
                                 edk::float32 backgroundColorG,
                                 edk::float32 backgroundColorB,
                                 edk::float32 backgroundColorA
                                 ){
    this->back.writeColor(backgroundColorR,backgroundColorG,backgroundColorB,backgroundColorA,x,y);
    this->map.writeColor(colorR,colorG,colorB,colorA,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8* c,
                                 edk::vec2f32 position,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB,
                                 edk::float32 colorA,
                                 edk::float32 backgroundColorR,
                                 edk::float32 backgroundColorG,
                                 edk::float32 backgroundColorB,
                                 edk::float32 backgroundColorA
                                 ){
    this->back.writeColor(backgroundColorR,backgroundColorG,backgroundColorB,backgroundColorA,position);
    this->map.writeColor(colorR,colorG,colorB,colorA,position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB,
                                 edk::float32 colorA,
                                 edk::float32 backgroundColorR,
                                 edk::float32 backgroundColorG,
                                 edk::float32 backgroundColorB,
                                 edk::float32 backgroundColorA
                                 ){
    this->back.writeColor(backgroundColorR,backgroundColorG,backgroundColorB,backgroundColorA,x,y);
    this->map.writeColor(colorR,colorG,colorB,colorA,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,
                                 edk::vec2f32 position,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB,
                                 edk::float32 colorA,
                                 edk::float32 backgroundColorR,
                                 edk::float32 backgroundColorG,
                                 edk::float32 backgroundColorB,
                                 edk::float32 backgroundColorA
                                 ){
    this->back.writeColor(backgroundColorR,backgroundColorG,backgroundColorB,backgroundColorA,position);
    this->map.writeColor(colorR,colorG,colorB,colorA,position);
    return this->map.writeChar(c,position);
}

bool edk::ViewConsole::writeChar(edk::char8 c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB,
                                 edk::float32 backgroundColorR,
                                 edk::float32 backgroundColorG,
                                 edk::float32 backgroundColorB
                                 ){
    this->back.writeColor(backgroundColorR,backgroundColorG,backgroundColorB,x,y);
    this->map.writeColor(colorR,colorG,colorB,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8 c,
                                 edk::vec2f32 position,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB,
                                 edk::float32 backgroundColorR,
                                 edk::float32 backgroundColorG,
                                 edk::float32 backgroundColorB
                                 ){
    this->back.writeColor(backgroundColorR,backgroundColorG,backgroundColorB,position);
    this->map.writeColor(colorR,colorG,colorB,position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(edk::char8* c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB,
                                 edk::float32 backgroundColorR,
                                 edk::float32 backgroundColorG,
                                 edk::float32 backgroundColorB
                                 ){
    this->back.writeColor(backgroundColorR,backgroundColorG,backgroundColorB,x,y);
    this->map.writeColor(colorR,colorG,colorB,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8* c,
                                 edk::vec2f32 position,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB,
                                 edk::float32 backgroundColorR,
                                 edk::float32 backgroundColorG,
                                 edk::float32 backgroundColorB
                                 ){
    this->back.writeColor(backgroundColorR,backgroundColorG,backgroundColorB,position);
    this->map.writeColor(colorR,colorG,colorB,position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB,
                                 edk::float32 backgroundColorR,
                                 edk::float32 backgroundColorG,
                                 edk::float32 backgroundColorB
                                 ){
    this->back.writeColor(backgroundColorR,backgroundColorG,backgroundColorB,x,y);
    this->map.writeColor(colorR,colorG,colorB,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,
                                 edk::vec2f32 position,
                                 edk::float32 colorR,
                                 edk::float32 colorG,
                                 edk::float32 colorB,
                                 edk::float32 backgroundColorR,
                                 edk::float32 backgroundColorG,
                                 edk::float32 backgroundColorB
                                 ){
    this->back.writeColor(backgroundColorR,backgroundColorG,backgroundColorB,position);
    this->map.writeColor(colorR,colorG,colorB,position);
    return this->map.writeChar(c,position);
}

bool edk::ViewConsole::writeChar(edk::char8 c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::color3f32 color,
                                 edk::color3f32 backgroundColor
                                 ){
    this->back.writeColor(backgroundColor,x,y);
    this->map.writeColor(color,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8 c,
                                 edk::vec2f32 position,
                                 edk::color3f32 color,
                                 edk::color3f32 backgroundColor
                                 ){
    this->back.writeColor(backgroundColor,position);
    this->map.writeColor(color,position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(edk::char8* c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::color3f32 color,
                                 edk::color3f32 backgroundColor
                                 ){
    this->back.writeColor(backgroundColor,x,y);
    this->map.writeColor(color,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8* c,
                                 edk::vec2f32 position,
                                 edk::color3f32 color,
                                 edk::color3f32 backgroundColor
                                 ){
    this->back.writeColor(backgroundColor,position);
    this->map.writeColor(color,position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::color3f32 color,
                                 edk::color3f32 backgroundColor
                                 ){
    this->back.writeColor(backgroundColor,x,y);
    this->map.writeColor(color,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,
                                 edk::vec2f32 position,
                                 edk::color3f32 color,
                                 edk::color3f32 backgroundColor
                                 ){
    this->back.writeColor(backgroundColor,position);
    this->map.writeColor(color,position);
    return this->map.writeChar(c,position);
}

bool edk::ViewConsole::writeChar(edk::char8 c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::color4f32 color,
                                 edk::color4f32 backgroundColor
                                 ){
    this->back.writeColor(backgroundColor,x,y);
    this->map.writeColor(color,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8 c,
                                 edk::vec2f32 position,
                                 edk::color4f32 color,
                                 edk::color4f32 backgroundColor
                                 ){
    this->back.writeColor(backgroundColor,position);
    this->map.writeColor(color,position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(edk::char8* c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::color4f32 color,
                                 edk::color4f32 backgroundColor
                                 ){
    this->back.writeColor(backgroundColor,x,y);
    this->map.writeColor(color,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8* c,
                                 edk::vec2f32 position,
                                 edk::color4f32 color,
                                 edk::color4f32 backgroundColor
                                 ){
    this->back.writeColor(backgroundColor,position);
    this->map.writeColor(color,position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::color4f32 color,
                                 edk::color4f32 backgroundColor
                                 ){
    this->back.writeColor(backgroundColor,x,y);
    this->map.writeColor(color,x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,
                                 edk::vec2f32 position,
                                 edk::color4f32 color,
                                 edk::color4f32 backgroundColor
                                 ){
    this->back.writeColor(backgroundColor,position);
    this->map.writeColor(color,position);
    return this->map.writeChar(c,position);
}

//write the string
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width
                                   ){
    return this->map.writeString(str,x,y,width);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width
                                   ){
    return this->map.writeString(str,position,width);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width
                                   ){
    return writeString((edk::char8*) str,x,y,width);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width
                                   ){
    return writeString((edk::char8*) str,position,width);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height
                                   ){
    return this->map.writeString(str,x,y,width,height);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::uint32 height
                                   ){
    return this->map.writeString(str,position,width,height);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height
                                   ){
    return writeString((edk::char8*) str,x,y,width,height);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::uint32 height
                                   ){
    return writeString((edk::char8*) str,position,width,height);
}

bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 colorA
                                   ){
    return this->map.writeStringColor(str,x,y,width,colorR,colorG,colorB,colorA);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 colorA
                                   ){
    return this->map.writeStringColor(str,position,width,colorR,colorG,colorB,colorA);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 colorA
                                   ){
    return writeString((edk::char8*) str,x,y,width,colorR,colorG,colorB,colorA);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 colorA
                                   ){
    return writeString((edk::char8*) str,position,width,colorR,colorG,colorB,colorA);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 colorA
                                   ){
    return this->map.writeStringColor(str,x,y,width,height,colorR,colorG,colorB,colorA);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 colorA
                                   ){
    return this->map.writeStringColor(str,position,width,height,colorR,colorG,colorB,colorA);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 colorA
                                   ){
    return writeString((edk::char8*) str,x,y,width,height,colorR,colorG,colorB,colorA);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 colorA
                                   ){
    return writeString((edk::char8*) str,position,width,height,colorR,colorG,colorB,colorA);
}

bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB
                                   ){
    return this->map.writeStringColor(str,x,y,width,colorR,colorG,colorB);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB
                                   ){
    return this->map.writeStringColor(str,position,width,colorR,colorG,colorB);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB
                                   ){
    return writeString((edk::char8*) str,x,y,width,colorR,colorG,colorB);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB
                                   ){
    return writeString((edk::char8*) str,position,width,colorR,colorG,colorB);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB
                                   ){
    return this->map.writeStringColor(str,x,y,width,height,colorR,colorG,colorB);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB
                                   ){
    return this->map.writeStringColor(str,position,width,height,colorR,colorG,colorB);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB
                                   ){
    return writeString((edk::char8*) str,x,y,width,height,colorR,colorG,colorB);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB
                                   ){
    return writeString((edk::char8*) str,position,width,height,colorR,colorG,colorB);
}

bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::color4f32 color
                                   ){
    return this->map.writeStringColor(str,x,y,width,color);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::color4f32 color
                                   ){
    return this->map.writeStringColor(str,position,width,color);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::color4f32 color
                                   ){
    return writeString((edk::char8*) str,x,y,width,color);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::color4f32 color
                                   ){
    return writeString((edk::char8*) str,position,width,color);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::color4f32 color
                                   ){
    return this->map.writeStringColor(str,x,y,width,height,color);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::color4f32 color
                                   ){
    return this->map.writeStringColor(str,position,width,height,color);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::color4f32 color
                                   ){
    return writeString((edk::char8*) str,x,y,width,height,color);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::color4f32 color
                                   ){
    return writeString((edk::char8*) str,position,width,height,color);
}

bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::color3f32 color
                                   ){
    return this->map.writeStringColor(str,x,y,width,color);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::color3f32 color
                                   ){
    return this->map.writeStringColor(str,position,width,color);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::color3f32 color
                                   ){
    return writeString((edk::char8*) str,x,y,width,color);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::color3f32 color
                                   ){
    return writeString((edk::char8*) str,position,width,color);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::color3f32 color
                                   ){
    return this->map.writeStringColor(str,x,y,width,height,color);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::color3f32 color
                                   ){
    return this->map.writeStringColor(str,position,width,height,color);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::color3f32 color
                                   ){
    return writeString((edk::char8*) str,x,y,width,height,color);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::color3f32 color
                                   ){
    return writeString((edk::char8*) str,position,width,height,color);
}




























bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 colorA,
                                   edk::float32 backgroundColorR,
                                   edk::float32 backgroundColorG,
                                   edk::float32 backgroundColorB,
                                   edk::float32 backgroundColorA
                                   ){
    this->back.writeSpacesColor(str,x,y,width,backgroundColorR,backgroundColorG,backgroundColorB,backgroundColorA);
    return this->map.writeStringColor(str,x,y,width,colorR,colorG,colorB,colorA);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 colorA,
                                   edk::float32 backgroundColorR,
                                   edk::float32 backgroundColorG,
                                   edk::float32 backgroundColorB,
                                   edk::float32 backgroundColorA
                                   ){
    this->back.writeSpacesColor(str,position,width,backgroundColorR,backgroundColorG,backgroundColorB,backgroundColorA);
    return this->map.writeStringColor(str,position,width,colorR,colorG,colorB,colorA);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 colorA,
                                   edk::float32 backgroundColorR,
                                   edk::float32 backgroundColorG,
                                   edk::float32 backgroundColorB,
                                   edk::float32 backgroundColorA
                                   ){
    return writeString((edk::char8*) str,x,y,width,colorR,colorG,colorB,colorA,
                       backgroundColorR,backgroundColorG,backgroundColorB,backgroundColorA
                       );
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 colorA,
                                   edk::float32 backgroundColorR,
                                   edk::float32 backgroundColorG,
                                   edk::float32 backgroundColorB,
                                   edk::float32 backgroundColorA
                                   ){
    return writeString((edk::char8*) str,position,width,colorR,colorG,colorB,colorA,
                       backgroundColorR,backgroundColorG,backgroundColorB,backgroundColorA
                       );
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 colorA,
                                   edk::float32 backgroundColorR,
                                   edk::float32 backgroundColorG,
                                   edk::float32 backgroundColorB,
                                   edk::float32 backgroundColorA
                                   ){
    this->back.writeSpacesColor(str,x,y,width,height,backgroundColorR,backgroundColorG,backgroundColorB,backgroundColorA);
    return this->map.writeStringColor(str,x,y,width,height,colorR,colorG,colorB,colorA);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 colorA,
                                   edk::float32 backgroundColorR,
                                   edk::float32 backgroundColorG,
                                   edk::float32 backgroundColorB,
                                   edk::float32 backgroundColorA
                                   ){
    this->back.writeSpacesColor(str,position,width,height,backgroundColorR,backgroundColorG,backgroundColorB,backgroundColorA);
    return this->map.writeStringColor(str,position,width,height,colorR,colorG,colorB,colorA);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 colorA,
                                   edk::float32 backgroundColorR,
                                   edk::float32 backgroundColorG,
                                   edk::float32 backgroundColorB,
                                   edk::float32 backgroundColorA
                                   ){
    return writeString((edk::char8*) str,x,y,width,height,colorR,colorG,colorB,colorA,
                       backgroundColorR,backgroundColorG,backgroundColorB,backgroundColorA
                       );
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 colorA,
                                   edk::float32 backgroundColorR,
                                   edk::float32 backgroundColorG,
                                   edk::float32 backgroundColorB,
                                   edk::float32 backgroundColorA
                                   ){
    return writeString((edk::char8*) str,position,width,height,colorR,colorG,colorB,colorA,
                       backgroundColorR,backgroundColorG,backgroundColorB,backgroundColorA
                       );
}

bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 backgroundColorR,
                                   edk::float32 backgroundColorG,
                                   edk::float32 backgroundColorB
                                   ){
    this->back.writeSpacesColor(str,x,y,width,backgroundColorR,backgroundColorG,backgroundColorB);
    return this->map.writeStringColor(str,x,y,width,colorR,colorG,colorB);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 backgroundColorR,
                                   edk::float32 backgroundColorG,
                                   edk::float32 backgroundColorB
                                   ){
    this->back.writeSpacesColor(str,position,width,backgroundColorR,backgroundColorG,backgroundColorB);
    return this->map.writeStringColor(str,position,width,colorR,colorG,colorB);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 backgroundColorR,
                                   edk::float32 backgroundColorG,
                                   edk::float32 backgroundColorB
                                   ){
    return writeString((edk::char8*) str,x,y,width,colorR,colorG,colorB,
                       backgroundColorR,backgroundColorG,backgroundColorB
                       );
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 backgroundColorR,
                                   edk::float32 backgroundColorG,
                                   edk::float32 backgroundColorB
                                   ){
    return writeString((edk::char8*) str,position,width,colorR,colorG,colorB,
                       backgroundColorR,backgroundColorG,backgroundColorB
                       );
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 backgroundColorR,
                                   edk::float32 backgroundColorG,
                                   edk::float32 backgroundColorB
                                   ){
    this->back.writeSpacesColor(str,x,y,width,height,backgroundColorR,backgroundColorG,backgroundColorB);
    return this->map.writeStringColor(str,x,y,width,height,colorR,colorG,colorB);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 backgroundColorR,
                                   edk::float32 backgroundColorG,
                                   edk::float32 backgroundColorB
                                   ){
    this->back.writeSpacesColor(str,position,width,height,backgroundColorR,backgroundColorG,backgroundColorB);
    return this->map.writeStringColor(str,position,width,height,colorR,colorG,colorB);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 backgroundColorR,
                                   edk::float32 backgroundColorG,
                                   edk::float32 backgroundColorB
                                   ){
    return writeString((edk::char8*) str,x,y,width,height,colorR,colorG,colorB,
                       backgroundColorR,backgroundColorG,backgroundColorB
                       );
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::float32 colorR,
                                   edk::float32 colorG,
                                   edk::float32 colorB,
                                   edk::float32 backgroundColorR,
                                   edk::float32 backgroundColorG,
                                   edk::float32 backgroundColorB
                                   ){
    return writeString((edk::char8*) str,position,width,height,colorR,colorG,colorB,
                       backgroundColorR,backgroundColorG,backgroundColorB
                       );
}

bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::color4f32 color,
                                   edk::color4f32 backgroundColor
                                   ){
    this->back.writeSpacesColor(str,x,y,width,backgroundColor);
    return this->map.writeStringColor(str,x,y,width,color);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::color4f32 color,
                                   edk::color4f32 backgroundColor
                                   ){
    this->back.writeSpacesColor(str,position,width,backgroundColor);
    return this->map.writeStringColor(str,position,width,color);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::color4f32 color,
                                   edk::color4f32 backgroundColor
                                   ){
    return writeString((edk::char8*) str,x,y,width,color,backgroundColor);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::color4f32 color,
                                   edk::color4f32 backgroundColor
                                   ){
    return writeString((edk::char8*) str,position,width,color,backgroundColor);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::color4f32 color,
                                   edk::color4f32 backgroundColor
                                   ){
    this->back.writeSpacesColor(str,x,y,width,height,backgroundColor);
    return this->map.writeStringColor(str,x,y,width,height,color);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::color4f32 color,
                                   edk::color4f32 backgroundColor
                                   ){
    this->back.writeSpacesColor(str,position,width,height,backgroundColor);
    return this->map.writeStringColor(str,position,width,height,color);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::color4f32 color,
                                   edk::color4f32 backgroundColor
                                   ){
    return writeString((edk::char8*) str,x,y,width,height,color,backgroundColor);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::color4f32 color,
                                   edk::color4f32 backgroundColor
                                   ){
    return writeString((edk::char8*) str,position,width,height,color,backgroundColor);
}

bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::color3f32 color,
                                   edk::color3f32 backgroundColor
                                   ){
    this->back.writeSpacesColor(str,x,y,width,backgroundColor);
    return this->map.writeStringColor(str,x,y,width,color);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::color3f32 color,
                                   edk::color3f32 backgroundColor
                                   ){
    this->back.writeSpacesColor(str,position,width,backgroundColor);
    return this->map.writeStringColor(str,position,width,color);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::color3f32 color,
                                   edk::color3f32 backgroundColor
                                   ){
    return writeString((edk::char8*) str,x,y,width,color,backgroundColor);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::color3f32 color,
                                   edk::color3f32 backgroundColor
                                   ){
    return writeString((edk::char8*) str,position,width,color,backgroundColor);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::color3f32 color,
                                   edk::color3f32 backgroundColor
                                   ){
    this->back.writeSpacesColor(str,x,y,width,height,backgroundColor);
    return this->map.writeStringColor(str,x,y,width,height,color);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::color3f32 color,
                                   edk::color3f32 backgroundColor
                                   ){
    this->back.writeSpacesColor(str,position,width,height,backgroundColor);
    return this->map.writeStringColor(str,position,width,height,color);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::color3f32 color,
                                   edk::color3f32 backgroundColor
                                   ){
    return writeString((edk::char8*) str,x,y,width,height,color,backgroundColor);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2f32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::color3f32 color,
                                   edk::color3f32 backgroundColor
                                   ){
    return writeString((edk::char8*) str,position,width,height,color,backgroundColor);
}
