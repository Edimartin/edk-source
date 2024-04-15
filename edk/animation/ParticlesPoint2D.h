#ifndef PARTICLESPOINT2D_H
#define PARTICLESPOINT2D_H

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
#pragma message "Inside ParticlesPoint2D"
#endif

#pragma once
#include "../TypeVars.h"
#include "../Random.h"
#include "../Object2DValues.h"
#include "../Object2D.h"
#include "InterpolationLine3D.h"
#include "../Random.h"
#include "../watch/Time.h"
#include "../vector/BinaryTree.h"

#ifdef printMessages
#pragma message "    Compiling ParticlesPoint2D"
#endif

namespace edk{
namespace animation{
class ParticlesPoint2D : public edk::Object2DValues{
public:
    ParticlesPoint2D();
    ~ParticlesPoint2D();

    void Constructor(bool runFather=true);

    //add objects into the tree
    bool addNewObject(edk::Object2D* obj,edk::float32 angleObject,edk::size2f32 sizeObject);
    //remove an object from the tree
    bool removeObject(edk::Object2D* obj);
    bool deleteObject(edk::Object2D* obj);
    //update the object angle and size
    bool updateObject(edk::Object2D* obj,edk::float32 angleObject,edk::size2f32 sizeObject);
    bool updateObjectAngle(edk::Object2D* obj,edk::float32 angleObject);
    bool updateObjectSize(edk::Object2D* obj,edk::size2f32 sizeObject);
    //clean all objects inside the tree
    void cleanObjects();
    void deleteObjects();

    //angle
    void setAngleNear(edk::float32 _near);
    void setAngleFar(edk::float32 _far);
    void setAngleNearAndFar(edk::float32 _near,edk::float32 _far);
    //TimeLimit
    void setTimeNear(edk::float32 _near);
    void setTimeFar(edk::float32 _far);
    void setTimeNearAndFar(edk::float32 _near,edk::float32 _far);
    //life
    void setLifeNear(edk::float32 near);
    void setLifeFar(edk::float32 far);
    void setLifeNearAndFar(edk::float32 _near,edk::float32 _far);
    //speed
    void setSpeedNear(edk::float32 _near);
    void setSpeedFar(edk::float32 _far);
    void setSpeedNearAndFar(edk::float32 _near,edk::float32 _far);
    //frame
    void setFrameStart(edk::float32 start);
    void setFrameEnd(edk::float32 end);
    void setFrameStartAndEnd(edk::float32 start,edk::float32 end);
    //gravity
    void setGravity(edk::vec2f32 gravity);
    void setGravity(edk::float32 x,edk::float32 y);
    //set the blow
    bool setBlowCount(edk::uint32 blow);
    bool setBlowCountNear(edk::uint32 blowNear);
    bool setBlowCountFar(edk::uint32 blowFar);
    bool setBlowCountNearAndFar(edk::uint32 blowNear,edk::uint32 blowFar);
    //get the angles near and far
    edk::float32 getAngleNear();
    edk::float32 getAngleFar();

    //set angle object as the same angle of the real object
    void setAngleObjectFromObject();
    void setSizeObjectFromObject();
    void setAngleAndSizeObjectFromObject();

    //load particles
    bool loadParticles(edk::uint32 size);
    //clean the particles
    void cleanParticles();

    //player
    void play();
    void pause();
    void pauseOn();
    void pauseOff();
    void pauseParticles();
    void stop();
    void stopAndCleanParticles();
    //return true if is playing
    bool isPlaying();

    void update();
    void update(edk::float32 seconds);
    void draw();
    //draw the pivo
    void drawPivo(edk::float32 size,edk::color3f32 color);
    void drawPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b);
    //draw the angles vector
    virtual void drawAngles(edk::float32 size,edk::color3f32 color);
    virtual void drawAngles(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b);

    bool autoRotate;

    //Object to draw
    edk::Object2D obj;
    edk::float32 angleObject;
    edk::size2f32 sizeObject;

protected:
    //get the position
    virtual edk::vec2f32 newPosition();
    //angles limit
    edk::float32 angleNear,angleFar,angleDistance;
    //speeds
    edk::float32 speedFar,speedNear,speedDistance;
    //frame
    edk::float32 frameStart,frameEnd;
    //gravity
    edk::vec2f32 gravity;
private:
    //save if is playing
    bool isPlayingBlower;
    //particles count to blow
    edk::uint32 blowNear,blowFar;

    //clock
    edk::watch::Time time;
    //time limit to create a new particle
    edk::float32 timeNear,timeFar,timeDistance,timeLimit;
    //life
    edk::float32 lifeNear,lifeFar,lifeDistance;
    //save the last second
    edk::float32 lastSecond;
    edk::float32 saveLastSecond;

    //animated object
    class ParticleObject : public edk::Object2DValues{
    public:
        ParticleObject(edk::Object2D *obj);
        ParticleObject();
        ~ParticleObject();

        void Constructor(edk::Object2D *obj,bool runFather=true);
        void Constructor(bool runFather=true);

        //set the object pointer
        void setObject(edk::Object2D *obj);
        void setGravity(edk::vec2f32* gravity);
        void setAngleObject(edk::float32* angleObj);
        void setSizeObject(edk::size2f32* sizeObj);
        //update animations
        void update(edk::float32 second);
        void draw();
        bool isPlaying();
        bool isPlayingName(const edk::char8* name);
        bool isPlayingName(edk::char8* name);
        bool wasPlayingName(const edk::char8* name);
        bool wasPlayingName(edk::char8* name);
        bool isStoped();
        void play();
        void pause();
        void pauseOn();
        void pauseOff();
        //clean
        void clean();
        //set this
        bool setThis(edk::animation::ParticlesPoint2D* function);
        //animation
        //edk::animation::Interpolation2DGroup animPosition;
        edk::animation::Interpolation1DGroup life;
        edk::float32 lifeLimit;
        edk::vec2f32 direction;
        edk::vec2f32* gravity;
        edk::float32* angleObj;
        edk::size2f32* sizeObj;
        edk::float32 speed;
        //edk::animation::Interpolation2DGroup animSize;
        //edk::animation::Interpolation2DGroup animAngle;
        bool autoRotate;
        //class pointer to update the function
        edk::animation::ParticlesPoint2D* function;
        edk::animation::Interpolation1DGroup animFrame;
        edk::float32 frame;
    private:
        edk::Object2D *obj;
        static edk::vec2f32 gravitySet;
        static edk::float32 angleObject;
        static edk::size2f32 sizeObject;
    private:
        edk::classID classThis;
    };

    //particles vector
    edk::animation::ParticlesPoint2D::ParticleObject* particles;
    edk::uint32 nextParticle;
    edk::uint32 sizeParticles;
    bool isOne;

    //tree with particles on scene
    class TreeParticles: public edk::vector::BinaryTree<edk::animation::ParticlesPoint2D::ParticleObject*>{
    public:
        TreeParticles();
        ~TreeParticles();

        void Constructor(bool runFather=true);
        //render particles
        void renderElement(edk::animation::ParticlesPoint2D::ParticleObject* value);
        //update particles
        void updateElement(edk::animation::ParticlesPoint2D::ParticleObject* value);
        //pause particles
        void printElement(edk::animation::ParticlesPoint2D::ParticleObject* value);

        //update the elements
        void update(){
            this->haveSomeParticle=false;
            edk::vector::BinaryTree<edk::animation::ParticlesPoint2D::ParticleObject*>::update();edkEnd();
        }

        //update the objects
        void updateParticles(edk::float32 second);
        void pauseParticles();
        //return true if have the particles
        bool haveParticles();
    private:
        edk::float32 second;
        bool haveSomeParticle;
        //remove tree
        class treeRemove: public edk::vector::BinaryTree<edk::animation::ParticlesPoint2D::ParticleObject*>{
        public:
            treeRemove(){this->classThis=NULL;this->Constructor(false);}
            ~treeRemove(){
                if(this->classThis==this){
                    this->classThis=NULL;edkEnd();
                    //can destruct the class
                }
            }

            void Constructor(bool runFather=true){
                if(runFather){
                    edk::vector::BinaryTree<edk::animation::ParticlesPoint2D::ParticleObject*>::Constructor();
                }
                if(this->classThis!=this){
                    this->classThis=this;
                }
            }
            //update particles
            void updateElement(edk::animation::ParticlesPoint2D::ParticleObject* value){
                //remove the element from treeTemp
                this->treeTemp->remove(value);edkEnd();
            }
            edk::vector::BinaryTree<edk::animation::ParticlesPoint2D::ParticleObject*>* treeTemp;
        private:
            edk::classID classThis;
        }treeRemove;
    private:
        edk::classID classThis;
    }treeParticles;


    //tree objects
    class ParticleObject2D{
    public:
        ParticleObject2D(edk::Object2D* obj,edk::float32 angleObject,edk::size2f32 sizeObject){
            this->Constructor(obj,angleObject,sizeObject,false);edkEnd();
        }
        ParticleObject2D(){}

        void Constructor(edk::Object2D* obj,edk::float32 angleObject,edk::size2f32 sizeObject,bool runFather=true){
            if(runFather){edkEnd();}
            if(this->classThis==this){
                this->classThis=NULL;edkEnd();
                this->obj=obj;
                this->angleObject=angleObject;
                this->sizeObject=sizeObject;
            }
        }

        //Object to draw
        edk::Object2D* obj;
        edk::float32 angleObject;
        edk::size2f32 sizeObject;
    private:
        edk::classID classThis;
    };
    class TreeObjects2D: public edk::vector::BinaryTree<edk::animation::ParticlesPoint2D::ParticleObject2D*>{
    public:
        TreeObjects2D(){this->classThis=NULL;this->Constructor(false);edkEnd();}
        ~TreeObjects2D(){
            if(this->classThis==this){
                this->classThis=NULL;edkEnd();
                //can destruct the class
                this->cleanObjects();
            }
        }

        void Constructor(bool runFather=true){
            if(runFather){
                edk::vector::BinaryTree<edk::animation::ParticlesPoint2D::ParticleObject2D*>::Constructor();
            }
            if(this->classThis!=this){
                this->classThis=this;

                this->objTemplate.Constructor(NULL,0.f,edk::size2f32(0.f,0.f));edkEnd();
            }
        }
        //compare if the value is bigger
        bool firstBiggerSecond(edk::animation::ParticlesPoint2D::ParticleObject2D* first,edk::animation::ParticlesPoint2D::ParticleObject2D* second){
            if(first->obj>second->obj){
                //
                return true;
            }
            return false;
        }
        //compare if the value is equal
        bool firstEqualSecond(edk::animation::ParticlesPoint2D::ParticleObject2D* first,edk::animation::ParticlesPoint2D::ParticleObject2D* second){
            if(first->obj==second->obj){
                //
                return true;
            }
            return false;
        }
        //clean objects on the tree
        void cleanObjects(){
            edk::uint32 size = this->size();
            edk::animation::ParticlesPoint2D::ParticleObject2D* obj;
            for(edk::uint32 i=0u;i<size;i++){
                obj = this->getElementInPosition(i);
                if(obj){
                    delete obj;
                }
            }
            this->clean();
        }
        bool removeObject(edk::Object2D* obj){
            if(obj){
                edk::animation::ParticlesPoint2D::ParticleObject2D* temp=this->getObject2DByObject(obj);
                if(temp){
                    if(this->remove(temp)){
                        delete temp;
                        return true;
                    }
                }
            }
            return false;
        }
        //add a object into the tree
        bool addNewObject(edk::Object2D* obj,edk::float32 angleObject,edk::size2f32 sizeObject){
            edk::animation::ParticlesPoint2D::ParticleObject2D* temp=this->getObject2DByObject(obj);
            if(!temp){
                temp = new edk::animation::ParticlesPoint2D::ParticleObject2D(obj,angleObject,sizeObject);
                if(temp){
                    if(this->add(temp)){
                        return true;
                    }
                    delete temp;
                }
            }
            else{
                //else just update the object
                temp->angleObject=angleObject;
                temp->sizeObject=sizeObject;
            }
            return false;
        }
        bool updateObject(edk::Object2D* obj,edk::float32 angleObject,edk::size2f32 sizeObject){
            edk::animation::ParticlesPoint2D::ParticleObject2D* temp=this->getObject2DByObject(obj);
            if(temp){
                temp->angleObject = angleObject;
                temp->sizeObject = sizeObject;
                return true;
            }
            return false;
        }
        bool updateObjectAngle(edk::Object2D* obj,edk::float32 angleObject){
            edk::animation::ParticlesPoint2D::ParticleObject2D* temp=this->getObject2DByObject(obj);
            if(temp){
                temp->angleObject = angleObject;
                return true;
            }
            return false;
        }
        bool updateObjectSize(edk::Object2D* obj,edk::size2f32 sizeObject){
            edk::animation::ParticlesPoint2D::ParticleObject2D* temp=this->getObject2DByObject(obj);
            if(temp){
                temp->sizeObject = sizeObject;
                return true;
            }
            return false;
        }
        //get object in a position
        edk::Object2D* getObjectInPosition(edk::uint32 position){
            edk::animation::ParticlesPoint2D::ParticleObject2D* obj = getElementInPosition(position);
            if(obj){
                return obj->obj;
            }
            return NULL;
        }
        edk::Object2D* getObjectInPosition(edk::uint32 position,edk::float32* angleObject,edk::size2f32* sizeObject){
            edk::animation::ParticlesPoint2D::ParticleObject2D* obj = getElementInPosition(position);
            if(obj && angleObject && sizeObject){
                *angleObject = obj->angleObject;
                *sizeObject = obj->sizeObject;
                return obj->obj;
            }
            return NULL;
        }
    private:
        edk::animation::ParticlesPoint2D::ParticleObject2D* getObject2DByObject(edk::Object2D* obj){
            this->objTemplate.obj = obj;
            return this->getElement(&this->objTemplate);
        }
        edk::animation::ParticlesPoint2D::ParticleObject2D objTemplate;
    private:
        edk::classID classThis;
    }treeObjects;

public:
    //update the particle
    virtual void updateParticle(edk::animation::ParticlesPoint2D::ParticleObject* particle);
    //create a frame animation
    virtual void newFrameAnimation(edk::animation::Interpolation1DGroup* animFrame,edk::float32 life);
private:
    edk::classID classThis;
};
}//end namespace animation
}//end namespace edk

#endif // ParticlesPoint2D_H
