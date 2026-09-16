#ifndef RETROIMAGECONVERTER_H
#define RETROIMAGECONVERTER_H

/*
Library RetroImageConverter - Retro class to convert images using EDK
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
#pragma message "Inside RetroImageConverter"
#endif

//Include the binaryTree to save the elements
#pragma once
#include "../TypeVars.h"
#include "../Image2D.h"

#ifdef printMessages
#pragma message "    Compiling RetroImageConverter"
#endif

namespace edk{
class RetroImageConverter{
public:
    RetroImageConverter();
    ~RetroImageConverter();

    void Constructor();
    void Destructor();

    //convert PNG to sms
    static bool imageTosmsCode(edk::Image2D* img);
private:
    edk::classID classThis;
};
}

#endif // RETROIMAGECONVERTER_H
