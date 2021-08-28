/*
Library EDK - How to create an TCP client
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
#include "edk/network/tcp/ClientTCP.h"

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
        edk::network::tcp::ClientTCP client;
        edk::int32 ret = 0;
        edk::char8* str=NULL;
        edk::watch::FPS fps;
        edk::char8 buffer[1024];

        bool looping = true;
        bool loopingServer = true;
        fps.setFPS(1);
        fps.start();
        while(looping){
            loopingServer=true;
            //try to connect with the server
            printf("\nTry connect with the server %s on port %u",host,port);fflush(stdout);
            if(client.connectSocket(host,port)){

                fps.setFPS(30);
                fps.start();
                printf("\nConnect with the server");fflush(stdout);
                while(looping && loopingServer){
                    //receive the message
                    ret = client.receiveStreamNonBlock(buffer,sizeof(buffer)-1u);
                    if(ret>0){
                        buffer[ret]='\0';
                        printf("\nRet == %d from %s",ret,host);fflush(stdout);
                        printf("\n%s",buffer);fflush(stdout);
                    }
                    else if(ret==0){
                        //server disconnect
                        printf("\nServer Disconnect");fflush(stdout);
                        loopingServer=false;
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
                                ret = client.sendString(str);
                                delete str;
                                printf("\nSend");
                            }
                        }
                    }
                    if(looping && loopingServer)
                    fps.waitForFPS();
                }
                client.disconnect();
                fps.setFPS(1);
                fps.start();
            }
            else{
                printf("\n    Can't connect with the server");fflush(stdout);
            }
            if(edk::String::consoleKeyPressed()){
                if(edk::String::consoleReadKey() == 27){
                    //close the server
                    looping = false;
                    break;
                }
            }
            if(looping)
            fps.waitForFPS();
        }

        //delete the host string
        delete host;
    }

    printf("\n\n");
    return 0;
}

