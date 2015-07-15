#ifndef EDK_NETWORK_SERVERSOCKET_H
#define EDK_NETWORK_SERVERSOCKET_H

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

#pragma once
#include "Socket.h"
#include "../vector/BinaryTree.h"

namespace edk{
namespace network{
class ServerSocket : public edk::network::Socket{
public:
    ServerSocket();
    //Send the message
    virtual bool sendStream(edk::network::Adress host,edk::classID stream,edk::uint32 size)=0;
    //Receive the message
    virtual edk::int32 receiveStream(edk::classID stream,edk::uint32 size,edk::network::Adress* host)=0;
protected:
    //node to save the adresses
    class nodeAdress{
    public:
        nodeAdress(){}
        ~nodeAdress(){}
        //socket adress
        edk::network::Adress host;
        struct sockaddr_in adress;
    };
    //Tree used to save the adresses
    //Binary Tree
    class treeAdress:public edk::vector::BinaryTree<nodeAdress*>{
    public:
        treeAdress();
        ~treeAdress();
        //Add a adress to the tree
        bool addAdress(edk::network::Adress host,struct sockaddr_in adress);
        //get a adress in the tree
        nodeAdress* getAdress(edk::network::Adress host);
        //remove one adress from the tree
        bool removeAdress(edk::network::Adress host);
        //delete all Adresses
        void deleteAllAdress();
    protected:
        //compare if the value is bigger
        bool firstBiggerSecond(nodeAdress* first,nodeAdress* second);
        bool firstEqualSecond(nodeAdress* first,nodeAdress* second);
    }tree;
};
}
}

#endif // SERVERSOCKET_H
