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

//USING LIBRARIES
#if defined(_WIN32) || defined(_WIN64)
//Windows 32/64
#define EDK_USE_SFML
#undef EDK_USE_X11
#endif
#ifdef __linux__
//#define EDK_USE_X11
//#undef EDK_USE_SFML
/////////////////////////
#define EDK_USE_SFML
#undef EDK_USE_X11
/////////////////////////
#define X11_BUFFER_SIZE 12u
#endif
#ifdef __APPLE__
//MACOS
#endif

#if defined(EDK_USE_SFML)
//Windows 32/64
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
/*LIBS
-lsfml-window
-lsfml-graphics
*/
#endif
#if defined(EDK_USE_X11)
//X11
#include <GL/glx.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include <X11/Xatom.h>
//get monitors
#include <X11/extensions/Xrandr.h>
//joystick
#include <linux/joystick.h>
/*LIBS
-lX11
*/
#endif

#ifdef printMessages
#pragma message "    Compiling Window"
#endif

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

    //useOpenGL
    static bool setUseOpenGL();
    static inline bool useOpenGL(){
        return edk::Window::setUseOpenGL();
    }
    //dontUseOpenGL
    static bool setDontUseOpenGL();
    static inline bool dontUseOpenGL(){
        return edk::Window::setDontUseOpenGL();
    }
    //finishUseOpenGL
    static bool setFinishUseOpenGL();
    static inline bool finishUseOpenGL(){
        return edk::Window::setFinishUseOpenGL();
    }

    bool createWindowWithAliasing(edk::uint32 width, edk::uint32 height, edk::char8 *name, edk::typeID design, edk::uint32 depth, edk::uint32 stencil, edk::uint8 aliasing);

    bool createWindowWithAliasing(edk::uint32 width, edk::uint32 height, const char *name, edk::typeID design, edk::uint32 depth, edk::uint32 stencil, edk::uint8 aliasing);

    bool createWindowWithAliasing(edk::uint32  width, edk::uint32  height, edk::char8 *name, edk::typeID design, edk::uint8 aliasing);

    bool createWindowWithAliasing(edk::uint32  width, edk::uint32  height, const edk::char8 *name, edk::typeID  design, edk::uint8 aliasing);

    bool createWindow(edk::uint32 width, edk::uint32 height, edk::char8 *name, edk::typeID design, edk::uint32 depth, edk::uint32 stencil);

    bool createWindow(edk::uint32 width, edk::uint32 height, const edk::char8 *name, edk::typeID design, edk::uint32 depth, edk::uint32 stencil);

    bool createWindow(edk::uint32  width, edk::uint32  height, edk::char8 *name, edk::typeID design);

    bool createWindow(edk::uint32  width, edk::uint32  height, const char *name, edk::typeID  design);

    //useOpenGL
    bool setUseOpenGLInWindow();
    inline bool useOpenGLInWindow(){
        return edk::Window::setUseOpenGLInWindow();
    }
    //dontUseOpenGL
    bool setDontUseOpenGLInWindow();
    inline bool dontUseOpenGLInWindow(){
        return edk::Window::setDontUseOpenGLInWindow();
    }

    bool setWindowName(const edk::char8 *name);
    bool setWindowName(edk::char8 *name);

    bool isOpened();

    bool isShowing();

    bool haveFocus();
    bool isMinimized();

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

    //set full screen
    void setFullscreen(bool fullscreen);
    void setFullscreenOn();
    void setFullscreenOff();

    //change the design of the window
    void changeDesign(typeID design);

    void mouseRender(bool show);

    void showMouse();

    void hideMouse();

    bool setMousePosition(edk::vec2i32 pos);

    bool setMousePosition(edk::int32 x, edk::int32 y);

    static bool setMousePositionGlobal(edk::vec2i32 pos);

    static bool setMousePositionGlobal(edk::int32 x, edk::int32 y);

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

    edk::vec2i32 getPos();

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

    //get the size of connected controllers
    static edk::uint32 getControllersSize();
    //get the size of connected controllers
    static edk::uint32 getControllerIdInPosition(edk::uint32 position);

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
#if defined(EDK_USE_SFML)
    color3f32 cleanColor;
#endif
#if defined(EDK_USE_X11)
    edk::color4f32 cleanColor;
#endif
    //
private:
    //update the viewGU
    void updateView(edk::View* viewGU,edk::vec2f32 screenPosition);
    //contactView
    void mousePressView(edk::ViewController* view, edk::vec2i32 point, edk::vector::Stack<edk::uint32> buttons);
    void mouseReleaseView(edk::ViewController* view, edk::vec2i32 point, edk::vector::Stack<edk::uint32> buttons);
    void mouseDoubleClickView(edk::ViewController* view, edk::vec2i32 point, edk::vector::Stack<edk::uint32> buttons);

#if defined(EDK_USE_SFML)
#endif
#if defined(EDK_USE_X11)
    //create a new GC
    bool newGC();
    //set the window colors
    void setColorForeground(edk::color4f32 color);
    void setColorForegroundF32(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a=1.f);
    void setColorForegroundUI8(edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a=255u);
    void setColorForeground(edk::uint32 color);
    void setColorBackground(edk::color4f32 color);
    void setColorBackgroundF32(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a=1.f);
    void setColorBackgroundUI8(edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a=255u);
    void setColorBackground(edk::uint32 color);
    //update the position and size
    void updatePositionAndSize();
    //load the window attributes
    void loadWindowAttributes(bool* resize=NULL, edk::size2i32* resizePosition=NULL
            ,bool* move=NULL, edk::vec2i32* movePosition=NULL
            );
#endif

    //Atualiza o tamanho da view
    void updateViewSize();

    void cleanEvents();
    void cleanEventsMouse();
    //update joystick events
    void updateControllerEvents();
    //save focus
    bool windowFocus;
    //save minimized
    bool windowMinimized;
    //save grab window
    bool windowGrab;
    //saveMouseinside
    bool mouseInside;
    //save the mousePosition
    edk::vec2i32 saveMousePos;

#if defined(EDK_USE_SFML)
    //janela SFML
    sf::RenderWindow window;
    //sf::Window window;
#endif

    //window aliasing value 2, 4, 8 or 16.
    edk::uint8 aliasing;
    edk::size2i32 windowSizeIncrement;

#if defined(EDK_USE_X11)
    //save the mousePositionGlobal
    edk::vec2i32 saveMousePosGlobal;
    //save the design of the window to change in the future
    edk::typeID saveDesign;

    //X11
    //display status
    static edk::uint64 displayBlack;
    static edk::uint64 displayWhite;
    static edk::int32 displayNumberOfScreens;
    static edk::int32 displayScreen;
    static edk::int32 displayDepth;
    static edk::size2ui32 displaySize;

    static XRRMonitorInfo	*m;

    edk::char8 buffer[X11_BUFFER_SIZE];
    KeySym keysym;
    Status status;
    //X11 Window
    XID window;
    XIM xim;
    XIC xic;
    //GC
    GC gc;
    //Image
    XImage *image;
    //pixmap
    Pixmap pixmap;
    //configuration of openGL in the window
    GLXFBConfig fb_config;
    GLXContext context;

    //MOUSE BUTTONS
    //KEYS
    edk::uchar8 keyCodesBits1[32u];
    edk::uchar8 keyCodesBits2[32u];
    edk::uchar8* keyCodesBitsNow;
    edk::uchar8* keyCodesBitsLast;
    edk::uchar8* keyCodesBitsChange;

    struct XlibHints{
        edk::uint64 flags;
        edk::uint64 functions;
        edk::uint64 decorations;
    }hints;

    //save if the window is open
    bool opened;

    //windows name
    edk::Name windowName;

    //window position
    edk::vec2i32 windowPosition;
    edk::vec2i32 viewPosition;

    //save the size of the window
    edk::size2ui32 windowRealSize;
    edk::size2ui32 viewSize;

    //window depth
    edk::uint32 windowDepth;

    bool haveSaveWindowDesign;
    edk::vec2i32 saveWindowDesignPosition;
    edk::size2ui32 saveWindowDesignSize;

#endif
    //save the controller holded
    edk::WindowEvents::ControllerButtonsEvent saveControllerHolded;
    edk::size2ui32 windowSize;
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
            this->canUpdateThis=false;
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

    edk::WindowEvents events;
    class SaveHolded{
    public:
        SaveHolded(){
            this->id=0u;
            this->count=0u;
        }
        SaveHolded(edk::uint32 id){
            this->id=id;
            this->count=0u;
        }
        ~SaveHolded(){}

        inline bool operator==(edk::Window::SaveHolded position){
            if(this->id == position.id){ return true; }
            return false;
        }
        inline bool operator>(edk::Window::SaveHolded position){
            if(this->id > position.id){ return true; }
            return false;
        }
        inline edk::Window::SaveHolded operator=(edk::Window::SaveHolded position){
            this->id = position.id;
            this->count = position.count;
            return *this;
        }
        edk::uint32 id;
        edk::uint8 count;
    };
    class TreeSaveHolded: public edk::vector::BinaryTree<edk::Window::SaveHolded>{
    public:
        TreeSaveHolded(){}
        ~TreeSaveHolded(){}
        virtual bool firstBiggerSecond(edk::Window::SaveHolded first,edk::Window::SaveHolded second){
            if(first.id>second.id){
                return true;
            }
            return false;
        }
        //compare if the value is equal
        virtual bool firstEqualSecond(edk::Window::SaveHolded first,edk::Window::SaveHolded second){
            if(first.id==second.id){
                return true;
            }
            return false;
        }

        //UPDATE
        virtual void updateElementWithPointer(edk::Window::SaveHolded* value){
            if(value->count){
                value->count--;
            }
            else{
                this->st.pushBack(value->id);
            }
        }
        //update the elements
        virtual void updateWithPointer(){
            edk::vector::BinaryTree<edk::Window::SaveHolded>::updateWithPointer();
            edk::uint32 size = this->st.size();
            for(edk::uint32 i=0u;i<size;i++){
                this->removeHolded(this->st.get(i));
            }
            this->st.clean();
        }

        bool addHolded(edk::Window::SaveHolded holded){
            return this->add(holded);
        }
        bool addHolded(edk::uint32 id){
            if(this->haveHolded(id)){
                this->incrementHolded(id,20u);
                return true;
            }
            if(this->add(edk::Window::SaveHolded(id))){
                this->incrementHolded(id,50u);
                return true;
            }
            return false;
        }
        bool removeHolded(edk::uint32 id){
            return this->remove(edk::Window::SaveHolded(id));
        }
        bool haveHolded(edk::uint32 id){
            edk::Window::SaveHolded temp(id);
            return this->haveElement(temp);
        }
        edk::uint32 getHoldedCount(edk::uint32 id){
            edk::Window::SaveHolded temp(id);
            return this->getElement(temp).count;
        }
        edk::uint32 getHoldedInPosition(edk::uint32 position){
            edk::Window::SaveHolded temp = this->getElementInPosition(position);
            return temp.id;
        }
        bool incrementHolded(edk::uint32 id){
            edk::Window::SaveHolded temp(id);
            edk::Window::SaveHolded tempAdd;
            tempAdd = this->getElement(temp);
            if(tempAdd.id == id){
                if(this->remove(tempAdd)){
                    if(tempAdd.count<100u) tempAdd.count++;
                    if(this->add(tempAdd)){
                        return true;
                    }
                }
            }
            return false;
        }
        bool incrementHolded(edk::uint32 id,edk::uint32 value){
            if(value){
                edk::Window::SaveHolded temp(id);
                edk::Window::SaveHolded tempAdd;
                tempAdd = this->getElement(temp);
                if(tempAdd.id == id){
                    if(this->remove(tempAdd)){
                        if(tempAdd.count<100u) tempAdd.count=value;
                        if(this->add(tempAdd)){
                            return true;
                        }
                    }
                }
            }
            return false;
        }
    private:
        edk::vector::Stack<edk::uint32> st;
    }saveMouseHolded, saveKeyHolded;
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
