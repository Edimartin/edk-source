#include "Audio3D.h"

/*
Library Audio3D - edk::Audio in a 3D World
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
#warning "            Inside Audio3D.cpp"
#endif

edk::Audio3D::Audio3D()
{
    //ctor
}

edk::Audio3D::~Audio3D()
{
    //dtor
}

//OPEN
bool edk::Audio3D::open(const char* name){
    //
    return this->open((edk::char8*) name);
}
bool edk::Audio3D::open(edk::char8* name){
    //open the audio
    if(edk::Audio::open(name)){
        //then set the position of the audio
        this->setPosition3D(this->position);
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::Audio3D::openFromMemory(const char* name,edk::classID vector,edk::uint32 size){
    return this->openFromMemory((edk::char8*) name,vector,size);
}
bool edk::Audio3D::openFromMemory(edk::char8* name,edk::classID vector,edk::uint32 size){
    //open the audio
    if(edk::Audio::openFromMemory(name,vector,size)){
        //then set the position of the audio
        this->setPosition3D(this->position);
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::Audio3D::openFromPack(edk::pack::FilePackage* pack,const char* name){
    return this->openFromPack(pack,(edk::char8*) name);
}
bool edk::Audio3D::openFromPack(edk::pack::FilePackage* pack,edk::char8* name){
    //open the audio
    if(edk::Audio::openFromPack(pack,name)){
        //then set the position of the audio
        this->setPosition3D(this->position);
        //then return true
        return true;
    }
    //else return false
    return false;
}

//Set the listener position
void edk::Audio3D::setListenerPosition3D(edk::vec3f32 position){
    //
    //sf::Listener::SetPosition(position.x,position.y,position.z);//1.6
    sf::Listener::setPosition(position.x,position.y,position.z);//2.0
}
//Set the listener lookAt
void edk::Audio3D::setListenerLookAt3D(edk::vec3f32 lookAt){
    //
    //sf::Listener::SetTarget(lookAt.x,lookAt.y,lookAt.z);//1.6
    sf::Listener::setDirection(lookAt.x,lookAt.y,lookAt.z);//2.0
}

//SETERS
//Set the position of the audio in the cene
bool edk::Audio3D::setPosition3D(edk::vec3f32 position){
    //save the position
    this->position=position;
    //
    if(this->sound){
        //
        //this->sound->SetPosition(sf::Vector3f(this->position.x,this->position.y,this->position.z));//1.6
        this->sound->setPosition(sf::Vector3f(this->position.x,this->position.y,this->position.z));//2.0
        return true;
    }
    //else return false
    return false;
}
//set if are using the listener
bool edk::Audio3D::useListener(bool use){
    //clean haveListener
    this->haveListener=false;
    //test if have a sound
    if(this->sound){
        //the set are using the listener
        //this->sound->SetRelativeToListener(use);//1.6
        this->sound->setRelativeToListener(use);//2.0
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
bool edk::Audio3D::usingListener(){
    //
    return this->haveListener;
}
