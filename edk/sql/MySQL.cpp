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
    this->classThis=NULL;
    this->Constructor();
}
edk::sql::MySQL::~MySQL(){
    this->Destructor();
}

void edk::sql::MySQL::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        this->error.Constructor();

#if defined(EDK_USE_MYSQL)
        this->con=NULL;
        this->res=NULL;
        this->field=NULL;
#endif
        this->error.setName(" ");
    }
}
void edk::sql::MySQL::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->closeDataBase();
    }
}

//open dataBase
bool edk::sql::MySQL::openDataBase(const edk::char8* database,const edk::char8* user,const edk::char8* password){
    return this->openDataBase((edk::char8*) database,(edk::char8*) user,(edk::char8*) password);
}
bool edk::sql::MySQL::openDataBase(edk::char8* database,edk::char8* user,edk::char8* password){
    return this->openDataBase(database,user,password,(edk::char8*)"127.0.0.1",3306u);
}
bool edk::sql::MySQL::openDataBase(const edk::char8* database,const edk::char8* user,const edk::char8* password,const edk::char8* host){
    return this->openDataBase((edk::char8*) database,(edk::char8*) user,(edk::char8*) password,(edk::char8*) host);
}
bool edk::sql::MySQL::openDataBase(edk::char8* database,edk::char8* user,edk::char8* password,edk::char8* host){
    return this->openDataBase(database,user,password,host,3306u);
}
bool edk::sql::MySQL::openDataBase(const edk::char8* database,const edk::char8* user,const edk::char8* password,const edk::char8* host,edk::uint32 port){
    return this->openDataBase((edk::char8*) database,(edk::char8*) user,(edk::char8*) password,(edk::char8*) host,port);
}
bool edk::sql::MySQL::openDataBase(edk::char8* database,edk::char8* user,edk::char8* password,edk::char8* host,edk::uint32 port){
    this->closeDataBase();

    if(database && user && password && host && port){
#if defined(EDK_USE_MYSQL)
        this->con = mysql_init(NULL);  // mysql instance
        if(this->con){
            // connect to the mysql database
            if(mysql_real_connect(this->con, host, user, password, database, port, NULL, 0)){
                return true;
            }
            else{
                //if error then copy the error
                this->error.setName(mysql_error(this->con));

                this->closeDataBase();
            }
        }
#else
        printf("\nYou must define EDK_USE_MYSQL before use");
#endif
    }

    return false;
}

//execute a command
bool edk::sql::MySQL::execute(const edk::char8* command,edk::sql::SQLGroup* callback){
    return this->execute((edk::char8*) command,callback);
}
bool edk::sql::MySQL::execute(edk::char8* command,
                              edk::sql::SQLGroup*
                              #if defined(EDK_USE_MYSQL)
                              callback
                              #endif
                              ){
    this->error.setName(" ");
    if(this->haveOpenedDataBase()){
        //
        if(command){
#if defined(EDK_USE_MYSQL)
            if(mysql_query(this->con, command)){
                //if error then copy the error
                this->error.setName(mysql_error(this->con));
            }
            else{
                this->res = mysql_store_result(this->con);
                if(this->res){
                    edk::int32 num_fields = mysql_num_fields(this->res);
                    if(callback){
                        edk::sql::SQLNodes* group=NULL;
                        /* List down all the records */
                        while(this->field = mysql_fetch_field(this->res)){
                            //add the field into the stack
                            this->fields.pushBack(this->field->name);
                        }
                        this->field=NULL;
                        while ((this->row = mysql_fetch_row(this->res)) != NULL){
                            group = callback->getNewGroup();
                            if(group){
                                for(int i = 0; i < num_fields; i++){
                                    //test if have the field in the stack
                                    if(this->fields.havePos(i)){
                                        //
                                        group->addNode((edk::char8*)this->fields.get(i),(edk::char8*)this->row[i]);
                                    }
                                    else{

                                        group->addNode((edk::char8*)this->row[i],(edk::char8*)this->row[i]);
                                    }
                                }
                            }
                        }
                        this->row=NULL;

                        this->fields.clean();
                    }
                    mysql_free_result(this->res);
                }
                return true;
            }
#else
            printf("\nYou must define EDK_USE_MYSQL before use");
#endif
        }
    }
    return false;
}

//return true if have a dataBase
bool edk::sql::MySQL::haveOpenedDataBase(){
#if defined(EDK_USE_MYSQL)
    if(this->con){
        return true;
    }
#else
    printf("\nYou must define EDK_USE_MYSQL before use");
#endif
    return false;
}

//close the dataBase
void edk::sql::MySQL::closeDataBase(){
#if defined(EDK_USE_MYSQL)
    if(this->con){
        // close database connection
        mysql_close(this->con);
    }

    this->con=NULL;
    this->res=NULL;
    this->field=NULL;

    this->fields.clean();
#else
    printf("\nYou must define EDK_USE_MYSQL before use");
#endif
}

//return the error string
edk::char8* edk::sql::MySQL::getError(){
    return this->error.getName();
}
