#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

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
#pragma message "Inside CommandParser"
#endif

#pragma once
#include "vector/BinaryTree.h"
#include "vector/Stack.h"

#ifdef printMessages
#pragma message "    Compiling CommandParser"
#endif

namespace edk{
class CommandParser{
public:
    CommandParser();
    CommandParser(edk::int32 argc,edk::char8* argv[]);
    virtual ~CommandParser();

    void Constructor(bool runFather=true);
    void Constructor(edk::int32 argc,edk::char8* argv[],bool runFather=true);

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

    //Program
    bool setCommandName(const edk::char8* name);
    bool setCommandName(edk::char8* name);
    bool setCommandCommand(const edk::char8* name);
    bool setCommandCommand(edk::char8* name);
    bool haveProgramName();
    bool haveProgramCommand();
    edk::uint32 getProgramNameLenght();
    edk::uint32 getProgramCommandLenght();
    edk::char8* getProgramName();
    edk::char8* getProgramCommand();

    //print commands
    void printCommands();
    void printCommandsWithValues();

    //parse ARGC and ARGV
    bool parseArgcArgv(edk::int32 argc,edk::char8* argv[]);
private:
    //program name
    edk::Name strPName;
    //program command
    edk::Name strPCommand;

    void printProgramStrings();

    //create a command class
    class Command : public edk::Name{
    public:
        Command();
        virtual ~Command();

        void Constructor(bool runFather=true);

        //command value
        edk::Name value;
        //command explanation
        //create in the future

        //command position in the stack
        edk::uint32 position;
    private:
        edk::classID classThis;
    };
    //command tree
    class TreeCommand:public edk::vector::NameTree{
    public:
        TreeCommand();
        virtual ~TreeCommand();

        void Constructor(bool runFather=true);
        //Print the command and value
        void printElement(edk::Name* value);
        //print only the command name
        void renderElement(edk::Name* value);

        //print
        void printElements();
        void printElementsWithValues();

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
    private:
        //stack with the commands
        edk::vector::StackNames stack;
    private:
        edk::classID classThis;
    }tree;
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // COMMANDPARSER_H
