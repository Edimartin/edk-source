#ifndef EDK_NETWORK_TCP_SERVERTCP_H
#define EDK_NETWORK_TCP_SERVERTCP_H

/*
Library ServerTCP - Server TCP for EDK
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
#pragma message "Inside ServerTCP"
#endif

#pragma once
#include "../ServerSocket.h"
#if _WIN32 || _WIN64
#include <Mswsock.h>
#else
#include <sys/poll.h>
#endif

#ifdef printMessages
#pragma message "    Compiling ServerTCP"
#endif

namespace edk{
namespace network{
namespace tcp{
class ServerTCP : public edk::network::ServerSocket{
public:
    ServerTCP();
    ~ServerTCP();

    //Inicia a ouvir a porta
    edk::network::networkCodes startListen(edk::uint16 port,edk::uint32 connections=0u);
    //test if have listened
    bool haveListened();
    //accept client
    edk::network::Adress acceptClient();
    edk::network::Adress acceptClientNonBlock();
    //Send the message
    edk::int32 sendStream(edk::network::Adress host,edk::classID stream,edk::uint32 size);
    edk::int32 sendStreamNonBlock(edk::network::Adress host,edk::classID stream,edk::uint32 size);
    edk::int32 sendString(edk::network::Adress host,edk::char8* string);
    edk::int32 sendString(edk::network::Adress host,const edk::char8* string);
    edk::int32 sendStringNonBlock(edk::network::Adress host,edk::char8* string);
    edk::int32 sendStringNonBlock(edk::network::Adress host,const edk::char8* string);
    //Receive the message
    edk::int32 receiveStream(edk::classID stream,edk::uint32 size,edk::network::Adress* host);
    edk::int32 receiveStream(edk::classID stream,edk::uint32 size,edk::network::Adress host);
    edk::int32 receiveStreamNonBlock(edk::classID stream,edk::uint32 size,edk::network::Adress* host);
    edk::int32 receiveStreamNonBlock(edk::classID stream,edk::uint32 size,edk::network::Adress host);
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
