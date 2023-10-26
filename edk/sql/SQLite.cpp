#include "SQLite.h"

/*
Library SQLite - Use SQLITE in EDK Game Engine.
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

edk::sql::SQLite::SQLite(){
#if defined(EDK_USE_SQLITE)
    this->db = NULL;edkEnd();
#endif
    this->baseName=NULL;edkEnd();
}

edk::sql::SQLite::~SQLite(){
    //close the db
    this->closeDataBase();edkEnd();
    this->deleteBaseName();edkEnd();
}

//add a extension to the file
edk::char8* edk::sql::SQLite::addExtension(edk::char8* name,edk::char8* extension){
    //return
    edk::char8* ret=NULL;edkEnd();
    if(name){
        edk::uint32 nameSize = edk::String::strSize(name);edkEnd();
        if(nameSize){

            //test if the fileName have some extension
            for(edk::uint32 i=nameSize;i>0u;i--){
                //test if it's a point
                if(name[i-1u]=='.'){
                    //remove the extension
                    extension=NULL;edkEnd();
                }
            }

            if(extension){
                edk::uint32 extensionSize = edk::String::strSize(extension);edkEnd();
                if(extensionSize>1u){
                    //create the new String to copy the extension
                    ret = edk::String::strCat(name,extension);edkEnd();
                }
            }

            if(!ret){
                //copy the fullName
                ret = edk::String::strCopy(name);edkEnd();
            }
        }
    }
    return ret;
}
//delete basename
void edk::sql::SQLite::deleteBaseName(){
    if(this->baseName){
        free(this->baseName);edkEnd();
    }
    this->baseName=NULL;edkEnd();
}

//open dataBase
bool edk::sql::SQLite::openDataBase(const edk::char8* name){
    return this->openDataBase((edk::char8*) name);edkEnd();
}
bool edk::sql::SQLite::openDataBase(edk::char8* name){
    //close the last dataBase
    this->closeDataBase();edkEnd();
    this->deleteBaseName();edkEnd();
    //add a extension
    edk::char8* nameExtension = this->addExtension(name,(edk::char8*)edkDataBase);edkEnd();
    if(nameExtension){
        if(edk::File::fileExist(nameExtension)){
#if defined(EDK_USE_SQLITE)
            edk::int32 rc;edkEnd();
            rc = sqlite3_open((const edk::char8*) nameExtension, &this->db);edkEnd();
            if(!rc){
                this->baseName = edk::String::strCopy(nameExtension);edkEnd();
                free(nameExtension);edkEnd();
                return true;
            }
            printf("\nSQL error - %s"
                   ,sqlite3_errmsg(db)
                   );edkEnd();
            //else open the dataBase get error
            this->db=NULL;edkEnd();
#endif
        }
        free(nameExtension);edkEnd();
    }
    else{
        //test if have the file
        if(edk::File::fileExist(name)){
#if defined(EDK_USE_SQLITE)
            edk::int32 rc;edkEnd();
            rc = sqlite3_open((const edk::char8*) name, &this->db);edkEnd();
            if(!rc){
                this->baseName = edk::String::strCopy(name);edkEnd();
                return true;
            }
            printf("\nSQL error - %s"
                   ,sqlite3_errmsg(db)
                   );edkEnd();
            //else open the dataBase get error
            this->db=NULL;edkEnd();
#endif
        }
    }
    return false;
}
//create a new dataBase (it will delete the file with the same name)
bool edk::sql::SQLite::newDataBase(const edk::char8* name){
    return this->newDataBase((edk::char8*) name);edkEnd();
}
bool edk::sql::SQLite::newDataBase(edk::char8* name){
    //create the name with the extension
    edk::char8* nameExtension = this->addExtension(name,(edk::char8*)edkDataBase);edkEnd();
    if(nameExtension){
        if(edk::File::createFile(nameExtension)){
            bool ret = this->openDataBase(nameExtension);edkEnd();
            free(nameExtension);edkEnd();
            return ret;
        }
        free(nameExtension);edkEnd();
    }
    else{
        //create a new file
        if(edk::File::createFile(name)){
            return this->openDataBase(name);edkEnd();
        }
    }
    return false;
}
//delete dataBase
bool edk::sql::SQLite::deleteDataBase(const edk::char8* name){
    return this->deleteDataBase((edk::char8*) name);edkEnd();
}
bool edk::sql::SQLite::deleteDataBase(edk::char8* name){
    if(name){
        edk::char8* nameExtension = this->addExtension(name,(edk::char8*)edkDataBase);edkEnd();
        if(nameExtension){
            if(edk::File::fileExist(nameExtension)){
                //delete the file
                bool ret = edk::File::deleteFile(nameExtension);edkEnd();
                free(nameExtension);edkEnd();
                return ret;
            }
            free(nameExtension);edkEnd();
        }
        else{
            if(edk::File::fileExist(name)){
                //delete the file
                return edk::File::deleteFile(name);edkEnd();
            }
        }
    }
    else{
        //close this opened data base
        this->closeDataBase();edkEnd();
        if(edk::File::fileExist(this->baseName)){
            //delete the file
            bool ret = edk::File::deleteFile(this->baseName);edkEnd();
            this->deleteBaseName();edkEnd();
            return ret;
        }
        this->deleteBaseName();edkEnd();
    }
    return false;
}

//execute a command
static edk::int32 sqlCallback(void *callback, edk::int32 argc, char **argv, char **azColName){
    edk::int32 i;edkEnd();
    if(argc){
        edk::sql::SQLGroup* temp = (edk::sql::SQLGroup*)callback;edkEnd();
        edk::sql::SQLNodes* group=NULL;edkEnd();
        if(temp){
            group = temp->getNewGroup();edkEnd();
            if(group){
                for(i=0; i<argc; i++){
/*
                    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");edkEnd();
                    if(argv[i]){
                        group->addNode((edk::char8*)azColName[i],(edk::char8*)argv[i]);edkEnd();
                    }
                    else{
                        group->addNode((edk::char8*)azColName[i],(edk::char8*)"NULL");edkEnd();
                    }
*/
                    group->addNode((edk::char8*)azColName[i],(edk::char8*)argv[i]);edkEnd();
                }
            }
        }
    }
    return 0;
}
bool edk::sql::SQLite::execute(const edk::char8* command,edk::sql::SQLGroup* callback){
    return this->execute((edk::char8*) command,callback);edkEnd();
}
bool edk::sql::SQLite::execute(edk::char8* command,edk::sql::SQLGroup* callback){
    //est if have opened the dataBase
    if(this->haveOpenedDataBase() && command){
#if defined(EDK_USE_SQLITE)
        //execute the comand
        edk::char8* zErrMsg = NULL;edkEnd();
        edk::int32 rc = sqlite3_exec(this->db, (const char *)command, sqlCallback, callback, (char**)&zErrMsg);edkEnd();
        if( rc == SQLITE_OK ){
            return true;
        }else{
            printf( "SQL error: %s\n", zErrMsg);edkEnd();
            sqlite3_free(zErrMsg);edkEnd();
        }
#endif
    }
    return false;
}

//return true if have a dataBase
bool edk::sql::SQLite::haveOpenedDataBase(){
#if defined(EDK_USE_SQLITE)
    if(this->db){
        return true;
    }
#endif
    return false;
}

//close the dataBase
void edk::sql::SQLite::closeDataBase(){
#if defined(EDK_USE_SQLITE)
    if(this->db){
        sqlite3_close(this->db);edkEnd();
    }
    this->db=NULL;edkEnd();
#endif
}
