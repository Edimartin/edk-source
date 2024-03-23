#include "Object3D.h"

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

edk::Object3D::Object3D(){
    //
    this->loadIdentityValues();edkEnd();
    this->father=NULL;
}
edk::Object3D::~Object3D(){
    //
    this->clean();
}

void edk::Object3D::calculateMatrices(){
    //generate the matrices
    this->matrixTransform.setIdentity(1.f,0.f);edkEnd();
    edk::Math::generateTranslateMatrix(this->position,&this->matrixTranslate);edkEnd();
    edk::Math::generateRotateMatrixX(this->angle.x,&this->matrixRotateX);edkEnd();
    edk::Math::generateRotateMatrixY(this->angle.y,&this->matrixRotateY);edkEnd();
    edk::Math::generateRotateMatrixZ(this->angle.z,&this->matrixRotateZ);edkEnd();
    edk::Math::generateScaleMatrix(this->size,&this->matrixScale);edkEnd();
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixTranslate);edkEnd();
    //this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotate);edkEnd();
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotateX);edkEnd();
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotateY);edkEnd();
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotateZ);edkEnd();
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixScale);edkEnd();
    edk::Math::generateTranslateMatrix(this->pivo*-1.f,&this->matrixTranslate);edkEnd();
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixTranslate);edkEnd();
}
//draw the mesh
void edk::Object3D::drawChildrems(){
    edk::uint32 size = this->childrems.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childrems.getElementInPosition(i);
        obj->draw();
    }
}
void edk::Object3D::drawChildremsWithoutMaterial(){
    edk::uint32 size = this->childrems.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childrems.getElementInPosition(i);
        obj->drawWithoutMaterial();
    }
}
void edk::Object3D::drawChildremsWithoutMaterialWithLight(){
    edk::uint32 size = this->childrems.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childrems.getElementInPosition(i);
        obj->drawWithoutMaterialWithLight();
    }
}
void edk::Object3D::drawChildremsWire(){
    edk::uint32 size = this->childrems.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childrems.getElementInPosition(i);
        obj->drawWire();
    }
}
void edk::Object3D::drawChildremsNormals(){
    edk::uint32 size = this->childrems.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childrems.getElementInPosition(i);
        obj->drawNormals();
    }
}
void edk::Object3D::drawChildremsNormalsWithColor(edk::color3f32 color){
    edk::uint32 size = this->childrems.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childrems.getElementInPosition(i);
        obj->drawNormalsWithColor(color);
    }
}
void edk::Object3D::drawChildremsNormalsWithColor(edk::float32 r,edk::float32 g,edk::float32 b){
    edk::uint32 size = this->childrems.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childrems.getElementInPosition(i);
        obj->drawNormalsWithColor(r,g,b);
    }
}
//draw the pivo
void edk::Object3D::drawChildremsPivo(edk::float32 size,edk::color3f32 color){
    edk::uint32 cSize = this->childrems.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childrems.getElementInPosition(i);
        obj->drawPivo(size,color);
    }
}
void edk::Object3D::drawChildremsPivoWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::float32 size,edk::color3f32 color){
    edk::uint32 cSize = this->childrems.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<cSize;i++){
        obj = this->childrems.getElementInPosition(i);
        obj->drawPivoWithMatrix(matrix,size,color);
    }
}

//load the mtlFile
bool edk::Object3D::loadMTL(const edk::char8* fileName,edk::shape::Mesh3D* mesh){
    return this->loadMTL((edk::char8*) fileName,mesh);
}
bool edk::Object3D::loadMTL(edk::char8* fileName,edk::shape::Mesh3D* mesh){
    if(fileName && mesh){
        //open the file
        edk::File file;
        if(file.openTextFile(fileName)){
            edk::char8 c;edkEnd();
            edk::char8* str;edkEnd();
            edk::char8* temp;edkEnd();
            edk::int32 illum=0u;

            edk::float32 Ns=0.f;
            edk::float32 Ni=0.f;

            edk::color3f32 Ka,Kd,Ks,Ke;
            edk::Name mapKd,mapBump,mapKa;

            edk::float32 dValue=0.f;

            edk::char8* folder = edk::String::strFolderName(fileName);

            while(!file.endOfFile()){
                c = file.readTextChar();edkEnd();
                switch(c){
                case '#':
                    //comentario
                    str = file.readTextString("\n",false);edkEnd();
                    if(str){
                        free(str);edkEnd();
                    }
                    //printf("\nComentario");fflush(stdout);edkEnd();
                    break;
                case 'n':
                    //newmtl - name of the material
                    if(file.readTextChar() == 'e'){
                        if(file.readTextChar() == 'w'){
                            if(file.readTextChar() == 'm'){
                                if(file.readTextChar() == 't'){
                                    if(file.readTextChar() == 'l'){
                                        if(file.readTextChar() == ' '){
                                            //find the material name
                                            str = file.readTextString("\n",false);edkEnd();
                                            if(str){
                                                //printf("\nMaterial name == '%s'",str);fflush(stdout);edkEnd();
                                                free(str);edkEnd();
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    break;

                case 'i':
                    //illum
                    if(file.readTextChar() == 'l'){
                        if(file.readTextChar() == 'l'){
                            if(file.readTextChar() == 'u'){
                                if(file.readTextChar() == 'm'){
                                    if(file.readTextChar() == ' '){
                                        //read the ilum value
                                        str = file.readTextString("\n",false);edkEnd();
                                        if(str){
                                            illum = edk::String::strToInt32(str);
                                            //printf("\nIllum == '%s' [%d]",str,illum);fflush(stdout);edkEnd();
                                            free(str);edkEnd();
                                        }
                                    }
                                }
                            }
                        }
                    }
                    break;
                case 'N':
                    //Ns
                    if(file.readTextChar() == 's'){
                        if(file.readTextChar() == ' '){
                            //read the ilum value
                            str = file.readTextString("\n",false);edkEnd();
                            if(str){
                                Ns = edk::String::strToFloat32(str);
                                //printf("\nNs == '%s' [%.2f]",str,Ns);fflush(stdout);edkEnd();
                                free(str);edkEnd();
                            }
                        }
                    }
                    else if(file.readTextChar() == 'i'){
                        if(file.readTextChar() == ' '){
                            //read the ilum value
                            str = file.readTextString("\n",false);edkEnd();
                            if(str){
                                Ni = edk::String::strToFloat32(str);
                                //printf("\nNi == '%s' [%.2f]",str,Ni);fflush(stdout);edkEnd();
                                free(str);edkEnd();
                            }
                        }
                    }
                    break;
                case 'd':
                    if(file.readTextChar() == ' '){
                        //read the ilum value
                        str = file.readTextString("\n",false);edkEnd();
                        if(str){
                            dValue = edk::String::strToFloat32(str);
                            //printf("\nd == '%s' [%.2f]",str,dValue);fflush(stdout);edkEnd();
                            free(str);edkEnd();
                        }
                    }
                    break;
                case 'K':
                    c = file.readTextChar();
                    //Ka
                    if(c == 'a'){
                        if(file.readTextChar() == ' '){
                            //read the ilum value
                            str = file.readTextString("\n",false);edkEnd();
                            if(str){
                                temp = str;edkEnd();
                                if(*temp){
                                    Ka.r = edk::String::strToFloat32(temp);edkEnd();
                                }
                                //search for the ' ';
                                while(*temp){
                                    if(*temp==' '){
                                        temp++;edkEnd();
                                        break;
                                    }
                                    temp++;edkEnd();
                                }
                                if(*temp){
                                    Ka.g = edk::String::strToFloat32(temp);edkEnd();
                                }
                                //search for the ' ';
                                while(*temp){
                                    if(*temp==' '){
                                        temp++;edkEnd();
                                        break;
                                    }
                                    temp++;edkEnd();
                                }
                                if(*temp){
                                    Ka.b = edk::String::strToFloat32(temp);edkEnd();
                                }
                                //printf("\nKa == '%s' r[%.2f] g[%.2f] b[%.2f]",str,Ka.r,Ka.g,Ka.b);fflush(stdout);edkEnd();
                                free(str);edkEnd();
                            }
                        }
                    }
                    //Kd
                    else if(c == 'd'){
                        if(file.readTextChar() == ' '){
                            //read the ilum value
                            str = file.readTextString("\n",false);edkEnd();
                            if(str){
                                temp = str;edkEnd();
                                if(*temp){
                                    Kd.r = edk::String::strToFloat32(temp);edkEnd();
                                }
                                //search for the ' ';
                                while(*temp){
                                    if(*temp==' '){
                                        temp++;edkEnd();
                                        break;
                                    }
                                    temp++;edkEnd();
                                }
                                if(*temp){
                                    Kd.g = edk::String::strToFloat32(temp);edkEnd();
                                }
                                //search for the ' ';
                                while(*temp){
                                    if(*temp==' '){
                                        temp++;edkEnd();
                                        break;
                                    }
                                    temp++;edkEnd();
                                }
                                if(*temp){
                                    Kd.b = edk::String::strToFloat32(temp);edkEnd();
                                }
                                //printf("\nKd == '%s' r[%.2f] g[%.2f] b[%.2f]",str,Kd.r,Kd.g,Kd.b);fflush(stdout);edkEnd();
                                free(str);edkEnd();
                            }
                        }
                    }
                    //Ks
                    else if(c == 's'){
                        if(file.readTextChar() == ' '){
                            //read the ilum value
                            str = file.readTextString("\n",false);edkEnd();
                            if(str){
                                temp = str;edkEnd();
                                if(*temp){
                                    Ks.r = edk::String::strToFloat32(temp);edkEnd();
                                }
                                //search for the ' ';
                                while(*temp){
                                    if(*temp==' '){
                                        temp++;edkEnd();
                                        break;
                                    }
                                    temp++;edkEnd();
                                }
                                if(*temp){
                                    Ks.g = edk::String::strToFloat32(temp);edkEnd();
                                }
                                //search for the ' ';
                                while(*temp){
                                    if(*temp==' '){
                                        temp++;edkEnd();
                                        break;
                                    }
                                    temp++;edkEnd();
                                }
                                if(*temp){
                                    Ks.b = edk::String::strToFloat32(temp);edkEnd();
                                }
                                //printf("\nKs == '%s' r[%.2f] g[%.2f] b[%.2f]",str,Ks.r,Ks.g,Ks.b);fflush(stdout);edkEnd();
                                free(str);edkEnd();
                            }
                        }
                    }
                    //Ke
                    else if(c == 'e'){
                        if(file.readTextChar() == ' '){
                            //read the ilum value
                            str = file.readTextString("\n",false);edkEnd();
                            if(str){
                                temp = str;edkEnd();
                                if(*temp){
                                    Ke.r = edk::String::strToFloat32(temp);edkEnd();
                                }
                                //search for the ' ';
                                while(*temp){
                                    if(*temp==' '){
                                        temp++;edkEnd();
                                        break;
                                    }
                                    temp++;edkEnd();
                                }
                                if(*temp){
                                    Ke.g = edk::String::strToFloat32(temp);edkEnd();
                                }
                                //search for the ' ';
                                while(*temp){
                                    if(*temp==' '){
                                        temp++;edkEnd();
                                        break;
                                    }
                                    temp++;edkEnd();
                                }
                                if(*temp){
                                    Ke.b = edk::String::strToFloat32(temp);edkEnd();
                                }
                                //printf("\nKe == '%s' r[%.2f] g[%.2f] b[%.2f]",str,Ke.r,Ke.g,Ke.b);fflush(stdout);edkEnd();
                                free(str);edkEnd();
                            }
                        }
                    }
                    break;
                case 'm':
                    //textures
                    if(file.readTextChar() == 'a'){
                        if(file.readTextChar() == 'p'){
                            if(file.readTextChar() == '_'){
                                c = file.readTextChar();
                                if(c == 'K'){
                                    c = file.readTextChar();
                                    if(c == 'd'){
                                        if(file.readTextChar() == ' '){
                                            //texture Kd
                                            str = file.readTextString("\n",false);edkEnd();
                                            if(str){
                                                if(folder){
                                                    temp = edk::String::strCatMulti(folder,str,NULL);
                                                    if(temp){
                                                        mapKd.setName(temp);
                                                        //printf("\nTexture Kd == '%s' == '%s'",temp,mapKd.getName());fflush(stdout);edkEnd();
                                                        free(temp);
                                                    }
                                                }
                                                else{
                                                    mapKd.setName(str);
                                                    //printf("\nTexture Kd == '%s' == '%s'",str,mapKd.getName());fflush(stdout);edkEnd();
                                                }
                                                free(str);edkEnd();
                                            }
                                        }
                                    }
                                    else if(c == 'a'){
                                        if(file.readTextChar() == ' '){
                                            //texture Ka
                                            str = file.readTextString("\n",false);edkEnd();
                                            if(str){
                                                if(folder){
                                                    temp = edk::String::strCatMulti(folder,str,NULL);
                                                    if(temp){
                                                        mapKa.setName(temp);
                                                        //printf("\nTexture Ka == '%s' == '%s'",temp,mapKa.getName());fflush(stdout);edkEnd();
                                                        free(temp);
                                                    }
                                                }
                                                else{
                                                    mapKa.setName(str);
                                                    //printf("\nTexture Ka == '%s' == '%s'",str,mapKa.getName());fflush(stdout);edkEnd();
                                                }
                                                free(str);edkEnd();
                                            }
                                        }
                                    }
                                }
                                else if(c == 'B'){
                                    if(file.readTextChar() == 'u'){
                                        if(file.readTextChar() == 'm'){
                                            if(file.readTextChar() == 'p'){
                                                if(file.readTextChar() == ' '){
                                                    //texture bumpMap
                                                    str = file.readTextString("\n",false);edkEnd();
                                                    if(str){
                                                        if(folder){
                                                            temp = edk::String::strCatMulti(folder,str,NULL);
                                                            if(temp){
                                                                mapBump.setName(temp);
                                                                //printf("\nTexture Bump == '%s' == '%s'",temp,mapBump.getName());fflush(stdout);edkEnd();
                                                                free(temp);
                                                            }
                                                        }
                                                        else{
                                                            mapBump.setName(str);
                                                            //printf("\nTexture Bump == '%s' == '%s'",str,mapBump.getName());fflush(stdout);edkEnd();
                                                        }
                                                        free(str);edkEnd();
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    break;
                }
            }
            if(folder){
                free(folder);
            }
            mesh->material.loadTexture(mapKd.getName(),0u);
            mesh->material.loadTexture(mapKa.getName(),1u);
            mesh->material.loadTexture(mapBump.getName(),2u);
            mesh->material.setAmbient(Ka);
            mesh->material.setDiffuse(Kd);
            mesh->material.setSpecular(Ks);
            mesh->material.setEmission(Ke);
            mesh->material.setShininess(Ns);

            file.closeFile();
            return true;
        }
    }
    return false;
}

void edk::Object3D::clean(){
    this->cleanSelected();
    this->cleanMeshes();
}

//get the bodyType
edk::TypeObject edk::Object3D::getType(){
    return edk::TypeObject3D;
}

//create a new mesh and add to the meshs stack
edk::shape::Mesh3D* edk::Object3D::newMesh(edk::uint32* position){
    return this->meshes.pushNewMesh(position);edkEnd();
}
//Add a list to the Object2D
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
bool edk::Object3D::setPolygonsColor(edk::color4f32 color){
    edk::uint32 size = this->meshes.size();edkEnd();
    edk::shape::Mesh3D* temp;edkEnd();
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->meshes.getMesh(i);edkEnd();
            if(temp){
                temp->setPolygonsColor(color);edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::Object3D::setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setPolygonsColor(edk::color4f32(r,g,b,a));edkEnd();
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

//LIGHT
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
        //open the file
        edk::File file;edkEnd();
        if(file.openTextFile(fileName)){
            bool ret = true;edkEnd();
            edk::char8 c;edkEnd();
            edk::char8* str;edkEnd();
            edk::char8* temp;edkEnd();
            edk::char8* ve;edkEnd();
            edk::uint8 read;edkEnd();
            edk::uint32 v,n,p;edkEnd();
            edk::uint32 countV=0u;
            edk::uint32 countP=0u;
            edk::uint32 countN=0u;
            edk::float32 x,y,z;edkEnd();

            edk::vector::Stack<edk::uint32> sv(1000u),sp(1000u),sn(1000u);edkEnd();

            edk::shape::Mesh3D* mesh = NULL;edkEnd();
            edk::uint32 meshes=0u;
            bool smooth = false;edkEnd();

            edk::char8* folder = edk::String::strFolderName(fileName);

            while(!file.endOfFile()){
                c = file.readTextChar();edkEnd();
                switch(c){
                case '#':
                    //comentario
                    str = file.readTextString("\n",false);edkEnd();
                    if(str){
                        free(str);edkEnd();
                    }
                    //printf("\nComentario");edkEnd();
                    break;
                    //mtllib cubes.mtl
                case 'm':
                    if(file.readTextChar() == 't'){
                        if(file.readTextChar() == 'l'){
                            if(file.readTextChar() == 'l'){
                                if(file.readTextChar() == 'i'){
                                    if(file.readTextChar() == 'b'){
                                        if(file.readTextChar() == ' '){
                                            //readthe mtlFile
                                            str = file.readTextString("\n",false);edkEnd();
                                            if(str){
                                                if(!mesh){
                                                    mesh=this->newMesh();edkEnd();
                                                }
                                                //test if have the folder
                                                if(folder){
                                                    //concat to generate the mtl new name
                                                    temp = edk::String::strCatMulti(folder,str,NULL);
                                                    if(temp){
                                                        //printf("\nTry load MTL == '%s'",temp);fflush(stdout);edkEnd();
                                                        if(this->loadMTL(temp,mesh)){
                                                            //printf("\nMTL LIB == '%s'",temp);fflush(stdout);edkEnd();
                                                        }
                                                        else{
                                                            //printf("\nERROR: Can't load MTL == '%s'",temp);fflush(stdout);edkEnd();
                                                        }
                                                        free(temp);
                                                    }
                                                }
                                                else{
                                                    //printf("\nTry load MTL == '%s'",str);fflush(stdout);edkEnd();
                                                    if(this->loadMTL(str,mesh)){
                                                        //printf("\nMTL LIB == '%s'",str);fflush(stdout);edkEnd();
                                                    }
                                                    else{
                                                        //printf("\nERROR: Can't load MTL == '%s'",str);fflush(stdout);edkEnd();
                                                    }
                                                }
                                                free(str);edkEnd();
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    break;
                case 'o':
                case 'g':
                    if(file.readTextChar() == ' '){
                        str = file.readTextString("\n",false);edkEnd();
                        if(str){
                            //printf("\nNEW OBJECT NAME == '%s'",str);edkEnd();
                            free(str);edkEnd();

                            if(mesh){
                                countV += mesh->getVertexSize();edkEnd();
                                countP += mesh->getUVSize();edkEnd();
                                countN += mesh->getNormalSize();edkEnd();
                                if(meshes){
                                    //create a new mesh
                                    mesh = this->newMesh();edkEnd();
                                    meshes++;
                                }
                            }
                            else{
                                //new mesh
                                mesh = this->newMesh();edkEnd();
                                meshes++;
                            }
                        }
                    }
                    break;
                case 'v':
                    if(!mesh){
                        mesh=this->newMesh();edkEnd();
                    }
                    c = file.readTextChar();edkEnd();
                    if(c == ' '){
                        //read the entire phrase
                        str = file.readTextString("\n",false);edkEnd();
                        if(str){
                            if(edk::String::strSize(str)){
                                //printf("\nStr == '%s'",str);fflush(stdout);edkEnd();
                                edk::uint8 pos=1u;
                                temp = str;
                                while(*temp){
                                    if(*temp!=' '){
                                        switch(pos){
                                        case 1u:
                                            //read the value
                                            x = edk::String::strToFloat32(temp);edkEnd();
                                            pos++;
                                            break;
                                        case 2u:
                                            //read the value
                                            y = edk::String::strToFloat32(temp);edkEnd();
                                            pos++;
                                            break;
                                        case 3u:
                                            //read the value
                                            z = edk::String::strToFloat32(temp);edkEnd();
                                            pos++;
                                            break;
                                        }
                                        //search for the next space ' '
                                        while(*temp){
                                            if(*temp==' '){
                                                break;
                                            }
                                            temp++;
                                        }
                                    }
                                    else{
                                        temp++;
                                    }
                                }
                            }
                            free(str);
                        }
                        //printf("\nNEW Vertex %.2f %.2f %.2f",x,y,z);fflush(stdout);edkEnd();
                        mesh->newVertex(x,y,z,1,1,1,1);edkEnd();
                    }
                    else if(c == 't'){
                        if(file.readTextChar() == ' '){
                            //read the entire phrase
                            str = file.readTextString("\n",false);edkEnd();
                            if(str){
                                if(edk::String::strSize(str)){
                                    //printf("\nStr == '%s'",str);fflush(stdout);edkEnd();
                                    edk::uint8 pos=1u;
                                    temp = str;
                                    while(*temp){
                                        if(*temp!=' '){
                                            switch(pos){
                                            case 1u:
                                                //read the value
                                                x = edk::String::strToFloat32(temp);edkEnd();
                                                pos++;
                                                break;
                                            case 2u:
                                                //read the value
                                                y = edk::String::strToFloat32(temp);edkEnd();
                                                pos++;
                                                break;
                                            case 3u:
                                                //read the value
                                                z = edk::String::strToFloat32(temp);edkEnd();
                                                pos++;
                                                break;
                                            }
                                            //search for the next space ' '
                                            while(*temp){
                                                if(*temp==' '){
                                                    break;
                                                }
                                                temp++;
                                            }
                                        }
                                        else{
                                            temp++;
                                        }
                                    }
                                }
                                free(str);
                            }
                            //printf("\nNEW Vertex Texture %.2f %.2f",x,y);edkEnd();
                            mesh->newUV(x,y);edkEnd();
                        }
                    }
                    else if(c == 'n'){
                        if(file.readTextChar() == ' '){
                            //read the entire phrase
                            str = file.readTextString("\n",false);edkEnd();
                            if(str){
                                if(edk::String::strSize(str)){
                                    //printf("\nStr == '%s'",str);fflush(stdout);edkEnd();
                                    edk::uint8 pos=1u;
                                    temp = str;
                                    while(*temp){
                                        if(*temp!=' '){
                                            switch(pos){
                                            case 1u:
                                                //read the value
                                                x = edk::String::strToFloat32(temp);edkEnd();
                                                pos++;
                                                break;
                                            case 2u:
                                                //read the value
                                                y = edk::String::strToFloat32(temp);edkEnd();
                                                pos++;
                                                break;
                                            case 3u:
                                                //read the value
                                                z = edk::String::strToFloat32(temp);edkEnd();
                                                pos++;
                                                break;
                                            }
                                            //search for the next space ' '
                                            while(*temp){
                                                if(*temp==' '){
                                                    break;
                                                }
                                                temp++;
                                            }
                                        }
                                        else{
                                            temp++;
                                        }
                                    }
                                }
                                free(str);
                            }
                            //printf("\nNEW Vertex Normal %.2f %.2f %.2f",x,y,z);fflush(stdout);edkEnd();
                            mesh->newNormal(x,y,z);edkEnd();
                        }
                    }
                    break;
                case 's':
                    if(!mesh){
                        mesh=this->newMesh();edkEnd();
                    }
                    if(file.readTextChar() == ' '){
                        str = file.readTextString("\n",false);edkEnd();
                        if(str){
                            if(str[0u]=='o'){
                                if(str[1u]=='f'){
                                    if(str[2u]=='f'){
                                        //
                                        //printf("\nSMOOTH FALSE '%s'",str);edkEnd();
                                        smooth=false;edkEnd();
                                    }
                                }
                            }
                            else if(str[0u]=='0'){
                                //
                                //printf("\nSMOOTH FALSE '%s'",str);edkEnd();
                                smooth=false;edkEnd();
                            }
                            else if(str[0u]=='1'){
                                //
                                //printf("\nSMOOTH TRUE '%s'",str);edkEnd();
                                smooth=true;edkEnd();
                            }
                            free(str);edkEnd();
                        }
                    }
                    else{
                        str = file.readTextString("\n",false);edkEnd();
                        if(str){
                            free(str);edkEnd();
                        }
                    }
                    break;
                case 'f':
                    if(!mesh){
                        mesh=this->newMesh();edkEnd();
                    }
                    if(file.readTextChar() == ' '){
                        //
                        str = file.readTextString("\n",true);edkEnd();
                        if(str){
                            ve = temp = str;edkEnd();
                            read = 0u;edkEnd();
                            //printf("\n");edkEnd();

                            //printf("\nTEMP == '%s'",temp);fflush(stdout);


                            while(*temp){
                                switch(*temp){
                                case '/':
                                    //set the end of the string
                                    *temp = '\0';edkEnd();
                                    if(ve<temp){
                                        switch(read){
                                        case 0u:
                                            v = edk::String::strToInt64(ve);edkEnd();
                                            break;
                                        case 1u:
                                            p = edk::String::strToInt64(ve);edkEnd();
                                            break;
                                        case 2u:
                                            n = edk::String::strToInt64(ve);edkEnd();
                                            break;
                                        }
                                    }
                                    *temp = '/';edkEnd();
                                    //
                                    switch(read){
                                    case 0u:
                                        read = 1u;edkEnd();
                                        break;
                                    case 1u:
                                        read = 2u;edkEnd();
                                        break;
                                    case 2u:
                                        read = 3u;edkEnd();
                                        break;
                                    }


                                    ve = temp+1u;edkEnd();
                                    break;
                                case ' ':
                                case '\n':
                                    *temp = '\0';edkEnd();
                                    if(ve<temp){
                                        switch(read){
                                        case 0u:
                                            v = edk::String::strToInt64(ve);edkEnd();
                                            read = 1u;edkEnd();
                                            break;
                                        case 1u:
                                            p = edk::String::strToInt64(ve);edkEnd();
                                            read = 2u;edkEnd();
                                            break;
                                        case 2u:
                                            n = edk::String::strToInt64(ve);edkEnd();
                                            read = 3u;edkEnd();
                                            break;
                                        }


                                        switch(read){
                                        case 1u:
                                            /*
                                            printf(" Face %u"
                                                   ,v
                                                   );edkEnd();
                                                   */
                                            sv.pushBack(v);edkEnd();
                                            sp.pushBack(0u);edkEnd();
                                            sn.pushBack(0u);edkEnd();
                                            break;
                                        case 2u:
                                            /*
                                            printf(" Face %u/%u"
                                                   ,v
                                                   ,p
                                                   );edkEnd();
                                            */
                                            sv.pushBack(v);edkEnd();
                                            sp.pushBack(p);edkEnd();
                                            sn.pushBack(0u);edkEnd();
                                            break;
                                        case 3u:
                                            /*
                                            printf(" Face %u/%u/%u"
                                                   ,v
                                                   ,p
                                                   ,n
                                                   );edkEnd();
                                            */
                                            sv.pushBack(v);edkEnd();
                                            sp.pushBack(p);edkEnd();
                                            sn.pushBack(n);edkEnd();
                                            break;
                                        }
                                        v=p=n=0u;
                                        read=0u;
                                    }
                                    *temp = ' ';edkEnd();

                                    ve = temp+1u;edkEnd();
                                    break;
                                default:
                                    break;
                                }

                                temp++;edkEnd();
                            }

                            edk::uint32 size = sv.size();edkEnd();
                            if(size){
                                //printf(" NEW FACE");edkEnd();
                                edk::uint32 po = mesh->newPolygon(size);edkEnd();
                                mesh->selectPolygon(po);edkEnd();
                                mesh->selectedPolygonSetSmooth(smooth);edkEnd();
                                if(smooth){
                                    mesh->selectedPolygonUpdateNormal();edkEnd();
                                }
                                else{
                                    mesh->selectedPolygonSetNormalFlat(mesh->getNormal(sn.get(0u)-1u-countN));edkEnd();
                                }
                                for(edk::uint32 i=0u;i<size;i++){
                                    v = sv.get(i);edkEnd();
                                    p = sp.get(i);edkEnd();
                                    n = sn.get(i);edkEnd();
                                    if(v){
                                        mesh->selectedPolygonSetVertex(i,v-1u-countV);edkEnd();
                                        if(p){
                                            mesh->selectedPolygonSetUV(i,p-1u-countP);edkEnd();
                                            if(n){
                                                //
                                                mesh->selectedPolygonSetNormal(i,n-1u-countN);edkEnd();
                                            }
                                        }
                                        else{
                                            if(n){
                                                //
                                                mesh->selectedPolygonSetNormal(i,n-1u-countN);edkEnd();
                                            }
                                        }
                                    }
                                }
                            }

                            sv.clean();edkEnd();
                            sp.clean();edkEnd();
                            sn.clean();edkEnd();

                            free(str);edkEnd();
                        }
                    }
                    else{
                        str = file.readTextString("\n",false);edkEnd();
                        if(str){
                            free(str);edkEnd();
                        }
                    }
                    break;
                case 'u':
                    if(file.readTextChar() == 's'){
                        if(file.readTextChar() == 'e'){
                            if(file.readTextChar() == 'm'){
                                if(file.readTextChar() == 't'){
                                    if(file.readTextChar() == 'l'){
                                        if(file.readTextChar() == ' '){
                                            //readthe mtlFile
                                            str = file.readTextString("\n",false);edkEnd();
                                            if(str){
                                                //printf("\nUSE MTL == '%s'",str);edkEnd();
                                                free(str);edkEnd();
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    break;
                }
            }
            if(folder){
                free(folder);
            }

            file.closeFile();edkEnd();
            return ret;
        }
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

//DRAW
//print the mesh
void edk::Object3D::print(){
    //
    printf("\nOBJECT:");
    this->meshes.print();edkEnd();
}
//draw the mesh
void edk::Object3D::draw(){

    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    bool haveLight=false;edkEnd();

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

    if(this->father){
        //add translate
        edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
        //add rotation
        edk::GU::guRotateXf32(this->connectedAngle.x);edkEnd();
        edk::GU::guRotateYf32(this->connectedAngle.y);edkEnd();
        edk::GU::guRotateZf32(this->connectedAngle.z);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->connectedSize);edkEnd();
    }
    else{
        //add translate
        edk::GU::guTranslate3f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateXf32(this->angle.x);edkEnd();
        edk::GU::guRotateYf32(this->angle.y);edkEnd();
        edk::GU::guRotateZf32(this->angle.z);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->size);edkEnd();
    }
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    if(haveLight){
        //
        edk::GU::guEnable(GU_LIGHTING);edkEnd();
        this->meshes.render();edkEnd();
        edk::GU::guDisable(GU_LIGHTING);edkEnd();
    }
    else{
        this->meshes.render();edkEnd();
    }
    this->drawChildrems();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawWithoutMaterial(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    if(this->father){
        //add translate
        edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
        //add rotation
        edk::GU::guRotateXf32(this->connectedAngle.x);edkEnd();
        edk::GU::guRotateYf32(this->connectedAngle.y);edkEnd();
        edk::GU::guRotateZf32(this->connectedAngle.z);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->connectedSize);edkEnd();
    }
    else{
        //add translate
        edk::GU::guTranslate3f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateXf32(this->angle.x);edkEnd();
        edk::GU::guRotateYf32(this->angle.y);edkEnd();
        edk::GU::guRotateZf32(this->angle.z);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->size);edkEnd();
    }
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->meshes.drawWithoutMaterial();edkEnd();

    this->drawChildremsWithoutMaterial();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawWithoutMaterialWithLight(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();


    bool haveLight=false;edkEnd();

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

    if(this->father){
        //add translate
        edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
        //add rotation
        edk::GU::guRotateXf32(this->connectedAngle.x);edkEnd();
        edk::GU::guRotateYf32(this->connectedAngle.y);edkEnd();
        edk::GU::guRotateZf32(this->connectedAngle.z);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->connectedSize);edkEnd();
    }
    else{
        //add translate
        edk::GU::guTranslate3f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateXf32(this->angle.x);edkEnd();
        edk::GU::guRotateYf32(this->angle.y);edkEnd();
        edk::GU::guRotateZf32(this->angle.z);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->size);edkEnd();
    }
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    if(haveLight){
        edk::GU::guEnable(GU_LIGHTING);edkEnd();
        this->meshes.drawWithoutMaterial();edkEnd();
        edk::GU::guDisable(GU_LIGHTING);edkEnd();
    }
    else{
        this->meshes.drawWithoutMaterial();edkEnd();
    }

    this->drawChildremsWithoutMaterialWithLight();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawWire(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    if(this->father){
        //add translate
        edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
        //add rotation
        edk::GU::guRotateXf32(this->connectedAngle.x);edkEnd();
        edk::GU::guRotateYf32(this->connectedAngle.y);edkEnd();
        edk::GU::guRotateZf32(this->connectedAngle.z);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->connectedSize);edkEnd();
    }
    else{
        //add translate
        edk::GU::guTranslate3f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateXf32(this->angle.x);edkEnd();
        edk::GU::guRotateYf32(this->angle.y);edkEnd();
        edk::GU::guRotateZf32(this->angle.z);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->size);edkEnd();
    }
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->meshes.drawWire();edkEnd();

    this->drawChildremsWire();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawNormals(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    if(this->father){
        //add translate
        edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
        //add rotation
        edk::GU::guRotateXf32(this->connectedAngle.x);edkEnd();
        edk::GU::guRotateYf32(this->connectedAngle.y);edkEnd();
        edk::GU::guRotateZf32(this->connectedAngle.z);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->connectedSize);edkEnd();
    }
    else{
        //add translate
        edk::GU::guTranslate3f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateXf32(this->angle.x);edkEnd();
        edk::GU::guRotateYf32(this->angle.y);edkEnd();
        edk::GU::guRotateZf32(this->angle.z);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->size);edkEnd();
    }
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->meshes.drawNormals();edkEnd();

    this->drawChildremsNormals();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawNormalsWithColor(edk::color3f32 color){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    if(this->father){
        //add translate
        edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
        //add rotation
        edk::GU::guRotateXf32(this->connectedAngle.x);edkEnd();
        edk::GU::guRotateYf32(this->connectedAngle.y);edkEnd();
        edk::GU::guRotateZf32(this->connectedAngle.z);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->connectedSize);edkEnd();
    }
    else{
        //add translate
        edk::GU::guTranslate3f32(this->position);edkEnd();
        //add rotation
        edk::GU::guRotateXf32(this->angle.x);edkEnd();
        edk::GU::guRotateYf32(this->angle.y);edkEnd();
        edk::GU::guRotateZf32(this->angle.z);edkEnd();
        //add scale
        edk::GU::guScale3f32(this->size);edkEnd();
    }
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->meshes.drawNormalsWithColor(color);edkEnd();

    this->drawChildremsNormalsWithColor(color);
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawNormalsWithColor(edk::float32 r,edk::float32 g,edk::float32 b){
    this->drawNormalsWithColor(edk::color3f32(r,g,b));edkEnd();
}
//draw the mesh with projection matrix
void edk::Object3D::drawWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix){
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
void edk::Object3D::drawWithMatrixWithoutMaterial(edk::vector::Matrix<edk::float32,4u,4u>* matrix){
    if(matrix){
        this->calculateMatrices();edkEnd();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);edkEnd();

        edk::uint32 size = this->meshes.size();edkEnd();
        edk::Object3D::MeshAlloc* value;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            value = this->meshes.get(i);edkEnd();
            value->getMesh()->drawPolygonsWithMatrix(&this->matrixTransform,&this->matrixTemp);edkEnd();
        }
    }
}
void edk::Object3D::drawWithMatrixWithoutMaterialWithLight(edk::vector::Matrix<edk::float32,4u,4u>* matrix){
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
                value->getMesh()->drawPolygonsWithMatrix(&this->matrixTransform,&this->matrixTemp);edkEnd();
            }
            edk::GU::guDisable(GU_LIGHTING);edkEnd();
        }
        else{
            edk::uint32 size = this->meshes.size();edkEnd();
            edk::Object3D::MeshAlloc* value;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                value = this->meshes.get(i);edkEnd();
                value->getMesh()->drawPolygonsWithMatrix(&this->matrixTransform,&this->matrixTemp);edkEnd();
            }
        }
    }
}
void edk::Object3D::drawWireWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix){
    if(matrix){
        this->calculateMatrices();edkEnd();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);edkEnd();

        edk::uint32 size = this->meshes.size();edkEnd();
        edk::Object3D::MeshAlloc* value;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            value = this->meshes.get(i);edkEnd();
            value->getMesh()->drawWirePolygonsWithMatrix(&this->matrixTransform,&this->matrixTemp);edkEnd();
        }
    }
}
void edk::Object3D::drawNormalsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix){
    if(matrix){
        this->calculateMatrices();edkEnd();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);edkEnd();

        edk::uint32 size = this->meshes.size();edkEnd();
        edk::Object3D::MeshAlloc* value;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            value = this->meshes.get(i);edkEnd();
            value->getMesh()->drawWirePolygonsWithMatrix(&this->matrixTransform,&this->matrixTemp);edkEnd();
        }
    }
}
void edk::Object3D::drawNormalsWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::color3f32 color){
    if(matrix){
        this->calculateMatrices();edkEnd();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);edkEnd();

        edk::uint32 size = this->meshes.size();edkEnd();
        edk::Object3D::MeshAlloc* value;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            value = this->meshes.get(i);edkEnd();
            value->getMesh()->drawWirePolygonsWithMatrixWithColor(&this->matrixTransform,&this->matrixTemp,edk::color4f32(color.r,color.g,color.b,1.f));edkEnd();
        }
    }
}
void edk::Object3D::drawNormalsWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::float32 r,edk::float32 g,edk::float32 b){
    if(matrix){
        this->calculateMatrices();edkEnd();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);edkEnd();

        edk::uint32 size = this->meshes.size();edkEnd();
        edk::Object3D::MeshAlloc* value;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            value = this->meshes.get(i);edkEnd();
            value->getMesh()->drawWirePolygonsWithMatrixWithColor(&this->matrixTransform,&this->matrixTemp,edk::color4f32(r,g,b,1.f));edkEnd();
        }
    }
}
//draw the pivo
void edk::Object3D::drawPivo(edk::float32 size,edk::color3f32 color){
    //
    edk::GU::guPushMatrix();edkEnd();

    if(father){
        //add translate
        edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
    }
    else{
        //add translate
        edk::GU::guTranslate3f32(this->position);edkEnd();
    }
    //add scale
    edk::GU::guScale3f32(edk::size3f32(size,size,size));edkEnd();

    //lineSize
    edk::GU::guLineWidth(3);edkEnd();

    //set the colors
    edk::GU::guColor3f32(color);edkEnd();
    //draw the lines
    edk::GU::guBegin(GU_LINES);edkEnd();
    //LINE 1
    edk::GU::guVertex3f32(-0.5f,-0.5f,0.f);edkEnd();
    edk::GU::guVertex3f32( 0.5f, 0.5f,0.f);edkEnd();
    //LINE 2
    edk::GU::guVertex3f32(-0.5f, 0.5f,0.f);edkEnd();
    edk::GU::guVertex3f32( 0.5f,-0.5f,0.f);edkEnd();
    //LINE 3
    edk::GU::guVertex3f32(0.0f, 0.5f,-0.5f);edkEnd();
    edk::GU::guVertex3f32(0.0f,-0.5f, 0.5f);edkEnd();
    //LINE 4
    edk::GU::guVertex3f32(0.0f, 0.5f, 0.5f);edkEnd();
    edk::GU::guVertex3f32(0.0f,-0.5f,-0.5f);edkEnd();
    edk::GU::guEnd();edkEnd();

    //lineSize
    edk::GU::guLineWidth(1);edkEnd();

    //
    edk::GU::guPopMatrix();edkEnd();

    if(this->childrems.size()){
        //put the transformation on a stack
        edk::GU::guPushMatrix();edkEnd();
        if(this->father){
            //add translate
            edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
            //add rotation
            edk::GU::guRotateXf32(this->connectedAngle.x);edkEnd();
            edk::GU::guRotateYf32(this->connectedAngle.y);edkEnd();
            edk::GU::guRotateZf32(this->connectedAngle.z);edkEnd();
            //add scale
            edk::GU::guScale3f32(this->connectedSize);edkEnd();
        }
        else{
            //add translate
            edk::GU::guTranslate3f32(this->position);edkEnd();
            //add rotation
            edk::GU::guRotateXf32(this->angle.x);edkEnd();
            edk::GU::guRotateYf32(this->angle.y);edkEnd();
            edk::GU::guRotateZf32(this->angle.z);edkEnd();
            //add scale
            edk::GU::guScale3f32(this->size);edkEnd();
        }
        //set the pivo
        edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();
        this->drawChildremsPivo(size,color);
        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::Object3D::drawPivoWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::float32 size,edk::color3f32 color){

    //
    edk::GU::guPushMatrix();edkEnd();
    this->matrixTransform.setIdentity(1.f,0.f);edkEnd();
    if(this->father){
        edk::Math::generateTranslateMatrix(this->connectedPosition,&this->matrixTranslate);edkEnd();
    }
    else{
        edk::Math::generateTranslateMatrix(this->position,&this->matrixTranslate);edkEnd();
    }
    edk::Math::generateScaleMatrix3D(size,size,size,&this->matrixScale);edkEnd();
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixTranslate);edkEnd();
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixScale);edkEnd();
    //multiply with the matrix
    this->matrixTransform.multiplyThisWithMatrix(matrix);edkEnd();

    //lineSize
    edk::GU::guLineWidth(3);edkEnd();

    //set the colors
    edk::GU::guColor3f32(color);edkEnd();
    //draw the lines
    edk::GU::guBegin(GU_LINES);edkEnd();
    //LINE 1
    edk::GU::guVertex3f32(-0.5f,-0.5f,0.f);edkEnd();
    edk::GU::guVertex3f32( 0.5f, 0.5f,0.f);edkEnd();
    //LINE 2
    edk::GU::guVertex3f32(-0.5f, 0.5f,0.f);edkEnd();
    edk::GU::guVertex3f32( 0.5f,-0.5f,0.f);edkEnd();
    //LINE 3
    edk::GU::guVertex3f32(0.0f, 0.5f,-0.5f);edkEnd();
    edk::GU::guVertex3f32(0.0f,-0.5f, 0.5f);edkEnd();
    //LINE 4
    edk::GU::guVertex3f32(0.0f, 0.5f, 0.5f);edkEnd();
    edk::GU::guVertex3f32(0.0f,-0.5f,-0.5f);edkEnd();
    edk::GU::guEnd();edkEnd();

    //lineSize
    edk::GU::guLineWidth(1);edkEnd();

    //
    edk::GU::guPopMatrix();edkEnd();

    if(this->childrems.size()){
        //put the transformation on a stack
        edk::GU::guPushMatrix();edkEnd();
        if(this->father){
            //add translate
            edk::GU::guTranslate3f32(this->connectedPosition);edkEnd();
            //add rotation
            edk::GU::guRotateXf32(this->connectedAngle.x);edkEnd();
            edk::GU::guRotateYf32(this->connectedAngle.y);edkEnd();
            edk::GU::guRotateZf32(this->connectedAngle.z);edkEnd();
            //add scale
            edk::GU::guScale3f32(this->connectedSize);edkEnd();
        }
        else{
            //add translate
            edk::GU::guTranslate3f32(this->position);edkEnd();
            //add rotation
            edk::GU::guRotateXf32(this->angle.x);edkEnd();
            edk::GU::guRotateYf32(this->angle.y);edkEnd();
            edk::GU::guRotateZf32(this->angle.z);edkEnd();
            //add scale
            edk::GU::guScale3f32(this->size);edkEnd();
        }
        //set the pivo
        edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();
        this->drawChildremsPivoWithMatrix(matrix,size,color);
        edk::GU::guPopMatrix();edkEnd();
    }
}

//connect another object into this
bool edk::Object3D::connectObject(edk::Object3D* obj){
    if(obj){
        if(!obj->father){
            if(this->childrems.add(obj)){
                obj->father=this;

                //translate the object to be connected with the another
                obj->connectedPosition-=this->position;
                obj->connectedSize/=this->size;
                obj->connectedAngle-=this->angle;

                return true;
            }
        }
    }
    return false;
}
bool edk::Object3D::disconnectObject(edk::Object3D* obj){
    if(obj){
        if(obj->father == this){
            if(this->childrems.remove(obj)){
                this->father=NULL;
                obj->connectedLoadIdentityValues();
                return true;
            }
        }
    }
    return false;
}
bool edk::Object3D::cleanConnectedObjects(){
    edk::uint32 size = this->childrems.size();
    edk::Object3D* obj;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->childrems.getElementInPosition(i);
        if(obj){
            if(obj->father == this){
                obj->father=NULL;
                obj->connectedLoadIdentityValues();
            }
        }
    }
    this->childrems.clean();
}
