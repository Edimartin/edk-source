#include "FileNode.h"

/*
FileNode - Node used in FilePackage with the Name, position and size of the file inside the package.
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

edk::pack::FileNode::FileNode(){
    this->position = 0u;
    this->fileSize = 0u;
    //this->position = this->fileSize = 0u;
    this->cleanMD5();
}
edk::pack::FileNode::~FileNode(){
    this->str.cleanName();
    this->fileName.cleanName();
}
//clean the md5 code
void edk::pack::FileNode::cleanMD5(){
    memset(this->md5,0u,sizeof(this->md5));
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
        printf("%02x",(edk::uint8)md5[i]);
    }
    fflush(stdout);
}

//set the fileName
bool edk::pack::FileNode::setFileName(edk::char8* str){
    //clean the names
    this->cleanName();
    //test the string
    if(str){
        //set the string
        if(this->str.setName(str)){
            //get the fileName string
            edk::char8* temp = edk::String::strFileName(str);
            if(temp){
                //set the temp to the fileName
                if(this->fileName.setName(temp)){
                    delete[] temp;
                    return true;
                }
                delete[] temp;
            }
            this->str.cleanName();
        }
    }
    return false;
}
bool edk::pack::FileNode::setFileName(const edk::char8* str){
    return this->setFileName((edk::char8*) str);
}
//return the fileName
edk::char8* edk::pack::FileNode::getFileName(){
    return this->fileName.getName();
}
edk::char8* edk::pack::FileNode::getStrName(){
    return this->str.getName();
}
//clean the name
void edk::pack::FileNode::cleanName(){
    this->str.cleanName();
    this->fileName.cleanName();
}
void edk::pack::FileNode::clean(){
    this->cleanName();
    this->position = this->fileSize = 0u;
}

void edk::pack::FileNode::setPosition(edk::uint64 position){
    this->position = position;
}
edk::uint64 edk::pack::FileNode::getPosition(){
    return this->position;
}
void edk::pack::FileNode::setFileSize(edk::uint64 fileSize){
    this->fileSize = fileSize;
}
edk::uint64 edk::pack::FileNode::getFileSize(){
    return this->fileSize;
}

//return the size of the node
edk::uint64 edk::pack::FileNode::getSize(){
    return this->size();
}
edk::uint64 edk::pack::FileNode::size(){
    //return the node size
    return this->fileName.size()+1u + sizeof(this->fileName.size()) + sizeof(this->position) + sizeof(this->fileSize);
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
           );
    printf("\nName '%s' '%s'"
           ,this->str.getName()
           ,this->fileName.getName()
           );
    printf("\nposition %lu fileSize %lu"
           ,this->position
           ,this->fileSize
           );
    printf("\nMD5: ");this->printMD5(this->md5);
    fflush(stdout);
}

//write the node to the file
bool edk::pack::FileNode::writeFile(edk::File* file){
    //test the file
    if(file && this->fileName.size()){
        //write the nameSize
        file->writeBin(this->fileName.size());
        //write the string
        edk::uint32 size = this->fileName.size();
        file->writeBin(this->fileName.getName(),size);
        //file->writeBin(this->fileName.getName());
        //write the position and the size
        file->writeBin(this->position);
        file->writeBin(this->fileSize);
        file->writeBin(this->md5,sizeof(this->md5));
        return true;
    }
    return false;
}
bool edk::pack::FileNode::readFile(edk::File* file){
    this->clean();
    if(file){
        if(file->getFileSize()){
            if(!file->endOfFile()){
                //get the string size
                edk::uint32 strSize = file->readBinUInt32();
                //create a new string to copy
                edk::char8* temp = new char[strSize+1u];
                if(temp){
                    temp[strSize] = '\0';
                    //read the string
                    file->readBin(temp,strSize);
                    //copy the string
                    this->setFileName(temp);
                    delete temp;
                }

                //read the position
                this->position = file->readBinUInt64();
                this->fileSize = file->readBinUInt64();
                //read the md5
                file->readBin(this->md5,sizeof(this->md5));

                return true;
            }
        }
    }
    return false;
}
