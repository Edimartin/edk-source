/*
Library EDK - How to use Extensible Development Kit
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
