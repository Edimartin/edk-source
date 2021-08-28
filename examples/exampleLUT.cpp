/*
Library EDK - How to use Extensible Development Kit
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

#include <stdio.h>

#include "edk/LUT/LUT3D.h"
#include "edk/String.h"

//File Names to be saved
#define imageFile "LUT.png"
#define lutFile "LUT.cube"
//Table size. A cube with 32 positions.
#define lutSize 32u

int main(){
    //Declare the lut's to create the PNG and create the cube file.
    edk::LUT3D lut1,lut2;

    printf("\n");fflush(stdout);
    //Create the new normal table with simple colors.
    if(lut1.newTable(lutSize)){
        //Save the table to an PNG file to be edited.
        if(lut1.saveToImage(imageFile)){
            //Wait until the user edit the PNG file in an Image Editor Software.
            printf("\nImage '%s' created. Edit the image3 and press some key",imageFile);fflush(stdout);
            edk::String::consoleReadKey();

            //load the LUT from the Edited PNG file.
            if(lut2.loadFromImage(lutSize,imageFile)){
                //save the LUT Cube file to bte used in the future by the user
                if(lut2.saveTo(lutFile)){
                    //
                    printf("\nLUT file '%s' created",lutFile);fflush(stdout);
                }
                //Delete the tables generated from the PNG file.
                lut2.deleteTable();
            }
            else{
                printf("\nCan't load the Image File");fflush(stdout);
            }
        }
        else{
            printf("\nCan't save the Image File");fflush(stdout);
        }
        //delete the normal LUT table.
        lut1.deleteTable();
    }
    else{
        printf("\nCan't create LUT Table");fflush(stdout);
    }
    //Close the software.
    printf("\n");fflush(stdout);
    return 0;
}
