#include "ViewTextField.h"

/*
Library C++ ViewTextField - Entry text
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
#pragma message "            Inside ViewTextField.cpp"
#endif

edk::vector::BinaryTree<edk::ViewTextField::TextField*> edk::ViewTextField::TextField::treeSelected;

edk::ViewTextField::ViewTextField(){
    this->classThis=NULL;
    this->Constructor();
}
edk::ViewTextField::~ViewTextField(){
    this->Destructor();
}

void edk::ViewTextField::Constructor(){
    edk::ViewMenu::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->text.Constructor();

        this->borderSize = 7;
    }
}
void edk::ViewTextField::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class

        this->text.Destructor();
    }
    edk::ViewMenu::Destructor();
}

edk::ViewTextField::TextField::TextField(){
    this->classThis=NULL;
    this->Constructor();
}
edk::ViewTextField::TextField::~TextField(){
    this->Destructor();
}

void edk::ViewTextField::TextField::Constructor(){
    edk::ViewText::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->obj.Constructor();
        this->anim.Constructor();

        this->saveBorder = 0u;
        this->selectView = false;
        this->pressInside=false;
        this->string=NULL;
        this->sizeString = 0u;
        this->deleteString();
        this->pressReturn=false;
        this->pressQuote = false;
        this->pressTilde = false;
    }
}
void edk::ViewTextField::TextField::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->cleanString();
        this->deleteString();
        edk::ViewTextField::TextField::treeSelected.remove(this);

        this->obj.Destructor();
        this->anim.Destructor();
    }
    edk::ViewText::Destructor();
}

//Set the entryPosition
bool edk::ViewTextField::TextField::setEntryPosition(edk::float32 x){
    //convert the X and Y to the camera
    edk::rectf32 cameraRect = this->camera.getRectPositionAndSize();
    edk::float32 worldPositionX = cameraRect.origin.x + ((x/this->frame.size.width) * cameraRect.size.width)
            -((this->borderSize/this->frame.size.width)* cameraRect.size.width);

    if(worldPositionX<0.f){
        worldPositionX=0.f;
    }
    //convert the position to int
    this->writePosition = (edk::uint32)(worldPositionX + 0.5f);

    this->setWritePosition(this->writePosition);
    return false;
}

void edk::ViewTextField::TextField::eventMousePressed(edk::vec2f32 point ,edk::uint32 button){
    if(button == edk::mouse::left){
        //
        this->selectView=true;
        edk::ViewTextField::TextField::treeSelected.add(this);
        this->pressInside=true;

        //set the entry position
        this->setEntryPosition(point.x);
        this->anim.loopOn();
        this->anim.setAnimationEndSecond(1);
        this->anim.playForward();
    }
}
void edk::ViewTextField::TextField::eventMouseMoved(edk::vec2f32 point,edk::vec2f32 /*moved*/,edk::uint32 button){
    if(button == edk::mouse::left){
        //set the entry position
        this->setEntryPosition(point.x);
    }
}
void edk::ViewTextField::TextField::eventMouseReleased(edk::vec2f32,edk::uint32){
    //
}
void edk::ViewTextField::TextField::eventMouseDoubleClicked(edk::vec2f32,edk::uint32){
    //
}

void edk::ViewTextField::TextField::load(rectf32 outsideViewOrigin){
    this->saveOutsideView.size = outsideViewOrigin.size;
    edk::shape::Mesh2D *mesh = this->obj.newMesh();
    if(mesh){
        edk::shape::Rectangle2D rect;
        rect.setScale(0.1f,0.9f);
        rect.setTranslate(0.f,0.05f);
        mesh->addPolygon(rect);
    }
    this->obj.setPolygonsColor(0,0,0,1);


    //add one animation to the object
    this->anim.addNewInterpolationLine(0,1);
    this->anim.addNewInterpolationLine(0.49,1);
    this->anim.addNewInterpolationLine(0.5,0);
    this->anim.addNewInterpolationLine(0.99,0);
    this->anim.addNewInterpolationLine(1,1);

    this->anim.loopOn();
    this->anim.setAnimationEndSecond(1);
    this->anim.playForward();
}
void edk::ViewTextField::TextField::unload(){
    //
    this->obj.cleanMeshes();
    this->anim.cleanAnimations();
}
void edk::ViewTextField::TextField::update(edk::WindowEvents* events){
    //update animation
    this->anim.updateClockAnimation();
    this->obj.setPolygonsColor(0,0,0,this->anim.getClockX());

    //test if is playing
    if(!this->anim.isPlaying()){
        //then play with loop
        this->anim.setAnimationEndSecond(1);
        this->anim.loopOn();
        this->anim.playForward();
    }

    //test if mouse is pressed
    edk::uint32 size = events->mousePressed.size();
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            if(events->mousePressed.get(i) == edk::mouse::left){
                if(!this->pressInside){
                    //remove selection
                    this->selectView = false;
                    edk::ViewTextField::TextField::treeSelected.remove(this);
                }
            }
        }
    }
    this->pressInside=false;


    //test if the view is selected
    if(this->selectView){
        size = events->keyHolded.size();
        bool shift=false;
        //test if is holding the shift
        for(edk::uint32 i=0u;i<size;i++){
            switch(events->keyHolded.get(i)){
            case edk::key::lShift:
            case edk::key::rShift:
                shift=true;
                break;
            }
        }
        //test the keyboard
        size = events->keyPressed.size();
        edk::uint32 keyPressed;
        for(edk::uint32 i=0u;i<size;i++){
            //load the keyPressed
            keyPressed = events->keyPressed.get(i);
            /*
            printf("\nKey Pressed %u"
                   ,keyPressed
                   );
*/
            switch(keyPressed){
            case edk::key::left:
                //back the writer position
                if(this->writePosition){
                    this->setWritePosition(this->writePosition-1u);
                }
                break;
            case edk::key::right:
                //foward the writer position
                this->setWritePosition(this->writePosition+1u);
                break;
            case edk::key::home:
                //
                this->setWritePosition(0u);
                break;
            case edk::key::end:
                //
                this->setWritePosition(this->sizeString);
                break;
            case edk::key::space:
                //
                //accent
                if(this->pressTilde){
                    this->addCharacter('~');
                    this->pressTilde=false;
                }
                else if(this->pressQuote){
                    this->addCharacterFromString("´");
                    this->pressQuote=false;
                }
                else{
                    this->addCharacter(' ');
                }
                break;
            case edk::key::comma:
                //
                this->addCharacter(',');
                break;
            case edk::key::semiColon:
                //
                this->addCharacter(';');
                break;
            case edk::key::period:
                //
                this->addCharacter('.');
                break;
            case edk::key::quote:
                //accent
                if(this->pressQuote){
                    this->addCharacterFromString("´");
                    this->pressQuote=false;
                }
                else if(this->pressTilde){
                    this->addCharacter('~');
                    this->pressTilde=false;
                }
                else{
                    this->pressQuote=true;
                }
                break;
            case edk::key::tilde:
                //accent
                if(this->pressTilde){
                    this->addCharacter('~');
                    this->pressTilde=false;
                }
                else if(this->pressQuote){
                    this->addCharacterFromString("´");
                    this->pressQuote=false;
                }
                else{
                    this->pressTilde=true;
                }
                break;
            case edk::key::slash:
                //accent
                this->addCharacter('/');
                break;
            case edk::key::backSlash:
                //accent
                this->addCharacter('\\');
                break;
            case edk::key::equal:
                //accent
                this->addCharacter('=');
                break;
            case edk::key::dash:
                //accent
                this->addCharacter('-');
                break;
            case edk::key::tab:
                //accent
                this->addCharacter(' ');
                this->addCharacter(' ');
                this->addCharacter(' ');
                break;
            case edk::key::add:
                //accent
                this->addCharacter('+');
                break;
            case edk::key::subtract:
                //accent
                this->addCharacter('-');
                break;
            case edk::key::multiply:
                //accent
                this->addCharacter('*');
                break;
            case edk::key::divide:
                //accent
                this->addCharacter(247);
                break;
            case edk::key::backSpace:
                //remove the character
                if(this->pressQuote){
                    this->pressQuote=false;
                }
                else if(this->pressTilde){
                    this->pressTilde=false;
                }
                else{
                    this->removeCharacter();
                }
                break;
            case edk::key::Delete:
                //delete the character
                this->deleteCharacter();
                break;
            case edk::key::Return:
                //set press return
                this->pressReturn = true;
                break;
            case edk::key::escape:
                //
                this->selectView=false;
                edk::ViewTextField::TextField::treeSelected.remove(this);
                break;
            default:
                //test if the key is a letter
                if(keyPressed>=edk::key::A
                        &&
                        keyPressed<=edk::key::Z
                        ){
                    //add the character
                    if(shift){
                        if(this->pressQuote){
                            this->pressQuote=false;
                            switch(keyPressed){
                            case 'a':
                                this->addCharacterFromString("Á");
                                break;
                            case 'e':
                                this->addCharacterFromString("É");
                                break;
                            case 'i':
                                this->addCharacterFromString("Í");
                                break;
                            case 'o':
                                this->addCharacterFromString("Ó");
                                break;
                            case 'u':
                                this->addCharacterFromString("Ú");
                                break;
                            default:
                                this->addCharacterFromString("´");
                                this->addCharacter(keyPressed + ('A' - 'a'));
                            }
                        }
                        else if(this->pressTilde){
                            this->pressTilde=false;
                            switch(keyPressed){
                            case 'a':
                                this->addCharacterFromString("Ã");
                                break;
                            case 'e':
                                this->addCharacterFromString("Ẽ");
                                break;
                            case 'i':
                                this->addCharacterFromString("Ĩ");
                                break;
                            case 'o':
                                this->addCharacterFromString("Õ");
                                break;
                            case 'u':
                                this->addCharacterFromString("Ũ");
                                break;
                            default:
                                this->addCharacter('~');
                                this->addCharacter(keyPressed + ('A' - 'a'));
                            }
                        }
                        else{
                            this->addCharacter(keyPressed + ('A' - 'a'));
                        }
                    }
                    else{
                        if(this->pressQuote){
                            this->pressQuote=false;
                            switch(keyPressed){
                            case 'a':
                                this->addCharacterFromString("á");
                                break;
                            case 'e':
                                this->addCharacterFromString("é");
                                break;
                            case 'i':
                                this->addCharacterFromString("í");
                                break;
                            case 'o':
                                this->addCharacterFromString("ó");
                                break;
                            case 'u':
                                this->addCharacterFromString("ú");
                                break;
                            default:
                                this->addCharacterFromString("´");
                                this->addCharacter(keyPressed);
                            }
                        }
                        else if(this->pressQuote){
                            this->pressQuote=false;
                            switch(keyPressed){
                            case 'a':
                                this->addCharacterFromString("ã");
                                break;
                            case 'e':
                                this->addCharacterFromString("ẽ");
                                break;
                            case 'i':
                                this->addCharacterFromString("ĩ");
                                break;
                            case 'o':
                                this->addCharacterFromString("õ");
                                break;
                            case 'u':
                                this->addCharacterFromString("ũ");
                                break;
                            default:
                                this->addCharacter('~');
                                this->addCharacter(keyPressed);
                            }
                        }
                        else{
                            this->addCharacter(keyPressed);
                        }
                    }
                }
                //test if the key is a number
                if(keyPressed>=edk::key::num0
                        &&
                        keyPressed<=edk::key::num9
                        ){
                    //add the character
                    this->addCharacter(keyPressed);
                }
            }
        }
    }
}
void edk::ViewTextField::TextField::update(edk::WindowEvents* events,edk::float32 seconds){

    //update animation
    this->anim.updateClockAnimation(seconds);
    this->obj.setPolygonsColor(0,0,0,this->anim.getClockX());

    //test if is playing
    if(!this->anim.isPlaying()){
        //then play with loop
        this->anim.setAnimationEndSecond(1);
        this->anim.loopOn();
        this->anim.playForward();
    }

    //test if mouse is pressed
    edk::uint32 size = events->mousePressed.size();
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            if(events->mousePressed.get(i) == edk::mouse::left){
                if(!this->pressInside){
                    //remove selection
                    this->selectView = false;
                    edk::ViewTextField::TextField::treeSelected.remove(this);
                }
            }
        }
    }
    this->pressInside=false;


    //test if the view is selected
    if(this->selectView){
        size = events->keyHolded.size();
        bool shift=false;
        //test if is holding the shift
        for(edk::uint32 i=0u;i<size;i++){
            switch(events->keyHolded.get(i)){
            case edk::key::lShift:
            case edk::key::rShift:
                shift=true;
                break;
            }
        }
        //test the keyboard
        size = events->keyPressed.size();
        edk::uint32 keyPressed;
        for(edk::uint32 i=0u;i<size;i++){
            //load the keyPressed
            keyPressed = events->keyPressed.get(i);
            /*
            printf("\nKey Pressed %u"
                   ,keyPressed
                   );
*/
            switch(keyPressed){
            case edk::key::left:
                //back the writer position
                if(this->writePosition){
                    this->setWritePosition(this->writePosition-1u);
                }
                break;
            case edk::key::right:
                //foward the writer position
                this->setWritePosition(this->writePosition+1u);
                break;
            case edk::key::home:
                //
                this->setWritePosition(0u);
                break;
            case edk::key::end:
                //
                this->setWritePosition(this->sizeString);
                break;
            case edk::key::space:
                //
                //accent
                if(this->pressTilde){
                    this->addCharacter('~');
                    this->pressTilde=false;
                }
                else if(this->pressQuote){
                    this->addCharacterFromString("´");
                    this->pressQuote=false;
                }
                else{
                    this->addCharacter(' ');
                }
                break;
            case edk::key::comma:
                //
                this->addCharacter(',');
                break;
            case edk::key::semiColon:
                //
                this->addCharacter(';');
                break;
            case edk::key::period:
                //
                this->addCharacter('.');
                break;
            case edk::key::quote:
                //accent
                if(this->pressQuote){
                    this->addCharacterFromString("´");
                    this->pressQuote=false;
                }
                else if(this->pressTilde){
                    this->addCharacter('~');
                    this->pressTilde=false;
                }
                else{
                    this->pressQuote=true;
                }
                break;
            case edk::key::tilde:
                //accent
                if(this->pressTilde){
                    this->addCharacter('~');
                    this->pressTilde=false;
                }
                else if(this->pressQuote){
                    this->addCharacterFromString("´");
                    this->pressQuote=false;
                }
                else{
                    this->pressTilde=true;
                }
                break;
            case edk::key::slash:
                //accent
                this->addCharacter('/');
                break;
            case edk::key::backSlash:
                //accent
                this->addCharacter('\\');
                break;
            case edk::key::equal:
                //accent
                this->addCharacter('=');
                break;
            case edk::key::dash:
                //accent
                this->addCharacter('-');
                break;
            case edk::key::tab:
                //accent
                this->addCharacter(' ');
                this->addCharacter(' ');
                this->addCharacter(' ');
                break;
            case edk::key::add:
                //accent
                this->addCharacter('+');
                break;
            case edk::key::subtract:
                //accent
                this->addCharacter('-');
                break;
            case edk::key::multiply:
                //accent
                this->addCharacter('*');
                break;
            case edk::key::divide:
                //accent
                this->addCharacter(247);
                break;
            case edk::key::backSpace:
                //remove the character
                if(this->pressQuote){
                    this->pressQuote=false;
                }
                else if(this->pressTilde){
                    this->pressTilde=false;
                }
                else{
                    this->removeCharacter();
                }
                break;
            case edk::key::Delete:
                //delete the character
                this->deleteCharacter();
                break;
            case edk::key::Return:
                //set press return
                this->pressReturn = true;
                break;
            case edk::key::escape:
                //
                this->selectView=false;
                edk::ViewTextField::TextField::treeSelected.remove(this);
                break;
            default:
                //test if the key is a letter
                if(keyPressed>=edk::key::A
                        &&
                        keyPressed<=edk::key::Z
                        ){
                    //add the character
                    if(shift){
                        if(this->pressQuote){
                            this->pressQuote=false;
                            switch(keyPressed){
                            case 'a':
                                this->addCharacterFromString("Á");
                                break;
                            case 'e':
                                this->addCharacterFromString("É");
                                break;
                            case 'i':
                                this->addCharacterFromString("Í");
                                break;
                            case 'o':
                                this->addCharacterFromString("Ó");
                                break;
                            case 'u':
                                this->addCharacterFromString("Ú");
                                break;
                            default:
                                this->addCharacterFromString("´");
                                this->addCharacter(keyPressed + ('A' - 'a'));
                            }
                        }
                        else if(this->pressTilde){
                            this->pressTilde=false;
                            switch(keyPressed){
                            case 'a':
                                this->addCharacterFromString("Ã");
                                break;
                            case 'e':
                                this->addCharacterFromString("Ẽ");
                                break;
                            case 'i':
                                this->addCharacterFromString("Ĩ");
                                break;
                            case 'o':
                                this->addCharacterFromString("Õ");
                                break;
                            case 'u':
                                this->addCharacterFromString("Ũ");
                                break;
                            default:
                                this->addCharacter('~');
                                this->addCharacter(keyPressed + ('A' - 'a'));
                            }
                        }
                        else{
                            this->addCharacter(keyPressed + ('A' - 'a'));
                        }
                    }
                    else{
                        if(this->pressQuote){
                            this->pressQuote=false;
                            switch(keyPressed){
                            case 'a':
                                this->addCharacterFromString("á");
                                break;
                            case 'e':
                                this->addCharacterFromString("é");
                                break;
                            case 'i':
                                this->addCharacterFromString("í");
                                break;
                            case 'o':
                                this->addCharacterFromString("ó");
                                break;
                            case 'u':
                                this->addCharacterFromString("ú");
                                break;
                            default:
                                this->addCharacterFromString("´");
                                this->addCharacter(keyPressed);
                            }
                        }
                        else if(this->pressQuote){
                            this->pressQuote=false;
                            switch(keyPressed){
                            case 'a':
                                this->addCharacterFromString("ã");
                                break;
                            case 'e':
                                this->addCharacterFromString("ẽ");
                                break;
                            case 'i':
                                this->addCharacterFromString("ĩ");
                                break;
                            case 'o':
                                this->addCharacterFromString("õ");
                                break;
                            case 'u':
                                this->addCharacterFromString("ũ");
                                break;
                            default:
                                this->addCharacter('~');
                                this->addCharacter(keyPressed);
                            }
                        }
                        else{
                            this->addCharacter(keyPressed);
                        }
                    }
                }
                //test if the key is a number
                if(keyPressed>=edk::key::num0
                        &&
                        keyPressed<=edk::key::num9
                        ){
                    //add the character
                    this->addCharacter(keyPressed);
                }
            }
        }
    }
}
//draw the GU scene
void edk::ViewTextField::TextField::drawScene(rectf32 outsideViewOrigin){
    this->saveOutsideView.size = outsideViewOrigin.size;
    if(this->saveRect.size!=outsideViewOrigin.size
            ||
            this->saveBorder!=this->borderSize){
        this->saveBorder = this->borderSize;
        this->frame.size = outsideViewOrigin.size - (this->saveBorder);
        this->saveRect.size = this->frame.size;
    }
    edk::ViewText::drawScene(outsideViewOrigin);

    if(this->selectView){
        this->obj.drawWithoutMaterial();
    }
}

//test if a point is inside the view
bool edk::ViewTextField::TextField::pointInside(edk::vec2f32 point){
    //create a tempRectangleShape
    edk::shape::Rectangle2D temp;
    temp.setVertexPosition(0u,this->saveOutsideView.origin);
    temp.setVertexPosition(1u,this->saveOutsideView.origin.x + this->saveOutsideView.size.width+this->saveBorder,this->saveOutsideView.origin.y + this->saveOutsideView.size.height+this->saveBorder);
    //test the contact
    return edk::collision::RectangleContact::contactPoint(point,temp);
}

//set writePosition
void edk::ViewTextField::TextField::setWritePosition(edk::uint32 position){
    if(position>this->sizeString){
        position=this->sizeString;
    }
    this->writePosition = position;
    this->obj.position.x = position;

    this->anim.loopOff();
    this->anim.setAnimationEndSecond(0.49f);
    this->anim.playForward();

    edk::rectf32 camRect = this->camera.getRectPoints();
    if(this->writePosition<camRect.origin.x){
        edk::float32 move = camRect.origin.x-(edk::float32)this->writePosition;
        camRect.size.width -= move;
        camRect.origin.x -= move;
        camRect.size.width-=camRect.origin.x;
        camRect.size.height-=camRect.origin.y;
        this->camera.setRectPoints(camRect);
    }
    else if(this->writePosition>camRect.size.width){
        edk::float32 move = (edk::float32)this->writePosition-camRect.size.width;
        camRect.origin.x += move;
        camRect.size.width += move;
        camRect.size.width-=camRect.origin.x;
        camRect.size.height-=camRect.origin.y;
        this->camera.setRectPoints(camRect);
    }
}
//delete the string
void edk::ViewTextField::TextField::deleteString(){
    if(this->string){
        free(this->string);
    }
    this->string = NULL;
    this->sizeString = 0u;
    this->setWritePosition(0u);
}
//copy the string
bool edk::ViewTextField::TextField::setString(edk::char8* string){
    this->deleteString();
    if(string){
        this->string = edk::String::strCopyFilterAccent(string);
        if(this->string){
            //create the map
            if(this->createString(string)){
                this->sizeString = edk::String::strSize(this->string);
                /*
                if(this->sizeString==1u){
                    //test if the character is space
                    if(this->string[0u] == ' '){
                        this->sizeString=0u;
                    }
                }
                */
                return true;
            }
        }
        this->deleteString();
    }

    this->cleanString();
    return false;
}
//add a characted
bool edk::ViewTextField::TextField::addCharacter(edk::char8 c){
    bool ret=false;
    if(c){
        //create a string with the character
        edk::char8* temp = (edk::char8*)malloc(sizeof(edk::char8) * (2u));
        if(temp){
            temp[0u] = c;
            temp[1u] = '\0';
            //test if have a string
            if(this->string){
                edk::char8* strSet;
                if(this->writePosition>this->sizeString){
                    this->sizeString = this->writePosition;
                }
                //test if the writer and the size are equal
                if(this->sizeString == this->writePosition){
                    //then add the character to the end of the string
                    strSet = edk::String::strCat(this->string,temp);
                    if(strSet){
                        //delete this string
                        free(this->string);
                        this->string = strSet;
                        this->sizeString = edk::String::strSize(this->string);
                        this->setWritePosition(this->writePosition+1u);
                        ret=true;
                    }
                }
                //test if the writerPosition is the first
                else if(!this->writePosition){
                    //then add to the start
                    strSet = edk::String::strCat(temp,this->string);
                    if(strSet){
                        //delete this string
                        free(this->string);
                        this->string = strSet;
                        this->sizeString = edk::String::strSize(this->string);
                        this->setWritePosition(this->writePosition+1u);
                        ret=true;
                    }
                }
                else{
                    //else coy the characters manualy
                    strSet = (edk::char8*)malloc(sizeof(edk::char8) * (this->sizeString+2u));
                    if(strSet){
                        //add the end
                        strSet[this->sizeString+1u] = '\0';
                        //copy the first characters
                        memcpy(strSet,this->string,this->writePosition);
                        //set the character
                        strSet[this->writePosition] = temp[0u];
                        //copy the last characters
                        memcpy(&strSet[this->writePosition+1u],&this->string[this->writePosition],this->sizeString-this->writePosition);
                        //delete the string
                        free(this->string);
                        //set the string
                        this->string = strSet;
                        this->sizeString = edk::String::strSize(this->string);
                        this->setWritePosition(this->writePosition+1u);
                        ret=true;
                    }
                }

                free(temp);
            }
            else{
                //else the string receive the character
                this->string = temp;
                this->sizeString = edk::String::strSize(this->string);
                this->setWritePosition(this->writePosition+1u);
                ret=true;
            }
        }
    }
    if(ret){
        this->createString(this->string);
    }
    return ret;
}
bool edk::ViewTextField::TextField::addCharacterFromString(const edk::char8* str){
    return this->addCharacterFromString((edk::char8*) str);
}
bool edk::ViewTextField::TextField::addCharacterFromString(edk::char8* str){
    //filter the first character
    return this->addCharacter(edk::String::filterAccent(str));
}
//remove the caracter
bool edk::ViewTextField::TextField::removeCharacter(){
    bool ret=false;
    //test if have the string
    if(this->string){
        edk::char8* strSet;
        if(this->writePosition>this->sizeString){
            this->sizeString = this->writePosition;
        }

        if(this->sizeString==1u && this->writePosition==1u){
            //just delete the string
            this->deleteString();
            this->cleanString();
            return true;
        }
        //else test if remove the first characters
        else if(this->writePosition==1u){
            strSet = edk::String::strCopy(&this->string[1u]);
            if(strSet){
                //delete this string
                free(this->string);
                this->string = strSet;
                this->sizeString = edk::String::strSize(this->string);
                this->setWritePosition(this->writePosition-1u);
                ret=true;
            }
        }
        //else test if remove the characters inside
        else if(this->writePosition){
            //create the new string
            strSet = (edk::char8*)malloc(sizeof(edk::char8) * (this->sizeString));
            if(strSet){
                this->setWritePosition(this->writePosition-1u);
                //add the end
                strSet[this->sizeString-1u] = '\0';
                //copy the first characters
                memcpy(strSet,this->string,this->writePosition);
                //copy the last characters
                memcpy(&strSet[this->writePosition],&this->string[this->writePosition+1u],this->sizeString-this->writePosition-1u);
                //delete the string
                free(this->string);
                //set the string
                this->string = strSet;
                this->sizeString = edk::String::strSize(this->string);
                ret=true;
            }
        }
    }
    if(ret){
        this->createString(this->string);
    }
    return ret;
}
//delete the character
bool edk::ViewTextField::TextField::deleteCharacter(){
    bool ret=false;
    //test if have the string
    if(this->string){
        edk::char8* strSet;
        if(this->writePosition>this->sizeString){
            this->sizeString = this->writePosition;
        }
        //test if remove the last character

        if(this->sizeString==1u && this->writePosition==0u){
            //just delete the string
            this->deleteString();
            this->cleanString();
            return true;
        }
        else if(!this->writePosition){
            strSet = (edk::char8*)malloc(sizeof(edk::char8) * (this->sizeString));
            if(strSet){
                //add the end
                strSet[this->sizeString-1u] = '\0';
                //set the memory
                memcpy(strSet,&this->string[1u],this->sizeString-1u);
                //delete this string
                free(this->string);
                this->string = strSet;
                this->sizeString = edk::String::strSize(this->string);
                this->setWritePosition(this->writePosition);
                ret=true;
            }
        }
        //else test if remove the characters inside
        else if(this->writePosition<this->sizeString){
            //create the new string
            strSet = (edk::char8*)malloc(sizeof(edk::char8) * (this->sizeString));
            if(strSet){
                //add the end
                strSet[this->sizeString-1u] = '\0';
                //copy the first characters
                memcpy(strSet,this->string,this->writePosition);
                //copy the last characters
                memcpy(&strSet[this->writePosition],&this->string[this->writePosition+1u],this->sizeString-this->writePosition-1u);
                //delete the string
                free(this->string);
                //set the string
                this->string = strSet;
                this->sizeString = edk::String::strSize(this->string);

                this->setWritePosition(this->writePosition);
                ret=true;
            }
        }
    }
    if(ret){
        this->createString(this->string);
    }
    return ret;
}
//return the string
edk::char8* edk::ViewTextField::TextField::getString(){
    return this->string;
}
edk::uint32 edk::ViewTextField::TextField::getSizeString(){
    return this->sizeString;
}
//eturn true if the text is selected
bool edk::ViewTextField::TextField::isSelected(){
    return this->selectView;
}
bool edk::ViewTextField::TextField::isSomeoneSelected(){
    if (edk::ViewTextField::TextField::treeSelected.size()){
        return true;
    }
    return false;
}

void edk::ViewTextField::load(rectf32){
    this->addSubview(&this->text);
    this->text.backgroundColor = edk::color4f32(1,1,1,0);
}
void edk::ViewTextField::unload(){
    this->removeSubview(&this->text);
}
void edk::ViewTextField::update(edk::WindowEvents*){
    if(this->saveRect!=this->frame){
        this->saveRect = this->frame;
        //this->text.frame.size = this->saveRect.size - (this->borderTemp*2);
    }
    this->text.borderSize = this->borderTemp;
}

//create a string
bool edk::ViewTextField::createString(const edk::char8* string){
    return this->createString((edk::char8*) string);
}
bool edk::ViewTextField::createString(edk::char8* string){
    return this->text.setString(string);
}
//get the string
edk::char8* edk::ViewTextField::getString(){
    return this->text.getString();
}
//return the size of the string
edk::uint32 edk::ViewTextField::getStringSize(){
    return this->text.getSizeString();
}
//clean the string
void edk::ViewTextField::cleanString(){
    this->text.deleteString();
    this->text.cleanString();
}

//add a character
bool edk::ViewTextField::addCharacter(edk::char8 c){
    return this->text.addCharacter(c);
}
//remove the caracter
bool edk::ViewTextField::removeCharacter(){
    return this->text.removeCharacter();
}
//delete the character
bool edk::ViewTextField::deleteCharacter(){
    return this->text.deleteCharacter();
}
//test if press enter
bool edk::ViewTextField::havePressReturn(){
    if(this->text.pressReturn){
        this->text.pressReturn=false;
        return true;
    }
    return false;
}
//Set the writer position
void edk::ViewTextField::setWritePosition(edk::uint32 position){
    this->text.setWritePosition(position);
}
//return true if is selected
bool edk::ViewTextField::isSelected(){
    return this->text.isSelected();
}
bool edk::ViewTextField::isSomeoneSelected(){
    return edk::ViewTextField::TextField::isSomeoneSelected();
}
//test if the mouse is inside
bool edk::ViewTextField::isMouseInside(){
    if(edk::View::isMouseInside()
            ||
            text.isMouseInside()
            )
        return true;
    return false;
}
