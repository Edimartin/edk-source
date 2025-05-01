#ifndef FILEPACKAGE_H
#define FILEPACKAGE_H

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

#ifdef printMessages
#pragma message "Inside pack::FilePackage"
#endif

#pragma once
#if defined(EDK_FILEPACK_PRINT_DEBUG)
#include "../DebugLineFile.h"
#endif
#include "../thread/Mutex.h"
#include "FileNode.h"
#include "../vector/BinaryTree.h"
#include "../encrypt/MD5.h"

#ifdef printMessages
#pragma message "    Compiling pack::FilePackage"
#endif

#define packBufferSize 1024u*10

namespace edk{
namespace pack{
class FilePackage{
public:
    FilePackage();
    virtual ~FilePackage();

    void Constructor();
    void Destructor();

    //set the debugFile Name
    static bool createDebugFile(const edk::char8* name);
    static bool createDebugFile(edk::char8* name);
    //close the debug file to not write the file
    static void closeDebugFile();

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

    //public mutex
    edk::multi::Mutex mutex;
private:
    edk::File file;
    edk::pack::FileNode* selected;
    //buffer to read the full files
    edk::uint8* buffer;
    edk::uint64 bufferSize;
    edk::uint64 bufferReadSize;
#if defined(EDK_FILEPACK_PRINT_DEBUG)
    static edk::DebugLineFile debugFile;
    static edk::multi::Mutex debugMut;
    static bool templateConstructNeed;
#endif

    //node tree
    class treeInt:public edk::vector::BinaryTree<edk::pack::FileNode*>{
    public:
        treeInt(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~treeInt(){
            this->Destructor();
        }

        void Constructor(){
            if(this->classThis!=this){
                this->classThis=this;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
                this->removeAllNodes();
            }
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
    private:
        edk::classID classThis;
    }tree;
    bool readNodeToBuffer(edk::pack::FileNode* node);
    //read the file bytes
    bool readNodeFile(edk::pack::FileNode* node,classID vec,uint64 size);
    //test if the buffer is valid with the node
    bool isBufferValid(edk::pack::FileNode* node);

#if defined(EDK_FILEPACK_PRINT_DEBUG)
    //write some command in the debugFile
    inline void writeDebug(edk::char8* text,edk::int32 line,edk::char8* file,edk::char8* function){
        //write this string into the file
        edk::pack::FilePackage::debugMut.lock();
        edk::pack::FilePackage::debugFile.writeDebug(text,line,file,function);
        edk::pack::FilePackage::debugMut.unlock();
    }
    inline void writeDebug(const edk::char8* text,edk::int32 line,const edk::char8* file,const edk::char8* function){
        this->writeDebug((edk::char8*) text,line,(edk::char8*) file,(edk::char8*) function);
    }
#endif
private:
    edk::classID classThis;
};
}
}

#endif // FILEPACKAGE_H
