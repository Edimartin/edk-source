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
    this->loadIdentityValues();
}
edk::Object3D::~Object3D(){
    //
}

//create a new mesh and add to the meshs stack
edk::shape::Mesh3D* edk::Object3D::newMesh(edk::uint32* position){
    return this->meshes.pushNewMesh(position);
}
//Add a list to the Object2D
edk::uint32 edk::Object3D::addMesh(edk::shape::Mesh3D* mesh){
    //test if the list exist
    if(mesh){
        edk::uint32 ret = 0u;
        //then add the mesh to the list
        ret = this->meshes.pushBackMesh(mesh,false);
        if(ret<this->meshes.size()){
            //test if select the first
            if(this->meshes.size()==1u) this->selectMesh(0u);
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
bool edk::Object3D::setPolygonsColor(edk::color4f32 color){
    edk::uint32 size = this->meshes.size();
    edk::shape::Mesh3D* temp;
    if(size){
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->meshes.getMesh(i);
            if(temp){
                temp->setPolygonsColor(color);
            }
        }
        return true;
    }
    return false;
}
bool edk::Object3D::setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setPolygonsColor(edk::color4f32(r,g,b,a));
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

//LIGHT
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
bool edk::Object3D::addObj(const edk::char8* fileName){
    return this->addObj((edk::char8*) fileName);
}
bool edk::Object3D::addObj(edk::char8* fileName){
    if(fileName){
        //open the file
        edk::File file;
        if(file.openTextFile(fileName)){
            bool ret = true;
            edk::char8 c;
            edk::char8* str;
            edk::char8* temp;
            edk::char8* ve;
            edk::uint8 read;
            edk::uint32 v,n,p;
            edk::uint32 countV=0u;
            edk::uint32 countP=0u;
            edk::uint32 countN=0u;
            edk::float32 x,y,z;

            edk::vector::Stack<edk::uint32> sv,sp,sn;

            edk::shape::Mesh3D* mesh = NULL;
            bool smooth = true;

            while(!file.endOfFile()){
                c = file.readTextChar();
                switch(c){
                case '#':
                    //comentario
                    str = file.readTextString("\n",false);
                    if(str){
                        delete[] str;
                    }
                    //printf("\nComentario");fflush(stdout);
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
                                            str = file.readTextString("\n",false);
                                            if(str){
                                                //printf("\nMTL LIB == '%s'",str);fflush(stdout);
                                                delete[] str;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    break;
                case 'o':
                    if(file.readTextChar() == ' '){
                        str = file.readTextString("\n",false);
                        if(str){
                            //printf("\nNEW OBJECT NAME == '%s'",str);fflush(stdout);
                            delete[] str;

                            if(mesh){
                                countV += mesh->getVertexSize();
                                countP += mesh->getUVSize();
                                countN += mesh->getNormalSize();
                            }
                            //new mesh
                            mesh = this->newMesh();
                        }
                    }
                    break;
                case 'v':
                    if(!mesh){
                        mesh=this->newMesh();
                    }
                    c = file.readTextChar();
                    if(c == ' '){
                        str = file.readTextString(" ",false);
                        if(str){
                            x = edk::String::strToFloat32(str);
                            delete[] str;
                        }
                        str = file.readTextString(" ",false);
                        if(str){
                            y = edk::String::strToFloat32(str);
                            delete[] str;
                        }
                        str = file.readTextString("\n",false);
                        if(str){
                            z = edk::String::strToFloat32(str);
                            delete[] str;
                        }
                        //printf("\nNEW Vertex %.2f %.2f %.2f",x,y,z);fflush(stdout);
                        mesh->newVertex(x,y,z,1,1,1,1);
                        //mesh->newVertex(x,y,z,0,0,0,1);
                    }
                    else if(c == 't'){
                        if(file.readTextChar() == ' '){
                            //
                            str = file.readTextString(" ",false);
                            if(str){
                                x = edk::String::strToFloat32(str);
                                delete[] str;
                            }
                            str = file.readTextString("\n",false);
                            if(str){
                                y = edk::String::strToFloat32(str);
                                delete[] str;
                            }
                            //printf("\nNEW Vertex Texture %.2f %.2f",x,y);fflush(stdout);
                            mesh->newUV(x,y);
                        }
                    }
                    else if(c == 'n'){
                        if(file.readTextChar() == ' '){
                            //
                            str = file.readTextString(" ",false);
                            if(str){
                                x = edk::String::strToFloat32(str);
                                delete[] str;
                            }
                            str = file.readTextString(" ",false);
                            if(str){
                                y = edk::String::strToFloat32(str);
                                delete[] str;
                            }
                            str = file.readTextString("\n",false);
                            if(str){
                                z = edk::String::strToFloat32(str);
                                delete[] str;
                            }
                            //printf("\nNEW Vertex Normal %.2f %.2f %.2f",x,y,z);fflush(stdout);
                            mesh->newNormal(x,y,z);
                        }
                    }
                    break;
                case 's':
                    if(!mesh){
                        mesh=this->newMesh();
                    }
                    if(file.readTextChar() == ' '){
                        str = file.readTextString("\n",false);
                        if(str){
                            if(str[0u]=='o'){
                                if(str[1u]=='f'){
                                    if(str[2u]=='f'){
                                        //
                                        //printf("\nSMOOTH FALSE '%s'",str);fflush(stdout);
                                        smooth=false;
                                    }
                                }
                            }
                            else{
                                if(str[0u]=='1'){
                                    //
                                    //printf("\nSMOOTH TRUE '%s'",str);fflush(stdout);
                                    smooth=true;
                                }
                            }
                            delete[] str;
                        }
                    }
                    else{
                        str = file.readTextString("\n",false);
                        if(str){
                            delete[] str;
                        }
                    }
                    break;
                case 'f':
                    if(!mesh){
                        mesh=this->newMesh();
                    }
                    if(file.readTextChar() == ' '){
                        //
                        str = file.readTextString("\n",true);
                        if(str){
                            ve = temp = str;
                            read = 0u;
                            //printf("\n");



                            while(*temp){
                                switch(*temp){
                                case '/':
                                    //set the end of the string
                                    *temp = '\0';
                                    if(ve<temp){
                                        switch(read){
                                        case 0u:
                                            v = edk::String::strToInt64(ve);
                                            break;
                                        case 1u:
                                            p = edk::String::strToInt64(ve);
                                            break;
                                        case 2u:
                                            n = edk::String::strToInt64(ve);
                                            break;
                                        }
                                    }
                                    *temp = '/';
                                    //
                                    switch(read){
                                    case 0u:
                                        read = 1u;
                                        break;
                                    case 1u:
                                        read = 2u;
                                        break;
                                    case 2u:
                                        read = 3u;
                                        break;
                                    }


                                    ve = temp+1u;
                                    break;
                                case ' ':
                                case '\n':
                                    *temp = '\0';
                                    if(ve<temp){
                                        switch(read){
                                        case 0u:
                                            v = edk::String::strToInt64(ve);
                                            read = 1u;
                                            break;
                                        case 1u:
                                            p = edk::String::strToInt64(ve);
                                            read = 2u;
                                            break;
                                        case 2u:
                                            n = edk::String::strToInt64(ve);
                                            read = 3u;
                                            break;
                                        }


                                        switch(read){
                                        case 1u:
                                            /*
                                            printf(" Face %u"
                                                   ,v
                                                   );fflush(stdout);
                                                   */
                                            sv.pushBack(v);
                                            sp.pushBack(0u);
                                            sn.pushBack(0u);
                                            break;
                                        case 2u:
                                            /*
                                            printf(" Face %u/%u"
                                                   ,v
                                                   ,p
                                                   );fflush(stdout);
                                            */
                                            sv.pushBack(v);
                                            sp.pushBack(p);
                                            sn.pushBack(0u);
                                            break;
                                        case 3u:
                                            /*
                                            printf(" Face %u/%u/%u"
                                                   ,v
                                                   ,p
                                                   ,n
                                                   );fflush(stdout);
                                            */
                                            sv.pushBack(v);
                                            sp.pushBack(p);
                                            sn.pushBack(n);
                                            break;
                                        }
                                        v=p=n=0u;
                                        read=0u;
                                    }
                                    *temp = ' ';

                                    ve = temp+1u;
                                    break;
                                default:
                                    break;
                                }

                                temp++;
                            }

                            edk::uint32 size = sv.size();
                            if(size){
                                //printf(" NEW FACE");fflush(stdout);
                                edk::uint32 po = mesh->newPolygon(size);
                                mesh->selectPolygon(po);
                                mesh->selectedPolygonSetSmooth(smooth);
                                if(smooth){
                                    mesh->selectedPolygonUpdateNormal();
                                }
                                else{
                                    mesh->selectedPolygonSetNormalFlat(mesh->getNormal(sn[0u]-1u-countN));
                                }
                                for(edk::uint32 i=0u;i<size;i++){
                                    v = sv[i];
                                    p = sp[i];
                                    n = sn[i];
                                    if(v){
                                        mesh->selectedPolygonSetVertex(i,v-1u-countV);
                                        if(p){
                                            mesh->selectedPolygonSetUV(i,p-1u-countP);
                                            if(n){
                                                //
                                                mesh->selectedPolygonSetNormal(i,n-1u-countN);
                                            }
                                        }
                                        else{
                                            if(n){
                                                //
                                                mesh->selectedPolygonSetNormal(i,n-1u-countN);
                                            }
                                        }
                                    }
                                }
                            }

                            sv.clean();
                            sp.clean();
                            sn.clean();

                            delete[] str;
                        }
                    }
                    else{
                        str = file.readTextString("\n",false);
                        if(str){
                            delete[] str;
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
                                            str = file.readTextString("\n",false);
                                            if(str){
                                                //printf("\nUSE MTL == '%s'",str);fflush(stdout);
                                                delete[] str;
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

            file.closeFile();
            return ret;
        }
    }
    return false;
}
bool edk::Object3D::loadOBJ(const edk::char8* fileName){
    return this->loadOBJ((edk::char8*) fileName);
}
bool edk::Object3D::loadOBJ(edk::char8* fileName){
    this->cleanMeshes();
    return this->addObj(fileName);
}

//DRAW
//print the mesh
void edk::Object3D::print(){
    //
}
//draw the mesh
void edk::Object3D::draw(){

    //put the transformation on a stack
    edk::GU::guPushMatrix();

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

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateXf32(this->angle.x);
    edk::GU::guRotateYf32(this->angle.y);
    edk::GU::guRotateZf32(this->angle.z);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);


    if(haveLight){
        //
        edk::GU::guEnable(GU_LIGHTING);
        this->meshes.render();
        edk::GU::guDisable(GU_LIGHTING);
    }
    else{
        this->meshes.render();
    }
    edk::GU::guPopMatrix();
}
void edk::Object3D::drawWithoutMaterial(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateXf32(this->angle.x);
    edk::GU::guRotateYf32(this->angle.y);
    edk::GU::guRotateZf32(this->angle.z);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->meshes.drawWithoutMaterial();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawWithoutMaterialWithLight(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();


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

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateXf32(this->angle.x);
    edk::GU::guRotateYf32(this->angle.y);
    edk::GU::guRotateZf32(this->angle.z);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    if(haveLight){
        edk::GU::guEnable(GU_LIGHTING);
        this->meshes.drawWithoutMaterial();
        edk::GU::guDisable(GU_LIGHTING);
    }
    else{
        this->meshes.drawWithoutMaterial();
    }

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawWire(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateXf32(this->angle.x);
    edk::GU::guRotateYf32(this->angle.y);
    edk::GU::guRotateZf32(this->angle.z);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->meshes.drawWire();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawNormals(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateXf32(this->angle.x);
    edk::GU::guRotateYf32(this->angle.y);
    edk::GU::guRotateZf32(this->angle.z);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->meshes.drawNormals();

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawNormalsWithColor(edk::color3f32 color){
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateXf32(this->angle.x);
    edk::GU::guRotateYf32(this->angle.y);
    edk::GU::guRotateZf32(this->angle.z);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->meshes.drawNormalsWithColor(color);

    edk::GU::guPopMatrix();
}
//draw the pivo
void edk::Object3D::drawPivo(edk::float32 size,edk::color3f32 color){
    //
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
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
