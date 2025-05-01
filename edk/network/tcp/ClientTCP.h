#ifndef EDK_NETWORK_TCP_CLIENT_H
#define EDK_NETWORK_TCP_CLIENT_H

/*
Library ClientTCP - Client TCP for EDK
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
#pragma message "Inside ClientTCP"
#endif

#pragma once
#include "../Socket.h"

#ifdef printMessages
#pragma message "    Compiling ClientTCP"
#endif

namespace edk{
namespace network{
namespace tcp{
class ClientTCP : public edk::network::Socket{
public:
    ClientTCP();
    ~ClientTCP();

    void Constructor();
    void Destructor();

    //connect the socket with a server
    edk::network::networkCodes connectSocket(edk::network::Adress host);
    edk::network::networkCodes connectSocket(edk::uint32 ip,edk::uint16 port);
    edk::network::networkCodes connectSocket(edk::char8* ip,edk::uint16 port);
    edk::network::networkCodes connectSocket(const edk::char8* ip,edk::uint16 port);

    //test if have connection
    bool haveConnection();
    //disconnect
    void disconnect();

    //send the stream to server

    edk::int32 sendStream(edk::network::Adress host,edk::classID stream,edk::uint32 size);
    edk::int32 sendStreamNonBlock(edk::network::Adress host,edk::classID stream,edk::uint32 size);
    edk::int32 sendString(edk::network::Adress host,edk::char8* string);
    edk::int32 sendString(edk::network::Adress host,const edk::char8* string);
    edk::int32 sendStringNonBlock(edk::network::Adress host,edk::char8* string);
    edk::int32 sendStringNonBlock(edk::network::Adress host,const edk::char8* string);
    edk::int32 sendStream(edk::classID stream,edk::uint32 size);
    edk::int32 sendStream(const edk::char8* stream,edk::uint32 size);
    edk::int32 sendStreamNonBlock(edk::classID stream,edk::uint32 size);
    edk::int32 sendStreamNonBlock(const edk::char8* stream,edk::uint32 size);
    edk::int32 sendString(edk::char8* string);
    edk::int32 sendString(const edk::char8* string);
    edk::int32 sendStringNonBlock(edk::char8* string);
    edk::int32 sendStringNonBlock(const edk::char8* string);
    //receive the stream from the server
    edk::int32 receiveStream(edk::classID stream,edk::uint32 size,edk::network::Adress* host);
    edk::int32 receiveStream(edk::classID stream,edk::uint32 size);
    edk::int32 receiveStreamNonBlock(edk::classID stream,edk::uint32 size,edk::network::Adress* host);
    edk::int32 receiveStreamNonBlock(edk::classID stream,edk::uint32 size);
private:
    //save the host of the server
    edk::network::Adress serverHost;
    //save if is connected
    bool connected;
private:
    edk::classID classThis;
};
}
}
}

#endif // CLIENT_H
