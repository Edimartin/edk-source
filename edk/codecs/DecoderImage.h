#ifndef DECODERIMAGE_H
#define DECODERIMAGE_H

/*
Library C++ codecs - Set the parameters use for the image encoder
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

#pragma once
#include "CodecImage.h"
#include "../File.h"

namespace edk{
namespace codecs{
class DecoderImage : protected edk::codecs::CodecImage{
    public:
        DecoderImage();
        virtual ~DecoderImage();

        //process the decoder
        virtual bool decode(edk::uint8* encoded,edk::uint32 size);
        virtual bool decode(const unsigned char* encoded,edk::uint32 size);

        //decode from file
        bool decodeFromFile(const char* fileName);
        bool decodeFromFile(edk::char8* fileName);

        //Return the frame
        edk::uint8* getFrame();
        edk::size2ui32 getFrameSize();
        edk::uint32 getFrameWidth();
        edk::uint32 getFrameHeight();
        edk::uint32 getFrameChannels();
        //delete the frame
        void deleteFrame();
        //clean the frame
        edk::uint8* cleanFrame();
    protected:
        edk::File file;
    private:
};
}//end namespace codecs
}//end namespace edk

#endif // DECODERIMAGE_H
