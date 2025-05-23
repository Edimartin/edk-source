#include "Polygon2DContact.h"

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
#pragma message "            Inside Polygon2DContact.cpp"
#endif


edk::collision::Polygon2DContact::Polygon2DContact(){
    this->classThis=NULL;
    this->Constructor();
}
edk::collision::Polygon2DContact::~Polygon2DContact(){
    this->Destructor();
}

void edk::collision::Polygon2DContact::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::collision::Polygon2DContact::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
}
//calculate the vertexes
bool edk::collision::Polygon2DContact::pointsCalculateFromPolygonA(edk::shape::Polygon2D* polyA,
                                                                   edk::shape::Polygon2D* polyB,
                                                                   edk::vector::Stack<edk::shape::Vertex2DAnimatedUV>* aOutside,
                                                                   edk::vector::Stack<edk::shape::Vertex2DAnimatedUV>* aInside,
                                                                   edk::vector::Stack<edk::shape::Vertex2DAnimatedUV>* bOutside,
                                                                   edk::vector::Stack<edk::shape::Vertex2DAnimatedUV>* bInside,
                                                                   edk::vector::Stack<edk::collision::Polygon2DContact::ContactVertex>* newVertexesA,
                                                                   edk::vector::Stack<edk::collision::Polygon2DContact::ContactVertex>* newVertexesB
                                                                   ){
    //test if have the polygons and stacks
    if(polyA
            && polyB
            && aOutside
            && aInside
            && bOutside
            && bInside
            && newVertexesA
            && newVertexesB
            ){
        bool ret=false;
        //calculate if the lines internect creating new vertexes
        edk::uint32 sizeA = polyA->getVertexCount();
        edk::uint32 sizeB = polyB->getVertexCount();
        edk::collision::Vecs2f32 vecs;
        edk::collision::Polygon2DContact::ContactVertex vA,vB;
        edk::vec2f32 vec;
        edk::float32 percentA,percentB;
        edk::vec2f32 aStart,aEnd;
        edk::vec2f32 bStart,bEnd;
        edk::shape::Vertex2DAnimatedUV v;
        //type of the vertex
        //EDK_SHAPE_ANIMATED_UV
        //EDK_SHAPE_UV
        //EDK_SHAPE_NOUV
        for(edk::uint32 i=1u;i<=sizeA;i++){
            for(edk::uint32 j=1u;j<=sizeB;j++){
                aStart = polyA->getVertexPosition(i-1u);
                if(i==sizeA){
                    aEnd = polyA->getVertexPosition(0);
                }
                else{
                    aEnd = polyA->getVertexPosition(i);
                }
                bStart = polyB->getVertexPosition(j-1u);
                if(j==sizeB){
                    bEnd = polyB->getVertexPosition(0);
                }
                else{
                    bEnd = polyB->getVertexPosition(j);
                }
                if(edk::collision::MathCollision::straightStraight2D(aStart,
                                                                     aEnd,
                                                                     bStart,
                                                                     bEnd,
                                                                     &vecs
                                                                     )){
                    ret=true;
                    vec = vecs[0u];
                    //set the positions
                    vA.vec.position = vB.vec.position = vec;

                    //calculate the percent
                    percentA = edk::Math::pythagoras(vec - aStart)/edk::Math::pythagoras(aEnd - aStart);
                    percentB = edk::Math::pythagoras(vec - bStart)/edk::Math::pythagoras(bEnd - bStart);

                    //set the vA
                    vA.vec.color = (((polyA->getVertexColor(i)-polyA->getVertexColor(i-1u))*percentA)+polyA->getVertexColor(i-1u));
                    if(polyA->getVertexType(i-1u) == polyA->getVertexType(i)){
                        switch(polyA->getVertexType(i)){
                        case EDK_SHAPE_ANIMATED_UV:
                            vA.vec.setUV(((polyA->getVertexUV(i)-polyA->getVertexUV(i-1u))*percentA)+polyA->getVertexUV(i-1u));
                            vA.vec.setUVFrames(polyA->getFrames());
                            //set the vA
                            break;
                        case EDK_SHAPE_UV:
                            vA.vec.setUV(((polyA->getVertexUV(i)-polyA->getVertexUV(i-1u))*percentA)+polyA->getVertexUV(i-1u));
                            //set the vA
                            break;
                        }
                    }

                    //set the vB color
                    vB.vec.color = (((polyB->getVertexColor(i)-polyB->getVertexColor(i-1u))*percentB)+polyB->getVertexColor(i-1u));
                    if(polyB->getVertexType(i-1u) == polyB->getVertexType(i)){
                        switch(polyB->getVertexType(i)){
                        case EDK_SHAPE_ANIMATED_UV:
                            vB.vec.setUV(((polyB->getVertexUV(i)-polyB->getVertexUV(i-1u))*percentB)+polyB->getVertexUV(i-1u));
                            vB.vec.setUVFrames(polyB->getFrames());
                            //set the vB uv
                            break;
                        case EDK_SHAPE_UV:
                            vB.vec.setUV(((polyB->getVertexUV(i)-polyB->getVertexUV(i-1u))*percentB)+polyB->getVertexUV(i-1u));
                            //set the vB uv
                            break;
                        }
                    }

                    //copy the new vertex
                    newVertexesA->pushBack(vA);
                    newVertexesB->pushBack(vB);

                }
                vecs.clean();
            }
        }
        //test vertexes inside outside
        for(edk::uint32 i=0u;i<sizeA;i++){
            if(edk::collision::MathCollision::polygonPoint(*polyB,polyA->getVertexPosition(i))){
                //inside
                v.position = polyA->getVertexPosition(i);
                v.color = polyA->getVertexColor(i);
                v.setUV(polyA->getVertexUV(i));
                v.setUVFrames(polyA->getFrames());
                aInside->pushBack(v);
                ret=true;
            }
            else{
                //outside
                v.position = polyA->getVertexPosition(i);
                v.color = polyA->getVertexColor(i);
                v.setUV(polyA->getVertexUV(i));
                v.setUVFrames(polyA->getFrames());
                aOutside->pushBack(v);
            }
        }
        for(edk::uint32 i=0u;i<sizeB;i++){
            if(edk::collision::MathCollision::polygonPoint(*polyA,polyB->getVertexPosition(i))){
                //inside
                v.position = polyB->getVertexPosition(i);
                v.color = polyB->getVertexColor(i);
                v.setUV(polyB->getVertexUV(i));
                v.setUVFrames(polyB->getFrames());
                bInside->pushBack(v);
                ret=true;
            }
            else{
                //outside
                v.position = polyB->getVertexPosition(i);
                v.color = polyB->getVertexColor(i);
                v.setUV(polyB->getVertexUV(i));
                v.setUVFrames(polyB->getFrames());
                bOutside->pushBack(v);
            }
        }
        return ret;
    }
    return false;
}
bool edk::collision::Polygon2DContact::pointsCalculateFromPolygonA(edk::shape::Polygon2D* polyA,
                                                                   edk::shape::Polygon2D* polyB,
                                                                   edk::shape::Polygon2D* polyNewA
                                                                   ){
    //test if have the polygons and stacks
    if(polyA
            && polyB
            &&polyNewA
            ){
        bool ret = false;
        bool haveInter = false;
        //implement in the future
        //calculate if the lines internect creating new vertexes
        edk::uint32 sizeA = polyA->getVertexCount();
        edk::uint32 sizeB = polyB->getVertexCount();
        edk::uint32 size = polyB->getVertexCount();
        edk::collision::Vecs2f32 vecs;
        edk::vec2f32 vec;
        edk::float32 percent;
        edk::vec2f32 aStart,aEnd;
        edk::vec2f32 bStart,bEnd;
        edk::shape::Vertex2DAnimatedUV v;
        edk::vector::BinaryTree<edk::collision::Polygon2DContact::ContactVertex> tree;
        edk::collision::Polygon2DContact::ContactVertex node;
        //type of the vertex
        //EDK_SHAPE_ANIMATED_UV
        //EDK_SHAPE_UV
        //EDK_SHAPE_NOUV
        edk::vector::Stack<edk::shape::Vertex2DAnimatedUV> newA;
        edk::uint32 i=0u;
        edk::uint32 j=0u;
        edk::uint32 k=0u;
        edk::uint32 c=0u;

        //change the polygons to counterClockWise
        polyA->setCounterClockWise();
        polyB->setCounterClockWise();

        if(sizeA>2u && sizeB>2u){
            j=sizeB-1u;
            //test vertexes inside
            for(i=0u;i<sizeA;i++){
                vec = polyA->getVertexPosition(i);
                if(edk::collision::MathCollision::polygonPoint(*polyB,vec)){
                    //inside

                    //calculate the line collision
                    if(!i){
                        //
                        k=sizeA-1u;
                        //test if the point before are inside
                        vec = polyA->getVertexPosition(k);
                        if(edk::collision::MathCollision::polygonPoint(*polyB,vec)){
                            //search for the last vertex inside and the vertex outside
                            for(;i<sizeA;i++){
                                vec = polyA->getVertexPosition(i);
                                if(edk::collision::MathCollision::polygonPoint(*polyB,vec)){
                                    //
                                    v.position = polyA->getVertexPosition(i);
                                    v.color = polyA->getVertexColor(i);
                                    v.setUV(polyA->getVertexUV(i));
                                    v.setUVFrames(polyA->getFrames());
                                    newA.pushBack(v);
                                    ret=true;
                                }
                                else{

                                    if(i){
                                        k = i-1u;
                                    }
                                    else{
                                        k = sizeA-1u;
                                    }

                                    haveInter=false;

                                    do{
                                        aStart = polyA->getVertexPosition(k);
                                        aEnd = polyA->getVertexPosition(i);
                                        if(j<sizeB){
                                            bStart = polyB->getVertexPosition(j+1u);
                                        }
                                        else{
                                            bStart = polyB->getVertexPosition(0u);
                                        }
                                        bEnd = polyB->getVertexPosition(j);
                                        if(edk::collision::MathCollision::straightStraight2D(aStart,
                                                                                             aEnd,
                                                                                             bStart,
                                                                                             bEnd,
                                                                                             &vecs
                                                                                             )){
                                            ret=true;
                                            haveInter=true;
                                            vec = vecs[0u];
                                            //set the positions
                                            v.position = vec;

                                            //calculate the percent
                                            percent = edk::Math::pythagoras(vec - aStart)/edk::Math::pythagoras(aEnd - aStart);

                                            //set the vA
                                            v.color = (((polyA->getVertexColor(i)-polyA->getVertexColor(i-1u))*percent)+polyA->getVertexColor(i-1u));
                                            if(polyA->getVertexType(i-1u) == polyA->getVertexType(i)){
                                                switch(polyA->getVertexType(i)){
                                                case EDK_SHAPE_ANIMATED_UV:
                                                    v.setUV(((polyA->getVertexUV(i)-polyA->getVertexUV(i-1u))*percent)+polyA->getVertexUV(i-1u));
                                                    v.setUVFrames(polyA->getFrames());
                                                    //set the vA
                                                    break;
                                                case EDK_SHAPE_UV:
                                                    v.setUV(((polyA->getVertexUV(i)-polyA->getVertexUV(i-1u))*percent)+polyA->getVertexUV(i-1u));
                                                    //set the vA
                                                    break;
                                                }
                                            }

                                            //copy the new vertex
                                            newA.pushBack(v);

                                            break;
                                        }
                                        vecs.clean();
                                        if(j){
                                            j--;
                                        }
                                    }while(j);

                                    //add the outside vertex
                                    v.position = polyA->getVertexPosition(i);
                                    v.color = polyA->getVertexColor(i);
                                    v.setUV(polyA->getVertexUV(i));
                                    v.setUVFrames(polyA->getFrames());
                                    newA.pushBack(v);
                                    break;
                                }

                            }

                            continue;
                        }
                        //else calculate the intersection
                    }
                    else{
                        //
                        k=i-1u;
                    }

                    haveInter=false;
                    if(j){
                        do{
                            aStart = polyA->getVertexPosition(k);
                            aEnd = polyA->getVertexPosition(i);
                            bStart = polyB->getVertexPosition(j);
                            if(!j){
                                bEnd = polyB->getVertexPosition(sizeB-1u);
                            }
                            else{
                                bEnd = polyB->getVertexPosition(j-1u);
                            }
                            if(edk::collision::MathCollision::straightStraight2D(aStart,
                                                                                 aEnd,
                                                                                 bStart,
                                                                                 bEnd,
                                                                                 &vecs
                                                                                 )){
                                ret=true;
                                haveInter=true;
                                vec = vecs[0u];
                                //set the positions
                                v.position = vec;

                                //calculate the percent
                                percent = edk::Math::pythagoras(vec - aStart)/edk::Math::pythagoras(aEnd - aStart);

                                //set the vA
                                v.color = (((polyA->getVertexColor(i)-polyA->getVertexColor(i-1u))*percent)+polyA->getVertexColor(i-1u));
                                if(polyA->getVertexType(i-1u) == polyA->getVertexType(i)){
                                    switch(polyA->getVertexType(i)){
                                    case EDK_SHAPE_ANIMATED_UV:
                                        v.setUV(((polyA->getVertexUV(i)-polyA->getVertexUV(i-1u))*percent)+polyA->getVertexUV(i-1u));
                                        v.setUVFrames(polyA->getFrames());
                                        //set the vA
                                        break;
                                    case EDK_SHAPE_UV:
                                        v.setUV(((polyA->getVertexUV(i)-polyA->getVertexUV(i-1u))*percent)+polyA->getVertexUV(i-1u));
                                        //set the vA
                                        break;
                                    }
                                }

                                //copy the new vertex
                                newA.pushBack(v);

                                if(j){
                                    j--;
                                }
                                vecs.clean();
                                break;
                            }
                            vecs.clean();
                            if(j){
                                j--;
                            }
                        }while(j);
                    }

                    //test if find a intersection
                    if(haveInter){
                        //test if are not the last line
                        if(j){



                            //calculate if the b points are inside
                            do{
                                vec = polyB->getVertexPosition(j);
                                if(edk::collision::MathCollision::polygonPoint(*polyA,vec)){
                                    //inside
                                    v.position = polyB->getVertexPosition(j);
                                    v.color = polyB->getVertexColor(j);
                                    v.setUV(polyB->getVertexUV(j));
                                    v.setUVFrames(polyB->getFrames());
                                    newA.pushBack(v);
                                    ret=true;
                                }
                                else{

                                    //search for the last vertex inside and the vertex outside
                                    for(;i<sizeA;i++){
                                        vec = polyA->getVertexPosition(i);
                                        if(!edk::collision::MathCollision::polygonPoint(*polyB,vec)){

                                            if(i){
                                                k = i-1u;
                                            }
                                            else{
                                                k = sizeA-1u;
                                            }

                                            haveInter=false;

                                            do{
                                                aStart = polyA->getVertexPosition(k);
                                                aEnd = polyA->getVertexPosition(i);
                                                if(j<sizeB){
                                                    bStart = polyB->getVertexPosition(j+1u);
                                                }
                                                else{
                                                    bStart = polyB->getVertexPosition(0u);
                                                }
                                                bEnd = polyB->getVertexPosition(j);
                                                if(edk::collision::MathCollision::straightStraight2D(aStart,
                                                                                                     aEnd,
                                                                                                     bStart,
                                                                                                     bEnd,
                                                                                                     &vecs
                                                                                                     )){
                                                    ret=true;
                                                    haveInter=true;
                                                    vec = vecs[0u];
                                                    //set the positions
                                                    v.position = vec;

                                                    //calculate the percent
                                                    percent = edk::Math::pythagoras(vec - aStart)/edk::Math::pythagoras(aEnd - aStart);

                                                    //set the vA
                                                    v.color = (((polyA->getVertexColor(i)-polyA->getVertexColor(i-1u))*percent)+polyA->getVertexColor(i-1u));
                                                    if(polyA->getVertexType(i-1u) == polyA->getVertexType(i)){
                                                        switch(polyA->getVertexType(i)){
                                                        case EDK_SHAPE_ANIMATED_UV:
                                                            v.setUV(((polyA->getVertexUV(i)-polyA->getVertexUV(i-1u))*percent)+polyA->getVertexUV(i-1u));
                                                            v.setUVFrames(polyA->getFrames());
                                                            //set the vA
                                                            break;
                                                        case EDK_SHAPE_UV:
                                                            v.setUV(((polyA->getVertexUV(i)-polyA->getVertexUV(i-1u))*percent)+polyA->getVertexUV(i-1u));
                                                            //set the vA
                                                            break;
                                                        }
                                                    }

                                                    //copy the new vertex
                                                    newA.pushBack(v);

                                                    break;
                                                }
                                                vecs.clean();
                                                if(j){
                                                    j--;
                                                }
                                            }while(j>0u);

                                            //add the outside vertex
                                            v.position = polyA->getVertexPosition(i);
                                            v.color = polyA->getVertexColor(i);
                                            v.setUV(polyA->getVertexUV(i));
                                            v.setUVFrames(polyA->getFrames());
                                            newA.pushBack(v);
                                            break;
                                        }

                                    }
                                    break;
                                }
                                if(j){
                                    j--;
                                }
                            }while(j);
                        }
                    }

                    ret=true;
                }
                else{
                    //outside
                    v.position = polyA->getVertexPosition(i);
                    v.color = polyA->getVertexColor(i);
                    v.setUV(polyA->getVertexUV(i));
                    v.setUVFrames(polyA->getFrames());
                    newA.pushBack(v);
                    edk::uint32 posB=0u;

                    //test if the next vertex are inside
                    if(i<sizeA){
                        k = i+1u;
                    }
                    else{
                        k = 0u;
                    }
                    vec = polyA->getVertexPosition(k);
                    if(edk::collision::MathCollision::polygonPoint(*polyB,vec)){
                        //continue
                        continue;
                    }
                    else{
                        //test if the lineA have contact with the polyB
                        aStart = polyA->getVertexPosition(i);
                        aEnd = polyA->getVertexPosition(k);

                        //node,tree;
                        for(edk::uint32 b=0u;b<=sizeB;b++){
                            if(b==sizeB-1u){
                                c = 0u;
                            }
                            else{
                                c = b+1u;
                            }

                            //test the collision
                            bStart = polyB->getVertexPosition(b);
                            bEnd = polyB->getVertexPosition(c);
                            if(edk::collision::MathCollision::straightStraight2D(aStart,
                                                                                 aEnd,
                                                                                 bStart,
                                                                                 bEnd,
                                                                                 &vecs
                                                                                 )){
                                ret=true;
                                vec = vecs[0u];

                                //copy the vertex into the tree
                                //set the positions
                                node.vec.position = vec;

                                //calculate the percent
                                percent = edk::Math::pythagoras(vec - aStart)/edk::Math::pythagoras(aEnd - aStart);

                                //set the vA
                                node.vec.color = (((polyA->getVertexColor(i)-polyA->getVertexColor(i-1u))*percent)+polyA->getVertexColor(i-1u));
                                if(polyA->getVertexType(i-1u) == polyA->getVertexType(i)){
                                    switch(polyA->getVertexType(i)){
                                    case EDK_SHAPE_ANIMATED_UV:
                                        node.vec.setUV(((polyA->getVertexUV(i)-polyA->getVertexUV(i-1u))*percent)+polyA->getVertexUV(i-1u));
                                        node.vec.setUVFrames(polyA->getFrames());
                                        //set the vA
                                        break;
                                    case EDK_SHAPE_UV:
                                        node.vec.setUV(((polyA->getVertexUV(i)-polyA->getVertexUV(i-1u))*percent)+polyA->getVertexUV(i-1u));
                                        //set the vA
                                        break;
                                    }
                                }

                                node.posA.x = i;
                                node.posA.y = k;
                                node.posB.x = b;
                                node.posB.y = c;
                                node.distance = edk::Math::pythagoras(vec.x - aStart.x,vec.y - aStart.y);
                                node.position = posB++;
                                tree.add(node);
                            }
                            vecs.clean();
                        }
                        size = tree.size();
                        if(size){
                            edk::uint32 posStart;
                            edk::uint32 posEnd;
                            node = tree.getElementInPosition(0u);
                            for(edk::uint32 t=0u;t<size;t++){
                                //walk into the polygon

                                //add the collided vertex
                                newA.pushBack(node.vec);

                                if((t+1u)<size){
                                    posStart = node.posB.x;
                                    posEnd = node.posB.y;
                                    posB = node.position;
                                    node = tree.getElementInPosition(t+1u);

                                    if(posB<node.position){
                                        //increment
                                        posB = posEnd;

                                        if(posB>node.posB.x){
                                            //go into the last
                                            while(posB<sizeB){
                                                v.position = polyB->getVertexPosition(posB);
                                                v.color = polyB->getVertexColor(posB);
                                                v.setUV(polyB->getVertexUV(posB));
                                                v.setUVFrames(polyB->getFrames());
                                                newA.pushBack(v);
                                                ret=true;

                                                posB++;
                                            }
                                            posB=0u;
                                        }
                                        if(posB<node.posB.x){
                                            while(posB<=node.posB.x){
                                                v.position = polyB->getVertexPosition(posB);
                                                v.color = polyB->getVertexColor(posB);
                                                v.setUV(polyB->getVertexUV(posB));
                                                v.setUVFrames(polyB->getFrames());
                                                newA.pushBack(v);
                                                ret=true;

                                                posB++;
                                            }
                                        }
                                    }
                                    else{
                                        //decrement
                                        posB = posStart;

                                        if(posB<node.posB.y){
                                            //go into the first
                                            v.position = polyB->getVertexPosition(posB);
                                            v.color = polyB->getVertexColor(posB);
                                            v.setUV(polyB->getVertexUV(posB));
                                            v.setUVFrames(polyB->getFrames());
                                            newA.pushBack(v);
                                            ret=true;
                                            do{
                                                posB--;
                                                v.position = polyB->getVertexPosition(posB);
                                                v.color = polyB->getVertexColor(posB);
                                                v.setUV(polyB->getVertexUV(posB));
                                                v.setUVFrames(polyB->getFrames());
                                                newA.pushBack(v);
                                                ret=true;

                                            }while(posB);
                                            posB=sizeB-1u;
                                        }
                                        if(posB>node.posB.y){
                                            while(posB>node.posB.y){
                                                v.position = polyB->getVertexPosition(posB);
                                                v.color = polyB->getVertexColor(posB);
                                                v.setUV(polyB->getVertexUV(posB));
                                                v.setUVFrames(polyB->getFrames());
                                                newA.pushBack(v);
                                                ret=true;

                                                posB--;
                                            }
                                        }
                                        v.position = polyB->getVertexPosition(posB);
                                        v.color = polyB->getVertexColor(posB);
                                        v.setUV(polyB->getVertexUV(posB));
                                        v.setUVFrames(polyB->getFrames());
                                        newA.pushBack(v);
                                        ret=true;
                                    }
                                }
                            }
                        }
                        tree.clean();
                    }
                }
            }

            //test if DON'T create the polygon
            if(!ret){
                //test if the polygon B are inside the polygon A
                newA.clean();

                ret=true;
                edk::uint32 closerPos = 0u;
                edk::float32 closer = edk::Math::pythagoras(polyB->getVertexPosition(0u)-polyA->getVertexPosition(0u));
                edk::float32 newCloser;
                for(i=0u;i<sizeB;i++){
                    vec = polyB->getVertexPosition(i);
                    if(!edk::collision::MathCollision::polygonPoint(*polyA,vec)){
                        ret=false;
                    }
                    if(i){
                        //calculate the new closer
                        newCloser = edk::Math::pythagoras(polyB->getVertexPosition(j)-polyA->getVertexPosition(0u));
                        if(closer>newCloser){
                            closer=newCloser;
                            closerPos = j;
                        }
                    }
                }
                if(ret){
                    //Then copy the vertexes from outside to inside
                    for(i=0u;i<=sizeA;i++){
                        if(i==sizeA){
                            i=0u;
                            v.position = polyA->getVertexPosition(i);
                            v.color = polyA->getVertexColor(i);
                            v.setUV(polyA->getVertexUV(i));
                            v.setUVFrames(polyA->getFrames());
                            newA.pushBack(v);

                            //copy the polyB vertexes
                            j=closerPos;
                            do{
                                v.position = polyB->getVertexPosition(j);
                                v.color = polyB->getVertexColor(j);
                                v.setUV(polyB->getVertexUV(j));
                                v.setUVFrames(polyB->getFrames());
                                newA.pushBack(v);
                                if(j){
                                    j--;
                                }
                            }while(j);
                            j=sizeB-1u;
                            v.position = polyB->getVertexPosition(j);
                            v.color = polyB->getVertexColor(j);
                            v.setUV(polyB->getVertexUV(j));
                            v.setUVFrames(polyB->getFrames());
                            newA.pushBack(v);
                            while(j>closerPos){
                                if(j){
                                    j--;
                                }
                                v.position = polyB->getVertexPosition(j);
                                v.color = polyB->getVertexColor(j);
                                v.setUV(polyB->getVertexUV(j));
                                v.setUVFrames(polyB->getFrames());
                                newA.pushBack(v);
                            }
                            break;
                        }
                        else{
                            v.position = polyA->getVertexPosition(i);
                            v.color = polyA->getVertexColor(i);
                            v.setUV(polyA->getVertexUV(i));
                            v.setUVFrames(polyA->getFrames());
                            newA.pushBack(v);
                        }
                    }
                }
            }

            //in the end create the polygn if have vertexes
            sizeA = newA.size();
            if(sizeA){
                if(polyNewA->createPolygon(sizeA)){
                    for(i=0u;i<sizeA;i++){
                        v = newA.get(i);
                        polyNewA->setVertexPosition(i,v.position);
                        polyNewA->setVertexColor(i,v.color);
                        polyNewA->setVertexUV(i,v.getUV());
                    }
                    polyNewA->setPolygonMorphUVFrames(i,v.getUVFrames());
                }
            }
        }
        return ret;
    }
    return false;
}

//boolean with two polygons
bool edk::collision::Polygon2DContact::booleanAnotB(edk::shape::Polygon2D* polyA,edk::shape::Polygon2D* polyB,edk::shape::Polygon2D* polyDest){
    if(polyA && polyB && polyDest){
        bool ret = false;
        //test if the polygon have 2 vertexes
        if(polyA->getVertexCount() <= 2u){
            if(polyA->isRect()){
                if(polyB->getVertexCount() <= 2u){
                    if(polyB->isRect()){
                        edk::shape::Polygon2D newPolyA;
                        edk::shape::Polygon2D newPolyB;
                        if(newPolyA.createPolygon(4u) && newPolyB.createPolygon(4u)){
                            newPolyA.setVertexPosition(0u,polyA->getVertexPosition(0u).x,polyA->getVertexPosition(0u).y);
                            newPolyA.setVertexPosition(1u,polyA->getVertexPosition(1u).x,polyA->getVertexPosition(0u).y);
                            newPolyA.setVertexPosition(2u,polyA->getVertexPosition(1u).x,polyA->getVertexPosition(1u).y);
                            newPolyA.setVertexPosition(3u,polyA->getVertexPosition(0u).x,polyA->getVertexPosition(1u).y);
                            newPolyA.setVertexColor(0u,polyA->getVertexColor(0u));
                            newPolyA.setVertexColor(1u,polyA->getVertexColor(0u));
                            newPolyA.setVertexColor(2u,polyA->getVertexColor(1u));
                            newPolyA.setVertexColor(3u,polyA->getVertexColor(1u));
                            if(polyA->getVertexType(0u) == EDK_SHAPE_UV
                                    && polyA->getVertexType(1u) == EDK_SHAPE_UV
                                    ){
                                newPolyA.setVertexUV(0u,polyA->getVertexUV(0u).x,polyA->getVertexUV(0u).y);
                                newPolyA.setVertexUV(1u,polyA->getVertexUV(1u).x,polyA->getVertexUV(0u).y);
                                newPolyA.setVertexUV(2u,polyA->getVertexUV(1u).x,polyA->getVertexUV(1u).y);
                                newPolyA.setVertexUV(3u,polyA->getVertexUV(0u).x,polyA->getVertexUV(1u).y);
                            }
                            else if(polyA->getVertexType(0u) == EDK_SHAPE_ANIMATED_UV
                                    && polyA->getVertexType(1u) == EDK_SHAPE_ANIMATED_UV
                                    ){
                                newPolyA.setVertexUV(0u,polyA->getVertexUV(0u).x,polyA->getVertexUV(0u).y);
                                newPolyA.setVertexUV(1u,polyA->getVertexUV(1u).x,polyA->getVertexUV(0u).y);
                                newPolyA.setVertexUV(2u,polyA->getVertexUV(1u).x,polyA->getVertexUV(1u).y);
                                newPolyA.setVertexUV(3u,polyA->getVertexUV(0u).x,polyA->getVertexUV(1u).y);
                                newPolyA.setPolygonUVFrames(polyA->getFrames());
                            }
                            newPolyB.setVertexPosition(0u,polyB->getVertexPosition(0u).x,polyB->getVertexPosition(0u).y);
                            newPolyB.setVertexPosition(1u,polyB->getVertexPosition(1u).x,polyB->getVertexPosition(0u).y);
                            newPolyB.setVertexPosition(2u,polyB->getVertexPosition(1u).x,polyB->getVertexPosition(1u).y);
                            newPolyB.setVertexPosition(3u,polyB->getVertexPosition(0u).x,polyB->getVertexPosition(1u).y);
                            newPolyB.setVertexColor(0u,polyB->getVertexColor(0u));
                            newPolyB.setVertexColor(1u,polyB->getVertexColor(0u));
                            newPolyB.setVertexColor(2u,polyB->getVertexColor(1u));
                            newPolyB.setVertexColor(3u,polyB->getVertexColor(1u));
                            if(polyB->getVertexType(0u) == EDK_SHAPE_UV
                                    && polyB->getVertexType(1u) == EDK_SHAPE_UV
                                    ){
                                newPolyB.setVertexUV(0u,polyB->getVertexUV(0u).x,polyB->getVertexUV(0u).y);
                                newPolyB.setVertexUV(1u,polyB->getVertexUV(1u).x,polyB->getVertexUV(0u).y);
                                newPolyB.setVertexUV(2u,polyB->getVertexUV(1u).x,polyB->getVertexUV(1u).y);
                                newPolyB.setVertexUV(3u,polyB->getVertexUV(0u).x,polyB->getVertexUV(1u).y);
                            }
                            else if(polyB->getVertexType(0u) == EDK_SHAPE_ANIMATED_UV
                                    && polyB->getVertexType(1u) == EDK_SHAPE_ANIMATED_UV
                                    ){
                                newPolyB.setVertexUV(0u,polyB->getVertexUV(0u).x,polyB->getVertexUV(0u).y);
                                newPolyB.setVertexUV(1u,polyB->getVertexUV(1u).x,polyB->getVertexUV(0u).y);
                                newPolyB.setVertexUV(2u,polyB->getVertexUV(1u).x,polyB->getVertexUV(1u).y);
                                newPolyB.setVertexUV(3u,polyB->getVertexUV(0u).x,polyB->getVertexUV(1u).y);
                                newPolyB.setPolygonUVFrames(polyB->getFrames());
                            }
                            ret = edk::collision::Polygon2DContact::pointsCalculateFromPolygonA(&newPolyA,
                                                                                                &newPolyB,
                                                                                                polyDest
                                                                                                );
                        }
                    }
                }
                else{
                    edk::shape::Polygon2D newPolyA;
                    if(newPolyA.createPolygon(4u)){
                        newPolyA.setVertexPosition(0u,polyA->getVertexPosition(0u).x,polyA->getVertexPosition(0u).y);
                        newPolyA.setVertexPosition(1u,polyA->getVertexPosition(1u).x,polyA->getVertexPosition(0u).y);
                        newPolyA.setVertexPosition(2u,polyA->getVertexPosition(1u).x,polyA->getVertexPosition(1u).y);
                        newPolyA.setVertexPosition(3u,polyA->getVertexPosition(0u).x,polyA->getVertexPosition(1u).y);
                        newPolyA.setVertexColor(0u,polyA->getVertexColor(0u));
                        newPolyA.setVertexColor(1u,polyA->getVertexColor(0u));
                        newPolyA.setVertexColor(2u,polyA->getVertexColor(1u));
                        newPolyA.setVertexColor(3u,polyA->getVertexColor(1u));
                        if(polyA->getVertexType(0u) == EDK_SHAPE_UV
                                && polyA->getVertexType(1u) == EDK_SHAPE_UV
                                ){
                            newPolyA.setVertexUV(0u,polyA->getVertexUV(0u).x,polyA->getVertexUV(0u).y);
                            newPolyA.setVertexUV(1u,polyA->getVertexUV(1u).x,polyA->getVertexUV(0u).y);
                            newPolyA.setVertexUV(2u,polyA->getVertexUV(1u).x,polyA->getVertexUV(1u).y);
                            newPolyA.setVertexUV(3u,polyA->getVertexUV(0u).x,polyA->getVertexUV(1u).y);
                        }
                        else if(polyA->getVertexType(0u) == EDK_SHAPE_ANIMATED_UV
                                && polyA->getVertexType(1u) == EDK_SHAPE_ANIMATED_UV
                                ){
                            newPolyA.setVertexUV(0u,polyA->getVertexUV(0u).x,polyA->getVertexUV(0u).y);
                            newPolyA.setVertexUV(1u,polyA->getVertexUV(1u).x,polyA->getVertexUV(0u).y);
                            newPolyA.setVertexUV(2u,polyA->getVertexUV(1u).x,polyA->getVertexUV(1u).y);
                            newPolyA.setVertexUV(3u,polyA->getVertexUV(0u).x,polyA->getVertexUV(1u).y);
                            newPolyA.setPolygonUVFrames(polyA->getFrames());
                        }
                        ret = edk::collision::Polygon2DContact::pointsCalculateFromPolygonA(&newPolyA,
                                                                                            polyB,
                                                                                            polyDest
                                                                                            );
                    }
                }
            }
        }
        else{
            if(polyB->getVertexCount() <= 2u){if(polyB->isRect()){
                    edk::shape::Polygon2D newPolyB;
                    if(newPolyB.createPolygon(4u)){
                        newPolyB.setVertexPosition(0u,polyB->getVertexPosition(0u).x,polyB->getVertexPosition(0u).y);
                        newPolyB.setVertexPosition(1u,polyB->getVertexPosition(1u).x,polyB->getVertexPosition(0u).y);
                        newPolyB.setVertexPosition(2u,polyB->getVertexPosition(1u).x,polyB->getVertexPosition(1u).y);
                        newPolyB.setVertexPosition(3u,polyB->getVertexPosition(0u).x,polyB->getVertexPosition(1u).y);
                        newPolyB.setVertexColor(0u,polyB->getVertexColor(0u));
                        newPolyB.setVertexColor(1u,polyB->getVertexColor(0u));
                        newPolyB.setVertexColor(2u,polyB->getVertexColor(1u));
                        newPolyB.setVertexColor(3u,polyB->getVertexColor(1u));
                        if(polyB->getVertexType(0u) == EDK_SHAPE_UV
                                && polyB->getVertexType(1u) == EDK_SHAPE_UV
                                ){
                            newPolyB.setVertexUV(0u,polyB->getVertexUV(0u).x,polyB->getVertexUV(0u).y);
                            newPolyB.setVertexUV(1u,polyB->getVertexUV(1u).x,polyB->getVertexUV(0u).y);
                            newPolyB.setVertexUV(2u,polyB->getVertexUV(1u).x,polyB->getVertexUV(1u).y);
                            newPolyB.setVertexUV(3u,polyB->getVertexUV(0u).x,polyB->getVertexUV(1u).y);
                        }
                        else if(polyB->getVertexType(0u) == EDK_SHAPE_ANIMATED_UV
                                && polyB->getVertexType(1u) == EDK_SHAPE_ANIMATED_UV
                                ){
                            newPolyB.setVertexUV(0u,polyB->getVertexUV(0u).x,polyB->getVertexUV(0u).y);
                            newPolyB.setVertexUV(1u,polyB->getVertexUV(1u).x,polyB->getVertexUV(0u).y);
                            newPolyB.setVertexUV(2u,polyB->getVertexUV(1u).x,polyB->getVertexUV(1u).y);
                            newPolyB.setVertexUV(3u,polyB->getVertexUV(0u).x,polyB->getVertexUV(1u).y);
                            newPolyB.setPolygonUVFrames(polyB->getFrames());
                        }
                        ret = edk::collision::Polygon2DContact::pointsCalculateFromPolygonA(polyA,
                                                                                            &newPolyB,
                                                                                            polyDest
                                                                                            );
                    }
                }
            }
            else{
                ret = edk::collision::Polygon2DContact::pointsCalculateFromPolygonA(polyA,
                                                                                    polyB,
                                                                                    polyDest
                                                                                    );
            }
        }
        if(ret && polyDest->getVertexCount()){

            //print the vertexes
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);
            //polyDest->print();
            //fflush(stdout);

            return true;
        }
    }
    return false;
}

bool edk::collision::Polygon2DContact::boolean(edk::shape::Polygon2D* polyA,edk::shape::Polygon2D* polyB,edk::shape::Polygon2D* polyDest,edk::collision::TypesBoolean type){
    if(polyA && polyB && polyDest){
        edk::vector::Stack<edk::shape::Vertex2DAnimatedUV> aOutside;
        edk::vector::Stack<edk::shape::Vertex2DAnimatedUV> aInside;
        edk::vector::Stack<edk::shape::Vertex2DAnimatedUV> bOutside;
        edk::vector::Stack<edk::shape::Vertex2DAnimatedUV> bInside;
        edk::vector::Stack<edk::collision::Polygon2DContact::ContactVertex> newVertexesA;
        edk::vector::Stack<edk::collision::Polygon2DContact::ContactVertex> newVertexesB;
        bool ret = false;
        //test if the polygon have 2 vertexes
        if(polyA->getVertexCount() <= 2u){
            if(polyA->isRect()){
                if(polyB->getVertexCount() <= 2u){
                    if(polyB->isRect()){
                        edk::shape::Polygon2D newPolyA;
                        edk::shape::Polygon2D newPolyB;
                        if(newPolyA.createPolygon(4u) && newPolyB.createPolygon(4u)){
                            newPolyA.setVertexPosition(0u,polyA->getVertexPosition(0u).x,polyA->getVertexPosition(0u).y);
                            newPolyA.setVertexPosition(1u,polyA->getVertexPosition(1u).x,polyA->getVertexPosition(0u).y);
                            newPolyA.setVertexPosition(2u,polyA->getVertexPosition(1u).x,polyA->getVertexPosition(1u).y);
                            newPolyA.setVertexPosition(3u,polyA->getVertexPosition(0u).x,polyA->getVertexPosition(1u).y);
                            newPolyA.setVertexColor(0u,polyA->getVertexColor(0u));
                            newPolyA.setVertexColor(1u,polyA->getVertexColor(0u));
                            newPolyA.setVertexColor(2u,polyA->getVertexColor(1u));
                            newPolyA.setVertexColor(3u,polyA->getVertexColor(1u));
                            if(polyA->getVertexType(0u) == EDK_SHAPE_UV
                                    && polyA->getVertexType(1u) == EDK_SHAPE_UV
                                    ){
                                newPolyA.setVertexUV(0u,polyA->getVertexUV(0u).x,polyA->getVertexUV(0u).y);
                                newPolyA.setVertexUV(1u,polyA->getVertexUV(1u).x,polyA->getVertexUV(0u).y);
                                newPolyA.setVertexUV(2u,polyA->getVertexUV(1u).x,polyA->getVertexUV(1u).y);
                                newPolyA.setVertexUV(3u,polyA->getVertexUV(0u).x,polyA->getVertexUV(1u).y);
                            }
                            else if(polyA->getVertexType(0u) == EDK_SHAPE_ANIMATED_UV
                                    && polyA->getVertexType(1u) == EDK_SHAPE_ANIMATED_UV
                                    ){
                                newPolyA.setVertexUV(0u,polyA->getVertexUV(0u).x,polyA->getVertexUV(0u).y);
                                newPolyA.setVertexUV(1u,polyA->getVertexUV(1u).x,polyA->getVertexUV(0u).y);
                                newPolyA.setVertexUV(2u,polyA->getVertexUV(1u).x,polyA->getVertexUV(1u).y);
                                newPolyA.setVertexUV(3u,polyA->getVertexUV(0u).x,polyA->getVertexUV(1u).y);
                                newPolyA.setPolygonUVFrames(polyA->getFrames());
                            }
                            newPolyB.setVertexPosition(0u,polyB->getVertexPosition(0u).x,polyB->getVertexPosition(0u).y);
                            newPolyB.setVertexPosition(1u,polyB->getVertexPosition(1u).x,polyB->getVertexPosition(0u).y);
                            newPolyB.setVertexPosition(2u,polyB->getVertexPosition(1u).x,polyB->getVertexPosition(1u).y);
                            newPolyB.setVertexPosition(3u,polyB->getVertexPosition(0u).x,polyB->getVertexPosition(1u).y);
                            newPolyB.setVertexColor(0u,polyB->getVertexColor(0u));
                            newPolyB.setVertexColor(1u,polyB->getVertexColor(0u));
                            newPolyB.setVertexColor(2u,polyB->getVertexColor(1u));
                            newPolyB.setVertexColor(3u,polyB->getVertexColor(1u));
                            if(polyB->getVertexType(0u) == EDK_SHAPE_UV
                                    && polyB->getVertexType(1u) == EDK_SHAPE_UV
                                    ){
                                newPolyB.setVertexUV(0u,polyB->getVertexUV(0u).x,polyB->getVertexUV(0u).y);
                                newPolyB.setVertexUV(1u,polyB->getVertexUV(1u).x,polyB->getVertexUV(0u).y);
                                newPolyB.setVertexUV(2u,polyB->getVertexUV(1u).x,polyB->getVertexUV(1u).y);
                                newPolyB.setVertexUV(3u,polyB->getVertexUV(0u).x,polyB->getVertexUV(1u).y);
                            }
                            else if(polyB->getVertexType(0u) == EDK_SHAPE_ANIMATED_UV
                                    && polyB->getVertexType(1u) == EDK_SHAPE_ANIMATED_UV
                                    ){
                                newPolyB.setVertexUV(0u,polyB->getVertexUV(0u).x,polyB->getVertexUV(0u).y);
                                newPolyB.setVertexUV(1u,polyB->getVertexUV(1u).x,polyB->getVertexUV(0u).y);
                                newPolyB.setVertexUV(2u,polyB->getVertexUV(1u).x,polyB->getVertexUV(1u).y);
                                newPolyB.setVertexUV(3u,polyB->getVertexUV(0u).x,polyB->getVertexUV(1u).y);
                                newPolyB.setPolygonUVFrames(polyB->getFrames());
                            }
                            ret = edk::collision::Polygon2DContact::pointsCalculateFromPolygonA(&newPolyA,
                                                                                                &newPolyB,
                                                                                                &aOutside,
                                                                                                &aInside,
                                                                                                &bOutside,
                                                                                                &bInside,
                                                                                                &newVertexesA,
                                                                                                &newVertexesB
                                                                                                );
                        }
                    }
                }
                else{
                    edk::shape::Polygon2D newPolyA;
                    if(newPolyA.createPolygon(4u)){
                        newPolyA.setVertexPosition(0u,polyA->getVertexPosition(0u).x,polyA->getVertexPosition(0u).y);
                        newPolyA.setVertexPosition(1u,polyA->getVertexPosition(1u).x,polyA->getVertexPosition(0u).y);
                        newPolyA.setVertexPosition(2u,polyA->getVertexPosition(1u).x,polyA->getVertexPosition(1u).y);
                        newPolyA.setVertexPosition(3u,polyA->getVertexPosition(0u).x,polyA->getVertexPosition(1u).y);
                        newPolyA.setVertexColor(0u,polyA->getVertexColor(0u));
                        newPolyA.setVertexColor(1u,polyA->getVertexColor(0u));
                        newPolyA.setVertexColor(2u,polyA->getVertexColor(1u));
                        newPolyA.setVertexColor(3u,polyA->getVertexColor(1u));
                        if(polyA->getVertexType(0u) == EDK_SHAPE_UV
                                && polyA->getVertexType(1u) == EDK_SHAPE_UV
                                ){
                            newPolyA.setVertexUV(0u,polyA->getVertexUV(0u).x,polyA->getVertexUV(0u).y);
                            newPolyA.setVertexUV(1u,polyA->getVertexUV(1u).x,polyA->getVertexUV(0u).y);
                            newPolyA.setVertexUV(2u,polyA->getVertexUV(1u).x,polyA->getVertexUV(1u).y);
                            newPolyA.setVertexUV(3u,polyA->getVertexUV(0u).x,polyA->getVertexUV(1u).y);
                        }
                        else if(polyA->getVertexType(0u) == EDK_SHAPE_ANIMATED_UV
                                && polyA->getVertexType(1u) == EDK_SHAPE_ANIMATED_UV
                                ){
                            newPolyA.setVertexUV(0u,polyA->getVertexUV(0u).x,polyA->getVertexUV(0u).y);
                            newPolyA.setVertexUV(1u,polyA->getVertexUV(1u).x,polyA->getVertexUV(0u).y);
                            newPolyA.setVertexUV(2u,polyA->getVertexUV(1u).x,polyA->getVertexUV(1u).y);
                            newPolyA.setVertexUV(3u,polyA->getVertexUV(0u).x,polyA->getVertexUV(1u).y);
                            newPolyA.setPolygonUVFrames(polyA->getFrames());
                        }
                        ret = edk::collision::Polygon2DContact::pointsCalculateFromPolygonA(&newPolyA,
                                                                                            polyB,
                                                                                            &aOutside,
                                                                                            &aInside,
                                                                                            &bOutside,
                                                                                            &bInside,
                                                                                            &newVertexesA,
                                                                                            &newVertexesB
                                                                                            );
                    }
                }
            }
        }
        else{
            if(polyB->getVertexCount() <= 2u){if(polyB->isRect()){
                    edk::shape::Polygon2D newPolyB;
                    if(newPolyB.createPolygon(4u)){
                        newPolyB.setVertexPosition(0u,polyB->getVertexPosition(0u).x,polyB->getVertexPosition(0u).y);
                        newPolyB.setVertexPosition(1u,polyB->getVertexPosition(1u).x,polyB->getVertexPosition(0u).y);
                        newPolyB.setVertexPosition(2u,polyB->getVertexPosition(1u).x,polyB->getVertexPosition(1u).y);
                        newPolyB.setVertexPosition(3u,polyB->getVertexPosition(0u).x,polyB->getVertexPosition(1u).y);
                        newPolyB.setVertexColor(0u,polyB->getVertexColor(0u));
                        newPolyB.setVertexColor(1u,polyB->getVertexColor(0u));
                        newPolyB.setVertexColor(2u,polyB->getVertexColor(1u));
                        newPolyB.setVertexColor(3u,polyB->getVertexColor(1u));
                        if(polyB->getVertexType(0u) == EDK_SHAPE_UV
                                && polyB->getVertexType(1u) == EDK_SHAPE_UV
                                ){
                            newPolyB.setVertexUV(0u,polyB->getVertexUV(0u).x,polyB->getVertexUV(0u).y);
                            newPolyB.setVertexUV(1u,polyB->getVertexUV(1u).x,polyB->getVertexUV(0u).y);
                            newPolyB.setVertexUV(2u,polyB->getVertexUV(1u).x,polyB->getVertexUV(1u).y);
                            newPolyB.setVertexUV(3u,polyB->getVertexUV(0u).x,polyB->getVertexUV(1u).y);
                        }
                        else if(polyB->getVertexType(0u) == EDK_SHAPE_ANIMATED_UV
                                && polyB->getVertexType(1u) == EDK_SHAPE_ANIMATED_UV
                                ){
                            newPolyB.setVertexUV(0u,polyB->getVertexUV(0u).x,polyB->getVertexUV(0u).y);
                            newPolyB.setVertexUV(1u,polyB->getVertexUV(1u).x,polyB->getVertexUV(0u).y);
                            newPolyB.setVertexUV(2u,polyB->getVertexUV(1u).x,polyB->getVertexUV(1u).y);
                            newPolyB.setVertexUV(3u,polyB->getVertexUV(0u).x,polyB->getVertexUV(1u).y);
                            newPolyB.setPolygonUVFrames(polyB->getFrames());
                        }
                        ret = edk::collision::Polygon2DContact::pointsCalculateFromPolygonA(polyA,
                                                                                            &newPolyB,
                                                                                            &aOutside,
                                                                                            &aInside,
                                                                                            &bOutside,
                                                                                            &bInside,
                                                                                            &newVertexesA,
                                                                                            &newVertexesB
                                                                                            );
                    }
                }
            }
            else{
                ret = edk::collision::Polygon2DContact::pointsCalculateFromPolygonA(polyA,
                                                                                    polyB,
                                                                                    &aOutside,
                                                                                    &aInside,
                                                                                    &bOutside,
                                                                                    &bInside,
                                                                                    &newVertexesA,
                                                                                    &newVertexesB
                                                                                    );
            }
        }
        if(ret){
            //print the vertexes

            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            //printf("\naOutside %u",aOutside.size());fflush(stdout);
            //printf("\naInside %u",aInside.size());fflush(stdout);
            //printf("\nbOutside %u",bOutside.size());fflush(stdout);
            //printf("\nbInside %u",bInside.size());fflush(stdout);
            //printf("\nnewVertexesA %u",newVertexesA.size());fflush(stdout);
            //printf("\nnewVertexesB %u",newVertexesB.size());fflush(stdout);

            switch(type){
            case edk::collision::TypeBooleanUnion:
                break;
            case edk::collision::typeBooleanDifference:
                break;
            case edk::collision::typeBooleanIntersection:
                break;
            case edk::collision::typeBooleanExclusion:
                break;
            case edk::collision::typeBooleanDivision:
                break;
            default:
                ret=false;
                break;
            }
        }
    }
    return false;
}
