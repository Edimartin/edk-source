#include "Audio2D.h"

/*
Library Audio2D - edk::Audio in a 2D World
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
#pragma message "            Inside Audio2D.cpp"
#endif

edk::Audio2D::Audio2D(){
    this->classThis=NULL;
    this->Constructor();
}

edk::Audio2D::~Audio2D(){
    this->Destructor();
}

void edk::Audio2D::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;
        this->haveListener=false;
    }
}
void edk::Audio2D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
    edk::Audio::Destructor();
}

//OPEN
bool edk::Audio2D::open(const edk::char8* name){
    //
    return this->open((edk::char8*) name);
}
bool edk::Audio2D::open(edk::char8* name){
    //open the audio
    if(edk::Audio::open(name)){
        //then set the position of the audio
        this->setPosition2D(this->position);
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::Audio2D::openFromMemory(const edk::char8* name,edk::classID vector,edk::uint32 size){
    return this->openFromMemory((edk::char8*) name,vector,size);
}
bool edk::Audio2D::openFromMemory(edk::char8* name,edk::classID vector,edk::uint32 size){
    //open the audio
    if(edk::Audio::openFromMemory(name,vector,size)){
        //then set the position of the audio
        this->setPosition2D(this->position);
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::Audio2D::openFromPack(edk::pack::FilePackage* pack,const edk::char8* name){
    return this->openFromPack(pack,(edk::char8*) name);
}
bool edk::Audio2D::openFromPack(edk::pack::FilePackage* pack,edk::char8* name){
    //open the audio
    if(edk::Audio::openFromPack(pack,name)){
        //then set the position of the audio
        this->setPosition2D(this->position);
        //then return true
        return true;
    }
    //else return false
    return false;
}

//Set the listener position
void edk::Audio2D::setListenerPosition2D(edk::vec2f32 position){
    //
    //sf::Listener::SetPosition(position.x,position.y,0.f); //1.6
    sf::Listener::setPosition(position.x,position.y,0.f); //2.0
}
//Set the listener lookAt
void edk::Audio2D::setListenerLookAt2D(edk::vec2f32 lookAt){
    //
    //sf::Listener::SetTarget(lookAt.x,lookAt.y,0.f); //1.6
    sf::Listener::setDirection(lookAt.x,lookAt.y,0.f); //2.0
}

//SETERS
//Set the position of the audio in the cene
bool edk::Audio2D::setPosition2D(edk::vec2f32 position){
    //save the position
    this->position=position;
    //
    if(this->sound){
        //
        //this->sound->SetPosition(sf::Vector3f(this->position.x,this->position.y,0.f)); //1.6
        this->sound->setPosition(sf::Vector3f(this->position.x,this->position.y,0.f));
        return true;
    }
    //else return false
    return false;
}
//set if are using the listener
bool edk::Audio2D::useListener(bool use){
    //clean haveListener
    this->haveListener=false;
    //test if have a sound
    if(this->sound){
        //the set are using the listener
        //this->sound->SetRelativeToListener(use); //1.6
        this->sound->setRelativeToListener(!use); //2.0
        //save haveListener
        this->haveListener=use;
        //return true
        return true;
    }
    //else return false
    return false;
}

//GETERS
//return if are using the listener
bool edk::Audio2D::usingListener(){
    //
    return this->haveListener;
}
