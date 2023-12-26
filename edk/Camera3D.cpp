#include "Camera3D.h"

/*
Library Camera3D - 3D camera in a 3D World
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

edk::Camera3D::Camera3D(){
    //
    this->start();edkEnd();
    this->perspective = true;edkEnd();
    this->firstPerson=false;edkEnd();
}
edk::Camera3D::Camera3D(edk::vec3f32 position,edk::vec3f32 lookAt){
    this->start();edkEnd();
    this->position = position;edkEnd();
    this->lookAt = lookAt;edkEnd();
    this->perspective = true;edkEnd();
    this->firstPerson=false;edkEnd();
}
edk::Camera3D::Camera3D(edk::float32 pX,edk::float32 pY,edk::float32 pZ,edk::float32 lookX,edk::float32 lookY,edk::float32 lookZ){
    this->start();edkEnd();
    this->position = edk::vec3f32(pX,pY,pZ);edkEnd();
    this->lookAt = edk::vec3f32(lookX,lookY,lookZ);edkEnd();
    this->perspective = true;edkEnd();
    this->firstPerson=false;edkEnd();
}
edk::Camera3D::~Camera3D(){
    //
}
void edk::Camera3D::start(){
    //
    this->position = edk::vec3f32(0.f,0.f,-1.f);edkEnd();
    this->lookAt = edk::vec3f32(0.f,0.f,0.f);edkEnd();

    this->up = edk::vec2f32(0.f,1.f);edkEnd();
    this->size = edk::size2f32(1.f,1.f);edkEnd();
    this->sizePercent = this->size.width/this->size.height;edkEnd();
    this->_near = 0.0001f;edkEnd();
    this->_far = 1.f;edkEnd();
}
//generate the camera matrix
void edk::Camera3D::calculateProjectionMatrix(){
    this->projection.setIdentity(1.f,0.f);
    //generate the translate matrix
    edk::Math::generateTranslateMatrix(this->position-1.f,&this->matrixTranslate);edkEnd();
    //generate the rotate matrix
    edk::Math::generateRotateMatrixX(this->getAngleX()*-1.f,&this->matrixRotateX);edkEnd();
    edk::Math::generateRotateMatrixY(this->getAngleY()*-1.f,&this->matrixRotateY);edkEnd();
    edk::Math::generateRotateMatrixZ(this->getAngleUp()*-1.f,&this->matrixRotateZ);edkEnd();

    //multiply the matrix
    //translate
    this->projection.multiplyThisWithMatrix(&this->matrixTranslate);edkEnd();
    //angle
    this->projection.multiplyThisWithMatrix(&this->matrixRotateX);edkEnd();
    this->projection.multiplyThisWithMatrix(&this->matrixRotateY);edkEnd();
    this->projection.multiplyThisWithMatrix(&this->matrixRotateZ);edkEnd();
}

//Sset witch camera type its using
void edk::Camera3D::usePerspective(){
    this->perspective=true;edkEnd();
}
void edk::Camera3D::useOrtho(){
    this->perspective=false;edkEnd();
}

//set the size
void edk::Camera3D::setSize(edk::size2f32 size){
    //
    this->size=size*0.5f;edkEnd();
    this->sizePercent = this->size.width/this->size.height;edkEnd();
}
void edk::Camera3D::setSize(edk::float32 sizeW,edk::float32 sizeH){
    //
    return this->setSize(edk::size2f32(sizeW,sizeH));edkEnd();
}
void edk::Camera3D::setSizeW(edk::float32 width){
    this->size.width = width*0.5f;edkEnd();
    this->sizePercent = this->size.width/this->size.height;edkEnd();
}
void edk::Camera3D::setSizeH(edk::float32 height){
    this->size.height = height*0.5f;edkEnd();
    this->sizePercent = this->size.width/this->size.height;edkEnd();
}
//return the size
edk::float32 edk::Camera3D::getWidth(){
    return this->size.width * 2.f;edkEnd();
}
edk::float32 edk::Camera3D::getHeight(){
    return this->size.height * 2.f;edkEnd();
}

//set near and far
void edk::Camera3D::setNearFar(edk::float32 _near,edk::float32 _far){
    if(_far>_near){
        this->_near = _near;edkEnd();
        this->_far = _far;edkEnd();
    }
    else{
        this->_near = _far;edkEnd();
        this->_far = _near;edkEnd();
    }
}
void edk::Camera3D::setFar(edk::float32 _far){
    this->setNearFar(0.0001f,_far);edkEnd();
}
//Get near and far
edk::float32 edk::Camera3D::getNear(){
    return this->_near;edkEnd();
}
edk::float32 edk::Camera3D::getFar(){
    return this->_far;edkEnd();
}

//Distance
edk::float32 edk::Camera3D::getDistance(){
    //
    return edk::Math::pythagoras(this->lookAt.x - this->position.x,
                                 this->lookAt.y - this->position.y,
                                 this->lookAt.y - this->position.z
                                 );edkEnd();
}
//set the distance
bool edk::Camera3D::setDistance(edk::float32 distance){
    if(distance>0.f){
        edk::float32 percent = distance / this->getDistance();edkEnd();
        //set the distance
        if(this->firstPerson){
            //
            this->lookAt.x = this->position.x + ((this->lookAt.x-this->position.x) * percent);edkEnd();
            this->lookAt.y = this->position.y + ((this->lookAt.y-this->position.y) * percent);edkEnd();
            this->lookAt.z = this->position.z + ((this->lookAt.z-this->position.z) * percent);edkEnd();
        }
        else{
            //
            this->position.x = this->lookAt.x + ((this->position.x-this->lookAt.x) * percent);edkEnd();
            this->position.y = this->lookAt.y + ((this->position.y-this->lookAt.y) * percent);edkEnd();
            this->position.z = this->lookAt.z + ((this->position.z-this->lookAt.z) * percent);edkEnd();
        }
        return true;
    }
    return false;
}
//move the distance
bool edk::Camera3D::moveDistance(edk::float32 distance){
    return this->setDistance(this->getDistance()+distance);edkEnd();
}
bool edk::Camera3D::incrementDistance(edk::float32 distance){
    return this->setDistance(this->getDistance()+distance);edkEnd();
}

//functions to move the camera in his axis
void edk::Camera3D::moveHorizontal(edk::float32 distance){
    //get the right vector
    edk::float32 angle = this->getAngleX();edkEnd();
    edk::vec3f32 right;edkEnd();
    right.x = edk::Math::rotateX(1.f,angle+90.f);edkEnd();
    right.z = edk::Math::rotateY(1.f,angle+90.f);edkEnd();

    //move the distance
    this->position.x+=right.x * distance;edkEnd();
    this->position.y+=right.y * distance;edkEnd();
    this->position.z+=right.z * distance;edkEnd();
    this->lookAt.x+=right.x * distance;edkEnd();
    this->lookAt.y+=right.y * distance;edkEnd();
    this->lookAt.z+=right.z * distance;edkEnd();
}
void edk::Camera3D::moveVertical(edk::float32 distance){
    //
    edk::vec3f32 up;edkEnd();
    edk::float32 angleX = this->getAngleX();edkEnd();
    edk::float32 angleY = this->getAngleY();edkEnd();
    edk::float32 distanceX;edkEnd();
    edk::float32 distanceY;edkEnd();
    if(this->firstPerson){
        distanceX = edk::Math::pythagoras(this->lookAt.x - this->position.x,this->lookAt.z - this->position.z);edkEnd();
        distanceY = edk::Math::pythagoras(distanceX,this->lookAt.y - this->position.y);edkEnd();
        //
        distanceX = edk::Math::rotateX(distanceY,angleY+90.f);edkEnd();
        up.y = edk::Math::rotateY(distanceY,angleY+90.f) + this->position.z;edkEnd();
        //
        up.x = edk::Math::rotateX(distanceX,angleX) + this->position.x;edkEnd();
        up.z = edk::Math::rotateY(distanceX,angleX) + this->position.z;edkEnd();
    }
    else{
        distanceX = edk::Math::pythagoras(this->position.x - this->lookAt.x,this->position.z - this->lookAt.z);edkEnd();
        distanceY = edk::Math::pythagoras(distanceX,this->position.y - this->lookAt.y);edkEnd();
        //
        distanceX = edk::Math::rotateX(distanceY,angleY+90.f);edkEnd();
        up.y = edk::Math::rotateY(distanceY,angleY+90.f) + this->lookAt.z;edkEnd();
        //
        up.x = edk::Math::rotateX(distanceX,angleX) + this->lookAt.x;edkEnd();
        up.z = edk::Math::rotateY(distanceX,angleX) + this->lookAt.z;edkEnd();
    }

    //move the distance
    this->position.x+=up.x * distance;edkEnd();
    this->position.y+=up.y * distance;edkEnd();
    this->position.z+=up.z * distance;edkEnd();
    this->lookAt.x+=up.x * distance;edkEnd();
    this->lookAt.y+=up.y * distance;edkEnd();
    this->lookAt.z+=up.z * distance;edkEnd();
}

//return the angle width and height
edk::float32 edk::Camera3D::getAngleX(){
    if(this->firstPerson){
        return edk::Math::getAngle(this->lookAt.x-this->position.x,this->lookAt.z-this->position.z);edkEnd();
    }
    return edk::Math::getAngle(this->position.x-this->lookAt.x,this->position.z-this->lookAt.z);edkEnd();
}
edk::float32 edk::Camera3D::getAngleY(){
    if(this->firstPerson){
        return edk::Math::getAngle(edk::Math::pythagoras(this->lookAt.x-this->position.x,this->lookAt.z-this->position.z),this->lookAt.y-this->position.y);edkEnd();
    }
    return edk::Math::getAngle(edk::Math::pythagoras(this->position.x-this->lookAt.x,this->position.z-this->lookAt.z),this->position.y-this->lookAt.y);edkEnd();
}
edk::float32 edk::Camera3D::getAngleUp(){
    //
    return edk::Math::getAngle(this->up.x,this->up.y);edkEnd();
}
//set the angles
void edk::Camera3D::setAngleX(edk::float32 angle){
    if(this->firstPerson){
        edk::float32 distance = edk::Math::pythagoras(this->lookAt.x - this->position.x,this->lookAt.z - this->position.z);edkEnd();
        this->lookAt.x = edk::Math::rotateX(distance,angle) + this->position.x;edkEnd();
        this->lookAt.z = edk::Math::rotateY(distance,angle) + this->position.z;edkEnd();
    }
    else{
        edk::float32 distance = edk::Math::pythagoras(this->position.x - this->lookAt.x,this->position.z - this->lookAt.z);edkEnd();
        this->position.x = edk::Math::rotateX(distance,angle) + this->lookAt.x;edkEnd();
        this->position.z = edk::Math::rotateY(distance,angle) + this->lookAt.z;edkEnd();
    }
}
void edk::Camera3D::setAngleY(edk::float32 angle){
    if(this->firstPerson){
        edk::float32 angleX = this->getAngleX();edkEnd();
        edk::float32 distanceX = edk::Math::pythagoras(this->lookAt.x - this->position.x,this->lookAt.z - this->position.z);edkEnd();
        edk::float32 distanceY = edk::Math::pythagoras(distanceX,this->lookAt.y - this->position.y);edkEnd();
        //
        distanceX = edk::Math::rotateX(distanceY,angle);edkEnd();
        this->lookAt.y = edk::Math::rotateY(distanceY,angle) + this->position.y;edkEnd();
        //
        this->lookAt.x = edk::Math::rotateX(distanceX,angleX) + this->position.x;edkEnd();
        this->lookAt.z = edk::Math::rotateY(distanceX,angleX) + this->position.z;edkEnd();
    }
    else{
        edk::float32 angleX = this->getAngleX();edkEnd();
        edk::float32 distanceX = edk::Math::pythagoras(this->position.x - this->lookAt.x,this->position.z - this->lookAt.z);edkEnd();
        edk::float32 distanceY = edk::Math::pythagoras(distanceX,this->position.y - this->lookAt.y);edkEnd();
        //
        distanceX = edk::Math::rotateX(distanceY,angle);edkEnd();
        this->position.y = edk::Math::rotateY(distanceY,angle) + this->lookAt.y;edkEnd();
        //
        this->position.x = edk::Math::rotateX(distanceX,angleX) + this->lookAt.x;edkEnd();
        this->position.z = edk::Math::rotateY(distanceX,angleX) + this->lookAt.z;edkEnd();
    }
}
void edk::Camera3D::setAngleUp(edk::float32 angle){
    this->up.x = edk::Math::rotateX(1.f,angle);edkEnd();
    this->up.y = edk::Math::rotateY(1.f,angle);edkEnd();
}
//move the angles
void edk::Camera3D::rotateAngleX(edk::float32 angle){
    this->setAngleX(angle + this->getAngleX());edkEnd();
}
void edk::Camera3D::rotateAngleY(edk::float32 angle){
    this->setAngleY(angle + this->getAngleY());edkEnd();
}
void edk::Camera3D::rotateAngleUp(edk::float32 angle){
    this->setAngleUp(angle + this->getAngleUp());edkEnd();
}

//get the projection matrix
void edk::Camera3D::updateProjection(){
    this->calculateProjectionMatrix();
}
edk::vector::Matrix<edk::float32,4u,4u>* edk::Camera3D::getProjection(){
    return &this->projection;
}

//draw the camera
void edk::Camera3D::draw(){
    //
    //test if are NOT using GUmodelview
    if(!edk::GU::guUsingMatrix(GU_PROJECTION)){
        //then set to use modelView
        edk::GU::guUseMatrix(GU_PROJECTION);edkEnd();
    }
    edk::GU::guLoadIdentity();edkEnd();
    //
    edk::Camera3D::drawAxisOnly();edkEnd();
}
void edk::Camera3D::drawAxisOnly(){
    if(this->perspective){
        edk::GU::guUsePerspective(this->size.height*2.f,this->sizePercent,this->_near,this->_far);edkEnd();
    }
    else{
        edk::GU::guUseOrtho(-this->size.width,
                            this->size.width,
                            -this->size.height,
                            this->size.height,
                            this->_near,//nea
                            this->_far//far
                            );edkEnd();
    }

    edk::GU::guLookAt(this->position.x,this->position.y,this->position.z,
                      this->lookAt.x,this->lookAt.y,this->lookAt.z,
                      this->up.x,this->up.y,0.f
                      );edkEnd();
}
void edk::Camera3D::drawAxisOnly(edk::float32 /*seconds*/){
    //
}

//operator to copy the cameras
bool edk::Camera3D::cloneFrom(edk::Camera3D* cam){
    if(cam){
        this->position = cam->position;edkEnd();
        this->lookAt = cam->lookAt;edkEnd();
        this->perspective = cam->perspective;edkEnd();
        this->up = cam->up;edkEnd();
        this->size = cam->size;edkEnd();
        this->sizePercent = cam->sizePercent;edkEnd();
        this->_near = cam->_near;edkEnd();
        this->_far = cam->_far;edkEnd();
        this->firstPerson = cam->firstPerson;edkEnd();
        this->projection.cloneFrom(&cam->projection);
        return true;
    }
    return false;
}
