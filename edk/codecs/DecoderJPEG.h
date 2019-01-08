#ifndef DECODERJPEG_H
#define DECODERJPEG_H

/*
Library C++ EncoderJPEG - Encode a frame to a JPEG stream or file
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
#warning "Inside DecoderImage"
#endif

#pragma once
#include "DecoderImage.h"
//Use JPEGlib
#include "../../jpeglib/jpeglib.h"

#ifdef printMessages
#warning "    Compiling DecoderImage"
#endif

namespace edk{
namespace codecs{
class DecoderJPEG : public edk::codecs::DecoderImage{
    public:
        DecoderJPEG();
        virtual ~DecoderJPEG();

        //process the decoder
        bool decode(edk::uint8* encoded,edk::uint32 size);
        bool decode(const unsigned char* encoded,edk::uint32 size);

        //return the vector size
        edk::uint32 getVectorSize();
    protected:
    private:
};
}//end namespace codecs
}//end namespace edk

#endif // DECODERJPEG_H
