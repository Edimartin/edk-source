#include "OpenLamp.h"

edk::OpenLamp::OpenLamp()
{
}

//convert one pixel
edk::color3ui8 edk::OpenLamp::pixelToNormal(edk::uint8 up,edk::uint8 down,edk::uint8 left,edk::uint8 right,edk::uint8 front){
    edk::color3ui8 ret;
    //get the vertical and horizontal angles
    edk::int32 angleH = (edk::int32)((((edk::int32)right-(edk::int32)left)/255.f)*90u);
    edk::int32 angleV = (edk::int32)((((edk::int32)up-(edk::int32)down)/255.f)*90u);
    //load the R and G using sen 0 to 255 (0 == -128; 255 == 128)
    ret.r = (edk::uint32)((sin ( ( angleH * PI)/180)     * 127) + 127);
    ret.r = (edk::uint32)((edk::Math::getSinInt32(angleH) * 127) + 127);
    ret.g = (edk::uint32)((sin ( ( angleV * PI)/180)     * 127) + 127);
    ret.g = (edk::uint32)((edk::Math::getSinInt32(angleV) * 127) + 127);
    ret.b = front;

    return ret;
}
edk::color3ui8 edk::OpenLamp::pixelToNormal(edk::uint8 up,edk::uint8 down,edk::uint8 left,edk::uint8 right){
    edk::color3ui8 ret;
    //get the vertical and horizontal angles
    edk::int32 angleH = (edk::int32)((((edk::int32)right-(edk::int32)left)/255.f)*90u);
    edk::int32 angleV = (edk::int32)((((edk::int32)up-(edk::int32)down)/255.f)*90u);
    //load the R and G using sen 0 to 255 (0 == -128; 255 == 128)
    ret.r = (edk::uint32)((sin ( ( angleH * PI)/180)     * 127) + 127);
    ret.r = (edk::uint32)((edk::Math::getSinInt32(angleH) * 127) + 127);
    ret.g = (edk::uint32)((sin ( ( angleV * PI)/180)     * 127) + 127);
    ret.g = (edk::uint32)((edk::Math::getSinInt32(angleV) * 127) + 127);

    //load the two depth of the angles using cosin
    //edk::float32 depthV = cos ( ( angleV * PI)/180);
    edk::float32 depthV = edk::Math::getCosinInt32(angleV);
    //edk::float32 depthH = cos ( ( angleH * PI)/180);
    edk::float32 depthH = edk::Math::getCosinInt32(angleH);
    //test with depth is higher to calculate the middle point
    if(depthV > depthH){
        //calculate the mittle point
        ret.b = (edk::uint32)(((edk::int32)((depthV - depthH)*0.5f)+depthH)* 128) + 127u;
    }
    else{
        //calculate the mittle point
        ret.b = (edk::uint32)((edk::int32)(((depthH - depthV)*0.5f)+depthV)* 128) + 127u;
    }

    return ret;
}

//convert the vector
bool edk::OpenLamp::vectorToNormal(edk::uint8* up,edk::uint8 upChannels,
                                   edk::uint8* down,edk::uint8 downChannels,
                                   edk::uint8* left,edk::uint8 leftChannels,
                                   edk::uint8* right,edk::uint8 rightChannels,
                                   edk::uint8* front,edk::uint8 frontChannels,
                                   edk::uint8* normal,edk::uint32 pixelsSize
                                   ){
    //test if have the full vectors
    edk::color3ui8 temp;
    if(normal && pixelsSize){
        //try the front
        if(front && frontChannels){
            //try the vertical
            if(up && upChannels
                    &&
                    down && downChannels){
                //try the horizontal
                if(left && leftChannels
                        &&
                        right && rightChannels){
                    //FULL
                    for(edk::uint32 i=0u;i<pixelsSize;i++){
                        //get the pixel
                        temp = edk::OpenLamp::pixelToNormal(*up,*down,*left,*right,*front);
                        normal[0u]=temp.r;
                        normal[1u]=temp.g;
                        normal[2u]=temp.b;
                        //increment the vectors
                        up+=upChannels;down+=downChannels;left+=leftChannels;right+=rightChannels;front+=frontChannels;
                        normal+=3u;
                    }
                }
                else if(left && leftChannels){
                    //up down left
                    for(edk::uint32 i=0u;i<pixelsSize;i++){
                        //get the pixel
                        temp = edk::OpenLamp::pixelToNormal(*up,*down,*left,128,*front);
                        normal[0u]=temp.r;
                        normal[1u]=temp.g;
                        normal[2u]=temp.b;
                        //increment the vectors
                        up+=upChannels;down+=downChannels;left+=leftChannels;front+=frontChannels;
                        normal+=3u;
                    }
                }
                else if(right && rightChannels){
                    //up down right
                    for(edk::uint32 i=0u;i<pixelsSize;i++){
                        //get the pixel
                        temp = edk::OpenLamp::pixelToNormal(*up,*down,128,*right,*front);
                        normal[0u]=temp.r;
                        normal[1u]=temp.g;
                        normal[2u]=temp.b;
                        //increment the vectors
                        up+=upChannels;down+=downChannels;right+=rightChannels;front+=frontChannels;
                        normal+=3u;
                    }
                }
            }
            else if(up && upChannels){
                //try the horizontal
                if(left && leftChannels
                        &&
                        right && rightChannels){
                    //up left right
                    for(edk::uint32 i=0u;i<pixelsSize;i++){
                        //get the pixel
                        temp = edk::OpenLamp::pixelToNormal(*up,128,*left,*right,*front);
                        normal[0u]=temp.r;
                        normal[1u]=temp.g;
                        normal[2u]=temp.b;
                        //increment the vectors
                        up+=upChannels;left+=leftChannels;right+=rightChannels;front+=frontChannels;
                        normal+=3u;
                    }
                }
                else if(left && leftChannels){
                    //up left
                    for(edk::uint32 i=0u;i<pixelsSize;i++){
                        //get the pixel
                        temp = edk::OpenLamp::pixelToNormal(*up,128,*left,128,*front);
                        normal[0u]=temp.r;
                        normal[1u]=temp.g;
                        normal[2u]=temp.b;
                        //increment the vectors
                        up+=upChannels;left+=leftChannels;front+=frontChannels;
                        normal+=3u;
                    }
                }
                else if(right && rightChannels){
                    //up right
                    for(edk::uint32 i=0u;i<pixelsSize;i++){
                        //get the pixel
                        temp = edk::OpenLamp::pixelToNormal(*up,128,128,*right,*front);
                        normal[0u]=temp.r;
                        normal[1u]=temp.g;
                        normal[2u]=temp.b;
                        //increment the vectors
                        up+=upChannels;right+=rightChannels;front+=frontChannels;
                        normal+=3u;
                    }
                }
            }
            else if(down && downChannels){
                //try the horizontal
                if(left && leftChannels
                        &&
                        right && rightChannels){
                    //down left right
                    for(edk::uint32 i=0u;i<pixelsSize;i++){
                        //get the pixel
                        temp = edk::OpenLamp::pixelToNormal(128,*down,*left,*right,*front);
                        normal[0u]=temp.r;
                        normal[1u]=temp.g;
                        normal[2u]=temp.b;
                        //increment the vectors
                        down+=downChannels;left+=leftChannels;right+=rightChannels;front+=frontChannels;
                        normal+=3u;
                    }
                }
                else if(left && leftChannels){
                    //down left
                    for(edk::uint32 i=0u;i<pixelsSize;i++){
                        //get the pixel
                        temp = edk::OpenLamp::pixelToNormal(128,*down,*left,128,*front);
                        normal[0u]=temp.r;
                        normal[1u]=temp.g;
                        normal[2u]=temp.b;
                        //increment the vectors
                        down+=downChannels;left+=leftChannels;front+=frontChannels;
                        normal+=3u;
                    }
                }
                else if(right && rightChannels){
                    //down right
                    for(edk::uint32 i=0u;i<pixelsSize;i++){
                        //get the pixel
                        temp = edk::OpenLamp::pixelToNormal(128,*down,128,*right,*front);
                        normal[0u]=temp.r;
                        normal[1u]=temp.g;
                        normal[2u]=temp.b;
                        //increment the vectors
                        down+=downChannels;right+=rightChannels;front+=frontChannels;
                        normal+=3u;
                    }
                }
            }
        }


        //noFront
        else{
            //try the vertical
            if(up && upChannels
                    &&
                    down && downChannels){
                //try the horizontal
                if(left && leftChannels
                        &&
                        right && rightChannels){
                    //FULL
                    for(edk::uint32 i=0u;i<pixelsSize;i++){
                        //get the pixel
                        temp = edk::OpenLamp::pixelToNormal(*up,*down,*left,*right);
                        normal[0u]=temp.r;
                        normal[1u]=temp.g;
                        normal[2u]=temp.b;
                        //increment the vectors
                        up+=upChannels;down+=downChannels;left+=leftChannels;right+=rightChannels;
                        normal+=3u;
                    }
                }
                else if(left && leftChannels){
                    //up down left
                    for(edk::uint32 i=0u;i<pixelsSize;i++){
                        //get the pixel
                        temp = edk::OpenLamp::pixelToNormal(*up,*down,*left,128);
                        normal[0u]=temp.r;
                        normal[1u]=temp.g;
                        normal[2u]=temp.b;
                        //increment the vectors
                        up+=upChannels;down+=downChannels;left+=leftChannels;
                        normal+=3u;
                    }
                }
                else if(right && rightChannels){
                    //up down right
                    for(edk::uint32 i=0u;i<pixelsSize;i++){
                        //get the pixel
                        temp = edk::OpenLamp::pixelToNormal(*up,*down,128,*right);
                        normal[0u]=temp.r;
                        normal[1u]=temp.g;
                        normal[2u]=temp.b;
                        //increment the vectors
                        up+=upChannels;down+=downChannels;right+=rightChannels;
                        normal+=3u;
                    }
                }
            }
            else if(up && upChannels){
                //try the horizontal
                if(left && leftChannels
                        &&
                        right && rightChannels){
                    //up left right
                    for(edk::uint32 i=0u;i<pixelsSize;i++){
                        //get the pixel
                        temp = edk::OpenLamp::pixelToNormal(*up,128,*left,*right);
                        normal[0u]=temp.r;
                        normal[1u]=temp.g;
                        normal[2u]=temp.b;
                        //increment the vectors
                        up+=upChannels;left+=leftChannels;right+=rightChannels;
                        normal+=3u;
                    }
                }
                else if(left && leftChannels){
                    //up left
                    for(edk::uint32 i=0u;i<pixelsSize;i++){
                        //get the pixel
                        temp = edk::OpenLamp::pixelToNormal(*up,128,*left,128);
                        normal[0u]=temp.r;
                        normal[1u]=temp.g;
                        normal[2u]=temp.b;
                        //increment the vectors
                        up+=upChannels;left+=leftChannels;
                        normal+=3u;
                    }
                }
                else if(right && rightChannels){
                    //up right
                    for(edk::uint32 i=0u;i<pixelsSize;i++){
                        //get the pixel
                        temp = edk::OpenLamp::pixelToNormal(*up,128,128,*right);
                        normal[0u]=temp.r;
                        normal[1u]=temp.g;
                        normal[2u]=temp.b;
                        //increment the vectors
                        up+=upChannels;right+=rightChannels;
                        normal+=3u;
                    }
                }
            }
            else if(down && downChannels){
                //try the horizontal
                if(left && leftChannels
                        &&
                        right && rightChannels){
                    //down left right
                    for(edk::uint32 i=0u;i<pixelsSize;i++){
                        //get the pixel
                        temp = edk::OpenLamp::pixelToNormal(128,*down,*left,*right);
                        normal[0u]=temp.r;
                        normal[1u]=temp.g;
                        normal[2u]=temp.b;
                        //increment the vectors
                        down+=downChannels;left+=leftChannels;right+=rightChannels;
                        normal+=3u;
                    }
                }
                else if(left && leftChannels){
                    //down left
                    for(edk::uint32 i=0u;i<pixelsSize;i++){
                        //get the pixel
                        temp = edk::OpenLamp::pixelToNormal(128,*down,*left,128);
                        normal[0u]=temp.r;
                        normal[1u]=temp.g;
                        normal[2u]=temp.b;
                        //increment the vectors
                        down+=downChannels;left+=leftChannels;
                        normal+=3u;
                    }
                }
                else if(right && rightChannels){
                    //down right
                    for(edk::uint32 i=0u;i<pixelsSize;i++){
                        //get the pixel
                        temp = edk::OpenLamp::pixelToNormal(128,*down,128,*right);
                        normal[0u]=temp.r;
                        normal[1u]=temp.g;
                        normal[2u]=temp.b;
                        //increment the vectors
                        down+=downChannels;right+=rightChannels;
                        normal+=3u;
                    }
                }
            }
        }
    }
    return false;
}
bool edk::OpenLamp::imageToNormal(edk::Image2D* up,edk::Image2D* down,edk::Image2D* left,edk::Image2D* right,edk::Image2D* front,edk::Image2D* normal){
    edk::uint8* upTemp=NULL;
    edk::uint8* downTemp=NULL;
    edk::uint8* leftTemp=NULL;
    edk::uint8* rightTemp=NULL;
    edk::uint8* frontTemp=NULL;
    edk::uint8* normalTemp=NULL;
    edk::uint8 upChannels=0;
    edk::uint8 downChannels=0;
    edk::uint8 leftChannels=0;
    edk::uint8 rightChannels=0;
    edk::uint8 frontChannels=0;

    edk::uint32 width=0u;
    edk::uint32 height=0u;

    //load the up
    if(up){
        if(up->haveImage()){
            width = up->getWidth();
            height = up->getHeight();
            upTemp = up->getPixels();
            upChannels = up->getChannels();
        }
    }

    //load the down
    if(down){
        if(down->haveImage()){
            if(width == down->getWidth()
                    &&
                    height == down->getHeight()){
                downTemp = down->getPixels();
                downChannels = down->getChannels();
            }
        }
    }

    //load the left
    if(left){
        if(left->haveImage()){
            if(width == left->getWidth()
                    &&
                    height == left->getHeight()){
                leftTemp = left->getPixels();
                leftChannels = left->getChannels();
            }
        }
    }

    //load the right
    if(right){
        if(right->haveImage()){
            if(width == right->getWidth()
                    &&
                    height == right->getHeight()){
                rightTemp = right->getPixels();
                rightChannels = right->getChannels();
            }
        }
    }

    //load the front
    if(front){
        if(front->haveImage()){
            if(width == front->getWidth()
                    &&
                    height == front->getHeight()){
                frontTemp = front->getPixels();
                frontChannels = front->getChannels();
            }
        }
    }

    //create the image
    if(normal->newImage("normalMap",width,height,3u)){
        normalTemp = normal->getPixels();
    }

    //set the pixelSize
    edk::uint32 pixelsSize= width * height;

    return edk::OpenLamp::vectorToNormal(upTemp,upChannels,
                                         downTemp,downChannels,
                                         leftTemp,leftChannels,
                                         rightTemp,rightChannels,
                                         frontTemp,frontChannels,
                                         normalTemp,pixelsSize
                                         );
}