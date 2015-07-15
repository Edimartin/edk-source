/*
Library EDK - How to use Extensible Development Kit
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

Thanks to download the Extensible Development Kit.
To use EDK you need add the source code to your IDE project with the other libs as: Box2D, jpeglib, pugixml and sqlite.
To compile the source code, you will need add the external libs founded in "edk/LIBS.h":

-lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
LINUX
-lpthread -lGL -lGLU -lGLEW -ldl
WINDOWS
-lwsock32 -lopengl32 -lglu32 -lglew32

If you use QTCreator paste this code in yourProject.pro:
LIBS += -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
win32: LIBS += -lwsock32 -lopengl32 -lglu32 -lglew32
else:unix: LIBS += -lpthread -lGL -lGLU -lGLEW -ldl

This link can show to you how to intall SFML:
http://www.sfml-dev.org/tutorials/2.3/#getting-started

You can se the edk hello world in helloEDK.cpp.
