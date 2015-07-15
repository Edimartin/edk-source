#ifndef LIBS_H
#define LIBS_H

/* ALL
-lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
*/

/* LINUX
-lpthread -lGL -lGLU -lGLEW -ldl
*/

/* WINDOWS
-lwsock32 -lopengl32 -lglu32 -lglew32
*/

/*QTCreator

LIBS += -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

win32: LIBS += -lwsock32 -lopengl32 -lglu32 -lglew32
else:unix: LIBS += -lpthread -lGL -lGLU -lGLEW -ldl

*/

#endif // LIBS_H
