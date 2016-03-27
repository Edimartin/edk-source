#ifndef EDK_TYPEDEFINES_H
#define EDK_TYPEDEFINES_H

/*
Library C++ typeDefines - Type Definitions used in Edk Game Engine
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
#warning "Inside TypeDefines"
#endif

#ifdef printMessages
#warning "    Compiling TypeDefines"
#endif

//DEFINES
#define EDK_NULL               0x00000//NULL

#define SH_VERTEX                                      0x0100//O SH_VERTEX  e um vertex    shader
#define SH_FRAGMENT                                    0x0101//O SH_FRAG    e um fragment  shader
#define SH_GEOMETRY                                    0x0102//O SH_PROGRAM e um geometry   shader
#define SH_PROGRAM                                     0x0103//O SH_PROGRAM e um program   shader
#define SH_NULL                                        0x0104//O SH_NULL nao aloca nenhum  shader


#define EDK_WINDOW_BAR         1u
#define EDK_WINDOW_RESIZE      2u
#define EDK_WINDOW_BUTTONS     4u
#define EDK_WINDOW_NOBAR       8u
#define EDK_WINDOW_FULLSCREEN  16u

//CODECS
#define EDK_CODEC_NO   0x00
#define EDK_CODEC_JPEG 0x21
#define EDK_CODEC_PNG  0x22

//AUDIO
#define EDK_STOPPED                                 0x0000
#define EDK_PAUSED                                  0x0001
#define EDK_PLAYING                                 0x0002

//SOCKET
#define EDK_SOCKET_NONE 0x00
#define EDK_SOCKET_UDP  0xaa
#define EDK_SOCKET_TCP  0xbb

//VERTEX TYPE
#define EDK_SHAPE_ANIMATED_UV                        0x0003
#define EDK_SHAPE_UV                                 0x0002
#define EDK_SHAPE_NOUV                               0x0001

//PHYSICS
#define EDK_MAX_CONTACTS_POINTS 2u
//JOINTS
#define EDK_JOINT           0x00
#define EDK_REVOLUTE_JOINT  0x01
#define EDK_DISTANCE_JOINT  0x02
#define EDK_PRISMATIC_JOINT 0x03
#define EDK_PULLEY_JOINT    0x04
#define EDK_WHEEL_JOINT     0x05
#define EDK_ROPE_JOINT      0x06
#define EDK_JOINT_ANGLE     0x07
#define EDK_JOINT_MOTOR     0x08

//LEVEL
#define EDK_LEVEL_NOTHING         0x00
#define EDK_LEVEL_OBJ             0xF0
#define EDK_LEVEL_OBJ_PHYSICS     0xF1
#define EDK_LEVEL_TILE_MAP        0xF2

//BONES
#define EDK_BVH_XY 0x00
#define EDK_BVH_XZ 0x01
#define EDK_BVH_YZ 0x02

//MARCROS
static void edk_nothing(){}
#define edk_printDebug(my_val) \
    printf("\n%s [%u] ",__FILE__,__LINE__); \
    printf(my_val); \
    printf(" (%s)",__FUNCTION__); \
    edk_nothing()

//
namespace edk{
//SFML 1.6
/*
    namespace key{
        enum code{
            A = 'a',
            B = 'b',
            C = 'c',
            D = 'd',
            E = 'e',
            F = 'f',
            G = 'g',
            H = 'h',
            I = 'i',
            J = 'j',
            K = 'k',
            L = 'l',
            M = 'm',
            N = 'n',
            O = 'o',
            P = 'p',
            Q = 'q',
            R = 'r',
            S = 's',
            T = 't',
            U = 'u',
            V = 'v',
            W = 'w',
            X = 'x',
            Y = 'y',
            Z = 'z',
            num0 = '0',
            num1 = '1',
            num2 = '2',
            num3 = '3',
            num4 = '4',
            num5 = '5',
            num6 = '6',
            num7 = '7',
            num8 = '8',
            num9 = '9',
            escape = 256,
            lControl,
            lShift,
            lAlt,
            lSystem,
            rControl,
            rShift,
            rAlt,
            rSystem,
            menu,
            lBracket,
            rBracket,
            semiColon,
            comma,
            period,
            quote,
            slash,
            backSlash,
            tilde,
            equal,
            dash,
            space,
            back,
            tab,
            pageUp,
            pageDown,
            end,
            home,
            insert,
            deleteKey,
            add,
            subtract,
            multiply,
            divide,
            left,
            right,
            up,
            down,
            numPad0,
            numPad1,
            numPad2,
            numPad3,
            numPad4,
            numPad5,
            numPad6,
            numPad7,
            numPad8,
            numPad9,
            F1,
            F2,
            F3,
            F4,
            F5,
            F6,
            F7,
            F8,
            F9,
            F10,
            F11,
            F12,
            F13,
            F14,
            F15,
            pause
        };
        namespace state{
            enum id{
                pressed,
                released,
                held
            };
        }
    }
    */
//SFML 2.0

namespace key{
enum code{
    num0 = '0',
    num1 = '1',
    num2 = '2',
    num3 = '3',
    num4 = '4',
    num5 = '5',
    num6 = '6',
    num7 = '7',
    num8 = '8',
    num9 = '9',
    A = 'a',
    B = 'b',
    C = 'c',
    D = 'd',
    E = 'e',
    F = 'f',
    G = 'g',
    H = 'h',
    I = 'i',
    J = 'j',
    K = 'k',
    L = 'l',
    M = 'm',
    N = 'n',
    O = 'o',
    P = 'p',
    Q = 'q',
    R = 'r',
    S = 's',
    T = 't',
    U = 'u',
    V = 'v',
    W = 'w',
    X = 'x',
    Y = 'y',
    Z = 'z',
    escape=256,
    lControl,
    lShift,
    lAlt,
    lSystem,
    rControl,
    rShift,
    rAlt,
    rSystem,
    menu,
    lBracket,
    rBracket,
    semiColon,
    comma,
    period,
    quote,
    slash,
    backSlash,
    tilde,
    equal,
    dash,
    space,
    Return,
    backSpace,
    tab,
    pageUp,
    pageDown,
    end,
    home,
    insert,
    Delete,
    add,
    subtract,
    multiply,
    divide,
    left,
    right,
    up,
    down,
    numpad0,
    numpad1,
    numpad2,
    numpad3,
    numpad4,
    numpad5,
    numpad6,
    numpad7,
    numpad8,
    numpad9,
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12,
    F13,
    F14,
    F15,
    pause
};
namespace state{
enum id{
    pressed,
    released,
    held
};
}
}
//MOUSE
namespace mouse{
enum button{
    left=1u,
    right,
    middle,
    xButton1,
    xButton2
};
namespace state{
enum id{
    pressed,
    released,
    moved
};
}
}
namespace buttonView{
//
namespace state{
//
enum id{
    normal,
    pressed,
    up
};
}
}
/*
    namespace controller{
        enum Axis
        {
            AxisX,
            AxisY,
            AxisZ,
            AxisR,
            AxisU,
            AxisV,
            AxisPOV
        };
    }
*/

namespace physics{
enum bodyType
{
    StaticBody = 0u,
    KinematicBody,
    DynamicBody
};
}
}//end namespace

#endif // TYPEDEFINES_H
