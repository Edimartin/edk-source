#include "SMS_Math.h"

/*
Library C++ SMS_Math - Math used in the SMS.
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

#ifdef printMessages
#pragma message "            Inside SMS_Math.c"
#endif

/*
bool math_aabb(struct vec2i32 a1,struct vec2i32 a2,struct vec2i32 b1,struct vec2i32 b2){
    if(a2.x<b1.x || a1.x>b2.x) return false;
    if(a2.y<b1.y || a1.y>b2.y) return false;
    return true;
}
*/
bool math_aabb(int32 a1x,int32 a1y,int32 a2x,int32 a2y,
               int32 b1x,int32 b1y,int32 b2x,int32 b2y
               ){
    if(a2x<b1x || a1x>b2x) return false;
    if(a2y<b1y || a1y>b2y) return false;
    return true;
}
