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
        //render particles
        void renderElement(edk::animation::ParticlesPoint2D::ParticleObject* value);
        //update particles
        void updateElement(edk::animation::ParticlesPoint2D::ParticleObject* value);
        //pause particles
        void printElement(edk::animation::ParticlesPoint2D::ParticleObject* value);

        //update the objects
        void updateParticles(edk::float32 second);
        void pauseParticles();
    private:
        edk::float32 second;
        //remove tree
        class treeRemove: public edk::vector::BinaryTree<edk::animation::ParticlesPoint2D::ParticleObject*>{
        public:
            treeRemove(){}
            ~treeRemove(){}
            //update particles
            void updateElement(edk::animation::ParticlesPoint2D::ParticleObject* value){
                //remove the element from treeTemp
                this->treeTemp->remove(value);edkEnd();
            }
            edk::vector::BinaryTree<edk::animation::ParticlesPoint2D::ParticleObject*>* treeTemp;
        }treeRemove;
    }treeParticles;

public:
    //update the particle
    virtual void updateParticle(edk::animation::ParticlesPoint2D::ParticleObject* particle);
    //create a frame animation
    virtual void newFrameAnimation(edk::animation::Interpolation1DGroup* animFrame,edk::float32 life);
};
}//end namespace animation
}//end namespace edk

#endif // ParticlesPoint2D_H
