#ifndef INFINITEWALLPAPER_H
#define INFINITEWALLPAPER_H

#include "Object2D.h"
#include "vector/Stack.h"
#include "vector/Matrix.h"
#include "Random.h"
#include "edk/watch/Time.h"

//#define EDK_INFITINE_WALLPAPER_DEBUG_ON

namespace edk{
class InfiniteWallpaper{
public:
    InfiniteWallpaper();
    ~InfiniteWallpaper();

    //clean wallpapers
    void clean();
    //add new wallpaper
    //filter
    //GU_NEAREST
    //GU_LINEAR
    //GU_NEAREST_MIPMAP_NEAREST
    //GU_NEAREST_MIPMAP_LINEAR
    //GU_LINEAR_MIPMAP_NEAREST
    //GU_LINEAR_MIPMAP_LINEAR
    bool newWallpaper(edk::char8* name,edk::uint32 drawTimes=0u,edk::uint32 filter = GU_NEAREST);
    bool newWallpaper(const edk::char8* name,edk::uint32 drawTimes=0u,edk::uint32 filter = GU_NEAREST);
    bool newWallpaperFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 drawTimes=0u,edk::uint32 filter = GU_NEAREST);
    bool newWallpaperFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 drawTimes=0u,edk::uint32 filter = GU_NEAREST);
    bool newWallpaperFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 drawTimes=0u,edk::uint32 filter = GU_NEAREST);
    bool newWallpaperFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 drawTimes=0u,edk::uint32 filter = GU_NEAREST);
    //clone a wallpaper from an object
    bool newWallpaperFromObject2D(edk::Object2D* obj,edk::uint32 drawTimes=0u);

    //set the speed of the wallpaper
    void setSpeed(edk::vec2f32 speed);
    void setSpeed(edk::float32 x,edk::float32 y);
    void setSpeedX(edk::float32 speedX);
    void setSpeedY(edk::float32 speedY);

    //set the sizeLimit
    void setLimit(edk::size2ui32 size);
    void setLimitWidth(edk::uint32 width);
    void setLimitHeight(edk::uint32 height);
    void cleanLimit();
    void cleanLimitWidth();
    void cleanLimitHeight();

    void update(edk::float32 runMove,edk::float32 seconds);
    void update(edk::float32 runMove);
    void update(edk::vec2f32 runMove,edk::float32 seconds);
    void update(edk::vec2f32 runMove);

    //draw the wallpaper
    void drawInsideRect(edk::rectf32 rect);
    void drawInsideSize(edk::vec2f32 position,edk::size2f32 size);

    edk::size2f32 size;
    edk::vec2f32 position;
private:
    class WallpaperObject{
    public:
        WallpaperObject(edk::uint32 drawTimes){
            this->drawTimes = drawTimes;edkEnd();
            this->cleanDraw();edkEnd();
        }
        ~WallpaperObject(){
            this->obj.cleanMeshes();edkEnd();
        }
        //return true if can draw
        bool canDraw(){
            if(this->drawTimes){
                if(this->drawCounter<this->drawTimes
                        &&
                        this->drawCounter>(edk::int64)this->drawTimes*-1){
                    return true;
                }
                else{
                    return false;
                }
            }
            return true;
        }
        //increment and decrement the drawCounter
        bool incrementDraw(){
            bool ret=false;edkEnd();
            if(this->canDraw()){
                ret=true;edkEnd();
            }
            this->drawCounter++;edkEnd();
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
            if(this->drawTimes){
                printf("\n%u %s %s increment %ld",__LINE__,__FILE__,__func__,this->drawCounter);edkEnd();
            }
#endif
            return ret;
        }
        bool decrementDraw(){
            bool ret=false;edkEnd();
            if(this->canDraw()){
                ret=true;edkEnd();
            }
            this->drawCounter--;edkEnd();
#if defined(EDK_INFITINE_WALLPAPER_DEBUG_ON)
            if(this->drawTimes){
                printf("\n%u %s %s decrement %ld",__LINE__,__FILE__,__func__,this->drawCounter);edkEnd();
            }
#endif
            return ret;
        }
        bool isMinusDraw(){
            if(this->drawCounter<0){
                return true;
            }
            return false;
        }
        void cleanDraw(){
            this->drawCounter=0;edkEnd();
            this->haveRemoved=false;edkEnd();
        }
        edk::uint32 getDrawTimes(){
            return this->drawTimes;edkEnd();
        }
        edk::Object2D obj;
        bool haveRemoved;
    private:
        edk::uint32 drawTimes;
        edk::int64 drawCounter;
    };
    edk::vector::Stack<edk::InfiniteWallpaper::WallpaperObject*> stack;
    edk::size2f32 saveSize;
    edk::vec2f32 savePosition;
    edk::vec2i32 saveLenght;
    edk::vec2f32 speed;
    edk::vec2f32 percent;
    edk::vec2f32 translate;
    edk::watch::Time clock;
    //matrix with the position values
    edk::vector::MatrixDynamic<edk::uint32> matrix;
    //limit of matrix size
    edk::size2ui32 sizeLimit;
    //object pointer to be rendered
    edk::Object2D obj;
    //change the status
    void changeStatus();
    void changeSize();
};
}

#endif // INFINITEWALLPAPER_H
