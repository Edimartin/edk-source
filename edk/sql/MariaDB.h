#ifndef MARIADB_H
#define MARIADB_H

/*
Library MARIADB - Use MariaDB in EDK Game Engine.
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
-ldl -lmariadb
*/

#ifdef printMessages
#warning "Inside MARIADB"
#endif

#define edkDataBase ".edb"

#pragma once
#include "../String.h"
#include "SQLGroup.h"
#ifdef EDK_USE_MARIADB
#include <mariadb/mysql.h>
#endif

#ifdef printMessages
#warning "    Compiling MARIADB"
#endif

namespace edk{
namespace sql{


class MariaDB{
public:
    MariaDB();
    ~MariaDB();

    //open dataBase
    bool openDataBase(const edk::char8* database,const edk::char8* user,const edk::char8* password);
    bool openDataBase(edk::char8* database,edk::char8* user,edk::char8* password);
    bool openDataBase(const edk::char8* database,const edk::char8* user,const edk::char8* password,const edk::char8* host);
    bool openDataBase(edk::char8* database,edk::char8* user,edk::char8* password,edk::char8* host);
    bool openDataBase(const edk::char8* database,const edk::char8* user,const edk::char8* password,const edk::char8* host,edk::uint32 port);
    bool openDataBase(edk::char8* database,edk::char8* user,edk::char8* password,edk::char8* host,edk::uint32 port);

    //execute a command
    bool execute(const edk::char8* command,edk::sql::SQLGroup* callback = NULL);
    bool execute(edk::char8* command,edk::sql::SQLGroup* callback = NULL);

    //return true if have a dataBase
    bool haveOpenedDataBase();

    //close the dataBase
    void closeDataBase();

    //return the error string
    edk::char8* getError();
private:
#ifdef EDK_USE_MARIADB
    MYSQL *con;	// the connection
    MYSQL_RES *res;	// the results
    MYSQL_ROW row;	// the results rows (array)
#endif
    edk::Name error;
};
}//end namespace sql
}//end namespace edk

#endif // MARIADB_H
