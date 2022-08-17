#include "InfiniteWallpaper.h"

edk::InfiniteWallpaper::InfiniteWallpaper(){
    //
    this->percent=0.f;
    this->translate=0.f;
    this->clock.start();
}
edk::InfiniteWallpaper::~InfiniteWallpaper(){
    //
    this->clean();
}
//change the status
void edk::InfiniteWallpaper::changeStatus(){
    edk::uint32 size = this->stack.size();
    edk::Object2D* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->stack.get(i);
        if(temp){
            temp->size = this->saveSize;
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
    edk::Object2D* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->stack.get(i);
        if(temp){
            temp->cleanMeshes();
            delete temp;
        }
    }
    this->stack.clean();
    this->translate=0.f;
}
//add new wallpaper
//filter
//GU_NEAREST
//GU_LINEAR
//GU_NEAREST_MIPMAP_NEAREST
//GU_NEAREST_MIPMAP_LINEAR
//GU_LINEAR_MIPMAP_NEAREST
//GU_LINEAR_MIPMAP_LINEAR
bool edk::InfiniteWallpaper::newWallpaper(edk::char8* name,edk::uint32 filter){
    if(name){
        edk::Object2D* temp = new edk::Object2D;
        if(temp){
            //create a new mesh
            edk::shape::Mesh2D* mesh = temp->newMesh();
            if(mesh){
                edk::shape::Rectangle2D rect;
                rect.setPivoToCenter();
                mesh->addPolygon(rect);
                if(mesh->material.loadTexture(name,0u,filter)){
                    //add the temp in to the stack
                    edk::uint32 size = this->stack.size();
                    this->stack.pushBack(temp);
                    if(size < this->stack.size()){
                        temp->size=this->size;
                        return true;
                    }
                }
                temp->cleanMeshes();
            }
            delete temp;
        }
    }
    return false;
}
bool edk::InfiniteWallpaper::newWallpaper(const edk::char8* name,edk::uint32 filter){
    return newWallpaper((edk::char8*) name,filter);
}
bool edk::InfiniteWallpaper::newWallpaperFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter){
    if(name){
        edk::Object2D* temp = new edk::Object2D;
        if(temp){
            //create a new mesh
            edk::shape::Mesh2D* mesh = temp->newMesh();
            if(mesh){
                edk::shape::Rectangle2D rect;
                rect.setPivoToCenter();
                mesh->addPolygon(rect);
                if(mesh->material.loadTextureFromMemory(name,image,size,0u,filter)){
                    //add the temp in to the stack
                    edk::uint32 size = this->stack.size();
                    this->stack.pushBack(temp);
                    if(size < this->stack.size()){
                        temp->size=this->size;
                        return true;
                    }
                }
                temp->cleanMeshes();
            }
            delete temp;
        }
    }
    return false;
}
bool edk::InfiniteWallpaper::newWallpaperFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter){
    return this->newWallpaperFromMemory((edk::char8*) name,image,size,filter);
}
bool edk::InfiniteWallpaper::newWallpaperFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter){
    if(name){
        edk::Object2D* temp = new edk::Object2D;
        if(temp){
            //create a new mesh
            edk::shape::Mesh2D* mesh = temp->newMesh();
            if(mesh){
                edk::shape::Rectangle2D rect;
                rect.setPivoToCenter();
                mesh->addPolygon(rect);
                if(mesh->material.loadTextureFromPack(pack,name,0u,filter)){
                    //add the temp in to the stack
                    edk::uint32 size = this->stack.size();
                    this->stack.pushBack(temp);
                    if(size < this->stack.size()){
                        temp->size=this->size;
                        return true;
                    }
                }
                temp->cleanMeshes();
            }
            delete temp;
        }
    }
    return false;
}
bool edk::InfiniteWallpaper::newWallpaperFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter){
    return this->newWallpaperFromPack(pack,(edk::char8*) name,filter);
}
//clone a wallpaper from an object
bool edk::InfiniteWallpaper::newWallpaperFromObject2D(edk::Object2D* obj){
    if(obj){
        //create a new object
        edk::Object2D* temp = new edk::Object2D;
        if(temp){
            //clone the temp from object
            if(temp->cloneFrom(obj)){
                //push back the object
                edk::uint32 size = this->stack.size();
                this->stack.pushBack(temp);
                if(size < this->stack.size()){
                    temp->size=this->size;
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

void edk::InfiniteWallpaper::update(edk::float32 runMove,edk::float32 seconds){
    if(seconds<0.f)seconds*=-1.f;
    //update the size
    if(this->saveSize!=this->size){
        this->changeSize();
    }
/*
    //test the runMove
    if(runMove<-1){
        runMove=-1;
    }
    else if(runMove>+1){
        runMove=+1;
    }
*/
    //
    this->translate+=this->speed*runMove * seconds;

    //test if the translate is bigger then the size
    if(this->translate.x > this->size.width){
        this->translate.x -= this->size.width;
    }
    if(this->translate.x < this->size.width*-1.f){
        this->translate.x += this->size.width;
    }
    if(this->translate.y > this->size.height){
        this->translate.y -= this->size.height;
    }
    if(this->translate.y < this->size.height*-1.f){
        this->translate.y += this->size.height;
    }
}
void edk::InfiniteWallpaper::update(edk::float32 runMove){
    this->update(runMove,this->clock.getSeconds());
    this->clock.start();
}

//draw the wallpaper
void edk::InfiniteWallpaper::drawInsideRect(edk::rectf32 rect){
    //


    //how many wallpapers will fits inside the rect
    /*
    //first get the distance
    edk::vec2f32 distance = this->position - edk::vec2f32(rect.origin.x + rect.size.width*0.5f,
                                                          rect.origin.y + rect.size.height*0.5f
                                                          );
*/
    //
    edk::vec2i32 lenght = edk::vec2i32((edk::int32)(rect.size.width / this->size.width),
                                       (edk::int32)(rect.size.height / this->size.height)
                                       ) + 1;
    if(lenght.x<0)lenght.x*=-1;
    if(lenght.y<0)lenght.y*=-1;

    if(this->saveLenght!=lenght){
        this->saveLenght = lenght;

        //change the matrix
    }

    if(this->stack.size()){
        edk::Object2D* temp = this->stack.get(0u);
        if(temp){
            //draw the objects
            for(edk::int32 y=lenght.y*-1;y<=lenght.y;y++){
                temp->position.y = this->position.y + this->translate.y + (y * this->size.height);
                for(edk::int32 x=lenght.x*-1;x<=lenght.x;x++){
                    temp->position.x = this->position.x + this->translate.x + (x * this->size.width);
                    temp->draw();
                }
            }
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
