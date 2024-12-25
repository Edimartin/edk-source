#include "Polygon3DList.h"

/*
Library Polygon3DList - Manage 3D Polygons in EDK Game Engine
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
#pragma message "            Inside Polygon3DList.cpp"
#endif

edk::shape::Polygon3DList::Polygon3DList(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::shape::Polygon3DList::~Polygon3DList(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        //clean the polygons
        this->cleanPolygons();edkEnd();
    }
}

void edk::shape::Polygon3DList::Constructor(bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;

        this->polygons.Constructor();edkEnd();

        //clean the selected
        this->freeSelected();edkEnd();

        this->tempP.Constructor();
        this->tempP.setTranslate(0.f,0.f,0.f);
        this->tempP.setScale(1.f,1.f,1.f);
        this->tempP.setAngle(0.f);
        this->tempP.setVertexPosition(0u,0.f,0.f,0.f);
        this->tempP.setVertexPosition(1u,1.f,1.f,1.f);
    }
}

//Set polygons color
bool edk::shape::Polygon3DList::setPolygonsColor(edk::color4f32 color){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon3D* polygon=NULL;edkEnd();
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
bool edk::shape::Polygon3DList::setPolygonsColor(edk::color3f32 color){
    return setPolygonsColor(color.r,color.g,color.b);edkEnd();
}
bool edk::shape::Polygon3DList::setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon3D* polygon=NULL;edkEnd();
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
bool edk::shape::Polygon3DList::setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon3D* polygon=NULL;edkEnd();
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
bool edk::shape::Polygon3DList::setPolygonsColorR(edk::float32 r){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon3D* polygon=NULL;edkEnd();
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
bool edk::shape::Polygon3DList::setPolygonsColorG(edk::float32 g){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon3D* polygon=NULL;edkEnd();
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
bool edk::shape::Polygon3DList::setPolygonsColorB(edk::float32 b){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon3D* polygon=NULL;edkEnd();
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
bool edk::shape::Polygon3DList::setPolygonsColorA(edk::float32 a){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon3D* polygon=NULL;edkEnd();
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
//set polygons smooth
bool edk::shape::Polygon3DList::setPolygonsSmooth(bool smooth){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon3D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.getPolygon(i);edkEnd();
            if(polygon){
                polygon->smooth=smooth;edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon3DList::setPolygonsSmoothOn(){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon3D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.getPolygon(i);edkEnd();
            if(polygon){
                polygon->smooth=true;edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon3DList::setPolygonsSmoothOff(){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon3D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.getPolygon(i);edkEnd();
            if(polygon){
                polygon->smooth=false;edkEnd();
            }
        }
        return true;
    }
    return false;
}
//update polygons normals
bool edk::shape::Polygon3DList::updatePolygonsNormals(){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon3D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.getPolygon(i);edkEnd();
            if(polygon){
                polygon->updateNormal();edkEnd();
            }
        }
        return true;
    }
    return false;
}

//set physics
bool edk::shape::Polygon3DList::setPolygonDensity(edk::uint32 position,edk::float32 density){
    if(this->polygons.havePos(position)){
        this->polygons.get(position)->setDensity(density);edkEnd();
        return true;
    }
    return false;
}
void edk::shape::Polygon3DList::setDensity(edk::float32 density){
    edk::uint32 size = this->polygons.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->setDensity(density);edkEnd();
        }
    }
}
bool edk::shape::Polygon3DList::setPolygonFriction(edk::uint32 position,edk::float32 friction){
    if(this->polygons.havePos(position)){
        this->polygons.get(position)->setFriction(friction);edkEnd();
        return true;
    }
    return false;
}
void edk::shape::Polygon3DList::setFriction(edk::float32 friction){
    edk::uint32 size = this->polygons.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->setFriction(friction);edkEnd();
        }
    }
}
bool edk::shape::Polygon3DList::setPolygonRestitution(edk::uint32 position,edk::float32 restitution){
    if(this->polygons.havePos(position)){
        this->polygons.get(position)->setRestitution(restitution);edkEnd();
        return true;
    }
    return false;
}
void edk::shape::Polygon3DList::setRestitution(edk::float32 restitution){
    edk::uint32 size = this->polygons.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->setRestitution(restitution);edkEnd();
        }
    }
}
//getPhysics
edk::float32 edk::shape::Polygon3DList::getPolygonDensity(edk::uint32 position){
    if(this->polygons.havePos(position)){
        return this->polygons.get(position)->getDensity();edkEnd();
    }
    //return initial value
    return 1.f;edkEnd();
}
edk::float32 edk::shape::Polygon3DList::getPolygonFriction(edk::uint32 position){
    if(this->polygons.havePos(position)){
        return this->polygons.get(position)->getFriction();edkEnd();
    }
    //return initial value
    return 0.f;
}
edk::float32 edk::shape::Polygon3DList::getPolygonRestitution(edk::uint32 position){
    if(this->polygons.havePos(position)){
        return this->polygons.get(position)->getRestitution();edkEnd();
    }
    //return initial value
    return 0.f;
}

//function to calculate boundingBox
bool edk::shape::Polygon3DList::calculateBoundingBox(edk::cubef32* rectangle,edk::vector::Matrixf32<4u,4u>* transformMat){
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
edk::cubef32 edk::shape::Polygon3DList::generateBoundingBox(edk::vector::Matrixf32<4u,4u>* transformMat){
    edk::cubef32 ret;edkEnd();
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
bool edk::shape::Polygon3DList::calculateBoundingPoint(edk::vec3f32 point,edk::vec3f32* dest,edk::vector::Matrixf32<4u,4u>* transformMat){
    if(dest && transformMat){
        this->tempP.setVertexPosition(0u,point);
        return this->tempP.calculateBoundingPoint(dest,transformMat);
    }
    return false;
}
edk::vec3f32 edk::shape::Polygon3DList::generateBoundingPoint(edk::vec3f32 point,edk::vector::Matrixf32<4u,4u>* transformMat){
    edk::vec3f32 ret;edkEnd();
    if(transformMat){
        this->tempP.setVertexPosition(0u,point);
        ret = this->tempP.generateBoundingPoint(transformMat);
    }
    return ret;
}
//function to calculate boundingBox from polygon positions
bool edk::shape::Polygon3DList::calculateBoundingBoxFromPolygons(edk::cubef32* rectangle,
                                                                 edk::vector::Matrixf32<4u,4u>* transformMat,
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
edk::cubef32 edk::shape::Polygon3DList::generateBoundingBoxFromPolygons(edk::vector::Matrixf32<4u,4u>* transformMat,
                                                                        edk::uint32 lenght,
                                                                        edk::uint32* positions
                                                                        ){
    edk::cubef32 ret;edkEnd();
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
bool edk::shape::Polygon3DList::getWorldPolygon(edk::shape::Polygon3D* dest,edk::uint32 polygonPosition,edk::vector::Matrixf32<4u,4u>* transformMat){
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
bool edk::shape::Polygon3DList::generateWorldPolygons(edk::shape::Polygon3DList* dest,
                                                      edk::vector::Matrixf32<4u,4u>* transformMat
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
bool edk::shape::Polygon3DList::generateWorldPolygons(edk::shape::Polygon3DList* dest,
                                                      edk::vector::Matrixf32<4u,4u>* transformMat,
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
edk::uint32 edk::shape::Polygon3DList::addPolygon(edk::shape::Polygon3D polygon){
    //return
    edk::uint32 ret=0u;
    //polygon to be added
    edk::shape::Polygon3D* temp=NULL;edkEnd();
    //test if it's a line
    if(polygon.isLine()){
        temp=new edk::shape::Lines3D;edkEnd();
    }
    //test al much vertex have the polygon. Test if are a polygon or Rectangle.
    else if(polygon.getVertexCount()>=2u){
        if(polygon.getVertexCount()>2u){
            if(polygon.isCircle()){
                //it's circle

                //create the circle
                temp=(edk::shape::Polygon3D*)new edk::shape::Circle3D;edkEnd();
            }
            else{
                //it's a polygon

                //create the polygon
                temp=new edk::shape::Polygon3D;edkEnd();
            }
        }
        else{
            //it's a rectangle

            //create a rectangle
            temp=(edk::shape::Polygon3D*) new edk::shape::Cube3D;edkEnd();
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
edk::uint32 edk::shape::Polygon3DList::getPolygonSize(){
    //
    return this->polygons.size();edkEnd();
}
//return true if have a polygon selected
bool edk::shape::Polygon3DList::haveSelected(){
    //
    return (bool) this->selected;edkEnd();
}

//test if have a polygon in a position
bool edk::shape::Polygon3DList::havePolygon(edk::uint32 position){
    return this->polygons.havePos(position);
}
//get the polygon in a position
edk::shape::Polygon3D edk::shape::Polygon3DList::getPolygon(edk::uint32 position){
    edk::shape::Polygon3D ret;
    if(this->havePolygon(position)){
        //get the polygon
        edk::shape::Polygon3D* temp = this->polygons.get(position);
        if(temp){
            //copy the polygon
            ret.cloneFrom(temp);
        }
    }
    return ret;
}
bool edk::shape::Polygon3DList::getPolygon(edk::uint32 position,edk::shape::Polygon3D* dest){
    if(dest && this->havePolygon(position)){
        //get the polygon
        edk::shape::Polygon3D* temp = this->polygons.get(position);
        if(temp){
            //copy the polygon
            return dest->cloneFrom(temp);
        }
    }
    return false;
}

//DELETE
//clean the polygons
void edk::shape::Polygon3DList::cleanPolygons(){
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
bool edk::shape::Polygon3DList::removePolygon(edk::uint32 position){
    //test if have this polygon
    if(this->polygons.havePos(position)){
        //then get the element in the position
        edk::shape::Polygon3D* temp = this->polygons.remove(position);edkEnd();
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
void edk::shape::Polygon3DList::freeSelected(){
    //
    this->selected=NULL;edkEnd();
}

//SELECTED
bool edk::shape::Polygon3DList::selectPolygon(edk::uint32 position){
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
bool edk::shape::Polygon3DList::selectedSetVertexPosition(edk::uint32 vertex,edk::vec3f32 position){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setVertexPosition(vertex,position);edkEnd();
    }
    //else return false
    return false;
}
bool edk::shape::Polygon3DList::selectedSetVertexPosition(edk::uint32 vertex,edk::float32 x,edk::float32 y,edk::float32 z){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setVertexPosition(vertex,x,y,z);edkEnd();
    }
    //else return false
    return false;
}
//set the color of a vertex
bool edk::shape::Polygon3DList::selectedSetVertexColor(edk::uint32 vertex,edk::color4f32 color){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setVertexColor(vertex,color);edkEnd();
    }
    //else return false
    return false;
}
bool edk::shape::Polygon3DList::selectedSetVertexColor(edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setVertexColor(vertex,r,g,b);edkEnd();
    }
    //else return false
    return false;
}
bool edk::shape::Polygon3DList::selectedSetVertexColor(edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
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
bool edk::shape::Polygon3DList::selectedSetPolygonColor(edk::color4f32 color){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setPolygonColor(color);edkEnd();
    }
    //else return false
    return false;
}
bool edk::shape::Polygon3DList::selectedSetPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setPolygonColor(r,g,b);edkEnd();
    }
    //else return false
    return false;
}
bool edk::shape::Polygon3DList::selectedSetPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
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
bool edk::shape::Polygon3DList::selectedSetVertexUV(edk::uint32 vertex,edk::vec2f32 uv){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setVertexUV(vertex,uv);edkEnd();
    }
    //else return false
    return false;
}
bool edk::shape::Polygon3DList::selectedSetVertexUV(edk::uint32 vertex,edk::float32 x,edk::float32 y){
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
bool edk::shape::Polygon3DList::selectedSetPolygonUVFrames(edk::vec2ui32 frames){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setPolygonUVFrames(frames);edkEnd();
    }
    //else return false
    return false;
}
bool edk::shape::Polygon3DList::selectedSetPolygonUVFrames(edk::uint32 x,edk::uint32 y){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setPolygonUVFrames(x,y);edkEnd();
    }
    //else return false
    return false;
}
bool edk::shape::Polygon3DList::selectedSetPolygonUVFramesX(edk::uint32 x){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setPolygonUVFramesX(x);edkEnd();
    }
    //else return false
    return false;
}
bool edk::shape::Polygon3DList::selectedSetPolygonUVFramesY(edk::uint32 y){
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
bool edk::shape::Polygon3DList::selectedSetPolygonUVFrame(edk::vec2ui32 frame){
    return this->selectedUsePolygonUVFrame(frame);
}
bool edk::shape::Polygon3DList::selectedSetPolygonUVFrame(edk::uint32 x,edk::uint32 y){
    return this->selectedUsePolygonUVFrame(x,y);
}
bool edk::shape::Polygon3DList::selectedSetPolygonUVFramePosition(edk::uint32 position){
    return this->selectedUsePolygonUVFramePosition(position);
}
bool edk::shape::Polygon3DList::selectedSetPolygonUVFrameX(edk::uint32 x){
    return this->selectedUsePolygonUVFrameX(x);
}
bool edk::shape::Polygon3DList::selectedSetPolygonUVFrameY(edk::uint32 y){
    return this->selectedUsePolygonUVFrameY(y);
}
bool edk::shape::Polygon3DList::selectedUsePolygonUVFrame(edk::vec2ui32 frame){
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
bool edk::shape::Polygon3DList::selectedUsePolygonUVFrame(edk::uint32 x,edk::uint32 y){
    return this->selectedUsePolygonUVFrame(edk::vec2ui32 (x,y));edkEnd();
}
bool edk::shape::Polygon3DList::selectedUsePolygonUVFramePosition(edk::uint32 position){
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
bool edk::shape::Polygon3DList::selectedUsePolygonUVFrameX(edk::uint32 x){
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
bool edk::shape::Polygon3DList::selectedUsePolygonUVFrameY(edk::uint32 y){
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
bool edk::shape::Polygon3DList::selectedSetDensity(edk::float32 density){
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
bool edk::shape::Polygon3DList::selectedSetFriction(edk::float32 friction){
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
bool edk::shape::Polygon3DList::selectedSetRestitution(edk::float32 restitution){
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
bool edk::shape::Polygon3DList::selectedSetTranslate(edk::vec3f32 translate){
    //test if have selected
    if(this->selected){
        this->selected->setTranslate(translate);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon3DList::selectedSetTranslate(edk::float32 translate){
    //test if have selected
    if(this->selected){
        this->selected->setTranslate(translate);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon3DList::selectedSetTranslate(edk::float32 x,edk::float32 y,edk::float32 z){
    return this->selectedSetTranslate(edk::vec3f32(x,y,z));
}
bool edk::shape::Polygon3DList::selectedSetScale(edk::size3f32 scale){
    //test if have selected
    if(this->selected){
        this->selected->setScale(scale);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon3DList::selectedSetScale(edk::float32 scale){
    //test if have selected
    if(this->selected){
        this->selected->setScale(scale);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon3DList::selectedSetScale(edk::float32 width,edk::float32 height,edk::float32 length){
    return this->selectedSetScale(edk::size3f32(width,height,length));
}
bool edk::shape::Polygon3DList::selectedSetAngle(edk::float32 angle){
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
bool edk::shape::Polygon3DList::selectedRemoveVertexUV(edk::uint32 vertex){
    //test if have selected
    if(this->selected){
        //
        return this->selected->removeVertexUV(vertex);edkEnd();
    }
    //else return false
    return false;
}
//remove the UV from the polygon
bool edk::shape::Polygon3DList::selectedRemovePolygonUV(){
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
bool edk::shape::Polygon3DList::selectedCleanPolygonUVAnimation(){
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
edk::uint32 edk::shape::Polygon3DList::selectedGetVertexCount(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getVertexCount();edkEnd();
    }
    //else return zero
    return 0u;edkEnd();
}
//return if the vertex have UV
edk::uint8 edk::shape::Polygon3DList::selectedGetVertexType(edk::uint32 pos){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getVertexType(pos);edkEnd();
    }
    //else return zero
    return 0u;edkEnd();
}
//return the vertex
edk::vec3f32 edk::shape::Polygon3DList::selectedGetVertexPosition(edk::uint32 pos){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getVertexPosition(pos);edkEnd();
    }
    //else return zero
    return edk::vec3f32(0.f,0.f,0.f);edkEnd();
}
//return the vertex color
edk::color4f32 edk::shape::Polygon3DList::selectedGetVertexColor(edk::uint32 pos){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getVertexColor(pos);edkEnd();
    }
    //else return zero
    return edk::color4f32(0,0,0,0);edkEnd();
}
//return the vertex UV
edk::vec2f32 edk::shape::Polygon3DList::selectedGetVertexUV(edk::uint32 pos){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getVertexUV(pos);edkEnd();
    }
    //else return zero
    return edk::vec2f32();edkEnd();
}
//return the frames
edk::vec2ui32 edk::shape::Polygon3DList::selectedGetFrames(){
    //test if have selected
    if(this->selected){
        return this->selected->getFrames();edkEnd();
    }
    //else return zero
    return edk::vec2ui32(0u,0u);edkEnd();
}
edk::uint32 edk::shape::Polygon3DList::selectedGetFramesPosition(){
    //test if have selected
    if(this->selected){
        return this->selected->getFramesPosition();edkEnd();
    }
    //else return zero
    return 0u;edkEnd();
}
//return the frameUsed
edk::vec2ui32 edk::shape::Polygon3DList::selectedGetFrameUsed(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getFrameUsed();edkEnd();
    }
    //else return zero
    return edk::vec2ui32(0u,0u);edkEnd();
}
edk::uint32 edk::shape::Polygon3DList::selectedGetFramePositionUsed(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getFramePositionUsed();edkEnd();
    }
    //else return zero
    return 0u;edkEnd();
}

//get Transate
edk::vec3f32 edk::shape::Polygon3DList::selectedGetTranslate(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getTranslate();edkEnd();
    }
    //else return zero
    return edk::vec3f32(0.f,0.f,0.f);edkEnd();
}
//get scale
edk::size3f32 edk::shape::Polygon3DList::selectedGetScale(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getScale();edkEnd();
    }
    //else return zero
    return edk::size3f32(0.f,0.f,0.f);edkEnd();
}
//get angle
edk::float32 edk::shape::Polygon3DList::selectedGetAngle(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getAngle();edkEnd();
    }
    //else return zero
    return 0u;edkEnd();
}
//return if is a circle
bool edk::shape::Polygon3DList::selectedIsCircle(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->isCircle();edkEnd();
    }
    return false;
}
//return if is a line
bool edk::shape::Polygon3DList::selectedIsLine(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->isLine();edkEnd();
    }
    return false;
}
//return the collisionID
edk::uint8 edk::shape::Polygon3DList::selectedGetCollisionID(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getCollisionID();edkEnd();
    }
    return 0u;edkEnd();
}
//return the circle radius
edk::float32 edk::shape::Polygon3DList::selectedGetCircleRadius(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getCircleRadius();edkEnd();
    }
    return 0.f;
}
//get Physics
edk::float32 edk::shape::Polygon3DList::selectedGetDensity(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getDensity();edkEnd();
    }
    return 0.f;
}
edk::float32 edk::shape::Polygon3DList::selectedGetFriction(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getFriction();edkEnd();
    }
    return 0.f;
}
edk::float32 edk::shape::Polygon3DList::selectedGetRestitution(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getRestitution();edkEnd();
    }
    return 0.f;
}
//draw the selectedPolygon
bool edk::shape::Polygon3DList::selectedDrawPolygon(){
    //test if have selected
    if(this->selected){
        //
        this->selected->draw();edkEnd();
        return true;
    }
    return false;
}
bool edk::shape::Polygon3DList::selectedDrawWirePolygon(){
    //test if have selected
    if(this->selected){
        //
        this->selected->drawWire();edkEnd();
        return true;
    }
    return false;
}
bool edk::shape::Polygon3DList::selectedDrawVertexs(edk::color3f32 color){
    //test if have selected
    if(this->selected){
        //
        this->selected->drawPolygonVertexs(edk::color4f32(color.r,color.g,color.b,1.f));edkEnd();
        return true;
    }
    return false;
}

//XML
bool edk::shape::Polygon3DList::writeToXML(edk::XML* xml,edk::uint32 id){
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
                        edk::shape::Polygon3D* poly;edkEnd();
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
bool edk::shape::Polygon3DList::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    edk::shape::Polygon3D poly;edkEnd();
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
bool edk::shape::Polygon3DList::cloneFrom(edk::shape::Polygon3DList* list){
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
        edk::shape::Polygon3D* temp = NULL;edkEnd();
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
void edk::shape::Polygon3DList::printPolygons(){
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
bool edk::shape::Polygon3DList::printPolygon(edk::uint32 polygon){
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
void edk::shape::Polygon3DList::drawPolygons(){
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->draw();edkEnd();
        }
    }
}
bool edk::shape::Polygon3DList::drawPolygon(edk::uint32 polygon){
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
void edk::shape::Polygon3DList::drawWirePolygons(){
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->drawWire();edkEnd();
        }
    }
}
bool edk::shape::Polygon3DList::drawWirePolygon(edk::uint32 polygon){
    //draw the polygons
    if(polygon<this->polygons.size()){
        if(this->polygons.havePos(polygon)){
            this->polygons.get(polygon)->drawWire();edkEnd();
            return true;
        }
    }
    return false;
}
void edk::shape::Polygon3DList::drawVertexs(edk::color3f32 color){
    edk::GU::guColor3f32(color);edkEnd();
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->drawPolygonVertexs(edk::color4f32(color.r,color.g,color.b,1.f));edkEnd();
        }
    }
}
bool edk::shape::Polygon3DList::drawPolygonVertexs(edk::uint32 polygon,edk::color3f32 color){
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
//draw the polygons normals
void edk::shape::Polygon3DList::drawNormals(){
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->drawNormals();edkEnd();
        }
    }
}
void edk::shape::Polygon3DList::drawNormalsWithColor(edk::color3f32 color){
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->drawNormalsWithColor(edk::color4f32(color.r,color.g,color.b,1.f));edkEnd();
        }
    }
}
//draw the polygons in wireframe in world points
void edk::shape::Polygon3DList::drawWirePolygonsWorld(){
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->drawWireWorld();edkEnd();
        }
    }
}
bool edk::shape::Polygon3DList::drawWirePolygonWorld(edk::uint32 polygon){
    //draw the polygons
    if(polygon<this->polygons.size()){
        if(this->polygons.havePos(polygon)){
            this->polygons.get(polygon)->drawWireWorld();edkEnd();
            return true;
        }
    }
    return false;
}
void edk::shape::Polygon3DList::drawVertexsWorld(edk::color3f32 color){
    edk::GU::guColor3f32(color);edkEnd();
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->drawPolygonVertexsWorld(edk::color4f32(color.r,color.g,color.b,1.f));edkEnd();
        }
    }
}
bool edk::shape::Polygon3DList::drawPolygonVertexsWorld(edk::uint32 polygon,edk::color3f32 color){
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

//draw the mesh with matrix
void edk::shape::Polygon3DList::drawPolygonsWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                       edk::vector::Matrixf32<4u,4u>* matrixTemp
                                                       ){
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->drawWithMatrix(matrix,matrixTemp);edkEnd();
        }
    }
}
bool edk::shape::Polygon3DList::drawPolygonWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                      edk::vector::Matrixf32<4u,4u>* matrixTemp,
                                                      edk::uint32 polygon){
    //draw the polygon
    if(polygon<this->polygons.size()){
        if(this->polygons.havePos(polygon)){
            this->polygons.get(polygon)->drawWithMatrix(matrix,matrixTemp);edkEnd();
            return true;
        }
    }
    return false;
}
//draw the polygons in wireframe with matrix
void edk::shape::Polygon3DList::drawWirePolygonsWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                           edk::vector::Matrixf32<4u,4u>* matrixTemp
                                                           ){
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->drawWireWithMatrix(matrix,matrixTemp);edkEnd();
        }
    }
}
bool edk::shape::Polygon3DList::drawWirePolygonWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                          edk::vector::Matrixf32<4u,4u>* matrixTemp,
                                                          edk::uint32 polygon
                                                          ){
    //draw the polygons
    if(polygon<this->polygons.size()){
        if(this->polygons.havePos(polygon)){
            this->polygons.get(polygon)->drawWireWithMatrix(matrix,matrixTemp);edkEnd();
            return true;
        }
    }
    return false;
}
void edk::shape::Polygon3DList::drawVertexsWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                      edk::vector::Matrixf32<4u,4u>* matrixTemp,
                                                      edk::color3f32 color
                                                      ){
    edk::GU::guColor3f32(color);edkEnd();
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->drawPolygonVertexsWithMatrix(matrix,
                                                                matrixTemp,
                                                                edk::color4f32(color.r,color.g,color.b,1.f)
                                                                );edkEnd();
        }
    }
}
bool edk::shape::Polygon3DList::drawPolygonVertexsWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                             edk::vector::Matrixf32<4u,4u>* matrixTemp,
                                                             edk::uint32 polygon,edk::color3f32 color
                                                             ){
    //draw the polygons
    if(polygon<this->polygons.size()){
        if(this->polygons.havePos(polygon)){
            edk::GU::guColor3f32(color);edkEnd();
            this->polygons.get(polygon)->drawPolygonVertexsWithMatrix(matrix,
                                                                      matrixTemp,
                                                                      edk::color4f32(color.r,color.g,color.b,1.f)
                                                                      );edkEnd();
            return true;
        }
    }
    return false;
}
//draw the polygons in wireframe in world points with matrix
void edk::shape::Polygon3DList::drawWirePolygonsWorldWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                                edk::vector::Matrixf32<4u,4u>* matrixTemp
                                                                ){
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->drawWireWorldWithMatrix(matrix,matrixTemp);edkEnd();
        }
    }
}
bool edk::shape::Polygon3DList::drawWirePolygonWorldWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                               edk::vector::Matrixf32<4u,4u>* matrixTemp,
                                                               edk::uint32 polygon
                                                               ){
    //draw the polygons
    if(polygon<this->polygons.size()){
        if(this->polygons.havePos(polygon)){
            this->polygons.get(polygon)->drawWireWorldWithMatrix(matrix,matrixTemp);edkEnd();
            return true;
        }
    }
    return false;
}
void edk::shape::Polygon3DList::drawVertexsWorldWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                           edk::vector::Matrixf32<4u,4u>* matrixTemp,
                                                           edk::color3f32 color
                                                           ){
    edk::GU::guColor3f32(color);edkEnd();
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        if(this->polygons.havePos(i)){
            this->polygons.get(i)->drawPolygonVertexsWorldWithMatrix(matrix,
                                                                     matrixTemp,
                                                                     edk::color4f32(color.r,color.g,color.b,1.f)
                                                                     );edkEnd();
        }
    }
}
bool edk::shape::Polygon3DList::drawPolygonVertexsWorldWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                                  edk::vector::Matrixf32<4u,4u>* matrixTemp
                                                                  ,edk::uint32 polygon,edk::color3f32 color
                                                                  ){
    //draw the polygons
    if(polygon<this->polygons.size()){
        if(this->polygons.havePos(polygon)){
            edk::GU::guColor3f32(color);edkEnd();
            this->polygons.get(polygon)->drawPolygonVertexsWorldWithMatrix(matrix,
                                                                           matrixTemp,
                                                                           edk::color4f32(color.r,color.g,color.b,1.f)
                                                                           );edkEnd();
            return true;
        }
    }
    return false;
}
