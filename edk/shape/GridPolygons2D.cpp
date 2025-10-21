#include "GridPolygons2D.h"

/*
Library GridPolygons2D - Grid in the 2D world drawing polygons by ID.
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
#pragma message "            Inside GridPolygons2D.cpp"
#endif

edk::shape::GridPolygons2D::GridPolygons2D(){
    this->classThis=NULL;
    this->Constructor();
}
edk::shape::GridPolygons2D::~GridPolygons2D(){
    this->Destructor();
}

void edk::shape::GridPolygons2D::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        edk::shape::GridLines2D::Constructor();

        edk::shape::Mesh2D* mesh = this->obj.newMesh();
        if(mesh){
            edk::shape::Rectangle2D rect;
            mesh->addPolygon(rect);
        }

        this->stack.pushBack(edk::color4f32(0.f,0.f,0.f,0.f));
    }
}
void edk::shape::GridPolygons2D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        edk::shape::GridLines2D::Destructor();

        this->obj.clean();

        this->stack.clean();
        this->tree.clean();
    }
}

//create a new matrix
bool edk::shape::GridPolygons2D::newMatrix(edk::size2ui32 size){
    return this->mat.createMatrix(size.width,size.height);
}
bool edk::shape::GridPolygons2D::newMatrix(edk::uint32 width,edk::uint32 height){
    return this->newMatrix(edk::size2ui32(width,height));
}

edk::size2ui32 edk::shape::GridPolygons2D::getMatrixSize(){
    return this->mat.getSize();
}
edk::uint32 edk::shape::GridPolygons2D::getMatrixWidth(){
    return this->mat.getWidth();
}
edk::uint32 edk::shape::GridPolygons2D::getMatrixHeight(){
    return this->mat.getHeight();
}

//set color value in position
bool edk::shape::GridPolygons2D::setColor(edk::vec2ui32 position,edk::color4f32 color){
    //test if have the matrix
    if(this->mat.have(position)){
        //test if have the color in the list
        edk::shape::GridPolygons2D::ColorWithID newColor;
        newColor.color = color;
        if(this->tree.haveElement(newColor)){
            newColor = this->tree.getElement(newColor);
        }
        else{
            //else create a new color and add into the stack
            newColor.color = color;
            edk::uint32 size = this->stack.size();
            newColor.position = this->stack.pushBack(color);
            if(size>=this->stack.size()){
                return false;
            }
            //add the new color into the tree
            if(!this->tree.add(newColor)){
                return false;
            }
        }
        //set the value into the matrix
        return this->mat.set(position,newColor.position);
    }
    return false;
}
bool edk::shape::GridPolygons2D::setColor(edk::uint32 x,edk::uint32 y,edk::color4f32 color){
    return this->setColor(edk::vec2ui32(x,y),color);
}
bool edk::shape::GridPolygons2D::setColor(edk::vec2ui32 position,edk::float32 r,edk::float32 g,edk::float32 b){
    return this->setColor(position,edk::color4f32(r,g,b,1.f));
}
bool edk::shape::GridPolygons2D::setColor(edk::uint32 x,edk::uint32 y,edk::float32 r,edk::float32 g,edk::float32 b){
    return this->setColor(edk::vec2ui32(x,y),edk::color4f32(r,g,b,1.f));
}
bool edk::shape::GridPolygons2D::setColor(edk::vec2ui32 position,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setColor(position,edk::color4f32(r,g,b,a));
}
bool edk::shape::GridPolygons2D::setColor(edk::uint32 x,edk::uint32 y,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setColor(edk::vec2ui32(x,y),edk::color4f32(r,g,b,a));
}

//draw the grid
void edk::shape::GridPolygons2D::draw(){
    if(this->mat.haveMatrix()){
        //draw polygons
        edk::uint32 width = this->mat.getWidth(),height = this->mat.getHeight();
        this->obj.size = this->size;
        edk::vec2f32 newPosition = edk::vec2f32(this->size.width*-0.5*this->mat.getWidth(),
                                                this->size.height*-0.5*this->mat.getHeight()
                                                );
        edk::shape::Mesh2D* mesh = this->obj.getMesh(0u);
        edk::uint32 value=0u;
        edk::float32 newY=0.f;
        if(mesh){
            for(edk::uint32 y=0u;y<height;y++){
                newY = ((this->size.height*y*-1.f)+(this->size.height*(this->mat.getHeight()-1.f)));
                for(edk::uint32 x=0u;x<width;x++){

                    //get the matrixValue in position
                    value = this->mat.get(x,y);

                    if(value && this->stack.havePos(value)){
                        this->obj.position = edk::vec2f32(newPosition.x + (this->size.width*x),
                                                          newPosition.y + newY
                                                          );
                        mesh->setPolygonsColor(this->stack.get(value));
                        this->obj.drawWithoutMaterial();
                    }
                }
            }
        }

        //DRAW LINES
        edk::GU::guPushMatrix();
        edk::GU::guTranslate2f32(this->position);
        edk::GU::guRotateZf32(this->angle);

        edk::GU::guLineWidth(1u);

        edk::GU::guColor4f32(this->colorLines);

        //draw the lines
        edk::GU::guBegin(GU_LINES);
        //WIDTH
        this->p1=this->size.height*-0.5*this->mat.getHeight();
        this->p2=this->size.height*0.5*this->mat.getHeight();
        this->limit = this->size.width*0.5*this->mat.getWidth();
        for(this->i=this->size.width*-0.5*this->mat.getWidth();this->i<=this->limit;this->i+=this->size.width){
            edk::GU::guVertex2f32(this->i,this->p1);
            edk::GU::guVertex2f32(this->i,this->p2);
        }
        //HEIGHT
        this->p1=this->size.width*-0.5*this->mat.getWidth();
        this->p2=this->size.width*0.5*this->mat.getWidth();
        this->limit = this->size.height*0.5*this->mat.getHeight();
        for(this->i=this->size.height*-0.5*this->mat.getHeight();this->i<=this->limit;this->i+=this->size.height){
            edk::GU::guVertex2f32(this->p1,this->i);
            edk::GU::guVertex2f32(this->p2,this->i);
        }
        edk::GU::guEnd();

        edk::GU::guPopMatrix();
    }
}

void edk::shape::GridPolygons2D::drawSelection(){
    if(this->mat.haveMatrix()){
        //draw polygons
        edk::uint32 width = this->mat.getWidth(),height = this->mat.getHeight();
        this->obj.size = this->size;
        edk::vec2f32 newPosition = edk::vec2f32(this->size.width*-0.5*this->mat.getWidth(),
                                                this->size.height*-0.5*this->mat.getHeight()
                                                );
        edk::shape::Mesh2D* mesh = this->obj.getMesh(0u);
        edk::float32 newY=0.f;
        if(mesh){
            for(edk::uint32 y=0u;y<height;y++){
                newY = ((this->size.height*y*-1.f)+(this->size.height*(this->mat.getHeight()-1.f)));
                for(edk::uint32 x=0u;x<width;x++){
                    this->obj.position = edk::vec2f32(newPosition.x + (this->size.width*x),
                                                      newPosition.y + newY
                                                      );
                    mesh->setPolygonsColor(0.f,0.f,0.f,1.f);
                    edk::GU::guPushName(x);
                    edk::GU::guPushName(y);
                    this->obj.drawWithoutMaterial();
                    edk::GU::guPopName();
                    edk::GU::guPopName();
                }
            }
        }
    }
}
