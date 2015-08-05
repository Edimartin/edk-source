#include "AnimatedPolygon2DList.h"

/*
Library AnimatedPolygon2DList - Add animation to 2D Polygons in EDK Game Engine
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

edk::shape::AnimatedPolygon2DList::AnimatedPolygon2DList()
{
    this->freeSelectedAnimation();
    this->selectedID=0u;
}
edk::shape::AnimatedPolygon2DList::~AnimatedPolygon2DList()
{
}

//ANIMATIONS
//create a new animation in a polygon
bool edk::shape::AnimatedPolygon2DList::newAnimationFramesToPolygon(edk::uint32 position){
    //test if have the polygon
    if(this->polygons.havePos(position)){
        //select the polygon
        edk::shape::Polygon2D* temp = this->polygons[position];
        //test if have selected some polygon
        if(temp){
            //then add a new animation
            return temp->framesCreateAnimation();
        }
    }
    //else return false
    return false;
}
//copy an animation to another polygon
bool edk::shape::AnimatedPolygon2DList::copyAnimationFramesToPolygon(edk::uint32 position,edk::uint32 dest){
    //test if have the 2 polygons
    if(this->polygons.havePos(position)
            &&
            this->polygons.havePos(dest)){
        //select the polygon
        edk::shape::Polygon2D* temp1 = this->polygons[position];
        edk::shape::Polygon2D* temp2 = this->polygons[dest];
        //test if have selected some polygon
        if(temp1 && temp2){
            //then copy the animation from temp1 to temp2
            return temp2->framesSetAnimation(temp1->framesGetAnimation());
        }
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon2DList::copyThisAnimationFramesToPolygon(edk::animation::Interpolation1DGroup* anim,edk::uint32 dest){
    //test if have the 2 polygons
    if(this->polygons.havePos(dest)
            &&
            anim){
        //select the polygon
        edk::shape::Polygon2D* poly = this->polygons[dest];
        if(poly){
            //clean the animation
            edk::animation::Interpolation1DGroup* temp = poly->framesGetAnimation();
            if(temp){
                temp->cleanAnimations();
                *temp = *anim;
                return true;
            }
        }
    }
    return false;
}
//remove polygonAnimation
bool edk::shape::AnimatedPolygon2DList::removeAnimationFramesFromPolygon(edk::uint32 position){
    //test if have the polygon
    if(this->polygons.havePos(position)){
        //select the polygon
        edk::shape::Polygon2D* temp = this->polygons[position];
        //test if have selected some polygon
        if(temp){
            //then remove the animation
            temp->framesRemoveAnimation();
            //then return true
            return true;
        }
    }
    //else return false
    return false;
}
//select the animation
bool edk::shape::AnimatedPolygon2DList::selectAnimationFramesFromPolygon(edk::uint32 position){
    //free the animation
    this->freeSelectedAnimation();
    //test if have the polygon
    if(this->polygons.havePos(position)){
        //select the polygon
        edk::shape::Polygon2D* temp = this->polygons[position];
        //test if have selected some polygon
        if(temp){
            //test if have an animation
            if(temp->framesHaveAnimation()){
                //then select the animation
                this->selectedAnimation = temp->framesGetAnimation();
                //then return true
                return true;
            }
        }
    }
    //else return false
    return false;
}
//get animation ID selected
edk::uint32 edk::shape::AnimatedPolygon2DList::getAnimationFramesSelectedID(){
    return this->selectedID;
}
//return true if have the animation
bool edk::shape::AnimatedPolygon2DList::haveSelectedAnimation(){
    if(this->selectedAnimation){
        return true;
    }
    return false;
}

//free the selected animation
void edk::shape::AnimatedPolygon2DList::freeSelectedAnimation(){
    //set selectedAnimation to NULL
    this->selectedAnimation=NULL;
    this->selectedID=0u;
}
//Atualiza as animações da malha
void edk::shape::AnimatedPolygon2DList::updateFramesAnimations(){
    //update all animations
    for(unsigned int i=0u;i<this->polygons.size();i++){
        //
        if(this->polygons[i]){
            //carrega a animation
            if(this->polygons[i]->framesIsAnimationCreator()){
                //carrega a animation
                edk::float32 clock =
                this->polygons[i]->framesGetAnimation()->updateClockAnimation();
            }
        }
    }
    //after update all polygons

    bool success;

    for(unsigned int i=0u;i<this->polygons.size();i++){
        //
        if(this->polygons[i]){
            //carrega a animation
            if(this->polygons[i]->framesGetAnimation()){
                //
                edk::float32 frameTemp = this->polygons[i]->framesGetAnimation()->getClockX(&success);
                if(success){
                    this->polygons[i]->usePolygonUVFramePosition(frameTemp);
                }
            }
        }
    }
}


//AnimationSelected
//set the abstract
bool edk::shape::AnimatedPolygon2DList::selectedAnimationSetAnimationCallback(edk::animation::AnimationCallback* callback){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->setAnimationCallback(callback);
    }
    //else return false
    return false;
}
//create a new interpoationLine
bool edk::shape::AnimatedPolygon2DList::selectedAnimationAddInterpolationLine(edk::float32 second,edk::float32 x){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->addNewInterpolationLine(second,x);
    }
    //else return false
    return false;
}
//return frames size
edk::uint32 edk::shape::AnimatedPolygon2DList::selectedAnimationGetInterpolationSize(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->getInterpolationSize();
    }
    //else return false
    return 0u;
}

//cleanFrames
bool edk::shape::AnimatedPolygon2DList::selectedAnimationCleanFrames(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->cleanAnimations();
        return true;
    }
    //else return false
    return false;
}
//controls
bool edk::shape::AnimatedPolygon2DList::selectedAnimationPlayForward(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playForward();
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon2DList::selectedAnimationPlayForwardIn(edk::float32 second){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playForwardIn(second);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon2DList::selectedAnimationPlayRewind(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playRewind();
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon2DList::selectedAnimationPlayRewindIn(edk::float32 second){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playRewindIn(second);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon2DList::selectedAnimationPause(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->pause();
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon2DList::selectedAnimationStop(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->stop();
        return true;
    }
    //else return false
    return false;
}
//set loop
bool edk::shape::AnimatedPolygon2DList::selectedAnimationSetLoop(bool loop){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->setLoop(loop);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon2DList::selectedAnimationLoopOn(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->loopOn();
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon2DList::selectedAnimationLoopOff(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->loopOff();
        return true;
    }
    //else return false
    return false;
}
//get the second
edk::float32 edk::shape::AnimatedPolygon2DList::selectedAnimationGetSecond(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->getAnimationSecond();
    }
    //return zero;
    return 0.0f;
}
//return if are playing
bool edk::shape::AnimatedPolygon2DList::selectedAnimationIsPlaying(){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->isPlaying();
        return true;
    }
    //else return false
    return false;
}
//animationNames
bool edk::shape::AnimatedPolygon2DList::selectedAnimationAddAnimationName(const char* name, edk::float32 start,edk::float32 end){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->addNewAnimationName(name,start,end);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon2DList::selectedAnimationAddAnimationName(edk::char8* name, edk::float32 start,edk::float32 end){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->addNewAnimationName(name,start,end);
        return true;
    }
    //else return false
    return false;
}
//test if have the animationName
bool edk::shape::AnimatedPolygon2DList::selectedAnimationHaveAnimationName(const char* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->haveAnimationName(name);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon2DList::selectedAnimationHaveAnimationName(edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->haveAnimationName(name);
        return true;
    }
    //else return false
    return false;
}
//Play the animationName
bool edk::shape::AnimatedPolygon2DList::selectedAnimationPlayNameForward(const char* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playNameForward(name);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon2DList::selectedAnimationPlayNameForward(edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playNameForward(name);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon2DList::selectedAnimationPlayNameRewind(const char* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playNameRewind(name);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon2DList::selectedAnimationPlayNameRewind(edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->playNameRewind(name);
        return true;
    }
    //else return false
    return false;
}
//remove the animationName
bool edk::shape::AnimatedPolygon2DList::selectedAnimationRemoveAnimationName(const char* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->removeAnimationName(name);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon2DList::selectedAnimationRemoveAnimationName(edk::char8* name){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->removeAnimationName(name);
        return true;
    }
    //else return false
    return false;
}

//Set one interpolation X as a curve
bool edk::shape::AnimatedPolygon2DList::selectedAnimationSetCurveX(edk::uint32 position){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->setInterpolationCurveX(position);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon2DList::selectedAnimationSetNotCurveX(edk::uint32 position){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        this->selectedAnimation->setInterpolationNotCurveX(position);
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon2DList::selectedAnimationGetIsCurveX(edk::uint32 position){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->getInterpolationIsCurveX(position);
    }
    //else return false
    return false;
}
//Set the interpolation curve points
bool edk::shape::AnimatedPolygon2DList::selectedAnimationSetCurveP1X(edk::uint32 position,edk::float32 second,edk::float32 x){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->setInterpolationP1X(position,second,x);
    }
    //else return false
    return false;
}
bool edk::shape::AnimatedPolygon2DList::selectedAnimationSetCurveP2X(edk::uint32 position,edk::float32 second,edk::float32 x){
    //test if have a animationSelected
    if(this->selectedAnimation){
        //add new interpolationLine
        return this->selectedAnimation->setInterpolationP2X(position,second,x);
    }
    //else return false
    return false;
}
/*
//XML
bool edk::shape::AnimatedPolygon2DList::writeToXML(edk::XML* xml,edk::uint32 id){
    if(edk::shape::Polygon2DList::writeToXML(xml,id)){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"mesh_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //write the animation
                    ret=true;
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] nameID;
        }
        return ret;
    }
    return false;
}
bool edk::shape::AnimatedPolygon2DList::readFromXML(edk::XML* xml,edk::uint32 id){
    if(edk::shape::Polygon2DList::readFromXML(xml,id)){
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"mesh_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    edk::uint32 size = edk::String::strToInt64(xml->getSelectedAttributeValueByName("pCount"));
                    edk::shape::Polygon2D poly;
                    //write the polygons
                    for(edk::uint32 i=0u;i<size;i++){
                        poly.deletePolygon();
                        poly.readFromXML(xml,i);
                        //add the poly
                        this->addPolygon(poly);
                    }
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] nameID;
        }
    }
    return false;
}
*/
