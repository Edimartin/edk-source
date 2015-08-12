#include "ViewController.h"

/*
Library C++ edkController - Render other views inside this view in Edk Game Engine
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
#warning "            Inside ViewController.cpp"
#endif

namespace edk {
//

ViewController::ViewController(){
    //
    this->frame = edk::rectf32(0.f,0.f,0.f,0.f);
    this->setRectInside = false;
}

ViewController::ViewController(rectf32 frame){
    //
    this->frame=frame;
    this->setRectInside = false;
}

ViewController::~ViewController(){
    //
    this->frame = edk::rectf32(0.f,0.f,0.f,0.f);
}



bool ViewController::addSubview(edk::View *addView){
    //test if the view exist
    if(addView){
        //now he can add the view
        edk::uint32 temp = this->nexts.size();

        //Add the new view
        this->nexts.pushBack(addView);

        //test if have added the view
        if(this->nexts.size()>temp){
            //load the view
            if(this->setRectInside){
                this->rectInside = edk::rectf32(
                            rectTemp.origin.x + this->borderSize,
                            rectTemp.origin.y,
                            rectTemp.size.width - this->borderSize,
                            rectTemp.size.height - this->borderSize
                            );
                addView->load(this->rectInside);
            }
            else{
                addView->load(this->frame);
            }
            //have added the view
            return true;
        }
    }
    //else return false
    return false;
}

uint32 ViewController::getCount(){
    //return the vector size
    return this->nexts.size();
}

View* ViewController::getSubview(edk::uint64 n){
    //test if the view exist
    if(n<this->nexts.size()){
        //then find the view
        return this->nexts[n];
    }
    //else return NULL
    return NULL;
}

uint32 ViewController::getSubviewId(edk::View *subView){
    //test if the view to find exist
    if(subView){
        //find the view
        for(edk::uint32 i=0u;i<this->nexts.size();i++){
            //test if the pointer is equal
            if(subView==this->nexts[i]){
                //foundIt. Return the pos in the vector
                return i;
            }
        }
    }
    //else return the viewSize+1u
    return this->nexts.size()+1u;
}

bool ViewController::haveSubview(edk::View *subView){
    //get the view ID
    if(this->getSubviewId(subView)<this->nexts.size()){
        //then return true
        return true;
    }
    //else return false
    return false;
}

//bring subView to front
bool ViewController::bringSubviewToSubviewFront(edk::View *subView1,edk::View *subView2){
    //
    return this->bringSubviewIDToIDFront(this->getSubviewId(subView1),this->getSubviewId(subView2));
}
bool ViewController::bringSubviewToIDFront(edk::View *subView,edk::uint32 newID){
    //
    return this->bringSubviewIDToIDFront(this->getSubviewId(subView),newID);
}
bool ViewController::bringSubviewIDToIDFront(edk::uint32 id,edk::uint32 newID){
    //test if the newId are on the front
    if(newID>id){
        //bring to front of the newID
        return this->nexts.bringPositionTo(id,newID+1u);
    }
    else{
        //bring to position of the newID
        return this->nexts.bringPositionTo(id,newID);
    }
    //else return false
    return false;
}
bool ViewController::bringSubviewToFront(edk::View *subView){
    //first find the subViewID
    return this-> bringSubviewIDToFront(this->getSubviewId(subView));
}
bool ViewController::bringSubviewIDToFront(edk::uint32 id){
    //
    if(this->nexts.size()){
        return this->bringSubviewIDToIDFront(id,this->nexts.size()-1u);
    }
    //else return false
    return false;
}
//move the subViews
bool ViewController::bringSubviewUp(edk::View* subView){
    //
    return this->bringSubviewIDUp(this->getSubviewId(subView));
}
bool ViewController::bringSubviewIDUp(edk::uint32 id){
    //test if the id can move up
    return this->nexts.bringPositionPlusOne(id);
}
bool ViewController::bringSubviewDown(edk::View* subView){
    //
    return this->bringSubviewIDDown(this->getSubviewId(subView));
}
bool ViewController::bringSubviewIDDown(edk::uint32 id){
    //
    return this->nexts.bringPositionMinusOne(id);
}
bool ViewController::bringSubviewUp(edk::View* subView,edk::uint32 count){
    //
    return this->bringSubviewIDUp(this->getSubviewId(subView),count);
}
bool ViewController::bringSubviewIDUp(edk::uint32 id,edk::uint32 count){
    //
    return this->bringSubviewIDToIDFront(id,id+count);
}
bool ViewController::bringSubviewDown(edk::View* subView,edk::uint32 count){
    //
    return this->bringSubviewIDDown(this->getSubviewId(subView),count);
}
bool ViewController::bringSubviewIDDown(edk::uint32 id,edk::uint32 count){
    //test if the the count is les than id
    if(count<=id){
        return this->bringSubviewIDToIDFront(id,id-count);
    }
    //else return false
    return false;
}

//remove subView
bool ViewController::removeSubview(edk::View *subView){
    if(subView){
        //get subView ID
        edk::uint32 id = this->getSubviewId(subView);
        if(id<this->nexts.size()){
            //set the subview to NULL
            this->nexts.set((edk::uint32)id,(View*)NULL);
            //then remove the same
            this->nexts.remove((edk::uint32)id);

            //run unload
            subView->unload();
            return true;
        }
    }
    return false;
}

void ViewController::draw(edk::rectf32 outsideViewOrigin){
    //First draw calculting the rectTemp
    edk::View::draw(outsideViewOrigin);
    //Then call the nextView

    //test if this view is not hided
    if(!this->hide){
        //save the rectInside
        this->rectInside = edk::rectf32(
                    rectTemp.origin.x + this->borderSize,
                    rectTemp.origin.y,
                    rectTemp.size.width - this->borderSize,
                    rectTemp.size.height - this->borderSize
                    );
        this->setRectInside = true;
        //Then draw the others
        for(edk::uint32 i=0u;i<this->nexts.size();i++){
            //test if the view exist
            if(this->nexts[i]){
                //then draw using the view in GU. no in EDK
                this->nexts[i]->draw(
                            this->rectInside
                            );
            }
        }
    }
}

//contact in the view
bool ViewController::contact(edk::vec2f32 point,edk::uint8 state,edk::vector::Stack<edk::uint32>* buttons){
    //return
    bool ret=false;
    //first test the contact
    if(edk::View::contact(point,state,buttons)){
        //
    }
    //set the ViewFunction to run the eventFunctions
    for(edk::uint32 i=this->nexts.size();i>0u;i--){
        //test if the view exist
        if(this->nexts[i-1u]){
            //test if not get the contact
            if(!ret){
                //test the contact
                if(this->nexts[i-1u]->contact(point - this->animatedFrame.origin,state,buttons)){
                    //
                    ret=true;
                }
            }
            else{
                //test if it's a button
                if(this->nexts[i-1u]->isButton()){
                    //then remove the contact by testing it
                    this->nexts[i-1u]->contact(point - this->animatedFrame.origin,state,buttons);
                }
            }
        }
    }
    //else return false
    return ret;
}

//return false to isLeaf
bool ViewController::isLeaf(){
    //
    return false;
}

} /* End of namespace edk */
