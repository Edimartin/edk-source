#include "ServerTCP.h"

/*
Library ServerTCP - Server TCP for EDK
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

edk::network::tcp::ServerTCP::ServerTCP()
{
    this->listened=false;
}
edk::network::tcp::ServerTCP::~ServerTCP(){
    this->disconnect();
}

int haveClient(int socket){
    if(socket>=0){
        //set the wait timeout
#if _WIN32 || _WIN64
        edk::int32 rc = -1;
#else
        struct pollfd fds[200];
        //clean
        memset(fds,0,sizeof(fds));
        //set the socket
        fds[0u].fd = socket;
        fds[0u].events = POLLIN;
        edk::int32 rc = poll(fds,1,1/*Timeout*/);
#endif
        //test if have the client
        if(rc>0){
            //have the client.
            return 1;
        }
        else if(rc==0){
            //else dont have the client
            return 0;
        }
        else{
            //else the poll return error
            return -2;
        }
    }
    return -1;
}

//accept client
edk::network::Adress edk::network::tcp::ServerTCP::acceptTCPClient(bool nonBlock){
    edk::network::Adress host;
    //test if have the socket
    if(this->haveSocket() && this->haveListened()){
        sockaddr_in clientAdress;
        //socket do client
        edk::uint32 size = sizeof(struct sockaddr_in);
        edk::int32 client  = -1;
        if(nonBlock){
            //test if the socket have a client
            if(haveClient(this->getSocket())<=0){
                //
                return host;
            }
        }
#if _WIN32 || _WIN64
        client = accept(this->getSocket()
                        ,(struct sockaddr *)(&clientAdress)
                        ,(edk::int32*)&size
                        );
        //this->nonBloking=false;
#else
        client = accept(this->getSocket()
                        ,(struct sockaddr *)(&clientAdress)
                        ,(socklen_t*)&size
                        );
#endif
        //test if accept the client
        if(client>0){
            //save the clientHost
            //load the adress
            host.setIP(edk::network::Adress::getIpNumber(clientAdress.sin_addr.s_addr,0u),
                       edk::network::Adress::getIpNumber(clientAdress.sin_addr.s_addr,1u),
                       edk::network::Adress::getIpNumber(clientAdress.sin_addr.s_addr,2u),
                       edk::network::Adress::getIpNumber(clientAdress.sin_addr.s_addr,3u)
                       );
            host.setPort(clientAdress.sin_port);
            //load the client
            edk::network::tcp::ServerTCP::nodeAdressTCP* temp = (edk::network::tcp::ServerTCP::nodeAdressTCP*)this->tree.getAdress(host);
            if(temp){
                //just set the socket
                temp->socket=client;
                return host;
            }
            else{
                //else create the new adress
                temp = new edk::network::tcp::ServerTCP::nodeAdressTCP;
                if(temp){
                    temp->host=host;
                    temp->socket=client;
                    //add
                    if(this->tree.add(temp)){
                        return host;
                    }
                    delete temp;
                    host = edk::network::Adress();
                }
            }
        }
    }
    //senao retorna 0u
    return host;
}

//Inicia a ouvir a porta
edk::network::networkCodes edk::network::tcp::ServerTCP::startListen(edk::uint16 port,edk::uint32 connections){
    if(!this->haveSocket()){
        this->createSocket(EDK_SOCKET_TCP);
        this->cleanAdress();
    }
    //testa se possui o socket
    if(this->haveSocket()){
        //testa se ja esta ouvindo
        if(this->listened){
            //retorna true
            return edk::network::ok;
        }
        edk::int32 on = 1;


#if _WIN32 || _WIN64
        setsockopt (this->getSocket(), SOL_SOCKET, SO_REUSEADDR, (const edk::char8*)&on, sizeof (on));

#else
        setsockopt (this->getSocket(), SOL_SOCKET, SO_REUSEADDR, &on, sizeof (on));
#endif

        //setsockopt (this->getSocket(), SOL_SOCKET, SO_REUSEADDR, &on, sizeof (on));
        //Seta a porta no myAdress
        this->sockAdress.sin_port = htons(port);
        //Inicia o bind
        if (bind(this->getSocket(), (struct sockaddr *)&this->sockAdress, sizeof(struct sockaddr))== -1){
            this->cleanAdress();
            return edk::network::cantStartBind;
        }
        //senao testa ouvir pela primeira vez
        if (listen(this->getSocket(), connections) >= 0){
            this->listened = true;
            return edk::network::ok;
        }
    }
    this->closeSocket();
    //senao retorna false
    return edk::network::cantStartListen;
}
//test if have listened
bool edk::network::tcp::ServerTCP::haveListened(){
    return this->listened;
}
//accept client
edk::network::Adress edk::network::tcp::ServerTCP::acceptClient(){
    return this->acceptTCPClient(false);
}
edk::network::Adress edk::network::tcp::ServerTCP::acceptClientNonBlock(){
    return this->acceptTCPClient(true);
}
//Send the message
edk::int32 edk::network::tcp::ServerTCP::sendStream(edk::network::Adress host,edk::classID stream,edk::uint32 size){
    //test the host and stream
    if(host.getIP() && host.getPort() && stream && size){
        //search the adress
        edk::network::tcp::ServerTCP::nodeAdressTCP* temp = (edk::network::tcp::ServerTCP::nodeAdressTCP*)this->tree.getAdress(host);
        if(temp){
            if(temp->socket){
                //send the stream
                return edk::network::Socket::sendStream(temp->socket,stream,size);
            }
            else{
                this->disconnectClient(host);
            }
        }
    }
    return false;
}
edk::int32 edk::network::tcp::ServerTCP::sendStreamNonBlock(edk::network::Adress host,edk::classID stream,edk::uint32 size){
    //test the host and stream
    if(host.getIP() && host.getPort() && stream && size){
        //search the adress
        edk::network::tcp::ServerTCP::nodeAdressTCP* temp = (edk::network::tcp::ServerTCP::nodeAdressTCP*)this->tree.getAdress(host);
        if(temp){
            if(temp->socket){
                //send the stream
                return edk::network::Socket::sendStreamNonBlock(temp->socket,stream,size);
            }
            else{
                this->disconnectClient(host);
            }
        }
    }
    return false;
}
edk::int32 edk::network::tcp::ServerTCP::sendString(edk::network::Adress host,edk::char8* string){
    return this->sendStream(host,string,edk::String::strSize(string)+1u);
}
edk::int32 edk::network::tcp::ServerTCP::sendString(edk::network::Adress host,const edk::char8* string){
    return this->sendString(host,(edk::char8*) string);
}
edk::int32 edk::network::tcp::ServerTCP::sendStringNonBlock(edk::network::Adress host,edk::char8* string){
    return this->sendStreamNonBlock(host,string,edk::String::strSize(string)+1u);
}
edk::int32 edk::network::tcp::ServerTCP::sendStringNonBlock(edk::network::Adress host,const edk::char8* string){
    return this->sendStringNonBlock(host,(edk::char8*) string);
}
//Receive the message
edk::int32 edk::network::tcp::ServerTCP::receiveStream(edk::classID stream,edk::uint32 size,edk::network::Adress* host){
    //test the host and stream
    if(host && stream && size){
        //search the adress
        edk::network::tcp::ServerTCP::nodeAdressTCP* temp = (edk::network::tcp::ServerTCP::nodeAdressTCP*)this->tree.getAdress(*host);
        if(temp){
            if(temp->socket){
                //send the stream
                edk::int32 ret  =  edk::network::Socket::receiveStream(temp->socket,stream,size);
                if(ret!=0){
                    return ret;
                }
            }
            else{
                this->disconnectClient(*host);
            }
        }
    }
    return 0;
}
edk::int32 edk::network::tcp::ServerTCP::receiveStream(edk::classID stream,edk::uint32 size,edk::network::Adress host){
    return this->receiveStream(stream,size,&host);
}
edk::int32 edk::network::tcp::ServerTCP::receiveStreamNonBlock(edk::classID stream,edk::uint32 size,edk::network::Adress* host){
    //test the host and stream
    if(host && stream && size){
        //search the adress
        edk::network::tcp::ServerTCP::nodeAdressTCP* temp = (edk::network::tcp::ServerTCP::nodeAdressTCP*)this->tree.getAdress(*host);
        if(temp){
            if(temp->socket){
                //send the stream
                edk::int32 ret  =  edk::network::Socket::receiveStreamNonBlock(temp->socket,stream,size);
                if(ret!=0){
                    return ret;
                }
            }
            else{
                this->disconnectClient(*host);
            }
        }
    }
    return 0;
}
edk::int32 edk::network::tcp::ServerTCP::receiveStreamNonBlock(edk::classID stream,edk::uint32 size,edk::network::Adress host){
    return this->receiveStreamNonBlock(stream,size,&host);
}
//disconnect the server
void edk::network::tcp::ServerTCP::disconnect(){
    this->listened=false;
    this->closeSocket();
    this->cleanAdress();
    this->tree.deleteAllAdress();
}
//disconnect the client
bool edk::network::tcp::ServerTCP::disconnectClient(edk::network::Adress host){
    //load the adress
    edk::network::tcp::ServerTCP::nodeAdressTCP* temp = (edk::network::tcp::ServerTCP::nodeAdressTCP*)this->tree.getAdress(host);
    if(temp){
        //test the socket
        if(this->tree.remove(temp)){
            //close the socket
            if(temp->socket){
                close(temp->socket);
            }
            delete temp;
            return true;
        }
    }
    return false;
}
//return the number of connected clients
edk::uint32 edk::network::tcp::ServerTCP::getClients(){
    return this->tree.size();
}
