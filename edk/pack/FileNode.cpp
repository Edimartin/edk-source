#include "FileNode.h"

edk::pack::FileNode::FileNode(){
    this->position = 0u;
    this->fileSize = 0u;
    //this->position = this->fileSize = 0u;
}
edk::pack::FileNode::~FileNode(){
    this->str.cleanName();
    this->fileName.cleanName();
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

                return true;
            }
        }
    }
    return false;
}
