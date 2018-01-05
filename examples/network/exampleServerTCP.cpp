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

