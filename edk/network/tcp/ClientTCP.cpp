#include "ClientTCP.h"

/*
Library ClientTCP - Client TCP for EDK
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
edk::network::tcp::ClientTCP::ClientTCP(){
    //
    this->connected=false;
    this->cleanAdress();
}
//connect the socket with a server
edk::network::networkCodes edk::network::tcp::ClientTCP::connectSocket(edk::network::Adress host){
    //disconnect the last connection
    this->disconnect();
    //test the host
    if(host.getIP()&&host.getPort()){
        //test if have NOT the socket
        if(!this->haveSocket()){
            //create a new socket
            if(!this->createSocket(EDK_SOCKET_TCP)){
                return edk::network::cantCreateSocket;
            }
        }
        if(this->haveSocket()){
            //set the adress
            this->sockAdress = this->getAdress(host.getIP());
            this->sockAdress.sin_port = htons(host.getPort());
            //connect
            edk::int32 ret = connect(this->getSocket()
                                     ,(struct sockaddr *)&this->sockAdress
                                     ,sizeof(struct sockaddr)
                                     );
            if(ret>=0){
                //
                this->connected=true;
                this->serverHost=host;
                return edk::network::ok;
            }
            else{
#if _WIN32 || _WIN64
#else
                //disconnect the last connection
                this->disconnect();
                //Linux error code
                switch(errno){
                case ECONNREFUSED:
                    return edk::network::connectionRefused;
                }
#endif
            }
        }
    }
    //disconnect the last connection
    this->disconnect();
    return edk::network::error;
}
edk::network::networkCodes edk::network::tcp::ClientTCP::connectSocket(edk::uint32 ip,edk::uint16 port){
    return this->connectSocket(edk::network::Adress(ip,port));
}
edk::network::networkCodes edk::network::tcp::ClientTCP::connectSocket(edk::char8* ip,edk::uint16 port){
    return this->connectSocket(edk::network::Adress(ip,port));
}
edk::network::networkCodes edk::network::tcp::ClientTCP::connectSocket(const edk::char8* ip,edk::uint16 port){
    return this->connectSocket(edk::network::Adress(ip,port));
}

//test if have connection
bool edk::network::tcp::ClientTCP::haveConnection(){
    return this->connected;
}
//disconnect
void edk::network::tcp::ClientTCP::disconnect(){
    //
    this->closeSocket();
    this->cleanAdress();
    this->connected=false;
}

//send stream to server
edk::int32 edk::network::tcp::ClientTCP::sendStream(edk::network::Adress host,edk::classID stream,edk::uint32 size){
    if(host.getIP() && host.getPort() && stream && size){
        //Test if the host is diferent
        if(host != this->serverHost){
            //then close the connection and connect with the new host
            this->disconnect();
            if(!this->connectSocket(host)){
                return false;
            }
        }
        //test if the host are equal then the host connected
        if(host == this->serverHost){
            //send the stream
            return this->sendStream(stream,size);
        }
    }
    return false;
}
edk::int32 edk::network::tcp::ClientTCP::sendStreamNonBlock(edk::network::Adress host,edk::classID stream,edk::uint32 size){
    if(host.getIP() && host.getPort() && stream && size){
        //Test if the host is diferent
        if(host != this->serverHost){
            //then close the connection and connect with the new host
            this->disconnect();
            if(!this->connectSocket(host)){
                return false;
            }
        }
        //test if the host are equal then the host connected
        if(host == this->serverHost){
            //send the stream
            return this->sendStreamNonBlock(stream,size);
        }
    }
    return false;
}
edk::int32 edk::network::tcp::ClientTCP::sendString(edk::network::Adress host,edk::char8* string){
    return this->sendStream(host,string,edk::String::strSize(string)+1u);
}
edk::int32 edk::network::tcp::ClientTCP::sendString(edk::network::Adress host,const edk::char8* string){
    return this->sendString(host,(edk::char8*) string);
}
edk::int32 edk::network::tcp::ClientTCP::sendStringNonBlock(edk::network::Adress host,edk::char8* string){
    return this->sendStreamNonBlock(host,string,edk::String::strSize(string)+1u);
}
edk::int32 edk::network::tcp::ClientTCP::sendStringNonBlock(edk::network::Adress host,const edk::char8* string){
    return this->sendStringNonBlock(host,(edk::char8*) string);
}
edk::int32 edk::network::tcp::ClientTCP::sendStream(edk::classID stream,edk::uint32 size){
    //test the stream e size
    if(stream && size && this->haveSocket() && this->haveConnection()){
        //send the message
        return edk::network::Socket::sendStreamTo(this->getSocket(),this->sockAdress,stream,size);
    }
    return false;
}
edk::int32 edk::network::tcp::ClientTCP::sendStream(const edk::char8* stream,edk::uint32 size){
    return this->sendStream((edk::classID) stream,size);
}
edk::int32 edk::network::tcp::ClientTCP::sendStreamNonBlock(edk::classID stream,edk::uint32 size){
    //test the stream e size
    if(stream && size && this->haveSocket() && this->haveConnection()){
        //send the message
        return edk::network::Socket::sendStreamToNonBlock(this->getSocket(),this->sockAdress,stream,size);
    }
    return false;
}
edk::int32 edk::network::tcp::ClientTCP::sendStreamNonBlock(const edk::char8* stream,edk::uint32 size){
    return this->sendStreamNonBlock((edk::classID) stream,size);
}
edk::int32 edk::network::tcp::ClientTCP::sendString(edk::char8* string){
    return this->sendStream(string,edk::String::strSize(string)+1u);
}
edk::int32 edk::network::tcp::ClientTCP::sendString(const edk::char8* string){
    return this->sendString((edk::char8*)string);
}
edk::int32 edk::network::tcp::ClientTCP::sendStringNonBlock(edk::char8* string){
    return this->sendStreamNonBlock(string,edk::String::strSize(string)+1u);
}
edk::int32 edk::network::tcp::ClientTCP::sendStringNonBlock(const edk::char8* string){
    return this->sendStringNonBlock((edk::char8*)string);
}
//receive the stream from the server
edk::int32 edk::network::tcp::ClientTCP::receiveStream(edk::classID stream,edk::uint32 size,edk::network::Adress* host){
    if(host && stream && size){
        //test if the host is diferent
        if(*host != this->serverHost){
            //then close the connection and connect with the new host
            this->disconnect();
            if(!this->connectSocket(*host)){
                return false;
            }
        }
        //test if the host are equal
        if(*host == this->serverHost){
            //then receive the message
            return edk::network::Socket::receiveStreamFrom(this->getSocket(),&this->sockAdress,stream,size);
        }
    }
    return 0u;
}
edk::int32 edk::network::tcp::ClientTCP::receiveStream(edk::classID stream,edk::uint32 size){
    //test the stream e size
    if(stream && size && this->haveSocket() && this->haveConnection()){
        //receive the message
        //edk::int32 ret = this->receiveStreamFunction(stream,size,this->getSocket(),&this->sockAdress);
        edk::int32 ret = edk::network::Socket::receiveStreamFrom(this->getSocket(),&this->sockAdress,stream,size);
        //
        return ret;
    }
    return 0u;
}
edk::int32 edk::network::tcp::ClientTCP::receiveStreamNonBlock(edk::classID stream,edk::uint32 size,edk::network::Adress* host){
    if(host && stream && size){
        //test if the host is diferent
        if(*host != this->serverHost){
            //then close the connection and connect with the new host
            this->disconnect();
            if(!this->connectSocket(*host)){
                return false;
            }
        }
        //test if the host are equal
        if(*host == this->serverHost){
            //then receive the message
            return edk::network::Socket::receiveStreamFromNonBlock(this->getSocket(),&this->sockAdress,stream,size);
        }
    }
    return 0u;
}
edk::int32 edk::network::tcp::ClientTCP::receiveStreamNonBlock(edk::classID stream,edk::uint32 size){
    //test the stream e size
    if(stream && size && this->haveSocket() && this->haveConnection()){
        //receive the message
        //edk::int32 ret = this->receiveStreamFunction(stream,size,this->getSocket(),&this->sockAdress);
        edk::int32 ret = edk::network::Socket::receiveStreamFromNonBlock(this->getSocket(),&this->sockAdress,stream,size);
        //
        return ret;
    }
    return 0u;
}
