#ifndef EDK_SQL_H
#define EDK_SQL_H

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


/*LIBS:
-ldl
*/

#define edkDataBase ".edb"

#pragma once
extern "C" {
#include "../../sqlite/sqlite3.h"
}
#include "../File.h"
#include "../String.h"
#include "../vector/Stack.h"

namespace edk{
class SQLNode{
public:
    SQLNode(){
        this->name = NULL;
        this->value = NULL;
        this->canDelete = true;
    }
    SQLNode(edk::char8* name,edk::char8* value){
        this->name = edk::String::strCopy(name);
        this->value = edk::String::strCopy(value);
        this->canDelete = true;
    }
    ~SQLNode(){
        if(this->canDelete){
            if(this->name) delete[] this->name;
            if(this->value) delete[] this->value;
        }
        this->canDelete=true;
    }
    //getters
    edk::char8* getName(){return this->name;}
    edk::char8* getValue(){return this->value;}

    SQLNode operator=(SQLNode node){
        if(this->name) delete[] this->name;
        if(this->value) delete[] this->value;
        this->name = edk::String::strCopy(node.name);
        this->value = edk::String::strCopy(node.value);
        node.cantDelete();
        return node;
    }
    //cant delete
    void cantDelete(){this->canDelete = false;}

private:
    edk::char8* name;
    edk::char8* value;
    bool canDelete;
};
class SQLNodes{
public:
    SQLNodes():nodes(5){}
    ~SQLNodes(){
        edk::uint32 size = this->nodes.size();
        edk::SQLNode* temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->nodes[i];
            if(temp)
                delete temp;
        }
        this->nodes.clean();
    }
    //add a node
    bool addNode(edk::char8* name,edk::char8* value){
        //test the name
        if(name){
            //create the node
            edk::SQLNode* node;
            node = new edk::SQLNode(name,value);
            if(node){
                edk::uint32 size = this->nodes.size();
                //add the node
                this->nodes.pushBack(node);
                if(size < this->nodes.size()){
                    return true;
                }
            }
        }
        return false;
    }
    //return the nodesSize
    edk::uint32 getSize(){return this->nodes.size();}
    //return true if have the node
    bool haveNode(edk::uint32 position){return this->nodes.havePos(position);}
    //return the node
    SQLNode* getNode(edk::uint32 position){
        return this->nodes[position];
    }
    //return the nodeName
    edk::char8* getNodeName(edk::uint32 position){
        if(this->nodes.havePos(position)){
            return this->nodes[position]->getName();
        }
        return NULL;
    }
    //return the nodeValue
    edk::char8* getNodeValue(edk::uint32 position){
        if(this->nodes.havePos(position)){
            return this->nodes[position]->getValue();
        }
        return NULL;
    }

private:
    edk::vector::Stack<SQLNode*> nodes;
};
class SQLGroup{
public:
    SQLGroup(){}
    ~SQLGroup(){
        this->deleteAllGroups();
    }
    void deleteAllGroups(){
        edk::uint32 size = this->groups.size();
        SQLNodes* temp = NULL;
        for(edk::uint32 i=0u;i<size;i++){
            temp=this->groups[i];
            if(temp) delete temp;
        }
        this->groups.clean();
    }
    edk::uint32 getGroupSize(){
        return this->groups.size();
    }
    edk::uint32 getNodeSize(edk::uint32 position){
        if(this->haveGroup(position)){
            return this->groups[position]->getSize();
        }
        return 0u;
    }

    //create a new group;
    edk::uint32 newGroup(){
        //create a new group;
        SQLNodes* group = new SQLNodes;
        if(group){
            //add the group
            edk::uint32 size = this->groups.size();
            edk::uint32 ret = this->groups.pushBack(group);
            if(size<this->groups.size()){
                return ret;
            }
            //else dont add the group
            delete group;
        }
        return 0u;
    }
    //return true if have the group
    bool haveGroup(edk::uint32 position){return this->groups.havePos(position);}
    //return a group
    SQLNodes* getGroup(edk::uint32 position){
        if(this->haveGroup(position)){
            return this->groups[position];
        }
        return NULL;
    }
    edk::char8* getNodeName(edk::uint32 groupPosition, edk::uint32 nodePosition){
        //test if have the group
        if(this->haveGroup(groupPosition)){
            return this->groups[groupPosition]->getNodeName(nodePosition);
        }
        return NULL;
    }
    edk::char8* getNodeValue(edk::uint32 groupPosition, edk::uint32 nodePosition){
        //test if have the group
        if(this->haveGroup(groupPosition)){
            return this->groups[groupPosition]->getNodeValue(nodePosition);
        }
        return NULL;
    }
    SQLNodes* getNewGroup(){
        edk::uint32 position = this->newGroup();
        return this->getGroup(position);
    }
private:
    edk::vector::Stack<SQLNodes*> groups;
};
class SQL{
public:
    SQL();
    ~SQL();

    //open dataBase
    bool openDataBase(const char* name);
    bool openDataBase(edk::char8* name);
    //create a new dataBase (it will delete the file with the same name)
    bool newDataBase(const char* name);
    bool newDataBase(edk::char8* name);
    //delete dataBase
    bool deleteDataBase(const char* name);
    bool deleteDataBase(edk::char8* name = NULL);

    //execute a command
    bool execute(const char* command,SQLGroup* callback = NULL);
    bool execute(edk::char8* command,SQLGroup* callback = NULL);

    //return true if have a dataBase
    bool haveOpenedDataBase();

    //close the dataBase
    void closeDataBase();

private:
    sqlite3 *db;
    edk::char8* baseName;

    //add a extension to the file
    edk::char8* addExtension(edk::char8* name,edk::char8* extension);
    //delete basename
    void deleteBaseName();
};
}//end namespace edk

#endif // SQL_H
