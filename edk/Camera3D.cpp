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
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::Camera3D::Camera3D(edk::vec3f32 position,edk::vec3f32 lookAt){
    this->classThis=NULL;edkEnd();
    this->Constructor(position,lookAt,false);edkEnd();
}
edk::Camera3D::Camera3D(edk::float32 pX,edk::float32 pY,edk::float32 pZ,edk::float32 lookX,edk::float32 lookY,edk::float32 lookZ){
    this->classThis=NULL;edkEnd();
    this->Constructor(pX,pY,pZ,lookX,lookY,lookZ,false);edkEnd();
}
edk::Camera3D::~Camera3D(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::Camera3D::Constructor(bool /*runFather*/){
    //
    if(this->classThis!=this){
        this->classThis=this;
        this->matrixTranslate.Constructor();
        this->matrixRotateX.Constructor();
        this->matrixRotateY.Constructor();
        this->matrixRotateZ.Constructor();
        this->matrixScale.Constructor();
        this->projection.Constructor();
        this->matrixPosition.Constructor();
        this->start();edkEnd();
        this->perspective = true;edkEnd();
        this->firstPerson=false;edkEnd();
        this->matrixPosition.createMatrix(1u,4u);edkEnd();
    }
}
void edk::Camera3D::Constructor(edk::vec3f32 position,edk::vec3f32 lookAt,bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;
        this->matrixTranslate.Constructor();
        this->matrixRotateX.Constructor();
        this->matrixRotateY.Constructor();
        this->matrixRotateZ.Constructor();
        this->matrixScale.Constructor();
        this->projection.Constructor();
        this->matrixPosition.Constructor();
        this->start();edkEnd();
        this->position = position;edkEnd();
        this->lookAt = lookAt;edkEnd();
        this->perspective = true;edkEnd();
        this->firstPerson=false;edkEnd();
        this->matrixPosition.createMatrix(1u,4u);edkEnd();
    }
}
void edk::Camera3D::Constructor(edk::float32 pX,edk::float32 pY,edk::float32 pZ,edk::float32 lookX,edk::float32 lookY,edk::float32 lookZ,bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;
        this->matrixTranslate.Constructor();
        this->matrixRotateX.Constructor();
        this->matrixRotateY.Constructor();
        this->matrixRotateZ.Constructor();
        this->matrixScale.Constructor();
        this->projection.Constructor();
        this->matrixPosition.Constructor();
        this->start();edkEnd();
        this->position = edk::vec3f32(pX,pY,pZ);edkEnd();
        this->lookAt = edk::vec3f32(lookX,lookY,lookZ);edkEnd();
        this->perspective = true;edkEnd();
        this->firstPerson=false;edkEnd();
        this->matrixPosition.createMatrix(1u,3u);edkEnd();
    }
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

    this->updateProjection();
}
//generate the camera matrix
void edk::Camera3D::calculateProjectionMatrix(){
    this->projection.setIdentity(1.f,0.f);edkEnd();
    edk::Math::generateLookAtMatrix(this->position.x,this->position.y,this->position.z,
                                    this->lookAt.x,this->lookAt.y,this->lookAt.z,
                                    this->up.x,this->up.y,0.f,
                                    &this->projection
                                    );edkEnd();
}
//update the camera vectors
void edk::Camera3D::updateVectors(){
    //multiply the vectors
    //for some reazon it must be a giant lenght to work
    this->vecLeft=  edk::Math::normalise(this->multiplyPointWithMatrix(edk::vec3f32(-10000.f, 0.f, 0.f)));edkEnd();
    this->vecRight= edk::Math::normalise(this->multiplyPointWithMatrix(edk::vec3f32( 10000.f, 0.f, 0.f)));edkEnd();
    this->vecUp=    edk::Math::normalise(this->multiplyPointWithMatrix(edk::vec3f32( 0.f, 10000.f, 0.f)));edkEnd();
    this->vecDown=  edk::Math::normalise(this->multiplyPointWithMatrix(edk::vec3f32( 0.f,-10000.f, 0.f)));edkEnd();
    this->vecFront= edk::Math::normalise(this->multiplyPointWithMatrix(edk::vec3f32( 0.f, 0.f, 10000.f)));edkEnd();
    this->vecBack=  edk::Math::normalise(this->multiplyPointWithMatrix(edk::vec3f32( 0.f, 0.f,-10000.f)));edkEnd();
}
//multiply a point to the matrix
edk::vec3f32 edk::Camera3D::multiplyPointWithMatrix(edk::vec3f32 point){
    if(this->matrixPosition.haveMatrix()){
        //
        this->matrixPosition.set(0u,0u,point.x);edkEnd();
        this->matrixPosition.set(0u,1u,point.y);edkEnd();
        this->matrixPosition.set(0u,2u,point.z);edkEnd();
        this->matrixPosition.set(0u,3u,1.f);edkEnd();

        //multiply the matrix
        this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->projection);edkEnd();

        point.x = this->matrixPosition.getNoIF(0u,0u);edkEnd();
        point.y = this->matrixPosition.getNoIF(0u,1u);edkEnd();
        point.z = this->matrixPosition.getNoIF(0u,2u);edkEnd();
    }
    return point;
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
    this->updateVectors();
}
edk::vector::Matrixf32<4u,4u>* edk::Camera3D::getProjection(){
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

//draw a wire camera in the world
void edk::Camera3D::drawPivo(edk::float32 size,
                             edk::color3f32 positionColor,
                             edk::color3f32 lookAtColor,
                             edk::color3f32 distanceColor
                             ){
    //draw the two pivo
    edk::GU::guBegin(GU_LINES);
    edk::GU::guColor3f32(positionColor);
    //position
    edk::GU::guVertex3f32(this->position.x+(this->vecLeft.x*size),
                          this->position.y+(this->vecLeft.y*size),
                          this->position.z+(this->vecLeft.z*size)
                          );
    edk::GU::guVertex3f32(this->position.x+(this->vecRight.x*size),
                          this->position.y+(this->vecRight.y*size),
                          this->position.z+(this->vecRight.z*size)
                          );
    edk::GU::guVertex3f32(this->position.x+(this->vecUp.x*size),
                          this->position.y+(this->vecUp.y*size),
                          this->position.z+(this->vecUp.z*size)
                          );
    edk::GU::guVertex3f32(this->position.x+(this->vecDown.x*size),
                          this->position.y+(this->vecDown.y*size),
                          this->position.z+(this->vecDown.z*size)
                          );
    edk::GU::guVertex3f32(this->position.x,
                          this->position.y,
                          this->position.z
                          );
    edk::GU::guVertex3f32(this->position.x+(this->vecBack.x*size),
                          this->position.y+(this->vecBack.y*size),
                          this->position.z+(this->vecBack.z*size)
                          );
    edk::GU::guColor3f32(lookAtColor);
    //lookAt
    edk::GU::guVertex3f32(this->lookAt.x+(this->vecLeft.x*size),
                          this->lookAt.y+(this->vecLeft.y*size),
                          this->lookAt.z+(this->vecLeft.z*size)
                          );
    edk::GU::guVertex3f32(this->lookAt.x+(this->vecRight.x*size),
                          this->lookAt.y+(this->vecRight.y*size),
                          this->lookAt.z+(this->vecRight.z*size)
                          );
    edk::GU::guVertex3f32(this->lookAt.x+(this->vecUp.x*size),
                          this->lookAt.y+(this->vecUp.y*size),
                          this->lookAt.z+(this->vecUp.z*size)
                          );
    edk::GU::guVertex3f32(this->lookAt.x+(this->vecDown.x*size),
                          this->lookAt.y+(this->vecDown.y*size),
                          this->lookAt.z+(this->vecDown.z*size)
                          );
    edk::GU::guVertex3f32(this->lookAt.x,
                          this->lookAt.y,
                          this->lookAt.z
                          );
    edk::GU::guVertex3f32(this->lookAt.x+(this->vecBack.x*size),
                          this->lookAt.y+(this->vecBack.y*size),
                          this->lookAt.z+(this->vecBack.z*size)
                          );
    edk::GU::guColor3f32(distanceColor);
    //Line
    edk::GU::guVertex3f32(this->position.x,
                          this->position.y,
                          this->position.z
                          );
    edk::GU::guVertex3f32(this->lookAt.x,
                          this->lookAt.y,
                          this->lookAt.z
                          );
    edk::GU::guEnd();
}
void edk::Camera3D::drawPivo(edk::float32 size,
                             edk::float32 positionR,
                             edk::float32 positionG,
                             edk::float32 positionB,
                             edk::float32 lookAtR,
                             edk::float32 lookAtG,
                             edk::float32 lookAtB,
                             edk::float32 distanceR,
                             edk::float32 distanceG,
                             edk::float32 distanceB
                             ){
    this->drawPivo(size,
                   edk::color3f32(positionR,positionG,positionB),
                   edk::color3f32(lookAtR,lookAtG,lookAtB),
                   edk::color3f32(distanceR,distanceG,distanceB)
                   );
}
void edk::Camera3D::drawPivo(edk::float32 size,
                             edk::color3f32 positionColor,
                             edk::color3f32 lookAtColor
                             ){
    //draw the two pivo
    edk::GU::guBegin(GU_LINES);
    edk::GU::guColor3f32(positionColor);
    //position
    edk::GU::guVertex3f32(this->position.x+(this->vecLeft.x*size),
                          this->position.y+(this->vecLeft.y*size),
                          this->position.z+(this->vecLeft.z*size)
                          );
    edk::GU::guVertex3f32(this->position.x+(this->vecRight.x*size),
                          this->position.y+(this->vecRight.y*size),
                          this->position.z+(this->vecRight.z*size)
                          );
    edk::GU::guVertex3f32(this->position.x+(this->vecUp.x*size),
                          this->position.y+(this->vecUp.y*size),
                          this->position.z+(this->vecUp.z*size)
                          );
    edk::GU::guVertex3f32(this->position.x+(this->vecDown.x*size),
                          this->position.y+(this->vecDown.y*size),
                          this->position.z+(this->vecDown.z*size)
                          );
    edk::GU::guVertex3f32(this->position.x,
                          this->position.y,
                          this->position.z
                          );
    edk::GU::guVertex3f32(this->position.x+(this->vecBack.x*size),
                          this->position.y+(this->vecBack.y*size),
                          this->position.z+(this->vecBack.z*size)
                          );
    edk::GU::guColor3f32(lookAtColor);
    //lookAt
    edk::GU::guVertex3f32(this->lookAt.x+(this->vecLeft.x*size),
                          this->lookAt.y+(this->vecLeft.y*size),
                          this->lookAt.z+(this->vecLeft.z*size)
                          );
    edk::GU::guVertex3f32(this->lookAt.x+(this->vecRight.x*size),
                          this->lookAt.y+(this->vecRight.y*size),
                          this->lookAt.z+(this->vecRight.z*size)
                          );
    edk::GU::guVertex3f32(this->lookAt.x+(this->vecUp.x*size),
                          this->lookAt.y+(this->vecUp.y*size),
                          this->lookAt.z+(this->vecUp.z*size)
                          );
    edk::GU::guVertex3f32(this->lookAt.x+(this->vecDown.x*size),
                          this->lookAt.y+(this->vecDown.y*size),
                          this->lookAt.z+(this->vecDown.z*size)
                          );
    edk::GU::guVertex3f32(this->lookAt.x+(this->vecFront.x*size),
                          this->lookAt.y+(this->vecFront.y*size),
                          this->lookAt.z+(this->vecFront.z*size)
                          );
    edk::GU::guVertex3f32(this->lookAt.x,
                          this->lookAt.y,
                          this->lookAt.z
                          );
    //Line
    edk::GU::guColor3f32(positionColor);
    edk::GU::guVertex3f32(this->position.x,
                          this->position.y,
                          this->position.z
                          );
    edk::GU::guColor3f32(lookAtColor);
    edk::GU::guVertex3f32(this->lookAt.x,
                          this->lookAt.y,
                          this->lookAt.z
                          );
    edk::GU::guEnd();
}
void edk::Camera3D::drawPivo(edk::float32 size,
                             edk::float32 positionR,
                             edk::float32 positionG,
                             edk::float32 positionB,
                             edk::float32 lookAtR,
                             edk::float32 lookAtG,
                             edk::float32 lookAtB
                             ){
    this->drawPivo(size,
                   edk::color3f32(positionR,positionG,positionB),
                   edk::color3f32(lookAtR,lookAtG,lookAtB)
                   );
}
void edk::Camera3D::drawPivo(edk::float32 size,edk::color3f32 color){
    this->drawPivo(size,
                   color,
                   color,
                   color
                   );
}
void edk::Camera3D::drawPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    this->drawPivo(size,
                   edk::color3f32(r,g,b),
                   edk::color3f32(r,g,b),
                   edk::color3f32(r,g,b)
                   );
}
void edk::Camera3D::drawVectors(edk::float32 size,edk::color3f32 color){
    //draw the two pivo
    edk::GU::guBegin(GU_LINES);
    edk::GU::guColor3f32(color);
    //LEFT
    edk::GU::guVertex3f32(this->lookAt.x,
                          this->lookAt.y,
                          this->lookAt.z
                          );
    edk::GU::guVertex3f32(this->lookAt.x+(this->vecLeft.x*size),
                          this->lookAt.y+(this->vecLeft.y*size),
                          this->lookAt.z+(this->vecLeft.z*size)
                          );
    //RIGHT
    edk::GU::guVertex3f32(this->lookAt.x,
                          this->lookAt.y,
                          this->lookAt.z
                          );
    edk::GU::guVertex3f32(this->lookAt.x+(this->vecRight.x*size),
                          this->lookAt.y+(this->vecRight.y*size),
                          this->lookAt.z+(this->vecRight.z*size)
                          );
    //UP
    edk::GU::guVertex3f32(this->lookAt.x,
                          this->lookAt.y,
                          this->lookAt.z
                          );
    edk::GU::guVertex3f32(this->lookAt.x+(this->vecUp.x*size),
                          this->lookAt.y+(this->vecUp.y*size),
                          this->lookAt.z+(this->vecUp.z*size)
                          );
    //DOWN
    edk::GU::guVertex3f32(this->lookAt.x,
                          this->lookAt.y,
                          this->lookAt.z
                          );
    edk::GU::guVertex3f32(this->lookAt.x+(this->vecDown.x*size),
                          this->lookAt.y+(this->vecDown.y*size),
                          this->lookAt.z+(this->vecDown.z*size)
                          );
    //FRONT
    edk::GU::guVertex3f32(this->lookAt.x,
                          this->lookAt.y,
                          this->lookAt.z
                          );
    edk::GU::guVertex3f32(this->lookAt.x+(this->vecFront.x*size),
                          this->lookAt.y+(this->vecFront.y*size),
                          this->lookAt.z+(this->vecFront.z*size)
                          );
    //BACK
    edk::GU::guVertex3f32(this->lookAt.x,
                          this->lookAt.y,
                          this->lookAt.z
                          );
    edk::GU::guVertex3f32(this->lookAt.x+(this->vecBack.x*size),
                          this->lookAt.y+(this->vecBack.y*size),
                          this->lookAt.z+(this->vecBack.z*size)
                          );
    edk::GU::guEnd();
}
void edk::Camera3D::drawVectors(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    return this->drawVectors(size,edk::color3f32(r,g,b));
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
