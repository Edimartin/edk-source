#include "Mesh2D.h"

/*
Library Mesh2D - Draw a 2D Mesh in EDK Game Engine
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
#warning "            Inside Mesh2D.cpp"
#endif

edk::shape::Mesh2D::Mesh2D()
{
    //ctor
    this->polygons.clean(2u);
    //clean the selected
    this->freeSelected();
    this->canDeleteMesh=true;
}

edk::shape::Mesh2D::~Mesh2D()
{
    if(this->canDeleteMesh){
        this->cleanTextures();
    }
    else{
        this->material.cantDelete();
        this->cantDeleteList();
    }
    this->canDeleteMesh=true;
}
//remove the rextures
void edk::shape::Mesh2D::cleanTextures(){
    this->material.removeAllTextures();
}
//remove the texture
bool edk::shape::Mesh2D::removeTexture(edk::uint32 position){
    return this->material.removeTexture(position);
}

//DRAW
//print the mesh
void edk::shape::Mesh2D::print(){
    //
    this->printPolygons();
}
//draw the mesh
void edk::shape::Mesh2D::drawOneTexture(){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture();
        //Draw the mesh
        this->drawPolygons();

        this->material.drawEndWithTexture();
    }
    else{
        this->material.drawNoTexture();
        //else just draw the mesh
        this->drawPolygons();
    }
}
void edk::shape::Mesh2D::drawOneTexture(edk::uint32 position){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture(position);
        //Draw the mesh
        this->drawPolygons();

        this->material.drawEndWithTexture();
    }
    else{
        this->material.drawNoTexture();
        //else just draw the mesh
        this->drawPolygons();
    }
}
bool edk::shape::Mesh2D::selectedDrawOneTexture(){
    if(this->selected){
        //set the texture if have one
        if(this->material.haveTexture()){
            this->material.drawStartWithOneTexture();
            //Draw the polygon
            this->selected->draw();

            this->material.drawEndWithTexture();
        }
        else{
            this->material.drawNoTexture();
            //else just draw the polygon
            this->selected->draw();
        }
        return true;
    }
    return false;
}
bool edk::shape::Mesh2D::selectedDrawOneTexture(edk::uint32 position){
    if(this->selected){
        //set the texture if have one
        if(this->material.haveTexture()){
            this->material.drawStartWithOneTexture(position);
            //Draw the polygon
            this->selected->draw();

            this->material.drawEndWithTexture();
        }
        else{
            this->material.drawNoTexture();
            //else just draw the polygon
            this->selected->draw();
        }
        return true;
    }
    return false;
}

void edk::shape::Mesh2D::drawOneTextureWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
bool lightIsOn[][EDK_LIGHT_LIMIT]){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture();
        //Draw the mesh
        this->drawPolygonsWithLight(lightPositions,lightDirections,lightIsOn);

        this->material.drawEndWithTexture();
    }
    else{
        this->material.drawNoTexture();
        //else just draw the mesh
        this->drawPolygonsWithLight(lightPositions,lightDirections,lightIsOn);
    }
}
void edk::shape::Mesh2D::drawOneTextureWithLight(edk::uint32 position,edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
bool lightIsOn[][EDK_LIGHT_LIMIT]){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture(position);
        //Draw the mesh
        this->drawPolygonsWithLight(lightPositions,lightDirections,lightIsOn);

        this->material.drawEndWithTexture();
    }
    else{
        this->material.drawNoTexture();
        //else just draw the mesh
        this->drawPolygonsWithLight(lightPositions,lightDirections,lightIsOn);
    }
}
bool edk::shape::Mesh2D::SelectedDrawOneTextureWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
bool lightIsOn[][EDK_LIGHT_LIMIT]){
    if(this->selected){
        //set the texture if have one
        if(this->material.haveTexture()){
            this->material.drawStartWithOneTexture();
            //Draw the mesh
            this->selected->drawWithLight(lightPositions,lightDirections,lightIsOn);

            this->material.drawEndWithTexture();
        }
        else{
            this->material.drawNoTexture();
            //else just draw the mesh
            this->selected->drawWithLight(lightPositions,lightDirections,lightIsOn);
        }
        return true;
    }
    return false;
}
bool edk::shape::Mesh2D::SelectedDrawOneTextureWithLight(edk::uint32 position,edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
bool lightIsOn[][EDK_LIGHT_LIMIT]){
    if(this->selected){
        //set the texture if have one
        if(this->material.haveTexture()){
            this->material.drawStartWithOneTexture(position);
            //Draw the mesh
            this->selected->drawWithLight(lightPositions,lightDirections,lightIsOn);

            this->material.drawEndWithTexture();
        }
        else{
            this->material.drawNoTexture();
            //else just draw the mesh
            this->selected->drawWithLight(lightPositions,lightDirections,lightIsOn);
        }
        return true;
    }
    return false;
}

//draw the mesh
void edk::shape::Mesh2D::drawMultiTexture(){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithMultiTexture();
        //Draw the mesh
        this->drawPolygons();

        this->material.drawEndWithTexture();
    }
    else{
        this->material.drawNoTexture();
        //else just draw the mesh
        this->drawPolygons();
    }
}
bool edk::shape::Mesh2D::SelectedDrawMultiTexture(){
    if(this->selected){
        //set the texture if have one
        if(this->material.haveTexture()){
            this->material.drawStartWithMultiTexture();
            //Draw the mesh
            this->selected->draw();

            this->material.drawEndWithTexture();
        }
        else{
            this->material.drawNoTexture();
            //else just draw the mesh
            this->selected->draw();
        }
        return true;
    }
    return false;
}
void edk::shape::Mesh2D::drawMultiTextureWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
bool lightIsOn[][EDK_LIGHT_LIMIT]){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithMultiTexture();
        //Draw the mesh
        this->drawPolygonsWithLight(lightPositions,lightDirections,lightIsOn);

        this->material.drawEndWithTexture();
    }
    else{
        this->material.drawNoTexture();
        //else just draw the mesh
        this->drawPolygonsWithLight(lightPositions,lightDirections,lightIsOn);
    }
}
bool edk::shape::Mesh2D::SelectedDrawMultiTextureWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
bool lightIsOn[][EDK_LIGHT_LIMIT]){
    if(selected){
        //set the texture if have one
        if(this->material.haveTexture()){
            this->material.drawStartWithMultiTexture();
            //Draw the mesh
            this->selected->drawWithLight(lightPositions,lightDirections,lightIsOn);

            this->material.drawEndWithTexture();
        }
        else{
            this->material.drawNoTexture();
            //else just draw the mesh
            this->selected->drawWithLight(lightPositions,lightDirections,lightIsOn);
        }
        return true;
    }
    return false;
}
void edk::shape::Mesh2D::drawWire(){
    this->material.drawNoTexture();
    //else just draw the mesh
    this->drawWirePolygons();
}

void edk::shape::Mesh2D::cantDeleteMesh(){
    canDeleteMesh=false;
}
//XML
bool edk::shape::Mesh2D::writeToXML(edk::XML* xml,edk::uint32 id){
    if(edk::shape::Polygon2DList::writeToXML(xml,id)){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"mesh_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //write the material
                    this->material.writeToXML(xml,0u);
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
bool edk::shape::Mesh2D::readFromXML(edk::XML* xml,edk::uint32 id){
    if(edk::shape::Polygon2DList::readFromXML(xml,id)){
        bool ret=true;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"mesh_",nameID);
            if(name){
                //select the name
                if(xml->selectChild(name)){
                    //read the material
                    this->material.readFromXML(xml,0u);
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

bool edk::shape::Mesh2D::cloneFrom(edk::shape::Mesh2D* mesh){
    if(mesh){
        //
        edk::shape::Mesh2D::TreeAnimations tree;

        //delete the polygons
        this->cleanPolygons();
        //read the polygons
        register edk::uint32 size = mesh->polygons.size();
        edk::uint32 select=0u;
        edk::shape::Polygon2D* temp = NULL;
        edk::uint32 id;
        edk::animation::Interpolation1DGroup* animTemp=NULL;
        for(edk::uint32 i=0u;i<size;i++){
            //
            temp=mesh->polygons[i];
            if(temp){
                if(temp==mesh->selected){
                    select=i;
                }
                id=this->addPolygon(*temp);

                //test the animation
                animTemp = temp->framesGetAnimation();
                if(animTemp){
                    //test if already have the animation on the tree
                    if(tree.haveAnimation(animTemp)){
                        //set the animation to the polygon in the mesh
                        this->copyAnimationFramesToPolygon(tree.getAnimationID(animTemp),id);
                    }
                    else{
                        //add the animation on the tree
                        if(tree.addAnimations(animTemp,id)){
                            //create a new animation in the polygon
                            if(this->newAnimationFramesToPolygon(id)){
                                //copy the animation
                                this->copyThisAnimationFramesToPolygon(animTemp,id);
                            }
                        }
                    }
                }
            }
        }
        this->selectPolygon(select);
        //test if have animation selected
        if(mesh->haveSelectedAnimation()){
            //Set the ID of the animation selected
            this->selectAnimationFramesFromPolygon(mesh->getAnimationFramesSelectedID());
        }
        mesh->cantDeleteList();

        this->material = mesh->material;
        return true;
    }
    return false;
}
