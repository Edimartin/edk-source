#include "ImageToShadertoy.h"

/*
Library ImageToShadertoy - Write an image into a frag shader to run in shadertoy
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

edk::ImageToShadertoy::ImageToShadertoy(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::ImageToShadertoy::~ImageToShadertoy(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::ImageToShadertoy::Constructor(bool /*runFather*/){
    //
    if(this->classThis!=this){
        this->classThis=this;
    }
}
//
bool edk::ImageToShadertoy::writeToFile(edk::char8* imageName,edk::uint32 lineSize){
    if(!lineSize) lineSize=10u;edkEnd();
    //test the name
    if(imageName){
        bool ret=false;edkEnd();
        edk::Image2D image;edkEnd();
        edk::char8* nameVec = edk::FileToH::readFileName(imageName);edkEnd();
        if(nameVec){
            edk::char8* className = nameVec;edkEnd();
            {
                edk::char8* temp = className;edkEnd();
                while(*temp){
                    if((*temp == '.' || *temp == '/' )&& temp[1u]){
                        className = ++temp;edkEnd();
                    }
                    else
                        temp++;edkEnd();
                }
            }
            edk::char8* fileNameFiltered = imageName;edkEnd();
            {
                edk::uint32 nameSize = edk::String::strSize(fileNameFiltered);edkEnd();
                for(edk::uint32 i=nameSize;i>0u;i--){
                    if(i) if(imageName[i-1u] == '/'){
                        fileNameFiltered = &imageName[i];edkEnd();
                        break;edkEnd();
                    }
                }
            }

            //load the image from the file
            if(image.loadFromFileToRGB(imageName)){

                //get the image size
                edk::size2ui32 sizeImage = image.getSize();edkEnd();

                edk::uint8* buffer = image.getPixels();edkEnd();

                if(sizeImage.width && sizeImage.height && buffer && image.getChannels() == 3u){
                    //create the file
                    //edk::char8* fileName = edk::String::strCat(nameVec,".frag");edkEnd();
                    edk::char8* fileName = edk::String::strCat(nameVec,".txt");edkEnd();
                    if(fileName){
                        //create the file
                        edk::File file;edkEnd();
                        if(file.createAndOpenTextFile(fileName)){
                            //write the size
                            file.writeText("const vec2 ");edkEnd();
                            file.writeText(className);edkEnd();
                            file.writeText("_size = vec2(");edkEnd();
                            file.writeText(image.getWidth());edkEnd();
                            file.writeText(",");edkEnd();
                            file.writeText(image.getHeight());edkEnd();
                            file.writeText(");");edkEnd();
                            file.writeText("\n");edkEnd();

                            //write the vector
                            //const int[] bitmap = int[] (
                            file.writeText("const float[] ");edkEnd();
                            file.writeText(className);edkEnd();
                            file.writeText(" = float[] (\n");edkEnd();

                            edk::uint64 size =sizeImage.width * sizeImage.height;edkEnd();
                            edk::float32 pixelValue = 0.f;edkEnd();
                            for(edk::uint64 i=0u;i<size;i++){
                                //write the pixelValue
                                pixelValue = (edk::float32)buffer[0u]/255.f;edkEnd();
                                file.writeText(pixelValue,3u);edkEnd();
                                file.writeText(",");edkEnd();
                                //write the pixelValue
                                pixelValue = (edk::float32)buffer[1u]/255.f;edkEnd();
                                file.writeText(pixelValue,3u);edkEnd();
                                file.writeText(",");edkEnd();
                                //write the pixelValue
                                pixelValue = (edk::float32)buffer[2u]/255.f;edkEnd();
                                file.writeText(pixelValue,3u);edkEnd();
                                if(i<size-1u){
                                    file.writeText(",");edkEnd();
                                }
                                file.writeText("\n");edkEnd();
                                buffer+=3u;edkEnd();
                            }
                            file.writeText(");");edkEnd();
                            file.writeText("\n");edkEnd();
                            file.writeText("\n");edkEnd();

                            //floatToInt
                            file.writeText("int floatToInt(float value){");edkEnd();
                            file.writeText("\n");edkEnd();
                            file.writeText("    ");edkEnd();
                            file.writeText("highp int ret = int(value);");edkEnd();
                            file.writeText("\n");edkEnd();
                            file.writeText("    ");edkEnd();
                            file.writeText("return ret;");edkEnd();
                            file.writeText("\n");edkEnd();
                            file.writeText("}");edkEnd();
                            file.writeText("\n");edkEnd();
                            file.writeText("\n");edkEnd();

                            //function getIndex
                            file.writeText("int get_");edkEnd();
                            file.writeText(className);edkEnd();
                            file.writeText("_index(in vec2 uv){");edkEnd();
                            file.writeText("\n");edkEnd();
                            file.writeText("    ");edkEnd();
                            file.writeText("return ((floatToInt((uv.y * ");edkEnd();
                            file.writeText(className);edkEnd();
                            file.writeText("_size.y))) *");edkEnd();
                            file.writeText("\n");edkEnd();
                            file.writeText("    ");edkEnd();
                            file.writeText("(floatToInt((");edkEnd();
                            file.writeText(className);edkEnd();
                            file.writeText("_size.x)))*3) +");edkEnd();
                            file.writeText("\n");edkEnd();
                            file.writeText("    ");edkEnd();
                            file.writeText("(floatToInt((uv.x * ");edkEnd();
                            file.writeText(className);edkEnd();
                            file.writeText("_size.x))*3);");edkEnd();
                            file.writeText("\n");edkEnd();
                            file.writeText("}");edkEnd();
                            file.writeText("\n");edkEnd();
                            file.writeText("\n");edkEnd();

                            //function get pixel
                            file.writeText("vec4 get_");edkEnd();
                            file.writeText(className);edkEnd();
                            file.writeText("_pixel(in int index){");edkEnd();
                            file.writeText("\n");edkEnd();
                            file.writeText("    ");edkEnd();
                            file.writeText("return vec4(");edkEnd();
                            file.writeText(className);edkEnd();
                            file.writeText("[index+0],");edkEnd();
                            file.writeText(className);edkEnd();
                            file.writeText("[index+1],");edkEnd();
                            file.writeText(className);edkEnd();
                            file.writeText("[index+2],1.0);");edkEnd();
                            file.writeText("\n");edkEnd();
                            file.writeText("}");edkEnd();
                            file.writeText("\n");edkEnd();
                            file.writeText("\n");edkEnd();

                            //function get color
                            file.writeText("vec4 get_");edkEnd();
                            file.writeText(className);edkEnd();
                            file.writeText("_color(in vec2 uv){");edkEnd();
                            file.writeText("\n");edkEnd();
                            file.writeText("    ");edkEnd();
                            file.writeText("return get_");edkEnd();
                            file.writeText(className);edkEnd();
                            file.writeText("_pixel(get_");edkEnd();
                            file.writeText(className);edkEnd();
                            file.writeText("_index(uv));");edkEnd();
                            file.writeText("\n");edkEnd();
                            file.writeText("}");edkEnd();
                            file.writeText("\n");edkEnd();
                            file.writeText("\n");edkEnd();



                            //functions to get pixel color
                            /*

int floatToInt(float value){
    highp int ret = int(value);edkEnd();
    return ret;edkEnd();
}

int get_image_index(in vec2 uv){
    return ((floatToInt((uv.y * image_size.y))) *
    (floatToInt((image_size.x)))*3) +
    (floatToInt((uv.x * image_size.x))*3);edkEnd();
}

vec4 get_image_pixel(in int index){
    return vec4(image[index+0],image[index+1],image[index+2],1.0);edkEnd();
}

vec4 get_image_color(in vec2 uv){
    return get_image_pixel(get_image_index(uv));edkEnd();
}
*/


                            //function main
                            file.writeText("void mainImage(out vec4 fragColor,in vec2 fragCoord){");edkEnd();
                            file.writeText("\n");edkEnd();
                            file.writeText("    ");edkEnd();
                            file.writeText("vec2 uv = vec2(fragCoord.x / iResolution.x,(fragCoord.y / iResolution.y*-1.0)+1.0);");edkEnd();
                            file.writeText("\n");edkEnd();
                            file.writeText("    ");edkEnd();
                            file.writeText("fragColor = get_");edkEnd();
                            file.writeText(className);edkEnd();
                            file.writeText("_color(uv);");edkEnd();
                            file.writeText("\n");edkEnd();
                            file.writeText("}");edkEnd();
                            /*
void mainImage(out vec4 fragColor,in vec2 fragCoord){
    vec2 uv = vec2(fragCoord.x / iResolution.x,(fragCoord.y / iResolution.y*-1.0)+1.0);edkEnd();
    fragColor = get_image_color(uv);edkEnd();
}
*/
                            //return true
                            ret=true;edkEnd();

                            file.flush();edkEnd();
                            file.closeFile();edkEnd();
                        }
                        free(fileName);edkEnd();
                    }
                }

                image.deleteImage();edkEnd();
            }
            free(nameVec);edkEnd();
        }
        return ret;edkEnd();
    }
    return false;edkEnd();
}
bool edk::ImageToShadertoy::writeToFile(const edk::char8* imageName,edk::uint32 lineSize){
    return edk::ImageToShadertoy::writeToFile((edk::char8*) imageName,lineSize);edkEnd();
}
bool edk::ImageToShadertoy::writeToEDKFile(edk::char8* imageName,edk::uint32 lineSize){
    if(!lineSize) lineSize=10u;edkEnd();
    //test the name
    if(imageName){
        bool ret=false;edkEnd();
        //
        return ret;edkEnd();
    }
    return false;edkEnd();
}
bool edk::ImageToShadertoy::writeToEDKFile(const edk::char8* imageName,edk::uint32 lineSize){
    return edk::ImageToShadertoy::writeToEDKFile((edk::char8*) imageName,lineSize);edkEnd();
}
