#include "Object3D.h"

/*
Library Object3D - Object in the 3D world.
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
#pragma message "            Inside Object3D.cpp"
#endif

edk::Object3D::Object3D(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::Object3D::~Object3D(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        /*
    this->actions.cleanReadXMLActionFunction();edkEnd();
    */
        this->cleanMeshes();edkEnd();
    }
}

//Draw function
//HIDE
void edk::Object3D::drawHideBoundingBox(){}
void edk::Object3D::drawHide(bool ){}
void edk::Object3D::drawHideOneTexture(){}
void edk::Object3D::drawHideOneTextureWithLight(bool ){}
void edk::Object3D::drawHideWithoutMaterial(){}
void edk::Object3D::drawHideWithoutMaterialWithLight(bool ){}
void edk::Object3D::drawHideWire(){}
void edk::Object3D::drawHideWirePolygon(edk::uint32 ,edk::uint32 ){}
void edk::Object3D::drawHideNormals(){}
void edk::Object3D::drawHideNormalsWithColor(edk::color3f32){}
bool edk::Object3D::drawHideMesh(bool /*haveLight*/,edk::uint32 ){return true;}
bool edk::Object3D::drawHidePolygon(bool /*haveLight*/,edk::uint32 ,edk::uint32 ){return true;}
bool edk::Object3D::drawHideMeshOneTexture(edk::uint32 ){return true;}
bool edk::Object3D::drawHidePolygonOneTexture(edk::uint32 ,edk::uint32 ){return true;}
bool edk::Object3D::drawHideMeshOneTextureWithLight(bool /*haveLight*/,edk::uint32 ){return true;}
bool edk::Object3D::drawHidePolygonOneTextureWithLight(bool /*haveLight*/,edk::uint32 ,edk::uint32 ){return true;}
bool edk::Object3D::drawHideMeshWithoutMaterial(edk::uint32 ){return true;}
bool edk::Object3D::drawHidePolygonWithoutMaterial(edk::uint32 ,edk::uint32 ){return true;}
bool edk::Object3D::drawHideMeshWithoutMaterialWithLight(bool /*haveLight*/,edk::uint32 ){return true;}
bool edk::Object3D::drawHidePolygonWithoutMaterialWithLight(bool /*haveLight*/,edk::uint32 ,edk::uint32 ){return true;}
bool edk::Object3D::drawHideMeshWire(edk::uint32 ){return true;}
bool edk::Object3D::drawHidePolygonWire(edk::uint32 ,edk::uint32 ){return true;}
//UNHIDE
void edk::Object3D::drawUnhideBoundingBox(){
    edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   ,this->boundingBox.origin.z   );edkEnd();
    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.size.height,this->boundingBox.size.length);edkEnd();
    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.size.height,this->boundingBox.size.length);edkEnd();
    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.origin.y   ,this->boundingBox.origin.z   );edkEnd();
    edk::GU::guEnd();edkEnd();
}
void edk::Object3D::drawUnhide(bool haveLight){
    edk::shape::Mesh3D* mesh;edkEnd();
    if(haveLight){
        edk::uint32 size = this->meshes.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);edkEnd();
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
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);edkEnd();
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
}
void edk::Object3D::drawUnhideOneTexture(){
    edk::shape::Mesh3D* mesh;edkEnd();
    //print all polygonList
    edk::uint32 size = this->meshes.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        //
        mesh = this->meshes.getMesh(i);edkEnd();
        if(mesh){
            mesh->drawOneTexture();edkEnd();
        }
    }
}
void edk::Object3D::drawUnhideOneTextureWithLight(bool haveLight){
    edk::shape::Mesh3D* mesh;edkEnd();
    if(haveLight){
        edk::uint32 size = this->meshes.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);edkEnd();
            if(mesh){
                mesh->drawOneTexture();edkEnd();
            }
        }
    }
    else{
        edk::uint32 size = this->meshes.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);edkEnd();
            if(mesh){
                mesh->drawOneTexture();edkEnd();
            }
        }
    }
}
void edk::Object3D::drawUnhideWithoutMaterial(){
    edk::shape::Mesh3D* mesh;edkEnd();
    //print all polygonList
    edk::uint32 size = this->meshes.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        //
        mesh = this->meshes.getMesh(i);edkEnd();
        if(mesh){
            mesh->drawWithoutMaterial();edkEnd();
        }
    }
}
void edk::Object3D::drawUnhideWithoutMaterialWithLight(bool haveLight){
    edk::shape::Mesh3D* mesh;edkEnd();
    if(haveLight){
        edk::uint32 size = this->meshes.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);edkEnd();
            if(mesh){
                mesh->drawWithoutMaterial();edkEnd();
            }
        }
    }
    else{
        edk::uint32 size = this->meshes.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);edkEnd();
            if(mesh){
                mesh->drawWithoutMaterial();edkEnd();
            }
        }
    }
}
void edk::Object3D::drawUnhideWire(){
    edk::shape::Mesh3D* mesh;edkEnd();
    //print all polygonList
    edk::uint32 size = this->meshes.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        //
        mesh = this->meshes.getMesh(i);edkEnd();
        if(mesh){
            mesh->drawWirePolygons();edkEnd();
        }
    }
}
void edk::Object3D::drawUnhideWirePolygon(edk::uint32 meshPosition,edk::uint32 polygon){
    edk::shape::Mesh3D* mesh = this->meshes.getMesh(meshPosition);edkEnd();
    if(mesh){
        mesh->drawWirePolygon(polygon);edkEnd();
    }
}
void edk::Object3D::drawUnhideNormals(){
    edk::shape::Mesh3D* mesh;edkEnd();
    //print all polygonList
    edk::uint32 size = this->meshes.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        //
        mesh = this->meshes.getMesh(i);edkEnd();
        if(mesh){
            mesh->drawNormals();edkEnd();
        }
    }
}
void edk::Object3D::drawUnhideNormalsWithColor(edk::color3f32 color){
    edk::shape::Mesh3D* mesh;edkEnd();
    //print all polygonList
    edk::uint32 size = this->meshes.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        //
        mesh = this->meshes.getMesh(i);edkEnd();
        if(mesh){
            mesh->drawNormalsWithColor(color);edkEnd();
        }
    }
}
bool edk::Object3D::drawUnhideMesh(bool haveLight,edk::uint32 meshPosition){
    bool ret=false;
    edk::shape::Mesh3D* mesh;edkEnd();
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
    return ret;
}
bool edk::Object3D::drawUnhidePolygon(bool haveLight,edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;
    edk::shape::Mesh3D* mesh;edkEnd();
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
    return ret;
}
bool edk::Object3D::drawUnhideMeshOneTexture(edk::uint32 meshPosition){
    bool ret=false;
    edk::shape::Mesh3D* mesh;edkEnd();
    //
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);edkEnd();
        if(mesh){
            mesh->drawOneTexture();edkEnd();
            ret = true;edkEnd();
        }
    }
    return ret;
}
bool edk::Object3D::drawUnhidePolygonOneTexture(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;
    edk::shape::Mesh3D* mesh;edkEnd();
    //
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);edkEnd();
        if(mesh){
            ret = mesh->drawPolygonOneTexture(polygon);edkEnd();
        }
    }
    return ret;
}
bool edk::Object3D::drawUnhideMeshOneTextureWithLight(bool haveLight,edk::uint32 meshPosition){
    bool ret=false;
    edk::shape::Mesh3D* mesh;edkEnd();
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
        edk::uint32 size = this->meshes.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);edkEnd();
            if(mesh){
                mesh->drawOneTexture();edkEnd();
                ret = true;edkEnd();
            }
        }
    }
    return ret;
}
bool edk::Object3D::drawUnhidePolygonOneTextureWithLight(bool haveLight,edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;
    edk::shape::Mesh3D* mesh;edkEnd();
    if(haveLight){
        if(meshPosition < this->meshes.size()){
            mesh = this->meshes.getMesh(meshPosition);edkEnd();
            if(mesh){
                ret = mesh->drawPolygonOneTexture(polygon);edkEnd();
            }
        }
    }
    else{
        edk::uint32 size = this->meshes.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);edkEnd();
            if(mesh){
                ret = mesh->drawPolygonOneTexture(polygon);edkEnd();
            }
        }
    }
    return ret;
}
bool edk::Object3D::drawUnhideMeshWithoutMaterial(edk::uint32 meshPosition){
    bool ret=false;
    edk::shape::Mesh3D* mesh;edkEnd();
    //print all polygonList
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);edkEnd();
        if(mesh){
            mesh->drawWithoutMaterial();edkEnd();
            ret = true;edkEnd();
        }
    }
    return ret;
}
bool edk::Object3D::drawUnhidePolygonWithoutMaterial(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;
    edk::shape::Mesh3D* mesh;edkEnd();
    //print all polygonList
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);edkEnd();
        if(mesh){
            ret = mesh->drawPolygonWithoutMaterial(polygon);edkEnd();
        }
    }
    return ret;
}
bool edk::Object3D::drawUnhideMeshWithoutMaterialWithLight(bool haveLight,edk::uint32 meshPosition){
    bool ret=false;
    edk::shape::Mesh3D* mesh;edkEnd();
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
    return ret;
}
bool edk::Object3D::drawUnhidePolygonWithoutMaterialWithLight(bool haveLight,edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;
    edk::shape::Mesh3D* mesh;edkEnd();
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
    return ret;
}
bool edk::Object3D::drawUnhideMeshWire(edk::uint32 meshPosition){
    bool ret=false;
    edk::shape::Mesh3D* mesh;edkEnd();
    //print all polygonList
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);edkEnd();
        if(mesh){
            mesh->drawWirePolygons();edkEnd();
            ret = true;edkEnd();
        }
    }
    return ret;
}
bool edk::Object3D::drawUnhidePolygonWire(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;

    edk::shape::Mesh3D* mesh;edkEnd();
    //print all polygonList
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);edkEnd();
        if(mesh){
            ret = mesh->drawWirePolygon(polygon);edkEnd();
        }
    }
    return ret;
}

//load the mtlFile
bool edk::Object3D::loadMTL(const edk::char8* fileName,edk::shape::Mesh3D* mesh){
    return this->loadMTL((edk::char8*) fileName,mesh);
}
bool edk::Object3D::loadMTL(edk::char8* fileName,edk::shape::Mesh3D* mesh){
    if(fileName && mesh){
        return true;
    }
    return false;
}

//update animations
void edk::Object3D::updateChildremsAnimations(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
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
void edk::Object3D::updateChildremsAnimations(edk::float32 seconds){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
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
bool edk::Object3D::updateValuesFromFather(edk::vector::Matrixf32<4u,4u>* matrixTransform){
    if(matrixTransform){
        if(this->father){
            //calculate the boundingBox from the father
            this->father->updateValuesFromFather(matrixTransform);

            edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);edkEnd();
            edk::Math::generateRotateMatrixZ(this->connectedAngle.x,&this->matrixAngleX);edkEnd();
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);edkEnd();
            edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);edkEnd();
            matrixTransform->multiplyThisWithMatrix(&this->matrixSize);edkEnd();
            matrixTransform->multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
            matrixTransform->multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            matrixTransform->multiplyThisWithMatrix(&this->matrixPivo);edkEnd();

            //first copy the matrix
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
            //translate
            matrixTransform->multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            //angle
            matrixTransform->multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
            //scale
            matrixTransform->multiplyThisWithMatrix(&this->matrixSize);edkEnd();
            //Pivo
            matrixTransform->multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
        }
        else{
            //first copy the matrix
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
            //translate
            matrixTransform->multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            //angle
            matrixTransform->multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
            //scale
            matrixTransform->multiplyThisWithMatrix(&this->matrixSize);edkEnd();
            //Pivo
            matrixTransform->multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
        }
        return true;
    }
    return false;
}

void edk::Object3D::Constructor(bool runFather){
    if(runFather){
        edk::Object3DValues::Constructor();edkEnd();
        edk::shape::FileOBJ::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;edkEnd();

        this->hided=true;edkEnd();
        this->meshes.Constructor();edkEnd();
        this->matrixPosition.Constructor();edkEnd();
        this->matrixPivo.Constructor();edkEnd();
        this->matrixAngleX.Constructor();edkEnd();
        this->matrixSize.Constructor();edkEnd();
        this->matrixTransform.Constructor();edkEnd();
        this->matrixPivo.Constructor();edkEnd();
        this->childremsFront.Constructor();edkEnd();
        this->childremsBack.Constructor();edkEnd();

        //
        this->type=edk::TypeObject3D;edkEnd();
        this->selected=NULL;edkEnd();
        //rotation
        this->angle=0.0f;edkEnd();
        //Scale
        this->size = edk::size3f32(1.f,1.f,1.f);edkEnd();
        /*
    this->actions.setReadXMLActionFunction(&edk::Object3D::readXMLAction);edkEnd();
    */
        this->father=NULL;edkEnd();

        this->newSize=1.f;edkEnd();
        this->loadSaveIdentityValues();edkEnd();

        this->unhide();edkEnd();
    }
}

void edk::Object3D::calculateMatrices(){
    //generate the matrices
    this->matrixTransform.setIdentity(1.f,0.f);edkEnd();
    edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
    edk::Math::generateRotateMatrixX(this->angle.x,&this->matrixAngleX);edkEnd();
    edk::Math::generateRotateMatrixY(this->angle.y,&this->matrixAngleY);edkEnd();
    edk::Math::generateRotateMatrixZ(this->angle.z,&this->matrixAngleZ);edkEnd();
    edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
    //this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotate);edkEnd();
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleY);edkEnd();
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleZ);edkEnd();
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
    edk::Math::generateTranslateMatrix(this->pivo*-1.f,&this->matrixPosition);edkEnd();
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
}

void edk::Object3D::writeFatherBoundingBox(edk::cubef32* cube,edk::vector::Matrixf32<4u,4u>* transformMat){
    if(this->father){
        //calculate the boundingBox from the father
        this->father->writeFatherBoundingBox(cube,transformMat);

        edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);edkEnd();
        edk::Math::generateRotateMatrixZ(this->connectedAngle.x,&this->matrixAngleX);edkEnd();
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);edkEnd();
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);edkEnd();
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
        //translate
        transformMat->multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        //angle
        transformMat->multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
        //scale
        transformMat->multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        //Pivo
        transformMat->multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
        //translate
        transformMat->multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        //angle
        transformMat->multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
        //scale
        transformMat->multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        //Pivo
        transformMat->multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
    }
}
bool edk::Object3D::writeBoundingBox(edk::cubef32* cube){
    //multiply the matrix by
    this->matrixTransform.setIdentity();edkEnd();
    if(this->father){
        //calculate the boundingBox from the father
        this->father->writeFatherBoundingBox(cube,&this->matrixTransform);

        edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);edkEnd();
        edk::Math::generateRotateMatrixZ(this->connectedAngle.x,&this->matrixAngleX);edkEnd();
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);edkEnd();
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);edkEnd();
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
    }


    edk::shape::Mesh3D* mesh;edkEnd();
    edk::uint32 size = this->meshes.size();edkEnd();
    if(size){
        mesh = this->meshes.getMesh(0u);edkEnd();
        if(mesh){
            if(this->father){
                mesh->calculateBoundingBox(cube,&this->matrixTransform);edkEnd();
            }
            else{
                *cube = mesh->generateBoundingBox(&this->matrixTransform);edkEnd();
            }
        }
        for(edk::uint32 i=1u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);edkEnd();
            if(mesh){
                mesh->calculateBoundingBox(cube,&this->matrixTransform);edkEnd();
            }
        }
        return true;
    }
    else{
        //generate a small boundingBox
        cube->origin = this->position - 0.1f;
        cube->size = edk::size3f32(this->position.x + 0.1f,this->position.y + 0.1f,this->position.z + 0.1f);
    }
    return false;
}
bool edk::Object3D::writeBoundingBox(edk::cubef32* cube,edk::vector::Matrixf32<4u,4u>* transformMat){
    //first copy the matrix
    if(this->matrixTransform.cloneFrom(transformMat)){
        if(this->father){
            //calculate the boundingBox from the father
            this->father->writeFatherBoundingBox(cube,&this->matrixTransform);

            edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);edkEnd();
            edk::Math::generateRotateMatrixZ(this->connectedAngle.x,&this->matrixAngleX);edkEnd();
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);edkEnd();
            edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);edkEnd();
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();

            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
        }
        else{
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
        }



        edk::shape::Mesh3D* mesh;edkEnd();
        edk::uint32 size = this->meshes.size();edkEnd();
        if(size){
            mesh = this->meshes.getMesh(0u);edkEnd();
            if(mesh){
                if(this->father){
                    *cube = mesh->generateBoundingBox(&this->matrixTransform);edkEnd();
                }
                else{
                    mesh->calculateBoundingBox(cube,&this->matrixTransform);edkEnd();
                }
            }
            for(edk::uint32 i=1u;i<size;i++){
                //
                mesh = this->meshes.getMesh(i);edkEnd();
                if(mesh){
                    mesh->calculateBoundingBox(cube,&this->matrixTransform);edkEnd();
                }
            }
        }
        else{
            //generate a small boundingBox
            cube->origin = this->position - 0.1f;
            cube->size = edk::size3f32(this->position.x + 0.1f,this->position.y + 0.1f,this->position.z + 0.1f);
        }
    }
    return true;
}
bool edk::Object3D::writeChildremBoundingBox(edk::cubef32* cube){
    edk::uint32 size=0u;
    bool ret = false;
    //multiply the matrix by
    this->matrixTransform.setIdentity();edkEnd();
    if(this->father){
        //calculate the boundingBox from the father
        this->father->writeFatherBoundingBox(cube,&this->matrixTransform);

        edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);edkEnd();
        edk::Math::generateRotateMatrixZ(this->connectedAngle.x,&this->matrixAngleX);edkEnd();
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);edkEnd();
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);edkEnd();
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();

        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
    }

    edk::shape::Mesh3D* mesh;edkEnd();
    size = this->meshes.size();edkEnd();
    if(size){
        mesh = this->meshes.getMesh(0u);edkEnd();
        if(mesh){
            if(this->father){
                mesh->calculateBoundingBox(cube,&this->matrixTransform);edkEnd();
            }
            else{
                *cube = mesh->generateBoundingBox(&this->matrixTransform);edkEnd();
            }
        }
        for(edk::uint32 i=1u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);edkEnd();
            if(mesh){
                mesh->calculateBoundingBox(cube,&this->matrixTransform);edkEnd();
            }
        }
        ret = true;
    }
    else{
        //generate a small boundingBox
        cube->origin = this->position - 0.1f;
        cube->size = edk::size3f32(this->position.x + 0.1f,this->position.y + 0.1f,this->position.z + 0.1f);
    }
    return ret;
}
bool edk::Object3D::writeChildremBoundingBox(edk::cubef32* cube,edk::vector::Matrixf32<4u,4u>* transformMat){
    edk::uint32 size=0u;
    //first copy the matrix
    if(this->matrixTransform.cloneFrom(transformMat)){
        if(this->father){
            //calculate the boundingBox from the father
            this->father->writeBoundingBox(cube,&this->matrixTransform);

            edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);edkEnd();
            edk::Math::generateRotateMatrixZ(this->connectedAngle.x,&this->matrixAngleX);edkEnd();
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);edkEnd();
            edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);edkEnd();
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();


            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
        }
        else{
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
        }

        edk::shape::Mesh3D* mesh;edkEnd();
        size = this->meshes.size();edkEnd();
        if(size){
            mesh = this->meshes.getMesh(0u);edkEnd();
            if(mesh){
                if(this->father){
                    *cube = mesh->generateBoundingBox(&this->matrixTransform);edkEnd();
                }
                else{
                    mesh->calculateBoundingBox(cube,&this->matrixTransform);edkEnd();
                }
            }
            for(edk::uint32 i=1u;i<size;i++){
                //
                mesh = this->meshes.getMesh(i);edkEnd();
                if(mesh){
                    mesh->calculateBoundingBox(cube,&this->matrixTransform);edkEnd();
                }
            }
        }
        else{
            //generate a small boundingBox
            cube->origin = this->position - 0.1f;
            cube->size = edk::size3f32(this->position.x + 0.1f,this->position.y + 0.1f,this->position.z + 0.1f);
        }
    }
    return true;
}

void edk::Object3D::loadFatherMatrix(edk::vector::Matrixf32<4u,4u>* transformMat){
    if(this->father){
        //calculate the boundingBox from the father
        this->father->loadFatherMatrix(transformMat);

        edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);edkEnd();
        edk::Math::generateRotateMatrixZ(this->connectedAngle.x,&this->matrixAngleX);edkEnd();
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);edkEnd();
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);edkEnd();
        transformMat->multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        transformMat->multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
        transformMat->multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        transformMat->multiplyThisWithMatrix(&this->matrixPivo);edkEnd();

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
        //translate
        transformMat->multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        //angle
        transformMat->multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
        //scale
        transformMat->multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        //Pivo
        transformMat->multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
        //translate
        transformMat->multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        //angle
        transformMat->multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
        //scale
        transformMat->multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        //Pivo
        transformMat->multiplyThisWithMatrix(&this->matrixPivo);edkEnd();
    }
}

//Function to read the actions
edk::Action* edk::Object3D::readXMLAction(edk::classID /*thisPointer*/,edk::uint32 /*actionCode*/){
    /*
    switch(actionCode){
    case 1u:
    {
        //ActionPosition
        return new edk::Object3D::ActionPosition((edk::Object3D*)thisPointer,edk::vec3f32(0,0));edkEnd();
        break;
    }
    case 2u:
    {
        //ActionMove
        return new edk::Object3D::ActionMove((edk::Object3D*)thisPointer,0,edk::vec3f32(0,0));edkEnd();
        break;
    }
    case 3u:
    {
        //ActionSetSize
        return new edk::Object3D::ActionSetSize((edk::Object3D*)thisPointer,edk::size3f32(1,1));edkEnd();
        break;
    }
    case 4u:
    {
        //ActionSize
        return new edk::Object3D::ActionSize((edk::Object3D*)thisPointer,0,edk::size3f32(1,1));edkEnd();
        break;
    }
    case 5u:
    {
        //ActionSetAngle
        return new edk::Object3D::ActionSetAngle((edk::Object3D*)thisPointer,0);edkEnd();
        break;
    }
    case 6u:
    {
        //ActionAngle
        return new edk::Object3D::ActionAngle((edk::Object3D*)thisPointer,0,0);edkEnd();
        break;
    }
    case 7u:
    {
        //ActionMeshName
        return new edk::Object3D::ActionMeshName((edk::Object3D*)thisPointer,0,NULL,false);edkEnd();
        break;
    }
    case 8u:
    {
        //ActionMeshStop
        return new edk::Object3D::ActionMeshStop((edk::Object3D*)thisPointer,0);edkEnd();
        break;
    }
    }
    */
    return new edk::ActionZero();edkEnd();
}

//draw the mesh
void edk::Object3D::drawChildremsBackBoundingBox(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBoundingBox();
    }
}
void edk::Object3D::drawChildBackBoundingBox(){
    //test if have a father
    //if(this->father){
    //    //put the transformation on a stack
    //    edk::GU::guPushMatrix();edkEnd();
    //
    //    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);edkEnd();
    //
    //    edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    //    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );edkEnd();
    //    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);edkEnd();
    //    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.size.height);edkEnd();
    //    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.origin.y   );edkEnd();
    //    edk::GU::guEnd();edkEnd();
    //
    //    edk::GU::guPopMatrix();edkEnd();
    //}
    //else{
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);edkEnd();

    this->drawChildremsBackBoundingBox();

    (this->*functionDrawBoundingBox)();

    edk::GU::guPopMatrix();edkEnd();
    //}
}
void edk::Object3D::drawChildremsFrontBoundingBox(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildBoundingBox();
    }
}
void edk::Object3D::drawChildFrontBoundingBox(){
    //test if have a father
    //if(this->father){
    //    //put the transformation on a stack
    //    edk::GU::guPushMatrix();edkEnd();
    //
    //    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);edkEnd();
    //
    //    edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    //    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );edkEnd();
    //    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);edkEnd();
    //    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.size.height);edkEnd();
    //    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.origin.y   );edkEnd();
    //    edk::GU::guEnd();edkEnd();
    //
    //    edk::GU::guPopMatrix();edkEnd();
    //}
    //else{
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    (this->*functionDrawBoundingBox)();

    this->drawChildremsFrontBoundingBox();

    edk::GU::guPopMatrix();edkEnd();
    //}
}
void edk::Object3D::drawChildremsBoundingBox(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildBoundingBox();
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildBoundingBox();
    }
}
void edk::Object3D::drawChildBoundingBox(){
    //test if have a father
    //if(this->father){
    //    //put the transformation on a stack
    //    edk::GU::guPushMatrix();edkEnd();
    //
    //    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);edkEnd();
    //
    //    edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    //    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );edkEnd();
    //    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);edkEnd();
    //    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.size.height);edkEnd();
    //    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.origin.y   );edkEnd();
    //    edk::GU::guEnd();edkEnd();
    //
    //    edk::GU::guPopMatrix();edkEnd();
    //}
    //else{
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);edkEnd();

    this->drawChildremsBackBoundingBox();

    (this->*functionDrawBoundingBox)();

    this->drawChildremsFrontBoundingBox();
    edk::GU::guPopMatrix();edkEnd();
    //}
}
void edk::Object3D::drawChildremsBack(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChild(haveLight);
    }
}
void edk::Object3D::drawChildBack(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBack(haveLight);

    (this->*functionDraw)(haveLight);

    //glEnable(GL_RESCALE_NORMAL);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsFront(bool haveLight){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChild(haveLight);
    }
}
void edk::Object3D::drawChildFront(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    (this->*functionDraw)(haveLight);

    this->drawChildremsFront(haveLight);
    //glEnable(GL_RESCALE_NORMAL);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildrems(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChild(haveLight);
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChild(haveLight);
    }
}
void edk::Object3D::drawChild(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBack(haveLight);

    (this->*functionDraw)(haveLight);

    this->drawChildremsFront(haveLight);
    //glEnable(GL_RESCALE_NORMAL);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsBackOneTexture(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildOneTexture();
    }
}
void edk::Object3D::drawChildBackOneTexture(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackOneTexture();

    (this->*functionDrawOneTexture)();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsFrontOneTexture(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildOneTexture();
    }
}
void edk::Object3D::drawChildFrontOneTexture(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    (this->*functionDrawOneTexture)();

    this->drawChildremsFrontOneTexture();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsOneTexture(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildOneTexture();
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildOneTexture();
    }
}
void edk::Object3D::drawChildOneTexture(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackOneTexture();

    (this->*functionDrawOneTexture)();

    this->drawChildremsFrontOneTexture();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsBackOneTextureWithLight(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildOneTextureWithLight(haveLight);
    }
}
void edk::Object3D::drawChildBackOneTextureWithLight(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackOneTextureWithLight(haveLight);

    (this->*functionDrawOneTextureWithLight)(haveLight);

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsFrontOneTextureWithLight(bool haveLight){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildOneTextureWithLight(haveLight);
    }
}
void edk::Object3D::drawChildFrontOneTextureWithLight(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    (this->*functionDrawOneTextureWithLight)(haveLight);

    this->drawChildremsFrontOneTextureWithLight(haveLight);

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsOneTextureWithLight(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildOneTextureWithLight(haveLight);
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildOneTextureWithLight(haveLight);
    }
}
void edk::Object3D::drawChildOneTextureWithLight(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackOneTextureWithLight(haveLight);

    (this->*functionDrawOneTextureWithLight)(haveLight);

    this->drawChildremsFrontOneTextureWithLight(haveLight);

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsBackWithoutMaterial(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildWithoutMaterial();
    }
}
void edk::Object3D::drawChildBackWithoutMaterial(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWithoutMaterial();

    (this->*functionDrawWithoutMaterial)();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsFrontWithoutMaterial(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildWithoutMaterial();
    }
}
void edk::Object3D::drawChildFrontWithoutMaterial(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    edk::shape::Mesh3D* mesh;edkEnd();
    //print all polygonList
    edk::uint32 size = this->meshes.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        //
        mesh = this->meshes.getMesh(i);edkEnd();
        if(mesh){
            mesh->drawWithoutMaterial();edkEnd();
        }
    }

    this->drawChildremsFrontWithoutMaterial();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsWithoutMaterial(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildWithoutMaterial();
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildWithoutMaterial();
    }
}
void edk::Object3D::drawChildWithoutMaterial(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWithoutMaterial();

    edk::shape::Mesh3D* mesh;edkEnd();
    //print all polygonList
    edk::uint32 size = this->meshes.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        //
        mesh = this->meshes.getMesh(i);edkEnd();
        if(mesh){
            mesh->drawWithoutMaterial();edkEnd();
        }
    }

    this->drawChildremsFrontWithoutMaterial();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsBackWithoutMaterialWithLight(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildWithoutMaterialWithLight(haveLight);
    }
}
void edk::Object3D::drawChildBackWithoutMaterialWithLight(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWithoutMaterialWithLight(haveLight);

    (this->*functionDrawWithoutMaterialWithLight)(haveLight);

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsFrontWithoutMaterialWithLight(bool haveLight){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildWithoutMaterialWithLight(haveLight);
    }
}
void edk::Object3D::drawChildFrontWithoutMaterialWithLight(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    (this->*functionDrawWithoutMaterialWithLight)(haveLight);

    this->drawChildremsFrontWithoutMaterialWithLight(haveLight);

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsWithoutMaterialWithLight(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildWithoutMaterialWithLight(haveLight);
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildWithoutMaterialWithLight(haveLight);
    }
}
void edk::Object3D::drawChildWithoutMaterialWithLight(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWithoutMaterialWithLight(haveLight);

    (this->*functionDrawWithoutMaterialWithLight)(haveLight);

    this->drawChildremsFrontWithoutMaterialWithLight(haveLight);

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsBackWire(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildWire();
    }
}
void edk::Object3D::drawChildBackWire(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWire();

    (this->*functionDrawNormals)();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsBackNormals(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildNormals();
    }
}
void edk::Object3D::drawChildBackNormals(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWire();

    (this->*functionDrawNormals)();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsBackNormalsWithColor(edk::color3f32 color){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildNormalsWithColor(color);
    }
}
void edk::Object3D::drawChildBackNormalsWithColor(edk::color3f32 color){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWire();

    (this->*functionDrawNormalsWithColor)(color);

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsFrontWire(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildWire();
    }
}
void edk::Object3D::drawChildFrontWire(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    (this->*functionDrawWire)();

    this->drawChildremsFrontWire();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsFrontNormals(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildNormals();
    }
}
void edk::Object3D::drawChildFrontNormals(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    (this->*functionDrawNormals)();

    this->drawChildremsFrontWire();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsFrontNormalsWithColor(edk::color3f32 color){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildNormalsWithColor(color);
    }
}
void edk::Object3D::drawChildFrontNormalsWithColor(edk::color3f32 color){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    (this->*functionDrawNormalsWithColor)(color);

    this->drawChildremsFrontWire();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsWire(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildWire();
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildWire();
    }
}
void edk::Object3D::drawChildWire(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWire();

    (this->*functionDrawWire)();

    this->drawChildremsFrontWire();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsNormals(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildNormals();
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildNormals();
    }
}
void edk::Object3D::drawChildNormals(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWire();

    (this->*functionDrawNormals)();

    this->drawChildremsFrontWire();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsNormalsWithColor(edk::color3f32 color){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildNormalsWithColor(color);
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildNormalsWithColor(color);
    }
}
void edk::Object3D::drawChildNormalsWithColor(edk::color3f32 color){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWire();

    (this->*functionDrawNormalsWithColor)(color);

    this->drawChildremsFrontWire();

    edk::GU::guPopMatrix();edkEnd();
}
//draw the pivo
void edk::Object3D::drawChildremsBackPivo(edk::float32 size,edk::color3f32 color){
    edk::uint32 cSize = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildPivo(size,color);
    }
}
void edk::Object3D::drawChildBackPivo(edk::float32 size,edk::color3f32 color){
    edk::Object3D::drawPivoInPosition(this->position,size,color);
    if(this->childremsBack.size()){
        edk::GU::guPushMatrix();edkEnd();
        //add translate
        edk::GU::guTranslate3f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateZf32(this->angle.x);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->size);edkEnd();
        //set the pivo
        edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();
        this->drawChildremsBackPivo(size,color);
        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::Object3D::drawChildremsFrontPivo(edk::float32 size,edk::color3f32 color){
    edk::uint32 cSize = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildPivo(size,color);
    }
}
void edk::Object3D::drawChildFrontPivo(edk::float32 size,edk::color3f32 color){
    edk::Object3D::drawPivoInPosition(this->position,size,color);
    if(this->childremsFront.size()){
        edk::GU::guPushMatrix();edkEnd();
        //add translate
        edk::GU::guTranslate3f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateZf32(this->angle.x);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->size);edkEnd();
        //set the pivo
        edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();
        this->drawChildremsFrontPivo(size,color);
        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::Object3D::drawChildremsPivo(edk::float32 size,edk::color3f32 color){
    edk::uint32 cSize = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildPivo(size,color);
    }
    cSize = this->childremsFront.size();
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildPivo(size,color);
    }
}
void edk::Object3D::drawChildPivo(edk::float32 size,edk::color3f32 color){
    if(this->childremsBack.size()){
        edk::GU::guPushMatrix();edkEnd();
        //add translate
        edk::GU::guTranslate3f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateZf32(this->angle.x);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->size);edkEnd();
        //set the pivo
        edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();
        this->drawChildremsBackPivo(size,color);
        edk::GU::guPopMatrix();edkEnd();
    }
    edk::Object3D::drawPivoInPosition(this->position,size,color);
    if(this->childremsFront.size()){
        edk::GU::guPushMatrix();edkEnd();
        //add translate
        edk::GU::guTranslate3f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateZf32(this->angle.x);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->size);edkEnd();
        //set the pivo
        edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();
        this->drawChildremsFrontPivo(size,color);
        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::Object3D::drawChildremsBackPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::uint32 cSize = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildPivo(size,r,g,b);
    }
}
void edk::Object3D::drawChildBackPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::GU::guPushMatrix();edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();
    if(this->childremsBack.size()){
        this->drawChildremsBackPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();edkEnd();

    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    //edk::GU::guTranslate3f32(this->position);edkEnd();

    edk::Object3D::drawPivoInPosition(this->position,size,edk::color3f32(r,g,b));

    edk::GU::guPopMatrix();edkEnd();

    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();
    if(this->childremsFront.size()){
        this->drawChildremsFrontPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsFrontPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::uint32 cSize = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildPivo(size,r,g,b);
    }
}
void edk::Object3D::drawChildFrontPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::GU::guPushMatrix();edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();
    if(this->childremsBack.size()){
        this->drawChildremsBackPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();edkEnd();


    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guScale3f32(this->connectedSize);edkEnd();
    edk::GU::guRotateZf32(this->connectedAngle.x);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);edkEnd();

    //add translate
    //edk::GU::guTranslate3f32(this->position);edkEnd();

    edk::Object3D::drawPivoInPosition(this->position,size,edk::color3f32(r,g,b));

    edk::GU::guPopMatrix();edkEnd();

    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();
    if(this->childremsFront.size()){
        this->drawChildremsFrontPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawChildremsPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::uint32 cSize = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsBack.getElementInPosition(i);
        obj->drawChildPivo(size,r,g,b);
    }
    cSize = this->childremsFront.size();
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsFront.getElementInPosition(i);
        obj->drawChildPivo(size,r,g,b);
    }
}
void edk::Object3D::drawChildPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    if(this->childremsBack.size()){
        edk::Object3D::drawPivoInPosition(this->position,size,edk::color3f32(r,g,b));
        edk::GU::guPushMatrix();edkEnd();
        //add translate
        edk::GU::guTranslate3f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateZf32(this->angle.x);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->size);edkEnd();
        //set the pivo
        edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();
        this->drawChildremsBackPivo(size,r,g,b);
        edk::GU::guPopMatrix();edkEnd();
    }
    edk::Object3D::drawPivoInPosition(this->position,size,edk::color3f32(r,g,b));
    if(this->childremsFront.size()){
        edk::Object3D::drawPivoInPosition(this->position,size,edk::color3f32(r,g,b));
        edk::GU::guPushMatrix();edkEnd();
        //add translate
        edk::GU::guTranslate3f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateZf32(this->angle.x);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->size);edkEnd();
        //set the pivo
        edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();
        this->drawChildremsFrontPivo(size,r,g,b);
        edk::GU::guPopMatrix();edkEnd();
    }
}

//Actions
edk::Object3D::ActionPosition::ActionPosition(edk::Object3D* /*object*/, edk::vec3f32 /*position*/){
    /*
    this->position=position;edkEnd();
    this->object=object;edkEnd();
    this->code = 1u;edkEnd();
    */
}
//run action function
void edk::Object3D::ActionPosition::runAction(){
    this->object->position = this->position;edkEnd();
}
//write to XML
bool edk::Object3D::ActionPosition::writeToXML(edk::XML* xml,edk::uint32 id){
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
                    xml->addSelectedNextAttribute("positionZ",this->position.z);edkEnd();

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
bool edk::Object3D::ActionPosition::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    this->position.z = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionZ"));edkEnd();

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
edk::vec3f32 edk::Object3D::ActionPosition::getPosition(){
    return this->position;edkEnd();
}
edk::Object3D::ActionMove::ActionMove(edk::Object3D* object,edk::float32 duration, edk::vec3f32 position){
    this->position=position;edkEnd();
    this->duration = duration;edkEnd();
    this->object=object;edkEnd();
    this->code = 2u;edkEnd();
}
//run action function
void edk::Object3D::ActionMove::runAction(){
    this->object->animationPosition.cleanTracks();edkEnd();
    edk::uint32 track = this->object->animationPosition.newTrack();edkEnd();
    this->object->animationPosition.addFirstInterpolationLine(track,0,
                                                              this->object->position.x,
                                                              this->object->position.y,
                                                              this->object->position.z,
                                                              this->duration,
                                                              this->position.x,
                                                              this->position.y,
                                                              this->position.z
                                                              );edkEnd();
    this->object->animationPosition.playForwardAllTracks();edkEnd();
}
//write to XML
bool edk::Object3D::ActionMove::writeToXML(edk::XML* xml,edk::uint32 id){
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
                    xml->addSelectedNextAttribute("positionZ",this->position.z);edkEnd();
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
bool edk::Object3D::ActionMove::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    this->position.z = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionZ"));edkEnd();
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
edk::vec3f32 edk::Object3D::ActionMove::getPosition(){
    return this->position;edkEnd();
}
edk::float32 edk::Object3D::ActionMove::getDuration(){
    return this->duration;edkEnd();
}
edk::Object3D::ActionSetSize::ActionSetSize(edk::Object3D* /*object*/, edk::size3f32 /*size*/){
    /*
    this->object=object;edkEnd();
    this->size=size;edkEnd();
    this->code = 3u;edkEnd();
    */
}
//run action function
void edk::Object3D::ActionSetSize::runAction(){
    /*
    this->object->size = this->size;edkEnd();
    */
}
//write to XML
bool edk::Object3D::ActionSetSize::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
bool edk::Object3D::ActionSetSize::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
edk::size3f32 edk::Object3D::ActionSetSize::getSize(){
    return this->size;edkEnd();
}
edk::Object3D::ActionSize::ActionSize(edk::Object3D* /*object*/,edk::float32 /*duration*/, edk::size3f32 /*size*/){
    /*
    this->size=size;edkEnd();
    this->duration = duration;edkEnd();
    this->object=object;edkEnd();
    this->code = 4u;edkEnd();
    */
}
//run action function
void edk::Object3D::ActionSize::runAction(){
    /*
    this->object->animationSize.cleanAnimations();edkEnd();
    this->object->animationSize.addFirstInterpolationLine(0,this->object->size.width,this->object->size.height,this->duration,this->size.width,this->size.height);edkEnd();
    this->object->animationSize.playForward();edkEnd();
    */
}
//write to XML
bool edk::Object3D::ActionSize::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
                    xml->addSelectedNextAttribute("length",this->size.length);edkEnd();
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
bool edk::Object3D::ActionSize::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
                    this->size.length = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("length"));edkEnd();
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
edk::size3f32 edk::Object3D::ActionSize::getSize(){
    return this->size;edkEnd();
}
edk::float32 edk::Object3D::ActionSize::getDuration(){
    return this->duration;edkEnd();
}
edk::Object3D::ActionSetAngle::ActionSetAngle(edk::Object3D* object, edk::float32 angle){
    this->object = object;edkEnd();
    this->angle = angle;edkEnd();
    this->code = 5u;edkEnd();
}
//run action function
void edk::Object3D::ActionSetAngle::runAction(){
    this->object->angle = this->angle;edkEnd();
}
//write to XML
bool edk::Object3D::ActionSetAngle::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
                    xml->addSelectedNextAttribute("angle",this->angle.x);edkEnd();

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
bool edk::Object3D::ActionSetAngle::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
edk::float32 edk::Object3D::ActionSetAngle::getAngle(){
    return this->angle;edkEnd();
}
edk::Object3D::ActionAngle::ActionAngle(edk::Object3D* /*object*/,edk::float32 /*duration*/, edk::float32 /*angle*/){
    /*
    this->object = object;edkEnd();
    this->duration = duration;edkEnd();
    this->angle = angle;edkEnd();
    this->code = 6u;edkEnd();
    */
}
//run action function
void edk::Object3D::ActionAngle::runAction(){
    /*
    this->object->animationRotation.cleanAnimations();edkEnd();
    this->object->animationRotation.addFirstInterpolationLine(0,this->object->angle,this->duration,this->angle.x);edkEnd();
    this->object->animationRotation.playForward();edkEnd();
    */
}
//write to XML
bool edk::Object3D::ActionAngle::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
                    xml->addSelectedNextAttribute("angle",this->angle.x);edkEnd();
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
bool edk::Object3D::ActionAngle::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
edk::float32 edk::Object3D::ActionAngle::getAngle(){
    return this->angle;edkEnd();
}
edk::float32 edk::Object3D::ActionAngle::getDuration(){
    return this->duration;edkEnd();
}
edk::Object3D::ActionMeshName::ActionMeshName(edk::Object3D* /*object*/,edk::uint32 /*id*/, edk::char8* /*name*/,bool /*loop*/){
    /*
    this->object=object;edkEnd();
    this->loop = loop;edkEnd();
    this->id = id;edkEnd();
    this->setName(name);edkEnd();
    this->code = 7u;edkEnd();
    */
}
//run action function
void edk::Object3D::ActionMeshName::runAction(){
    /*
    //load the mesh
    edk::shape::Mesh3D* mesh = this->object->getMesh(this->id);edkEnd();
    if(mesh){
        mesh->selectedAnimationSetLoop(this->loop);edkEnd();
        mesh->selectedAnimationPlayNameForward(this->name());edkEnd();
    }
    */
}
//write to XML
bool edk::Object3D::ActionMeshName::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
bool edk::Object3D::ActionMeshName::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
edk::uint32 edk::Object3D::ActionMeshName::getId(){
    return this->id;edkEnd();
}
bool edk::Object3D::ActionMeshName::getLoop(){
    return this->loop;edkEnd();
}
edk::Object3D::ActionMeshStop::ActionMeshStop(edk::Object3D* /*object*/,edk::uint32 /*id*/){
    /*
    this->object=object;edkEnd();
    this->id = id;edkEnd();
    this->code = 8u;edkEnd();
    */
}
//run action function
void edk::Object3D::ActionMeshStop::runAction(){
    /*
    //load the mesh
    edk::shape::Mesh3D* mesh = this->object->getMesh(this->id);edkEnd();
    if(mesh){
        mesh->selectedAnimationStop();edkEnd();
    }
    */
}
//write to XML
bool edk::Object3D::ActionMeshStop::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
bool edk::Object3D::ActionMeshStop::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
edk::uint32 edk::Object3D::ActionMeshStop::getId(){
    return this->id;edkEnd();
}

//create a new mesh and add to the meshs stack
edk::shape::Mesh3D* edk::Object3D::newMesh(edk::uint32* position){
    return this->meshes.pushNewMesh(position);edkEnd();
}

edk::shape::Mesh3D* edk::Object3D::allocMeshForOBJ(){
    return this->newMesh();
}

//clean the obect
void edk::Object3D::clean(){
    //
    this->cleanConnectedObjects();
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
edk::TypeObject edk::Object3D::getType(){
    return this->type;
}

//Add a list to the Object3D
edk::uint32 edk::Object3D::addMesh(edk::shape::Mesh3D* mesh){
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
bool edk::Object3D::removeMesh(edk::uint32 position){
    //remove the mesh
    return this->meshes.removeMesh(position);edkEnd();
}
//remove all meshes
void edk::Object3D::cleanMeshes(){
    this->cleanSelected();edkEnd();
    this->meshes.removeAllMeshes();edkEnd();
}

//function to calculate boundingBox
bool edk::Object3D::calculateBoundingBox(){
    return this->writeChildremBoundingBox(&this->boundingBox);
}
bool edk::Object3D::calculateBoundingBox(edk::vector::Matrixf32<4u,4u>* transformMat){
    return this->writeChildremBoundingBox(&this->boundingBox,transformMat);
}
bool edk::Object3D::generateBoundingBox(){
    return this->writeChildremBoundingBox(&this->boundingBox);
}
bool edk::Object3D::generateBoundingBox(edk::vector::Matrixf32<4u,4u>* transformMat){
    return this->writeChildremBoundingBox(&this->boundingBox,transformMat);
}
//functions to calculate a new boundingBox
edk::cubef32 edk::Object3D::calculateNewBoundingBox(){
    edk::cubef32 ret;
    this->writeChildremBoundingBox(&ret);
    return ret;
}
edk::cubef32 edk::Object3D::calculateNewBoundingBox(edk::vector::Matrixf32<4u,4u>* transformMat){
    edk::cubef32 ret;
    this->writeChildremBoundingBox(&ret,transformMat);
    return ret;
}
edk::cubef32 edk::Object3D::generateNewBoundingBox(){
    edk::cubef32 ret;
    this->writeChildremBoundingBox(&ret);
    return ret;
}
edk::cubef32 edk::Object3D::generateNewBoundingBox(edk::vector::Matrixf32<4u,4u>* transformMat){
    edk::cubef32 ret;
    this->writeChildremBoundingBox(&ret,transformMat);
    return ret;
}

//function to calculate boundingBox
bool edk::Object3D::calculateBoundingBoxNoChildrem(){
    return this->writeBoundingBox(&this->boundingBox);
}
bool edk::Object3D::calculateBoundingBoxNoChildrem(edk::vector::Matrixf32<4u,4u>* transformMat){
    return this->writeBoundingBox(&this->boundingBox,transformMat);
}
bool edk::Object3D::generateBoundingBoxNoChildrem(){
    return this->writeBoundingBox(&this->boundingBox);
}
bool edk::Object3D::generateBoundingBoxNoChildrem(edk::vector::Matrixf32<4u,4u>* transformMat){
    return this->writeBoundingBox(&this->boundingBox,transformMat);
}
//functions to calculate a new boundingBox
edk::cubef32 edk::Object3D::calculateNewBoundingBoxNoChildrem(){
    edk::cubef32 ret;
    this->writeBoundingBox(&ret);
    return ret;
}
edk::cubef32 edk::Object3D::calculateNewBoundingBoxNoChildrem(edk::vector::Matrixf32<4u,4u>* transformMat){
    edk::cubef32 ret;
    this->writeBoundingBox(&ret,transformMat);
    return ret;
}
edk::cubef32 edk::Object3D::generateNewBoundingBoxNoChildrem(){
    edk::cubef32 ret;
    this->writeBoundingBox(&ret);
    return ret;
}
edk::cubef32 edk::Object3D::generateNewBoundingBoxNoChildrem(edk::vector::Matrixf32<4u,4u>* transformMat){
    edk::cubef32 ret;
    this->writeBoundingBox(&ret,transformMat);
    return ret;
}

//return a copy of the boundingBox
edk::cubef32 edk::Object3D::getBoundingBox(){
    return this->boundingBox;
}

//Select the polygonList
bool edk::Object3D::selectMesh(edk::uint32 position){
    //free the selected
    this->cleanSelected();edkEnd();
    if((this->selected = this->meshes.getMesh(position))){
        return true;
    }
    //else return false
    return false;
}
//return the selected textureID
edk::uint32 edk::Object3D::selectedGetTextureID(edk::uint8 number){
    //test if have one selected mesh
    if(this->selected){
        //return the number
        return this->selected->material.getTexture(number);edkEnd();
    }
    //else return false
    return 0u;edkEnd();
}
//free the selected
void edk::Object3D::cleanSelected(){
    //
    this->selected=NULL;edkEnd();
}
//return the number of meshs
edk::uint32 edk::Object3D::getMeshSize(){
    return this->meshes.size();edkEnd();
}
//return the mesh pointer
edk::shape::Mesh3D* edk::Object3D::getMesh(edk::uint32 position){
    return this->meshes.getMesh(position);edkEnd();
}
//remove all meshes
void edk::Object3D::removeAllMesh(){
    this->cleanMeshes();edkEnd();
}
//set the polygonsColor
bool edk::Object3D::setPolygonColor(edk::uint32 position,edk::color4f32 color){
    if(this->meshes.getMesh(position)){
        this->meshes.getMesh(position)->setPolygonsColor(color);edkEnd();
    }
    return false;
}
bool edk::Object3D::setPolygonColor(edk::uint32 position,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setPolygonColor(position,edk::color4f32(r,g,b,a));edkEnd();
}

void edk::Object3D::setPolygonsColor(edk::color4f32 color){
    edk::uint32 size = this->meshes.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColor(color);edkEnd();
        }
    }
}
void edk::Object3D::setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setPolygonsColor(edk::color4f32(r,g,b,a));edkEnd();
}
void edk::Object3D::setPolygonsColorR(edk::float32 r){
    edk::uint32 size = this->meshes.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColorR(r);edkEnd();
        }
    }
}
void edk::Object3D::setPolygonsColorG(edk::float32 g){
    edk::uint32 size = this->meshes.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColorG(g);edkEnd();
        }
    }
}
void edk::Object3D::setPolygonsColorB(edk::float32 b){
    edk::uint32 size = this->meshes.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColorB(b);edkEnd();
        }
    }
}
void edk::Object3D::setPolygonsColorA(edk::float32 a){
    edk::uint32 size = this->meshes.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColorA(a);edkEnd();
        }
    }
}
//Set the polygons smooth
bool edk::Object3D::setPolygonsSmooth(bool smooth){
    edk::uint32 size = this->meshes.size();edkEnd();
    edk::shape::Mesh3D* temp;edkEnd();
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->meshes.getMesh(i);edkEnd();
            if(temp){
                temp->setPolygonsSmooth(smooth);edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::Object3D::setPolygonsSmoothOn(){
    edk::uint32 size = this->meshes.size();edkEnd();
    edk::shape::Mesh3D* temp;edkEnd();
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->meshes.getMesh(i);edkEnd();
            if(temp){
                temp->setPolygonsSmoothOn();edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::Object3D::setPolygonsSmoothOff(){
    edk::uint32 size = this->meshes.size();edkEnd();
    edk::shape::Mesh3D* temp;edkEnd();
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->meshes.getMesh(i);edkEnd();
            if(temp){
                temp->setPolygonsSmoothOff();edkEnd();
            }
        }
        return true;
    }
    return false;
}
//update the polygons normals
bool edk::Object3D::updatePolygonsNormals(){
    edk::uint32 size = this->meshes.size();edkEnd();
    edk::shape::Mesh3D* temp;edkEnd();
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->meshes.getMesh(i);edkEnd();
            if(temp){
                temp->updatePolygonsNormals();edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::Object3D::calculatePolygonsNormals(){
    edk::uint32 size = this->meshes.size();edkEnd();
    edk::shape::Mesh3D* temp;edkEnd();
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->meshes.getMesh(i);edkEnd();
            if(temp){
                temp->updatePolygonsNormals();edkEnd();
            }
        }
        return true;
    }
    return false;
}

//rotate the object to look at the camera
void edk::Object3D::lookAtPoint(edk::float32 x,edk::float32 y,edk::float32 z){
    this->lookAtPoint(edk::vec3f32(x,y,z));edkEnd();
}
void edk::Object3D::lookAtPoint(edk::vec3f32 point){
    //get the point angle
    point-=this->position;edkEnd();
    this->angle.x = 0.f;edkEnd();
    this->angle.y = 0.f;edkEnd();
    this->angle.z = 0.f;edkEnd();

    //get the base angle
    this->angle.y = edk::Math::getAngle(point.x,point.z) *-1.f;edkEnd();
    //get the height angle
    edk::vec2f32 newPosition = edk::Math::rotatePlus(edk::vec2f32(point.x,point.z),this->angle.y);edkEnd();
    this->angle.z = edk::Math::getAngle(newPosition.x,point.y);edkEnd();
}

//get world polygon
bool edk::Object3D::getWorldPolygon(edk::shape::Polygon3D* dest,edk::uint32 meshPosition,edk::uint32 polygonPosition){
    bool ret=false;edkEnd();
    if(dest){
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();
        //multiply the matrix by

        this->matrixTransform.setIdentity();edkEnd();

        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();

        edk::shape::Mesh3D* mesh = this->meshes.getMesh(meshPosition);edkEnd();
        if(mesh){
            ret = mesh->getWorldPolygon(dest,polygonPosition,&this->matrixTransform);edkEnd();
        }
    }
    return ret;
}
bool edk::Object3D::getWorldPolygon(edk::shape::Polygon3D* dest,edk::uint32 meshPosition,edk::uint32 polygonPosition,edk::vector::Matrixf32<4u,4u>* transformMat){
    bool ret=false;edkEnd();
    if(dest){
        //first copy the matrix
        if(this->matrixTransform.cloneFrom(transformMat)){
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);edkEnd();

            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);edkEnd();
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);edkEnd();

            edk::shape::Mesh3D* mesh;edkEnd();
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
bool edk::Object3D::setLight(edk::uint32 position,edk::light::Light light){
    if(position<EDK_LIGHT_LIMIT){
        this->lights[position] = light;edkEnd();
        return true;
    }
    return false;
}
bool edk::Object3D::cleanLight(edk::uint32 position){
    if(position<EDK_LIGHT_LIMIT){
        //
        this->lights[position].clean();edkEnd();
        return true;
    }
    return false;
}
bool edk::Object3D::lightOn(edk::uint32 position){
    if(position<EDK_LIGHT_LIMIT){
        //add the light on the tree
        this->lights[position].on=true;edkEnd();
        return true;
    }
    return false;
}
bool edk::Object3D::lightOff(edk::uint32 position){
    if(position<EDK_LIGHT_LIMIT){
        //remove the position from the tree
        this->lights[position].on=false;edkEnd();
        return true;
    }
    return false;
}

//OBJ
bool edk::Object3D::addObj(const edk::char8* fileName){
    return this->addObj((edk::char8*) fileName);edkEnd();
}
bool edk::Object3D::addObj(edk::char8* fileName){
    if(fileName){
        return this->objAddFile(fileName);
    }
    return false;
}
bool edk::Object3D::loadOBJ(const edk::char8* fileName){
    return this->loadOBJ((edk::char8*) fileName);edkEnd();
}
bool edk::Object3D::loadOBJ(edk::char8* fileName){
    this->cleanMeshes();edkEnd();
    return this->addObj(fileName);edkEnd();
}

//HIDE
bool edk::Object3D::hide(){
    if(!this->hided){
        //
        this->functionDrawBoundingBox = &edk::Object3D::drawHideBoundingBox;
        this->functionDraw = &edk::Object3D::drawHide;
        this->functionDrawOneTexture = &edk::Object3D::drawHideOneTexture;
        this->functionDrawOneTextureWithLight = &edk::Object3D::drawHideOneTextureWithLight;
        this->functionDrawWithoutMaterial = &edk::Object3D::drawHideWithoutMaterial;
        this->functionDrawWithoutMaterialWithLight = &edk::Object3D::drawHideWithoutMaterialWithLight;
        this->functionDrawWire = &edk::Object3D::drawHideWire;
        this->functionDrawWirePolygon = &edk::Object3D::drawHideWirePolygon;
        this->functionDrawNormals = &edk::Object3D::drawHideNormals;
        this->functionDrawNormalsWithColor = &edk::Object3D::drawHideNormalsWithColor;
        this->functionDrawMesh = &edk::Object3D::drawHideMesh;
        this->functionDrawPolygon = &edk::Object3D::drawHidePolygon;
        this->functionDrawMeshOneTexture = &edk::Object3D::drawHideMeshOneTexture;
        this->functionDrawPolygonOneTexture = &edk::Object3D::drawHidePolygonOneTexture;
        this->functionDrawMeshOneTextureWithLight = &edk::Object3D::drawHideMeshOneTextureWithLight;
        this->functionDrawPolygonOneTextureWithLight = &edk::Object3D::drawHidePolygonOneTextureWithLight;
        this->functionDrawMeshWithoutMaterial = &edk::Object3D::drawHideMeshWithoutMaterial;
        this->functionDrawPolygonWithoutMaterial = &edk::Object3D::drawHidePolygonWithoutMaterial;
        this->functionDrawMeshWithoutMaterialWithLight = &edk::Object3D::drawHideMeshWithoutMaterialWithLight;
        this->functionDrawPolygonWithoutMaterialWithLight = &edk::Object3D::drawHidePolygonWithoutMaterialWithLight;
        this->functionDrawMeshWire = &edk::Object3D::drawHideMeshWire;
        this->functionDrawPolygonWire = &edk::Object3D::drawHidePolygonWire;

        this->hided=true;

        return true;
    }
    return false;
}
//UNHIDE
bool edk::Object3D::unhide(){
    if(this->hided){
        //
        this->functionDrawBoundingBox = &edk::Object3D::drawUnhideBoundingBox;
        this->functionDraw = &edk::Object3D::drawUnhide;
        this->functionDrawOneTexture = &edk::Object3D::drawUnhideOneTexture;
        this->functionDrawOneTextureWithLight = &edk::Object3D::drawUnhideOneTextureWithLight;
        this->functionDrawWithoutMaterial = &edk::Object3D::drawUnhideWithoutMaterial;
        this->functionDrawWithoutMaterialWithLight = &edk::Object3D::drawUnhideWithoutMaterialWithLight;
        this->functionDrawWire = &edk::Object3D::drawUnhideWire;
        this->functionDrawWirePolygon = &edk::Object3D::drawUnhideWirePolygon;
        this->functionDrawNormals = &edk::Object3D::drawUnhideNormals;
        this->functionDrawNormalsWithColor = &edk::Object3D::drawUnhideNormalsWithColor;
        this->functionDrawMesh = &edk::Object3D::drawUnhideMesh;
        this->functionDrawPolygon = &edk::Object3D::drawUnhidePolygon;
        this->functionDrawMeshOneTexture = &edk::Object3D::drawUnhideMeshOneTexture;
        this->functionDrawPolygonOneTexture = &edk::Object3D::drawUnhidePolygonOneTexture;
        this->functionDrawMeshOneTextureWithLight = &edk::Object3D::drawUnhideMeshOneTextureWithLight;
        this->functionDrawPolygonOneTextureWithLight = &edk::Object3D::drawUnhidePolygonOneTextureWithLight;
        this->functionDrawMeshWithoutMaterial = &edk::Object3D::drawUnhideMeshWithoutMaterial;
        this->functionDrawPolygonWithoutMaterial = &edk::Object3D::drawUnhidePolygonWithoutMaterial;
        this->functionDrawMeshWithoutMaterialWithLight = &edk::Object3D::drawUnhideMeshWithoutMaterialWithLight;
        this->functionDrawPolygonWithoutMaterialWithLight = &edk::Object3D::drawUnhidePolygonWithoutMaterialWithLight;
        this->functionDrawMeshWire = &edk::Object3D::drawUnhideMeshWire;
        this->functionDrawPolygonWire = &edk::Object3D::drawUnhidePolygonWire;

        this->hided=false;

        return true;
    }
    return false;
}

bool edk::Object3D::getHided(){
    return this->hided;
}
bool edk::Object3D::isHided(){
    return this->hided;
}
bool edk::Object3D::areHided(){
    return this->hided;
}
bool edk::Object3D::isUnhided(){
    return !this->hided;
}
bool edk::Object3D::areUnhided(){
    return !this->hided;
}

//play all mesh animations
void edk::Object3D::playMeshAnimations(){
    edk::uint32 size = this->meshes.size();edkEnd();
    edk::shape::Mesh3D* mesh;edkEnd();
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
bool edk::Object3D::playMeshAnimations(edk::uchar32 position){
    edk::shape::Mesh3D* mesh = this->meshes.getMesh(position);edkEnd();
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
void edk::Object3D::pauseMeshAnimations(){
    edk::uint32 size = this->meshes.size();edkEnd();
    edk::shape::Mesh3D* mesh;edkEnd();
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
bool edk::Object3D::pauseMeshAnimations(edk::uchar32 position){
    edk::shape::Mesh3D* mesh = this->meshes.getMesh(position);edkEnd();
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
void edk::Object3D::updateMeshAnimations(){
    //update mesh animations
    edk::uint32 size = this->meshes.size();edkEnd();
    edk::shape::Mesh3D *mesh;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        mesh = this->meshes.getMesh(i);edkEnd();
        if(mesh){
            mesh->updateFramesAnimations();edkEnd();
        }
    }
}
void edk::Object3D::updateMeshAnimations(edk::float32 seconds){
    //update mesh animations
    edk::uint32 size = this->meshes.size();edkEnd();
    edk::shape::Mesh3D *mesh;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.haveCreateMesh(i)){
            mesh = this->meshes.getMesh(i);edkEnd();
            if(mesh){
                mesh->updateFramesAnimations(seconds);edkEnd();
            }
        }
    }
}
bool edk::Object3D::updateMeshAnimationsFromPosition(edk::uchar32 position){
    edk::shape::Mesh3D* mesh = this->meshes.getMesh(position);edkEnd();
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
bool edk::Object3D::updateMeshAnimationsFromPosition(edk::uchar32 position,edk::float32 seconds){
    edk::shape::Mesh3D* mesh = this->meshes.getMesh(position);edkEnd();
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
bool edk::Object3D::updateAnimations(){
    bool ret=edk::Object3DValues::updateAnimations();edkEnd();
    this->updateMeshAnimations();edkEnd();
    this->updateChildremsAnimations();
    return ret;
}
bool edk::Object3D::updateAnimations(edk::float32 seconds){
    bool ret=edk::Object3DValues::updateAnimations(seconds);edkEnd();
    this->updateMeshAnimations(seconds);edkEnd();
    this->updateChildremsAnimations(seconds);
    return ret;
}

//ACTIONS
//play actions
void edk::Object3D::playForwardActions(){
    /*
    this->actions.playForward();edkEnd();
    */
}
void edk::Object3D::playForwardInActions(edk::float32 /*second*/){
    /*
    this->actions.playForwardIn(second);edkEnd();
    */
}
void edk::Object3D::pauseActions(){
    /*
    this->actions.pause();edkEnd();
    */
}
void edk::Object3D::stopActions(){
    /*
    this->actions.stop();edkEnd();
    */
}
//set loop
void edk::Object3D::setLoopActions(bool /*loop*/){
    /*
    this->actions.setLoop(loop);edkEnd();
    */
}
void edk::Object3D::loopOnActions(){
    /*
    this->actions.loopOn();edkEnd();
    */
}
void edk::Object3D::loopOffActions(){
    /*
    this->actions.loopOff();edkEnd();
    */
}

//return if are playing
bool edk::Object3D::isPlayingActions(){
    /*
    return this->actions.isPlaying();edkEnd();
    */
    return false;
}
bool edk::Object3D::isPausedActions(){
    /*
    return this->actions.isPaused();edkEnd();
    */
    return false;
}
//update actions
void edk::Object3D::updateActions(){
    /*
    this->actions.update();edkEnd();
    */
}
//remove actions
void edk::Object3D::removeAllActions(){
    /*
    this->actions.clean();edkEnd();
    */
}
void edk::Object3D::cleanAllActions(){
    /*
    this->actions.clean();edkEnd();
    */
}
bool edk::Object3D::removeActionSecond(edk::float32 /*second*/){
    /*
    return this->actions.removeSecond(second);edkEnd();
    */
    return false;
}
//Add zero action
bool edk::Object3D::actionZero(edk::float32 /*second*/){
    /*
    return this->actions.addAction(second,new edk::ActionZero);edkEnd();
    */
    return false;
}
//add move action
bool edk::Object3D::actionSetPosition(edk::float32 /*second*/,edk::vec3f32 /*position*/){
    /*
    return this->actions.addAction(second,new edk::Object3D::ActionPosition(this,position));edkEnd();
    */
    return false;
}
bool edk::Object3D::actionSetPosition(edk::float32 /*second*/,edk::float32 /*x*/,edk::float32 /*y*/){
    /*
    return this->actionSetPosition(second,edk::vec3f32(x,y));edkEnd();
    */
    return false;
}
//add move action
bool edk::Object3D::actionMove(edk::float32 /*second*/,edk::float32 /*duration*/, edk::vec3f32 /*position*/){
    /*
    //create the action
    if(this->actions.addAction(second,new edk::Object3D::ActionMove(this,duration,position))){
        this->actions.addZeroAction(second+duration);edkEnd();
        return true;
    }
    */
    return false;
}
bool edk::Object3D::actionMove(edk::float32 /*second*/,edk::float32 /*duration*/, edk::float32 /*x*/,edk::float32 /*y*/){
    /*
    return this->actionMove(second,duration, edk::vec3f32(x,y));edkEnd();
    */
    return false;
}
bool edk::Object3D::actionMoveTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::vec3f32 /*position*/){
    /*
    return this->actionMove(start,end-start, position);edkEnd();
    */
    return false;
}
bool edk::Object3D::actionMoveTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::float32 /*x*/,edk::float32 /*y*/){
    /*
    return this->actionMove(start,end-start,x,y);edkEnd();
    */
    return false;
}
//add scale action
bool edk::Object3D::actionSetSize(edk::float32 /*second*/,edk::size3f32 /*size*/){
    /*
    //create the action
    return this->actions.addAction(second,new edk::Object3D::ActionSetSize(this,size));edkEnd();
    */
    return false;
}
bool edk::Object3D::actionSetSize(edk::float32 /*second*/,
                                  edk::float32 /*width*/,
                                  edk::float32 /*height*/,
                                  edk::float32 /*length*/
                                  ){
    /*
    return this->actionSetSize(second,edk::size3f32(width,height));edkEnd();
    */
    return false;
}
bool edk::Object3D::actionSetSize(edk::float32 /*second*/,edk::float32 /*size*/){
    /*
    return this->actionSetSize(second,size,size);edkEnd();
    */
    return false;
}
//add scale action
bool edk::Object3D::actionScale(edk::float32 /*second*/,edk::float32 /*duration*/, edk::size3f32 /*size*/){
    /*
    //create the action
    if(this->actions.addAction(second,new edk::Object3D::ActionSize(this,duration,size))){
        this->actions.addZeroAction(second+duration);edkEnd();
        return true;
    }
    */
    return false;
}
bool edk::Object3D::actionScale(edk::float32 /*second*/,
                                edk::float32 /*duration*/,
                                edk::float32 /*width*/,
                                edk::float32 /*height*/,
                                edk::float32 /*length*/
                                ){
    /*
    return this->actionScale(second,duration, edk::size3f32( width,height));edkEnd();
    */
    return false;
}
bool edk::Object3D::actionScale(edk::float32 /*second*/,edk::float32 /*duration*/, edk::float32 /*size*/){
    /*
    return this->actionScale(second,duration, size,size);edkEnd();
    */
    return false;
}
bool edk::Object3D::actionScaleTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::size3f32 /*size*/){
    /*
    return this->actionScale(start,end-start, size);edkEnd();
    */
    return false;
}
bool edk::Object3D::actionScaleTo(edk::float32 /*start*/,
                                  edk::float32 /*end*/,
                                  edk::float32 /*width*/,
                                  edk::float32 /*height*/,
                                  edk::float32 /*length*/
                                  ){
    /*
    return this->actionScale(start,end-start, width,height);edkEnd();
    */
    return false;
}
bool edk::Object3D::actionScaleTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::float32 /*size*/){
    /*
    return this->actionScale(start,end-start, size);edkEnd();
    */
    return false;
}
//add angle action
bool edk::Object3D::actionSetAngle(edk::float32 /*second*/,edk::float32 /*angle*/){
    /*
    return this->actions.addAction(second,new edk::Object3D::ActionSetAngle(this,angle));edkEnd();
    */
    return false;
}
//add angle action
bool edk::Object3D::actionRotateFor(edk::float32 /*second*/,edk::float32 /*duration*/, edk::float32 /*angle*/){
    /*
    if(this->actions.addAction(second,new edk::Object3D::ActionAngle(this,duration,angle))){
        this->actions.addZeroAction(second);edkEnd();
        return true;
    }
    */
    return false;
}
bool edk::Object3D::actionRotateTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::float32 /*angle*/){
    /*
    return this->actionRotateFor(start,end-start, angle);edkEnd();
    */
    return false;
}
//MESH SPRITE SHEET
bool edk::Object3D::actionPlayName(edk::float32 /*second*/,edk::uint32 /*id*/,edk::char8* /*name*/,bool /*loop*/){
    //
    /*
    return this->actions.addAction(second,new edk::Object3D::ActionMeshName(this,id,name,loop));edkEnd();
    */
    return false;
}
bool edk::Object3D::actionPlayName(edk::float32 /*second*/,edk::uint32 /*id*/,const edk::char8* /*name*/,bool /*loop*/){
    //
    /*
    return actionPlayName(second,id,(edk::char8*)name,loop);edkEnd();
    */
    return false;
}
bool edk::Object3D::actionPlayNameFor(edk::float32 /*second*/,edk::float32 /*duration*/,edk::uint32 /*id*/,edk::char8* /*name*/){
    /*
    if(this->actions.addAction(second,new edk::Object3D::ActionMeshName(this,id,name,true))){
        //add the stop action
        this->actions.addAction(second+duration,new edk::Object3D::ActionMeshStop(this,id));edkEnd();
        return true;
    }
    */
    return false;
}
bool edk::Object3D::actionPlayNameFor(edk::float32 /*second*/,edk::float32 /*duration*/,edk::uint32 /*id*/,const edk::char8* /*name*/){
    /*
    return this->actionPlayNameFor(second,duration,id,(edk::char8*)name);edkEnd();
    */
    return false;
}

//DRAW
//print the mesh
void edk::Object3D::print(){
    edk::Object3DValues::print();

    edk::uint32 size = this->meshes.size();edkEnd();
    edk::shape::Mesh3D* mesh;edkEnd();
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
void edk::Object3D::drawBoundingBox(){
    //test if have a father
    //if(this->father){
    //    //put the transformation on a stack
    //    edk::GU::guPushMatrix();edkEnd();
    //
    //    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);edkEnd();
    //
    //    edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    //    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );edkEnd();
    //    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);edkEnd();
    //    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.size.height);edkEnd();
    //    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.origin.y   );edkEnd();
    //    edk::GU::guEnd();edkEnd();
    //
    //    edk::GU::guPopMatrix();edkEnd();
    //}
    //else{
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);edkEnd();

    this->drawChildremsBackBoundingBox();

    (this->*functionDrawBoundingBox)();

    this->drawChildremsFrontBoundingBox();

    edk::GU::guPopMatrix();edkEnd();
    //}
}
void edk::Object3D::draw(){
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
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBack(haveLight);

    (this->*functionDraw)(haveLight);

    this->drawChildremsFront(haveLight);

    //glEnable(GL_RESCALE_NORMAL);edkEnd();
    edk::GU::guDisable(GU_LIGHTING);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawOneTexture(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackOneTexture();

    (this->*functionDrawOneTexture)();

    this->drawChildremsFrontOneTexture();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawOneTextureWithLight(){
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
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackOneTextureWithLight(haveLight);

    (this->*functionDrawOneTextureWithLight)(haveLight);

    this->drawChildremsFrontOneTextureWithLight(haveLight);

    edk::GU::guDisable(GU_LIGHTING);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawWithoutMaterial(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWithoutMaterial();

    (this->*functionDrawWithoutMaterial)();

    this->drawChildremsFrontWithoutMaterial();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawWithoutMaterialWithLight(){
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
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWithoutMaterialWithLight(haveLight);

    (this->*functionDrawWithoutMaterialWithLight)(haveLight);

    this->drawChildremsFrontWithoutMaterialWithLight(haveLight);

    edk::GU::guDisable(GU_LIGHTING);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawWire(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackWire();

    (this->*functionDrawWire)();

    this->drawChildremsFrontWire();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawWirePolygon(edk::uint32 meshPosition,edk::uint32 polygon){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    (this->*functionDrawWirePolygon)(meshPosition,polygon);

    edk::GU::guPopMatrix();edkEnd();
}
bool edk::Object3D::drawMesh(edk::uint32 meshPosition){
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
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    ret = (this->*functionDrawMesh)(haveLight,meshPosition);

    //glEnable(GL_RESCALE_NORMAL);edkEnd();
    edk::GU::guDisable(GU_LIGHTING);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object3D::drawPolygon(edk::uint32 meshPosition,edk::uint32 polygon){
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
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    ret = (this->*functionDrawPolygon)(haveLight,meshPosition,polygon);

    //glEnable(GL_RESCALE_NORMAL);edkEnd();
    edk::GU::guDisable(GU_LIGHTING);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object3D::drawMeshOneTexture(edk::uint32 meshPosition){
    bool ret = false;edkEnd();
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    ret = (this->*functionDrawMeshOneTexture)(meshPosition);

    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object3D::drawPolygonOneTexture(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret = false;edkEnd();
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    ret = (this->*functionDrawPolygonOneTexture)(meshPosition,polygon);

    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object3D::drawMeshOneTextureWithLight(edk::uint32 meshPosition){
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
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    ret = (this->*functionDrawMeshOneTextureWithLight)(haveLight,meshPosition);

    edk::GU::guDisable(GU_LIGHTING);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object3D::drawPolygonOneTextureWithLight(edk::uint32 meshPosition,edk::uint32 polygon){
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
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    ret = (this->*functionDrawPolygonOneTextureWithLight)(haveLight,meshPosition,polygon);

    edk::GU::guDisable(GU_LIGHTING);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object3D::drawMeshWithoutMaterial(edk::uint32 meshPosition){
    bool ret = false;edkEnd();
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    ret = (this->*functionDrawMeshWithoutMaterial)(meshPosition);

    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object3D::drawPolygonWithoutMaterial(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret = false;edkEnd();
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    ret = (this->*functionDrawPolygonWithoutMaterial)(meshPosition,polygon);

    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object3D::drawMeshWithoutMaterialWithLight(edk::uint32 meshPosition){
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
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    ret = (this->*functionDrawMeshWithoutMaterialWithLight)(haveLight,meshPosition);

    edk::GU::guDisable(GU_LIGHTING);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object3D::drawPolygonWithoutMaterialWithLight(edk::uint32 meshPosition,edk::uint32 polygon){
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
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    ret = (this->*functionDrawPolygonWithoutMaterialWithLight)(haveLight,meshPosition,polygon);

    edk::GU::guDisable(GU_LIGHTING);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object3D::drawMeshWire(edk::uint32 meshPosition){
    bool ret=false;edkEnd();
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    ret = (this->*functionDrawMeshWire)(meshPosition);

    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
bool edk::Object3D::drawPolygonWire(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;edkEnd();
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    ret = (this->*functionDrawPolygonWire)(meshPosition,polygon);

    edk::GU::guPopMatrix();edkEnd();
    return ret;
}
void edk::Object3D::drawNormals(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackNormals();

    (this->*functionDrawNormals)();

    this->drawChildremsFrontNormals();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawNormalsWithColor(edk::color3f32 color){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->drawChildremsBackNormalsWithColor(color);

    (this->*functionDrawNormalsWithColor)(color);

    this->drawChildremsFrontNormalsWithColor(color);

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawNormalsWithColor(edk::float32 r,edk::float32 g,edk::float32 b){
    this->drawNormalsWithColor(edk::color3f32(r,g,b));
}
//draw the mesh with projection matrix
void edk::Object3D::drawWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix){
    if(matrix){
        this->calculateMatrices();edkEnd();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);edkEnd();

        edk::uint32 size = this->meshes.size();edkEnd();
        edk::Object3D::MeshAlloc* value;
        for(edk::uint32 i=0u;i<size;i++){
            value = this->meshes.get(i);edkEnd();
            if(value->getMesh()->material.haveOneTexture()){
                value->getMesh()->drawOneTextureWithMatrix(&this->matrixTransform,&this->matrixTemp);edkEnd();
            }
            else{
                value->getMesh()->drawMultiTextureWithMatrix(&this->matrixTransform,&this->matrixTemp);edkEnd();
            }
        }
    }
}
void edk::Object3D::drawWithMatrixWithoutMaterial(edk::vector::Matrixf32<4u,4u>* matrix){
    if(matrix){
        this->calculateMatrices();edkEnd();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);edkEnd();

        edk::uint32 size = this->meshes.size();edkEnd();
        edk::Object3D::MeshAlloc* value;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            value = this->meshes.get(i);edkEnd();
            value->getMesh()->drawWithoutMaterialWithMatrix(&this->matrixTransform,&this->matrixTemp);edkEnd();
        }
    }
}
void edk::Object3D::drawWithMatrixWithoutMaterialWithLight(edk::vector::Matrixf32<4u,4u>* matrix){
    if(matrix){
        this->calculateMatrices();edkEnd();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);edkEnd();

        bool haveLight=false;edkEnd();edkEnd();

        {
            //edk::vec3f32 temp;edkEnd();
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
        if(haveLight){
            edk::GU::guEnable(GU_LIGHTING);edkEnd();
            edk::uint32 size = this->meshes.size();edkEnd();
            edk::Object3D::MeshAlloc* value;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                value = this->meshes.get(i);edkEnd();
                value->getMesh()->drawWithoutMaterialWithMatrix(&this->matrixTransform,&this->matrixTemp);edkEnd();
            }
            edk::GU::guDisable(GU_LIGHTING);edkEnd();
        }
        else{
            edk::uint32 size = this->meshes.size();edkEnd();
            edk::Object3D::MeshAlloc* value;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                value = this->meshes.get(i);edkEnd();
                value->getMesh()->drawWithoutMaterialWithMatrix(&this->matrixTransform,&this->matrixTemp);edkEnd();
            }
        }
    }
}
void edk::Object3D::drawWireWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix){
    if(matrix){
        this->calculateMatrices();edkEnd();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);edkEnd();

        edk::uint32 size = this->meshes.size();edkEnd();
        edk::Object3D::MeshAlloc* value;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            value = this->meshes.get(i);edkEnd();
            value->getMesh()->drawWireWithMatrix(&this->matrixTransform,&this->matrixTemp);edkEnd();
        }
    }
}
void edk::Object3D::drawNormalsWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix){
    if(matrix){
        this->calculateMatrices();edkEnd();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);edkEnd();

        edk::uint32 size = this->meshes.size();edkEnd();
        edk::Object3D::MeshAlloc* value;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            value = this->meshes.get(i);edkEnd();
            value->getMesh()->drawWireWithMatrix(&this->matrixTransform,&this->matrixTemp);edkEnd();
        }
    }
}
void edk::Object3D::drawNormalsWithMatrixWithColor(edk::vector::Matrixf32<4u,4u>* matrix,edk::color3f32 color){
    if(matrix){
        this->calculateMatrices();edkEnd();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);edkEnd();

        edk::uint32 size = this->meshes.size();edkEnd();
        edk::Object3D::MeshAlloc* value;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            value = this->meshes.get(i);edkEnd();
            value->getMesh()->drawWireWithColorWithMatrix(&this->matrixTransform,&this->matrixTemp,edk::color4f32(color.r,color.g,color.b,1.f));edkEnd();
        }
    }
}
void edk::Object3D::drawNormalsWithMatrixWithColor(edk::vector::Matrixf32<4u,4u>* matrix,edk::float32 r,edk::float32 g,edk::float32 b){
    if(matrix){
        this->calculateMatrices();edkEnd();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);edkEnd();

        edk::uint32 size = this->meshes.size();edkEnd();
        edk::Object3D::MeshAlloc* value;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            value = this->meshes.get(i);edkEnd();
            value->getMesh()->drawWireWithColorWithMatrix(&this->matrixTransform,&this->matrixTemp,edk::color4f32(r,g,b,1.f));edkEnd();
        }
    }
}

//draw the pivo
void edk::Object3D::drawPivo(edk::float32 size,edk::color3f32 color){
    if(this->childremsBack.size()){
        edk::GU::guPushMatrix();edkEnd();
        //add translate
        edk::GU::guTranslate3f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateZf32(this->angle.x);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->size);edkEnd();
        //set the pivo
        edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();
        this->drawChildremsBackPivo(size,color);
        edk::GU::guPopMatrix();edkEnd();
    }
    edk::Object3D::drawPivoInPosition(this->position,size,color);
    if(this->childremsFront.size()){
        edk::GU::guPushMatrix();edkEnd();
        //add translate
        edk::GU::guTranslate3f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateZf32(this->angle.x);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->size);edkEnd();
        //set the pivo
        edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();
        this->drawChildremsFrontPivo(size,color);
        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::Object3D::drawPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();
    if(this->childremsBack.size()){
        this->drawChildremsBackPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();edkEnd();


    edk::GU::guPushMatrix();edkEnd();
    //add translate
    //edk::GU::guTranslate3f32(this->position);edkEnd();

    edk::Object3D::drawPivoInPosition(this->position,size,edk::color3f32(r,g,b));

    edk::GU::guPopMatrix();edkEnd();

    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();
    if(this->childremsFront.size()){
        this->drawChildremsFrontPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawPivoInPosition(edk::vec3f32 position,edk::float32 size,edk::color3f32 color){
    //
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(position);edkEnd();
    //add scale
    edk::GU::guScale3f32(edk::size3f32(size,size,size));edkEnd();

    //lineSize
    edk::GU::guLineWidth(3);edkEnd();

    //set the colors
    edk::GU::guColor3f32(color);edkEnd();
    //draw the lines
    edk::GU::guBegin(GU_LINES);edkEnd();
    //LINE 1
    edk::GU::guVertex3f32(-0.5f,-0.5f,-0.5f);edkEnd();
    edk::GU::guVertex3f32( 0.5f, 0.5f, 0.5f);edkEnd();
    //LINE 2
    edk::GU::guVertex3f32(-0.5f, 0.5f, 0.5f);edkEnd();
    edk::GU::guVertex3f32( 0.5f,-0.5f,-0.5f);edkEnd();
    edk::GU::guEnd();edkEnd();

    //lineSize
    edk::GU::guLineWidth(1);edkEnd();

    //
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawPivoInPosition(edk::float32 x,edk::float32 y,edk::float32 z,
                                       edk::float32 size,
                                       edk::color3f32 color
                                       ){
    edk::Object3D::drawPivoInPosition(edk::vec3f32(x,y,z),size,color);
}
void edk::Object3D::drawPivoInPosition(edk::float32 x,edk::float32 y,edk::float32 z,
                                       edk::float32 size,
                                       edk::float32 r,edk::float32 g,edk::float32 b
                                       ){
    edk::Object3D::drawPivoInPosition(edk::vec3f32(x,y,z),size,edk::color3f32(r,g,b));
}

//XML
bool edk::Object3D::writeToXML(edk::XML* xml,edk::uint32 id){
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
                        edk::shape::Mesh3D* mesh;edkEnd();
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
                        temp = edk::String::float32ToStr(this->pivo.z);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"pivoZ",temp);edkEnd();
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
                        temp = edk::String::float32ToStr(this->position.z);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"positionZ",temp);edkEnd();
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
                        temp = edk::String::float32ToStr(this->size.length);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"sizeL",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        //angle
                        temp = edk::String::float32ToStr(this->angle.x);edkEnd();
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
bool edk::Object3D::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    edk::shape::Mesh3D* mesh;edkEnd();
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
                    this->pivo = edk::vec3f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoX")),
                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoY")),
                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoZ"))
                                              );edkEnd();
                    //read the object values
                    //position
                    this->position = edk::vec3f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionX")),
                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionY")),
                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionZ"))
                                                  );edkEnd();
                    //size
                    this->size = edk::size3f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeW")),
                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeH")),
                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeZ"))
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
bool edk::Object3D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
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
                    edk::shape::Mesh3D* mesh;edkEnd();
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
                    this->pivo = edk::vec3f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoX")),
                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoY")),
                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoZ"))
                                              );edkEnd();
                    //read the object values
                    //position
                    this->position = edk::vec3f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionX")),
                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionY")),
                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionZ"))
                                                  );edkEnd();
                    //size
                    this->size = edk::size3f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeW")),
                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeH")),
                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeL"))
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

//connect another object into this
bool edk::Object3D::connectObjectBack(edk::Object3D* obj){
    if(obj){
        if(!obj->father){
            if(this->childremsBack.add(obj)){
                obj->father=this;

                obj->newSize = edk::size3f32(1.f / this->size.width,1.f / this->size.height,1.f / this->size.length);

                //translate the object to be connected with the another
                obj->connectedPosition=this->position*-1.f;
                obj->connectedSize= edk::size3f32(1.f/this->size.width,1.f/this->size.height,1.f/this->size.length);
                obj->connectedAngle=this->angle*-1.f;

                //save the position
                obj->saveTransformation();

                return true;
            }
        }
    }
    return false;
}
bool edk::Object3D::updateConnectedObjectBackValues(edk::Object3D* obj){
    if(obj){
        if(obj->father == this){
            if(this->childremsBack.haveElement(obj)){
                edk::shape::Mesh3D* mesh;edkEnd();

                //update the values
                obj->matrixTransform.setIdentity();
                obj->updateValuesFromFather(&obj->matrixTransform);

                if(obj->meshes.size()){
                    mesh = obj->meshes.getMesh(0u);edkEnd();
                    if(mesh){
                        //calculate the position
                        obj->position = mesh->generateBoundingPoint(edk::vec3f32(0.f,0.f,0.f),&obj->matrixTransform);edkEnd();
                        //calculate the angle
                        edk::vec3f32 temp;
                        temp = mesh->generateBoundingPoint(edk::vec3f32(1.f,0.f,0.f),&obj->matrixTransform);
                        obj->angle+=edk::Math::getAngle(temp.x-obj->position.x,
                                                        temp.y-obj->position.y
                                                        );

                        while(obj->angle.x<0.f){
                            obj->angle.x+=360.f;
                        }
                        while(obj->angle.x>360.f){
                            obj->angle.x-=360.f;
                        }
                        while(obj->angle.y<0.f){
                            obj->angle.y+=360.f;
                        }
                        while(obj->angle.y>360.f){
                            obj->angle.y-=360.f;
                        }
                        while(obj->angle.z<0.f){
                            obj->angle.z+=360.f;
                        }
                        while(obj->angle.z>360.f){
                            obj->angle.z-=360.f;
                        }
                    }
                }
                return true;
            }
        }
    }
    return false;
}
edk::vec3f32 edk::Object3D::getConnectedObjectBackWorldPosition(edk::Object3D* obj){
    edk::vec3f32 ret;
    if(obj){
        if(obj->father == this){
            if(this->childremsBack.haveElement(obj)){
                edk::shape::Mesh3D* mesh;edkEnd();

                //update the values
                obj->matrixTransform.setIdentity();
                obj->updateValuesFromFather(&obj->matrixTransform);

                if(obj->meshes.size()){
                    mesh = obj->meshes.getMesh(0u);edkEnd();
                    if(mesh){
                        //calculate the position
                        ret = mesh->generateBoundingPoint(edk::vec3f32(0.f,0.f,0.f),&obj->matrixTransform);edkEnd();
                    }
                }
            }
        }
    }
    return ret;
}
bool edk::Object3D::haveConnectedObjectBack(edk::Object3D* obj){
    if(obj){
        if(obj->father == this){
            if(this->childremsBack.haveElement(obj)){
                return true;
            }
        }
    }
    return false;
}
bool edk::Object3D::disconnectObjectBack(edk::Object3D* obj){
    if(obj){
        if(obj->father == this){
            if(this->childremsBack.remove(obj)){
                obj->father=NULL;
                obj->connectedLoadIdentityValues();
                obj->newSize=1.f;
                return true;
            }
        }
    }
    return false;
}
void edk::Object3D::cleanConnectedObjectsBack(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
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
bool edk::Object3D::connectObjectFront(edk::Object3D* obj){
    if(obj){
        if(!obj->father){
            if(this->childremsFront.add(obj)){
                obj->father=this;

                obj->newSize = edk::size3f32(1.f / this->size.width,1.f / this->size.height,1.f / this->size.length);

                //translate the object to be connected with the another
                obj->connectedPosition=this->position*-1.f;
                obj->connectedSize= edk::size3f32(1.f/this->size.width,1.f/this->size.height,1.f/this->size.length);
                obj->connectedAngle=this->angle*-1.f;

                //save the position
                obj->saveTransformation();

                return true;
            }
        }
    }
    return false;
}
bool edk::Object3D::updateConnectedObjectFrontValues(edk::Object3D* obj){
    if(obj){
        if(obj->father == this){
            if(this->childremsFront.haveElement(obj)){
                edk::shape::Mesh3D* mesh;edkEnd();

                //update the values
                obj->matrixTransform.setIdentity();
                obj->updateValuesFromFather(&obj->matrixTransform);

                if(obj->meshes.size()){
                    mesh = obj->meshes.getMesh(0u);edkEnd();
                    if(mesh){
                        //calculate the position
                        obj->position = mesh->generateBoundingPoint(edk::vec3f32(0.f,0.f,0.f),&obj->matrixTransform);edkEnd();
                        //calculate the angle
                        edk::vec3f32 temp = mesh->generateBoundingPoint(edk::vec3f32(1.f,0.f,0.f),&obj->matrixTransform);
                        obj->angle+=edk::Math::getAngle(temp.x-obj->position.x,
                                                        temp.y-obj->position.y
                                                        );
                    }
                }
                return true;
            }
        }
    }
    return false;
}
edk::vec3f32 edk::Object3D::getConnectedObjectFrontWorldPosition(edk::Object3D* obj){
    edk::vec3f32 ret;
    if(obj){
        if(obj->father == this){
            if(this->childremsFront.haveElement(obj)){
                edk::shape::Mesh3D* mesh;edkEnd();

                //update the values
                obj->matrixTransform.setIdentity();
                obj->updateValuesFromFather(&obj->matrixTransform);

                if(obj->meshes.size()){
                    mesh = obj->meshes.getMesh(0u);edkEnd();
                    if(mesh){
                        //calculate the position
                        ret = mesh->generateBoundingPoint(edk::vec3f32(0.f,0.f,0.f),&obj->matrixTransform);edkEnd();
                    }
                }
            }
        }
    }
    return ret;
}
bool edk::Object3D::haveConnectedObjectFront(edk::Object3D* obj){
    if(obj){
        if(obj->father == this){
            if(this->childremsFront.haveElement(obj)){
                return true;
            }
        }
    }
    return false;
}
bool edk::Object3D::disconnectObjectFront(edk::Object3D* obj){
    if(obj){
        if(obj->father == this){
            if(this->childremsFront.remove(obj)){
                obj->father=NULL;
                obj->connectedLoadIdentityValues();
                obj->newSize=1.f;
                return true;
            }
        }
    }
    return false;
}
void edk::Object3D::cleanConnectedObjectsFront(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
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
bool edk::Object3D::updateConnectedObjectValues(edk::Object3D* obj){
    if(obj){
        if(obj->father == this){
            if(this->childremsBack.haveElement(obj) || this->childremsFront.haveElement(obj)){
                edk::shape::Mesh3D* mesh;edkEnd();

                //update the values
                obj->matrixTransform.setIdentity();
                obj->updateValuesFromFather(&obj->matrixTransform);

                if(obj->meshes.size()){
                    mesh = obj->meshes.getMesh(0u);edkEnd();
                    if(mesh){
                        //calculate the position
                        obj->position = mesh->generateBoundingPoint(edk::vec3f32(0.f,0.f,0.f),&obj->matrixTransform);edkEnd();
                        //calculate the angle
                        edk::vec3f32 temp = mesh->generateBoundingPoint(edk::vec3f32(1.f,0.f,0.f),&obj->matrixTransform);
                        obj->angle+=edk::Math::getAngle(temp.x-obj->position.x,
                                                        temp.y-obj->position.y
                                                        );
                    }
                }
                return true;
            }
        }
    }
    return false;
}
edk::vec3f32 edk::Object3D::getConnectedObjectWorldPosition(edk::Object3D* obj){
    edk::vec3f32 ret;
    if(obj){
        if(obj->father == this){
            if(this->childremsBack.haveElement(obj)||this->childremsFront.haveElement(obj)){
                edk::shape::Mesh3D* mesh;edkEnd();

                //update the values
                obj->matrixTransform.setIdentity();
                obj->updateValuesFromFather(&obj->matrixTransform);

                if(obj->meshes.size()){
                    mesh = obj->meshes.getMesh(0u);edkEnd();
                    if(mesh){
                        //calculate the position
                        ret = mesh->generateBoundingPoint(edk::vec3f32(0.f,0.f,0.f),&obj->matrixTransform);edkEnd();
                    }
                }
            }
        }
    }
    return ret;
}
bool edk::Object3D::haveConnectedObject(edk::Object3D* obj){
    if(obj){
        if(obj->father == this){
            if(this->childremsBack.haveElement(obj)||this->childremsFront.haveElement(obj)){
                return true;
            }
        }
    }
    return false;
}
bool edk::Object3D::disconnectObject(edk::Object3D* obj){
    return (this->disconnectObjectBack(obj) || this->disconnectObjectFront(obj));
}
void edk::Object3D::cleanConnectedObjects(){
    this->cleanConnectedObjectsBack();
    this->cleanConnectedObjectsFront();
}

bool edk::Object3D::cloneFrom(edk::Object3D* obj){
    if(obj){
        this->cleanSelected();edkEnd();
        this->cleanMeshes();edkEnd();

        //copy the meshs
        edk::uint32 size = obj->meshes.size();edkEnd();
        edk::shape::Mesh3D* temp = NULL;edkEnd();
        edk::shape::Mesh3D* mesh = NULL;edkEnd();
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
                    edk::Object3D::ActionPosition* temp = (edk::Object3D::ActionPosition*)obj->actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object3D::ActionPosition(this,temp->getPosition()));edkEnd();
                    break;
                }
                case 2u:
                {
                    //ActionMove
                    edk::Object3D::ActionMove* temp = (edk::Object3D::ActionMove*)obj->actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object3D::ActionMove(this,temp->getDuration(),temp->getPosition()));edkEnd();
                    break;
                }
                case 3u:
                {
                    //ActionSetSize
                    edk::Object3D::ActionSetSize* temp = (edk::Object3D::ActionSetSize*)obj->actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object3D::ActionSetSize(this,temp->getSize()));edkEnd();
                    break;
                }
                case 4u:
                {
                    //ActionSize
                    edk::Object3D::ActionSize* temp = (edk::Object3D::ActionSize*)obj->actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object3D::ActionSize(this,temp->getDuration(),temp->getSize()));edkEnd();
                    break;
                }
                case 5u:
                {
                    //ActionSetAngle
                    edk::Object3D::ActionSetAngle* temp = (edk::Object3D::ActionSetAngle*)obj->actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object3D::ActionSetAngle(this,temp->getAngle()));edkEnd();
                    break;
                }
                case 6u:
                {
                    //ActionAngle
                    edk::Object3D::ActionAngle* temp = (edk::Object3D::ActionAngle*)obj->actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object3D::ActionAngle(this,temp->getDuration(),temp->getAngle()));edkEnd();
                    break;
                }
                case 7u:
                {
                    //ActionMeshName
                    edk::Object3D::ActionMeshName* temp = (edk::Object3D::ActionMeshName*)obj->actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object3D::ActionMeshName(this,temp->getId(),temp->getName(),temp->getLoop()));edkEnd();
                    break;
                }
                case 8u:
                {
                    //ActionMeshStop
                    edk::Object3D::ActionMeshStop* temp = (edk::Object3D::ActionMeshStop*)obj->actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object3D::ActionMeshStop(this,temp->getId()));edkEnd();
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
bool edk::Object3D::addMeshFrom(edk::Object3D* obj){
    if(obj){
        //copy the meshs
        edk::uint32 size = obj->meshes.size();edkEnd();
        edk::shape::Mesh3D* temp = NULL;edkEnd();
        edk::shape::Mesh3D* mesh = NULL;edkEnd();
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
        return true;
    }
    return false;
}
bool edk::Object3D::addMeshFrom(edk::shape::Mesh3D* mesh){
    if(mesh){
        edk::shape::Mesh3D* temp = this->newMesh();edkEnd();
        if(temp){
            //*mesh = *temp;edkEnd();
            temp->cloneFrom(mesh);edkEnd();
            return true;
        }
    }
    return false;
}
