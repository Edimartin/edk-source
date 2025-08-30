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
    this->classThis=NULL;
    this->Constructor();
}
edk::physics2D::PhysicObject2D::~PhysicObject2D(){
    this->Destructor();
}

void edk::physics2D::PhysicObject2D::Constructor(){
    edk::Object2D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->boundingBoxPhysics=0.f;
        this->physicMesh.Constructor();
        this->physicMeshWorld.Constructor();
        this->physicMatrixPosition.Constructor();
        this->physicMatrixPivo.Constructor();
        this->physicMatrixAngle.Constructor();
        this->physicMatrixSize.Constructor();
        this->physicMatrixTransform.Constructor();
        this->treeCollisionGroups.Constructor();
        this->treeNotCollisionGroups.Constructor();

        this->type=edk::TypeObject2DPhysic;
        this->fixedRotation=false;
        this->canSleep=false;
        this->isObjectSensor=false;

        this->speed=0.f;
        this->linearVelocity = edk::vec2f32(0,0);
        this->linearVelocitySetted=false;
        this->angularVelocity=0.f;
        this->angularVelocitySetted=false;
        this->direction = edk::vec2f32(0,0);

        this->functionDrawBoundingBoxPhysics = &edk::physics2D::PhysicObject2D::drawUnhideBoundingBoxPhysics;
        this->functionDrawWirePhysics = &edk::physics2D::PhysicObject2D::drawUnhideWirePhysics;
        this->functionDrawWirePhysicsWorld = &edk::physics2D::PhysicObject2D::drawUnhideWirePhysicsWorld;
    }
}
void edk::physics2D::PhysicObject2D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->physicMesh.cleanPolygons();
        this->physicMeshWorld.cleanPolygons();
        this->treeCollisionGroups.clean();
        this->treeNotCollisionGroups.clean();

        this->physicMesh.Destructor();
        this->physicMeshWorld.Destructor();
        this->physicMatrixPosition.Destructor();
        this->physicMatrixPivo.Destructor();
        this->physicMatrixAngle.Destructor();
        this->physicMatrixSize.Destructor();
        this->physicMatrixTransform.Destructor();
        this->treeCollisionGroups.Destructor();
        this->treeNotCollisionGroups.Destructor();
    }
    edk::Object2D::Destructor();
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

        edk::Math::generateScaleMatrix(this->connectedSize,&this->physicMatrixSize);
        edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->physicMatrixAngle);
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->physicMatrixPosition);
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->physicMatrixPivo);
        transformMat->multiplyThisWithMatrix(&this->physicMatrixSize);
        transformMat->multiplyThisWithMatrix(&this->physicMatrixAngle);
        transformMat->multiplyThisWithMatrix(&this->physicMatrixPosition);
        transformMat->multiplyThisWithMatrix(&this->physicMatrixPivo);

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);
        //translate
        transformMat->multiplyThisWithMatrix(&this->physicMatrixPosition);
        //angle
        transformMat->multiplyThisWithMatrix(&this->physicMatrixAngle);
        //scale
        transformMat->multiplyThisWithMatrix(&this->physicMatrixSize);
        //Pivo
        transformMat->multiplyThisWithMatrix(&this->physicMatrixPivo);
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);
        //translate
        transformMat->multiplyThisWithMatrix(&this->physicMatrixPosition);
        //angle
        transformMat->multiplyThisWithMatrix(&this->physicMatrixAngle);
        //scale
        transformMat->multiplyThisWithMatrix(&this->physicMatrixSize);
        //Pivo
        transformMat->multiplyThisWithMatrix(&this->physicMatrixPivo);
    }
}
bool edk::physics2D::PhysicObject2D::writeBoundingBoxPhysic(edk::rectf32* rect){
    //multiply the matrix by
    this->physicMatrixTransform.setIdentity();
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

        edk::Math::generateScaleMatrix(this->connectedSize,&this->physicMatrixSize);
        edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->physicMatrixAngle);
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->physicMatrixPosition);
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->physicMatrixPivo);
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);
        //translate
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
        //angle
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
        //scale
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
        //Pivo
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);
        //translate
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
        //angle
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
        //scale
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
        //Pivo
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);
    }

    if(this->physicMesh.getPolygonSize()){
        if(this->father){
            this->physicMesh.calculateBoundingBox(rect,&this->physicMatrixTransform);
        }
        else{
            *rect = this->physicMesh.generateBoundingBox(&this->physicMatrixTransform);
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

            edk::Math::generateScaleMatrix(this->connectedSize,&this->physicMatrixSize);
            edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->physicMatrixAngle);
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->physicMatrixPosition);
            edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->physicMatrixPivo);
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);

            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
            edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
            edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);
            //multiply the matrix by
            //translate
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
            //angle
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
            //scale
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
            //Pivo
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);
        }
        else{
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
            edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
            edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);
            //multiply the matrix by
            //translate
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
            //angle
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
            //scale
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
            //Pivo
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);
        }

        if(this->physicMesh.getPolygonSize()){
            if(this->father){
                *rect = this->physicMesh.generateBoundingBox(&this->physicMatrixTransform);
            }
            else{
                this->physicMesh.calculateBoundingBox(rect,&this->physicMatrixTransform);
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
    this->physicMatrixTransform.setIdentity();
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

        edk::Math::generateScaleMatrix(this->connectedSize,&this->physicMatrixSize);
        edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->physicMatrixAngle);
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->physicMatrixPosition);
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->physicMatrixPivo);
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);

        //translate
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
        //angle
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
        //scale
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
        //Pivo
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);
        //translate
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
        //angle
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
        //scale
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
        //Pivo
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);
    }

    if(this->physicMesh.getPolygonSize()){
        if(this->father){
            this->physicMesh.calculateBoundingBox(rect,&this->physicMatrixTransform);
        }
        else{
            *rect = this->physicMesh.generateBoundingBox(&this->physicMatrixTransform);
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

            edk::Math::generateScaleMatrix(this->connectedSize,&this->physicMatrixSize);
            edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->physicMatrixAngle);
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->physicMatrixPosition);
            edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->physicMatrixPivo);
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);


            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
            edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
            edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);
            //multiply the matrix by
            //translate
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
            //angle
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
            //scale
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
            //Pivo
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);
        }
        else{
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
            edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
            edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);
            //multiply the matrix by
            //translate
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
            //angle
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
            //scale
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
            //Pivo
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);
        }

        if(this->physicMesh.getPolygonSize()){
            if(this->father){
                *rect = this->physicMesh.generateBoundingBox(&this->physicMatrixTransform);
            }
            else{
                this->physicMesh.calculateBoundingBox(rect,&this->physicMatrixTransform);
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
    this->physicMatrixTransform.setIdentity();
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

        edk::Math::generateScaleMatrix(this->connectedSize,&this->physicMatrixSize);
        edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->physicMatrixAngle);
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->physicMatrixPosition);
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->physicMatrixPivo);
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);
        //translate
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
        //angle
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
        //scale
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
        //Pivo
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);
        //translate
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
        //angle
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
        //scale
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
        //Pivo
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);
    }

    if(this->physicMesh.getPolygonSize()){
        if(this->father){
            this->physicMesh.calculateBoundingBoxFromPolygons(rect,
                                                              &this->physicMatrixTransform,
                                                              lenght,
                                                              positions
                                                              );
        }
        else{
            *rect = this->physicMesh.generateBoundingBoxFromPolygons(&this->physicMatrixTransform,
                                                                     lenght,
                                                                     positions
                                                                     );
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

            edk::Math::generateScaleMatrix(this->connectedSize,&this->physicMatrixSize);
            edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->physicMatrixAngle);
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->physicMatrixPosition);
            edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->physicMatrixPivo);
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);

            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
            edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
            edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);
            //multiply the matrix by
            //translate
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
            //angle
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
            //scale
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
            //Pivo
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);
        }
        else{
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
            edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
            edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);
            //multiply the matrix by
            //translate
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
            //angle
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
            //scale
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
            //Pivo
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);
        }

        if(this->physicMesh.getPolygonSize()){
            if(this->father){
                *rect = this->physicMesh.generateBoundingBoxFromPolygons(&this->physicMatrixTransform,
                                                                         lenght,
                                                                         positions
                                                                         );
            }
            else{
                this->physicMesh.calculateBoundingBoxFromPolygons(rect,
                                                                  &this->physicMatrixTransform,
                                                                  lenght,
                                                                  positions
                                                                  );
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
    this->physicMatrixTransform.setIdentity();
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

        edk::Math::generateScaleMatrix(this->connectedSize,&this->physicMatrixSize);
        edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->physicMatrixAngle);
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->physicMatrixPosition);
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->physicMatrixPivo);
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);

        //translate
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
        //angle
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
        //scale
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
        //Pivo
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);
        //translate
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
        //angle
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
        //scale
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
        //Pivo
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);
    }

    if(this->physicMesh.getPolygonSize()){
        if(this->father){
            this->physicMesh.calculateBoundingBoxFromPolygons(rect,
                                                              &this->physicMatrixTransform,
                                                              lenght,
                                                              positions
                                                              );
        }
        else{
            *rect = this->physicMesh.generateBoundingBoxFromPolygons(&this->physicMatrixTransform,
                                                                     lenght,
                                                                     positions
                                                                     );
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

            edk::Math::generateScaleMatrix(this->connectedSize,&this->physicMatrixSize);
            edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->physicMatrixAngle);
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->physicMatrixPosition);
            edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->physicMatrixPivo);
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);


            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
            edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
            edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);
            //multiply the matrix by
            //translate
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
            //angle
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
            //scale
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
            //Pivo
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);
        }
        else{
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
            edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
            edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);
            //multiply the matrix by
            //translate
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
            //angle
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
            //scale
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
            //Pivo
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);
        }

        if(this->physicMesh.getPolygonSize()){
            if(this->father){
                *rect = this->physicMesh.generateBoundingBoxFromPolygons(&this->physicMatrixTransform,
                                                                         lenght,
                                                                         positions
                                                                         );
            }
            else{
                this->physicMesh.calculateBoundingBoxFromPolygons(rect,
                                                                  &this->physicMatrixTransform,
                                                                  lenght,
                                                                  positions
                                                                  );
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
        obj = (edk::physics2D::PhysicObject2D*)this->childremsBack.get(i);
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
    edk::GU::guPushMatrix();

    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);

    this->drawChildremsBackBoundingBoxPhysics();

    (this->*functionDrawBoundingBoxPhysics)();

    edk::GU::guPopMatrix();
}
void edk::physics2D::PhysicObject2D::drawChildremsFrontBoundingBoxPhysics(){
    edk::uint32 size = this->childremsFront.size();
    edk::physics2D::PhysicObject2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsFront.get(i);
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
    edk::GU::guPushMatrix();

    (this->*functionDrawBoundingBoxPhysics)();

    this->drawChildremsFrontBoundingBoxPhysics();

    edk::GU::guPopMatrix();
}
void edk::physics2D::PhysicObject2D::drawChildremsBoundingBoxPhysics(){
    edk::uint32 size = this->childremsBack.size();
    edk::physics2D::PhysicObject2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsBack.get(i);
        if(this->father->getType()>= edk::TypeObject2DPhysic
                &&
                this->father->getType()<= edk::TypeObject2DKinematic
                ){
            obj->drawChildBoundingBoxPhysics();
        }
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsFront.get(i);
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
    edk::GU::guPushMatrix();

    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);

    this->drawChildremsBackBoundingBoxPhysics();

    (this->*functionDrawBoundingBoxPhysics)();

    this->drawChildremsFrontBoundingBoxPhysics();
    edk::GU::guPopMatrix();
}
void edk::physics2D::PhysicObject2D::drawChildremsBackWirePhysics(){
    edk::uint32 size = this->childremsBack.size();
    edk::physics2D::PhysicObject2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsBack.get(i);
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
    edk::GU::guPushMatrix();

    edk::GU::guScale2f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle);
    edk::GU::guTranslate2f32(this->connectedPosition);
    edk::GU::guTranslate2f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add scale
    edk::GU::guScale2f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    this->drawChildremsBackWirePhysics();

    (this->*functionDrawWirePhysics)();

    edk::GU::guPopMatrix();
}
void edk::physics2D::PhysicObject2D::drawChildremsFrontWirePhysics(){
    edk::uint32 size = this->childremsFront.size();
    edk::physics2D::PhysicObject2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsFront.get(i);
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
    edk::GU::guPushMatrix();

    edk::GU::guScale2f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle);
    edk::GU::guTranslate2f32(this->connectedPosition);
    edk::GU::guTranslate2f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add scale
    edk::GU::guScale2f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    (this->*functionDrawWirePhysics)();

    this->drawChildremsFrontWirePhysics();

    edk::GU::guPopMatrix();
}
void edk::physics2D::PhysicObject2D::drawChildremsWirePhysics(){
    edk::uint32 size = this->childremsBack.size();
    edk::physics2D::PhysicObject2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsBack.get(i);
        if(obj->getType()>= edk::TypeObject2DPhysic
                &&
                obj->getType()<= edk::TypeObject2DKinematic
                ){
            obj->drawChildWirePhysics();
        }
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsFront.get(i);
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
    edk::GU::guPushMatrix();

    edk::GU::guScale2f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle);
    edk::GU::guTranslate2f32(this->connectedPosition);
    edk::GU::guTranslate2f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add scale
    edk::GU::guScale2f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    this->drawChildremsBackWirePhysics();

    (this->*functionDrawWirePhysics)();

    this->drawChildremsFrontWirePhysics();

    edk::GU::guPopMatrix();
}
void edk::physics2D::PhysicObject2D::drawChildremsBackWirePhysicsWorld(){
    edk::uint32 size = this->childremsBack.size();
    edk::physics2D::PhysicObject2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsBack.get(i);
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
    edk::GU::guPushMatrix();

    this->drawChildremsBackWirePhysicsWorld();

    (this->*functionDrawWirePhysicsWorld)();

    edk::GU::guPopMatrix();
}
void edk::physics2D::PhysicObject2D::drawChildremsFrontWirePhysicsWorld(){
    edk::uint32 size = this->childremsFront.size();
    edk::physics2D::PhysicObject2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsFront.get(i);
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
    edk::GU::guPushMatrix();

    (this->*functionDrawWirePhysicsWorld)();

    this->drawChildremsFrontWirePhysicsWorld();

    edk::GU::guPopMatrix();
}
void edk::physics2D::PhysicObject2D::drawChildremsWirePhysicsWorld(){
    edk::uint32 size = this->childremsBack.size();
    edk::physics2D::PhysicObject2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsBack.get(i);
        if(obj->getType()>= edk::TypeObject2DPhysic
                &&
                obj->getType()<= edk::TypeObject2DKinematic
                ){
            obj->drawChildWirePhysicsWorld();
        }
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = (edk::physics2D::PhysicObject2D*)this->childremsFront.get(i);
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
    edk::GU::guPushMatrix();

    this->drawChildremsBackWirePhysicsWorld();

    (this->*functionDrawWirePhysicsWorld)();

    this->drawChildremsFrontWirePhysicsWorld();

    edk::GU::guPopMatrix();
}

//Draw function
//HIDE
void edk::physics2D::PhysicObject2D::drawHideBoundingBoxPhysics(){}
void edk::physics2D::PhysicObject2D::drawHideWirePhysics(){}
void edk::physics2D::PhysicObject2D::drawHideWirePhysicsWorld(){}
//UNHIDE
void edk::physics2D::PhysicObject2D::drawUnhideBoundingBoxPhysics(){
    edk::GU::guBegin(GU_LINE_LOOP);
    edk::GU::guVertex2f32(this->boundingBoxPhysics.origin.x  ,this->boundingBoxPhysics.origin.y   );
    edk::GU::guVertex2f32(this->boundingBoxPhysics.origin.x  ,this->boundingBoxPhysics.size.height);
    edk::GU::guVertex2f32(this->boundingBoxPhysics.size.width,this->boundingBoxPhysics.size.height);
    edk::GU::guVertex2f32(this->boundingBoxPhysics.size.width,this->boundingBoxPhysics.origin.y   );
    edk::GU::guEnd();
}
void edk::physics2D::PhysicObject2D::drawUnhideWirePhysics(){
    this->physicMesh.drawWirePolygons();
}
void edk::physics2D::PhysicObject2D::drawUnhideWirePhysicsWorld(){
    this->physicMeshWorld.drawWirePolygonsWorld();
}

//clean the obect
void edk::physics2D::PhysicObject2D::clean(){
    this->physicMesh.cleanPolygons();
    this->treeCollisionGroups.clean();
    this->treeNotCollisionGroups.clean();
    this->canSleep=false;
    this->speed=0.f;
    this->direction=0.f;
    this->linearVelocity=0.f;
    this->angularVelocity=0.f;
    this->linearVelocitySetted=false;
    this->angularVelocitySetted=false;
    edk::Object2D::clean();
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
    this->linearVelocity = velocity;
    //calculate the speed
    this->speed = edk::Math::pythagoras(this->linearVelocity);
    //get the direction
    this->direction = edk::Math::normalise(this->linearVelocity);
    this->linearVelocitySetted=true;
}
void edk::physics2D::PhysicObject2D::setLinearVelocity(edk::float32 x,edk::float32 y){
    this->setLinearVelocity(edk::vec2f32(x,y));
}
void edk::physics2D::PhysicObject2D::setAngularVelocity(edk::float32 angle){
    this->angularVelocity = angle;
    this->angularVelocitySetted=true;
}
//remove all meshes
void edk::physics2D::PhysicObject2D::cleanMeshes(){
    edk::Object2D::cleanMeshes();
    this->physicMesh.cleanPolygons();
}
void edk::physics2D::PhysicObject2D::cleanMesh(){
    edk::Object2D::cleanMeshes();
}

//return the speed
edk::float32 edk::physics2D::PhysicObject2D::getSpeed(){
    return this->speed;
}
//return the direction
edk::vec2f32 edk::physics2D::PhysicObject2D::getDirection(){
    return this->direction;
}
//rturn the linearVelocity
edk::vec2f32 edk::physics2D::PhysicObject2D::getLinearVelocity(){
    this->linearVelocitySetted=false;
    edk::vec2f32 ret = this->linearVelocity;
    return ret;
}
//return if set the linearVelocity
bool edk::physics2D::PhysicObject2D::haveSettedLinearVelocity(){
    if(this->linearVelocitySetted){
        this->linearVelocitySetted=false;
        return true;
    }
    return false;
}
//return the angular velocity
edk::float32 edk::physics2D::PhysicObject2D::getAngularVelocity(){
    this->angularVelocitySetted=false;
    edk::float32 ret = this->angularVelocity;
    return ret;
}
//return if set angular velocoty
bool edk::physics2D::PhysicObject2D::haveSettedAngularVelocity(){
    if(this->angularVelocitySetted){
        this->angularVelocitySetted=false;
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
        this->physicMatrixTransform.setIdentity();
        this->loadFatherMatrix(&this->physicMatrixTransform);
        //copy the polygons
        this->physicMesh.generateWorldPolygons(&this->physicMeshWorld,&this->physicMatrixTransform);
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
        this->physicMatrixTransform.setIdentity();
        this->loadFatherMatrix(&this->physicMatrixTransform);
        //copy the polygons
        this->physicMesh.generateWorldPolygons(&this->physicMeshWorld,
                                               &this->physicMatrixTransform,
                                               lenght,
                                               positions
                                               );
        return true;
    }
    return false;
}

void edk::physics2D::PhysicObject2D::removeAllMesh(){
    this->cleanMesh();
}

//return if it's a sensor
bool edk::physics2D::PhysicObject2D::isSensor(){
    return this->isObjectSensor;
}

//add a group
bool edk::physics2D::PhysicObject2D::addCollisionGroup(edk::uint32 id){
    //remove from notCollisionGroup
    this->removeNotCollisionGroup(id);
    if(id){
        return this->treeCollisionGroups.add(id);
    }
    return false;
}
bool edk::physics2D::PhysicObject2D::addNotCollisionGroup(edk::uint32 id){
    //remove from collision group
    this->removeCollisionGroup(id);
    if(id){
        return this->treeNotCollisionGroups.add(id);
    }
    return false;
}
bool edk::physics2D::PhysicObject2D::removeCollisionGroup(edk::uint32 id){
    return this->treeCollisionGroups.remove(id);
}
bool edk::physics2D::PhysicObject2D::removeNotCollisionGroup(edk::uint32 id){
    return this->treeNotCollisionGroups.remove(id);
}
void edk::physics2D::PhysicObject2D::cleanCollisionGroups(){
    this->treeCollisionGroups.clean();
}
void edk::physics2D::PhysicObject2D::cleanNotCollisionGroups(){
    this->treeNotCollisionGroups.clean();
}
void edk::physics2D::PhysicObject2D::cleanAllGroups(){
    this->cleanCollisionGroups();
    this->cleanNotCollisionGroups();
}
bool edk::physics2D::PhysicObject2D::haveCollisionGroup(edk::uint32 id){
    return this->treeCollisionGroups.haveElement(id);
}
bool edk::physics2D::PhysicObject2D::haveNotCollisionGroup(edk::uint32 id){
    return this->treeNotCollisionGroups.haveElement(id);
}
edk::uint32 edk::physics2D::PhysicObject2D::getCollisionGroupInPosition(edk::uint32 position){
    return this->treeCollisionGroups.getElementInPosition(position);
}
edk::uint32 edk::physics2D::PhysicObject2D::getNotCollisionGroupInPosition(edk::uint32 position){
    return this->treeNotCollisionGroups.getElementInPosition(position);
}
//get group size
edk::uint32 edk::physics2D::PhysicObject2D::getCollisionGroupSize(){
    return this->treeCollisionGroups.size();
}
edk::uint32 edk::physics2D::PhysicObject2D::getNotCollisionGroupSize(){
    return this->treeNotCollisionGroups.size();
}

//get world polygon
bool edk::physics2D::PhysicObject2D::getWorldPolygonPhysic(edk::shape::Polygon2D* dest,edk::uint32 polygonPosition){
    bool ret=false;
    if(dest){
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
        edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);
        //multiply the matrix by

        this->physicMatrixTransform.setIdentity(1.f,0.f);

        //translate
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
        //angle
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
        //scale
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
        //Pivo
        this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);

        ret = this->physicMesh.getWorldPolygon(dest,polygonPosition,&this->physicMatrixTransform);
    }
    return ret;
}
bool edk::physics2D::PhysicObject2D::getWorldPolygonPhysic(edk::shape::Polygon2D* dest,edk::uint32 polygonPosition,edk::vector::Matrixf32<3u,3u>* transformMat){
    bool ret=false;
    if(dest){
        //first copy the matrix
        if(this->physicMatrixTransform.cloneFrom(transformMat)){
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->physicMatrixPosition);
            edk::Math::generateRotateMatrixZ(this->angle,&this->physicMatrixAngle);
            edk::Math::generateScaleMatrix(this->size,&this->physicMatrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->physicMatrixPivo);

            //multiply the matrix by
            //translate
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPosition);
            //angle
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixAngle);
            //scale
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixSize);
            //Pivo
            this->physicMatrixTransform.multiplyThisWithMatrix(&this->physicMatrixPivo);

            ret = this->physicMesh.getWorldPolygon(dest,polygonPosition,&this->physicMatrixTransform);
        }
    }
    return ret;
}

void edk::physics2D::PhysicObject2D::drawPhysics(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    this->physicMesh.drawPolygons();

    edk::GU::guPopMatrix();
}
void edk::physics2D::PhysicObject2D::drawWirePhysics(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    this->drawChildremsBackWirePhysics();

    (this->*functionDrawWirePhysics)();

    this->drawChildremsFrontWirePhysics();

    edk::GU::guPopMatrix();
}
void edk::physics2D::PhysicObject2D::drawWirePhysicsWorld(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    //this->drawChildremsBackWirePhysicsWorld();

    (this->*functionDrawWirePhysicsWorld)();

    //this->drawChildremsFrontWirePhysicsWorld();

    edk::GU::guPopMatrix();
}
void edk::physics2D::PhysicObject2D::drawPolygonPhysics(edk::uint32 position){
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    this->physicMesh.drawPolygon(position);

    edk::GU::guPopMatrix();
}
void edk::physics2D::PhysicObject2D::drawPolygonWirePhysics(edk::uint32 position){
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    this->physicMesh.drawWirePolygon(position);

    edk::GU::guPopMatrix();
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
    bool ret=false;
    this->animationPosition.updateClockAnimation();
    this->animationRotation.updateClockAnimation();
    //test if are playing the animations
    if(this->animationPosition.isPlaying()){
        //get X and Y
        this->position = edk::vec2f32(this->animationPosition.getClockX(),
                                      this->animationPosition.getClockY()
                                      );
        ret=true;
    }
    if(this->animationRotation.isPlaying()){
        //get the new Angle
        this->angle = this->animationRotation.getClockX();
        ret=true;
    }
    this->updateMeshAnimations();
    this->updateChildremsAnimations();
    return ret;
}
bool edk::physics2D::PhysicObject2D::updateAnimations(edk::float32 seconds){
    bool ret=false;
    this->animationPosition.updateClockAnimation(seconds);
    this->animationRotation.updateClockAnimation(seconds);
    this->animationSize.updateClockAnimation(seconds);
    //test if are playing the animations
    if(this->animationPosition.isPlaying()){
        //get X and Y
        this->position = edk::vec2f32(this->animationPosition.getClockX(this->position.x),
                                      this->animationPosition.getClockY(this->position.y)
                                      );
        ret=true;
    }
    if(this->animationRotation.isPlaying()){
        //get the new Angle
        this->angle = this->animationRotation.getClockX();
        ret=true;
    }
    //test if is animating the size
    if(this->animationSize.isPlaying()){
        //
        this->size.width = this->animationSize.getClockX();
        this->size.height = this->animationSize.getClockY();
        ret=true;
    }
    this->updateMeshAnimations(seconds);
    this->updateChildremsAnimations(seconds);
    return ret;
}

//XML
bool edk::physics2D::PhysicObject2D::writeToXML(edk::XML* xml,edk::uint32 id,bool connected){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"physicObject_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //set the string
                        if(connected){
                            xml->setSelectedString("true");
                        }
                        //write object
                        edk::Object2D::writeToXML(xml,id);
                        //write type
                        edk::char8* temp;
                        edk::char8* nameTemp;
                        edk::char8* iTemp;
                        temp = edk::String::int32ToStr(this->getTypeValue());
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"type",temp);
                            free(temp);
                        }
                        //write sensor
                        if(this->isSensor()){
                            xml->addSelectedNextAttribute("sensor","true");
                        }
                        else{
                            xml->addSelectedNextAttribute("sensor","false");
                        }
                        //write fixedRot
                        if(this->fixedRotation){
                            xml->addSelectedNextAttribute("fixedRot","true");
                        }
                        else{
                            xml->addSelectedNextAttribute("fixedRot","false");
                        }
                        //write canSleep
                        if(this->canSleep){
                            xml->addSelectedNextAttribute("canSleep","true");
                        }
                        else{
                            xml->addSelectedNextAttribute("canSleep","false");
                        }
                        //write the mesh
                        this->physicMesh.writeToXML(xml,0u);
                        edk::uint32 size = 0u;
                        //write collision groups
                        if(xml->addSelectedNextChild("collision")){
                            if(xml->selectChild("collision")){
                                size = this->treeCollisionGroups.size();
                                for(edk::uint32 i= 0u;i<size;i++){
                                    temp = edk::String::int64ToStr(this->treeCollisionGroups.getElementInPosition(i));
                                    if(temp){
                                        iTemp = edk::String::int64ToStr(i);
                                        if(iTemp){
                                            nameTemp = edk::String::strCat((edk::char8*)"c",iTemp);
                                            if(nameTemp){
                                                xml->addSelectedNextAttribute(nameTemp,temp);
                                                free(nameTemp);
                                            }
                                            free(iTemp);
                                        }
                                        free(temp);
                                    }
                                }
                                xml->selectFather();
                            }
                        }
                        //write notCollision groups
                        if(xml->addSelectedNextChild("notCollision")){
                            if(xml->selectChild("notCollision")){
                                size = this->treeCollisionGroups.size();
                                for(edk::uint32 i= 0u;i<size;i++){
                                    temp = edk::String::int64ToStr(this->treeCollisionGroups.getElementInPosition(i));
                                    if(temp){
                                        iTemp = edk::String::int64ToStr(i);
                                        if(iTemp){
                                            nameTemp = edk::String::strCat((edk::char8*)"n",iTemp);
                                            if(nameTemp){
                                                xml->addSelectedNextAttribute(nameTemp,temp);
                                                free(nameTemp);
                                            }
                                            free(iTemp);
                                        }
                                        free(temp);
                                    }
                                }
                                xml->selectFather();
                            }
                        }
                        //write physics animations
                        this->animationPosition.writeToXML(xml,0u);
                        //this->animationPositionX.writeToXML(xml,0u);
                        //this->animationPositionY.writeToXML(xml,0u);
                        this->animationRotation.writeToXML(xml,1u);

                        ret=true;
                        xml->selectFather();
                    }
                }
                free(name);
            }
            free(nameID);
        }
        return ret;
    }
    return false;
}
bool edk::physics2D::PhysicObject2D::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"physicObject_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    edk::char8* nameTemp;
                    edk::char8* iTemp;
                    this->physicMesh.cleanPolygons();
                    //read the object
                    edk::Object2D::readFromXML(xml,id);
                    //read type
                    edk::uint32 newType = edk::String::strToInt32(xml->getSelectedAttributeValueByName("type"));
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
                        this->isObjectSensor=true;
                    }
                    else{
                        this->isObjectSensor=false;
                    }
                    //read fixedRot
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("fixedRot"),(edk::char8*)"true")){
                        this->fixedRotation=true;
                    }
                    else{
                        this->fixedRotation=false;
                    }
                    //read canSleep
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("canSleep"),(edk::char8*)"true")){
                        this->canSleep=true;
                    }
                    else{
                        this->canSleep=false;
                    }
                    //read mesh
                    this->physicMesh.readFromXML(xml,0u);
                    //read collisionGroup
                    this->treeCollisionGroups.clean();
                    if(xml->selectChild("collision")){
                        edk::uint32 i=0u;
                        bool cont=true;
                        do{
                            iTemp = edk::String::int64ToStr(i);
                            if(iTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"c",iTemp);
                                if(nameTemp){
                                    if(xml->haveSelectedAttribute(nameTemp)){
                                        //read the value
                                        this->treeCollisionGroups.add(edk::String::strToInt64(xml->getSelectedAttributeValueByName(nameTemp)));
                                    }
                                    else{
                                        cont=false;
                                    }
                                    free(nameTemp);
                                }
                                free(iTemp);
                            }
                            i++;
                        }while(cont);
                        xml->selectFather();
                    }
                    //read notCollisionGroup
                    this->treeNotCollisionGroups.clean();
                    if(xml->selectChild("notCollision")){
                        edk::uint32 i=0u;
                        bool cont=true;
                        do{
                            iTemp = edk::String::int64ToStr(i);
                            if(iTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"n",iTemp);
                                if(nameTemp){
                                    if(xml->haveSelectedAttribute(nameTemp)){
                                        //read the value
                                        this->treeNotCollisionGroups.add(edk::String::strToInt64(xml->getSelectedAttributeValueByName(nameTemp)));
                                    }
                                    else{
                                        cont=false;
                                    }
                                    free(nameTemp);
                                }
                                free(iTemp);
                            }
                            i++;
                        }while(cont);
                        xml->selectFather();
                    }
                    //write physics animations
                    this->animationPosition.readFromXML(xml,0u);
                    //this->animationPositionX.readFromXML(xml,0u);
                    //this->animationPositionY.readFromXML(xml,0u);
                    this->animationRotation.readFromXML(xml,1u);

                    ret=true;
                    xml->selectFather();
                }
                free(name);
            }
            free(nameID);
        }
        return ret;
    }
    return false;
}
bool edk::physics2D::PhysicObject2D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    if(xml && pack){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"physicObject_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    edk::char8* nameTemp;
                    edk::char8* iTemp;
                    this->physicMesh.cleanPolygons();
                    //read the object
                    edk::Object2D::readFromXMLFromPack(pack,xml,id);
                    //read type
                    edk::uint32 newType = edk::String::strToInt32(xml->getSelectedAttributeValueByName("type"));
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
                        this->isObjectSensor=true;
                    }
                    else{
                        this->isObjectSensor=false; }
                    //read fixedRot
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("fixedRot"),(edk::char8*)"true")){
                        this->fixedRotation=true;
                    }
                    else{
                        this->fixedRotation=false;
                    }
                    //read canSleep
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("canSleep"),(edk::char8*)"true")){
                        this->canSleep=true;
                    }
                    else{
                        this->canSleep=false;
                    }
                    //read mesh
                    this->physicMesh.readFromXML(xml,0u);
                    //read collisionGroup
                    this->treeCollisionGroups.clean();
                    if(xml->selectChild("collision")){
                        edk::uint32 i=0u;
                        bool cont=true;
                        do{
                            iTemp = edk::String::int64ToStr(i);
                            if(iTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"c",iTemp);
                                if(nameTemp){
                                    if(xml->haveSelectedAttribute(nameTemp)){
                                        //read the value
                                        this->treeCollisionGroups.add(edk::String::strToInt64(xml->getSelectedAttributeValueByName(nameTemp)));
                                    }
                                    else{
                                        cont=false;
                                    }
                                    free(nameTemp);
                                }
                                free(iTemp);
                            }
                            i++;
                        }while(cont);
                        xml->selectFather();
                    }
                    //read notCollisionGroup
                    this->treeNotCollisionGroups.clean();
                    if(xml->selectChild("notCollision")){
                        edk::uint32 i=0u;
                        bool cont=true;
                        do{
                            iTemp = edk::String::int64ToStr(i);
                            if(iTemp){
                                nameTemp = edk::String::strCat((edk::char8*)"n",iTemp);
                                if(nameTemp){
                                    if(xml->haveSelectedAttribute(nameTemp)){
                                        //read the value
                                        this->treeNotCollisionGroups.add(edk::String::strToInt64(xml->getSelectedAttributeValueByName(nameTemp)));
                                    }
                                    else{
                                        cont=false;
                                    }
                                    free(nameTemp);
                                }
                                free(iTemp);
                            }
                            i++;
                        }while(cont);
                        xml->selectFather();
                    }
                    //write physics animations
                    this->animationPosition.readFromXML(xml,0u);
                    //this->animationPositionX.readFromXML(xml,0u);
                    //this->animationPositionY.readFromXML(xml,0u);
                    this->animationRotation.readFromXML(xml,1u);

                    ret=true;
                    xml->selectFather();
                }
                free(name);
            }
            free(nameID);
        }
        return ret;
    }
    return false;
}
bool edk::physics2D::PhysicObject2D::readFromXMLisSensor(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"physicObject_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //read sensor
                    if(edk::String::strCompare(xml->getSelectedAttributeValueByName("sensor"),(edk::char8*)"true")){
                        ret=true;
                    }
                    else{
                        ret=false;
                    }
                    xml->selectFather();
                }
                free(name);
            }
            free(nameID);
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
        edk::Object2D::cloneFrom(obj);
        //copy the mesh
        //this->physicMesh=obj->physicMesh;
        this->physicMesh.cloneFrom(&obj->physicMesh);
        this->canSleep = obj->canSleep;
        this->fixedRotation = obj->fixedRotation;
        this->animationPosition.cloneFrom(&obj->animationPosition);
        //this->animationRotation = obj->animationRotation;
        this->animationRotation.cloneFrom(&obj->animationRotation);

        //copy the collision groups
        edk::uint32 size;
        size = obj->treeCollisionGroups.size();
        for(edk::uint32 i=0u;i<size;i++){
            this->treeCollisionGroups.add(obj->treeCollisionGroups.getElementInPosition(i));
        }
        size = obj->treeNotCollisionGroups.size();
        for(edk::uint32 i=0u;i<size;i++){
            this->treeNotCollisionGroups.add(obj->treeNotCollisionGroups.getElementInPosition(i));
        }
        return true;
    }
    return false;
}
bool edk::physics2D::PhysicObject2D::cloneFromWithType(edk::physics2D::PhysicObject2D* obj){
    if(obj){
        edk::Object2D::cloneFrom(obj);
        //copy the mesh
        //this->physicMesh=obj->physicMesh;
        this->physicMesh.cloneFrom(&obj->physicMesh);
        this->canSleep = obj->canSleep;
        this->fixedRotation = obj->fixedRotation;
        this->animationPosition.cloneFrom(&obj->animationPosition);
        //this->animationRotation = obj->animationRotation;
        this->animationRotation.cloneFrom(&obj->animationRotation);
        this->type=obj->type;

        //copy the collision groups
        edk::uint32 size;
        size = obj->treeCollisionGroups.size();
        for(edk::uint32 i=0u;i<size;i++){
            this->treeCollisionGroups.add(obj->treeCollisionGroups.getElementInPosition(i));
        }
        size = obj->treeNotCollisionGroups.size();
        for(edk::uint32 i=0u;i<size;i++){
            this->treeNotCollisionGroups.add(obj->treeNotCollisionGroups.getElementInPosition(i));
        }
        return true;
    }
    return false;
}

bool edk::physics2D::PhysicObject2D::cloneFrom(edk::Object2D* obj){
    if(obj){
        edk::Object2D::cloneFrom(obj);
        return true;
    }
    return false;
}
