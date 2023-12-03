#ifndef EDK_TEXTURE2DLIST_H
#define EDK_TEXTURE2DLIST_H

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
#pragma message "Inside Texture2DList"
#endif

//Includes
#pragma once
#include "Texture2DFile.h"
#include "NameClass.h"
#include "pack/FilePackage.h"
#include "edk/thread/Thread.h"
#include "edk/thread/Mutex.h"
#include "edk/thread/BufferThreadTree.h"

#ifdef printMessages
#pragma message "    Compiling Texture2DList"
#endif

/*

List of textures loaded

*/


namespace edk{

class Texture2DList{
public:
    Texture2DList();
    ~Texture2DList();

    //filter
    //GU_NEAREST
    //GU_LINEAR
    //GU_NEAREST_MIPMAP_NEAREST
    //GU_NEAREST_MIPMAP_LINEAR
    //GU_LINEAR_MIPMAP_NEAREST
    //GU_LINEAR_MIPMAP_LINEAR
    //create a new texture
    edk::uint32 createTexture(edk::char8* name,edk::size2ui32 size,edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    edk::uint32 createTexture(const char8* name,edk::size2ui32 size,edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    //draw on a texture
    bool drawTexture(edk::char8* name,edk::uint8* image,edk::uint32 filter = GU_NEAREST);
    bool drawTexture(const char8* name,edk::uint8* image,edk::uint32 filter = GU_NEAREST);
    bool drawTexture(edk::uint32 code,edk::uint8* image,edk::uint32 filter = GU_NEAREST);
    //read from a texture

    //format
    //GU_STENCIL_INDEX
    //GU_DEPTH_COMPONENT
    //GU_DEPTH_STENCIL
    //GU_RED
    //GU_GREEN
    //GU_BLUE
    //GU_RG
    //GU_RGB
    //GU_RGBA
    //GU_BGR
    //GU_BGRA
    //filter
    //GU_NEAREST
    //GU_LINEAR
    //GU_NEAREST_MIPMAP_NEAREST
    //GU_NEAREST_MIPMAP_LINEAR
    //GU_LINEAR_MIPMAP_NEAREST
    //GU_LINEAR_MIPMAP_LINEAR
    bool readTexture(edk::char8* name,edk::uint32 format,edk::uint8* image,edk::uint32 filter = GU_NEAREST);
    bool readTexture(const char8* name,edk::uint32 format,edk::uint8* image,edk::uint32 filter = GU_NEAREST);
    bool readTexture(edk::uint32 code,edk::uint32 format,edk::uint8* image);
    //Load Texture
    edk::uint32 loadTexture(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    edk::uint32 loadTexture(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    //load Texture from memory
    edk::uint32 loadTextureFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    edk::uint32 loadTextureFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    //set Texture from memory
    edk::uint32 setTextureFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 filter = GU_NEAREST);
    edk::uint32 setTextureFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 filter = GU_NEAREST);
    //load the texture from a file package
    edk::uint32 loadTextureFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST);
    edk::uint32 loadTextureFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    //retain the texture
    bool retainTexture(edk::uint32 code);
    //remove texture
    bool removeTexture(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool removeTexture(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool removeTexture(edk::uint32 code);
    //delete texture
    bool deleteTexture(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool deleteTexture(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool deleteTexture(edk::uint32 code);
    //delete all textures
    void deleteAllTextures();
    //return the size of the texture
    //filter
    //GU_NEAREST
    //GU_LINEAR
    //GU_NEAREST_MIPMAP_NEAREST
    //GU_NEAREST_MIPMAP_LINEAR
    //GU_LINEAR_MIPMAP_NEAREST
    //GU_LINEAR_MIPMAP_LINEAR
    edk::size2ui32 getTextureSize(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    edk::size2ui32 getTextureSize(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    edk::size2ui32 getTextureSize(edk::uint32 code);
    edk::uint32 getTextureWidth(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    edk::uint32 getTextureWidth(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    edk::uint32 getTextureWidth(edk::uint32 code);
    edk::uint32 getTextureHeight(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    edk::uint32 getTextureHeight(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    edk::uint32 getTextureHeight(edk::uint32 code);
    //return the textureName
    edk::char8* getTextureName(edk::uint32 code);
    edk::uint32 getTextureFilter(edk::uint32 code);
    //Test if have the texture
    bool haveTexture(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool haveTexture(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool haveTexture(edk::uint32 code);
protected:
private:
    //mutex to load the texture
    edk::multi::Mutex mutTexture;
    edk::multi::Mutex mutNameTree;
    //buffer thread tree
    static edk::multi::BufferThreadTree bufferTree;
    //Class to save the texture by the name and code
    class TextureCode: public edk::Name {
    public:
        TextureCode(){
            this->code=0u;edkEnd();
            this->file=NULL;edkEnd();
            this->count=0u;edkEnd();
            this->filter = 0u;edkEnd();
        }
        ~TextureCode(){
            this->deleteTexture();edkEnd();
        }
        void deleteTexture(){
            if(this->file){
                delete this->file;edkEnd();
            }
            this->file=NULL;edkEnd();
            this->code=0u;edkEnd();
            this->filter = 0u;edkEnd();
            this->deleteName();edkEnd();
        }
        //create a new testure
        bool createTexture(edk::char8* name,edk::size2ui32 size,edk::uint32 mode,edk::uint32 filter){
            this->deleteTexture();edkEnd();
            if(name){
                this->file = new edk::Texture2DFile;edkEnd();
                if(this->file){
                    if(this->file->createTexture(size.width,size.height,mode,NULL,filter)){
                        //save the name
                        if(this->setName(name)){
                            //save the code
                            this->code=this->file->getID();edkEnd();
                            this->filter = filter;edkEnd();
                            return true;
                        }
                    }
                }
            }
            this->deleteTexture();edkEnd();
            return false;
        }
        //draw in the texture
        bool drawTexture(edk::uint8* image,edk::uint32 filter){
            if(image){
                //draw on the texture
                return this->file->drawToTexture(image,filter);edkEnd();
            }
            return false;
        }
        //read from the texture
        bool readTexture(edk::uint8* image,edk::uint32 format){
            if(image){
                //read from the texture
                return this->file->readFromTexture(image,format);edkEnd();
            }
            return false;
        }
        //load texture
        bool loadFromFile(edk::char8* name,edk::uint32 filter){
            this->deleteTexture();edkEnd();
            this->file = new edk::Texture2DFile;edkEnd();
            if(this->file){
                if(this->file->loadFromFile(name,filter)){
                    //save the name
                    if(this->setName(name)){
                        //save the code
                        this->code=this->file->getID();edkEnd();
                        this->filter = filter;edkEnd();
                        return true;
                    }
                }
            }
            this->deleteTexture();edkEnd();
            return false;
        }
        bool loadFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter){
            this->deleteTexture();edkEnd();
            if(name){
                this->file = new edk::Texture2DFile;edkEnd();
                if(this->file){
                    if(this->file->loadFromMemory(image,size,filter)){
                        //save the name
                        if(this->setName(name)){
                            //save the code
                            this->code=this->file->getID();edkEnd();
                            this->filter = filter;edkEnd();
                            return true;
                        }
                    }
                }
            }
            this->deleteTexture();edkEnd();
            return false;
        }
        bool setFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 filter){
            this->deleteTexture();edkEnd();
            if(name){
                this->file = new edk::Texture2DFile;edkEnd();
                if(this->file){
                    if(this->file->setFromMemory(/*name,*/image,width,height,channels,filter)){
                        //save the name
                        if(this->setName(name)){
                            //save the code
                            this->code=this->file->getID();edkEnd();
                            this->filter = filter;edkEnd();
                            return true;
                        }
                    }
                }
            }
            this->deleteTexture();edkEnd();
            return false;
        }
        //retain release
        void retainTexture(){
            this->count++;edkEnd();
        }
        bool releaseTexture(){
            if(this->count){
                this->count--;edkEnd();
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
    //read from the texture
    bool readTexture(edk::Texture2DList::TextureCode* temp,edk::uint8* image,edk::uint32 format);
    //remove the texture
    bool removeTexture(edk::Texture2DList::TextureCode* temp);
    //delete the texture
    bool deleteTexture(edk::Texture2DList::TextureCode* temp);
};
}

#endif // Texture2DList_H
