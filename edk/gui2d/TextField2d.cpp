#include "TextField2d.h"

/*
TextField2d - TextField2d for the GUI 2D library
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

static edk::uint32 fieldBorderSize = 1008u;
static edk::char8 fieldBorderName[16] = "fieldBorder.png";
static edk::uchar8 fieldBorder[1008] = {
137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,38,0,0 \
,0,38,8,6,0,0,0,168,61,233,174,0,0,0,6,98,75,71,68,0,0 \
,0,0,0,0,249,67,187,127,0,0,0,9,112,72,89,115,0,0,14,196,0 \
,0,14,196,1,149,43,14,27,0,0,0,7,116,73,77,69,7,227,10,30,20 \
,16,20,237,69,54,1,0,0,3,125,73,68,65,84,88,195,205,152,61,143,27 \
,85,20,134,159,25,175,21,75,227,213,186,24,17,103,99,39,66,91,224,194,21 \
,40,145,32,86,164,35,65,73,40,18,16,43,16,84,192,143,160,160,1,33,126 \
,2,16,4,13,225,67,249,80,72,13,87,144,149,88,145,214,197,80,24,65,198 \
,108,38,210,20,94,217,150,188,25,123,135,130,123,205,205,68,81,108,175,63,56 \
,205,232,158,145,117,30,207,61,247,227,125,29,102,8,165,212,9,224,2,112,30 \
,168,0,199,245,51,5,218,64,164,159,59,192,15,34,114,111,218,26,206,20,48 \
,5,224,61,96,27,56,3,184,19,254,244,16,184,3,124,13,124,38,34,7,115 \
,1,83,74,185,192,69,224,19,224,105,142,22,33,240,33,240,133,136,140,102,6 \
,83,74,157,6,174,3,207,218,249,92,46,135,239,251,148,74,37,138,197,34,133 \
,66,129,181,181,53,0,134,195,33,131,193,128,94,175,71,167,211,33,142,99,70 \
,163,71,24,238,0,151,68,228,238,212,96,74,169,231,129,27,186,127,0,240,60 \
,143,74,165,66,185,92,198,113,38,235,130,52,77,137,162,136,118,187,77,191,223 \
,183,95,197,26,238,231,137,193,148,82,219,192,151,192,49,147,219,218,218,162,90 \
,173,30,109,30,195,144,86,171,101,167,14,128,183,69,228,187,39,130,41,165,206 \
,1,63,26,40,207,243,168,213,106,172,175,175,51,143,232,118,187,4,65,96,127 \
,189,7,192,75,34,242,203,99,193,116,79,253,6,60,5,176,177,177,65,189,94 \
,39,159,207,51,207,72,146,132,102,179,201,254,254,190,73,221,7,206,218,61,231 \
,102,86,223,53,3,229,121,222,66,160,0,242,249,60,245,122,29,207,243,76,234 \
,56,112,85,51,60,12,6,188,9,60,103,6,181,90,109,33,80,54,92,173,86 \
,179,83,103,128,55,30,154,74,189,121,254,14,156,154,87,163,207,184,32,254,2 \
,158,17,145,3,243,197,222,53,80,158,231,45,13,10,160,90,173,218,83,122,90 \
,179,140,167,114,252,9,43,149,10,203,142,76,205,109,0,71,41,181,169,15,92 \
,39,151,203,209,104,52,38,222,60,231,21,105,154,178,179,179,99,78,136,67,160 \
,226,2,175,152,94,243,125,127,233,80,0,142,227,224,251,190,189,32,47,184,192 \
,57,147,41,149,74,172,42,50,181,27,46,112,210,140,138,197,226,202,192,50,181 \
,55,93,96,211,140,10,133,194,202,192,50,181,79,186,192,9,51,50,87,151,85 \
,68,166,246,166,203,255,52,92,96,124,31,31,14,135,43,3,201,212,110,187,192 \
,158,25,13,6,131,149,129,101,106,239,185,192,223,102,212,235,245,86,6,150,169 \
,189,231,2,227,11,90,167,211,89,25,88,166,246,109,23,184,169,143,1,226,56 \
,38,77,211,165,67,165,105,74,28,199,182,220,187,229,138,200,125,125,107,101,52 \
,26,17,69,209,210,193,162,40,178,149,212,175,34,18,153,237,226,202,120,57,180 \
,219,75,7,203,212,252,198,190,246,124,10,252,1,208,239,247,9,195,112,105,80 \
,97,24,218,194,228,79,224,242,24,76,68,30,0,31,152,183,173,86,139,110,183 \
,187,112,168,110,183,155,149,115,239,27,11,193,222,249,175,104,133,12,64,16,4 \
,36,73,178,48,168,36,73,8,130,192,78,237,2,223,62,34,70,68,228,16,184 \
,164,165,20,253,126,159,102,179,185,16,56,35,223,172,41,140,128,215,52,195,99 \
,5,239,11,192,79,75,22,188,47,138,200,237,73,44,130,215,129,175,150,100,17 \
,188,37,34,223,79,107,170,92,7,202,11,52,85,46,102,173,129,73,109,168,83 \
,192,85,45,70,231,105,67,237,2,175,138,72,251,40,198,157,163,23,197,199,192 \
,214,17,91,236,46,240,17,112,217,110,244,153,192,44,192,99,192,59,90,131,158 \
,101,58,171,115,87,111,71,159,235,61,243,201,202,105,150,191,173,205,225,151,129 \
,6,255,154,194,101,160,106,217,153,247,248,207,28,190,37,34,83,31,192,255,0 \
,100,90,121,51,111,35,8,244,0,0,0,0,73,69,78,68,174,66,96,130
};

edk::gui2d::TextField2d::TextVec::TextVec(){
    //
    this->caseInput = edk::gui2d::upperAndLowerCase;edkEnd();
    this->limit = 0u;edkEnd();
}
edk::gui2d::TextField2d::TextVec::~TextVec(){
    //
    this->cleanFilterIn();edkEnd();
    this->cleanFilterOut();edkEnd();
}
edk::uint32 edk::gui2d::TextField2d::TextVec::sizeOfString(){
    edk::uint32 size = this->vec.size();edkEnd();
    edk::uint32 ret = size;edkEnd();
    edk::uint32 c=0u;
    for(edk::uint32 i = 0u;i<size;i++){
        //get the 32 bits character
        c = this->vec.get(i);edkEnd();
        if(edk::BinaryConverter::getByteLittleEndian(c,1u)){
            ret++;edkEnd();
            if(edk::BinaryConverter::getByteLittleEndian(c,2u)){
                ret++;edkEnd();
                if(edk::BinaryConverter::getByteLittleEndian(c,3u)){
                    ret++;edkEnd();
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
        return this->filterIn.haveElement(c);edkEnd();
    }
    else{
        //else test if have something in filterOut
        if(this->filterOut.size()){
            //test if can't add the c
            return !this->filterOut.haveElement(c);edkEnd();
        }
    }
    //else return true
    return true;
}
void edk::gui2d::TextField2d::TextVec::clean(){
    this->vec.clean();edkEnd();
}
bool edk::gui2d::TextField2d::TextVec::write(edk::char8* str){
    this->clean();edkEnd();
    //test the string
    if(str){
        //get the strng lenght
        edk::uint32 lenght = edk::String::strSize(str);edkEnd();
        edk::char32 c;edkEnd();
        edk::uint8 increment=0u;
        if(lenght){
            //populate the vector
            for(edk::uint32 i=0u;i<lenght;){
                if(str[i]==13
                        ||
                        str[i]==10
                        ||
                        str[i]=='\0'
                        ){
                    break;
                }
                c = edk::String::utf8ToUint32(&str[i]);edkEnd();
                increment=edk::String::utf8Bytes(&str[i]);edkEnd();
                if(increment){
                    i+=increment;edkEnd();

                    //test if the lenght exceede the limit
                    if(this->vec.size()>=this->limit && this->limit){
                        return true;
                    }

                    //test the case
                    switch(this->caseInput){
                    case edk::gui2d::upperAndLowerCase:
                        break;
                    case edk::gui2d::upperCase:
                        if(c>='a' && c<='z'){
                            c+='A'-'a';edkEnd();
                        }
                        break;
                    case edk::gui2d::lowerCase:
                        if(c>='A' && c<='Z'){
                            c-='A'-'a';edkEnd();
                        }
                        break;
                    }

                    if(this->canGetIt(c)){
                        this->vec.pushBack(c);edkEnd();
                    }
                }
                else{
                    edkEnd();
                    return false;
                }
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
        edk::uint32 lenght = edk::String::strSize(str);edkEnd();
        edk::char32 c;edkEnd();
        edk::uint32 ret = 0u;edkEnd();
        edk::uint8 increment=0u;
        if(lenght){
            //populate the vector
            for(edk::uint32 i=0u;i<lenght;){
                if(str[i]==13
                        ||
                        str[i]==10
                        ||
                        str[i]=='\0'
                        ){
                    break;
                }
                c = edk::String::utf8ToUint32(&str[i]);edkEnd();
                increment=edk::String::utf8Bytes(&str[i]);edkEnd();
                if(increment){
                    i+=increment;edkEnd();

                    //test the case
                    switch(this->caseInput){
                    case edk::gui2d::upperAndLowerCase:
                        break;
                    case edk::gui2d::upperCase:
                        if(c>='a' && c<='z'){
                            c+='A'-'a';edkEnd();
                        }
                        break;
                    case edk::gui2d::lowerCase:
                        if(c>='A' && c<='Z'){
                            c-='A'-'a';edkEnd();
                        }
                        break;
                    }

                    if(!this->add(c,position)){
                        return 0u;edkEnd();
                    }
                    position++;edkEnd();
                    ret++;edkEnd();
                }
                else{
                    edkEnd();
                    return false;
                }
            }
            return ret;
        }
    }
    return 0u;edkEnd();
}
edk::uint32 edk::gui2d::TextField2d::TextVec::add(edk::char8 c,edk::uint32 position){
    return add((edk::char32) c,position);edkEnd();
}
edk::uint32 edk::gui2d::TextField2d::TextVec::add(edk::char16 c,edk::uint32 position){
    return add((edk::char32) c,position);edkEnd();
}
edk::uint32 edk::gui2d::TextField2d::TextVec::add(edk::char32 c,edk::uint32 position){
    edk::uint32 size = this->vec.size();edkEnd();
    //test if the lenght exceede the limit
    if(size>=this->limit && this->limit){
        return 0u;edkEnd();
    }
    //test if have the position
    if(position<=size && this->canGetIt(c)){
        //test the case
        switch(this->caseInput){
        case edk::gui2d::upperAndLowerCase:
            break;
        case edk::gui2d::upperCase:
            if(c>='a' && c<='z'){
                c+='A'-'a';edkEnd();
            }
            break;
        case edk::gui2d::lowerCase:
            if(c>='A' && c<='Z'){
                c-='A'-'a';edkEnd();
            }
            break;
        }
        this->vec.pushBack(c);edkEnd();
        if(size<this->vec.size()){
            //
            if(position<size){
                this->vec.bringPositionTo(size,position);edkEnd();
            }
            return 1u;edkEnd();
        }
    }
    return 0u;edkEnd();
}

bool edk::gui2d::TextField2d::TextVec::remove(edk::uint32 position){
    edk::uint32 size = this->vec.size();edkEnd();
    //test if have the position
    if(position<size){
        size--;edkEnd();
        //move the position to the end
        this->vec.bringPositionTo(position,size);edkEnd();
        this->vec.remove(size);edkEnd();
        return true;
    }
    return false;
}
bool edk::gui2d::TextField2d::TextVec::remove(edk::uint32 position,edk::uint32 times){
    bool ret=true;edkEnd();
    for(edk::uint32 i=0u;i<times;i++){
        ret = this->remove(position);edkEnd();
    }
    return ret;
}
edk::char8* edk::gui2d::TextField2d::TextVec::getString(){
    edk::uint32 size = this->sizeOfString();edkEnd();
    //test if have some characters
    if(size){
        //create the new string
        edk::char8* str = new edk::char8[size+1u];edkEnd();
        if(str){
            str[size]='\0';edkEnd();
            edk::uint32 position = 0u;edkEnd();
            edk::char8* p = str;edkEnd();
            edk::uint32 c = 0u;edkEnd();
            //copy the characters
            for(edk::uint32 i=0u;i<size;i++){
                //
                c = this->vec.get(position);edkEnd();
                if(!c){
                    delete[] str;edkEnd();
                    return NULL;
                }
                //test if is a special character
                if(edk::BinaryConverter::getByteLittleEndian(c,1u)){
                    i++;edkEnd();
                    if(edk::BinaryConverter::getByteLittleEndian(c,2u)){
                        i++;edkEnd();
                        if(edk::BinaryConverter::getByteLittleEndian(c,3u)){
                            i++;edkEnd();
                            //add the value
                            *p = edk::BinaryConverter::getByteLittleEndian(c,3u);edkEnd();
                            p++;edkEnd();
                        }
                        //add the value
                        *p = edk::BinaryConverter::getByteLittleEndian(c,2u);edkEnd();
                        p++;edkEnd();
                    }
                    //add the value
                    *p = edk::BinaryConverter::getByteLittleEndian(c,1u);edkEnd();
                    p++;edkEnd();
                }
                *p = edk::BinaryConverter::getByteLittleEndian(c,0u);edkEnd();
                p++;edkEnd();
                position++;edkEnd();
            }
            return str;edkEnd();
        }
    }
    return NULL;
}
edk::char8* edk::gui2d::TextField2d::TextVec::getStringWithLastSpace(){
    edk::uint32 size = this->sizeOfString();edkEnd();
    //test if have some characters
    if(size){
        //create the new string
        edk::char8* str = new edk::char8[size+2u];edkEnd();
        if(str){
            str[size+1u]='\0';edkEnd();
            str[size]=' ';edkEnd();
            edk::uint32 position = 0u;edkEnd();
            edk::char8* p = str;edkEnd();
            edk::uint32 c = 0u;edkEnd();
            //copy the characters
            for(edk::uint32 i=0u;i<size;i++){
                //
                c = this->vec.get(position);edkEnd();
                if(!c){
                    delete[] str;edkEnd();
                    return NULL;
                }
                //test if is a special character
                if(edk::BinaryConverter::getByteLittleEndian(c,1u)){
                    i++;edkEnd();
                    if(edk::BinaryConverter::getByteLittleEndian(c,2u)){
                        i++;edkEnd();
                        if(edk::BinaryConverter::getByteLittleEndian(c,3u)){
                            i++;edkEnd();
                            //add the value
                            *p = edk::BinaryConverter::getByteLittleEndian(c,3u);edkEnd();
                            p++;edkEnd();
                        }
                        //add the value
                        *p = edk::BinaryConverter::getByteLittleEndian(c,2u);edkEnd();
                        p++;edkEnd();
                    }
                    //add the value
                    *p = edk::BinaryConverter::getByteLittleEndian(c,1u);edkEnd();
                    p++;edkEnd();
                }
                *p = edk::BinaryConverter::getByteLittleEndian(c,0u);edkEnd();
                p++;edkEnd();
                position++;edkEnd();
            }
            return str;edkEnd();
        }
    }
    return NULL;
}
edk::uint32 edk::gui2d::TextField2d::TextVec::getSize(){
    return this->vec.size();edkEnd();
}
//add a character to the filter
bool edk::gui2d::TextField2d::TextVec::addFilterIn(edk::char8* str){
    //test the string
    if(str){
        //get the strng lenght
        edk::uint32 lenght = edk::String::strSize(str);edkEnd();
        edk::char32 c;edkEnd();
        edk::uint32 increment;edkEnd();
        bool ret = false;edkEnd();
        if(lenght){
            //populate the vector
            for(edk::uint32 i=0u;i<lenght;){
                if(str[i]==13
                        ||
                        str[i]==10
                        ||
                        str[i]=='\0'
                        ){
                    break;
                }
                c = edk::String::utf8ToUint32(&str[i]);edkEnd();
                increment=edk::String::utf8Bytes(&str[i]);edkEnd();
                i+=increment;edkEnd();
                if(increment){
                    //test the case
                    switch(this->caseInput){
                    case edk::gui2d::upperAndLowerCase:
                        break;
                    case edk::gui2d::upperCase:
                        if(c>='a' && c<='z'){
                            c+='A'-'a';edkEnd();
                        }
                        break;
                    case edk::gui2d::lowerCase:
                        if(c>='A' && c<='Z'){
                            c-='A'-'a';edkEnd();
                        }
                        break;
                    }

                    if(!this->addFilterIn(c)){
                        return false;
                    }
                    ret = true;edkEnd();
                }
                else{
                    edkEnd();
                    return false;
                }
            }
            return ret;
        }
    }
    return false;
}
bool edk::gui2d::TextField2d::TextVec::addFilterIn(edk::char8 c){
    return this->addFilterIn((edk::char32)c);edkEnd();
}
bool edk::gui2d::TextField2d::TextVec::addFilterIn(edk::char16 c){
    return this->addFilterIn((edk::char32)c);edkEnd();
}
bool edk::gui2d::TextField2d::TextVec::addFilterIn(edk::char32 c){
    return this->filterIn.add(c);edkEnd();
}
void edk::gui2d::TextField2d::TextVec::cleanFilterIn(){
    this->filterIn.clean();edkEnd();
}
bool edk::gui2d::TextField2d::TextVec::addFilterOut(edk::char8* str){
    //test the string
    if(str){
        //get the strng lenght
        edk::uint32 lenght = edk::String::strSize(str);edkEnd();
        edk::char32 c;edkEnd();
        edk::uint32 increment;edkEnd();
        bool ret = false;edkEnd();
        if(lenght){
            //populate the vector
            for(edk::uint32 i=0u;i<lenght;){
                if(str[i]==13
                        ||
                        str[i]==10
                        ||
                        str[i]=='\0'
                        ){
                    break;
                }

                c = edk::String::utf8ToUint32(&str[i]);edkEnd();
                increment=edk::String::utf8Bytes(&str[i]);edkEnd();
                i+=increment;edkEnd();
                if(increment){
                    //test the case
                    switch(this->caseInput){
                    case edk::gui2d::upperAndLowerCase:
                        break;
                    case edk::gui2d::upperCase:
                        if(c>='a' && c<='z'){
                            c+='A'-'a';edkEnd();
                        }
                        break;
                    case edk::gui2d::lowerCase:
                        if(c>='A' && c<='Z'){
                            c-='A'-'a';edkEnd();
                        }
                        break;
                    }

                    if(!this->addFilterOut(c)){
                        return false;
                    }
                    ret = true;edkEnd();
                }
                else{
                    edkEnd();
                    return false;
                }
            }
            return ret;
        }
    }
    return false;
}
bool edk::gui2d::TextField2d::TextVec::addFilterOut(edk::char8 c){
    return this->addFilterOut((edk::char32)c);edkEnd();
}
bool edk::gui2d::TextField2d::TextVec::addFilterOut(edk::char16 c){
    return this->addFilterOut((edk::char32)c);edkEnd();
}
bool edk::gui2d::TextField2d::TextVec::addFilterOut(edk::char32 c){
    return this->filterOut.add(c);edkEnd();
}
void edk::gui2d::TextField2d::TextVec::cleanFilterOut(){
    this->filterOut.clean();edkEnd();
}
//set the textLimit. Use zero to unlimited
void edk::gui2d::TextField2d::TextVec::setCharacterLimit(edk::uint32 limit){
    this->limit = limit;edkEnd();
}
//set the caseInput
void edk::gui2d::TextField2d::TextVec::setCaseInput(edk::gui2d::Case caseInput){
    this->caseInput = caseInput;edkEnd();
}

edk::gui2d::TextField2d::TextField2d(){
    //
    this->fontColor = edk::color4f32(0,0,0,1);edkEnd();
    this->drawBackground=true;edkEnd();
    this->obj.setBorderSize(0.25f);edkEnd();
    this->originID = 0u;edkEnd();
    this->cursorID = 0u;edkEnd();
    this->endID=0u;
    this->selectionMiddle = this->selectionStart = this->selectionEnd = 0u;edkEnd();
}
edk::gui2d::TextField2d::~TextField2d(){
    //
    this->unload();edkEnd();
}

//get the type
edk::gui2d::gui2dTypes edk::gui2d::TextField2d::getType(){
    return edk::gui2d::gui2dTypeTextField;edkEnd();
}
//clean all characters
void edk::gui2d::TextField2d::cleanCharacters(){
    this->textVec.clean();edkEnd();
    this->originID = 0u;edkEnd();
    this->cursorID = 0u;edkEnd();
    this->endID=0u;
    this->selectionMiddle = this->selectionStart = this->selectionEnd = 0u;edkEnd();
}

void edk::gui2d::TextField2d::updateTextSize(edk::size2f32 sizeText,edk::size2f32 centerSize,edk::size2ui32 mapSize){
    edk::uint32 mapWidth = this->text.getMapSizeWidth();edkEnd();
    if(mapWidth){
        mapWidth--;edkEnd();
    }

    if(mapWidth){
        this->text.setScale((centerSize.height * (sizeText.width/sizeText.height))/(edk::float32)mapSize.width,
                            centerSize.height
                            );edkEnd();
        //save the cursor size
        this->cursor.size = edk::size2f32(this->text.getMapScaleWidth() * edkGU2dCursorWidthPercent,this->text.getMapScaleHeight());edkEnd();

        //test if it was modified
        if(this->cursor.size != this->saveCursorSize){
            //update the cursor animation
            this->cursor.animationSize.cleanAnimations();edkEnd();

            //create a size animation for the cursor
            this->cursor.animationSize.addNewInterpolationLine(0.f,this->cursor.size.width,this->cursor.size.height);edkEnd();
            this->cursor.animationSize.addNewInterpolationLine(edkGU2dCursorSecond,this->cursor.size.width,this->cursor.size.height);edkEnd();
            this->cursor.animationSize.addNewInterpolationLine(edkGU2dCursorSecond + 0.001f,0.f,0.f);edkEnd();
            this->cursor.animationSize.addNewInterpolationLine((edkGU2dCursorSecond*2.f) + 0.001f,0.f,0.f);edkEnd();
            this->cursor.animationSize.loopOn();edkEnd();

            //save the cursorSize to the next comparison
            this->saveCursorSize = this->cursor.size;edkEnd();

            //if its selected. Then play the animation
            if(this->selected){
                this->cursor.animationSize.stop();edkEnd();
                this->cursor.animationSize.playForward();edkEnd();
            }
        }

        //get the size of characters inside the field
        edk::uint32 chSize = (edk::uint32)(centerSize.width/this->text.getMapScaleWidth());edkEnd();
        edk::uint32 selection1=0u,selection2=0u;

        if(this->cursorID>mapWidth){
            //
            this->cursorID=mapWidth;edkEnd();
        }

        //test if the origin can be drawed
        if(mapWidth >= chSize){
            //test if the cursor in outsize the origin and last
            if(this->cursorID < this->originID
                    ){
                this->originID = this->cursorID;edkEnd();
            }
            else if(this->cursorID > this->originID+chSize
                    ){
                this->originID = this->cursorID - chSize;edkEnd();
            }

            if(this->originID > mapWidth - chSize){
                this->originID = mapWidth - chSize;edkEnd();
            }
            //set the size
            this->endID = this->originID + chSize - 1u;edkEnd();
            this->text.setOriginAndLast(this->originID,this->originID + chSize - 1u);edkEnd();
        }
        else{
            this->originID = 0u;edkEnd();
            this->endID = mapWidth-1u;edkEnd();
            this->text.setOriginAndLast(this->originID,mapWidth-1u);edkEnd();
        }

        //set the text position with the origin ID
        this->text.setPosition((centerSize.width*-0.5f) + (this->text.getMapScaleWidth()*0.5f) - this->text.getMapScaleWidth() * this->originID,
                               0.f
                               );edkEnd();
        //set the cursor position
        this->cursor.position = edk::vec2f32((centerSize.width*-0.5f) + (this->text.getMapScaleWidth() * (this->cursorID-this->originID)),
                                             0.f
                                             );edkEnd();
        //Calculate the selection position inside the object
        if(this->selectionEnd>this->endID+1u){
            selection2 = this->endID+1u;edkEnd();
        }
        else{
            selection2 = this->selectionEnd;edkEnd();
        }
        if(this->selectionStart<this->originID){
            selection1 = this->originID;edkEnd();
        }
        else{
            selection1 = this->selectionStart;edkEnd();
        }
        if(selection2<selection1){
            selection2 = selection1;edkEnd();
        }
        //set the selection object position to be in the smaller character

        this->selection.position = edk::vec2f32((centerSize.width*-0.5f) + (this->text.getMapScaleWidth()) * (selection1 - this->originID),
                                                0.f
                                                );edkEnd();
        //set the selection size to the end be on the bigger character
        this->selection.size = edk::size2f32(this->text.getMapScaleWidth() * (selection2 - selection1),
                                             this->text.getMapScaleHeight()
                                             );edkEnd();
    }
    else{
        this->text.setScale(centerSize.height,centerSize.height);edkEnd();

        //save the cursor size
        this->cursorID = 0u;edkEnd();
        this->originID = 0u;edkEnd();
        this->endID = 0u;edkEnd();
        this->selectionMiddle = this->selectionStart = this->selectionEnd = 0u;edkEnd();
        this->selection.size = edk::size2f32(0.f,
                                             0.f
                                             );edkEnd();

        this->text.setPosition(edk::vec2f32(this->position.x + (centerSize.width*-0.5f) + (this->text.getMapScaleWidth()*0.5f),
                                            this->position.y
                                            ));edkEnd();
        this->selection.position = edk::vec2f32(this->position.x + (centerSize.width*-0.5f),
                                                this->position.y
                                                );edkEnd();
        //save the cursor size
        this->cursor.size = edk::size2f32(this->text.getMapScaleWidth() * edkGU2dCursorWidthPercent,this->text.getMapScaleHeight());edkEnd();
        this->cursor.position = edk::vec2f32( (centerSize.width*-0.5f),
                                              0.f
                                              );edkEnd();

        //test if it was modified
        if(this->cursor.size != this->saveCursorSize){
            //update the cursor animation
            this->cursor.animationSize.cleanAnimations();edkEnd();

            //create a size animation for the cursor
            this->cursor.animationSize.addNewInterpolationLine(0.f,this->cursor.size.width,this->cursor.size.height);edkEnd();
            this->cursor.animationSize.addNewInterpolationLine(edkGU2dCursorSecond,this->cursor.size.width,this->cursor.size.height);edkEnd();
            this->cursor.animationSize.addNewInterpolationLine(edkGU2dCursorSecond + 0.001f,0.f,0.f);edkEnd();
            this->cursor.animationSize.addNewInterpolationLine((edkGU2dCursorSecond*2.f) + 0.001f,0.f,0.f);edkEnd();
            this->cursor.animationSize.loopOn();edkEnd();

            //play the animation
            //this->cursor.animationSize.playForward();edkEnd();

            //save the cursorSize to the next comparison
            this->saveCursorSize = this->cursor.size;edkEnd();

            //if its selected. Then play the animation
            if(this->selected){
                this->cursor.animationSize.stop();edkEnd();
                this->cursor.animationSize.playForward();edkEnd();
            }
        }
    }
    //set the centerSelection to be clicked by the mouse
    this->selectionInside.position = 0.f;edkEnd();//this->position;edkEnd();
    this->selectionInside.size = centerSize;edkEnd();
}
void edk::gui2d::TextField2d::cleanTextVariables(edk::char8* newText){
    //clean the cursor
    this->cursorID = 0u;edkEnd();
    this->originID = 0u;edkEnd();
    this->selectionMiddle = this->selectionStart = this->selectionEnd = 0u;edkEnd();
    this->endID = 0u;edkEnd();
    this->textVec.clean();edkEnd();

    //test if need to write a new text
    if(newText){
        //filter the text

        //
        this->textVec.write(newText);edkEnd();
    }
}
//remove a character from the vec and update the text
bool edk::gui2d::TextField2d::removeCharacter(edk::uint32 position){
    bool ret = false;edkEnd();
    if(this->textVec.remove(position)){
        //get the string and write the text to the object text
        edk::char8* str = this->textVec.getStringWithLastSpace();edkEnd();
        if(str){
            //write the string
            if(edk::gui2d::ObjectGui2d::writeText(str)){
                //
                ret = true;edkEnd();

                //force update the text
                this->forceUpdate();edkEnd();
            }
            delete[] str;edkEnd();
        }
        return ret;
    }
    return false;
}
//update the selection values with the cursor
void edk::gui2d::TextField2d::updateSelection(){
    if(this->cursorID>this->selectionMiddle){
        this->selectionStart = this->selectionMiddle;edkEnd();
        this->selectionEnd = this->cursorID;edkEnd();
    }
    else{
        this->selectionEnd = this->selectionMiddle;edkEnd();
        this->selectionStart = this->cursorID;edkEnd();
    }
}

//load the button textures and meshes
bool edk::gui2d::TextField2d::load(){
    this->setBorderSize(0.2f);edkEnd();
    this->saveCursorSize = 0.f;edkEnd();
    if(edk::gui2d::ObjectGui2d::load()){
        //create the cursor object
        this->cursor.addMesh(&this->meshCursor);edkEnd();
        edk::shape::Mesh2D* mesh = &this->meshCursor;edkEnd();
        if(mesh){
            edk::shape::Rectangle2D rect;edkEnd();
            rect.setPivoToCenter();edkEnd();
            mesh->addPolygon(rect);edkEnd();
            mesh->setPolygonsColor(0,0,0,1);edkEnd();
        }
        mesh = this->selectionInside.newMesh();edkEnd();
        if(mesh){
            edk::shape::Rectangle2D rect;edkEnd();
            rect.setPivoToCenter();edkEnd();
            rect.setVertexPosition(0u,rect.getVertexPosition(0u).x,0.5f);edkEnd();
            rect.setVertexPosition(1u,rect.getVertexPosition(1u).x,-0.5f);edkEnd();
            mesh->addPolygon(rect);edkEnd();
            mesh->setPolygonsColor(0.5f,0.5f,1.f,0.5f);edkEnd();
        }
        mesh = this->selection.newMesh();edkEnd();
        if(mesh){
            edk::shape::Rectangle2D rect;edkEnd();
            rect.setVertexPosition(0u,rect.getVertexPosition(0u).x,0.5f);edkEnd();
            rect.setVertexPosition(1u,rect.getVertexPosition(1u).x,-0.5f);edkEnd();
            mesh->addPolygon(rect);edkEnd();
            mesh->setPolygonsColor(0.5f,0.5f,1.f,0.5f);edkEnd();
        }

        //load the borders
        this->loadSpriteFromMemory(fieldBorderName,fieldBorder,fieldBorderSize);edkEnd();
        this->loadSpritePressedFromMemory(fieldBorderName,fieldBorder,fieldBorderSize);edkEnd();
        this->loadSpriteUpFromMemory(fieldBorderName,fieldBorder,fieldBorderSize);edkEnd();
        //this->loadSpritePressedUpFromMemory(fieldBorderName,fieldBorder,fieldBorderSize);edkEnd();
        return true;
    }
    return false;
}
void edk::gui2d::TextField2d::unload(){
    //clean the cursor
    this->cursor.removeAllMesh();edkEnd();
    this->cursor.animationSize.cleanAnimations();edkEnd();
    this->selection.removeAllMesh();edkEnd();
    this->selectionInside.removeAllMesh();edkEnd();
    this->meshCursor.cleanPolygons();edkEnd();

    edk::gui2d::ObjectGui2d::unload();edkEnd();
}
void edk::gui2d::TextField2d::update(){
    //test if NOT have the text
    if(!this->text.haveText()){
        //create a text only with space
        this->cursorID = 0u;edkEnd();
        this->selectionMiddle = this->selectionStart = this->selectionEnd = 0u;edkEnd();
        this->forceUpdate();edkEnd();
    }


    edk::gui2d::ObjectGui2d::update();edkEnd();
    this->cursor.updateAnimations();edkEnd();
}

//enable and disable the background draw
void edk::gui2d::TextField2d::enableBackground(){
    this->drawBackground = true;edkEnd();
}
void edk::gui2d::TextField2d::disableBackground(){
    this->drawBackground = false;edkEnd();
}
bool edk::gui2d::TextField2d::haveDrawBackground(){
    return this->drawBackground;edkEnd();
}

//set the textLimit. Use zero to unlimited
void edk::gui2d::TextField2d::setCharacterLimit(edk::uint32 limit){
    this->textVec.setCharacterLimit(limit);edkEnd();
}

//set border size
bool edk::gui2d::TextField2d::setBorderSize(edk::float32 size){
    return this->obj.setBorderSize(size);edkEnd();
}
bool edk::gui2d::TextField2d::setStatus(edk::gui2d::gui2dTexture status){
    switch(status){
    case gui2dTextureNormal:
        return edk::gui2d::ObjectGui2d::setStatus(gui2dTextureNormal);edkEnd();
        break;
    case gui2dTextureUp:
        return edk::gui2d::ObjectGui2d::setStatus(gui2dTextureUp);edkEnd();
        break;
    case gui2dTexturePressed:
        return edk::gui2d::ObjectGui2d::setStatus(gui2dTextureNormal);edkEnd();
        break;
    case gui2dTexturePressedUp:
        return edk::gui2d::ObjectGui2d::setStatus(gui2dTextureNormal);edkEnd();
        break;
    case gui2dTextureSize:
        return edk::gui2d::ObjectGui2d::setStatus(gui2dTextureNormal);edkEnd();
        break;
    }
    return false;
}
//set the color of the font and cursor
void edk::gui2d::TextField2d::setFontColor(edk::color4f32 fontColor){
    this->fontColor=fontColor;edkEnd();
    this->meshCursor.setPolygonsColor(fontColor);edkEnd();
}
void edk::gui2d::TextField2d::setFontColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setFontColor(edk::color4f32(r,g,b,a));edkEnd();
}
//select functions
void edk::gui2d::TextField2d::select(){
    edk::gui2d::ObjectGui2d::select();edkEnd();
    this->cursor.animationSize.playForward();edkEnd();
}
void edk::gui2d::TextField2d::deselect(){
    edk::gui2d::ObjectGui2d::deselect();edkEnd();
    this->cursor.animationSize.stop();edkEnd();
}
edk::uint32 counterID = 0u;
//click to select an polygon inside the object
void edk::gui2d::TextField2d::clickStart(edk::uint32 name){
    edk::gui2d::ObjectGui2d::clickStart(name);edkEnd();
    if(name>= this->text.getMapSizeWidth()){
        this->cursorID = this->endID+1u;edkEnd();
        this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;edkEnd();
        //force update
        this->forceUpdate();edkEnd();
        this->cursor.animationSize.stop();edkEnd();
        this->cursor.animationSize.playForward();edkEnd();
    }
    else{
        if(name){
            name--;edkEnd();
        }
        if(name>=this->originID && name<=this->endID+1u){
            this->cursorID = name;edkEnd();
            this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;edkEnd();
            //force update
            this->forceUpdate();edkEnd();
            this->cursor.animationSize.stop();edkEnd();
            this->cursor.animationSize.playForward();edkEnd();
        }
    }
}
void edk::gui2d::TextField2d::clickMove(edk::uint32 name,bool mouseInside){
    edk::gui2d::ObjectGui2d::clickMove(name,mouseInside);edkEnd();
}
void edk::gui2d::TextField2d::clickEnd(edk::uint32 name,bool mouseInside,bool doubleClick){
    edk::gui2d::ObjectGui2d::clickEnd(name,mouseInside,doubleClick);edkEnd();
    //select all text
    if(doubleClick){
        this->selectAll();edkEnd();
    }
}

//set the case
void edk::gui2d::TextField2d::setUpperAndLowerCase(){
    this->textVec.setCaseInput(edk::gui2d::upperAndLowerCase);edkEnd();
}
void edk::gui2d::TextField2d::setUpperCase(){
    this->textVec.setCaseInput(edk::gui2d::upperCase);edkEnd();
}
void edk::gui2d::TextField2d::setLowerCase(){
    this->textVec.setCaseInput(edk::gui2d::lowerCase);edkEnd();
}

//cursor functions
void edk::gui2d::TextField2d::incrementCursor(){
    if(this->textVec.getSize()){
        edk::uint32 mapSize = this->text.getMapSizeWidth();edkEnd();
        if(mapSize){
            mapSize--;edkEnd();
        }
        if(this->cursorID < mapSize){
            this->cursorID++;edkEnd();
            this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;edkEnd();
            //force update
            this->forceUpdate();edkEnd();
            this->cursor.animationSize.stop();edkEnd();
            this->cursor.animationSize.playForward();edkEnd();
        }
    }
}
void edk::gui2d::TextField2d::incrementCursorWithSelect(){
    if(this->textVec.getSize()){
        edk::uint32 mapSize = this->text.getMapSizeWidth();edkEnd();
        if(mapSize){
            mapSize--;edkEnd();
        }
        if(this->cursorID < mapSize){
            this->cursorID++;edkEnd();
            this->updateSelection();edkEnd();
            //force update
            this->forceUpdate();edkEnd();
            this->cursor.animationSize.stop();edkEnd();
            this->cursor.animationSize.playForward();edkEnd();
        }
    }
}
void edk::gui2d::TextField2d::decrementCursor(){
    if(this->cursorID){
        this->cursorID--;edkEnd();
        this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;edkEnd();
        //force update
        this->forceUpdate();edkEnd();
        this->cursor.animationSize.stop();edkEnd();
        this->cursor.animationSize.playForward();edkEnd();
    }
}
void edk::gui2d::TextField2d::decrementCursorWithSelect(){
    if(this->cursorID){
        this->cursorID--;edkEnd();
        this->updateSelection();edkEnd();
        //force update
        this->forceUpdate();edkEnd();
        this->cursor.animationSize.stop();edkEnd();
        this->cursor.animationSize.playForward();edkEnd();
    }
}
void edk::gui2d::TextField2d::moveCursorToEnd(){
    edk::uint32 mapSize = this->text.getMapSizeWidth();edkEnd();
    if(mapSize){
        mapSize--;edkEnd();
    }
    if(this->cursorID < mapSize){
        this->cursorID = mapSize;edkEnd();
        this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;edkEnd();
        //force update
        this->forceUpdate();edkEnd();
        this->cursor.animationSize.stop();edkEnd();
        this->cursor.animationSize.playForward();edkEnd();
    }
}
void edk::gui2d::TextField2d::moveCursorToEndWithSelect(){
    edk::uint32 mapSize = this->text.getMapSizeWidth();edkEnd();
    if(mapSize){
        mapSize--;edkEnd();
    }
    if(this->cursorID < mapSize){
        this->cursorID = mapSize;edkEnd();
        this->updateSelection();edkEnd();
        //force update
        this->forceUpdate();edkEnd();
        this->cursor.animationSize.stop();edkEnd();
        this->cursor.animationSize.playForward();edkEnd();
    }
}
void edk::gui2d::TextField2d::moveCursorToStart(){
    if(this->cursorID){
        this->cursorID = 0u;edkEnd();
        this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;edkEnd();
        //force update
        this->forceUpdate();edkEnd();
        this->cursor.animationSize.stop();edkEnd();
        this->cursor.animationSize.playForward();edkEnd();
    }
}
void edk::gui2d::TextField2d::moveCursorToStartWithSelect(){
    if(this->cursorID){
        this->cursorID = 0u;edkEnd();
        this->updateSelection();edkEnd();
        //force update
        this->forceUpdate();edkEnd();
        this->cursor.animationSize.stop();edkEnd();
        this->cursor.animationSize.playForward();edkEnd();
    }
}
void edk::gui2d::TextField2d::selectAll(){
    this->cursorID = this->text.getMapSizeWidth();edkEnd();
    if(this->cursorID){
        this->cursorID--;edkEnd();
        this->selectionEnd = this->cursorID;edkEnd();
        this->selectionStart=0u;
    }
}
//add some character
bool edk::gui2d::TextField2d::addCharacter(edk::char8 c){
    if(this->selectionStart!=this->selectionEnd){
        this->deleteCharacter();edkEnd();
    }
    //add the character
    if(this->textVec.add((edk::char32)edk::BinaryConverter::joinBytesLittleEndian(0u,0u,0u,c),this->cursorID)){
        //force update
        this->forceUpdate();edkEnd();
        this->cursor.animationSize.stop();edkEnd();
        this->cursor.animationSize.playForward();edkEnd();
        edk::char8* str = this->textVec.getStringWithLastSpace();edkEnd();
        if(str){
            this->cursorID++;edkEnd();
            this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;edkEnd();
            edk::gui2d::ObjectGui2d::writeText(str);edkEnd();
            delete[] str;edkEnd();
            return true;
        }
        else{
            edk::gui2d::ObjectGui2d::cleanText();edkEnd();
        }
    }
    return false;
}
bool edk::gui2d::TextField2d::addString(edk::char8* str){
    edk::uint32 lenght=0u;
    if((lenght = this->textVec.add(str,this->cursorID))){
        this->cursorID+=lenght;edkEnd();
        this->forceUpdate();edkEnd();
        this->cursor.animationSize.stop();edkEnd();
        this->cursor.animationSize.playForward();edkEnd();
        edk::char8* str = this->textVec.getStringWithLastSpace();edkEnd();
        if(str){
            this->cursorID++;edkEnd();
            this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;edkEnd();
            edk::gui2d::ObjectGui2d::writeText(str);edkEnd();
            delete[] str;edkEnd();
            return true;
        }
        else{
            edk::gui2d::ObjectGui2d::cleanText();edkEnd();
        }
        return true;
    }
    return false;
}
bool edk::gui2d::TextField2d::addString(const edk::char8* str){
    return this->addString((edk::char8*) str);edkEnd();
}
//add characters to the filters
bool edk::gui2d::TextField2d::addCharacterFilterIn(edk::char8 c){
    return this->textVec.addFilterIn(c);edkEnd();
}
bool edk::gui2d::TextField2d::addStringFilterIn(edk::char8* str){
    if(str){
        return this->textVec.addFilterIn(str);edkEnd();
    }
    return false;
}
bool edk::gui2d::TextField2d::addStringFilterIn(const edk::char8* str){
    //
    return this->addStringFilterIn((edk::char8*) str);edkEnd();
}
bool edk::gui2d::TextField2d::addCharacterFilterOut(edk::char8 c){
    return this->textVec.addFilterOut(c);edkEnd();
}
bool edk::gui2d::TextField2d::addStringFilterOut(edk::char8* str){
    if(str){
        return this->textVec.addFilterOut(str);edkEnd();
    }
    return false;
}
bool edk::gui2d::TextField2d::addStringFilterOut(const edk::char8* str){
    //
    return this->addStringFilterOut((edk::char8*) str);edkEnd();
}
void edk::gui2d::TextField2d::cleanFilterIn(){
    this->textVec.cleanFilterIn();edkEnd();
}
void edk::gui2d::TextField2d::cleanFilterOut(){
    this->textVec.cleanFilterOut();edkEnd();
}

//write text to clean the originID and cursorID
bool edk::gui2d::TextField2d::writeText(const edk::char8* text){
    bool ret = false;edkEnd();
    this->cleanTextVariables((edk::char8*)text);edkEnd();
    //get the string
    edk::char8* str = this->textVec.getStringWithLastSpace();edkEnd();
    if(str){
        if(edk::gui2d::ObjectGui2d::writeText(str)){
            ret = true;edkEnd();
        }
        delete[] str;edkEnd();
        return ret;
    }
    this->cleanTextVariables(NULL);edkEnd();
    return false;
}
bool edk::gui2d::TextField2d::writeText(edk::char8* text){
    bool ret = false;edkEnd();
    this->cleanTextVariables(text);edkEnd();
    //get the string
    edk::char8* str = this->textVec.getStringWithLastSpace();edkEnd();
    if(str){
        if(edk::gui2d::ObjectGui2d::writeText(str)){
            ret = true;edkEnd();
        }
        delete[] str;edkEnd();
        return ret;
    }
    this->cleanTextVariables(NULL);edkEnd();
    return false;
}
bool edk::gui2d::TextField2d::writeText(const edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight){
    bool ret = false;edkEnd();
    this->cleanTextVariables((edk::char8*)text);edkEnd();
    //get the string
    edk::char8* str = this->textVec.getStringWithLastSpace();edkEnd();
    if(str){
        if(edk::gui2d::ObjectGui2d::writeText(str,scaleWidth,scaleHeight)){
            ret = true;edkEnd();
        }
        delete[] str;edkEnd();
        return ret;
    }
    this->cleanTextVariables(NULL);edkEnd();
    return false;
}
bool edk::gui2d::TextField2d::writeText(edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight){
    bool ret = false;edkEnd();
    this->cleanTextVariables(text);edkEnd();
    //get the string
    edk::char8* str = this->textVec.getStringWithLastSpace();edkEnd();
    if(str){
        if(edk::gui2d::ObjectGui2d::writeText(str,scaleWidth,scaleHeight)){
            ret = true;edkEnd();
        }
        delete[] str;edkEnd();
        return ret;
    }
    this->cleanTextVariables(NULL);edkEnd();
    return false;
}
bool edk::gui2d::TextField2d::writeText(const edk::char8* text,edk::size2f32 scale){
    bool ret = false;edkEnd();
    this->cleanTextVariables((edk::char8*)text);edkEnd();
    //get the string
    edk::char8* str = this->textVec.getStringWithLastSpace();edkEnd();
    if(str){
        if(edk::gui2d::ObjectGui2d::writeText(str,scale)){
            ret = true;edkEnd();
        }
        delete[] str;edkEnd();
        return ret;
    }
    this->cleanTextVariables(NULL);edkEnd();
    return false;
}
bool edk::gui2d::TextField2d::writeText(edk::char8* text,edk::size2f32 scale){
    bool ret = false;edkEnd();
    this->cleanTextVariables(text);edkEnd();
    //get the string
    edk::char8* str = this->textVec.getStringWithLastSpace();edkEnd();
    if(str){
        if(edk::gui2d::ObjectGui2d::writeText(str,scale)){
            ret = true;edkEnd();
        }
        delete[] str;edkEnd();
        return ret;
    }
    this->cleanTextVariables(NULL);edkEnd();
    return false;
}
void edk::gui2d::TextField2d::cleanText(){
    this->cleanTextVariables(NULL);edkEnd();
    return edk::gui2d::ObjectGui2d::cleanText();edkEnd();
}
//remove or delete characters
void edk::gui2d::TextField2d::deleteCharacter(){
    //test if have something selected
    if(this->selectionStart!=this->selectionEnd){
        //
        this->cursorID = this->selectionStart;edkEnd();
        this->textVec.remove(this->cursorID,this->selectionEnd - this->selectionStart);edkEnd();
    }
    else{
        this->textVec.remove(this->cursorID);edkEnd();
    }
    edk::char8* str = this->textVec.getStringWithLastSpace();edkEnd();
    if(str){
        edk::gui2d::ObjectGui2d::writeText(str);edkEnd();
        delete[] str;edkEnd();
    }
    else{
        edk::gui2d::ObjectGui2d::cleanText();edkEnd();
    }
    this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;edkEnd();
    //force update
    this->forceUpdate();edkEnd();
    this->cursor.animationSize.stop();edkEnd();
    this->cursor.animationSize.playForward();edkEnd();
}
void edk::gui2d::TextField2d::removeCharacter(){
    bool remove = false;edkEnd();
    //test if have something selected
    if(this->selectionStart!=this->selectionEnd){
        //
        this->cursorID = this->selectionStart;edkEnd();
        this->textVec.remove(this->cursorID,this->selectionEnd - this->selectionStart);edkEnd();
        remove = true;edkEnd();
    }
    else{
        if(this->cursorID){
            this->textVec.remove(this->cursorID-1u);edkEnd();
            this->cursorID--;edkEnd();
            remove = true;edkEnd();
        }
    }
    if(remove){
        edk::char8* str = this->textVec.getStringWithLastSpace();edkEnd();
        if(str){
            edk::gui2d::ObjectGui2d::writeText(str);edkEnd();
            delete[] str;edkEnd();
        }
        else{
            this->cursorID=0u;
            edk::gui2d::ObjectGui2d::cleanText();edkEnd();
        }
    }
    this->selectionMiddle = this->selectionEnd = this->selectionStart = this->cursorID;edkEnd();
    //force update
    this->forceUpdate();edkEnd();
    this->cursor.animationSize.stop();edkEnd();
    this->cursor.animationSize.playForward();edkEnd();
}
//get string writed
edk::char8* edk::gui2d::TextField2d::getText(){
    return this->textVec.getString();edkEnd();
}
//get string size
edk::uint32 edk::gui2d::TextField2d::getTextSize(){
    return this->textVec.getSize();edkEnd();
}

//draw the button
void edk::gui2d::TextField2d::draw(){
    this->drawStart();edkEnd();
    edk::GU::guEnable(GU_LIGHTING);edkEnd();

    if(this->drawBackground){
        switch(this->status){
        case edk::gui2d::gui2dTexture::gui2dTextureUp:
            //draw the border
            this->obj.drawUp();edkEnd();
            break;
        case edk::gui2d::gui2dTexture::gui2dTexturePressed:
            //draw the border
            this->obj.drawPressed();edkEnd();
            break;
        case edk::gui2d::gui2dTexture::gui2dTexturePressedUp:
            //draw the border
            this->obj.drawPressedUp();edkEnd();
            break;
        case edk::gui2d::gui2dTexture::gui2dTextureNormal:
        case edk::gui2d::gui2dTexture::gui2dTextureSize:
        default:
            //draw the border
            this->obj.drawNormal();edkEnd();
            break;
        }
    }
    edk::GU::guDisable(GU_LIGHTING);edkEnd();

    //test if have the texture
    if(this->sprite.material.getTexture(this->status)){
        //draw the srite on the button
        this->sprite.drawOneTexture(this->status);edkEnd();
    }

    if(this->text.haveText() && this->drawText){
        if(this->isSelected()){
            //draw the selection
            this->selection.drawWithoutMaterial();edkEnd();

            this->text.draw(this->fontColor);edkEnd();
        }
        else{
            this->text.draw(this->fontColor);edkEnd();
        }
    }

    //draw the cursor
    if(this->isSelected()){
        this->meshCursor.setPolygonsColor(fontColor);edkEnd();
        this->cursor.drawWithoutMaterial();edkEnd();
    }

    this->drawEnd();edkEnd();
}
void edk::gui2d::TextField2d::drawSelection(){
    this->drawStart();edkEnd();
    //draw the border
    this->obj.drawSelection();edkEnd();

    if(this->text.haveText() && this->drawText){
        //first draw the selectionInside
        edk::GU::guPushName(this->text.getMapSizeWidth());edkEnd();
        this->selectionInside.drawWithoutMaterial();edkEnd();
        edk::GU::guPopName();edkEnd();
        //
        this->text.setPosition(this->text.getPositionX() - this->text.getMapScaleWidth()*0.5,
                               this->text.getPositionY()
                               );edkEnd();
        this->text.setLast(this->endID + 1u);edkEnd();
        this->text.drawSelection();edkEnd();
        this->text.setPosition(this->text.getPositionX() + this->text.getMapScaleWidth()*0.5,
                               this->text.getPositionY()
                               );edkEnd();
        this->text.setLast(this->endID);edkEnd();
    }
    //
    this->drawEnd();edkEnd();
}
