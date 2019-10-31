#include "ScrollBar2d.h"

/*
ScrollBar2d - ScrollBar for the GUI 2D library
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

static edk::uint32 borderScrollNormalSize = 1282u;
static edk::char8 borderScrollNormalName[23] = "borderScrollNormal.png";
static edk::uchar8 borderScrollNormal[1282] = {
137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,40,0,0 \
,0,40,8,6,0,0,0,140,254,184,109,0,0,0,6,98,75,71,68,0,255 \
,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,14,196,0 \
,0,14,196,1,149,43,14,27,0,0,0,7,116,73,77,69,7,227,10,31,19 \
,25,35,57,201,89,167,0,0,4,143,73,68,65,84,88,195,221,152,203,139,35 \
,85,20,198,127,157,174,64,18,187,82,221,41,59,233,36,42,8,58,15,71,80 \
,231,34,163,110,199,165,138,46,125,162,54,138,32,51,204,31,224,210,189,136,131 \
,160,227,99,227,232,74,55,234,202,199,210,17,228,42,202,56,204,99,35,218,132 \
,84,50,149,144,84,72,2,73,42,46,172,110,110,223,220,76,58,73,41,131,103 \
,121,111,42,247,171,115,207,247,213,119,14,220,228,177,178,232,131,82,202,251,128 \
,147,192,67,192,97,224,118,96,45,218,238,0,127,2,87,129,11,192,247,66,136 \
,95,255,117,128,82,74,27,120,21,216,6,142,206,121,214,37,224,67,224,125,33 \
,68,39,86,128,82,74,11,56,5,188,1,228,150,188,53,31,120,19,56,43,132 \
,24,46,13,80,74,121,4,248,12,184,63,230,242,250,5,120,90,8,113,101,97 \
,128,82,202,39,128,243,74,109,237,197,120,60,166,219,237,18,4,1,253,126,159 \
,225,112,200,112,248,79,66,44,203,194,178,44,82,169,20,182,109,147,201,100,88 \
,89,49,30,21,0,207,10,33,190,156,27,160,148,242,121,224,35,192,82,215,195 \
,48,196,247,125,26,141,6,97,24,30,40,85,137,68,130,92,46,135,235,186,36 \
,18,9,125,123,8,188,36,132,248,228,192,0,163,204,125,174,131,107,181,90,120 \
,158,199,104,52,90,232,78,45,203,34,159,207,227,56,142,9,228,83,66,136,175 \
,102,2,148,82,222,13,72,192,86,175,179,94,175,227,251,126,44,197,183,190,190 \
,206,214,214,150,126,237,29,224,65,33,196,229,169,0,35,182,254,164,18,98,60 \
,30,179,179,179,67,167,211,137,149,33,182,109,83,46,151,117,144,63,3,39,84 \
,118,91,218,115,167,116,182,214,106,181,169,224,18,137,4,217,108,22,219,182,73 \
,165,82,172,174,174,2,48,26,141,232,245,122,116,58,29,218,237,182,177,86,131 \
,32,160,94,175,147,207,231,213,229,227,192,235,192,219,19,25,148,82,222,2,252 \
,1,220,170,214,92,165,82,49,130,115,28,135,124,62,143,101,89,55,204,212,112 \
,56,164,86,171,209,106,181,140,251,229,114,153,108,54,171,235,228,157,66,136,0 \
,64,165,212,107,42,184,48,12,169,213,106,147,172,90,89,161,88,44,82,42,149 \
,102,130,219,37,70,169,84,162,88,44,26,165,166,90,173,234,25,118,129,87,246 \
,110,73,217,216,222,247,26,190,191,167,107,106,20,10,5,214,215,215,23,34,70 \
,177,88,156,88,31,141,70,52,26,13,125,121,123,31,192,232,195,127,84,37,134 \
,225,33,28,199,97,99,99,99,97,98,56,142,99,146,24,124,223,103,60,30,171 \
,75,247,72,41,239,85,51,248,168,186,219,237,118,39,10,59,145,72,176,185,185 \
,185,52,123,243,249,252,132,88,135,97,72,183,219,213,127,122,82,5,120,66,103 \
,152,30,217,108,150,100,50,185,52,64,203,178,176,109,219,200,106,45,30,86,1 \
,30,81,119,250,253,190,81,183,226,212,64,61,12,103,30,86,1,150,116,105,208 \
,35,149,74,197,6,208,244,95,134,51,111,83,1,218,179,0,238,138,112,28,97 \
,89,214,132,228,24,206,180,117,153,249,79,67,99,237,116,39,164,248,178,125,111 \
,104,210,171,184,194,116,67,134,51,247,125,73,42,179,0,246,122,189,216,0,154 \
,72,104,56,115,71,5,120,121,86,17,199,233,102,76,50,150,78,167,245,165,43 \
,42,192,31,103,201,64,187,221,102,48,24,196,114,189,38,128,134,51,127,80,1 \
,126,171,238,100,50,25,163,218,215,235,245,165,1,214,106,53,227,87,202,144,193 \
,239,246,0,10,33,126,3,46,170,142,37,151,155,236,46,91,173,22,205,102,115 \
,97,112,205,102,211,104,187,92,215,213,101,231,146,16,226,119,93,102,62,214,31 \
,50,145,197,243,188,133,64,54,155,77,60,207,51,146,195,144,140,15,76,118,235 \
,61,224,186,154,118,205,237,238,233,87,181,90,165,82,169,24,229,66,143,193,96 \
,64,165,82,161,90,173,26,181,175,80,40,232,229,228,3,231,166,245,36,103,128 \
,183,244,140,153,172,215,238,75,216,182,141,109,219,164,211,233,9,203,31,4,1 \
,65,16,76,109,79,93,215,53,37,225,180,16,226,157,105,61,201,89,224,5,224 \
,1,213,30,13,6,3,35,243,194,48,164,213,106,77,181,243,179,12,131,193,190 \
,73,224,221,89,109,231,93,209,15,179,55,93,219,169,128,124,28,248,66,207,112 \
,187,221,198,243,188,3,213,222,52,147,80,40,20,244,38,105,183,113,127,82,8 \
,241,245,60,163,143,231,34,102,79,140,62,26,141,6,190,239,207,53,250,112,93 \
,151,92,46,55,109,244,241,162,16,226,252,34,195,163,199,128,79,117,59,118,144 \
,225,81,50,153,36,149,74,177,182,182,118,163,225,81,27,120,198,148,185,121,198 \
,111,135,162,241,219,241,152,29,151,140,198,111,215,14,98,183,166,134,16,226,106 \
,212,179,156,137,52,106,217,184,14,156,142,70,28,215,226,30,1,175,69,35,224 \
,151,129,99,115,2,187,24,141,243,206,197,62,2,158,2,246,88,212,174,62,2 \
,28,2,238,80,6,157,1,240,87,100,153,46,0,223,8,33,46,241,127,140,191 \
,1,81,57,244,47,121,34,251,39,0,0,0,0,73,69,78,68,174,66,96,130 \
};

static edk::uint32 borderScrollUpSize = 1167u;
static edk::char8 borderScrollUpName[19] = "borderScrollUp.png";
static edk::uchar8 borderScrollUp[1167] = {
137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,40,0,0 \
,0,40,8,6,0,0,0,140,254,184,109,0,0,0,6,98,75,71,68,0,255 \
,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,14,196,0 \
,0,14,196,1,149,43,14,27,0,0,0,7,116,73,77,69,7,227,10,31,19 \
,26,15,32,60,102,135,0,0,4,28,73,68,65,84,88,195,221,152,75,139,35 \
,85,20,199,127,167,242,174,60,186,82,186,18,21,5,157,30,31,224,3,100,212 \
,237,184,20,193,157,232,8,202,32,8,50,56,234,39,112,225,7,112,47,186,113 \
,220,185,82,87,62,150,142,168,61,162,206,52,163,184,16,21,9,104,135,74,165 \
,82,169,132,78,29,55,213,77,165,234,102,146,78,170,155,193,255,242,156,186,247 \
,254,239,121,220,58,231,192,77,14,89,119,161,170,62,4,156,5,30,7,182,129 \
,59,128,86,162,14,128,63,128,95,129,203,192,87,34,242,227,177,223,70,85,219 \
,170,250,150,170,238,234,209,113,77,85,223,84,213,214,113,16,43,171,234,27,170 \
,186,167,155,227,95,85,189,168,170,229,162,200,157,86,213,31,180,120,92,81,213 \
,237,141,98,80,85,159,1,46,165,98,107,14,147,201,132,40,138,152,78,167,204 \
,102,51,226,56,6,192,178,44,74,165,18,213,106,149,122,189,78,173,86,91,116 \
,196,16,120,65,68,62,57,50,65,85,125,17,120,31,40,103,228,4,65,64,16 \
,4,135,132,150,193,178,44,90,173,22,237,118,219,164,222,7,94,22,145,15,87 \
,38,152,88,238,227,44,185,241,120,140,231,121,43,19,203,162,84,42,177,181,181 \
,69,163,209,48,145,124,86,68,62,93,74,80,85,239,5,118,128,185,235,250,190 \
,207,112,56,44,36,174,155,205,38,142,227,100,197,1,240,152,136,92,95,72,48 \
,201,172,239,128,135,211,242,189,189,61,162,40,42,244,101,104,52,26,184,174,155 \
,21,95,1,206,136,200,254,129,32,155,234,23,178,228,6,131,193,66,114,34,130 \
,109,219,52,26,13,42,149,10,150,101,1,16,199,49,211,233,148,40,138,8,195 \
,16,85,205,173,29,143,199,248,190,79,167,211,73,139,31,5,94,3,222,205,89 \
,80,85,155,192,239,192,173,233,77,250,253,254,66,55,117,58,157,67,82,139,16 \
,199,49,190,239,51,26,141,140,122,215,117,179,49,185,7,220,45,34,67,128,244 \
,238,175,166,201,29,88,207,100,181,110,183,139,227,56,75,201,29,100,176,227,56 \
,116,187,93,68,242,57,233,121,94,214,194,183,0,175,28,174,79,41,206,207,61 \
,80,195,33,179,217,44,183,161,227,56,216,182,125,228,152,179,109,155,110,183,107 \
,180,112,16,4,89,241,249,57,130,201,143,255,190,185,148,202,47,162,217,108,174 \
,69,46,157,24,205,102,51,39,55,156,117,191,170,62,152,182,224,83,217,63,68 \
,246,173,19,145,108,64,175,133,78,167,147,115,117,28,199,76,38,147,236,167,103 \
,211,4,207,164,53,166,172,181,109,123,165,152,91,37,38,77,94,48,156,249,68 \
,154,224,233,180,102,58,157,26,221,83,20,234,245,122,78,102,56,115,59,77,240 \
,182,180,198,148,28,149,74,165,48,130,213,106,53,39,51,156,121,123,154,96,59 \
,27,19,38,215,20,5,203,178,140,113,152,65,59,251,204,156,40,76,127,23,227 \
,101,82,117,217,13,173,181,110,5,179,232,239,178,130,135,230,254,36,127,103,203 \
,162,21,130,120,109,152,246,50,156,249,87,154,224,245,101,65,92,100,53,99,218 \
,203,112,230,47,105,130,223,44,123,6,194,48,44,196,205,113,28,19,134,225,42 \
,207,216,215,105,130,95,164,53,181,90,45,23,19,170,138,239,251,27,19,28,12 \
,6,185,4,177,44,203,100,193,47,15,9,138,200,79,192,213,180,182,213,202,247 \
,73,163,209,200,120,251,85,17,134,161,113,189,225,172,93,17,185,150,125,102,62 \
,152,123,132,218,109,99,178,120,158,183,22,201,48,12,241,60,207,152,28,134,102 \
,234,189,19,45,88,7,131,193,194,75,45,40,88,239,18,145,96,206,130,34,50 \
,2,222,201,6,174,201,213,7,238,238,245,122,120,158,71,20,69,115,9,20,199 \
,49,81,20,225,121,30,189,94,111,33,185,118,187,109,74,142,183,15,200,45,106 \
,154,190,5,30,73,203,251,253,62,227,241,248,36,154,166,157,164,105,154,221,168 \
,237,188,39,249,176,115,51,180,157,150,161,231,248,13,56,151,52,211,115,133,166 \
,235,186,198,196,57,74,227,238,186,174,137,220,62,240,92,150,220,178,209,199,185 \
,36,179,115,83,168,225,112,88,244,232,227,37,17,185,180,206,240,232,105,224,163 \
,108,57,182,202,240,168,92,46,83,169,84,150,13,143,124,224,121,17,249,108,147 \
,178,232,148,170,238,28,195,248,237,251,100,204,82,216,0,243,245,100,248,184,41 \
,254,81,213,11,170,90,162,104,168,106,43,25,227,94,93,131,216,207,201,148,246 \
,72,35,224,77,134,232,15,36,237,234,147,192,41,224,206,212,160,115,8,252,153 \
,148,76,151,129,207,69,100,151,255,35,254,3,112,247,144,62,219,151,99,215,0 \
,0,0,0,73,69,78,68,174,66,96,130
};

static edk::uint32 borderScrollPressedSize = 1376u;
static edk::char8 borderScrollPressedName[24] = "borderScrollPressed.png";
static edk::uchar8 borderScrollPressed[1376] = {
137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,40,0,0 \
,0,40,8,6,0,0,0,140,254,184,109,0,0,0,6,98,75,71,68,0,255 \
,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,14,196,0 \
,0,14,196,1,149,43,14,27,0,0,0,7,116,73,77,69,7,227,10,31,19 \
,24,51,61,101,120,130,0,0,4,237,73,68,65,84,88,195,221,152,223,107,155 \
,101,20,199,63,77,90,90,226,226,69,127,92,212,164,174,82,243,163,78,170,93 \
,234,82,101,80,186,89,198,192,90,189,232,133,63,209,51,20,65,54,246,7,120 \
,233,189,136,67,208,233,227,141,83,198,208,50,84,70,105,237,216,24,182,75,19 \
,139,101,142,52,105,153,213,198,94,116,237,133,25,129,178,52,245,230,93,121,242 \
,190,79,108,146,70,25,158,203,115,206,251,158,47,231,121,206,121,190,231,192,125 \
,46,117,213,126,168,148,122,2,56,10,244,3,33,160,3,216,103,153,239,0,191 \
,3,41,96,26,152,18,145,95,254,117,128,74,41,47,240,54,112,2,232,174,48 \
,214,77,224,115,224,83,17,185,83,83,128,74,169,122,224,36,240,30,208,188,199 \
,83,91,7,222,7,206,136,72,126,207,0,149,82,97,224,107,224,201,26,95,175 \
,57,224,37,17,89,168,26,160,82,234,121,224,156,118,183,138,100,105,105,137,100 \
,50,201,198,198,6,155,155,155,220,189,123,23,128,134,134,6,26,27,27,105,110 \
,110,38,28,14,211,213,213,85,42,68,22,120,69,68,190,171,24,160,82,234,53 \
,64,1,245,186,62,159,207,115,245,234,85,210,233,52,91,91,91,101,165,202,237 \
,118,19,8,4,24,28,28,164,174,206,17,50,15,188,41,34,95,150,13,208,202 \
,220,55,118,112,115,115,115,204,206,206,146,207,231,171,58,211,134,134,6,250,250 \
,250,232,237,237,53,129,124,81,68,190,223,21,160,82,42,0,36,0,175,174,159 \
,156,156,36,149,74,213,228,242,117,116,116,48,60,60,108,87,223,1,158,18,145 \
,100,73,128,86,181,206,218,11,226,252,249,243,172,175,175,215,180,66,218,218,218 \
,24,29,29,181,171,127,6,162,122,117,215,219,28,78,218,193,93,186,116,169,36 \
,56,151,203,133,207,231,35,20,10,225,247,251,241,120,60,0,228,114,57,150,151 \
,151,89,92,92,36,147,201,80,40,20,28,223,174,173,173,49,62,62,206,177,99 \
,199,116,245,65,224,93,224,67,71,6,149,82,15,0,191,1,173,250,157,155,158 \
,158,54,130,243,249,124,12,13,13,237,128,42,37,185,92,142,137,137,9,50,153 \
,140,209,126,248,240,97,122,122,122,236,125,242,17,17,201,2,184,52,195,59,58 \
,184,237,237,109,226,241,184,179,170,234,234,136,70,163,140,140,140,236,10,14,192 \
,227,241,48,50,50,66,52,26,53,85,48,51,51,51,246,162,107,1,222,218,57 \
,37,205,112,66,247,186,124,249,242,78,95,211,37,18,137,16,137,68,42,190,115 \
,145,72,132,254,254,126,135,62,159,207,115,237,218,53,187,250,68,17,64,235,225 \
,47,122,91,211,233,180,241,88,15,29,58,84,117,97,244,246,246,226,243,249,28 \
,250,133,5,199,99,242,152,82,234,113,61,131,207,218,95,8,123,19,118,185,92 \
,28,57,114,100,207,213,59,52,52,132,203,229,42,210,109,109,109,177,180,180,100 \
,119,61,170,3,140,234,150,100,50,105,204,158,215,235,221,51,64,143,199,67,123 \
,123,187,67,111,136,249,180,14,48,172,91,54,54,54,28,63,8,133,66,53,235 \
,129,193,96,208,161,51,196,12,233,0,31,210,45,155,155,155,142,31,248,253,254 \
,154,1,52,253,203,16,211,175,3,44,58,59,83,245,150,211,82,202,21,175,215 \
,235,104,57,134,152,94,123,155,249,79,101,123,123,187,44,63,151,198,203,138,88 \
,135,233,69,168,149,100,179,89,35,211,49,112,197,29,128,127,234,150,198,198,70 \
,199,15,150,151,151,107,6,112,101,101,197,161,51,196,92,209,1,22,213,120,115 \
,179,115,236,88,92,92,172,25,64,19,109,107,109,109,117,244,111,29,224,140,110 \
,9,135,195,142,31,100,50,25,227,209,84,42,185,92,142,213,213,85,135,190,187 \
,219,49,36,254,164,3,156,212,45,93,93,93,184,221,238,34,239,66,161,192,212 \
,212,212,158,1,142,143,143,59,232,151,219,237,166,179,179,211,238,250,227,14,64 \
,17,153,7,110,232,214,64,32,96,204,98,44,22,171,26,92,44,22,51,102,207 \
,240,8,220,20,145,95,237,109,230,11,221,99,112,112,208,88,205,137,68,162,42 \
,144,177,88,140,68,34,97,172,222,129,129,1,187,250,51,19,221,250,4,184,173 \
,243,190,190,190,62,99,255,138,199,227,92,188,120,177,172,214,147,205,102,25,27 \
,27,35,30,143,27,123,159,129,39,174,3,103,75,205,36,167,129,15,236,148,255 \
,214,173,91,37,41,127,123,123,59,193,96,144,253,251,247,59,40,127,42,149,98 \
,117,117,213,72,249,239,221,117,27,229,7,56,37,34,31,149,154,73,206,0,175 \
,3,59,115,225,241,227,199,185,112,225,2,107,107,107,142,0,133,66,129,76,38 \
,83,146,206,239,54,52,25,192,37,128,143,119,27,59,31,181,28,31,188,239,198 \
,78,13,228,48,240,173,61,195,243,243,243,92,191,126,221,72,38,202,29,220,163 \
,209,168,125,72,186,55,184,191,32,34,63,84,178,250,120,213,170,236,122,123,145 \
,92,185,114,133,133,133,133,138,86,31,161,80,136,129,129,129,82,171,143,55,68 \
,228,92,53,203,163,231,128,175,236,116,172,156,229,81,83,83,19,45,45,45,4 \
,131,193,127,90,30,253,5,188,108,202,92,37,235,183,160,181,126,59,88,99,198 \
,149,176,214,111,233,114,232,86,73,17,145,148,53,179,156,182,122,212,94,229,54 \
,112,202,90,113,164,107,189,2,222,103,173,128,5,56,80,33,176,27,214,58,239 \
,108,205,87,192,37,192,30,176,198,213,103,128,32,240,176,182,232,204,2,127,88 \
,148,105,26,152,16,145,155,252,31,229,111,127,237,223,107,177,223,187,245,0,0 \
,0,0,73,69,78,68,174,66,96,130
};

edk::gui2d::ScrollBar2d::ScrollBar2d(){
    //
    this->setBorderSize(0.05f);
    this->objPosition = 0.f;
    this->saveSize = 1.f;
    this->foregroundSize = 0.5f;
    this->saveSize = 0.f;
    //set the percents
    this->setPercent(50.0f,50.0f);

    this->saveStatusInside=this->statusInside=edk::gui2d::gui2dTextureNormal;
}
edk::gui2d::ScrollBar2d::~ScrollBar2d(){
    //clean the meshes
    this->unload();
}

//get the type
edk::gui2d::gui2dTypes edk::gui2d::ScrollBar2d::getType(){
    //
    return edk::gui2d::gui2dTypeScrollBar;
}

void edk::gui2d::ScrollBar2d::updateObjPosition(){
    //update X
    edk::vec2f32 position = this->objPosition-this->position;
    if(position.x + (this->foregroundSize.width*(this->size.width*0.5))>(this->size.width*0.5)){
        //
        this->objPosition.x = this->position.x + (this->size.width*0.5) - (this->foregroundSize.width*(this->size.width*0.5));
    }
    if(position.x - (this->foregroundSize.width*(this->size.width*0.5))<(this->size.width*-0.5)){
        //
        this->objPosition.x = this->position.x - (this->size.width*0.5) + (this->foregroundSize.width*(this->size.width*0.5));
    }
    //update Y
    if(position.y + (this->foregroundSize.height*(this->size.height*0.5))>(this->size.height*0.5)){
        //
        this->objPosition.y = this->position.y + (this->size.height*0.5) - (this->foregroundSize.height*(this->size.height*0.5));
    }
    if(position.y - (this->foregroundSize.height*(this->size.height*0.5))<(this->size.height*-0.5)){
        //
        this->objPosition.y = this->position.y - (this->size.height*0.5) + (this->foregroundSize.height*(this->size.height*0.5));
    }
}
//function to calculate the percent values for X and Y
void edk::gui2d::ScrollBar2d::calculatePercents(){
    //
    edk::float32 div = 0.f;

    div = this->size.width - this->foregroundSize.width;
    if(div==0.f){
        this->percent.x = 1.f;
    }
    else{
        this->percent.x = (this->objPosition.x - this->position.x + this->size.width*0.5 - this->foregroundSize.width*0.5f)
                / (this->size.width - this->foregroundSize.width);
    }
    div = this->size.height - this->foregroundSize.height;
    if(div==0.f){
        this->percent.y = 1.f;
    }
    else{
        this->percent.y = (this->objPosition.y - this->position.y + this->size.height*0.5 - this->foregroundSize.height*0.5f)
                / (this->size.height - this->foregroundSize.height);
    }
    //change the percent to 0.f to 100.f
    this->percent.x *= 100.f;
    this->percent.y *= 100.f;
}
//calculate the position from the percents
void edk::gui2d::ScrollBar2d::calculatePosition(){
    this->objPosition.x = (this->position.x - this->size.width*0.5f + this->foregroundSize.width*0.5f) + (this->size.width - this->foregroundSize.width)
            * (this->percent.x * 0.01f);
    this->objPosition.y = (this->position.x - this->size.height*0.5f + this->foregroundSize.height*0.5f) + (this->size.height - this->foregroundSize.height)
            * (this->percent.y * 0.01f);
}

//Set the percent
void edk::gui2d::ScrollBar2d::setPercent(edk::vec2f32 percent){
    this->setPercent(percent.x,percent.y);
}
void edk::gui2d::ScrollBar2d::setPercent(edk::float32 x,edk::float32 y){
    this->percent.x = x;
    this->percent.y = y;

    //test the new percent
    if(this->percent.x<0.f)this->percent.x=0.f;
    if(this->percent.y<0.f)this->percent.y=0.f;
    if(this->percent.x>100.f)this->percent.x=100.f;
    if(this->percent.y>100.f)this->percent.y=100.f;

    this->calculatePosition();
}
void edk::gui2d::ScrollBar2d::setPercentX(edk::float32 x){
    this->percent.x = x;

    //test the new percent
    if(this->percent.x<0.f)this->percent.x=0.f;
    if(this->percent.y<0.f)this->percent.y=0.f;

    this->calculatePosition();
}
void edk::gui2d::ScrollBar2d::setPercentY(edk::float32 y){
    this->percent.y = y;

    //test the new percent
    if(this->percent.x>100.f)this->percent.x=100.f;
    if(this->percent.y>100.f)this->percent.y=100.f;

    this->calculatePosition();
}
//return the percent
edk::float32 edk::gui2d::ScrollBar2d::getPercentX(){
    return this->percent.x;
}
edk::float32 edk::gui2d::ScrollBar2d::getPercentY(){
    return this->percent.y;
}
edk::vec2f32 edk::gui2d::ScrollBar2d::getPercent(){
    return this->percent;
}

//load the button textures and meshes
bool edk::gui2d::ScrollBar2d::load(){
    if(edk::gui2d::ObjectGui2d::load()){
        this->saveSize = this->size;
        this->objInside.load(edk::size2f32(this->foregroundSize * this->size));
        //update the obj position
        this->calculatePosition();
        this->calculatePercents();

        this->objInside.loadSpriteNormalFromMemory(borderScrollNormalName,borderScrollNormal,borderScrollNormalSize);
        this->objInside.loadSpritePressedFromMemory(borderScrollPressedName,borderScrollPressed,borderScrollPressedSize);
        this->objInside.loadSpriteUpFromMemory(borderScrollUpName,borderScrollUp,borderScrollUpSize);
        this->objInside.loadSpritePressedUpFromMemory(borderScrollPressedName,borderScrollPressed,borderScrollPressedSize);

        return true;
    }
    return false;
}
void edk::gui2d::ScrollBar2d::unload(){
    this->obj.unload();
    edk::gui2d::ObjectGui2d::unload();
}
void edk::gui2d::ScrollBar2d::update(){
    edk::gui2d::ObjectGui2d::update();
}

//set border size
bool edk::gui2d::ScrollBar2d::setBorderSize(edk::float32 size){
    this->saveSize.width = this->size.width+1.f;
    this->objInside.setBorderSize(size);
    return edk::gui2d::ObjectGui2d::setBorderSize(size);
}
//set the size
bool edk::gui2d::ScrollBar2d::setForegroundSize(edk::size2f32 size){
    //
    return this->setForegroundSize(size.width,size.height);
}
bool edk::gui2d::ScrollBar2d::setForegroundSize(edk::float32 width,edk::float32 height){
    bool ret = true;
    //test the size
    if(width<0.f){
        width=0.f;
        ret = false;
    }
    if(width>1.f){
        width=1.f;
        ret = false;
    }
    if(height<0.f){
        height=0.f;
        ret = false;
    }
    if(height>1.f){
        height=1.f;
        ret = false;
    }
    //set the size
    this->foregroundSize.width = width;
    this->foregroundSize.height = height;

    this->saveSize.width = this->saveSize.width+1.f;

    return ret;
}
//get the foregroundSize
edk::float32 edk::gui2d::ScrollBar2d::getForegroundWidth(){
    return this->foregroundSize.width;
}
edk::float32 edk::gui2d::ScrollBar2d::getForegroundHeight(){
    return this->foregroundSize.height;
}
edk::size2f32 edk::gui2d::ScrollBar2d::getForegroundSize(){
    return this->foregroundSize;
}

//set the color
void edk::gui2d::ScrollBar2d::setForegroundColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->objInside.setColor(r,g,b,a);
}
void edk::gui2d::ScrollBar2d::setForegroundColor(edk::float32 r,edk::float32 g,edk::float32 b){
    this->objInside.setColor(r,g,b);
}
void edk::gui2d::ScrollBar2d::setForegroundColor(edk::color4f32 color){
    this->objInside.setColor(color);
}
void edk::gui2d::ScrollBar2d::setForegroundColor(edk::color3f32 color){
    this->objInside.setColor(color);
}

//draw the button
void edk::gui2d::ScrollBar2d::draw(){
    edk::gui2d::ObjectGui2d::draw();

    //test if the size is different
    if(this->saveSize!=this->size){
        this->saveSize=this->size;
        //update the obj position
        this->objInside.updatePolygons(this->foregroundSize * this->size);
        this->calculatePosition();
        this->calculatePercents();
    }

    //put the transformation on a stack
    edk::GU::guPushMatrix();

    //add translate
    edk::GU::guTranslate2f32(this->position + this->objPosition);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    //edk::GU::guScale2f32(this->size);

    edk::GU::guEnable(GU_LIGHTING);

    switch(this->statusInside){
    case gui2dTextureUp:
        this->objInside.drawUp();
        break;
    case gui2dTexturePressed:
        this->objInside.drawPressed();
        break;
    case gui2dTexturePressedUp:
        this->objInside.drawPressedUp();
        break;
    case gui2dTextureSize:
    case gui2dTextureNormal:
        this->objInside.drawNormal();
        break;
    }
    edk::GU::guDisable(GU_LIGHTING);

    edk::GU::guPopMatrix();
}

//move functions
void edk::gui2d::ScrollBar2d::startMove(edk::vec2f32 mousePosition){
    //test if the mousePosition is inside the objInside
    edk::size2f32 sizeTemp = this->foregroundSize * this->size;
    edk::vec2f32 position = mousePosition - this->objPosition;
    if(!(position.x<sizeTemp.width*0.5
         &&
         position.x>sizeTemp.width*-0.5
         &&
         position.y<sizeTemp.height*0.5
         &&
         position.y>sizeTemp.height*-0.5)
            ){
        //move the objPosition to mousePosition
        this->objPosition = mousePosition;

        //update the inside position
        this->updateObjPosition();
        this->calculatePercents();
    }
    this->savePosition = this->objPosition;
}
void edk::gui2d::ScrollBar2d::moveTo(edk::vec2f32 position){
    this->objPosition = this->savePosition + position;

    //update the inside position
    this->updateObjPosition();
    this->calculatePercents();
}
void edk::gui2d::ScrollBar2d::cancelMove(){
    this->objPosition = this->savePosition;
}
//return true if the object can be moved
bool edk::gui2d::ScrollBar2d::canMove(){
    return true;
}
bool edk::gui2d::ScrollBar2d::setStatus(edk::gui2d::gui2dTexture status){
    this->status = edk::gui2d::gui2dTexture::gui2dTextureNormal;
    switch(status){
    case edk::gui2d::gui2dTexture::gui2dTextureUp:
        this->statusInside = edk::gui2d::gui2dTexture::gui2dTextureUp;
        return true;
        break;
    case edk::gui2d::gui2dTexture::gui2dTexturePressedUp:
        this->statusInside = edk::gui2d::gui2dTexture::gui2dTexturePressedUp;
        return true;
        break;
    case edk::gui2d::gui2dTexture::gui2dTexturePressed:
        this->statusInside = edk::gui2d::gui2dTexture::gui2dTexturePressed;
        return true;
        break;
    case edk::gui2d::gui2dTexture::gui2dTextureSize:
    case edk::gui2d::gui2dTexture::gui2dTextureNormal:
        this->statusInside = edk::gui2d::gui2dTexture::gui2dTextureNormal;
        return true;
        break;
    }
    return false;
}
edk::gui2d::gui2dTexture edk::gui2d::ScrollBar2d::getStatus(){
    return this->statusInside;
}

