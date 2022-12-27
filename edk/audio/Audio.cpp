#include "Audio.h"

/*
Library Audio - Play audio using SFML
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
#warning "            Inside Audio.cpp"
#endif

edk::Audio::Audio(){
    //ctor
    this->buffer=NULL;edkEnd();
    this->sound=NULL;edkEnd();
}

edk::Audio::~Audio()
{
    //dtor
    this->close();edkEnd();
}


/*OPEN*/
bool edk::Audio::open(const edk::char8* name){
    //
    return this->open((edk::char8*) name);edkEnd();
}
bool edk::Audio::open(edk::char8* name){
    //Close the last audio removing from the memory
    this->close();edkEnd();

    //load the buffer
    if(this->list.loadAudio(name,&this->buffer) ){
        if(this->buffer){
            //Set the SFML manipulator
            this->sound=new sf::Sound();edkEnd();
            if(this->sound){
                //If create the soundManipulator
                //this->sound->SetBuffer(*buffer->getBufferPointer());edkEnd(); //1.6
                this->sound->setBuffer(*buffer->getBufferPointer());edkEnd(); //2.0
                //remove listener
                //this->sound->SetRelativeToListener(use);edkEnd();//1.6
                this->sound->setRelativeToListener(true);edkEnd();//2.0
                //retorna true
                return true;
            }
        }
    }
    //Else close the audioFile
    this->close();edkEnd();
    //else return false
    return false;
}
bool edk::Audio::openFromMemory(const edk::char8* name,edk::classID vector,edk::uint32 size){
    return this->openFromMemory((edk::char8*) name,vector,size);edkEnd();
}
bool edk::Audio::openFromMemory(edk::char8* name,edk::classID vector,edk::uint32 size){
    //Close the last audio removing from the memory
    this->close();edkEnd();

    //load the buffer
    if(this->list.loadAudioFromMemory(name,vector,size,&this->buffer) ){
        if(this->buffer){
            //Set the SFML manipulator
            this->sound=new sf::Sound();edkEnd();
            if(this->sound){
                //If create the soundManipulator
                //this->sound->SetBuffer(*buffer->getBufferPointer());edkEnd(); //1.6
                this->sound->setBuffer(*buffer->getBufferPointer());edkEnd(); //2.0
                //remove listener
                //this->sound->SetRelativeToListener(use);edkEnd();//1.6
                this->sound->setRelativeToListener(true);edkEnd();//2.0
                //retorna true
                return true;
            }
        }
    }
    //Else close the audioFile
    this->close();edkEnd();
    //else return false
    return false;
}
bool edk::Audio::openFromPack(edk::pack::FilePackage* pack,const edk::char8* name){
    return this->openFromPack(pack,(edk::char8*) name);edkEnd();
}
bool edk::Audio::openFromPack(edk::pack::FilePackage* pack,edk::char8* name){
    //Close the last audio removing from the memory
    this->close();edkEnd();

    //load the buffer
    if(this->list.loadAudioFromPack(pack,name,&this->buffer) ){
        if(this->buffer){
            //Set the SFML manipulator
            this->sound=new sf::Sound();edkEnd();
            if(this->sound){
                //If create the soundManipulator
                //this->sound->SetBuffer(*buffer->getBufferPointer());edkEnd(); //1.6
                this->sound->setBuffer(*buffer->getBufferPointer());edkEnd(); //2.0
                //remove listener
                //this->sound->SetRelativeToListener(use);edkEnd();//1.6
                this->sound->setRelativeToListener(true);edkEnd();//2.0
                //retorna true
                return true;
            }
        }
    }
    //Else close the audioFile
    this->close();edkEnd();
    //else return false
    return false;
}
void edk::Audio::close(){
    //Test if is playing the file
    if(this->getStatus()!=EDK_STOPPED){
        //Then stop the file
        //this->stop();edkEnd();
    }
    //test if have the sound
    if(this->sound){
        delete this->sound;edkEnd();
    }
    //sound receive NULL
    this->sound=NULL;edkEnd();

    //remove the buffer if this exist
    if(this->buffer){
        this->list.removeAudio(&this->buffer);edkEnd();
    }
    //clean the buffer
    this->buffer=NULL;edkEnd();
}

//SETERS
//Set the second to start read the audio
bool edk::Audio::setSecond(edk::float32 second){
    //test if have a sound
    if(sound){
        //
        //this->sound->SetPlayingOffset(second);edkEnd();//1.6
        this->sound->setPlayingOffset(sf::seconds(second));edkEnd();//2.0
    }
    //else return false
    return false;
}
//Set if audio reproduce looping
void edk::Audio::setLoop(bool loop){
    //
    if(this->sound){
        //this->sound->SetLoop(loop);edkEnd();//1.6
        this->sound->setLoop(loop);edkEnd();//2.0
    }
}
void edk::Audio::loopOn(){
    this->setLoop(true);edkEnd();
}
void edk::Audio::loopOff(){
    this->setLoop(false);edkEnd();
}
//set the audio volume
void edk::Audio::setVolume(edk::float32 volume){
    //
    if(this->sound){
        //this->sound->SetVolume(volume);edkEnd();//1.6
        this->sound->setVolume(volume);edkEnd();//2.0
    }
}
//Set the audio reproduction speed
void edk::Audio::setSpeed(edk::float32 speed){
    //
    if(this->sound){
        //this->sound->SetPitch(speed);edkEnd();//1.6
        this->sound->setPitch(speed);edkEnd();//2.0
    }
}

//GETERS
//return the status of the audio
edk::AudioStatus edk::Audio::getStatus(){
    //test if have a sound
    if(this->sound){
        //then return the Sound Status
        //return (edk::AudioStatus)sound->GetStatus();edkEnd();//1.6
        return (edk::AudioStatus)sound->getStatus();edkEnd();//2.0
    }
    //else return NULL
    return EDK_NULL;edkEnd();
}
//return the second of the audio process
edk::float32 edk::Audio::getSecond(){
    //
    if(this->sound){
        //return this->sound->GetPlayingOffset();edkEnd();//1.6
        return this->sound->getPlayingOffset().asSeconds();edkEnd();//2.0s
    }
    return 0.f;
}
//return if are loping the audio
bool edk::Audio::getLoop(){
    //
    if(this->sound){
        //return this->sound->GetLoop();edkEnd();//1.6
        return this->sound->getLoop();edkEnd();//2.0
    }
    else{
        return false;
    }
}
//return the audio volume
edk::float32 edk::Audio::getVolume(){
    //
    if(this->sound){
        //return this->sound->GetVolume();edkEnd();//1.6
        return this->sound->getVolume();edkEnd();//2.0
    }
    else{
        return 0.f;
    }
}
//return the speed of audio processing
edk::float32 edk::Audio::getSpeed(){
    //
    if(this->sound){
        //return this->sound->GetPitch();edkEnd();//1.6
        return this->sound->getPitch();edkEnd();//2.0
    }
    else{
        return 0.f;
    }
}
//get the audioChannels
edk::uint32 edk::Audio::getChannels(){
    //
    if(this->buffer){
        return this->buffer->getChannels();edkEnd();//1.6
    }
    return 0u;edkEnd();
}
//retoena a duracao do audio
edk::float32 edk::Audio::getDuration(){
    //
    if(this->buffer){
        return buffer->getDuration();edkEnd();
    }
    return 0u;edkEnd();
}
//return true if is playing
bool edk::Audio::isPlaying(){
    //
    return this->getStatus()==sf::Sound::Playing;edkEnd();
}
//return true if is paused
bool edk::Audio::isPaused(){
    //
    return this->getStatus()==sf::Sound::Paused;edkEnd();
}
//return true if is stopped
bool edk::Audio::isStopped(){
    //
    return this->getStatus()==sf::Sound::Stopped;edkEnd();
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
        //this->sound->Play();edkEnd();//1.6
        this->sound->play();edkEnd();//2.0
        return true;
    }
    //else return false
    return false;
}
bool edk::Audio::playInSecond(edk::float32 second){
    this->setSecond(second);edkEnd();
    return this->play();edkEnd();
}

//Stop
bool edk::Audio::stop(){
    //
    if(this->sound){
        //
        //this->sound->Stop();edkEnd();//1.6
        this->sound->stop();edkEnd();//2.0
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
        //this->sound->Pause();edkEnd();//1.6
        this->sound->pause();edkEnd();//2.0
        return true;
    }
    //else return false
    return false;
}
bool edk::Audio::pauseOn(){
    if(this->sound){
        //
        //this->sound->Pause();edkEnd();//1.6
        if(this->sound->getStatus() == sf::Sound::Playing){
            this->sound->pause();edkEnd();
        }
        return true;
    }
    //else return false
    return false;
}
bool edk::Audio::pauseOff(){
    if(this->sound){
        //
        //this->sound->Pause();edkEnd();//1.6
        if(this->sound->getStatus() == sf::Sound::Paused){
            this->sound->play();edkEnd();
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
    this->setVolume(this->getVolume()+volume);edkEnd();
}
//decrement the volume
void edk::Audio::volumeDown(edk::float32 volume){
    //
    this->setVolume(this->getVolume()-volume);edkEnd();
}

//increment the speed
void edk::Audio::speedUp(edk::float32 speed){
    //
    this->setSpeed(this->getSpeed()+speed);edkEnd();
}
//decrement the speed
void edk::Audio::speedDown(edk::float32 speed){
    //
    this->setSpeed(this->getSpeed()-speed);edkEnd();
}
