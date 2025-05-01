#ifndef FONTSET_H
#define FONTSET_H

/*
Library FontSet - Tile Set for Font Images
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
#pragma message "Inside FontSet"
#endif

#pragma once
#include "../tiles/TileSet2D.h"
#include "../NameClass.h"

#include "../pack/FilePackage.h"

#ifdef printMessages
#pragma message "    Compiling FontSet"
#endif

namespace edk{
namespace fonts{
class FontSet{
public:
    FontSet(edk::uint32 filter = 0u);
    virtual ~FontSet();

    void Constructor(edk::uint32 filter = 0u);
    void Destructor();

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
private:
    edk::classID classThis;
};

//list of FontSet's
class fontSetList{
public:
    fontSetList();
    virtual ~fontSetList();

    void Constructor();
    void Destructor();
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
        virtual ~FontRetain();

        void Constructor(edk::uint32 filter = 0u);
        void Destructor();

        edk::fonts::FontSet set;
        //retain release
        void retain();
        bool release();
        //test if have no retains
        bool haveNoRetains();
    private:
        edk::uint64 retains;
    private:
        edk::classID classThis;
    };

    class TreeFont:public edk::vector::BinaryTree<edk::fonts::fontSetList::FontRetain*>{
    public:
        TreeFont(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~TreeFont(){
            this->Destructor();
        }

        void Constructor(){
            if(this->classThis!=this){
                this->classThis=this;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
            }
        }

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
    private:
        edk::classID classThis;
    };

    //treeFonts
    static edk::fonts::fontSetList::TreeFont tree;
    static bool templateConstructNeed;
private:
    edk::classID classThis;
};

}//end namespace fonts
}//end namespace edk

#endif // FONTSET_H
