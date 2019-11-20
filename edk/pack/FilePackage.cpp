#include "FilePackage.h"

/*
FilePackage - Class used to save and open a file package with files inside.
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

edk::pack::FilePackage::FilePackage(){
    this->selected = NULL;
    this->buffer = NULL;
    this->bufferSize = 0u;
    this->bufferReadSize = 0u;
}
edk::pack::FilePackage::~FilePackage(){
    this->deleteBuffer();
    this->removeAllNames();
}
bool edk::pack::FilePackage::readNodeToBuffer(edk::pack::FileNode* node){
    this->bufferReadSize=0u;
    //test if have selected file
    if(node){
        //get the selected size
        edk::uint64 size = node->getFileSize();
        if(size){
            //test if the size is bigger then the buffer size
            if(size>this->bufferSize){
                //create a new buffer
                this->deleteBuffer();
                this->buffer = new edk::char8[size];
                if(buffer){
                    this->bufferSize = size;
                }
            }
            //test if have the buffer
            if(this->buffer && this->bufferSize){
                //save the seek
                edk::uint64 seek = this->file.getSeek64();
                //seek to the file position to read
                this->file.seekStart(node->getPosition());
                bool ret = this->readNodeFile(node,this->buffer,size);
                if(ret){
                    this->bufferReadSize=size;
                }
                //return the seek
                this->file.seekStart(seek);
                return ret;
            }
        }
    }
    return false;
}
//read the file bytes
bool edk::pack::FilePackage::readNodeFile(edk::pack::FileNode* node,classID vec,uint64 size){
    //test if have a node selected
    if(node && vec && size){
        //test if have the size to be readed
        if(size<=((node->getFileSize()+ node->getPosition()) - this->file.getSeek64() )){
            //read the file
            return this->file.readBin(vec,size);
        }
    }
    return false;
}

//add a fileName to the tree
bool edk::pack::FilePackage::addFileName(edk::char8* fileName){
    //test the fileName
    if(fileName){
        //test if have the file
        if(edk::File::fileExist(fileName)){
            //create a new node
            return this->tree.newNode(fileName);
        }
    }
    return false;
}
bool edk::pack::FilePackage::addFileName(const edk::char8* fileName){
    return this->addFileName((edk::char8*) fileName);
}
//remove the file from the tree
bool edk::pack::FilePackage::removeFileName(edk::char8* fileName){
    this->selected = NULL;
    if(fileName){
        //remove the node from the tree
        return this->tree.removeNode(fileName);
    }
    return false;
}
bool edk::pack::FilePackage::removeFileName(const edk::char8* fileName){
    return this->removeFileName((edk::char8*) fileName);
}
//get the fileName in position
edk::char8* edk::pack::FilePackage::getFileName(edk::uint32 position){
    //get the node in position
    edk::pack::FileNode* node = this->tree.getElementInPosition(position);
    if(node){
        return node->getFileName();
    }
    return NULL;
}
//remove all fileNames
void edk::pack::FilePackage::removeAllNames(){
    this->selected = NULL;
    this->tree.removeAllNodes();
}
//return the files size
edk::uint32 edk::pack::FilePackage::getFilesSize(){
    return this->tree.size();
}
//save all files in one package file
bool edk::pack::FilePackage::savePackFile(edk::char8* fileName){
    this->selected = NULL;
    //test the fileName
    if(fileName){
        //create the file
        if(this->file.createAndOpenBinFile(fileName)){
            //read the node list
            edk::uint32 size = this->tree.size();
            edk::pack::FileNode* node;
            edk::uint8 md5[16u];
            edk::uint32 md5Size = 0u;
            edk::uint32 divide = (255u/15u);
            edk::uint8 buffer[packBufferSize];
            edk::uint64 bufferRead = 0u;
            bool success = true;
            for(edk::uint32 i=0u;i<size;i++){
                node = this->tree.getElementInPosition(i);
                if(node){
                    if(node->getFileName() && node->getStrName()){
                        memset(md5,0u,sizeof(md5));
                        //generate the md5 from the fileName
                        edk::encrypt::MD5::convertTo(node->getFileName(),md5);
                        md5Size = *md5 % divide;
                        if(md5Size>sizeof(md5)){
                            md5Size = 15u;
                        }

                        //write the md5
                        for(edk::uint32 j = 0u;j<md5Size;j++){
                            this->file.writeBin(md5[j]);
                        }

                        //open and write the file
                        edk::File copy;
                        if(copy.openBinFile(node->getStrName())){
                            //set the values to the node
                            node->setPosition(this->file.getSeek64());
                            node->setFileSize(copy.getFileSize());
                            while((bufferRead = copy.getFileSize() - copy.getSeek64())){
                                //test if the buffer read is bigger then packBufferSize
                                if(bufferRead>packBufferSize){
                                    //read from the file
                                    copy.readBin(buffer,packBufferSize);
                                    //write the buffer
                                    this->file.writeBin(buffer,packBufferSize);
                                }
                                else{
                                    //read from the file
                                    copy.readBin(buffer,bufferRead);
                                    //write the buffer
                                    this->file.writeBin(buffer,bufferRead);
                                }
                            }
                            copy.closeFile();
                        }
                        else{
                            this->file.writeBin(0xFFFFFFFFFFFFFFFF);
                            success = false;
                            break;
                        }
                    }
                    else{
                        this->file.writeBin(0xFFFFFFFFFFFFFFFF);
                        success = false;
                        break;
                    }
                }
                else{
                    this->file.writeBin(0xFFFFFFFFFFFFFFFF);
                    success = false;
                    break;
                }
            }
            if(success){
                //get the nodes position
                edk::uint64 nodesPosition = this->file.getSeek64();
                //write the nodes
                for(edk::uint32 i=0u;i<size;i++){
                    node = this->tree.getElementInPosition(i);
                    if(node){
                        if(node->getFileName() && node->getStrName()){
                            if(!node->writeFile(&this->file)){
                                this->file.writeBin(0xFFFFFFFFFFFFFFFF);
                                success = false;
                            }
                        }
                        else{
                            this->file.writeBin(0xFFFFFFFFFFFFFFFF);
                            success = false;
                            break;
                        }
                    }
                    else{
                        this->file.writeBin(0xFFFFFFFFFFFFFFFF);
                        success = false;
                        break;
                    }
                }
                if(success){
                    //write the nodes position
                    this->file.writeBin(nodesPosition);
                }
            }
            this->file.closeFile();

            return success;
        }
    }
    return false;
}
bool edk::pack::FilePackage::savePackFile(const edk::char8* fileName){
    return this->savePackFile((edk::char8*) fileName);
}
bool edk::pack::FilePackage::openPackFile(edk::char8* fileName){
    this->selected = NULL;
    bool success = false;
    if(fileName){
        //
        //create the file
        if(this->file.openBinFile(fileName)){
            edk::pack::FileNode* node;
            edk::uint64 nodesPosition = 0u;
            success = true;
            if(this->file.getFileSize()>sizeof(nodesPosition)){
                //go to the end of the file to read 8 bytes
                edk::uint64 positionRead = this->file.getFileSize() - sizeof(nodesPosition);
                this->file.seek(positionRead);
                //read the position of the nodes in the file
                this->file.readBin(&nodesPosition,sizeof(nodesPosition));
                //test if the nodes is smaller then the file size
                if(nodesPosition < this->file.getFileSize()){
                    //go to the position of the first node
                    this->file.seekStart(nodesPosition);

                    //read the nodes
                    //printf("\n%lu",this->file.getSeek64());fflush(stdout);
                    while(this->file.getSeek64() < positionRead){
                        //create a new node
                        node = new edk::pack::FileNode;
                        if(node){
                            //ead the node
                            if(node->readFile(&this->file)){
                                //add the node in the tree
                                if(!this->tree.add(node)){
                                    delete node;
                                    success=false;
                                    break;
                                }
                            }
                            else{
                                delete node;
                                success=false;
                                break;
                            }
                        }
                    }
                }
                else{
                    success=false;
                }

            }
            else{
                success=false;
            }
            if(success)
                file.seekStart64();
            else
                file.closeFile();
        }
    }
    return success;
}
bool edk::pack::FilePackage::openPackFile(const edk::char8* fileName){
    return this->openPackFile((edk::char8*) fileName);
}
void edk::pack::FilePackage::closePackFile(){
    this->selected = NULL;
    this->file.closeFile();
}
//go to read a file in the node
bool edk::pack::FilePackage::goToFile(edk::char8* fileName){
    //test if the string and if the file is opened
    if(fileName && this->file.isOpened()){
        //get the node
        edk::pack::FileNode* node = this->tree.getNode(fileName);
        if(node){
            if(node->getPosition() < file.getFileSize()){
                //seek to the file position to read
                this->file.seekStart(node->getPosition());

                this->selected = node;
                return true;
            }
        }
    }
    return false;
}
bool edk::pack::FilePackage::goToFile(const edk::char8* fileName){
    return this->goToFile((edk::char8*) fileName);
}
//read the file bytes
bool edk::pack::FilePackage::readFile(classID vec,uint64 size){
    //test if have a node selected
    if(this->selected && vec && size){
        //test if have the size to be readed
        if(size<=((this->selected->getFileSize()+ this->selected->getPosition()) - this->file.getSeek64() )){
            //read the file
            return this->file.readBin(vec,size);
        }
    }
    return false;
}

//red the file to the buffer
bool edk::pack::FilePackage::readFileToBuffer(){
    //test if have selected file
    if(this->selected){
        return this->readNodeToBuffer(this->selected);
    }
    return false;
}
bool edk::pack::FilePackage::readFileToBuffer(edk::char8* fileName){
    return this->readNodeToBuffer(this->tree.getNode(fileName));
}

//delete the read buffer
void edk::pack::FilePackage::deleteBuffer(){
    if(this->buffer){
        delete[] this->buffer;
        this->buffer = NULL;
        this->bufferSize = 0u;
        this->bufferReadSize=0u;
    }
}

//get the buffer and the buffer size
edk::char8* edk::pack::FilePackage::getBuffer(){
    return this->buffer;
}
edk::uint64 edk::pack::FilePackage::getBufferSize(){
    return this->bufferReadSize;
}

//get the size of the file inside the file pack
edk::uint64 edk::pack::FilePackage::getFileSize(edk::char8* fileName){
    if(fileName){
        //get the node
        edk::pack::FileNode* node = this->tree.getNode(fileName);
        if(node){
            return node->getFileSize();
        }
    }
    return 0L;
}
edk::uint64 edk::pack::FilePackage::getFileSize(const edk::char8* fileName){
    return this->getFileSize((edk::char8*) fileName);
}
//print the names
void edk::pack::FilePackage::printNames(){
    this->tree.print();
}
