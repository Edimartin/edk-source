#ifndef EDK_SQL_H
#define EDK_SQL_H

/*
Library SQLite - Use SQLITE in EDK Game Engine.
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


/*LIBS:
-ldl
*/

#ifdef printMessages
#pragma message "Inside SQLite"
#endif

#define edkDataBase ".edb"

#pragma once
#ifndef EDK_NO_SQLITE
#ifndef EDK_USE_SQLITE
#define EDK_USE_SQLITE
#pragma message "EDK WARNING: As default EDK use SQLite, If you don't want use SQLite you can define EDK_NO_SQLITE"
#endif
#endif

#if defined(EDK_USE_SQLITE)
extern "C" {
#include "../../sqlite/sqlite3.h"
}
#endif

#include "../File.h"
#include "../String.h"
#include "../vector/Stack.h"
#include "../NameClass.h"

#include "SQLGroup.h"

#ifdef printMessages
#pragma message "    Compiling SQLite"
#endif

namespace edk{
namespace sql{
class SQLite{
public:
    SQLite();
    ~SQLite();

    //open dataBase
    bool openDataBase(const edk::char8* name);
    bool openDataBase(edk::char8* name);
    //create a new dataBase (it will delete the file with the same name)
    bool newDataBase(const edk::char8* name);
    bool newDataBase(edk::char8* name);
    //delete dataBase
    bool deleteDataBase(const edk::char8* name);
    bool deleteDataBase(edk::char8* name = NULL);

    //execute a command
    bool execute(const edk::char8* command,edk::sql::SQLGroup* callback = NULL);
    bool execute(edk::char8* command,edk::sql::SQLGroup* callback = NULL);

    //return true if have a dataBase
    bool haveOpenedDataBase();

    //close the dataBase
    void closeDataBase();

private:
#if defined(EDK_USE_SQLITE)
    sqlite3 *db;
#endif
    edk::char8* baseName;

    //add a extension to the file
    edk::char8* addExtension(edk::char8* name,edk::char8* extension);
    //delete basename
    void deleteBaseName();
};
}//end namespace sql
}//end namespace edk

#endif // SQL_H
