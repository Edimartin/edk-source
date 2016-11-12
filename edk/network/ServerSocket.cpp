#include "ServerSocket.h"

/*
Library ServerSocket - Socket Server for EDK
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

edk::network::ServerSocket::ServerSocket()
{
}

edk::network::ServerSocket::treeAdress::treeAdress(){
    //
}
edk::network::ServerSocket::treeAdress::~treeAdress(){
    //delete all the adresses
    this->deleteAllAdress();
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
