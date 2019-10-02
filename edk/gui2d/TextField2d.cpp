#include "TextField2d.h"

/*
TextField2d - TextField2d for the GUI 2D library
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

edk::gui2d::TextField2d::TextVec::TextVec(){
    //
    this->caseInput = edk::gui2d::upperAndLowerCase;
    this->limit = 0u;
}
edk::gui2d::TextField2d::TextVec::~TextVec(){
    //
    this->cleanFilterIn();
    this->cleanFilterOut();
}
edk::uint32 edk::gui2d::TextField2d::TextVec::sizeOfString(){
    edk::uint32 size = this->vec.size();
    edk::uint32 ret = size;
    edk::uint32 c=0u;
    for(edk::uint32 i = 0u;i<size;i++){
        //get the 32 bits character
        c = this->vec.get(i);
        if(edk::BinaryConverter::getByteLittleEndian(c,1u)){
            ret++;
            if(edk::BinaryConverter::getByteLittleEndian(c,2u)){
                ret++;
                if(edk::BinaryConverter::getByteLittleEndian(c,3u)){
                    ret++;
                }
            }
        }
    }
    return ret;
}
//return true if the character can be inside the tree
bool edk::gui2d::TextField2d::TextVec::canGetIt(edk::char32 c){
    //test if have something in filterIN
    if(this->filterIn.size()){
        //test if can add the c
        return this->filterIn.haveElement(c);
    }
    else{
        //else test if have something in filterOut
        if(this->filterOut.size()){
            //test if can't add the c
            return !this->filterOut.haveElement(c);
        }
    }
    //else return true
    return true;
}
void edk::gui2d::TextField2d::TextVec::clean(){
    this->vec.clean();
}
bool edk::gui2d::TextField2d::TextVec::write(edk::char8* str){
    this->clean();
    //test the string
    if(str){
        //get the strng lenght
        edk::uint32 lenght = edk::String::strSize(str);
        edk::char32 c;
        edk::uint8 increment=0u;
        if(lenght){
            //populate the vector
            for(edk::uint32 i=0u;i<lenght;i++){
                if(str[i]==13
                        ||
                        str[i]==10
                        ||
                        str[i]=='\0'
                        ){
                    break;
                }
                c = edk::String::utf8ToUint32(&str[i]);
                increment=edk::String::utf8Bytes(&str[i]);
                i+=increment;

                //test if the lenght exceede the limit
                if(this->vec.size()>=this->limit){
                    return true;
                }

                //test the case
                switch(this->caseInput){
                case edk::gui2d::upperAndLowerCase:
                    break;
                case edk::gui2d::upperCase:
                    if(c>='a' && c<='z'){
                        c+='A'-'a';
                    }
                    break;
                case edk::gui2d::lowerCase:
                    if(c>='A' && c<='Z'){
                        c-='A'-'a';
                    }
                    break;
                }

                if(this->canGetIt(c))
                    this->vec.pushBack(c);
            }
            if(this->vec.size()){
                return true;
            }
        }
    }
    return false;
}
edk::uint32 edk::gui2d::TextField2d::TextVec::add(edk::char8* str,edk::uint32 position){
    //test the string
    if(str){
        //get the strng lenght
        edk::uint32 lenght = edk::String::strSize(str);
        edk::char32 c;
        edk::uint32 ret = 0u;
        edk::uint8 increment=0u;
        if(lenght){
            //populate the vector
            for(edk::uint32 i=0u;i<lenght;i++){
                if(str[i]==13
                        ||
                        str[i]==10
                        ||
                        str[i]=='\0'
                        ){
                    break;
                }
                c = edk::String::utf8ToUint32(&str[i]);
                increment=edk::String::utf8Bytes(&str[i]);
                i+=increment;

                //test the case
                switch(this->caseInput){
                case edk::gui2d::upperAndLowerCase:
                    break;
                case edk::gui2d::upperCase:
                    if(c>='a' && c<='z'){
                        c+='A'-'a';
                    }
                    break;
                case edk::gui2d::lowerCase:
                    if(c>='A' && c<='Z'){
                        c-='A'-'a';
                    }
                    break;
                }

                if(!this->add(c,position)){
                    return 0u;
                }
                position++;
                ret++;
            }
            return ret;
        }
    }
    return 0u;
}
edk::uint32 edk::gui2d::TextField2d::TextVec::add(edk::char8 c,edk::uint32 position){
    return add((edk::char32) c,position);
}
edk::uint32 edk::gui2d::TextField2d::TextVec::add(edk::char16 c,edk::uint32 position){
    return add((edk::char32) c,position);
}
edk::uint32 edk::gui2d::TextField2d::TextVec::add(edk::char32 c,edk::uint32 position){
    edk::uint32 size = this->vec.size();
    //test if the lenght exceede the limit
    if(size>=this->limit){
        return 0u;
    }
    //test if have the position
    if(position<=size && this->canGetIt(c)){
        //test the case
        switch(this->caseInput){
        case edk::gui2d::upperAndLowerCase:
            break;
        case edk::gui2d::upperCase:
            if(c>='a' && c<='z'){
                c+='A'-'a';
            }
            break;
        case edk::gui2d::lowerCase:
            if(c>='A' && c<='Z'){
                c-='A'-'a';
            }
            break;
        }
        this->vec.pushBack(c);
        if(size<this->vec.size()){
            //
            if(position<size){
                this->vec.bringPositionTo(size,position);
            }
            return 1u;
        }
    }
    return 0u;
}

bool edk::gui2d::TextField2d::TextVec::remove(edk::uint32 position){
    edk::uint32 size = this->vec.size();
    //test if have the position
    if(position<size){
        size--;
        //move the position to the end
        this->vec.bringPositionTo(position,size);
        this->vec.remove(size);
        return true;
    }
    return false;
}
bool edk::gui2d::TextField2d::TextVec::remove(edk::uint32 position,edk::uint32 times){
    bool ret=true;
    for(edk::uint32 i=0u;i<times;i++){
        ret = this->remove(position);
    }
    return ret;
}
edk::char8* edk::gui2d::TextField2d::TextVec::getString(){
    edk::uint32 size = this->sizeOfString();
    //test if have some characters
    if(size){
        //create the new string
        edk::char8* str = new edk::char8[size+1u];
        if(str){
            str[size]='\0';
            edk::uint32 position = 0u;
            edk::char8* p = str;
            edk::uint32 c = 0u;
            //copy the characters
            for(edk::uint32 i=0u;i<size;i++){
                //
                c = this->vec.get(position);
                if(!c){
                    delete[] str;
                    return NULL;
                }
                //test if is a special character
                if(edk::BinaryConverter::getByteLittleEndian(c,1u)){
                    i++;
                    if(edk::BinaryConverter::getByteLittleEndian(c,2u)){
                        i++;
                        if(edk::BinaryConverter::getByteLittleEndian(c,3u)){
                            i++;
                            //add the value
                            *p = edk::BinaryConverter::getByteLittleEndian(c,3u);
                            p++;
                        }
                        //add the value
                        *p = edk::BinaryConverter::getByteLittleEndian(c,2u);
                        p++;
                    }
                    //add the value
                    *p = edk::BinaryConverter::getByteLittleEndian(c,1u);
                    p++;
                }
                *p = edk::BinaryConverter::getByteLittleEndian(c,0u);
                p++;
                position++;
            }
            return str;
        }
    }
    return NULL;
}
edk::char8* edk::gui2d::TextField2d::TextVec::getStringWithLastSpace(){
    edk::uint32 size = this->sizeOfString();
    //test if have some characters
    if(size){
        //create the new string
        edk::char8* str = new edk::char8[size+2u];
        if(str){
            str[size+1u]='\0';
            str[size]=' ';
            edk::uint32 position = 0u;
            edk::char8* p = str;
            edk::uint32 c = 0u;
            //copy the characters
            for(edk::uint32 i=0u;i<size;i++){
                //
                c = this->vec.get(position);
                if(!c){
                    delete[] str;
                    return NULL;
                }
                //test if is a special character
                if(edk::BinaryConverter::getByteLittleEndian(c,1u)){
                    i++;
                    if(edk::BinaryConverter::getByteLittleEndian(c,2u)){
                        i++;
                        if(edk::BinaryConverter::getByteLittleEndian(c,3u)){
                            i++;
                            //add the value
                            *p = edk::BinaryConverter::getByteLittleEndian(c,3u);
                            p++;
                        }
                        //add the value
                        *p = edk::BinaryConverter::getByteLittleEndian(c,2u);
                        p++;
                    }
                    //add the value
                    *p = edk::BinaryConverter::getByteLittleEndian(c,1u);
                    p++;
                }
                *p = edk::BinaryConverter::getByteLittleEndian(c,0u);
                p++;
                position++;
            }
            return str;
        }
    }
    return NULL;
}
edk::uint32 edk::gui2d::TextField2d::TextVec::getSize(){
    return this->vec.size();
}
//add a character to the filter
bool edk::gui2d::TextField2d::TextVec::addFilterIn(edk::char8* str){
    //test the string
    if(str){
        //get the strng lenght
        edk::uint32 lenght = edk::String::strSize(str);
        edk::char32 c;
        edk::uint32 increment;
        bool ret = false;
        if(lenght){
            //populate the vector
            for(edk::uint32 i=0u;i<lenght;i++){
                if(str[i]==13
                        ||
                        str[i]==10
                        ||
                        str[i]=='\0'
                        ){
                    break;
                }
                c = edk::String::utf8ToUint32(&str[i]);
                increment=edk::String::utf8Bytes(&str[i]);
                i+=increment;

                //test the case
                switch(this->caseInput){
                case edk::gui2d::upperAndLowerCase:
                    break;
                case edk::gui2d::upperCase:
                    if(c>='a' && c<='z'){
                        c+='A'-'a';
                    }
                    break;
                case edk::gui2d::lowerCase:
                    if(c>='A' && c<='Z'){
                        c-='A'-'a';
                    }
                    break;
                }

                if(!this->addFilterIn(c)){
                    return false;
                }
                ret = true;
            }
            return ret;
        }
    }
    return false;
}
bool edk::gui2d::TextField2d::TextVec::addFilterIn(edk::char8 c){
    return this->addFilterIn((edk::char32)c);
}
bool edk::gui2d::TextField2d::TextVec::addFilterIn(edk::char16 c){
    return this->addFilterIn((edk::char32)c);
}
bool edk::gui2d::TextField2d::TextVec::addFilterIn(edk::char32 c){
    return this->filterIn.add(c);
}
void edk::gui2d::TextField2d::TextVec::cleanFilterIn(){
    this->filterIn.clean();
}
bool edk::gui2d::TextField2d::TextVec::addFilterOut(edk::char8* str){
    //test the string
    if(str){
        //get the strng lenght
        edk::uint32 lenght = edk::String::strSize(str);
        edk::char32 c;
        edk::uint32 increment;
        bool ret = false;
        if(lenght){
            //populate the vector
            for(edk::uint32 i=0u;i<lenght;i++){
                if(str[i]==13
                        ||
                        str[i]==10
                        ||
                        str[i]=='\0'
                        ){
                    break;
                }

                c = edk::String::utf8ToUint32(&str[i]);
                increment=edk::String::utf8Bytes(&str[i]);
                i+=increment;

                //test the case
                switch(this->caseInput){
                case edk::gui2d::upperAndLowerCase:
                    break;
                case edk::gui2d::upperCase:
                    if(c>='a' && c<='z'){
                        c+='A'-'a';
                    }
                    break;
                case edk::gui2d::lowerCase:
                    if(c>='A' && c<='Z'){
                        c-='A'-'a';
                    }
                    break;
                }

                if(!this->addFilterOut(c)){
                    return false;
                }
                ret = true;
            }
            return ret;
        }
    }
    return false;
}
bool edk::gui2d::TextField2d::TextVec::addFilterOut(edk::char8 c){
    return this->addFilterOut((edk::char32)c);
}
bool edk::gui2d::TextField2d::TextVec::addFilterOut(edk::char16 c){
    return this->addFilterOut((edk::char32)c);
}
bool edk::gui2d::TextField2d::TextVec::addFilterOut(edk::char32 c){
    return this->filterOut.add(c);
}
void edk::gui2d::TextField2d::TextVec::cleanFilterOut(){
    this->filterOut.clean();
}
//set the textLimit. Use zero to unlimited
void edk::gui2d::TextField2d::TextVec::setCharacterLimit(edk::uint32 limit){
    this->limit = limit;
}
//set the caseInput
void edk::gui2d::TextField2d::TextVec::setCaseInput(edk::gui2d::Case caseInput){
    this->caseInput = caseInput;
}

edk::gui2d::TextField2d::TextField2d(){
    //
    this->fontColor = edk::color4f32(0,0,0,1);
    this->drawBackground=true;
    this->obj.setBorderSize(0.25f);
    this->originID = 0u;
    this->cursorID = 0u;
    this->endID=0u;
    this->selectionMiddle = this->selectionStart = this->selectionEnd = 0u;
}
edk::gui2d::TextField2d::~TextField2d(){
    //
    this->unload();
}

//get the type
edk::gui2d::gui2dTypes edk::gui2d::TextField2d::getType(){
    return edk::gui2d::gui2dTypeTextField;
}
//clean all characters
void edk::gui2d::TextField2d::cleanCharacters(){
    this->textVec.clean();
    this->originID = 0u;
    this->cursorID = 0u;
    this->endID=0u;
    this->selectionMiddle = this->selectionStart = this->selectionEnd = 0u;
}

void edk::gui2d::TextField2d::updateTextSize(edk::size2f32 sizeText,edk::size2f32 centerSize,edk::size2ui32 mapSize){
    edk::uint32 mapWidth = this->text.getMapSizeWidth();
    if(mapWidth)mapWidth--;

    if(mapWidth){
        this->text.setScale((centerSize.height * (sizeText.width/sizeText.height))/(edk::float32)mapSize.width,
                            centerSize.height
                            );
        //save the cursor size
        this->cursor.size = edk::size2f32(this->text.getMapScaleWidth() * edkGU2dCursorWidthPercent,this->text.getMapScaleHeight());

        //test if it was modified
        if(this->cursor.size != this->saveCursorSize){
            //update the cursor animation
            this->cursor.animationSize.cleanAnimations();

            //create a size animation for the cursor
            this->cursor.animationSize.addNewInterpolationLine(0.f,this->cursor.size.width,this->cursor.size.height);
            this->cursor.animationSize.addNewInterpolationLine(edkGU2dCursorSecond,this->cursor.size.width,this->cursor.size.height);
            this->cursor.animationSize.addNewInterpolationLine(edkGU2dCursorSecond + 0.001f,0.f,0.f);
            this->cursor.animationSize.addNewInterpolationLine((edkGU2dCursorSecond*2.f) + 0.001f,0.f,0.f);
            this->cursor.animationSize.loopOn();

            //save the cursorSize to the next comparison
            this->saveCursorSize = this->cursor.size;

            //if its selected. Then play the animation
            if(this->selected){
                this->cursor.animationSize.stop();
                this->cursor.animationSize.playForward();
            }
        }

        //get the size of characters inside the field
        edk::uint32 chSize = (edk::uint32)(centerSize.width/this->text.getMapScaleWidth());
        edk::uint32 selection1=0u,selection2=0u;

        if(this->cursorID>mapWidth){
            //
            this->cursorID=mapWidth;
        }

        //test if the origin can be drawed
        if(mapWidth >= chSize){
            //test if the cursor in outsize the origin and last
            if(this->cursorID < this->originID
                    ){
                this->originID = this->cursorID;
            }
            else if(this->cursorID > this->originID+chSize
                    ){
                this->originID = this->cursorID - chSize;
            }

            if(this->originID > mapWidth - chSize){
                this->originID = mapWidth - chSize;
            }
            //set the size
            this->endID = this->originID + chSize - 1u;
            this->text.setOriginAndLast(this->originID,this->originID + chSize - 1u);
        }
        else{
            this->originID = 0u;
            this->endID = mapWidth-1u;
            this->text.setOriginAndLast(this->originID,mapWidth-1u);
        }

        //set the text position with the origin ID
        this->text.setPosition((centerSize.width*-0.5f) + (this->text.getMapScaleWidth()*0.5f) - this->text.getMapScaleWidth() * this->originID,
                               0.f
                               );
        //set the cursor position
        this->cursor.position = edk::vec2f32((centerSize.width*-0.5f) + (this->text.getMapScaleWidth() * (this->cursorID-this->originID)),
                                             0.f
                                             );
        //Calculate the selection position inside the object
        if(this->selectionEnd>this->endID+1u){
            selection2 = this->endID+1u;
        }
        else{
            selection2 = this->selectionEnd;
        }
        if(this->selectionStart<this->originID){
            selection1 = this->originID;
        }
        else{
            selection1 = this->selectionStart;
        }
        if(selection2<selection1){
            selection2 = selection1;
        }
        //set the selection object position to be in the smaller character

        this->selection.position = edk::vec2f32((centerSize.width*-0.5f) + (this->text.getMapScaleWidth()) * (selection1 - this->originID),
                                                0.f
                                                );
        //set the selection size to the end be on the bigger character
        this->selection.size = edk::size2f32(this->text.getMapScaleWidth() * (selection2 - selection1),
                                             this->text.getMapScaleHeight()
                                             );
    }
    else{
        this->text.setScale(centerSize.height,centerSize.height);

        //save the cursor size
        this->cursorID = 0u;
        this->originID = 0u;
        this->endID = 0u;
        this->selectionMiddle = this->selectionStart = this->selectionEnd = 0u;
        this->selection.size = edk::size2f32(0.f,
                                             0.f
                                             );

        this->text.setPosition(edk::vec2f32(this->position.x + (centerSize.width*-0.5f) + (this->text.getMapScaleWidth()*0.5f),
                                            this->position.y
                                            ));
        this->selection.position = edk::vec2f32(this->position.x + (centerSize.width*-0.5f),
                                                this->position.y
                                                );
        //save the cursor size
        this->cursor.size = edk::size2f32(this->text.getMapScaleWidth() * edkGU2dCursorWidthPercent,this->text.getMapScaleHeight());
        this->cursor.position = edk::vec2f32( (centerSize.width*-0.5f),
                                              0.f
                                              );

        //test if it was modified
        if(this->cursor.size != this->saveCursorSize){
            //update the cursor animation
            this->cursor.animationSize.cleanAnimations();

            //create a size animation for the cursor
            this->cursor.animationSize.addNewInterpolationLine(0.f,this->cursor.size.width,this->cursor.size.height);
            this->cursor.animationSize.addNewInterpolationLine(edkGU2dCursorSecond,this->cursor.size.width,this->cursor.size.height);
            this->cursor.animationSize.addNewInterpolationLine(edkGU2dCursorSecond + 0.001f,0.f,0.f);
            this->cursor.animationSize.addNewInterpolationLine((edkGU2dCursorSecond*2.f) + 0.001f,0.f,0.f);
            this->cursor.animationSize.loopOn();

            //play the animation
            //this->cursor.animationSize.playForward();

            //save the cursorSize to the next comparison
            this->saveCursorSize = this->cursor.size;

            //if its selected. Then play the animation
            if(this->selected){
                this->cursor.animationSize.stop();
                this->cursor.animationSize.playForward();
            }
        }
    }
    //set the centerSelection to be clicked by the mouse
    this->selectionInside.position = 0.f;//this->position;
    this->selectionInside.size = centerSize;
}
void edk::gui2d::TextField2d::cleanTextVariables(edk::char8* newText){
    //clean the cursor
    this->cursorID = 0u;
    this->originID = 0u;
    this->selectionMiddle = this->selectionStart = this->selectionEnd = 0u;
    this->endID = 0u;
    this->textVec.clean();

    //test if need to write a new text
    if(newText){
        //filter the text

        //
        this->textVec.write(newText);
    }
}
//remove a character from the vec and update the text
bool edk::gui2d::TextField2d::removeCharacter(edk::uint32 position){
    bool ret = false;
    if(this->textVec.remove(position)){
        //get the string and write the text to the object text
        edk::char8* str = this->textVec.getStringWithLastSpace();
        if(str){
            //write the string
            if(edk::gui2d::ObjectGui2d::writeText(str)){
                //
                ret = true;

                //force update the text
                this->forceUpdate();
            }
            delete[] str;
        }
        return ret;
    }
    return false;
}
//update the selection values with the cursor
void edk::gui2d::TextField2d::updateSelection(){
    if(this->cursorID>this->selectionMiddle){
        this->selectionStart = this->selectionMiddle;
        this->selectionEnd = this->cursorID;
    }
    else{
        this->selectionEnd = this->selectionMiddle;
        this->selectionStart = this->cursorID;
    }
}

//load the button textures and meshes
bool edk::gui2d::TextField2d::load(){
    this->saveCursorSize = 0.f;
    if(edk::gui2d::ObjectGui2d::load()){
        //create the cursor object
        this->cursor.addMesh(&this->meshCursor);
        edk::shape::Mesh2D* mesh = &this->meshCursor;
        if(mesh){
            edk::shape::Rectangle2D rect;
            rect.setPivoToCenter();
            mesh->addPolygon(rect);
            mesh->setPolygonsColor(0,0,0,1);
        }
        mesh = this->selectionInside.newMesh();
        if(mesh){
            edk::shape::Rectangle2D rect;
            rect.setPivoToCenter();
            rect.setVertexPosition(0u,rect.getVertexPosition(0u).x,0.5f);
            rect.setVertexPosition(1u,rect.getVertexPosition(1u).x,-0.5f);
            mesh->addPolygon(rect);
            mesh->setPolygonsColor(0.5f,0.5f,1.f,0.5f);
        }
        mesh = this->selection.newMesh();
        if(mesh){
            edk::shape::Rectangle2D rect;
            rect.setVertexPosition(0u,rect.getVertexPosition(0u).x,0.5f);
            rect.setVertexPosition(1u,rect.getVertexPosition(1u).x,-0.5f);
            mesh->addPolygon(rect);
            mesh->setPolygonsColor(0.5f,0.5f,1.f,0.5f);
        }
        return true;
    }
    return false;
}
void edk::gui2d::TextField2d::unload(){
    //clean the cursor
    this->cursor.removeAllMesh();
    this->cursor.animationSize.cleanAnimations();
    this->selection.removeAllMesh();
    this->selectionInside.removeAllMesh();
    this->meshCursor.cleanPolygons();

    edk::gui2d::ObjectGui2d::unload();
}
void edk::gui2d::TextField2d::update(){
    //test if NOT have the text
    if(!this->text.haveText()){
        //create a text only with space
        this->cursorID = 0u;
        this->selectionMiddle = this->selectionStart = this->selectionEnd = 0u;
        this->forceUpdate();
    }


    edk::gui2d::ObjectGui2d::update();
    this->cursor.updateAnimations();
}

//enable and disable the background draw
void edk::gui2d::TextField2d::enableBackground(){
    this->drawBackground = true;
}
void edk::gui2d::TextField2d::disableBackground(){
    this->drawBackground = false;
}
bool edk::gui2d::TextField2d::haveDrawBackground(){
    return this->drawBackground;
}

//set the textLimit. Use zero to unlimited
void edk::gui2d::TextField2d::setCharacterLimit(edk::uint32 limit){
    this->textVec.setCharacterLimit(limit);
}

//set border size
bool edk::gui2d::TextField2d::setBorderSize(edk::float32 size){
    return this->obj.setBorderSize(size);
}
bool edk::gui2d::TextField2d::setStatus(edk::gui2d::gui2dTexture status){
    switch(status){
    case gui2dTextureNormal:
        return edk::gui2d::ObjectGui2d::setStatus(gui2dTextureNormal);
        break;
    case gui2dTextureUp:
        return edk::gui2d::ObjectGui2d::setStatus(gui2dTextureUp);
        break;
    case gui2dTexturePressed:
        return edk::gui2d::ObjectGui2d::setStatus(gui2dTextureNormal);
        break;
    case gui2dTexturePressedUp:
        return edk::gui2d::ObjectGui2d::setStatus(gui2dTextureNormal);
        break;
    case gui2dTextureSize:
        return edk::gui2d::ObjectGui2d::setStatus(gui2dTextureNormal);
        break;
    }
    return false;
}
//set the color of the font and cursor
void edk::gui2d::TextField2d::setFontColor(edk::color4f32 fontColor){
    this->fontColor=fontColor;
    this->meshCursor.setPolygonsColor(fontColor);
}
void edk::gui2d::TextField2d::setFontColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setFontColor(edk::color4f32(r,g,b,a));
}
//select functions
void edk::gui2d::TextField2d::select(){
    edk::gui2d::ObjectGui2d::select();
    this->cursor.animationSize.playForward();
}
void edk::gui2d::TextField2d::deselect(){
    edk::gui2d::ObjectGui2d::deselect();
    this->cursor.animationSize.stop();
}
edk::uint32 counterID = 0u;
//click to select an polygon inside the object
void edk::gui2d::TextField2d::clickStart(edk::uint32 name){
    edk::gui2d::ObjectGui2d::clickStart(name);
    if(name>= this->text.getMapSizeWidth()){
        this->cursorID = this->endID+1u;
        this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;
        //force update
        this->forceUpdate();
        this->cursor.animationSize.stop();
        this->cursor.animationSize.playForward();
    }
    else{
        if(name) name--;
        if(name>=this->originID && name<=this->endID+1u){
            this->cursorID = name;
            this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;
            //force update
            this->forceUpdate();
            this->cursor.animationSize.stop();
            this->cursor.animationSize.playForward();
        }
    }
}
void edk::gui2d::TextField2d::clickMove(edk::uint32 name,bool mouseInside){
    edk::gui2d::ObjectGui2d::clickMove(name,mouseInside);
}
void edk::gui2d::TextField2d::clickEnd(edk::uint32 name,bool mouseInside,bool doubleClick){
    edk::gui2d::ObjectGui2d::clickEnd(name,mouseInside,doubleClick);
    //select all text
    if(doubleClick)
        this->selectAll();
}

//set the case
void edk::gui2d::TextField2d::setUpperAndLowerCase(){
    this->textVec.setCaseInput(edk::gui2d::upperAndLowerCase);
}
void edk::gui2d::TextField2d::setUpperCase(){
    this->textVec.setCaseInput(edk::gui2d::upperCase);
}
void edk::gui2d::TextField2d::setLowerCase(){
    this->textVec.setCaseInput(edk::gui2d::lowerCase);
}

//cursor functions
void edk::gui2d::TextField2d::incrementCursor(){
    if(this->textVec.getSize()){
        edk::uint32 mapSize = this->text.getMapSizeWidth();
        if(mapSize)mapSize--;
        if(this->cursorID < mapSize){
            this->cursorID++;
            this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;
            //force update
            this->forceUpdate();
            this->cursor.animationSize.stop();
            this->cursor.animationSize.playForward();
        }
    }
}
void edk::gui2d::TextField2d::incrementCursorWithSelect(){
    if(this->textVec.getSize()){
        edk::uint32 mapSize = this->text.getMapSizeWidth();
        if(mapSize)mapSize--;
        if(this->cursorID < mapSize){
            this->cursorID++;
            this->updateSelection();
            //force update
            this->forceUpdate();
            this->cursor.animationSize.stop();
            this->cursor.animationSize.playForward();
        }
    }
}
void edk::gui2d::TextField2d::decrementCursor(){
    if(this->cursorID){
        this->cursorID--;
        this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;
        //force update
        this->forceUpdate();
        this->cursor.animationSize.stop();
        this->cursor.animationSize.playForward();
    }
}
void edk::gui2d::TextField2d::decrementCursorWithSelect(){
    if(this->cursorID){
        this->cursorID--;
        this->updateSelection();
        //force update
        this->forceUpdate();
        this->cursor.animationSize.stop();
        this->cursor.animationSize.playForward();
    }
}
void edk::gui2d::TextField2d::moveCursorToEnd(){
    edk::uint32 mapSize = this->text.getMapSizeWidth();
    if(mapSize)mapSize--;
    if(this->cursorID < mapSize){
        this->cursorID = mapSize;
        this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;
        //force update
        this->forceUpdate();
        this->cursor.animationSize.stop();
        this->cursor.animationSize.playForward();
    }
}
void edk::gui2d::TextField2d::moveCursorToEndWithSelect(){
    edk::uint32 mapSize = this->text.getMapSizeWidth();
    if(mapSize)mapSize--;
    if(this->cursorID < mapSize){
        this->cursorID = mapSize;
        this->updateSelection();
        //force update
        this->forceUpdate();
        this->cursor.animationSize.stop();
        this->cursor.animationSize.playForward();
    }
}
void edk::gui2d::TextField2d::moveCursorToStart(){
    if(this->cursorID){
        this->cursorID = 0u;
        this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;
        //force update
        this->forceUpdate();
        this->cursor.animationSize.stop();
        this->cursor.animationSize.playForward();
    }
}
void edk::gui2d::TextField2d::moveCursorToStartWithSelect(){
    if(this->cursorID){
        this->cursorID = 0u;
        this->updateSelection();
        //force update
        this->forceUpdate();
        this->cursor.animationSize.stop();
        this->cursor.animationSize.playForward();
    }
}
void edk::gui2d::TextField2d::selectAll(){
    this->cursorID = this->text.getMapSizeWidth();
    if(this->cursorID){this->cursorID--;
        this->selectionEnd = this->cursorID;
        this->selectionStart=0u;
    }
}
//add some character
bool edk::gui2d::TextField2d::addCharacter(edk::char8 c){
    if(this->selectionStart!=this->selectionEnd){
        this->deleteCharacter();
    }
    //add the character
    if(this->textVec.add((edk::char32)edk::BinaryConverter::joinBytesLittleEndian(0u,0u,0u,c),this->cursorID)){
        //force update
        this->forceUpdate();
        this->cursor.animationSize.stop();
        this->cursor.animationSize.playForward();
        edk::char8* str = this->textVec.getStringWithLastSpace();
        if(str){
            this->cursorID++;
            this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;
            edk::gui2d::ObjectGui2d::writeText(str);
            delete[] str;
            return true;
        }
        else{
            edk::gui2d::ObjectGui2d::cleanText();
        }
    }
    return false;
}
bool edk::gui2d::TextField2d::addString(edk::char8* str){
    edk::uint32 lenght=0u;
    if((lenght = this->textVec.add(str,this->cursorID))){
        this->cursorID+=lenght;
        this->forceUpdate();
        this->cursor.animationSize.stop();
        this->cursor.animationSize.playForward();
        edk::char8* str = this->textVec.getStringWithLastSpace();
        if(str){
            this->cursorID++;
            this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;
            edk::gui2d::ObjectGui2d::writeText(str);
            delete[] str;
            return true;
        }
        else{
            edk::gui2d::ObjectGui2d::cleanText();
        }
        return true;
    }
    return false;
}
bool edk::gui2d::TextField2d::addString(const edk::char8* str){
    return this->addString((edk::char8*) str);
}
//add characters to the filters
bool edk::gui2d::TextField2d::addCharacterFilterIn(edk::char8 c){
    return this->textVec.addFilterIn(c);
}
bool edk::gui2d::TextField2d::addStringFilterIn(edk::char8* str){
    if(str){
        return this->textVec.addFilterIn(str);
    }
    return false;
}
bool edk::gui2d::TextField2d::addStringFilterIn(const edk::char8* str){
    //
    return this->addStringFilterIn((edk::char8*) str);
}
bool edk::gui2d::TextField2d::addCharacterFilterOut(edk::char8 c){
    return this->textVec.addFilterOut(c);
}
bool edk::gui2d::TextField2d::addStringFilterOut(edk::char8* str){
    if(str){
        return this->textVec.addFilterOut(str);
    }
    return false;
}
bool edk::gui2d::TextField2d::addStringFilterOut(const edk::char8* str){
    //
    return this->addStringFilterOut((edk::char8*) str);
}
void edk::gui2d::TextField2d::cleanFilterIn(){
    this->textVec.cleanFilterIn();
}
void edk::gui2d::TextField2d::cleanFilterOut(){
    this->textVec.cleanFilterOut();
}

//write text to clean the originID and cursorID
bool edk::gui2d::TextField2d::writeText(const char* text){
    bool ret = false;
    this->cleanTextVariables((edk::char8*)text);
    //get the string
    edk::char8* str = this->textVec.getStringWithLastSpace();
    if(str){
        if(edk::gui2d::ObjectGui2d::writeText(str)){
            ret = true;
        }
        delete[] str;
        return ret;
    }
    this->cleanTextVariables(NULL);
    return false;
}
bool edk::gui2d::TextField2d::writeText(edk::char8* text){
    bool ret = false;
    this->cleanTextVariables(text);
    //get the string
    edk::char8* str = this->textVec.getStringWithLastSpace();
    if(str){
        if(edk::gui2d::ObjectGui2d::writeText(str)){
            ret = true;
        }
        delete[] str;
        return ret;
    }
    this->cleanTextVariables(NULL);
    return false;
}
bool edk::gui2d::TextField2d::writeText(const char* text,edk::float32 scaleWidth,edk::float32 scaleHeight){
    bool ret = false;
    this->cleanTextVariables((edk::char8*)text);
    //get the string
    edk::char8* str = this->textVec.getStringWithLastSpace();
    if(str){
        if(edk::gui2d::ObjectGui2d::writeText(str,scaleWidth,scaleHeight)){
            ret = true;
        }
        delete[] str;
        return ret;
    }
    this->cleanTextVariables(NULL);
    return false;
}
bool edk::gui2d::TextField2d::writeText(edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight){
    bool ret = false;
    this->cleanTextVariables(text);
    //get the string
    edk::char8* str = this->textVec.getStringWithLastSpace();
    if(str){
        if(edk::gui2d::ObjectGui2d::writeText(str,scaleWidth,scaleHeight)){
            ret = true;
        }
        delete[] str;
        return ret;
    }
    this->cleanTextVariables(NULL);
    return false;
}
bool edk::gui2d::TextField2d::writeText(const char* text,edk::size2f32 scale){
    bool ret = false;
    this->cleanTextVariables((edk::char8*)text);
    //get the string
    edk::char8* str = this->textVec.getStringWithLastSpace();
    if(str){
        if(edk::gui2d::ObjectGui2d::writeText(str,scale)){
            ret = true;
        }
        delete[] str;
        return ret;
    }
    this->cleanTextVariables(NULL);
    return false;
}
bool edk::gui2d::TextField2d::writeText(edk::char8* text,edk::size2f32 scale){
    bool ret = false;
    this->cleanTextVariables(text);
    //get the string
    edk::char8* str = this->textVec.getStringWithLastSpace();
    if(str){
        if(edk::gui2d::ObjectGui2d::writeText(str,scale)){
            ret = true;
        }
        delete[] str;
        return ret;
    }
    this->cleanTextVariables(NULL);
    return false;
}
void edk::gui2d::TextField2d::cleanText(){
    this->cleanTextVariables(NULL);
    return edk::gui2d::ObjectGui2d::cleanText();
}
//remove or delete characters
void edk::gui2d::TextField2d::deleteCharacter(){
    //test if have something selected
    if(this->selectionStart!=this->selectionEnd){
        //
        this->cursorID = this->selectionStart;
        this->textVec.remove(this->cursorID,this->selectionEnd - this->selectionStart);
    }
    else{
        this->textVec.remove(this->cursorID);
    }
    edk::char8* str = this->textVec.getStringWithLastSpace();
    if(str){
        edk::gui2d::ObjectGui2d::writeText(str);
        delete[] str;
    }
    else{
        edk::gui2d::ObjectGui2d::cleanText();
    }
    this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;
    //force update
    this->forceUpdate();
    this->cursor.animationSize.stop();
    this->cursor.animationSize.playForward();
}
void edk::gui2d::TextField2d::removeCharacter(){
    bool remove = false;
    //test if have something selected
    if(this->selectionStart!=this->selectionEnd){
        //
        this->cursorID = this->selectionStart;
        this->textVec.remove(this->cursorID,this->selectionEnd - this->selectionStart);
        remove = true;
    }
    else{
        if(this->cursorID){
            this->textVec.remove(this->cursorID-1u);
            this->cursorID--;
            remove = true;
        }
    }
    if(remove){
        edk::char8* str = this->textVec.getStringWithLastSpace();
        if(str){
            edk::gui2d::ObjectGui2d::writeText(str);
            delete[] str;
        }
        else{
            this->cursorID=0u;
            edk::gui2d::ObjectGui2d::cleanText();
        }
    }
    this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;
    //force update
    this->forceUpdate();
    this->cursor.animationSize.stop();
    this->cursor.animationSize.playForward();
}
//get string writed
edk::char8* edk::gui2d::TextField2d::getText(){
    return this->textVec.getString();
}
//get string size
edk::uint32 edk::gui2d::TextField2d::getTextSize(){
    return this->textVec.getSize();
}

//draw the button
void edk::gui2d::TextField2d::draw(){
    this->drawStart();
    edk::GU::guEnable(GU_LIGHTING);

    if(this->drawBackground){
        switch(this->status){
        case edk::gui2d::gui2dTexture::gui2dTextureUp:
            //draw the border
            this->obj.drawUp();
            break;
        case edk::gui2d::gui2dTexture::gui2dTexturePressed:
            //draw the border
            this->obj.drawPressed();
            break;
        case edk::gui2d::gui2dTexture::gui2dTexturePressedUp:
            //draw the border
            this->obj.drawPressedUp();
            break;
        case edk::gui2d::gui2dTexture::gui2dTextureNormal:
        case edk::gui2d::gui2dTexture::gui2dTextureSize:
        default:
            //draw the border
            this->obj.drawNormal();
            break;
        }
    }
    edk::GU::guDisable(GU_LIGHTING);

    //test if have the texture
    if(this->sprite.material.getTexture(this->status)){
        //draw the srite on the button
        this->sprite.drawOneTexture(this->status);
    }

    if(this->text.haveText() && this->drawText){
        if(this->isSelected()){
            //draw the selection
            this->selection.drawWithoutMaterial();

            this->text.draw(this->fontColor);
        }
        else{
            this->text.draw(this->fontColor);
        }
    }

    //draw the cursor
    if(this->isSelected()){
        this->meshCursor.setPolygonsColor(fontColor);
        this->cursor.drawWithoutMaterial();
    }

    this->drawEnd();
}
void edk::gui2d::TextField2d::drawSelection(){
    this->drawStart();
    //draw the border
    this->obj.drawSelection();

    if(this->text.haveText() && this->drawText){
        //first draw the selectionInside
        edk::GU::guPushName(this->text.getMapSizeWidth());
        this->selectionInside.drawWithoutMaterial();
        edk::GU::guPopName();
        //
        this->text.setPosition(this->text.getPositionX() - this->text.getMapScaleWidth()*0.5,
                               this->text.getPositionY()
                               );
        this->text.setLast(this->endID + 1u);
        this->text.drawSelection();
        this->text.setPosition(this->text.getPositionX() + this->text.getMapScaleWidth()*0.5,
                               this->text.getPositionY()
                               );
        this->text.setLast(this->endID);
    }
    //
    this->drawEnd();
}
