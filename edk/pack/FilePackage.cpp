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

#if defined(EDK_FILEPACK_PRINT_DEBUG)
edk::DebugLineFile edk::pack::FilePackage::debugFile;
edk::multi::Mutex edk::pack::FilePackage::debugMut;
bool edk::pack::FilePackage::templateConstructNeed=true;
#endif

edk::pack::FilePackage::FilePackage(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::pack::FilePackage::~FilePackage(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->deleteBuffer();edkEnd();
        this->removeAllNames();edkEnd();
    }
}

void edk::pack::FilePackage::Constructor(bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;

        this->tree.Constructor();edkEnd();
        this->mutex.Constructor();edkEnd();
        this->file.Constructor();edkEnd();

#if defined(EDK_FILEPACK_PRINT_DEBUG)
        if(edk::pack::FilePackage::templateConstructNeed){
            edk::pack::FilePackage::debugFile.Constructor();
            edk::pack::FilePackage::debugMut.Constructor();
            edk::pack::FilePackage::templateConstructNeed=false;
        }
#endif
        this->selected = NULL;edkEnd();
        this->buffer = NULL;edkEnd();
        this->bufferSize = 0u;edkEnd();
        this->bufferReadSize = 0u;edkEnd();
    }
}

//set the debugFile Name
bool edk::pack::FilePackage::createDebugFile(const edk::char8* name){
    return edk::pack::FilePackage::createDebugFile((edk::char8*) name);
}
bool edk::pack::FilePackage::createDebugFile(edk::char8* name){
    if(name){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
        bool ret=false;
        edk::pack::FilePackage::debugMut.lock();
        edk::pack::FilePackage::debugFile.closeFile();
        ret = edk::pack::FilePackage::debugFile.createFile(name);
        edk::pack::FilePackage::debugMut.unlock();
        return ret;
#else
        return true;
#endif
    }
    return false;
}
//close the debug file to not write the file
void edk::pack::FilePackage::closeDebugFile(){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    edk::pack::FilePackage::debugMut.lock();
    edk::pack::FilePackage::debugFile.closeFile();
    edk::pack::FilePackage::debugMut.unlock();
#endif
}

bool edk::pack::FilePackage::readNodeToBuffer(edk::pack::FileNode* node){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug(node?"Node TRUE":"Node NULL",__LINE__,__FILE__,__func__);
#endif
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
                this->buffer = (edk::uint8*)malloc(sizeof(edk::uint8) * (size));edkEnd();
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
#if defined(EDK_FILEPACK_PRINT_DEBUG)
                this->debugFile.writeDebug(ret?"    OK":"    NOTOK",__LINE__,__FILE__,__func__);
#endif
                return ret;
            }
        }
    }
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug("    NOTOK",__LINE__,__FILE__,__func__);
#endif
    return false;
}
//read the file bytes
bool edk::pack::FilePackage::readNodeFile(edk::pack::FileNode* node,classID vec,uint64 size){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    edk::char8* strSize = edk::String::uint64ToStr(size);
    if(strSize){
        edk::char8* strVec = edk::String::uint64ToStr((edk::uint64)vec);
        if(strVec){
            edk::char8* str = edk::String::strCatMulti(node?"Node True":"Node NULL"," vec[",strVec,"] size[",strSize,"]",NULL);
            if(str){
                this->debugFile.writeDebug(str,__LINE__,__FILE__,__func__);
                free(str);
            }
            free(strVec);
        }
        free(strSize);
    }
#endif
    //test if have a node selected
    if(node && vec && size){
        //test if have the size to be readed
        if(size<=((node->getFileSize()+ node->getPosition()) - this->file.getSeek64() )){
            //read the file
            bool ret = this->file.readBin(vec,size);edkEnd();
#if defined(EDK_FILEPACK_PRINT_DEBUG)
            this->debugFile.writeDebug(ret?"    OK":"    NOTOK",__LINE__,__FILE__,__func__);
#endif
            return ret;
        }
    }
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug("    NOTOK",__LINE__,__FILE__,__func__);
#endif
    return false;
}
//test if the buffer is valid with the node
bool edk::pack::FilePackage::isBufferValid(edk::pack::FileNode* node){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug(node?"node TRUE":"node NULL",__LINE__,__FILE__,__func__);
#endif
    if(node){
        //generate the buffer hash
        edk::uint8 md5[16u];edkEnd();
        if(edk::encrypt::MD5::convertTo((edk::char8*)this->buffer,this->bufferReadSize,md5)){
            //test if the md5 is equal to node md5
            bool ret = node->compareMD5(md5);edkEnd();
#if defined(EDK_FILEPACK_PRINT_DEBUG)
            this->debugFile.writeDebug(ret?"    OK":"    NOTOK",__LINE__,__FILE__,__func__);
#endif
            return ret;
        }
    }
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug("    NOTOK",__LINE__,__FILE__,__func__);
#endif
    return false;
}


//add a fileName to the tree
bool edk::pack::FilePackage::addFileName(edk::char8* fileName){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug(fileName?fileName:"fileName NULL",__LINE__,__FILE__,__func__);
#endif
    //test the fileName
    if(fileName){
        //test if have the file
        if(edk::File::fileExist(fileName)){
            //create a new node
            bool ret = this->tree.newNode(fileName);edkEnd();
#if defined(EDK_FILEPACK_PRINT_DEBUG)
            this->debugFile.writeDebug(ret?"    OK":"    NOTOK",__LINE__,__FILE__,__func__);
#endif
            return ret;
        }
    }
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug("    NOTOK",__LINE__,__FILE__,__func__);
#endif
    return false;
}
bool edk::pack::FilePackage::addFileName(const edk::char8* fileName){
    return this->addFileName((edk::char8*) fileName);edkEnd();
}
//remove the file from the tree
bool edk::pack::FilePackage::removeFileName(edk::char8* fileName){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug(fileName?fileName:"fileName NULL",__LINE__,__FILE__,__func__);
#endif
    this->selected = NULL;edkEnd();
    if(fileName){
        //remove the node from the tree
        bool ret = this->tree.removeNode(fileName);edkEnd();
#if defined(EDK_FILEPACK_PRINT_DEBUG)
        this->debugFile.writeDebug(ret?"    OK":"    NOTOK",__LINE__,__FILE__,__func__);
#endif
        return ret;
    }
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug("    NOTOK",__LINE__,__FILE__,__func__);
#endif
    return false;
}
bool edk::pack::FilePackage::removeFileName(const edk::char8* fileName){
    return this->removeFileName((edk::char8*) fileName);edkEnd();
}
//get the fileName in position
edk::char8* edk::pack::FilePackage::getFileName(edk::uint32 position){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    edk::char8* strSize = edk::String::uint64ToStr(position);
    if(strSize){
        edk::char8* str = edk::String::strCatMulti("position[",strSize,"]",NULL);
        if(str){
            this->debugFile.writeDebug(str,__LINE__,__FILE__,__func__);
            free(str);
        }
        free(strSize);
    }
#endif
    //get the node in position
    edk::pack::FileNode* node = this->tree.getElementInPosition(position);edkEnd();
    if(node){
        return node->getFileName();edkEnd();
    }
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug("Return NULL;",__LINE__,__FILE__,__func__);
#endif
    return NULL;
}
//remove all fileNames
void edk::pack::FilePackage::removeAllNames(){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    edk::char8* strSize = edk::String::uint64ToStr(this->tree.size());
    if(strSize){
        edk::char8* str = edk::String::strCatMulti("tree.size[",strSize,"]",NULL);
        if(str){
            this->debugFile.writeDebug(str,__LINE__,__FILE__,__func__);
            free(str);
        }
        free(strSize);
    }
#endif
    this->selected = NULL;edkEnd();
    this->tree.removeAllNodes();edkEnd();
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug("END",__LINE__,__FILE__,__func__);
#endif
}
//return the files size
edk::uint32 edk::pack::FilePackage::getFilesSize(){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    edk::char8* strSize = edk::String::uint64ToStr(this->tree.size());
    if(strSize){
        edk::char8* str = edk::String::strCatMulti("tree.size[",strSize,"]",NULL);
        if(str){
            this->debugFile.writeDebug(str,__LINE__,__FILE__,__func__);
            free(str);
        }
        free(strSize);
    }
#endif
    return this->tree.size();edkEnd();
}
//save all files in one package file
bool edk::pack::FilePackage::savePackFile(edk::char8* fileName){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug(fileName?fileName:"fileName NULL",__LINE__,__FILE__,__func__);
#endif
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

#if defined(EDK_FILEPACK_PRINT_DEBUG)
            this->debugFile.writeDebug(success?"return success TRUE;":"return success FALSE;",__LINE__,__FILE__,__func__);
#endif
            return success;edkEnd();
        }
    }
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug("return FALSE;",__LINE__,__FILE__,__func__);
#endif
    return false;
}
bool edk::pack::FilePackage::savePackFile(const edk::char8* fileName){
    return this->savePackFile((edk::char8*) fileName);edkEnd();
}
bool edk::pack::FilePackage::openPackFile(edk::char8* fileName){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug(fileName?fileName:"fileName NULL",__LINE__,__FILE__,__func__);
#endif
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
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug(success?"return success TRUE;":"return success FALSE;",__LINE__,__FILE__,__func__);
#endif
    return success;edkEnd();
}
bool edk::pack::FilePackage::openPackFile(const edk::char8* fileName){
    return this->openPackFile((edk::char8*) fileName);edkEnd();
}
void edk::pack::FilePackage::closePackFile(){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug(this->file.getName()?this->file.getName():"fileName NULL",__LINE__,__FILE__,__func__);
#endif
    this->selected = NULL;edkEnd();
    this->file.closeFile();edkEnd();
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug("END",__LINE__,__FILE__,__func__);
#endif
}
//go to read a file in the node
bool edk::pack::FilePackage::goToFile(edk::char8* fileName){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug(fileName?fileName:"NULL",__LINE__,__FILE__,__func__);
#endif
    //test if the string and if the file is opened
    if(fileName && this->file.isOpened()){
        //get the node
        edk::pack::FileNode* node = this->tree.getNode(fileName);edkEnd();
        if(node){
            if(node->getPosition() < file.getFileSize()){
                //seek to the file position to read
                this->file.seekStart(node->getPosition());edkEnd();

                this->selected = node;edkEnd();
#if defined(EDK_FILEPACK_PRINT_DEBUG)
                this->debugFile.writeDebug("    OK",__LINE__,__FILE__,__func__);
#endif
                return true;
            }
        }
    }
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug("    NOTOK",__LINE__,__FILE__,__func__);
#endif
    return false;
}
bool edk::pack::FilePackage::goToFile(const edk::char8* fileName){
    return this->goToFile((edk::char8*) fileName);edkEnd();
}
//read the file bytes
bool edk::pack::FilePackage::readFile(classID vec,uint64 size){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    edk::char8* strSize = edk::String::uint64ToStr(size);
    if(strSize){
        edk::char8* str;
        if(vec){
            str = edk::String::strCatMulti("VEC size[",strSize,"]",NULL);
            if(str){
                this->debugFile.writeDebug(str,__LINE__,__FILE__,__func__);
                free(str);
            }
        }
        else{
            str = edk::String::strCatMulti("VEC[NULL] size[",strSize,"]",NULL);
            if(str){
                this->debugFile.writeDebug(str,__LINE__,__FILE__,__func__);
                free(str);
            }
        }
        free(strSize);
    }
#endif
    //test if have a node selected
    if(this->selected && vec && size){
        //test if have the size to be readed
        if(size<=((this->selected->getFileSize()+ this->selected->getPosition()) - this->file.getSeek64() )){
            //read the file
            bool ret = this->file.readBin(vec,size);edkEnd();
#if defined(EDK_FILEPACK_PRINT_DEBUG)
            this->debugFile.writeDebug(ret?"    OK":"    NOTOK",__LINE__,__FILE__,__func__);
#endif
            return ret;
        }
    }
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug("    NOTOK",__LINE__,__FILE__,__func__);
#endif
    return false;
}

//red the file to the buffer
bool edk::pack::FilePackage::readFileToBuffer(){
    //test if have selected file
    if(this->selected){
        bool ret = this->readNodeToBuffer(this->selected);edkEnd();
#if defined(EDK_FILEPACK_PRINT_DEBUG)
        this->debugFile.writeDebug(ret?"    OK":"    NOTOK",__LINE__,__FILE__,__func__);
#endif
        return ret;
    }
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug("    NOTOK",__LINE__,__FILE__,__func__);
#endif
    return false;
}
bool edk::pack::FilePackage::readFileToBuffer(edk::char8* fileName){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug(fileName?fileName:"NULL",__LINE__,__FILE__,__func__);
#endif
    bool ret = this->readNodeToBuffer(this->tree.getNode(fileName));edkEnd();
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug(ret?"    OK":"    NOTOK",__LINE__,__FILE__,__func__);
#endif
    return ret;
}
//test if the buffer readed is valid
bool edk::pack::FilePackage::isBufferValid(edk::char8* fileName){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug(fileName?fileName:"NULL",__LINE__,__FILE__,__func__);
#endif
    if(fileName && this->buffer && this->bufferReadSize){
        //get the node
        edk::pack::FileNode* node = this->tree.getNode(fileName);edkEnd();
        bool ret = this->isBufferValid(node);edkEnd();
#if defined(EDK_FILEPACK_PRINT_DEBUG)
        this->debugFile.writeDebug(ret?"    OK":"    NOTOK",__LINE__,__FILE__,__func__);
#endif
        return ret;
    }
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug("    NOTOK",__LINE__,__FILE__,__func__);
#endif
    return false;
}
bool edk::pack::FilePackage::isBufferValid(const edk::char8* fileName){
    return this->isBufferValid((edk::char8*) fileName);edkEnd();
}

//test if all the files are valid
bool edk::pack::FilePackage::isFilesValid(){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    edk::char8* strSize = edk::String::uint32ToStr(this->tree.size());
    if(strSize){
        edk::char8* str = edk::String::strCatMulti("size == ",strSize,NULL);
        if(str){
            this->debugFile.writeDebug(str,__LINE__,__FILE__,__func__);
            free(str);
        }
        free(strSize);
    }
#endif
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
#if defined(EDK_FILEPACK_PRINT_DEBUG)
                    this->debugFile.writeDebug("    NOTOK",__LINE__,__FILE__,__func__);
#endif
                    return false;
                }
            }
            else{
#if defined(EDK_FILEPACK_PRINT_DEBUG)
                this->debugFile.writeDebug("    NOTOK",__LINE__,__FILE__,__func__);
#endif
                return false;
            }
        }
    }
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug("    OK",__LINE__,__FILE__,__func__);
#endif
    return true;
}

//delete the read buffer
void edk::pack::FilePackage::deleteBuffer(){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug(this->buffer?"Buffer TRUE":"Buffer NULL",__LINE__,__FILE__,__func__);
#endif
    if(this->buffer){
        free(this->buffer);edkEnd();
        this->buffer = NULL;edkEnd();
        this->bufferSize = 0u;edkEnd();
        this->bufferReadSize=0u;
#if defined(EDK_FILEPACK_PRINT_DEBUG)
        this->debugFile.writeDebug("    OK",__LINE__,__FILE__,__func__);
#endif
    }
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    else{
        this->debugFile.writeDebug("    NOTOK",__LINE__,__FILE__,__func__);
    }
#endif
}

//get the buffer and the buffer size
edk::uint8* edk::pack::FilePackage::getBuffer(){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug(this->buffer?"Buffer TRUE":"Buffer NULL",__LINE__,__FILE__,__func__);
#endif
    return this->buffer;edkEnd();
}
edk::uint64 edk::pack::FilePackage::getBufferSize(){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    edk::char8* strSize = edk::String::uint64ToStr(this->bufferReadSize);
    if(strSize){
        edk::char8* str = edk::String::strCatMulti("this->bufferReadSize[",strSize,"]",NULL);
        if(str){
            this->debugFile.writeDebug(str,__LINE__,__FILE__,__func__);
            free(str);
        }
        free(strSize);
    }
#endif
    return this->bufferReadSize;edkEnd();
}

//get the size of the file inside the file pack
edk::uint64 edk::pack::FilePackage::getFileSize(edk::char8* fileName){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug(fileName?fileName:"fileName NULL",__LINE__,__FILE__,__func__);
#endif
    if(fileName){
        //get the node
        edk::pack::FileNode* node = this->tree.getNode(fileName);edkEnd();
        if(node){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
            edk::char8* strSize = edk::String::uint64ToStr(node->getFileSize());
            if(strSize){
                edk::char8* str = edk::String::strCatMulti("return ",strSize,";",NULL);
                if(strSize){
                    this->debugFile.writeDebug(str,__LINE__,__FILE__,__func__);
                    free(str);
                }
            }
#endif
            return node->getFileSize();edkEnd();
        }
    }
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug("return 0L;",__LINE__,__FILE__,__func__);
#endif
    return 0L;
}
edk::uint64 edk::pack::FilePackage::getFileSize(const edk::char8* fileName){
    return this->getFileSize((edk::char8*) fileName);edkEnd();
}

//return true if have the file
bool edk::pack::FilePackage::haveFile(edk::char8* fileName){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug(fileName?fileName:"fileName NULL",__LINE__,__FILE__,__func__);
#endif
    //test the name
    if(fileName){
        //test if have the node
        edk::pack::FileNode* node = this->tree.getNode(fileName);edkEnd();
        if(node){
#if defined(EDK_FILEPACK_PRINT_DEBUG)
            this->debugFile.writeDebug("    OK",__LINE__,__FILE__,__func__);
#endif
            return true;
        }
    }
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    this->debugFile.writeDebug("    NOTOK",__LINE__,__FILE__,__func__);
#endif
    return false;
}
bool edk::pack::FilePackage::haveFile(const edk::char8* fileName){
    return this->haveFile((edk::char8*) fileName);edkEnd();
}
//print the names
void edk::pack::FilePackage::printNames(){
    this->tree.print();edkEnd();
}
