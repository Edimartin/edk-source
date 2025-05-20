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

#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
bool edk::Texture2DFile::templateConstructNeed=true;
edk::DebugLineFile edk::Texture2DFile::debugFile;
edk::multi::Mutex edk::Texture2DFile::debugMut;
#endif

edk::Texture2DFile::Texture2DFile(){
    this->classThis=NULL;
    this->Constructor();
}
edk::Texture2DFile::Texture2DFile(edk::char8 *textureFileName){
    this->classThis=NULL;
    this->Constructor(textureFileName);
}
edk::Texture2DFile::Texture2DFile(const char *textureFileName){
    this->classThis=NULL;
    this->Constructor(textureFileName);
}

edk::Texture2DFile::~Texture2DFile(){
    this->Destructor();
}

void edk::Texture2DFile::Constructor(){
    edk::Texture2D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->image.Constructor();

#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
        if(edk::Texture2DFile::templateConstructNeed){
            edk::Texture2DFile::debugFile.Constructor();
            edk::Texture2DFile::debugMut.Constructor();
            edk::Texture2DFile::templateConstructNeed=false;
        }
#endif
        //ctor
    }
}
void edk::Texture2DFile::Constructor(edk::char8 *textureFileName){
    edk::Texture2D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->image.Constructor();

#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
        if(edk::Texture2DFile::templateConstructNeed){
            edk::Texture2DFile::debugFile.Constructor();
            edk::Texture2DFile::debugMut.Constructor();
            edk::Texture2DFile::templateConstructNeed=false;
        }
#endif
        //
        this->setName(textureFileName);
    }
}
void edk::Texture2DFile::Constructor(const char *textureFileName){
    edk::Texture2D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->image.Constructor();
/*
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
        if(edk::Texture2DFile::templateConstructNeed){
            edk::Texture2DFile::debugFile.Constructor();
            edk::Texture2DFile::debugMut.Constructor();
            edk::Texture2DFile::templateConstructNeed=false;
        }
#endif
*/
        //
        this->setName(textureFileName);
    }
}
void edk::Texture2DFile::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->deleteTexture();
        this->deleteName();
        //remove all
        this->removeAll();

        this->image.Destructor();
/*
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
        edk::Texture2DFile::debugFile.Destructor();
        edk::Texture2DFile::debugMut.Destructor();
#endif
*/
    }
    edk::Texture2D::Destructor();
}

//set the debugFile Name
bool edk::Texture2DFile::createDebugFile(const edk::char8* name){
    return edk::Texture2DFile::createDebugFile((edk::char8*) name);
}
bool edk::Texture2DFile::createDebugFile(edk::char8* name){
    if(name){
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
        bool ret=false;
        edk::Texture2DFile::debugMut.lock();
        edk::Texture2DFile::debugFile.closeFile();
        ret = edk::Texture2DFile::debugFile.createFile(name);
        edk::Texture2DFile::debugMut.unlock();
        return ret;
#else
        return true;
#endif
    }
    return false;
}
//close the debug file to not write the file
void edk::Texture2DFile::closeDebugFile(){
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
    edk::Texture2DFile::debugMut.lock();
    edk::Texture2DFile::debugFile.closeFile();
    edk::Texture2DFile::debugMut.unlock();
#endif
}


//LOAD
bool edk::Texture2DFile::loadFromFile(edk::char8 *fileName,edk::uint32 minFilter,edk::uint32 magFilter){
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
    this->writeDebug(fileName?fileName:"FILENAME_NULL",__LINE__,__FILE__,__func__);
#endif
    //return
    bool ret=false;
    //delete the last texture
    this->deleteTexture();
    //first open the image
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
    edk::char8* str = edk::String::strCatMulti("loadFromFileToRGBA(",fileName?fileName:"FILENAME_NULL",")",NULL);
    if(str){
        this->writeDebug(fileName?fileName:"FILENAME NULL",__LINE__,__FILE__,__func__);
        free(str);
    }
#endif
    if(this->image.loadFromFileToRGBA(fileName)){
        //test the channels
        switch(this->image.getChannels()){
        case 1u://GRAYSCALE
            //load the texture
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
            this->writeDebug("createTexture(GRAYSCALE)",__LINE__,__FILE__,__func__);
#endif
            this->createTexture(this->image.width(),
                                this->image.height(),
                                GU_LUMINANCE,
                                (edk::classID)this->image.getPixels(),
                                minFilter,
                                magFilter
                                );
            break;
        case 3u://RGB
            //load the texture
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
            this->writeDebug("createTexture(RGB)",__LINE__,__FILE__,__func__);
#endif
            this->createTexture(this->image.width(),
                                this->image.height(),
                                GU_RGB,
                                (edk::classID)this->image.getPixels(),
                                minFilter,
                                magFilter
                                );
            break;
        case 4u://RGBA
            //load the texture
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
            this->writeDebug("createTexture(RGBA)",__LINE__,__FILE__,__func__);
#endif
            this->createTexture(this->image.width(),
                                this->image.height(),
                                GU_RGBA,
                                (edk::classID)this->image.getPixels(),
                                minFilter,
                                magFilter
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
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
    this->writeDebug(ret?"RETURN TRUE":"RETURN FALSE",__LINE__,__FILE__,__func__);
#endif
    return ret;
}
bool edk::Texture2DFile::loadFromFile(const char *fileName,edk::uint32 minFilter,edk::uint32 magFilter){
    //
    return this->loadFromFile((edk::char8 *)fileName,minFilter,magFilter);
}
//LOAD from memory
bool edk::Texture2DFile::loadFromMemory(edk::uint8* image,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
    edk::char8* strSize = edk::String::uint32ToStr(size);
    if(strSize){
        edk::char8* str = edk::String::strCatMulti("Size[",strSize,"]",NULL);
        if(str){
            this->writeDebug(str,__LINE__,__FILE__,__func__);
            free(str);
        }
        free(strSize);
    }
#endif
    //return
    bool ret=false;
    //delete the last texture
    this->deleteTexture();
    //test the image
    if(image && size){
        //process the decode
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
        edk::char8* strSize = edk::String::uint32ToStr(size);
        if(strSize){
            edk::char8* str = edk::String::strCatMulti("loadFromMemoryToRGBA(Size[",strSize,"])",NULL);
            if(str){
                this->writeDebug(str,__LINE__,__FILE__,__func__);
                free(str);
            }
            free(strSize);
        }
#endif
        if(this->image.loadFromMemoryToRGBA(image,size)){
            //test the channels
            switch(this->image.getChannels()){
            case 1u://GRAYSCALE
            {
                //load the texture
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
                this->writeDebug("createTexture(GRAYSCALE)",__LINE__,__FILE__,__func__);
#endif
                this->createTexture(this->image.width(),
                                    this->image.height(),
                                    GU_LUMINANCE,
                                    (edk::classID)this->image.getPixels(),
                                    minFilter,
                                    magFilter
                                    );
            }
                break;
            case 3u://RGB
            {
                //load the texture
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
                this->writeDebug("createTexture(RGB)",__LINE__,__FILE__,__func__);
#endif
                this->createTexture(this->image.width(),
                                    this->image.height(),
                                    GU_RGB,
                                    (edk::classID)this->image.getPixels(),
                                    minFilter,
                                    magFilter
                                    );
            }
                break;
            case 4u://RGBA
            {
                //load the texture
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
                this->writeDebug("createTexture(RGBA)",__LINE__,__FILE__,__func__);
#endif
                this->createTexture(this->image.width(),
                                    this->image.height(),
                                    GU_RGBA,
                                    (edk::classID)this->image.getPixels(),
                                    minFilter,
                                    magFilter
                                    );
            }
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
    //return true or false
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
    this->writeDebug(ret?"RETURN TRUE":"RETURN FALSE",__LINE__,__FILE__,__func__);
#endif
    return ret;
}
//SERT from memory
bool edk::Texture2DFile::setFromMemory(edk::uint8* image,
                                       edk::uint32 width,
                                       edk::uint32 height,
                                       edk::uint32 channels,
                                       edk::uint32 minFilter,
                                       edk::uint32 magFilter
                            ){
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
    edk::char8* strWidth = edk::String::uint32ToStr(width);
    if(strWidth){
        edk::char8* strHeight = edk::String::uint32ToStr(height);
        if(strHeight){
            edk::char8* strChannels = edk::String::uint32ToStr(channels);
            if(strChannels){
                edk::char8* str = edk::String::strCatMulti("Size[",strWidth,",",strWidth,"] channels[",strChannels,"]",NULL);
                if(str){
                    this->writeDebug(str,__LINE__,__FILE__,__func__);
                    free(str);
                }
                free(strChannels);
            }
            free(strHeight);
        }
        free(strWidth);
    }
#endif
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
        {
            //load the texture
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
            edk::char8* strWidth = edk::String::uint32ToStr(width);
            if(strWidth){
                edk::char8* strHeight = edk::String::uint32ToStr(height);
                if(strHeight){
                    edk::char8* strChannels = edk::String::uint32ToStr(channels);
                    if(strChannels){
                        edk::char8* str = edk::String::strCatMulti("createTexture(GRAYSCALE,Size[",strWidth,",",strWidth,"] channels[",strChannels,"])",NULL);
                        if(str){
                            this->writeDebug(str,__LINE__,__FILE__,__func__);
                            free(str);
                        }
                        free(strChannels);
                    }
                    free(strHeight);
                }
                free(strWidth);
            }
#endif
            this->createTexture(width,
                                height,
                                GU_LUMINANCE,
                                (edk::classID)image,
                                minFilter,
                                magFilter
                                );
        }
            break;
        case 3u://RGB
        {
            //load the texture
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
            edk::char8* strWidth = edk::String::uint32ToStr(width);
            if(strWidth){
                edk::char8* strHeight = edk::String::uint32ToStr(height);
                if(strHeight){
                    edk::char8* strChannels = edk::String::uint32ToStr(channels);
                    if(strChannels){
                        edk::char8* str = edk::String::strCatMulti("createTexture(RGB,Size[",strWidth,",",strWidth,"] channels[",strChannels,"])",NULL);
                        if(str){
                            this->writeDebug(str,__LINE__,__FILE__,__func__);
                            free(str);
                        }
                        free(strChannels);
                    }
                    free(strHeight);
                }
                free(strWidth);
            }
#endif
            this->createTexture(width,
                                height,
                                GU_RGB,
                                (edk::classID)image,
                                minFilter,
                                magFilter
                                );
        }
            break;
        case 4u://RGBA
        {
            //load the texture
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
            edk::char8* strWidth = edk::String::uint32ToStr(width);
            if(strWidth){
                edk::char8* strHeight = edk::String::uint32ToStr(height);
                if(strHeight){
                    edk::char8* strChannels = edk::String::uint32ToStr(channels);
                    if(strChannels){
                        edk::char8* str = edk::String::strCatMulti("createTexture(RGBA,Size[",strWidth,",",strWidth,"] channels[",strChannels,"])",NULL);
                        if(str){
                            this->writeDebug(str,__LINE__,__FILE__,__func__);
                            free(str);
                        }
                        free(strChannels);
                    }
                    free(strHeight);
                }
                free(strWidth);
            }
#endif
            this->createTexture(width,
                                height,
                                GU_RGBA,
                                (edk::classID)image,
                                minFilter,
                                magFilter
                                );
        }
            break;
        }

        //test if create the texture
        if(this->getID()){
            //set the textureName
            this->setName("");

            //return true
            ret = true;
        }
        //delete the image
        this->image.deleteImage();
    }
#if defined(EDK_TEX2DFILE_PRINT_DEBUG)
    this->writeDebug(ret?"RETURN TRUE":"RETURN FALSE",__LINE__,__FILE__,__func__);
#endif
    return ret;
}
