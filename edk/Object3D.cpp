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
            bool smooth = false;edkEnd();

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
                                                //printf("\nMTL LIB == '%s'",str);edkEnd();
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
                            }
                            //new mesh
                            mesh = this->newMesh();edkEnd();
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

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateXf32(this->angle.x);edkEnd();
    edk::GU::guRotateYf32(this->angle.y);edkEnd();
    edk::GU::guRotateZf32(this->angle.z);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
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
    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawWithoutMaterial(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateXf32(this->angle.x);edkEnd();
    edk::GU::guRotateYf32(this->angle.y);edkEnd();
    edk::GU::guRotateZf32(this->angle.z);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->meshes.drawWithoutMaterial();edkEnd();

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

    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateXf32(this->angle.x);edkEnd();
    edk::GU::guRotateYf32(this->angle.y);edkEnd();
    edk::GU::guRotateZf32(this->angle.z);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
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

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawWire(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateXf32(this->angle.x);edkEnd();
    edk::GU::guRotateYf32(this->angle.y);edkEnd();
    edk::GU::guRotateZf32(this->angle.z);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->meshes.drawWire();edkEnd();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawNormals(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateXf32(this->angle.x);edkEnd();
    edk::GU::guRotateYf32(this->angle.y);edkEnd();
    edk::GU::guRotateZf32(this->angle.z);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->meshes.drawNormals();edkEnd();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::Object3D::drawNormalsWithColor(edk::color3f32 color){
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateXf32(this->angle.x);edkEnd();
    edk::GU::guRotateYf32(this->angle.y);edkEnd();
    edk::GU::guRotateZf32(this->angle.z);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);edkEnd();

    this->meshes.drawNormalsWithColor(color);edkEnd();

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
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
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
}
void edk::Object3D::drawPivoWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::float32 size,edk::color3f32 color){

    //
    edk::GU::guPushMatrix();edkEnd();
    this->matrixTransform.setIdentity(1.f,0.f);edkEnd();
    edk::Math::generateTranslateMatrix(this->position,&this->matrixTranslate);edkEnd();
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
}
