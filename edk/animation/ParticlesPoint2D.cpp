#include "ParticlesPoint2D.h"

/*
Biblioteca C++ ParticlesPoint2D - Manage a particle system generated in a single point
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
#pragma message "            Inside ParticlesPoint2D.cpp"
#endif
edk::animation::ParticlesPoint2D particlesTemporaryFunctionPointer;
edk::vec2f32 edk::animation::ParticlesPoint2D::ParticleObject::gravitySet = edk::vec2f32(0,0);
edk::float32 edk::animation::ParticlesPoint2D::ParticleObject::angleObject = 0.f;
edk::size2f32 edk::animation::ParticlesPoint2D::ParticleObject::sizeObject = edk::size2f32(1,1);
edk::animation::ParticlesPoint2D::ParticleObject::ParticleObject(edk::Object2D *obj){
    this->classThis=NULL;
    this->Constructor(obj);
}
edk::animation::ParticlesPoint2D::ParticleObject::ParticleObject(){
    this->classThis=NULL;
    this->Constructor();
}
edk::animation::ParticlesPoint2D::ParticleObject::~ParticleObject(){
    this->Destructor();
}

void edk::animation::ParticlesPoint2D::ParticleObject::Constructor(edk::Object2D *obj){
    edk::Object2DValues::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->life.Constructor();
        this->animFrame.Constructor();

        this->autoRotate=0.f;
        this->obj = obj;
        this->direction = edk::vec2f32(0,1);
        this->speed = 1.0f;
        this->autoRotate = false;
        this->setGravity(NULL);
        this->setAngleObject(NULL);
        this->setSizeObject(NULL);
        this->lifeLimit=0.f;
        this->setThis(NULL);
        this->frame = 0.f;
    }
}
void edk::animation::ParticlesPoint2D::ParticleObject::Constructor(){
    edk::Object2DValues::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->life.Constructor();
        this->animFrame.Constructor();

        this->autoRotate=0.f;
        this->obj = NULL;
        this->direction = edk::vec2f32(0,1);
        this->speed = 1.0f;
        this->autoRotate = false;
        this->setGravity(NULL);
        this->setAngleObject(NULL);
        this->setSizeObject(NULL);
        this->lifeLimit=0.f;
        this->setThis(NULL);
        this->frame = 0.f;
    }
}
void edk::animation::ParticlesPoint2D::ParticleObject::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
    edk::Object2DValues::Destructor();
}

//set the object pointer
bool edk::animation::ParticlesPoint2D::ParticleObject::setObject(edk::Object2D *obj){
    this->obj=obj;
    if(this->obj){
        return true;
    }
    return false;
}
void edk::animation::ParticlesPoint2D::ParticleObject::setGravity(edk::vec2f32* gravity){
    if(gravity){
        this->gravity = gravity;
    }
    else{
        this->gravity = &edk::animation::ParticlesPoint2D::ParticleObject::gravitySet;
    }
}
void edk::animation::ParticlesPoint2D::ParticleObject::setAngleObject(edk::float32* angleObj){
    if(angleObj){
        this->angleObj = angleObj;
    }
    else{
        this->angleObj = &edk::animation::ParticlesPoint2D::ParticleObject::angleObject;
    }
}
void edk::animation::ParticlesPoint2D::ParticleObject::setSizeObject(edk::size2f32* sizeObj){
    if(sizeObj){
        this->sizeObj = sizeObj;
    }
    else{
        this->sizeObj = &edk::animation::ParticlesPoint2D::ParticleObject::sizeObject;
    }
}

//update animation
void edk::animation::ParticlesPoint2D::ParticleObject::update(edk::float32 second){
    //update animations
    this->life.updateClockAnimation(second);
    this->animFrame.updateClockAnimation(second);
    edk::float32 temp;
    //frame
    temp = this->animFrame.getClockX();
    this->frame = temp;
    //update the position
    edk::float32 percent = second * this->speed;
    this->position += (this->direction * percent);
    //update direction
    this->direction+=*this->gravity * percent;

    //rotate the object
    if(this->autoRotate){
        this->angle = edk::Math::getAngle(this->direction) + *this->angleObj;
    }

    //Run the function
    this->function->updateParticle(this);
}
void edk::animation::ParticlesPoint2D::ParticleObject::draw(){
    //set the object
    this->obj->position = this->position;
    this->obj->size = this->size * *this->sizeObj;
    this->obj->angle = this->angle;
    //set the frame
    {
        edk::shape::Mesh2D* mesh = this->obj->getMesh(0u);
        if(mesh){
            mesh->selectedUsePolygonUVFramePosition(this->frame);
        }
    }
    //draw the object
    this->obj->draw();
}
bool edk::animation::ParticlesPoint2D::ParticleObject::isPlaying(){
    if(this->life.isPlaying()){
        return true;
    }
    return false;
}
bool edk::animation::ParticlesPoint2D::ParticleObject::isPlayingName(const edk::char8* name){
    return this->isPlayingName((edk::char8*) name);
}
bool edk::animation::ParticlesPoint2D::ParticleObject::isPlayingName(edk::char8* name){
    if(this->life.isPlayingName(name)){
        return true;
    }
    return false;
}
bool edk::animation::ParticlesPoint2D::ParticleObject::wasPlayingName(const edk::char8* name){
    return this->wasPlayingName((edk::char8*) name);
}
bool edk::animation::ParticlesPoint2D::ParticleObject::wasPlayingName(edk::char8* name){
    if(this->life.wasPlayingName(name)){
        return true;
    }
    return false;
}
bool edk::animation::ParticlesPoint2D::ParticleObject::isStoped(){
    if(!this->life.isPlaying() && !this->life.isPaused()){
        return true;
    }
    return false;
}
void edk::animation::ParticlesPoint2D::ParticleObject::play(){
    this->life.playForward();
    this->animFrame.playForward();
}
void edk::animation::ParticlesPoint2D::ParticleObject::pause(){
    this->life.pause();
    this->animFrame.pause();
}
void edk::animation::ParticlesPoint2D::ParticleObject::pauseOn(){
    this->life.pauseOn();
    this->animFrame.pauseOn();
}
void edk::animation::ParticlesPoint2D::ParticleObject::pauseOff(){
    this->life.pauseOff();
    this->animFrame.pauseOff();
}
//clean
void edk::animation::ParticlesPoint2D::ParticleObject::clean(){
    this->life.cleanAnimations();
    this->animFrame.cleanAnimations();
    //this->animAngle.cleanAnimations();
    //this->animSize.cleanAnimations();
    this->direction = edk::vec2f32(0,1);
    this->speed = 0.1f;
    this->lifeLimit = 0.f;
    this->setThis(NULL);
    this->frame = 0.f;
}
//set this
bool edk::animation::ParticlesPoint2D::ParticleObject::setThis(edk::animation::ParticlesPoint2D* function){
    if(function){
        this->function = function;
        return true;
    }
    this->function = &particlesTemporaryFunctionPointer;
    return false;
}

edk::animation::ParticlesPoint2D::TreeParticles::TreeParticles(){
    this->classThis=NULL;
    this->Constructor();
}
edk::animation::ParticlesPoint2D::TreeParticles::~TreeParticles(){
}

void edk::animation::ParticlesPoint2D::TreeParticles::Constructor(){
    edk::vector::BinaryTree<edk::animation::ParticlesPoint2D::ParticleObject*>::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->treeRemove.Constructor();

        this->treeRemove.treeTemp = this;
        this->haveSomeParticle=false;
    }
}
void edk::animation::ParticlesPoint2D::TreeParticles::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
    edk::vector::BinaryTree<edk::animation::ParticlesPoint2D::ParticleObject*>::Destructor();
}

//render particles
void edk::animation::ParticlesPoint2D::TreeParticles::renderElement(edk::animation::ParticlesPoint2D::ParticleObject* value){
    value->draw();
}
//update particles
void edk::animation::ParticlesPoint2D::TreeParticles::updateElement(edk::animation::ParticlesPoint2D::ParticleObject* value){
    //test if is playing
    if(value->isPlaying()){
        //then update
        value->update(this->second);
        this->haveSomeParticle=true;
    }
    else if(value->isStoped()){
        //add to the remove tree
        this->treeRemove.add(value);
    }
}
//pause particles
void edk::animation::ParticlesPoint2D::TreeParticles::printElement(edk::animation::ParticlesPoint2D::ParticleObject* value){
    value->pause();
}

//update the objects
void edk::animation::ParticlesPoint2D::TreeParticles::updateParticles(edk::float32 second){
    this->second = second;
    this->update();
    //remove elements
    this->treeRemove.update();
    this->treeRemove.clean();
}
void edk::animation::ParticlesPoint2D::TreeParticles::pauseParticles(){
    this->print();
}
//return true if have the particles
bool edk::animation::ParticlesPoint2D::TreeParticles::haveParticles(){
    return this->haveSomeParticle;
}

edk::animation::ParticlesPoint2D::ParticlesPoint2D(){
    this->classThis=NULL;
    this->Constructor();
}
edk::animation::ParticlesPoint2D::~ParticlesPoint2D(){
    this->Destructor();
}

void edk::animation::ParticlesPoint2D::Constructor(){
    edk::Object2DValues::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        //Object to draw
        this->obj.Constructor();
        this->time.Constructor();
        this->treeParticles.Constructor();
        this->treeObjects.Constructor();

        this->isOne=false;
        this->blowNear = 1u;
        this->blowFar = 1u;
        this->particles=NULL;
        this->nextParticle=0u;
        this->cleanParticles();
        this->setAngleNearAndFar(0.f,0.f);
        this->setSpeedNearAndFar(1.f,1.f);
        this->setFrameStartAndEnd(0.f,1.f);
        this->setTimeNearAndFar(0.f,0.5f);
        this->setLifeNearAndFar(1.f,2.f);
        this->setGravity(0,0);
        this->isPlayingBlower = false;
        //this->isPlayingParticles = false;

        //load the object
        {
            edk::shape::Mesh2D* mesh = this->obj.newMesh();
            if(mesh){
                edk::shape::Rectangle2D rect;
                rect.setPivoToCenter();
                mesh->addPolygon(rect);
                mesh->material.setEmission(1,1,1,1);
            }
        }
        this->time.start();
        this->lastSecond = 0.f;

        this->angle = 0u;
        this->angleObject=0.f;
        this->sizeObject = edk::size2f32(1,1);
        this->position = edk::vec2f32(0,0);

        //load the rand
        this->rand.loadSeed();
    }
}
void edk::animation::ParticlesPoint2D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->cleanParticles();
        this->obj.clean();
    }
    edk::Object2DValues::Destructor();
}

//get the position
edk::vec2f32 edk::animation::ParticlesPoint2D::newPosition(){
    return this->position;
}

void edk::animation::ParticlesPoint2D::clean(){
    this->stopAndCleanParticles();
    this->cleanObjects();
}

//add objects into the tree
bool edk::animation::ParticlesPoint2D::addObject(edk::Object2D* obj,edk::float32 angleObject,edk::size2f32 sizeObject){
    return this->treeObjects.addNewObject(obj,angleObject,sizeObject);
}
bool edk::animation::ParticlesPoint2D::addObject(edk::Object2D* obj){
    return this->treeObjects.addNewObject(obj,obj->angle,obj->size);
}
//add a new object to be cloned
bool edk::animation::ParticlesPoint2D::addNewObject(edk::Object2D* obj,edk::float32 angleObject,edk::size2f32 sizeObject){
    return this->treeObjects.addCloneObject(obj,angleObject,sizeObject);
}
bool edk::animation::ParticlesPoint2D::addNewObject(edk::Object2D* obj){
    return this->treeObjects.addCloneObject(obj,obj->angle,obj->size);
}
//remove an object from the tree
bool edk::animation::ParticlesPoint2D::removeObject(edk::Object2D* obj){
    return this->treeObjects.removeObject(obj);
}
bool edk::animation::ParticlesPoint2D::deleteObject(edk::Object2D* obj){
    if(obj){
        if(this->removeObject(obj)){
            delete obj;
        }
    }
    return false;
}
//update the object angle and size
bool edk::animation::ParticlesPoint2D::updateObject(edk::Object2D* obj,edk::float32 angleObject,edk::size2f32 sizeObject){
    return this->treeObjects.updateObject(obj,angleObject,sizeObject);
}
bool edk::animation::ParticlesPoint2D::updateObjectAngle(edk::Object2D* obj,edk::float32 angleObject){
    return this->treeObjects.updateObjectAngle(obj,angleObject);
}
bool edk::animation::ParticlesPoint2D::updateObjectSize(edk::Object2D* obj,edk::size2f32 sizeObject){
    return this->treeObjects.updateObjectSize(obj,sizeObject);
}
//clean all objects inside the tree
void edk::animation::ParticlesPoint2D::cleanObjects(){
    this->treeObjects.cleanObjects();
}
void edk::animation::ParticlesPoint2D::deleteObjects(){
    this->cleanParticles();
    edk::uint32 size = this->treeObjects.size();
    edk::Object2D* obj=NULL;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->treeObjects.getObjectInPosition(i);
        if(obj){
            delete obj;
        }
    }
    this->treeObjects.clean();
}

//set angles near and far
void edk::animation::ParticlesPoint2D::setAngleNear(edk::float32 _near){
    this->setAngleNearAndFar(_near,this->angleFar);
}
void edk::animation::ParticlesPoint2D::setAngleFar(edk::float32 _far){
    this->setAngleNearAndFar(this->angleNear,_far);
}
void edk::animation::ParticlesPoint2D::setAngleNearAndFar(edk::float32 _near,edk::float32 _far){
    //set the angles
    this->angleNear = _near;
    this->angleFar = _far;
    //filter the angles
    while(this->angleNear>360.f){
        this->angleNear-=360.f;
    }
    while(this->angleNear<0.f){
        this->angleNear+=360.f;
    }
    while(this->angleFar>360.f){
        this->angleFar-=360.f;
    }
    while(this->angleFar<0.f){
        this->angleFar+=360.f;
    }

    //calculate the distance
    if(this->angleNear>this->angleFar){
        this->angleDistance = this->angleFar + this->angleNear - 360.f;
    }
    else{
        //just calculate the distance
        this->angleDistance = this->angleFar - this->angleNear;
    }
}
void edk::animation::ParticlesPoint2D::setAngleNearAndFar(edk::float32 angle){
    this->setAngleNearAndFar(angle,angle);
}
//TimeLimit
void edk::animation::ParticlesPoint2D::setTimeNear(edk::float32 _near){
    this->setTimeNearAndFar(_near,this->timeFar);
}
void edk::animation::ParticlesPoint2D::setTimeFar(edk::float32 _far){
    this->setTimeNearAndFar(this->timeNear,_far);
}
void edk::animation::ParticlesPoint2D::setTimeNearAndFar(edk::float32 _near,edk::float32 _far){
    this->timeNear = _near;
    this->timeFar = _far;
    this->timeDistance = _far - _near;
    this->timeLimit = this->timeNear;
}
//LifeLimit
void edk::animation::ParticlesPoint2D::setLifeNear(edk::float32 _near){
    this->setLifeNearAndFar(_near,this->lifeFar);
}
void edk::animation::ParticlesPoint2D::setLifeFar(edk::float32 _far){
    this->setLifeNearAndFar(this->lifeNear,_far);
}
void edk::animation::ParticlesPoint2D::setLifeNearAndFar(edk::float32 _near,edk::float32 _far){
    this->lifeNear = _near;
    this->lifeFar = _far;
    this->lifeDistance = _far - _near;
}
void edk::animation::ParticlesPoint2D::setLifeNearAndFar(edk::float32 seconds){
    return this->setLifeNearAndFar(seconds,seconds);
}
//speed
void edk::animation::ParticlesPoint2D::setSpeedNear(edk::float32 _near){
    this->setSpeedNearAndFar(_near,this->speedFar);
}
void edk::animation::ParticlesPoint2D::setSpeedFar(edk::float32 _far){
    this->setSpeedNearAndFar(this->speedNear,_far);
}
void edk::animation::ParticlesPoint2D::setSpeedNearAndFar(edk::float32 _near,edk::float32 _far){
    this->speedNear = _near;
    this->speedFar = _far;
    this->speedDistance = _far - _near;
}
void edk::animation::ParticlesPoint2D::setSpeedNearAndFar(edk::float32 speed){
    this->setSpeedNearAndFar(speed,speed);
}
//frame
void edk::animation::ParticlesPoint2D::setFrameStart(edk::float32 start){
    this->setFrameStartAndEnd(start,this->frameStart);
}
void edk::animation::ParticlesPoint2D::setFrameEnd(edk::float32 end){
    this->setFrameStartAndEnd(this->frameEnd,end);
}
void edk::animation::ParticlesPoint2D::setFrameStartAndEnd(edk::float32 start,edk::float32 end){
    this->frameStart = start;
    this->frameEnd = end;
}
//gravity
void edk::animation::ParticlesPoint2D::setGravity(edk::vec2f32 gravity){
    this->gravity = gravity;
}
void edk::animation::ParticlesPoint2D::setGravity(edk::float32 x,edk::float32 y){
    this->setGravity(edk::vec2f32(x,y));
}
//set the blow
bool edk::animation::ParticlesPoint2D::setBlowCount(edk::uint32 blow){
    if(blow){
        this->blowFar = this->blowNear = blow;
        return true;
    }
    this->blowFar = this->blowNear = 1u;
    return false;
}
bool edk::animation::ParticlesPoint2D::setBlowCountNear(edk::uint32 blowNear){
    if(blowNear){
        this->blowNear = blowNear;
        if(this->blowFar<this->blowNear){
            this->blowFar=this->blowNear;
        }
        return true;
    }
    this->blowNear = 1u;
    if(this->blowFar<this->blowNear){
        this->blowFar=this->blowNear;
    }
    return false;
}
bool edk::animation::ParticlesPoint2D::setBlowCountFar(edk::uint32 blowFar){
    if(blowFar){
        this->blowFar=blowFar;
        if(this->blowNear>this->blowFar){
            this->blowNear=this->blowFar;
        }
        return true;
    }
    this->blowFar=1u;
    if(this->blowNear>this->blowFar){
        this->blowNear=this->blowFar;
    }
    return false;
}
bool edk::animation::ParticlesPoint2D::setBlowCountNearAndFar(edk::uint32 blowNear,edk::uint32 blowFar){
    if(blowNear && blowFar){
        this->setBlowCountNear(blowNear);
        this->setBlowCountFar(blowFar);
        return true;
    }
    this->setBlowCountNear(1u);
    this->setBlowCountFar(1u);
    return false;
}
//get the angles near and far
edk::float32 edk::animation::ParticlesPoint2D::getAngleNear(){
    return this->angleFar;
}
edk::float32 edk::animation::ParticlesPoint2D::getAngleFar(){
    return this->angleNear;
}

//set angle object as the same angle of the real object
void edk::animation::ParticlesPoint2D::setAngleObjectFromObject(){
    this->angleObject=this->obj.angle;
}
void edk::animation::ParticlesPoint2D::setSizeObjectFromObject(){
    this->sizeObject=this->obj.size;
}
void edk::animation::ParticlesPoint2D::setAngleAndSizeObjectFromObject(){
    this->setAngleObjectFromObject();
    this->setSizeObjectFromObject();
}

//load particles
bool edk::animation::ParticlesPoint2D::loadParticles(edk::uint32 size){
    this->cleanParticles();
    this->treeObjects.removeObject(&this->obj);
    if(size){
        if(!this->treeObjects.size()){
            //add the object into the treeObjects
            this->treeObjects.addNewObject(&this->obj,this->angleObject,this->sizeObject);
        }
        //create the new particles
        this->particles = new edk::animation::ParticlesPoint2D::ParticleObject[size];
        if(this->particles){
            edk::Object2D* temp;
            edk::uint32 sizeObjects = this->treeObjects.size();
            edk::uint32 positionObject=0u;
            this->sizeParticles = size;
            edk::float32 angleObject;edk::size2f32 sizeObject;
            //set the objects
#if defined(edkCPPversion17)
            for(edk::uint32 i = 0u;i<this->sizeParticles;i++){
#else
            for(register edk::uint32 i = 0u;i<this->sizeParticles;i++){
#endif
                temp = this->treeObjects.getObjectInPosition(positionObject,&angleObject,&sizeObject);
                if(temp){
                    this->particles[i].setObject(temp);
                    this->particles[i].size = sizeObject;
                    this->particles[i].angle = angleObject;
                }
                else{
                    this->particles[i].setObject(&this->obj);
                }
                positionObject++;
                if(positionObject>=sizeObjects){
                    positionObject=0u;
                }
            }
            if(this->sizeParticles==1u){
                this->isOne=true;
            }
            return true;
        }
    }
    return false;
}
//clean the particles
void edk::animation::ParticlesPoint2D::cleanParticles(){
    if(this->particles){
        this->stop();
        if(this->isOne){
            delete this->particles;
        }
        else{
            delete[] this->particles;
        }
        this->particles=NULL;
    }
    this->sizeParticles = 0u;
    this->nextParticle=0u;
    this->isOne=false;
}

//player
void edk::animation::ParticlesPoint2D::play(){
    //
    if(!this->isPlaying()){
        this->isPlayingBlower = true;
        this->time.start();
        this->lastSecond = this->timeLimit;
    }
}
void edk::animation::ParticlesPoint2D::pause(){
    //
    this->isPlayingBlower = !this->isPlayingBlower;
    /*
    if(this->isPlayingBlower){
        //this->isPlayingParticles=true;
    }
    */
}
void edk::animation::ParticlesPoint2D::pauseOn(){
    if(!this->isPlayingBlower){
        this->isPlayingBlower=true;
    }
}
void edk::animation::ParticlesPoint2D::pauseOff(){
    if(this->isPlayingBlower){
        this->isPlayingBlower=false;
    }
}

void edk::animation::ParticlesPoint2D::pauseParticles(){
    /*
    if(this->isPlaying){
        this->isPlaying=false;
        this->isPlayingParticles=false;
    }
    else if(!this->runPause){
        this->isPlaying=true;
        this->isPlayingParticles=true;
    }
    else{

        //update particles
        void updateElement(edk::animation::ParticlesPoint2D::ParticleObject* value);         this->isPlayingParticles=!this->isPlayingParticles;
    }
    */
    this->treeParticles.pauseParticles();
}
void edk::animation::ParticlesPoint2D::stop(){
    if(this->isPlaying()){
        this->isPlayingBlower = false;
    }
}
void edk::animation::ParticlesPoint2D::stopAndCleanParticles(){
    this->stop();
    this->treeParticles.clean();
}
//return true if is playing
bool edk::animation::ParticlesPoint2D::isPlaying(){
    return this->isPlayingBlower;
}

void edk::animation::ParticlesPoint2D::update(){
    edk::float32 second = (edk::float32)this->time.getMicroseconds() / (edk::float32)edk::watch::second;
    this->update(second);
    this->time.start();
}
void edk::animation::ParticlesPoint2D::update(edk::float32 seconds){
    this->saveLastSecond = this->lastSecond;

    this->lastSecond += seconds;
    if(this->isPlayingBlower && this->particles){
        if(this->lastSecond > this->timeLimit){
            this->lastSecond -= this->timeLimit;
            edk::uint32 blowSize = this->blowNear + ((this->blowFar - this->blowNear) * (this->rand.getRandPercent()*2.f));
            if(blowSize>this->blowFar){
                blowSize = this->blowFar;
            }

            for(edk::uint32 i=0u;i<blowSize;i++){
                if(this->nextParticle >= this->sizeParticles){
                    this->nextParticle=0u;
                }
                //clean the particle
                this->particles[this->nextParticle].clean();
                //set the particle life
                this->particles[this->nextParticle].lifeLimit = this->lifeNear + (this->rand.getRandPercent() * this->lifeDistance);
                this->particles[this->nextParticle].life.addFirstInterpolationLine(0.f,this->particles[this->nextParticle].lifeLimit); ;
                this->particles[this->nextParticle].life.playForward();
                //set the particle frame animation
                this->newFrameAnimation(&this->particles[this->nextParticle].animFrame,this->particles[this->nextParticle].lifeLimit);
                this->particles[this->nextParticle].animFrame.playForward();
                //set position
                this->particles[this->nextParticle].position = this->newPosition();
                this->particles[this->nextParticle].speed = this->speedNear + (this->rand.getRandPercent() * this->speedDistance);
                //gravity
                this->particles[this->nextParticle].setGravity(&this->gravity);
                //angleObject
                this->particles[this->nextParticle].setAngleObject(&this->angleObject);
                //sizeObject
                this->particles[this->nextParticle].setSizeObject(&this->sizeObject);
                //set direction
                this->particles[this->nextParticle].direction = edk::Math::rotate(edk::vec2f32(1,0),this->angleNear + (this->angleDistance * this->rand.getRandPercent()) + this->angle);
                //autorotate
                this->particles[this->nextParticle].autoRotate=this->autoRotate;
                //add to the tree
                this->treeParticles.add(&this->particles[this->nextParticle]);

                this->nextParticle++;
            }
            this->timeLimit = this->timeNear + (this->rand.getRandPercent() * this->timeDistance);
        }
    }
    else{
        this->lastSecond = 0.f;
    }

    //update the tree
    this->treeParticles.updateParticles(seconds);
    if(!this->treeParticles.haveParticles()){
        this->treeParticles.clean();
    }
}
void edk::animation::ParticlesPoint2D::draw(){
    this->treeParticles.render();
}
//draw the pivo
void edk::animation::ParticlesPoint2D::drawPivo(edk::float32 size,edk::color3f32 color){
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
void edk::animation::ParticlesPoint2D::drawPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    this->drawPivo(size,edk::color3f32(r,g,b));
}
//draw the angles vector
void edk::animation::ParticlesPoint2D::drawAngles(edk::float32 size,edk::color3f32 color){
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
    edk::GU::guVertex2f32(-0.0f,-0.0f);
    edk::GU::guVertex2f32(edk::Math::rotate(edk::vec2f32(1,0),this->angleNear + this->angle));
    //LINE 2
    edk::GU::guVertex2f32(-0.0f,-0.0f);
    edk::GU::guVertex2f32(edk::Math::rotate(edk::vec2f32(1,0),this->angleFar + this->angle));
    edk::GU::guEnd();

    //lineSize
    edk::GU::guLineWidth(1);

    //
    edk::GU::guPopMatrix();
}
void edk::animation::ParticlesPoint2D::drawAngles(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    return this->drawAngles(size,edk::color3f32(r,g,b));
}
//update the particle
void edk::animation::ParticlesPoint2D::updateParticle(edk::animation::ParticlesPoint2D::ParticleObject*){
    //
}
//create a frame animation
void edk::animation::ParticlesPoint2D::newFrameAnimation(edk::animation::Interpolation1DGroup* animFrame,edk::float32 life){
    animFrame->addFirstInterpolationLine(0.f,this->frameStart,life,this->frameEnd);
}
