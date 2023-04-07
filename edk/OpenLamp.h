#ifndef OPENLAMP_H
#define OPENLAMP_H

/*
Library C++ OpenLamp - Core functions to the openLamp software to change luminance image to normalMap
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
#pragma message "Inside OpenLamp"
#endif

#pragma once
#include "TypeColor.h"
#include "Image2D.h"
#include "Math.h"

#ifdef printMessages
#pragma message "    Compiling OpenLamp"
#endif

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
