#include "CommandParser.h"

/*
Library C++ CommandParser - Parse Argc Argv.
Copyright (C) 1013 Eduardo Moura Sales Martins
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

#ifdef printMessages
#warning "            Inside CommandParser.cpp"
#endif


edk::CommandParser::Command::Command(){
    //
}
edk::CommandParser::Command::~Command(){
    //
    this->cleanName();
    this->value.cleanName();
}

edk::CommandParser::TreeCommand::TreeCommand(){
    //
}
edk::CommandParser::TreeCommand::~TreeCommand(){
    //
}

//Print the command and value
void edk::CommandParser::TreeCommand::printElement(edk::Name* value){
    edk::CommandParser::Command* temp = (edk::CommandParser::Command*)value;
    printf("\n%s %s"
           ,temp->getName()
           ,temp->value.getName()
           );
}
//print only the command name
void edk::CommandParser::TreeCommand::renderElement(edk::Name* value){
    printf("\n%s"
           ,value->getName()
           );
}
//add the command
bool edk::CommandParser::TreeCommand::addCommand(edk::char8* command,edk::char8* value){
    //test if have the command
    if(command){
        edk::CommandParser::Command* temp = (edk::CommandParser::Command*)this->getElementByName(command);
        if(!temp){
            //create a new commmand
            temp = new edk::CommandParser::Command;
            if(temp){
                if(temp->setName(command)){
                    if(temp->value.setName(value)){
                        //add the command to the tree
                        if(this->add(temp)){
                            return true;
                        }
                    }
                }
            }
            delete temp;
        }
    }
    return false;
}
//remove command
bool edk::CommandParser::TreeCommand::removeCommand(edk::char8* command){
    //test if have the command
    if(command){
        edk::CommandParser::Command* temp = (edk::CommandParser::Command*)this->getElementByName(command);
        if(temp){
            //remove the command
            if(this->remove(temp)){
                delete temp;
                return true;
            }
        }
    }
    return false;
}
//test if have the command
bool edk::CommandParser::TreeCommand::haveCommand(edk::char8* command){
    return this->haveName(command);
}
//get command value
edk::char8* edk::CommandParser::TreeCommand::getValue(edk::char8* command){
    //test if have the command
    if(command){
        edk::CommandParser::Command* temp = (edk::CommandParser::Command*)this->getElementByName(command);
        if(temp){
            return temp->value.getName();
        }
    }
    return NULL;
}
//clean commands
void edk::CommandParser::TreeCommand::cleanCommands(){
    edk::uint32 position = 0u;
    edk::uint32 treeSize = this->size();
    edk::CommandParser::Command* temp = NULL;
    for(edk::uint32 i=0u;i<treeSize;i++){
        temp = (edk::CommandParser::Command*)this->getElementInPosition(position);
        if(this->remove(temp)){
            delete temp;
        }
        else{
            position++;
        }
    }
}

edk::CommandParser::CommandParser(){
    //
}
edk::CommandParser::CommandParser(edk::int32 argc,edk::char8* argv[]){
    this->parseArgcArgv(argc,argv);
}

edk::CommandParser::~CommandParser(){
    //
}

//new command
bool edk::CommandParser::addCommand(const char* command,const char* value){
    return addCommand((edk::char8*) command,(edk::char8*) value);
}
bool edk::CommandParser::addCommand(edk::char8* command,edk::char8* value){
    return this->tree.addCommand(command,value);
}
//remove a command
bool edk::CommandParser::removeCommand(const char* command){
    return removeCommand((edk::char8*) command);
}
bool edk::CommandParser::removeCommand(edk::char8* command){
    return this->tree.removeCommand(command);
}
//test if have a command
bool edk::CommandParser::haveCommand(const char* command){
    return haveCommand((edk::char8*) command);
}
bool edk::CommandParser::haveCommand(edk::char8* command){
    return this->tree.haveCommand(command);
}
//return the value of a command
edk::char8* edk::CommandParser::getValue(const char* command){
    return getValue((edk::char8*) command);
}
edk::char8* edk::CommandParser::getValue(edk::char8* command){
    return this->tree.getValue(command);
}

//print commands
void edk::CommandParser::printCommands(){
    this->tree.render();
}
void edk::CommandParser::printCommandsWithValues(){
    this->tree.print();
}

//parse ARGC and ARGV
bool edk::CommandParser::parseArgcArgv(edk::int32 argc,edk::char8* argv[]){
    if(argc>1 && argv){
        edk::char8* temp=NULL;
        //test the argc,argv
        for(edk::int32 i=1;i<argc;i++){
            //test the commad
            if(argv[i]){
                temp = argv[i];
                //test if have an attribution
                while(*temp){
                    //test if have an attribution
                    if(*temp=='='){
                        //remove the attribution
                        *temp='\0';
                        temp++;
                        if(*temp){
                            //then add the command
                            this->addCommand(argv[i],temp);
                            temp=NULL;
                            break;
                        }
                    }
                    temp++;
                }
                if(!temp) continue;
                //else test if have the next argv
                if(argv[i+1u]){
                    //test if have the attributio
                    temp = argv[i+1u];
                    //test if have an attribution
                    while(*temp){
                        //test if have an attribution
                        if(*temp=='='){
                            //remove the attribution
                            *temp='\0';
                            temp++;
                            if(*temp){
                                //then add the command
                                this->addCommand(argv[i+1u],temp);
                            }
                        }
                        temp++;
                    }
                    //else add the normal command with two argv's
                    this->addCommand(argv[i],argv[i+1u]);
                    //increment i to teste the next two argv's
                    i++;
                }
            }
        }
        return true;
    }
    return false;
}
