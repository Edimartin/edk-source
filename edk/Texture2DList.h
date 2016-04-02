#ifndef EDK_TEXTURE2DLIST_H
#define EDK_TEXTURE2DLIST_H

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
#warning "Inside Texture2DList"
#endif

//Includes
#pragma once
#include "Texture2DFile.h"
#include "NameClass.h"

#ifdef printMessages
#warning "    Compiling Texture2DList"
#endif

/*

List of textures loaded

*/


namespace edk{

class Texture2DList{
public:
    Texture2DList();
    ~Texture2DList();

    //create a new texture
    edk::uint32 createTexture(edk::char8* name,edk::size2ui32 size,edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    edk::uint32 createTexture(const char8* name,edk::size2ui32 size,edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    //draw on a texture
    bool drawTexture(edk::char8* name,edk::uint8* image,edk::uint32 filter = GU_NEAREST);
    bool drawTexture(const char8* name,edk::uint8* image,edk::uint32 filter = GU_NEAREST);
    bool drawTexture(edk::uint32 code,edk::uint8* image,edk::uint32 filter = GU_NEAREST);
    //Load Texture
    edk::uint32 loadTexture(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    edk::uint32 loadTexture(const char* name,edk::uint32 filter = GU_NEAREST);
    //load Texture from memory
    edk::uint32 loadTextureFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    edk::uint32 loadTextureFromMemory(const char* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    //retain the texture
    bool retainTexture(edk::uint32 code);
    //remove texture
    bool removeTexture(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool removeTexture(const char* name,edk::uint32 filter = GU_NEAREST);
    bool removeTexture(edk::uint32 code);
    //delete texture
    bool deleteTexture(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool deleteTexture(const char* name,edk::uint32 filter = GU_NEAREST);
    bool deleteTexture(edk::uint32 code);
    //delete all textures
    void deleteAllTextures();
    //return the size of the texture
    edk::size2ui32 getTextureSize(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    edk::size2ui32 getTextureSize(const char* name,edk::uint32 filter = GU_NEAREST);
    edk::size2ui32 getTextureSize(edk::uint32 code);
    edk::uint32 getTextureWidth(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    edk::uint32 getTextureWidth(const char* name,edk::uint32 filter = GU_NEAREST);
    edk::uint32 getTextureWidth(edk::uint32 code);
    edk::uint32 getTextureHeight(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    edk::uint32 getTextureHeight(const char* name,edk::uint32 filter = GU_NEAREST);
    edk::uint32 getTextureHeight(edk::uint32 code);
    //return the textureName
    edk::char8* getTextureName(edk::uint32 code);
    edk::uint32 getTextureFilter(edk::uint32 code);
    //Test if have the texture
    bool haveTexture(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool haveTexture(const char* name,edk::uint32 filter = GU_NEAREST);
    bool haveTexture(edk::uint32 code);
protected:
private:
    //Class to save the texture by the name and code
    class TextureCode: public edk::Name {
    public:
        TextureCode(){
            this->code=0u;
            this->file=NULL;
            this->count=0u;
            this->filter = 0u;
        }
        ~TextureCode(){
            this->deleteTexture();
        }
        void deleteTexture(){
            if(this->file) delete this->file;
            this->file=NULL;
            this->code=0u;
            this->filter = 0u;
            this->deleteName();
        }
        //create a new testure
        bool createTexture(edk::char8* name,edk::size2ui32 size,edk::uint32 mode,edk::uint32 filter){
            this->deleteTexture();
            if(name){
                if((this->file = new edk::Texture2DFile)){
                    if(this->file->createTexture(size.width,size.height,mode,NULL,filter)){
                        //save the name
                        if(this->setName(name)){
                            //save the code
                            this->code=this->file->getID();
                            this->filter = filter;
                            return true;
                        }
                    }
                }
            }
            this->deleteTexture();
            return false;
        }
        //draw in the texture
        bool drawTexture(edk::uint8* image,edk::uint32 filter){
            if(image){
                //draw on the texture
                return this->file->drawToTexture(image,filter);
            }
            return false;
        }
        //load texture
        bool loadFromFile(edk::char8* name,edk::uint32 filter){
            this->deleteTexture();
            if((this->file = new edk::Texture2DFile)){
                if(this->file->loadFromFile(name,filter)){
                    //save the name
                    if(this->setName(name)){
                        //save the code
                        this->code=this->file->getID();
                        this->filter = filter;
                        return true;
                    }
                }
            }
            this->deleteTexture();
            return false;
        }
        bool loadFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter){
            this->deleteTexture();
            if(name){
                if((this->file = new edk::Texture2DFile)){
                    if(this->file->loadFromMemory(image,size,filter)){
                        //save the name
                        if(this->setName(name)){
                            //save the code
                            this->code=this->file->getID();
                            this->filter = filter;
                            return true;
                        }
                    }
                }
            }
            this->deleteTexture();
            return false;
        }
        //retain release
        void retainTexture(){
            this->count++;
        }
        bool releaseTexture(){
            if(this->count){
                this->count--;
                return true;
            }
            return false;
        }
        bool haveOneRetain(){
            if(this->count<=1){
                return true;
            }return false;
        }

        //code of the texture
        edk::uint32 filter;
        edk::uint32 code;
        edk::Texture2DFile* file;
    private:
        //textures using count
        edk::uint32 count;
    };
    //Tree to save the textures by the code
    class TextureCodeTree:public edk::vector::BinaryTree<edk::Texture2DList::TextureCode*>{
    public:
        //virtual functions
        virtual bool firstBiggerSecond(edk::Texture2DList::TextureCode* first,edk::Texture2DList::TextureCode* second){
            //load the textures
            if(first && second){
                if(first->code>second->code){
                    //
                    return true;
                }
            }
            return false;
        }
        virtual bool firstEqualSecond(edk::Texture2DList::TextureCode* first,edk::Texture2DList::TextureCode* second){
            if(first && second){
                if(first->code==second->code){
                    //
                    return true;
                }
            }
            return false;
        }
    };
    //nameFilterTree
    class NameFilterTree: public edk::vector::BinaryTree<edk::Texture2DList::TextureCode*>{
    public:
        //virtual functions
        virtual bool firstBiggerSecond(edk::Texture2DList::TextureCode* first,edk::Texture2DList::TextureCode* second){
            //load the textures
            if(first && second){
                if(first->getName()&&second->getName()){
                    if(first->filter>second->filter){
                        return true;
                    }
                    else if(first->filter==second->filter){
                        if(edk::Name::firstNameBiggerSecond(first->getName(),second->getName())){
                            if(first->filter>second->filter){
                                //
                                return true;
                            }
                        }
                    }
                }
            }
            return false;
        }
        virtual bool firstEqualSecond(edk::Texture2DList::TextureCode* first,edk::Texture2DList::TextureCode* second){
            if(first && second){
                if(first->filter==second->filter){
                    if(edk::Name::stringEqual(first->getName(),second->getName())){
                        //
                        return true;
                    }
                }
            }
            return false;
        }
    };
    //Tree to save the textures by code
    static edk::Texture2DList::TextureCodeTree codeTree;
    //Tree to save the textures by name
    static edk::Texture2DList::NameFilterTree nameTree;

    //get the texture by the name
    edk::Texture2DList::TextureCode* getTextureByName(edk::char8* name, edk::uint32 filter);
    //get the texture by the code
    edk::Texture2DList::TextureCode* getTextureByCode(edk::uint32 code);
    //draw on the texture
    bool drawTexture(edk::Texture2DList::TextureCode* temp,edk::uint8* image,edk::uint32 filter = GU_NEAREST);
    //remove the texture
    bool removeTexture(edk::Texture2DList::TextureCode* temp);
    //delete the texture
    bool deleteTexture(edk::Texture2DList::TextureCode* temp);
};
}

#endif // Texture2DList_H
