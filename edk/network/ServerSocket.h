#ifndef EDK_NETWORK_SERVERSOCKET_H
#define EDK_NETWORK_SERVERSOCKET_H

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

#ifdef printMessages
#pragma message "Inside ServerSocket"
#endif

#pragma once
#include "Socket.h"
#include "../vector/BinaryTree.h"

#ifdef printMessages
#pragma message "    Compiling ServerSocket"
#endif

namespace edk{
namespace network{
class ServerSocket : public edk::network::Socket{
public:
    ServerSocket();
    virtual ~ServerSocket();

    void Constructor();
    void Destructor();
    //Send the message
    virtual edk::int32 sendStream(edk::network::Adress host,edk::classID stream,edk::uint32 size)=0;
    virtual edk::int32 sendStreamNonBlock(edk::network::Adress host,edk::classID stream,edk::uint32 size)=0;
    //Receive the message
    virtual edk::int32 receiveStream(edk::classID stream,edk::uint32 size,edk::network::Adress* host)=0;
    virtual edk::int32 receiveStreamNonBlock(edk::classID stream,edk::uint32 size,edk::network::Adress* host)=0;
protected:
    //node to save the adresses
    class nodeAdress{
    public:
        nodeAdress(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~nodeAdress(){
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
            }
        }
        //socket adress
        edk::network::Adress host;
        struct sockaddr_in adress;
    private:
        edk::classID classThis;
    };
    //Tree used to save the adresses
    //Binary Tree
    class treeAdress:public edk::vector::BinaryTree<nodeAdress*>{
    public:
        treeAdress();
        virtual ~treeAdress();

        void Constructor();
        void Destructor();
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
    private:
        edk::classID classThis;
    }tree;
private:
    edk::classID classThis;
};
}
}

#endif // SERVERSOCKET_H
