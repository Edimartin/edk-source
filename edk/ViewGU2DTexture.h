#ifndef VIEWGU2DTEXTURE_H
#define VIEWGU2DTEXTURE_H

#include "ViewGUTexture.h"

namespace edk{
class ViewGU2DTexture : public edk::ViewGUTexture{
public:
    ViewGU2DTexture(edk::size2ui32 size);
    ViewGU2DTexture(edk::uint32 width,edk::uint32 height);
    ~ViewGU2DTexture();

    //the edkGU 2D camera
    edk::Camera2D camera;
protected:
//draw the polygon on the scene
void drawPolygon(rectf32 outsideViewOrigin);
private:
//draw the 2Dcamera
void drawCamera2D();
};
}//end namespace edk

#endif // VIEWGU2DTEXTURE_H
