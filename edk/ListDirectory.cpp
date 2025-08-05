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
    this->classThis=NULL;
    this->Constructor();
}
edk::ListDirectory::~ListDirectory(){
    this->Destructor();
}

//start listing the folders and files in a directory received by function parameter
bool edk::ListDirectory::runNoClean(edk::char8* directory){
    if(directory){
        //directory pointer
        DIR *dir;
        //file pointer
        struct dirent *file;
        //status of the file
        struct stat status;


        edk::char8* str = NULL;
        if(edk::String::strCompareEnd(directory,"/")){
            str = edk::String::strCopy(directory);
        }
        else{
            str = edk::String::strCat(directory,"/");
        }
        if(str){
            this->directorySave.setName(str);
            free(str);
        }

        edk::char8* temp=NULL;
        //open the directory
        dir = opendir(directory);
        if(dir){
            //printf("\nDirectory %s",directory);
            //list the files
            while((file = readdir(dir)) != NULL){
                //create the file string to read the status
                temp = edk::String::strCatMulti(directory,"/",file->d_name,NULL);
                if(temp){
                    //read the status
                    stat(temp, &status);

                    switch(status.st_mode & S_IFMT){
                    case S_IFDIR:
                        //FOLDER
                        //test if the folder are different the . or ..
                        if(!edk::String::strCompare(file->d_name,".")
                            && !edk::String::strCompare(file->d_name,"..")
                            ){
                            //printf("\nFolder:'%s' LastModify:%lu size:%lu",file->d_name,status.st_mtime,status.st_size);fflush(stdout);
                            this->listFolder(file->d_name,status.st_mtime,status.st_size);
                        }
                        break;
                    case S_IFREG:
                        //FILE
                        //printf("\nFile  :'%s' LastModify:%lu size:%lu",file->d_name,status.st_mtime,status.st_size);fflush(stdout);
                        this->listFile(file->d_name,status.st_mtime,status.st_size);
                        break;
                    }

                    free(temp);
                }
            }
            closedir(dir);
            return true;
        }
    }
    return false;
}
bool edk::ListDirectory::runNoClean(const edk::char8* directory){
    return this->runNoClean((edk::char8*) directory);
}
bool edk::ListDirectory::runNoCleanFilesOnly(edk::char8* directory){
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
            //printf("\nDirectory %s",directory);
            //list the files
            while((file = readdir(dir)) != NULL){
                //create the file string to read the status
                temp = edk::String::strCatMulti(directory,"/",file->d_name,NULL);
                if(temp){
                    //read the status
                    stat(temp, &status);

                    switch(status.st_mode & S_IFMT){
                    case S_IFDIR:
                        //FOLDER
                        break;
                    case S_IFREG:
                        //FILE
                        //printf("\nFile  :'%s' LastModify:%lu size:%lu",file->d_name,status.st_mtime,status.st_size);fflush(stdout);
                        this->listFile(file->d_name,status.st_mtime,status.st_size);
                        break;
                    }

                    free(temp);
                }
            }
            closedir(dir);
            return true;
        }
    }
    return false;
}
bool edk::ListDirectory::runNoCleanFilesOnly(const edk::char8* directory){
    return this->runNoCleanFoldersOnly((edk::char8*) directory);
}
bool edk::ListDirectory::runNoCleanFoldersOnly(edk::char8* directory){
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
            //printf("\nDirectory %s",directory);
            //list the files
            while((file = readdir(dir)) != NULL){
                //create the file string to read the status
                temp = edk::String::strCatMulti(directory,"/",file->d_name,NULL);
                if(temp){
                    //read the status
                    stat(temp, &status);

                    switch(status.st_mode & S_IFMT){
                    case S_IFDIR:
                        //FOLDER
                        //test if the folder are different the . or ..
                        if(!edk::String::strCompare(file->d_name,".")
                            && !edk::String::strCompare(file->d_name,"..")
                            ){
                            //printf("\nFolder:'%s' LastModify:%lu size:%lu",file->d_name,status.st_mtime,status.st_size);fflush(stdout);
                            this->listFolder(file->d_name,status.st_mtime,status.st_size);
                        }
                        break;
                    case S_IFREG:
                        break;
                    }

                    free(temp);
                }
            }
            closedir(dir);
            return true;
        }
    }
    return false;
}
bool edk::ListDirectory::runNoCleanFoldersOnly(const edk::char8* directory){
    return this->runNoCleanFoldersOnly((edk::char8*) directory);
}

void edk::ListDirectory::Constructor(){
    //
    if(this->classThis!=this){
        this->classThis=this;

        this->files.Constructor();
        this->folders.Constructor();
    }
}
void edk::ListDirectory::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class

        this->files.Destructor();
        this->folders.Destructor();
    }
}

void edk::ListDirectory::clean(){
    this->cleanFiles();
    this->cleanFolders();
}

//start listing the folders and files in a directory received by function parameter
bool edk::ListDirectory::run(edk::char8* directory){
    this->folders.clean();
    this->files.clean();
    return this->runNoClean(directory);
}
bool edk::ListDirectory::run(const edk::char8* directory){
    return this->run((edk::char8*) directory);
}
bool edk::ListDirectory::runFilesOnly(edk::char8* directory){
    this->folders.clean();
    this->files.clean();
    return this->runNoCleanFilesOnly(directory);
}
bool edk::ListDirectory::runFilesOnly(const edk::char8* directory){
    return this->runFoldersOnly((edk::char8*) directory);
}
bool edk::ListDirectory::runFoldersOnly(edk::char8* directory){
    this->folders.clean();
    this->files.clean();
    return this->runNoCleanFoldersOnly(directory);
}
bool edk::ListDirectory::runFoldersOnly(const edk::char8* directory){
    return this->runFoldersOnly((edk::char8*) directory);
}
//recursive
bool edk::ListDirectory::runRecursive(edk::char8* directory){
    this->folders.clean();
    this->files.clean();
    if(directory){
        //run the first with the directory
        if(this->runNoClean(directory)){
            //get the size of directories
            edk::uint32 size = this->folders.size();
            edk::uint32 i=0u;
            edk::ListDirectory::FileOrFolders* folderTemp=NULL;
            do{
                for(;i<size;i++){
                    //print the folder name
                    folderTemp = this->folders.get(i);
                    if(folderTemp){
                        if(folderTemp->name.haveName()){
                            this->runNoClean(folderTemp->name.getName());
                        }
                    }
                }
            }while(i<size);
            return true;
        }
    }
    return false;
}
bool edk::ListDirectory::runRecursive(const edk::char8* directory){
    return this->runRecursive((edk::char8*) directory);
}
bool edk::ListDirectory::runFilesOnlyRecursive(edk::char8* directory){
    this->folders.clean();
    this->files.clean();
    if(directory){
        //run the first with the directory
        if(this->runNoClean(directory)){
            //get the size of directories
            edk::uint32 size = this->folders.size();
            edk::uint32 i=0u;
            edk::ListDirectory::FileOrFolders* folderTemp=NULL;
            do{
                for(;i<size;i++){
                    //print the folder name
                    folderTemp = this->folders.get(i);
                    if(folderTemp){
                        if(folderTemp->name.haveName()){
                            this->runNoClean(folderTemp->name.getName());
                        }
                    }
                }
            }while(i<size);
            this->cleanFolders();
            return true;
        }
    }
    return false;
}
bool edk::ListDirectory::runFilesOnlyRecursive(const edk::char8* directory){
    return this->runFilesOnlyRecursive((edk::char8*) directory);
}
bool edk::ListDirectory::runFoldersOnlyRecursive(edk::char8* directory){
    this->folders.clean();
    this->files.clean();
    if(directory){
        //run the first with the directory
        if(this->runNoCleanFoldersOnly(directory)){
            //get the size of directories
            edk::uint32 size = this->folders.size();
            edk::uint32 i=0u;
            edk::ListDirectory::FileOrFolders* folderTemp=NULL;
            do{
                for(;i<size;i++){
                    //print the folder name
                    folderTemp = this->folders.get(i);
                    if(folderTemp){
                        if(folderTemp->name.haveName()){
                            this->runNoCleanFoldersOnly(folderTemp->name.getName());
                        }
                    }
                }
            }while(i<size);
            return true;
        }
    }
    return false;
}
bool edk::ListDirectory::runFoldersOnlyRecursive(const edk::char8* directory){
    return this->runFoldersOnlyRecursive((edk::char8*) directory);
}

//get files
edk::uint32 edk::ListDirectory::getFilesSize(){
    return this->files.size();
}
edk::char8* edk::ListDirectory::getFileName(edk::uint32 position){
    if(this->files.havePos(position)){
        return this->files.get(position)->name.getName();
    }
    return NULL;
}
edk::uint64 edk::ListDirectory::getFileLastModify(edk::uint32 position){
    if(this->files.havePos(position)){
        return this->files.get(position)->lastModify;
    }
    return 0uL;
}
edk::uint64 edk::ListDirectory::getFileSize(edk::uint32 position){
    if(this->files.havePos(position)){
        return this->files.get(position)->size;
    }
    return 0uL;
}
void edk::ListDirectory::cleanFiles(){
    edk::uint32 size = this->files.size();
    edk::ListDirectory::FileOrFolders* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->files.get(i);
        delete temp;
    }
    this->files.clean();
}
//get folders
edk::uint32 edk::ListDirectory::getFoldersSize(){
    return this->folders.size();
}
edk::char8* edk::ListDirectory::getFolderName(edk::uint32 position){
    if(this->folders.havePos(position)){
        return this->folders.get(position)->name.getName();
    }
    return NULL;
}
edk::uint64 edk::ListDirectory::getFolderLastModify(edk::uint32 position){
    if(this->folders.havePos(position)){
        return this->folders.get(position)->lastModify;
    }
    return 0uL;
}
edk::uint64 edk::ListDirectory::getFolderSize(edk::uint32 position){
    if(this->folders.havePos(position)){
        return this->folders.get(position)->size;
    }
    return 0uL;
}
void edk::ListDirectory::cleanFolders(){
    edk::uint32 size = this->folders.size();
    edk::ListDirectory::FileOrFolders* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->folders.get(i);
        delete temp;
    }
    this->folders.clean();
}

//print the data
void edk::ListDirectory::printFiles(){
    edk::uint32 size = this->files.size();
    edk::ListDirectory::FileOrFolders* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->files.get(i);
        if(temp){
            printf("\n%s",temp->name.getName());fflush(stdout);
        }
    }
}
void edk::ListDirectory::printFolders(){
    edk::uint32 size = this->folders.size();
    edk::ListDirectory::FileOrFolders* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->folders.get(i);
        if(temp){
            printf("\n%s/",temp->name.getName());fflush(stdout);
        }
    }
}
void edk::ListDirectory::print(){
    this->printFolders();
    this->printFiles();
}
bool edk::ListDirectory::printDirectory(edk::char8* directory){
    edk::ListDirectory l;
    if(l.run(directory)){
        l.print();
        return true;
    }
    return false;
}
bool edk::ListDirectory::printDirectory(const edk::char8* directory){
    return edk::ListDirectory::printDirectory((edk::char8*) directory);
}
bool edk::ListDirectory::printDirectoryFiles(edk::char8* directory){
    edk::ListDirectory l;
    if(l.run(directory)){
        l.printFiles();
        return true;
    }
    return false;
}
bool edk::ListDirectory::printDirectoryFiles(const edk::char8* directory){
    return edk::ListDirectory::printDirectoryFiles((edk::char8*) directory);
}
bool edk::ListDirectory::printDirectoryFolders(edk::char8* directory){
    edk::ListDirectory l;
    if(l.run(directory)){
        l.printFolders();
        return true;
    }
    return false;
}
bool edk::ListDirectory::printDirectoryFolders(const edk::char8* directory){
    return edk::ListDirectory::printDirectoryFolders((edk::char8*) directory);
}

void edk::ListDirectory::listFile(edk::char8* name,edk::uint64 lastModify,edk::uint64 size){//test if have directory saved
    edk::ListDirectory::FileOrFolders* temp = NULL;
    if(this->directorySave.haveName()){
        edk::char8* str = edk::String::strCat(this->directorySave.getName(),name);
        if(str){
            temp = new edk::ListDirectory::FileOrFolders(str,lastModify,size);
            if(temp){
                edk::uint32 size = this->files.size();
                this->files.pushBack(temp);
                if(size >= this->files.size()){
                    delete temp;
                }
            }
            free(str);
        }
    }
    else{
        temp = new edk::ListDirectory::FileOrFolders(name,lastModify,size);
        if(temp){
            edk::uint32 size = this->files.size();
            this->files.pushBack(temp);
            if(size >= this->files.size()){
                delete temp;
            }
        }
    }
}
void edk::ListDirectory::listFolder(edk::char8* name,edk::uint64 lastModify,edk::uint64 size){
    //test if have directory saved
    edk::ListDirectory::FileOrFolders* temp = NULL;
    if(this->directorySave.haveName()){
        edk::char8* str = edk::String::strCat(this->directorySave.getName(),name);
        if(str){
            temp = new edk::ListDirectory::FileOrFolders(str,lastModify,size);
            if(temp){
                edk::uint32 size = this->folders.size();
                this->folders.pushBack(temp);
                if(size >= this->folders.size()){
                    delete temp;
                }
            }
            free(str);
        }
    }
    else{
        temp = new edk::ListDirectory::FileOrFolders(name,lastModify,size);
        if(temp){
            edk::uint32 size = this->folders.size();
            this->folders.pushBack(temp);
            if(size >= this->folders.size()){
                delete temp;
            }
        }
    }
}
