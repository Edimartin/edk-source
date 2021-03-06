#ifndef EDK_SQL_H
#define EDK_SQL_H

/*
Library SQLite - Use SQLITE in EDK Game Engine.
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


/*LIBS:
-ldl
*/

#ifdef printMessages
#warning "Inside SQLite"
#endif

#define edkDataBase ".edb"

#pragma once
extern "C" {
#include "../../sqlite/sqlite3.h"
}
#include "../File.h"
#include "../String.h"
#include "../vector/Stack.h"
#include "../NameClass.h"

#include "SQLGroup.h"

#ifdef printMessages
#warning "    Compiling SQLite"
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
    sqlite3 *db;
    edk::char8* baseName;

    //add a extension to the file
    edk::char8* addExtension(edk::char8* name,edk::char8* extension);
    //delete basename
    void deleteBaseName();
};
}//end namespace sql
}//end namespace edk

#endif // SQL_H
