#include "Body2D.h"

/*
Library bones Body2D - Body 2D to create the bones2D
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


//Defines used in the channelLinks
#define CHANNEL_XPOS 0x01
#define CHANNEL_YPOS 0x02
#define CHANNEL_ZPOS 0x03
#define CHANNEL_XROT 0x04
#define CHANNEL_YROT 0x05
#define CHANNEL_ZROT 0x06

edk::bones::Body2D::Body2D(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::bones::Body2D::~Body2D(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->deleteAllBones();edkEnd();
    }
}

void edk::bones::Body2D::Constructor(bool runFather){
    if(runFather){
        edk::Object2DValues::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;

        this->root.Constructor();edkEnd();
        this->bones.Constructor();edkEnd();
        this->links.Constructor();edkEnd();
        this->matrixPosition.Constructor();edkEnd();
        this->matrixAngle.Constructor();edkEnd();
        this->matrixSize.Constructor();edkEnd();
        this->matrixTransform.Constructor();edkEnd();
        this->matrixPosition.Constructor();edkEnd();
        this->matrixPivo.Constructor();edkEnd();

        this->position = edk::vec2f32(0,0);edkEnd();
        this->angle=0;
        this->cleanSelected();edkEnd();

        this->root.vector = vec2f32(0.f,0.001f);edkEnd();
    }
}

//remove using recursivity
bool edk::bones::Body2D::removeRecursive(edk::bones::Bone2D* next,edk::bones::Bone2D* removing){
    //test the removing
    if(removing){
        //test the next
        if(next){
            //search the nexts
            for(edk::uint32 i=0u;i<next->getNextsSize();i++){
                //
                edk::bones::Bone2D* temp = next->getNextInPosition(i);edkEnd();
                if(temp){
                    //test if temp have nexts
                    if(temp->getNextsSize()){
                        if(this->removeRecursive(temp,removing)){
                            return true;
                        }
                    }
                    else{
                        //else test if the temp is equal removing
                        if(temp==removing){
                            //remove the temp
                            next->removeNext(temp);edkEnd();
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
//load the Hierarckhy
edk::uint32 edk::bones::Body2D::loadHierarkhy(edk::File* file,edk::bones::Bone2D* last,edk::bones::Bone2D* bone, edk::uint8 mode,edk::vector::Stack<edk::bones::Body2D::ChannelLink>* channelLinks){
    edk::uint32 ret=0u;
    //test the file
    if(file/* && bone*/){
        //select the bone
        this->selectBone(bone);edkEnd();
        edk::bones::Bone2D* next=NULL;edkEnd();
        //set the while
        edk::char8* fileText=NULL;edkEnd();
        edk::char8 stringTest[4u];edkEnd();
        stringTest[0u] = ' ';edkEnd();
        stringTest[1u] = 9u;edkEnd();
        stringTest[2u] = '\n';edkEnd();
        stringTest[3u] = '\0';edkEnd();

        //        printf("\n   Inside");edkEnd();
        while(!file->endOfFile()){
            if(fileText){
                //                printf("\n''%s''"
                //                       ,fileText
                //                       );edkEnd();

                //test if it's the end of hierarkhy
                if(edk::String::strCompare(fileText,"}")){
                    //
                    free(fileText);edkEnd(); fileText=NULL;edkEnd();
                    //return true
                    return ret;
                }

                //test if start a new bone
                else if(edk::String::strCompare(fileText,"{")){
                    //
                    free(fileText);edkEnd(); fileText=NULL;edkEnd();

                    /////////////////////////////// START SET CHANNELS
                    /////////////////////////////// END   SET CHANNELS

                    ret+=this->loadHierarkhy(file,bone,next,mode,channelLinks);edkEnd();
                    //select the actual bone
                    this->selectBone(bone);edkEnd();

                    continue;
                }

                else if(edk::String::strCompare(fileText,"OFFSET")){
                    //create the new joint
                    //                    printf("\nSet OFFSET");edkEnd();
                    free(fileText);edkEnd();
                    edk::float32 x=0.f,y=0.f,z=0.f;edkEnd();
                    fileText = file->readBinString(stringTest,false);edkEnd();
                    if(fileText){
                        //                        printf(" X '%s'"
                        //                               ,fileText
                        //                               );edkEnd();
                        x = edk::String::strToFloat32(fileText);edkEnd();

                        free(fileText);edkEnd();
                        fileText = file->readBinString(stringTest,false);edkEnd();
                        if(fileText){
                            //                            printf(" Y '%s'"
                            //                                   ,fileText
                            //                                   );edkEnd();
                            y = edk::String::strToFloat32(fileText);edkEnd();

                            free(fileText);edkEnd();
                            fileText = file->readBinString(stringTest,false);edkEnd();
                            if(fileText){
                                //                                printf(" Z '%s'"
                                //                                       ,fileText
                                //                                       );edkEnd();
                                z = edk::String::strToFloat32(fileText);edkEnd();


                                /////////////////////////////// START LOAD OFFSET
                                //                                printf(" floatX %.2f"
                                //                                       ,x
                                //                                       );edkEnd();
                                //                                printf(" floatY %.2f"
                                //                                       ,y
                                //                                       );edkEnd();
                                //                                printf(" floatZ %.2f"
                                //                                       ,z
                                //                                       );edkEnd();
                                //set the bone position on the mode
                                switch(mode){
                                case EDK_BVH_XY:
                                    if(last){
                                        last->vector = edk::vec2f32(x,y);edkEnd();
                                    }
                                    if(bone){
                                        bone->position = edk::vec2f32(x,y);edkEnd();
                                    }
                                    break;
                                case EDK_BVH_XZ:
                                    if(last){
                                        last->vector = edk::vec2f32(x,z);edkEnd();
                                    }
                                    if(bone){
                                        bone->position = edk::vec2f32(x,z);edkEnd();
                                    }
                                    break;
                                case EDK_BVH_YZ:
                                    if(last){
                                        last->vector = edk::vec2f32(y,z);edkEnd();
                                    }
                                    if(bone){
                                        bone->position = edk::vec2f32(y,z);edkEnd();
                                    }
                                    break;
                                }
                                /////////////////////////////// END LOAD OFFSET

                                free(fileText);edkEnd();
                            }
                        }
                    }
                    fileText=NULL;edkEnd();
                    continue;
                }

                else if(edk::String::strCompare(fileText,"CHANNELS")){
                    //create the new joint
                    //                    printf("\nSet Channels");edkEnd();
                    free(fileText);edkEnd();
                    fileText = file->readBinString(stringTest,false);edkEnd();
                    if(fileText){
                        //load the number of channels
                        edk::uint32 channels = edk::String::strToInt32(fileText);edkEnd();

                        free(fileText);edkEnd();
                        /////////////////////////////// START LOAD CHANNEL SIZE
                        //                        printf(" Channels %u"
                        //                               ,channels
                        //                               );edkEnd();
                        ret+=channels;edkEnd();
                        /////////////////////////////// END LOAD CHANNEL SIZE
                        //load the channels
                        for(edk::uint32 i=0u;i<channels;i++){
                            //
                            fileText = file->readBinString(stringTest,false);edkEnd();
                            if(fileText){
                                //
                                //                                printf(" C%u == '%s'"
                                //                                       ,i
                                //                                       ,fileText
                                //                                       );edkEnd();
                                edk::bones::Body2D::ChannelLink link;edkEnd();
                                /////////////////////////////// START LOAD CHANNELS
                                if(edk::String::strCompare(fileText,"Xposition")){
                                    //create the new joint
                                    //                                    printf("=xPos");edkEnd();

                                    //add the xPos
                                    link.channel = CHANNEL_XPOS;edkEnd();
                                    link.bone = bone;edkEnd();
                                    //add the link to the channelsLink
                                    channelLinks->pushBack(link);edkEnd();
                                }

                                else if(edk::String::strCompare(fileText,"Yposition")){
                                    //create the new joint
                                    //                                    printf("=yPos");edkEnd();

                                    //add the yPos
                                    link.channel = CHANNEL_YPOS;edkEnd();
                                    link.bone = bone;edkEnd();
                                    //add the link to the channelsLink
                                    channelLinks->pushBack(link);edkEnd();
                                }

                                else if(edk::String::strCompare(fileText,"Zposition")){
                                    //create the new joint
                                    //                                    printf("=zPos");edkEnd();

                                    //add the zPos
                                    link.channel = CHANNEL_ZPOS;edkEnd();
                                    link.bone = bone;edkEnd();
                                    //add the link to the channelsLink
                                    channelLinks->pushBack(link);edkEnd();
                                }

                                else if(edk::String::strCompare(fileText,"Xrotation")){
                                    //create the new joint
                                    //                                    printf("=xRot");edkEnd();

                                    //add the xRot
                                    link.channel = CHANNEL_XROT;edkEnd();
                                    link.bone = bone;edkEnd();
                                    //add the link to the channelsLink
                                    channelLinks->pushBack(link);edkEnd();
                                }

                                else if(edk::String::strCompare(fileText,"Yrotation")){
                                    //create the new joint
                                    //                                    printf("=yRot");edkEnd();

                                    //add the yRot
                                    link.channel = CHANNEL_YROT;edkEnd();
                                    link.bone = bone;edkEnd();
                                    //add the link to the channelsLink
                                    channelLinks->pushBack(link);edkEnd();
                                }

                                else if(edk::String::strCompare(fileText,"Zrotation")){
                                    //create the new joint
                                    //                                    printf("=zRot");edkEnd();

                                    //add the zRot
                                    link.channel = CHANNEL_ZROT;edkEnd();
                                    link.bone = bone;edkEnd();
                                    //add the link to the channelsLink
                                    channelLinks->pushBack(link);edkEnd();
                                }

                                /////////////////////////////// END LOAD CHANNELS
                                free(fileText);edkEnd();
                            }
                        }
                    }
                    fileText=NULL;edkEnd();
                    continue;
                }

                else if(edk::String::strCompare(fileText,"JOINT")){
                    //create the new joint
                    //                    printf("\nCreate Joint");edkEnd();
                    free(fileText);edkEnd();
                    fileText = file->readBinString(stringTest,false);edkEnd();
                    if(fileText){

                        /////////////////////////////// START CREATE JOINT
                        //                        printf(" Joint Name '%s'"
                        //                               ,fileText
                        //                               );edkEnd();
                        next = this->createBoneToSelected(fileText);edkEnd();
                        /////////////////////////////// END CREATE JOINT
                        //
                        free(fileText);edkEnd();
                        fileText=NULL;edkEnd();
                        continue;
                    }
                }

                else if(edk::String::strCompare(fileText,"End")){
                    //create the new joint
                    //                    printf("\nCreate END");edkEnd();
                    free(fileText);edkEnd();
                    fileText = file->readBinString(stringTest,false);edkEnd();
                    if(fileText){
                        /////////////////////////////// START CREATE END
                        //                        printf(" END Name '%s'"
                        //                               ,fileText
                        //                               );edkEnd();
                        //next = this->createBoneToSelected(fileText);edkEnd();
                        next = NULL;edkEnd();
                        /////////////////////////////// END CREATE END
                        free(fileText);edkEnd();
                        fileText=NULL;edkEnd();
                        continue;
                    }
                }



                //
                free(fileText);edkEnd(); fileText=NULL;edkEnd();
            }
            //load the string
            fileText = file->readBinString(stringTest,false);edkEnd();
        }
    }
    return ret;
}

//load the BVH
bool edk::bones::Body2D::loadBVH(edk::char8* name,edk::uint8 mode){
    this->deleteAllBones();edkEnd();
    if(name){
        bool ret=true;edkEnd();
        //first count the name
        edk::uint32 size = edk::String::strSize(name);edkEnd();
        edk::char8* nameTemp=NULL;edkEnd();

        if(size>4u){
            //test if have the bvh in the end of the string
            if(name[size-1u] == 'h')if(name[size-2u] == 'v')if(name[size-3u] == 'b')if(name[size-4u] == '.'){
                //then ret=false
                ret=false;edkEnd();
            }
        }

        if(size<=4u || ret){
            //need to add the .bvh
            nameTemp = (edk::char8*)malloc(sizeof(edk::char8) * (size + 5u));edkEnd();
            if(nameTemp){
                //copy the string
                memcpy(nameTemp,name,size);edkEnd();
                nameTemp[size] = '.';edkEnd();
                nameTemp[size+1u] = 'b';edkEnd();
                nameTemp[size+2u] = 'v';edkEnd();
                nameTemp[size+3u] = 'h';edkEnd();
                nameTemp[size+4u] = '\0';edkEnd();
            }
        }
        else{
            //just clone the string
            nameTemp = edk::String::strCopy(name);edkEnd();
        }

        //just set the rect correctly
        ret=false;edkEnd();

        //test if alloc the nameTemp
        if(nameTemp){
            //

            //            printf("\nNameTemp == '%s'"
            //                   ,nameTemp
            //                   );edkEnd();

            //channels vector
            edk::vector::Stack<edk::bones::Body2D::ChannelLink> channelLinks(3u);edkEnd();

            //open the file
            edk::File file;edkEnd();
            if(file.openBinFile(nameTemp)){
                //
                //                printf("\nAbriu o arquivo");edkEnd();

                //load the file to create the bvh
                edk::char8* fileText = NULL;edkEnd();
                edk::char8 stringTest[4u];edkEnd();
                stringTest[0u] = ' ';edkEnd();
                stringTest[1u] = 9u;edkEnd();
                stringTest[2u] = '\n';edkEnd();
                stringTest[3u] = '\0';edkEnd();

                //animation channels
                edk::uint32 channels=0u;

                while(!file.endOfFile()){
                    ret=true;edkEnd();
                    //load the strings
                    fileText = file.readBinString(stringTest,false);edkEnd();
                    if(fileText){
                        //                        printf("\n'%s'"
                        //                               ,fileText
                        //                               );edkEnd();
                        if(edk::String::strCompare(fileText,"HIERARCHY")){
                            //                            printf(" Find HIERARCHY");edkEnd();
                            //delete the text to load a new text
                            free(fileText);edkEnd();

                            fileText = file.readBinString(stringTest,false);edkEnd();

                            if(fileText){
                                //test if find the root
                                if(edk::String::strCompare(fileText,"ROOT")){
                                    //
                                    free(fileText);edkEnd();

                                    //load the root name
                                    fileText = file.readBinString("\n\0",false);edkEnd();
                                    if(fileText){
                                        //
                                        //                                        printf("\nRoot Name '%s'"
                                        //                                               ,fileText
                                        //                                               );edkEnd();
                                        this->root.setName(fileText);edkEnd();

                                        free(fileText);edkEnd();
                                        //load the {
                                        fileText = file.readBinString(stringTest,false);edkEnd();
                                        if(fileText){
                                            //
                                            if(edk::String::strCompare(fileText,"{")){
                                                //
                                                //                                                printf("\nStart load hierarkhy");edkEnd();
                                                channels = this->loadHierarkhy(&file,NULL,&this->root,mode,&channelLinks);edkEnd();
                                            }
                                        }
                                        else{
                                            edkEnd();
                                            continue;
                                        }
                                    }
                                    else{
                                        edkEnd();
                                        continue;
                                    }
                                }
                            }
                            else{
                                edkEnd();
                                continue;
                            }



                        }
                        else if(edk::String::strCompare(fileText,"MOTION")){
                            //                            printf(" Find MOTION");edkEnd();
                            free(fileText);edkEnd();

                            //load the next frames
                            fileText = file.readBinString(stringTest,false);edkEnd();
                            if(fileText){
                                //test if is frames
                                if(edk::String::strCompare(fileText,"Frames:")){
                                    //find frames
                                    //                                    printf("\nFind Frames");edkEnd();

                                    free(fileText);edkEnd();
                                    //load the next frames
                                    fileText = file.readBinString(stringTest,false);edkEnd();
                                    if(fileText){
                                        //
                                        //                                        printf("  Frames == '%s'"
                                        //                                               ,fileText
                                        //                                               );edkEnd();
                                        edk::uint32 frames = edk::String::strToInt32(fileText);edkEnd();

                                        //                                        printf("  Number %u"
                                        //                                               ,frames
                                        //                                               );edkEnd();

                                        free(fileText);edkEnd();
                                        //load the next frames
                                        fileText = file.readBinString(stringTest,false);edkEnd();
                                        if(fileText){
                                            //test if this is equal to frame
                                            if(edk::String::strCompare(fileText,"Frame")){
                                                //
                                                free(fileText);edkEnd();
                                                fileText = file.readBinString(stringTest,false);edkEnd();
                                                if(fileText){
                                                    //
                                                    if(edk::String::strCompare(fileText,"Time:")){
                                                        //load the time
                                                        free(fileText);edkEnd();
                                                        fileText = file.readBinString(stringTest,false);edkEnd();
                                                        if(fileText){
                                                            //
                                                            edk::float32 time = edk::String::strToFloat32(fileText);edkEnd();

                                                            //                                                            printf("  Time == %.2f"
                                                            //                                                                   ,time
                                                            //                                                                   );edkEnd();
                                                            //                                                            printf("\nChannels == %u links == %u"
                                                            //                                                                   ,channels
                                                            //                                                                   ,channelLinks.size()
                                                            //                                                                   );edkEnd();
                                                            free(fileText);edkEnd();

                                                            edk::float32 frameClock = 0.f;edkEnd();


                                                            //load the time animation
                                                            edk::float32 channelValue = 0.f;edkEnd();
                                                            for(edk::uint32 i=0u;i<frames;i++){
                                                                for(edk::uint32 j=0u;j<channels;j++){
                                                                    if(j>=channels-1u){
                                                                        fileText = file.readBinString("\n\0",false);edkEnd();
                                                                    }
                                                                    else{
                                                                        fileText = file.readBinString(" \n\0",false);edkEnd();
                                                                    }
                                                                    if(fileText){
                                                                        //
                                                                        channelValue = edk::String::strToFloat32(fileText);edkEnd();
                                                                        //                                                                        printf("\nFRAME %u %u '%s' value %.2f to %u channel "
                                                                        //                                                                               ,i
                                                                        //                                                                               ,j
                                                                        //                                                                               ,fileText
                                                                        //                                                                               ,channelValue
                                                                        //                                                                               ,channelLinks[j].bone
                                                                        //                                                                               );edkEnd();
                                                                        switch (channelLinks.get(j).channel){
                                                                        //POSITION
                                                                        case CHANNEL_XPOS:
                                                                            //                                                                            printf(" Xposition");edkEnd();
                                                                            //test if can set the position
                                                                            if(mode== EDK_BVH_XY || mode == EDK_BVH_XZ){
                                                                                //test if dont have the frame
                                                                                if(!channelLinks.get(j).bone->animationPosition.selectFrame(frameClock)
                                                                                        &&
                                                                                        !channelLinks.get(j).bone->animationPosition.selectTempFrame(frameClock)
                                                                                        ){
                                                                                    //add the new interpolation
                                                                                    channelLinks.get(j).bone->animationPosition.addNewInterpolationLine(frameClock,
                                                                                                                                                        channelValue,
                                                                                                                                                        0
                                                                                                                                                        );edkEnd();
                                                                                }
                                                                                //else just set the x value
                                                                                channelLinks.get(j).bone->animationPosition.setFrameX(frameClock,channelValue);edkEnd();
                                                                                //                                                                                printf(" setXPos");edkEnd();
                                                                            }
                                                                            break;
                                                                        case CHANNEL_YPOS:
                                                                            //                                                                            printf(" Yposition");edkEnd();
                                                                            //test if can set the position
                                                                            if(mode == EDK_BVH_XY){
                                                                                //test if dont have the frame
                                                                                if(!channelLinks.get(j).bone->animationPosition.selectFrame(frameClock)
                                                                                        &&
                                                                                        !channelLinks.get(j).bone->animationPosition.selectTempFrame(frameClock)){
                                                                                    //add the new interpolation
                                                                                    channelLinks.get(j).bone->animationPosition.addNewInterpolationLine(frameClock,
                                                                                                                                                        channelLinks.get(j).bone->position.x,
                                                                                                                                                        channelValue
                                                                                                                                                        );edkEnd();
                                                                                }
                                                                                //else just set the x value
                                                                                channelLinks.get(j).bone->animationPosition.setFrameY(frameClock,channelValue);edkEnd();
                                                                                //                                                                                printf(" setYPos");edkEnd();
                                                                            }
                                                                            //Else test if the Y is the X
                                                                            else if(mode == EDK_BVH_YZ){
                                                                                //test if dont have the frame
                                                                                if(!channelLinks.get(j).bone->animationPosition.selectFrame(frameClock)
                                                                                        &&
                                                                                        !channelLinks.get(j).bone->animationPosition.selectTempFrame(frameClock)){
                                                                                    //add the new interpolation
                                                                                    channelLinks.get(j).bone->animationPosition.addNewInterpolationLine(frameClock,
                                                                                                                                                        channelValue,
                                                                                                                                                        0
                                                                                                                                                        );edkEnd();
                                                                                }
                                                                                //else just set the x value
                                                                                channelLinks.get(j).bone->animationPosition.setFrameX(frameClock,channelValue);edkEnd();
                                                                                //                                                                                printf(" setXPos");edkEnd();
                                                                            }
                                                                            break;
                                                                        case CHANNEL_ZPOS:
                                                                            //                                                                            printf(" Zposition");edkEnd();
                                                                            //test if can set the position
                                                                            if(mode== EDK_BVH_XZ || mode == EDK_BVH_YZ){
                                                                                //test if dont have the frame
                                                                                if(!channelLinks.get(j).bone->animationPosition.selectFrame(frameClock)
                                                                                        &&
                                                                                        !channelLinks.get(j).bone->animationPosition.selectTempFrame(frameClock)){
                                                                                    //add the new interpolation
                                                                                    channelLinks.get(j).bone->animationPosition.addNewInterpolationLine(frameClock,
                                                                                                                                                        channelLinks.get(j).bone->position.x,
                                                                                                                                                        channelValue
                                                                                                                                                        );edkEnd();
                                                                                }
                                                                                //else just set the x value
                                                                                channelLinks.get(j).bone->animationPosition.setFrameY(frameClock,channelValue);edkEnd();
                                                                                //                                                                                printf(" setYPos");edkEnd();
                                                                            }
                                                                            break;
                                                                            //ROTATION
                                                                        case CHANNEL_XROT:
                                                                            //                                                                            printf(" Xrotation");edkEnd();
                                                                            //test if use the X rotation
                                                                            if(mode==EDK_BVH_YZ){
                                                                                //add the animation
                                                                                channelLinks.get(j).bone->animationAngle.addNewInterpolationLine(frameClock,channelValue*-1.f);edkEnd();
                                                                                //                                                                                printf(" setAngle");edkEnd();
                                                                            }
                                                                            break;
                                                                        case CHANNEL_YROT:
                                                                            //                                                                            printf(" Yrotation");edkEnd();
                                                                            //test if use the Y rotation
                                                                            if(mode==EDK_BVH_XZ){
                                                                                //add the animation
                                                                                channelLinks.get(j).bone->animationAngle.addNewInterpolationLine(frameClock,channelValue*-1.f);edkEnd();
                                                                                //                                                                                printf(" setAngle");edkEnd();
                                                                            }
                                                                            break;
                                                                        case CHANNEL_ZROT:
                                                                            //                                                                            printf(" Zrotation");edkEnd();
                                                                            //test if use the Z rotation
                                                                            if(mode==EDK_BVH_XY){
                                                                                //add the animation
                                                                                channelLinks.get(j).bone->animationAngle.addNewInterpolationLine(frameClock,channelValue*-1.f);edkEnd();
                                                                                //                                                                                printf(" setAngle");edkEnd();
                                                                            }
                                                                            break;
                                                                        default:
                                                                            break;
                                                                        }

                                                                        //
                                                                        free(fileText);edkEnd();
                                                                    }
                                                                }
                                                                frameClock+=time;edkEnd();
                                                                //frameClock+=1.f;edkEnd();
                                                            }
                                                        }
                                                        continue;
                                                    }
                                                    free(fileText);edkEnd();
                                                }
                                                continue;
                                            }
                                            free(fileText);edkEnd();
                                        }
                                    }
                                    continue;
                                }

                                free(fileText);edkEnd();
                                continue;
                            }
                            continue;
                        }

                        free(fileText);edkEnd();
                    }
                }
                file.closeFile();edkEnd();
            }

            //delete nameTemp
            free(nameTemp);edkEnd();
        }
        return ret;
    }
    return false;
}

//add a new bone to the selected
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(const edk::char8* name){
    return this->createBoneToSelected((edk::char8*) name);edkEnd();
}
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(const edk::char8* name,edk::vec2f32 position){
    return this->createBoneToSelected((edk::char8*) name,position);edkEnd();
}
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(const edk::char8* name,edk::float32 positionX,edk::float32 positionY){
    return this->createBoneToSelected((edk::char8*) name,edk::vec2f32(positionX,positionY));edkEnd();
}
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(const edk::char8* name,edk::vec2f32 position,edk::float32 angle){
    return this->createBoneToSelected((edk::char8*) name,position,angle);edkEnd();
}
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(const edk::char8* name,edk::float32 positionX,edk::float32 positionY,edk::float32 angle){
    return this->createBoneToSelected((edk::char8*) name,edk::vec2f32(positionX,positionY),angle);edkEnd();
}
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(edk::char8* name){
    return this->createBoneToSelected(name,edk::vec2f32(0,0));edkEnd();
}
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(edk::char8* name,edk::vec2f32 position){
    return this->createBoneToSelected(name,position,0);edkEnd();
}
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(edk::char8* name,edk::float32 positionX,edk::float32 positionY){
    return this->createBoneToSelected(name,edk::vec2f32(positionX,positionY),0);edkEnd();
}
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(edk::char8* name,edk::vec2f32 position,edk::float32 angle){
    //test the name
    if(name){
        //create the new bone
        edk::bones::Bone2D* next = new edk::bones::Bone2D(name);edkEnd();
        if(next){
            //add the next in the tree
            if(this->bones.add(next)){
                this->selected->vector = position;edkEnd();
                //set the bone position and angle
                next->position= position;edkEnd();
                next->angle = angle;edkEnd();

                //add the bone to the nexts in the selected
                this->selected->addNext(next);edkEnd();
                return next;edkEnd();
            }
            delete next;edkEnd();
        }
    }
    return NULL;
}
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(edk::char8* name,edk::float32 positionX,edk::float32 positionY,edk::float32 angle){
    return this->createBoneToSelected(name,edk::vec2f32(positionX,positionY),angle);edkEnd();
}

//Add the bone to the selected
bool edk::bones::Body2D::addBoneToSelected(edk::bones::Bone2D* bone){
    if(bone){
        edk::bones::Bone2D* temp = /*(edk::bones::Bone2D*)*/this->bones.getElement(bone);edkEnd();
        //test if have the bone on the tree
        if(temp){
            //then remove from the last bone
            this->removeRecursive(&this->root,temp);edkEnd();
            //then add the bone to the selected
            return this->selected->addNext(temp);edkEnd();
        }
    }
    return false;
}
bool edk::bones::Body2D::addBoneToSelected(const edk::char8* name){
    return this->addBoneToSelected((edk::char8*) name);edkEnd();
}
bool edk::bones::Body2D::addBoneToSelected(edk::char8* name){
    if(name){
        //find the bone
        edk::bones::Bone2D* temp = this->getBoneByName(name);edkEnd();
        if(temp){
            //then remove from the last bone
            this->removeRecursive(&this->root,temp);edkEnd();
            //then add the bone to the selected
            return this->selected->addNext(temp);edkEnd();
        }
    }
    return false;
}

//Select the bone
bool edk::bones::Body2D::selectBone(edk::bones::Bone2D* bone){
    //test if have the bone in the body
    if(bone){
        //then can select the bone
        this->selected = /*(edk::bones::Bone2D*)*/this->bones.getElement(bone);edkEnd();
        if(selected){
            return true;
        }
        else{
            //test if the bone is the root
            if(bone==&root){
                //select the root
                this->cleanSelected();edkEnd();
                return true;
            }
        }
    }
    //else clean the selected
    this->cleanSelected();edkEnd();
    return false;
}
//Select the bone by the name
bool edk::bones::Body2D::selectBoneByName(const edk::char8* name){
    return this->selectBoneByName((edk::char8*) name);edkEnd();
}
bool edk::bones::Body2D::selectBoneByName(edk::char8* name){
    //test the name
    if(name){
        //select the bone by the name
        this->selected = this->getBoneByName(name);edkEnd();
        if(selected){
            return true;
        }
    }
    //else clean the selected
    this->cleanSelected();edkEnd();
    return false;
}
bool edk::bones::Body2D::selectedSetPosition(edk::vec2f32 position){
    //test the selected
    if(this->selected){
        //set the position
        this->selected->position = position;edkEnd();
    }
    return false;
}
bool edk::bones::Body2D::selectedSetPosition(edk::float32 x,edk::float32 y){
    return this->selectedSetPosition(edk::vec2f32(x,y));edkEnd();
}
bool edk::bones::Body2D::selectedSetVector(edk::vec2f32 vector){
    //test the selected
    if(this->selected){
        //set the position
        this->selected->vector = vector;edkEnd();
    }
    return false;
}
bool edk::bones::Body2D::selectedSetVector(edk::float32 x,edk::float32 y){
    return this->selectedSetVector(edk::vec2f32(x,y));edkEnd();
}
bool edk::bones::Body2D::selectedSetAngle(edk::float32 angle){
    //test the selected
    if(this->selected){
        //set the position
        this->selected->angle = angle;edkEnd();
    }
    return false;
}
edk::vec2f32 edk::bones::Body2D::selectedGetPosition(){
    edk::vec2f32 ret;
    if(this->selected){
        ret = this->selected->position;
    }
    return ret;
}
edk::vec2f32 edk::bones::Body2D::selectedGetWorldPosition(){
    edk::vec2f32 ret;
    if(this->selected){
        ret = this->getBoneWorldPosition(this->selected);
    }
    return ret;
}
edk::vec2f32 edk::bones::Body2D::selectedGetWorldVector(){
    edk::vec2f32 ret;
    if(this->selected){
        ret = this->getBoneWorldVector(this->selected);
    }
    return ret;
}
edk::vec2f32 edk::bones::Body2D::selectedGetVector(){
    edk::vec2f32 ret;
    if(this->selected){
        ret = this->selected->vector;
    }
    return ret;
}
edk::float32 edk::bones::Body2D::selectedGetAngle(){
    edk::float32 ret=1.f;
    if(this->selected){
        ret = this->selected->angle;
    }
    return ret;
}
//animations
bool edk::bones::Body2D::selectedCleanAnimationPosition(){
    //test the selected
    if(this->selected){
        //set the position
        this->selected->animationPosition.cleanAnimationNames();edkEnd();
        this->selected->animationPosition.cleanAnimations();edkEnd();
    }
    return false;
}
bool edk::bones::Body2D::selectedCleanAnimationNamesPosition(){
    //test the selected
    if(this->selected){
        //set the position
        this->selected->animationPosition.cleanAnimationNames();edkEnd();
    }
    return false;
}
bool edk::bones::Body2D::selectedCleanAnimationAngle(){
    //test the selected
    if(this->selected){
        //set the position
        this->selected->animationAngle.cleanAnimationNames();edkEnd();
        this->selected->animationAngle.cleanAnimations();edkEnd();
    }
    return false;
}
bool edk::bones::Body2D::selectedCleanAnimationNamesAngle(){
    //test the selected
    if(this->selected){
        //set the position
        this->selected->animationAngle.cleanAnimationNames();edkEnd();
    }
    return false;
}

//return the size of the bones
edk::uint32 edk::bones::Body2D::getBonesSize(){
    return this->bones.size()+1u;edkEnd();
}

//get the bone
edk::bones::Bone2D* edk::bones::Body2D::getBone(edk::uint32 position){
    //test the position
    if(position){
        position--;edkEnd();
        if(position < this->getBonesSize()-1u){
            //return the bone
            return /*(edk::bones::Bone2D*)*/this->bones.getElementInPosition(position);edkEnd();
        }
    }
    else{
        return &this->root;edkEnd();
    }
    return NULL;
}
edk::bones::Bone2D* edk::bones::Body2D::getBoneByName(const edk::char8* name){
    return this->getBoneByName((edk::char8*) name);edkEnd();
}
edk::bones::Bone2D* edk::bones::Body2D::getBoneByName(edk::char8* name){
    if(name){
        //test if the bone is the root
        if(edk::String::strCompare(name,this->root.getName())){
            //return the root
            return &this->root;edkEnd();
        }
        //else find the bone
        //return the bone
        return /*(edk::bones::Bone2D*)*/this->bones.getElementByName(name);edkEnd();
    }
    return NULL;
}

//remove the selection
void edk::bones::Body2D::cleanSelected(){
    this->selected=&this->root;edkEnd();
}
//delete a bone
bool edk::bones::Body2D::deleteBone(edk::bones::Bone2D* bone){
    edk::bones::Bone2D* temp = /*(edk::bones::Bone2D*)*/this->bones.getElement(bone);edkEnd();
    if(temp){
        //remove the temp from bones
        this->removeRecursive(&this->root,temp);edkEnd();
        if(this->bones.remove(temp)){
            delete temp;edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::bones::Body2D::deleteBone(const edk::char8* name){
    return this->deleteBone((edk::char8*) name);edkEnd();
}
bool edk::bones::Body2D::deleteBone(edk::char8* name){
    return this->deleteBone(this->getBoneByName(name));edkEnd();
}
//delete all bones
void edk::bones::Body2D::deleteAllBones(){
    this->cleanSelected();edkEnd();
    edk::bones::Bone2D* temp;edkEnd();
    edk::uint32 size = this->bones.size();edkEnd();
    edk::uint32 count=0u;

    for(edk::uint32 i=0u;i<size;i++){
        temp = /*(edk::bones::Bone2D*)*/this->bones.getElementInPosition(count);edkEnd();
        if(this->bones.remove(temp)){
            if(temp){
                delete temp;edkEnd();
            }
        }
        else{
            count++;edkEnd();
        }
    }
    this->bones.clean();edkEnd();

    //clean the root
    this->root.cleanBone();edkEnd();
}
//add a connection object
bool edk::bones::Body2D::addConnectionObject(const edk::char8* boneName,edk::Object2DValues* object){
    return this->addConnectionObject((edk::char8*)boneName,object);edkEnd();
}
bool edk::bones::Body2D::addConnectionObject(edk::char8* boneName,edk::Object2DValues* object){
    edk::bones::Bone2D* temp = this->getBoneByName(boneName);edkEnd();
    if(temp){
        return temp->addConnectionObject(object);edkEnd();
    }
    return false;
}

//return the objects size
edk::uint32 edk::bones::Body2D::getConnectionObjectSize(const edk::char8* boneName){
    return this->getConnectionObjectSize((edk::char8*)boneName);edkEnd();
}
edk::uint32 edk::bones::Body2D::getConnectionObjectSize(edk::char8* boneName){
    //
    edk::bones::Bone2D* temp = this->getBoneByName(boneName);edkEnd();
    if(temp){
        return temp->getConnectionObjectSize();edkEnd();
    }
    return 0u;edkEnd();
}
//remove the connectionObject
bool edk::bones::Body2D::removeConnectionObject(const edk::char8* boneName,edk::Object2DValues* object){
    return this->removeConnectionObject((edk::char8*)boneName,object);edkEnd();
}
bool edk::bones::Body2D::removeConnectionObject(edk::char8* boneName,edk::Object2DValues* object){
    //
    edk::bones::Bone2D* temp = this->getBoneByName(boneName);edkEnd();
    if(temp){
        return temp->removeConnectionObject(object);edkEnd();
    }
    return false;
}
//remove the connectionObject in the position
bool edk::bones::Body2D::removeConnectionObjectInPosition(const edk::char8* boneName,edk::uint32 position){
    return this->removeConnectionObjectInPosition((edk::char8*)boneName,position);edkEnd();
}
bool edk::bones::Body2D::removeConnectionObjectInPosition(edk::char8* boneName,edk::uint32 position){
    //
    edk::bones::Bone2D* temp = this->getBoneByName(boneName);edkEnd();
    if(temp){
        return temp->removeConnectionObjectInPosition(position);edkEnd();
    }
    return false;
}
//remove all connection objects
bool edk::bones::Body2D::removeAllConnectionObjects(const edk::char8* boneName){
    return this->removeAllConnectionObjects((edk::char8*) boneName);edkEnd();
}
bool edk::bones::Body2D::removeAllConnectionObjects(edk::char8* boneName){
    edk::bones::Bone2D* temp = this->getBoneByName(boneName);edkEnd();
    if(temp){
        temp->removeAllConnectionObjects();edkEnd();
        return true;
    }
    return false;
}
void edk::bones::Body2D::removeAllConnectionObjects(){
    edk::uint32 size = this->bones.size();edkEnd();
    edk::bones::Bone2D* temp;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        temp = /*(edk::bones::Bone2D*)*/this->bones.getElementInPosition(i);edkEnd();
        if(temp){
            temp->removeAllConnectionObjects();edkEnd();
        }
    }
}

//update animations
bool edk::bones::Body2D::updateAnimations(){
    this->root.updateAnimations();edkEnd();
    return true;
}
bool edk::bones::Body2D::updateAnimations(edk::float32 seconds){
    this->root.updateAnimations(seconds);edkEnd();
    return true;
}
//scale animations
void edk::bones::Body2D::scaleAnimations(edk::float32 scale){
    this->root.scaleAnimations(scale);edkEnd();
}
void edk::bones::Body2D::scaleAnimationsPosition(edk::float32 scale){
    this->root.scaleAnimationsPosition(scale);edkEnd();
}
void edk::bones::Body2D::scaleAnimationsAngle(edk::float32 scale){
    this->root.scaleAnimationsAngle(scale);edkEnd();
}
//scale animations
void edk::bones::Body2D::setAnimationsSpeed(edk::float32 speed){
    this->root.setAnimationsSpeed(speed);edkEnd();
}
void edk::bones::Body2D::setAnimationsPositionSpeed(edk::float32 speed){
    this->root.setAnimationPositionSpeed(speed);edkEnd();
}
void edk::bones::Body2D::setAnimationsAngleSpeed(edk::float32 speed){
    this->root.setAnimationAngleSpeed(speed);edkEnd();
}
//CONTROLS
//animation controllers
void edk::bones::Body2D::playForward(){
    this->root.playForward();edkEnd();
}
void edk::bones::Body2D::playForwardIn(edk::float32 second){
    this->root.playForwardIn(second);edkEnd();
}
void edk::bones::Body2D::playRewind(){
    this->root.playRewind();edkEnd();
}
void edk::bones::Body2D::playRewindIn(edk::float32 second){
    this->root.playRewindIn(second);edkEnd();
}
void edk::bones::Body2D::pause(){
    this->root.pause();edkEnd();
}
void edk::bones::Body2D::pauseOn(){
    this->root.pauseOn();edkEnd();
}
void edk::bones::Body2D::pauseOff(){
    this->root.pauseOff();edkEnd();
}
void edk::bones::Body2D::stop(){
    this->root.stop();edkEnd();
}
//set loop
void edk::bones::Body2D::setLoop(bool loop){
    this->root.setLoop(loop);edkEnd();
}
void edk::bones::Body2D::loopOn(){
    this->root.loopOn();edkEnd();
}
void edk::bones::Body2D::loopOff(){
    this->root.loopOff();edkEnd();
}
void edk::bones::Body2D::printFrames(){
    this->root.printFrames();edkEnd();
}
//ANIMATIONNAMES
bool edk::bones::Body2D::addNewAnimationName(const edk::char8* name, edk::float32 start,edk::float32 end){
    return this->root.addNewAnimationName(name,start,end);edkEnd();
}
bool edk::bones::Body2D::addNewAnimationName(edk::char8* name, edk::float32 start,edk::float32 end){
    return this->root.addNewAnimationName(name,start,end);edkEnd();
}
//select the animationName
bool edk::bones::Body2D::selectAnimationName(const edk::char8* name){
    return this->root.selectAnimationName(name);edkEnd();
}
bool edk::bones::Body2D::selectAnimationName(edk::char8* name){
    return this->root.selectAnimationName(name);edkEnd();
}
//test if have the animationName
bool edk::bones::Body2D::haveAnimationName(const edk::char8* name){
    return this->root.haveAnimationName(name);edkEnd();
}
bool edk::bones::Body2D::haveAnimationName(edk::char8* name){
    return this->root.haveAnimationName(name);edkEnd();
}
//Play the animationName
bool edk::bones::Body2D::playNameForward(const edk::char8* name){
    return this->root.playNameForward(name);edkEnd();
}
bool edk::bones::Body2D::playNameForward(edk::char8* name){
    return this->root.playNameForward(name);edkEnd();
}
bool edk::bones::Body2D::playNameRewind(const edk::char8* name){
    return this->root.playNameRewind(name);edkEnd();
}
bool edk::bones::Body2D::playNameRewind(edk::char8* name){
    return this->root.playNameRewind(name);edkEnd();
}
//remove the animationName
bool edk::bones::Body2D::removeAnimationName(const edk::char8* name){
    return this->root.removeAnimationName(name);edkEnd();
}
bool edk::bones::Body2D::removeAnimationName(edk::char8* name){
    return this->root.removeAnimationName(name);edkEnd();
}
void edk::bones::Body2D::removeAllAnimationNames(){
    this->root.removeAllAnimationNames();edkEnd();
}

//return if are playing
bool edk::bones::Body2D::isPlaying(){
    return this->root.isPlaying();edkEnd();
}
bool edk::bones::Body2D::isPlayingName(const edk::char8* name){
    return this->isPlayingName((edk::char8*) name);edkEnd();
}
bool edk::bones::Body2D::isPlayingName(edk::char8* name){
    return this->root.isPlayingName(name);edkEnd();
}
bool edk::bones::Body2D::wasPlayingName(const edk::char8* name){
    return this->wasPlayingName((edk::char8*) name);edkEnd();
}
bool edk::bones::Body2D::wasPlayingName(edk::char8* name){
    return this->root.wasPlayingName(name);edkEnd();
}

//load the BVH
bool edk::bones::Body2D::loadBVHXY(const edk::char8* name){
    return this->loadBVH((edk::char8*)name,EDK_BVH_XY);edkEnd();
}
bool edk::bones::Body2D::loadBVHXY(edk::char8* name){
    return this->loadBVH((edk::char8*)name,EDK_BVH_XY);edkEnd();
}
bool edk::bones::Body2D::loadBVHXZ(const edk::char8* name){
    return this->loadBVH((edk::char8*)name,EDK_BVH_XZ);edkEnd();
}
bool edk::bones::Body2D::loadBVHXZ(edk::char8* name){
    return this->loadBVH((edk::char8*)name,EDK_BVH_XZ);edkEnd();
}
bool edk::bones::Body2D::loadBVHYZ(const edk::char8* name){
    return this->loadBVH((edk::char8*)name,EDK_BVH_YZ);edkEnd();
}
bool edk::bones::Body2D::loadBVHYZ(edk::char8* name){
    return this->loadBVH((edk::char8*)name,EDK_BVH_YZ);edkEnd();
}

//print the bones
void edk::bones::Body2D::print(){
    this->root.print();edkEnd();
}
//draw the bones
void edk::bones::Body2D::draw(){
    edk::GU::guPushMatrix();edkEnd();
    edk::GU::guTranslate2f32(this->position);edkEnd();
    edk::GU::guRotateZf32(this->angle);edkEnd();
    edk::GU::guScale2f32(this->size);edkEnd();
    this->root.draw();edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
//draw the bones
void edk::bones::Body2D::drawLines(){
    edk::GU::guPushMatrix();edkEnd();
    edk::GU::guTranslate2f32(this->position);edkEnd();
    edk::GU::guRotateZf32(this->angle);edkEnd();
    edk::GU::guScale2f32(this->size);edkEnd();
    this->root.drawLines();edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::bones::Body2D::drawLinesIK(){
    edk::GU::guPushMatrix();edkEnd();
    //multiply the matrix by
    this->matrixTransform.setIdentity();edkEnd();

    //generate transform matrices
    edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
    edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);edkEnd();
    edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();

    //translate
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
    //angle
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
    //scale
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();

    edk::GU::guBegin(GU_LINES);edkEnd();
    this->root.drawLinesIK(&this->matrixTransform);edkEnd();
    edk::GU::guEnd();edkEnd();

    edk::GU::guPopMatrix();edkEnd();
}
void edk::bones::Body2D::drawPoints(edk::float32 size){
    edk::GU::guPushMatrix();edkEnd();
    edk::GU::guTranslate2f32(this->position);edkEnd();
    edk::GU::guRotateZf32(this->angle);edkEnd();
    edk::GU::guScale2f32(this->size);edkEnd();
    this->root.drawPoints(size);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
//update the connected objects
void edk::bones::Body2D::updateObjects(){
    //TRANSLATE AND ROTATE DE BONE POSITION
    edk::float32 translate[3u][3u];edkEnd();
    edk::bones::Bone2D::generateTranslateMatrix(this->position,&translate);edkEnd();

    edk::float32 angleRemove=0.f;edkEnd();
    edk::float32 angleMultiply = 1.f;edkEnd();

    //calculate the remove angle
    if(this->size.width>=0.f){
        if(this->size.height<0.f){
            //
            //printf("\n2");edkEnd();
            angleMultiply = -1.f;edkEnd();
        }
    }
    else{
        if(this->size.height>=0.f){
            //
            //printf("\n3");edkEnd();
            angleRemove = 180.f;edkEnd();
            angleMultiply = -1.f;edkEnd();
        }
    }

    //generate matrix
    edk::float32 rotate[3u][3u];edkEnd();
    edk::bones::Bone2D::generateRotationMatrix(this->angle,&rotate);edkEnd();
    //generate scale
    edk::float32 scale[3u][3u];edkEnd();
    edk::bones::Bone2D::generateScaleMatrix(this->size,&scale);edkEnd();

    //create a new matrix
    edk::float32 newMat[3u][3u];edkEnd();
    edk::bones::Bone2D::setIdentity(&newMat);edkEnd();

    //multiply the scale matrix
    edk::bones::Bone2D::multiplyMatrix(&scale,&newMat);edkEnd();
    //multiply the rotatio matrix
    edk::bones::Bone2D::multiplyMatrix(&rotate,&newMat);edkEnd();
    //multiply the translation matrix
    edk::bones::Bone2D::multiplyMatrix(&translate,&newMat);edkEnd();

    //this->root.updateObjects(this->angle,this->size,&newMat,angleRemove);edkEnd();

    this->root.updateObjects(this->angle,this->size,&newMat,angleRemove,angleMultiply);edkEnd();
}
//return the world vector of the bone
edk::vec2f32  edk::bones::Body2D::getBoneWorldVector(edk::bones::Bone2D* bone, bool* found){
    if(bone){
        //multiply the matrix by
        this->matrixTransform.setIdentity();edkEnd();

        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();

        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();

        //get the position
        if(found){
            *found=false;edkEnd();
            return this->root.getWorldVector(bone,found,this->angle,this->size,&this->matrixTransform);edkEnd();
        }
        else{
            bool iFound=false;edkEnd();
            return this->root.getWorldVector(bone,&iFound,this->angle,this->size,&this->matrixTransform);edkEnd();
        }
    }
    return edk::vec2f32(0,0);
}
edk::vec2f32  edk::bones::Body2D::getBoneWorldPosition(edk::bones::Bone2D* bone, bool* found){
    if(bone){
        //multiply the matrix by
        this->matrixTransform.setIdentity();edkEnd();

        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
        edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);edkEnd();
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();

        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();

        //get the position
        if(found){
            *found=false;edkEnd();
            return this->root.getWorldPosition(bone,found,this->angle,this->size,&this->matrixTransform);edkEnd();
        }
        else{
            bool iFound=false;edkEnd();
            return this->root.getWorldPosition(bone,&iFound,this->angle,this->size,&this->matrixTransform);edkEnd();
        }
    }
    return edk::vec2f32(0,0);
}
void edk::bones::Body2D::calculateInverseKinematic(const edk::char8* name,edk::vec2f32 worldPoint,edk::uint32 tail,edk::uint32 times){
    return this->calculateInverseKinematic((edk::char8*) name,worldPoint,tail,times);edkEnd();
}
void edk::bones::Body2D::calculateInverseKinematic(edk::char8* name,edk::vec2f32 worldPoint,edk::uint32 tail,edk::uint32 times){
    return this->calculateInverseKinematic(this->getBoneByName(name),worldPoint,tail,times);edkEnd();
}
void edk::bones::Body2D::calculateInverseKinematic(edk::bones::Bone2D* bone,edk::vec2f32 worldPoint,edk::uint32 tail,edk::uint32 times){
    if(bone){
        bool found=false;edkEnd();
        for(edk::uint32 i=0u;i<times;i++){
            //multiply the matrix by
            this->matrixTransform.setIdentity();edkEnd();

            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);edkEnd();
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);edkEnd();
            edk::Math::generateScaleMatrix(this->size,&this->matrixSize);edkEnd();

            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();

            //get the position
            found=false;edkEnd();
            edk::uint32 count;edkEnd();
            this->root.calculateInverseKinematic(bone,&found,worldPoint,tail,&count,this->angle,this->size,&this->matrixTransform);edkEnd();
        }
    }
}
