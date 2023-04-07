#include "Texture2DFile.h"

/*
Library Texture2DFile - Load a 2D Image to a texture
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
#pragma message "            Inside Texture2DFile.cpp"
#endif

edk::Texture2DFile::Texture2DFile()
{
    //ctor
}
edk::Texture2DFile::Texture2DFile(edk::char8 *textureFileName){
    //
    this->setName(textureFileName);edkEnd();
}
edk::Texture2DFile::Texture2DFile(const char *textureFileName){
    //
    this->setName(textureFileName);edkEnd();
}

edk::Texture2DFile::~Texture2DFile()
{
    //dtor
    this->deleteTexture();edkEnd();
    this->deleteName();edkEnd();
    //remove all
    this->removeAll();edkEnd();
}

//LOAD
bool edk::Texture2DFile::loadFromFile(edk::char8 *fileName,edk::uint32 filter){
    //return
    bool ret=false;edkEnd();
    //delete the last texture
    this->deleteTexture();edkEnd();
    //first open the image
    if(this->image.loadFromFileToRGBA(fileName)){
        //test the channels
        switch(this->image.getChannels()){
        case 1u://GRAYSCALE
            //load the texture
            this->createTexture(this->image.width(),
                                this->image.height(),
                                GU_LUMINANCE,
                                (edk::classID)this->image.getPixels(),
                                filter
                                );edkEnd();
            break;
        case 3u://RGB
            //load the texture
            this->createTexture(this->image.width(),
                                this->image.height(),
                                GU_RGB,
                                (edk::classID)this->image.getPixels(),
                                filter
                                );edkEnd();
            break;
        case 4u://RGBA
            //load the texture
            this->createTexture(this->image.width(),
                                this->image.height(),
                                GU_RGBA,
                                (edk::classID)this->image.getPixels(),
                                filter
                                );edkEnd();
            break;
        }

        //test if create the texture
        if(this->getID()){
            //set the textureName
            this->setName( this->image.getFileName() );edkEnd();

            //return true
            ret = true;edkEnd();
        }
        //delete the image
        this->image.deleteImage();edkEnd();
    }
    //return true or false
    return ret;
}
bool edk::Texture2DFile::loadFromFile(const char *fileName,edk::uint32 filter){
    //
    return this->loadFromFile((edk::char8 *)fileName,filter);edkEnd();
}
//LOAD from memory
bool edk::Texture2DFile::loadFromMemory(edk::uint8* image,edk::uint32 size,edk::uint32 filter){
    //return
    bool ret=false;edkEnd();
    //delete the last texture
    this->deleteTexture();edkEnd();
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
                                    (edk::classID)this->image.getPixels(),
                                    filter
                                    );edkEnd();
                break;
            case 3u://RGB
                //load the texture
                this->createTexture(this->image.width(),
                                    this->image.height(),
                                    GU_RGB,
                                    (edk::classID)this->image.getPixels(),
                                    filter
                                    );edkEnd();
                break;
            case 4u://RGBA
                //load the texture
                this->createTexture(this->image.width(),
                                    this->image.height(),
                                    GU_RGBA,
                                    (edk::classID)this->image.getPixels(),
                                    filter
                                    );edkEnd();
                break;
            }

            //test if create the texture
            if(this->getID()){
                //set the textureName
                this->setName( this->image.getFileName() );edkEnd();

                //return true
                ret = true;edkEnd();
            }
            //delete the image
            this->image.deleteImage();edkEnd();
        }
    }
    return ret;
}
//SERT from memory
bool edk::Texture2DFile::setFromMemory(edk::uint8* image,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 filter){
    //return
    bool ret=false;edkEnd();
    //delete the last texture
    this->deleteTexture();edkEnd();
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
                                    (edk::classID)image,
                                    filter
                                    );edkEnd();
                break;
            case 3u://RGB
                //load the texture
                this->createTexture(width,
                                    height,
                                    GU_RGB,
                                    (edk::classID)image,
                                    filter
                                    );edkEnd();
                break;
            case 4u://RGBA
                //load the texture
                this->createTexture(width,
                                    height,
                                    GU_RGBA,
                                    (edk::classID)image,
                                    filter
                                    );edkEnd();
                break;
            }

            //test if create the texture
            if(this->getID()){
                //set the textureName
                this->setName( "" );edkEnd();

                //return true
                ret = true;edkEnd();
            }
            //delete the image
            this->image.deleteImage();edkEnd();
    }
    return ret;
}
