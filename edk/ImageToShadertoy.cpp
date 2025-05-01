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
    this->classThis=NULL;
    this->Constructor();
}
edk::ImageToShadertoy::~ImageToShadertoy(){
    this->Destructor();
}

void edk::ImageToShadertoy::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::ImageToShadertoy::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
}
//
bool edk::ImageToShadertoy::writeToFile(edk::char8* imageName,edk::uint32 lineSize){
    if(!lineSize){lineSize=10u; }
    //test the name
    if(imageName){
        bool ret=false;
        edk::Image2D image;
        edk::char8* nameVec = edk::FileToH::readFileName(imageName);
        if(nameVec){
            edk::char8* className = nameVec;
            {
                edk::char8* temp = className;
                while(*temp){
                    if((*temp == '.' || *temp == '/' )&& temp[1u]){
                        className = ++temp;
                    }
                    else{
                        temp++;
                    }
                }
            }
            edk::char8* fileNameFiltered = imageName;
            {
                edk::uint32 nameSize = edk::String::strSize(fileNameFiltered);
                for(edk::uint32 i=nameSize;i>0u;i--){
                    if(i) if(imageName[i-1u] == '/'){
                        fileNameFiltered = &imageName[i];
                        break;
                    }
                }
            }

            //load the image from the file
            if(image.loadFromFileToRGB(imageName)){

                //get the image size
                edk::size2ui32 sizeImage = image.getSize();

                edk::uint8* buffer = image.getPixels();

                if(sizeImage.width && sizeImage.height && buffer && image.getChannels() == 3u){
                    //create the file
                    //edk::char8* fileName = edk::String::strCat(nameVec,".frag");
                    edk::char8* fileName = edk::String::strCat(nameVec,".txt");
                    if(fileName){
                        //create the file
                        edk::File file;
                        if(file.createAndOpenTextFile(fileName)){
                            //write the size
                            file.writeText("const vec2 ");
                            file.writeText(className);
                            file.writeText("_size = vec2(");
                            file.writeText(image.getWidth());
                            file.writeText(",");
                            file.writeText(image.getHeight());
                            file.writeText(");");
                            file.writeText("\n");

                            //write the vector
                            //const int[] bitmap = int[] (
                            file.writeText("const float[] ");
                            file.writeText(className);
                            file.writeText(" = float[] (\n");

                            edk::uint64 size =sizeImage.width * sizeImage.height;
                            edk::float32 pixelValue = 0.f;
                            for(edk::uint64 i=0u;i<size;i++){
                                //write the pixelValue
                                pixelValue = (edk::float32)buffer[0u]/255.f;
                                file.writeText(pixelValue,3u);
                                file.writeText(",");
                                //write the pixelValue
                                pixelValue = (edk::float32)buffer[1u]/255.f;
                                file.writeText(pixelValue,3u);
                                file.writeText(",");
                                //write the pixelValue
                                pixelValue = (edk::float32)buffer[2u]/255.f;
                                file.writeText(pixelValue,3u);
                                if(i<size-1u){
                                    file.writeText(",");
                                }
                                file.writeText("\n");
                                buffer+=3u;
                            }
                            file.writeText(");");
                            file.writeText("\n");
                            file.writeText("\n");

                            //floatToInt
                            file.writeText("int floatToInt(float value){");
                            file.writeText("\n");
                            file.writeText("    ");
                            file.writeText("highp int ret = int(value);");
                            file.writeText("\n");
                            file.writeText("    ");
                            file.writeText("return ret;");
                            file.writeText("\n");
                            file.writeText("}");
                            file.writeText("\n");
                            file.writeText("\n");

                            //function getIndex
                            file.writeText("int get_");
                            file.writeText(className);
                            file.writeText("_index(in vec2 uv){");
                            file.writeText("\n");
                            file.writeText("    ");
                            file.writeText("return ((floatToInt((uv.y * ");
                            file.writeText(className);
                            file.writeText("_size.y))) *");
                            file.writeText("\n");
                            file.writeText("    ");
                            file.writeText("(floatToInt((");
                            file.writeText(className);
                            file.writeText("_size.x)))*3) +");
                            file.writeText("\n");
                            file.writeText("    ");
                            file.writeText("(floatToInt((uv.x * ");
                            file.writeText(className);
                            file.writeText("_size.x))*3);");
                            file.writeText("\n");
                            file.writeText("}");
                            file.writeText("\n");
                            file.writeText("\n");

                            //function get pixel
                            file.writeText("vec4 get_");
                            file.writeText(className);
                            file.writeText("_pixel(in int index){");
                            file.writeText("\n");
                            file.writeText("    ");
                            file.writeText("return vec4(");
                            file.writeText(className);
                            file.writeText("[index+0],");
                            file.writeText(className);
                            file.writeText("[index+1],");
                            file.writeText(className);
                            file.writeText("[index+2],1.0);");
                            file.writeText("\n");
                            file.writeText("}");
                            file.writeText("\n");
                            file.writeText("\n");

                            //function get color
                            file.writeText("vec4 get_");
                            file.writeText(className);
                            file.writeText("_color(in vec2 uv){");
                            file.writeText("\n");
                            file.writeText("    ");
                            file.writeText("return get_");
                            file.writeText(className);
                            file.writeText("_pixel(get_");
                            file.writeText(className);
                            file.writeText("_index(uv));");
                            file.writeText("\n");
                            file.writeText("}");
                            file.writeText("\n");
                            file.writeText("\n");



                            //functions to get pixel color
                            /*

int floatToInt(float value){
    highp int ret = int(value);
    return ret;
}

int get_image_index(in vec2 uv){
    return ((floatToInt((uv.y * image_size.y))) *
    (floatToInt((image_size.x)))*3) +
    (floatToInt((uv.x * image_size.x))*3);
}

vec4 get_image_pixel(in int index){
    return vec4(image[index+0],image[index+1],image[index+2],1.0);
}

vec4 get_image_color(in vec2 uv){
    return get_image_pixel(get_image_index(uv));
}
*/


                            //function main
                            file.writeText("void mainImage(out vec4 fragColor,in vec2 fragCoord){");
                            file.writeText("\n");
                            file.writeText("    ");
                            file.writeText("vec2 uv = vec2(fragCoord.x / iResolution.x,(fragCoord.y / iResolution.y*-1.0)+1.0);");
                            file.writeText("\n");
                            file.writeText("    ");
                            file.writeText("fragColor = get_");
                            file.writeText(className);
                            file.writeText("_color(uv);");
                            file.writeText("\n");
                            file.writeText("}");
                            /*
void mainImage(out vec4 fragColor,in vec2 fragCoord){
    vec2 uv = vec2(fragCoord.x / iResolution.x,(fragCoord.y / iResolution.y*-1.0)+1.0);
    fragColor = get_image_color(uv);
}
*/
                            //return true
                            ret=true;

                            file.flush();
                            file.closeFile();
                        }
                        free(fileName);
                    }
                }

                image.deleteImage();
            }
            free(nameVec);
        }
        return ret;
    }
    return false;
}
bool edk::ImageToShadertoy::writeToFile(const edk::char8* imageName,edk::uint32 lineSize){
    return edk::ImageToShadertoy::writeToFile((edk::char8*) imageName,lineSize);
}
bool edk::ImageToShadertoy::writeToEDKFile(edk::char8* imageName,edk::uint32 lineSize){
    if(!lineSize){ lineSize=10u; }
    //test the name
    if(imageName){
        bool ret=false;
        //
        return ret;
    }
    return false;
}
bool edk::ImageToShadertoy::writeToEDKFile(const edk::char8* imageName,edk::uint32 lineSize){
    return edk::ImageToShadertoy::writeToEDKFile((edk::char8*) imageName,lineSize);
}
