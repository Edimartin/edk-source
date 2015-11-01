#include "ParticlesPoint2D.h"

/*
Biblioteca C++ ParticlesPoint2D - Manage a particle system generated in a single point
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
#warning "            Inside ParticlesPoint2D.cpp"
#endif

edk::vec2f32 edk::animation::ParticlesPoint2D::ParticleObject::gravitySet = edk::vec2f32(0,0);
edk::animation::ParticlesPoint2D::ParticleObject::ParticleObject(edk::Object2D *obj){
    //
    this->obj = obj;
    this->direction = edk::vec2f32(0,1);
    this->speed = 1.0f;
    this->setGravity(NULL);
}
edk::animation::ParticlesPoint2D::ParticleObject::ParticleObject(){
    //
    this->obj = NULL;
    this->direction = edk::vec2f32(0,1);
    this->speed = 1.0f;
    this->setGravity(NULL);
}
edk::animation::ParticlesPoint2D::ParticleObject::~ParticleObject(){
    //
}
//set the object pointer
void edk::animation::ParticlesPoint2D::ParticleObject::setObject(edk::Object2D *obj){
    this->obj=obj;
}
void edk::animation::ParticlesPoint2D::ParticleObject::setGravity(edk::vec2f32* gravity){
    if(gravity){
        this->gravity = gravity;
    }
    else{
        this->gravity = &edk::animation::ParticlesPoint2D::ParticleObject::gravitySet;
    }
}

//update animation
void edk::animation::ParticlesPoint2D::ParticleObject::update(edk::float32 second){
    //update animations
    this->life.updateClockAnimation();
    this->animSize.updateClockAnimation();
    this->animAngle.updateClockAnimation();
    edk::float32 temp;
    bool success=false;
    //angle
    temp = this->animSize.getClockX(&success);
    if(success){
        this->size.width = temp;
        temp = this->animSize.getClockY(&success);
        if(success){
            this->size.height = temp;
        }
    }
    //angle
    temp = this->animSize.getClockX(&success);
    if(success){
        this->size.width = temp;
    }

    //update the position
    edk::float32 percent = second * this->speed;
    this->position += (this->direction * percent);
    //update direction
    this->direction+=*this->gravity * percent;
}
void edk::animation::ParticlesPoint2D::ParticleObject::draw(){
    //set the object
    this->obj->position = this->position;
    this->obj->size = this->size;
    this->obj->angle = this->angle;
    //draw the object
    this->obj->draw();
}
bool edk::animation::ParticlesPoint2D::ParticleObject::isPlaying(){
    if(this->life.isPlaying()){
        return true;
    }
    return false;
}
//clean
void edk::animation::ParticlesPoint2D::ParticleObject::clean(){
    this->life.cleanAnimations();
    this->animAngle.cleanAnimations();
    this->animSize.cleanAnimations();
    this->direction = edk::vec2f32(0,1);
    this->speed = 0.1f;
}

edk::animation::ParticlesPoint2D::TreeParticles::TreeParticles(){
    //
    this->treeRemove.treeTemp = this;
}
edk::animation::ParticlesPoint2D::TreeParticles::~TreeParticles(){
    //
}
//render particles
void edk::animation::ParticlesPoint2D::TreeParticles::renderElement(edk::animation::ParticlesPoint2D::ParticleObject* value){
    value->draw();
}
//update particles
void edk::animation::ParticlesPoint2D::TreeParticles::updateElement(edk::animation::ParticlesPoint2D::ParticleObject* value){
    value->update(this->second);

    //test if the value is playing
    if(!value->isPlaying()){
        //add to the remove tree
        this->treeRemove.add(value);
    }
}

//update the objects
void edk::animation::ParticlesPoint2D::TreeParticles::updateParticles(edk::float32 second){
    this->second = second;
    this->update();
    //remove elements
    this->treeRemove.update();
    this->treeRemove.clean();
}

edk::animation::ParticlesPoint2D::ParticlesPoint2D(){
    this->particles=NULL;
    this->nextParticle=0u;
    this->cleanParticles();
    this->setAngleNearAndFar(0.f,0.f);
    this->setSpeedNearAndFar(1.f,1.f);
    this->setTimeNearAndFar(1.f,1.f);
    this->setLifeNearAndFar(1.f,1.f);
    this->gravity = edk::vec2f32(0,0);

    //load the object
    {
        edk::shape::Mesh2D* mesh = this->obj.newMesh();
        if(mesh){
            edk::shape::Rectangle2D rect;
            rect.setPivoToCenter();
            mesh->addPolygon(rect);
            mesh->material.setEmission(1,0,0,1);
        }
    }
    this->time.start();
    this->lastSecond = 0.f;

    this->angle = 0u;
    this->position = edk::vec2f32(0,0);

    //load the rand
    edk::Random::loadSeed();
}
edk::animation::ParticlesPoint2D::~ParticlesPoint2D(){
    //
    this->cleanParticles();
    this->obj.cleanMeshes();
}

//set angles near and far
void edk::animation::ParticlesPoint2D::setAngleNear(edk::float32 near){
    this->setAngleNearAndFar(near,this->angleFar);
}
void edk::animation::ParticlesPoint2D::setAngleFar(edk::float32 far){
    this->setAngleNearAndFar(this->angleNear,far);
}
void edk::animation::ParticlesPoint2D::setAngleNearAndFar(edk::float32 near,edk::float32 far){
    //set the angles
    this->angleNear = near;
    this->angleFar = far;
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
//TimeLimit
void edk::animation::ParticlesPoint2D::setTimeNear(edk::float32 near){
    this->setTimeNearAndFar(near,this->timeFar);
}
void edk::animation::ParticlesPoint2D::setTimeFar(edk::float32 far){
    this->setTimeNearAndFar(this->timeNear,far);
}
void edk::animation::ParticlesPoint2D::setTimeNearAndFar(edk::float32 near,edk::float32 far){
    this->timeNear = near;
    this->timeFar = far;
    this->timeDistance = far - near;
    this->timeLimit = this->timeNear;
}
//LifeLimit
void edk::animation::ParticlesPoint2D::setLifeNear(edk::float32 near){
    this->setLifeNearAndFar(near,this->lifeFar);
}
void edk::animation::ParticlesPoint2D::setLifeFar(edk::float32 far){
    this->setLifeNearAndFar(this->lifeNear,far);
}
void edk::animation::ParticlesPoint2D::setLifeNearAndFar(edk::float32 near,edk::float32 far){
    this->lifeNear = near;
    this->lifeFar = far;
    this->lifeDistance = far - near;
}
//speed
void edk::animation::ParticlesPoint2D::setSpeedNear(edk::float32 near){
    this->setSpeedNearAndFar(near,this->speedFar);
}
void edk::animation::ParticlesPoint2D::setSpeedFar(edk::float32 far){
    this->setSpeedNearAndFar(this->speedNear,far);
}
void edk::animation::ParticlesPoint2D::setSpeedNearAndFar(edk::float32 near,edk::float32 far){
    this->speedNear = near;
    this->speedFar = far;
    this->speedDistance = far - near;
}
//gravity
void edk::animation::ParticlesPoint2D::setGravity(edk::vec2f32 gravity){
    this->gravity = gravity;
}
void edk::animation::ParticlesPoint2D::setGravity(edk::float32 x,edk::float32 y){
    this->setGravity(edk::vec2f32(x,y));
}
//get the angles near and far
edk::float32 edk::animation::ParticlesPoint2D::getAngleNear(){
    return this->angleFar;
}
edk::float32 edk::animation::ParticlesPoint2D::getAngleFar(){
    return this->angleNear;
}

//set object
bool edk::animation::ParticlesPoint2D::setObject(edk::Object2D obj){
    this->obj=obj;
    obj.cantDeleteObject2D();
    return false;
}
//load particles
bool edk::animation::ParticlesPoint2D::loadParticles(edk::uint32 size){
    this->cleanParticles();
    if(size){
        //create the new particles
        this->particles = new edk::animation::ParticlesPoint2D::ParticleObject[size];
        if(this->particles){
            this->size = size;
            //set the objects
            for(register edk::uint32 i = 0u;i<this->size;i++){
                this->particles[i].setObject(&this->obj);
            }
            return true;
        }
    }
    return false;
}
//clean the particles
void edk::animation::ParticlesPoint2D::cleanParticles(){
    if(this->particles){
        delete[] particles;
        this->particles=NULL;
    }
    this->size = 0u;
    this->nextParticle=0u;
}

void edk::animation::ParticlesPoint2D::update(){
    edk::float32 second = (edk::float32)this->time.getMicroseconds() / (edk::float32)edk::watch::second;
    //update the tree
    this->treeParticles.updateParticles(second - this->lastSecond);

    if(second > this->timeLimit){
        //
        this->time.start();
        if(this->nextParticle >= this->size){
            this->nextParticle=0u;
        }
        //clean the particle
        this->particles[this->nextParticle].clean();
        //set the particle life
        this->particles[this->nextParticle].life.addFirstInterpolationLine(0.f,this->lifeNear + (edk::Random::getRandPercent() * this->lifeDistance));
        this->particles[this->nextParticle].life.playForward();
        //set position
        this->particles[this->nextParticle].position = this->position;
        this->particles[this->nextParticle].speed = this->speedNear + (edk::Random::getRandPercent() * this->speedDistance);
        //gravity
        this->particles[this->nextParticle].setGravity(&this->gravity);
        //set direction
        this->particles[this->nextParticle].direction = edk::Math::rotate2f(edk::vec2f32(1,0),this->angleNear + (this->angleDistance * edk::Random::getRandPercent()));
        //add to the tree
        this->treeParticles.add(&this->particles[this->nextParticle]);

        this->nextParticle++;
        this->lastSecond = 0.f;
        this->timeLimit = this->timeNear + (edk::Random::getRandPercent() * this->timeDistance);
    }
    else{
        this->lastSecond = second;
    }
}
void edk::animation::ParticlesPoint2D::draw(){
    this->treeParticles.render();
}
