#ifndef DEBUGFILE_H
#define DEBUGFILE_H

/*
Library C++ DebugFile - Write debug messages in a file
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

#pragma once
#include <stdio.h>

#ifdef printMessages
#pragma message "Inside DebugFile"
#endif

#include "TypeVars.h"
#include "File.h"

#ifdef printMessages
#pragma message "    Compiling DebugFile"
#endif

#if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
#ifndef EDK_DEBUG_FILE_NAME
#pragma message "    Don't have EDK_DEBUG_FILE_NAME"
#define EDK_DEBUG_FILE_NAME "./edkDebug.txt"
#pragma message " using the EDK_DEBUG_FILE_NAME as "./edkDebug.txt" "
#pragma message " if you want define a debugFile. You can use the command -DEDK_DEBUG_FILE_NAME=\"./edkDebug.txt\" "
#pragma message " if you want define a debugFile in qtCreator. You can use the command DEFINES += EDK_DEBUGGER EDK_DEBUG_FILE_NAME=\\\"./edkDebug.txt\\\" "
#endif
#endif

extern edk::uint64 EDKArrayVectorFreeCounter;

namespace edk{
class DebugFile{
public:
    DebugFile();
    ~DebugFile();

    void Constructor(bool runFather=true);

    static bool newFile(const edk::char8* name);
    static bool newFile(edk::char8* name);

    static void closeFile();

    //write in to file
    static inline bool writeDebug(edk::uint64 line,const edk::char8* fileName,const edk::char8* funcName){
        return edk::DebugFile::writeDebug(line,(edk::char8*) fileName,(edk::char8*) funcName);
    }
    static inline bool writeDebug(edk::uint64
                              #if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
                                  line
                              #endif
                                  ,edk::char8*
                              #if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
                                  fileName
                              #endif
                                  ,edk::char8*
                              #if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
                                  funcName
                              #endif
                                  ){
#if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
        //test if haven't open the file
        if(!edk::DebugFile::file.isOpened()){
            //create the file
            edk::DebugFile::newFile(EDK_DEBUG_FILE_NAME);
        }
        if(edk::DebugFile::file.writeText(line)){
            if(edk::DebugFile::file.writeText(" ")){
                if(edk::DebugFile::file.writeText(fileName)){
                    if(edk::DebugFile::file.writeText(" ")){
                        if(edk::DebugFile::file.writeText(funcName)){
                            if(edk::DebugFile::file.writeText("\n")){
                                //flush the file
                                edk::DebugFile::file.flush();
                                return true;
                            }
                        }
                    }
                }
            }
        }
#endif
        return false;
    }

    //write memset in to file
    static inline bool writeMemSetDebug(edk::uint64 line,const edk::char8* fileName,const edk::char8* funcName, edk::uint64 size){
        return edk::DebugFile::writeMemSetDebug(line,(edk::char8*) fileName,(edk::char8*) funcName,size);
    }
    static inline bool writeMemSetDebug(edk::uint64
                                    #if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
                                        line
                                    #endif
                                        ,edk::char8*
                                    #if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
                                        fileName
                                    #endif
                                        ,edk::char8*
                                    #if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
                                        funcName
                                    #endif
                                        ,edk::uint64
                                    #if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
                                        size
                                    #endif
                                        ){
#if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
        //test if haven't open the file
        if(!edk::DebugFile::file.isOpened()){
            //create the file
            edk::DebugFile::newFile(EDK_DEBUG_FILE_NAME);
        }
        if(edk::DebugFile::file.writeText(line)){
            if(edk::DebugFile::file.writeText(" ")){
                if(edk::DebugFile::file.writeText(fileName)){
                    if(edk::DebugFile::file.writeText(" ")){
                        if(edk::DebugFile::file.writeText(funcName)){
                            if(edk::DebugFile::file.writeText(" memSetSize(")){
                                if(edk::DebugFile::file.writeText(size)){
                                    if(edk::DebugFile::file.writeText(")\n")){
                                        //flush the file
                                        edk::DebugFile::file.flush();
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
#endif
        return false;
    }

    //write memset in to file
    static inline bool writeMemCpyDebug(edk::uint64 line,const edk::char8* fileName,const edk::char8* funcName, edk::uint64 size){
        return edk::DebugFile::writeMemCpyDebug(line,(edk::char8*) fileName,(edk::char8*) funcName,size);
    }
    static inline bool writeMemCpyDebug(edk::uint64
                                    #if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
                                        line
                                    #endif
                                        ,edk::char8*
                                    #if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
                                        fileName
                                    #endif
                                        ,edk::char8*
                                    #if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
                                        funcName
                                    #endif
                                        ,edk::uint64
                                    #if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
                                        size
                                    #endif
                                        ){
#if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
        //test if haven't open the file
        if(!edk::DebugFile::file.isOpened()){
            //create the file
            edk::DebugFile::newFile(EDK_DEBUG_FILE_NAME);
        }
        if(edk::DebugFile::file.writeText(line)){
            if(edk::DebugFile::file.writeText(" ")){
                if(edk::DebugFile::file.writeText(fileName)){
                    if(edk::DebugFile::file.writeText(" ")){
                        if(edk::DebugFile::file.writeText(funcName)){
                            if(edk::DebugFile::file.writeText(" memCpySize(")){
                                if(edk::DebugFile::file.writeText(size)){
                                    if(edk::DebugFile::file.writeText(")\n")){
                                        //flush the file
                                        edk::DebugFile::file.flush();
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
#endif
        return false;
    }

private:
#if defined(EDK_DEBUGGER) || defined(EDK_DEBUG_MEMSET) || defined(EDK_DEBUG_MEMCPY)
    //statis file
    static edk::File file;
    static bool templateConstructNeed;
#endif
private:
    edk::classID classThis;
};
}//end namespace edk

#if defined(EDK_DEBUGGER)
#define edkEnd() edk::DebugFile::writeDebug(__LINE__,__FILE__,__func__); edk::NothingClass::edk_nothing()
#else
#define edkEnd() edk::NothingClass::edk_nothing()
#endif

#if defined(EDK_DEBUG_MEMSET)
#define edkMemSet(vec,set,size) \
    \
    \
    memset(vec,set,size); \
    edk::DebugFile::writeMemSetDebug(__LINE__,__FILE__,__func__,size); \
    edk::NothingClass::edk_nothing()
#else
#define edkMemSet(vec,set,size) \
    memset(vec,set,size); \
    edk::NothingClass::edk_nothing()
#endif

#if defined(EDK_DEBUG_MEMCPY)
#define edkMemCpy(dest,vec,size) \
    \
    memcpy(dest,vec,size); \
    edk::DebugFile::writeMemCpyDebug(__LINE__,__FILE__,__func__,size); \
    edk::NothingClass::edk_nothing()
#else
#define edkMemCpy(dest,vec,size) \
    memcpy(dest,vec,size); \
    edk::NothingClass::edk_nothing()
#endif

#endif // DEBUGFILE_H
