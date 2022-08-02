#include "FontMap.h"

/*
Library FontMap - Tile Map for Font Set to show text
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



edk::uint32 EDKFontTemplateSize = 4480u;
edk::char8 EDKFontTemplateName[20] = "EDKFontTemplate.png";
edk::uchar8 EDKFontTemplate[4480u] = {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,144,0,0 \
    ,1,0,8,6,0,0,0,92,87,255,79,0,0,0,6,98,75,71,68,0,255 \
    ,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,11,19,0 \
    ,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,227,9,21,23 \
    ,41,0,107,252,44,78,0,0,0,29,105,84,88,116,67,111,109,109,101,110,116 \
    ,0,0,0,0,0,67,114,101,97,116,101,100,32,119,105,116,104,32,71,73,77 \
    ,80,100,46,101,7,0,0,16,228,73,68,65,84,120,218,237,93,237,146,221,32 \
    ,8,237,58,121,219,221,199,217,247,109,127,109,39,77,21,14,31,26,76,14,51 \
    ,157,217,222,235,77,20,17,1,143,240,241,249,249,249,139,36,211,247,247,247,111 \
    ,233,251,175,175,175,143,149,207,169,68,141,226,65,138,208,145,177,18,207,43,7 \
    ,105,67,242,241,251,202,67,237,123,100,62,36,173,136,204,217,97,25,204,232,129 \
    ,63,223,73,157,145,126,159,197,104,233,249,72,155,106,36,241,244,58,158,239,239 \
    ,239,223,18,143,53,129,65,148,64,143,135,45,178,42,144,206,140,86,197,207,111 \
    ,207,127,123,236,6,164,63,72,155,202,26,40,67,232,17,62,107,109,68,13,212 \
    ,147,232,94,231,53,225,208,38,108,244,93,111,245,156,133,204,203,196,30,67,86 \
    ,104,67,137,71,218,86,52,67,99,106,207,25,105,160,81,63,126,62,111,61,21 \
    ,87,65,221,75,130,215,235,103,175,255,86,205,134,172,192,243,187,164,73,31,109 \
    ,25,8,159,145,9,92,185,141,94,183,210,159,5,248,245,245,245,113,88,247,188 \
    ,172,21,230,49,214,87,105,142,209,123,174,218,183,215,79,164,141,244,46,212,182 \
    ,249,121,246,249,89,51,120,211,123,254,249,189,77,90,85,189,207,163,91,88,68 \
    ,221,90,25,36,181,127,130,87,136,204,69,150,6,26,105,253,195,99,213,35,157 \
    ,149,12,108,109,229,246,218,73,130,44,169,121,205,166,235,189,79,243,54,81,45 \
    ,137,240,32,203,182,67,118,139,232,115,123,127,31,200,4,205,118,79,181,73,93 \
    ,165,45,34,11,3,221,86,206,246,67,134,150,70,236,40,175,135,139,236,6,135 \
    ,119,210,123,15,67,218,88,133,67,251,30,177,93,144,54,59,9,225,140,62,121 \
    ,127,243,193,179,48,191,81,111,101,118,181,179,176,12,15,239,160,120,188,151,50 \
    ,4,150,135,169,36,10,16,233,62,162,13,68,10,209,17,245,76,86,186,217,136 \
    ,81,74,216,200,13,2,228,21,4,228,172,73,114,171,165,88,6,226,234,246,126 \
    ,147,113,240,26,133,133,236,8,29,73,177,129,44,1,45,244,160,50,18,13,149 \
    ,66,245,189,104,175,116,208,105,25,207,211,96,33,75,141,232,104,4,83,59,60 \
    ,156,225,134,122,112,44,214,62,175,28,87,21,115,224,204,219,222,191,161,23,22 \
    ,1,120,93,181,64,68,43,88,53,149,119,66,145,62,103,143,11,5,120,173,20 \
    ,30,207,251,26,58,128,149,3,66,4,226,42,60,81,33,90,77,82,127,145,67 \
    ,221,213,115,49,250,252,64,127,184,122,130,118,19,136,232,54,209,27,47,130,189 \
    ,202,238,147,213,9,57,44,82,119,245,128,208,14,205,24,252,249,208,81,242,202 \
    ,144,5,178,178,207,136,179,80,205,139,147,208,19,205,19,71,177,2,181,102,217 \
    ,19,40,214,199,51,30,207,179,44,219,190,5,195,164,189,207,11,136,71,188,77 \
    ,147,6,178,48,77,131,110,68,227,64,94,79,44,34,68,25,130,136,110,59,17 \
    ,24,203,29,154,105,4,191,57,34,157,178,224,127,102,123,96,215,45,45,106,7 \
    ,100,240,164,122,32,49,3,34,188,245,89,24,143,50,238,39,30,166,146,66,68 \
    ,56,7,137,2,68,162,0,193,174,49,233,225,2,116,231,17,8,5,117,61,29 \
    ,94,102,207,246,120,162,33,246,209,179,178,50,93,140,158,245,38,44,144,75,3 \
    ,101,96,98,180,244,46,215,235,179,145,115,177,172,19,123,84,64,158,120,134,183 \
    ,116,11,203,58,22,208,158,49,218,114,178,0,108,145,118,111,16,34,17,15,148 \
    ,57,217,72,234,18,148,217,150,91,170,163,201,68,147,72,172,178,181,180,243,178 \
    ,138,66,120,238,83,203,20,142,200,239,123,127,75,7,133,163,251,229,146,192,246 \
    ,174,13,175,166,106,121,152,162,218,186,236,205,212,209,150,101,49,92,175,217,36 \
    ,238,158,48,75,190,195,168,97,30,77,158,137,110,225,219,95,109,182,216,37,119 \
    ,111,7,90,214,50,203,182,27,221,238,179,248,220,188,140,200,190,253,224,241,238 \
    ,118,223,2,50,140,237,21,91,178,196,231,182,186,211,136,13,132,48,85,186,23 \
    ,182,90,131,88,24,110,1,211,221,105,220,163,139,180,228,81,70,207,136,150,84 \
    ,61,250,156,140,21,143,100,40,219,77,43,70,182,195,242,112,142,183,69,118,119 \
    ,227,13,243,3,61,84,51,172,34,2,202,72,33,34,30,136,68,1,34,81,128 \
    ,72,155,210,209,179,234,53,3,13,193,195,72,198,158,245,54,69,228,214,169,54 \
    ,46,239,237,213,140,113,237,230,237,245,198,245,215,136,30,101,36,151,30,134,92 \
    ,213,181,36,147,178,188,47,11,130,145,213,103,235,184,170,184,244,81,254,180,94 \
    ,35,237,80,79,90,177,72,112,47,43,175,114,6,83,87,70,123,175,125,67,175 \
    ,46,207,18,30,105,174,167,196,129,172,47,139,12,172,167,17,73,113,115,162,215 \
    ,86,186,213,171,237,50,71,239,165,179,113,195,189,193,121,85,191,167,110,168,213 \
    ,222,26,225,136,144,54,168,157,230,105,131,194,107,209,254,104,87,195,151,193,57 \
    ,208,173,227,170,170,53,163,244,220,70,42,165,169,85,246,137,224,138,164,231,68 \
    ,235,164,173,176,121,162,66,164,110,97,209,14,101,12,12,153,192,29,38,100,38 \
    ,89,52,6,58,199,30,30,28,111,158,132,170,182,139,101,139,138,214,117,243,238 \
    ,26,255,4,18,175,198,241,204,106,193,89,152,157,234,23,1,87,45,166,44,80 \
    ,26,106,115,93,223,243,207,97,170,22,72,204,42,98,111,9,184,33,198,118,70 \
    ,112,207,106,244,35,239,138,102,113,181,60,99,86,28,72,107,203,211,120,82,136 \
    ,120,22,70,162,0,145,40,64,36,10,16,137,2,68,34,25,201,157,31,40,114 \
    ,120,55,203,61,247,134,21,208,254,88,239,226,123,194,19,189,80,138,118,245,25 \
    ,13,75,120,33,40,210,124,180,115,35,36,235,185,84,217,101,116,97,78,203,255 \
    ,51,98,28,202,180,17,36,3,189,192,151,121,91,20,77,62,129,94,176,140,188 \
    ,67,155,47,100,49,106,185,154,26,210,72,147,96,171,246,178,50,1,125,159,231 \
    ,132,219,211,159,221,40,90,3,46,197,6,154,93,94,105,197,33,174,37,234,90 \
    ,69,136,238,64,53,134,108,160,44,129,200,206,75,120,215,10,155,193,155,149,194 \
    ,115,174,113,129,212,54,153,110,68,91,1,83,209,34,40,22,38,69,219,160,105 \
    ,87,238,16,166,217,218,221,43,68,174,12,101,119,225,136,179,237,159,209,216,102 \
    ,106,20,203,36,221,85,228,47,77,128,86,10,201,140,173,243,9,100,17,162,59 \
    ,198,222,86,107,24,164,180,163,215,22,240,48,240,41,25,85,239,234,255,113,222 \
    ,255,162,120,150,145,80,72,183,0,52,251,2,9,216,161,117,222,17,100,95,212 \
    ,168,148,222,169,141,219,163,105,102,11,142,38,27,196,3,145,114,183,48,18,137 \
    ,2,68,162,0,145,40,64,164,23,120,113,20,32,18,116,98,63,162,143,207,207 \
    ,79,24,199,163,65,56,178,158,131,60,107,101,90,22,43,110,6,197,241,88,198 \
    ,159,145,216,93,122,143,183,92,121,187,254,96,4,231,64,32,31,89,207,121,58 \
    ,89,130,181,189,118,214,227,16,244,42,179,103,46,90,117,70,71,87,96,102,63 \
    ,50,110,238,102,141,35,99,193,245,132,203,122,10,209,238,158,12,105,32,179,152 \
    ,127,215,196,101,39,141,168,160,181,91,175,83,25,56,20,164,68,65,181,251,237 \
    ,22,27,69,18,112,132,135,89,90,236,110,254,77,59,76,181,64,39,158,100,255 \
    ,32,219,110,118,10,156,59,249,215,86,48,51,122,131,162,162,118,138,30,182,102 \
    ,215,145,189,139,127,45,131,153,222,173,173,146,241,139,198,66,102,100,220,200,178 \
    ,171,74,224,129,118,50,224,60,66,100,77,160,148,229,238,206,246,166,110,221,194 \
    ,16,124,9,114,63,203,82,121,89,171,5,166,245,203,242,28,41,175,98,70,130 \
    ,74,180,207,87,45,140,98,127,34,21,173,103,107,124,55,30,136,233,236,72,191 \
    ,126,37,228,72,156,125,227,130,84,55,180,17,210,64,36,210,116,55,158,68,1 \
    ,34,145,112,1,170,158,58,151,84,143,254,179,129,50,10,164,100,122,103,89,207 \
    ,140,60,199,250,219,72,234,92,203,187,86,230,31,128,183,176,72,144,108,198,32 \
    ,102,20,126,177,142,109,229,228,88,11,164,148,116,227,159,236,150,175,40,31,181 \
    ,155,16,164,11,16,26,19,152,89,22,19,209,20,222,18,147,90,73,204,8,20 \
    ,99,198,22,228,49,43,144,49,141,110,226,90,32,200,205,186,178,80,24,6,154 \
    ,222,14,205,134,38,49,21,121,206,168,191,215,231,32,239,149,198,159,173,125,178 \
    ,176,89,146,208,254,140,201,3,65,110,214,142,120,138,170,89,75,101,90,141,80 \
    ,169,79,217,176,216,59,50,150,100,224,134,102,245,251,240,14,166,138,187,207,99 \
    ,148,66,113,32,82,61,131,191,210,98,45,43,64,111,169,33,246,68,33,106,158 \
    ,129,104,134,228,117,50,71,121,159,209,54,90,18,110,9,15,164,25,209,8,192 \
    ,223,50,121,209,220,61,51,222,149,97,67,141,248,204,211,248,9,134,171,199,150 \
    ,220,213,150,107,20,24,158,255,69,136,26,232,87,110,169,202,138,239,163,0,145 \
    ,184,133,145,158,73,7,89,192,237,251,188,149,90,141,250,242,91,216,219,65,251 \
    ,104,41,118,207,193,46,122,152,186,173,0,189,253,234,80,86,5,162,153,124,164 \
    ,13,68,114,123,143,127,109,32,15,46,164,183,95,102,224,75,122,223,175,76,67 \
    ,183,162,77,143,170,107,217,115,238,128,115,95,219,117,128,40,46,68,59,130,24 \
    ,49,14,77,149,135,150,171,92,65,153,25,202,70,227,187,78,214,140,44,30,222 \
    ,160,169,52,159,109,54,211,181,201,168,32,32,146,102,212,22,135,87,112,180,187 \
    ,252,51,18,56,120,248,172,37,150,104,43,86,239,46,25,202,232,28,108,100,68 \
    ,191,53,67,235,211,60,203,118,7,3,165,218,232,232,239,178,109,23,45,193,212 \
    ,172,138,213,187,104,225,17,116,248,111,28,200,155,252,91,242,158,52,64,188,181 \
    ,173,247,54,133,39,160,102,245,230,36,161,138,120,97,51,3,137,25,244,159,0 \
    ,161,47,98,126,32,242,232,86,27,136,194,243,12,234,214,202,176,214,38,165,22 \
    ,138,223,17,219,90,128,72,36,110,97,55,106,26,175,23,58,219,3,67,222,21 \
    ,109,211,42,76,200,78,174,108,84,136,170,129,233,163,253,105,163,201,92,49,161 \
    ,43,111,187,34,99,66,174,246,68,251,154,149,241,126,22,79,172,115,223,122,12 \
    ,186,35,66,92,229,60,12,17,30,47,127,170,214,74,139,212,71,57,70,234,107 \
    ,69,30,157,170,118,205,72,96,36,15,171,167,161,102,46,136,44,104,72,180,143 \
    ,135,229,225,59,226,89,16,108,81,182,93,34,69,164,175,183,109,145,144,73,166 \
    ,176,74,39,243,158,212,124,7,82,78,32,91,88,172,185,128,238,52,18,189,43 \
    ,89,226,29,138,247,145,4,195,58,14,52,182,135,148,233,250,71,3,121,139,173 \
    ,70,130,137,79,185,214,235,117,243,71,119,255,17,225,65,238,239,35,191,243,228 \
    ,99,234,66,90,61,26,104,135,173,171,130,177,141,240,110,36,68,63,223,141,62 \
    ,247,206,131,103,219,146,190,107,61,232,232,21,182,58,203,109,182,252,126,102,104 \
    ,33,243,93,218,150,100,173,184,156,145,49,196,42,240,102,55,94,194,46,87,94 \
    ,237,189,232,168,23,55,20,197,96,143,4,48,42,248,104,109,214,172,248,157,245 \
    ,247,199,200,184,227,246,148,171,125,70,60,246,242,57,115,110,34,66,103,58,76 \
    ,213,128,87,200,190,138,60,227,105,57,116,42,216,100,179,120,120,172,94,137,136 \
    ,27,139,186,196,164,251,233,150,228,10,20,136,231,16,225,28,164,117,26,40,59 \
    ,105,55,105,127,91,106,106,217,111,169,13,130,173,201,192,223,100,135,13,86,129 \
    ,193,184,133,61,116,5,70,189,194,106,66,24,237,15,51,148,45,222,186,45,135 \
    ,169,171,198,22,233,15,5,136,94,104,168,63,31,191,127,255,222,54,103,77,197 \
    ,109,174,199,59,79,137,40,13,227,163,97,142,70,159,33,55,105,45,207,57,60 \
    ,133,222,72,99,134,95,79,216,71,185,145,174,54,8,122,26,63,178,201,34,72 \
    ,200,145,109,135,60,231,120,194,37,193,138,71,29,87,129,186,218,27,200,36,245 \
    ,132,200,83,19,4,1,165,89,53,212,95,1,122,99,138,149,59,109,139,40,34 \
    ,209,130,7,66,231,116,212,23,100,65,182,167,76,84,5,237,51,210,42,189,255 \
    ,35,213,142,60,54,208,106,237,205,56,208,77,49,151,158,237,129,174,254,44,60 \
    ,80,70,190,162,227,13,147,134,24,142,43,60,209,39,226,129,30,47,64,214,91 \
    ,6,111,138,1,101,244,133,91,24,137,2,68,162,0,145,54,165,87,156,133,189 \
    ,21,83,189,2,191,117,204,154,16,173,77,165,219,31,111,77,79,183,173,6,146 \
    ,66,251,81,33,206,200,54,59,234,211,27,115,67,106,7,174,221,52,191,81,192 \
    ,148,182,154,179,82,161,160,64,47,84,27,206,200,202,177,75,21,30,111,159,83 \
    ,183,48,203,106,206,96,114,214,101,200,12,144,151,53,73,66,21,225,137,246,121 \
    ,121,177,21,244,250,52,138,65,206,48,20,51,83,237,33,71,10,150,54,210,216 \
    ,51,5,201,251,252,229,54,16,178,69,246,108,164,158,102,203,48,204,123,24,24 \
    ,175,93,134,190,123,4,54,27,141,31,25,123,150,54,127,44,164,85,58,225,222 \
    ,205,77,239,37,216,146,170,62,34,48,11,109,65,205,178,201,142,85,204,202,238 \
    ,120,150,6,26,33,8,103,11,227,104,187,236,245,199,171,13,173,9,195,60,239 \
    ,104,179,152,50,251,230,65,47,179,168,55,219,232,140,28,137,89,185,164,87,1 \
    ,254,188,249,160,142,217,43,11,73,94,20,205,23,56,67,248,103,217,63,200,54 \
    ,150,229,28,88,251,236,78,243,91,193,22,232,165,24,206,8,56,174,50,162,45 \
    ,80,211,153,201,68,51,180,142,229,89,233,129,196,202,70,107,70,1,60,210,166 \
    ,94,216,74,15,143,116,147,17,77,162,0,145,72,38,98,193,57,82,158,13,148 \
    ,129,209,65,158,97,129,69,236,24,101,70,239,115,101,157,221,69,219,68,250,210 \
    ,70,47,204,168,139,174,157,217,100,213,111,208,158,49,250,55,51,44,33,9,87 \
    ,70,34,247,108,207,212,219,151,244,72,52,18,6,64,58,157,37,60,163,119,87 \
    ,137,197,172,20,224,43,95,61,135,181,67,1,202,10,231,91,126,175,97,132,232 \
    ,94,207,17,30,105,174,66,25,202,34,48,208,145,90,156,5,178,122,106,50,114 \
    ,79,64,215,99,19,73,91,152,101,91,59,170,172,134,25,180,210,206,208,242,0 \
    ,245,250,163,101,239,24,29,171,32,80,22,20,238,34,57,52,200,98,116,149,58 \
    ,168,176,247,123,52,208,121,82,172,37,26,42,106,162,108,111,204,83,181,199,149 \
    ,39,250,169,247,172,170,140,39,171,158,72,116,107,131,50,148,209,252,220,207,6 \
    ,66,92,112,139,141,19,113,229,155,119,165,210,67,154,167,5,207,161,6,36,20 \
    ,130,134,75,52,97,154,142,7,170,100,3,85,180,91,86,111,181,82,38,127,164 \
    ,42,53,242,156,41,54,208,155,237,150,74,2,107,137,223,160,229,181,172,66,196 \
    ,211,248,23,217,85,63,127,103,134,54,104,68,191,192,131,244,148,100,71,137,112 \
    ,14,218,91,33,106,94,213,134,92,205,213,126,155,113,117,119,230,233,122,68,120 \
    ,34,252,201,120,254,170,254,12,15,83,35,204,236,165,249,215,226,19,90,170,217 \
    ,209,103,209,56,134,215,243,153,201,31,100,236,85,250,179,253,22,150,149,168,234 \
    ,141,185,127,50,232,63,1,66,2,74,187,181,65,115,69,123,34,180,119,180,177 \
    ,8,253,236,54,173,215,104,69,169,202,85,109,174,26,10,57,144,148,78,182,71 \
    ,209,225,149,109,70,109,239,104,99,130,180,238,214,38,82,68,36,35,65,249,202 \
    ,54,183,122,97,90,136,123,215,54,146,218,207,176,151,102,193,40,118,10,29,188 \
    ,42,18,157,225,165,101,129,229,170,128,238,162,116,84,102,78,70,155,171,13,100 \
    ,169,161,37,33,6,181,45,103,85,155,82,26,8,201,175,179,91,155,94,14,33 \
    ,205,126,66,43,248,84,241,206,184,133,221,188,149,245,234,111,161,64,246,183,111 \
    ,101,199,155,5,7,93,233,136,118,90,217,102,212,86,139,223,204,104,195,195,212 \
    ,13,61,31,106,160,13,52,19,133,7,35,106,32,18,141,104,210,38,2,132,224 \
    ,120,118,197,21,101,109,133,21,48,58,25,125,75,23,32,244,38,232,142,184,162 \
    ,44,170,134,25,90,225,20,124,124,126,126,210,136,116,26,219,79,224,81,84,184 \
    ,224,52,191,214,207,36,70,87,107,147,161,129,17,254,220,221,70,106,231,229,79 \
    ,179,170,98,52,41,212,249,8,97,116,138,94,161,77,116,149,238,112,224,137,110 \
    ,191,30,254,180,12,85,206,184,81,77,129,144,22,84,196,0,63,255,191,141,94 \
    ,242,54,33,178,20,194,219,73,171,92,39,28,5,202,141,238,207,95,159,211,188 \
    ,157,122,26,33,53,50,42,85,154,246,204,151,215,246,147,60,193,230,121,201,19 \
    ,133,232,156,65,21,133,115,188,129,36,236,246,215,215,215,71,203,144,236,167,48 \
    ,10,25,219,211,133,71,243,240,174,91,220,177,58,240,180,243,246,246,86,30,73 \
    ,151,18,224,64,226,219,227,64,189,103,237,48,174,140,62,75,196,211,248,151,83 \
    ,90,36,154,68,242,16,225,28,36,10,16,137,2,68,218,93,128,44,56,25,164 \
    ,237,202,18,3,171,18,76,85,226,79,149,254,152,19,76,89,238,115,75,0,39 \
    ,9,73,168,253,127,212,151,10,9,166,162,252,65,199,94,165,63,221,252,64,90 \
    ,76,1,77,6,160,197,142,86,85,72,92,229,246,102,240,103,183,254,208,141,31 \
    ,168,112,70,225,141,2,84,33,219,213,204,54,146,198,179,32,254,164,247,221,25 \
    ,101,142,32,8,34,109,186,26,168,90,254,155,104,155,81,134,14,180,250,80,53 \
    ,184,106,37,30,31,22,43,124,199,54,61,237,147,181,205,85,24,219,221,116,160 \
    ,222,204,142,109,122,159,71,86,35,211,218,189,44,144,56,74,160,41,221,101,35 \
    ,148,133,2,228,218,26,172,53,208,208,224,220,170,54,165,188,48,164,158,248,238 \
    ,109,188,70,115,85,47,236,174,54,140,3,49,14,148,163,129,72,36,218,64,36 \
    ,10,16,105,47,58,44,6,41,137,212,213,64,214,208,126,150,203,89,9,87,148 \
    ,101,136,87,28,59,218,175,51,204,6,125,247,63,70,180,230,226,162,90,42,251 \
    ,236,197,219,159,204,133,97,245,230,102,142,221,50,46,203,152,67,112,142,108,28 \
    ,207,110,184,162,76,97,169,130,25,242,148,233,116,9,144,245,4,248,233,177,160 \
    ,89,171,245,73,227,255,207,136,182,60,28,81,175,103,122,82,134,50,148,249,21 \
    ,33,32,145,252,64,163,247,53,148,81,231,31,239,146,125,204,154,161,108,116,30 \
    ,38,85,53,124,67,178,45,233,176,153,153,234,129,69,243,134,113,35,72,196,222 \
    ,231,199,219,152,22,17,148,167,217,61,150,92,72,80,209,93,106,34,249,10,77 \
    ,175,221,27,22,156,154,31,232,154,222,141,81,232,184,182,218,77,11,89,202,141 \
    ,15,65,245,104,224,110,167,219,11,25,94,152,167,8,93,53,44,148,54,126,111 \
    ,44,141,112,142,23,58,11,153,90,148,54,16,133,39,68,116,227,95,20,154,152 \
    ,86,108,133,68,242,210,31,117,49,251,72,141,15,187,166,0,0,0,0,73,69 \
    ,78,68,174,66,96,130
};

edk::fonts::FontMap::FontLine::FontLine(edk::uint32 size){
    this->size = size;
    if(this->size){
        this->line = new edk::uint32[this->size];
        if(line){
            //clean the line
            for(edk::uint32 i=0u;i<this->size;i++){
                this->line[i]=0u;
            }
        }
        else{
            this->size=0u;
        }
    }
}
edk::fonts::FontMap::FontLine::~FontLine(){
    //delete the line
    if(this->line) delete[] this->line;
}
//get the size
edk::uint32 edk::fonts::FontMap::FontLine::getSize(){
    return size;
}
//return true if have the line
bool edk::fonts::FontMap::FontLine::haveLine(){
    if(this->line) return true;
    return false;
}
//set the value
bool edk::fonts::FontMap::FontLine::setValue(edk::uint32 position,edk::uint32 value){
    //test if have the position
    if(this->havePosition(position)){
        //set the value
        this->line[position] = value;
        return true;
    }
    return false;
}
//get the value
edk::uint32 edk::fonts::FontMap::FontLine::getValue(edk::uint32 position){
    if(this->havePosition(position)){
        //return the value
        return this->line[position];
    }
    return 0u;
}
//test if have position
bool edk::fonts::FontMap::FontLine::havePosition(edk::uint32 position){
    if(this->line && position<this->size){
        return true;
    }
    return false;
}


edk::fonts::FontMap::FontMap(){
    this->set = NULL;
    this->map.cleanTiles();
    this->originID = this->lastID = 0u;
    this->origin = this->last = edk::vec2ui32(0u,0u);
    this->speedOrigin = this->fasterOrigin = 1.f;
    this->speedLast = 1.f;
    this->fasterLast = 4.f;
    this->animOrigin.setSpeed(this->speedOrigin);
    this->animLast.setSpeed(this->speedLast);
    this->forceSpeedOrigin = forceSpeedLast = false;
    this->forceSpeedOriginValue = this->forceSpeedLastValue = 1.f;
    this->enterOrigin = this->enterLast = false;
    this->write=0u;

    //set the animation callback
    this->animOrigin.setAnimationCallback(this);
    this->animLast.setAnimationCallback(this);
    this->maxSizeLine=0u;

    //load the templateFont
    this->loadFontImageFromMemory(EDKFontTemplateName,EDKFontTemplate,EDKFontTemplateSize);
}
edk::fonts::FontMap::~FontMap(){
    this->removeFontImage();
    this->cleanLines();
}

//gete the tileID
edk::uint32 edk::fonts::FontMap::getTileID(edk::char8* str,edk::uint8* jump){
    //
    if(str && jump){
        *jump=1u;
        if((edk::uint8)*str==195u){
            *jump+=1u;
            str++;
            switch((edk::uint8)*str){
            case 128u:
                //printf("\nCrase A");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 129u:
                //printf("\nAcento A");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 130u:
                //printf("\nChapeu A");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 131u:
                //printf("\nTio A");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 132u:
                //printf("\nTrema A");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 135u:
                //printf("\nCedilha Maiusculo");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 136u:
                //printf("\nCrase E");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 137u:
                //printf("\nAcento E");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 138u:
                //printf("\nChapeu E");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 139u:
                //printf("\nTrema E");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 140u:
                //printf("\nCrase I");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 141u:
                //printf("\nAcento I");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 142u:
                //printf("\nChapeu I");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 143u:
                //printf("\nTrema I");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 145u:
                //printf("\nTio N");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 146u:
                //printf("\nCrase O");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 147u:
                //printf("\nAcento O");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 148u:
                //printf("\nChapeu O");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 149u:
                //printf("\nTio O");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 150u:
                //printf("\nTrema O");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 153u:
                //printf("\nCrase U");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 154u:
                //printf("\nAcento U");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 155u:
                //printf("\nChapeu U");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 156u:
                //printf("\nTrema U");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 157u:
                //printf("\nAcento Y");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 160u:
                //printf("\nCrase a");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 161u:
                //printf("\nAcento a");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 162u:
                //printf("\nChapeu a");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 163u:
                //printf("\nTio a");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 164u:
                //printf("\nTrema a");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 167u:
                //printf("\nCedilha Minusculo");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 168u:
                //printf("\nCrase e");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 169u:
                //printf("\nAcento e");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 170u:
                //printf("\nChapeu e");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 171u:
                //printf("\nTrema e");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 172u:
                //printf("\nCrase i");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 173u:
                //printf("\nAcento i");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 174u:
                //printf("\nChapeu i");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 175u:
                //printf("\ntrema i");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 177u:
                //printf("\nTio n");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 178u:
                //printf("\nCrase o");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 179u:
                //printf("\nAcento o");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 180u:
                //printf("\nChapeu o");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 181u:
                //printf("\nTio o");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 182u:
                //printf("\nTrema o");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 185u:
                //printf("\nCrase u");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 186u:
                //printf("\nAcento u");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 187u:
                //printf("\nChapeu u");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 188u:
                //printf("\nTrema u");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 189u:
                //printf("\nAcento y");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            default:
                *jump-=1u;
                str--;
            }
        }
        else if((edk::uint8)*str==225u){
            *jump+=1u;
            str++;
            if((edk::uint8)*str==186u){
                *jump+=1u;
                str++;
                if((edk::uint8)*str==189u){
                    //printf("\nTio e");
                    return 32u;
                }
                *jump-=1u;
                str--;
            }
            *jump-=1u;
            str--;
        }
        else if((edk::uint8)*str==226u){
            *jump+=1u;
            str++;
            if((edk::uint8)*str==128u){
                *jump+=1u;
                str++;
                if((edk::uint8)*str==148u){
                    //printf("\n");
                    return 45u;
                }
                else if((edk::uint8)*str==152u){
                    //printf("\nAbrir aspas simples");
                    return '\'';
                }
                else if((edk::uint8)*str==153u){
                    //printf("\nFechar aspas simples");
                    return '\'';
                }
                else if((edk::uint8)*str==156u){
                    //printf("\nAbrir aspas");
                    return '\"';
                }
                else if((edk::uint8)*str==157u){
                    //printf("\nFechar aspas");
                    return '\"';
                }
                *jump-=1u;
                str--;
            }
            *jump-=1u;
            str--;
        }
        else if((edk::uint8)*str==196u){
            *jump+=1u;
            str++;
            if((edk::uint8)*str==169u){
                //printf("\nTio i");
                return 32u;
            }
            *jump-=1u;
            str--;
        }
        else if((edk::uint8)*str==197u){
            *jump+=1u;
            str++;
            if((edk::uint8)*str==169u){
                //printf("\nTio u");
                return 32u;
            }
            *jump-=1u;
            str--;
        }
        return (edk::uchar8)*str;
    }
    return 0u;
}
//return the wordSize
edk::uint32 edk::fonts::FontMap::wordSize(edk::char8* str){
    if(str){
        edk::uint32 size = 0u;
        edk::uint8 jump=0u;
        edk::uint32 c = this->getTileID(str,&jump);
        while(c){
            if(c == ' ' || c==10 || c == 13){
                break;
            }
            size++;
            str+=jump;
            c = this->getTileID(str,&jump);
        }
        return size;
    }
    return 0u;
}
//return the lineSize
edk::uint32 edk::fonts::FontMap::lineSize(edk::char8* str){
    if(str){
        edk::uint32 size = 0u;
        edk::uint8 jump=0u;
        edk::uint32 c = this->getTileID(str,&jump);
        while(c){
            if(c==10 || c == 13){
                break;
            }
            size++;
            str+=jump;
            c = this->getTileID(str,&jump);
        }
        return size;
    }
    return 0u;
}

//clean lines
void edk::fonts::FontMap::cleanLines(){
    edk::uint32 size = this->lines.size();
    edk::fonts::FontMap::FontLine * temp = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->lines[i];
        if(temp){
            //
            delete temp;
        }
    }
    this->lines.clean();
    this->maxSizeLine=0u;
}
//create new line
edk::fonts::FontMap::FontLine* edk::fonts::FontMap::newLine(edk::uint32 size){
    //test the size
    if(size){
        //create a new line
        edk::fonts::FontMap::FontLine* line = new edk::fonts::FontMap::FontLine(size);
        if(line){
            //test if the line was created
            if(line->getSize() == size){
                //add the line to the stack
                edk::uint32 sizeTemp = this->lines.size();
                this->lines.pushBack(line);
                if(sizeTemp<this->lines.size()){
                    if(size>this->maxSizeLine) this->maxSizeLine = size;
                    //return the line
                    return line;
                }
            }
            delete line;
        }
    }
    return NULL;
}
//return the last line on the map
edk::fonts::FontMap::FontLine* edk::fonts::FontMap::getLastLine(){
    edk::fonts::FontMap::FontLine* ret=NULL;
    //test if have some lines
    if(this->lines.size()){
        //get the last line
        ret = this->lines.get(this->lines.size()-1u);
    }
    return ret;
}
//copy the text to the map
bool edk::fonts::FontMap::copyLinesToMap(){
    //test if have lines
    edk::uint32 size=this->lines.size();
    edk::uint32 sizeLine=0u;
    if(size){
        //
        edk::fonts::FontMap::FontLine *temp=NULL;
        for(edk::uint32 i=0u;i<size;i++){
            //load the line
            temp = this->lines[i];
            if(temp){
                sizeLine=temp->getSize();
                for(edk::uint32 j=0u;j<sizeLine;j++){
                    //copy the character
                    if(!this->map.setTile(temp->getValue(j),j,i)){
                        break;
                    }
                }
            }
        }
        return true;
    }
    return false;
}
//test if have the ID
bool edk::fonts::FontMap::haveID(edk::uint32 ID){
    edk::uint32 width=this->map.getMapSize().width;
    if(width){
        //test the y
        if((ID/width)<this->map.getMapSize().height){
            return true;
        }
    }
    return false;
}
//get position of the tile
edk::vec2ui32 edk::fonts::FontMap::getCharacterPosition(edk::uint32 ID){
    edk::vec2ui32 ret;
    edk::uint32 width=this->map.getMapSize().width;
    edk::uint32 height=this->map.getMapSize().height;
    //test the width
    if(width){
        //get the position
        edk::uint32 x=ID%width;
        edk::uint32 y=ID/width;
        //test the y
        if(y<height){
            ret.x = x;
            ret.y = y;
        }
    }
    return ret;
}
edk::uint32 edk::fonts::FontMap::getCharacterID(edk::vec2ui32 position){
    //test the position
    edk::uint32 width=this->map.getMapSize().width;
    edk::uint32 height=this->map.getMapSize().height;
    if(position.x<=width && position.y<=height){
        //return the ID
        return position.x + (width * position.y);
    }
    return 0u;
}
//Draw
void edk::fonts::FontMap::draw(edk::vec2ui32 origin,edk::vec2ui32 last,edk::color4f32 color){
    //test if the line is the same
    if(origin.y == last.y){
        //then draw correctly
        this->map.draw(origin,edk::size2ui32(last.x+1u,last.y+1u),color);
    }
    else{
        edk::uint32 width = this->map.getMapSize().width;
        this->map.draw(edk::vec2ui32(origin.x,origin.y),edk::size2ui32(width,origin.y+1u),color);
        //draw all the lines
        for(edk::uint32 i=origin.y+1u;i<last.y;i++){
            this->map.draw(edk::vec2ui32(0u,i),edk::size2ui32(this->map.getMapSize().width,i+1u),color);
        }
        this->map.draw(edk::vec2ui32(0u,last.y),edk::size2ui32(last.x+1u,last.y+1u),color);
    }
}
void edk::fonts::FontMap::draw(edk::uint32 originWidth,edk::uint32 originLine,edk::uint32 lastWidth,edk::uint32 lastLine,edk::color4f32 color){
    this->draw(edk::vec2ui32(originWidth,originLine),edk::vec2ui32 (lastWidth,lastLine),color);
}

void edk::fonts::FontMap::drawWithoutMaterial(edk::vec2ui32 origin,edk::vec2ui32 last,edk::color4f32 color){
    //test if the line is the same
    if(origin.y == last.y){
        //then draw correctly
        this->map.drawWithoutMaterial(origin,edk::size2ui32(last.x+1u,last.y+1u),color);
    }
    else{
        edk::uint32 width = this->map.getMapSize().width;
        this->map.drawWithoutMaterial(edk::vec2ui32(origin.x,origin.y),edk::size2ui32(width,origin.y+1u),color);
        //draw all the lines
        for(edk::uint32 i=origin.y+1u;i<last.y;i++){
            this->map.drawWithoutMaterial(edk::vec2ui32(0u,i),edk::size2ui32(this->map.getMapSize().width,i+1u),color);
        }
        this->map.drawWithoutMaterial(edk::vec2ui32(0u,last.y),edk::size2ui32(last.x+1u,last.y+1u),color);
    }
}
void edk::fonts::FontMap::drawWithoutMaterial(edk::uint32 originWidth,edk::uint32 originLine,edk::uint32 lastWidth,edk::uint32 lastLine,edk::color4f32 color){
    this->drawWithoutMaterial(edk::vec2ui32(originWidth,originLine),edk::vec2ui32 (lastWidth,lastLine),color);
}

void edk::fonts::FontMap::drawWire(edk::vec2ui32 origin,edk::vec2ui32 last,edk::color4f32 color){
    //test if the line is the same
    if(origin.y == last.y){
        //then drawWire correctly
        this->map.drawWire(origin,edk::size2ui32(last.x+1u,last.y+1u),color);
    }
    else{
        edk::uint32 width = this->map.getMapSize().width;
        this->map.drawWire(edk::vec2ui32(origin.x,origin.y),edk::size2ui32(width,origin.y+1u),color);
        //drawWire all the lines
        for(edk::uint32 i=origin.y+1u;i<last.y;i++){
            this->map.drawWire(edk::vec2ui32(0u,i),edk::size2ui32(this->map.getMapSize().width,i+1u),color);
        }
        this->map.drawWire(edk::vec2ui32(0u,last.y),edk::size2ui32(last.x+1u,last.y+1u),color);
    }
}
void edk::fonts::FontMap::drawWire(edk::uint32 originWidth,edk::uint32 originLine,edk::uint32 lastWidth,edk::uint32 lastLine,edk::color4f32 color){
    this->drawWire(edk::vec2ui32(originWidth,originLine),edk::vec2ui32 (lastWidth,lastLine),color);
}
void edk::fonts::FontMap::drawSelection(edk::vec2ui32 origin,edk::vec2ui32 last){
    //test if the line is the same
    if(origin.y == last.y){
        //then drawWire correctly
        this->map.drawSelection(origin,edk::size2ui32(last.x+1u,last.y+1u));
    }
    else{
        edk::uint32 width = this->map.getMapSize().width;
        this->map.drawSelection(edk::vec2ui32(origin.x,origin.y),edk::size2ui32(width,origin.y+1u));
        //drawSelection all the lines
        for(edk::uint32 i=origin.y+1u;i<last.y;i++){
            this->map.drawSelection(edk::vec2ui32(0u,i),edk::size2ui32(this->map.getMapSize().width,i+1u));
        }
        this->map.drawSelection(edk::vec2ui32(0u,last.y),edk::size2ui32(last.x+1u,last.y+1u));
    }
}
void edk::fonts::FontMap::drawSelection(edk::uint32 originWidth,edk::uint32 originLine,edk::uint32 lastWidth,edk::uint32 lastLine){
    this->drawSelection(edk::vec2ui32(originWidth,originLine),edk::vec2ui32 (lastWidth,lastLine));
}
//Draw without passing a color
void edk::fonts::FontMap::draw(edk::vec2ui32 origin,edk::vec2ui32 last){
    //test if the line is the same
    if(origin.y == last.y){
        //then draw correctly
        this->map.draw(origin,edk::size2ui32(last.x+1u,last.y+1u));
    }
    else{
        edk::uint32 width = this->map.getMapSize().width;
        this->map.draw(edk::vec2ui32(origin.x,origin.y),edk::size2ui32(width,origin.y+1u));
        //draw all the lines
        for(edk::uint32 i=origin.y+1u;i<last.y;i++){
            this->map.draw(edk::vec2ui32(0u,i),edk::size2ui32(this->map.getMapSize().width,i+1u));
        }
        this->map.draw(edk::vec2ui32(0u,last.y),edk::size2ui32(last.x+1u,last.y+1u));
    }
}
void edk::fonts::FontMap::draw(edk::uint32 originWidth,edk::uint32 originLine,edk::uint32 lastWidth,edk::uint32 lastLine){
    this->draw(edk::vec2ui32(originWidth,originLine),edk::vec2ui32 (lastWidth,lastLine));
}

void edk::fonts::FontMap::drawWithoutMaterial(edk::vec2ui32 origin,edk::vec2ui32 last){
    //test if the line is the same
    if(origin.y == last.y){
        //then draw correctly
        this->map.drawWithoutMaterial(origin,edk::size2ui32(last.x+1u,last.y+1u));
    }
    else{
        edk::uint32 width = this->map.getMapSize().width;
        this->map.drawWithoutMaterial(edk::vec2ui32(origin.x,origin.y),edk::size2ui32(width,origin.y+1u));
        //draw all the lines
        for(edk::uint32 i=origin.y+1u;i<last.y;i++){
            this->map.drawWithoutMaterial(edk::vec2ui32(0u,i),edk::size2ui32(this->map.getMapSize().width,i+1u));
        }
        this->map.drawWithoutMaterial(edk::vec2ui32(0u,last.y),edk::size2ui32(last.x+1u,last.y+1u));
    }
}
void edk::fonts::FontMap::drawWithoutMaterial(edk::uint32 originWidth,edk::uint32 originLine,edk::uint32 lastWidth,edk::uint32 lastLine){
    this->drawWithoutMaterial(edk::vec2ui32(originWidth,originLine),edk::vec2ui32 (lastWidth,lastLine));
}

void edk::fonts::FontMap::drawWire(edk::vec2ui32 origin,edk::vec2ui32 last){
    //test if the line is the same
    if(origin.y == last.y){
        //then drawWire correctly
        this->map.drawWire(origin,edk::size2ui32(last.x+1u,last.y+1u));
    }
    else{
        edk::uint32 width = this->map.getMapSize().width;
        this->map.drawWire(edk::vec2ui32(origin.x,origin.y),edk::size2ui32(width,origin.y+1u));
        //drawWire all the lines
        for(edk::uint32 i=origin.y+1u;i<last.y;i++){
            this->map.drawWire(edk::vec2ui32(0u,i),edk::size2ui32(this->map.getMapSize().width,i+1u));
        }
        this->map.drawWire(edk::vec2ui32(0u,last.y),edk::size2ui32(last.x+1u,last.y+1u));
    }
}
void edk::fonts::FontMap::drawWire(edk::uint32 originWidth,edk::uint32 originLine,edk::uint32 lastWidth,edk::uint32 lastLine){
    this->drawWire(edk::vec2ui32(originWidth,originLine),edk::vec2ui32 (lastWidth,lastLine));
}

//draw the ID
void edk::fonts::FontMap::draw(edk::uint32 originID,edk::uint32 lastID,edk::color4f32 color){
    edk::vec2ui32 origin = this->getCharacterPosition(originID);
    edk::vec2ui32 last = this->getCharacterPosition(lastID);
    return this->draw(origin,last,color);
}
void edk::fonts::FontMap::draw(edk::vec2ui32 origin,edk::uint32 lastID,edk::color4f32 color){
    edk::vec2ui32 last = this->getCharacterPosition(lastID);
    return this->draw(origin,last,color);
}
void edk::fonts::FontMap::draw(edk::uint32 originID,edk::vec2ui32 last,edk::color4f32 color){
    edk::vec2ui32 origin = this->getCharacterPosition(originID);
    return this->draw(origin,last,color);
}
void edk::fonts::FontMap::drawWithoutMaterial(edk::uint32 originID,edk::uint32 lastID,edk::color4f32 color){
    edk::vec2ui32 origin = this->getCharacterPosition(originID);
    edk::vec2ui32 last = this->getCharacterPosition(lastID);
    return this->drawWithoutMaterial(origin,last,color);
}
void edk::fonts::FontMap::drawWithoutMaterial(edk::vec2ui32 origin,edk::uint32 lastID,edk::color4f32 color){
    edk::vec2ui32 last = this->getCharacterPosition(lastID);
    return this->drawWithoutMaterial(origin,last,color);
}
void edk::fonts::FontMap::drawWithoutMaterial(edk::uint32 originID,edk::vec2ui32 last,edk::color4f32 color){
    edk::vec2ui32 origin = this->getCharacterPosition(originID);
    return this->drawWithoutMaterial(origin,last,color);
}
void edk::fonts::FontMap::drawWire(edk::uint32 originID,edk::uint32 lastID,edk::color4f32 color){
    edk::vec2ui32 origin = this->getCharacterPosition(originID);
    edk::vec2ui32 last = this->getCharacterPosition(lastID);
    return this->drawWire(origin,last,color);
}
void edk::fonts::FontMap::drawWire(edk::vec2ui32 origin,edk::uint32 lastID,edk::color4f32 color){
    edk::vec2ui32 last = this->getCharacterPosition(lastID);
    return this->drawWire(origin,last,color);
}
void edk::fonts::FontMap::drawWire(edk::uint32 originID,edk::vec2ui32 last,edk::color4f32 color){
    edk::vec2ui32 origin = this->getCharacterPosition(originID);
    return this->drawWire(origin,last,color);
}
void edk::fonts::FontMap::drawSelection(edk::uint32 originID,edk::uint32 lastID){
    edk::vec2ui32 origin = this->getCharacterPosition(originID);
    edk::vec2ui32 last = this->getCharacterPosition(lastID);
    return this->drawSelection(origin,last);
}
void edk::fonts::FontMap::drawSelection(edk::vec2ui32 origin,edk::uint32 lastID){
    edk::vec2ui32 last = this->getCharacterPosition(lastID);
    return this->drawSelection(origin,last);
}
void edk::fonts::FontMap::drawSelection(edk::uint32 originID,edk::vec2ui32 last){
    edk::vec2ui32 origin = this->getCharacterPosition(originID);
    return this->drawSelection(origin,last);
}
//draw the ID without passing a color
void edk::fonts::FontMap::draw(edk::uint32 originID,edk::uint32 lastID){
    edk::vec2ui32 origin = this->getCharacterPosition(originID);
    edk::vec2ui32 last = this->getCharacterPosition(lastID);
    return this->draw(origin,last);
}
void edk::fonts::FontMap::draw(edk::vec2ui32 origin,edk::uint32 lastID){
    edk::vec2ui32 last = this->getCharacterPosition(lastID);
    return this->draw(origin,last);
}
void edk::fonts::FontMap::draw(edk::uint32 originID,edk::vec2ui32 last){
    edk::vec2ui32 origin = this->getCharacterPosition(originID);
    return this->draw(origin,last);
}
void edk::fonts::FontMap::drawWithoutMaterial(edk::uint32 originID,edk::uint32 lastID){
    edk::vec2ui32 origin = this->getCharacterPosition(originID);
    edk::vec2ui32 last = this->getCharacterPosition(lastID);
    return this->drawWithoutMaterial(origin,last);
}
void edk::fonts::FontMap::drawWithoutMaterial(edk::vec2ui32 origin,edk::uint32 lastID){
    edk::vec2ui32 last = this->getCharacterPosition(lastID);
    return this->drawWithoutMaterial(origin,last);
}
void edk::fonts::FontMap::drawWithoutMaterial(edk::uint32 originID,edk::vec2ui32 last){
    edk::vec2ui32 origin = this->getCharacterPosition(originID);
    return this->drawWithoutMaterial(origin,last);
}
void edk::fonts::FontMap::drawWire(edk::uint32 originID,edk::uint32 lastID){
    edk::vec2ui32 origin = this->getCharacterPosition(originID);
    edk::vec2ui32 last = this->getCharacterPosition(lastID);
    return this->drawWire(origin,last);
}
void edk::fonts::FontMap::drawWire(edk::vec2ui32 origin,edk::uint32 lastID){
    edk::vec2ui32 last = this->getCharacterPosition(lastID);
    return this->drawWire(origin,last);
}
void edk::fonts::FontMap::drawWire(edk::uint32 originID,edk::vec2ui32 last){
    edk::vec2ui32 origin = this->getCharacterPosition(originID);
    return this->drawWire(origin,last);
}

//SET
void edk::fonts::FontMap::setPosition(edk::vec2f32 position){
    this->map.setPosition(position);
}
void edk::fonts::FontMap::setPosition(edk::float32 x,edk::float32 y){
    this->map.setPosition(x,y);
}
void edk::fonts::FontMap::setScale(edk::size2f32 scale){
    this->map.setScaleMap(scale);
}
void edk::fonts::FontMap::setScale(edk::float32 width,edk::float32 height){
    this->map.setScaleMap(width,height);
}

//GET
edk::vec2f32 edk::fonts::FontMap::getPosition(){
    return this->map.getPosition();
}
edk::float32 edk::fonts::FontMap::getPositionX(){
    return this->map.getPositionX();
}
edk::float32 edk::fonts::FontMap::getPositionY(){
    return this->map.getPositionY();
}
//get size of the map
edk::size2ui32 edk::fonts::FontMap::getMapSize(){
    return this->map.getMapSize();
}
edk::uint32 edk::fonts::FontMap::getMapSizeWidth(){
    return this->map.getMapSize().width;
}
edk::uint32 edk::fonts::FontMap::getMapSizeHeight(){
    return this->map.getMapSize().height;
}
//get the mapScale
edk::size2f32 edk::fonts::FontMap::getMapScale(){
    return this->map.getScaleMap();
}
edk::float32 edk::fonts::FontMap::getMapScaleWidth(){
    return this->map.getScaleMap().width;
}
edk::float32 edk::fonts::FontMap::getMapScaleHeight(){
    return this->map.getScaleMap().height;
}
//return the last position
edk::vec2ui32 edk::fonts::FontMap::getTheLastPosition(){
    vec2ui32 ret(0u,0u);
    if(this->map.getMapSize().width){
        ret.x = this->map.getMapSize().width-1u;
    }
    if(this->map.getMapSize().height){
        ret.y = this->map.getMapSize().height-1u;
    }
    return ret;
}
edk::uint32 edk::fonts::FontMap::getTheLastPositionX(){
    return this->getTheLastPosition().x;
}
edk::uint32 edk::fonts::FontMap::getTheLastPositionY(){
    return this->getTheLastPosition().y;
}
//load fontImage
bool edk::fonts::FontMap::loadFontImage(const edk::char8* name,edk::uint32 filter,edk::color4f32 color){
    return this->loadFontImage((edk::char8*) name,filter,color);
}
bool edk::fonts::FontMap::loadFontImage(edk::char8* name,edk::uint32 filter,edk::color4f32 color){
    //remove the fontImage
    this->removeFontImage();
    //test the name
    if(name){
        //load the fontImage
        if((this->set = this->list.createFontSet(name,filter,color))){
            //set tileSet in map
            if(this->map.setTileSet(this->set->getTileSet())){
                //return true
                return true;
            }
        }
    }
    //else remove fontImage
    this->removeFontImage();
    return false;
}
bool edk::fonts::FontMap::loadFontImageFromMemory(const edk::char8* name,
                                                  edk::uint8* image,
                                                  edk::uint32 size,
                                                  edk::uint32 filter,
                                                  edk::color4f32 color
                                                  ){
    return this->loadFontImageFromMemory((edk::char8*) name,image,size,filter,color);
}

bool edk::fonts::FontMap::loadFontImageFromMemory(edk::char8* name,
                                                  edk::uint8* image,
                                                  edk::uint32 size,
                                                  edk::uint32 filter,
                                                  edk::color4f32 color
                                                  ){
    //remove the fontImage
    this->removeFontImage();
    //test the name
    if(name){
        //load the fontImage
        if((this->set = this->list.createFontSetFromMemory(name,image,size,filter,color))){
            //set tileSet in map
            if(this->map.setTileSet(this->set->getTileSet())){
                //return true
                return true;
            }
        }
    }
    //else remove fontImage
    this->removeFontImage();
    return false;
}
bool edk::fonts::FontMap::loadFontImageFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter,edk::color4f32 color){
    return this->loadFontImageFromPack(pack,(edk::char8*) name,filter,color);
}
bool edk::fonts::FontMap::loadFontImageFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter,edk::color4f32 color){
    //remove the fontImage
    this->removeFontImage();
    //test the name
    if(name && pack){
        //load the fontImage
        if((this->set = this->list.createFontSetFromPack(pack,name,filter,color))){
            //set tileSet in map
            if(this->map.setTileSet(this->set->getTileSet())){
                //return true
                return true;
            }
        }
    }
    //else remove fontImage
    this->removeFontImage();
    return false;
}
//create a map
bool edk::fonts::FontMap::createMap(edk::size2ui32 size){
    //clean the lines
    this->cleanLines();
    //test the size
    if(size.width && size.height){
        //
        if(this->map.newTileMap(size.width,size.height)){
            this->selectAll();
            return true;
        }
    }
    return false;
}
bool edk::fonts::FontMap::createMap(edk::uint32 width,edk::uint32 height){
    return this->createMap(edk::size2ui32(width,height));
}

//create the string
bool edk::fonts::FontMap::createStringMap(const edk::char8* str,edk::uint32 width){
    return this->createStringMap((edk::char8*) str,width);
}
bool edk::fonts::FontMap::createStringMap(edk::char8* str,edk::uint32 width){
    this->cleanLines();
    if(this->addStringLine(str,width)){
        return true;
    }
    //first get the word size
    this->cleanLines();
    return false;
}
bool edk::fonts::FontMap::createStringMap(const edk::char8* str){
    return this->createStringMap((edk::char8*) str);
}
bool edk::fonts::FontMap::createStringMap(edk::char8* str){
    this->cleanLines();
    if(this->addStringLine(str)){
        return true;
    }
    this->cleanLines();
    return false;
}
bool edk::fonts::FontMap::addStringLine(const edk::char8* str,edk::uint32 width){
    return this->addStringLine((edk::char8*) str, width);
}
bool edk::fonts::FontMap::addStringLine(edk::char8* str,edk::uint32 width){
    //first get the word size
    if(str && width){
        edk::fonts::FontMap::FontLine* line=NULL;
        edk::uint32 size = 0u;
        edk::uint32 c = 0u;
        edk::uint8 jump=0u;
        edk::uint32 enters=0u;
        while(*str){
            //test if dont have the line
            if(!line){
                //create the new line
                line = this->newLine(width);
                this->write=0u;
            }
            //test if have the line
            if(line){
                //
                size = this->wordSize(str);
                if(size){
                    enters=0u;
                    //test if can write the word in the line
                    if(size<=(line->getSize()-this->write)){
                        //then write the word
                        for(edk::uint32 i=0u;i<size;i++){
                            c = this->getTileID(str,&jump);
                            line->setValue(this->write,c+1u);
                            str+=jump;
                            this->write++;
                        }
                    }
                    //test if the write is zero
                    else if(!this->write){
                        //then break the word
                        size = line->getSize();
                        for(edk::uint32 i=0u;i<size;i++){
                            c = this->getTileID(str,&jump);
                            line->setValue(this->write,c+1u);
                            str+=jump;
                            this->write++;
                        }
                    }
                    else{
                        //else create a new line
                        line=NULL;
                    }
                }
                else{
                    //test if can write the character
                    if(this->write<line->getSize()){
                        //write the character
                        c = this->getTileID(str,&jump);
                        //test if have the enter '\n'
                        if(c==10 || c == 13 || c == '\n'){
                            //then create a new line
                            if(enters){
                                line=NULL;
                            }
                            enters++;
                            str+=jump;
                        }
                        else{
                            line->setValue(this->write,c+1u);
                            this->write++;
                            str+=jump;
                            enters=0u;
                        }
                    }
                    else{
                        //else clean the line pointer
                        line=NULL;
                    }
                }
            }
            else{
                return false;
            }
        }
        //test if have lines
        if(this->lines.size()){
            //create the new tileMap
            if(this->map.newTileMap(this->maxSizeLine,this->lines.size())){
                this->copyLinesToMap();
                //this->cleanLines();
                this->selectAll();
                return true;
            }
        }
    }
    return false;
}
bool edk::fonts::FontMap::addStringLine(const edk::char8* str){
    return this->addStringLine((edk::char8*) str);
}
bool edk::fonts::FontMap::addStringLine(edk::char8* str){
    //first get the word size
    if(str){
        edk::fonts::FontMap::FontLine* line=NULL;
        edk::uint32 size = 0u;
        edk::uint32 c = 0u;
        edk::uint8 jump=0u;
        edk::uint32 width=0u;
        edk::uint32 enters=0u;
        while(*str){
            //test if dont have the line
            if(!line){
                //get the lineSize
                width = this->lineSize(str);
                if(width){
                    //create the new line
                    line = this->newLine(width);
                    this->write=0u;
                    enters=0u;
                }
                else{
                    if(*str == 10 || *str == 13){
                        if(enters){
                            line = this->newLine(1u);
                        }
                        enters++;
                    }
                }
            }
            //test if have the line
            if(line){
                //
                size = this->wordSize(str);
                if(size){
                    //test if can write the word in the line
                    if(size<=(line->getSize()-this->write)){
                        //then write the word
                        for(edk::uint32 i=0u;i<size;i++){
                            c = this->getTileID(str,&jump);
                            line->setValue(this->write,c+1u);
                            str+=jump;
                            this->write++;
                        }
                    }
                    //test if the write is zero
                    else if(!write){
                        //then break the word
                        size = line->getSize();
                        for(edk::uint32 i=0u;i<size;i++){
                            c = this->getTileID(str,&jump);
                            line->setValue(this->write,c+1u);
                            str+=jump;
                            this->write++;
                        }
                    }
                    else{
                        //else create a new line
                        line=NULL;
                    }
                }
                else{
                    //test if can write the character
                    if(this->write<line->getSize()){
                        //write the character
                        c = this->getTileID(str,&jump);
                        //test if have the enter '\n'
                        if(c==10 || c == 13 || c == '\n'){
                            //then create a new line
                            line=NULL;
                            str+=jump;
                        }
                        else{
                            line->setValue(this->write,c+1u);
                            this->write++;
                            str+=jump;
                        }
                    }
                    else{
                        //else clean the line pointer
                        line=NULL;
                        if(*str == 10 || *str == 13){
                            str++;
                        }
                    }
                }
            }
            else if(*str)str++;
        }
        //test if have lines
        if(this->lines.size()){
            //create the new tileMap
            if(this->map.newTileMap(this->maxSizeLine,this->lines.size())){
                this->copyLinesToMap();
                //this->cleanLines();
                this->selectAll();
                return true;
            }
        }
    }
    return false;
}
bool edk::fonts::FontMap::createStringMapOneLine(const edk::char8* str,edk::uint32 width){
    return this->createStringMapOneLine((edk::char8*) str,width);
}
bool edk::fonts::FontMap::createStringMapOneLine(edk::char8* str,edk::uint32 width){
    this->cleanLines();
    //first get the word size
    if(str && width){
        edk::fonts::FontMap::FontLine* line=NULL;
        edk::uint32 size = 0u;
        edk::uint32 c = 0u;
        edk::uint8 jump=0u;
        edk::uint32 enters=0u;
        bool haveLine = false;
        while(*str){
            //test if dont have the line
            if(!line){
                if(haveLine){
                    break;
                }
                haveLine=true;
                //create the new line
                line = this->newLine(width);
                this->write=0u;
            }
            //test if have the line
            if(line){
                //
                size = this->wordSize(str);
                if(size){
                    enters=0u;
                    //test if can write the word in the line
                    if(size<=(line->getSize()-this->write)){
                        //then write the word
                        for(edk::uint32 i=0u;i<size;i++){
                            c = this->getTileID(str,&jump);
                            line->setValue(this->write,c+1u);
                            str+=jump;
                            this->write++;
                        }
                    }
                    //test if the write is zero
                    else if(!this->write){
                        //then break the word
                        size = line->getSize();
                        for(edk::uint32 i=0u;i<size;i++){
                            c = this->getTileID(str,&jump);
                            line->setValue(this->write,c+1u);
                            str+=jump;
                            this->write++;
                        }
                    }
                    else{
                        //else create a new line
                        line=NULL;
                    }
                }
                else{
                    //test if can write the character
                    if(this->write<line->getSize()){
                        //write the character
                        c = this->getTileID(str,&jump);
                        //test if have the enter '\n'
                        if(c==10 || c == 13 || c == '\n'){
                            //then create a new line
                            if(enters){
                                line=NULL;
                            }
                            enters++;
                            str+=jump;
                        }
                        else{
                            line->setValue(this->write,c+1u);
                            this->write++;
                            str+=jump;
                            enters=0u;
                        }
                    }
                    else{
                        //else clean the line pointer
                        line=NULL;
                    }
                }
            }
            else{
                this->cleanLines();
                return false;
            }
        }
        //test if have lines
        if(this->lines.size()){
            //create the new tileMap
            if(this->map.newTileMap(width,this->lines.size())){
                this->copyLinesToMap();
                //this->cleanLines();
                this->selectAll();
                return true;
            }
        }
    }
    this->cleanLines();
    return false;
}
bool edk::fonts::FontMap::createStringMapOneLine(const edk::char8* str){
    return this->createStringMapOneLine((edk::char8*) str);
}
bool edk::fonts::FontMap::createStringMapOneLine(edk::char8* str){
    this->cleanLines();
    //first get the word size
    if(str){
        edk::fonts::FontMap::FontLine* line=NULL;
        edk::uint32 size = 0u;
        edk::uint32 c = 0u;
        edk::uint8 jump=0u;
        edk::uint32 width=0u;
        edk::uint32 enters=0u;
        bool haveLine = false;
        while(*str){
            //test if dont have the line
            if(!line){
                if(haveLine){
                    break;
                }
                haveLine=true;
                //get the lineSize
                width = this->lineSize(str);
                if(width){
                    //create the new line
                    line = this->newLine(width);
                    this->write=0u;
                    enters=0u;
                }
                else{
                    if(*str == 10 || *str == 13){
                        if(enters){
                            this->newLine(1u);
                        }
                        enters++;
                    }
                }
            }
            //test if have the line
            if(line){
                //
                size = this->wordSize(str);
                if(size){
                    //test if can write the word in the line
                    if(size<=(line->getSize()-this->write)){
                        //then write the word
                        for(edk::uint32 i=0u;i<size;i++){
                            c = this->getTileID(str,&jump);
                            line->setValue(this->write,c+1u);
                            str+=jump;
                            this->write++;
                        }
                    }
                    //test if the write is zero
                    else if(!this->write){
                        //then break the word
                        size = line->getSize();
                        for(edk::uint32 i=0u;i<size;i++){
                            c = this->getTileID(str,&jump);
                            line->setValue(this->write,c+1u);
                            str+=jump;
                            this->write++;
                        }
                    }
                    else{
                        //else create a new line
                        line=NULL;
                    }
                }
                else{
                    //test if can write the character
                    if(this->write<line->getSize()){
                        //write the character
                        c = this->getTileID(str,&jump);
                        //test if have the enter '\n'
                        if(c==10 || c == 13 || c == '\n'){
                            //then create a new line
                            line=NULL;
                            str+=jump;
                        }
                        else{
                            line->setValue(this->write,c+1u);
                            this->write++;
                            str+=jump;
                        }
                    }
                    else{
                        //else clean the line pointer
                        line=NULL;
                    }
                }
            }
            else if(*str)str++;
        }
        //test if have lines
        if(this->lines.size()){
            //create the new tileMap
            if(this->map.newTileMap(this->maxSizeLine,this->lines.size())){
                this->copyLinesToMap();
                this->cleanLines();
                this->selectAll();
                return true;
            }
        }
    }
    this->cleanLines();
    return false;
}

//write a character in the map position
bool edk::fonts::FontMap::writeChar(edk::uchar8 c,edk::uint32 x,edk::uint32 y){
    //test if have the position in the map
    if(x<this->map.getMapSize().width && y<this->map.getMapSize().height
            && c
            ){
        //set the character in the map
        edk::char8 str[2u];
        str[0u]=c;
        str[1u]='\0';
        edk::uint8 jump=0u;
        c = this->getTileID(str,&jump);

        return this->map.setTile(c+1,x,y);
    }
    return false;
}
bool edk::fonts::FontMap::writeChar(edk::uchar8 c,edk::vec2ui32 position){
    return this->writeChar(c,position.x,position.y);
}
bool edk::fonts::FontMap::writeChar(edk::char8* c,edk::uint32 x,edk::uint32 y){
    //test if have the position in the map
    if(x<this->map.getMapSize().width && y<this->map.getMapSize().height
            && c
            ){
        //set the character in the map
        edk::uint8 jump;
        edk::uint32 temp = this->getTileID(c,&jump);

        return this->map.setTile(temp+1,x,y);
    }
    return false;
}
bool edk::fonts::FontMap::writeChar(edk::char8* c,edk::vec2ui32 position){
    return this->writeChar(c,position.x,position.y);
}
bool edk::fonts::FontMap::writeChar(const edk::char8* c,edk::uint32 x,edk::uint32 y){
    return this->writeChar((edk::char8*) c,x,y);
}
bool edk::fonts::FontMap::writeChar(const edk::char8* c,edk::vec2ui32 position){
    return this->writeChar((edk::char8*) c,position);
}
bool edk::fonts::FontMap::writeColor(edk::color4f32 color,edk::uint32 x,edk::uint32 y){
    //test if have the position in the map
    if(x<this->map.getMapSize().width && y<this->map.getMapSize().height
            ){
        return this->map.setTileColor(color,x,y);
    }
    return false;
}
bool edk::fonts::FontMap::writeColor(edk::color4f32 color,edk::vec2ui32 position){
    return this->writeColor(color,position.x,position.y);
}
bool edk::fonts::FontMap::writeColor(edk::color3f32 color,edk::uint32 x,edk::uint32 y){
    return this->writeColor(edk::color4f32(color.r,color.g,color.b,1.f),x,y);
}
bool edk::fonts::FontMap::writeColor(edk::color3f32 color,edk::vec2ui32 position){
    return this->writeColor(edk::color4f32(color.r,color.g,color.b,1.f),position.x,position.y);
}
bool edk::fonts::FontMap::writeColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a,edk::uint32 x,edk::uint32 y){
    return this->writeColor(edk::color4f32(r,g,b,a),x,y);
}
bool edk::fonts::FontMap::writeColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a,edk::vec2ui32 position){
    return this->writeColor(edk::color4f32(r,g,b,a),position.x,position.y);
}
bool edk::fonts::FontMap::writeColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::uint32 x,edk::uint32 y){
    return this->writeColor(edk::color4f32(r,g,b,1.f),x,y);
}
bool edk::fonts::FontMap::writeColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::vec2ui32 position){
    return this->writeColor(edk::color4f32(r,g,b,1.f),position.x,position.y);
}

bool edk::fonts::FontMap::writeString(const edk::char8* str,edk::uint32 x,edk::uint8 y,edk::uint32 width){
    return this->writeString((edk::char8*) str,x,y,width);
}
bool edk::fonts::FontMap::writeString(edk::char8* str,edk::uint32 x,edk::uint8 y,edk::uint32 width){
    edk::uint32 lenght=x+width;
    if(lenght>=this->map.getMapSize().width){
        lenght = this->map.getMapSize().width;
        width = lenght-x;
    }
    if(str && width
            && x<this->map.getMapSize().width
            && y<this->map.getMapSize().height
            ){
        edk::uint32 size=0u;
        edk::uint32 headX=x;
        edk::uint32 headY=y;
        edk::uint32 c;
        edk::uint32 space;
        edk::uint8 jump=0u;
        edk::char8 temp[2u];
        bool haveInitialReturn=true;
        bool newLine=false;
        temp[0u]=' ';
        temp[1u]='\0';
        //prepare the space
        space = this->getTileID(temp,&jump);
        while(*str){
            size = this->wordSize(str);
            //test if the word fit inside the line
            if(size>=lenght-headX){
                newLine=true;
                //test if the headX is in the beggining
                if(headX==x){
                    size = width;
                }
                else{
                    //clean the last characters of the line
                    for(;headX<lenght;headX++){
                        this->map.setTile(space+1u,headX,headY);
                    }

                    //else it create a new line
                    headY++;
                    headX=x;
                    if(headY>=this->map.getMapSize().height){
                        break;
                    }
                    continue;
                }
            }
            //write the characters
            if(size){
                haveInitialReturn=false;
                for(edk::uint32 i=0u;i<size;i++){
                    c = this->getTileID(str,&jump);
                    this->map.setTile(c+1u,headX,headY);
                    str+=jump;
                    headX++;
                }
            }
            else{
                if(*str=='\n' || *str==10){
                    if(headX == x && !haveInitialReturn){
                        //
                        str++;
                    }
                    else{
                        //clean the last characters of the line
                        for(;headX<lenght;headX++){
                            this->map.setTile(space+1u,headX,headY);
                        }

                        //create a new line
                        headY++;
                        headX=x;
                        str++;
                        if(headY>=this->map.getMapSize().height){
                            break;
                        }
                    }
                    haveInitialReturn=true;
                }
                else if(*str==' ' && newLine){
                    if(str[1u]!=' ' && str[1u]!=10 && str[1u]!='\n'){
                        str++;
                    }
                }
                else{
                    haveInitialReturn=false;
                    c = this->getTileID(str,&jump);
                    this->map.setTile(c+1u,headX,headY);
                    str+=jump;
                    headX++;
                }
            }
            newLine=false;
        }
        return true;
    }
    return false;
}
bool edk::fonts::FontMap::writeString(const edk::char8* str,edk::vec2ui32 position,edk::uint32 width){
    return this->writeString((edk::char8*) str,position.x,position.y,width);
}
bool edk::fonts::FontMap::writeString(edk::char8* str,edk::vec2ui32 position,edk::uint32 width){
    return this->writeString(str,position.x,position.y,width);
}
bool edk::fonts::FontMap::writeString(const edk::char8* str,edk::uint32 x,
                                      edk::uint8 y,
                                      edk::uint32 width,
                                      edk::uint32 height
                                      ){
    return this->writeString((edk::char8*) str,x,y,width,height);
}

bool edk::fonts::FontMap::writeString(edk::char8* str,edk::uint32 x,edk::uint8 y,edk::uint32 width,edk::uint32 height){
    edk::uint32 lenght=x+width;
    if(lenght>=this->map.getMapSize().width){
        lenght = this->map.getMapSize().width;
        width = lenght-x;
    }
    edk::uint32 up=y+height;
    if(up>=this->map.getMapSize().height){
        up = this->map.getMapSize().height;
        height = up-y;
    }
    if(str && width && height
            && x<this->map.getMapSize().width
            && y<this->map.getMapSize().height
            ){
        //
        edk::uint32 size=0u;
        edk::uint32 headX=x;
        edk::uint32 headY=y;
        edk::uint32 c;
        edk::uint32 space;
        edk::uint8 jump=0u;
        edk::char8 temp[2u];
        bool haveInitialReturn=true;
        bool newLine=false;
        temp[0u]=' ';
        temp[1u]='\0';
        //prepare the space
        space = this->getTileID(temp,&jump);
        while(*str){
            size = this->wordSize(str);
            //test if the word fit inside the line
            if(size>=lenght-headX){
                newLine=true;
                //test if the headX is in the beggining
                if(headX==x){
                    size = width;
                }
                else{
                    //clean the last characters of the line
                    for(;headX<lenght;headX++){
                        this->map.setTile(space+1u,headX,headY);
                    }

                    //else it create a new line
                    headY++;
                    headX=x;
                    if(headY>=up){
                        break;
                    }
                    continue;
                }
            }
            //write the characters
            if(size){
                haveInitialReturn=false;
                for(edk::uint32 i=0u;i<size;i++){
                    c = this->getTileID(str,&jump);
                    this->map.setTile(c+1u,headX,headY);
                    str+=jump;
                    headX++;
                }
            }
            else{
                if(*str=='\n' || *str==10){
                    if(headX == x && !haveInitialReturn){
                        //
                        str++;
                    }
                    else{
                        //clean the last characters of the line
                        for(;headX<lenght;headX++){
                            this->map.setTile(space+1u,headX,headY);
                        }

                        //create a new line
                        headY++;
                        headX=x;
                        str++;
                        if(headY>=up){
                            break;
                        }
                    }
                    haveInitialReturn=true;
                }
                else if(*str==' ' && newLine){
                    if(str[1u]!=' ' && str[1u]!=10 && str[1u]!='\n'){
                        str++;
                    }
                }
                else{
                    haveInitialReturn=false;
                    c = this->getTileID(str,&jump);
                    this->map.setTile(c+1u,headX,headY);
                    str+=jump;
                    headX++;
                }
            }
            newLine=false;
        }
        return true;
    }
    return false;
}
bool edk::fonts::FontMap::writeString(const edk::char8* str,
                                      edk::vec2ui32 position,
                                      edk::uint32 width,
                                      edk::uint32 height
                                      ){
    return this->writeString((edk::char8*) str,position.x,position.y,width,height);
}
bool edk::fonts::FontMap::writeString(edk::char8* str,
                                      edk::vec2ui32 position,
                                      edk::uint32 width,
                                      edk::uint32 height
                                      ){
    return this->writeString(str,position.x,position.y,width,height);
}
bool edk::fonts::FontMap::writeString(const edk::char8* str,edk::uint32 x,edk::uint8 y,edk::size2ui32 size){
    return this->writeString((edk::char8*) str,x,y,size.width,size.height);
}
bool edk::fonts::FontMap::writeString(edk::char8* str,edk::uint32 x,edk::uint8 y,edk::size2ui32 size){
    return this->writeString(str,x,y,size.width,size.height);
}
bool edk::fonts::FontMap::writeString(const edk::char8* str,edk::vec2ui32 position,edk::size2ui32 size){
    return this->writeString((edk::char8*) str,position.x,position.y,size.width,size.height);
}
bool edk::fonts::FontMap::writeString(edk::char8* str,edk::vec2ui32 position,edk::size2ui32 size){
    return this->writeString(str,position.x,position.y,size.width,size.height);
}

bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeStringColor((edk::char8*) str,x,y,width,r,g,b,a);
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    edk::uint32 lenght=x+width;
    if(lenght>=this->map.getMapSize().width){
        lenght = this->map.getMapSize().width;
        width = lenght-x;
    }
    if(str && width
            && x<this->map.getMapSize().width
            && y<this->map.getMapSize().height
            ){
        //
        edk::uint32 size=0u;
        edk::uint32 headX=x;
        edk::uint32 headY=y;
        edk::uint32 c;
        edk::uint32 space;
        edk::uint8 jump=0u;
        edk::char8 temp[2u];
        bool haveInitialReturn=true;
        bool newLine=false;
        temp[0u]=' ';
        temp[1u]='\0';
        //prepare the space
        space = this->getTileID(temp,&jump);
        while(*str){
            size = this->wordSize(str);
            //test if the word fit inside the line
            if(size>=lenght-headX){
                newLine=true;
                //test if the headX is in the beggining
                if(headX==x){
                    size = width;
                }
                else{
                    //clean the last characters of the line
                    for(;headX<lenght;headX++){
                        this->map.setTile(space+1u,headX,headY);
                        this->map.setTileColor(r,g,b,a,headX,headY);
                    }

                    //else it create a new line
                    headY++;
                    headX=x;
                    if(headY>=this->map.getMapSize().height){
                        break;
                    }
                    continue;
                }
            }
            //write the characters
            if(size){
                haveInitialReturn=false;
                for(edk::uint32 i=0u;i<size;i++){
                    c = this->getTileID(str,&jump);
                    this->map.setTile(c+1u,headX,headY);
                    this->map.setTileColor(r,g,b,a,headX,headY);
                    str+=jump;
                    headX++;
                }
            }
            else{
                if(*str=='\n' || *str==10){
                    if(headX == x && !haveInitialReturn){
                        //
                        str++;
                    }
                    else{
                        //clean the last characters of the line
                        for(;headX<lenght;headX++){
                            this->map.setTile(space+1u,headX,headY);
                            this->map.setTileColor(r,g,b,a,headX,headY);
                        }

                        //create a new line
                        headY++;
                        headX=x;
                        str++;
                        if(headY>=this->map.getMapSize().height){
                            break;
                        }
                    }
                    haveInitialReturn=true;
                }
                else if(*str==' ' && newLine){
                    if(str[1u]!=' ' && str[1u]!=10 && str[1u]!='\n'){
                        str++;
                    }
                }
                else{
                    haveInitialReturn=false;
                    c = this->getTileID(str,&jump);
                    this->map.setTile(c+1u,headX,headY);
                    this->map.setTileColor(r,g,b,a,headX,headY);
                    str+=jump;
                    headX++;
                }
            }
            newLine=false;
        }
        return true;
    }
    return false;
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeStringColor((edk::char8*) str,position.x,position.y,width,r,g,b,a);
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeStringColor(str,position.x,position.y,width,r,g,b,a);
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeStringColor((edk::char8*) str,x,y,width,height,r,g,b,a);
}

bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    edk::uint32 lenght=x+width;
    if(lenght>=this->map.getMapSize().width){
        lenght = this->map.getMapSize().width;
        width = lenght-x;
    }
    edk::uint32 up=y+height;
    if(up>=this->map.getMapSize().height){
        up = this->map.getMapSize().height;
        height = up-y;
    }
    if(str && width && height
            && x<this->map.getMapSize().width
            && y<this->map.getMapSize().height
            ){
        //
        edk::uint32 size=0u;
        edk::uint32 headX=x;
        edk::uint32 headY=y;
        edk::uint32 c;
        edk::uint32 space;
        edk::uint8 jump=0u;
        edk::char8 temp[2u];
        bool haveInitialReturn=true;
        bool newLine=false;
        temp[0u]=' ';
        temp[1u]='\0';
        //prepare the space
        space = this->getTileID(temp,&jump);
        while(*str){
            size = this->wordSize(str);
            //test if the word fit inside the line
            if(size>=lenght-headX){
                newLine=true;
                //test if the headX is in the beggining
                if(headX==x){
                    size = width;
                }
                else{
                    //clean the last characters of the line
                    for(;headX<lenght;headX++){
                        this->map.setTile(space+1u,headX,headY);
                        this->map.setTileColor(r,g,b,a,headX,headY);
                    }

                    //else it create a new line
                    headY++;
                    headX=x;
                    if(headY>=up){
                        break;
                    }
                    continue;
                }
            }
            //write the characters
            if(size){
                haveInitialReturn=false;
                for(edk::uint32 i=0u;i<size;i++){
                    c = this->getTileID(str,&jump);
                    this->map.setTile(c+1u,headX,headY);
                    this->map.setTileColor(r,g,b,a,headX,headY);
                    str+=jump;
                    headX++;
                }
            }
            else{
                if(*str=='\n' || *str==10){
                    if(headX == x && !haveInitialReturn){
                        //
                        str++;
                    }
                    else{
                        //clean the last characters of the line
                        for(;headX<lenght;headX++){
                            this->map.setTile(space+1u,headX,headY);
                            this->map.setTileColor(r,g,b,a,headX,headY);
                        }

                        //create a new line
                        headY++;
                        headX=x;
                        str++;
                        if(headY>=up){
                            break;
                        }
                    }
                    haveInitialReturn=true;
                }
                else if(*str==' ' && newLine){
                    if(str[1u]!=' ' && str[1u]!=10 && str[1u]!='\n'){
                        str++;
                    }
                }
                else{
                    haveInitialReturn=false;
                    c = this->getTileID(str,&jump);
                    this->map.setTile(c+1u,headX,headY);
                    this->map.setTileColor(r,g,b,a,headX,headY);
                    str+=jump;
                    headX++;
                }
            }
            newLine=false;
        }
        return true;
    }
    return false;
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeStringColor((edk::char8*) str,position.x,position.y,width,height,r,g,b,a);
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeStringColor(str,position.x,position.y,width,height,r,g,b,a);
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::size2ui32 size,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeStringColor((edk::char8*) str,x,y,size.width,size.height,r,g,b,a);
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::size2ui32 size,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeStringColor(str,x,y,size.width,size.height,r,g,b,a);
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::size2ui32 size,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeStringColor((edk::char8*) str,position.x,position.y,size.width,size.height,r,g,b,a);
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::size2ui32 size,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeStringColor(str,position.x,position.y,size.width,size.height,r,g,b,a);
}

bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeStringColor((edk::char8*) str,x,y,width,r,g,b,1.0f);
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeStringColor(str,x,y,width,r,g,b,1.f);
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeStringColor((edk::char8*) str,position.x,position.y,width,r,g,b,1.0f);
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeStringColor(str,position.x,position.y,width,r,g,b,1.0f);
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeStringColor((edk::char8*) str,x,y,width,height,r,g,b,1.0f);
}

bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeStringColor(str,x,y,width,height,r,g,b,1.f);
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeStringColor((edk::char8*) str,position.x,position.y,width,height,r,g,b,1.0f);
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeStringColor(str,position.x,position.y,width,height,r,g,b,1.0f);
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::size2ui32 size,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeStringColor((edk::char8*) str,x,y,size.width,size.height,r,g,b,1.0f);
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::size2ui32 size,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeStringColor(str,x,y,size.width,size.height,r,g,b,1.0f);
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::size2ui32 size,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeStringColor((edk::char8*) str,position.x,position.y,size.width,size.height,r,g,b,1.0f);
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::size2ui32 size,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeStringColor(str,position.x,position.y,size.width,size.height,r,g,b,1.0f);
}

bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::color4f32 color
                                           ){
    return this->writeStringColor((edk::char8*) str,x,y,width,color.r,color.g,color.b,color.a);
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::color4f32 color
                                           ){
    return this->writeStringColor(str,x,y,width,color.r,color.g,color.b,color.a);
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::color4f32 color
                                           ){
    return this->writeStringColor((edk::char8*) str,position.x,position.y,width,color.r,color.g,color.b,color.a);
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::color4f32 color
                                           ){
    return this->writeStringColor(str,position.x,position.y,width,color.r,color.g,color.b,color.a);
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::color4f32 color
                                           ){
    return this->writeStringColor((edk::char8*) str,x,y,width,height,color.r,color.g,color.b,color.a);
}

bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::color4f32 color
                                           ){
    return this->writeStringColor(str,x,y,width,height,color.r,color.g,color.b,color.a);
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::color4f32 color
                                           ){
    return this->writeStringColor((edk::char8*) str,
                                  position.x,
                                  position.y,
                                  width,height,
                                  color.r,
                                  color.g,
                                  color.b,
                                  color.a
                                  );
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::color4f32 color
                                           ){
    return this->writeStringColor(str,position.x,position.y,width,height,color.r,color.g,color.b,color.a);
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::size2ui32 size,
                                           edk::color4f32 color
                                           ){
    return this->writeStringColor((edk::char8*) str,x,y,size.width,size.height,color.r,color.g,color.b,color.a);
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::size2ui32 size,
                                           edk::color4f32 color
                                           ){
    return this->writeStringColor(str,x,y,size.width,size.height,color.r,color.g,color.b,color.a);
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::size2ui32 size,
                                           edk::color4f32 color
                                           ){
    return this->writeStringColor((edk::char8*) str,position.x,
                                  position.y,
                                  size.width,
                                  size.height,
                                  color.r,
                                  color.g,
                                  color.b,
                                  color.a
                                  );
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::size2ui32 size,
                                           edk::color4f32 color
                                           ){
    return this->writeStringColor(str,position.x,position.y,size.width,size.height,color.r,color.g,color.b,color.a);
}

bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::color3f32 color
                                           ){
    return this->writeStringColor((edk::char8*) str,x,y,width,color.r,color.g,color.b,1.0f);
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::color3f32 color
                                           ){
    return this->writeStringColor(str,x,y,width,color.r,color.g,color.b,1.0f);
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::color3f32 color
                                           ){
    return this->writeStringColor((edk::char8*) str,position.x,position.y,width,color.r,color.g,color.b,1.0f);
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::color3f32 color
                                           ){
    return this->writeStringColor(str,position.x,position.y,width,color.r,color.g,color.b,1.0f);
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::color3f32 color
                                           ){
    return this->writeStringColor((edk::char8*) str,x,y,width,height,color.r,color.g,color.b,1.0f);
}

bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::color3f32 color
                                           ){
    return this->writeStringColor(str,x,y,width,height,color.r,color.g,color.b,1.0f);
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::color3f32 color
                                           ){
    return this->writeStringColor((edk::char8*) str,
                                  position.x,
                                  position.y,
                                  width,height,
                                  color.r,
                                  color.g,
                                  color.b,
                                  1.0f
                                  );
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::color3f32 color
                                           ){
    return this->writeStringColor(str,position.x,position.y,width,height,color.r,color.g,color.b,1.0f);
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::size2ui32 size,
                                           edk::color3f32 color
                                           ){
    return this->writeStringColor((edk::char8*) str,x,y,size.width,size.height,color.r,color.g,color.b,1.0f);
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::size2ui32 size,
                                           edk::color3f32 color
                                           ){
    return this->writeStringColor(str,x,y,size.width,size.height,color.r,color.g,color.b,1.0f);
}
bool edk::fonts::FontMap::writeStringColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::size2ui32 size,
                                           edk::color3f32 color
                                           ){
    return this->writeStringColor((edk::char8*) str,position.x,
                                  position.y,
                                  size.width,
                                  size.height,
                                  color.r,
                                  color.g,
                                  color.b,
                                  1.0f
                                  );
}
bool edk::fonts::FontMap::writeStringColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::size2ui32 size,
                                           edk::color3f32 color
                                           ){
    return this->writeStringColor(str,position.x,position.y,size.width,size.height,color.r,color.g,color.b,1.0f);
}

bool edk::fonts::FontMap::writeSpaces(const edk::char8* str,edk::uint32 x,edk::uint8 y,edk::uint32 width){
    return this->writeSpaces((edk::char8*) str,x,y,width);
}
bool edk::fonts::FontMap::writeSpaces(edk::char8* str,edk::uint32 x,edk::uint8 y,edk::uint32 width){
    edk::uint32 lenght=x+width;
    if(lenght>=this->map.getMapSize().width){
        lenght = this->map.getMapSize().width;
        width = lenght-x;
    }
    if(str && width
            && x<this->map.getMapSize().width
            && y<this->map.getMapSize().height
            ){
        //
        edk::uint32 size=0u;
        edk::uint32 headX=x;
        edk::uint32 headY=y;
        edk::uint32 space;
        edk::uint8 jump=0u;
        edk::char8 temp[2u];
        bool haveInitialReturn=true;
        bool newLine=false;
        temp[0u]=' ';
        temp[1u]='\0';
        //prepare the space
        space = this->getTileID(temp,&jump);
        while(*str){
            size = this->wordSize(str);
            //test if the word fit inside the line
            if(size>=lenght-headX){
                newLine=true;
                //test if the headX is in the beggining
                if(headX==x){
                    size = width;
                }
                else{
                    //clean the last characters of the line
                    for(;headX<lenght;headX++){
                        this->map.setTile(space+1u,headX,headY);
                    }

                    //else it create a new line
                    headY++;
                    headX=x;
                    if(headY>=this->map.getMapSize().height){
                        break;
                    }
                    continue;
                }
            }
            //write the characters
            if(size){
                for(edk::uint32 i=0u;i<size;i++){
                    this->map.setTile(space+1u,headX,headY);
                    str+=jump;
                    headX++;
                }
            }
            else{
                if(*str=='\n' || *str==10){
                    if(headX == x && !haveInitialReturn){
                        //
                        str++;
                    }
                    else{
                        //clean the last characters of the line
                        for(;headX<lenght;headX++){
                            this->map.setTile(space+1u,headX,headY);
                        }

                        //create a new line
                        headY++;
                        headX=x;
                        str++;
                        if(headY>=this->map.getMapSize().height){
                            break;
                        }
                    }
                    haveInitialReturn=true;
                }
                else if(*str==' ' && newLine){
                    if(str[1u]!=' ' && str[1u]!=10 && str[1u]!='\n'){
                        str++;
                    }
                }
                else{
                    this->map.setTile(space+1u,headX,headY);
                    str+=jump;
                    headX++;
                }
            }
            newLine=false;
        }

        //test if reach the end of the limit
        if(headX<lenght){
            for(;headX<lenght;headX++){
                this->map.setTile(space+1u,headX,headY);
            }
            headX = x;
            headY++;
        }
        return true;
    }
    return false;
}
bool edk::fonts::FontMap::writeSpaces(const edk::char8* str,edk::vec2ui32 position,edk::uint32 width){
    return this->writeSpaces((edk::char8*) str,position.x,position.y,width);
}
bool edk::fonts::FontMap::writeSpaces(edk::char8* str,edk::vec2ui32 position,edk::uint32 width){
    return this->writeSpaces(str,position.x,position.y,width);
}
bool edk::fonts::FontMap::writeSpaces(const edk::char8* str,edk::uint32 x,
                                      edk::uint8 y,
                                      edk::uint32 width,
                                      edk::uint32 height
                                      ){
    return this->writeSpaces((edk::char8*) str,x,y,width,height);
}

bool edk::fonts::FontMap::writeSpaces(edk::char8* str,edk::uint32 x,edk::uint8 y,edk::uint32 width,edk::uint32 height){
    edk::uint32 lenght=x+width;
    if(lenght>=this->map.getMapSize().width){
        lenght = this->map.getMapSize().width;
        width = lenght-x;
    }
    edk::uint32 up=y+height;
    if(up>=this->map.getMapSize().height){
        up = this->map.getMapSize().height;
        height = up-y;
    }
    if(str && width && height
            && x<this->map.getMapSize().width
            && y<this->map.getMapSize().height
            ){
        //
        edk::uint32 size=0u;
        edk::uint32 headX=x;
        edk::uint32 headY=y;
        edk::uint32 space;
        edk::uint8 jump=0u;
        edk::char8 temp[2u];
        bool haveInitialReturn=true;
        bool newLine=false;
        temp[0u]=' ';
        temp[1u]='\0';
        //prepare the space
        space = this->getTileID(temp,&jump);
        while(*str){
            size = this->wordSize(str);
            //test if the word fit inside the line
            if(size>=lenght-headX){
                newLine=true;
                //test if the headX is in the beggining
                if(headX==x){
                    size = width;
                }
                else{
                    //clean the last characters of the line
                    for(;headX<lenght;headX++){
                        this->map.setTile(space+1u,headX,headY);
                    }

                    //else it create a new line
                    headY++;
                    headX=x;
                    if(headY>=up){
                        break;
                    }
                    continue;
                }
            }
            //write the characters
            if(size){
                for(edk::uint32 i=0u;i<size;i++){
                    this->map.setTile(space+1u,headX,headY);
                    str+=jump;
                    headX++;
                }
            }
            else{
                if(*str=='\n' || *str==10){
                    if(headX == x && !haveInitialReturn){
                        //
                        str++;
                    }
                    else{
                        //clean the last characters of the line
                        for(;headX<lenght;headX++){
                            this->map.setTile(space+1u,headX,headY);
                        }

                        //create a new line
                        headY++;
                        headX=x;
                        str++;
                        if(headY>=up){
                            break;
                        }
                    }
                    haveInitialReturn=true;
                }
                else if(*str==' ' && newLine){
                    haveInitialReturn=false;
                    if(str[1u]!=' ' && str[1u]!=10 && str[1u]!='\n'){
                        str++;
                    }
                }
                else{
                    haveInitialReturn=false;
                    this->map.setTile(space+1u,headX,headY);
                    str+=jump;
                    headX++;
                }
            }
            newLine=false;
        }

        //test if reach the end of the limit
        if(headX<lenght){
            if(headY<up){
                for(;headX<lenght;headX++){
                    this->map.setTile(space+1u,headX,headY);
                }
                headX = x;
                headY++;
            }
        }
        if(headY<up){
            for(;headY<up;headY++){
                for(headX=x;headX<lenght;headX++){
                    this->map.setTile(space+1u,headX,headY);
                }
            }
        }
        return true;
    }
    return false;
}
bool edk::fonts::FontMap::writeSpaces(const edk::char8* str,
                                      edk::vec2ui32 position,
                                      edk::uint32 width,
                                      edk::uint32 height
                                      ){
    return this->writeSpaces((edk::char8*) str,position.x,position.y,width,height);
}
bool edk::fonts::FontMap::writeSpaces(edk::char8* str,
                                      edk::vec2ui32 position,
                                      edk::uint32 width,
                                      edk::uint32 height
                                      ){
    return this->writeSpaces(str,position.x,position.y,width,height);
}
bool edk::fonts::FontMap::writeSpaces(const edk::char8* str,edk::uint32 x,edk::uint8 y,edk::size2ui32 size){
    return this->writeSpaces((edk::char8*) str,x,y,size.width,size.height);
}
bool edk::fonts::FontMap::writeSpaces(edk::char8* str,edk::uint32 x,edk::uint8 y,edk::size2ui32 size){
    return this->writeSpaces(str,x,y,size.width,size.height);
}
bool edk::fonts::FontMap::writeSpaces(const edk::char8* str,edk::vec2ui32 position,edk::size2ui32 size){
    return this->writeSpaces((edk::char8*) str,position.x,position.y,size.width,size.height);
}
bool edk::fonts::FontMap::writeSpaces(edk::char8* str,edk::vec2ui32 position,edk::size2ui32 size){
    return this->writeSpaces(str,position.x,position.y,size.width,size.height);
}

bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeSpacesColor((edk::char8*) str,x,y,width,r,g,b,a);
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    edk::uint32 lenght=x+width;
    if(lenght>=this->map.getMapSize().width){
        lenght = this->map.getMapSize().width;
        width = lenght-x;
    }
    if(str && width
            && x<this->map.getMapSize().width
            && y<this->map.getMapSize().height
            ){
        //
        edk::uint32 size=0u;
        edk::uint32 headX=x;
        edk::uint32 headY=y;
        edk::uint32 space;
        edk::uint8 jump=0u;
        edk::char8 temp[2u];
        bool haveInitialReturn=true;
        bool newLine=false;
        temp[0u]=' ';
        temp[1u]='\0';
        //prepare the space
        space = this->getTileID(temp,&jump);
        while(*str){
            size = this->wordSize(str);
            //test if the word fit inside the line
            if(size>=lenght-headX){
                newLine=true;
                //test if the headX is in the beggining
                if(headX==x){
                    size = width;
                }
                else{
                    //clean the last characters of the line
                    for(;headX<lenght;headX++){
                        this->map.setTile(space+1u,headX,headY);
                        this->map.setTileColor(r,g,b,a,headX,headY);
                    }

                    //else it create a new line
                    headY++;
                    headX=x;
                    if(headY>=this->map.getMapSize().height){
                        break;
                    }
                    continue;
                }
            }
            //write the characters
            if(size){
                haveInitialReturn=false;
                for(edk::uint32 i=0u;i<size;i++){
                    this->map.setTile(space+1u,headX,headY);
                    this->map.setTileColor(r,g,b,a,headX,headY);
                    str+=jump;
                    headX++;
                }
            }
            else{
                if(*str=='\n' || *str==10){
                    if(headX == x && !haveInitialReturn){
                        //
                        str++;
                    }
                    else{
                        //clean the last characters of the line
                        for(;headX<lenght;headX++){
                            this->map.setTile(space+1u,headX,headY);
                            this->map.setTileColor(r,g,b,a,headX,headY);
                        }

                        //create a new line
                        headY++;
                        headX=x;
                        str++;
                        if(headY>=this->map.getMapSize().height){
                            break;
                        }
                    }
                    haveInitialReturn=true;
                }
                else if(*str==' ' && newLine){
                    haveInitialReturn=false;
                    if(str[1u]!=' ' && str[1u]!=10 && str[1u]!='\n'){
                        str++;
                    }
                }
                else{
                    haveInitialReturn=false;
                    this->map.setTile(space+1u,headX,headY);
                    this->map.setTileColor(r,g,b,a,headX,headY);
                    str+=jump;
                    headX++;
                }
            }
            newLine=false;
        }

        //test if reach the end of the limit
        if(headX<lenght){
            for(;headX<lenght;headX++){
                this->map.setTile(space+1u,headX,headY);
                this->map.setTileColor(r,g,b,a,headX,headY);
            }
            headX = x;
            headY++;
        }
        return true;
    }
    return false;
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeSpacesColor((edk::char8*) str,position.x,position.y,width,r,g,b,a);
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeSpacesColor(str,position.x,position.y,width,r,g,b,a);
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeSpacesColor((edk::char8*) str,x,y,width,height,r,g,b,a);
}

bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    edk::uint32 lenght=x+width;
    if(lenght>=this->map.getMapSize().width){
        lenght = this->map.getMapSize().width;
        width = lenght-x;
    }
    edk::uint32 up=y+height;
    if(up>=this->map.getMapSize().height){
        up = this->map.getMapSize().height;
        height = up-y;
    }
    if(str && width && height
            && x<this->map.getMapSize().width
            && y<this->map.getMapSize().height
            ){
        //
        edk::uint32 size=0u;
        edk::uint32 headX=x;
        edk::uint32 headY=y;
        edk::uint32 space;
        edk::uint8 jump=0u;
        edk::char8 temp[2u];
        bool haveInitialReturn=true;
        bool newLine=false;
        temp[0u]=' ';
        temp[1u]='\0';
        //prepare the space
        space = this->getTileID(temp,&jump);
        while(*str){
            size = this->wordSize(str);
            //test if the word fit inside the line
            if(size>=lenght-headX){
                newLine=true;
                //test if the headX is in the beggining
                if(headX==x){
                    size = width;
                }
                else{
                    //clean the last characters of the line
                    for(;headX<lenght;headX++){
                        this->map.setTile(space+1u,headX,headY);
                        this->map.setTileColor(r,g,b,a,headX,headY);
                    }

                    //else it create a new line
                    headY++;
                    headX=x;
                    if(headY>=up){
                        break;
                    }
                    continue;
                }
            }
            //write the characters
            if(size){
                haveInitialReturn=false;
                for(edk::uint32 i=0u;i<size;i++){
                    this->map.setTile(space+1u,headX,headY);
                    this->map.setTileColor(r,g,b,a,headX,headY);
                    str+=jump;
                    headX++;
                }
            }
            else{
                if(*str=='\n' || *str==10){
                    if(headX == x && !haveInitialReturn){
                        //
                        str++;
                    }
                    else{
                        //clean the last characters of the line
                        for(;headX<lenght;headX++){
                            this->map.setTile(space+1u,headX,headY);
                            this->map.setTileColor(r,g,b,a,headX,headY);
                        }

                        //create a new line
                        headY++;
                        headX=x;
                        str++;
                        if(headY>=up){
                            break;
                        }
                    }
                    haveInitialReturn=true;
                }
                else if(*str==' ' && newLine){
                    if(str[1u]!=' ' && str[1u]!=10 && str[1u]!='\n'){
                        str++;
                    }
                }
                else{
                    haveInitialReturn=false;
                    this->map.setTile(space+1u,headX,headY);
                    this->map.setTileColor(r,g,b,a,headX,headY);
                    str+=jump;
                    headX++;
                }
            }
            newLine=false;
        }

        //test if reach the end of the limit
        if(headX<lenght){
            if(headY<up){
                for(;headX<lenght;headX++){
                    this->map.setTile(space+1u,headX,headY);
                    this->map.setTileColor(r,g,b,a,headX,headY);
                }
                headX = x;
                headY++;
            }
        }
        if(headY<up){
            for(;headY<up;headY++){
                for(headX=x;headX<lenght;headX++){
                    this->map.setTile(space+1u,headX,headY);
                    this->map.setTileColor(r,g,b,a,headX,headY);
                }
            }
        }
        return true;
    }
    return false;
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeSpacesColor((edk::char8*) str,position.x,position.y,width,height,r,g,b,a);
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeSpacesColor(str,position.x,position.y,width,height,r,g,b,a);
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::size2ui32 size,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeSpacesColor((edk::char8*) str,x,y,size.width,size.height,r,g,b,a);
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::size2ui32 size,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeSpacesColor(str,x,y,size.width,size.height,r,g,b,a);
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::size2ui32 size,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeSpacesColor((edk::char8*) str,position.x,position.y,size.width,size.height,r,g,b,a);
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::size2ui32 size,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b,
                                           edk::float32 a
                                           ){
    return this->writeSpacesColor(str,position.x,position.y,size.width,size.height,r,g,b,a);
}

bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeSpacesColor((edk::char8*) str,x,y,width,r,g,b,1.0f);
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeSpacesColor(str,x,y,width,r,g,b,1.f);
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeSpacesColor((edk::char8*) str,position.x,position.y,width,r,g,b,1.0f);
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeSpacesColor(str,position.x,position.y,width,r,g,b,1.0f);
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeSpacesColor((edk::char8*) str,x,y,width,height,r,g,b,1.0f);
}

bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeSpacesColor(str,x,y,width,height,r,g,b,1.f);
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeSpacesColor((edk::char8*) str,position.x,position.y,width,height,r,g,b,1.0f);
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeSpacesColor(str,position.x,position.y,width,height,r,g,b,1.0f);
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::size2ui32 size,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeSpacesColor((edk::char8*) str,x,y,size.width,size.height,r,g,b,1.0f);
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::size2ui32 size,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeSpacesColor(str,x,y,size.width,size.height,r,g,b,1.0f);
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::size2ui32 size,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeSpacesColor((edk::char8*) str,position.x,position.y,size.width,size.height,r,g,b,1.0f);
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::size2ui32 size,
                                           edk::float32 r,
                                           edk::float32 g,
                                           edk::float32 b
                                           ){
    return this->writeSpacesColor(str,position.x,position.y,size.width,size.height,r,g,b,1.0f);
}

bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::color4f32 color
                                           ){
    return this->writeSpacesColor((edk::char8*) str,x,y,width,color.r,color.g,color.b,color.a);
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::color4f32 color
                                           ){
    return this->writeSpacesColor(str,x,y,width,color.r,color.g,color.b,color.a);
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::color4f32 color
                                           ){
    return this->writeSpacesColor((edk::char8*) str,position.x,position.y,width,color.r,color.g,color.b,color.a);
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::color4f32 color
                                           ){
    return this->writeSpacesColor(str,position.x,position.y,width,color.r,color.g,color.b,color.a);
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::color4f32 color
                                           ){
    return this->writeSpacesColor((edk::char8*) str,x,y,width,height,color.r,color.g,color.b,color.a);
}

bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::color4f32 color
                                           ){
    return this->writeSpacesColor(str,x,y,width,height,color.r,color.g,color.b,color.a);
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::color4f32 color
                                           ){
    return this->writeSpacesColor((edk::char8*) str,
                                  position.x,
                                  position.y,
                                  width,height,
                                  color.r,
                                  color.g,
                                  color.b,
                                  color.a
                                  );
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::color4f32 color
                                           ){
    return this->writeSpacesColor(str,position.x,position.y,width,height,color.r,color.g,color.b,color.a);
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::size2ui32 size,
                                           edk::color4f32 color
                                           ){
    return this->writeSpacesColor((edk::char8*) str,x,y,size.width,size.height,color.r,color.g,color.b,color.a);
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::size2ui32 size,
                                           edk::color4f32 color
                                           ){
    return this->writeSpacesColor(str,x,y,size.width,size.height,color.r,color.g,color.b,color.a);
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::size2ui32 size,
                                           edk::color4f32 color
                                           ){
    return this->writeSpacesColor((edk::char8*) str,position.x,
                                  position.y,
                                  size.width,
                                  size.height,
                                  color.r,
                                  color.g,
                                  color.b,
                                  color.a
                                  );
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::size2ui32 size,
                                           edk::color4f32 color
                                           ){
    return this->writeSpacesColor(str,position.x,position.y,size.width,size.height,color.r,color.g,color.b,color.a);
}

bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::color3f32 color
                                           ){
    return this->writeSpacesColor((edk::char8*) str,x,y,width,color.r,color.g,color.b,1.0f);
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::color3f32 color
                                           ){
    return this->writeSpacesColor(str,x,y,width,color.r,color.g,color.b,1.0f);
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::color3f32 color
                                           ){
    return this->writeSpacesColor((edk::char8*) str,position.x,position.y,width,color.r,color.g,color.b,1.0f);
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::color3f32 color
                                           ){
    return this->writeSpacesColor(str,position.x,position.y,width,color.r,color.g,color.b,1.0f);
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::color3f32 color
                                           ){
    return this->writeSpacesColor((edk::char8*) str,x,y,width,height,color.r,color.g,color.b,1.0f);
}

bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::color3f32 color
                                           ){
    return this->writeSpacesColor(str,x,y,width,height,color.r,color.g,color.b,1.0f);
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::color3f32 color
                                           ){
    return this->writeSpacesColor((edk::char8*) str,
                                  position.x,
                                  position.y,
                                  width,height,
                                  color.r,
                                  color.g,
                                  color.b,
                                  1.0f
                                  );
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::uint32 width,
                                           edk::uint32 height,
                                           edk::color3f32 color
                                           ){
    return this->writeSpacesColor(str,position.x,position.y,width,height,color.r,color.g,color.b,1.0f);
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::size2ui32 size,
                                           edk::color3f32 color
                                           ){
    return this->writeSpacesColor((edk::char8*) str,x,y,size.width,size.height,color.r,color.g,color.b,1.0f);
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::uint32 x,
                                           edk::uint8 y,
                                           edk::size2ui32 size,
                                           edk::color3f32 color
                                           ){
    return this->writeSpacesColor(str,x,y,size.width,size.height,color.r,color.g,color.b,1.0f);
}
bool edk::fonts::FontMap::writeSpacesColor(const edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::size2ui32 size,
                                           edk::color3f32 color
                                           ){
    return this->writeSpacesColor((edk::char8*) str,position.x,
                                  position.y,
                                  size.width,
                                  size.height,
                                  color.r,
                                  color.g,
                                  color.b,
                                  1.0f
                                  );
}
bool edk::fonts::FontMap::writeSpacesColor(edk::char8* str,
                                           edk::vec2ui32 position,
                                           edk::size2ui32 size,
                                           edk::color3f32 color
                                           ){
    return this->writeSpacesColor(str,position.x,position.y,size.width,size.height,color.r,color.g,color.b,1.0f);
}

//set the color
void edk::fonts::FontMap::setColor(edk::color4f32 color){
    this->map.setColor(color);
}
void edk::fonts::FontMap::setColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->map.setColor(r,g,b,a);
}
void edk::fonts::FontMap::setAlpha(edk::float32 value){
    this->map.setAlpha(value);
}
void edk::fonts::FontMap::setColor(edk::color4ui8 color){
    this->setColor(edk::color4f32((edk::float32)color.r/255.f,
                                  (edk::float32)color.g/255.f,
                                  (edk::float32)color.b/255.f,
                                  (edk::float32)color.a/255.f
                                  )
                   );
}
void edk::fonts::FontMap::setColor(edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
    this->setColor(edk::color4ui8(r,g,b,a));
}
void edk::fonts::FontMap::setAlpha(edk::uint8 value){
    this->setAlpha((edk::float32)value/255.f);
}

//delete tileMap
void edk::fonts::FontMap::deleteMap(){
    //delete lines
    this->cleanLines();
    this->map.deleteTileMap();
}
//return true if have a text
bool edk::fonts::FontMap::haveText(){
    return this->map.haveTileMap();
}

//add callback
bool edk::fonts::FontMap::addCallback(edk::fonts::FontCallback* callback){
    return this->treeCallbacks.add(callback);
}

bool edk::fonts::FontMap::removeCallback(edk::fonts::FontCallback* callback){
    return this->treeCallbacks.remove(callback);
}

//cleanCallacks
void edk::fonts::FontMap::cleanCallbacks(){
    this->treeCallbacks.clean();
}

//Select characters to draw
void edk::fonts::FontMap::selectAll(){
    this->origin = edk::vec2ui32(0u,0u);
    this->last = edk::vec2ui32(this->map.getMapSize().width-1u,this->map.getMapSize().height-1u);
    this->originID = 0u;
    this->lastID = this->getCharacterID(this->last);
}

//set the origin and the last values
bool edk::fonts::FontMap::setOriginAndLast(edk::uint32 originID, edk::uint32 lastID){
    //test if have the ID
    if(this->haveID(originID) && this->haveID(lastID)){
        //test if the ID from origin is smaller than last
        if(originID<lastID){
            //add the interpolation
            this->originID = originID;
            this->lastID = lastID;
            this->origin = this->getCharacterPosition(this->originID);
            this->last = this->getCharacterPosition(this->lastID);
            return true;
        }
    }
    return false;
}
bool edk::fonts::FontMap::setOriginAndLast(edk::vec2ui32 origin, edk::vec2ui32 last){
    return this->setOriginAndLast(this->getCharacterID(origin),this->getCharacterID(last));
}
bool edk::fonts::FontMap::setOriginAndLast(edk::uint32 originX,edk::uint32 originY,edk::uint32 lastX,edk::uint32 lastY){
    return this->setOriginAndLast(edk::vec2ui32(originX,originY),edk::vec2ui32(lastX,lastY));
}
bool edk::fonts::FontMap::setOrigin(edk::uint32 originID){
    //test if have the ID
    if(this->haveID(originID)){
        //test if the ID from origin is smaller than last
        if(originID<this->lastID){
            //add the interpolation
            this->originID = originID;
            this->origin = this->getCharacterPosition(this->originID);
            return true;
        }
    }
    return false;
}
bool edk::fonts::FontMap::setOrigin(edk::vec2ui32 origin){
    return this->setOrigin(this->getCharacterID(origin));
}
bool edk::fonts::FontMap::setOrigin(edk::uint32 originX,edk::uint32 originY){
    return this->setOrigin(edk::vec2ui32(originX,originY));
}
bool edk::fonts::FontMap::setLast(edk::uint32 lastID){
    //test if have the ID
    if(this->haveID(lastID)){
        //test if the ID from origin is smaller than last
        if(lastID>this->originID){
            //add the interpolation
            this->lastID = lastID;
            this->last = this->getCharacterPosition(this->lastID);
            return true;
        }
    }
    return false;
}
bool edk::fonts::FontMap::setLast(edk::vec2ui32 last){
    return this->setLast(this->getCharacterID(last));
}
bool edk::fonts::FontMap::setLast(edk::uint32 lastX,edk::uint32 lastY){
    return this->setLast(edk::vec2ui32(lastX,lastY));
}

//add animations
bool edk::fonts::FontMap::addInterpolation(edk::float32 second,edk::uint32 originID,edk::uint32 lastID){
    //test if have the ID
    if(this->haveID(originID) && this->haveID(lastID)){
        //add the interpolation
        this->animOrigin.addNewInterpolationLine(second,(edk::float32)originID);
        this->animLast.addNewInterpolationLine(second,(edk::float32)lastID+1u);
        return true;
    }
    return false;
}
bool edk::fonts::FontMap::addInterpolation(edk::float32 second,edk::vec2ui32 origin,edk::vec2ui32 last){
    return this->addInterpolation(second,this->getCharacterID(origin),this->getCharacterID(last));
}
bool edk::fonts::FontMap::addInterpolation(edk::float32 second,edk::uint32 originX,edk::uint32 originY,edk::uint32 lastX,edk::uint32 lastY){
    return this->addInterpolation(second,edk::vec2ui32(originX,originY),edk::vec2ui32(lastX,lastY));
}

bool edk::fonts::FontMap::addInterpolationOrigin(edk::float32 second,edk::uint32 ID){
    //test if have the ID
    if(this->haveID(ID)){
        //add the interpolation
        this->animOrigin.addNewInterpolationLine(second,(edk::float32)ID);
        return true;
    }
    return false;
}
bool edk::fonts::FontMap::addInterpolationOrigin(edk::float32 second,edk::vec2ui32 origin){
    return this->addInterpolationOrigin(second,this->getCharacterID(origin));
}
bool edk::fonts::FontMap::addInterpolationOrigin(edk::float32 second,edk::uint32 originX,edk::uint32 originY){
    return this->addInterpolationOrigin(second,edk::vec2ui32(originX,originY));
}
bool edk::fonts::FontMap::addInterpolationLast(edk::float32 second,edk::uint32 ID){
    //test if have the ID
    if(this->haveID(ID)){
        //add the interpolation
        this->animLast.addNewInterpolationLine(second,(edk::float32)ID+1u);
        return true;
    }
    return false;
}
bool edk::fonts::FontMap::addInterpolationLast(edk::float32 second,edk::vec2ui32 last){
    return this->addInterpolationLast(second,this->getCharacterID(last));
}
bool edk::fonts::FontMap::addInterpolationLast(edk::float32 second,edk::uint32 lastX,edk::uint32 lastY){
    return this->addInterpolationLast(second,edk::vec2ui32(lastX,lastY));
}

//Set animation speed
void edk::fonts::FontMap::setAnimationSpeedOrigin(edk::float32 speed){
    this->speedOrigin = speed;
}
//set faster
void edk::fonts::FontMap::setAtimationFasterSpeedOrigin(edk::float32 faster){
    this->fasterOrigin = faster;
}
//speed
void edk::fonts::FontMap::setAnimationSpeedLast(edk::float32 speed){
    this->speedLast=speed;
}
//set faster
void edk::fonts::FontMap::setAtimationFasterSpeedLast(edk::float32 faster){
    this->fasterLast=faster;
}

//CONTROLS
//animation controllers
void edk::fonts::FontMap::playForward(){
    this->animOrigin.playForward();
    this->animLast.playForward();
}
void edk::fonts::FontMap::playForwardIn(edk::float32 second){
    this->animOrigin.playForwardIn(second);
    this->animLast.playForwardIn(second);
}
void edk::fonts::FontMap::playRewind(){
    this->animOrigin.playRewind();
    this->animLast.playRewind();
}
void edk::fonts::FontMap::playRewindIn(edk::float32 second){
    this->animOrigin.playRewindIn(second);
    this->animLast.playRewindIn(second);
}
void edk::fonts::FontMap::pause(){
    this->animLast.pause();
    this->animOrigin.pause();
}
void edk::fonts::FontMap::pauseOn(){
    this->animLast.pauseOn();
    this->animOrigin.pauseOn();
}
void edk::fonts::FontMap::pauseOff(){
    this->animLast.pauseOff();
    this->animOrigin.pauseOff();
}
void edk::fonts::FontMap::stop(){
    this->animOrigin.stop();
    this->animLast.stop();
}
//set loop
void edk::fonts::FontMap::setLoop(bool loop){
    this->animOrigin.setLoop(loop);
    this->animLast.setLoop(loop);
}
void edk::fonts::FontMap::loopOn(){
    this->animOrigin.loopOn();
    this->animLast.loopOn();
}
void edk::fonts::FontMap::loopOff(){
    this->animOrigin.loopOff();
    this->animLast.loopOff();
}

//Force speed for the next update
void edk::fonts::FontMap::forceSpeedInOrigin(edk::float32 speed){
    this->forceSpeedOrigin = true;
    this->forceSpeedOriginValue = speed;
}
void edk::fonts::FontMap::forceSpeedInLast(edk::float32 speed){
    this->forceSpeedLast = true;
    this->forceSpeedLastValue = speed;
}
//update animations
bool edk::fonts::FontMap::updateAnimations(){
    bool ret=false;
    edk::uint32 tileID;
    bool success = false;
    //test if is animating
    if(this->animOrigin.isPlaying()){

        //test if need force speed
        if(this->forceSpeedOrigin){
            this->forceSpeedOrigin = false;
            //set the update speed
            this->animOrigin.setSpeed(this->forceSpeedOriginValue);
        }

        this->animOrigin.updateClockAnimation();

        //get the value
        edk::float32 clockX = this->animLast.getClockX(&success);
        if(success){
            this->originID = (edk::uint32)clockX;
            //update the origin
            this->origin = this->getCharacterPosition(this->originID);

            tileID = this->map.getTileID(this->origin);
            if(tileID == 0u || tileID == ' '){
                //test if found enter
                if(tileID == 0u){
                    //found enter
                    if(!this->enterOrigin){
                        this->enterOrigin=true;
                        //Run found Enter
                        edk::uint32 size = this->treeCallbacks.size();
                        for(edk::uint32 i=0u;i<size;i++){
                            this->treeCallbacks.getElementInPosition(i)->originFoundEnd();
                        }
                    }
                }
                else{
                    this->enterOrigin=false;
                }
                //speed the animation
                this->animOrigin.setSpeed(this->fasterOrigin);//faster
            }
            else{
                this->animOrigin.setSpeed(this->speedOrigin);//normal
                this->enterOrigin=false;
            }

            ret=true;
        }
    }
    if(this->animLast.isPlaying()){

        //test if need force speed
        if(this->forceSpeedLast){
            this->forceSpeedLast = false;
            //set the update speed
            this->animLast.setSpeed(this->forceSpeedLastValue);
        }

        //test the character
        this->animLast.updateClockAnimation();
        //get the value
        edk::float32 clockX = this->animLast.getClockX(&success);
        if(success){
            this->lastID = (edk::uint32)clockX;
            //update last
            this->last = this->getCharacterPosition(this->lastID);

            //update the last speed
            tileID = this->map.getTileID(this->last);
            if(tileID == 0u || tileID == ' '){
                //test if found enter
                if(tileID == 0u){
                    //found enter
                    if(!this->enterOrigin){
                        this->enterOrigin=true;
                        //Run found Enter
                        edk::uint32 size = this->treeCallbacks.size();
                        for(edk::uint32 i=0u;i<size;i++){
                            this->treeCallbacks.getElementInPosition(i)->lastFoundEnd();
                        }
                    }
                }
                else{
                    this->enterOrigin=false;
                }
                //speed the animation
                this->animLast.setSpeed(this->fasterLast);//faster
            }
            else{
                this->animLast.setSpeed(this->speedLast);//normal
                this->enterOrigin=false;
            }

            ret=true;
        }
    }

    //update the position
    if(this->animationPosition.isPlaying()){
        this->animationPosition.updateClockAnimation();
        edk::vec2f32 posTemp;
        posTemp.x = this->animationPosition.getClockX(&success);
        if(success){
            posTemp.y = this->animationPosition.getClockY(&success);
            if(success){
                this->setPosition(posTemp);
            }
        }
    }

    //update the position
    if(this->animationSize.isPlaying()){
        this->animationSize.updateClockAnimation();
        edk::size2f32 sizeTemp;
        sizeTemp.width = this->animationSize.getClockX(&success);
        if(success){
            sizeTemp.height = this->animationSize.getClockY(&success);
            if(success){
                this->setScale(sizeTemp);
            }
        }
    }

    return ret;
}
bool edk::fonts::FontMap::updateAnimations(edk::float32 seconds){
    bool ret=false;
    edk::uint32 tileID;
    bool success = false;
    //test if is animating
    if(this->animOrigin.isPlaying()){

        //test if need force speed
        if(this->forceSpeedOrigin){
            this->forceSpeedOrigin = false;
            //set the update speed
            this->animOrigin.setSpeed(this->forceSpeedOriginValue);
        }

        this->animOrigin.updateClockAnimation(seconds);

        //get the value
        edk::float32 clockX = this->animLast.getClockX(&success);
        if(success){
            this->originID = (edk::uint32)clockX;
            //update the origin
            this->origin = this->getCharacterPosition(this->originID);

            tileID = this->map.getTileID(this->origin);
            if(tileID == 0u || tileID == ' '){
                //test if found enter
                if(tileID == 0u){
                    //found enter
                    if(!this->enterOrigin){
                        this->enterOrigin=true;
                        //Run found Enter
                        edk::uint32 size = this->treeCallbacks.size();
                        for(edk::uint32 i=0u;i<size;i++){
                            this->treeCallbacks.getElementInPosition(i)->originFoundEnd();
                        }
                    }
                }
                else{
                    this->enterOrigin=false;
                }
                //speed the animation
                this->animOrigin.setSpeed(this->fasterOrigin);//faster
            }
            else{
                this->animOrigin.setSpeed(this->speedOrigin);//normal
                this->enterOrigin=false;
            }

            ret=true;
        }
    }
    if(this->animLast.isPlaying()){

        //test if need force speed
        if(this->forceSpeedLast){
            this->forceSpeedLast = false;
            //set the update speed
            this->animLast.setSpeed(this->forceSpeedLastValue);
        }

        //test the character
        this->animLast.updateClockAnimation(seconds);
        //get the value
        edk::float32 clockX = this->animLast.getClockX(&success);
        if(success){
            this->lastID = (edk::uint32)clockX;
            //update last
            this->last = this->getCharacterPosition(this->lastID);

            //update the last speed
            tileID = this->map.getTileID(this->last);
            if(tileID == 0u || tileID == ' '){
                //test if found enter
                if(tileID == 0u){
                    //found enter
                    if(!this->enterOrigin){
                        this->enterOrigin=true;
                        //Run found Enter
                        edk::uint32 size = this->treeCallbacks.size();
                        for(edk::uint32 i=0u;i<size;i++){
                            this->treeCallbacks.getElementInPosition(i)->lastFoundEnd();
                        }
                    }
                }
                else{
                    this->enterOrigin=false;
                }
                //speed the animation
                this->animLast.setSpeed(this->fasterLast);//faster
            }
            else{
                this->animLast.setSpeed(this->speedLast);//normal
                this->enterOrigin=false;
            }

            ret=true;
        }
    }

    //update the position
    if(this->animationPosition.isPlaying()){
        this->animationPosition.updateClockAnimation(seconds);
        edk::vec2f32 posTemp;
        posTemp.x = this->animationPosition.getClockX(&success);
        if(success){
            posTemp.y = this->animationPosition.getClockY(&success);
            if(success){
                this->setPosition(posTemp);
            }
        }
    }

    //update the position
    if(this->animationSize.isPlaying()){
        this->animationSize.updateClockAnimation(seconds);
        edk::size2f32 sizeTemp;
        sizeTemp.width = this->animationSize.getClockX(&success);
        if(success){
            sizeTemp.height = this->animationSize.getClockY(&success);
            if(success){
                this->setScale(sizeTemp);
            }
        }
    }

    return ret;
}

//draw the text
void edk::fonts::FontMap::draw(edk::color4f32 color){
    this->draw(this->origin,this->last,color);
}
void edk::fonts::FontMap::draw(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->draw(this->origin,this->last,edk::color4f32(r,g,b,a));
}
void edk::fonts::FontMap::draw(edk::float32 r,edk::float32 g,edk::float32 b){
    this->draw(r,g,b,1.f);
}
void edk::fonts::FontMap::draw(){
    this->draw(this->origin,this->last);
}
void edk::fonts::FontMap::drawWithoutMaterial(edk::color4f32 color){
    //this->map.draw(color);
    this->drawWithoutMaterial(this->origin,this->last,color);
}
void edk::fonts::FontMap::drawWithoutMaterial(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->drawWithoutMaterial(this->origin,this->last,edk::color4f32(r,g,b,a));
}
void edk::fonts::FontMap::drawWithoutMaterial(edk::float32 r,edk::float32 g,edk::float32 b){
    this->drawWithoutMaterial(r,g,b,1.f);
}
void edk::fonts::FontMap::drawWithoutMaterial(){
    this->drawWithoutMaterial(this->origin,this->last);
}
void edk::fonts::FontMap::drawWire(edk::color4f32 color){
    this->drawWire(this->origin,this->last,color);
}
void edk::fonts::FontMap::drawWire(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->drawWire(this->origin,this->last,edk::color4f32(r,g,b,a));
}
void edk::fonts::FontMap::drawWire(edk::float32 r,edk::float32 g,edk::float32 b){
    this->drawWire(r,g,b,1.f);
}
void edk::fonts::FontMap::drawWire(){
    this->drawWire(this->origin,this->last);
}
void edk::fonts::FontMap::drawSelection(){
    this->drawSelection(this->origin,this->last);
}
//draw the pivo
void edk::fonts::FontMap::drawPivo(edk::float32 size,edk::color3f32 color){
    this->map.drawPivo(size,color);
}

//remove the fontImage
void edk::fonts::FontMap::removeFontImage(){
    //remove the tileSet from map
    this->map.removeTileSet();
    this->list.removeFontSet(this->set);
    this->set=NULL;
}

void edk::fonts::FontMap::animationEnd(edk::animation::InterpolationGroup* animation){
    //run the animation callback
    edk::uint32 size = this->treeCallbacks.size();
    bool isOrigin=false;
    if(animation == &this->animOrigin) isOrigin=true;
    for(edk::uint32 i=0u;i<size;i++){
        this->treeCallbacks.getElementInPosition(i)->animationEnd(this,isOrigin);
    }
}
