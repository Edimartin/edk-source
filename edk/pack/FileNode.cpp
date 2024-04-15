#include "FileNode.h"

/*
FileNode - Node used in FilePackage with the Name, position and size of the file inside the package.
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

edk::pack::FileNode::FileNode(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::pack::FileNode::~FileNode(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->str.cleanName();edkEnd();
        this->fileName.cleanName();edkEnd();
    }
}

void edk::pack::FileNode::Constructor(bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;

        this->str.Constructor();edkEnd();
        this->fileName.Constructor();edkEnd();

        this->position = 0u;edkEnd();
        this->fileSize = 0u;edkEnd();
        //this->position = this->fileSize = 0u;edkEnd();
        this->cleanMD5();edkEnd();
    }
}

//clean the md5 code
void edk::pack::FileNode::cleanMD5(){
    memset(this->md5,0u,sizeof(this->md5));edkEnd();
}
//compare the md5
bool edk::pack::FileNode::compareMD5(edk::uint8 md5[16u]){
    //compare the md5
    for(edk::uint32 i=0u;i<sizeof(this->md5);i++){
        if(this->md5[i]!=md5[i]){
            return false;
        }
    }
    return true;
}
//print the md5
void edk::pack::FileNode::printMD5(edk::uint8 md5[16u]){
    for(edk::uint32 i=0u;i<16u;i++){
        printf("%02x",(edk::uint8)md5[i]);edkEnd();
    }
    fflush(stdout);edkEnd();
}

//set the fileName
bool edk::pack::FileNode::setFileName(edk::char8* str){
    //clean the names
    this->cleanName();edkEnd();
    //test the string
    if(str){
        //set the string
        if(this->str.setName(str)){
            //get the fileName string
            edk::char8* temp = edk::String::strFileName(str);edkEnd();
            if(temp){
                //set the temp to the fileName
                if(this->fileName.setName(temp)){
                    free(temp);edkEnd();
                    return true;
                }
                free(temp);edkEnd();
            }
            this->str.cleanName();edkEnd();
        }
    }
    return false;
}
bool edk::pack::FileNode::setFileName(const edk::char8* str){
    return this->setFileName((edk::char8*) str);edkEnd();
}
//return the fileName
edk::char8* edk::pack::FileNode::getFileName(){
    return this->fileName.getName();edkEnd();
}
edk::char8* edk::pack::FileNode::getStrName(){
    return this->str.getName();edkEnd();
}
//clean the name
void edk::pack::FileNode::cleanName(){
    this->str.cleanName();edkEnd();
    this->fileName.cleanName();edkEnd();
}
void edk::pack::FileNode::clean(){
    this->cleanName();edkEnd();
    this->position = this->fileSize = 0u;edkEnd();
}

void edk::pack::FileNode::setPosition(edk::uint64 position){
    this->position = position;edkEnd();
}
edk::uint64 edk::pack::FileNode::getPosition(){
    return this->position;edkEnd();
}
void edk::pack::FileNode::setFileSize(edk::uint64 fileSize){
    this->fileSize = fileSize;edkEnd();
}
edk::uint64 edk::pack::FileNode::getFileSize(){
    return this->fileSize;edkEnd();
}

//return the size of the node
edk::uint64 edk::pack::FileNode::getSize(){
    return this->size();edkEnd();
}
edk::uint64 edk::pack::FileNode::size(){
    //return the node size
    return this->fileName.size()+1u + sizeof(this->fileName.size()) + sizeof(this->position) + sizeof(this->fileSize);edkEnd();
}

//return true if this fileNode is bigger then the other node
bool edk::pack::FileNode::biggerThan(edk::pack::FileNode* node){
    if(node){
        //test if the fileName is bigger
        if(this->fileName.nameBiggerThan(&node->fileName)){
            return true;
        }
    }
    return false;
}
bool edk::pack::FileNode::equalThan(edk::pack::FileNode* node){
    if(node){
        //test if the fileName are equal
        if(this->fileName.nameEqual(&node->fileName)){
            return true;
        }
    }
    return false;
}

void edk::pack::FileNode::print(){
    printf("\nNode size %lu:"
           ,this->getSize()
           );edkEnd();
    printf("\nName '%s' '%s'"
           ,this->str.getName()
           ,this->fileName.getName()
           );edkEnd();
    printf("\nposition %lu fileSize %lu"
           ,this->position
           ,this->fileSize
           );edkEnd();
    printf("\nMD5: ");edkEnd();this->printMD5(this->md5);edkEnd();
    fflush(stdout);edkEnd();
}

//write the node to the file
bool edk::pack::FileNode::writeFile(edk::File* file){
    //test the file
    if(file && this->fileName.size()){
        //write the nameSize
        file->writeBin(this->fileName.size());edkEnd();
        //write the string
        edk::uint32 size = this->fileName.size();edkEnd();
        file->writeBin(this->fileName.getName(),size);edkEnd();
        //file->writeBin(this->fileName.getName());edkEnd();
        //write the position and the size
        file->writeBin(this->position);edkEnd();
        file->writeBin(this->fileSize);edkEnd();
        file->writeBin(this->md5,sizeof(this->md5));edkEnd();
        return true;
    }
    return false;
}
bool edk::pack::FileNode::readFile(edk::File* file){
    this->clean();edkEnd();
    if(file){
        if(file->getFileSize()){
            if(!file->endOfFile()){
                //get the string size
                edk::uint32 strSize = file->readBinUInt32();edkEnd();
                //create a new string to copy
                edk::char8* temp = (edk::char8*)malloc(sizeof(edk::char8)*strSize+1u);edkEnd();
                if(temp){
                    temp[strSize] = '\0';edkEnd();
                    //read the string
                    file->readBin(temp,strSize);edkEnd();
                    //copy the string
                    this->setFileName(temp);edkEnd();
                    free(temp);edkEnd();
                }

                //read the position
                this->position = file->readBinUInt64();edkEnd();
                this->fileSize = file->readBinUInt64();edkEnd();
                //read the md5
                file->readBin(this->md5,sizeof(this->md5));edkEnd();

                return true;
            }
        }
    }
    return false;
}
