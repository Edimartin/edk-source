#include "FileToH.h"

/*
Library FileToH - Write a bin file to a H header
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
                                file.writeText((edk::uint32)(edk::String::strSize(fileName) + 1u));
                                file.writeText("]");
                                file.writeText(" = \"");
                                file.writeText(fileName);
                                file.writeText("\";");

                                //write the char;
                                file.writeText("\nstatic unsigned char ");
                                file.writeText(className);
                                file.writeText("[");
                                file.writeText(size);
                                file.writeText("] = {\n");
                                //write the bytes
                                file.writeText((edk::uint8)fileVec[0]);
                                edk::uint8 count = 1u;
                                bool enter=false;
                                for(unsigned int i=1u;i<size;i++){
                                    file.writeText(",");
                                    file.writeText((edk::uint8)fileVec[i]);
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
        {
            //filter fileName
            edk::uint32 nameSize = edk::String::strSize(fileName);
            if(nameSize){
                for(edk::uint32 i=0u;i<nameSize;i++){
                    //
                }
            }
        }
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
                                file.writeText((edk::uint32)(edk::String::strSize(fileName) + 1u));
                                file.writeText("]");
                                file.writeText(" = \"");
                                file.writeText(fileName);
                                file.writeText("\";");

                                //write the char;
                                file.writeText("\nstatic edk::uchar8 ");
                                file.writeText(className);
                                file.writeText("[");
                                file.writeText(size);
                                file.writeText("] = {\n");
                                //write the bytes
                                file.writeText((edk::uint8)fileVec[0]);
                                edk::uint8 count = 1u;
                                bool enter=false;
                                for(unsigned int i=1u;i<size;i++){
                                    file.writeText(",");
                                    file.writeText((edk::uint8)fileVec[i]);
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
