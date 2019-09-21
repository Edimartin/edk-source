#include "FontMap.h"



edk::uint32 EDKFontTemplateSize = 4472u;
edk::char8 EDKFontTemplateName[20] = "EDKFontTemplate.png";
edk::uchar8 EDKFontTemplate[4472u] = {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,144,0,0 \
    ,1,0,8,6,0,0,0,92,87,255,79,0,0,0,6,98,75,71,68,0,111 \
    ,0,111,0,111,124,167,171,55,0,0,0,9,112,72,89,115,0,0,11,19,0 \
    ,0,11,19,1,0,154,156,24,0,0,0,7,116,73,77,69,7,227,9,21,18 \
    ,22,4,50,132,0,128,0,0,0,29,105,84,88,116,67,111,109,109,101,110,116 \
    ,0,0,0,0,0,67,114,101,97,116,101,100,32,119,105,116,104,32,71,73,77 \
    ,80,100,46,101,7,0,0,16,220,73,68,65,84,120,218,237,93,237,114,29,33 \
    ,8,77,156,125,223,123,31,37,111,156,254,74,103,179,81,60,124,168,184,123,152 \
    ,233,180,77,92,69,68,4,68,248,124,189,94,31,4,25,190,190,190,190,165,223 \
    ,191,223,239,207,153,253,100,130,66,246,32,120,224,136,216,137,231,157,131,180,33 \
    ,216,232,125,165,97,239,247,200,122,72,82,17,89,179,67,51,153,86,135,63,191 \
    ,147,144,145,190,143,34,180,212,63,210,38,27,72,52,189,206,231,235,235,235,91 \
    ,162,113,143,97,16,33,80,163,97,241,236,10,4,153,214,174,248,249,246,252,111 \
    ,139,222,128,224,131,180,201,44,129,34,152,30,161,115,175,141,40,129,106,28,93 \
    ,67,190,199,28,189,5,107,253,174,182,123,206,76,102,37,98,141,32,51,164,161 \
    ,68,163,222,81,52,66,98,246,250,105,73,160,22,30,63,63,47,53,17,151,65 \
    ,220,75,140,87,195,179,134,191,86,178,33,59,240,60,150,180,232,173,35,3,161 \
    ,51,178,128,51,143,209,235,81,250,179,1,223,239,247,231,161,61,243,162,118,152 \
    ,69,89,159,37,57,90,227,92,165,111,13,79,164,141,52,22,170,219,252,244,125 \
    ,238,107,4,109,106,253,159,199,45,210,174,170,253,220,123,132,121,196,173,150,64 \
    ,82,251,59,88,133,200,90,68,73,160,150,212,63,44,90,61,130,172,164,96,247 \
    ,118,110,173,157,196,200,146,152,239,233,116,181,241,122,214,38,42,37,17,26,68 \
    ,233,118,200,105,225,237,183,246,239,3,89,160,209,230,105,111,81,103,73,11,207 \
    ,198,64,143,149,179,254,16,33,165,17,61,202,106,225,34,167,193,97,93,244,90 \
    ,103,72,27,45,115,244,126,143,232,46,72,155,157,152,112,4,78,214,111,62,121 \
    ,23,102,87,234,181,196,206,118,23,22,97,225,29,100,143,231,66,4,195,242,50 \
    ,149,64,6,34,172,3,234,64,4,23,28,94,203,100,166,153,141,40,165,12,27 \
    ,89,192,64,86,70,64,238,154,36,179,90,242,101,32,166,110,237,155,136,139,87 \
    ,111,88,200,142,161,35,33,58,144,198,161,133,94,84,122,188,161,146,171,190,230 \
    ,237,149,46,58,53,243,185,91,88,200,84,37,218,235,193,236,93,30,142,48,67 \
    ,45,113,44,90,156,103,206,43,139,58,112,166,109,237,79,211,10,243,4,120,93 \
    ,165,128,71,42,104,37,149,117,65,17,156,163,231,133,6,120,205,100,30,203,120 \
    ,5,157,192,204,9,33,12,113,101,30,47,19,205,6,9,95,228,82,119,246,90 \
    ,180,126,126,160,31,206,94,160,221,24,194,123,76,212,230,139,196,94,69,227,164 \
    ,53,66,14,13,215,93,45,32,20,161,17,147,63,95,58,74,86,25,178,65,102 \
    ,226,140,24,11,217,172,56,41,122,162,88,252,40,218,64,173,81,250,4,26,235 \
    ,99,153,143,165,47,205,177,175,137,97,234,141,103,13,136,71,172,77,149,4,210 \
    ,16,173,23,186,225,245,3,89,45,49,15,19,69,48,34,122,236,120,194,88,86 \
    ,72,166,86,248,205,225,65,74,19,255,51,218,2,187,30,105,94,61,32,130,38 \
    ,217,29,137,17,33,194,91,223,133,241,42,99,61,240,50,149,224,2,134,115,16 \
    ,200,64,4,50,16,108,26,19,110,206,64,43,175,64,200,168,243,225,176,18,123 \
    ,180,197,227,117,177,183,250,138,202,116,209,234,235,73,177,64,38,9,20,17,19 \
    ,211,75,239,114,125,62,235,185,23,139,186,177,71,25,228,142,119,120,83,143,176 \
    ,168,107,129,94,31,173,35,39,42,128,205,211,238,9,76,36,198,3,69,46,54 \
    ,146,186,4,37,182,230,149,106,107,49,209,36,18,179,116,173,222,125,89,70,38 \
    ,60,227,84,34,153,195,243,125,237,223,210,69,97,235,125,185,196,176,181,103,195 \
    ,179,33,91,30,38,175,180,78,251,50,181,117,100,105,20,215,107,54,137,213,11 \
    ,166,201,119,232,85,204,189,201,51,209,35,124,251,167,205,26,189,100,245,113,208 \
    ,203,90,166,57,118,189,199,125,20,157,139,149,16,209,175,31,44,214,221,238,71 \
    ,64,132,178,61,227,72,150,232,92,102,35,141,232,64,8,81,165,119,97,179,37 \
    ,136,134,224,154,96,186,149,202,61,186,73,83,94,101,212,148,104,73,212,163,253 \
    ,68,236,120,36,67,217,110,82,209,115,28,166,15,231,120,154,103,119,55,218,48 \
    ,63,208,77,37,195,44,96,64,25,193,5,140,7,34,144,129,8,100,32,194,166 \
    ,112,212,180,250,158,130,134,196,195,72,202,158,246,53,133,231,213,105,111,94,214 \
    ,215,171,17,243,218,205,218,171,205,235,191,18,221,202,72,46,117,134,60,213,213 \
    ,36,147,210,140,23,21,130,17,133,179,118,94,89,76,122,47,125,74,173,81,239 \
    ,82,79,218,177,136,115,47,42,175,114,4,81,103,122,123,175,184,161,79,151,71 \
    ,49,143,180,214,67,252,64,218,193,60,19,171,73,68,130,95,157,168,181,149,94 \
    ,245,246,78,153,163,54,232,232,184,225,218,228,172,162,223,82,55,84,171,111,181 \
    ,226,136,144,54,168,158,102,105,131,134,215,162,248,244,158,134,79,11,231,64,143 \
    ,142,171,168,238,41,165,231,54,82,41,205,94,101,31,79,92,145,212,143,183,78 \
    ,218,12,157,199,203,68,221,35,204,139,80,196,196,144,5,220,97,65,70,130,70 \
    ,98,160,107,108,161,193,241,228,69,200,170,187,104,142,40,111,93,55,235,169,241 \
    ,203,145,120,85,142,71,86,11,142,138,217,201,254,16,112,214,102,138,10,74,67 \
    ,117,174,235,56,191,46,83,123,142,196,168,34,246,26,135,27,162,108,71,56,247 \
    ,180,74,63,50,150,55,139,171,166,143,81,126,160,94,91,222,198,19,92,192,187 \
    ,48,2,25,136,64,6,34,144,129,8,100,32,2,65,9,230,252,64,158,203,187 \
    ,81,230,185,213,173,128,226,163,125,139,111,113,79,212,92,41,189,167,207,168,91 \
    ,194,26,130,34,173,71,57,55,66,178,158,75,149,93,90,15,230,122,249,127,90 \
    ,132,67,137,214,10,201,64,31,240,69,190,22,69,147,79,160,15,44,61,99,244 \
    ,214,11,217,140,189,92,77,5,105,212,227,96,173,244,210,18,1,29,207,114,195 \
    ,109,193,103,55,240,214,128,11,209,129,70,151,87,154,113,137,171,241,186,102,97 \
    ,162,21,81,141,46,29,40,138,33,162,243,18,174,218,97,35,104,51,147,121,206 \
    ,53,46,144,218,38,195,149,104,109,192,148,183,8,138,134,72,222,54,104,218,149 \
    ,21,204,52,90,186,91,153,200,148,161,108,85,28,113,180,254,211,154,219,72,137 \
    ,162,89,164,85,69,254,194,24,104,38,147,140,56,58,239,0,26,38,90,49,247 \
    ,50,91,194,32,165,29,173,186,128,133,128,119,201,168,186,10,255,227,124,254,121 \
    ,227,89,90,76,33,189,2,232,233,23,136,195,14,173,243,142,68,246,121,149,74 \
    ,105,204,222,188,45,146,102,52,227,244,120,131,241,64,132,216,35,140,64,32,3 \
    ,17,200,64,4,50,16,225,1,86,28,25,136,0,221,216,183,224,243,245,122,193 \
    ,113,60,189,16,142,168,126,144,190,102,166,101,209,198,205,160,113,60,154,249,71 \
    ,36,118,151,198,177,150,43,47,215,15,90,225,28,72,200,71,84,63,119,7,141 \
    ,179,182,214,78,123,29,130,62,101,182,172,69,201,78,104,239,14,140,196,35,226 \
    ,229,110,212,60,34,54,92,141,185,180,183,16,101,245,98,72,19,25,69,252,85 \
    ,11,23,157,52,34,131,212,46,53,164,34,226,80,144,18,5,217,222,183,107,116 \
    ,20,137,193,17,26,70,73,177,213,244,27,118,153,170,9,157,184,147,254,131,28 \
    ,187,209,41,112,86,210,175,204,32,166,247,5,69,70,233,228,189,108,141,174,35 \
    ,187,138,126,37,130,152,214,163,45,147,242,139,250,66,70,100,220,136,210,171,82 \
    ,196,3,237,164,192,89,152,72,155,64,41,202,220,29,109,77,45,61,194,144,248 \
    ,18,228,125,150,166,242,114,175,22,88,15,47,77,63,82,94,197,136,4,149,40 \
    ,206,87,41,140,198,254,120,42,90,143,150,248,230,120,32,166,179,35,124,124,4 \
    ,228,72,28,253,226,130,144,215,181,225,146,64,4,194,112,51,158,64,6,34,16 \
    ,112,6,202,158,58,151,144,15,254,232,64,17,5,82,34,173,179,168,62,61,253 \
    ,104,191,245,164,206,213,140,53,51,255,0,124,132,121,156,100,35,38,49,162,240 \
    ,139,118,110,51,23,71,91,32,37,165,25,127,103,179,124,70,249,168,221,152,32 \
    ,156,129,80,159,192,200,178,152,136,164,176,150,152,236,149,196,244,132,98,140,56 \
    ,130,44,106,5,50,167,214,75,92,77,8,114,209,238,44,52,12,3,77,111,135 \
    ,102,67,147,136,138,244,211,194,247,218,15,50,174,52,255,104,233,19,21,155,37 \
    ,49,237,207,156,44,33,200,69,139,136,165,168,154,182,84,166,86,9,149,112,138 \
    ,14,139,93,145,177,36,34,110,104,20,222,135,117,50,89,204,125,94,163,36,242 \
    ,3,17,242,41,252,153,54,107,90,6,122,74,13,177,59,50,81,177,76,164,167 \
    ,72,94,23,179,149,247,25,109,211,75,194,45,197,3,245,148,104,36,192,95,179 \
    ,120,222,220,61,35,198,138,208,161,90,116,230,109,252,0,197,213,162,75,238,170 \
    ,203,21,50,12,239,255,60,64,9,244,17,91,170,50,227,120,100,32,2,143,48 \
    ,194,61,225,32,9,120,124,159,143,82,173,82,159,254,8,123,122,208,62,90,138 \
    ,221,114,177,139,94,166,110,203,64,79,127,58,20,85,129,104,36,29,169,3,17 \
    ,204,214,227,127,29,200,18,23,82,59,47,35,226,75,106,191,159,153,134,110,70 \
    ,155,26,100,151,178,231,220,1,103,92,203,117,130,104,92,72,239,10,162,69,56 \
    ,52,85,30,90,174,114,6,68,102,40,107,205,239,186,88,35,178,120,88,157,166 \
    ,210,122,150,209,68,239,45,70,6,6,145,36,99,111,115,88,25,167,247,150,127 \
    ,68,2,7,11,157,123,137,37,202,140,221,187,75,134,50,26,7,27,41,209,79 \
    ,205,208,122,55,203,178,172,32,160,84,27,29,253,46,90,119,233,37,152,26,85 \
    ,177,122,23,41,220,10,29,254,239,7,178,38,255,150,172,167,94,64,188,182,173 \
    ,245,53,133,197,161,166,181,230,36,166,242,88,97,35,29,137,17,240,135,129,208 \
    ,129,152,31,136,52,90,170,3,145,121,238,1,213,90,25,218,218,164,148,66,254 \
    ,55,98,91,51,16,129,192,35,108,161,164,177,90,161,25,44,48,47,62,203,37 \
    ,80,134,20,37,179,113,205,54,103,15,62,191,24,104,85,108,176,181,86,85,180 \
    ,82,139,152,196,94,92,51,233,74,17,151,187,165,70,160,21,30,226,44,247,97 \
    ,8,99,89,233,147,181,86,154,167,62,202,209,218,121,51,242,232,100,213,107,90 \
    ,12,35,237,208,154,167,122,228,134,136,10,13,241,226,120,104,58,223,241,81,28 \
    ,18,91,20,61,31,201,35,125,125,109,139,184,76,172,204,218,91,47,180,126,153 \
    ,212,207,231,247,247,183,138,147,35,244,36,180,182,106,38,29,72,59,22,50,14 \
    ,130,79,107,13,174,87,40,232,181,145,181,4,85,171,159,95,142,68,116,210,81 \
    ,139,63,83,130,205,98,32,79,130,77,148,121,174,223,212,22,87,179,94,218,108 \
    ,114,191,172,176,21,18,232,174,12,228,73,69,167,101,162,40,9,132,226,220,234 \
    ,167,212,66,71,175,97,171,22,75,205,235,36,187,126,63,210,233,22,57,86,143 \
    ,65,181,21,151,61,25,67,122,235,133,214,47,147,250,57,90,202,29,226,175,88 \
    ,169,60,183,252,50,22,41,16,161,68,183,22,38,34,126,90,82,198,37,189,202 \
    ,178,94,218,117,63,36,164,120,73,26,39,125,90,52,182,210,57,114,109,60,146 \
    ,125,200,85,134,215,163,123,183,28,58,119,134,37,119,97,148,114,100,32,2,225 \
    ,227,227,131,225,28,4,50,16,97,75,6,210,248,33,164,223,121,219,204,212,219 \
    ,178,5,131,81,2,109,2,145,86,225,221,34,18,153,161,12,128,200,122,27,87 \
    ,95,208,106,43,212,139,15,25,104,49,67,238,142,79,243,97,33,157,119,62,157 \
    ,176,117,217,169,169,149,102,137,142,208,228,48,66,131,210,196,120,160,149,49,209 \
    ,119,100,34,233,110,14,125,34,221,99,34,41,160,172,118,83,111,101,48,100,131 \
    ,84,31,22,102,23,185,61,130,102,96,160,218,223,22,92,91,12,17,25,15,36 \
    ,225,213,235,231,144,68,26,37,80,188,110,161,81,90,107,18,168,197,28,82,14 \
    ,38,228,184,148,240,237,74,32,234,64,249,36,39,18,36,230,141,137,70,215,25 \
    ,214,129,8,243,25,198,186,81,35,94,101,68,224,115,123,6,242,228,236,25,33 \
    ,129,239,246,176,144,18,136,224,2,94,101,16,200,64,4,50,16,129,12,148,91 \
    ,145,102,232,197,24,56,172,11,162,245,29,72,22,64,6,15,114,22,203,232,17 \
    ,12,20,181,96,181,247,104,94,38,142,200,54,219,194,233,137,158,250,158,169,31 \
    ,110,198,107,242,77,123,83,161,160,222,115,84,26,142,200,202,177,83,214,53,11 \
    ,206,38,6,66,22,234,235,235,235,231,199,97,222,87,132,0,218,187,158,168,35 \
    ,21,125,199,158,141,121,188,56,151,150,162,25,165,120,94,51,95,181,158,227,182 \
    ,20,223,94,184,101,68,180,96,68,25,131,22,222,222,54,51,140,0,79,255,211 \
    ,159,54,35,239,197,107,58,82,75,138,121,165,72,45,233,146,85,47,67,199,238 \
    ,101,214,64,99,136,44,99,247,214,197,20,210,138,22,24,89,9,210,3,255,221 \
    ,34,7,106,217,47,164,170,143,72,146,132,222,134,26,37,20,134,199,3,141,90 \
    ,220,40,9,116,149,56,179,152,81,162,249,21,31,171,52,212,230,41,178,140,17 \
    ,154,165,245,242,221,119,77,129,142,92,128,86,105,76,237,120,35,114,36,122,116 \
    ,150,86,168,234,104,134,182,140,113,32,71,68,228,98,72,146,195,146,47,112,132 \
    ,68,24,169,255,32,199,88,148,113,160,197,217,50,78,168,25,175,49,245,81,95 \
    ,17,162,120,123,252,60,163,131,188,232,7,186,1,104,51,144,238,164,144,175,6 \
    ,62,44,36,179,184,128,225,28,4,50,16,97,29,48,38,154,16,167,3,69,92 \
    ,99,32,125,104,28,150,59,122,153,71,94,218,122,173,224,104,92,74,107,192,136 \
    ,186,232,189,59,27,52,59,186,55,27,126,235,207,12,147,184,198,92,173,68,238 \
    ,43,45,83,43,46,161,58,208,149,48,173,133,71,144,142,172,91,81,27,123,148 \
    ,119,60,131,187,2,101,28,203,101,109,147,129,162,220,249,154,239,165,54,153,11 \
    ,208,101,61,58,181,109,188,204,243,71,7,242,132,129,182,196,226,168,32,171,187 \
    ,190,229,183,148,73,240,190,111,239,233,67,210,183,71,150,221,48,2,102,234,25 \
    ,72,17,147,43,62,189,236,29,173,219,120,228,218,197,90,206,9,173,205,241,39 \
    ,59,135,135,49,86,236,122,139,4,170,229,235,201,106,241,89,74,66,140,176,216 \
    ,160,252,64,90,37,241,174,169,95,178,204,39,170,158,72,196,209,214,139,21,163 \
    ,39,122,67,29,8,49,193,107,109,90,37,162,144,218,111,87,195,230,87,189,176 \
    ,93,119,234,29,1,141,3,186,26,42,146,203,66,122,135,167,233,167,246,255,195 \
    ,178,59,50,49,212,19,51,169,93,25,3,125,173,210,59,158,92,17,137,187,74 \
    ,158,217,56,101,125,104,128,120,193,37,43,203,106,29,83,7,122,144,94,117,214 \
    ,133,162,250,102,64,217,3,44,72,75,253,88,20,24,206,65,125,203,5,197,42 \
    ,218,144,167,185,189,111,35,158,238,142,188,93,247,48,143,135,62,17,253,207,194 \
    ,167,121,153,234,33,166,100,18,162,14,176,218,197,95,239,50,112,36,19,205,164 \
    ,15,50,247,44,248,108,127,132,69,189,229,103,150,126,27,252,97,32,228,166,124 \
    ,183,54,104,174,104,79,85,155,153,109,52,76,63,186,77,169,53,154,81,170,114 \
    ,86,155,171,132,66,46,36,37,207,107,43,78,105,102,155,86,219,21,109,84,33 \
    ,173,187,181,209,100,183,208,154,179,17,125,68,182,89,106,133,33,55,176,59,182 \
    ,145,196,126,132,190,52,50,140,98,23,215,193,163,60,209,17,86,90,84,176,92 \
    ,150,160,59,47,28,153,137,19,209,166,149,164,1,233,87,138,206,235,29,57,179 \
    ,218,164,146,64,72,126,157,221,218,212,114,8,245,244,39,180,130,79,22,235,140 \
    ,71,216,226,163,236,26,116,133,232,28,60,202,42,71,216,147,117,32,196,218,67 \
    ,221,5,163,219,180,218,246,252,55,35,218,240,50,117,67,203,135,18,104,3,201 \
    ,68,230,193,128,18,136,64,37,154,176,9,3,33,113,60,187,198,21,69,29,133 \
    ,25,98,116,34,112,11,103,32,244,37,232,142,113,69,81,144,45,102,104,134,81 \
    ,240,249,122,189,168,68,26,149,237,59,208,200,203,92,255,149,104,180,192,7,250 \
    ,51,137,208,217,218,68,72,96,132,62,171,219,72,237,172,244,41,90,81,140,38 \
    ,133,106,149,76,200,214,198,187,75,239,82,139,213,74,159,18,33,202,233,55,202 \
    ,201,16,210,134,242,40,224,231,255,151,214,32,79,99,34,77,33,188,157,164,202 \
    ,117,193,209,64,185,90,172,121,173,159,98,69,234,110,128,148,86,202,84,105,218 \
    ,178,94,86,221,79,178,4,139,101,144,59,50,209,57,131,42,26,206,241,4,144 \
    ,98,183,223,239,247,103,137,224,236,187,16,10,153,219,221,153,167,103,225,65,249 \
    ,129,120,27,93,63,222,158,74,35,233,81,2,236,72,124,186,31,168,214,215,14 \
    ,243,138,192,89,2,222,198,63,28,194,60,209,4,130,5,24,206,65,32,3,17 \
    ,200,64,132,221,25,72,19,39,131,180,157,89,98,96,86,130,169,76,244,201,130 \
    ,143,58,193,148,230,61,183,20,224,36,69,18,246,254,223,194,37,67,130,41,47 \
    ,125,208,185,103,193,167,154,31,168,231,83,64,147,1,244,124,71,179,42,36,206 \
    ,50,123,35,232,179,27,62,52,227,27,34,156,94,120,37,3,101,200,118,53,178 \
    ,141,36,241,52,17,127,210,120,43,189,204,158,8,2,79,155,170,4,202,150,255 \
    ,38,178,100,81,77,84,35,1,238,30,166,139,110,147,137,198,135,70,11,223,177 \
    ,77,77,250,68,29,115,25,230,182,26,14,212,154,217,177,77,237,231,158,221,200 \
    ,180,118,15,115,36,182,18,104,74,111,217,24,202,66,6,50,29,13,218,42,209 \
    ,168,115,110,86,155,84,86,24,82,79,124,247,54,86,165,57,171,21,182,170,13 \
    ,253,64,244,3,197,72,32,2,129,58,16,129,12,68,216,11,14,141,66,74,32 \
    ,84,37,144,214,181,31,101,114,102,138,43,138,82,196,51,206,29,197,235,28,102 \
    ,131,142,253,75,137,238,153,184,168,148,138,190,123,177,226,19,185,49,180,214,220 \
    ,200,185,107,230,165,153,179,43,156,35,58,142,103,183,184,162,72,102,201,18,51 \
    ,100,41,211,105,98,32,237,13,240,221,125,65,163,118,235,157,230,255,71,137,214 \
    ,116,142,136,215,51,220,41,67,25,74,252,140,33,32,158,252,64,173,241,10,74 \
    ,168,243,199,187,100,31,211,102,40,107,221,135,73,85,13,159,144,108,75,186,108 \
    ,102,166,122,96,211,60,97,222,72,36,98,237,231,199,211,136,230,97,148,187,233 \
    ,61,154,92,72,80,209,93,74,34,249,9,77,173,221,19,54,92,55,63,208,53 \
    ,189,27,189,208,126,105,181,155,20,210,148,27,111,6,213,163,142,187,157,94,47 \
    ,68,88,97,150,34,116,217,98,161,122,243,183,250,210,24,206,241,64,99,33,82 \
    ,138,82,7,34,243,184,128,102,252,131,92,19,195,138,173,16,8,86,248,7,31 \
    ,69,59,75,157,96,19,94,0,0,0,0,73,69,78,68,174,66,96,130
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
bool edk::fonts::FontMap::loadFontImage(const char* name,edk::uint32 filter,edk::color4f32 color){
    return this->loadFontImage((edk::char8*) name,filter,color);
}
bool edk::fonts::FontMap::loadFontImage(edk::char8* name,edk::uint32 filter,edk::color4f32 color){
    //remove the fontImage
    this->removeFontImage();
    //test the name
    if(name){
        this->color = color;
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
bool edk::fonts::FontMap::loadFontImageFromMemory(const char* name,
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
        this->color = color;
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

//create the string
bool edk::fonts::FontMap::createStringMap(const char* str,edk::uint32 width){
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
bool edk::fonts::FontMap::createStringMap(const char* str){
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
bool edk::fonts::FontMap::addStringLine(const char* str,edk::uint32 width){
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
            if(this->map.newTileMap(width,this->lines.size())){
                this->copyLinesToMap();
                //this->cleanLines();
                this->selectAll();
                return true;
            }
        }
    }
    return false;
}
bool edk::fonts::FontMap::addStringLine(const char* str){
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
bool edk::fonts::FontMap::createStringMapOneLine(const char* str,edk::uint32 width){
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
bool edk::fonts::FontMap::createStringMapOneLine(const char* str){
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

//set the color
void edk::fonts::FontMap::setColor(edk::color4f32 color){
    this->color = color;
}
void edk::fonts::FontMap::setColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setColor(edk::color4f32(r,g,b,a));
}
void edk::fonts::FontMap::setAlpha(edk::float32 value){
    this->color.a = value;
}
void edk::fonts::FontMap::setColor(edk::color4ui8 color){
    this->color = color;
}
void edk::fonts::FontMap::setColor(edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
    this->setColor(edk::color4ui8(r,g,b,a));
}
void edk::fonts::FontMap::setAlpha(edk::uint8 value){
    this->color.a = (edk::float32)value / 255.f;
}

//delete tileMap
void edk::fonts::FontMap::deleteMap(){
    //delete lines
    //this->cleanLines();
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

//draw the text
void edk::fonts::FontMap::draw(edk::color4f32 color){
    this->color = color;
    //this->map.draw(color);
    this->draw(this->origin,this->last,color);
}
void edk::fonts::FontMap::draw(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->color = edk::color4f32(r,g,b,a);
    //this->map.draw(color);
    this->draw(this->origin,this->last,color);
}
void edk::fonts::FontMap::draw(edk::float32 r,edk::float32 g,edk::float32 b){
    this->draw(r,g,b,1.f);
}
void edk::fonts::FontMap::draw(){
    this->draw(this->origin,this->last,this->color);
}
void edk::fonts::FontMap::drawWire(edk::color4f32 color){
    this->color = color;
    //this->map.drawWire(color);
    this->drawWire(this->origin,this->last,color);
}
void edk::fonts::FontMap::drawWire(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->color = edk::color4f32(r,g,b,a);
    //this->map.drawWire(color);
    this->drawWire(this->origin,this->last,color);
}
void edk::fonts::FontMap::drawWire(edk::float32 r,edk::float32 g,edk::float32 b){
    this->drawWire(r,g,b,1.f);
}
void edk::fonts::FontMap::drawWire(){
    this->drawWire(this->origin,this->last,this->color);
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
