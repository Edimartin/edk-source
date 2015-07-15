#include "AudioBuffer.h"

/*
Library AudioBuffer - Load an entire audio file
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
#warning "            Inside AudioBuffer.cpp"
#endif

edk::AudioBuffer::AudioBuffer()
{
    //ctor
    this->buffer=NULL;
}

edk::AudioBuffer::~AudioBuffer()
{
    //delete the buffer
    this->deleteBuffer();
}


//LOAD
//load the buffer from a file
bool edk::AudioBuffer::loadBufferFromFile(const char* name){
    return loadBufferFromFile((edk::char8*) name);
}
bool edk::AudioBuffer::loadBufferFromFile(edk::char8* name){
    //delete the last buffer
    this->deleteBuffer();
    //test if the file exist
    if(edk::File::fileExist(name)){
        //open the file using SFML
        this->buffer=new sf::SoundBuffer;
        //load from the file
        //if (this->buffer->LoadFromFile((const char*)name) ){//1.6
        if (this->buffer->loadFromFile((const char*)name) ){//2.0
            //then set the name
            this->setName(name);
            //return true
            return true;
        }
    }
    //else return false
    return false;
}

//DELETE
//delete the buffer
void edk::AudioBuffer::deleteBuffer(){
    //test if the buffer are alloced//then delete
    if(this->buffer)
        delete this->buffer;
    this->buffer=NULL;
}

//GETER
//return the buffer pointer
sf::SoundBuffer* edk::AudioBuffer::getBufferPointer(){
    //
    return this->buffer;
}
//return the channels
edk::uint32 edk::AudioBuffer::getChannels(){
    //test if the buffer is alloc
    if(this->buffer){
        //
        //this->buffer->GetChannelsCount();//1.6
        this->buffer->getChannelCount();//2.0
    }
    //else return 0u
    return 0u;
}
//return the audio duration
edk::float32 edk::AudioBuffer::getDuration(){
    //test if the buffer is alloc
    if(this->buffer){
        //
        //this->buffer->GetDuration();//1.6
        this->buffer->getDuration();//2.0
    }
    //else return 0.0
    return 0.0f;
}
