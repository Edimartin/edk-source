#ifndef EDK_NETWORK_UDP_CLIENT_H
#define EDK_NETWORK_UDP_CLIENT_H

/*
Library ClientUDP - Client UDP for EDK
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
#include "../Socket.h"

namespace edk{
namespace network{
namespace udp{
class ClientUDP: public edk::network::Socket{
public:
    ClientUDP();

    //Send a message to the server
    bool sendStream(edk::network::Adress host,edk::classID stream,edk::uint32 size);
    bool sendStream(edk::network::Adress host,const void* stream,edk::uint32 size);
    bool sendStream(edk::char8* ip,edk::uint16 port,edk::classID stream,edk::uint32 size);
    bool sendStream(const char* ip,edk::uint16 port,edk::classID stream,edk::uint32 size);
    bool sendStream(edk::char8* ip,edk::uint16 port,const void* stream,edk::uint32 size);
    bool sendStream(const char* ip,edk::uint16 port,const void* stream,edk::uint32 size);
    //Recebe uma mensagem
    edk::int32 receiveStream(edk::classID stream,edk::uint32 size,edk::network::Adress* host);
protected:
    //Carrega o novo endereco
    void loadNewSendAdress(edk::uint32 ip);
    void loadNewSendAdress(edk::char8* ip);
private:
    edk::network::Adress sendHost;
};
}//end namespace udp
}//end namespace network
}//end namespace edk

#endif // CLIENT_H
