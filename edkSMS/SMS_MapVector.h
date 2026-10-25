#ifndef SMS_MAPVECTOR_H
#define SMS_MAPVECTOR_H

/*
Library C++ SMS_MapVector - Map Vector used in SMS. Functions to get the vector.
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
#pragma message "Inside SMS_MapVector"
#endif

#ifdef printMessages
#pragma message "    Compiling SMS_MapVector"
#endif

#pragma once
#include <stdio.h>
#include <stdbool.h>
//#include <stdlib.h>

#include "SMS_TypeVars.h"

//get the position in the vector
uint16 mapVector_getPosition(uint16* vector,uint16 x,uint16 y,uint16 width);

#endif // SMS_MAPVECTOR_H
