#include "Data.h"

/*
Library DATA - Control datas in the edk shaders
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
#warning "            Inside Data.cpp"
#endif

edk::shd::Data::Data()
{
    //set the float
    this->ints.clean(4u);
    this->floats.clean(4u);
    this->ID=-1u;
}

edk::shd::Data::~Data()
{
    //dtor
    this->cleanInts();
    this->cleanFloats();
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
}

//Send the data to the shader
bool edk::shd::Data::updateData(){
    //test the ID
    if(this->ID!=-1){
        //then test witch data are using
        if(this->useData){
            //are using ints
            switch(this->ints.size()){
                case 1u:
                    //
                    edk::GU_GLSL::guData1i32(this->ID,this->ints[0u]);
                    break;
                case 2u:
                    //
                    edk::GU_GLSL::guData2i32(this->ID,this->ints[0u],this->ints[1u]);
                    break;
                case 3u:
                    //
                    edk::GU_GLSL::guData3i32(this->ID,this->ints[0u],this->ints[1u],this->ints[2u]);
                    break;
                case 4u:
                    //
                    edk::GU_GLSL::guData4i32(this->ID,this->ints[0u],this->ints[1u],this->ints[2u],this->ints[3u]);
                    break;
            }
            return true;
        }
        else{
            //are using floats
            switch(this->floats.size()){
                case 1u:
                    //
                    edk::GU_GLSL::guData1f32(this->ID,this->floats[0]);
                    break;
                case 2u:
                    //
                    edk::GU_GLSL::guData2f32(this->ID,this->floats[0u],this->floats[1u]);
                    break;
                case 3u:
                    //
                    edk::GU_GLSL::guData3f32(this->ID,this->floats[0u],this->floats[1u],this->floats[2u]);
                    break;
                case 4u:
                    //
                    edk::GU_GLSL::guData4f32(this->ID,this->floats[0u],this->floats[1u],this->floats[2u],this->floats[3u]);
                    break;
            }
            return true;
        }
    }
    //else return false
    return false;
}
