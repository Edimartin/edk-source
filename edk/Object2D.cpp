#include "Object2D.h"

/*
Library Object2D - Object in the 2D world.
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
#pragma message "            Inside Object2D.cpp"
#endif

edk::Object2D::Object2D(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::Object2D::~Object2D(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        /*
    this->actions.cleanReadXMLActionFunction();edkEnd();
    */
        //dtor
        if(this->canDeleteObject){
            this->cleanMeshes();edkEnd();
        }
        else{
            this->meshes.cantDestroy();edkEnd();
            this->meshes.cantDeleteMeshes();edkEnd();
            this->animationPosition.cantDeleteGroup();edkEnd();
            this->animationRotation.cantDeleteGroup();edkEnd();
            this->animationSize.cantDeleteGroup();edkEnd();
            /*
        this->actions.cantDeleteGroup();edkEnd();
        */
        }
        this->canDeleteObject=true;edkEnd();
    }
}

void edk::Object2D::Constructor(bool runFather){
    if(runFather){
        edk::Object2DValues::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;

        this->meshes.Constructor();
        this->matrixPosition.Constructor();
        this->matrixPivo.Constructor();
        this->matrixAngle.Constructor();
        this->matrixSize.Constructor();
        this->matrixTransform.Constructor();
        this->childremsFront.Constructor();
        this->childremsBack.Constructor();

        //
        this->type=edk::TypeObject2D;
        this->selected=NULL;edkEnd();
        //rotation
        this->angle=0.0f;edkEnd();
        //Scale
        this->size = edk::size2f32(1.f,1.f);edkEnd();
        this->canDeleteObject=true;edkEnd();
        /*
    this->actions.setReadXMLActionFunction(&edk::Object2D::readXMLAction);edkEnd();
    */
        this->father=NULL;

        this->newSize=1.f;
        this->loadSaveIdentityValues();
    }
}

void edk::Object2D::writeFatherBoundingBox(edk::rectf32* rect,edk::vector::Matrixf32<3u,3u>* transformMat){
    if(this->father){
        //calculate the boundingBox from the father
        this->father->writeFatherBoundingBox(rect,transformMat);

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->matrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
        //translate
        transformMat->multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        //angle
        transformMat->multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
        //scale
        transformMat->multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        //Pivo
        transformMat->multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
        //translate
        transformMat->multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        //angle
        transformMat->multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
        //scale
        transformMat->multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        //Pivo
        transformMat->multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
    }
}
bool edk::Object2D::writeBoundingBox(edk::rectf32* rect){
    //multiply the matrix by
    this->matrixTransform.setIdentity();edkEnd();
    if(this->father){
        //calculate the boundingBox from the father
        this->father->writeFatherBoundingBox(rect,&this->matrixTransform);

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->matrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
    }


    edk::shape::Mesh2D* mesh;edkEnd();
    edk::uint32 size = this->meshes.size();edkEnd();
    if(size){
        mesh = this->meshes.getMesh(0u);edkEnd();
        if(mesh){
            if(this->father){
                mesh->calculateBoundingBox(rect,&this->matrixTransform);edkEnd();
            }
            else{
                *rect = mesh->generateBoundingBox(&this->matrixTransform);edkEnd();
            }
        }
        for(edk::uint32 i=1u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);edkEnd();
            if(mesh){
                mesh->calculateBoundingBox(rect,&this->matrixTransform);edkEnd();
            }
        }
        return true;
    }
    else{
        //generate a small boundingBox
        rect->origin = this->position - 0.1f;
        rect->size = edk::size2f32(this->position.x + 0.1f,this->position.y + 0.1f);
    }
    return false;
}
bool edk::Object2D::writeBoundingBox(edk::rectf32* rect,edk::vector::Matrixf32<3u,3u>* transformMat){
    //first copy the matrix
    if(this->matrixTransform.cloneFrom(transformMat)){
        if(this->father){
            //calculate the boundingBox from the father
            this->father->writeFatherBoundingBox(rect,&this->matrixTransform);

            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->matrixAngle);edkEnd();
            edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
        }
        else{
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
        }



        edk::shape::Mesh2D* mesh;edkEnd();
        edk::uint32 size = this->meshes.size();edkEnd();
        if(size){
            mesh = this->meshes.getMesh(0u);edkEnd();
            if(mesh){
                if(this->father){
                    *rect = mesh->generateBoundingBox(&this->matrixTransform);edkEnd();
                }
                else{
                    mesh->calculateBoundingBox(rect,&this->matrixTransform);edkEnd();
                }
            }
            for(edk::uint32 i=1u;i<size;i++){
                //
                mesh = this->meshes.getMesh(i);edkEnd();
                if(mesh){
                    mesh->calculateBoundingBox(rect,&this->matrixTransform);edkEnd();
                }
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
bool edk::Object2D::writeChildremBoundingBox(edk::rectf32* rect){
    edk::uint32 size=0u;
    bool ret = false;
    edk::rectf32 newRect;
    //multiply the matrix by
    this->matrixTransform.setIdentity();edkEnd();
    if(this->father){
        //calculate the boundingBox from the father
        this->father->writeFatherBoundingBox(rect,&this->matrixTransform);

        edk::Math::generateScaleMatrix(edk::size2f32(1.f/this->father->size.width,1.f/this->father->size.height)
                                       ,&this->matrixSize
                                       );edkEnd();
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position + this->connectedPosition,&this->matrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();

        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
    }

    edk::shape::Mesh2D* mesh;edkEnd();
    size = this->meshes.size();edkEnd();
    if(size){
        mesh = this->meshes.getMesh(0u);edkEnd();
        if(mesh){
            if(this->father){
                mesh->calculateBoundingBox(rect,&this->matrixTransform);edkEnd();
            }
            else{
                *rect = mesh->generateBoundingBox(&this->matrixTransform);edkEnd();
            }
        }
        for(edk::uint32 i=1u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);edkEnd();
            if(mesh){
                mesh->calculateBoundingBox(rect,&this->matrixTransform);edkEnd();
            }
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
bool edk::Object2D::writeChildremBoundingBox(edk::rectf32* rect,edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::uint32 size=0u;
    //first copy the matrix
    if(this->matrixTransform.cloneFrom(transformMat)){
        if(this->father){
            //calculate the boundingBox from the father
            this->father->writeBoundingBox(rect,&this->matrixTransform);

            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->matrixAngle);edkEnd();
            edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
        }
        else{
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
        }

        edk::shape::Mesh2D* mesh;edkEnd();
        size = this->meshes.size();edkEnd();
        if(size){
            mesh = this->meshes.getMesh(0u);edkEnd();
            if(mesh){
                if(this->father){
                    *rect = mesh->generateBoundingBox(&this->matrixTransform);edkEnd();
                }
                else{
                    mesh->calculateBoundingBox(rect,&this->matrixTransform);edkEnd();
                }
            }
            for(edk::uint32 i=1u;i<size;i++){
                //
                mesh = this->meshes.getMesh(i);edkEnd();
                if(mesh){
                    mesh->calculateBoundingBox(rect,&this->matrixTransform);edkEnd();
                }
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

//Function to read the actions
edk::Action* edk::Object2D::readXMLAction(edk::classID /*thisPointer*/,edk::uint32 /*actionCode*/){
    /*
    switch(actionCode){
    case 1u:
    {
        //ActionPosition
        return new edk::Object2D::ActionPosition((edk::Object2D*)thisPointer,edk::vec2f32(0,0));edkEnd();
        break;
    }
    case 2u:
    {
        //ActionMove
        return new edk::Object2D::ActionMove((edk::Object2D*)thisPointer,0,edk::vec2f32(0,0));edkEnd();
        break;
    }
    case 3u:
    {
        //ActionSetSize
        return new edk::Object2D::ActionSetSize((edk::Object2D*)thisPointer,edk::size2f32(1,1));edkEnd();
        break;
    }
    case 4u:
    {
        //ActionSize
        return new edk::Object2D::ActionSize((edk::Object2D*)thisPointer,0,edk::size2f32(1,1));edkEnd();
        break;
    }
    case 5u:
    {
        //ActionSetAngle
        return new edk::Object2D::ActionSetAngle((edk::Object2D*)thisPointer,0);edkEnd();
        break;
    }
    case 6u:
    {
        //ActionAngle
        return new edk::Object2D::ActionAngle((edk::Object2D*)thisPointer,0,0);edkEnd();
        break;
    }
    case 7u:
    {
        //ActionMeshName
        return new edk::Object2D::ActionMeshName((edk::Object2D*)thisPointer,0,NULL,false);edkEnd();
        break;
    }
    case 8u:
    {
        //ActionMeshStop
        return new edk::Object2D::ActionMeshStop((edk::Object2D*)thisPointer,0);edkEnd();
        break;
    }
    }
    */
    return new edk::ActionZero();edkEnd();
}

//draw the mesh
void edk::Object2D::drawChildremsBackBoundingBox(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBackBoundingBox();
    }
}
void edk::Object2D::drawChildBackBoundingBox(){
    //test if have a father
    //if(this->father){
    this->updateChangedValues();
    //    //put the transformation on a stack
    //    edk::GU::guPushMatrix();edkEnd();
    //
    //    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);edkEnd();
    //
    //    edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    //    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );edkEnd();
    //    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);edkEnd();
    //    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.size.height);edkEnd();
    //    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.origin.y   );edkEnd();
    //    edk::GU::guEnd();edkEnd();
    //
    //    edk::GU::guPopMatrix();edkEnd();
    //}
    //else{
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);edkEnd();

    this->drawChildremsBackBoundingBox();

    edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );edkEnd();
    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);edkEnd();
    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.size.height);edkEnd();
    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.origin.y   );edkEnd();
    edk::GU::guEnd();edkEnd();

    edk::GU::guPopMatrix();edkEnd();
    //}
}
void edk::Object2D::drawChildremsFrontBoundingBox(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildFrontBoundingBox();
    }
}
void edk::Object2D::drawChildFrontBoundingBox(){
    //test if have a father
    //if(this->father){
    this->updateChangedValues();
    //    //put the transformation on a stack
    //    edk::GU::guPushMatrix();edkEnd();
    //
    //    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);edkEnd();
    //
    //    edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    //    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );edkEnd();
    //    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);edkEnd();
    //    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.size.height);edkEnd();
    //    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.origin.y   );edkEnd();
    //    edk::GU::guEnd();edkEnd();
    //
    //    edk::GU::guPopMatrix();edkEnd();
    //}
    //else{
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);edkEnd();

    edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );edkEnd();
    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);edkEnd();
    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.size.height);edkEnd();
    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.origin.y   );edkEnd();
    edk::GU::guEnd();edkEnd();

    this->drawChildremsFrontBoundingBox();
    edk::GU::guPopMatrix();edkEnd();
    //}
}
void edk::Object2D::drawChildremsBoundingBox(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBackBoundingBox();
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildFrontBoundingBox();
    }
}
void edk::Object2D::drawChildBoundingBox(){
    //test if have a father
    //if(this->father){
    this->updateChangedValues();
    //    //put the transformation on a stack
    //    edk::GU::guPushMatrix();edkEnd();
    //
    //    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);edkEnd();
    //
    //    edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    //    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );edkEnd();
    //    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);edkEnd();
    //    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.size.height);edkEnd();
    //    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.origin.y   );edkEnd();
    //    edk::GU::guEnd();edkEnd();
    //
    //    edk::GU::guPopMatrix();edkEnd();
    //}
    //else{
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);edkEnd();

    this->drawChildremsBackBoundingBox();

    edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );edkEnd();
    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);edkEnd();
    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.size.height);edkEnd();
    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.origin.y   );edkEnd();
    edk::GU::guEnd();edkEnd();

    this->drawChildremsFrontBoundingBox();
    edk::GU::guPopMatrix();edkEnd();
    //}
}
void edk::Object2D::drawChildremsBack(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBack(haveLight);
    }
}
void edk::Object2D::drawChildBack(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    this->updateChangedValues();
    //add translate
    edk::GU::guTranslate2f32(this->connectedPosition);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->connectedSize);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->connectedAngle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBack(haveLight);

    edk::shape::Mesh2D* mesh;edkEnd();
    if(haveLight){
        edk::uint32 size = this->meshes.size();edkEnd();
        for(edk::uint32 i=size;i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    mesh->drawOneTexture();edkEnd();
                }
                else{
                    mesh->drawMultiTexture();edkEnd();
                }
            }
        }
    }
    else{
        edk::uint32 size = this->meshes.size();edkEnd();
        for(edk::uint32 i=size;i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    mesh->drawOneTexture();edkEnd();
                }
                else{
                    mesh->drawMultiTexture();edkEnd();
                }
            }
        }
    }
    //glEnable(GL_RESCALE_NORMAL);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawChildremsFront(bool haveLight){
    edk::uint32 size = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildFront(haveLight);
    }
}
void edk::Object2D::drawChildFront(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    this->updateChangedValues();
    //add translate
    edk::GU::guTranslate2f32(this->connectedPosition);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->connectedSize);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->connectedAngle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    edk::shape::Mesh2D* mesh;edkEnd();
    if(haveLight){
        edk::uint32 size = this->meshes.size();edkEnd();
        for(edk::uint32 i=size;i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    mesh->drawOneTexture();edkEnd();
                }
                else{
                    mesh->drawMultiTexture();edkEnd();
                }
            }
        }
    }
    else{
        edk::uint32 size = this->meshes.size();edkEnd();
        for(edk::uint32 i=size;i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    mesh->drawOneTexture();edkEnd();
                }
                else{
                    mesh->drawMultiTexture();edkEnd();
                }
            }
        }
    }
    this->drawChildremsFront(haveLight);
    //glEnable(GL_RESCALE_NORMAL);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawChildrems(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBack(haveLight);
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildFront(haveLight);
    }
}
void edk::Object2D::drawChild(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    this->updateChangedValues();
    //add translate
    edk::GU::guTranslate2f32(this->connectedPosition);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->connectedSize);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->connectedAngle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBack(haveLight);

    edk::shape::Mesh2D* mesh;edkEnd();
    if(haveLight){
        edk::uint32 size = this->meshes.size();edkEnd();
        for(edk::uint32 i=size;i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    mesh->drawOneTexture();edkEnd();
                }
                else{
                    mesh->drawMultiTexture();edkEnd();
                }
            }
        }
    }
    else{
        edk::uint32 size = this->meshes.size();edkEnd();
        for(edk::uint32 i=size;i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    mesh->drawOneTexture();edkEnd();
                }
                else{
                    mesh->drawMultiTexture();edkEnd();
                }
            }
        }
    }
    this->drawChildremsFront(haveLight);
    //glEnable(GL_RESCALE_NORMAL);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawChildremsBackOneTexture(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBackOneTexture();
    }
}
void edk::Object2D::drawChildBackOneTexture(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    this->updateChangedValues();
    //add translate
    edk::GU::guTranslate2f32(this->connectedPosition);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->connectedSize);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->connectedAngle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackOneTexture();

    edk::shape::Mesh2D* mesh;edkEnd();
    //print all polygonList
    for(edk::uint32 i=this->meshes.size();i>0u;i--){
        //
        mesh = this->meshes.getMesh(i-1u);edkEnd();
        if(mesh){
            mesh->drawOneTexture();edkEnd();
        }
    }
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawChildremsFrontOneTexture(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildFrontOneTexture();
    }
}
void edk::Object2D::drawChildFrontOneTexture(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    this->updateChangedValues();
    //add translate
    edk::GU::guTranslate2f32(this->connectedPosition);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->connectedSize);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->connectedAngle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    edk::shape::Mesh2D* mesh;edkEnd();
    //print all polygonList
    for(edk::uint32 i=this->meshes.size();i>0u;i--){
        //
        mesh = this->meshes.getMesh(i-1u);edkEnd();
        if(mesh){
            mesh->drawOneTexture();edkEnd();
        }
    }
    this->drawChildremsFrontOneTexture();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawChildremsOneTexture(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBackOneTexture();
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildFrontOneTexture();
    }
}
void edk::Object2D::drawChildOneTexture(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    this->updateChangedValues();
    //add translate
    edk::GU::guTranslate2f32(this->connectedPosition);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->connectedSize);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->connectedAngle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackOneTexture();

    edk::shape::Mesh2D* mesh;edkEnd();
    //print all polygonList
    for(edk::uint32 i=this->meshes.size();i>0u;i--){
        //
        mesh = this->meshes.getMesh(i-1u);edkEnd();
        if(mesh){
            mesh->drawOneTexture();edkEnd();
        }
    }
    this->drawChildremsFrontOneTexture();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawChildremsBackOneTextureWithLight(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBackOneTextureWithLight(haveLight);
    }
}
void edk::Object2D::drawChildBackOneTextureWithLight(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    this->updateChangedValues();
    //add translate
    edk::GU::guTranslate2f32(this->connectedPosition);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->connectedSize);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->connectedAngle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackOneTextureWithLight(haveLight);

    edk::shape::Mesh2D* mesh;edkEnd();
    if(haveLight){
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                mesh->drawOneTexture();edkEnd();
            }
        }
    }
    else{
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                mesh->drawOneTexture();edkEnd();
            }
        }
    }
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawChildremsFrontOneTextureWithLight(bool haveLight){
    edk::uint32 size = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildFrontOneTextureWithLight(haveLight);
    }
}
void edk::Object2D::drawChildFrontOneTextureWithLight(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    this->updateChangedValues();
    //add translate
    edk::GU::guTranslate2f32(this->connectedPosition);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->connectedSize);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->connectedAngle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    edk::shape::Mesh2D* mesh;edkEnd();
    if(haveLight){
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                mesh->drawOneTexture();edkEnd();
            }
        }
    }
    else{
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                mesh->drawOneTexture();edkEnd();
            }
        }
    }
    this->drawChildremsFrontOneTextureWithLight(haveLight);
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawChildremsOneTextureWithLight(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBackOneTextureWithLight(haveLight);
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildFrontOneTextureWithLight(haveLight);
    }
}
void edk::Object2D::drawChildOneTextureWithLight(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    this->updateChangedValues();
    //add translate
    edk::GU::guTranslate2f32(this->connectedPosition);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->connectedSize);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->connectedAngle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackOneTextureWithLight(haveLight);

    edk::shape::Mesh2D* mesh;edkEnd();
    if(haveLight){
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                mesh->drawOneTexture();edkEnd();
            }
        }
    }
    else{
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                mesh->drawOneTexture();edkEnd();
            }
        }
    }
    this->drawChildremsFrontOneTextureWithLight(haveLight);
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawChildremsBackWithoutMaterial(){
    edk::GU::guScale2f32(1.f/this->size.width,1.f/this->size.height);edkEnd();
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBackWithoutMaterial();
    }
    edk::GU::guScale2f32(this->size);edkEnd();
}
void edk::Object2D::drawChildBackWithoutMaterial(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    this->updateChangedValues();
    //add translate
    edk::GU::guTranslate2f32(this->position + this->connectedPosition);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWithoutMaterial();

    edk::shape::Mesh2D* mesh;edkEnd();
    //print all polygonList
    for(edk::uint32 i=this->meshes.size();i>0u;i--){
        //
        mesh = this->meshes.getMesh(i-1u);edkEnd();
        if(mesh){
            mesh->drawWithoutMaterial();edkEnd();
        }
    }
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawChildremsFrontWithoutMaterial(){
    edk::GU::guScale2f32(1.f/this->size.width,1.f/this->size.height);edkEnd();
    edk::uint32 size = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildFrontWithoutMaterial();
    }
    edk::GU::guScale2f32(this->size);edkEnd();
}
void edk::Object2D::drawChildFrontWithoutMaterial(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    this->updateChangedValues();
    //add translate
    edk::GU::guTranslate2f32(this->connectedPosition);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->connectedSize);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->connectedAngle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    edk::shape::Mesh2D* mesh;edkEnd();
    //print all polygonList
    for(edk::uint32 i=this->meshes.size();i>0u;i--){
        //
        mesh = this->meshes.getMesh(i-1u);edkEnd();
        if(mesh){
            mesh->drawWithoutMaterial();edkEnd();
        }
    }
    this->drawChildremsFrontWithoutMaterial();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawChildremsWithoutMaterial(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBackWithoutMaterial();
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildFrontWithoutMaterial();
    }
}
void edk::Object2D::drawChildWithoutMaterial(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    this->updateChangedValues();
    //add translate
    edk::GU::guTranslate2f32(this->connectedPosition);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->connectedSize);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->connectedAngle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWithoutMaterial();

    edk::shape::Mesh2D* mesh;edkEnd();
    //print all polygonList
    for(edk::uint32 i=this->meshes.size();i>0u;i--){
        //
        mesh = this->meshes.getMesh(i-1u);edkEnd();
        if(mesh){
            mesh->drawWithoutMaterial();edkEnd();
        }
    }
    this->drawChildremsFrontWithoutMaterial();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawChildremsBackWithoutMaterialWithLight(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBackWithoutMaterialWithLight(haveLight);
    }
}
void edk::Object2D::drawChildBackWithoutMaterialWithLight(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();


    this->updateChangedValues();
    //add translate
    edk::GU::guTranslate2f32(this->connectedPosition);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->connectedSize);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->connectedAngle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWithoutMaterialWithLight(haveLight);

    edk::shape::Mesh2D* mesh;edkEnd();
    if(haveLight){
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                mesh->drawWithoutMaterial();edkEnd();
            }
        }
    }
    else{
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                mesh->drawWithoutMaterial();edkEnd();
            }
        }
    }
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawChildremsFrontWithoutMaterialWithLight(bool haveLight){
    edk::uint32 size = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildFrontWithoutMaterialWithLight(haveLight);
    }
}
void edk::Object2D::drawChildFrontWithoutMaterialWithLight(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();


    this->updateChangedValues();
    //add translate
    edk::GU::guTranslate2f32(this->connectedPosition);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->connectedSize);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->connectedAngle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    edk::shape::Mesh2D* mesh;edkEnd();
    if(haveLight){
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                mesh->drawWithoutMaterial();edkEnd();
            }
        }
    }
    else{
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                mesh->drawWithoutMaterial();edkEnd();
            }
        }
    }
    this->drawChildremsFrontWithoutMaterialWithLight(haveLight);
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawChildremsWithoutMaterialWithLight(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBackWithoutMaterialWithLight(haveLight);
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildFrontWithoutMaterialWithLight(haveLight);
    }
}
void edk::Object2D::drawChildWithoutMaterialWithLight(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();


    this->updateChangedValues();
    //add translate
    edk::GU::guTranslate2f32(this->connectedPosition);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->connectedSize);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->connectedAngle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWithoutMaterialWithLight(haveLight);

    edk::shape::Mesh2D* mesh;edkEnd();
    if(haveLight){
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                mesh->drawWithoutMaterial();edkEnd();
            }
        }
    }
    else{
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                mesh->drawWithoutMaterial();edkEnd();
            }
        }
    }
    this->drawChildremsFrontWithoutMaterialWithLight(haveLight);
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawChildremsBackWire(){
    edk::GU::guScale2f32(1.f/this->size.width,1.f/this->size.height);edkEnd();
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBackWire();
    }
    edk::GU::guScale2f32(this->size);edkEnd();
}
void edk::Object2D::drawChildBackWire(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    this->updateChangedValues();
    //add translate
    edk::GU::guTranslate2f32(this->position + this->connectedPosition);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWire();

    edk::shape::Mesh2D* mesh;edkEnd();
    //print all polygonList
    for(edk::uint32 i=this->meshes.size();i>0u;i--){
        //
        mesh = this->meshes.getMesh(i-1u);edkEnd();
        if(mesh){
            mesh->drawWirePolygons();edkEnd();
        }
    }
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawChildremsFrontWire(){
    edk::GU::guScale2f32(1.f/this->size.width,1.f/this->size.height);edkEnd();
    edk::uint32 size = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildFrontWire();
    }
    edk::GU::guScale2f32(this->size);edkEnd();
}
void edk::Object2D::drawChildFrontWire(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    this->updateChangedValues();
    //add translate
    edk::GU::guTranslate2f32(this->connectedPosition);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->connectedSize);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->connectedAngle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    edk::shape::Mesh2D* mesh;edkEnd();
    //print all polygonList
    for(edk::uint32 i=this->meshes.size();i>0u;i--){
        //
        mesh = this->meshes.getMesh(i-1u);edkEnd();
        if(mesh){
            mesh->drawWirePolygons();edkEnd();
        }
    }
    this->drawChildremsFrontWire();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawChildremsWire(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBackWire();
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildFrontWire();
    }
}
void edk::Object2D::drawChildWire(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    this->updateChangedValues();
    //add translate
    edk::GU::guTranslate2f32(this->connectedPosition);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->connectedSize);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->connectedAngle);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWire();

    edk::shape::Mesh2D* mesh;edkEnd();
    //print all polygonList
    for(edk::uint32 i=this->meshes.size();i>0u;i--){
        //
        mesh = this->meshes.getMesh(i-1u);edkEnd();
        if(mesh){
            mesh->drawWirePolygons();edkEnd();
        }
    }
    this->drawChildremsFrontWire();
    edk::GU::guPopMatrix();edkEnd();
}
//draw the pivo
void edk::Object2D::drawChildremsBackPivo(edk::float32 size,edk::color3f32 color){
    edk::uint32 cSize = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBackPivo(size,color);
    }
}
void edk::Object2D::drawChildBackPivo(edk::float32 size,edk::color3f32 color){
    edk::Object2D::drawPivoInPosition(this->connectedPosition,size,color);
    if(this->childremsBack.size()){
        edk::GU::guPushMatrix();edkEnd();
        //add translate
        edk::GU::guTranslate2f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateZf32(this->angle);edkEnd();
        //add scale
        edk::GU::guScale2f32(this->size);edkEnd();
        //set the pivo
        edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();
        this->drawChildremsBackPivo(size,color);
        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::Object2D::drawChildremsFrontPivo(edk::float32 size,edk::color3f32 color){
    edk::uint32 cSize = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildFrontPivo(size,color);
    }
}
void edk::Object2D::drawChildFrontPivo(edk::float32 size,edk::color3f32 color){
    edk::Object2D::drawPivoInPosition(this->connectedPosition,size,color);
    if(this->childremsFront.size()){
        edk::GU::guPushMatrix();edkEnd();
        //add translate
        edk::GU::guTranslate2f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateZf32(this->angle);edkEnd();
        //add scale
        edk::GU::guScale2f32(this->size);edkEnd();
        //set the pivo
        edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();
        this->drawChildremsFrontPivo(size,color);
        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::Object2D::drawChildremsPivo(edk::float32 size,edk::color3f32 color){
    edk::uint32 cSize = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBackPivo(size,color);
    }
    cSize = this->childremsFront.size();
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildFrontPivo(size,color);
    }
}
void edk::Object2D::drawChildPivo(edk::float32 size,edk::color3f32 color){
    if(this->childremsBack.size()){
        edk::GU::guPushMatrix();edkEnd();
        //add translate
        edk::GU::guTranslate2f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateZf32(this->angle);edkEnd();
        //add scale
        edk::GU::guScale2f32(this->size);edkEnd();
        //set the pivo
        edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();
        this->drawChildremsBackPivo(size,color);
        edk::GU::guPopMatrix();edkEnd();
    }
    edk::Object2D::drawPivoInPosition(this->connectedPosition,size,color);
    if(this->childremsFront.size()){
        edk::GU::guPushMatrix();edkEnd();
        //add translate
        edk::GU::guTranslate2f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateZf32(this->angle);edkEnd();
        //add scale
        edk::GU::guScale2f32(this->size);edkEnd();
        //set the pivo
        edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();
        this->drawChildremsFrontPivo(size,color);
        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::Object2D::drawChildremsBackPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::GU::guScale2f32(1.f/this->size.width,1.f/this->size.height);edkEnd();
    edk::uint32 cSize = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBackPivo(size,r,g,b);
    }
    edk::GU::guScale2f32(this->size);edkEnd();
}
void edk::Object2D::drawChildBackPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate2f32(this->position + this->connectedPosition);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();
    if(this->childremsBack.size()){
        this->drawChildremsBackPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();edkEnd();

    edk::GU::guPushMatrix();edkEnd();
    //add translate
    //edk::GU::guTranslate2f32(this->position + this->connectedPosition);edkEnd();

    edk::Object2D::drawPivoInPosition(this->position + this->connectedPosition,size,edk::color3f32(r,g,b));

    edk::GU::guPopMatrix();edkEnd();

    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate2f32(this->position + this->connectedPosition);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();
    if(this->childremsFront.size()){
        this->drawChildremsFrontPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawChildremsFrontPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::GU::guScale2f32(1.f/this->size.width,1.f/this->size.height);edkEnd();
    edk::uint32 cSize = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildFrontPivo(size,r,g,b);
    }
    edk::GU::guScale2f32(this->size);edkEnd();
}
void edk::Object2D::drawChildFrontPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate2f32(this->position + this->connectedPosition);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();
    if(this->childremsBack.size()){
        this->drawChildremsBackPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();edkEnd();


    edk::GU::guPushMatrix();edkEnd();
    //add translate
    //edk::GU::guTranslate2f32(this->position + this->connectedPosition);edkEnd();

    edk::Object2D::drawPivoInPosition(this->position + this->connectedPosition,size,edk::color3f32(r,g,b));

    edk::GU::guPopMatrix();edkEnd();

    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate2f32(this->position + this->connectedPosition);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();
    if(this->childremsFront.size()){
        this->drawChildremsFrontPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawChildremsPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::uint32 cSize = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBackPivo(size,r,g,b);
    }
    cSize = this->childremsFront.size();
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildFrontPivo(size,r,g,b);
    }
}
void edk::Object2D::drawChildPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    if(this->childremsBack.size()){
        edk::Object2D::drawPivoInPosition(this->position,size,edk::color3f32(r,g,b));
        edk::GU::guPushMatrix();edkEnd();
        //add translate
        edk::GU::guTranslate2f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateZf32(this->angle);edkEnd();
        //add scale
        edk::GU::guScale2f32(this->size);edkEnd();
        //set the pivo
        edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();
        this->drawChildremsBackPivo(size,r,g,b);
        edk::GU::guPopMatrix();edkEnd();
    }
    edk::Object2D::drawPivoInPosition(this->connectedPosition,size,edk::color3f32(r,g,b));
    if(this->childremsFront.size()){
        edk::Object2D::drawPivoInPosition(this->position,size,edk::color3f32(r,g,b));
        edk::GU::guPushMatrix();edkEnd();
        //add translate
        edk::GU::guTranslate2f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateZf32(this->angle);edkEnd();
        //add scale
        edk::GU::guScale2f32(this->size);edkEnd();
        //set the pivo
        edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();
        this->drawChildremsFrontPivo(size,r,g,b);
        edk::GU::guPopMatrix();edkEnd();
    }
}
//update animations
void edk::Object2D::updateChildremsAnimations(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->updateAnimations();
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->updateAnimations();
    }
}
void edk::Object2D::updateChildremsAnimations(edk::float32 seconds){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->updateAnimations(seconds);
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->updateAnimations(seconds);
    }
}
//update the values from father
bool edk::Object2D::updateValuesFromFather(edk::vector::Matrixf32<3u,3u>* matrixTransform){
    if(matrixTransform){
        if(this->father){
            //calculate the boundingBox from the father
            this->father->updateValuesFromFather(matrixTransform);

            //first copy the matrix
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->matrixAngle);edkEnd();
            edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
            //translate
            matrixTransform->multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            //angle
            //matrixTransform->multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
            //scale
            //matrixTransform->multiplyThisWithMatrix(&this->matrixSize);edkEnd();
            //Pivo
            matrixTransform->multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
        }
        else{
            matrixTransform->setIdentity();
            //first copy the matrix
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
            //translate
            matrixTransform->multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            //angle
            matrixTransform->multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
            //scale
            matrixTransform->multiplyThisWithMatrix(&this->matrixSize);edkEnd();
            //Pivo
            matrixTransform->multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
        }
        return true;
    }
    return false;
}

//Actions
edk::Object2D::ActionPosition::ActionPosition(edk::Object2D* /*object*/, edk::vec2f32 /*position*/){
    /*
    this->position=position;edkEnd();
    this->object=object;edkEnd();
    this->code = 1u;edkEnd();
    */
}
//run action function
void edk::Object2D::ActionPosition::runAction(){
    this->object->position = this->position;edkEnd();
}
//write to XML
bool edk::Object2D::ActionPosition::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write the position
                    xml->addSelectedNextAttribute("positionX",this->position.x);edkEnd();
                    xml->addSelectedNextAttribute("positionY",this->position.y);edkEnd();

                    ret=true;edkEnd();
                    //select father
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(number);edkEnd();
        }
    }
    return ret;
}
//read XML
bool edk::Object2D::ActionPosition::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read the position
                    this->position.x = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionX"));edkEnd();
                    this->position.y = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionY"));edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(number);edkEnd();
        }
    }
    return ret;
}
//GET
edk::vec2f32 edk::Object2D::ActionPosition::getPosition(){
    return this->position;edkEnd();
}
edk::Object2D::ActionMove::ActionMove(edk::Object2D* object,edk::float32 duration, edk::vec2f32 position){
    this->position=position;edkEnd();
    this->duration = duration;edkEnd();
    this->object=object;edkEnd();
    this->code = 2u;edkEnd();
}
//run action function
void edk::Object2D::ActionMove::runAction(){
    this->object->animationPosition.cleanTracks();edkEnd();
    edk::uint32 track = this->object->animationPosition.newTrack();edkEnd();
    this->object->animationPosition.addFirstInterpolationLine(track,0,this->object->position.x,this->object->position.y,this->duration,this->position.x,this->position.y);edkEnd();
    this->object->animationPosition.playForwardAllTracks();edkEnd();
}
//write to XML
bool edk::Object2D::ActionMove::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write the position
                    xml->addSelectedNextAttribute("positionX",this->position.x);edkEnd();
                    xml->addSelectedNextAttribute("positionY",this->position.y);edkEnd();
                    //write the duration
                    xml->addSelectedNextAttribute("duration",this->duration);edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(number);edkEnd();
        }
    }
    return ret;
}
//read XML
bool edk::Object2D::ActionMove::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;edkEnd();
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read the position
                    this->position.x = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionX"));edkEnd();
                    this->position.y = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionY"));edkEnd();
                    //read duration
                    this->duration = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("duration"));edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(number);edkEnd();
        }
    }
    return ret;
}
//GET
edk::vec2f32 edk::Object2D::ActionMove::getPosition(){
    return this->position;edkEnd();
}
edk::float32 edk::Object2D::ActionMove::getDuration(){
    return this->duration;edkEnd();
}
edk::Object2D::ActionSetSize::ActionSetSize(edk::Object2D* /*object*/, edk::size2f32 /*size*/){
    /*
    this->object=object;edkEnd();
    this->size=size;edkEnd();
    this->code = 3u;edkEnd();
    */
}
//run action function
void edk::Object2D::ActionSetSize::runAction(){
    /*
    this->object->size = this->size;edkEnd();
    */
}
//write to XML
bool edk::Object2D::ActionSetSize::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;edkEnd();
    /*
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write the size
                    xml->addSelectedNextAttribute("width",this->size.width);edkEnd();
                    xml->addSelectedNextAttribute("height",this->size.height);edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(number);edkEnd();
        }
    }
    */
    return ret;
}
//read XML
bool edk::Object2D::ActionSetSize::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;edkEnd();
    /*
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read the code
                    this->size.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("width"));edkEnd();
                    this->size.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("height"));edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(number);edkEnd();
        }
    }
    */
    return ret;
}
//GET
edk::size2f32 edk::Object2D::ActionSetSize::getSize(){
    return this->size;edkEnd();
}
edk::Object2D::ActionSize::ActionSize(edk::Object2D* /*object*/,edk::float32 /*duration*/, edk::size2f32 /*size*/){
    /*
    this->size=size;edkEnd();
    this->duration = duration;edkEnd();
    this->object=object;edkEnd();
    this->code = 4u;edkEnd();
    */
}
//run action function
void edk::Object2D::ActionSize::runAction(){
    /*
    this->object->animationSize.cleanAnimations();edkEnd();
    this->object->animationSize.addFirstInterpolationLine(0,this->object->size.width,this->object->size.height,this->duration,this->size.width,this->size.height);edkEnd();
    this->object->animationSize.playForward();edkEnd();
    */
}
//write to XML
bool edk::Object2D::ActionSize::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;edkEnd();
    /*
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write the size
                    xml->addSelectedNextAttribute("width",this->size.width);edkEnd();
                    xml->addSelectedNextAttribute("height",this->size.height);edkEnd();
                    //write the duration
                    xml->addSelectedNextAttribute("duration",this->duration);edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(number);edkEnd();
        }
    }
    */
    return ret;
}
//read XML
bool edk::Object2D::ActionSize::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;edkEnd();
    /*
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read the code
                    this->size.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("width"));edkEnd();
                    this->size.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("height"));edkEnd();
                    //read the duration
                    this->duration = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("duration"));edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(number);edkEnd();
        }
    }
    */
    return ret;
}
//GET
edk::size2f32 edk::Object2D::ActionSize::getSize(){
    return this->size;edkEnd();
}
edk::float32 edk::Object2D::ActionSize::getDuration(){
    return this->duration;edkEnd();
}
edk::Object2D::ActionSetAngle::ActionSetAngle(edk::Object2D* object, edk::float32 angle){
    this->object = object;edkEnd();
    this->angle = angle;edkEnd();
    this->code = 5u;edkEnd();
}
//run action function
void edk::Object2D::ActionSetAngle::runAction(){
    this->object->angle = this->angle;edkEnd();
}
//write to XML
bool edk::Object2D::ActionSetAngle::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;edkEnd();
    /*
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write angle
                    xml->addSelectedNextAttribute("angle",this->angle);edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(number);edkEnd();
        }
    }
    */
    return ret;
}
//read XML
bool edk::Object2D::ActionSetAngle::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;edkEnd();
    /*
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read angle
                    this->angle = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("angle"));edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(number);edkEnd();
        }
    }
    */
    return ret;
}
//GET
edk::float32 edk::Object2D::ActionSetAngle::getAngle(){
    return this->angle;edkEnd();
}
edk::Object2D::ActionAngle::ActionAngle(edk::Object2D* /*object*/,edk::float32 /*duration*/, edk::float32 /*angle*/){
    /*
    this->object = object;edkEnd();
    this->duration = duration;edkEnd();
    this->angle = angle;edkEnd();
    this->code = 6u;edkEnd();
    */
}
//run action function
void edk::Object2D::ActionAngle::runAction(){
    /*
    this->object->animationRotation.cleanAnimations();edkEnd();
    this->object->animationRotation.addFirstInterpolationLine(0,this->object->angle,this->duration,this->angle);edkEnd();
    this->object->animationRotation.playForward();edkEnd();
    */
}
//write to XML
bool edk::Object2D::ActionAngle::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;edkEnd();
    /*
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write angle
                    xml->addSelectedNextAttribute("angle",this->angle);edkEnd();
                    //write the duration
                    xml->addSelectedNextAttribute("duration",this->duration);edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(number);edkEnd();
        }
    }
    */
    return ret;
}
//read XML
bool edk::Object2D::ActionAngle::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;edkEnd();
    /*
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read angle
                    this->angle = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("angle"));edkEnd();
                    //read duratio
                    this->duration = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("duration"));edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(number);edkEnd();
        }
    }
    */
    return ret;
}
//GET
edk::float32 edk::Object2D::ActionAngle::getAngle(){
    return this->angle;edkEnd();
}
edk::float32 edk::Object2D::ActionAngle::getDuration(){
    return this->duration;edkEnd();
}
edk::Object2D::ActionMeshName::ActionMeshName(edk::Object2D* /*object*/,edk::uint32 /*id*/, edk::char8* /*name*/,bool /*loop*/){
    /*
    this->object=object;edkEnd();
    this->loop = loop;edkEnd();
    this->id = id;edkEnd();
    this->setName(name);edkEnd();
    this->code = 7u;edkEnd();
    */
}
//run action function
void edk::Object2D::ActionMeshName::runAction(){
    /*
    //load the mesh
    edk::shape::Mesh2D* mesh = this->object->getMesh(this->id);edkEnd();
    if(mesh){
        mesh->selectedAnimationSetLoop(this->loop);edkEnd();
        mesh->selectedAnimationPlayNameForward(this->name());edkEnd();
    }
    */
}
//write to XML
bool edk::Object2D::ActionMeshName::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;edkEnd();
    /*
    if(edk::ActionName::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write the loop
                    if(this->loop){
                        xml->setSelectedString("loopOn");edkEnd();
                    }
                    else{
                        xml->setSelectedString("loopOff");edkEnd();
                    }

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(number);edkEnd();
        }
    }
    */
    return ret;
}
//read XML
bool edk::Object2D::ActionMeshName::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;edkEnd();
    /*
    edk::ActionName::readFromXML(xml,id);edkEnd();
    this->id = 7u;edkEnd();
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read the loop
                    if(edk::String::strCompare((edk::char8*)"loopOn",xml->getSelectedString())){
                        this->loop=true;edkEnd();
                    }
                    else{
                        this->loop=false;edkEnd();
                    }

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(number);edkEnd();
        }
    }
    */
    return ret;
}
//GET
edk::uint32 edk::Object2D::ActionMeshName::getId(){
    return this->id;edkEnd();
}
bool edk::Object2D::ActionMeshName::getLoop(){
    return this->loop;edkEnd();
}
edk::Object2D::ActionMeshStop::ActionMeshStop(edk::Object2D* /*object*/,edk::uint32 /*id*/){
    /*
    this->object=object;edkEnd();
    this->id = id;edkEnd();
    this->code = 8u;edkEnd();
    */
}
//run action function
void edk::Object2D::ActionMeshStop::runAction(){
    /*
    //load the mesh
    edk::shape::Mesh2D* mesh = this->object->getMesh(this->id);edkEnd();
    if(mesh){
        mesh->selectedAnimationStop();edkEnd();
    }
    */
}
//write to XML
bool edk::Object2D::ActionMeshStop::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;edkEnd();
    /*
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write the ID
                    xml->addSelectedNextAttribute("id",this->id);edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(number);edkEnd();
        }
    }
    */
    return ret;
}
//read XML
bool edk::Object2D::ActionMeshStop::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;edkEnd();
    /*
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);edkEnd();
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);edkEnd();
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read the id
                    this->id = edk::String::strToInt64(xml->getSelectedAttributeValueByName("id"));edkEnd();

                    ret=true;edkEnd();
                    //then select the father
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(number);edkEnd();
        }
    }
    */
    return ret;
}
//GET
edk::uint32 edk::Object2D::ActionMeshStop::getId(){
    return this->id;edkEnd();
}

//create a new mesh and add to the meshs stack
edk::shape::Mesh2D* edk::Object2D::newMesh(edk::uint32* position){
    return this->meshes.pushNewMesh(position);edkEnd();
}

//clean the obect
void edk::Object2D::clean(){
    //
    this->cleanSelected();edkEnd();
    this->cleanMeshes();edkEnd();
    this->pivo = 0.f;edkEnd();
    this->animationPosition.cleanTracks();edkEnd();
    this->animationRotation.cleanAnimationNameSelected();edkEnd();
    this->animationRotation.cleanAnimationNames();edkEnd();
    this->animationRotation.cleanAnimations();edkEnd();
    this->animationSize.cleanAnimationNameSelected();edkEnd();
    this->animationSize.cleanAnimationNames();edkEnd();
    this->animationSize.cleanAnimations();edkEnd();

    this->position = 0.f;edkEnd();
    this->angle = 0.f;edkEnd();
    this->size = 0.f;edkEnd();

    /*
    this->removeAllActions();edkEnd();
    */
}

//get the bodyType
edk::TypeObject edk::Object2D::getType(){
    return this->type;
}

//Add a list to the Object2D
edk::uint32 edk::Object2D::addMesh(edk::shape::Mesh2D* mesh){
    //test if the list exist
    if(mesh){
        edk::uint32 ret = 0u;edkEnd();
        //then add the mesh to the list
        ret = this->meshes.pushBackMesh(mesh,false);edkEnd();
        if(ret<this->meshes.size()){
            //test if select the first
            if(this->meshes.size()==1u){
                this->selectMesh(0u);edkEnd();
            }
            return ret;
        }
    }

    //else return falses
    return 0u;edkEnd();
}
//remove a polygonlist
bool edk::Object2D::removeMesh(edk::uint32 position){
    //remove the mesh
    return this->meshes.removeMesh(position);edkEnd();
}
//remove all meshes
void edk::Object2D::cleanMeshes(){
    this->cleanSelected();edkEnd();
    this->meshes.removeAllMeshes();edkEnd();
}

//function to calculate boundingBox
bool edk::Object2D::calculateBoundingBox(){
    return this->writeChildremBoundingBox(&this->boundingBox);
}
bool edk::Object2D::calculateBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat){
    return this->writeChildremBoundingBox(&this->boundingBox,transformMat);
}
bool edk::Object2D::generateBoundingBox(){
    return this->writeChildremBoundingBox(&this->boundingBox);
}
bool edk::Object2D::generateBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat){
    return this->writeChildremBoundingBox(&this->boundingBox,transformMat);
}
//functions to calculate a new boundingBox
edk::rectf32 edk::Object2D::calculateNewBoundingBox(){
    edk::rectf32 ret;
    this->writeChildremBoundingBox(&ret);
    return ret;
}
edk::rectf32 edk::Object2D::calculateNewBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::rectf32 ret;
    this->writeChildremBoundingBox(&ret,transformMat);
    return ret;
}
edk::rectf32 edk::Object2D::generateNewBoundingBox(){
    edk::rectf32 ret;
    this->writeChildremBoundingBox(&ret);
    return ret;
}
edk::rectf32 edk::Object2D::generateNewBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::rectf32 ret;
    this->writeChildremBoundingBox(&ret,transformMat);
    return ret;
}

//function to calculate boundingBox
bool edk::Object2D::calculateBoundingBoxNoChildrem(){
    return this->writeBoundingBox(&this->boundingBox);
}
bool edk::Object2D::calculateBoundingBoxNoChildrem(edk::vector::Matrixf32<3u,3u>* transformMat){
    return this->writeBoundingBox(&this->boundingBox,transformMat);
}
bool edk::Object2D::generateBoundingBoxNoChildrem(){
    return this->writeBoundingBox(&this->boundingBox);
}
bool edk::Object2D::generateBoundingBoxNoChildrem(edk::vector::Matrixf32<3u,3u>* transformMat){
    return this->writeBoundingBox(&this->boundingBox,transformMat);
}
//functions to calculate a new boundingBox
edk::rectf32 edk::Object2D::calculateNewBoundingBoxNoChildrem(){
    edk::rectf32 ret;
    this->writeBoundingBox(&ret);
    return ret;
}
edk::rectf32 edk::Object2D::calculateNewBoundingBoxNoChildrem(edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::rectf32 ret;
    this->writeBoundingBox(&ret,transformMat);
    return ret;
}
edk::rectf32 edk::Object2D::generateNewBoundingBoxNoChildrem(){
    edk::rectf32 ret;
    this->writeBoundingBox(&ret);
    return ret;
}
edk::rectf32 edk::Object2D::generateNewBoundingBoxNoChildrem(edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::rectf32 ret;
    this->writeBoundingBox(&ret,transformMat);
    return ret;
}

//return a copy of the boundingBox
edk::rectf32 edk::Object2D::getBoundingBox(){
    return this->boundingBox;
}

//Select the polygonList
bool edk::Object2D::selectMesh(edk::uint32 position){
    //free the selected
    this->cleanSelected();edkEnd();
    if((this->selected = this->meshes.getMesh(position))){
        return true;
    }
    //else return false
    return false;
}
//return the selected textureID
edk::uint32 edk::Object2D::selectedGetTextureID(edk::uint8 number){
    //test if have one selected mesh
    if(this->selected){
        //return the number
        return this->selected->material.getTexture(number);edkEnd();
    }
    //else return false
    return 0u;edkEnd();
}
//free the selected
void edk::Object2D::cleanSelected(){
    //
    this->selected=NULL;edkEnd();
}
//return the number of meshs
edk::uint32 edk::Object2D::getMeshSize(){
    return this->meshes.size();edkEnd();
}
//return the mesh pointer
edk::shape::Mesh2D* edk::Object2D::getMesh(edk::uint32 position){
    return this->meshes.getMesh(position);edkEnd();
}
//remove all meshes
void edk::Object2D::removeAllMesh(){
    this->cleanMeshes();edkEnd();
}
//set the polygonsColor
bool edk::Object2D::setPolygonColor(edk::uint32 position,edk::color4f32 color){
    if(this->meshes.getMesh(position)){
        this->meshes.getMesh(position)->setPolygonsColor(color);edkEnd();
    }
    return false;
}
bool edk::Object2D::setPolygonColor(edk::uint32 position,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setPolygonColor(position,edk::color4f32(r,g,b,a));edkEnd();
}

void edk::Object2D::setPolygonsColor(edk::color4f32 color){
    edk::uint32 size = this->meshes.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColor(color);edkEnd();
        }
    }
}
void edk::Object2D::setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setPolygonsColor(edk::color4f32(r,g,b,a));edkEnd();
}
void edk::Object2D::setPolygonsColorR(edk::float32 r){
    edk::uint32 size = this->meshes.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColorR(r);edkEnd();
        }
    }
}
void edk::Object2D::setPolygonsColorG(edk::float32 g){
    edk::uint32 size = this->meshes.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColorG(g);edkEnd();
        }
    }
}
void edk::Object2D::setPolygonsColorB(edk::float32 b){
    edk::uint32 size = this->meshes.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColorB(b);edkEnd();
        }
    }
}
void edk::Object2D::setPolygonsColorA(edk::float32 a){
    edk::uint32 size = this->meshes.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColorA(a);edkEnd();
        }
    }
}

//get world polygon
bool edk::Object2D::getWorldPolygon(edk::shape::Polygon2D* dest,edk::uint32 meshPosition,edk::uint32 polygonPosition){
    bool ret=false;edkEnd();
    if(dest){
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
        //multiply the matrix by

        this->matrixTransform.setIdentity();edkEnd();

        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();

        edk::shape::Mesh2D* mesh = this->meshes.getMesh(meshPosition);edkEnd();
        if(mesh){
            ret = mesh->getWorldPolygon(dest,polygonPosition,&this->matrixTransform);edkEnd();
        }
    }
    return ret;
}
bool edk::Object2D::getWorldPolygon(edk::shape::Polygon2D* dest,edk::uint32 meshPosition,edk::uint32 polygonPosition,edk::vector::Matrixf32<3u,3u>* transformMat){
    bool ret=false;edkEnd();
    if(dest){
        //first copy the matrix
        if(this->matrixTransform.cloneFrom(transformMat)){
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();

            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();

            edk::shape::Mesh2D* mesh;edkEnd();
            mesh = this->meshes.getMesh(meshPosition);edkEnd();
            if(mesh){
                ret = mesh->getWorldPolygon(dest,polygonPosition,&this->matrixTransform);edkEnd();
            }
        }
    }
    return ret;
}

//LIGHT
//EDK_LIGHT_LIMIT
bool edk::Object2D::setLight(edk::uint32 position,edk::light::Light light){
    if(position<EDK_LIGHT_LIMIT){
        this->lights[position] = light;edkEnd();
        return true;
    }
    return false;
}
bool edk::Object2D::cleanLight(edk::uint32 position){
    if(position<EDK_LIGHT_LIMIT){
        //
        this->lights[position].clean();edkEnd();
        return true;
    }
    return false;
}
bool edk::Object2D::lightOn(edk::uint32 position){
    if(position<EDK_LIGHT_LIMIT){
        //add the light on the tree
        this->lights[position].on=true;edkEnd();
        return true;
    }
    return false;
}
bool edk::Object2D::lightOff(edk::uint32 position){
    if(position<EDK_LIGHT_LIMIT){
        //remove the position from the tree
        this->lights[position].on=false;edkEnd();
        return true;
    }
    return false;
}

//play all mesh animations
void edk::Object2D::playMeshAnimations(){
    edk::uint32 size = this->meshes.size();edkEnd();
    edk::shape::Mesh2D* mesh;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        mesh = this->meshes.getMesh(i);edkEnd();
        if(mesh){
            edk::uint32 polySize = mesh->getPolygonSize();edkEnd();
            for(edk::uint32 j=0u;j<polySize;j++){
                mesh->selectAnimationFramesFromPolygon(j);edkEnd();
                mesh->selectedAnimationPlayForward();edkEnd();
            }
        }
    }
}
bool edk::Object2D::playMeshAnimations(edk::uchar32 position){
    edk::shape::Mesh2D* mesh = this->meshes.getMesh(position);edkEnd();
    if(mesh){
        edk::uint32 polySize = mesh->getPolygonSize();edkEnd();
        for(edk::uint32 j=0u;j<polySize;j++){
            mesh->selectAnimationFramesFromPolygon(j);edkEnd();
            mesh->selectedAnimationPlayForward();edkEnd();
        }
        return true;
    }
    return false;
}
//pause polygons animations
void edk::Object2D::pauseMeshAnimations(){
    edk::uint32 size = this->meshes.size();edkEnd();
    edk::shape::Mesh2D* mesh;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        mesh = this->meshes.getMesh(i);edkEnd();
        if(mesh){
            edk::uint32 polySize = mesh->getPolygonSize();edkEnd();
            for(edk::uint32 j=0u;j<polySize;j++){
                mesh->selectAnimationFramesFromPolygon(j);edkEnd();
                mesh->selectedAnimationPause();edkEnd();
            }
        }
    }
}
bool edk::Object2D::pauseMeshAnimations(edk::uchar32 position){
    edk::shape::Mesh2D* mesh = this->meshes.getMesh(position);edkEnd();
    if(mesh){
        edk::uint32 polySize = mesh->getPolygonSize();edkEnd();
        for(edk::uint32 j=0u;j<polySize;j++){
            mesh->selectAnimationFramesFromPolygon(j);edkEnd();
            mesh->selectedAnimationPause();edkEnd();
        }
        return true;
    }
    return false;
}
//update mesh animations
void edk::Object2D::updateMeshAnimations(){
    //update mesh animations
    edk::uint32 size = this->meshes.size();edkEnd();
    edk::shape::Mesh2D *mesh;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        mesh = this->meshes.getMesh(i);edkEnd();
        if(mesh){
            mesh->updateFramesAnimations();edkEnd();
        }
    }
}
void edk::Object2D::updateMeshAnimations(edk::float32 seconds){
    //update mesh animations
    edk::uint32 size = this->meshes.size();edkEnd();
    edk::shape::Mesh2D *mesh;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.haveCreateMesh(i)){
            mesh = this->meshes.getMesh(i);edkEnd();
            if(mesh){
                mesh->updateFramesAnimations(seconds);edkEnd();
            }
        }
    }
}
bool edk::Object2D::updateMeshAnimationsFromPosition(edk::uchar32 position){
    edk::shape::Mesh2D* mesh = this->meshes.getMesh(position);edkEnd();
    if(mesh){
        edk::uint32 polySize = mesh->getPolygonSize();edkEnd();
        for(edk::uint32 j=0u;j<polySize;j++){
            mesh->selectAnimationFramesFromPolygon(j);edkEnd();
            mesh->updateFramesAnimations();edkEnd();
        }
        return true;
    }
    return false;
}
bool edk::Object2D::updateMeshAnimationsFromPosition(edk::uchar32 position,edk::float32 seconds){
    edk::shape::Mesh2D* mesh = this->meshes.getMesh(position);edkEnd();
    if(mesh){
        edk::uint32 polySize = mesh->getPolygonSize();edkEnd();
        for(edk::uint32 j=0u;j<polySize;j++){
            mesh->selectAnimationFramesFromPolygon(j);edkEnd();
            mesh->updateFramesAnimations(seconds);edkEnd();
        }
        return true;
    }
    return false;
}

//update all animations
bool edk::Object2D::updateAnimations(){
    bool ret=edk::Object2DValues::updateAnimations();edkEnd();
    this->updateMeshAnimations();edkEnd();
    this->updateChildremsAnimations();
    return ret;
}
bool edk::Object2D::updateAnimations(edk::float32 seconds){
    bool ret=edk::Object2DValues::updateAnimations(seconds);edkEnd();
    this->updateMeshAnimations(seconds);edkEnd();
    this->updateChildremsAnimations(seconds);
    return ret;
}

//ACTIONS
//play actions
void edk::Object2D::playForwardActions(){
    /*
    this->actions.playForward();edkEnd();
    */
}
void edk::Object2D::playForwardInActions(edk::float32 /*second*/){
    /*
    this->actions.playForwardIn(second);edkEnd();
    */
}
void edk::Object2D::pauseActions(){
    /*
    this->actions.pause();edkEnd();
    */
}
void edk::Object2D::stopActions(){
    /*
    this->actions.stop();edkEnd();
    */
}
//set loop
void edk::Object2D::setLoopActions(bool /*loop*/){
    /*
    this->actions.setLoop(loop);edkEnd();
    */
}
void edk::Object2D::loopOnActions(){
    /*
    this->actions.loopOn();edkEnd();
    */
}
void edk::Object2D::loopOffActions(){
    /*
    this->actions.loopOff();edkEnd();
    */
}

//return if are playing
bool edk::Object2D::isPlayingActions(){
    /*
    return this->actions.isPlaying();edkEnd();
    */
    return false;
}
bool edk::Object2D::isPausedActions(){
    /*
    return this->actions.isPaused();edkEnd();
    */
    return false;
}
//update actions
void edk::Object2D::updateActions(){
    /*
    this->actions.update();edkEnd();
    */
}
//remove actions
void edk::Object2D::removeAllActions(){
    /*
    this->actions.clean();edkEnd();
    */
}
void edk::Object2D::cleanAllActions(){
    /*
    this->actions.clean();edkEnd();
    */
}
bool edk::Object2D::removeActionSecond(edk::float32 /*second*/){
    /*
    return this->actions.removeSecond(second);edkEnd();
    */
    return false;
}
//Add zero action
bool edk::Object2D::actionZero(edk::float32 /*second*/){
    /*
    return this->actions.addAction(second,new edk::ActionZero);edkEnd();
    */
    return false;
}
//add move action
bool edk::Object2D::actionSetPosition(edk::float32 /*second*/,edk::vec2f32 /*position*/){
    /*
    return this->actions.addAction(second,new edk::Object2D::ActionPosition(this,position));edkEnd();
    */
    return false;
}
bool edk::Object2D::actionSetPosition(edk::float32 /*second*/,edk::float32 /*x*/,edk::float32 /*y*/){
    /*
    return this->actionSetPosition(second,edk::vec2f32(x,y));edkEnd();
    */
    return false;
}
//add move action
bool edk::Object2D::actionMove(edk::float32 /*second*/,edk::float32 /*duration*/, edk::vec2f32 /*position*/){
    /*
    //create the action
    if(this->actions.addAction(second,new edk::Object2D::ActionMove(this,duration,position))){
        this->actions.addZeroAction(second+duration);edkEnd();
        return true;
    }
    */
    return false;
}
bool edk::Object2D::actionMove(edk::float32 /*second*/,edk::float32 /*duration*/, edk::float32 /*x*/,edk::float32 /*y*/){
    /*
    return this->actionMove(second,duration, edk::vec2f32(x,y));edkEnd();
    */
    return false;
}
bool edk::Object2D::actionMoveTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::vec2f32 /*position*/){
    /*
    return this->actionMove(start,end-start, position);edkEnd();
    */
    return false;
}
bool edk::Object2D::actionMoveTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::float32 /*x*/,edk::float32 /*y*/){
    /*
    return this->actionMove(start,end-start,x,y);edkEnd();
    */
    return false;
}
//add scale action
bool edk::Object2D::actionSetSize(edk::float32 /*second*/,edk::size2f32 /*size*/){
    /*
    //create the action
    return this->actions.addAction(second,new edk::Object2D::ActionSetSize(this,size));edkEnd();
    */
    return false;
}
bool edk::Object2D::actionSetSize(edk::float32 /*second*/,edk::float32 /*width*/,edk::float32 /*height*/){
    /*
    return this->actionSetSize(second,edk::size2f32(width,height));edkEnd();
    */
    return false;
}
bool edk::Object2D::actionSetSize(edk::float32 /*second*/,edk::float32 /*size*/){
    /*
    return this->actionSetSize(second,size,size);edkEnd();
    */
    return false;
}
//add scale action
bool edk::Object2D::actionScale(edk::float32 /*second*/,edk::float32 /*duration*/, edk::size2f32 /*size*/){
    /*
    //create the action
    if(this->actions.addAction(second,new edk::Object2D::ActionSize(this,duration,size))){
        this->actions.addZeroAction(second+duration);edkEnd();
        return true;
    }
    */
    return false;
}
bool edk::Object2D::actionScale(edk::float32 /*second*/,edk::float32 /*duration*/, edk::float32 /*width*/,edk::float32 /*height*/){
    /*
    return this->actionScale(second,duration, edk::size2f32( width,height));edkEnd();
    */
    return false;
}
bool edk::Object2D::actionScale(edk::float32 /*second*/,edk::float32 /*duration*/, edk::float32 /*size*/){
    /*
    return this->actionScale(second,duration, size,size);edkEnd();
    */
    return false;
}
bool edk::Object2D::actionScaleTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::size2f32 /*size*/){
    /*
    return this->actionScale(start,end-start, size);edkEnd();
    */
    return false;
}
bool edk::Object2D::actionScaleTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::float32 /*width*/,edk::float32 /*height*/){
    /*
    return this->actionScale(start,end-start, width,height);edkEnd();
    */
    return false;
}
bool edk::Object2D::actionScaleTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::float32 /*size*/){
    /*
    return this->actionScale(start,end-start, size);edkEnd();
    */
    return false;
}
//add angle action
bool edk::Object2D::actionSetAngle(edk::float32 /*second*/,edk::float32 /*angle*/){
    /*
    return this->actions.addAction(second,new edk::Object2D::ActionSetAngle(this,angle));edkEnd();
    */
    return false;
}
//add angle action
bool edk::Object2D::actionRotateFor(edk::float32 /*second*/,edk::float32 /*duration*/, edk::float32 /*angle*/){
    /*
    if(this->actions.addAction(second,new edk::Object2D::ActionAngle(this,duration,angle))){
        this->actions.addZeroAction(second);edkEnd();
        return true;
    }
    */
    return false;
}
bool edk::Object2D::actionRotateTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::float32 /*angle*/){
    /*
    return this->actionRotateFor(start,end-start, angle);edkEnd();
    */
    return false;
}
//MESH SPRITE SHEET
bool edk::Object2D::actionPlayName(edk::float32 /*second*/,edk::uint32 /*id*/,edk::char8* /*name*/,bool /*loop*/){
    //
    /*
    return this->actions.addAction(second,new edk::Object2D::ActionMeshName(this,id,name,loop));edkEnd();
    */
    return false;
}
bool edk::Object2D::actionPlayName(edk::float32 /*second*/,edk::uint32 /*id*/,const edk::char8* /*name*/,bool /*loop*/){
    //
    /*
    return actionPlayName(second,id,(edk::char8*)name,loop);edkEnd();
    */
    return false;
}
bool edk::Object2D::actionPlayNameFor(edk::float32 /*second*/,edk::float32 /*duration*/,edk::uint32 /*id*/,edk::char8* /*name*/){
    /*
    if(this->actions.addAction(second,new edk::Object2D::ActionMeshName(this,id,name,true))){
        //add the stop action
        this->actions.addAction(second+duration,new edk::Object2D::ActionMeshStop(this,id));edkEnd();
        return true;
    }
    */
    return false;
}
bool edk::Object2D::actionPlayNameFor(edk::float32 /*second*/,edk::float32 /*duration*/,edk::uint32 /*id*/,const edk::char8* /*name*/){
    /*
    return this->actionPlayNameFor(second,duration,id,(edk::char8*)name);edkEnd();
    */
    return false;
}

//DRAW
//print the mesh
void edk::Object2D::print(){
    edk::uint32 size = this->meshes.size();edkEnd();
    edk::shape::Mesh2D* mesh;edkEnd();
    //print all polygonList
    for(edk::uint32 i=0u;i<size;i++){
        //
        mesh = this->meshes.getMesh(i);edkEnd();
        if(mesh){
            //
            printf("\nMESH %u"
                   ,i
                   );fflush(stdout);edkEnd();
            mesh->print();edkEnd();
        }
    }
}
//draw the mesh
void edk::Object2D::drawBoundingBox(){
    //test if have a father
    //if(this->father){
    this->updateChangedValues();
    //    //put the transformation on a stack
    //    edk::GU::guPushMatrix();edkEnd();
    //
    //    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);edkEnd();
    //
    //    edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    //    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );edkEnd();
    //    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);edkEnd();
    //    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.size.height);edkEnd();
    //    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.origin.y   );edkEnd();
    //    edk::GU::guEnd();edkEnd();
    //
    //    edk::GU::guPopMatrix();edkEnd();
    //}
    //else{
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);edkEnd();

    this->drawChildremsBackBoundingBox();

    edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );edkEnd();
    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);edkEnd();
    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.size.height);edkEnd();
    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.origin.y   );edkEnd();
    edk::GU::guEnd();edkEnd();

    this->drawChildremsFrontBoundingBox();
    edk::GU::guPopMatrix();edkEnd();
    //}
}
void edk::Object2D::draw(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    bool haveLight=false;edkEnd();
    edk::GU::guEnable(GU_LIGHTING);edkEnd();
    //glEnable(GL_RESCALE_NORMAL);edkEnd();
    {
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);edkEnd();
                this->lights[i].draw(i);edkEnd();
                haveLight=true;edkEnd();

            }
            else{
                edk::GU::guDisable(GU_LIGHT0+i);edkEnd();
            }
        }
    }
    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBack(haveLight);

    edk::shape::Mesh2D* mesh;edkEnd();
    if(haveLight){
        edk::uint32 size = this->meshes.size();edkEnd();
        for(edk::uint32 i=size;i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    mesh->drawOneTexture();edkEnd();
                }
                else{
                    mesh->drawMultiTexture();edkEnd();
                }
            }
        }
    }
    else{
        edk::uint32 size = this->meshes.size();edkEnd();
        for(edk::uint32 i=size;i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    mesh->drawOneTexture();edkEnd();
                }
                else{
                    mesh->drawMultiTexture();edkEnd();
                }
            }
        }
    }
    this->drawChildremsFront(haveLight);
    //glEnable(GL_RESCALE_NORMAL);edkEnd();
    edk::GU::guDisable(GU_LIGHTING);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawOneTexture(){
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

    this->drawChildremsBackOneTexture();

    edk::shape::Mesh2D* mesh;edkEnd();
    //print all polygonList
    for(edk::uint32 i=this->meshes.size();i>0u;i--){
        //
        mesh = this->meshes.getMesh(i-1u);edkEnd();
        if(mesh){
            mesh->drawOneTexture();edkEnd();
        }
    }
    this->drawChildremsFrontOneTexture();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawOneTextureWithLight(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guEnable(GU_LIGHTING);edkEnd();

    bool haveLight=false;edkEnd();

    {
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);edkEnd();
                this->lights[i].draw(i);edkEnd();
                haveLight=true;edkEnd();

            }
            else{
                edk::GU::guDisable(GU_LIGHT0+i);edkEnd();
            }
        }
    }
    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackOneTextureWithLight(haveLight);

    edk::shape::Mesh2D* mesh;edkEnd();
    if(haveLight){
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                mesh->drawOneTexture();edkEnd();
            }
        }
    }
    else{
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                mesh->drawOneTexture();edkEnd();
            }
        }
    }
    this->drawChildremsFrontOneTextureWithLight(haveLight);
    edk::GU::guDisable(GU_LIGHTING);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawWithoutMaterial(){
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

    this->drawChildremsBackWithoutMaterial();

    edk::shape::Mesh2D* mesh;edkEnd();
    //print all polygonList
    for(edk::uint32 i=this->meshes.size();i>0u;i--){
        //
        mesh = this->meshes.getMesh(i-1u);edkEnd();
        if(mesh){
            mesh->drawWithoutMaterial();edkEnd();
        }
    }
    this->drawChildremsFrontWithoutMaterial();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawWithoutMaterialWithLight(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guEnable(GU_LIGHTING);edkEnd();

    bool haveLight=false;edkEnd();

    {
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);edkEnd();
                this->lights[i].draw(i);edkEnd();
                haveLight=true;edkEnd();

            }
            else{
                edk::GU::guDisable(GU_LIGHT0+i);edkEnd();
            }
        }
    }
    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWithoutMaterialWithLight(haveLight);

    edk::shape::Mesh2D* mesh;edkEnd();
    if(haveLight){
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                mesh->drawWithoutMaterial();edkEnd();
            }
        }
    }
    else{
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                mesh->drawWithoutMaterial();edkEnd();
            }
        }
    }
    this->drawChildremsFrontWithoutMaterialWithLight(haveLight);
    edk::GU::guDisable(GU_LIGHTING);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawWire(){
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

    this->drawChildremsBackWire();

    edk::shape::Mesh2D* mesh;edkEnd();
    //print all polygonList
    for(edk::uint32 i=this->meshes.size();i>0u;i--){
        //
        mesh = this->meshes.getMesh(i-1u);edkEnd();
        if(mesh){
            mesh->drawWirePolygons();edkEnd();
        }
    }
    this->drawChildremsFrontWire();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawWirePolygon(edk::uint32 meshPosition,edk::uint32 polygon){

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

    edk::shape::Mesh2D* mesh = this->meshes.getMesh(meshPosition);edkEnd();
    if(mesh){
        mesh->drawWirePolygon(polygon);edkEnd();
    }
    edk::GU::guPopMatrix();edkEnd();
}
bool edk::Object2D::drawMesh(edk::uint32 meshPosition){
    bool ret=false;edkEnd();
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();


    edk::GU::guEnable(GU_LIGHTING);edkEnd();
    //glEnable(GL_RESCALE_NORMAL);edkEnd();

    bool haveLight=false;edkEnd();

    {
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);edkEnd();
                this->lights[i].draw(i);edkEnd();
                haveLight=true;edkEnd();

            }
            else{
                edk::GU::guDisable(GU_LIGHT0+i);edkEnd();
            }
        }
    }

    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    edk::shape::Mesh2D* mesh;edkEnd();
    if(haveLight){
        if(meshPosition < this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);edkEnd();
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    mesh->drawOneTexture();edkEnd();
                }
                else{
                    mesh->drawMultiTexture();edkEnd();
                }
                ret=true;edkEnd();
            }
        }
    }
    else{
        if(meshPosition < this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);edkEnd();
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    mesh->drawOneTexture();edkEnd();
                }
                else{
                    mesh->drawMultiTexture();edkEnd();
                }
                ret=true;edkEnd();
            }
        }
    }
    //glEnable(GL_RESCALE_NORMAL);edkEnd();
    edk::GU::guDisable(GU_LIGHTING);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object2D::drawPolygon(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;edkEnd();
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();


    edk::GU::guEnable(GU_LIGHTING);edkEnd();
    //glEnable(GL_RESCALE_NORMAL);edkEnd();

    bool haveLight=false;edkEnd();

    {
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);edkEnd();
                this->lights[i].draw(i);edkEnd();
                haveLight=true;edkEnd();

            }
            else{
                edk::GU::guDisable(GU_LIGHT0+i);edkEnd();
            }
        }
    }

    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    edk::shape::Mesh2D* mesh;edkEnd();
    if(haveLight){
        if(meshPosition < this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);edkEnd();
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    ret = mesh->drawPolygonOneTexture(polygon);edkEnd();
                }
                else{
                    ret = mesh->drawPolygonMultiTexture(polygon);edkEnd();
                }
            }
        }
    }
    else{
        if(meshPosition < this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);edkEnd();
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    ret = mesh->drawPolygonOneTexture(polygon);edkEnd();
                }
                else{
                    ret = mesh->drawPolygonMultiTexture(polygon);edkEnd();
                }
            }
        }
    }
    //glEnable(GL_RESCALE_NORMAL);edkEnd();
    edk::GU::guDisable(GU_LIGHTING);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object2D::drawMeshOneTexture(edk::uint32 meshPosition){
    bool ret = false;edkEnd();
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

    edk::shape::Mesh2D* mesh;edkEnd();
    //
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);edkEnd();
        if(mesh){
            mesh->drawOneTexture();edkEnd();
            ret = true;edkEnd();
        }
    }
    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object2D::drawPolygonOneTexture(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret = false;edkEnd();
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

    edk::shape::Mesh2D* mesh;edkEnd();
    //
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);edkEnd();
        if(mesh){
            ret = mesh->drawPolygonOneTexture(polygon);edkEnd();
        }
    }
    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object2D::drawMeshOneTextureWithLight(edk::uint32 meshPosition){
    bool ret = false;edkEnd();
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guEnable(GU_LIGHTING);edkEnd();

    bool haveLight=false;edkEnd();

    {
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);edkEnd();
                this->lights[i].draw(i);edkEnd();
                haveLight=true;edkEnd();

            }
            else{
                edk::GU::guDisable(GU_LIGHT0+i);edkEnd();
            }
        }
    }
    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    edk::shape::Mesh2D* mesh;edkEnd();
    if(haveLight){
        if(meshPosition < this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);edkEnd();
            if(mesh){
                mesh->drawOneTexture();edkEnd();
                ret = true;edkEnd();
            }
        }
    }
    else{
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                mesh->drawOneTexture();edkEnd();
                ret = true;edkEnd();
            }
        }
    }
    edk::GU::guDisable(GU_LIGHTING);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object2D::drawPolygonOneTextureWithLight(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret = false;edkEnd();
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guEnable(GU_LIGHTING);edkEnd();

    bool haveLight=false;edkEnd();

    {
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);edkEnd();
                this->lights[i].draw(i);edkEnd();
                haveLight=true;edkEnd();

            }
            else{
                edk::GU::guDisable(GU_LIGHT0+i);edkEnd();
            }
        }
    }
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    edk::shape::Mesh2D* mesh;edkEnd();
    if(haveLight){
        if(meshPosition < this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);edkEnd();
            if(mesh){
                ret = mesh->drawPolygonOneTexture(polygon);edkEnd();
            }
        }
    }
    else{
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);edkEnd();
            if(mesh){
                ret = mesh->drawPolygonOneTexture(polygon);edkEnd();
            }
        }
    }
    edk::GU::guDisable(GU_LIGHTING);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object2D::drawMeshWithoutMaterial(edk::uint32 meshPosition){
    bool ret = false;edkEnd();
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

    edk::shape::Mesh2D* mesh;edkEnd();
    //print all polygonList
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);edkEnd();
        if(mesh){
            mesh->drawWithoutMaterial();edkEnd();
            ret = true;edkEnd();
        }
    }
    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object2D::drawPolygonWithoutMaterial(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret = false;edkEnd();
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

    edk::shape::Mesh2D* mesh;edkEnd();
    //print all polygonList
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);edkEnd();
        if(mesh){
            ret = mesh->drawPolygonWithoutMaterial(polygon);edkEnd();
        }
    }
    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object2D::drawMeshWithoutMaterialWithLight(edk::uint32 meshPosition){
    bool ret = false;edkEnd();
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guEnable(GU_LIGHTING);edkEnd();

    bool haveLight=false;edkEnd();

    {
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);edkEnd();
                this->lights[i].draw(i);edkEnd();
                haveLight=true;edkEnd();

            }
            else{
                edk::GU::guDisable(GU_LIGHT0+i);edkEnd();
            }
        }
    }
    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    edk::shape::Mesh2D* mesh;edkEnd();
    if(haveLight){
        if(meshPosition<this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);edkEnd();
            if(mesh){
                mesh->drawWithoutMaterial();edkEnd();
                ret=true;edkEnd();
            }
        }
    }
    else{
        if(meshPosition<this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);edkEnd();
            if(mesh){
                mesh->drawWithoutMaterial();edkEnd();
                ret=true;edkEnd();
            }
        }
    }
    edk::GU::guDisable(GU_LIGHTING);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object2D::drawPolygonWithoutMaterialWithLight(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret = false;edkEnd();
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guEnable(GU_LIGHTING);edkEnd();

    bool haveLight=false;edkEnd();

    {
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);edkEnd();
                this->lights[i].draw(i);edkEnd();
                haveLight=true;edkEnd();

            }
            else{
                edk::GU::guDisable(GU_LIGHT0+i);edkEnd();
            }
        }
    }
    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();

    edk::shape::Mesh2D* mesh;edkEnd();
    if(haveLight){
        if(meshPosition<this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);edkEnd();
            if(mesh){
                ret = mesh->drawPolygonWithoutMaterial(polygon);edkEnd();
            }
        }
    }
    else{
        if(meshPosition<this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);edkEnd();
            if(mesh){
                ret = mesh->drawPolygonWithoutMaterial(polygon);edkEnd();
            }
        }
    }
    edk::GU::guDisable(GU_LIGHTING);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object2D::drawMeshWire(edk::uint32 meshPosition){
    bool ret=false;edkEnd();
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

    edk::shape::Mesh2D* mesh;edkEnd();
    //print all polygonList
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);edkEnd();
        if(mesh){
            mesh->drawWirePolygons();edkEnd();
            ret = true;edkEnd();
        }
    }
    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object2D::drawPolygonWire(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;edkEnd();
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

    edk::shape::Mesh2D* mesh;edkEnd();
    //print all polygonList
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);edkEnd();
        if(mesh){
            ret = mesh->drawWirePolygon(polygon);edkEnd();
        }
    }
    edk::GU::guPopMatrix();edkEnd();
    return ret;
}

//draw the pivo
void edk::Object2D::drawPivo(edk::float32 size,edk::color3f32 color){
    if(this->childremsBack.size()){
        edk::GU::guPushMatrix();edkEnd();
        //add translate
        edk::GU::guTranslate2f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateZf32(this->angle);edkEnd();
        //add scale
        edk::GU::guScale2f32(this->size);edkEnd();
        //set the pivo
        edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();
        this->drawChildremsBackPivo(size,color);
        edk::GU::guPopMatrix();edkEnd();
    }
    edk::Object2D::drawPivoInPosition(this->position,size,color);
    if(this->childremsFront.size()){
        edk::GU::guPushMatrix();edkEnd();
        //add translate
        edk::GU::guTranslate2f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateZf32(this->angle);edkEnd();
        //add scale
        edk::GU::guScale2f32(this->size);edkEnd();
        //set the pivo
        edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();
        this->drawChildremsFrontPivo(size,color);
        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::Object2D::drawPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();
    if(this->childremsBack.size()){
        this->drawChildremsBackPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();edkEnd();


    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();

    edk::Object2D::drawPivoInPosition(this->position,size,edk::color3f32(r,g,b));

    edk::GU::guPopMatrix();edkEnd();

    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    edk::GU::guScale2f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);edkEnd();
    if(this->childremsFront.size()){
        this->drawChildremsFrontPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawPivoInPosition(edk::vec2f32 position,edk::float32 size,edk::color3f32 color){
    //
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate2f32(position);edkEnd();
    //add scale
    edk::GU::guScale2f32(edk::size2f32(size,size));edkEnd();

    //lineSize
    edk::GU::guLineWidth(3);edkEnd();

    //set the colors
    edk::GU::guColor3f32(color);edkEnd();
    //draw the lines
    edk::GU::guBegin(GU_LINES);edkEnd();
    //LINE 1
    edk::GU::guVertex2f32(-0.5f,-0.5f);edkEnd();
    edk::GU::guVertex2f32( 0.5f, 0.5f);edkEnd();
    //LINE 2
    edk::GU::guVertex2f32(-0.5f, 0.5f);edkEnd();
    edk::GU::guVertex2f32( 0.5f,-0.5f);edkEnd();
    edk::GU::guEnd();edkEnd();

    //lineSize
    edk::GU::guLineWidth(1);edkEnd();

    //
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object2D::drawPivoInPosition(edk::float32 x,edk::float32 y,edk::float32 size,edk::color3f32 color){
    edk::Object2D::drawPivoInPosition(edk::vec2f32(x,y),size,color);
}
void edk::Object2D::drawPivoInPosition(edk::float32 x,edk::float32 y,edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::Object2D::drawPivoInPosition(edk::vec2f32(x,y),size,edk::color3f32(r,g,b));
}

//XML
bool edk::Object2D::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"object_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //WRITE
                        //write the mesh
                        edk::uint32 size = this->meshes.size();edkEnd();
                        edk::shape::Mesh2D* mesh;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            mesh = this->meshes.getMesh(i);edkEnd();
                            if(mesh){
                                mesh->writeToXML(xml,i);edkEnd();
                            }
                        }

                        //write pivo
                        edk::char8* temp=NULL;edkEnd();
                        temp = edk::String::float32ToStr(this->pivo.x);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"pivoX",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->pivo.y);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"pivoY",temp);edkEnd();
                            free(temp);edkEnd();
                        }

                        //write objectValues
                        //position
                        temp = edk::String::float32ToStr(this->position.x);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"positionX",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->position.y);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"positionY",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        //size
                        temp = edk::String::float32ToStr(this->size.width);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"sizeW",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->size.height);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"sizeH",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        //angle
                        temp = edk::String::float32ToStr(this->angle);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"angle",temp);edkEnd();
                            free(temp);edkEnd();
                        }

                        //write animations
                        this->animationPosition.writeToXML(xml,0u);edkEnd();
                        this->animationRotation.writeToXML(xml,1u);edkEnd();
                        this->animationSize.writeToXML(xml,2u);edkEnd();

                        /*
                        //write the actins
                        this->actions.writeToXML(xml,0u);edkEnd();
                        */

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
bool edk::Object2D::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"object_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    this->cleanMeshes();edkEnd();
                    //read mesh
                    edk::shape::Mesh2D* mesh;edkEnd();
                    edk::uint32 count=0u;
                    edk::uint32 position=0u;
                    do{
                        mesh = this->newMesh(&position);edkEnd();
                        if(mesh){
                            if(!mesh->readFromXML(xml,count)){
                                this->removeMesh(position);edkEnd();
                                mesh=NULL;edkEnd();
                            }
                        }
                        count++;edkEnd();
                    }while(mesh);edkEnd();
                    //read pivo
                    this->pivo = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoX")),
                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoY"))
                                              );edkEnd();
                    //read the object values
                    //position
                    this->position = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionX")),
                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionY"))
                                                  );edkEnd();
                    //size
                    this->size = edk::size2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeW")),
                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeH"))
                                               );edkEnd();
                    //angle
                    this->angle = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("angle"));edkEnd();

                    //write animations
                    this->animationPosition.readFromXML(xml,0u);edkEnd();
                    this->animationRotation.readFromXML(xml,1u);edkEnd();
                    this->animationSize.readFromXML(xml,2u);edkEnd();

                    /*
                    //ACTIONS
                    this->actions.readFromXML(xml,0u,this);edkEnd();
                    */

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
bool edk::Object2D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    if(xml && pack){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"object_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    this->cleanMeshes();edkEnd();
                    //read mesh
                    edk::shape::Mesh2D* mesh;edkEnd();
                    edk::uint32 count=0u;
                    edk::uint32 position=0u;
                    do{
                        mesh = this->newMesh(&position);edkEnd();
                        if(mesh){
                            if(!mesh->readFromXMLFromPack(pack,xml,count)){
                                this->removeMesh(position);edkEnd();
                                mesh=NULL;edkEnd();
                            }
                        }
                        count++;edkEnd();
                    }while(mesh);edkEnd();
                    //read pivo
                    this->pivo = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoX")),
                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoY"))
                                              );edkEnd();
                    //read the object values
                    //position
                    this->position = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionX")),
                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionY"))
                                                  );edkEnd();
                    //size
                    this->size = edk::size2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeW")),
                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeH"))
                                               );edkEnd();
                    //angle
                    this->angle = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("angle"));edkEnd();

                    //write animations
                    this->animationPosition.readFromXML(xml,0u);edkEnd();
                    this->animationRotation.readFromXML(xml,1u);edkEnd();
                    this->animationSize.readFromXML(xml,2u);edkEnd();

                    /*
                    //ACTIONS
                    this->actions.readFromXML(xml,0u,this);edkEnd();
                    */

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

//cant delete
void edk::Object2D::cantDeleteObject2D(){
    this->canDeleteObject=false;edkEnd();
    //transform matrices
    this->matrixPosition.cantDeleteMatrix();edkEnd();
    this->matrixPivo.cantDeleteMatrix();edkEnd();
    this->matrixAngle.cantDeleteMatrix();edkEnd();
    this->matrixSize.cantDeleteMatrix();edkEnd();
    this->matrixTransform.cantDeleteMatrix();edkEnd();
}

//connect another object into this
bool edk::Object2D::connectObjectBack(edk::Object2D* obj){
    if(obj){
        if(!obj->father){
            if(this->childremsBack.add(obj)){
                obj->father=this;

                obj->newSize = edk::size2f32(1.f / this->size.width,1.f / this->size.height);


                //translate the object to be connected with the another
                obj->connectedPosition=obj->position - this->position;
                obj->connectedPosition.x*=obj->newSize.width;
                obj->connectedPosition.y*=obj->newSize.height;
                obj->connectedSize=obj->size*obj->newSize;
                obj->connectedAngle=obj->angle-this->angle;

                //save the position
                obj->saveTransformation();

                return true;
            }
        }
    }
    return false;
}
bool edk::Object2D::updateConnectedObjectBackValues(edk::Object2D* obj){
    if(obj){
        if(obj->father == this){
            if(this->childremsBack.haveElement(obj)){
                //update the values
                obj->matrixTransform.setIdentity();
                obj->updateValuesFromFather(&obj->matrixTransform);
                //
                edk::Math::generateTranslateMatrix(edk::vec2f32(0.f,0.f),&obj->matrixPosition);edkEnd();
                /*
                this->matrixPosition.setIdentity();
                this->matrixPosition.set(0u,0u,this->position.x);edkEnd();
                this->matrixPosition.set(0u,1u,this->position.y);edkEnd();
                this->matrixPosition.set(0u,2u,1.f);edkEnd();
                */

                //multiply the matrix
                obj->matrixPosition.multiplyMatrixWithThis(&obj->matrixTransform);edkEnd();

                obj->position.x = obj->matrixPosition.getNoIF(0u,0u);edkEnd();
                obj->position.y = obj->matrixPosition.getNoIF(0u,1u);edkEnd();

                return true;
            }
        }
    }
    return false;
}
bool edk::Object2D::haveConnectedObjectBack(edk::Object2D* obj){
    if(obj){
        if(obj->father == this){
            if(this->childremsBack.haveElement(obj)){
                return true;
            }
        }
    }
    return false;
}
bool edk::Object2D::disconnectObjectBack(edk::Object2D* obj){
    if(obj){
        if(obj->father == this){
            if(this->childremsBack.remove(obj)){
                this->father=NULL;
                obj->connectedLoadIdentityValues();
                obj->newSize=1.f;
                return true;
            }
        }
    }
    return false;
}
void edk::Object2D::cleanConnectedObjectsBack(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        if(obj){
            if(obj->father == this){
                obj->father=NULL;
                obj->connectedLoadIdentityValues();
                obj->newSize=1.f;
            }
        }
    }
    this->childremsBack.clean();
}
bool edk::Object2D::connectObjectFront(edk::Object2D* obj){
    if(obj){
        if(!obj->father){
            if(this->childremsFront.add(obj)){
                obj->father=this;

                obj->newSize = edk::size2f32(1.f / this->size.width,1.f / this->size.height);


                //translate the object to be connected with the another
                obj->connectedPosition=obj->position - this->position;
                obj->connectedPosition.x*=obj->newSize.width;
                obj->connectedPosition.y*=obj->newSize.height;
                obj->connectedSize=obj->size*obj->newSize;
                obj->connectedAngle=obj->angle-this->angle;

                //save the position
                obj->saveTransformation();

                return true;
            }
        }
    }
    return false;
}
bool edk::Object2D::updateConnectedObjectFrontValues(edk::Object2D* obj){
    if(obj){
        if(obj->father == this){
            if(this->childremsFront.haveElement(obj)){
                obj->updateValuesFromConnected();
                return true;
            }
        }
    }
    return false;
}
bool edk::Object2D::haveConnectedObjectFront(edk::Object2D* obj){
    if(obj){
        if(obj->father == this){
            if(this->childremsFront.haveElement(obj)){
                return true;
            }
        }
    }
    return false;
}
bool edk::Object2D::disconnectObjectFront(edk::Object2D* obj){
    if(obj){
        if(obj->father == this){
            if(this->childremsFront.remove(obj)){
                this->father=NULL;
                obj->connectedLoadIdentityValues();
                obj->newSize=1.f;
                return true;
            }
        }
    }
    return false;
}
void edk::Object2D::cleanConnectedObjectsFront(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        if(obj){
            if(obj->father == this){
                obj->father=NULL;
                obj->connectedLoadIdentityValues();
                obj->newSize=1.f;
            }
        }
    }
    this->childremsFront.clean();
}

bool edk::Object2D::cloneFrom(edk::Object2D* obj){
    if(obj){
        this->cleanSelected();edkEnd();
        this->cleanMeshes();edkEnd();

        //copy the meshs
        edk::uint32 size = obj->meshes.size();edkEnd();
        edk::shape::Mesh2D* temp = NULL;edkEnd();
        edk::shape::Mesh2D* mesh = NULL;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = obj->meshes.getMesh(i);edkEnd();
            if(temp){
                mesh = this->newMesh();edkEnd();
                if(mesh){
                    //*mesh = *temp;edkEnd();
                    mesh->cloneFrom(temp);edkEnd();
                }
            }
        }
        //copy pivo
        this->pivo = obj->pivo;edkEnd();
        //copy the animations
        //this->animationPosition = obj->animationPosition;edkEnd();
        this->animationPosition.cloneFrom(&obj->animationPosition);edkEnd();
        //this->animationRotation = obj->animationRotation;edkEnd();
        this->animationRotation.cloneFrom(&obj->animationRotation);edkEnd();
        //this->animationSize = obj->animationSize;edkEnd();
        this->animationSize.cloneFrom(&obj->animationSize);edkEnd();

        this->position = obj->position;edkEnd();
        this->angle = obj->angle;edkEnd();
        this->size = obj->size;edkEnd();


        //class ActionPosition 1
        //class ActionMove     2
        //class ActionSetSize  3
        //class ActionSize     4
        //class ActionSetAngle 5
        //class ActionAngle    6
        //class ActionMeshName 7
        //class ActionMeshStop 8



        /*
        //copy the actions
        this->actions.clean();edkEnd();
        size = obj->actions.getKeySize();edkEnd();
        edk::uint32 actionSize = 0u;edkEnd();
        edk::float32 second=0.f;edkEnd();
        edk::uint64 code = 0u;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            //load the kay second
            second = obj->actions.getKeySecond(i);edkEnd();
            //load the size of actions inside de key
            actionSize = obj->actions.getActionsSize(i);edkEnd();
            for(edk::uint32 j=0u;j<actionSize;j++){
                //get the action code
                code = obj->actions.getActionCode(i,j);edkEnd();

                switch(code){
                case 1u:
                {
                    //ActionPosition
                    edk::Object2D::ActionPosition* temp = (edk::Object2D::ActionPosition*)obj->actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object2D::ActionPosition(this,temp->getPosition()));edkEnd();
                    break;
                }
                case 2u:
                {
                    //ActionMove
                    edk::Object2D::ActionMove* temp = (edk::Object2D::ActionMove*)obj->actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object2D::ActionMove(this,temp->getDuration(),temp->getPosition()));edkEnd();
                    break;
                }
                case 3u:
                {
                    //ActionSetSize
                    edk::Object2D::ActionSetSize* temp = (edk::Object2D::ActionSetSize*)obj->actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object2D::ActionSetSize(this,temp->getSize()));edkEnd();
                    break;
                }
                case 4u:
                {
                    //ActionSize
                    edk::Object2D::ActionSize* temp = (edk::Object2D::ActionSize*)obj->actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object2D::ActionSize(this,temp->getDuration(),temp->getSize()));edkEnd();
                    break;
                }
                case 5u:
                {
                    //ActionSetAngle
                    edk::Object2D::ActionSetAngle* temp = (edk::Object2D::ActionSetAngle*)obj->actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object2D::ActionSetAngle(this,temp->getAngle()));edkEnd();
                    break;
                }
                case 6u:
                {
                    //ActionAngle
                    edk::Object2D::ActionAngle* temp = (edk::Object2D::ActionAngle*)obj->actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object2D::ActionAngle(this,temp->getDuration(),temp->getAngle()));edkEnd();
                    break;
                }
                case 7u:
                {
                    //ActionMeshName
                    edk::Object2D::ActionMeshName* temp = (edk::Object2D::ActionMeshName*)obj->actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object2D::ActionMeshName(this,temp->getId(),temp->getName(),temp->getLoop()));edkEnd();
                    break;
                }
                case 8u:
                {
                    //ActionMeshStop
                    edk::Object2D::ActionMeshStop* temp = (edk::Object2D::ActionMeshStop*)obj->actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object2D::ActionMeshStop(this,temp->getId()));edkEnd();
                    break;
                }
                default:
                {
                    //actionZero
                    this->actions.addAction(second,new edk::ActionZero());edkEnd();
                }
                }
            }
        }
        */
        return true;
    }
    return false;
}
