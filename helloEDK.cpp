/*
Library EDK - How to use Extensible Development Kit
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

