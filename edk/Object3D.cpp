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
    this->classThis=NULL;
    this->Constructor();
}

edk::Object3D::~Object3D(){
    this->Destructor();
}

//Draw function
//HIDE
void edk::Object3D::drawHideBoundingBox(){}
void edk::Object3D::drawHide(bool ){}
void edk::Object3D::drawVBOHide(bool ){}
void edk::Object3D::drawHideOneTexture(){}
void edk::Object3D::drawHideOneTextureWithLight(bool ){}
void edk::Object3D::drawHideWithoutMaterial(){}
void edk::Object3D::drawHideWithoutMaterialWithLight(bool ){}
void edk::Object3D::drawHideWire(){}
void edk::Object3D::drawVBOHideWire(){}
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
    edk::GU::guBegin(GU_LINE_LOOP);
    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   ,this->boundingBox.origin.z   );
    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.size.height,this->boundingBox.size.length);
    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.size.height,this->boundingBox.size.length);
    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.origin.y   ,this->boundingBox.origin.z   );
    edk::GU::guEnd();
}
void edk::Object3D::drawUnhide(bool haveLight){
    edk::shape::Mesh3D* mesh;
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
void edk::Object3D::drawVBOUnhide(bool haveLight){
    edk::shape::Mesh3D* mesh;
    if(haveLight){
        edk::uint32 size = this->meshes.size();
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    mesh->drawVBOOneTexture();
                }
                else{
                    mesh->drawVBOMultiTexture();
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
                    mesh->drawVBOOneTexture();
                }
                else{
                    mesh->drawVBOMultiTexture();
                }
            }
        }
    }
}
void edk::Object3D::drawUnhideOneTexture(){
    edk::shape::Mesh3D* mesh;
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
void edk::Object3D::drawUnhideOneTextureWithLight(bool haveLight){
    edk::shape::Mesh3D* mesh;
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
void edk::Object3D::drawUnhideWithoutMaterial(){
    edk::shape::Mesh3D* mesh;
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
void edk::Object3D::drawUnhideWithoutMaterialWithLight(bool haveLight){
    edk::shape::Mesh3D* mesh;
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
void edk::Object3D::drawUnhideWire(){
    edk::shape::Mesh3D* mesh;
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
void edk::Object3D::drawVBOUnhideWire(){
    edk::shape::Mesh3D* mesh;
    //print all polygonList
    edk::uint32 size = this->meshes.size();
    for(edk::uint32 i=0u;i<size;i++){
        //
        mesh = this->meshes.getMesh(i);
        if(mesh){
            mesh->drawVBOWirePolygons();
        }
    }
}
void edk::Object3D::drawUnhideWirePolygon(edk::uint32 meshPosition,edk::uint32 polygon){
    edk::shape::Mesh3D* mesh = this->meshes.getMesh(meshPosition);
    if(mesh){
        mesh->drawWirePolygon(polygon);
    }
}
void edk::Object3D::drawUnhideNormals(){
    edk::shape::Mesh3D* mesh;
    //print all polygonList
    edk::uint32 size = this->meshes.size();
    for(edk::uint32 i=0u;i<size;i++){
        //
        mesh = this->meshes.getMesh(i);
        if(mesh){
            mesh->drawNormals();
        }
    }
}
void edk::Object3D::drawUnhideNormalsWithColor(edk::color3f32 color){
    edk::shape::Mesh3D* mesh;
    //print all polygonList
    edk::uint32 size = this->meshes.size();
    for(edk::uint32 i=0u;i<size;i++){
        //
        mesh = this->meshes.getMesh(i);
        if(mesh){
            mesh->drawNormalsWithColor(color);
        }
    }
}
bool edk::Object3D::drawUnhideMesh(bool haveLight,edk::uint32 meshPosition){
    bool ret=false;
    edk::shape::Mesh3D* mesh;
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
bool edk::Object3D::drawUnhidePolygon(bool haveLight,edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;
    edk::shape::Mesh3D* mesh;
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
bool edk::Object3D::drawUnhideMeshOneTexture(edk::uint32 meshPosition){
    bool ret=false;
    edk::shape::Mesh3D* mesh;
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
bool edk::Object3D::drawUnhidePolygonOneTexture(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;
    edk::shape::Mesh3D* mesh;
    //
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);
        if(mesh){
            ret = mesh->drawPolygonOneTexture(polygon);
        }
    }
    return ret;
}
bool edk::Object3D::drawUnhideMeshOneTextureWithLight(bool haveLight,edk::uint32 meshPosition){
    bool ret=false;
    edk::shape::Mesh3D* mesh;
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
bool edk::Object3D::drawUnhidePolygonOneTextureWithLight(bool haveLight,edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;
    edk::shape::Mesh3D* mesh;
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
bool edk::Object3D::drawUnhideMeshWithoutMaterial(edk::uint32 meshPosition){
    bool ret=false;
    edk::shape::Mesh3D* mesh;
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
bool edk::Object3D::drawUnhidePolygonWithoutMaterial(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;
    edk::shape::Mesh3D* mesh;
    //print all polygonList
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);
        if(mesh){
            ret = mesh->drawPolygonWithoutMaterial(polygon);
        }
    }
    return ret;
}
bool edk::Object3D::drawUnhideMeshWithoutMaterialWithLight(bool haveLight,edk::uint32 meshPosition){
    bool ret=false;
    edk::shape::Mesh3D* mesh;
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
bool edk::Object3D::drawUnhidePolygonWithoutMaterialWithLight(bool haveLight,edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;
    edk::shape::Mesh3D* mesh;
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
bool edk::Object3D::drawUnhideMeshWire(edk::uint32 meshPosition){
    bool ret=false;
    edk::shape::Mesh3D* mesh;
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
bool edk::Object3D::drawUnhidePolygonWire(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;

    edk::shape::Mesh3D* mesh;
    //print all polygonList
    if(meshPosition<this->meshes.size()){
        mesh = this->meshes.getMesh(meshPosition);
        if(mesh){
            ret = mesh->drawWirePolygon(polygon);
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
        obj = this->childremsBack.get(i);
        obj->updateAnimations();
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->updateAnimations();
    }
}
void edk::Object3D::updateChildremsAnimations(edk::float32 seconds){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
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
bool edk::Object3D::updateValuesFromFather(edk::vector::Matrixf32<4u,4u>* matrixTransform){
    if(matrixTransform){
        if(this->father){
            //calculate the boundingBox from the father
            this->father->updateValuesFromFather(matrixTransform);

            edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);
            edk::Math::generateRotateMatrixZ(this->connectedAngle.x,&this->matrixAngleX);
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);
            edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);
            matrixTransform->multiplyThisWithMatrix(&this->matrixSize);
            matrixTransform->multiplyThisWithMatrix(&this->matrixAngleX);
            matrixTransform->multiplyThisWithMatrix(&this->matrixPosition);
            matrixTransform->multiplyThisWithMatrix(&this->matrixPivo);

            //first copy the matrix
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
            edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
            //translate
            matrixTransform->multiplyThisWithMatrix(&this->matrixPosition);
            //angle
            matrixTransform->multiplyThisWithMatrix(&this->matrixAngleX);
            //scale
            matrixTransform->multiplyThisWithMatrix(&this->matrixSize);
            //Pivo
            matrixTransform->multiplyThisWithMatrix(&this->matrixPivo);
        }
        else{
            //first copy the matrix
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
            edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
            //translate
            matrixTransform->multiplyThisWithMatrix(&this->matrixPosition);
            //angle
            matrixTransform->multiplyThisWithMatrix(&this->matrixAngleX);
            //scale
            matrixTransform->multiplyThisWithMatrix(&this->matrixSize);
            //Pivo
            matrixTransform->multiplyThisWithMatrix(&this->matrixPivo);
        }
        return true;
    }
    return false;
}

void edk::Object3D::Constructor(){
    edk::Object3DValues::Constructor();
    edk::shape::FileOBJ::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->hided=true;
        this->meshes.Constructor();
        this->matrixPosition.Constructor();
        this->matrixPivo.Constructor();
        this->matrixAngleX.Constructor();
        this->matrixSize.Constructor();
        this->matrixTransform.Constructor();
        this->matrixPivo.Constructor();
        this->childremsFront.Constructor();
        this->childremsBack.Constructor();

        //
        this->type=edk::TypeObject3D;
        this->selected=NULL;
        //rotation
        this->angle=0.0f;
        //Scale
        this->size = edk::size3f32(1.f,1.f,1.f);
        /*
    this->actions.setReadXMLActionFunction(&edk::Object3D::readXMLAction);
    */
        this->father=NULL;

        this->newSize=1.f;
        this->loadSaveIdentityValues();

        this->unhide();
    }
}
void edk::Object3D::Destructor(){
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
        this->matrixAngleX.Destructor();
        this->matrixSize.Destructor();
        this->matrixTransform.Destructor();
        this->matrixPivo.Destructor();
        this->childremsFront.Destructor();
        this->childremsBack.Destructor();
    }
    edk::Object3DValues::Destructor();
    edk::shape::FileOBJ::Destructor();
}

void edk::Object3D::calculateMatrices(){
    //generate the matrices
    this->matrixTransform.setIdentity(1.f,0.f);
    edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
    edk::Math::generateRotateMatrixX(this->angle.x,&this->matrixAngleX);
    edk::Math::generateRotateMatrixY(this->angle.y,&this->matrixAngleY);
    edk::Math::generateRotateMatrixZ(this->angle.z,&this->matrixAngleZ);
    edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
    //this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotate);
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleY);
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleZ);
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
    edk::Math::generateTranslateMatrix(this->pivo*-1.f,&this->matrixPosition);
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
}

void edk::Object3D::writeFatherBoundingBox(edk::cubef32* cube,edk::vector::Matrixf32<4u,4u>* transformMat){
    if(this->father){
        //calculate the boundingBox from the father
        this->father->writeFatherBoundingBox(cube,transformMat);

        edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);
        edk::Math::generateRotateMatrixZ(this->connectedAngle.x,&this->matrixAngleX);
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
        //translate
        transformMat->multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        transformMat->multiplyThisWithMatrix(&this->matrixAngleX);
        //scale
        transformMat->multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        transformMat->multiplyThisWithMatrix(&this->matrixPivo);
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
        //translate
        transformMat->multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        transformMat->multiplyThisWithMatrix(&this->matrixAngleX);
        //scale
        transformMat->multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        transformMat->multiplyThisWithMatrix(&this->matrixPivo);
    }
}
bool edk::Object3D::writeBoundingBox(edk::cubef32* cube){
    //multiply the matrix by
    this->matrixTransform.setIdentity();
    if(this->father){
        //calculate the boundingBox from the father
        this->father->writeFatherBoundingBox(cube,&this->matrixTransform);

        edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);
        edk::Math::generateRotateMatrixZ(this->connectedAngle.x,&this->matrixAngleX);
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);
    }


    edk::shape::Mesh3D* mesh;
    edk::uint32 size = this->meshes.size();
    if(size){
        mesh = this->meshes.getMesh(0u);
        if(mesh){
            if(this->father){
                mesh->calculateBoundingBox(cube,&this->matrixTransform);
            }
            else{
                *cube = mesh->generateBoundingBox(&this->matrixTransform);
            }
        }
        for(edk::uint32 i=1u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);
            if(mesh){
                mesh->calculateBoundingBox(cube,&this->matrixTransform);
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

            edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);
            edk::Math::generateRotateMatrixZ(this->connectedAngle.x,&this->matrixAngleX);
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);
            edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);

            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
            edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);
        }
        else{
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
            edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);
        }



        edk::shape::Mesh3D* mesh;
        edk::uint32 size = this->meshes.size();
        if(size){
            mesh = this->meshes.getMesh(0u);
            if(mesh){
                if(this->father){
                    *cube = mesh->generateBoundingBox(&this->matrixTransform);
                }
                else{
                    mesh->calculateBoundingBox(cube,&this->matrixTransform);
                }
            }
            for(edk::uint32 i=1u;i<size;i++){
                //
                mesh = this->meshes.getMesh(i);
                if(mesh){
                    mesh->calculateBoundingBox(cube,&this->matrixTransform);
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
    this->matrixTransform.setIdentity();
    if(this->father){
        //calculate the boundingBox from the father
        this->father->writeFatherBoundingBox(cube,&this->matrixTransform);

        edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);
        edk::Math::generateRotateMatrixZ(this->connectedAngle.x,&this->matrixAngleX);
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);

        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);
    }

    edk::shape::Mesh3D* mesh;
    size = this->meshes.size();
    if(size){
        mesh = this->meshes.getMesh(0u);
        if(mesh){
            if(this->father){
                mesh->calculateBoundingBox(cube,&this->matrixTransform);
            }
            else{
                *cube = mesh->generateBoundingBox(&this->matrixTransform);
            }
        }
        for(edk::uint32 i=1u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);
            if(mesh){
                mesh->calculateBoundingBox(cube,&this->matrixTransform);
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

            edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);
            edk::Math::generateRotateMatrixZ(this->connectedAngle.x,&this->matrixAngleX);
            edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);
            edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);


            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
            edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);
        }
        else{
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
            edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);
        }

        edk::shape::Mesh3D* mesh;
        size = this->meshes.size();
        if(size){
            mesh = this->meshes.getMesh(0u);
            if(mesh){
                if(this->father){
                    *cube = mesh->generateBoundingBox(&this->matrixTransform);
                }
                else{
                    mesh->calculateBoundingBox(cube,&this->matrixTransform);
                }
            }
            for(edk::uint32 i=1u;i<size;i++){
                //
                mesh = this->meshes.getMesh(i);
                if(mesh){
                    mesh->calculateBoundingBox(cube,&this->matrixTransform);
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

        edk::Math::generateScaleMatrix(this->connectedSize,&this->matrixSize);
        edk::Math::generateRotateMatrixZ(this->connectedAngle.x,&this->matrixAngleX);
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixPosition);
        edk::Math::generateTranslateMatrix(this->connectedPivo*-1.0f,&this->matrixPivo);
        transformMat->multiplyThisWithMatrix(&this->matrixSize);
        transformMat->multiplyThisWithMatrix(&this->matrixAngleX);
        transformMat->multiplyThisWithMatrix(&this->matrixPosition);
        transformMat->multiplyThisWithMatrix(&this->matrixPivo);

        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
        //translate
        transformMat->multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        transformMat->multiplyThisWithMatrix(&this->matrixAngleX);
        //scale
        transformMat->multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        transformMat->multiplyThisWithMatrix(&this->matrixPivo);
    }
    else{
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
        //translate
        transformMat->multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        transformMat->multiplyThisWithMatrix(&this->matrixAngleX);
        //scale
        transformMat->multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        transformMat->multiplyThisWithMatrix(&this->matrixPivo);
    }
}

//Function to read the actions
edk::Action* edk::Object3D::readXMLAction(edk::classID /*thisPointer*/,edk::uint32 /*actionCode*/){
    /*
    switch(actionCode){
    case 1u:
    {
        //ActionPosition
        return new edk::Object3D::ActionPosition((edk::Object3D*)thisPointer,edk::vec3f32(0,0));
        break;
    }
    case 2u:
    {
        //ActionMove
        return new edk::Object3D::ActionMove((edk::Object3D*)thisPointer,0,edk::vec3f32(0,0));
        break;
    }
    case 3u:
    {
        //ActionSetSize
        return new edk::Object3D::ActionSetSize((edk::Object3D*)thisPointer,edk::size3f32(1,1));
        break;
    }
    case 4u:
    {
        //ActionSize
        return new edk::Object3D::ActionSize((edk::Object3D*)thisPointer,0,edk::size3f32(1,1));
        break;
    }
    case 5u:
    {
        //ActionSetAngle
        return new edk::Object3D::ActionSetAngle((edk::Object3D*)thisPointer,0);
        break;
    }
    case 6u:
    {
        //ActionAngle
        return new edk::Object3D::ActionAngle((edk::Object3D*)thisPointer,0,0);
        break;
    }
    case 7u:
    {
        //ActionMeshName
        return new edk::Object3D::ActionMeshName((edk::Object3D*)thisPointer,0,NULL,false);
        break;
    }
    case 8u:
    {
        //ActionMeshStop
        return new edk::Object3D::ActionMeshStop((edk::Object3D*)thisPointer,0);
        break;
    }
    }
    */
    return new edk::ActionZero();
}

//draw the mesh
void edk::Object3D::drawChildremsBackBoundingBox(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildBoundingBox();
    }
}
void edk::Object3D::drawChildBackBoundingBox(){
    //test if have a father
    //if(this->father){
    //    //put the transformation on a stack
    //    edk::GU::guPushMatrix();
    //
    //    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);
    //
    //    edk::GU::guBegin(GU_LINE_LOOP);
    //    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );
    //    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);
    //    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.size.height);
    //    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.origin.y   );
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
void edk::Object3D::drawChildremsFrontBoundingBox(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildBoundingBox();
    }
}
void edk::Object3D::drawChildFrontBoundingBox(){
    //test if have a father
    //if(this->father){
    //    //put the transformation on a stack
    //    edk::GU::guPushMatrix();
    //
    //    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);
    //
    //    edk::GU::guBegin(GU_LINE_LOOP);
    //    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );
    //    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);
    //    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.size.height);
    //    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.origin.y   );
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
void edk::Object3D::drawChildremsBoundingBox(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
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
void edk::Object3D::drawChildBoundingBox(){
    //test if have a father
    //if(this->father){
    //    //put the transformation on a stack
    //    edk::GU::guPushMatrix();
    //
    //    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);
    //
    //    edk::GU::guBegin(GU_LINE_LOOP);
    //    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );
    //    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);
    //    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.size.height);
    //    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.origin.y   );
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
void edk::Object3D::drawChildremsBack(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChild(haveLight);
    }
}
void edk::Object3D::drawVBOChildremsBack(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawVBOChild(haveLight);
    }
}
void edk::Object3D::drawChildBack(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBack(haveLight);

    (this->*functionDraw)(haveLight);

    //glEnable(GL_RESCALE_NORMAL);
    edk::GU::guPopMatrix();
}
void edk::Object3D::drawVBOChildBack(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawVBOChildremsBack(haveLight);

    (this->*functionDrawVBO)(haveLight);

    //glEnable(GL_RESCALE_NORMAL);
    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsFront(bool haveLight){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChild(haveLight);
    }
}
void edk::Object3D::drawVBOChildremsFront(bool haveLight){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawVBOChild(haveLight);
    }
}
void edk::Object3D::drawChildFront(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    (this->*functionDraw)(haveLight);

    this->drawChildremsFront(haveLight);
    //glEnable(GL_RESCALE_NORMAL);
    edk::GU::guPopMatrix();
}
void edk::Object3D::drawVBOChildFront(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    (this->*functionDrawVBO)(haveLight);

    this->drawVBOChildremsFront(haveLight);
    //glEnable(GL_RESCALE_NORMAL);
    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildrems(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
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
void edk::Object3D::drawChild(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBack(haveLight);

    (this->*functionDraw)(haveLight);

    this->drawChildremsFront(haveLight);
    //glEnable(GL_RESCALE_NORMAL);
    edk::GU::guPopMatrix();
}
void edk::Object3D::drawVBOChild(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawVBOChildremsBack(haveLight);

    (this->*functionDrawVBO)(haveLight);

    this->drawVBOChildremsFront(haveLight);
    //glEnable(GL_RESCALE_NORMAL);
    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildVBO(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawVBOChildremsBack(haveLight);

    (this->*functionDrawVBO)(haveLight);

    this->drawVBOChildremsFront(haveLight);
    //glEnable(GL_RESCALE_NORMAL);
    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsBackOneTexture(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildOneTexture();
    }
}
void edk::Object3D::drawChildBackOneTexture(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackOneTexture();

    (this->*functionDrawOneTexture)();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsFrontOneTexture(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildOneTexture();
    }
}
void edk::Object3D::drawChildFrontOneTexture(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    (this->*functionDrawOneTexture)();

    this->drawChildremsFrontOneTexture();
    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsOneTexture(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
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
void edk::Object3D::drawChildOneTexture(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackOneTexture();

    (this->*functionDrawOneTexture)();

    this->drawChildremsFrontOneTexture();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsBackOneTextureWithLight(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildOneTextureWithLight(haveLight);
    }
}
void edk::Object3D::drawChildBackOneTextureWithLight(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackOneTextureWithLight(haveLight);

    (this->*functionDrawOneTextureWithLight)(haveLight);

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsFrontOneTextureWithLight(bool haveLight){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildOneTextureWithLight(haveLight);
    }
}
void edk::Object3D::drawChildFrontOneTextureWithLight(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    (this->*functionDrawOneTextureWithLight)(haveLight);

    this->drawChildremsFrontOneTextureWithLight(haveLight);

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsOneTextureWithLight(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
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
void edk::Object3D::drawChildOneTextureWithLight(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackOneTextureWithLight(haveLight);

    (this->*functionDrawOneTextureWithLight)(haveLight);

    this->drawChildremsFrontOneTextureWithLight(haveLight);

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsBackWithoutMaterial(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildWithoutMaterial();
    }
}
void edk::Object3D::drawChildBackWithoutMaterial(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackWithoutMaterial();

    (this->*functionDrawWithoutMaterial)();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsFrontWithoutMaterial(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildWithoutMaterial();
    }
}
void edk::Object3D::drawChildFrontWithoutMaterial(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    edk::shape::Mesh3D* mesh;
    //print all polygonList
    edk::uint32 size = this->meshes.size();
    for(edk::uint32 i=0u;i<size;i++){
        //
        mesh = this->meshes.getMesh(i);
        if(mesh){
            mesh->drawWithoutMaterial();
        }
    }

    this->drawChildremsFrontWithoutMaterial();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsWithoutMaterial(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
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
void edk::Object3D::drawChildWithoutMaterial(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackWithoutMaterial();

    edk::shape::Mesh3D* mesh;
    //print all polygonList
    edk::uint32 size = this->meshes.size();
    for(edk::uint32 i=0u;i<size;i++){
        //
        mesh = this->meshes.getMesh(i);
        if(mesh){
            mesh->drawWithoutMaterial();
        }
    }

    this->drawChildremsFrontWithoutMaterial();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsBackWithoutMaterialWithLight(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildWithoutMaterialWithLight(haveLight);
    }
}
void edk::Object3D::drawChildBackWithoutMaterialWithLight(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackWithoutMaterialWithLight(haveLight);

    (this->*functionDrawWithoutMaterialWithLight)(haveLight);

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsFrontWithoutMaterialWithLight(bool haveLight){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildWithoutMaterialWithLight(haveLight);
    }
}
void edk::Object3D::drawChildFrontWithoutMaterialWithLight(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    (this->*functionDrawWithoutMaterialWithLight)(haveLight);

    this->drawChildremsFrontWithoutMaterialWithLight(haveLight);

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsWithoutMaterialWithLight(bool haveLight){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
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
void edk::Object3D::drawChildWithoutMaterialWithLight(bool haveLight){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackWithoutMaterialWithLight(haveLight);

    (this->*functionDrawWithoutMaterialWithLight)(haveLight);

    this->drawChildremsFrontWithoutMaterialWithLight(haveLight);

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsBackWire(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildWire();
    }
}
void edk::Object3D::drawVBOChildremsBackWire(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawVBOChildWire();
    }
}
void edk::Object3D::drawChildBackWire(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackWire();

    (this->*functionDrawNormals)();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsBackNormals(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildNormals();
    }
}
void edk::Object3D::drawChildBackNormals(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackWire();

    (this->*functionDrawNormals)();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsBackNormalsWithColor(edk::color3f32 color){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildNormalsWithColor(color);
    }
}
void edk::Object3D::drawChildBackNormalsWithColor(edk::color3f32 color){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackWire();

    (this->*functionDrawNormalsWithColor)(color);

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsFrontWire(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildWire();
    }
}
void edk::Object3D::drawVBOChildremsFrontWire(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawVBOChildWire();
    }
}
void edk::Object3D::drawChildFrontWire(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    (this->*functionDrawWire)();

    this->drawChildremsFrontWire();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawVBOChildFrontWire(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    (this->*functionDrawVBOWire)();

    this->drawVBOChildremsFrontWire();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsFrontNormals(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildNormals();
    }
}
void edk::Object3D::drawChildFrontNormals(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    (this->*functionDrawNormals)();

    this->drawChildremsFrontWire();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsFrontNormalsWithColor(edk::color3f32 color){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildNormalsWithColor(color);
    }
}
void edk::Object3D::drawChildFrontNormalsWithColor(edk::color3f32 color){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    (this->*functionDrawNormalsWithColor)(color);

    this->drawChildremsFrontWire();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsWire(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
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
void edk::Object3D::drawChildWire(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackWire();

    (this->*functionDrawWire)();

    this->drawChildremsFrontWire();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawVBOChildWire(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawVBOChildremsBackWire();

    (this->*functionDrawVBOWire)();

    this->drawVBOChildremsFrontWire();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsNormals(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildNormals();
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildNormals();
    }
}
void edk::Object3D::drawChildNormals(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackWire();

    (this->*functionDrawNormals)();

    this->drawChildremsFrontWire();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsNormalsWithColor(edk::color3f32 color){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildNormalsWithColor(color);
    }
    size = this->childremsFront.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildNormalsWithColor(color);
    }
}
void edk::Object3D::drawChildNormalsWithColor(edk::color3f32 color){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add scale
    edk::GU::guScale3f32(this->size);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackWire();

    (this->*functionDrawNormalsWithColor)(color);

    this->drawChildremsFrontWire();

    edk::GU::guPopMatrix();
}
//draw the pivo
void edk::Object3D::drawChildremsBackPivo(edk::float32 size,edk::color3f32 color){
    edk::uint32 cSize = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildPivo(size,color);
    }
}
void edk::Object3D::drawChildBackPivo(edk::float32 size,edk::color3f32 color){
    edk::Object3D::drawPivoInPosition(this->position,0.f,size,color);
    if(this->childremsBack.size()){
        edk::GU::guPushMatrix();
        //add translate
        edk::GU::guTranslate3f32(this->position);
        //add rotation
        edk::GU::guRotateZf32(this->angle.x);
        //add scale
        edk::GU::guScale3f32(this->size);
        //set the pivo
        edk::GU::guTranslate3f32(this->pivo*-1.0f);
        this->drawChildremsBackPivo(size,color);
        edk::GU::guPopMatrix();
    }
}
void edk::Object3D::drawChildremsFrontPivo(edk::float32 size,edk::color3f32 color){
    edk::uint32 cSize = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildPivo(size,color);
    }
}
void edk::Object3D::drawChildFrontPivo(edk::float32 size,edk::color3f32 color){
    edk::Object3D::drawPivoInPosition(this->position,0.f,size,color);
    if(this->childremsFront.size()){
        edk::GU::guPushMatrix();
        //add translate
        edk::GU::guTranslate3f32(this->position);
        //add rotation
        edk::GU::guRotateZf32(this->angle.x);
        //add scale
        edk::GU::guScale3f32(this->size);
        //set the pivo
        edk::GU::guTranslate3f32(this->pivo*-1.0f);
        this->drawChildremsFrontPivo(size,color);
        edk::GU::guPopMatrix();
    }
}
void edk::Object3D::drawChildremsPivo(edk::float32 size,edk::color3f32 color){
    edk::uint32 cSize = this->childremsBack.size();
    edk::Object3D* obj;
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
void edk::Object3D::drawChildPivo(edk::float32 size,edk::color3f32 color){
    if(this->childremsBack.size()){
        edk::GU::guPushMatrix();
        //add translate
        edk::GU::guTranslate3f32(this->position);
        //add rotation
        edk::GU::guRotateZf32(this->angle.x);
        //add scale
        edk::GU::guScale3f32(this->size);
        //set the pivo
        edk::GU::guTranslate3f32(this->pivo*-1.0f);
        this->drawChildremsBackPivo(size,color);
        edk::GU::guPopMatrix();
    }
    edk::Object3D::drawPivoInPosition(this->position,0.f,size,color);
    if(this->childremsFront.size()){
        edk::GU::guPushMatrix();
        //add translate
        edk::GU::guTranslate3f32(this->position);
        //add rotation
        edk::GU::guRotateZf32(this->angle.x);
        //add scale
        edk::GU::guScale3f32(this->size);
        //set the pivo
        edk::GU::guTranslate3f32(this->pivo*-1.0f);
        this->drawChildremsFrontPivo(size,color);
        edk::GU::guPopMatrix();
    }
}
void edk::Object3D::drawChildremsBackPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::uint32 cSize = this->childremsBack.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsBack.get(i);
        obj->drawChildPivo(size,r,g,b);
    }
}
void edk::Object3D::drawChildBackPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::GU::guPushMatrix();

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);
    if(this->childremsBack.size()){
        this->drawChildremsBackPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();

    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    //edk::GU::guTranslate3f32(this->position);

    edk::Object3D::drawPivoInPosition(this->position,0.f,size,edk::color3f32(r,g,b));

    edk::GU::guPopMatrix();

    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);
    if(this->childremsFront.size()){
        this->drawChildremsFrontPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsFrontPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::uint32 cSize = this->childremsFront.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childremsFront.get(i);
        obj->drawChildPivo(size,r,g,b);
    }
}
void edk::Object3D::drawChildFrontPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::GU::guPushMatrix();

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);
    if(this->childremsBack.size()){
        this->drawChildremsBackPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();


    edk::GU::guPushMatrix();

    edk::GU::guScale3f32(this->connectedSize);
    edk::GU::guRotateZf32(this->connectedAngle.x);
    edk::GU::guTranslate3f32(this->connectedPosition);
    edk::GU::guTranslate3f32(this->connectedPivo*-1.0f);

    //add translate
    //edk::GU::guTranslate3f32(this->position);

    edk::Object3D::drawPivoInPosition(this->position,0.f,size,edk::color3f32(r,g,b));

    edk::GU::guPopMatrix();

    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);
    if(this->childremsFront.size()){
        this->drawChildremsFrontPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();
}
void edk::Object3D::drawChildremsPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::uint32 cSize = this->childremsBack.size();
    edk::Object3D* obj;
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
void edk::Object3D::drawChildPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    if(this->childremsBack.size()){
        edk::Object3D::drawPivoInPosition(this->position,0.f,size,edk::color3f32(r,g,b));
        edk::GU::guPushMatrix();
        //add translate
        edk::GU::guTranslate3f32(this->position);
        //add rotation
        edk::GU::guRotateZf32(this->angle.x);
        //add scale
        edk::GU::guScale3f32(this->size);
        //set the pivo
        edk::GU::guTranslate3f32(this->pivo*-1.0f);
        this->drawChildremsBackPivo(size,r,g,b);
        edk::GU::guPopMatrix();
    }
    edk::Object3D::drawPivoInPosition(this->position,0.f,size,edk::color3f32(r,g,b));
    if(this->childremsFront.size()){
        edk::Object3D::drawPivoInPosition(this->position,0.f,size,edk::color3f32(r,g,b));
        edk::GU::guPushMatrix();
        //add translate
        edk::GU::guTranslate3f32(this->position);
        //add rotation
        edk::GU::guRotateZf32(this->angle.x);
        //add scale
        edk::GU::guScale3f32(this->size);
        //set the pivo
        edk::GU::guTranslate3f32(this->pivo*-1.0f);
        this->drawChildremsFrontPivo(size,r,g,b);
        edk::GU::guPopMatrix();
    }
}

//Actions
edk::Object3D::ActionPosition::ActionPosition(edk::Object3D* /*object*/, edk::vec3f32 /*position*/){
    /*
    this->position=position;
    this->object=object;
    this->code = 1u;
    */
}
//run action function
void edk::Object3D::ActionPosition::runAction(){
    this->object->position = this->position;
}
//write to XML
bool edk::Object3D::ActionPosition::writeToXML(edk::XML* xml,edk::uint32 id){
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
                    xml->addSelectedNextAttribute("positionZ",this->position.z);

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
bool edk::Object3D::ActionPosition::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    this->position.z = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionZ"));

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
edk::vec3f32 edk::Object3D::ActionPosition::getPosition(){
    return this->position;
}
edk::Object3D::ActionMove::ActionMove(edk::Object3D* object,edk::float32 duration, edk::vec3f32 position){
    this->position=position;
    this->duration = duration;
    this->object=object;
    this->code = 2u;
}
//run action function
void edk::Object3D::ActionMove::runAction(){
    this->object->animationPosition.cleanTracks();
    edk::uint32 track = this->object->animationPosition.newTrack();
    this->object->animationPosition.addFirstInterpolationLine(track,0,
                                                              this->object->position.x,
                                                              this->object->position.y,
                                                              this->object->position.z,
                                                              this->duration,
                                                              this->position.x,
                                                              this->position.y,
                                                              this->position.z
                                                              );
    this->object->animationPosition.playForwardAllTracks();
}
//write to XML
bool edk::Object3D::ActionMove::writeToXML(edk::XML* xml,edk::uint32 id){
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
                    xml->addSelectedNextAttribute("positionZ",this->position.z);
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
bool edk::Object3D::ActionMove::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    this->position.z = edk::String::strToInt32(xml->getSelectedAttributeValueByName("positionZ"));
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
edk::vec3f32 edk::Object3D::ActionMove::getPosition(){
    return this->position;
}
edk::float32 edk::Object3D::ActionMove::getDuration(){
    return this->duration;
}
edk::Object3D::ActionSetSize::ActionSetSize(edk::Object3D* /*object*/, edk::size3f32 /*size*/){
    /*
    this->object=object;
    this->size=size;
    this->code = 3u;
    */
}
//run action function
void edk::Object3D::ActionSetSize::runAction(){
    /*
    this->object->size = this->size;
    */
}
//write to XML
bool edk::Object3D::ActionSetSize::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
bool edk::Object3D::ActionSetSize::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
edk::size3f32 edk::Object3D::ActionSetSize::getSize(){
    return this->size;
}
edk::Object3D::ActionSize::ActionSize(edk::Object3D* /*object*/,edk::float32 /*duration*/, edk::size3f32 /*size*/){
    /*
    this->size=size;
    this->duration = duration;
    this->object=object;
    this->code = 4u;
    */
}
//run action function
void edk::Object3D::ActionSize::runAction(){
    /*
    this->object->animationSize.cleanAnimations();
    this->object->animationSize.addFirstInterpolationLine(0,this->object->size.width,this->object->size.height,this->duration,this->size.width,this->size.height);
    this->object->animationSize.playForward();
    */
}
//write to XML
bool edk::Object3D::ActionSize::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
                    xml->addSelectedNextAttribute("length",this->size.length);
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
bool edk::Object3D::ActionSize::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
                    this->size.length = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("length"));
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
edk::size3f32 edk::Object3D::ActionSize::getSize(){
    return this->size;
}
edk::float32 edk::Object3D::ActionSize::getDuration(){
    return this->duration;
}
edk::Object3D::ActionSetAngle::ActionSetAngle(edk::Object3D* object, edk::float32 angle){
    this->object = object;
    this->angle = angle;
    this->code = 5u;
}
//run action function
void edk::Object3D::ActionSetAngle::runAction(){
    this->object->angle = this->angle;
}
//write to XML
bool edk::Object3D::ActionSetAngle::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
                    xml->addSelectedNextAttribute("angle",this->angle.x);

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
bool edk::Object3D::ActionSetAngle::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
edk::float32 edk::Object3D::ActionSetAngle::getAngle(){
    return this->angle;
}
edk::Object3D::ActionAngle::ActionAngle(edk::Object3D* /*object*/,edk::float32 /*duration*/, edk::float32 /*angle*/){
    /*
    this->object = object;
    this->duration = duration;
    this->angle = angle;
    this->code = 6u;
    */
}
//run action function
void edk::Object3D::ActionAngle::runAction(){
    /*
    this->object->animationRotation.cleanAnimations();
    this->object->animationRotation.addFirstInterpolationLine(0,this->object->angle,this->duration,this->angle.x);
    this->object->animationRotation.playForward();
    */
}
//write to XML
bool edk::Object3D::ActionAngle::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
                    xml->addSelectedNextAttribute("angle",this->angle.x);
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
bool edk::Object3D::ActionAngle::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
edk::float32 edk::Object3D::ActionAngle::getAngle(){
    return this->angle;
}
edk::float32 edk::Object3D::ActionAngle::getDuration(){
    return this->duration;
}
edk::Object3D::ActionMeshName::ActionMeshName(edk::Object3D* /*object*/,edk::uint32 /*id*/, edk::char8* /*name*/,bool /*loop*/){
    /*
    this->object=object;
    this->loop = loop;
    this->id = id;
    this->setName(name);
    this->code = 7u;
    */
}
//run action function
void edk::Object3D::ActionMeshName::runAction(){
    /*
    //load the mesh
    edk::shape::Mesh3D* mesh = this->object->getMesh(this->id);
    if(mesh){
        mesh->selectedAnimationSetLoop(this->loop);
        mesh->selectedAnimationPlayNameForward(this->name());
    }
    */
}
//write to XML
bool edk::Object3D::ActionMeshName::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
bool edk::Object3D::ActionMeshName::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
edk::uint32 edk::Object3D::ActionMeshName::getId(){
    return this->id;
}
bool edk::Object3D::ActionMeshName::getLoop(){
    return this->loop;
}
edk::Object3D::ActionMeshStop::ActionMeshStop(edk::Object3D* /*object*/,edk::uint32 /*id*/){
    /*
    this->object=object;
    this->id = id;
    this->code = 8u;
    */
}
//run action function
void edk::Object3D::ActionMeshStop::runAction(){
    /*
    //load the mesh
    edk::shape::Mesh3D* mesh = this->object->getMesh(this->id);
    if(mesh){
        mesh->selectedAnimationStop();
    }
    */
}
//write to XML
bool edk::Object3D::ActionMeshStop::writeToXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
bool edk::Object3D::ActionMeshStop::readFromXML(edk::XML* /*xml*/,edk::uint32 /*id*/){
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
edk::uint32 edk::Object3D::ActionMeshStop::getId(){
    return this->id;
}

//create a new mesh and add to the meshs stack
edk::shape::Mesh3D* edk::Object3D::newMesh(edk::uint32* position){
    return this->meshes.pushNewMesh(position);
}

edk::shape::Mesh3D* edk::Object3D::allocMeshForOBJ(){
    return this->newMesh();
}

//clean the obect
void edk::Object3D::clean(){
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
edk::TypeObject edk::Object3D::getType(){
    return this->type;
}

//Add a list to the Object3D
edk::uint32 edk::Object3D::addMesh(edk::shape::Mesh3D* mesh){
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
bool edk::Object3D::removeMesh(edk::uint32 position){
    //remove the mesh
    return this->meshes.removeMesh(position);
}
//remove all meshes
void edk::Object3D::cleanMeshes(){
    this->cleanSelected();
    this->meshes.removeAllMeshes();
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

bool edk::Object3D::calculateModelMatrix(edk::vector::Matrixf32<4u,4u>* dest){
    if(dest){
        dest->setIdentity(1.f,0.f);
        edk::vector::Matrixf32<4u,4u> transformMat;

        edk::Math::generateTranslateMatrix(this->position,&transformMat);
        dest->multiplyThisWithMatrix(&transformMat);

        edk::Math::generateRotateMatrixX(this->angle.x,&transformMat);
        dest->multiplyThisWithMatrix(&transformMat);
        edk::Math::generateRotateMatrixY(this->angle.y,&transformMat);
        dest->multiplyThisWithMatrix(&transformMat);
        edk::Math::generateRotateMatrixZ(this->angle.z,&transformMat);
        dest->multiplyThisWithMatrix(&transformMat);

        edk::Math::generateScaleMatrix(this->size,&transformMat);
        dest->multiplyThisWithMatrix(&transformMat);
        return true;
    }
    return false;
}

//set the drawStart function to set the textures in the shader
bool edk::Object3D::setShaderPointer(edk::material::ShaderFunctionToMaterial* shader){
    if(shader){
        edk::uint32 size = this->meshes.size();
        edk::shape::Mesh3D* temp;
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

//return a copy of the boundingBox
edk::cubef32 edk::Object3D::getBoundingBox(){
    return this->boundingBox;
}

//Select the polygonList
bool edk::Object3D::selectMesh(edk::uint32 position){
    //free the selected
    this->cleanSelected();
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
        return this->selected->material.getTexture(number);
    }
    //else return false
    return 0u;
}
//free the selected
void edk::Object3D::cleanSelected(){
    //
    this->selected=NULL;
}
//return the number of meshs
edk::uint32 edk::Object3D::getMeshSize(){
    return this->meshes.size();
}
//return the mesh pointer
edk::shape::Mesh3D* edk::Object3D::getMesh(edk::uint32 position){
    return this->meshes.getMesh(position);
}
//remove all meshes
void edk::Object3D::removeAllMesh(){
    this->cleanMeshes();
}
//set the polygonsColor
bool edk::Object3D::setPolygonColor(edk::uint32 position,edk::color4f32 color){
    if(this->meshes.getMesh(position)){
        this->meshes.getMesh(position)->setPolygonsColor(color);
    }
    return false;
}
bool edk::Object3D::setPolygonColor(edk::uint32 position,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setPolygonColor(position,edk::color4f32(r,g,b,a));
}

void edk::Object3D::setPolygonsColor(edk::color4f32 color){
    edk::uint32 size = this->meshes.size();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColor(color);
        }
    }
}
void edk::Object3D::setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setPolygonsColor(edk::color4f32(r,g,b,a));
}
void edk::Object3D::setPolygonsColorR(edk::float32 r){
    edk::uint32 size = this->meshes.size();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColorR(r);
        }
    }
}
void edk::Object3D::setPolygonsColorG(edk::float32 g){
    edk::uint32 size = this->meshes.size();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColorG(g);
        }
    }
}
void edk::Object3D::setPolygonsColorB(edk::float32 b){
    edk::uint32 size = this->meshes.size();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColorB(b);
        }
    }
}
void edk::Object3D::setPolygonsColorA(edk::float32 a){
    edk::uint32 size = this->meshes.size();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.getMesh(i)){
            this->meshes.getMesh(i)->setPolygonsColorA(a);
        }
    }
}
//Set the polygons smooth
bool edk::Object3D::setPolygonsSmooth(bool smooth){
    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh3D* temp;
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->meshes.getMesh(i);
            if(temp){
                temp->setPolygonsSmooth(smooth);
            }
        }
        return true;
    }
    return false;
}
bool edk::Object3D::setPolygonsSmoothOn(){
    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh3D* temp;
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->meshes.getMesh(i);
            if(temp){
                temp->setPolygonsSmoothOn();
            }
        }
        return true;
    }
    return false;
}
bool edk::Object3D::setPolygonsSmoothOff(){
    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh3D* temp;
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->meshes.getMesh(i);
            if(temp){
                temp->setPolygonsSmoothOff();
            }
        }
        return true;
    }
    return false;
}
//update the polygons normals
bool edk::Object3D::updatePolygonsNormals(){
    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh3D* temp;
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->meshes.getMesh(i);
            if(temp){
                temp->updatePolygonsNormals();
            }
        }
        return true;
    }
    return false;
}
bool edk::Object3D::calculatePolygonsNormals(){
    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh3D* temp;
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->meshes.getMesh(i);
            if(temp){
                temp->updatePolygonsNormals();
            }
        }
        return true;
    }
    return false;
}

//rotate the object to look at the camera
void edk::Object3D::lookAtPoint(edk::float32 x,edk::float32 y,edk::float32 z){
    this->lookAtPoint(edk::vec3f32(x,y,z));
}
void edk::Object3D::lookAtPoint(edk::vec3f32 point){
    //get the point angle
    point-=this->position;
    this->angle.x = 0.f;
    this->angle.y = 0.f;
    this->angle.z = 0.f;

    //get the base angle
    this->angle.y = edk::Math::getAngle(point.x,point.z) *-1.f;
    //get the height angle
    edk::vec2f32 newPosition = edk::Math::rotatePlus(edk::vec2f32(point.x,point.z),this->angle.y);
    this->angle.z = edk::Math::getAngle(newPosition.x,point.y);
}

//get world polygon
bool edk::Object3D::getWorldPolygon(edk::shape::Polygon3D* dest,edk::uint32 meshPosition,edk::uint32 polygonPosition){
    bool ret=false;
    if(dest){
        //first copy the matrix
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
        //multiply the matrix by

        this->matrixTransform.setIdentity();

        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);

        edk::shape::Mesh3D* mesh = this->meshes.getMesh(meshPosition);
        if(mesh){
            ret = mesh->getWorldPolygon(dest,polygonPosition,&this->matrixTransform);
        }
    }
    return ret;
}
bool edk::Object3D::getWorldPolygon(edk::shape::Polygon3D* dest,edk::uint32 meshPosition,edk::uint32 polygonPosition,edk::vector::Matrixf32<4u,4u>* transformMat){
    bool ret=false;
    if(dest){
        //first copy the matrix
        if(this->matrixTransform.cloneFrom(transformMat)){
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
            edk::Math::generateRotateMatrixZ(this->angle.x,&this->matrixAngleX);
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
            edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);

            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngleX);
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
            //Pivo
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);

            edk::shape::Mesh3D* mesh;
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
bool edk::Object3D::setLight(edk::uint32 position,edk::light::Light light){
    if(position<EDK_LIGHT_LIMIT){
        this->lights[position] = light;
        return true;
    }
    return false;
}
bool edk::Object3D::cleanLight(edk::uint32 position){
    if(position<EDK_LIGHT_LIMIT){
        //
        this->lights[position].clean();
        return true;
    }
    return false;
}
bool edk::Object3D::lightOn(edk::uint32 position){
    if(position<EDK_LIGHT_LIMIT){
        //add the light on the tree
        this->lights[position].on=true;
        return true;
    }
    return false;
}
bool edk::Object3D::lightOff(edk::uint32 position){
    if(position<EDK_LIGHT_LIMIT){
        //remove the position from the tree
        this->lights[position].on=false;
        return true;
    }
    return false;
}

//OBJ
bool edk::Object3D::addOBJ(const edk::char8* fileName){
    return this->addOBJ((edk::char8*) fileName);
}
bool edk::Object3D::addOBJ(edk::char8* fileName){
    if(fileName){
        return this->objAddFile(fileName);
    }
    return false;
}
bool edk::Object3D::loadOBJ(const edk::char8* fileName){
    return this->loadOBJ((edk::char8*) fileName);
}
bool edk::Object3D::loadOBJ(edk::char8* fileName){
    this->cleanMeshes();
    return this->addOBJ(fileName);
}

//VBO
bool edk::Object3D::setUseVBO(edk::uint32 meshPosition,bool use){
    edk::shape::Mesh3D* mesh = this->meshes.getMesh(meshPosition);
    if(mesh){
        mesh->setUseVBO(use);
        return true;
    }
    return false;
}
bool edk::Object3D::useVBO(edk::uint32 meshPosition){
    edk::shape::Mesh3D* mesh = this->meshes.getMesh(meshPosition);
    if(mesh){
        mesh->useVBO();
        return true;
    }
    return false;
}
bool edk::Object3D::dontUseVBO(edk::uint32 meshPosition){
    edk::shape::Mesh3D* mesh = this->meshes.getMesh(meshPosition);
    if(mesh){
        mesh->dontUseVBO();
        return true;
    }
    return false;
}
bool edk::Object3D::setUseVBO(bool use){
    edk::shape::Mesh3D* mesh;
    //print all polygonList
    edk::uint32 size = this->meshes.size();
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);
            if(mesh){
                mesh->setUseVBO(use);
            }
        }
        return true;
    }
    return false;
}
bool edk::Object3D::useVBO(){
    edk::shape::Mesh3D* mesh;
    //print all polygonList
    edk::uint32 size = this->meshes.size();
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);
            if(mesh){
                mesh->useVBO();
            }
        }
        return true;
    }
    return false;
}
bool edk::Object3D::dontUseVBO(){
    edk::shape::Mesh3D* mesh;
    //print all polygonList
    edk::uint32 size = this->meshes.size();
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);
            if(mesh){
                mesh->dontUseVBO();
            }
        }
        return true;
    }
    return false;
}
//convert the mesh to the VBO
bool edk::Object3D::generateVBO(edk::uint32 meshPosition){
    edk::shape::Mesh3D* mesh = this->meshes.getMesh(meshPosition);
    if(mesh){
        mesh->generateVBO();
        return true;
    }
    return false;
}
bool edk::Object3D::generateVBOWire(edk::uint32 meshPosition){
    edk::shape::Mesh3D* mesh = this->meshes.getMesh(meshPosition);
    if(mesh){
        mesh->generateVBOWire();
        return true;
    }
    return false;
}
bool edk::Object3D::generateVBO(){
    edk::shape::Mesh3D* mesh;
    //print all polygonList
    edk::uint32 size = this->meshes.size();
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);
            if(mesh){
                mesh->generateVBO();
            }
        }
        return true;
    }
    return false;
}
bool edk::Object3D::generateVBOWire(){
    edk::shape::Mesh3D* mesh;
    //print all polygonList
    edk::uint32 size = this->meshes.size();
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);
            if(mesh){
                mesh->generateVBOWire();
            }
        }
        return true;
    }
    return false;
}
bool edk::Object3D::generateVBOTangentAndBiTangent(){
    edk::shape::Mesh3D* mesh;
    //print all polygonList
    edk::uint32 size = this->meshes.size();
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            //
            mesh = this->meshes.getMesh(i);
            if(mesh){
                mesh->generateVBOTangentAndBiTangent();
            }
        }
        return true;
    }
    return false;
}

//HIDE
bool edk::Object3D::hide(){
    if(!this->hided){
        //
        this->functionDrawBoundingBox = &edk::Object3D::drawHideBoundingBox;
        this->functionDraw = &edk::Object3D::drawHide;
        this->functionDrawVBO = &edk::Object3D::drawVBOHide;
        this->functionDrawOneTexture = &edk::Object3D::drawHideOneTexture;
        this->functionDrawOneTextureWithLight = &edk::Object3D::drawHideOneTextureWithLight;
        this->functionDrawWithoutMaterial = &edk::Object3D::drawHideWithoutMaterial;
        this->functionDrawWithoutMaterialWithLight = &edk::Object3D::drawHideWithoutMaterialWithLight;
        this->functionDrawWire = &edk::Object3D::drawHideWire;
        this->functionDrawVBOWire = &edk::Object3D::drawVBOHideWire;
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
        this->functionDrawVBO = &edk::Object3D::drawVBOUnhide;
        this->functionDrawOneTexture = &edk::Object3D::drawUnhideOneTexture;
        this->functionDrawOneTextureWithLight = &edk::Object3D::drawUnhideOneTextureWithLight;
        this->functionDrawWithoutMaterial = &edk::Object3D::drawUnhideWithoutMaterial;
        this->functionDrawWithoutMaterialWithLight = &edk::Object3D::drawUnhideWithoutMaterialWithLight;
        this->functionDrawWire = &edk::Object3D::drawUnhideWire;
        this->functionDrawVBOWire = &edk::Object3D::drawVBOUnhideWire;
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
    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh3D* mesh;
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
bool edk::Object3D::playMeshAnimations(edk::uchar32 position){
    edk::shape::Mesh3D* mesh = this->meshes.getMesh(position);
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
void edk::Object3D::pauseMeshAnimations(){
    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh3D* mesh;
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
bool edk::Object3D::pauseMeshAnimations(edk::uchar32 position){
    edk::shape::Mesh3D* mesh = this->meshes.getMesh(position);
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
void edk::Object3D::updateMeshAnimations(){
    //update mesh animations
    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh3D *mesh;
    for(edk::uint32 i=0u;i<size;i++){
        mesh = this->meshes.getMesh(i);
        if(mesh){
            mesh->updateFramesAnimations();
        }
    }
}
void edk::Object3D::updateMeshAnimations(edk::float32 seconds){
    //update mesh animations
    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh3D *mesh;
    for(edk::uint32 i=0u;i<size;i++){
        if(this->meshes.haveCreateMesh(i)){
            mesh = this->meshes.getMesh(i);
            if(mesh){
                mesh->updateFramesAnimations(seconds);
            }
        }
    }
}
bool edk::Object3D::updateMeshAnimationsFromPosition(edk::uchar32 position){
    edk::shape::Mesh3D* mesh = this->meshes.getMesh(position);
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
bool edk::Object3D::updateMeshAnimationsFromPosition(edk::uchar32 position,edk::float32 seconds){
    edk::shape::Mesh3D* mesh = this->meshes.getMesh(position);
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
bool edk::Object3D::updateAnimations(){
    bool ret=edk::Object3DValues::updateAnimations();
    this->updateMeshAnimations();
    this->updateChildremsAnimations();
    return ret;
}
bool edk::Object3D::updateAnimations(edk::float32 seconds){
    bool ret=edk::Object3DValues::updateAnimations(seconds);
    this->updateMeshAnimations(seconds);
    this->updateChildremsAnimations(seconds);
    return ret;
}

//ACTIONS
//play actions
void edk::Object3D::playForwardActions(){
    /*
    this->actions.playForward();
    */
}
void edk::Object3D::playForwardInActions(edk::float32 /*second*/){
    /*
    this->actions.playForwardIn(second);
    */
}
void edk::Object3D::pauseActions(){
    /*
    this->actions.pause();
    */
}
void edk::Object3D::stopActions(){
    /*
    this->actions.stop();
    */
}
//set loop
void edk::Object3D::setLoopActions(bool /*loop*/){
    /*
    this->actions.setLoop(loop);
    */
}
void edk::Object3D::loopOnActions(){
    /*
    this->actions.loopOn();
    */
}
void edk::Object3D::loopOffActions(){
    /*
    this->actions.loopOff();
    */
}

//return if are playing
bool edk::Object3D::isPlayingActions(){
    /*
    return this->actions.isPlaying();
    */
    return false;
}
bool edk::Object3D::isPausedActions(){
    /*
    return this->actions.isPaused();
    */
    return false;
}
//update actions
void edk::Object3D::updateActions(){
    /*
    this->actions.update();
    */
}
//remove actions
void edk::Object3D::removeAllActions(){
    /*
    this->actions.clean();
    */
}
void edk::Object3D::cleanAllActions(){
    /*
    this->actions.clean();
    */
}
bool edk::Object3D::removeActionSecond(edk::float32 /*second*/){
    /*
    return this->actions.removeSecond(second);
    */
    return false;
}
//Add zero action
bool edk::Object3D::actionZero(edk::float32 /*second*/){
    /*
    return this->actions.addAction(second,new edk::ActionZero);
    */
    return false;
}
//add move action
bool edk::Object3D::actionSetPosition(edk::float32 /*second*/,edk::vec3f32 /*position*/){
    /*
    return this->actions.addAction(second,new edk::Object3D::ActionPosition(this,position));
    */
    return false;
}
bool edk::Object3D::actionSetPosition(edk::float32 /*second*/,edk::float32 /*x*/,edk::float32 /*y*/){
    /*
    return this->actionSetPosition(second,edk::vec3f32(x,y));
    */
    return false;
}
//add move action
bool edk::Object3D::actionMove(edk::float32 /*second*/,edk::float32 /*duration*/, edk::vec3f32 /*position*/){
    /*
    //create the action
    if(this->actions.addAction(second,new edk::Object3D::ActionMove(this,duration,position))){
        this->actions.addZeroAction(second+duration);
        return true;
    }
    */
    return false;
}
bool edk::Object3D::actionMove(edk::float32 /*second*/,edk::float32 /*duration*/, edk::float32 /*x*/,edk::float32 /*y*/){
    /*
    return this->actionMove(second,duration, edk::vec3f32(x,y));
    */
    return false;
}
bool edk::Object3D::actionMoveTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::vec3f32 /*position*/){
    /*
    return this->actionMove(start,end-start, position);
    */
    return false;
}
bool edk::Object3D::actionMoveTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::float32 /*x*/,edk::float32 /*y*/){
    /*
    return this->actionMove(start,end-start,x,y);
    */
    return false;
}
//add scale action
bool edk::Object3D::actionSetSize(edk::float32 /*second*/,edk::size3f32 /*size*/){
    /*
    //create the action
    return this->actions.addAction(second,new edk::Object3D::ActionSetSize(this,size));
    */
    return false;
}
bool edk::Object3D::actionSetSize(edk::float32 /*second*/,
                                  edk::float32 /*width*/,
                                  edk::float32 /*height*/,
                                  edk::float32 /*length*/
                                  ){
    /*
    return this->actionSetSize(second,edk::size3f32(width,height));
    */
    return false;
}
bool edk::Object3D::actionSetSize(edk::float32 /*second*/,edk::float32 /*size*/){
    /*
    return this->actionSetSize(second,size,size);
    */
    return false;
}
//add scale action
bool edk::Object3D::actionScale(edk::float32 /*second*/,edk::float32 /*duration*/, edk::size3f32 /*size*/){
    /*
    //create the action
    if(this->actions.addAction(second,new edk::Object3D::ActionSize(this,duration,size))){
        this->actions.addZeroAction(second+duration);
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
    return this->actionScale(second,duration, edk::size3f32( width,height));
    */
    return false;
}
bool edk::Object3D::actionScale(edk::float32 /*second*/,edk::float32 /*duration*/, edk::float32 /*size*/){
    /*
    return this->actionScale(second,duration, size,size);
    */
    return false;
}
bool edk::Object3D::actionScaleTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::size3f32 /*size*/){
    /*
    return this->actionScale(start,end-start, size);
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
    return this->actionScale(start,end-start, width,height);
    */
    return false;
}
bool edk::Object3D::actionScaleTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::float32 /*size*/){
    /*
    return this->actionScale(start,end-start, size);
    */
    return false;
}
//add angle action
bool edk::Object3D::actionSetAngle(edk::float32 /*second*/,edk::float32 /*angle*/){
    /*
    return this->actions.addAction(second,new edk::Object3D::ActionSetAngle(this,angle));
    */
    return false;
}
//add angle action
bool edk::Object3D::actionRotateFor(edk::float32 /*second*/,edk::float32 /*duration*/, edk::float32 /*angle*/){
    /*
    if(this->actions.addAction(second,new edk::Object3D::ActionAngle(this,duration,angle))){
        this->actions.addZeroAction(second);
        return true;
    }
    */
    return false;
}
bool edk::Object3D::actionRotateTo(edk::float32 /*start*/,edk::float32 /*end*/, edk::float32 /*angle*/){
    /*
    return this->actionRotateFor(start,end-start, angle);
    */
    return false;
}
//MESH SPRITE SHEET
bool edk::Object3D::actionPlayName(edk::float32 /*second*/,edk::uint32 /*id*/,edk::char8* /*name*/,bool /*loop*/){
    //
    /*
    return this->actions.addAction(second,new edk::Object3D::ActionMeshName(this,id,name,loop));
    */
    return false;
}
bool edk::Object3D::actionPlayName(edk::float32 /*second*/,edk::uint32 /*id*/,const edk::char8* /*name*/,bool /*loop*/){
    //
    /*
    return actionPlayName(second,id,(edk::char8*)name,loop);
    */
    return false;
}
bool edk::Object3D::actionPlayNameFor(edk::float32 /*second*/,edk::float32 /*duration*/,edk::uint32 /*id*/,edk::char8* /*name*/){
    /*
    if(this->actions.addAction(second,new edk::Object3D::ActionMeshName(this,id,name,true))){
        //add the stop action
        this->actions.addAction(second+duration,new edk::Object3D::ActionMeshStop(this,id));
        return true;
    }
    */
    return false;
}
bool edk::Object3D::actionPlayNameFor(edk::float32 /*second*/,edk::float32 /*duration*/,edk::uint32 /*id*/,const edk::char8* /*name*/){
    /*
    return this->actionPlayNameFor(second,duration,id,(edk::char8*)name);
    */
    return false;
}

//DRAW
//print the mesh
void edk::Object3D::print(){
    edk::Object3DValues::print();

    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh3D* mesh;
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
void edk::Object3D::drawBoundingBox(){
    //test if have a father
    //if(this->father){
    //    //put the transformation on a stack
    //    edk::GU::guPushMatrix();
    //
    //    edk::GU::guColor4f32(1.0,1.0,1.0,1.0);
    //
    //    edk::GU::guBegin(GU_LINE_LOOP);
    //    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.origin.y   );
    //    edk::GU::guVertex3f32(this->boundingBox.origin.x  ,this->boundingBox.size.height);
    //    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.size.height);
    //    edk::GU::guVertex3f32(this->boundingBox.size.width,this->boundingBox.origin.y   );
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
void edk::Object3D::draw(){
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
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBack(haveLight);

    (this->*functionDraw)(haveLight);

    this->drawChildremsFront(haveLight);

    //glEnable(GL_RESCALE_NORMAL);
    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
}
void edk::Object3D::drawVBO(){
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
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawVBOChildremsBack(haveLight);

    (this->*functionDrawVBO)(haveLight);

    this->drawVBOChildremsFront(haveLight);

    //glEnable(GL_RESCALE_NORMAL);
    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
}
void edk::Object3D::drawOneTexture(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackOneTexture();

    (this->*functionDrawOneTexture)();

    this->drawChildremsFrontOneTexture();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawOneTextureWithLight(){
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
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackOneTextureWithLight(haveLight);

    (this->*functionDrawOneTextureWithLight)(haveLight);

    this->drawChildremsFrontOneTextureWithLight(haveLight);

    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
}
void edk::Object3D::drawWithoutMaterial(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackWithoutMaterial();

    (this->*functionDrawWithoutMaterial)();

    this->drawChildremsFrontWithoutMaterial();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawWithoutMaterialWithLight(){
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
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackWithoutMaterialWithLight(haveLight);

    (this->*functionDrawWithoutMaterialWithLight)(haveLight);

    this->drawChildremsFrontWithoutMaterialWithLight(haveLight);

    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
}
void edk::Object3D::drawWire(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackWire();

    (this->*functionDrawWire)();

    this->drawChildremsFrontWire();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawVBOWire(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawVBOChildremsBackWire();

    (this->*functionDrawVBOWire)();

    this->drawVBOChildremsFrontWire();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawWirePolygon(edk::uint32 meshPosition,edk::uint32 polygon){
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    (this->*functionDrawWirePolygon)(meshPosition,polygon);

    edk::GU::guPopMatrix();
}
bool edk::Object3D::drawMesh(edk::uint32 meshPosition){
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
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    ret = (this->*functionDrawMesh)(haveLight,meshPosition);

    //glEnable(GL_RESCALE_NORMAL);
    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object3D::drawPolygon(edk::uint32 meshPosition,edk::uint32 polygon){
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
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    ret = (this->*functionDrawPolygon)(haveLight,meshPosition,polygon);

    //glEnable(GL_RESCALE_NORMAL);
    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object3D::drawMeshOneTexture(edk::uint32 meshPosition){
    bool ret = false;
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    ret = (this->*functionDrawMeshOneTexture)(meshPosition);

    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object3D::drawPolygonOneTexture(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret = false;
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    ret = (this->*functionDrawPolygonOneTexture)(meshPosition,polygon);

    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object3D::drawMeshOneTextureWithLight(edk::uint32 meshPosition){
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
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    ret = (this->*functionDrawMeshOneTextureWithLight)(haveLight,meshPosition);

    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object3D::drawPolygonOneTextureWithLight(edk::uint32 meshPosition,edk::uint32 polygon){
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
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    ret = (this->*functionDrawPolygonOneTextureWithLight)(haveLight,meshPosition,polygon);

    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object3D::drawMeshWithoutMaterial(edk::uint32 meshPosition){
    bool ret = false;
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    ret = (this->*functionDrawMeshWithoutMaterial)(meshPosition);

    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object3D::drawPolygonWithoutMaterial(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret = false;
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    ret = (this->*functionDrawPolygonWithoutMaterial)(meshPosition,polygon);

    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object3D::drawMeshWithoutMaterialWithLight(edk::uint32 meshPosition){
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
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    ret = (this->*functionDrawMeshWithoutMaterialWithLight)(haveLight,meshPosition);

    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object3D::drawPolygonWithoutMaterialWithLight(edk::uint32 meshPosition,edk::uint32 polygon){
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
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    ret = (this->*functionDrawPolygonWithoutMaterialWithLight)(haveLight,meshPosition,polygon);

    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object3D::drawMeshWire(edk::uint32 meshPosition){
    bool ret=false;
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    ret = (this->*functionDrawMeshWire)(meshPosition);

    edk::GU::guPopMatrix();
    return ret;
}
bool edk::Object3D::drawPolygonWire(edk::uint32 meshPosition,edk::uint32 polygon){
    bool ret=false;
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    ret = (this->*functionDrawPolygonWire)(meshPosition,polygon);

    edk::GU::guPopMatrix();
    return ret;
}
void edk::Object3D::drawNormals(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackNormals();

    (this->*functionDrawNormals)();

    this->drawChildremsFrontNormals();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawNormalsWithColor(edk::color3f32 color){
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->drawChildremsBackNormalsWithColor(color);

    (this->*functionDrawNormalsWithColor)(color);

    this->drawChildremsFrontNormalsWithColor(color);

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawNormalsWithColor(edk::float32 r,edk::float32 g,edk::float32 b){
    this->drawNormalsWithColor(edk::color3f32(r,g,b));
}
//draw the mesh with projection matrix
void edk::Object3D::drawWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix){
    if(matrix){
        this->calculateMatrices();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);

        edk::uint32 size = this->meshes.size();
        edk::Object3D::MeshAlloc* value;
        for(edk::uint32 i=0u;i<size;i++){
            value = this->meshes.get(i);
            if(value->getMesh()->material.haveOneTexture()){
                value->getMesh()->drawOneTextureWithMatrix(&this->matrixTransform,&this->matrixTemp);
            }
            else{
                value->getMesh()->drawMultiTextureWithMatrix(&this->matrixTransform,&this->matrixTemp);
            }
        }
    }
}
void edk::Object3D::drawWithMatrixWithoutMaterial(edk::vector::Matrixf32<4u,4u>* matrix){
    if(matrix){
        this->calculateMatrices();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);

        edk::uint32 size = this->meshes.size();
        edk::Object3D::MeshAlloc* value;
        for(edk::uint32 i=0u;i<size;i++){
            value = this->meshes.get(i);
            value->getMesh()->drawWithoutMaterialWithMatrix(&this->matrixTransform,&this->matrixTemp);
        }
    }
}
void edk::Object3D::drawWithMatrixWithoutMaterialWithLight(edk::vector::Matrixf32<4u,4u>* matrix){
    if(matrix){
        this->calculateMatrices();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);

        bool haveLight=false;

        {
            //edk::vec3f32 temp;
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
        if(haveLight){
            edk::GU::guEnable(GU_LIGHTING);
            edk::uint32 size = this->meshes.size();
            edk::Object3D::MeshAlloc* value;
            for(edk::uint32 i=0u;i<size;i++){
                value = this->meshes.get(i);
                value->getMesh()->drawWithoutMaterialWithMatrix(&this->matrixTransform,&this->matrixTemp);
            }
            edk::GU::guDisable(GU_LIGHTING);
        }
        else{
            edk::uint32 size = this->meshes.size();
            edk::Object3D::MeshAlloc* value;
            for(edk::uint32 i=0u;i<size;i++){
                value = this->meshes.get(i);
                value->getMesh()->drawWithoutMaterialWithMatrix(&this->matrixTransform,&this->matrixTemp);
            }
        }
    }
}
void edk::Object3D::drawWireWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix){
    if(matrix){
        this->calculateMatrices();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);

        edk::uint32 size = this->meshes.size();
        edk::Object3D::MeshAlloc* value;
        for(edk::uint32 i=0u;i<size;i++){
            value = this->meshes.get(i);
            value->getMesh()->drawWireWithMatrix(&this->matrixTransform,&this->matrixTemp);
        }
    }
}
void edk::Object3D::drawNormalsWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix){
    if(matrix){
        this->calculateMatrices();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);

        edk::uint32 size = this->meshes.size();
        edk::Object3D::MeshAlloc* value;
        for(edk::uint32 i=0u;i<size;i++){
            value = this->meshes.get(i);
            value->getMesh()->drawWireWithMatrix(&this->matrixTransform,&this->matrixTemp);
        }
    }
}
void edk::Object3D::drawNormalsWithMatrixWithColor(edk::vector::Matrixf32<4u,4u>* matrix,edk::color3f32 color){
    if(matrix){
        this->calculateMatrices();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);

        edk::uint32 size = this->meshes.size();
        edk::Object3D::MeshAlloc* value;
        for(edk::uint32 i=0u;i<size;i++){
            value = this->meshes.get(i);
            value->getMesh()->drawWireWithColorWithMatrix(&this->matrixTransform,&this->matrixTemp,edk::color4f32(color.r,color.g,color.b,1.f));
        }
    }
}
void edk::Object3D::drawNormalsWithMatrixWithColor(edk::vector::Matrixf32<4u,4u>* matrix,edk::float32 r,edk::float32 g,edk::float32 b){
    if(matrix){
        this->calculateMatrices();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);

        edk::uint32 size = this->meshes.size();
        edk::Object3D::MeshAlloc* value;
        for(edk::uint32 i=0u;i<size;i++){
            value = this->meshes.get(i);
            value->getMesh()->drawWireWithColorWithMatrix(&this->matrixTransform,&this->matrixTemp,edk::color4f32(r,g,b,1.f));
        }
    }
}

//draw the pivo
void edk::Object3D::drawPivo(edk::float32 size,edk::color3f32 color){
    if(this->childremsBack.size()){
        edk::GU::guPushMatrix();
        //add translate
        edk::GU::guTranslate3f32(this->position);
        //add rotation
        edk::GU::guRotateZf32(this->angle.x);
        //add scale
        edk::GU::guScale3f32(this->size);
        //set the pivo
        edk::GU::guTranslate3f32(this->pivo*-1.0f);
        this->drawChildremsBackPivo(size,color);
        edk::GU::guPopMatrix();
    }
    edk::Object3D::drawPivoInPosition(this->position,0.f,size,color);
    if(this->childremsFront.size()){
        edk::GU::guPushMatrix();
        //add translate
        edk::GU::guTranslate3f32(this->position);
        //add rotation
        edk::GU::guRotateZf32(this->angle.x);
        //add scale
        edk::GU::guScale3f32(this->size);
        //set the pivo
        edk::GU::guTranslate3f32(this->pivo*-1.0f);
        this->drawChildremsFrontPivo(size,color);
        edk::GU::guPopMatrix();
    }
}
void edk::Object3D::drawPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.z);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);
    if(this->childremsBack.size()){
        this->drawChildremsBackPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();


    edk::GU::guPushMatrix();
    //add translate
    //edk::GU::guTranslate3f32(this->position);

    edk::Object3D::drawPivoInPosition(this->position,this->angle.z,size,edk::color3f32(r,g,b));

    edk::GU::guPopMatrix();

    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.z);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);
    if(this->childremsFront.size()){
        this->drawChildremsFrontPivo(size,r,g,b);
    }
    edk::GU::guPopMatrix();
}
void edk::Object3D::drawPivoInPosition(edk::vec3f32 position,edk::float32 angle,edk::float32 size,edk::color3f32 color){
    //
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(position);
    //add rotation
    edk::GU::guRotateYf32(angle);
    //add scale
    edk::GU::guScale3f32(edk::size3f32(size,size,size));

    //lineSize
    edk::GU::guLineWidth(3);

    //set the colors
    edk::GU::guColor3f32(color);
    //draw the lines
    edk::GU::guBegin(GU_LINES);
    //LINE 1
    edk::GU::guVertex3f32(-0.5f,-0.5f,0.f);
    edk::GU::guVertex3f32( 0.5f, 0.5f,0.f);
    //LINE 2
    edk::GU::guVertex3f32(-0.5f, 0.5f,0.f);
    edk::GU::guVertex3f32( 0.5f,-0.5f,0.f);
    //LINE 3
    edk::GU::guVertex3f32(0.0f, 0.5f,-0.5f);
    edk::GU::guVertex3f32(0.0f,-0.5f, 0.5f);
    //LINE 4
    edk::GU::guVertex3f32(0.0f, 0.5f, 0.5f);
    edk::GU::guVertex3f32(0.0f,-0.5f,-0.5f);
    edk::GU::guEnd();

    //lineSize
    edk::GU::guLineWidth(1);

    //
    edk::GU::guPopMatrix();
}
void edk::Object3D::drawPivoInPosition(edk::float32 x,edk::float32 y,edk::float32 z,
                                       edk::float32 angle,
                                       edk::float32 size,
                                       edk::color3f32 color
                                       ){
    edk::Object3D::drawPivoInPosition(edk::vec3f32(x,y,z),angle,size,color);
}
void edk::Object3D::drawPivoInPosition(edk::float32 x,edk::float32 y,edk::float32 z,
                                       edk::float32 angle,
                                       edk::float32 size,
                                       edk::float32 r,edk::float32 g,edk::float32 b
                                       ){
    edk::Object3D::drawPivoInPosition(edk::vec3f32(x,y,z),angle,size,edk::color3f32(r,g,b));
}

//XML
bool edk::Object3D::writeToXML(edk::XML* xml,edk::uint32 id){
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
                        edk::shape::Mesh3D* mesh;
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
                        temp = edk::String::float32ToStr(this->pivo.z);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"pivoZ",temp);
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
                        temp = edk::String::float32ToStr(this->position.z);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"positionZ",temp);
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
                        temp = edk::String::float32ToStr(this->size.length);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"sizeL",temp);
                            free(temp);
                        }
                        //angle
                        temp = edk::String::float32ToStr(this->angle.x);
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
bool edk::Object3D::readFromXML(edk::XML* xml,edk::uint32 id){
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
                    edk::shape::Mesh3D* mesh;
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
                    this->pivo = edk::vec3f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoX")),
                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoY")),
                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoZ"))
                                              );
                    //read the object values
                    //position
                    this->position = edk::vec3f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionX")),
                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionY")),
                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionZ"))
                                                  );
                    //size
                    this->size = edk::size3f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeW")),
                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeH")),
                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeZ"))
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
bool edk::Object3D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
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
                    edk::shape::Mesh3D* mesh;
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
                    this->pivo = edk::vec3f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoX")),
                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoY")),
                                              edk::String::strToFloat32(xml->getSelectedAttributeValueByName("pivoZ"))
                                              );
                    //read the object values
                    //position
                    this->position = edk::vec3f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionX")),
                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionY")),
                                                  edk::String::strToFloat32(xml->getSelectedAttributeValueByName("positionZ"))
                                                  );
                    //size
                    this->size = edk::size3f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeW")),
                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeH")),
                                               edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeL"))
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
bool edk::Object3D::connectObjectBack(edk::Object3D* obj){
    if(obj){
        if(!obj->father){
            edk::uint32 size = this->childremsBack.size();
            this->childremsBack.pushBack(obj);
            if(size<this->childremsBack.size()){
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
                edk::shape::Mesh3D* mesh;

                //update the values
                obj->matrixTransform.setIdentity();
                obj->updateValuesFromFather(&obj->matrixTransform);

                if(obj->meshes.size()){
                    mesh = obj->meshes.getMesh(0u);
                    if(mesh){
                        //calculate the position
                        obj->position = mesh->generateBoundingPoint(edk::vec3f32(0.f,0.f,0.f),&obj->matrixTransform);
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
                edk::shape::Mesh3D* mesh;

                //update the values
                obj->matrixTransform.setIdentity();
                obj->updateValuesFromFather(&obj->matrixTransform);

                if(obj->meshes.size()){
                    mesh = obj->meshes.getMesh(0u);
                    if(mesh){
                        //calculate the position
                        ret = mesh->generateBoundingPoint(edk::vec3f32(0.f,0.f,0.f),&obj->matrixTransform);
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
void edk::Object3D::cleanConnectedObjectsBack(){
    edk::uint32 size = this->childremsBack.size();
    edk::Object3D* obj;
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
bool edk::Object3D::connectObjectFront(edk::Object3D* obj){
    if(obj){
        if(!obj->father){
            edk::uint32 size = this->childremsFront.size();
            this->childremsFront.pushBack(obj);
            if(size<this->childremsFront.size()){
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
                edk::shape::Mesh3D* mesh;

                //update the values
                obj->matrixTransform.setIdentity();
                obj->updateValuesFromFather(&obj->matrixTransform);

                if(obj->meshes.size()){
                    mesh = obj->meshes.getMesh(0u);
                    if(mesh){
                        //calculate the position
                        obj->position = mesh->generateBoundingPoint(edk::vec3f32(0.f,0.f,0.f),&obj->matrixTransform);
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
                edk::shape::Mesh3D* mesh;

                //update the values
                obj->matrixTransform.setIdentity();
                obj->updateValuesFromFather(&obj->matrixTransform);

                if(obj->meshes.size()){
                    mesh = obj->meshes.getMesh(0u);
                    if(mesh){
                        //calculate the position
                        ret = mesh->generateBoundingPoint(edk::vec3f32(0.f,0.f,0.f),&obj->matrixTransform);
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
void edk::Object3D::cleanConnectedObjectsFront(){
    edk::uint32 size = this->childremsFront.size();
    edk::Object3D* obj;
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
bool edk::Object3D::updateConnectedObjectValues(edk::Object3D* obj){
    if(obj){
        if(obj->father == this){
            if(this->childremsBack.haveElement(obj) || this->childremsFront.haveElement(obj)){
                edk::shape::Mesh3D* mesh;

                //update the values
                obj->matrixTransform.setIdentity();
                obj->updateValuesFromFather(&obj->matrixTransform);

                if(obj->meshes.size()){
                    mesh = obj->meshes.getMesh(0u);
                    if(mesh){
                        //calculate the position
                        obj->position = mesh->generateBoundingPoint(edk::vec3f32(0.f,0.f,0.f),&obj->matrixTransform);
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
                edk::shape::Mesh3D* mesh;

                //update the values
                obj->matrixTransform.setIdentity();
                obj->updateValuesFromFather(&obj->matrixTransform);

                if(obj->meshes.size()){
                    mesh = obj->meshes.getMesh(0u);
                    if(mesh){
                        //calculate the position
                        ret = mesh->generateBoundingPoint(edk::vec3f32(0.f,0.f,0.f),&obj->matrixTransform);
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
        this->cleanSelected();
        this->cleanMeshes();

        //copy the meshs
        edk::uint32 size = obj->meshes.size();
        edk::shape::Mesh3D* temp = NULL;
        edk::shape::Mesh3D* mesh = NULL;
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
                    edk::Object3D::ActionPosition* temp = (edk::Object3D::ActionPosition*)obj->actions.getActionInKey(i,j);
                    this->actions.addAction(second,new edk::Object3D::ActionPosition(this,temp->getPosition()));
                    break;
                }
                case 2u:
                {
                    //ActionMove
                    edk::Object3D::ActionMove* temp = (edk::Object3D::ActionMove*)obj->actions.getActionInKey(i,j);
                    this->actions.addAction(second,new edk::Object3D::ActionMove(this,temp->getDuration(),temp->getPosition()));
                    break;
                }
                case 3u:
                {
                    //ActionSetSize
                    edk::Object3D::ActionSetSize* temp = (edk::Object3D::ActionSetSize*)obj->actions.getActionInKey(i,j);
                    this->actions.addAction(second,new edk::Object3D::ActionSetSize(this,temp->getSize()));
                    break;
                }
                case 4u:
                {
                    //ActionSize
                    edk::Object3D::ActionSize* temp = (edk::Object3D::ActionSize*)obj->actions.getActionInKey(i,j);
                    this->actions.addAction(second,new edk::Object3D::ActionSize(this,temp->getDuration(),temp->getSize()));
                    break;
                }
                case 5u:
                {
                    //ActionSetAngle
                    edk::Object3D::ActionSetAngle* temp = (edk::Object3D::ActionSetAngle*)obj->actions.getActionInKey(i,j);
                    this->actions.addAction(second,new edk::Object3D::ActionSetAngle(this,temp->getAngle()));
                    break;
                }
                case 6u:
                {
                    //ActionAngle
                    edk::Object3D::ActionAngle* temp = (edk::Object3D::ActionAngle*)obj->actions.getActionInKey(i,j);
                    this->actions.addAction(second,new edk::Object3D::ActionAngle(this,temp->getDuration(),temp->getAngle()));
                    break;
                }
                case 7u:
                {
                    //ActionMeshName
                    edk::Object3D::ActionMeshName* temp = (edk::Object3D::ActionMeshName*)obj->actions.getActionInKey(i,j);
                    this->actions.addAction(second,new edk::Object3D::ActionMeshName(this,temp->getId(),temp->getName(),temp->getLoop()));
                    break;
                }
                case 8u:
                {
                    //ActionMeshStop
                    edk::Object3D::ActionMeshStop* temp = (edk::Object3D::ActionMeshStop*)obj->actions.getActionInKey(i,j);
                    this->actions.addAction(second,new edk::Object3D::ActionMeshStop(this,temp->getId()));
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
bool edk::Object3D::addMeshFrom(edk::Object3D* obj){
    if(obj){
        //copy the meshs
        edk::uint32 size = obj->meshes.size();
        edk::shape::Mesh3D* temp = NULL;
        edk::shape::Mesh3D* mesh = NULL;
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
bool edk::Object3D::addMeshFrom(edk::shape::Mesh3D* mesh){
    if(mesh){
        edk::shape::Mesh3D* temp = this->newMesh();
        if(temp){
            //*mesh = *temp;
            temp->cloneFrom(mesh);
            return true;
        }
    }
    return false;
}
