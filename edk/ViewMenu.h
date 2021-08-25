#ifndef EDK_VIEWMENU_H
#define EDK_VIEWMENU_H

/*
Library C++ edkViewMenu - Viewport used to show a Menu sprite in the background
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
#warning "Inside ViewMenu"
#endif

#include "ViewSpriteController.h"
#include "Camera2D.h"

#ifdef printMessages
#warning "    Compiling ViewMenu"
#endif

//#define borderSize 50.f

namespace edk{
class ViewMenu: public edk::ViewSpriteController{
public:
    ViewMenu();
    ~ViewMenu();

    //set borderSize
    bool setBorderSize(edk::uint32 size);
    //return the inside frame
    edk::rectui32 getInsideFrame();
    //return the size inside
    edk::size2ui32 getInsideSize();

    //draw
    virtual void draw(rectf32 outsideViewOrigin);
protected:
    //draw the polygon on the scene
    virtual void drawPolygon(rectf32 outsideViewOrigin);
private:
    edk::Camera2D cam;
    edk::rectf32 rectMenuSave;
};
}//end namespace edk

#endif // EDK_VIEWMENU_H
