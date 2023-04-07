#ifndef EDK_VIEWCONTROLLER_h
#define EDK_VIEWCONTROLLER_h

/*
Library C++ edkController - Render other views inside this view in Edk Game Engine
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
#pragma message "Inside ViewControllers"
#endif

//#include <vector>
#include "vector/Stack.h"
#include "View.h"
/*
#include "ViewController.h"
#include "animation2D/PointAnimation.h"
#include "color3f32.h"
#include "rectf32.h"
*/

#ifdef printMessages
#pragma message "    Compiling ViewControllers"
#endif

/*
void resize(edk::rectf32 outsideViewOrigin){
    //
}
void load(edk::rectf32 outsideViewOrigin){
    //
}
void unload(){
    //
}
void update(edk::WindowEvents* events){
    //
}
void pause(){
    //
}
void unpause(){
    //
}
*/

namespace edk {
class Window;
class ViewController : public View {
    //
    public:
    ViewController();

    ViewController(edk::rectf32 frame);

    //Window can use the protected functions of the view
    friend edk::Window;

    ~ViewController();

    virtual bool addSubview(edk::View *addView);

    uint32 getCount();

    View* getSubview(edk::uint64 n);

    uint32 getSubviewId(edk::View *subView);

    bool haveSubview(edk::View *subView);

    //bring subView to Positions
    bool bringSubviewToSubviewFront(View *subView1,edk::View *subView2);
    bool bringSubviewToIDFront(View *subView,edk::uint32 newID);
    bool bringSubviewIDToIDFront(edk::uint32 id,edk::uint32 newID);
    bool bringSubviewToFront(View *subView);
    bool bringSubviewIDToFront(edk::uint32 id);
    //move the subViews
    bool bringSubviewUp(View* subView);
    bool bringSubviewIDUp(edk::uint32 id);
    bool bringSubviewDown(View* subView);
    bool bringSubviewIDDown(edk::uint32 id);
    bool bringSubviewUp(View* subView,edk::uint32 count);
    bool bringSubviewIDUp(edk::uint32 id,edk::uint32 count);
    bool bringSubviewDown(View* subView,edk::uint32 count);
    bool bringSubviewIDDown(edk::uint32 id,edk::uint32 count);

    //remove subView
    bool removeSubview(View *subView);
    void removeAllSubview();

    virtual void draw(edk::rectf32 outsideViewOrigin);

    //process contact in the view
    bool contact(edk::vec2f32 point,edk::uint8 state,edk::vector::Stack<edk::uint32>* buttons);
    void contactRelease(edk::vec2f32 point,edk::uint8 state,edk::vector::Stack<edk::uint32>* buttons);

    //return false to isLeaf
    bool isLeaf();
protected:
    //draw the view inside in a separated function to viewTexture draw other views inside
    void drawViewInside();
    //run the pause function
    void runPause();
    //run the unpause function
    void runUnpause();
    //run the pauseSwitch function in the views
    void runPauseSwitch();
 private:

    //The list of views inside this view
    edk::vector::Stack<edk::View*> nexts;
    //save the rect inside
    edk::rectf32 rectInside;
    bool setRectInside;
};

} /* End of namespace edk */

#endif // edk_ViewController_h
