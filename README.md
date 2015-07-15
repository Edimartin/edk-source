# edk-source
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
