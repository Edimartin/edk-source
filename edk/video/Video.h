#ifndef VIDEO_H
#define VIDEO_H

/*
Library Video - Play video files
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
#pragma message "Inside VideoEDK"
#endif

#pragma once
#include "../watch/Time.h"
#include "../File.h"
#include "../String.h"
#include "../TypeDefines.h"
#include "../pack/FilePackage.h"
#include "../Image2D.h"
#include "../MemoryBuffer.h"
#include "../pack/FilePackage.h"

#ifdef printMessages
#pragma message "    Compiling VideoEDK"
#endif

namespace edk{
enum EdkVideoWrite{
    edkVideoWriteNothing,
    edkVideoWriteTrue,
    edkVideoWriteFalse,

    edkVideoWriteSize
};
class Video{
public:
    Video();
    ~Video();

    void Constructor(bool runFather=true);

    //close the file
    void close();

    //create a file
    bool newFile(const edk::char8* name,edk::float32 seconds,edk::float32 fps);
    bool newFile(edk::char8* name,edk::float32 seconds,edk::float32 fps);

    //open a file
    bool openFile(const edk::char8* name);
    bool openFile(edk::char8* name);

    //return true if have the file opened
    bool haveFile();

    inline edk::float32 getSecondLenght(){
        return this->seconds;
    }
    inline edk::size2ui32 getSize(){
        return this->size;
    }
    inline edk::uint32 getWidth(){
        return this->size.width;
    }
    inline edk::uint32 getHeight(){
        return this->size.height;
    }
    inline edk::uint8 getChannels(){
        return this->channels;
    }
    inline edk::float32 getFPS(){
        if(this->frames>0.f){
            return this->seconds / this->frames;
        }
        return 0.f;
    }
    edk::uint8* getFrameVector();

    //
    bool startWriteFrames(edk::uint32 width,edk::uint32 height,edk::uint32 channels);
    bool startWriteFrames(edk::size2ui32 size,edk::uint32 channels);
    //function tu write an image into the file
    bool writeFrame(edk::uint8* vector,bool keyFrame=false);
    //read frames
    bool startReadFrames();
    bool readNextFrame();
    //get the frame vector
    edk::uint8* getFramePixels();
protected:
    virtual void writeHeader(edk::File* file)=0;
    virtual bool readHeader(edk::File*  file)=0;
    //start the encoder
    virtual bool startEncoder(edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::float32 fps)=0;
    //encode a frame
    virtual bool encodeFrame(edk::uint8* vector,
                             edk::uint64 lenght,
                             edk::uint8 channels,
                             edk::MemoryBuffer<edk::uint8>* bufferWrite,
                             bool keyFrame
                             )=0;
    //finish the encoder
    virtual void finishEncoder()=0;
    //start the decoder
    virtual bool startDecoder()=0;
    //decode a frame
    virtual bool decodeFrame(edk::MemoryBuffer<edk::uint8>* bufferWrite,
                             edk::uint32* width,
                             edk::uint32* height,
                             edk::uint8* channels
                             )=0;
    //decode a frame
    virtual bool copyDecodedFrame(edk::MemoryBuffer<edk::uint8>* bufferDest)=0;
    //finish the decoder
    virtual void finishDecoder()=0;
    //
    inline edk::float32 getTimeIncrement(){
        return this->timeIncrement;
    }
private:
    edk::EdkVideoWrite writingFile;
    edk::File file;
    edk::MemoryBuffer<edk::uint8> buffer;
    edk::watch::Time timeCounter;
    edk::float32 timeIncrement;
    //save the frame size and channels
    edk::size2ui32 size;
    edk::uint8 channels;
    edk::uint32 frames;
    edk::float32 seconds;
private:
    edk::classID classThis;
};
}

#endif // VIDEO_H
