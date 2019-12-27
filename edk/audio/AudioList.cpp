#include "AudioList.h"

/*
Library AudioBuffer - List of Audios used in the gameEngine
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
#warning "            Inside AudioList.cpp"
#endif

//Tree with the audioNames
edk::ObjectNameTree audioTree;

edk::AudioList::AudioList()
{
    //ctor
}

edk::AudioList::~AudioList()
{
    //dtor
}


//LOAD
bool edk::AudioList::loadAudio(const char* name, edk::AudioBuffer** retainAudio){
    //
    return this->loadAudio((edk::char8*) name, retainAudio);
}
bool edk::AudioList::loadAudio(edk::char8* name, edk::AudioBuffer** retainAudio){
    //test the name and the retainAudio
    if(name){
        if(retainAudio){
            //find the audio
            edk::AudioBuffer find;
            find.setName(name);
            edk::AudioBuffer* temp = (edk::AudioBuffer*)audioTree.getElement((edk::ObjectWithName*)&find);

            if(temp){
                //retain the audio and return true
                if(audioTree.addElement(temp,(edk::ObjectWithName**)retainAudio)){
                    //audio added. Return true
                    return true;
                }
            }
            else{
                //else create a new audio buffer
                edk::AudioBuffer* temp = new edk::AudioBuffer();
                if(temp){
                    if(temp->loadBufferFromFile(name)){
                        if(audioTree.addElement(temp,(edk::ObjectWithName**)retainAudio)){
                            //audio added. Return true
                            return true;
                        }
                        else{
                            //cant added the audio. delete temp and return false
                            temp->deleteBuffer();
                            delete temp;
                            return false;
                        }
                    }
                    else{
                        //can open the audio (the file dont exist).
                        //delete temp
                        delete temp;
                        //return false
                        return false;
                    }
                }
            }
        }
    }
    //else return false
    return false;
}
bool edk::AudioList::loadAudioFromMemory(const char* name,edk::classID vector,edk::uint32 size, edk::AudioBuffer** retainAudio){
    return this->loadAudioFromMemory((edk::char8*) name,vector,size, retainAudio);
}
bool edk::AudioList::loadAudioFromMemory(edk::char8* name,edk::classID vector,edk::uint32 size, edk::AudioBuffer** retainAudio){
    //test the name and the retainAudio
    if(name){
        if(retainAudio){
            //find the audio
            edk::AudioBuffer find;
            find.setName(name);
            edk::AudioBuffer* temp = (edk::AudioBuffer*)audioTree.getElement((edk::ObjectWithName*)&find);

            if(temp){
                //retain the audio and return true
                if(audioTree.addElement(temp,(edk::ObjectWithName**)retainAudio)){
                    //audio added. Return true
                    return true;
                }
            }
            else{
                //else create a new audio buffer
                edk::AudioBuffer* temp = new edk::AudioBuffer();
                if(temp){
                    if(temp->loadBufferFromMemory(name,vector,size)){
                        if(audioTree.addElement(temp,(edk::ObjectWithName**)retainAudio)){
                            //audio added. Return true
                            return true;
                        }
                        else{
                            //cant added the audio. delete temp and return false
                            temp->deleteBuffer();
                            delete temp;
                            return false;
                        }
                    }
                    else{
                        //can open the audio (the file dont exist).
                        //delete temp
                        delete temp;
                        //return false
                        return false;
                    }
                }
            }
        }
    }
    //else return false
    return false;
}
bool edk::AudioList::loadAudioFromPack(edk::pack::FilePackage* pack,const char* name, edk::AudioBuffer** retainAudio){
    return this->loadAudioFromPack(pack,(edk::char8*) name, retainAudio);
}
bool edk::AudioList::loadAudioFromPack(edk::pack::FilePackage* pack,edk::char8* name, edk::AudioBuffer** retainAudio){
    //test the name and the retainAudio
    if(name && pack){
        if(retainAudio){
            //find the audio
            edk::AudioBuffer find;
            find.setName(name);
            edk::AudioBuffer* temp = (edk::AudioBuffer*)audioTree.getElement((edk::ObjectWithName*)&find);

            if(temp){
                //retain the audio and return true
                if(audioTree.addElement(temp,(edk::ObjectWithName**)retainAudio)){
                    //audio added. Return true
                    return true;
                }
            }
            else{
                //else create a new audio buffer
                edk::AudioBuffer* temp = new edk::AudioBuffer();
                if(temp){
                    if(temp->loadBufferFromPack(pack,name)){
                        if(audioTree.addElement(temp,(edk::ObjectWithName**)retainAudio)){
                            //audio added. Return true
                            return true;
                        }
                        else{
                            //cant added the audio. delete temp and return false
                            temp->deleteBuffer();
                            delete temp;
                            return false;
                        }
                    }
                    else{
                        //can open the audio (the file dont exist).
                        //delete temp
                        delete temp;
                        //return false
                        return false;
                    }
                }
            }
        }
    }
    //else return false
    return false;
}
//remove audio. Release the audio file
bool edk::AudioList::removeAudio(edk::AudioBuffer** retainAudio){
    //test if the buffer are alloc
    if(retainAudio){
        edk::AudioBuffer* temp = *retainAudio;
        if(temp){
            //test if have one retain
            if(temp->haveOneRetain()){
                //delete the buffer
                temp->deleteBuffer();
            }
            //remove the element
            if(audioTree.releaseElement(temp,(edk::ObjectWithName**)retainAudio)){
                return true;
            }
        }
    }
    //else return false
    return false;
}
//delete the audioBuffer
void edk::AudioList::deleteAudio(edk::AudioBuffer* retainAudio){
    //
    if(retainAudio){
        //delete the element
        audioTree.deleteElement(retainAudio);
    }
}
