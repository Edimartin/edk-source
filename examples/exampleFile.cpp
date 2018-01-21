/*
Library EDK - How to use Extensible Development Kit
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

#include <stdio.h>

#include "edk/File.h"
#include "edk/String.h"

#define textFileName "fileFolder/file.txt"
#define textFileNameNEW "fileFolder/fileNEW.txt"

int main(){
    edk::File file;
    //create a file and open this to write from the start
    file.createAndOpenTextFile(textFileName);fflush(stdout);
    if(file.isOpened()){
        file.writeText("Text inside the file");
        //flush the file
        file.flush();
        //close the file
        file.closeFile();
    }

    //open the file to write at the end of the file
    if(file.openEndTextFile(textFileName)){
        //
        file.writeText("\nSecond text writed in the file");fflush(stdout);
        //flush the file
        file.flush();
        //close the file
        file.closeFile();
    }

    //test if the file exist
    if(edk::File::fileExist(textFileName)){
        //
        file.writeText("\nThe file textFileName exist");fflush(stdout);

        //change the name of the file
        edk::File::renameFile(textFileName,textFileNameNEW);
    }
    else{
        //
        file.writeText("\nThe file textFileName DON'T exist");fflush(stdout);
    }

    if(file.openBinFile(textFileNameNEW)){
        file.closeFile();
    }

    //open the file to read from the start
    if(file.openTextFile(textFileNameNEW)){
        //get the fileSize
        edk::uint64 size = file.getFileSize();
        if(size){
            //read the file string
            edk::char8* buffer;
            buffer = new edk::char8[size+1u];
            if(buffer){
                printf("\nRead the file two times");fflush(stdout);
                //read the file two times
                for(edk::uint32 i=0u;i<2u;i++){
                    buffer[size]=0u;
                    //copy the buffer
                    if(file.readTextString(buffer,size)){
                        printf("\n'%s'"
                               ,buffer
                               );fflush(stdout);
                    }
                    //seek to start
                    file.seekStart();
                }
                //delete the buffer
                delete[] buffer;
            }
        }
    }

    printf("\nPress a key to continue");fflush(stdout);
    edk::String::consoleReadKey();

    //delete the file
    printf("\nDelete the file");fflush(stdout);
    edk::File::deleteFile(textFileNameNEW);

    printf("\n\n");fflush(stdout);
    return 0;
}
