#ifndef POLYGON2DCONTACT_H
#define POLYGON2DCONTACT_H

/*
Library Polygon2DContact - Teste collision between polygons in EDK
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
#pragma message "Inside Polygon2DContact"
#endif

#pragma once
#include "../TypeVec2.h"
#include "MathCollision.h"
#include "../shape/Polygon2D.h"

#ifdef printMessages
#pragma message "    Compiling Polygon2DContact"
#endif

namespace edk{
namespace collision{
enum TypesBoolean{
    TypeBooleanNone=0b10000000,
    TypeBooleanUnion,
    typeBooleanDifference,
    typeBooleanIntersection,
    typeBooleanExclusion,
    typeBooleanDivision,
    typeBooleanSize,
};
class Polygon2DContact{
public:
    Polygon2DContact();
    virtual ~Polygon2DContact();

    void Constructor(bool runFather=true);

    //boolean with two polygons
    static bool booleanAnotB(edk::shape::Polygon2D* polyA,edk::shape::Polygon2D* polyB,edk::shape::Polygon2D* polyDest);

    static bool boolean(edk::shape::Polygon2D* polyA,edk::shape::Polygon2D* polyB,edk::shape::Polygon2D* polyDest,edk::collision::TypesBoolean type);

private:
    class ContactVertex{
    public:
        ContactVertex(){this->classThis=NULL;this->Constructor(false); }
        virtual ~ContactVertex(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
            }
        }

        void Constructor(bool runFather=true){
            if(runFather){ }
            if(this->classThis!=this){
                this->classThis=this;

                this->vec.Constructor();edkEnd();
            }
        }
        edk::shape::Vertex2DAnimatedUV vec;
        edk::vec2ui32 posA;
        edk::vec2ui32 posB;
        edk::float32 distance;
        edk::uint32 position;

        ContactVertex operator=(ContactVertex vec){
            this->vec=vec.vec;
            this->posA=vec.posA;
            this->posB=vec.posB;
            this->distance=vec.distance;
            this->position=vec.position;
            return vec;
        }
        ContactVertex* operator=(ContactVertex* vec){
            this->vec=vec->vec;
            this->posA=vec->posA;
            this->posB=vec->posB;
            this->distance=vec->distance;
            this->position=vec->position;
            return this;
        }
        bool operator>(ContactVertex vec){
            return (this->distance>vec.distance);
        }
        bool operator<(ContactVertex vec){
            return (this->distance<vec.distance);
        }
        bool operator==(ContactVertex vec){
            return edk::Math::equal(this->distance,vec.distance);
        }
    private:
        edk::classID classThis;
    };
    //calculate the vertexes
    static bool pointsCalculateFromPolygonA(edk::shape::Polygon2D* polyA,
                                            edk::shape::Polygon2D* polyB,
                                            edk::vector::Stack<edk::shape::Vertex2DAnimatedUV>* aOutside,
                                            edk::vector::Stack<edk::shape::Vertex2DAnimatedUV>* aInside,
                                            edk::vector::Stack<edk::shape::Vertex2DAnimatedUV>* bOutside,
                                            edk::vector::Stack<edk::shape::Vertex2DAnimatedUV>* bInside,
                                            edk::vector::Stack<edk::collision::Polygon2DContact::ContactVertex>* newVertexesA,
                                            edk::vector::Stack<edk::collision::Polygon2DContact::ContactVertex>* newVertexesB
                                            );
    static bool pointsCalculateFromPolygonA(edk::shape::Polygon2D* polyA,
                                            edk::shape::Polygon2D* polyB,
                                            edk::shape::Polygon2D* polyNewA
                                            );
private:
    edk::classID classThis;
};
}//end namespace collision
}//end namespace edk

#endif // POLYGON2DCONTACT_H
