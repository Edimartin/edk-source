#include "ClientUDP.h"

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

edk::network::udp::ClientUDP::ClientUDP()
{
    this->cleanAdress();
}
edk::network::udp::ClientUDP::~ClientUDP(){
    this->cleanAdress();
    this->closeSocket();
}

//close the socket
void edk::network::udp::ClientUDP::closeSocket(){
    edk::network::Socket::closeSocket();
}


//Send a message to the server
edk::int32 edk::network::udp::ClientUDP::sendStream(edk::network::Adress host,edk::classID stream,edk::uint32 size){
    //test the host stream and size
    if(host.getIP() && host.getPort() && stream && size){
        //test if dont have the socket
        if(!this->haveSocket()){
            //create the socket
            if(!this->createSocket(EDK_SOCKET_UDP)){
                //else return false
                return false;
            }
        }
        //else send the stream
        if(this->haveSocket()){
            //test if the adress is diferent than the last adress
            if(this->sendHost!=host){
                //create a new host
                this->sendHost = host;
                this->loadNewSendAdress(this->sendHost.getIP());
                this->sockAdress.sin_port = htons(this->sendHost.getPort());
            }
            //then send the message
            return edk::network::Socket::sendStreamTo(this->getSocket(),this->sockAdress,stream,size);
        }
    }
    return false;
}
edk::int32 edk::network::udp::ClientUDP::sendStream(edk::network::Adress host,const void* stream,edk::uint32 size){
    return edk::network::Socket::sendStream(host,stream,size);
}
edk::int32 edk::network::udp::ClientUDP::sendString(edk::network::Adress host,edk::char8* string){
    return this->sendStream(host,string,edk::String::strSize(string)+1u);
}
edk::int32 edk::network::udp::ClientUDP::sendString(edk::network::Adress host,const edk::char8* string){
    return this->sendString(host,(edk::char8*)string);
}
edk::int32 edk::network::udp::ClientUDP::sendStream(edk::char8* ip,edk::uint16 port,edk::classID stream,edk::uint32 size){
    return edk::network::Socket::sendStream(ip,port,stream,size);
}
edk::int32 edk::network::udp::ClientUDP::sendStream(const edk::char8* ip,edk::uint16 port,edk::classID stream,edk::uint32 size){
    return edk::network::Socket::sendStream(ip,port,stream,size);
}
edk::int32 edk::network::udp::ClientUDP::sendStream(edk::char8* ip,edk::uint16 port,const void* stream,edk::uint32 size){
    return edk::network::Socket::sendStream(ip,port,stream,size);
}
edk::int32 edk::network::udp::ClientUDP::sendStream(const edk::char8* ip,edk::uint16 port,const void* stream,edk::uint32 size){
    return edk::network::Socket::sendStream(ip,port,stream,size);
}
edk::int32 edk::network::udp::ClientUDP::sendString(edk::char8* ip,edk::uint16 port,edk::char8* string){
    return this->edk::network::udp::ClientUDP::sendStream(ip,port,string,edk::String::strSize(string)+1u);
}
edk::int32 edk::network::udp::ClientUDP::sendString(const edk::char8* ip,edk::uint16 port,edk::char8* string){
    return this->sendString((edk::char8* )ip,port,string);
}
edk::int32 edk::network::udp::ClientUDP::sendString(edk::char8* ip,edk::uint16 port,const edk::char8* string){
    return this->sendString(ip,port,(edk::char8* )string);
}
edk::int32 edk::network::udp::ClientUDP::sendString(const edk::char8* ip,edk::uint16 port,const edk::char8* string){
    return this->sendString((edk::char8* )ip,port,(edk::char8* )string);
}
//Receive the message
edk::int32 edk::network::udp::ClientUDP::receiveStream(edk::classID stream,edk::uint32 size,edk::network::Adress* host){
    //test the host, sream and size
    if(host && stream && size){
        //recebe a mensagem
        struct sockaddr_in adress;
        edk::network::Socket::cleanAdress(&adress);
        edk::int32 ret = edk::network::Socket::receiveStreamFrom(this->getSocket(),&adress,stream,size);
        //carrega o IP
        host->setIP(edk::network::Adress::getIpNumber(adress.sin_addr.s_addr,0u),
                    edk::network::Adress::getIpNumber(adress.sin_addr.s_addr,1u),
                    edk::network::Adress::getIpNumber(adress.sin_addr.s_addr,2u),
                    edk::network::Adress::getIpNumber(adress.sin_addr.s_addr,3u)
                    );
        host->setPort(adress.sin_port);
        return ret;
    }
    //senao retorna 0u
    return 0u;
}
edk::int32 edk::network::udp::ClientUDP::receiveStreamNonBlock(edk::classID stream,edk::uint32 size,edk::network::Adress* host){
    //test the host, sream and size
    if(host && stream && size){
        //recebe a mensagem
        struct sockaddr_in adress;
        edk::network::Socket::cleanAdress(&adress);
        edk::int32 ret = edk::network::Socket::receiveStreamFromNonBlock(this->getSocket(),&adress,stream,size);
        //carrega o IP
        host->setIP(edk::network::Adress::getIpNumber(adress.sin_addr.s_addr,0u),
                    edk::network::Adress::getIpNumber(adress.sin_addr.s_addr,1u),
                    edk::network::Adress::getIpNumber(adress.sin_addr.s_addr,2u),
                    edk::network::Adress::getIpNumber(adress.sin_addr.s_addr,3u)
                    );
        host->setPort(adress.sin_port);
        return ret;
    }
    //senao retorna 0u
    return 0u;
}

//Carrega o novo endereco
void edk::network::udp::ClientUDP::loadNewSendAdress(edk::uint32 ip){
    //this->cleanAdress(&this->myAdress);
    this->sockAdress = this->getAdress(ip);
}
void edk::network::udp::ClientUDP::loadNewSendAdress(edk::char8* ip){
    //
    //this->cleanAdress(&this->myAdress);
    this->sockAdress = this->getAdress(ip);
}
