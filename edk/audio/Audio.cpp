#include "Audio.h"

/*
Library Audio - Play audio using SFML
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
#warning "            Inside Audio.cpp"
#endif

edk::Audio::Audio(){
    //ctor
   this->buffer=NULL;
   this->sound=NULL;
}

edk::Audio::~Audio()
{
    //dtor
    this->close();
}


/*OPEN*/
bool edk::Audio::open(const edk::char8* name){
    //
    return this->open((edk::char8*) name);
}
bool edk::Audio::open(edk::char8* name){
    //Close the last audio removing from the memory
    this->close();

    //load the buffer
    if(this->list.loadAudio(name,&this->buffer) ){
        if(this->buffer){
            //Set the SFML manipulator
            this->sound=new sf::Sound();
            if(this->sound){
                //If create the soundManipulator
                //this->sound->SetBuffer(*buffer->getBufferPointer()); //1.6
                this->sound->setBuffer(*buffer->getBufferPointer()); //2.0
                //remove listener
                //this->sound->SetRelativeToListener(use);//1.6
                this->sound->setRelativeToListener(true);//2.0
                //retorna true
                return true;
            }
        }
    }
    //Else close the audioFile
    this->close();
    //else return false
    return false;
}
bool edk::Audio::openFromMemory(const edk::char8* name,edk::classID vector,edk::uint32 size){
    return this->openFromMemory((edk::char8*) name,vector,size);
}
bool edk::Audio::openFromMemory(edk::char8* name,edk::classID vector,edk::uint32 size){
    //Close the last audio removing from the memory
    this->close();

    //load the buffer
    if(this->list.loadAudioFromMemory(name,vector,size,&this->buffer) ){
        if(this->buffer){
            //Set the SFML manipulator
            this->sound=new sf::Sound();
            if(this->sound){
                //If create the soundManipulator
                //this->sound->SetBuffer(*buffer->getBufferPointer()); //1.6
                this->sound->setBuffer(*buffer->getBufferPointer()); //2.0
                //remove listener
                //this->sound->SetRelativeToListener(use);//1.6
                this->sound->setRelativeToListener(true);//2.0
                //retorna true
                return true;
            }
        }
    }
    //Else close the audioFile
    this->close();
    //else return false
    return false;
}
bool edk::Audio::openFromPack(edk::pack::FilePackage* pack,const edk::char8* name){
    return this->openFromPack(pack,(edk::char8*) name);
}
bool edk::Audio::openFromPack(edk::pack::FilePackage* pack,edk::char8* name){
    //Close the last audio removing from the memory
    this->close();

    //load the buffer
    if(this->list.loadAudioFromPack(pack,name,&this->buffer) ){
        if(this->buffer){
            //Set the SFML manipulator
            this->sound=new sf::Sound();
            if(this->sound){
                //If create the soundManipulator
                //this->sound->SetBuffer(*buffer->getBufferPointer()); //1.6
                this->sound->setBuffer(*buffer->getBufferPointer()); //2.0
                //remove listener
                //this->sound->SetRelativeToListener(use);//1.6
                this->sound->setRelativeToListener(true);//2.0
                //retorna true
                return true;
            }
        }
    }
    //Else close the audioFile
    this->close();
    //else return false
    return false;
}
void edk::Audio::close(){
    //Test if is playing the file
    if(this->getStatus()!=EDK_STOPPED){
        //Then stop the file
        //this->stop();
    }
    //test if have the sound
    if(this->sound)
        delete this->sound;
    //sound receive NULL
    this->sound=NULL;

    //remove the buffer if this exist
    if(this->buffer)
        this->list.removeAudio(&this->buffer);
    //clean the buffer
    this->buffer=NULL;
}

//SETERS
//Set the second to start read the audio
bool edk::Audio::setSecond(edk::float32 second){
    //test if have a sound
    if(sound){
        //
        //this->sound->SetPlayingOffset(second);//1.6
        this->sound->setPlayingOffset(sf::seconds(second));//2.0
    }
    //else return false
    return false;
}
//Set if audio reproduce looping
void edk::Audio::setLoop(bool loop){
    //
   if(this->sound)
      //this->sound->SetLoop(loop);//1.6
      this->sound->setLoop(loop);//2.0
}
void edk::Audio::loopOn(){
    this->setLoop(true);
}
void edk::Audio::loopOff(){
    this->setLoop(false);
}
//set the audio volume
void edk::Audio::setVolume(edk::float32 volume){
    //
    if(this->sound)
        //this->sound->SetVolume(volume);//1.6
        this->sound->setVolume(volume);//2.0
}
//Set the audio reproduction speed
void edk::Audio::setSpeed(edk::float32 speed){
    //
    if(this->sound)
        //this->sound->SetPitch(speed);//1.6
        this->sound->setPitch(speed);//2.0
}

//GETERS
//return the status of the audio
edk::AudioStatus edk::Audio::getStatus(){
    //test if have a sound
    if(this->sound)
        //then return the Sound Status
        //return (edk::AudioStatus)sound->GetStatus();//1.6
        return (edk::AudioStatus)sound->getStatus();//2.0
    //else return NULL
    return EDK_NULL;
}
//return the second of the audio process
edk::float32 edk::Audio::getSecond(){
    //
    if(this->sound)
        //return this->sound->GetPlayingOffset();//1.6
        return this->sound->getPlayingOffset().asSeconds();//2.0s
    return 0.f;
}
//return if are loping the audio
bool edk::Audio::getLoop(){
    //
    if(this->sound)
        //return this->sound->GetLoop();//1.6
        return this->sound->getLoop();//2.0
    else
        return false;
}
//return the audio volume
edk::float32 edk::Audio::getVolume(){
    //
    if(this->sound)
        //return this->sound->GetVolume();//1.6
        return this->sound->getVolume();//2.0
    else
        return 0.f;
}
//return the speed of audio processing
edk::float32 edk::Audio::getSpeed(){
    //
    if(this->sound)
        //return this->sound->GetPitch();//1.6
        return this->sound->getPitch();//2.0
    else
        return 0.f;
}
//get the audioChannels
edk::uint32 edk::Audio::getChannels(){
    //
    if(this->buffer)
        return this->buffer->getChannels();//1.6
    return 0u;
}
//retoena a duracao do audio
edk::float32 edk::Audio::getDuration(){
    //
    if(this->buffer)
        return buffer->getDuration();
    return 0u;
}
//return true if is playing
bool edk::Audio::isPlaying(){
    //
    return this->getStatus()==EDK_PLAYING;
}
//return true if is paused
bool edk::Audio::isPaused(){
    //
    return this->getStatus()==EDK_PAUSED;
}
//return true if is stopped
bool edk::Audio::isStopped(){
    //
    return this->getStatus()==EDK_STOPPED;
}

//test if have audio
bool edk::Audio::haveAudio(){
    if(this->sound){
        return true;
    }
    return false;
}

//INTERACT
//Play
bool edk::Audio::play(){
    //
    if(this->sound){
        //
        //this->sound->Play();//1.6
        this->sound->play();//2.0
        return true;
    }
    //else return false
    return false;
}
bool edk::Audio::playInSecond(edk::float32 second){
    this->setSecond(second);
    return this->play();
}

//Stop
bool edk::Audio::stop(){
    //
    if(this->sound){
        //
        //this->sound->Stop();//1.6
        this->sound->stop();//2.0
        return true;
    }
    //else return false
    return false;
}
//Pause
bool edk::Audio::pause(){
    //
    if(this->sound){
        //
        //this->sound->Pause();//1.6
        this->sound->pause();//2.0
        return true;
    }
    //else return false
    return false;
}
bool edk::Audio::pauseOn(){
    if(this->sound){
        //
        //this->sound->Pause();//1.6
        if(this->sound->Playing){
            this->sound->pause();
        }
        return true;
    }
    //else return false
    return false;
}
bool edk::Audio::pauseOff(){
    if(this->sound){
        //
        //this->sound->Pause();//1.6
        if(!this->sound->Playing){
            this->sound->pause();
        }
        return true;
    }
    //else return false
    return false;
}

//INCREMENT DECREMENT
//increment the volume
void edk::Audio::volumeUp(edk::float32 volume){
    //
    this->setVolume(this->getVolume()+volume);
}
//decrement the volume
void edk::Audio::volumeDown(edk::float32 volume){
    //
    this->setVolume(this->getVolume()-volume);
}

//increment the speed
void edk::Audio::speedUp(edk::float32 speed){
    //
    this->setSpeed(this->getSpeed()+speed);
}
//decrement the speed
void edk::Audio::speedDown(edk::float32 speed){
    //
    this->setSpeed(this->getSpeed()-speed);
}
