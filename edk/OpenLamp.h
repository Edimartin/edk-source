#ifndef OPENLAMP_H
#define OPENLAMP_H

#include "TypeColor.h"
#include "Image2D.h"
#include "Math.h"

namespace edk{
class OpenLamp{
public:
    OpenLamp();

    //convert one pixel
    static edk::color3ui8 pixelToNormal(edk::uint8 up,edk::uint8 down,edk::uint8 left,edk::uint8 right,edk::uint8 front);
    static edk::color3ui8 pixelToNormal(edk::uint8 up,edk::uint8 down,edk::uint8 left,edk::uint8 right);
    //convert the vector
    static bool vectorToNormal(edk::uint8* up,edk::uint8 upChannels,
                               edk::uint8* down,edk::uint8 downChannels,
                               edk::uint8* left,edk::uint8 leftChannels,
                               edk::uint8* right,edk::uint8 rightChannels,
                               edk::uint8* front,edk::uint8 frontChannels,
                               edk::uint8* normal,edk::uint32 pixelsSize
                               );
    static bool imageToNormal(edk::Image2D* up,edk::Image2D* down,edk::Image2D* left,edk::Image2D* right,edk::Image2D* front,edk::Image2D* normal);
};
}//end namespace edk

#endif // OPENLAMP_H
