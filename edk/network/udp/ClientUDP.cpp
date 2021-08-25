#include "ClientUDP.h"

/*
Library ClientUDP - Client UDP for EDK
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
edk::int32 edk::network::udp::ClientUDP::sendStreamNonBlock(edk::network::Adress host,edk::classID stream,edk::uint32 size){
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
            return edk::network::Socket::sendStreamToNonBlock(this->getSocket(),this->sockAdress,stream,size);
        }
    }
    return false;
}
edk::int32 edk::network::udp::ClientUDP::sendStreamNonBlock(edk::network::Adress host,const void* stream,edk::uint32 size){
    return edk::network::Socket::sendStreamNonBlock(host,stream,size);
}
edk::int32 edk::network::udp::ClientUDP::sendString(edk::network::Adress host,edk::char8* string){
    return this->sendStream(host,string,edk::String::strSize(string)+1u);
}
edk::int32 edk::network::udp::ClientUDP::sendString(edk::network::Adress host,const edk::char8* string){
    return this->sendString(host,(edk::char8*)string);
}
edk::int32 edk::network::udp::ClientUDP::sendStringNonBlock(edk::network::Adress host,edk::char8* string){
    return this->sendStreamNonBlock(host,string,edk::String::strSize(string)+1u);
}
edk::int32 edk::network::udp::ClientUDP::sendStringNonBlock(edk::network::Adress host,const edk::char8* string){
    return this->sendStringNonBlock(host,(edk::char8*)string);
}
edk::int32 edk::network::udp::ClientUDP::sendStream(edk::char8* ip,edk::uint16 port,edk::classID stream,edk::uint32 size){
    return edk::network::Socket::sendStream(ip,port,stream,size);
}
edk::int32 edk::network::udp::ClientUDP::sendStream(const edk::char8* ip,edk::uint16 port,edk::classID stream,edk::uint32 size){
    return edk::network::Socket::sendStream((edk::char8*)ip,port,stream,size);
}
edk::int32 edk::network::udp::ClientUDP::sendStream(edk::char8* ip,edk::uint16 port,const void* stream,edk::uint32 size){
    return edk::network::Socket::sendStream(ip,port,stream,size);
}
edk::int32 edk::network::udp::ClientUDP::sendStream(const edk::char8* ip,edk::uint16 port,const void* stream,edk::uint32 size){
    return edk::network::Socket::sendStream((edk::char8*)ip,port,(void*)stream,size);
}
edk::int32 edk::network::udp::ClientUDP::sendStreamNonBlock(edk::char8* ip,edk::uint16 port,edk::classID stream,edk::uint32 size){
    return edk::network::Socket::sendStreamNonBlock(ip,port,stream,size);
}
edk::int32 edk::network::udp::ClientUDP::sendStreamNonBlock(const edk::char8* ip,edk::uint16 port,edk::classID stream,edk::uint32 size){
    return edk::network::Socket::sendStreamNonBlock((edk::char8*)ip,port,stream,size);
}
edk::int32 edk::network::udp::ClientUDP::sendStreamNonBlock(edk::char8* ip,edk::uint16 port,const void* stream,edk::uint32 size){
    return edk::network::Socket::sendStreamNonBlock(ip,port,stream,size);
}
edk::int32 edk::network::udp::ClientUDP::sendStreamNonBlock(const edk::char8* ip,edk::uint16 port,const void* stream,edk::uint32 size){
    return edk::network::Socket::sendStreamNonBlock((edk::char8*)ip,port,(void*)stream,size);
}
edk::int32 edk::network::udp::ClientUDP::sendString(edk::char8* ip,edk::uint16 port,edk::char8* string){
    return this->sendStream(ip,port,string,edk::String::strSize(string)+1u);
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
edk::int32 edk::network::udp::ClientUDP::sendStringNonBlock(edk::char8* ip,edk::uint16 port,edk::char8* string){
    return this->sendStreamNonBlock(ip,port,string,edk::String::strSize(string)+1u);
}
edk::int32 edk::network::udp::ClientUDP::sendStringNonBlock(const edk::char8* ip,edk::uint16 port,edk::char8* string){
    return this->sendStringNonBlock((edk::char8* )ip,port,string);
}
edk::int32 edk::network::udp::ClientUDP::sendStringNonBlock(edk::char8* ip,edk::uint16 port,const edk::char8* string){
    return this->sendStringNonBlock(ip,port,(edk::char8* )string);
}
edk::int32 edk::network::udp::ClientUDP::sendStringNonBlock(const edk::char8* ip,edk::uint16 port,const edk::char8* string){
    return this->sendStringNonBlock((edk::char8* )ip,port,(edk::char8* )string);
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
