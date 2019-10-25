#ifndef FILEPACKAGE_H
#define FILEPACKAGE_H

#include "FileNode.h"
#include "../vector/BinaryTree.h"
#include "../encrypt/MD5.h"

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
    //remove all fileNames
    void removeAllNames();

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

    //get the size of the file inside the file pack
    edk::uint64 getFileSize(edk::char8* fileName);
    edk::uint64 getFileSize(const edk::char8* fileName);

    //print the names
    void printNames();

private:
    edk::File file;
    edk::pack::FileNode* selected;
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
};
}
}

#endif // FILEPACKAGE_H
