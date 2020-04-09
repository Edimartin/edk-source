#include "Object3D.h"

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
void edk::Object3D::setPolygonsColor(edk::color4f32 color){
    //
}
void edk::Object3D::setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){

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

    edk::GU::guEnable(GU_LIGHTING);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.z);
    edk::GU::guRotateYf32(this->angle.y);
    edk::GU::guRotateXf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    bool haveLight=false;

    {
        //edk::vec3f32 temp;
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);
                this->lights[i].draw(i);
                this->lightIsOn[i] = true;

                //translate pivo
                this->lightPositions[i][0u] = this->lights[i].getPositionX() + this->pivo.x;
                this->lightPositions[i][1u] = this->lights[i].getPositionY() + this->pivo.y;
                this->lightPositions[i][2u] = this->lights[i].getPositionZ() + this->pivo.z;
                this->lightPositions[i][3u] = 1.f;

                this->lightDirections[i][0u] = this->lights[i].getDirectionX() + this->pivo.x;
                this->lightDirections[i][1u] = this->lights[i].getDirectionY() + this->pivo.y;
                this->lightDirections[i][2u] = this->lights[i].getDirectionZ() + this->pivo.z;
                this->lightDirections[i][3u] = 1.f;

                //translate
                this->lightPositions[i][0u] -= this->position.x;
                this->lightPositions[i][1u] -= this->position.y;
                this->lightPositions[i][2u] -= this->position.z;

                this->lightDirections[i][0u] -= this->position.x;
                this->lightDirections[i][1u] -= this->position.y;
                this->lightDirections[i][2u] -= this->position.z;

                //scale
                this->lightPositions[i][0u] *= (1.f/this->size.width);
                this->lightPositions[i][1u] *= (1.f/this->size.height);
                this->lightPositions[i][2u] *= (1.f/this->size.length);

                this->lightDirections[i][0u] *= (1.f/this->size.width);
                this->lightDirections[i][1u] *= (1.f/this->size.height);
                this->lightDirections[i][2u] *= (1.f/this->size.length);
/*
                //rotate
                temp = edk::Math::rotatePlus2f(edk::vec2f32(this->lightPositions[i][0u],this->lightPositions[i][1u])
                        ,this->angle*-1.f
                        );
                this->lightPositions[i][0u] = temp.x;
                this->lightPositions[i][1u] = temp.y;
                this->lightPositions[i][2u] = temp.z;

                temp = edk::Math::rotatePlus2f(edk::vec2f32(this->lightDirections[i][0u],this->lightDirections[i][1u])
                        ,this->angle*-1.f
                        );
                this->lightDirections[i][0u] = temp.x;
                this->lightDirections[i][1u] = temp.y;
                this->lightDirections[i][2u] = temp.z;
*/

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

    if(haveLight){
        //
        this->meshes.drawWithLight(&this->lightPositions,&this->lightDirections,&this->lightIsOn);
    }
    else{
        this->meshes.render();
    }
    edk::GU::guDisable(GU_LIGHTING);
    edk::GU::guPopMatrix();
}
void edk::Object3D::drawWithoutMaterial(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.z);
    edk::GU::guRotateYf32(this->angle.y);
    edk::GU::guRotateXf32(this->angle.x);
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

    edk::GU::guEnable(GU_LIGHTING);

    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.z);
    edk::GU::guRotateYf32(this->angle.y);
    edk::GU::guRotateXf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    bool haveLight=false;

    {
        //edk::vec3f32 temp;
        for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
            if(this->lights[i].on){
                edk::GU::guEnable(GU_LIGHT0+i);
                this->lights[i].draw(i);
                this->lightIsOn[i] = true;

                //translate pivo
                this->lightPositions[i][0u] = this->lights[i].getPositionX() + this->pivo.x;
                this->lightPositions[i][1u] = this->lights[i].getPositionY() + this->pivo.y;
                this->lightPositions[i][2u] = this->lights[i].getPositionZ() + this->pivo.z;
                this->lightPositions[i][3u] = 1.f;

                this->lightDirections[i][0u] = this->lights[i].getDirectionX() + this->pivo.x;
                this->lightDirections[i][1u] = this->lights[i].getDirectionY() + this->pivo.y;
                this->lightDirections[i][2u] = this->lights[i].getDirectionZ() + this->pivo.z;
                this->lightDirections[i][3u] = 1.f;

                //translate
                this->lightPositions[i][0u] -= this->position.x;
                this->lightPositions[i][1u] -= this->position.y;
                this->lightPositions[i][2u] -= this->position.z;

                this->lightDirections[i][0u] -= this->position.x;
                this->lightDirections[i][1u] -= this->position.y;
                this->lightDirections[i][2u] -= this->position.z;

                //scale
                this->lightPositions[i][0u] *= (1.f/this->size.width);
                this->lightPositions[i][1u] *= (1.f/this->size.height);
                this->lightPositions[i][2u] *= (1.f/this->size.length);

                this->lightDirections[i][0u] *= (1.f/this->size.width);
                this->lightDirections[i][1u] *= (1.f/this->size.height);
                this->lightDirections[i][2u] *= (1.f/this->size.length);
/*
                //rotate
                temp = edk::Math::rotatePlus2f(edk::vec2f32(this->lightPositions[i][0u],this->lightPositions[i][1u])
                        ,this->angle*-1.f
                        );
                this->lightPositions[i][0u] = temp.x;
                this->lightPositions[i][1u] = temp.y;
                this->lightPositions[i][2u] = temp.z;

                temp = edk::Math::rotatePlus2f(edk::vec2f32(this->lightDirections[i][0u],this->lightDirections[i][1u])
                        ,this->angle*-1.f
                        );
                this->lightDirections[i][0u] = temp.x;
                this->lightDirections[i][1u] = temp.y;
                this->lightDirections[i][2u] = temp.z;
*/

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

    if(haveLight){
        this->meshes.drawWithoutMaterialWithLight(&this->lightPositions,&this->lightDirections,&this->lightIsOn);
    }
    else{
        this->meshes.drawWithoutMaterial();
    }

    edk::GU::guDisable(GU_LIGHTING);

    edk::GU::guPopMatrix();
}
void edk::Object3D::drawWire(){
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle.z);
    edk::GU::guRotateYf32(this->angle.y);
    edk::GU::guRotateXf32(this->angle.x);
    //add scale
    edk::GU::guScale3f32(this->size);
    //set the pivo
    edk::GU::guTranslate3f32(this->pivo*-1.0f);

    this->meshes.drawWire();

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
