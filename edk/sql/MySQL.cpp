#include "MySQL.h"

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

edk::sql::MySQL::MySQL(){
#ifdef EDK_USE_MYSQL
    this->con=NULL;edkEnd();
    this->res=NULL;edkEnd();
    this->field=NULL;edkEnd();
#endif
    this->error.setName(" ");edkEnd();
}
edk::sql::MySQL::~MySQL(){
    //
    this->closeDataBase();edkEnd();
}

//open dataBase
bool edk::sql::MySQL::openDataBase(const edk::char8* database,const edk::char8* user,const edk::char8* password){
    return this->openDataBase((edk::char8*) database,(edk::char8*) user,(edk::char8*) password);edkEnd();
}
bool edk::sql::MySQL::openDataBase(edk::char8* database,edk::char8* user,edk::char8* password){
    return this->openDataBase(database,user,password,(edk::char8*)"127.0.0.1",3306u);edkEnd();
}
bool edk::sql::MySQL::openDataBase(const edk::char8* database,const edk::char8* user,const edk::char8* password,const edk::char8* host){
    return this->openDataBase((edk::char8*) database,(edk::char8*) user,(edk::char8*) password,(edk::char8*) host);edkEnd();
}
bool edk::sql::MySQL::openDataBase(edk::char8* database,edk::char8* user,edk::char8* password,edk::char8* host){
    return this->openDataBase(database,user,password,host,3306u);edkEnd();
}
bool edk::sql::MySQL::openDataBase(const edk::char8* database,const edk::char8* user,const edk::char8* password,const edk::char8* host,edk::uint32 port){
    return this->openDataBase((edk::char8*) database,(edk::char8*) user,(edk::char8*) password,(edk::char8*) host,port);edkEnd();
}
bool edk::sql::MySQL::openDataBase(edk::char8* database,edk::char8* user,edk::char8* password,edk::char8* host,edk::uint32 port){
    this->closeDataBase();edkEnd();

    if(database && user && password && host && port){
#ifdef EDK_USE_MYSQL
        this->con = mysql_init(NULL);edkEnd(); // mysql instance
        if(this->con){
            // connect to the mysql database
            if(mysql_real_connect(this->con, host, user, password, database, port, NULL, 0)){
                return true;
            }
            else{
                //if error then copy the error
                this->error.setName(mysql_error(this->con));edkEnd();

                this->closeDataBase();edkEnd();
            }
        }
#else
        printf("\nYou must define EDK_USE_MYSQL before use");edkEnd();
#endif
    }

    return false;
}

//execute a command
bool edk::sql::MySQL::execute(const edk::char8* command,edk::sql::SQLGroup* callback){
    return this->execute((edk::char8*) command,callback);edkEnd();
}
bool edk::sql::MySQL::execute(edk::char8* command,
                              edk::sql::SQLGroup*
#ifdef EDK_USE_MYSQL
                              callback
#endif
                              ){
    this->error.setName(" ");edkEnd();
    if(this->haveOpenedDataBase()){
        //
        if(command){
#ifdef EDK_USE_MYSQL
            if(mysql_query(this->con, command)){
                //if error then copy the error
                this->error.setName(mysql_error(this->con));edkEnd();
            }
            else{
                this->res = mysql_store_result(this->con);edkEnd();
                if(this->res){
                    edk::int32 num_fields = mysql_num_fields(this->res);edkEnd();
                    if(callback){
                        edk::sql::SQLNodes* group=NULL;edkEnd();
                        /* List down all the records */
                        while(this->field = mysql_fetch_field(this->res)){
                            //add the field into the stack
                            this->fields.pushBack(this->field->name);edkEnd();
                        }
                        this->field=NULL;edkEnd();
                        while ((this->row = mysql_fetch_row(this->res)) != NULL){
                            group = callback->getNewGroup();edkEnd();
                            if(group){
                                for(int i = 0; i < num_fields; i++){
                                    //test if have the field in the stack
                                    if(this->fields.havePos(i)){
                                        //
                                        group->addNode((edk::char8*)this->fields.get(i),(edk::char8*)this->row[i]);edkEnd();
                                    }
                                    else{

                                        group->addNode((edk::char8*)this->row[i],(edk::char8*)this->row[i]);edkEnd();
                                    }
                                }
                            }
                        }
                        this->row=NULL;edkEnd();

                        this->fields.clean();edkEnd();
                    }
                    mysql_free_result(this->res);edkEnd();
                }
                return true;
            }
#else
            printf("\nYou must define EDK_USE_MYSQL before use");edkEnd();
#endif
        }
    }
    return false;
}

//return true if have a dataBase
bool edk::sql::MySQL::haveOpenedDataBase(){
#ifdef EDK_USE_MYSQL
    if(this->con){
        return true;
    }
#else
    printf("\nYou must define EDK_USE_MYSQL before use");edkEnd();
#endif
    return false;
}

//close the dataBase
void edk::sql::MySQL::closeDataBase(){
#ifdef EDK_USE_MYSQL
    if(this->con){
        // close database connection
        mysql_close(this->con);edkEnd();
    }

    this->con=NULL;edkEnd();
    this->res=NULL;edkEnd();
    this->field=NULL;edkEnd();

    this->fields.clean();edkEnd();
#else
    printf("\nYou must define EDK_USE_MYSQL before use");edkEnd();
#endif
}

//return the error string
edk::char8* edk::sql::MySQL::getError(){
    return this->error.getName();edkEnd();
}
