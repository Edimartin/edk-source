#include "InterpolationLine.h"

/*
Library C++ InterpolationLine - Animate one line interpolation in Edk Game Engine
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
#pragma message "            Inside InterpolationLine.cpp"
#endif

edk::animation::InterpolationLine::InterpolationLine(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::animation::InterpolationLine::~InterpolationLine(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->deleteFrames();edkEnd();
    }
}

void edk::animation::InterpolationLine::Constructor(bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;
        this->startAlloc=this->endAlloc=false;edkEnd();
        this->start=this->end=NULL;edkEnd();
        //
        this->allocStart();edkEnd();
        this->allocEnd();edkEnd();
        this->active=false;edkEnd();
    }
}

//calculate de distance
void edk::animation::InterpolationLine::updateDistance(){
    //
    this->distance = this->end->second - this->start->second;edkEnd();
}

//write to XML
bool edk::animation::InterpolationLine::writeToXMLStart(edk::XML* xml,edk::uint32 frameID){
    return this->start->writeToXML(xml,frameID);edkEnd();
}
bool edk::animation::InterpolationLine::writeToXMLEnd(edk::XML* xml,edk::uint32 frameID){
    return this->end->writeToXML(xml,frameID);edkEnd();
}

//alloc frames
bool edk::animation::InterpolationLine::allocStart(){
    //delete the start
    this->deleteStart();edkEnd();
    if((this->start=this->useNewFrame(4u,0,0,0,0))){
        if(this->start->retainObject(&this->start)){
            //set using startAlloc
            this->startAlloc=true;edkEnd();
            //
            return true;
        }
        else{
            //Erro to retainStart
            delete this->start;edkEnd();
            this->start=NULL;edkEnd();
        }
    }
    else{
        //Error to allocStart
    }
    return false;
}
bool edk::animation::InterpolationLine::allocEnd(){
    //delete the end
    this->deleteEnd();edkEnd();
    if((this->end=this->useNewFrame(4u,0,0,0,0))){
        if(this->end->retainObject(&this->end)){
            //set using startAlloc
            this->endAlloc=true;edkEnd();
            //
            return true;
        }
        else{
            //Erro to retainEnd
            delete this->end;edkEnd();
            this->end=NULL;edkEnd();
        }
    }
    else{
        //Error to allocEnd
    }
    return false;
}
//set new
edk::animation::Frame* edk::animation::InterpolationLine::useNewFrame(edk::uint8,edk::float32 values,...){
    edk::float32* value = &values;edkEnd();
    //    if(count) value = &values;edkEnd();
    //    else value = &values;edkEnd();
    return new edk::animation::Frame(value[0]);edkEnd();
}

//delete the frames
void edk::animation::InterpolationLine::deleteStart(){
    //
    if(this->start){
        //release the object
        this->start->releaseObject(&this->start);edkEnd();
    }
    this->start=NULL;edkEnd();
    //set false using alloc
    this->startAlloc=false;edkEnd();
}
void edk::animation::InterpolationLine::deleteEnd(){
    //
    if(this->end){
        //release the object
        this->end->releaseObject(&this->end);edkEnd();
    }
    this->end=NULL;edkEnd();
    //set false using alloc
    this->endAlloc=false;edkEnd();
}
void edk::animation::InterpolationLine::deleteFrames(){
    //
    this->deleteStart();edkEnd();
    this->deleteEnd();edkEnd();
}

//switch the frames
void edk::animation::InterpolationLine::switchFrames(){
    //first save the frames
    edk::animation::Frame* tempStart=NULL;edkEnd();
    this->start->retainObject(&tempStart);edkEnd();
    edk::animation::Frame* tempEnd=NULL;edkEnd();
    this->end->retainObject(&tempEnd);edkEnd();
    //Release the start and end
    this->start->releaseObject(&this->start);edkEnd();
    this->end->releaseObject(&this->end);edkEnd();
    //then retain the new objects
    tempStart->retainObject(&this->end);edkEnd();
    tempEnd->retainObject(&this->start);edkEnd();
    //release the temps
    tempStart->releaseObject(&tempStart);edkEnd();
    tempEnd->releaseObject(&tempEnd);edkEnd();

    //at the end. switch the alloc
    bool temp = this->startAlloc;edkEnd();
    this->startAlloc=this->endAlloc;edkEnd();
    this->endAlloc=temp;edkEnd();
}


//SETERS
//set the start frame
bool edk::animation::InterpolationLine::setStart(edk::animation::Frame* frame){
    //First need to test if the new frame exist
    if(frame && this->start && this->end){
        //then he can use the frame

        //delete the last frame to receive a new pointer
        this->deleteStart();edkEnd();

        //retain the frame
        frame->retainObject(&this->start);edkEnd();

        //test if the end is < then start
        //if(*this->end<*this->start){
        if(this->end->smallerThan(this->start)){
            //then switch the frames
            this->switchFrames();edkEnd();
        }

        //update the distance
        this->updateDistance();edkEnd();
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
        this->start->second=second;edkEnd();
        //test if the end is < then start
        //if(*this->end<*this->start){
        if(this->end->smallerThan(this->start)){
            //then switch the frames
            this->switchFrames();edkEnd();
        }
        //update the distance
        this->updateDistance();edkEnd();
        //return true
        return true;
    }
    else{
        //else create a new frame and add to the start
        return this->setStart(this->useNewFrame(1u,second));edkEnd();
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine::setStartNoFilter(edk::float32 second){
    //test if are using a frame alloc
    if(this->startAlloc){
        //
        this->start->second=second;edkEnd();
        //remove filter
        /*
        if(*this->end<*this->start){
            //then switch the frames
            this->switchFrames();edkEnd();
        }
        //update the distance
        this->updateDistance();edkEnd();
        */
        //return true
        return true;
    }
    else{
        //else create a new frame and add to the start
        return this->setStart(this->useNewFrame(1u,second));edkEnd();
    }
    //else return false
    return false;
}

bool edk::animation::InterpolationLine::setEnd(edk::animation::Frame* frame){
    //First need to test if the new frame exist
    if(frame && this->end){
        //then he can use the frame

        //delete the frame
        this->deleteEnd();edkEnd();

        //retain the frame
        frame->retainObject(&this->end);edkEnd();

        //test if the end is < then start
        //if(*this->end<*this->start){
        if(this->end->smallerThan(this->start)){
            //then switch the frames
            this->switchFrames();edkEnd();
        }
        //update the distance
        this->updateDistance();edkEnd();

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
        this->end->second=second;edkEnd();
        //test if the end is < then start
        //if(*this->end<*this->start){
        if(this->end->smallerThan(this->start)){
            //then switch the frames
            this->switchFrames();edkEnd();
        }
        //update the distance
        this->updateDistance();edkEnd();
        //return true
        return true;
    }
    else{
        //else create a new frame and add to the start
        return this->setEnd(this->useNewFrame(1u,second));edkEnd();
    }
    return false;
}
bool edk::animation::InterpolationLine::setEndNoFilter(edk::float32 second){
    //test if are using a frame alloc
    if(this->endAlloc){
        //
        this->end->second=second;edkEnd();
        //remove the filter
        /*
        if(*this->end<*this->start){
            //then switch the frames
            this->switchFrames();edkEnd();
        }
        //update the distance
        this->updateDistance();edkEnd();
*/
        //return true
        return true;
    }
    else{
        //else create a new frame and add to the start
        return this->setEnd(this->useNewFrame(1u,second));edkEnd();
    }
    return false;
}


//GETERS
//return the start
edk::animation::Frame edk::animation::InterpolationLine::getStart(){
    //
    this->start->cantDestruct();edkEnd();
    return *this->start;edkEnd();
}
//return if create the start
bool edk::animation::InterpolationLine::getCreateStart(){
    return this->startAlloc;edkEnd();
}
//return the end
edk::animation::Frame edk::animation::InterpolationLine::getEnd(){
    //
    this->end->cantDestruct();edkEnd();
    return *this->end;edkEnd();
}
//return if create the end
bool edk::animation::InterpolationLine::getCreateEnd(){
    return this->endAlloc;edkEnd();
}
//use the start frame in another interpolation
bool edk::animation::InterpolationLine::useStartInStart(edk::animation::InterpolationLine* get){
    //test if have a get
    if(get){
        //then set the frame
        return get->setStart(this->start);edkEnd();
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine::useStartInEnd(edk::animation::InterpolationLine* get){
    //test if have a get
    if(get){
        //then set the frame
        return get->setEnd(this->start);edkEnd();
    }
    //else return false
    return false;
}
//use the start frame in another interpolation
bool edk::animation::InterpolationLine::useEndInEnd(edk::animation::InterpolationLine* get){
    //test if have a get
    if(get){
        //then set the frame
        return get->setEnd(this->end);edkEnd();
    }
    //else return false
    return false;
}
bool edk::animation::InterpolationLine::useEndInStart(edk::animation::InterpolationLine* get){
    //test if have a get
    if(get){
        //then set the frame
        return get->setStart(this->end);edkEnd();
    }
    //else return false
    return false;
}
