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

//COLOR VALUES
edk::float32 consoleColors[edk::colorSize][3u]=
{
    {0.f,0.f,0.f},//black
    {1.f,0.f,0.f},//red
    {0.f,1.f,0.f},//green
    {1.f,1.f,0.f},//yellow
    {0.f,0.f,1.f},//blue
    {1.f,0.f,1.f},//purple
    {0.f,1.f,1.f},//cyan
    {1.f,1.f,1.f} //white
};

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
    //this->map.drawWire(1.0f,0.0f,0.0f,1.0f);
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

edk::size2ui32 edk::ViewConsole::getSize(){
    return this->map.getMapSize();
}
edk::uint32 edk::ViewConsole::getWidth(){
    return this->map.getMapSizeWidth();
}
edk::uint32 edk::ViewConsole::getHeight(){
    return this->map.getMapSizeHeight();
}

//Write a position
bool edk::ViewConsole::writeChar(edk::char8 c,edk::uint32 x,edk::uint32 y){
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8 c,edk::vec2ui32 position){
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(edk::char8* c,edk::uint32 x,edk::uint32 y){
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8* c,edk::vec2ui32 position){
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,edk::uint32 x,edk::uint32 y){
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,edk::vec2ui32 position){
    return this->map.writeChar(c,position);
}

bool edk::ViewConsole::writeChar(edk::char8 c,edk::uint32 x,edk::uint32 y,edk::ConsoleColors color){
    this->map.writeColor(consoleColors[color][0u],consoleColors[color][1u],consoleColors[color][2u],x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8 c,edk::vec2ui32 position,edk::ConsoleColors color){
    this->map.writeColor(consoleColors[color][0u],consoleColors[color][1u],consoleColors[color][2u],position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(edk::char8* c,edk::uint32 x,edk::uint32 y,edk::ConsoleColors color){
    this->map.writeColor(consoleColors[color][0u],consoleColors[color][1u],consoleColors[color][2u],x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8* c,edk::vec2ui32 position,edk::ConsoleColors color){
    this->map.writeColor(consoleColors[color][0u],consoleColors[color][1u],consoleColors[color][2u],position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,edk::uint32 x,edk::uint32 y,edk::ConsoleColors color){
    this->map.writeColor(consoleColors[color][0u],consoleColors[color][1u],consoleColors[color][2u],x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,edk::vec2ui32 position,edk::ConsoleColors color){
    this->map.writeColor(consoleColors[color][0u],consoleColors[color][1u],consoleColors[color][2u],position);
    return this->map.writeChar(c,position);
}

bool edk::ViewConsole::writeChar(edk::char8 c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::ConsoleColors color,
                                 edk::ConsoleColors backgroundColor
                                 ){
    this->back.writeColor(consoleColors[backgroundColor][0u],
            consoleColors[backgroundColor][1u],
            consoleColors[backgroundColor][2u],
            x,y);
    this->map.writeColor(consoleColors[color][0u],consoleColors[color][1u],consoleColors[color][2u],x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8 c,
                                 edk::vec2ui32 position,
                                 edk::ConsoleColors color,
                                 edk::ConsoleColors backgroundColor
                                 ){
    this->back.writeColor(consoleColors[backgroundColor][0u],
            consoleColors[backgroundColor][1u],
            consoleColors[backgroundColor][2u],
            position);
    this->map.writeColor(consoleColors[color][0u],consoleColors[color][1u],consoleColors[color][2u],position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(edk::char8* c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::ConsoleColors color,
                                 edk::ConsoleColors backgroundColor
                                 ){
    this->back.writeColor(consoleColors[backgroundColor][0u],
            consoleColors[backgroundColor][1u],
            consoleColors[backgroundColor][2u],
            x,y);
    this->map.writeColor(consoleColors[color][0u],consoleColors[color][1u],consoleColors[color][2u],x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(edk::char8* c,
                                 edk::vec2ui32 position,
                                 edk::ConsoleColors color,
                                 edk::ConsoleColors backgroundColor
                                 ){
    this->back.writeColor(consoleColors[backgroundColor][0u],
            consoleColors[backgroundColor][1u],
            consoleColors[backgroundColor][2u],
            position);
    this->map.writeColor(consoleColors[color][0u],consoleColors[color][1u],consoleColors[color][2u],position);
    return this->map.writeChar(c,position);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,
                                 edk::uint32 x,
                                 edk::uint32 y,
                                 edk::ConsoleColors color,
                                 edk::ConsoleColors backgroundColor
                                 ){
    this->back.writeColor(consoleColors[backgroundColor][0u],
            consoleColors[backgroundColor][1u],
            consoleColors[backgroundColor][2u],
            x,y);
    this->map.writeColor(consoleColors[color][0u],consoleColors[color][1u],consoleColors[color][2u],x,y);
    return this->map.writeChar(c,x,y);
}
bool edk::ViewConsole::writeChar(const edk::char8* c,
                                 edk::vec2ui32 position,
                                 edk::ConsoleColors color,
                                 edk::ConsoleColors backgroundColor
                                 ){
    this->back.writeColor(consoleColors[backgroundColor][0u],
            consoleColors[backgroundColor][1u],
            consoleColors[backgroundColor][2u],
            position);
    this->map.writeColor(consoleColors[color][0u],consoleColors[color][1u],consoleColors[color][2u],position);
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
                                   edk::vec2ui32 position,
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
                                   edk::vec2ui32 position,
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
                                   edk::vec2ui32 position,
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
                                   edk::vec2ui32 position,
                                   edk::uint32 width,
                                   edk::uint32 height
                                   ){
    return writeString((edk::char8*) str,position,width,height);
}

bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::ConsoleColors color
                                   ){
    return this->map.writeStringColor(str,
                                 x,
                                 y,
                                 width,
                                 consoleColors[color][0u],
            consoleColors[color][1u],
            consoleColors[color][2u]
            );
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2ui32 position,
                                   edk::uint32 width,
                                   edk::ConsoleColors color
                                   ){
    return this->map.writeStringColor(str,
                                 position,
                                 width,
                                 consoleColors[color][0u],
            consoleColors[color][1u],
            consoleColors[color][2u]);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::ConsoleColors color
                                   ){
    return writeString((edk::char8*) str,x,y,width,color);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2ui32 position,
                                   edk::uint32 width,
                                   edk::ConsoleColors color
                                   ){
    return writeString((edk::char8*) str,position,width,color);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::ConsoleColors color
                                   ){
    return this->map.writeStringColor(str,
                                 x,
                                 y,
                                 width,
                                 height,
                                 consoleColors[color][0u],
            consoleColors[color][1u],
            consoleColors[color][2u]
                                 );
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2ui32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::ConsoleColors color
                                   ){
    return this->map.writeStringColor(str,
                                 position,
                                 width,
                                 height,
                                 consoleColors[color][0u],
            consoleColors[color][1u],
            consoleColors[color][2u]
                                 );
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::ConsoleColors color
                                   ){
    return writeString((edk::char8*) str,x,y,width,height,color);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2ui32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::ConsoleColors color
                                   ){
    return writeString((edk::char8*) str,position,width,height,color);
}

bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::ConsoleColors color,
                                   edk::ConsoleColors backgroundColor
                                   ){
    this->back.writeSpacesColor(str,
                                x,
                                y,
                                width,
                                consoleColors[backgroundColor][0u],
           consoleColors[backgroundColor][1u],
           consoleColors[backgroundColor][2u]
           );
    return this->map.writeStringColor(str,
                                 x,
                                 y,
                                 width,
                                 consoleColors[color][0u],
            consoleColors[color][1u],
            consoleColors[color][2u]
            );
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2ui32 position,
                                   edk::uint32 width,
                                   edk::ConsoleColors color,
                                   edk::ConsoleColors backgroundColor
                                   ){
    this->back.writeSpacesColor(str,
                                position,
                                width,
                                consoleColors[backgroundColor][0u],
           consoleColors[backgroundColor][1u],
           consoleColors[backgroundColor][2u]
           );
    return this->map.writeStringColor(str,
                                 position,
                                 width,
                                 consoleColors[color][0u],
            consoleColors[color][1u],
            consoleColors[color][2u]);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::ConsoleColors color,
                                   edk::ConsoleColors backgroundColor
                                   ){
    return writeString((edk::char8*) str,x,y,width,color,backgroundColor);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2ui32 position,
                                   edk::uint32 width,
                                   edk::ConsoleColors color,
                                   edk::ConsoleColors backgroundColor
                                   ){
    return writeString((edk::char8*) str,position,width,color,backgroundColor);
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::ConsoleColors color,
                                   edk::ConsoleColors backgroundColor
                                   ){
    this->back.writeSpacesColor(str,
                                x,
                                y,
                                width,
                                height,
                                consoleColors[backgroundColor][0u],
           consoleColors[backgroundColor][1u],
           consoleColors[backgroundColor][2u]
           );
    return this->map.writeStringColor(str,
                                 x,
                                 y,
                                 width,
                                 height,
                                 consoleColors[color][0u],
            consoleColors[color][1u],
            consoleColors[color][2u]
                                 );
}
bool edk::ViewConsole::writeString(edk::char8* str,
                                   edk::vec2ui32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::ConsoleColors color,
                                   edk::ConsoleColors backgroundColor
                                   ){
    this->back.writeSpacesColor(str,
                                position,
                                width,
                                height,
                                consoleColors[backgroundColor][0u],
           consoleColors[backgroundColor][1u],
           consoleColors[backgroundColor][2u]
           );
    return this->map.writeStringColor(str,
                                 position,
                                 width,
                                 height,
                                 consoleColors[color][0u],
            consoleColors[color][1u],
            consoleColors[color][2u]
                                 );
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::uint32 x,
                                   edk::uint32 y,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::ConsoleColors color,
                                   edk::ConsoleColors backgroundColor
                                   ){
    return writeString((edk::char8*) str,x,y,width,height,color,backgroundColor);
}
bool edk::ViewConsole::writeString(const edk::char8* str,
                                   edk::vec2ui32 position,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::ConsoleColors color,
                                   edk::ConsoleColors backgroundColor
                                   ){
    return writeString((edk::char8*) str,position,width,height,color,backgroundColor);
}

//write a rectangle just in background color
bool edk::ViewConsole::writeRectangle(edk::uint32 x,
                                      edk::uint32 y,
                                      edk::uint32 width,
                                      edk::uint32 height,
                                      edk::ConsoleColors backgroundColor
                                      ){
    edk::size2ui32 size = this->back.getMapSize();
    if(width+x >= size.width){
        width = size.width - x;
    }
    if(height+y >= size.height){
        height = size.height - y;
    }
    edk::size2ui32 end = edk::size2ui32(width+x,height+y);
    if(x<size.width
            && y<size.height
            && end.width<= size.width
            && end.height <= size.height
            ){
        for(edk::uint32 i= y;i<end.height;i++){
            for(edk::uint32 j= x;j<end.width;j++){
                this->back.writeChar(' ',j,i);
                this->back.writeColor(consoleColors[backgroundColor][0u],
                        consoleColors[backgroundColor][1u],
                        consoleColors[backgroundColor][2u],
                        j,i
                        );
                this->map.writeChar(' ',j,i);
            }
        }
        return true;
    }
    return false;
}
bool edk::ViewConsole::writeRectangle(edk::vec2ui32 position,
                    edk::uint32 width,
                    edk::uint32 height,
                    edk::ConsoleColors backgroundColor
                    ){
    return this->writeRectangle(position.x,
                                position.y,
                                width,
                                height,
                                backgroundColor
                                );
}
bool edk::ViewConsole::writeBox(edk::uint32 x,
              edk::uint32 y,
              edk::uint32 width,
              edk::uint32 height,
              edk::ConsoleColors color,
              edk::ConsoleColors backgroundColor
                                ){
    edk::size2ui32 size = this->back.getMapSize();
    if(width+x >= size.width){
        width = size.width - x;
    }
    if(height+y >= size.height){
        height = size.height - y;
    }
    edk::size2ui32 end = edk::size2ui32(width+x,height+y);
    if(x<size.width
            && y<size.height
            && end.width<= size.width
            && end.height <= size.height
            && width>=3u
            && height>=3u
            ){
        for(edk::uint32 i= y;i<end.height;i++){
            for(edk::uint32 j= x;j<end.width;j++){
                this->back.writeChar(' ',j,i);
                this->back.writeColor(consoleColors[backgroundColor][0u],
                        consoleColors[backgroundColor][1u],
                        consoleColors[backgroundColor][2u],
                        j,i
                        );
                this->map.writeChar(' ',j,i);
                this->map.writeColor(consoleColors[color][0u],
                        consoleColors[color][1u],
                        consoleColors[color][2u],
                        j,i);
            }
        }
        //write the borders
        this->map.writeChar((edk::uchar8)129u,x,y);
        this->map.writeChar((edk::uchar8)144u,x+width-1u,y);
        this->map.writeChar((edk::uchar8)143u,x,y+height-1u);
        this->map.writeChar((edk::uchar8)159u,x+width-1u,y+height-1u);
        //
        for(edk::uint32 i=x+1u;i<end.width-1u;i++){
            this->map.writeChar((edk::uchar8)191u,i,y);
            this->map.writeChar((edk::uchar8)191u,i,end.height-1u);
        }
        //
        for(edk::uint32 i=y+1u;i<end.height-1u;i++){
            this->map.writeChar((edk::uchar8)160u,x,i);
            this->map.writeChar((edk::uchar8)160u,end.width-1u,i);
        }
        return true;
    }
    return false;
}
bool edk::ViewConsole::writeBox(edk::vec2ui32 position,
              edk::uint32 width,
              edk::uint32 height,
              edk::ConsoleColors color,
              edk::ConsoleColors backgroundColor
                                ){
    return this->writeBox(position.x,
                          position.y,
                          width,
                          height,
                          color,
                          backgroundColor
                                            );
}
