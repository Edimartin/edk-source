#ifndef DEBUGLINEFILE_H
#define DEBUGLINEFILE_H

/*
Library C++ DebugLineFile - Write debug messages with line codes in a file
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
#pragma message "Inside DebugLineFile"
#endif

#include "DebugFile.h"
#include "thread/Thread.h"

#ifdef printMessages
#pragma message "    Compiling DebugLineFile"
#endif

namespace edk{
class DebugLineFile{
public:
    DebugLineFile(){this->classThis=NULL;edkEnd();
                    this->Constructor(false);edkEnd();}
    virtual ~DebugLineFile(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){edkEnd();}
        if(this->classThis!=this){
            this->classThis=this;

            this->debugLineFile.Constructor();edkEnd();
        }
    }

    //create the file
    inline bool createFile(edk::char8* fileName){
        //create the new file
        if(fileName){
            this->debugLineFile.closeFile();
            return this->debugLineFile.createAndOpenTextFile(fileName);
        }
        return false;
    }
    inline bool createFile(const edk::char8* fileName){
        return this->createFile((edk::char8*) fileName);
    }
    //close the file
    inline void closeFile(){
        this->debugLineFile.closeFile();
    }
    inline void writeDebug(edk::char8* text,edk::int32 line,edk::char8* file,edk::char8* function){
        if(text && line && function){
            //create the debugString
            edk::char8* newLine = edk::String::int32ToStr(line);
            if(newLine){
                //create strings for this class and thread ID
                edk::char8* thisStr = edk::String::uint64ToStr((edk::uint64)this);
                if(thisStr){
                    edk::char8* id = edk::String::uint64ToStr((edk::uint64)edk::multi::Thread::getThisThreadID());
                    if(id){
                        //create the string
                        edk::char8* str = edk::String::strCatMulti("\n",newLine," ",file," thread(",id,") this[",thisStr,"] ",function," ",text,NULL);
                        if(str){
                            //write this string into the file
                            this->debugLineFile.writeText(str);
                            this->debugLineFile.flush();
                            free(str);
                        }
                        free(id);
                    }
                    free(thisStr);
                }
                free(newLine);
            }
        }
    }
    inline void writeDebug(const edk::char8* text,edk::int32 line,const edk::char8* file,const edk::char8* function){
        this->writeDebug((edk::char8*) text,line,(edk::char8*) file,(edk::char8*) function);
    }
    inline void writeDebug(edk::char8* text){
        if(text){
            //write this string into the file
            this->debugLineFile.writeText(text);
            this->debugLineFile.flush();
        }
    }
    inline void writeDebug(const edk::char8* text){
        this->writeDebug((edk::char8*) text);
    }
private:
    edk::File debugLineFile;
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // DEBUGLINEFILE_H
