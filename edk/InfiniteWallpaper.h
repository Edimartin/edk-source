#ifndef INFINITEWALLPAPER_H
#define INFINITEWALLPAPER_H

#include "Object2D.h"
#include "vector/Stack.h"
#include "vector/Matrix.h"
#include "Random.h"
#include "edk/watch/Time.h"

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
    bool newWallpaper(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool newWallpaper(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool newWallpaperFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool newWallpaperFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool newWallpaperFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool newWallpaperFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    //clone a wallpaper from an object
    bool newWallpaperFromObject2D(edk::Object2D* obj);

    //set the speed of the wallpaper
    void setSpeed(edk::vec2f32 speed);
    void setSpeed(edk::float32 x,edk::float32 y);
    void setSpeedX(edk::float32 speedX);
    void setSpeedY(edk::float32 speedY);

    void update(edk::float32 runMove,edk::float32 seconds);
    void update(edk::float32 runMove);

    //draw the wallpaper
    void drawInsideRect(edk::rectf32 rect);
    void drawInsideSize(edk::vec2f32 position,edk::size2f32 size);

    edk::size2f32 size;
    edk::vec2f32 position;
private:
    edk::vector::Stack<edk::Object2D*> stack;
    edk::size2f32 saveSize;
    edk::vec2f32 savePosition;
    edk::vec2i32 saveLenght;
    edk::vec2f32 speed;
    edk::vec2f32 percent;
    edk::vec2f32 translate;
    edk::watch::Time clock;
    //matrix with the position values
    edk::vector::Matrix<edk::uint32> matrix;
    //object pointer to be rendered
    edk::Object2D obj;
    //change the status
    void changeStatus();
    void changeSize();
};
}

#endif // INFINITEWALLPAPER_H
