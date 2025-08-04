#ifndef LIBS_H
#define LIBS_H

/*
LIBS file - This file have the library links used to compile EDK
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

/* ALL
-lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
*/

/* LINUX
-lpthread -ldl -lX11 -lGL -lGLU -lGLEW
*/

/* WINDOWS
-lwsock32 -lopengl32 -lglu32 -lglew32
*/

/* POSTGRE ALL
 -lpqxx
*/

/* MARIADB ALL
 -lmariadb
*/

/* MYSQL ALL
 -lmysqlclient
*/

/*QTCreator QMAKE

#C_FLAGS
#QMAKE_CFLAGS +=  -nostdlib
#QMAKE_CFLAGS +=  -nostdinc
QMAKE_CFLAGS += -Wno-deprecated-declarations
QMAKE_CFLAGS += -Wno-deprecated-copy

#C++_FLAGS
#QMAKE_CXXFLAGS +=  -nostdlib
#QMAKE_CXXFLAGS +=  -nostdinc
QMAKE_CXXFLAGS += -Wno-deprecated-declarations
QMAKE_CXXFLAGS += -Wno-deprecated-copy

#DEFINES DEBUGGER
#This line will enable the usage of the debugger file
#DEFINES += EDK_DEBUGGER
#This line will enable debug file to ba saved in 'files' folder
#DEFINES += EDK_DEBUG_FILE_NAME=\\\"./edkDebug.txt\\\"
#This line will enable write the debugger file
#DEFINES += EDK_DEBUG_LINE
#This line will enable write debug message in memset function
#DEFINES += EDK_DEBUG_MEMSET
#This line will enable write debug message in memcpy function
#DEFINES += EDK_DEBUG_MEMCPY
#This line will enable write debug message in vector classes functions
#DEFINES += EDK_DEBUG_VECTOR
#This line will enable debug print in edk::InfiniteWallpaper
#DEFINES += EDK_INFITINE_WALLPAPER_DEBUG_ON

#This line unable the use of printDebug to edk::pack::FilePackage (NEED RUN 'edk::pack::FilePackage::createDebugFile(edk::char8* name)' function to create the file)
#DEFINES += EDK_FILEPACK_PRINT_DEBUG
#This line unable write a debug file to edk::Texture2DFile (NEED RUN 'edk::Texture2DFile::createDebugFile(edk::char8* name)' function to create the file)
#DEFINES += EDK_TEX2DFILE_PRINT_DEBUG
#This line unable the use of printDebug to edk::multi::Mutex (NEED RUN 'edk::multi::Mutex::createDebugFile(edk::char8* name)' function to create the file)
#DEFINES += EDK_MUTEX_PRINT_DEBUG
#This line unable the use of draw to edk::vector::QuadTree32 and edk::vector::QuadTree64
#DEFINES += EDK_QUADTREE_GU
#This line activate the use of printDebug to
#DEFINES += EDK_DEBUGGER EDK_DEBUG_FILE_NAME=\\\"./edkDebug.txt\\\"

#DEFINES DISABLE
#This line disable the use of edk::vector::QuadTree32 and edk::vector::QuadTree64
#DEFINES += EDK_DONT_USE_QUADTREE
#This line disable the use of Box2D (don't need Box2D files in project)
#DEFINES += EDK_NO_BOX2D
#This line disable the use of SQlite (don't need Sqlite file in project)
#DEFINES += EDK_NO_SQLITE

#DEFINES ENABLE
#This line will enable read and write window events in class edk::Window
#DEFINES += EDK_WINDOW_EVENTS_RW
#This line will enable the use of mariaDB
#DEFINES += EDK_USE_MARIADB
#This line will enable the use of postgree
#DEFINES += EDK_USE_POSTGRE
#This line will enable the use of mysql
#DEFINES += EDK_USE_MYSQL
#This line will enable the use of openH264
#DEFINES += EDK_USE_OPENH264

#with no pie it will not run in terminal
win32: QMAKE_LFLAGS   += -mwindows
else:unix: QMAKE_LFLAGS   += -no-pie

LIBS += -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

win32: LIBS += -lwsock32 -lopengl32 -lglu32 -lglew32
else:unix: LIBS += -lpthread -ldl -lX11 -lGL -lGLU -lGLEW

*/

/*QTCreator CMAKE

#C_FLAGS
#set(CMAKE_C_FLAGS   -nostdlib)
#set(CMAKE_C_FLAGS   -nostdinc)
set(CMAKE_C_FLAGS   -Wno-deprecated-declarations)
set(CMAKE_C_FLAGS   -Wno-deprecated-copy)

#C++_FLAGS
#set(CMAKE_C_FLAGS   -nostdlib)
#set(CMAKE_C_FLAGS   -nostdinc)
set(CMAKE_C_FLAGS   -Wno-deprecated-declarations)
set(CMAKE_C_FLAGS   -Wno-deprecated-copy)

#DEFINES DEBUGGER
#This line will enable the usage of the debugger file
#add_definitions(-DEDK_DEBUGGER)
#This line will enable debug file to ba saved in 'files' folder
#set(PROJECT_VERSION_STRING "./edkDebug.txt")
#add_definitions(-DEDK_DEBUG_FILE_NAME="${PROJECT_VERSION_STRING}")
#This line will enable write the debugger file
#add_definitions(-DEDK_DEBUG_LINE)
#This line will enable write debug message in memset function
#add_definitions(-DEDK_DEBUG_MEMSET)
#This line will enable write debug message in memcpy function
#add_definitions(-DEDK_DEBUG_MEMCPY)
#This line will enable write debug message in vector classes functions
#add_definitions(-DEDK_DEBUG_VECTOR)
#This line will enable debug print in edk::InfiniteWallpaper
#add_definitions(-DEDK_INFITINE_WALLPAPER_DEBUG_ON)

#This line unable the use of printDebug to edk::pack::FilePackage (NEED RUN 'edk::pack::FilePackage::createDebugFile(edk::char8* name)' function to create the file)
#add_definitions(-DEDK_FILEPACK_PRINT_DEBUG)
#This line unable write a debug file to edk::Texture2DFile (NEED RUN 'edk::Texture2DFile::createDebugFile(edk::char8* name)' function to create the file)
#add_definitions(-DEDK_TEX2DFILE_PRINT_DEBUG)
#This line unable the use of printDebug to edk::multi::Mutex (NEED RUN 'edk::multi::Mutex::createDebugFile(edk::char8* name)' function to create the file)
#add_definitions(-DEDK_MUTEX_PRINT_DEBUG)
#This line unable the use of draw to edk::vector::QuadTree32 and edk::vector::QuadTree64
#add_definitions(-DEDK_QUADTREE_GU)

#DEFINES DISABLE
#This line disable the use of edk::vector::QuadTree32 and edk::vector::QuadTree64
#add_definitions(-DEDK_DONT_USE_QUADTREE)
#This line disable the use of Box2D (don't need Box2D files in project)
#add_definitions(-DEDK_NO_BOX2D)
#This line disable the use of SQlite (don't need Sqlite file in project)
#add_definitions(-DEDK_NO_SQLITE)

#DEFINES ENABLE
#This line will enable read and write window events in class edk::Window
#add_definitions(-DEDK_WINDOW_EVENTS_RW)
#This line will enable the use of mariaDB
#add_definitions(-DEDK_USE_MARIADB)
#This line will enable the use of postgree
#add_definitions(-DEDK_USE_POSTGRE)
#This line will enable the use of mysql
#add_definitions(-DEDK_USE_MYSQL)
#This line will enable the use of openH264
#add_definitions(-DEDK_USE_OPENH264)

add_definitions(-DeditMode)

include_directories(./)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(CMAKE_L_FLAGS -no-pie)
    target_link_libraries(helloEDK -lpthread -ldl -lX11 -lGL -lGLU -lGLEW)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(CMAKE_L_FLAGS -no-pie)
    target_link_libraries(helloEDK -lpthread -ldl -lX11 -lGL -lGLU -lGLEW)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(CMAKE_L_FLAGS -mwindows)
    target_link_libraries(helloEDK -lwsock32 -lopengl32 -lglu32 -lglew32)
else()
    set(CMAKE_L_FLAGS -no-pie)
    target_link_libraries(helloEDK -lpthread -ldl -lX11 -lGL -lGLU -lGLEW)
endif()

target_link_libraries(helloEDK -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio)

*/

#endif // LIBS_H
