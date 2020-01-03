#include <stdio.h>

#include "edk/Image2D.h"
#include "edk/codecs/EncoderH264.h"
#include "edk/codecs/DecoderH264.h"

#define imageIN "imageIn.jpg"
#define imageOUT "imageOut.jpg"

int main(){
    //Image objects to encode and decode
    edk::Image2D in;
    edk::Image2D out;
    //load the imageFile
    if(in.loadFromFile(imageIN)){
        //get the imageSize to start the encoder
        edk::size2ui32 size;
        size.width = in.getWidth();
        size.height = in.getHeight();
        //test if the image is rgb
        if(in.getChannels() == 3u && size.width && size.height){
            //encoder and decoder objects
            edk::codecs::EncoderH264 enc;
            edk::codecs::DecoderH264 dec;
            //start the encoder for 60 fps
            if(enc.startEncoder(size,60u)){
                //encode the image IN
                if(enc.encode(in.getPixels(),in.getChannels())){
                    //after encode the frame, start the decoder
                    if(dec.startDecoder(enc.getEncodedUsedSize())){
                        //decode the encoded frame
                        if(dec.decode(enc.getEncoded(),enc.getEncodedUsedSize())){
                            //create the new image from the decoder
                            if(out.newImage("decoded.jpg",dec.getFrameWidth(),dec.getFrameHeight(),dec.getFrameChannels())){
                                //draw the image
                                out.draw(dec.getFrame());

                                //and save to file
                                out.saveToFile(imageOUT);

                                //delete the image OUT from the memory
                                out.deleteImage();
                            }
                        }
                        //finish the decoder
                        dec.finishDecoder();
                    }
                }
                //finish the encoder
                enc.finishEncoder();
            }
        }
        //delete the image IN from the memory
        in.deleteImage();
    }


    return 0;
}
