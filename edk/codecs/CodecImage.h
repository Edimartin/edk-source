#ifndef CODECIMAGE_H
#define CODECIMAGE_H

/*
Library C++ codecs - Set the parameters use for the image codecs
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
#include <string.h>
#include "../TypeVars.h"
#include "../TypeSize2.h"

#include <stdio.h>

namespace edk{
namespace codecs{
class CodecImage{
    public:
        CodecImage();
        virtual ~CodecImage();
    protected:
        //create a new frame
        bool newFrame(edk::size2ui32 size,edk::uint8 channels);
        bool newFrame(edk::uint32 width,edk::uint32 height,edk::uint8 channels);
        //delete the frame
        void deleteFrame();
        //alloc a new frameEncoded
        bool newFrameEncoded(edk::uint32 size);
        //delete the encoded
        void deleteEncoded();

        //draw a image in the frame
        bool drawFrame(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels);
        bool drawFrame(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels);

        //set the quality
        bool setQuality(edk::uint32 quality);

        //get the frames
        edk::uint8* getFrame();
        edk::uint8* getEncoded();
        edk::uint8** getEncodedPosition();

        //clean the pointers
        edk::uint8* cleanFrame();
        edk::uint8* cleanEncoded();

        //return the size of the frame
        edk::size2ui32 getFrameSize();
        edk::uint32 getFrameWidth();
        edk::uint32 getFrameHeight();
        edk::uint32 getFrameChannels();
        edk::uint32 getFrameVectorSize();
        //return the size of the encoded
        edk::uint32 getEncodedSize();
        edk::uint32* getEncodedSizePosition();
        edk::uint32 getQuality();
    private:
        //image vector to encode
        edk::uint8* frame;
        //save the type of the frame
        edk::float32 frameChannels;
        //save the size of the frame
        edk::size2ui32 frameSize;
        edk::uint32 vectorFrameSize;
        //save the frame encoded
        edk::uint8* encoded;
        //size of the frame encoded
        edk::uint32 encodedSize;
        //save the quality of the frame encoded
        edk::uint32 encodedQuality;
};
}//end namespace codecs
}//end namespace edk
#endif // CODECIMAGE_H
