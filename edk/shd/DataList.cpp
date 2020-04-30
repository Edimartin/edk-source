#include "DataList.h"

/*
Library DATAList - List of data shaders
Copyright (C) 2013 Eduardo Moura Sales Martins
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

#ifdef printMessages
#warning "            Inside DataList.cpp"
#endif

edk::shd::DataList::DataList()
{
    //ctor
    this->selected=NULL;
}

edk::shd::DataList::~DataList()
{
    //dtor
    this->selected=NULL;
    //clean all the datas
    this->cleanDatas();
}

//select the data
bool edk::shd::DataList::selectData(edk::char8* name){
    edk::uint8 count = 2u;
    do{
        //select the data
        this->selected=(edk::shd::Data*)this->tree.getElementByName(name);
        if(this->selected){
            //return true
            return true;
        }
        else{
            if(count==1u)
                break;
            //else add the newData
            this->newData(name);
        }
        //decrement count
        count--;
    }while(count);
    //else return false
    return false;
}
//Set the id of the data
bool edk::shd::DataList::setDataID(const char* name,edk::int32 id){
    //
    return this->setDataID((edk::char8*) name,id);
}
bool edk::shd::DataList::setDataID(edk::char8* name,edk::int32 id){
    //select the data
    if(this->selectData(name) && id!=-1){
        //set the id
        this->selected->ID=id;
        //return true
        return true;
    }
    //else return false
    return false;
}

//create a new data
bool edk::shd::DataList::newData(const char* name){
    //
    return this->newData((edk::char8*) name);
}
bool edk::shd::DataList::newData(edk::char8* name){
    //test if the name is true
    if(name){
        //then create the new data
        edk::shd::Data* temp = new edk::shd::Data();
        //test if have a tmep
        if(temp){
            //set the dataName
            if(temp->setName(name)){
                //then add to the tree
                if(this->tree.add(temp)){
                    //return true
                    return true;
                }
            }
            //else delete the temp
            delete temp;
        }
    }
    //else return false
    return false;
}

//clean the datas
void edk::shd::DataList::cleanDatas(){
    //delete the datas
    for(edk::uint32 i=0u;i<this->tree.size();i++){
        //return the element
        edk::shd::Data* temp= (edk::shd::Data*)this->tree.getElementInPosition(i);
        if(temp){
            delete temp;
        }
    }
    //clean the tree
    this->tree.clean();
}

//Set the data int's
bool edk::shd::DataList::setData1i(const char* name,edk::int32 d0){
    //select the data
    return this->setData1i((edk::char8*) name,d0);
}
bool edk::shd::DataList::setData1i(edk::char8* name,edk::int32 d0){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData1i(d0);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::setData2i(const char* name,edk::int32 d0,edk::int32 d1){
    //select the data
    return this->setData2i((edk::char8*) name,d0,d1);
}
bool edk::shd::DataList::setData2i(edk::char8* name,edk::int32 d0,edk::int32 d1){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData2i(d0,d1);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::setData2i(const char* name,edk::vec2i32 datas){
    //select the data
    return this->setData2i((edk::char8*) name,datas);
}
bool edk::shd::DataList::setData2i(edk::char8* name,edk::vec2i32 datas){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData2i(datas);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::setData3i(const char* name,edk::int32 d0,edk::int32 d1,edk::int32 d2){
    //select the data
    return this->setData3i((edk::char8*) name,d0,d1,d2);
}
bool edk::shd::DataList::setData3i(edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData3i(d0,d1,d2);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::setData3i(const char* name,edk::vec3i32 datas){
    //
    return this->setData3i((edk::char8*) name,datas);
}
bool edk::shd::DataList::setData3i(edk::char8* name,edk::vec3i32 datas){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData3i(datas);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::setData4i(const char* name,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3){
    //select the data
    return this->setData4i((edk::char8*) name,d0,d1,d2,d3);
}
bool edk::shd::DataList::setData4i(edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData4i(d0,d1,d2,d3);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::setData4i(const char* name,edk::vec4i32 datas){
    //
    return this->setData4i((edk::char8*) name,datas);
}
bool edk::shd::DataList::setData4i(edk::char8* name,edk::vec4i32 datas){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData4i(datas);
        //return true
        return true;
    }
    //else return false
    return false;
}
//Set the data float's
bool edk::shd::DataList::setData1f(const char* name,edk::float32 d0){
    //select the data
    return this->setData1f((edk::char8*) name,d0);
}
bool edk::shd::DataList::setData1f(edk::char8* name,edk::float32 d0){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData1f(d0);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::setData2f(const char* name,edk::float32 d0,edk::float32 d1){
    //select the data
    return this->setData2f((edk::char8*) name,d0,d1);
}
bool edk::shd::DataList::setData2f(edk::char8* name,edk::float32 d0,edk::float32 d1){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData2f(d0,d1);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::setData2f(const char* name,edk::vec2f32 datas){
    //select the data
    return this->setData2f((edk::char8*) name,datas);
}
bool edk::shd::DataList::setData2f(edk::char8* name,edk::vec2f32 datas){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData2f(datas);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::setData3f(const char* name,edk::float32 d0,edk::float32 d1,edk::float32 d2){
    //select the data
    return this->setData3f((edk::char8*) name,d0,d1,d2);
}
bool edk::shd::DataList::setData3f(edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData3f(d0,d1,d2);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::setData3f(const char* name,edk::vec3f32 datas){
    //
    return this->setData3f((edk::char8*) name,datas);
}
bool edk::shd::DataList::setData3f(edk::char8* name,edk::vec3f32 datas){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData3f(datas);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::setData4f(const char* name,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3){
    //select the data
    return this->setData4f((edk::char8*) name,d0,d1,d2,d3);
}
bool edk::shd::DataList::setData4f(edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData4f(d0,d1,d2,d3);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::setData4f(const char* name,edk::vec4f32 datas){
    //
    return this->setData4f((edk::char8*) name,datas);
}
bool edk::shd::DataList::setData4f(edk::char8* name,edk::vec4f32 datas){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData4f(datas);
        //return true
        return true;
    }
    //else return false
    return false;
}



//SET AND UPDATE DATA'S
//update the data int's
bool edk::shd::DataList::updateData1i(const char* name,edk::int32 d0){
    //select the data
    return this->updateData1i((edk::char8*) name,d0);
}
bool edk::shd::DataList::updateData1i(edk::char8* name,edk::int32 d0){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData1i(d0);
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::updateData2i(const char* name,edk::int32 d0,edk::int32 d1){
    //select the data
    return this->updateData2i((edk::char8*) name,d0,d1);
}
bool edk::shd::DataList::updateData2i(edk::char8* name,edk::int32 d0,edk::int32 d1){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData2i(d0,d1);
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::updateData2i(const char* name,edk::vec2i32 datas){
    //select the data
    return this->updateData2i((edk::char8*) name,datas);
}
bool edk::shd::DataList::updateData2i(edk::char8* name,edk::vec2i32 datas){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData2i(datas);
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::updateData3i(const char* name,edk::int32 d0,edk::int32 d1,edk::int32 d2){
    //select the data
    return this->updateData3i((edk::char8*) name,d0,d1,d2);
}
bool edk::shd::DataList::updateData3i(edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData3i(d0,d1,d2);
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::updateData3i(const char* name,edk::vec3i32 datas){
    //
    return this->updateData3i((edk::char8*) name,datas);
}
bool edk::shd::DataList::updateData3i(edk::char8* name,edk::vec3i32 datas){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData3i(datas);
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::updateData4i(const char* name,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3){
    //select the data
    return this->updateData4i((edk::char8*) name,d0,d1,d2,d3);
}
bool edk::shd::DataList::updateData4i(edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData4i(d0,d1,d2,d3);
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::updateData4i(const char* name,edk::vec4i32 datas){
    //
    return this->updateData4i((edk::char8*) name,datas);
}
bool edk::shd::DataList::updateData4i(edk::char8* name,edk::vec4i32 datas){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData4i(datas);
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}
//Set the data float's
bool edk::shd::DataList::updateData1f(const char* name,edk::float32 d0){
    //select the data
    return this->updateData1f((edk::char8*) name,d0);
}
bool edk::shd::DataList::updateData1f(edk::char8* name,edk::float32 d0){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData1f(d0);
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::updateData2f(const char* name,edk::float32 d0,edk::float32 d1){
    //select the data
    return this->updateData2f((edk::char8*) name,d0,d1);
}
bool edk::shd::DataList::updateData2f(edk::char8* name,edk::float32 d0,edk::float32 d1){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData2f(d0,d1);
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::updateData2f(const char* name,edk::vec2f32 datas){
    //select the data
    return this->updateData2f((edk::char8*) name,datas);
}
bool edk::shd::DataList::updateData2f(edk::char8* name,edk::vec2f32 datas){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData2f(datas);
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::updateData3f(const char* name,edk::float32 d0,edk::float32 d1,edk::float32 d2){
    //select the data
    return this->updateData3f((edk::char8*) name,d0,d1,d2);
}
bool edk::shd::DataList::updateData3f(edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData3f(d0,d1,d2);
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::updateData3f(const char* name,edk::vec3f32 datas){
    //
    return this->updateData3f((edk::char8*) name,datas);
}
bool edk::shd::DataList::updateData3f(edk::char8* name,edk::vec3f32 datas){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData3f(datas);
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::updateData4f(const char* name,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3){
    //select the data
    return this->updateData4f((edk::char8*) name,d0,d1,d2,d3);
}
bool edk::shd::DataList::updateData4f(edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData4f(d0,d1,d2,d3);
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::updateData4f(const char* name,edk::vec4f32 datas){
    //
    return this->updateData4f((edk::char8*) name,datas);
}
bool edk::shd::DataList::updateData4f(edk::char8* name,edk::vec4f32 datas){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setData4f(datas);
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}

//update one data
bool edk::shd::DataList::updateData(const char* name){
    //
    return this->updateData((edk::char8*) name);
}
bool edk::shd::DataList::updateData(edk::char8* name){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->updateData();
        //return true
        return true;
    }
    //else return false
    return false;
}
//update all datas
bool edk::shd::DataList::updateAllDatas(){
    //test if have datas
    if(this->tree.size()){
        //update all
        /*
        for(edk::uint32 i=0u;i<this->tree.size();i++){
            //select the data
            this->selected = (edk::shd::Data*)this->tree.getElementInPosition(i);
            if(this->selected){
                //update the element
                this->selected->updateData();
            }
        }
        */
        this->tree.update();
        //return true
        return true;
    }
    //else return false
    return false;
}

//remove a data
void edk::shd::DataList::deleteData(const char* name){
    return this->deleteData((edk::char8*) name);
}
void edk::shd::DataList::deleteData(edk::char8* name){
    //select the data
    if(this->selectData(name)){
        //remove the data
        this->tree.remove(this->selected);
        delete this->selected;
        this->selected=NULL;
    }
}
