#include "Audio3D.h"

/*
Library Audio3D - edk::Audio in a 3D World
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
#pragma message "            Inside Audio3D.cpp"
#endif

edk::Audio3D::Audio3D(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::Audio3D::~Audio3D(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::Audio3D::Constructor(bool runFather){
    if(runFather){
        edk::Audio::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;
    }
}

//OPEN
bool edk::Audio3D::open(const edk::char8* name){
    //
    return this->open((edk::char8*) name);edkEnd();
}
bool edk::Audio3D::open(edk::char8* name){
    //open the audio
    if(edk::Audio::open(name)){
        //then set the position of the audio
        this->setPosition3D(this->position);edkEnd();
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::Audio3D::openFromMemory(const edk::char8* name,edk::classID vector,edk::uint32 size){
    return this->openFromMemory((edk::char8*) name,vector,size);edkEnd();
}
bool edk::Audio3D::openFromMemory(edk::char8* name,edk::classID vector,edk::uint32 size){
    //open the audio
    if(edk::Audio::openFromMemory(name,vector,size)){
        //then set the position of the audio
        this->setPosition3D(this->position);edkEnd();
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::Audio3D::openFromPack(edk::pack::FilePackage* pack,const edk::char8* name){
    return this->openFromPack(pack,(edk::char8*) name);edkEnd();
}
bool edk::Audio3D::openFromPack(edk::pack::FilePackage* pack,edk::char8* name){
    //open the audio
    if(edk::Audio::openFromPack(pack,name)){
        //then set the position of the audio
        this->setPosition3D(this->position);edkEnd();
        //then return true
        return true;
    }
    //else return false
    return false;
}

//Set the listener position
void edk::Audio3D::setListenerPosition3D(edk::vec3f32 position){
    //
    //sf::Listener::SetPosition(position.x,position.y,position.z);edkEnd();//1.6
    sf::Listener::setPosition(position.x,position.y,position.z);edkEnd();//2.0
}
//Set the listener lookAt
void edk::Audio3D::setListenerLookAt3D(edk::vec3f32 lookAt){
    //
    //sf::Listener::SetTarget(lookAt.x,lookAt.y,lookAt.z);edkEnd();//1.6
    sf::Listener::setDirection(lookAt.x,lookAt.y,lookAt.z);edkEnd();//2.0
}

//SETERS
//Set the position of the audio in the cene
bool edk::Audio3D::setPosition3D(edk::vec3f32 position){
    //save the position
    this->position=position;edkEnd();
    //
    if(this->sound){
        //
        //this->sound->SetPosition(sf::Vector3f(this->position.x,this->position.y,this->position.z));edkEnd();//1.6
        this->sound->setPosition(sf::Vector3f(this->position.x,this->position.y,this->position.z));edkEnd();//2.0
        return true;
    }
    //else return false
    return false;
}
//set if are using the listener
bool edk::Audio3D::useListener(bool use){
    //clean haveListener
    this->haveListener=false;edkEnd();
    //test if have a sound
    if(this->sound){
        //the set are using the listener
        //this->sound->SetRelativeToListener(use);edkEnd();//1.6
        this->sound->setRelativeToListener(use);edkEnd();//2.0
        //save haveListener
        this->haveListener=use;edkEnd();
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
    return this->haveListener;edkEnd();
}
