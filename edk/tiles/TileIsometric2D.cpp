#include "TileIsometric2D.h"

/*
Library TileIsometric2D -Tile to be used in a Isometric TimeSet.
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

edk::tiles::TileIsometric2D::TileIsometric2D(){
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
edk::tiles::TileIsometric2D::~TileIsometric2D(){
    //
}

//return the type of the tile to the tileSet know witch tile is before delete it
edk::tiles::tile2DType edk::tiles::TileIsometric2D::getType(){
    return edk::tiles::tile2DTypeIsometric;
}

