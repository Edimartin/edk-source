#ifndef SQLGROUP_H
#define SQLGROUP_H

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


/*LIBS:
-ldl
*/

#ifdef printMessages
#warning "Inside SQLNode"
#endif
#include "../String.h"
#include "../vector/Stack.h"
#include "../NameClass.h"

#ifdef printMessages
#warning "    Compiling SQLNode"
#endif

namespace edk{
namespace sql{
class SQLNode{
public:
    SQLNode(){
        this->name.cleanName();
        this->value.cleanName();
    }
    SQLNode(edk::char8* name,edk::char8* value){
        this->name.setName(name);
        this->value.setName(value);
    }
    ~SQLNode(){
        this->name.cleanName();
        this->value.cleanName();
    }
    //getters
    edk::char8* getName(){return this->name.getName();}
    edk::char8* getValue(){return this->value.getName();}

    virtual bool cloneFrom(SQLNode* node){
        if(node){
            this->name.cleanName();
            this->value.cleanName();
            this->name.setName(node->name.getName());
            this->value.setName(node->value.getName());
            return true;
        }
        return false;
    }

private:
    edk::Name name;
    edk::Name value;
};
class SQLNodes{
public:
    SQLNodes():nodes(5){}
    ~SQLNodes(){
        edk::uint32 size = this->nodes.size();
        edk::sql::SQLNode* temp;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->nodes[i];
            if(temp){
                delete temp;
            }
        }
        this->nodes.clean();
    }
    //add a node
    bool addNode(edk::char8* name,edk::char8* value){
        //test the name
        if(name){
            //create the node
            edk::sql::SQLNode* node;
            node = new edk::sql::SQLNode(name,value);
            if(node){
                edk::uint32 size = this->nodes.size();
                //add the node
                this->nodes.pushBack(node);
                if(size < this->nodes.size()){
                    return true;
                }
                delete node;
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
            if(temp){
                delete temp;
            }
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
}
}

#endif // SQLGROUP_H
