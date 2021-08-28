/*
Library EDK - How to use Extensible Development Kit
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
