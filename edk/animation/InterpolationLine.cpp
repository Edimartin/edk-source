#include "InterpolationLine.h"

/*
Library C++ InterpolationLine - Animate one line interpolation in Edk Game Engine
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
#warning "            Inside InterpolationLine.cpp"
#endif

edk::animation::InterpolationLine::InterpolationLine()
{
    this->startAlloc=this->endAlloc=false;
    this->start=this->end=NULL;
    //
    this->allocStart();
    this->allocEnd();
}

edk::animation::InterpolationLine::~InterpolationLine()
{
    this->deleteFrames();
}

//calculate de distance
void edk::animation::InterpolationLine::updateDistance(){
    //
    this->distance = this->end->second - this->start->second;
}

//write to XML
bool edk::animation::InterpolationLine::writeToXMLStart(edk::XML* xml,edk::uint32 frameID){
    return this->start->writeToXML(xml,frameID);
}
bool edk::animation::InterpolationLine::writeToXMLEnd(edk::XML* xml,edk::uint32 frameID){
    return this->end->writeToXML(xml,frameID);
}

//alloc frames
bool edk::animation::InterpolationLine::allocStart(){
    //delete the start
    this->deleteStart();
    if((this->start=this->useNewFrame(4u,0,0,0,0))){
        if(this->start->retainObject(&this->start)){
            //set using startAlloc
            this->startAlloc=true;
            //
            return true;
        }
        else{
            //Erro to retainStart
            delete this->start;
            this->start=NULL;
        }
    }
    else{
        //Error to allocStart
    }
    return false;
}
bool edk::animation::InterpolationLine::allocEnd(){
    //delete the end
    this->deleteEnd();
    if((this->end=this->useNewFrame(4u,0,0,0,0))){
        if(this->end->retainObject(&this->end)){
            //set using startAlloc
            this->endAlloc=true;
            //
            return true;
        }
        else{
            //Erro to retainEnd
            delete this->end;
            this->end=NULL;
        }
    }
    else{
        //Error to allocEnd
    }
    return false;
}
//set new
edk::animation::Frame* edk::animation::InterpolationLine::useNewFrame(edk::uint8,edk::float32 values,...){
    edk::float32* value = &values;
//    if(count) value = &values;
//    else value = &values;
    return new edk::animation::Frame(value[0]);
}

//delete the frames
void edk::animation::InterpolationLine::deleteStart(){
    //
    if(this->start){
        //release the object
        this->start->releaseObject(&this->start);
    }
    this->start=NULL;
    //set false using alloc
    this->startAlloc=false;
}
void edk::animation::InterpolationLine::deleteEnd(){
    //
    if(this->end){
        //release the object
        this->end->releaseObject(&this->end);
    }
    this->end=NULL;
    //set false using alloc
    this->endAlloc=false;
}
void edk::animation::InterpolationLine::deleteFrames(){
    //
    this->deleteStart();
    this->deleteEnd();
}

//switch the frames
void edk::animation::InterpolationLine::switchFrames(){
    //first save the frames
    edk::animation::Frame* tempStart=NULL;
    this->start->retainObject(&tempStart);
    edk::animation::Frame* tempEnd=NULL;
    this->end->retainObject(&tempEnd);
    //Release the start and end
    this->start->releaseObject(&this->start);
    this->end->releaseObject(&this->end);
    //then retain the new objects
    tempStart->retainObject(&this->end);
    tempEnd->retainObject(&this->start);
    //release the temps
    tempStart->releaseObject(&tempStart);
    tempEnd->releaseObject(&tempEnd);

    //at the end. switch the alloc
    bool temp = this->startAlloc;
    this->startAlloc=this->endAlloc;
    this->endAlloc=temp;
}


//SETERS
//set the start frame
bool edk::animation::InterpolationLine::setStart(edk::animation::Frame* frame){
    //First need to test if the new frame exist
    if(frame){
        //then he can use the frame

        //delete the last frame to receive a new pointer
        this->deleteStart();

        //retain the frame
        frame->retainObject(&this->start);

        //test if the end is < then start
        if(*this->end<*this->start){
            //then switch the frames
            this->switchFrames();
        }

        //update the distance
        this->updateDistance();
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine::setStart(edk::float32 second){
    //test if are using a frame alloc
    if(this->startAlloc){
        //
        this->start->second=second;
        //test if the end is < then start
        if(*this->end<*this->start){
            //then switch the frames
            this->switchFrames();
        }
        //update the distance
        this->updateDistance();
        //return true
        return true;
    }
    else{
        //else create a new frame and add to the start
        return this->setStart(this->useNewFrame(1u,second));
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine::setStartNoFilter(edk::float32 second){
    //test if are using a frame alloc
    if(this->startAlloc){
        //
        this->start->second=second;
        //remove filter
        /*
        if(*this->end<*this->start){
            //then switch the frames
            this->switchFrames();
        }
        //update the distance
        this->updateDistance();
        */
        //return true
        return true;
    }
    else{
        //else create a new frame and add to the start
        return this->setStart(this->useNewFrame(1u,second));
    }
    //else return false
    return false;
}

bool edk::animation::InterpolationLine::setEnd(edk::animation::Frame* frame){
    //First need to test if the new frame exist
    if(frame){
        //then he can use the frame

        //delete the frame
        this->deleteEnd();

        //retain the frame
        frame->retainObject(&this->end);

        //test if the end is < then start
        if(*this->end<*this->start){
            //then switch the frames
            this->switchFrames();
        }
        //update the distance
        this->updateDistance();

        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine::setEnd(edk::float32 second){
    //test if are using a frame alloc
    if(this->endAlloc){
        //
        this->end->second=second;
        //test if the end is < then start
        if(*this->end<*this->start){
            //then switch the frames
            this->switchFrames();
        }
        //update the distance
        this->updateDistance();
        //return true
        return true;
    }
    else{
        //else create a new frame and add to the start
        return this->setEnd(this->useNewFrame(1u,second));
    }
    return false;
}
bool edk::animation::InterpolationLine::setEndNoFilter(edk::float32 second){
    //test if are using a frame alloc
    if(this->endAlloc){
        //
        this->end->second=second;
        //remove the filter
        /*
        if(*this->end<*this->start){
            //then switch the frames
            this->switchFrames();
        }
        //update the distance
        this->updateDistance();
*/
        //return true
        return true;
    }
    else{
        //else create a new frame and add to the start
        return this->setEnd(this->useNewFrame(1u,second));
    }
    return false;
}


//GETERS
//return the start
edk::animation::Frame edk::animation::InterpolationLine::getStart(){
    //
    this->start->cantDestruct();
    return *this->start;
}
//return if create the start
bool edk::animation::InterpolationLine::getCreateStart(){
    return this->startAlloc;
}
//return the end
edk::animation::Frame edk::animation::InterpolationLine::getEnd(){
    //
    this->end->cantDestruct();
    return *this->end;
}
//return if create the end
bool edk::animation::InterpolationLine::getCreateEnd(){
    return this->endAlloc;
}
//use the start frame in another interpolation
bool edk::animation::InterpolationLine::useStartInStart(edk::animation::InterpolationLine* get){
    //test if have a get
    if(get){
        //then set the frame
        return get->setStart(this->start);
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine::useStartInEnd(edk::animation::InterpolationLine* get){
    //test if have a get
    if(get){
        //then set the frame
        return get->setEnd(this->start);
    }
    //else return false
    return false;
}
//use the start frame in another interpolation
bool edk::animation::InterpolationLine::useEndInEnd(edk::animation::InterpolationLine* get){
    //test if have a get
    if(get){
        //then set the frame
        return get->setEnd(this->end);
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine::useEndInStart(edk::animation::InterpolationLine* get){
    //test if have a get
    if(get){
        //then set the frame
        return get->setStart(this->end);
    }
    //else return false
    return false;
}
