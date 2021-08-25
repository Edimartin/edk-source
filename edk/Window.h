#ifndef EDK_WINDOW_h
#define EDK_WINDOW_h

/*
Library C++ Window - Manipulate a window in Edk Game Engine
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
#warning "Inside Window"
#endif

#pragma once
//View to window
#include "ViewController.h"
#include "ViewGU.h"

#include "Types.h"
//Events
#include "WindowEvents.h"

//EDK WINDOW usa SFML
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#ifdef printMessages
#warning "    Compiling Window"
#endif

/*LIBS

-lsfml-window
-lsfml-graphics

*/

//Classe para gerenciamento de janelas EDK

/*
WINDOW typeID

EDK_WINDOW_BAR
EDK_WINDOW_RESIZE
EDK_WINDOW_BUTTONS
EDK_WINDOW_NOBAR
EDK_WINDOW_FULLSCREEN
*/

namespace edk {
class Window {
 public:

    Window();

    ~Window();

    bool createWindow(uint32 width, uint32 height/*, uint32 bitsPerPixel*/, char8 *name, typeID design, uint32 depth, uint32 stencil, uint32 antialiasing);

    bool createWindow(uint32 width, uint32 height/*, uint32 bitsPerPixel*/, const char *name, typeID design, uint32 depth, uint32 stencil, uint32 antialiasing);

    bool createWindow(uint32  width, uint32  height/*, uint32  bitsPerPixel*/, char8 *name, typeID design);

    bool createWindow(uint32  width, uint32  height/*, uint32  bitsPerPixel*/, const char *name, typeID  design);

    bool isOpened();

    bool isShowing();

    bool haveFocus();

    void closeWindow();

    void clean();

    edk::uint32 getViewCount();

    bool addSubview(View *addView);

    View* getSubview(uint64 n);

    uint64 getSubviewId(View *subView);

    void removeSubview(View *subView);

    void removeAllSubview();

    void windowRender(bool show);

    void showWindow();

    void hideWindow();

    void mouseRender(bool show);

    void showMouse();

    void hideMouse();

    bool setMousePosition(vec2i32 pos);

    bool setMousePosition(int32 x, int32 y);

    bool setWindowPosition(vec2i32 pos);

    bool setWindowPosition(int32 x, int32 y);

    bool setWindowSize(size2ui32 size);

    bool setWindowSize(uint32 width, uint32 height);

    //Update the views
    void updateViews();

    bool drawStart();

    bool drawEnd();

    void drawView();

    bool flip();

    bool render();

    size2ui32 getSize();

    size2ui32 getScreenSize();

    uint32 getWidth();

    uint32 getHeight();

    vec2i32 getMousePos();

    vec2i32 eventGetMouseMoved();

    bool eventLostFocus();

    bool eventGainedFocus();

    bool eventButtonClose();

    bool eventKeyPressed();

    bool eventKeyRelease();

    bool eventKeyHolded();

    uint32 eventGetKeyPressedSize();

    uint32 eventGetKeyReleaseSize();

    uint32 eventGetKeyHoldedSize();

    uint32 eventGetKeyPressed(uint32 pos);

    uint32 eventGetKeyRelease(uint32 pos);

    uint32 eventGetKeyHolded(uint32 pos);

    bool eventMousePressed();

    bool eventMouseRelease();

    bool eventMouseHolded();

    uint8 eventGetMousePressedSize();

    uint8 eventGetMouseReleaseSize();

    uint8 eventGetMouseHoldedSize();

    uint8 eventGetMousePressed(uint32 pos);

    uint8 eventGetMouseRelease(uint32 pos);

    uint8 eventGetMouseHolded(uint32 pos);

    bool eventMouseEnter();

    bool eventMouseExit();

    bool eventMouseMoved();

    int8 getMouseScrollWheel();

    bool eventResizeWindow();

    size2i32 getResize();

    bool loadEvents();

    static size2ui32 getDesktopSize();

    static uint32 getDesktopBitsPerPixel();

    //test if have a controller
    static bool haveController(edk::uint32 controller);
    //return the number of buttons of a controller
    static edk::uint32 getControllerButtonCount(edk::uint32 controller);

    bool eventControllerButtonPressed(edk::uint32 controller);

    bool eventControllerButtonRelease(edk::uint32 controller);

    bool eventControllerButtonHolded(edk::uint32 controller);

    bool eventControllerAxisMoved(edk::uint32 controller);

    uint8 eventGetControllerButtonPressedSize(edk::uint32 controller);

    uint8 eventGetControllerButtonReleaseSize(edk::uint32 controller);

    uint8 eventGetControllerButtonHoldedSize(edk::uint32 controller);

    uint8 eventGetControllerAxisMovedSize(edk::uint32 controller);

    uint8 eventGetControllerButtonPressed(edk::uint32 controller, uint32 pos);

    uint8 eventGetControllerButtonRelease(edk::uint32 controller, uint32 pos);

    uint8 eventGetControllerButtonHolded(edk::uint32 controller, uint32 pos);

    uint32 eventGetControllerAxisIDMoved(edk::uint32 controller, uint32 pos);

    float32 eventGetControllerAxisMoved(edk::uint32 controller, uint32 pos);

    float32 eventGetControllerAxisMovedByID(edk::uint32 controller, uint32 id);

 public:
    color3f32 cleanColor;
        //
    private:
        //update the viewGU
        void updateView(edk::View* viewGU);
        //contactView
        void mousePressView(edk::ViewController* view, edk::vec2i32 point, edk::vector::Stack<edk::uint32> buttons);
        void mouseReleaseView(edk::ViewController* view, edk::vec2i32 point, edk::vector::Stack<edk::uint32> buttons);

        //Atualiza o tamanho da view
        void updateViewSize();

        void cleanEvents();
        //update joystick events
        void updateControllerEvents();
        //save focus
        bool windowFocus;
        //saveMouseinside
        bool mouseInside;
        //save the mousePosition
        edk::vec2i32 saveMousePos;

        //janela SFML
        sf::RenderWindow window;
        //sf::Window window;

        //View principal
        edk::ViewController viewWindow;

        //renderiza o mouse na tela
        bool renderMouse;
        //renderiza a window na tela
        bool renderWindow;
        //Guarda se o render da janela esta ativo
        bool activeRender;

        //save the size of the window
        edk::size2ui32 windowSize;

        edk::WindowEvents events;
};

} /* End of namespace edk */

#endif // edk_Window_h
