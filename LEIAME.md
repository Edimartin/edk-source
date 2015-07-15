# edk-source
Obrigado por fazer o download do Extensible Development Kit.
Para usar o edk você precisa adicionar o código no projeto na sua IDE junto com as outras bibliotecas: Box2D, jpeglib, pugixml e sqlite.
Para compilar o código, você vai precisar das bibliotecas externas encontradas nos arquivos "edk/LIBS.h":

-lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
LINUX
-lpthread -lGL -lGLU -lGLEW -ldl
WINDOWS
-lwsock32 -lopengl32 -lglu32 -lglew32

Se você usa o QTCreator cole este código no seuProjeto.pro:
LIBS += -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
win32: LIBS += -lwsock32 -lopengl32 -lglu32 -lglew32
else:unix: LIBS += -lpthread -lGL -lGLU -lGLEW -ldl

Este link mostra como instalar a SFML:
http://www.sfml-dev.org/tutorials/2.3/#getting-started

Você pode encotrar o edk hello world no helloEDK.cpp.

