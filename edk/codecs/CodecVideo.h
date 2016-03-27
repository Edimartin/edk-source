#ifndef CODECVIDEO_H
#define CODECVIDEO_H

/*
Library C++ codecs - Set the parameters use for the video codecs
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
#warning "Inside CodecVideo"
#endif

#pragma once
#include "CodecImage.h"

#ifdef printMessages
#warning "    Compiling CodecVideo"
#endif

namespace edk{
namespace codecs{
class CodecVideo : private edk::codecs::CodecImage{
public:
    CodecVideo();
    virtual ~CodecVideo();
protected:
    //create a new frame
    bool newFrame(edk::size2ui32 size,edk::uint8 channels);
    bool newFrame(edk::uint32 width,edk::uint32 height,edk::uint8 channels);
    //create a new frame
    bool newFrameYUV(edk::size2ui32 size);
    bool newFrameYUV(edk::uint32 width,edk::uint32 height);
    //delete the frame
    void deleteFrame();
    //alloc a new frameEncoded
    bool newSpaceEncoded(edk::uint32 size);
    //delete the encoded
    void deleteSpaceEncoded();

    //draw an image in the frame
    bool drawFrame(edk::uint8* frame,edk::uint8 channels);

    //write in the frame encoded
    bool writeEncoded(edk::uint8* frame,edk::uint32 size);
    bool appendEncoded(edk::uint8* frame,edk::uint32 size);

    //set the quality
    bool setQuality(edk::uint32 quality);
    //set the next is keyFrame
    void setNextkeyframe();
    //return true if the next is keyframe
    bool isNextKeyframe();

    //get the frames
    edk::uint8* getFrame();
    edk::uint8* getEncoded();
    edk::uint8** getEncodedPosition();
    edk::uint8* getFrameY();
    edk::uint8* getFrameU();
    edk::uint8* getFrameV();

    //clean the pointers
    edk::uint8* cleanFrame();
    bool cleanYUV(edk::uint8** Y,edk::uint8** U,edk::uint8** V);
    edk::uint8* cleanEncoded();

    //return the size of the frame
    edk::size2ui32 getFrameSize();
    edk::uint32 getFrameWidth();
    edk::uint32 getFrameHeight();
    edk::uint32 getFrameChannels();
    edk::uint32 getFrameVectorSize();
    edk::uint32 getFrameYSize();
    edk::uint32 getFrameUSize();
    edk::uint32 getFrameVSize();
    //return the size of the encoded
    edk::uint32 getSpaceEncodedSize();
    edk::uint32 getEncodedUsedSize();
    edk::uint32 getQuality();
private:
    //YUV channels
    edk::uint8 *Y, *U, *V;
    edk::uint32 sizeY;
    edk::uint32 sizeU;
    edk::uint32 sizeV;
    //set the next keyFrame
    bool nexKeyframe;
    //frame encoded size
    edk::uint32 usingEncodedSize;
};
}//end namespace codecs
}//end namespace edk

#endif // CODECVIDEO_H
