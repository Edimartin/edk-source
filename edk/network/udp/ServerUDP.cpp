#include "ServerUDP.h"

/*
Library ServerUDP - ServerUDP UDP for EDK
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
        if(bind(this->getSocket(), (struct sockaddr *)&this->sockAdress, sizeof(struct sockaddr))>= 0){
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
edk::int32 edk::network::udp::ServerUDP::sendStreamNonBlock(edk::network::Adress host,edk::classID stream,edk::uint32 size){
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
                edk::network::Socket::sendStreamToNonBlock(this->getSocket(),
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
edk::int32 edk::network::udp::ServerUDP::sendString(edk::network::Adress host,const edk::char8* string){
    return this->sendString(host,(edk::char8*) string);
}
edk::int32 edk::network::udp::ServerUDP::sendStringNonBlock(edk::network::Adress host,edk::char8* string){
    return this->sendStreamNonBlock(host,string,edk::String::strSize(string)+1u);
}
edk::int32 edk::network::udp::ServerUDP::sendStringNonBlock(edk::network::Adress host,const edk::char8* string){
    return this->sendStringNonBlock(host,(edk::char8*) string);
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
