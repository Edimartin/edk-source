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
#warning "            Inside Polygon2DList.cpp"
#endif

edk::shape::Polygon2DList::Polygon2DList(){
    //clean the selected
    this->freeSelected();
    this->canDeleteList=true;
}

edk::shape::Polygon2DList::~Polygon2DList(){
    //clean the polygons
    if(this->canDeleteList){
        this->cleanPolygons();
    }
    else{
        this->polygons.cantDestroy();
    }
    this->canDeleteList=true;
}

//Set polygons color
bool edk::shape::Polygon2DList::setPolygonsColor(edk::color4f32 color){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon2D* polygon=NULL;
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.get(i);
            if(polygon){
                polygon->setPolygonColor(color);
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon2DList::setPolygonsColor(edk::color3f32 color){
    return setPolygonsColor(color.r,color.g,color.b);
}
bool edk::shape::Polygon2DList::setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon2D* polygon=NULL;
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.get(i);
            if(polygon){
                polygon->setPolygonColor(r,g,b);
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon2DList::setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon2D* polygon=NULL;
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.get(i);
            if(polygon){
                polygon->setPolygonColor(r,g,b,a);
            }
        }
        return true;
    }
    return false;
}
//set physics
bool edk::shape::Polygon2DList::setPolygonDensity(edk::uint32 position,edk::float32 density){
    if(this->polygons.havePos(position)){
        this->polygons[position]->setDensity(density);
        return true;
    }
    return false;
}
void edk::shape::Polygon2DList::setDensity(edk::float32 density){
    edk::uint32 size = this->polygons.size();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->polygons.havePos(i)){
            this->polygons[i]->setDensity(density);
        }
    }
}
bool edk::shape::Polygon2DList::setPolygonFriction(edk::uint32 position,edk::float32 friction){
    if(this->polygons.havePos(position)){
        this->polygons[position]->setFriction(friction);
        return true;
    }
    return false;
}
void edk::shape::Polygon2DList::setFriction(edk::float32 friction){
    edk::uint32 size = this->polygons.size();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->polygons.havePos(i)){
            this->polygons[i]->setFriction(friction);
        }
    }
}
bool edk::shape::Polygon2DList::setPolygonRestitution(edk::uint32 position,edk::float32 restitution){
    if(this->polygons.havePos(position)){
        this->polygons[position]->setRestitution(restitution);
        return true;
    }
    return false;
}
void edk::shape::Polygon2DList::setRestitution(edk::float32 restitution){
    edk::uint32 size = this->polygons.size();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->polygons.havePos(i)){
            this->polygons[i]->setRestitution(restitution);
        }
    }
}
//getPhysics
edk::float32 edk::shape::Polygon2DList::getPolygonDensity(edk::uint32 position){
    if(this->polygons.havePos(position)){
        return this->polygons[position]->getDensity();
    }
    //return initial value
    return 1.f;
}
edk::float32 edk::shape::Polygon2DList::getPolygonFriction(edk::uint32 position){
    if(this->polygons.havePos(position)){
        return this->polygons[position]->getFriction();
    }
    //return initial value
    return 0.f;
}
edk::float32 edk::shape::Polygon2DList::getPolygonRestitution(edk::uint32 position){
    if(this->polygons.havePos(position)){
        return this->polygons[position]->getRestitution();
    }
    //return initial value
    return 0.f;
}

//ADD
//add a polygon to the mesh
edk::uint32 edk::shape::Polygon2DList::addPolygon(edk::shape::Polygon2D polygon){
    //return
    edk::uint32 ret=0u;
    //polygon to be added
    edk::shape::Polygon2D* temp=NULL;
    //test if it's a line
    if(polygon.isLine()){
        temp=new edk::shape::Lines2D;
    }
    //test al much vertex have the polygon. Test if are a polygon or Rectangle.
    else if(polygon.getVertexCount()>=2u){
        if(polygon.getVertexCount()>2u){
            //it's a polygon

            //create the polygon
            temp=new edk::shape::Polygon2D();
        }
        else{
            //it's a rectangle

            //create a rectangle
            temp=(edk::shape::Polygon2D*) new edk::shape::Rectangle2D();
        }
    }

    //test if have created the polygon
    if(temp){
        //copy the polygon
        //*temp = polygon;
        temp->cloneFrom(&polygon);

        //load the size of the polygons
        edk::uint32 size = this->polygons.size() - this->polygons.sizeRemoved();
        //add the polygon
        ret = this->polygons.pushBack(temp);
        //now compare the size in the list
        if(size<(this->polygons.size() - this->polygons.sizeRemoved())){
            //polygon added

            //select the ret
            this->selectPolygon(ret);
        }
        else{
            //polygon dont added. Delete the temp
            delete temp;
            //clean the ret
            ret=0u;
        }
    }
    //set temp NULL
    temp=NULL;

    //remove the delete from the polygon. This dont delete polygon in the next destrutor
    polygon.cantDeletePolygon();
    //else return 0u;
    return ret;
}
//GETERS
//return the polygonSize
edk::uint32 edk::shape::Polygon2DList::getPolygonSize(){
    //
    return this->polygons.size();
}
//return true if have a polygon selected
bool edk::shape::Polygon2DList::haveSelected(){
    //
    return (bool) this->selected;
}

//DELETE
//clean the polygons
void edk::shape::Polygon2DList::cleanPolygons(){
    this->freeSelected();
    //remove all the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        //
        this->removePolygon(i);
    }
    this->polygons.clean();
}
//delete the polygon
bool edk::shape::Polygon2DList::removePolygon(edk::uint32 position){
    //test if have this polygon
    if(this->polygons.havePos(position)){
        //then get the element in the position
        edk::shape::Polygon2D* temp = this->polygons.remove(position);
        //test if have the temp
        if(temp){
            //delete the polygon
            delete temp;
        }
        temp=NULL;
        //return true
        return true;
    }
    //else return false
    return false;
}
//free de selected
void edk::shape::Polygon2DList::freeSelected(){
    //
    this->selected=NULL;
}

//SELECTED
bool edk::shape::Polygon2DList::selectPolygon(edk::uint32 position){
    //test if have the position
    if(this->polygons.havePos(position)){
        //select the polygon
        this->selected = this->polygons[position];
        //test if have selected some polygon
        if(this->selected)
            //then return true
            return true;
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
        return this->selected->setVertexPosition(vertex,position);
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetVertexPosition(edk::uint32 vertex,edk::float32 x,edk::float32 y){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setVertexPosition(vertex,x,y);
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
        return this->selected->setVertexColor(vertex,color);
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetVertexColor(edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setVertexColor(vertex,r,g,b);
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetVertexColor(edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setVertexColor(vertex,r,g,b,a);
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
        return this->selected->setPolygonColor(color);
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setPolygonColor(r,g,b);
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setPolygonColor(r,g,b,a);
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
        return this->selected->setVertexUV(vertex,uv);
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetVertexUV(edk::uint32 vertex,edk::float32 x,edk::float32 y){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setVertexUV(vertex,x,y);
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
        return this->selected->setPolygonUVFrames(frames);
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetPolygonUVFrames(edk::uint32 x,edk::uint32 y){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setPolygonUVFrames(x,y);
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetPolygonUVFramesX(edk::uint32 x){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setPolygonUVFramesX(x);
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedSetPolygonUVFramesY(edk::uint32 y){
    //test if have selected
    if(this->selected){
        //

        //return true
        return this->selected->setPolygonUVFramesY(y);
    }
    //else return false
    return false;
}
//Set the polygon frame
bool edk::shape::Polygon2DList::selectedUsePolygonUVFrame(edk::vec2ui32 frame){
    //test if have selected
    if(this->selected){
        //
        this->selected->usePolygonUVFrame(frame);

        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2DList::selectedUsePolygonUVFrame(edk::uint32 x,edk::uint32 y){
    return this->selectedUsePolygonUVFrame(edk::vec2ui32 (x,y));
}
bool edk::shape::Polygon2DList::selectedUsePolygonUVFramePosition(edk::uint32 position){
    //test if have selcted
    if(this->selected){
        //
        this->selected->usePolygonUVFramePosition(position);

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
        this->selected->usePolygonUVFrameX(x);

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
        this->selected->usePolygonUVFrameY(y);

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
        this->selected->setDensity(density);

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
        this->selected->setFriction(friction);

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
        this->selected->setRestitution(restitution);

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
        return this->selected->removeVertexUV(vertex);
    }
    //else return false
    return false;
}
//remove the UV from the polygon
bool edk::shape::Polygon2DList::selectedRemovePolygonUV(){
    //test if have selected
    if(this->selected){
        //
        this->selected->removePolygonUV();

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
        this->selected->cleanPolygonUVAnimation();

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
        return this->selected->getVertexCount();
    }
    //else return zero
    return 0u;
}
//return if the vertex have UV
edk::uint8 edk::shape::Polygon2DList::selectedGetVertexType(edk::uint32 pos){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getVertexType(pos);
    }
    //else return zero
    return 0u;
}
//return the vertex
edk::vec2f32 edk::shape::Polygon2DList::selectedGetVertexPosition(edk::uint32 pos){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getVertexPosition(pos);
    }
    //else return zero
    return edk::vec2f32(0,0);
}
//return the vertex color
edk::color4f32 edk::shape::Polygon2DList::selectedGetVertexColor(edk::uint32 pos){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getVertexColor(pos);
    }
    //else return zero
    return edk::color4f32(0,0,0,0);
}
//return the vertex UV
edk::vec2f32 edk::shape::Polygon2DList::selectedGetVertexUV(edk::uint32 pos){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getVertexUV(pos);
    }
    //else return zero
    return edk::vec2f32();
}
//return the frames
edk::vec2ui32 edk::shape::Polygon2DList::selectedGetFrames(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getFrames();
    }
    //else return zero
    return edk::vec2ui32(0u,0u);
}
//return the frameUsed
edk::vec2ui32 edk::shape::Polygon2DList::selectedGetFrameUsed(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getFrameUsed();
    }
    //else return zero
    return edk::vec2ui32(0u,0u);
}
edk::uint32 edk::shape::Polygon2DList::selectedGetFramePositionUsed(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getFramePositionUsed();
    }
    //else return zero
    return 0u;
}

//get Transate
edk::vec2f32 edk::shape::Polygon2DList::selectedGetTranslate(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getTranslate();
    }
    //else return zero
    return edk::vec2f32(0u,0u);
}
//get scale
edk::size2f32 edk::shape::Polygon2DList::selectedGetScale(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getScale();
    }
    //else return zero
    return edk::size2f32(0u,0u);
}
//get angle
edk::float32 edk::shape::Polygon2DList::selectedGetAngle(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getAngle();
    }
    //else return zero
    return 0u;
}
//return if is a circle
bool edk::shape::Polygon2DList::selectedIsCircle(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->isCircle();
    }
    return false;
}
//return if is a line
bool edk::shape::Polygon2DList::selectedIsLine(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->isLine();
    }
    return false;
}
//return the collisionID
edk::uint8 edk::shape::Polygon2DList::selectedGetCollisionID(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getCollisionID();
    }
    return 0u;
}
//return the circle radius
edk::float32 edk::shape::Polygon2DList::selectedGetCircleRadius(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getCircleRadius();
    }
    return 0.f;
}
//get Physics
edk::float32 edk::shape::Polygon2DList::selectedGetDensity(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getDensity();
    }
    return 0.f;
}
edk::float32 edk::shape::Polygon2DList::selectedGetFriction(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getFriction();
    }
    return 0.f;
}
edk::float32 edk::shape::Polygon2DList::selectedGetRestitution(){
    //test if have selected
    if(this->selected){
        //
        return this->selected->getRestitution();
    }
    return 0.f;
}
//draw the selectedPolygon
bool edk::shape::Polygon2DList::selectedDrawPolygon(){
    //test if have selected
    if(this->selected){
        //
        this->selected->draw();
        return true;
    }
    return false;
}
bool edk::shape::Polygon2DList::selectedDrawWirePolygon(){
    //test if have selected
    if(this->selected){
        //
        this->selected->drawWire();
        return true;
    }
    return false;
}
bool edk::shape::Polygon2DList::selectedDrawVertexs(edk::color3f32 color){
    //test if have selected
    if(this->selected){
        //
        this->selected->drawPolygonVertexs(edk::color4f32(color.r,color.g,color.b,1.f));
        return true;
    }
    return false;
}

//XML
bool edk::shape::Polygon2DList::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"mesh_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        edk::uint32 size = this->polygons.size();
                        edk::char8* temp = edk::String::int64ToStr((edk::int64)size);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"pCount",temp);
                            delete[] temp;
                        }
                        edk::shape::Polygon2D* poly;
                        //write the polygons
                        for(edk::uint32 i=0u;i<size;i++){
                            if(this->polygons.havePos(i)){
                                poly=this->polygons[i];
                                if(poly){
                                    poly->writeToXML(xml,i);
                                }
                            }
                        }
                        ret=true;
                        xml->selectFather();
                    }
                }
                delete[] name;
            }
            delete[] nameID;
        }
        return ret;
    }
    return false;
}
bool edk::shape::Polygon2DList::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"mesh_",nameID);
            if(name){
                //select the name
                if(xml->selectChild(name)){
                    this->cleanPolygons();
                    edk::uint32 size = edk::String::strToInt64(xml->getSelectedAttributeValueByName("pCount"));
                    edk::shape::Polygon2D poly;
                    //READ the polygons
                    for(edk::uint32 i=0u;i<size;i++){
                        poly.deletePolygon();
                        poly.readFromXML(xml,i);
                        //add the poly
                        this->addPolygon(poly);
                    }
                    ret=true;
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] nameID;
        }
        return ret;
    }
    return false;
}
bool edk::shape::Polygon2DList::cloneFrom(edk::shape::Polygon2DList* list){
    //delete the polygons
    this->cleanPolygons();
    if(list){
        //read the polygons
        register edk::uint32 size = list->polygons.size();
        edk::uint32 select=0u;
        edk::shape::Polygon2D* temp = NULL;
        for(edk::uint32 i=0u;i<size;i++){
            temp=list->polygons[i];
            if(temp){
                if(temp==list->selected){
                    select=i;
                }
                this->addPolygon(*temp);
            }
        }
        this->selectPolygon(select);
        return true;
    }
    return false;
}

//DRAW
//print the mesh
void edk::shape::Polygon2DList::printPolygons(){
    //print the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        //
        if(this->polygons.havePos(i)){
            //
            printf("\nPolygon %u"
                   ,i
                   );
            this->polygons[i]->print();
        }
    }
}

//draw the mesh
void edk::shape::Polygon2DList::drawPolygons(){
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        //
        if(this->polygons.havePos(i)){
            //
            this->polygons[i]->draw();
        }
    }
}
//draw the polygons in wireframe
void edk::shape::Polygon2DList::drawWirePolygons(){
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        //
        if(this->polygons.havePos(i)){
            //
            this->polygons[i]->drawWire();
        }
    }
}
void edk::shape::Polygon2DList::drawVertexs(edk::color3f32 color){
    edk::GU::guColor3f32(color);
    //draw the polygons
    for(edk::uint32 i=0u;i<this->polygons.size();i++){
        //
        if(this->polygons.havePos(i)){
            //
            this->polygons[i]->drawPolygonVertexs(edk::color4f32(color.r,color.g,color.b,1.f));
        }
    }
}

//Set to cant delete the polygon
void edk::shape::Polygon2DList::cantDeleteList(){
    this->canDeleteList=false;
    this->polygons.cantDestroy();
}
