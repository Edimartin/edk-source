/*
Library EDK - How to use Extensible Development Kit
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

//Include the Window
#include "edk/Window.h"
//Include the View to render Graphics
#include "edk/ViewGU2D.h"
//Include the FontMap render
#include "edk/fonts/FontMap.h"

class RenderView: public edk::ViewGU2D{
public:
    RenderView(){}
    ~RenderView(){}
    void load(edk::rectf32){
        this->camera.position.x = 7;
        this->camera.position.y = -0.5f;
        this->camera.setSize(16.f,10.f);
        //create the message
        text.createStringMap("Hello EDK World");
        text.setColor(0.f,0.f,0.f,1.f);
    }
    void unload(){
        //remove the message
        text.deleteMap();
    }
    //render the scene in the vew
    void drawScene(edk::rectf32){
        //draw the message
        text.draw();
    }
private:
    edk::fonts::FontMap text;
};

int main(){
    edk::Window win;
    //create the window with the buttons
    win.createWindow(800,600,"EDK HELLO WORLD",EDK_WINDOW_BUTTONS);
    //set the background color fo the window
    win.cleanColor = edk::color3ui8(0,0,0);

    //Create a view to draw the scene
    RenderView view;
    view.backgroundColor = edk::color4f32(1,1,1,1); //set the viewColor
    view.frame.origin = edk::vec2f32(50,50);        //set the view position inside the Window View
    view.frame.size = edk::size2f32(700,500);       //set the size of the View

    //add the view in the Window
    win.addSubview(&view);

    //Loop
    while(win.isOpened()){
        //Clean the Windows
        win.clean();
        //load the Window Events
        win.loadEvents();
        //update the Views with the events pre-loaded
        win.updateViews();

        //check if click to close de Window
        if(win.eventButtonClose()){
            //close the window
            win.closeWindow();
        }
        //test if release the ESC key
        if(win.eventGetKeyReleaseSize()){
            for(edk::uint32 i=0u;i<win.eventGetKeyReleaseSize();i++){
                if(win.eventGetKeyRelease(i) == edk::key::escape){
                    //close Window
                    win.closeWindow();
                }
            }
        }
        //draw the View's
        win.drawView();
        //render the scene
        win.render();
    }
    //remove the view from window
    win.removeSubview(&view);
    return 0;
}

