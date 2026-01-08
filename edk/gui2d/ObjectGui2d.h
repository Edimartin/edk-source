#ifndef OBJECT_H
#define OBJECT_H

/*
ObjectGui2d - Object for the GUI 2D library
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
#pragma message "Inside gui2d::ObjectGui2d"
#endif

#pragma once
#include "../Object2DValues.h"
#include "../TypeDefines.h"
#include "../GU/GU.h"
#include "../vector/BinaryTree.h"
#include "../fonts/FontMap.h"
#include "../NameClass.h"
#include "../pack/FilePackage.h"
#include "ObjectGui2dBorder.h"
#include "../xml/XML.h"

#ifdef printMessages
#pragma message "    Compiling gui2d::ObjectGui2d"
#endif

#define EDK_GUI2D_XML_GUI2D_OBJ      "gui2dOBJ_"
#define EDK_GUI2D_XML_GUI2D_STRING   "gui2dString_"

#define EDK_GUI2D_XML_GUI2D_POSITION "gui2dPosition_"
#define EDK_GUI2D_XML_GUI2D_ANGLE    "gui2dAngle_"
#define EDK_GUI2D_XML_GUI2D_SIZE     "gui2dSize_"

namespace edk{
namespace gui2d{
enum gui2dTypes{
    gui2dTypeObject=0u,
    gui2dTypeButton,
    gui2dTypeScrollBar,
    gui2dTypeMenu,
    gui2dTypeText,
    gui2dTypeTextField,
    //
    gui2dTypeSize,
};
class ObjectGui2d: public edk::Object2DValues{
public:
    ObjectGui2d();
    virtual ~ObjectGui2d();

    void Constructor();
    void Destructor();

    //get GUI type
    edk::gui2d::gui2dTypes getTypeGUI();
    edk::char8* getStringTypeGUI();
    static edk::char8* getStringTypeGUI(edk::gui2d::gui2dTypes type);

    //LOAD SPRITES
    bool loadSprite(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSprite(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpriteFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpriteFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpriteFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpriteFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    void removeSprite();
    //load pressed sprite
    bool loadSpritePressed(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpritePressed(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpritePressedFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpritePressedFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpritePressedFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpritePressedFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    void removeSpritePressed();
    //load UP sprite
    bool loadSpriteUp(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpriteUp(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpriteUpFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpriteUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpriteUpFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpriteUpFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    void removeSpriteUp();
    //load UP sprite
    bool loadSpritePressedUp(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpritePressedUp(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpritePressedUpFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpritePressedUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpritePressedUpFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSpritePressedUpFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    void removeSpritePressedUp();

    //Load button symbol normal
    bool loadSymbol(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbol(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    void removeSymbol();
    //Load button symbol pressed
    bool loadSymbolPressed(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolPressed(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolPressedFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolPressedFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolPressedFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolPressedFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    void removeSymbolPressed();
    //Load button symbol up
    bool loadSymbolUp(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolUp(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolUpFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolUpFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolUpFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    void removeSymbolUp();
    //Load button symbol pressedUp
    bool loadSymbolPressedUp(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolPressedUp(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolPressedUpFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolPressedUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolPressedUpFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolPressedUpFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    void removeSymbolPressedUp();
    //Load button symbolAllStatus normal
    bool loadSymbolAllStatus(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolAllStatus(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolAllStatusFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolAllStatusFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolAllStatusFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolAllStatusFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //Load button symbolAllUPStatus normal
    bool loadSymbolAllUPStatus(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolAllUPStatus(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolAllUPStatusFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolAllUPStatusFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolAllUPStatusFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolAllUPStatusFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //Load button symbolAllUPStatus normal
    bool loadSymbolAllNormalAndPressedStatus(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolAllNormalAndPressedStatus(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolAllNormalAndPressedStatusFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolAllNormalAndPressedStatusFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolAllNormalAndPressedStatusFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadSymbolAllNormalAndPressedStatusFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);

    //set the color
    void setColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setColor(edk::float32 r,edk::float32 g,edk::float32 b);
    void setColor(edk::color4f32 color);
    void setColor(edk::color3f32 color);

    virtual bool writeText(const edk::char8* text);
    virtual bool writeText(edk::char8* text);
    virtual bool writeText(const edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight);
    virtual bool writeText(edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight);
    virtual bool writeText(const edk::char8* text,edk::size2f32 scale);
    virtual bool writeText(edk::char8* text,edk::size2f32 scale);
    virtual void cleanText();

    //function to calculate boundingBox
    bool calculateBoundingBox();
    bool calculateBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat);
    bool generateBoundingBox();
    bool generateBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat);
    //functions to calculate a new boundingBox
    edk::rectf32 calculateNewBoundingBox();
    edk::rectf32 calculateNewBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat);
    edk::rectf32 generateNewBoundingBox();
    edk::rectf32 generateNewBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat);

    //return a copy of the boundingBox
    edk::rectf32 getBoundingBox();


    //load the button textures and meshes
    virtual bool load();
    virtual void unload();
    virtual void update();
    virtual void startMove(edk::vec2f32 mousePosition);
    virtual void moveTo(edk::vec2f32 position);
    virtual void cancelMove();
    virtual bool setStatus(edk::gui2d::gui2dTexture status);
    void forceUpdate();
    virtual edk::gui2d::gui2dTexture getStatus();
    //select functions
    virtual void select();
    virtual void deselect();
    bool isSelected();
    //click to select an polygon inside the object
    virtual void clickStart(edk::uint32 name);
    virtual void clickMove(edk::uint32 name,bool mouseInside);
    virtual void clickEnd(edk::uint32 name,bool mouseInside,bool doubleClick);

    //set border size
    virtual bool setBorderSize(edk::float32 size);

    //return the object rectangle inside
    edk::rectf32 getInsideRect();

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id);

    //draw the button
    virtual void draw();
    virtual void drawSelection();
    //return true if the object can be moved
    virtual bool canMove();

    //clone the gui object from
    virtual bool cloneFrom(edk::gui2d::ObjectGui2d* obj);

    //button frame in the world
    bool pressed;
protected:
    void drawStart();
    void drawObject();
    void drawObjectSelection();
    void drawSprite();
    void drawTextFont();
    void drawTextFontWire();
    void drawEnd();
    void runTextSize();
    void calculateTextScale(edk::size2f32 scale);
    //get the text scale template
    edk::size2f32 getTextTemplateScale();
    virtual void updateTextSize(edk::size2f32 sizeText,edk::size2f32 centerSize,edk::size2ui32 mapSize);
    edk::gui2d::ObjectGui2dBorder obj;
    //save if the obj is selected
    bool selected;
    //image inside the button
    edk::shape::Mesh2D sprite;
    //save the size
    edk::size2f32 sizeS;
    edk::float32 borderSizeS;
    edk::shape::Rectangle2D center;
    edk::shape::Rectangle2D centerS;
    edk::shape::Rectangle2D spritePolygon;
    //text to be printed in front
    edk::fonts::FontMap text;
    edk::Name textString;
    bool drawText;
    edk::size2f32 textSize;
    //sprite size
    edk::size2ui32 spriteSize[edk::gui2d::gui2dTextureSize];
    //temp
    edk::float32 percent1;
    edk::float32 percent2;
    edk::float32 resize;
    //object status
    edk::gui2d::gui2dTexture status;
    //save the object status to compare in update function
    edk::gui2d::gui2dTexture saveStatus;
    //save the position to move the object
    edk::vec2f32 savePosition;

    //transform matrices
    edk::vector::Matrixf32<3u,3u> matrixPosition;
    edk::vector::Matrixf32<3u,3u> matrixPivo;
    edk::vector::Matrixf32<3u,3u> matrixAngle;
    edk::vector::Matrixf32<3u,3u> matrixSize;
    edk::vector::Matrixf32<3u,3u> matrixTransform;

    //object boundingBox
    edk::rectf32 boundingBox;

    edk::gui2d::gui2dTypes typeGUI;

    bool writeBoundingBox(edk::rectf32* rect);
    bool writeBoundingBox(edk::rectf32* rect,edk::vector::Matrixf32<3u,3u>* transformMat);
private:
    edk::classID classThis;
};
}//end namespace gui2d
}//end namespace edk

#endif // OBJECT_H
