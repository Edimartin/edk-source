#include "CodecImage.h"

/*
Library C++ codecs - Set the parameters use for the image codecs
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
#pragma message "            Inside CodecImage.cpp"
#endif

edk::codecs::CodecImage::CodecImage(){
    //printf("\nCodecImage Construtor");edkEnd();
    this->frame=NULL;edkEnd();
    this->encoded=NULL;edkEnd();
    this->frameSize = edk::size2ui32(0u,0u);edkEnd();
    this->encodedSize = 0u;edkEnd();
    this->encodedQuality = 0u;edkEnd();
    this->frameChannels = 0.f;edkEnd();
    this->vectorFrameSize=0u;
}

edk::codecs::CodecImage::~CodecImage(){
    //printf("\nCodecImage Destrutor");edkEnd();
    //delete the vectors
    this->deleteEncoded();edkEnd();
    this->deleteFrame();edkEnd();
}

//create a new frame
bool edk::codecs::CodecImage::newFrame(edk::size2ui32 size,edk::uint8 channels){
    //test the size of the image
    if(size.width && size.height && channels){
        //test if the size of the image is diferent then the last size
        if(this->frameSize.width == size.width &&
                this->frameSize.height == size.height &&
                this->frameChannels == channels
                ){
            //return true if have the vector
            if(this->frame){
                return true;
            }
        }
        //else create a new frame

        //first delete the last frame
        this->deleteFrame();edkEnd();

        //set the size of the vector frame
        this->vectorFrameSize = (edk::uint32)(size.width * size.height * channels);edkEnd();

        //create the new frame
        if(this->vectorFrameSize){
            if( ( this->frame = (edk::uint8*)malloc(sizeof(edk::uint8) * (this->vectorFrameSize)) ) ){
                //save the new size
                this->frameSize = size;edkEnd();
                this->frameChannels = channels;edkEnd();
                //return true
                return true;
            }
        }
    }
    //else delete the frame
    this->deleteFrame();edkEnd();
    //else return false
    return false;
}
bool edk::codecs::CodecImage::newFrame(edk::uint32 width,edk::uint32 height,edk::uint8 channels){
    return this->newFrame(edk::size2ui32(width,height),channels);edkEnd();
}
//delete the frame
void edk::codecs::CodecImage::deleteFrame(){
    //test if have the frame
    if(this->frame){
        free(this->frame);edkEnd();
        this->frame=NULL;edkEnd();
    }
    //clean the size
    this->frameSize = edk::size2ui32(0u,0u);edkEnd();
    this->frameChannels=0.f;edkEnd();
    this->vectorFrameSize=0u;
}
//alloc a new frameEncoded
bool edk::codecs::CodecImage::newFrameEncoded(edk::uint32 size){
    //test the size of the frameEncoded
    if(size){
        //test if the size is are the same
        if(this->encodedSize == size){
            //return true if have the encoded
            if(this->encoded){
                return true;
            }
        }
        //else delete the last encoded
        this->deleteEncoded();edkEnd();

        //create a new encoded
        if((this->encoded = (edk::uint8*)malloc(sizeof(edk::uint8) * (size)))){
            //save the encodedSize
            this->encodedSize = size;edkEnd();
            return true;
        }
    }
    //else delete the encoded
    this->deleteEncoded();edkEnd();
    return false;
}
//delete the encoded
void edk::codecs::CodecImage::deleteEncoded(){
    //test if have the encoded
    if(this->encoded){
        free(this->encoded);edkEnd();
        this->encoded=NULL;edkEnd();
    }
    //clean the size
    this->encodedSize = 0u;edkEnd();
}

//draw a image in the frame
bool edk::codecs::CodecImage::drawFrame(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels){
    //create a new frame
    if(this->newFrame(size,channels)){
        //copy the frame
        memcpy(this->frame,frame,this->vectorFrameSize);edkEnd();
        //then return true
        return true;
    }
    return false;
}
bool edk::codecs::CodecImage::drawFrame(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels){
    return this->drawFrame(frame,edk::size2ui32(width,height),channels);edkEnd();
}
//write in the frame encoded
bool edk::codecs::CodecImage::writeEncoded(edk::uint8* frame){
    //test if have the frameEncoded
    if(this->encoded && this->encodedSize){
        //copy the frame
        memcpy(this->encoded,frame,this->encodedSize);edkEnd();
        return true;
    }
    return false;
}
//set the quality
bool edk::codecs::CodecImage::setQuality(edk::uint32 quality){
    //clean the quality
    this->encodedQuality=1u;edkEnd();
    if(quality){
        this->encodedQuality=quality;edkEnd();
        return true;
    }
    return false;
}
//get the frames
edk::uint8* edk::codecs::CodecImage::getFrame(){
    return this->frame;edkEnd();
}
edk::uint8* edk::codecs::CodecImage::getEncoded(){
    return this->encoded;edkEnd();
}
edk::uint8** edk::codecs::CodecImage::getEncodedPosition(){
    return &this->encoded;edkEnd();
}

//clean the pointers
edk::uint8* edk::codecs::CodecImage::cleanFrame(){
    edk::uint8* ret = this->frame;edkEnd();

    this->frame=NULL;edkEnd();
    //clean the size
    this->frameSize = edk::size2ui32(0u,0u);edkEnd();
    this->frameChannels=0u;
    this->vectorFrameSize=0u;

    return ret;
}
edk::uint8* edk::codecs::CodecImage::cleanEncoded(){
    edk::uint8* ret = this->encoded;edkEnd();

    this->encoded=NULL;edkEnd();
    //clean the size
    this->encodedSize = 0u;edkEnd();

    return ret;
}

//return the size of the frame
edk::size2ui32 edk::codecs::CodecImage::getFrameSize(){
    return this->frameSize;edkEnd();
}
edk::uint32 edk::codecs::CodecImage::getFrameWidth(){
    return this->frameSize.width;edkEnd();
}
edk::uint32 edk::codecs::CodecImage::getFrameHeight(){
    return this->frameSize.height;edkEnd();
}
edk::uint32 edk::codecs::CodecImage::getFrameChannels(){
    return this->frameChannels;edkEnd();
}
edk::uint32 edk::codecs::CodecImage::getFrameVectorSize(){
    return this->vectorFrameSize;edkEnd();
}
//return the size of the encoded
edk::uint32 edk::codecs::CodecImage::getEncodedSize(){
    return this->encodedSize;edkEnd();
}
edk::uint32* edk::codecs::CodecImage::getEncodedSizePosition(){
    return &this->encodedSize;edkEnd();
}
edk::uint32 edk::codecs::CodecImage::getQuality(){
    return this->encodedQuality;edkEnd();
}


//Convertions
//RGB to HSV
edk::color3f32 edk::codecs::CodecImage::rgbTohsv(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    edk::color3f32 hsv;edkEnd();
    edk::float32 min, max, delta;edkEnd();

    min = r < g ? r : g;edkEnd();
    min = min  < b ? min  : b;edkEnd();

    max = r > g ? r : g;edkEnd();
    max = max  > b ? max  : b;edkEnd();

    hsv.b = max/255;edkEnd(); // v
    //hsv.b = max*0.003921569;edkEnd(); // v


    delta = max - min;edkEnd();
    if( max > 0.f ){ // NOTE: if Max is == 0, this divide would cause a crash
        hsv.g = (delta / max);edkEnd();// s
    } else {
        // if max is 0, then r = g = b = 0
        // s = 0, v is undefined
        hsv.g = 0.f;edkEnd(); // s
        hsv.r = 0.f;edkEnd();//NAN;edkEnd(); // h its now undefined
        return hsv;edkEnd();
    }

    if(delta){
        if( r >= max ){                        // > is bogus, just keeps compilor happy
            hsv.r = ( g - b ) / delta;edkEnd();        // between yellow & magenta
        }
        else{
            if( g >= max ){
                hsv.r = 2.0 + ( b - r ) / delta;edkEnd();  // between cyan & yellow
            }
            else{
                hsv.r = 4.0 + ( r - g ) / delta;edkEnd();  // between magenta & cyan
            }
        }


        hsv.r *= 60.0;                              // degrees

        if( hsv.r  < 0.0 )
            hsv.r  += 360.0;
    }
    else{
        hsv.r=0.f;edkEnd();
    }

    return hsv;edkEnd();
}
edk::color3f32 edk::codecs::CodecImage::rgbTohsv(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbTohsv(rgb.r,rgb.g,rgb.b);edkEnd();
}
edk::color3f32 edk::codecs::CodecImage::rgbTohsv(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbTohsv(rgba.r,rgba.g,rgba.b);edkEnd();
}
edk::uint8 edk::codecs::CodecImage::rgbToV(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    edk::uint8 max;edkEnd();

    max = r > g ? r : g;edkEnd();
    max = max  > b ? max  : b;edkEnd();

    return max;edkEnd(); // v
}
edk::uint8 edk::codecs::CodecImage::rgbToV(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbToV(rgb.r,rgb.g,rgb.b);edkEnd();
}
edk::uint8 edk::codecs::CodecImage::rgbaToV(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbToV(rgba.r,rgba.g,rgba.b);edkEnd();
}
//RGB to A
edk::uint8 edk::codecs::CodecImage::rgbToA(edk::uint8 r,edk::uint8 g,edk::uint8 b
                                           ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                                           ){
    return (edk::uint8)edk::Math::pythagoras((edk::int16)r-compareR
                                             ,(edk::int16)g-compareG
                                             ,(edk::int16)b-compareB
                                             )
            /edk::Math::pythagoras(0x00FF-compareR,0x00FF-compareG,0x00FF-compareB);
}
edk::uint8 edk::codecs::CodecImage::rgbToA(edk::uint8 r,edk::uint8 g,edk::uint8 b
                                           ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                                           ,edk::uint8 min,edk::uint8 max
                                           ){
    edk::uint8 ret = edk::codecs::CodecImage::rgbToA(r,g,b,compareR,compareG,compareB);
    if(ret<=min||ret>=max){
        return 0u;
    }
    return ret;
}
edk::uint8 edk::codecs::CodecImage::rgbToA(edk::color3ui8 rgb,edk::color3ui8 compareRGB){
    return edk::codecs::CodecImage::rgbToA(rgb.r,rgb.g,rgb.b
                                           ,compareRGB.r,compareRGB.g,compareRGB.b
                                           );
}
edk::uint8 edk::codecs::CodecImage::rgbToA(edk::color3ui8 rgb,edk::color3ui8 compareRGB,edk::uint8 min,edk::uint8 max){
    edk::uint8 ret = edk::codecs::CodecImage::rgbToA(rgb,compareRGB);
    if(ret<=min||ret>=max){
        return 0u;
    }
    return ret;
}
//RGBA to A
edk::uint8 edk::codecs::CodecImage::rgbaToA(edk::color4ui8 rgba,edk::color3ui8 compareRGB){
    return edk::codecs::CodecImage::rgbToA(rgba.r,rgba.g,rgba.b
                                           ,compareRGB.r,compareRGB.g,compareRGB.b
                                           );
}
edk::uint8 edk::codecs::CodecImage::rgbaToA(edk::color4ui8 rgba,edk::color3ui8 compareRGB,edk::uint8 min,edk::uint8 max){
    edk::uint8 ret = edk::codecs::CodecImage::rgbaToA(rgba,compareRGB);
    if(ret<=min||ret>=max){
        return 0u;
    }
    return ret;
}
//vector
bool edk::codecs::CodecImage::rgbToV(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    if(vector && size.width && size.height && dest){
        edk::uint32 vecSize = size.width * size.height;edkEnd();
        for(edk::uint32 i=0u;i<vecSize;i++){
            *dest = edk::codecs::CodecImage::rgbToV(vector[0u],vector[1u],vector[2u]);edkEnd();

            vector+=3u;edkEnd();
            dest++;edkEnd();
        }
        return true;
    }
    return false;
}
edk::uint8* edk::codecs::CodecImage::rgbToV(edk::uint8* vector,edk::size2ui32 size){
    if(vector && size.width && size.height){
        edk::uint32 vecSize = size.width * size.height;edkEnd();
        //create the return
        edk::uint8* ret = (edk::uint8*)malloc(sizeof(edk::uint8) * (vecSize));edkEnd();
        if(ret){
            if(edk::codecs::CodecImage::rgbToV(vector,size,ret)){
                return ret;
            }
            //
            free(ret);edkEnd();
        }
    }
    return NULL;
}
bool edk::codecs::CodecImage::rgbToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbToV(vector,edk::size2ui32(width,height),dest);edkEnd();
}
edk::uint8* edk::codecs::CodecImage::rgbToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbToV(vector,edk::size2ui32(width,height));edkEnd();
}
bool edk::codecs::CodecImage::rgbaToV(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    if(vector && size.width && size.height && dest){
        edk::uint32 vecSize = size.width * size.height;edkEnd();
        for(edk::uint32 i=0u;i<vecSize;i++){
            *dest = edk::codecs::CodecImage::rgbToV(vector[0u],vector[1u],vector[2u]);edkEnd();

            vector+=4u;edkEnd();
            dest++;edkEnd();
        }
        return true;
    }
    return false;
}
edk::uint8* edk::codecs::CodecImage::rgbaToV(edk::uint8* vector,edk::size2ui32 size){
    if(vector && size.width && size.height){
        edk::uint32 vecSize = size.width * size.height;edkEnd();
        //create the return
        edk::uint8* ret = (edk::uint8*)malloc(sizeof(edk::uint8) * (vecSize));edkEnd();
        if(ret){
            if(edk::codecs::CodecImage::rgbaToV(vector,size,ret)){
                return ret;
            }
            //
            free(ret);edkEnd();
        }
    }
    return NULL;
}
bool edk::codecs::CodecImage::rgbaToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbaToV(vector,edk::size2ui32(width,height),dest);edkEnd();
}
edk::uint8* edk::codecs::CodecImage::rgbaToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbaToV(vector,edk::size2ui32(width,height));edkEnd();
}
bool edk::codecs::CodecImage::rgbaToAlpha(edk::uint8* vector,edk::size2ui32 size
                                          ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                                          ){
    if(vector && size.width && size.height){
        edk::uint32 vecSize = size.width * size.height;edkEnd();
        for(edk::uint32 i=0u;i<vecSize;i++){
            vector[3u] = edk::codecs::CodecImage::rgbToA(vector[0u],vector[1u],vector[2u]
                    ,compareR,compareG,compareB
                    );edkEnd();
            vector+=4u;edkEnd();
        }
        return true;
    }
    return false;
}
bool edk::codecs::CodecImage::rgbaToAlpha(edk::uint8* vector,edk::size2ui32 size
                                          ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                                          ,edk::uint8 min,edk::uint8 max
                                          ){
    if(vector && size.width && size.height){
        edk::uint32 vecSize = size.width * size.height;edkEnd();
        for(edk::uint32 i=0u;i<vecSize;i++){
            vector[3u] = edk::codecs::CodecImage::rgbToA(vector[0u],vector[1u],vector[2u]
                    ,compareR,compareG,compareB
                    ,min,max
                    );edkEnd();
            vector+=4u;edkEnd();
        }
        return true;
    }
    return false;
}
bool edk::codecs::CodecImage::rgbaToAlpha(edk::uint8* vector,edk::size2ui32 size
                                          ,edk::color3ui8 compareRGB
                                          ){
    return edk::codecs::CodecImage::rgbaToAlpha(vector,size
                                                ,compareRGB.r,compareRGB.g,compareRGB.b
                                                );
}
bool edk::codecs::CodecImage::rgbaToAlpha(edk::uint8* vector,edk::size2ui32 size
                                          ,edk::color3ui8 compareRGB
                                          ,edk::uint8 min,edk::uint8 max
                                          ){
    return edk::codecs::CodecImage::rgbaToAlpha(vector,size
                                                ,compareRGB.r,compareRGB.g,compareRGB.b
                                                ,min,max
                                                );
}
bool edk::codecs::CodecImage::rgbaToAlpha(edk::uint8* vector,edk::uint32 width,edk::uint32 height
                                          ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                                          ){
    return edk::codecs::CodecImage::rgbaToAlpha(vector,edk::size2ui32(width,height)
                                                ,compareR,compareG,compareB
                                                );
}
bool edk::codecs::CodecImage::rgbaToAlpha(edk::uint8* vector,edk::uint32 width,edk::uint32 height
                                          ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                                          ,edk::uint8 min,edk::uint8 max
                                          ){
    return edk::codecs::CodecImage::rgbaToAlpha(vector,edk::size2ui32(width,height)
                                                ,compareR,compareG,compareB
                                                ,min,max
                                                );
}
bool edk::codecs::CodecImage::rgbaToAlpha(edk::uint8* vector,edk::uint32 width,edk::uint32 height
                                          ,edk::color3ui8 compareRGB
                                          ){
    return edk::codecs::CodecImage::rgbaToAlpha(vector,edk::size2ui32(width,height)
                                                ,compareRGB.r,compareRGB.g,compareRGB.b
                                                );
}
bool edk::codecs::CodecImage::rgbaToAlpha(edk::uint8* vector,edk::uint32 width,edk::uint32 height
                                          ,edk::color3ui8 compareRGB
                                          ,edk::uint8 min,edk::uint8 max
                                          ){
    return edk::codecs::CodecImage::rgbaToAlpha(vector,edk::size2ui32(width,height)
                                                ,compareRGB.r,compareRGB.g,compareRGB.b
                                                ,min,max
                                                );
}
//HSV to RGB
edk::color3ui8 edk::codecs::CodecImage::hsvTorgb(edk::float32 h,edk::float32 s,edk::float32 v){
    edk::color3ui8 rgb;edkEnd();

    v*=255;edkEnd();

    edk::float64      hh, p, q, t, ff;edkEnd();
    edk::int64        i;edkEnd();

    if(s <= 0.0){       // < is bogus, just shuts up warnings
        rgb.r = v;edkEnd();
        rgb.g = v;edkEnd();
        rgb.b = v;edkEnd();
        return rgb;edkEnd();
    }
    hh = h;edkEnd();
    if(hh >= 360.0){
        hh = 0.0;edkEnd();
    }
    hh /= 60.0;
    i = (edk::int64)hh;edkEnd();
    ff = hh - i;edkEnd();
    p = v * (1.0 -  s);edkEnd();
    q = v * (1.0 - (s * ff));edkEnd();
    t = v * (1.0 - (s * (1.0 - ff)));edkEnd();

    switch(i){
    case 0:
        rgb.r = v;edkEnd();
        rgb.g = t;edkEnd();
        rgb.b = p;edkEnd();
        break;
    case 1:
        rgb.r = q;edkEnd();
        rgb.g = v;edkEnd();
        rgb.b = p;edkEnd();
        break;
    case 2:
        rgb.r = p;edkEnd();
        rgb.g = v;edkEnd();
        rgb.b = t;edkEnd();
        break;

    case 3:
        rgb.r = p;edkEnd();
        rgb.g = q;edkEnd();
        rgb.b = v;edkEnd();
        break;
    case 4:
        rgb.r = t;edkEnd();
        rgb.g = p;edkEnd();
        rgb.b = v;edkEnd();
        break;
    case 5:
    default:
        rgb.r = v;edkEnd();
        rgb.g = p;edkEnd();
        rgb.b = q;edkEnd();
        break;
    }

    return rgb;edkEnd();
}
edk::color3ui8 edk::codecs::CodecImage::hsvTorgb(edk::color3f32 hsv){
    return edk::codecs::CodecImage::hsvTorgb(hsv.r,hsv.g,hsv.b);edkEnd();
}
//RGB to HSL
edk::color3f32 edk::codecs::CodecImage::rgbTohsl(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    edk::color3f32 hsl;edkEnd();
    edk::float32 dr = r/255.f,dg = g/255.f,db = b/255.f;edkEnd();
    edk::float64 min, max;edkEnd();

    min = dr < dg ? dr : dg;edkEnd();
    min = min  < db ? min  : db;edkEnd();

    max = dr > dg ? dr : dg;edkEnd();
    max = max  > db ? max  : db;edkEnd();

    hsl.b = (max + min) / 2.f;edkEnd(); // l

    if(max == min){
        hsl.r = hsl.g= 0; // achromatic
    }else{
        edk::float64  delta = max - min;edkEnd();
        hsl.g = hsl.b > 0.5f ? delta / (2.f - max - min) : delta / (max + min);edkEnd();

        if(delta){
            if(max==dr){
                hsl.r = (dg - db) / delta + (dg < db ? 6.f : 0.f);edkEnd();
            }
            else if(max==dg){
                hsl.r = (db - dr) / delta + 2.f;edkEnd();
            }
            else if(max==db){
                hsl.r = (dr - dg) / delta + 4.f;edkEnd();
            }

            hsl.r/= 6.f;edkEnd();
            //hsl.r*=360.f;edkEnd();
        }
        else{
            hsl.r=0.f;edkEnd();
        }
    }
    return hsl;edkEnd();
}
edk::color3f32 edk::codecs::CodecImage::rgbTohsl(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbTohsl(rgb.r,rgb.g,rgb.b);edkEnd();
}
edk::color3f32 edk::codecs::CodecImage::rgbaTohsl(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbTohsl(rgba.r,rgba.g,rgba.b);edkEnd();
}
edk::float32 edk::codecs::CodecImage::rgbToL(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    //
    edk::float32 dr = r/255.f,dg = g/255.f,db = b/255.f;edkEnd();
    edk::float32 min, max;edkEnd();

    min = dr < dg ? dr : dg;edkEnd();
    min = min  < db ? min  : db;edkEnd();

    max = dr > dg ? dr : dg;edkEnd();
    max = max  > db ? max  : db;edkEnd();

    return (max + min) / 2.f;edkEnd(); // l
}
edk::float32 edk::codecs::CodecImage::rgbToL(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbToL(rgb.r,rgb.g,rgb.b);edkEnd();
}
edk::float32 edk::codecs::CodecImage::rgbaToL(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbToL(rgba.r,rgba.g,rgba.b);edkEnd();
}
edk::uint8 edk::codecs::CodecImage::rgbToLui8(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return (edk::uint8)(edk::codecs::CodecImage::rgbToL(r,g,b) * 255.f);edkEnd();
}
edk::uint8 edk::codecs::CodecImage::rgbToLui8(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbToLui8(rgb.r,rgb.g,rgb.b);edkEnd();
}
edk::uint8 edk::codecs::CodecImage::rgbaToLui8(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbToLui8(rgba.r,rgba.g,rgba.b);edkEnd();
}
//vector
bool edk::codecs::CodecImage::rgbToLui8(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    if(vector && size.width && size.height && dest){
        edk::uint32 vecSize = size.width * size.height;edkEnd();
        for(edk::uint32 i=0u;i<vecSize;i++){
            *dest = edk::codecs::CodecImage::rgbToLui8(vector[0u],vector[1u],vector[2u]);edkEnd();

            vector+=3u;edkEnd();
            dest++;edkEnd();
        }
        return true;
    }
    return false;
}
edk::uint8* edk::codecs::CodecImage::rgbToLui8(edk::uint8* vector,edk::size2ui32 size){
    if(vector && size.width && size.height){
        edk::uint32 vecSize = size.width * size.height;edkEnd();
        //create the return
        edk::uint8* ret = (edk::uint8*)malloc(sizeof(edk::uint8) * (vecSize));edkEnd();
        if(ret){
            if(edk::codecs::CodecImage::rgbToLui8(vector,size,ret)){
                return ret;
            }
            //
            free(ret);edkEnd();
        }
        ret=NULL;edkEnd();
    }
    return NULL;
}
bool edk::codecs::CodecImage::rgbToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbToLui8(vector,edk::size2ui32(width,height),dest);edkEnd();
}
edk::uint8* edk::codecs::CodecImage::rgbToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbToLui8(vector,edk::size2ui32(width,height));edkEnd();
}
bool edk::codecs::CodecImage::rgbaToLui8(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    if(vector && size.width && size.height && dest){
        edk::uint32 vecSize = size.width * size.height;edkEnd();
        for(edk::uint32 i=0u;i<vecSize;i++){
            *dest = edk::codecs::CodecImage::rgbToLui8(vector[0u],vector[1u],vector[2u]);edkEnd();

            vector+=4u;edkEnd();
            dest++;edkEnd();
        }
        return true;
    }
    return false;
}
edk::uint8* edk::codecs::CodecImage::rgbaToLui8(edk::uint8* vector,edk::size2ui32 size){
    if(vector && size.width && size.height){
        edk::uint32 vecSize = size.width * size.height;edkEnd();
        //create the return
        edk::uint8* ret = (edk::uint8*)malloc(sizeof(edk::uint8) * (vecSize));edkEnd();
        if(ret){
            if(edk::codecs::CodecImage::rgbaToLui8(vector,size,ret)){
                return ret;
            }
            //
            free(ret);edkEnd();
        }
        ret=NULL;edkEnd();
    }
    return NULL;
}
bool edk::codecs::CodecImage::rgbaToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbaToLui8(vector,edk::size2ui32(width,height),dest);edkEnd();
}
edk::uint8* edk::codecs::CodecImage::rgbaToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbaToLui8(vector,edk::size2ui32(width,height));edkEnd();
}
//HSL to RGB
inline edk::float32 EDKhue2rgb(edk::float32 p, edk::float32 q, edk::float32 t){
    if(t < 0.f){
        t += 1.f;edkEnd();
    }
    if(t > 1.f){
        t -= 1.f;edkEnd();
    }
    if(t < 1.f/6.f){
        return p + (q - p) * 6.f * t;edkEnd();
    }
    if(t < 1.f/2.f){
        return q;edkEnd();
    }
    if(t < 2.f/3.f){
        return p + (q - p) * (2.f/3.f - t) * 6.f;edkEnd();
    }
    return p;edkEnd();
}
edk::color3ui8 edk::codecs::CodecImage::hslTorgb(edk::float32 h,edk::float32 s,edk::float32 l){

    edk::float32 r,g,b;edkEnd();


    if(s == 0.f){
        r = g = b = l;edkEnd(); // achromatic
    }else{
        edk::float32 q = l < 0.5f ? l * (1.f + s) : l + s - l * s;edkEnd();
        edk::float32 p = 2.f * l - q;edkEnd();
        r = EDKhue2rgb(p, q, h + (1.f/3.f));edkEnd();
        g = EDKhue2rgb(p, q, h);edkEnd();
        b = EDKhue2rgb(p, q, h - (1.f/3.f));edkEnd();
    }
    edk::color3ui8 rgb((edk::uint8)(r*255.f),
                       (edk::uint8)(g*255.f),
                       (edk::uint8)(b*255.f)
                       );edkEnd();
    /*
    if((r-rgb.r)>0.5f){
        rgb.r++;edkEnd();
    }
    if((g-rgb.g)>0.5f){
        rgb.g++;edkEnd();
    }
    if((b-rgb.b)>0.5f){
        rgb.b++;edkEnd();
    }
*/
    return rgb;edkEnd();
}
edk::color3ui8 edk::codecs::CodecImage::hslTorgb(edk::color3f32 hsl){
    return edk::codecs::CodecImage::hslTorgb(hsl.r,hsl.g,hsl.b);edkEnd();
}
//RGB to YUV
edk::vec3ui8 edk::codecs::CodecImage::rgbToyuv(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::vec3ui8(
                (edk::uint8)(r *  0.299000 + g *  0.587000 + b *  0.114000),
                (edk::uint8)(r * -0.168736 + g * -0.331264 + b *  0.500000 + 128),
                (edk::uint8)(r *  0.500000 + g * -0.418688 + b * -0.081312 + 128)
                );edkEnd();
}
edk::vec3ui8 edk::codecs::CodecImage::rgbToyuv(edk::color3ui8 color){
    return edk::codecs::CodecImage::rgbToyuv(color.r,color.g,color.b);edkEnd();
}
edk::vec3ui8 grayToyuv(edk::uint8 gray){
    return edk::vec3ui8(
                (edk::uint8)(gray *  0.299000 + gray *  0.587000 + gray *  0.114000),
                (edk::uint8)(gray * -0.168736 + gray * -0.331264 + gray *  0.500000 + 128),
                (edk::uint8)(gray *  0.500000 + gray * -0.418688 + gray * -0.081312 + 128)
                );edkEnd();
}
//vector
bool edk::codecs::CodecImage::rgbToyuv(edk::uint8* rgb,edk::size2ui32 size,edk::uint8* yuv){
    if(rgb && size.width && size.height && yuv){
        edk::uint32 vecSize = size.width * size.height;edkEnd();
        for(edk::uint32 i=0u;i<vecSize;i++){
            yuv[0u] = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
            yuv[1u] = (edk::uint8)(rgb[0u] * -0.168736 + rgb[1u]* -0.331264 + rgb[2u] *  0.500000 + 128);edkEnd();
            yuv[2u] = (edk::uint8)(rgb[0u] *  0.500000 + rgb[1u]* -0.418688 + rgb[2u]* -0.081312 + 128);edkEnd();

            rgb+=3u;edkEnd();
            yuv+=3u;edkEnd();
        }
        return true;
    }
    return false;
}
bool edk::codecs::CodecImage::rgbToyuv(edk::uint8* rgb,edk::size2ui32 size,edk::uint8* y,edk::uint8* u,edk::uint8* v){
    if(rgb && size.width && size.height && y && u && v){
        edk::uint32 vecSize = size.width * size.height;edkEnd();
        for(edk::uint32 i=0u;i<vecSize;i++){
            *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u] *  0.587000 + rgb[2u] *  0.114000);edkEnd();
            *u = (edk::uint8)(rgb[0u] * -0.168736 + rgb[1u] * -0.331264 + rgb[2u] *  0.500000 + 128);edkEnd();
            *v = (edk::uint8)(rgb[0u] *  0.500000 + rgb[1u] * -0.418688 + rgb[2u]* -0.081312 + 128);edkEnd();

            rgb+=3u;edkEnd();
            y++;edkEnd();
            u++;edkEnd();
            v++;edkEnd();
        }
        return true;
    }
    return false;
}
bool edk::codecs::CodecImage::grayToyuv(edk::uint8* gray,edk::size2ui32 size,edk::uint8* y,edk::uint8* u,edk::uint8* v){
    if(gray && size.width && size.height && y && u && v){
        edk::uint32 vecSize = size.width * size.height;edkEnd();
        for(edk::uint32 i=0u;i<vecSize;i++){
            *y = (edk::uint8)(*gray *  0.299000 + *gray *  0.587000 + *gray *  0.114000);edkEnd();
            *u = (edk::uint8)(*gray * -0.168736 + *gray * -0.331264 + *gray *  0.500000 + 128);edkEnd();
            *v = (edk::uint8)(*gray *  0.500000 + *gray * -0.418688 + *gray * -0.081312 + 128);edkEnd();

            gray++;edkEnd();
            y++;edkEnd();
            u++;edkEnd();
            v++;edkEnd();
        }
        return true;
    }
    return false;
}
bool edk::codecs::CodecImage::rgbToi420(edk::uint8* rgb,edk::size2ui32 size,edk::uint8* y,edk::uint8* u,edk::uint8* v){
    if(rgb && size.width && size.height && y && u && v){
        //test the lenght (even or odd)
        if(!(size.width<<((sizeof(size.width)*8u)-1u))){
            //even
            if(!(size.height<<((sizeof(size.height)*8u)-1u))){
                //even

                //run the algorith for the fully size
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    //process the line even
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                        y++;edkEnd();
                        rgb+=3u;edkEnd();
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                        *u = (edk::uint8)(rgb[0u] * -0.168736 + rgb[1u]* -0.331264 + rgb[2u] *  0.500000 + 128);edkEnd();
                        *v = (edk::uint8)(rgb[0u] *  0.500000 + rgb[1u]* -0.418688 + rgb[2u]* -0.081312 + 128);edkEnd();
                        y++;edkEnd();
                        rgb+=3u;edkEnd();
                        u++;edkEnd();
                        v++;edkEnd();
                    }
                    //process the line odd
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                        y++;edkEnd();
                        rgb+=3u;edkEnd();
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                        y++;edkEnd();
                        rgb+=3u;edkEnd();
                    }
                }
            }
            else{
                //odd

                //run the algorith for height-2 because the counter go twice
                size.height-=2u;edkEnd();
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    //process the line even
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                        y++;edkEnd();
                        rgb+=3u;edkEnd();
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                        *u = (edk::uint8)(rgb[0u] * -0.168736 + rgb[1u]* -0.331264 + rgb[2u] *  0.500000 + 128);edkEnd();
                        *v = (edk::uint8)(rgb[0u] *  0.500000 + rgb[1u]* -0.418688 + rgb[2u]* -0.081312 + 128);edkEnd();
                        y++;edkEnd();
                        rgb+=3u;edkEnd();
                        u++;edkEnd();
                        v++;edkEnd();
                    }
                    //process the line odd
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                        y++;edkEnd();
                        rgb+=3u;edkEnd();
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                        y++;edkEnd();
                        rgb+=3u;edkEnd();
                    }
                }
                //process the last odd line
                for(j=0u;j<size.width;j+=2u){
                    *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                    y++;edkEnd();
                    rgb+=3u;edkEnd();
                    *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                    *u = (edk::uint8)(rgb[0u] * -0.168736 + rgb[1u]* -0.331264 + rgb[2u] *  0.500000 + 128);edkEnd();
                    *v = (edk::uint8)(rgb[0u] *  0.500000 + rgb[1u]* -0.418688 + rgb[2u]* -0.081312 + 128);edkEnd();
                    y++;edkEnd();
                    rgb+=3u;edkEnd();
                    u++;edkEnd();
                    v++;edkEnd();
                }
            }
        }
        else{
            //odd
            if(!(size.height<<((sizeof(size.height)*8u)-1u))){
                //even

                //run the algorith for width-2 because the counter go twice
                size.width-=2u;edkEnd();
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    //start the line even
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                        y++;edkEnd();
                        rgb+=3u;edkEnd();
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                        *u = (edk::uint8)(rgb[0u] * -0.168736 + rgb[1u]* -0.331264 + rgb[2u] *  0.500000 + 128);edkEnd();
                        *v = (edk::uint8)(rgb[0u] *  0.500000 + rgb[1u]* -0.418688 + rgb[2u]* -0.081312 + 128);edkEnd();
                        y++;edkEnd();
                        rgb+=3u;edkEnd();
                        u++;edkEnd();
                        v++;edkEnd();
                    }
                    //process the last pixel odd
                    *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                    y++;edkEnd();
                    rgb+=3u;edkEnd();
                    //start the line odd
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                        y++;edkEnd();
                        rgb+=3u;edkEnd();
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                        y++;edkEnd();
                        rgb+=3u;edkEnd();
                    }
                    //process the last pixel odd
                    *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                    y++;edkEnd();
                    rgb+=3u;edkEnd();
                }
            }
            else{
                //odd

                //run the algorith for width-2 and heigth-2 because the counter go twice
                size.height-=2u;edkEnd();
                size.width-=2u;edkEnd();
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    //process the line even
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                        y++;edkEnd();
                        rgb+=3u;edkEnd();
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                        *u = (edk::uint8)(rgb[0u] * -0.168736 + rgb[1u]* -0.331264 + rgb[2u] *  0.500000 + 128);edkEnd();
                        *v = (edk::uint8)(rgb[0u] *  0.500000 + rgb[1u]* -0.418688 + rgb[2u]* -0.081312 + 128);edkEnd();
                        y++;edkEnd();
                        rgb+=3u;edkEnd();
                        u++;edkEnd();
                        v++;edkEnd();
                    }
                    //process the last pixel even
                    *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                    y++;edkEnd();
                    rgb+=3u;edkEnd();
                    //process the line odd
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                        y++;edkEnd();
                        rgb+=3u;edkEnd();
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                        y++;edkEnd();
                        rgb+=3u;edkEnd();
                    }
                    //process the last pixel odd
                    *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                    y++;edkEnd();
                    rgb+=3u;edkEnd();
                }
                //process the last line odd
                for(j=0u;j<size.width;j+=2u){
                    *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                    y++;edkEnd();
                    rgb+=3u;edkEnd();
                    *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                    *u = (edk::uint8)(rgb[0u] * -0.168736 + rgb[1u]* -0.331264 + rgb[2u] *  0.500000 + 128);edkEnd();
                    *v = (edk::uint8)(rgb[0u] *  0.500000 + rgb[1u]* -0.418688 + rgb[2u]* -0.081312 + 128);edkEnd();
                    y++;edkEnd();
                    rgb+=3u;edkEnd();
                    u++;edkEnd();
                    v++;edkEnd();
                }
                //process the last pixel odd
                *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);edkEnd();
                y++;edkEnd();
                rgb+=3u;edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::codecs::CodecImage::grayToi420(edk::uint8* gray,edk::size2ui32 size,edk::uint8* y,edk::uint8* u,edk::uint8* v){
    if(gray && size.width && size.height && y && u && v){
        //test the lenght (even or odd)
        if(!(size.width<<((sizeof(size.width)*8u)-1u))){
            //even
            if(!(size.height<<((sizeof(size.height)*8u)-1u))){
                //even

                //run the algorith for the fully size
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    //process the line even
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                        y++;edkEnd();
                        gray++;edkEnd();
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                        *u = (edk::uint8)(*gray * -0.168736 + *gray* -0.331264 + *gray *  0.500000 + 128);edkEnd();
                        *v = (edk::uint8)(*gray *  0.500000 + *gray* -0.418688 + *gray* -0.081312 + 128);edkEnd();
                        y++;edkEnd();
                        gray++;edkEnd();
                        u++;edkEnd();
                        v++;edkEnd();
                    }
                    //process the line odd
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                        y++;edkEnd();
                        gray++;edkEnd();
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                        y++;edkEnd();
                        gray++;edkEnd();
                    }
                }
            }
            else{
                //odd

                //run the algorith for height-2 because the counter go twice
                size.height-=2u;edkEnd();
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    //process the line even
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                        y++;edkEnd();
                        gray++;edkEnd();
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                        *u = (edk::uint8)(*gray * -0.168736 + *gray* -0.331264 + *gray *  0.500000 + 128);edkEnd();
                        *v = (edk::uint8)(*gray *  0.500000 + *gray* -0.418688 + *gray* -0.081312 + 128);edkEnd();
                        y++;edkEnd();
                        gray++;edkEnd();
                        u++;edkEnd();
                        v++;edkEnd();
                    }
                    //process the line odd
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                        y++;edkEnd();
                        gray++;edkEnd();
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                        y++;edkEnd();
                        gray++;edkEnd();
                    }
                }
                //process the last odd line
                for(j=0u;j<size.width;j+=2u){
                    *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                    y++;edkEnd();
                    gray++;edkEnd();
                    *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                    *u = (edk::uint8)(*gray * -0.168736 + *gray* -0.331264 + *gray *  0.500000 + 128);edkEnd();
                    *v = (edk::uint8)(*gray *  0.500000 + *gray* -0.418688 + *gray* -0.081312 + 128);edkEnd();
                    y++;edkEnd();
                    gray++;edkEnd();
                    u++;edkEnd();
                    v++;edkEnd();
                }
            }
        }
        else{
            //odd
            if(!(size.height<<((sizeof(size.height)*8u)-1u))){
                //even

                //run the algorith for width-2 because the counter go twice
                size.width-=2u;edkEnd();
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    //start the line even
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                        y++;edkEnd();
                        gray++;edkEnd();
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                        *u = (edk::uint8)(*gray * -0.168736 + *gray* -0.331264 + *gray *  0.500000 + 128);edkEnd();
                        *v = (edk::uint8)(*gray *  0.500000 + *gray* -0.418688 + *gray* -0.081312 + 128);edkEnd();
                        y++;edkEnd();
                        gray++;edkEnd();
                        u++;edkEnd();
                        v++;edkEnd();
                    }
                    //process the last pixel odd
                    *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                    y++;edkEnd();
                    gray++;edkEnd();
                    //start the line odd
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                        y++;edkEnd();
                        gray++;edkEnd();
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                        y++;edkEnd();
                        gray++;edkEnd();
                    }
                    //process the last pixel odd
                    *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                    y++;edkEnd();
                    gray++;edkEnd();
                }
            }
            else{
                //odd

                //run the algorith for width-2 and heigth-2 because the counter go twice
                size.height-=2u;edkEnd();
                size.width-=2u;edkEnd();
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    //process the line even
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                        y++;edkEnd();
                        gray++;edkEnd();
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                        *u = (edk::uint8)(*gray * -0.168736 + *gray* -0.331264 + *gray *  0.500000 + 128);edkEnd();
                        *v = (edk::uint8)(*gray *  0.500000 + *gray* -0.418688 + *gray* -0.081312 + 128);edkEnd();
                        y++;edkEnd();
                        gray++;edkEnd();
                        u++;edkEnd();
                        v++;edkEnd();
                    }
                    //process the last pixel even
                    *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                    y++;edkEnd();
                    gray++;edkEnd();
                    //process the line odd
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                        y++;edkEnd();
                        gray++;edkEnd();
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                        y++;edkEnd();
                        gray++;edkEnd();
                    }
                    //process the last pixel odd
                    *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                    y++;edkEnd();
                    gray+=1u;edkEnd();
                }
                //process the last line odd
                for(j=0u;j<size.width;j+=2u){
                    *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                    y++;edkEnd();
                    gray++;edkEnd();
                    *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                    *u = (edk::uint8)(*gray * -0.168736 + *gray* -0.331264 + *gray *  0.500000 + 128);edkEnd();
                    *v = (edk::uint8)(*gray *  0.500000 + *gray* -0.418688 + *gray* -0.081312 + 128);edkEnd();
                    y++;edkEnd();
                    gray++;edkEnd();
                    u++;edkEnd();
                    v++;edkEnd();
                }
                //process the last pixel odd
                *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);edkEnd();
                y++;edkEnd();
                gray++;edkEnd();
            }
        }
        return true;
    }
    return false;
}
//YUV to RGB
edk::color3ui8 edk::codecs::CodecImage::yuvTorgb(edk::uint8 y,edk::uint8 u,edk::uint8 v){
    edk::float32 r,g,b;edkEnd();
    r = y + 1.4075 *                        (v - 128) ;edkEnd();
    g = y - 0.3455 * (u - 128) - (0.7169 * (v - 128));edkEnd();
    b = y + 1.7790 * (u - 128);edkEnd();

    if(r<0){
        r=0;
    }
    else if(r>255){
        r=255;edkEnd();
    }

    if(g<0) g=0;
    else if(g>255){
        g=255;edkEnd();
    }

    if(b<0) b=0;
    else if(b>255){
        b=255;edkEnd();
    }
    return edk::color3ui8(
                (edk::uint8)(r),
                (edk::uint8)(g),
                (edk::uint8)(b)
                );edkEnd();
}
edk::color3ui8 edk::codecs::CodecImage::yuvTorgb(edk::vec3ui8 color){
    return edk::codecs::CodecImage::yuvTorgb(color.x,color.y,color.z);edkEnd();
}
bool edk::codecs::CodecImage::i420Torgb(edk::uint8* y,edk::uint8* u,edk::uint8* v,edk::size2ui32 size,edk::uint8* rgb){
    if(rgb && size.width && size.height && y && u && v){
        edk::float32 r,g,b;edkEnd();
        //test the lenght (even or odd)
        if(!(size.width<<((sizeof(size.width)*8u)-1u))){
            //even
            if(!(size.height<<((sizeof(size.height)*8u)-1u))){
                //even

                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    for(j=0u;j<size.width;j+=2u){
                        r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                        b = *y + 1.7790 * (*u - 128);edkEnd();
                        if(r<0){
                            r=0;;edkEnd();
                        }
                        else if(r>255){
                            r=255;edkEnd();
                        }
                        if(g<0){
                            g=0;;edkEnd();
                        }
                        else if(g>255){
                            g=255;edkEnd();
                        }
                        if(b<0){
                            b=0;;edkEnd();
                        }
                        else if(b>255){
                            b=255;edkEnd();
                        }

                        rgb[0u]=(edk::uint8)r;edkEnd();
                        rgb[1u]=(edk::uint8)g;edkEnd();
                        rgb[2u]=(edk::uint8)b;edkEnd();

                        //increment the rgb and y
                        rgb+=3u;edkEnd();
                        y++;edkEnd();

                        r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                        b = *y + 1.7790 * (*u - 128);edkEnd();
                        if(r<0){
                            r=0;edkEnd();
                        }
                        else if(r>255){
                            r=255;edkEnd();
                        }
                        if(g<0){
                            g=0;edkEnd();
                        }
                        else if(g>255){
                            g=255;edkEnd();
                        }
                        if(b<0){
                            b=0;edkEnd();
                        }
                        else if(b>255){
                            b=255;edkEnd();
                        }

                        rgb[0u]=(edk::uint8)r;edkEnd();
                        rgb[1u]=(edk::uint8)g;edkEnd();
                        rgb[2u]=(edk::uint8)b;edkEnd();

                        //increment the rgb and y
                        rgb+=3u;edkEnd();
                        y++;edkEnd();
                        //increment the u v
                        u++;edkEnd();
                        v++;edkEnd();
                    }
                    //decrement the y
                    u-=size.width>>1;edkEnd();
                    v-=size.width>>1;edkEnd();
                    for(j=0u;j<size.width;j+=2u){
                        r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                        b = *y + 1.7790 * (*u - 128);edkEnd();
                        if(r<0){
                            r=0;edkEnd();
                        }
                        else if(r>255){
                            r=255;edkEnd();
                        }
                        if(g<0){
                            g=0;edkEnd();
                        }
                        else if(g>255){
                            g=255;edkEnd();
                        }
                        if(b<0){
                            b=0;edkEnd();
                        }
                        else if(b>255){
                            b=255;edkEnd();
                        }

                        rgb[0u]=(edk::uint8)r;edkEnd();
                        rgb[1u]=(edk::uint8)g;edkEnd();
                        rgb[2u]=(edk::uint8)b;edkEnd();

                        //increment the rgb and the y
                        rgb+=3u;edkEnd();
                        y++;edkEnd();

                        r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                        b = *y + 1.7790 * (*u - 128);edkEnd();
                        if(r<0){
                            r=0;edkEnd();
                        }
                        else if(r>255){
                            r=255;edkEnd();
                        }
                        if(g<0){
                            g=0;edkEnd();
                        }
                        else if(g>255){
                            g=255;edkEnd();
                        }
                        if(b<0){
                            b=0;edkEnd();
                        }
                        else if(b>255){
                            b=255;edkEnd();
                        }

                        rgb[0u]=(edk::uint8)r;edkEnd();
                        rgb[1u]=(edk::uint8)g;edkEnd();
                        rgb[2u]=(edk::uint8)b;edkEnd();

                        //increment the rgb and the y
                        rgb+=3u;edkEnd();
                        y++;edkEnd();
                        //increment the u v
                        u++;edkEnd();
                        v++;edkEnd();
                    }
                }
            }
            else{
                //odd
                size.height-=2u;edkEnd();
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    for(j=0u;j<size.width;j+=2u){
                        r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                        b = *y + 1.7790 * (*u - 128);edkEnd();
                        if(r<0){
                            r=0;edkEnd();
                        }
                        else if(r>255){
                            r=255;edkEnd();
                        }
                        if(g<0){
                            g=0;edkEnd();
                        }
                        else if(g>255){
                            g=255;edkEnd();
                        }
                        if(b<0){
                            b=0;edkEnd();
                        }
                        else if(b>255){
                            b=255;edkEnd();
                        }

                        rgb[0u]=(edk::uint8)r;edkEnd();
                        rgb[1u]=(edk::uint8)g;edkEnd();
                        rgb[2u]=(edk::uint8)b;edkEnd();

                        //increment the rgb and y
                        rgb+=3u;edkEnd();
                        y++;edkEnd();

                        r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                        b = *y + 1.7790 * (*u - 128);edkEnd();
                        if(r<0){
                            r=0;edkEnd();
                        }
                        else if(r>255){
                            r=255;edkEnd();
                        }
                        if(g<0){
                            g=0;edkEnd();
                        }
                        else if(g>255){
                            g=255;edkEnd();
                        }
                        if(b<0){
                            b=0;edkEnd();
                        }
                        else if(b>255){
                            b=255;edkEnd();
                        }

                        rgb[0u]=(edk::uint8)r;edkEnd();
                        rgb[1u]=(edk::uint8)g;edkEnd();
                        rgb[2u]=(edk::uint8)b;edkEnd();

                        //increment the rgb and y
                        rgb+=3u;edkEnd();
                        y++;edkEnd();
                        //increment the u v
                        u++;edkEnd();
                        v++;edkEnd();
                    }
                    //decrement the y
                    u-=size.width>>1;edkEnd();
                    v-=size.width>>1;edkEnd();
                    for(j=0u;j<size.width;j+=2u){
                        r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                        b = *y + 1.7790 * (*u - 128);edkEnd();
                        if(r<0){
                            r=0;edkEnd();
                        }
                        else if(r>255){
                            r=255;edkEnd();
                        }
                        if(g<0){
                            g=0;edkEnd();
                        }
                        else if(g>255){
                            g=255;edkEnd();
                        }
                        if(b<0){
                            b=0;edkEnd();
                        }
                        else if(b>255){
                            b=255;edkEnd();
                        }

                        rgb[0u]=(edk::uint8)r;edkEnd();
                        rgb[1u]=(edk::uint8)g;edkEnd();
                        rgb[2u]=(edk::uint8)b;edkEnd();

                        //increment the rgb and the y
                        rgb+=3u;edkEnd();
                        y++;edkEnd();

                        r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                        b = *y + 1.7790 * (*u - 128);edkEnd();
                        if(r<0){
                            r=0;edkEnd();
                        }
                        else if(r>255){
                            r=255;edkEnd();
                        }
                        if(g<0){
                            g=0;edkEnd();
                        }
                        else if(g>255){
                            g=255;edkEnd();
                        }
                        if(b<0){
                            b=0;edkEnd();
                        }
                        else if(b>255){
                            b=255;edkEnd();
                        }

                        rgb[0u]=(edk::uint8)r;edkEnd();
                        rgb[1u]=(edk::uint8)g;edkEnd();
                        rgb[2u]=(edk::uint8)b;edkEnd();

                        //increment the rgb and the y
                        rgb+=3u;edkEnd();
                        y++;edkEnd();
                        //increment the u v
                        u++;edkEnd();
                        v++;edkEnd();
                    }
                }
                //process the last line odd
                for(j=0u;j<size.width;j+=2u){
                    r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                    g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                    b = *y + 1.7790 * (*u - 128);edkEnd();
                    if(r<0){
                        r=0;edkEnd();
                    }
                    else if(r>255){
                        r=255;edkEnd();
                    }
                    if(g<0){
                        g=0;edkEnd();
                    }
                    else if(g>255){
                        g=255;edkEnd();
                    }
                    if(b<0){
                        b=0;edkEnd();
                    }
                    else if(b>255){
                        b=255;edkEnd();
                    }

                    rgb[0u]=(edk::uint8)r;edkEnd();
                    rgb[1u]=(edk::uint8)g;edkEnd();
                    rgb[2u]=(edk::uint8)b;edkEnd();

                    //increment the rgb and y
                    rgb+=3u;edkEnd();
                    y++;edkEnd();

                    r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                    g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                    b = *y + 1.7790 * (*u - 128);edkEnd();
                    if(r<0){
                        r=0;edkEnd();
                    }
                    else if(r>255){
                        r=255;edkEnd();
                    }
                    if(g<0){
                        g=0;edkEnd();
                    }
                    else if(g>255){
                        g=255;edkEnd();
                    }
                    if(b<0){
                        b=0;edkEnd();
                    }
                    else if(b>255){
                        b=255;edkEnd();
                    }

                    rgb[0u]=(edk::uint8)r;edkEnd();
                    rgb[1u]=(edk::uint8)g;edkEnd();
                    rgb[2u]=(edk::uint8)b;edkEnd();

                    //increment the rgb and y
                    rgb+=3u;edkEnd();
                    y++;edkEnd();
                    //increment the u v
                    u++;edkEnd();
                    v++;edkEnd();
                }
            }
        }
        else{
            //odd
            if(!(size.height<<((sizeof(size.height)*8u)-1u))){
                //even

                size.width-=2u;edkEnd();
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    for(j=0u;j<size.width;j+=2u){
                        r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                        b = *y + 1.7790 * (*u - 128);edkEnd();
                        if(r<0){
                            r=0;edkEnd();
                        }
                        else if(r>255){
                            r=255;edkEnd();
                        }
                        if(g<0){
                            g=0;edkEnd();
                        }
                        else if(g>255){
                            g=255;edkEnd();
                        }
                        if(b<0){
                            b=0;edkEnd();
                        }
                        else if(b>255){
                            b=255;edkEnd();
                        }

                        rgb[0u]=(edk::uint8)r;edkEnd();
                        rgb[1u]=(edk::uint8)g;edkEnd();
                        rgb[2u]=(edk::uint8)b;edkEnd();

                        //increment the rgb and y
                        rgb+=3u;edkEnd();
                        y++;edkEnd();

                        r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                        b = *y + 1.7790 * (*u - 128);edkEnd();
                        if(r<0){
                            r=0;edkEnd();
                        }
                        else if(r>255){
                            r=255;edkEnd();
                        }
                        if(g<0){
                            g=0;edkEnd();
                        }
                        else if(g>255){
                            g=255;edkEnd();
                        }
                        if(b<0){
                            b=0;edkEnd();
                        }
                        else if(b>255){
                            b=255;edkEnd();
                        }

                        rgb[0u]=(edk::uint8)r;edkEnd();
                        rgb[1u]=(edk::uint8)g;edkEnd();
                        rgb[2u]=(edk::uint8)b;edkEnd();

                        //increment the rgb and y
                        rgb+=3u;edkEnd();
                        y++;edkEnd();
                        //increment the u v
                        u++;edkEnd();
                        v++;edkEnd();
                    }
                    //process the last pixel odd
                    r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                    g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                    b = *y + 1.7790 * (*u - 128);edkEnd();
                    if(r<0){
                        r=0;edkEnd();
                    }
                    else if(r>255){
                        r=255;edkEnd();
                    }
                    if(g<0){
                        g=0;edkEnd();
                    }
                    else if(g>255){
                        g=255;edkEnd();
                    }
                    if(b<0){
                        b=0;edkEnd();
                    }
                    else if(b>255){
                        b=255;edkEnd();
                    }

                    rgb[0u]=(edk::uint8)r;edkEnd();
                    rgb[1u]=(edk::uint8)g;edkEnd();
                    rgb[2u]=(edk::uint8)b;edkEnd();

                    //increment the rgb and y
                    rgb+=3u;edkEnd();
                    y++;edkEnd();

                    //decrement the y
                    u-=(size.width>>1)+1u;edkEnd();
                    v-=(size.width>>1)+1u;edkEnd();
                    for(j=0u;j<size.width;j+=2u){
                        r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                        b = *y + 1.7790 * (*u - 128);edkEnd();
                        if(r<0){
                            r=0;edkEnd();
                        }
                        else if(r>255){
                            r=255;edkEnd();
                        }
                        if(g<0){
                            g=0;edkEnd();
                        }
                        else if(g>255){
                            g=255;edkEnd();
                        }
                        if(b<0){
                            b=0;edkEnd();
                        }
                        else if(b>255){
                            b=255;edkEnd();
                        }

                        rgb[0u]=(edk::uint8)r;edkEnd();
                        rgb[1u]=(edk::uint8)g;edkEnd();
                        rgb[2u]=(edk::uint8)b;edkEnd();

                        //increment the rgb and the y
                        rgb+=3u;edkEnd();
                        y++;edkEnd();

                        r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                        b = *y + 1.7790 * (*u - 128);edkEnd();
                        if(r<0){
                            r=0;edkEnd();
                        }
                        else if(r>255){
                            r=255;edkEnd();
                        }
                        if(g<0){
                            g=0;edkEnd();
                        }
                        else if(g>255){
                            g=255;edkEnd();
                        }
                        if(b<0){
                            b=0;edkEnd();
                        }
                        else if(b>255){
                            b=255;edkEnd();
                        }

                        rgb[0u]=(edk::uint8)r;edkEnd();
                        rgb[1u]=(edk::uint8)g;edkEnd();
                        rgb[2u]=(edk::uint8)b;edkEnd();

                        //increment the rgb and the y
                        rgb+=3u;edkEnd();
                        y++;edkEnd();
                        //increment the u v
                        u++;edkEnd();
                        v++;edkEnd();
                    }
                    //process the last pixel odd
                    r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                    g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                    b = *y + 1.7790 * (*u - 128);edkEnd();
                    if(r<0){
                        r=0;edkEnd();
                    }
                    else if(r>255){
                        r=255;edkEnd();
                    }
                    if(g<0){
                        g=0;edkEnd();
                    }
                    else if(g>255){
                        g=255;edkEnd();
                    }
                    if(b<0){
                        b=0;edkEnd();
                    }
                    else if(b>255){
                        b=255;edkEnd();
                    }

                    rgb[0u]=(edk::uint8)r;edkEnd();
                    rgb[1u]=(edk::uint8)g;edkEnd();
                    rgb[2u]=(edk::uint8)b;edkEnd();

                    //increment the rgb and the y
                    rgb+=3u;edkEnd();
                    y++;edkEnd();
                }
            }
            else{
                //odd

                size.width-=2u;edkEnd();
                size.height-=2u;edkEnd();
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    for(j=0u;j<size.width;j+=2u){
                        r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                        b = *y + 1.7790 * (*u - 128);edkEnd();
                        if(r<0){
                            r=0;edkEnd();
                        }
                        else if(r>255){
                            r=255;edkEnd();
                        }
                        if(g<0){
                            g=0;edkEnd();
                        }
                        else if(g>255){
                            g=255;edkEnd();
                        }
                        if(b<0){
                            b=0;edkEnd();
                        }
                        else if(b>255){
                            b=255;edkEnd();
                        }

                        rgb[0u]=(edk::uint8)r;edkEnd();
                        rgb[1u]=(edk::uint8)g;edkEnd();
                        rgb[2u]=(edk::uint8)b;edkEnd();

                        //increment the rgb and y
                        rgb+=3u;edkEnd();
                        y++;edkEnd();

                        r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                        b = *y + 1.7790 * (*u - 128);edkEnd();
                        if(r<0){
                            r=0;edkEnd();
                        }
                        else if(r>255){
                            r=255;edkEnd();
                        }
                        if(g<0){
                            g=0;edkEnd();
                        }
                        else if(g>255){
                            g=255;edkEnd();
                        }
                        if(b<0){
                            b=0;edkEnd();
                        }
                        else if(b>255){
                            b=255;edkEnd();
                        }

                        rgb[0u]=(edk::uint8)r;edkEnd();
                        rgb[1u]=(edk::uint8)g;edkEnd();
                        rgb[2u]=(edk::uint8)b;edkEnd();

                        //increment the rgb and y
                        rgb+=3u;edkEnd();
                        y++;edkEnd();
                        //increment the u v
                        u++;edkEnd();
                        v++;edkEnd();
                    }
                    //process the last pixel odd
                    r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                    g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                    b = *y + 1.7790 * (*u - 128);edkEnd();
                    if(r<0){
                        r=0;edkEnd();
                    }
                    else if(r>255){
                        r=255;edkEnd();
                    }
                    if(g<0){
                        g=0;edkEnd();
                    }
                    else if(g>255){
                        g=255;edkEnd();
                    }
                    if(b<0){
                        b=0;edkEnd();
                    }
                    else if(b>255){
                        b=255;edkEnd();
                    }

                    rgb[0u]=(edk::uint8)r;edkEnd();
                    rgb[1u]=(edk::uint8)g;edkEnd();
                    rgb[2u]=(edk::uint8)b;edkEnd();

                    //increment the rgb and y
                    rgb+=3u;edkEnd();
                    y++;edkEnd();

                    //decrement the y
                    u-=(size.width>>1)+1u;edkEnd();
                    v-=(size.width>>1)+1u;edkEnd();
                    for(j=0u;j<size.width;j+=2u){
                        r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                        b = *y + 1.7790 * (*u - 128);edkEnd();
                        if(r<0){
                            r=0;edkEnd();
                        }
                        else if(r>255){
                            r=255;edkEnd();
                        }
                        if(g<0){
                            g=0;edkEnd();
                        }
                        else if(g>255){
                            g=255;edkEnd();
                        }
                        if(b<0){
                            b=0;edkEnd();
                        }
                        else if(b>255){
                            b=255;edkEnd();
                        }

                        rgb[0u]=(edk::uint8)r;edkEnd();
                        rgb[1u]=(edk::uint8)g;edkEnd();
                        rgb[2u]=(edk::uint8)b;edkEnd();

                        //increment the rgb and the y
                        rgb+=3u;edkEnd();
                        y++;edkEnd();

                        r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                        b = *y + 1.7790 * (*u - 128);edkEnd();
                        if(r<0){
                            r=0;edkEnd();
                        }
                        else if(r>255){
                            r=255;edkEnd();
                        }
                        if(g<0){
                            g=0;edkEnd();
                        }
                        else if(g>255){
                            g=255;edkEnd();
                        }
                        if(b<0){
                            b=0;edkEnd();
                        }
                        else if(b>255){
                            b=255;edkEnd();
                        }

                        rgb[0u]=(edk::uint8)r;edkEnd();
                        rgb[1u]=(edk::uint8)g;edkEnd();
                        rgb[2u]=(edk::uint8)b;edkEnd();

                        //increment the rgb and the y
                        rgb+=3u;edkEnd();
                        y++;edkEnd();
                        //increment the u v
                        u++;edkEnd();
                        v++;edkEnd();
                    }
                    //process the last pixel odd
                    r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                    g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                    b = *y + 1.7790 * (*u - 128);edkEnd();
                    if(r<0){
                        r=0;edkEnd();
                    }
                    else if(r>255){
                        r=255;edkEnd();
                    }
                    if(g<0){
                        g=0;edkEnd();
                    }
                    else if(g>255){
                        g=255;edkEnd();
                    }
                    if(b<0){
                        b=0;edkEnd();
                    }
                    else if(b>255){
                        b=255;edkEnd();
                    }

                    rgb[0u]=(edk::uint8)r;edkEnd();
                    rgb[1u]=(edk::uint8)g;edkEnd();
                    rgb[2u]=(edk::uint8)b;edkEnd();

                    //increment the rgb and the y
                    rgb+=3u;edkEnd();
                    y++;edkEnd();

                }
                //process the last line odd
                for(j=0u;j<size.width;j+=2u){
                    r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                    g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                    b = *y + 1.7790 * (*u - 128);edkEnd();
                    if(r<0){
                        r=0;edkEnd();
                    }
                    else if(r>255){
                        r=255;edkEnd();
                    }
                    if(g<0){
                        g=0;edkEnd();
                    }
                    else if(g>255){
                        g=255;edkEnd();
                    }
                    if(b<0){
                        b=0;edkEnd();
                    }
                    else if(b>255){
                        b=255;edkEnd();
                    }

                    rgb[0u]=(edk::uint8)r;edkEnd();
                    rgb[1u]=(edk::uint8)g;edkEnd();
                    rgb[2u]=(edk::uint8)b;edkEnd();

                    //increment the rgb and y
                    rgb+=3u;edkEnd();
                    y++;edkEnd();

                    r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                    g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                    b = *y + 1.7790 * (*u - 128);edkEnd();
                    if(r<0){
                        r=0;edkEnd();
                    }
                    else if(r>255){
                        r=255;edkEnd();
                    }
                    if(g<0){
                        g=0;edkEnd();
                    }
                    else if(g>255){
                        g=255;edkEnd();
                    }
                    if(b<0){
                        b=0;edkEnd();
                    }
                    else if(b>255){
                        b=255;edkEnd();
                    }

                    rgb[0u]=(edk::uint8)r;edkEnd();
                    rgb[1u]=(edk::uint8)g;edkEnd();
                    rgb[2u]=(edk::uint8)b;edkEnd();

                    //increment the rgb and y
                    rgb+=3u;edkEnd();
                    y++;edkEnd();
                    //increment the u v
                    u++;edkEnd();
                    v++;edkEnd();
                }
                //process the last pixel odd
                r = *y + 1.4075 *                        (*v - 128) ;edkEnd();
                g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));edkEnd();
                b = *y + 1.7790 * (*u - 128);edkEnd();
                if(r<0){
                    r=0;edkEnd();
                }
                else if(r>255){
                    r=255;edkEnd();
                }
                if(g<0){
                    g=0;edkEnd();
                }
                else if(g>255){
                    g=255;edkEnd();
                }
                if(b<0){
                    b=0;edkEnd();
                }
                else if(b>255){
                    b=255;edkEnd();
                }

                rgb[0u]=(edk::uint8)r;edkEnd();
                rgb[1u]=(edk::uint8)g;edkEnd();
                rgb[2u]=(edk::uint8)b;edkEnd();

                //increment the rgb and y
                rgb+=3u;edkEnd();
                y++;edkEnd();

            }
        }
        return true;
    }
    return false;
}
