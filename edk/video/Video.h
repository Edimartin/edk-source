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
#include "../thread/Thread.h"

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
class ThreadVideo;
class Video{
public:
    Video();
    ~Video();

    friend edk::ThreadVideo;

    void Constructor(bool runFather=true);

    //close the file
    void close();

    //create a file

    inline bool newFile(const edk::char8* name,
                        edk::float32 seconds,
                        edk::float32 fps,
                        edk::size2ui32 size,
                        edk::uint32 channels
                        ){
        return this->newFile((edk::char8*) name,
                             seconds,
                             fps,
                             size.width,
                             size.height,
                             channels
                             );
    }
    inline bool newFile(edk::char8* name,
                        edk::float32 seconds,
                        edk::float32 fps,
                        edk::size2ui32 size,
                        edk::uint32 channels
                        ){
        return this->newFile(name,
                             seconds,
                             fps,
                             size.width,
                             size.height,
                             channels
                             );
    }
    inline bool newFile(const edk::char8* name,
                        edk::float32 seconds,
                        edk::float32 fps,
                        edk::uint32 width,
                        edk::uint32 height,
                        edk::uint32 channels
                        ){
        return this->newFile((edk::char8*) name,
                             seconds,
                             fps,
                             width,
                             height,
                             channels
                             );
    }
    bool newFile(edk::char8* name,
                 edk::float32 seconds,
                 edk::float32 fps,
                 edk::uint32 width,
                 edk::uint32 height,
                 edk::uint32 channels
                 );

    //open a file
    inline bool openFile(const edk::char8* name,
                         edk::uint8 threads=1u
            ){
        return this->openFile((edk::char8*) name,
                              threads
                              );
    }
    bool openFile(edk::char8* name,
                  edk::uint8 threads=1u
            );

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

    //function tu write an image into the file
    bool writeFrame(edk::uint8* vector,bool keyFrame=false);
    //read frames
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
    virtual inline bool canDecodeFrame(edk::uint32 /*frameID*/){return true;}
    //decode a frame
    virtual inline bool decodeFrame(edk::MemoryBuffer<edk::uint8>* /*bufferWrite*/,
                                    edk::uint32* /*width*/,
                                    edk::uint32* /*height*/,
                                    edk::uint8* /*channels*/
                                    ){return false;}
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

    edk::uint32 frameID;

    //threads
    edk::vector::Stack<edk::ThreadVideo*> threads;
    edk::vector::Queue<edk::ThreadVideo*> queueEncode;
    edk::vector::Queue<edk::ThreadVideo*> queueDecode;

private:
    edk::classID classThis;
};
class ThreadVideo{
public:
    ThreadVideo(edk::uint32 id,edk::Video* thisVideo){
        this->frameID=0xFFFFFFFF;
        this->id=id;
        this->haveEncoded=false;
        this->haveDecoded=false;
        this->needExit=false;
        this->thisVideo=thisVideo;
        this->canDelete=false;
    }
    ~ThreadVideo(){
    }
    bool canDecodeFrame(){
        return this->thisVideo->canDecodeFrame(this->frameID);
    }

    bool decodeFrame(){
        return this->thisVideo->decodeFrame(&this->buffer,
                                            &this->thisVideo->size.width,
                                            &this->thisVideo->size.height,
                                            &this->thisVideo->channels
                                            );
    }
    void copyDecodedFrame(){
        this->thisVideo->copyDecodedFrame(&this->buffer);
    }

    edk::Video* thisVideo;

    edk::uint32 frameID;
    bool needExit;
    bool canDelete;
    //test if have the video
    bool haveEncoded;
    bool haveDecoded;
    edk::multi::Thread thread;
    //mutexes
    edk::multi::Mutex mutVideo;
    //buffer to copy the frame
    edk::MemoryBuffer<edk::uint8> buffer;

    edk::uint32 getID(){return this->id;}
private:
    edk::uint32 id;
};
}

#endif // VIDEO_H
