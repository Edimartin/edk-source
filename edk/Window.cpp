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

#if defined(EDK_USE_SFML)
#endif
#if defined(EDK_USE_X11)
//mouse defines
#define EDK_Mouse_Button_left 0b00000000000000000000000100000000
#define EDK_Mouse_Button_middle 0b00000000000000000000001000000000
#define EDK_Mouse_Button_right 0b00000000000000000000010000000000
#define EDK_Mouse_Button_scrollUP 0b00000000000000000000100000000000
#define EDK_Mouse_Button_scrollDOWN 0b00000000000000000001000000000000
#define EDK_Mouse_key_ctrl 0b00000000000000000000000000000100
#define EDK_Mouse_key_shift 0b00000000000000000000000000000001
#define EDK_Mouse_key_lAlt 0b00000000000000000000000000001000
#define EDK_Mouse_key_rAlt 0b00000000000000000000000010000000
#define EDK_Mouse_key_numLock 0b00000000000000000000000000010000
#define EDK_Mouse_key_capsLock 0b00000000000000000000000000000010
#define EDK_Mouse_key_scrollLock 0b00000000000000000000000000100000

//display status
edk::uint64 edk::Window::displayBlack = 0uL;
edk::uint64 edk::Window::displayWhite = 0uL;
edk::int32 edk::Window::displayNumberOfScreens = 0;
edk::int32 edk::Window::displayScreen = 0;
edk::int32 edk::Window::displayDepth = 0;
edk::size2ui32 edk::Window::displaySize = 0u;

//LINUX
XRRMonitorInfo	*edk::Window::m=NULL;

namespace edk{
class EDK_Input_Global{
public:
    EDK_Input_Global(void* pointer){
        this->pointer=pointer;
        this->clean();
    }
    ~EDK_Input_Global(){}
    void clean(){
        this->mouseMask=0u;
        this->readMouse=false;
        this->readKeys=false;
        this->mouseX = this->mouseY = 0;
        memset(this->keys,0u,sizeof(this->keys));
        this->controllerPressed.clean();
        this->controllerReleased.clean();
        this->controllerAxisMoved.clean();
    }
    void* pointer;
    //mouse
    bool readMouse;
    edk::int32 mouseX, mouseY;
    edk::uint32 mouseMask;
    //KEYCODES
    bool readKeys;
    edk::char8 keys[32u];
    //controllers
    edk::WindowEvents::ControllerButtonsEvent controllerPressed;
    edk::WindowEvents::ControllerButtonsEvent controllerReleased;
    edk::WindowEvents::ControllerAxisEvent    controllerAxisMoved;
};
class EDK_Monitors_Global{
public:
    EDK_Monitors_Global(){
        this->clean();
    }
    EDK_Monitors_Global(edk::int32 id,
                        edk::uint32 name,
                        bool primary,
                        bool automatic,
                        edk::vec2i32 position,
                        edk::size2i32 size,
                        edk::size2i32 sizeM
                        ){
        this->clean();
        this->id=id;
        this->name=name;
        this->primary=primary;
        this->automatic=automatic;
        this->position=position;
        this->size = size;
        this->sizeM = sizeM;
    }
    ~EDK_Monitors_Global(){
        this->outputs.clean();
    }
    void clean(){
        this->id = 0;
        this->name = 0u;
        this->primary = false;
        this->automatic = false;
        this->position = edk::vec2i32(0,0);
        this->size = edk::size2i32(0,0);
        this->sizeM = edk::size2i32(0,0);
        this->outputs.clean();
    }
    //functions to set and get outputs
    void addOutput(edk::uint32 output){
        this->outputs.pushBack(output);
    }
    //get the outputs size
    edk::int32 getOutputSize(){
        return this->outputs.size();
    }
    edk::uint32 getOutput(edk::uint32 position){
        return this->outputs.get(position);
    }
    void print(){
        printf("\nID == %d",this->id);fflush(stdout);
        printf("\nName == %u",this->name);fflush(stdout);
        printf("\nPrimary == %s",this->primary?"true":"false");fflush(stdout);
        printf("\nAutomatic == %s",this->automatic?"true":"false");fflush(stdout);
        printf("\nPosition == %d %d",this->position.x,this->position.y);fflush(stdout);
        printf("\nSize == %d %d",this->size.width,this->size.height);fflush(stdout);
        printf("\nSize Millimeters == %d %d",this->sizeM.width,this->sizeM.height);fflush(stdout);
        edk::uint32 size = this->outputs.size();
        printf("\nNoutputs == %u",this->outputs.size());fflush(stdout);
        for(edk::uint32 i=0u;i<size;i++){
            printf(" [%u]",this->outputs.get(i));fflush(stdout);
        }
    }
    //get the output
    edk::int32 id;
    edk::uint32 name;
    bool primary;
    bool automatic;
    edk::vec2i32 position;
    edk::size2i32 size;
    edk::size2i32 sizeM;
private:
    edk::vector::Stack<edk::uint32> outputs;
};
//TREE to save the monitors
class EDK_Monitors_Tree : public edk::vector::BinaryTree<EDK_Monitors_Global*>{
public:
    EDK_Monitors_Tree(){
    }
    ~EDK_Monitors_Tree(){
        this->cleanMonitors();
    }
    //compare if the value is bigger
    bool firstBiggerSecond(EDK_Monitors_Global* first,EDK_Monitors_Global* second){
        if(first->position.x>second->position.x){
            return true;
        }
        else if(first->position.x==second->position.x
                &&
                first->position.y>second->position.y
                ){
            return true;
        }
        return false;
    }
    //compare if the value is equal
    bool firstEqualSecond(EDK_Monitors_Global* first,EDK_Monitors_Global* second){
        if(first->position.x==second->position.x
                &&
                first->position.y==second->position.y
                ){
            return true;
        }
        return false;
    }
    //Print the monitor
    void printElement(EDK_Monitors_Global* value){
        value->print();
    }

    //Print the elements
    void print(){
        edk::vector::BinaryTree<EDK_Monitors_Global*>::print();
    }
    //render the elements
    void render(){
        edk::vector::BinaryTree<EDK_Monitors_Global*>::render();
    }
    void update(){
        edk::vector::BinaryTree<EDK_Monitors_Global*>::update();
    }
    void cleanMonitors(){
        edk::uint32 size = this->size();
        EDK_Monitors_Global* temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->getElementInPosition(i);
            if(temp){
                delete temp;
            }
        }
        this->clean();
        this->tree.clean();
    }
    //add a new monitor
    bool newMonitor(edk::int32 id,
                    edk::uint32 name,
                    bool primary,
                    bool automatic,
                    edk::vec2i32 position,
                    edk::size2i32 size,
                    edk::size2i32 sizeM,
                    edk::uint32 noutputs,
                    edk::uint32* outputs
                    ){
        //
        EDK_Monitors_Global* tempID = this->getMonitorFromID(id);
        EDK_Monitors_Global* tempPosition = this->getMonitorFromPosition(position);
        if(!tempID && !tempPosition){
            //create the new monitor
            EDK_Monitors_Global* tempID = new EDK_Monitors_Global(id,
                                                                  name,
                                                                  primary,
                                                                  automatic,
                                                                  position,
                                                                  size,
                                                                  sizeM);
            if(tempID){
                //add the monitor in to the trees
                if(this->add(tempID)){
                    //add to the ID
                    if(this->tree.add(tempID)){
                        //set the outputs
                        for(edk::uint32 i=0u;i<noutputs;i++){
                            tempID->addOutput(outputs[i]);
                        }
                        return true;
                    }
                    this->remove(tempID);
                }
            }
        }
        return false;
    }
    //get the monitor from ID
    EDK_Monitors_Global* getMonitorFromID(edk::int32 id){
        EDK_Monitors_Global find;
        find.id = id;
        return this->tree.getElement(&find);
    }
    //get the monitor from position
    EDK_Monitors_Global* getMonitorFromPosition(edk::vec2i32 position){
        EDK_Monitors_Global find;
        find.position = position;
        return this->tree.getElement(&find);
    }
private:
    //class tree for the monitors ID's
    class EDK_MonitorsID_Tree : public edk::vector::BinaryTree<EDK_Monitors_Global*>{
    public:
        EDK_MonitorsID_Tree(){
        }
        ~EDK_MonitorsID_Tree(){
            this->clean();
        }
        //compare if the value is bigger
        bool firstBiggerSecond(EDK_Monitors_Global* first,EDK_Monitors_Global* second){
            if(first->id>second->id){return true;} return false;
        }
        //compare if the value is equal
        bool firstEqualSecond(EDK_Monitors_Global* first,EDK_Monitors_Global* second){
            if(first->id==second->id){return true;} return false;
        }
        //Print the monitor
        void printElement(EDK_Monitors_Global* value){
            value->print();
        }
    }tree;
};

class EDK_Visuals_Global{
public:
    EDK_Visuals_Global(Visual* visual,edk::int32 depth){
        this->visual=visual;
        this->depth=depth;
    }
    ~EDK_Visuals_Global(){}
    Visual* visual;
    edk::int32 depth;
};
//TREE VISUALS
class EDK_Visuals_Tree : public edk::vector::BinaryTree<EDK_Visuals_Global*>{
public:
    EDK_Visuals_Tree(){
    }
    ~EDK_Visuals_Tree(){
        this->cleanVisuals();
    }
    //compare if the value is bigger
    bool firstBiggerSecond(EDK_Visuals_Global* first,EDK_Visuals_Global* second){
        if(first->depth>second->depth){
            return true;
        }
        return false;
    }
    //compare if the value is equal
    bool firstEqualSecond(EDK_Visuals_Global* first,EDK_Visuals_Global* second){
        if(first->depth==second->depth){
            return true;
        }
        return false;
    }
    void cleanVisuals(){
        edk::uint32 size = this->size();
        EDK_Visuals_Global* temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->getElementInPosition(i);
            if(temp) delete temp;
        }
        this->clean();
    }
    //add a new visual
    bool addNewVisual(Visual* visual,edk::int32 depth){
        if(visual && depth){
            EDK_Visuals_Global* temp = this->getVisualGlobal(depth);
            if(!temp){
                temp = new EDK_Visuals_Global(visual,depth);
                if(temp){
                    //add the depth in to the tree
                    if(this->add(temp)){
                        return true;
                    }
                    delete temp;
                }
            }
        }
        return false;
    }
    //get the visual from depth
    Visual* getVisual(edk::int32 depth){
        EDK_Visuals_Global* temp = this->getVisualGlobal(depth);
        if(temp){
            return temp->visual;
        }
        return NULL;
    }
    edk::int32 getDepthInPosition(edk::uint32 position){
        EDK_Visuals_Global* temp = this->getElementInPosition(position);
        if(temp){
            return temp->depth;
        }
        return 0u;
    }
private:
    //get the visual from depth
    EDK_Visuals_Global* getVisualGlobal(edk::int32 depth){
        EDK_Visuals_Global find(NULL,depth);
        return this->getElement(&find);
    }
private:
};

//CONTROLLERS CONNECTED
class EDK_Controllers_Global{
public:
    EDK_Controllers_Global(const edk::char8* name){
        this->path.setName(name);
        this->id=0u;
        this->axes=0u;
        this->buttons=0u;
        this->version=0;
        this->name=NULL;
    }
    EDK_Controllers_Global(edk::char8* name){
        this->path.setName(name);
        this->id=0u;
        this->axes=0u;
        this->buttons=0u;
        this->version=0;
        this->name=NULL;
    }
    EDK_Controllers_Global(edk::uint32 id){
        this->id=id;
        this->axes=0u;
        this->buttons=0u;
        this->version=0;
        this->name=NULL;
    }
    EDK_Controllers_Global(const edk::char8* name,edk::uint32 id){
        //open
        if(this->stream.openFileStreamNonBlock(name)){
            this->path.setName(this->stream.getName());
            //copy the numbers and string of the controller
            this->stream.ioControl(JSIOCGAXES,&this->axes);
            this->stream.ioControl(JSIOCGBUTTONS,&this->buttons);
            this->stream.ioControl(JSIOCGVERSION,&this->version);
            edk::int32 size = 128;
            edk::int32 ret = -1;
            do{
                this->name = new edk::char8[size];
                if(this->name){
                    memset(this->name,0u,size);
                    ret = this->stream.ioControl(JSIOCGNAME(size),this->name);
                    if(ret>=0){
                        if(ret<size){
                            break;
                        }
                    }
                    else{
                        delete[] this->name;
                        this->name=NULL;
                        break;
                    }
                    delete[] this->name;
                    this->name=NULL;
                }
                size *= 2;
                if(size>2000) break;
            }while(true);
        }
        this->id=id;
    }
    EDK_Controllers_Global(edk::char8* name,edk::uint32 id){
        //open
        if(this->stream.openFileStreamNonBlock(name)){
            this->path.setName(this->stream.getName());
            //copy the numbers and string of the controller
            this->stream.ioControl(JSIOCGAXES,&this->axes);
            this->stream.ioControl(JSIOCGBUTTONS,&this->buttons);
            this->stream.ioControl(JSIOCGVERSION,&this->version);
            edk::int32 size = 128;
            edk::int32 ret = -1;
            do{
                this->name = new edk::char8[size];
                if(this->name){
                    memset(this->name,0u,size);
                    ret = this->stream.ioControl(JSIOCGNAME(size),this->name);
                    if(ret>=0){
                        if(ret<size){
                            break;
                        }
                    }
                    else{
                        delete[] this->name;
                        this->name=NULL;
                        break;
                    }
                    delete[] this->name;
                    this->name=NULL;
                }
                size *= 2;
                if(size>2000) break;
            }while(true);
        }
        this->id=id;
    }
    ~EDK_Controllers_Global(){
        this->stream.closeFileStream();
        if(this->name){
            delete[] this->name;
        }
    }
    //return true if the file is opened
    bool isOpened(){
        return this->stream.isOpened();
    }
    edk::char8* getPath(){
        return this->path.getName();
    }
    edk::uint32 getID(){
        return this->id;
    }
    edk::uint8 getAxes(){
        return this->axes;
    }
    edk::uint8 getButtons(){
        return this->buttons;
    }
    edk::int32 getVersion(){
        return this->version;
    }
    edk::char8* getName(){
        return this->name;
    }
    bool biggerThan(edk::char8* name){
        return this->path.nameBiggerThan(name);
    }
    bool equalThan(edk::char8* name){
        return this->path.nameEqual(name);
    }
    edk::int64 readVec(edk::classID vec,edk::uint64 size){
        return this->stream.readVec(vec,size);
    }
    edk::int64 readVec(edk::classID vec,edk::uint32 size){
        return this->stream.readVec(vec,size);
    }
    //open controller
    void openController(){
        if(this->name){
            printf("\n%u %s %s Open Controller[%d] '%s' '%s' axes %u buttons %u version %d",__LINE__,__FILE__,__func__
                   ,this->id
                   ,this->path.getName()
                   ,this->name
                   ,this->axes
                   ,this->buttons
                   ,this->version
                   );fflush(stdout);
        }
        else{
            printf("\n%u %s %s Open Controller[%d] '%s' '%s' axes %u buttons %u version %d",__LINE__,__FILE__,__func__
                   ,this->id
                   ,this->path.getName()
                   ,"noName"
                   ,this->axes
                   ,this->buttons
                   ,this->version
                   );fflush(stdout);
        }
    }
    void closeController(){
        if(this->name){
            printf("\n%u %s %s Close Controller[%d] '%s' '%s' axes %u buttons %u version %d",__LINE__,__FILE__,__func__
                   ,this->id
                   ,this->path.getName()
                   ,this->name
                   ,this->axes
                   ,this->buttons
                   ,this->version
                   );fflush(stdout);
        }
        else{
            printf("\n%u %s %s Close Controller[%d] '%s' '%s' axes %u buttons %u version %d",__LINE__,__FILE__,__func__
                   ,this->id
                   ,this->path.getName()
                   ,"noName"
                   ,this->axes
                   ,this->buttons
                   ,this->version
                   );fflush(stdout);
        }
    }
private:
    edk::FileStream stream;
    edk::uint32 id;
    edk::Name path;
    edk::uint8 axes;
    edk::uint8 buttons;
    edk::int32 version;
    edk::char8* name;
};
class EDK_Controllers_Tree : public edk::vector::BinaryTree<EDK_Controllers_Global*>{
public:
    EDK_Controllers_Tree(){
        this->controllerPressed=NULL;
        this->controllerReleased=NULL;
        this->controllerAxisMoved=NULL;
        this->time.start();
        this->time.increaseSeconds(1.f);
        this->disconnecteds.clean(10u);
    }
    ~EDK_Controllers_Tree(){
        //close all controllers
        this->closeControllers();
    }

    //compare if the value is bigger
    bool firstBiggerSecond(EDK_Controllers_Global* first,EDK_Controllers_Global* second){
        if(first->biggerThan(second->getPath())){
            return true;
        }
        return false;
    }
    //compare if the value is equal
    bool firstEqualSecond(EDK_Controllers_Global* first,EDK_Controllers_Global* second){
        if(first->equalThan(second->getPath())){
            return true;
        }
        return false;
    }
    //Print
    void printElement(EDK_Controllers_Global* ){
    }
    void renderElement(EDK_Controllers_Global* ){
    }
    //UPDATE
    void updateElement(EDK_Controllers_Global* value){
        if(value->readVec(&this->event,sizeof(this->event)) == sizeof(this->event)){
            //read the values
            switch (this->event.type)
            {
            case JS_EVENT_BUTTON:
                //printf("\nButton %u %s", event.number, event.value ?"pressed":"released");
                if(event.value){
                    //pressed
                    //event.number
                    this->controllerPressed->addButton(value->getID(),event.number);
                    this->controllerHolded->addButton(value->getID(),event.number);
                }
                else{
                    //released
                    //event.number
                    this->controllerReleased->addButton(value->getID(),event.number);
                    this->controllerHolded->removeControllerButtonByID(value->getID(),event.number);
                }
                break;
            case JS_EVENT_AXIS:
            {
                edk::vec2i32 position;
                edk::int32 axis = this->event.number / 2u;
                if (this->event.number % 2 == 0){
                    position.x = this->event.value;
                    this->controllerAxisMoved->addAxis(value->getID(),axis,this->event.value);
                }
                else{
                    position.y = this->event.value;
                    this->controllerAxisMoved->addAxis(value->getID(),axis,this->event.value);
                }
                //printf("\nAxis %zu at (%6d, %6d)", axis, axes[axis].x, axes[axis].y);
            }
                break;
            case JS_EVENT_INIT:
                //printf("\nJS_EVENT_INIT");
                break;
            default:
                // Ignore init events.
                //printf("\nDEFAULT");
                break;
            }
        }
        else{
            //else maybe it's closed
            if(!value->isOpened()){
                //
                this->disconnecteds.pushBack(value);
            }
        }
    }

    //Print the elements
    void print(){
        edk::vector::BinaryTree<EDK_Controllers_Global*>::print();
    }
    //render the elements
    void render(){
        edk::vector::BinaryTree<EDK_Controllers_Global*>::render();
    }
    void update(){
        //
    }
    bool updateControllers(
            edk::WindowEvents::ControllerButtonsEvent* controllerPressed,
            edk::WindowEvents::ControllerButtonsEvent* controllerReleased,
            edk::WindowEvents::ControllerButtonsEvent* controllerHolded,
            edk::WindowEvents::ControllerAxisEvent* controllerAxisMoved
            ){
        if(this->size() && controllerPressed && controllerReleased && controllerHolded && controllerAxisMoved){
            this->controllerPressed=controllerPressed;
            this->controllerReleased=controllerReleased;
            this->controllerHolded=controllerHolded;
            this->controllerAxisMoved=controllerAxisMoved;
            //then update the tree
            edk::vector::BinaryTree<EDK_Controllers_Global*>::update();
            //clean the pointers
            this->controllerPressed=NULL;
            this->controllerReleased=NULL;
            this->controllerHolded=NULL;
            this->controllerAxisMoved=NULL;

            //remove disconnected controllers
            edk::uint32 size = this->disconnecteds.size();
            edk::EDK_Controllers_Global* temp;
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->disconnecteds.get(i);
                if(this->remove(temp)){
                    temp->closeController();
                    delete temp;
                }
            }
            this->disconnecteds.clean();

            return true;
        }
        return false;
    }
    //close all controllers
    void closeControllers(){
        edk::uint32 size = this->size();
        EDK_Controllers_Global* temp=NULL;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->getElementInPosition(i);
            if(temp)
                delete temp;
        }
        this->clean();
        this->disconnecteds.clean();
    }
    //return the size of the controllers connected
    edk::uint32 getControllersSize(){
        return this->ids.size();
    }
    //get the controller ID in position
    edk::uint32 getControllerIDInPosition(edk::uint32 position){
        return this->ids.getControllerIDInPosition(position);
    }
    //test if have the controller
    bool haveController(edk::char8* name){
        EDK_Controllers_Global find(name);
        return this->haveElement(&find);
    }
    bool haveControllerID(edk::uint32 id){
        return this->ids.haveControllerID(id);
    }
    edk::uint8 getControllerAxes(edk::uint32 id){
        edk::EDK_Controllers_Global* temp = this->ids.getControllerByID(id);
        if(temp){
            return temp->getAxes();
        }
        return 0u;
    }
    edk::uint8 getControllerButtons(edk::uint32 id){
        edk::EDK_Controllers_Global* temp = this->ids.getControllerByID(id);
        if(temp){
            return temp->getButtons();
        }
        return 0u;
    }
    edk::int32 getControllerVersion(edk::uint32 id){
        edk::EDK_Controllers_Global* temp = this->ids.getControllerByID(id);
        if(temp){
            return temp->getVersion();
        }
        return 0;
    }
    edk::char8* getControllerName(edk::uint32 id){
        edk::EDK_Controllers_Global* temp = this->ids.getControllerByID(id);
        if(temp){
            return temp->getName();
        }
        return NULL;
    }
    //open a new controller
    bool openControllers(edk::uint32 size=10u){
        bool ret=false;
        //test the time
        if(this->time.getSeconds()>1.f){
            this->time.removeSeconds(1.f);
            if(size>=100u)size=100u;
            EDK_Controllers_Global* temp=NULL;
            for(edk::uint32 i=0u;i<size;i++){
                memset(this->name,0u,sizeof(this->name));
                //create the string to open the controller
                sprintf(this->name,"/dev/input/js%d",i);
                //test if have the controller
                if(!this->haveController(this->name)){
                    //test to open the controller
                    temp = new EDK_Controllers_Global(this->name,i);
                    if(temp){
                        //test if the controller is opened
                        if(temp->isOpened()){
                            //add the temp
                            if(this->add(temp)){
                                //add the id
                                this->ids.add(temp);
                                temp->openController();
                                //continue
                                ret=true;
                                continue;
                            }
                        }
                        //else delete the temp to close the controller
                        delete temp;
                    }
                }
            }
        }
        return ret;
    }
private:
    edk::char8 name[sizeof("/dev/input/js000")];
    struct js_event event;
    edk::WindowEvents::ControllerButtonsEvent* controllerPressed;
    edk::WindowEvents::ControllerButtonsEvent* controllerReleased;
    edk::WindowEvents::ControllerButtonsEvent* controllerHolded;
    edk::WindowEvents::ControllerAxisEvent*    controllerAxisMoved;
    //time
    edk::watch::Time time;
    //disconnected controllers list
    edk::vector::Stack<edk::EDK_Controllers_Global*> disconnecteds;
    //tree to save the ID's
    class EDK_Controller_IDs_Global: public edk::vector::BinaryTree<edk::EDK_Controllers_Global*>{
    public:
        EDK_Controller_IDs_Global(){}
        ~EDK_Controller_IDs_Global(){
            this->clean();
        }
        //compare if the value is bigger
        bool firstBiggerSecond(edk::EDK_Controllers_Global* first,edk::EDK_Controllers_Global* second){
            if(first->getID()>second->getID()){
                return true;
            }
            return false;
        }
        //compare if the value is equal
        bool firstEqualSecond(edk::EDK_Controllers_Global* first,edk::EDK_Controllers_Global* second){
            if(first->getID()==second->getID()){
                return true;
            }
            return false;
        }
        bool haveControllerID(edk::uint32 id){
            edk::EDK_Controllers_Global find(id);
            if(this->getElement(&find))
                return true;
            return false;
        }
        edk::EDK_Controllers_Global* getControllerByID(edk::uint32 id){
            edk::EDK_Controllers_Global find(id);
            return this->getElement(&find);
        }
        edk::uint32 getControllerIDInPosition(edk::uint32 position){
            edk::EDK_Controllers_Global* temp = this->getElementInPosition(position);
            if(temp){
                return temp->getID();
            }
            return 0u;
        }
    }ids;
};
class EDK_Input_Thread : public edk::vector::BinaryTree<edk::EDK_Input_Global*>{
public:
    EDK_Input_Thread() : global(this){
        this->dis=NULL;
        this->rootw=0u;
        this->glc=0u;
        this->winCounter=0u;
        this->haveKeyCodes=false;
        //
        this->hintFunctions   =1<<0;
        this->hintDecorations =1<<1;
        //
        this->hintDecorationBorder   =1<<1;
        this->hintDecorationResize  =1<<2;
        this->hintDecorationTitle    =1<<3;
        this->hintDecorationMenu     =1<<4;
        this->hintDecorationMinimize =1<<5;
        this->hintDecorationMaximize =1<<6;

        //
        this->hintFunctionResize   =1<<1;
        this->hintFunctionMove     =1<<2;
        this->hintFunctionMinimize =1<<3;
        this->hintFunctionMaximize =1<<4;
        this->hintFunctionClose    =1<<5;
    }
    ~EDK_Input_Thread(){
        this->cleanGlobals();
        this->cleanMonitors();
        this->treeVisuals.cleanVisuals();
        this->controllers.closeControllers();
        this->controllerHolded.clean();
    }
    //compare if the value is bigger
    bool firstBiggerSecond(edk::EDK_Input_Global* first,edk::EDK_Input_Global* second){
        if(first->pointer>second->pointer){
            return true;
        }
        return false;
    }
    //compare if the value is equal
    bool firstEqualSecond(edk::EDK_Input_Global* first,edk::EDK_Input_Global* second){
        if(first->pointer==second->pointer){
            return true;
        }
        return false;
    }
    //UPDATE
    void updateElement(edk::EDK_Input_Global* value){
        //update the value
        value->readMouse = this->global.readMouse || value->readMouse;
        value->mouseX = this->global.mouseX;
        value->mouseY = this->global.mouseY;
        value->mouseMask |= this->global.mouseMask;
        value->readKeys = this->global.readKeys || value->readKeys;
        for(edk::uint8 i=0u;i<sizeof(this->global.keys);i++){
            value->keys[i]|=this->global.keys[i];
        }
        //copy the controller
        value->controllerPressed.cloneFrom(&this->controllerPressed);
        value->controllerReleased.cloneFrom(&this->controllerReleased);
        value->controllerAxisMoved.cloneFrom(&this->controllerAxisMoved);
    }
    void update(){
        //first update the controllers

        this->controllers.updateControllers(&this->controllerPressed,
                                            &this->controllerReleased,
                                            &this->controllerHolded,
                                            &this->controllerAxisMoved
                                            );
        //then update the controllers in the windows
        edk::vector::BinaryTree<EDK_Input_Global*>::update();
        //clean controllers
        this->controllerPressed.clean();
        this->controllerReleased.clean();
        this->controllerAxisMoved.clean();
    }
    //remove all globals
    void cleanGlobals(){
        edk::uint32 size = this->size();
        edk::EDK_Input_Global* temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->getElementInPosition(i);
            if(temp){
                delete temp;
            }
        }
        this->clean();
    }
    //get a global from the tree
    edk::EDK_Input_Global* getGlobal(edk::Window* window){
        if(window){
            edk::EDK_Input_Global find(window);
            return this->getElement(&find);
        }
        return NULL;
    }
    //add a new globals in the tree
    bool newGlobal(edk::Window* window){
        if(window){
            edk::EDK_Input_Global* temp = this->getGlobal(window);
            if(!temp){
                //create a new global
                temp = new edk::EDK_Input_Global(window);
                if(temp){
                    //add the temp to the tree
                    if(this->add(temp)){
                        return true;
                    }
                    //else delete the temp
                    delete temp;
                }
            }
        }
        return false;
    }
    //remove a global window
    bool removeGlobal(edk::Window* window){
        edk::EDK_Input_Global* temp = this->getGlobal(window);
        if(temp){
            if(this->remove(temp)){
                delete temp;
                return true;
            }
        }
        return false;
    }
    //remove all monitors
    void cleanMonitors(){
        this->monitors.cleanMonitors();
    }
    //add a new monitor
    bool newMonitor(edk::int32 id,
                    edk::uint32 name,
                    bool primary,
                    bool automatic,
                    edk::vec2i32 position,
                    edk::size2i32 size,
                    edk::size2i32 sizeM,
                    edk::uint32 noutputs,
                    edk::uint32* outputs
                    ){
        return this->monitors.newMonitor(id,
                                         name,
                                         primary,
                                         automatic,
                                         position,
                                         size,
                                         sizeM,
                                         noutputs,
                                         outputs
                                         );
    }
    //get the monitor from ID
    EDK_Monitors_Global* getMonitorFromID(edk::int32 id){
        return this->monitors.getMonitorFromID(id);
    }
    //get the monitor from position
    EDK_Monitors_Global* getMonitorFromPosition(edk::vec2i32 position){
        return this->monitors.getMonitorFromPosition(position);
    }
    EDK_Monitors_Global* getMonitorFromPosition(edk::int32 x,edk::int32 y){
        return this->monitors.getMonitorFromPosition(edk::vec2i32(x,y));
    }
    edk::multi::Thread thread;
    edk::multi::Mutex mut;

    //LINUX
    Display* dis;
    XID rootw;
    GLXContext glc;
    edk::uint32 winCounter;
    bool haveKeyCodes;
    edk::key::code keyCodes[32u*8u];

    //LINUX
    edk::EDK_Visuals_Tree treeVisuals;

    //monitors
    EDK_Monitors_Tree monitors;

    //LINUX
    //controllers
    EDK_Controllers_Tree controllers;
    //global holded buttons from controllers
    edk::WindowEvents::ControllerButtonsEvent controllerHolded;

    //global inputs to update
    edk::EDK_Input_Global global;

    //Xlib's
    edk::uint64 hintFunctions;
    edk::uint64 hintDecorations;
    //
    edk::uint64 hintDecorationBorder;
    edk::uint64 hintDecorationResize;
    edk::uint64 hintDecorationTitle;
    edk::uint64 hintDecorationMenu;
    edk::uint64 hintDecorationMinimize;
    edk::uint64 hintDecorationMaximize;

    //
    edk::uint64 hintFunctionResize;
    edk::uint64 hintFunctionMove;
    edk::uint64 hintFunctionMinimize;
    edk::uint64 hintFunctionMaximize;
    edk::uint64 hintFunctionClose;
private:
    //controllers
    edk::WindowEvents::ControllerButtonsEvent controllerPressed;
    edk::WindowEvents::ControllerButtonsEvent controllerReleased;
    edk::WindowEvents::ControllerAxisEvent    controllerAxisMoved;
};
}
edk::EDK_Input_Thread edkInputVariables;

//THREAD to read the mouse scroll
void* edkFunctionMouseScroll(void*){
    XID window_returned;
    edk::int32 root_x, root_y;
    edk::int32 win_x, win_y;
    edk::uint32 mask_return;

    //LINUX
    edkInputVariables.mut.lock();
    while(edkInputVariables.dis){
        edkInputVariables.global.clean();
        if(XQueryPointer(edkInputVariables.dis, edkInputVariables.rootw, &window_returned,
                         &window_returned, &root_x, &root_y, &win_x, &win_y,
                         &mask_return)){
            //get the mouse values
            edkInputVariables.global.readMouse=true;
            edkInputVariables.global.mouseX = root_x;
            edkInputVariables.global.mouseY = root_y;
            edkInputVariables.global.mouseMask=mask_return;
        }
        //
        if(XQueryKeymap(edkInputVariables.dis,edkInputVariables.global.keys)){
            //copy the keys
            for(edk::uint8 i=0u;i<sizeof(edkInputVariables.global.keys);i++){
                //copy the keys
                if(edkInputVariables.global.keys[i]){
                    edkInputVariables.global.readKeys=true;
                    break;
                }
            }
        }
        //open the controllers
        edkInputVariables.controllers.openControllers();
        //update the globals to the windows
        edkInputVariables.update();
        edkInputVariables.mut.unlock();
        //
        edk::watch::Time::sleepProcessMiliseconds(10u);
        edkInputVariables.mut.lock();
    }
    edkInputVariables.mut.unlock();
    return NULL;
}
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
void edk::Window::cleanEventsMouse(){
    //
    this->events.cleanMouseOnly();
}
//update joystick events
void edk::Window::updateControllerEvents(){
#if defined(EDK_USE_SFML)
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
#endif
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

        this->saveMouseHolded.Constructor();
        this->saveKeyHolded.Constructor();
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

#if defined(EDK_USE_SFML)
#endif
#if defined(EDK_USE_X11)
        this->image=NULL;
        this->gc=0u;
        this->window=0u;
        this->xim=NULL;
        this->xic=NULL;
        this->keysym = NoSymbol;
        this->fb_config=NULL;
        this->pixmap=0u;

        memset(this->keyCodesBits1,0u,sizeof(this->keyCodesBits1));
        memset(this->keyCodesBits2,0u,sizeof(this->keyCodesBits2));
        this->keyCodesBitsNow=&this->keyCodesBits1[0u];
        this->keyCodesBitsLast=&this->keyCodesBits2[0u];
        this->keyCodesBitsChange=NULL;
        this->windowPosition = 0;
        this->viewPosition = 0;
        this->windowRealSize = 0u;
        this->viewSize = 0u;
        this->saveDesign=0u;
        this->windowName.setName(" ");
        this->windowDepth=24;
        this->saveMousePosGlobal=-1;
        this->saveMousePos=-1;
        this->windowSizeIncrement=0;

        edkInputVariables.mut.lock();

        //LINUX
        XInitThreads();
        //test if need open the display
        if(!edkInputVariables.dis){
            //open the X11 display
            edkInputVariables.dis = XOpenDisplay(NULL);
            if(edkInputVariables.dis){
                setlocale(LC_ALL, "");
                edk::Window::displayNumberOfScreens = XScreenCount(edkInputVariables.dis);
                edk::Window::displayScreen = DefaultScreen(edkInputVariables.dis);
                edk::Window::displayDepth = DefaultDepth(edkInputVariables.dis, DefaultScreen(edkInputVariables.dis));

                /*
            edk::char8* vendorString = XServerVendor(edkInputVariables.dis);
            if(vendorString){
                printf("\n%u %s %s XServerVendor == '%s'",__LINE__,__FILE__,__func__,vendorString);fflush(stdout);
            }

            edk::char8* display_string = DisplayString(edkInputVariables.dis);
            if(display_string){
                printf("\n%u %s %s DisplayString == '%s'",__LINE__,__FILE__,__func__,display_string);fflush(stdout);
            }
*/
                edk::Window::displaySize.width = XDisplayWidth(edkInputVariables.dis, edk::Window::displayScreen);
                edk::Window::displaySize.height = XDisplayHeight(edkInputVariables.dis, edk::Window::displayScreen);

                edk::Window::displayBlack = XBlackPixel(edkInputVariables.dis, edk::Window::displayScreen);
                edk::Window::displayWhite = XWhitePixel(edkInputVariables.dis, edk::Window::displayScreen);



                //test if have keyCodes
                if(!edkInputVariables.haveKeyCodes){
                    edkInputVariables.haveKeyCodes=true;

                    for(edk::uint32 i=0u;i<32u*8u;i++){
                        edkInputVariables.keyCodes[i]=edk::key::nothing;
                    }

                    //load the keyCodes

                    edkInputVariables.keyCodes[/*022*/XKeysymToKeycode(edkInputVariables.dis,XK_BackSpace)] = edk::key::backSpace;
                    edkInputVariables.keyCodes[/*023*/XKeysymToKeycode(edkInputVariables.dis,XK_Tab)] = edk::key::tab;
                    edkInputVariables.keyCodes[/*036*/XKeysymToKeycode(edkInputVariables.dis,XK_Return)] = edk::key::Return;
                    edkInputVariables.keyCodes[/*127*/XKeysymToKeycode(edkInputVariables.dis,XK_Pause)] = edk::key::pause;
                    edkInputVariables.keyCodes[/*009*/XKeysymToKeycode(edkInputVariables.dis,XK_Escape)] = edk::key::escape;
                    edkInputVariables.keyCodes[/*119*/XKeysymToKeycode(edkInputVariables.dis,XK_Delete)] = edk::key::Delete;
                    edkInputVariables.keyCodes[/*110*/XKeysymToKeycode(edkInputVariables.dis,XK_Home)] = edk::key::home;
                    edkInputVariables.keyCodes[/*113*/XKeysymToKeycode(edkInputVariables.dis,XK_Left)] = edk::key::left;
                    edkInputVariables.keyCodes[/*111*/XKeysymToKeycode(edkInputVariables.dis,XK_Up)] = edk::key::up;
                    edkInputVariables.keyCodes[/*114*/XKeysymToKeycode(edkInputVariables.dis,XK_Right)] = edk::key::right;
                    edkInputVariables.keyCodes[/*116*/XKeysymToKeycode(edkInputVariables.dis,XK_Down)] = edk::key::down;
                    edkInputVariables.keyCodes[/*112*/XKeysymToKeycode(edkInputVariables.dis,XK_Prior)] = edk::key::pageUp;
                    edkInputVariables.keyCodes[/*117*/XKeysymToKeycode(edkInputVariables.dis,XK_Next)] = edk::key::pageDown;
                    edkInputVariables.keyCodes[/*115*/XKeysymToKeycode(edkInputVariables.dis,XK_End)] = edk::key::end;
                    edkInputVariables.keyCodes[/*118*/XKeysymToKeycode(edkInputVariables.dis,XK_Insert)] = edk::key::insert;
                    edkInputVariables.keyCodes[/*135*/XKeysymToKeycode(edkInputVariables.dis,XK_Menu)] = edk::key::menu;
                    edkInputVariables.keyCodes[/*000*/XKeysymToKeycode(edkInputVariables.dis,XK_KP_Space)] = edk::key::space;
                    edkInputVariables.keyCodes[/*000*/XKeysymToKeycode(edkInputVariables.dis,XK_KP_Tab)] = edk::key::tab;
                    edkInputVariables.keyCodes[/*079*/XKeysymToKeycode(edkInputVariables.dis,XK_KP_Home)] = edk::key::numpad7;
                    edkInputVariables.keyCodes[/*083*/XKeysymToKeycode(edkInputVariables.dis,XK_KP_Left)] = edk::key::numpad4;
                    edkInputVariables.keyCodes[/*080*/XKeysymToKeycode(edkInputVariables.dis,XK_KP_Up)] = edk::key::numpad8;
                    edkInputVariables.keyCodes[/*085*/XKeysymToKeycode(edkInputVariables.dis,XK_KP_Right)] = edk::key::numpad6;
                    edkInputVariables.keyCodes[/*088*/XKeysymToKeycode(edkInputVariables.dis,XK_KP_Down)] = edk::key::numpad2;
                    edkInputVariables.keyCodes[/*081*/XKeysymToKeycode(edkInputVariables.dis,XK_KP_Page_Up)] = edk::key::numpad9;
                    edkInputVariables.keyCodes[/*089*/XKeysymToKeycode(edkInputVariables.dis,XK_KP_Page_Down)] = edk::key::numpad3;
                    edkInputVariables.keyCodes[/*087*/XKeysymToKeycode(edkInputVariables.dis,XK_KP_End)] = edk::key::numpad1;
                    edkInputVariables.keyCodes[/*084*/XKeysymToKeycode(edkInputVariables.dis,XK_KP_Begin)] = edk::key::numpad5;
                    edkInputVariables.keyCodes[/*090*/XKeysymToKeycode(edkInputVariables.dis,XK_KP_Insert)] = edk::key::numpad0;
                    edkInputVariables.keyCodes[/*091*/XKeysymToKeycode(edkInputVariables.dis,XK_KP_Delete)] = edk::key::Delete;
                    edkInputVariables.keyCodes[/*125*/XKeysymToKeycode(edkInputVariables.dis,XK_KP_Equal)] = edk::key::equal;
                    edkInputVariables.keyCodes[/*063*/XKeysymToKeycode(edkInputVariables.dis,XK_KP_Multiply)] = edk::key::multiply;
                    edkInputVariables.keyCodes[/*086*/XKeysymToKeycode(edkInputVariables.dis,XK_KP_Add)] = edk::key::add;
                    edkInputVariables.keyCodes[/*082*/XKeysymToKeycode(edkInputVariables.dis,XK_KP_Subtract)] = edk::key::subtract;
                    edkInputVariables.keyCodes[/*106*/XKeysymToKeycode(edkInputVariables.dis,XK_KP_Divide)] = edk::key::divide;
                    edkInputVariables.keyCodes[/*067*/XKeysymToKeycode(edkInputVariables.dis,XK_F1)] = edk::key::F1;
                    edkInputVariables.keyCodes[/*068*/XKeysymToKeycode(edkInputVariables.dis,XK_F2)] = edk::key::F2;
                    edkInputVariables.keyCodes[/*069*/XKeysymToKeycode(edkInputVariables.dis,XK_F3)] = edk::key::F3;
                    edkInputVariables.keyCodes[/*070*/XKeysymToKeycode(edkInputVariables.dis,XK_F4)] = edk::key::F4;
                    edkInputVariables.keyCodes[/*071*/XKeysymToKeycode(edkInputVariables.dis,XK_F5)] = edk::key::F5;
                    edkInputVariables.keyCodes[/*072*/XKeysymToKeycode(edkInputVariables.dis,XK_F6)] = edk::key::F6;
                    edkInputVariables.keyCodes[/*073*/XKeysymToKeycode(edkInputVariables.dis,XK_F7)] = edk::key::F7;
                    edkInputVariables.keyCodes[/*074*/XKeysymToKeycode(edkInputVariables.dis,XK_F8)] = edk::key::F8;
                    edkInputVariables.keyCodes[/*075*/XKeysymToKeycode(edkInputVariables.dis,XK_F9)] = edk::key::F9;
                    edkInputVariables.keyCodes[/*076*/XKeysymToKeycode(edkInputVariables.dis,XK_F10)] = edk::key::F10;
                    edkInputVariables.keyCodes[/*095*/XKeysymToKeycode(edkInputVariables.dis,XK_F11)] = edk::key::F11;
                    edkInputVariables.keyCodes[/*096*/XKeysymToKeycode(edkInputVariables.dis,XK_F12)] = edk::key::F12;
                    edkInputVariables.keyCodes[/*000*/XKeysymToKeycode(edkInputVariables.dis,XK_F13)] = edk::key::F13;
                    edkInputVariables.keyCodes[/*000*/XKeysymToKeycode(edkInputVariables.dis,XK_F14)] = edk::key::F14;
                    edkInputVariables.keyCodes[/*000*/XKeysymToKeycode(edkInputVariables.dis,XK_F15)] = edk::key::F15;
                    edkInputVariables.keyCodes[/*050*/XKeysymToKeycode(edkInputVariables.dis,XK_Shift_L)] = edk::key::lShift;
                    edkInputVariables.keyCodes[/*062*/XKeysymToKeycode(edkInputVariables.dis,XK_Shift_R)] = edk::key::rShift;
                    edkInputVariables.keyCodes[/*037*/XKeysymToKeycode(edkInputVariables.dis,XK_Control_L)] = edk::key::lControl;
                    edkInputVariables.keyCodes[/*105*/XKeysymToKeycode(edkInputVariables.dis,XK_Control_R)] = edk::key::rControl;
                    edkInputVariables.keyCodes[/*064*/XKeysymToKeycode(edkInputVariables.dis,XK_Alt_L)] = edk::key::lAlt;
                    edkInputVariables.keyCodes[/*000*/XKeysymToKeycode(edkInputVariables.dis,XK_Alt_R)] = edk::key::rAlt;
                    edkInputVariables.keyCodes[/*133*/XKeysymToKeycode(edkInputVariables.dis,XK_Super_L)] = edk::key::lSuper;
                    edkInputVariables.keyCodes[/*134*/XKeysymToKeycode(edkInputVariables.dis,XK_Super_R)] = edk::key::rSuper;
                    edkInputVariables.keyCodes[/*065*/XKeysymToKeycode(edkInputVariables.dis,XK_space)] = edk::key::space;// U+0020 SPACE
                    edkInputVariables.keyCodes[/*049*/XKeysymToKeycode(edkInputVariables.dis,XK_apostrophe)] = edk::key::quote;// U+0027 APOSTROPHE
                    edkInputVariables.keyCodes[/*059*/XKeysymToKeycode(edkInputVariables.dis,XK_comma)] = edk::key::comma;// U+002C COMMA
                    edkInputVariables.keyCodes[/*020*/XKeysymToKeycode(edkInputVariables.dis,XK_minus)] = edk::key::hyphen;// U+002D HYPHEN-MINUS
                    edkInputVariables.keyCodes[/*060*/XKeysymToKeycode(edkInputVariables.dis,XK_period)] = edk::key::period;// U+002E FULL STOP
                    edkInputVariables.keyCodes[/*097*/XKeysymToKeycode(edkInputVariables.dis,XK_slash)] = edk::key::slash;// U+002F SOLIDUS
                    edkInputVariables.keyCodes[/*061*/XKeysymToKeycode(edkInputVariables.dis,XK_semicolon)] = edk::key::semiColon;// U+003B SEMICOLON
                    edkInputVariables.keyCodes[/*021*/XKeysymToKeycode(edkInputVariables.dis,XK_equal)] = edk::key::equal;// U+003D EQUALS SIGN
                    edkInputVariables.keyCodes[/*038*/XKeysymToKeycode(edkInputVariables.dis,XK_A)] = edk::key::A;// U+0041 LATIN CAPITAL LETTER A
                    edkInputVariables.keyCodes[/*056*/XKeysymToKeycode(edkInputVariables.dis,XK_B)] = edk::key::B;// U+0042 LATIN CAPITAL LETTER B
                    edkInputVariables.keyCodes[/*054*/XKeysymToKeycode(edkInputVariables.dis,XK_C)] = edk::key::C;// U+0043 LATIN CAPITAL LETTER C
                    edkInputVariables.keyCodes[/*040*/XKeysymToKeycode(edkInputVariables.dis,XK_D)] = edk::key::D;// U+0044 LATIN CAPITAL LETTER D
                    edkInputVariables.keyCodes[/*026*/XKeysymToKeycode(edkInputVariables.dis,XK_E)] = edk::key::E;// U+0045 LATIN CAPITAL LETTER E
                    edkInputVariables.keyCodes[/*041*/XKeysymToKeycode(edkInputVariables.dis,XK_F)] = edk::key::F;// U+0046 LATIN CAPITAL LETTER F
                    edkInputVariables.keyCodes[/*042*/XKeysymToKeycode(edkInputVariables.dis,XK_G)] = edk::key::G;// U+0047 LATIN CAPITAL LETTER G
                    edkInputVariables.keyCodes[/*043*/XKeysymToKeycode(edkInputVariables.dis,XK_H)] = edk::key::H;// U+0048 LATIN CAPITAL LETTER H
                    edkInputVariables.keyCodes[/*031*/XKeysymToKeycode(edkInputVariables.dis,XK_I)] = edk::key::I;// U+0049 LATIN CAPITAL LETTER I
                    edkInputVariables.keyCodes[/*044*/XKeysymToKeycode(edkInputVariables.dis,XK_J)] = edk::key::J;// U+004A LATIN CAPITAL LETTER J
                    edkInputVariables.keyCodes[/*045*/XKeysymToKeycode(edkInputVariables.dis,XK_K)] = edk::key::K;// U+004B LATIN CAPITAL LETTER K
                    edkInputVariables.keyCodes[/*046*/XKeysymToKeycode(edkInputVariables.dis,XK_L)] = edk::key::L;// U+004C LATIN CAPITAL LETTER L
                    edkInputVariables.keyCodes[/*058*/XKeysymToKeycode(edkInputVariables.dis,XK_M)] = edk::key::M;// U+004D LATIN CAPITAL LETTER M
                    edkInputVariables.keyCodes[/*057*/XKeysymToKeycode(edkInputVariables.dis,XK_N)] = edk::key::N;// U+004E LATIN CAPITAL LETTER N
                    edkInputVariables.keyCodes[/*032*/XKeysymToKeycode(edkInputVariables.dis,XK_O)] = edk::key::O;// U+004F LATIN CAPITAL LETTER O
                    edkInputVariables.keyCodes[/*033*/XKeysymToKeycode(edkInputVariables.dis,XK_P)] = edk::key::P;// U+0050 LATIN CAPITAL LETTER P
                    edkInputVariables.keyCodes[/*024*/XKeysymToKeycode(edkInputVariables.dis,XK_Q)] = edk::key::Q;// U+0051 LATIN CAPITAL LETTER Q
                    edkInputVariables.keyCodes[/*027*/XKeysymToKeycode(edkInputVariables.dis,XK_R)] = edk::key::R;// U+0052 LATIN CAPITAL LETTER R
                    edkInputVariables.keyCodes[/*039*/XKeysymToKeycode(edkInputVariables.dis,XK_S)] = edk::key::S;// U+0053 LATIN CAPITAL LETTER S
                    edkInputVariables.keyCodes[/*028*/XKeysymToKeycode(edkInputVariables.dis,XK_T)] = edk::key::T;// U+0054 LATIN CAPITAL LETTER T
                    edkInputVariables.keyCodes[/*030*/XKeysymToKeycode(edkInputVariables.dis,XK_U)] = edk::key::U;// U+0055 LATIN CAPITAL LETTER U
                    edkInputVariables.keyCodes[/*055*/XKeysymToKeycode(edkInputVariables.dis,XK_V)] = edk::key::V;// U+0056 LATIN CAPITAL LETTER V
                    edkInputVariables.keyCodes[/*025*/XKeysymToKeycode(edkInputVariables.dis,XK_W)] = edk::key::W;// U+0057 LATIN CAPITAL LETTER W
                    edkInputVariables.keyCodes[/*053*/XKeysymToKeycode(edkInputVariables.dis,XK_X)] = edk::key::X;// U+0058 LATIN CAPITAL LETTER X
                    edkInputVariables.keyCodes[/*029*/XKeysymToKeycode(edkInputVariables.dis,XK_Y)] = edk::key::Y;// U+0059 LATIN CAPITAL LETTER Y
                    edkInputVariables.keyCodes[/*052*/XKeysymToKeycode(edkInputVariables.dis,XK_Z)] = edk::key::Z;// U+005A LATIN CAPITAL LETTER Z
                    edkInputVariables.keyCodes[/*035*/XKeysymToKeycode(edkInputVariables.dis,XK_bracketleft)] = edk::key::lBracket;// U+005B LEFT SQUARE BRACKET
                    edkInputVariables.keyCodes[/*094*/XKeysymToKeycode(edkInputVariables.dis,XK_backslash)] = edk::key::backSlash;// U+005C REVERSE SOLIDUS
                    edkInputVariables.keyCodes[/*051*/XKeysymToKeycode(edkInputVariables.dis,XK_bracketright)] = edk::key::rBracket;// U+005D RIGHT SQUARE BRACKET
                    edkInputVariables.keyCodes[/*034*/XKeysymToKeycode(edkInputVariables.dis,XK_grave)] = edk::key::tilde;// U+0060 GRAVE ACCENT

                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Escape)] = edk::key::escape;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_F1)] = edk::key::F1;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_F2)] = edk::key::F2;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_F3)] = edk::key::F3;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_F4)] = edk::key::F4;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_F5)] = edk::key::F5;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_F6)] = edk::key::F6;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_F7)] = edk::key::F7;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_F8)] = edk::key::F8;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_F9)] = edk::key::F9;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_F10)] = edk::key::F10;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_F11)] = edk::key::F11;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_F12)] = edk::key::F12;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_F13)] = edk::key::F13;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_F14)] = edk::key::F14;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_F15)] = edk::key::F15;

                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_BackSpace)] = edk::key::backSpace;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Tab)] = edk::key::tab;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Return)] = edk::key::Return;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Pause)] = edk::key::pause;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Delete)] = edk::key::Delete;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Home)] = edk::key::home;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Left)] = edk::key::left;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Up)] = edk::key::up;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Right)] = edk::key::right;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Down)] = edk::key::down;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Prior)] = edk::key::pageUp;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Next)] = edk::key::pageDown;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_End)] = edk::key::end;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Insert)] = edk::key::insert;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Menu)] = edk::key::menu;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_Space)] = edk::key::space;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_Tab)] = edk::key::tab;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_Home)] = edk::key::numpad7;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_Left)] = edk::key::numpad4;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_Up)] = edk::key::numpad8;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_Right)] = edk::key::numpad6;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_Down)] = edk::key::numpad2;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_Page_Up)] = edk::key::numpad9;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_Page_Down)] = edk::key::numpad3;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_End)] = edk::key::numpad1;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_Begin)] = edk::key::numpad5;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_Insert)] = edk::key::numpad0;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_Delete)] = edk::key::Delete;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_Equal)] = edk::key::equal;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_Multiply)] = edk::key::multiply;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_Add)] = edk::key::add;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_Subtract)] = edk::key::subtract;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_Divide)] = edk::key::divide;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Shift_L)] = edk::key::lShift;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Shift_R)] = edk::key::rShift;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Control_L)] = edk::key::lControl;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Control_R)] = edk::key::rControl;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Alt_L)] = edk::key::lAlt;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Alt_R)] = edk::key::rAlt;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Super_L)] = edk::key::lSuper;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Super_R)] = edk::key::rSuper;
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_space)] = edk::key::space;// U+0020 SPACE
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_apostrophe)] = edk::key::quote;// U+0027 APOSTROPHE
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_comma)] = edk::key::comma;// U+002C COMMA
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_minus)] = edk::key::hyphen;// U+002D HYPHEN-MINUS
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_period)] = edk::key::period;// U+002E FULL STOP
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_slash)] = edk::key::slash;// U+002F SOLIDUS
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_semicolon)] = edk::key::semiColon;// U+003B SEMICOLON
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_equal)] = edk::key::equal;// U+003D EQUALS SIGN
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_A)] = edk::key::A;// U+0041 LATIN CAPITAL LETTER A
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_B)] = edk::key::B;// U+0042 LATIN CAPITAL LETTER B
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_C)] = edk::key::C;// U+0043 LATIN CAPITAL LETTER C
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_D)] = edk::key::D;// U+0044 LATIN CAPITAL LETTER D
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_E)] = edk::key::E;// U+0045 LATIN CAPITAL LETTER E
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_F)] = edk::key::F;// U+0046 LATIN CAPITAL LETTER F
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_G)] = edk::key::G;// U+0047 LATIN CAPITAL LETTER G
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_H)] = edk::key::H;// U+0048 LATIN CAPITAL LETTER H
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_I)] = edk::key::I;// U+0049 LATIN CAPITAL LETTER I
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_J)] = edk::key::J;// U+004A LATIN CAPITAL LETTER J
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_K)] = edk::key::K;// U+004B LATIN CAPITAL LETTER K
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_L)] = edk::key::L;// U+004C LATIN CAPITAL LETTER L
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_M)] = edk::key::M;// U+004D LATIN CAPITAL LETTER M
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_N)] = edk::key::N;// U+004E LATIN CAPITAL LETTER N
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_O)] = edk::key::O;// U+004F LATIN CAPITAL LETTER O
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_P)] = edk::key::P;// U+0050 LATIN CAPITAL LETTER P
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Q)] = edk::key::Q;// U+0051 LATIN CAPITAL LETTER Q
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_R)] = edk::key::R;// U+0052 LATIN CAPITAL LETTER R
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_S)] = edk::key::S;// U+0053 LATIN CAPITAL LETTER S
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_T)] = edk::key::T;// U+0054 LATIN CAPITAL LETTER T
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_U)] = edk::key::U;// U+0055 LATIN CAPITAL LETTER U
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_V)] = edk::key::V;// U+0056 LATIN CAPITAL LETTER V
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_W)] = edk::key::W;// U+0057 LATIN CAPITAL LETTER W
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_X)] = edk::key::X;// U+0058 LATIN CAPITAL LETTER X
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Y)] = edk::key::Y;// U+0059 LATIN CAPITAL LETTER Y
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_Z)] = edk::key::Z;// U+005A LATIN CAPITAL LETTER Z
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_bracketleft)] = edk::key::lBracket;// U+005B LEFT SQUARE BRACKET
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_backslash)] = edk::key::backSlash;// U+005C REVERSE SOLIDUS
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_bracketright)] = edk::key::rBracket;// U+005D RIGHT SQUARE BRACKET
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_grave)] = edk::key::tilde;// U+0060 GRAVE ACCENT
                    //
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_0)] = edk::key::num0;//
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_1)] = edk::key::num1;//
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_2)] = edk::key::num2;//
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_3)] = edk::key::num3;//
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_4)] = edk::key::num4;//
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_5)] = edk::key::num5;//
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_6)] = edk::key::num6;//
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_7)] = edk::key::num7;//
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_8)] = edk::key::num8;//
                    edkInputVariables.keyCodes[XKeysymToKeycode(edkInputVariables.dis,XK_KP_9)] = edk::key::num9;//

#include "DebugWindow.h"
                }

                //open the root window
                edkInputVariables.rootw = XRootWindow(edkInputVariables.dis,edk::Window::displayScreen);
                edkInputVariables.rootw = DefaultRootWindow(edkInputVariables.dis);
                if(edkInputVariables.rootw){
                    XWindowAttributes xwa;
                    XGetWindowAttributes( edkInputVariables.dis, edkInputVariables.rootw, &xwa );
                    //printf("\nDEPTHS");fflush(stdout);
                    if(xwa.screen){
                        if(xwa.screen->depths && xwa.screen->ndepths){
                            for(edk::int32 i=0u;i<xwa.screen->ndepths;i++){
                                //printf("\nDEPTH %d == %d",i,xwa.screen->depths[i].depth);fflush(stdout);
                                if(xwa.screen->depths[i].visuals && xwa.screen->depths[i].nvisuals){
                                    //printf("\n     VISUAL %d == %ld",0,xwa.screen->depths[i].visuals->visualid);fflush(stdout);
                                    edkInputVariables.treeVisuals.addNewVisual(xwa.screen->depths[i].visuals,
                                                                               xwa.screen->depths[i].depth
                                                                               );
                                }
                            }
                        }
                    }

                    //get the monitors
                    edk::int32 n;
                    edk::Window::m = XRRGetMonitors(edkInputVariables.dis, edkInputVariables.rootw, true, &n);
                    if(edk::Window::m){
                        //get the monitors
                        for(edk::int32 i=0;i<n;i++){
                            //
                            edkInputVariables.newMonitor(i,
                                                         (edk::uint32)edk::Window::m[i].name,
                                                         edk::Window::m[i].primary,
                                                         edk::Window::m[i].automatic,
                                                         edk::vec2i32(edk::Window::m[i].x,edk::Window::m[i].y),
                                                         edk::size2i32(edk::Window::m[i].width,edk::Window::m[i].height),
                                                         edk::size2i32(edk::Window::m[i].mwidth,edk::Window::m[i].mheight),
                                                         edk::Window::m[i].noutput,
                                                         (edk::uint32*)edk::Window::m[i].outputs
                                                         );
                        }
                    }
                    //increment the winCounter
                    edkInputVariables.winCounter++;
                    //add the window in to the globals
                    edkInputVariables.newGlobal(this);

                    //create the thread to read the globalMouse
                    edk::uint32 cores = edkInputVariables.thread.numberOfCores();
                    if(cores){
                        edkInputVariables.thread.startIn(edkFunctionMouseScroll,cores-1u);
                    }
                    else{
                        edkInputVariables.thread.startIn(edkFunctionMouseScroll,0u);
                    }
                }
                else{
                    //else it don't have a root window

                    //close the display
                    XCloseDisplay(edkInputVariables.dis);
                    edkInputVariables.dis=NULL;
                }
            }
            edkInputVariables.mut.unlock();
            edk::Window::useOpenGL();
            edkInputVariables.mut.lock();
        }
        else{
            //increment the winCounter
            edkInputVariables.winCounter++;
            //add the window in to the globals
            edkInputVariables.newGlobal(this);
        }

        edkInputVariables.mut.unlock();
#endif
    }
}
void edk::Window::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        //clean the events
        this->cleanEvents();

        this->saveMouseHolded.clean();
        this->saveKeyHolded.clean();

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

//useOpenGL
bool edk::Window::setUseOpenGL(){
#if defined(EDK_USE_X11)
    //LINUX
    edkInputVariables.mut.lock();
    if(edkInputVariables.dis){
        if(!edkInputVariables.glc){
            /*
            // Atributos GLX (agora para FBConfig)
            // Usamos FBConfig que é o método moderno para pedir recursos como MSAA.
            int fb_attribs[] = {
                GLX_RENDER_TYPE, GLX_RGBA_BIT,
                GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
                GLX_DOUBLEBUFFER, True,
                GLX_DEPTH_SIZE, 24,
                GLX_RED_SIZE, 8,
                GLX_GREEN_SIZE, 8,
                GLX_BLUE_SIZE, 8,
                // --- Configurações MSAA (aqui definimos o pedido) ---
                GLX_SAMPLE_BUFFERS, 1, // Pede o buffer de amostragem
                GLX_SAMPLES, 4,        // Pede 4x de samples (MSAA 4x)
                None
            };

            // Variáveis para FBConfig
            GLXFBConfig *fb_configs = nullptr;
            int num_configs = 0;

            // Tenta encontrar a FBConfig com MSAA 4x
            fb_configs = glXChooseFBConfig(edkInputVariables.dis, DefaultScreen(edkInputVariables.dis), fb_attribs, &num_configs);

            // 2. Tenta fazer o fallback (se MSAA 4x não funcionar)
            if (!fb_configs || num_configs == 0) {
                XFree(fb_configs); // Libera o ponteiro nulo ou falho

                // Atributos de fallback sem MSAA
                int fallback_attribs[] = {
                    GLX_RENDER_TYPE, GLX_RGBA_BIT,
                    GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
                    GLX_DOUBLEBUFFER, True,
                    GLX_DEPTH_SIZE, 24,
                    None
                };
                fb_configs = glXChooseFBConfig(edkInputVariables.dis, DefaultScreen(edkInputVariables.dis), fallback_attribs, &num_configs);

                if (!fb_configs || num_configs == 0) {
                    edkInputVariables.mut.unlock();
                    return false;
                }
            }

            // 3. Escolhe o primeiro FBConfig encontrado
            edkInputVariables.fb_config = fb_configs[0];
            XFree(fb_configs); // Libera a lista de configurações

            // 5. Cria o contexto GLX
            // glXCreateNewContext é o correspondente moderno de glXCreateContext para FBConfigs
            edkInputVariables.glc = glXCreateNewContext(edkInputVariables.dis, edkInputVariables.fb_config, GLX_RGBA_TYPE, nullptr, GL_TRUE);
            if (!edkInputVariables.glc) {
                edkInputVariables.mut.unlock();
                return false;
            }
*/
            XVisualInfo *vInfo;
            edk::int32 glx_attributes[] = {
                GLX_RGBA,
                GLX_DEPTH_SIZE, 24,
                GLX_DOUBLEBUFFER,
                None
            };
            vInfo = glXChooseVisual(edkInputVariables.dis, DefaultScreen(edkInputVariables.dis), glx_attributes);
            if(vInfo){
                edkInputVariables.glc = glXCreateContext(edkInputVariables.dis, vInfo, NULL, GL_TRUE);
                if(!edkInputVariables.glc){
                    XFree(vInfo);
                    edkInputVariables.mut.unlock();
                    return false;
                }
                XFree(vInfo);
            }
            else{
                edkInputVariables.mut.unlock();
                return false;
            }
        }
        if(edkInputVariables.glc){
            glXMakeCurrent(edkInputVariables.dis, None, edkInputVariables.glc);
        }
        edkInputVariables.mut.unlock();
        return true;
    }
    edkInputVariables.mut.unlock();
#endif
    return false;
}
//dontUseOpenGL
bool edk::Window::setDontUseOpenGL(){
#if defined(EDK_USE_X11)
    //LINUX
    if(edkInputVariables.dis){
        if(edkInputVariables.glc){
            glXMakeCurrent(edkInputVariables.dis, None, NULL);
        }
        edkInputVariables.mut.unlock();
        return true;
    }
    edkInputVariables.mut.unlock();
#endif
    return false;
}
//finishUseOpenGL
bool edk::Window::setFinishUseOpenGL(){
#if defined(EDK_USE_X11)
    edkInputVariables.mut.lock();
    if(edkInputVariables.dis){
        if(edkInputVariables.glc){
            edk::Window::dontUseOpenGL();
            glXDestroyContext(edkInputVariables.dis, edkInputVariables.glc);
            edkInputVariables.glc=NULL;
        }
        edkInputVariables.mut.unlock();
        return true;
    }
    edkInputVariables.mut.unlock();
#endif
    return false;
}

bool edk::Window::createWindowWithAliasing(edk::uint32 width, edk::uint32 height, edk::char8 *name, edk::typeID design, edk::uint32 depth, edk::uint32 stencil, edk::uint8 aliasing){
    //antes fecha a janela anterior
    if(this->isOpened()){
        //fecha a janela
        this->closeWindow();
    }
#if defined(EDK_USE_SFML)
    uint32 bitsPerPixel=0u;

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
        //this->window.Create(sf::VideoMode(width, height, bitsPerPixel),(const edk::char8*)name,style,sf::WindowSettings(depth,stencil,aliasing));//1.6
        this->window.create(sf::VideoMode(width, height, bitsPerPixel),(const edk::char8*)name,style,sf::ContextSettings(depth,stencil,aliasing));//2.0

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
#endif
#if defined(EDK_USE_X11)
    if(name){

        // Variáveis para FBConfig
        GLXFBConfig *fb_configs = nullptr;
        int num_configs = 0;

        // Atributos GLX (agora para FBConfig)
        // Usamos FBConfig que é o método moderno para pedir recursos como MSAA.
        int fb_attribs[] = {
            GLX_RENDER_TYPE, GLX_RGBA_BIT,
            GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
            GLX_DOUBLEBUFFER, True,
            GLX_DEPTH_SIZE, 24,
            GLX_RED_SIZE, 8,
            GLX_GREEN_SIZE, 8,
            GLX_BLUE_SIZE, 8,
            // --- Configurações MSAA (aqui definimos o pedido) ---
            GLX_SAMPLE_BUFFERS, 0, // Pede o buffer de amostragem
            GLX_SAMPLES, 0,        // Pede 4x de samples (MSAA 4x)
            None
        };
        this->aliasing=aliasing;

        if(this->aliasing){

            if(this->aliasing>=1u && this->aliasing<=3u){
                this->aliasing=2u;
            }
            else if(this->aliasing>=4u && this->aliasing<=7u){
                this->aliasing=4u;
            }
            else if(this->aliasing>=8u && this->aliasing<=15u){
                this->aliasing=8u;
            }
            else if(this->aliasing>=16u && this->aliasing<=31u){
                this->aliasing=16u;
            }
            else if(this->aliasing>=32u){
                this->aliasing=32u;
            }
            fb_attribs[15u] = 1;
            fb_attribs[17u] = this->aliasing;
        }

        // Tenta encontrar a FBConfig com MSAA 4x
        fb_configs = glXChooseFBConfig(edkInputVariables.dis, DefaultScreen(edkInputVariables.dis), fb_attribs, &num_configs);

        // 2. Tenta fazer o fallback (se MSAA 4x não funcionar)
        if (!fb_configs || num_configs == 0) {
            XFree(fb_configs); // Libera o ponteiro nulo ou falho

            // Atributos de fallback sem MSAA
            int fallback_attribs[] = {
                GLX_RENDER_TYPE, GLX_RGBA_BIT,
                GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
                GLX_DOUBLEBUFFER, True,
                GLX_DEPTH_SIZE, 24,
                None
            };
            fb_configs = glXChooseFBConfig(edkInputVariables.dis, DefaultScreen(edkInputVariables.dis), fallback_attribs, &num_configs);

            if (!fb_configs || num_configs == 0) {
                return false;
            }
        }

        // 3. Escolhe o primeiro FBConfig encontrado
        this->fb_config = fb_configs[0];
        XFree(fb_configs); // Libera a lista de configurações

        // 5. Cria o contexto GLX
        // glXCreateNewContext é o correspondente moderno de glXCreateContext para FBConfigs
        this->context = glXCreateNewContext(edkInputVariables.dis, this->fb_config, GLX_RGBA_TYPE, nullptr, GL_TRUE);
        if (!this->context) {
            return false;
        }

        XVisualInfo *vInfo;
        /*
        edk::int32 glx_attributes[] = {
            GLX_RGBA,
            GLX_DEPTH_SIZE, 24,
            GLX_DOUBLEBUFFER,
            None
        };
        */
        vInfo =
                //glXChooseVisual(edkInputVariables.dis, DefaultScreen(edkInputVariables.dis), glx_attributes)
                glXGetVisualFromFBConfig(edkInputVariables.dis, this->fb_config);
        ;

        if(!vInfo){
            return false;
        }

        //LINUX
        Visual *visual=
                vInfo->visual
                //edkInputVariables.treeVisuals.getVisual(depth)
                ;
        //test if have the depth
        if(visual){
            this->windowDepth = depth;
        }
        else{
            if(edkInputVariables.treeVisuals.size()){
                depth = edkInputVariables.treeVisuals.getDepthInPosition(0u);
                visual = edkInputVariables.treeVisuals.getVisual(depth);
                if(visual){
                    this->windowDepth = depth;
                }
                else{
                    return false;
                }
            }
            else{
                //else return false
                return false;
            }
        }

        // create window
        XSetWindowAttributes attr ;
        attr.colormap   = XCreateColormap( edkInputVariables.dis, edkInputVariables.rootw, visual, AllocNone) ;
        /*
        attr.event_mask =
                ExposureMask |
                KeyPressMask |
                ResizeRedirectMask |
                0;
        attr.background_pixmap = None ;
        attr.border_pixel      = 0 ;
*/
        attr.event_mask = ExposureMask | KeyPressMask;

        this->window = XCreateWindow(edkInputVariables.dis, edkInputVariables.rootw,
                                     0, 0, width, height,
                                     0,
                                     vInfo->depth,
                                     InputOutput,
                                     visual,
                                     CWColormap | CWEventMask, &attr
                                     );
        if(this->window){
            //set the window to opened
            this->opened=true;

            XMapWindow(edkInputVariables.dis, this->window);

            this->setWindowName(name);

            this->useOpenGLInWindow();

            //load the window attributes
            this->loadWindowAttributes();
            this->windowSize = this->windowRealSize;

            //set the position and size
            this->setWindowSize(width,height);

            if((design & EDK_WINDOW_FULLSCREEN) && !this->haveSaveWindowDesign){
                //save the position and size
                this->saveWindowDesignPosition = this->windowPosition;
                this->saveWindowDesignSize = this->windowRealSize;
                this->haveSaveWindowDesign=true;
            }

            //set the design
            this->changeDesign(design);

            // Set the window mask
            XSelectInput(edkInputVariables.dis, this->window,
                         KeyPressMask
                         | KeyReleaseMask
                         | ButtonPressMask
                         | ButtonReleaseMask
                         | EnterWindowMask
                         | LeaveWindowMask
                         | PointerMotionMask

                         //| PointerMotionHintMask
                         //| Button1MotionMask
                         //| Button2MotionMask
                         //| Button3MotionMask
                         //| Button4MotionMask
                         //| Button5MotionMask
                         //| ButtonMotionMask

                         //| KeymapStateMask

                         | ExposureMask

                         //| VisibilityChangeMask

                         | StructureNotifyMask

                         //| ResizeRedirectMask

                         | SubstructureNotifyMask

                         //| SubstructureRedirectMask

                         | FocusChangeMask

                         //| PropertyChangeMask
                         //| ColormapChangeMask
                         //| OwnerGrabButtonMask
                         );
            XMapWindow(edkInputVariables.dis, this->window);

            this->newGC();

            //create an image with the pixMap
            this->pixmap = XCreatePixmap(edkInputVariables.dis, edkInputVariables.rootw,200, 200, 24);
            this->image = XGetImage(edkInputVariables.dis, this->pixmap,0, 0, 200, 200, 24, XYPixmap);

            edk::GU::guOpen();
            edk::GU_GLSL::guShaderInit();

            //set the blend with alpha channel
            edk::GU::guEnable(GU_BLEND);
            edk::GU::guBlendFunc(GU_SRC_ALPHA,GU_ONE_MINUS_SRC_ALPHA);

            this->renderWindow=true;

            this->time.start();

            //Activate the charactere reader
            XSetLocaleModifiers("");

            this->xim = XOpenIM(edkInputVariables.dis, NULL, NULL, NULL);
            if (this->xim) {
                this->xic = XCreateIC(this->xim,
                                      XNInputStyle, XIMPreeditNothing | XIMStatusNothing,
                                      XNClientWindow, this->window,
                                      XNFocusWindow, this->window,
                                      nullptr);
                if (this->xic) {
                    XSetICFocus(this->xic); // Garante que o IC está focado na nossa janela
                }
            }

            this->dontUseOpenGLInWindow();

            return true;
        }
    }
#endif
    return false;
}

bool edk::Window::createWindowWithAliasing(edk::uint32 width, edk::uint32 height, const char *name, edk::typeID design, edk::uint32 depth, edk::uint32 stencil, edk::uint8 aliasing){
    return this->createWindowWithAliasing(width,height,
                                          (edk::char8*) name,
                                          design, depth, stencil,
                                          aliasing
                                          );
}

bool edk::Window::createWindowWithAliasing(edk::uint32  width, edk::uint32  height, edk::char8 *name, edk::typeID design, edk::uint8 aliasing){
    return this->createWindowWithAliasing(width,height,
                                          name,
                                          design,
                                          24u,8u,
                                          aliasing
                                          );
}

bool edk::Window::createWindowWithAliasing(edk::uint32  width, edk::uint32  height, const edk::char8 *name, edk::typeID  design, edk::uint8 aliasing){
    return this->createWindowWithAliasing(width, height,
                                          (char8 *)name,
                                          design,
                                          24u,8u,
                                          aliasing
                                          );
}

bool edk::Window::createWindow(edk::uint32 width, edk::uint32 height, edk::char8 *name, edk::typeID design, edk::uint32 depth, edk::uint32 stencil){
    return this->createWindowWithAliasing(width,height,
                                          (edk::char8*) name,
                                          design, depth, stencil,
                                          0u
                                          );
}

bool edk::Window::createWindow(edk::uint32 width, edk::uint32 height, const edk::char8 *name, edk::typeID design, edk::uint32 depth, edk::uint32 stencil){
    return this->createWindowWithAliasing(width,height,
                                          (edk::char8*) name,
                                          design, depth, stencil,
                                          0u
                                          );
}

bool edk::Window::createWindow(edk::uint32  width, edk::uint32  height, edk::char8 *name, edk::typeID design){
    return this->createWindowWithAliasing(width,height,
                                          name,
                                          design,
                                          24u,8u,0u
                                          );
}

bool edk::Window::createWindow(edk::uint32  width, edk::uint32  height, const char *name, edk::typeID  design){
    return this->createWindowWithAliasing(width, height,
                                          (char8 *)name,
                                          design,
                                          24u,8u,0u
                                          );
}

//useOpenGL
bool edk::Window::setUseOpenGLInWindow(){
#if defined(EDK_USE_SFML)
#endif
#if defined(EDK_USE_X11)
    edkInputVariables.mut.lock();
    if(edkInputVariables.dis){
        if(edkInputVariables.glc){
            glXMakeCurrent(edkInputVariables.dis, this->window,this->context);
        }
        edkInputVariables.mut.unlock();
        edk::GU::guEnable(GU_MULTISAMPLE);
        return true;
    }
    edkInputVariables.mut.unlock();
#endif
    return false;
}
//dontUseOpenGL
bool edk::Window::setDontUseOpenGLInWindow(){
#if defined(EDK_USE_SFML)
#endif
#if defined(EDK_USE_X11)
    edkInputVariables.mut.lock();
    if(edkInputVariables.dis){
        if(edkInputVariables.glc){
            glXMakeCurrent(edkInputVariables.dis, None, this->context);
        }
        edkInputVariables.mut.unlock();
        return true;
    }
    edkInputVariables.mut.unlock();
#endif
    return false;
}

bool edk::Window::setWindowName(const edk::char8 *name){
    return this->setWindowName((edk::char8 *)name);
}
bool edk::Window::setWindowName(edk::char8 *name){
    if(this->isOpened()){
#if defined(EDK_USE_SFML)
        this->window.setTitle(name);
#endif
#if defined(EDK_USE_X11)
        if(this->window){
            if(name){
                this->windowName.setName(name);
            }
            //else set " "
            else{
                this->windowName.setName(" ");
            }

            const char *titulo_utf8 = name;
            XTextProperty window_name_prop;

            // Converte a string UTF-8 para uma propriedade XTextProperty
            Status status = Xutf8TextListToTextProperty(
                        edkInputVariables.dis,
                        (char**)&titulo_utf8,
                        1,
                        XUTF8StringStyle,
                        &window_name_prop
                        );

            if(status >= Success){
                // Define _NET_WM_NAME (Padrão moderno, deve ser UTF-8)
                Atom net_wm_name = XInternAtom(edkInputVariables.dis, "_NET_WM_NAME", False);
                XSetTextProperty(edkInputVariables.dis, this->window, &window_name_prop, net_wm_name);

                // Define XA_WM_NAME (Compatibilidade, também definida com UTF-8)
                XSetTextProperty(edkInputVariables.dis, this->window, &window_name_prop, XA_WM_NAME);

                XFree(window_name_prop.value);
            }
            else{
                XStoreName(edkInputVariables.dis, this->window, titulo_utf8);
            }
        }
#endif
        return true;
    }
    return false;
}

bool edk::Window::isOpened(){
    //antes fecha a janela anterior
    //if(this->window.IsOpened()){1.6
#if defined(EDK_USE_SFML)
    if(this->window.isOpen()){//2.0
        //fecha a janela
        return true;
    }
#endif
#if defined(EDK_USE_X11)
    return this->opened;
#endif
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
bool edk::Window::isMinimized(){
    return false;
}

void edk::Window::closeWindow(){
    edk::GU::guDisable(GU_BLEND);
#if defined(EDK_USE_SFML)
    //
    //if(this->window.IsOpened()){//1.6
    if(this->window.isOpen()){//2.0
        //
        //this->window.Close();//1.6
        this->window.close();//2.0

        //set init the GU
        edk::GU::guClose();
    }
#endif
#if defined(EDK_USE_X11)
    edkInputVariables.mut.lock();
    if(edkInputVariables.dis){
        if(this->window){
            //edk::GU::guDisable(GU_BLEND);
            if(this->context){
                glXDestroyContext(edkInputVariables.dis, this->context);
            }
            if(this->image){
                //XDestroyImage(this->image);
                this->image=NULL;
            }

            if(this->pixmap){
                XFreePixmap(edkInputVariables.dis, this->pixmap);
                this->pixmap=0u;
            }


            if(this->gc){
                XFreeGC(edkInputVariables.dis, this->gc);
                this->gc=0;
            }

            if(this->xic){
                XDestroyIC(xic);
            }
            if(this->xim){
                XCloseIM(xim);
            }

            XDestroyWindow(edkInputVariables.dis, this->window);
        }

        XFlush(edkInputVariables.dis);
    }
    edkInputVariables.mut.unlock();
    this->window=0u;
    this->keysym = NoSymbol;
    this->xim=NULL;
    this->xic=NULL;
    this->fb_config=NULL;
#endif

    this->windowFocus = false;
    this->windowMinimized = false;
    this->windowGrab = false;
    this->mouseInside=false;
    this->windowSizeIncrement=0;
    this->aliasing=0u;

    //clean holded
    this->saveKeyHolded.clean();
    this->saveMouseHolded.clean();
    this->saveControllerHolded.clean();
}

void edk::Window::setVSYNC(bool vsync){
    if(this->vsync!=vsync){
        this->vsync=vsync;
#if defined(EDK_USE_SFML)
        if(this->window.isOpen()){
            this->window.setVerticalSyncEnabled(this->vsync);
        }
#endif
#if defined(EDK_USE_X11)
        if(this->vsync){
            //TRUE
            PFNGLXSWAPINTERVALEXTPROC glXSwapIntervalEXT =
                    (PFNGLXSWAPINTERVALEXTPROC)glXGetProcAddress((const GLubyte *)"glXSwapIntervalEXT");

            if(glXSwapIntervalEXT){
                // 'display' e 'window' são suas variáveis globais X11
                glXSwapIntervalEXT(edkInputVariables.dis, this->window, 1);
            }
        }
        else{
            //FALSE
            PFNGLXSWAPINTERVALEXTPROC glXSwapIntervalEXT =
                    (PFNGLXSWAPINTERVALEXTPROC)glXGetProcAddress((const GLubyte *)"glXSwapIntervalEXT");

            if(glXSwapIntervalEXT){
                // Intervalo = 0: DESABILITA VSync (troca de buffers ocorre imediatamente)
                glXSwapIntervalEXT(edkInputVariables.dis, this->window, 0);
            }
        }
#endif
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
#if defined(EDK_USE_SFML)
        //Entao ele pode limpar a janela
        //this->window.Clear(sf::Color((edk::uint32)(this->cleanColor.r*255),(edk::uint32)(this->cleanColor.g*255),(edk::uint32)(this->cleanColor.b*255),(edk::uint32)255));//1.6
        this->window.clear(sf::Color((edk::uint32)(this->cleanColor.r*255),
                                     (edk::uint32)(this->cleanColor.g*255),
                                     (edk::uint32)(this->cleanColor.b*255),
                                     (edk::uint32)255
                                     )
                           );//2.0
#endif
#if defined(EDK_USE_X11)
#endif
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
#if defined(EDK_USE_SFML)
        //seta o mouse
        //this->window.Show(show);//1.6
        this->window.setVisible(show);//2.0
#endif
#if defined(EDK_USE_X11)
#endif
    }
    this->renderWindow=show;
}

void edk::Window::showWindow(){
    this->windowRender(true);
}

void edk::Window::hideWindow(){
    this->windowRender(false);
}

//set full screen
void edk::Window::setFullscreen(bool fullscreen){
#if defined(EDK_USE_SFML)
    fullscreen=false;
#endif
#if defined(EDK_USE_X11)
    //test if have a window
    if(fullscreen){
        //add the fullscreen for the design
        this->changeDesign(this->saveDesign | EDK_WINDOW_FULLSCREEN);
    }
    else{
        //remove the fullscreen for the design
        this->changeDesign(this->saveDesign & ~EDK_WINDOW_FULLSCREEN);
    }
#endif
}
void edk::Window::setFullscreenOn(){
    this->setFullscreen(true);
}
void edk::Window::setFullscreenOff(){
    this->setFullscreen(false);
}

//change the design of the window
void edk::Window::changeDesign(typeID design){
    //
#if defined(EDK_USE_SFML)
#endif
#if defined(EDK_USE_X11)
    if(this->window){
        //test if need close and open a new window
        if(design & EDK_WINDOW_FULLSCREEN){
            if(!(this->saveDesign & EDK_WINDOW_FULLSCREEN)){
                edk::Name name;
                name.setName(this->windowName.getName());
                //save the design
                this->saveDesign=design;
                this->loadWindowAttributes();
                //save the position and size
                this->saveWindowDesignPosition = this->windowPosition;
                this->saveWindowDesignSize = this->windowRealSize;
                this->haveSaveWindowDesign=true;
                //ADD THE FULLSCREEN
                this->createWindowWithAliasing(this->windowRealSize.width,this->windowRealSize.height,name.getName(),design,this->windowDepth);

                //update the size to the last position and size
                this->windowPosition = this->saveWindowDesignPosition;
                this->windowRealSize = this->saveWindowDesignSize;
                this->updatePositionAndSize();

                edkInputVariables.mut.lock();
                XFlush(edkInputVariables.dis);
                edkInputVariables.mut.unlock();
                return;
            }
        }
        else{
            if(this->saveDesign & EDK_WINDOW_FULLSCREEN){
                edk::Name name;
                name.setName(this->windowName.getName());
                //save the design
                this->saveDesign=design;
                //if it's not saved. It will get the window attributes
                if(!this->haveSaveWindowDesign){
                    this->loadWindowAttributes();
                    //save the position and size
                    this->saveWindowDesignPosition = this->windowPosition;
                    this->saveWindowDesignSize = this->windowRealSize;
                }
                //REMOVE FULLSCREEN
                this->createWindowWithAliasing(this->saveWindowDesignSize.width,this->saveWindowDesignSize.height,name.getName(),design,this->windowDepth);

                //update the size to the last position and size
                this->setWindowPosition(this->saveWindowDesignPosition);

                this->haveSaveWindowDesign=false;

                edkInputVariables.mut.lock();
                XFlush(edkInputVariables.dis);
                edkInputVariables.mut.unlock();
                return;
            }
        }

        //clean the hints
        memset(&this->hints, 0u, sizeof(hints));
        this->hints.flags       = edkInputVariables.hintFunctions | edkInputVariables.hintDecorations;
        this->hints.decorations = 0u;
        this->hints.functions   = 0u;


        //set the window as NOBAR
        this->hints.decorations |= 0u;
        this->hints.functions |= edkInputVariables.hintFunctionMove;

        if(!(design & EDK_WINDOW_NOBAR)){
            edkEnd();
        }
        if(!(design & EDK_WINDOW_FULLSCREEN)){
            edkEnd();
        }
        if(!(design & EDK_WINDOW_NOBAR) && !(design & EDK_WINDOW_FULLSCREEN)){
            edkEnd();
        }
        //test if DON'T have noBar
        if(!(design & EDK_WINDOW_NOBAR) && !(design & EDK_WINDOW_FULLSCREEN)){
            //SET THE BAR
            if(design & EDK_WINDOW_BAR){
                this->hints.decorations |= edkInputVariables.hintDecorationBorder |
                        edkInputVariables.hintDecorationTitle;
                this->hints.functions |= edkInputVariables.hintFunctionMove;
            }
            if(design & EDK_WINDOW_RESIZE){
                this->hints.decorations |= edkInputVariables.hintDecorationBorder |
                        edkInputVariables.hintDecorationTitle;
                this->hints.functions |= edkInputVariables.hintFunctionMove |
                        edkInputVariables.hintFunctionMinimize |
                        edkInputVariables.hintFunctionMaximize |
                        edkInputVariables.hintFunctionResize;
            }
            if (design & EDK_WINDOW_BUTTONS){
                this->hints.decorations |= edkInputVariables.hintDecorationBorder |
                        edkInputVariables.hintDecorationTitle |
                        edkInputVariables.hintDecorationMenu |
                        edkInputVariables.hintDecorationMinimize;
                this->hints.functions |= edkInputVariables.hintFunctionClose |
                        edkInputVariables.hintFunctionMove |
                        edkInputVariables.hintFunctionMinimize;
            }
        }

        //load the fullscreen atom
        Atom wm_state   = XInternAtom (edkInputVariables.dis, "_NET_WM_STATE", false );
        Atom wm_fullscreen = XInternAtom (edkInputVariables.dis, "_NET_WM_STATE_FULLSCREEN", false );
        if(design & EDK_WINDOW_FULLSCREEN){
            //if(!(this->saveDesign & EDK_WINDOW_FULLSCREEN)){
            //ADD THE FULLSCREEN
            XChangeProperty(edkInputVariables.dis, this->window, wm_state, XA_ATOM, 32,
                            PropModeReplace, (edk::uchar8 *)&wm_fullscreen, 1);
            this->hints.decorations = 0u;
            this->hints.functions   = 0u;
            //}
        }
        else{
            //if(this->saveDesign & EDK_WINDOW_FULLSCREEN){
            //REMOVE THE FULLSCREEN
            XChangeProperty(edkInputVariables.dis, this->window, wm_state, XA_ATOM, 32,
                            PropModeReplace, (edk::uchar8 *)&wm_fullscreen, 0);
            //set the position and size
            this->updatePositionAndSize();
            //}
        }

        //change the decoration and functions
        Atom hintsAtom = XInternAtom(edkInputVariables.dis, "_MOTIF_WM_HINTS", false);
        if (hintsAtom){
            XChangeProperty(edkInputVariables.dis,
                            this->window,
                            hintsAtom,
                            hintsAtom,
                            32,
                            PropModeReplace,
                            (edk::uchar8*)(&this->hints),
                            3u);
        }


        XInternAtom(edkInputVariables.dis, "WM_DELETE_WINDOW", 0);
        Atom del_window = XInternAtom(edkInputVariables.dis, "WM_DELETE_WINDOW", 0);
        XSetWMProtocols(edkInputVariables.dis, this->window, &del_window, 1);





        edkInputVariables.mut.lock();
        XFlush(edkInputVariables.dis);
        edkInputVariables.mut.unlock();
    }
    //save the design
    this->saveDesign=design;
#endif
}

void edk::Window::mouseRender(bool show){
    //primeiro testa se possui uma window
    if(this->isOpened()){
#if defined(EDK_USE_SFML)
        //seta o mouse
        //this->window.ShowMouseCursor(show);//1.6
        this->window.setMouseCursorVisible(show);//2.0
#endif
#if defined(EDK_USE_X11)
#endif
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
#if defined(EDK_USE_SFML)
        //seta a posicao do mouse
        //this->window.SetCursorPosition(pos.x,pos.y);//1.6
        sf::Mouse::setPosition(sf::Vector2i(pos.x,pos.y), this->window);//2.0
        saveMousePos = pos;
#endif
#if defined(EDK_USE_X11)
        XWarpPointer(edkInputVariables.dis,None, this->window, 0, 0, 0, 0,pos.x,pos.y);
#endif
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

bool edk::Window::setMousePositionGlobal(edk::vec2i32 pos){
#if defined(EDK_USE_SFML)
#endif
#if defined(EDK_USE_X11)
    if(edkInputVariables.dis && edkInputVariables.rootw){
        XWarpPointer(edkInputVariables.dis,None, edkInputVariables.rootw, 0, 0, 0, 0,pos.x,pos.y);
        //retorna true
        return true;
    }
#endif
    return false;
}

bool edk::Window::setMousePositionGlobal(edk::int32 x, edk::int32 y){
    return edk::Window::setMousePositionGlobal(edk::vec2i32(x,y));
}

bool edk::Window::setWindowPosition(vec2i32 pos){
    //testa se a janela esta aberta
    if(this->isOpened()){
#if defined(EDK_USE_SFML)
        //seta a posicao do mouse
        //this->window.SetPosition(pos.x,pos.y);//1.6
        this->window.setPosition(sf::Vector2i(pos.x,pos.y));//2.0
#endif
#if defined(EDK_USE_X11)
        this->windowPosition = pos;
        this->updatePositionAndSize();
        //retorna true
        return true;
#endif
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
#if defined(EDK_USE_SFML)
        //seta a posicao do mouse
        //this->window.SetSize(size.width,size.height);//1.6
        this->window.setSize(sf::Vector2u(size.width,size.height));//2.0
#endif
#if defined(EDK_USE_X11)
        this->windowSize=size;
        this->updatePositionAndSize();
#endif
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
        this->events.mousePosView.x -= (edk::int32)view->animatedFrame.origin.x;
        this->events.mousePosView.y -= (edk::int32)view->animatedFrame.origin.y;
        //update the position in the screen
        view->positionInWindow=view->frame.origin+screenPosition;
        //update the animations on the view
        view->updateAnimations(this->events.secondPassed);
        if(view->canUpdateView()){
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
        }
        this->events.mousePosView.x += (edk::int32)view->animatedFrame.origin.x;
        this->events.mousePosView.y += (edk::int32)view->animatedFrame.origin.y;
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

#if defined(EDK_USE_SFML)
#endif
#if defined(EDK_USE_X11)
//create a new GC
bool edk::Window::newGC(){
    bool ret=false;
    if(edkInputVariables.dis){
        if(this->window){
            if(this->gc){
                XFreeGC(edkInputVariables.dis, this->gc);
                this->gc=0;
            }
            XGCValues values;
            edk::uint32 color = edk::BinaryConverter::joinBytesBigEndian((edk::uint8)0x00,(edk::uint8)0x00,(edk::uint8)0x00,(edk::uint8)0xFF);
            values.font = 0u;
            values.background = /*edk::Window::displayBlack*/color;
            values.foreground = color;
            this->gc = XCreateGC(edkInputVariables.dis, this->window,GCBackground | GCForeground, &values);
            if(this->gc){
                ret=true;
            }
        }
        edkInputVariables.mut.lock();
        XFlush(edkInputVariables.dis);
        edkInputVariables.mut.unlock();
    }
    return ret;
}
//set the window colors
void edk::Window::setColorForeground(edk::color4f32 color){
    edk::uint32 colorui32 = edk::BinaryConverter::joinBytesBigEndian((edk::uint8)(color.b*255u),
                                                                     (edk::uint8)(color.g*255u),
                                                                     (edk::uint8)(color.r*255u),
                                                                     (edk::uint8)(color.a*255u)
                                                                     );
    this->setColorForeground(colorui32);
}
void edk::Window::setColorForegroundF32(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    edk::uint32 colorui32 = edk::BinaryConverter::joinBytesBigEndian((edk::uint8)(b*255u),
                                                                     (edk::uint8)(g*255u),
                                                                     (edk::uint8)(r*255u),
                                                                     (edk::uint8)(a*255u)
                                                                     );
    this->setColorForeground(colorui32);
}
void edk::Window::setColorForegroundUI8(edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
    edk::uint32 colorui32 = edk::BinaryConverter::joinBytesBigEndian(b,g,r,a);
    this->setColorForeground(colorui32);
}
void edk::Window::setColorForeground(edk::uint32 color){
    if(edkInputVariables.dis){
        if(this->gc){
            XSetForeground(edkInputVariables.dis, this->gc, color);
        }
    }
}
void edk::Window::setColorBackground(edk::color4f32 color){
    edk::uint32 colorui32 = edk::BinaryConverter::joinBytesBigEndian((edk::uint8)(color.b*255u),
                                                                     (edk::uint8)(color.g*255u),
                                                                     (edk::uint8)(color.r*255u),
                                                                     (edk::uint8)(color.a*255u)
                                                                     );
    this->setColorBackground(colorui32);
}
void edk::Window::setColorBackgroundF32(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    edk::uint32 colorui32 = edk::BinaryConverter::joinBytesBigEndian((edk::uint8)(b*255u),
                                                                     (edk::uint8)(g*255u),
                                                                     (edk::uint8)(r*255u),
                                                                     (edk::uint8)(a*255u)
                                                                     );
    this->setColorBackground(colorui32);
}
void edk::Window::setColorBackgroundUI8(edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
    edk::uint32 colorui32 = edk::BinaryConverter::joinBytesBigEndian(b,g,r,a);
    this->setColorBackground(colorui32);
}
void edk::Window::setColorBackground(edk::uint32 color){
    if(edkInputVariables.dis){
        if(this->gc){
            XSetBackground(edkInputVariables.dis, this->gc, color);
        }
    }
}
//update the position and size
void edk::Window::updatePositionAndSize(){
    XMoveResizeWindow(edkInputVariables.dis,
                      this->window,
                      this->windowPosition.x,
                      this->windowPosition.y,
                      this->windowSize.width,
                      this->windowSize.height
                      );
}
//load the window attributes
void edk::Window::loadWindowAttributes(bool* resize, edk::size2i32* resizePosition
                                       ,bool* move, edk::vec2i32* movePosition
                                       ){
    if(this->window){
        edk::int32 x, y;
        XID child;
        XWindowAttributes xwa;
        XTranslateCoordinates( edkInputVariables.dis,
                               this->window,
                               edkInputVariables.rootw,
                               0,
                               0,
                               &x,
                               &y,
                               &child
                               );
        XGetWindowAttributes( edkInputVariables.dis, this->window, &xwa );
        //set window position and size
        if(this->windowPosition.x!=x - xwa.x
                ||
                this->windowPosition.y!=y - xwa.y
                ){
            if(move){
                if(*move){
                    *move=true;
                }
            }
            if(movePosition){
                *movePosition = edk::vec2i32((x - xwa.x) - (edk::int32)this->windowPosition.x,
                                             (y - xwa.y) - (edk::int32)this->windowPosition.y
                                             );
            }
        }
        this->windowPosition = edk::vec2i32(x - xwa.x,y - xwa.y);
        if(xwa.width<0)xwa.width*=-1;
        if(xwa.height<0)xwa.width*=-1;
        if(this->windowRealSize.width!=(edk::uint32)xwa.width
                ||
                this->windowRealSize.height!=(edk::uint32)xwa.height
                ){
            if(resize){
                *resize=true;
            }
            if(resizePosition){
                *resizePosition = edk::size2i32(xwa.width - (edk::int32)this->windowRealSize.width,
                                                xwa.height - (edk::int32)this->windowRealSize.height
                                                );
            }
        }
        this->windowRealSize = edk::size2ui32((edk::uint32)xwa.width,(edk::uint32)xwa.height);
    }
}
#endif

bool edk::Window::drawStart(){
    //Tetsa se finalizou o render antes e se a janela esta aberta
    if(!this->activeRender && this->isOpened()){
#if defined(EDK_USE_SFML)
        //pode setar o render
        //this->window.SetActive(true);//1.6
        this->window.setActive(true);//2.0
#endif
#if defined(EDK_USE_X11)
        //pode setar o render
        this->useOpenGLInWindow();
#endif
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
#if defined(EDK_USE_SFML)
        //pode setar o render
        //this->window.SetActive(false);//1.6
        this->window.setActive(false);//2.0
#endif
#if defined(EDK_USE_X11)
#endif
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

#if defined(EDK_USE_SFML)
#endif
#if defined(EDK_USE_X11)
    //clean the screen with the foreground color
    this->setColorBackground(this->cleanColor);
    this->setColorForeground(this->cleanColor);

    edk::GU::guClearColor3f32(this->cleanColor.r,
                              this->cleanColor.g,
                              this->cleanColor.b
                              );
    edk::GU::guClear(GU_COLOR_BUFFER_BIT);
#endif

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

    //if it's runnind the events with mouse then print a view with mouse position
#if defined(EDK_WINDOW_EVENTS_RW)
    //READ
    if(this->playingReadEvents && !this->pausedFileEvents){
        if(!this->viewWindow.haveSubview(&this->viewMouse)){
            this->addSubview(&this->viewMouse);
        }
        this->viewMouse.objMouse.position.x = this->events.mousePosWindow.x;
        this->viewMouse.objMouse.position.y = (this->events.mousePosWindow.y * -1.f) + this->viewMouse.camera.getSize().height;
    }
    else{
        if(this->viewWindow.haveSubview(&this->viewMouse)){
            this->removeSubview(&this->viewMouse);
        }
    }
#endif

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
#if defined(EDK_USE_SFML)
        //Pode renderizar na tela
        //this->window.Display();//1.6
        this->window.display();//2.0
#endif
#if defined(EDK_USE_X11)
        this->useOpenGLInWindow();
        edkInputVariables.mut.lock();

        //LINUX
        glXSwapBuffers(edkInputVariables.dis, this->window);
        //XFlush(edkInputVariables.dis);

        edkInputVariables.mut.unlock();
#endif
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
#if defined(EDK_USE_SFML)
        //retorna o tamanho da view
        //ret = edk::size2ui32(this->window.GetWidth(),this->window.GetHeight());//1.6
        ret = edk::size2ui32(this->window.getSize().x,this->window.getSize().y);//2.0
#endif
#if defined(EDK_USE_X11)
#endif
    }
    //senao retorna um tamanho zerado
    return ret;
}

edk::uint32 edk::Window::getWidth(){
    //
    if(this->isOpened()){
#if defined(EDK_USE_SFML)
        //
        //return this->window.GetWidth();//1.6
        return this->window.getSize().x;//2.0
#endif
#if defined(EDK_USE_X11)
#endif
    }
    //senao retorna 0u
    return 0u;
}

edk::uint32 edk::Window::getHeight(){
    //
    if(this->isOpened()){
#if defined(EDK_USE_SFML)
        //
        //return this->window.GetHeight();//1.6
        return this->window.getSize().y;//2.0
#endif
#if defined(EDK_USE_X11)
#endif
    }
    //senao retorna 0u
    return 0u;
}

edk::vec2i32 edk::Window::getPos(){
    //
    if(this->isOpened()){
#if defined(EDK_USE_SFML)
        //
        //return this->window.GetHeight();//1.6
        return edk::vec2i32(this->window.getPosition().x,this->window.getPosition().y);//2.0
#endif
#if defined(EDK_USE_X11)
#endif
    }
    //senao retorna 0u
    return edk::vec2i32(0u,0u);
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

edk::int8 edk::Window::getMouseScrollWheelVertical(){
    //
    return (int8)this->events.mouseScrollWheelVertical;
}
edk::int8 edk::Window::getMouseScrollWheelHorizontal(){
    //
    return (int8)this->events.mouseScrollWheelHorizontal;
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
    bool canAddHolded=true;
#if defined(EDK_USE_SFML)
    edk::uint32 mouseButtonValue=0u;
    //Eventos da janela
    sf::Event event;
    //Input da janela
    //const sf::Input& input=window.GetInput();//1.6
    //2.0
#endif
    bool ret=false;
    this->updateControllerEvents();
    //Limpa os eventos
    this->cleanEvents();

    //test if DON'T need force the second passed
    if(!this->events.updateForceSecondPassed()){
        //load the time passed since the last frame
        this->events.secondPassed = this->time.getMicroseconds() * edk::watch::microsecond;
        this->events.secondsGlobal = this->time.getMicrosecondsReal() * edk::watch::microsecond;
    }


    this->time.start();

#if defined(EDK_USE_SFML)
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
                //if(!this->saveKeyHolded.haveHolded(event.key.code+'a')){
                this->saveKeyHolded.addHolded(event.key.code+'a');
                //}
            }
            else if(event.key.code>=26&&event.key.code<36){
                this->events.keyPressed.pushBack(event.key.code+ '0' - 26) ;//2.0
                //if(!this->saveKeyHolded.haveHolded(event.key.code+ '0' - 26)){
                this->saveKeyHolded.addHolded(event.key.code+ '0' - 26);
                //}
            }
            else if(event.key.code>=75&&event.key.code<85){
                this->events.keyPressed.pushBack(event.key.code+ '0' - 75) ;//2.0
                //if(!this->saveKeyHolded.haveHolded(event.key.code+ '0' - 75)){
                this->saveKeyHolded.addHolded(event.key.code+ '0' - 75);
                //}
            }
            else{
                this->events.keyPressed.pushBack(event.key.code+256 - 36) ;//2.0
                //if(!this->saveKeyHolded.haveHolded(event.key.code+256 - 36)){
                this->saveKeyHolded.addHolded(event.key.code+256 - 36);
                //}
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
            //printf("\nKey Release %d",event.key.code);fflush(stdout);
            if(event.key.code>=0&&event.key.code<26){
                this->events.keyRelease.pushBack(event.key.code+'a') ;//2.0
                this->saveKeyHolded.removeHolded(event.key.code+'a');
            }
            else if(event.key.code>=26&&event.key.code<36){
                this->events.keyRelease.pushBack(event.key.code+ '0' - 26) ;//2.0
                this->saveKeyHolded.removeHolded(event.key.code+ '0' - 26);
            }
            else if(event.key.code>=75&&event.key.code<85){
                this->events.keyRelease.pushBack(event.key.code+ '0' - 75) ;//2.0
                this->saveKeyHolded.removeHolded(event.key.code+ '0' - 75);
            }
            else{
                this->events.keyRelease.pushBack(event.key.code+256 - 36) ;//2.0
                this->saveKeyHolded.removeHolded(event.key.code+256 - 36);
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
            if(!this->saveMouseHolded.haveHolded(event.mouseButton.button+1u)){
                this->saveMouseHolded.addHolded(event.mouseButton.button+1u);
                this->events.mousePressed.pushBack(event.mouseButton.button+1u);//2.0
                canAddHolded=false;
            }

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
            this->saveMouseHolded.removeHolded(mouseButtonValue);

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
            this->events.mousePosView = edk::vec2i32(mouseTemp.x,mouseTemp.y);
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
            this->events.mouseScrollWheelVertical=event.mouseWheel.delta;//2.0

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
#endif
#if defined(EDK_USE_X11)
#endif
    //load the window size
#if defined(EDK_USE_SFML)
    this->windowSize = edk::size2ui32(window.getSize().x,window.getSize().y);//2.0
#endif
#if defined(EDK_USE_X11)
#endif
    this->events.windowSize = this->windowSize;

    //load mousePosition
    //events.mousePosWindow = events.mousePos = edk::vec2i32( input.GetMouseX(),input.GetMouseY());//1.6
#if defined(EDK_USE_SFML)
    this->events.mousePosWindow = this->events.mousePosView = edk::vec2i32( sf::Mouse::getPosition(this->window).x,sf::Mouse::getPosition(this->window).y);//2.0
#endif
#if defined(EDK_USE_X11)
#endif
    this->saveMousePos.x = this->events.mousePosView.x;
    this->saveMousePos.y = this->events.mousePosView.y;
    this->events.mousePosWorld = edk::vec2i32( sf::Mouse::getPosition().x,sf::Mouse::getPosition().y);//2.0

#if defined(EDK_WINDOW_EVENTS_RW)
    //READ
    if(this->playingReadEvents && !this->pausedFileEvents){
        this->secondEvents+=this->events.secondPassed;
        //clean the mouse events
        this->cleanEventsMouse();
        //test if the secondEvents is bigger then the nextSecondEvent
        if(this->secondEvents >= this->nextSecondEvents){
            while(this->secondEvents > this->nextSecondEvents){
                //test if reach the end of the file
                if(this->fileEvents.endOfFile()){
                    //stop the read
                    this->stopReadEvents();
                    break;
                }
                else{
                    //else read the events
                    this->events.readFile(&this->fileEvents);
                    this->saveEvents.clean();
                    //test if reach the end of the file
                    if(this->fileEvents.endOfFile()){
                        //stop the read
                        this->stopReadEvents();
                        break;
                    }
                    else{
                        this->saveEvents.cloneFrom(&this->events);
                        //then read the nextSecondEvent
                        this->fileEvents.readBin(&this->nextSecondEvents,sizeof(this->nextSecondEvents));
                    }
                }
            }
        }
        else{
            edk::float32 secondPassed = this->events.secondPassed;
            edk::float32 secondsGlobal = this->events.secondsGlobal;
            this->events.cloneFromSaved(&this->saveEvents);
            this->events.secondPassed = secondPassed;
            this->events.secondsGlobal = secondsGlobal;
        }
    }
#endif

    //Seta o tamanho da janela
    this->updateViewSize();

    //save focus
    this->windowFocus = this->events.focus;

    //test if have focus
    if(this->windowFocus){
        edk::uint32 sizeHold = this->saveKeyHolded.getSize();
        edk::uint32 idHold=0u;
        for(edk::uint32 i=0u;i<sizeHold;i++){
            idHold = this->saveKeyHolded.getHoldedInPosition(i);
            switch(this->saveKeyHolded.getHoldedInPosition(i)){
            case edk::key::lShift:
            case edk::key::rShift:
            case edk::key::lAlt:
            case edk::key::rAlt:
            case edk::key::lControl:
            case edk::key::rControl:
            case edk::key::capsLock:
                this->saveKeyHolded.incrementHolded(idHold,1u);
                break;
            default:
                break;
            }
            this->events.keyHolded.pushBack(this->saveKeyHolded.getHoldedInPosition(i));
        }
        //load the holded mouse button
        for(edk::int32 i=sf::Mouse::Left ;i<sf::Mouse::ButtonCount;i=i+1){
            if(sf::Mouse::isButtonPressed((sf::Mouse::Button)i)){
                this->events.mouseHolded.pushBack(i+1u);
                if(!this->saveMouseHolded.haveHolded(i+1u)
                        ){
                    this->events.mousePressed.pushBack(i+1u);
                }
                if(canAddHolded){
                    this->saveMouseHolded.addHolded(i+1u);
                }
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

    //this->printEvents();

#if defined(EDK_WINDOW_EVENTS_RW)
    //WRITEprintEvents
    //test if are writing or reading some events file
    if(this->playingWriteEvents && !this->pausedFileEvents){
        this->secondEvents+=this->events.secondPassed;
        //test if have some eventType on the tree
        if(this->treeEventTypes.size()){
            //test if have something in the events
            if(this->events.haveSomethingTypesTree(&this->treeEventTypes)){
                //write the secondEvents
                this->fileEvents.writeBin(this->secondEvents);this->fileEvents.flush();
                //write the events
                this->events.writeFileTypesTree(&this->fileEvents,&this->treeEventTypes);
                this->saveHaveEvents=true;
            }
            else if(this->saveHaveEvents){
                //write the events to remove all used events
                this->fileEvents.writeBin(this->secondEvents);this->fileEvents.flush();
                //write the events
                this->events.writeFileTypesTree(&this->fileEvents,&this->treeEventTypes);
                this->saveHaveEvents=false;
            }
        }
        else{
            //test if have something in the events
            if(this->events.haveSomething()){
                //write the secondEvents
                this->fileEvents.writeBin(this->secondEvents);this->fileEvents.flush();
                //write the events
                this->events.writeFile(&this->fileEvents);
                this->saveHaveEvents=true;
            }
            else if(this->saveHaveEvents){
                //write the events to remove all used events
                this->fileEvents.writeBin(this->secondEvents);this->fileEvents.flush();
                //write the events
                this->events.writeFile(&this->fileEvents);
                this->saveHaveEvents=false;
            }
        }
    }
#endif

    this->saveMouseHolded.updateWithPointer();
    this->saveKeyHolded.updateWithPointer();

    //senao retorna false
    return ret;
}

edk::size2ui32 edk::Window::getDesktopSize(){
#if defined(EDK_USE_SFML)
    //Carrega o modo do desktop
    //sf::VideoMode DesktopMode = sf::VideoMode::GetDesktopMode();//1.6
    sf::VideoMode DesktopMode = sf::VideoMode::getDesktopMode();//2.0
    //seta o retorno
    //edk::size2ui32 temp(DesktopMode.Width,DesktopMode.Height);//1.6
    edk::size2ui32 temp(DesktopMode.width,DesktopMode.height);//2.0
#endif
#if defined(EDK_USE_X11)
    edk::size2ui32 temp;
#endif
    //carrega o desktop mode
    return temp;
}

edk::uint32 edk::Window::getDesktopBitsPerPixel(){
#if defined(EDK_USE_SFML)
    //Carrega o modo do desktop
    //sf::VideoMode DesktopMode = sf::VideoMode::GetDesktopMode();//1.6
    sf::VideoMode DesktopMode = sf::VideoMode::getDesktopMode();//2.0
    //retorna os bits
    //return DesktopMode.BitsPerPixel;//1.6
    return DesktopMode.bitsPerPixel;//2.0
#endif
#if defined(EDK_USE_X11)
#endif
    return 0u;
}

//get the size of connected controllers
edk::uint32 edk::Window::getControllersSize(){
    edk::uint32 ret=0u;
#if defined(EDK_USE_SFML)
#endif
#if defined(EDK_USE_X11)
    edkInputVariables.mut.lock();
    //LINUX
    ret = edkInputVariables.controllers.getControllersSize();
    edkInputVariables.mut.unlock();
#endif
    return ret;
}
//get the size of connected controllers
edk::uint32 edk::Window::getControllerIdInPosition(edk::uint32 position){
    edk::uint32 ret=0u;
#if defined(EDK_USE_SFML)
#endif
#if defined(EDK_USE_X11)
    edkInputVariables.mut.lock();
    //LINUX
    ret = edkInputVariables.controllers.getControllerIDInPosition(position);
    edkInputVariables.mut.unlock();
#endif
    return ret;
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
