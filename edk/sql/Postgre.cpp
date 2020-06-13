#include "Postgre.h"

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

//dbname = mydb user = edimartin password = mydb hostaddr = 127.0.0.1 port = 5432
#define name_dbname "dbname"
#define name_user "user"
#define name_password "password"
#define name_hostaddr "hostaddr"
#define name_port "port"

edk::sql::Postgre::Postgre(){
    //
#ifdef EDK_USE_POSTGRE
    this->C=NULL;
    this->N=NULL;
#endif
    this->error.setName(" ");
}
edk::sql::Postgre::~Postgre(){
    //
}

//open dataBase
bool edk::sql::Postgre::openDataBase(const edk::char8* database,const edk::char8* user,const edk::char8* password){
    return this->openDataBase((edk::char8*) database,(edk::char8*) user,(edk::char8*) password);
}
bool edk::sql::Postgre::openDataBase(edk::char8* database,edk::char8* user,edk::char8* password){
    return this->openDataBase(database,user,password,(edk::char8*)"127.0.0.1",5432u);
}
bool edk::sql::Postgre::openDataBase(const edk::char8* database,const edk::char8* user,const edk::char8* password,const edk::char8* host){
    return this->openDataBase((edk::char8*) database,(edk::char8*) user,(edk::char8*) password,(edk::char8*) host);
}
bool edk::sql::Postgre::openDataBase(edk::char8* database,edk::char8* user,edk::char8* password,edk::char8* host){
    return this->openDataBase(database,user,password,host,6432u);
}
bool edk::sql::Postgre::openDataBase(const edk::char8* database,const edk::char8* user,const edk::char8* password,const edk::char8* host,edk::uint32 port){
    return this->openDataBase((edk::char8*) database,(edk::char8*) user,(edk::char8*) password,(edk::char8*) host,port);
}
bool edk::sql::Postgre::openDataBase(edk::char8* database,edk::char8* user,edk::char8* password,edk::char8* host,edk::uint32 port){
    this->closeDataBase();


    if(database && user && password && host && port){
#ifdef EDK_USE_POSTGRE
        //create the postgre connection string
        edk::char8* str=NULL;
        edk::uint32 size = sizeof(name_dbname) +
                sizeof(" = ") +
                edk::String::strSize(database) +
                sizeof(" ") +

                sizeof(name_user) +
                sizeof(" = ") +
                edk::String::strSize(user) +
                sizeof(" ") +

                sizeof(name_password) +
                sizeof(" = ") +
                edk::String::strSize(password) +
                sizeof(" ") +

                sizeof(name_hostaddr) +
                sizeof(" = ") +
                edk::String::strSize(host) +
                sizeof(" ") +

                sizeof(name_port) +
                sizeof(" = ") +
                sizeof("65535")
                ;
        if(size){
            //create the new string
            str = new edk::char8[size+1u];
            if(str){
                memset(str,0u,size+1u);
                str[size]='\0';
                sprintf(str,"dbname = %s user = %s password = %s hostaddr = %s port = %u"
                        ,database
                        ,user
                        ,password
                        ,host
                        ,port
                        );
                try {
                    this->C = new pqxx::connection(str);
                    if(this->C){
                        //test if it's connected
                        if(this->C->is_open()){
                            delete[] str;

                            //create the nonTransaction
                            this->N = new pqxx::nontransaction(*this->C);
                            if(N){
                                //then return true
                                return true;
                            }
                        }
                        delete C;
                    }
                } catch (const std::exception &e) {
                    this->error.setName(e.what());
                }
                //create the new database
                delete[] str;
            }
        }
#else
        printf("\nYou must define EDK_USE_POSTGRE before use");fflush(stdout);
#endif
    }
    return false;
}

//execute a command
bool edk::sql::Postgre::execute(const edk::char8* command,edk::sql::SQLGroup* callback){
    return this->execute((edk::char8*) command,callback);
}
bool edk::sql::Postgre::execute(edk::char8* command,edk::sql::SQLGroup* callback){
    this->error.setName(" ");
    if(this->haveOpenedDataBase()){
        //
        if(command){
#ifdef EDK_USE_POSTGRE
            try {
                //execute
                /* Execute SQL query */
                pqxx::result R( this->N->exec( command ));
                if(callback){

                    edk::sql::SQLNodes* group=NULL;
                    //group = temp->getNewGroup();

                    edk::uint32 size = 0u;
                    /* List down all the records */
                    for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c) {
                        size = c.size();
                        if(size){
                            group = callback->getNewGroup();
                            if(group){
                                for(edk::uint32 i=0u;i<size;i++){
                                    /*
                                    printf("\n'%s' == '%s'"
                                           ,R.column_name(i)
                                           ,c[i].c_str()
                                           );
*/
                                    group->addNode((edk::char8*)R.column_name(i),(edk::char8*)c[i].c_str());
                                }
                            }
                        }
                    }
                }
            } catch (const std::exception &e) {
                this->error.setName(e.what());
            }
#else
            printf("\nYou must define EDK_USE_POSTGRE before use");fflush(stdout);
#endif
        }
    }
    return false;
}

//return true if have a dataBase
bool edk::sql::Postgre::haveOpenedDataBase(){
#ifdef EDK_USE_POSTGRE
    if(this->C){
        if(this->C->is_open()){
            return true;
        }
    }
#else
    printf("\nYou must define EDK_USE_POSTGRE before use");fflush(stdout);
#endif
    return false;
}

//close the dataBase
void edk::sql::Postgre::closeDataBase(){
    this->error.setName(" ");
#ifdef EDK_USE_POSTGRE
    if(this->N){
        delete this->N;
    }
    this->N=NULL;
    if(this->C){
        //close the database
        this->C->disconnect();

        delete this->C;
    }
    this->C=NULL;
#else
    printf("\nYou must define EDK_USE_POSTGRE before use");fflush(stdout);
#endif
}

//return the error string
edk::char8* edk::sql::Postgre::getError(){
    return this->error.getName();
}
