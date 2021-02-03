#include "ListDirectory.h"

/*
Library C++ ListDirectory - List files and folders inside a directory
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
    }
    return false;
}
bool edk::ListDirectory::run(const edk::char8* directory){
    return this->run((edk::char8*) directory);
}
