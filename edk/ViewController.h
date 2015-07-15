#ifndef EDK_VIEWCONTROLLER_h
#define EDK_VIEWCONTROLLER_h

/*
Library C++ edkController - Render other views inside this view in Edk Game Engine
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#ifdef printMessages
#warning "Inside ViewControllers"
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
#warning "    Compiling ViewControllers"
#endif

namespace edk {

/*
 */
class ViewController : public View {
    //
    public:
    ViewController();

    ViewController(edk::rectf32 frame);

    ~ViewController();

    bool addSubview(edk::View *addView);

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

    virtual void draw(edk::rectf32 outsideViewOrigin);

    //process contact in the view
    bool contact(edk::vec2f32 point,edk::uint8 state,edk::vector::Stack<edk::uint32>* buttons);

    //return false to isLeaf
    bool isLeaf();
 private:

    //The list of views inside this view
    edk::vector::Stack<edk::View*> nexts;
    //save the rect inside
    edk::rectf32 rectInside;
};

} /* End of namespace edk */

#endif // edk_ViewController_h
