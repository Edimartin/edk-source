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
    this->classThis=NULL;
    this->Constructor();
}

edk::Object2D::~Object2D(){
    this->Destructor();
}

//Draw function
//HIDE
void edk::Object2D::drawHideBoundingBox(){}
void edk::Object2D::drawHide(bool ){}
void edk::Object2D::drawHideOneTexture(){}
void edk::Object2D::drawHideOneTextureWithLight(bool ){}
void edk::Object2D::drawHideWithoutMaterial(){}
void edk::Object2D::drawHideWithoutMaterialWithLight(bool ){}
void edk::Object2D::drawHideWire(){}
void edk::Object2D::drawHideWirePolygon(edk::uint32 ,edk::uint32 ){}
bool edk::Object2D::drawHideMesh(bool /*haveLight*/,edk::uint32 ){return true;}
bool edk::Object2D::drawHidePolygon(bool /*haveLight*/,edk::uint32 ,edk::uint32 ){return true;}
bool edk::Object2D::drawHideMeshOneTexture(edk::uint32 ){return true;}
bool edk::Object2D::drawHidePolygonOneTexture(edk::uint32 ,edk::uint32 ){return true;}
bool edk::Object2D::drawHideMeshOneTextureWithLight(bool /*haveLight*/,edk::uint32 ){return true;}
bool edk::Object2D::drawHidePolygonOneTextureWithLight(bool /*haveLight*/,edk::uint32 ,edk::uint32 ){return true;}
bool edk::Object2D::drawHideMeshWithoutMaterial(edk::uint32 ){return true;}
bool edk::Object2D::drawHidePolygonWithoutMaterial(edk::uint32 ,edk::uint32 ){return true;}
bool edk::Object2D::drawHideMeshWithoutMaterialWithLight(bool /*haveLight*/,edk::uint32 ){return true;}
bool edk::Object2D::drawHidePolygonWithoutMaterialWithLight(bool /*haveLight*/,edk::uint32 ,edk::uint32 ){return true;}
bool edk::Object2D::drawHideMeshWire(edk::uint32 ){return true;}
bool edk::Object2D::drawHidePolygonWire(edk::uint32 ,edk::uint32 ){return true;}
//UNHIDE
void edk::Object2D::drawUnhideBoundingBox(){
    edk::GU::guBegin(GU_LINE_LOOP);
    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );
    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);
    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.size.height);
    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.origin.y   );
    edk::GU::guEnd();
}
void edk::Object2D::drawUnhide(bool haveLight){
    edk::shape::Mesh2D* mesh;
    if(haveLight){
        edk::uint32 size = this->meshes.size();
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    mesh->drawOneTexture();
                }
                else{
                    mesh->drawMultiTexture();
                }
            }
        }
    }
    else{
        edk::uint32 size = this->meshes.size();
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    mesh->drawOneTexture();
                }
                else{
                    mesh->drawMultiTexture();
                }
            }
        }
    }
}
void edk::Object2D::drawUnhideOneTexture(){
    edk::shape::Mesh2D* mesh;
    //print all polygonList
    edk::uint32 size = this->meshes.size();
    for(edk::uint32 i=0u;i<size;i++){
        //
        mesh = this->meshes.getMesh(i);
        if(mesh){
            mesh->drawOneTexture();
        }
    }
}
void edk::Object2D::drawUnhideOneTextureWithLight(bool haveLight){
    edk::shape::Mesh2D* mesh;
    if(haveLight){
        edk::uint32 size = this->meshes.size();
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);
            if(mesh){
                mesh->drawOneTexture();
            }
        }
    }
    else{
        edk::uint32 size = this->meshes.size();
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);
            if(mesh){
                mesh->drawOneTexture();
            }
        }
    }
}
void edk::Object2D::drawUnhideWithoutMaterial(){
    edk::shape::Mesh2D* mesh;
    //print all polygonList
    edk::uint32 size = this->meshes.size();
    for(edk::uint32 i=0u;i<size;i++){
        //
        mesh = this->meshes.getMesh(i);
        if(mesh){
            mesh->drawWithoutMaterial();
        }
    }
}
void edk::Object2D::drawUnhideWithoutMaterialWithLight(bool haveLight){
    edk::shape::Mesh2D* mesh;
    if(haveLight){
        edk::uint32 size = this->meshes.size();
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);
            if(mesh){
                mesh->drawWithoutMaterial();
            }
        }
    }
    else{
        edk::uint32 size = this->meshes.size();
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);
            if(mesh){
                mesh->drawWithoutMaterial();
            }
        }
    }
}
void edk::Object2D::drawUnhideWire(){
    edk::shape::Mesh2D* mesh;
    //print all polygonList
    edk::uint32 size = this->meshes.size();
    for(edk::uint32 i=0u;i<size;i++){
        //
        mesh = this->meshes.getMesh(i);
        if(mesh){
            mesh->drawWirePolygons();
        }
    }
}
void edk::Object2D::drawUnhideWirePolygon(edk::uint32 meshPosition,edk::uint32 polygon){
    edk::shape::Mesh2D* mesh = this->meshes.getMesh(meshPosition);
    if(mesh){
        mesh->drawWirePolygon(polygon);
    }
}
bool edk::Object2D::drawUnhideMesh(bool haveLight,edk::uint32 meshPosition){
    bool ret=false;
    edk::shape::Mesh2D* mesh;
    if(haveLight){
        if(meshPosition < this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    mesh->drawOneTexture();
                }
                else{
                    mesh->drawMultiTexture();
                }
                ret=true;
            }
        }
    }
    else{
        if(meshPosition < this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    mesh->drawOneTexture();
                }
                else{
                    mesh->drawMultiTexture();
                }
                ret=true;
            }
        }
    }
    return ret;
}
bool edk::Object2D::drawUnhidePolygon(bool haveLight,edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;
    edk::shape::Mesh2D* mesh;
    if(haveLight){
        if(meshPosition < this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    ret = mesh->drawPolygonOneTexture(polygon);
                }
                else{
                    ret = mesh->drawPolygonMultiTexture(polygon);
                }
            }
        }
    }
    else{
        if(meshPosition < this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    ret = mesh->drawPolygonOneTexture(polygon);
                }
                else{
                    ret = mesh->drawPolygonMultiTexture(polygon);
                }
            }
        }
    }
    return ret;
}
bool edk::Object2D::drawUnhideMeshOneTexture(edk::uint32 meshPosition){
    bool ret=false;
    edk::shape::Mesh2D* mesh;
    //
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);
        if(mesh){
            mesh->drawOneTexture();
            ret = true;
        }
    }
    return ret;
}
bool edk::Object2D::drawUnhidePolygonOneTexture(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;
    edk::shape::Mesh2D* mesh;
    //
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);
        if(mesh){
            ret = mesh->drawPolygonOneTexture(polygon);
        }
    }
    return ret;
}
bool edk::Object2D::drawUnhideMeshOneTextureWithLight(bool haveLight,edk::uint32 meshPosition){
    bool ret=false;
    edk::shape::Mesh2D* mesh;
    if(haveLight){
        if(meshPosition < this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);
            if(mesh){
                mesh->drawOneTexture();
                ret = true;
            }
        }
    }
    else{
        edk::uint32 size = this->meshes.size();
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);
            if(mesh){
                mesh->drawOneTexture();
                ret = true;
            }
        }
    }
    return ret;
}
bool edk::Object2D::drawUnhidePolygonOneTextureWithLight(bool haveLight,edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;
    edk::shape::Mesh2D* mesh;
    if(haveLight){
        if(meshPosition < this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);
            if(mesh){
                ret = mesh->drawPolygonOneTexture(polygon);
            }
        }
    }
    else{
        edk::uint32 size = this->meshes.size();
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);
            if(mesh){
                ret = mesh->drawPolygonOneTexture(polygon);
            }
        }
    }
    return ret;
}
bool edk::Object2D::drawUnhideMeshWithoutMaterial(edk::uint32 meshPosition){
    bool ret=false;
    edk::shape::Mesh2D* mesh;
    //print all polygonList
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);
        if(mesh){
            mesh->drawWithoutMaterial();
            ret = true;
        }
    }
    return ret;
}
bool edk::Object2D::drawUnhidePolygonWithoutMaterial(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;
    edk::shape::Mesh2D* mesh;
    //print all polygonList
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);
        if(mesh){
            ret = mesh->drawPolygonWithoutMaterial(polygon);
        }
    }
    return ret;
}
bool edk::Object2D::drawUnhideMeshWithoutMaterialWithLight(bool haveLight,edk::uint32 meshPosition){
    bool ret=false;
    edk::shape::Mesh2D* mesh;
    if(haveLight){
        if(meshPosition<this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);
            if(mesh){
                mesh->drawWithoutMaterial();
                ret=true;
            }
        }
    }
    else{
        if(meshPosition<this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);
            if(mesh){
                mesh->drawWithoutMaterial();
                ret=true;
            }
        }
    }
    return ret;
}
bool edk::Object2D::drawUnhidePolygonWithoutMaterialWithLight(bool haveLight,edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;
    edk::shape::Mesh2D* mesh;
    if(haveLight){
        if(meshPosition<this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);
            if(mesh){
                ret = mesh->drawPolygonWithoutMaterial(polygon);
            }
        }
    }
    else{
        if(meshPosition<this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);
            if(mesh){
                ret = mesh->drawPolygonWithoutMaterial(polygon);
            }
        }
    }
    return ret;
}
bool edk::Object2D::drawUnhideMeshWire(edk::uint32 meshPosition){
    bool ret=false;
    edk::shape::Mesh2D* mesh;
    //print all polygonList
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);
        if(mesh){
            mesh->drawWirePolygons();
            ret = true;
        }
    }
    return ret;
}
bool edk::Object2D::drawUnhidePolygonWire(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;

    edk::shape::Mesh2D* mesh;
    //print all polygonList
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);
        if(mesh){
            ret = mesh->drawWirePolygon(polygon);
        }
    }
    return ret;
}
//update animations
void edk::Object2D::updateChildremsAnimations(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->updateAnimations();
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->updateAnimations();
    }
}
void edk::Object2D::updateChildremsAnimations(edk::float32 seconds){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->updateAnimations(seconds);
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->updateAnimations(seconds);
    }
}
//update the values from father
bool edk::Object2D::updateValuesFromFather(edk::vector::Matrixf32<3u,3u>* matrixTransform){
    if(matrixTransform){
        if(this->father){
            //calculate the boundingBox from the father
            this->father->updateValuesFromFather(matrixTransform);

            edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);
            edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->matrixAngle);
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);
            edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);
            matrixTransform->multiplyThisWithMatrix(&this->matrixSize);
            matrixTransform->multiplyThisWithMatrix(&this->matrixAngle);
            matrixTransform->multiplyThisWithMatrix(&this->matrixPosition);
            matrixTransform->multiplyThisWithMatrix(&this->matrixPivo);

            //first copy the matrix
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
            //translate
            matrixTransform->multiplyThisWithMatrix(&this->matrixPosition);
            //angle
            matrixTransform->multiplyThisWithMatrix(&this->matrixAngle);
            //scale
            matrixTransform->multiplyThisWithMatrix(&this->matrixSize);
            //Pivo
            matrixTransform->multiplyThisWithMatrix(&this->matrixPivo);
        }
        else{
            //first copy the matrix
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
            //translate
            matrixTransform->multiplyThisWithMatrix(&this->matrixPosition);
            //angle
            matrixTransform->multiplyThisWithMatrix(&this->matrixAngle);
            //scale
            matrixTransform->multiplyThisWithMatrix(&this->matrixSize);
            //Pivo
            matrixTransform->multiplyThisWithMatrix(&this->matrixPivo);
        }
        return true;
    }
    return false;
}

void edk::Object2D::Constructor(){
    edk::Object2DValues::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->hided=true;

        this->boundingBox = 0.f;
        this->meshes.Constructor();
        this->matrixPosition.Constructor();
        this->matrixPivo.Constructor();
        this->matrixAngle.Constructor();
        this->matrixSize.Constructor();
        this->matrixTransform.Constructor();
        this->matrixPivo.Constructor();
        this->childremsFront.Constructor();
        this->childremsBack.Constructor();

        //
        this->type=edk::TypeObject2D;
        this->selected=NULL;
        //rotation
        this->angle=0.0f;
        //Scale
        this->size = edk::size2f32(1.f,1.f);
        /*
    this->actions.setReadXMLActionFunction(&edk::Object2D::readXMLAction);
    */
        this->father=NULL;

        this->newSize=1.f;
        this->loadSaveIdentityValues();

        this->unhide();
    }
}
void edk::Object2D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        /*
    this->actions.cleanReadXMLActionFunction();
    */
        this->cleanMeshes();

        this->meshes.Destructor();
        this->matrixPosition.Destructor();
        this->matrixPivo.Destructor();
        this->matrixAngle.Destructor();
        this->matrixSize.Destructor();
        this->matrixTransform.Destructor();
        this->matrixPivo.Destructor();
        this->childremsFront.Destructor();
        this->childremsBack.Destructor();
    }
    edk::Object2DValues::Destructor();
}

void edk::Object2D::writeFatherBoundingBox(edk::rectf32* rect,edk::vector::Matrixf32<3u,3u>* transformMat){
    if(this->father){
        //calculate the boundingBox from the father
        this->father->writeFatherBoundingBox(rect,transformMat);

        edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);
        edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->matrixAngle);
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
        //translate
        transformMat->multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        if(this->fixedRotation){
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
            transformMat->multiplyThisWithMatrix(&this->matrixAngle);
        }
        //scale
        transformMat->multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        transformMat->multiplyThisWithMatrix(&this->matrixPivo);
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
        //translate
        transformMat->multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        if(this->fixedRotation){
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
            transformMat->multiplyThisWithMatrix(&this->matrixAngle);
        }
        //scale
        transformMat->multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        transformMat->multiplyThisWithMatrix(&this->matrixPivo);
    }
}
bool edk::Object2D::writeBoundingBox(edk::rectf32* rect){
    //multiply the matrix by
    this->matrixTransform.setIdentity();
    if(this->father){
        //calculate the boundingBox from the father
        this->father->writeFatherBoundingBox(rect,&this->matrixTransform);

        edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);
        edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->matrixAngle);
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        if(this->fixedRotation){
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
        }
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        if(this->fixedRotation){
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
        }
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);
    }


    edk::shape::Mesh2D* mesh;
    edk::uint32 size = this->meshes.size();
    if(size){
        mesh = this->meshes.getMesh(0u);
        if(mesh){
            if(this->father){
                mesh->calculateBoundingBox(rect,&this->matrixTransform);
            }
            else{
                *rect = mesh->generateBoundingBox(&this->matrixTransform);
            }
        }
        for(edk::uint32 i=1u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);
            if(mesh){
                mesh->calculateBoundingBox(rect,&this->matrixTransform);
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

            edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);
            edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->matrixAngle);
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);
            edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);

            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
            //angle
            if(this->fixedRotation){
                edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
                this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
            }
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);
        }
        else{
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
            //angle
            if(this->fixedRotation){
                edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
                this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
            }
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);
        }



        edk::shape::Mesh2D* mesh;
        edk::uint32 size = this->meshes.size();
        if(size){
            mesh = this->meshes.getMesh(0u);
            if(mesh){
                if(this->father){
                    *rect = mesh->generateBoundingBox(&this->matrixTransform);
                }
                else{
                    mesh->calculateBoundingBox(rect,&this->matrixTransform);
                }
            }
            for(edk::uint32 i=1u;i<size;i++){
                //
                mesh = this->meshes.getMesh(i);
                if(mesh){
                    mesh->calculateBoundingBox(rect,&this->matrixTransform);
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
    //multiply the matrix by
    this->matrixTransform.setIdentity();
    if(this->father){
        //calculate the boundingBox from the father
        this->father->writeFatherBoundingBox(rect,&this->matrixTransform);

        edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);
        edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->matrixAngle);
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);

        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        if(this->fixedRotation){
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
        }
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        if(this->fixedRotation){
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
        }
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);
    }

    edk::shape::Mesh2D* mesh;
    size = this->meshes.size();
    if(size){
        mesh = this->meshes.getMesh(0u);
        if(mesh){
            if(this->father){
                mesh->calculateBoundingBox(rect,&this->matrixTransform);
            }
            else{
                *rect = mesh->generateBoundingBox(&this->matrixTransform);
            }
        }
        for(edk::uint32 i=1u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);
            if(mesh){
                mesh->calculateBoundingBox(rect,&this->matrixTransform);
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

            edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);
            edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->matrixAngle);
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);
            edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);


            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
            //angle
            if(this->fixedRotation){
                edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
                this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
            }
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);
        }
        else{
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
            //angle
            if(this->fixedRotation){
                edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
                this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
            }
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);
        }

        edk::shape::Mesh2D* mesh;
        size = this->meshes.size();
        if(size){
            mesh = this->meshes.getMesh(0u);
            if(mesh){
                if(this->father){
                    *rect = mesh->generateBoundingBox(&this->matrixTransform);
                }
                else{
                    mesh->calculateBoundingBox(rect,&this->matrixTransform);
                }
            }
            for(edk::uint32 i=1u;i<size;i++){
                //
                mesh = this->meshes.getMesh(i);
                if(mesh){
                    mesh->calculateBoundingBox(rect,&this->matrixTransform);
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

void edk::Object2D::loadFatherMatrix(edk::vector::Matrixf32<3u,3u>* transformMat){
    if(this->father){
        //calculate the boundingBox from the father
        this->father->loadFatherMatrix(transformMat);

        edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);
        edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->matrixAngle);
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);
        transformMat->multiplyThisWithMatrix(&this->matrixSize);
        transformMat->multiplyThisWithMatrix(&this->matrixAngle);
        transformMat->multiplyThisWithMatrix(&this->matrixPosition);
        transformMat->multiplyThisWithMatrix(&this->matrixPivo);

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
        //translate
        transformMat->multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        if(this->fixedRotation){
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
            transformMat->multiplyThisWithMatrix(&this->matrixAngle);
        }
        //scale
        transformMat->multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        transformMat->multiplyThisWithMatrix(&this->matrixPivo);
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
        //translate
        transformMat->multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        if(this->fixedRotation){
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
            transformMat->multiplyThisWithMatrix(&this->matrixAngle);
        }
        //scale
        transformMat->multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        transformMat->multiplyThisWithMatrix(&this->matrixPivo);
    }
}

//Function to read the actions
edk::Action* edk::Object2D::readXMLAction(edk::classID /*thisPointer*/,edk::uint32 /*actionCode*/){
    /*
    switch(actionCode){
    case 1u:
    {
        //ActionPosition
        return new edk::Object2D::ActionPosition((edk::Object2D*)thisPointer,edk::vec2f32(0,0));
        break;
    }
    case 2u:
    {
        //ActionMove
        return new edk::Object2D::ActionMove((edk::Object2D*)thisPointer,0,edk::vec2f32(0,0));
        break;
    }
    case 3u:
    {
        //ActionSetSize
        return new edk::Object2D::ActionSetSize((edk::Object2D*)thisPointer,edk::size2f32(1,1));
        break;
    }
    case 4u:
    {
        //ActionSize
        return new edk::Object2D::ActionSize((edk::Object2D*)thisPointer,0,edk::size2f32(1,1));
        break;
    }
    case 5u:
    {
        //ActionSetAngle
        return new edk::Object2D::ActionSetAngle((edk::Object2D*)thisPointer,0);
        break;
    }
    case 6u:
    {
        //ActionAngle
        return new edk::Object2D::ActionAngle((edk::Object2D*)thisPointer,0,0);
        break;
    }
    case 7u:
    {
        //ActionMeshName
        return new edk::Object2D::ActionMeshName((edk::Object2D*)thisPointer,0,NULL,false);
        break;
    }
    case 8u:
    {
        //ActionMeshStop
        return new edk::Object2D::ActionMeshStop((edk::Object2D*)thisPointer,0);
        break;
    }
    }
    */
    return new edk::ActionZero();
}

//draw the mesh
void edk::Object2D::drawChildremsBackBoundingBox(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildBoundingBox();
    }
}
void edk::Object2D::drawChildBackBoundingBox(){
    //test if have a father
    //if(this->father){
    //    //put the transformation on a stack
    //    edk::GU::guPushMatrix();
    //
    //    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);
    //
    //    edk::GU::guBegin(GU_LINE_LOOP);
    //    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );
    //    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);
    //    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.size.height);
    //    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.origin.y   );
    //    edk::GU::guEnd();
    //
    //    edk::GU::guPopMatrix();
    //}
    //else{
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);

    this->drawChildremsBackBoundingBox();

    (this->*functionDrawBoundingBox)();

    edk::GU::guPopMatrix();
    //}
}
void edk::Object2D::drawChildremsFrontBoundingBox(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildBoundingBox();
    }
}
void edk::Object2D::drawChildFrontBoundingBox(){
    //test if have a father
    //if(this->father){
    //    //put the transformation on a stack
    //    edk::GU::guPushMatrix();
    //
    //    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);
    //
    //    edk::GU::guBegin(GU_LINE_LOOP);
    //    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );
    //    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);
    //    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.size.height);
    //    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.origin.y   );
    //    edk::GU::guEnd();
    //
    //    edk::GU::guPopMatrix();
    //}
    //else{
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    (this->*functionDrawBoundingBox)();

    this->drawChildremsFrontBoundingBox();

    edk::GU::guPopMatrix();
    //}
}
void edk::Object2D::drawChildremsBoundingBox(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildBoundingBox();
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildBoundingBox();
    }
}
void edk::Object2D::drawChildBoundingBox(){
    //test if have a father
    //if(this->father){
    //    //put the transformation on a stack
    //    edk::GU::guPushMatrix();
    //
    //    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);
    //
    //    edk::GU::guBegin(GU_LINE_LOOP);
    //    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );
    //    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);
    //    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.size.height);
    //    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.origin.y   );
    //    edk::GU::guEnd();
    //
    //    edk::GU::guPopMatrix();
    //}
    //else{
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);

    this->drawChildremsBackBoundingBox();

    (this->*functionDrawBoundingBox)();

    this->drawChildremsFrontBoundingBox();
    edk::GU::guPopMatrix();
    //}
}
void edk::Object2D::drawChildremsBack(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChild(haveLight);
    }
}
void edk::Object2D::drawChildBack(bool haveLight){
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

    this->drawChildremsBack(haveLight);

    (this->*functionDraw)(haveLight);

    //glEnable(GL_RESCALE_NORMAL);
    edk::GU::guPopMatrix();
}
void edk::Object2D::drawChildremsFront(bool haveLight){
    edk::uint32 size = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChild(haveLight);
    }
}
void edk::Object2D::drawChildFront(bool haveLight){
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

    (this->*functionDraw)(haveLight);

    this->drawChildremsFront(haveLight);
    //glEnable(GL_RESCALE_NORMAL);
    edk::GU::guPopMatrix();
}
void edk::Object2D::drawChildrems(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChild(haveLight);
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChild(haveLight);
    }
}
void edk::Object2D::drawChild(bool haveLight){
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

    this->drawChildremsBack(haveLight);

    (this->*functionDraw)(haveLight);

    this->drawChildremsFront(haveLight);
    //glEnable(GL_RESCALE_NORMAL);
    edk::GU::guPopMatrix();
}
void edk::Object2D::drawChildremsBackOneTexture(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildOneTexture();
    }
}
void edk::Object2D::drawChildBackOneTexture(){
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

    this->drawChildremsBackOneTexture();

    (this->*functionDrawOneTexture)();

    edk::GU::guPopMatrix();
}
void edk::Object2D::drawChildremsFrontOneTexture(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildOneTexture();
    }
}
void edk::Object2D::drawChildFrontOneTexture(){
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

    (this->*functionDrawOneTexture)();

    this->drawChildremsFrontOneTexture();
    edk::GU::guPopMatrix();
}
void edk::Object2D::drawChildremsOneTexture(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildOneTexture();
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildOneTexture();
    }
}
void edk::Object2D::drawChildOneTexture(){
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

    this->drawChildremsBackOneTexture();

    (this->*functionDrawOneTexture)();

    this->drawChildremsFrontOneTexture();

    edk::GU::guPopMatrix();
}
void edk::Object2D::drawChildremsBackOneTextureWithLight(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildOneTextureWithLight(haveLight);
    }
}
void edk::Object2D::drawChildBackOneTextureWithLight(bool haveLight){
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

    this->drawChildremsBackOneTextureWithLight(haveLight);

    (this->*functionDrawOneTextureWithLight)(haveLight);

    edk::GU::guPopMatrix();
}
void edk::Object2D::drawChildremsFrontOneTextureWithLight(bool haveLight){
    edk::uint32 size = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildOneTextureWithLight(haveLight);
    }
}
void edk::Object2D::drawChildFrontOneTextureWithLight(bool haveLight){
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

    (this->*functionDrawOneTextureWithLight)(haveLight);

    this->drawChildremsFrontOneTextureWithLight(haveLight);

    edk::GU::guPopMatrix();
}
void edk::Object2D::drawChildremsOneTextureWithLight(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildOneTextureWithLight(haveLight);
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildOneTextureWithLight(haveLight);
    }
}
void edk::Object2D::drawChildOneTextureWithLight(bool haveLight){
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

    this->drawChildremsBackOneTextureWithLight(haveLight);

    (this->*functionDrawOneTextureWithLight)(haveLight);

    this->drawChildremsFrontOneTextureWithLight(haveLight);

    edk::GU::guPopMatrix();
}
void edk::Object2D::drawChildremsBackWithoutMaterial(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildWithoutMaterial();
    }
}
void edk::Object2D::drawChildBackWithoutMaterial(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale2f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle);
    edk::GU::guTranslate2f32(this->connectedPosition);
    edk::GU::guTranslate2f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    this->drawChildremsBackWithoutMaterial();

    (this->*functionDrawWithoutMaterial)();

    edk::GU::guPopMatrix();
}
void edk::Object2D::drawChildremsFrontWithoutMaterial(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildWithoutMaterial();
    }
}
void edk::Object2D::drawChildFrontWithoutMaterial(){
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

    (this->*functionDrawWithoutMaterial)();

    this->drawChildremsFrontWithoutMaterial();

    edk::GU::guPopMatrix();
}
void edk::Object2D::drawChildremsWithoutMaterial(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildWithoutMaterial();
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildWithoutMaterial();
    }
}
void edk::Object2D::drawChildWithoutMaterial(){
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

    this->drawChildremsBackWithoutMaterial();

    (this->*functionDrawWithoutMaterial)();

    this->drawChildremsFrontWithoutMaterial();

    edk::GU::guPopMatrix();
}
void edk::Object2D::drawChildremsBackWithoutMaterialWithLight(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildWithoutMaterialWithLight(haveLight);
    }
}
void edk::Object2D::drawChildBackWithoutMaterialWithLight(bool haveLight){
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

    this->drawChildremsBackWithoutMaterialWithLight(haveLight);

    (this->*functionDrawWithoutMaterialWithLight)(haveLight);

    edk::GU::guPopMatrix();
}
void edk::Object2D::drawChildremsFrontWithoutMaterialWithLight(bool haveLight){
    edk::uint32 size = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildWithoutMaterialWithLight(haveLight);
    }
}
void edk::Object2D::drawChildFrontWithoutMaterialWithLight(bool haveLight){
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

    (this->*functionDrawWithoutMaterialWithLight)(haveLight);

    this->drawChildremsFrontWithoutMaterialWithLight(haveLight);

    edk::GU::guPopMatrix();
}
void edk::Object2D::drawChildremsWithoutMaterialWithLight(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildWithoutMaterialWithLight(haveLight);
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildWithoutMaterialWithLight(haveLight);
    }
}
void edk::Object2D::drawChildWithoutMaterialWithLight(bool haveLight){
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

    this->drawChildremsBackWithoutMaterialWithLight(haveLight);

    (this->*functionDrawWithoutMaterialWithLight)(haveLight);

    this->drawChildremsFrontWithoutMaterialWithLight(haveLight);

    edk::GU::guPopMatrix();
}
void edk::Object2D::drawChildremsBackWire(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildWire();
    }
}
void edk::Object2D::drawChildBackWire(){
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

    this->drawChildremsBackWire();

    (this->*functionDrawWire)();

    edk::GU::guPopMatrix();
}
void edk::Object2D::drawChildremsFrontWire(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildWire();
    }
}
void edk::Object2D::drawChildFrontWire(){
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

    (this->*functionDrawWire)();

    this->drawChildremsFrontWire();

    edk::GU::guPopMatrix();
}
void edk::Object2D::drawChildremsWire(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildWire();
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildWire();
    }
}
void edk::Object2D::drawChildWire(){
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

    this->drawChildremsBackWire();

    (this->*functionDrawWire)();

    this->drawChildremsFrontWire();

    edk::GU::guPopMatrix();
}
//draw the pivo
void edk::Object2D::drawChildremsBackPivo(edk::float32 size,edk::color3f32 color){
    edk::uint32 cSize = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildPivo(size,color);
    }
}
void edk::Object2D::drawChildBackPivo(edk::float32 size,edk::color3f32 color){
    edk::Object2D::drawPivoInPosition(this->position,size,color);
    if(this->childremsBack.size()){
        edk::GU::guPushMatrix();
        //add translate
        edk::GU::guTranslate2f32(this->position);
        //add rotation
        edk::GU::guRotateZf32(this->angle);
        //add scale
        edk::GU::guScale2f32(this->size);
        //set the pivo
        edk::GU::guTranslate2f32(this->pivo*-1.0f);
        this->drawChildremsBackPivo(size,color);
        edk::GU::guPopMatrix();
    }
}
void edk::Object2D::drawChildremsFrontPivo(edk::float32 size,edk::color3f32 color){
    edk::uint32 cSize = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildPivo(size,color);
    }
}
void edk::Object2D::drawChildFrontPivo(edk::float32 size,edk::color3f32 color){
    edk::Object2D::drawPivoInPosition(this->position,size,color);
    if(this->childremsFront.size()){
        edk::GU::guPushMatrix();
        //add translate
        edk::GU::guTranslate2f32(this->position);
        //add rotation
        edk::GU::guRotateZf32(this->angle);
        //add scale
        edk::GU::guScale2f32(this->size);
        //set the pivo
        edk::GU::guTranslate2f32(this->pivo*-1.0f);
        this->drawChildremsFrontPivo(size,color);
        edk::GU::guPopMatrix();
    }
}
void edk::Object2D::drawChildremsPivo(edk::float32 size,edk::color3f32 color){
    edk::uint32 cSize = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildPivo(size,color);
    }
    cSize = this->childremsFront.size();
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildPivo(size,color);
    }
}
void edk::Object2D::drawChildPivo(edk::float32 size,edk::color3f32 color){
    if(this->childremsBack.size()){
        edk::GU::guPushMatrix();
        //add translate
        edk::GU::guTranslate2f32(this->position);
        //add rotation
        edk::GU::guRotateZf32(this->angle);
        //add scale
        edk::GU::guScale2f32(this->size);
        //set the pivo
        edk::GU::guTranslate2f32(this->pivo*-1.0f);
        this->drawChildremsBackPivo(size,color);
        edk::GU::guPopMatrix();
    }
    edk::Object2D::drawPivoInPosition(this->position,size,color);
    if(this->childremsFront.size()){
        edk::GU::guPushMatrix();
        //add translate
        edk::GU::guTranslate2f32(this->position);
        //add rotation
        edk::GU::guRotateZf32(this->angle);
        //add scale
        edk::GU::guScale2f32(this->size);
        //set the pivo
        edk::GU::guTranslate2f32(this->pivo*-1.0f);
        this->drawChildremsFrontPivo(size,color);
        edk::GU::guPopMatrix();
    }
}
void edk::Object2D::drawChildremsBackPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::uint32 cSize = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildPivo(size,r,g,b);
    }
}
void edk::Object2D::drawChildBackPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::GU::guPushMatrix();

    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);
    if(this->childremsBack.size()){
        this->drawChildremsBackPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();

    edk::GU::guPushMatrix();

    edk::GU::guScale2f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle);
    edk::GU::guTranslate2f32(this->connectedPosition);
    edk::GU::guTranslate2f32(this->connectedPivo*-1.0f);

    //add translate
    //edk::GU::guTranslate2f32(this->position);

    edk::Object2D::drawPivoInPosition(this->position,size,edk::color3f32(r,g,b));

    edk::GU::guPopMatrix();

    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);
    if(this->childremsFront.size()){
        this->drawChildremsFrontPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();
}
void edk::Object2D::drawChildremsFrontPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::uint32 cSize = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildPivo(size,r,g,b);
    }
}
void edk::Object2D::drawChildFrontPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::GU::guPushMatrix();

    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);
    if(this->childremsBack.size()){
        this->drawChildremsBackPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();


    edk::GU::guPushMatrix();

    edk::GU::guScale2f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle);
    edk::GU::guTranslate2f32(this->connectedPosition);
    edk::GU::guTranslate2f32(this->connectedPivo*-1.0f);

    //add translate
    //edk::GU::guTranslate2f32(this->position);

    edk::Object2D::drawPivoInPosition(this->position,size,edk::color3f32(r,g,b));

    edk::GU::guPopMatrix();

    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);
    if(this->childremsFront.size()){
        this->drawChildremsFrontPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();
}
void edk::Object2D::drawChildremsPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::uint32 cSize = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildPivo(size,r,g,b);
    }
    cSize = this->childremsFront.size();
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildPivo(size,r,g,b);
    }
}
void edk::Object2D::drawChildPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    if(this->childremsBack.size()){
        edk::Object2D::drawPivoInPosition(this->position,size,edk::color3f32(r,g,b));
        edk::GU::guPushMatrix();
        //add translate
        edk::GU::guTranslate2f32(this->position);
        //add rotation
        edk::GU::guRotateZf32(this->angle);
        //add scale
        edk::GU::guScale2f32(this->size);
        //set the pivo
        edk::GU::guTranslate2f32(this->pivo*-1.0f);
        this->drawChildremsBackPivo(size,r,g,b);
        edk::GU::guPopMatrix();
    }
    edk::GU::guPushMatrix();
    edk::GU::guScale2f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle);
    edk::GU::guTranslate2f32(this->connectedPosition);
    edk::GU::guTranslate2f32(this->connectedPivo*-1.0f);
    edk::Object2D::drawPivoInPosition(this->position,size,edk::color3f32(r,g,b));
    edk::GU::guPopMatrix();
    if(this->childremsFront.size()){
        edk::Object2D::drawPivoInPosition(this->position,size,edk::color3f32(r,g,b));
        edk::GU::guPushMatrix();
        //add translate
        edk::GU::guTranslate2f32(this->position);
        //add rotation
        edk::GU::guRotateZf32(this->angle);
        //add scale
        edk::GU::guScale2f32(this->size);
        //set the pivo
        edk::GU::guTranslate2f32(this->pivo*-1.0f);
        this->drawChildremsFrontPivo(size,r,g,b);
        edk::GU::guPopMatrix();
    }
}

//Actions
edk::Object2D::ActionPosition::ActionPosition(edk::Object2D* /*object*/, edk::vec2f32 /*position*/){
    /*
    this->position=position;
    this->object=object;
    this->code = 1u;
    */
}
//run action function
void edk::Object2D::ActionPosition::runAction(){
    this->object->position = this->position;
}
//write to XML
bool edk::Object2D::ActionPosition::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write the position
                    xml->addSelectedNextAttribute("positionX",this->position.x);
                    xml->addSelectedNextAttribute("positionY",this->position.y);

                    ret=true;
                    //select father
                    xml->selectFather();
                }
                free(name);
            }
            free(number);
        }
    }
    return ret;
}
//read XML
bool edk::Object2D::ActionPosition::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read the position
                    this->position.x = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionX"));
                    this->position.y = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionY"));

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                free(name);
            }
            free(number);
        }
    }
    return ret;
}
//GET
edk::vec2f32 edk::Object2D::ActionPosition::getPosition(){
    return this->position;
}
edk::Object2D::ActionMove::ActionMove(edk::Object2D* object,edk::float32 duration, edk::vec2f32 position){
    this->position=position;
    this->duration = duration;
    this->object=object;
    this->code = 2u;
}
//run action function
void edk::Object2D::ActionMove::runAction(){
    this->object->animationPosition.cleanTracks();
    edk::uint32 track = this->object->animationPosition.newTrack();
    this->object->animationPosition.addFirstInterpolationLine(track,0,this->object->position.x,this->object->position.y,this->duration,this->position.x,this->position.y);
    this->object->animationPosition.playForwardAllTracks();
}
//write to XML
bool edk::Object2D::ActionMove::writeToXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write the position
                    xml->addSelectedNextAttribute("positionX",this->position.x);
                    xml->addSelectedNextAttribute("positionY",this->position.y);
                    //write the duration
                    xml->addSelectedNextAttribute("duration",this->duration);

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                free(name);
            }
            free(number);
        }
    }
    return ret;
}
//read XML
bool edk::Object2D::ActionMove::readFromXML(edk::XML* xml,edk::uint32 id){
    bool ret=false;
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read the position
                    this->position.x = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionX"));
                    this->position.y = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionY"));
                    //read duration
                    this->duration = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("duration"));

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                free(name);
            }
            free(number);
        }
    }
    return ret;
}
//GET
edk::vec2f32 edk::Object2D::ActionMove::getPosition(){
    return this->position;
}
edk::float32 edk::Object2D::ActionMove::getDuration(){
    return this->duration;
}
edk::Object2D::ActionSetSize::ActionSetSize(edk::Object2D* /*object*/, edk::size2f32 /*size*/){
    /*
    this->object=object;
    this->size=size;
    this->code = 3u;
    */
}
//run action function
void edk::Object2D::ActionSetSize::runAction(){
    /*
    this->object->size = this->size;
    */
}
//write to XML
bool edk::Object2D::ActionSetSize::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;
    /*
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write the size
                    xml->addSelectedNextAttribute("width",this->size.width);
                    xml->addSelectedNextAttribute("height",this->size.height);

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                free(name);
            }
            free(number);
        }
    }
    */
    return ret;
}
//read XML
bool edk::Object2D::ActionSetSize::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;
    /*
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read the code
                    this->size.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("width"));
                    this->size.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("height"));

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                free(name);
            }
            free(number);
        }
    }
    */
    return ret;
}
//GET
edk::size2f32 edk::Object2D::ActionSetSize::getSize(){
    return this->size;
}
edk::Object2D::ActionSize::ActionSize(edk::Object2D* /*object*/,edk::float32 /*duration*/, edk::size2f32 /*size*/){
    /*
    this->size=size;
    this->duration = duration;
    this->object=object;
    this->code = 4u;
    */
}
//run action function
void edk::Object2D::ActionSize::runAction(){
    /*
    this->object->animationSize.cleanAnimations();
    this->object->animationSize.addFirstInterpolationLine(0,this->object->size.width,this->object->size.height,this->duration,this->size.width,this->size.height);
    this->object->animationSize.playForward();
    */
}
//write to XML
bool edk::Object2D::ActionSize::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;
    /*
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write the size
                    xml->addSelectedNextAttribute("width",this->size.width);
                    xml->addSelectedNextAttribute("height",this->size.height);
                    //write the duration
                    xml->addSelectedNextAttribute("duration",this->duration);

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                free(name);
            }
            free(number);
        }
    }
    */
    return ret;
}
//read XML
bool edk::Object2D::ActionSize::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;
    /*
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read the code
                    this->size.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("width"));
                    this->size.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("height"));
                    //read the duration
                    this->duration = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("duration"));

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                free(name);
            }
            free(number);
        }
    }
    */
    return ret;
}
//GET
edk::size2f32 edk::Object2D::ActionSize::getSize(){
    return this->size;
}
edk::float32 edk::Object2D::ActionSize::getDuration(){
    return this->duration;
}
edk::Object2D::ActionSetAngle::ActionSetAngle(edk::Object2D* object, edk::float32 angle){
    this->object = object;
    this->angle = angle;
    this->code = 5u;
}
//run action function
void edk::Object2D::ActionSetAngle::runAction(){
    this->object->angle = this->angle;
}
//write to XML
bool edk::Object2D::ActionSetAngle::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;
    /*
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write angle
                    xml->addSelectedNextAttribute("angle",this->angle);

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                free(name);
            }
            free(number);
        }
    }
    */
    return ret;
}
//read XML
bool edk::Object2D::ActionSetAngle::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;
    /*
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read angle
                    this->angle = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("angle"));

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                free(name);
            }
            free(number);
        }
    }
    */
    return ret;
}
//GET
edk::float32 edk::Object2D::ActionSetAngle::getAngle(){
    return this->angle;
}
edk::Object2D::ActionAngle::ActionAngle(edk::Object2D* /*object*/,edk::float32 /*duration*/, edk::float32 /*angle*/){
    /*
    this->object = object;
    this->duration = duration;
    this->angle = angle;
    this->code = 6u;
    */
}
//run action function
void edk::Object2D::ActionAngle::runAction(){
    /*
    this->object->animationRotation.cleanAnimations();
    this->object->animationRotation.addFirstInterpolationLine(0,this->object->angle,this->duration,this->angle);
    this->object->animationRotation.playForward();
    */
}
//write to XML
bool edk::Object2D::ActionAngle::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;
    /*
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write angle
                    xml->addSelectedNextAttribute("angle",this->angle);
                    //write the duration
                    xml->addSelectedNextAttribute("duration",this->duration);

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                free(name);
            }
            free(number);
        }
    }
    */
    return ret;
}
//read XML
bool edk::Object2D::ActionAngle::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;
    /*
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read angle
                    this->angle = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("angle"));
                    //read duratio
                    this->duration = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("duration"));

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                free(name);
            }
            free(number);
        }
    }
    */
    return ret;
}
//GET
edk::float32 edk::Object2D::ActionAngle::getAngle(){
    return this->angle;
}
edk::float32 edk::Object2D::ActionAngle::getDuration(){
    return this->duration;
}
edk::Object2D::ActionMeshName::ActionMeshName(edk::Object2D* /*object*/,edk::uint32 /*id*/, edk::char8* /*name*/,bool /*loop*/){
    /*
    this->object=object;
    this->loop = loop;
    this->id = id;
    this->setName(name);
    this->code = 7u;
    */
}
//run action function
void edk::Object2D::ActionMeshName::runAction(){
    /*
    //load the mesh
    edk::shape::Mesh2D* mesh = this->object->getMesh(this->id);
    if(mesh){
        mesh->selectedAnimationSetLoop(this->loop);
        mesh->selectedAnimationPlayNameForward(this->name());
    }
    */
}
//write to XML
bool edk::Object2D::ActionMeshName::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;
    /*
    if(edk::ActionName::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write the loop
                    if(this->loop){
                        xml->setSelectedString("loopOn");
                    }
                    else{
                        xml->setSelectedString("loopOff");
                    }

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                free(name);
            }
            free(number);
        }
    }
    */
    return ret;
}
//read XML
bool edk::Object2D::ActionMeshName::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;
    /*
    edk::ActionName::readFromXML(xml,id);
    this->id = 7u;
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read the loop
                    if(edk::String::strCompare((edk::char8*)"loopOn",xml->getSelectedString())){
                        this->loop=true;
                    }
                    else{
                        this->loop=false;
                    }

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                free(name);
            }
            free(number);
        }
    }
    */
    return ret;
}
//GET
edk::uint32 edk::Object2D::ActionMeshName::getId(){
    return this->id;
}
bool edk::Object2D::ActionMeshName::getLoop(){
    return this->loop;
}
edk::Object2D::ActionMeshStop::ActionMeshStop(edk::Object2D* /*object*/,edk::uint32 /*id*/){
    /*
    this->object=object;
    this->id = id;
    this->code = 8u;
    */
}
//run action function
void edk::Object2D::ActionMeshStop::runAction(){
    /*
    //load the mesh
    edk::shape::Mesh2D* mesh = this->object->getMesh(this->id);
    if(mesh){
        mesh->selectedAnimationStop();
    }
    */
}
//write to XML
bool edk::Object2D::ActionMeshStop::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;
    /*
    if(edk::ActionZero::writeToXML(xml,id)){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //write the ID
                    xml->addSelectedNextAttribute("id",this->id);

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                free(name);
            }
            free(number);
        }
    }
    */
    return ret;
}
//read XML
bool edk::Object2D::ActionMeshStop::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
    bool ret=false;
    /*
    if(xml){
        edk::char8* number = edk::String::uint32ToStr(id);
        if(number){
            edk::char8* name = edk::String::strCat("Action_",number);
            if(name){
                //create the Action
                if(xml->selectChild(name)){
                    //read the id
                    this->id = edk::String::strToInt64(xml->getSelectedAttributeValueByName("id"));

                    ret=true;
                    //then select the father
                    xml->selectFather();
                }
                free(name);
            }
            free(number);
        }
    }
    */
    return ret;
}
//GET
edk::uint32 edk::Object2D::ActionMeshStop::getId(){
    return this->id;
}

//create a new mesh and add to the meshs stack
edk::shape::Mesh2D* edk::Object2D::newMesh(edk::uint32* position){
    return this->meshes.pushNewMesh(position);
}

//clean the obect
void edk::Object2D::clean(){
    //
    this->cleanConnectedObjects();
    this->cleanSelected();
    this->cleanMeshes();
    this->pivo = 0.f;
    this->animationPosition.cleanTracks();
    this->animationRotation.cleanAnimationNameSelected();
    this->animationRotation.cleanAnimationNames();
    this->animationRotation.cleanAnimations();
    this->animationSize.cleanAnimationNameSelected();
    this->animationSize.cleanAnimationNames();
    this->animationSize.cleanAnimations();

    this->position = 0.f;
    this->angle = 0.f;
    this->size = 0.f;

    /*
    this->removeAllActions();
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
        edk::uint32 ret = 0u;
        //then add the mesh to the list
        ret = this->meshes.pushBackMesh(mesh,false);
        if(ret<this->meshes.size()){
            //test if select the first
            if(this->meshes.size()==1u){
                this->selectMesh(0u);
            }
            return ret;
        }
    }

    //else return falses
    return 0u;
}
//remove a polygonlist
bool edk::Object2D::removeMesh(edk::uint32 position){
    //remove the mesh
    return this->meshes.removeMesh(position);
}
//remove all meshes
void edk::Object2D::cleanMeshes(){
    this->cleanSelected();
    this->meshes.removeAllMeshes();
}

//set the drawStart function to set the textures in the shader
bool edk::Object2D::setShaderPointer(edk::material::ShaderFunctionToMaterial* shader){
    if(shader){
        edk::uint32 size = this->meshes.size();
        edk::shape::Mesh2D* temp;
        if(size){
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->meshes.getMesh(i);
                if(temp){
                    temp->material.setShaderPointer(shader);
                }
            }
            return true;
        }
    }
    return false;
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

edk::vec2f32 edk::Object2D::getConnectedWorldPosition(){
    edk::vec2f32 ret;
    //multiply the matrix by
    this->matrixTransform.setIdentity();
    if(this->father){
        //calculate the boundingBox from the father
        this->father->loadFatherMatrix(&this->matrixTransform);

        edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);
        edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->matrixAngle);
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);

        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        if(this->fixedRotation){
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
        }
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);

        //transform all the vertices
        if(this->matrixPosition.haveMatrix()){
            //transform the point
            //
            this->matrixPosition.set(0u,0u,0.f);
            this->matrixPosition.set(0u,1u,0.f);
            this->matrixPosition.set(0u,2u,1.f);

            //multiply the matrix
            this->matrixPosition.multiplyMatrixWithThis(&this->matrixTransform);

            ret.x = this->matrixPosition.getNoIF(0u,0u);
            ret.y = this->matrixPosition.getNoIF(0u,1u);
        }
    }
    else{
        ret = this->position;
    }
    return ret;
}
edk::Object2DValues edk::Object2D::getConnectedWorldValues(){
    edk::Object2DValues ret;
    //multiply the matrix by
    this->matrixTransform.setIdentity();
    if(this->father){
        //calculate the boundingBox from the father
        this->father->loadFatherMatrix(&this->matrixTransform);

        edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);
        edk::Math::generateRotateMatrixZ(this->connectedAngle,&this->matrixAngle);
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->savePosition,&this->matrixPosition);
        edk::Math::generateScaleMatrix(this->saveSize,&this->matrixSize);
        edk::Math::generateRotateMatrix2DZ(this->saveAngle,&this->matrixAngle);
        edk::Math::generateTranslateMatrix(this->savePivo*-1.0f,&this->matrixPivo);

        edk::vector::Matrixf32<3u,3u> matrixTransformTEMP;
        matrixTransformTEMP.cloneFrom(&this->matrixTransform);
/*
        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        if(this->fixedRotation){
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
        }
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);
*/
        //transform all the vertices
        if(this->matrixPosition.haveMatrix()){
            matrixTransformTEMP.cloneFrom(&this->matrixTransform);
            //translate
            matrixTransformTEMP.multiplyThisWithMatrix(&this->matrixPosition);
            ////angle
            //if(!this->fixedRotation){
            //    edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
            //    matrixTransformTEMP.multiplyThisWithMatrix(&this->matrixAngle);
            //}
            ////scale
            //matrixTransformTEMP.multiplyThisWithMatrix(&this->matrixSize);
            //Pivo
            matrixTransformTEMP.multiplyThisWithMatrix(&this->matrixPivo);


            //transform the point
            this->matrixPosition.setIdentity();
            this->matrixPosition.set(0u,0u,0.f);
            this->matrixPosition.set(0u,1u,0.f);
            this->matrixPosition.set(0u,2u,1.f);

            //multiply the matrix
            this->matrixPosition.multiplyMatrixWithThis(&matrixTransformTEMP);

            ret.position.x = this->matrixPosition.getNoIF(0u,0u);
            ret.position.y = this->matrixPosition.getNoIF(0u,1u);

            edk::vec2f32 vecAngle = edk::Math::rotate(1.f,0.f,this->saveAngle);

            //angle
            this->matrixPosition.setIdentity();
            this->matrixPosition.set(0u,0u,vecAngle.x);
            this->matrixPosition.set(0u,1u,vecAngle.y);
            this->matrixPosition.set(0u,2u,1.f);

            //multiply the matrix
            this->matrixPosition.multiplyMatrixWithThis(&matrixTransformTEMP);

            ret.angle = edk::Math::getAngle(this->matrixPosition.getNoIF(0u,0u),
                                            this->matrixPosition.getNoIF(0u,1u)
                                            );

            //size
            //matrixTransformTEMP.cloneFrom(&this->matrixTransform);
            //////translate
            ////matrixTransformTEMP.multiplyThisWithMatrix(&this->matrixPosition);
            ////scale
            //matrixTransformTEMP.multiplyThisWithMatrix(&this->matrixSize);
            ////Pivo
            //matrixTransformTEMP.multiplyThisWithMatrix(&this->matrixPivo);

            //transform the point
            this->matrixPosition.setIdentity();
            this->matrixPosition.set(0u,0u,this->saveSize.width);
            this->matrixPosition.set(0u,1u,this->saveSize.height);
            this->matrixPosition.set(0u,2u,1.f);

            //multiply the matrix
            this->matrixPosition.multiplyMatrixWithThis(&matrixTransformTEMP);

            ret.size.width  = this->matrixPosition.getNoIF(0u,0u) - ret.position.x;
            ret.size.height = this->matrixPosition.getNoIF(0u,1u) - ret.position.y;
        }
    }
    else{
        ret.cloneValuesFrom(this);
    }
    return ret;
}

//return a copy of the boundingBox
edk::rectf32 edk::Object2D::getBoundingBox(){
    return this->boundingBox;
}

//Select the polygonList
bool edk::Object2D::selectMesh(edk::uint32 position){
    //free the selected
    this->cleanSelected();
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
        return this->selected->material.getTexture(number);
    }
    //else return false
    return 0u;
}
//free the selected
void edk::Object2D::cleanSelected(){
    //
    this->selected=NULL;
}
//return the number of meshs
edk::uint32 edk::Object2D::getMeshSize(){
    return this->meshes.size();
}
//return the mesh pointer
edk::shape::Mesh2D* edk::Object2D::getMesh(edk::uint32 position){
    return this->meshes.getMesh(position);
}
//remove all meshes
void edk::Object2D::removeAllMesh(){
    this->cleanMeshes();
}
//set the polygonsColor
bool edk::Object2D::setPolygonColor(edk::uint32 position,edk::color4f32 color){
    if(this->meshes.getMesh(position)){
        this->meshes.getMesh(position)->setPolygonsColor(color);
    }
    return false;
}
bool edk::Object2D::setPolygonColor(edk::uint32 position,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setPolygonColor(position,edk::color4f32(r,g,b,a));
}

void edk::Object2D::setPolygonsColor(edk::color4f32 color){
    edk::uint32 size = this->meshes.size();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColor(color);
        }
    }
}
void edk::Object2D::setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setPolygonsColor(edk::color4f32(r,g,b,a));
}
void edk::Object2D::setPolygonsColorR(edk::float32 r){
    edk::uint32 size = this->meshes.size();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColorR(r);
        }
    }
}
void edk::Object2D::setPolygonsColorG(edk::float32 g){
    edk::uint32 size = this->meshes.size();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColorG(g);
        }
    }
}
void edk::Object2D::setPolygonsColorB(edk::float32 b){
    edk::uint32 size = this->meshes.size();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColorB(b);
        }
    }
}
void edk::Object2D::setPolygonsColorA(edk::float32 a){
    edk::uint32 size = this->meshes.size();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColorA(a);
        }
    }
}

//get world polygon
bool edk::Object2D::getWorldPolygon(edk::shape::Polygon2D* dest,edk::uint32 meshPosition,edk::uint32 polygonPosition){
    bool ret=false;
    if(dest){
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
        //multiply the matrix by

        this->matrixTransform.setIdentity();

        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        if(this->fixedRotation){
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
        }
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);

        edk::shape::Mesh2D* mesh = this->meshes.getMesh(meshPosition);
        if(mesh){
            ret = mesh->getWorldPolygon(dest,polygonPosition,&this->matrixTransform);
        }
    }
    return ret;
}
bool edk::Object2D::getWorldPolygon(edk::shape::Polygon2D* dest,edk::uint32 meshPosition,edk::uint32 polygonPosition,edk::vector::Matrixf32<3u,3u>* transformMat){
    bool ret=false;
    if(dest){
        //first copy the matrix
        if(this->matrixTransform.cloneFrom(transformMat)){
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);

            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
            //angle
            if(this->fixedRotation){
                edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
                this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
            }
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);

            edk::shape::Mesh2D* mesh;
            mesh = this->meshes.getMesh(meshPosition);
            if(mesh){
                ret = mesh->getWorldPolygon(dest,polygonPosition,&this->matrixTransform);
            }
        }
    }
    return ret;
}

//LIGHT
//EDK_LIGHT_LIMIT
bool edk::Object2D::setLight(edk::uint32 position,edk::light::Light light){
    if(position<EDK_LIGHT_LIMIT){
        this->lights[position] = light;
        return true;
    }
    return false;
}
bool edk::Object2D::cleanLight(edk::uint32 position){
    if(position<EDK_LIGHT_LIMIT){
        //
        this->lights[position].clean();
        return true;
    }
    return false;
}
bool edk::Object2D::lightOn(edk::uint32 position){
    if(position<EDK_LIGHT_LIMIT){
        //add the light on the tree
        this->lights[position].on=true;
        return true;
    }
    return false;
}
bool edk::Object2D::lightOff(edk::uint32 position){
    if(position<EDK_LIGHT_LIMIT){
        //remove the position from the tree
        this->lights[position].on=false;
        return true;
    }
    return false;
}

//HIDE
bool edk::Object2D::hide(){
    if(!this->hided){
        //
        this->functionDrawBoundingBox = &edk::Object2D::drawHideBoundingBox;
        this->functionDraw = &edk::Object2D::drawHide;
        this->functionDrawOneTexture = &edk::Object2D::drawHideOneTexture;
        this->functionDrawOneTextureWithLight = &edk::Object2D::drawHideOneTextureWithLight;
        this->functionDrawWithoutMaterial = &edk::Object2D::drawHideWithoutMaterial;
        this->functionDrawWithoutMaterialWithLight = &edk::Object2D::drawHideWithoutMaterialWithLight;
        this->functionDrawWire = &edk::Object2D::drawHideWire;
        this->functionDrawWirePolygon = &edk::Object2D::drawHideWirePolygon;
        this->functionDrawMesh = &edk::Object2D::drawHideMesh;
        this->functionDrawPolygon = &edk::Object2D::drawHidePolygon;
        this->functionDrawMeshOneTexture = &edk::Object2D::drawHideMeshOneTexture;
        this->functionDrawPolygonOneTexture = &edk::Object2D::drawHidePolygonOneTexture;
        this->functionDrawMeshOneTextureWithLight = &edk::Object2D::drawHideMeshOneTextureWithLight;
        this->functionDrawPolygonOneTextureWithLight = &edk::Object2D::drawHidePolygonOneTextureWithLight;
        this->functionDrawMeshWithoutMaterial = &edk::Object2D::drawHideMeshWithoutMaterial;
        this->functionDrawPolygonWithoutMaterial = &edk::Object2D::drawHidePolygonWithoutMaterial;
        this->functionDrawMeshWithoutMaterialWithLight = &edk::Object2D::drawHideMeshWithoutMaterialWithLight;
        this->functionDrawPolygonWithoutMaterialWithLight = &edk::Object2D::drawHidePolygonWithoutMaterialWithLight;
        this->functionDrawMeshWire = &edk::Object2D::drawHideMeshWire;
        this->functionDrawPolygonWire = &edk::Object2D::drawHidePolygonWire;

        this->hided=true;

        return true;
    }
    return false;
}
//UNHIDE
bool edk::Object2D::unhide(){
    if(this->hided){
        //
        this->functionDrawBoundingBox = &edk::Object2D::drawUnhideBoundingBox;
        this->functionDraw = &edk::Object2D::drawUnhide;
        this->functionDrawOneTexture = &edk::Object2D::drawUnhideOneTexture;
        this->functionDrawOneTextureWithLight = &edk::Object2D::drawUnhideOneTextureWithLight;
        this->functionDrawWithoutMaterial = &edk::Object2D::drawUnhideWithoutMaterial;
        this->functionDrawWithoutMaterialWithLight = &edk::Object2D::drawUnhideWithoutMaterialWithLight;
        this->functionDrawWire = &edk::Object2D::drawUnhideWire;
        this->functionDrawWirePolygon = &edk::Object2D::drawUnhideWirePolygon;
        this->functionDrawMesh = &edk::Object2D::drawUnhideMesh;
        this->functionDrawPolygon = &edk::Object2D::drawUnhidePolygon;
        this->functionDrawMeshOneTexture = &edk::Object2D::drawUnhideMeshOneTexture;
        this->functionDrawPolygonOneTexture = &edk::Object2D::drawUnhidePolygonOneTexture;
        this->functionDrawMeshOneTextureWithLight = &edk::Object2D::drawUnhideMeshOneTextureWithLight;
        this->functionDrawPolygonOneTextureWithLight = &edk::Object2D::drawUnhidePolygonOneTextureWithLight;
        this->functionDrawMeshWithoutMaterial = &edk::Object2D::drawUnhideMeshWithoutMaterial;
        this->functionDrawPolygonWithoutMaterial = &edk::Object2D::drawUnhidePolygonWithoutMaterial;
        this->functionDrawMeshWithoutMaterialWithLight = &edk::Object2D::drawUnhideMeshWithoutMaterialWithLight;
        this->functionDrawPolygonWithoutMaterialWithLight = &edk::Object2D::drawUnhidePolygonWithoutMaterialWithLight;
        this->functionDrawMeshWire = &edk::Object2D::drawUnhideMeshWire;
        this->functionDrawPolygonWire = &edk::Object2D::drawUnhidePolygonWire;

        this->hided=false;

        return true;
    }
    return false;
}

bool edk::Object2D::getHided(){
    return this->hided;
}
bool edk::Object2D::isHided(){
    return this->hided;
}
bool edk::Object2D::areHided(){
    return this->hided;
}
bool edk::Object2D::isUnhided(){
    return !this->hided;
}
bool edk::Object2D::areUnhided(){
    return !this->hided;
}

//play all mesh animations
void edk::Object2D::playMeshAnimations(){
    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh2D* mesh;
    for(edk::uint32 i=0u;i<size;i++){
        mesh = this->meshes.getMesh(i);
        if(mesh){
            edk::uint32 polySize = mesh->getPolygonSize();
            for(edk::uint32 j=0u;j<polySize;j++){
                mesh->selectAnimationFramesFromPolygon(j);
                mesh->selectedAnimationPlayForward();
            }
        }
    }
}
bool edk::Object2D::playMeshAnimations(edk::uchar32 position){
    edk::shape::Mesh2D* mesh = this->meshes.getMesh(position);
    if(mesh){
        edk::uint32 polySize = mesh->getPolygonSize();
        for(edk::uint32 j=0u;j<polySize;j++){
            mesh->selectAnimationFramesFromPolygon(j);
            mesh->selectedAnimationPlayForward();
        }
        return true;
    }
    return false;
}
//pause polygons animations
void edk::Object2D::pauseMeshAnimations(){
    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh2D* mesh;
    for(edk::uint32 i=0u;i<size;i++){
        mesh = this->meshes.getMesh(i);
        if(mesh){
            edk::uint32 polySize = mesh->getPolygonSize();
            for(edk::uint32 j=0u;j<polySize;j++){
                mesh->selectAnimationFramesFromPolygon(j);
                mesh->selectedAnimationPause();
            }
        }
    }
}
bool edk::Object2D::pauseMeshAnimations(edk::uchar32 position){
    edk::shape::Mesh2D* mesh = this->meshes.getMesh(position);
    if(mesh){
        edk::uint32 polySize = mesh->getPolygonSize();
        for(edk::uint32 j=0u;j<polySize;j++){
            mesh->selectAnimationFramesFromPolygon(j);
            mesh->selectedAnimationPause();
        }
        return true;
    }
    return false;
}
//update mesh animations
void edk::Object2D::updateMeshAnimations(){
    //update mesh animations
    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh2D *mesh;
    for(edk::uint32 i=0u;i<size;i++){
        mesh = this->meshes.getMesh(i);
        if(mesh){
            mesh->updateFramesAnimations();
        }
    }
}
void edk::Object2D::updateMeshAnimations(edk::float32 seconds){
    //update mesh animations
    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh2D *mesh;
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.haveCreateMesh(i)){
            mesh = this->meshes.getMesh(i);
            if(mesh){
                mesh->updateFramesAnimations(seconds);
            }
        }
    }
}
bool edk::Object2D::updateMeshAnimationsFromPosition(edk::uchar32 position){
    edk::shape::Mesh2D* mesh = this->meshes.getMesh(position);
    if(mesh){
        edk::uint32 polySize = mesh->getPolygonSize();
        for(edk::uint32 j=0u;j<polySize;j++){
            mesh->selectAnimationFramesFromPolygon(j);
            mesh->updateFramesAnimations();
        }
        return true;
    }
    return false;
}
bool edk::Object2D::updateMeshAnimationsFromPosition(edk::uchar32 position,edk::float32 seconds){
    edk::shape::Mesh2D* mesh = this->meshes.getMesh(position);
    if(mesh){
        edk::uint32 polySize = mesh->getPolygonSize();
        for(edk::uint32 j=0u;j<polySize;j++){
            mesh->selectAnimationFramesFromPolygon(j);
            mesh->updateFramesAnimations(seconds);
        }
        return true;
    }
    return false;
}

//update all animations
bool edk::Object2D::updateAnimations(){
    bool ret=edk::Object2DValues::updateAnimations();
    this->updateMeshAnimations();
    this->updateChildremsAnimations();
    return ret;
}
bool edk::Object2D::updateAnimations(edk::float32 seconds){
    bool ret=edk::Object2DValues::updateAnimations(seconds);
    this->updateMeshAnimations(seconds);
    this->updateChildremsAnimations(seconds);
    return ret;
}

bool edk::Object2D::updateSizeFromTexture(edk::uint32 meshPosition,edk::uint32 textPosition,edk::float32 multiply){
    edk::shape::Mesh2D* mesh = this->getMesh(meshPosition);
    if(mesh){
        if(mesh->material.haveTexture(textPosition)){
            this->size.width = mesh->material.getTextureWidth(textPosition) * multiply;
            this->size.height = mesh->material.getTextureHeight(textPosition) * multiply;
            return true;
        }
    }
    return false;
}

//ACTIONS
//play actions
void edk::Object2D::playForwardActions(){
    /*
    this->actions.playForward();
    */
}
void edk::Object2D::playForwardInActions(edk::float32 /*second*/){
    /*
    this->actions.playForwardIn(second);
    */
}
void edk::Object2D::pauseActions(){
    /*
    this->actions.pause();
    */
}
void edk::Object2D::stopActions(){
    /*
    this->actions.stop();
    */
}
//set loop
void edk::Object2D::setLoopActions(bool /*loop*/){
    /*
    this->actions.setLoop(loop);
    */
}
void edk::Object2D::loopOnActions(){
    /*
    this->actions.loopOn();
    */
}
void edk::Object2D::loopOffActions(){
    /*
    this->actions.loopOff();
    */
}

//return if are playing
bool edk::Object2D::isPlayingActions(){
    /*
    return this->actions.isPlaying();
    */
    return false;
}
bool edk::Object2D::isPausedActions(){
    /*
    return this->actions.isPaused();
    */
    return false;
}
//update actions
void edk::Object2D::updateActions(){
    /*
    this->actions.update();
    */
}
//remove actions
void edk::Object2D::removeAllActions(){
    /*
    this->actions.clean();
    */
}
void edk::Object2D::cleanAllActions(){
    /*
    this->actions.clean();
    */
}
bool edk::Object2D::removeActionSecond(edk::float32 /*second*/){
    /*
    return this->actions.removeSecond(second);
    */
    return false;
}
//Add zero action
bool edk::Object2D::actionZero(edk::float32 /*second*/){
    /*
    return this->actions.addAction(second,new edk::ActionZero);
    */
    return false;
}
//add move action
bool edk::Object2D::actionSetPosition(edk::float32 /*second*/,edk::vec2f32 /*position*/){
    /*
    return this->actions.addAction(second,new edk::Object2D::ActionPosition(this,position));
    */
    return false;
}
bool edk::Object2D::actionSetPosition(edk::float32 /*second*/,edk::float32 /*x*/,edk::float32 /*y*/){
    /*
    return this->actionSetPosition(second,edk::vec2f32(x,y));
    */
    return false;
}
//add move action
bool edk::Object2D::actionMove(edk::float32 /*second*/,edk::float32 /*duration*/, edk::vec2f32 /*position*/){
    /*
    //create the action
    if(this->actions.addAction(second,new edk::Object2D::ActionMove(this,duration,position))){
        this->actions.addZeroAction(second+duration);
        return true;
    }
    */
    return false;
}
bool edk::Object2D::actionMove(edk::float32 /*second*/,edk::float32 /*duration*/, edk::float32 /*x*/,edk::float32 /*y*/){
    /*
    return this->actionMove(second,duration, edk::vec2f32(x,y));
    */
    return false;
}
bool edk::Object2D::actionMoveTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::vec2f32 /*position*/){
    /*
    return this->actionMove(start,end-start, position);
    */
    return false;
}
bool edk::Object2D::actionMoveTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::float32 /*x*/,edk::float32 /*y*/){
    /*
    return this->actionMove(start,end-start,x,y);
    */
    return false;
}
//add scale action
bool edk::Object2D::actionSetSize(edk::float32 /*second*/,edk::size2f32 /*size*/){
    /*
    //create the action
    return this->actions.addAction(second,new edk::Object2D::ActionSetSize(this,size));
    */
    return false;
}
bool edk::Object2D::actionSetSize(edk::float32 /*second*/,edk::float32 /*width*/,edk::float32 /*height*/){
    /*
    return this->actionSetSize(second,edk::size2f32(width,height));
    */
    return false;
}
bool edk::Object2D::actionSetSize(edk::float32 /*second*/,edk::float32 /*size*/){
    /*
    return this->actionSetSize(second,size,size);
    */
    return false;
}
//add scale action
bool edk::Object2D::actionScale(edk::float32 /*second*/,edk::float32 /*duration*/, edk::size2f32 /*size*/){
    /*
    //create the action
    if(this->actions.addAction(second,new edk::Object2D::ActionSize(this,duration,size))){
        this->actions.addZeroAction(second+duration);
        return true;
    }
    */
    return false;
}
bool edk::Object2D::actionScale(edk::float32 /*second*/,edk::float32 /*duration*/, edk::float32 /*width*/,edk::float32 /*height*/){
    /*
    return this->actionScale(second,duration, edk::size2f32( width,height));
    */
    return false;
}
bool edk::Object2D::actionScale(edk::float32 /*second*/,edk::float32 /*duration*/, edk::float32 /*size*/){
    /*
    return this->actionScale(second,duration, size,size);
    */
    return false;
}
bool edk::Object2D::actionScaleTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::size2f32 /*size*/){
    /*
    return this->actionScale(start,end-start, size);
    */
    return false;
}
bool edk::Object2D::actionScaleTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::float32 /*width*/,edk::float32 /*height*/){
    /*
    return this->actionScale(start,end-start, width,height);
    */
    return false;
}
bool edk::Object2D::actionScaleTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::float32 /*size*/){
    /*
    return this->actionScale(start,end-start, size);
    */
    return false;
}
//add angle action
bool edk::Object2D::actionSetAngle(edk::float32 /*second*/,edk::float32 /*angle*/){
    /*
    return this->actions.addAction(second,new edk::Object2D::ActionSetAngle(this,angle));
    */
    return false;
}
//add angle action
bool edk::Object2D::actionRotateFor(edk::float32 /*second*/,edk::float32 /*duration*/, edk::float32 /*angle*/){
    /*
    if(this->actions.addAction(second,new edk::Object2D::ActionAngle(this,duration,angle))){
        this->actions.addZeroAction(second);
        return true;
    }
    */
    return false;
}
bool edk::Object2D::actionRotateTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::float32 /*angle*/){
    /*
    return this->actionRotateFor(start,end-start, angle);
    */
    return false;
}
//MESH SPRITE SHEET
bool edk::Object2D::actionPlayName(edk::float32 /*second*/,edk::uint32 /*id*/,edk::char8* /*name*/,bool /*loop*/){
    //
    /*
    return this->actions.addAction(second,new edk::Object2D::ActionMeshName(this,id,name,loop));
    */
    return false;
}
bool edk::Object2D::actionPlayName(edk::float32 /*second*/,edk::uint32 /*id*/,const edk::char8* /*name*/,bool /*loop*/){
    //
    /*
    return actionPlayName(second,id,(edk::char8*)name,loop);
    */
    return false;
}
bool edk::Object2D::actionPlayNameFor(edk::float32 /*second*/,edk::float32 /*duration*/,edk::uint32 /*id*/,edk::char8* /*name*/){
    /*
    if(this->actions.addAction(second,new edk::Object2D::ActionMeshName(this,id,name,true))){
        //add the stop action
        this->actions.addAction(second+duration,new edk::Object2D::ActionMeshStop(this,id));
        return true;
    }
    */
    return false;
}
bool edk::Object2D::actionPlayNameFor(edk::float32 /*second*/,edk::float32 /*duration*/,edk::uint32 /*id*/,const edk::char8* /*name*/){
    /*
    return this->actionPlayNameFor(second,duration,id,(edk::char8*)name);
    */
    return false;
}

//DRAW
//print the mesh
void edk::Object2D::print(){
    edk::Object2DValues::print();

    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh2D* mesh;
    //print all polygonList
    for(edk::uint32 i=0u;i<size;i++){
        //
        mesh = this->meshes.getMesh(i);
        if(mesh){
            //
            printf("\nMESH %u"
                   ,i
                   );fflush(stdout);
            mesh->print();
        }
    }
}
//draw the mesh
void edk::Object2D::drawBoundingBox(){
    //test if have a father
    //if(this->father){
    //    //put the transformation on a stack
    //    edk::GU::guPushMatrix();
    //
    //    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);
    //
    //    edk::GU::guBegin(GU_LINE_LOOP);
    //    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );
    //    edk::GU::guVertex2f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);
    //    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.size.height);
    //    edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.origin.y   );
    //    edk::GU::guEnd();
    //
    //    edk::GU::guPopMatrix();
    //}
    //else{
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);

    this->drawChildremsBackBoundingBox();

    (this->*functionDrawBoundingBox)();

    this->drawChildremsFrontBoundingBox();

    edk::GU::guPopMatrix();
    //}
}
void edk::Object2D::draw(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    bool haveLight=false;
    edk::GU::guEnable(GU_LIGHTING);
    //glEnable(GL_RESCALE_NORMAL);
    {
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);
                this->lights[i].draw(i);
                haveLight=true;

            }
            else{
                edk::GU::guDisable(GU_LIGHT0+i);
            }
        }
    }
    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    this->drawChildremsBack(haveLight);

    (this->*functionDraw)(haveLight);

    this->drawChildremsFront(haveLight);

    //glEnable(GL_RESCALE_NORMAL);
    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
}
void edk::Object2D::drawOneTexture(){
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

    this->drawChildremsBackOneTexture();

    (this->*functionDrawOneTexture)();

    this->drawChildremsFrontOneTexture();

    edk::GU::guPopMatrix();
}
void edk::Object2D::drawOneTextureWithLight(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guEnable(GU_LIGHTING);

    bool haveLight=false;

    {
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);
                this->lights[i].draw(i);
                haveLight=true;

            }
            else{
                edk::GU::guDisable(GU_LIGHT0+i);
            }
        }
    }
    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    this->drawChildremsBackOneTextureWithLight(haveLight);

    (this->*functionDrawOneTextureWithLight)(haveLight);

    this->drawChildremsFrontOneTextureWithLight(haveLight);

    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
}
void edk::Object2D::drawWithoutMaterial(){
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

    this->drawChildremsBackWithoutMaterial();

    (this->*functionDrawWithoutMaterial)();

    this->drawChildremsFrontWithoutMaterial();

    edk::GU::guPopMatrix();
}
void edk::Object2D::drawWithoutMaterialWithLight(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guEnable(GU_LIGHTING);

    bool haveLight=false;

    {
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);
                this->lights[i].draw(i);
                haveLight=true;

            }
            else{
                edk::GU::guDisable(GU_LIGHT0+i);
            }
        }
    }
    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    this->drawChildremsBackWithoutMaterialWithLight(haveLight);

    (this->*functionDrawWithoutMaterialWithLight)(haveLight);

    this->drawChildremsFrontWithoutMaterialWithLight(haveLight);

    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
}
void edk::Object2D::drawWire(){
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

    this->drawChildremsBackWire();

    (this->*functionDrawWire)();

    this->drawChildremsFrontWire();

    edk::GU::guPopMatrix();
}
void edk::Object2D::drawWirePolygon(edk::uint32 meshPosition,edk::uint32 polygon){
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

    (this->*functionDrawWirePolygon)(meshPosition,polygon);

    edk::GU::guPopMatrix();
}
bool edk::Object2D::drawMesh(edk::uint32 meshPosition){
    bool ret=false;
    //put the transformation on a stack
    edk::GU::guPushMatrix();


    edk::GU::guEnable(GU_LIGHTING);
    //glEnable(GL_RESCALE_NORMAL);

    bool haveLight=false;

    {
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);
                this->lights[i].draw(i);
                haveLight=true;

            }
            else{
                edk::GU::guDisable(GU_LIGHT0+i);
            }
        }
    }

    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    ret = (this->*functionDrawMesh)(haveLight,meshPosition);

    //glEnable(GL_RESCALE_NORMAL);
    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object2D::drawPolygon(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;
    //put the transformation on a stack
    edk::GU::guPushMatrix();


    edk::GU::guEnable(GU_LIGHTING);
    //glEnable(GL_RESCALE_NORMAL);

    bool haveLight=false;

    {
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);
                this->lights[i].draw(i);
                haveLight=true;

            }
            else{
                edk::GU::guDisable(GU_LIGHT0+i);
            }
        }
    }

    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    ret = (this->*functionDrawPolygon)(haveLight,meshPosition,polygon);

    //glEnable(GL_RESCALE_NORMAL);
    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object2D::drawMeshOneTexture(edk::uint32 meshPosition){
    bool ret = false;
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

    ret = (this->*functionDrawMeshOneTexture)(meshPosition);

    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object2D::drawPolygonOneTexture(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret = false;
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

    ret = (this->*functionDrawPolygonOneTexture)(meshPosition,polygon);

    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object2D::drawMeshOneTextureWithLight(edk::uint32 meshPosition){
    bool ret = false;
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guEnable(GU_LIGHTING);

    bool haveLight=false;

    {
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);
                this->lights[i].draw(i);
                haveLight=true;

            }
            else{
                edk::GU::guDisable(GU_LIGHT0+i);
            }
        }
    }
    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    ret = (this->*functionDrawMeshOneTextureWithLight)(haveLight,meshPosition);

    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object2D::drawPolygonOneTextureWithLight(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret = false;
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guEnable(GU_LIGHTING);

    bool haveLight=false;

    {
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);
                this->lights[i].draw(i);
                haveLight=true;

            }
            else{
                edk::GU::guDisable(GU_LIGHT0+i);
            }
        }
    }
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    ret = (this->*functionDrawPolygonOneTextureWithLight)(haveLight,meshPosition,polygon);

    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object2D::drawMeshWithoutMaterial(edk::uint32 meshPosition){
    bool ret = false;
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

    ret = (this->*functionDrawMeshWithoutMaterial)(meshPosition);

    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object2D::drawPolygonWithoutMaterial(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret = false;
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

    ret = (this->*functionDrawPolygonWithoutMaterial)(meshPosition,polygon);

    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object2D::drawMeshWithoutMaterialWithLight(edk::uint32 meshPosition){
    bool ret = false;
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guEnable(GU_LIGHTING);

    bool haveLight=false;

    {
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);
                this->lights[i].draw(i);
                haveLight=true;

            }
            else{
                edk::GU::guDisable(GU_LIGHT0+i);
            }
        }
    }
    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    ret = (this->*functionDrawMeshWithoutMaterialWithLight)(haveLight,meshPosition);

    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object2D::drawPolygonWithoutMaterialWithLight(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret = false;
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guEnable(GU_LIGHTING);

    bool haveLight=false;

    {
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);
                this->lights[i].draw(i);
                haveLight=true;

            }
            else{
                edk::GU::guDisable(GU_LIGHT0+i);
            }
        }
    }
    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    ret = (this->*functionDrawPolygonWithoutMaterialWithLight)(haveLight,meshPosition,polygon);

    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object2D::drawMeshWire(edk::uint32 meshPosition){
    bool ret=false;
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

    ret = (this->*functionDrawMeshWire)(meshPosition);

    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object2D::drawPolygonWire(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;
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

    ret = (this->*functionDrawPolygonWire)(meshPosition,polygon);

    edk::GU::guPopMatrix();
    return ret;
}

//draw the pivo
void edk::Object2D::drawPivo(edk::float32 size,edk::color3f32 color){
    if(this->childremsBack.size()){
        edk::GU::guPushMatrix();
        //add translate
        edk::GU::guTranslate2f32(this->position);
        //add rotation
        edk::GU::guRotateZf32(this->angle);
        //add scale
        edk::GU::guScale2f32(this->size);
        //set the pivo
        edk::GU::guTranslate2f32(this->pivo*-1.0f);
        this->drawChildremsBackPivo(size,color);
        edk::GU::guPopMatrix();
    }
    edk::Object2D::drawPivoInPosition(this->position,size,color);
    if(this->childremsFront.size()){
        edk::GU::guPushMatrix();
        //add translate
        edk::GU::guTranslate2f32(this->position);
        //add rotation
        edk::GU::guRotateZf32(this->angle);
        //add scale
        edk::GU::guScale2f32(this->size);
        //set the pivo
        edk::GU::guTranslate2f32(this->pivo*-1.0f);
        this->drawChildremsFrontPivo(size,color);
        edk::GU::guPopMatrix();
    }
}
void edk::Object2D::drawPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);
    if(this->childremsBack.size()){
        this->drawChildremsBackPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();


    edk::GU::guPushMatrix();
    //add translate
    //edk::GU::guTranslate2f32(this->position);

    edk::Object2D::drawPivoInPosition(this->position,size,edk::color3f32(r,g,b));

    edk::GU::guPopMatrix();

    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);
    if(this->childremsFront.size()){
        this->drawChildremsFrontPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();
}
void edk::Object2D::drawPivoInPosition(edk::vec2f32 position,edk::float32 size,edk::color3f32 color){
    //
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate2f32(position);
    //add scale
    edk::GU::guScale2f32(edk::size2f32(size,size));

    //lineSize
    edk::GU::guLineWidth(3);

    //set the colors
    edk::GU::guColor3f32(color);
    //draw the lines
    edk::GU::guBegin(GU_LINES);
    //LINE 1
    edk::GU::guVertex2f32(-0.5f,-0.5f);
    edk::GU::guVertex2f32( 0.5f, 0.5f);
    //LINE 2
    edk::GU::guVertex2f32(-0.5f, 0.5f);
    edk::GU::guVertex2f32( 0.5f,-0.5f);
    edk::GU::guEnd();

    //lineSize
    edk::GU::guLineWidth(1);

    //
    edk::GU::guPopMatrix();
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
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"object_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //WRITE
                        //write the mesh
                        edk::uint32 size = this->meshes.size();
                        edk::shape::Mesh2D* mesh;
                        for(edk::uint32 i=0u;i<size;i++){
                            mesh = this->meshes.getMesh(i);
                            if(mesh){
                                mesh->writeToXML(xml,i);
                            }
                        }

                        //write pivo
                        edk::char8* temp=NULL;
                        temp = edk::String::float32ToStr(this->pivo.x);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"pivoX",temp);
                            free(temp);
                        }
                        temp = edk::String::float32ToStr(this->pivo.y);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"pivoY",temp);
                            free(temp);
                        }

                        //write objectValues
                        //position
                        temp = edk::String::float32ToStr(this->position.x);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"positionX",temp);
                            free(temp);
                        }
                        temp = edk::String::float32ToStr(this->position.y);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"positionY",temp);
                            free(temp);
                        }
                        //size
                        temp = edk::String::float32ToStr(this->size.width);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"sizeW",temp);
                            free(temp);
                        }
                        temp = edk::String::float32ToStr(this->size.height);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"sizeH",temp);
                            free(temp);
                        }
                        //angle
                        temp = edk::String::float32ToStr(this->angle);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"angle",temp);
                            free(temp);
                        }

                        //write animations
                        this->animationPosition.writeToXML(xml,0u);
                        this->animationRotation.writeToXML(xml,1u);
                        this->animationSize.writeToXML(xml,2u);

                        /*
                        //write the actins
                        this->actions.writeToXML(xml,0u);
                        */

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
bool edk::Object2D::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"object_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    this->cleanMeshes();
                    //read mesh
                    edk::shape::Mesh2D* mesh;
                    edk::uint32 count=0u;
                    edk::uint32 position=0u;
                    do{
                        mesh = this->newMesh(&position);
                        if(mesh){
                            if(!mesh->readFromXML(xml,count)){
                                this->removeMesh(position);
                                mesh=NULL;
                            }
                        }
                        count++;
                    }while(mesh);
                    //read pivo
                    this->pivo = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoX")),
                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoY"))
                                              );
                    //read the object values
                    //position
                    this->position = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionX")),
                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionY"))
                                                  );
                    //size
                    this->size = edk::size2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeW")),
                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeH"))
                                               );
                    //angle
                    this->angle = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("angle"));

                    //write animations
                    this->animationPosition.readFromXML(xml,0u);
                    this->animationRotation.readFromXML(xml,1u);
                    this->animationSize.readFromXML(xml,2u);

                    /*
                    //ACTIONS
                    this->actions.readFromXML(xml,0u,this);
                    */

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
bool edk::Object2D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    if(xml && pack){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"object_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    this->cleanMeshes();
                    //read mesh
                    edk::shape::Mesh2D* mesh;
                    edk::uint32 count=0u;
                    edk::uint32 position=0u;
                    do{
                        mesh = this->newMesh(&position);
                        if(mesh){
                            if(!mesh->readFromXMLFromPack(pack,xml,count)){
                                this->removeMesh(position);
                                mesh=NULL;
                            }
                        }
                        count++;
                    }while(mesh);
                    //read pivo
                    this->pivo = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoX")),
                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoY"))
                                              );
                    //read the object values
                    //position
                    this->position = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionX")),
                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionY"))
                                                  );
                    //size
                    this->size = edk::size2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeW")),
                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeH"))
                                               );
                    //angle
                    this->angle = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("angle"));

                    //write animations
                    this->animationPosition.readFromXML(xml,0u);
                    this->animationRotation.readFromXML(xml,1u);
                    this->animationSize.readFromXML(xml,2u);

                    /*
                    //ACTIONS
                    this->actions.readFromXML(xml,0u,this);
                    */

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

//connect another object into this
bool edk::Object2D::isConnected(){
    if(this->father){
        return true;
    }
    return false;
}
bool edk::Object2D::connectObjectBack(edk::Object2D* obj){
    if(obj){
        if(!obj->father){
            edk::uint32 size = this->childremsBack.size();
            this->childremsBack.pushBack(obj);
            if(size<this->childremsBack.size()){
                obj->father=this;

                obj->newSize = edk::size2f32(1.f / this->size.width,1.f / this->size.height);

                obj->savePosition = obj->position;
                obj->saveAngle = obj->angle;
                obj->saveSize = obj->size;

                //translate the object to be connected with the another
                obj->connectedPosition=this->position*-1.f;
                obj->connectedSize= edk::size2f32(1.f/this->size.width,1.f/this->size.height);
                obj->connectedAngle=this->angle*-1.f;

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
                edk::shape::Mesh2D* mesh;

                //update the values
                obj->matrixTransform.setIdentity();
                obj->updateValuesFromFather(&obj->matrixTransform);

                if(obj->meshes.size()){
                    mesh = obj->meshes.getMesh(0u);
                    if(mesh){
                        //calculate the position
                        obj->position = mesh->generateBoundingPoint(edk::vec2f32(0.f,0.f),&obj->matrixTransform);
                        //calculate the angle
                        obj->angle+=edk::Math::getAngle(mesh->generateBoundingPoint(edk::vec2f32(1.f,0.f),&obj->matrixTransform)-obj->position);

                        while(obj->angle<0.f){
                            obj->angle+=360.f;
                        }
                        while(obj->angle>360.f){
                            obj->angle-=360.f;
                        }
                    }
                }
                return true;
            }
        }
    }
    return false;
}
edk::vec2f32 edk::Object2D::getConnectedObjectBackWorldPosition(edk::Object2D* obj){
    edk::vec2f32 ret;
    if(obj){
        if(obj->father == this){
            if(this->childremsBack.haveElement(obj)){
                edk::shape::Mesh2D* mesh;

                //update the values
                obj->matrixTransform.setIdentity();
                obj->updateValuesFromFather(&obj->matrixTransform);

                //transform all the vertices
                if(this->matrixPosition.haveMatrix()){
                    //transform the point
                    //
                    this->matrixPosition.set(0u,0u,0.f);
                    this->matrixPosition.set(0u,1u,0.f);
                    this->matrixPosition.set(0u,2u,1.f);

                    //multiply the matrix
                    this->matrixPosition.multiplyMatrixWithThis(&this->matrixTransform);

                    ret.x = this->matrixPosition.getNoIF(0u,0u);
                    ret.y = this->matrixPosition.getNoIF(0u,1u);
                }

                return ret;

                if(obj->meshes.size()){
                    mesh = obj->meshes.getMesh(0u);
                    if(mesh){
                        //calculate the position
                        ret = mesh->generateBoundingPoint(edk::vec2f32(0.f,0.f),&obj->matrixTransform);
                    }
                }
            }
        }
    }
    return ret;
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
            if(this->childremsBack.bringPositionToEnd(this->childremsBack.getPositionElement(obj))){
                if(this->childremsBack.popBack()){
                    obj->father=NULL;
                    obj->connectedLoadIdentityValues();
                    obj->newSize=1.f;
                    return true;
                }
            }
        }
    }
    return false;
}
void edk::Object2D::disconnectAllObjectsBack(){
    this->cleanConnectedObjectsBack();
}
void edk::Object2D::cleanConnectedObjectsBack(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
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
            edk::uint32 size = this->childremsFront.size();
            this->childremsFront.pushBack(obj);
            if(size < this->childremsFront.size()){
                obj->father=this;

                obj->newSize = edk::size2f32(1.f / this->size.width,1.f / this->size.height);

                obj->savePosition = obj->position;
                obj->saveAngle = obj->angle;
                obj->saveSize = obj->size;

                //translate the object to be connected with the another
                obj->connectedPosition=this->position*-1.f;
                obj->connectedSize= edk::size2f32(1.f/this->size.width,1.f/this->size.height);
                obj->connectedAngle=this->angle*-1.f;

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
                edk::shape::Mesh2D* mesh;

                //update the values
                obj->matrixTransform.setIdentity();
                obj->updateValuesFromFather(&obj->matrixTransform);

                if(obj->meshes.size()){
                    mesh = obj->meshes.getMesh(0u);
                    if(mesh){
                        //calculate the position
                        obj->position = mesh->generateBoundingPoint(edk::vec2f32(0.f,0.f),&obj->matrixTransform);
                        //calculate the angle
                        obj->angle+=edk::Math::getAngle(mesh->generateBoundingPoint(edk::vec2f32(1.f,0.f),&obj->matrixTransform)-obj->position);
                    }
                }
                return true;
            }
        }
    }
    return false;
}
edk::vec2f32 edk::Object2D::getConnectedObjectFrontWorldPosition(edk::Object2D* obj){
    edk::vec2f32 ret;
    if(obj){
        if(obj->father == this){
            if(this->childremsFront.haveElement(obj)){
                edk::shape::Mesh2D* mesh;

                //update the values
                obj->matrixTransform.setIdentity();
                obj->updateValuesFromFather(&obj->matrixTransform);

                if(obj->meshes.size()){
                    mesh = obj->meshes.getMesh(0u);
                    if(mesh){
                        //calculate the position
                        ret = mesh->generateBoundingPoint(edk::vec2f32(0.f,0.f),&obj->matrixTransform);
                    }
                }
            }
        }
    }
    return ret;
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
            if(this->childremsFront.bringPositionToEnd(this->childremsFront.getPositionElement(obj))){
                if(this->childremsFront.popBack()){
                    obj->father=NULL;
                    obj->connectedLoadIdentityValues();
                    obj->newSize=1.f;
                    return true;
                }
            }
        }
    }
    return false;
}
void edk::Object2D::disconnectAllObjectsFront(){
    this->cleanConnectedObjectsFront();
}
void edk::Object2D::cleanConnectedObjectsFront(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object2D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
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
bool edk::Object2D::updateConnectedObjectValues(edk::Object2D* obj){
    if(obj){
        if(obj->father == this){
            if(this->childremsBack.haveElement(obj) || this->childremsFront.haveElement(obj)){
                edk::shape::Mesh2D* mesh;

                //update the values
                obj->matrixTransform.setIdentity();
                obj->updateValuesFromFather(&obj->matrixTransform);

                if(obj->meshes.size()){
                    mesh = obj->meshes.getMesh(0u);
                    if(mesh){
                        //calculate the position
                        obj->position = mesh->generateBoundingPoint(edk::vec2f32(0.f,0.f),&obj->matrixTransform);
                        //calculate the angle
                        obj->angle+=edk::Math::getAngle(mesh->generateBoundingPoint(edk::vec2f32(1.f,0.f),&obj->matrixTransform)-obj->position);
                    }
                }
                return true;
            }
        }
    }
    return false;
}
edk::vec2f32 edk::Object2D::getConnectedObjectWorldPosition(edk::Object2D* obj){
    edk::vec2f32 ret;
    if(obj){
        if(obj->father == this){
            if(this->childremsBack.haveElement(obj)||this->childremsFront.haveElement(obj)){
                edk::shape::Mesh2D* mesh;

                //update the values
                obj->matrixTransform.setIdentity();
                obj->updateValuesFromFather(&obj->matrixTransform);

                if(obj->meshes.size()){
                    mesh = obj->meshes.getMesh(0u);
                    if(mesh){
                        //calculate the position
                        ret = mesh->generateBoundingPoint(edk::vec2f32(0.f,0.f),&obj->matrixTransform);
                    }
                }
            }
        }
    }
    return ret;
}
bool edk::Object2D::haveConnectedObject(edk::Object2D* obj){
    if(obj){
        if(obj->father == this){
            if(this->childremsBack.haveElement(obj)||this->childremsFront.haveElement(obj)){
                return true;
            }
        }
    }
    return false;
}
bool edk::Object2D::disconnectObject(edk::Object2D* obj){
    return (this->disconnectObjectBack(obj) || this->disconnectObjectFront(obj));
}
void edk::Object2D::updateAllConnectedObjectValues(){
    edk::uint32 size = 0u;
    edk::Object2D* obj;
    edk::shape::Mesh2D* mesh;
    size = this->childremsBack.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        if(obj){
            //update the values
            obj->matrixTransform.setIdentity();
            obj->updateValuesFromFather(&obj->matrixTransform);

            if(obj->meshes.size()){
                mesh = obj->meshes.getMesh(0u);
                if(mesh){
                    //calculate the position
                    obj->position = mesh->generateBoundingPoint(edk::vec2f32(0.f,0.f),&obj->matrixTransform);
                    //calculate the angle
                    obj->angle+=edk::Math::getAngle(mesh->generateBoundingPoint(edk::vec2f32(1.f,0.f),&obj->matrixTransform)-obj->position);
                }
            }
            //update connected values
            obj->connectedLoadIdentityValues();
            obj->newSize = edk::size2f32(1.f / this->size.width,1.f / this->size.height);
            //translate the object to be connected with the another
            obj->connectedPosition=this->position*-1.f;
            obj->connectedSize= edk::size2f32(1.f/this->size.width,1.f/this->size.height);
            obj->connectedAngle=this->angle*-1.f;
        }
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        if(obj){
            //update the values
            obj->matrixTransform.setIdentity();
            obj->updateValuesFromFather(&obj->matrixTransform);

            if(obj->meshes.size()){
                mesh = obj->meshes.getMesh(0u);
                if(mesh){
                    //calculate the position
                    obj->position = mesh->generateBoundingPoint(edk::vec2f32(0.f,0.f),&obj->matrixTransform);
                    //calculate the angle
                    obj->angle+=edk::Math::getAngle(mesh->generateBoundingPoint(edk::vec2f32(1.f,0.f),&obj->matrixTransform)-obj->position);
                }
            }
            //update connected values
            obj->connectedLoadIdentityValues();
            obj->newSize = edk::size2f32(1.f / this->size.width,1.f / this->size.height);
            //translate the object to be connected with the another
            obj->connectedPosition=this->position*-1.f;
            obj->connectedSize= edk::size2f32(1.f/this->size.width,1.f/this->size.height);
            obj->connectedAngle=this->angle*-1.f;
        }
    }
}
void edk::Object2D::disconnectAllObjects(){
    this->disconnectAllObjectsBack();this->disconnectAllObjectsFront();
}
void edk::Object2D::updateAndDisconnectAllObjects(){
    this->updateAllConnectedObjectValues();
    this->disconnectAllObjects();
}
void edk::Object2D::cleanConnectedObjects(){
    this->cleanConnectedObjectsBack();
    this->cleanConnectedObjectsFront();
}

bool edk::Object2D::cloneFrom(edk::Object2D* obj){
    if(obj){
        this->cleanSelected();
        this->cleanMeshes();

        //copy the meshs
        edk::uint32 size = obj->meshes.size();
        edk::shape::Mesh2D* temp = NULL;
        edk::shape::Mesh2D* mesh = NULL;
        for(edk::uint32 i=0u;i<size;i++){
            temp = obj->meshes.getMesh(i);
            if(temp){
                mesh = this->newMesh();
                if(mesh){
                    //*mesh = *temp;
                    mesh->cloneFrom(temp);
                }
            }
        }
        //copy pivo
        this->pivo = obj->pivo;
        //copy the animations
        //this->animationPosition = obj->animationPosition;
        this->animationPosition.cloneFrom(&obj->animationPosition);
        //this->animationRotation = obj->animationRotation;
        this->animationRotation.cloneFrom(&obj->animationRotation);
        //this->animationSize = obj->animationSize;
        this->animationSize.cloneFrom(&obj->animationSize);

        this->position = obj->position;
        this->angle = obj->angle;
        this->size = obj->size;


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
        this->actions.clean();
        size = obj->actions.getKeySize();
        edk::uint32 actionSize = 0u;
        edk::float32 second=0.f;
        edk::uint64 code = 0u;
        for(edk::uint32 i=0u;i<size;i++){
            //load the kay second
            second = obj->actions.getKeySecond(i);
            //load the size of actions inside de key
            actionSize = obj->actions.getActionsSize(i);
            for(edk::uint32 j=0u;j<actionSize;j++){
                //get the action code
                code = obj->actions.getActionCode(i,j);

                switch(code){
                case 1u:
                {
                    //ActionPosition
                    edk::Object2D::ActionPosition* temp = (edk::Object2D::ActionPosition*)obj->actions.getActionInKey(i,j);
                    this->actions.addAction(second,new edk::Object2D::ActionPosition(this,temp->getPosition()));
                    break;
                }
                case 2u:
                {
                    //ActionMove
                    edk::Object2D::ActionMove* temp = (edk::Object2D::ActionMove*)obj->actions.getActionInKey(i,j);
                    this->actions.addAction(second,new edk::Object2D::ActionMove(this,temp->getDuration(),temp->getPosition()));
                    break;
                }
                case 3u:
                {
                    //ActionSetSize
                    edk::Object2D::ActionSetSize* temp = (edk::Object2D::ActionSetSize*)obj->actions.getActionInKey(i,j);
                    this->actions.addAction(second,new edk::Object2D::ActionSetSize(this,temp->getSize()));
                    break;
                }
                case 4u:
                {
                    //ActionSize
                    edk::Object2D::ActionSize* temp = (edk::Object2D::ActionSize*)obj->actions.getActionInKey(i,j);
                    this->actions.addAction(second,new edk::Object2D::ActionSize(this,temp->getDuration(),temp->getSize()));
                    break;
                }
                case 5u:
                {
                    //ActionSetAngle
                    edk::Object2D::ActionSetAngle* temp = (edk::Object2D::ActionSetAngle*)obj->actions.getActionInKey(i,j);
                    this->actions.addAction(second,new edk::Object2D::ActionSetAngle(this,temp->getAngle()));
                    break;
                }
                case 6u:
                {
                    //ActionAngle
                    edk::Object2D::ActionAngle* temp = (edk::Object2D::ActionAngle*)obj->actions.getActionInKey(i,j);
                    this->actions.addAction(second,new edk::Object2D::ActionAngle(this,temp->getDuration(),temp->getAngle()));
                    break;
                }
                case 7u:
                {
                    //ActionMeshName
                    edk::Object2D::ActionMeshName* temp = (edk::Object2D::ActionMeshName*)obj->actions.getActionInKey(i,j);
                    this->actions.addAction(second,new edk::Object2D::ActionMeshName(this,temp->getId(),temp->getName(),temp->getLoop()));
                    break;
                }
                case 8u:
                {
                    //ActionMeshStop
                    edk::Object2D::ActionMeshStop* temp = (edk::Object2D::ActionMeshStop*)obj->actions.getActionInKey(i,j);
                    this->actions.addAction(second,new edk::Object2D::ActionMeshStop(this,temp->getId()));
                    break;
                }
                default:
                {
                    //actionZero
                    this->actions.addAction(second,new edk::ActionZero());
                }
                }
            }
        }
        */
        return true;
    }
    return false;
}
bool edk::Object2D::addMeshFrom(edk::Object2D* obj){
    if(obj){
        //copy the meshs
        edk::uint32 size = obj->meshes.size();
        edk::shape::Mesh2D* temp = NULL;
        edk::shape::Mesh2D* mesh = NULL;
        for(edk::uint32 i=0u;i<size;i++){
            temp = obj->meshes.getMesh(i);
            if(temp){
                mesh = this->newMesh();
                if(mesh){
                    //*mesh = *temp;
                    mesh->cloneFrom(temp);
                }
            }
        }
        return true;
    }
    return false;
}
bool edk::Object2D::addMeshFrom(edk::shape::Mesh2D* mesh){
    if(mesh){
        edk::shape::Mesh2D* temp = this->newMesh();
        if(temp){
            //*mesh = *temp;
            temp->cloneFrom(mesh);
            return true;
        }
    }
    return false;
}
