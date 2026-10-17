#include "RetroViewPaletteEdit.h"

/*
Library C++ ViewPaletteEdit - View used to Edit Palettes in EDK
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
#pragma message "            Inside RetroViewPaletteEdit.cpp"
#endif

edk::retro::RetroPalette edk::retro::RetroViewPaletteEdit::staticPalette;
edk::uint64 edk::retro::RetroViewPaletteEdit::staticCounterPalette=0uL;

#define editorWaitSelection 0.25f
#define EditorBackground 0x33

edk::retro::RetroViewPaletteEdit::RetroViewPaletteEdit(){
    this->classThis=NULL;
    this->Constructor();
}
edk::retro::RetroViewPaletteEdit::~RetroViewPaletteEdit(){
    this->Destructor();
}

void edk::retro::RetroViewPaletteEdit::Constructor(){
    edk::ViewGU2D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;


        this->movingIdStart = 0u;
        this->movingIdEnd = 0u;
        this->selectingMove=false;
        this->haveMoveId=false;

        this->animSelection.addFirstInterpolationLine(0.f,editorWaitSelection);

        if(!edk::retro::RetroViewPaletteEdit::staticCounterPalette){
            edk::retro::RetroViewPaletteEdit::staticPalette.Constructor();
        }
        edk::retro::RetroViewPaletteEdit::staticCounterPalette++;

        this->setPalette(NULL);
    }
}
void edk::retro::RetroViewPaletteEdit::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;

        if(edk::retro::RetroViewPaletteEdit::staticCounterPalette){
            edk::retro::RetroViewPaletteEdit::staticCounterPalette--;
            if(!edk::retro::RetroViewPaletteEdit::staticCounterPalette){
                edk::retro::RetroViewPaletteEdit::staticPalette.Destructor();
            }
        }

        this->animSelection.clean();
        this->animCenterCamera.clean();
    }
    edk::ViewGU2D::Destructor();
}

//set the img pointer
bool edk::retro::RetroViewPaletteEdit::setFromImg(edk::Image2D* img){
    if(img){
        if(img->havePalette()){
            return this->palette->copyPalette(img->getPalette(),
                                             img->getPaletteSize(),
                                             img->getChannels(),
                                             img->getBytesPerChannel()
                                             );
        }
    }
    return false;
}
bool edk::retro::RetroViewPaletteEdit::setFromPalette(edk::uint8* palette,edk::uint32 size,edk::uint8 channels,edk::uint8 bytesPerChannel){
    if(palette && size && channels && bytesPerChannel){
        return this->palette->copyPalette(palette,
                                         size,
                                         channels,
                                         bytesPerChannel
                                         );;
    }
    return false;
}

bool edk::retro::RetroViewPaletteEdit::setPalette(edk::retro::RetroPalette* palette){
    if(palette){
        this->palette=palette;
        return true;
    }
    this->palette=&edk::retro::RetroViewPaletteEdit::staticPalette;
    return false;
}
edk::retro::RetroPalette* edk::retro::RetroViewPaletteEdit::getPalette(){
    return this->palette;
}

bool edk::retro::RetroViewPaletteEdit::havePressedColor(){
    if(this->colorPressed){
        this->colorPressed=false;
        return true;
    }
    return false;
}
edk::uint32 edk::retro::RetroViewPaletteEdit::getPressedColorId(){
    return this->idPressed;
}
edk::uint32 edk::retro::RetroViewPaletteEdit::getPressedMouseButton(){
    return this->mousePressed;
}

bool edk::retro::RetroViewPaletteEdit::needMoveID(){
    if(this->haveMoveId){
        this->haveMoveId=false;
        return true;
    }
    return false;
}
edk::uint32 edk::retro::RetroViewPaletteEdit::getMoveIdStart(){
    return this->movingIdStart;
}
edk::uint32 edk::retro::RetroViewPaletteEdit::getMoveIdEnd(){
    return this->movingIdEnd;
}

//start select to move
void edk::retro::RetroViewPaletteEdit::selectMove(edk::uint32 id){
    this->selectingMove=true;
    this->movingIdStart = id;
}

void edk::retro::RetroViewPaletteEdit::updateViewSize(){
    //
    this->updateCamera();
}

//update the camera size
void edk::retro::RetroViewPaletteEdit::updateCamera(){
    this->camera.setSize(this->frame.size.width,this->frame.size.height);
    this->camera.position = 0.f;
    /*
    if(this->frame.size.width >= this->frame.size.height){
        if(this->objBack.size.width >= this->objBack.size.height){
            this->camera.setSizeH(this->objBack.size.width);
            this->camera.setSizeW((this->frame.size.width / this->frame.size.height)
                                  * this->camera.getSize().width
                                  );
        }
        else{
            this->camera.setSizeW(this->objBack.size.height);
            this->camera.setSizeH((this->frame.size.height / this->frame.size.width)
                                  * this->camera.getSize().height
                                  );
        }
    }
    else{
        if(this->objBack.size.width >= this->objBack.size.height){
            this->camera.setSizeW(this->objBack.size.width);
            this->camera.setSizeH((this->frame.size.width / this->frame.size.height)
                                  * this->camera.getSize().width
                                  );
        }
        else{
            this->camera.setSizeH(this->objBack.size.height);
            this->camera.setSizeW((this->frame.size.height / this->frame.size.width)
                                  * this->camera.getSize().height
                                  );
        }
    }
    */
    //calculate the object inside the camera
    //edk::rectf32 rect = this->camera.getRectPositionAndSize();
    //rect = edk::Math::aspectRatioCorrect(rect,edk::size2f32(this->img.getWidth(),this->img.getHeight()));
    //this->objBack.size.width = rect.size.width;
    //this->objBack.size.height = rect.size.height;
}
//process the selection
void edk::retro::RetroViewPaletteEdit::selectObject(edk::uint32 /*position*/,
                                                    edk::int32 /*objects*/,
                                                    edk::float32 /*near*/,
                                                    edk::float32 /*far*/,
                                                    edk::vector::Stack<edk::uint32>* names
                                                    ){
    /*
    printf("\n%u %s %s"
           "\nposition[%u]"
           "\nobjects[%d]"
           "\nnear[%.2f]"
           "\nfar[%.2f]"
           "\nnames[%u]: "
           ,__LINE__,__FILE__,__func__
           ,position
           ,objects
           ,near
           ,far
           ,names->size()
           );fflush(stdout);
    edk::uint32 size = names->size();
    for(edk::uint32 i=0u;i<size;i++){
        printf("[%u]",names->get(i));
        fflush(stdout);
    }
*/
    if(names->size()>=2u){
        edk::uint32 id = names->get(1u);
        if(this->mousePressed){
            switch(this->mousePressed){
            case edk::mouse::left:
                if(this->selectingMove){
                    this->movingIdEnd = id;
                    this->selectingMove=false;
/*
                    printf("\n%u %s %s Move from %u to %u",__LINE__,__FILE__,__func__
                           ,this->movingIdStart
                           ,this->movingIdEnd
                           );fflush(stdout);
*/
                    this->haveMoveId=true;
                }
                else{
                    //
                    //printf("\nClick color %u mouse Left",id);fflush(stdout);
                    this->idPressed = id;
                    this->colorPressed=true;
                }
                break;
            case edk::mouse::right:
                //printf("\nClick color %u mouse Right",id);fflush(stdout);
                this->idPressed = id;
                this->colorPressed=true;
                break;
            }
        }
        else{
            this->movingIdEnd = id;
        }
    }
}

void edk::retro::RetroViewPaletteEdit::resize(edk::rectf32 /*outsideViewOrigin*/){
}
void edk::retro::RetroViewPaletteEdit::load(edk::rectf32 /*outsideViewOrigin*/){
    this->backgroundColor = edk::color4f32((edk::float32)EditorBackground/0xFF,
                                           (edk::float32)EditorBackground/0xFF,
                                           (edk::float32)EditorBackground/0xFF,
                                           1.f);
    this->updateCamera();
}
void edk::retro::RetroViewPaletteEdit::unload(){
    //
}
//update the view
void edk::retro::RetroViewPaletteEdit::update(edk::WindowEvents* events){
    //update the view
    edk::View::update(events);

    this->animSelection.updateClockAnimation(events->secondPassed);

    //process the in
    edk::uint32 size = 0u;

    bool holdControl=false;
    bool pressZoomIn=false;
    bool pressZoomDout=false;
    bool pressMouseMiddle=false;
    bool pressMouseLeft=false;
    bool pressMouseRight=false;
    //bool holdMouseLeft=false;
    bool holdMouseMiddle=false;

    size = events->keyHolded.size();
    for(edk::uint32 i=0u;i<size;i++){
        switch(events->keyHolded.get(i)){
        case edk::key::lControl:
            holdControl=true;
            break;
        case edk::key::rControl:
            holdControl=true;
            break;
        }
    }

    size = events->keyPressed.size();
    for(edk::uint32 i=0u;i<size;i++){
        switch(events->keyPressed.get(i)){
        case edk::key::add:
            pressZoomIn=true;
            break;
        case edk::key::equal:
            pressZoomIn=true;
            break;
        case edk::key::subtract:
            pressZoomDout=true;
            break;
        case edk::key::dash:
            pressZoomDout=true;
            break;
        }
    }
    size = events->keyRelease.size();
    for(edk::uint32 i=0u;i<size;i++){
        switch(events->keyRelease.get(i)){
        case edk::key::add:
            //pressZoomIn=true;
            break;
        case edk::key::equal:
            //pressZoomIn=true;
            break;
        case edk::key::subtract:
            //pressZoomDout=true;
            break;
        case edk::key::dash:
            //pressZoomDout=true;
            break;
        }
    }

    size = events->mousePressed.size();
    for(edk::uint32 i=0u;i<size;i++){
        switch(events->mousePressed.get(i)){
        case edk::mouse::left:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            pressMouseLeft=true;
            break;
        case edk::mouse::right:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            pressMouseRight=true;
            break;
        case edk::mouse::middle:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            pressMouseMiddle=true;
            break;
        }
    }
    size = events->mouseHolded.size();
    for(edk::uint32 i=0u;i<size;i++){
        switch(events->mouseHolded.get(i)){
        case edk::mouse::left:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            //holdMouseLeft=true;
            break;
        case edk::mouse::right:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            break;
        case edk::mouse::middle:
            //printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
            holdMouseMiddle=true;
            break;
        }
    }

    if(this->isMouseInside()){
        //convert the mouse position
        this->posMouse.position = this->positionScreenToWorld(events->mousePosView.x,events->mousePosView.y);

        //distance in the world
        edk::vec2f32 distance = edk::vec2f32(this->savePosMouse.x - this->posMouse.position.x,
                                             this->savePosMouse.y - this->posMouse.position.y
                                             );
        this->distanceMouse = edk::Math::pythagoras(edk::vec2f32(this->savePosMouseSelect.x - this->posMouse.position.x,
                                                                 this->savePosMouseSelect.y - this->posMouse.position.y
                                                                 )
                                                    );

        //move the camera with the scroll
        if(events->mouseScrollWheelHorizontal){
            if(!holdControl){
/*
                this->camera.position.x += this->camera.getSize().width * 0.1f * events->mouseScrollWheelHorizontal
                        * -1.f
                        ;
*/
            }
        }
        if(events->mouseScrollWheelVertical){
            if(!holdControl){
                /*
                this->camera.position.y += this->camera.getSize().height * 0.1f * events->mouseScrollWheelVertical;
                */
            }
        }
        //process the zoom
        if(pressZoomIn){
            //
        }
        if(pressZoomDout){
            //
        }

        //process the selection
        if(/*holdMouseLeft || */pressMouseLeft || pressMouseRight){
            //
            if(pressMouseLeft){
                this->mousePressed = edk::mouse::left;
            }
            else if(pressMouseRight){
                this->mousePressed = edk::mouse::right;
            }
            if(!this->animSelection.isPlaying()){
                this->testSelection(events->mousePosView.x,events->mousePosView.y,
                                    1.f,
                                    1.f
                                    );
                this->animSelection.playForward();
            }
        }
        else if(this->selectingMove){
            this->mousePressed = 0u;
            this->testSelection(events->mousePosView.x,events->mousePosView.y,
                                1.f,
                                1.f
                                );
        }
        if(pressMouseMiddle){
            //
        }
        if(holdMouseMiddle){
            if(events->mouseMoved){
                if(edk::Math::equal(0.f,this->frame.size.width)
                        || edk::Math::equal(0.f,this->frame.size.height)
                        ){
                    distance = edk::vec2f32((((edk::float32)events->mouseMove.x/(this->frame.size.width+0.001f))*this->camera.getSize().width)
                                            ,
                                            (((edk::float32)events->mouseMove.y/(this->frame.size.height+0.001f))*this->camera.getSize().height)
                                            );
                }
                else{
                    distance = edk::vec2f32((((edk::float32)events->mouseMove.x/this->frame.size.width)*this->camera.getSize().width)
                                            ,
                                            (((edk::float32)events->mouseMove.y/this->frame.size.height)*this->camera.getSize().height)
                                            );
                }
                //move the camera into the distance
                if(!this->animCenterCamera.isPlaying()){
                    this->camera.position.x -= distance.x;
                    //this->camera.position.y += distance.y;
                    //this->updateZoom();
                }
            }
        }
    }
}
void edk::retro::RetroViewPaletteEdit::drawScene(edk::rectf32 /*outsideViewOrigin*/){
    //draw the polygons inside the rectangle
    if(this->palette->havePalette()){
        edk::uint32 sizePalette = this->palette->getSize();
        edk::uint8* vec = this->palette->getPalette();
        edk::uint8 channels = this->palette->getChannels();
        edk::uint8 bytesPerchannel = this->palette->getBytesPerChannel();
        edk::rectf32 rect;
        rect.origin.x = (this->frame.size.height * sizePalette) * -0.5f;
        rect.size.width = (this->frame.size.height * sizePalette) * +0.5f;
        rect.origin.y = this->frame.size.height * -0.5f;
        rect.size.height = this->frame.size.height * +0.5f;

        edk::float32 increment = (rect.size.width-rect.origin.x)*1.f/(edk::float32)sizePalette;
        edk::float32 position1 = rect.origin.x;
        edk::float32 position2 = rect.origin.x + increment;

        edk::uint32 r,g,b,a;

        //draw the quads
        switch(channels){
        case 1u:
            //G
            edk::GU::guBegin(GU_QUADS);
            for(edk::uint32 i=0u;i<sizePalette;i++){
                g=0u;
                edkMemCpy(&g,&vec[0u*bytesPerchannel],bytesPerchannel);
                edk::GU::guColor4f32(g/(edk::float32)(0xFF*bytesPerchannel),
                                     g/(edk::float32)(0xFF*bytesPerchannel),
                                     g/(edk::float32)(0xFF*bytesPerchannel),
                                     1.f
                                     );
                //X1 Y1
                edk::GU::guVertex2f32(position1,rect.origin.y);
                //X1 Y2
                edk::GU::guVertex2f32(position1,rect.size.height);
                //X2 Y2
                edk::GU::guVertex2f32(position2,rect.size.height);
                //X2 Y1
                edk::GU::guVertex2f32(position2,rect.origin.y);

                position1 = position2;
                position2+=increment;
                vec+=channels*bytesPerchannel;
            }
            edk::GU::guEnd();
            break;
        case 2u:
            //GA
            edk::GU::guBegin(GU_QUADS);
            for(edk::uint32 i=0u;i<sizePalette;i++){
                g=a=0u;
                edkMemCpy(&g,&vec[0u*bytesPerchannel],bytesPerchannel);
                edkMemCpy(&a,&vec[1u*bytesPerchannel],bytesPerchannel);
                edk::GU::guColor4f32(g/(edk::float32)(0xFF*bytesPerchannel),
                                     g/(edk::float32)(0xFF*bytesPerchannel),
                                     g/(edk::float32)(0xFF*bytesPerchannel),
                                     a/(edk::float32)(0xFF*bytesPerchannel)
                                     );
                //X1 Y1
                edk::GU::guVertex2f32(position1,rect.origin.y);
                //X1 Y2
                edk::GU::guVertex2f32(position1,rect.size.height);
                //X2 Y2
                edk::GU::guVertex2f32(position2,rect.size.height);
                //X2 Y1
                edk::GU::guVertex2f32(position2,rect.origin.y);

                position1 = position2;
                position2+=increment;
                vec+=channels*bytesPerchannel;
            }
            edk::GU::guEnd();
            break;
        case 3u:
            //RGB
            edk::GU::guBegin(GU_QUADS);
            for(edk::uint32 i=0u;i<sizePalette;i++){
                r=g=b=0u;
                edkMemCpy(&r,&vec[0u*bytesPerchannel],bytesPerchannel);
                edkMemCpy(&g,&vec[1u*bytesPerchannel],bytesPerchannel);
                edkMemCpy(&b,&vec[2u*bytesPerchannel],bytesPerchannel);
                edk::GU::guColor4f32(r/(edk::float32)(0xFF*bytesPerchannel),
                                     g/(edk::float32)(0xFF*bytesPerchannel),
                                     b/(edk::float32)(0xFF*bytesPerchannel),
                                     1.f
                                     );
                //X1 Y1
                edk::GU::guVertex2f32(position1,rect.origin.y);
                //X1 Y2
                edk::GU::guVertex2f32(position1,rect.size.height);
                //X2 Y2
                edk::GU::guVertex2f32(position2,rect.size.height);
                //X2 Y1
                edk::GU::guVertex2f32(position2,rect.origin.y);

                position1 = position2;
                position2+=increment;
                vec+=channels*bytesPerchannel;
            }
            edk::GU::guEnd();
            break;
        case 4u:
            //RGBA
            edk::GU::guBegin(GU_QUADS);
            for(edk::uint32 i=0u;i<sizePalette;i++){
                r=g=b=a=0u;
                edkMemCpy(&r,&vec[0u*bytesPerchannel],bytesPerchannel);
                edkMemCpy(&g,&vec[1u*bytesPerchannel],bytesPerchannel);
                edkMemCpy(&b,&vec[2u*bytesPerchannel],bytesPerchannel);
                edkMemCpy(&a,&vec[3u*bytesPerchannel],bytesPerchannel);
                edk::GU::guColor4f32(r/(edk::float32)(0xFF*bytesPerchannel),
                                     g/(edk::float32)(0xFF*bytesPerchannel),
                                     b/(edk::float32)(0xFF*bytesPerchannel),
                                     a/(edk::float32)(0xFF*bytesPerchannel)
                                     );
                //X1 Y1
                edk::GU::guVertex2f32(position1,rect.origin.y);
                //X1 Y2
                edk::GU::guVertex2f32(position1,rect.size.height);
                //X2 Y2
                edk::GU::guVertex2f32(position2,rect.size.height);
                //X2 Y1
                edk::GU::guVertex2f32(position2,rect.origin.y);

                position1 = position2;
                position2+=increment;
                vec+=channels*bytesPerchannel;
            }
            edk::GU::guEnd();
            break;
        }

        //draw grade
        position1 = rect.origin.x;
        edk::GU::guColor4f32(0.f,
                             0.f,
                             0.f,
                             1.f
                             );
        edk::GU::guLineWidth(2u);
        edk::GU::guBegin(GU_LINES);

        edk::GU::guVertex2f32(rect.origin.x,rect.origin.y);
        edk::GU::guVertex2f32(rect.size.width,rect.origin.y);
        edk::GU::guVertex2f32(rect.origin.x,rect.size.height);
        edk::GU::guVertex2f32(rect.size.width,rect.size.height);

        for(edk::uint32 i=0u;i<=sizePalette;i++){
            //X1 Y1
            edk::GU::guVertex2f32(position1,rect.origin.y);
            //X1 Y2
            edk::GU::guVertex2f32(position1,rect.size.height);

            position1+=increment;
        }
        edk::GU::guEnd();
        edk::GU::guLineWidth(1u);


        //draw selectinMove
        if(this->selectingMove){
            //
            position1 = rect.origin.x + (increment * this->movingIdEnd);
            position2 = position1 + increment;
            edk::GU::guColor4f32(0.f,
                                 1.f,
                                 0.f,
                                 1.f
                                 );
            edk::GU::guLineWidth(4u);
            edk::GU::guBegin(GU_LINE_STRIP);

            edk::GU::guVertex2f32(position1,rect.origin.y);
            edk::GU::guVertex2f32(position1,rect.size.height);

            edk::GU::guVertex2f32(position1,rect.size.height);
            edk::GU::guVertex2f32(position2,rect.size.height);

            edk::GU::guVertex2f32(position2,rect.size.height);
            edk::GU::guVertex2f32(position2,rect.origin.y);

            edk::GU::guVertex2f32(position1,rect.origin.y);
            edk::GU::guVertex2f32(position2,rect.origin.y);

            edk::GU::guEnd();
            edk::GU::guLineWidth(1u);
        }

    }
}
void edk::retro::RetroViewPaletteEdit::drawSelectionScene(){
    if(this->palette->havePalette()){
        edk::uint32 sizePalette = this->palette->getSize();
        edk::uint8* vec = this->palette->getPalette();
        edk::uint8 channels = this->palette->getChannels();
        edk::uint8 bytesPerchannel = this->palette->getBytesPerChannel();
        edk::rectf32 rect;
        rect.origin.x = (this->frame.size.height * sizePalette) * -0.5f;
        rect.size.width = (this->frame.size.height * sizePalette) * +0.5f;
        rect.origin.y = this->frame.size.height * -0.5f;
        rect.size.height = this->frame.size.height * +0.5f;

        edk::float32 increment = (rect.size.width-rect.origin.x)*1.f/(edk::float32)sizePalette;
        edk::float32 position1 = rect.origin.x;
        edk::float32 position2 = rect.origin.x + increment;

        edk::GU::guPushName(1u);
        //draw the quads
        for(edk::uint32 i=0u;i<sizePalette;i++){
            edk::GU::guPushName(i);
            edk::GU::guBegin(GU_QUADS);
            //X1 Y1
            edk::GU::guVertex2f32(position1,rect.origin.y);
            //X1 Y2
            edk::GU::guVertex2f32(position1,rect.size.height);
            //X2 Y2
            edk::GU::guVertex2f32(position2,rect.size.height);
            //X2 Y1
            edk::GU::guVertex2f32(position2,rect.origin.y);

            position1 = position2;
            position2+=increment;
            vec+=channels*bytesPerchannel;
            edk::GU::guEnd();
            edk::GU::guPopName();
        }
        edk::GU::guPopName();
    }
}

