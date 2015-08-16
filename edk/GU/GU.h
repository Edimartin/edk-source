#ifndef EDK_GU_H
#define EDK_GU_H

/*
Library GU - Graphic Unit to draw polygons in the video board
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
#warning "Inside GU"
#endif

#pragma once
#include "../TypeVars.h"
#include "../TypeVec2.h"
#include "../TypeVec3.h"
#include "../TypeColor.h"
#include "../TypeRect.h"
#include "../TypeSize2.h"
#include "../TypeSize3.h"

//include the SHD before GU
#include "../GU/GU_GLSL.h"

#if defined(_WIN32) || defined(__linux__)
#include <GL/gl.h>
#include <GL/glu.h>
#elif defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
//#include <X11/X.h>
//#include <X11/keysym.h>
#endif

#ifdef printMessages
#warning "    Compiling GU"
#endif

/*LIBS WINDOWS

-lgl
-lglu
-lglew

*/

/*LIBS LINUX

-lGL
-lGLU
-lGLEW

*/

/*LIBS MAC

-framework OpenGL
-framework CocoamodelViewProjMatrixLoc

*/



/*
// Data types
#define GU_BYTE                                 0x1400
#define GU_UNSIGNED_BYTE                        0x1401
#define GU_SHORT                                0x1402
#define GU_UNSIGNED_SHORT                       0x1403
#define GU_INT                                  0x1404
#define GU_UNSIGNED_INT                         0x1405
#define GU_FLOAT                                0x1406
#define GU_DOUBLE                               0x140A
#define GU_2_BYTES                              0x1407
#define GU_3_BYTES                              0x1408
#define GU_4_BYTES                              0x1409

// Primitives
#define GU_POINTS                               0x0000
#define GU_LINES                                0x0001
#define GU_LINE_LOOP                            0x0002
#define GU_LINE_STRIP                           0x0003
#define GU_TRIANGLES                            0x0004
#define GU_TRIANGLE_STRIP                       0x0005
#define GU_TRIANGLE_FAN                         0x0006
#define GU_QUADS                                0x0007
#define GU_QUAD_STRIP                           0x0008
#define GU_POLYGON                              0x0009

// Vertex Arrays
#define GU_VERTEX_ARRAY                         0x8074
#define GU_NORMAL_ARRAY                         0x8075
#define GU_COLOR_ARRAY                          0x8076
#define GU_INDEX_ARRAY                          0x8077
#define GU_TEXTURE_COORD_ARRAY                  0x8078
#define GU_EDGE_FLAG_ARRAY                      0x8079
#define GU_VERTEX_ARRAY_SIZE                    0x807A
#define GU_VERTEX_ARRAY_TYPE                    0x807B
#define GU_VERTEX_ARRAY_STRIDE                  0x807C
#define GU_NORMAL_ARRAY_TYPE                    0x807E
#define GU_NORMAL_ARRAY_STRIDE                  0x807F
#define GU_COLOR_ARRAY_SIZE                     0x8081
#define GU_COLOR_ARRAY_TYPE                     0x8082
#define GU_COLOR_ARRAY_STRIDE                   0x8083
#define GU_INDEX_ARRAY_TYPE                     0x8085
#define GU_INDEX_ARRAY_STRIDE                   0x8086
#define GU_TEXTURE_COORD_ARRAY_SIZE             0x8088
#define GU_TEXTURE_COORD_ARRAY_TYPE             0x8089
#define GU_TEXTURE_COORD_ARRAY_STRIDE           0x808A
#define GU_EDGE_FLAG_ARRAY_STRIDE               0x808C
#define GU_VERTEX_ARRAY_POINTER                 0x808E
#define GU_NORMAL_ARRAY_POINTER                 0x808F
#define GU_COLOR_ARRAY_POINTER                  0x8090
#define GU_INDEX_ARRAY_POINTER                  0x8091
#define GU_TEXTURE_COORD_ARRAY_POINTER          0x8092
#define GU_EDGE_FLAG_ARRAY_POINTER              0x8093
#define GU_V2F                                  0x2A20
#define GU_V3F                                  0x2A21
#define GU_C4UB_V2F                             0x2A22
#define GU_C4UB_V3F                             0x2A23
#define GU_C3F_V3F                              0x2A24
#define GU_N3F_V3F                              0x2A25
#define GU_C4F_N3F_V3F                          0x2A26
#define GU_T2F_V3F                              0x2A27
#define GU_T4F_V4F                              0x2A28
#define GU_T2F_C4UB_V3F                         0x2A29
#define GU_T2F_C3F_V3F                          0x2A2A
#define GU_T2F_N3F_V3F                          0x2A2B
#define GU_T2F_C4F_N3F_V3F                      0x2A2C
#define GU_T4F_C4F_N3F_V4F                      0x2A2D

// Matrix Mode
#define GU_MATRIX_MODE                          0x0BA0
#define GU_MODELVIEW                            0x1700
#define GU_PROJECTION                           0x1701
#define GU_TEXTURE                              0x1702

// Points
#define GU_POINT_SMOOTH                         0x0B10
#define GU_POINT_SIZE                           0x0B11
#define GU_POINT_SIZE_GRANULARITY               0x0B13
#define GU_POINT_SIZE_RANGE                     0x0B12

// Lines
#define GU_LINE_SMOOTH                          0x0B20
#define GU_LINE_STIPPLE                         0x0B24
#define GU_LINE_STIPPLE_PATTERN                 0x0B25
#define GU_LINE_STIPPLE_REPEAT                  0x0B26
#define GU_LINE_WIDTH                           0x0B21
#define GU_LINE_WIDTH_GRANULARITY               0x0B23
#define GU_LINE_WIDTH_RANGE                     0x0B22

// Polygons
#define GU_POINT                                0x1B00
#define GU_LINE                                 0x1B01
#define GU_FILL                                 0x1B02
#define GU_CW                                   0x0900
#define GU_CCW                                  0x0901
#define GU_FRONT                                0x0404
#define GU_BACK                                 0x0405
#define GU_POLYGON_MODE                         0x0B40
#define GU_POLYGON_SMOOTH                       0x0B41
#define GU_POLYGON_STIPPLE                      0x0B42
#define GU_EDGE_FLAG                            0x0B43
#define GU_CULL_FACE                            0x0B44
#define GU_CULL_FACE_MODE                       0x0B45
#define GU_FRONT_FACE                           0x0B46
#define GU_POLYGON_OFFSET_FACTOR                0x8038
#define GU_POLYGON_OFFSET_UNITS                 0x2A00
#define GU_POLYGON_OFFSET_POINT                 0x2A01
#define GU_POLYGON_OFFSET_LINE                  0x2A02
#define GU_POLYGON_OFFSET_FILL                  0x8037

// Display Lists
#define GU_COMPILE                              0x1300
#define GU_COMPILE_AND_EXECUTE                  0x1301
#define GU_LIST_BASE                            0x0B32
#define GU_LIST_INDEX                           0x0B33
#define GU_LIST_MODE                            0x0B30

// Depth buffer
#define GU_NEVER                                0x0200
#define GU_LESS                                 0x0201
#define GU_EQUAL                                0x0202
#define GU_LEQUAL                               0x0203
#define GU_GREATER                              0x0204
#define GU_NOTEQUAL                             0x0205
#define GU_GEQUAL                               0x0206
#define GU_ALWAYS                               0x0207
#define GU_DEPTH_TEST                           0x0B71
#define GU_DEPTH_BITS                           0x0D56
#define GU_DEPTH_CLEAR_VALUE                    0x0B73
#define GU_DEPTH_FUNC                           0x0B74
#define GU_DEPTH_RANGE                          0x0B70
#define GU_DEPTH_WRITEMASK                      0x0B72
#define GU_DEPTH_COMPONENT                      0x1902

// Lighting
#define GU_LIGHTING                             0x0B50
#define GU_LIGHT0                               0x4000
#define GU_LIGHT1                               0x4001
#define GU_LIGHT2                               0x4002
#define GU_LIGHT3                               0x4003
#define GU_LIGHT4                               0x4004
#define GU_LIGHT5                               0x4005
#define GU_LIGHT6                               0x4006
#define GU_LIGHT7                               0x4007
#define GU_SPOT_EXPONENT                        0x1205
#define GU_SPOT_CUTOFF                          0x1206
#define GU_CONSTANT_ATTENUATION                 0x1207
#define GU_LINEAR_ATTENUATION                   0x1208
#define GU_QUADRATIC_ATTENUATION                0x1209
#define GU_AMBIENT                              0x1200
#define GU_DIFFUSE                              0x1201
#define GU_SPECULAR                             0x1202
#define GU_SHININESS                            0x1601
#define GU_EMISSION                             0x1600
#define GU_POSITION                             0x1203
#define GU_SPOT_DIRECTION                       0x1204
#define GU_AMBIENT_AND_DIFFUSE                  0x1602
#define GU_COLOR_INDEXES                        0x1603
#define GU_LIGHT_MODEL_TWO_SIDE                 0x0B52
#define GU_LIGHT_MODEL_LOCAL_VIEWER             0x0B51
#define GU_LIGHT_MODEL_AMBIENT                  0x0B53
#define GU_FRONT_AND_BACK                       0x0408
#define GU_SHADE_MODEL                          0x0B54
#define GU_FLAT                                 0x1D00
#define GU_SMOOTH                               0x1D01
#define GU_COLOR_MATERIAL                       0x0B57
#define GU_COLOR_MATERIAL_FACE                  0x0B55
#define GU_COLOR_MATERIAL_PARAMETER             0x0B56
#define GU_NORMALIZE                            0x0BA1

// User clipping planes
#define GU_CLIP_PLANE0                          0x3000
#define GU_CLIP_PLANE1                          0x3001
#define GU_CLIP_PLANE2                          0x3002
#define GU_CLIP_PLANE3                          0x3003
#define GU_CLIP_PLANE4                          0x3004
#define GU_CLIP_PLANE5                          0x3005

// Accumulation buffer
#define GU_ACCUM_RED_BITS                       0x0D58
#define GU_ACCUM_GREEN_BITS                     0x0D59
#define GU_ACCUM_BLUE_BITS                      0x0D5A
#define GU_ACCUM_ALPHA_BITS                     0x0D5B
#define GU_ACCUM_CLEAR_VALUE                    0x0B80
#define GU_ACCUM                                0x0100
#define GU_ADD                                  0x0104
#define GU_LOAD                                 0x0101
#define GU_MULT                                 0x0103
#define GU_RETURN                               0x0102

// Alpha testing
#define GU_ALPHA_TEST                           0x0BC0
#define GU_ALPHA_TEST_REF                       0x0BC2
#define GU_ALPHA_TEST_FUNC                      0x0BC1

// Blending
#define GU_BLEND                                0x0BE2
#define GU_BLEND_SRC                            0x0BE1
#define GU_BLEND_DST                            0x0BE0
#define GU_ZERO                                 0x0
#define GU_ONE                                  0x1
#define GU_SRC_COLOR                            0x0300
#define GU_ONE_MINUS_SRC_COLOR                  0x0301
#define GU_SRC_ALPHA                            0x0302
#define GU_ONE_MINUS_SRC_ALPHA                  0x0303
#define GU_DST_ALPHA                            0x0304
#define GU_ONE_MINUS_DST_ALPHA                  0x0305
#define GU_DST_COLOR                            0x0306
#define GU_ONE_MINUS_DST_COLOR                  0x0307
#define GU_SRC_ALPHA_SATURATE                   0x0308
#define GU_CONSTANT_COLOR                       0x8001
#define GU_ONE_MINUS_CONSTANT_COLOR             0x8002
#define GU_CONSTANT_ALPHA                       0x8003
#define GU_ONE_MINUS_CONSTANT_ALPHA             0x8004

// Render Mode
#define GU_FEEDBACK                             0x1C01
#define GU_RENDER                               0x1C00
#define GU_SELECT                               0x1C02

// Feedback
#define GU_2D                                   0x0600
#define GU_3D                                   0x0601
#define GU_3D_COLOR                             0x0602
#define GU_3D_COLOR_TEXTURE                     0x0603
#define GU_4D_COLOR_TEXTURE                     0x0604
#define GU_POINT_TOKEN                          0x0701
#define GU_LINE_TOKEN                           0x0702
#define GU_LINE_RESET_TOKEN                     0x0707
#define GU_POLYGON_TOKEN                        0x0703
#define GU_BITMAP_TOKEN                         0x0704
#define GU_DRAW_PIXEL_TOKEN                     0x0705
#define GU_COPY_PIXEL_TOKEN                     0x0706
#define GU_PASS_THROUGH_TOKEN                   0x0700
#define GU_FEEDBACK_BUFFER_POINTER              0x0DF0
#define GU_FEEDBACK_BUFFER_SIZE                 0x0DF1
#define GU_FEEDBACK_BUFFER_TYPE                 0x0DF2

// Selection
#define GU_SELECTION_BUFFER_POINTER             0x0DF3
#define GU_SELECTION_BUFFER_SIZE                0x0DF4

// Fog
#define GU_FOG                                  0x0B60
#define GU_FOG_MODE                             0x0B65
#define GU_FOG_DENSITY                          0x0B62
#define GU_FOG_COLOR                            0x0B66
#define GU_FOG_INDEX                            0x0B61
#define GU_FOG_START                            0x0B63
#define GU_FOG_END                              0x0B64
#define GU_LINEAR                               0x2601
#define GU_EXP                                  0x0800
#define GU_EXP2                                 0x0801

// Logic Ops
#define GU_LOGIC_OP                             0x0BF1
#define GU_INDEX_LOGIC_OP                       0x0BF1
#define GU_COLOR_LOGIC_OP                       0x0BF2
#define GU_LOGIC_OP_MODE                        0x0BF0
#define GU_CLEAR                                0x1500
#define GU_SET                                  0x150F
#define GU_COPY                                 0x1503
#define GU_COPY_INVERTED                        0x150C
#define GU_NOOP                                 0x1505
#define GU_INVERT                               0x150A
#define GU_AND                                  0x1501
#define GU_NAND                                 0x150E
#define GU_OR                                   0x1507
#define GU_NOR                                  0x1508
#define GU_XOR                                  0x1506
#define GU_EQUIV                                0x1509
#define GU_AND_REVERSE                          0x1502
#define GU_AND_INVERTED                         0x1504
#define GU_OR_REVERSE                           0x150B
#define GU_OR_INVERTED                          0x150D

// Stencil
#define GU_STENCIL_TEST                         0x0B90
#define GU_STENCIL_WRITEMASK                    0x0B98
#define GU_STENCIL_BITS                         0x0D57
#define GU_STENCIL_FUNC                         0x0B92
#define GU_STENCIL_VALUE_MASK                   0x0B93
#define GU_STENCIL_REF                          0x0B97
#define GU_STENCIL_FAIL                         0x0B94
#define GU_STENCIL_PASS_DEPTH_PASS              0x0B96
#define GU_STENCIL_PASS_DEPTH_FAIL              0x0B95
#define GU_STENCIL_CLEAR_VALUE                  0x0B91
#define GU_STENCIL_INDEX                        0x1901
#define GU_KEEP                                 0x1E00
#define GU_REPLACE                              0x1E01
#define GU_INCR                                 0x1E02
#define GU_DECR                                 0x1E03

// Buffers, Pixel Drawing/Reading
#define GU_NONE                                 0x0
#define GU_LEFT                                 0x0406
#define GU_RIGHT                                0x0407
#define GU_FRONT                                0x0404
#define GU_BACK                                 0x0405
#define GU_FRONT_AND_BACK                       0x0408
#define GU_FRONT_LEFT                           0x0400
#define GU_FRONT_RIGHT                          0x0401
#define GU_BACK_LEFT                            0x0402
#define GU_BACK_RIGHT                           0x0403
#define GU_AUX0                                 0x0409
#define GU_AUX1                                 0x040A
#define GU_AUX2                                 0x040B
#define GU_AUX3                                 0x040C
#define GU_COLOR_INDEX                          0x1900
#define GU_RED                                  0x1903
#define GU_GREEN                                0x1904
#define GU_BLUE                                 0x1905
#define GU_ALPHA                                0x1906
#define GU_LUMINANCE                            0x1909
#define GU_LUMINANCE_ALPHA                      0x190A
#define GU_ALPHA_BITS                           0x0D55
#define GU_RED_BITS                             0x0D52
#define GU_GREEN_BITS                           0x0D53
#define GU_BLUE_BITS                            0x0D54
#define GU_INDEX_BITS                           0x0D51
#define GU_SUBPIXEL_BITS                        0x0D50
#define GU_AUX_BUFFERS                          0x0C00
#define GU_READ_BUFFER                          0x0C02
#define GU_DRAW_BUFFER                          0x0C01
#define GU_DOUBLEBUFFER                         0x0C32
#define GU_STEREO                               0x0C33
#define GU_BITMAP                               0x1A00
#define GU_COLOR                                0x1800
#define GU_DEPTH                                0x1801
#define GU_STENCIL                              0x1802
#define GU_DITHER                               0x0BD0
#define GU_RGB                                  0x1907
#define GU_RGBA                                 0x1908

// Implementation limits
#define GU_MAX_LIST_NESTING                     0x0B31
#define GU_MAX_ATTRIB_STACK_DEPTH               0x0D35
#define GU_MAX_MODELVIEW_STACK_DEPTH            0x0D36
#define GU_MAX_NAME_STACK_DEPTH                 0x0D37
#define GU_MAX_PROJECTION_STACK_DEPTH           0x0D38
#define GU_MAX_TEXTURE_STACK_DEPTH              0x0D39
#define GU_MAX_EVAL_ORDER                       0x0D30
#define GU_MAX_LIGHTS                           0x0D31
#define GU_MAX_CLIP_PLANES                      0x0D32
#define GU_MAX_TEXTURE_SIZE                     0x0D33
#define GU_MAX_PIXEL_MAP_TABLE                  0x0D34
#define GU_MAX_VIEWPORT_DIMS                    0x0D3A
#define GU_MAX_CLIENT_ATTRIB_STACK_DEPTH        0x0D3B

// Gets
#define GU_ATTRIB_STACK_DEPTH                   0x0BB0
#define GU_CLIENT_ATTRIB_STACK_DEPTH            0x0BB1
#define GU_COLOR_CLEAR_VALUE                    0x0C22
#define GU_COLOR_WRITEMASK                      0x0C23
#define GU_CURRENT_INDEX                        0x0B01
#define GU_CURRENT_COLOR                        0x0B00
#define GU_CURRENT_NORMAL                       0x0B02
#define GU_CURRENT_RASTER_COLOR                 0x0B04
#define GU_CURRENT_RASTER_DISTANCE              0x0B09
#define GU_CURRENT_RASTER_INDEX                 0x0B05
#define GU_CURRENT_RASTER_POSITION              0x0B07
#define GU_CURRENT_RASTER_TEXTURE_COORDS        0x0B06
#define GU_CURRENT_RASTER_POSITION_VALID        0x0B08
#define GU_CURRENT_TEXTURE_COORDS               0x0B03
#define GU_INDEX_CLEAR_VALUE                    0x0C20
#define GU_INDEX_MODE                           0x0C30
#define GU_INDEX_WRITEMASK                      0x0C21
#define GU_MODELVIEW_MATRIX                     0x0BA6
#define GU_MODELVIEW_STACK_DEPTH                0x0BA3
#define GU_NAME_STACK_DEPTH                     0x0D70
#define GU_PROJECTION_MATRIX                    0x0BA7
#define GU_PROJECTION_STACK_DEPTH               0x0BA4
#define GU_RENDER_MODE                          0x0C40
#define GU_RGBA_MODE                            0x0C31
#define GU_TEXTURE_MATRIX                       0x0BA8
#define GU_TEXTURE_STACK_DEPTH                  0x0BA5
#define GU_VIEWPORT                             0x0BA2

// Evaluators
#define GU_AUTO_NORMAL                          0x0D80
#define GU_MAP1_COLOR_4                         0x0D90
#define GU_MAP1_GRID_DOMAIN                     0x0DD0
#define GU_MAP1_GRID_SEGMENTS                   0x0DD1
#define GU_MAP1_INDEX                           0x0D91
#define GU_MAP1_NORMAL                          0x0D92
#define GU_MAP1_TEXTURE_COORD_1                 0x0D93
#define GU_MAP1_TEXTURE_COORD_2                 0x0D94
#define GU_MAP1_TEXTURE_COORD_3                 0x0D95
#define GU_MAP1_TEXTURE_COORD_4                 0x0D96
#define GU_MAP1_VERTEX_3                        0x0D97
#define GU_MAP1_VERTEX_4                        0x0D98
#define GU_MAP2_COLOR_4                         0x0DB0
#define GU_MAP2_GRID_DOMAIN                     0x0DD2
#define GU_MAP2_GRID_SEGMENTS                   0x0DD3
#define GU_MAP2_INDEX                           0x0DB1
#define GU_MAP2_NORMAL                          0x0DB2
#define GU_MAP2_TEXTURE_COORD_1                 0x0DB3
#define GU_MAP2_TEXTURE_COORD_2                 0x0DB4
#define GU_MAP2_TEXTURE_COORD_3                 0x0DB5
#define GU_MAP2_TEXTURE_COORD_4                 0x0DB6
#define GU_MAP2_VERTEX_3                        0x0DB7
#define GU_MAP2_VERTEX_4                        0x0DB8
#define GU_COEFF                                0x0A00
#define GU_DOMAIN                               0x0A02
#define GU_ORDER                                0x0A01

// Hints
#define GU_FOG_HINT                             0x0C54
#define GU_LINE_SMOOTH_HINT                     0x0C52
#define GU_PERSPECTIVE_CORRECTION_HINT          0x0C50
#define GU_POINT_SMOOTH_HINT                    0x0C51
#define GU_POLYGON_SMOOTH_HINT                  0x0C53
#define GU_DONT_CARE                            0x1100
#define GU_FASTEST                              0x1101
#define GU_NICEST                               0x1102

// Scissor box
#define GU_SCISSOR_TEST                         0x0C11
#define GU_SCISSOR_BOX                          0x0C10

// Pixel Mode / Transfer
#define GU_MAP_COLOR                            0x0D10
#define GU_MAP_STENCIL                          0x0D11
#define GU_INDEX_SHIFT                          0x0D12
#define GU_INDEX_OFFSET                         0x0D13
#define GU_RED_SCALE                            0x0D14
#define GU_RED_BIAS                             0x0D15
#define GU_GREEN_SCALE                          0x0D18
#define GU_GREEN_BIAS                           0x0D19
#define GU_BLUE_SCALE                           0x0D1A
#define GU_BLUE_BIAS                            0x0D1B
#define GU_ALPHA_SCALE                          0x0D1C
#define GU_ALPHA_BIAS                           0x0D1D
#define GU_DEPTH_SCALE                          0x0D1E
#define GU_DEPTH_BIAS                           0x0D1F
#define GU_PIXEL_MAP_S_TO_S_SIZE                0x0CB1
#define GU_PIXEL_MAP_I_TO_I_SIZE                0x0CB0
#define GU_PIXEL_MAP_I_TO_R_SIZE                0x0CB2
#define GU_PIXEL_MAP_I_TO_G_SIZE                0x0CB3
#define GU_PIXEL_MAP_I_TO_B_SIZE                0x0CB4
#define GU_PIXEL_MAP_I_TO_A_SIZE                0x0CB5
#define GU_PIXEL_MAP_R_TO_R_SIZE                0x0CB6
#define GU_PIXEL_MAP_G_TO_G_SIZE                0x0CB7
#define GU_PIXEL_MAP_B_TO_B_SIZE                0x0CB8
#define GU_PIXEL_MAP_A_TO_A_SIZE                0x0CB9
#define GU_PIXEL_MAP_S_TO_S                     0x0C71
#define GU_PIXEL_MAP_I_TO_I                     0x0C70
#define GU_PIXEL_MAP_I_TO_R                     0x0C72
#define GU_PIXEL_MAP_I_TO_G                     0x0C73
#define GU_PIXEL_MAP_I_TO_B                     0x0C74
#define GU_PIXEL_MAP_I_TO_A                     0x0C75
#define GU_PIXEL_MAP_R_TO_R                     0x0C76
#define GU_PIXEL_MAP_G_TO_G                     0x0C77
#define GU_PIXEL_MAP_B_TO_B                     0x0C78
#define GU_PIXEL_MAP_A_TO_A                     0x0C79
#define GU_PACK_ALIGNMENT                       0x0D05
#define GU_PACK_LSB_FIRST                       0x0D01
#define GU_PACK_ROW_LENGTH                      0x0D02
#define GU_PACK_SKIP_PIXELS                     0x0D04
#define GU_PACK_SKIP_ROWS                       0x0D03
#define GU_PACK_SWAP_BYTES                      0x0D00
#define GU_UNPACK_ALIGNMENT                     0x0CF5
#define GU_UNPACK_LSB_FIRST                     0x0CF1
#define GU_UNPACK_ROW_LENGTH                    0x0CF2
#define GU_UNPACK_SKIP_PIXELS                   0x0CF4
#define GU_UNPACK_SKIP_ROWS                     0x0CF3
#define GU_UNPACK_SWAP_BYTES                    0x0CF0
#define GU_ZOOM_X                               0x0D16
#define GU_ZOOM_Y                               0x0D17

// Texture mapping
#define GU_TEXTURE_ENV                          0x2300
#define GU_TEXTURE_ENV_MODE                     0x2200
#define GU_TEXTURE_1D                           0x0DE0
#define GU_TEXTURE_2D                           0x0DE1
#define GU_TEXTURE_WRAP_S                       0x2802
#define GU_TEXTURE_WRAP_T                       0x2803
#define GU_TEXTURE_MAG_FILTER                   0x2800
#define GU_TEXTURE_MIN_FILTER                   0x2801
#define GU_TEXTURE_ENV_COLOR                    0x2201
#define GU_TEXTURE_GEN_S                        0x0C60
#define GU_TEXTURE_GEN_T                        0x0C61
#define GU_TEXTURE_GEN_MODE                     0x2500
#define GU_TEXTURE_BORDER_COLOR                 0x1004
#define GU_TEXTURE_WIDTH                        0x1000
#define GU_TEXTURE_HEIGHT                       0x1001
#define GU_TEXTURE_BORDER                       0x1005
#define GU_TEXTURE_COMPONENTS                   0x1003
#define GU_TEXTURE_RED_SIZE                     0x805C
#define GU_TEXTURE_GREEN_SIZE                   0x805D
#define GU_TEXTURE_BLUE_SIZE                    0x805E
#define GU_TEXTURE_ALPHA_SIZE                   0x805F
#define GU_TEXTURE_LUMINANCE_SIZE               0x8060
#define GU_TEXTURE_INTENSITY_SIZE               0x8061
#define GU_NEAREST_MIPMAP_NEAREST               0x2700
#define GU_NEAREST_MIPMAP_LINEAR                0x2702
#define GU_LINEAR_MIPMAP_NEAREST                0x2701
#define GU_LINEAR_MIPMAP_LINEAR                 0x2703
#define GU_OBJECT_LINEAR                        0x2401
#define GU_OBJECT_PLANE                         0x2501
#define GU_EYE_LINEAR                           0x2400
#define GU_EYE_PLANE                            0x2502
#define GU_SPHERE_MAP                           0x2402
#define GU_DECAL                                0x2101
#define GU_MODULATE                             0x2100
#define GU_NEAREST                              0x2600
#define GU_REPEAT                               0x2901
#define GU_CLAMP                                0x2900
#define GU_S                                    0x2000
#define GU_T                                    0x2001
#define GU_R                                    0x2002
#define GU_Q                                    0x2003
#define GU_TEXTURE_GEN_R                        0x0C62
#define GU_TEXTURE_GEN_Q                        0x0C63

// Utility
#define GU_VENDOR                               0x1F00
#define GU_RENDERER                             0x1F01
#define GU_VERSION                              0x1F02
#define GU_EXTENSIONS                           0x1F03

// Errors
#define GU_NO_ERROR                             0x0
#define GU_INVALID_VALUE                        0x0501
#define GU_INVALID_ENUM                         0x0500
#define GU_INVALID_OPERATION                    0x0502
#define GU_STACK_OVERFLOW                       0x0503
#define GU_STACK_UNDERFLOW                      0x0504
#define GU_OUT_OF_MEMORY                        0x0505

// glPush/PopAttrib bits
#define GU_CURRENT_BIT                          0x00000001
#define GU_POINT_BIT                            0x00000002
#define GU_LINE_BIT                             0x00000004
#define GU_POLYGON_BIT                          0x00000008
#define GU_POLYGON_STIPPLE_BIT                  0x00000010
#define GU_PIXEL_MODE_BIT                       0x00000020
#define GU_LIGHTING_BIT                         0x00000040
#define GU_FOG_BIT                              0x00000080
#define GU_DEPTH_BUFFER_BIT                     0x00000100
#define GU_ACCUM_BUFFER_BIT                     0x00000200
#define GU_STENCIL_BUFFER_BIT                   0x00000400
#define GU_VIEWPORT_BIT                         0x00000800
#define GU_TRANSFORM_BIT                        0x00001000
#define GU_ENABLE_BIT                           0x00002000
#define GU_COLOR_BUFFER_BIT                     0x00004000
#define GU_HINT_BIT                             0x00008000
#define GU_EVAL_BIT                             0x00010000
#define GU_LIST_BIT                             0x00020000
#define GU_TEXTURE_BIT                          0x00040000
#define GU_SCISSOR_BIT                          0x00080000
#define GU_ALL_ATTRIB_BITS                      0x000FFFFF


// OpenGL 1.1
#define GU_PROXY_TEXTURE_1D                     0x8063
#define GU_PROXY_TEXTURE_2D                     0x8064
#define GU_TEXTURE_PRIORITY                     0x8066
#define GU_TEXTURE_RESIDENT                     0x8067
#define GU_TEXTURE_BINDING_1D                   0x8068
#define GU_TEXTURE_BINDING_2D                   0x8069
#define GU_TEXTURE_INTERNAL_FORMAT              0x1003
#define GU_ALPHA4                               0x803B
#define GU_ALPHA8                               0x803C
#define GU_ALPHA12                              0x803D
#define GU_ALPHA16                              0x803E
#define GU_LUMINANCE4                           0x803F
#define GU_LUMINANCE8                           0x8040
#define GU_LUMINANCE12                          0x8041
#define GU_LUMINANCE16                          0x8042
#define GU_LUMINANCE4_ALPHA4                    0x8043
#define GU_LUMINANCE6_ALPHA2                    0x8044
#define GU_LUMINANCE8_ALPHA8                    0x8045
#define GU_LUMINANCE12_ALPHA4                   0x8046
#define GU_LUMINANCE12_ALPHA12                  0x8047
#define GU_LUMINANCE16_ALPHA16                  0x8048
#define GU_INTENSITY                            0x8049
#define GU_INTENSITY4                           0x804A
#define GU_INTENSITY8                           0x804B
#define GU_INTENSITY12                          0x804C
#define GU_INTENSITY16                          0x804D
#define GU_R3_G3_B2                             0x2A10
#define GU_RGB4                                 0x804F
#define GU_RGB5                                 0x8050
#define GU_RGB8                                 0x8051
#define GU_RGB10                                0x8052
#define GU_RGB12                                0x8053
#define GU_RGB16                                0x8054
#define GU_RGBA2                                0x8055
#define GU_RGBA4                                0x8056
#define GU_RGB5_A1                              0x8057
#define GU_RGBA8                                0x8058
#define GU_RGB10_A2                             0x8059
#define GU_RGBA12                               0x805A
#define GU_RGBA16                               0x805B
#define GU_CLIENT_PIXEL_STORE_BIT               0x00000001
#define GU_CLIENT_VERTEX_ARRAY_BIT              0x00000002
#define GU_ALL_CLIENT_ATTRIB_BITS               0xFFFFFFFF
#define GU_CLIENT_ALL_ATTRIB_BITS               0xFFFFFFFF














// Under Windows, we do not define OpenGL 1.2 & 1.3 functionality, since
   it is treated as extensions (defined in glext.h)
#if !defined(__WIN32__)

// OpenGL 1.2
#define GU_RESCALE_NORMAL                       0x803A
#define GU_CLAMP_TO_EDGE                        0x812F
#define GU_MAX_ELEMENTS_VERTICES                0x80E8
#define GU_MAX_ELEMENTS_INDICES                 0x80E9
#define GU_BGR                                  0x80E0
#define GU_BGRA                                 0x80E1
#define GU_UNSIGNED_BYTE_3_3_2                  0x8032
#define GU_UNSIGNED_BYTE_2_3_3_REV              0x8362
#define GU_UNSIGNED_SHORT_5_6_5                 0x8363
#define GU_UNSIGNED_SHORT_5_6_5_REV             0x8364
#define GU_UNSIGNED_SHORT_4_4_4_4               0x8033
#define GU_UNSIGNED_SHORT_4_4_4_4_REV           0x8365
#define GU_UNSIGNED_SHORT_5_5_5_1               0x8034
#define GU_UNSIGNED_SHORT_1_5_5_5_REV           0x8366
#define GU_UNSIGNED_INT_8_8_8_8                 0x8035
#define GU_UNSIGNED_INT_8_8_8_8_REV             0x8367
#define GU_UNSIGNED_INT_10_10_10_2              0x8036
#define GU_UNSIGNED_INT_2_10_10_10_REV          0x8368
#define GU_LIGHT_MODEL_COLOR_CONTROL            0x81F8
#define GU_SINGLE_COLOR                         0x81F9
#define GU_SEPARATE_SPECULAR_COLOR              0x81FA
#define GU_TEXTURE_MIN_LOD                      0x813A
#define GU_TEXTURE_MAX_LOD                      0x813B
#define GU_TEXTURE_BASE_LEVEL                   0x813C
#define GU_TEXTURE_MAX_LEVEL                    0x813D
#define GU_SMOOTH_POINT_SIZE_RANGE              0x0B12
#define GU_SMOOTH_POINT_SIZE_GRANULARITY        0x0B13
#define GU_SMOOTH_LINE_WIDTH_RANGE              0x0B22
#define GU_SMOOTH_LINE_WIDTH_GRANULARITY        0x0B23
#define GU_ALIASED_POINT_SIZE_RANGE             0x846D
#define GU_ALIASED_LINE_WIDTH_RANGE             0x846E
#define GU_PACK_SKIP_IMAGES                     0x806B
#define GU_PACK_IMAGE_HEIGHT                    0x806C
#define GU_UNPACK_SKIP_IMAGES                   0x806D
#define GU_UNPACK_IMAGE_HEIGHT                  0x806E
#define GU_TEXTURE_3D                           0x806F
#define GU_PROXY_TEXTURE_3D                     0x8070
#define GU_TEXTURE_DEPTH                        0x8071
#define GU_TEXTURE_WRAP_R                       0x8072
#define GU_MAX_3D_TEXTURE_SIZE                  0x8073
#define GU_TEXTURE_BINDING_3D                   0x806A

// OpenGL 1.2 imaging subset
// GU_EXT_color_table
#define GU_COLOR_TABLE                          0x80D0
#define GU_POST_CONVOLUTION_COLOR_TABLE         0x80D1
#define GU_POST_COLOR_MATRIX_COLOR_TABLE        0x80D2
#define GU_PROXY_COLOR_TABLE                    0x80D3
#define GU_PROXY_POST_CONVOLUTION_COLOR_TABLE   0x80D4
#define GU_PROXY_POST_COLOR_MATRIX_COLOR_TABLE  0x80D5
#define GU_COLOR_TABLE_SCALE                    0x80D6
#define GU_COLOR_TABLE_BIAS                     0x80D7
#define GU_COLOR_TABLE_FORMAT                   0x80D8
#define GU_COLOR_TABLE_WIDTH                    0x80D9
#define GU_COLOR_TABLE_RED_SIZE                 0x80DA
#define GU_COLOR_TABLE_GREEN_SIZE               0x80DB
#define GU_COLOR_TABLE_BLUE_SIZE                0x80DC
#define GU_COLOR_TABLE_ALPHA_SIZE               0x80DD
#define GU_COLOR_TABLE_LUMINANCE_SIZE           0x80DE
#define GU_COLOR_TABLE_INTENSITY_SIZE           0x80DF
// GU_EXT_convolution and GU_HP_convolution_border_modes
#define GU_CONVOLUTION_1D                       0x8010
#define GU_CONVOLUTION_2D                       0x8011
#define GU_SEPARABLE_2D                         0x8012
#define GU_CONVOLUTION_BORDER_MODE              0x8013
#define GU_CONVOLUTION_FILTER_SCALE             0x8014
#define GU_CONVOLUTION_FILTER_BIAS              0x8015
#define GU_REDUCE                               0x8016
#define GU_CONVOLUTION_FORMAT                   0x8017
#define GU_CONVOLUTION_WIDTH                    0x8018
#define GU_CONVOLUTION_HEIGHT                   0x8019
#define GU_MAX_CONVOLUTION_WIDTH                0x801A
#define GU_MAX_CONVOLUTION_HEIGHT               0x801B
#define GU_POST_CONVOLUTION_RED_SCALE           0x801C
#define GU_POST_CONVOLUTION_GREEN_SCALE         0x801D
#define GU_POST_CONVOLUTION_BLUE_SCALE          0x801E
#define GU_POST_CONVOLUTION_ALPHA_SCALE         0x801F
#define GU_POST_CONVOLUTION_RED_BIAS            0x8020
#define GU_POST_CONVOLUTION_GREEN_BIAS          0x8021
#define GU_POST_CONVOLUTION_BLUE_BIAS           0x8022
#define GU_POST_CONVOLUTION_ALPHA_BIAS          0x8023
#define GU_CONSTANT_BORDER                      0x8151
#define GU_REPLICATE_BORDER                     0x8153
#define GU_CONVOLUTION_BORDER_COLOR             0x8154
// GU_SGI_color_matrix
#define GU_COLOR_MATRIX                         0x80B1
#define GU_COLOR_MATRIX_STACK_DEPTH             0x80B2
#define GU_MAX_COLOR_MATRIX_STACK_DEPTH         0x80B3
#define GU_POST_COLOR_MATRIX_RED_SCALE          0x80B4
#define GU_POST_COLOR_MATRIX_GREEN_SCALE        0x80B5
#define GU_POST_COLOR_MATRIX_BLUE_SCALE         0x80B6
#define GU_POST_COLOR_MATRIX_ALPHA_SCALE        0x80B7
#define GU_POST_COLOR_MATRIX_RED_BIAS           0x80B8
#define GU_POST_COLOR_MATRIX_GREEN_BIAS         0x80B9
#define GU_POST_COLOR_MATRIX_BLUE_BIAS          0x80BA
#define GU_POST_COLOR_MATRIX_ALPHA_BIAS         0x80BB
// GU_EXT_histogram
#define GU_HISTOGRAM                            0x8024
#define GU_PROXY_HISTOGRAM                      0x8025
#define GU_HISTOGRAM_WIDTH                      0x8026
#define GU_HISTOGRAM_FORMAT                     0x8027
#define GU_HISTOGRAM_RED_SIZE                   0x8028
#define GU_HISTOGRAM_GREEN_SIZE                 0x8029
#define GU_HISTOGRAM_BLUE_SIZE                  0x802A
#define GU_HISTOGRAM_ALPHA_SIZE                 0x802B
#define GU_HISTOGRAM_LUMINANCE_SIZE             0x802C
#define GU_HISTOGRAM_SINK                       0x802D
#define GU_MINMAX                               0x802E
#define GU_MINMAX_FORMAT                        0x802F
#define GU_MINMAX_SINK                          0x8030
#define GU_TABLE_TOO_LARGE                      0x8031
// GU_EXT_blend_color, GU_EXT_blend_minmax
#define GU_BLEND_EQUATION                       0x8009
#define GU_MIN                                  0x8007
#define GU_MAX                                  0x8008
#define GU_FUNC_ADD                             0x8006
#define GU_FUNC_SUBTRACT                        0x800A
#define GU_FUNC_REVERSE_SUBTRACT                0x800B
#define GU_BLEND_COLOR                          0x8005


// OpenGL 1.3
// multitexture
#define GU_TEXTURE0                             0x84C0
#define GU_TEXTURE1                             0x84C1
#define GU_TEXTURE2                             0x84C2
#define GU_TEXTURE3                             0x84C3
#define GU_TEXTURE4                             0x84C4
#define GU_TEXTURE5                             0x84C5
#define GU_TEXTURE6                             0x84C6
#define GU_TEXTURE7                             0x84C7
#define GU_TEXTURE8                             0x84C8
#define GU_TEXTURE9                             0x84C9
#define GU_TEXTURE10                            0x84CA
#define GU_TEXTURE11                            0x84CB
#define GU_TEXTURE12                            0x84CC
#define GU_TEXTURE13                            0x84CD
#define GU_TEXTURE14                            0x84CE
#define GU_TEXTURE15                            0x84CF
#define GU_TEXTURE16                            0x84D0
#define GU_TEXTURE17                            0x84D1
#define GU_TEXTURE18                            0x84D2
#define GU_TEXTURE19                            0x84D3
#define GU_TEXTURE20                            0x84D4
#define GU_TEXTURE21                            0x84D5
#define GU_TEXTURE22                            0x84D6
#define GU_TEXTURE23                            0x84D7
#define GU_TEXTURE24                            0x84D8
#define GU_TEXTURE25                            0x84D9
#define GU_TEXTURE26                            0x84DA
#define GU_TEXTURE27                            0x84DB
#define GU_TEXTURE28                            0x84DC
#define GU_TEXTURE29                            0x84DD
#define GU_TEXTURE30                            0x84DE
#define GU_TEXTURE31                            0x84DF
#define GU_ACTIVE_TEXTURE                       0x84E0
#define GU_CLIENT_ACTIVE_TEXTURE                0x84E1
#define GU_MAX_TEXTURE_UNITS                    0x84E2
// texture_cube_map
#define GU_NORMAL_MAP                           0x8511
#define GU_REFLECTION_MAP                       0x8512
#define GU_TEXTURE_CUBE_MAP                     0x8513
#define GU_TEXTURE_BINDING_CUBE_MAP             0x8514
#define GU_TEXTURE_CUBE_MAP_POSITIVE_X          0x8515
#define GU_TEXTURE_CUBE_MAP_NEGATIVE_X          0x8516
#define GU_TEXTURE_CUBE_MAP_POSITIVE_Y          0x8517
#define GU_TEXTURE_CUBE_MAP_NEGATIVE_Y          0x8518
#define GU_TEXTURE_CUBE_MAP_POSITIVE_Z          0x8519
#define GU_TEXTURE_CUBE_MAP_NEGATIVE_Z          0x851A
#define GU_PROXY_TEXTURE_CUBE_MAP               0x851B
#define GU_MAX_CUBE_MAP_TEXTURE_SIZE            0x851C
// texture_compression
#define GU_COMPRESSED_ALPHA                     0x84E9
#define GU_COMPRESSED_LUMINANCE                 0x84EA
#define GU_COMPRESSED_LUMINANCE_ALPHA           0x84EB
#define GU_COMPRESSED_INTENSITY                 0x84EC
#define GU_COMPRESSED_RGB                       0x84ED
#define GU_COMPRESSED_RGBA                      0x84EE
#define GU_TEXTURE_COMPRESSION_HINT             0x84EF
#define GU_TEXTURE_COMPRESSED_IMAGE_SIZE        0x86A0
#define GU_TEXTURE_COMPRESSED                   0x86A1
#define GU_NUM_COMPRESSED_TEXTURE_FORMATS       0x86A2
#define GU_COMPRESSED_TEXTURE_FORMATS           0x86A3
// multisample
#define GU_MULTISAMPLE                          0x809D
#define GU_SAMPLE_ALPHA_TO_COVERAGE             0x809E
#define GU_SAMPLE_ALPHA_TO_ONE                  0x809F
#define GU_SAMPLE_COVERAGE                      0x80A0
#define GU_SAMPLE_BUFFERS                       0x80A8
#define GU_SAMPLES                              0x80A9
#define GU_SAMPLE_COVERAGE_VALUE                0x80AA
#define GU_SAMPLE_COVERAGE_INVERT               0x80AB
#define GU_MULTISAMPLE_BIT                      0x20000000
// transpose_matrix
#define GU_TRANSPOSE_MODELVIEW_MATRIX           0x84E3
#define GU_TRANSPOSE_PROJECTION_MATRIX          0x84E4
#define GU_TRANSPOSE_TEXTURE_MATRIX             0x84E5
#define GU_TRANSPOSE_COLOR_MATRIX               0x84E6
// texture_env_combine
#define GU_COMBINE                              0x8570
#define GU_COMBINE_RGB                          0x8571
#define GU_COMBINE_ALPHA                        0x8572
#define GU_SOURCE0_RGB                          0x8580
#define GU_SOURCE1_RGB                          0x8581
#define GU_SOURCE2_RGB                          0x8582
#define GU_SOURCE0_ALPHA                        0x8588
#define GU_SOURCE1_ALPHA                        0x8589
#define GU_SOURCE2_ALPHA                        0x858A
#define GU_OPERAND0_RGB                         0x8590
#define GU_OPERAND1_RGB                         0x8591
#define GU_OPERAND2_RGB                         0x8592
#define GU_OPERAND0_ALPHA                       0x8598
#define GU_OPERAND1_ALPHA                       0x8599
#define GU_OPERAND2_ALPHA                       0x859A
#define GU_RGB_SCALE                            0x8573
#define GU_ADD_SIGNED                           0x8574
#define GU_INTERPOLATE                          0x8575
#define GU_SUBTRACT                             0x84E7
#define GU_CONSTANT                             0x8576
#define GU_PRIMARY_COLOR                        0x8577
#define GU_PREVIOUS                             0x8578
// texture_env_dot3
#define GU_DOT3_RGB                             0x86AE
#define GU_DOT3_RGBA                            0x86AF
// texture_border_clamp
#define GU_CLAMP_TO_BORDER                      0x812D

#endif // __WIN32__






































//GLU
// Boolean
//#define GU_FALSE                          0
//#define GU_TRUE                           1

// Version
#define GU_VERSION_1_1                    1
#define GU_VERSION_1_2                    1

// StringName
//#define GU_VERSION                        100800
//#define GU_EXTENSIONS                     100801

// ErrorCode
//#define GU_INVALID_ENUM                   100900
//#define GU_INVALID_VALUE                  100901
//#define GU_OUT_OF_MEMORY                  100902
//#define GU_INVALID_OPERATION              100904

// NurbsDisplay
//      GU_FILL
#define GU_OUTLINE_POLYGON                100240
#define GU_OUTLINE_PATCH                  100241

// NurbsError
#define GU_NURBS_ERROR1                   100251
#define GU_NURBS_ERROR2                   100252
#define GU_NURBS_ERROR3                   100253
#define GU_NURBS_ERROR4                   100254
#define GU_NURBS_ERROR5                   100255
#define GU_NURBS_ERROR6                   100256
#define GU_NURBS_ERROR7                   100257
#define GU_NURBS_ERROR8                   100258
#define GU_NURBS_ERROR9                   100259
#define GU_NURBS_ERROR10                  100260
#define GU_NURBS_ERROR11                  100261
#define GU_NURBS_ERROR12                  100262
#define GU_NURBS_ERROR13                  100263
#define GU_NURBS_ERROR14                  100264
#define GU_NURBS_ERROR15                  100265
#define GU_NURBS_ERROR16                  100266
#define GU_NURBS_ERROR17                  100267
#define GU_NURBS_ERROR18                  100268
#define GU_NURBS_ERROR19                  100269
#define GU_NURBS_ERROR20                  100270
#define GU_NURBS_ERROR21                  100271
#define GU_NURBS_ERROR22                  100272
#define GU_NURBS_ERROR23                  100273
#define GU_NURBS_ERROR24                  100274
#define GU_NURBS_ERROR25                  100275
#define GU_NURBS_ERROR26                  100276
#define GU_NURBS_ERROR27                  100277
#define GU_NURBS_ERROR28                  100278
#define GU_NURBS_ERROR29                  100279
#define GU_NURBS_ERROR30                  100280
#define GU_NURBS_ERROR31                  100281
#define GU_NURBS_ERROR32                  100282
#define GU_NURBS_ERROR33                  100283
#define GU_NURBS_ERROR34                  100284
#define GU_NURBS_ERROR35                  100285
#define GU_NURBS_ERROR36                  100286
#define GU_NURBS_ERROR37                  100287

// NurbsProperty
#define GU_AUTO_LOAD_MATRIX               100200
#define GU_CULLING                        100201
#define GU_SAMPLING_TOLERANCE             100203
#define GU_DISPLAY_MODE                   100204
#define GU_PARAMETRIC_TOLERANCE           100202
#define GU_SAMPLING_METHOD                100205
#define GU_U_STEP                         100206
#define GU_V_STEP                         100207

// NurbsSampling
#define GU_PATH_LENGTH                    100215
#define GU_PARAMETRIC_ERROR               100216
#define GU_DOMAIN_DISTANCE                100217

// NurbsTrim
#define GU_MAP1_TRIM_2                    100210
#define GU_MAP1_TRIM_3                    100211

// QuadricDrawStyle
//#define GU_POINT                          100010
//#define GU_LINE                           100011
//#define GU_FILL                           100012
#define GU_SILHOUETTE                     100013

// QuadricCallback
#define GU_ERROR                          100103

// QuadricNormal
//#define GU_SMOOTH                         100000
//#define GU_FLAT                           100001
//#define GU_NONE                           100002

// QuadricOrientation
#define GU_OUTSIDE                        100020
#define GU_INSIDE                         100021

// TessCallback
#define GU_TESS_BEGIN                     100100
#define GU_BEGIN                          100100
#define GU_TESS_VERTEX                    100101
#define GU_VERTEX                         100101
#define GU_TESS_END                       100102
#define GU_END                            100102
#define GU_TESS_ERROR                     100103
#define GU_TESS_EDGE_FLAG                 100104
//#define GU_EDGE_FLAG                      100104
#define GU_TESS_COMBINE                   100105
#define GU_TESS_BEGIN_DATA                100106
#define GU_TESS_VERTEX_DATA               100107
#define GU_TESS_END_DATA                  100108
#define GU_TESS_ERROR_DATA                100109
#define GU_TESS_EDGE_FLAG_DATA            100110
#define GU_TESS_COMBINE_DATA              100111

// TessContour
//#define GU_CW                             100120
//#define GU_CCW                            100121
#define GU_INTERIOR                       100122
#define GU_EXTERIOR                       100123
#define GU_UNKNOWN                        100124

// TessProperty
#define GU_TESS_WINDING_RULE              100140
#define GU_TESS_BOUNDARY_ONLY             100141
#define GU_TESS_TOLERANCE                 100142

// TessError
#define GU_TESS_ERROR1                    100151
#define GU_TESS_ERROR2                    100152
#define GU_TESS_ERROR3                    100153
#define GU_TESS_ERROR4                    100154
#define GU_TESS_ERROR5                    100155
#define GU_TESS_ERROR6                    100156
#define GU_TESS_ERROR7                    100157
#define GU_TESS_ERROR8                    100158
#define GU_TESS_MISSING_BEGIN_POLYGON     100151
#define GU_TESS_MISSING_BEGIN_CONTOUR     100152
#define GU_TESS_MISSING_END_POLYGON       100153
#define GU_TESS_MISSING_END_CONTOUR       100154
#define GU_TESS_COORD_TOO_LARGE           100155
#define GU_TESS_NEED_COMBINE_CALLBACK     100156

// TessWinding
#define GU_TESS_WINDING_ODD               100130
#define GU_TESS_WINDING_NONZERO           100131
#define GU_TESS_WINDING_POSITIVE          100132
#define GU_TESS_WINDING_NEGATIVE          100133
#define GU_TESS_WINDING_ABS_GEQ_TWO       100134

// Obsolete. For compatibility with previous Sun OpenGL versions
#define GU_INCOMPATIBLE_GL_VERSION        100903

#define GU_TESS_MAX_COORD 1.0e150




//GLEW
#define GU_FRAMEBUFFER                          0x8D40
#define GU_COLOR_ATTACHMENT0_EXT                0x8CE0
#define GU_COLOR_ATTACHMENT1_EXT                0x8CE1
#define GU_COLOR_ATTACHMENT2_EXT                0x8CE2
#define GU_COLOR_ATTACHMENT3_EXT                0x8CE3
#define GU_COLOR_ATTACHMENT4_EXT                0x8CE4
#define GU_COLOR_ATTACHMENT5_EXT                0x8CE5
#define GU_COLOR_ATTACHMENT6_EXT                0x8CE6
#define GU_COLOR_ATTACHMENT7_EXT                0x8CE7
#define GU_COLOR_ATTACHMENT8_EXT                0x8CE8
#define GU_COLOR_ATTACHMENT9_EXT                0x8CE9
#define GU_COLOR_ATTACHMENT10_EXT               0x8CEA
#define GU_COLOR_ATTACHMENT11_EXT               0x8CEB
#define GU_COLOR_ATTACHMENT12_EXT               0x8CEC
#define GU_COLOR_ATTACHMENT13_EXT               0x8CED
#define GU_COLOR_ATTACHMENT14_EXT               0x8CEE
#define GU_COLOR_ATTACHMENT15_EXT               0x8CEF
#define GU_DEPTH_ATTACHMENT_EXT                 0x8D00
#define GU_STENCIL_ATTACHMENT_EXT               0x8D20
*/



/*
namespace edk{
    //
    typedef edk::uint32    GUenum;
    typedef edk::uint8     GUboolean;
    typedef edk::uint32    GUbitfield;
    typedef void            GUvoid;
    typedef edk::int8      GUbyte;         // 1-byte signed
    typedef short           GUshort;        // 2-byte signed
    typedef edk::int32             GUint;          // 4-byte signed
    typedef edk::uint8   GUubyte;        // 1-byte unsigned
    typedef edk::uint16  GUushort;       // 2-byte unsigned
    typedef edk::uint32    GUuint;         // 4-byte unsigned
    typedef edk::int32             GUsizei;        // 4-byte signed
    typedef float           GUfloat;        // single precision float
    typedef float           GUclampf;       // single precision float in [0,1]
    typedef double          GUdouble;       // double precision float
    typedef double          GUclampd;       // double precision float in [0,1]

    class GUnurbs;
    class GUquadric;
    class GUtesselator;

    typedef GUnurbs GLnurbsObj;
    typedef GUquadric GUquadricObj;
    typedef GUtesselator GUtesselatorObj;
    typedef GUtesselator GUtriangulatorObj;

    // Internal convenience typedefs
    typedef void (*_GUfuncptr)();

    //GL
    // Miscellaneous
    void guClearIndex( edk::GUfloat c );
    void guClearColor( edk::GUclampf red, edk::GUclampf green, edk::GUclampf blue, edk::GUclampf alpha );
    void guClear( edk::GUbitfield mask );
    void guIndexMask( edk::GUuint mask );
    void guColorMask( edk::GUboolean red, edk::GUboolean green, edk::GUboolean blue, edk::GUboolean alpha );
    void guAlphaFunc( edk::GUenum func, edk::GUclampf ref );
    void guBlendFunc( edk::GUenum sfactor, edk::GUenum dfactor );
    void guLogicOp( edk::GUenum opcode );
    void guCullFace( edk::GUenum mode );
    void guFrontFace( edk::GUenum mode );
    void guPointSize( edk::GUfloat size );
    void guLineWidth( edk::GUfloat width );
    void guLineStipple( edk::GUint factor, edk::GUushort pattern );
    void guPolygonMode( edk::GUenum face, edk::GUenum mode );
    void guPolygonOffset( edk::GUfloat factor, edk::GUfloat units );
    void guPolygonStipple( const edk::GUubyte *mask );
    void guGetPolygonStipple( edk::GUubyte *mask );
    void guEdgeFlag( edk::GUboolean flag );
    void guEdgeFlagv( const edk::GUboolean *flag );
    void guScissor( edk::GUint x, edk::GUint y, edk::GUsizei width, edk::GUsizei height);
    void guClipPlane( edk::GUenum plane, const edk::GUdouble *equation );
    void guGetClipPlane( edk::GUenum plane, edk::GUdouble* equation );
    void guDrawBuffer( edk::GUenum mode );
    void guReadBuffer( edk::GUenum mode );
    void guEnable( edk::GUenum cap );
    void guDisable( edk::GUenum cap );
    edk::GUboolean guIsEnabled( edk::GUenum cap );
    //using matrix
    edk::GUboolean guUsingMatrix(edk::GUenum mode);
    void guEnableClientState( edk::GUenum cap );
    void guDisableClientState( edk::GUenum cap );
    void guGetBooleanv( edk::GUenum pname, edk::GUboolean *params );
    void guGetDoublev( edk::GUenum pname, edk::GUdouble *params );
    void guGetFloatv( edk::GUenum pname, edk::GUfloat *params );
    void guGetIntegerv( edk::GUenum pname, edk::GUint *params );
    void guPushAttrib( edk::GUbitfield mask );
    void guPopAttrib( void );
    void guPushClientAttrib( edk::GUbitfield mask );
    void guPopClientAttrib( void );
    edk::GUint guRenderMode( edk::GUenum mode );
    edk::GUenum guGetError(         void );
    const edk::GUubyte* guGetString( edk::GUenum name );
    void guFinish(         void );
    void guFlush(         void );
    void guHint( edk::GUenum target, edk::GUenum mode );

    // Depth Buffer
    void guClearDepth( edk::GUclampd depth );
    void guDepthFunc( edk::GUenum func );
    void guDepthMask( edk::GUboolean flag );
    void guDepthRange( edk::GUclampd near_val, edk::GUclampd far_val );

    // Accumulation Buffer
    void guClearAccum( edk::GUfloat red, edk::GUfloat green, edk::GUfloat blue, edk::GUfloat alpha );
    void guAccum( edk::GUenum op, edk::GUfloat value );

    // Transformation
    void guMatrixMode( edk::GUenum mode );
    void guOrtho( edk::GUdouble left, edk::GUdouble right, edk::GUdouble bottom, edk::GUdouble top, edk::GUdouble near_val, edk::GUdouble far_val );
    void guFrustum( edk::GUdouble left, edk::GUdouble right, edk::GUdouble bottom, edk::GUdouble top, edk::GUdouble near_val, edk::GUdouble far_val );
    void guViewport( edk::GUint x, edk::GUint y, edk::GUsizei width, edk::GUsizei height );
    void guPushMatrix( void );
    void guPopMatrix( void );
    void guLoadIdentity( void );
    void guLoadMatrixd( const edk::GUdouble *m );
    void guLoadMatrixf( const edk::GUfloat *m );
    void guMultMatrixd( const edk::GUdouble *m );
    void guMultMatrixf( const edk::GUfloat *m );
    void guRotated( edk::GUdouble angle, edk::GUdouble x, edk::GUdouble y, edk::GUdouble z );
    void guRotatef( edk::GUfloat angle, edk::GUfloat x, edk::GUfloat y, edk::GUfloat z );
    void guScaled( edk::GUdouble x, edk::GUdouble y, edk::GUdouble z );
    void guScalef( edk::GUfloat x, edk::GUfloat y, edk::GUfloat z );
    void guTranslated( edk::GUdouble x, edk::GUdouble y, edk::GUdouble z );
    void guTranslatef( edk::GUfloat x, edk::GUfloat y, edk::GUfloat z );

    // Display Lists
    edk::GUboolean guIsList( edk::GUuint list );
    void guDeleteLists( edk::GUuint list, edk::GUsizei range );
    edk::GUuint guGenLists( edk::GUsizei range );
    void guNewList( edk::GUuint list, edk::GUenum mode );
    void guEndList(         void );
    void guCallList( edk::GUuint list );
    void guCallLists(  edk::GUsizei n, edk::GUenum type, const edk::GUvoid *lists  );
    void guListBase( edk::GUuint base );

    // Drawing Functions
    void guBegin( edk::GUenum mode );
    void guEnd(         void );
    void guVertex2d( edk::GUdouble x, edk::GUdouble y );
    void guVertex2f( edk::GUfloat x, edk::GUfloat y );
    void guVertex2i( edk::GUint x, edk::GUint y );
    void guVertex2s( edk::GUshort x, edk::GUshort y );
    void guVertex3d( edk::GUdouble x, edk::GUdouble y, edk::GUdouble z );
    void guVertex3f( edk::GUfloat x, edk::GUfloat y, edk::GUfloat z );
    void guVertex3i( edk::GUint x, edk::GUint y, edk::GUint z );
    void guVertex3s( edk::GUshort x, edk::GUshort y, edk::GUshort z );
    void guVertex4d( edk::GUdouble x, edk::GUdouble y, edk::GUdouble z, edk::GUdouble w );
    void guVertex4f( edk::GUfloat x, edk::GUfloat y, edk::GUfloat z, edk::GUfloat w );
    void guVertex4i( edk::GUint x, edk::GUint y, edk::GUint z, edk::GUint w );
    void guVertex4s( edk::GUshort x, edk::GUshort y, edk::GUshort z, edk::GUshort w );
    void guVertex2dv( const edk::GUdouble *v );
    void guVertex2fv( const edk::GUfloat *v );
    void guVertex2iv( const edk::GUint *v );
    void guVertex2sv( const edk::GUshort *v );
    void guVertex3dv( const edk::GUdouble *v );
    void guVertex3fv( const edk::GUfloat *v );
    void guVertex3iv( const edk::GUint *v );
    void guVertex3sv( const edk::GUshort *v );
    void guVertex4dv( const edk::GUdouble *v );
    void guVertex4fv( const edk::GUfloat *v );
    void guVertex4iv( const edk::GUint *v );
    void guVertex4sv( const edk::GUshort *v );
    void guNormal3b( edk::GUbyte nx, edk::GUbyte ny, edk::GUbyte nz );
    void guNormal3d( edk::GUdouble nx, edk::GUdouble ny, edk::GUdouble nz );
    void guNormal3f( edk::GUfloat nx, edk::GUfloat ny, edk::GUfloat nz );
    void guNormal3i( edk::GUint nx, edk::GUint ny, edk::GUint nz );
    void guNormal3s( edk::GUshort nx, edk::GUshort ny, edk::GUshort nz );
    void guNormal3bv( const edk::GUbyte *v );
    void guNormal3dv( const edk::GUdouble *v );
    void guNormal3fv( const edk::GUfloat *v );
    void guNormal3iv( const edk::GUint *v );
    void guNormal3sv( const edk::GUshort *v );
    void guIndexd( edk::GUdouble c );
    void guIndexf( edk::GUfloat c );
    void guIndexi( edk::GUint c );
    void guIndexs( edk::GUshort c );
    void guIndexub( edk::GUubyte c );  // 1.1
    void guIndexdv( const edk::GUdouble *c );
    void guIndexfv( const edk::GUfloat *c );
    void guIndexiv( const edk::GUint *c );
    void guIndexsv( const edk::GUshort *c );
    void guIndexubv( const edk::GUubyte *c );  // 1.1
    void guColor3b( edk::GUbyte red, edk::GUbyte green, edk::GUbyte blue );
    void guColor3d( edk::GUdouble red, edk::GUdouble green, edk::GUdouble blue );
    void guColor3f( edk::GUfloat red, edk::GUfloat green, edk::GUfloat blue );
    void guColor3i( edk::GUint red, edk::GUint green, edk::GUint blue );
    void guColor3s( edk::GUshort red, edk::GUshort green, edk::GUshort blue );
    void guColor3ub( edk::GUubyte red, edk::GUubyte green, edk::GUubyte blue );
    void guColor3ui( edk::GUuint red, edk::GUuint green, edk::GUuint blue );
    void guColor3us( edk::GUushort red, edk::GUushort green, edk::GUushort blue );
    void guColor4b( edk::GUbyte red, edk::GUbyte green, edk::GUbyte blue, edk::GUbyte alpha );
    void guColor4d( edk::GUdouble red, edk::GUdouble green, edk::GUdouble blue, edk::GUdouble alpha );
    void guColor4f( edk::GUfloat red, edk::GUfloat green, edk::GUfloat blue, edk::GUfloat alpha );
    void guColor4i( edk::GUint red, edk::GUint green, edk::GUint blue, edk::GUint alpha );
    void guColor4s( edk::GUshort red, edk::GUshort green, edk::GUshort blue, edk::GUshort alpha );
    void guColor4ub( edk::GUubyte red, edk::GUubyte green, edk::GUubyte blue, edk::GUubyte alpha );
    void guColor4ui( edk::GUuint red, edk::GUuint green, edk::GUuint blue, edk::GUuint alpha );
    void guColor4us( edk::GUushort red, edk::GUushort green, edk::GUushort blue, edk::GUushort alpha );
    void guColor3bv( const edk::GUbyte *v );
    void guColor3dv( const edk::GUdouble *v );
    void guColor3fv( const edk::GUfloat *v );
    void guColor3iv( const edk::GUint *v );
    void guColor3sv( const edk::GUshort *v );
    void guColor3ubv( const edk::GUubyte *v );
    void guColor3uiv( const edk::GUuint *v );
    void guColor3usv( const edk::GUushort *v );
    void guColor4bv( const edk::GUbyte *v );
    void guColor4dv( const edk::GUdouble *v );
    void guColor4fv( const edk::GUfloat *v );
    void guColor4iv( const edk::GUint *v );
    void guColor4sv( const edk::GUshort *v );
    void guColor4ubv( const edk::GUubyte *v );
    void guColor4uiv( const edk::GUuint *v );
    void guColor4usv( const edk::GUushort *v );
    void guTexCoord1d( edk::GUdouble s );
    void guTexCoord1f( edk::GUfloat s );
    void guTexCoord1i( edk::GUint s );
    void guTexCoord1s( edk::GUshort s );
    void guTexCoord2d( edk::GUdouble s, edk::GUdouble t );
    void guTexCoord2f( edk::GUfloat s, edk::GUfloat t );
    void guTexCoord2i( edk::GUint s, edk::GUint t );
    void guTexCoord2s( edk::GUshort s, edk::GUshort t );
    void guTexCoord3d( edk::GUdouble s, edk::GUdouble t, edk::GUdouble r );
    void guTexCoord3f( edk::GUfloat s, edk::GUfloat t, edk::GUfloat r );
    void guTexCoord3i( edk::GUint s, edk::GUint t, edk::GUint r );
    void guTexCoord3s( edk::GUshort s, edk::GUshort t, edk::GUshort r );
    void guTexCoord4d( edk::GUdouble s, edk::GUdouble t, edk::GUdouble r, edk::GUdouble q );
    void guTexCoord4f( edk::GUfloat s, edk::GUfloat t, edk::GUfloat r, edk::GUfloat q );
    void guTexCoord4i( edk::GUint s, edk::GUint t, edk::GUint r, edk::GUint q );
    void guTexCoord4s( edk::GUshort s, edk::GUshort t, edk::GUshort r, edk::GUshort q );
    void guTexCoord1dv( const edk::GUdouble *v );
    void guTexCoord1fv( const edk::GUfloat *v );
    void guTexCoord1iv( const edk::GUint *v );
    void guTexCoord1sv( const edk::GUshort *v );
    void guTexCoord2dv( const edk::GUdouble *v );
    void guTexCoord2fv( const edk::GUfloat *v );
    void guTexCoord2iv( const edk::GUint *v );
    void guTexCoord2sv( const edk::GUshort *v );
    void guTexCoord3dv( const edk::GUdouble *v );
    void guTexCoord3fv( const edk::GUfloat *v );
    void guTexCoord3iv( const edk::GUint *v );
    void guTexCoord3sv( const edk::GUshort *v );
    void guTexCoord4dv( const edk::GUdouble *v );
    void guTexCoord4fv( const edk::GUfloat *v );
    void guTexCoord4iv( const edk::GUint *v );
    void guTexCoord4sv( const edk::GUshort *v );
    void guRasterPos2d( edk::GUdouble x, edk::GUdouble y );
    void guRasterPos2f( edk::GUfloat x, edk::GUfloat y );
    void guRasterPos2i( edk::GUint x, edk::GUint y );
    void guRasterPos2s( edk::GUshort x, edk::GUshort y );
    void guRasterPos3d( edk::GUdouble x, edk::GUdouble y, edk::GUdouble z );
    void guRasterPos3f( edk::GUfloat x, edk::GUfloat y, edk::GUfloat z );
    void guRasterPos3i( edk::GUint x, edk::GUint y, edk::GUint z );
    void guRasterPos3s( edk::GUshort x, edk::GUshort y, edk::GUshort z );
    void guRasterPos4d( edk::GUdouble x, edk::GUdouble y, edk::GUdouble z, edk::GUdouble w );
    void guRasterPos4f( edk::GUfloat x, edk::GUfloat y, edk::GUfloat z, edk::GUfloat w );
    void guRasterPos4i( edk::GUint x, edk::GUint y, edk::GUint z, edk::GUint w );
    void guRasterPos4s( edk::GUshort x, edk::GUshort y, edk::GUshort z, edk::GUshort w );
    void guRasterPos2dv( const edk::GUdouble *v );
    void guRasterPos2fv( const edk::GUfloat *v );
    void guRasterPos2iv( const edk::GUint *v );
    void guRasterPos2sv( const edk::GUshort *v );
    void guRasterPos3dv( const edk::GUdouble *v );
    void guRasterPos3fv( const edk::GUfloat *v );
    void guRasterPos3iv( const edk::GUint *v );
    void guRasterPos3sv( const edk::GUshort *v );
    void guRasterPos4dv( const edk::GUdouble *v );
    void guRasterPos4fv( const edk::GUfloat *v );
    void guRasterPos4iv( const edk::GUint *v );
    void guRasterPos4sv( const edk::GUshort *v );
    void guRectd( edk::GUdouble x1, edk::GUdouble y1, edk::GUdouble x2, edk::GUdouble y2 );
    void guRectf( edk::GUfloat x1, edk::GUfloat y1, edk::GUfloat x2, edk::GUfloat y2 );
    void guRecti( edk::GUint x1, edk::GUint y1, edk::GUint x2, edk::GUint y2 );
    void guRects( edk::GUshort x1, edk::GUshort y1, edk::GUshort x2, edk::GUshort y2 );
    void guRectdv( const edk::GUdouble *v1, const edk::GUdouble *v2 );
    void guRectfv( const edk::GUfloat *v1, const edk::GUfloat *v2 );
    void guRectiv( const edk::GUint *v1, const edk::GUint *v2 );
    void guRectsv( const edk::GUshort *v1, const edk::GUshort *v2 );

    // Lighting
    void guShadeModel( edk::GUenum mode );
    void guLightf( edk::GUenum light, edk::GUenum pname, edk::GUfloat param );
    void guLighti( edk::GUenum light, edk::GUenum pname, edk::GUint param );
    void guLightfv( edk::GUenum light, edk::GUenum pname, const edk::GUfloat *params );
    void guLightiv( edk::GUenum light, edk::GUenum pname, const edk::GUint *params );
    void guGetLightfv( edk::GUenum light, edk::GUenum pname, edk::GUfloat *params );
    void guGetLightiv( edk::GUenum light, edk::GUenum pname, edk::GUint *params );
    void guLightModelf( edk::GUenum pname, edk::GUfloat param );
    void guLightModeli( edk::GUenum pname, edk::GUint param );
    void guLightModelfv( edk::GUenum pname, const edk::GUfloat *params );
    void guLightModeliv( edk::GUenum pname, const edk::GUint *params );
    void guMaterialf( edk::GUenum face, edk::GUenum pname, edk::GUfloat param );
    void guMateriali( edk::GUenum face, edk::GUenum pname, edk::GUint param );
    void guMaterialfv( edk::GUenum face, edk::GUenum pname, const edk::GUfloat *params );
    void guMaterialiv( edk::GUenum face, edk::GUenum pname, const edk::GUint *params );
    void guGetMaterialfv( edk::GUenum face, edk::GUenum pname, edk::GUfloat *params );
    void guGetMaterialiv( edk::GUenum face, edk::GUenum pname, edk::GUint *params );
    void guColorMaterial( edk::GUenum face, edk::GUenum mode );

    // Raster functions
    void guPixelZoom( edk::GUfloat xfactor, edk::GUfloat yfactor );
    void guPixelStoref( edk::GUenum pname, edk::GUfloat param );
    void guPixelStorei( edk::GUenum pname, edk::GUint param );
    void guPixelTransferf( edk::GUenum pname, edk::GUfloat param );
    void guPixelTransferi( edk::GUenum pname, edk::GUint param );
    void guPixelMapfv( edk::GUenum map, edk::GUint mapsize, const edk::GUfloat *values );
    void guPixelMapuiv( edk::GUenum map, edk::GUint mapsize, const edk::GUuint *values );
    void guPixelMapusv( edk::GUenum map, edk::GUint mapsize, const edk::GUushort *values );
    void guGetPixelMapfv( edk::GUenum map, edk::GUfloat *values );
    void guGetPixelMapuiv( edk::GUenum map, edk::GUuint *values );
    void guGetPixelMapusv( edk::GUenum map, edk::GUushort *values );
    void guBitmap( edk::GUsizei width, edk::GUsizei height, edk::GUfloat xorig, edk::GUfloat yorig, edk::GUfloat xmove, edk::GUfloat ymove, const edk::GUubyte *bitmap );
    void guReadPixels( edk::GUint x, edk::GUint y, edk::GUsizei width, edk::GUsizei height, edk::GUenum format, edk::GUenum type, edk::GUvoid *pixels );
    void guDrawPixels( edk::GUsizei width, edk::GUsizei height, edk::GUenum format, edk::GUenum type, const edk::GUvoid *pixels );
    void guCopyPixels( edk::GUint x, edk::GUint y, edk::GUsizei width, edk::GUsizei height, edk::GUenum type );

        // Stenciling
    void guStencilFunc( edk::GUenum func, edk::GUint ref, edk::GUuint mask );
    void guStencilMask( edk::GUuint mask );
    void guStencilOp( edk::GUenum fail, edk::GUenum zfail, edk::GUenum zpass );
    void guClearStencil( edk::GUint s );

    // Texture mapping
    void guTexGend( edk::GUenum coord, edk::GUenum pname, edk::GUdouble param );
    void guTexGenf( edk::GUenum coord, edk::GUenum pname, edk::GUfloat param );
    void guTexGeni( edk::GUenum coord, edk::GUenum pname, edk::GUint param );
    void guTexGendv( edk::GUenum coord, edk::GUenum pname, const edk::GUdouble *params );
    void guTexGenfv( edk::GUenum coord, edk::GUenum pname, const edk::GUfloat *params );
    void guTexGeniv( edk::GUenum coord, edk::GUenum pname, const edk::GUint *params );
    void guGetTexGendv( edk::GUenum coord, edk::GUenum pname, edk::GUdouble *params );
    void guGetTexGenfv( edk::GUenum coord, edk::GUenum pname, edk::GUfloat *params );
    void guGetTexGeniv( edk::GUenum coord, edk::GUenum pname, edk::GUint *params );
    void guTexEnvf( edk::GUenum target, edk::GUenum pname, edk::GUfloat param );
    void guTexEnvi( edk::GUenum target, edk::GUenum pname, edk::GUint param );
    void guTexEnvfv( edk::GUenum target, edk::GUenum pname, const edk::GUfloat *params );
    void guTexEnviv( edk::GUenum target, edk::GUenum pname, const edk::GUint *params );
    void guGetTexEnvfv( edk::GUenum target, edk::GUenum pname, edk::GUfloat *params );
    void guGetTexEnviv( edk::GUenum target, edk::GUenum pname, edk::GUint *params );
    void guTexParameterf( edk::GUenum target, edk::GUenum pname, edk::GUfloat param );
    void guTexParameteri( edk::GUenum target, edk::GUenum pname, edk::GUint param );
    void guTexParameterfv( edk::GUenum target, edk::GUenum pname, const edk::GUfloat *params );
    void guTexParameteriv( edk::GUenum target, edk::GUenum pname, const edk::GUint *params );
    void guGetTexParameterfv( edk::GUenum target, edk::GUenum pname, edk::GUfloat *params);
    void guGetTexParameteriv( edk::GUenum target, edk::GUenum pname, edk::GUint *params );
    void guGetTexLevelParameterfv( edk::GUenum target, edk::GUint level, edk::GUenum pname, edk::GUfloat *params );
    void guGetTexLevelParameteriv( edk::GUenum target, edk::GUint level, edk::GUenum pname, edk::GUint *params );
    void guTexImage1D( edk::GUenum target, edk::GUint level, edk::GUint internalFormat, edk::GUsizei width, edk::GUint border, edk::GUenum format, edk::GUenum type, const edk::GUvoid *pixels );
    void guTexImage2D( edk::GUenum target, edk::GUint level, edk::GUint internalFormat, edk::GUsizei width, edk::GUsizei height, edk::GUint border, edk::GUenum format, edk::GUenum type, const edk::GUvoid *pixels );
    void guGetTexImage( edk::GUenum target, edk::GUint level, edk::GUenum format, edk::GUenum type, edk::GUvoid *pixels );

    // Evaluators
    void guMap1d( edk::GUenum target, edk::GUdouble u1, edk::GUdouble u2, edk::GUint stride, edk::GUint order, const edk::GUdouble *points );
    void guMap1f( edk::GUenum target, edk::GUfloat u1, edk::GUfloat u2, edk::GUint stride, edk::GUint order, const edk::GUfloat *points );
    void guMap2d( edk::GUenum target, edk::GUdouble u1, edk::GUdouble u2, edk::GUint ustride, edk::GUint uorder, edk::GUdouble v1, edk::GUdouble v2, edk::GUint vstride, edk::GUint vorder, const edk::GUdouble *points );
    void guMap2f( edk::GUenum target, edk::GUfloat u1, edk::GUfloat u2, edk::GUint ustride, edk::GUint uorder, edk::GUfloat v1, edk::GUfloat v2, edk::GUint vstride, edk::GUint vorder, const edk::GUfloat *points );
    void guGetMapdv( edk::GUenum target, edk::GUenum query, edk::GUdouble *v );
    void guGetMapfv( edk::GUenum target, edk::GUenum query, edk::GUfloat *v );
    void guGetMapiv( edk::GUenum target, edk::GUenum query, edk::GUint *v );
    void guEvalCoord1d( edk::GUdouble u );
    void guEvalCoord1f( edk::GUfloat u );
    void guEvalCoord1dv( const edk::GUdouble *u );
    void guEvalCoord1fv( const edk::GUfloat *u );
    void guEvalCoord2d( edk::GUdouble u, edk::GUdouble v );
    void guEvalCoord2f( edk::GUfloat u, edk::GUfloat v );
    void guEvalCoord2dv( const edk::GUdouble *u );
    void guEvalCoord2fv( const edk::GUfloat *u );
    void guMapGrid1d( edk::GUint un, edk::GUdouble u1, edk::GUdouble u2 );
    void guMapGrid1f( edk::GUint un, edk::GUfloat u1, edk::GUfloat u2 );
    void guMapGrid2d( edk::GUint un, edk::GUdouble u1, edk::GUdouble u2, edk::GUint vn, edk::GUdouble v1, edk::GUdouble v2 );
    void guMapGrid2f( edk::GUint un, edk::GUfloat u1, edk::GUfloat u2, edk::GUint vn, edk::GUfloat v1, edk::GUfloat v2 );
    void guEvalPoint1( edk::GUint i );
    void guEvalPoint2( edk::GUint i, edk::GUint j );
    void guEvalMesh1( edk::GUenum mode, edk::GUint i1, edk::GUint i2 );
    void guEvalMesh2( edk::GUenum mode, edk::GUint i1, edk::GUint i2, edk::GUint j1, edk::GUint j2 );

        // Fog
    void guFogf( edk::GUenum pname, edk::GUfloat param );
    void guFogi( edk::GUenum pname, edk::GUint param );
    void guFogfv( edk::GUenum pname, const edk::GUfloat *params );
    void guFogiv( edk::GUenum pname, const edk::GUint *params );

    // Selection and Feedback
    void guFeedbackBuffer( edk::GUsizei size, edk::GUenum type, edk::GUfloat *buffer );
    void guPassThrough( edk::GUfloat token );
    void guSelectBuffer( edk::GUsizei size, edk::GUuint *buffer );
    void guInitNames( void );
    void guLoadName( edk::GUuint name );
    void guPushName( edk::GUuint name );
    void guPopName( void );


    // 1.1 functions
    // texture objects
    void guGenTextures( edk::GUsizei n, edk::GUuint *textures );
    void guDeleteTextures( edk::GUsizei n, const edk::GUuint *textures);
    void guBindTexture( edk::GUenum target, edk::GUuint texture );
    void guPrioritizeTextures( edk::GUsizei n, const edk::GUuint *textures, const edk::GUclampf *priorities );
    edk::GUboolean guAreTexturesResident( edk::GUsizei n, const edk::GUuint *textures, edk::GUboolean *residences );
    edk::GUboolean guIsTexture( edk::GUuint texture );
    // texture mapping
    void guTexSubImage1D( edk::GUenum target, edk::GUint level, edk::GUint xoffset, edk::GUsizei width, edk::GUenum format, edk::GUenum type, const edk::GUvoid *pixels );
    void guTexSubImage2D( edk::GUenum target, edk::GUint level, edk::GUint xoffset, edk::GUint yoffset, edk::GUsizei width, edk::GUsizei height, edk::GUenum format, edk::GUenum type, const edk::GUvoid *pixels );
    void guCopyTexImage1D( edk::GUenum target, edk::GUint level, edk::GUenum internalformat, edk::GUint x, edk::GUint y, edk::GUsizei width, edk::GUint border );
    void guCopyTexImage2D( edk::GUenum target, edk::GUint level, edk::GUenum internalformat, edk::GUint x, edk::GUint y, edk::GUsizei width, edk::GUsizei height, edk::GUint border );
    void guCopyTexSubImage1D( edk::GUenum target, edk::GUint level, edk::GUint xoffset, edk::GUint x, edk::GUint y, edk::GUsizei width );
    void guCopyTexSubImage2D( edk::GUenum target, edk::GUint level, edk::GUint xoffset, edk::GUint yoffset, edk::GUint x, edk::GUint y, edk::GUsizei width, edk::GUsizei height );
    // vertex arrays
    void guVertexPointer( edk::GUint size, edk::GUenum type, edk::GUsizei stride, const edk::GUvoid *ptr );
    void guNormalPointer( edk::GUenum type, edk::GUsizei stride, const edk::GUvoid *ptr );
    void guColorPointer( edk::GUint size, edk::GUenum type, edk::GUsizei stride, const edk::GUvoid *ptr );
    void guIndexPointer( edk::GUenum type, edk::GUsizei stride, const edk::GUvoid *ptr );
    void guTexCoordPointer( edk::GUint size, edk::GUenum type, edk::GUsizei stride, const edk::GUvoid *ptr );
    void guEdgeFlagPointer( edk::GUsizei stride, const edk::GUvoid *ptr );
    void guGetPointerv( edk::GUenum pname, edk::GUvoid **params );
    void guArrayElement( edk::GUint i );
    void guDrawArrays( edk::GUenum mode, edk::GUint first, edk::GUsizei count );
    void guDrawElements( edk::GUenum mode, edk::GUsizei count, edk::GUenum type, const edk::GUvoid *indices );
    void guInterleavedArrays( edk::GUenum format, edk::GUsizei stride, const edk::GUvoid *pointer );



    // Under Windows, we do not define OpenGL 1.2 & 1.3 functionality, since
    it is treated as extensions (defined in guext.h)
    //#if !defined(__WIN32__)

    // 1.2 functions
    void guDrawRangeElements( edk::GUenum mode, edk::GUuint start, edk::GUuint end, edk::GUsizei count, edk::GUenum type, const edk::GUvoid *indices );
    void guTexImage3D( edk::GUenum target, edk::GUint level, edk::GUenum internalFormat, edk::GUsizei width, edk::GUsizei height, edk::GUsizei depth, edk::GUint border, edk::GUenum format, edk::GUenum type, const edk::GUvoid *pixels );
    void guTexSubImage3D( edk::GUenum target, edk::GUint level, edk::GUint xoffset, edk::GUint yoffset, edk::GUint zoffset, edk::GUsizei width, edk::GUsizei height, edk::GUsizei depth, edk::GUenum format, edk::GUenum type, const edk::GUvoid *pixels);
    void guCopyTexSubImage3D( edk::GUenum target, edk::GUint level, edk::GUint xoffset, edk::GUint yoffset, edk::GUint zoffset, edk::GUint x, edk::GUint y, edk::GUsizei width, edk::GUsizei height );

    // 1.2 imaging extension functions
    void guColorTable( edk::GUenum target, edk::GUenum internalformat, edk::GUsizei width, edk::GUenum format, edk::GUenum type, const edk::GUvoid *table );
    void guColorSubTable( edk::GUenum target, edk::GUsizei start, edk::GUsizei count, edk::GUenum format, edk::GUenum type, const edk::GUvoid *data );
    void guColorTableParameteriv(edk::GUenum target, edk::GUenum pname, const edk::GUint *params);
    void guColorTableParameterfv(edk::GUenum target, edk::GUenum pname, const edk::GUfloat *params);
    void guCopyColorSubTable( edk::GUenum target, edk::GUsizei start, edk::GUint x, edk::GUint y, edk::GUsizei width );
    void guCopyColorTable( edk::GUenum target, edk::GUenum internalformat, edk::GUint x, edk::GUint y, edk::GUsizei width );
    void guGetColorTable( edk::GUenum target, edk::GUenum format, edk::GUenum type, edk::GUvoid *table );
    void guGetColorTableParameterfv( edk::GUenum target, edk::GUenum pname, edk::GUfloat *params );
    void guGetColorTableParameteriv( edk::GUenum target, edk::GUenum pname, edk::GUint *params );
    void guBlendEquation( edk::GUenum mode );
    void guBlendColor( edk::GUclampf red, edk::GUclampf green, edk::GUclampf blue, edk::GUclampf alpha );
    void guHistogram( edk::GUenum target, edk::GUsizei width, edk::GUenum internalformat, edk::GUboolean sink );
    void guResetHistogram( edk::GUenum target );
    void guGetHistogram( edk::GUenum target, edk::GUboolean reset, edk::GUenum format, edk::GUenum type, edk::GUvoid *values );
    void guGetHistogramParameterfv( edk::GUenum target, edk::GUenum pname, edk::GUfloat *params );
    void guGetHistogramParameteriv( edk::GUenum target, edk::GUenum pname, edk::GUint *params );
    void guMinmax( edk::GUenum target, edk::GUenum internalformat, edk::GUboolean sink );
    void guResetMinmax( edk::GUenum target );
    void guGetMinmax( edk::GUenum target, edk::GUboolean reset, edk::GUenum format, edk::GUenum types, edk::GUvoid *values );
    void guGetMinmaxParameterfv( edk::GUenum target, edk::GUenum pname, edk::GUfloat *params );
    void guGetMinmaxParameteriv( edk::GUenum target, edk::GUenum pname, edk::GUint *params );
    void guConvolutionFilter1D( edk::GUenum target, edk::GUenum internalformat, edk::GUsizei width, edk::GUenum format, edk::GUenum type, const edk::GUvoid *image );
    void guConvolutionFilter2D( edk::GUenum target, edk::GUenum internalformat, edk::GUsizei width, edk::GUsizei height, edk::GUenum format, edk::GUenum type, const edk::GUvoid *image );
    void guConvolutionParameterf( edk::GUenum target, edk::GUenum pname, edk::GUfloat params );
    void guConvolutionParameterfv( edk::GUenum target, edk::GUenum pname, const edk::GUfloat *params );
    void guConvolutionParameteri( edk::GUenum target, edk::GUenum pname, edk::GUint params );
    void guConvolutionParameteriv( edk::GUenum target, edk::GUenum pname, const edk::GUint *params );
    void guCopyConvolutionFilter1D( edk::GUenum target, edk::GUenum internalformat, edk::GUint x, edk::GUint y, edk::GUsizei width );
    void guCopyConvolutionFilter2D( edk::GUenum target, edk::GUenum internalformat, edk::GUint x, edk::GUint y, edk::GUsizei width, edk::GUsizei height);
    void guGetConvolutionFilter( edk::GUenum target, edk::GUenum format, edk::GUenum type, edk::GUvoid *image );
    void guGetConvolutionParameterfv( edk::GUenum target, edk::GUenum pname, edk::GUfloat *params );
    void guGetConvolutionParameteriv( edk::GUenum target, edk::GUenum pname, edk::GUint *params );
    void guSeparableFilter2D( edk::GUenum target, edk::GUenum internalformat, edk::GUsizei width, edk::GUsizei height, edk::GUenum format, edk::GUenum type, const edk::GUvoid *row, const edk::GUvoid *column );
    void guGetSeparableFilter( edk::GUenum target, edk::GUenum format, edk::GUenum type, edk::GUvoid *row, edk::GUvoid *column, edk::GUvoid *span );

    // 1.3 functions
    void guActiveTexture( edk::GUenum texture );
    void guClientActiveTexture( edk::GUenum texture );
    void guCompressedTexImage1D( edk::GUenum target, edk::GUint level, edk::GUenum internalformat, edk::GUsizei width, edk::GUint border, edk::GUsizei imageSize, const edk::GUvoid *data );
    void guCompressedTexImage2D( edk::GUenum target, edk::GUint level, edk::GUenum internalformat, edk::GUsizei width, edk::GUsizei height, edk::GUint border, edk::GUsizei imageSize, const edk::GUvoid *data );
    void guCompressedTexImage3D( edk::GUenum target, edk::GUint level, edk::GUenum internalformat, edk::GUsizei width, edk::GUsizei height, edk::GUsizei depth, edk::GUint border, edk::GUsizei imageSize, const edk::GUvoid *data );
    void guCompressedTexSubImage1D( edk::GUenum target, edk::GUint level, edk::GUint xoffset, edk::GUsizei width, edk::GUenum format, edk::GUsizei imageSize, const edk::GUvoid *data );
    void guCompressedTexSubImage2D( edk::GUenum target, edk::GUint level, edk::GUint xoffset, edk::GUint yoffset, edk::GUsizei width, edk::GUsizei height, edk::GUenum format, edk::GUsizei imageSize, const edk::GUvoid *data );
    void guCompressedTexSubImage3D( edk::GUenum target, edk::GUint level, edk::GUint xoffset, edk::GUint yoffset, edk::GUint zoffset, edk::GUsizei width, edk::GUsizei height, edk::GUsizei depth, edk::GUenum format, edk::GUsizei imageSize, const edk::GUvoid *data );
    void guGetCompressedTexImage( edk::GUenum target, edk::GUint lod, edk::GUvoid *img );
    void guMultiTexCoord1d( edk::GUenum target, edk::GUdouble s );
    void guMultiTexCoord1dv( edk::GUenum target, const edk::GUdouble *v );
    void guMultiTexCoord1f( edk::GUenum target, edk::GUfloat s );
    void guMultiTexCoord1fv( edk::GUenum target, const edk::GUfloat *v );
    void guMultiTexCoord1i( edk::GUenum target, edk::GUint s );
    void guMultiTexCoord1iv( edk::GUenum target, const edk::GUint *v );
    void guMultiTexCoord1s( edk::GUenum target, edk::GUshort s );
    void guMultiTexCoord1sv( edk::GUenum target, const edk::GUshort *v );
    void guMultiTexCoord2d( edk::GUenum target, edk::GUdouble s, edk::GUdouble t );
    void guMultiTexCoord2dv( edk::GUenum target, const edk::GUdouble *v );
    void guMultiTexCoord2f( edk::GUenum target, edk::GUfloat s, edk::GUfloat t );
    void guMultiTexCoord2fv( edk::GUenum target, const edk::GUfloat *v );
    void guMultiTexCoord2i( edk::GUenum target, edk::GUint s, edk::GUint t );
    void guMultiTexCoord2iv( edk::GUenum target, const edk::GUint *v );
    void guMultiTexCoord2s( edk::GUenum target, edk::GUshort s, edk::GUshort t );
    void guMultiTexCoord2sv( edk::GUenum target, const edk::GUshort *v );
    void guMultiTexCoord3d( edk::GUenum target, edk::GUdouble s, edk::GUdouble t, edk::GUdouble r );
    void guMultiTexCoord3dv( edk::GUenum target, const edk::GUdouble *v );
    void guMultiTexCoord3f( edk::GUenum target, edk::GUfloat s, edk::GUfloat t, edk::GUfloat r );
    void guMultiTexCoord3fv( edk::GUenum target, const edk::GUfloat *v );
    void guMultiTexCoord3i( edk::GUenum target, edk::GUint s, edk::GUint t, edk::GUint r );
    void guMultiTexCoord3iv( edk::GUenum target, const edk::GUint *v );
    void guMultiTexCoord3s( edk::GUenum target, edk::GUshort s, edk::GUshort t, edk::GUshort r );
    void guMultiTexCoord3sv( edk::GUenum target, const edk::GUshort *v );
    void guMultiTexCoord4d( edk::GUenum target, edk::GUdouble s, edk::GUdouble t, edk::GUdouble r, edk::GUdouble q );
    void guMultiTexCoord4dv( edk::GUenum target, const edk::GUdouble *v );
    void guMultiTexCoord4f( edk::GUenum target, edk::GUfloat s, edk::GUfloat t, edk::GUfloat r, edk::GUfloat q );
    void guMultiTexCoord4fv( edk::GUenum target, const edk::GUfloat *v );
    void guMultiTexCoord4i( edk::GUenum target, edk::GUint s, edk::GUint t, edk::GUint r, edk::GUint q );
    void guMultiTexCoord4iv( edk::GUenum target, const edk::GUint *v );
    void guMultiTexCoord4s( edk::GUenum target, edk::GUshort s, edk::GUshort t, edk::GUshort r, edk::GUshort q );
    void guMultiTexCoord4sv( edk::GUenum target, const edk::GUshort *v );
    void guLoadTransposeMatrixd( const edk::GUdouble m[16] );
    void guLoadTransposeMatrixf( const edk::GUfloat m[16] );
    void guMultTransposeMatrixd( const edk::GUdouble m[16] );
    void guMultTransposeMatrixf( const edk::GUfloat m[16] );
    void guSampleCoverage( edk::GUclampf value, edk::GUboolean invert );
    void guSamplePass( edk::GUenum pass );

    //#endif // __WIN32__





    //filter
    GLenum filterGUtoGLU(edk::GUenum id);



    //GLU
    void guBeginCurve (edk::GUnurbs* nurb);
    void guBeginPolygon (edk::GUtesselator* tess);
    void guBeginSurface (edk::GUnurbs* nurb);
    void guBeginTrim (edk::GUnurbs* nurb);
    edk::GUint guBuild1DMipmaps (edk::GUenum target, edk::GUint internalFormat, edk::GUsizei width, edk::GUenum format, edk::GUenum type, const void *data);
    edk::GUint guBuild2DMipmaps (edk::GUenum target, edk::GUint internalFormat, edk::GUsizei width, edk::GUsizei height, edk::GUenum format, edk::GUenum type, const void *data);
    void guCylinder (edk::GUquadric* quad, edk::GUdouble base, edk::GUdouble top, edk::GUdouble height, edk::GUint slices, edk::GUint stacks);
    void guDeleteNurbsRenderer (edk::GUnurbs* nurb);
    void guDeleteQuadric (edk::GUquadric* quad);
    void guDeleteTess (edk::GUtesselator* tess);
    void guDisk (edk::GUquadric* quad, edk::GUdouble inner, edk::GUdouble outer, edk::GUint slices, edk::GUint loops);
    void guEndCurve (edk::GUnurbs* nurb);
    void guEndPolygon (edk::GUtesselator* tess);
    void guEndSurface (edk::GUnurbs* nurb);
    void guEndTrim (edk::GUnurbs* nurb);
    const edk::GUubyte * guErrorString (edk::GUenum error);
    const wchar_t * guErrorUnicodeStringEXT (edk::GUenum error);
    void guGetNurbsProperty (edk::GUnurbs* nurb, edk::GUenum property, edk::GUfloat* data);

    //const edk::GUubyte * guGetString (edk::GUenum name);

    void guGetTessProperty (edk::GUtesselator* tess, edk::GUenum which, edk::GUdouble* data);
    void guLoadSamplingMatrices (edk::GUnurbs* nurb, const edk::GUfloat *model, const edk::GUfloat *perspective, const edk::GUint *view);
    void guLookAt (edk::GUdouble eyeX, edk::GUdouble eyeY, edk::GUdouble eyeZ, edk::GUdouble centerX, edk::GUdouble centerY, edk::GUdouble centerZ, edk::GUdouble upX, edk::GUdouble upY, edk::GUdouble upZ);
    edk::GUnurbs* guNewNurbsRenderer (void);
    edk::GUquadric* guNewQuadric (void);
    edk::GUtesselator* guNewTess (void);
    void guNextContour (edk::GUtesselator* tess, edk::GUenum type);
    void guNurbsCallback (edk::GUnurbs* nurb, edk::GUenum which, edk::_GUfuncptr CallBackFunc);
    void guNurbsCurve (edk::GUnurbs* nurb, edk::GUint knotCount, edk::GUfloat *knots, edk::GUint stride, edk::GUfloat *control, edk::GUint order, edk::GUenum type);
    void guNurbsProperty (edk::GUnurbs* nurb, edk::GUenum property, edk::GUfloat value);
    void guNurbsSurface (edk::GUnurbs* nurb, edk::GUint sKnotCount, edk::GUfloat* sKnots, edk::GUint tKnotCount, edk::GUfloat* tKnots, edk::GUint sStride, edk::GUint tStride, edk::GUfloat* control, edk::GUint sOrder, edk::GUint tOrder, edk::GUenum type);
    void guOrtho2D (edk::GUdouble left, edk::GUdouble right, edk::GUdouble bottom, edk::GUdouble top);
    void guPartialDisk (edk::GUquadric* quad, edk::GUdouble inner, edk::GUdouble outer, edk::GUint slices, edk::GUint loops, edk::GUdouble start, edk::GUdouble sweep);
    void guPerspective (edk::GUdouble fovy, edk::GUdouble aspect, edk::GUdouble zNear, edk::GUdouble zFar);
    void guPickMatrix (edk::GUdouble x, edk::GUdouble y, edk::GUdouble delX, edk::GUdouble delY, edk::GUint *viewport);
    edk::GUint guProject (edk::GUdouble objX, edk::GUdouble objY, edk::GUdouble objZ, const edk::GUdouble *model, const edk::GUdouble *proj, const edk::GUint *view, edk::GUdouble* winX, edk::GUdouble* winY, edk::GUdouble* winZ);
    void guPwlCurve (edk::GUnurbs* nurb, edk::GUint count, edk::GUfloat* data, edk::GUint stride, edk::GUenum type);
    void guQuadricCallback (edk::GUquadric* quad, edk::GUenum which, edk::_GUfuncptr CallBackFunc);
    void guQuadricDrawStyle (edk::GUquadric* quad, edk::GUenum draw);
    void guQuadricNormals (edk::GUquadric* quad, edk::GUenum normal);
    void guQuadricOrientation (edk::GUquadric* quad, edk::GUenum orientation);
    void guQuadricTexture (edk::GUquadric* quad, edk::GUboolean texture);
    edk::GUint guScaleImage (edk::GUenum format, edk::GUsizei wIn, edk::GUsizei hIn, edk::GUenum typeIn, const void *dataIn, edk::GUsizei wOut, edk::GUsizei hOut, edk::GUenum typeOut, edk::GUvoid* dataOut);
    void guSphere (edk::GUquadric* quad, edk::GUdouble radius, edk::GUint slices, edk::GUint stacks);
    void guTessBeginContour (edk::GUtesselator* tess);
    void guTessBeginPolygon (edk::GUtesselator* tess, edk::GUvoid* data);
    void guTessCallback (edk::GUtesselator* tess, edk::GUenum which, edk::_GUfuncptr CallBackFunc);
    void guTessEndContour (edk::GUtesselator* tess);
    void guTessEndPolygon (edk::GUtesselator* tess);
    void guTessNormal (edk::GUtesselator* tess, edk::GUdouble valueX, edk::GUdouble valueY, edk::GUdouble valueZ);
    void guTessProperty (edk::GUtesselator* tess, edk::GUenum which, edk::GUdouble data);
    void guTessVertex (edk::GUtesselator* tess, edk::GUdouble *location, edk::GUvoid* data);
    //
    edk::GUint guUnProject (edk::GUdouble winX, edk::GUdouble winY, edk::GUdouble winZ, const edk::GUdouble *model, const edk::GUdouble *proj, const edk::GUint *view, edk::GUdouble* objX, edk::GUdouble* objY, edk::GUdouble* objZ);
    edk::GUint guUnProject4 (edk::GUdouble winX, edk::GUdouble winY, edk::GUdouble winZ, edk::GUdouble clipW, const edk::GUdouble *model, const edk::GUdouble *proj, const edk::GUint *view, edk::GUdouble nearVal, edk::GUdouble farVal, edk::GUdouble* objX, edk::GUdouble* objY, edk::GUdouble* objZ, edk::GUdouble* objW);


    //

    glGenFramebuffers(1, &FramebufferName);
    glBindFramebuffer(GL_FRAMEBUFFER, FramebufferName);


    void guGenBuffers(edk::GUsizei n,  edk::GUuint * ids);
    void guBindBuffer (edk::GUenum target, edk::GUuint buffer);
    //glDeleteBuffers (GLsizei n, const GLuint *buffers)
    void guDeleteBuffers(edk::GUsizei n, const edk::GUuint *buffers);
    void guFrameBufferTexture(edk::GUenum target, edk::GUenum attachment, edk::GUuint texture, edk::GUint level);

}//end namespace
*/


//
//DEFINES GU
#define GU_FALSE                                0x0
#define GU_TRUE                                 0x1
#define GU_MODELVIEW                            0x1700
#define GU_PROJECTION                           0x1701
#define GU_TEXTURE                              0x1702
#define GU_RGB                                  0x1907
#define GU_RGBA                                 0x1908
#define GU_LUMINANCE                            0x1909
#define GU_LUMINANCE_ALPHA                      0x190A

// Blending
#define GU_BLEND                                0x0BE2
#define GU_ZERO                                 0x0
#define GU_ONE                                  0x1
#define GU_SRC_COLOR                            0x0300
#define GU_ONE_MINUS_SRC_COLOR                  0x0301
#define GU_SRC_ALPHA                            0x0302
#define GU_ONE_MINUS_SRC_ALPHA                  0x0303
#define GU_DST_ALPHA                            0x0304
#define GU_ONE_MINUS_DST_ALPHA                  0x0305
#define GU_DST_COLOR                            0x0306
#define GU_ONE_MINUS_DST_COLOR                  0x0307
#define GU_SRC_ALPHA_SATURATE                   0x0308
#define GU_CONSTANT_COLOR                       0x8001
#define GU_ONE_MINUS_CONSTANT_COLOR             0x8002
#define GU_CONSTANT_ALPHA                       0x8003
#define GU_ONE_MINUS_CONSTANT_ALPHA             0x8004

// Primitives
#define GU_POINTS                               0x0000
#define GU_LINES                                0x0001
#define GU_LINE_LOOP                            0x0002
#define GU_LINE_STRIP                           0x0003
#define GU_TRIANGLES                            0x0004
#define GU_TRIANGLE_STRIP                       0x0005
#define GU_TRIANGLE_FAN                         0x0006
#define GU_QUADS                                0x0007
#define GU_QUAD_STRIP                           0x0008
#define GU_POLYGON                              0x0009

// Lighting
#define GU_LIGHTING                             0x0B50
#define GU_LIGHT0                               0x4000
#define GU_LIGHT1                               0x4001
#define GU_LIGHT2                               0x4002
#define GU_LIGHT3                               0x4003
#define GU_LIGHT4                               0x4004
#define GU_LIGHT5                               0x4005
#define GU_LIGHT6                               0x4006
#define GU_LIGHT7                               0x4007
#define GU_AMBIENT                              0x1200
#define GU_DIFFUSE                              0x1201
#define GU_SPECULAR                             0x1202
#define GU_POSITION                             0x1203
#define GU_SPOT_DIRECTION                       0x1204
#define GU_SPOT_EXPONENT                        0x1205
#define GU_SPOT_CUTOFF                          0x1206
#define GU_CONSTANT_ATTENUATION                 0x1207
#define GU_LINEAR_ATTENUATION                   0x1208
#define GU_QUADRATIC_ATTENUATION                0x1209
#define GU_SHADE_MODEL                          0x0B54
#define GU_FLAT                                 0x1D00
#define GU_SMOOTH                               0x1D01
#define GU_COLOR_MATERIAL                       0x0B57
#define GU_COLOR_MATERIAL_FACE                  0x0B55
#define GU_COLOR_MATERIAL_PARAMETER             0x0B56
#define GU_FRONT                                0x0404
#define GU_BACK                                 0x0405
#define GU_FRONT_AND_BACK                       0x0408
#define GU_SHININESS                            0x1601
#define GU_EMISSION                             0x1600
#define GU_AMBIENT_AND_DIFFUSE                  0x1602
/*
GL_AMBIENT
GL_DIFFUSE
GL_SPECULAR
GL_POSITION
GL_SPOT_DIRECTION
GL_SPOT_EXPONENT
GL_SPOT_CUTOFF
GL_CONSTANT_ATTENUATION
GL_LINEAR_ATTENUATION
GL_QUADRATIC_ATTENUATION

#define GU_COLOR_INDEXES                        0x1603
#define GU_LIGHT_MODEL_TWO_SIDE                 0x0B52
#define GU_LIGHT_MODEL_LOCAL_VIEWER             0x0B51
#define GU_LIGHT_MODEL_AMBIENT                  0x0B53
#define GU_NORMALIZE                            0x0BA1
*/

// Render
#define GU_RENDER                               0x1C00
#define GU_SELECT                               0x1C02

// Texture mapping
#define GU_TEXTURE_1D                           0x0DE0
#define GU_TEXTURE_2D                           0x0DE1
#define GU_TEXTURE_3D                           0x806F
#define GU_TEXTURE_ENV_COLOR                    0x2201
#define GU_TEXTURE_BORDER_COLOR                 0x1004
#define GU_TEXTURE_WIDTH                        0x1000
#define GU_TEXTURE_HEIGHT                       0x1001
#define GU_TEXTURE_BORDER                       0x1005
#define GU_TEXTURE_RED_SIZE                     0x805C
#define GU_TEXTURE_GREEN_SIZE                   0x805D
#define GU_TEXTURE_BLUE_SIZE                    0x805E
#define GU_TEXTURE_ALPHA_SIZE                   0x805F
#define GU_TEXTURE_LUMINANCE_SIZE               0x8060
#define GU_TEXTURE_INTENSITY_SIZE               0x8061
#define GU_NEAREST_MIPMAP_NEAREST               0x2700
#define GU_NEAREST_MIPMAP_LINEAR                0x2702
#define GU_LINEAR_MIPMAP_NEAREST                0x2701
#define GU_LINEAR_MIPMAP_LINEAR                 0x2703
#define GU_NEAREST                              0x2600
#define GU_LINEAR                               0x2601
#define GU_REPEAT                               0x2901
#define GU_CLAMP                                0x2900
/*
#define GU_TEXTURE0                             0x84C0
#define GU_TEXTURE1                             0x84C1
#define GU_TEXTURE2                             0x84C2
#define GU_TEXTURE3                             0x84C3
#define GU_TEXTURE4                             0x84C4
#define GU_TEXTURE5                             0x84C5
#define GU_TEXTURE6                             0x84C6
#define GU_TEXTURE7                             0x84C7
#define GU_TEXTURE8                             0x84C8
#define GU_TEXTURE9                             0x84C9
#define GU_TEXTURE10                            0x84CA
#define GU_TEXTURE11                            0x84CB
#define GU_TEXTURE12                            0x84CC
#define GU_TEXTURE13                            0x84CD
#define GU_TEXTURE14                            0x84CE
#define GU_TEXTURE15                            0x84CF
#define GU_TEXTURE16                            0x84D0
#define GU_TEXTURE17                            0x84D1
#define GU_TEXTURE18                            0x84D2
#define GU_TEXTURE19                            0x84D3
#define GU_TEXTURE20                            0x84D4
#define GU_TEXTURE21                            0x84D5
#define GU_TEXTURE22                            0x84D6
#define GU_TEXTURE23                            0x84D7
#define GU_TEXTURE24                            0x84D8
#define GU_TEXTURE25                            0x84D9
#define GU_TEXTURE26                            0x84DA
#define GU_TEXTURE27                            0x84DB
#define GU_TEXTURE28                            0x84DC
#define GU_TEXTURE29                            0x84DD
#define GU_TEXTURE30                            0x84DE
#define GU_TEXTURE31                            0x84DF
*/

//library
namespace edk{
class GU{
public:
    //construtor
    GU();

    //destrutor
    ~GU();

    //Color
    static void guColor3f32(edk::color3f32 color);
    static void guColor3f64(edk::color3f64 color);
    static void guColor3f32(edk::float32 r,edk::float32 g,edk::float32 b);
    static void guColor3f64(edk::float64 r,edk::float64 g,edk::float64 b);
    static void guColor4f32(edk::color4f32 color);
    static void guColor4f64(edk::color4f64 color);
    static void guColor4f32(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    static void guColor4f64(edk::float64 r,edk::float64 g,edk::float64 b,edk::float64 a);

    //return the openGL matrix are using
    static bool guUsingMatrix(edk::uint32 mode);

    //set the usingMatrix
    static void guUseMatrix(edk::uint32 mode);

    //load the identity matrix
    static void guLoadIdentity();

    //Push Matrix
    static void guPushMatrix();
    static void guPopMatrix();

    //setViewport
    static void guSetViewport(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height);
    static void guSetViewportRect(edk::rectui32 rect);

    //setThe camera
    static void guUseOrtho(edk::float32 left, edk::float32 right, edk::float32 botton, edk::float32 top, edk::float32 near, edk::float32 far);

    //Set perspective
    //static usePerspective(edk::float32 left, edk::float32 right, edk::float32 botton, edk::float32 top, edk::float32 near, edk::float32 far);

    //create a texture
    static edk::uint32 guAllocTexture2D(edk::uint32 width, edk::uint32 height, edk::uint32 mode, edk::uint32 filter, const edk::classID  data);
    //Draw to texture
    //    GU_RGB
    //    GU_RGBA
    //    GU_LUMINANCE
    //    GU_LUMINANCE_ALPHA
    static bool guDrawToTexture(edk::uint32 ID,edk::uint32 width, edk::uint32 height, edk::uint32 mode, edk::uint32 filter, const edk::classID  data);
    //delete texture
    static void guDeleteTexture(edk::uint32 ID);

    //BLEND
    static void guBlendFunc( edk::uint32 sfactor, edk::uint32 dfactor );

    //ENABLE_DISABLE
    static void guEnable( edk::uint32 cap );
    static void guDisable( edk::uint32 cap );
    //disable all lights
    static void guDisableAllLights();

    //TRANSFORMATIONS
    //rotation
    static void guRotate3f32( edk::float32 angle, edk::vec3f32 vec);
    static void guRotate3f32( edk::float32 angle, edk::float32 x, edk::float32 y, edk::float32 z );
    static void guRotate3f64( edk::float64 angle, edk::vec3f64 vec);
    static void guRotate3f64( edk::float64 angle, edk::float64 x, edk::float64 y, edk::float64 z );
    static void guRotateXf32(edk::float32 angle);
    static void guRotateXf64(edk::float64 angle);
    static void guRotateYf32(edk::float32 angle);
    static void guRotateYf64(edk::float64 angle);
    static void guRotateZf32(edk::float32 angle);
    static void guRotateZf64(edk::float64 angle);
    //scale
    static void guScale3f32( edk::size3f32 size );
    static void guScale3f32( edk::float32 x, edk::float32 y, edk::float32 z );
    static void guScale3f64( edk::size3f64 size );
    static void guScale3f64( edk::float64 x, edk::float64 y, edk::float64 z );
    static void guScale2f32( edk::size2f32 size );
    static void guScale2f32( edk::float32 x, edk::float32 y);
    static void guScale2f64( edk::size2f64 size );
    static void guScale2f64( edk::float64 x, edk::float64 y);
    static void guScaleXf32( edk::float64 x);
    static void guScaleXf64( edk::float64 x);
    static void guScaleYf32( edk::float64 y);
    static void guScaleYf64( edk::float64 y);
    static void guScaleZf32( edk::float64 z);
    static void guScaleZf64( edk::float64 z);
    //translate
    static void guTranslate3f32( edk::vec3f32 vec);
    static void guTranslate3f32( edk::float32 x, edk::float32 y, edk::float32 z );
    static void guTranslate3f64( edk::vec3f64 vec);
    static void guTranslate3f64( edk::float64 x, edk::float64 y, edk::float64 z );
    static void guTranslate2f32( edk::vec2f32 vec);
    static void guTranslate2f32( edk::float32 x, edk::float32 y );
    static void guTranslate2f64( edk::vec2f64 vec);
    static void guTranslate2f64( edk::float64 x, edk::float64 y );
    static void guTranslateXf32( edk::float32 x );
    static void guTranslateXf64( edk::float64 x );
    static void guTranslateYf32( edk::float32 y );
    static void guTranslateYf64( edk::float64 y );
    static void guTranslateZf32( edk::float32 z );
    static void guTranslateZf64( edk::float64 z );

    //SIZES
    static void guPointSize(edk::float32 size);
    static void guPointSize(edk::float64 size);
    static void guPointSize(edk::int8 size);
    static void guPointSize(edk::int16 size);
    static void guPointSize(edk::int32 size);
    static void guPointSize(edk::int64 size);
    static void guPointSize(edk::uint8 size);
    static void guPointSize(edk::uint16 size);
    static void guPointSize(edk::uint32 size);
    static void guPointSize(edk::uint64 size);
    static void guLineWidth(edk::float32 size);
    static void guLineWidth(edk::float64 size);
    static void guLineWidth(edk::int8 size);
    static void guLineWidth(edk::int16 size);
    static void guLineWidth(edk::int32 size);
    static void guLineWidth(edk::int64 size);
    static void guLineWidth(edk::uint8 size);
    static void guLineWidth(edk::uint16 size);
    static void guLineWidth(edk::uint32 size);
    static void guLineWidth(edk::uint64 size);
    //DRAW functions
    static void guBegin(edk::uint32 mode);
    static void guEnd();
    static void guVertex2f32(edk::vec2f32 vec);
    static void guVertex2f64(edk::vec2f64 vec);
    static void guVertex2f32(edk::float32 x,edk::float32 y);
    static void guVertex2f64(edk::float64 x,edk::float64 y);
    static void guVertex3f32(edk::vec3f32 vec);
    static void guVertex3f64(edk::vec3f64 vec);
    static void guVertex3f32(edk::float32 x,edk::float32 y,edk::float32 z);
    static void guVertex3f64(edk::float64 x,edk::float64 y,edk::float64 z);
    static void guVertex4f32(edk::vec4f32 vec);
    static void guVertex4f64(edk::vec4f64 vec);
    static void guVertex4f32(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w);
    static void guVertex4f64(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 w);
    static void guVertexNormal3f32(edk::vec3f32 vec);
    static void guVertexNormal3f64(edk::vec3f64 vec);
    static void guVertexNormal3f32(edk::float32 x,edk::float32 y,edk::float32 z);
    static void guVertexNormal3f64(edk::float64 x,edk::float64 y,edk::float64 z);

    // LIGHTING
    static void guShadeModel( edk::uint32 model );
    static void guLightf32( edk::uint32 light, edk::uint32 pname, edk::float32 param );
    static void guLighti32( edk::uint32 light, edk::uint32 pname, edk::int32 param );
    static void guLightfv32( edk::uint32 light, edk::uint32 pname, const edk::float32 *params );
    static void guLightiv32( edk::uint32 light, edk::uint32 pname, const edk::int32 *params );
    static void guGetLightfv32( edk::uint32 light, edk::uint32 pname, edk::float32 *params );
    static void guGetLightiv32( edk::uint32 light, edk::uint32 pname, edk::int32 *params );

    //MATERIAL
    static void guMaterialf32( edk::uint32 face, edk::uint32 pname, edk::float32 param );
    static void guMateriali32( edk::uint32 face, edk::uint32 pname, edk::int32 param );
    static void guMaterialfv32( edk::uint32 face, edk::uint32 pname, const edk::float32 *params );
    static void guMaterialiv32( edk::uint32 face, edk::uint32 pname, const edk::int32 *params );
    static void guGetMaterialfv32( edk::uint32 face, edk::uint32 pname, edk::float32 *params );
    static void guGetMaterialiv32( edk::uint32 face, edk::uint32 pname, edk::int32 *params );
    static void guColorMaterial( edk::uint32 face, edk::uint32 mode );

    //TEXTURE
    static void guUseTexture(edk::uint32 target, edk::uint32 texture);
    //select te texture
    static void guUseTexture1D(edk::uint32 texture);
    static void guUseTexture2D(edk::uint32 texture);
    static void guUseTexture3D(edk::uint32 texture);
    static void guVertexTex1f32(edk::float32 n);
    static void guVertexTex1f64(edk::float64 n);
    static void guVertexTex2f32(edk::vec2f32 vec);
    static void guVertexTex2f64(edk::vec2f64 vec);
    static void guVertexTex2f32(edk::float32 x,edk::float32 y);
    static void guVertexTex2f64(edk::float64 x,edk::float64 y);
    static void guVertexTex3f32(edk::vec3f32 vec);
    static void guVertexTex3f64(edk::vec3f64 vec);
    static void guVertexTex3f32(edk::float32 x,edk::float32 y,edk::float32 z);
    static void guVertexTex3f64(edk::float64 x,edk::float64 y,edk::float64 z);
    static void guVertexTex4f32(edk::vec4f32 vec);
    static void guVertexTex4f64(edk::vec4f64 vec);
    static void guVertexTex4f32(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w);
    static void guVertexTex4f64(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 w);

    //SELET BUFFER
    //alloc the buffer
    static bool guSetSelectionBuffer(edk::uint32 size,edk::uint32* vector);
    //Set renderMode
    static edk::uint32 guRenderMode( edk::uint32 mode);
    //init the names
    static void guInitNames();
    //push a name
    static void guPushName(edk::uint32 id);
    static void guPopName();
    //get the viewport specification
    //set the pickMatrix
    static void guPickMatrix(edk::float64  x,  edk::float64  y,  edk::float64  delX,  edk::float64  delY);

    //STRING
    //GL_VENDOR
    //Returns the company responsible for this GL implementation
    static edk::char8* guGetVendor();
    //GL_RENDERER
    //Returns the name of the renderer
    static edk::char8* guGetRenderer();
    //GL_VERSION
    //Returns a version or release number of the form
    static edk::char8* guGetVersion();
    //GL_EXTENSIONS
    //Returns a space-separated list of supported extensions to GL.
    static edk::char8* guGetExtensions();
};
}//end namespace





#endif // GU_H
