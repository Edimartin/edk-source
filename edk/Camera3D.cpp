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

    this->up = edk::vec2f32(0.f,1.f);
    this->size = edk::size2f32(1.f,1.f);
    this->sizePercent = this->size.width/this->size.height;
    this->_near = 0.0001f;
    this->_far = 1.f;
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
void edk::Camera3D::setNearFar(edk::float32 _near,edk::float32 _far){
    if(_far>_near){
        this->_near = _near;
        this->_far = _far;
    }
    else{
        this->_near = _far;
        this->_far = _near;
    }
}
void edk::Camera3D::setFar(edk::float32 _far){
    this->setNearFar(0.0001f,_far);
}
//Get near and far
edk::float32 edk::Camera3D::getNear(){
    return this->_near;
}
edk::float32 edk::Camera3D::getFar(){
    return this->_far;
}

//Distance
edk::float32 edk::Camera3D::getDistance(){
    //
    return edk::Math::pythagoras(this->lookAt.x - this->position.x,
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

//functions to move the camera in his axis
void edk::Camera3D::moveHorizontal(edk::float32 distance){
    //get the right vector
    edk::float32 angle = this->getAngleX();
    edk::vec3f32 right;
    right.x = edk::Math::rotateX(1.f,angle+90.f);
    right.z = edk::Math::rotateY(1.f,angle+90.f);

    //move the distance
    this->position.x+=right.x * distance;
    this->position.y+=right.y * distance;
    this->position.z+=right.z * distance;
    this->lookAt.x+=right.x * distance;
    this->lookAt.y+=right.y * distance;
    this->lookAt.z+=right.z * distance;
}
void edk::Camera3D::moveVertical(edk::float32 distance){
    //
    edk::vec3f32 up;
    edk::float32 angleX = this->getAngleX();
    edk::float32 angleY = this->getAngleY();
    edk::float32 distanceX;
    edk::float32 distanceY;
    if(this->firstPerson){
        distanceX = edk::Math::pythagoras(this->lookAt.x - this->position.x,this->lookAt.z - this->position.z);
        distanceY = edk::Math::pythagoras(distanceX,this->lookAt.y - this->position.y);
        //
        distanceX = edk::Math::rotateX(distanceY,angleY+90.f);
        up.y = edk::Math::rotateY(distanceY,angleY+90.f) + this->position.z;
        //
        up.x = edk::Math::rotateX(distanceX,angleX) + this->position.x;
        up.z = edk::Math::rotateY(distanceX,angleX) + this->position.z;
    }
    else{
        distanceX = edk::Math::pythagoras(this->position.x - this->lookAt.x,this->position.z - this->lookAt.z);
        distanceY = edk::Math::pythagoras(distanceX,this->position.y - this->lookAt.y);
        //
        distanceX = edk::Math::rotateX(distanceY,angleY+90.f);
        up.y = edk::Math::rotateY(distanceY,angleY+90.f) + this->lookAt.z;
        //
        up.x = edk::Math::rotateX(distanceX,angleX) + this->lookAt.x;
        up.z = edk::Math::rotateY(distanceX,angleX) + this->lookAt.z;
    }

    //move the distance
    this->position.x+=up.x * distance;
    this->position.y+=up.y * distance;
    this->position.z+=up.z * distance;
    this->lookAt.x+=up.x * distance;
    this->lookAt.y+=up.y * distance;
    this->lookAt.z+=up.z * distance;
}

//return the angle width and height
edk::float32 edk::Camera3D::getAngleX(){
    if(this->firstPerson){
        return edk::Math::getAngle(this->lookAt.x-this->position.x,this->lookAt.z-this->position.z);
    }
    return edk::Math::getAngle(this->position.x-this->lookAt.x,this->position.z-this->lookAt.z);
}
edk::float32 edk::Camera3D::getAngleY(){
    if(this->firstPerson){
        return edk::Math::getAngle(edk::Math::pythagoras(this->lookAt.x-this->position.x,this->lookAt.z-this->position.z),this->lookAt.y-this->position.y);
    }
    return edk::Math::getAngle(edk::Math::pythagoras(this->position.x-this->lookAt.x,this->position.z-this->lookAt.z),this->position.y-this->lookAt.y);
}
edk::float32 edk::Camera3D::getAngleUp(){
    //
    return edk::Math::getAngle(this->up.x,this->up.y);
}
//set the angles
void edk::Camera3D::setAngleX(edk::float32 angle){
    if(this->firstPerson){
        edk::float32 distance = edk::Math::pythagoras(this->lookAt.x - this->position.x,this->lookAt.z - this->position.z);
        this->lookAt.x = edk::Math::rotateX(distance,angle) + this->position.x;
        this->lookAt.z = edk::Math::rotateY(distance,angle) + this->position.z;
    }
    else{
        edk::float32 distance = edk::Math::pythagoras(this->position.x - this->lookAt.x,this->position.z - this->lookAt.z);
        this->position.x = edk::Math::rotateX(distance,angle) + this->lookAt.x;
        this->position.z = edk::Math::rotateY(distance,angle) + this->lookAt.z;
    }
}
void edk::Camera3D::setAngleY(edk::float32 angle){
    if(this->firstPerson){
        edk::float32 angleX = this->getAngleX();
        edk::float32 distanceX = edk::Math::pythagoras(this->lookAt.x - this->position.x,this->lookAt.z - this->position.z);
        edk::float32 distanceY = edk::Math::pythagoras(distanceX,this->lookAt.y - this->position.y);
        //
        distanceX = edk::Math::rotateX(distanceY,angle);
        this->lookAt.y = edk::Math::rotateY(distanceY,angle) + this->position.y;
        //
        this->lookAt.x = edk::Math::rotateX(distanceX,angleX) + this->position.x;
        this->lookAt.z = edk::Math::rotateY(distanceX,angleX) + this->position.z;
    }
    else{
        edk::float32 angleX = this->getAngleX();
        edk::float32 distanceX = edk::Math::pythagoras(this->position.x - this->lookAt.x,this->position.z - this->lookAt.z);
        edk::float32 distanceY = edk::Math::pythagoras(distanceX,this->position.y - this->lookAt.y);
        //
        distanceX = edk::Math::rotateX(distanceY,angle);
        this->position.y = edk::Math::rotateY(distanceY,angle) + this->lookAt.y;
        //
        this->position.x = edk::Math::rotateX(distanceX,angleX) + this->lookAt.x;
        this->position.z = edk::Math::rotateY(distanceX,angleX) + this->lookAt.z;
    }
}
void edk::Camera3D::setAngleUp(edk::float32 angle){
    this->up.x = edk::Math::rotateX(1.f,angle);
    this->up.y = edk::Math::rotateY(1.f,angle);
}
//move the angles
void edk::Camera3D::rotateAngleX(edk::float32 angle){
    this->setAngleX(angle + this->getAngleX());
}
void edk::Camera3D::rotateAngleY(edk::float32 angle){
    this->setAngleY(angle + this->getAngleY());
}
void edk::Camera3D::rotateAngleUp(edk::float32 angle){
    this->setAngleUp(angle + this->getAngleUp());
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
        edk::GU::guUsePerspective(this->size.height*2.f,this->sizePercent,this->_near,this->_far);
    }
    else{
        edk::GU::guUseOrtho(-this->size.width,
                            this->size.width,
                            -this->size.height,
                            this->size.height,
                            this->_near,//nea
                            this->_far//far
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
                      this->up.x,this->up.y,0.f
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
        this->_near = cam->_near;
        this->_far = cam->_far;
        this->firstPerson = cam->firstPerson;
        return true;
    }
    return false;
}
