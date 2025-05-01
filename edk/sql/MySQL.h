#ifndef MYSQL_H
#define MYSQL_H

/*
Library MYSQL - Use MySQL in EDK Game Engine.
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
-ldl -lmysqlclient
*/

#ifdef printMessages
#pragma message "Inside MYSQL"
#endif

#pragma once
#include "../String.h"
#include "SQLGroup.h"
#include "../vector/Stack.h"
#if defined(EDK_USE_MYSQL)
#include <mysql/mysql.h>
#endif

#ifdef printMessages
#pragma message "    Compiling MYSQL"
#endif

namespace edk{
namespace sql{
class MySQL{
public:
    MySQL();
    virtual ~MySQL();

    void Constructor();
    void Destructor();

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
#if defined(EDK_USE_MYSQL)
    MYSQL *con;	// the connection
    MYSQL_RES *res;	// the results
    MYSQL_ROW row;	// the results rows (array)
    MYSQL_FIELD *field; //the fields
    edk::vector::StackNames fields; //fields used to save the field names
#endif
    edk::Name error;
private:
    edk::classID classThis;
};
}//end namespace sql
}//end namespace edk

#endif // MYSQL_H
