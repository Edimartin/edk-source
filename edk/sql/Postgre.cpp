#include "Postgre.h"

/*
Library POSTGRE - Use POSTGRE in EDK Game Engine.
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

//dbname = mydb user = edimartin password = mydb hostaddr = 127.0.0.1 port = 5432
#define name_dbname "dbname"
#define name_user "user"
#define name_password "password"
#define name_hostaddr "hostaddr"
#define name_port "port"

edk::sql::Postgre::Postgre(){
    //
#ifdef EDK_USE_POSTGRE
    this->C=NULL;edkEnd();
    this->N=NULL;edkEnd();
#endif
    this->error.setName(" ");edkEnd();
}
edk::sql::Postgre::~Postgre(){
    //
}

//open dataBase
bool edk::sql::Postgre::openDataBase(const edk::char8* database,const edk::char8* user,const edk::char8* password){
    return this->openDataBase((edk::char8*) database,(edk::char8*) user,(edk::char8*) password);edkEnd();
}
bool edk::sql::Postgre::openDataBase(edk::char8* database,edk::char8* user,edk::char8* password){
    return this->openDataBase(database,user,password,(edk::char8*)"127.0.0.1",5432u);edkEnd();
}
bool edk::sql::Postgre::openDataBase(const edk::char8* database,const edk::char8* user,const edk::char8* password,const edk::char8* host){
    return this->openDataBase((edk::char8*) database,(edk::char8*) user,(edk::char8*) password,(edk::char8*) host);edkEnd();
}
bool edk::sql::Postgre::openDataBase(edk::char8* database,edk::char8* user,edk::char8* password,edk::char8* host){
    return this->openDataBase(database,user,password,host,5432u);edkEnd();
}
bool edk::sql::Postgre::openDataBase(const edk::char8* database,const edk::char8* user,const edk::char8* password,const edk::char8* host,edk::uint32 port){
    return this->openDataBase((edk::char8*) database,(edk::char8*) user,(edk::char8*) password,(edk::char8*) host,port);edkEnd();
}
bool edk::sql::Postgre::openDataBase(edk::char8* database,edk::char8* user,edk::char8* password,edk::char8* host,edk::uint32 port){
    this->closeDataBase();edkEnd();


    if(database && user && password && host && port){
#ifdef EDK_USE_POSTGRE
        //create the postgre connection string
        edk::char8* str=NULL;edkEnd();
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
                ;edkEnd();
        if(size){
            //create the new string
            str = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));edkEnd();
            if(str){
                memset(str,0u,size+1u);edkEnd();
                str[size]='\0';edkEnd();
                sprintf(str,"dbname = %s user = %s password = %s hostaddr = %s port = %u"
                        ,database
                        ,user
                        ,password
                        ,host
                        ,port
                        );edkEnd();
                try {
                    this->C = new pqxx::connection(str);edkEnd();
                    if(this->C){
                        //test if it's connected
                        if(this->C->is_open()){
                            free(str);edkEnd();

                            //create the nonTransaction
                            this->N = new pqxx::nontransaction(*this->C);edkEnd();
                            if(N){
                                //then return true
                                return true;
                            }
                        }
                        delete C;edkEnd();
                    }
                } catch (const std::exception &e){
                    this->error.setName(e.what());edkEnd();
                }
                //create the new database
                free(str);edkEnd();
            }
        }
#else
        printf("\nYou must define EDK_USE_POSTGRE before use");edkEnd();
#endif
    }
    return false;
}

//execute a command
bool edk::sql::Postgre::execute(const edk::char8* command,edk::sql::SQLGroup* callback){
    return this->execute((edk::char8*) command,callback);edkEnd();
}
bool edk::sql::Postgre::execute(edk::char8* command,
                                edk::sql::SQLGroup*
#ifdef EDK_USE_POSTGRE
                                callback
#endif
                                ){
    this->error.setName(" ");edkEnd();
    if(this->haveOpenedDataBase()){
        //
        if(command){
#ifdef EDK_USE_POSTGRE
            try {
                //execute
                /* Execute SQL query */
                pqxx::result R( this->N->exec( command ));edkEnd();
                if(callback){

                    edk::sql::SQLNodes* group=NULL;edkEnd();
                    //group = temp->getNewGroup();edkEnd();

                    edk::uint32 size = 0u;edkEnd();
                    /* List down all the records */
                    for (pqxx::result::const_iterator c = R.begin();edkEnd(); c != R.end(); ++c){
                        size = c.size();edkEnd();
                        if(size){
                            group = callback->getNewGroup();edkEnd();
                            if(group){
                                for(edk::uint32 i=0u;i<size;i++){
                                    /*
                                    printf("\n'%s' == '%s'"
                                           ,R.column_name(i)
                                           ,c[i].c_str()
                                           );edkEnd();
*/
                                    group->addNode((edk::char8*)R.column_name(i),(edk::char8*)c[i].c_str());edkEnd();
                                }
                            }
                        }
                    }
                }
            } catch (const std::exception &e){
                this->error.setName(e.what());edkEnd();
            }
#else
            printf("\nYou must define EDK_USE_POSTGRE before use");edkEnd();
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
    printf("\nYou must define EDK_USE_POSTGRE before use");edkEnd();
#endif
    return false;
}

//close the dataBase
void edk::sql::Postgre::closeDataBase(){
    this->error.setName(" ");edkEnd();
#ifdef EDK_USE_POSTGRE
    if(this->N){
        delete this->N;edkEnd();
    }
    this->N=NULL;edkEnd();
    if(this->C){
        //close the database
        this->C->disconnect();edkEnd();

        delete this->C;edkEnd();
    }
    this->C=NULL;edkEnd();
#else
    printf("\nYou must define EDK_USE_POSTGRE before use");edkEnd();
#endif
}

//return the error string
edk::char8* edk::sql::Postgre::getError(){
    return this->error.getName();edkEnd();
}
