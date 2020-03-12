#include "SQL.h"

/*
Library SQL - Use SQLITE in EDK Game Engine.
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

edk::SQL::SQL(){
    this->db = NULL;
    this->baseName=NULL;
}

edk::SQL::~SQL(){
    //close the db
    this->closeDataBase();
    this->deleteBaseName();
}

//add a extension to the file
edk::char8* edk::SQL::addExtension(edk::char8* name,edk::char8* extension){
    //return
    edk::char8* ret=NULL;
    if(name){
        edk::uint32 nameSize = edk::String::strSize(name);
        if(nameSize){

            //test if the fileName have some extension
            for(edk::uint32 i=nameSize;i>0u;i--){
                //test if it's a point
                if(name[i-1u]=='.'){
                    //remove the extension
                    extension=NULL;
                }
            }

            if(extension){
                edk::uint32 extensionSize = edk::String::strSize(extension);
                if(extensionSize>1u){
                    //create the new String to copy the extension
                    ret = edk::String::strCat(name,extension);
                }
            }

            if(!ret){
                //copy the fullName
                ret = edk::String::strCopy(name);
            }
        }
    }
    return ret;
}
//delete basename
void edk::SQL::deleteBaseName(){
    if(this->baseName){
        delete[] this->baseName;
    }
    this->baseName=NULL;
}

//open dataBase
bool edk::SQL::openDataBase(const char* name){
    return this->openDataBase((edk::char8*) name);
}
bool edk::SQL::openDataBase(edk::char8* name){
    //close the last dataBase
    this->closeDataBase();
    this->deleteBaseName();
    //add a extension
    edk::char8* nameExtension = this->addExtension(name,(edk::char8*)edkDataBase);
    if(nameExtension){
        if(edk::File::fileExist(nameExtension)){
            edk::int32 rc;
            rc = sqlite3_open((const char*) nameExtension, &this->db);
            if(!rc){
                this->baseName = edk::String::strCopy(nameExtension);
                delete[] nameExtension;
                return true;
            }
            printf("\nSQL error - %s"
                   ,sqlite3_errmsg(db)
                   );
            //else open the dataBase get error
            this->db=NULL;
        }
        delete[] nameExtension;
    }
    else{
        //test if have the file
        if(edk::File::fileExist(name)){
            edk::int32 rc;
            rc = sqlite3_open((const char*) name, &this->db);
            if(!rc){
                this->baseName = edk::String::strCopy(name);
                return true;
            }
            printf("\nSQL error - %s"
                   ,sqlite3_errmsg(db)
                   );
            //else open the dataBase get error
            this->db=NULL;
        }
    }
    return false;
}
//create a new dataBase (it will delete the file with the same name)
bool edk::SQL::newDataBase(const char* name){
    return this->newDataBase((edk::char8*) name);
}
bool edk::SQL::newDataBase(edk::char8* name){
    //create the name with the extension
    edk::char8* nameExtension = this->addExtension(name,(edk::char8*)edkDataBase);
    if(nameExtension){
        if(edk::File::createFile(nameExtension)){
            bool ret = this->openDataBase(nameExtension);
            delete[] nameExtension;
            return ret;
        }
        delete[] nameExtension;
    }
    else{
        //create a new file
        if(edk::File::createFile(name)){
            return this->openDataBase(name);
        }
    }
    return false;
}
//delete dataBase
bool edk::SQL::deleteDataBase(const char* name){
    return this->deleteDataBase((edk::char8*) name);
}
bool edk::SQL::deleteDataBase(edk::char8* name){
    if(name){
        edk::char8* nameExtension = this->addExtension(name,(edk::char8*)edkDataBase);
        if(nameExtension){
            if(edk::File::fileExist(nameExtension)){
                //delete the file
                bool ret = edk::File::deleteFile(nameExtension);
                delete[] nameExtension;
                return ret;
            }
            delete[] nameExtension;
        }
        else{
            if(edk::File::fileExist(name)){
                //delete the file
                return edk::File::deleteFile(name);
            }
        }
    }
    else{
        //close this opened data base
        this->closeDataBase();
        if(edk::File::fileExist(this->baseName)){
            //delete the file
            bool ret = edk::File::deleteFile(this->baseName);
            this->deleteBaseName();
            return ret;
        }
        this->deleteBaseName();
    }
    return false;
}

//execute a command
static edk::int32 sqlCallback(void *callback, edk::int32 argc, char **argv, char **azColName){
    edk::int32 i;
    if(argc){
        edk::SQLGroup* temp = (edk::SQLGroup*)callback;
        edk::SQLNodes* group=NULL;
        if(temp){
            group = temp->getNewGroup();
            if(group){
                for(i=0; i<argc; i++){
/*
                    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");fflush(stdout);
                    if(argv[i]){
                        group->addNode((edk::char8*)azColName[i],(edk::char8*)argv[i]);
                    }
                    else{
                        group->addNode((edk::char8*)azColName[i],(edk::char8*)"NULL");
                    }
*/
                    group->addNode((edk::char8*)azColName[i],(edk::char8*)argv[i]);
                }
            }
        }
    }
    return 0;
}
bool edk::SQL::execute(const char* command,SQLGroup* callback){
    return this->execute((edk::char8*) command,callback);
}
bool edk::SQL::execute(edk::char8* command,SQLGroup* callback){
    //est if have opened the dataBase
    if(this->haveOpenedDataBase() && command){
        //execute the comand
        edk::char8* zErrMsg = NULL;
        edk::int32 rc = sqlite3_exec(this->db, (const char *)command, sqlCallback, callback, (char**)&zErrMsg);
        if( rc == SQLITE_OK ){
            return true;
        }else{
            printf( "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
    }
    return false;
}

//return true if have a dataBase
bool edk::SQL::haveOpenedDataBase(){
    if(this->db){
        return true;
    }
    return false;
}

//close the dataBase
void edk::SQL::closeDataBase(){
    if(this->db){
        sqlite3_close(this->db);
    }
    this->db=NULL;
}
