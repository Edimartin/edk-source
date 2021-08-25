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
    if(!lineSize) lineSize=10u;
    //test the vector and the size
    if(fileName){
        bool ret=false;
        //open the file
        edk::File file;
        edk::char8* nameVec = edk::FileToH::readFileName(fileName);
        if(nameVec){
            edk::char8* nameH = edk::String::strCat(nameVec,(edk::char8*)".h");
            if(nameH){
                if(file.openBinFile(fileName)){
                    edk::uint32 size = file.getFileSize();
                    if(size){
                        //create the vector
                        edk::char8* fileVec = new edk::char8[size];
                        edk::char8 hex[5u];
                        hex[0u] = '0';
                        hex[1u] = 'x';
                        hex[4u] = '\0';
                        if(fileVec){
                            //read the file
                            file.readBin(fileVec,size);

                            //close the file
                            file.closeFile();
                            if(file.createAndOpenTextFile(nameH)){
                                edk::char8* className = nameVec;
                                {
                                    edk::char8* temp = className;
                                    while(*temp){
                                        if((*temp == '.' || *temp == '/' )&& temp[1u]){
                                            className = ++temp;
                                        }
                                        else
                                        temp++;
                                    }
                                }
                                edk::char8* fileNameFiltered = fileName;
                                {
                                    edk::uint32 nameSize = edk::String::strSize(fileNameFiltered);
                                    for(edk::uint32 i=nameSize;i>0u;i--){
                                        if(i) if(fileName[i-1u] == '/'){
                                            fileNameFiltered = &fileName[i];
                                            break;
                                        }
                                    }
                                }
                                //write the header
                                file.writeText("#ifndef ");
                                file.writeText(className);
                                file.writeText("_H");
                                file.writeText("\n#define ");
                                file.writeText(className);
                                file.writeText("_H");
                                file.writeText("\n");

                                //write the size
                                file.writeText("\nstatic unsigned int ");
                                file.writeText(className);
                                file.writeText("Size = ");
                                file.writeText(size);
                                file.writeText("u;");

                                //write fileName
                                file.writeText("\nstatic char ");
                                file.writeText(className);
                                file.writeText("Name");
                                file.writeText("[");
                                file.writeText((edk::uint32)(edk::String::strSize(fileNameFiltered) + 1u));
                                file.writeText("]");
                                file.writeText(" = \"");
                                file.writeText(fileNameFiltered);
                                file.writeText("\";");

                                //write the char;
                                file.writeText("\nstatic unsigned char ");
                                file.writeText(className);
                                file.writeText("[");
                                file.writeText(size);
                                file.writeText("] = {\n");
                                //write the bytes

                                sprintf(hex,"0x%02x",(edk::uint8)fileVec[0u]);
                                file.writeText(hex);

                                //file.writeText((edk::uint8)fileVec[0]);

                                edk::uint8 count = 1u;
                                bool enter=false;
                                for(edk::uint32 i=1u;i<size;i++){
                                    file.writeText(",");

                                    sprintf(hex,"0x%02x",(edk::uint8)fileVec[i]);
                                    file.writeText(hex);

                                    //file.writeText((edk::uint8)fileVec[i]);

                                    if(count>lineSize){
                                        file.writeText(" \\\n");
                                        count=0u;
                                        enter=true;
                                    }
                                    else{
                                        enter=false;
                                    }
                                    count++;
                                }
                                if(!enter)file.writeText("\n");
                                file.writeText("};");

                                file.writeText("\n");
                                //write the endIf
                                file.writeText("\n#endif");


                                //flush the file
                                file.flush();

                                //return true
                                ret = true;
                            }

                            delete[] fileVec;
                        }
                    }
                    file.closeFile();
                }
                delete[] nameH;
            }
            delete[] nameVec;
        }
        return ret;
    }
    return false;
}
bool edk::FileToH::writeToFile(const edk::char8* fileName,edk::uint32 lineSize){
    return edk::FileToH::writeToFile((edk::char8*) fileName,lineSize);
}
bool edk::FileToH::writeToEDKFile(edk::char8* fileName,edk::uint32 lineSize){
    if(!lineSize) lineSize=10u;
    //test the vector and the size
    if(fileName){
        bool ret=false;
        //open the file
        edk::File file;
        edk::char8* nameVec = edk::FileToH::readFileName(fileName);
        if(nameVec){
            edk::char8* nameH = edk::String::strCat(nameVec,(edk::char8*)".h");
            if(nameH){
                if(file.openBinFile(fileName)){
                    edk::uint32 size = file.getFileSize();
                    if(size){
                        //create the vector
                        edk::char8* fileVec = new edk::char8[size];
                        edk::char8 hex[5u];
                        hex[0u] = '0';
                        hex[1u] = 'x';
                        hex[4u] = '\0';
                        if(fileVec){
                            //read the file
                            file.readBin(fileVec,size);

                            //close the file
                            file.closeFile();
                            if(file.createAndOpenTextFile(nameH)){
                                edk::char8* className = nameVec;
                                {
                                    edk::char8* temp = className;
                                    while(*temp){
                                        if((*temp == '.' || *temp == '/' )&& temp[1u]){
                                            className = ++temp;
                                        }
                                        else
                                        temp++;
                                    }
                                }
                                edk::char8* fileNameFiltered = fileName;
                                {
                                    edk::uint32 nameSize = edk::String::strSize(fileNameFiltered);
                                    for(edk::uint32 i=nameSize;i>0u;i--){
                                        if(i) if(fileName[i-1u] == '/'){
                                            fileNameFiltered = &fileName[i];
                                            break;
                                        }
                                    }
                                }
                                //write the header
                                file.writeText("#ifndef ");
                                file.writeText(className);
                                file.writeText("_H");
                                file.writeText("\n#define ");
                                file.writeText(className);
                                file.writeText("_H");
                                file.writeText("\n");
                                file.writeText("\n");

                                //include edk::types
                                file.writeText("#include \"edk/TypeVars.h\"\n");

                                //write the size
                                file.writeText("\nstatic edk::uint32 ");
                                file.writeText(className);
                                file.writeText("Size = ");
                                file.writeText(size);
                                file.writeText("u;");

                                //write fileName
                                file.writeText("\nstatic edk::char8 ");
                                file.writeText(className);
                                file.writeText("Name");
                                file.writeText("[");
                                file.writeText((edk::uint32)(edk::String::strSize(fileNameFiltered) + 1u));
                                file.writeText("]");
                                file.writeText(" = \"");
                                file.writeText(fileNameFiltered);
                                file.writeText("\";");

                                //write the char;
                                file.writeText("\nstatic edk::uchar8 ");
                                file.writeText(className);
                                file.writeText("[");
                                file.writeText(size);
                                file.writeText("] = {\n");
                                //write the bytes

                                sprintf(hex,"0x%02x",(edk::uint8)fileVec[0u]);
                                file.writeText(hex);

                                //file.writeText((edk::uint8)fileVec[0]);

                                edk::uint8 count = 1u;
                                bool enter=false;
                                for(edk::uint32 i=1u;i<size;i++){
                                    file.writeText(",");

                                    sprintf(hex,"0x%02x",(edk::uint8)fileVec[i]);
                                    file.writeText(hex);

                                    //file.writeText((edk::uint8)fileVec[i]);

                                    if(count>lineSize){
                                        file.writeText(" \\\n");
                                        count=0u;
                                        enter=true;
                                    }
                                    else{
                                        enter=false;
                                    }
                                    count++;
                                }
                                if(!enter)file.writeText("\n");
                                file.writeText("};");

                                file.writeText("\n");
                                //write the endIf
                                file.writeText("\n#endif");


                                //flush the file
                                file.flush();

                                //return true
                                ret = true;
                            }

                            delete[] fileVec;
                        }
                    }
                    file.closeFile();
                }
                delete[] nameH;
            }
            delete[] nameVec;
        }
        return ret;
    }
    return false;
}
bool edk::FileToH::writeToEDKFile(const edk::char8* fileName,edk::uint32 lineSize){
    return edk::FileToH::writeToEDKFile((edk::char8*) fileName,lineSize);
}
//read the name without the extension
edk::char8* edk::FileToH::readFileName(edk::char8* fileName){
    if(fileName){
        edk::uint32 size = edk::String::strSize(fileName);
        if(size){
            size--;
            //find the pointer
            while(size){
                switch(fileName[size]){
                case '.':
                    //found it
                    if(size){
                        edk::char8* ret = new edk::char8[size+1u];
                        if(ret){
                            ret[size] = '\0';
                            memcpy(ret,fileName,size);
                            return ret;
                        }
                    }
                    break;
                case '\0':
                    break;
                }
                size--;
            }
        }
    }
    return NULL;
}
