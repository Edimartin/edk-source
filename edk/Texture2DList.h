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
    virtual ~Texture2DList();

    void Constructor();
    void Destructor();

    //filters
    //GU_NEAREST
    //GU_LINEAR
    //GU_NEAREST_MIPMAP_NEAREST
    //GU_NEAREST_MIPMAP_LINEAR
    //GU_LINEAR_MIPMAP_NEAREST
    //GU_LINEAR_MIPMAP_LINEAR
    //create a new texture
    edk::uint32 createTexture(edk::char8* name,edk::size2ui32 size,edk::uint32 mode = GU_RGB,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 createTexture(const char8* name,edk::size2ui32 size,edk::uint32 mode = GU_RGB,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 createTextureWithPBODraw(edk::char8* name,edk::size2ui32 size,edk::uint32 mode,edk::uint32 minFilter,edk::uint32 magFilter);
    edk::uint32 createTextureWithPBODraw(const char8* name,edk::size2ui32 size,edk::uint32 mode,edk::uint32 minFilter,edk::uint32 magFilter);
    edk::uint32 createAndDrawTexture(edk::char8* name,edk::size2ui32 size,edk::uint8* image,edk::uint32 mode = GU_RGB,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 createAndDrawTexture(const char8* name,edk::size2ui32 size,edk::uint8* image,edk::uint32 mode = GU_RGB,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 createAndDrawTextureWithPBODraw(edk::char8* name,edk::size2ui32 size,edk::uint8* image,edk::uint32 mode,edk::uint32 minFilter,edk::uint32 magFilter);
    edk::uint32 createAndDrawTextureWithPBODraw(const char8* name,edk::size2ui32 size,edk::uint8* image,edk::uint32 mode,edk::uint32 minFilter,edk::uint32 magFilter);
    //create a new textureRepeat
    edk::uint32 createTextureRepeat(edk::char8* name,edk::size2ui32 size,edk::uint32 mode = GU_RGB,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 createTextureRepeat(const char8* name,edk::size2ui32 size,edk::uint32 mode = GU_RGB,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 createTextureWithPBODrawRepeat(edk::char8* name,edk::size2ui32 size,edk::uint32 mode,edk::uint32 minFilter,edk::uint32 magFilter);
    edk::uint32 createTextureWithPBODrawRepeat(const char8* name,edk::size2ui32 size,edk::uint32 mode,edk::uint32 minFilter,edk::uint32 magFilter);
    edk::uint32 createAndDrawTextureRepeat(edk::char8* name,edk::size2ui32 size,edk::uint8* image,edk::uint32 mode = GU_RGB,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 createAndDrawTextureRepeat(const char8* name,edk::size2ui32 size,edk::uint8* image,edk::uint32 mode = GU_RGB,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 createAndDrawTextureWithPBODrawRepeat(edk::char8* name,edk::size2ui32 size,edk::uint8* image,edk::uint32 mode,edk::uint32 minFilter,edk::uint32 magFilter);
    edk::uint32 createAndDrawTextureWithPBODrawRepeat(const char8* name,edk::size2ui32 size,edk::uint8* image,edk::uint32 mode,edk::uint32 minFilter,edk::uint32 magFilter);
    //draw on a texture
    bool drawTexture(edk::char8* name,edk::uint8* image,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool drawTexture(const char8* name,edk::uint8* image,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool drawTexture(edk::uint32 code,edk::uint8* image,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //draw on a textureRepeat
    bool drawTextureRepeat(edk::char8* name,edk::uint8* image,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool drawTextureRepeat(const char8* name,edk::uint8* image,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool drawTextureRepeat(edk::uint32 code,edk::uint8* image,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
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
    //filters
    //GU_NEAREST
    //GU_LINEAR
    //GU_NEAREST_MIPMAP_NEAREST
    //GU_NEAREST_MIPMAP_LINEAR
    //GU_LINEAR_MIPMAP_NEAREST
    //GU_LINEAR_MIPMAP_LINEAR
    bool readTexture(edk::char8* name,edk::uint32 format,edk::uint8* image,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool readTexture(const char8* name,edk::uint32 format,edk::uint8* image,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool readTexture(edk::uint32 code,edk::uint32 format,edk::uint8* image);
    //Load Texture
    edk::uint32 loadTexture(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 loadTexture(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //Load TextureRepeat
    edk::uint32 loadTextureRepeat(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 loadTextureRepeat(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //load Texture from memory
    edk::uint32 loadTextureFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 loadTextureFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //load TextureRepeat from memory
    edk::uint32 loadTextureRepeatFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 loadTextureRepeatFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //set Texture from memory
    edk::uint32 setTextureFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 setTextureFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //set TextureRepeat from memory
    edk::uint32 setTextureRepeatFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 setTextureRepeatFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //load the texture from a file package
    edk::uint32 loadTextureFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 loadTextureFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //load the textureRepeat from a file package
    edk::uint32 loadTextureRepeatFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 loadTextureRepeatFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //retain the texture
    bool retainTexture(edk::uint32 code);
    //remove texture
    bool removeTexture(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool removeTexture(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool removeTexture(edk::uint32 code);
    //delete texture
    bool deleteTexture(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool deleteTexture(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool deleteTexture(edk::uint32 code);
    //delete all textures
    void deleteAllTextures();
    //return the size of the texture
    //filters
    //GU_NEAREST
    //GU_LINEAR
    //GU_NEAREST_MIPMAP_NEAREST
    //GU_NEAREST_MIPMAP_LINEAR
    //GU_LINEAR_MIPMAP_NEAREST
    //GU_LINEAR_MIPMAP_LINEAR
    edk::size2ui32 getTextureSize(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::size2ui32 getTextureSize(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::size2ui32 getTextureSize(edk::uint32 code);
    edk::uint32 getTextureWidth(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 getTextureWidth(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 getTextureWidth(edk::uint32 code);
    edk::uint32 getTextureHeight(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 getTextureHeight(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint32 getTextureHeight(edk::uint32 code);
    edk::uint8 getTextureBytesPerChannel(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint8 getTextureBytesPerChannel(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    edk::uint8 getTextureBytesPerChannel(edk::uint32 code);
    //return the textureName
    edk::char8* getTextureName(edk::uint32 code);
    edk::uint32 getTextureMinFilter(edk::uint32 code);
    edk::uint32 getTextureMagFilter(edk::uint32 code);
    //Test if have the texture
    bool haveTexture(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool haveTexture(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
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
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~TextureCode(){
            this->Destructor();
        }

        void Constructor(){
            edk::Name::Constructor();
            if(this->classThis!=this){
                this->classThis=this;
                this->code=0u;
                this->file=NULL;
                this->count=0u;
                this->minFilter = 0u;
                this->magFilter = 0u;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
                this->deleteTexture();
            }
            edk::Name::Destructor();
        }
        void deleteTexture(){
            if(this->file){
                delete this->file;
            }
            this->file=NULL;
            this->code=0u;
            this->minFilter = 0u;
            this->magFilter = 0u;
            this->deleteName();
        }
        //create a new texture
        bool createTexture(edk::char8* name,edk::size2ui32 size,edk::uint32 mode,edk::uint32 minFilter,edk::uint32 magFilter){
            this->deleteTexture();
            if(name){
                this->file = new edk::Texture2DFile;
                if(this->file){
                    if(this->file->createTexture(size.width,size.height,mode,NULL,minFilter,magFilter)){
                        //save the name
                        if(this->setName(name)){
                            //save the code
                            this->code=this->file->getID();
                            this->minFilter = minFilter;
                            this->magFilter = magFilter;
                            return true;
                        }
                    }
                }
            }
            this->deleteTexture();
            return false;
        }
        bool createTextureWithPBODraw(edk::char8* name,edk::size2ui32 size,edk::uint32 mode,edk::uint32 minFilter,edk::uint32 magFilter){
            this->deleteTexture();
            if(name){
                this->file = new edk::Texture2DFile;
                if(this->file){
                    if(this->file->createTextureWithPBODraw(size.width,size.height,mode,NULL,minFilter,magFilter)){
                        //save the name
                        if(this->setName(name)){
                            //save the code
                            this->code=this->file->getID();
                            this->minFilter = minFilter;
                            this->magFilter = magFilter;
                            return true;
                        }
                    }
                }
            }
            this->deleteTexture();
            return false;
        }
        bool createAndDrawTexture(edk::char8* name,edk::size2ui32 size,edk::uint8* image,edk::uint32 mode,edk::uint32 minFilter,edk::uint32 magFilter){
            this->deleteTexture();
            if(name){
                this->file = new edk::Texture2DFile;
                if(this->file){
                    if(this->file->createTexture(size.width,size.height,mode,image,minFilter,magFilter)){
                        //save the name
                        if(this->setName(name)){
                            //save the code
                            this->code=this->file->getID();
                            this->minFilter = minFilter;
                            this->magFilter = magFilter;
                            return true;
                        }
                    }
                }
            }
            this->deleteTexture();
            return false;
        }
        bool createAndDrawTextureWithPBODraw(edk::char8* name,edk::size2ui32 size,edk::uint8* image,edk::uint32 mode,edk::uint32 minFilter,edk::uint32 magFilter){
            this->deleteTexture();
            if(name){
                this->file = new edk::Texture2DFile;
                if(this->file){
                    if(this->file->createTextureWithPBODraw(size.width,size.height,mode,image,minFilter,magFilter)){
                        //save the name
                        if(this->setName(name)){
                            //save the code
                            this->code=this->file->getID();
                            this->minFilter = minFilter;
                            this->magFilter = magFilter;
                            return true;
                        }
                    }
                }
            }
            this->deleteTexture();
            return false;
        }
        //draw in the texture
        bool drawTexture(edk::uint8* image,edk::uint32 minFilter,edk::uint32 magFilter){
            if(image){
                //draw on the texture
                return this->file->drawToTexture(image,minFilter,magFilter);
            }
            return false;
        }
        //draw in the textureRepeat
        bool drawTextureRepeat(edk::uint8* image,edk::uint32 minFilter,edk::uint32 magFilter){
            if(image){
                //draw on the texture
                return this->file->drawToTextureRepeat(image,minFilter,magFilter);
            }
            return false;
        }
        //read from the texture
        bool readTexture(edk::uint8* image,edk::uint32 format){
            if(image){
                //read from the texture
                return this->file->readFromTexture(image,format);
            }
            return false;
        }
        //read from the textureRepeat
        bool readTextureRepeat(edk::uint8* image,edk::uint32 format){
            if(image){
                //read from the texture
                return this->file->readFromTextureRepeat(image,format);
            }
            return false;
        }
        //load texture
        bool loadFromFile(edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
            this->deleteTexture();
            this->file = new edk::Texture2DFile;
            if(this->file){
                if(this->file->loadFromFile(name,minFilter,magFilter)){
                    //save the name
                    if(this->setName(name)){
                        //save the code
                        this->code=this->file->getID();
                        this->minFilter = minFilter;
                        this->magFilter = magFilter;
                        return true;
                    }
                }
            }
            this->deleteTexture();
            return false;
        }
        bool loadFromFileRepeat(edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
            this->deleteTexture();
            this->file = new edk::Texture2DFile;
            if(this->file){
                if(this->file->loadFromFileRepeat(name,minFilter,magFilter)){
                    //save the name
                    if(this->setName(name)){
                        //save the code
                        this->code=this->file->getID();
                        this->minFilter = minFilter;
                        this->magFilter = magFilter;
                        return true;
                    }
                }
            }
            this->deleteTexture();
            return false;
        }
        bool loadFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
            this->deleteTexture();
            if(name){
                this->file = new edk::Texture2DFile;
                if(this->file){
                    if(this->file->loadFromMemory(image,size,minFilter,magFilter)){
                        //save the name
                        if(this->setName(name)){
                            //save the code
                            this->code=this->file->getID();
                            this->minFilter = minFilter;
                            this->magFilter = magFilter;
                            return true;
                        }
                    }
                }
            }
            this->deleteTexture();
            return false;
        }
        bool loadFromMemoryRepeat(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
            this->deleteTexture();
            if(name){
                this->file = new edk::Texture2DFile;
                if(this->file){
                    if(this->file->loadFromMemoryRepeat(image,size,minFilter,magFilter)){
                        //save the name
                        if(this->setName(name)){
                            //save the code
                            this->code=this->file->getID();
                            this->minFilter = minFilter;
                            this->magFilter = magFilter;
                            return true;
                        }
                    }
                }
            }
            this->deleteTexture();
            return false;
        }
        bool setFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 minFilter,edk::uint32 magFilter){
            this->deleteTexture();
            if(name){
                this->file = new edk::Texture2DFile;
                if(this->file){
                    if(this->file->setFromMemory(/*name,*/image,width,height,channels,minFilter,magFilter)){
                        //save the name
                        if(this->setName(name)){
                            //save the code
                            this->code=this->file->getID();
                            this->minFilter = minFilter;
                            this->magFilter = magFilter;
                            return true;
                        }
                    }
                }
            }
            this->deleteTexture();
            return false;
        }
        bool setFromMemoryRepeat(edk::char8* name,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 minFilter,edk::uint32 magFilter){
            this->deleteTexture();
            if(name){
                this->file = new edk::Texture2DFile;
                if(this->file){
                    if(this->file->setFromMemoryRepeat(/*name,*/image,width,height,channels,minFilter,magFilter)){
                        //save the name
                        if(this->setName(name)){
                            //save the code
                            this->code=this->file->getID();
                            this->minFilter = minFilter;
                            this->magFilter = magFilter;
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
        edk::uint32 minFilter;
        edk::uint32 magFilter;
        edk::uint32 code;
        edk::Texture2DFile* file;
    private:
        //textures using count
        edk::uint32 count;
    private:
        edk::classID classThis;
    };
    //Tree to save the textures by the code
    class TextureCodeTree:public edk::vector::BinaryTree<edk::Texture2DList::TextureCode*>{
    public:
        TextureCodeTree(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~TextureCodeTree(){
        }

        void Constructor(){
            edk::vector::BinaryTree<edk::Texture2DList::TextureCode*>::Constructor();
            if(this->classThis!=this){
                this->classThis=this;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
                edk::uint32 size = this->size();
                edk::Texture2DList::TextureCode* temp;
                for(edk::uint32 i=0u;i<size;i++){
                    temp = this->getElementInPosition(i);
                    if(temp){
                        delete temp;
                    }
                }
                this->clean();
            }
            edk::vector::BinaryTree<edk::Texture2DList::TextureCode*>::Destructor();
        }

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
    private:
        edk::classID classThis;
    };
    //nameFilterTree
    class NameFilterTree: public edk::vector::BinaryTree<edk::Texture2DList::TextureCode*>{
    public:
        NameFilterTree(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~NameFilterTree(){
            this->Destructor();
        }

        void Constructor(){
            edk::vector::BinaryTree<edk::Texture2DList::TextureCode*>::Constructor();
            if(this->classThis!=this){
                this->classThis=this;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
            }
            edk::vector::BinaryTree<edk::Texture2DList::TextureCode*>::Destructor();
        }

        //virtual functions
        virtual bool firstBiggerSecond(edk::Texture2DList::TextureCode* first,edk::Texture2DList::TextureCode* second){
            //load the textures
            if(first && second){
                if(first->getName()&&second->getName()){
                    if(first->minFilter>second->minFilter){
                        return true;
                    }
                    else if(first->minFilter==second->minFilter){
                        if(first->magFilter>second->magFilter){
                            return true;
                        }
                        else if(edk::Name::firstNameBiggerSecond(first->getName(),second->getName())){
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        virtual bool firstEqualSecond(edk::Texture2DList::TextureCode* first,edk::Texture2DList::TextureCode* second){
            if(first && second){
                if(first->minFilter==second->minFilter
                        && first->magFilter==second->magFilter
                        && edk::Name::stringEqual(first->getName(),second->getName())
                        ){
                    return true;
                }
            }
            return false;
        }
    private:
        edk::classID classThis;
    };
    //Tree to save the textures by code
    static edk::Texture2DList::TextureCodeTree codeTree;
    //Tree to save the textures by name
    static edk::Texture2DList::NameFilterTree nameTree;
    //Tree to save the texturesRepeat by name
    static edk::Texture2DList::NameFilterTree nameTreeRepeat;

    static edk::uint64 templateConstructNeed;

    //get the texture by the name
    edk::Texture2DList::TextureCode* getTextureByName(edk::char8* name, edk::uint32 minFilter, edk::uint32 magFilter);
    //get the texture by the code
    edk::Texture2DList::TextureCode* getTextureByCode(edk::uint32 code);
    //get the textureRepeat by the name
    edk::Texture2DList::TextureCode* getTextureRepeatByName(edk::char8* name, edk::uint32 minFilter, edk::uint32 magFilter);
    //draw on the texture
    bool drawTexture(edk::Texture2DList::TextureCode* temp,edk::uint8* image,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //draw on the textureRepeat
    bool drawTextureRepeat(edk::Texture2DList::TextureCode* temp,edk::uint8* image,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //read from the texture
    bool readTexture(edk::Texture2DList::TextureCode* temp,edk::uint8* image,edk::uint32 format);
    //read from the textureRepeat
    bool readTextureRepeat(edk::Texture2DList::TextureCode* temp,edk::uint8* image,edk::uint32 format);
    //remove the texture
    bool removeTexture(edk::Texture2DList::TextureCode* temp);
    //delete the texture
    bool deleteTexture(edk::Texture2DList::TextureCode* temp);
private:
    edk::classID classThis;
};
}

#endif // Texture2DList_H
