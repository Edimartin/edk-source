#include "ServerSocket.h"

/*
Library ServerSocket - Socket Server for EDK
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

edk::network::ServerSocket::ServerSocket(){
    this->classThis=NULL;
    this->Constructor();
}
edk::network::ServerSocket::~ServerSocket(){
    this->Constructor();
}

void edk::network::ServerSocket::Constructor(){
    edk::network::Socket::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->tree.Constructor();
    }
}
void edk::network::ServerSocket::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
    edk::network::Socket::Destructor();
}

edk::network::ServerSocket::treeAdress::treeAdress(){
    this->classThis=NULL;
    this->Constructor();
}
edk::network::ServerSocket::treeAdress::~treeAdress(){
    this->Destructor();
}

void edk::network::ServerSocket::treeAdress::Constructor(){
    edk::vector::BinaryTree<nodeAdress*>::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::network::ServerSocket::treeAdress::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        //delete all the adresses
        this->deleteAllAdress();
    }
    edk::vector::BinaryTree<nodeAdress*>::Destructor();
}

//Add a adress to the tree
bool edk::network::ServerSocket::treeAdress::addAdress(edk::network::Adress host,struct sockaddr_in adress){
    //test the host
    if(host.getIP() && host.getPort()){
        //create new adress
        edk::network::ServerSocket::nodeAdress* node = new edk::network::ServerSocket::nodeAdress;
        if(node){
            //set the host and the adress
            node->host = host;
            node->adress = adress;
            //add the node in the tree
            if(this->add(node)){
                return true;
            }
            delete node;
        }
    }
    return false;
}
//get a adress in the tree
edk::network::ServerSocket::nodeAdress* edk::network::ServerSocket::treeAdress::getAdress(edk::network::Adress host){
    //find the adress
    edk::network::ServerSocket::nodeAdress find;
    find.host = host;
    return this->getElement(&find);
}
//remove one adress from the tree
bool edk::network::ServerSocket::treeAdress::removeAdress(edk::network::Adress host){
    //get Element
    edk::network::ServerSocket::nodeAdress* node = this->getAdress(host);
    if(node){
        //remove from the tree
        if(this->remove(node)){
            //delete the node
            delete node;
            //return true
            return true;
        }
    }
    return false;
}
//delete all Adresses
void edk::network::ServerSocket::treeAdress::deleteAllAdress(){
    edk::network::ServerSocket::nodeAdress* node = NULL;
    for(edk::uint32 i=0u;i<this->getSize();i++){
        node = this->getElementInPosition(i);
        if(node){
            delete node;
        }
        node=NULL;
    }
    this->clean();
}
//compare if the value is bigger
bool edk::network::ServerSocket::treeAdress::firstBiggerSecond(edk::network::ServerSocket::nodeAdress* first,
                                                               edk::network::ServerSocket::nodeAdress* second
                                                               ){
    if(first && second){
        if(first->host>second->host){
            //
            return true;
        }
    }
    return false;
}
bool edk::network::ServerSocket::treeAdress::firstEqualSecond(edk::network::ServerSocket::nodeAdress* first,
                                                              edk::network::ServerSocket::nodeAdress* second
                                                              ){
    if(first && second){
        if(first->host==second->host){
            //
            return true;
        }
    }
    return false;
}
