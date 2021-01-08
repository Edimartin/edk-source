#ifndef VIEWCONSOLE_H
#define VIEWCONSOLE_H

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

#ifdef printMessages
#warning "Inside ViewConsole"
#endif

#include "edk/ViewGU.h"

#include "edk/fonts/FontMap.h"

#ifdef printMessages
#warning "    Compiling ViewConsole"
#endif

#define mapSizeX 80u
#define mapSizeY 24u

/*
BLACK
RED
GREEN
YELLOW
BLUE
MAGENTA
CYAN
WHITE

    Black \033[0;30m

    Red \033[0;31m

    Green \033[0;32m

    Yellow \033[0;33m

    Blue \033[0;34m

    Purple \033[0;35m

    Cyan \033[0;36m

    White \033[0;37m
*/

namespace edk{

//COLOR IDS
enum ConsoleColors{
    black = 0u,
    red,
    green,
    yellow,
    blue,
    purple,
    cyan,
    white,

    colorSize
};

class ViewConsole : public edk::ViewGU{
public:
    ViewConsole();
    ~ViewConsole();

    //set the map size
    bool newConsole(edk::size2ui32 size);
    bool newConsole(edk::uint32 width,edk::uint32 height);

    edk::size2ui32 getSize();
    edk::uint32 getWidth();
    edk::uint32 getHeight();

    //Write a position
    bool writeChar(edk::char8 c,edk::uint32 x,edk::uint32 y);
    bool writeChar(edk::char8 c,edk::vec2ui32 position);
    bool writeChar(edk::char8* c,edk::uint32 x,edk::uint32 y);
    bool writeChar(edk::char8* c,edk::vec2ui32 position);
    bool writeChar(const edk::char8* c,edk::uint32 x,edk::uint32 y);
    bool writeChar(const edk::char8* c,edk::vec2ui32 position);

    bool writeChar(edk::char8 c,edk::uint32 x,edk::uint32 y,edk::ConsoleColors color);
    bool writeChar(edk::char8 c,edk::vec2ui32 position,edk::ConsoleColors color);
    bool writeChar(edk::char8* c,edk::uint32 x,edk::uint32 y,edk::ConsoleColors color);
    bool writeChar(edk::char8* c,edk::vec2ui32 position,edk::ConsoleColors color);
    bool writeChar(const edk::char8* c,edk::uint32 x,edk::uint32 y,edk::ConsoleColors color);
    bool writeChar(const edk::char8* c,edk::vec2ui32 position,edk::ConsoleColors color);

    bool writeChar(edk::char8 c,edk::uint32 x,edk::uint32 y,edk::ConsoleColors color,edk::ConsoleColors backgroundColor);
    bool writeChar(edk::char8 c,edk::vec2ui32 position,edk::ConsoleColors color,edk::ConsoleColors backgroundColor);
    bool writeChar(edk::char8* c,edk::uint32 x,edk::uint32 y,edk::ConsoleColors color,edk::ConsoleColors backgroundColor);
    bool writeChar(edk::char8* c,edk::vec2ui32 position,edk::ConsoleColors color,edk::ConsoleColors backgroundColor);
    bool writeChar(const edk::char8* c,edk::uint32 x,edk::uint32 y,edk::ConsoleColors color,edk::ConsoleColors backgroundColor);
    bool writeChar(const edk::char8* c,edk::vec2ui32 position,edk::ConsoleColors color,edk::ConsoleColors backgroundColor);

    //write the string
    bool writeString(edk::char8* str,
                     edk::uint32 x,
                     edk::uint32 y,
                     edk::uint32 width
                     );
    bool writeString(edk::char8* str,
                     edk::vec2ui32 position,
                     edk::uint32 width
                     );
    bool writeString(const edk::char8* str,
                     edk::uint32 x,
                     edk::uint32 y,
                     edk::uint32 width
                     );
    bool writeString(const edk::char8* str,
                     edk::vec2ui32 position,
                     edk::uint32 width
                     );
    bool writeString(edk::char8* str,
                     edk::uint32 x,
                     edk::uint32 y,
                     edk::uint32 width,
                     edk::uint32 height
                     );
    bool writeString(edk::char8* str,
                     edk::vec2ui32 position,
                     edk::uint32 width,
                     edk::uint32 height
                     );
    bool writeString(const edk::char8* str,
                     edk::uint32 x,
                     edk::uint32 y,
                     edk::uint32 width,
                     edk::uint32 height
                     );
    bool writeString(const edk::char8* str,
                     edk::vec2ui32 position,
                     edk::uint32 width,
                     edk::uint32 height
                     );

    bool writeString(edk::char8* str,
                     edk::uint32 x,
                     edk::uint32 y,
                     edk::uint32 width,
                     edk::ConsoleColors color
                     );
    bool writeString(edk::char8* str,
                     edk::vec2ui32 position,
                     edk::uint32 width,
                     edk::ConsoleColors color
                     );
    bool writeString(const edk::char8* str,
                     edk::uint32 x,
                     edk::uint32 y,
                     edk::uint32 width,
                     edk::ConsoleColors color
                     );
    bool writeString(const edk::char8* str,
                     edk::vec2ui32 position,
                     edk::uint32 width,
                     edk::ConsoleColors color
                     );
    bool writeString(edk::char8* str,
                     edk::uint32 x,
                     edk::uint32 y,
                     edk::uint32 width,
                     edk::uint32 height,
                     edk::ConsoleColors color
                     );
    bool writeString(edk::char8* str,
                     edk::vec2ui32 position,
                     edk::uint32 width,
                     edk::uint32 height,
                     edk::ConsoleColors color
                     );
    bool writeString(const edk::char8* str,
                     edk::uint32 x,
                     edk::uint32 y,
                     edk::uint32 width,
                     edk::uint32 height,
                     edk::ConsoleColors color
                     );
    bool writeString(const edk::char8* str,
                     edk::vec2ui32 position,
                     edk::uint32 width,
                     edk::uint32 height,
                     edk::ConsoleColors color
                     );

    bool writeString(edk::char8* str,
                     edk::uint32 x,
                     edk::uint32 y,
                     edk::uint32 width,
                     edk::ConsoleColors color,
                     edk::ConsoleColors backgroundColor
                     );
    bool writeString(edk::char8* str,
                     edk::vec2ui32 position,
                     edk::uint32 width,
                     edk::ConsoleColors color,
                     edk::ConsoleColors backgroundColor
                     );
    bool writeString(const edk::char8* str,
                     edk::uint32 x,
                     edk::uint32 y,
                     edk::uint32 width,
                     edk::ConsoleColors color,
                     edk::ConsoleColors backgroundColor
                     );
    bool writeString(const edk::char8* str,
                     edk::vec2ui32 position,
                     edk::uint32 width,
                     edk::ConsoleColors color,
                     edk::ConsoleColors backgroundColor
                     );
    bool writeString(edk::char8* str,
                     edk::uint32 x,
                     edk::uint32 y,
                     edk::uint32 width,
                     edk::uint32 height,
                     edk::ConsoleColors color,
                     edk::ConsoleColors backgroundColor
                     );
    bool writeString(edk::char8* str,
                     edk::vec2ui32 position,
                     edk::uint32 width,
                     edk::uint32 height,
                     edk::ConsoleColors color,
                     edk::ConsoleColors backgroundColor
                     );
    bool writeString(const edk::char8* str,
                     edk::uint32 x,
                     edk::uint32 y,
                     edk::uint32 width,
                     edk::uint32 height,
                     edk::ConsoleColors color,
                     edk::ConsoleColors backgroundColor
                     );
    bool writeString(const edk::char8* str,
                     edk::vec2ui32 position,
                     edk::uint32 width,
                     edk::uint32 height,
                     edk::ConsoleColors color,
                     edk::ConsoleColors backgroundColor
                     );

    //write a rectangle just in background color
    bool writeRectangle(edk::uint32 x,
                        edk::uint32 y,
                        edk::uint32 width,
                        edk::uint32 height,
                        edk::ConsoleColors backgroundColor
                        );
    bool writeRectangle(edk::vec2ui32 position,
                        edk::uint32 width,
                        edk::uint32 height,
                        edk::ConsoleColors backgroundColor
                        );
    bool writeRectangleWithShadow(edk::uint32 x,
                                  edk::uint32 y,
                                  edk::uint32 width,
                                  edk::uint32 height,
                                  edk::ConsoleColors backgroundColor
                                  );
    bool writeRectangleWithShadow(edk::vec2ui32 position,
                                  edk::uint32 width,
                                  edk::uint32 height,
                                  edk::ConsoleColors backgroundColor
                                  );
    //write a box with background and border
    bool writeBox(edk::uint32 x,
                  edk::uint32 y,
                  edk::uint32 width,
                  edk::uint32 height,
                  edk::ConsoleColors color,
                  edk::ConsoleColors backgroundColor
                  );
    bool writeBox(edk::vec2ui32 position,
                  edk::uint32 width,
                  edk::uint32 height,
                  edk::ConsoleColors color,
                  edk::ConsoleColors backgroundColor
                  );
    bool writeBoxWithShadow(edk::uint32 x,
                  edk::uint32 y,
                  edk::uint32 width,
                  edk::uint32 height,
                  edk::ConsoleColors color,
                  edk::ConsoleColors backgroundColor
                  );
    bool writeBoxWithShadow(edk::vec2ui32 position,
                  edk::uint32 width,
                  edk::uint32 height,
                  edk::ConsoleColors color,
                  edk::ConsoleColors backgroundColor
                  );
protected:
    //draw the polygon on the scene
    void runDrawScene(edk::rectf32 outsideViewOrigin);
private:
    edk::fonts::FontMap map;
    edk::fonts::FontMap back;
};
}

#endif // VIEWCONSOLE_H
