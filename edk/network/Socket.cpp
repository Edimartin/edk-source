#include "Socket.h"

/*
Library Socket - Socket controller for Edk Engine
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

#if _WIN32 || _WIN64
//inicializa a winSock
static bool thisInitWinsock=false;edkEnd();
static void startWinsock(){
    //
    if(!thisInitWinsock){
        WORD sockVersion;edkEnd();
        WSADATA wsaData;edkEnd();
        sockVersion = MAKEWORD(1, 1);edkEnd();
        // We'd like Winsock version 1.1

        // We begin by initializing Winsock
        WSAStartup(sockVersion, &wsaData);edkEnd();

        thisInitWinsock=true;edkEnd();
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
                    str[0]++;edkEnd();
                    return true;
                }
                //incrementa a string
                str[0]++;edkEnd();
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
    this->setIP(n1,n2,n3,n4);edkEnd();
    this->setPort(port);edkEnd();
}
edk::network::Adress::Adress(edk::uint32 ip,edk::uint16 port){
    this->ip=0u;
    this->port=0u;
    this->setIP(ip);edkEnd();
    this->setPort(port);edkEnd();
}
edk::network::Adress::Adress(edk::char8* str,edk::uint16 port){
    this->ip=0u;
    this->port=0u;
    this->setIP(str);edkEnd();
    this->setPort(port);edkEnd();
}
edk::network::Adress::Adress(const edk::char8* str,edk::uint16 port){
    this->ip=0u;
    this->port=0u;
    this->setIP(str);edkEnd();
    this->setPort(port);edkEnd();
}
//return the IP by the interface name
edk::uint32 edk::network::Adress::getIpByInterfaceName(edk::char8* name){
#ifdef __linux__
    if(name){
        edk::int32 fd;edkEnd();
        struct ifreq ifr;edkEnd();

        fd = socket(AF_INET, SOCK_DGRAM, 0);edkEnd();

        /* I want to get an IPv4 IP address */
        ifr.ifr_addr.sa_family = AF_INET;edkEnd();

        /* I want IP address attached to "eth0" */
        strncpy(ifr.ifr_name, name, IFNAMSIZ-1);edkEnd();

        ioctl(fd, SIOCGIFADDR, &ifr);edkEnd();

        close(fd);edkEnd();

        edk::uint32 ip = ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr.s_addr;edkEnd();

        return edk::network::Adress::getIP(edk::network::Adress::getIpNumber(ip,0u),
                                           edk::network::Adress::getIpNumber(ip,1u),
                                           edk::network::Adress::getIpNumber(ip,2u),
                                           edk::network::Adress::getIpNumber(ip,3u)
                                           );edkEnd();

        //return ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr.s_addr;edkEnd();
    }
#endif
    return 0u;edkEnd();
}
edk::uint32 edk::network::Adress::getIpByInterfaceName(const edk::char8* name){
    return edk::network::Adress::getIpByInterfaceName((edk::char8*) name);edkEnd();
}
//set the IP
bool edk::network::Adress::setIP(edk::uchar8 n1,edk::uchar8 n2,edk::uchar8 n3,edk::uchar8 n4){
    if(n1 || n2 || n3 || n4){
        //set the ip
        this->ip = edk::network::Adress::getIP(n1,n2,n3,n4);edkEnd();
        return true;
    }
    return false;
}
bool edk::network::Adress::setIP(edk::uint32 ip){
    if(ip){
        //set the IP
        this->ip = ip;edkEnd();
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
        this->ip = edk::network::Adress::getIpByName(str);edkEnd();
        return true;
    }
    return false;
}
bool edk::network::Adress::setIP(const edk::char8* str){
    return this->setIP((edk::char8*) str);edkEnd();
}
//set the port
bool edk::network::Adress::setPort(edk::uint16 port){
    if(port){
        this->port=port;edkEnd();
        return true;
    }
    return false;
}
//return the IP
edk::uint32 edk::network::Adress::getIP(){
    return this->ip;edkEnd();
}
//printIP
void edk::network::Adress::printIP(){
    edk::network::Adress::printIP(this->ip);edkEnd();
}

//return the port
edk::uint16 edk::network::Adress::getPort(){
    return this->port;edkEnd();
}

//return the ipNumber
edk::uchar8 edk::network::Adress::getIpNumber(edk::uint32 ip,edk::uchar8 position){
    return (unsigned char)(ip>>(position*8u));edkEnd();
}
//Convert to IP
edk::uint32 edk::network::Adress::getIP(edk::uchar8 n1,edk::uchar8 n2,edk::uchar8 n3,edk::uchar8 n4){
    return (edk::uint32)((((edk::uint32)n1)<<24)+
                         (((edk::uint32)n2)<<16)+
                         (((edk::uint32)n3)<<8)+
                         ((edk::uint32)n4)
                         );edkEnd();
}
edk::uint32 edk::network::Adress::getIP(edk::char8* str){
    if(str){
        //carrega o primeiro valor do ip
        edk::uchar8 ip1 = (edk::uchar8)edk::String::strToInt32(str);edkEnd();
        edk::uchar8 ip2 = 0u;edkEnd();
        edk::uchar8 ip3 = 0u;edkEnd();
        edk::uchar8 ip4 = 0u;edkEnd();
        //busca pelo proximo numero
        if(ipFindCharacter(&str,'.')){
            //converte o segundo valor da string
            ip2 = (edk::uchar8)edk::String::strToInt32(str);edkEnd();
            //busca pelo proximo numero
            if(ipFindCharacter(&str,'.')){
                //converte o terceiro valor da string
                ip3 = (edk::uchar8)edk::String::strToInt32(str);edkEnd();
                //busca pelo proximo numero
                if(ipFindCharacter(&str,'.')){
                    //converte o quarto valor da string
                    ip4 = (edk::uchar8)edk::String::strToInt32(str);edkEnd();


                    //retorna o valor do IP
                    return (edk::uint32)(   (edk::uint32)ip4
                                            +((edk::uint32)ip3<<8)
                                            +((edk::uint32)ip2<<16)
                                            +((edk::uint32)ip1<<24)
                                            );edkEnd();
                }
            }
        }
    }
    return 0u;edkEnd();
}
edk::uint32 edk::network::Adress::getIP(const edk::char8* str){
    return edk::network::Adress::getIP((edk::char8*) str);edkEnd();
}
//return the IP by the name
edk::uint32 edk::network::Adress::getIpByName(edk::char8* name){
    //
    if(name){
        //carrega o host
        hostent *host=NULL;edkEnd();

        //carrega o host pelo nome
        host = gethostbyname((const edk::char8*)name);edkEnd();
        //testa se carregou o host
        if(host){
            //testa o tamanho do ip
            if(host->h_length==4u){
                //converte os valores do IP
                return edk::network::Adress::getIP(host->h_addr[0u],
                        host->h_addr[1u],
                        host->h_addr[2u],
                        host->h_addr[3u]
                        );edkEnd();
            }
        }
        else{
            return edk::network::Adress::getIP(name);edkEnd();
        }
    }
    return 0u;edkEnd();
}
edk::uint32 edk::network::Adress::getIpByName(const edk::char8* name){
    return edk::network::Adress::getIpByName((edk::char8*) name);edkEnd();
}
//return the ipMachine
edk::uint32 edk::network::Adress::getMyIP(){
#if defined(WIN32) || defined(WIN64)
    return 0u;edkEnd();
#elif defined(__linux__)
    return edk::network::Adress::getIpByInterfaceName("eth0");edkEnd();
#endif
}
//convert ipToString
edk::char8* edk::network::Adress::ipToString(edk::uint32 ip){
    //create the string
    edk::char8* ret = new edk::char8[16u];edkEnd();
    if(ret){
        //print the IP on the string
        if(edk::network::Adress::ipToString(ip,ret)){
            return ret;
        }
        //else delete the ret
        delete[] ret;edkEnd();
    }
    //convert the ipNumber
    return NULL;edkEnd();
}
bool edk::network::Adress::ipToString(edk::uint32 ip,edk::char8* str){
    if(str){
        sprintf((char*)str,"%u.%u.%u.%u"
                ,edk::network::Adress::getIpNumber(ip,3u)
                ,edk::network::Adress::getIpNumber(ip,2u)
                ,edk::network::Adress::getIpNumber(ip,1u)
                ,edk::network::Adress::getIpNumber(ip,0u)
                );edkEnd();
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
           );edkEnd();
}

edk::network::Socket::Socket(){
    //
    this->edkSocket=-1u;edkEnd();
}
edk::network::Socket::~Socket(){
    this->closeSocket();edkEnd();
}
edk::int32 edk::network::Socket::sendStream(edk::network::Adress host,const void* stream,edk::uint32 size){
    return this->sendStream(host,(edk::classID) stream,size);edkEnd();
}
edk::int32 edk::network::Socket::sendStream(edk::char8* ip,edk::uint16 port,edk::classID stream,edk::uint32 size){
    return this->sendStream(edk::network::Adress(ip,port),stream,size);edkEnd();
}
edk::int32 edk::network::Socket::sendStream(const edk::char8* ip,edk::uint16 port,edk::classID stream,edk::uint32 size){
    return this->sendStream((edk::char8*) ip,port,stream,size);edkEnd();
}
edk::int32 edk::network::Socket::sendStream(edk::char8* ip,edk::uint16 port,const void* stream,edk::uint32 size){
    return this->sendStream(ip,port,(edk::classID) stream,size);edkEnd();
}
edk::int32 edk::network::Socket::sendStream(const edk::char8* ip,edk::uint16 port,const void* stream,edk::uint32 size){
    return this->sendStream((edk::char8*) ip,port,(edk::classID) stream,size);edkEnd();
}
edk::int32 edk::network::Socket::sendStreamNonBlock(edk::network::Adress host,const void* stream,edk::uint32 size){
    return this->sendStreamNonBlock(host,(edk::classID) stream,size);edkEnd();
}
edk::int32 edk::network::Socket::sendStreamNonBlock(edk::char8* ip,edk::uint16 port,edk::classID stream,edk::uint32 size){
    return this->sendStreamNonBlock(edk::network::Adress(ip,port),stream,size);edkEnd();
}
edk::int32 edk::network::Socket::sendStreamNonBlock(const edk::char8* ip,edk::uint16 port,edk::classID stream,edk::uint32 size){
    return this->sendStreamNonBlock((edk::char8*) ip,port,stream,size);edkEnd();
}
edk::int32 edk::network::Socket::sendStreamNonBlock(edk::char8* ip,edk::uint16 port,const void* stream,edk::uint32 size){
    return this->sendStreamNonBlock(ip,port,(edk::classID) stream,size);edkEnd();
}
edk::int32 edk::network::Socket::sendStreamNonBlock(const edk::char8* ip,edk::uint16 port,const void* stream,edk::uint32 size){
    return this->sendStreamNonBlock((edk::char8*) ip,port,(edk::classID) stream,size);edkEnd();
}

//create the socket
bool edk::network::Socket::createSocket(socketType type){
#if _WIN32 || _WIN64
    //inicializa a winSock
    if(!thisInitWinsock){
        startWinsock();edkEnd();
    }
#endif
    //test the type
    switch(type){
    case EDK_SOCKET_TCP:
        if ((this->edkSocket = socket(AF_INET, SOCK_STREAM, 0)) >= 0){
            return true;
        }
        break;edkEnd();
    case EDK_SOCKET_UDP:
        if ((this->edkSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) >= 0){
            return true;
        }
        break;edkEnd();
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
            u_long iMode=1;edkEnd();
            ioctlsocket(this->edkSocket,FIONBIO,&iMode);edkEnd();
#else
        if ((this->edkSocket = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0)) >= 0){
#endif
            return true;
        }
    case EDK_SOCKET_UDP:
#if _WIN32 || _WIN64
        if ((this->edkSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) >= 0){
            u_long iMode=1;edkEnd();
            ioctlsocket(this->edkSocket,FIONBIO,&iMode);edkEnd();
#else
        if ((this->edkSocket = socket(AF_INET, SOCK_DGRAM | SOCK_NONBLOCK, IPPROTO_UDP)) >= 0){
#endif
            return true;
        }
        break;edkEnd();
    }
    return false;
}
*/
//return true if have the socket
bool edk::network::Socket::haveSocket(){
    if(this->edkSocket>=0){
        return true;
    }
    return false;
}
//return the socket
edk::int32 edk::network::Socket::getSocket(){
    return this->edkSocket;edkEnd();
}

//close the socket
void edk::network::Socket::closeSocket(){
    if(this->edkSocket>=0){
        //fecha o socket
        close(this->edkSocket);edkEnd();
        this->edkSocket=-1;edkEnd();
    }
}

void edk::network::Socket::cleanAdress(){
    edk::network::Socket::cleanAdress(&this->sockAdress);edkEnd();
}
void edk::network::Socket::cleanAdress(struct sockaddr_in* adress){
    //limpa o myAdress
    adress->sin_family = AF_INET;edkEnd();
    adress->sin_port = htons(0u);edkEnd();
    adress->sin_addr.s_addr = INADDR_ANY;edkEnd();
    bzero(&(adress->sin_zero), 8u);edkEnd();
}
//Carrega o host pelo IP
struct sockaddr_in edk::network::Socket::getAdress(edk::uint32 IP){
    edk::char8 host[16u];edkEnd();
    host[15]='\0';edkEnd();
    edk::network::Adress::ipToString(IP,host);edkEnd();
    return this->getAdress(host);edkEnd();
}
//Carrega o host pelo IP
struct sockaddr_in edk::network::Socket::getAdress(const edk::char8* host){
    return this->getAdress((edk::char8*) host);edkEnd();
}
struct sockaddr_in edk::network::Socket::getAdress(edk::char8* host){
    struct sockaddr_in ret;edkEnd();
    //limpa o endereco
    this->cleanAdress(&ret);edkEnd();

    //carrega o host
    struct hostent *hosten=gethostbyname((const edk::char8*)host);edkEnd();
    if(host){
        //carrega o IP do host
        ret.sin_addr = *((struct in_addr *)hosten->h_addr);edkEnd();
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
                send(socket,(const edk::char8*)stream,size, 0);edkEnd();
#else
                send(socket,stream,size, MSG_EOR|MSG_NOSIGNAL);edkEnd();
#endif
        //retorna true
        return ret;
    }
    return 0;
}
edk::int32 edk::network::Socket::sendStreamNonBlock(edk::int32 socket,
                                                    edk::classID stream,
                                                    edk::uint32 size
                                                    ){
    //testa o stream
    if(stream && size && socket){
        edk::int32 ret =
                //send the message
        #if _WIN32 || _WIN64
                send(socket,(const edk::char8*)stream,size, WSAEWOULDBLOCK);edkEnd();
#else
                send(socket,stream,size, MSG_EOR|MSG_NOSIGNAL|MSG_DONTWAIT);edkEnd();
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
                recv(socket,(char*)stream,size, 0);edkEnd();
#else
                recv(socket,stream,size, MSG_EOR|MSG_NOSIGNAL);edkEnd();
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
                recv(socket,(char*)stream,size, WSAEWOULDBLOCK);edkEnd();
#else
                recv(socket,stream,size, MSG_EOR|MSG_NOSIGNAL|MSG_DONTWAIT);edkEnd();
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
    edk::int32 ret = -1u;edkEnd();
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
                 );edkEnd();
#else
    ret = sendto(socket, stream, size, MSG_EOR|MSG_NOSIGNAL,
                 (struct sockaddr *)&sendAdress,
                 sizeof(struct sockaddr)
                 );edkEnd();
#endif
    //
    return ret;
}
edk::uint32 edk::network::Socket::sendStreamToNonBlock(edk::int32  socket,
                                                       sockaddr_in sendAdress,
                                                       edk::classID stream,
                                                       edk::uint32 size
                                                       ){
    edk::int32 ret = -1u;edkEnd();
    /*
    (edk::int32 __fd, __const void *__buf, size_t __n,
            edk::int32 __flags, __CONST_SOCKADDR_ARG __addr,
            socklen_t __addr_len)
*/
    //envia a mensagem para o endereco
#if _WIN32 || _WIN64
    ret = sendto(socket, (char *)stream, size, WSAEWOULDBLOCK,
                 (struct sockaddr *)&sendAdress,
                 sizeof(struct sockaddr)
                 );edkEnd();
#else
    ret = sendto(socket, stream, size, MSG_EOR|MSG_NOSIGNAL|MSG_DONTWAIT,
                 (struct sockaddr *)&sendAdress,
                 sizeof(struct sockaddr)
                 );edkEnd();
#endif
    //
    return ret;
}

edk::int32 edk::network::Socket::receiveStreamFrom(edk::int32 socket,
                                                   sockaddr_in *adress,
                                                   edk::classID stream,
                                                   edk::uint32 size
                                                   ){
    edk::uint32 sizeAdress = sizeof(struct sockaddr);edkEnd();
    /*
    (edk::int32 __fd, void *__restrict __buf, size_t __n,
             edk::int32 __flags, __SOCKADDR_ARG __addr,
             socklen_t *__restrict __addr_len)
*/
#if _WIN32 || _WIN64
    edk::int32 sizeAdressTemp = (edk::int32)sizeAdress;edkEnd();
    edk::int32 ret =
            recvfrom(socket,
                     (char *)stream,
                     size,
                     0,
                     (struct sockaddr *)adress,
                     &sizeAdressTemp
                     );edkEnd();
#else
    edk::int32 ret =
            //recv(this->mySocket, stream, size, MSG_EOR|MSG_NOSIGNAL)
            recvfrom(socket,
                     stream,
                     size,
                     MSG_EOR|MSG_NOSIGNAL,
                     (struct sockaddr *)adress,
                     &sizeAdress
                     );edkEnd();
#endif
    return ret;
}
edk::int32 edk::network::Socket::receiveStreamFromNonBlock(edk::int32 socket,
                                                           sockaddr_in *adress,
                                                           edk::classID stream,
                                                           edk::uint32 size
                                                           ){
    edk::uint32 sizeAdress = sizeof(struct sockaddr);edkEnd();
    /*
    (edk::int32 __fd, void *__restrict __buf, size_t __n,
             edk::int32 __flags, __SOCKADDR_ARG __addr,
             socklen_t *__restrict __addr_len)
*/
#if _WIN32 || _WIN64
    edk::int32 sizeAdressTemp = (edk::int32)sizeAdress;edkEnd();
    edk::int32 ret =
            recvfrom(socket,
                     (char *)stream,
                     size,
                     WSAEWOULDBLOCK,
                     (struct sockaddr *)adress,
                     &sizeAdressTemp
                     );edkEnd();
#else
    edk::int32 ret =
            //recv(this->mySocket, stream, size, MSG_EOR|MSG_NOSIGNAL)
            recvfrom(socket,
                     stream,
                     size,
                     MSG_EOR|MSG_NOSIGNAL|MSG_DONTWAIT,
                     (struct sockaddr *)adress,
                     &sizeAdress
                     );edkEnd();
#endif
    return ret;
}
