# edk-source

/*
Library EDK - How to use Extensible Development Kit
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

Thank you for download the Extensible Development Kit.
To use the edk you must add the source code of the project in your IDE project with others libraries such as: Box2D, jpeglib, pugixml e sqlite.
To compile the source code, you will need the external libraries finded in the "edk/LIBS.h" file.

-lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
LINUX
-lpthread -lGL -lGLU -lGLEW -ldl
WINDOWS
-lwsock32 -lopengl32 -lglu32 -lglew32

If you use the QTCreator, just paste this in your project.pro:
LIBS += -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
win32: LIBS += -lwsock32 -lopengl32 -lglu32 -lglew32
else:unix: LIBS += -lpthread -lGL -lGLU -lGLEW -ldl

In this link you will find a tutorial in how to install SFML:
http://www.sfml-dev.org/tutorials/2.3/#getting-started

You can find the edk hello world software source code in helloEDK.cpp file.

