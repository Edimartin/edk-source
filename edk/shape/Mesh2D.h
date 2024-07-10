#ifndef EDK_SHAPE_MESH2D_H
#define EDK_SHAPE_MESH2D_H

/*
Library Mesh2D - Draw a 2D Mesh in EDK Game Engine
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
#pragma message "Inside Mesh2D"
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
#include "../collision/MathCollision.h"
#include "../pack/FilePackage.h"

#ifdef printMessages
#pragma message "    Compiling Mesh2D"
#endif

//Mesh2D have the polygons and one texture

namespace edk{
namespace shape{
class Mesh2D: public edk::shape::AnimatedPolygon2DList{
    //number of textures
#define texturesCount 7u
    //distance definition to not have two vertexes in the same position
#define vertexDistanceIncrement 0.0001f
public:
    Mesh2D();
    virtual ~Mesh2D();

    void Constructor(bool runFather=true);
    //DELETE
    //clean Mesh
    void clean();
    //remove the rextures
    void cleanTextures();
    //remove the texture
    bool removeTexture(edk::uint32 position);

    //DRAW
    //print the mesh
    virtual void print();
    //draw the mesh
    //edk::uint32 position
    virtual void drawWithoutMaterial();
    virtual void drawNoTexture();
    virtual void drawOneTexture();
    virtual void drawOneTexture(edk::uint32 position);
    virtual bool selectedDrawOneTexture();
    virtual bool selectedDrawOneTexture(edk::uint32 position);
    virtual void drawMultiTexture();
    virtual bool selectedDrawMultiTexture();
    virtual void drawWire();
    virtual bool drawPolygonWithoutMaterial(edk::uint32 polygon);
    virtual bool drawPolygonNoTexture(edk::uint32 polygon);
    virtual bool drawPolygonOneTexture(edk::uint32 polygon);
    virtual bool drawPolygonOneTexture(edk::uint32 polygon, edk::uint32 position);
    virtual bool drawPolygonMultiTexture(edk::uint32 polygon);
    virtual bool drawPolygonWire(edk::uint32 polygon);

    bool triangularizateFromVertex(edk::vector::Stack<edk::vec2f32>* vertexes);
    bool triangularizateFromPolygon(edk::shape::Polygon2D polygon);
    bool putHoleInPolygon(edk::shape::Polygon2D outside,edk::shape::Polygon2D inside);
    bool putHoleInRectangle(edk::rectf32 rect,edk::shape::Polygon2D inside);

    //vertexTriangularization the mesh with the triangles
    static bool vertexTriangularization(edk::vector::Stack<edk::vec2f32>* vertexes,edk::shape::Mesh2D *mesh);
    static bool polygonTriangularization(edk::shape::Polygon2D polygon,edk::shape::Mesh2D *mesh);

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id);

    virtual bool cloneFrom(edk::shape::Mesh2D* mesh);

    //Material used for the mesh
    edk::material::Material material;
private:
    class AnimationDouble{
    public:
        AnimationDouble(edk::animation::Interpolation1DGroup* first,edk::uint32 id){
            this->classThis=NULL;edkEnd();
            this->Constructor(first,id,false);edkEnd();
        }
        virtual ~AnimationDouble(){
            if(this->classThis==this){
                this->classThis=NULL;edkEnd();
                //can destruct the class
            }
        }

        void Constructor(edk::animation::Interpolation1DGroup* first,edk::uint32 id,bool runFather=true){
            if(this->classThis!=this){
                this->classThis=this;
                if(runFather){edkEnd();}
                this->first = first;edkEnd();
                this->id=id;edkEnd();
            }
        }
        edk::animation::Interpolation1DGroup* first;
        edk::uint32 id;
    private:
        edk::classID classThis;
    };

    //class to save animations pointer
    class TreeAnimations: public edk::vector::BinaryTree<edk::shape::Mesh2D::AnimationDouble*>{
    public:
        TreeAnimations(){
            this->classThis=NULL;edkEnd();
            this->Constructor(false);edkEnd();
        }
        virtual ~TreeAnimations(){
            if(this->classThis==this){
                this->classThis=NULL;edkEnd();
                //can destruct the class
                this->cleanAllAnimations();edkEnd();
            }
        }

        void Constructor(bool runFather=true){
            if(runFather){
                edk::vector::BinaryTree<edk::shape::Mesh2D::AnimationDouble*>::Constructor();edkEnd();
            }
            if(this->classThis!=this){
                this->classThis=this;
            }
        }

        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::shape::Mesh2D::AnimationDouble* first,edk::shape::Mesh2D::AnimationDouble* second){
            if(first->first>second->first){
                return true;
            }
            return false;
        }
        virtual bool firstEqualSecond(edk::shape::Mesh2D::AnimationDouble* first,edk::shape::Mesh2D::AnimationDouble* second){
            if(first->first==second->first){
                return true;
            }
            return false;
        }

        //add the animations
        bool addAnimations(edk::animation::Interpolation1DGroup* first,edk::uint32 id){
            if(first){
                //test if have the first
                if(!this->haveAnimation(first)){
                    //create the new double
                    edk::shape::Mesh2D::AnimationDouble* temp = new edk::shape::Mesh2D::AnimationDouble(first,id);edkEnd();
                    if(temp){
                        //add the temp
                        if(this->add(temp)){
                            return true;
                        }
                        delete temp;edkEnd();
                    }
                }
            }
            return false;
        }
        //test if have the animation
        bool haveAnimation(edk::animation::Interpolation1DGroup* first){
            edk::shape::Mesh2D::AnimationDouble find(first,0u);edkEnd();
            return this->haveElement(&find);
        }
        //return the second animation
        edk::uint32 getAnimationID(edk::animation::Interpolation1DGroup* first){
            edk::shape::Mesh2D::AnimationDouble* temp = this->getDouble(first);edkEnd();
            if(temp){
                return temp->id;edkEnd();
            }
            return 0u;edkEnd();
        }
        //clean all animations
        void cleanAllAnimations(){
            edk::shape::Mesh2D::AnimationDouble* temp = NULL;edkEnd();
            edk::uint32 size = 0u;edkEnd();
            edk::uint32 position = 0u;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->getElementInPosition(position);edkEnd();
                if(temp){
                    this->remove(temp);edkEnd();
                    delete temp;edkEnd();
                }
                else{
                    position++;edkEnd();
                }
            }
        }

    private:
        //return the double
        edk::shape::Mesh2D::AnimationDouble* getDouble(edk::animation::Interpolation1DGroup* first){
            edk::shape::Mesh2D::AnimationDouble find(first,0u);edkEnd();
            return this->getElement(&find);
        }
    private:
        edk::classID classThis;
    };
private:
    //functions to vertex triangularization
    class TriangleValues{
    public:
        TriangleValues(edk::uint32 i,edk::uint32 j,edk::uint32 w){this->classThis=NULL;this->Constructor(i,j,w,false);edkEnd();}
        virtual ~TriangleValues(){
            if(this->classThis==this){
                this->classThis=NULL;edkEnd();
                //can destruct the class
            }
        }

        void Constructor(edk::uint32 i,edk::uint32 j,edk::uint32 w,bool runFather=true){
            if(runFather){edkEnd();}
            if(this->classThis!=this){
                this->classThis=this;
                this->i=i;edkEnd();
                this->j=j;edkEnd();
                this->k=w;edkEnd();
            }
        }
        edk::uint32 i,j,k;
    private:
        edk::classID classThis;
    };
    //binary tree with the triangle vertex positions in stack
    class treeTriangles:public edk::vector::BinaryTree<TriangleValues*>{
    public:
        //compare if the value is bigger
        bool firstBiggerSecond(TriangleValues* first,TriangleValues* second){
            if(first  &&  second){
                if(first->i>second->i){
                    return true;
                }
                else if(first->j>second->j){
                    return true;
                }
                else if(first->k>second->k){
                    return true;
                }
            }
            return false;
        }
        //compare if the value is equal
        bool firstEqualSecond(TriangleValues* first,TriangleValues* second){
            if(first&&second){
                if((first->i==second->i || first->i==second->j || first->i==second->k)
                        &&
                        (first->j==second->i || first->j==second->j || first->j==second->k)
                        &&
                        (first->k==second->i || first->k==second->j || first->k==second->k)
                        ){
                    return true;
                }
            }
            return false;
        }
        bool haveTriangle(edk::uint32 i,edk::uint32 j,edk::uint32 k){
            if(i != j && i != k && j != k){
                TriangleValues triangle(i,j,k);edkEnd();
                return this->haveElement(&triangle);edkEnd();
            }
            return false;
        }
        //add a new triangle
        bool newTriangle(edk::uint32 i,edk::uint32 j,edk::uint32 k){
            if(i != j && i != k && j != k){
                if(!this->haveTriangle(i,j,k)){
                    //create a new triangle
                    TriangleValues* temp = new TriangleValues(i,j,k);edkEnd();
                    if(temp){
                        if(this->add(temp)){
                            return true;
                        }
                        delete temp;edkEnd();
                    }
                }
            }
            return false;
        }
    };

    static inline bool floatDifferent(edk::float32 f1,edk::float32 f2);
    static bool pointInsideLine(edk::vec2f32 point,edk::vec2f32 lineStart,edk::vec2f32 lineEnd);

    edk::shape::Mesh2D operator=(edk::shape::Mesh2D mesh){
        //
        edk::shape::Mesh2D::TreeAnimations tree;edkEnd();

        //delete the polygons
        this->cleanPolygons();edkEnd();
        //read the polygons
        register edk::uint32 size = mesh.polygons.size();edkEnd();
        edk::uint32 select=0u;edkEnd();
        edk::shape::Polygon2D* temp = NULL;edkEnd();
        edk::uint32 id;edkEnd();
        edk::animation::Interpolation1DGroup* animTemp=NULL;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            //
            temp=mesh.polygons.get(i);edkEnd();
            if(temp){
                if(temp==mesh.selected){
                    select=i;edkEnd();
                }
                id=this->addPolygon(*temp);edkEnd();

                //test the animation
                animTemp = temp->framesGetAnimation();edkEnd();
                if(animTemp){
                    //test if already have the animation on the tree
                    if(tree.haveAnimation(animTemp)){
                        //set the animation to the polygon in the mesh
                        this->copyAnimationFramesToPolygon(tree.getAnimationID(animTemp),id);edkEnd();
                    }
                    else{
                        //add the animation on the tree
                        if(tree.addAnimations(animTemp,id)){
                            //create a new animation in the polygon
                            if(this->setAnimationFramesToPolygon(id)){
                                //copy the animation
                                this->copyThisAnimationFramesToPolygon(animTemp,id);edkEnd();
                            }
                        }
                    }
                }
            }
        }
        this->selectPolygon(select);edkEnd();
        //test if have animation selected
        if(mesh.haveSelectedAnimation()){
            //Set the ID of the animation selected
            this->selectAnimationFramesFromPolygon(mesh.getAnimationFramesSelectedID());edkEnd();
        }
        this->material = mesh.material;edkEnd();
        return mesh;edkEnd();
    }
private:
    edk::classID classThis;
};
}//end namespace shape
}//end namespace edk

#endif // MESH2D_H
