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
#pragma message "            Inside Audio.cpp"
#endif

edk::Audio::Audio(){
    this->classThis=NULL;
    this->Constructor();
}

edk::Audio::~Audio(){
    this->Destructor();
}

void edk::Audio::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        this->list.Constructor();

        this->buffer=NULL;
        this->sound=NULL;
        this->looping=false;
    }
}
void edk::Audio::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->close();

        this->list.Destructor();
    }
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
                //this->sound->SetBuffer(*buffer->getBufferPointer());  //1.6
                this->sound->setBuffer(*buffer->getBufferPointer());  //2.0
                //remove listener
                //this->sound->SetRelativeToListener(use); //1.6
                this->sound->setRelativeToListener(true); //2.0
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
                //this->sound->SetBuffer(*buffer->getBufferPointer());  //1.6
                this->sound->setBuffer(*buffer->getBufferPointer());  //2.0
                //remove listener
                //this->sound->SetRelativeToListener(use); //1.6
                this->sound->setRelativeToListener(true); //2.0
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
                //this->sound->SetBuffer(*buffer->getBufferPointer());  //1.6
                this->sound->setBuffer(*buffer->getBufferPointer());  //2.0
                //remove listener
                //this->sound->SetRelativeToListener(use); //1.6
                this->sound->setRelativeToListener(true); //2.0
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
    if(this->sound){
        delete this->sound;
    }
    //sound receive NULL
    this->sound=NULL;

    //remove the buffer if this exist
    if(this->buffer){
        this->list.removeAudio(&this->buffer);
    }
    //clean the buffer
    this->buffer=NULL;
}

//SETERS
//Set the second to start read the audio
bool edk::Audio::setSecond(edk::float32 second){
    //test if have a sound
    if(sound){
        //
        //this->sound->SetPlayingOffset(second); //1.6
        this->sound->setPlayingOffset(sf::seconds(second)); //2.0
    }
    //else return false
    return false;
}
//Set if audio reproduce looping
void edk::Audio::setLoop(bool loop){
    //
    if(this->sound){
        //this->sound->SetLoop(loop); //1.6
        this->looping=loop;
        this->sound->setLoop(loop); //2.0
    }
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
    if(this->sound){
        //this->sound->SetVolume(volume); //1.6
        this->sound->setVolume(volume); //2.0
    }
}
//Set the audio reproduction speed
void edk::Audio::setSpeed(edk::float32 speed){
    //
    if(this->sound){
        //this->sound->SetPitch(speed); //1.6
        this->sound->setPitch(speed); //2.0
    }
}

//GETERS
//return the status of the audio
edk::AudioStatus edk::Audio::getStatus(){
    //test if have a sound
    if(this->sound){
        //then return the Sound Status
        //return (edk::AudioStatus)sound->GetStatus(); //1.6
        return (edk::AudioStatus)sound->getStatus(); //2.0
    }
    //else return NULL
    return EDK_NULL;
}
//return the second of the audio process
edk::float32 edk::Audio::getSecond(){
    //
    if(this->sound){
        //return this->sound->GetPlayingOffset(); //1.6
        return this->sound->getPlayingOffset().asSeconds(); //2.0s
    }
    return 0.f;
}
//return if are loping the audio
bool edk::Audio::getLoop(){
    //
    if(this->sound){
        //return this->sound->GetLoop(); //1.6
        return this->sound->getLoop(); //2.0
    }
    else{
        return false;
    }
}
//return the audio volume
edk::float32 edk::Audio::getVolume(){
    //
    if(this->sound){
        //return this->sound->GetVolume(); //1.6
        return this->sound->getVolume(); //2.0
    }
    else{
        return 0.f;
    }
}
//return the speed of audio processing
edk::float32 edk::Audio::getSpeed(){
    //
    if(this->sound){
        //return this->sound->GetPitch(); //1.6
        return this->sound->getPitch(); //2.0
    }
    else{
        return 0.f;
    }
}
//get the audioChannels
edk::uint32 edk::Audio::getChannels(){
    //
    if(this->buffer){
        return this->buffer->getChannels(); //1.6
    }
    return 0u;
}
//retoena a duracao do audio
edk::float32 edk::Audio::getDuration(){
    //
    if(this->buffer){
        return buffer->getDuration();
    }
    return 0.f;
}
//return true if is playing
bool edk::Audio::isPlaying(){
    //
    return this->getStatus()==sf::Sound::Playing;
}
//return true if is paused
bool edk::Audio::isPaused(){
    //
    return this->getStatus()==sf::Sound::Paused;
}
//return true if is stopped
bool edk::Audio::isStopped(){
    //
    return this->getStatus()==sf::Sound::Stopped;
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
        //this->sound->Play(); //1.6
        this->sound->setLoop(this->looping);
        this->sound->play(); //2.0
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
        //this->sound->Stop(); //1.6
        this->sound->setLoop(false);
        this->sound->stop(); //2.0
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
        //this->sound->Pause(); //1.6
        this->sound->pause(); //2.0
        return true;
    }
    //else return false
    return false;
}
bool edk::Audio::pauseOn(){
    if(this->sound){
        //
        //this->sound->Pause(); //1.6
        if(this->sound->getStatus() == sf::Sound::Playing){
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
        //this->sound->Pause(); //1.6
        if(this->sound->getStatus() == sf::Sound::Paused){
            this->sound->setLoop(this->looping);
            this->sound->play();
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
