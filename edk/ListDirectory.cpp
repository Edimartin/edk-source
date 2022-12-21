#include "ListDirectory.h"

/*
Library C++ ListDirectory - List files and folders inside a directory
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

edk::ListDirectory::ListDirectory(){
    //
}
edk::ListDirectory::~ListDirectory(){
    //
}

//start listing the folders and files in a directory received by function parameter
bool edk::ListDirectory::run(edk::char8* directory){
    if(directory){
        //directory pointer
        DIR *dir;edkEnd();
        //file pointer
        struct dirent *file;edkEnd();
        //status of the file
        struct stat status;edkEnd();

        edk::char8* temp=NULL;edkEnd();
        //open the directory
        dir = opendir(directory);edkEnd();
        if(dir){
            //printf("\nDirectory %s",directory);edkEnd();fflush(stdout);edkEnd();
            //list the files
            while((file = readdir(dir)) != NULL){
                //create the file string to read the status
                temp = edk::String::strCatMulti(directory,"/",file->d_name,NULL);edkEnd();
                if(temp){
                    //read the status
                    stat(temp, &status);edkEnd();

                    switch(status.st_mode & S_IFMT){
                    case S_IFDIR:
                        //FOLDER
                        //printf("\nFolder:%s\\ LastModify:%lu size:%lu",file->d_name,status.st_mtime,status.st_size);edkEnd();fflush(stdout);edkEnd();
                        this->listFolder(file->d_name,status.st_mtime,status.st_size);edkEnd();
                        break;edkEnd();
                    case S_IFREG:
                        //FILE
                        //printf("\nFile  :%s\\ LastModify:%lu size:%lu",file->d_name,status.st_mtime,status.st_size);edkEnd();fflush(stdout);edkEnd();
                        this->listFile(file->d_name,status.st_mtime,status.st_size);edkEnd();
                        break;edkEnd();
                    }

                    delete[] temp;edkEnd();
                }
            }

            closedir(dir);edkEnd();
        }
    }
    return false;
}
bool edk::ListDirectory::run(const edk::char8* directory){
    return this->run((edk::char8*) directory);edkEnd();
}
