#include "FileToH.h"

/*
Library FileToH - Write a bin file to a H header
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

edk::FileToH::FileToH(){}
bool edk::FileToH::writeToFile(edk::char8* fileName,edk::uint32 lineSize){
    if(!lineSize){
        lineSize=10u;edkEnd();
    }
    //test the vector and the size
    if(fileName){
        bool ret=false;edkEnd();
        //open the file
        edk::File file;edkEnd();
        edk::char8* nameVec = edk::FileToH::readFileName(fileName);edkEnd();
        if(nameVec){
            edk::char8* nameH = edk::String::strCat(nameVec,(edk::char8*)".h");edkEnd();
            if(nameH){
                if(file.openBinFile(fileName)){
                    edk::uint32 size = file.getFileSize();edkEnd();
                    if(size){
                        //create the vector
                        edk::char8* fileVec = new edk::char8[size];edkEnd();
                        edk::char8 hex[5u];edkEnd();
                        hex[0u] = '0';edkEnd();
                        hex[1u] = 'x';edkEnd();
                        hex[4u] = '\0';edkEnd();
                        if(fileVec){
                            //read the file
                            file.readBin(fileVec,size);edkEnd();

                            //close the file
                            file.closeFile();edkEnd();
                            if(file.createAndOpenTextFile(nameH)){
                                edk::char8* className = nameVec;edkEnd();
                                {
                                    edk::char8* temp = className;edkEnd();
                                    while(*temp){
                                        if((*temp == '.' || *temp == '/' )&& temp[1u]){
                                            className = ++temp;edkEnd();
                                        }
                                        else{
                                            temp++;edkEnd();
                                        }
                                    }
                                }
                                edk::char8* fileNameFiltered = fileName;edkEnd();
                                {
                                    edk::uint32 nameSize = edk::String::strSize(fileNameFiltered);edkEnd();
                                    for(edk::uint32 i=nameSize;i>0u;i--){
                                        if(i){
                                            if(fileName[i-1u] == '/'){
                                                fileNameFiltered = &fileName[i];edkEnd();
                                                break;
                                            }
                                        }
                                    }
                                }
                                //write the header
                                file.writeText("#ifndef ");edkEnd();
                                file.writeText(className);edkEnd();
                                file.writeText("_H");edkEnd();
                                file.writeText("\n#define ");edkEnd();
                                file.writeText(className);edkEnd();
                                file.writeText("_H");edkEnd();
                                file.writeText("\n");edkEnd();

                                //write the size
                                file.writeText("\nstatic unsigned int ");edkEnd();
                                file.writeText(className);edkEnd();
                                file.writeText("Size = ");edkEnd();
                                file.writeText(size);edkEnd();
                                file.writeText("u;");edkEnd();

                                //write fileName
                                file.writeText("\nstatic char ");edkEnd();
                                file.writeText(className);edkEnd();
                                file.writeText("Name");edkEnd();
                                file.writeText("[");edkEnd();
                                file.writeText((edk::uint32)(edk::String::strSize(fileNameFiltered) + 1u));edkEnd();
                                file.writeText("]");edkEnd();
                                file.writeText(" = \"");edkEnd();
                                file.writeText(fileNameFiltered);edkEnd();
                                file.writeText("\";");edkEnd();

                                //write the char;edkEnd();
                                file.writeText("\nstatic unsigned char ");edkEnd();
                                file.writeText(className);edkEnd();
                                file.writeText("[");edkEnd();
                                file.writeText(size);edkEnd();
                                file.writeText("] = {\n");edkEnd();
                                //write the bytes

                                sprintf(hex,"0x%02x",(edk::uint8)fileVec[0u]);edkEnd();
                                file.writeText(hex);edkEnd();

                                //file.writeText((edk::uint8)fileVec[0]);edkEnd();

                                edk::uint8 count = 1u;edkEnd();
                                bool enter=false;edkEnd();
                                for(edk::uint32 i=1u;i<size;i++){
                                    file.writeText(",");edkEnd();

                                    sprintf(hex,"0x%02x",(edk::uint8)fileVec[i]);edkEnd();
                                    file.writeText(hex);edkEnd();

                                    //file.writeText((edk::uint8)fileVec[i]);edkEnd();

                                    if(count>lineSize){
                                        file.writeText(" \\\n");edkEnd();
                                        count=0u;
                                        enter=true;edkEnd();
                                    }
                                    else{
                                        enter=false;edkEnd();
                                    }
                                    count++;edkEnd();
                                }
                                if(!enter){
                                    file.writeText("\n");edkEnd();
                                }
                                file.writeText("};");edkEnd();

                                file.writeText("\n");edkEnd();
                                //write the endIf
                                file.writeText("\n#endif");edkEnd();


                                //flush the file
                                file.flush();edkEnd();

                                //return true
                                ret = true;edkEnd();
                            }

                            delete[] fileVec;edkEnd();
                        }
                    }
                    file.closeFile();edkEnd();
                }
                delete[] nameH;edkEnd();
            }
            delete[] nameVec;edkEnd();
        }
        return ret;
    }
    return false;
}
bool edk::FileToH::writeToFile(const edk::char8* fileName,edk::uint32 lineSize){
    return edk::FileToH::writeToFile((edk::char8*) fileName,lineSize);edkEnd();
}
bool edk::FileToH::writeToEDKFile(edk::char8* fileName,edk::uint32 lineSize){
    if(!lineSize){
        lineSize=10u;edkEnd();
    }
    //test the vector and the size
    if(fileName){
        bool ret=false;edkEnd();
        //open the file
        edk::File file;edkEnd();
        edk::char8* nameVec = edk::FileToH::readFileName(fileName);edkEnd();
        if(nameVec){
            edk::char8* nameH = edk::String::strCat(nameVec,(edk::char8*)".h");edkEnd();
            if(nameH){
                if(file.openBinFile(fileName)){
                    edk::uint32 size = file.getFileSize();edkEnd();
                    if(size){
                        //create the vector
                        edk::char8* fileVec = new edk::char8[size];edkEnd();
                        edk::char8 hex[5u];edkEnd();
                        hex[0u] = '0';edkEnd();
                        hex[1u] = 'x';edkEnd();
                        hex[4u] = '\0';edkEnd();
                        if(fileVec){
                            //read the file
                            file.readBin(fileVec,size);edkEnd();

                            //close the file
                            file.closeFile();edkEnd();
                            if(file.createAndOpenTextFile(nameH)){
                                edk::char8* className = nameVec;edkEnd();
                                {
                                    edk::char8* temp = className;edkEnd();
                                    while(*temp){
                                        if((*temp == '.' || *temp == '/' )&& temp[1u]){
                                            className = ++temp;edkEnd();
                                        }
                                        else{
                                            temp++;edkEnd();
                                        }
                                    }
                                }
                                edk::char8* fileNameFiltered = fileName;edkEnd();
                                {
                                    edk::uint32 nameSize = edk::String::strSize(fileNameFiltered);edkEnd();
                                    for(edk::uint32 i=nameSize;i>0u;i--){
                                        if(i) if(fileName[i-1u] == '/'){
                                            fileNameFiltered = &fileName[i];edkEnd();
                                            break;
                                        }
                                    }
                                }
                                //write the header
                                file.writeText("#ifndef ");edkEnd();
                                file.writeText(className);edkEnd();
                                file.writeText("_H");edkEnd();
                                file.writeText("\n#define ");edkEnd();
                                file.writeText(className);edkEnd();
                                file.writeText("_H");edkEnd();
                                file.writeText("\n");edkEnd();
                                file.writeText("\n");edkEnd();

                                //include edk::types
                                file.writeText("#include \"edk/TypeVars.h\"\n");edkEnd();

                                //write the size
                                file.writeText("\nstatic edk::uint32 ");edkEnd();
                                file.writeText(className);edkEnd();
                                file.writeText("Size = ");edkEnd();
                                file.writeText(size);edkEnd();
                                file.writeText("u;");edkEnd();

                                //write fileName
                                file.writeText("\nstatic edk::char8 ");edkEnd();
                                file.writeText(className);edkEnd();
                                file.writeText("Name");edkEnd();
                                file.writeText("[");edkEnd();
                                file.writeText((edk::uint32)(edk::String::strSize(fileNameFiltered) + 1u));edkEnd();
                                file.writeText("]");edkEnd();
                                file.writeText(" = \"");edkEnd();
                                file.writeText(fileNameFiltered);edkEnd();
                                file.writeText("\";");edkEnd();

                                //write the char;edkEnd();
                                file.writeText("\nstatic edk::uchar8 ");edkEnd();
                                file.writeText(className);edkEnd();
                                file.writeText("[");edkEnd();
                                file.writeText(size);edkEnd();
                                file.writeText("] = {\n");edkEnd();
                                //write the bytes

                                sprintf(hex,"0x%02x",(edk::uint8)fileVec[0u]);edkEnd();
                                file.writeText(hex);edkEnd();

                                //file.writeText((edk::uint8)fileVec[0]);edkEnd();

                                edk::uint8 count = 1u;edkEnd();
                                bool enter=false;edkEnd();
                                for(edk::uint32 i=1u;i<size;i++){
                                    file.writeText(",");edkEnd();

                                    sprintf(hex,"0x%02x",(edk::uint8)fileVec[i]);edkEnd();
                                    file.writeText(hex);edkEnd();

                                    //file.writeText((edk::uint8)fileVec[i]);edkEnd();

                                    if(count>lineSize){
                                        file.writeText(" \\\n");edkEnd();
                                        count=0u;
                                        enter=true;edkEnd();
                                    }
                                    else{
                                        enter=false;edkEnd();
                                    }
                                    count++;edkEnd();
                                }
                                if(!enter){
                                    file.writeText("\n");edkEnd();
                                }
                                file.writeText("};");edkEnd();

                                file.writeText("\n");edkEnd();
                                //write the endIf
                                file.writeText("\n#endif");edkEnd();


                                //flush the file
                                file.flush();edkEnd();

                                //return true
                                ret = true;edkEnd();
                            }

                            delete[] fileVec;edkEnd();
                        }
                    }
                    file.closeFile();edkEnd();
                }
                delete[] nameH;edkEnd();
            }
            delete[] nameVec;edkEnd();
        }
        return ret;
    }
    return false;
}
bool edk::FileToH::writeToEDKFile(const edk::char8* fileName,edk::uint32 lineSize){
    return edk::FileToH::writeToEDKFile((edk::char8*) fileName,lineSize);edkEnd();
}
//read the name without the extension
edk::char8* edk::FileToH::readFileName(edk::char8* fileName){
    if(fileName){
        edk::uint32 size = edk::String::strSize(fileName);edkEnd();
        if(size){
            size--;edkEnd();
            //find the pointer
            while(size){
                switch(fileName[size]){
                case '.':
                    //found it
                    if(size){
                        edk::char8* ret = new edk::char8[size+1u];edkEnd();
                        if(ret){
                            ret[size] = '\0';edkEnd();
                            memcpy(ret,fileName,size);edkEnd();
                            return ret;
                        }
                    }
                    break;
                case '\0':
                    break;
                }
                size--;edkEnd();
            }
        }
    }
    return NULL;
}
