#include "InfiniteWallpaper.h"

edk::InfiniteWallpaper::InfiniteWallpaper(){
    //
    this->percent=0.f;
    this->translate=0.f;
    this->clock.start();
    this->saveLenght = 0u;
    this->cleanLimit();
}
edk::InfiniteWallpaper::~InfiniteWallpaper(){
    //
    this->clean();
}
//change the status
void edk::InfiniteWallpaper::changeStatus(){
    edk::uint32 size = this->stack.size();
    edk::InfiniteWallpaper::WallpaperObject* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->stack.get(i);
        if(temp){
            temp->obj.size = this->saveSize;
        }
    }
}
void edk::InfiniteWallpaper::changeSize(){
    this->saveSize = this->size;
    this->changeStatus();
}

//clean wallpapers
void edk::InfiniteWallpaper::clean(){
    edk::uint32 size = this->stack.size();
    edk::InfiniteWallpaper::WallpaperObject* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->stack.get(i);
        if(temp){
            temp->obj.cleanMeshes();
            delete temp;
        }
    }
    this->stack.clean();
    this->translate=0.f;
    this->matrix.deleteMatrix();
    this->saveLenght=0u;
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
        edk::InfiniteWallpaper::WallpaperObject* temp = new edk::InfiniteWallpaper::WallpaperObject(drawTimes);
        if(temp){
            //create a new mesh
            edk::shape::Mesh2D* mesh = temp->obj.newMesh();
            if(mesh){
                edk::shape::Rectangle2D rect;
                rect.setPivoToCenter();
                mesh->addPolygon(rect);
                if(mesh->material.loadTexture(name,0u,filter)){
                    //add the temp in to the stack
                    edk::uint32 size = this->stack.size();
                    this->stack.pushBack(temp);
                    if(size < this->stack.size()){
                        temp->obj.size=this->size;
                        return true;
                    }
                }
                temp->obj.cleanMeshes();
            }
            delete temp;
        }
    }
    return false;
}
bool edk::InfiniteWallpaper::newWallpaper(const edk::char8* name,edk::uint32 drawTimes,edk::uint32 filter){
    return newWallpaper((edk::char8*) name,drawTimes,filter);
}
bool edk::InfiniteWallpaper::newWallpaperFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 drawTimes,edk::uint32 filter){
    if(name){
        edk::InfiniteWallpaper::WallpaperObject* temp = new edk::InfiniteWallpaper::WallpaperObject(drawTimes);
        if(temp){
            //create a new mesh
            edk::shape::Mesh2D* mesh = temp->obj.newMesh();
            if(mesh){
                edk::shape::Rectangle2D rect;
                rect.setPivoToCenter();
                mesh->addPolygon(rect);
                if(mesh->material.loadTextureFromMemory(name,image,size,0u,filter)){
                    //add the temp in to the stack
                    edk::uint32 size = this->stack.size();
                    this->stack.pushBack(temp);
                    if(size < this->stack.size()){
                        temp->obj.size=this->size;
                        return true;
                    }
                }
                temp->obj.cleanMeshes();
            }
            delete temp;
        }
    }
    return false;
}
bool edk::InfiniteWallpaper::newWallpaperFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 drawTimes,edk::uint32 filter){
    return this->newWallpaperFromMemory((edk::char8*) name,image,size,drawTimes,filter);
}
bool edk::InfiniteWallpaper::newWallpaperFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 drawTimes,edk::uint32 filter){
    if(name){
        edk::InfiniteWallpaper::WallpaperObject* temp = new edk::InfiniteWallpaper::WallpaperObject(drawTimes);
        if(temp){
            //create a new mesh
            edk::shape::Mesh2D* mesh = temp->obj.newMesh();
            if(mesh){
                edk::shape::Rectangle2D rect;
                rect.setPivoToCenter();
                mesh->addPolygon(rect);
                if(mesh->material.loadTextureFromPack(pack,name,0u,filter)){
                    //add the temp in to the stack
                    edk::uint32 size = this->stack.size();
                    this->stack.pushBack(temp);
                    if(size < this->stack.size()){
                        temp->obj.size=this->size;
                        return true;
                    }
                }
                temp->obj.cleanMeshes();
            }
            delete temp;
        }
    }
    return false;
}
bool edk::InfiniteWallpaper::newWallpaperFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 drawTimes,edk::uint32 filter){
    return this->newWallpaperFromPack(pack,(edk::char8*) name,drawTimes,filter);
}
//clone a wallpaper from an object
bool edk::InfiniteWallpaper::newWallpaperFromObject2D(edk::Object2D* obj,edk::uint32 drawTimes){
    if(obj){
        //create a new object
        edk::InfiniteWallpaper::WallpaperObject* temp = new edk::InfiniteWallpaper::WallpaperObject(drawTimes);
        if(temp){
            //clone the temp from object
            if(temp->obj.cloneFrom(obj)){
                //push back the object
                edk::uint32 size = this->stack.size();
                this->stack.pushBack(temp);
                if(size < this->stack.size()){
                    temp->obj.size=this->size;
                    return true;
                }
            }
            delete temp;
        }
    }
    return false;
}

//set the speed of the wallpaper
void edk::InfiniteWallpaper::setSpeed(edk::vec2f32 speed){
    this->speed = speed;
}
void edk::InfiniteWallpaper::setSpeed(edk::float32 x,edk::float32 y){
    return this->setSpeed(edk::vec2f32(x,y));
}
void edk::InfiniteWallpaper::setSpeedX(edk::float32 speedX){
    this->speed.x = speedX;
}
void edk::InfiniteWallpaper::setSpeedY(edk::float32 speedY){
    this->speed.y = speedY;
}

//set the sizeLimit
void edk::InfiniteWallpaper::setLimit(edk::size2ui32 size){
    this->sizeLimit=size;
}
void edk::InfiniteWallpaper::setLimitWidth(edk::uint32 width){
    this->sizeLimit.width = width;
}
void edk::InfiniteWallpaper::setLimitHeight(edk::uint32 height){
    this->sizeLimit.height = height;
}
void edk::InfiniteWallpaper::cleanLimit(){
    this->sizeLimit=0u;
}
void edk::InfiniteWallpaper::cleanLimitWidth(){
    this->sizeLimit.width = 0u;
}
void edk::InfiniteWallpaper::cleanLimitHeight(){
    this->sizeLimit.height = 0u;
}

#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
edk::uint32 counter=0u;
#endif
void edk::InfiniteWallpaper::update(edk::float32 runMove,edk::float32 seconds){
    if(seconds<0.f)seconds*=-1.f;
    //update the size
    if(this->saveSize!=this->size){
        this->changeSize();
    }
    //
    this->translate.x+=this->speed.x*runMove * seconds;
    this->translate.y+=this->speed.y*runMove * seconds *-1;

    bool changeXNegative;
    bool changeXPositive;
    bool changeYNegative;
    bool changeYPositive;

    do{
        changeXNegative=false;
        changeXPositive=false;
        changeYNegative=false;
        changeYPositive=false;
        //test if the translate is bigger then the size
        if(this->translate.x > this->size.width){
            if(this->matrix.width()==1u){
                this->translate.x = this->size.width;
            }
            else{
                this->translate.x -= this->size.width;
                //change the matrix in X
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                printf("\n\n%u",counter++);fflush(stdout);
#endif
                changeXPositive=true;
            }
        }
        if(this->matrix.width()==1u){
            if(this->translate.x < 0.f){
                this->translate.x = 0.f;
            }
        }
        else{
            if(this->translate.x < this->size.width*-1.f){
                this->translate.x += this->size.width;
                //change the matrix
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                printf("\n\n%u",counter++);fflush(stdout);
#endif
                changeXNegative=true;
            }
        }
        if(this->translate.y > this->size.height){
            if(this->matrix.height()==1u){
                this->translate.y = this->size.height;
            }
            else{
                this->translate.y -= this->size.height;
                //change the matrix
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                printf("\n\n%u",counter++);fflush(stdout);
#endif
                changeYPositive=true;
            }
        }
        if(this->matrix.height()==1u){
            if(this->translate.y < 0.f){
                this->translate.y = 0.f;
            }
        }
        else{
            if(this->translate.y < this->size.height*-1.f){
                this->translate.y += this->size.height;
                //change the matrix
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                printf("\n\n%u",counter++);fflush(stdout);
#endif
                changeYNegative=true;
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
                    edk::size2ui32 size = this->matrix.size();
                    edk::InfiniteWallpaper::WallpaperObject* temp = NULL;
                    edk::uint32 position;
                    edk::uint32 savePosition;
                    bool runIncreDecre=false;

                    if(size.width){
                        for(edk::uint32 y=0u;y<size.height;y++){
                            position = this->matrix.get(size.width-1u,y);
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                            printf("\n%u %s %s this->matrix.remove((size.width[%u]-1u)[%u],y[%u])[%u];",__LINE__,__FILE__,__func__
                                   ,size.width
                                   ,size.width-1u
                                   ,y
                                   ,position
                                   );fflush(stdout);
#endif
                            temp = this->stack.get(position);
                            if(temp){
                                //
                                if(temp->getDrawTimes()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                    printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                    temp->incrementDraw();
                                    temp->haveRemoved=false;
                                }
                            }


                            //test with the neighbours
                            if(size.width>1u){
                                savePosition = this->matrix.get(size.width-2u,y);
                                if(savePosition<position){
                                    for(edk::uint32 i = position-1u;i>savePosition;i--){
                                        temp = this->stack.get(i);
                                        if(temp){
                                            //
                                            if(temp->getDrawTimes()){
                                                if(temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                    printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                                    temp->incrementDraw();
                                                    temp->haveRemoved=false;
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
                                        temp = this->stack.get(i-1u);
                                        if(temp){
                                            //
                                            if(temp->getDrawTimes()){
                                                if(!temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                    printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                                    temp->incrementDraw();
                                                    temp->haveRemoved=false;
                                                }
                                                else{
                                                    runIncreDecre=true;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    if(!runIncreDecre){
                                        for(edk::uint32 i = this->stack.size()-1u;i>savePosition;i--){
                                            temp = this->stack.get(i);
                                            if(temp){
                                                //
                                                if(temp->getDrawTimes()){
                                                    if(!temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                        printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                                        temp->incrementDraw();
                                                        temp->haveRemoved=false;
                                                    }
                                                    else{
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    runIncreDecre=false;
                                }

                            }
                        }
                    }

                    for(edk::uint32 x=size.width;x>0u;x--){
                        for(edk::uint32 y=0u;y<size.height;y++){
                            this->matrix.set(x-1u,y,this->matrix.get(x-2u,y));
                        }
                    }
                    //in the end it fill the first matrix values
                    for(edk::uint32 y=0u;y<size.height;y++){
                        position = this->matrix.get(1u,y);
                        if(position==0u) position = this->stack.size()-1u;
                        else position--;
                        savePosition = position;
                        for(;;){
                            temp = this->stack.get(position);
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                            printf("\n%u %s %s try([%u])'%s'",__LINE__,__FILE__,__func__
                                   ,position
                                   ,temp?"true":"false"
                                         );fflush(stdout);
#endif
                            if(temp){
                                if(temp->getDrawTimes()){
                                    if(temp->isMinusDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                        printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                        temp->incrementDraw();
                                        runIncreDecre=true;
                                    }
                                }
                                //test if can draw
                                if(temp->canDraw()){
                                    if(!temp->haveRemoved){
                                        if(temp->getDrawTimes()){
                                            //temp->incrementDraw();
                                        }
                                    }
                                    break;
                                }
                                else{
                                    if(!temp->haveRemoved){
                                        if(temp->getDrawTimes()){
                                            if(!runIncreDecre){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                                temp->incrementDraw();
                                            }
                                        }
                                    }
                                }
                                temp->haveRemoved=false;
                                runIncreDecre=false;
                            }
                            if(position==0u) position = this->stack.size()-1u;
                            else position--;
                            if(position==savePosition){
                                break;
                            }
                        }
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                        printf("\n%u %s %s this->matrix.set(0[%u],y[%u],position[%u]);",__LINE__,__FILE__,__func__
                               ,0
                               ,y
                               ,position
                               );fflush(stdout);
#endif
                        this->matrix.set(0u,y,position);
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
                    edk::size2ui32 size = this->matrix.size();
                    if(size.width>1u){
                        edk::uint32 position;
                        edk::uint32 savePosition;
                        bool runIncreDecre=false;
                        edk::InfiniteWallpaper::WallpaperObject* temp = NULL;

                        for(edk::uint32 y=0u;y<size.height;y++){
                            position = this->matrix.get(0u,y);
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                            printf("\n%u %s %s this->matrix.remove(0u[%u],y[%u])[%u];",__LINE__,__FILE__,__func__
                                   ,0u
                                   ,y
                                   ,position
                                   );fflush(stdout);
#endif
                            temp = this->stack.get(position);
                            if(temp){
                                //decrement the draw from TEMP
                                if(temp->getDrawTimes()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                    printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                    temp->decrementDraw();
                                    temp->haveRemoved=false;
                                }
                            }


                            //test with the neighbours
                            savePosition = this->matrix.get(1u,y);
                            if(savePosition>position){
                                for(edk::uint32 i = position+1u;i<savePosition;i++){
                                    temp = this->stack.get(i);
                                    if(temp){
                                        //
                                        if(temp->getDrawTimes()){
                                            if(temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                                temp->decrementDraw();
                                                temp->haveRemoved=false;
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
                                    temp = this->stack.get(i);
                                    if(temp){
                                        //
                                        if(temp->getDrawTimes()){
                                            if(!temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                                temp->decrementDraw();
                                                temp->haveRemoved=false;
                                            }
                                            else{
                                                runIncreDecre=true;
                                                break;
                                            }
                                        }
                                    }
                                }
                                if(!runIncreDecre){
                                    for(edk::uint32 i = 0u;i<savePosition;i++){
                                        temp = this->stack.get(i);
                                        if(temp){
                                            //
                                            if(temp->getDrawTimes()){
                                                if(!temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                    printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                                    temp->decrementDraw();
                                                    temp->haveRemoved=false;
                                                }
                                                else{
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                                runIncreDecre=false;
                            }

                        }

                        size.width--;
                        for(edk::uint32 x=0;x<size.width;x++){
                            for(edk::uint32 y=0u;y<size.height;y++){
                                this->matrix.set(x,y,this->matrix.get(x+1u,y));
                            }
                        }
                        //in the end it fill the first matrix values
                        for(edk::uint32 y=0u;y<size.height;y++){
                            position = this->matrix.get(size.width-1u,y) + 1u;
                            if(this->stack.size()<=position) position=0u;
                            savePosition = position;
                            for(;;){
                                temp = this->stack.get(position);
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                printf("\n%u %s %s try([%u])'%s'",__LINE__,__FILE__,__func__
                                       ,position
                                       ,temp?"true":"false"
                                             );fflush(stdout);
#endif
                                if(temp){
                                    if(temp->getDrawTimes()){
                                        if(!temp->isMinusDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                            printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                            temp->decrementDraw();
                                            runIncreDecre=true;
                                        }
                                    }
                                    //test if can draw
                                    if(temp->canDraw()){
                                        if(!temp->haveRemoved){
                                            if(temp->getDrawTimes()){
                                                //temp->decrementDraw();
                                            }
                                        }
                                        break;
                                    }
                                    else{
                                        if(!temp->haveRemoved){
                                            if(temp->getDrawTimes()){
                                                if(!runIncreDecre){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                    printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                                    temp->decrementDraw();
                                                }
                                            }
                                        }
                                    }
                                    temp->haveRemoved=false;
                                    runIncreDecre=false;
                                }
                                position++;
                                if(this->stack.size()<=position) position=0u;
                                if(position==savePosition){
                                    break;
                                }
                            }
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                            printf("\n%u %s %s this->matrix.set(size.width[%u],y[%u],position[%u]);",__LINE__,__FILE__,__func__
                                   ,size.width
                                   ,y
                                   ,position
                                   );fflush(stdout);
#endif
                            this->matrix.set(size.width,y,position);
                        }
                    }
                }
            }
        }
        else if(changeYPositive){
            //just Y Positive
            if(this->matrix.haveMatrix() && this->stack.size()){
                edk::size2ui32 size = this->matrix.size();
                edk::InfiniteWallpaper::WallpaperObject* temp = NULL;
                edk::uint32 position;
                edk::uint32 savePosition;
                bool runIncreDecre=false;

                for(edk::uint32 x=0u;x<size.width;x++){
                    position = this->matrix.get(x,size.height-1u);
                    temp = this->stack.get(position);
                    if(temp){
                        //decrement the draw from TEMP
                        if(temp->getDrawTimes()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                            printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                            temp->incrementDraw();
                            temp->haveRemoved=false;
                        }
                    }


                    //test with the neighbours
                    if(size.height>1u){
                        savePosition = this->matrix.get(x,size.height-2u);
                        if(savePosition<position){
                            for(edk::uint32 i = position-1u;i>savePosition;i--){
                                temp = this->stack.get(i);
                                if(temp){
                                    //
                                    if(temp->getDrawTimes()){
                                        if(temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                            printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                            temp->incrementDraw();
                                            temp->haveRemoved=false;
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
                                temp = this->stack.get(i-1u);
                                if(temp){
                                    //
                                    if(temp->getDrawTimes()){
                                        if(!temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                            printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                            temp->incrementDraw();
                                            temp->haveRemoved=false;
                                        }
                                        else{
                                            runIncreDecre=true;
                                            break;
                                        }
                                    }
                                }
                            }
                            if(!runIncreDecre){
                                for(edk::uint32 i = this->stack.size()-1u;i>savePosition;i--){
                                    temp = this->stack.get(i);
                                    if(temp){
                                        //
                                        if(temp->getDrawTimes()){
                                            if(!temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                                temp->incrementDraw();
                                                temp->haveRemoved=false;
                                            }
                                            else{
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            runIncreDecre=false;
                        }

                    }
                }

                for(edk::uint32 y=size.width;y>0u;y--){
                    for(edk::uint32 x=0u;x<size.width;x++){
                        this->matrix.set(x,y-1u,this->matrix.get(x,y-2u));
                    }
                }
                //in the end it fill the first matrix values
                for(edk::uint32 x=0u;x<size.width;x++){
                    position = this->matrix.get(x,1u);
                    if(position==0u) position = this->stack.size()-1u;
                    else position--;
                    savePosition = position;
                    for(;;){
                        temp = this->stack.get(position);
                        if(temp){
                            if(temp->getDrawTimes()){
                                if(temp->isMinusDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                    printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                    temp->incrementDraw();
                                    runIncreDecre=true;
                                }
                            }
                            //test if can draw
                            if(temp->canDraw()){
                                if(!temp->haveRemoved){
                                    if(temp->getDrawTimes()){
                                        //temp->incrementDraw();
                                    }
                                }
                                break;
                            }
                            else{
                                if(!temp->haveRemoved){
                                    if(temp->getDrawTimes()){
                                        if(!runIncreDecre){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                            printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                            temp->incrementDraw();
                                        }
                                    }
                                }
                            }
                            temp->haveRemoved=false;
                            runIncreDecre=false;
                        }
                        if(position==0u) position = this->stack.size()-1u;
                        else position--;
                        if(position==savePosition){
                            break;
                        }
                    }
                    this->matrix.set(x,0u,position);
                }
            }
        }
        else if(changeYNegative){
            //just Y Negative
            if(this->matrix.haveMatrix() && this->stack.size()){
                edk::size2ui32 size = this->matrix.size();
                if(size.height>1u){
                    edk::uint32 position;
                    edk::uint32 savePosition;
                    bool runIncreDecre=false;
                    edk::InfiniteWallpaper::WallpaperObject* temp = NULL;

                    for(edk::uint32 x=0u;x<size.width;x++){
                        position = this->matrix.get(x,0u);
                        temp = this->stack.get(position);
                        if(temp){
                            //decrement the draw from TEMP
                            if(temp->getDrawTimes()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                temp->decrementDraw();
                                temp->haveRemoved=false;
                            }
                        }


                        //test with the neighbours
                        savePosition = this->matrix.get(x,1u);
                        if(savePosition>position){
                            for(edk::uint32 i = position+1u;i<savePosition;i++){
                                temp = this->stack.get(i);
                                if(temp){
                                    //
                                    if(temp->getDrawTimes()){
                                        if(temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                            printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                            temp->decrementDraw();
                                            temp->haveRemoved=false;
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
                                temp = this->stack.get(i);
                                if(temp){
                                    //
                                    if(temp->getDrawTimes()){
                                        if(!temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                            printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                            temp->decrementDraw();
                                            temp->haveRemoved=false;
                                        }
                                        else{
                                            runIncreDecre=true;
                                            break;
                                        }
                                    }
                                }
                            }
                            if(!runIncreDecre){
                                for(edk::uint32 i = 0u;i<savePosition;i++){
                                    temp = this->stack.get(i);
                                    if(temp){
                                        //
                                        if(temp->getDrawTimes()){
                                            if(!temp->canDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                                temp->decrementDraw();
                                                temp->haveRemoved=false;
                                            }
                                            else{
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            runIncreDecre=false;
                        }

                    }

                    size.height--;
                    for(edk::uint32 y=0;y<size.height;y++){
                        for(edk::uint32 x=0u;x<size.width;x++){
                            this->matrix.set(x,y,this->matrix.get(x,y+1u));
                        }
                    }
                    //in the end it fill the first matrix values
                    for(edk::uint32 x=0u;x<size.width;x++){
                        position = this->matrix.get(x,size.height-1u) + 1u;
                        if(this->stack.size()<=position) position=0u;
                        savePosition = position;
                        for(;;){
                            temp = this->stack.get(position);
                            if(temp){
                                if(temp->getDrawTimes()){
                                    if(!temp->isMinusDraw()){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                        printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                        temp->decrementDraw();
                                        runIncreDecre=true;
                                    }
                                }
                                //test if can draw
                                if(temp->canDraw()){
                                    if(!temp->haveRemoved){
                                        if(temp->getDrawTimes()){
                                            //temp->decrementDraw();
                                        }
                                    }
                                    break;
                                }
                                else{
                                    if(!temp->haveRemoved){
                                        if(temp->getDrawTimes()){
                                            if(!runIncreDecre){
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
                                                printf("\n%u %s %s",__LINE__,__FILE__,__func__);fflush(stdout);
#endif
                                                temp->decrementDraw();
                                            }
                                        }
                                    }
                                }
                                temp->haveRemoved=false;
                                runIncreDecre=false;
                            }
                            position++;
                            if(this->stack.size()<=position) position=0u;
                            if(position==savePosition){
                                break;
                            }
                        }
                        this->matrix.set(x,size.height,position);
                    }
                }
            }
        }
    }while(changeXNegative||
           changeXPositive||
           changeYNegative||
           changeYPositive
           );
}
void edk::InfiniteWallpaper::update(edk::float32 runMove){
    this->update(runMove,this->clock.getSeconds());
    this->clock.start();
}
void edk::InfiniteWallpaper::update(edk::vec2f32 runMove,edk::float32 seconds){
    //save the speed
    edk::vec2f32 speed = this->speed;
    //update the speed
    this->speed = runMove;
    //run the update
    this->update(1.f,seconds);
    //paste the speed
    this->speed = speed;
}
void edk::InfiniteWallpaper::update(edk::vec2f32 runMove){
    this->update(runMove,this->clock.getSeconds());
    this->clock.start();
}

//draw the wallpaper
void edk::InfiniteWallpaper::drawInsideRect(edk::rectf32 rect){
    //
    edk::vec2i32 lenght = edk::vec2i32((edk::int32)(rect.size.width / this->size.width),
                                       (edk::int32)(rect.size.height / this->size.height)
                                       ) + 1;
    edk::vec2i32 lenghtDouble;
    if(lenght.x<0)lenght.x*=-1;
    if(lenght.y<0)lenght.y*=-1;

    lenghtDouble = lenght +2;

    //test if lenght is bigger than the sizeLimit
    if(this->sizeLimit.width != 0u){
        //test the X
        if(lenghtDouble.x > (edk::int32)this->sizeLimit.width){
            //
            lenghtDouble.x = (edk::int32)this->sizeLimit.width;
            lenght.x = lenghtDouble.x/2u;
            if(!lenght.x)lenght.x=1;
        }
    }
    if(this->sizeLimit.height != 0u){
        //test the Y
        if(lenghtDouble.y > (edk::int32)this->sizeLimit.height){
            //
            lenghtDouble.y = (edk::int32)this->sizeLimit.height;
            lenght.y = lenghtDouble.y/2u;
            if(!lenght.y)lenght.y=1;
        }
    }


    if(this->matrix.width()!=(edk::uint32)lenghtDouble.x
            ||
            this->matrix.height()!=(edk::uint32)lenghtDouble.y
            ){
        //change the matrix
        this->matrix.createMatrix(lenghtDouble.x,lenghtDouble.y);

        edk::size2ui32 size = this->matrix.size();
        //fill the matrix with the wallpapers in X (temporary)
        edk::uint32 value = 0u;

        //decrement value
        if(this->stack.size()){
            for(edk::uint32 i=0u;i<(edk::uint32)lenght.x;i++){
                if(value) value--;
                else value = this->stack.size()-1u;
            }
        }

        for(edk::uint32 x=0u;x<size.width;x++){
            for(edk::uint32 y=0;y<size.height;y++){
                this->matrix.set(x,y,value);
                value++;
                if(value>=this->stack.size()){
                    value=0u;
                }
            }
        }
    }


    if(this->stack.size()){
        edk::uint32 objPos=0u;
        edk::uint32 matrixValue=0u;
        edk::InfiniteWallpaper::WallpaperObject* temp = this->stack.get(objPos);
        if(this->matrix.haveMatrix()){
            edk::size2ui32 size = this->matrix.size();
            edk::int32 posX,posY;
            this->obj.size = this->size;
            this->obj.addMesh(temp->obj.getMesh(0u));
            if(lenghtDouble.x==1)
                lenght.x=0;
            if(lenghtDouble.y==1)
                lenght.y=0;
            posY=lenght.y*-1;
            for(edk::uint32 y=0u;y<size.height;y++){
                this->obj.position.y = this->position.y + (this->translate.y * -1.f) + (posY * this->size.height);
                posX=lenght.x*-1;
                for(edk::uint32 x=0u;x<size.width;x++){
                    this->obj.position.x = this->position.x + this->translate.x + (posX * this->size.width);
                    //test if need change the mesh
                    matrixValue = this->matrix.get(x,y);
                    if(matrixValue != objPos){
                        if((temp = this->stack.get(matrixValue))){
                            //chante the mesh
                            this->obj.cleanMeshes();
                            this->obj.addMesh(temp->obj.getMesh(0u));
                            objPos = matrixValue;
                        }
                    }
                    this->obj.draw();
                    posX++;
                }
                posY++;
            }
            this->obj.cleanMeshes();
        }
    }
}
void edk::InfiniteWallpaper::drawInsideSize(edk::vec2f32 position,edk::size2f32 size){
    this->drawInsideRect(edk::rectf32(position.x - (size.width*0.5f),
                                      position.y - (size.height*0.5f),
                                      position.x + (size.width*0.5f),
                                      position.y + (size.height*0.5f)
                                      )
                         );
}
