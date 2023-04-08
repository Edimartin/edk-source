#include "Window.h"

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
#pragma message "            Inside Window.cpp"
#endif

//PRIVATE
//Atualiza o tamanho da view
void edk::Window::updateViewSize(){
    //seta o tamanho da view
    this->viewWindow.animatedFrame = this->viewWindow.frame=edk::rectf32(0.f,0.f,(edk::float32)this->getScreenSize().width,(edk::float32)this->getScreenSize().height);edkEnd();
}

void edk::Window::cleanEvents(){
    //
    this->events.clean();edkEnd();
}
//update joystick events
void edk::Window::updateControllerEvents(){
    edk::uint32 controllers = this->events.controllerPressed.getControllerSize();edkEnd();
    edk::uint32 controllerID = 0u;edkEnd();
    edk::uint32 buttons = 0u;edkEnd();
    edk::uint32 buttonID=0u;
    for(edk::uint32 i=0u;i<controllers;i++){
        //load the controllerID
        controllerID = this->events.controllerPressed.getControllerIDInPosition(i);edkEnd();
        if(sf::Joystick::isConnected(controllerID)){
            //load the buttons size
            buttons = this->events.controllerPressed.getControllerButtonSizeInPosition(i);edkEnd();
            for(edk::uint32 j=0u;j<buttons;j++){
                buttonID = this->events.controllerPressed.getControllerButtonByID(controllerID,j);edkEnd();
                if(sf::Joystick::isButtonPressed(controllerID,buttonID)){
                    //copy the button to the holded
                    this->events.controllerHolded.addButton(controllerID,buttonID);edkEnd();
                }
            }
        }
        else{
            //else clean the controller
            this->events.controllerHolded.cleanControllerButtonsByID(controllerID);edkEnd();
        }
    }
    //test if is holding the buttons
    controllers = this->events.controllerHolded.getControllerSize();edkEnd();
    for(edk::uint32 i=0u;i<controllers;i++){
        //load the controllerID
        controllerID = this->events.controllerHolded.getControllerIDInPosition(i);edkEnd();
        if(sf::Joystick::isConnected(controllerID)){
            //load the buttons size
            buttons = this->events.controllerHolded.getControllerButtonSizeInPosition(i);edkEnd();
            for(edk::uint32 j=0u;j<buttons;j++){
                buttonID = this->events.controllerHolded.getControllerButtonByID(controllerID,j);edkEnd();
                if(!sf::Joystick::isButtonPressed(controllerID,buttonID)){
                    //remove the button
                    this->events.controllerHolded.removeControllerButtonByID(controllerID,buttonID);edkEnd();
                }
            }
        }
        else{
            //else clean the controller
            this->events.controllerHolded.cleanControllerButtonsByID(controllerID);edkEnd();
        }
    }
}


edk::Window::Window(){
    //ctor
    //por padrao a window e o mouse sao renderizados
    this->renderMouse = true;edkEnd();
    this->renderWindow = true;edkEnd();
    this->activeRender = false;edkEnd();
    this->windowFocus = true;edkEnd();
    this->mouseInside=false;edkEnd();
    this->cleanEvents();edkEnd();
    this->time.start();edkEnd();
}

edk::Window::~Window(){
    //clean the events
    this->cleanEvents();edkEnd();
}

bool edk::Window::createWindow(uint32 width, uint32 height/*, uint32 bitsPerPixel*/, char8 *name, typeID design, uint32 depth, uint32 stencil, uint32 antialiasing){
    uint32 bitsPerPixel=0u;
    //antes fecha a janela anterior
    if(this->isOpened()){
        //fecha a janela
        this->closeWindow();edkEnd();
    }

    //testa se a string e valida
    if(name){

        //calcula o estilo da janela
        edk::uint32 style = 0u;edkEnd();

        if(design & EDK_WINDOW_NOBAR){
            //
            style = style | sf::Style::None;edkEnd();//Desenha a janela sem uma barra de titulo
        }
        if(design & EDK_WINDOW_BUTTONS){
            //
            style = style | sf::Style::Close;edkEnd();//Desenha a janela com o botao de close e o minimize
        }
        if(design & EDK_WINDOW_BAR){
            //
            style = style | sf::Style::Titlebar;edkEnd();//Desenha a janela com a barra de titulo
        }
        if(design & EDK_WINDOW_RESIZE){
            //
            style = style | sf::Style::Resize;edkEnd();//Deixa a janela ser redimensionada
        }
        if(design & EDK_WINDOW_FULLSCREEN){
            //
            style = style | sf::Style::Fullscreen;edkEnd();//Desenha a janela em FULLSCREEN
        }

        /*
        switch(design){
            //
            case EDK_WINDOW_NOBAR:
                //
                style = style | sf::Style::None;edkEnd();//Desenha a janela sem uma barra de titulo
                break;
            case EDK_WINDOW_BUTTONS:
                //
                style = style | sf::Style::Close;edkEnd();//Desenha a janela com o botao de close e o minimize
                break;
            case EDK_WINDOW_BAR:
                //
                style = style | sf::Style::Titlebar;edkEnd();//Desenha a janela com a barra de titulo
                break;
            case EDK_WINDOW_RESIZE:
                //
                style = style | sf::Style::Resize;edkEnd();//Deixa a janela ser redimensionada
                break;
            case EDK_WINDOW_FULLSCREEN:
                //
                style = sf::Style::Fullscreen;edkEnd();//Desenha a janela em FULLSCREEN
                break;
            }
        */



        /*
        // Display the list of all the video modes available for fullscreen
        std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();edkEnd();
        for (std::size_t i = 0; i < modes.size(); ++i)
        {
            sf::VideoMode mode = modes[i];edkEnd();
            std::cout << "Mode #" << i << ": "
                      << mode.width << "x" << mode.height << " - "
                      << mode.bitsPerPixel << " bpp" << std::endl;edkEnd();
        }
        // Create a window with the same pixel depth as the desktop
        sf::VideoMode desktop = sf::VideoMode::getDesktopMode();edkEnd();
        window.create(sf::VideoMode(1024, 768, desktop.bitsPerPixel), "SFML window");edkEnd();
*/

        sf::VideoMode desktop = sf::VideoMode::getDesktopMode();edkEnd();
        bitsPerPixel = desktop.bitsPerPixel;edkEnd();
        //Agora ele pode criar a janela
        //this->window.Create(sf::VideoMode(width, height, bitsPerPixel),(const edk::char8*)name,style,sf::WindowSettings(depth,stencil,antialiasing));edkEnd();//1.6
        this->window.create(sf::VideoMode(width, height, bitsPerPixel),(const edk::char8*)name,style,sf::ContextSettings(depth,stencil,antialiasing));edkEnd();//2.0

        //Testa se a janela foi aberta
        if(this->isOpened()){
            //Seta a renderizacao da window
            //this->window.Show(this->renderWindow);edkEnd();//1.6
            this->window.setVisible(this->renderWindow);edkEnd();//2.0
            //Seta a renderizacao do mouse
            //this->window.ShowMouseCursor(this->renderMouse);edkEnd();//1.6
            this->window.setMouseCursorVisible(this->renderMouse);edkEnd();//2.0
            //Seta a keyRepeat como true
            //this->window.EnableKeyRepeat(true);edkEnd();//1.6
            this->window.setKeyRepeatEnabled(true);edkEnd();//2.0

            //Seta o tamanho da window
            this->setWindowSize(this->window.getSize().x,this->window.getSize().y);edkEnd();

            //set the blend with alpha channel
            edk::GU::guEnable(GU_BLEND);edkEnd();
            edk::GU::guBlendFunc(GU_SRC_ALPHA,GU_ONE_MINUS_SRC_ALPHA);edkEnd();

            this->time.start();edkEnd();
            //retorna true
            return true;
        }
    }
    //senao retorna false
    return false;
}

bool edk::Window::createWindow(uint32 width, uint32 height/*, uint32 bitsPerPixel*/, const char *name, typeID design, uint32 depth, uint32 stencil, uint32 antialiasing){
    //
    return this->createWindow(width,height/*,bitsPerPixel*/,
                              (edk::char8*) name,
                              design,
                              depth,stencil,antialiasing
                              );edkEnd();
}

bool edk::Window::createWindow(uint32  width, uint32  height/*, uint32  bitsPerPixel*/, char8 *name, typeID design){
    //
    return this->createWindow(width,height/*,bitsPerPixel*/,
                              name,
                              design,
                              24u,8u,0u
                              );edkEnd();
}

bool edk::Window::createWindow(uint32  width, uint32  height/*, uint32  bitsPerPixel*/, const char *name, typeID  design){
    return this->createWindow(width, height/*, bitsPerPixel*/,
                              (char8 *)name,
                              design,
                              24u,8u,0u
                              );edkEnd();
}

bool edk::Window::isOpened(){
    //antes fecha a janela anterior
    //if(this->window.IsOpened()){1.6
    if(this->window.isOpen()){//2.0
        //fecha a janela
        return true;
    }
    //senao retorna false
    return false;
}

bool edk::Window::isShowing(){
    //retorna se a janela esta sendo mostrada
    return this->renderWindow;edkEnd();
}

bool edk::Window::haveFocus(){
    //
    return this->windowFocus;edkEnd();
    //return this->events.focus;edkEnd();
}

void edk::Window::closeWindow(){
    edk::GU::guDisable(GU_BLEND);edkEnd();
    //
    //if(this->window.IsOpened()){//1.6
    if(this->window.isOpen()){//2.0
        //
        //this->window.Close();edkEnd();//1.6
        this->window.close();edkEnd();//2.0
    }
}

void edk::Window::clean(){
    //
    if(this->isOpened()){
        //Entao ele pode limpar a janela
        //this->window.Clear(sf::Color((edk::uint32)(this->cleanColor.r*255),(edk::uint32)(this->cleanColor.g*255),(edk::uint32)(this->cleanColor.b*255),(edk::uint32)255));edkEnd();//1.6
        this->window.clear(sf::Color((edk::uint32)(this->cleanColor.r*255),
                                     (edk::uint32)(this->cleanColor.g*255),
                                     (edk::uint32)(this->cleanColor.b*255),
                                     (edk::uint32)255
                                     )
                           );edkEnd();//2.0
    }
}

edk::uint32 edk::Window::getViewCount(){
    //
    return this->viewWindow.getCount();edkEnd();
}

bool edk::Window::addSubview(View *addView){
    //Add the view to the viewWindow
    return this->viewWindow.addSubview(addView);edkEnd();
}

edk::View* edk::Window::getSubview(uint64 n){
    return this->viewWindow.getSubview(n);edkEnd();
}

edk::uint64 edk::Window::getSubviewId(View *subView){
    return this->getSubviewId(subView);edkEnd();
}

void edk::Window::removeSubview(View *subView){
    //
    this->viewWindow.removeSubview(subView);edkEnd();
}

void edk::Window::removeAllSubview(){
    this->viewWindow.removeAllSubview();edkEnd();
}

void edk::Window::windowRender(bool show){
    //primeiro testa se possui uma window
    if(this->isOpened()){
        //seta o mouse
        //this->window.Show(show);edkEnd();//1.6
        this->window.setVisible(show);edkEnd();//2.0
    }
    this->renderWindow=show;edkEnd();
}

void edk::Window::showWindow(){
    this->windowRender(true);edkEnd();
}

void edk::Window::hideWindow(){
    this->windowRender(false);edkEnd();
}

void edk::Window::mouseRender(bool show){
    //primeiro testa se possui uma window
    if(this->isOpened()){
        //seta o mouse
        //this->window.ShowMouseCursor(show);edkEnd();//1.6
        this->window.setMouseCursorVisible(show);edkEnd();//2.0
    }
    this->renderMouse=show;edkEnd();
}

void edk::Window::showMouse(){
    //Seta para mostrar o mouse
    this->mouseRender(true);edkEnd();
}

void edk::Window::hideMouse(){
    //Seta para esconder o mouse
    this->mouseRender(false);edkEnd();
}

bool edk::Window::setMousePosition(vec2i32 pos){
    //testa se a janela esta aberta
    if(this->isOpened()){
        //seta a posicao do mouse
        //this->window.SetCursorPosition(pos.x,pos.y);edkEnd();//1.6
        sf::Mouse::setPosition(sf::Vector2i(pos.x,pos.y), this->window);edkEnd();//2.0
        saveMousePos = pos;edkEnd();
        //retorna true
        return true;
    }
    //senao retorna false
    return false;
}

bool edk::Window::setMousePosition(int32 x, int32 y){
    //seta o mouse
    return this->setMousePosition(edk::vec2i32(x,y));edkEnd();
}

bool edk::Window::setWindowPosition(vec2i32 pos){
    //testa se a janela esta aberta
    if(this->isOpened()){
        //seta a posicao do mouse
        //this->window.SetPosition(pos.x,pos.y);edkEnd();//1.6
        this->window.setPosition(sf::Vector2i(pos.x,pos.y));edkEnd();//2.0
        //retorna true
        return true;
    }
    //senao retorna false
    return false;
}

bool edk::Window::setWindowPosition(int32 x, int32 y){
    //
    return this->setWindowPosition(edk::vec2i32(x,y));edkEnd();
}

bool edk::Window::setWindowSize(size2ui32 size){
    //testa se a janela esta aberta
    if(this->isOpened()){
        //save the size of the window
        this->windowSize = size;edkEnd();
        //seta a posicao do mouse
        //this->window.SetSize(size.width,size.height);edkEnd();//1.6
        this->window.setSize(sf::Vector2u(size.width,size.height));edkEnd();//2.0
        //seta o tamanho da view
        this->updateViewSize();edkEnd();
        //retorna true
        return true;
    }
    //senao retorna false
    return false;
}

bool edk::Window::setWindowSize(uint32 width, uint32 height){
    //
    return this->setWindowSize(edk::size2ui32(width,height));edkEnd();
}

//Update the views
void edk::Window::updateViews(){
    //test if have a mousePress ou Release
    if(this->eventMousePressed()){
        //test pressed with views
        this->viewWindow.contact(edk::vec2f32(this->getMousePos().x,this->getMousePos().y),edk::mouse::state::pressed,&this->events.mousePressed);edkEnd();
    }
    if(this->eventMouseMoved()){
        //
        this->viewWindow.contact(edk::vec2f32(this->getMousePos().x,this->getMousePos().y),edk::mouse::state::moved,&this->events.mouseHolded);edkEnd();
    }
    if(this->eventMouseRelease()){
        //test released with views
        this->viewWindow.contact(edk::vec2f32(this->getMousePos().x,this->getMousePos().y),edk::mouse::state::released,&this->events.mouseRelease);edkEnd();
    }
    if(this->eventMouseDoubleClick()){
        //test released with views
        this->viewWindow.contact(edk::vec2f32(this->getMousePos().x,this->getMousePos().y),edk::mouse::state::doubleClicked,&this->events.mouseRelease);edkEnd();
    }

    //update the view
    this->updateView(&this->viewWindow);edkEnd();
}
//update the viewGU
void edk::Window::updateView(edk::View* view){
    //test the viewGU
    if(view){
        this->events.mousePos.x -= (edk::int32)view->animatedFrame.origin.x;edkEnd();
        this->events.mousePos.y -= (edk::int32)view->animatedFrame.origin.y;edkEnd();
        //update the envents on the view
        view->updateView(&this->events);edkEnd();
        //update the animations on the view
        view->updateAnimations();edkEnd();
        //tets if is not a leaf
        if(!view->isLeaf()){
            //load the temp
            edk::ViewController* temp=(edk::ViewController*)view;edkEnd();
            //then search anothers views
            for(edk::uint64 i=0u;i<temp->getCount();i++){
                //load the nextView
                edk::ViewController* tempController = (edk::ViewController*)temp->getSubview(i);edkEnd();
                //test if have the nextView
                if(tempController){
                    //then test if is a ViewGU
                    this->updateView(tempController);edkEnd();
                }
            }
        }
        this->events.mousePos.x += (edk::int32)view->animatedFrame.origin.x;edkEnd();
        this->events.mousePos.y += (edk::int32)view->animatedFrame.origin.y;edkEnd();
    }
}
//contactView
void edk::Window::mousePressView(edk::ViewController* view, edk::vec2i32 point, edk::vector::Stack<edk::uint32> buttons){
    //
    if(view && point.x){
        //remove the warning
    }
    //buttons cant delete
    buttons.cantDestroy();edkEnd();
}
void edk::Window::mouseReleaseView(edk::ViewController* view, edk::vec2i32 point, edk::vector::Stack<edk::uint32> buttons){
    //
    if(view && point.x){
        //remove the warning
    }

    //buttons cant delete
    buttons.cantDestroy();edkEnd();
}
void edk::Window::mouseDoubleClickView(edk::ViewController* view, edk::vec2i32 point, edk::vector::Stack<edk::uint32> buttons){
    //
    if(view && point.x){
        //remove the warning
    }

    //buttons cant delete
    buttons.cantDestroy();edkEnd();
}

bool edk::Window::drawStart(){
    //Tetsa se finalizou o render antes e se a janela esta aberta
    if(!this->activeRender && this->isOpened()){
        //pode setar o render
        //this->window.SetActive(true);edkEnd();//1.6
        this->window.setActive(true);edkEnd();//2.0
        //seta activeRender como true
        this->activeRender=true;edkEnd();
        //retorna true
        return true;
    }
    //senao retorna false
    return false;
}

bool edk::Window::drawEnd(){
    //Tetsa se iniciou o render antes e se a janela esta aberta
    if(this->activeRender && this->isOpened()){
        //pode setar o render
        //this->window.SetActive(false);edkEnd();//1.6
        this->window.setActive(false);edkEnd();//2.0
        //seta activeRender como false
        this->activeRender=false;edkEnd();
        //retorna true
        return true;
    }
    //senao retorna false
    return false;
}

void edk::Window::drawView(){
    //Start the draw
    this->drawStart();edkEnd();

    //load the identity matrix
    edk::GU::guLoadIdentity();edkEnd();

    //Set the clean color to the first view backGroundColor
    this->viewWindow.backgroundColor(this->cleanColor.r,
                                     this->cleanColor.g,
                                     this->cleanColor.b,
                                     1.f
                                     );edkEnd();
    //draw the view
    this->viewWindow.draw(
                this->viewWindow.frame
                );edkEnd();

    //End the drawing
    this->drawEnd();edkEnd();
}

void edk::Window::runPauseSwitchViews(){
    this->viewWindow.runPauseSwitch();
}

void edk::Window::runPauseViews(){
    this->viewWindow.runPause();edkEnd();
}

void edk::Window::runUnpauseViews(){
    this->viewWindow.runUnpause();edkEnd();
    //after unpause the views, start the time to generate new seconds because, if it's not started
    //it will get all the time where the views was paused
    this->time.start();edkEnd();
}

bool edk::Window::isPaused(){
    return this->viewWindow.isPaused();
}

bool edk::Window::flip(){
    //testa se possui uma janela e se ja desenhou
    if(this->isOpened() && !this->activeRender){
        //Pode renderizar na tela
        //this->window.Display();edkEnd();//1.6
        this->window.display();edkEnd();//2.0
        //retorna true
        return true;
    }
    //senao retorna false
    return false;
}

bool edk::Window::render(){
    //
    return this->flip();edkEnd();
}

edk::size2ui32 edk::Window::getSize(){
    //testa se a janela esta aberta
    edk::size2ui32 ret(0u,0u);edkEnd();
    if(this->isOpened()){
        //retorna o tamanho da window
        /*
        ret = edk::size2ui32((edk::uint32)this->window.GetDefaultView().GetRect().GetWidth(),
                     (edk::uint32)this->window.GetDefaultView().GetRect().GetHeight()
                     );edkEnd();
        */
        ret = this->windowSize;edkEnd();
    }
    //senao retorna um tamanho zerado
    return ret;
}

edk::size2ui32 edk::Window::getScreenSize(){
    //testa se a janela esta aberta
    edk::size2ui32 ret(0u,0u);edkEnd();
    if(this->isOpened()){
        //retorna o tamanho da view
        //ret = edk::size2ui32(this->window.GetWidth(),this->window.GetHeight());edkEnd();//1.6
        ret = edk::size2ui32(this->window.getSize().x,this->window.getSize().y);edkEnd();//2.0
    }
    //senao retorna um tamanho zerado
    return ret;
}

edk::uint32 edk::Window::getWidth(){
    //
    if(this->isOpened()){
        //
        //return this->window.GetWidth();edkEnd();//1.6
        return this->window.getSize().x;edkEnd();//2.0
    }
    //senao retorna 0u
    return 0u;edkEnd();
}

edk::uint32 edk::Window::getHeight(){
    //
    if(this->isOpened()){
        //
        //return this->window.GetHeight();edkEnd();//1.6
        return this->window.getSize().y;edkEnd();//2.0
    }
    //senao retorna 0u
    return 0u;edkEnd();
}

edk::vec2i32 edk::Window::getMousePos(){
    //
    //senao retorna uma posicao zerada
    //return this->mousePos;edkEnd();
    return this->events.mousePosWindow;edkEnd();
}

edk::vec2i32 edk::Window::eventGetMouseMoved(){
    //
    //return this->mouseMove;edkEnd();
    return this->events.mouseMove;edkEnd();
}

bool edk::Window::eventLostFocus(){
    return this->events.lostFocus;edkEnd();
}

bool edk::Window::eventGainedFocus(){
    return this->events.gainedFocus;edkEnd();
}

bool edk::Window::eventButtonClose(){
    //
    bool temp = events.buttonExit;edkEnd();
    events.buttonExit=false;edkEnd();
    return temp;edkEnd();
}

bool edk::Window::eventKeyPressed(){
    //
    return (bool)this->eventGetKeyPressedSize();edkEnd();
}

bool edk::Window::eventKeyRelease(){
    //
    return (bool)this->eventGetKeyReleaseSize();edkEnd();
}

bool edk::Window::eventKeyHolded(){
    return (bool)this->eventGetKeyHoldedSize();edkEnd();
}

edk::uint32 edk::Window::eventGetKeyPressedSize(){
    //Retorna o tamanho do vector
    return this->events.keyPressed.size();edkEnd();
}

edk::uint32 edk::Window::eventGetKeyReleaseSize(){
    //Retorna o tamanho do vetor
    return this->events.keyRelease.size();edkEnd();
}

edk::uint32 edk::Window::eventGetKeyHoldedSize(){
    return this->events.keyHolded.size();edkEnd();
}

edk::uint32 edk::Window::eventGetKeyPressed(uint32 pos){
    //
    if(pos<this->events.keyPressed.size()){
        //
        return this->events.keyPressed[pos];edkEnd();
    }
    //senao retorna 0u
    return 0u;edkEnd();
}

edk::uint32 edk::Window::eventGetKeyRelease(uint32 pos){
    if(pos<this->events.keyRelease.size()){
        //
        return this->events.keyRelease[pos];edkEnd();
    }
    //senao retorna 0u
    return 0u;edkEnd();
}

edk::uint32 edk::Window::eventGetKeyHolded(uint32 pos){

    if(pos<this->events.keyHolded.size()){
        //
        return this->events.keyHolded[pos];edkEnd();
    }
    //senao retorna 0u
    return 0u;edkEnd();
}

bool edk::Window::eventMousePressed(){
    //
    return (bool)this->eventGetMousePressedSize();edkEnd();
}

bool edk::Window::eventMouseRelease(){
    //
    return (bool)this->eventGetMouseReleaseSize();edkEnd();
}

bool edk::Window::eventMouseDoubleClick(){
    //
    return (bool)this->eventGetMouseDoubleClickSize();edkEnd();
}

bool edk::Window::eventMouseHolded(){
    return (bool)this->eventGetMouseHoldedSize();edkEnd();
}

edk::uint8 edk::Window::eventGetMousePressedSize(){
    //
    return this->events.mousePressed.size();edkEnd();
}

edk::uint8 edk::Window::eventGetMouseReleaseSize(){
    //
    return this->events.mouseRelease.size();edkEnd();
}

edk::uint8 edk::Window::eventGetMouseDoubleClickSize(){
    //
    return this->events.mouseDoubleClick.size();edkEnd();
}

edk::uint8 edk::Window::eventGetMouseHoldedSize(){
    //
    return this->events.mouseHolded.size();edkEnd();
}

edk::uint8 edk::Window::eventGetMousePressed(uint32 pos){
    //
    if(pos<this->events.mousePressed.size()){
        //
        return this->events.mousePressed[pos];edkEnd();
    }
    //senao retorna false
    return false;
}

edk::uint8 edk::Window::eventGetMouseRelease(uint32 pos){
    //
    if(pos<this->events.mouseRelease.size()){
        //
        return this->events.mouseRelease[pos];edkEnd();
    }
    //senao retorna false
    return false;
}

edk::uint8 edk::Window::eventGetMouseDoubleClick(edk::uint32 pos){
    //
    if(pos<this->events.mouseDoubleClick.size()){
        //
        return this->events.mouseDoubleClick[pos];edkEnd();
    }
    //senao retorna false
    return false;
}

edk::uint8 edk::Window::eventGetMouseHolded(uint32 pos){
    //
    if(pos<this->events.mouseHolded.size()){
        //
        return this->events.mouseHolded[pos];edkEnd();
    }
    //senao retorna false
    return false;
}

bool edk::Window::eventMouseEnter(){
    //
    return this->events.mouseEnter;edkEnd();
}

bool edk::Window::eventMouseExit(){
    //
    return this->events.mouseExit;edkEnd();
}

bool edk::Window::eventMouseMoved(){
    //retorna se o mouse foi movido
    return this->events.mouseMoved;edkEnd();
}

edk::int8 edk::Window::getMouseScrollWheel(){
    //
    return (int8)this->events.mouseScrollWheel;edkEnd();
}

bool edk::Window::eventResizeWindow(){
    //retorna se redimencionou a janela
    return this->events.resize;edkEnd();
}

edk::size2i32 edk::Window::getResize(){
    //
    return this->events.resizePos;edkEnd();
}

//set and get the second passed
bool edk::Window::setSecondPassed(edk::float32 seconds){
    if(seconds>0.f){
        this->events.secondPassed = seconds;edkEnd();
        return true;
    }
    return false;
}
edk::float32 edk::Window::eventGetSecondPassed(){
    return this->events.secondPassed;edkEnd();
}

bool edk::Window::loadEvents(){
    edk::uint32 mouseButtonValue=0u;
    bool ret=false;edkEnd();
    this->updateControllerEvents();edkEnd();
    //Limpa os eventos
    this->cleanEvents();edkEnd();

    //Eventos da janela
    sf::Event event;edkEnd();
    //Input da janela
    //const sf::Input& input=window.GetInput();edkEnd();//1.6
    //2.0

    //test if DON'T need force the second passed
    if(!this->events.updateForceSecondPassed()){
        //load the time passed since the last frame
        this->events.secondPassed = this->time.getMicroseconds() * edk::watch::microsecond;edkEnd();
        this->events.secondsGlobal = this->time.getMicrosecondsReal() * edk::watch::microsecond;edkEnd();
    }

    this->time.start();edkEnd();

    //while(window.GetEvent(event)){//1.6
    while(window.pollEvent(event)){//2.0
        //processa os eventos
        ///////////////////////////////////////////////////////////
        //JANELA FECHANDO
        //if(event.Type == sf::Event::Closed){//1.6
        if(event.type == sf::Event::Closed){//2.0
            //
            this->events.buttonExit=true;edkEnd();
        }
        //if(event.Type == sf::Event::LostFocus){//1.6
        if(event.type == sf::Event::LostFocus){//2.0
            //Minimize
            this->events.lostFocus=true;edkEnd();
            this->events.focus = false;edkEnd();
        }
        //if(event.Type == sf::Event::GainedFocus){//1.6
        if(event.type == sf::Event::GainedFocus){//2.0
            //unMinimize
            this->events.gainedFocus=true;edkEnd();
            this->events.focus=true;edkEnd();
        }
        ///////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////
        //PRESSIONOU TECLA
        //if(event.Type == sf::Event::KeyPressed){//1.6
        if(event.type == sf::Event::KeyPressed){//2.0
            //carrega a tecla pressionada
            //this->events.keyPressed.pushBack(event.Key.Code);edkEnd();//1.6
            //printf("\nKey Pressed %d",event.key.code);edkEnd();
            if(event.key.code>=0&&event.key.code<26){
                this->events.keyPressed.pushBack(event.key.code+'a') ;edkEnd();//2.0
            }
            else if(event.key.code>=26&&event.key.code<36){
                this->events.keyPressed.pushBack(event.key.code+ '0' - 26) ;edkEnd();//2.0
            }
            else if(event.key.code>=75&&event.key.code<85){
                this->events.keyPressed.pushBack(event.key.code+ '0' - 75) ;edkEnd();//2.0
            }
            else{
                this->events.keyPressed.pushBack(event.key.code+256 - 36) ;edkEnd();//2.0
            }
        }
        //FIM PRESSIONOU TECLA
        ///////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////
        //RETIROU DA PRESSAO A TECLA
        //if(event.Type == sf::Event::KeyReleased){//1.6
        if(event.type == sf::Event::KeyReleased){//2.0
            //carrega a tecla pressionada
            //this->events.keyRelease.pushBack(event.Key.Code);edkEnd();//1.6
            if(event.key.code>=0&&event.key.code<26){
                this->events.keyRelease.pushBack(event.key.code+'a') ;edkEnd();//2.0
            }
            else if(event.key.code>=26&&event.key.code<36){
                this->events.keyRelease.pushBack(event.key.code+ '0' - 26) ;edkEnd();//2.0
            }
            else if(event.key.code>=75&&event.key.code<85){
                this->events.keyRelease.pushBack(event.key.code+ '0' - 75) ;edkEnd();//2.0
            }
            else{
                this->events.keyRelease.pushBack(event.key.code+256 - 36) ;edkEnd();//2.0
            }
        }
        //FIM RETIROU DA PRESSAO A TECLA
        ///////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////
        //TEXT ENTERED
        //if(event.Type == sf::Event::TextEntered){//1.6
        if(event.type == sf::Event::TextEntered){//2.0
            //
            this->events.keyText.pushBack(event.text.unicode);edkEnd();
        }
        //END TEX ENTERED
        ///////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////
        //REDIMENCIONAMENTO DA JANELA
        //if(event.Type == sf::Event::Resized){//1.6
        if(event.type == sf::Event::Resized){//2.0
            /*
                sf::FloatRect NewSize(0, 0, event.Size.Width, event.Size.Height);edkEnd();
                window.GetDefaultView().SetFromRect(NewSize);edkEnd();
                */
            //resize true
            this->events.resize=true;edkEnd();
            //edk::size2ui32 tempView = edk::size2ui32(window.GetWidth(),window.GetHeight());edkEnd();//1.6
            edk::size2ui32 tempView = edk::size2ui32(window.getSize().x,window.getSize().y);edkEnd();//2.0
            //resizePos
            //this->resizePos = edk::size2i32(window.GetWidth(),window.GetHeight());edkEnd();
            /*
                this->resizePos = edk::size2i32(this->windowSize.width,this->windowSize.height) -
                                  edk::size2i32(tempView.width,tempView.height)
                                                ;edkEnd();
                */
            this->events.resizePos.width += (edk::int32)tempView.width - (edk::int32)this->windowSize.width;edkEnd();
            this->events.resizePos.height+= (edk::int32)tempView.height- (edk::int32)this->windowSize.height;edkEnd();

            //set the new size of the window
            this->windowSize = tempView;edkEnd();
            this->events.windowSize = this->windowSize;edkEnd();

            //Seta o tamanho da janela
            this->updateViewSize();edkEnd();
        }
        ///////////////////////////////////////////////////////////




        ///////////////////////////////////////////////////////////
        //MOUSE PRESSIONADO
        //if(event.Type == sf::Event::MouseButtonPressed){//1.6
        if(event.type == sf::Event::MouseButtonPressed){//2.0
            //
            //this->events.mousePressed.pushBack(event.MouseButton.Button+1u);edkEnd();//1.6
            this->events.mousePressed.pushBack(event.mouseButton.button+1u);edkEnd();//2.0

            this->mouseInside=true;edkEnd();
        }
        //FIM DO MOUSE PRESSIONADO
        ///////////////////////////////////////////////////////////




        ///////////////////////////////////////////////////////////
        //MOUSE ENTROU SAIU DA JANELA
        //if(event.Type == sf::Event::MouseEntered){//1.6
        if(event.type == sf::Event::MouseEntered){//2.0
            //
            this->events.mouseEnter=true;edkEnd();

            this->mouseInside=true;edkEnd();
        }
        //if(event.Type == sf::Event::MouseLeft){//1.6
        if(event.type == sf::Event::MouseLeft){//2.0
            //
            this->events.mouseExit=true;edkEnd();

            this->mouseInside=false;edkEnd();
        }
        //FIM DO MOUSE ENTROU SAIU DA JANELA
        ///////////////////////////////////////////////////////////





        ///////////////////////////////////////////////////////////
        //MOUSE SOLTO
        //if(event.Type == sf::Event::MouseButtonReleased){//1.6
        if(event.type == sf::Event::MouseButtonReleased){//2.0
            //
            mouseButtonValue = event.mouseButton.button+1u;edkEnd();//2.0
            //this->events.mouseRelease.pushBack(event.MouseButton.Button+1u);edkEnd();//1.6
            this->events.mouseRelease.pushBack(mouseButtonValue);edkEnd();//2.0

            //test the time distance from the last mouse button release
            if(mouseButtonValue < edk::mouse::mouseButtonsSize){
                //test the time
                if(this->events.timeMouseDouble[mouseButtonValue].getSeconds() < this->events.getMouseDoubleClickLimit()){
                    //add this mouse button into doubleClick event
                    this->events.mouseDoubleClick.pushBack(mouseButtonValue);edkEnd();
                    //start the time
                }
                this->events.timeMouseDouble[mouseButtonValue].start();
            }
        }
        //FIM DO MOUSE SOLTO
        ///////////////////////////////////////////////////////////










        ///////////////////////////////////////////////////////////
        //MOUSE MOVIDO
        //if(event.Type == sf::Event::MouseMoved){//1.6
        if(event.type == sf::Event::MouseMoved){//2.0
            //
            this->events.mouseMoved=true;edkEnd();

            //Carrega a nova posicao do mouse
            edk::vec2ui32 mouseTemp = edk::vec2ui32((edk::uint32)sf::Mouse::getPosition(this->window).x,(edk::uint32)sf::Mouse::getPosition(this->window).y);edkEnd();//2.0
            //Calcula a distancia movida
            this->events.mouseMove = edk::vec2i32((edk::int32)mouseTemp.x-(edk::int32)this->saveMousePos.x,
                                                  (edk::int32)mouseTemp.y-(edk::int32)this->saveMousePos.y
                                                  );edkEnd();
            //salva a nova posicao do mouse
            this->events.mousePos = edk::vec2i32(mouseTemp.x,mouseTemp.y);edkEnd();
        }
        //FIM MOUSE MOVIDO
        ///////////////////////////////////////////////////////////







        ///////////////////////////////////////////////////////////
        //MOUSE SCROLL
        //if(event.Type == sf::Event::MouseWheelMoved){//1.6
        if(event.type == sf::Event::MouseWheelMoved){//2.0
            //
            /*
                printf("\nScrool %d"
                       ,event.MouseWheel.Delta
                       );edkEnd();
                */
            //this->events.mouseScrollWheel=event.MouseWheel.Delta;edkEnd();//1.6
            this->events.mouseScrollWheel=event.mouseWheel.delta;edkEnd();//2.0

            this->mouseInside=true;edkEnd();
        }
        //FIM MOUSE SCROLL
        ///////////////////////////////////////////////////////////

        //if(event.Type == sf::Event::JoyButtonPressed){//1.6
        if(event.type == sf::Event::JoystickButtonPressed){//2.0
/*
                printf("\nJoyButtonPressed joy == %u button == %u"
                       ,event.joystickButton.joystickId
                       ,event.joystickButton.button
                       );edkEnd();
*/
            this->events.controllerPressed.addButton(event.joystickButton.joystickId,event.joystickButton.button);edkEnd();
        }

        //if(event.Type == sf::Event::JoyButtonPressed){//1.6
        if(event.type == sf::Event::JoystickButtonReleased){//2.0
/*
                printf("\nJoyButtonReleased joy == %u button == %u"
                       ,event.joystickButton.joystickId
                       ,event.joystickButton.button
                       );edkEnd();
*/
            this->events.controllerReleased.addButton(event.joystickButton.joystickId,event.joystickButton.button);edkEnd();
        }


        //if(event.Type == sf::Event::JoyButtonPressed){//1.6
        if(event.type == sf::Event::JoystickMoved){//2.0
/*
                printf("\nJoyMoved joy == %u position == %.2f axis %u"
                       ,event.joystickMove.joystickId
                       ,event.joystickMove.position
                       ,event.joystickMove.axis
                       );edkEnd();
*/
            //test if it's the Y
            if(event.joystickMove.axis<(sizeof(event.joystickMove.axis)*8)-1u){
                this->events.controllerAxisMoved.addAxis(event.joystickMove.joystickId,event.joystickMove.axis,event.joystickMove.position*-1.f);edkEnd();
            }
            else{
                this->events.controllerAxisMoved.addAxis(event.joystickMove.joystickId,event.joystickMove.axis,event.joystickMove.position);edkEnd();
            }
        }


        ret=true;edkEnd();

    }
    //load the window size
    this->windowSize = edk::size2ui32(window.getSize().x,window.getSize().y);edkEnd();//2.0
    this->events.windowSize = this->windowSize;edkEnd();

    //Seta o tamanho da janela
    this->updateViewSize();edkEnd();

    //load mousePosition
    //events.mousePosWindow = events.mousePos = edk::vec2i32( input.GetMouseX(),input.GetMouseY());edkEnd();//1.6
    events.mousePosWindow = events.mousePos = edk::vec2i32( sf::Mouse::getPosition(this->window).x,sf::Mouse::getPosition(this->window).y);edkEnd();//2.0
    this->saveMousePos.x = this->events.mousePos.x;edkEnd();
    this->saveMousePos.y = this->events.mousePos.y;edkEnd();
    events.mousePosWorld = edk::vec2i32( sf::Mouse::getPosition().x,sf::Mouse::getPosition().y);edkEnd();//2.0

    //save focus
    this->windowFocus = this->events.focus;edkEnd();

    //test if have focus
    if(this->windowFocus){
        //load the holded keys
        for(edk::int32 i=sf::Keyboard::A;i<sf::Keyboard::KeyCount;i=i+1){
            if(sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i)){
                if(i>=0&&i<26){
                    this->events.keyHolded.pushBack(i+'a') ;edkEnd();//2.0
                }
                else if(i>=26&&i<36){
                    this->events.keyHolded.pushBack(i+ '0' - 26) ;edkEnd();//2.0
                }
                else{
                    this->events.keyHolded.pushBack(i+256 - 36) ;edkEnd();//2.0
                }
            }
        }
        //load the holded mouse button
        for(edk::int32 i=sf::Mouse::Left ;i<sf::Mouse::ButtonCount;i=i+1){
            if(sf::Mouse::isButtonPressed((sf::Mouse::Button)i)){
                this->events.mouseHolded.pushBack(i+1u);edkEnd();
            }
        }
        ret=true;edkEnd();
    }

    //Testa os controlers
    /*
        for(edk::uint32 i=0u;i<2u;i++){
            //Adiciona o novo controler
            edk::Window::ctrlPressed temp;edkEnd();
            this->controllerPressed.push_back(temp);edkEnd();
            for(edk::uint32 j=0u;j<=15u;j++){
                //adiciona os valores
                if(input.IsJoystickButtonDown(i, j)){
                    //
                    printf("\nBotao %u controle %u"
                           ,i
                           ,j
                           );edkEnd();
                    }
            }
        }
*/

    //senao retorna false
    return ret;
}

edk::size2ui32 edk::Window::getDesktopSize(){
    //Carrega o modo do desktop
    //sf::VideoMode DesktopMode = sf::VideoMode::GetDesktopMode();edkEnd();//1.6
    sf::VideoMode DesktopMode = sf::VideoMode::getDesktopMode();edkEnd();//2.0
    //seta o retorno
    //edk::size2ui32 temp(DesktopMode.Width,DesktopMode.Height);edkEnd();//1.6
    edk::size2ui32 temp(DesktopMode.width,DesktopMode.height);edkEnd();//2.0
    //carrega o desktop mode
    return temp;edkEnd();
}

edk::uint32 edk::Window::getDesktopBitsPerPixel(){
    //Carrega o modo do desktop
    //sf::VideoMode DesktopMode = sf::VideoMode::GetDesktopMode();edkEnd();//1.6
    sf::VideoMode DesktopMode = sf::VideoMode::getDesktopMode();edkEnd();//2.0
    //retorna os bits
    //return DesktopMode.BitsPerPixel;edkEnd();//1.6
    return DesktopMode.bitsPerPixel;edkEnd();//2.0
}

//test if have a controller
bool edk::Window::haveController(edk::uint32 controller){
    if(sf::Joystick::isConnected(controller)){
        return true;
    }
    return false;
}
//return the number of buttons of a controller
edk::uint32 edk::Window::getControllerButtonCount(edk::uint32 controller){
    // check how many buttons joystick number 0 has
    return sf::Joystick::getButtonCount(controller);edkEnd();
}

bool edk::Window::eventControllerButtonPressed(edk::uint32 controller){
    return (bool)this->eventGetControllerButtonPressedSize(controller);edkEnd();
}

bool edk::Window::eventControllerButtonRelease(edk::uint32 controller){
    return (bool)this->eventGetControllerButtonReleaseSize(controller);edkEnd();
}

bool edk::Window::eventControllerButtonHolded(edk::uint32 controller){
    return (bool)this->eventGetControllerButtonHoldedSize(controller);edkEnd();
}

bool edk::Window::eventControllerAxisMoved(edk::uint32 controller){
    return (bool)this->eventGetControllerAxisMovedSize(controller);edkEnd();
}

edk::uint8 edk::Window::eventGetControllerButtonPressedSize(edk::uint32 controller){
    return this->events.controllerPressed.getControllerButtonSizeInPosition(controller);edkEnd();
}

edk::uint8 edk::Window::eventGetControllerButtonReleaseSize(edk::uint32 controller){
    return this->events.controllerReleased.getControllerButtonSizeInPosition(controller);edkEnd();
}

edk::uint8 edk::Window::eventGetControllerButtonHoldedSize(edk::uint32 controller){
    return this->events.controllerHolded.getControllerButtonSizeInPosition(controller);edkEnd();
}

edk::uint8 edk::Window::eventGetControllerAxisMovedSize(edk::uint32 controller){
    return this->events.controllerAxisMoved.getControllerButtonSizeInPosition(controller);edkEnd();
}

edk::uint8 edk::Window::eventGetControllerButtonPressed(edk::uint32 controller, uint32 pos){
    return this->events.controllerPressed.getControllerButtonInPosition(controller,pos);edkEnd();
}

edk::uint8 edk::Window::eventGetControllerButtonRelease(edk::uint32 controller, uint32 pos){
    return this->events.controllerReleased.getControllerButtonInPosition(controller,pos);edkEnd();
}

edk::uint8 edk::Window::eventGetControllerButtonHolded(edk::uint32 controller, uint32 pos){
    return this->events.controllerHolded.getControllerButtonInPosition(controller,pos);edkEnd();
}

edk::uint32 edk::Window::eventGetControllerAxisIDMoved(edk::uint32 controller, uint32 pos){
    return this->events.controllerAxisMoved.getControllerAxisInPosition(controller,pos);edkEnd();
}

edk::float32 edk::Window::eventGetControllerAxisMoved(edk::uint32 controller, uint32 pos){
    return this->events.controllerAxisMoved.getControllerAxisValueInPosition(controller,pos);edkEnd();
}

edk::float32 edk::Window::eventGetControllerAxisMovedByID(edk::uint32 controller, uint32 id){
    return this->events.controllerAxisMoved.getControllerAxisValueByID(controller,id);edkEnd();
}
