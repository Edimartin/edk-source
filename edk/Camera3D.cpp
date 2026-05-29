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

#ifdef printMessages
#pragma message "            Inside Camera3D.cpp"
#endif

edk::Camera3D::Camera3D(){
    this->classThis=NULL;
    this->Constructor();
}
edk::Camera3D::Camera3D(edk::vec3f32 position,edk::vec3f32 lookAt){
    this->classThis=NULL;
    this->Constructor(position,lookAt);
}
edk::Camera3D::Camera3D(edk::float32 pX,edk::float32 pY,edk::float32 pZ,edk::float32 lookX,edk::float32 lookY,edk::float32 lookZ){
    this->classThis=NULL;
    this->Constructor(pX,pY,pZ,lookX,lookY,lookZ);
}
edk::Camera3D::~Camera3D(){
    this->Destructor();
}

void edk::Camera3D::Constructor(){
    //
    if(this->classThis!=this){
        this->perspective=true;
        this->classThis=this;
        this->matrixTranslate.Constructor();
        this->matrixRotateX.Constructor();
        this->matrixRotateY.Constructor();
        this->matrixRotateZ.Constructor();
        this->matrixScale.Constructor();
        this->projection.Constructor();
        this->lookAtView.Constructor();
        this->matrixPosition.Constructor();
        this->animPosition.Constructor();
        this->animLookAt.Constructor();
        this->animAngleUp.Constructor();
        this->animShakeInitPosition.Constructor();
        this->animShakeInitAngle.Constructor();
        this->tempPosition = edk::vec3f32(0.f,0.f,0.f);
        this->shakePosition = edk::vec2f32(0.f,0.f);
        this->shakeAngle=0.f;
        this->shakeDistance=0.f;
        this->runningShakePosition=false;
        this->pauseShakePosition=false;
        this->runningShakeAngle=false;
        this->pauseShakeAngle=false;
        this->shakeSecondsInit=0.f;
        this->shakeRandomPercent=0.f;
        this->shakeInterpolationDistance=0.f;

        this->start();
        this->perspective = true;
        this->firstPerson=false;
        this->matrixPosition.createMatrix(1u,4u);
    }
}
void edk::Camera3D::Constructor(edk::vec3f32 position,edk::vec3f32 lookAt){
    if(this->classThis!=this){
        this->classThis=this;
        this->matrixTranslate.Constructor();
        this->matrixRotateX.Constructor();
        this->matrixRotateY.Constructor();
        this->matrixRotateZ.Constructor();
        this->matrixScale.Constructor();
        this->projection.Constructor();
        this->lookAtView.Constructor();
        this->matrixPosition.Constructor();
        this->animPosition.Constructor();
        this->animLookAt.Constructor();
        this->animAngleUp.Constructor();
        this->animShakeInitPosition.Constructor();
        this->animShakeInitAngle.Constructor();
        this->tempPosition = edk::vec3f32(0.f,0.f,0.f);
        this->shakePosition = edk::vec2f32(0.f,0.f);
        this->shakeAngle=0.f;
        this->shakeDistance=0.f;
        this->runningShakePosition=false;
        this->pauseShakePosition=false;
        this->runningShakeAngle=false;
        this->pauseShakeAngle=false;
        this->shakeSecondsInit=0.f;
        this->shakeRandomPercent=0.f;
        this->shakeInterpolationDistance=0.f;

        this->start();
        this->position = position;
        this->lookAt = lookAt;
        this->perspective = true;
        this->firstPerson=false;
        this->matrixPosition.createMatrix(1u,4u);
    }
}
void edk::Camera3D::Constructor(edk::float32 pX,
                                edk::float32 pY,
                                edk::float32 pZ,
                                edk::float32 lookX,
                                edk::float32 lookY,
                                edk::float32 lookZ
                                ){
    if(this->classThis!=this){
        this->classThis=this;
        this->matrixTranslate.Constructor();
        this->matrixRotateX.Constructor();
        this->matrixRotateY.Constructor();
        this->matrixRotateZ.Constructor();
        this->matrixScale.Constructor();
        this->projection.Constructor();
        this->lookAtView.Constructor();
        this->matrixPosition.Constructor();
        this->animPosition.Constructor();
        this->animLookAt.Constructor();
        this->animAngleUp.Constructor();
        this->animShakeInitPosition.Constructor();
        this->animShakeInitAngle.Constructor();
        this->tempPosition = edk::vec3f32(0.f,0.f,0.f);
        this->shakePosition = edk::vec2f32(0.f,0.f);
        this->shakeAngle=0.f;
        this->shakeDistance=0.f;
        this->runningShakePosition=false;
        this->pauseShakePosition=false;
        this->runningShakeAngle=false;
        this->pauseShakeAngle=false;
        this->shakeSecondsInit=0.f;
        this->shakeRandomPercent=0.f;
        this->shakeInterpolationDistance=0.f;

        this->start();
        this->position = edk::vec3f32(pX,pY,pZ);
        this->lookAt = edk::vec3f32(lookX,lookY,lookZ);
        this->perspective = true;
        this->firstPerson=false;
        this->matrixPosition.createMatrix(1u,3u);
    }
}
void edk::Camera3D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class

        this->matrixTranslate.Destructor();
        this->matrixRotateX.Destructor();
        this->matrixRotateY.Destructor();
        this->matrixRotateZ.Destructor();
        this->matrixScale.Destructor();
        this->projection.Destructor();
        this->lookAtView.Destructor();
        this->matrixPosition.Destructor();
        this->animPosition.Destructor();
        this->animLookAt.Destructor();
        this->animAngleUp.Destructor();
        this->animShakeInitPosition.Destructor();
        this->animShakeInitAngle.Destructor();
    }
}

void edk::Camera3D::start(){
    //
    this->position = edk::vec3f32(0.f,0.f,-1.f);
    this->lookAt = edk::vec3f32(0.f,0.f,0.f);

    this->up = edk::vec3f32(0.f,1.f,0.f);
    this->size = edk::size2f32(1.f,1.f);
    if(edk::Math::equal(0.f,this->size.height)){
        this->sizePercent = this->size.width/(this->size.height+0.001f);
    }
    else{
        this->sizePercent = this->size.width/this->size.height;
    }
    this->distancePercent = edk::Math::pythagoras(this->size.width*0.5f,this->size.height*0.5f);
    this->_near = 0.0001f;
    this->_far = 1.f;

    this->updateProjection();
}
//update the camera vectors
void edk::Camera3D::updateVectors(){
    //multiply the vectors
    //for some reazon it must be a giant length to work
    this->vecLeft=  edk::Math::normalise(this->multiplyPointWithMatrix(edk::vec3f32(-1.f, 0.f, 0.f)));
    this->vecRight= edk::Math::normalise(this->multiplyPointWithMatrix(edk::vec3f32( 1.f, 0.f, 0.f)));
    this->vecUp=    edk::Math::normalise(this->multiplyPointWithMatrix(edk::vec3f32( 0.f, 1.f, 0.f)));
    this->vecDown=  edk::Math::normalise(this->multiplyPointWithMatrix(edk::vec3f32( 0.f,-1.f, 0.f)));
    this->vecFront= edk::Math::normalise(this->multiplyPointWithMatrix(edk::vec3f32( 0.f, 0.f, 1.f)));
    this->vecBack=  edk::Math::normalise(this->multiplyPointWithMatrix(edk::vec3f32( 0.f, 0.f,-1.f)));
    //
    this->positionNear =    (edk::Math::normalise(this->lookAt - this->position) * this->_near) + this->position;
    this->positionFar =     (edk::Math::normalise(this->lookAt - this->position) * this->_far) + this->position;
    //
    this->vecNearUpLeft=    (edk::Math::normalise(this->multiplyPointWithMatrix(edk::vec3f32(-1.f * this->size.width,
                                                                                             1.f  * this->size.height,
                                                                                             0.f)
                                                                                )
                                                  )*this->distancePercent);// + this->positionNear;
    this->vecNearUpRight=   (edk::Math::normalise(this->multiplyPointWithMatrix(edk::vec3f32( 1.f * this->size.width,
                                                                                              1.f * this->size.height,
                                                                                              0.f)
                                                                                )
                                                  )*this->distancePercent);// + this->positionNear;
    this->vecNearDownLeft=  (edk::Math::normalise(this->multiplyPointWithMatrix(edk::vec3f32(-1.f * this->size.width,
                                                                                             -1.f * this->size.height,
                                                                                             0.f)
                                                                                )
                                                  )*this->distancePercent);// + this->positionNear;
    this->vecNearDownRight= (edk::Math::normalise(this->multiplyPointWithMatrix(edk::vec3f32( 1.f  * this->size.width,
                                                                                              -1.f * this->size.height,
                                                                                              0.f)
                                                                                )
                                                  )*this->distancePercent);// + this->positionNear;
    //
    edk::float32 percent = 0.f;
    if(edk::Math::equal(0.f,this->_near)){
        percent = this->_far/(this->_near+0.001f);
    }
    else{
        percent = this->_far/this->_near;
    }
    this->vecFarUpLeft= (this->vecNearUpLeft * percent
                         )+this->positionFar;
    this->vecFarUpRight= (this->vecNearUpRight * percent
                          )+this->positionFar;
    this->vecFarDownLeft= (this->vecNearDownLeft * percent
                           )+this->positionFar;
    this->vecFarDownRight= (this->vecNearDownRight * percent
                            )+this->positionFar;
    //
    this->vecNearUpLeft+=this->positionNear;
    this->vecNearUpRight+=this->positionNear;
    this->vecNearDownLeft+=this->positionNear;
    this->vecNearDownRight+=this->positionNear;
}
//multiply a point to the matrix
edk::vec3f32 edk::Camera3D::multiplyPointWithMatrix(edk::vec3f32 point){
    if(this->matrixPosition.haveMatrix()){
        //
        this->matrixPosition.setIdentity(1.f,0.f);
        this->matrixPosition.set(0u,0u,point.x);
        this->matrixPosition.set(0u,1u,point.y);
        this->matrixPosition.set(0u,2u,point.z);
        this->matrixPosition.set(0u,3u,1.f);

        //multiply the matrix
        this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->lookAtView);

        point.x = this->matrixPosition.getNoIF(0u,0u);
        point.y = this->matrixPosition.getNoIF(0u,1u);
        point.z = this->matrixPosition.getNoIF(0u,2u);

        return point;

        //this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->projection);
        //
        //edk::float32 w_final = this->matrixPosition.getNoIF(0u, 3u);
        //
        //point.x = this->matrixPosition.getNoIF(0u,0u) / w_final;
        //point.y = this->matrixPosition.getNoIF(0u,1u) / w_final;
        //point.z = this->matrixPosition.getNoIF(0u,2u) / w_final;
    }
    return point;
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
    if(edk::Math::equal(0.f,this->size.height)){
        this->sizePercent = this->size.width/(this->size.height+0.001f);
    }
    else{
        this->sizePercent = this->size.width/this->size.height;
    }
    this->distancePercent = edk::Math::pythagoras(this->size.width*0.5f,this->size.height*0.5f);
}
void edk::Camera3D::setSize(edk::float32 sizeW,edk::float32 sizeH){
    //
    return this->setSize(edk::size2f32(sizeW,sizeH));
}
void edk::Camera3D::setSizeW(edk::float32 width){
    this->size.width = width*0.5f;
    if(edk::Math::equal(0.f,this->size.height)){
        this->sizePercent = this->size.width/(this->size.height+0.001f);
    }
    else{
        this->sizePercent = this->size.width/this->size.height;
    }
    this->distancePercent = edk::Math::pythagoras(this->size.width*0.5f,this->size.height*0.5f);
}
void edk::Camera3D::setSizeH(edk::float32 height){
    this->size.height = height*0.5f;
    if(edk::Math::equal(0.f,this->size.height)){
        this->sizePercent = this->size.width/(this->size.height+0.001f);
    }
    else{
        this->sizePercent = this->size.width/this->size.height;
    }
    this->distancePercent = edk::Math::pythagoras(this->size.width*0.5f,this->size.height*0.5f);
}
//return the size
edk::size2f32 edk::Camera3D::getSize(){
    return edk::size2f32(this->size.width * 2.f,this->size.height * 2.f);
}
edk::float32 edk::Camera3D::getWidth(){
    return this->size.width * 2.f;
}
edk::float32 edk::Camera3D::getHeight(){
    return this->size.height * 2.f;
}
edk::float32 edk::Camera3D::getSizePercent(){
    return this->sizePercent;
}
//return the camera rect
edk::rectf32 edk::Camera3D::getRectPositionAndSize(){
    return edk::rectf32(this->position.x,this->position.y,
                        this->size.width*2.f,this->size.height*2.f
                        );
}
edk::rectf32 edk::Camera3D::getRectPoints(){
    return edk::rectf32(this->position.x - (this->size.width),this->position.y - (this->size.height),
                        this->position.x + this->size.width,this->position.y + this->size.height
                        );
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

//zoom the camera
bool edk::Camera3D::runZoomPercent(edk::float32 percent){
    if(percent<0.f){
        if(edk::Math::pythagoras(this->position - this->lookAt) > 0.1f){
            this->position = ((this->position - this->lookAt)*(1.f + percent))+this->lookAt;
            return true;
        }
    }
    else{
        this->position = ((this->position - this->lookAt)*(1.f + percent))+this->lookAt;
        return true;
    }
    return false;
}

//get vectors
edk::vec3f32 edk::Camera3D::getPositionNear(){
    return this->positionNear+this->position;
}
edk::vec3f32 edk::Camera3D::getPositionFar(){
    return this->positionFar+this->position;
}
edk::vec3f32 edk::Camera3D::getPositionLeft(){
    return this->vecLeft+this->position;
}
edk::vec3f32 edk::Camera3D::getPositionRight(){
    return this->vecRight+this->position;
}
edk::vec3f32 edk::Camera3D::getPositionUp(){
    return this->vecUp+this->position;
}
edk::vec3f32 edk::Camera3D::getPositionDown(){
    return this->vecDown+this->position;
}
edk::vec3f32 edk::Camera3D::getPositionNearUpLeft(){
    return this->vecNearUpLeft;
}
edk::vec3f32 edk::Camera3D::getPositionNearUpRight(){
    return this->vecNearUpRight;
}
edk::vec3f32 edk::Camera3D::getPositionNearDownLeft(){
    return this->vecNearDownLeft;
}
edk::vec3f32 edk::Camera3D::getPositionNearDownRight(){
    return this->vecNearDownRight;
}
edk::vec3f32 edk::Camera3D::getPositionFarUpLeft(){
    return this->vecFarUpLeft;
}
edk::vec3f32 edk::Camera3D::getPositionFarUpRight(){
    return this->vecFarUpRight;
}
edk::vec3f32 edk::Camera3D::getPositionFarDownLeft(){
    return this->vecFarDownLeft;
}
edk::vec3f32 edk::Camera3D::getPositionFarDownRight(){
    return this->vecFarDownRight;
}

edk::vec3f32 edk::Camera3D::getUP(){
    return this->up;
}
edk::float32 edk::Camera3D::getUPX(){
    return this->up.x;
}
edk::float32 edk::Camera3D::getUPY(){
    return this->up.y;
}
edk::float32 edk::Camera3D::getUPZ(){
    return this->up.z;
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
        edk::float32 percent = 0.f;
        if(edk::Math::equal(0.f,this->getDistance())){
            percent = distance / (this->getDistance()+0.001f);
        }
        else{
            percent = distance / this->getDistance();
        }
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
bool edk::Camera3D::incrementDistance(edk::float32 distance){
    return this->setDistance(this->getDistance()+distance);
}

//functions to move the camera in his axis
void edk::Camera3D::moveHorizontal(edk::float32 distance){
    //get the right vector
    edk::float32 angle = this->getAngleX();
    edk::vec3f32 right;
    right.x = edk::Math::rotateXAxis(1.f,angle+90.f);
    right.z = edk::Math::rotateYAxis(1.f,angle+90.f);

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
        distanceX = edk::Math::rotateXAxis(distanceY,angleY+90.f);
        up.y = edk::Math::rotateYAxis(distanceY,angleY+90.f) + this->position.z;
        //
        up.x = edk::Math::rotateXAxis(distanceX,angleX) + this->position.x;
        up.z = edk::Math::rotateYAxis(distanceX,angleX) + this->position.z;
    }
    else{
        distanceX = edk::Math::pythagoras(this->position.x - this->lookAt.x,this->position.z - this->lookAt.z);
        distanceY = edk::Math::pythagoras(distanceX,this->position.y - this->lookAt.y);
        //
        distanceX = edk::Math::rotateXAxis(distanceY,angleY+90.f);
        up.y = edk::Math::rotateYAxis(distanceY,angleY+90.f) + this->lookAt.z;
        //
        up.x = edk::Math::rotateXAxis(distanceX,angleX) + this->lookAt.x;
        up.z = edk::Math::rotateYAxis(distanceX,angleX) + this->lookAt.z;
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
        this->lookAt.x = edk::Math::rotateXAxis(distance,angle) + this->position.x;
        this->lookAt.z = edk::Math::rotateYAxis(distance,angle) + this->position.z;
    }
    else{
        edk::float32 distance = edk::Math::pythagoras(this->position.x - this->lookAt.x,this->position.z - this->lookAt.z);
        this->position.x = edk::Math::rotateXAxis(distance,angle) + this->lookAt.x;
        this->position.z = edk::Math::rotateYAxis(distance,angle) + this->lookAt.z;
    }
}
void edk::Camera3D::setAngleY(edk::float32 angle){
    if(this->firstPerson){
        edk::float32 angleX = this->getAngleX();
        edk::float32 distanceX = edk::Math::pythagoras(this->lookAt.x - this->position.x,this->lookAt.z - this->position.z);
        edk::float32 distanceY = edk::Math::pythagoras(distanceX,this->lookAt.y - this->position.y);
        //
        distanceX = edk::Math::rotateXAxis(distanceY,angle);
        this->lookAt.y = edk::Math::rotateYAxis(distanceY,angle) + this->position.y;
        //
        this->lookAt.x = edk::Math::rotateXAxis(distanceX,angleX) + this->position.x;
        this->lookAt.z = edk::Math::rotateYAxis(distanceX,angleX) + this->position.z;
    }
    else{
        edk::float32 angleX = this->getAngleX();
        edk::float32 distanceX = edk::Math::pythagoras(this->position.x - this->lookAt.x,this->position.z - this->lookAt.z);
        edk::float32 distanceY = edk::Math::pythagoras(distanceX,this->position.y - this->lookAt.y);
        //
        distanceX = edk::Math::rotateXAxis(distanceY,angle);
        this->position.y = edk::Math::rotateYAxis(distanceY,angle) + this->lookAt.y;
        //
        this->position.x = edk::Math::rotateXAxis(distanceX,angleX) + this->lookAt.x;
        this->position.z = edk::Math::rotateYAxis(distanceX,angleX) + this->lookAt.z;
    }
}
void edk::Camera3D::setAngleUp(edk::float32 angle){
    this->up.x = edk::Math::rotateXAxis(1.f,angle);
    this->up.y = edk::Math::rotateYAxis(1.f,angle);
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

//get the projection matrix
void edk::Camera3D::updateProjection(){
    this->calculateProjectionMatrix();
    this->calculateLookAtMatrix();
    this->updateVectors();
}
//generate the camera matrix
void edk::Camera3D::calculateProjectionMatrix(){
    if(this->perspective){
        edk::Math::generatePerspectiveMatrix(edk::Math::angleToRad(this->getHeight()),
                                             this->getSizePercent(),
                                             this->getNear(),
                                             this->getFar(),
                                             &this->projection
                                             );
    }
    else{
        edk::Math::generateOrthoMatrix(-this->size.width,
                                       this->size.width,
                                       -this->size.height,
                                       this->size.height,
                                       this->_near,
                                       this->_far,
                                       &this->projection);
    }
}
void edk::Camera3D::calculateLookAtMatrix(){
    this->lookAtView.setIdentity(1.f,0.f);
    edk::Math::generateLookAtMatrixInverse(0.f,0.f,0.f,
                                           this->lookAt.x - this->position.x,
                                           this->lookAt.y - this->position.y,
                                           this->lookAt.z - this->position.z,
                                           this->up.x,this->up.y,this->up.z,
                                           &this->lookAtView
                                           );
}
edk::vector::Matrixf32<4u,4u>* edk::Camera3D::getProjection(){
    return &this->projection;
}
edk::vector::Matrixf32<4u,4u>* edk::Camera3D::getLookAtMatrix(){
    return &this->lookAtView;
}

//draw the camera
void edk::Camera3D::draw(){
    //
    //test if are NOT using GUmodelview
    if(!edk::GU::guUsingMatrix(GU_PROJECTION)){
        //then set to use modelView
        edk::GU::guUseMatrix(GU_PROJECTION);
    }
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
    //update the shaking animations

    //shake angle
    this->animShakeInitAngle.updateClockAnimation(this->secondPassed);

    if(this->runningShakeAngle || this->animShakeInitAngle.isPlaying()){
        this->updateProjection();
        this->shakeAngle = edk::Math::getAngle(edk::vec2f32(this->up.x,this->up.y));
        if(!this->pauseShakeAngle){
            this->secondPercentShake=1.f;
            if(this->animShakeInitAngle.isPlaying()){
                this->secondPercentShake = this->animShakeInitAngle.getClockX();
            }

            this->tempAngle = (edk::Random::getStaticRandPercent() * 180.f);
        }

        //rotate the angle
        edk::vec2f32 newUP = edk::Math::rotatePlus(edk::vec2f32(1.f,0.f),this->shakeAngle
                                                   + (this->tempAngle * this->shakeRandomPercent*this->secondPercentShake));

        //move into the vectors
        if(newUP.x<0.f){
            this->tempUp = ((this->vecLeft)*newUP.x);
        }
        else{
            this->tempUp = ((this->vecRight)*(newUP.x*-1.f));
        }
        if(newUP.y<0.f){
            this->tempUp = ((this->vecUp)*newUP.y)+this->tempUp;
        }
        else{
            this->tempUp = ((this->vecDown)*(newUP.y*-1.f))+this->tempUp;
        }
/*
        this->tempUp.x = newUP.x;
        this->tempUp.y = newUP.y;
        this->tempUp.z = 0.f;
*/
    }
    else{
        this->tempUp = this->up;
    }


    //shake position
    this->animShakeInitPosition.updateClockAnimation(this->secondPassed);

    if(this->runningShakePosition || this->animShakeInitPosition.isPlaying()){
        this->updateProjection();
        if(!this->pauseShakePosition){
            if(this->animShakeInitPosition.isPlaying()){
                this->secondPercentShake = this->animShakeInitPosition.getClockX();
            }
            else{
                this->secondPercentShake=1.f;
            }
            //rotate the angle
            this->shakePosition = edk::Math::rotatePlus(this->shakePosition,180.f + (this->shakeAngle * this->shakeRandomPercent));
        }

        edk::float32 percentX = this->shakePosition.x*this->secondPercentShake;
        edk::float32 percentY = this->shakePosition.y*this->secondPercentShake;

        //move into the vectors
        if(percentX<0.f){
            this->tempPosition = ((this->vecLeft)*percentX)+this->position;
            this->tempLookAt = ((this->vecLeft)*percentX)+this->lookAt;
        }
        else{
            this->tempPosition = ((this->vecRight)*(percentX*-1.f))+this->position;
            this->tempLookAt = ((this->vecRight)*(percentX*-1.f))+this->lookAt;
        }
        if(percentY<0.f){
            this->tempPosition = ((this->vecUp)*percentY)+this->tempPosition;
            this->tempLookAt = ((this->vecUp)*percentY)+this->tempLookAt;
        }
        else{
            this->tempPosition = ((this->vecDown)*(percentY*-1.f))+this->tempPosition;
            this->tempLookAt = ((this->vecDown)*(percentY*-1.f))+this->tempLookAt;
        }

        edk::GU::guLookAt(this->tempPosition.x,this->tempPosition.y,this->tempPosition.z,
                          this->tempLookAt.x,this->tempLookAt.y,this->tempLookAt.z,
                          this->tempUp.x,this->tempUp.y,0.f
                          );

    }
    else{
        edk::GU::guLookAt(this->position.x,this->position.y,this->position.z,
                          this->lookAt.x,this->lookAt.y,this->lookAt.z,
                          this->tempUp.x,this->tempUp.y,0.f
                          );

    }

    this->secondPassed=0.f;
}
void edk::Camera3D::drawAxisOnly(edk::float32 /*seconds*/){
    /*
    //
    //update the shaking animations
    this->animAngleUp.updateClockAnimation(seconds);
    if(this->animAngleUp.isPlaying()){
        //calculate the angle of shaking
        //this->up = edk::Math::rotate(edk::vec2f32(1,0),(((this->getAngleUp() + this->animAngleUp.getClockX())*-1)+360.f)+90);
    }
    else{
        //this->up = edk::Math::rotate(edk::vec2f32(1,0),((this->getAngleUp()*-1)+360.f)+90);
    }

    //shake position
    this->animPosition.updateClockAnimation(seconds);
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
void edk::Camera3D::drawVectors(edk::color3f32 color){
    //draw the two pivo
    edk::GU::guColor3f32(color);
    edk::GU::guBegin(GU_LINES);
    //NEAR END FAR POSITIONS
    edk::GU::guVertex3f32(this->positionNear.x,
                          this->positionNear.y,
                          this->positionNear.z
                          );
    edk::GU::guVertex3f32(this->positionFar.x,
                          this->positionFar.y,
                          this->positionFar.z
                          );

    //nearUpLeftRight
    edk::GU::guVertex3f32(this->vecNearUpLeft.x,
                          this->vecNearUpLeft.y,
                          this->vecNearUpLeft.z
                          );
    edk::GU::guVertex3f32(this->vecNearUpRight.x,
                          this->vecNearUpRight.y,
                          this->vecNearUpRight.z
                          );
    //nearDownLeftRight
    edk::GU::guVertex3f32(this->vecNearDownLeft.x,
                          this->vecNearDownLeft.y,
                          this->vecNearDownLeft.z
                          );
    edk::GU::guVertex3f32(this->vecNearDownRight.x,
                          this->vecNearDownRight.y,
                          this->vecNearDownRight.z
                          );
    //nearUpDownLeft
    edk::GU::guVertex3f32(this->vecNearDownLeft.x,
                          this->vecNearDownLeft.y,
                          this->vecNearDownLeft.z
                          );
    edk::GU::guVertex3f32(this->vecNearUpLeft.x,
                          this->vecNearUpLeft.y,
                          this->vecNearUpLeft.z
                          );
    //nearUpDownRight
    edk::GU::guVertex3f32(this->vecNearDownRight.x,
                          this->vecNearDownRight.y,
                          this->vecNearDownRight.z
                          );
    edk::GU::guVertex3f32(this->vecNearUpRight.x,
                          this->vecNearUpRight.y,
                          this->vecNearUpRight.z
                          );

    //farUpLeftRight
    edk::GU::guVertex3f32(this->vecFarUpLeft.x,
                          this->vecFarUpLeft.y,
                          this->vecFarUpLeft.z
                          );
    edk::GU::guVertex3f32(this->vecFarUpRight.x,
                          this->vecFarUpRight.y,
                          this->vecFarUpRight.z
                          );
    //farDownLeftRight
    edk::GU::guVertex3f32(this->vecFarDownLeft.x,
                          this->vecFarDownLeft.y,
                          this->vecFarDownLeft.z
                          );
    edk::GU::guVertex3f32(this->vecFarDownRight.x,
                          this->vecFarDownRight.y,
                          this->vecFarDownRight.z
                          );
    //farUpDownLeft
    edk::GU::guVertex3f32(this->vecFarDownLeft.x,
                          this->vecFarDownLeft.y,
                          this->vecFarDownLeft.z
                          );
    edk::GU::guVertex3f32(this->vecFarUpLeft.x,
                          this->vecFarUpLeft.y,
                          this->vecFarUpLeft.z
                          );
    //farUpDownRight
    edk::GU::guVertex3f32(this->vecFarDownRight.x,
                          this->vecFarDownRight.y,
                          this->vecFarDownRight.z
                          );
    edk::GU::guVertex3f32(this->vecFarUpRight.x,
                          this->vecFarUpRight.y,
                          this->vecFarUpRight.z
                          );

    //upLeft
    edk::GU::guVertex3f32(this->vecNearUpLeft.x,
                          this->vecNearUpLeft.y,
                          this->vecNearUpLeft.z
                          );
    edk::GU::guVertex3f32(this->vecFarUpLeft.x,
                          this->vecFarUpLeft.y,
                          this->vecFarUpLeft.z
                          );
    //upRight
    edk::GU::guVertex3f32(this->vecNearUpRight.x,
                          this->vecNearUpRight.y,
                          this->vecNearUpRight.z
                          );
    edk::GU::guVertex3f32(this->vecFarUpRight.x,
                          this->vecFarUpRight.y,
                          this->vecFarUpRight.z
                          );
    //downLeft
    edk::GU::guVertex3f32(this->vecNearDownLeft.x,
                          this->vecNearDownLeft.y,
                          this->vecNearDownLeft.z
                          );
    edk::GU::guVertex3f32(this->vecFarDownLeft.x,
                          this->vecFarDownLeft.y,
                          this->vecFarDownLeft.z
                          );
    //downRight
    edk::GU::guVertex3f32(this->vecNearDownRight.x,
                          this->vecNearDownRight.y,
                          this->vecNearDownRight.z
                          );
    edk::GU::guVertex3f32(this->vecFarDownRight.x,
                          this->vecFarDownRight.y,
                          this->vecFarDownRight.z
                          );
    edk::GU::guEnd();
}
void edk::Camera3D::drawVectors(edk::float32 r,edk::float32 g,edk::float32 b){
    return this->drawVectors(edk::color3f32(r,g,b));
}

//pause the animations
void edk::Camera3D::pauseAnim(){
    this->animAngleUp.pause();
    this->animPosition.pause();
    this->animShakeInitPosition.pause();
    this->animShakeInitAngle.pause();
    this->pauseShakePosition=!this->pauseShakePosition;
    this->pauseShakeAngle=!this->pauseShakePosition;
}
void edk::Camera3D::pauseAnimOn(){
    this->animAngleUp.pauseOn();
    this->animPosition.pauseOn();
    this->animShakeInitPosition.pauseOn();
    this->animShakeInitAngle.pauseOn();
    this->pauseShakePosition=true;
    this->pauseShakeAngle=true;
}
void edk::Camera3D::pauseAnimOff(){
    this->animAngleUp.pauseOff();
    this->animPosition.pauseOff();
    this->animShakeInitPosition.pauseOff();
    this->animShakeInitAngle.pauseOff();
    this->pauseShakePosition=false;
    this->pauseShakeAngle=false;
}
bool edk::Camera3D::isPausedAnim(){
    return this->animAngleUp.isPaused();
}
//update all animations
void edk::Camera3D::updateAnimations(){
    this->secondPassed = this->clock.getSeconds();
    this->clock.start();
    this->animPosition.updateClockAnimation(this->secondPassed);
    this->animLookAt.updateClockAnimation(this->secondPassed);
    this->animAngleUp.updateClockAnimation(this->secondPassed);
    if(this->animPosition.isPlaying()){
        this->position.x = this->animPosition.getClockX();
        this->position.y = this->animPosition.getClockY();
    }
    if(this->animAngleUp.isPlaying()){
        this->setAngleUp(this->animAngleUp.getClockX());
    }
}
void edk::Camera3D::updateAnimations(edk::float32 seconds){
    this->animPosition.updateClockAnimation(seconds);
    this->animLookAt.updateClockAnimation(seconds);
    this->animAngleUp.updateClockAnimation(seconds);
    if(this->animPosition.isPlaying()){
        this->position.x = this->animPosition.getClockX();
        this->position.y = this->animPosition.getClockY();
    }
    if(this->animAngleUp.isPlaying()){
        this->setAngleUp(this->animAngleUp.getClockX());
    }
    this->secondPassed = seconds;
    this->clock.start();
}

//start and end shakking
bool edk::Camera3D::startShakeAngle(edk::float32 /*angle*/,
                                    edk::float32 randomPercent,
                                    edk::float32 secondsInit,
                                    edk::float32 interpolationDistance
                                    ){
    this->shakeAngle = edk::Math::getAngle(edk::vec2f32(this->tempUp.x,this->tempUp.y));
    this->shakeInterpolationDistance=interpolationDistance;
    this->shakeRandomPercent=randomPercent;
    this->animShakeInitAngle.clean();
    this->animShakeInitAngle.addFirstInterpolationLine(0.f,0.f,secondsInit,1.f);
    this->animShakeInitAngle.restartForward();
    this->shakeDistance = edk::Math::pythagoras(position);
    if(!this->runningShakeAngle){
        this->runningShakeAngle=true;
        this->pauseShakeAngle=false;
        return true;
    }
    return false;
}
bool edk::Camera3D::stopShakeAngle(edk::float32 secondsEnd){
    //test if are running
    if(this->runningShakeAngle){
        this->runningShakeAngle=false;
        this->pauseShakeAngle=false;
        this->animShakeInitAngle.clean();
        this->animShakeInitAngle.addFirstInterpolationLine(0.f,0.f,secondsEnd,1.f);
        this->animShakeInitAngle.restartRewind();
        /*
        //add a new shake position
        return this->addShakingAngle(this->shakeAngle,
                                     0.9f,
                                     this->shakeInterpolationDistance
                                     );
*/
    }
    return false;
}
bool edk::Camera3D::stopShakeAngle(){
    //test if are running
    if(this->runningShakeAngle){
        this->runningShakeAngle=false;
        this->pauseShakeAngle=false;
        this->animShakeInitAngle.restartRewind();
        return true;
    }
    return false;
}
bool edk::Camera3D::isShakingAngle(){
    return (this->runningShakeAngle || this->animShakeInitAngle.isPlaying() || this->animShakeInitAngle.isPaused());
}
bool edk::Camera3D::isShakingAnglePause(){
    return this->pauseShakeAngle;
}
bool edk::Camera3D::startShakePosition(edk::vec2f32 position,
                                       edk::float32 randomPercent,
                                       edk::float32 secondsInit,
                                       edk::float32 interpolationDistance
                                       ){
    this->shakeAngle = edk::Math::getAngle(position);
    this->shakePosition=position;
    this->shakeRandomPercent=randomPercent;
    this->shakeInterpolationDistance=interpolationDistance;
    this->animShakeInitPosition.clean();
    this->animShakeInitPosition.addFirstInterpolationLine(0.f,0.f,secondsInit,1.f);
    this->animShakeInitPosition.restartForward();
    if(!this->runningShakePosition){
        this->runningShakePosition=true;
        this->pauseShakePosition=false;
        return true;
    }
    return false;
}
bool edk::Camera3D::stopShakePosition(edk::float32 secondsEnd){
    //test if are running
    if(this->runningShakePosition){
        this->runningShakePosition=false;
        this->pauseShakePosition=false;
        this->animShakeInitPosition.clean();
        this->animShakeInitPosition.addFirstInterpolationLine(0.f,0.f,secondsEnd,1.f);
        this->animShakeInitPosition.restartRewind();
        return true;
    }
    return false;
}
bool edk::Camera3D::stopShakePosition(){
    //test if are running
    if(this->runningShakePosition){
        this->runningShakePosition=false;
        this->pauseShakePosition=false;
        this->animShakeInitPosition.restartRewind();
        return true;
    }
    return false;
}
bool edk::Camera3D::isShakingPosition(){
    return (this->runningShakePosition || this->animShakeInitPosition.isPlaying() || this->animShakeInitPosition.isPaused());
}
bool edk::Camera3D::isShakingPositionPause(){
    return this->pauseShakePosition;
}

//operator to copy the cameras
bool edk::Camera3D::cloneFrom(edk::Camera3D* cam){
    if(cam){
        this->position=cam->position;
        this->lookAt=cam->lookAt;
        this->animPosition.cloneFrom(&cam->animPosition);
        this->animLookAt.cloneFrom(&cam->animLookAt);
        this->animAngleUp.cloneFrom(&cam->animAngleUp);
        //
        this->perspective=cam->perspective;
        this->up=cam->up;
        this->size=cam->size;
        this->sizePercent=cam->sizePercent;
        this->distancePercent=cam->distancePercent;
        this->_near=cam->_near;
        this->_far=cam->_far;
        this->firstPerson=cam->firstPerson;
        //
        this->vecLeft=cam->vecLeft;
        this->vecRight=cam->vecRight;
        this->vecUp=cam->vecUp;
        this->vecDown=cam->vecDown;
        this->vecFront=cam->vecFront;
        this->vecBack=cam->vecBack;
        //
        this->positionNear=cam->positionNear;
        this->positionFar=cam->positionFar;
        this->vecNearUpLeft=cam->vecNearUpLeft;
        this->vecNearUpRight=cam->vecNearUpRight;
        this->vecNearDownLeft=cam->vecNearDownLeft;
        this->vecNearDownRight=cam->vecNearDownRight;
        this->vecFarUpLeft=cam->vecFarUpLeft;
        this->vecFarUpRight=cam->vecFarUpRight;
        this->vecFarDownLeft=cam->vecFarDownLeft;
        this->vecFarDownRight=cam->vecFarDownRight;
        //
        this->shakePosition=cam->shakePosition;
        this->shakeAngle=cam->shakeAngle;
        this->shakeDistance=cam->shakeDistance;
        this->runningShakePosition=cam->runningShakePosition;
        this->pauseShakePosition=cam->pauseShakePosition;
        this->runningShakeAngle=cam->runningShakeAngle;
        this->pauseShakeAngle=cam->pauseShakeAngle;
        this->shakeSecondsInit=cam->shakeSecondsInit;
        this->shakeRandomPercent=cam->shakeRandomPercent;
        this->shakeInterpolationDistance=cam->shakeInterpolationDistance;
        this->animShakeInitPosition.cloneFrom(&cam->animShakeInitPosition);
        this->animShakeInitAngle.cloneFrom(&cam->animShakeInitAngle);
        return true;
    }
    return false;
}
