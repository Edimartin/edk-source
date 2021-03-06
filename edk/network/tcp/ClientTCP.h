#ifndef EDK_NETWORK_TCP_CLIENT_H
#define EDK_NETWORK_TCP_CLIENT_H

/*
Library ClientTCP - Client TCP for EDK
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

#ifdef printMessages
#warning "Inside ClientTCP"
#endif

#pragma once
#include "../Socket.h"

#ifdef printMessages
#warning "    Compiling ClientTCP"
#endif

namespace edk{
namespace network{
namespace tcp{
class ClientTCP : public edk::network::Socket{
public:
    ClientTCP();

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
};
}
}
}

#endif // CLIENT_H
