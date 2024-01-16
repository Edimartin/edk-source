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
    //
    this->obj = obj;edkEnd();
    this->direction = edk::vec2f32(0,1);edkEnd();
    this->speed = 1.0f;edkEnd();
    this->autoRotate = false;edkEnd();
    this->setGravity(NULL);edkEnd();
    this->setAngleObject(NULL);edkEnd();
    this->setSizeObject(NULL);edkEnd();
    this->lifeLimit=0.f;edkEnd();
    this->setThis(NULL);edkEnd();
    this->frame = 0.f;edkEnd();
}
edk::animation::ParticlesPoint2D::ParticleObject::ParticleObject(){
    //
    this->obj = NULL;edkEnd();
    this->direction = edk::vec2f32(0,1);edkEnd();
    this->speed = 1.0f;edkEnd();
    this->autoRotate = false;edkEnd();
    this->setGravity(NULL);edkEnd();
    this->setAngleObject(NULL);edkEnd();
    this->setSizeObject(NULL);edkEnd();
    this->lifeLimit=0.f;edkEnd();
    this->setThis(NULL);edkEnd();
    this->frame = 0.f;edkEnd();
}
edk::animation::ParticlesPoint2D::ParticleObject::~ParticleObject(){
    //
}
//set the object pointer
void edk::animation::ParticlesPoint2D::ParticleObject::setObject(edk::Object2D *obj){
    this->obj=obj;edkEnd();
}
void edk::animation::ParticlesPoint2D::ParticleObject::setGravity(edk::vec2f32* gravity){
    if(gravity){
        this->gravity = gravity;edkEnd();
    }
    else{
        this->gravity = &edk::animation::ParticlesPoint2D::ParticleObject::gravitySet;edkEnd();
    }
}
void edk::animation::ParticlesPoint2D::ParticleObject::setAngleObject(edk::float32* angleObj){
    if(angleObj){
        this->angleObj = angleObj;edkEnd();
    }
    else{
        this->angleObj = &edk::animation::ParticlesPoint2D::ParticleObject::angleObject;edkEnd();
    }
}
void edk::animation::ParticlesPoint2D::ParticleObject::setSizeObject(edk::size2f32* sizeObj){
    if(sizeObj){
        this->sizeObj = sizeObj;edkEnd();
    }
    else{
        this->sizeObj = &edk::animation::ParticlesPoint2D::ParticleObject::sizeObject;edkEnd();
    }
}

//update animation
void edk::animation::ParticlesPoint2D::ParticleObject::update(edk::float32 second){
    //update animations
    this->life.updateClockAnimation(second);edkEnd();
    this->animFrame.updateClockAnimation(second);edkEnd();
    edk::float32 temp;edkEnd();
    //frame
    temp = this->animFrame.getClockX();edkEnd();
    this->frame = temp;edkEnd();
    //update the position
    edk::float32 percent = second * this->speed;edkEnd();
    this->position += (this->direction * percent);edkEnd();
    //update direction
    this->direction+=*this->gravity * percent;edkEnd();

    //rotate the object
    this->angle = (edk::Math::getAngle(this->direction) * this->autoRotate) + *this->angleObj;edkEnd();

    //Run the function
    this->function->updateParticle(this);edkEnd();
}
void edk::animation::ParticlesPoint2D::ParticleObject::draw(){
    //set the object
    this->obj->position = this->position;edkEnd();
    this->obj->size = this->size * *this->sizeObj;edkEnd();
    this->obj->angle = this->angle;edkEnd();
    //set the frame
    {
        edk::shape::Mesh2D* mesh = this->obj->getMesh(0u);edkEnd();
        if(mesh){
            mesh->selectedUsePolygonUVFramePosition(this->frame);edkEnd();
        }
    }
    //draw the object
    this->obj->draw();edkEnd();
}
bool edk::animation::ParticlesPoint2D::ParticleObject::isPlaying(){
    if(this->life.isPlaying()){
        return true;
    }
    return false;
}
bool edk::animation::ParticlesPoint2D::ParticleObject::isPlayingName(const edk::char8* name){
    return this->isPlayingName((edk::char8*) name);edkEnd();
}
bool edk::animation::ParticlesPoint2D::ParticleObject::isPlayingName(edk::char8* name){
    if(this->life.isPlayingName(name)){
        return true;
    }
    return false;
}
bool edk::animation::ParticlesPoint2D::ParticleObject::wasPlayingName(const edk::char8* name){
    return this->wasPlayingName((edk::char8*) name);edkEnd();
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
    this->life.playForward();edkEnd();
    this->animFrame.playForward();edkEnd();
}
void edk::animation::ParticlesPoint2D::ParticleObject::pause(){
    this->life.pause();edkEnd();
    this->animFrame.pause();edkEnd();
}
void edk::animation::ParticlesPoint2D::ParticleObject::pauseOn(){
    this->life.pauseOn();edkEnd();
    this->animFrame.pauseOn();edkEnd();
}
void edk::animation::ParticlesPoint2D::ParticleObject::pauseOff(){
    this->life.pauseOff();edkEnd();
    this->animFrame.pauseOff();edkEnd();
}
//clean
void edk::animation::ParticlesPoint2D::ParticleObject::clean(){
    this->life.cleanAnimations();edkEnd();
    this->animFrame.cleanAnimations();edkEnd();
    //this->animAngle.cleanAnimations();edkEnd();
    //this->animSize.cleanAnimations();edkEnd();
    this->direction = edk::vec2f32(0,1);edkEnd();
    this->speed = 0.1f;edkEnd();
    this->lifeLimit = 0.f;edkEnd();
    this->setThis(NULL);edkEnd();
    this->frame = 0.f;edkEnd();
}
//set this
bool edk::animation::ParticlesPoint2D::ParticleObject::setThis(edk::animation::ParticlesPoint2D* function){
    if(function){
        this->function = function;edkEnd();
        return true;
    }
    this->function = &particlesTemporaryFunctionPointer;edkEnd();
    return false;
}

edk::animation::ParticlesPoint2D::TreeParticles::TreeParticles(){
    //
    this->treeRemove.treeTemp = this;edkEnd();
}
edk::animation::ParticlesPoint2D::TreeParticles::~TreeParticles(){
    //
}
//render particles
void edk::animation::ParticlesPoint2D::TreeParticles::renderElement(edk::animation::ParticlesPoint2D::ParticleObject* value){
    value->draw();edkEnd();
}
//update particles
void edk::animation::ParticlesPoint2D::TreeParticles::updateElement(edk::animation::ParticlesPoint2D::ParticleObject* value){
    //test if is playing
    if(value->isPlaying()){
        //then update
        value->update(this->second);edkEnd();
    }
    else if(value->isStoped()){
        //add to the remove tree
        this->treeRemove.add(value);edkEnd();
    }
}
//pause particles
void edk::animation::ParticlesPoint2D::TreeParticles::printElement(edk::animation::ParticlesPoint2D::ParticleObject* value){
    value->pause();edkEnd();
}

//update the objects
void edk::animation::ParticlesPoint2D::TreeParticles::updateParticles(edk::float32 second){
    this->second = second;edkEnd();
    this->update();edkEnd();
    //remove elements
    this->treeRemove.update();edkEnd();
    this->treeRemove.clean();edkEnd();
}
void edk::animation::ParticlesPoint2D::TreeParticles::pauseParticles(){
    this->print();edkEnd();
}

edk::animation::ParticlesPoint2D::ParticlesPoint2D(){
    this->isOne=false;
    this->blowNear = 1u;edkEnd();
    this->blowFar = 1u;edkEnd();
    this->particles=NULL;edkEnd();
    this->nextParticle=0u;
    this->cleanParticles();edkEnd();
    this->setAngleNearAndFar(0.f,0.f);edkEnd();
    this->setSpeedNearAndFar(1.f,1.f);edkEnd();
    this->setFrameStartAndEnd(0.f,1.f);edkEnd();
    this->setTimeNearAndFar(0.f,0.5f);edkEnd();
    this->setLifeNearAndFar(1.f,2.f);edkEnd();
    this->setGravity(0,0);
    this->isPlayingBlower = false;edkEnd();
    //this->isPlayingParticles = false;edkEnd();

    //load the object
    {
        edk::shape::Mesh2D* mesh = this->obj.newMesh();edkEnd();
        if(mesh){
            edk::shape::Rectangle2D rect;edkEnd();
            rect.setPivoToCenter();edkEnd();
            mesh->addPolygon(rect);edkEnd();
            mesh->material.setEmission(1,1,1,1);edkEnd();
        }
    }
    this->time.start();edkEnd();
    this->lastSecond = 0.f;edkEnd();

    this->angle = 0u;edkEnd();
    this->angleObject=0.f;edkEnd();
    this->sizeObject = edk::size2f32(1,1);edkEnd();
    this->position = edk::vec2f32(0,0);edkEnd();

    //load the rand
    edk::Random::loadStaticSeed();edkEnd();
}
edk::animation::ParticlesPoint2D::~ParticlesPoint2D(){
    //
    this->cleanParticles();edkEnd();
    this->obj.clean();edkEnd();
}
//get the position
edk::vec2f32 edk::animation::ParticlesPoint2D::newPosition(){
    return this->position;edkEnd();
}

//set angles near and far
void edk::animation::ParticlesPoint2D::setAngleNear(edk::float32 _near){
    this->setAngleNearAndFar(_near,this->angleFar);edkEnd();
}
void edk::animation::ParticlesPoint2D::setAngleFar(edk::float32 _far){
    this->setAngleNearAndFar(this->angleNear,_far);edkEnd();
}
void edk::animation::ParticlesPoint2D::setAngleNearAndFar(edk::float32 _near,edk::float32 _far){
    //set the angles
    this->angleNear = _near;edkEnd();
    this->angleFar = _far;edkEnd();
    //filter the angles
    while(this->angleNear>360.f){
        this->angleNear-=360.f;edkEnd();
    }
    while(this->angleNear<0.f){
        this->angleNear+=360.f;edkEnd();
    }
    while(this->angleFar>360.f){
        this->angleFar-=360.f;edkEnd();
    }
    while(this->angleFar<0.f){
        this->angleFar+=360.f;edkEnd();
    }

    //calculate the distance
    if(this->angleNear>this->angleFar){
        this->angleDistance = this->angleFar + this->angleNear - 360.f;edkEnd();
    }
    else{
        //just calculate the distance
        this->angleDistance = this->angleFar - this->angleNear;edkEnd();
    }
}
//TimeLimit
void edk::animation::ParticlesPoint2D::setTimeNear(edk::float32 _near){
    this->setTimeNearAndFar(_near,this->timeFar);edkEnd();
}
void edk::animation::ParticlesPoint2D::setTimeFar(edk::float32 _far){
    this->setTimeNearAndFar(this->timeNear,_far);edkEnd();
}
void edk::animation::ParticlesPoint2D::setTimeNearAndFar(edk::float32 _near,edk::float32 _far){
    this->timeNear = _near;edkEnd();
    this->timeFar = _far;edkEnd();
    this->timeDistance = _far - _near;edkEnd();
    this->timeLimit = this->timeNear;edkEnd();
}
//LifeLimit
void edk::animation::ParticlesPoint2D::setLifeNear(edk::float32 _near){
    this->setLifeNearAndFar(_near,this->lifeFar);edkEnd();
}
void edk::animation::ParticlesPoint2D::setLifeFar(edk::float32 _far){
    this->setLifeNearAndFar(this->lifeNear,_far);edkEnd();
}
void edk::animation::ParticlesPoint2D::setLifeNearAndFar(edk::float32 _near,edk::float32 _far){
    this->lifeNear = _near;edkEnd();
    this->lifeFar = _far;edkEnd();
    this->lifeDistance = _far - _near;edkEnd();
}
//speed
void edk::animation::ParticlesPoint2D::setSpeedNear(edk::float32 _near){
    this->setSpeedNearAndFar(_near,this->speedFar);edkEnd();
}
void edk::animation::ParticlesPoint2D::setSpeedFar(edk::float32 _far){
    this->setSpeedNearAndFar(this->speedNear,_far);edkEnd();
}
void edk::animation::ParticlesPoint2D::setSpeedNearAndFar(edk::float32 _near,edk::float32 _far){
    this->speedNear = _near;edkEnd();
    this->speedFar = _far;edkEnd();
    this->speedDistance = _far - _near;edkEnd();
}
//frame
void edk::animation::ParticlesPoint2D::setFrameStart(edk::float32 start){
    this->setFrameStartAndEnd(start,this->frameStart);edkEnd();
}
void edk::animation::ParticlesPoint2D::setFrameEnd(edk::float32 end){
    this->setFrameStartAndEnd(this->frameEnd,end);edkEnd();
}
void edk::animation::ParticlesPoint2D::setFrameStartAndEnd(edk::float32 start,edk::float32 end){
    this->frameStart = start;edkEnd();
    this->frameEnd = end;edkEnd();
}
//gravity
void edk::animation::ParticlesPoint2D::setGravity(edk::vec2f32 gravity){
    this->gravity = gravity;edkEnd();
}
void edk::animation::ParticlesPoint2D::setGravity(edk::float32 x,edk::float32 y){
    this->setGravity(edk::vec2f32(x,y));edkEnd();
}
//set the blow
bool edk::animation::ParticlesPoint2D::setBlowCount(edk::uint32 blow){
    if(blow){
        this->blowFar = this->blowNear = blow;edkEnd();
        return true;
    }
    this->blowFar = this->blowNear = 1u;edkEnd();
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
    return this->angleFar;edkEnd();
}
edk::float32 edk::animation::ParticlesPoint2D::getAngleFar(){
    return this->angleNear;edkEnd();
}

//set angle object as the same angle of the real object
void edk::animation::ParticlesPoint2D::setAngleObjectAsTheSame(){
    this->angleObject=this->obj.angle;
}

//load particles
bool edk::animation::ParticlesPoint2D::loadParticles(edk::uint32 size){
    this->cleanParticles();edkEnd();
    if(size){
        //create the new particles
        this->particles = new edk::animation::ParticlesPoint2D::ParticleObject[size];edkEnd();
        if(this->particles){
            this->sizeParticles = size;edkEnd();
            //set the objects
            for(register edk::uint32 i = 0u;i<this->sizeParticles;i++){
                this->particles[i].setObject(&this->obj);edkEnd();
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
        this->stop();edkEnd();
        if(this->isOne){
            delete this->particles;edkEnd();
        }
        else{
            delete[] this->particles;edkEnd();
        }
        this->particles=NULL;edkEnd();
    }
    this->sizeParticles = 0u;edkEnd();
    this->nextParticle=0u;
    this->isOne=false;
}

//player
void edk::animation::ParticlesPoint2D::play(){
    //
    this->isPlayingBlower = true;edkEnd();
    this->time.start();edkEnd();
    //this->isPlayingParticles=true;edkEnd();
}
void edk::animation::ParticlesPoint2D::pause(){
    //
    this->isPlayingBlower = !this->isPlayingBlower;edkEnd();
    if(this->isPlayingBlower){
        //this->isPlayingParticles=true;edkEnd();
    }
}
void edk::animation::ParticlesPoint2D::pauseOn(){
    if(!this->isPlayingBlower){
        this->isPlayingBlower=true;edkEnd();
    }
}
void edk::animation::ParticlesPoint2D::pauseOff(){
    if(this->isPlayingBlower){
        this->isPlayingBlower=false;edkEnd();
    }
}

void edk::animation::ParticlesPoint2D::pauseParticles(){
    /*
    if(this->isPlaying){
        this->isPlaying=false;edkEnd();
        this->isPlayingParticles=false;edkEnd();
    }
    else if(!this->runPause){
        this->isPlaying=true;edkEnd();
        this->isPlayingParticles=true;edkEnd();
    }
    else{

        //update particles
        void updateElement(edk::animation::ParticlesPoint2D::ParticleObject* value);edkEnd();        this->isPlayingParticles=!this->isPlayingParticles;edkEnd();
    }
    */
    this->treeParticles.pauseParticles();edkEnd();
}
void edk::animation::ParticlesPoint2D::stop(){
    this->isPlayingBlower = false;edkEnd();
    this->treeParticles.clean();edkEnd();
    //this->isPlayingParticles=false;edkEnd();
}
//return true if is playing
bool edk::animation::ParticlesPoint2D::isPlaying(){
    return this->isPlayingBlower;edkEnd();
}

void edk::animation::ParticlesPoint2D::update(){
    edk::float32 second = (edk::float32)this->time.getMicroseconds() / (edk::float32)edk::watch::second;edkEnd();edkEnd();
    this->update(second);edkEnd();
    this->time.start();edkEnd();
}
void edk::animation::ParticlesPoint2D::update(edk::float32 seconds){
    this->saveLastSecond = this->lastSecond;edkEnd();

    this->lastSecond += seconds;edkEnd();
    if(this->isPlayingBlower && this->particles){
        if(this->lastSecond > this->timeLimit){
            this->lastSecond -= this->timeLimit;edkEnd();
            edk::uint32 blowSize = this->blowNear + ((this->blowFar - this->blowNear) * (edk::Random::getStaticRandPercent()*2.f));
            if(blowSize>this->blowFar){
                blowSize = this->blowFar;
            }

            for(edk::uint32 i=0u;i<blowSize;i++){
                if(this->nextParticle >= this->sizeParticles){
                    this->nextParticle=0u;
                }
                //clean the particle
                this->particles[this->nextParticle].clean();edkEnd();
                //set the particle life
                this->particles[this->nextParticle].lifeLimit = this->lifeNear + (edk::Random::getStaticRandPercent() * this->lifeDistance);edkEnd();
                this->particles[this->nextParticle].life.addFirstInterpolationLine(0.f,this->particles[this->nextParticle].lifeLimit);edkEnd();;
                this->particles[this->nextParticle].life.playForward();edkEnd();
                //set the particle frame animation
                this->newFrameAnimation(&this->particles[this->nextParticle].animFrame,this->particles[this->nextParticle].lifeLimit);edkEnd();
                this->particles[this->nextParticle].animFrame.playForward();edkEnd();
                //set position
                this->particles[this->nextParticle].position = this->newPosition();edkEnd();
                this->particles[this->nextParticle].speed = this->speedNear + (edk::Random::getStaticRandPercent() * this->speedDistance);edkEnd();
                //gravity
                this->particles[this->nextParticle].setGravity(&this->gravity);edkEnd();
                //angleObject
                this->particles[this->nextParticle].setAngleObject(&this->angleObject);edkEnd();
                //sizeObject
                this->particles[this->nextParticle].setSizeObject(&this->sizeObject);edkEnd();
                //set direction
                this->particles[this->nextParticle].direction = edk::Math::rotate(edk::vec2f32(1,0),this->angleNear + (this->angleDistance * edk::Random::getStaticRandPercent()) + this->angle);edkEnd();
                //autorotate
                this->particles[this->nextParticle].autoRotate=this->autoRotate;edkEnd();
                //add to the tree
                this->treeParticles.add(&this->particles[this->nextParticle]);edkEnd();

                this->nextParticle++;edkEnd();
            }
            this->timeLimit = this->timeNear + (edk::Random::getStaticRandPercent() * this->timeDistance);edkEnd();
        }
    }
    else{
        this->lastSecond = 0.f;edkEnd();
    }

    //update the tree
    this->treeParticles.updateParticles(seconds);edkEnd();
}
void edk::animation::ParticlesPoint2D::draw(){
    this->treeParticles.render();edkEnd();
}
//draw the pivo
void edk::animation::ParticlesPoint2D::drawPivo(edk::float32 size,edk::color3f32 color){
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale2f32(edk::size2f32(size,size));edkEnd();

    //lineSize
    edk::GU::guLineWidth(3);edkEnd();

    //set the colors
    edk::GU::guColor3f32(color);edkEnd();
    //draw the lines
    edk::GU::guBegin(GU_LINES);edkEnd();
    //LINE 1
    edk::GU::guVertex2f32(-0.5f,-0.5f);edkEnd();
    edk::GU::guVertex2f32( 0.5f, 0.5f);edkEnd();
    //LINE 2
    edk::GU::guVertex2f32(-0.5f, 0.5f);edkEnd();
    edk::GU::guVertex2f32( 0.5f,-0.5f);edkEnd();
    edk::GU::guEnd();edkEnd();

    //lineSize
    edk::GU::guLineWidth(1);edkEnd();

    //
    edk::GU::guPopMatrix();edkEnd();
}
void edk::animation::ParticlesPoint2D::drawPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    this->drawPivo(size,edk::color3f32(r,g,b));
}
//draw the angles vector
void edk::animation::ParticlesPoint2D::drawAngles(edk::float32 size,edk::color3f32 color){
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add scale
    edk::GU::guScale2f32(edk::size2f32(size,size));edkEnd();

    //lineSize
    edk::GU::guLineWidth(3);edkEnd();

    //set the colors
    edk::GU::guColor3f32(color);edkEnd();
    //draw the lines
    edk::GU::guBegin(GU_LINES);edkEnd();
    //LINE 1
    edk::GU::guVertex2f32(-0.0f,-0.0f);edkEnd();
    edk::GU::guVertex2f32(edk::Math::rotate(edk::vec2f32(1,0),this->angleNear + this->angle));edkEnd();
    //LINE 2
    edk::GU::guVertex2f32(-0.0f,-0.0f);edkEnd();
    edk::GU::guVertex2f32(edk::Math::rotate(edk::vec2f32(1,0),this->angleFar + this->angle));edkEnd();
    edk::GU::guEnd();edkEnd();

    //lineSize
    edk::GU::guLineWidth(1);edkEnd();

    //
    edk::GU::guPopMatrix();edkEnd();
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
    animFrame->addFirstInterpolationLine(0.f,this->frameStart,life,this->frameEnd);edkEnd();
}
