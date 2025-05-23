#include "AudioList.h"

/*
Library AudioBuffer - List of Audios used in the gameEngine
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
#pragma message "            Inside AudioList.cpp"
#endif

//Tree with the audioNames
edk::ObjectNameTree audioTree;

edk::AudioList::AudioList(){
    this->classThis=NULL;
    this->Constructor();
}

edk::AudioList::~AudioList(){
}

void edk::AudioList::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::AudioList::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
}


//LOAD
bool edk::AudioList::loadAudio(const edk::char8* name, edk::AudioBuffer** retainAudio){
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
bool edk::AudioList::loadAudioFromMemory(const edk::char8* name,edk::classID vector,edk::uint32 size, edk::AudioBuffer** retainAudio){
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
bool edk::AudioList::loadAudioFromPack(edk::pack::FilePackage* pack,const edk::char8* name, edk::AudioBuffer** retainAudio){
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
