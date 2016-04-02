#include "Texture2DList.h"

/*
Library Texture2DList - Manages 2D textures by their names and ID's
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
#warning "            Inside Texture2DList.cpp"
#endif

//textureTree ordened by the name of the textures
edk::Texture2DList::TextureCodeTree edk::Texture2DList::codeTree;
edk::Texture2DList::NameFilterTree edk::Texture2DList::nameTree;

edk::Texture2DList::Texture2DList()
{
    //ctor
}

edk::Texture2DList::~Texture2DList()
{
    //dtor
}
//get the texture by the name
edk::Texture2DList::TextureCode* edk::Texture2DList::getTextureByName(edk::char8* name, edk::uint32 filter){
    //find the texture in the nameTree
    edk::Texture2DList::TextureCode find;
    find.setName(name);
    find.filter = filter;
    return (edk::Texture2DList::TextureCode*)edk::Texture2DList::nameTree.getElement(&find);
}
//get the texture by the code
edk::Texture2DList::TextureCode* edk::Texture2DList::getTextureByCode(edk::uint32 code){
    //find the texture in the nameTree
    edk::Texture2DList::TextureCode find;
    find.code = code;
    return edk::Texture2DList::codeTree.getElement(&find);
}
//create a new texture
edk::uint32 edk::Texture2DList::createTexture(edk::char8* name,edk::size2ui32 size,edk::uint32 mode,edk::uint32 filter){
    edk::uint32 ret=0u;
    //test the pointers and size
    if(name && size.height && size.width){
        //get the texture from the tree
        edk::Texture2DList::TextureCode* temp = this->getTextureByName(name,filter);
        //test if NOT hame the texture
        if(!temp){
            //load the new texture
            temp = new edk::Texture2DList::TextureCode;
            if(temp){
                //load the texture
                if(temp->createTexture(name,size,mode,filter)){
                    //add the texture to the tree's
                    if(edk::Texture2DList::codeTree.add(temp)){
                        if(edk::Texture2DList::nameTree.add(temp)){
                            ret = temp->code;
                            temp->retainTexture();
                            return ret;
                        }
                        else{
                            edk::Texture2DList::codeTree.remove(temp);
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
                else{
                    //else delete temp
                    delete temp;
                    temp=NULL;
                }
            }
        }
        if(temp){
            //retain the texture
            ret=temp->code;
            temp->retainTexture();
        }
    }
    return ret;
}
edk::uint32 edk::Texture2DList::createTexture(const char8* name,edk::size2ui32 size,edk::uint32 mode,edk::uint32 filter){
    return this->createTexture((edk::char8*) name,size,mode,filter);
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
        return this->drawTexture(this->getTextureByCode(code),image);
    }
    return false;
}

//Load Texture
edk::uint32 edk::Texture2DList::loadTexture(edk::char8* name,edk::uint32 filter){
    //test the fileName and the retain texture
    edk::uint32 ret=0u;
    if(name){
        //get the texture from the tree
        edk::Texture2DList::TextureCode* temp = this->getTextureByName(name,filter);
        //test if NOT hame the texture
        if(!temp){
            //load the new texture
            temp = new edk::Texture2DList::TextureCode;
            if(temp){
                //load the texture
                if(temp->loadFromFile(name,filter)){
                    //add the texture to the tree's
                    if(edk::Texture2DList::codeTree.add(temp)){
                        if(edk::Texture2DList::nameTree.add(temp)){
                            ret = temp->code;
                            temp->retainTexture();
                            return ret;
                        }
                        else{
                            edk::Texture2DList::codeTree.remove(temp);
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
                else{
                    //else delete temp
                    delete temp;
                    temp=NULL;
                }
            }
        }
        if(temp){
            //retain the texture
            ret=temp->code;
            temp->retainTexture();
        }
    }
    //else return false
    return ret;
}
edk::uint32 edk::Texture2DList::loadTexture(const char* name,edk::uint32 filter){
    //
    return this->loadTexture((edk::char8*) name,filter);
}
//load Texture from memory
edk::uint32 edk::Texture2DList::loadTextureFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter){
    edk::uint32 ret=0u;
    //test the pointers and size
    if(name && image && size){
        //get the texture from the tree
        edk::Texture2DList::TextureCode* temp = this->getTextureByName(name,filter);
        //test if NOT hame the texture
        if(!temp){
            //load the new texture
            temp = new edk::Texture2DList::TextureCode;
            if(temp){
                //load the texture
                if(temp->loadFromMemory(name,image,size,filter)){
                    //add the texture to the tree's
                    if(edk::Texture2DList::codeTree.add(temp)){
                        if(edk::Texture2DList::nameTree.add(temp)){
                            ret = temp->code;
                            temp->retainTexture();
                            return ret;
                        }
                        else{
                            edk::Texture2DList::codeTree.remove(temp);
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
                else{
                    //else delete temp
                    delete temp;
                    temp=NULL;
                }
            }
        }
        if(temp){
            //retain the texture
            ret=temp->code;
            temp->retainTexture();
        }
    }
    return ret;
}
edk::uint32 edk::Texture2DList::loadTextureFromMemory(const char* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter){
    return this->loadTextureFromMemory((edk::char8*) name,image,size,filter);
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
//remove the texture
bool edk::Texture2DList::removeTexture(edk::Texture2DList::TextureCode* temp){
    if(temp){
        //test if have one retain
        if(temp->haveOneRetain()){
            temp->releaseTexture();

            //remove
            edk::Texture2DList::codeTree.remove(temp);
            //remove
            edk::Texture2DList::nameTree.remove(temp);
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
bool edk::Texture2DList::removeTexture(const char* name,edk::uint32 filter){
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
        //remove
        edk::Texture2DList::codeTree.remove(temp);
        //remove
        edk::Texture2DList::nameTree.remove(temp);
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
bool edk::Texture2DList::deleteTexture(const char* name,edk::uint32 filter){
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
    while(edk::Texture2DList::codeTree.size()){
        //delete the first element
        this->deleteTexture(edk::Texture2DList::codeTree.getElementInPosition(0u));
    }
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
edk::size2ui32 edk::Texture2DList::getTextureSize(const char* name,edk::uint32 filter){
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
edk::uint32 edk::Texture2DList::getTextureWidth(const char* name,edk::uint32 filter){
    return this->getTextureSize(name,filter).width;
}
edk::uint32 edk::Texture2DList::getTextureWidth(edk::uint32 code){
    return this->getTextureSize(code).width;
}
edk::uint32 edk::Texture2DList::getTextureHeight(edk::char8* name,edk::uint32 filter){
    return this->getTextureSize(name,filter).height;
}
edk::uint32 edk::Texture2DList::getTextureHeight(const char* name,edk::uint32 filter){
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
    if((this->getTextureByName(name,filter))){
        return true;
    }
    return false;
}
bool edk::Texture2DList::haveTexture(const char* name,edk::uint32 filter){
    return this->haveTexture((edk::char8*) name,filter);
}
bool edk::Texture2DList::haveTexture(uint32 code){
    if((this->getTextureByCode(code))){
        return true;
    }
    return false;
}
