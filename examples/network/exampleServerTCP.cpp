/*
Library EDK - How to create a TCP server
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

#include <stdio.h>

#include "edk/String.h"
#include "edk/watch/FPS.h"
#include "edk/network/tcp/ServerTCP.h"

void printHelp(){
    printf("\nYou need pass only the port number\n\n");fflush(stdout);
}

int main(int argc,char* argv[]){
    edk::uint16 port=0u;
    //test the size
    if(argc==2){
        //load the port
        printf("\nPort == %s",argv[1u]);fflush(stdout);
        edk::int64 temp = edk::String::strToInt32(argv[1]);
        if(temp>0 && temp<65535){
            port = temp;
        }
    }
    else{
        //else
        printHelp();
        return 0;
    }

    edk::watch::FPS fps(30u);
    edk::char8 buffer[1024];
    edk::network::Adress address;
    edk::int32 ret=0u;
    edk::char8* str=NULL;
    //start the server
    edk::network::tcp::ServerTCP server;
    if(server.startListen(port,1u)){
        bool looping = true;
        bool loopingClient = true;
        bool printWait=false;
        fps.start();
        while(looping){
            if(!printWait){
                printf("\nWait to accept the client");fflush(stdout);
                printWait=true;
            }
            address = server.acceptClientNonBlock();
            if(address.getIP() && address.getPort()){
                printWait=false;
                loopingClient = true;
                printf("\nAccept client ");fflush(stdout);
                address.printIP();
                printf(" on port %u"
                       ,address.getPort()
                       );fflush(stdout);
                while(looping && loopingClient){
                    //accept the client
                    ret = server.receiveStreamNonBlock(buffer,sizeof(buffer)-1u,address);
                    if(ret>0){
                        buffer[ret]='\0';
                        //receive something
                        printf("\nReceive from ");fflush(stdout);
                        address.printIP();fflush(stdout);
                        printf("\n%s",buffer);fflush(stdout);
                    }
                    else if(ret==0){
                        //client disconnect
                        printf("\nClient ");fflush(stdout);
                        address.printIP();
                        printf(" disconnect");fflush(stdout);
                        loopingClient = false;
                    }

                    if(edk::String::consoleKeyPressed()){
                        switch(edk::String::consoleReadKey()){
                        case 27:
                            //close the server
                            looping = false;
                            break;
                        default:
                            printf("\nWrite something and press return:\n");
                            //read a string
                            str = edk::String::consoleReadString();
                            if(str){
                                //
                                //send the string
                                ret = server.sendString(address,str);
                                printf("\nSend");
                                delete str;
                            }
                        }
                    }
                    fps.waitForFPS();
                }
                server.disconnectClient(address);
            }

            if(edk::String::consoleKeyPressed()){
                if(edk::String::consoleReadKey() == 27){
                    //close the server
                    looping = false;
                    break;
                }
            }
            fps.waitForFPS();
        }

        //close server
        printf("\nDisconnect the server");fflush(stdout);
        server.disconnect();
    }
    else{
        //cant connet in port
        printf("\nServer can't connect in port %u"
               ,port
               );
    }

    printf("\n\n");
    return 0;
}

