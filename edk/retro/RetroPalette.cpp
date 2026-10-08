#include "RetroPalette.h"
/*
Library C++ RetroPalette - Retro Palette used in EDK
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
#pragma message "            Inside RetroPalette.cpp"
#endif

#define HEADER_GIMP "GIMP Palette"
#define HEADER_JASC "JASC-PAL"
#define HEADER_PAINT "paint.net"
#define WORD_GIMP_COLORS "Colors: "

#define paletteExtension_paint "txt"
#define paletteExtension_HEX   "hex"
#define paletteExtension_JASP  "pal"
#define paletteExtension_GIMP  "gpl"
#define paletteExtension_ASE   "ase"

edk::retro::RetroPalette::RetroPalette(){
    this->classThis=NULL;
    this->Constructor();
}
edk::retro::RetroPalette::~RetroPalette(){
    this->Destructor();
}

void edk::retro::RetroPalette::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        this->vec=NULL;
        this->size=0u;
        this->lenght=0u;
        this->channels=0u;
        this->bytesPerChannel=0u;
    }
}
void edk::retro::RetroPalette::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;

        this->deletePalette();
    }
}

bool edk::retro::RetroPalette::havePalette(){
    if(this->vec && this->lenght){
        return true;
    }
    return false;
}

void edk::retro::RetroPalette::deletePalette(){
    if(this->vec){
        free(this->vec);
    }
    this->vec=NULL;
    this->size=0u;
    this->lenght=0u;
    this->channels=0u;
    this->bytesPerChannel=0u;
}

bool edk::retro::RetroPalette::newPalette(edk::uint32 size,edk::uint8 channels,edk::uint8 bytesPerChannel){
    this->deletePalette();
    if(size && channels && bytesPerChannel
            && channels<=4u
            && bytesPerChannel <=2u
            ){
        this->lenght = size * channels * bytesPerChannel;
        this->vec = (edk::uint8* )malloc(this->lenght);
        if(this->vec){
            this->size=size;
            this->channels=channels;
            this->bytesPerChannel=bytesPerChannel;
            return true;
        }
        this->lenght=0u;
    }
    return false;
}

//READ AND WRITE
bool edk::retro::RetroPalette::loadFromFile(edk::char8* fileName){
    bool ret = false;
    if(fileName){
        edk::retro::edkPaletteFileType type;
        edk::File file;
        edk::MemoryBuffer<edk::char8> buffer;
        edk::char8* extension = edk::String::strFileExtensionNoName(fileName);
        if(extension){
            if(edk::String::strCompare(extension,paletteExtension_paint)){
                //TXT
                type = edk::retro::palette_txt;
            }
            else if(edk::String::strCompare(extension,paletteExtension_HEX)){
                //HEX
                type = edk::retro::palette_hex;
            }
            else if(edk::String::strCompare(extension,paletteExtension_JASP)){
                //PAL
                type = edk::retro::palette_pal;
            }
            else if(edk::String::strCompare(extension,paletteExtension_GIMP)){
                //GIMP
                type = edk::retro::palette_gpl;
            }
            else if(edk::String::strCompare(extension,paletteExtension_ASE)){
                //photoshop
                type = edk::retro::palette_ase;
            }

            if(type != edk::retro::palette_ase){
                if(file.openTextFile(fileName)){
                    buffer.writeFileFullToBuffer(&file);
                    file.closeFile();
                }

                bool header=false;

                if(buffer.size()){
                    //start to read the buffers
                    edk::char8* str = buffer.getPointer();
                    edk::char8* temp;
                    edk::int64 size=0u;

                    edk::uint8 a,r,g,b;
                    edk::uint8 counter=0;

                    //colors
                    edk::vector::Stack<edk::color4ui8> colors;
                    edk::color4ui8 color;
                    edk::uint8 channels=3u;

                    while(*str){
                        switch(*str){
                        case 'G':
                            if(edk::String::strHaveInsideBeggin(str,HEADER_GIMP)){
                                header=true;
                                type = edk::retro::palette_gpl;
                            }
                            //goto nextLine
                            str = edk::String::strGoToEndLine(str);
                            break;
                        case 'J':
                            if(edk::String::strHaveInsideBeggin(str,HEADER_JASC)){
                                header=true;
                                type = edk::retro::palette_pal;
                                str = edk::String::strGoToEndLine(str);
                                while(*str){
                                    if(*str==13 || *str==10) str++;
                                    else break;
                                }
                                str = edk::String::strGoToEndLine(str);
                                while(*str){
                                    if(*str==13 || *str==10) str++;
                                    else break;
                                }
                                //read the number of colors
                                temp = edk::String::strCopyLine(str);
                                if(temp){
                                    size = edk::String::strToInt64(str);
                                    free(temp);
                                }
                            }
                            //goto nextLine
                            str = edk::String::strGoToEndLine(str);
                            break;
                        case ';':
                            if(header){
                                str++;
                                if(edk::String::strHaveInsideBeggin(str,WORD_GIMP_COLORS)){
                                    str+=sizeof(WORD_GIMP_COLORS)-1u;
                                    //read the number of colors
                                    temp = edk::String::strCopyLine(str);
                                    if(temp){
                                        size = edk::String::strToInt64(str);
                                        free(temp);
                                    }
                                }
                            }
                            else{
                                //read the first header
                                str++;
                                if(edk::String::strHaveInsideBeggin(str,HEADER_PAINT)){
                                    header=true;
                                    type = edk::retro::palette_txt;
                                }
                            }
                            //goto nextLine
                            str = edk::String::strGoToEndLine(str);
                            break;
                        case '#':
                            if(header){
                                str++;
                                if(edk::String::strHaveInsideBeggin(str,WORD_GIMP_COLORS)){
                                    str+=sizeof(WORD_GIMP_COLORS)-1u;
                                    //read the number of colors
                                    temp = edk::String::strCopyLine(str);
                                    if(temp){
                                        size = edk::String::strToInt64(str);
                                        free(temp);
                                    }
                                }
                            }
                            //goto nextLine
                            str = edk::String::strGoToEndLine(str);
                            break;
                        default:
                            if((*str>='0'&&*str<='9')
                                    || (*str>='a'&&*str<='f')
                                    || (*str>='A'&&*str<='F')
                                    ){
                                //its a color value value
                                if(header){
                                    if(size){
                                        a=0xFF;
                                        //read the values
                                        switch(type){
                                        case edk::retro::palette_gpl:

                                            //goto the word 4th
                                            counter=0u;
                                            while(*str){
                                                if(*str==' '
                                                        ||
                                                        *str==9
                                                        ){
                                                    //
                                                    counter++;
                                                    if(counter>=3u){
                                                        str++;
                                                        break;
                                                    }
                                                }
                                                str++;
                                            }

                                            ////XXXXXXXXXXXX
                                            //str+=sizeof("XXXXXXXXXXXX")-1u;
                                            temp = edk::String::strCopyLine(str);
                                            if(temp){
                                                if(edk::String::strSize(temp) > 6u){
                                                    r = edk::String::strHexToUi8(&temp[0u]);
                                                    g = edk::String::strHexToUi8(&temp[2u]);
                                                    b = edk::String::strHexToUi8(&temp[4u]);
                                                }
                                                free(temp);
                                            }
                                            break;
                                        case edk::retro::palette_pal:
                                            //R
                                            temp = edk::String::strCopyWord(str);
                                            if(temp){
                                                r = edk::String::strToInt32(temp);
                                                //go to the next value
                                                while(*str){
                                                    if(*str==' '){
                                                        str++;
                                                        break;
                                                    }
                                                    str++;
                                                }
                                                free(temp);
                                            }
                                            //G
                                            temp = edk::String::strCopyWord(str);
                                            if(temp){
                                                g = edk::String::strToInt32(temp);
                                                //go to the next value
                                                while(*str){
                                                    if(*str==' '){
                                                        str++;
                                                        break;
                                                    }
                                                    str++;
                                                }
                                                free(temp);
                                            }
                                            //B
                                            temp = edk::String::strCopyWord(str);
                                            if(temp){
                                                b = edk::String::strToInt32(temp);
                                                free(temp);
                                            }
                                            break;
                                        case edk::retro::palette_txt:
                                            temp = edk::String::strCopyLine(str);
                                            if(temp){
                                                if(edk::String::strSize(temp) > 8u){
                                                    a = edk::String::strHexToUi8(&temp[0u]);
                                                    r = edk::String::strHexToUi8(&temp[2u]);
                                                    g = edk::String::strHexToUi8(&temp[4u]);
                                                    b = edk::String::strHexToUi8(&temp[6u]);
                                                    channels=4u;
                                                }
                                                free(temp);
                                            }
                                            break;
                                        default:
                                            break;
                                        }
                                        //save new color
                                        //printf("\n%u %s %s NEW COLOR([%u][%u][%u][%u])",__LINE__,__FILE__,__func__,r,g,b,a);
                                        color.r=r;
                                        color.g=g;
                                        color.b=b;
                                        color.a=a;
                                        colors.pushBack(color);
                                    }
                                }
                                else{
                                    //read the hex
                                    temp = edk::String::strCopyLine(str);
                                    if(temp){
                                        if(edk::String::strSize(temp) > 6u){
                                            r = edk::String::strHexToUi8(&temp[0u]);
                                            g = edk::String::strHexToUi8(&temp[2u]);
                                            b = edk::String::strHexToUi8(&temp[4u]);
                                        }
                                        free(temp);
                                    }
                                    //save new color
                                    //printf("\n%u %s %s NEW COLOR([%u][%u][%u][%u])",__LINE__,__FILE__,__func__,r,g,b,a);
                                    //fflush(stdout);
                                    color.r=r;
                                    color.g=g;
                                    color.b=b;
                                    color.a=a;
                                    colors.pushBack(color);
                                }
                            }
                            //goto nextLine
                            str = edk::String::strGoToEndLine(str);
                            break;
                        }
                        str++;
                    }

                    //create the new palette
                    size = colors.size();
                    if(size){
                        if(this->newPalette(size,channels,1u)){
                            switch(channels){
                            case 3u:
                                for(edk::uint32 i=0u;i<size;i++){
                                    color = colors.get(i);
                                    this->setColor(i,color.r,color.g,color.b);
                                }
                                break;
                            case 4u:
                                for(edk::uint32 i=0u;i<size;i++){
                                    color = colors.get(i);
                                    this->setColor(i,color.r,color.g,color.b,color.a);
                                }
                                break;
                            }
                            //
                        }
                    }

                    ret=true;

                    buffer.clean();
                }
            }
            free(extension);
        }
    }
    return ret;
}
bool edk::retro::RetroPalette::loadFromFile(const edk::char8* fileName){
    return this->loadFromFile((edk::char8*) fileName);
}
bool edk::retro::RetroPalette::saveToFile(edk::char8* fileName,edk::char8* name,edk::char8* description){
    if(fileName && this->havePalette()){
        //

        edk::uint32 size = this->getSize();
        edk::retro::edkPaletteFileType type;
        edk::File file;
        edk::MemoryBuffer<edk::char8> buffer;
        edk::char8* extension = edk::String::strFileExtensionNoName(fileName);
        edk::color4ui8 color;
        if(extension){
            if(edk::String::strCompare(extension,paletteExtension_paint)){
                //TXT
                type = edk::retro::palette_txt;
            }
            else if(edk::String::strCompare(extension,paletteExtension_HEX)){
                //HEX
                type = edk::retro::palette_hex;
            }
            else if(edk::String::strCompare(extension,paletteExtension_JASP)){
                //PAL
                type = edk::retro::palette_pal;
            }
            else if(edk::String::strCompare(extension,paletteExtension_GIMP)){
                //GIMP
                type = edk::retro::palette_gpl;
            }
            else if(edk::String::strCompare(extension,paletteExtension_ASE)){
                //photoshop
                type = edk::retro::palette_ase;
            }

            if(type != edk::retro::palette_ase){
                edk::char8* temp;

                //write to the buffer
                switch(type){
                case edk::retro::palette_txt:
                    //write the header
                    buffer.pushToBuffer(";paint.net Palette File");
                    buffer.pushToBuffer("\n;Palette Name: ");
                    if(name)
                        buffer.pushToBuffer(name);
                    else
                        buffer.pushToBuffer("EDK_PALETTE no name");
                    buffer.pushToBuffer("\n;Description: ");
                    if(description)
                        buffer.pushToBuffer(description);
                    else
                        buffer.pushToBuffer("No Description");
                    //colors
                    buffer.pushToBuffer("\n;");
                    buffer.pushToBuffer(WORD_GIMP_COLORS);
                    temp = edk::String::uint32ToStr(this->getSize());
                    if(temp){
                        buffer.pushToBuffer(temp);
                        free(temp);
                    }
                    for(edk::uint32 i=0u;i<size;i++){
                        buffer.pushToBuffer("\n");
                        color = this->getColor4ui8(i);
                        //write the color
                        temp = edk::String::uint8HexToStr(color.a);
                        if(temp){
                            buffer.pushToBuffer(temp);
                            free(temp);
                        }
                        temp = edk::String::uint8HexToStr(color.r);
                        if(temp){
                            buffer.pushToBuffer(temp);
                            free(temp);
                        }
                        temp = edk::String::uint8HexToStr(color.g);
                        if(temp){
                            buffer.pushToBuffer(temp);
                            free(temp);
                        }
                        temp = edk::String::uint8HexToStr(color.b);
                        if(temp){
                            buffer.pushToBuffer(temp);
                            free(temp);
                        }
                    }
                    break;
                case edk::retro::palette_hex:
                    for(edk::uint32 i=0u;i<size;i++){
                        if(i)buffer.pushToBuffer("\n");
                        color = this->getColor4ui8(i);
                        //write the color
                        temp = edk::String::uint8HexToStr(color.r);
                        if(temp){
                            buffer.pushToBuffer(temp);
                            free(temp);
                        }
                        temp = edk::String::uint8HexToStr(color.g);
                        if(temp){
                            buffer.pushToBuffer(temp);
                            free(temp);
                        }
                        temp = edk::String::uint8HexToStr(color.b);
                        if(temp){
                            buffer.pushToBuffer(temp);
                            free(temp);
                        }
                    }
                    break;
                case edk::retro::palette_pal:
                    //write the header
                    buffer.pushToBuffer("JASC-PAL");
                    //write the version
                    buffer.pushToBuffer("\n0100");
                    //write the colors
                    buffer.pushToBuffer("\n");
                    temp = edk::String::uint32ToStr(this->getSize());
                    if(temp){
                        buffer.pushToBuffer(temp);
                        free(temp);
                    }
                    for(edk::uint32 i=0u;i<size;i++){
                        buffer.pushToBuffer("\n");
                        color = this->getColor4ui8(i);
                        //write the color
                        temp = edk::String::uint32ToStr(color.r);
                        if(temp){
                            buffer.pushToBuffer(temp);
                            free(temp);
                        }
                        buffer.pushToBuffer(" ");
                        temp = edk::String::uint32ToStr(color.g);
                        if(temp){
                            buffer.pushToBuffer(temp);
                            free(temp);
                        }
                        buffer.pushToBuffer(" ");
                        temp = edk::String::uint32ToStr(color.b);
                        if(temp){
                            buffer.pushToBuffer(temp);
                            free(temp);
                        }
                    }
                    break;
                case edk::retro::palette_gpl:
                    //write the header
                    buffer.pushToBuffer("GIMP Palette");
                    buffer.pushToBuffer("\n#Palette Name: ");
                    if(name)
                        buffer.pushToBuffer(name);
                    else
                        buffer.pushToBuffer("EDK_PALETTE no name");
                    buffer.pushToBuffer("\n#Description: ");
                    if(description)
                        buffer.pushToBuffer(description);
                    else
                        buffer.pushToBuffer("No Description");
                    //colors
                    buffer.pushToBuffer("\n#");
                    buffer.pushToBuffer(WORD_GIMP_COLORS);
                    temp = edk::String::uint32ToStr(this->getSize());
                    if(temp){
                        buffer.pushToBuffer(temp);
                        free(temp);
                    }
                    for(edk::uint32 i=0u;i<size;i++){
                        buffer.pushToBuffer("\n");
                        color = this->getColor4ui8(i);
                        //write the color
                        temp = edk::String::uint32ToStr(color.r);
                        if(temp){
                            buffer.pushToBuffer(temp);
                            free(temp);
                        }
                        buffer.pushToBuffer((edk::char8)9u);
                        temp = edk::String::uint32ToStr(color.g);
                        if(temp){
                            buffer.pushToBuffer(temp);
                            free(temp);
                        }
                        buffer.pushToBuffer((edk::char8)9u);
                        temp = edk::String::uint32ToStr(color.b);
                        if(temp){
                            buffer.pushToBuffer(temp);
                            free(temp);
                        }
                        buffer.pushToBuffer((edk::char8)9u);
                        //write the color
                        temp = edk::String::uint8HexToStr(color.r);
                        if(temp){
                            buffer.pushToBuffer(temp);
                            free(temp);
                        }
                        temp = edk::String::uint8HexToStr(color.g);
                        if(temp){
                            buffer.pushToBuffer(temp);
                            free(temp);
                        }
                        temp = edk::String::uint8HexToStr(color.b);
                        if(temp){
                            buffer.pushToBuffer(temp);
                            free(temp);
                        }
                    }
                    break;
                default:
                    break;
                }
                if(buffer.size()){
                    if(file.createAndOpenBinFile(fileName)){
                        file.writeText(buffer.getPointerStr());
                        file.flush();
                        file.closeFile();
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool edk::retro::RetroPalette::saveToFile(const edk::char8* fileName,const edk::char8* name,const edk::char8* description){
    return this->saveToFile((edk::char8*) fileName,(edk::char8*) name,(edk::char8*) description);
}

//GETTERS
edk::uint8* edk::retro::RetroPalette::getPalette(){
    return this->vec;
}
edk::uint32 edk::retro::RetroPalette::getSize(){
    return this->size;
}
edk::uint8 edk::retro::RetroPalette::getChannels(){
    return this->channels;
}
edk::uint8 edk::retro::RetroPalette::getBytesPerChannel(){
    return this->bytesPerChannel;
}

bool edk::retro::RetroPalette::havePosition(edk::uint32 position){
    if(position <= this->size){
        return true;
    }
    return false;
}

//copy palette
bool edk::retro::RetroPalette::setPalette(edk::uint8* palette){
    if(palette){
        if(this->havePalette()){
            //copy the palette
            edkMemCpy(this->vec,palette,this->lenght);
            return true;
        }
    }
    return false;
}
bool edk::retro::RetroPalette::copyPalette(edk::uint8* palette,edk::uint32 size,edk::uint8 channels,edk::uint8 bytesPerChannel){
    if(palette && size && channels && bytesPerChannel){
        if(this->newPalette(size,channels,bytesPerChannel)){
            edkMemCpy(this->vec,palette,this->lenght);
            return true;
        }
    }
    return false;
}

//EDIT THE PALETTE
bool edk::retro::RetroPalette::setColor(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //set the palette inside the color
            switch(this->channels){
            case 1u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 2u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = a;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 3u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = g;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = b;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 4u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = g;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = b;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = a;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            }
        }
    }
    return false;
}
bool edk::retro::RetroPalette::setColor(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b){
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //set the palette inside the color
            switch(this->channels){
            case 1u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 2u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = 0xFF*sizeof(color);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 3u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = g;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = b;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 4u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = g;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = b;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = 0xFF*sizeof(color);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            }
        }
    }
    return false;
}
bool edk::retro::RetroPalette::setColor(edk::uint32 position,edk::uint8 g,edk::uint8 a){
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //set the palette inside the color
            switch(this->channels){
            case 1u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 2u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = a;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 3u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 4u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = a;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            }
        }
    }
    return false;
}
bool edk::retro::RetroPalette::setColor(edk::uint32 position,edk::uint8 g){
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //set the palette inside the color
            switch(this->channels){
            case 1u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 2u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = 0xFF*sizeof(color);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 3u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 4u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = 0xFF*sizeof(color);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            }
        }
    }
    return false;
}
bool edk::retro::RetroPalette::setColor(edk::uint32 position,edk::uint16 r,edk::uint16 g,edk::uint16 b,edk::uint16 a){
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //set the palette inside the color
            switch(this->channels){
            case 1u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 2u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = a;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 3u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = g;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = b;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 4u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = g;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = b;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = a;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            }
        }
    }
    return false;
}
bool edk::retro::RetroPalette::setColor(edk::uint32 position,edk::uint16 r,edk::uint16 g,edk::uint16 b){
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //set the palette inside the color
            switch(this->channels){
            case 1u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 2u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = 0xFF*sizeof(color);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 3u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = g;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = b;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 4u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = g;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = b;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = 0xFF*sizeof(color);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            }
        }
    }
    return false;
}
bool edk::retro::RetroPalette::setColor(edk::uint32 position,edk::uint16 g,edk::uint16 a){
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //set the palette inside the color
            switch(this->channels){
            case 1u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 2u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = a;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 3u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 4u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = a;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            }
        }
    }
    return false;
}
bool edk::retro::RetroPalette::setColor(edk::uint32 position,edk::uint16 g){
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //set the palette inside the color
            switch(this->channels){
            case 1u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 2u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = 0xFF*sizeof(color);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 3u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 4u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = 0xFF*sizeof(color);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            }
        }
    }
    return false;
}
bool edk::retro::RetroPalette::setColor(edk::uint32 position,edk::uint32 r,edk::uint32 g,edk::uint32 b,edk::uint32 a){
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //set the palette inside the color
            switch(this->channels){
            case 1u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 2u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = a;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 3u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = g;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = b;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 4u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = g;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = b;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = a;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            }
        }
    }
    return false;
}
bool edk::retro::RetroPalette::setColor(edk::uint32 position,edk::uint32 r,edk::uint32 g,edk::uint32 b){
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //set the palette inside the color
            switch(this->channels){
            case 1u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 2u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = 0xFF*sizeof(color);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 3u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = g;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = b;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 4u:
            {
                color = 0u;
                color = r;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = g;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = b;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = 0xFF*sizeof(color);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            }
        }
    }
    return false;
}
bool edk::retro::RetroPalette::setColor(edk::uint32 position,edk::uint32 g,edk::uint32 a){
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //set the palette inside the color
            switch(this->channels){
            case 1u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 2u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = a;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 3u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 4u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = a;
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            }
        }
    }
    return false;
}
bool edk::retro::RetroPalette::setColor(edk::uint32 position,edk::uint32 g){
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //set the palette inside the color
            switch(this->channels){
            case 1u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 2u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = 0xFF*sizeof(color);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 3u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            case 4u:
            {
                color = 0u;
                color = g;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
                color = 0u;
                color = 0xFF*sizeof(color);
                temp+=this->bytesPerChannel;
                edkMemCpy(temp,&color,this->bytesPerChannel);
            }
                break;
            }
        }
    }
    return false;
}
//CHANNELS
edk::uint8 edk::retro::RetroPalette::getColorR8(edk::uint32 position){
    edk::uint8 ret = 0u;
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //
            switch(this->channels){
            case 1u:
            {
            }
                break;
            case 2u:
            {
            }
                break;
            case 3u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            case 4u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            }
        }
    }
    return ret;
}
edk::uint8 edk::retro::RetroPalette::getColorG8(edk::uint32 position){
    edk::uint8 ret;
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //
            switch(this->channels){
            case 1u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            case 2u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            case 3u:
            {
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            case 4u:
            {
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            }
        }
    }
    return ret;
}
edk::uint8 edk::retro::RetroPalette::getColorB8(edk::uint32 position){
    edk::uint8 ret;
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //
            switch(this->channels){
            case 1u:
            {
            }
                break;
            case 2u:
            {
            }
                break;
            case 3u:
            {
                temp+=this->bytesPerChannel;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            case 4u:
            {
                temp+=this->bytesPerChannel;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            }
        }
    }
    return ret;
}
edk::uint8 edk::retro::RetroPalette::getColorA8(edk::uint32 position){
    edk::uint8 ret;
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //
            switch(this->channels){
            case 1u:
            {
            }
                break;
            case 2u:
            {
            }
                break;
            case 3u:
            {
                temp+=this->bytesPerChannel;
                temp+=this->bytesPerChannel;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            case 4u:
            {
                temp+=this->bytesPerChannel;
                temp+=this->bytesPerChannel;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            }
        }
    }
    return ret;
}
edk::uint16 edk::retro::RetroPalette::getColorR16(edk::uint32 position){
    edk::uint16 ret = 0u;
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //
            switch(this->channels){
            case 1u:
            {
            }
                break;
            case 2u:
            {
            }
                break;
            case 3u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            case 4u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            }
        }
    }
    return ret;
}
edk::uint16 edk::retro::RetroPalette::getColorG16(edk::uint32 position){
    edk::uint16 ret;
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //
            switch(this->channels){
            case 1u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            case 2u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            case 3u:
            {
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            case 4u:
            {
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            }
        }
    }
    return ret;
}
edk::uint16 edk::retro::RetroPalette::getColorB16(edk::uint32 position){
    edk::uint16 ret;
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //
            switch(this->channels){
            case 1u:
            {
            }
                break;
            case 2u:
            {
            }
                break;
            case 3u:
            {
                temp+=this->bytesPerChannel;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            case 4u:
            {
                temp+=this->bytesPerChannel;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            }
        }
    }
    return ret;
}
edk::uint16 edk::retro::RetroPalette::getColorA16(edk::uint32 position){
    edk::uint16 ret;
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //
            switch(this->channels){
            case 1u:
            {
            }
                break;
            case 2u:
            {
            }
                break;
            case 3u:
            {
                temp+=this->bytesPerChannel;
                temp+=this->bytesPerChannel;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            case 4u:
            {
                temp+=this->bytesPerChannel;
                temp+=this->bytesPerChannel;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret = color;
            }
                break;
            }
        }
    }
    return ret;
}
//COLORS
edk::color1ui8 edk::retro::RetroPalette::getColor1ui8(edk::uint32 position){
    edk::color1ui8 ret;
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //
            switch(this->channels){
            case 1u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
            }
                break;
            case 2u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
            }
                break;
            case 3u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
            }
                break;
            case 4u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
            }
                break;
            }
        }
    }
    return ret;
}
edk::color2ui8 edk::retro::RetroPalette::getColor2ui8(edk::uint32 position){
    edk::color2ui8 ret;
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //
            switch(this->channels){
            case 1u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
                ret.a = 0xFF*sizeof(ret.a);
            }
                break;
            case 2u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.a = color;
            }
                break;
            case 3u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
                ret.a = 0xFF*sizeof(ret.a);
            }
                break;
            case 4u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
                temp+=this->bytesPerChannel;
                temp+=this->bytesPerChannel;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.a = color;
            }
                break;
            }
        }
    }
    return ret;
}
edk::color3ui8 edk::retro::RetroPalette::getColor3ui8(edk::uint32 position){
    edk::color3ui8 ret;
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //
            switch(this->channels){
            case 1u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.r = color;
                ret.g = color;
                ret.b = color;
            }
                break;
            case 2u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.r = color;
                ret.g = color;
                ret.b = color;
            }
                break;
            case 3u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.r = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.b = color;
            }
                break;
            case 4u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.r = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.b = color;
            }
                break;
            }
        }
    }
    return ret;
}
edk::color4ui8 edk::retro::RetroPalette::getColor4ui8(edk::uint32 position){
    edk::color4ui8 ret;
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //
            switch(this->channels){
            case 1u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.r = color;
                ret.g = color;
                ret.b = color;
                ret.a = 0xFF*sizeof(ret.a);
            }
                break;
            case 2u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.r = color;
                ret.g = color;
                ret.b = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.a = color;
            }
                break;
            case 3u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.r = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.b = color;
                ret.a = 0xFF*sizeof(ret.a);
            }
                break;
            case 4u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.r = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.b = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.a = color;
            }
                break;
            }
        }
    }
    return ret;
}
edk::color1ui16 edk::retro::RetroPalette::getColor1ui16(edk::uint32 position){
    edk::color1ui16 ret;
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //
            switch(this->channels){
            case 1u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
            }
                break;
            case 2u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
            }
                break;
            case 3u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
            }
                break;
            case 4u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
            }
                break;
            }
        }
    }
    return ret;
}
edk::color2ui16 edk::retro::RetroPalette::getColor2ui16(edk::uint32 position){
    edk::color2ui16 ret;
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //
            switch(this->channels){
            case 1u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
                ret.a = 0xFF*sizeof(ret.a);
            }
                break;
            case 2u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.a = color;
            }
                break;
            case 3u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
                ret.a = 0xFF*sizeof(ret.a);
            }
                break;
            case 4u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
                temp+=this->bytesPerChannel;
                temp+=this->bytesPerChannel;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.a = color;
            }
                break;
            }
        }
    }
    return ret;
}
edk::color3ui16 edk::retro::RetroPalette::getColor3ui16(edk::uint32 position){
    edk::color3ui16 ret;
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //
            switch(this->channels){
            case 1u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.r = color;
                ret.g = color;
                ret.b = color;
            }
                break;
            case 2u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.r = color;
                ret.g = color;
                ret.b = color;
            }
                break;
            case 3u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.r = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.b = color;
            }
                break;
            case 4u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.r = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.b = color;
            }
                break;
            }
        }
    }
    return ret;
}
edk::color4ui16 edk::retro::RetroPalette::getColor4ui16(edk::uint32 position){
    edk::color4ui16 ret;
    if(this->havePalette()){
        if(position < this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //
            switch(this->channels){
            case 1u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.r = color;
                ret.g = color;
                ret.b = color;
                ret.a = 0xFF*sizeof(ret.a);
            }
                break;
            case 2u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.r = color;
                ret.g = color;
                ret.b = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.a = color;
            }
                break;
            case 3u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.r = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.b = color;
                ret.a = 0xFF*sizeof(ret.a);
            }
                break;
            case 4u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.r = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.g = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.b = color;
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                ret.a = color;
            }
                break;
            }
        }
    }
    return ret;
}

bool edk::retro::RetroPalette::swapColor(edk::uint32 start,edk::uint32 end){
    if(this->havePalette() && this->havePosition(start) && this->havePosition(end)){
        edk::uint8* tempStart=&this->vec[start * this->channels * this->bytesPerChannel];
        edk::uint8* tempEnd=&this->vec[end* this->channels * this->bytesPerChannel];
        edk::uint32 color;
        for(edk::uint8 i=0u;i<this->channels;i++){
            color=0u;
            edkMemCpy(&color,tempStart,this->bytesPerChannel);
            edkMemCpy(tempStart,tempEnd,this->bytesPerChannel);
            edkMemCpy(tempEnd,&color,this->bytesPerChannel);
            tempStart+=this->bytesPerChannel;
            tempEnd+=this->bytesPerChannel;
        }
        return true;
    }
    return false;
}

bool edk::retro::RetroPalette::equal(edk::retro::RetroPalette* palette){
    if(palette){
        //compare palette
        if(this->havePalette() && palette->havePalette()){
            if(this->size == palette->size
                    && this->channels == palette->channels
                    && this->bytesPerChannel == palette->bytesPerChannel
                    ){
                if(!edkMemCmp(this->vec,palette->vec,this->lenght)){
                    return true;
                }
            }
        }
    }
    return false;
}
bool edk::retro::RetroPalette::clone(edk::retro::RetroPalette* palette){
    if(palette){
        //compare palette
        if(palette->havePalette()){
            if(this->copyPalette(palette->vec,palette->size,palette->channels,palette->bytesPerChannel)){
                return true;
            }
        }
    }
    return false;
}

void edk::retro::RetroPalette::printPosition(edk::uint32 position){
    if(this->havePalette()){
        if(position <= this->size){
            edk::uint8* temp=&this->vec[position * this->channels * this->bytesPerChannel];
            edk::uint32 color;
            //
            switch(this->channels){
            case 1u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                printf("[%u]",color);
            }
                break;
            case 2u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                printf("[%u,",color);
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                printf("%u]",color);
            }
                break;
            case 3u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                printf("[%u,",color);
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                printf("%u,",color);
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                printf("%u]",color);
            }
                break;
            case 4u:
            {
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                printf("[%u,",color);
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                printf("%u,",color);
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                printf("%u,",color);
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                printf("%u]",color);
            }
                break;
            }
        }
    }
}
void edk::retro::RetroPalette::print(){
    if(this->havePalette()){
        edk::uint8* temp=this->vec;
        edk::uint32 color;
        //
        switch(this->channels){
        case 1u:
        {
            for(edk::uint32 i=0u;i<this->size;i++){
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                if(i==(this->size-1u)){
                    printf("[%u]",color);
                }
                else{
                    printf("[%u],",color);
                }
                temp+=this->bytesPerChannel;
            }
        }
            break;
        case 2u:
        {
            for(edk::uint32 i=0u;i<this->size;i++){
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                printf("[%u,",color);
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                if(i==(this->size-1u)){
                    printf("%u]",color);
                }
                else{
                    printf("%u],",color);
                }
                temp+=this->bytesPerChannel;
            }
        }
            break;
        case 3u:
        {
            for(edk::uint32 i=0u;i<this->size;i++){
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                printf("[%u,",color);
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                printf("%u,",color);
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                if(i==(this->size-1u)){
                    printf("%u]",color);
                }
                else{
                    printf("%u],",color);
                }
                temp+=this->bytesPerChannel;
            }
        }
            break;
        case 4u:
        {
            for(edk::uint32 i=0u;i<this->size;i++){
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                printf("[%u,",color);
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                printf("%u,",color);
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                printf("%u,",color);
                temp+=this->bytesPerChannel;
                color=0u;
                edkMemCpy(&color,temp,this->bytesPerChannel);
                if(i==(this->size-1u)){
                    printf("%u]",color);
                }
                else{
                    printf("%u],",color);
                }
                temp+=this->bytesPerChannel;
            }
        }
            break;
        }
    }
}
