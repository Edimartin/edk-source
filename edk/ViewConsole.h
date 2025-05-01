#ifndef VIEWCONSOLE_H
#define VIEWCONSOLE_H

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
#pragma message "Inside ViewConsole"
#endif

#include "edk/ViewGU.h"

#include "edk/fonts/FontMap.h"

#ifdef printMessages
#pragma message "    Compiling ViewConsole"
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
    virtual ~ViewConsole();

    void Constructor();
    void Destructor();

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

    //write a scroll bar in the console
    bool writeScrollBarVertical(edk::uint32 x,
                                edk::uint32 y,
                                edk::uint32 lenght,
                                edk::uint32 barPosition,
                                edk::uint32 barLenght,
                                edk::ConsoleColors color,
                                edk::ConsoleColors backgroundColor
                                );
    bool writeScrollBarVertical(edk::vec2ui32 position,
                                edk::uint32 lenght,
                                edk::uint32 barPosition,
                                edk::uint32 barLenght,
                                edk::ConsoleColors color,
                                edk::ConsoleColors backgroundColor
                                );
    bool writeScrollBarHorizontal(edk::uint32 x,
                                  edk::uint32 y,
                                  edk::uint32 lenght,
                                  edk::uint32 barPosition,
                                  edk::uint32 barLenght,
                                  edk::ConsoleColors color,
                                  edk::ConsoleColors backgroundColor
                                  );
    bool writeScrollBarHorizontal(edk::vec2ui32 position,
                                  edk::uint32 lenght,
                                  edk::uint32 barPosition,
                                  edk::uint32 barLenght,
                                  edk::ConsoleColors color,
                                  edk::ConsoleColors backgroundColor
                                  );
    //write a scroll bar in the console with percent
    bool writeScrollBarVertical(edk::uint32 x,
                                edk::uint32 y,
                                edk::uint32 lenght,
                                edk::float32 barPosition,
                                edk::float32 barLenght,
                                edk::ConsoleColors color,
                                edk::ConsoleColors backgroundColor
                                );
    bool writeScrollBarVertical(edk::vec2ui32 position,
                                edk::uint32 lenght,
                                edk::float32 barPosition,
                                edk::float32 barLenght,
                                edk::ConsoleColors color,
                                edk::ConsoleColors backgroundColor
                                );
    bool writeScrollBarHorizontal(edk::uint32 x,
                                  edk::uint32 y,
                                  edk::uint32 lenght,
                                  edk::float32 barPosition,
                                  edk::float32 barLenght,
                                  edk::ConsoleColors color,
                                  edk::ConsoleColors backgroundColor
                                  );
    bool writeScrollBarHorizontal(edk::vec2ui32 position,
                                  edk::uint32 lenght,
                                  edk::float32 barPosition,
                                  edk::float32 barLenght,
                                  edk::ConsoleColors color,
                                  edk::ConsoleColors backgroundColor
                                  );
protected:
    //draw the polygon on the scene
    void runDrawScene(edk::rectf32 outsideViewOrigin);
private:
    edk::fonts::FontMap map;
    edk::fonts::FontMap back;
private:
    edk::classID classThis;
};
}

#endif // VIEWCONSOLE_H
