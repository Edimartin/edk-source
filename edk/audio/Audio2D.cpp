#include "Audio2D.h"

/*
Library Audio2D - edk::Audio in a 2D World
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
#warning "            Inside Audio2D.cpp"
#endif

edk::Audio2D::Audio2D()
{
    //ctor
    this->haveListener=false;
}

edk::Audio2D::~Audio2D()
{
    //dtor
}

//OPEN
bool edk::Audio2D::open(const char* name){
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
bool edk::Audio2D::openFromMemory(const char* name,edk::classID vector,edk::uint32 size){
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
bool edk::Audio2D::openFromPack(edk::pack::FilePackage* pack,const char* name){
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
    //sf::Listener::SetPosition(position.x,position.y,0.f);//1.6
    sf::Listener::setPosition(position.x,position.y,0.f);//2.0
}
//Set the listener lookAt
void edk::Audio2D::setListenerLookAt2D(edk::vec2f32 lookAt){
    //
    //sf::Listener::SetTarget(lookAt.x,lookAt.y,0.f);//1.6
    sf::Listener::setDirection(lookAt.x,lookAt.y,0.f);//2.0
}

//SETERS
//Set the position of the audio in the cene
bool edk::Audio2D::setPosition2D(edk::vec2f32 position){
    //save the position
    this->position=position;
    //
    if(this->sound){
        //
        //this->sound->SetPosition(sf::Vector3f(this->position.x,this->position.y,0.f));//1.6
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
        //this->sound->SetRelativeToListener(use);//1.6
        this->sound->setRelativeToListener(!use);//2.0
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
