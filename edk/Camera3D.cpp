#include "Camera3D.h"

edk::Camera3D::Camera3D(){
    //
    this->start();
    this->perspective = false;
    this->firstPerson=false;
}
edk::Camera3D::Camera3D(edk::vec3f32 position,edk::vec3f32 lookAt){
    this->start();
    this->position = position;
    this->lookAt = lookAt;
    this->perspective = false;
    this->firstPerson=false;
}
edk::Camera3D::Camera3D(edk::float32 pX,edk::float32 pY,edk::float32 pZ,edk::float32 lookX,edk::float32 lookY,edk::float32 lookZ){
    this->start();
    this->position = edk::vec3f32(pX,pY,pZ);
    this->lookAt = edk::vec3f32(lookX,lookY,lookZ);
    this->perspective = false;
    this->firstPerson=false;
}
edk::Camera3D::~Camera3D(){
    //
}
void edk::Camera3D::start(){
    //
    this->position = edk::vec3f32(0.f,0.f,-1.f);
    this->lookAt = edk::vec3f32(0.f,0.f,0.f);

    this->up = edk::vec3f32(0.f,1.f,0.f);
    this->size = edk::size2f32(1.f,1.f);
    this->sizePercent = this->size.width/this->size.height;
    this->near = 0.0001f;
    this->far = 1.f;
}

//Sset witch camera type its using
void edk::Camera3D::usePerspective(){
    this->perspective=true;
}
void edk::Camera3D::useOrtho(){
    this->perspective=false;
}

//set the size
void edk::Camera3D::setSize(edk::size2f32 size){
    //
    this->size=size*0.5f;
    this->sizePercent = this->size.width/this->size.height;
}
void edk::Camera3D::setSize(edk::float32 sizeW,edk::float32 sizeH){
    //
    return this->setSize(edk::size2f32(sizeW,sizeH));
}
void edk::Camera3D::setSizeW(edk::float32 width){
    this->size.width = width*0.5f;
    this->sizePercent = this->size.width/this->size.height;
}
void edk::Camera3D::setSizeH(edk::float32 height){
    this->size.height = height*0.5f;
    this->sizePercent = this->size.width/this->size.height;
}
//return the size
edk::float32 edk::Camera3D::getWidth(){
    return this->size.width * 2.f;
}
edk::float32 edk::Camera3D::getHeight(){
    return this->size.height * 2.f;
}

//set near and far
void edk::Camera3D::setNearFar(edk::float32 near,edk::float32 far){
    if(far>near){
        this->near = near;
        this->far = far;
    }
    else{
        this->near = far;
        this->far = near;
    }
}
void edk::Camera3D::setFar(edk::float32 far){
    this->setNearFar(0.0001f,far);
}
//Get near and far
edk::float32 edk::Camera3D::getNear(){
    return this->near;
}
edk::float32 edk::Camera3D::getFar(){
    return this->far;
}

//Distance
edk::float32 edk::Camera3D::getDistance(){
    //
    return edk::Math::pythagoras3f(this->lookAt.x - this->position.x,
                                   this->lookAt.y - this->position.y,
                                   this->lookAt.y - this->position.z
                                   );
}
//set the distance
bool edk::Camera3D::setDistance(edk::float32 distance){
    if(distance>0.f){
        edk::float32 percent = distance / this->getDistance();
        //set the distance
        if(this->firstPerson){
            //
            this->lookAt.x = this->position.x + ((this->lookAt.x-this->position.x) * percent);
            this->lookAt.y = this->position.y + ((this->lookAt.y-this->position.y) * percent);
            this->lookAt.z = this->position.z + ((this->lookAt.z-this->position.z) * percent);
        }
        else{
            //
            this->position.x = this->lookAt.x + ((this->position.x-this->lookAt.x) * percent);
            this->position.y = this->lookAt.y + ((this->position.y-this->lookAt.y) * percent);
            this->position.z = this->lookAt.z + ((this->position.z-this->lookAt.z) * percent);
        }
        return true;
    }
    return false;
}
//move the distance
bool edk::Camera3D::moveDistance(edk::float32 distance){
    return this->setDistance(this->getDistance()+distance);
}

//return the angle width and height
edk::float32 edk::Camera3D::getAngleX(){
    if(this->firstPerson){
        return edk::Math::getAngle2f(this->lookAt.x-this->position.x,this->lookAt.z-this->position.z);
    }
    return edk::Math::getAngle2f(this->position.x-this->lookAt.x,this->position.z-this->lookAt.z);
}
edk::float32 edk::Camera3D::getAngleY(){
    if(this->firstPerson){
        return edk::Math::getAngle2f(edk::Math::pythagoras2f(this->lookAt.x-this->position.x,this->lookAt.z-this->position.z),this->lookAt.y-this->position.y);
    }
    return edk::Math::getAngle2f(edk::Math::pythagoras2f(this->position.x-this->lookAt.x,this->position.z-this->lookAt.z),this->position.y-this->lookAt.y);
}
//set the angles
void edk::Camera3D::setAngleX(edk::float32 angle){
    if(this->firstPerson){
        edk::float32 distance = edk::Math::pythagoras2f(this->lookAt.x - this->position.x,this->lookAt.z - this->position.z);
        this->lookAt.x = edk::Math::rotateXFloat(distance,angle) + this->position.x;
        this->lookAt.z = edk::Math::rotateYFloat(distance,angle) + this->position.z;
    }
    else{
        edk::float32 distance = edk::Math::pythagoras2f(this->position.x - this->lookAt.x,this->position.z - this->lookAt.z);
        this->position.x = edk::Math::rotateXFloat(distance,angle) + this->lookAt.x;
        this->position.z = edk::Math::rotateYFloat(distance,angle) + this->lookAt.z;
    }
}
void edk::Camera3D::setAngleY(edk::float32 angle){
    if(this->firstPerson){
        edk::float32 angleX = this->getAngleX();
        edk::float32 distanceX = edk::Math::pythagoras2f(this->lookAt.x - this->position.x,this->lookAt.z - this->position.z);
        edk::float32 distanceY = edk::Math::pythagoras2f(distanceX,this->lookAt.y - this->position.y);
        //
        distanceX = edk::Math::rotateXFloat(distanceY,angle) + this->position.x;
        this->lookAt.y = edk::Math::rotateYFloat(distanceY,angle) + this->position.z;
        //
        this->lookAt.x = edk::Math::rotateXFloat(distanceX,angleX) + this->position.x;
        this->lookAt.z = edk::Math::rotateYFloat(distanceX,angleX) + this->position.z;
    }
    else{
        edk::float32 angleX = this->getAngleX();
        edk::float32 distanceX = edk::Math::pythagoras2f(this->position.x - this->lookAt.x,this->position.z - this->lookAt.z);
        edk::float32 distanceY = edk::Math::pythagoras2f(distanceX,this->position.y - this->lookAt.y);
        //
        distanceX = edk::Math::rotateXFloat(distanceY,angle) + this->lookAt.x;
        this->position.y = edk::Math::rotateYFloat(distanceY,angle) + this->lookAt.z;
        //
        this->position.x = edk::Math::rotateXFloat(distanceX,angleX) + this->lookAt.x;
        this->position.z = edk::Math::rotateYFloat(distanceX,angleX) + this->lookAt.z;
    }
}
//move the angles
void edk::Camera3D::moveAngleX(edk::float32 angle){
    this->setAngleX(angle + this->getAngleX());
}
void edk::Camera3D::moveAngleY(edk::float32 angle){
    this->setAngleY(angle + this->getAngleY());
}

//draw the camera
void edk::Camera3D::draw(){
    //
    //test if are NOT using GUmodelview
    if(!edk::GU::guUsingMatrix(GU_PROJECTION))
        //then set to use modelView
        edk::GU::guUseMatrix(GU_PROJECTION);
    edk::GU::guLoadIdentity();
    //
    edk::Camera3D::drawAxisOnly();
}
void edk::Camera3D::drawAxisOnly(){
    if(this->perspective){
        edk::GU::guUsePerspective(this->size.height*2.f,this->sizePercent,this->near,this->far);
    }
    else{
        edk::GU::guUseOrtho(-this->size.width,
                            this->size.width,
                            -this->size.height,
                            this->size.height,
                            this->near,//nea
                            this->far//far
                            );
    }
    /*
    //update the shaking animations
    this->animAngle.updateClockAnimation();
    if(this->animAngle.isPlaying()){
        //calculate the angle of shaking
        this->up = edk::Math::rotate2f(edk::vec2f32(1,0),(((this->angle + this->animAngle.getClockX())*-1)+360.f)+90);
    }
    else{
        this->up = edk::Math::rotate2f(edk::vec2f32(1,0),((this->angle*-1)+360.f)+90);
    }
*/

    //shake position
    /*
    this->animPosition.updateClockAnimation();
    if(this->animPosition.isPlaying()){
        this->tempPosition.x = this->position.x+this->animPosition.getClockX();
        this->tempPosition.y = this->position.y+this->animPosition.getClockY();
        edk::GU::guLookAt(this->tempPosition.x,this->tempPosition.y,1.f,
                          this->tempPosition.x,this->tempPosition.y,0.f,
                          this->up.x,this->up.y,0.f
                          );
    }
    else{
        edk::GU::guLookAt(this->position.x,this->position.y,1.f,
                          this->position.x,this->position.y,0.f,
                          this->up.x,this->up.y,0.f
                          );
    }
    */
    edk::GU::guLookAt(this->position.x,this->position.y,this->position.z,
                      this->lookAt.x,this->lookAt.y,this->lookAt.z,
                      this->up.x,this->up.y,this->up.z
                      );
}
void edk::Camera3D::drawAxisOnly(edk::float32 seconds){
    //
}

//operator to copy the cameras
bool edk::Camera3D::cloneFrom(edk::Camera3D* cam){
    if(cam){
        this->position = cam->position;
        this->lookAt = cam->lookAt;
        this->perspective = cam->perspective;
        this->up = cam->up;
        this->size = cam->size;
        this->sizePercent = cam->sizePercent;
        this->near = cam->near;
        this->far = cam->far;
        this->firstPerson = cam->firstPerson;
        return true;
    }
    return false;
}
