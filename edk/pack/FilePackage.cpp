#include "FilePackage.h"

/*
FilePackage - Class used to save and open a file package with files inside.
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

edk::pack::FilePackage::FilePackage(){
    this->selected = NULL;edkEnd();
    this->buffer = NULL;edkEnd();
    this->bufferSize = 0u;edkEnd();
    this->bufferReadSize = 0u;edkEnd();
}
edk::pack::FilePackage::~FilePackage(){
    this->deleteBuffer();edkEnd();
    this->removeAllNames();edkEnd();
}
bool edk::pack::FilePackage::readNodeToBuffer(edk::pack::FileNode* node){
    this->bufferReadSize=0u;
    //test if have selected file
    if(node){
        //get the selected size
        edk::uint64 size = node->getFileSize();edkEnd();
        if(size){
            //test if the size is bigger then the buffer size
            if(size>this->bufferSize){
                //create a new buffer
                this->deleteBuffer();edkEnd();
                this->buffer = new edk::uint8[size];edkEnd();
                if(buffer){
                    this->bufferSize = size;edkEnd();
                }
            }
            //test if have the buffer
            if(this->buffer && this->bufferSize){
                //save the seek
                edk::uint64 seek = this->file.getSeek64();edkEnd();
                //seek to the file position to read
                this->file.seekStart(node->getPosition());edkEnd();
                bool ret = this->readNodeFile(node,this->buffer,size);edkEnd();
                if(ret){
                    this->bufferReadSize=size;edkEnd();
                }
                //return the seek
                this->file.seekStart(seek);edkEnd();
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
            return this->file.readBin(vec,size);edkEnd();
        }
    }
    return false;
}
//test if the buffer is valid with the node
bool edk::pack::FilePackage::isBufferValid(edk::pack::FileNode* node){
    if(node){
        //generate the buffer hash
        edk::uint8 md5[16u];edkEnd();
        if(edk::encrypt::MD5::convertTo((edk::char8*)this->buffer,this->bufferReadSize,md5)){
            //test if the md5 is equal to node md5
            return node->compareMD5(md5);edkEnd();
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
            return this->tree.newNode(fileName);edkEnd();
        }
    }
    return false;
}
bool edk::pack::FilePackage::addFileName(const edk::char8* fileName){
    return this->addFileName((edk::char8*) fileName);edkEnd();
}
//remove the file from the tree
bool edk::pack::FilePackage::removeFileName(edk::char8* fileName){
    this->selected = NULL;edkEnd();
    if(fileName){
        //remove the node from the tree
        return this->tree.removeNode(fileName);edkEnd();
    }
    return false;
}
bool edk::pack::FilePackage::removeFileName(const edk::char8* fileName){
    return this->removeFileName((edk::char8*) fileName);edkEnd();
}
//get the fileName in position
edk::char8* edk::pack::FilePackage::getFileName(edk::uint32 position){
    //get the node in position
    edk::pack::FileNode* node = this->tree.getElementInPosition(position);edkEnd();
    if(node){
        return node->getFileName();edkEnd();
    }
    return NULL;
}
//remove all fileNames
void edk::pack::FilePackage::removeAllNames(){
    this->selected = NULL;edkEnd();
    this->tree.removeAllNodes();edkEnd();
}
//return the files size
edk::uint32 edk::pack::FilePackage::getFilesSize(){
    return this->tree.size();edkEnd();
}
//save all files in one package file
bool edk::pack::FilePackage::savePackFile(edk::char8* fileName){
    this->selected = NULL;edkEnd();
    //test the fileName
    if(fileName){
        //create the file
        if(this->file.createAndOpenBinFile(fileName)){
            //read the node list
            edk::uint32 size = this->tree.size();edkEnd();
            edk::pack::FileNode* node;edkEnd();
            edk::uint8 md5[16u];edkEnd();
            edk::uint32 md5Size = 0u;edkEnd();
            edk::uint32 divide = (255u/15u);edkEnd();
            edk::uint8 buffer[packBufferSize];edkEnd();
            edk::uint64 bufferRead = 0u;edkEnd();
            bool success = true;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                node = this->tree.getElementInPosition(i);edkEnd();
                if(node){
                    if(node->getFileName() && node->getStrName()){
                        memset(md5,0u,sizeof(md5));edkEnd();
                        //generate the md5 from the fileName
                        edk::encrypt::MD5::convertTo(node->getFileName(),md5);edkEnd();
                        md5Size = *md5 % divide;edkEnd();
                        if(md5Size>sizeof(md5)){
                            md5Size = 15u;edkEnd();
                        }

                        //write the md5
                        for(edk::uint32 j = 0u;j<md5Size;j++){
                            this->file.writeBin(md5[j]);edkEnd();
                        }

                        //set the node md5
                        edk::encrypt::MD5::convertFileTo(node->getStrName(),node->md5);edkEnd();

                        //open and write the file
                        edk::File copy;edkEnd();
                        if(copy.openBinFile(node->getStrName())){
                            //set the values to the node
                            node->setPosition(this->file.getSeek64());edkEnd();
                            node->setFileSize(copy.getFileSize());edkEnd();
                            while((bufferRead = copy.getFileSize() - copy.getSeek64())){
                                //test if the buffer read is bigger then packBufferSize
                                if(bufferRead>packBufferSize){
                                    //read from the file
                                    copy.readBin(buffer,packBufferSize);edkEnd();
                                    //write the buffer
                                    this->file.writeBin(buffer,packBufferSize);edkEnd();
                                }
                                else{
                                    //read from the file
                                    copy.readBin(buffer,bufferRead);edkEnd();
                                    //write the buffer
                                    this->file.writeBin(buffer,bufferRead);edkEnd();
                                }
                            }
                            copy.closeFile();edkEnd();
                        }
                        else{
                            this->file.writeBin(0xFFFFFFFFFFFFFFFF);edkEnd();
                            success = false;edkEnd();
                            break;
                        }
                    }
                    else{
                        this->file.writeBin(0xFFFFFFFFFFFFFFFF);edkEnd();
                        success = false;edkEnd();
                        break;
                    }
                }
                else{
                    this->file.writeBin(0xFFFFFFFFFFFFFFFF);edkEnd();
                    success = false;edkEnd();
                    break;
                }
            }
            if(success){
                //get the nodes position
                edk::uint64 nodesPosition = this->file.getSeek64();edkEnd();
                //write the nodes
                for(edk::uint32 i=0u;i<size;i++){
                    node = this->tree.getElementInPosition(i);edkEnd();
                    if(node){
                        if(node->getFileName() && node->getStrName()){
                            if(!node->writeFile(&this->file)){
                                this->file.writeBin(0xFFFFFFFFFFFFFFFF);edkEnd();
                                success = false;edkEnd();
                            }
                        }
                        else{
                            this->file.writeBin(0xFFFFFFFFFFFFFFFF);edkEnd();
                            success = false;edkEnd();
                            break;
                        }
                    }
                    else{
                        this->file.writeBin(0xFFFFFFFFFFFFFFFF);edkEnd();
                        success = false;edkEnd();
                        break;
                    }
                }
                if(success){
                    //write the nodes position
                    this->file.writeBin(nodesPosition);edkEnd();
                }
            }
            this->file.closeFile();edkEnd();

            return success;edkEnd();
        }
    }
    return false;
}
bool edk::pack::FilePackage::savePackFile(const edk::char8* fileName){
    return this->savePackFile((edk::char8*) fileName);edkEnd();
}
bool edk::pack::FilePackage::openPackFile(edk::char8* fileName){
    this->selected = NULL;edkEnd();
    bool success = false;edkEnd();
    if(fileName){
        //
        //create the file
        if(this->file.openBinFile(fileName)){
            edk::pack::FileNode* node;edkEnd();
            edk::uint64 nodesPosition = 0u;edkEnd();
            success = true;edkEnd();
            if(this->file.getFileSize()>sizeof(nodesPosition)){
                //go to the end of the file to read 8 bytes
                edk::uint64 positionRead = this->file.getFileSize() - sizeof(nodesPosition);edkEnd();
                this->file.seek(positionRead);edkEnd();
                //read the position of the nodes in the file
                this->file.readBin(&nodesPosition,sizeof(nodesPosition));edkEnd();
                //test if the nodes is smaller then the file size
                if(nodesPosition < this->file.getFileSize()){
                    //go to the position of the first node
                    this->file.seekStart(nodesPosition);edkEnd();

                    //read the nodes
                    //printf("\n%lu",this->file.getSeek64());edkEnd();
                    while(this->file.getSeek64() < positionRead){
                        //create a new node
                        node = new edk::pack::FileNode;edkEnd();
                        if(node){
                            //ead the node
                            if(node->readFile(&this->file)){
                                //add the node in the tree
                                if(!this->tree.add(node)){
                                    delete node;edkEnd();
                                    success=false;edkEnd();
                                    break;
                                }
                            }
                            else{
                                delete node;edkEnd();
                                success=false;edkEnd();
                                break;
                            }
                        }
                    }
                }
                else{
                    success=false;edkEnd();
                }

            }
            else{
                success=false;edkEnd();
            }
            if(success){
                file.seekStart64();edkEnd();
            }
            else{
                file.closeFile();edkEnd();
            }
        }
    }
    return success;edkEnd();
}
bool edk::pack::FilePackage::openPackFile(const edk::char8* fileName){
    return this->openPackFile((edk::char8*) fileName);edkEnd();
}
void edk::pack::FilePackage::closePackFile(){
    this->selected = NULL;edkEnd();
    this->file.closeFile();edkEnd();
}
//go to read a file in the node
bool edk::pack::FilePackage::goToFile(edk::char8* fileName){
    //test if the string and if the file is opened
    if(fileName && this->file.isOpened()){
        //get the node
        edk::pack::FileNode* node = this->tree.getNode(fileName);edkEnd();
        if(node){
            if(node->getPosition() < file.getFileSize()){
                //seek to the file position to read
                this->file.seekStart(node->getPosition());edkEnd();

                this->selected = node;edkEnd();
                return true;
            }
        }
    }
    return false;
}
bool edk::pack::FilePackage::goToFile(const edk::char8* fileName){
    return this->goToFile((edk::char8*) fileName);edkEnd();
}
//read the file bytes
bool edk::pack::FilePackage::readFile(classID vec,uint64 size){
    //test if have a node selected
    if(this->selected && vec && size){
        //test if have the size to be readed
        if(size<=((this->selected->getFileSize()+ this->selected->getPosition()) - this->file.getSeek64() )){
            //read the file
            return this->file.readBin(vec,size);edkEnd();
        }
    }
    return false;
}

//red the file to the buffer
bool edk::pack::FilePackage::readFileToBuffer(){
    //test if have selected file
    if(this->selected){
        return this->readNodeToBuffer(this->selected);edkEnd();
    }
    return false;
}
bool edk::pack::FilePackage::readFileToBuffer(edk::char8* fileName){
    return this->readNodeToBuffer(this->tree.getNode(fileName));edkEnd();
}
//test if the buffer readed is valid
bool edk::pack::FilePackage::isBufferValid(edk::char8* fileName){
    if(fileName && this->buffer && this->bufferReadSize){
        //get the node
        edk::pack::FileNode* node = this->tree.getNode(fileName);edkEnd();
        return this->isBufferValid(node);edkEnd();
    }
    return false;
}
bool edk::pack::FilePackage::isBufferValid(const edk::char8* fileName){
    return this->isBufferValid((edk::char8*) fileName);edkEnd();
}

//test if all the files are valid
bool edk::pack::FilePackage::isFilesValid(){
    //test the files
    edk::uint32 size = this->tree.size();edkEnd();
    edk::pack::FileNode *node;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        node = this->tree.getElementInPosition(i);edkEnd();
        if(node){
            //load the node to the buffer
            if(this->readNodeToBuffer(node)){
                //test if the node is valid
                if(!this->isBufferValid(node)){
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    return true;
}

//delete the read buffer
void edk::pack::FilePackage::deleteBuffer(){
    if(this->buffer){
        delete[] this->buffer;edkEnd();
        this->buffer = NULL;edkEnd();
        this->bufferSize = 0u;edkEnd();
        this->bufferReadSize=0u;
    }
}

//get the buffer and the buffer size
edk::uint8* edk::pack::FilePackage::getBuffer(){
    return this->buffer;edkEnd();
}
edk::uint64 edk::pack::FilePackage::getBufferSize(){
    return this->bufferReadSize;edkEnd();
}

//get the size of the file inside the file pack
edk::uint64 edk::pack::FilePackage::getFileSize(edk::char8* fileName){
    if(fileName){
        //get the node
        edk::pack::FileNode* node = this->tree.getNode(fileName);edkEnd();
        if(node){
            return node->getFileSize();edkEnd();
        }
    }
    return 0L;edkEnd();
}
edk::uint64 edk::pack::FilePackage::getFileSize(const edk::char8* fileName){
    return this->getFileSize((edk::char8*) fileName);edkEnd();
}

//return true if have the file
bool edk::pack::FilePackage::haveFile(edk::char8* fileName){
    //test the name
    if(fileName){
        //test if have the node
        edk::pack::FileNode* node = this->tree.getNode(fileName);edkEnd();
        if(node){
            return true;
        }
    }
    return false;
}
bool edk::pack::FilePackage::haveFile(const edk::char8* fileName){
    return this->haveFile((edk::char8*) fileName);edkEnd();
}
//print the names
void edk::pack::FilePackage::printNames(){
    this->tree.print();edkEnd();
}
