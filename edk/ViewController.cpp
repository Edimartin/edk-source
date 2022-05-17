#include "ViewController.h"

/*
Library C++ edkController - Render other views inside this view in Edk Game Engine
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

//draw the view inside in a separated function to viewTexture draw other views inside
void ViewController::drawViewInside(){
    //test if this view is not hided
    if(!this->hide){
        //save the rectInside
        this->rectInside = edk::rectf32(
                    rectTemp.origin.x + this->borderTemp,
                    rectTemp.origin.y,
                    rectTemp.size.width - this->borderTemp,
                    rectTemp.size.height - this->borderTemp
                    );
        this->setRectInside = true;
        //Then draw the others
        for(edk::uint32 i=0u;i<this->nexts.size();i++){
            //test if the view exist
            if(this->nexts.havePos(i)){
                //then draw using the view in GU. no in EDK
                this->nexts[i]->runDraw(
                            this->rectInside
                            );
            }
        }
    }
}
//run the pause function
void ViewController::runPause(){
    //test if this view is not hided
    if(!this->hide){
        //pause this view
        edk::View::runPause();
        //Then pause the others
        for(edk::uint32 i=0u;i<this->nexts.size();i++){
            //test if the view exist
            if(this->nexts.havePos(i)){
                //then pause the view
                this->nexts[i]->runPause();
            }
        }
    }
}
//run the unpause function
void ViewController::runUnpause(){
    //test if this view is not hided
    if(!this->hide){
        //pause this view
        edk::View::runUnpause();
        //Then unpause the others
        for(edk::uint32 i=0u;i<this->nexts.size();i++){
            //test if the view exist
            if(this->nexts.havePos(i)){
                //then unpause the view
                this->nexts[i]->runUnpause();
            }
        }
    }
}



bool ViewController::addSubview(edk::View *addView){
    //test if the view exist
    if(addView){
        if(!this->haveSubview(addView)){
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
                    addView->runLoad(this->rectInside);
                }
                else{
                    addView->runLoad(this->frame);
                }
                //have added the view
                return true;
            }
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
    if(this->nexts.havePos(n)){
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
            if(this->nexts.havePos(i)){
                if(subView==this->nexts[i]){
                    //foundIt. Return the pos in the vector
                    return i;
                }
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
        return this->nexts.bringPositionTo(id,this->nexts.size()-1u);
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
        if(this->nexts.havePos(id)){
            this->nexts.bringPositionTo(id,this->nexts.size()-1u);
            //then remove the same
            this->nexts.remove(this->nexts.size()-1u);

            //remove the mouseInside
            this->mouseInside = false;
            //run unload
            subView->runUnload();
            return true;
        }
    }
    return false;
}
void ViewController::removeAllSubview(){
    edk::uint32 size  =this->nexts.size();
    edk::View *subView=NULL;
    for(edk::uint32 i=0u;i<size;i++){
        //run unload function in views
        if(this->nexts.havePos(i)){
            subView = this->nexts[i];
            if(subView){
                subView->runUnload();
            }
        }
    }
    this->nexts.clean();
}

void ViewController::draw(edk::rectf32 outsideViewOrigin){
    //First draw calculting the rectTemp
    edk::View::draw(outsideViewOrigin);
    //draw the view inside
    this->drawViewInside();
}

//contact in the view
bool ViewController::contact(edk::vec2f32 point,edk::uint8 state,edk::vector::Stack<edk::uint32>* buttons){
    //return
    bool ret=false;
    if(this->pointInside(point)){
        for(edk::uint32 i=this->nexts.size();i>0u;i--){
            //test if the view exist
            if(this->nexts.havePos(i-1u)){
                if(this->nexts[i-1u]){
                    //test the contact
                    if(ret){
                        this->nexts[i-1u]->contactRelease(point - this->animatedFrame.origin,state,buttons);
                    }
                    else{
                        if(this->nexts[i-1u]->contact(point - this->animatedFrame.origin,state,buttons)){
                            //
                            ret=true;
                        }
                        else{
                            this->nexts[i-1u]->contactRelease(point - this->animatedFrame.origin,state,buttons);
                        }
                    }
                }
            }
        }
        if(ret){
            this->edk::View::contactRelease(point,state,buttons);
        }
        else{
            ret = this->edk::View::contact(point,state,buttons);
        }
    }
    else{
        this->contactRelease(point,state,buttons);
    }
    //else return false
    return ret;
}
void ViewController::contactRelease(edk::vec2f32 point,edk::uint8 state,edk::vector::Stack<edk::uint32>* buttons){
    this->edk::View::contactRelease(point,state,buttons);
    for(edk::uint32 i=this->nexts.size();i>0u;i--){
        //test if the view exist
        if(this->nexts.havePos(i-1u)){
            if(this->nexts[i-1u]){
                //test the contact
                this->nexts[i-1u]->contactRelease(point - this->animatedFrame.origin,state,buttons);
            }
        }
    }
}

//return false to isLeaf
bool ViewController::isLeaf(){
    //
    return false;
}

} /* End of namespace edk */
