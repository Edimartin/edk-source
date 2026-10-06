#include "RetroImageConverter.h"

/*
Library RetroImageConverter - Retro class to convert images using EDK
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
#pragma message "            Inside RetroImageConverter.cpp"
#endif

#define LINE_WIDTH_SET 16u
#define LINE_WIDTH_MAP 8u

edk::RetroImageConverter::RetroImageConverter(){
    this->classThis = this;
    this->Constructor();
}
edk::RetroImageConverter::~RetroImageConverter(){
    this->Destructor();
}
void edk::RetroImageConverter::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::RetroImageConverter::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
    }
}
edk::uint8 edk::RetroImageConverter::rgb8ToSMSRound(edk::uint8 r, edk::uint8 g, edk::uint8 b){
    edk::uint8 r_2bit = (edk::uint8)round(r / 85.0);
    edk::uint8 g_2bit = (edk::uint8)round(g / 85.0);
    edk::uint8 b_2bit = (edk::uint8)round(b / 85.0);
    return (b_2bit << 4) | (g_2bit << 2) | r_2bit;
}
edk::uint8 edk::RetroImageConverter::rgb8ToSMSRound(edk::color3ui8 color){
    edk::uint8 r_2bit = (edk::uint8)round(color.r / 85.0);
    edk::uint8 g_2bit = (edk::uint8)round(color.g / 85.0);
    edk::uint8 b_2bit = (edk::uint8)round(color.b / 85.0);
    return (b_2bit << 4) | (g_2bit << 2) | r_2bit;
}
edk::uint8 edk::RetroImageConverter::rgb8ToSMSRound(edk::color4ui8 color){
    edk::uint8 r_2bit = (edk::uint8)round(color.r / 85.0);
    edk::uint8 g_2bit = (edk::uint8)round(color.g / 85.0);
    edk::uint8 b_2bit = (edk::uint8)round(color.b / 85.0);
    return (b_2bit << 4) | (g_2bit << 2) | r_2bit;
}
edk::uint8 edk::RetroImageConverter::rgb8ToSMSFast(edk::uint8 r, edk::uint8 g, edk::uint8 b){
    edk::uint8 r_2bit = r >> 6;
    edk::uint8 g_2bit = g >> 6;
    edk::uint8 b_2bit = b >> 6;
    return (b_2bit << 4) | (g_2bit << 2) | r_2bit;
}
edk::uint8 edk::RetroImageConverter::rgb8ToSMSFast(edk::color3ui8 color){
    edk::uint8 r_2bit = color.r >> 6;
    edk::uint8 g_2bit = color.g >> 6;
    edk::uint8 b_2bit = color.b >> 6;
    return (b_2bit << 4) | (g_2bit << 2) | r_2bit;
}
edk::uint8 edk::RetroImageConverter::rgb8ToSMSFast(edk::color4ui8 color){
    edk::uint8 r_2bit = color.r >> 6;
    edk::uint8 g_2bit = color.g >> 6;
    edk::uint8 b_2bit = color.b >> 6;
    return (b_2bit << 4) | (g_2bit << 2) | r_2bit;
}

//convert retroIMG to sms
//H
edk::MemoryBuffer<edk::char8>* edk::RetroImageConverter::retroIMGtoCodeH_SMS(edk::char8* name,
                                                                             edk::retro::RetroPalette* palette,
                                                                             edk::retro::RetroTileSet* set,
                                                                             edk::retro::RetroTileMap* map
                                                                             ){
    if(palette && set && map && name){
        //
        edk::uint8 counterLine=0u;
        edk::retro::RetroTile tile;
        edk::uint8 value8=0u;
        edk::uint32 value32=0u;
        edk::color4ui8 color;
        edk::uint32 size=0u;
        edk::char8 str[1024u];
        edk::MemoryBuffer<edk::char8>* buffer = new edk::MemoryBuffer<edk::char8>;
        edk::uint32 width =0u;
        edk::uint32 height=0u;
        edk::uint32 sizePalette,sizeSet,sizeMap;
        edk::uint8 planes[4u];
        if(buffer){
            sizePalette = size = palette->getSize();
            if(size){
                buffer->pushToBuffer("extern const unsigned char ");
                buffer->pushToBuffer(name);
                buffer->pushToBuffer("_palette[");
                sprintf(str,"%u",size);
                buffer->pushToBuffer(str);
                buffer->pushToBuffer("]={\n");
                for(edk::uint32 i=0u;i<size;i++){
                    color = palette->getColor4ui8(i);
                    value8 = edk::RetroImageConverter::rgb8ToSMSRound(color);
                    sprintf(str,"0x%02x",value8);
                    buffer->pushToBuffer(str);
                    if(i<size-1u){
                        buffer->pushToBuffer(",");
                    }
                }
                buffer->pushToBuffer("};");
            }
            //
            sizeSet = size = set->size();
            if(size){
                buffer->pushToBuffer("\nextern const unsigned char ");
                buffer->pushToBuffer(name);
                buffer->pushToBuffer("_tileSet[");
                sizeSet*=32u;
                sprintf(str,"%u",sizeSet);
                buffer->pushToBuffer(str);
                buffer->pushToBuffer("]={\n");
                counterLine = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    tile = set->get(i);
                    for(edk::uint32 y=0u;y<8u;y++){
                        //clean the planes
                        for(edk::uint32 j=0u;j<4u;j++){
                            planes[0] = 0u;
                            planes[1] = 0u;
                            planes[2] = 0u;
                            planes[3] = 0u;
                        }
                        for(edk::uint32 x=0u;x<8u;x++){
                            value8 = tile.getPixel(x, y) & 0x0F;

                            planes[0] |= ((value8 >> 0) & 1) << (7 - x);
                            planes[1] |= ((value8 >> 1) & 1) << (7 - x);
                            planes[2] |= ((value8 >> 2) & 1) << (7 - x);
                            planes[3] |= ((value8 >> 3) & 1) << (7 - x);
                        }
                        for(edk::uint32 j=0u;j<4u;j++){
                            sprintf(str,"0x%02x",planes[j]);
                            buffer->pushToBuffer(str);
                            if(i<size-1u
                                    ||
                                    y<7u
                                    ||
                                    j<3u
                                    ){
                                buffer->pushToBuffer(",");
                            }
                            counterLine++;
                            if(counterLine>=LINE_WIDTH_SET){
                                buffer->pushToBuffer("\n");
                                counterLine=0u;
                            }
                        }
                    }
                }
                buffer->pushToBuffer("};");
            }
            //
            width=map->getWidth();
            height=map->getHeight();
            if(width && height){
                sizeMap = width*height;
                buffer->pushToBuffer("\nextern const unsigned int ");
                buffer->pushToBuffer(name);
                buffer->pushToBuffer("_tileMap[");
                sprintf(str,"%u",width*height);
                buffer->pushToBuffer(str);
                buffer->pushToBuffer("]={\n");
                counterLine = 0u;
                for(edk::uint32 y=0u;y<height;y++){
                    for(edk::uint32 x=0u;x<width;x++){
                        value32 = map->getValueSMS(x,y);
                        sprintf(str,"0x%04x",value32);
                        buffer->pushToBuffer(str);
                        if(y<height-1u || x<width-1u){
                            buffer->pushToBuffer(",");
                        }
                        counterLine++;
                        if(counterLine>=LINE_WIDTH_MAP){
                            buffer->pushToBuffer("\n");
                            counterLine=0u;
                        }
                    }
                }
                buffer->pushToBuffer("};");
            }
            //DEFINES
            //PALETTE
            buffer->pushToBuffer("\n#define sizePalette_");
            buffer->pushToBuffer(name);
            buffer->pushToBuffer(" ");
            sprintf(str,"%u",sizePalette);
            buffer->pushToBuffer(str);
            //SET
            buffer->pushToBuffer("\n#define sizeTileSet_");
            buffer->pushToBuffer(name);
            buffer->pushToBuffer(" ");
            sprintf(str,"%u",sizeSet);
            buffer->pushToBuffer(str);
            //MAP
            buffer->pushToBuffer("\n#define sizeTileMap_");
            buffer->pushToBuffer(name);
            buffer->pushToBuffer(" ");
            sprintf(str,"%u",sizeMap);
            buffer->pushToBuffer(str);
        }
        return buffer;
    }
    return NULL;
}
bool edk::RetroImageConverter::retroIMGtoCodeFileH_SMS(const edk::char8* fileName,
                                                       edk::retro::RetroPalette* palette,
                                                       edk::retro::RetroTileSet* set,
                                                       edk::retro::RetroTileMap* map
                                                       ){
    return edk::RetroImageConverter::retroIMGtoCodeFileH_SMS((edk::char8*) fileName,
                                                             palette,
                                                             set,
                                                             map
                                                             );
}
bool edk::RetroImageConverter::retroIMGtoCodeFileH_SMS(edk::char8* fileName,
                                                       edk::retro::RetroPalette* palette,
                                                       edk::retro::RetroTileSet* set,
                                                       edk::retro::RetroTileMap* map
                                                       ){
    //create the file
    edk::File file;
    if(file.createAndOpenBinFile(fileName)){
        bool ret = false;
        //
        edk::char8* name = edk::String::strFileNameNoExtension(fileName);
        if(name){
            edk::MemoryBuffer<edk::char8>* buffer = edk::RetroImageConverter::retroIMGtoCodeH_SMS(name,
                                                                                                  palette,
                                                                                                  set,
                                                                                                  map
                                                                                                  );
            if(buffer){
                //
                //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
                //printf("buffer == '%s'",buffer->getPointerStr());fflush(stdout);
                file.writeText(buffer->getPointerStr());
                ret=true;
            }
            free(name);
        }
        file.flush();
        return ret;
    }
    return false;
}
//CPP
edk::MemoryBuffer<edk::char8>* edk::RetroImageConverter::retroIMGtoHeaderH_SMS(edk::char8* name,
                                                                               edk::retro::RetroPalette* palette,
                                                                               edk::retro::RetroTileSet* set,
                                                                               edk::retro::RetroTileMap* map
                                                                               ){
    if(palette && set && map && name){
        //
        edk::uint32 size=0u;
        edk::char8 str[1024u];
        edk::MemoryBuffer<edk::char8>* buffer = new edk::MemoryBuffer<edk::char8>;
        edk::uint32 width =0u;
        edk::uint32 height=0u;
        edk::uint32 sizePalette,sizeSet,sizeMap;
        if(buffer){
            sizePalette = size = palette->getSize();
            if(size){
                buffer->pushToBuffer("extern const unsigned char ");
                buffer->pushToBuffer(name);
                buffer->pushToBuffer("_palette[");
                sprintf(str,"%u",size);
                buffer->pushToBuffer(str);
                buffer->pushToBuffer("];");
            }
            //
            sizeSet = size = set->size();
            if(size){
                buffer->pushToBuffer("\nextern const unsigned char ");
                buffer->pushToBuffer(name);
                buffer->pushToBuffer("_tileSet[");
                sizeSet*=32u;
                sprintf(str,"%u",sizeSet);
                buffer->pushToBuffer(str);
                buffer->pushToBuffer("];");
            }
            //
            width=map->getWidth();
            height=map->getHeight();
            if(width && height){
                sizeMap = width*height;
                buffer->pushToBuffer("\nextern const unsigned int ");
                buffer->pushToBuffer(name);
                buffer->pushToBuffer("_tileMap[");
                sprintf(str,"%u",width*height);
                buffer->pushToBuffer(str);
                buffer->pushToBuffer("];");
            }
            //DEFINES
            //PALETTE
            buffer->pushToBuffer("\n#define sizePalette_");
            buffer->pushToBuffer(name);
            buffer->pushToBuffer(" ");
            sprintf(str,"%u",sizePalette);
            buffer->pushToBuffer(str);
            //SET
            buffer->pushToBuffer("\n#define sizeTileSet_");
            buffer->pushToBuffer(name);
            buffer->pushToBuffer(" ");
            sprintf(str,"%u",sizeSet);
            buffer->pushToBuffer(str);
            //MAP
            buffer->pushToBuffer("\n#define sizeTileMap_");
            buffer->pushToBuffer(name);
            buffer->pushToBuffer(" ");
            sprintf(str,"%u",sizeMap);
            buffer->pushToBuffer(str);
        }
        return buffer;
    }
    return NULL;
}
edk::MemoryBuffer<edk::char8>* edk::RetroImageConverter::retroIMGtoCodeCPP_SMS(edk::char8* name,
                                                                               edk::retro::RetroPalette* palette,
                                                                               edk::retro::RetroTileSet* set,
                                                                               edk::retro::RetroTileMap* map
                                                                               ){
    if(palette && set && map && name){
        //
        edk::uint8 counterLine=0u;
        edk::retro::RetroTile tile;
        edk::uint8 value8=0u;
        edk::uint32 value32=0u;
        edk::color4ui8 color;
        edk::uint32 size=0u;
        edk::char8 str[1024u];
        edk::MemoryBuffer<edk::char8>* buffer = new edk::MemoryBuffer<edk::char8>;
        edk::uint32 width =0u;
        edk::uint32 height=0u;
        edk::uint32 sizeSet;
        edk::uint8 planes[4u];

        if(buffer){
            size = palette->getSize();
            if(size){
                buffer->pushToBuffer("const unsigned char ");
                buffer->pushToBuffer(name);
                buffer->pushToBuffer("_palette[");
                sprintf(str,"%u",size);
                buffer->pushToBuffer(str);
                buffer->pushToBuffer("]={\n");
                for(edk::uint32 i=0u;i<size;i++){
                    color = palette->getColor4ui8(i);
                    value8 = edk::RetroImageConverter::rgb8ToSMSRound(color);
                    sprintf(str,"0x%02x",value8);
                    buffer->pushToBuffer(str);
                    if(i<size-1u){
                        buffer->pushToBuffer(",");
                    }
                }
                buffer->pushToBuffer("};");
            }
            //
            sizeSet = size = set->size();
            if(size){
                buffer->pushToBuffer("\nconst unsigned char ");
                buffer->pushToBuffer(name);
                buffer->pushToBuffer("_tileSet[");
                sizeSet*=32u;
                sprintf(str,"%u",sizeSet);
                buffer->pushToBuffer(str);
                buffer->pushToBuffer("]={\n");
                counterLine = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    tile = set->get(i);
                    for(edk::uint32 y=0u;y<8u;y++){
                        //clean the planes
                        for(edk::uint32 j=0u;j<4u;j++){
                            planes[0] = 0u;
                            planes[1] = 0u;
                            planes[2] = 0u;
                            planes[3] = 0u;
                        }
                        for(edk::uint32 x=0u;x<8u;x++){
                            value8 = tile.getPixel(x, y) & 0x0F;

                            planes[0] |= ((value8 >> 0) & 1) << (7 - x);
                            planes[1] |= ((value8 >> 1) & 1) << (7 - x);
                            planes[2] |= ((value8 >> 2) & 1) << (7 - x);
                            planes[3] |= ((value8 >> 3) & 1) << (7 - x);
                        }
                        for(edk::uint32 j=0u;j<4u;j++){
                            sprintf(str,"0x%02x",planes[j]);
                            buffer->pushToBuffer(str);
                            if(i<size-1u
                                    ||
                                    y<7u
                                    ||
                                    j<3u
                                    ){
                                buffer->pushToBuffer(",");
                            }
                            counterLine++;
                            if(counterLine>=LINE_WIDTH_SET){
                                buffer->pushToBuffer("\n");
                                counterLine=0u;
                            }
                        }
                    }
                }
                buffer->pushToBuffer("};");
            }
            //
            width=map->getWidth();
            height=map->getHeight();
            if(width && height){
                buffer->pushToBuffer("\nconst unsigned int ");
                buffer->pushToBuffer(name);
                buffer->pushToBuffer("_tileMap[");
                sprintf(str,"%u",width*height);
                buffer->pushToBuffer(str);
                buffer->pushToBuffer("]={\n");
                counterLine = 0u;
                for(edk::uint32 y=0u;y<height;y++){
                    for(edk::uint32 x=0u;x<width;x++){
                        value32 = map->getValueSMS(x,y);
                        sprintf(str,"0x%04x",value32);
                        buffer->pushToBuffer(str);
                        if(y<height-1u || x<width-1u){
                            buffer->pushToBuffer(",");
                        }
                        counterLine++;
                        if(counterLine>=LINE_WIDTH_MAP){
                            buffer->pushToBuffer("\n");
                            counterLine=0u;
                        }
                    }
                }
                buffer->pushToBuffer("};");
            }
        }
        return buffer;
    }
    return NULL;
}
bool edk::RetroImageConverter::retroIMGtoCodeFileCPP_SMS(const edk::char8* fileNameH,
                                                         const edk::char8* fileNameCPP,
                                                         edk::retro::RetroPalette* palette,
                                                         edk::retro::RetroTileSet* set,
                                                         edk::retro::RetroTileMap* map
                                                         ){
    return edk::RetroImageConverter::retroIMGtoCodeFileCPP_SMS((edk::char8*) fileNameH,
                                                               (edk::char8*) fileNameCPP,
                                                               palette,
                                                               set,
                                                               map
                                                               );
}
bool edk::RetroImageConverter::retroIMGtoCodeFileCPP_SMS(edk::char8* fileNameH,
                                                         edk::char8* fileNameCPP,
                                                         edk::retro::RetroPalette* palette,
                                                         edk::retro::RetroTileSet* set,
                                                         edk::retro::RetroTileMap* map
                                                         ){
    //create the file
    edk::File fileH;
    edk::File fileCPP;
    if(fileH.createAndOpenBinFile(fileNameH)){
        bool ret = false;
        //
        edk::char8* name = edk::String::strFileNameNoExtension(fileNameH);
        if(name){
            if(fileCPP.createAndOpenBinFile(fileNameCPP)){
                edk::MemoryBuffer<edk::char8>* buffer = edk::RetroImageConverter::retroIMGtoHeaderH_SMS(name,
                                                                                                        palette,
                                                                                                        set,
                                                                                                        map
                                                                                                        );
                if(buffer){
                    //
                    //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
                    //printf("buffer == '%s'",buffer->getPointerStr());fflush(stdout);
                    fileH.writeText(buffer->getPointerStr());
                    ret=true;
                }
                buffer = edk::RetroImageConverter::retroIMGtoCodeCPP_SMS(name,
                                                                         palette,
                                                                         set,
                                                                         map
                                                                         );
                if(buffer){
                    //
                    //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
                    //printf("buffer == '%s'",buffer->getPointerStr());fflush(stdout);
                    fileCPP.writeText(buffer->getPointerStr());
                    ret=true;
                }
                free(name);
                fileCPP.flush();
                fileCPP.closeFile();
            }
        }
        fileH.flush();
        fileCPP.closeFile();
        return ret;
    }
    return false;
}
