#include "CommandParser.h"

/*
Library C++ CommandParser - Parse Argc Argv.
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
#warning "            Inside CommandParser.cpp"
#endif


edk::CommandParser::Command::Command(){
    //
    this->position=0u;
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
           ,temp->value.getName()?temp->value.getName():" "
           );
}
//print only the command name
void edk::CommandParser::TreeCommand::renderElement(edk::Name* value){
    printf("\n%s"
           ,value->getName()
           );
}

//print
void edk::CommandParser::TreeCommand::printElements(){
    edk::uint32 size = this->stack.size();
    edk::CommandParser::Command* temp = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::CommandParser::Command*)this->stack.get(i);
        if(temp){
            printf("\n%s"
                   ,temp->getName()
                   );
        }
    }
}
void edk::CommandParser::TreeCommand::printElementsWithValues(){
    edk::uint32 size = this->stack.size();
    edk::CommandParser::Command* temp = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        temp = (edk::CommandParser::Command*)this->stack.get(i);
        if(temp){
            printf("\n%s %s"
                   ,temp->getName()
                   ,temp->value.getName()?temp->value.getName():" "
                   );
        }
    }
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

                            //add the command in the stack
                            edk::uint32 size = this->stack.size();
                            temp->position = this->stack.pushBack((edk::Name*)temp);
                            if(size<this->stack.size()){
                                return true;
                            }
                            //else remove the temp from the tree
                            this->remove(temp);
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
            edk::uint32 size = this->stack.size();
            if(size){
                if(this->stack.havePos(temp->position)){
                    //set the position into the last position
                    this->stack.bringPositionTo(temp->position,size-1u);
                    //remove the temp
                    this->stack.remove(size-1u);
                    size--;

                    edk::CommandParser::Command* tempCommand = NULL;
                    //update the positions
                    for(edk::uint32 i=temp->position;i<size;i++){
                        tempCommand = (edk::CommandParser::Command*)this->stack.get(i);
                        if(tempCommand){
                            tempCommand->position = i;
                        }
                    }

                    //remove the command
                    if(this->remove(temp)){
                        delete temp;
                        return true;
                    }
                }
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
    edk::CommandParser::Command* temp = (edk::CommandParser::Command*)this->stack.get(position);
    if(temp){
        //return the value
        return temp->getName();
    }
    //else return NULL
    return NULL;
}
//remove all commands on the tree
void edk::CommandParser::TreeCommand::clean(){
    this->cleanCommands();
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
    edk::CommandParser::Command* temp = (edk::CommandParser::Command*)this->stack.get(position);
    if(temp){
        //return the value
        return temp->value.getName();
    }
    //else return NULL
    return NULL;
}
//clean commands
void edk::CommandParser::TreeCommand::cleanCommands(){
    //clean the stack first
    this->stack.clean();
    //delete from tree
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

edk::CommandParser::CommandParser(){
    //
}
edk::CommandParser::CommandParser(edk::int32 argc,edk::char8* argv[]){
    this->parseArgcArgv(argc,argv);
}

edk::CommandParser::~CommandParser(){
    //
    this->tree.clean();
}

//new command
bool edk::CommandParser::addCommand(const edk::char8* command,const edk::char8* value){
    return addCommand((edk::char8*) command,(edk::char8*) value);
}
bool edk::CommandParser::addCommand(edk::char8* command,edk::char8* value){
    return this->tree.addCommand(command,value);
}
//remove a command
bool edk::CommandParser::removeCommand(const edk::char8* command){
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
bool edk::CommandParser::haveCommand(const edk::char8* command){
    return haveCommand((edk::char8*) command);
}
bool edk::CommandParser::haveCommand(edk::char8* command){
    return this->tree.haveCommand(command);
}
//return the value of a command
edk::char8* edk::CommandParser::getValue(const edk::char8* command){
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
    this->tree.printElements();
}
void edk::CommandParser::printCommandsWithValues(){
    this->tree.printElementsWithValues();
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
