#ifndef EDK_NETWORK_TCP_SERVERTCP_H
#define EDK_NETWORK_TCP_SERVERTCP_H

/*
Library ServerTCP - Server TCP for EDK
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
#include "../ServerSocket.h"

namespace edk{
namespace network{
namespace tcp{
class ServerTCP : public edk::network::ServerSocket{
public:
    ServerTCP();
    ~ServerTCP();

    //Inicia a ouvir a porta
    bool startListen(edk::uint16 port,edk::uint32 connections);
    //test if have listened
    bool haveListened();
    //accept client
    edk::network::Adress acceptClient();
    edk::network::Adress acceptNonBlockClient();
    //Send the message
    bool sendStream(edk::network::Adress host,edk::classID stream,edk::uint32 size);
    bool sendString(edk::network::Adress host,edk::char8* string);
    bool sendString(edk::network::Adress host,const char* string);
    //Receive the message
    edk::int32 receiveStream(edk::classID stream,edk::uint32 size,edk::network::Adress* host);
    edk::int32 receiveStream(edk::classID stream,edk::uint32 size,edk::network::Adress host);
    //disconnect the server
    void disconnect();
    //disconnect the client
    bool disconnectClient(edk::network::Adress host);
    //return the number of connected clients
    edk::uint32 getClients();
protected:
    class nodeAdressTCP : public edk::network::ServerSocket::nodeAdress{
    public:
        nodeAdressTCP(){}
        ~nodeAdressTCP(){}
        //clientSocket
        edk::uint32 socket;
    };

private:
    bool listened;
    //accept client
    edk::network::Adress acceptTCPClient(bool nonBlock);
};
}
}
}

#endif // SERVERTCP_H