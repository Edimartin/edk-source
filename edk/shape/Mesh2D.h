#ifndef EDK_SHAPE_MESH2D_H
#define EDK_SHAPE_MESH2D_H

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
#warning "Inside Mesh2D"
#endif

#pragma once
#include "../vector/Stack.h"
#include "../vector/BinaryTree.h"
#include "Polygon2D.h"
#include "Rectangle2D.h"
#include "Triangle2D.h"
#include "Quadrangle2D.h"
//list of polygons
#include "AnimatedPolygon2DList.h"
#include "../Texture2DList.h"
#include "../material/Material.h"

#ifdef printMessages
#warning "    Compiling Mesh2D"
#endif

//Mesh2D have the polygons and one texture

namespace edk{
namespace shape{
class Mesh2D: public edk::shape::AnimatedPolygon2DList{
    //number of textures
#define texturesCount 7u
public:
    Mesh2D();
    virtual ~Mesh2D();
    //DELETE
    //remove the rextures
    void cleanTextures();
    //remove the texture
    bool removeTexture(edk::uint32 position);

    //DRAW
    //print the mesh
    virtual void print();
    //draw the mesh
    virtual void drawOneTexture();
    virtual void drawOneTextureWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
    edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
    bool lightIsOn[][EDK_LIGHT_LIMIT]);
    virtual void drawMultiTexture();
    virtual void drawMultiTextureWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
    edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
    bool lightIsOn[][EDK_LIGHT_LIMIT]);
    virtual void drawWire();

    void cantDeleteMesh();
    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

    //Material used for the mesh
    edk::material::Material material;

    edk::shape::Mesh2D operator=(edk::shape::Mesh2D mesh){
        //
        edk::shape::Mesh2D::TreeAnimations tree;

        //delete the polygons
        this->cleanPolygons();
        //read the polygons
        register edk::uint32 size = mesh.polygons.size();
        edk::uint32 select=0u;
        edk::shape::Polygon2D* temp = NULL;
        edk::uint32 id;
        edk::animation::Interpolation1DGroup* animTemp=NULL;
        for(edk::uint32 i=0u;i<size;i++){
            //
            temp=mesh.polygons[i];
            if(temp){
                if(temp==mesh.selected){
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
        if(mesh.haveSelectedAnimation()){
            //Set the ID of the animation selected
            this->selectAnimationFramesFromPolygon(mesh.getAnimationFramesSelectedID());
        }
        mesh.cantDeleteList();

        this->material = mesh.material;
        mesh.cantDeleteList();
        mesh.cantDeleteMesh();
        return mesh;
    }
private:
    bool canDeleteMesh;

    class AnimationDouble{
    public:
        AnimationDouble(edk::animation::Interpolation1DGroup* first,edk::uint32 id){}
        ~AnimationDouble(){}
        edk::animation::Interpolation1DGroup* first;
        edk::uint32 id;
    };

    //class to save animations pointer
    class TreeAnimations: public edk::vector::BinaryTree<edk::shape::Mesh2D::AnimationDouble*>{
    public:
        TreeAnimations(){
            //
        }
        ~TreeAnimations(){
            this->cleanAllAnimations();
        }
        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::shape::Mesh2D::AnimationDouble* first,edk::shape::Mesh2D::AnimationDouble* second){
            if(first->first>second->first)
                return true;
            return false;
        }
        virtual bool firstEqualSecond(edk::shape::Mesh2D::AnimationDouble* first,edk::shape::Mesh2D::AnimationDouble* second){
            if(first->first==second->first)
                return true;
            return false;
        }

        //add the animations
        bool addAnimations(edk::animation::Interpolation1DGroup* first,edk::uint32 id){
            if(first){
                //test if have the first
                if(!this->haveAnimation(first)){
                    //create the new double
                    edk::shape::Mesh2D::AnimationDouble* temp = new edk::shape::Mesh2D::AnimationDouble(first,id);
                    if(temp){
                        //add the temp
                        if(this->add(temp)){
                            return true;
                        }
                        delete temp;
                    }
                }
            }
            return false;
        }
        //test if have the animation
        bool haveAnimation(edk::animation::Interpolation1DGroup* first){
            edk::shape::Mesh2D::AnimationDouble find(first,0u);
            return this->haveElement(&find);
        }
        //return the second animation
        edk::uint32 getAnimationID(edk::animation::Interpolation1DGroup* first){
            edk::shape::Mesh2D::AnimationDouble* temp = this->getDouble(first);
            if(temp){
                return temp->id;
            }
            return 0u;
        }
        //clean all animations
        void cleanAllAnimations(){
            edk::shape::Mesh2D::AnimationDouble* temp = NULL;
            edk::uint32 size = 0u;
            edk::uint32 position = 0u;
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->getElementInPosition(position);
                if(temp){
                    this->remove(temp);
                    delete temp;
                }
                else{
                    position++;
                }
            }
        }

    private:
        //return the double
        edk::shape::Mesh2D::AnimationDouble* getDouble(edk::animation::Interpolation1DGroup* first){
            edk::shape::Mesh2D::AnimationDouble find(first,0u);
            return this->getElement(&find);
        }
    };
};
}//end namespace shape
}//end namespace edk

#endif // MESH2D_H
