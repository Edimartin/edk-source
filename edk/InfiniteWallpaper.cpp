#include "InfiniteWallpaper.h"

edk::InfiniteWallpaper::InfiniteWallpaper(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::InfiniteWallpaper::~InfiniteWallpaper(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->clean();edkEnd();
    }
}

void edk::InfiniteWallpaper::Constructor(bool /*runFather*/){
    //
    if(this->classThis!=this){
        this->classThis=this;

        this->stack.Constructor();
        this->clock.Constructor();
        this->matrix.Constructor();
        this->obj.Constructor();

        this->percent=0.f;edkEnd();
        this->translate=0.f;edkEnd();
        this->clock.start();edkEnd();
        this->saveLenght = 0u;edkEnd();
        this->cleanLimit();edkEnd();
    }
}

//change the status
void edk::InfiniteWallpaper::changeStatus(){
    edk::uint32 size = this->stack.size();edkEnd();
    edk::InfiniteWallpaper::WallpaperObject* temp;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->stack.get(i);edkEnd();
        if(temp){
            temp->obj.size = this->saveSize;edkEnd();
        }
    }
}
void edk::InfiniteWallpaper::changeSize(){
    this->saveSize = this->size;edkEnd();
    this->changeStatus();edkEnd();
}

//clean wallpapers
void edk::InfiniteWallpaper::clean(){
    edk::uint32 size = this->stack.size();edkEnd();
    edk::InfiniteWallpaper::WallpaperObject* temp;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->stack.get(i);edkEnd();
        if(temp){
            temp->obj.cleanMeshes();edkEnd();
            delete temp;edkEnd();
        }
    }
    this->stack.clean();edkEnd();
    this->translate=0.f;edkEnd();
    this->matrix.deleteMatrix();edkEnd();
    this->saveLenght=0u;edkEnd();
}
//add new wallpaper
//filter
//GU_NEAREST
//GU_LINEAR
//GU_NEAREST_MIPMAP_NEAREST
//GU_NEAREST_MIPMAP_LINEAR
//GU_LINEAR_MIPMAP_NEAREST
//GU_LINEAR_MIPMAP_LINEAR
bool edk::InfiniteWallpaper::newWallpaper(edk::char8* name,edk::uint32 drawTimes,edk::uint32 filter){
    if(name){
        edk::InfiniteWallpaper::WallpaperObject* temp = new edk::InfiniteWallpaper::WallpaperObject(drawTimes);edkEnd();
        if(temp){
            //create a new mesh
            edk::shape::Mesh2D* mesh = temp->obj.newMesh();edkEnd();
            if(mesh){
                edk::shape::Rectangle2D rect;edkEnd();
                rect.setPivoToCenter();edkEnd();
                mesh->addPolygon(rect);edkEnd();
                if(mesh->material.loadTexture(name,0u,filter)){
                    //add the temp in to the stack
                    edk::uint32 size = this->stack.size();edkEnd();
                    this->stack.pushBack(temp);edkEnd();
                    if(size < this->stack.size()){
                        temp->obj.size=this->size;edkEnd();
                        return true;
                    }
                }
                temp->obj.cleanMeshes();edkEnd();
            }
            delete temp;edkEnd();
        }
    }
    return false;
}
bool edk::InfiniteWallpaper::newWallpaper(const edk::char8* name,edk::uint32 drawTimes,edk::uint32 filter){
    return newWallpaper((edk::char8*) name,drawTimes,filter);edkEnd();
}
bool edk::InfiniteWallpaper::newWallpaperFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 drawTimes,edk::uint32 filter){
    if(name){
        edk::InfiniteWallpaper::WallpaperObject* temp = new edk::InfiniteWallpaper::WallpaperObject(drawTimes);edkEnd();
        if(temp){
            //create a new mesh
            edk::shape::Mesh2D* mesh = temp->obj.newMesh();edkEnd();
            if(mesh){
                edk::shape::Rectangle2D rect;edkEnd();
                rect.setPivoToCenter();edkEnd();
                mesh->addPolygon(rect);edkEnd();
                if(mesh->material.loadTextureFromMemory(name,image,size,0u,filter)){
                    //add the temp in to the stack
                    edk::uint32 size = this->stack.size();edkEnd();
                    this->stack.pushBack(temp);edkEnd();
                    if(size < this->stack.size()){
                        temp->obj.size=this->size;edkEnd();
                        return true;
                    }
                }
                temp->obj.cleanMeshes();edkEnd();
            }
            delete temp;edkEnd();
        }
    }
    return false;
}
bool edk::InfiniteWallpaper::newWallpaperFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 drawTimes,edk::uint32 filter){
    return this->newWallpaperFromMemory((edk::char8*) name,image,size,drawTimes,filter);edkEnd();
}
bool edk::InfiniteWallpaper::newWallpaperFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 drawTimes,edk::uint32 filter){
    if(name){
        edk::InfiniteWallpaper::WallpaperObject* temp = new edk::InfiniteWallpaper::WallpaperObject(drawTimes);edkEnd();
        if(temp){
            //create a new mesh
            edk::shape::Mesh2D* mesh = temp->obj.newMesh();edkEnd();
            if(mesh){
                edk::shape::Rectangle2D rect;edkEnd();
                rect.setPivoToCenter();edkEnd();
                mesh->addPolygon(rect);edkEnd();
                if(mesh->material.loadTextureFromPack(pack,name,0u,filter)){
                    //add the temp in to the stack
                    edk::uint32 size = this->stack.size();edkEnd();
                    this->stack.pushBack(temp);edkEnd();
                    if(size < this->stack.size()){
                        temp->obj.size=this->size;edkEnd();
                        return true;
                    }
                }
                temp->obj.cleanMeshes();edkEnd();
            }
            delete temp;edkEnd();
        }
    }
    return false;
}
bool edk::InfiniteWallpaper::newWallpaperFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 drawTimes,edk::uint32 filter){
    return this->newWallpaperFromPack(pack,(edk::char8*) name,drawTimes,filter);edkEnd();
}
//clone a wallpaper from an object
bool edk::InfiniteWallpaper::newWallpaperFromObject2D(edk::Object2D* obj,edk::uint32 drawTimes){
    if(obj){
        //create a new object
        edk::InfiniteWallpaper::WallpaperObject* temp = new edk::InfiniteWallpaper::WallpaperObject(drawTimes);edkEnd();
        if(temp){
            //clone the temp from object
            if(temp->obj.cloneFrom(obj)){
                //push back the object
                edk::uint32 size = this->stack.size();edkEnd();
                this->stack.pushBack(temp);edkEnd();
                if(size < this->stack.size()){
                    temp->obj.size=this->size;edkEnd();
                    return true;
                }
            }
            delete temp;edkEnd();
        }
    }
    return false;
}

//set the speed of the wallpaper
void edk::InfiniteWallpaper::setSpeed(edk::vec2f32 speed){
    this->speed = speed;edkEnd();
}
void edk::InfiniteWallpaper::setSpeed(edk::float32 x,edk::float32 y){
    return this->setSpeed(edk::vec2f32(x,y));edkEnd();
}
void edk::InfiniteWallpaper::setSpeedX(edk::float32 speedX){
    this->speed.x = speedX;edkEnd();
}
void edk::InfiniteWallpaper::setSpeedY(edk::float32 speedY){
    this->speed.y = speedY;edkEnd();
}

//set the sizeLimit
void edk::InfiniteWallpaper::setLimit(edk::size2ui32 size){
    this->sizeLimit=size;edkEnd();
}
void edk::InfiniteWallpaper::setLimitWidth(edk::uint32 width){
    this->sizeLimit.width = width;edkEnd();
}
void edk::InfiniteWallpaper::setLimitHeight(edk::uint32 height){
    this->sizeLimit.height = height;edkEnd();
}
void edk::InfiniteWallpaper::cleanLimit(){
    this->sizeLimit=0u;edkEnd();
}
void edk::InfiniteWallpaper::cleanLimitWidth(){
    this->sizeLimit.width = 0u;edkEnd();
}
void edk::InfiniteWallpaper::cleanLimitHeight(){
    this->sizeLimit.height = 0u;edkEnd();
}

#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
edk::uint32 counter=0u;
#endif
void edk::InfiniteWallpaper::update(edk::float32 runMove,edk::float32 seconds){
    if(seconds<0.f){
        seconds*=-1.f;edkEnd();
    }
    //update the size
    if(this->saveSize!=this->size){
        this->changeSize();edkEnd();
    }
    //
    this->translate.x+=this->speed.x*runMove * seconds;edkEnd();
    this->translate.y+=this->speed.y*runMove * seconds *-1;edkEnd();

    bool changeXNegative;edkEnd();
    bool changeXPositive;edkEnd();
    bool changeYNegative;edkEnd();
    bool changeYPositive;edkEnd();

    do{
        changeXNegative=false;edkEnd();
        changeXPositive=false;edkEnd();
        changeYNegative=false;edkEnd();
        changeYPositive=false;edkEnd();
        //test if the translate is bigger then the size
        if(this->translate.x > this->size.width){
            if(this->matrix.width()==1u){
                this->translate.x = this->size.width;edkEnd();
            }
            else{
                this->translate.x -= this->size.width;edkEnd();
                //change the matrix in X
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                printf("\n\n%u",counter++);edkEnd();
#endif
                changeXPositive=true;edkEnd();
            }
        }
        if(this->matrix.width()==1u){
            if(this->translate.x < 0.f){
                this->translate.x = 0.f;edkEnd();
            }
        }
        else{
            if(this->translate.x < this->size.width*-1.f){
                this->translate.x += this->size.width;edkEnd();
                //change the matrix
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                printf("\n\n%u",counter++);edkEnd();
#endif
                changeXNegative=true;edkEnd();
            }
        }
        if(this->translate.y > this->size.height){
            if(this->matrix.height()==1u){
                this->translate.y = this->size.height;edkEnd();
            }
            else{
                this->translate.y -= this->size.height;edkEnd();
                //change the matrix
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                printf("\n\n%u",counter++);edkEnd();
#endif
                changeYPositive=true;edkEnd();
            }
        }
        if(this->matrix.height()==1u){
            if(this->translate.y < 0.f){
                this->translate.y = 0.f;edkEnd();
            }
        }
        else{
            if(this->translate.y < this->size.height*-1.f){
                this->translate.y += this->size.height;edkEnd();
                //change the matrix
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                printf("\n\n%u",counter++);edkEnd();
#endif
                changeYNegative=true;edkEnd();
            }
        }

        //test if need to change the matrix values
        if(changeXPositive){
            if(changeYPositive){
                //XPositive YPositive
            }
            else if(changeYNegative){
                //XPositive YNegative
            }
            else{
                //just X Positive
                if(this->matrix.haveMatrix() && this->stack.size()){
                    edk::size2ui32 size = this->matrix.size();edkEnd();
                    edk::InfiniteWallpaper::WallpaperObject* temp = NULL;edkEnd();
                    edk::uint32 position;edkEnd();
                    edk::uint32 savePosition;edkEnd();
                    bool runIncreDecre=false;edkEnd();

                    if(size.width){
                        for(edk::uint32 y=0u;y<size.height;y++){
                            position = this->matrix.get(size.width-1u,y);edkEnd();
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                            printf("\n%u %s %s this->matrix.remove((size.width[%u]-1u)[%u],y[%u])[%u];edkEnd();",__LINE__,__FILE__,__func__
                                   ,size.width
                                   ,size.width-1u
                                   ,y
                                   ,position
                                   );edkEnd();
#endif
                            temp = this->stack.get(position);edkEnd();
                            if(temp){
                                //
                                if(temp->getDrawTimes()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                    printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                    temp->incrementDraw();edkEnd();
                                    temp->haveRemoved=false;edkEnd();
                                }
                            }


                            //test with the neighbours
                            if(size.width>1u){
                                savePosition = this->matrix.get(size.width-2u,y);edkEnd();
                                if(savePosition<position){
                                    for(edk::uint32 i = position-1u;i>savePosition;i--){
                                        temp = this->stack.get(i);edkEnd();
                                        if(temp){
                                            //
                                            if(temp->getDrawTimes()){
                                                if(temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                    printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                                    temp->incrementDraw();edkEnd();
                                                    temp->haveRemoved=false;edkEnd();
                                                }
                                                else{
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                                else{
                                    for(edk::uint32 i = position;i>0u;i--){
                                        temp = this->stack.get(i-1u);edkEnd();
                                        if(temp){
                                            //
                                            if(temp->getDrawTimes()){
                                                if(!temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                    printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                                    temp->incrementDraw();edkEnd();
                                                    temp->haveRemoved=false;edkEnd();
                                                }
                                                else{
                                                    runIncreDecre=true;edkEnd();
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    if(!runIncreDecre){
                                        for(edk::uint32 i = this->stack.size()-1u;i>savePosition;i--){
                                            temp = this->stack.get(i);edkEnd();
                                            if(temp){
                                                //
                                                if(temp->getDrawTimes()){
                                                    if(!temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                        printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                                        temp->incrementDraw();edkEnd();
                                                        temp->haveRemoved=false;edkEnd();
                                                    }
                                                    else{
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    runIncreDecre=false;edkEnd();
                                }

                            }
                        }
                    }

                    for(edk::uint32 x=size.width;x>0u;x--){
                        for(edk::uint32 y=0u;y<size.height;y++){
                            this->matrix.set(x-1u,y,this->matrix.get(x-2u,y));edkEnd();
                        }
                    }
                    //in the end it fill the first matrix values
                    for(edk::uint32 y=0u;y<size.height;y++){
                        position = this->matrix.get(1u,y);edkEnd();
                        if(position==0u){
                            position = this->stack.size()-1u;edkEnd();
                        }
                        else{
                            position--;edkEnd();
                        }
                        savePosition = position;edkEnd();
                        for(;;){
                            temp = this->stack.get(position);edkEnd();
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                            printf("\n%u %s %s try([%u])'%s'",__LINE__,__FILE__,__func__
                                   ,position
                                   ,temp?"true":"false"
                                         );edkEnd();
#endif
                            if(temp){
                                if(temp->getDrawTimes()){
                                    if(temp->isMinusDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                        printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                        temp->incrementDraw();edkEnd();
                                        runIncreDecre=true;edkEnd();
                                    }
                                }
                                //test if can draw
                                if(temp->canDraw()){
                                    if(!temp->haveRemoved){
                                        if(temp->getDrawTimes()){
                                            //temp->incrementDraw();edkEnd();
                                        }
                                    }
                                    break;
                                }
                                else{
                                    if(!temp->haveRemoved){
                                        if(temp->getDrawTimes()){
                                            if(!runIncreDecre){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                                temp->incrementDraw();edkEnd();
                                            }
                                        }
                                    }
                                }
                                temp->haveRemoved=false;edkEnd();
                                runIncreDecre=false;edkEnd();
                            }
                            if(position==0u){
                                position = this->stack.size()-1u;edkEnd();
                            }
                            else{
                                position--;edkEnd();
                            }
                            if(position==savePosition){
                                break;
                            }
                        }
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                        printf("\n%u %s %s this->matrix.set(0[%u],y[%u],position[%u]);edkEnd();",__LINE__,__FILE__,__func__
                               ,0
                               ,y
                               ,position
                               );edkEnd();
#endif
                        this->matrix.set(0u,y,position);edkEnd();
                    }
                }
            }
        }
        else if(changeXNegative){
            if(changeYPositive){
                //XPositive YPositive
            }
            else if(changeYNegative){
                //XPositive YNegative
            }
            else{
                //just X Negative
                if(this->matrix.haveMatrix() && this->stack.size()){
                    edk::size2ui32 size = this->matrix.size();edkEnd();
                    if(size.width>1u){
                        edk::uint32 position;edkEnd();
                        edk::uint32 savePosition;edkEnd();
                        bool runIncreDecre=false;edkEnd();
                        edk::InfiniteWallpaper::WallpaperObject* temp = NULL;edkEnd();

                        for(edk::uint32 y=0u;y<size.height;y++){
                            position = this->matrix.get(0u,y);edkEnd();
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                            printf("\n%u %s %s this->matrix.remove(0u[%u],y[%u])[%u];edkEnd();",__LINE__,__FILE__,__func__
                                   ,0u
                                   ,y
                                   ,position
                                   );edkEnd();
#endif
                            temp = this->stack.get(position);edkEnd();
                            if(temp){
                                //decrement the draw from TEMP
                                if(temp->getDrawTimes()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                    printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                    temp->decrementDraw();edkEnd();
                                    temp->haveRemoved=false;edkEnd();
                                }
                            }


                            //test with the neighbours
                            savePosition = this->matrix.get(1u,y);edkEnd();
                            if(savePosition>position){
                                for(edk::uint32 i = position+1u;i<savePosition;i++){
                                    temp = this->stack.get(i);edkEnd();
                                    if(temp){
                                        //
                                        if(temp->getDrawTimes()){
                                            if(temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                                temp->decrementDraw();edkEnd();
                                                temp->haveRemoved=false;edkEnd();
                                            }
                                            else{
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            else{
                                for(edk::uint32 i = position+1u;i<this->stack.size();i++){
                                    temp = this->stack.get(i);edkEnd();
                                    if(temp){
                                        //
                                        if(temp->getDrawTimes()){
                                            if(!temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                                temp->decrementDraw();edkEnd();
                                                temp->haveRemoved=false;edkEnd();
                                            }
                                            else{
                                                runIncreDecre=true;edkEnd();
                                                break;
                                            }
                                        }
                                    }
                                }
                                if(!runIncreDecre){
                                    for(edk::uint32 i = 0u;i<savePosition;i++){
                                        temp = this->stack.get(i);edkEnd();
                                        if(temp){
                                            //
                                            if(temp->getDrawTimes()){
                                                if(!temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                    printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                                    temp->decrementDraw();edkEnd();
                                                    temp->haveRemoved=false;edkEnd();
                                                }
                                                else{
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                                runIncreDecre=false;edkEnd();
                            }

                        }

                        size.width--;edkEnd();
                        for(edk::uint32 x=0;x<size.width;x++){
                            for(edk::uint32 y=0u;y<size.height;y++){
                                this->matrix.set(x,y,this->matrix.get(x+1u,y));edkEnd();
                            }
                        }
                        //in the end it fill the first matrix values
                        for(edk::uint32 y=0u;y<size.height;y++){
                            position = this->matrix.get(size.width-1u,y) + 1u;edkEnd();
                            if(this->stack.size()<=position){
                                position=0u;edkEnd();
                            }
                            savePosition = position;edkEnd();
                            for(;;){
                                temp = this->stack.get(position);edkEnd();
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                printf("\n%u %s %s try([%u])'%s'",__LINE__,__FILE__,__func__
                                       ,position
                                       ,temp?"true":"false"
                                             );edkEnd();
#endif
                                if(temp){
                                    if(temp->getDrawTimes()){
                                        if(!temp->isMinusDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                            printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                            temp->decrementDraw();edkEnd();
                                            runIncreDecre=true;edkEnd();
                                        }
                                    }
                                    //test if can draw
                                    if(temp->canDraw()){
                                        if(!temp->haveRemoved){
                                            if(temp->getDrawTimes()){
                                                //temp->decrementDraw();edkEnd();
                                            }
                                        }
                                        break;
                                    }
                                    else{
                                        if(!temp->haveRemoved){
                                            if(temp->getDrawTimes()){
                                                if(!runIncreDecre){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                    printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                                    temp->decrementDraw();edkEnd();
                                                }
                                            }
                                        }
                                    }
                                    temp->haveRemoved=false;edkEnd();
                                    runIncreDecre=false;edkEnd();
                                }
                                position++;edkEnd();
                                if(this->stack.size()<=position){
                                    position=0u;edkEnd();
                                }
                                if(position==savePosition){
                                    break;
                                }
                            }
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                            printf("\n%u %s %s this->matrix.set(size.width[%u],y[%u],position[%u]);edkEnd();",__LINE__,__FILE__,__func__
                                   ,size.width
                                   ,y
                                   ,position
                                   );edkEnd();
#endif
                            this->matrix.set(size.width,y,position);edkEnd();
                        }
                    }
                }
            }
        }
        else if(changeYPositive){
            //just Y Positive
            if(this->matrix.haveMatrix() && this->stack.size()){
                edk::size2ui32 size = this->matrix.size();edkEnd();
                edk::InfiniteWallpaper::WallpaperObject* temp = NULL;edkEnd();
                edk::uint32 position;edkEnd();
                edk::uint32 savePosition;edkEnd();
                bool runIncreDecre=false;edkEnd();

                for(edk::uint32 x=0u;x<size.width;x++){
                    position = this->matrix.get(x,size.height-1u);edkEnd();
                    temp = this->stack.get(position);edkEnd();
                    if(temp){
                        //decrement the draw from TEMP
                        if(temp->getDrawTimes()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                            printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                            temp->incrementDraw();edkEnd();
                            temp->haveRemoved=false;edkEnd();
                        }
                    }


                    //test with the neighbours
                    if(size.height>1u){
                        savePosition = this->matrix.get(x,size.height-2u);edkEnd();
                        if(savePosition<position){
                            for(edk::uint32 i = position-1u;i>savePosition;i--){
                                temp = this->stack.get(i);edkEnd();
                                if(temp){
                                    //
                                    if(temp->getDrawTimes()){
                                        if(temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                            printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                            temp->incrementDraw();edkEnd();
                                            temp->haveRemoved=false;edkEnd();
                                        }
                                        else{
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        else{
                            for(edk::uint32 i = position;i>0u;i--){
                                temp = this->stack.get(i-1u);edkEnd();
                                if(temp){
                                    //
                                    if(temp->getDrawTimes()){
                                        if(!temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                            printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                            temp->incrementDraw();edkEnd();
                                            temp->haveRemoved=false;edkEnd();
                                        }
                                        else{
                                            runIncreDecre=true;edkEnd();
                                            break;
                                        }
                                    }
                                }
                            }
                            if(!runIncreDecre){
                                for(edk::uint32 i = this->stack.size()-1u;i>savePosition;i--){
                                    temp = this->stack.get(i);edkEnd();
                                    if(temp){
                                        //
                                        if(temp->getDrawTimes()){
                                            if(!temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                                temp->incrementDraw();edkEnd();
                                                temp->haveRemoved=false;edkEnd();
                                            }
                                            else{
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            runIncreDecre=false;edkEnd();
                        }

                    }
                }

                for(edk::uint32 y=size.width;y>0u;y--){
                    for(edk::uint32 x=0u;x<size.width;x++){
                        this->matrix.set(x,y-1u,this->matrix.get(x,y-2u));edkEnd();
                    }
                }
                //in the end it fill the first matrix values
                for(edk::uint32 x=0u;x<size.width;x++){
                    position = this->matrix.get(x,1u);edkEnd();
                    if(position==0u){
                        position = this->stack.size()-1u;edkEnd();
                    }
                    else{
                        position--;edkEnd();
                    }
                    savePosition = position;edkEnd();
                    for(;;){
                        temp = this->stack.get(position);edkEnd();
                        if(temp){
                            if(temp->getDrawTimes()){
                                if(temp->isMinusDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                    printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                    temp->incrementDraw();edkEnd();
                                    runIncreDecre=true;edkEnd();
                                }
                            }
                            //test if can draw
                            if(temp->canDraw()){
                                if(!temp->haveRemoved){
                                    if(temp->getDrawTimes()){
                                        //temp->incrementDraw();edkEnd();
                                    }
                                }
                                break;
                            }
                            else{
                                if(!temp->haveRemoved){
                                    if(temp->getDrawTimes()){
                                        if(!runIncreDecre){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                            printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                            temp->incrementDraw();edkEnd();
                                        }
                                    }
                                }
                            }
                            temp->haveRemoved=false;edkEnd();
                            runIncreDecre=false;edkEnd();
                        }
                        if(position==0u){
                            position = this->stack.size()-1u;edkEnd();
                        }
                        else{
                            position--;edkEnd();
                        }
                        if(position==savePosition){
                            break;
                        }
                    }
                    this->matrix.set(x,0u,position);edkEnd();
                }
            }
        }
        else if(changeYNegative){
            //just Y Negative
            if(this->matrix.haveMatrix() && this->stack.size()){
                edk::size2ui32 size = this->matrix.size();edkEnd();
                if(size.height>1u){
                    edk::uint32 position;edkEnd();
                    edk::uint32 savePosition;edkEnd();
                    bool runIncreDecre=false;edkEnd();
                    edk::InfiniteWallpaper::WallpaperObject* temp = NULL;edkEnd();

                    for(edk::uint32 x=0u;x<size.width;x++){
                        position = this->matrix.get(x,0u);edkEnd();
                        temp = this->stack.get(position);edkEnd();
                        if(temp){
                            //decrement the draw from TEMP
                            if(temp->getDrawTimes()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                temp->decrementDraw();edkEnd();
                                temp->haveRemoved=false;edkEnd();
                            }
                        }


                        //test with the neighbours
                        savePosition = this->matrix.get(x,1u);edkEnd();
                        if(savePosition>position){
                            for(edk::uint32 i = position+1u;i<savePosition;i++){
                                temp = this->stack.get(i);edkEnd();
                                if(temp){
                                    //
                                    if(temp->getDrawTimes()){
                                        if(temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                            printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                            temp->decrementDraw();edkEnd();
                                            temp->haveRemoved=false;edkEnd();
                                        }
                                        else{
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        else{
                            for(edk::uint32 i = position+1u;i<this->stack.size();i++){
                                temp = this->stack.get(i);edkEnd();
                                if(temp){
                                    //
                                    if(temp->getDrawTimes()){
                                        if(!temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                            printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                            temp->decrementDraw();edkEnd();
                                            temp->haveRemoved=false;edkEnd();
                                        }
                                        else{
                                            runIncreDecre=true;edkEnd();
                                            break;
                                        }
                                    }
                                }
                            }
                            if(!runIncreDecre){
                                for(edk::uint32 i = 0u;i<savePosition;i++){
                                    temp = this->stack.get(i);edkEnd();
                                    if(temp){
                                        //
                                        if(temp->getDrawTimes()){
                                            if(!temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                                temp->decrementDraw();edkEnd();
                                                temp->haveRemoved=false;edkEnd();
                                            }
                                            else{
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            runIncreDecre=false;edkEnd();
                        }

                    }

                    size.height--;edkEnd();
                    for(edk::uint32 y=0;y<size.height;y++){
                        for(edk::uint32 x=0u;x<size.width;x++){
                            this->matrix.set(x,y,this->matrix.get(x,y+1u));edkEnd();
                        }
                    }
                    //in the end it fill the first matrix values
                    for(edk::uint32 x=0u;x<size.width;x++){
                        position = this->matrix.get(x,size.height-1u) + 1u;edkEnd();
                        if(this->stack.size()<=position){
                            position=0u;edkEnd();
                        }
                        savePosition = position;edkEnd();
                        for(;;){
                            temp = this->stack.get(position);edkEnd();
                            if(temp){
                                if(temp->getDrawTimes()){
                                    if(!temp->isMinusDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                        printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                        temp->decrementDraw();edkEnd();
                                        runIncreDecre=true;edkEnd();
                                    }
                                }
                                //test if can draw
                                if(temp->canDraw()){
                                    if(!temp->haveRemoved){
                                        if(temp->getDrawTimes()){
                                            //temp->decrementDraw();edkEnd();
                                        }
                                    }
                                    break;
                                }
                                else{
                                    if(!temp->haveRemoved){
                                        if(temp->getDrawTimes()){
                                            if(!runIncreDecre){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                printf("\n%u %s %s",__LINE__,__FILE__,__func__);edkEnd();
#endif
                                                temp->decrementDraw();edkEnd();
                                            }
                                        }
                                    }
                                }
                                temp->haveRemoved=false;edkEnd();
                                runIncreDecre=false;edkEnd();
                            }
                            position++;edkEnd();
                            if(this->stack.size()<=position){
                                position=0u;edkEnd();
                            }
                            if(position==savePosition){
                                break;
                            }
                        }
                        this->matrix.set(x,size.height,position);edkEnd();
                    }
                }
            }
        }
    }while(changeXNegative||
           changeXPositive||
           changeYNegative||
           changeYPositive
           );edkEnd();
}
void edk::InfiniteWallpaper::update(edk::float32 runMove){
    this->update(runMove,this->clock.getSeconds());edkEnd();
    this->clock.start();edkEnd();
}
void edk::InfiniteWallpaper::update(edk::vec2f32 runMove,edk::float32 seconds){
    //save the speed
    edk::vec2f32 speed = this->speed;edkEnd();
    //update the speed
    this->speed = runMove;edkEnd();
    //run the update
    this->update(1.f,seconds);edkEnd();
    //paste the speed
    this->speed = speed;edkEnd();
}
void edk::InfiniteWallpaper::update(edk::vec2f32 runMove){
    this->update(runMove,this->clock.getSeconds());edkEnd();
    this->clock.start();edkEnd();
}

//draw the wallpaper
void edk::InfiniteWallpaper::drawInsideRect(edk::rectf32 rect){
    //
    edk::vec2i32 lenght = edk::vec2i32((edk::int32)(rect.size.width / this->size.width),
                                       (edk::int32)(rect.size.height / this->size.height)
                                       ) + 1;edkEnd();
    edk::vec2i32 lenghtDouble;edkEnd();
    if(lenght.x<0){
        lenght.x*=-1;edkEnd();}

    if(lenght.y<0){
        lenght.y*=-1;edkEnd();
    }

    lenghtDouble = lenght +2;edkEnd();

    //test if lenght is bigger than the sizeLimit
    if(this->sizeLimit.width != 0u){
        //test the X
        if(lenghtDouble.x > (edk::int32)this->sizeLimit.width){
            //
            lenghtDouble.x = (edk::int32)this->sizeLimit.width;edkEnd();
            lenght.x = lenghtDouble.x/2u;edkEnd();
            if(!lenght.x){
                lenght.x=1;edkEnd();
            }
        }
    }
    if(this->sizeLimit.height != 0u){
        //test the Y
        if(lenghtDouble.y > (edk::int32)this->sizeLimit.height){
            //
            lenghtDouble.y = (edk::int32)this->sizeLimit.height;edkEnd();
            lenght.y = lenghtDouble.y/2u;edkEnd();
            if(!lenght.y){
                lenght.y=1;edkEnd();
            }
        }
    }


    if(this->matrix.width()!=(edk::uint32)lenghtDouble.x
            ||
            this->matrix.height()!=(edk::uint32)lenghtDouble.y
            ){
        //change the matrix
        this->matrix.createMatrix(lenghtDouble.x,lenghtDouble.y);edkEnd();

        edk::size2ui32 size = this->matrix.size();edkEnd();
        //fill the matrix with the wallpapers in X (temporary)
        edk::uint32 value = 0u;edkEnd();

        //decrement value
        if(this->stack.size()){
            for(edk::uint32 i=0u;i<(edk::uint32)lenght.x;i++){
                if(value){
                    value--;edkEnd();
                }
                else{
                    value = this->stack.size()-1u;edkEnd();
                }
            }
        }

        for(edk::uint32 x=0u;x<size.width;x++){
            for(edk::uint32 y=0;y<size.height;y++){
                this->matrix.set(x,y,value);edkEnd();
                value++;edkEnd();
                if(value>=this->stack.size()){
                    value=0u;
                }
            }
        }
    }


    if(this->stack.size()){
        edk::uint32 objPos=0u;
        edk::uint32 matrixValue=0u;
        edk::InfiniteWallpaper::WallpaperObject* temp = this->stack.get(objPos);edkEnd();
        if(this->matrix.haveMatrix()){
            edk::size2ui32 size = this->matrix.size();edkEnd();
            edk::int32 posX,posY;edkEnd();
            this->obj.size = this->size;edkEnd();
            this->obj.addMesh(temp->obj.getMesh(0u));edkEnd();
            if(lenghtDouble.x==1){
                lenght.x=0;edkEnd();
            }
            if(lenghtDouble.y==1){
                lenght.y=0;edkEnd();
            }
            posY=lenght.y*-1;edkEnd();
            for(edk::uint32 y=0u;y<size.height;y++){
                this->obj.position.y = this->position.y + (this->translate.y * -1.f) + (posY * this->size.height);edkEnd();
                posX=lenght.x*-1;edkEnd();
                for(edk::uint32 x=0u;x<size.width;x++){
                    this->obj.position.x = this->position.x + this->translate.x + (posX * this->size.width);edkEnd();
                    //test if need change the mesh
                    matrixValue = this->matrix.get(x,y);edkEnd();
                    if(matrixValue != objPos){
                        if((temp = this->stack.get(matrixValue))){
                            //chante the mesh
                            this->obj.cleanMeshes();edkEnd();
                            this->obj.addMesh(temp->obj.getMesh(0u));edkEnd();
                            objPos = matrixValue;edkEnd();
                        }
                    }
                    this->obj.draw();edkEnd();
                    posX++;edkEnd();
                }
                posY++;edkEnd();
            }
            this->obj.cleanMeshes();edkEnd();
        }
    }
}
void edk::InfiniteWallpaper::drawInsideSize(edk::vec2f32 position,edk::size2f32 size){
    this->drawInsideRect(edk::rectf32(position.x - (size.width*0.5f),
                                      position.y - (size.height*0.5f),
                                      position.x + (size.width*0.5f),
                                      position.y + (size.height*0.5f)
                                      )
                         );edkEnd();
}
