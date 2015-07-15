#include "Object2D.h"

/*
Library Object2D - Object in the 2D world.
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#ifdef printMessages
#warning "            Inside Object2D.cpp"
#endif

edk::Object2D::Object2D(){
    //
    this->selected=NULL;
    //rotation
    this->angle=0.0f;
    //Scale
    this->size = edk::size2f32(1.f,1.f);
    this->canDeleteObject=true;
}

edk::Object2D::~Object2D(){
    //dtor
    if(this->canDeleteObject){
        this->cleanMeshes();
    }
    else{
        this->meshes.cantDestroy();
        this->animationPosition.cantDeleteGroup();
        this->animationRotation.cantDeleteGroup();
        this->animationSize.cantDeleteGroup();
    }
    this->canDeleteObject=true;
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
            if(this->meshes.size()==1u) this->selectMesh(0u);
            return ret;
        }
    }

    //else return falses
    return 0u;
}
//create a new mesh and add to the meshs stack
edk::shape::Mesh2D* edk::Object2D::newMesh(edk::uint32* position){
    return this->meshes.pushNewMesh(position);
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
    return false;
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
    //
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
bool edk::Object2D::updateMeshAnimations(edk::uchar32 position){
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

//update all animations
bool edk::Object2D::updateAnimations(){
    bool ret=false;
    bool success;
    //test if are playing the animations
    if(this->animationPosition.isPlaying()){
        //
        this->animationPosition.updateClockAnimation();
        edk::vec2f32 posTemp;
        posTemp.x = this->animationPosition.getClockX(&success);
        if(success){
            posTemp.y = this->animationPosition.getClockY(&success);
            if(success){
                //set the value
                this->position = posTemp;
                ret=true;
            }
        }
    }
    if(this->animationRotation.isPlaying()){
        //
        this->animationRotation.updateClockAnimation();
        edk::float32 angleTemp = this->animationRotation.getClockX(&success);
        if(success){
            //set the value
            this->angle = angleTemp;
            ret=true;
        }
    }
    if(this->animationSize.isPlaying()){
        //
        this->animationSize.updateClockAnimation();
        edk::size2f32 sizeTemp;
        sizeTemp.width = this->animationSize.getClockX(&success);
        if(success){
            sizeTemp.height = this->animationSize.getClockY(&success);
            if(success){
                //set the value
                this->size = sizeTemp;
                ret=true;
            }
        }
    }
    this->updateMeshAnimations();
    return ret;
}

//DRAW
//print the mesh
void edk::Object2D::print(){
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
                   );
            mesh->print();
        }
    }
}
//draw the mesh
void edk::Object2D::draw(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    /*
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_POSITION,this->position);
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_SPOT_DIRECTION,this->direction);


    edk::light::Light lights[EDK_LIGHT_LIMIT];
    edk::vec2f32 lightPositions[EDK_LIGHT_LIMIT];
    edk::vec2f32 lightDirections[EDK_LIGHT_LIMIT];
    */

    edk::GU::guEnable(GU_LIGHTING);
    //glEnable(GL_RESCALE_NORMAL);

    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);
    //set the pivo
    edk::GU::guTranslate2f32(this->pivo*-1.0f);

    bool haveLight=false;

    {
        edk::vec2f32 temp;
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);
                this->lights[i].draw(i);
                this->lightIsOn[i] = true;

                //translate pivo
                this->lightPositions[i][0u] = this->lights[i].getPositionX() + this->pivo.x;
                this->lightPositions[i][1u] = this->lights[i].getPositionY() + this->pivo.y;
                this->lightPositions[i][2u] = this->lights[i].getPositionZ();
                this->lightPositions[i][3u] = 1.f;

                this->lightDirections[i][0u] = this->lights[i].getDirectionX() + this->pivo.x;
                this->lightDirections[i][1u] = this->lights[i].getDirectionY() + this->pivo.y;
                this->lightDirections[i][2u] = this->lights[i].getDirectionZ();
                this->lightDirections[i][3u] = 1.f;

                //translate
                this->lightPositions[i][0u] -= this->position.x;
                this->lightPositions[i][1u] -= this->position.y;

                this->lightDirections[i][0u] -= this->position.x;
                this->lightDirections[i][1u] -= this->position.y;

                //scale
                this->lightPositions[i][0u] *= (1.f/this->size.width);
                this->lightPositions[i][1u] *= (1.f/this->size.height);

                this->lightDirections[i][0u] *= (1.f/this->size.width);
                this->lightDirections[i][1u] *= (1.f/this->size.height);

                //rotate
                temp = edk::Math::rotatePlus2f(edk::vec2f32(this->lightPositions[i][0u],this->lightPositions[i][1u])
                        ,this->angle*-1.f
                        );
                this->lightPositions[i][0u] = temp.x;
                this->lightPositions[i][1u] = temp.y;

                temp = edk::Math::rotatePlus2f(edk::vec2f32(this->lightDirections[i][0u],this->lightDirections[i][1u])
                        ,this->angle*-1.f
                        );
                this->lightDirections[i][0u] = temp.x;
                this->lightDirections[i][1u] = temp.y;


                edk::GU::guLightfv32(GU_LIGHT0+i,GU_POSITION,this->lightPositions[i]);
                edk::GU::guLightfv32(GU_LIGHT0+i,GU_SPOT_DIRECTION,this->lightDirections[i]);

                haveLight=true;

            }
            else{
                this->lightIsOn[i] = false;
                edk::GU::guDisable(GU_LIGHT0+i);
            }
        }
    }

    edk::shape::Mesh2D* mesh;
    if(haveLight){
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);
            if(mesh){
                if(mesh->material.haveOneTexture()){
                    mesh->drawOneTextureWithLight(&this->lightPositions,&this->lightDirections,&this->lightIsOn);
                }
                else{
                    mesh->drawMultiTextureWithLight(&this->lightPositions,&this->lightDirections,&this->lightIsOn);
                }
            }
        }
    }
    else{
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);
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
    //glEnable(GL_RESCALE_NORMAL);
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

    edk::shape::Mesh2D* mesh;
    //print all polygonList
    for(edk::uint32 i=this->meshes.size();i>0u;i--){
        //
        mesh = this->meshes.getMesh(i-1u);
        if(mesh){
            mesh->drawOneTexture();
        }
    }
    edk::GU::guPopMatrix();
}
void edk::Object2D::drawWithoutMaterialWithLight(){
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

    bool haveLight=false;

    {
        edk::vec2f32 temp;
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);
                this->lights[i].draw(i);
                this->lightIsOn[i] = true;

                //translate pivo
                this->lightPositions[i][0u] = this->lights[i].getPositionX() + this->pivo.x;
                this->lightPositions[i][1u] = this->lights[i].getPositionY() + this->pivo.y;
                this->lightPositions[i][2u] = this->lights[i].getPositionZ();
                this->lightPositions[i][3u] = 1.f;

                this->lightDirections[i][0u] = this->lights[i].getDirectionX() + this->pivo.x;
                this->lightDirections[i][1u] = this->lights[i].getDirectionY() + this->pivo.y;
                this->lightDirections[i][2u] = this->lights[i].getDirectionZ();
                this->lightDirections[i][3u] = 1.f;

                //translate
                this->lightPositions[i][0u] -= this->position.x;
                this->lightPositions[i][1u] -= this->position.y;

                this->lightDirections[i][0u] -= this->position.x;
                this->lightDirections[i][1u] -= this->position.y;

                //scale
                this->lightPositions[i][0u] *= (1.f/this->size.width);
                this->lightPositions[i][1u] *= (1.f/this->size.height);

                this->lightDirections[i][0u] *= (1.f/this->size.width);
                this->lightDirections[i][1u] *= (1.f/this->size.height);

                //rotate
                temp = edk::Math::rotatePlus2f(edk::vec2f32(this->lightPositions[i][0u],this->lightPositions[i][1u])
                        ,this->angle*-1.f
                        );
                this->lightPositions[i][0u] = temp.x;
                this->lightPositions[i][1u] = temp.y;

                temp = edk::Math::rotatePlus2f(edk::vec2f32(this->lightDirections[i][0u],this->lightDirections[i][1u])
                        ,this->angle*-1.f
                        );
                this->lightDirections[i][0u] = temp.x;
                this->lightDirections[i][1u] = temp.y;


                edk::GU::guLightfv32(GU_LIGHT0+i,GU_POSITION,this->lightPositions[i]);
                edk::GU::guLightfv32(GU_LIGHT0+i,GU_SPOT_DIRECTION,this->lightDirections[i]);

                haveLight=true;

            }
            else{
                this->lightIsOn[i] = false;
                edk::GU::guDisable(GU_LIGHT0+i);
            }
        }
    }

    edk::shape::Mesh2D* mesh;
    if(haveLight){
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);
            if(mesh){
                mesh->drawOneTextureWithLight(&this->lightPositions,&this->lightDirections,&this->lightIsOn);
            }
        }
    }
    else{
        for(edk::uint32 i=this->meshes.size();i>0u;i--){
            //
            mesh = this->meshes.getMesh(i-1u);
            if(mesh){
                mesh->drawOneTexture();
            }
        }
    }
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

    edk::shape::Mesh2D* mesh;
    //print all polygonList
    for(edk::uint32 i=this->meshes.size();i>0u;i--){
        //
        mesh = this->meshes.getMesh(i-1u);
        if(mesh){
            mesh->drawWirePolygons();
        }
    }
    edk::GU::guPopMatrix();
}

//draw the pivo
void edk::Object2D::drawPivo(edk::float32 size,edk::color3f32 color){
    //
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate2f32(this->position);
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
                            delete[] temp;
                        }
                        temp = edk::String::float32ToStr(this->pivo.y);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"pivoY",temp);
                            delete[] temp;
                        }

                        //write objectValues
                        //position
                        temp = edk::String::float32ToStr(this->position.x);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"positionX",temp);
                            delete[] temp;
                        }
                        temp = edk::String::float32ToStr(this->position.y);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"positionY",temp);
                            delete[] temp;
                        }
                        //size
                        temp = edk::String::float32ToStr(this->size.width);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"sizeW",temp);
                            delete[] temp;
                        }
                        temp = edk::String::float32ToStr(this->size.height);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"sizeH",temp);
                            delete[] temp;
                        }
                        //angle
                        temp = edk::String::float32ToStr(this->angle);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"angle",temp);
                            delete[] temp;
                        }

                        //write animations
                        this->animationPosition.writeToXML(xml,0u);
                        this->animationRotation.writeToXML(xml,1u);
                        this->animationSize.writeToXML(xml,2u);

                        ret=true;
                        xml->selectFather();
                    }
                }
                delete[] name;
            }
            delete[] nameID;
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
                    ret=true;
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] nameID;
        }
        return ret;
    }
    return false;
}

//cant delete
void edk::Object2D::cantDeleteObject2D(){
    this->canDeleteObject=false;
}
