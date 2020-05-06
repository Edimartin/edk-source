#ifndef ENCODERIMAGE_H
#define ENCODERIMAGE_H

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

#ifdef printMessages
#warning "Inside EncoderImage"
#endif

#pragma once
#include "CodecImage.h"
#include "../File.h"

#ifdef printMessages
#warning "    Compiling EncoderImage"
#endif

namespace edk{
namespace codecs{
class EncoderImage : protected edk::codecs::CodecImage{
    public:
        EncoderImage();
        virtual ~EncoderImage();

        //process the encoder
        virtual bool encode(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality);
        virtual bool encode(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality);
        virtual bool encode(const unsigned char* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality);
        virtual bool encode(const unsigned char* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality);

        //process the encoder and save to a file
        bool encodeToFile(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality,const edk::char8* fileName);
        bool encodeToFile(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality,edk::char8* fileName);
        bool encodeToFile(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality,const edk::char8* fileName);
        bool encodeToFile(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality,edk::char8* fileName);
        bool encodeToFile(const unsigned char* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality,const edk::char8* fileName);
        bool encodeToFile(const unsigned char* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality,edk::char8* fileName);
        bool encodeToFile(const unsigned char* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality,const edk::char8* fileName);
        bool encodeToFile(const unsigned char* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality,edk::char8* fileName);

        //return the frame encoded
        edk::uint8* getEncoded();
        edk::uint32 getEncodedSize();
        //delete the encoded
        virtual void deleteEncoded();
    protected:
    private:
        //file manipulator
        edk::File file;
};
}//end namespace codecs
}//end namespace edk

#endif // ENCODERIMAGE_H
