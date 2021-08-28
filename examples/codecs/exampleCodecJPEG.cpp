/*
Library EDK - How to use codec JPEG in EDK
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

#include "edk/codecs/EncoderJPEG.h"
#include "edk/codecs/DecoderJPEG.h"

#define width 320
#define height 240
#define rgb 3u
//grayscale
#define gray 1u

//FileNames
#define fileRGB100 "./RGB_100.jpg"
#define fileRGB50 "./RGB_50.jpg"
#define fileRGB10 "./RGB_10.jpg"
#define fileGRAY100 "./GRAY_100.jpg"
#define fileGRAY50 "./GRAY_50.jpg"
#define fileGRAY10 "./GRAY_10.jpg"

int main(){
    printf("\n\n");fflush(stdout);

    //create a new image
    edk::char8 imageRGB[width*height*rgb];
    edk::char8 imageGray[width*height*gray];

    //clean the images
    edk::char8* vec1=NULL;
    vec1 = imageRGB;
    edk::char8* vec2=NULL;
    vec2 = imageGray;
    edk::uint8 counter=0u;
    edk::color3ui8 color;
    color = edk::color3ui8(145,169,213);
    for(edk::uint32 y=0u;y<height;y++){
        for(edk::uint32 x=0u;x<width;x++){
            vec1[0u] = color.r;
            vec1[1u] = color.g;
            vec1[2u] = color.b;
            vec1+=rgb;

            *vec2 = color.r;
            vec2+=gray;
        }
        if(counter>10u){
            //change color

            if(color.r == 246){
                color = edk::color3ui8(145,169,213);
            }
            else{
                color = edk::color3ui8(246,202,199);
            }

            counter=0u;
        }
        else{
            counter++;
        }
    }

    //convert it to JPG
    edk::codecs::EncoderJPEG jpegE;
    jpegE.encodeToFile((edk::uint8*)imageRGB,width,height,rgb,100,fileRGB100);
    jpegE.encodeToFile((edk::uint8*)imageRGB,width,height,rgb,50,fileRGB50);
    jpegE.encodeToFile((edk::uint8*)imageRGB,width,height,rgb,10,fileRGB10);
    //save the grayscale
    jpegE.encodeToFile((edk::uint8*)imageGray,width,height,gray,100,fileGRAY100);
    jpegE.encodeToFile((edk::uint8*)imageGray,width,height,gray,100,fileGRAY50);
    jpegE.encodeToFile((edk::uint8*)imageGray,width,height,gray,100,fileGRAY10);

    //convert from JPG
    edk::codecs::DecoderJPEG jpegD;
    //RGB
    if(jpegD.decodeFromFile(fileRGB100)){
        printf("\n%s == width %u height %u channels %u"
               ,fileRGB100
               ,jpegD.getFrameWidth()
               ,jpegD.getFrameHeight()
               ,jpegD.getFrameChannels()
               );fflush(stdout);
        if(jpegD.getFrameWidth() == width && jpegD.getFrameHeight() == height && jpegD.getFrameChannels() == rgb){
            //copy the vector
            memcpy(imageRGB,jpegD.getFrame(),jpegD.getVectorSize());
        }
    }
    if(jpegD.decodeFromFile(fileRGB50)){
        printf("\n%s == width %u height %u channels %u"
               ,fileRGB50
               ,jpegD.getFrameWidth()
               ,jpegD.getFrameHeight()
               ,jpegD.getFrameChannels()
               );fflush(stdout);
        if(jpegD.getFrameWidth() == width && jpegD.getFrameHeight() == height && jpegD.getFrameChannels() == rgb){
            //copy the vector
            memcpy(imageRGB,jpegD.getFrame(),jpegD.getVectorSize());
        }
    }
    if(jpegD.decodeFromFile(fileRGB10)){
        printf("\n%s == width %u height %u channels %u"
               ,fileRGB10
               ,jpegD.getFrameWidth()
               ,jpegD.getFrameHeight()
               ,jpegD.getFrameChannels()
               );fflush(stdout);
        if(jpegD.getFrameWidth() == width && jpegD.getFrameHeight() == height && jpegD.getFrameChannels() == rgb){
            //copy the vector
            memcpy(imageRGB,jpegD.getFrame(),jpegD.getVectorSize());
        }
    }
    //GRAY
    if(jpegD.decodeFromFile(fileGRAY100)){
        printf("\n%s == width %u height %u channels %u"
               ,fileGRAY100
               ,jpegD.getFrameWidth()
               ,jpegD.getFrameHeight()
               ,jpegD.getFrameChannels()
               );fflush(stdout);
        if(jpegD.getFrameWidth() == width && jpegD.getFrameHeight() == height && jpegD.getFrameChannels() == gray){
            //copy the vector
            memcpy(imageGray,jpegD.getFrame(),jpegD.getVectorSize());
        }
    }
    if(jpegD.decodeFromFile(fileGRAY50)){
        printf("\n%s == width %u height %u channels %u"
               ,fileGRAY50
               ,jpegD.getFrameWidth()
               ,jpegD.getFrameHeight()
               ,jpegD.getFrameChannels()
               );fflush(stdout);
        if(jpegD.getFrameWidth() == width && jpegD.getFrameHeight() == height && jpegD.getFrameChannels() == gray){
            //copy the vector
            memcpy(imageGray,jpegD.getFrame(),jpegD.getVectorSize());
        }
    }
    if(jpegD.decodeFromFile(fileGRAY10)){
        printf("\n%s == width %u height %u channels %u"
               ,fileGRAY10
               ,jpegD.getFrameWidth()
               ,jpegD.getFrameHeight()
               ,jpegD.getFrameChannels()
               );fflush(stdout);
        if(jpegD.getFrameWidth() == width && jpegD.getFrameHeight() == height && jpegD.getFrameChannels() == gray){
            //copy the vector
            memcpy(imageGray,jpegD.getFrame(),jpegD.getVectorSize());
        }
    }

    //Encode to a vector
    edk::uint8* encoded=NULL;
    if(jpegE.encode((edk::uint8*)imageRGB,width,height,rgb,100)){
        if(jpegE.getEncoded() && jpegE.getEncodedSize()){
            //create a new encoded to receve the JPEG
            encoded = new edk::uint8[jpegE.getEncodedSize()];
            if(encoded){
                memcpy(encoded,jpegE.getEncoded(),jpegE.getEncodedSize());
                printf("\nEncodedSize %u",jpegE.getEncodedSize());

                //decode from encoded
                if(jpegD.decode(encoded,jpegE.getEncodedSize())){
                    printf("\ndecodeFromMemory == width %u height %u channels %u"
                           ,jpegD.getFrameWidth()
                           ,jpegD.getFrameHeight()
                           ,jpegD.getFrameChannels()
                           );fflush(stdout);
                    if(jpegD.getFrameWidth() == width && jpegD.getFrameHeight() == height && jpegD.getFrameChannels() == rgb){
                        //copy the vector
                        memcpy(imageRGB,jpegD.getFrame(),jpegD.getVectorSize());
                    }
                }
                //
                delete[] encoded;
            }
            jpegE.deleteEncoded();
        }
    }


    printf("\n\n");fflush(stdout);
    return 0;
}
