#include "PhysicObject2D.h"

/*
Library PhysicObject2D - Object used in 2D physics engine for EDK
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

namespace tempEDK{
namespace physics{
enum bodyType{
    StaticBody = 0u,
    KinematicBody,
    DynamicBody
};
}
}

edk::physics2D::PhysicObject2D::PhysicObject2D(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::physics2D::PhysicObject2D::~PhysicObject2D(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->physicMesh.cleanPolygons();edkEnd();
        this->physicMeshWorld.cleanPolygons();edkEnd();
        this->treeCollisionGroups.clean();edkEnd();
        this->treeNotCollisionGroups.clean();edkEnd();
    }
}

void edk::physics2D::PhysicObject2D::Constructor(bool runFather){
    if(runFather){
        edk::Object2D::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;

        this->physicMesh.Constructor();edkEnd();
        this->physicMeshWorld.Constructor();edkEnd();
        this->physicMatrixPosition.Constructor();edkEnd();
        this->physicMatrixPivo.Constructor();edkEnd();
        this->physicMatrixAngle.Constructor();edkEnd();
        this->physicMatrixSize.Constructor();edkEnd();
        this->physicMatrixTransform.Constructor();edkEnd();
        this->treeCollisionGroups.Constructor();edkEnd();
        this->treeNotCollisionGroups.Constructor();edkEnd();

        this->type=edk::TypeObject2DPhysic;
        this->fixedRotation=false;edkEnd();
        this->canSleep=false;edkEnd();
        this->isObjectSensor=false;edkEnd();

        this->speed=0.f;edkEnd();
        this->linearVelocity = edk::vec2f32(0,0);edkEnd();
        this->linearVelocitySetted=false;edkEnd();
        this->angularVelocity=0.f;edkEnd();
        this->angularVelocitySetted=false;edkEnd();
        this->direction = edk::vec2f32(0,0);edkEnd();

        this->functionDrawBoundingBoxPhysics = &edk::physics2D::PhysicObject2D::drawUnhideBoundingBoxPhysics;
        this->functionDrawWirePhysics = &edk::physics2D::PhysicObject2D::drawUnhideWirePhysics;
        this->functionDrawWirePhysicsWorld = &edk::physics2D::PhysicObject2D::drawUnhideWirePhysicsWorld;
    }
}

void edk::physics2D::PhysicObject2D::writeFatherBoundingBoxPhysic(edk::rectf32* rect,edk::vector::Matrixf32<3u,3u>* transformMat){
    if(this->father){
        //calculate the boundingBox from the father
        edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)this->father;
        if(this->father->getType()>= edk::TypeObject2DPhysic
                &&
                this->father->getType()<= edk::TypeObject2DKinematic
                ){
            temp->writeFatherBoundingBoxPhysic(rect,transformMat);
        }
        else if(this->father->getType()== edk::TypeObject2D){
            temp->writeFatherBoundingBox(rect,transformMat);
        }

        edk::Math::generateScaleMatrix(this->connectedSize,&this->physicMatrixSize);edkEnd();
        edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->physicMatrixAngle);edkEnd();
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->physicMatrixPosition);edkEnd();
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->physicMatrixPivo);edkEnd();
        transformMat->multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
        transformMat->multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
        transformMat->multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
        transformMat->multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();
        //translate
        transformMat->multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
        //angle
        transformMat->multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
        //scale
        transformMat->multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
        //Pivo
        transformMat->multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();
        //translate
        transformMat->multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
        //angle
        transformMat->multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
        //scale
        transformMat->multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
        //Pivo
        transformMat->multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();
    }
}
bool edk::physics2D::PhysicObject2D::writeBoundingBoxPhysic(edk::rectf32* rect){
    //multiply the matrix by
    this->physicMatrixTransform.setIdentity();edkEnd();
    if(this->father){
        //calculate the boundingBox from the father
        edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)this->father;
        if(this->father->getType()>= edk::TypeObject2DPhysic
                &&
                this->father->getType()<= edk::TypeObject2DKinematic
                ){
            temp->writeFatherBoundingBoxPhysic(rect,&this->physicMatrixTransform);
        }
        else if(this->father->getType()== edk::TypeObject2D){
            temp->writeFatherBoundingBox(rect,&this->physicMatrixTransform);
        }

        edk::Math::generateScaleMatrix(this->connectedSize,&this->physicMatrixSize);edkEnd();
        edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->physicMatrixAngle);edkEnd();
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->physicMatrixPosition);edkEnd();
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->physicMatrixPivo);edkEnd();
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();
        //translate
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
        //angle
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
        //scale
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
        //Pivo
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();
        //translate
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
        //angle
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
        //scale
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
        //Pivo
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();
    }

    if(this->physicMesh.getPolygonSize()){
        if(this->father){
            this->physicMesh.calculateBoundingBox(rect,&this->physicMatrixTransform);edkEnd();
        }
        else{
            *rect = this->physicMesh.generateBoundingBox(&this->physicMatrixTransform);edkEnd();
        }
    }
    else{
        //generate a small boundingBox
        rect->origin = this->position - 0.1f;
        rect->size = edk::size2f32(this->position.x + 0.1f,this->position.y + 0.1f);
    }
    return false;
}
bool edk::physics2D::PhysicObject2D::writeBoundingBoxPhysic(edk::rectf32* rect,edk::vector::Matrixf32<3u,3u>* transformMat){
    //first copy the matrix
    if(this->physicMatrixTransform.cloneFrom(transformMat)){
        if(this->father){
            //calculate the boundingBox from the father
            edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)this->father;
            if(this->father->getType()>= edk::TypeObject2DPhysic
                    &&
                    this->father->getType()<= edk::TypeObject2DKinematic
                    ){
                temp->writeFatherBoundingBoxPhysic(rect,&this->physicMatrixTransform);
            }
            else if(this->father->getType()== edk::TypeObject2D){
                temp->writeFatherBoundingBox(rect,&this->physicMatrixTransform);
            }

            edk::Math::generateScaleMatrix(this->connectedSize,&this->physicMatrixSize);edkEnd();
            edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->physicMatrixAngle);edkEnd();
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->physicMatrixPosition);edkEnd();
            edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->physicMatrixPivo);edkEnd();
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();

            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();
            //multiply the matrix by
            //translate
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
            //angle
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
            //scale
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
            //Pivo
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();
        }
        else{
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();
            //multiply the matrix by
            //translate
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
            //angle
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
            //scale
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
            //Pivo
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();
        }

        if(this->physicMesh.getPolygonSize()){
            if(this->father){
                *rect = this->physicMesh.generateBoundingBox(&this->physicMatrixTransform);edkEnd();
            }
            else{
                this->physicMesh.calculateBoundingBox(rect,&this->physicMatrixTransform);edkEnd();
            }
        }
        else{
            //generate a small boundingBox
            rect->origin = this->position - 0.1f;
            rect->size = edk::size2f32(this->position.x + 0.1f,this->position.y + 0.1f);
        }
    }
    return true;
}
bool edk::physics2D::PhysicObject2D::writeChildremBoundingBoxPhysic(edk::rectf32* rect){
    bool ret = false;
    //multiply the matrix by
    this->physicMatrixTransform.setIdentity();edkEnd();
    if(this->father){
        //calculate the boundingBox from the father
        edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)this->father;
        if(this->father->getType()>= edk::TypeObject2DPhysic
                &&
                this->father->getType()<= edk::TypeObject2DKinematic
                ){
            temp->writeFatherBoundingBoxPhysic(rect,&this->physicMatrixTransform);
        }
        else if(this->father->getType()== edk::TypeObject2D){
            temp->writeFatherBoundingBox(rect,&this->physicMatrixTransform);
        }

        edk::Math::generateScaleMatrix(this->connectedSize,&this->physicMatrixSize);edkEnd();
        edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->physicMatrixAngle);edkEnd();
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->physicMatrixPosition);edkEnd();
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->physicMatrixPivo);edkEnd();
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();

        //translate
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
        //angle
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
        //scale
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
        //Pivo
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();
        //translate
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
        //angle
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
        //scale
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
        //Pivo
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();
    }

    if(this->physicMesh.getPolygonSize()){
        if(this->father){
            this->physicMesh.calculateBoundingBox(rect,&this->physicMatrixTransform);edkEnd();
        }
        else{
            *rect = this->physicMesh.generateBoundingBox(&this->physicMatrixTransform);edkEnd();
        }
        ret = true;
    }
    else{
        //generate a small boundingBox
        rect->origin = this->position - 0.1f;
        rect->size = edk::size2f32(this->position.x + 0.1f,this->position.y + 0.1f);
    }
    return ret;
}
bool edk::physics2D::PhysicObject2D::writeChildremBoundingBoxPhysic(edk::rectf32* rect,edk::vector::Matrixf32<3u,3u>* transformMat){
    //first copy the matrix
    if(this->physicMatrixTransform.cloneFrom(transformMat)){
        if(this->father){
            //calculate the boundingBox from the father
            edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)this->father;
            if(this->father->getType()>= edk::TypeObject2DPhysic
                    &&
                    this->father->getType()<= edk::TypeObject2DKinematic
                    ){
                temp->writeBoundingBoxPhysic(rect,&this->physicMatrixTransform);
            }
            else if(this->father->getType()== edk::TypeObject2D){
                temp->writeBoundingBox(rect,&this->physicMatrixTransform);
            }

            edk::Math::generateScaleMatrix(this->connectedSize,&this->physicMatrixSize);edkEnd();
            edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->physicMatrixAngle);edkEnd();
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->physicMatrixPosition);edkEnd();
            edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->physicMatrixPivo);edkEnd();
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();


            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();
            //multiply the matrix by
            //translate
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
            //angle
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
            //scale
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
            //Pivo
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();
        }
        else{
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();
            //multiply the matrix by
            //translate
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
            //angle
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
            //scale
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
            //Pivo
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();
        }

        if(this->physicMesh.getPolygonSize()){
            if(this->father){
                *rect = this->physicMesh.generateBoundingBox(&this->physicMatrixTransform);edkEnd();
            }
            else{
                this->physicMesh.calculateBoundingBox(rect,&this->physicMatrixTransform);edkEnd();
            }
        }
        else{
            //generate a small boundingBox
            rect->origin = this->position - 0.1f;
            rect->size = edk::size2f32(this->position.x + 0.1f,this->position.y + 0.1f);
        }
    }
    return true;
}
//from polygons
bool edk::physics2D::PhysicObject2D::writeBoundingBoxPhysicFromPolygons(edk::rectf32* rect,
                                                                        edk::uint32 lenght,
                                                                        edk::uint32* positions
                                                                        ){
    //multiply the matrix by
    this->physicMatrixTransform.setIdentity();edkEnd();
    if(this->father){
        //calculate the boundingBox from the father
        edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)this->father;
        if(this->father->getType()>= edk::TypeObject2DPhysic
                &&
                this->father->getType()<= edk::TypeObject2DKinematic
                ){
            temp->writeFatherBoundingBoxPhysic(rect,&this->physicMatrixTransform);
        }
        else if(this->father->getType()== edk::TypeObject2D){
            temp->writeFatherBoundingBox(rect,&this->physicMatrixTransform);
        }

        edk::Math::generateScaleMatrix(this->connectedSize,&this->physicMatrixSize);edkEnd();
        edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->physicMatrixAngle);edkEnd();
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->physicMatrixPosition);edkEnd();
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->physicMatrixPivo);edkEnd();
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();
        //translate
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
        //angle
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
        //scale
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
        //Pivo
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();
        //translate
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
        //angle
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
        //scale
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
        //Pivo
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();
    }

    if(this->physicMesh.getPolygonSize()){
        if(this->father){
            this->physicMesh.calculateBoundingBoxFromPolygons(rect,
                                                              &this->physicMatrixTransform,
                                                              lenght,
                                                              positions
                                                              );edkEnd();
        }
        else{
            *rect = this->physicMesh.generateBoundingBoxFromPolygons(&this->physicMatrixTransform,
                                                                     lenght,
                                                                     positions
                                                                     );edkEnd();
        }
    }
    else{
        //generate a small boundingBox
        rect->origin = this->position - 0.1f;
        rect->size = edk::size2f32(this->position.x + 0.1f,this->position.y + 0.1f);
    }
    return false;
}
bool edk::physics2D::PhysicObject2D::writeBoundingBoxPhysicFromPolygons(edk::rectf32* rect,
                                                                        edk::vector::Matrixf32<3u,3u>* transformMat,
                                                                        edk::uint32 lenght,
                                                                        edk::uint32* positions
                                                                        ){
    //first copy the matrix
    if(this->physicMatrixTransform.cloneFrom(transformMat)){
        if(this->father){
            //calculate the boundingBox from the father
            edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)this->father;
            if(this->father->getType()>= edk::TypeObject2DPhysic
                    &&
                    this->father->getType()<= edk::TypeObject2DKinematic
                    ){
                temp->writeFatherBoundingBoxPhysic(rect,&this->physicMatrixTransform);
            }
            else if(this->father->getType()== edk::TypeObject2D){
                temp->writeFatherBoundingBox(rect,&this->physicMatrixTransform);
            }

            edk::Math::generateScaleMatrix(this->connectedSize,&this->physicMatrixSize);edkEnd();
            edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->physicMatrixAngle);edkEnd();
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->physicMatrixPosition);edkEnd();
            edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->physicMatrixPivo);edkEnd();
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();

            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();
            //multiply the matrix by
            //translate
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
            //angle
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
            //scale
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
            //Pivo
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();
        }
        else{
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();
            //multiply the matrix by
            //translate
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
            //angle
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
            //scale
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
            //Pivo
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();
        }

        if(this->physicMesh.getPolygonSize()){
            if(this->father){
                *rect = this->physicMesh.generateBoundingBoxFromPolygons(&this->physicMatrixTransform,
                                                                         lenght,
                                                                         positions
                                                                         );edkEnd();
            }
            else{
                this->physicMesh.calculateBoundingBoxFromPolygons(rect,
                                                                  &this->physicMatrixTransform,
                                                                  lenght,
                                                                  positions
                                                                  );edkEnd();
            }
        }
        else{
            //generate a small boundingBox
            rect->origin = this->position - 0.1f;
            rect->size = edk::size2f32(this->position.x + 0.1f,this->position.y + 0.1f);
        }
    }
    return true;
}
bool edk::physics2D::PhysicObject2D::writeChildremBoundingBoxPhysicFromPolygons(edk::rectf32* rect,
                                                                                edk::uint32 lenght,
                                                                                edk::uint32* positions
                                                                                ){
    bool ret = false;
    //multiply the matrix by
    this->physicMatrixTransform.setIdentity();edkEnd();
    if(this->father){
        //calculate the boundingBox from the father
        edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)this->father;
        if(this->father->getType()>= edk::TypeObject2DPhysic
                &&
                this->father->getType()<= edk::TypeObject2DKinematic
                ){
            temp->writeFatherBoundingBoxPhysic(rect,&this->physicMatrixTransform);
        }
        else if(this->father->getType()== edk::TypeObject2D){
            temp->writeFatherBoundingBox(rect,&this->physicMatrixTransform);
        }

        edk::Math::generateScaleMatrix(this->connectedSize,&this->physicMatrixSize);edkEnd();
        edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->physicMatrixAngle);edkEnd();
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->physicMatrixPosition);edkEnd();
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->physicMatrixPivo);edkEnd();
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();

        //translate
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
        //angle
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
        //scale
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
        //Pivo
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();
        //translate
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
        //angle
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
        //scale
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
        //Pivo
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();
    }

    if(this->physicMesh.getPolygonSize()){
        if(this->father){
            this->physicMesh.calculateBoundingBoxFromPolygons(rect,
                                                              &this->physicMatrixTransform,
                                                              lenght,
                                                              positions
                                                              );edkEnd();
        }
        else{
            *rect = this->physicMesh.generateBoundingBoxFromPolygons(&this->physicMatrixTransform,
                                                                     lenght,
                                                                     positions
                                                                     );edkEnd();
        }
        ret = true;
    }
    else{
        //generate a small boundingBox
        rect->origin = this->position - 0.1f;
        rect->size = edk::size2f32(this->position.x + 0.1f,this->position.y + 0.1f);
    }
    return ret;
}
bool edk::physics2D::PhysicObject2D::writeChildremBoundingBoxPhysicFromPolygons(edk::rectf32* rect,
                                                                                edk::vector::Matrixf32<3u,3u>* transformMat,
                                                                                edk::uint32 lenght,
                                                                                edk::uint32* positions
                                                                                ){
    //first copy the matrix
    if(this->physicMatrixTransform.cloneFrom(transformMat)){
        if(this->father){
            //calculate the boundingBox from the father
            edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)this->father;
            if(this->father->getType()>= edk::TypeObject2DPhysic
                    &&
                    this->father->getType()<= edk::TypeObject2DKinematic
                    ){
                temp->writeBoundingBoxPhysic(rect,&this->physicMatrixTransform);
            }
            else if(this->father->getType()== edk::TypeObject2D){
                temp->writeBoundingBox(rect,&this->physicMatrixTransform);
            }

            edk::Math::generateScaleMatrix(this->connectedSize,&this->physicMatrixSize);edkEnd();
            edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->physicMatrixAngle);edkEnd();
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->physicMatrixPosition);edkEnd();
            edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->physicMatrixPivo);edkEnd();
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();


            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();
            //multiply the matrix by
            //translate
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
            //angle
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
            //scale
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
            //Pivo
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();
        }
        else{
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();
            //multiply the matrix by
            //translate
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
            //angle
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
            //scale
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
            //Pivo
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();
        }

        if(this->physicMesh.getPolygonSize()){
            if(this->father){
                *rect = this->physicMesh.generateBoundingBoxFromPolygons(&this->physicMatrixTransform,
                                                                         lenght,
                                                                         positions
                                                                         );edkEnd();
            }
            else{
                this->physicMesh.calculateBoundingBoxFromPolygons(rect,
                                                                  &this->physicMatrixTransform,
                                                                  lenght,
                                                                  positions
                                                                  );edkEnd();
            }
        }
        else{
            //generate a small boundingBox
            rect->origin = this->position - 0.1f;
            rect->size = edk::size2f32(this->position.x + 0.1f,this->position.y + 0.1f);
        }
    }
    return true;
}

//draw the mesh
void edk::physics2D::PhysicObject2D::drawChildremsBackBoundingBoxPhysics(){
    edk::uint32 size = this->childremsBack.size();
    edk::physics2D::PhysicObject2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsBack.getElementInPosition(i);
        if(this->father->getType()>= edk::TypeObject2DPhysic
                &&
                this->father->getType()<= edk::TypeObject2DKinematic
                ){
            obj->drawChildBoundingBoxPhysics();
        }
    }
}
void edk::physics2D::PhysicObject2D::drawChildBackBoundingBoxPhysics(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);edkEnd();

    this->drawChildremsBackBoundingBoxPhysics();

    (this->*functionDrawBoundingBoxPhysics)();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::physics2D::PhysicObject2D::drawChildremsFrontBoundingBoxPhysics(){
    edk::uint32 size = this->childremsFront.size();
    edk::physics2D::PhysicObject2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsFront.getElementInPosition(i);
        if(this->father->getType()>= edk::TypeObject2DPhysic
                &&
                this->father->getType()<= edk::TypeObject2DKinematic
                ){
            obj->drawChildBoundingBoxPhysics();
        }
    }
}
void edk::physics2D::PhysicObject2D::drawChildFrontBoundingBoxPhysics(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    (this->*functionDrawBoundingBoxPhysics)();

    this->drawChildremsFrontBoundingBoxPhysics();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::physics2D::PhysicObject2D::drawChildremsBoundingBoxPhysics(){
    edk::uint32 size = this->childremsBack.size();
    edk::physics2D::PhysicObject2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsBack.getElementInPosition(i);
        if(this->father->getType()>= edk::TypeObject2DPhysic
                &&
                this->father->getType()<= edk::TypeObject2DKinematic
                ){
            obj->drawChildBoundingBoxPhysics();
        }
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsFront.getElementInPosition(i);
        if(this->father->getType()>= edk::TypeObject2DPhysic
                &&
                this->father->getType()<= edk::TypeObject2DKinematic
                ){
            obj->drawChildBoundingBoxPhysics();
        }
    }
}
void edk::physics2D::PhysicObject2D::drawChildBoundingBoxPhysics(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);edkEnd();

    this->drawChildremsBackBoundingBoxPhysics();

    (this->*functionDrawBoundingBoxPhysics)();

    this->drawChildremsFrontBoundingBoxPhysics();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::physics2D::PhysicObject2D::drawChildremsBackWirePhysics(){
    edk::uint32 size = this->childremsBack.size();
    edk::physics2D::PhysicObject2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsBack.getElementInPosition(i);
        if(obj->getType()>= edk::TypeObject2DPhysic
                &&
                obj->getType()<= edk::TypeObject2DKinematic
                ){
            obj->drawChildWirePhysics();
        }
    }
}
void edk::physics2D::PhysicObject2D::drawChildBackWirePhysics(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale2f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle);edkEnd();
    edk::GU::guTranslate2f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate2f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWirePhysics();

    (this->*functionDrawWirePhysics)();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::physics2D::PhysicObject2D::drawChildremsFrontWirePhysics(){
    edk::uint32 size = this->childremsFront.size();
    edk::physics2D::PhysicObject2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsFront.getElementInPosition(i);
        if(obj->getType()>= edk::TypeObject2DPhysic
                &&
                obj->getType()<= edk::TypeObject2DKinematic
                ){
            obj->drawChildWirePhysics();
        }
    }
}
void edk::physics2D::PhysicObject2D::drawChildFrontWirePhysics(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale2f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle);edkEnd();
    edk::GU::guTranslate2f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate2f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    (this->*functionDrawWirePhysics)();

    this->drawChildremsFrontWirePhysics();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::physics2D::PhysicObject2D::drawChildremsWirePhysics(){
    edk::uint32 size = this->childremsBack.size();
    edk::physics2D::PhysicObject2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsBack.getElementInPosition(i);
        if(obj->getType()>= edk::TypeObject2DPhysic
                &&
                obj->getType()<= edk::TypeObject2DKinematic
                ){
            obj->drawChildWirePhysics();
        }
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsFront.getElementInPosition(i);
        if(obj->getType()>= edk::TypeObject2DPhysic
                &&
                obj->getType()<= edk::TypeObject2DKinematic
                ){
            obj->drawChildWirePhysics();
        }
    }
}
void edk::physics2D::PhysicObject2D::drawChildWirePhysics(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale2f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle);edkEnd();
    edk::GU::guTranslate2f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate2f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWirePhysics();

    (this->*functionDrawWirePhysics)();

    this->drawChildremsFrontWirePhysics();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::physics2D::PhysicObject2D::drawChildremsBackWirePhysicsWorld(){
    edk::uint32 size = this->childremsBack.size();
    edk::physics2D::PhysicObject2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsBack.getElementInPosition(i);
        if(obj->getType()>= edk::TypeObject2DPhysic
                &&
                obj->getType()<= edk::TypeObject2DKinematic
                ){
            obj->drawChildWirePhysicsWorld();
        }
    }
}
void edk::physics2D::PhysicObject2D::drawChildBackWirePhysicsWorld(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    this->drawChildremsBackWirePhysicsWorld();

    (this->*functionDrawWirePhysicsWorld)();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::physics2D::PhysicObject2D::drawChildremsFrontWirePhysicsWorld(){
    edk::uint32 size = this->childremsFront.size();
    edk::physics2D::PhysicObject2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsFront.getElementInPosition(i);
        if(obj->getType()>= edk::TypeObject2DPhysic
                &&
                obj->getType()<= edk::TypeObject2DKinematic
                ){
            obj->drawChildWirePhysicsWorld();
        }
    }
}
void edk::physics2D::PhysicObject2D::drawChildFrontWirePhysicsWorld(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    (this->*functionDrawWirePhysicsWorld)();

    this->drawChildremsFrontWirePhysicsWorld();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::physics2D::PhysicObject2D::drawChildremsWirePhysicsWorld(){
    edk::uint32 size = this->childremsBack.size();
    edk::physics2D::PhysicObject2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsBack.getElementInPosition(i);
        if(obj->getType()>= edk::TypeObject2DPhysic
                &&
                obj->getType()<= edk::TypeObject2DKinematic
                ){
            obj->drawChildWirePhysicsWorld();
        }
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsFront.getElementInPosition(i);
        if(obj->getType()>= edk::TypeObject2DPhysic
                &&
                obj->getType()<= edk::TypeObject2DKinematic
                ){
            obj->drawChildWirePhysicsWorld();
        }
    }
}
void edk::physics2D::PhysicObject2D::drawChildWirePhysicsWorld(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    this->drawChildremsBackWirePhysicsWorld();

    (this->*functionDrawWirePhysicsWorld)();

    this->drawChildremsFrontWirePhysicsWorld();

    edk::GU::guPopMatrix();edkEnd();
}

//Draw function
//HIDE
void edk::physics2D::PhysicObject2D::drawHideBoundingBoxPhysics(){}
void edk::physics2D::PhysicObject2D::drawHideWirePhysics(){}
void edk::physics2D::PhysicObject2D::drawHideWirePhysicsWorld(){}
//UNHIDE
void edk::physics2D::PhysicObject2D::drawUnhideBoundingBoxPhysics(){
    edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    edk::GU::guVertex2f32(this->boundingBoxPhysics.origin.x  ,this->boundingBoxPhysics.origin.y   );edkEnd();
    edk::GU::guVertex2f32(this->boundingBoxPhysics.origin.x  ,this->boundingBoxPhysics.size.height);edkEnd();
    edk::GU::guVertex2f32(this->boundingBoxPhysics.size.width,this->boundingBoxPhysics.size.height);edkEnd();
    edk::GU::guVertex2f32(this->boundingBoxPhysics.size.width,this->boundingBoxPhysics.origin.y   );edkEnd();
    edk::GU::guEnd();edkEnd();
}
void edk::physics2D::PhysicObject2D::drawUnhideWirePhysics(){
    this->physicMesh.drawWirePolygons();edkEnd();
}
void edk::physics2D::PhysicObject2D::drawUnhideWirePhysicsWorld(){
    this->physicMeshWorld.drawWirePolygonsWorld();edkEnd();
}

//clean the obect
void edk::physics2D::PhysicObject2D::clean(){
    this->physicMesh.cleanPolygons();edkEnd();
    this->treeCollisionGroups.clean();edkEnd();
    this->treeNotCollisionGroups.clean();edkEnd();
    this->canSleep=false;edkEnd();
    this->speed=0.f;edkEnd();
    this->direction=0.f;edkEnd();
    this->linearVelocity=0.f;edkEnd();
    this->angularVelocity=0.f;edkEnd();
    this->linearVelocitySetted=false;edkEnd();
    this->angularVelocitySetted=false;edkEnd();
    edk::Object2D::clean();edkEnd();
}

//HIDE
bool edk::physics2D::PhysicObject2D::hide(){
    if(edk::Object2D::hide()){
        //
        this->functionDrawBoundingBoxPhysics = &edk::physics2D::PhysicObject2D::drawHideBoundingBoxPhysics;
        this->functionDrawWirePhysics = &edk::physics2D::PhysicObject2D::drawHideWirePhysics;
        this->functionDrawWirePhysicsWorld = &edk::physics2D::PhysicObject2D::drawHideWirePhysicsWorld;
        return true;
    }
    return false;
}
//UNHIDE
bool edk::physics2D::PhysicObject2D::unhide(){
    if(edk::Object2D::unhide()){
        //
        this->functionDrawBoundingBoxPhysics = &edk::physics2D::PhysicObject2D::drawUnhideBoundingBoxPhysics;
        this->functionDrawWirePhysics = &edk::physics2D::PhysicObject2D::drawUnhideWirePhysics;
        this->functionDrawWirePhysicsWorld = &edk::physics2D::PhysicObject2D::drawUnhideWirePhysicsWorld;
        return true;
    }
    return false;
}

//set the lonearVelocity
void edk::physics2D::PhysicObject2D::setLinearVelocity(edk::vec2f32 velocity){
    //set linear velocity
    this->linearVelocity = velocity;edkEnd();
    //calculate the speed
    this->speed = edk::Math::pythagoras(this->linearVelocity);edkEnd();
    //get the direction
    this->direction = edk::Math::normalise(this->linearVelocity);edkEnd();
    this->linearVelocitySetted=true;edkEnd();
}
void edk::physics2D::PhysicObject2D::setLinearVelocity(edk::float32 x,edk::float32 y){
    this->setLinearVelocity(edk::vec2f32(x,y));edkEnd();
}
void edk::physics2D::PhysicObject2D::setAngularVelocity(edk::float32 angle){
    this->angularVelocity = angle;edkEnd();
    this->angularVelocitySetted=true;edkEnd();
}
//remove all meshes
void edk::physics2D::PhysicObject2D::cleanMeshes(){
    edk::Object2D::cleanMeshes();edkEnd();
    this->physicMesh.cleanPolygons();edkEnd();
}
void edk::physics2D::PhysicObject2D::cleanMesh(){
    edk::Object2D::cleanMeshes();edkEnd();
}

//return the speed
edk::float32 edk::physics2D::PhysicObject2D::getSpeed(){
    return this->speed;edkEnd();
}
//return the direction
edk::vec2f32 edk::physics2D::PhysicObject2D::getDirection(){
    return this->direction;edkEnd();
}
//rturn the linearVelocity
edk::vec2f32 edk::physics2D::PhysicObject2D::getLinearVelocity(){
    this->linearVelocitySetted=false;edkEnd();
    edk::vec2f32 ret = this->linearVelocity;edkEnd();
    return ret;
}
//return if set the linearVelocity
bool edk::physics2D::PhysicObject2D::haveSettedLinearVelocity(){
    if(this->linearVelocitySetted){
        this->linearVelocitySetted=false;edkEnd();
        return true;
    }
    return false;
}
//return the angular velocity
edk::float32 edk::physics2D::PhysicObject2D::getAngularVelocity(){
    this->angularVelocitySetted=false;edkEnd();
    edk::float32 ret = this->angularVelocity;edkEnd();
    return ret;
}
//return if set angular velocoty
bool edk::physics2D::PhysicObject2D::haveSettedAngularVelocity(){
    if(this->angularVelocitySetted){
        this->angularVelocitySetted=false;edkEnd();
        return true;
    }
    return false;
}

//function to calculate boundingBoxPhysic
bool edk::physics2D::PhysicObject2D::calculateBoundingBoxPhysic(){
    return this->writeChildremBoundingBoxPhysic(&this->boundingBoxPhysics);
}
bool edk::physics2D::PhysicObject2D::calculateBoundingBoxPhysic(edk::vector::Matrixf32<3u,3u>* transformMat){
    return this->writeChildremBoundingBoxPhysic(&this->boundingBoxPhysics,transformMat);
}
bool edk::physics2D::PhysicObject2D::generateBoundingBoxPhysic(){
    return this->writeChildremBoundingBoxPhysic(&this->boundingBoxPhysics);
}
bool edk::physics2D::PhysicObject2D::generateBoundingBoxPhysic(edk::vector::Matrixf32<3u,3u>* transformMat){
    return this->writeChildremBoundingBoxPhysic(&this->boundingBoxPhysics,transformMat);
}
//function to calculate boundingBoxPhysic from polygons
bool edk::physics2D::PhysicObject2D::calculateBoundingBoxPhysicFromPolygons(edk::uint32 lenght,
                                                                            edk::uint32* positions
                                                                            ){
    if(lenght && positions){
        return this->writeChildremBoundingBoxPhysicFromPolygons(&this->boundingBoxPhysics,
                                                                lenght,
                                                                positions
                                                                );
    }
    return false;
}
bool edk::physics2D::PhysicObject2D::calculateBoundingBoxPhysicFromPolygons(edk::vector::Matrixf32<3u,3u>* transformMat,
                                                                            edk::uint32 lenght,
                                                                            edk::uint32* positions
                                                                            ){
    if(lenght && transformMat && positions){
        return this->writeChildremBoundingBoxPhysicFromPolygons(&this->boundingBoxPhysics,
                                                                transformMat,
                                                                lenght,
                                                                positions
                                                                );
    }
    return false;
}
bool edk::physics2D::PhysicObject2D::generateBoundingBoxPhysicFromPolygons(edk::uint32 lenght,
                                                                           edk::uint32* positions
                                                                           ){
    if(lenght && positions){
        return this->writeChildremBoundingBoxPhysicFromPolygons(&this->boundingBoxPhysics,
                                                                lenght,
                                                                positions
                                                                );
    }
    return false;
}
bool edk::physics2D::PhysicObject2D::generateBoundingBoxPhysicFromPolygons(edk::vector::Matrixf32<3u,3u>* transformMat,
                                                                           edk::uint32 lenght,
                                                                           edk::uint32* positions
                                                                           ){
    if(lenght && transformMat){
        return this->writeChildremBoundingBoxPhysicFromPolygons(&this->boundingBoxPhysics,
                                                                transformMat,
                                                                lenght,
                                                                positions
                                                                );
    }
    return false;
}
//functions to calculate a new boundingBoxPhysic
edk::rectf32 edk::physics2D::PhysicObject2D::calculateNewBoundingBoxPhysic(){
    edk::rectf32 ret;
    this->writeChildremBoundingBoxPhysic(&ret);
    return ret;
}
edk::rectf32 edk::physics2D::PhysicObject2D::calculateNewBoundingBoxPhysic(edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::rectf32 ret;
    this->writeChildremBoundingBoxPhysic(&ret,transformMat);
    return ret;
}
edk::rectf32 edk::physics2D::PhysicObject2D::generateNewBoundingBoxPhysic(){
    edk::rectf32 ret;
    this->writeChildremBoundingBoxPhysic(&ret);
    return ret;
}
edk::rectf32 edk::physics2D::PhysicObject2D::generateNewBoundingBoxPhysic(edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::rectf32 ret;
    this->writeChildremBoundingBoxPhysic(&ret,transformMat);
    return ret;
}
//functions to calculate a new boundingBoxPhysic from polygons
edk::rectf32 edk::physics2D::PhysicObject2D::calculateNewBoundingBoxPhysicFromPolygons(edk::uint32 lenght,
                                                                                       edk::uint32* positions
                                                                                       ){
    edk::rectf32 ret;
    this->writeChildremBoundingBoxPhysicFromPolygons(&ret,lenght,positions);
    return ret;
}
edk::rectf32 edk::physics2D::PhysicObject2D::calculateNewBoundingBoxPhysicFromPolygons(edk::vector::Matrixf32<3u,3u>* transformMat,
                                                                                       edk::uint32 lenght,
                                                                                       edk::uint32* positions
                                                                                       ){
    edk::rectf32 ret;
    this->writeChildremBoundingBoxPhysicFromPolygons(&ret,transformMat,lenght,positions);
    return ret;
}
edk::rectf32 edk::physics2D::PhysicObject2D::generateNewBoundingBoxPhysicFromPolygons(edk::uint32 lenght,
                                                                                      edk::uint32* positions
                                                                                      ){
    edk::rectf32 ret;
    this->writeChildremBoundingBoxPhysicFromPolygons(&ret,lenght,positions);
    return ret;
}
edk::rectf32 edk::physics2D::PhysicObject2D::generateNewBoundingBoxPhysicFromPolygons(edk::vector::Matrixf32<3u,3u>* transformMat,
                                                                                      edk::uint32 lenght,
                                                                                      edk::uint32* positions
                                                                                      ){
    edk::rectf32 ret;
    this->writeChildremBoundingBoxPhysicFromPolygons(&ret,transformMat,lenght,positions);
    return ret;
}

//function to calculate boundingBoxPhysic
bool edk::physics2D::PhysicObject2D::calculateBoundingBoxPhysicNoChildrem(){
    return this->writeBoundingBoxPhysic(&this->boundingBoxPhysics);
}
bool edk::physics2D::PhysicObject2D::calculateBoundingBoxPhysicNoChildrem(edk::vector::Matrixf32<3u,3u>* transformMat){
    return this->writeBoundingBoxPhysic(&this->boundingBoxPhysics,transformMat);
}
bool edk::physics2D::PhysicObject2D::generateBoundingBoxPhysicNoChildrem(){
    return this->writeBoundingBoxPhysic(&this->boundingBoxPhysics);
}
bool edk::physics2D::PhysicObject2D::generateBoundingBoxPhysicNoChildrem(edk::vector::Matrixf32<3u,3u>* transformMat){
    return this->writeBoundingBoxPhysic(&this->boundingBoxPhysics,transformMat);
}
//function to calculate boundingBoxPhysic from polygons
bool edk::physics2D::PhysicObject2D::calculateBoundingBoxPhysicNoChildremFromPolygons(edk::uint32 lenght,
                                                                                      edk::uint32* positions
                                                                                      ){
    return this->writeBoundingBoxPhysicFromPolygons(&this->boundingBoxPhysics,lenght,positions);
}
bool edk::physics2D::PhysicObject2D::calculateBoundingBoxPhysicNoChildremFromPolygons(edk::vector::Matrixf32<3u,3u>* transformMat,
                                                                                      edk::uint32 lenght,
                                                                                      edk::uint32* positions
                                                                                      ){
    return this->writeBoundingBoxPhysicFromPolygons(&this->boundingBoxPhysics,transformMat,lenght,positions);
}
bool edk::physics2D::PhysicObject2D::generateBoundingBoxPhysicNoChildremFromPolygons(edk::uint32 lenght,
                                                                                     edk::uint32* positions
                                                                                     ){
    return this->writeBoundingBoxPhysicFromPolygons(&this->boundingBoxPhysics,lenght,positions);
}
bool edk::physics2D::PhysicObject2D::generateBoundingBoxPhysicNoChildremFromPolygons(edk::vector::Matrixf32<3u,3u>* transformMat,
                                                                                     edk::uint32 lenght,
                                                                                     edk::uint32* positions
                                                                                     ){
    return this->writeBoundingBoxPhysicFromPolygons(&this->boundingBoxPhysics,transformMat,lenght,positions);
}
//functions to calculate a new boundingBoxPhysic
edk::rectf32 edk::physics2D::PhysicObject2D::calculateNewBoundingBoxPhysicNoChildrem(){
    edk::rectf32 ret;
    this->writeBoundingBoxPhysic(&ret);
    return ret;
}
edk::rectf32 edk::physics2D::PhysicObject2D::calculateNewBoundingBoxPhysicNoChildrem(edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::rectf32 ret;
    this->writeBoundingBoxPhysic(&ret,transformMat);
    return ret;
}
edk::rectf32 edk::physics2D::PhysicObject2D::generateNewBoundingBoxPhysicNoChildrem(){
    edk::rectf32 ret;
    this->writeBoundingBoxPhysic(&ret);
    return ret;
}
edk::rectf32 edk::physics2D::PhysicObject2D::generateNewBoundingBoxPhysicNoChildrem(edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::rectf32 ret;
    this->writeBoundingBoxPhysic(&ret,transformMat);
    return ret;
}
//functions to calculate a new boundingBoxPhysic from polygons
edk::rectf32 edk::physics2D::PhysicObject2D::calculateNewBoundingBoxPhysicNoChildremFromPolygons(edk::uint32 lenght,
                                                                                                 edk::uint32* positions
                                                                                                 ){
    edk::rectf32 ret;
    this->writeBoundingBoxPhysicFromPolygons(&ret,lenght,positions);
    return ret;
}
edk::rectf32 edk::physics2D::PhysicObject2D::calculateNewBoundingBoxPhysicNoChildremFromPolygons(edk::vector::Matrixf32<3u,3u>* transformMat,
                                                                                                 edk::uint32 lenght,
                                                                                                 edk::uint32* positions
                                                                                                 ){
    edk::rectf32 ret;
    this->writeBoundingBoxPhysicFromPolygons(&ret,transformMat,lenght,positions);
    return ret;
}
edk::rectf32 edk::physics2D::PhysicObject2D::generateNewBoundingBoxPhysicNoChildremFromPolygons(edk::uint32 lenght,
                                                                                                edk::uint32* positions
                                                                                                ){
    edk::rectf32 ret;
    this->writeBoundingBoxPhysicFromPolygons(&ret,lenght,positions);
    return ret;
}
edk::rectf32 edk::physics2D::PhysicObject2D::generateNewBoundingBoxPhysicNoChildremFromPolygons(edk::vector::Matrixf32<3u,3u>* transformMat,
                                                                                                edk::uint32 lenght,
                                                                                                edk::uint32* positions
                                                                                                ){
    edk::rectf32 ret;
    this->writeBoundingBoxPhysicFromPolygons(&ret,transformMat,lenght,positions);
    return ret;
}
//return a copy of the physicBoundingBoxPhysic
edk::rectf32 edk::physics2D::PhysicObject2D::getBoundingBoxPhysic(){
    return this->boundingBoxPhysics;
}

//generate the physic mesh in the world with world vertexes
bool edk::physics2D::PhysicObject2D::copyAndGenerateWorldPhysicMesh(){
    if(this->physicMeshWorld.cloneFrom(&this->physicMesh)){
        return this->generateWorldPhysicMesh();
    }
    return false;
}
bool edk::physics2D::PhysicObject2D::generateWorldPhysicMesh(){
    if(this->physicMesh.getPolygonSize() == this->physicMeshWorld.getPolygonSize()){
        //multiply the matrix by
        this->physicMatrixTransform.setIdentity();edkEnd();
        this->loadFatherMatrix(&this->physicMatrixTransform);
        //copy the polygons
        this->physicMesh.generateWorldPolygons(&this->physicMeshWorld,&this->physicMatrixTransform);edkEnd();
        return true;
    }
    return false;
}
//generate the physic mesh in the world with world vertexes from polygons
bool edk::physics2D::PhysicObject2D::copyAndGenerateWorldPhysicMeshFromPolygons(edk::uint32 lenght,
                                                                                edk::uint32* positions
                                                                                ){
    if(positions){
        if(this->physicMeshWorld.cloneFrom(&this->physicMesh)){
            return this->generateWorldPhysicMeshFromPolygons(lenght,positions);
        }
    }
    return false;
}
bool edk::physics2D::PhysicObject2D::generateWorldPhysicMeshFromPolygons(edk::uint32 lenght,
                                                                         edk::uint32* positions
                                                                         ){
    if(this->physicMesh.getPolygonSize() == this->physicMeshWorld.getPolygonSize()){
        //multiply the matrix by
        this->physicMatrixTransform.setIdentity();edkEnd();
        this->loadFatherMatrix(&this->physicMatrixTransform);
        //copy the polygons
        this->physicMesh.generateWorldPolygons(&this->physicMeshWorld,
                                               &this->physicMatrixTransform,
                                               lenght,
                                               positions
                                               );edkEnd();
        return true;
    }
    return false;
}

void edk::physics2D::PhysicObject2D::removeAllMesh(){
    this->cleanMesh();edkEnd();
}

//return if it's a sensor
bool edk::physics2D::PhysicObject2D::isSensor(){
    return this->isObjectSensor;
}

//add a group
bool edk::physics2D::PhysicObject2D::addCollisionGroup(edk::uint32 id){
    //remove from notCollisionGroup
    this->removeNotCollisionGroup(id);edkEnd();
    if(id){
        return this->treeCollisionGroups.add(id);edkEnd();
    }
    return false;
}
bool edk::physics2D::PhysicObject2D::addNotCollisionGroup(edk::uint32 id){
    //remove from collision group
    this->removeCollisionGroup(id);edkEnd();
    if(id){
        return this->treeNotCollisionGroups.add(id);edkEnd();
    }
    return false;
}
bool edk::physics2D::PhysicObject2D::removeCollisionGroup(edk::uint32 id){
    return this->treeCollisionGroups.remove(id);edkEnd();
}
bool edk::physics2D::PhysicObject2D::removeNotCollisionGroup(edk::uint32 id){
    return this->treeNotCollisionGroups.remove(id);edkEnd();
}
void edk::physics2D::PhysicObject2D::cleanCollisionGroups(){
    this->treeCollisionGroups.clean();edkEnd();
}
void edk::physics2D::PhysicObject2D::cleanNotCollisionGroups(){
    this->treeNotCollisionGroups.clean();edkEnd();
}
void edk::physics2D::PhysicObject2D::cleanAllGroups(){
    this->cleanCollisionGroups();edkEnd();
    this->cleanNotCollisionGroups();edkEnd();
}
bool edk::physics2D::PhysicObject2D::haveCollisionGroup(edk::uint32 id){
    return this->treeCollisionGroups.haveElement(id);edkEnd();
}
bool edk::physics2D::PhysicObject2D::haveNotCollisionGroup(edk::uint32 id){
    return this->treeNotCollisionGroups.haveElement(id);edkEnd();
}
edk::uint32 edk::physics2D::PhysicObject2D::getCollisionGroupInPosition(edk::uint32 position){
    return this->treeCollisionGroups.getElementInPosition(position);edkEnd();
}
edk::uint32 edk::physics2D::PhysicObject2D::getNotCollisionGroupInPosition(edk::uint32 position){
    return this->treeNotCollisionGroups.getElementInPosition(position);edkEnd();
}
//get group size
edk::uint32 edk::physics2D::PhysicObject2D::getCollisionGroupSize(){
    return this->treeCollisionGroups.size();edkEnd();
}
edk::uint32 edk::physics2D::PhysicObject2D::getNotCollisionGroupSize(){
    return this->treeNotCollisionGroups.size();edkEnd();
}

//get world polygon
bool edk::physics2D::PhysicObject2D::getWorldPolygonPhysic(edk::shape::Polygon2D* dest,edk::uint32 polygonPosition){
    bool ret=false;edkEnd();
    if(dest){
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();
        //multiply the matrix by

        this->physicMatrixTransform.setIdentity(1.f,0.f);edkEnd();

        //translate
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
        //angle
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
        //scale
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
        //Pivo
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();

        ret = this->physicMesh.getWorldPolygon(dest,polygonPosition,&this->physicMatrixTransform);edkEnd();
    }
    return ret;
}
bool edk::physics2D::PhysicObject2D::getWorldPolygonPhysic(edk::shape::Polygon2D* dest,edk::uint32 polygonPosition,edk::vector::Matrixf32<3u,3u>* transformMat){
    bool ret=false;edkEnd();
    if(dest){
        //first copy the matrix
        if(this->physicMatrixTransform.cloneFrom(transformMat)){
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);edkEnd();

            //multiply the matrix by
            //translate
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);edkEnd();
            //angle
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);edkEnd();
            //scale
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);edkEnd();
            //Pivo
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);edkEnd();

            ret = this->physicMesh.getWorldPolygon(dest,polygonPosition,&this->physicMatrixTransform);edkEnd();
        }
    }
    return ret;
}

void edk::physics2D::PhysicObject2D::drawPhysics(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->physicMesh.drawPolygons();edkEnd();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::physics2D::PhysicObject2D::drawWirePhysics(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWirePhysics();

    (this->*functionDrawWirePhysics)();

    this->drawChildremsFrontWirePhysics();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::physics2D::PhysicObject2D::drawWirePhysicsWorld(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    //this->drawChildremsBackWirePhysicsWorld();

    (this->*functionDrawWirePhysicsWorld)();

    //this->drawChildremsFrontWirePhysicsWorld();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::physics2D::PhysicObject2D::drawPolygonPhysics(edk::uint32 position){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->physicMesh.drawPolygon(position);edkEnd();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::physics2D::PhysicObject2D::drawPolygonWirePhysics(edk::uint32 position){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->physicMesh.drawWirePolygon(position);edkEnd();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::physics2D::PhysicObject2D::drawLinearVelocity(edk::color3f32 color,edk::vec2f32 position,edk::float32 scale){
    edk::GU::guColor3f32(color);
    edk::GU::guBegin(GU_LINES);
    edk::GU::guVertex2f32(position);
    edk::GU::guVertex2f32(position + (this->linearVelocity * scale));
    edk::GU::guEnd();
}
void edk::physics2D::PhysicObject2D::drawLinearVelocity(edk::color3f32 color,edk::float32 scale){
    this->drawLinearVelocity(color,this->position,scale);
}
void edk::physics2D::PhysicObject2D::drawLinearVelocity(edk::float32 r,
                                                        edk::float32 g,
                                                        edk::float32 b,
                                                        edk::vec2f32 position,
                                                        edk::float32 scale
                                                        ){
    return this->drawLinearVelocity(edk::color3f32(r,g,b),position,scale);
}
void edk::physics2D::PhysicObject2D::drawLinearVelocity(edk::float32 r,
                                                        edk::float32 g,
                                                        edk::float32 b,
                                                        edk::float32 scale
                                                        ){
    return this->drawLinearVelocity(edk::color3f32(r,g,b),this->position,scale);
}

//update all animations
bool edk::physics2D::PhysicObject2D::updateAnimations(){
    bool ret=false;edkEnd();
    this->animationPosition.updateClockAnimation();edkEnd();
    this->animationRotation.updateClockAnimation();edkEnd();
    //test if are playing the animations
    if(this->animationPosition.isPlaying()){
        //get X and Y
        this->position = edk::vec2f32(this->animationPosition.getClockX(),
                                      this->animationPosition.getClockY()
                                      );edkEnd();
        ret=true;edkEnd();
    }
    if(this->animationRotation.isPlaying()){
        //get the new Angle
        this->angle = this->animationRotation.getClockX();edkEnd();
        ret=true;edkEnd();
    }
    this->updateMeshAnimations();edkEnd();
    this->updateChildremsAnimations();
    return ret;
}
bool edk::physics2D::PhysicObject2D::updateAnimations(edk::float32 seconds){
    bool ret=false;edkEnd();
    this->animationPosition.updateClockAnimation(seconds);edkEnd();
    this->animationRotation.updateClockAnimation(seconds);edkEnd();
    this->animationSize.updateClockAnimation(seconds);edkEnd();
    //test if are playing the animations
    if(this->animationPosition.isPlaying()){
        //get X and Y
        this->position = edk::vec2f32(this->animationPosition.getClockX(this->position.x),
                                      this->animationPosition.getClockY(this->position.y)
                                      );edkEnd();
        ret=true;edkEnd();
    }
    if(this->animationRotation.isPlaying()){
        //get the new Angle
        this->angle = this->animationRotation.getClockX();edkEnd();
        ret=true;edkEnd();
    }
    //test if is animating the size
    if(this->animationSize.isPlaying()){
        //
        this->size.width = this->animationSize.getClockX();edkEnd();
        this->size.height = this->animationSize.getClockY();edkEnd();
        ret=true;edkEnd();
    }
    this->updateMeshAnimations(seconds);edkEnd();
    this->updateChildremsAnimations(seconds);
    return ret;
}

//XML
bool edk::physics2D::PhysicObject2D::writeToXML(edk::XML* xml,edk::uint32 id,bool connected){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"physicObject_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //set the string
                        if(connected){
                            xml->setSelectedString("true");edkEnd();
                        }
                        //write object
                        edk::Object2D::writeToXML(xml,id);edkEnd();
                        //write type
                        edk::char8* temp;edkEnd();
                        edk::char8* nameTemp;edkEnd();
                        edk::char8* iTemp;edkEnd();
                        temp = edk::String::int32ToStr(this->getTypeValue());edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"type",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        //write sensor
                        if(this->isSensor()){
                            xml->addSelectedNextAttribute("sensor","true");edkEnd();
                        }
                        else{
                            xml->addSelectedNextAttribute("sensor","false");edkEnd();
                        }
                        //write fixedRot
                        if(this->fixedRotation){
                            xml->addSelectedNextAttribute("fixedRot","true");edkEnd();
                        }
                        else{
                            xml->addSelectedNextAttribute("fixedRot","false");edkEnd();
                        }
                        //write canSleep
                        if(this->canSleep){
                            xml->addSelectedNextAttribute("canSleep","true");edkEnd();
                        }
                        else{
                            xml->addSelectedNextAttribute("canSleep","false");edkEnd();
                        }
                        //write the mesh
                        this->physicMesh.writeToXML(xml,0u);edkEnd();
                        edk::uint32 size = 0u;edkEnd();
                        //write collision groups
                        if(xml->addSelectedNextChild("collision")){
                            if(xml->selectChild("collision")){
                                size = this->treeCollisionGroups.size();edkEnd();
                                for(edk::uint32 i= 0u;i<size;i++){
                                    temp = edk::String::int64ToStr(this->treeCollisionGroups.getElementInPosition(i));edkEnd();
                                    if(temp){
                                        iTemp = edk::String::int64ToStr(i);edkEnd();
                                        if(iTemp){
                                            nameTemp = edk::String::strCat((edk::char8*)"c",iTemp);edkEnd();
                                            if(nameTemp){
                                                xml->addSelectedNextAttribute(nameTemp,temp);edkEnd();
                                                free(nameTemp);edkEnd();
                                            }
                                            free(iTemp);edkEnd();
                                        }
                                        free(temp);edkEnd();
                                    }
                                }
                                xml->selectFather();edkEnd();
                            }
                        }
                        //write notCollision groups
                        if(xml->addSelectedNextChild("notCollision")){
                            if(xml->selectChild("notCollision")){
                                size = this->treeCollisionGroups.size();edkEnd();
                                for(edk::uint32 i= 0u;i<size;i++){
                                    temp = edk::String::int64ToStr(this->treeCollisionGroups.getElementInPosition(i));edkEnd();
                                    if(temp){
                                        iTemp = edk::String::int64ToStr(i);edkEnd();
                                        if(iTemp){
                                            nameTemp = edk::String::strCat((edk::char8*)"n",iTemp);edkEnd();
                                            if(nameTemp){
                                                xml->addSelectedNextAttribute(nameTemp,temp);edkEnd();
                                                free(nameTemp);edkEnd();
                                            }
                                            free(iTemp);edkEnd();
                                        }
                                        free(temp);edkEnd();
                                    }
                                }
                                xml->selectFather();edkEnd();
                            }
                        }
                        //write physics animations
                        this->animationPosition.writeToXML(xml,0u);edkEnd();
                        //this->animationPositionX.writeToXML(xml,0u);edkEnd();
                        //this->animationPositionY.writeToXML(xml,0u);edkEnd();
                        this->animationRotation.writeToXML(xml,1u);edkEnd();

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
bool edk::physics2D::PhysicObject2D::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"physicObject_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    edk::char8* nameTemp;edkEnd();
                    edk::char8* iTemp;edkEnd();
                    this->physicMesh.cleanPolygons();edkEnd();
                    //read the object
                    edk::Object2D::readFromXML(xml,id);edkEnd();
                    //read type
                    edk::uint32 newType = edk::String::strToInt32(xml->getSelectedAttributeValueByName("type"));edkEnd();
                    if(newType==(edk::uint32)edk::TypeObject2DStatic || newType==tempEDK::physics::StaticBody){
                        this->type = edk::TypeObject2DStatic;
                    }
                    else if(newType==(edk::uint32)edk::TypeObject2DKinematic || newType==tempEDK::physics::KinematicBody){
                        this->type = edk::TypeObject2DKinematic;
                    }
                    else if(newType==(edk::uint32)edk::TypeObject2DDynamic || newType==tempEDK::physics::DynamicBody){
                        this->type = edk::TypeObject2DDynamic;
                    }
                    //read sensor
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("sensor"),(edk::char8*)"true")){
                        this->isObjectSensor=true;edkEnd();
                    }
                    else{
                        this->isObjectSensor=false;edkEnd();
                    }
                    //read fixedRot
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("fixedRot"),(edk::char8*)"true")){
                        this->fixedRotation=true;edkEnd();
                    }
                    else{
                        this->fixedRotation=false;edkEnd();
                    }
                    //read canSleep
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("canSleep"),(edk::char8*)"true")){
                        this->canSleep=true;edkEnd();
                    }
                    else{
                        this->canSleep=false;edkEnd();
                    }
                    //read mesh
                    this->physicMesh.readFromXML(xml,0u);edkEnd();
                    //read collisionGroup
                    this->treeCollisionGroups.clean();edkEnd();
                    if(xml->selectChild("collision")){
                        edk::uint32 i=0u;
                        bool cont=true;edkEnd();
                        do{
                            iTemp = edk::String::int64ToStr(i);edkEnd();
                            if(iTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"c",iTemp);edkEnd();
                                if(nameTemp){
                                    if(xml->haveSelectedAttribute(nameTemp)){
                                        //read the value
                                        this->treeCollisionGroups.add(edk::String::strToInt64(xml->getSelectedAttributeValueByName(nameTemp)));edkEnd();
                                    }
                                    else{
                                        cont=false;edkEnd();
                                    }
                                    free(nameTemp);edkEnd();
                                }
                                free(iTemp);edkEnd();
                            }
                            i++;edkEnd();
                        }while(cont);edkEnd();
                        xml->selectFather();edkEnd();
                    }
                    //read notCollisionGroup
                    this->treeNotCollisionGroups.clean();edkEnd();
                    if(xml->selectChild("notCollision")){
                        edk::uint32 i=0u;
                        bool cont=true;edkEnd();
                        do{
                            iTemp = edk::String::int64ToStr(i);edkEnd();
                            if(iTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"n",iTemp);edkEnd();
                                if(nameTemp){
                                    if(xml->haveSelectedAttribute(nameTemp)){
                                        //read the value
                                        this->treeNotCollisionGroups.add(edk::String::strToInt64(xml->getSelectedAttributeValueByName(nameTemp)));edkEnd();
                                    }
                                    else{
                                        cont=false;edkEnd();
                                    }
                                    free(nameTemp);edkEnd();
                                }
                                free(iTemp);edkEnd();
                            }
                            i++;edkEnd();
                        }while(cont);edkEnd();
                        xml->selectFather();edkEnd();
                    }
                    //write physics animations
                    this->animationPosition.readFromXML(xml,0u);edkEnd();
                    //this->animationPositionX.readFromXML(xml,0u);edkEnd();
                    //this->animationPositionY.readFromXML(xml,0u);edkEnd();
                    this->animationRotation.readFromXML(xml,1u);edkEnd();

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
bool edk::physics2D::PhysicObject2D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    if(xml && pack){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"physicObject_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    edk::char8* nameTemp;edkEnd();
                    edk::char8* iTemp;edkEnd();
                    this->physicMesh.cleanPolygons();edkEnd();
                    //read the object
                    edk::Object2D::readFromXMLFromPack(pack,xml,id);edkEnd();
                    //read type
                    edk::uint32 newType = edk::String::strToInt32(xml->getSelectedAttributeValueByName("type"));edkEnd();
                    if(newType==(edk::uint32)edk::TypeObject2DStatic || newType==tempEDK::physics::StaticBody){
                        this->type = edk::TypeObject2DStatic;
                    }
                    else if(newType==(edk::uint32)edk::TypeObject2DKinematic || newType==tempEDK::physics::KinematicBody){
                        this->type = edk::TypeObject2DKinematic;
                    }
                    else if(newType==(edk::uint32)edk::TypeObject2DDynamic || newType==tempEDK::physics::DynamicBody){
                        this->type = edk::TypeObject2DDynamic;
                    }
                    //read sensor
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("sensor"),(edk::char8*)"true")){
                        this->isObjectSensor=true;edkEnd();
                    }
                    else{
                        this->isObjectSensor=false;edkEnd();}
                    //read fixedRot
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("fixedRot"),(edk::char8*)"true")){
                        this->fixedRotation=true;edkEnd();
                    }
                    else{
                        this->fixedRotation=false;edkEnd();
                    }
                    //read canSleep
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("canSleep"),(edk::char8*)"true")){
                        this->canSleep=true;edkEnd();
                    }
                    else{
                        this->canSleep=false;edkEnd();
                    }
                    //read mesh
                    this->physicMesh.readFromXML(xml,0u);edkEnd();
                    //read collisionGroup
                    this->treeCollisionGroups.clean();edkEnd();
                    if(xml->selectChild("collision")){
                        edk::uint32 i=0u;
                        bool cont=true;edkEnd();
                        do{
                            iTemp = edk::String::int64ToStr(i);edkEnd();
                            if(iTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"c",iTemp);edkEnd();
                                if(nameTemp){
                                    if(xml->haveSelectedAttribute(nameTemp)){
                                        //read the value
                                        this->treeCollisionGroups.add(edk::String::strToInt64(xml->getSelectedAttributeValueByName(nameTemp)));edkEnd();
                                    }
                                    else{
                                        cont=false;edkEnd();
                                    }
                                    free(nameTemp);edkEnd();
                                }
                                free(iTemp);edkEnd();
                            }
                            i++;edkEnd();
                        }while(cont);edkEnd();
                        xml->selectFather();edkEnd();
                    }
                    //read notCollisionGroup
                    this->treeNotCollisionGroups.clean();edkEnd();
                    if(xml->selectChild("notCollision")){
                        edk::uint32 i=0u;
                        bool cont=true;edkEnd();
                        do{
                            iTemp = edk::String::int64ToStr(i);edkEnd();
                            if(iTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"n",iTemp);edkEnd();
                                if(nameTemp){
                                    if(xml->haveSelectedAttribute(nameTemp)){
                                        //read the value
                                        this->treeNotCollisionGroups.add(edk::String::strToInt64(xml->getSelectedAttributeValueByName(nameTemp)));edkEnd();
                                    }
                                    else{
                                        cont=false;edkEnd();
                                    }
                                    free(nameTemp);edkEnd();
                                }
                                free(iTemp);edkEnd();
                            }
                            i++;edkEnd();
                        }while(cont);edkEnd();
                        xml->selectFather();edkEnd();
                    }
                    //write physics animations
                    this->animationPosition.readFromXML(xml,0u);edkEnd();
                    //this->animationPositionX.readFromXML(xml,0u);edkEnd();
                    //this->animationPositionY.readFromXML(xml,0u);edkEnd();
                    this->animationRotation.readFromXML(xml,1u);edkEnd();

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
bool edk::physics2D::PhysicObject2D::readFromXMLisSensor(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"physicObject_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //read sensor
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("sensor"),(edk::char8*)"true")){
                        ret=true;edkEnd();
                    }
                    else{
                        ret=false;edkEnd();
                    }
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

//clone the physics mesh from mesh in a position
bool edk::physics2D::PhysicObject2D::clonePhysicsMeshFromMeshPosition(edk::uint32 position){
    //clone from the mesh
    return this->physicMesh.cloneFrom(this->getMesh(position));
}

bool edk::physics2D::PhysicObject2D::cloneFrom(edk::physics2D::PhysicObject2D* obj){
    if(obj){
        edk::Object2D::cloneFrom(obj);edkEnd();
        //copy the mesh
        //this->physicMesh=obj->physicMesh;edkEnd();
        this->physicMesh.cloneFrom(&obj->physicMesh);edkEnd();
        this->canSleep = obj->canSleep;edkEnd();
        this->fixedRotation = obj->fixedRotation;edkEnd();
        this->animationPosition.cloneFrom(&obj->animationPosition);edkEnd();
        //this->animationRotation = obj->animationRotation;edkEnd();
        this->animationRotation.cloneFrom(&obj->animationRotation);edkEnd();

        //copy the collision groups
        edk::uint32 size;edkEnd();
        size = obj->treeCollisionGroups.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            this->treeCollisionGroups.add(obj->treeCollisionGroups.getElementInPosition(i));edkEnd();
        }
        size = obj->treeNotCollisionGroups.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            this->treeNotCollisionGroups.add(obj->treeNotCollisionGroups.getElementInPosition(i));edkEnd();
        }
        return true;
    }
    return false;
}
bool edk::physics2D::PhysicObject2D::cloneFromWithType(edk::physics2D::PhysicObject2D* obj){
    if(obj){
        edk::Object2D::cloneFrom(obj);edkEnd();
        //copy the mesh
        //this->physicMesh=obj->physicMesh;edkEnd();
        this->physicMesh.cloneFrom(&obj->physicMesh);edkEnd();
        this->canSleep = obj->canSleep;edkEnd();
        this->fixedRotation = obj->fixedRotation;edkEnd();
        this->animationPosition.cloneFrom(&obj->animationPosition);edkEnd();
        //this->animationRotation = obj->animationRotation;edkEnd();
        this->animationRotation.cloneFrom(&obj->animationRotation);edkEnd();
        this->type=obj->type;edkEnd();

        //copy the collision groups
        edk::uint32 size;edkEnd();
        size = obj->treeCollisionGroups.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            this->treeCollisionGroups.add(obj->treeCollisionGroups.getElementInPosition(i));edkEnd();
        }
        size = obj->treeNotCollisionGroups.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            this->treeNotCollisionGroups.add(obj->treeNotCollisionGroups.getElementInPosition(i));edkEnd();
        }
        return true;
    }
    return false;
}

bool edk::physics2D::PhysicObject2D::cloneFrom(edk::Object2D* obj){
    if(obj){
        edk::Object2D::cloneFrom(obj);edkEnd();
        return true;
    }
    return false;
}
