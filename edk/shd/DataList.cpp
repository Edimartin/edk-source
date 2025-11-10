#include "DataList.h"

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
#pragma message "            Inside DataList.cpp"
#endif

edk::shd::DataList::DataList(){
    this->classThis=NULL;
    this->Constructor();
}

edk::shd::DataList::~DataList(){
    this->Destructor();
}

void edk::shd::DataList::Constructor(){
    edk::ObjectWithName::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->tree.Constructor();

        this->selected=NULL;
    }
}
void edk::shd::DataList::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->selected=NULL;
        //clean all the datas
        this->cleanDatas();

        this->tree.Destructor();
    }
    edk::ObjectWithName::Destructor();
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
            if(count==1u){
                break;
            }
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
bool edk::shd::DataList::setDataID(const edk::char8* name,edk::int32 id){
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
bool edk::shd::DataList::newData(const edk::char8* name){
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
bool edk::shd::DataList::setData1i(const edk::char8* name,edk::int32 d0){
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
bool edk::shd::DataList::setData2i(const edk::char8* name,edk::int32 d0,edk::int32 d1){
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
bool edk::shd::DataList::setData2i(const edk::char8* name,edk::vec2i32 datas){
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
bool edk::shd::DataList::setData3i(const edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2){
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
bool edk::shd::DataList::setData3i(const edk::char8* name,edk::vec3i32 datas){
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
bool edk::shd::DataList::setData4i(const edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3){
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
bool edk::shd::DataList::setData4i(const edk::char8* name,edk::vec4i32 datas){
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
bool edk::shd::DataList::setData1f(const edk::char8* name,edk::float32 d0){
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
bool edk::shd::DataList::setData2f(const edk::char8* name,edk::float32 d0,edk::float32 d1){
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
bool edk::shd::DataList::setData2f(const edk::char8* name,edk::vec2f32 datas){
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
bool edk::shd::DataList::setData3f(const edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2){
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
bool edk::shd::DataList::setData3f(const edk::char8* name,edk::vec3f32 datas){
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
bool edk::shd::DataList::setData4f(const edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3){
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
bool edk::shd::DataList::setData4f(const edk::char8* name,edk::vec4f32 datas){
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
//set the matrices
bool edk::shd::DataList::setMatrix2f(const edk::char8* name,edk::vector::Matrix<edk::float32,2u,2u> mat){
    if(mat.haveMatrix()){
        return this->setMatrix2f((edk::char8*) name,
                                 mat.getNoIF(0u,0u),mat.getNoIF(0u,1u),
                                 mat.getNoIF(1u,0u),mat.getNoIF(1u,1u)
                                 );
    }
    return false;
}
bool edk::shd::DataList::setMatrix2f(edk::char8* name,edk::vector::Matrix<edk::float32,2u,2u> mat){
    if(mat.haveMatrix()){
        return this->setMatrix2f(name,
                                 mat.getNoIF(0u,0u),mat.getNoIF(0u,1u),
                                 mat.getNoIF(1u,0u),mat.getNoIF(1u,1u)
                                 );
    }
    return false;
}
bool edk::shd::DataList::setMatrix2f(const edk::char8* name,edk::vector::Matrix<edk::float32,2u,2u>* mat){
    if(mat){
        if(mat->haveMatrix()){
            return this->setMatrix2f((edk::char8*) name,
                                     mat->getNoIF(0u,0u),mat->getNoIF(0u,1u),
                                     mat->getNoIF(1u,0u),mat->getNoIF(1u,1u)
                                     );
        }
    }
    return false;
}
bool edk::shd::DataList::setMatrix2f(edk::char8* name,edk::vector::Matrix<edk::float32,2u,2u>* mat){
    if(mat){
        if(mat->haveMatrix()){
            return this->setMatrix2f(name,
                                     mat->getNoIF(0u,0u),mat->getNoIF(0u,1u),
                                     mat->getNoIF(1u,0u),mat->getNoIF(1u,1u)
                                     );
        }
    }
    return false;
}
bool edk::shd::DataList::setMatrix2f(const edk::char8* name,edk::float32 mat[2u][2u]){
    return this->setMatrix2f((edk::char8*) name,mat);
}
bool edk::shd::DataList::setMatrix2f(edk::char8* name,edk::float32 mat[2u][2u]){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setMatrix2f(mat);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::setMatrix2f(const edk::char8* name,
                                     edk::float32 f00,edk::float32 f01,
                                     edk::float32 f10,edk::float32 f11
                                     ){
    return this->setMatrix2f((edk::char8*) name,
                             f00,f01,
                             f10,f11
                             );
}
bool edk::shd::DataList::setMatrix2f(edk::char8* name,
                                     edk::float32 f00,edk::float32 f01,
                                     edk::float32 f10,edk::float32 f11
                                     ){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setMatrix2f(f00,f01,
                                    f10,f11
                                    );
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::setMatrix3f(const edk::char8* name,edk::vector::Matrix<edk::float32,3u,3u> mat){
    if(mat.haveMatrix()){
        return this->setMatrix3f((edk::char8*) name,
                                 mat.getNoIF(0u,0u),mat.getNoIF(0u,1u),mat.getNoIF(0u,2u),
                                 mat.getNoIF(1u,0u),mat.getNoIF(1u,1u),mat.getNoIF(1u,2u),
                                 mat.getNoIF(2u,0u),mat.getNoIF(2u,1u),mat.getNoIF(2u,2u)
                                 );
    }
    return false;
}
bool edk::shd::DataList::setMatrix3f(edk::char8* name,edk::vector::Matrix<edk::float32,3u,3u> mat){
    if(mat.haveMatrix()){
        return this->setMatrix3f(name,
                                 mat.getNoIF(0u,0u),mat.getNoIF(0u,1u),mat.getNoIF(0u,2u),
                                 mat.getNoIF(1u,0u),mat.getNoIF(1u,1u),mat.getNoIF(1u,2u),
                                 mat.getNoIF(2u,0u),mat.getNoIF(2u,1u),mat.getNoIF(2u,2u)
                                 );
    }
    return false;
}
bool edk::shd::DataList::setMatrix3f(const edk::char8* name,edk::vector::Matrix<edk::float32,3u,3u>* mat){
    if(mat){
        if(mat->haveMatrix()){
            return this->setMatrix3f((edk::char8*) name,
                                     mat->getNoIF(0u,0u),mat->getNoIF(0u,1u),mat->getNoIF(0u,2u),
                                     mat->getNoIF(1u,0u),mat->getNoIF(1u,1u),mat->getNoIF(1u,2u),
                                     mat->getNoIF(2u,0u),mat->getNoIF(2u,1u),mat->getNoIF(2u,2u)
                                     );
        }
    }
    return false;
}
bool edk::shd::DataList::setMatrix3f(edk::char8* name,edk::vector::Matrix<edk::float32,3u,3u>* mat){
    if(mat){
        if(mat->haveMatrix()){
            return this->setMatrix3f(name,
                                     mat->getNoIF(0u,0u),mat->getNoIF(0u,1u),mat->getNoIF(0u,2u),
                                     mat->getNoIF(1u,0u),mat->getNoIF(1u,1u),mat->getNoIF(1u,2u),
                                     mat->getNoIF(2u,0u),mat->getNoIF(2u,1u),mat->getNoIF(2u,2u)
                                     );
        }
    }
    return false;
}
bool edk::shd::DataList::setMatrix3f(const edk::char8* name,edk::float32 mat[3u][3u]){
    return this->setMatrix3f((edk::char8*) name,mat);
}
bool edk::shd::DataList::setMatrix3f(edk::char8* name,edk::float32 mat[3u][3u]){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setMatrix3f(mat);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::setMatrix3f(const edk::char8* name,
                                     edk::float32 f00,edk::float32 f01,edk::float32 f02,
                                     edk::float32 f10,edk::float32 f11,edk::float32 f12,
                                     edk::float32 f20,edk::float32 f21,edk::float32 f22
                                     ){
    return this->setMatrix3f((edk::char8*) name,
                             f00,f01,f02,
                             f10,f11,f12,
                             f20,f21,f22
                             );
}
bool edk::shd::DataList::setMatrix3f(edk::char8* name,
                                     edk::float32 f00,edk::float32 f01,edk::float32 f02,
                                     edk::float32 f10,edk::float32 f11,edk::float32 f12,
                                     edk::float32 f20,edk::float32 f21,edk::float32 f22
                                     ){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setMatrix3f(f00,f01,f02,
                                    f10,f11,f12,
                                    f20,f21,f22
                                    );
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::setMatrix4f(const edk::char8* name,edk::vector::Matrix<edk::float32,4u,4u> mat){
    if(mat.haveMatrix()){
        return this->setMatrix4f((edk::char8*) name,
                                 mat.getNoIF(0u,0u),mat.getNoIF(0u,1u),mat.getNoIF(0u,2u),mat.getNoIF(0u,3u),
                                 mat.getNoIF(1u,0u),mat.getNoIF(1u,1u),mat.getNoIF(1u,2u),mat.getNoIF(1u,3u),
                                 mat.getNoIF(2u,0u),mat.getNoIF(2u,1u),mat.getNoIF(2u,2u),mat.getNoIF(2u,3u),
                                 mat.getNoIF(3u,0u),mat.getNoIF(3u,1u),mat.getNoIF(3u,2u),mat.getNoIF(3u,3u)
                                 );
    }
    return false;
}
bool edk::shd::DataList::setMatrix4f(edk::char8* name,edk::vector::Matrix<edk::float32,4u,4u> mat){
    if(mat.haveMatrix()){
        return this->setMatrix4f(name,
                                 mat.getNoIF(0u,0u),mat.getNoIF(0u,1u),mat.getNoIF(0u,2u),mat.getNoIF(0u,3u),
                                 mat.getNoIF(1u,0u),mat.getNoIF(1u,1u),mat.getNoIF(1u,2u),mat.getNoIF(1u,3u),
                                 mat.getNoIF(2u,0u),mat.getNoIF(2u,1u),mat.getNoIF(2u,2u),mat.getNoIF(2u,3u),
                                 mat.getNoIF(3u,0u),mat.getNoIF(3u,1u),mat.getNoIF(3u,2u),mat.getNoIF(3u,3u)
                                 );
    }
    return false;
}
bool edk::shd::DataList::setMatrix4f(const edk::char8* name,edk::vector::Matrix<edk::float32,4u,4u>* mat){
    if(mat){
        if(mat->haveMatrix()){
            return this->setMatrix4f((edk::char8*) name,
                                     mat->getNoIF(0u,0u),mat->getNoIF(0u,1u),mat->getNoIF(0u,2u),mat->getNoIF(0u,3u),
                                     mat->getNoIF(1u,0u),mat->getNoIF(1u,1u),mat->getNoIF(1u,2u),mat->getNoIF(1u,3u),
                                     mat->getNoIF(2u,0u),mat->getNoIF(2u,1u),mat->getNoIF(2u,2u),mat->getNoIF(2u,3u),
                                     mat->getNoIF(3u,0u),mat->getNoIF(3u,1u),mat->getNoIF(3u,2u),mat->getNoIF(3u,3u)
                                     );
        }
    }
    return false;
}
bool edk::shd::DataList::setMatrix4f(edk::char8* name,edk::vector::Matrix<edk::float32,4u,4u>* mat){
    if(mat){
        if(mat->haveMatrix()){
            return this->setMatrix4f(name,
                                     mat->getNoIF(0u,0u),mat->getNoIF(0u,1u),mat->getNoIF(0u,2u),mat->getNoIF(0u,3u),
                                     mat->getNoIF(1u,0u),mat->getNoIF(1u,1u),mat->getNoIF(1u,2u),mat->getNoIF(1u,3u),
                                     mat->getNoIF(2u,0u),mat->getNoIF(2u,1u),mat->getNoIF(2u,2u),mat->getNoIF(2u,3u),
                                     mat->getNoIF(3u,0u),mat->getNoIF(3u,1u),mat->getNoIF(3u,2u),mat->getNoIF(3u,3u)
                                     );
        }
    }
    return false;
}
bool edk::shd::DataList::setMatrix4f(const edk::char8* name,edk::float32 mat[4u][4u]){
    return this->setMatrix4f((edk::char8*) name,mat);
}
bool edk::shd::DataList::setMatrix4f(edk::char8* name,edk::float32 mat[4u][4u]){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setMatrix4f(mat);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::setMatrix4f(const edk::char8* name,
                                     edk::float32 f00,edk::float32 f01,edk::float32 f02,edk::float32 f03,
                                     edk::float32 f10,edk::float32 f11,edk::float32 f12,edk::float32 f13,
                                     edk::float32 f20,edk::float32 f21,edk::float32 f22,edk::float32 f23,
                                     edk::float32 f30,edk::float32 f31,edk::float32 f32,edk::float32 f33
                                     ){
    return this->setMatrix4f((edk::char8*) name,
                             f00,f01,f02,f03,
                             f10,f11,f12,f13,
                             f20,f21,f22,f23,
                             f30,f31,f32,f33
                             );
}
bool edk::shd::DataList::setMatrix4f(edk::char8* name,
                                     edk::float32 f00,edk::float32 f01,edk::float32 f02,edk::float32 f03,
                                     edk::float32 f10,edk::float32 f11,edk::float32 f12,edk::float32 f13,
                                     edk::float32 f20,edk::float32 f21,edk::float32 f22,edk::float32 f23,
                                     edk::float32 f30,edk::float32 f31,edk::float32 f32,edk::float32 f33
                                     ){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setMatrix4f(f00,f01,f02,f03,
                                    f10,f11,f12,f13,
                                    f20,f21,f22,f23,
                                    f30,f31,f32,f33
                                    );
        //return true
        return true;
    }
    //else return false
    return false;
}



//SET AND UPDATE DATA'S
//update the data int's
bool edk::shd::DataList::updateData1i(const edk::char8* name,edk::int32 d0){
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
bool edk::shd::DataList::updateData2i(const edk::char8* name,edk::int32 d0,edk::int32 d1){
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
bool edk::shd::DataList::updateData2i(const edk::char8* name,edk::vec2i32 datas){
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
bool edk::shd::DataList::updateData3i(const edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2){
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
bool edk::shd::DataList::updateData3i(const edk::char8* name,edk::vec3i32 datas){
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
bool edk::shd::DataList::updateData4i(const edk::char8* name,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3){
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
bool edk::shd::DataList::updateData4i(const edk::char8* name,edk::vec4i32 datas){
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
bool edk::shd::DataList::updateData1f(const edk::char8* name,edk::float32 d0){
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
bool edk::shd::DataList::updateData2f(const edk::char8* name,edk::float32 d0,edk::float32 d1){
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
bool edk::shd::DataList::updateData2f(const edk::char8* name,edk::vec2f32 datas){
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
bool edk::shd::DataList::updateData3f(const edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2){
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
bool edk::shd::DataList::updateData3f(const edk::char8* name,edk::vec3f32 datas){
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
bool edk::shd::DataList::updateData4f(const edk::char8* name,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3){
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
bool edk::shd::DataList::updateData4f(const edk::char8* name,edk::vec4f32 datas){
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
//set the matrices
bool edk::shd::DataList::updateMatrix2f(const edk::char8* name,edk::float32 mat[2u][2u]){
    return this->updateMatrix2f((edk::char8*) name,mat);
}
bool edk::shd::DataList::updateMatrix2f(edk::char8* name,edk::float32 mat[2u][2u]){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setMatrix2f(mat);
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::updateMatrix2f(const edk::char8* name,
                                        edk::float32 f11,edk::float32 f12,
                                        edk::float32 f21,edk::float32 f22
                                        ){
    return this->updateMatrix2f((edk::char8*) name,
                                f11,f12,
                                f21,f22
                                );
}
bool edk::shd::DataList::updateMatrix2f(edk::char8* name,
                                        edk::float32 f11,edk::float32 f12,
                                        edk::float32 f21,edk::float32 f22
                                        ){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setMatrix2f(f11,f12,
                                    f21,f22
                                    );
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::updateMatrix3f(const edk::char8* name,edk::float32 mat[3u][3u]){
    return this->updateMatrix3f((edk::char8*) name,mat);
}
bool edk::shd::DataList::updateMatrix3f(edk::char8* name,edk::float32 mat[3u][3u]){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setMatrix3f(mat);
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::updateMatrix3f(const edk::char8* name,
                                        edk::float32 f11,edk::float32 f12,edk::float32 f13,
                                        edk::float32 f21,edk::float32 f22,edk::float32 f23,
                                        edk::float32 f31,edk::float32 f32,edk::float32 f33
                                        ){
    return this->updateMatrix3f((edk::char8*) name,
                                f11,f12,f13,
                                f21,f22,f23,
                                f31,f32,f33
                                );
}
bool edk::shd::DataList::updateMatrix3f(edk::char8* name,
                                        edk::float32 f11,edk::float32 f12,edk::float32 f13,
                                        edk::float32 f21,edk::float32 f22,edk::float32 f23,
                                        edk::float32 f31,edk::float32 f32,edk::float32 f33
                                        ){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setMatrix3f(f11,f12,f13,
                                    f21,f22,f23,
                                    f31,f32,f33
                                    );
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::updateMatrix4f(const edk::char8* name,edk::float32 mat[4u][4u]){
    return this->updateMatrix4f((edk::char8*) name,mat);
}
bool edk::shd::DataList::updateMatrix4f(edk::char8* name,edk::float32 mat[4u][4u]){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setMatrix4f(mat);
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shd::DataList::updateMatrix4f(const edk::char8* name,
                                        edk::float32 f11,edk::float32 f12,edk::float32 f13,edk::float32 f14,
                                        edk::float32 f21,edk::float32 f22,edk::float32 f23,edk::float32 f24,
                                        edk::float32 f31,edk::float32 f32,edk::float32 f33,edk::float32 f34,
                                        edk::float32 f41,edk::float32 f42,edk::float32 f43,edk::float32 f44
                                        ){
    return this->updateMatrix4f((edk::char8*) name,
                                f11,f12,f13,f14,
                                f21,f22,f23,f24,
                                f31,f32,f33,f34,
                                f41,f42,f43,f44
                                );
}
bool edk::shd::DataList::updateMatrix4f(edk::char8* name,
                                        edk::float32 f11,edk::float32 f12,edk::float32 f13,edk::float32 f14,
                                        edk::float32 f21,edk::float32 f22,edk::float32 f23,edk::float32 f24,
                                        edk::float32 f31,edk::float32 f32,edk::float32 f33,edk::float32 f34,
                                        edk::float32 f41,edk::float32 f42,edk::float32 f43,edk::float32 f44
                                        ){
    //select the data
    if(this->selectData(name)){
        //set the id
        this->selected->setMatrix4f(f11,f12,f13,f14,
                                    f21,f22,f23,f24,
                                    f31,f32,f33,f34,
                                    f41,f42,f43,f44
                                    );
        this->updateData(name);
        //return true
        return true;
    }
    //else return false
    return false;
}

//update one data
bool edk::shd::DataList::updateData(const edk::char8* name){
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
void edk::shd::DataList::deleteData(const edk::char8* name){
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
