#include "ViewTextField.h"

/*
Library C++ ViewTextField - Entry text
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
#warning "            Inside ViewTextField.cpp"
#endif

edk::ViewTextField::ViewTextField(){
    //
    this->borderSize = 7;
}
edk::ViewTextField::~ViewTextField(){
    //
}

edk::ViewTextField::TextField::TextField(){
    this->saveBorder = 0u;
    this->selectView = false;
    this->pressInside=false;
    this->string=NULL;
    this->sizeString = 0u;
    this->deleteString();
    this->pressReturn=false;
}
edk::ViewTextField::TextField::~TextField(){
    //
    this->cleanString();
    this->deleteString();
}

//Set the entryPosition
bool edk::ViewTextField::TextField::setEntryPosition(edk::float32 x){
    //convert the X and Y to the camera
    edk::rectf32 cameraRect = this->camera.getRect();
    edk::float32 worldPositionX = cameraRect.origin.x + ((x/this->frame.size.width) * cameraRect.size.width)
            -((this->borderSize/this->frame.size.width)* cameraRect.size.width);

    if(worldPositionX<0.f)
        worldPositionX=0.f;
    //convert the position to int
    this->writePosition = (edk::uint32)(worldPositionX + 0.5f);

    this->setWritePosition(this->writePosition);
    return false;
}

void edk::ViewTextField::TextField::eventMousePressed(edk::vec2f32 point ,edk::uint32 button){
    if(button == edk::mouse::left){
        //
        this->selectView=true;
        this->pressInside=true;

        //set the entry position
        this->setEntryPosition(point.x);
        this->anim.loopOn();
        this->anim.setAnimationEndSecond(1);
        this->anim.playForward();
    }
}
void edk::ViewTextField::TextField::eventMouseMoved(edk::vec2f32 point,edk::uint32 button){
    if(button == edk::mouse::left){
        //set the entry position
        this->setEntryPosition(point.x);
    }
}
void edk::ViewTextField::TextField::eventMouseReleased(edk::vec2f32  ,edk::uint32){
    //
}

void edk::ViewTextField::TextField::load(rectf32){

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
            if(events->mousePressed[i] == edk::mouse::left){
                if(!this->pressInside){
                    //remove selection
                    this->selectView = false;
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
            switch(events->keyHolded[i]){
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
            keyPressed = events->keyPressed[i];
            switch(keyPressed){
            case edk::key::left:
                //back the writer position
                this->setWritePosition(this->writePosition-1u);
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
                this->addCharacter(' ');
                break;
            case edk::key::backSpace:
                //remove the character
                this->removeCharacter();
                break;
            case edk::key::Delete:
                //delete the character
                this->deleteCharacter();
            case edk::key::Return:
                //set press return
                this->pressReturn = true;
                break;
            case edk::key::escape:
                //
                this->selectView=false;
                break;
            default:
                //test if the key is a letter
                if(keyPressed>=edk::key::A
                        &&
                        keyPressed<=edk::key::Z
                        ){
                    //add the character
                    if(shift){
                        this->addCharacter(keyPressed + ('A' - 'a'));
                    }
                    else{
                        this->addCharacter(keyPressed);
                    }
                    break;
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
    if(this->saveRect.size!=outsideViewOrigin.size
            ||
            this->saveBorder!=this->borderSize){
        this->saveBorder = this->borderSize;
        this->frame.size = outsideViewOrigin.size - (this->saveBorder);
        this->saveRect.size = this->frame.size;
    }
    edk::ViewText::drawScene(outsideViewOrigin);

    if(this->selectView)
        this->obj.drawWithoutMaterial();
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

    edk::rectf32 camRect = this->camera.getRect();
    if(this->writePosition<camRect.origin.x){
        camRect.origin.x = this->writePosition;
        this->camera.setRect(camRect);
    }
    if(this->writePosition>camRect.origin.x + camRect.size.width){
        camRect.origin.x = this->writePosition - camRect.size.width;
        this->camera.setRect(camRect);
    }
}
//delete the string
void edk::ViewTextField::TextField::deleteString(){
    if(this->string)
        delete[] this->string;
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
        edk::char8* temp = new edk::char8[2u];
        if(temp){
            temp[0u] = c;
            temp[1u] = '\0';
            //test if have a string
            if(this->string){
                edk::char8* strSet;
                if(this->writePosition>this->sizeString) this->sizeString = this->writePosition;
                //test if the writer and the size are equal
                if(this->sizeString == this->writePosition){
                    //then add the character to the end of the string
                    strSet = edk::String::strCat(this->string,temp);
                    if(strSet){
                        //delete this string
                        delete[] this->string;
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
                        delete[] this->string;
                        this->string = strSet;
                        this->sizeString = edk::String::strSize(this->string);
                        this->setWritePosition(this->writePosition+1u);
                        ret=true;
                    }
                }
                else{
                    //else coy the characters manualy
                    strSet = new edk::char8[this->sizeString+2u];
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
                        delete[] this->string;
                        //set the string
                        this->string = strSet;
                        this->sizeString = edk::String::strSize(this->string);
                        this->setWritePosition(this->writePosition+1u);
                        ret=true;
                    }
                }

                delete[] temp;
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
    if(ret)
        this->createString(this->string);
    return ret;
}
bool edk::ViewTextField::TextField::addCharacterFromString(const char* str){
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
        if(this->writePosition>this->sizeString) this->sizeString = this->writePosition;

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
                delete[] this->string;
                this->string = strSet;
                this->sizeString = edk::String::strSize(this->string);
                this->setWritePosition(this->writePosition-1u);
                ret=true;
            }
        }
        //else test if remove the characters inside
        else if(this->writePosition){
            //create the new string
            strSet = new edk::char8[this->sizeString];
            if(strSet){
                this->setWritePosition(this->writePosition-1u);
                //add the end
                strSet[this->sizeString-1u] = '\0';
                //copy the first characters
                memcpy(strSet,this->string,this->writePosition);
                //copy the last characters
                memcpy(&strSet[this->writePosition],&this->string[this->writePosition+1u],this->sizeString-this->writePosition-1u);
                //delete the string
                delete[] this->string;
                //set the string
                this->string = strSet;
                this->sizeString = edk::String::strSize(this->string);
                ret=true;
            }
        }
    }
    if(ret)
        this->createString(this->string);
    return ret;
}
//delete the character
bool edk::ViewTextField::TextField::deleteCharacter(){
    bool ret=false;
    //test if have the string
    if(this->string){
        edk::char8* strSet;
        if(this->writePosition>this->sizeString) this->sizeString = this->writePosition;
        //test if remove the last character

        if(this->sizeString==1u && this->writePosition==0u){
            //just delete the string
            this->deleteString();
            this->cleanString();
            return true;
        }
        else if(!this->writePosition){
            strSet = new edk::char8[this->sizeString];
            if(strSet){
                //add the end
                strSet[this->sizeString-1u] = '\0';
                //set the memory
                memcpy(strSet,&this->string[1u],this->sizeString-1u);
                //delete this string
                delete[] this->string;
                this->string = strSet;
                this->sizeString = edk::String::strSize(this->string);
                this->setWritePosition(this->writePosition);
                ret=true;
            }
        }
        //else test if remove the characters inside
        else if(this->writePosition<this->sizeString){
            //create the new string
            strSet = new edk::char8[this->sizeString];
            if(strSet){
                //add the end
                strSet[this->sizeString-1u] = '\0';
                //copy the first characters
                memcpy(strSet,this->string,this->writePosition);
                //copy the last characters
                memcpy(&strSet[this->writePosition],&this->string[this->writePosition+1u],this->sizeString-this->writePosition-1u);
                //delete the string
                delete[] this->string;
                //set the string
                this->string = strSet;
                this->sizeString = edk::String::strSize(this->string);

                this->setWritePosition(this->writePosition);
                ret=true;
            }
        }
    }
    if(ret)
        this->createString(this->string);
    return ret;
}

void edk::ViewTextField::load(rectf32){
    //
    this->addSubview(&this->text);
    this->text.backgroundColor = edk::color4f32(0,1,0,1);
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
bool edk::ViewTextField::createString(const char* string){
    return this->createString((edk::char8*) string);
}
bool edk::ViewTextField::createString(edk::char8* string){
    return this->text.setString(string);
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
