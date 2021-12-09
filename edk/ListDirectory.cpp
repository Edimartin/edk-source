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

        //test if are trying to compile in Windows
#if defined(_WIN32) || defined(_WIN64)

        //Or Linux or MacOS
#elif defined(__linux__) || defined(__APPLE__)
        //directory pointer
        DIR *dir;
        //file pointer
        struct dirent *file;
        //status of the file
        struct stat status;

        edk::char8* temp=NULL;
        //open the directory
        dir = opendir(directory);
        if(dir){
            printf("\nDirectory %s",directory);fflush(stdout);
            //list the files
            while((file = readdir(dir)) != NULL){
                //create the file string to read the status
                temp = edk::String::strCatMulti(directory,"/",file->d_name,NULL);
                if(temp){
                    //read the status
                    stat(temp, &status);

                    switch(file->d_type){
                    case 4u:
                        //FOLDER
                        //printf("\nFolder:%s\\ LastModify:%lu size:%lu",file->d_name,status.st_mtime,status.st_size);fflush(stdout);
                        this->listFolder(file->d_name,status.st_mtime,status.st_size);
                        break;
                    case 8u:
                        //FILE
                        //printf("\nFile  :%s\\ LastModify:%lu size:%lu",file->d_name,status.st_mtime,status.st_size);fflush(stdout);
                        this->listFile(file->d_name,status.st_mtime,status.st_size);
                        break;
                    }

                    delete[] temp;
                }
            }

            closedir(dir);
        }
#endif
    }
    return false;
}
bool edk::ListDirectory::run(const edk::char8* directory){
    return this->run((edk::char8*) directory);
}
