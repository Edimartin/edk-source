/*
Library EDK - How to use Extensible Development Kit
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

/*
This tutorial show's how to use the animation Interpolation Group to change values in at least 3 dimensions.
The tutorial are using the animations in three different angles with different channels but, you can use the same funcions in every channel.
*/

#include <stdio.h>

//Including interpolation group for animate at least 3 values at the same time
#include "edk/animation/Interpolation3DGroup.h"
//Including interpolation for path
#include "edk/animation/Path3DGroup.h"

int main(){
    //
    edk::animation::Interpolation1DGroup inter1;

    //add first interpolation with two points
    inter1.addFirstInterpolationLine(0.f,0.f,1.f,1.f);
    //add a new interpolation passin a third point
    inter1.addNewInterpolationLine(2.f,2.f);

    //play the animation
    inter1.playForward();
    edk::float32 seconds=0.f;
    edk::float32 x=0.f;
    bool success = false;
    //run the animation
    if(inter1.isPlaying()){
        do{
            //clean the success
            success = true;
            seconds = inter1.updateClockAnimation();
            //return this value testing if have the value
            x = inter1.getClockX(&success);
            //if success print the value
            if(success){
                x = inter1.getClockX();
                printf("\nNORMAL ANIMATION Second %.2f Value %.2f"
                       ,seconds
                       ,x
                       );fflush(stdout);
            }
        }while(inter1.isPlaying());
    }

    edk::animation::Interpolation2DGroup inter2;

    //MAKING A BALL ANIMATION WITH A BEZIER CURVE

    //If you add a new interpolation without make the firt interpolation, the first interpolation point will wait until you add the new point.
    inter2.addNewInterpolationLine(0.f,0.f,10.f);
    //Add the second point to make the first animation
    inter2.addNewInterpolationLine(4.f,0.f,0.f);
    if(inter2.getInterpolations()){
        edk::uint32 position = inter2.getInterpolations()-1u;
        //change the straight line interpolation to be a curve interpolation
        inter2.setInterpolationCurveY(position);
        //set the curve values
        inter2.setInterpolationP1Y(position,3.f,10.f);
        inter2.setInterpolationP2Y(position,4.f,8.f);
    }
    //you can add an interpolation beetween the two last
    inter2.addNewInterpolationLine(8.0f,0.f,10.f);
    if(inter2.getInterpolations()){
        edk::uint32 position = inter2.getInterpolations()-1u;
        //change the straight line interpolation to be a curve interpolation
        inter2.setInterpolationCurveY(position);
        //set the curve values
        inter2.setInterpolationP1Y(position,4.f,8.f);
        inter2.setInterpolationP2Y(position,5.f,10.f);
    }

    //play the animation in a specific second
    inter2.playForwardIn(0.1f);
    //animate
    if(inter2.isPlaying()){
        do{
            printf("\nBALL ANIMATION FORWARD Second %.2f Value %.2f %.2f"
                   ,inter2.updateClockAnimation()
                   ,inter2.getClockX()
                   ,inter2.getClockY()
                   );fflush(stdout);
        }while(inter2.isPlaying());
    }
    //play the animation rewind
    inter2.playRewindIn(8.f);
    //animate
    if(inter2.isPlaying()){
        float second = 0.f;
        do{
            second = inter2.updateClockAnimation();
            printf("\nBALL ANIMATION REWIND Second %.2f Value %.2f %.2f"
                   ,second
                   ,inter2.getClockX()
                   ,inter2.getClockY()
                   );fflush(stdout);
        }while(inter2.isPlaying());
    }

    edk::animation::Interpolation3DGroup inter3;

    //add interpolations
    inter3.addNewInterpolationLine(0.f,0.f,0.f,0.f);
    inter3.addNewInterpolationLine(10.f,0.f,0.f,0.f);
    //don't be need to add the interpolation frames on sequence
    inter3.addNewInterpolationLine(4.35f,0.f,-5.f,0.f);
    inter3.addNewInterpolationLine(15.0f,0.f,-5.f,0.f);

    //create animation names to be played from the seconds
    inter3.addNewAnimationName("FIRST",0.f,5.f);
    inter3.addNewAnimationName("SECOND",5.f,10.f);
    inter3.addNewAnimationName("THIRD",10.f,15.f);
    //the back need to be played in rewind because an animation have to be the start before the end
    inter3.addNewAnimationName("BACK",0.f,15.f);

    //play the animation
    inter3.playNameForward("FIRST");
    //change the speed
    inter3.setSpeed(2.f);
    //animate
    if(inter3.isPlaying()){
        do{
            printf("\nPLAY FIRST Second %.2f Value %.2f %.2f %.2f"
                   ,inter3.updateClockAnimation()
                   ,inter3.getClockX()
                   ,inter3.getClockY()
                   ,inter3.getClockZ()
                   );fflush(stdout);
        }while(inter3.isPlaying());
    }
    //play the animation
    inter3.playNameForward("SECOND");
    //change the speed
    inter3.setSpeed(4.f);
    //animate
    if(inter3.isPlaying()){
        do{
            printf("\nPLAY SECOND Second %.2f Value %.2f %.2f %.2f"
                   ,inter3.updateClockAnimation()
                   ,inter3.getClockX()
                   ,inter3.getClockY()
                   ,inter3.getClockZ()
                   );fflush(stdout);
        }while(inter3.isPlaying());
    }
    //play the animation
    inter3.playNameForward("THIRD");
    //change the speed
    inter3.setSpeed(2.f);
    //animate
    if(inter3.isPlaying()){
        do{
            printf("\nPLAY THIRD Second %.2f Value %.2f %.2f %.2f"
                   ,inter3.updateClockAnimation()
                   ,inter3.getClockX()
                   ,inter3.getClockY()
                   ,inter3.getClockZ()
                   );fflush(stdout);
        }while(inter3.isPlaying());
    }
    //play the animation
    inter3.playNameRewind("BACK");
    //change the speed
    inter3.setSpeed(1.f);
    //animate
    if(inter3.isPlaying()){
        do{
            printf("\nPLAY BACK REWIND Second %.2f Value %.2f %.2f %.2f"
                   ,inter3.updateClockAnimation()
                   ,inter3.getClockX()
                   ,inter3.getClockY()
                   ,inter3.getClockZ()
                   );fflush(stdout);
        }while(inter3.isPlaying());
    }

    return 0;
}
