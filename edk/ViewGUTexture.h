#ifndef VIEWGUTEXTURE_H
#define VIEWGUTEXTURE_H

#include "ViewGU.h"
//Include the renderTexture
#include "Texture2DRender.h"
#include "Camera2D.h"

namespace edk{
class ViewGUTexture : public edk::ViewGU{
public:
    ViewGUTexture(edk::size2ui32 size);
    ViewGUTexture(edk::uint32 width,edk::uint32 height);
    ~ViewGUTexture();

    //set the new size of the texture
    bool setTextureSize(edk::size2ui32 size);
    bool setTextureSize(edk::uint32 width,edk::uint32 height);

    void draw(rectf32 outsideViewOrigin);
private:
    edk::Texture2DRender render;
    //camera to draw the polygon with the render texture
    edk::Camera2D renderCamera;
};
}//end namespace edk

#endif // VIEWGUTEXTURE_H
