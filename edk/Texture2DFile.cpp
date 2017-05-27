#include "Texture2DFile.h"

/*
Library Texture2DFile - Load a 2D Image to a texture
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
#warning "            Inside Texture2DFile.cpp"
#endif

using namespace edk;

edk::Texture2DFile::Texture2DFile()
{
    //ctor
}
edk::Texture2DFile::Texture2DFile(edk::char8 *textureFileName){
    //
    this->setName(textureFileName);
}
edk::Texture2DFile::Texture2DFile(const char *textureFileName){
    //
    this->setName(textureFileName);
}

edk::Texture2DFile::~Texture2DFile()
{
    //dtor
    this->deleteTexture();
    this->deleteName();
    //remove all
    this->removeAll();
}

//LOAD
bool edk::Texture2DFile::loadFromFile(edk::char8 *fileName,edk::uint32 filter){
    //return
    bool ret=false;
    //delete the last texture
    this->deleteTexture();
    //first open the image
    if(this->image.loadFromFileToRGBA(fileName)){
        //test the channels
        switch(this->image.getChannels()){
        case 1u://GRAYSCALE
            //load the texture
            this->createTexture(this->image.width(),
                                this->image.height(),
                                GU_LUMINANCE,
                                (const edk::classID)this->image.getPixels(),
                                filter
                                );
            break;
        case 3u://RGB
            //load the texture
            this->createTexture(this->image.width(),
                                this->image.height(),
                                GU_RGB,
                                (const edk::classID)this->image.getPixels(),
                                filter
                                );
            break;
        case 4u://RGBA
            //load the texture
            this->createTexture(this->image.width(),
                                this->image.height(),
                                GU_RGBA,
                                (const edk::classID)this->image.getPixels(),
                                filter
                                );
            break;
        }

        //test if create the texture
        if(this->getID()){
            //set the textureName
            this->setName( this->image.getFileName() );

            //return true
            ret = true;
        }
        //delete the image
        this->image.deleteImage();
    }
    //return true or false
    return ret;
}
bool edk::Texture2DFile::loadFromFile(const char *fileName,edk::uint32 filter){
    //
    return this->loadFromFile((edk::char8 *)fileName);
}
//LOAD from memory
bool edk::Texture2DFile::loadFromMemory(edk::uint8* image,edk::uint32 size,edk::uint32 filter){
    //return
    bool ret=false;
    //delete the last texture
    this->deleteTexture();
    //test the image
    if(image && size){
        //process the decode
        if(this->image.loadFromMemoryToRGBA(image,size)){
            //test the channels
            switch(this->image.getChannels()){
            case 1u://GRAYSCALE
                //load the texture
                this->createTexture(this->image.width(),
                                    this->image.height(),
                                    GU_LUMINANCE,
                                    (const edk::classID)this->image.getPixels(),
                                    filter
                                    );
                break;
            case 3u://RGB
                //load the texture
                this->createTexture(this->image.width(),
                                    this->image.height(),
                                    GU_RGB,
                                    (const edk::classID)this->image.getPixels(),
                                    filter
                                    );
                break;
            case 4u://RGBA
                //load the texture
                this->createTexture(this->image.width(),
                                    this->image.height(),
                                    GU_RGBA,
                                    (const edk::classID)this->image.getPixels(),
                                    filter
                                    );
                break;
            }

            //test if create the texture
            if(this->getID()){
                //set the textureName
                this->setName( this->image.getFileName() );

                //return true
                ret = true;
            }
            //delete the image
            this->image.deleteImage();
        }
    }
    return ret;
}
//SERT from memory
bool edk::Texture2DFile::setFromMemory(edk::char8 *fileName,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 filter){
    //return
    bool ret=false;
    //delete the last texture
    this->deleteTexture();
    //test the image
    if(image && width && height && channels){
        //process the decode
            //test the channels
            switch(channels){
            case 1u://GRAYSCALE
                //load the texture
                this->createTexture(width,
                                    height,
                                    GU_LUMINANCE,
                                    (const edk::classID)image,
                                    filter
                                    );
                break;
            case 3u://RGB
                //load the texture
                this->createTexture(width,
                                    height,
                                    GU_RGB,
                                    (const edk::classID)image,
                                    filter
                                    );
                break;
            case 4u://RGBA
                //load the texture
                this->createTexture(width,
                                    height,
                                    GU_RGBA,
                                    (const edk::classID)image,
                                    filter
                                    );
                break;
            }

            //test if create the texture
            if(this->getID()){
                //set the textureName
                this->setName( "" );

                //return true
                ret = true;
            }
            //delete the image
            this->image.deleteImage();
    }
    return ret;
}
bool edk::Texture2DFile::setFromMemory(const edk::char8 *fileName,edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 filter){
    return this->setFromMemory((edk::char8*) fileName,image,width,height,channels,filter);
}
