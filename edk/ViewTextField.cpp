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

edk::ViewTextField::ViewTextField(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::ViewTextField::~ViewTextField(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::ViewTextField::Constructor(bool runFather){
    if(runFather){
        edk::ViewMenu::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;

        this->text.Constructor();edkEnd();

        this->borderSize = 7;edkEnd();
    }
}

edk::ViewTextField::TextField::TextField(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::ViewTextField::TextField::~TextField(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->cleanString();edkEnd();
        this->deleteString();edkEnd();
    }
}

void edk::ViewTextField::TextField::Constructor(bool runFather){
    if(runFather){
        edk::ViewText::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;

        this->obj.Constructor();
        this->anim.Constructor();

        this->saveBorder = 0u;edkEnd();
        this->selectView = false;edkEnd();
        this->pressInside=false;edkEnd();
        this->string=NULL;edkEnd();
        this->sizeString = 0u;edkEnd();
        this->deleteString();edkEnd();
        this->pressReturn=false;edkEnd();
        this->pressQuote = false;edkEnd();
        this->pressTilde = false;edkEnd();
    }
}

//Set the entryPosition
bool edk::ViewTextField::TextField::setEntryPosition(edk::float32 x){
    //convert the X and Y to the camera
    edk::rectf32 cameraRect = this->camera.getRect();edkEnd();
    edk::float32 worldPositionX = cameraRect.origin.x + ((x/this->frame.size.width) * cameraRect.size.width)
            -((this->borderSize/this->frame.size.width)* cameraRect.size.width);edkEnd();

    if(worldPositionX<0.f){
        worldPositionX=0.f;edkEnd();
    }
    //convert the position to int
    this->writePosition = (edk::uint32)(worldPositionX + 0.5f);edkEnd();

    this->setWritePosition(this->writePosition);edkEnd();
    return false;
}

void edk::ViewTextField::TextField::eventMousePressed(edk::vec2f32 point ,edk::uint32 button){
    if(button == edk::mouse::left){
        //
        this->selectView=true;edkEnd();
        this->pressInside=true;edkEnd();

        //set the entry position
        this->setEntryPosition(point.x);edkEnd();
        this->anim.loopOn();edkEnd();
        this->anim.setAnimationEndSecond(1);edkEnd();
        this->anim.playForward();edkEnd();
    }
}
void edk::ViewTextField::TextField::eventMouseMoved(edk::vec2f32 point,edk::uint32 button){
    if(button == edk::mouse::left){
        //set the entry position
        this->setEntryPosition(point.x);edkEnd();
    }
}
void edk::ViewTextField::TextField::eventMouseReleased(edk::vec2f32,edk::uint32){
    //
}
void edk::ViewTextField::TextField::eventMouseDoubleClicked(edk::vec2f32,edk::uint32){
    //
}

void edk::ViewTextField::TextField::load(rectf32 outsideViewOrigin){
    this->saveOutsideView.size = outsideViewOrigin.size;edkEnd();
    edk::shape::Mesh2D *mesh = this->obj.newMesh();edkEnd();
    if(mesh){
        edk::shape::Rectangle2D rect;edkEnd();
        rect.setScale(0.1f,0.9f);edkEnd();
        rect.setTranslate(0.f,0.05f);edkEnd();
        mesh->addPolygon(rect);edkEnd();
    }
    this->obj.setPolygonsColor(0,0,0,1);edkEnd();


    //add one animation to the object
    this->anim.addNewInterpolationLine(0,1);edkEnd();
    this->anim.addNewInterpolationLine(0.49,1);edkEnd();
    this->anim.addNewInterpolationLine(0.5,0);edkEnd();
    this->anim.addNewInterpolationLine(0.99,0);edkEnd();
    this->anim.addNewInterpolationLine(1,1);edkEnd();

    this->anim.loopOn();edkEnd();
    this->anim.setAnimationEndSecond(1);edkEnd();
    this->anim.playForward();edkEnd();
}
void edk::ViewTextField::TextField::unload(){
    //
    this->obj.cleanMeshes();edkEnd();
    this->anim.cleanAnimations();edkEnd();
}
void edk::ViewTextField::TextField::update(edk::WindowEvents* events){
    //update animation
    this->anim.updateClockAnimation();edkEnd();
    this->obj.setPolygonsColor(0,0,0,this->anim.getClockX());edkEnd();

    //test if is playing
    if(!this->anim.isPlaying()){
        //then play with loop
        this->anim.setAnimationEndSecond(1);edkEnd();
        this->anim.loopOn();edkEnd();
        this->anim.playForward();edkEnd();
    }

    //test if mouse is pressed
    edk::uint32 size = events->mousePressed.size();edkEnd();
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            if(events->mousePressed.get(i) == edk::mouse::left){
                if(!this->pressInside){
                    //remove selection
                    this->selectView = false;edkEnd();
                }
            }
        }
    }
    this->pressInside=false;edkEnd();


    //test if the view is selected
    if(this->selectView){
        size = events->keyHolded.size();edkEnd();
        bool shift=false;edkEnd();
        //test if is holding the shift
        for(edk::uint32 i=0u;i<size;i++){
            switch(events->keyHolded.get(i)){
            case edk::key::lShift:
            case edk::key::rShift:
                shift=true;edkEnd();
                break;
            }
        }
        //test the keyboard
        size = events->keyPressed.size();edkEnd();
        edk::uint32 keyPressed;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            //load the keyPressed
            keyPressed = events->keyPressed.get(i);edkEnd();
            /*
            printf("\nKey Pressed %u"
                   ,keyPressed
                   );edkEnd();
*/
            switch(keyPressed){
            case edk::key::left:
                //back the writer position
                if(this->writePosition){
                    this->setWritePosition(this->writePosition-1u);edkEnd();
                }
                break;
            case edk::key::right:
                //foward the writer position
                this->setWritePosition(this->writePosition+1u);edkEnd();
                break;
            case edk::key::home:
                //
                this->setWritePosition(0u);edkEnd();
                break;
            case edk::key::end:
                //
                this->setWritePosition(this->sizeString);edkEnd();
                break;
            case edk::key::space:
                //
                //accent
                if(this->pressTilde){
                    this->addCharacter('~');edkEnd();
                    this->pressTilde=false;edkEnd();
                }
                else if(this->pressQuote){
                    this->addCharacterFromString("´");edkEnd();
                    this->pressQuote=false;edkEnd();
                }
                else{
                    this->addCharacter(' ');edkEnd();
                }
                break;
            case edk::key::comma:
                //
                this->addCharacter(',');edkEnd();
                break;
            case edk::key::semiColon:
                //
                this->addCharacter(';');edkEnd();
                break;
            case edk::key::period:
                //
                this->addCharacter('.');edkEnd();
                break;
            case edk::key::quote:
                //accent
                if(this->pressQuote){
                    this->addCharacterFromString("´");edkEnd();
                    this->pressQuote=false;edkEnd();
                }
                else if(this->pressTilde){
                    this->addCharacter('~');edkEnd();
                    this->pressTilde=false;edkEnd();
                }
                else{
                    this->pressQuote=true;edkEnd();
                }
                break;
            case edk::key::tilde:
                //accent
                if(this->pressTilde){
                    this->addCharacter('~');edkEnd();
                    this->pressTilde=false;edkEnd();
                }
                else if(this->pressQuote){
                    this->addCharacterFromString("´");edkEnd();
                    this->pressQuote=false;edkEnd();
                }
                else{
                    this->pressTilde=true;edkEnd();
                }
                break;
            case edk::key::slash:
                //accent
                this->addCharacter('/');edkEnd();
                break;
            case edk::key::backSlash:
                //accent
                this->addCharacter('\\');edkEnd();
                break;
            case edk::key::equal:
                //accent
                this->addCharacter('=');edkEnd();
                break;
            case edk::key::dash:
                //accent
                this->addCharacter('-');edkEnd();
                break;
            case edk::key::tab:
                //accent
                this->addCharacter(' ');edkEnd();
                this->addCharacter(' ');edkEnd();
                this->addCharacter(' ');edkEnd();
                break;
            case edk::key::add:
                //accent
                this->addCharacter('+');edkEnd();
                break;
            case edk::key::subtract:
                //accent
                this->addCharacter('-');edkEnd();
                break;
            case edk::key::multiply:
                //accent
                this->addCharacter('*');edkEnd();
                break;
            case edk::key::divide:
                //accent
                this->addCharacter(247);edkEnd();
                break;
            case edk::key::backSpace:
                //remove the character
                if(this->pressQuote){
                    this->pressQuote=false;edkEnd();
                }
                else if(this->pressTilde){
                    this->pressTilde=false;edkEnd();
                }
                else{
                    this->removeCharacter();edkEnd();
                }
                break;
            case edk::key::Delete:
                //delete the character
                this->deleteCharacter();edkEnd();
                break;
            case edk::key::Return:
                //set press return
                this->pressReturn = true;edkEnd();
                break;
            case edk::key::escape:
                //
                this->selectView=false;edkEnd();
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
                            this->pressQuote=false;edkEnd();
                            switch(keyPressed){
                            case 'a':
                                this->addCharacterFromString("Á");edkEnd();
                                break;
                            case 'e':
                                this->addCharacterFromString("É");edkEnd();
                                break;
                            case 'i':
                                this->addCharacterFromString("Í");edkEnd();
                                break;
                            case 'o':
                                this->addCharacterFromString("Ó");edkEnd();
                                break;
                            case 'u':
                                this->addCharacterFromString("Ú");edkEnd();
                                break;
                            default:
                                this->addCharacterFromString("´");edkEnd();
                                this->addCharacter(keyPressed + ('A' - 'a'));edkEnd();
                            }
                        }
                        else if(this->pressTilde){
                            this->pressTilde=false;edkEnd();
                            switch(keyPressed){
                            case 'a':
                                this->addCharacterFromString("Ã");edkEnd();
                                break;
                            case 'e':
                                this->addCharacterFromString("Ẽ");edkEnd();
                                break;
                            case 'i':
                                this->addCharacterFromString("Ĩ");edkEnd();
                                break;
                            case 'o':
                                this->addCharacterFromString("Õ");edkEnd();
                                break;
                            case 'u':
                                this->addCharacterFromString("Ũ");edkEnd();
                                break;
                            default:
                                this->addCharacter('~');edkEnd();
                                this->addCharacter(keyPressed + ('A' - 'a'));edkEnd();
                            }
                        }
                        else{
                            this->addCharacter(keyPressed + ('A' - 'a'));edkEnd();
                        }
                    }
                    else{
                        if(this->pressQuote){
                            this->pressQuote=false;edkEnd();
                            switch(keyPressed){
                            case 'a':
                                this->addCharacterFromString("á");edkEnd();
                                break;
                            case 'e':
                                this->addCharacterFromString("é");edkEnd();
                                break;
                            case 'i':
                                this->addCharacterFromString("í");edkEnd();
                                break;
                            case 'o':
                                this->addCharacterFromString("ó");edkEnd();
                                break;
                            case 'u':
                                this->addCharacterFromString("ú");edkEnd();
                                break;
                            default:
                                this->addCharacterFromString("´");edkEnd();
                                this->addCharacter(keyPressed);edkEnd();
                            }
                        }
                        else if(this->pressQuote){
                            this->pressQuote=false;edkEnd();
                            switch(keyPressed){
                            case 'a':
                                this->addCharacterFromString("ã");edkEnd();
                                break;
                            case 'e':
                                this->addCharacterFromString("ẽ");edkEnd();
                                break;
                            case 'i':
                                this->addCharacterFromString("ĩ");edkEnd();
                                break;
                            case 'o':
                                this->addCharacterFromString("õ");edkEnd();
                                break;
                            case 'u':
                                this->addCharacterFromString("ũ");edkEnd();
                                break;
                            default:
                                this->addCharacter('~');edkEnd();
                                this->addCharacter(keyPressed);edkEnd();
                            }
                        }
                        else{
                            this->addCharacter(keyPressed);edkEnd();
                        }
                    }
                }
                //test if the key is a number
                if(keyPressed>=edk::key::num0
                        &&
                        keyPressed<=edk::key::num9
                        ){
                    //add the character
                    this->addCharacter(keyPressed);edkEnd();
                }
            }
        }
    }
}
void edk::ViewTextField::TextField::update(edk::WindowEvents* events,edk::float32 seconds){

    //update animation
    this->anim.updateClockAnimation(seconds);edkEnd();
    this->obj.setPolygonsColor(0,0,0,this->anim.getClockX());edkEnd();

    //test if is playing
    if(!this->anim.isPlaying()){
        //then play with loop
        this->anim.setAnimationEndSecond(1);edkEnd();
        this->anim.loopOn();edkEnd();
        this->anim.playForward();edkEnd();
    }

    //test if mouse is pressed
    edk::uint32 size = events->mousePressed.size();edkEnd();
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            if(events->mousePressed.get(i) == edk::mouse::left){
                if(!this->pressInside){
                    //remove selection
                    this->selectView = false;edkEnd();
                }
            }
        }
    }
    this->pressInside=false;edkEnd();


    //test if the view is selected
    if(this->selectView){
        size = events->keyHolded.size();edkEnd();
        bool shift=false;edkEnd();
        //test if is holding the shift
        for(edk::uint32 i=0u;i<size;i++){
            switch(events->keyHolded.get(i)){
            case edk::key::lShift:
            case edk::key::rShift:
                shift=true;edkEnd();
                break;
            }
        }
        //test the keyboard
        size = events->keyPressed.size();edkEnd();
        edk::uint32 keyPressed;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            //load the keyPressed
            keyPressed = events->keyPressed.get(i);edkEnd();
            /*
            printf("\nKey Pressed %u"
                   ,keyPressed
                   );edkEnd();
*/
            switch(keyPressed){
            case edk::key::left:
                //back the writer position
                if(this->writePosition){
                    this->setWritePosition(this->writePosition-1u);edkEnd();
                }
                break;
            case edk::key::right:
                //foward the writer position
                this->setWritePosition(this->writePosition+1u);edkEnd();
                break;
            case edk::key::home:
                //
                this->setWritePosition(0u);edkEnd();
                break;
            case edk::key::end:
                //
                this->setWritePosition(this->sizeString);edkEnd();
                break;
            case edk::key::space:
                //
                //accent
                if(this->pressTilde){
                    this->addCharacter('~');edkEnd();
                    this->pressTilde=false;edkEnd();
                }
                else if(this->pressQuote){
                    this->addCharacterFromString("´");edkEnd();
                    this->pressQuote=false;edkEnd();
                }
                else{
                    this->addCharacter(' ');edkEnd();
                }
                break;
            case edk::key::comma:
                //
                this->addCharacter(',');edkEnd();
                break;
            case edk::key::semiColon:
                //
                this->addCharacter(';');edkEnd();
                break;
            case edk::key::period:
                //
                this->addCharacter('.');edkEnd();
                break;
            case edk::key::quote:
                //accent
                if(this->pressQuote){
                    this->addCharacterFromString("´");edkEnd();
                    this->pressQuote=false;edkEnd();
                }
                else if(this->pressTilde){
                    this->addCharacter('~');edkEnd();
                    this->pressTilde=false;edkEnd();
                }
                else{
                    this->pressQuote=true;edkEnd();
                }
                break;
            case edk::key::tilde:
                //accent
                if(this->pressTilde){
                    this->addCharacter('~');edkEnd();
                    this->pressTilde=false;edkEnd();
                }
                else if(this->pressQuote){
                    this->addCharacterFromString("´");edkEnd();
                    this->pressQuote=false;edkEnd();
                }
                else{
                    this->pressTilde=true;edkEnd();
                }
                break;
            case edk::key::slash:
                //accent
                this->addCharacter('/');edkEnd();
                break;
            case edk::key::backSlash:
                //accent
                this->addCharacter('\\');edkEnd();
                break;
            case edk::key::equal:
                //accent
                this->addCharacter('=');edkEnd();
                break;
            case edk::key::dash:
                //accent
                this->addCharacter('-');edkEnd();
                break;
            case edk::key::tab:
                //accent
                this->addCharacter(' ');edkEnd();
                this->addCharacter(' ');edkEnd();
                this->addCharacter(' ');edkEnd();
                break;
            case edk::key::add:
                //accent
                this->addCharacter('+');edkEnd();
                break;
            case edk::key::subtract:
                //accent
                this->addCharacter('-');edkEnd();
                break;
            case edk::key::multiply:
                //accent
                this->addCharacter('*');edkEnd();
                break;
            case edk::key::divide:
                //accent
                this->addCharacter(247);edkEnd();
                break;
            case edk::key::backSpace:
                //remove the character
                if(this->pressQuote){
                    this->pressQuote=false;edkEnd();
                }
                else if(this->pressTilde){
                    this->pressTilde=false;edkEnd();
                }
                else{
                    this->removeCharacter();edkEnd();
                }
                break;
            case edk::key::Delete:
                //delete the character
                this->deleteCharacter();edkEnd();
                break;
            case edk::key::Return:
                //set press return
                this->pressReturn = true;edkEnd();
                break;
            case edk::key::escape:
                //
                this->selectView=false;edkEnd();
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
                            this->pressQuote=false;edkEnd();
                            switch(keyPressed){
                            case 'a':
                                this->addCharacterFromString("Á");edkEnd();
                                break;
                            case 'e':
                                this->addCharacterFromString("É");edkEnd();
                                break;
                            case 'i':
                                this->addCharacterFromString("Í");edkEnd();
                                break;
                            case 'o':
                                this->addCharacterFromString("Ó");edkEnd();
                                break;
                            case 'u':
                                this->addCharacterFromString("Ú");edkEnd();
                                break;
                            default:
                                this->addCharacterFromString("´");edkEnd();
                                this->addCharacter(keyPressed + ('A' - 'a'));edkEnd();
                            }
                        }
                        else if(this->pressTilde){
                            this->pressTilde=false;edkEnd();
                            switch(keyPressed){
                            case 'a':
                                this->addCharacterFromString("Ã");edkEnd();
                                break;
                            case 'e':
                                this->addCharacterFromString("Ẽ");edkEnd();
                                break;
                            case 'i':
                                this->addCharacterFromString("Ĩ");edkEnd();
                                break;
                            case 'o':
                                this->addCharacterFromString("Õ");edkEnd();
                                break;
                            case 'u':
                                this->addCharacterFromString("Ũ");edkEnd();
                                break;
                            default:
                                this->addCharacter('~');edkEnd();
                                this->addCharacter(keyPressed + ('A' - 'a'));edkEnd();
                            }
                        }
                        else{
                            this->addCharacter(keyPressed + ('A' - 'a'));edkEnd();
                        }
                    }
                    else{
                        if(this->pressQuote){
                            this->pressQuote=false;edkEnd();
                            switch(keyPressed){
                            case 'a':
                                this->addCharacterFromString("á");edkEnd();
                                break;
                            case 'e':
                                this->addCharacterFromString("é");edkEnd();
                                break;
                            case 'i':
                                this->addCharacterFromString("í");edkEnd();
                                break;
                            case 'o':
                                this->addCharacterFromString("ó");edkEnd();
                                break;
                            case 'u':
                                this->addCharacterFromString("ú");edkEnd();
                                break;
                            default:
                                this->addCharacterFromString("´");edkEnd();
                                this->addCharacter(keyPressed);edkEnd();
                            }
                        }
                        else if(this->pressQuote){
                            this->pressQuote=false;edkEnd();
                            switch(keyPressed){
                            case 'a':
                                this->addCharacterFromString("ã");edkEnd();
                                break;
                            case 'e':
                                this->addCharacterFromString("ẽ");edkEnd();
                                break;
                            case 'i':
                                this->addCharacterFromString("ĩ");edkEnd();
                                break;
                            case 'o':
                                this->addCharacterFromString("õ");edkEnd();
                                break;
                            case 'u':
                                this->addCharacterFromString("ũ");edkEnd();
                                break;
                            default:
                                this->addCharacter('~');edkEnd();
                                this->addCharacter(keyPressed);edkEnd();
                            }
                        }
                        else{
                            this->addCharacter(keyPressed);edkEnd();
                        }
                    }
                }
                //test if the key is a number
                if(keyPressed>=edk::key::num0
                        &&
                        keyPressed<=edk::key::num9
                        ){
                    //add the character
                    this->addCharacter(keyPressed);edkEnd();
                }
            }
        }
    }
}
//draw the GU scene
void edk::ViewTextField::TextField::drawScene(rectf32 outsideViewOrigin){
    this->saveOutsideView.size = outsideViewOrigin.size;edkEnd();
    if(this->saveRect.size!=outsideViewOrigin.size
            ||
            this->saveBorder!=this->borderSize){
        this->saveBorder = this->borderSize;edkEnd();
        this->frame.size = outsideViewOrigin.size - (this->saveBorder);edkEnd();
        this->saveRect.size = this->frame.size;edkEnd();
    }
    edk::ViewText::drawScene(outsideViewOrigin);edkEnd();

    if(this->selectView){
        this->obj.drawWithoutMaterial();edkEnd();
    }
}

//test if a point is inside the view
bool edk::ViewTextField::TextField::pointInside(edk::vec2f32 point){
    //create a tempRectangleShape
    edk::shape::Rectangle2D temp;edkEnd();
    temp.setVertexPosition(0u,this->saveOutsideView.origin);edkEnd();
    temp.setVertexPosition(1u,this->saveOutsideView.origin.x + this->saveOutsideView.size.width+this->saveBorder,this->saveOutsideView.origin.y + this->saveOutsideView.size.height+this->saveBorder);edkEnd();
    //test the contact
    return edk::collision::RectangleContact::contactPoint(point,temp);
}

//set writePosition
void edk::ViewTextField::TextField::setWritePosition(edk::uint32 position){
    if(position>this->sizeString){
        position=this->sizeString;edkEnd();
    }
    this->writePosition = position;edkEnd();
    this->obj.position.x = position;edkEnd();

    this->anim.loopOff();edkEnd();
    this->anim.setAnimationEndSecond(0.49f);edkEnd();
    this->anim.playForward();edkEnd();

    edk::rectf32 camRect = this->camera.getRect();edkEnd();
    if(this->writePosition<camRect.origin.x){
        camRect.origin.x = this->writePosition;edkEnd();
        this->camera.setRect(camRect);edkEnd();
    }
    if(this->writePosition>camRect.origin.x + camRect.size.width){
        camRect.origin.x = this->writePosition - camRect.size.width;edkEnd();
        this->camera.setRect(camRect);edkEnd();
    }
}
//delete the string
void edk::ViewTextField::TextField::deleteString(){
    if(this->string){
        free(this->string);edkEnd();
    }
    this->string = NULL;edkEnd();
    this->sizeString = 0u;edkEnd();
    this->setWritePosition(0u);edkEnd();
}
//copy the string
bool edk::ViewTextField::TextField::setString(edk::char8* string){
    this->deleteString();edkEnd();
    if(string){
        this->string = edk::String::strCopyFilterAccent(string);edkEnd();
        if(this->string){
            //create the map
            if(this->createString(string)){
                this->sizeString = edk::String::strSize(this->string);edkEnd();
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
        this->deleteString();edkEnd();
    }

    this->cleanString();edkEnd();
    return false;
}
//add a characted
bool edk::ViewTextField::TextField::addCharacter(edk::char8 c){
    bool ret=false;edkEnd();
    if(c){
        //create a string with the character
        edk::char8* temp = (edk::char8*)malloc(sizeof(edk::char8) * (2u));edkEnd();
        if(temp){
            temp[0u] = c;edkEnd();
            temp[1u] = '\0';edkEnd();
            //test if have a string
            if(this->string){
                edk::char8* strSet;edkEnd();
                if(this->writePosition>this->sizeString){
                    this->sizeString = this->writePosition;edkEnd();
                }
                //test if the writer and the size are equal
                if(this->sizeString == this->writePosition){
                    //then add the character to the end of the string
                    strSet = edk::String::strCat(this->string,temp);edkEnd();
                    if(strSet){
                        //delete this string
                        free(this->string);edkEnd();
                        this->string = strSet;edkEnd();
                        this->sizeString = edk::String::strSize(this->string);edkEnd();
                        this->setWritePosition(this->writePosition+1u);edkEnd();
                        ret=true;edkEnd();
                    }
                }
                //test if the writerPosition is the first
                else if(!this->writePosition){
                    //then add to the start
                    strSet = edk::String::strCat(temp,this->string);edkEnd();
                    if(strSet){
                        //delete this string
                        free(this->string);edkEnd();
                        this->string = strSet;edkEnd();
                        this->sizeString = edk::String::strSize(this->string);edkEnd();
                        this->setWritePosition(this->writePosition+1u);edkEnd();
                        ret=true;edkEnd();
                    }
                }
                else{
                    //else coy the characters manualy
                    strSet = (edk::char8*)malloc(sizeof(edk::char8) * (this->sizeString+2u));edkEnd();
                    if(strSet){
                        //add the end
                        strSet[this->sizeString+1u] = '\0';edkEnd();
                        //copy the first characters
                        memcpy(strSet,this->string,this->writePosition);edkEnd();
                        //set the character
                        strSet[this->writePosition] = temp[0u];edkEnd();
                        //copy the last characters
                        memcpy(&strSet[this->writePosition+1u],&this->string[this->writePosition],this->sizeString-this->writePosition);edkEnd();
                        //delete the string
                        free(this->string);edkEnd();
                        //set the string
                        this->string = strSet;edkEnd();
                        this->sizeString = edk::String::strSize(this->string);edkEnd();
                        this->setWritePosition(this->writePosition+1u);edkEnd();
                        ret=true;edkEnd();
                    }
                }

                free(temp);edkEnd();
            }
            else{
                //else the string receive the character
                this->string = temp;edkEnd();
                this->sizeString = edk::String::strSize(this->string);edkEnd();
                this->setWritePosition(this->writePosition+1u);edkEnd();
                ret=true;edkEnd();
            }
        }
    }
    if(ret){
        this->createString(this->string);edkEnd();
    }
    return ret;
}
bool edk::ViewTextField::TextField::addCharacterFromString(const edk::char8* str){
    return this->addCharacterFromString((edk::char8*) str);edkEnd();
}
bool edk::ViewTextField::TextField::addCharacterFromString(edk::char8* str){
    //filter the first character
    return this->addCharacter(edk::String::filterAccent(str));edkEnd();
}
//remove the caracter
bool edk::ViewTextField::TextField::removeCharacter(){
    bool ret=false;edkEnd();
    //test if have the string
    if(this->string){
        edk::char8* strSet;edkEnd();
        if(this->writePosition>this->sizeString){
            this->sizeString = this->writePosition;edkEnd();
        }

        if(this->sizeString==1u && this->writePosition==1u){
            //just delete the string
            this->deleteString();edkEnd();
            this->cleanString();edkEnd();
            return true;
        }
        //else test if remove the first characters
        else if(this->writePosition==1u){
            strSet = edk::String::strCopy(&this->string[1u]);edkEnd();
            if(strSet){
                //delete this string
                free(this->string);edkEnd();
                this->string = strSet;edkEnd();
                this->sizeString = edk::String::strSize(this->string);edkEnd();
                this->setWritePosition(this->writePosition-1u);edkEnd();
                ret=true;edkEnd();
            }
        }
        //else test if remove the characters inside
        else if(this->writePosition){
            //create the new string
            strSet = (edk::char8*)malloc(sizeof(edk::char8) * (this->sizeString));edkEnd();
            if(strSet){
                this->setWritePosition(this->writePosition-1u);edkEnd();
                //add the end
                strSet[this->sizeString-1u] = '\0';edkEnd();
                //copy the first characters
                memcpy(strSet,this->string,this->writePosition);edkEnd();
                //copy the last characters
                memcpy(&strSet[this->writePosition],&this->string[this->writePosition+1u],this->sizeString-this->writePosition-1u);edkEnd();
                //delete the string
                free(this->string);edkEnd();
                //set the string
                this->string = strSet;edkEnd();
                this->sizeString = edk::String::strSize(this->string);edkEnd();
                ret=true;edkEnd();
            }
        }
    }
    if(ret){
        this->createString(this->string);edkEnd();
    }
    return ret;
}
//delete the character
bool edk::ViewTextField::TextField::deleteCharacter(){
    bool ret=false;edkEnd();
    //test if have the string
    if(this->string){
        edk::char8* strSet;edkEnd();
        if(this->writePosition>this->sizeString){
            this->sizeString = this->writePosition;edkEnd();
        }
        //test if remove the last character

        if(this->sizeString==1u && this->writePosition==0u){
            //just delete the string
            this->deleteString();edkEnd();
            this->cleanString();edkEnd();
            return true;
        }
        else if(!this->writePosition){
            strSet = (edk::char8*)malloc(sizeof(edk::char8) * (this->sizeString));edkEnd();
            if(strSet){
                //add the end
                strSet[this->sizeString-1u] = '\0';edkEnd();
                //set the memory
                memcpy(strSet,&this->string[1u],this->sizeString-1u);edkEnd();
                //delete this string
                free(this->string);edkEnd();
                this->string = strSet;edkEnd();
                this->sizeString = edk::String::strSize(this->string);edkEnd();
                this->setWritePosition(this->writePosition);edkEnd();
                ret=true;edkEnd();
            }
        }
        //else test if remove the characters inside
        else if(this->writePosition<this->sizeString){
            //create the new string
            strSet = (edk::char8*)malloc(sizeof(edk::char8) * (this->sizeString));edkEnd();
            if(strSet){
                //add the end
                strSet[this->sizeString-1u] = '\0';edkEnd();
                //copy the first characters
                memcpy(strSet,this->string,this->writePosition);edkEnd();
                //copy the last characters
                memcpy(&strSet[this->writePosition],&this->string[this->writePosition+1u],this->sizeString-this->writePosition-1u);edkEnd();
                //delete the string
                free(this->string);edkEnd();
                //set the string
                this->string = strSet;edkEnd();
                this->sizeString = edk::String::strSize(this->string);edkEnd();

                this->setWritePosition(this->writePosition);edkEnd();
                ret=true;edkEnd();
            }
        }
    }
    if(ret){
        this->createString(this->string);edkEnd();
    }
    return ret;
}
//return the string
edk::char8* edk::ViewTextField::TextField::getString(){
    return this->string;edkEnd();
}
edk::uint32 edk::ViewTextField::TextField::getSizeString(){
    return this->sizeString;edkEnd();
}
//eturn true if the text is selected
bool edk::ViewTextField::TextField::isSelected(){
    return this->selectView;edkEnd();
}

void edk::ViewTextField::load(rectf32){
    this->addSubview(&this->text);edkEnd();
    this->text.backgroundColor = edk::color4f32(1,1,1,0);edkEnd();
}
void edk::ViewTextField::unload(){
    this->removeSubview(&this->text);edkEnd();
}
void edk::ViewTextField::update(edk::WindowEvents*){
    if(this->saveRect!=this->frame){
        this->saveRect = this->frame;edkEnd();
        //this->text.frame.size = this->saveRect.size - (this->borderTemp*2);edkEnd();
    }
    this->text.borderSize = this->borderTemp;edkEnd();
}

//create a string
bool edk::ViewTextField::createString(const edk::char8* string){
    return this->createString((edk::char8*) string);edkEnd();
}
bool edk::ViewTextField::createString(edk::char8* string){
    return this->text.setString(string);edkEnd();
}
//get the string
edk::char8* edk::ViewTextField::getString(){
    return this->text.getString();edkEnd();
}
//return the size of the string
edk::uint32 edk::ViewTextField::getStringSize(){
    return this->text.getSizeString();edkEnd();
}
//clean the string
void edk::ViewTextField::cleanString(){
    this->text.deleteString();edkEnd();
    this->text.cleanString();edkEnd();
}

//add a character
bool edk::ViewTextField::addCharacter(edk::char8 c){
    return this->text.addCharacter(c);edkEnd();
}
//remove the caracter
bool edk::ViewTextField::removeCharacter(){
    return this->text.removeCharacter();edkEnd();
}
//delete the character
bool edk::ViewTextField::deleteCharacter(){
    return this->text.deleteCharacter();edkEnd();
}
//test if press enter
bool edk::ViewTextField::havePressReturn(){
    if(this->text.pressReturn){
        this->text.pressReturn=false;edkEnd();
        return true;
    }
    return false;
}
//Set the writer position
void edk::ViewTextField::setWritePosition(edk::uint32 position){
    this->text.setWritePosition(position);edkEnd();
}
//return true if is selected
bool edk::ViewTextField::isSelected(){
    return this->text.isSelected();edkEnd();
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
