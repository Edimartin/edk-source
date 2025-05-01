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
    this->classThis=NULL; 
    this->Constructor();
}
edk::Voronoi::~Voronoi(){
    this->Destructor();
}

void edk::Voronoi::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::Voronoi::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
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
        edk::uint32 size = points->getSize(); 
        edk::float32 distance=0.f,distanceN=0.f; 
        edk::vec2f32ColorRGB point; 
        if(size){
            for(edk::uint32 y = start;y<end;y++){
                for(edk::uint32 x = 0u;x<width;x++){
                    point = points->get(0u); 
                    //get the first distance
                    distance = edk::Math::pythagoras(x - (point.position.x*width),
                                                     y - (point.position.y*height)
                                                     ); 
                    image[0u] = point.color.r; 
                    image[1u] = point.color.g; 
                    image[2u] = point.color.b; 
                    for(edk::uint32 i=1u;i<size;i++){
                        point = points->get(i); 
                        //calculate the new distance
                        distanceN = edk::Math::pythagoras(x - (point.position.x*width),
                                                          y - (point.position.y*height)
                                                          ); 
                        //test the distances
                        if(distanceN < distance){
                            distance = distanceN; 
                            //copy the new color
                            image[0u] = point.color.r; 
                            image[1u] = point.color.g; 
                            image[2u] = point.color.b; 
                        }
                    }
                    //increment the image
                    image+=3u; 
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
        edk::uint32 size = points->getSize(); 
        edk::float32 distance=0.f,distanceN=0.f; 
        edk::vec2f32ColorGray point; 
        if(size){
            for(edk::uint32 y = start;y<end;y++){
                for(edk::uint32 x = 0u;x<width;x++){
                    point = points->get(0u); 
                    //get the first distance
                    distance = edk::Math::pythagoras(x - (point.position.x*width),
                                                     y - (point.position.y*height)
                                                     ); 
                    image[0u] = point.grayscale; 
                    image[1u] = point.grayscale; 
                    image[2u] = point.grayscale; 
                    for(edk::uint32 i=1u;i<size;i++){
                        point = points->get(i); 
                        //calculate the new distance
                        distanceN = edk::Math::pythagoras(x - (point.position.x*width),
                                                          y - (point.position.y*height)
                                                          ); 
                        //test the distances
                        if(distanceN < distance){
                            distance = distanceN; 
                            //copy the new color
                            image[0u] = point.grayscale; 
                            image[1u] = point.grayscale; 
                            image[2u] = point.grayscale; 
                        }
                    }
                    //increment the image
                    image+=3u; 
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
        edk::uint32 size = points->getSize(); 
        edk::float32 distance=0.f,distanceN=0.f; 
        edk::vec2f32ColorRGB point; 
        if(size){
            for(edk::uint32 y = start;y<end;y++){
                for(edk::uint32 x = 0u;x<width;x++){
                    point = points->get(0u); 
                    //get the first distance
                    distance = edk::Math::pythagoras(x - (point.position.x*width),
                                                     y - (point.position.y*height)
                                                     ); 
                    *image = point.color.r; 
                    for(edk::uint32 i=1u;i<size;i++){
                        point = points->get(i); 
                        //calculate the new distance
                        distanceN = edk::Math::pythagoras(x - (point.position.x*width),
                                                          y - (point.position.y*height)
                                                          ); 
                        //test the distances
                        if(distanceN < distance){
                            distance = distanceN; 
                            //copy the new color
                            *image = point.color.r; 
                        }
                    }
                    //increment the image
                    image+=1u; 
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
        edk::uint32 size = points->getSize(); 
        edk::float32 distance=0.f,distanceN=0.f; 
        edk::vec2f32ColorGray point; 
        if(size){
            for(edk::uint32 y = start;y<end;y++){
                for(edk::uint32 x = 0u;x<width;x++){
                    point = points->get(0u); 
                    //get the first distance
                    distance = edk::Math::pythagoras(x - (point.position.x*width),
                                                     y - (point.position.y*height)
                                                     ); 
                    *image = point.grayscale; 
                    for(edk::uint32 i=1u;i<size;i++){
                        point = points->get(i); 
                        //calculate the new distance
                        distanceN = edk::Math::pythagoras(x - (point.position.x*width),
                                                          y - (point.position.y*height)
                                                          ); 
                        //test the distances
                        if(distanceN < distance){
                            distance = distanceN; 
                            //copy the new color
                            *image = point.grayscale; 
                        }
                    }
                    //increment the image
                    image+=1u; 
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
        edk::Voronoi::ImageRGB* points = (edk::Voronoi::ImageRGB*)image; 
        //run the function
        if(points){
            bool ret = edk::Voronoi::runGenerateImageRGB(&points->points,
                                                         points->image,
                                                         points->width,
                                                         points->height,
                                                         points->start,
                                                         points->end
                                                         ); 
            delete points; 
            return (edk::classID)ret; 
        }
    }
    return NULL;
}
edk::classID edk::Voronoi::runThreadGenerateImageRGBFromGray(edk::classID image){
    if(image){
        //
        edk::Voronoi::ImageGray* points = (edk::Voronoi::ImageGray*)image; 
        //run the function
        if(points){
            bool ret = edk::Voronoi::runGenerateImageRGB(&points->points,
                                                         points->image,
                                                         points->width,
                                                         points->height,
                                                         points->start,
                                                         points->end
                                                         ); 
            delete points; 
            return (edk::classID)ret; 
        }
    }
    return NULL;
}
edk::classID edk::Voronoi::runThreadGenerateImageGrayFromRGB(edk::classID image){
    if(image){
        //
        edk::Voronoi::ImageRGB* points = (edk::Voronoi::ImageRGB*)image; 
        //run the function
        if(points){
            bool ret = edk::Voronoi::runGenerateImageGray(&points->points,
                                                          points->image,
                                                          points->width,
                                                          points->height,
                                                          points->start,
                                                          points->end
                                                          ); 
            delete points; 
            return (edk::classID)ret; 
        }
    }
    return NULL;
}
edk::classID edk::Voronoi::runThreadGenerateImageGrayFromGray(edk::classID image){
    if(image){
        //
        edk::Voronoi::ImageGray* points = (edk::Voronoi::ImageGray*)image; 
        //run the function
        if(points){
            bool ret = edk::Voronoi::runGenerateImageGray(&points->points,
                                                          points->image,
                                                          points->width,
                                                          points->height,
                                                          points->start,
                                                          points->end
                                                          ); 
            delete points; 
            return (edk::classID)ret; 
        }
    }
    return NULL;
}


//generate the voronoi image
bool edk::Voronoi::generateImageRGB(edk::uint32 pointSize,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //test the variables
    if(pointSize && image && width && height){
        //generate the points
        edk::vector::Array<edk::vec2f32ColorRGB> points; 
        if(points.createArray(pointSize)){
            //start the rand
            edk::Random rand; 
            rand.loadStaticSeed(); 
            for(edk::uint32 i=0u;i<pointSize;i++){
                points.set(i,edk::vec2f32ColorRGB(rand.getStaticRandPercent(),rand.getStaticRandPercent(),
                                                  (edk::uint8)rand.getStaticRandNumber(),(edk::uint8)rand.getStaticRandNumber(),(edk::uint8)rand.getStaticRandNumber()
                                                  )
                           ); 
            }

            //generate the image
            bool ret = edk::Voronoi::generateImageRGB(&points,image,width,height); 

            points.deleteArray(); 

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
                                             ); 
}
bool edk::Voronoi::generateImageRGB(edk::vector::Array<edk::vec2f32ColorGray>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //run the function
    return edk::Voronoi::runGenerateImageRGB(points,
                                             image,
                                             width,
                                             height,
                                             0u,
                                             height
                                             ); 
}
bool edk::Voronoi::generateImageGray(edk::uint32 pointSize,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //test the variables
    if(pointSize && image && width && height){
        //generate the points
        edk::vector::Array<edk::vec2f32ColorGray> points; 
        if(points.createArray(pointSize)){
            //start the rand
            edk::Random rand; 
            rand.loadStaticSeed(); 
            for(edk::uint32 i=0u;i<pointSize;i++){
                points.set(i,edk::vec2f32ColorGray(rand.getStaticRandPercent(),rand.getStaticRandPercent(),
                                                   (edk::uint8)rand.getStaticRandNumber()
                                                   )
                           ); 
            }

            //generate the image
            bool ret = edk::Voronoi::generateImageGray(&points,image,width,height); 

            points.deleteArray(); 

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
                                              ); 
}
bool edk::Voronoi::generateImageGray(edk::vector::Array<edk::vec2f32ColorGray>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //run the function
    return edk::Voronoi::runGenerateImageGray(points,
                                              image,
                                              width,
                                              height,
                                              0u,
                                              height
                                              ); 
}
bool edk::Voronoi::generateImage(edk::uint32 pointSize,edk::Image2D* image){
    //test the variables
    if(pointSize && image){
        //test the image channels
        switch(image->getChannels()){
        case 1u:
            return edk::Voronoi::generateImageGray(pointSize,image->getPixels(),image->getSize().width,image->getSize().height); 
            break;
        case 3u:
            return edk::Voronoi::generateImageRGB(pointSize,image->getPixels(),image->getSize().width,image->getSize().height); 
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
            return edk::Voronoi::generateImageGray(points,image->getPixels(),image->getSize().width,image->getSize().height); 
            break;
        case 3u:
            return edk::Voronoi::generateImageRGB(points,image->getPixels(),image->getSize().width,image->getSize().height); 
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
            return edk::Voronoi::generateImageGray(points,image->getPixels(),image->getSize().width,image->getSize().height); 
            break;
        case 3u:
            return edk::Voronoi::generateImageRGB(points,image->getPixels(),image->getSize().width,image->getSize().height); 
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
        edk::vector::Array<edk::vec2f32ColorRGB> points; 
        if(points.createArray(pointSize)){
            //start the rand
            edk::Random rand; 
            rand.loadStaticSeed(); 
            for(edk::uint32 i=0u;i<pointSize;i++){
                points.set(i,edk::vec2f32ColorRGB(rand.getStaticRandPercent(),rand.getStaticRandPercent(),
                                                  (edk::uint8)rand.getStaticRandNumber(),(edk::uint8)rand.getStaticRandNumber(),(edk::uint8)rand.getStaticRandNumber()
                                                  )
                           ); 
            }

            //generate the image
            bool ret = edk::Voronoi::multiGenerateImageRGB(cores,&points,image,width,height); 

            points.deleteArray(); 

            return ret;
        }
    }
    return false;
}
bool edk::Voronoi::multiGenerateImageRGB(edk::uint32 cores,edk::vector::Array<edk::vec2f32ColorRGB>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //test the variables
    if(cores>1u && points && image && width && height){

        edk::uint32 start = 0u,end = 0u,lenght = height/cores; 
        edk::uint32 size = points->getSize(); 

        edk::Voronoi::ImageRGB* list = NULL; 

        cores--; 
        //create the threads
        edk::multi::Thread* threadPointer=NULL; 
        edk::vector::Array<edk::multi::Thread*> threads; 
        if(threads.createArray(cores)){
            //start the cores
            for(edk::uint32 i=0u;i<cores;i++){
                end = start+lenght; 
                if(start>height){
                    start = height; 
                }
                if(end>height){
                    end = height; 
                }

                list = new edk::Voronoi::ImageRGB; 
                if(list){
                    if(list->points.createArray(size)){
                        //copy the vector
                        for(edk::uint32 j=0u;j<size;j++){
                            list->points.set(j,points->get(j)); 
                        }
                        //copy the variables
                        list->image = image; 
                        list->width = width; 
                        list->height = height; 
                        list->start = start; 
                        list->end = end; 

                        //create the new thread
                        threadPointer = new edk::multi::Thread; 
                        if(threadPointer){
                            //start the thread
                            if(threadPointer->start(edk::Voronoi::runThreadGenerateImageRGBFromRGB, (edk::classID)list)){
                                //set the thread pointer in the list
                                threads.set(i,threadPointer); 
                            }
                            else{
                                edk::Voronoi::runGenerateImageRGB(points,
                                                                  image,
                                                                  width,
                                                                  height,
                                                                  start,
                                                                  end
                                                                  ); 
                                delete list; 
                                delete threadPointer; 
                                threads.set(i,NULL); 
                            }
                        }
                        else{
                            delete list; 
                        }
                        threadPointer=NULL; 
                    }
                    else{
                        delete list; 
                    }
                }

                //
                start = end; 
                //increment the image
                image+=lenght * width * 3u; 
            }
            if(start<height){
                edk::Voronoi::runGenerateImageRGB(points,
                                                  image,
                                                  width,
                                                  height,
                                                  start,
                                                  height
                                                  ); 
            }
            for(edk::uint32 i=0u;i<cores;i++){
                //test if have the thread
                threadPointer = threads.get(i); 
                if(threadPointer){
                    threadPointer->waitEnd(); 
                    delete threadPointer; 
                }
            }
            threads.deleteArray(); 
            //wait for the threads end
            return true;
        }

    }
    return false;
}
bool edk::Voronoi::multiGenerateImageRGB(edk::uint32 cores,edk::vector::Array<edk::vec2f32ColorGray>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //test the variables
    if(cores>1u && points && image && width && height){

        edk::uint32 start = 0u,end = 0u,lenght = height/cores; 
        edk::uint32 size = points->getSize(); 

        edk::Voronoi::ImageGray* list = NULL; 

        cores--; 
        //create the threads
        edk::multi::Thread* threadPointer=NULL; 
        edk::vector::Array<edk::multi::Thread*> threads; 
        if(threads.createArray(cores)){
            //start the cores
            for(edk::uint32 i=0u;i<cores;i++){
                end = start+lenght; 
                if(start>height){
                    start = height; 
                }
                if(end>height){
                    end = height; 
                }

                list = new edk::Voronoi::ImageGray; 
                if(list){
                    if(list->points.createArray(size)){
                        //copy the vector
                        for(edk::uint32 j=0u;j<size;j++){
                            list->points.set(j,points->get(j)); 
                        }
                        //copy the variables
                        list->image = image; 
                        list->width = width; 
                        list->height = height; 
                        list->start = start; 
                        list->end = end; 

                        //create the new thread
                        threadPointer = new edk::multi::Thread; 
                        if(threadPointer){
                            //start the thread
                            if(threadPointer->start(edk::Voronoi::runThreadGenerateImageRGBFromGray, (edk::classID)list)){
                                //set the thread pointer in the list
                                threads.set(i,threadPointer); 
                            }
                            else{
                                edk::Voronoi::runGenerateImageRGB(points,
                                                                  image,
                                                                  width,
                                                                  height,
                                                                  start,
                                                                  end
                                                                  ); 
                                delete list; 
                                delete threadPointer; 
                                threads.set(i,NULL); 
                            }
                        }
                        else{
                            delete list; 
                        }
                        threadPointer=NULL; 
                    }
                    else{
                        delete list; 
                    }
                }

                //
                start = end; 
                //increment the image
                image+=lenght * width * 3u; 
            }
            if(start<height){
                edk::Voronoi::runGenerateImageRGB(points,
                                                  image,
                                                  width,
                                                  height,
                                                  start,
                                                  height
                                                  ); 
            }
            for(edk::uint32 i=0u;i<cores;i++){
                //test if have the thread
                threadPointer = threads.get(i); 
                if(threadPointer){
                    threadPointer->waitEnd(); 
                    delete threadPointer; 
                }
            }
            threads.deleteArray(); 
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
        edk::vector::Array<edk::vec2f32ColorGray> points; 
        if(points.createArray(pointSize)){
            //start the rand
            edk::Random rand; 
            rand.loadStaticSeed(); 
            for(edk::uint32 i=0u;i<pointSize;i++){
                points.set(i,edk::vec2f32ColorGray(rand.getStaticRandPercent(),rand.getStaticRandPercent(),
                                                   (edk::uint8)rand.getStaticRandNumber()
                                                   )
                           ); 
            }

            //generate the image
            bool ret = edk::Voronoi::multiGenerateImageGray(cores,&points,image,width,height); 

            points.deleteArray(); 

            return ret;
        }
    }
    return false;
}
bool edk::Voronoi::multiGenerateImageGray(edk::uint32 cores,edk::vector::Array<edk::vec2f32ColorRGB>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //test the variables
    if(cores>1u && points && image && width && height){

        edk::uint32 start = 0u,end = 0u,lenght = height/cores; 
        edk::uint32 size = points->getSize(); 

        edk::Voronoi::ImageRGB* list = NULL; 

        cores--; 
        //create the threads
        edk::multi::Thread* threadPointer=NULL; 
        edk::vector::Array<edk::multi::Thread*> threads; 
        if(threads.createArray(cores)){
            //start the cores
            for(edk::uint32 i=0u;i<cores;i++){
                end = start+lenght; 
                if(start>height){
                    start = height; 
                }
                if(end>height){
                    end = height; 
                }

                list = new edk::Voronoi::ImageRGB; 
                if(list){
                    if(list->points.createArray(size)){
                        //copy the vector
                        for(edk::uint32 j=0u;j<size;j++){
                            list->points.set(j,points->get(j)); 
                        }
                        //copy the variables
                        list->image = image; 
                        list->width = width; 
                        list->height = height; 
                        list->start = start; 
                        list->end = end; 

                        //create the new thread
                        threadPointer = new edk::multi::Thread; 
                        if(threadPointer){
                            //start the thread
                            if(threadPointer->start(edk::Voronoi::runThreadGenerateImageGrayFromRGB, (edk::classID)list)){
                                //set the thread pointer in the list
                                threads.set(i,threadPointer); 
                            }
                            else{
                                edk::Voronoi::runGenerateImageRGB(points,
                                                                  image,
                                                                  width,
                                                                  height,
                                                                  start,
                                                                  end
                                                                  ); 
                                delete list; 
                                delete threadPointer; 
                                threads.set(i,NULL); 
                            }
                        }
                        else{
                            delete list; 
                        }
                        threadPointer=NULL; 
                    }
                    else{
                        delete list; 
                    }
                }

                //
                start = end; 
                //increment the image
                image+=lenght * width * 1u; 
            }
            if(start<height){
                edk::Voronoi::runGenerateImageRGB(points,
                                                  image,
                                                  width,
                                                  height,
                                                  start,
                                                  height
                                                  ); 
            }
            for(edk::uint32 i=0u;i<cores;i++){
                //test if have the thread
                threadPointer = threads.get(i); 
                if(threadPointer){
                    threadPointer->waitEnd(); 
                    delete threadPointer; 
                }
            }
            threads.deleteArray(); 
            //wait for the threads end
            return true;
        }

    }
    return false;
}
bool edk::Voronoi::multiGenerateImageGray(edk::uint32 cores,edk::vector::Array<edk::vec2f32ColorGray>* points,edk::uint8* image,edk::uint32 width,edk::uint32 height){
    //test the variables
    if(cores>1u && points && image && width && height){

        edk::uint32 start = 0u,end = 0u,lenght = height/cores; 
        edk::uint32 size = points->getSize(); 

        edk::Voronoi::ImageGray* list = NULL; 

        cores--; 
        //create the threads
        edk::multi::Thread* threadPointer=NULL; 
        edk::vector::Array<edk::multi::Thread*> threads; 
        if(threads.createArray(cores)){
            //start the cores
            for(edk::uint32 i=0u;i<cores;i++){
                end = start+lenght; 
                if(start>height){
                    start = height; 
                }
                if(end>height){
                    end = height; 
                }

                list = new edk::Voronoi::ImageGray; 
                if(list){
                    if(list->points.createArray(size)){
                        //copy the vector
                        for(edk::uint32 j=0u;j<size;j++){
                            list->points.set(j,points->get(j)); 
                        }
                        //copy the variables
                        list->image = image; 
                        list->width = width; 
                        list->height = height; 
                        list->start = start; 
                        list->end = end; 

                        //create the new thread
                        threadPointer = new edk::multi::Thread; 
                        if(threadPointer){
                            //start the thread
                            if(threadPointer->start(edk::Voronoi::runThreadGenerateImageGrayFromGray, (edk::classID)list)){
                                //set the thread pointer in the list
                                threads.set(i,threadPointer); 
                            }
                            else{
                                edk::Voronoi::runGenerateImageGray(points,
                                                                   image,
                                                                   width,
                                                                   height,
                                                                   start,
                                                                   end
                                                                   ); 
                                delete list; 
                                delete threadPointer; 
                                threads.set(i,NULL); 
                            }
                        }
                        else{
                            delete list; 
                        }
                        threadPointer=NULL; 
                    }
                    else{
                        delete list; 
                    }
                }

                //
                start = end; 
                //increment the image
                image+=lenght * width * 1u; 
            }
            if(start<height){
                edk::Voronoi::runGenerateImageGray(points,
                                                   image,
                                                   width,
                                                   height,
                                                   start,
                                                   height
                                                   ); 
            }
            for(edk::uint32 i=0u;i<cores;i++){
                //test if have the thread
                threadPointer = threads.get(i); 
                if(threadPointer){
                    threadPointer->waitEnd(); 
                    delete threadPointer; 
                }
            }
            threads.deleteArray(); 
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
            return edk::Voronoi::multiGenerateImageGray(cores,pointSize,image->getPixels(),image->getSize().width,image->getSize().height); 
            break;
        case 3u:
            return edk::Voronoi::multiGenerateImageRGB(cores,pointSize,image->getPixels(),image->getSize().width,image->getSize().height); 
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
            return edk::Voronoi::multiGenerateImageGray(cores,points,image->getPixels(),image->getSize().width,image->getSize().height); 
            break;
        case 3u:
            return edk::Voronoi::multiGenerateImageRGB(cores,points,image->getPixels(),image->getSize().width,image->getSize().height); 
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
            return edk::Voronoi::multiGenerateImageGray(cores,points,image->getPixels(),image->getSize().width,image->getSize().height); 
            break;
        case 3u:
            return edk::Voronoi::multiGenerateImageRGB(cores,points,image->getPixels(),image->getSize().width,image->getSize().height); 
            break;
        default:
            return false;
        }
    }
    return false;
}
