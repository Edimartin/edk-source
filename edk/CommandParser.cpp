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
    this->clean();
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
//return the command istring in a position
edk::char8* edk::CommandParser::TreeCommand::getCommandInPosition(edk::uint32 position){
    //test if have the position
    edk::CommandParser::Command* temp = (edk::CommandParser::Command*)this->getElementInPosition(position);
    if(temp){
        //return the value
        return temp->getName();
    }
    //else return NULL
    return NULL;
}
//remove all commands on the tree
void edk::CommandParser::TreeCommand::clean(){
    edk::uint32 size = this->size();
    edk::CommandParser::Command* temp=NULL;
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::CommandParser::Command*)this->getElementInPosition(i);
        if(temp){
            delete temp;
        }
    }
    edk::vector::NameTree::clean();
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
//get command value in position
edk::char8* edk::CommandParser::TreeCommand::getValueInPosition(edk::uint32 position){
    //test if have the position
    edk::CommandParser::Command* temp = (edk::CommandParser::Command*)this->getElementInPosition(position);
    if(temp){
        //return the value
        return temp->value.getName();
    }
    //else return NULL
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
//clean the commands
void edk::CommandParser::cleanCommands(){
    this->tree.cleanCommands();
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
//return the value of the command in position
edk::char8* edk::CommandParser::getValueInPosition(edk::uint32 position){
    return this->tree.getValueInPosition(position);
}
//return the command string in a position
edk::char8* edk::CommandParser::getCommandInPosition(edk::uint32 position){
    return this->tree.getCommandInPosition(position);
}
//return the size of the commands
edk::uint32 edk::CommandParser::getCommandsSize(){
    return this->tree.size();
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
        edk::char8 character[3u];
        character[0u]='-';
        character[2u]='\0';
        //test the argc,argv
        for(edk::int32 i=1;i<argc;i++){
            //test the commad
            if(argv[i]){
                temp = argv[i];
                //test if have '-'
                if(temp[0u] == '-'){
                    //test if have the second '-'
                    if(temp[1u] == '-'){
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

                        //else read the single command
                        this->addCommand(argv[i],argv[i]);
                        //increment i to teste the next two argv's
                        continue;
                    }
                    else{
                        //test if is not only one character
                        if(temp[2u]!='\0' && temp[2u]!='='){
                            //read the characters
                            while(temp[1u]){
                                character[1u] = temp[1u];
                                this->addCommand((edk::char8*)character,(edk::char8*)character);
                                temp++;
                            }
                            //increment i to teste the next two argv's
                            continue;
                        }
                    }
                }
                else{
                    this->addCommand(argv[i],argv[i]);
                    continue;
                }

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
                    //test if have the attribution
                    temp = argv[i+1u];
                    //test if the temp is an '-'
                    if(*temp=='-'){
                        //then add the single command
                        this->addCommand(argv[i],argv[i]);
                        continue;
                    }

                    //else test if have an attribution
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
                else{
                    //else add the single command
                    this->addCommand(argv[i],argv[i]);
                }
            }
        }
        return true;
    }
    return false;
}
