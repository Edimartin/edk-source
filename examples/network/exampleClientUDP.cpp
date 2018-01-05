#include <stdio.h>

#include "edk/String.h"
#include "edk/watch/FPS.h"
#include "edk/network/udp/ClientUDP.h"

void printHelp(){
    printf("\nYou need pass only the host and port number\n\n");fflush(stdout);
}

int main(int argc,char* argv[]){
    edk::uint16 port=0u;
    edk::char8* host=NULL;
    //test the size
    if(argc==3){
        //read the host
        printf("\nHost == %s",argv[1u]);fflush(stdout);
        host = edk::String::strCopy(argv[1u]);
        //load the port
        printf("\nPort == %s",argv[2u]);fflush(stdout);
        edk::int64 temp = edk::String::strToInt32(argv[2]);
        if(temp>0 && temp<65535){
            port = temp;
        }
        //
    }
    else{
        //else
        printHelp();
        return 0;
    }

    //test the host
    if(host){
        //start the client
        edk::network::udp::ClientUDP client;
        edk::int32 ret = 0;
        edk::char8* str=NULL;
        edk::watch::FPS fps(30u);
        edk::char8 buffer[1024];
        edk::network::Adress address;

        bool looping = true;
        fps.start();
        while(looping){
            //receive the message
            ret = client.receiveStreamNonBlock(buffer,sizeof(buffer)-1u,&address);
            if(ret>0){
                buffer[ret]='\0';
                printf("\nRet == %d from ",ret);fflush(stdout);
                address.printIP();fflush(stdout);
                printf("\n%s",buffer);fflush(stdout);
            }
            //
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
                        client.sendString(host,port,str);
                        delete str;
                        printf("\nSend");
                    }
                }
            }
            fps.waitForFPS();
        }
        client.closeSocket();

        //delete the host string
        delete host;
    }

    printf("\n\n");
    return 0;
}

