#ifndef TIMELINE2D_H
#define TIMELINE2D_H

/*
Timeline2d - Show a Timeline 2d for in GUI 2D library
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
#pragma message "Inside gui2d::Timeline2d"
#endif

#pragma once
#include "../thread/Mutex.h"
#include "ObjectGui2dBorder.h"
#include "ObjectGui2d.h"

#ifdef printMessages
#pragma message "    Compiling gui2d::Timeline2d"
#endif

#define EDK_GUI2D_XML_GUI2D_TIMELINE "gui2dTimeline2d_"

#define DEF_EDK_WORLD_SLICES_PERCENT 1.25f // size of the max slices when show only linear numbers
#define DEF_EDK_SCREEN_NUMBERS_PERCENT 0.1f // size of the bar to draw the numbers
#define DEF_EDK_SCREEN_NUMBERS_HEIGHT_PERCENT 0.5f // size of the numbers inside the bar
#define DEF_EDK_NUMBER_FILTER GU_LINEAR

namespace edk{
namespace gui2d{
class Timeline2d : public edk::gui2d::ObjectGui2d{
public:
    Timeline2d();
    ~Timeline2d();

    void Constructor();
    void Destructor();

    //SETTERS
    bool setSlices(edk::uint32 slices);
    //set the numbers size percent
    bool setNumbersSizePercent(edk::float32 percent);

    //load the button textures and meshes
    bool load();
    void unload();
    void update();

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id);

    //draw the button
    virtual void draw();
    virtual void drawSelection();

    //click to select an polygon inside the object
    virtual void clickStart(edk::uint32 name,edk::vec2f32 position);
    virtual void clickMove(edk::uint32 name,edk::vec2f32 position,bool mouseInside);
    virtual void clickEnd(edk::uint32 name,edk::vec2f32 position,bool mouseInside,bool doubleClick);
    virtual void mouseScrollVertical(edk::uint32 name,edk::int32 scroll,bool mouseInside);
    virtual void mouseScrollHorizontal(edk::uint32 name,edk::int32 scroll,bool mouseInside);

    //clone the gui object from
    virtual bool cloneFrom(edk::gui2d::ObjectGui2d* obj);
    virtual bool cloneFrom(edk::gui2d::Timeline2d* obj);
private:
    edk::Object2D objBack;
    edk::Object2D objFront;
    //colors
    edk::color3f32 colorBackLight,colorBackDark;

    //timeline limits
    edk::float32 timeStart,timeEnd;
    //timeline inside camera
    edk::float32 camStart,camEnd,camLenght;

    //World size
    edk::float32 worldPercent;
    edk::uint32 worldSlices;

    //object to draw the numbers
    edk::Object2D objNumber;
    edk::float32 percentNumbers;

    //inline functions
    inline bool inlineSetObjColor(edk::Object2D* obj,edk::color3f32 color){
        if(obj){
            edk::shape::Mesh2D * mesh = obj->getMesh(0u);
            if(mesh){
                mesh->material.setAmbient(color.r,color.g,color.b,1.0f);
                mesh->material.setDiffuse(color.r,color.g,color.b,1.0f);
                mesh->material.setEmission(color.r,color.g,color.b,1.0f);
            }
            return true;
        }
        return false;
    }
    inline void inlineUpdateCameraLenght(){
        this->camLenght = this->camEnd - this->camStart;
    }

    //draw the number into a position
    bool drawNumber(edk::float32 position,edk::int64 value);

    static edk::Texture2DList list;
    static edk::uint64 listCounter;
    static edk::multi::Mutex mut;
    //load and unload the texture from the list
    void privateLoadNumbers();
    void privateUnloadNumbers();
private:
    edk::classID classThis;
};
}//end namespace gui2d
}//end namespace edk

#endif // TIMELINE2D_H
