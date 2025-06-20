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

edk::Texture2D::Texture2D(){
    this->classThis=NULL;
    this->Constructor();
}

edk::Texture2D::~Texture2D(){
    this->Destructor();
}

void edk::Texture2D::Constructor(){
    edk::ObjectWithName::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        this->textureId=0u;
        this->pbo=0u;
        this->mode = 0u;
        this->minFilter = 0u;
        this->magFilter = 0u;
    }
}
void edk::Texture2D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->deleteTexture();
    }
    edk::ObjectWithName::Destructor();
}

//alloc the textureObject
bool edk::Texture2D::createTexture(edk::uint32 width,
                                   edk::uint32 height,
                                   edk::uint32 mode,
                                   const edk::classID  data,
                                   edk::uint32 minFilter,
                                   edk::uint32 magFilter
                                   ){
    //alloc the texture
    //first delete the texture
    this->deleteTexture();

    switch(mode){
    case EDK_RGB:
        this->mode = GU_RGB;
        break;
    case EDK_RGBA:
        this->mode = GU_RGBA;
        break;
    case EDK_LUMINANCE:
        this->mode = GU_LUMINANCE;
        break;
    case EDK_LUMINANCE_ALPHA:
        this->mode = GU_LUMINANCE_ALPHA;
        break;
    case GU_RGB:
        this->mode = GU_RGB;
        break;
    case GU_RGBA:
        this->mode = GU_RGBA;
        break;
    case GU_LUMINANCE:
        this->mode = GU_LUMINANCE;
        break;
    case GU_LUMINANCE_ALPHA:
        this->mode = GU_LUMINANCE_ALPHA;
        break;
    default:
        return false;
    }

    //then alloc the texture
    this->textureId = edk::GU::guAllocTexture2D(width, height, this->mode, minFilter,magFilter, data);
    if(this->textureId){
        this->size.width = width;
        this->size.height = height;
        this->minFilter = minFilter;
        this->magFilter = magFilter;
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::Texture2D::createTextureWithPBODraw(edk::uint32 width,
                                              edk::uint32 height,
                                              edk::uint32 mode,
                                              const edk::classID  data,
                                              edk::uint32 minFilter,
                                              edk::uint32 magFilter
                                              ){
    //alloc the texture
    //first delete the texture
    this->deleteTexture();

    edk::uint8 channels = 3u;

    switch(mode){
    case EDK_RGB:
        this->mode = GU_RGB;
        channels = 3u;
        break;
    case EDK_RGBA:
        this->mode = GU_RGBA;
        channels = 4u;
        break;
    case EDK_LUMINANCE:
        this->mode = GU_LUMINANCE;
        channels = 1u;
        break;
    case EDK_LUMINANCE_ALPHA:
        this->mode = GU_LUMINANCE_ALPHA;
        channels = 2u;
        break;
    case GU_RGB:
        this->mode = GU_RGB;
        channels = 3u;
        break;
    case GU_RGBA:
        this->mode = GU_RGBA;
        channels = 4u;
        break;
    case GU_LUMINANCE:
        this->mode = GU_LUMINANCE;
        channels = 1u;
        break;
    case GU_LUMINANCE_ALPHA:
        this->mode = GU_LUMINANCE_ALPHA;
        channels = 2u;
        break;
    default:
        return false;
    }

    //then alloc the texture
    this->textureId = edk::GU::guAllocTexture2D(width, height, this->mode, minFilter,magFilter, data);
    if(this->textureId){
        this->size.width = width;
        this->size.height = height;
        this->minFilter = minFilter;
        this->magFilter = magFilter;

        //generate the PBO
        this->pbo = edk::GU_GLSL::guAllocBuffer(GU_PIXEL_UNPACK_BUFFER);
        if(this->pbo){
            edk::GU_GLSL::guBufferData(GU_PIXEL_UNPACK_BUFFER,width*height*channels,NULL,GU_STREAM_DRAW);

            //return true
            return true;
        }

    }
    //else return false
    return false;
}
bool edk::Texture2D::createTextureWithPBORead(edk::uint32 width,
                                              edk::uint32 height,
                                              edk::uint32 mode,
                                              const edk::classID  data,
                                              edk::uint32 minFilter,
                                              edk::uint32 magFilter
                                              ){
    //alloc the texture
    //first delete the texture
    this->deleteTexture();

    edk::uint8 channels = 3u;

    switch(mode){
    case EDK_RGB:
        this->mode = GU_RGB;
        channels = 3u;
        break;
    case EDK_RGBA:
        this->mode = GU_RGBA;
        channels = 4u;
        break;
    case EDK_LUMINANCE:
        this->mode = GU_LUMINANCE;
        channels = 1u;
        break;
    case EDK_LUMINANCE_ALPHA:
        this->mode = GU_LUMINANCE_ALPHA;
        channels = 2u;
        break;
    case GU_RGB:
        this->mode = GU_RGB;
        channels = 3u;
        break;
    case GU_RGBA:
        this->mode = GU_RGBA;
        channels = 4u;
        break;
    case GU_LUMINANCE:
        this->mode = GU_LUMINANCE;
        channels = 1u;
        break;
    case GU_LUMINANCE_ALPHA:
        this->mode = GU_LUMINANCE_ALPHA;
        channels = 2u;
        break;
    default:
        return false;
    }

    //then alloc the texture
    this->textureId = edk::GU::guAllocTexture2D(width, height, this->mode, minFilter,magFilter, data);
    if(this->textureId){
        this->size.width = width;
        this->size.height = height;
        this->minFilter = minFilter;
        this->magFilter = magFilter;

        //generate the PBO
        this->pbo = edk::GU_GLSL::guAllocBuffer(GU_PIXEL_PACK_BUFFER);
        if(this->pbo){
            edk::GU_GLSL::guBufferData(GU_PIXEL_PACK_BUFFER,width*height*channels,data,GU_STREAM_DRAW);

            //return true
            return true;
        }

    }
    //else return false
    return false;
}
bool edk::Texture2D::createTextureRepeat(edk::uint32 width,
                                         edk::uint32 height,
                                         edk::uint32 mode,
                                         const edk::classID  data,
                                         edk::uint32 minFilter,
                                         edk::uint32 magFilter
                                         ){
    //alloc the texture
    //first delete the texture
    this->deleteTexture();

    switch(mode){
    case EDK_RGB:
        this->mode = GU_RGB;
        break;
    case EDK_RGBA:
        this->mode = GU_RGBA;
        break;
    case EDK_LUMINANCE:
        this->mode = GU_LUMINANCE;
        break;
    case EDK_LUMINANCE_ALPHA:
        this->mode = GU_LUMINANCE_ALPHA;
        break;
    case GU_RGB:
        this->mode = GU_RGB;
        break;
    case GU_RGBA:
        this->mode = GU_RGBA;
        break;
    case GU_LUMINANCE:
        this->mode = GU_LUMINANCE;
        break;
    case GU_LUMINANCE_ALPHA:
        this->mode = GU_LUMINANCE_ALPHA;
        break;
    default:
        return false;
    }

    //then alloc the texture
    this->textureId = edk::GU::guAllocTexture2DRepeat(width, height, this->mode, minFilter,magFilter, data);
    if(this->textureId){
        this->size.width = width;
        this->size.height = height;
        this->minFilter = minFilter;
        this->magFilter = magFilter;
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::Texture2D::createTextureRepeatWithPBODraw(edk::uint32 width,
                                                    edk::uint32 height,
                                                    edk::uint32 mode,
                                                    const edk::classID  data,
                                                    edk::uint32 minFilter,
                                                    edk::uint32 magFilter
                                                    ){
    //alloc the texture
    //first delete the texture
    this->deleteTexture();

    edk::uint8 channels = 3u;

    switch(mode){
    case EDK_RGB:
        this->mode = GU_RGB;
        channels = 3u;
        break;
    case EDK_RGBA:
        this->mode = GU_RGBA;
        channels = 4u;
        break;
    case EDK_LUMINANCE:
        this->mode = GU_LUMINANCE;
        channels = 1u;
        break;
    case EDK_LUMINANCE_ALPHA:
        this->mode = GU_LUMINANCE_ALPHA;
        channels = 2u;
        break;
    case GU_RGB:
        this->mode = GU_RGB;
        channels = 3u;
        break;
    case GU_RGBA:
        this->mode = GU_RGBA;
        channels = 4u;
        break;
    case GU_LUMINANCE:
        this->mode = GU_LUMINANCE;
        channels = 1u;
        break;
    case GU_LUMINANCE_ALPHA:
        this->mode = GU_LUMINANCE_ALPHA;
        channels = 2u;
        break;
    default:
        return false;
    }

    //then alloc the texture
    this->textureId = edk::GU::guAllocTexture2DRepeat(width, height, this->mode, minFilter,magFilter, data);
    if(this->textureId){
        this->size.width = width;
        this->size.height = height;
        this->minFilter = minFilter;
        this->magFilter = magFilter;

        //generate the PBO
        this->pbo = edk::GU_GLSL::guAllocBuffer(GU_PIXEL_UNPACK_BUFFER);
        if(this->pbo){
            edk::GU_GLSL::guBufferData(GU_PIXEL_UNPACK_BUFFER,width*height*channels,NULL,GU_STREAM_DRAW);

            //return true
            return true;
        }

    }
    //else return false
    return false;
}
bool edk::Texture2D::createTextureRepeatWithPBORead(edk::uint32 width,
                                                    edk::uint32 height,
                                                    edk::uint32 mode,
                                                    const edk::classID  data,
                                                    edk::uint32 minFilter,
                                                    edk::uint32 magFilter
                                                    ){
    //alloc the texture
    //first delete the texture
    this->deleteTexture();

    edk::uint8 channels = 3u;

    switch(mode){
    case EDK_RGB:
        this->mode = GU_RGB;
        channels = 3u;
        break;
    case EDK_RGBA:
        this->mode = GU_RGBA;
        channels = 4u;
        break;
    case EDK_LUMINANCE:
        this->mode = GU_LUMINANCE;
        channels = 1u;
        break;
    case EDK_LUMINANCE_ALPHA:
        this->mode = GU_LUMINANCE_ALPHA;
        channels = 2u;
        break;
    case GU_RGB:
        this->mode = GU_RGB;
        channels = 3u;
        break;
    case GU_RGBA:
        this->mode = GU_RGBA;
        channels = 4u;
        break;
    case GU_LUMINANCE:
        this->mode = GU_LUMINANCE;
        channels = 1u;
        break;
    case GU_LUMINANCE_ALPHA:
        this->mode = GU_LUMINANCE_ALPHA;
        channels = 2u;
        break;
    default:
        return false;
    }

    //then alloc the texture
    this->textureId = edk::GU::guAllocTexture2DRepeat(width, height, this->mode, minFilter,magFilter, data);
    if(this->textureId){
        this->size.width = width;
        this->size.height = height;
        this->minFilter = minFilter;
        this->magFilter = magFilter;

        //generate the PBO
        this->pbo = edk::GU_GLSL::guAllocBuffer(GU_PIXEL_PACK_BUFFER);
        if(this->pbo){
            edk::GU_GLSL::guBufferData(GU_PIXEL_PACK_BUFFER,width*height*channels,data,GU_STREAM_DRAW);

            //return true
            return true;
        }

    }
    //else return false
    return false;
}
//draw to the texture
bool edk::Texture2D::drawToTexture(const edk::classID  data){
    //test if have texture
    if(this->getID() && this->size.width && this->size.height && this->mode){
        //then draw to texture
        if(this->getPBO()){
            return edk::GU::guDrawPBOToTexture2D(this->getPBO(),this->getID(),this->size.width,this->size.height,this->mode,data);
        }
        return edk::GU::guDrawToTexture2D(this->getID(),this->size.width,this->size.height,this->mode,this->minFilter,this->magFilter,data);
    }
    return false;
}
bool edk::Texture2D::drawToTextureRepeat(const edk::classID  data){
    //test if have texture
    if(this->getID() && this->size.width && this->size.height && this->mode){
        //then draw to texture
        if(this->getPBO()){
            return edk::GU::guDrawPBOToTexture2DRepeat(this->getPBO(),this->getID(),this->size.width,this->size.height,this->mode,data);
        }
        return edk::GU::guDrawToTexture2DRepeat(this->getID(),this->size.width,this->size.height,this->mode,this->minFilter,this->magFilter,data);
    }
    return false;
}
bool edk::Texture2D::drawToTexture(const edk::classID  data, edk::uint32 minFilter, edk::uint32 magFilter){
    //test if have texture
    if(this->getID() && this->size.width && this->size.height && this->mode){
        //then draw to texture
        this->minFilter = minFilter;
        this->magFilter = magFilter;
        if(this->getPBO()){
            return edk::GU::guDrawPBOToTexture2D(this->getPBO(),this->getID(),this->size.width,this->size.height,this->mode,data);
        }
        return edk::GU::guDrawToTexture2D(this->getID(),this->size.width,this->size.height,this->mode,minFilter,magFilter,data);
    }
    return false;
}
bool edk::Texture2D::drawToTextureRepeat(const edk::classID  data, edk::uint32 minFilter, edk::uint32 magFilter){
    //test if have texture
    if(this->getID() && this->size.width && this->size.height && this->mode){
        //then draw to texture
        this->minFilter = minFilter;
        this->magFilter = magFilter;
        if(this->getPBO()){
            return edk::GU::guDrawPBOToTexture2DRepeat(this->getPBO(),this->getID(),this->size.width,this->size.height,this->mode,data);
        }
        return edk::GU::guDrawToTexture2DRepeat(this->getID(),this->size.width,this->size.height,this->mode,minFilter,magFilter,data);
    }
    return false;
}
//read the texture
bool edk::Texture2D::readFromTexture(const edk::classID  data,edk::uint32 format){
    //test if have texture
    if(this->getID() && this->size.width && this->size.height && this->mode){
        //
        return edk::GU_GLSL::guReadTexture(this->getID(),format,data);
    }
    return false;
}
bool edk::Texture2D::readFromTextureRepeat(const edk::classID  data,edk::uint32 format){
    //test if have texture
    if(this->getID() && this->size.width && this->size.height && this->mode){
        //
        return edk::GU_GLSL::guReadTextureRepeat(this->getID(),format,data);
    }
    return false;
}

//GETTERS
//return the textureID
edk::uint32 edk::Texture2D::getID(){
    //
    return this->textureID();
}
//return the texturePBO
edk::uint32 edk::Texture2D::getPBO(){
    //
    return this->pbo;
}
edk::size2ui32 edk::Texture2D::getSize(){
    return this->size;
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
    return this->mode;
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
    if(this->pbo){
        //
        edk::GU_GLSL::guDeleteBuffer(this->pbo);

        //clean the pbo
        this->pbo=0u;
    }
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
