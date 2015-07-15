#ifndef EDK_SHD_DATALIST_H
#define EDK_SHD_DATALIST_H

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
#warning "Inside DataList"
#endif

//Use the datas
#include "Data.h"

//use one bynaryTree
#include "../vector/BinaryTree.h"
//the shaderProgram have a name
#include "../Object.h"

//compare string with the edk::String
#include "../String.h"

#ifdef printMessages
#warning "    Compiling DataList"
#endif

namespace edk{
namespace shd{

class dataTREE: public edk::vector::NameTree{
    //
public:
    dataTREE(){
        //
    }
    ~dataTREE(){
        //
    }
    void updateElement(edk::vector::Name* shader){
        //update the tree
        edk::shd::Data* temp = (edk::shd::Data*)shader;
        temp->updateData();
    }
};


class DataList:public edk::ObjectWithName{
public:
    DataList();
    virtual ~DataList();

    //create a new data
    virtual bool newData(const char* name);
    virtual bool newData(edk::char8* name);
    //Set the data int's
    bool setData1i(const char* name,edk::int32 d0);
    bool setData1i(edk::char8* name,edk::int32 d0);
    bool setData2i(const char* name,edk::int32 d0,edk::int32 d1);
    bool setData2i(edk::char8* name,edk::int32 d0,edk::int32 d1);
    bool setData2i(const char* name,edk::vec2i32 datas);
    bool setData2i(edk::char8* name,edk::vec2i32 datas);
    bool setData3i(const char* name,edk::int32 d0,edk::int32 d1,edk::int32 d2);
    bool setData3i(edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2);
    bool setData3i(const char* name,edk::vec3i32 datas);
    bool setData3i(edk::char8* name,edk::vec3i32 datas);
    bool setData4i(const char* name,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3);
    bool setData4i(edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3);
    bool setData4i(const char* name,edk::vec4i32 datas);
    bool setData4i(edk::char8* name,edk::vec4i32 datas);
    //Set the data float's
    bool setData1f(const char* name,edk::float32 d0);
    bool setData1f(edk::char8* name,edk::float32 d0);
    bool setData2f(const char* name,edk::float32 d0,edk::float32 d1);
    bool setData2f(edk::char8* name,edk::float32 d0,edk::float32 d1);
    bool setData2f(const char* name,edk::vec2f32 datas);
    bool setData2f(edk::char8* name,edk::vec2f32 datas);
    bool setData3f(const char* name,edk::float32 d0,edk::float32 d1,edk::float32 d2);
    bool setData3f(edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2);
    bool setData3f(const char* name,edk::vec3f32 datas);
    bool setData3f(edk::char8* name,edk::vec3f32 datas);
    bool setData4f(const char* name,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3);
    bool setData4f(edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3);
    bool setData4f(const char* name,edk::vec4f32 datas);
    bool setData4f(edk::char8* name,edk::vec4f32 datas);

    //SET AND UPDATE DATA'S
    //update the data int's
    bool updateData1i(const char* name,edk::int32 d0);
    bool updateData1i(edk::char8* name,edk::int32 d0);
    bool updateData2i(const char* name,edk::int32 d0,edk::int32 d1);
    bool updateData2i(edk::char8* name,edk::int32 d0,edk::int32 d1);
    bool updateData2i(const char* name,edk::vec2i32 datas);
    bool updateData2i(edk::char8* name,edk::vec2i32 datas);
    bool updateData3i(const char* name,edk::int32 d0,edk::int32 d1,edk::int32 d2);
    bool updateData3i(edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2);
    bool updateData3i(const char* name,edk::vec3i32 datas);
    bool updateData3i(edk::char8* name,edk::vec3i32 datas);
    bool updateData4i(const char* name,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3);
    bool updateData4i(edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3);
    bool updateData4i(const char* name,edk::vec4i32 datas);
    bool updateData4i(edk::char8* name,edk::vec4i32 datas);
    //update the data float's
    bool updateData1f(const char* name,edk::float32 d0);
    bool updateData1f(edk::char8* name,edk::float32 d0);
    bool updateData2f(const char* name,edk::float32 d0,edk::float32 d1);
    bool updateData2f(edk::char8* name,edk::float32 d0,edk::float32 d1);
    bool updateData2f(const char* name,edk::vec2f32 datas);
    bool updateData2f(edk::char8* name,edk::vec2f32 datas);
    bool updateData3f(const char* name,edk::float32 d0,edk::float32 d1,edk::float32 d2);
    bool updateData3f(edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2);
    bool updateData3f(const char* name,edk::vec3f32 datas);
    bool updateData3f(edk::char8* name,edk::vec3f32 datas);
    bool updateData4f(const char* name,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3);
    bool updateData4f(edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3);
    bool updateData4f(const char* name,edk::vec4f32 datas);
    bool updateData4f(edk::char8* name,edk::vec4f32 datas);

    //update one data
    virtual bool updateData(const char* name);
    virtual bool updateData(edk::char8* name);
    //update all datas
    bool updateAllDatas();

    //remove a data
    void deleteData(const char* name);
    void deleteData(edk::char8* name);
    //clean the datas
    void cleanDatas();
protected:
    //Set the id of the data
    bool setDataID(const char* name,edk::int32 id);
    bool setDataID(edk::char8* name,edk::int32 id);
private:
    //save the datas on the tree
    edk::shd::dataTREE tree;
    //data selected
    edk::shd::Data* selected;

    //select the data
    bool selectData(edk::char8* name);
};
}//end namespace shd
}//end namespace edk

#endif // DATALIST_H
