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
#pragma message "Inside Window"
#endif

#pragma once
//View to window
#include "ViewGU.h"
#include "vector/Queue.h"
#include "ViewController.h"
#include "edk/watch/Time.h"

#include "Types.h"
//Events
#include "WindowEvents.h"

#include "edk/Object2D.h"
#include "edk/ViewGU2D.h"

//EDK WINDOW usa SFML
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

#ifdef printMessages
#pragma message "    Compiling Window"
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

    virtual ~Window();

    void Constructor();
    void Destructor();

    bool createWindow(edk::uint32 width, edk::uint32 height/*, edk::uint32 bitsPerPixel*/, char8 *name, typeID design, edk::uint32 depth, edk::uint32 stencil, edk::uint32 antialiasing);

    bool createWindow(edk::uint32 width, edk::uint32 height/*, edk::uint32 bitsPerPixel*/, const char *name, typeID design, edk::uint32 depth, edk::uint32 stencil, edk::uint32 antialiasing);

    bool createWindow(edk::uint32  width, edk::uint32  height/*, edk::uint32  bitsPerPixel*/, char8 *name, typeID design);

    bool createWindow(edk::uint32  width, edk::uint32  height/*, edk::uint32  bitsPerPixel*/, const char *name, typeID  design);

    bool setWindowName(const edk::char8 *name);
    bool setWindowName(edk::char8 *name);

    bool isOpened();

    bool isShowing();

    bool haveFocus();

    void closeWindow();

    void setVSYNC(bool vsync);
    void enableVSYNC();
    void disableVSYNC();
    bool isUsingVSYNC();

    void clean();

    edk::uint32 getViewCount();

    bool addSubview(edk::View *addView);

    View* getSubview(edk::uint64 n);

    edk::uint64 getSubviewId(edk::View *subView);

    void removeSubview(edk::View *subView);

    void removeAllSubview();

    void windowRender(bool show);

    void showWindow();

    void hideWindow();

    void mouseRender(bool show);

    void showMouse();

    void hideMouse();

    bool setMousePosition(edk::vec2i32 pos);

    bool setMousePosition(edk::int32 x, edk::int32 y);

    bool setWindowPosition(edk::vec2i32 pos);

    bool setWindowPosition(edk::int32 x, edk::int32 y);

    bool setWindowSize(edk::size2ui32 size);

    bool setWindowSize(edk::uint32 width, edk::uint32 height);

    //Update the views
    void updateViews();

    bool drawStart();

    bool drawEnd();

    void drawView();

    void runPauseSwitchViews();

    void runPauseViews();
    void pauseViews();

    void runUnpauseViews();
    void unpauseViews();

    bool isPaused();

    bool flip();

    bool render();

    edk::size2ui32 getSize();

    edk::size2ui32 getScreenSize();

    edk::uint32 getWidth();

    edk::uint32 getHeight();

    edk::vec2i32 getMousePos();

    edk::vec2i32 eventGetMouseMoved();

    /*
    eventWindowButtonExit
    eventWindowLostFocus
    eventWindowGainedFocus
    eventWindowResize
    eventWindowMouseMoved
    eventWindowMouseEnter
    eventWindowMouseExit
    eventWindowResizePos
    eventWindowWindowSize
    eventWindowMousePos
    eventWindowMousePosWorld
    eventWindowMousePosWindow
    eventWindowMouseMove
    eventWindowKeyPressed
    eventWindowKeyRelease
    eventWindowKeyHolded
    eventWindowKeyText
    eventWindowMousePressed
    eventWindowMouseRelease
    eventWindowMouseHolded
    eventWindowMouseDoubleClick
    eventWindowMouseScrollWheel
    eventWindowSecondPassed
    eventWindowSecondsGlobal
    eventWindowControllerPressed
    eventWindowControllerHolded
    eventWindowControllerReleased
    eventWindowControllerAxisMoved
*/
    //test if the events have something
    bool eventsHaveSomething();
    bool haveSomethingTypes(edk::EventWindowType types, ...);

    //start writing events into a file
    bool startWriteEvents(edk::char8* fileName);
    bool startWriteEvents(const edk::char8* fileName);
    bool startWriteEvents(edk::char8* fileName,edk::EventWindowType types, ...);
    bool startWriteEvents(const edk::char8* fileName,edk::EventWindowType types, ...);
    //start reading events from a file
    bool startReadEvents(edk::char8* fileName);
    bool startReadEvents(const edk::char8* fileName);
    //get the events status
    bool isWritingEventsFile();
    bool isReadingEventsFile();
    bool isPlayingWriteEventsFile();
    bool isPlayingReadEventsFile();

    //stop writing the events into a file
    void stopWriteEvents();
    //stop reading the events from a file
    void stopReadEvents();

    //pause file events
    void pauseFileEvents();
    bool pauseWriteEvents();
    bool pauseReadEvents();
    void unpauseFileEvents();
    bool unpauseWriteEvents();
    bool unpauseReadEvents();
    bool isPausedFileEvents();
    bool isPausedWriteEvents();
    bool isPausedReadEvents();

    //print events
    void eventsPrint();

    //print events
    void printEvents();

    bool eventLostFocus();

    bool eventGainedFocus();

    bool eventButtonClose();

    bool eventKeyPressed();

    bool eventKeyRelease();

    bool eventKeyHolded();

    edk::uint32 eventGetKeyPressedSize();

    edk::uint32 eventGetKeyReleaseSize();

    edk::uint32 eventGetKeyHoldedSize();

    edk::uint32 eventGetKeyPressed(edk::uint32 pos);

    edk::uint32 eventGetKeyRelease(edk::uint32 pos);

    edk::uint32 eventGetKeyHolded(edk::uint32 pos);

    bool eventMousePressed();

    bool eventMouseRelease();

    bool eventMouseDoubleClick();

    bool eventMouseHolded();

    edk::uint8 eventGetMousePressedSize();

    edk::uint8 eventGetMouseReleaseSize();

    edk::uint8 eventGetMouseDoubleClickSize();

    edk::uint8 eventGetMouseHoldedSize();

    edk::uint8 eventGetMousePressed(edk::uint32 pos);

    edk::uint8 eventGetMouseRelease(edk::uint32 pos);

    edk::uint8 eventGetMouseDoubleClick(edk::uint32 pos);

    edk::uint8 eventGetMouseHolded(edk::uint32 pos);

    bool eventMouseEnter();

    bool eventMouseExit();

    bool eventMouseMoved();

    edk::int8 getMouseScrollWheelVertical();
    edk::int8 getMouseScrollWheelHorizontal();

    bool eventResizeWindow();

    edk::size2i32 getResize();

    //set and get the second passed
    bool setSecondPassedBeforeLoadEvents(edk::float32 seconds);
    bool setSecondPassedAfterLoadEvents(edk::float32 seconds);
    edk::float32 eventGetSecondPassed();

    bool loadEvents();

    static edk::size2ui32 getDesktopSize();

    static edk::uint32 getDesktopBitsPerPixel();

    //test if have a controller
    static bool haveController(edk::uint32 controller);
    //return the number of buttons of a controller
    static edk::uint32 getControllerButtonCount(edk::uint32 controller);

    bool eventControllerButtonPressed(edk::uint32 controller);

    bool eventControllerButtonRelease(edk::uint32 controller);

    bool eventControllerButtonHolded(edk::uint32 controller);

    bool eventControllerAxisMoved(edk::uint32 controller);

    edk::uint8 eventGetControllerButtonPressedSize(edk::uint32 controller);

    edk::uint8 eventGetControllerButtonReleaseSize(edk::uint32 controller);

    edk::uint8 eventGetControllerButtonHoldedSize(edk::uint32 controller);

    edk::uint8 eventGetControllerAxisMovedSize(edk::uint32 controller);

    edk::uint8 eventGetControllerButtonPressed(edk::uint32 controller, edk::uint32 pos);

    edk::uint8 eventGetControllerButtonRelease(edk::uint32 controller, edk::uint32 pos);

    edk::uint8 eventGetControllerButtonHolded(edk::uint32 controller, edk::uint32 pos);

    edk::uint32 eventGetControllerAxisIDMoved(edk::uint32 controller, edk::uint32 pos);

    float32 eventGetControllerAxisMoved(edk::uint32 controller, edk::uint32 pos);

    float32 eventGetControllerAxisMovedByID(edk::uint32 controller, edk::uint32 id);

public:
    color3f32 cleanColor;
    //
private:
    //update the viewGU
    void updateView(edk::View* viewGU,edk::vec2f32 screenPosition);
    //contactView
    void mousePressView(edk::ViewController* view, edk::vec2i32 point, edk::vector::Stack<edk::uint32> buttons);
    void mouseReleaseView(edk::ViewController* view, edk::vec2i32 point, edk::vector::Stack<edk::uint32> buttons);
    void mouseDoubleClickView(edk::ViewController* view, edk::vec2i32 point, edk::vector::Stack<edk::uint32> buttons);

    //Atualiza o tamanho da view
    void updateViewSize();

    void cleanEvents();
    void cleanEventsMouse();
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

    bool vsync;

    //View principal
    edk::ViewController viewWindow;
    class ViewMouseDebug: public edk::ViewGU2D{
    public:
        ViewMouseDebug(){}
        ~ViewMouseDebug(){}

        void resize(edk::rectf32 outsideViewOrigin){
            this->frame=outsideViewOrigin;
        }
        void load(edk::rectf32 /*outsideViewOrigin*/){
            this->canUpdate=false;
            //
            this->backgroundColor = edk::color4f32(1.f,1.f,1.f,0.25f);
        }
        void drawScene(edk::rectf32 /*outsideViewOrigin*/){
            this->camera.setRectPoints(this->frame.origin.x,
                                       this->frame.origin.y,
                                       this->frame.origin.x + this->frame.size.width,
                                       this->frame.origin.x + this->frame.size.height
                                       );
            //
            this->objMouse.drawPivo(this->camera.getSize().height,
                                    0.f,0.f,0.f
                                    );
        }

        edk::Object2D objMouse;
    }viewMouse;

    //renderiza o mouse na tela
    bool renderMouse;
    //renderiza a window na tela
    bool renderWindow;
    //Guarda se o render da janela esta ativo
    bool activeRender;

    //edkTime to count the passed time since the last frame
    edk::watch::Time time;

    //save the size of the window
    edk::size2ui32 windowSize;

    edk::WindowEvents events;
#if defined(EDK_WINDOW_EVENTS_RW)
    edk::WindowEvents saveEvents;
    bool saveHaveEvents;
    //file to write the windowEvents
    edk::File fileEvents;
    bool playingWriteEvents;
    bool playingReadEvents;
    bool pausedFileEvents;
    edk::float32 secondEvents;
    edk::float32 nextSecondEvents;
    //eventTypes to be writed in the file
    edk::vector::BinaryTree<edk::EventWindowType> treeEventTypes;
#endif
private:
    edk::classID classThis;
};

}//End of namespace edk

#endif // edk_Window_h
