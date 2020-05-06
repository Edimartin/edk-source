#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

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
#warning "Inside CommandParser"
#endif

#pragma once
#include "vector/BinaryTree.h"

#ifdef printMessages
#warning "    Compiling CommandParser"
#endif

namespace edk{
class CommandParser{
public:
    CommandParser();
    CommandParser(edk::int32 argc,edk::char8* argv[]);
    ~CommandParser();

    //new command
    bool addCommand(const edk::char8* command,const edk::char8* value);
    bool addCommand(edk::char8* command,edk::char8* value);
    //remove a command
    bool removeCommand(const edk::char8* command);
    bool removeCommand(edk::char8* command);
    //clean the commands
    void cleanCommands();
    //test if have a command
    bool haveCommand(const edk::char8* command);
    bool haveCommand(edk::char8* command);
    //return the value of a command
    edk::char8* getValue(const edk::char8* command);
    edk::char8* getValue(edk::char8* command);
    //return the value of the command in position
    edk::char8* getValueInPosition(edk::uint32 position);
    //return the command string in a position
    edk::char8* getCommandInPosition(edk::uint32 position);
    //return the size of the commands
    edk::uint32 getCommandsSize();

    //print commands
    void printCommands();
    void printCommandsWithValues();

    //parse ARGC and ARGV
    bool parseArgcArgv(edk::int32 argc,edk::char8* argv[]);
private:

    //create a command class
    class Command : public edk::Name{
    public:
        Command();
        ~Command();

        //command value
        edk::Name value;
        //command explanation
        //create in the future
    };
    //command tree
    class TreeCommand:public edk::vector::NameTree{
    public:
        TreeCommand();
        ~TreeCommand();
        //Print the command and value
        void printElement(edk::Name* value);
        //print only the command name
        void renderElement(edk::Name* value);

        //add the command
        bool addCommand(edk::char8* command,edk::char8* value);
        //remove command
        bool removeCommand(edk::char8* command);
        //remove all commands on the tree
        void clean();
        //test if have the command
        bool haveCommand(edk::char8* command);
        //return the command istring in a position
        edk::char8* getCommandInPosition(edk::uint32 position);
        //get command value
        edk::char8* getValue(edk::char8* command);
        //get command value in position
        edk::char8* getValueInPosition(edk::uint32 position);
        //clean commands
        void cleanCommands();
    }tree;
};
}//end namespace edk

#endif // COMMANDPARSER_H
