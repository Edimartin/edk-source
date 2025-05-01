#include "Texture2DList.h"

/*
Library Texture2DList - Manages 2D textures by their names and ID's
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
#pragma message "            Inside Texture2DList.cpp"
#endif

//tentatives to load the texture
#define EDK_TEXTURE_LOADER_TENTATIVES 2u

//textureTree ordened by the name of the textures
bool edk::Texture2DList::templateConstructNeed=true;
edk::Texture2DList::TextureCodeTree edk::Texture2DList::codeTree;
edk::Texture2DList::NameFilterTree edk::Texture2DList::nameTree;
edk::multi::BufferThreadTree edk::Texture2DList::bufferTree;

edk::Texture2DList::Texture2DList(){
    this->classThis=NULL;
    this->Constructor();
}

edk::Texture2DList::~Texture2DList(){
    this->Destructor();
}

void edk::Texture2DList::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        this->mutTexture.Constructor();
        this->mutNameTree.Constructor();
        edk::Texture2DList::bufferTree.Constructor();
        edk::Texture2DList::codeTree.Constructor();
        edk::Texture2DList::nameTree.Constructor();

        if(edk::Texture2DList::templateConstructNeed){
            edk::Texture2DList::codeTree.Constructor();
            edk::Texture2DList::nameTree.Constructor();
            edk::Texture2DList::bufferTree.Constructor();
            edk::Texture2DList::templateConstructNeed=false;
        }
    }
}
void edk::Texture2DList::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
}

//get the texture by the name
edk::Texture2DList::TextureCode* edk::Texture2DList::getTextureByName(edk::char8* name, edk::uint32 filter){
    //find the texture in the nameTree
    edk::Texture2DList::TextureCode find;
    find.setName(name);
    find.filter = filter;

    this->mutNameTree.lock();
    edk::Texture2DList::TextureCode* ret = (edk::Texture2DList::TextureCode*)edk::Texture2DList::nameTree.getElement(&find);
    this->mutNameTree.unlock();
    return ret;
}
//get the texture by the code
edk::Texture2DList::TextureCode* edk::Texture2DList::getTextureByCode(edk::uint32 code){
    //find the texture in the nameTree
    edk::Texture2DList::TextureCode find;
    find.code = code;

    this->mutNameTree.lock();
    edk::Texture2DList::TextureCode* ret = edk::Texture2DList::codeTree.getElement(&find);
    this->mutNameTree.unlock();
    return ret;
}
//create a new texture
edk::uint32 edk::Texture2DList::createTexture(edk::char8* name,edk::size2ui32 size,edk::uint32 mode,edk::uint32 filter){
    edk::uint32 ret=0u;
    //test the pointers and size
    if(name && size.height && size.width){
        edk::Texture2DList::TextureCode* temp;
        for(edk::uint8 i=0u;i<EDK_TEXTURE_LOADER_TENTATIVES;i++){
            //get the texture from the tree
            temp = this->getTextureByName(name,filter);
            //test if NOT hame the texture
            if(!temp){
                //load the new texture
                temp = new edk::Texture2DList::TextureCode;
                if(temp){
                    //load the texture
                    if(temp->createTexture(name,size,mode,filter)){
                        //add the texture to the tree's

                        this->mutNameTree.lock();
                        if(edk::Texture2DList::codeTree.add(temp)){
                            if(edk::Texture2DList::nameTree.add(temp)){
                                this->mutNameTree.unlock();
                                ret = temp->code;
                                temp->retainTexture();
                                break;
                            }
                            else{
                                edk::Texture2DList::codeTree.remove(temp);
                                this->mutNameTree.unlock();
                                //else delete temp
                                delete temp;
                                temp=NULL;
                            }
                        }
                        else{
                            this->mutNameTree.unlock();
                            //else delete temp
                            delete temp;
                            temp=NULL;
                        }
                    }
                    else{
                        //else delete temp
                        delete temp;
                        temp=NULL;
                    }
                }
                if(temp){
                    //else delete temp
                    delete temp;
                    temp=NULL;
                }
            }
            if(temp){
                //retain the texture
                ret=temp->code;
                temp->retainTexture();
                break;
            }
        }
    }
    return ret;
}
edk::uint32 edk::Texture2DList::createTexture(const char8* name,edk::size2ui32 size,edk::uint32 mode,edk::uint32 filter){
    return this->createTexture((edk::char8*) name,size,mode,filter);
}
edk::uint32 edk::Texture2DList::createTextureWithPBODraw(edk::char8* name,edk::size2ui32 size,edk::uint32 mode,edk::uint32 filter){
    edk::uint32 ret=0u;
    //test the pointers and size
    if(name && size.height && size.width){
        edk::Texture2DList::TextureCode* temp;
        for(edk::uint8 i=0u;i<EDK_TEXTURE_LOADER_TENTATIVES;i++){
            //get the texture from the tree
            temp = this->getTextureByName(name,filter);
            //test if NOT hame the texture
            if(!temp){
                //load the new texture
                temp = new edk::Texture2DList::TextureCode;
                if(temp){
                    //load the texture
                    if(temp->createTextureWithPBODraw(name,size,mode,filter)){
                        //add the texture to the tree's

                        this->mutNameTree.lock();
                        if(edk::Texture2DList::codeTree.add(temp)){
                            if(edk::Texture2DList::nameTree.add(temp)){
                                this->mutNameTree.unlock();
                                ret = temp->code;
                                temp->retainTexture();
                                break;
                            }
                            else{
                                edk::Texture2DList::codeTree.remove(temp);
                                this->mutNameTree.unlock();
                                //else delete temp
                                delete temp;
                                temp=NULL;
                            }
                        }
                        else{
                            this->mutNameTree.unlock();
                            //else delete temp
                            delete temp;
                            temp=NULL;
                        }
                    }
                    else{
                        //else delete temp
                        delete temp;
                        temp=NULL;
                    }
                }
                if(temp){
                    //else delete temp
                    delete temp;
                    temp=NULL;
                }
            }
            if(temp){
                //retain the texture
                ret=temp->code;
                temp->retainTexture();
                break;
            }
        }
    }
    return ret;
}
edk::uint32 edk::Texture2DList::createTextureWithPBODraw(const char8* name,edk::size2ui32 size,edk::uint32 mode,edk::uint32 filter){
    return this->createTextureWithPBODraw((edk::char8*) name,size,mode,filter);
}
edk::uint32 edk::Texture2DList::createAndDrawTexture(edk::char8* name,edk::size2ui32 size,edk::uint8* image,edk::uint32 mode,edk::uint32 filter){
    edk::uint32 ret=0u;
    //test the pointers and size
    if(name && size.height && size.width && image){
        edk::Texture2DList::TextureCode* temp;
        for(edk::uint8 i=0u;i<EDK_TEXTURE_LOADER_TENTATIVES;i++){
            //get the texture from the tree
            temp = this->getTextureByName(name,filter);
            //test if NOT hame the texture
            if(!temp){
                //load the new texture
                temp = new edk::Texture2DList::TextureCode;
                if(temp){
                    //load the texture
                    if(temp->createAndDrawTexture(name,size,image,mode,filter)){
                        //add the texture to the tree's

                        this->mutNameTree.lock();
                        if(edk::Texture2DList::codeTree.add(temp)){
                            if(edk::Texture2DList::nameTree.add(temp)){
                                this->mutNameTree.unlock();
                                ret = temp->code;
                                temp->retainTexture();
                                break;
                            }
                            else{
                                edk::Texture2DList::codeTree.remove(temp);
                                this->mutNameTree.unlock();
                                //else delete temp
                                delete temp;
                                temp=NULL;
                            }
                        }
                        else{
                            this->mutNameTree.unlock();
                            //else delete temp
                            delete temp;
                            temp=NULL;
                        }
                    }
                    else{
                        //else delete temp
                        delete temp;
                        temp=NULL;
                    }
                }
                if(temp){
                    //else delete temp
                    delete temp;
                    temp=NULL;
                }
            }
            if(temp){
                //retain the texture
                ret=temp->code;
                temp->retainTexture();
                break;
            }
        }
    }
    return ret;
}
edk::uint32 edk::Texture2DList::createAndDrawTexture(const char8* name,edk::size2ui32 size,edk::uint8* image,edk::uint32 mode,edk::uint32 filter){
    return this->createAndDrawTexture((edk::char8*) name,size,image,mode,filter);
}
edk::uint32 edk::Texture2DList::createAndDrawTextureWithPBODraw(edk::char8* name,edk::size2ui32 size,edk::uint8* image,edk::uint32 mode,edk::uint32 filter){
    edk::uint32 ret=0u;
    //test the pointers and size
    if(name && size.height && size.width && image){
        edk::Texture2DList::TextureCode* temp;
        for(edk::uint8 i=0u;i<EDK_TEXTURE_LOADER_TENTATIVES;i++){
            //get the texture from the tree
            temp = this->getTextureByName(name,filter);
            //test if NOT hame the texture
            if(!temp){
                //load the new texture
                temp = new edk::Texture2DList::TextureCode;
                if(temp){
                    //load the texture
                    if(temp->createAndDrawTextureWithPBODraw(name,size,image,mode,filter)){
                        //add the texture to the tree's

                        this->mutNameTree.lock();
                        if(edk::Texture2DList::codeTree.add(temp)){
                            if(edk::Texture2DList::nameTree.add(temp)){
                                this->mutNameTree.unlock();
                                ret = temp->code;
                                temp->retainTexture();
                                break;
                            }
                            else{
                                edk::Texture2DList::codeTree.remove(temp);
                                this->mutNameTree.unlock();
                                //else delete temp
                                delete temp;
                                temp=NULL;
                            }
                        }
                        else{
                            this->mutNameTree.unlock();
                            //else delete temp
                            delete temp;
                            temp=NULL;
                        }
                    }
                    else{
                        //else delete temp
                        delete temp;
                        temp=NULL;
                    }
                }
                if(temp){
                    //else delete temp
                    delete temp;
                    temp=NULL;
                }
            }
            if(temp){
                //retain the texture
                ret=temp->code;
                temp->retainTexture();
                break;
            }
        }
    }
    return ret;
}
edk::uint32 edk::Texture2DList::createAndDrawTextureWithPBODraw(const char8* name,edk::size2ui32 size,edk::uint8* image,edk::uint32 mode,edk::uint32 filter){
    return this->createAndDrawTextureWithPBODraw((edk::char8*) name,size,image,mode,filter);
}
//draw on a texture
bool edk::Texture2DList::drawTexture(edk::char8* name,edk::uint8* image,edk::uint32 filter){
    //test the name and retainTexture
    if(name){
        //get the texture from the tree
        return this->drawTexture(this->getTextureByName(name,filter),image);
    }
    return false;
}
bool edk::Texture2DList::drawTexture(const char8* name,edk::uint8* image,edk::uint32 filter){
    return this->drawTexture((const char8*) name, image,filter);
}
bool edk::Texture2DList::drawTexture(edk::uint32 code,edk::uint8* image,edk::uint32 filter){
    //test the name and retainTexture
    if(code){
        //get the texture from the tree
        return this->drawTexture(this->getTextureByCode(code),image,filter);
    }
    return false;
}
//read from a texture
bool edk::Texture2DList::readTexture(edk::char8* name,edk::uint32 format,edk::uint8* image,edk::uint32 filter){
    //test the name and retainTexture
    if(name){
        //get the texture from the tree
        return this->readTexture(this->getTextureByName(name,filter),image,format);
    }
    return false;
}
bool edk::Texture2DList::readTexture(const char8* name,edk::uint32 format,edk::uint8* image,edk::uint32 filter){
    return this->readTexture((const char8*) name, format,image,filter);
}
bool edk::Texture2DList::readTexture(edk::uint32 code,edk::uint32 format,edk::uint8* image){
    //test the name and retainTexture
    if(code){
        //get the texture from the tree
        return this->readTexture(this->getTextureByCode(code),image,format);
    }
    return false;
}

//Load Texture
edk::uint32 edk::Texture2DList::loadTexture(edk::char8* name,edk::uint32 filter){
    //test the fileName and the retain texture
    edk::uint32 ret=0u;
    if(name){
        edk::Texture2DList::TextureCode* temp;
        for(edk::uint8 i=0u;i<EDK_TEXTURE_LOADER_TENTATIVES;i++){
            //get the texture from the tree
            temp = this->getTextureByName(name,filter);
            //test if NOT hame the texture
            if(!temp){
                //load the new texture
                temp = new edk::Texture2DList::TextureCode;
                if(temp){
                    //load the texture
                    if(temp->loadFromFile(name,filter)){
                        //add the texture to the tree's
                        this->mutNameTree.lock();
                        if(edk::Texture2DList::codeTree.add(temp)){
                            if(edk::Texture2DList::nameTree.add(temp)){
                                this->mutNameTree.unlock();
                                ret = temp->code;
                                temp->retainTexture();
                                break;
                            }
                            else{
                                edk::Texture2DList::codeTree.remove(temp);
                                this->mutNameTree.unlock();
                                //else delete temp
                                delete temp;
                                temp=NULL;
                            }
                        }
                        else{
                            this->mutNameTree.unlock();
                            //else delete temp
                            delete temp;
                            temp=NULL;
                        }
                    }
                    else{
                        //else delete temp
                        delete temp;
                        temp=NULL;
                    }
                }
                if(temp){
                    //else delete temp
                    delete temp;
                    temp=NULL;
                }
            }
            if(temp){
                //retain the texture
                ret=temp->code;
                temp->retainTexture();
                break;
            }
        }
    }
    //else return false
    return ret;
}
edk::uint32 edk::Texture2DList::loadTexture(const edk::char8* name,edk::uint32 filter){
    //
    return this->loadTexture((edk::char8*) name,filter);
}
//load Texture from memory
edk::uint32 edk::Texture2DList::loadTextureFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter){
    edk::uint32 ret=0u;
    //test the pointers and size
    if(name && image && size){
        edk::Texture2DList::TextureCode* temp;
        for(edk::uint8 i=0u;i<EDK_TEXTURE_LOADER_TENTATIVES;i++){
            //get the texture from the tree
            temp = this->getTextureByName(name,filter);
            //test if NOT hame the texture
            if(!temp){
                //load the new texture
                temp = new edk::Texture2DList::TextureCode;
                if(temp){
                    //load the texture
                    if(temp->loadFromMemory(name,image,size,filter)){
                        //add the texture to the tree's
                        this->mutNameTree.lock();
                        if(edk::Texture2DList::codeTree.add(temp)){
                            if(edk::Texture2DList::nameTree.add(temp)){
                                this->mutNameTree.unlock();
                                ret = temp->code;
                                temp->retainTexture();
                                break;
                            }
                            else{
                                edk::Texture2DList::codeTree.remove(temp);
                                this->mutNameTree.unlock();
                                //else delete temp
                                delete temp;
                                temp=NULL;
                            }
                        }
                        else{
                            this->mutNameTree.unlock();
                            //else delete temp
                            delete temp;
                            temp=NULL;
                        }
                    }
                    else{
                        //else delete temp
                        delete temp;
                        temp=NULL;
                    }
                }
                if(temp){
                    //else delete temp
                    delete temp;
                    temp=NULL;
                }
            }
            if(temp){
                //retain the texture
                ret=temp->code;
                temp->retainTexture();
                break;
            }
        }
    }
    return ret;
}
edk::uint32 edk::Texture2DList::loadTextureFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter){
    return this->loadTextureFromMemory((edk::char8*) name,image,size,filter);
}
//set Texture from memory
edk::uint32 edk::Texture2DList::setTextureFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 filter){
    edk::uint32 ret=0u;
    //test the pointers and size
    if(name && image && width && height && channels){
        edk::Texture2DList::TextureCode* temp;
        for(edk::uint8 i=0u;i<EDK_TEXTURE_LOADER_TENTATIVES;i++){
            //get the texture from the tree
            temp = this->getTextureByName(name,filter);
            //test if NOT hame the texture
            if(!temp){
                //load the new texture
                temp = new edk::Texture2DList::TextureCode;
                if(temp){
                    //load the texture
                    if(temp->setFromMemory(name,image,width,height,channels,filter)){
                        //add the texture to the tree's

                        this->mutNameTree.lock();
                        if(edk::Texture2DList::codeTree.add(temp)){
                            if(edk::Texture2DList::nameTree.add(temp)){
                                this->mutNameTree.unlock();
                                ret = temp->code;
                                temp->retainTexture();
                                break;
                            }
                            else{
                                edk::Texture2DList::codeTree.remove(temp);
                                this->mutNameTree.unlock();
                                //else delete temp
                                delete temp;
                                temp=NULL;
                            }
                        }
                        else{
                            this->mutNameTree.unlock();
                            //else delete temp
                            delete temp;
                            temp=NULL;
                        }
                    }
                    else{
                        //else delete temp
                        delete temp;
                        temp=NULL;
                    }
                }
                if(temp){
                    //else delete temp
                    delete temp;
                    temp=NULL;
                }
            }
            if(temp){
                //retain the texture
                ret=temp->code;
                temp->retainTexture();
                break;
            }
        }
    }
    return ret;
}
edk::uint32 edk::Texture2DList::setTextureFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 filter){
    return this->setTextureFromMemory((edk::char8*) name,image,width,height,channels,filter);
}
//load the texture from a file package
edk::uint32 edk::Texture2DList::loadTextureFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter){
    //test the fileName and the retain texture
    edk::uint32 ret=0u;
    if(name && pack){
        //get the texture from the tree
        edk::Texture2DList::TextureCode* temp = NULL;
        for(edk::uint8 i=0u;i<EDK_TEXTURE_LOADER_TENTATIVES;i++){

            if(edk::multi::Thread::isThisThreadMain()){
                while(true){
                    //test if can tryLock
                    if(pack->mutex.tryLock()){
                        //it lock
                        break;
                    }
                    else{
                        //else load textures from other threads
                        edk::GU::guUpdateLoadTextures();
                        edk::GU_GLSL::guUpdateCreateShaders();
                    }
                }
                while(true){
                    //test if can tryLock
                    if(this->mutTexture.tryLock()){
                        //it lock
                        break;
                    }
                    else{
                        //else load textures from other threads
                        edk::GU::guUpdateLoadTextures();
                        edk::GU_GLSL::guUpdateCreateShaders();
                    }
                }
            }

            temp = this->getTextureByName(name,filter);
            //test if NOT hame the texture
            if(!temp){
                //load the new texture
                temp = new edk::Texture2DList::TextureCode;
                if(temp){
                    //only lock if it's not the mainTread because it aready lock before
                    if(!edk::multi::Thread::isThisThreadMain()){
                        pack->mutex.lock();
                    }
                    //read the file
                    if(pack->readFileToBuffer(name)){
                        //only lock if it's not the mainTread because it aready lock before
                        if(!edk::multi::Thread::isThisThreadMain()){
                            this->mutTexture.lock();
                        }
                        //copy the file into the buffer
                        if(edk::Texture2DList::bufferTree.writeToBuffer(pack->getBuffer(),pack->getBufferSize())){
                            //load the texture
                            if(temp->loadFromMemory(name,(edk::uint8*)edk::Texture2DList::bufferTree.getPointer(),edk::Texture2DList::bufferTree.getSize(),filter)){
                                pack->mutex.unlock();
                                this->mutTexture.unlock();
                                //add the texture to the tree's
                                this->mutNameTree.lock();
                                if(edk::Texture2DList::codeTree.add(temp)){
                                    if(edk::Texture2DList::nameTree.add(temp)){
                                        this->mutNameTree.unlock();
                                        ret = temp->code;
                                        temp->retainTexture();
                                        break;
                                    }
                                    else{
                                        edk::Texture2DList::codeTree.remove(temp);
                                        this->mutNameTree.unlock();
                                        //else delete temp
                                        delete temp;
                                        temp=NULL;
                                    }
                                }
                                else{
                                    this->mutNameTree.unlock();
                                    //else delete temp
                                    delete temp;
                                    temp=NULL;
                                }
                            }
                            else{
                                pack->mutex.unlock();
                                this->mutTexture.unlock();
                                //else delete temp
                                delete temp;
                                temp=NULL;
                            }
                        }
                        else{
                            this->mutTexture.unlock();
                            pack->mutex.unlock();
                        }
                    }
                    else{
                        pack->mutex.unlock();
                        delete temp;
                        temp=NULL;
                    }
                }
            }
            if(temp){
                if(edk::multi::Thread::isThisThreadMain()){
                    //The main thread need unlock the mutexes
                    pack->mutex.unlock();
                    this->mutTexture.unlock();

                }
                //retain the texture
                ret=temp->code;
                temp->retainTexture();
                break;
            }
            else{
                if(edk::multi::Thread::isThisThreadMain()){
                    this->mutTexture.unlock();
                }
            }
        }
    }
    //else return false
    return ret;
}
edk::uint32 edk::Texture2DList::loadTextureFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter){
    return this->loadTextureFromPack(pack,(edk::char8*) name,filter);
}
//retain the texture
bool edk::Texture2DList::retainTexture(edk::uint32 code){
    //get the texture
    edk::Texture2DList::TextureCode* temp = this->getTextureByCode(code);
    if(temp){
        //set retain
        temp->retainTexture();
        return true;
    }
    return false;
}
//draw on the texture
bool edk::Texture2DList::drawTexture(edk::Texture2DList::TextureCode* temp,edk::uint8* image,edk::uint32 filter){
    if(temp){
        return temp->drawTexture(image,filter);
    }
    return false;
}
//read from the texture
bool edk::Texture2DList::readTexture(edk::Texture2DList::TextureCode* temp,edk::uint8* image,edk::uint32 format){
    if(temp){
        return temp->readTexture(image,format);
    }
    return false;
}
//remove the texture
bool edk::Texture2DList::removeTexture(edk::Texture2DList::TextureCode* temp){
    if(temp){
        //test if have one retain
        if(temp->haveOneRetain()){
            temp->releaseTexture();
            this->mutNameTree.lock();
            //remove
            edk::Texture2DList::codeTree.remove(temp);
            //remove
            edk::Texture2DList::nameTree.remove(temp);
            this->mutNameTree.unlock();

            temp->deleteTexture();
            //delete texture
            delete temp;
        }
        else{
            //else just release
            temp->releaseTexture();
        }
        return true;
    }
    return false;
}
//remove texture
bool edk::Texture2DList::removeTexture(edk::char8* name,edk::uint32 filter){
    //test the name and retainTexture
    if(name){
        //get the texture from the tree
        return this->removeTexture(this->getTextureByName(name,filter));
    }
    //else return false
    return false;
}
bool edk::Texture2DList::removeTexture(const edk::char8* name,edk::uint32 filter){
    //
    return this->removeTexture((edk::char8*) name,filter);
}
bool edk::Texture2DList::removeTexture(edk::uint32 code){
    if(code){
        //get the texture from the tree
        return this->removeTexture(this->getTextureByCode(code));
    }
    //else return false
    return false;
}
//delete the texture
bool edk::Texture2DList::deleteTexture(edk::Texture2DList::TextureCode* temp){
    if(temp){
        this->mutNameTree.lock();
        //remove
        edk::Texture2DList::codeTree.remove(temp);
        //remove
        edk::Texture2DList::nameTree.remove(temp);
        this->mutNameTree.unlock();
        //delete texture
        delete temp;

        return true;
    }
    return false;
}
//delete texture
bool edk::Texture2DList::deleteTexture(edk::char8* name,edk::uint32 filter){
    //test the name
    if(name){
        //delete the texture
        return this->deleteTexture(this->getTextureByName(name,filter));
    }
    //else return false
    return false;
}
bool edk::Texture2DList::deleteTexture(const edk::char8* name,edk::uint32 filter){
    return this->deleteTexture((edk::char8*) name,filter);
}
bool edk::Texture2DList::deleteTexture(edk::uint32 code){
    //test the name
    if(code){
        //delete the texture
        return this->deleteTexture(this->getTextureByCode(code));
    }
    //else return false
    return false;
}
//delete all textures
void edk::Texture2DList::deleteAllTextures(){
    this->mutNameTree.lock();
    while(edk::Texture2DList::codeTree.size()){
        this->mutNameTree.unlock();
        //delete the first element
        this->deleteTexture(edk::Texture2DList::codeTree.getElementInPosition(0u));
        this->mutNameTree.lock();
    }
    this->mutNameTree.unlock();
}
//return the size of the texture
edk::size2ui32 edk::Texture2DList::getTextureSize(edk::char8* name,edk::uint32 filter){
    edk::size2ui32 ret(0u,0u);
    //load the texture
    edk::Texture2DList::TextureCode* temp = this->getTextureByName(name,filter);
    if(temp){
        ret = temp->file->getSize();
    }
    return ret;
}
edk::size2ui32 edk::Texture2DList::getTextureSize(const edk::char8* name,edk::uint32 filter){
    return this->getTextureSize((edk::char8*) name,filter);
}
edk::size2ui32 edk::Texture2DList::getTextureSize(edk::uint32 code){
    edk::size2ui32 ret(0u,0u);
    //load the texture
    edk::Texture2DList::TextureCode* temp = this->getTextureByCode(code);
    if(temp){
        ret = temp->file->getSize();
    }
    return ret;
}
edk::uint32 edk::Texture2DList::getTextureWidth(edk::char8* name,edk::uint32 filter){
    return this->getTextureSize(name,filter).width;
}
edk::uint32 edk::Texture2DList::getTextureWidth(const edk::char8* name,edk::uint32 filter){
    return this->getTextureSize(name,filter).width;
}
edk::uint32 edk::Texture2DList::getTextureWidth(edk::uint32 code){
    return this->getTextureSize(code).width;
}
edk::uint32 edk::Texture2DList::getTextureHeight(edk::char8* name,edk::uint32 filter){
    return this->getTextureSize(name,filter).height;
}
edk::uint32 edk::Texture2DList::getTextureHeight(const edk::char8* name,edk::uint32 filter){
    return this->getTextureSize(name,filter).height;
}
edk::uint32 edk::Texture2DList::getTextureHeight(edk::uint32 code){
    return this->getTextureSize(code).height;
}
//return the textureName
edk::char8* edk::Texture2DList::getTextureName(edk::uint32 code){
    edk::Texture2DList::TextureCode* temp = this->getTextureByCode(code);
    if(temp){
        return temp->getName();
    }
    return NULL;
}
edk::uint32 edk::Texture2DList::getTextureFilter(edk::uint32 code){
    edk::Texture2DList::TextureCode* temp = this->getTextureByCode(code);
    if(temp){
        return temp->filter;
    }
    return 0u;
}

//Test if have the texture
bool edk::Texture2DList::haveTexture(edk::char8* name,edk::uint32 filter){
    if(this->getTextureByName(name,filter)){
        return true;
    }
    return false;
}
bool edk::Texture2DList::haveTexture(const edk::char8* name,edk::uint32 filter){
    return this->haveTexture((edk::char8*) name,filter);
}
bool edk::Texture2DList::haveTexture(uint32 code){
    if(this->getTextureByCode(code)){
        return true;
    }
    return false;
}

