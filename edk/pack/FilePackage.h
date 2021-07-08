#ifndef FILEPACKAGE_H
#define FILEPACKAGE_H

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

#ifdef printMessages
#warning "Inside pack::FilePackage"
#endif

#pragma once
#include "FileNode.h"
#include "../vector/BinaryTree.h"
#include "../encrypt/MD5.h"

#ifdef printMessages
#warning "    Compiling pack::FilePackage"
#endif

#define packBufferSize 1024u*10

namespace edk{
namespace pack{
class FilePackage{
public:
    FilePackage();
    virtual ~FilePackage();

    //add a fileName to the tree
    bool addFileName(edk::char8* fileName);
    bool addFileName(const edk::char8* fileName);
    //remove the file from the tree
    bool removeFileName(edk::char8* fileName);
    bool removeFileName(const edk::char8* fileName);
    //get the fileName in position
    edk::char8* getFileName(edk::uint32 position);
    //remove all fileNames
    void removeAllNames();
    //return the files size
    edk::uint32 getFilesSize();

    //save all files in one package file
    bool savePackFile(edk::char8* fileName);
    bool savePackFile(const edk::char8* fileName);
    bool openPackFile(edk::char8* fileName);
    bool openPackFile(const edk::char8* fileName);
    void closePackFile();
    //go to read a file in the node
    bool goToFile(edk::char8* fileName);
    bool goToFile(const edk::char8* fileName);

    //read the file bytes
    bool readFile(classID vec,uint64 size);

    //red the file to the buffer
    bool readFileToBuffer();
    bool readFileToBuffer(edk::char8* fileName);
    //test if the buffer readed is valid
    bool isBufferValid(edk::char8* fileName);
    bool isBufferValid(const edk::char8* fileName);

    //test if all the files are valid
    bool isFilesValid();

    //delete the read buffer
    void deleteBuffer();

    //get the buffer and the buffer size
    edk::uint8* getBuffer();
    edk::uint64 getBufferSize();

    //get the size of the file inside the file pack
    edk::uint64 getFileSize(edk::char8* fileName);
    edk::uint64 getFileSize(const edk::char8* fileName);

    //return true if have the file
    bool haveFile(edk::char8* fileName);
    bool haveFile(const edk::char8* fileName);

    //print the names
    void printNames();
private:
    edk::File file;
    edk::pack::FileNode* selected;
    //buffer to read the full files
    edk::uint8* buffer;
    edk::uint64 bufferSize;
    edk::uint64 bufferReadSize;
    //node tree
    class treeInt:public edk::vector::BinaryTree<edk::pack::FileNode*>{
    public:
        treeInt(){}
        virtual ~treeInt(){
            this->removeAllNodes();
        }
        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::pack::FileNode* first,edk::pack::FileNode* second){
            if(first && second){
                if(first->biggerThan(second)){
                    //
                    return true;
                }
            }
            return false;
        }
        //compare if the value is equal
        virtual bool firstEqualSecond(edk::pack::FileNode* first,edk::pack::FileNode* second){
            if(first && second){
                if(first->equalThan(second)){
                    //
                    return true;
                }
            }
            return false;
        }
        //Print
        virtual void printElement(edk::pack::FileNode* value){
            if(value){
                value->print();
            }
        }
        //create a new node
        bool newNode(edk::char8* fileName){
            if(fileName){
                edk::pack::FileNode *node = this->getNode(fileName);
                if(!node){
                    //creat a new node
                    node = new edk::pack::FileNode;
                    if(node){
                        //set the fileName
                        if(node->setFileName(fileName)){
                            //add the fileName to the tree
                            if(this->add(node)){
                                return true;
                            }
                        }
                        delete node;
                    }
                }
            }
            return false;
        }
        //return the node from the fileName
        edk::pack::FileNode* getNode(edk::char8* fileName){
            edk::pack::FileNode node;
            if(node.setFileName(fileName)){
                return this->getElement(&node);
            }
            return NULL;
        }
        //remove the node from the tree
        bool removeNode(edk::char8* fileName){
            if(fileName){
                edk::pack::FileNode *node = this->getNode(fileName);
                if(node){
                    //remove the node from the tree
                    if(this->remove(node)){
                        //delete the node
                        delete node;
                        return true;
                    }
                }
            }
            return false;
        }
        void removeAllNodes(){
            edk::uint32 size = this->size();
            edk::pack::FileNode *node;
            for(edk::uint32 i=0u;i<size;i++){
                node = this->getElementInPosition(i);
                if(node){
                    delete node;
                }
            }
            this->clean();
        }
        //return true if have the node
        bool haveNode(edk::char8* fileName){
            edk::pack::FileNode node;
            if(node.setFileName(fileName)){
                return this->haveElement(&node);
            }
            return false;
        }
    }tree;
    bool readNodeToBuffer(edk::pack::FileNode* node);
    //read the file bytes
    bool readNodeFile(edk::pack::FileNode* node,classID vec,uint64 size);
    //test if the buffer is valid with the node
    bool isBufferValid(edk::pack::FileNode* node);
};
}
}

#endif // FILEPACKAGE_H
