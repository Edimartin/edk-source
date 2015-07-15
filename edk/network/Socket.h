#ifndef EDK_NETWORK_SOCKET_H
#define EDK_NETWORK_SOCKET_H

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

#pragma once
#include <stdio.h>
#include <stdlib.h>

#if _WIN32 || _WIN64
/*LIBS
-lwsock32
*/
#include <windows.h>
#include <winsock.h>
#include <winsock2.h>
#define bzero(b,len) (memset((b), '\0', (len)), (void) 0)
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#endif
#include <sys/types.h>
#include <string.h>

#include <unistd.h>

#include "../TypeVars.h"
#include "../String.h"
#include "../TypeDefines.h"

//Socket Type
//EDK_SOCKET_NONE
//EDK_SOCKET_UDP
//EDK_SOCKET_TCP

namespace edk{
namespace network{


class Adress{
public:
    Adress();
    Adress(edk::uchar8 n1,edk::uchar8 n2,edk::uchar8 n3,edk::uchar8 n4,edk::uint16 port);
    Adress(edk::char8* str,edk::uint16 port);
    Adress(const char* str,edk::uint16 port);
    //Adress Functions
    //set the IP
    bool setIP(edk::uchar8 n1,edk::uchar8 n2,edk::uchar8 n3,edk::uchar8 n4);
    bool setIP(edk::char8* str);
    bool setIP(const char* str);
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
        this->port=adress.port;
        this->ip=adress.ip;
        return adress;
    }
    bool operator==(Adress adress){
        return (bool)( (adress.ip==this->ip)&&(adress.port==this->port));
    }
    bool operator!=(Adress adress){
        return (bool)( (adress.ip!=this->ip)||(adress.port!=this->port));
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
    static edk::uint32 getIP(const char* str);
    //return the IP by the name
    static edk::uint32 getIpByName(edk::char8* name);
    static edk::uint32 getIpByName(const char* name);
    //convert ipToString
    static edk::char8* ipToString(edk::uint32 ip);
    static bool ipToString(edk::uint32 ip,edk::char8* str);
    //print the ip
    static void printIP(edk::uint32 ip);

private:
    edk::uint16 port;
    edk::uint32 ip;
};


//Socket class
class Socket{
public:
    Socket();
    ~Socket();

    //Send a message to the server
    virtual bool sendStream(edk::network::Adress host,edk::classID stream,edk::uint32 size)=0;
    bool sendStream(edk::network::Adress host,const void* stream,edk::uint32 size);
    bool sendStream(edk::char8* ip,edk::uint16 port,edk::classID stream,edk::uint32 size);
    bool sendStream(const char* ip,edk::uint16 port,edk::classID stream,edk::uint32 size);
    bool sendStream(edk::char8* ip,edk::uint16 port,const void* stream,edk::uint32 size);
    bool sendStream(const char* ip,edk::uint16 port,const void* stream,edk::uint32 size);
    //Recebe uma mensagem
    virtual edk::int32 receiveStream(edk::classID stream,edk::uint32 size,edk::network::Adress* host)=0;
protected:
    //create the socket
    bool createSocket(socketType type);
    //return true if have the socket
    bool haveSocket();
    //return the socket
    edk::uint32 getSocket();
    //close the socket
    void closeSocket();
    //clean the adress
    void cleanAdress();
    static void cleanAdress(struct sockaddr_in* adress);
    //Carrega o host pelo IP
    struct sockaddr_in getAdress(edk::uint32 IP);
    //Carrega o host pelo IP
    struct sockaddr_in getAdress(const char* host);
    struct sockaddr_in getAdress(edk::char8* host);
    //Adress used by the socket
    struct sockaddr_in sockAdress;
    //Send stream to
    static edk::int32 sendStream(edk::int32 socket,
                                edk::classID stream,
                                edk::uint32 size
                                );
    edk::uint32 receiveStream(edk::int32 socket,
                              edk::classID stream,
                              edk::uint32 size
                              );
    static bool sendStreamTo(edk::int32  socket,
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
    int edkSocket;
};


}//end namespace network
}//end namespace edk

#endif // NETWORK_H
