#include "Window.h"

/*
Library C++ Window - Manipulate a window in Edk Game Engine
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
#warning "            Inside Window.cpp"
#endif

namespace edk {

//PRIVATE
//Atualiza o tamanho da view
void edk::Window::updateViewSize(){
    //seta o tamanho da view
    this->viewWindow.animatedFrame = this->viewWindow.frame=edk::rectf32(0.f,0.f,(edk::float32)this->getScreenSize().width,(edk::float32)this->getScreenSize().height);
}

void Window::cleanEvents(){
    //
    this->events.clean();
}
//update joystick events
void Window::updateControllerEvents(){
    edk::uint32 controllers = this->events.controllerPressed.getControllerSize();
    edk::uint32 controllerID = 0u;
    edk::uint32 buttons = 0u;
    edk::uint32 buttonID=0u;
    for(edk::uint32 i=0u;i<controllers;i++){
        //load the controllerID
        controllerID = this->events.controllerPressed.getControllerIDInPosition(i);
        if(sf::Joystick::isConnected(controllerID)){
            //load the buttons size
            buttons = this->events.controllerPressed.getControllerButtonSizeInPosition(i);
            for(edk::uint32 j=0u;j<buttons;j++){
                buttonID = this->events.controllerPressed.getControllerButtonByID(controllerID,j);
                if(sf::Joystick::isButtonPressed(controllerID,buttonID)){
                    //copy the button to the holded
                    this->events.controllerHolded.addButton(controllerID,buttonID);
                }
            }
        }
        else{
            //else clean the controller
            this->events.controllerHolded.cleanControllerButtonsByID(controllerID);
        }
    }
    //test if is holding the buttons
    controllers = this->events.controllerHolded.getControllerSize();
    for(edk::uint32 i=0u;i<controllers;i++){
        //load the controllerID
        controllerID = this->events.controllerHolded.getControllerIDInPosition(i);
        if(sf::Joystick::isConnected(controllerID)){
            //load the buttons size
            buttons = this->events.controllerHolded.getControllerButtonSizeInPosition(i);
            for(edk::uint32 j=0u;j<buttons;j++){
                buttonID = this->events.controllerHolded.getControllerButtonByID(controllerID,j);
                if(!sf::Joystick::isButtonPressed(controllerID,buttonID)){
                    //remove the button
                    this->events.controllerHolded.removeControllerButtonByID(controllerID,buttonID);
                }
            }
        }
        else{
            //else clean the controller
            this->events.controllerHolded.cleanControllerButtonsByID(controllerID);
        }
    }
}


Window::Window(){
    //ctor
    //por padrao a window e o mouse sao renderizados
    this->renderMouse = true;
    this->renderWindow = true;
    this->activeRender = false;
    this->windowFocus = true;
    this->mouseInside=false;
    this->cleanEvents();
}

Window::~Window(){
    //clean the events
    this->cleanEvents();
}

bool Window::createWindow(uint32 width, uint32 height/*, uint32 bitsPerPixel*/, char8 *name, typeID design, uint32 depth, uint32 stencil, uint32 antialiasing){
    uint32 bitsPerPixel=0u;
    //antes fecha a janela anterior
    if(this->isOpened()){
        //fecha a janela
        this->closeWindow();
    }

    //testa se a string e valida
    if(name){

        //calcula o estilo da janela
        edk::uint32 style = 0u;

        if(design & EDK_WINDOW_NOBAR){
            //
            style = style | sf::Style::None;//Desenha a janela sem uma barra de titulo
        }
        if(design & EDK_WINDOW_BUTTONS){
            //
            style = style | sf::Style::Close;//Desenha a janela com o botao de close e o minimize
        }
        if(design & EDK_WINDOW_BAR){
            //
            style = style | sf::Style::Titlebar;//Desenha a janela com a barra de titulo
        }
        if(design & EDK_WINDOW_RESIZE){
            //
            style = style | sf::Style::Resize;//Deixa a janela ser redimensionada
        }
        if(design & EDK_WINDOW_FULLSCREEN){
            //
            style = style | sf::Style::Fullscreen;//Desenha a janela em FULLSCREEN
        }

        /*
        switch(design){
            //
            case EDK_WINDOW_NOBAR:
                //
                style = style | sf::Style::None;//Desenha a janela sem uma barra de titulo
                break;
            case EDK_WINDOW_BUTTONS:
                //
                style = style | sf::Style::Close;//Desenha a janela com o botao de close e o minimize
                break;
            case EDK_WINDOW_BAR:
                //
                style = style | sf::Style::Titlebar;//Desenha a janela com a barra de titulo
                break;
            case EDK_WINDOW_RESIZE:
                //
                style = style | sf::Style::Resize;//Deixa a janela ser redimensionada
                break;
            case EDK_WINDOW_FULLSCREEN:
                //
                style = sf::Style::Fullscreen;//Desenha a janela em FULLSCREEN
                break;
            }
        */



        /*
        // Display the list of all the video modes available for fullscreen
        std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
        for (std::size_t i = 0; i < modes.size(); ++i)
        {
            sf::VideoMode mode = modes[i];
            std::cout << "Mode #" << i << ": "
                      << mode.width << "x" << mode.height << " - "
                      << mode.bitsPerPixel << " bpp" << std::endl;
        }
        // Create a window with the same pixel depth as the desktop
        sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
        window.create(sf::VideoMode(1024, 768, desktop.bitsPerPixel), "SFML window");
*/

        sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
        bitsPerPixel = desktop.bitsPerPixel;
        //Agora ele pode criar a janela
        //this->window.Create(sf::VideoMode(width, height, bitsPerPixel),(const char*)name,style,sf::WindowSettings(depth,stencil,antialiasing));//1.6
        this->window.create(sf::VideoMode(width, height, bitsPerPixel),(const char*)name,style,sf::ContextSettings(depth,stencil,antialiasing));//2.0

        //Testa se a janela foi aberta
        if(this->isOpened()){
            //Seta a renderizacao da window
            //this->window.Show(this->renderWindow);//1.6
            this->window.setVisible(this->renderWindow);//2.0
            //Seta a renderizacao do mouse
            //this->window.ShowMouseCursor(this->renderMouse);//1.6
            this->window.setMouseCursorVisible(this->renderMouse);//2.0
            //Seta a keyRepeat como true
            //this->window.EnableKeyRepeat(true);//1.6
            this->window.setKeyRepeatEnabled(true);//2.0

            //Seta o tamanho da window
            this->setWindowSize(this->window.getSize().x,this->window.getSize().y);

            //set the blend with alpha channel
            edk::GU::guEnable(GU_BLEND);
            edk::GU::guBlendFunc(GU_SRC_ALPHA,GU_ONE_MINUS_SRC_ALPHA);

            //retorna true
            return true;
        }
    }
    //senao retorna false
    return false;
}

bool Window::createWindow(uint32 width, uint32 height/*, uint32 bitsPerPixel*/, const char *name, typeID design, uint32 depth, uint32 stencil, uint32 antialiasing){
    //
    return this->createWindow(width,height/*,bitsPerPixel*/,
                              (edk::char8*) name,
                              design,
                              depth,stencil,antialiasing
                              );
}

bool Window::createWindow(uint32  width, uint32  height/*, uint32  bitsPerPixel*/, char8 *name, typeID design){
    //
    return this->createWindow(width,height/*,bitsPerPixel*/,
                              name,
                              design,
                              24u,8u,0u
                              );
}

bool Window::createWindow(uint32  width, uint32  height/*, uint32  bitsPerPixel*/, const char *name, typeID  design){
    return this->createWindow(width, height/*, bitsPerPixel*/,
                              (char8 *)name,
                              design,
                              24u,8u,0u
                              );
}

bool Window::isOpened(){
    //antes fecha a janela anterior
    //if(this->window.IsOpened()){1.6
    if(this->window.isOpen()){//2.0
        //fecha a janela
        return true;
    }
    //senao retorna false
    return false;
}

bool Window::isShowing(){
    //retorna se a janela esta sendo mostrada
    return this->renderWindow;
}

bool Window::haveFocus(){
    //
    return this->windowFocus;
    //return this->events.focus;
}

void Window::closeWindow(){
    edk::GU::guDisable(GU_BLEND);
    //
    //if(this->window.IsOpened()){//1.6
    if(this->window.isOpen()){//2.0
        //
        //this->window.Close();//1.6
        this->window.close();//2.0
    }
}

void Window::clean(){
    //
    if(this->isOpened()){
        //Entao ele pode limpar a janela
        //this->window.Clear(sf::Color((edk::uint32)(this->cleanColor.r*255),(edk::uint32)(this->cleanColor.g*255),(edk::uint32)(this->cleanColor.b*255),(edk::uint32)255));//1.6
        this->window.clear(sf::Color((edk::uint32)(this->cleanColor.r*255),
                                     (edk::uint32)(this->cleanColor.g*255),
                                     (edk::uint32)(this->cleanColor.b*255),
                                     (edk::uint32)255
                                     )
                           );//2.0
    }
}

edk::uint32 Window::getViewCount(){
    //
    return this->viewWindow.getCount();
}

bool Window::addSubview(View *addView){
    //Add the view to the viewWindow
    return this->viewWindow.addSubview(addView);
}

View* Window::getSubview(uint64 n){
    return this->viewWindow.getSubview(n);
}

uint64 Window::getSubviewId(View *subView){
    return this->getSubviewId(subView);
}

void Window::removeSubview(View *subView){
    //
    this->viewWindow.removeSubview(subView);
}

void Window::removeAllSubview(){
    this->viewWindow.removeAllSubview();
}

void Window::windowRender(bool show){
    //primeiro testa se possui uma window
    if(this->isOpened()){
        //seta o mouse
        //this->window.Show(show);//1.6
        this->window.setVisible(show);//2.0
    }
    this->renderWindow=show;
}

void Window::showWindow(){
    this->windowRender(true);
}

void Window::hideWindow(){
    this->windowRender(false);
}

void Window::mouseRender(bool show){
    //primeiro testa se possui uma window
    if(this->isOpened()){
        //seta o mouse
        //this->window.ShowMouseCursor(show);//1.6
        this->window.setMouseCursorVisible(show);//2.0
    }
    this->renderMouse=show;
}

void Window::showMouse(){
    //Seta para mostrar o mouse
    this->mouseRender(true);
}

void Window::hideMouse(){
    //Seta para esconder o mouse
    this->mouseRender(false);
}

bool Window::setMousePosition(vec2i32 pos){
    //testa se a janela esta aberta
    if(this->isOpened()){
        //seta a posicao do mouse
        //this->window.SetCursorPosition(pos.x,pos.y);//1.6
        sf::Mouse::setPosition(sf::Vector2i(pos.x,pos.y), this->window);//2.0
        saveMousePos = pos;
        //retorna true
        return true;
    }
    //senao retorna false
    return false;
}

bool Window::setMousePosition(int32 x, int32 y){
    //seta o mouse
    return this->setMousePosition(edk::vec2i32(x,y));
}

bool Window::setWindowPosition(vec2i32 pos){
    //testa se a janela esta aberta
    if(this->isOpened()){
        //seta a posicao do mouse
        //this->window.SetPosition(pos.x,pos.y);//1.6
        this->window.setPosition(sf::Vector2i(pos.x,pos.y));//2.0
        //retorna true
        return true;
    }
    //senao retorna false
    return false;
}

bool Window::setWindowPosition(int32 x, int32 y){
    //
    return this->setWindowPosition(edk::vec2i32(x,y));
}

bool Window::setWindowSize(size2ui32 size){
    //testa se a janela esta aberta
    if(this->isOpened()){
        //save the size of the window
        this->windowSize = size;
        //seta a posicao do mouse
        //this->window.SetSize(size.width,size.height);//1.6
        this->window.setSize(sf::Vector2u(size.width,size.height));//2.0
        //seta o tamanho da view
        this->updateViewSize();
        //retorna true
        return true;
    }
    //senao retorna false
    return false;
}

bool Window::setWindowSize(uint32 width, uint32 height){
    //
    return this->setWindowSize(edk::size2ui32(width,height));
}

//Update the views
void Window::updateViews(){
    //test if have a mousePress ou Release
    if(this->eventMousePressed()){
        //test pressed with views
        this->viewWindow.contact(edk::vec2f32(this->getMousePos().x,this->getMousePos().y),edk::mouse::state::pressed,&this->events.mousePressed);
    }
    if(this->eventMouseMoved()){
        //
        this->viewWindow.contact(edk::vec2f32(this->getMousePos().x,this->getMousePos().y),edk::mouse::state::moved,&this->events.mouseHolded);
    }
    if(this->eventMouseRelease()){
        //test released with views
        this->viewWindow.contact(edk::vec2f32(this->getMousePos().x,this->getMousePos().y),edk::mouse::state::released,&this->events.mouseRelease);
    }

    //update the view
    this->updateView(&this->viewWindow);
}
//update the viewGU
void Window::updateView(edk::View* view){
    //test the viewGU
    if(view){
        this->events.mousePos.x -= (edk::int32)view->animatedFrame.origin.x;
        this->events.mousePos.y -= (edk::int32)view->animatedFrame.origin.y;
        //update the envents on the view
        view->updateView(&this->events);
        //update the animations on the view
        view->updateAnimations();
        //tets if is not a leaf
        if(!view->isLeaf()){
            //load the temp
            edk::ViewController* temp=(edk::ViewController*)view;
            //then search anothers views
            for(edk::uint64 i=0u;i<temp->getCount();i++){
                //load the nextView
                edk::ViewController* tempController = (edk::ViewController*)temp->getSubview(i);
                //test if have the nextView
                if(tempController){
                    //then test if is a ViewGU
                    this->updateView(tempController);
                }
            }
        }
        this->events.mousePos.x += (edk::int32)view->animatedFrame.origin.x;
        this->events.mousePos.y += (edk::int32)view->animatedFrame.origin.y;
    }
}
//contactView
void Window::mousePressView(edk::ViewController* view, edk::vec2i32 point, edk::vector::Stack<edk::uint32> buttons){
    //
    if(view && point.x){
        //remove the warning
    }
    //buttons cant delete
    buttons.cantDestroy();
}
void Window::mouseReleaseView(edk::ViewController* view, edk::vec2i32 point, edk::vector::Stack<edk::uint32> buttons){
    //
    if(view && point.x){
        //remove the warning
    }

    //buttons cant delete
    buttons.cantDestroy();
}

bool Window::drawStart(){
    //Tetsa se finalizou o render antes e se a janela esta aberta
    if(!this->activeRender && this->isOpened()){
        //pode setar o render
        //this->window.SetActive(true);//1.6
        this->window.setActive(true);//2.0
        //seta activeRender como true
        this->activeRender=true;
        //retorna true
        return true;
    }
    //senao retorna false
    return false;
}

bool Window::drawEnd(){
    //Tetsa se iniciou o render antes e se a janela esta aberta
    if(this->activeRender && this->isOpened()){
        //pode setar o render
        //this->window.SetActive(false);//1.6
        this->window.setActive(false);//2.0
        //seta activeRender como false
        this->activeRender=false;
        //retorna true
        return true;
    }
    //senao retorna false
    return false;
}

void Window::drawView(){
    //Start the draw
    this->drawStart();

    //load the identity matrix
    edk::GU::guLoadIdentity();

    //Set the clean color to the first view backGroundColor
    this->viewWindow.backgroundColor(this->cleanColor.r,
                                     this->cleanColor.g,
                                     this->cleanColor.b,
                                     1.f
                                     );

    //draw the view
    this->viewWindow.draw(
                this->viewWindow.frame
                );

    //End the drawing
    this->drawEnd();
}

bool Window::flip(){
    //testa se possui uma janela e se ja desenhou
    if(this->isOpened() && !this->activeRender){
        //Pode renderizar na tela
        //this->window.Display();//1.6
        this->window.display();//2.0
        //retorna true
        return true;
    }
    //senao retorna false
    return false;
}

bool Window::render(){
    //
    return this->flip();
}

size2ui32 Window::getSize(){
    //testa se a janela esta aberta
    edk::size2ui32 ret(0u,0u);
    if(this->isOpened()){
        //retorna o tamanho da window
        /*
        ret = edk::size2ui32((edk::uint32)this->window.GetDefaultView().GetRect().GetWidth(),
                     (edk::uint32)this->window.GetDefaultView().GetRect().GetHeight()
                     );
        */
        ret = this->windowSize;
    }
    //senao retorna um tamanho zerado
    return ret;
}

size2ui32 Window::getScreenSize(){
    //testa se a janela esta aberta
    edk::size2ui32 ret(0u,0u);
    if(this->isOpened()){
        //retorna o tamanho da view
        //ret = edk::size2ui32(this->window.GetWidth(),this->window.GetHeight());//1.6
        ret = edk::size2ui32(this->window.getSize().x,this->window.getSize().y);//2.0
    }
    //senao retorna um tamanho zerado
    return ret;
}

uint32 Window::getWidth(){
    //
    if(this->isOpened()){
        //
        //return this->window.GetWidth();//1.6
        return this->window.getSize().x;//2.0
    }
    //senao retorna 0u
    return 0u;
}

uint32 Window::getHeight(){
    //
    if(this->isOpened()){
        //
        //return this->window.GetHeight();//1.6
        return this->window.getSize().y;//2.0
    }
    //senao retorna 0u
    return 0u;
}

vec2i32 Window::getMousePos(){
    //
    //senao retorna uma posicao zerada
    //return this->mousePos;
    return this->events.mousePosWindow;
}

vec2i32 Window::eventGetMouseMoved(){
    //
    //return this->mouseMove;
    return this->events.mouseMove;
}

bool Window::eventLostFocus(){
    return this->events.lostFocus;
}

bool Window::eventGainedFocus(){
    return this->events.gainedFocus;
}

bool Window::eventButtonClose(){
    //
    bool temp = events.buttonExit;
    events.buttonExit=false;
    return temp;
}

bool Window::eventKeyPressed(){
    //
    return (bool)this->eventGetKeyPressedSize();
}

bool Window::eventKeyRelease(){
    //
    return (bool)this->eventGetKeyReleaseSize();
}

bool Window::eventKeyHolded(){
    return (bool)this->eventGetKeyHoldedSize();
}

uint32 Window::eventGetKeyPressedSize(){
    //Retorna o tamanho do vector
    return this->events.keyPressed.size();
}

uint32 Window::eventGetKeyReleaseSize(){
    //Retorna o tamanho do vetor
    return this->events.keyRelease.size();
}

uint32 Window::eventGetKeyHoldedSize(){
    return this->events.keyHolded.size();
}

uint32 Window::eventGetKeyPressed(uint32 pos){
    //
    if(pos<this->events.keyPressed.size()){
        //
        return this->events.keyPressed[pos];
    }
    //senao retorna 0u
    return 0u;
}

uint32 Window::eventGetKeyRelease(uint32 pos){
    if(pos<this->events.keyRelease.size()){
        //
        return this->events.keyRelease[pos];
    }
    //senao retorna 0u
    return 0u;
}

uint32 Window::eventGetKeyHolded(uint32 pos){

    if(pos<this->events.keyHolded.size()){
        //
        return this->events.keyHolded[pos];
    }
    //senao retorna 0u
    return 0u;
}

bool Window::eventMousePressed(){
    //
    return (bool)this->eventGetMousePressedSize();
}

bool Window::eventMouseRelease(){
    //
    return (bool)this->eventGetMouseReleaseSize();
}

bool Window::eventMouseHolded(){
    return (bool)this->eventGetMouseHoldedSize();
}

uint8 Window::eventGetMousePressedSize(){
    //
    return this->events.mousePressed.size();
}

uint8 Window::eventGetMouseReleaseSize(){
    //
    return this->events.mouseRelease.size();
}

uint8 Window::eventGetMouseHoldedSize(){
    //
    return this->events.mouseHolded.size();
}

uint8 Window::eventGetMousePressed(uint32 pos){
    //
    if(pos<this->events.mousePressed.size()){
        //
        return this->events.mousePressed[pos];
    }
    //senao retorna false
    return false;
}

uint8 Window::eventGetMouseRelease(uint32 pos){
    //
    if(pos<this->events.mouseRelease.size()){
        //
        return this->events.mouseRelease[pos];
    }
    //senao retorna false
    return false;
}

uint8 Window::eventGetMouseHolded(uint32 pos){
    //
    if(pos<this->events.mouseHolded.size()){
        //
        return this->events.mouseHolded[pos];
    }
    //senao retorna false
    return false;
}

bool Window::eventMouseEnter(){
    //
    return this->events.mouseEnter;
}

bool Window::eventMouseExit(){
    //
    return this->events.mouseExit;
}

bool Window::eventMouseMoved(){
    //retorna se o mouse foi movido
    return this->events.mouseMoved;
}

int8 Window::getMouseScrollWheel(){
    //
    return (int8)this->events.mouseScrollWheel;
}

bool Window::eventResizeWindow(){
    //retorna se redimencionou a janela
    return this->events.resize;
}

size2i32 Window::getResize(){
    //
    return this->events.resizePos;
}

bool Window::loadEvents(){
    this->updateControllerEvents();
    //Limpa os eventos
    this->cleanEvents();

    //Eventos da janela
    sf::Event event;
    //Input da janela
    //const sf::Input& input=window.GetInput();//1.6
    //2.0

    //while(window.GetEvent(event)){//1.6
    while(window.pollEvent(event)){//2.0
        //processa os eventos
        ///////////////////////////////////////////////////////////
        //JANELA FECHANDO
        //if(event.Type == sf::Event::Closed){//1.6
        if(event.type == sf::Event::Closed){//2.0
            //
            this->events.buttonExit=true;
        }
        //if(event.Type == sf::Event::LostFocus){//1.6
        if(event.type == sf::Event::LostFocus){//2.0
            //Minimize
            this->events.lostFocus=true;
            this->events.focus = false;
        }
        //if(event.Type == sf::Event::GainedFocus){//1.6
        if(event.type == sf::Event::GainedFocus){//2.0
            //unMinimize
            this->events.gainedFocus=true;
            this->events.focus=true;
        }
        ///////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////
        //PRESSIONOU TECLA
        //if(event.Type == sf::Event::KeyPressed){//1.6
        if(event.type == sf::Event::KeyPressed){//2.0
            //carrega a tecla pressionada
            //this->events.keyPressed.pushBack(event.Key.Code);//1.6
            //printf("\nKey Pressed %d",event.key.code);fflush(stdout);
            if(event.key.code>=0&&event.key.code<26){
                this->events.keyPressed.pushBack(event.key.code+'a') ;//2.0
            }
            else if(event.key.code>=26&&event.key.code<36){
                this->events.keyPressed.pushBack(event.key.code+ '0' - 26) ;//2.0
            }
            else if(event.key.code>=75&&event.key.code<85){
                this->events.keyPressed.pushBack(event.key.code+ '0' - 75) ;//2.0
            }
            else{
                this->events.keyPressed.pushBack(event.key.code+256 - 36) ;//2.0
            }
        }
        //FIM PRESSIONOU TECLA
        ///////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////
        //RETIROU DA PRESSAO A TECLA
        //if(event.Type == sf::Event::KeyReleased){//1.6
        if(event.type == sf::Event::KeyReleased){//2.0
            //carrega a tecla pressionada
            //this->events.keyRelease.pushBack(event.Key.Code);//1.6
            if(event.key.code>=0&&event.key.code<26){
                this->events.keyRelease.pushBack(event.key.code+'a') ;//2.0
            }
            else if(event.key.code>=26&&event.key.code<36){
                this->events.keyRelease.pushBack(event.key.code+ '0' - 26) ;//2.0
            }
            else if(event.key.code>=75&&event.key.code<85){
                this->events.keyRelease.pushBack(event.key.code+ '0' - 75) ;//2.0
            }
            else{
                this->events.keyRelease.pushBack(event.key.code+256 - 36) ;//2.0
            }
        }
        //FIM RETIROU DA PRESSAO A TECLA
        ///////////////////////////////////////////////////////////


        ///////////////////////////////////////////////////////////
        //REDIMENCIONAMENTO DA JANELA
        //if(event.Type == sf::Event::Resized){//1.6
        if(event.type == sf::Event::Resized){//2.0
            /*
                sf::FloatRect NewSize(0, 0, event.Size.Width, event.Size.Height);
                window.GetDefaultView().SetFromRect(NewSize);
                */
            //resize true
            this->events.resize=true;
            //edk::size2ui32 tempView = edk::size2ui32(window.GetWidth(),window.GetHeight());//1.6
            edk::size2ui32 tempView = edk::size2ui32(window.getSize().x,window.getSize().y);//2.0
            //resizePos
            //this->resizePos = edk::size2i32(window.GetWidth(),window.GetHeight());
            /*
                this->resizePos = edk::size2i32(this->windowSize.width,this->windowSize.height) -
                                  edk::size2i32(tempView.width,tempView.height)
                                                ;
                */
            this->events.resizePos.width += (edk::int32)tempView.width - (edk::int32)this->windowSize.width;
            this->events.resizePos.height+= (edk::int32)tempView.height- (edk::int32)this->windowSize.height;

            //set the new size of the window
            this->windowSize = tempView;
            this->events.windowSize = this->windowSize;

            //Seta o tamanho da janela
            this->updateViewSize();
        }
        ///////////////////////////////////////////////////////////




        ///////////////////////////////////////////////////////////
        //MOUSE PRESSIONADO
        //if(event.Type == sf::Event::MouseButtonPressed){//1.6
        if(event.type == sf::Event::MouseButtonPressed){//2.0
            //
            //this->events.mousePressed.pushBack(event.MouseButton.Button+1u);//1.6
            this->events.mousePressed.pushBack(event.mouseButton.button+1u);//2.0

            this->mouseInside=true;
        }
        //FIM DO MOUSE PRESSIONADO
        ///////////////////////////////////////////////////////////




        ///////////////////////////////////////////////////////////
        //MOUSE ENTROU SAIU DA JANELA
        //if(event.Type == sf::Event::MouseEntered){//1.6
        if(event.type == sf::Event::MouseEntered){//2.0
            //
            this->events.mouseEnter=true;

            this->mouseInside=true;
        }
        //if(event.Type == sf::Event::MouseLeft){//1.6
        if(event.type == sf::Event::MouseLeft){//2.0
            //
            this->events.mouseExit=true;

            this->mouseInside=false;
        }
        //FIM DO MOUSE ENTROU SAIU DA JANELA
        ///////////////////////////////////////////////////////////





        ///////////////////////////////////////////////////////////
        //MOUSE SOLTO
        //if(event.Type == sf::Event::MouseButtonReleased){//1.6
        if(event.type == sf::Event::MouseButtonReleased){//2.0
            //
            //this->events.mouseRelease.pushBack(event.MouseButton.Button+1u);//1.6
            this->events.mouseRelease.pushBack(event.mouseButton.button+1u);//2.0
        }
        //FIM DO MOUSE SOLTO
        ///////////////////////////////////////////////////////////










        ///////////////////////////////////////////////////////////
        //MOUSE MOVIDO
        //if(event.Type == sf::Event::MouseMoved){//1.6
        if(event.type == sf::Event::MouseMoved){//2.0
            //
            this->events.mouseMoved=true;

            //Carrega a nova posicao do mouse
            edk::vec2ui32 mouseTemp = edk::vec2ui32((edk::uint32)sf::Mouse::getPosition(this->window).x,(edk::uint32)sf::Mouse::getPosition(this->window).y);//2.0
            //Calcula a distancia movida
            this->events.mouseMove = edk::vec2i32((edk::int32)mouseTemp.x-(edk::int32)this->saveMousePos.x,
                                                  (edk::int32)mouseTemp.y-(edk::int32)this->saveMousePos.y
                                                  );
            //salva a nova posicao do mouse
            this->events.mousePos = edk::vec2i32(mouseTemp.x,mouseTemp.y);
        }
        else{
            this->events.mouseMove = edk::vec2i32(0,0);
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
                       );
                */
            //this->events.mouseScrollWheel=event.MouseWheel.Delta;//1.6
            this->events.mouseScrollWheel=event.mouseWheel.delta;//2.0

            this->mouseInside=true;
        }
        //FIM MOUSE SCROLL
        ///////////////////////////////////////////////////////////

        //if(event.Type == sf::Event::JoyButtonPressed){//1.6
        if(event.type == sf::Event::JoystickButtonPressed){//2.0
/*
                printf("\nJoyButtonPressed joy == %u button == %u"
                       ,event.joystickButton.joystickId
                       ,event.joystickButton.button
                       );fflush(stdout);
*/
                this->events.controllerPressed.addButton(event.joystickButton.joystickId,event.joystickButton.button);
        }

        //if(event.Type == sf::Event::JoyButtonPressed){//1.6
        if(event.type == sf::Event::JoystickButtonReleased){//2.0
/*
                printf("\nJoyButtonReleased joy == %u button == %u"
                       ,event.joystickButton.joystickId
                       ,event.joystickButton.button
                       );fflush(stdout);
*/
                this->events.controllerReleased.addButton(event.joystickButton.joystickId,event.joystickButton.button);
        }


        //if(event.Type == sf::Event::JoyButtonPressed){//1.6
        if(event.type == sf::Event::JoystickMoved){//2.0
/*
                printf("\nJoyMoved joy == %u position == %.2f axis %u"
                       ,event.joystickMove.joystickId
                       ,event.joystickMove.position
                       ,event.joystickMove.axis
                       );fflush(stdout);
*/
            //test if it's the Y
            if(event.joystickMove.axis<<(sizeof(event.joystickMove.axis)*8)-1u){
                this->events.controllerAxisMoved.addAxis(event.joystickMove.joystickId,event.joystickMove.axis,event.joystickMove.position*-1.f);
            }
            else{
                this->events.controllerAxisMoved.addAxis(event.joystickMove.joystickId,event.joystickMove.axis,event.joystickMove.position);
            }
        }




    }
    //load mousePosition
    //events.mousePosWindow = events.mousePos = edk::vec2i32( input.GetMouseX(),input.GetMouseY());//1.6
    events.mousePosWindow = events.mousePos = edk::vec2i32( sf::Mouse::getPosition(this->window).x,sf::Mouse::getPosition(this->window).y);//2.0
    this->saveMousePos.x = this->events.mousePos.x;
    this->saveMousePos.y = this->events.mousePos.y;
    events.mousePosWorld = edk::vec2i32( sf::Mouse::getPosition().x,sf::Mouse::getPosition().y);//2.0

    //save focus
    this->windowFocus = this->events.focus;

    //test if have focus
    if(this->windowFocus){
        //load the holded keys
        for(edk::int32 i=sf::Keyboard::A;i<sf::Keyboard::KeyCount;i=i+1){
            if(sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i)){
                if(i>=0&&i<26)
                    this->events.keyHolded.pushBack(i+'a') ;//2.0
                else if(i>=26&&i<36)
                    this->events.keyHolded.pushBack(i+ '0' - 26) ;//2.0
                else
                    this->events.keyHolded.pushBack(i+256 - 36) ;//2.0
            }
        }

        if(this->mouseInside){
            //load the holded mouse button
            for(edk::int32 i=sf::Mouse::Left ;i<sf::Mouse::ButtonCount;i=i+1){
                if(sf::Mouse::isButtonPressed((sf::Mouse::Button)i)){
                    this->events.mouseHolded.pushBack(i+1u);
                }
            }
        }
    }

    //Testa os controlers
    /*
        for(edk::uint32 i=0u;i<2u;i++){
            //Adiciona o novo controler
            edk::Window::ctrlPressed temp;
            this->controllerPressed.push_back(temp);
            for(edk::uint32 j=0u;j<=15u;j++){
                //adiciona os valores
                if(input.IsJoystickButtonDown(i, j)){
                    //
                    printf("\nBotao %u controle %u"
                           ,i
                           ,j
                           );
                    }
            }
        }
*/

    //senao retorna false
    return false;
}

size2ui32 Window::getDesktopSize(){
    //Carrega o modo do desktop
    //sf::VideoMode DesktopMode = sf::VideoMode::GetDesktopMode();//1.6
    sf::VideoMode DesktopMode = sf::VideoMode::getDesktopMode();//2.0
    //seta o retorno
    //edk::size2ui32 temp(DesktopMode.Width,DesktopMode.Height);//1.6
    edk::size2ui32 temp(DesktopMode.width,DesktopMode.height);//2.0
    //carrega o desktop mode
    return temp;
}

uint32 Window::getDesktopBitsPerPixel(){
    //Carrega o modo do desktop
    //sf::VideoMode DesktopMode = sf::VideoMode::GetDesktopMode();//1.6
    sf::VideoMode DesktopMode = sf::VideoMode::getDesktopMode();//2.0
    //retorna os bits
    //return DesktopMode.BitsPerPixel;//1.6
    return DesktopMode.bitsPerPixel;//2.0
}

//test if have a controller
bool Window::haveController(edk::uint32 controller){
    if (sf::Joystick::isConnected(controller)){
        return true;
    }
    return false;
}
//return the number of buttons of a controller
edk::uint32 Window::getControllerButtonCount(edk::uint32 controller){
    // check how many buttons joystick number 0 has
    return sf::Joystick::getButtonCount(controller);
}

bool Window::eventControllerButtonPressed(edk::uint32 controller){
    return (bool)this->eventGetControllerButtonPressedSize(controller);
}

bool Window::eventControllerButtonRelease(edk::uint32 controller){
    return (bool)this->eventGetControllerButtonReleaseSize(controller);
}

bool Window::eventControllerButtonHolded(edk::uint32 controller){
    return (bool)this->eventGetControllerButtonHoldedSize(controller);
}

bool Window::eventControllerAxisMoved(edk::uint32 controller){
    return (bool)this->eventGetControllerAxisMovedSize(controller);
}

uint8 Window::eventGetControllerButtonPressedSize(edk::uint32 controller){
    return this->events.controllerPressed.getControllerButtonSizeInPosition(controller);
}

uint8 Window::eventGetControllerButtonReleaseSize(edk::uint32 controller){
    return this->events.controllerReleased.getControllerButtonSizeInPosition(controller);
}

uint8 Window::eventGetControllerButtonHoldedSize(edk::uint32 controller){
    return this->events.controllerHolded.getControllerButtonSizeInPosition(controller);
}

uint8 Window::eventGetControllerAxisMovedSize(edk::uint32 controller){
    return this->events.controllerAxisMoved.getControllerButtonSizeInPosition(controller);
}

uint8 Window::eventGetControllerButtonPressed(edk::uint32 controller, uint32 pos){
    return this->events.controllerPressed.getControllerButtonInPosition(controller,pos);
}

uint8 Window::eventGetControllerButtonRelease(edk::uint32 controller, uint32 pos){
    return this->events.controllerReleased.getControllerButtonInPosition(controller,pos);
}

uint8 Window::eventGetControllerButtonHolded(edk::uint32 controller, uint32 pos){
    return this->events.controllerHolded.getControllerButtonInPosition(controller,pos);
}

uint32 Window::eventGetControllerAxisIDMoved(edk::uint32 controller, uint32 pos){
    return this->events.controllerAxisMoved.getControllerAxisInPosition(controller,pos);
}

float32 Window::eventGetControllerAxisMoved(edk::uint32 controller, uint32 pos){
    return this->events.controllerAxisMoved.getControllerAxisValueInPosition(controller,pos);
}

float32 Window::eventGetControllerAxisMovedByID(edk::uint32 controller, uint32 id){
    return this->events.controllerAxisMoved.getControllerAxisValueByID(controller,id);
}

} /* End of namespace edk */
