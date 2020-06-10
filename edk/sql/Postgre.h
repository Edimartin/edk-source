#ifndef POSTGRE_H
#define POSTGRE_H

/*
Library POSTGRE - Use POSTGRE in EDK Game Engine.
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
#warning "Inside POSTGRE"
#endif

#define edkDataBase ".edb"

#pragma once
#include "../String.h"
#include "SQLGroup.h"
#ifdef EDK_USE_POSTGRE
#include <pqxx/pqxx>
#endif

#ifdef printMessages
#warning "    Compiling POSTGRE"
#endif

namespace edk{
namespace sql{
class Postgre{
public:
    Postgre();
    virtual ~Postgre();

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
#ifdef EDK_USE_POSTGRE
    pqxx::connection* C;
    pqxx::nontransaction* N;
#endif
    edk::Name error;
};
}//end namespace sql
}//end namespace edk

#endif // POSTGRE_H
