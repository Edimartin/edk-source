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
