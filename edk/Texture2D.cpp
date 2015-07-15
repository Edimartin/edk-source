#include "Texture2D.h"

/*
Library Texture2D - 2D Textures in GU
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
#warning "            Inside Texture2D.cpp"
#endif

edk::Texture2D::Texture2D()
{
    //ctor
    this->textureId=0u;
    this->mode = 0u;
    this->filter = 0u;
}

edk::Texture2D::~Texture2D()
{
    //dtor
    this->deleteTexture();
}

//alloc the textureObject
bool edk::Texture2D::createTexture(edk::uint32 width, edk::uint32 height, edk::uint32 mode, const edk::classID  data, edk::uint32 filter){
    //alloc the texture
    //first delete the texture
    this->deleteTexture();

    //then alloc the texture
    this->textureId = edk::GU::guAllocTexture2D(width, height, mode, filter, data);
    if(textureId){
        this->size.width = width;
        this->size.height = height;
        this->mode = mode;
        this->filter = filter;
        //return true
        return true;
    }
    //else return false
    return false;
}
//draw to the texture
bool edk::Texture2D::drawToTexture(const edk::classID  data){
    //test if have texture
    if(this->getID() && this->size.width && this->size.height && this->mode){
        //then draw to texture
        return edk::GU::guDrawToTexture(this->getID(),this->size.width,this->size.height,this->mode,this->filter,data);
    }
    return false;
}
bool edk::Texture2D::drawToTexture(const edk::classID  data, edk::uint32 filter){
    //test if have texture
    if(this->getID() && this->size.width && this->size.height && this->mode){
        //then draw to texture
        this->filter = filter;
        return edk::GU::guDrawToTexture(this->getID(),this->size.width,this->size.height,this->mode,filter,data);
    }
    return false;
}

//GETTERS
//return the textureID
edk::uint32 edk::Texture2D::getID(){
    //
    return this->textureID();
}
edk::size2ui32 edk::Texture2D::getSize(){
    return this->size;
}

edk::uint32 edk::Texture2D::width(){
    return this->size.width;
}
edk::uint32 edk::Texture2D::height(){
    return this->size.height;
}

edk::uint32 edk::Texture2D::textureID(){
    //
    return this->textureId;
}
//DELETE
//remove the texture
void edk::Texture2D::deleteTexture(){
    //
    if(this->textureId){
        //
        edk::Texture2D::deleteTextureID(this->textureId);

        //clean the textureID
        this->textureId=0u;
    }
    this->size.width=this->size.height=0u;

    //delete the name
    this->deleteName();
}
//delete the ID
void edk::Texture2D::deleteTextureID(edk::uint32 id){
    //test the ID
    if(id){
        //delete
        edk::GU::guDeleteTexture(id);
    }
}
//Super Class Functions
//retain
edk::Texture2D* edk::Texture2D::retainObject(edk::Texture2D** pointer){
    //retain the super
    return (edk::Texture2D*)edk::ObjectWithName::retainObject((edk::ObjectWithName**)pointer);
    //return NULL;
}
//release
bool edk::Texture2D::releaseObject(edk::Texture2D** pointer){
    //
    return edk::ObjectWithName::releaseObject((edk::ObjectWithName**) pointer);
}
void edk::Texture2D::saveObject(ObjectWithName** pointer){
    //get a temp texture
    /*
    edk::Texture2D** temp = (edk::Texture2D**)pointer;
    if(temp){
        //
        *temp=(edk::Texture2D*)this;
    }
    */
    edk::uint32* temp = (edk::uint32*)pointer;
    if(temp){
        //
        *temp = this->textureId;
    }
}

//Clean the object
void edk::Texture2D::cleanObject(ObjectWithName** pointer){
    //
    /*
    edk::Texture2D** temp = (edk::Texture2D**)pointer;
    if(temp){
        //
        *temp=(edk::Texture2D*)NULL;
    }
    */

    edk::uint32* temp = (edk::uint32*)pointer;
    if(temp){
        //
        *temp = 0u;
    }
}
