#ifndef FONTSET_H
#define FONTSET_H

/*
Library FontSet - Tile Set for Font Images
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
#warning "Inside FontSet"
#endif

#pragma once
#include "../tiles/TileSet2D.h"
#include "../NameClass.h"

#include "../pack/FilePackage.h"

#ifdef printMessages
#warning "    Compiling FontSet"
#endif

namespace edk{
namespace fonts{
class FontSet{
public:
    FontSet(edk::uint32 filter = 0u);
    ~FontSet();

    //load the font
    bool loadFontImage(const edk::char8* image,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(0,0,0,1));
    bool loadFontImage(edk::char8* image,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(0,0,0,1));

    bool loadFontImageFromMemory(const edk::char8* name,
                                 edk::uint8* image,
                                 edk::uint32 size,
                                 edk::uint32 filter = GU_NEAREST,
                                 edk::color4f32 color = edk::color4f32(0,0,0,1)
            );
    bool loadFontImageFromMemory(edk::char8* name,
                                 edk::uint8* image,
                                 edk::uint32 size,
                                 edk::uint32 filter = GU_NEAREST,
                                 edk::color4f32 color = edk::color4f32(0,0,0,1)
            );

    bool loadFontImageFromPack(edk::pack::FilePackage* pack,const edk::char8* image,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(0,0,0,1));
    bool loadFontImageFromPack(edk::pack::FilePackage* pack,edk::char8* image,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(0,0,0,1));

    //delete image
    void deleteImage();

    //get the tileset
    edk::tiles::TileSet2D* getTileSet();
    //return the filter
    edk::uint32 getFilter();

    //setName
    bool setName(const edk::char8* name);
    bool setName(edk::char8* name);
    //test the names
    bool nameBiggerThan(const edk::char8* name);
    bool nameBiggerThan(edk::char8* name);
    bool nameEqualThan(const edk::char8* name);
    bool nameEqualThan(edk::char8* name);
    //get the name
    edk::char8* getName();
private:
    edk::tiles::TileSet2D tileSet;
    edk::Name name;
    edk::uint32 filter;
};

//list of FontSet's
class fontSetList{
public:
    fontSetList();
    ~fontSetList();
    //load the fontSet
    edk::fonts::FontSet* createFontSet(edk::char8* image,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(0,0,0,1));
    //load the fontSet
    edk::fonts::FontSet* createFontSetFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(0,0,0,1));
    //load the fontSet
    edk::fonts::FontSet* createFontSetFromPack(edk::pack::FilePackage* pack,edk::char8* image,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(0,0,0,1));
    //remove fontSet
    bool removeFontSetByName(edk::char8* image,edk::uint32 filter = GU_NEAREST);
    //remove fontSet
    bool removeFontSet(edk::fonts::FontSet* set);
    //delete all Fonts
    void deleteAllFonts();

private:

    //retain fonts
    class FontRetain{
    public:
        FontRetain(edk::uint32 filter = 0u);
        ~FontRetain();
        edk::fonts::FontSet set;
        //retain release
        void retain();
        bool release();
        //test if have no retains
        bool haveNoRetains();
    private:
        edk::uint64 retains;
    };

    class TreeFont:public edk::vector::BinaryTree<edk::fonts::fontSetList::FontRetain*>{
    public:
        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::fonts::fontSetList::FontRetain* first,edk::fonts::fontSetList::FontRetain* second);
        virtual bool firstEqualSecond(edk::fonts::fontSetList::FontRetain* first,edk::fonts::fontSetList::FontRetain* second);
        //UPDATE
        virtual void updateElement(edk::fonts::fontSetList::FontRetain* value);

        //load the font
        edk::fonts::FontSet* loadFontImage(edk::char8* image,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(0,0,0,1));
        edk::fonts::FontSet* loadFontImageFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(0,0,0,1));
        edk::fonts::FontSet* loadFontImageFromPack(edk::pack::FilePackage* pack,edk::char8* image,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(0,0,0,1));
        //remove image
        bool removeImage(edk::char8* image,edk::uint32 filter = GU_NEAREST);
        //remove FontSet
        bool removeFontSet(edk::fonts::FontSet* set);
        //delete all fontSet
        void deleteAllFontSet();
    private:
        //getFontSet
        edk::fonts::fontSetList::FontRetain* getFontSetByImage(edk::char8* image,edk::uint32 filter = GU_NEAREST);
    };

    //treeFonts
    static edk::fonts::fontSetList::TreeFont tree;
};

}//end namespace fonts
}//end namespace edk

#endif // FONTSET_H
