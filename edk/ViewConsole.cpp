#include "ViewConsole.h"

/*
Library C++ edkViewConsole - Console Viewport to write text like a DOS Console or Linux Terminal
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
#pragma message "            Inside ViewConsole.cpp"
#endif

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
    this->classThis=NULL;
    this->Constructor();
}
edk::ViewConsole::~ViewConsole(){
    this->Destructor();
}

void edk::ViewConsole::Constructor(){
    edk::ViewGU::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->map.Constructor();
        this->back.Constructor();

        //
        this->newConsole(mapSizeX,mapSizeY);
    }
}
void edk::ViewConsole::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class

        this->map.Destructor();
        this->back.Destructor();
    }
    edk::ViewGU::Destructor();
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
bool edk::ViewConsole::writeRectangleWithShadow(edk::uint32 x,
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
        //write the shadow
        edk::uint32 temp = 0u;
        if(width<2u){
            temp = end.width;
        }
        else{
            temp = end.width+1u;
        }
        for(edk::uint32 i=x+2u;i<=temp;i++){
            this->back.writeChar(' ',i,end.height);
            this->back.writeColor(consoleColors[edk::black][0u],
                    consoleColors[edk::black][1u],
                    consoleColors[edk::black][2u],
                    i,end.height
                    );
            this->map.writeChar(' ',i,end.height);
        }
        for(edk::uint32 i=y+1u;i<=end.height;i++){
            this->back.writeChar(' ',end.width,i);
            this->back.writeColor(consoleColors[edk::black][0u],
                    consoleColors[edk::black][1u],
                    consoleColors[edk::black][2u],
                    end.width,i
                    );
            this->map.writeChar(' ',end.width,i);
            this->back.writeChar(' ',temp,i);
            this->back.writeColor(consoleColors[edk::black][0u],
                    consoleColors[edk::black][1u],
                    consoleColors[edk::black][2u],
                    temp,i
                    );
            this->map.writeChar(' ',temp,i);
        }
        return true;
    }
    return false;
}
bool edk::ViewConsole::writeRectangleWithShadow(edk::vec2ui32 position,
                                                edk::uint32 width,
                                                edk::uint32 height,
                                                edk::ConsoleColors backgroundColor
                                                ){
    return this->writeRectangleWithShadow(position.x,
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
        edk::uint32 temp = 0u;
        //write the borders
        this->map.writeChar((edk::uchar8)129u,x,y);
        this->map.writeChar((edk::uchar8)144u,x+width-1u,y);
        this->map.writeChar((edk::uchar8)143u,x,y+height-1u);
        this->map.writeChar((edk::uchar8)159u,x+width-1u,y+height-1u);
        //
        temp = end.width-1u;
        for(edk::uint32 i=x+1u;i<temp;i++){
            this->map.writeChar((edk::uchar8)191u,i,y);
            this->map.writeChar((edk::uchar8)191u,i,end.height-1u);
        }
        //
        temp = end.height-1u;
        for(edk::uint32 i=y+1u;i<temp;i++){
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
bool edk::ViewConsole::writeBoxWithShadow(edk::uint32 x,
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
        edk::uint32 temp = 0u;
        //write the borders
        this->map.writeChar((edk::uchar8)129u,x,y);
        this->map.writeChar((edk::uchar8)144u,x+width-1u,y);
        this->map.writeChar((edk::uchar8)143u,x,y+height-1u);
        this->map.writeChar((edk::uchar8)159u,x+width-1u,y+height-1u);
        //
        temp = end.width-1u;
        for(edk::uint32 i=x+1u;i<temp;i++){
            this->map.writeChar((edk::uchar8)191u,i,y);
            this->map.writeChar((edk::uchar8)191u,i,end.height-1u);
        }
        //
        temp = end.height-1u;
        for(edk::uint32 i=y+1u;i<temp;i++){
            this->map.writeChar((edk::uchar8)160u,x,i);
            this->map.writeChar((edk::uchar8)160u,end.width-1u,i);
        }

        //write the shadow
        if(width<2u){
            temp = end.width;
        }
        else{
            temp = end.width+1u;
        }
        for(edk::uint32 i=x+2u;i<=temp;i++){
            this->back.writeChar(' ',i,end.height);
            this->back.writeColor(consoleColors[edk::black][0u],
                    consoleColors[edk::black][1u],
                    consoleColors[edk::black][2u],
                    i,end.height
                    );
            this->map.writeChar(' ',i,end.height);
        }
        for(edk::uint32 i=y+1u;i<=end.height;i++){
            this->back.writeChar(' ',end.width,i);
            this->back.writeColor(consoleColors[edk::black][0u],
                    consoleColors[edk::black][1u],
                    consoleColors[edk::black][2u],
                    end.width,i
                    );
            this->map.writeChar(' ',end.width,i);
            this->back.writeChar(' ',temp,i);
            this->back.writeColor(consoleColors[edk::black][0u],
                    consoleColors[edk::black][1u],
                    consoleColors[edk::black][2u],
                    temp,i
                    );
            this->map.writeChar(' ',temp,i);
        }
        return true;
    }
    return false;
}
bool edk::ViewConsole::writeBoxWithShadow(edk::vec2ui32 position,
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

//write a scroll bar in the console
bool edk::ViewConsole::writeScrollBarVertical(edk::uint32 x,
                                              edk::uint32 y,
                                              edk::uint32 lenght,
                                              edk::uint32 barPosition,
                                              edk::uint32 barLenght,
                                              edk::ConsoleColors color,
                                              edk::ConsoleColors backgroundColor
                                              ){

    edk::size2ui32 size = this->back.getMapSize();
    if(lenght+y >= size.height){
        lenght = size.height - y;
    }
    edk::size2ui32 end = edk::size2ui32(1u+x,lenght+y);

    edk::uint32 barEnd = barLenght+barPosition+y+1u;
    if(barEnd>y+lenght-1u){
        barEnd = y+lenght-1u;
    }


    if(x<size.width
            && y<size.height
            && end.width<= size.width
            && end.height <= size.height
            && lenght>=3u
            ){

        for(edk::uint32 i= y;i<end.height;i++){
            for(edk::uint32 j= x;j<end.width;j++){
                this->back.writeChar(' ',j,i);
                this->back.writeColor(consoleColors[backgroundColor][0u],
                        consoleColors[backgroundColor][1u],
                        consoleColors[backgroundColor][2u],
                        j,i
                        );
                this->map.writeChar((edk::uchar8)7u,j,i);
                this->map.writeColor(consoleColors[color][0u],
                        consoleColors[color][1u],
                        consoleColors[color][2u],
                        j,i);
            }
        }

        //write the arrows
        this->map.writeChar((edk::uchar8)30u,x,y);
        this->map.writeChar((edk::uchar8)31u,x,y+lenght-1u);
        //write the scroll bar
        for(edk::uint32 i=y+barPosition+1u;i<barEnd;i++){
            this->map.writeChar(' ',x,i);
            this->back.writeColor(consoleColors[color][0u],
                    consoleColors[color][1u],
                    consoleColors[color][2u],
                    x,i);
        }
        return true;
    }
    return false;
}
bool edk::ViewConsole::writeScrollBarVertical(edk::vec2ui32 position,
                                              edk::uint32 lenght,
                                              edk::uint32 barPosition,
                                              edk::uint32 barLenght,
                                              edk::ConsoleColors color,
                                              edk::ConsoleColors backgroundColor
                                              ){
    return this->writeScrollBarVertical(position.x,
                                        position.y,
                                        lenght,
                                        barPosition,
                                        barLenght,
                                        color,
                                        backgroundColor
                                        );
}

bool edk::ViewConsole::writeScrollBarHorizontal(edk::uint32 x,
                                                edk::uint32 y,
                                                edk::uint32 lenght,
                                                edk::uint32 barPosition,
                                                edk::uint32 barLenght,
                                                edk::ConsoleColors color,
                                                edk::ConsoleColors backgroundColor
                                                ){

    edk::size2ui32 size = this->back.getMapSize();
    if(lenght+x >= size.width){
        lenght = size.width - x;
    }
    edk::size2ui32 end = edk::size2ui32(lenght+x,1u+y);

    edk::uint32 barEnd = barLenght+barPosition+x+1u;
    if(barEnd>x+lenght-1u){
        barEnd = x+lenght-1u;
    }


    if(x<size.width
            && y<size.height
            && end.width<= size.width
            && end.height <= size.height
            && lenght>=3u
            ){

        for(edk::uint32 i= y;i<end.height;i++){
            for(edk::uint32 j= x;j<end.width;j++){
                this->back.writeChar(' ',j,i);
                this->back.writeColor(consoleColors[backgroundColor][0u],
                        consoleColors[backgroundColor][1u],
                        consoleColors[backgroundColor][2u],
                        j,i
                        );
                this->map.writeChar((edk::uchar8)7u,j,i);
                this->map.writeColor(consoleColors[color][0u],
                        consoleColors[color][1u],
                        consoleColors[color][2u],
                        j,i);
            }
        }
        //write the arrows
        this->map.writeChar((edk::uchar8)17u,x,y);
        this->map.writeChar((edk::uchar8)16u,x+lenght-1u,y);
        //write the scroll bar
        for(edk::uint32 i=x+barPosition+1u;i<barEnd;i++){
            this->map.writeChar(' ',i,y);
            this->back.writeColor(consoleColors[color][0u],
                    consoleColors[color][1u],
                    consoleColors[color][2u],
                    i,y);
        }
        return true;
    }
    return false;
}
bool edk::ViewConsole::writeScrollBarHorizontal(edk::vec2ui32 position,
                                                edk::uint32 lenght,
                                                edk::uint32 barPosition,
                                                edk::uint32 barLenght,
                                                edk::ConsoleColors color,
                                                edk::ConsoleColors backgroundColor
                                                ){
    return this->writeScrollBarHorizontal(position.x,
                                          position.y,
                                          lenght,
                                          barPosition,
                                          barLenght,
                                          color,
                                          backgroundColor
                                          );
}

//write a scroll bar in the console with percent
bool edk::ViewConsole::writeScrollBarVertical(edk::uint32 x,
                                              edk::uint32 y,
                                              edk::uint32 lenght,
                                              edk::float32 barPosition,
                                              edk::float32 barLenght,
                                              edk::ConsoleColors color,
                                              edk::ConsoleColors backgroundColor
                                              ){
    edk::uint32 _lenght = (edk::uint32)((edk::float32)lenght-2u)*barLenght;
    if(!_lenght){
        _lenght=1u;
    }
    edk::uint32 _position = (edk::uint32)(barPosition *
                                          ((edk::float32)lenght-2u-
                                           (edk::float32)_lenght));
    return writeScrollBarVertical(x,
                                  y,
                                  lenght,
                                  _position,
                                  _lenght,
                                  color,
                                  backgroundColor
                                  );
}
bool edk::ViewConsole::writeScrollBarVertical(edk::vec2ui32 position,
                                              edk::uint32 lenght,
                                              edk::float32 barPosition,
                                              edk::float32 barLenght,
                                              edk::ConsoleColors color,
                                              edk::ConsoleColors backgroundColor
                                              ){
    return writeScrollBarVertical(position.x,
                                  position.y,
                                  lenght,
                                  barPosition,
                                  barLenght,
                                  color,
                                  backgroundColor
                                  );
}
bool edk::ViewConsole::writeScrollBarHorizontal(edk::uint32 x,
                                                edk::uint32 y,
                                                edk::uint32 lenght,
                                                edk::float32 barPosition,
                                                edk::float32 barLenght,
                                                edk::ConsoleColors color,
                                                edk::ConsoleColors backgroundColor
                                                ){
    edk::uint32 _lenght = (edk::uint32)((edk::float32)lenght-2u)*barLenght;
    edk::uint32 _position = (edk::uint32)(barPosition *
                                          ((edk::float32)lenght-2u-
                                           (edk::float32)_lenght));
    return writeScrollBarHorizontal(x,
                                    y,
                                    lenght,
                                    _position,
                                    _lenght,
                                    color,
                                    backgroundColor
                                    );
}
bool edk::ViewConsole::writeScrollBarHorizontal(edk::vec2ui32 position,
                                                edk::uint32 lenght,
                                                edk::float32 barPosition,
                                                edk::float32 barLenght,
                                                edk::ConsoleColors color,
                                                edk::ConsoleColors backgroundColor
                                                ){
    return writeScrollBarHorizontal(position.x,
                                    position.y,
                                    lenght,
                                    barPosition,
                                    barLenght,
                                    color,
                                    backgroundColor
                                    );
}
