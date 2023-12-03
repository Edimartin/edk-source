#include "Voronoi.h"

/*
Library C++ Voronoi - Voronoi generator to be used in EDK.
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

edk::Voronoi::Voronoi(){
    //
}
edk::Voronoi::~Voronoi(){
    //
}
//functions used the generate the image
bool edk::Voronoi::runGenerateImageRGB(edk::vector::Array<edk::vec2f32ColorRGB>* points,
                                       edk::uint8* image,
                                       edk::uint32 width,
                                       edk::uint32 height,
                                       edk::uint32 start,
                                       edk::uint32 end
                                       ){
    //test the variables
    if(points && image && width && height && end && (start<end)){
        edk::uint32 size = points->getSize();edkEnd();
        edk::float32 distance=0.f,distanceN=0.f;edkEnd();
        edk::vec2f32ColorRGB point;edkEnd();
        if(size){
            for(edk::uint32 y = start;y<end;y++){
                for(edk::uint32 x = 0u;x<width;x++){
                    point = points->get(0u);edkEnd();
                    //get the first distance
                    distance = edk::Math::pythagoras(x - (point.position.x*width),
                                                       y - (point.position.y*height)
                                                       );edkEnd();
                    image[0u] = point.color.r;edkEnd();
                    image[1u] = point.color.g;edkEnd();
                    image[2u] = point.color.b;edkEnd();
                    for(edk::uint32 i=1u;i<size;i++){
                        point = points->get(i);edkEnd();
                        //calculate the new distance
                        distanceN = edk::Math::pythagoras(x - (point.position.x*width),
                                                            y - (point.position.y*height)
                                                            );edkEnd();
                        //test the distances
                        if(distanceN < distance){
                            distance = distanceN;edkEnd();
                            //copy the new color
                            image[0u] = point.color.r;edkEnd();
                            image[1u] = point.color.g;edkEnd();
                            image[2u] = point.color.b;edkEnd();
                        }
                    }
                    //increment the image
                    image+=3u;edkEnd();
                }
            }
            return true;
        }
    }
    return false;
}
bool edk::Voronoi::runGenerateImageRGB(edk::vector::Array<edk::vec2f32ColorGray>* points,
                                       edk::uint8* image,
                                       edk::uint32 width,
                                       edk::uint32 height,
                                       edk::uint32 start,
                                       edk::uint32 end
                                       ){
    //test the variables
    if(points && image && width && height && end && (start<end)){
        edk::uint32 size = points->getSize();edkEnd();
        edk::float32 distance=0.f,distanceN=0.f;edkEnd();
        edk::vec2f32ColorGray point;edkEnd();
        if(size){
            for(edk::uint32 y = start;y<end;y++){
                for(edk::uint32 x = 0u;x<width;x++){
                    point = points->get(0u);edkEnd();
                    //get the first distance
                    distance = edk::Math::pythagoras(x - (point.position.x*width),
                                                       y - (point.position.y*height)
                                                       );edkEnd();
                    image[0u] = point.grayscale;edkEnd();
                    image[1u] = point.grayscale;edkEnd();
                    image[2u] = point.grayscale;edkEnd();
                    for(edk::uint32 i=1u;i<size;i++){
                        point = points->get(i);edkEnd();
                        //calculate the new distance
                        distanceN = edk::Math::pythagoras(x - (point.position.x*width),
                                                            y - (point.position.y*height)
                                                            );edkEnd();
                        //test the distances
                        if(distanceN < distance){
                            distance = distanceN;edkEnd();
                            //copy the new color
                            image[0u] = point.grayscale;edkEnd();
                            image[1u] = point.grayscale;edkEnd();
                            image[2u] = point.grayscale;edkEnd();
                        }
                    }
                    //increment the image
                    image+=3u;edkEnd();
                }
            }
            return true;
        }
    }
    return false;
}
bool edk::Voronoi::runGenerateImageGray(edk::vector::Array<edk::vec2f32ColorRGB>* points,
                                        edk::uint8* image,
                                        edk::uint32 width,
                                        edk::uint32 height,
                                        edk::uint32 start,
                                        edk::uint32 end
                                        ){
    //test the variables
    if(points && image && width && height && end && (start<end)){
        edk::uint32 size = points->getSize();edkEnd();
        edk::float32 distance=0.f,distanceN=0.f;edkEnd();
        edk::vec2f32ColorRGB point;edkEnd();
        if(size){
            for(edk::uint32 y = start;y<end;y++){
                for(edk::uint32 x = 0u;x<width;x++){
                    point = points->get(0u);edkEnd();
                    //get the first distance
                    distance = edk::Math::pythagoras(x - (point.position.x*width),
                                                       y - (point.position.y*height)
                                                       );edkEnd();
                    *image = point.color.r;edkEnd();
                    for(edk::uint32 i=1u;i<size;i++){
                        point = points->get(i);edkEnd();
                        //calculate the new distance
                        distanceN = edk::Math::pythagoras(x - (point.position.x*width),
                                                            y - (point.position.y*height)
                                                            );edkEnd();
                        //test the distances
                        if(distanceN < distance){
                            distance = distanceN;edkEnd();
                            //copy the new color
                            *image = point.color.r;edkEnd();
                        }
                    }
                    //increment the image
                    image+=1u;edkEnd();
                }
            }
            return true;
        }
    }
    return false;
}
bool edk::Voronoi::runGenerateImageGray(edk::vector::Array<edk::vec2f32ColorGray>* points,
                                        edk::uint8* image,
                                        edk::uint32 width,
                                        edk::uint32 height,
                                        edk::uint32 start,
                                        edk::uint32 end
                                        ){
    //test the variables
    if(points && image && width && height && end && (start<end)){
        edk::uint32 size = points->getSize();edkEnd();
        edk::float32 distance=0.f,distanceN=0.f;edkEnd();
        edk::vec2f32ColorGray point;edkEnd();
        if(size){
            for(edk::uint32 y = start;y<end;y++){
                for(edk::uint32 x = 0u;x<width;x++){
                    point = points->get(0u);edkEnd();
                    //get the first distance
                    distance = edk::Math::pythagoras(x - (point.position.x*width),
                                                       y - (point.position.y*height)
                                                       );edkEnd();
                    *image = point.grayscale;edkEnd();
                    for(edk::uint32 i=1u;i<size;i++){
                        point = points->get(i);edkEnd();
                        //calculate the new distance
                        distanceN = edk::Math::pythagoras(x - (point.position.x*width),
                                                            y - (point.position.y*height)
                                                            );edkEnd();
                        //test the distances
                        if(distanceN < distance){
                            distance = distanceN;edkEnd();
                            //copy the new color
                            *image = point.grayscale;edkEnd();
                        }
                    }
                    //increment the image
                    image+=1u;edkEnd();
                }
            }
            return true;
        }
    }
    return false;
}
//thread functions
edk::classID edk::Voronoi::runThreadGenerateImageRGBFromRGB(edk::classID image){
    if(image){
        //
        edk::Voronoi::ImageRGB* points = (edk::Voronoi::ImageRGB*)image;edkEnd();
        //run the function
        if(points){
            bool ret = edk::Voronoi::runGenerateImageRGB(&points->points,
                                                         points->image,
                                                         points->width,
                                                         points->height,
                                                         points->start,
                                                         points->end
                                                         );edkEnd();
            delete points;edkEnd();
            return (edk::classID)ret;edkEnd();
        }
    }
    return NULL;
}
edk::classID edk::Voronoi::runThreadGenerateImageRGBFromGray(edk::classID image){
    if(image){
        //
        edk::Voronoi::ImageGray* points = (edk::Voronoi::ImageGray*)image;edkEnd();
        //run the function
        if(points){
            bool ret = edk::Voronoi::runGenerateImageRGB(&points->points,
                                                         points->image,
                                                         points->width,
                                                         points->height,
                                                         points->start,
                                                         points->end
                                                         );edkEnd();
            delete points;edkEnd();
            return (edk::classID)ret;edkEnd();
        }
    }
    return NULL;
}
edk::classID edk::Voronoi::runThreadGenerateImageGrayFromRGB(edk::classID image){
    if(image){
        //
        edk::Voronoi::ImageRGB* points = (edk::Voronoi::ImageRGB*)image;edkEnd();
        //run the function
        if(points){
            bool ret = edk::Voronoi::runGenerateImageGray(&points->points,
                                                         points->image,
                                                         points->width,
                                                         points->height,
                                                         points->start,
                                                         points->end
                                                         );edkEnd();
            delete points;edkEnd();
            return (edk::classID)ret;edkEnd();
        }
    }
    return NULL;
}
edk::classID edk::Voronoi::runThreadGenerateImageGrayFromGray(edk::classID image){
    if(image){
        //
        edk::Voronoi::ImageGray* points = (edk::Voronoi::ImageGray*)image;edkEnd();
        //run the function
        if(points){
            bool ret = edk::Voronoi::runGenerateImageGray(&points->points,
                                                         points->image,
                                                         points->width,
                                                         points->height,
                                                         points->start,
                                                         points->end
                                                         );edkEnd();
            delete points;edkEnd();
            return (edk::classID)ret;edkEnd();
        }
    }
    return NULL;
}


//generate the voronoi image
bool edk::Voronoi::generateImageRGB(edk::uint32 pointSize,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //test the variables
    if(pointSize && image && width && height){
        //generate the points
        edk::vector::Array<edk::vec2f32ColorRGB> points;edkEnd();
        if(points.createArray(pointSize)){
            //start the rand
            edk::Random rand;edkEnd();
            rand.loadStaticSeed();edkEnd();
            for(edk::uint32 i=0u;i<pointSize;i++){
                points.set(i,edk::vec2f32ColorRGB(rand.getStaticRandPercent(),rand.getStaticRandPercent(),
                                                  (edk::uint8)rand.getStaticRandNumber(),(edk::uint8)rand.getStaticRandNumber(),(edk::uint8)rand.getStaticRandNumber()
                                                  )
                           );edkEnd();
            }

            //generate the image
            bool ret = edk::Voronoi::generateImageRGB(&points,image,width,height);edkEnd();

            points.deleteArray();edkEnd();

            return ret;
        }
    }
    return false;
}
bool edk::Voronoi::generateImageRGB(edk::vector::Array<edk::vec2f32ColorRGB>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //run the function
    return edk::Voronoi::runGenerateImageRGB(points,
                                             image,
                                             width,
                                             height,
                                             0u,
                                             height
                                             );edkEnd();
}
bool edk::Voronoi::generateImageRGB(edk::vector::Array<edk::vec2f32ColorGray>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //run the function
    return edk::Voronoi::runGenerateImageRGB(points,
                                             image,
                                             width,
                                             height,
                                             0u,
                                             height
                                             );edkEnd();
}
bool edk::Voronoi::generateImageGray(edk::uint32 pointSize,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //test the variables
    if(pointSize && image && width && height){
        //generate the points
        edk::vector::Array<edk::vec2f32ColorGray> points;edkEnd();
        if(points.createArray(pointSize)){
            //start the rand
            edk::Random rand;edkEnd();
            rand.loadStaticSeed();edkEnd();
            for(edk::uint32 i=0u;i<pointSize;i++){
                points.set(i,edk::vec2f32ColorGray(rand.getStaticRandPercent(),rand.getStaticRandPercent(),
                                                   (edk::uint8)rand.getStaticRandNumber()
                                                   )
                           );edkEnd();
            }

            //generate the image
            bool ret = edk::Voronoi::generateImageGray(&points,image,width,height);edkEnd();

            points.deleteArray();edkEnd();

            return ret;
        }
    }
    return false;
}
bool edk::Voronoi::generateImageGray(edk::vector::Array<edk::vec2f32ColorRGB>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //run the function
    return edk::Voronoi::runGenerateImageGray(points,
                                              image,
                                              width,
                                              height,
                                              0u,
                                              height
                                              );edkEnd();
}
bool edk::Voronoi::generateImageGray(edk::vector::Array<edk::vec2f32ColorGray>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //run the function
    return edk::Voronoi::runGenerateImageGray(points,
                                              image,
                                              width,
                                              height,
                                              0u,
                                              height
                                              );edkEnd();
}
bool edk::Voronoi::generateImage(edk::uint32 pointSize,edk::Image2D* image){
    //test the variables
    if(pointSize && image){
        //test the image channels
        switch(image->getChannels()){
        case 1u:
            return edk::Voronoi::generateImageGray(pointSize,image->getPixels(),image->getSize().width,image->getSize().height);edkEnd();
            break;
        case 3u:
            return edk::Voronoi::generateImageRGB(pointSize,image->getPixels(),image->getSize().width,image->getSize().height);edkEnd();
            break;
        default:
            return false;
        }
    }
    return false;
}
bool edk::Voronoi::generateImage(edk::vector::Array<edk::vec2f32ColorRGB>* points,edk::Image2D* image){
    //test the variables
    if(points && image){
        //test the image channels
        switch(image->getChannels()){
        case 1u:
            return edk::Voronoi::generateImageGray(points,image->getPixels(),image->getSize().width,image->getSize().height);edkEnd();
            break;
        case 3u:
            return edk::Voronoi::generateImageRGB(points,image->getPixels(),image->getSize().width,image->getSize().height);edkEnd();
            break;
        default:
            return false;
        }
    }
    return false;
}
bool edk::Voronoi::generateImage(edk::vector::Array<edk::vec2f32ColorGray>* points,edk::Image2D* image){
    //test the variables
    if(points && image){
        //test the image channels
        switch(image->getChannels()){
        case 1u:
            return edk::Voronoi::generateImageGray(points,image->getPixels(),image->getSize().width,image->getSize().height);edkEnd();
            break;
        case 3u:
            return edk::Voronoi::generateImageRGB(points,image->getPixels(),image->getSize().width,image->getSize().height);edkEnd();
            break;
        default:
            return false;
        }
    }
    return false;
}
//multiThread
bool edk::Voronoi::multiGenerateImageRGB(edk::uint32 cores,edk::uint32 pointSize,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //test the variables
    if(cores && pointSize && image && width && height){
        //generate the points
        edk::vector::Array<edk::vec2f32ColorRGB> points;edkEnd();
        if(points.createArray(pointSize)){
            //start the rand
            edk::Random rand;edkEnd();
            rand.loadStaticSeed();edkEnd();
            for(edk::uint32 i=0u;i<pointSize;i++){
                points.set(i,edk::vec2f32ColorRGB(rand.getStaticRandPercent(),rand.getStaticRandPercent(),
                                                  (edk::uint8)rand.getStaticRandNumber(),(edk::uint8)rand.getStaticRandNumber(),(edk::uint8)rand.getStaticRandNumber()
                                                  )
                           );edkEnd();
            }

            //generate the image
            bool ret = edk::Voronoi::multiGenerateImageRGB(cores,&points,image,width,height);edkEnd();

            points.deleteArray();edkEnd();

            return ret;
        }
    }
    return false;
}
bool edk::Voronoi::multiGenerateImageRGB(edk::uint32 cores,edk::vector::Array<edk::vec2f32ColorRGB>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //test the variables
    if(cores>1u && points && image && width && height){

        edk::uint32 start = 0u,end = 0u,lenght = height/cores;edkEnd();
        edk::uint32 size = points->getSize();edkEnd();

        edk::Voronoi::ImageRGB* list = NULL;edkEnd();

        cores--;edkEnd();
        //create the threads
        edk::multi::Thread* threadPointer=NULL;edkEnd();
        edk::vector::Array<edk::multi::Thread*> threads;edkEnd();
        if(threads.createArray(cores)){
            //start the cores
            for(edk::uint32 i=0u;i<cores;i++){
                end = start+lenght;edkEnd();
                if(start>height){
                    start = height;edkEnd();
                }
                if(end>height){
                    end = height;edkEnd();
                }

                list = new edk::Voronoi::ImageRGB;edkEnd();
                if(list){
                    if(list->points.createArray(size)){
                        //copy the vector
                        for(edk::uint32 j=0u;j<size;j++){
                            list->points.set(j,points->get(j));edkEnd();
                        }
                        //copy the variables
                        list->image = image;edkEnd();
                        list->width = width;edkEnd();
                        list->height = height;edkEnd();
                        list->start = start;edkEnd();
                        list->end = end;edkEnd();

                        //create the new thread
                        threadPointer = new edk::multi::Thread;edkEnd();
                        if(threadPointer){
                            //start the thread
                            if(threadPointer->start(edk::Voronoi::runThreadGenerateImageRGBFromRGB, (edk::classID)list)){
                                //set the thread pointer in the list
                                threads.set(i,threadPointer);edkEnd();
                            }
                            else{
                                edk::Voronoi::runGenerateImageRGB(points,
                                                                  image,
                                                                  width,
                                                                  height,
                                                                  start,
                                                                  end
                                                                  );edkEnd();
                                delete list;edkEnd();
                                delete threadPointer;edkEnd();
                                threads.set(i,NULL);edkEnd();
                            }
                        }
                        else{
                            delete list;edkEnd();
                        }
                        threadPointer=NULL;edkEnd();
                    }
                    else{
                        delete list;edkEnd();
                    }
                }

                //
                start = end;edkEnd();
                //increment the image
                image+=lenght * width * 3u;edkEnd();
            }
            if(start<height){
                edk::Voronoi::runGenerateImageRGB(points,
                                                  image,
                                                  width,
                                                  height,
                                                  start,
                                                  height
                                                  );edkEnd();
            }
            for(edk::uint32 i=0u;i<cores;i++){
                //test if have the thread
                threadPointer = threads.get(i);edkEnd();
                if(threadPointer){
                    threadPointer->waitEnd();edkEnd();
                    delete threadPointer;edkEnd();
                }
            }
            threads.deleteArray();edkEnd();
            //wait for the threads end
            return true;
        }

    }
    return false;
}
bool edk::Voronoi::multiGenerateImageRGB(edk::uint32 cores,edk::vector::Array<edk::vec2f32ColorGray>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //test the variables
    if(cores>1u && points && image && width && height){

        edk::uint32 start = 0u,end = 0u,lenght = height/cores;edkEnd();
        edk::uint32 size = points->getSize();edkEnd();

        edk::Voronoi::ImageGray* list = NULL;edkEnd();

        cores--;edkEnd();
        //create the threads
        edk::multi::Thread* threadPointer=NULL;edkEnd();
        edk::vector::Array<edk::multi::Thread*> threads;edkEnd();
        if(threads.createArray(cores)){
            //start the cores
            for(edk::uint32 i=0u;i<cores;i++){
                end = start+lenght;edkEnd();
                if(start>height){
                    start = height;edkEnd();
                }
                if(end>height){
                    end = height;edkEnd();
                }

                list = new edk::Voronoi::ImageGray;edkEnd();
                if(list){
                    if(list->points.createArray(size)){
                        //copy the vector
                        for(edk::uint32 j=0u;j<size;j++){
                            list->points.set(j,points->get(j));edkEnd();
                        }
                        //copy the variables
                        list->image = image;edkEnd();
                        list->width = width;edkEnd();
                        list->height = height;edkEnd();
                        list->start = start;edkEnd();
                        list->end = end;edkEnd();

                        //create the new thread
                        threadPointer = new edk::multi::Thread;edkEnd();
                        if(threadPointer){
                            //start the thread
                            if(threadPointer->start(edk::Voronoi::runThreadGenerateImageRGBFromGray, (edk::classID)list)){
                                //set the thread pointer in the list
                                threads.set(i,threadPointer);edkEnd();
                            }
                            else{
                                edk::Voronoi::runGenerateImageRGB(points,
                                                                  image,
                                                                  width,
                                                                  height,
                                                                  start,
                                                                  end
                                                                  );edkEnd();
                                delete list;edkEnd();
                                delete threadPointer;edkEnd();
                                threads.set(i,NULL);edkEnd();
                            }
                        }
                        else{
                            delete list;edkEnd();
                        }
                        threadPointer=NULL;edkEnd();
                    }
                    else{
                        delete list;edkEnd();
                    }
                }

                //
                start = end;edkEnd();
                //increment the image
                image+=lenght * width * 3u;edkEnd();
            }
            if(start<height){
                edk::Voronoi::runGenerateImageRGB(points,
                                                  image,
                                                  width,
                                                  height,
                                                  start,
                                                  height
                                                  );edkEnd();
            }
            for(edk::uint32 i=0u;i<cores;i++){
                //test if have the thread
                threadPointer = threads.get(i);edkEnd();
                if(threadPointer){
                    threadPointer->waitEnd();edkEnd();
                    delete threadPointer;edkEnd();
                }
            }
            threads.deleteArray();edkEnd();
            //wait for the threads end
            return true;
        }

    }
    return false;
}
bool edk::Voronoi::multiGenerateImageGray(edk::uint32 cores,edk::uint32 pointSize,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //test the variables
    if(pointSize && image && width && height){
        //generate the points
        edk::vector::Array<edk::vec2f32ColorGray> points;edkEnd();
        if(points.createArray(pointSize)){
            //start the rand
            edk::Random rand;edkEnd();
            rand.loadStaticSeed();edkEnd();
            for(edk::uint32 i=0u;i<pointSize;i++){
                points.set(i,edk::vec2f32ColorGray(rand.getStaticRandPercent(),rand.getStaticRandPercent(),
                                                   (edk::uint8)rand.getStaticRandNumber()
                                                   )
                           );edkEnd();
            }

            //generate the image
            bool ret = edk::Voronoi::multiGenerateImageGray(cores,&points,image,width,height);edkEnd();

            points.deleteArray();edkEnd();

            return ret;
        }
    }
    return false;
}
bool edk::Voronoi::multiGenerateImageGray(edk::uint32 cores,edk::vector::Array<edk::vec2f32ColorRGB>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //test the variables
    if(cores>1u && points && image && width && height){

        edk::uint32 start = 0u,end = 0u,lenght = height/cores;edkEnd();
        edk::uint32 size = points->getSize();edkEnd();

        edk::Voronoi::ImageRGB* list = NULL;edkEnd();

        cores--;edkEnd();
        //create the threads
        edk::multi::Thread* threadPointer=NULL;edkEnd();
        edk::vector::Array<edk::multi::Thread*> threads;edkEnd();
        if(threads.createArray(cores)){
            //start the cores
            for(edk::uint32 i=0u;i<cores;i++){
                end = start+lenght;edkEnd();
                if(start>height){
                    start = height;edkEnd();
                }
                if(end>height){
                    end = height;edkEnd();
                }

                list = new edk::Voronoi::ImageRGB;edkEnd();
                if(list){
                    if(list->points.createArray(size)){
                        //copy the vector
                        for(edk::uint32 j=0u;j<size;j++){
                            list->points.set(j,points->get(j));edkEnd();
                        }
                        //copy the variables
                        list->image = image;edkEnd();
                        list->width = width;edkEnd();
                        list->height = height;edkEnd();
                        list->start = start;edkEnd();
                        list->end = end;edkEnd();

                        //create the new thread
                        threadPointer = new edk::multi::Thread;edkEnd();
                        if(threadPointer){
                            //start the thread
                            if(threadPointer->start(edk::Voronoi::runThreadGenerateImageGrayFromRGB, (edk::classID)list)){
                                //set the thread pointer in the list
                                threads.set(i,threadPointer);edkEnd();
                            }
                            else{
                                edk::Voronoi::runGenerateImageRGB(points,
                                                                  image,
                                                                  width,
                                                                  height,
                                                                  start,
                                                                  end
                                                                  );edkEnd();
                                delete list;edkEnd();
                                delete threadPointer;edkEnd();
                                threads.set(i,NULL);edkEnd();
                            }
                        }
                        else{
                            delete list;edkEnd();
                        }
                        threadPointer=NULL;edkEnd();
                    }
                    else{
                        delete list;edkEnd();
                    }
                }

                //
                start = end;edkEnd();
                //increment the image
                image+=lenght * width * 1u;edkEnd();
            }
            if(start<height){
                edk::Voronoi::runGenerateImageRGB(points,
                                                  image,
                                                  width,
                                                  height,
                                                  start,
                                                  height
                                                  );edkEnd();
            }
            for(edk::uint32 i=0u;i<cores;i++){
                //test if have the thread
                threadPointer = threads.get(i);edkEnd();
                if(threadPointer){
                    threadPointer->waitEnd();edkEnd();
                    delete threadPointer;edkEnd();
                }
            }
            threads.deleteArray();edkEnd();
            //wait for the threads end
            return true;
        }

    }
    return false;
}
bool edk::Voronoi::multiGenerateImageGray(edk::uint32 cores,edk::vector::Array<edk::vec2f32ColorGray>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //test the variables
    if(cores>1u && points && image && width && height){

        edk::uint32 start = 0u,end = 0u,lenght = height/cores;edkEnd();
        edk::uint32 size = points->getSize();edkEnd();

        edk::Voronoi::ImageGray* list = NULL;edkEnd();

        cores--;edkEnd();
        //create the threads
        edk::multi::Thread* threadPointer=NULL;edkEnd();
        edk::vector::Array<edk::multi::Thread*> threads;edkEnd();
        if(threads.createArray(cores)){
            //start the cores
            for(edk::uint32 i=0u;i<cores;i++){
                end = start+lenght;edkEnd();
                if(start>height){
                    start = height;edkEnd();
                }
                if(end>height){
                    end = height;edkEnd();
                }

                list = new edk::Voronoi::ImageGray;edkEnd();
                if(list){
                    if(list->points.createArray(size)){
                        //copy the vector
                        for(edk::uint32 j=0u;j<size;j++){
                            list->points.set(j,points->get(j));edkEnd();
                        }
                        //copy the variables
                        list->image = image;edkEnd();
                        list->width = width;edkEnd();
                        list->height = height;edkEnd();
                        list->start = start;edkEnd();
                        list->end = end;edkEnd();

                        //create the new thread
                        threadPointer = new edk::multi::Thread;edkEnd();
                        if(threadPointer){
                            //start the thread
                            if(threadPointer->start(edk::Voronoi::runThreadGenerateImageGrayFromGray, (edk::classID)list)){
                                //set the thread pointer in the list
                                threads.set(i,threadPointer);edkEnd();
                            }
                            else{
                                edk::Voronoi::runGenerateImageGray(points,
                                                                  image,
                                                                  width,
                                                                  height,
                                                                  start,
                                                                  end
                                                                  );edkEnd();
                                delete list;edkEnd();
                                delete threadPointer;edkEnd();
                                threads.set(i,NULL);edkEnd();
                            }
                        }
                        else{
                            delete list;edkEnd();
                        }
                        threadPointer=NULL;edkEnd();
                    }
                    else{
                        delete list;edkEnd();
                    }
                }

                //
                start = end;edkEnd();
                //increment the image
                image+=lenght * width * 1u;edkEnd();
            }
            if(start<height){
                edk::Voronoi::runGenerateImageGray(points,
                                                  image,
                                                  width,
                                                  height,
                                                  start,
                                                  height
                                                  );edkEnd();
            }
            for(edk::uint32 i=0u;i<cores;i++){
                //test if have the thread
                threadPointer = threads.get(i);edkEnd();
                if(threadPointer){
                    threadPointer->waitEnd();edkEnd();
                    delete threadPointer;edkEnd();
                }
            }
            threads.deleteArray();edkEnd();
            //wait for the threads end
            return true;
        }

    }
    return false;
}
bool edk::Voronoi::multiGenerateImage(edk::uint32 cores,edk::uint32 pointSize,edk::Image2D* image){
    //test the variables
    if(pointSize && image){
        //test the image channels
        switch(image->getChannels()){
        case 1u:
            return edk::Voronoi::multiGenerateImageGray(cores,pointSize,image->getPixels(),image->getSize().width,image->getSize().height);edkEnd();
            break;
        case 3u:
            return edk::Voronoi::multiGenerateImageRGB(cores,pointSize,image->getPixels(),image->getSize().width,image->getSize().height);edkEnd();
            break;
        default:
            return false;
        }
    }
    return false;
}
bool edk::Voronoi::multiGenerateImage(edk::uint32 cores,edk::vector::Array<edk::vec2f32ColorRGB>* points,edk::Image2D* image){
    //test the variables
    if(points && image){
        //test the image channels
        switch(image->getChannels()){
        case 1u:
            return edk::Voronoi::multiGenerateImageGray(cores,points,image->getPixels(),image->getSize().width,image->getSize().height);edkEnd();
            break;
        case 3u:
            return edk::Voronoi::multiGenerateImageRGB(cores,points,image->getPixels(),image->getSize().width,image->getSize().height);edkEnd();
            break;
        default:
            return false;
        }
    }
    return false;
}
bool edk::Voronoi::multiGenerateImage(edk::uint32 cores,edk::vector::Array<edk::vec2f32ColorGray>* points,edk::Image2D* image){
    //test the variables
    if(points && image){
        //test the image channels
        switch(image->getChannels()){
        case 1u:
            return edk::Voronoi::multiGenerateImageGray(cores,points,image->getPixels(),image->getSize().width,image->getSize().height);edkEnd();
            break;
        case 3u:
            return edk::Voronoi::multiGenerateImageRGB(cores,points,image->getPixels(),image->getSize().width,image->getSize().height);edkEnd();
            break;
        default:
            return false;
        }
    }
    return false;
}
