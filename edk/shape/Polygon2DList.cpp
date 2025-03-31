#include "Polygon2DList.h"

/*
Library Polygon2DList - Manage 2D Polygons in EDK Game Engine
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
#pragma message "            Inside Polygon2DList.cpp"
#endif

edk::shape::Polygon2DList::Polygon2DList(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::shape::Polygon2DList::~Polygon2DList(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        //clean the polygons
        this->cleanPolygons();edkEnd();
    }
}

void edk::shape::Polygon2DList::Constructor(bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;

        this->polygons.Constructor();edkEnd();

        //clean the selected
        this->freeSelected();edkEnd();

        this->tempP.Constructor();
        this->tempP.setTranslate(0.f,0.f);
        this->tempP.setScale(1.f,1.f);
        this->tempP.setAngle(0.f);
        this->tempP.setVertexPosition(0u,0.f,0.f);
        this->tempP.setVertexPosition(1u,1.f,1.f);
    }
}

//Set polygons color
bool edk::shape::Polygon2DList::setPolygonsColor(edk::color4f32 color){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon2D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.get(i);edkEnd();
            if(polygon){
                polygon->setPolygonColor(color);edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon2DList::setPolygonsColor(edk::color3f32 color){
    return setPolygonsColor(color.r,color.g,color.b);edkEnd();
}
bool edk::shape::Polygon2DList::setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon2D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.get(i);edkEnd();
            if(polygon){
                polygon->setPolygonColor(r,g,b);edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon2DList::setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon2D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.get(i);edkEnd();
            if(polygon){
                polygon->setPolygonColor(r,g,b,a);edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon2DList::setPolygonsColorR(edk::float32 r){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon2D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.get(i);edkEnd();
            if(polygon){
                polygon->setPolygonColorR(r);edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon2DList::setPolygonsColorG(edk::float32 g){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon2D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.get(i);edkEnd();
            if(polygon){
                polygon->setPolygonColorG(g);edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon2DList::setPolygonsColorB(edk::float32 b){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon2D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.get(i);edkEnd();
            if(polygon){
                polygon->setPolygonColorB(b);edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon2DList::setPolygonsColorA(edk::float32 a){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon2D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.get(i);edkEnd();
            if(polygon){
                polygon->setPolygonColorA(a);edkEnd();
            }
        }
        return true;
    }
    return false;
}
//set physics
bool edk::shape::Polygon2DList::setPolygonDensity(edk::uint32 position,edk::float32 density){
    if(this->polygons.havePos(position)){
        this->polygons.get(position)->setDensity(density);edkEnd();
        return true;
    }
    return false;
}
void edk::shape::Polygon2DList::setDensity(edk::float32 density){
    edk::uint32 size = this->polygons.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->setDensity(density);edkEnd();
        }
    }
}
bool edk::shape::Polygon2DList::setPolygonFriction(edk::uint32 position,edk::float32 friction){
    if(this->polygons.havePos(position)){
        this->polygons.get(position)->setFriction(friction);edkEnd();
        return true;
    }
    return false;
}
void edk::shape::Polygon2DList::setFriction(edk::float32 friction){
    edk::uint32 size = this->polygons.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->setFriction(friction);edkEnd();
        }
    }
}
bool edk::shape::Polygon2DList::setPolygonRestitution(edk::uint32 position,edk::float32 restitution){
    if(this->polygons.havePos(position)){
        this->polygons.get(position)->setRestitution(restitution);edkEnd();
        return true;
    }
    return false;
}
void edk::shape::Polygon2DList::setRestitution(edk::float32 restitution){
    edk::uint32 size = this->polygons.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->setRestitution(restitution);edkEnd();
        }
    }
}
//getPhysics
edk::float32 edk::shape::Polygon2DList::getPolygonDensity(edk::uint32 position){
    if(this->polygons.havePos(position)){
        return this->polygons.get(position)->getDensity();edkEnd();
    }
    //return initial value
    return 1.f;edkEnd();
}
edk::float32 edk::shape::Polygon2DList::getPolygonFriction(edk::uint32 position){
    if(this->polygons.havePos(position)){
        return this->polygons.get(position)->getFriction();edkEnd();
    }
    //return initial value
    return 0.f;
}
edk::float32 edk::shape::Polygon2DList::getPolygonRestitution(edk::uint32 position){
    if(this->polygons.havePos(position)){
        return this->polygons.get(position)->getRestitution();edkEnd();
    }
    //return initial value
    return 0.f;
}

//function to calculate boundingBox
bool edk::shape::Polygon2DList::calculateBoundingBox(edk::rectf32* rectangle,edk::vector::Matrixf32<3u,3u>* transformMat){
    if(rectangle && transformMat){
        edk::uint32 size = this->polygons.size();edkEnd();
        if(size){
            //copy the first polygon
            if(this->polygons.havePos(0u)){
                *rectangle = this->polygons.get(0u)->generateBoundingBox(transformMat);edkEnd();
                //draw the polygons
                for(edk::uint32 i=1u;i<size;i++){
                    if(this->polygons.havePos(i)){
                        this->polygons.get(i)->calculateBoundingBox(rectangle,transformMat);edkEnd();
                    }
                }
                return true;
            }
        }
    }
    return false;
}
edk::rectf32 edk::shape::Polygon2DList::generateBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::rectf32 ret;edkEnd();
    if(transformMat){
        edk::uint32 size = this->polygons.size();edkEnd();
        if(size){
            //copy the first polygon
            if(this->polygons.havePos(0u)){
                ret = this->polygons.get(0u)->generateBoundingBox(transformMat);edkEnd();
                //draw the polygons
                for(edk::uint32 i=1u;i<size;i++){
                    if(this->polygons.havePos(i)){
                        this->polygons.get(i)->calculateBoundingBox(&ret,transformMat);edkEnd();
                    }
                }
            }
        }
    }
    return ret;
}
bool edk::shape::Polygon2DList::calculateBoundingPoint(edk::vec2f32 point,edk::vec2f32* dest,edk::vector::Matrixf32<3u,3u>* transformMat){
    if(dest && transformMat){
        this->tempP.setVertexPosition(0u,point);
        return this->tempP.calculateBoundingPoint(dest,transformMat);
    }
    return false;
}
edk::vec2f32 edk::shape::Polygon2DList::generateBoundingPoint(edk::vec2f32 point,edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::vec2f32 ret;edkEnd();
    if(transformMat){
        this->tempP.setVertexPosition(0u,point);
        ret = this->tempP.generateBoundingPoint(transformMat);
    }
    return ret;
}
//function to calculate boundingBox from polygon positions
bool edk::shape::Polygon2DList::calculateBoundingBoxFromPolygons(edk::rectf32* rectangle,
                                                                 edk::vector::Matrixf32<3u,3u>* transformMat,
                                                                 edk::uint32 lenght,
                                                                 edk::uint32* positions
                                                                 ){
    if(rectangle && transformMat && positions){
        edk::uint32 size = this->polygons.size();edkEnd();
        if(size && lenght){
            edk::uint32 value = positions[0u];
            //copy the first polygon
            if(this->polygons.havePos(value)){
                *rectangle = this->polygons.get(value)->generateBoundingBox(transformMat);edkEnd();
                for(edk::uint32 i=1u;i<lenght;i++){
                    value = positions[i];
                    if(this->polygons.havePos(value)){
                        this->polygons.get(value)->calculateBoundingBox(rectangle,transformMat);edkEnd();
                    }
                }
                return true;
            }
        }
    }
    return false;
}
edk::rectf32 edk::shape::Polygon2DList::generateBoundingBoxFromPolygons(edk::vector::Matrixf32<3u,3u>* transformMat,
                                                                        edk::uint32 lenght,
                                                                        edk::uint32* positions
                                                                        ){
    edk::rectf32 ret;edkEnd();
    if(transformMat && positions){
        edk::uint32 size = this->polygons.size();edkEnd();
        if(size && lenght){
            edk::uint32 value = positions[0u];
            //copy the first polygon
            if(this->polygons.havePos(value)){
                ret = this->polygons.get(value)->generateBoundingBox(transformMat);edkEnd();
                for(edk::uint32 i=1u;i<lenght;i++){
                    value = positions[i];
                    if(this->polygons.havePos(value)){
                        this->polygons.get(value)->calculateBoundingBox(&ret,transformMat);edkEnd();
                    }
                }
            }
        }
    }
    return ret;
}
bool edk::shape::Polygon2DList::getWorldPolygon(edk::shape::Polygon2D* dest,edk::uint32 polygonPosition,edk::vector::Matrixf32<3u,3u>* transformMat){
    bool ret=false;edkEnd();
    if(dest){
        if(transformMat){
            //copy the first rectangle
            if(this->polygons.havePos(polygonPosition)){
                ret = this->polygons.get(polygonPosition)->getWorldPolygonClone(dest,transformMat);edkEnd();
            }
        }
    }
    return ret;
}

//generate world polygons from list into another list
bool edk::shape::Polygon2DList::generateWorldPolygons(edk::shape::Polygon2DList* dest,
                                                      edk::vector::Matrixf32<3u,3u>* transformMat
                                                      ){
    if(dest){
        if(transformMat){
            edk::uint32 size = this->getPolygonSize();
            if(size == dest->getPolygonSize()){
                for(edk::uint32 i=0u;i<size;i++){
                    if(!this->polygons.get(i)->getWorldPolygonCopy(dest->polygons.get(i),transformMat)){
                        return false;
                    }
                }
                return true;
            }
        }
    }
    return false;
}
bool edk::shape::Polygon2DList::generateWorldPolygons(edk::shape::Polygon2DList* dest,
                                                      edk::vector::Matrixf32<3u,3u>* transformMat,
                                                      edk::uint32 lenght,
                                                      edk::uint32* positions

                                                      ){
    if(dest){
        if(transformMat && positions){
            edk::uint32 size = this->getPolygonSize();
            if(size == dest->getPolygonSize()){
                edk::uint32 value=0u;
                for(edk::uint32 i=0u;i<lenght;i++){
                    value = positions[i];
                    if(!this->polygons.get(value)->getWorldPolygonCopy(dest->polygons.get(value),transformMat)){
                        return false;
                    }
                }
                return true;
            }
        }
    }
    return false;
}

//ADD
//add a polygon to the mesh
edk::uint32 edk::shape::Polygon2DList::addPolygon(edk::shape::Polygon2D polygon){
    //return
    edk::uint32 ret=0u;
    //polygon to be added
    edk::shape::Polygon2D* temp=NULL;edkEnd();
    //test if it's a line
    if(polygon.isLine()){
        temp=new edk::shape::Lines2D;edkEnd();
    }
    //test al much vertex have the polygon. Test if are a polygon or Rectangle.
    else if(polygon.getVertexCount()>=2u){
        if(polygon.getVertexCount()>2u){
            if(polygon.isCircle()){
                //it's circle

                //create the circle
                temp=(edk::shape::Polygon2D*)new edk::shape::Circle2D;edkEnd();
            }
            else{
                //it's a polygon

                //create the polygon
                temp=new edk::shape::Polygon2D;edkEnd();
            }
        }
        else{
            //it's a rectangle

            //create a rectangle
            temp=(edk::shape::Polygon2D*) new edk::shape::Rectangle2D;edkEnd();
        }
    }

    //test if have created the polygon
    if(temp){
        //copy the polygon
        //*temp = polygon;edkEnd();
        temp->cloneFrom(&polygon);edkEnd();

        //load the size of the polygons
        edk::uint32 size = this->polygons.size() - this->polygons.sizeRemoved();edkEnd();
        //add the polygon
        ret = this->polygons.pushBack(temp);edkEnd();
        //now compare the size in the list
        if(size<(this->polygons.size() - this->polygons.sizeRemoved())){
            //polygon added

            //select the ret
            this->selectPolygon(ret);edkEnd();
        }
        else{
            //polygon dont added. Delete the temp
            delete temp;edkEnd();
            //clean the ret
            ret=0u;
        }
    }
    //set temp NULL
    temp=NULL;edkEnd();

    //else return 0u;edkEnd();
    return ret;
}
//GETERS
//return the polygonSize
edk::uint32 edk::shape::Polygon2DList::getPolygonSize(){
    //
    return this->polygons.size();edkEnd();
}
//return true if have a polygon selected
bool edk::shape::Polygon2DList::haveSelected(){
    //
    return (bool) this->selected;edkEnd();
}

//test if have a polygon in a position
bool edk::shape::Polygon2DList::havePolygon(edk::uint32 position){
    return this->polygons.havePos(position);
}
//get the polygon in a position
edk::shape::Polygon2D edk::shape::Polygon2DList::getPolygon(edk::uint32 position){
    edk::shape::Polygon2D ret;
    if(this->havePolygon(position)){
        //get the polygon
        edk::shape::Polygon2D* temp = this->polygons.get(position);
        if(temp){
            //copy the polygon
            ret.cloneFrom(temp);
        }
    }
    return ret;
}
bool edk::shape::Polygon2DList::getPolygon(edk::uint32 position,edk::shape::Polygon2D* dest){
    if(dest && this->havePolygon(position)){
        //get the polygon
        edk::shape::Polygon2D* temp = this->polygons.get(position);
        if(temp){
            //copy the polygon
            return dest->cloneFrom(temp);
        }
    }
    return false;
}

//SET POLYGONS UV
//Set the polygonFrames setting in the vertexs
bool edk::shape::Polygon2DList::setPolygonUVFrames(edk::uint32 polygonID,edk::vec2ui32 frames){
    if(this->havePolygon(polygonID)){
        //get the polygon
        edk::shape::Polygon2D* temp = this->polygons.get(polygonID);
        if(temp){
            //return true
            return this->selected->setPolygonUVFrames(frames);edkEnd();
        }
    }
    return false;
}
bool edk::shape::Polygon2DList::setPolygonUVFrames(edk::uint32 polygonID,edk::uint32 x,edk::uint32 y){
    if(this->havePolygon(polygonID)){
        //get the polygon
        edk::shape::Polygon2D* temp = this->polygons.get(polygonID);
        if(temp){
            //return true
            return this->selected->setPolygonUVFrames(x,y);edkEnd();
        }
    }
    return false;
}
bool edk::shape::Polygon2DList::setPolygonUVFramesX(edk::uint32 polygonID,edk::uint32 x){
    if(this->havePolygon(polygonID)){
        //get the polygon
        edk::shape::Polygon2D* temp = this->polygons.get(polygonID);
        if(temp){
            //return true
            return this->selected->setPolygonUVFramesX(x);edkEnd();
        }
    }
    return false;
}
bool edk::shape::Polygon2DList::setPolygonUVFramesY(edk::uint32 polygonID,edk::uint32 y){
    if(this->havePolygon(polygonID)){
        //get the polygon
        edk::shape::Polygon2D* temp = this->polygons.get(polygonID);
        if(temp){
            //return true
            return this->selected->setPolygonUVFramesY(y);edkEnd();
        }
    }
    return false;
}
//Set the polygon frame
bool edk::shape::Polygon2DList::setPolygonUVFrame(edk::uint32 polygonID,edk::vec2ui32 frame){
    return this->usePolygonUVFrame(polygonID,frame);
}
bool edk::shape::Polygon2DList::setPolygonUVFrame(edk::uint32 polygonID,edk::uint32 x,edk::uint32 y){
    return this->usePolygonUVFrame(polygonID,x,y);
}
bool edk::shape::Polygon2DList::setPolygonUVFramePosition(edk::uint32 polygonID,edk::uint32 position){
    return this->usePolygonUVFramePosition(polygonID,position);
}
bool edk::shape::Polygon2DList::setPolygonUVFrameX(edk::uint32 polygonID,edk::uint32 x){
    return this->usePolygonUVFrameX(polygonID,x);
}
bool edk::shape::Polygon2DList::setPolygonUVFrameY(edk::uint32 polygonID,edk::uint32 y){
    return this->usePolygonUVFrameY(polygonID,y);
}
bool edk::shape::Polygon2DList::usePolygonUVFrame(edk::uint32 polygonID,edk::vec2ui32 frame){
    if(this->havePolygon(polygonID)){
        //get the polygon
        edk::shape::Polygon2D* temp = this->polygons.get(polygonID);
        if(temp){
            //return true
            temp->usePolygonUVFrame(frame);edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::shape::Polygon2DList::usePolygonUVFrame(edk::uint32 polygonID,edk::uint32 x,edk::uint32 y){
    return this->usePolygonUVFrame(polygonID,edk::vec2ui32 (x,y));edkEnd();
}
bool edk::shape::Polygon2DList::usePolygonUVFramePosition(edk::uint32 polygonID,edk::uint32 position){
    if(this->havePolygon(polygonID)){
        //get the polygon
        edk::shape::Polygon2D* temp = this->polygons.get(polygonID);
        if(temp){
            //return true
            temp->usePolygonUVFramePosition(position);edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::shape::Polygon2DList::usePolygonUVFrameX(edk::uint32 polygonID,edk::uint32 x){
    if(this->havePolygon(polygonID)){
        //get the polygon
        edk::shape::Polygon2D* temp = this->polygons.get(polygonID);
        if(temp){
            //return true
            temp->usePolygonUVFrameX(x);edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::shape::Polygon2DList::usePolygonUVFrameY(edk::uint32 polygonID,edk::uint32 y){
    if(this->havePolygon(polygonID)){
        //get the polygon
        edk::shape::Polygon2D* temp = this->polygons.get(polygonID);
        if(temp){
            //return true
            temp->usePolygonUVFrameY(y);edkEnd();
            return true;
        }
    }
    return false;
}
//Set the polygonsFrames setting in the vertexs
bool edk::shape::Polygon2DList::setPolygonsUVFrames(edk::vec2ui32 frames){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon2D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.get(i);edkEnd();
            if(polygon){
                polygon->setPolygonUVFrames(frames);edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon2DList::setPolygonsUVFrames(edk::uint32 x,edk::uint32 y){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon2D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.get(i);edkEnd();
            if(polygon){
                polygon->setPolygonUVFrames(x,y);edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon2DList::setPolygonsUVFramesX(edk::uint32 x){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon2D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.get(i);edkEnd();
            if(polygon){
                polygon->setPolygonUVFramesX(x);edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon2DList::setPolygonsUVFramesY(edk::uint32 y){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon2D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.get(i);edkEnd();
            if(polygon){
                polygon->setPolygonUVFramesY(y);edkEnd();
            }
        }
        return true;
    }
    return false;
}
//Set the polygons frame
bool edk::shape::Polygon2DList::setPolygonsUVFrame(edk::vec2ui32 frame){
    return this->usePolygonsUVFrame(frame);
}
bool edk::shape::Polygon2DList::setPolygonsUVFrame(edk::uint32 x,edk::uint32 y){
    return this->usePolygonsUVFrame(x,y);
}
bool edk::shape::Polygon2DList::setPolygonsUVFramePosition(edk::uint32 position){
    return this->usePolygonsUVFramePosition(position);
}
bool edk::shape::Polygon2DList::setPolygonsUVFrameX(edk::uint32 x){
    return this->usePolygonsUVFrameX(x);
}
bool edk::shape::Polygon2DList::setPolygonsUVFrameY(edk::uint32 y){
    return this->usePolygonsUVFrameY(y);
}
bool edk::shape::Polygon2DList::usePolygonsUVFrame(edk::vec2ui32 frame){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon2D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.get(i);edkEnd();
            if(polygon){
                polygon->usePolygonUVFrame(frame);edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon2DList::usePolygonsUVFrame(edk::uint32 x,edk::uint32 y){
    return this->usePolygonsUVFrame(edk::vec2ui32 (x,y));edkEnd();
}
bool edk::shape::Polygon2DList::usePolygonsUVFramePosition(edk::uint32 position){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon2D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.get(i);edkEnd();
            if(polygon){
                polygon->usePolygonUVFramePosition(position);edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon2DList::usePolygonsUVFrameX(edk::uint32 x){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon2D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.get(i);edkEnd();
            if(polygon){
                polygon->usePolygonUVFrameX(x);edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon2DList::usePolygonsUVFrameY(edk::uint32 y){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon2D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.get(i);edkEnd();
            if(polygon){
                polygon->usePolygonUVFrameY(y);edkEnd();
            }
        }
        return true;
    }
    return false;
}

//DELETE
//clean the polygons
void edk::shape::Polygon2DList::cleanPolygons(){
    this->freeSelected();edkEnd();
    edk::uint32 size = this->polygons.size();
    //remove all the polygons
    for(edk::uint32 i=size;i>0u;i--){
        //
        this->removePolygon(i-1u);edkEnd();
    }
    this->polygons.clean();edkEnd();
}
//delete the polygon
bool edk::shape::Polygon2DList::removePolygon(edk::uint32 position){
    //test if have this polygon
    if(this->polygons.havePos(position)){
        //then get the element in the position
        edk::shape::Polygon2D* temp = this->polygons.remove(position);edkEnd();
        //test if have the temp
        if(temp){
            //delete the polygon
            delete temp;edkEnd();
        }
        temp=NULL;edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
//free de selected
void edk::shape::Polygon2DList::freeSelected(){
    //
    this->selected=NULL;edkEnd();
}

//SELECTED
bool edk::shape::Polygon2DList::selectPolygon(edk::uint32 position){
    //test if have the position
    if(this->polygons.havePos(position)){
        //select the polygon
        this->selected = this->polygons.get(position);edkEnd();
        //test if have selected some polygon
        if(this->selected){
            //then return true
            return true;
        }
    }
    //else return false
    return false;
}
//set the position of a vertex
bool edk::shape::Polygon2DList::selectedSetVertexPosition(edk::uint32 vertex,edk::vec2f32 position){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setVertexPosition(vertex,position);edkEnd();
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetVertexPosition(edk::uint32 vertex,edk::float32 x,edk::float32 y){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setVertexPosition(vertex,x,y);edkEnd();
    }
    //else return false
    return false;
}
//set the color of a vertex
bool edk::shape::Polygon2DList::selectedSetVertexColor(edk::uint32 vertex,edk::color4f32 color){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setVertexColor(vertex,color);edkEnd();
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetVertexColor(edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setVertexColor(vertex,r,g,b);edkEnd();
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetVertexColor(edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setVertexColor(vertex,r,g,b,a);edkEnd();
    }
    //else return false
    return false;
}
//Set polygon color
bool edk::shape::Polygon2DList::selectedSetPolygonColor(edk::color4f32 color){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setPolygonColor(color);edkEnd();
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setPolygonColor(r,g,b);edkEnd();
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setPolygonColor(r,g,b,a);edkEnd();
    }
    //else return false
    return false;
}
//set the UVMap of the vertex
bool edk::shape::Polygon2DList::selectedSetVertexUV(edk::uint32 vertex,edk::vec2f32 uv){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setVertexUV(vertex,uv);edkEnd();
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetVertexUV(edk::uint32 vertex,edk::float32 x,edk::float32 y){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setVertexUV(vertex,x,y);edkEnd();
    }
    //else return false
    return false;
}
//Set the polygonFrames setting in the vertexs
bool edk::shape::Polygon2DList::selectedSetPolygonUVFrames(edk::vec2ui32 frames){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setPolygonUVFrames(frames);edkEnd();
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetPolygonUVFrames(edk::uint32 x,edk::uint32 y){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setPolygonUVFrames(x,y);edkEnd();
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetPolygonUVFramesX(edk::uint32 x){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setPolygonUVFramesX(x);edkEnd();
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetPolygonUVFramesY(edk::uint32 y){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setPolygonUVFramesY(y);edkEnd();
    }
    //else return false
    return false;
}
//Set the polygon frame
bool edk::shape::Polygon2DList::selectedSetPolygonUVFrame(edk::vec2ui32 frame){
    return this->selectedUsePolygonUVFrame(frame);
}
bool edk::shape::Polygon2DList::selectedSetPolygonUVFrame(edk::uint32 x,edk::uint32 y){
    return this->selectedUsePolygonUVFrame(x,y);
}
bool edk::shape::Polygon2DList::selectedSetPolygonUVFramePosition(edk::uint32 position){
    return this->selectedUsePolygonUVFramePosition(position);
}
bool edk::shape::Polygon2DList::selectedSetPolygonUVFrameX(edk::uint32 x){
    return this->selectedUsePolygonUVFrameX(x);
}
bool edk::shape::Polygon2DList::selectedSetPolygonUVFrameY(edk::uint32 y){
    return this->selectedUsePolygonUVFrameY(y);
}
bool edk::shape::Polygon2DList::selectedUsePolygonUVFrame(edk::vec2ui32 frame){
    //test if have selected
    if(this->selected){
        //
        this->selected->usePolygonUVFrame(frame);edkEnd();

        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedUsePolygonUVFrame(edk::uint32 x,edk::uint32 y){
    return this->selectedUsePolygonUVFrame(edk::vec2ui32 (x,y));edkEnd();
}
bool edk::shape::Polygon2DList::selectedUsePolygonUVFramePosition(edk::uint32 position){
    //test if have selcted
    if(this->selected){
        //
        this->selected->usePolygonUVFramePosition(position);edkEnd();

        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedUsePolygonUVFrameX(edk::uint32 x){
    //test if have selected
    if(this->selected){
        //
        this->selected->usePolygonUVFrameX(x);edkEnd();

        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedUsePolygonUVFrameY(edk::uint32 y){
    //test if have selected
    if(this->selected){
        //
        this->selected->usePolygonUVFrameY(y);edkEnd();

        //return true
        return true;
    }
    //else return false
    return false;
}
//Set physics
bool edk::shape::Polygon2DList::selectedSetDensity(edk::float32 density){
    //test if have selected
    if(this->selected){
        //
        this->selected->setDensity(density);edkEnd();

        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetFriction(edk::float32 friction){
    //test if have selected
    if(this->selected){
        //
        this->selected->setFriction(friction);edkEnd();

        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetRestitution(edk::float32 restitution){
    //test if have selected
    if(this->selected){
        //
        this->selected->setRestitution(restitution);edkEnd();

        //return true
        return true;
    }
    //else return false
    return false;
}
//set transform
bool edk::shape::Polygon2DList::selectedSetTranslate(edk::vec2f32 translate){
    //test if have selected
    if(this->selected){
        this->selected->setTranslate(translate);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetTranslate(edk::float32 translate){
    //test if have selected
    if(this->selected){
        this->selected->setTranslate(translate);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetTranslate(edk::float32 x,edk::float32 y){
    return this->selectedSetTranslate(edk::vec2f32(x,y));
}
bool edk::shape::Polygon2DList::selectedSetScale(edk::size2f32 scale){
    //test if have selected
    if(this->selected){
        this->selected->setScale(scale);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetScale(edk::float32 scale){
    //test if have selected
    if(this->selected){
        this->selected->setScale(scale);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetScale(edk::float32 width,edk::float32 height){
    return this->selectedSetScale(edk::size2f32(width,height));
}
bool edk::shape::Polygon2DList::selectedSetAngle(edk::float32 angle){
    //test if have selected
    if(this->selected){
        this->selected->setAngle(angle);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

//CLEANS
//remove the UV of one vertex
bool edk::shape::Polygon2DList::selectedRemoveVertexUV(edk::uint32 vertex){
    //test if have selected
    if(this->selected){
        //
        return this->selected->removeVertexUV(vertex);edkEnd();
    }
    //else return false
    return false;
}
//remove the UV from the polygon
bool edk::shape::Polygon2DList::selectedRemovePolygonUV(){
    //test if have selected
    if(this->selected){
        //
        this->selected->removePolygonUV();edkEnd();

        //return true
        return true;
    }
    //else return false
    return false;
}
//clean the UV animation in polygons
bool edk::shape::Polygon2DList::selectedCleanPolygonUVAnimation(){
    //test if have selected
    if(this->selected){
        //
        this->selected->cleanPolygonUVAnimation();edkEnd();

        //return true
        return true;
    }
    //else return false
    return false;
}
//return the vertexCount
edk::uint32 edk::shape::Polygon2DList::selectedGetVertexCount(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getVertexCount();edkEnd();
    }
    //else return zero
    return 0u;edkEnd();
}
//return if the vertex have UV
edk::uint8 edk::shape::Polygon2DList::selectedGetVertexType(edk::uint32 pos){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getVertexType(pos);edkEnd();
    }
    //else return zero
    return 0u;edkEnd();
}
//return the vertex
edk::vec2f32 edk::shape::Polygon2DList::selectedGetVertexPosition(edk::uint32 pos){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getVertexPosition(pos);edkEnd();
    }
    //else return zero
    return edk::vec2f32(0,0);edkEnd();
}
//return the vertex color
edk::color4f32 edk::shape::Polygon2DList::selectedGetVertexColor(edk::uint32 pos){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getVertexColor(pos);edkEnd();
    }
    //else return zero
    return edk::color4f32(0,0,0,0);edkEnd();
}
//return the vertex UV
edk::vec2f32 edk::shape::Polygon2DList::selectedGetVertexUV(edk::uint32 pos){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getVertexUV(pos);edkEnd();
    }
    //else return zero
    return edk::vec2f32();edkEnd();
}
//return the frames
edk::vec2ui32 edk::shape::Polygon2DList::selectedGetFrames(){
    //test if have selected
    if(this->selected){
        return this->selected->getFrames();edkEnd();
    }
    //else return zero
    return edk::vec2ui32(0u,0u);edkEnd();
}
edk::uint32 edk::shape::Polygon2DList::selectedGetFramesPosition(){
    //test if have selected
    if(this->selected){
        return this->selected->getFramesPosition();edkEnd();
    }
    //else return zero
    return 0u;edkEnd();
}
//return the frameUsed
edk::vec2ui32 edk::shape::Polygon2DList::selectedGetFrameUsed(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getFrameUsed();edkEnd();
    }
    //else return zero
    return edk::vec2ui32(0u,0u);edkEnd();
}
edk::uint32 edk::shape::Polygon2DList::selectedGetFramePositionUsed(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getFramePositionUsed();edkEnd();
    }
    //else return zero
    return 0u;edkEnd();
}

//get Transate
edk::vec2f32 edk::shape::Polygon2DList::selectedGetTranslate(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getTranslate();edkEnd();
    }
    //else return zero
    return edk::vec2f32(0u,0u);edkEnd();
}
//get scale
edk::size2f32 edk::shape::Polygon2DList::selectedGetScale(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getScale();edkEnd();
    }
    //else return zero
    return edk::size2f32(0u,0u);edkEnd();
}
//get angle
edk::float32 edk::shape::Polygon2DList::selectedGetAngle(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getAngle();edkEnd();
    }
    //else return zero
    return 0u;edkEnd();
}
//return if is a circle
bool edk::shape::Polygon2DList::selectedIsCircle(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->isCircle();edkEnd();
    }
    return false;
}
//return if is a line
bool edk::shape::Polygon2DList::selectedIsLine(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->isLine();edkEnd();
    }
    return false;
}
//return the collisionID
edk::uint8 edk::shape::Polygon2DList::selectedGetCollisionID(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getCollisionID();edkEnd();
    }
    return 0u;edkEnd();
}
//return the circle radius
edk::float32 edk::shape::Polygon2DList::selectedGetCircleRadius(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getCircleRadius();edkEnd();
    }
    return 0.f;
}
//get Physics
edk::float32 edk::shape::Polygon2DList::selectedGetDensity(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getDensity();edkEnd();
    }
    return 0.f;
}
edk::float32 edk::shape::Polygon2DList::selectedGetFriction(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getFriction();edkEnd();
    }
    return 0.f;
}
edk::float32 edk::shape::Polygon2DList::selectedGetRestitution(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getRestitution();edkEnd();
    }
    return 0.f;
}
//draw the selectedPolygon
bool edk::shape::Polygon2DList::selectedDrawPolygon(){
    //test if have selected
    if(this->selected){
        //
        this->selected->draw();edkEnd();
        return true;
    }
    return false;
}
bool edk::shape::Polygon2DList::selectedDrawWirePolygon(){
    //test if have selected
    if(this->selected){
        //
        this->selected->drawWire();edkEnd();
        return true;
    }
    return false;
}
bool edk::shape::Polygon2DList::selectedDrawVertexs(edk::color3f32 color){
    //test if have selected
    if(this->selected){
        //
        this->selected->drawPolygonVertexs(edk::color4f32(color.r,color.g,color.b,1.f));edkEnd();
        return true;
    }
    return false;
}

//XML
bool edk::shape::Polygon2DList::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"mesh_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        edk::uint32 size = this->polygons.size();edkEnd();
                        edk::char8* temp = edk::String::int64ToStr((edk::int64)size);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"pCount",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        edk::shape::Polygon2D* poly;edkEnd();
                        //write the polygons
                        for(edk::uint32 i=0u;i<size;i++){
                            if(this->polygons.havePos(i)){
                                poly=this->polygons.get(i);edkEnd();
                                if(poly){
                                    poly->writeToXML(xml,i);edkEnd();
                                }
                            }
                        }
                        ret=true;edkEnd();
                        xml->selectFather();edkEnd();
                    }
                }
                free(name);edkEnd();
            }
            free(nameID);edkEnd();
        }
        return ret;
    }
    return false;
}
bool edk::shape::Polygon2DList::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"mesh_",nameID);edkEnd();
            if(name){
                //select the name
                if(xml->selectChild(name)){
                    this->cleanPolygons();edkEnd();
                    edk::uint32 size = edk::String::strToInt64(xml->getSelectedAttributeValueByName("pCount"));edkEnd();
                    edk::shape::Polygon2D poly;edkEnd();
                    //READ the polygons
                    for(edk::uint32 i=0u;i<size;i++){
                        poly.deletePolygon();edkEnd();
                        poly.readFromXML(xml,i);edkEnd();
                        //add the poly
                        this->addPolygon(poly);edkEnd();
                    }
                    ret=true;edkEnd();
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(nameID);edkEnd();
        }
        return ret;
    }
    return false;
}
bool edk::shape::Polygon2DList::cloneFrom(edk::shape::Polygon2DList* list){
    //delete the polygons
    this->cleanPolygons();edkEnd();
    if(list){
        //read the polygons
#if defined(edkCPPversion17)
        edk::uint32 size = list->polygons.size();edkEnd();
#else
        register edk::uint32 size = list->polygons.size();edkEnd();
#endif
        edk::uint32 select=0u;
        edk::shape::Polygon2D* temp = NULL;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp=list->polygons.get(i);edkEnd();
            if(temp){
                if(temp==list->selected){
                    select=i;edkEnd();
                }
                this->addPolygon(*temp);edkEnd();
            }
        }
        this->selectPolygon(select);edkEnd();
        return true;
    }
    return false;
}

//DRAW
//print the mesh
void edk::shape::Polygon2DList::printPolygons(){
    //print the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        if(this->polygons.havePos(i)){
            printf("\nPolygon %u"
                   ,i
                   );fflush(stdout);edkEnd();
            this->polygons.get(i)->print();edkEnd();
        }
    }
}
bool edk::shape::Polygon2DList::printPolygon(edk::uint32 polygon){
    //print the polygons
    if(polygon<this->polygons.size()){
        if(this->polygons.havePos(polygon)){
            printf("\nPolygon %u"
                   ,polygon
                   );edkEnd();
            this->polygons.get(polygon)->print();edkEnd();
            return true;
        }
    }
    return false;
}

//draw the mesh
void edk::shape::Polygon2DList::drawPolygons(){
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->draw();edkEnd();
        }
    }
}
bool edk::shape::Polygon2DList::drawPolygon(edk::uint32 polygon){
    //draw the polygon
    if(polygon<this->polygons.size()){
        if(this->polygons.havePos(polygon)){
            this->polygons.get(polygon)->draw();edkEnd();
            return true;
        }
    }
    return false;
}
//draw the polygons in wireframe
void edk::shape::Polygon2DList::drawWirePolygons(){
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->drawWire();edkEnd();
        }
    }
}
bool edk::shape::Polygon2DList::drawWirePolygon(edk::uint32 polygon){
    //draw the polygons
    if(polygon<this->polygons.size()){
        if(this->polygons.havePos(polygon)){
            this->polygons.get(polygon)->drawWire();edkEnd();
            return true;
        }
    }
    return false;
}
void edk::shape::Polygon2DList::drawVertexs(edk::color3f32 color){
    edk::GU::guColor3f32(color);edkEnd();
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->drawPolygonVertexs(edk::color4f32(color.r,color.g,color.b,1.f));edkEnd();
        }
    }
}
bool edk::shape::Polygon2DList::drawPolygonVertexs(edk::uint32 polygon,edk::color3f32 color){
    //draw the polygons
    if(polygon<this->polygons.size()){
        if(this->polygons.havePos(polygon)){
            edk::GU::guColor3f32(color);edkEnd();
            this->polygons.get(polygon)->drawPolygonVertexs(edk::color4f32(color.r,color.g,color.b,1.f));edkEnd();
            return true;
        }
    }
    return false;
}
//draw the polygons in wireframe in world points
void edk::shape::Polygon2DList::drawWirePolygonsWorld(){
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->drawWireWorld();edkEnd();
        }
    }
}
bool edk::shape::Polygon2DList::drawWirePolygonWorld(edk::uint32 polygon){
    //draw the polygons
    if(polygon<this->polygons.size()){
        if(this->polygons.havePos(polygon)){
            this->polygons.get(polygon)->drawWireWorld();edkEnd();
            return true;
        }
    }
    return false;
}
void edk::shape::Polygon2DList::drawVertexsWorld(edk::color3f32 color){
    edk::GU::guColor3f32(color);edkEnd();
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->drawPolygonVertexsWorld(edk::color4f32(color.r,color.g,color.b,1.f));edkEnd();
        }
    }
}
bool edk::shape::Polygon2DList::drawPolygonVertexsWorld(edk::uint32 polygon,edk::color3f32 color){
    //draw the polygons
    if(polygon<this->polygons.size()){
        if(this->polygons.havePos(polygon)){
            edk::GU::guColor3f32(color);edkEnd();
            this->polygons.get(polygon)->drawPolygonVertexsWorld(edk::color4f32(color.r,color.g,color.b,1.f));edkEnd();
            return true;
        }
    }
    return false;
}
