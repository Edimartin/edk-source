#ifndef TEXT_H
#define TEXT_H

/*
Text - Simple Text for the GUI 2D library
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
#warning "Inside gui2d::Text"
#endif

#pragma once
#include "../Object2DValues.h"
#include "../TypeDefines.h"
#include "../GU/GU.h"
#include "../ViewSprite.h"
#include "../vector/BinaryTree.h"
#include "../fonts/FontMap.h"
#include "../NameClass.h"
#include "ObjectGui2dBorder.h"
#include "ObjectGui2d.h"

#ifdef printMessages
#warning "    Compiling gui2d::Text"
#endif

namespace edk{
namespace gui2d{
class Text: public edk::gui2d::ObjectGui2d{
public:
    Text();
    ~Text();

    //get the type
    virtual edk::gui2d::gui2dTypes getType();

    //load the button textures and meshes
    bool load();
    void unload();
    void update();

    //set border size
    bool setBorderSize(edk::float32 size);

    //draw the button
    void draw();
};
}
}

#endif // TEXT_H
