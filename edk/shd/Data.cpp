#include "Data.h"

/*
Library DATA - Control datas in the edk shaders
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
#pragma message "            Inside Data.cpp"
#endif

edk::shd::Data::Data(){
    this->classThis=NULL;
    this->Constructor();
}

edk::shd::Data::~Data(){
    this->Destructor();
}

void edk::shd::Data::Constructor(){
    edk::Name::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        //set the float
        this->ints.clean(4u);
        this->floats.clean(4u);
        this->ID=-1u;
    }
}
void edk::shd::Data::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->cleanInts();
        this->cleanFloats();
    }
    edk::Name::Destructor();
}

//clean the ints
void edk::shd::Data::cleanInts(){
    //
    if(this->ints.size()){
        this->ints.clean();
    }
}
//clean the floats
void edk::shd::Data::cleanFloats(){
    if(this->floats.size()){
        //
        this->floats.clean();
    }
}
//clean the matrix
void edk::shd::Data::cleanMatrix(){
    memset(this->mat,0u,sizeof(this->mat));
    this->useMatrix=edk::shd::matrix1;
}

//setaData GLint
void edk::shd::Data::setData1i(edk::int32 d0){
    //clean ints
    if(this->ints.size()!=1u){
        this->cleanInts();
        this->ints.pushBack(d0);
    }
    else{
        //else set the value
        this->ints.set(0u,d0);
    }
    //set use
    this->useData=true;
    this->cleanMatrix();
}
void edk::shd::Data::setData2i(edk::int32 d0,edk::int32 d1){
    //
    this->setData2i(edk::vec2i32(d0,d1));
}
void edk::shd::Data::setData2i(edk::vec2i32 datas){
    //clean ints
    if(this->ints.size()!=2u){
        this->cleanInts();
        this->ints.pushBack(datas.x);
        this->ints.pushBack(datas.y);
    }
    else{
        //else set the value
        this->ints.set(1u,datas.x);
        this->ints.set(2u,datas.y);
    }
    //set use
    this->useData=true;
    this->cleanMatrix();
}
void edk::shd::Data::setData3i(edk::int32 d0,edk::int32 d1,edk::int32 d2){
    //
    this->setData3i(edk::vec3i32(d0,d1,d2));
}
void edk::shd::Data::setData3i(edk::vec3i32 datas){
    //clean ints
    if(this->ints.size()!=3u){
        this->cleanInts();
        this->ints.pushBack(datas.x);
        this->ints.pushBack(datas.y);
        this->ints.pushBack(datas.z);
    }
    else{
        //else set the value
        this->ints.set(0u,datas.x);
        this->ints.set(1u,datas.y);
        this->ints.set(2u,datas.z);
    }
    //set use
    this->useData=true;
    this->cleanMatrix();
}
void edk::shd::Data::setData4i(edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3){
    //
    this->setData4i(edk::vec4i32(d0,d1,d2,d3));
}
void edk::shd::Data::setData4i(edk::vec4i32 datas){
    //clean ints
    if(this->ints.size()!=4u){
        this->cleanInts();
        this->ints.pushBack(datas.x);
        this->ints.pushBack(datas.y);
        this->ints.pushBack(datas.z);
        this->ints.pushBack(datas.w);
    }
    else{
        //else set the value
        this->ints.set(0u,datas.x);
        this->ints.set(1u,datas.y);
        this->ints.set(2u,datas.z);
        this->ints.set(3u,datas.w);
    }
    //set use
    this->useData=true;
    this->cleanMatrix();
}

//setaData GLfloat
void edk::shd::Data::setData1f(edk::float32 d0){
    //clean ints
    if(this->floats.size()!=1u){
        this->cleanFloats();
        this->floats.pushBack(d0);
    }
    else{
        //else set the value
        this->floats.set(0u,d0);
    }
    //set use
    this->useData=false;
    this->cleanMatrix();
}
void edk::shd::Data::setData2f(edk::float32 d0,edk::float32 d1){
    //
    setData2f(edk::vec2f32(d0,d1));
}
void edk::shd::Data::setData2f(edk::vec2f32 datas){
    //clean ints
    if(this->floats.size()!=2u){
        this->cleanFloats();
        this->floats.pushBack(datas.x);
        this->floats.pushBack(datas.y);
    }
    else{
        //else set the value
        this->floats.set(0u,datas.x);
        this->floats.set(2u,datas.y);
    }
    //set use
    this->useData=false;
    this->cleanMatrix();
}
void edk::shd::Data::setData3f(edk::float32 d0,edk::float32 d1,edk::float32 d2){
    //
    setData3f(edk::vec3f32(d0,d1,d2));
}
void edk::shd::Data::setData3f(edk::vec3f32 datas){
    //clean ints
    if(this->floats.size()!=3u){
        this->cleanFloats();
        this->floats.pushBack(datas.x);
        this->floats.pushBack(datas.y);
        this->floats.pushBack(datas.z);
    }
    else{
        //else set the value
        this->floats.set(0u,datas.x);
        this->floats.set(1u,datas.y);
        this->floats.set(2u,datas.z);
    }
    //set use
    this->useData=false;
    this->cleanMatrix();
}
void edk::shd::Data::setData4f(edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3){
    //
    setData4f(edk::vec4f32(d0,d1,d2,d3));
}
void edk::shd::Data::setData4f(edk::vec4f32 datas){
    //clean ints
    if(this->floats.size()!=3u){
        this->cleanFloats();
        this->floats.pushBack(datas.x);
        this->floats.pushBack(datas.y);
        this->floats.pushBack(datas.z);
        this->floats.pushBack(datas.w);
    }
    else{
        //else set the value
        this->floats.set(0u,datas.x);
        this->floats.set(1u,datas.y);
        this->floats.set(2u,datas.z);
        this->floats.set(3u,datas.w);
    }
    //set use
    this->useData=false;
    this->cleanMatrix();
}

//Set Matrices
void edk::shd::Data::setMatrix2f(edk::float32 mat[2u][2u]){
    this->setMatrix2f(mat[0u][0u],mat[0u][1u],
            mat[1u][0u],mat[1u][1u]
            );
}
void edk::shd::Data::setMatrix2f(edk::float32 f11,edk::float32 f12,
                                 edk::float32 f21,edk::float32 f22
                                 ){
    this->mat[0u] = f11;
    this->mat[1u] = f12;
    this->mat[2u] = f22;
    this->mat[3u] = f21;
    this->useMatrix = edk::shd::matrix2;
}
void edk::shd::Data::setMatrix3f(edk::float32 mat[3u][3u]){
    this->setMatrix3f(mat[0u][0u],mat[0u][1u],mat[0u][2u],
            mat[1u][0u],mat[1u][1u],mat[1u][2u],
            mat[2u][0u],mat[2u][1u],mat[2u][2u]
            );
}
void edk::shd::Data::setMatrix3f(edk::float32 f11,edk::float32 f12,edk::float32 f13,
                                 edk::float32 f21,edk::float32 f22,edk::float32 f23,
                                 edk::float32 f31,edk::float32 f32,edk::float32 f33
                                 ){
    this->mat[0u] = f11;
    this->mat[1u] = f12;
    this->mat[2u] = f13;
    this->mat[3u] = f21;
    this->mat[4u] = f22;
    this->mat[5u] = f23;
    this->mat[6u] = f31;
    this->mat[7u] = f32;
    this->mat[8u] = f33;
    this->useMatrix = edk::shd::matrix3;
}
void edk::shd::Data::setMatrix4f(edk::float32 mat[4u][4u]){
    this->setMatrix4f(mat[0u][0u],mat[0u][1u],mat[0u][2u],mat[0u][3u],
            mat[1u][0u],mat[1u][1u],mat[1u][2u],mat[1u][3u],
            mat[2u][0u],mat[2u][1u],mat[2u][2u],mat[2u][3u],
            mat[3u][0u],mat[3u][1u],mat[3u][2u],mat[3u][3u]
            );
}
void edk::shd::Data::setMatrix4f(edk::float32 f11,edk::float32 f12,edk::float32 f13,edk::float32 f14,
                                 edk::float32 f21,edk::float32 f22,edk::float32 f23,edk::float32 f24,
                                 edk::float32 f31,edk::float32 f32,edk::float32 f33,edk::float32 f34,
                                 edk::float32 f41,edk::float32 f42,edk::float32 f43,edk::float32 f44
                                 ){
    this->mat[ 0u] = f11;
    this->mat[ 1u] = f12;
    this->mat[ 2u] = f13;
    this->mat[ 3u] = f14;
    this->mat[ 4u] = f21;
    this->mat[ 5u] = f22;
    this->mat[ 6u] = f23;
    this->mat[ 7u] = f24;
    this->mat[ 8u] = f31;
    this->mat[ 9u] = f32;
    this->mat[10u] = f33;
    this->mat[11u] = f34;
    this->mat[12u] = f41;
    this->mat[13u] = f42;
    this->mat[14u] = f43;
    this->mat[15u] = f44;
    this->useMatrix = edk::shd::matrix4;
}

//Send the data to the shader
bool edk::shd::Data::updateData(){
    //test the ID
    if(this->ID!=-1){
        switch(this->useMatrix){
        case edk::shd::matrix1:
            //then test witch data are using
            if(this->useData){
                //are using ints
                switch(this->ints.size()){
                case 1u:
                    //
                    edk::GU_GLSL::guData1i32(this->ID,this->ints.get(0u));
                    break;
                case 2u:
                    //
                    edk::GU_GLSL::guData2i32(this->ID,this->ints.get(0u),this->ints.get(1u));
                    break;
                case 3u:
                    //
                    edk::GU_GLSL::guData3i32(this->ID,this->ints.get(0u),this->ints.get(1u),this->ints.get(2u));
                    break;
                case 4u:
                    //
                    edk::GU_GLSL::guData4i32(this->ID,this->ints.get(0u),this->ints.get(1u),this->ints.get(2u),this->ints.get(3u));
                    break;
                }
                return true;
            }
            else{
                //are using floats
                switch(this->floats.size()){
                case 1u:
                    //
                    edk::GU_GLSL::guData1f32(this->ID,this->floats.get(0u));
                    break;
                case 2u:
                    //
                    edk::GU_GLSL::guData2f32(this->ID,this->floats.get(0u),this->floats.get(1u));
                    break;
                case 3u:
                    //
                    edk::GU_GLSL::guData3f32(this->ID,this->floats.get(0u),this->floats.get(1u),this->floats.get(2u));
                    break;
                case 4u:
                    //
                    edk::GU_GLSL::guData4f32(this->ID,this->floats.get(0u),this->floats.get(1u),this->floats.get(2u),this->floats.get(3u));
                    break;
                }
                return true;
            }
            break;
        case edk::shd::matrix2:
            edk::GU_GLSL::guMatrix2f32(this->ID,(edk::float32*)this->mat);
            break;
        case edk::shd::matrix3:
            edk::GU_GLSL::guMatrix3f32(this->ID,(edk::float32*)this->mat);
            break;
        case edk::shd::matrix4:
            edk::GU_GLSL::guMatrix4f32(this->ID,(edk::float32*)this->mat);
            break;
        }
    }
    //else return false
    return false;
}
