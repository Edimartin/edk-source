#include "ServerUDP.h"

/*
Library ServerUDP - ServerUDP UDP for EDK
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

edk::network::udp::ServerUDP::ServerUDP(){
    this->binding=false;
    this->cleanAdress();
}

//wait for connection
edk::network::networkCodes edk::network::udp::ServerUDP::startBind(edk::uint16 port){
    //close the last bind
    this->closeBind();
    //creathe the socket
    if(this->createSocket(EDK_SOCKET_UDP)){
        //set the port in the adress
        this->sockAdress.sin_port = htons(port);
        //Start Bind
        if (bind(this->getSocket(), (struct sockaddr *)&this->sockAdress, sizeof(struct sockaddr))>= 0){
            return edk::network::ok;
        }
        //else close bind
        this->closeBind();
    }
    return edk::network::cantStartBind;
}
//close bind
void edk::network::udp::ServerUDP::closeBind(){
    //test if have socket
    if(this->haveSocket()){
        this->closeSocket();
        //delete all adress
        this->tree.deleteAllAdress();
    }
    //clean the adress
    this->cleanAdress();
}

edk::int32 edk::network::udp::ServerUDP::sendStream(edk::network::Adress host,edk::classID stream,edk::uint32 size){
    if(host.getIP() && host.getPort() && stream && size){
        //test if have NOT create the socket
        if(!this->haveSocket()){
            //create the socket
            this->createSocket(EDK_SOCKET_UDP);
        }
        //test if have the socket
        if(this->haveSocket()){
            //load the host
            edk::network::udp::ServerUDP::nodeAdress* node = this->tree.getAdress(host);
            if(node){
                //send the message to the host
                edk::network::Socket::sendStreamTo(this->getSocket(),
                                                   node->adress,
                                                   stream,
                                                   size
                                                   );
                return true;
            }
        }
    }
    return false;
}
edk::int32 edk::network::udp::ServerUDP::sendString(edk::network::Adress host,edk::char8* string){
    return this->sendStream(host,string,edk::String::strSize(string)+1u);
}
edk::int32 edk::network::udp::ServerUDP::sendString(edk::network::Adress host,const char* string){
    return this->sendString(host,(edk::char8*) string);
}
//Receive the message
edk::int32 edk::network::udp::ServerUDP::receiveStream(edk::classID stream,edk::uint32 size,edk::network::Adress* host){
    //test the variables
    if(stream && size && host){
        //receive the message
        struct sockaddr_in adress;
        edk::network::Socket::cleanAdress(&adress);
        edk::int32 ret = edk::network::Socket::receiveStreamFrom(this->getSocket(),&adress,stream,size);
        //load the adress
        host->setIP(edk::network::Adress::getIpNumber(adress.sin_addr.s_addr,0u),
                    edk::network::Adress::getIpNumber(adress.sin_addr.s_addr,1u),
                    edk::network::Adress::getIpNumber(adress.sin_addr.s_addr,2u),
                    edk::network::Adress::getIpNumber(adress.sin_addr.s_addr,3u)
                    );
        host->setPort(adress.sin_port);
        //test if have the host on the tree
        if(!this->tree.getAdress(*host)){
            //add the new host
            this->tree.addAdress(*host,adress);
        }
        return ret;
    }
    return 0u;
}
edk::int32 edk::network::udp::ServerUDP::receiveStreamNonBlock(edk::classID stream,edk::uint32 size,edk::network::Adress* host){
    //test the variables
    if(stream && size && host){
        //receive the message
        struct sockaddr_in adress;
        edk::network::Socket::cleanAdress(&adress);
        edk::int32 ret = edk::network::Socket::receiveStreamFromNonBlock(this->getSocket(),&adress,stream,size);
        //load the adress
        host->setIP(edk::network::Adress::getIpNumber(adress.sin_addr.s_addr,0u),
                    edk::network::Adress::getIpNumber(adress.sin_addr.s_addr,1u),
                    edk::network::Adress::getIpNumber(adress.sin_addr.s_addr,2u),
                    edk::network::Adress::getIpNumber(adress.sin_addr.s_addr,3u)
                    );
        host->setPort(adress.sin_port);
        //test if have the host on the tree
        if(!this->tree.getAdress(*host)){
            //add the new host
            this->tree.addAdress(*host,adress);
        }
        return ret;
    }
    return 0u;
}
