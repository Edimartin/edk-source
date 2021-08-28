/*
Library EDK - How to use Game Controller on Extensible Development Kit
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
#include "edk/shape/Mesh2D.h"
#include "edk/shape/Rectangle2D.h"
#include "edk/Object2D.h"

#define buttonsSize 11u
#define axisSize 4u

class RenderView: public edk::ViewGU2D{
public:
    RenderView(){}
    ~RenderView(){}
    void load(edk::rectf32){
        this->camera.position.x = -0.5f;
        this->camera.position.y = -2.5f;
        this->camera.setSize(18.f,17.f);
        //create the message
        edk::shape::Mesh2D* mesh=NULL;
        edk::shape::Rectangle2D rect;
        rect.setPivoToCenter();
        //load the buttons
        for(edk::uint32 i=0u;i<buttonsSize;i++){
            mesh = &this->meshs1[i];
            if(mesh){
                this->buttons1[i].addMesh(mesh);
                //add the polygon
                mesh->addPolygon(rect);
                mesh->material.setEmission(1.f,0.0f,0.0f,1.f);
            }
            mesh = &this->meshs2[i];
            if(mesh){
                this->buttons2[i].addMesh(mesh);
                //add the polygon
                mesh->addPolygon(rect);
                mesh->material.setEmission(1.f,0.0f,0.0f,1.f);
            }
            //set the button position
            this->buttons1[i].position.x = (1.5f * i)-8.0f;
            this->buttons1[i].position.y = 0;
            this->buttons2[i].position.x = (1.5f * i)-8.0f;
            this->buttons2[i].position.y = -4;
        }

        mesh=this->analogic1[0u].newMesh();
        if(mesh){
            mesh->addPolygon(rect);
            mesh->material.setEmission(0.f,1.f,0.f,1.f);
            this->analogic1[0].position.x = -4.5;
            this->analogic1[0].position.y = -2.0;
            for(edk::uint32 i=1u;i<axisSize;i++){
                this->analogic1[i].addMesh(mesh);

                //set the position
                this->analogic1[i].position.x = (2.5f * i) - 4.5;
                this->analogic1[i].position.y = - 2.0;
            }
        }
        mesh=this->analogic2[0u].newMesh();
        if(mesh){
            mesh->addPolygon(rect);
            mesh->material.setEmission(0.f,1.f,0.f,1.f);
            this->analogic2[0].position.x = -4.5;
            this->analogic2[0].position.y = 2;
            for(edk::uint32 i=1u;i<axisSize;i++){
                this->analogic2[i].addMesh(mesh);

                //set the position
                this->analogic2[i].position.x = (2.5f * i) - 4.5;
                this->analogic2[i].position.y = 2;
            }
        }
    }
    void unload(){
        //remove the message
        for(edk::uint32 i=0u;i<buttonsSize;i++){
            this->buttons1[i].cleanMeshes();
            this->buttons2[i].cleanMeshes();
        }
        for(edk::uint32 i=0u;i<axisSize;i++){
            this->analogic1[i].cleanMeshes();
            this->analogic2[i].cleanMeshes();
        }
    }
    void update(edk::WindowEvents* events){
        if(edk::Window::haveController(0u)){
            //printf("\nController 0 is connected buttonCount %u  %u",edk::Window::getControllerButtonCount(0u),this->count++);
        }


        //clean the button colors
        for(edk::uint32 i=0u;i<buttonsSize;i++){
            this->meshs1[i].material.setEmission(1.f,0.0f,0.0f,1.f);
            this->meshs2[i].material.setEmission(1.f,0.0f,0.0f,1.f);
        }

        //CONTROLLERS
        edk::uint32 controllersSize = events->controllerPressed.getControllerSize();
        edk::uint32 controllersId = 0u;
        edk::uint32 buttonSize=0u;
        edk::uint32 buttonId=0u;
        //pressed
        for(edk::uint32 i=0u;i<controllersSize;i++){
            buttonSize = events->controllerPressed.getControllerButtonSizeInPosition(i);
            controllersId = events->controllerPressed.getControllerIDInPosition(i);
            for(edk::uint32 j=0u;j<buttonSize;j++){
                //print the button

                printf("\nController %u button %u pressed"
                       ,controllersId
                       ,events->controllerPressed.getControllerButtonInPosition(i,j)
                       );fflush(stdout);

            }
        }
        //holded
        controllersSize = events->controllerHolded.getControllerSize();
        for(edk::uint32 i=0u;i<controllersSize;i++){
            buttonSize = events->controllerHolded.getControllerButtonSizeInPosition(i);
            controllersId = events->controllerHolded.getControllerIDInPosition(i);
            for(edk::uint32 j=0u;j<buttonSize;j++){
                //print the button
/*
                    printf("\nController %u button %u holded"
                           ,controllersId
                           ,events->controllerHolded.getControllerButtonInPosition(i,j)
                           );fflush(stdout);
*/
                //test if have the button
                buttonId = events->controllerHolded.getControllerButtonInPosition(i,j);
                switch(controllersId){
                case 0u:
                    if(buttonId<buttonsSize){
                        //change the mesh color
                        this->meshs2[buttonId].material.setEmission(1.f,0.5f,0.5f,1.f);
                    }
                    break;
                case 1u:
                    if(buttonId<buttonsSize){
                        //change the mesh color
                        this->meshs1[buttonId].material.setEmission(1.f,0.5f,0.5f,1.f);
                    }
                    break;
                }
            }
        }
        //released
        controllersSize = events->controllerReleased.getControllerSize();
        for(edk::uint32 i=0u;i<controllersSize;i++){
            buttonSize = events->controllerReleased.getControllerButtonSizeInPosition(i);
            controllersId = events->controllerReleased.getControllerIDInPosition(i);
            for(edk::uint32 j=0u;j<buttonSize;j++){
                //print the button
/*
                    printf("\nController %u button %u released"
                           ,controllersId
                           ,events->controllerReleased.getControllerButtonInPosition(i,j)
                           );fflush(stdout);
*/
            }
        }
        //axis
        controllersSize = events->controllerAxisMoved.getControllerSize();
        for(edk::uint32 i=0u;i<controllersSize;i++){
            buttonSize = events->controllerAxisMoved.getControllerButtonSizeInPosition(i);
            controllersId = events->controllerAxisMoved.getControllerIDInPosition(i);
            for(edk::uint32 j=0u;j<buttonSize;j++){
                //print the button
/*
                    printf("\nController %u Axis %u moveTo %.2f"
                           ,controllersId
                           ,events->controllerAxisMoved.getControllerAxisInPosition(i,j)
                           ,events->controllerAxisMoved.getControllerAxisValueInPosition(i,j)
                           );fflush(stdout);
*/
                buttonId = events->controllerAxisMoved.getControllerAxisInPosition(i,j);
                //test if is the zero or one
                switch(controllersId){
                case 0u:
                    switch(buttonId){
                    case 0u:
                        //set the value
                        this->analogic1[0u].position.x = (events->controllerAxisMoved.getControllerAxisValueInPosition(i,j)/100.f)+(2.5f * 0u) - 4.5;
                        break;
                    case 1u:
                        this->analogic1[0u].position.y = (events->controllerAxisMoved.getControllerAxisValueInPosition(i,j)/100.f)-2.0f;
                        break;
                    case 2u:
                        //set the value
                        this->analogic1[1u].position.x = (events->controllerAxisMoved.getControllerAxisValueInPosition(i,j)/100.f)+(2.5f * 1u) - 4.5;
                        break;
                    case 3u:
                        this->analogic1[1u].position.y = (events->controllerAxisMoved.getControllerAxisValueInPosition(i,j)/100.f)-2.0f;
                        break;
                    case 4u:
                        //set the value
                        this->analogic1[2u].position.x = (events->controllerAxisMoved.getControllerAxisValueInPosition(i,j)/100.f)+(2.5f * 2u) - 4.5;
                        break;
                    case 5u:
                        this->analogic1[2u].position.y = (events->controllerAxisMoved.getControllerAxisValueInPosition(i,j)/100.f)-2.0f;
                        break;
                    case 6u:
                        //set the value
                        this->analogic1[3u].position.x = (events->controllerAxisMoved.getControllerAxisValueInPosition(i,j)/100.f)+(2.5f * 3u) - 4.5;
                        break;
                    case 7u:
                        this->analogic1[3u].position.y = (events->controllerAxisMoved.getControllerAxisValueInPosition(i,j)/100.f)-2.0f;
                        break;
                    }
                    break;
                case 1u:
                    switch(buttonId){
                    case 0u:
                        //set the value
                        this->analogic2[0u].position.x = (events->controllerAxisMoved.getControllerAxisValueInPosition(i,j)/100.f)+(2.5f * 0u) - 4.5;
                        break;
                    case 1u:
                        this->analogic2[0u].position.y = (events->controllerAxisMoved.getControllerAxisValueInPosition(i,j)/100.f)+2;
                        break;
                    case 2u:
                        //set the value
                        this->analogic2[1u].position.x = (events->controllerAxisMoved.getControllerAxisValueInPosition(i,j)/100.f)+(2.5f * 1u) - 4.5;
                        break;
                    case 3u:
                        this->analogic2[1u].position.y = (events->controllerAxisMoved.getControllerAxisValueInPosition(i,j)/100.f)+2;
                        break;
                    case 4u:
                        //set the value
                        this->analogic2[2u].position.x = (events->controllerAxisMoved.getControllerAxisValueInPosition(i,j)/100.f)+(2.5f * 2u) - 4.5;
                        break;
                    case 5u:
                        this->analogic2[2u].position.y = (events->controllerAxisMoved.getControllerAxisValueInPosition(i,j)/100.f)+2;
                        break;
                    case 6u:
                        //set the value
                        this->analogic2[3u].position.x = (events->controllerAxisMoved.getControllerAxisValueInPosition(i,j)/100.f)+(2.5f * 3u) - 4.5;
                        break;
                    case 7u:
                        this->analogic2[3u].position.y = (events->controllerAxisMoved.getControllerAxisValueInPosition(i,j)/100.f)+2;
                        break;
                    }
                    break;
                }
            }
        }
    }
    //render the scene in the vew
    void drawScene(edk::rectf32){
        //draw the message
        for(edk::uint32 i=0u;i<buttonsSize;i++){
            this->buttons1[i].draw();
            this->buttons2[i].draw();
        }
        for(edk::uint32 i=0u;i<axisSize;i++){
            this->analogic1[i].draw();
            this->analogic2[i].draw();
        }
    }
private:
    edk::Object2D buttons1[buttonsSize];
    edk::Object2D buttons2[buttonsSize];
    edk::shape::Mesh2D meshs1[buttonsSize];
    edk::shape::Mesh2D meshs2[buttonsSize];

    edk::Object2D analogic1[axisSize];
    edk::Object2D analogic2[axisSize];
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
    view.frame.origin = edk::vec2f32(0,0);        //set the view position inside the Window View
    view.frame.size = edk::size2f32(800,800);       //set the size of the View

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

        //test the key on the terminal
        if(edk::String::consoleKeyPressed())if(edk::String::consoleReadKey()==27)win.closeWindow();

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
