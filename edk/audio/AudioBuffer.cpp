#include "AudioBuffer.h"

/*
Library AudioBuffer - Load an entire audio file
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
#pragma message "            Inside AudioBuffer.cpp"
#endif

edk::AudioBuffer::AudioBuffer(){
    this->classThis=NULL;
    this->Constructor();
}

edk::AudioBuffer::~AudioBuffer(){
    this->Destructor();
}

void edk::AudioBuffer::Constructor(){
    edk::ObjectWithName::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        this->buffer=NULL;
    }
}
void edk::AudioBuffer::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        //delete the buffer
        this->deleteBuffer();
    }
    edk::ObjectWithName::Destructor();
}

//LOAD
//load the buffer from a file
bool edk::AudioBuffer::loadBufferFromFile(const edk::char8* name){
    return loadBufferFromFile((edk::char8*) name);
}
bool edk::AudioBuffer::loadBufferFromFile(edk::char8* name){
    //delete the last buffer
    this->deleteBuffer();
    //test if the file exist
    if(edk::File::fileExist(name)){
        //open the file using SFML
        this->buffer=new sf::SoundBuffer;
        if(this->buffer){
            //load from the file
            //if(this->buffer->LoadFromFile((const edk::char8*)name) ){//1.6
            if(this->buffer->loadFromFile((const edk::char8*)name) ){//2.0
                //then set the name
                this->setName(name);
                //return true
                return true;
            }
            delete this->buffer;
            this->buffer=NULL;
        }
    }
    //else return false
    return false;
}
bool edk::AudioBuffer::loadBufferFromMemory(const edk::char8* name,edk::classID vector,edk::uint32 size){
    return this->loadBufferFromMemory((edk::char8*) name,vector,size);
}
bool edk::AudioBuffer::loadBufferFromMemory(edk::char8* name,edk::classID vector,edk::uint32 size){
    //delete the last buffer
    this->deleteBuffer();
    //test if the file exist
    if(name && vector && size){
        //open the file using SFML
        this->buffer=new sf::SoundBuffer;
        if(this->buffer){
            //load from the file
            //if(this->buffer->loadFromMemory(vector,size)){//1.6
            if(this->buffer->loadFromMemory(vector,size)){//2.0
                //then set the name
                this->setName(name);
                //return true
                return true;
            }
            delete this->buffer;
            this->buffer=NULL;
        }
    }
    //else return false
    return false;
}
bool edk::AudioBuffer::loadBufferFromPack(edk::pack::FilePackage* pack,const edk::char8* name){
    return this->loadBufferFromPack(pack,(edk::char8*) name);
}
bool edk::AudioBuffer::loadBufferFromPack(edk::pack::FilePackage* pack,edk::char8* name){
    //delete the last buffer
    this->deleteBuffer();
    if(pack && name){
        //test if the file exist
        pack->mutex.lock();
        if(pack->goToFile(name)){
            if(pack->readFileToBuffer()){
                //                if(pack->readFileToBuffer(name)){
                //open the file using SFML
                this->buffer=new sf::SoundBuffer;
                if(this->buffer){
                    //load from the file
                    //if(this->buffer->Memory(pack->getBuffer(),pack->getBufferSize()) ){//1.6
                    if(this->buffer->loadFromMemory(pack->getBuffer(),pack->getBufferSize())){//2.0
                        pack->mutex.unlock();
                        //then set the name
                        this->setName(name);
                        //return true
                        return true;
                    }
                    else{
                        pack->mutex.unlock();
                    }
                    delete this->buffer;
                    this->buffer=NULL;
                }
                else{
                    pack->mutex.unlock();
                }
                //                }
            }
            else{
                pack->mutex.unlock();
            }
        }
        else{
            pack->mutex.unlock();
        }
    }
    //else return false
    return false;
}

//DELETE
//delete the buffer
void edk::AudioBuffer::deleteBuffer(){
    //test if the buffer are alloced//then delete
    if(this->buffer){
        delete this->buffer;
    }
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
        //this->buffer->GetChannelsCount(); //1.6
        this->buffer->getChannelCount(); //2.0
    }
    //else return 0u
    return 0u;
}
//return the audio duration
edk::float32 edk::AudioBuffer::getDuration(){
    //test if the buffer is alloc
    if(this->buffer){
        //
        //this->buffer->GetDuration(); //1.6
        sf::Time ret = this->buffer->getDuration(); //2.0
        return ret.asSeconds();
    }
    //else return 0.0
    return 0.0f;
}
