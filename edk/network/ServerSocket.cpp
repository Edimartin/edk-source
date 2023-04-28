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

edk::network::ServerSocket::ServerSocket()
{
}

edk::network::ServerSocket::treeAdress::treeAdress(){
    //
}
edk::network::ServerSocket::treeAdress::~treeAdress(){
    //delete all the adresses
    this->deleteAllAdress();edkEnd();
}
//Add a adress to the tree
bool edk::network::ServerSocket::treeAdress::addAdress(edk::network::Adress host,struct sockaddr_in adress){
    //test the host
    if(host.getIP() && host.getPort()){
        //create new adress
        edk::network::ServerSocket::nodeAdress* node = new edk::network::ServerSocket::nodeAdress;edkEnd();
        if(node){
            //set the host and the adress
            node->host = host;edkEnd();
            node->adress = adress;edkEnd();
            //add the node in the tree
            if(this->add(node)){
                return true;
            }
            delete node;edkEnd();
        }
    }
    return false;
}
//get a adress in the tree
edk::network::ServerSocket::nodeAdress* edk::network::ServerSocket::treeAdress::getAdress(edk::network::Adress host){
    //find the adress
    edk::network::ServerSocket::nodeAdress find;edkEnd();
    find.host = host;edkEnd();
    return this->getElement(&find);
}
//remove one adress from the tree
bool edk::network::ServerSocket::treeAdress::removeAdress(edk::network::Adress host){
    //get Element
    edk::network::ServerSocket::nodeAdress* node = this->getAdress(host);edkEnd();
    if(node){
        //remove from the tree
        if(this->remove(node)){
            //delete the node
            delete node;edkEnd();
            //return true
            return true;
        }
    }
    return false;
}
//delete all Adresses
void edk::network::ServerSocket::treeAdress::deleteAllAdress(){
    edk::network::ServerSocket::nodeAdress* node = NULL;edkEnd();
    for(edk::uint32 i=0u;i<this->getSize();i++){
        node = this->getElementInPosition(i);edkEnd();
        if(node){
            delete node;edkEnd();
        }
        node=NULL;edkEnd();
    }
    this->clean();edkEnd();
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
