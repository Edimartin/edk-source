#include "Socket.h"

/*
Library Socket - Socket controller for Edk Engine
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

#if _WIN32 || _WIN64
//inicializa a winSock
static bool thisInitWinsock=false;
static void startWinsock(){
    //
    if(!thisInitWinsock){
        WORD sockVersion;
        WSADATA wsaData;
        sockVersion = MAKEWORD(1, 1);
        // We'd like Winsock version 1.1

        // We begin by initializing Winsock
        WSAStartup(sockVersion, &wsaData);

        thisInitWinsock=true;
    }
}
#endif

//percorre a string ate encontrar um caracter
static bool ipFindCharacter(edk::char8** str, edk::char8 c){
    //
    if(str){
        if(str[0]){
            while(str[0][0]){
                //testa se encontrou o caracter
                if(str[0][0] == c){
                    //incrementa a string
                    str[0]++;
                    return true;
                }
                //incrementa a string
                str[0]++;
            }
        }
    }
    //senao retorna false
    return false;
}

edk::network::Adress::Adress(){
    this->ip=0u;
    this->port=0u;
}
edk::network::Adress::Adress(edk::uchar8 n1,edk::uchar8 n2,edk::uchar8 n3,edk::uchar8 n4,edk::uint16 port){
    this->ip=0u;
    this->port=0u;
    this->setIP(n1,n2,n3,n4);
    this->setPort(port);
}
edk::network::Adress::Adress(edk::uint32 ip,edk::uint16 port){
    this->ip=0u;
    this->port=0u;
    this->setIP(ip);
    this->setPort(port);
}
edk::network::Adress::Adress(edk::char8* str,edk::uint16 port){
    this->ip=0u;
    this->port=0u;
    this->setIP(str);
    this->setPort(port);
}
edk::network::Adress::Adress(const edk::char8* str,edk::uint16 port){
    this->ip=0u;
    this->port=0u;
    this->setIP(str);
    this->setPort(port);
}
//return the IP by the interface name
edk::uint32 edk::network::Adress::getIpByInterfaceName(edk::char8* name){
#ifdef __linux__
    if(name){
        edk::int32 fd;
        struct ifreq ifr;

        fd = socket(AF_INET, SOCK_DGRAM, 0);

        /* I want to get an IPv4 IP address */
        ifr.ifr_addr.sa_family = AF_INET;

        /* I want IP address attached to "eth0" */
        strncpy(ifr.ifr_name, name, IFNAMSIZ-1);

        ioctl(fd, SIOCGIFADDR, &ifr);

        close(fd);

        edk::uint32 ip = ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr.s_addr;

        return edk::network::Adress::getIP(edk::network::Adress::getIpNumber(ip,0u),
                                           edk::network::Adress::getIpNumber(ip,1u),
                                           edk::network::Adress::getIpNumber(ip,2u),
                                           edk::network::Adress::getIpNumber(ip,3u)
                                           );

        //return ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr.s_addr;
    }
#endif
    return 0u;
}
edk::uint32 edk::network::Adress::getIpByInterfaceName(const edk::char8* name){
    return edk::network::Adress::getIpByInterfaceName((edk::char8*) name);
}
//set the IP
bool edk::network::Adress::setIP(edk::uchar8 n1,edk::uchar8 n2,edk::uchar8 n3,edk::uchar8 n4){
    if(n1 || n2 || n3 || n4){
        //set the ip
        this->ip = edk::network::Adress::getIP(n1,n2,n3,n4);
        return true;
    }
    return false;
}
bool edk::network::Adress::setIP(edk::uint32 ip){
    if(ip){
        //set the IP
        this->ip = ip;
        return true;
    }
    return false;
}
bool edk::network::Adress::setIP(edk::char8* str){
    //clean the IP
    this->ip=0u;
    //test the string
    if(str){
        //set the IP by the name
        this->ip = edk::network::Adress::getIpByName(str);
        return true;
    }
    return false;
}
bool edk::network::Adress::setIP(const edk::char8* str){
    return this->setIP((edk::char8*) str);
}
//set the port
bool edk::network::Adress::setPort(edk::uint16 port){
    if(port){
        this->port=port;
        return true;
    }
    return false;
}
//return the IP
edk::uint32 edk::network::Adress::getIP(){
    return this->ip;
}
//printIP
void edk::network::Adress::printIP(){
    edk::network::Adress::printIP(this->ip);
}

//return the port
edk::uint16 edk::network::Adress::getPort(){
    return this->port;
}

//return the ipNumber
edk::uchar8 edk::network::Adress::getIpNumber(edk::uint32 ip,edk::uchar8 position){
    return (unsigned char)(ip>>(position*8u));
}
//Convert to IP
edk::uint32 edk::network::Adress::getIP(edk::uchar8 n1,edk::uchar8 n2,edk::uchar8 n3,edk::uchar8 n4){
    return (edk::uint32)((((edk::uint32)n1)<<24)+
                         (((edk::uint32)n2)<<16)+
                         (((edk::uint32)n3)<<8)+
                         ((edk::uint32)n4)
                         );
}
edk::uint32 edk::network::Adress::getIP(edk::char8* str){
    if(str){
        //carrega o primeiro valor do ip
        edk::uchar8 ip1 = (edk::uchar8)edk::String::strToInt32(str);
        edk::uchar8 ip2 = 0u;
        edk::uchar8 ip3 = 0u;
        edk::uchar8 ip4 = 0u;
        //busca pelo proximo numero
        if(ipFindCharacter(&str,'.')){
            //converte o segundo valor da string
            ip2 = (edk::uchar8)edk::String::strToInt32(str);
            //busca pelo proximo numero
            if(ipFindCharacter(&str,'.')){
                //converte o terceiro valor da string
                ip3 = (edk::uchar8)edk::String::strToInt32(str);
                //busca pelo proximo numero
                if(ipFindCharacter(&str,'.')){
                    //converte o quarto valor da string
                    ip4 = (edk::uchar8)edk::String::strToInt32(str);


                    //retorna o valor do IP
                    return (edk::uint32)(   (edk::uint32)ip4
                                            +((edk::uint32)ip3<<8)
                                            +((edk::uint32)ip2<<16)
                                            +((edk::uint32)ip1<<24)
                                            );
                }
            }
        }
    }
    return 0u;
}
edk::uint32 edk::network::Adress::getIP(const edk::char8* str){
    return edk::network::Adress::getIP((edk::char8*) str);
}
//return the IP by the name
edk::uint32 edk::network::Adress::getIpByName(edk::char8* name){
    //
    if(name){
        //carrega o host
        hostent *host=NULL;

        //carrega o host pelo nome
        host = gethostbyname((const edk::char8*)name);
        //testa se carregou o host
        if(host){
            //testa o tamanho do ip
            if(host->h_length==4u){
                //converte os valores do IP
                return edk::network::Adress::getIP(host->h_addr[0u],
                        host->h_addr[1u],
                        host->h_addr[2u],
                        host->h_addr[3u]
                        );
            }
        }
        else{
            return edk::network::Adress::getIP(name);
        }
    }
    return 0u;
}
edk::uint32 edk::network::Adress::getIpByName(const edk::char8* name){
    return edk::network::Adress::getIpByName((edk::char8*) name);
}
//return the ipMachine
edk::uint32 edk::network::Adress::getMyIP(){
#if defined(WIN32) || defined(WIN64)
    return 0u;
#elif defined(__linux__)
    return edk::network::Adress::getIpByInterfaceName("eth0");
#endif
}
//convert ipToString
edk::char8* edk::network::Adress::ipToString(edk::uint32 ip){
    //create the string
    edk::char8* ret = new edk::char8[16u];
    if(ret){
        //print the IP on the string
        if(edk::network::Adress::ipToString(ip,ret)){
            return ret;
        }
        //else delete the ret
        delete[] ret;
    }
    //convert the ipNumber
    return NULL;
}
bool edk::network::Adress::ipToString(edk::uint32 ip,edk::char8* str){
    if(str){
        sprintf((char*)str,"%u.%u.%u.%u"
                ,edk::network::Adress::getIpNumber(ip,3u)
                ,edk::network::Adress::getIpNumber(ip,2u)
                ,edk::network::Adress::getIpNumber(ip,1u)
                ,edk::network::Adress::getIpNumber(ip,0u)
                );
        return true;
    }
    return false;
}
//print the ip
void edk::network::Adress::printIP(edk::uint32 ip){
    printf("%u.%u.%u.%u"
           ,edk::network::Adress::getIpNumber(ip,3u)
           ,edk::network::Adress::getIpNumber(ip,2u)
           ,edk::network::Adress::getIpNumber(ip,1u)
           ,edk::network::Adress::getIpNumber(ip,0u)
           );
}

edk::network::Socket::Socket(){
    //
    this->edkSocket=-1u;
}
edk::network::Socket::~Socket(){
    this->closeSocket();
}
edk::int32 edk::network::Socket::sendStream(edk::network::Adress host,const void* stream,edk::uint32 size){
    return this->sendStream(host,(edk::classID) stream,size);
}
edk::int32 edk::network::Socket::sendStream(edk::char8* ip,edk::uint16 port,edk::classID stream,edk::uint32 size){
    return this->sendStream(edk::network::Adress(ip,port),stream,size);
}
edk::int32 edk::network::Socket::sendStream(const edk::char8* ip,edk::uint16 port,edk::classID stream,edk::uint32 size){
    return this->sendStream((edk::char8*) ip,port,stream,size);
}
edk::int32 edk::network::Socket::sendStream(edk::char8* ip,edk::uint16 port,const void* stream,edk::uint32 size){
    return this->sendStream(ip,port,(edk::classID) stream,size);
}
edk::int32 edk::network::Socket::sendStream(const edk::char8* ip,edk::uint16 port,const void* stream,edk::uint32 size){
    return this->sendStream((edk::char8*) ip,port,(edk::classID) stream,size);
}

//create the socket
bool edk::network::Socket::createSocket(socketType type){
#if _WIN32 || _WIN64
//inicializa a winSock
if(!thisInitWinsock) startWinsock();
#endif
    //test the type
    switch(type){
    case EDK_SOCKET_TCP:
        if ((this->edkSocket = socket(AF_INET, SOCK_STREAM, 0)) >= 0){
            return true;
        }
        break;
    case EDK_SOCKET_UDP:
        if ((this->edkSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) >= 0){
            return true;
        }
        break;
    }
    return false;
}
/*
//create a nonblock soket
bool edk::network::Socket::createSocketNonBlock(socketType type){
    //test the type
    switch(type){
    case EDK_SOCKET_TCP:

#if _WIN32 || _WIN64
        if ((this->edkSocket = socket(AF_INET, SOCK_STREAM, 0)) >= 0){
            u_long iMode=1;
            ioctlsocket(this->edkSocket,FIONBIO,&iMode);
#else
        if ((this->edkSocket = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0)) >= 0){
#endif
            return true;
        }
    case EDK_SOCKET_UDP:
#if _WIN32 || _WIN64
        if ((this->edkSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) >= 0){
            u_long iMode=1;
            ioctlsocket(this->edkSocket,FIONBIO,&iMode);
#else
        if ((this->edkSocket = socket(AF_INET, SOCK_DGRAM | SOCK_NONBLOCK, IPPROTO_UDP)) >= 0){
#endif
            return true;
        }
        break;
    }
    return false;
}
*/
//return true if have the socket
bool edk::network::Socket::haveSocket(){
    if(this->edkSocket>=0) return true;
    return false;
}
//return the socket
edk::int32 edk::network::Socket::getSocket(){
    return this->edkSocket;
}

//close the socket
void edk::network::Socket::closeSocket(){
    if(this->edkSocket>=0){
        //fecha o socket
        close(this->edkSocket);
        this->edkSocket=-1;
    }
}

void edk::network::Socket::cleanAdress(){
    edk::network::Socket::cleanAdress(&this->sockAdress);
}
void edk::network::Socket::cleanAdress(struct sockaddr_in* adress){
    //limpa o myAdress
    adress->sin_family = AF_INET;
    adress->sin_port = htons(0u);
    adress->sin_addr.s_addr = INADDR_ANY;
    bzero(&(adress->sin_zero), 8u);
}
//Carrega o host pelo IP
struct sockaddr_in edk::network::Socket::getAdress(edk::uint32 IP){
    edk::char8 host[16u];
    host[15]='\0';
    edk::network::Adress::ipToString(IP,host);
    return this->getAdress(host);
}
//Carrega o host pelo IP
struct sockaddr_in edk::network::Socket::getAdress(const edk::char8* host){
    return this->getAdress((edk::char8*) host);
}
struct sockaddr_in edk::network::Socket::getAdress(edk::char8* host){
    struct sockaddr_in ret;
    //limpa o endereco
    this->cleanAdress(&ret);

    //carrega o host
    struct hostent *hosten=gethostbyname((const edk::char8*)host);
    if(host){
        //carrega o IP do host
        ret.sin_addr = *((struct in_addr *)hosten->h_addr);
    }
    return ret;
}

edk::int32 edk::network::Socket::sendStream(edk::int32 socket,
                                            edk::classID stream,
                                            edk::uint32 size
                                            ){
    //testa o stream
    if(stream && size && socket){
        edk::int32 ret =
                //send the message
        #if _WIN32 || _WIN64
                send(socket,(const edk::char8*)stream,size, 0);
#else
                send(socket,stream,size, MSG_EOR|MSG_NOSIGNAL);
#endif
        //retorna true
        return ret;
    }
    return 0;
}

edk::uint32 edk::network::Socket::receiveStream(edk::int32 socket,
                                                edk::classID stream,
                                                edk::uint32 size
                                                ){
    //testa o stream
    if(stream && size && socket){
        edk::int32 ret =
                //send the message
        #if _WIN32 || _WIN64
                recv(socket,(char*)stream,size, 0);
#else
                recv(socket,stream,size, MSG_EOR|MSG_NOSIGNAL);
#endif
        //retorna true
        return ret;
    }
    return 0;
}
edk::uint32 edk::network::Socket::receiveStreamNonBlock(edk::int32 socket,
                                                        edk::classID stream,
                                                        edk::uint32 size
                                                        ){
    //testa o stream
    if(stream && size && socket){
        edk::int32 ret =
                //send the message
        #if _WIN32 || _WIN64
                recv(socket,(char*)stream,size, WSAEWOULDBLOCK);
#else
                recv(socket,stream,size, MSG_EOR|MSG_NOSIGNAL|MSG_DONTWAIT);
#endif
        //retorna true
        return ret;
    }
    return 0;
}

edk::uint32 edk::network::Socket::sendStreamTo(edk::int32 socket,
                                        sockaddr_in sendAdress,
                                        edk::classID stream,
                                        edk::uint32 size
                                        ){
    edk::int32 ret = -1u;
    /*
    (edk::int32 __fd, __const void *__buf, size_t __n,
            edk::int32 __flags, __CONST_SOCKADDR_ARG __addr,
            socklen_t __addr_len)
*/
    //envia a mensagem para o endereco
#if _WIN32 || _WIN64
    ret = sendto(socket, (char *)stream, size, 0,
                 (struct sockaddr *)&sendAdress,
                 sizeof(struct sockaddr)
                 );
#else
    ret = sendto(socket, stream, size, MSG_EOR|MSG_NOSIGNAL,
                 (struct sockaddr *)&sendAdress,
                 sizeof(struct sockaddr)
                 );
#endif
    //
    return ret;
}

edk::int32 edk::network::Socket::receiveStreamFrom(edk::int32 socket,
                                                   sockaddr_in *adress,
                                                   edk::classID stream,
                                                   edk::uint32 size
                                                   ){
    edk::uint32 sizeAdress = sizeof(struct sockaddr);
    /*
    (edk::int32 __fd, void *__restrict __buf, size_t __n,
             edk::int32 __flags, __SOCKADDR_ARG __addr,
             socklen_t *__restrict __addr_len)
*/
#if _WIN32 || _WIN64
    edk::int32 sizeAdressTemp = (edk::int32)sizeAdress;
    edk::int32 ret =
            recvfrom(socket,
                     (char *)stream,
                     size,
                     0,
                     (struct sockaddr *)adress,
                     &sizeAdressTemp
                     );
#else
    edk::int32 ret =
            //recv(this->mySocket, stream, size, MSG_EOR|MSG_NOSIGNAL)
            recvfrom(socket,
                     stream,
                     size,
                     MSG_EOR|MSG_NOSIGNAL,
                     (struct sockaddr *)adress,
                     &sizeAdress
                     );
#endif
    return ret;
}
edk::int32 edk::network::Socket::receiveStreamFromNonBlock(edk::int32 socket,
                                                           sockaddr_in *adress,
                                                           edk::classID stream,
                                                           edk::uint32 size
                                                           ){
    edk::uint32 sizeAdress = sizeof(struct sockaddr);
    /*
    (edk::int32 __fd, void *__restrict __buf, size_t __n,
             edk::int32 __flags, __SOCKADDR_ARG __addr,
             socklen_t *__restrict __addr_len)
*/
#if _WIN32 || _WIN64
    edk::int32 sizeAdressTemp = (edk::int32)sizeAdress;
    edk::int32 ret =
            recvfrom(socket,
                     (char *)stream,
                     size,
                     WSAEWOULDBLOCK,
                     (struct sockaddr *)adress,
                     &sizeAdressTemp
                     );
#else
    edk::int32 ret =
            //recv(this->mySocket, stream, size, MSG_EOR|MSG_NOSIGNAL)
            recvfrom(socket,
                     stream,
                     size,
                     MSG_EOR|MSG_NOSIGNAL|MSG_DONTWAIT,
                     (struct sockaddr *)adress,
                     &sizeAdress
                     );
#endif
    return ret;
}
