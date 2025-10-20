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

#ifdef printMessages
#pragma message "            Inside Postgre.cpp"
#endif

//dbname = mydb user = edimartin password = mydb hostaddr = 127.0.0.1 port = 5432
#define name_dbname "dbname"
#define name_user "user"
#define name_password "password"
#define name_hostaddr "hostaddr"
#define name_port "port"

edk::sql::Postgre::Postgre(){
    this->classThis=NULL;
    this->Constructor();
}
edk::sql::Postgre::~Postgre(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
}

void edk::sql::Postgre::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        this->error.Constructor();

#if defined(EDK_USE_POSTGRE)
        this->C=NULL;
        this->N=NULL;
#endif
        this->error.setName(" ");
    }
}
void edk::sql::Postgre::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class

        this->error.Destructor();
    }
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
    return this->openDataBase(database,user,password,host,5432u);
}
bool edk::sql::Postgre::openDataBase(const edk::char8* database,const edk::char8* user,const edk::char8* password,const edk::char8* host,edk::uint32 port){
    return this->openDataBase((edk::char8*) database,(edk::char8*) user,(edk::char8*) password,(edk::char8*) host,port);
}
bool edk::sql::Postgre::openDataBase(edk::char8* database,edk::char8* user,edk::char8* password,edk::char8* host,edk::uint32 port){
    this->closeDataBase();


    if(database && user && password && host && port){
#if defined(EDK_USE_POSTGRE)
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
            str = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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
                            free(str);

                            //create the nonTransaction
                            this->N = new pqxx::nontransaction(*this->C);
                            if(N){
                                //then return true
                                return true;
                            }
                        }
                        delete C;
                    }
                } catch (const std::exception &e){
                    this->error.setName(e.what());
                }
                //create the new database
                free(str);
            }
        }
#else
        printf("\nYou must define EDK_USE_POSTGRE before use");
#endif
    }
    return false;
}

//execute a command
bool edk::sql::Postgre::execute(const edk::char8* command,edk::sql::SQLGroup* callback){
    return this->execute((edk::char8*) command,callback);
}
bool edk::sql::Postgre::execute(edk::char8* command,
                                edk::sql::SQLGroup*
                                #if defined(EDK_USE_POSTGRE)
                                callback
                                #endif
                                ){
    this->error.setName(" ");
    if(this->haveOpenedDataBase()){
        //
        if(command){
#if defined(EDK_USE_POSTGRE)
            try {
                //execute
                /* Execute SQL query */
                pqxx::result R( this->N->exec( command ));
                if(callback){

                    edk::sql::SQLNodes* group=NULL;
                    //group = temp->getNewGroup();

                    edk::uint32 size = 0u;
                    /* List down all the records */
                    for (pqxx::result::const_iterator c = R.begin();  c != R.end(); ++c){
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
            } catch (const std::exception &e){
                this->error.setName(e.what());
            }
#else
            printf("\nYou must define EDK_USE_POSTGRE before use");
#endif
        }
    }
    return false;
}

//return true if have a dataBase
bool edk::sql::Postgre::haveOpenedDataBase(){
#if defined(EDK_USE_POSTGRE)
    if(this->C){
        if(this->C->is_open()){
            return true;
        }
    }
#else
    printf("\nYou must define EDK_USE_POSTGRE before use");
#endif
    return false;
}

//close the dataBase
void edk::sql::Postgre::closeDataBase(){
    this->error.setName(" ");
#if defined(EDK_USE_POSTGRE)
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
    printf("\nYou must define EDK_USE_POSTGRE before use");
#endif
}

//return the error string
edk::char8* edk::sql::Postgre::getError(){
    return this->error.getName();
}
