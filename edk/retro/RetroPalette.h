#ifndef RETROPALETTE_H
#define RETROPALETTE_H

#include <stdlib.h>
#include "edk/TypeDefines.h"
#include "edk/TypeVars.h"
#include "edk/TypeColor.h"
#include "edk/DebugFile.h"

namespace edk{
namespace retro{
class RetroPalette{
public:
    RetroPalette();
    ~RetroPalette();

    void Constructor();
    void Destructor();

    bool havePalette();

    void deletePalette();
    inline void cleanPalette(){
        this->deletePalette();
    }

    bool newPalette(edk::uint32 size,edk::uint8 channels,edk::uint8 bytesPerChannel);

    //GETTERS
    edk::uint8* getPalette();
    edk::uint32 getSize();
    edk::uint8 getChannels();
    edk::uint8 getBytesPerChannel();

    //copy palette
    bool setPalette(edk::uint8* palette);
    bool copyPalette(edk::uint8* palette,edk::uint32 size,edk::uint8 channels,edk::uint8 bytesPerChannel);

    //EDIT THE PALETTE
    bool setColor(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a);
    bool setColor(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b);
    bool setColor(edk::uint32 position,edk::uint8 g,edk::uint8 a);
    bool setColor(edk::uint32 position,edk::uint8 g);
    bool setColor(edk::uint32 position,edk::uint16 r,edk::uint16 g,edk::uint16 b,edk::uint16 a);
    bool setColor(edk::uint32 position,edk::uint16 r,edk::uint16 g,edk::uint16 b);
    bool setColor(edk::uint32 position,edk::uint16 g,edk::uint16 a);
    bool setColor(edk::uint32 position,edk::uint16 g);
    //set from colors
    inline bool setColor(edk::uint32 position,edk::color4ui8 color){
        return this->setColor(position,color.r,color.g,color.b,color.a);
    }
    inline bool setColor(edk::uint32 position,edk::color3ui8 color){
        return this->setColor(position,color.r,color.g,color.b);
    }
    inline bool setColor(edk::uint32 position,edk::color2ui8 color){
        return this->setColor(position,color.g,color.a);
    }
    inline bool setColor(edk::uint32 position,edk::color1ui8 color){
        return this->setColor(position,color.g);
    }
    inline bool setColor(edk::uint32 position,edk::color4ui16 color){
        return this->setColor(position,color.r,color.g,color.b,color.a);
    }
    inline bool setColor(edk::uint32 position,edk::color3ui16 color){
        return this->setColor(position,color.r,color.g,color.b);
    }
    inline bool setColor(edk::uint32 position,edk::color2ui16 color){
        return this->setColor(position,color.g,color.a);
    }
    inline bool setColor(edk::uint32 position,edk::color1ui16 color){
        return this->setColor(position,color.g);
    }
    //CHANNELS
    edk::uint8 getColorR8(edk::uint32 position);
    edk::uint8 getColorG8(edk::uint32 position);
    edk::uint8 getColorB8(edk::uint32 position);
    edk::uint8 getColorA8(edk::uint32 position);
    edk::uint16 getColorR16(edk::uint32 position);
    edk::uint16 getColorG16(edk::uint32 position);
    edk::uint16 getColorB16(edk::uint32 position);
    edk::uint16 getColorA16(edk::uint32 position);
    //COLORS
    edk::color1ui8 getColor1ui8(edk::uint32 position);
    edk::color2ui8 getColor2ui8(edk::uint32 position);
    edk::color3ui8 getColor3ui8(edk::uint32 position);
    edk::color4ui8 getColor4ui8(edk::uint32 position);
    edk::color1ui16 getColor1ui16(edk::uint32 position);
    edk::color2ui16 getColor2ui16(edk::uint32 position);
    edk::color3ui16 getColor3ui16(edk::uint32 position);
    edk::color4ui16 getColor4ui16(edk::uint32 position);
private:
    edk::uint8* vec;
    edk::uint32 size;
    edk::uint32 lenght;
    edk::uint8 channels;
    edk::uint8 bytesPerChannel;
private:
    edk::classID classThis;
};
}//end namespace retro
}//end namespace edk

#endif // RETROPALETTE_H
