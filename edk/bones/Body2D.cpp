#include "Body2D.h"

/*
Library bones Body2D - Body 2D to create the bones2D
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


//Defines used in the channelLinks
#define CHANNEL_XPOS 0x01
#define CHANNEL_YPOS 0x02
#define CHANNEL_ZPOS 0x03
#define CHANNEL_XROT 0x04
#define CHANNEL_YROT 0x05
#define CHANNEL_ZROT 0x06

edk::bones::Body2D::Body2D()
{
    this->position = edk::vec2f32(0,0);
    this->angle=0;
    this->cleanSelected();

    this->root.vector = vec2f32(0.f,0.001f);

    this->canDelete=true;
}
edk::bones::Body2D::~Body2D(){
    if(this->canDelete){
        this->deleteAllBones();
    }
    else{
        this->canDelete=true;
        //this->root.cantDelete();
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
                edk::bones::Bone2D* temp = next->getNextInPosition(i);
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
                            next->removeNext(temp);
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
        this->selectBone(bone);
        edk::bones::Bone2D* next=NULL;
        //set the while
        edk::char8* fileText=NULL;
        edk::char8 stringTest[4u];
        stringTest[0u] = ' ';
        stringTest[1u] = 9u;
        stringTest[2u] = '\n';
        stringTest[3u] = '\0';

        //        printf("\n   Inside");fflush(stdout);
        while(!file->endOfFile()){
            if(fileText){
                //                printf("\n''%s''"
                //                       ,fileText
                //                       );fflush(stdout);

                //test if it's the end of hierarkhy
                if(edk::String::strCompare(fileText,"}")){
                    //
                    delete[] fileText; fileText=NULL;
                    //return true
                    return ret;
                }

                //test if start a new bone
                else if(edk::String::strCompare(fileText,"{")){
                    //
                    delete[] fileText; fileText=NULL;

                    /////////////////////////////// START SET CHANNELS
                    /////////////////////////////// END   SET CHANNELS

                    ret+=this->loadHierarkhy(file,bone,next,mode,channelLinks);
                    //select the actual bone
                    this->selectBone(bone);

                    continue;
                }

                else if(edk::String::strCompare(fileText,"OFFSET")){
                    //create the new joint
                    //                    printf("\nSet OFFSET");fflush(stdout);
                    delete[] fileText;
                    edk::float32 x=0.f,y=0.f,z=0.f;
                    fileText = file->readBinString(stringTest,false);
                    if(fileText){
                        //                        printf(" X '%s'"
                        //                               ,fileText
                        //                               );fflush(stdout);
                        x = edk::String::strToFloat32(fileText);

                        delete[] fileText;
                        fileText = file->readBinString(stringTest,false);
                        if(fileText){
                            //                            printf(" Y '%s'"
                            //                                   ,fileText
                            //                                   );fflush(stdout);
                            y = edk::String::strToFloat32(fileText);

                            delete[] fileText;
                            fileText = file->readBinString(stringTest,false);
                            if(fileText){
                                //                                printf(" Z '%s'"
                                //                                       ,fileText
                                //                                       );fflush(stdout);
                                z = edk::String::strToFloat32(fileText);


                                /////////////////////////////// START LOAD OFFSET
                                //                                printf(" floatX %.2f"
                                //                                       ,x
                                //                                       );fflush(stdout);
                                //                                printf(" floatY %.2f"
                                //                                       ,y
                                //                                       );fflush(stdout);
                                //                                printf(" floatZ %.2f"
                                //                                       ,z
                                //                                       );fflush(stdout);
                                //set the bone position on the mode
                                switch(mode){
                                case EDK_BVH_XY:
                                    if(last){
                                        last->vector = edk::vec2f32(x,y);
                                    }
                                    if(bone){
                                        bone->position = edk::vec2f32(x,y);
                                    }
                                    break;
                                case EDK_BVH_XZ:
                                    if(last){
                                        last->vector = edk::vec2f32(x,z);
                                    }
                                    if(bone){
                                        bone->position = edk::vec2f32(x,z);
                                    }
                                    break;
                                case EDK_BVH_YZ:
                                    if(last){
                                        last->vector = edk::vec2f32(y,z);
                                    }
                                    if(bone){
                                        bone->position = edk::vec2f32(y,z);
                                    }
                                    break;
                                }
                                /////////////////////////////// END LOAD OFFSET

                                delete[] fileText;
                            }
                        }
                    }
                    fileText=NULL;
                    continue;
                }

                else if(edk::String::strCompare(fileText,"CHANNELS")){
                    //create the new joint
                    //                    printf("\nSet Channels");fflush(stdout);
                    delete[] fileText;
                    fileText = file->readBinString(stringTest,false);
                    if(fileText){
                        //load the number of channels
                        edk::uint32 channels = edk::String::strToInt32(fileText);

                        delete[] fileText;
                        /////////////////////////////// START LOAD CHANNEL SIZE
                        //                        printf(" Channels %u"
                        //                               ,channels
                        //                               );fflush(stdout);
                        ret+=channels;
                        /////////////////////////////// END LOAD CHANNEL SIZE
                        //load the channels
                        for(edk::uint32 i=0u;i<channels;i++){
                            //
                            fileText = file->readBinString(stringTest,false);
                            if(fileText){
                                //
                                //                                printf(" C%u == '%s'"
                                //                                       ,i
                                //                                       ,fileText
                                //                                       );fflush(stdout);
                                edk::bones::Body2D::ChannelLink link;
                                /////////////////////////////// START LOAD CHANNELS
                                if(edk::String::strCompare(fileText,"Xposition")){
                                    //create the new joint
                                    //                                    printf("=xPos");fflush(stdout);

                                    //add the xPos
                                    link.channel = CHANNEL_XPOS;
                                    link.bone = bone;
                                    //add the link to the channelsLink
                                    channelLinks->pushBack(link);
                                }

                                else if(edk::String::strCompare(fileText,"Yposition")){
                                    //create the new joint
                                    //                                    printf("=yPos");fflush(stdout);

                                    //add the yPos
                                    link.channel = CHANNEL_YPOS;
                                    link.bone = bone;
                                    //add the link to the channelsLink
                                    channelLinks->pushBack(link);
                                }

                                else if(edk::String::strCompare(fileText,"Zposition")){
                                    //create the new joint
                                    //                                    printf("=zPos");fflush(stdout);

                                    //add the zPos
                                    link.channel = CHANNEL_ZPOS;
                                    link.bone = bone;
                                    //add the link to the channelsLink
                                    channelLinks->pushBack(link);
                                }

                                else if(edk::String::strCompare(fileText,"Xrotation")){
                                    //create the new joint
                                    //                                    printf("=xRot");fflush(stdout);

                                    //add the xRot
                                    link.channel = CHANNEL_XROT;
                                    link.bone = bone;
                                    //add the link to the channelsLink
                                    channelLinks->pushBack(link);
                                }

                                else if(edk::String::strCompare(fileText,"Yrotation")){
                                    //create the new joint
                                    //                                    printf("=yRot");fflush(stdout);

                                    //add the yRot
                                    link.channel = CHANNEL_YROT;
                                    link.bone = bone;
                                    //add the link to the channelsLink
                                    channelLinks->pushBack(link);
                                }

                                else if(edk::String::strCompare(fileText,"Zrotation")){
                                    //create the new joint
                                    //                                    printf("=zRot");fflush(stdout);

                                    //add the zRot
                                    link.channel = CHANNEL_ZROT;
                                    link.bone = bone;
                                    //add the link to the channelsLink
                                    channelLinks->pushBack(link);
                                }

                                /////////////////////////////// END LOAD CHANNELS
                                delete[] fileText;
                            }
                        }
                    }
                    fileText=NULL;
                    continue;
                }

                else if(edk::String::strCompare(fileText,"JOINT")){
                    //create the new joint
                    //                    printf("\nCreate Joint");fflush(stdout);
                    delete[] fileText;
                    fileText = file->readBinString(stringTest,false);
                    if(fileText){

                        /////////////////////////////// START CREATE JOINT
                        //                        printf(" Joint Name '%s'"
                        //                               ,fileText
                        //                               );fflush(stdout);
                        next = this->createBoneToSelected(fileText);
                        /////////////////////////////// END CREATE JOINT
                        //
                        delete[] fileText;
                        fileText=NULL;
                        continue;
                    }
                }

                else if(edk::String::strCompare(fileText,"End")){
                    //create the new joint
                    //                    printf("\nCreate END");fflush(stdout);
                    delete[] fileText;
                    fileText = file->readBinString(stringTest,false);
                    if(fileText){
                        /////////////////////////////// START CREATE END
                        //                        printf(" END Name '%s'"
                        //                               ,fileText
                        //                               );fflush(stdout);
                        //next = this->createBoneToSelected(fileText);
                        next = NULL;
                        /////////////////////////////// END CREATE END
                        delete[] fileText;
                        fileText=NULL;
                        continue;
                    }
                }



                //
                delete[] fileText; fileText=NULL;
            }
            //load the string
            fileText = file->readBinString(stringTest,false);
        }
    }
    return ret;
}

//load the BVH
bool edk::bones::Body2D::loadBVH(edk::char8* name,edk::uint8 mode){
    this->deleteAllBones();
    if(name){
        bool ret=true;
        //first count the name
        edk::uint32 size = edk::String::strSize(name);
        edk::char8* nameTemp=NULL;

        if(size>4u){
            //test if have the bvh in the end of the string
            if(name[size-1u] == 'h')if(name[size-2u] == 'v')if(name[size-3u] == 'b')if(name[size-4u] == '.'){
                //then ret=false
                ret=false;
            }
        }

        if(size<=4u || ret){
            //need to add the .bvh
            nameTemp = new edk::char8[size + 5u];
            if(nameTemp){
                //copy the string
                memcpy(nameTemp,name,size);
                nameTemp[size] = '.';
                nameTemp[size+1u] = 'b';
                nameTemp[size+2u] = 'v';
                nameTemp[size+3u] = 'h';
                nameTemp[size+4u] = '\0';
            }
        }
        else{
            //just clone the string
            nameTemp = edk::String::strCopy(name);
        }

        //just set the rect correctly
        ret=false;

        //test if alloc the nameTemp
        if(nameTemp){
            //

            //            printf("\nNameTemp == '%s'"
            //                   ,nameTemp
            //                   );fflush(stdout);

            //channels vector
            edk::vector::Stack<edk::bones::Body2D::ChannelLink> channelLinks(3u);

            //open the file
            edk::File file;
            if(file.openBinFile(nameTemp)){
                //
                //                printf("\nAbriu o arquivo");fflush(stdout);

                //load the file to create the bvh
                edk::char8* fileText = NULL;
                edk::char8 stringTest[4u];
                stringTest[0u] = ' ';
                stringTest[1u] = 9u;
                stringTest[2u] = '\n';
                stringTest[3u] = '\0';

                //animation channels
                edk::uint32 channels=0u;

                while(!file.endOfFile()){
                    ret=true;
                    //load the strings
                    fileText = file.readBinString(stringTest,false);
                    if(fileText){
                        //                        printf("\n'%s'"
                        //                               ,fileText
                        //                               );fflush(stdout);
                        if(edk::String::strCompare(fileText,"HIERARCHY")){
                            //                            printf(" Find HIERARCHY");fflush(stdout);
                            //delete the text to load a new text
                            delete[] fileText;

                            fileText = file.readBinString(stringTest,false);

                            if(fileText){
                                //test if find the root
                                if(edk::String::strCompare(fileText,"ROOT")){
                                    //
                                    delete[] fileText;

                                    //load the root name
                                    fileText = file.readBinString("\n\0",false);
                                    if(fileText){
                                        //
                                        //                                        printf("\nRoot Name '%s'"
                                        //                                               ,fileText
                                        //                                               );fflush(stdout);
                                        this->root.setName(fileText);

                                        delete[] fileText;
                                        //load the {
                                        fileText = file.readBinString(stringTest,false);
                                        if(fileText){
                                            //
                                            if(edk::String::strCompare(fileText,"{")){
                                                //
                                                //                                                printf("\nStart load hierarkhy");fflush(stdout);
                                                channels = this->loadHierarkhy(&file,NULL,&this->root,mode,&channelLinks);
                                            }
                                        }
                                        else continue;
                                    }
                                    else continue;
                                }
                            }
                            else continue;



                        }
                        else if(edk::String::strCompare(fileText,"MOTION")){
                            //                            printf(" Find MOTION");fflush(stdout);
                            delete[] fileText;

                            //load the next frames
                            fileText = file.readBinString(stringTest,false);
                            if(fileText){
                                //test if is frames
                                if(edk::String::strCompare(fileText,"Frames:")){
                                    //find frames
                                    //                                    printf("\nFind Frames");

                                    delete[] fileText;
                                    //load the next frames
                                    fileText = file.readBinString(stringTest,false);
                                    if(fileText){
                                        //
                                        //                                        printf("  Frames == '%s'"
                                        //                                               ,fileText
                                        //                                               );
                                        edk::uint32 frames = edk::String::strToInt32(fileText);

                                        //                                        printf("  Number %u"
                                        //                                               ,frames
                                        //                                               );

                                        delete[] fileText;
                                        //load the next frames
                                        fileText = file.readBinString(stringTest,false);
                                        if(fileText){
                                            //test if this is equal to frame
                                            if(edk::String::strCompare(fileText,"Frame")){
                                                //
                                                delete[] fileText;
                                                fileText = file.readBinString(stringTest,false);
                                                if(fileText){
                                                    //
                                                    if(edk::String::strCompare(fileText,"Time:")){
                                                        //load the time
                                                        delete[] fileText;
                                                        fileText = file.readBinString(stringTest,false);
                                                        if(fileText){
                                                            //
                                                            edk::float32 time = edk::String::strToFloat32(fileText);

                                                            //                                                            printf("  Time == %.2f"
                                                            //                                                                   ,time
                                                            //                                                                   );
                                                            //                                                            printf("\nChannels == %u links == %u"
                                                            //                                                                   ,channels
                                                            //                                                                   ,channelLinks.size()
                                                            //                                                                   );
                                                            delete[] fileText;

                                                            edk::float32 frameClock = 0.f;


                                                            //load the time animation
                                                            edk::float32 channelValue = 0.f;
                                                            for(edk::uint32 i=0u;i<frames;i++){
                                                                for(edk::uint32 j=0u;j<channels;j++){
                                                                    if(j>=channels-1u){
                                                                        fileText = file.readBinString("\n\0",false);
                                                                    }
                                                                    else{
                                                                        fileText = file.readBinString(" \n\0",false);
                                                                    }
                                                                    if(fileText){
                                                                        //
                                                                        channelValue = edk::String::strToFloat32(fileText);
                                                                        //                                                                        printf("\nFRAME %u %u '%s' value %.2f to %u channel "
                                                                        //                                                                               ,i
                                                                        //                                                                               ,j
                                                                        //                                                                               ,fileText
                                                                        //                                                                               ,channelValue
                                                                        //                                                                               ,channelLinks[j].bone
                                                                        //                                                                               );fflush(stdout);
                                                                        switch (channelLinks[j].channel) {
                                                                        //POSITION
                                                                        case CHANNEL_XPOS:
                                                                            //                                                                            printf(" Xposition");
                                                                            //test if can set the position
                                                                            if(mode== EDK_BVH_XY || mode == EDK_BVH_XZ){
                                                                                //test if dont have the frame
                                                                                if(!channelLinks[j].bone->animationPosition.selectFrame(frameClock)
                                                                                        &&
                                                                                        !channelLinks[j].bone->animationPosition.selectTempFrame(frameClock)
                                                                                        ){
                                                                                    //add the new interpolation
                                                                                    channelLinks[j].bone->animationPosition.addNewInterpolationLine(frameClock,
                                                                                                                                                    channelValue,
                                                                                                                                                    0
                                                                                                                                                    );
                                                                                }
                                                                                //else just set the x value
                                                                                channelLinks[j].bone->animationPosition.setFrameX(frameClock,channelValue);
                                                                                //                                                                                printf(" setXPos");fflush(stdout);
                                                                            }
                                                                            break;
                                                                        case CHANNEL_YPOS:
                                                                            //                                                                            printf(" Yposition");
                                                                            //test if can set the position
                                                                            if(mode == EDK_BVH_XY){
                                                                                //test if dont have the frame
                                                                                if(!channelLinks[j].bone->animationPosition.selectFrame(frameClock)
                                                                                        &&
                                                                                        !channelLinks[j].bone->animationPosition.selectTempFrame(frameClock)){
                                                                                    //add the new interpolation
                                                                                    channelLinks[j].bone->animationPosition.addNewInterpolationLine(frameClock,
                                                                                                                                                    channelLinks[j].bone->position.x,
                                                                                                                                                    channelValue
                                                                                                                                                    );
                                                                                }
                                                                                //else just set the x value
                                                                                channelLinks[j].bone->animationPosition.setFrameY(frameClock,channelValue);
                                                                                //                                                                                printf(" setYPos");fflush(stdout);
                                                                            }
                                                                            //Else test if the Y is the X
                                                                            else if(mode == EDK_BVH_YZ){
                                                                                //test if dont have the frame
                                                                                if(!channelLinks[j].bone->animationPosition.selectFrame(frameClock)
                                                                                        &&
                                                                                        !channelLinks[j].bone->animationPosition.selectTempFrame(frameClock)){
                                                                                    //add the new interpolation
                                                                                    channelLinks[j].bone->animationPosition.addNewInterpolationLine(frameClock,
                                                                                                                                                    channelValue,
                                                                                                                                                    0
                                                                                                                                                    );
                                                                                }
                                                                                //else just set the x value
                                                                                channelLinks[j].bone->animationPosition.setFrameX(frameClock,channelValue);
                                                                                //                                                                                printf(" setXPos");fflush(stdout);
                                                                            }
                                                                            break;
                                                                        case CHANNEL_ZPOS:
                                                                            //                                                                            printf(" Zposition");
                                                                            //test if can set the position
                                                                            if(mode== EDK_BVH_XZ || mode == EDK_BVH_YZ){
                                                                                //test if dont have the frame
                                                                                if(!channelLinks[j].bone->animationPosition.selectFrame(frameClock)
                                                                                        &&
                                                                                        !channelLinks[j].bone->animationPosition.selectTempFrame(frameClock)){
                                                                                    //add the new interpolation
                                                                                    channelLinks[j].bone->animationPosition.addNewInterpolationLine(frameClock,
                                                                                                                                                    channelLinks[j].bone->position.x,
                                                                                                                                                    channelValue
                                                                                                                                                    );
                                                                                }
                                                                                //else just set the x value
                                                                                channelLinks[j].bone->animationPosition.setFrameY(frameClock,channelValue);
                                                                                //                                                                                printf(" setYPos");fflush(stdout);
                                                                            }
                                                                            break;
                                                                            //ROTATION
                                                                        case CHANNEL_XROT:
                                                                            //                                                                            printf(" Xrotation");
                                                                            //test if use the X rotation
                                                                            if(mode==EDK_BVH_YZ){
                                                                                //add the animation
                                                                                channelLinks[j].bone->animationAngle.addNewInterpolationLine(frameClock,channelValue*-1.f);
                                                                                //                                                                                printf(" setAngle");fflush(stdout);
                                                                            }
                                                                            break;
                                                                        case CHANNEL_YROT:
                                                                            //                                                                            printf(" Yrotation");
                                                                            //test if use the Y rotation
                                                                            if(mode==EDK_BVH_XZ){
                                                                                //add the animation
                                                                                channelLinks[j].bone->animationAngle.addNewInterpolationLine(frameClock,channelValue*-1.f);
                                                                                //                                                                                printf(" setAngle");fflush(stdout);
                                                                            }
                                                                            break;
                                                                        case CHANNEL_ZROT:
                                                                            //                                                                            printf(" Zrotation");
                                                                            //test if use the Z rotation
                                                                            if(mode==EDK_BVH_XY){
                                                                                //add the animation
                                                                                channelLinks[j].bone->animationAngle.addNewInterpolationLine(frameClock,channelValue*-1.f);
                                                                                //                                                                                printf(" setAngle");fflush(stdout);
                                                                            }
                                                                            break;
                                                                        default:
                                                                            break;
                                                                        }

                                                                        //
                                                                        delete[] fileText;
                                                                    }
                                                                }
                                                                frameClock+=time;
                                                                //frameClock+=1.f;
                                                            }
                                                        }
                                                        continue;
                                                    }
                                                    delete[] fileText;
                                                }
                                                continue;
                                            }
                                            delete[] fileText;
                                        }
                                    }
                                    continue;
                                }

                                delete[] fileText;
                                continue;
                            }
                            continue;
                        }

                        delete[] fileText;
                    }
                }
                file.closeFile();
            }

            //delete nameTemp
            delete[] nameTemp;
        }
        return ret;
    }
    return false;
}

//add a new bone to the selected
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(const edk::char8* name){
    return this->createBoneToSelected((edk::char8*) name);
}
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(const edk::char8* name,edk::vec2f32 position){
    return this->createBoneToSelected((edk::char8*) name,position);
}
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(const edk::char8* name,edk::float32 positionX,edk::float32 positionY){
    return this->createBoneToSelected((edk::char8*) name,edk::vec2f32(positionX,positionY));
}
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(const edk::char8* name,edk::vec2f32 position,edk::float32 angle){
    return this->createBoneToSelected((edk::char8*) name,position,angle);
}
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(const edk::char8* name,edk::float32 positionX,edk::float32 positionY,edk::float32 angle){
    return this->createBoneToSelected((edk::char8*) name,edk::vec2f32(positionX,positionY),angle);
}
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(edk::char8* name){
    return this->createBoneToSelected(name,edk::vec2f32(0,0));
}
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(edk::char8* name,edk::vec2f32 position){
    return this->createBoneToSelected(name,position,0);
}
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(edk::char8* name,edk::float32 positionX,edk::float32 positionY){
    return this->createBoneToSelected(name,edk::vec2f32(positionX,positionY),0);
}
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(edk::char8* name,edk::vec2f32 position,edk::float32 angle){
    //test the name
    if(name){
        //create the new bone
        edk::bones::Bone2D* next = new edk::bones::Bone2D(name);
        if(next){
            //add the next in the tree
            if(this->bones.add(next)){
                this->selected->vector = position;
                //set the bone position and angle
                next->position= position;
                next->angle = angle;

                //add the bone to the nexts in the selected
                this->selected->addNext(next);
                return next;
            }
            delete next;
        }
    }
    return NULL;
}
edk::bones::Bone2D* edk::bones::Body2D::createBoneToSelected(edk::char8* name,edk::float32 positionX,edk::float32 positionY,edk::float32 angle){
    return this->createBoneToSelected(name,edk::vec2f32(positionX,positionY),angle);
}

//Add the bone to the selected
bool edk::bones::Body2D::addBoneToSelected(edk::bones::Bone2D* bone){
    if(bone){
        edk::bones::Bone2D* temp = /*(edk::bones::Bone2D*)*/this->bones.getElement(bone);
        //test if have the bone on the tree
        if(temp){
            //then remove from the last bone
            this->removeRecursive(&this->root,temp);
            //then add the bone to the selected
            return this->selected->addNext(temp);
        }
    }
    return false;
}
bool edk::bones::Body2D::addBoneToSelected(const edk::char8* name){
    return this->addBoneToSelected((edk::char8*) name);
}
bool edk::bones::Body2D::addBoneToSelected(edk::char8* name){
    if(name){
        //find the bone
        edk::bones::Bone2D* temp = this->getBoneByName(name);
        if(temp){
            //then remove from the last bone
            this->removeRecursive(&this->root,temp);
            //then add the bone to the selected
            return this->selected->addNext(temp);
        }
    }
    return false;
}

//Select the bone
bool edk::bones::Body2D::selectBone(edk::bones::Bone2D* bone){
    //test if have the bone in the body
    if(bone){
        //then can select the bone
        this->selected = /*(edk::bones::Bone2D*)*/this->bones.getElement(bone);
        if(selected){
            return true;
        }
        else{
            //test if the bone is the root
            if(bone==&root){
                //select the root
                this->cleanSelected();
                return true;
            }
        }
    }
    //else clean the selected
    this->cleanSelected();
    return false;
}
//Select the bone by the name
bool edk::bones::Body2D::selectBoneByName(const edk::char8* name){
    return this->selectBoneByName((edk::char8*) name);
}
bool edk::bones::Body2D::selectBoneByName(edk::char8* name){
    //test the name
    if(name){
        //select the bone by the name
        this->selected = this->getBoneByName(name);
        if(selected){
            return true;
        }
    }
    //else clean the selected
    this->cleanSelected();
    return false;
}
bool edk::bones::Body2D::selectedSetPosition(edk::vec2f32 position){
    //test the selected
    if(this->selected){
        //set the position
        this->selected->position = position;
    }
    return false;
}
bool edk::bones::Body2D::selectedSetPosition(edk::float32 x,edk::float32 y){
    return this->selectedSetPosition(edk::vec2f32(x,y));
}
bool edk::bones::Body2D::selectedSetVector(edk::vec2f32 vector){
    //test the selected
    if(this->selected){
        //set the position
        this->selected->vector = vector;
    }
    return false;
}
bool edk::bones::Body2D::selectedSetVector(edk::float32 x,edk::float32 y){
    return this->selectedSetVector(edk::vec2f32(x,y));
}
bool edk::bones::Body2D::selectedSetAngle(edk::float32 angle){
    //test the selected
    if(this->selected){
        //set the position
        this->selected->angle = angle;
    }
    return false;
}
//animations
bool edk::bones::Body2D::selectedCleanAnimationPosition(){
    //test the selected
    if(this->selected){
        //set the position
        this->selected->animationPosition.cleanAnimationNames();
        this->selected->animationPosition.cleanAnimations();
    }
    return false;
}
bool edk::bones::Body2D::selectedCleanAnimationNamesPosition(){
    //test the selected
    if(this->selected){
        //set the position
        this->selected->animationPosition.cleanAnimationNames();
    }
    return false;
}
bool edk::bones::Body2D::selectedCleanAnimationAngle(){
    //test the selected
    if(this->selected){
        //set the position
        this->selected->animationAngle.cleanAnimationNames();
        this->selected->animationAngle.cleanAnimations();
    }
    return false;
}
bool edk::bones::Body2D::selectedCleanAnimationNamesAngle(){
    //test the selected
    if(this->selected){
        //set the position
        this->selected->animationAngle.cleanAnimationNames();
    }
    return false;
}

//return the size of the bones
edk::uint32 edk::bones::Body2D::getBonesSize(){
    return this->bones.size()+1u;
}

//get the bone
edk::bones::Bone2D* edk::bones::Body2D::getBone(edk::uint32 position){
    //test the position
    if(position){
        position--;
        if(position < this->getBonesSize()-1u){
            //return the bone
            return /*(edk::bones::Bone2D*)*/this->bones.getElementInPosition(position);
        }
    }
    else{
        return &this->root;
    }
    return NULL;
}
edk::bones::Bone2D* edk::bones::Body2D::getBoneByName(const edk::char8* name){
    return this->getBoneByName((edk::char8*) name);
}
edk::bones::Bone2D* edk::bones::Body2D::getBoneByName(edk::char8* name){
    if(name){
        //test if the bone is the root
        if(edk::String::strCompare(name,this->root.getName())){
            //return the root
            return &this->root;
        }
        //else find the bone
        //return the bone
        return /*(edk::bones::Bone2D*)*/this->bones.getElementByName(name);
    }
    return NULL;
}

//remove the selection
void edk::bones::Body2D::cleanSelected(){
    this->selected=&this->root;
}
//delete a bone
bool edk::bones::Body2D::deleteBone(edk::bones::Bone2D* bone){
    edk::bones::Bone2D* temp = /*(edk::bones::Bone2D*)*/this->bones.getElement(bone);
    if(temp){
        //remove the temp from bones
        this->removeRecursive(&this->root,temp);
        if(this->bones.remove(temp)){
            delete temp;
            return true;
        }
    }
    return false;
}
bool edk::bones::Body2D::deleteBone(const edk::char8* name){
    return this->deleteBone((edk::char8*) name);
}
bool edk::bones::Body2D::deleteBone(edk::char8* name){
    return this->deleteBone(this->getBoneByName(name));
}
//delete all bones
void edk::bones::Body2D::deleteAllBones(){
    this->cleanSelected();
    edk::bones::Bone2D* temp;
    edk::uint32 size = this->bones.size();
    edk::uint32 count=0u;

    for(edk::uint32 i=0u;i<size;i++){
        temp = /*(edk::bones::Bone2D*)*/this->bones.getElementInPosition(count);
        if(this->bones.remove(temp)){
            if(temp){
                delete temp;
            }
        }
        else{
            count++;
        }
    }
    this->bones.clean();

    //clean the root
    this->root.cleanBone();
}
//add a connection object
bool edk::bones::Body2D::addConnectionObject(const edk::char8* boneName,edk::Object2DValues* object){
    return this->addConnectionObject((edk::char8*)boneName,object);
}
bool edk::bones::Body2D::addConnectionObject(edk::char8* boneName,edk::Object2DValues* object){
    edk::bones::Bone2D* temp = this->getBoneByName(boneName);
    if(temp){
        return temp->addConnectionObject(object);
    }
    return false;
}

//return the objects size
edk::uint32 edk::bones::Body2D::getConnectionObjectSize(const edk::char8* boneName){
    return this->getConnectionObjectSize((edk::char8*)boneName);
}
edk::uint32 edk::bones::Body2D::getConnectionObjectSize(edk::char8* boneName){
    //
    edk::bones::Bone2D* temp = this->getBoneByName(boneName);
    if(temp){
        return temp->getConnectionObjectSize();
    }
    return 0u;
}
//remove the connectionObject
bool edk::bones::Body2D::removeConnectionObject(const edk::char8* boneName,edk::Object2DValues* object){
    return this->removeConnectionObject((edk::char8*)boneName,object);
}
bool edk::bones::Body2D::removeConnectionObject(edk::char8* boneName,edk::Object2DValues* object){
    //
    edk::bones::Bone2D* temp = this->getBoneByName(boneName);
    if(temp){
        return temp->removeConnectionObject(object);
    }
    return false;
}
//remove the connectionObject in the position
bool edk::bones::Body2D::removeConnectionObjectInPosition(const edk::char8* boneName,edk::uint32 position){
    return this->removeConnectionObjectInPosition((edk::char8*)boneName,position);
}
bool edk::bones::Body2D::removeConnectionObjectInPosition(edk::char8* boneName,edk::uint32 position){
    //
    edk::bones::Bone2D* temp = this->getBoneByName(boneName);
    if(temp){
        return temp->removeConnectionObjectInPosition(position);
    }
    return false;
}
//remove all connection objects
bool edk::bones::Body2D::removeAllConnectionObjects(const edk::char8* boneName){
    return this->removeAllConnectionObjects((edk::char8*) boneName);
}
bool edk::bones::Body2D::removeAllConnectionObjects(edk::char8* boneName){
    edk::bones::Bone2D* temp = this->getBoneByName(boneName);
    if(temp){
        temp->removeAllConnectionObjects();
        return true;
    }
    return false;
}
void edk::bones::Body2D::removeAllConnectionObjects(){
    edk::uint32 size = this->bones.size();
    edk::bones::Bone2D* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = /*(edk::bones::Bone2D*)*/this->bones.getElementInPosition(i);
        if(temp){
            temp->removeAllConnectionObjects();
        }
    }
}

//update animations
void edk::bones::Body2D::updateAnimations(){
    this->root.updateAnimations();
}
//scale animations
void edk::bones::Body2D::scaleAnimations(edk::float32 scale){
    this->root.scaleAnimations(scale);
}
void edk::bones::Body2D::scaleAnimationsPosition(edk::float32 scale){
    this->root.scaleAnimationsPosition(scale);
}
void edk::bones::Body2D::scaleAnimationsAngle(edk::float32 scale){
    this->root.scaleAnimationsAngle(scale);
}
//scale animations
void edk::bones::Body2D::setAnimationsSpeed(edk::float32 speed){
    this->root.setAnimationsSpeed(speed);
}
void edk::bones::Body2D::setAnimationsPositionSpeed(edk::float32 speed){
    this->root.setAnimationPositionSpeed(speed);
}
void edk::bones::Body2D::setAnimationsAngleSpeed(edk::float32 speed){
    this->root.setAnimationAngleSpeed(speed);
}
//CONTROLS
//animation controllers
void edk::bones::Body2D::playForward(){
    this->root.playForward();
}
void edk::bones::Body2D::playForwardIn(edk::float32 second){
    this->root.playForwardIn(second);
}
void edk::bones::Body2D::playRewind(){
    this->root.playRewind();
}
void edk::bones::Body2D::playRewindIn(edk::float32 second){
    this->root.playRewindIn(second);
}
void edk::bones::Body2D::pause(){
    this->root.pause();
}
void edk::bones::Body2D::pauseOn(){
    this->root.pauseOn();
}
void edk::bones::Body2D::pauseOff(){
    this->root.pauseOff();
}
void edk::bones::Body2D::stop(){
    this->root.stop();
}
//set loop
void edk::bones::Body2D::setLoop(bool loop){
    this->root.setLoop(loop);
}
void edk::bones::Body2D::loopOn(){
    this->root.loopOn();
}
void edk::bones::Body2D::loopOff(){
    this->root.loopOff();
}
void edk::bones::Body2D::printFrames(){
    this->root.printFrames();
}
//ANIMATIONNAMES
bool edk::bones::Body2D::addNewAnimationName(const edk::char8* name, edk::float32 start,edk::float32 end){
    return this->root.addNewAnimationName(name,start,end);
}
bool edk::bones::Body2D::addNewAnimationName(edk::char8* name, edk::float32 start,edk::float32 end){
    return this->root.addNewAnimationName(name,start,end);
}
//select the animationName
bool edk::bones::Body2D::selectAnimationName(const edk::char8* name){
    return this->root.selectAnimationName(name);
}
bool edk::bones::Body2D::selectAnimationName(edk::char8* name){
    return this->root.selectAnimationName(name);
}
//test if have the animationName
bool edk::bones::Body2D::haveAnimationName(const edk::char8* name){
    return this->root.haveAnimationName(name);
}
bool edk::bones::Body2D::haveAnimationName(edk::char8* name){
    return this->root.haveAnimationName(name);
}
//Play the animationName
bool edk::bones::Body2D::playNameForward(const edk::char8* name){
    return this->root.playNameForward(name);
}
bool edk::bones::Body2D::playNameForward(edk::char8* name){
    return this->root.playNameForward(name);
}
bool edk::bones::Body2D::playNameRewind(const edk::char8* name){
    return this->root.playNameRewind(name);
}
bool edk::bones::Body2D::playNameRewind(edk::char8* name){
    return this->root.playNameRewind(name);
}
//remove the animationName
bool edk::bones::Body2D::removeAnimationName(const edk::char8* name){
    return this->root.removeAnimationName(name);
}
bool edk::bones::Body2D::removeAnimationName(edk::char8* name){
    return this->root.removeAnimationName(name);
}
void edk::bones::Body2D::removeAllAnimationNames(){
    this->root.removeAllAnimationNames();
}

//return if are playing
bool edk::bones::Body2D::isPlaying(){
    return this->root.isPlaying();
}

//load the BVH
bool edk::bones::Body2D::loadBVHXY(const edk::char8* name){
    return this->loadBVH((edk::char8*)name,EDK_BVH_XY);
}
bool edk::bones::Body2D::loadBVHXY(edk::char8* name){
    return this->loadBVH((edk::char8*)name,EDK_BVH_XY);
}
bool edk::bones::Body2D::loadBVHXZ(const edk::char8* name){
    return this->loadBVH((edk::char8*)name,EDK_BVH_XZ);
}
bool edk::bones::Body2D::loadBVHXZ(edk::char8* name){
    return this->loadBVH((edk::char8*)name,EDK_BVH_XZ);
}
bool edk::bones::Body2D::loadBVHYZ(const edk::char8* name){
    return this->loadBVH((edk::char8*)name,EDK_BVH_YZ);
}
bool edk::bones::Body2D::loadBVHYZ(edk::char8* name){
    return this->loadBVH((edk::char8*)name,EDK_BVH_YZ);
}

//print the bones
void edk::bones::Body2D::print(){
    this->root.print();
}
//draw the bones
void edk::bones::Body2D::draw(){
    edk::GU::guPushMatrix();
    edk::GU::guTranslate2f32(this->position);
    edk::GU::guRotateYf32(this->angle);
    edk::GU::guScale2f32(this->size);
    this->root.draw();
    edk::GU::guPopMatrix();
}
//update the connected objects
void edk::bones::Body2D::updateObjects(){
    //TRANSLATE AND ROTATE DE BONE POSITION
    edk::float32 translate[3u][3u];
    edk::bones::Bone2D::generateTranslateMatrix(this->position,&translate);

    edk::float32 angleRemove=0.f;
    edk::float32 angleMultiply = 1.f;

    //calculate the remove angle
    if(this->size.width>=0.f){
        if(this->size.height<0.f){
            //
            //printf("\n2");
            angleMultiply = -1.f;
        }
    }
    else{
        if(this->size.height>=0.f){
            //
            //printf("\n3");
            angleRemove = 180.f;
            angleMultiply = -1.f;
        }
    }

    //generate matrix
    edk::float32 rotate[3u][3u];
    edk::bones::Bone2D::generateRotationMatrix(this->angle,&rotate);
    //generate scale
    edk::float32 scale[3u][3u];
    edk::bones::Bone2D::generateScaleMatrix(this->size,&scale);

    //create a new matrix
    edk::float32 newMat[3u][3u];
    edk::bones::Bone2D::setIdentity(&newMat);

    //multiply the scale matrix
    edk::bones::Bone2D::multiplyMatrix(&scale,&newMat);
    //multiply the rotatio matrix
    edk::bones::Bone2D::multiplyMatrix(&rotate,&newMat);
    //multiply the translation matrix
    edk::bones::Bone2D::multiplyMatrix(&translate,&newMat);

    //this->root.updateObjects(this->angle,this->size,&newMat,angleRemove);

    this->root.updateObjects(this->angle,this->size,&newMat,angleRemove,angleMultiply);
}
//return the world vector of the bone
edk::vec2f32  edk::bones::Body2D::getBoneWorldVector(edk::bones::Bone2D* bone, bool* found){
    if(bone){
        //TRANSLATE AND ROTATE DE BONE POSITION
        edk::float32 translate[3u][3u];
        edk::bones::Bone2D::generateTranslateMatrix(this->position,&translate);
        //generate matrix
        edk::float32 rotate[3u][3u];
        edk::bones::Bone2D::generateRotationMatrix(this->angle,&rotate);
        //generate scale
        edk::float32 scale[3u][3u];
        edk::bones::Bone2D::generateScaleMatrix(this->size,&scale);

        //create a new matrix
        edk::float32 newMat[3u][3u];
        edk::bones::Bone2D::setIdentity(&newMat);

        //multiply the rotatio matrix
        edk::bones::Bone2D::multiplyMatrix(&rotate,&newMat);
        //multiply the scale matrix
        edk::bones::Bone2D::multiplyMatrix(&scale,&newMat);
        //multiply the translation matrix
        edk::bones::Bone2D::multiplyMatrix(&translate,&newMat);

        //get the position
        if(found){
            *found=false;
            return this->root.getWorldVector(bone,found,this->angle,this->size,&newMat);
        }
        else{
            bool iFound=false;
            return this->root.getWorldVector(bone,&iFound,this->angle,this->size,&newMat);
        }
    }
    return edk::vec2f32(0,0);
}
void edk::bones::Body2D::calculateInverseKinematic(const edk::char8* name,edk::vec2f32 worldPoint,edk::uint32 tail,edk::uint32 times){
    return this->calculateInverseKinematic((edk::char8*) name,worldPoint,tail,times);
}
void edk::bones::Body2D::calculateInverseKinematic(edk::char8* name,edk::vec2f32 worldPoint,edk::uint32 tail,edk::uint32 times){
    return this->calculateInverseKinematic(this->getBoneByName(name),worldPoint,tail,times);
}
void edk::bones::Body2D::calculateInverseKinematic(edk::bones::Bone2D* bone,edk::vec2f32 worldPoint,edk::uint32 tail,edk::uint32 times){
    if(bone){
        for(edk::uint32 i=0u;i<times;i++){
            //TRANSLATE AND ROTATE DE BONE POSITION
            edk::float32 translate[3u][3u];
            edk::bones::Bone2D::generateTranslateMatrix(this->position,&translate);
            //generate matrix
            edk::float32 rotate[3u][3u];
            edk::bones::Bone2D::generateRotationMatrix(this->angle,&rotate);
            //generate scale
            edk::float32 scale[3u][3u];
            edk::bones::Bone2D::generateScaleMatrix(this->size,&scale);

            //create a new matrix
            edk::float32 newMat[3u][3u];
            edk::bones::Bone2D::setIdentity(&newMat);

            //multiply the rotatio matrix
            edk::bones::Bone2D::multiplyMatrix(&rotate,&newMat);
            //multiply the scale matrix
            edk::bones::Bone2D::multiplyMatrix(&scale,&newMat);
            //multiply the translation matrix
            edk::bones::Bone2D::multiplyMatrix(&translate,&newMat);

            //get the position
            bool found=false;
            edk::uint32 count;
            this->root.calculateInverseKinematic(bone,&found,worldPoint,tail,&count,this->angle,this->size,&newMat);
        }
    }
}

void edk::bones::Body2D::cantDelete(){
    this->canDelete=false;
    this->root.cantDelete();
}
