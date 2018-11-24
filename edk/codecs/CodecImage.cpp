#include "CodecImage.h"

/*
Library C++ codecs - Set the parameters use for the image codecs
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

#ifdef printMessages
#warning "            Inside CodecImage.cpp"
#endif

edk::codecs::CodecImage::CodecImage(){
    //printf("\nCodecImage Construtor");fflush(stdout);
    this->frame=NULL;
    this->encoded=NULL;
    this->frameSize = edk::size2ui32(0u,0u);
    this->encodedSize = 0u;
    this->encodedQuality = 0u;
    this->frameChannels = 0.f;
    this->vectorFrameSize=0u;
}

edk::codecs::CodecImage::~CodecImage(){
    //printf("\nCodecImage Destrutor");fflush(stdout);
    //delete the vectors
    this->deleteEncoded();
    this->deleteFrame();
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
            if(this->frame) return true;
        }
        //else create a new frame

        //first delete the last frame
        this->deleteFrame();

        //set the size of the vector frame
        this->vectorFrameSize = (edk::uint32)(size.width * size.height * channels);

        //create the new frame
        if(this->vectorFrameSize){
            if( ( this->frame = new edk::uint8[this->vectorFrameSize] ) ){
                //save the new size
                this->frameSize = size;
                this->frameChannels = channels;
                //return true
                return true;
            }
        }
    }
    //else delete the frame
    this->deleteFrame();
    //else return false
    return false;
}
bool edk::codecs::CodecImage::newFrame(edk::uint32 width,edk::uint32 height,edk::uint8 channels){
    return this->newFrame(edk::size2ui32(width,height),channels);
}
//delete the frame
void edk::codecs::CodecImage::deleteFrame(){
    //test if have the frame
    if(this->frame){
        delete[] this->frame;
        this->frame=NULL;
    }
    //clean the size
    this->frameSize = edk::size2ui32(0u,0u);
    this->frameChannels=0.f;
    this->vectorFrameSize=0u;
}
//alloc a new frameEncoded
bool edk::codecs::CodecImage::newFrameEncoded(edk::uint32 size){
    //test the size of the frameEncoded
    if(size){
        //test if the size is are the same
        if(this->encodedSize == size){
            //return true if have the encoded
            if(this->encoded) return true;
        }
        //else delete the last encoded
        this->deleteEncoded();

        //create a new encoded
        if((this->encoded = new edk::uint8[size])){
            //save the encodedSize
            this->encodedSize = size;
            return true;
        }
    }
    //else delete the encoded
    this->deleteEncoded();
    return false;
}
//delete the encoded
void edk::codecs::CodecImage::deleteEncoded(){
    //test if have the encoded
    if(this->encoded){
        delete[] this->encoded;
        this->encoded=NULL;
    }
    //clean the size
    this->encodedSize = 0u;
}

//draw a image in the frame
bool edk::codecs::CodecImage::drawFrame(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels){
    //create a new frame
    if(this->newFrame(size,channels)){
        //copy the frame
        memcpy(this->frame,frame,this->vectorFrameSize);
        //then return true
        return true;
    }
    return false;
}
bool edk::codecs::CodecImage::drawFrame(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels){
    return this->drawFrame(frame,edk::size2ui32(width,height),channels);
}
//write in the frame encoded
bool edk::codecs::CodecImage::writeEncoded(edk::uint8* frame){
    //test if have the frameEncoded
    if(this->encoded && this->encodedSize){
        //copy the frame
        memcpy(this->encoded,frame,this->encodedSize);
        return true;
    }
    return false;
}
//set the quality
bool edk::codecs::CodecImage::setQuality(edk::uint32 quality){
    //clean the quality
    this->encodedQuality=1u;
    if(quality){
        this->encodedQuality=quality;
        return true;
    }
    return false;
}
//get the frames
edk::uint8* edk::codecs::CodecImage::getFrame(){
    return this->frame;
}
edk::uint8* edk::codecs::CodecImage::getEncoded(){
    return this->encoded;
}
edk::uint8** edk::codecs::CodecImage::getEncodedPosition(){
    return &this->encoded;
}

//clean the pointers
edk::uint8* edk::codecs::CodecImage::cleanFrame(){
    edk::uint8* ret = this->frame;

    this->frame=NULL;
    //clean the size
    this->frameSize = edk::size2ui32(0u,0u);
    this->frameChannels=0u;
    this->vectorFrameSize=0u;

    return ret;
}
edk::uint8* edk::codecs::CodecImage::cleanEncoded(){
    edk::uint8* ret = this->encoded;

    this->encoded=NULL;
    //clean the size
    this->encodedSize = 0u;

    return ret;
}

//return the size of the frame
edk::size2ui32 edk::codecs::CodecImage::getFrameSize(){
    return this->frameSize;
}
edk::uint32 edk::codecs::CodecImage::getFrameWidth(){
    return this->frameSize.width;
}
edk::uint32 edk::codecs::CodecImage::getFrameHeight(){
    return this->frameSize.height;
}
edk::uint32 edk::codecs::CodecImage::getFrameChannels(){
    return this->frameChannels;
}
edk::uint32 edk::codecs::CodecImage::getFrameVectorSize(){
    return this->vectorFrameSize;
}
//return the size of the encoded
edk::uint32 edk::codecs::CodecImage::getEncodedSize(){
    return this->encodedSize;
}
edk::uint32* edk::codecs::CodecImage::getEncodedSizePosition(){
    return &this->encodedSize;
}
edk::uint32 edk::codecs::CodecImage::getQuality(){
    return this->encodedQuality;
}


//Convertions
//RGB to HSV
edk::color3f32 edk::codecs::CodecImage::rgbTohsv(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    edk::color3f32 hsv;
    edk::float32 min, max, delta;

    min = r < g ? r : g;
    min = min  < b ? min  : b;

    max = r > g ? r : g;
    max = max  > b ? max  : b;

    hsv.b = max/255; // v
    //hsv.b = max*0.003921569; // v


    delta = max - min;
    if( max > 0.f ) { // NOTE: if Max is == 0, this divide would cause a crash
        hsv.g = (delta / max);// s
    } else {
        // if max is 0, then r = g = b = 0
        // s = 0, v is undefined
        hsv.g = 0.f; // s
        hsv.r = 0.f;//NAN; // h its now undefined
        return hsv;
    }

    if(delta){
        if( r >= max )                        // > is bogus, just keeps compilor happy
            hsv.r = ( g - b ) / delta;        // between yellow & magenta
        else
            if( g >= max )
                hsv.r = 2.0 + ( b - r ) / delta;  // between cyan & yellow
            else
                hsv.r = 4.0 + ( r - g ) / delta;  // between magenta & cyan

        hsv.r *= 60.0;                              // degrees

        if( hsv.r  < 0.0 )
            hsv.r  += 360.0;
    }
    else
        hsv.r=0.f;

    return hsv;
}
edk::color3f32 edk::codecs::CodecImage::rgbTohsv(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbTohsv(rgb.r,rgb.g,rgb.b);
}
edk::color3f32 edk::codecs::CodecImage::rgbTohsv(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbTohsv(rgba.r,rgba.g,rgba.b);
}
edk::uint8 edk::codecs::CodecImage::rgbToV(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    edk::uint8 max;

    max = r > g ? r : g;
    max = max  > b ? max  : b;

    return max; // v
}
edk::uint8 edk::codecs::CodecImage::rgbToV(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbToV(rgb.r,rgb.g,rgb.b);
}
edk::uint8 edk::codecs::CodecImage::rgbaToV(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbToV(rgba.r,rgba.g,rgba.b);
}
//vector
bool edk::codecs::CodecImage::rgbToV(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    if(vector && size.width && size.height && dest){
        edk::uint32 vecSize = size.width * size.height;
        for(edk::uint32 i=0u;i<vecSize;i++){
            *dest = edk::codecs::CodecImage::rgbToV(vector[0u],vector[1u],vector[2u]);

            vector+=3u;
            dest++;
        }
        return true;
    }
    return false;
}
edk::uint8* edk::codecs::CodecImage::rgbToV(edk::uint8* vector,edk::size2ui32 size){
    if(vector && size.width && size.height){
        edk::uint32 vecSize = size.width * size.height;
        //create the return
        edk::uint8* ret = new edk::uint8[vecSize];
        if(ret){
            if(edk::codecs::CodecImage::rgbToV(vector,size,ret)){
                return ret;
            }
            //
            delete[] ret;
        }
    }
    return NULL;
}
bool edk::codecs::CodecImage::rgbToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbToV(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* edk::codecs::CodecImage::rgbToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbToV(vector,edk::size2ui32(width,height));
}
bool edk::codecs::CodecImage::rgbaToV(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    if(vector && size.width && size.height && dest){
        edk::uint32 vecSize = size.width * size.height;
        for(edk::uint32 i=0u;i<vecSize;i++){
            *dest = edk::codecs::CodecImage::rgbToV(vector[0u],vector[1u],vector[2u]);

            vector+=4u;
            dest++;
        }
        return true;
    }
    return false;
}
edk::uint8* edk::codecs::CodecImage::rgbaToV(edk::uint8* vector,edk::size2ui32 size){
    if(vector && size.width && size.height){
        edk::uint32 vecSize = size.width * size.height;
        //create the return
        edk::uint8* ret = new edk::uint8[vecSize];
        if(ret){
            if(edk::codecs::CodecImage::rgbaToV(vector,size,ret)){
                return ret;
            }
            //
            delete[] ret;
        }
    }
    return NULL;
}
bool edk::codecs::CodecImage::rgbaToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbaToV(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* edk::codecs::CodecImage::rgbaToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbaToV(vector,edk::size2ui32(width,height));
}
//HSV to RGB
edk::color3ui8 edk::codecs::CodecImage::hsvTorgb(edk::float32 h,edk::float32 s,edk::float32 v){
    edk::color3ui8 rgb;

    v*=255;

    edk::float64      hh, p, q, t, ff;
    edk::int64        i;

    if(s <= 0.0) {       // < is bogus, just shuts up warnings
        rgb.r = v;
        rgb.g = v;
        rgb.b = v;
        return rgb;
    }
    hh = h;
    if(hh >= 360.0) hh = 0.0;
    hh /= 60.0;
    i = (edk::int64)hh;
    ff = hh - i;
    p = v * (1.0 -  s);
    q = v * (1.0 - (s * ff));
    t = v * (1.0 - (s * (1.0 - ff)));

    switch(i) {
    case 0:
        rgb.r = v;
        rgb.g = t;
        rgb.b = p;
        break;
    case 1:
        rgb.r = q;
        rgb.g = v;
        rgb.b = p;
        break;
    case 2:
        rgb.r = p;
        rgb.g = v;
        rgb.b = t;
        break;

    case 3:
        rgb.r = p;
        rgb.g = q;
        rgb.b = v;
        break;
    case 4:
        rgb.r = t;
        rgb.g = p;
        rgb.b = v;
        break;
    case 5:
    default:
        rgb.r = v;
        rgb.g = p;
        rgb.b = q;
        break;
    }

    return rgb;
}
edk::color3ui8 edk::codecs::CodecImage::hsvTorgb(edk::color3f32 hsv){
    return edk::codecs::CodecImage::hsvTorgb(hsv.r,hsv.g,hsv.b);
}
//RGB to HSL
edk::color3f32 edk::codecs::CodecImage::rgbTohsl(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    edk::color3f32 hsl;
    edk::float32 dr = r/255.f,dg = g/255.f,db = b/255.f;
    edk::float64 min, max;

    min = dr < dg ? dr : dg;
    min = min  < db ? min  : db;

    max = dr > dg ? dr : dg;
    max = max  > db ? max  : db;

    hsl.b = (max + min) / 2.f; // l

    if(max == min){
        hsl.r = hsl.g= 0; // achromatic
    }else{
        edk::float64  delta = max - min;
        hsl.g = hsl.b > 0.5f ? delta / (2.f - max - min) : delta / (max + min);

        if(delta){
            if(max==dr){
                hsl.r = (dg - db) / delta + (dg < db ? 6.f : 0.f);
            }
            else if(max==dg)
                hsl.r = (db - dr) / delta + 2.f;
            else if(max==db)
                hsl.r = (dr - dg) / delta + 4.f;

            hsl.r/= 6.f;
            //hsl.r*=360.f;
        }
        else{
            hsl.r=0.f;
        }
    }
    return hsl;
}
edk::color3f32 edk::codecs::CodecImage::rgbTohsl(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbTohsl(rgb.r,rgb.g,rgb.b);
}
edk::color3f32 edk::codecs::CodecImage::rgbaTohsl(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbTohsl(rgba.r,rgba.g,rgba.b);
}
edk::float32 edk::codecs::CodecImage::rgbToL(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    //
    edk::float32 dr = r/255.f,dg = g/255.f,db = b/255.f;
    edk::float32 min, max;

    min = dr < dg ? dr : dg;
    min = min  < db ? min  : db;

    max = dr > dg ? dr : dg;
    max = max  > db ? max  : db;

    return (max + min) / 2.f; // l
}
edk::float32 edk::codecs::CodecImage::rgbToL(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbToL(rgb.r,rgb.g,rgb.b);
}
edk::float32 edk::codecs::CodecImage::rgbaToL(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbToL(rgba.r,rgba.g,rgba.b);
}
edk::uint8 edk::codecs::CodecImage::rgbToLui8(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return (edk::uint8)(edk::codecs::CodecImage::rgbToL(r,g,b) * 255.f);
}
edk::uint8 edk::codecs::CodecImage::rgbToLui8(edk::color3ui8 rgb){
    return edk::codecs::CodecImage::rgbToLui8(rgb.r,rgb.g,rgb.b);
}
edk::uint8 edk::codecs::CodecImage::rgbaToLui8(edk::color4ui8 rgba){
    return edk::codecs::CodecImage::rgbToLui8(rgba.r,rgba.g,rgba.b);
}
//vector
bool edk::codecs::CodecImage::rgbToLui8(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    if(vector && size.width && size.height && dest){
        edk::uint32 vecSize = size.width * size.height;
        for(edk::uint32 i=0u;i<vecSize;i++){
            *dest = edk::codecs::CodecImage::rgbToLui8(vector[0u],vector[1u],vector[2u]);

            vector+=3u;
            dest++;
        }
        return true;
    }
    return false;
}
edk::uint8* edk::codecs::CodecImage::rgbToLui8(edk::uint8* vector,edk::size2ui32 size){
    if(vector && size.width && size.height){
        edk::uint32 vecSize = size.width * size.height;
        //create the return
        edk::uint8* ret = new edk::uint8[vecSize];
        if(ret){
            if(edk::codecs::CodecImage::rgbToLui8(vector,size,ret)){
                return ret;
            }
            //
            delete[] ret;
        }
        ret=NULL;
    }
    return NULL;
}
bool edk::codecs::CodecImage::rgbToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbToLui8(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* edk::codecs::CodecImage::rgbToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbToLui8(vector,edk::size2ui32(width,height));
}
bool edk::codecs::CodecImage::rgbaToLui8(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest){
    if(vector && size.width && size.height && dest){
        edk::uint32 vecSize = size.width * size.height;
        for(edk::uint32 i=0u;i<vecSize;i++){
            *dest = edk::codecs::CodecImage::rgbToLui8(vector[0u],vector[1u],vector[2u]);

            vector+=4u;
            dest++;
        }
        return true;
    }
    return false;
}
edk::uint8* edk::codecs::CodecImage::rgbaToLui8(edk::uint8* vector,edk::size2ui32 size){
    if(vector && size.width && size.height){
        edk::uint32 vecSize = size.width * size.height;
        //create the return
        edk::uint8* ret = new edk::uint8[vecSize];
        if(ret){
            if(edk::codecs::CodecImage::rgbaToLui8(vector,size,ret)){
                return ret;
            }
            //
            delete[] ret;
        }
        ret=NULL;
    }
    return NULL;
}
bool edk::codecs::CodecImage::rgbaToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest){
    return edk::codecs::CodecImage::rgbaToLui8(vector,edk::size2ui32(width,height),dest);
}
edk::uint8* edk::codecs::CodecImage::rgbaToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height){
    return edk::codecs::CodecImage::rgbaToLui8(vector,edk::size2ui32(width,height));
}
//HSL to RGB
inline edk::float32 EDKhue2rgb(edk::float32 p, edk::float32 q, edk::float32 t){
    if(t < 0.f) t += 1.f;
    if(t > 1.f) t -= 1.f;
    if(t < 1.f/6.f) return p + (q - p) * 6.f * t;
    if(t < 1.f/2.f) return q;
    if(t < 2.f/3.f) return p + (q - p) * (2.f/3.f - t) * 6.f;
    return p;
}
edk::color3ui8 edk::codecs::CodecImage::hslTorgb(edk::float32 h,edk::float32 s,edk::float32 l){

    edk::float32 r,g,b;


    if(s == 0.f){
        r = g = b = l; // achromatic
    }else{
        edk::float32 q = l < 0.5f ? l * (1.f + s) : l + s - l * s;
        edk::float32 p = 2.f * l - q;
        r = EDKhue2rgb(p, q, h + (1.f/3.f));
        g = EDKhue2rgb(p, q, h);
        b = EDKhue2rgb(p, q, h - (1.f/3.f));
    }
    edk::color3ui8 rgb((edk::uint8)(r*255.f),
                       (edk::uint8)(g*255.f),
                       (edk::uint8)(b*255.f)
                       );
    /*
    if((r-rgb.r)>0.5f){
        rgb.r++;
    }
    if((g-rgb.g)>0.5f){
        rgb.g++;
    }
    if((b-rgb.b)>0.5f){
        rgb.b++;
    }
*/
    return rgb;
}
edk::color3ui8 edk::codecs::CodecImage::hslTorgb(edk::color3f32 hsl){
    return edk::codecs::CodecImage::hslTorgb(hsl.r,hsl.g,hsl.b);
}
//RGB to YUV
edk::vec3ui8 edk::codecs::CodecImage::rgbToyuv(edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return edk::vec3ui8(
                (edk::uint8)(r *  0.299000 + g *  0.587000 + b *  0.114000),
                (edk::uint8)(r * -0.168736 + g * -0.331264 + b *  0.500000 + 128),
                (edk::uint8)(r *  0.500000 + g * -0.418688 + b * -0.081312 + 128)
                );
}
edk::vec3ui8 edk::codecs::CodecImage::rgbToyuv(edk::color3ui8 color){
    return edk::codecs::CodecImage::rgbToyuv(color.r,color.g,color.b);
}
edk::vec3ui8 grayToyuv(edk::uint8 gray){
    return edk::vec3ui8(
                (edk::uint8)(gray *  0.299000 + gray *  0.587000 + gray *  0.114000),
                (edk::uint8)(gray * -0.168736 + gray * -0.331264 + gray *  0.500000 + 128),
                (edk::uint8)(gray *  0.500000 + gray * -0.418688 + gray * -0.081312 + 128)
                );
}
//vector
bool edk::codecs::CodecImage::rgbToyuv(edk::uint8* rgb,edk::size2ui32 size,edk::uint8* yuv){
    if(rgb && size.width && size.height && yuv){
        edk::uint32 vecSize = size.width * size.height;
        for(edk::uint32 i=0u;i<vecSize;i++){
            yuv[0u] = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
            yuv[1u] = (edk::uint8)(rgb[0u] * -0.168736 + rgb[1u]* -0.331264 + rgb[2u] *  0.500000 + 128);
            yuv[2u] = (edk::uint8)(rgb[0u] *  0.500000 + rgb[1u]* -0.418688 + rgb[2u]* -0.081312 + 128);

            rgb+=3u;
            yuv+=3u;
        }
        return true;
    }
    return false;
}
bool edk::codecs::CodecImage::rgbToyuv(edk::uint8* rgb,edk::size2ui32 size,edk::uint8* y,edk::uint8* u,edk::uint8* v){
    if(rgb && size.width && size.height && y && u && v){
        edk::uint32 vecSize = size.width * size.height;
        for(edk::uint32 i=0u;i<vecSize;i++){
            *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u] *  0.587000 + rgb[2u] *  0.114000);
            *u = (edk::uint8)(rgb[0u] * -0.168736 + rgb[1u] * -0.331264 + rgb[2u] *  0.500000 + 128);
            *v = (edk::uint8)(rgb[0u] *  0.500000 + rgb[1u] * -0.418688 + rgb[2u]* -0.081312 + 128);

            rgb+=3u;
            y++;
            u++;
            v++;
        }
        return true;
    }
    return false;
}
bool edk::codecs::CodecImage::grayToyuv(edk::uint8* gray,edk::size2ui32 size,edk::uint8* y,edk::uint8* u,edk::uint8* v){
    if(gray && size.width && size.height && y && u && v){
        edk::uint32 vecSize = size.width * size.height;
        for(edk::uint32 i=0u;i<vecSize;i++){
            *y = (edk::uint8)(*gray *  0.299000 + *gray *  0.587000 + *gray *  0.114000);
            *u = (edk::uint8)(*gray * -0.168736 + *gray * -0.331264 + *gray *  0.500000 + 128);
            *v = (edk::uint8)(*gray *  0.500000 + *gray * -0.418688 + *gray * -0.081312 + 128);

            gray++;
            y++;
            u++;
            v++;
        }
        return true;
    }
    return false;
}
bool edk::codecs::CodecImage::rgbToi240(edk::uint8* rgb,edk::size2ui32 size,edk::uint8* y,edk::uint8* u,edk::uint8* v){
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
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                        y++;
                        rgb+=3u;
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                        *u = (edk::uint8)(rgb[0u] * -0.168736 + rgb[1u]* -0.331264 + rgb[2u] *  0.500000 + 128);
                        *v = (edk::uint8)(rgb[0u] *  0.500000 + rgb[1u]* -0.418688 + rgb[2u]* -0.081312 + 128);
                        y++;
                        rgb+=3u;
                        u++;
                        v++;
                    }
                    //process the line odd
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                        y++;
                        rgb+=3u;
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                        y++;
                        rgb+=3u;
                    }
                }
            }
            else{
                //odd

                //run the algorith for height-2 because the counter go twice
                size.height-=2u;
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    //process the line even
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                        y++;
                        rgb+=3u;
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                        *u = (edk::uint8)(rgb[0u] * -0.168736 + rgb[1u]* -0.331264 + rgb[2u] *  0.500000 + 128);
                        *v = (edk::uint8)(rgb[0u] *  0.500000 + rgb[1u]* -0.418688 + rgb[2u]* -0.081312 + 128);
                        y++;
                        rgb+=3u;
                        u++;
                        v++;
                    }
                    //process the line odd
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                        y++;
                        rgb+=3u;
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                        y++;
                        rgb+=3u;
                    }
                }
                //process the last odd line
                for(j=0u;j<size.width;j+=2u){
                    *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                    y++;
                    rgb+=3u;
                    *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                    *u = (edk::uint8)(rgb[0u] * -0.168736 + rgb[1u]* -0.331264 + rgb[2u] *  0.500000 + 128);
                    *v = (edk::uint8)(rgb[0u] *  0.500000 + rgb[1u]* -0.418688 + rgb[2u]* -0.081312 + 128);
                    y++;
                    rgb+=3u;
                    u++;
                    v++;
                }
            }
        }
        else{
            //odd
            if(!(size.height<<((sizeof(size.height)*8u)-1u))){
                //even

                //run the algorith for width-2 because the counter go twice
                size.width-=2u;
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    //start the line even
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                        y++;
                        rgb+=3u;
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                        *u = (edk::uint8)(rgb[0u] * -0.168736 + rgb[1u]* -0.331264 + rgb[2u] *  0.500000 + 128);
                        *v = (edk::uint8)(rgb[0u] *  0.500000 + rgb[1u]* -0.418688 + rgb[2u]* -0.081312 + 128);
                        y++;
                        rgb+=3u;
                        u++;
                        v++;
                    }
                    //process the last pixel odd
                    *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                    y++;
                    rgb+=3u;
                    //start the line odd
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                        y++;
                        rgb+=3u;
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                        y++;
                        rgb+=3u;
                    }
                    //process the last pixel odd
                    *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                    y++;
                    rgb+=3u;
                }
            }
            else{
                //odd

                //run the algorith for width-2 and heigth-2 because the counter go twice
                size.height-=2u;
                size.width-=2u;
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    //process the line even
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                        y++;
                        rgb+=3u;
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                        *u = (edk::uint8)(rgb[0u] * -0.168736 + rgb[1u]* -0.331264 + rgb[2u] *  0.500000 + 128);
                        *v = (edk::uint8)(rgb[0u] *  0.500000 + rgb[1u]* -0.418688 + rgb[2u]* -0.081312 + 128);
                        y++;
                        rgb+=3u;
                        u++;
                        v++;
                    }
                    //process the last pixel even
                    *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                    y++;
                    rgb+=3u;
                    //process the line odd
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                        y++;
                        rgb+=3u;
                        *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                        y++;
                        rgb+=3u;
                    }
                    //process the last pixel odd
                    *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                    y++;
                    rgb+=3u;
                }
                //process the last line odd
                for(j=0u;j<size.width;j+=2u){
                    *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                    y++;
                    rgb+=3u;
                    *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                    *u = (edk::uint8)(rgb[0u] * -0.168736 + rgb[1u]* -0.331264 + rgb[2u] *  0.500000 + 128);
                    *v = (edk::uint8)(rgb[0u] *  0.500000 + rgb[1u]* -0.418688 + rgb[2u]* -0.081312 + 128);
                    y++;
                    rgb+=3u;
                    u++;
                    v++;
                }
                //process the last pixel odd
                *y = (edk::uint8)(rgb[0u] *  0.299000 + rgb[1u]*  0.587000 + rgb[2u] *  0.114000);
                y++;
                rgb+=3u;
            }
        }
        return true;
    }
    return false;
}
bool edk::codecs::CodecImage::grayToi240(edk::uint8* gray,edk::size2ui32 size,edk::uint8* y,edk::uint8* u,edk::uint8* v){
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
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                        y++;
                        gray++;
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                        *u = (edk::uint8)(*gray * -0.168736 + *gray* -0.331264 + *gray *  0.500000 + 128);
                        *v = (edk::uint8)(*gray *  0.500000 + *gray* -0.418688 + *gray* -0.081312 + 128);
                        y++;
                        gray++;
                        u++;
                        v++;
                    }
                    //process the line odd
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                        y++;
                        gray++;
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                        y++;
                        gray++;
                    }
                }
            }
            else{
                //odd

                //run the algorith for height-2 because the counter go twice
                size.height-=2u;
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    //process the line even
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                        y++;
                        gray++;
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                        *u = (edk::uint8)(*gray * -0.168736 + *gray* -0.331264 + *gray *  0.500000 + 128);
                        *v = (edk::uint8)(*gray *  0.500000 + *gray* -0.418688 + *gray* -0.081312 + 128);
                        y++;
                        gray++;
                        u++;
                        v++;
                    }
                    //process the line odd
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                        y++;
                        gray++;
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                        y++;
                        gray++;
                    }
                }
                //process the last odd line
                for(j=0u;j<size.width;j+=2u){
                    *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                    y++;
                    gray++;
                    *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                    *u = (edk::uint8)(*gray * -0.168736 + *gray* -0.331264 + *gray *  0.500000 + 128);
                    *v = (edk::uint8)(*gray *  0.500000 + *gray* -0.418688 + *gray* -0.081312 + 128);
                    y++;
                    gray++;
                    u++;
                    v++;
                }
            }
        }
        else{
            //odd
            if(!(size.height<<((sizeof(size.height)*8u)-1u))){
                //even

                //run the algorith for width-2 because the counter go twice
                size.width-=2u;
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    //start the line even
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                        y++;
                        gray++;
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                        *u = (edk::uint8)(*gray * -0.168736 + *gray* -0.331264 + *gray *  0.500000 + 128);
                        *v = (edk::uint8)(*gray *  0.500000 + *gray* -0.418688 + *gray* -0.081312 + 128);
                        y++;
                        gray++;
                        u++;
                        v++;
                    }
                    //process the last pixel odd
                    *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                    y++;
                    gray++;
                    //start the line odd
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                        y++;
                        gray++;
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                        y++;
                        gray++;
                    }
                    //process the last pixel odd
                    *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                    y++;
                    gray++;
                }
            }
            else{
                //odd

                //run the algorith for width-2 and heigth-2 because the counter go twice
                size.height-=2u;
                size.width-=2u;
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    //process the line even
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                        y++;
                        gray++;
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                        *u = (edk::uint8)(*gray * -0.168736 + *gray* -0.331264 + *gray *  0.500000 + 128);
                        *v = (edk::uint8)(*gray *  0.500000 + *gray* -0.418688 + *gray* -0.081312 + 128);
                        y++;
                        gray++;
                        u++;
                        v++;
                    }
                    //process the last pixel even
                    *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                    y++;
                    gray++;
                    //process the line odd
                    for(j=0u;j<size.width;j+=2u){
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                        y++;
                        gray++;
                        *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                        y++;
                        gray++;
                    }
                    //process the last pixel odd
                    *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                    y++;
                    gray+=1u;
                }
                //process the last line odd
                for(j=0u;j<size.width;j+=2u){
                    *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                    y++;
                    gray++;
                    *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                    *u = (edk::uint8)(*gray * -0.168736 + *gray* -0.331264 + *gray *  0.500000 + 128);
                    *v = (edk::uint8)(*gray *  0.500000 + *gray* -0.418688 + *gray* -0.081312 + 128);
                    y++;
                    gray++;
                    u++;
                    v++;
                }
                //process the last pixel odd
                *y = (edk::uint8)(*gray *  0.299000 + *gray*  0.587000 + *gray *  0.114000);
                y++;
                gray++;
            }
        }
        return true;
    }
    return false;
}
//YUV to RGB
edk::color3ui8 edk::codecs::CodecImage::yuvTorgb(edk::uint8 y,edk::uint8 u,edk::uint8 v){
    edk::float32 r,g,b;
    r = y + 1.4075 *                        (v - 128) ;
    g = y - 0.3455 * (u - 128) - (0.7169 * (v - 128));
    b = y + 1.7790 * (u - 128);

    if (r<0) r=0;
    else if (r>255) r=255;

    if (g<0) g=0;
    else if (g>255) g=255;

    if (b<0) b=0;
    else if (b>255) b=255;
    return edk::color3ui8(
                (edk::uint8)(r),
                (edk::uint8)(g),
                (edk::uint8)(b)
                );
}
edk::color3ui8 edk::codecs::CodecImage::yuvTorgb(edk::vec3ui8 color){
    return edk::codecs::CodecImage::yuvTorgb(color.x,color.y,color.z);
}
bool edk::codecs::CodecImage::i240Torgb(edk::uint8* y,edk::uint8* u,edk::uint8* v,edk::size2ui32 size,edk::uint8* rgb){
    if(rgb && size.width && size.height && y && u && v){
        edk::float32 r,g,b;
        //test the lenght (even or odd)
        if(!(size.width<<((sizeof(size.width)*8u)-1u))){
            //even
            if(!(size.height<<((sizeof(size.height)*8u)-1u))){
                //even

                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    for(j=0u;j<size.width;j+=2u){
                        r = *y + 1.4075 *                        (*v - 128) ;
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                        b = *y + 1.7790 * (*u - 128);
                        if (r<0) r=0;
                        else if (r>255) r=255;
                        if (g<0) g=0;
                        else if (g>255) g=255;
                        if (b<0) b=0;
                        else if (b>255) b=255;

                        rgb[0u]=(edk::uint8)r;
                        rgb[1u]=(edk::uint8)g;
                        rgb[2u]=(edk::uint8)b;

                        //increment the rgb and y
                        rgb+=3u;
                        y++;

                        r = *y + 1.4075 *                        (*v - 128) ;
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                        b = *y + 1.7790 * (*u - 128);
                        if (r<0) r=0;
                        else if (r>255) r=255;
                        if (g<0) g=0;
                        else if (g>255) g=255;
                        if (b<0) b=0;
                        else if (b>255) b=255;

                        rgb[0u]=(edk::uint8)r;
                        rgb[1u]=(edk::uint8)g;
                        rgb[2u]=(edk::uint8)b;

                        //increment the rgb and y
                        rgb+=3u;
                        y++;
                        //increment the u v
                        u++;
                        v++;
                    }
                    //decrement the y
                    u-=size.width>>1;
                    v-=size.width>>1;
                    for(j=0u;j<size.width;j+=2u){
                        r = *y + 1.4075 *                        (*v - 128) ;
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                        b = *y + 1.7790 * (*u - 128);
                        if (r<0) r=0;
                        else if (r>255) r=255;
                        if (g<0) g=0;
                        else if (g>255) g=255;
                        if (b<0) b=0;
                        else if (b>255) b=255;

                        rgb[0u]=(edk::uint8)r;
                        rgb[1u]=(edk::uint8)g;
                        rgb[2u]=(edk::uint8)b;

                        //increment the rgb and the y
                        rgb+=3u;
                        y++;

                        r = *y + 1.4075 *                        (*v - 128) ;
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                        b = *y + 1.7790 * (*u - 128);
                        if (r<0) r=0;
                        else if (r>255) r=255;
                        if (g<0) g=0;
                        else if (g>255) g=255;
                        if (b<0) b=0;
                        else if (b>255) b=255;

                        rgb[0u]=(edk::uint8)r;
                        rgb[1u]=(edk::uint8)g;
                        rgb[2u]=(edk::uint8)b;

                        //increment the rgb and the y
                        rgb+=3u;
                        y++;
                        //increment the u v
                        u++;
                        v++;
                    }
                }
            }
            else{
                //odd
                size.height-=2u;
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    for(j=0u;j<size.width;j+=2u){
                        r = *y + 1.4075 *                        (*v - 128) ;
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                        b = *y + 1.7790 * (*u - 128);
                        if (r<0) r=0;
                        else if (r>255) r=255;
                        if (g<0) g=0;
                        else if (g>255) g=255;
                        if (b<0) b=0;
                        else if (b>255) b=255;

                        rgb[0u]=(edk::uint8)r;
                        rgb[1u]=(edk::uint8)g;
                        rgb[2u]=(edk::uint8)b;

                        //increment the rgb and y
                        rgb+=3u;
                        y++;

                        r = *y + 1.4075 *                        (*v - 128) ;
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                        b = *y + 1.7790 * (*u - 128);
                        if (r<0) r=0;
                        else if (r>255) r=255;
                        if (g<0) g=0;
                        else if (g>255) g=255;
                        if (b<0) b=0;
                        else if (b>255) b=255;

                        rgb[0u]=(edk::uint8)r;
                        rgb[1u]=(edk::uint8)g;
                        rgb[2u]=(edk::uint8)b;

                        //increment the rgb and y
                        rgb+=3u;
                        y++;
                        //increment the u v
                        u++;
                        v++;
                    }
                    //decrement the y
                    u-=size.width>>1;
                    v-=size.width>>1;
                    for(j=0u;j<size.width;j+=2u){
                        r = *y + 1.4075 *                        (*v - 128) ;
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                        b = *y + 1.7790 * (*u - 128);
                        if (r<0) r=0;
                        else if (r>255) r=255;
                        if (g<0) g=0;
                        else if (g>255) g=255;
                        if (b<0) b=0;
                        else if (b>255) b=255;

                        rgb[0u]=(edk::uint8)r;
                        rgb[1u]=(edk::uint8)g;
                        rgb[2u]=(edk::uint8)b;

                        //increment the rgb and the y
                        rgb+=3u;
                        y++;

                        r = *y + 1.4075 *                        (*v - 128) ;
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                        b = *y + 1.7790 * (*u - 128);
                        if (r<0) r=0;
                        else if (r>255) r=255;
                        if (g<0) g=0;
                        else if (g>255) g=255;
                        if (b<0) b=0;
                        else if (b>255) b=255;

                        rgb[0u]=(edk::uint8)r;
                        rgb[1u]=(edk::uint8)g;
                        rgb[2u]=(edk::uint8)b;

                        //increment the rgb and the y
                        rgb+=3u;
                        y++;
                        //increment the u v
                        u++;
                        v++;
                    }
                }
                //process the last line odd
                for(j=0u;j<size.width;j+=2u){
                    r = *y + 1.4075 *                        (*v - 128) ;
                    g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                    b = *y + 1.7790 * (*u - 128);
                    if (r<0) r=0;
                    else if (r>255) r=255;
                    if (g<0) g=0;
                    else if (g>255) g=255;
                    if (b<0) b=0;
                    else if (b>255) b=255;

                    rgb[0u]=(edk::uint8)r;
                    rgb[1u]=(edk::uint8)g;
                    rgb[2u]=(edk::uint8)b;

                    //increment the rgb and y
                    rgb+=3u;
                    y++;

                    r = *y + 1.4075 *                        (*v - 128) ;
                    g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                    b = *y + 1.7790 * (*u - 128);
                    if (r<0) r=0;
                    else if (r>255) r=255;
                    if (g<0) g=0;
                    else if (g>255) g=255;
                    if (b<0) b=0;
                    else if (b>255) b=255;

                    rgb[0u]=(edk::uint8)r;
                    rgb[1u]=(edk::uint8)g;
                    rgb[2u]=(edk::uint8)b;

                    //increment the rgb and y
                    rgb+=3u;
                    y++;
                    //increment the u v
                    u++;
                    v++;
                }
            }
        }
        else{
            //odd
            if(!(size.height<<((sizeof(size.height)*8u)-1u))){
                //even

                size.width-=2u;
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    for(j=0u;j<size.width;j+=2u){
                        r = *y + 1.4075 *                        (*v - 128) ;
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                        b = *y + 1.7790 * (*u - 128);
                        if (r<0) r=0;
                        else if (r>255) r=255;
                        if (g<0) g=0;
                        else if (g>255) g=255;
                        if (b<0) b=0;
                        else if (b>255) b=255;

                        rgb[0u]=(edk::uint8)r;
                        rgb[1u]=(edk::uint8)g;
                        rgb[2u]=(edk::uint8)b;

                        //increment the rgb and y
                        rgb+=3u;
                        y++;

                        r = *y + 1.4075 *                        (*v - 128) ;
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                        b = *y + 1.7790 * (*u - 128);
                        if (r<0) r=0;
                        else if (r>255) r=255;
                        if (g<0) g=0;
                        else if (g>255) g=255;
                        if (b<0) b=0;
                        else if (b>255) b=255;

                        rgb[0u]=(edk::uint8)r;
                        rgb[1u]=(edk::uint8)g;
                        rgb[2u]=(edk::uint8)b;

                        //increment the rgb and y
                        rgb+=3u;
                        y++;
                        //increment the u v
                        u++;
                        v++;
                    }
                    //process the last pixel odd
                    r = *y + 1.4075 *                        (*v - 128) ;
                    g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                    b = *y + 1.7790 * (*u - 128);
                    if (r<0) r=0;
                    else if (r>255) r=255;
                    if (g<0) g=0;
                    else if (g>255) g=255;
                    if (b<0) b=0;
                    else if (b>255) b=255;

                    rgb[0u]=(edk::uint8)r;
                    rgb[1u]=(edk::uint8)g;
                    rgb[2u]=(edk::uint8)b;

                    //increment the rgb and y
                    rgb+=3u;
                    y++;

                    //decrement the y
                    u-=(size.width>>1)+1u;
                    v-=(size.width>>1)+1u;
                    for(j=0u;j<size.width;j+=2u){
                        r = *y + 1.4075 *                        (*v - 128) ;
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                        b = *y + 1.7790 * (*u - 128);
                        if (r<0) r=0;
                        else if (r>255) r=255;
                        if (g<0) g=0;
                        else if (g>255) g=255;
                        if (b<0) b=0;
                        else if (b>255) b=255;

                        rgb[0u]=(edk::uint8)r;
                        rgb[1u]=(edk::uint8)g;
                        rgb[2u]=(edk::uint8)b;

                        //increment the rgb and the y
                        rgb+=3u;
                        y++;

                        r = *y + 1.4075 *                        (*v - 128) ;
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                        b = *y + 1.7790 * (*u - 128);
                        if (r<0) r=0;
                        else if (r>255) r=255;
                        if (g<0) g=0;
                        else if (g>255) g=255;
                        if (b<0) b=0;
                        else if (b>255) b=255;

                        rgb[0u]=(edk::uint8)r;
                        rgb[1u]=(edk::uint8)g;
                        rgb[2u]=(edk::uint8)b;

                        //increment the rgb and the y
                        rgb+=3u;
                        y++;
                        //increment the u v
                        u++;
                        v++;
                    }
                    //process the last pixel odd
                    r = *y + 1.4075 *                        (*v - 128) ;
                    g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                    b = *y + 1.7790 * (*u - 128);
                    if (r<0) r=0;
                    else if (r>255) r=255;
                    if (g<0) g=0;
                    else if (g>255) g=255;
                    if (b<0) b=0;
                    else if (b>255) b=255;

                    rgb[0u]=(edk::uint8)r;
                    rgb[1u]=(edk::uint8)g;
                    rgb[2u]=(edk::uint8)b;

                    //increment the rgb and the y
                    rgb+=3u;
                    y++;
                }
            }
            else{
                //odd

                size.width-=2u;
                size.height-=2u;
                register edk::uint32 i=0u;
                register edk::uint32 j=0u;
                for(i=0u;i<size.height;i+=2u){
                    for(j=0u;j<size.width;j+=2u){
                        r = *y + 1.4075 *                        (*v - 128) ;
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                        b = *y + 1.7790 * (*u - 128);
                        if (r<0) r=0;
                        else if (r>255) r=255;
                        if (g<0) g=0;
                        else if (g>255) g=255;
                        if (b<0) b=0;
                        else if (b>255) b=255;

                        rgb[0u]=(edk::uint8)r;
                        rgb[1u]=(edk::uint8)g;
                        rgb[2u]=(edk::uint8)b;

                        //increment the rgb and y
                        rgb+=3u;
                        y++;

                        r = *y + 1.4075 *                        (*v - 128) ;
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                        b = *y + 1.7790 * (*u - 128);
                        if (r<0) r=0;
                        else if (r>255) r=255;
                        if (g<0) g=0;
                        else if (g>255) g=255;
                        if (b<0) b=0;
                        else if (b>255) b=255;

                        rgb[0u]=(edk::uint8)r;
                        rgb[1u]=(edk::uint8)g;
                        rgb[2u]=(edk::uint8)b;

                        //increment the rgb and y
                        rgb+=3u;
                        y++;
                        //increment the u v
                        u++;
                        v++;
                    }
                    //process the last pixel odd
                    r = *y + 1.4075 *                        (*v - 128) ;
                    g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                    b = *y + 1.7790 * (*u - 128);
                    if (r<0) r=0;
                    else if (r>255) r=255;
                    if (g<0) g=0;
                    else if (g>255) g=255;
                    if (b<0) b=0;
                    else if (b>255) b=255;

                    rgb[0u]=(edk::uint8)r;
                    rgb[1u]=(edk::uint8)g;
                    rgb[2u]=(edk::uint8)b;

                    //increment the rgb and y
                    rgb+=3u;
                    y++;

                    //decrement the y
                    u-=(size.width>>1)+1u;
                    v-=(size.width>>1)+1u;
                    for(j=0u;j<size.width;j+=2u){
                        r = *y + 1.4075 *                        (*v - 128) ;
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                        b = *y + 1.7790 * (*u - 128);
                        if (r<0) r=0;
                        else if (r>255) r=255;
                        if (g<0) g=0;
                        else if (g>255) g=255;
                        if (b<0) b=0;
                        else if (b>255) b=255;

                        rgb[0u]=(edk::uint8)r;
                        rgb[1u]=(edk::uint8)g;
                        rgb[2u]=(edk::uint8)b;

                        //increment the rgb and the y
                        rgb+=3u;
                        y++;

                        r = *y + 1.4075 *                        (*v - 128) ;
                        g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                        b = *y + 1.7790 * (*u - 128);
                        if (r<0) r=0;
                        else if (r>255) r=255;
                        if (g<0) g=0;
                        else if (g>255) g=255;
                        if (b<0) b=0;
                        else if (b>255) b=255;

                        rgb[0u]=(edk::uint8)r;
                        rgb[1u]=(edk::uint8)g;
                        rgb[2u]=(edk::uint8)b;

                        //increment the rgb and the y
                        rgb+=3u;
                        y++;
                        //increment the u v
                        u++;
                        v++;
                    }
                    //process the last pixel odd
                    r = *y + 1.4075 *                        (*v - 128) ;
                    g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                    b = *y + 1.7790 * (*u - 128);
                    if (r<0) r=0;
                    else if (r>255) r=255;
                    if (g<0) g=0;
                    else if (g>255) g=255;
                    if (b<0) b=0;
                    else if (b>255) b=255;

                    rgb[0u]=(edk::uint8)r;
                    rgb[1u]=(edk::uint8)g;
                    rgb[2u]=(edk::uint8)b;

                    //increment the rgb and the y
                    rgb+=3u;
                    y++;

                }
                //process the last line odd
                for(j=0u;j<size.width;j+=2u){
                    r = *y + 1.4075 *                        (*v - 128) ;
                    g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                    b = *y + 1.7790 * (*u - 128);
                    if (r<0) r=0;
                    else if (r>255) r=255;
                    if (g<0) g=0;
                    else if (g>255) g=255;
                    if (b<0) b=0;
                    else if (b>255) b=255;

                    rgb[0u]=(edk::uint8)r;
                    rgb[1u]=(edk::uint8)g;
                    rgb[2u]=(edk::uint8)b;

                    //increment the rgb and y
                    rgb+=3u;
                    y++;

                    r = *y + 1.4075 *                        (*v - 128) ;
                    g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                    b = *y + 1.7790 * (*u - 128);
                    if (r<0) r=0;
                    else if (r>255) r=255;
                    if (g<0) g=0;
                    else if (g>255) g=255;
                    if (b<0) b=0;
                    else if (b>255) b=255;

                    rgb[0u]=(edk::uint8)r;
                    rgb[1u]=(edk::uint8)g;
                    rgb[2u]=(edk::uint8)b;

                    //increment the rgb and y
                    rgb+=3u;
                    y++;
                    //increment the u v
                    u++;
                    v++;
                }
                //process the last pixel odd
                r = *y + 1.4075 *                        (*v - 128) ;
                g = *y - 0.3455 * (*u - 128) - (0.7169 * (*v - 128));
                b = *y + 1.7790 * (*u - 128);
                if (r<0) r=0;
                else if (r>255) r=255;
                if (g<0) g=0;
                else if (g>255) g=255;
                if (b<0) b=0;
                else if (b>255) b=255;

                rgb[0u]=(edk::uint8)r;
                rgb[1u]=(edk::uint8)g;
                rgb[2u]=(edk::uint8)b;

                //increment the rgb and y
                rgb+=3u;
                y++;

            }
        }
        return true;
    }
    return false;
}
