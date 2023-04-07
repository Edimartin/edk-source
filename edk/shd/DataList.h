#ifndef EDK_SHD_DATALIST_H
#define EDK_SHD_DATALIST_H

/*
Library DATAList - List of data shaders
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
#pragma message "Inside DataList"
#endif

#pragma once
//Use the datas
#include "Data.h"

//use one bynaryTree
#include "../vector/BinaryTree.h"
//the shaderProgram have a name
#include "../Object.h"

//compare string with the edk::String
#include "../String.h"

#ifdef printMessages
#pragma message "    Compiling DataList"
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
    void updateElement(edk::Name* shader){
        //update the tree
        edk::shd::Data* temp = (edk::shd::Data*)shader;edkEnd();
        temp->updateData();edkEnd();
    }
};


class DataList:public edk::ObjectWithName{
public:
    DataList();
    virtual ~DataList();

    //create a new data
    virtual bool newData(const edk::char8* name);
    virtual bool newData(edk::char8* name);
    //Set the data int's
    bool setData1i(const edk::char8* name,edk::int32 d0);
    bool setData1i(edk::char8* name,edk::int32 d0);
    bool setData2i(const edk::char8* name,edk::int32 d0,edk::int32 d1);
    bool setData2i(edk::char8* name,edk::int32 d0,edk::int32 d1);
    bool setData2i(const edk::char8* name,edk::vec2i32 datas);
    bool setData2i(edk::char8* name,edk::vec2i32 datas);
    bool setData3i(const edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2);
    bool setData3i(edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2);
    bool setData3i(const edk::char8* name,edk::vec3i32 datas);
    bool setData3i(edk::char8* name,edk::vec3i32 datas);
    bool setData4i(const edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3);
    bool setData4i(edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3);
    bool setData4i(const edk::char8* name,edk::vec4i32 datas);
    bool setData4i(edk::char8* name,edk::vec4i32 datas);
    //Set the data float's
    bool setData1f(const edk::char8* name,edk::float32 d0);
    bool setData1f(edk::char8* name,edk::float32 d0);
    bool setData2f(const edk::char8* name,edk::float32 d0,edk::float32 d1);
    bool setData2f(edk::char8* name,edk::float32 d0,edk::float32 d1);
    bool setData2f(const edk::char8* name,edk::vec2f32 datas);
    bool setData2f(edk::char8* name,edk::vec2f32 datas);
    bool setData3f(const edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2);
    bool setData3f(edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2);
    bool setData3f(const edk::char8* name,edk::vec3f32 datas);
    bool setData3f(edk::char8* name,edk::vec3f32 datas);
    bool setData4f(const edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3);
    bool setData4f(edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3);
    bool setData4f(const edk::char8* name,edk::vec4f32 datas);
    bool setData4f(edk::char8* name,edk::vec4f32 datas);
    //set the matrices
    bool setMatrix2f(const edk::char8* name,edk::float32 mat[2u][2u]);
    bool setMatrix2f(edk::char8* name,edk::float32 mat[2u][2u]);
    bool setMatrix2f(const edk::char8* name,
                     edk::float32 f11,edk::float32 f12,
                     edk::float32 f21,edk::float32 f22
                     );
    bool setMatrix2f(edk::char8* name,
                     edk::float32 f11,edk::float32 f12,
                     edk::float32 f21,edk::float32 f22
                     );
    bool setMatrix3f(const edk::char8* name,edk::float32 mat[3u][3u]);
    bool setMatrix3f(edk::char8* name,edk::float32 mat[3u][3u]);
    bool setMatrix3f(const edk::char8* name,
                     edk::float32 f11,edk::float32 f12,edk::float32 f13,
                     edk::float32 f21,edk::float32 f22,edk::float32 f23,
                     edk::float32 f31,edk::float32 f32,edk::float32 f33
                     );
    bool setMatrix3f(edk::char8* name,
                     edk::float32 f11,edk::float32 f12,edk::float32 f13,
                     edk::float32 f21,edk::float32 f22,edk::float32 f23,
                     edk::float32 f31,edk::float32 f32,edk::float32 f33
                     );
    bool setMatrix4f(const edk::char8* name,edk::float32 mat[4u][4u]);
    bool setMatrix4f(edk::char8* name,edk::float32 mat[4u][4u]);
    bool setMatrix4f(const edk::char8* name,
                     edk::float32 f11,edk::float32 f12,edk::float32 f13,edk::float32 f14,
                     edk::float32 f21,edk::float32 f22,edk::float32 f23,edk::float32 f24,
                     edk::float32 f31,edk::float32 f32,edk::float32 f33,edk::float32 f34,
                     edk::float32 f41,edk::float32 f42,edk::float32 f43,edk::float32 f44
                     );
    bool setMatrix4f(edk::char8* name,
                     edk::float32 f11,edk::float32 f12,edk::float32 f13,edk::float32 f14,
                     edk::float32 f21,edk::float32 f22,edk::float32 f23,edk::float32 f24,
                     edk::float32 f31,edk::float32 f32,edk::float32 f33,edk::float32 f34,
                     edk::float32 f41,edk::float32 f42,edk::float32 f43,edk::float32 f44
                     );

    //SET AND UPDATE DATA'S
    //update the data int's
    bool updateData1i(const edk::char8* name,edk::int32 d0);
    bool updateData1i(edk::char8* name,edk::int32 d0);
    bool updateData2i(const edk::char8* name,edk::int32 d0,edk::int32 d1);
    bool updateData2i(edk::char8* name,edk::int32 d0,edk::int32 d1);
    bool updateData2i(const edk::char8* name,edk::vec2i32 datas);
    bool updateData2i(edk::char8* name,edk::vec2i32 datas);
    bool updateData3i(const edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2);
    bool updateData3i(edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2);
    bool updateData3i(const edk::char8* name,edk::vec3i32 datas);
    bool updateData3i(edk::char8* name,edk::vec3i32 datas);
    bool updateData4i(const edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3);
    bool updateData4i(edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3);
    bool updateData4i(const edk::char8* name,edk::vec4i32 datas);
    bool updateData4i(edk::char8* name,edk::vec4i32 datas);
    //update the data float's
    bool updateData1f(const edk::char8* name,edk::float32 d0);
    bool updateData1f(edk::char8* name,edk::float32 d0);
    bool updateData2f(const edk::char8* name,edk::float32 d0,edk::float32 d1);
    bool updateData2f(edk::char8* name,edk::float32 d0,edk::float32 d1);
    bool updateData2f(const edk::char8* name,edk::vec2f32 datas);
    bool updateData2f(edk::char8* name,edk::vec2f32 datas);
    bool updateData3f(const edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2);
    bool updateData3f(edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2);
    bool updateData3f(const edk::char8* name,edk::vec3f32 datas);
    bool updateData3f(edk::char8* name,edk::vec3f32 datas);
    bool updateData4f(const edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3);
    bool updateData4f(edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3);
    bool updateData4f(const edk::char8* name,edk::vec4f32 datas);
    bool updateData4f(edk::char8* name,edk::vec4f32 datas);
    //set the matrices
    bool updateMatrix2f(const edk::char8* name,edk::float32 mat[2u][2u]);
    bool updateMatrix2f(edk::char8* name,edk::float32 mat[2u][2u]);
    bool updateMatrix2f(const edk::char8* name,
                     edk::float32 f11,edk::float32 f12,
                     edk::float32 f21,edk::float32 f22
                     );
    bool updateMatrix2f(edk::char8* name,
                     edk::float32 f11,edk::float32 f12,
                     edk::float32 f21,edk::float32 f22
                     );
    bool updateMatrix3f(const edk::char8* name,edk::float32 mat[3u][3u]);
    bool updateMatrix3f(edk::char8* name,edk::float32 mat[3u][3u]);
    bool updateMatrix3f(const edk::char8* name,
                     edk::float32 f11,edk::float32 f12,edk::float32 f13,
                     edk::float32 f21,edk::float32 f22,edk::float32 f23,
                     edk::float32 f31,edk::float32 f32,edk::float32 f33
                     );
    bool updateMatrix3f(edk::char8* name,
                     edk::float32 f11,edk::float32 f12,edk::float32 f13,
                     edk::float32 f21,edk::float32 f22,edk::float32 f23,
                     edk::float32 f31,edk::float32 f32,edk::float32 f33
                     );
    bool updateMatrix4f(const edk::char8* name,edk::float32 mat[4u][4u]);
    bool updateMatrix4f(edk::char8* name,edk::float32 mat[4u][4u]);
    bool updateMatrix4f(const edk::char8* name,
                     edk::float32 f11,edk::float32 f12,edk::float32 f13,edk::float32 f14,
                     edk::float32 f21,edk::float32 f22,edk::float32 f23,edk::float32 f24,
                     edk::float32 f31,edk::float32 f32,edk::float32 f33,edk::float32 f34,
                     edk::float32 f41,edk::float32 f42,edk::float32 f43,edk::float32 f44
                     );
    bool updateMatrix4f(edk::char8* name,
                     edk::float32 f11,edk::float32 f12,edk::float32 f13,edk::float32 f14,
                     edk::float32 f21,edk::float32 f22,edk::float32 f23,edk::float32 f24,
                     edk::float32 f31,edk::float32 f32,edk::float32 f33,edk::float32 f34,
                     edk::float32 f41,edk::float32 f42,edk::float32 f43,edk::float32 f44
                     );

    //update one data
    virtual bool updateData(const edk::char8* name);
    virtual bool updateData(edk::char8* name);
    //update all datas
    bool updateAllDatas();

    //remove a data
    void deleteData(const edk::char8* name);
    void deleteData(edk::char8* name);
    //clean the datas
    void cleanDatas();
protected:
    //Set the id of the data
    bool setDataID(const edk::char8* name,edk::int32 id);
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
