#ifndef EDK_NETWORK_SOCKET_H
#define EDK_NETWORK_SOCKET_H

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

#ifdef printMessages
#warning "Inside Adress"
#endif

#pragma once
#if _WIN32 || _WIN64
/*LIBS
-lwsock32
*/
#include <winsock2.h>
//#include <winsock.h>
#include <windows.h>
#define bzero(b,len) (memset((b), '\0', (len)), (void) 0)
#else
#include <arpa/inet.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#endif
#include <sys/types.h>
#include <string.h>


#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include "../TypeVars.h"
#include "../String.h"
#include "../TypeDefines.h"

//Socket Type
//EDK_SOCKET_NONE
//EDK_SOCKET_UDP
//EDK_SOCKET_TCP

#ifdef printMessages
#warning "    Compiling Adress"
#endif

namespace edk{
namespace network{

class Adress{
public:
    Adress();
    Adress(edk::uchar8 n1,edk::uchar8 n2,edk::uchar8 n3,edk::uchar8 n4,edk::uint16 port);
    Adress(edk::uint32 ip,edk::uint16 port);
    Adress(edk::char8* str,edk::uint16 port);
    Adress(const edk::char8* str,edk::uint16 port);
    //Adress Functions
    //set the IP
    bool setIP(edk::uchar8 n1,edk::uchar8 n2,edk::uchar8 n3,edk::uchar8 n4);
    bool setIP(edk::uint32 ip);
    bool setIP(edk::char8* str);
    bool setIP(const edk::char8* str);
    //set the port
    bool setPort(edk::uint16 port);
    //return the IP
    edk::uint32 getIP();
    //printIP
    void printIP();
    //return the port
    edk::uint16 getPort();

    //Operator
    Adress operator=(Adress adress){
        this->port=adress.port;edkEnd();
        this->ip=adress.ip;edkEnd();
        return adress;edkEnd();
    }
    bool operator==(Adress adress){
        return (bool)( (adress.ip==this->ip)&&(adress.port==this->port));edkEnd();
    }
    bool operator!=(Adress adress){
        return (bool)( (adress.ip!=this->ip)||(adress.port!=this->port));edkEnd();
    }
    bool operator>(Adress adress){
        if(this->ip>adress.ip){
            return true;
        }
        else if(this->ip==adress.ip){
            if(this->port>adress.port){
                return true;
            }
        }
        return false;
    }
    bool operator<(Adress adress){
        if(this->ip<adress.ip){
            return true;
        }
        else if(this->ip==adress.ip){
            if(this->port<adress.port){
                return true;
            }
        }
        return false;
    }

    //Static Functions
    //return the ipNumber
    static edk::uchar8 getIpNumber(edk::uint32 ip,edk::uchar8 position);
    //Convert to IP
    static edk::uint32 getIP(edk::uchar8 n1,edk::uchar8 n2,edk::uchar8 n3,edk::uchar8 n4);
    static edk::uint32 getIP(edk::char8* str);
    static edk::uint32 getIP(const edk::char8* str);
    //return the IP by the name
    static edk::uint32 getIpByName(edk::char8* name);
    static edk::uint32 getIpByName(const edk::char8* name);
    //return the ipMachine
    static edk::uint32 getMyIP();
    //convert ipToString
    static edk::char8* ipToString(edk::uint32 ip);
    static bool ipToString(edk::uint32 ip,edk::char8* str);
    //print the ip
    static void printIP(edk::uint32 ip);

private:
    edk::uint16 port;
    edk::uint32 ip;
    //return the IP by the interface name
    static edk::uint32 getIpByInterfaceName(edk::char8* name);
    static edk::uint32 getIpByInterfaceName(const edk::char8* name);
};


//Socket class
class Socket{
public:
    Socket();
    ~Socket();

    //Send a message to the server
    virtual edk::int32 sendStream(edk::network::Adress host,edk::classID stream,edk::uint32 size)=0;
    edk::int32 sendStream(edk::network::Adress host,const void* stream,edk::uint32 size);
    edk::int32 sendStream(edk::char8* ip,edk::uint16 port,edk::classID stream,edk::uint32 size);
    edk::int32 sendStream(const edk::char8* ip,edk::uint16 port,edk::classID stream,edk::uint32 size);
    edk::int32 sendStream(edk::char8* ip,edk::uint16 port,const void* stream,edk::uint32 size);
    edk::int32 sendStream(const edk::char8* ip,edk::uint16 port,const void* stream,edk::uint32 size);
    virtual edk::int32 sendStreamNonBlock(edk::network::Adress host,edk::classID stream,edk::uint32 size)=0;
    edk::int32 sendStreamNonBlock(edk::network::Adress host,const void* stream,edk::uint32 size);
    edk::int32 sendStreamNonBlock(edk::char8* ip,edk::uint16 port,edk::classID stream,edk::uint32 size);
    edk::int32 sendStreamNonBlock(const edk::char8* ip,edk::uint16 port,edk::classID stream,edk::uint32 size);
    edk::int32 sendStreamNonBlock(edk::char8* ip,edk::uint16 port,const void* stream,edk::uint32 size);
    edk::int32 sendStreamNonBlock(const edk::char8* ip,edk::uint16 port,const void* stream,edk::uint32 size);
    //Recebe uma mensagem
    virtual edk::int32 receiveStream(edk::classID stream,edk::uint32 size,edk::network::Adress* host)=0;
    virtual edk::int32 receiveStreamNonBlock(edk::classID stream,edk::uint32 size,edk::network::Adress* host)=0;
protected:
    //create the socket
    bool createSocket(socketType type);
    //create a nonblock soket
    //bool createSocketNonBlock(socketType type);
    //return true if have the socket
    bool haveSocket();
    //return the socket
    edk::int32 getSocket();
    //close the socket
    void closeSocket();
    //clean the adress
    void cleanAdress();
    static void cleanAdress(struct sockaddr_in* adress);
    //Carrega o host pelo IP
    struct sockaddr_in getAdress(edk::uint32 IP);
    //Carrega o host pelo IP
    struct sockaddr_in getAdress(const edk::char8* host);
    struct sockaddr_in getAdress(edk::char8* host);
    //Adress used by the socket
    struct sockaddr_in sockAdress;
    //Send stream to
    static edk::int32 sendStream(edk::int32 socket,
                                 edk::classID stream,
                                 edk::uint32 size
                                 );
    static edk::int32 sendStreamNonBlock(edk::int32 socket,
                                         edk::classID stream,
                                         edk::uint32 size
                                         );
    edk::uint32 receiveStream(edk::int32 socket,
                              edk::classID stream,
                              edk::uint32 size
                              );
    edk::uint32 receiveStreamNonBlock(edk::int32 socket,
                                      edk::classID stream,
                                      edk::uint32 size
                                      );
    static edk::uint32 sendStreamTo(edk::int32  socket,
                                    sockaddr_in sendAdress,
                                    edk::classID stream,
                                    edk::uint32 size
                                    );
    static edk::uint32 sendStreamToNonBlock(edk::int32  socket,
                                            sockaddr_in sendAdress,
                                            edk::classID stream,
                                            edk::uint32 size
                                            );
    static edk::int32 receiveStreamFrom(edk::int32  socket,
                                        sockaddr_in *adress,
                                        edk::classID stream,
                                        edk::uint32 size
                                        );
    static edk::int32 receiveStreamFromNonBlock(edk::int32  socket,
                                                sockaddr_in *adress,
                                                edk::classID stream,
                                                edk::uint32 size
                                                );
private:
    //adress
    edk::int32 edkSocket;
};


}//end namespace network
}//end namespace edk

#endif // NETWORK_H
