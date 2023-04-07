#include "Texture2D.h"

/*
Library Texture2D - 2D Textures in GU
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
#pragma message "            Inside Texture2D.cpp"
#endif

edk::Texture2D::Texture2D()
{
    //ctor
    this->textureId=0u;
    this->mode = 0u;edkEnd();
    this->filter = 0u;edkEnd();
}

edk::Texture2D::~Texture2D()
{
    //dtor
    this->deleteTexture();edkEnd();
}

//alloc the textureObject
bool edk::Texture2D::createTexture(edk::uint32 width, edk::uint32 height, edk::uint32 mode, const edk::classID  data, edk::uint32 filter){
    //alloc the texture
    //first delete the texture
    this->deleteTexture();edkEnd();

    switch(mode){
    case EDK_RGB:
        this->mode = GU_RGB;edkEnd();
        break;
    case EDK_RGBA:
        this->mode = GU_RGBA;edkEnd();
        break;
    case EDK_LUMINANCE:
        this->mode = GU_LUMINANCE;edkEnd();
        break;
    case EDK_LUMINANCE_ALPHA:
        this->mode = GU_LUMINANCE_ALPHA;edkEnd();
        break;
    case GU_RGB:
        this->mode = GU_RGB;edkEnd();
        break;
    case GU_RGBA:
        this->mode = GU_RGBA;edkEnd();
        break;
    case GU_LUMINANCE:
        this->mode = GU_LUMINANCE;edkEnd();
        break;
    case GU_LUMINANCE_ALPHA:
        this->mode = GU_LUMINANCE_ALPHA;edkEnd();
        break;
    default:
        return false;
    }

    //then alloc the texture
    this->textureId = edk::GU::guAllocTexture2D(width, height, this->mode, filter, data);edkEnd();
    if(textureId){
        this->size.width = width;edkEnd();
        this->size.height = height;edkEnd();
        this->filter = filter;edkEnd();
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
        return edk::GU::guDrawToTexture(this->getID(),this->size.width,this->size.height,this->mode,this->filter,data);edkEnd();
    }
    return false;
}
bool edk::Texture2D::drawToTexture(const edk::classID  data, edk::uint32 filter){
    //test if have texture
    if(this->getID() && this->size.width && this->size.height && this->mode){
        //then draw to texture
        this->filter = filter;edkEnd();
        return edk::GU::guDrawToTexture(this->getID(),this->size.width,this->size.height,this->mode,filter,data);edkEnd();
    }
    return false;
}
//read the texture
bool edk::Texture2D::readFromTexture(const edk::classID  data,edk::uint32 format){
    //test if have texture
    if(this->getID() && this->size.width && this->size.height && this->mode){
        //
        return edk::GU_GLSL::guReadTexture(this->getID(),format,data);edkEnd();
    }
    return false;
}

//GETTERS
//return the textureID
edk::uint32 edk::Texture2D::getID(){
    //
    return this->textureID();edkEnd();
}
edk::size2ui32 edk::Texture2D::getSize(){
    return this->size;edkEnd();
}
edk::uint32 edk::Texture2D::getModeEDK(){
    switch(this->mode){
    case GU_RGB:
        return EDK_RGB;
    case GU_RGBA:
        return EDK_RGBA;
    case GU_LUMINANCE:
        return EDK_LUMINANCE;
    case GU_LUMINANCE_ALPHA:
        return EDK_LUMINANCE_ALPHA;
    }
    return 0u;
}
edk::uint32 edk::Texture2D::getModeGU(){
    return this->mode;edkEnd();
}
edk::uint32 edk::Texture2D::width(){
    return this->size.width;edkEnd();
}
edk::uint32 edk::Texture2D::height(){
    return this->size.height;edkEnd();
}

edk::uint32 edk::Texture2D::textureID(){
    //
    return this->textureId;edkEnd();
}
//DELETE
//remove the texture
void edk::Texture2D::deleteTexture(){
    //
    if(this->textureId){
        //
        edk::Texture2D::deleteTextureID(this->textureId);edkEnd();

        //clean the textureID
        this->textureId=0u;
    }
    this->size.width=this->size.height=0u;

    //delete the name
    this->deleteName();edkEnd();
}
//delete the ID
void edk::Texture2D::deleteTextureID(edk::uint32 id){
    //test the ID
    if(id){
        //delete
        edk::GU::guDeleteTexture(id);edkEnd();
    }
}
//Super Class Functions
//retain
edk::Texture2D* edk::Texture2D::retainObject(edk::Texture2D** pointer){
    //retain the super
    return (edk::Texture2D*)edk::ObjectWithName::retainObject((edk::ObjectWithName**)pointer);edkEnd();
    //return NULL;
}
//release
bool edk::Texture2D::releaseObject(edk::Texture2D** pointer){
    //
    return edk::ObjectWithName::releaseObject((edk::ObjectWithName**) pointer);edkEnd();
}
void edk::Texture2D::saveObject(ObjectWithName** pointer){
    //get a temp texture
    /*
    edk::Texture2D** temp = (edk::Texture2D**)pointer;edkEnd();
    if(temp){
        //
        *temp=(edk::Texture2D*)this;edkEnd();
    }
    */
    edk::uint32* temp = (edk::uint32*)pointer;edkEnd();
    if(temp){
        //
        *temp = this->textureId;edkEnd();
    }
}

//Clean the object
void edk::Texture2D::cleanObject(ObjectWithName** pointer){
    //
    /*
    edk::Texture2D** temp = (edk::Texture2D**)pointer;edkEnd();
    if(temp){
        //
        *temp=(edk::Texture2D*)NULL;edkEnd();
    }
    */

    edk::uint32* temp = (edk::uint32*)pointer;edkEnd();
    if(temp){
        //
        *temp = 0u;edkEnd();
    }
}
