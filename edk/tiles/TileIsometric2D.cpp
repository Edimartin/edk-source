#include "TileIsometric2D.h"

/*
Library TileIsometric2D -Tile to be used in a Isometric TimeSet.
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

edk::tiles::TileIsometric2D::TileIsometric2D(){
    this->classThis=NULL;
    this->Constructor();
}
edk::tiles::TileIsometric2D::~TileIsometric2D(){
    this->Destructor();
}

void edk::tiles::TileIsometric2D::Constructor(){
    edk::tiles::Tile2D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        //first remove the polygon in the mesh
        this->mesh.cleanPolygons();
        //create the new polygon
        edk::shape::Quadrangle2D lozenge;
        this->middle = edk::vec2f32(0,0);
        //Set the color to white
        lozenge.setPolygonColor(1,1,1,1);
        //Set all the quadrangle vertexs
        lozenge.setVertexPosition(0u,+0.0f,-0.25f);
        lozenge.setVertexPosition(1u,-0.5f,+0.0f);
        lozenge.setVertexPosition(2u,+0.0f,+0.25f);
        lozenge.setVertexPosition(3u,+0.5f,+0.0f);
        //set the UV'S
        lozenge.setVertexUV(0u,0.5f,0.25f);
        lozenge.setVertexUV(1u,0.0f,0.75f);
        lozenge.setVertexUV(2u,0.5f,0.75f);
        lozenge.setVertexUV(3u,0.0f,0.25f);
        //Use a lozengePolygon on the mesh
        this->mesh.addPolygon(lozenge);
        this->mesh.selectPolygon(0u);
    }
}
void edk::tiles::TileIsometric2D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
    edk::tiles::Tile2D::Destructor();
}

//return the type of the tile to the tileSet know witch tile is before delete it
edk::tiles::tile2DType edk::tiles::TileIsometric2D::getType(){
    return edk::tiles::tile2DTypeIsometric;
}

