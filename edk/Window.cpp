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

//Atualiza o tamanho da view
void edk::Window::updateViewSize(){
    //seta o tamanho da view
    this->viewWindow.animatedFrame = this->viewWindow.frame=edk::rectf32(0.f,0.f,(edk::float32)this->getScreenSize().width,(edk::float32)this->getScreenSize().height);
}

void edk::Window::cleanEvents(){
    //
    this->events.clean();
}
//update joystick events
void edk::Window::updateControllerEvents(){
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


edk::Window::Window(){
    this->classThis=NULL;
    this->Constructor();
}

edk::Window::~Window(){
    this->Destructor();
}

void edk::Window::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        this->viewWindow.Constructor();
        this->time.Constructor();
        this->events.Constructor();
#if defined(EDK_WINDOW_EVENTS_RW)
        this->saveEvents.Constructor();
        this->fileEvents.Constructor();
        this->treeEventTypes.Constructor();
#endif

        //por padrao a window e o mouse sao renderizados
        this->renderMouse = true;
        this->renderWindow = true;
        this->activeRender = false;
        this->windowFocus = true;
        this->mouseInside=false;
        this->cleanEvents();
        this->time.start();
#if defined(EDK_WINDOW_EVENTS_RW)
        this->fileEvents.closeFile();
        this->playingWriteEvents=false;
        this->playingReadEvents=false;
        this->pausedFileEvents=false;
        this->saveHaveEvents=true;
        this->nextSecondEvents=0.f;
        this->secondEvents=0.f;
        this->saveEvents.clean();
#endif

        this->vsync=true;
    }
}
void edk::Window::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        //clean the events
        this->cleanEvents();
#if defined(EDK_WINDOW_EVENTS_RW)
        this->fileEvents.closeFile();
        this->treeEventTypes.clean();
#endif

        this->viewWindow.Destructor();
        this->time.Destructor();
        this->events.Destructor();
#if defined(EDK_WINDOW_EVENTS_RW)
        this->saveEvents.Destructor();
        this->fileEvents.Destructor();
        this->treeEventTypes.Destructor();
#endif
    }
}

bool edk::Window::createWindow(uint32 width, uint32 height/*, uint32 bitsPerPixel*/, char8 *name, typeID design, uint32 depth, uint32 stencil, uint32 antialiasing){
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
        //this->window.Create(sf::VideoMode(width, height, bitsPerPixel),(const edk::char8*)name,style,sf::WindowSettings(depth,stencil,antialiasing));//1.6
        this->window.create(sf::VideoMode(width, height, bitsPerPixel),(const edk::char8*)name,style,sf::ContextSettings(depth,stencil,antialiasing));//2.0

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

            //use vsync in the window
            this->window.setVerticalSyncEnabled(this->vsync);

            this->window.setActive(true);

            //Seta o tamanho da window
            this->setWindowSize(this->window.getSize().x,this->window.getSize().y);

            edk::GU::guOpen();
            edk::GU_GLSL::guShaderInit();

            //set the blend with alpha channel
            edk::GU::guEnable(GU_BLEND);
            edk::GU::guBlendFunc(GU_SRC_ALPHA,GU_ONE_MINUS_SRC_ALPHA);

            this->time.start();
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
                              );
}

bool edk::Window::createWindow(uint32  width, uint32  height/*, uint32  bitsPerPixel*/, char8 *name, typeID design){
    //
    return this->createWindow(width,height/*,bitsPerPixel*/,
                              name,
                              design,
                              24u,8u,0u
                              );
}

bool edk::Window::createWindow(uint32  width, uint32  height/*, uint32  bitsPerPixel*/, const char *name, typeID  design){
    return this->createWindow(width, height/*, bitsPerPixel*/,
                              (char8 *)name,
                              design,
                              24u,8u,0u
                              );
}

bool edk::Window::setWindowName(const edk::char8 *name){
    return this->setWindowName((edk::char8 *)name);
}
bool edk::Window::setWindowName(edk::char8 *name){
    if(this->isOpened()){
        this->window.setTitle(name);
        return true;
    }
    return false;
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
    return this->renderWindow;
}

bool edk::Window::haveFocus(){
    //
    return this->windowFocus;
    //return this->events.focus;
}

void edk::Window::closeWindow(){
    edk::GU::guDisable(GU_BLEND);
    //
    //if(this->window.IsOpened()){//1.6
    if(this->window.isOpen()){//2.0
        //
        //this->window.Close();//1.6
        this->window.close();//2.0

        //set init the GU
        edk::GU::guClose();
    }
}

void edk::Window::setVSYNC(bool vsync){
    if(this->vsync!=vsync){
        this->vsync=vsync;
        if(this->window.isOpen()){
            this->window.setVerticalSyncEnabled(this->vsync);
        }
    }
}
void edk::Window::enableVSYNC(){
    this->setVSYNC(true);
}
void edk::Window::disableVSYNC(){
    this->setVSYNC(false);
}
bool edk::Window::isUsingVSYNC(){
    return this->vsync;
}

void edk::Window::clean(){
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

edk::uint32 edk::Window::getViewCount(){
    //
    return this->viewWindow.getCount();
}

bool edk::Window::addSubview(View *addView){
    //Add the view to the viewWindow
    return this->viewWindow.addSubview(addView);
}

edk::View* edk::Window::getSubview(uint64 n){
    return this->viewWindow.getSubview(n);
}

edk::uint64 edk::Window::getSubviewId(View *subView){
    return this->viewWindow.getSubviewId(subView);
}

void edk::Window::removeSubview(View *subView){
    //
    this->viewWindow.removeSubview(subView);
}

void edk::Window::removeAllSubview(){
    this->viewWindow.removeAllSubview();
}

void edk::Window::windowRender(bool show){
    //primeiro testa se possui uma window
    if(this->isOpened()){
        //seta o mouse
        //this->window.Show(show);//1.6
        this->window.setVisible(show);//2.0
    }
    this->renderWindow=show;
}

void edk::Window::showWindow(){
    this->windowRender(true);
}

void edk::Window::hideWindow(){
    this->windowRender(false);
}

void edk::Window::mouseRender(bool show){
    //primeiro testa se possui uma window
    if(this->isOpened()){
        //seta o mouse
        //this->window.ShowMouseCursor(show);//1.6
        this->window.setMouseCursorVisible(show);//2.0
    }
    this->renderMouse=show;
}

void edk::Window::showMouse(){
    //Seta para mostrar o mouse
    this->mouseRender(true);
}

void edk::Window::hideMouse(){
    //Seta para esconder o mouse
    this->mouseRender(false);
}

bool edk::Window::setMousePosition(vec2i32 pos){
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

bool edk::Window::setMousePosition(int32 x, int32 y){
    //seta o mouse
    return this->setMousePosition(edk::vec2i32(x,y));
}

bool edk::Window::setWindowPosition(vec2i32 pos){
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

bool edk::Window::setWindowPosition(int32 x, int32 y){
    //
    return this->setWindowPosition(edk::vec2i32(x,y));
}

bool edk::Window::setWindowSize(size2ui32 size){
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

bool edk::Window::setWindowSize(uint32 width, uint32 height){
    //
    return this->setWindowSize(edk::size2ui32(width,height));
}

//Update the views
void edk::Window::updateViews(){
    //test if have a mousePress ou Release
    if(this->eventMousePressed()){
        //test pressed with views
        this->viewWindow.contact(edk::vec2f32(this->getMousePos().x,this->getMousePos().y),
                                 edk::vec2f32(this->eventGetMouseMoved().x,this->eventGetMouseMoved().y),
                                 edk::mouse::state::pressed,
                                 &this->events.mousePressed);
    }
    if(this->eventMouseMoved()){
        //
        this->viewWindow.contact(edk::vec2f32(this->getMousePos().x,this->getMousePos().y),
                                 edk::vec2f32(this->eventGetMouseMoved().x,this->eventGetMouseMoved().y),
                                 edk::mouse::state::moved,
                                 &this->events.mouseHolded);
    }
    if(this->eventMouseRelease()){
        //test released with views
        this->viewWindow.contact(edk::vec2f32(this->getMousePos().x,this->getMousePos().y),
                                 edk::vec2f32(this->eventGetMouseMoved().x,this->eventGetMouseMoved().y),
                                 edk::mouse::state::released,
                                 &this->events.mouseRelease);
    }
    if(this->eventMouseDoubleClick()){
        //test released with views
        this->viewWindow.contact(edk::vec2f32(this->getMousePos().x,this->getMousePos().y),
                                 edk::vec2f32(this->eventGetMouseMoved().x,this->eventGetMouseMoved().y),
                                 edk::mouse::state::doubleClicked,
                                 &this->events.mouseRelease);
    }

    //update the view
    this->updateView(&this->viewWindow,edk::vec2f32(0.f,0.f));
}
//update the viewGU
void edk::Window::updateView(edk::View* view,edk::vec2f32 screenPosition){
    //test the viewGU
    if(view){
        this->events.mousePos.x -= (edk::int32)view->animatedFrame.origin.x;
        this->events.mousePos.y -= (edk::int32)view->animatedFrame.origin.y;
        //update the position in the screen
        view->positionInWindow=view->frame.origin+screenPosition;
        //update the animations on the view
        view->updateAnimations(this->events.secondPassed);
        //update the envents on the view
        view->updateView(&this->events);
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
                    this->updateView(tempController,view->positionInWindow);
                }
            }
        }
        this->events.mousePos.x += (edk::int32)view->animatedFrame.origin.x;
        this->events.mousePos.y += (edk::int32)view->animatedFrame.origin.y;
    }
}
//contactView
void edk::Window::mousePressView(edk::ViewController* view, edk::vec2i32 point, edk::vector::Stack<edk::uint32> /*buttons*/){
    //
    if(view && point.x){
        //remove the warning
    }
}
void edk::Window::mouseReleaseView(edk::ViewController* view, edk::vec2i32 point, edk::vector::Stack<edk::uint32> /*buttons*/){
    //
    if(view && point.x){
        //remove the warning
    }
}
void edk::Window::mouseDoubleClickView(edk::ViewController* view, edk::vec2i32 point, edk::vector::Stack<edk::uint32> /*buttons*/){
    //
    if(view && point.x){
        //remove the warning
    }
}

bool edk::Window::drawStart(){
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

bool edk::Window::drawEnd(){
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

void edk::Window::drawView(){
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

void edk::Window::runPauseSwitchViews(){
    this->viewWindow.runPauseSwitch();
}

void edk::Window::runPauseViews(){
    this->viewWindow.runPause();
}
void edk::Window::pauseViews(){
    this->viewWindow.runPause();
}

void edk::Window::runUnpauseViews(){
    this->viewWindow.runUnpause();
    //after unpause the views, start the time to generate new seconds because, if it's not started
    //it will get all the time where the views was paused
    this->time.start();
}
void edk::Window::unpauseViews(){
    this->viewWindow.runUnpause();
    //after unpause the views, start the time to generate new seconds because, if it's not started
    //it will get all the time where the views was paused
    this->time.start();
}

bool edk::Window::isPaused(){
    return this->viewWindow.isPaused();
}

bool edk::Window::flip(){
    //testa se possui uma janela e se ja desenhou
    if(this->isOpened() && !this->activeRender){
        //Pode renderizar na tela
        //this->window.Display();//1.6
        this->window.display();//2.0
        //update the loadTexture from GU
        edk::GU::guUpdateLoadTextures();
        edk::GU_GLSL::guUpdateCreateShaders();
        //retorna true
        return true;
    }
    //update the loadTexture from GU
    edk::GU::guUpdateLoadTextures();
    edk::GU_GLSL::guUpdateCreateShaders();
    //senao retorna false
    return false;
}

bool edk::Window::render(){
    return this->flip();
}

edk::size2ui32 edk::Window::getSize(){
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

edk::size2ui32 edk::Window::getScreenSize(){
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

edk::uint32 edk::Window::getWidth(){
    //
    if(this->isOpened()){
        //
        //return this->window.GetWidth();//1.6
        return this->window.getSize().x;//2.0
    }
    //senao retorna 0u
    return 0u;
}

edk::uint32 edk::Window::getHeight(){
    //
    if(this->isOpened()){
        //
        //return this->window.GetHeight();//1.6
        return this->window.getSize().y;//2.0
    }
    //senao retorna 0u
    return 0u;
}

edk::vec2i32 edk::Window::getMousePos(){
    //
    //senao retorna uma posicao zerada
    //return this->mousePos;
    return this->events.mousePosWindow;
}

edk::vec2i32 edk::Window::eventGetMouseMoved(){
    //
    //return this->mouseMove;
    return this->events.mouseMove;
}

//test if the events have something
bool edk::Window::eventsHaveSomething(){
    return this->events.haveSomething();
}
bool edk::Window::haveSomethingTypes(edk::EventWindowType types, ...){
    return this->events.haveSomethingTypes(types);
}

//start writing events into a file
bool edk::Window::startWriteEvents(edk::char8*
#if defined(EDK_WINDOW_EVENTS_RW)
                                   fileName
#endif
                                   ){
    this->stopWriteEvents();
#if defined(EDK_WINDOW_EVENTS_RW)
    //create the file
    if(this->fileEvents.createAndOpenBinFile(fileName)){
        this->playingWriteEvents=true;
        this->pausedFileEvents=false;
        return true;
    }
#else
    printf("\n%u %s %s ERROR: Tu use this function you need define EDK_WINDOW_EVENTS_RW",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
    return false;
}
bool edk::Window::startWriteEvents(const edk::char8* fileName){
    return this->startWriteEvents((edk::char8*) fileName);
}
bool edk::Window::startWriteEvents(edk::char8*
                                   fileName
                                   ,edk::EventWindowType
                                   #if defined(EDK_WINDOW_EVENTS_RW)
                                   types
                                   #endif
                                   , ...){
    //create the file
    if(this->startWriteEvents(fileName)){
#if defined(EDK_WINDOW_EVENTS_RW)
        bool first=true;
        edk::uint32 typeTemp;
        edk::EventWindowType type=edk::eventWindowNothing;
        va_list vl;
        //
        typeTemp = (edk::uint32)types;
        while(typeTemp){
            type = (edk::EventWindowType)(typeTemp);
            this->treeEventTypes.add(type);
            if(first){
                va_start(vl,types);
                first=false;
            }
            typeTemp = va_arg(vl,edk::uint32);
        }
        if(this->treeEventTypes.size()){
            return true;
        }
        //else stop write events
        this->stopWriteEvents();
#else
        printf("\n%u %s %s ERROR: Tu use this function you need define EDK_WINDOW_EVENTS_RW",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
    }
    return false;
}
bool edk::Window::startWriteEvents(const edk::char8* fileName,edk::EventWindowType types, ...){
    return this->startWriteEvents((edk::char8*) fileName,types);
}
//start reading events from a file
bool edk::Window::startReadEvents(edk::char8*
#if defined(EDK_WINDOW_EVENTS_RW)
                                  fileName
#endif
                                  ){
    this->stopReadEvents();
#if defined(EDK_WINDOW_EVENTS_RW)
    //create the file
    if(this->fileEvents.openBinFile(fileName)){
        this->playingReadEvents=true;
        //read the first second
        this->fileEvents.readBin(&this->nextSecondEvents,sizeof(this->nextSecondEvents));
        return true;
    }
#else
    printf("\n%u %s %s ERROR: Tu use this function you need define EDK_WINDOW_EVENTS_RW",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
    return false;
}
bool edk::Window::startReadEvents(const edk::char8* fileName){
    return this->startReadEvents((edk::char8*) fileName);
}
//get the events status
bool edk::Window::isWritingEventsFile(){
#if defined(EDK_WINDOW_EVENTS_RW)
    return this->playingWriteEvents;
#else
    return false;
#endif
}
bool edk::Window::isReadingEventsFile(){
#if defined(EDK_WINDOW_EVENTS_RW)
    return this->playingReadEvents;
#else
    return false;
#endif
}
bool edk::Window::isPlayingWriteEventsFile(){
#if defined(EDK_WINDOW_EVENTS_RW)
    return this->playingWriteEvents;
#else
    return false;
#endif
}
bool edk::Window::isPlayingReadEventsFile(){
#if defined(EDK_WINDOW_EVENTS_RW)
    return this->playingReadEvents;
#else
    return false;
#endif
}

//stop writing the events into a file
void edk::Window::stopWriteEvents(){
#if defined(EDK_WINDOW_EVENTS_RW)
    this->fileEvents.closeFile();
    this->treeEventTypes.clean();
    this->playingWriteEvents=false;
    this->playingReadEvents=false;
    this->pausedFileEvents=false;
    this->secondEvents=0.f;
#endif
}
void edk::Window::stopReadEvents(){
#if defined(EDK_WINDOW_EVENTS_RW)
    this->fileEvents.closeFile();
    this->playingWriteEvents=false;
    this->playingReadEvents=false;
    this->pausedFileEvents=false;
    this->nextSecondEvents=0.f;
    this->secondEvents=0.f;
    this->saveEvents.clean();
#endif
}

//pause file events
void edk::Window::pauseFileEvents(){
#if defined(EDK_WINDOW_EVENTS_RW)
    this->pausedFileEvents=true;
#endif
}
bool edk::Window::pauseWriteEvents(){
#if defined(EDK_WINDOW_EVENTS_RW)
    if(this->playingWriteEvents){
        this->pausedFileEvents=true;
        return true;
    }
#endif
    return false;
}
bool edk::Window::pauseReadEvents(){
#if defined(EDK_WINDOW_EVENTS_RW)
    if(this->playingReadEvents){
        this->pausedFileEvents=true;
        return true;
    }
#endif
    return false;
}
void edk::Window::unpauseFileEvents(){
#if defined(EDK_WINDOW_EVENTS_RW)
    this->pausedFileEvents=false;
#endif
}
bool edk::Window::unpauseWriteEvents(){
#if defined(EDK_WINDOW_EVENTS_RW)
    if(this->playingWriteEvents){
        this->pausedFileEvents=false;
        return true;
    }
#endif
    return false;
}
bool edk::Window::unpauseReadEvents(){
#if defined(EDK_WINDOW_EVENTS_RW)
    if(this->playingReadEvents){
        this->pausedFileEvents=false;
        return true;
    }
#endif
    return false;
}
bool edk::Window::isPausedFileEvents(){
#if defined(EDK_WINDOW_EVENTS_RW)
    return this->pausedFileEvents;
#else
    return false;
#endif
}
bool edk::Window::isPausedWriteEvents(){
#if defined(EDK_WINDOW_EVENTS_RW)
    if(this->playingWriteEvents){
        return this->pausedFileEvents;
    }
#endif
    return false;
}
bool edk::Window::isPausedReadEvents(){
#if defined(EDK_WINDOW_EVENTS_RW)
    if(this->playingReadEvents){
        return this->pausedFileEvents;
    }
#endif
    return false;
}

//print events
void edk::Window::eventsPrint(){
    this->events.printEvents();
}

//print events
void edk::Window::printEvents(){
    this->events.printEvents();
}

bool edk::Window::eventLostFocus(){
    return this->events.lostFocus;
}

bool edk::Window::eventGainedFocus(){
    return this->events.gainedFocus;
}

bool edk::Window::eventButtonClose(){
    //
    bool temp = events.buttonExit;
    events.buttonExit=false;
    return temp;
}

bool edk::Window::eventKeyPressed(){
    //
    return (bool)this->eventGetKeyPressedSize();
}

bool edk::Window::eventKeyRelease(){
    //
    return (bool)this->eventGetKeyReleaseSize();
}

bool edk::Window::eventKeyHolded(){
    return (bool)this->eventGetKeyHoldedSize();
}

edk::uint32 edk::Window::eventGetKeyPressedSize(){
    //Retorna o tamanho do vector
    return this->events.keyPressed.size();
}

edk::uint32 edk::Window::eventGetKeyReleaseSize(){
    //Retorna o tamanho do vetor
    return this->events.keyRelease.size();
}

edk::uint32 edk::Window::eventGetKeyHoldedSize(){
    return this->events.keyHolded.size();
}

edk::uint32 edk::Window::eventGetKeyPressed(uint32 pos){
    //
    if(pos<this->events.keyPressed.size()){
        //
        return this->events.keyPressed.get(pos);
    }
    //senao retorna 0u
    return 0u;
}

edk::uint32 edk::Window::eventGetKeyRelease(uint32 pos){
    if(pos<this->events.keyRelease.size()){
        //
        return this->events.keyRelease.get(pos);
    }
    //senao retorna 0u
    return 0u;
}

edk::uint32 edk::Window::eventGetKeyHolded(uint32 pos){

    if(pos<this->events.keyHolded.size()){
        //
        return this->events.keyHolded.get(pos);
    }
    //senao retorna 0u
    return 0u;
}

bool edk::Window::eventMousePressed(){
    //
    return (bool)this->eventGetMousePressedSize();
}

bool edk::Window::eventMouseRelease(){
    //
    return (bool)this->eventGetMouseReleaseSize();
}

bool edk::Window::eventMouseDoubleClick(){
    //
    return (bool)this->eventGetMouseDoubleClickSize();
}

bool edk::Window::eventMouseHolded(){
    return (bool)this->eventGetMouseHoldedSize();
}

edk::uint8 edk::Window::eventGetMousePressedSize(){
    //
    return this->events.mousePressed.size();
}

edk::uint8 edk::Window::eventGetMouseReleaseSize(){
    //
    return this->events.mouseRelease.size();
}

edk::uint8 edk::Window::eventGetMouseDoubleClickSize(){
    //
    return this->events.mouseDoubleClick.size();
}

edk::uint8 edk::Window::eventGetMouseHoldedSize(){
    //
    return this->events.mouseHolded.size();
}

edk::uint8 edk::Window::eventGetMousePressed(uint32 pos){
    //
    if(pos<this->events.mousePressed.size()){
        //
        return this->events.mousePressed.get(pos);
    }
    //senao retorna false
    return false;
}

edk::uint8 edk::Window::eventGetMouseRelease(uint32 pos){
    //
    if(pos<this->events.mouseRelease.size()){
        //
        return this->events.mouseRelease.get(pos);
    }
    //senao retorna false
    return false;
}

edk::uint8 edk::Window::eventGetMouseDoubleClick(edk::uint32 pos){
    //
    if(pos<this->events.mouseDoubleClick.size()){
        //
        return this->events.mouseDoubleClick.get(pos);
    }
    //senao retorna false
    return false;
}

edk::uint8 edk::Window::eventGetMouseHolded(uint32 pos){
    //
    if(pos<this->events.mouseHolded.size()){
        //
        return this->events.mouseHolded.get(pos);
    }
    //senao retorna false
    return false;
}

bool edk::Window::eventMouseEnter(){
    //
    return this->events.mouseEnter;
}

bool edk::Window::eventMouseExit(){
    //
    return this->events.mouseExit;
}

bool edk::Window::eventMouseMoved(){
    //retorna se o mouse foi movido
    return this->events.mouseMoved;
}

edk::int8 edk::Window::getMouseScrollWheel(){
    //
    return (int8)this->events.mouseScrollWheel;
}

bool edk::Window::eventResizeWindow(){
    //retorna se redimencionou a janela
    return this->events.resize;
}

edk::size2i32 edk::Window::getResize(){
    //
    return this->events.resizePos;
}

//set and get the second passed
bool edk::Window::setSecondPassedBeforeLoadEvents(edk::float32 seconds){
    if(seconds>0.f){
        this->events.forceSecondPassed(seconds);
        return true;
    }
    return false;
}
bool edk::Window::setSecondPassedAfterLoadEvents(edk::float32 seconds){
    if(seconds>0.f){
        this->events.secondPassed = seconds;
        return true;
    }
    return false;
}
edk::float32 edk::Window::eventGetSecondPassed(){
    return this->events.secondPassed;
}

bool edk::Window::loadEvents(){
    edk::uint32 mouseButtonValue=0u;
    bool ret=false;
    this->updateControllerEvents();
    //Limpa os eventos
    this->cleanEvents();

    //Eventos da janela
    sf::Event event;
    //Input da janela
    //const sf::Input& input=window.GetInput();//1.6
    //2.0

    //test if DON'T need force the second passed
    if(!this->events.updateForceSecondPassed()){
        //load the time passed since the last frame
        this->events.secondPassed = this->time.getMicroseconds() * edk::watch::microsecond;
        this->events.secondsGlobal = this->time.getMicrosecondsReal() * edk::watch::microsecond;
    }



#if defined(EDK_WINDOW_EVENTS_RW)
    if(this->playingReadEvents && !this->pausedFileEvents){
        this->secondEvents+=this->events.secondPassed;
        //test if the secondEvents is bigger then the nextSecondEvent
        if(this->secondEvents > this->nextSecondEvents){
            while(this->secondEvents > this->nextSecondEvents){
                //test if reach the end of the file
                if(this->fileEvents.endOfFile()){
                    //stop the read
                    this->stopReadEvents();
                }
                else{
                    //else read the events
                    this->events.readFile(&this->fileEvents);
                    this->saveEvents.clean();
                    //test if reach the end of the file
                    if(this->fileEvents.endOfFile()){
                        //stop the read
                        this->stopReadEvents();
                    }
                    else{
                        //then read the nextSecondEvent
                        this->fileEvents.readBin(&this->nextSecondEvents,sizeof(this->nextSecondEvents));
                        saveEvents.cloneFrom(&this->events);
                    }
                }
            }
        }
        else{
            edk::float32 secondPassed = this->events.secondPassed;
            edk::float32 secondsGlobal = this->events.secondsGlobal;
            this->events.cloneFrom(&this->saveEvents);
            this->events.secondPassed = secondPassed;
            this->events.secondsGlobal = secondsGlobal;
        }
    }
#endif

    this->time.start();

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
            //printf("\nKey Pressed %d",event.key.code);
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
        //TEXT ENTERED
        //if(event.Type == sf::Event::TextEntered){//1.6
        if(event.type == sf::Event::TextEntered){//2.0
            //
            this->events.keyText.pushBack(event.text.unicode);
        }
        //END TEX ENTERED
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
            mouseButtonValue = event.mouseButton.button+1u;//2.0
            //this->events.mouseRelease.pushBack(event.MouseButton.Button+1u);//1.6
            this->events.mouseRelease.pushBack(mouseButtonValue);//2.0

            //test the time distance from the last mouse button release
            if(mouseButtonValue < edk::mouse::mouseButtonsSize){
                //test the time
                if(this->events.timeMouseDouble[mouseButtonValue].getSeconds() < this->events.getMouseDoubleClickLimit()){
                    //add this mouse button into doubleClick event
                    this->events.mouseDoubleClick.pushBack(mouseButtonValue);
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
                       );
*/
            this->events.controllerPressed.addButton(event.joystickButton.joystickId,event.joystickButton.button);
        }

        //if(event.Type == sf::Event::JoyButtonPressed){//1.6
        if(event.type == sf::Event::JoystickButtonReleased){//2.0
            /*
                printf("\nJoyButtonReleased joy == %u button == %u"
                       ,event.joystickButton.joystickId
                       ,event.joystickButton.button
                       );
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
                       );
*/
            //test if it's the Y
            if(event.joystickMove.axis<(sizeof(event.joystickMove.axis)*8)-1u){
                this->events.controllerAxisMoved.addAxis(event.joystickMove.joystickId,event.joystickMove.axis,event.joystickMove.position*-1.f);
            }
            else{
                this->events.controllerAxisMoved.addAxis(event.joystickMove.joystickId,event.joystickMove.axis,event.joystickMove.position);
            }
        }


        ret=true;

    }
    //load the window size
    this->windowSize = edk::size2ui32(window.getSize().x,window.getSize().y);//2.0
    this->events.windowSize = this->windowSize;

    //Seta o tamanho da janela
    this->updateViewSize();

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
                if(i>=0&&i<26){
                    this->events.keyHolded.pushBack(i+'a') ;//2.0
                }
                else if(i>=26&&i<36){
                    this->events.keyHolded.pushBack(i+ '0' - 26) ;//2.0
                }
                else{
                    this->events.keyHolded.pushBack(i+256 - 36) ;//2.0
                }
            }
        }
        //load the holded mouse button
        for(edk::int32 i=sf::Mouse::Left ;i<sf::Mouse::ButtonCount;i=i+1){
            if(sf::Mouse::isButtonPressed((sf::Mouse::Button)i)){
                this->events.mouseHolded.pushBack(i+1u);
            }
        }
        ret=true;
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

#if defined(EDK_WINDOW_EVENTS_RW)
    //test if are writing or reading some events file
    if(this->playingWriteEvents && !this->pausedFileEvents){
        this->secondEvents+=this->events.secondPassed;
        //test if have some eventType on the tree
        if(this->treeEventTypes.size()){
            //test if have something in the events
            if(this->events.haveSomethingTypesTree(&this->treeEventTypes)){
                //write the secondEvents
                this->fileEvents.writeBin(this->secondEvents);
                //write the events
                this->events.writeFileTypesTree(&this->fileEvents,&this->treeEventTypes);
                this->saveHaveEvents=true;
            }
            else if(this->saveHaveEvents){
                //write the events to remove all used events
                this->fileEvents.writeBin(this->secondEvents);
                //write the events
                this->events.writeFileTypesTree(&this->fileEvents,&this->treeEventTypes);
                this->saveHaveEvents=false;
            }
        }
        else{
            //test if have something in the events
            if(this->events.haveSomething()){
                //write the secondEvents
                this->fileEvents.writeBin(this->secondEvents);
                //write the events
                this->events.writeFile(&this->fileEvents);
                this->saveHaveEvents=true;
            }
            else if(this->saveHaveEvents){
                //write the events to remove all used events
                this->fileEvents.writeBin(this->secondEvents);
                //write the events
                this->events.writeFile(&this->fileEvents);
                this->saveHaveEvents=false;
            }
        }
    }
#endif

    //senao retorna false
    return ret;
}

edk::size2ui32 edk::Window::getDesktopSize(){
    //Carrega o modo do desktop
    //sf::VideoMode DesktopMode = sf::VideoMode::GetDesktopMode();//1.6
    sf::VideoMode DesktopMode = sf::VideoMode::getDesktopMode();//2.0
    //seta o retorno
    //edk::size2ui32 temp(DesktopMode.Width,DesktopMode.Height);//1.6
    edk::size2ui32 temp(DesktopMode.width,DesktopMode.height);//2.0
    //carrega o desktop mode
    return temp;
}

edk::uint32 edk::Window::getDesktopBitsPerPixel(){
    //Carrega o modo do desktop
    //sf::VideoMode DesktopMode = sf::VideoMode::GetDesktopMode();//1.6
    sf::VideoMode DesktopMode = sf::VideoMode::getDesktopMode();//2.0
    //retorna os bits
    //return DesktopMode.BitsPerPixel;//1.6
    return DesktopMode.bitsPerPixel;//2.0
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
    return sf::Joystick::getButtonCount(controller);
}

bool edk::Window::eventControllerButtonPressed(edk::uint32 controller){
    return (bool)this->eventGetControllerButtonPressedSize(controller);
}

bool edk::Window::eventControllerButtonRelease(edk::uint32 controller){
    return (bool)this->eventGetControllerButtonReleaseSize(controller);
}

bool edk::Window::eventControllerButtonHolded(edk::uint32 controller){
    return (bool)this->eventGetControllerButtonHoldedSize(controller);
}

bool edk::Window::eventControllerAxisMoved(edk::uint32 controller){
    return (bool)this->eventGetControllerAxisMovedSize(controller);
}

edk::uint8 edk::Window::eventGetControllerButtonPressedSize(edk::uint32 controller){
    return this->events.controllerPressed.getControllerButtonSizeInPosition(controller);
}

edk::uint8 edk::Window::eventGetControllerButtonReleaseSize(edk::uint32 controller){
    return this->events.controllerReleased.getControllerButtonSizeInPosition(controller);
}

edk::uint8 edk::Window::eventGetControllerButtonHoldedSize(edk::uint32 controller){
    return this->events.controllerHolded.getControllerButtonSizeInPosition(controller);
}

edk::uint8 edk::Window::eventGetControllerAxisMovedSize(edk::uint32 controller){
    return this->events.controllerAxisMoved.getControllerButtonSizeInPosition(controller);
}

edk::uint8 edk::Window::eventGetControllerButtonPressed(edk::uint32 controller, uint32 pos){
    return this->events.controllerPressed.getControllerButtonInPosition(controller,pos);
}

edk::uint8 edk::Window::eventGetControllerButtonRelease(edk::uint32 controller, uint32 pos){
    return this->events.controllerReleased.getControllerButtonInPosition(controller,pos);
}

edk::uint8 edk::Window::eventGetControllerButtonHolded(edk::uint32 controller, uint32 pos){
    return this->events.controllerHolded.getControllerButtonInPosition(controller,pos);
}

edk::uint32 edk::Window::eventGetControllerAxisIDMoved(edk::uint32 controller, uint32 pos){
    return this->events.controllerAxisMoved.getControllerAxisIDInPosition(controller,pos);
}

edk::float32 edk::Window::eventGetControllerAxisMoved(edk::uint32 controller, uint32 pos){
    return this->events.controllerAxisMoved.getControllerAxisValueInPosition(controller,pos);
}

edk::float32 edk::Window::eventGetControllerAxisMovedByID(edk::uint32 controller, uint32 id){
    return this->events.controllerAxisMoved.getControllerAxisValueByControllerID(controller,id);
}
