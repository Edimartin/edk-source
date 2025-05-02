#include "Polygon2D.h"

/*
Library Polygon2D - Draw a 2D Polygon in EDK Game Engine
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
#pragma message "            Inside Polygon2D.cpp"
#endif

bool edk::shape::Polygon2D::successTemplate=false;

edk::uint8 vboSizeofPolygon2D[edk::GU::vbo_Size] = {
    0u,                       //vbo_NULL = 0u,
    /*sizeof(edk::float32)* */2u , //vbo_XY,
    /*sizeof(edk::float32)* */3u , //vbo_XYZ,
    /*sizeof(edk::float32)* */5u , //vbo_XY_NxNyNz,
    /*sizeof(edk::float32)* */6u , //vbo_XYZ_NxNyNz,
    /*sizeof(edk::float32)* */5u , //vbo_XY_RGB,
    /*sizeof(edk::float32)* */6u , //vbo_XYZ_RGB,
    /*sizeof(edk::float32)* */6u , //vbo_XY_RGBA,
    /*sizeof(edk::float32)* */7u , //vbo_XYZ_RGBA,
    /*sizeof(edk::float32)* */8u , //vbo_XY_RGB_NxNyNz,
    /*sizeof(edk::float32)* */9u , //vbo_XYZ_RGB_NxNyNz,
    /*sizeof(edk::float32)* */9u , //vbo_XY_RGBA_NxNyNz,
    /*sizeof(edk::float32)* */10u, //vbo_XYZ_RGBA_NxNyNz,
    /*sizeof(edk::float32)* */10u, //vbo_XY_RGB_NxNyNz_UVxUVy,
    /*sizeof(edk::float32)* */11u, //vbo_XYZ_RGB_NxNyNz_UVxUVy,
    /*sizeof(edk::float32)* */11u, //vbo_XY_RGBA_NxNyNz_UVxUVy,
    /*sizeof(edk::float32)* */12u  //vbo_XYZ_RGBA_NxNyNz_UVxUVy,
};

edk::shape::Polygon2D::Polygon2D(){
    this->classThis=NULL;
    this->Constructor();
}
edk::shape::Polygon2D::Polygon2D(edk::uint32 vertexCount){
    this->classThis=NULL;
    this->Constructor(vertexCount);
}

edk::shape::Polygon2D::~Polygon2D(){
    this->Destructor();
}

void edk::shape::Polygon2D::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        this->vertexs.Constructor();
        this->vertexsOriginal.Constructor();
        this->vertexBuffer.Constructor();
        this->vertexsMorph.Constructor();
        this->matrixTranslate.Constructor();
        this->matrixRotate.Constructor();
        this->matrixScale.Constructor();
        this->matrixTransform.Constructor();
        this->matrixPosition.Constructor();

        this->vboType = edk::GU::vbo_NULL;
        this->vbo=0u;
        this->vboCount=0u;
        this->vertexBuffer.clean();
        this->canUseVBO=false;
        //set the vbo function pointers
        this->setVBOFunctionUpdateNULL();

        this->type = edk::shape::typePolygon2D;
        this->angle=0.f;
        this->radius = 1.f;
        //init the polygonCOlor
        this->polygonColor = edk::color4f32(1,1,1,1);
        //set frames to 1
        this->frames = edk::vec2ui32(1u,1u);
        this->framesSize = this->frames.x*this->frames.y;
        this->animationFrame=NULL;
        this->createAnimationFrames=false;

        //Physics parameters
        this->density=1.f;
        this->friction=0.0f;
        this->restitution=0.0f;

        this->polygonLine = this->polygonCircle=false;
        this->collisionID=collisionAways;

        this->frameUsing=edk::vec2ui32(0u,0u);
        this->matrixPosition.createMatrix(1u,3u);
        this->testTransform();
    }
}
void edk::shape::Polygon2D::Constructor(edk::uint32 vertexCount){
    if(this->classThis!=this){
        this->classThis=this;

        this->vertexs.Constructor();
        this->vertexsOriginal.Constructor();
        this->vertexBuffer.Constructor();
        this->vertexsMorph.Constructor();
        this->matrixTranslate.Constructor();
        this->matrixRotate.Constructor();
        this->matrixScale.Constructor();
        this->matrixTransform.Constructor();
        this->matrixPosition.Constructor();

        this->vboType = edk::GU::vbo_NULL;
        this->vbo=0u;
        this->vboCount=0u;
        this->vertexBuffer.clean();
        this->canUseVBO=false;
        //set the vbo function pointers
        this->setVBOFunctionUpdateNULL();
        this->angle=0.f;
        this->radius = 1.f;
        //
        this->polygonColor = edk::color4f32(0,0,0,1);
        //create the vertex
        this->createPolygon(vertexCount);
        //set frames to 1
        this->frames = edk::vec2ui32(1u,1u);
        this->createAnimationFrames=false;

        this->frameUsing=edk::vec2ui32(0u,0u);
        this->matrixPosition.createMatrix(1u,3u);
        this->testTransform();
    }
}
void edk::shape::Polygon2D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        //destroy the polygon
        this->deletePolygon();

        this->vertexs.Destructor();
        this->vertexsOriginal.Destructor();
        this->vertexBuffer.Destructor();
        this->vertexsMorph.Destructor();
        this->matrixTranslate.Destructor();
        this->matrixRotate.Destructor();
        this->matrixScale.Destructor();
        this->matrixTransform.Destructor();
        this->matrixPosition.Destructor();
    }
}

//PROTECTED
//set the vertexFrames animation
bool edk::shape::Polygon2D::setVertexUVFrames(edk::uint32 vertex,edk::vec2ui32 frames){
    //load the polygon
    edk::shape::Vertex2DAnimatedUV* vTemp = (edk::shape::Vertex2DAnimatedUV*)this->getVertexPointer(vertex);
    edk::shape::Vertex2DAnimatedUV* voTemp = (edk::shape::Vertex2DAnimatedUV*)this->getVertexOriginalPointer(vertex);
    if(vTemp && voTemp){
        //test if the vertex is not the AnimatedUV
        if(vTemp->getType() != EDK_SHAPE_ANIMATED_UV
                || voTemp->getType() != EDK_SHAPE_ANIMATED_UV
                ){
            //then delete the vTemp and create another with AnimatedUV
            edk::shape::Vertex2DAnimatedUV* uvTemp = new edk::shape::Vertex2DAnimatedUV();
            edk::shape::Vertex2DAnimatedUV* uvoTemp = new edk::shape::Vertex2DAnimatedUV();
            if(uvTemp && uvoTemp){
                //copy the vTemp content to uvTemp
                uvTemp->position = vTemp->position;
                uvTemp->color = vTemp->color;
                uvoTemp->position = voTemp->position;
                uvoTemp->color = voTemp->color;
                //test if have UV
                if(vTemp->getType()==EDK_SHAPE_UV){
                    //copy the UV
                    uvTemp->setUV(vTemp->getUV());
                }
                if(voTemp->getType()==EDK_SHAPE_UV){
                    //copy the UV
                    uvoTemp->setUV(voTemp->getUV());
                }

                //delete the vTemp
                delete vTemp;
                delete voTemp;
                //set vTemp the uvTemp
                vTemp=uvTemp;
                voTemp=uvoTemp;
                //set the vertex on the array
                this->vertexs.set(vertex,(edk::shape::Vertex2D*)vTemp);
                this->vertexsOriginal.set(vertex,(edk::shape::Vertex2D*)voTemp);
                //clean uvTemp
                uvTemp=NULL;
                uvoTemp=NULL;
            }
            else{
                //else return false
                return false;
            }
        }
        //set the frames
        vTemp->setUVFrames(frames);
        voTemp->setUVFrames(frames);

        this->updateVBOUV();

        //return true
        return true;
    }
    //else return false
    return false;
}

//function to create the VBO
bool edk::shape::Polygon2D::createVBO(edk::uint32 vertexCount,edk::GU::VBOType type){
    //delete the last VBO
    this->deleteVBO();
    //
    if(this->canUseVBO && vertexCount){
        //create the new VBO
        if(type && type<edk::GU::vbo_Size){
            //create the vertexBuffer
            if(this->vertexBuffer.createArray(vertexCount * vboSizeofPolygon2D[type])){
                edk::uint32 increment = vboSizeofPolygon2D[type];
                edk::uint32 size = vertexCount * increment;
                //clean the vertexBuffer
                switch(type){
                case edk::GU::vbo_XY:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);
                    }
                    break;
                case edk::GU::vbo_XY_NxNyNz:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);

                        this->vertexBuffer.set(i+2u,0.f);
                        this->vertexBuffer.set(i+3u,0.f);
                        this->vertexBuffer.set(i+4u,1.f);
                    }
                    break;
                case edk::GU::vbo_XY_RGB:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);

                        this->vertexBuffer.set(i+2u,1.f);
                        this->vertexBuffer.set(i+3u,1.f);
                        this->vertexBuffer.set(i+4u,1.f);
                    }
                    break;
                case edk::GU::vbo_XY_RGBA:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);

                        this->vertexBuffer.set(i+2u,1.f);
                        this->vertexBuffer.set(i+3u,1.f);
                        this->vertexBuffer.set(i+4u,1.f);
                        this->vertexBuffer.set(i+5u,1.f);
                    }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);

                        this->vertexBuffer.set(i+2u,1.f);
                        this->vertexBuffer.set(i+3u,1.f);
                        this->vertexBuffer.set(i+4u,1.f);

                        this->vertexBuffer.set(i+5u,0.f);
                        this->vertexBuffer.set(i+6u,0.f);
                        this->vertexBuffer.set(i+7u,1.f);
                    }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);

                        this->vertexBuffer.set(i+2u,1.f);
                        this->vertexBuffer.set(i+3u,1.f);
                        this->vertexBuffer.set(i+4u,1.f);
                        this->vertexBuffer.set(i+5u,1.f);

                        this->vertexBuffer.set(i+6u,0.f);
                        this->vertexBuffer.set(i+7u,0.f);
                        this->vertexBuffer.set(i+8u,1.f);
                    }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);

                        this->vertexBuffer.set(i+2u,1.f);
                        this->vertexBuffer.set(i+3u,1.f);
                        this->vertexBuffer.set(i+4u,1.f);

                        this->vertexBuffer.set(i+5u,0.f);
                        this->vertexBuffer.set(i+6u,0.f);
                        this->vertexBuffer.set(i+7u,1.f);

                        this->vertexBuffer.set(i+8u,0.f);
                        this->vertexBuffer.set(i+9u,0.f);
                    }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);

                        this->vertexBuffer.set(i+2u,1.f);
                        this->vertexBuffer.set(i+3u,1.f);
                        this->vertexBuffer.set(i+4u,1.f);
                        this->vertexBuffer.set(i+5u,1.f);

                        this->vertexBuffer.set(i+6u,0.f);
                        this->vertexBuffer.set(i+7u,0.f);
                        this->vertexBuffer.set(i+8u,1.f);

                        this->vertexBuffer.set(i+9u,0.f);
                        this->vertexBuffer.set(i+10u,0.f);
                    }
                    break;
                case edk::GU::vbo_XYZ:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);
                        this->vertexBuffer.set(i+2u,0.f);
                    }
                    break;
                case edk::GU::vbo_XYZ_NxNyNz:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);
                        this->vertexBuffer.set(i+2u,0.f);

                        this->vertexBuffer.set(i+3u,0.f);
                        this->vertexBuffer.set(i+4u,0.f);
                        this->vertexBuffer.set(i+5u,1.f);
                    }
                    break;
                case edk::GU::vbo_XYZ_RGB:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);
                        this->vertexBuffer.set(i+2u,0.f);

                        this->vertexBuffer.set(i+3u,1.f);
                        this->vertexBuffer.set(i+4u,1.f);
                        this->vertexBuffer.set(i+5u,1.f);
                    }
                    break;
                case edk::GU::vbo_XYZ_RGBA:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);
                        this->vertexBuffer.set(i+2u,0.f);

                        this->vertexBuffer.set(i+3u,1.f);
                        this->vertexBuffer.set(i+4u,1.f);
                        this->vertexBuffer.set(i+5u,1.f);
                        this->vertexBuffer.set(i+6u,1.f);
                    }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);
                        this->vertexBuffer.set(i+2u,0.f);

                        this->vertexBuffer.set(i+3u,1.f);
                        this->vertexBuffer.set(i+4u,1.f);
                        this->vertexBuffer.set(i+5u,1.f);

                        this->vertexBuffer.set(i+6u,0.f);
                        this->vertexBuffer.set(i+7u,0.f);
                        this->vertexBuffer.set(i+8u,1.f);
                    }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);
                        this->vertexBuffer.set(i+2u,0.f);

                        this->vertexBuffer.set(i+3u,1.f);
                        this->vertexBuffer.set(i+4u,1.f);
                        this->vertexBuffer.set(i+5u,1.f);
                        this->vertexBuffer.set(i+6u,1.f);

                        this->vertexBuffer.set(i+7u,0.f);
                        this->vertexBuffer.set(i+8u,0.f);
                        this->vertexBuffer.set(i+9u,1.f);
                    }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);
                        this->vertexBuffer.set(i+2u,0.f);

                        this->vertexBuffer.set(i+3u,1.f);
                        this->vertexBuffer.set(i+4u,1.f);
                        this->vertexBuffer.set(i+5u,1.f);

                        this->vertexBuffer.set(i+6u,0.f);
                        this->vertexBuffer.set(i+7u,0.f);
                        this->vertexBuffer.set(i+8u,1.f);

                        this->vertexBuffer.set(i+9u,0.f);
                        this->vertexBuffer.set(i+10u,0.f);
                    }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);
                        this->vertexBuffer.set(i+2u,0.f);

                        this->vertexBuffer.set(i+3u,1.f);
                        this->vertexBuffer.set(i+4u,1.f);
                        this->vertexBuffer.set(i+5u,1.f);
                        this->vertexBuffer.set(i+6u,1.f);

                        this->vertexBuffer.set(i+7u,0.f);
                        this->vertexBuffer.set(i+8u,0.f);
                        this->vertexBuffer.set(i+9u,1.f);

                        this->vertexBuffer.set(i+10u,0.f);
                        this->vertexBuffer.set(i+11u,0.f);
                    }
                    break;
                default:
                    break;
                }


                //alloc the vertexBuffer in GU
                this->vbo = edk::GU_GLSL::guAllocBuffer(GU_ARRAY_BUFFER);
                if(this->vbo){
                    if(edk::GU_GLSL::guBufferData(GU_ARRAY_BUFFER, this->vertexBuffer.getSize() * sizeof(edk::float32), this->vertexBuffer.getPointer(), GU_STATIC_DRAW)){
                        edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
                        //save the type
                        this->vboType = type;
                        this->vboCount=vertexCount;

                        //update the VBO functions
                        this->setAutomaticallyVBOFunctions();

                        return true;
                    }
                    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);

                    //else delete the bugger
                    edk::GU_GLSL::guDeleteBuffer(this->vbo);
                    this->vbo=0u;
                }
                //else delete the vertexBuffer
                this->vertexBuffer.clean();
            }
        }
    }
    return false;
}
//run the GU function to update the VBO
bool edk::shape::Polygon2D::updateVBO(){
    if(this->haveVBO() && this->vertexBuffer.getSize()){
        edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);
        if(edk::GU_GLSL::guBufferData(GU_ARRAY_BUFFER, this->vertexBuffer.getSize() * sizeof(edk::float32), this->vertexBuffer.getPointer(), GU_STATIC_DRAW)){
            edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
            return true;
        }
        edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
    }
    return false;
}
bool edk::shape::Polygon2D::changeVBO(edk::GU::VBOType type){
    if(this->canUseVBO && type != this->vboType && type!=edk::GU::vbo_NULL && type<edk::GU::vbo_Size){
        edk::vector::Array<edk::float32> buffer;
        if(buffer.createArray(this->vboCount * vboSizeofPolygon2D[type])){
            edk::uint32 increment = vboSizeofPolygon2D[type];
            edk::uint32 size = this->vboCount*increment;
            //clean the vertexBuffer
            switch(type){
            case edk::GU::vbo_XY:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);
                }
                break;
            case edk::GU::vbo_XY_NxNyNz:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);

                    buffer.set(i+2u,0.f);
                    buffer.set(i+3u,0.f);
                    buffer.set(i+4u,1.f);
                }
                break;
            case edk::GU::vbo_XY_RGB:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);

                    buffer.set(i+2u,1.f);
                    buffer.set(i+3u,1.f);
                    buffer.set(i+4u,1.f);
                }
                break;
            case edk::GU::vbo_XY_RGBA:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);

                    buffer.set(i+2u,1.f);
                    buffer.set(i+3u,1.f);
                    buffer.set(i+4u,1.f);
                    buffer.set(i+5u,1.f);
                }
                break;
            case edk::GU::vbo_XY_RGB_NxNyNz:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);

                    buffer.set(i+2u,1.f);
                    buffer.set(i+3u,1.f);
                    buffer.set(i+4u,1.f);

                    buffer.set(i+5u,0.f);
                    buffer.set(i+6u,0.f);
                    buffer.set(i+7u,1.f);
                }
                break;
            case edk::GU::vbo_XY_RGBA_NxNyNz:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);

                    buffer.set(i+2u,1.f);
                    buffer.set(i+3u,1.f);
                    buffer.set(i+4u,1.f);
                    buffer.set(i+5u,1.f);

                    buffer.set(i+6u,0.f);
                    buffer.set(i+7u,0.f);
                    buffer.set(i+8u,1.f);
                }
                break;
            case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);

                    buffer.set(i+2u,1.f);
                    buffer.set(i+3u,1.f);
                    buffer.set(i+4u,1.f);

                    buffer.set(i+5u,0.f);
                    buffer.set(i+6u,0.f);
                    buffer.set(i+7u,1.f);

                    buffer.set(i+8u,0.f);
                    buffer.set(i+9u,0.f);
                }
                break;
            case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);

                    buffer.set(i+2u,1.f);
                    buffer.set(i+3u,1.f);
                    buffer.set(i+4u,1.f);
                    buffer.set(i+5u,1.f);

                    buffer.set(i+6u,0.f);
                    buffer.set(i+7u,0.f);
                    buffer.set(i+8u,1.f);

                    buffer.set(i+9u,0.f);
                    buffer.set(i+10u,0.f);
                }
                break;
            case edk::GU::vbo_XYZ:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);
                    buffer.set(i+2u,0.f);
                }
                break;
            case edk::GU::vbo_XYZ_NxNyNz:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);
                    buffer.set(i+2u,0.f);

                    buffer.set(i+3u,0.f);
                    buffer.set(i+4u,0.f);
                    buffer.set(i+5u,1.f);
                }
                break;
            case edk::GU::vbo_XYZ_RGB:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);
                    buffer.set(i+2u,0.f);

                    buffer.set(i+3u,1.f);
                    buffer.set(i+4u,1.f);
                    buffer.set(i+5u,1.f);
                }
                break;
            case edk::GU::vbo_XYZ_RGBA:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);
                    buffer.set(i+2u,0.f);

                    buffer.set(i+3u,1.f);
                    buffer.set(i+4u,1.f);
                    buffer.set(i+5u,1.f);
                    buffer.set(i+6u,1.f);
                }
                break;
            case edk::GU::vbo_XYZ_RGB_NxNyNz:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);
                    buffer.set(i+2u,0.f);

                    buffer.set(i+3u,1.f);
                    buffer.set(i+4u,1.f);
                    buffer.set(i+5u,1.f);

                    buffer.set(i+6u,0.f);
                    buffer.set(i+7u,0.f);
                    buffer.set(i+8u,1.f);
                }
                break;
            case edk::GU::vbo_XYZ_RGBA_NxNyNz:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);
                    buffer.set(i+2u,0.f);

                    buffer.set(i+3u,1.f);
                    buffer.set(i+4u,1.f);
                    buffer.set(i+5u,1.f);
                    buffer.set(i+6u,1.f);

                    buffer.set(i+7u,0.f);
                    buffer.set(i+8u,0.f);
                    buffer.set(i+9u,1.f);
                }
                break;
            case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);
                    buffer.set(i+2u,0.f);

                    buffer.set(i+3u,1.f);
                    buffer.set(i+4u,1.f);
                    buffer.set(i+5u,1.f);

                    buffer.set(i+6u,0.f);
                    buffer.set(i+7u,0.f);
                    buffer.set(i+8u,1.f);

                    buffer.set(i+9u,0.f);
                    buffer.set(i+10u,0.f);
                }
                break;
            case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);
                    buffer.set(i+2u,0.f);

                    buffer.set(i+3u,1.f);
                    buffer.set(i+4u,1.f);
                    buffer.set(i+5u,1.f);
                    buffer.set(i+6u,1.f);

                    buffer.set(i+7u,0.f);
                    buffer.set(i+8u,0.f);
                    buffer.set(i+9u,1.f);

                    buffer.set(i+10u,0.f);
                    buffer.set(i+11u,0.f);
                }
                break;
            default:
                break;
            }

            edk::uint32 source=0u,dest=0u;
            //
            switch(this->vboType){
            case edk::GU::vbo_XY:
            {
                for(edk::uint32 i=0u;i<this->vboCount;i++){
                    buffer.set(dest,this->vertexBuffer.get(source));
                    buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                    source+=vboSizeofPolygon2D[this->vboType];
                    dest+=vboSizeofPolygon2D[type];
                }
            }
                break;
            case edk::GU::vbo_XY_NxNyNz:
            {
                switch(type){
                case edk::GU::vbo_XY:
                {
                    //vbo_XY_NxNyNz -> edk::GU::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB:
                {
                    //vbo_XY_NxNyNz -> edk::GU::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA:
                {
                    //vbo_XY_NxNyNz -> edk::GU::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz:
                {
                    //vbo_XY_NxNyNz -> edk::GU::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz:
                {
                    //vbo_XY_NxNyNz -> edk::GU::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //vbo_XY_NxNyNz -> edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //vbo_XY_NxNyNz -> edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ:
                {
                    //vbo_XY_NxNyNz -> edk::GU::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_NxNyNz:
                {
                    //vbo_XY_NxNyNz -> edk::GU::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB:
                {
                    //vbo_XY_NxNyNz -> edk::GU::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA:
                {
                    //vbo_XY_NxNyNz -> edk::GU::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz:
                {
                    //vbo_XY_NxNyNz -> edk::GU::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz:
                {
                    //vbo_XY_NxNyNz -> edk::GU::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //vbo_XY_NxNyNz -> edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //vbo_XY_NxNyNz -> edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::GU::vbo_XY_RGB:
            {
                switch(type){
                case edk::GU::vbo_XY:
                {
                    //edk::GU::vbo_XY_RGB -> edk::GU::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGB -> edk::GU::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA:
                {
                    //edk::GU::vbo_XY_RGB -> edk::GU::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGB -> edk::GU::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGB -> edk::GU::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGB -> edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGB -> edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ:
                {
                    //edk::GU::vbo_XY_RGB -> edk::GU::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGB -> edk::GU::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB:
                {
                    //edk::GU::vbo_XY_RGB -> edk::GU::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA:
                {
                    //edk::GU::vbo_XY_RGB -> edk::GU::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGB -> edk::GU::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGB -> edk::GU::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGB -> edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGB -> edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::GU::vbo_XY_RGBA:
            {
                switch(type){
                case edk::GU::vbo_XY:
                {
                    //edk::GU::vbo_XY_RGBA -> edk::GU::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGBA -> edk::GU::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB:
                {
                    //edk::GU::vbo_XY_RGBA -> edk::GU::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGBA -> edk::GU::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGBA -> edk::GU::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGBA -> edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGBA -> edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ:
                {
                    //edk::GU::vbo_XY_RGBA -> edk::GU::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGBA -> edk::GU::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB:
                {
                    //edk::GU::vbo_XY_RGBA -> edk::GU::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA:
                {
                    //edk::GU::vbo_XY_RGBA -> edk::GU::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGBA -> edk::GU::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGBA -> edk::GU::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGBA -> edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGBA -> edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::GU::vbo_XY_RGB_NxNyNz:
            {
                switch(type){
                case edk::GU::vbo_XY:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz -> edk::GU::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz -> edk::GU::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz -> edk::GU::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz -> edk::GU::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz -> edk::GU::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz -> edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz -> edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz -> edk::GU::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz -> edk::GU::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz -> edk::GU::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz -> edk::GU::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz -> edk::GU::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz -> edk::GU::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz -> edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz -> edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::GU::vbo_XY_RGBA_NxNyNz:
            {
                switch(type){
                case edk::GU::vbo_XY:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz -> edk::GU::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz -> edk::GU::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz -> edk::GU::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz -> edk::GU::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz -> edk::GU::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz -> edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz -> edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz -> edk::GU::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz -> edk::GU::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz -> edk::GU::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz -> edk::GU::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz -> edk::GU::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz -> edk::GU::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz -> edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz -> edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
            {
                switch(type){
                case edk::GU::vbo_XY:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));

                        buffer.set(dest+9u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+10u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));

                        buffer.set(dest+9u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+10u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+7u));

                        buffer.set(dest+10u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+11u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
            {
                switch(type){
                case edk::GU::vbo_XY:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));

                        buffer.set(dest+8u,this->vertexBuffer.get(source+9u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+10u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));

                        buffer.set(dest+9u,this->vertexBuffer.get(source+9u));
                        buffer.set(dest+10u,this->vertexBuffer.get(source+10u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+8u));

                        buffer.set(dest+10u,this->vertexBuffer.get(source+9u));
                        buffer.set(dest+11u,this->vertexBuffer.get(source+10u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::GU::vbo_XYZ:
            {
                switch(type){
                case edk::GU::vbo_XY:
                {
                    //edk::GU::vbo_XYZ -> edk::GU::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_NxNyNz:
                {
                    //edk::GU::vbo_XYZ -> edk::GU::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB:
                {
                    //edk::GU::vbo_XYZ -> edk::GU::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA:
                {
                    //edk::GU::vbo_XYZ -> edk::GU::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XYZ -> edk::GU::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XYZ -> edk::GU::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));


                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ -> edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ -> edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_NxNyNz:
                {
                    //edk::GU::vbo_XYZ -> edk::GU::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB:
                {
                    //edk::GU::vbo_XYZ -> edk::GU::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA:
                {
                    //edk::GU::vbo_XYZ -> edk::GU::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XYZ -> edk::GU::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XYZ -> edk::GU::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ -> edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ -> edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::GU::vbo_XYZ_NxNyNz:
            {
                switch(type){
                case edk::GU::vbo_XY:
                {
                    //edk::GU::vbo_XYZ_NxNyNz -> edk::GU::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_NxNyNz -> edk::GU::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB:
                {
                    //edk::GU::vbo_XYZ_NxNyNz -> edk::GU::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA:
                {
                    //edk::GU::vbo_XYZ_NxNyNz -> edk::GU::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_NxNyNz -> edk::GU::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_NxNyNz -> edk::GU::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_NxNyNz -> edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_NxNyNz -> edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ:
                {
                    //edk::GU::vbo_XYZ_NxNyNz -> edk::GU::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB:
                {
                    //edk::GU::vbo_XYZ_NxNyNz -> edk::GU::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA:
                {
                    //edk::GU::vbo_XYZ_NxNyNz -> edk::GU::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_NxNyNz -> edk::GU::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_NxNyNz -> edk::GU::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_NxNyNz -> edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_NxNyNz -> edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::GU::vbo_XYZ_RGB:
            {
                switch(type){
                case edk::GU::vbo_XY:
                {
                    //edk::GU::vbo_XYZ_RGB -> edk::GU::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGB -> edk::GU::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB:
                {
                    //edk::GU::vbo_XYZ_RGB -> edk::GU::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA:
                {
                    //edk::GU::vbo_XYZ_RGB -> edk::GU::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGB -> edk::GU::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGB -> edk::GU::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGB -> edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGB -> edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ:
                {
                    //edk::GU::vbo_XYZ_RGB -> edk::GU::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGB -> edk::GU::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA:
                {
                    //edk::GU::vbo_XYZ_RGB -> edk::GU::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGB -> edk::GU::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGB -> edk::GU::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));


                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGB -> edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGB -> edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::GU::vbo_XYZ_RGBA:
            {
                switch(type){
                case edk::GU::vbo_XY:
                {
                    //edk::GU::vbo_XYZ_RGBA -> edk::GU::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGBA -> edk::GU::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB:
                {
                    //edk::GU::vbo_XYZ_RGBA -> edk::GU::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA:
                {
                    //edk::GU::vbo_XYZ_RGBA -> edk::GU::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGBA -> edk::GU::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGBA -> edk::GU::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGBA -> edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGBA -> edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ:
                {
                    //edk::GU::vbo_XYZ_RGBA -> edk::GU::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGBA -> edk::GU::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB:
                {
                    //edk::GU::vbo_XYZ_RGBA -> edk::GU::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGBA -> edk::GU::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGBA -> edk::GU::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGBA -> edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGBA -> edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::GU::vbo_XYZ_RGB_NxNyNz:
            {
                switch(type){
                case edk::GU::vbo_XY:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz -> edk::GU::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz -> edk::GU::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz -> edk::GU::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz -> edk::GU::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz -> edk::GU::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz -> edk::GU::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz -> edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz -> edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz -> edk::GU::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz -> edk::GU::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz -> edk::GU::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz -> edk::GU::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz -> edk::GU::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz -> edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz -> edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+8u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+10u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::GU::vbo_XYZ_RGBA_NxNyNz:
            {
                switch(type){
                case edk::GU::vbo_XY:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz -> edk::GU::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz -> edk::GU::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz -> edk::GU::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz -> edk::GU::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz -> edk::GU::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz -> edk::GU::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz -> edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz -> edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz -> edk::GU::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz -> edk::GU::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz -> edk::GU::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz -> edk::GU::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz -> edk::GU::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz -> edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz -> edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            {
                switch(type){
                case edk::GU::vbo_XY:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));

                        buffer.set(dest+8u,this->vertexBuffer.get(source+9u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+10u));
                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));

                        buffer.set(dest+9u,this->vertexBuffer.get(source+9u));
                        buffer.set(dest+10u,this->vertexBuffer.get(source+10u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+8u));

                        buffer.set(dest+10u,this->vertexBuffer.get(source+9u));
                        buffer.set(dest+11u,this->vertexBuffer.get(source+10u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            {
                switch(type){
                case edk::GU::vbo_XY:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+9u));

                        buffer.set(dest+8u,this->vertexBuffer.get(source+10u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+11u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+9u));

                        buffer.set(dest+9u,this->vertexBuffer.get(source+10u));
                        buffer.set(dest+10u,this->vertexBuffer.get(source+11u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+9u));

                        buffer.set(dest+9u,this->vertexBuffer.get(source+10u));
                        buffer.set(dest+10u,this->vertexBuffer.get(source+11u));

                        source+=vboSizeofPolygon2D[this->vboType];
                        dest+=vboSizeofPolygon2D[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            default:
                break;
            }
            //clone the buffer
            this->vertexBuffer.cloneFrom(&buffer);
            this->vboType = type;
            //set the update funtions
            this->updateVBOFunctions();
            return true;
        }
    }
    return false;
}
void edk::shape::Polygon2D::deleteVBO(){
    if(this->vbo){
        edk::GU_GLSL::guDeleteBuffer(this->vbo);
        this->vbo=0u;
    }
    if(this->vertexBuffer.size()){
        this->vertexBuffer.deleteArray();
    }
    this->vboType = edk::GU::vbo_NULL;
    this->vboCount=0u;
}
bool edk::shape::Polygon2D::haveVBO(){
    return (bool)(this->canUseVBO && this->vbo);
}
//set the vboFunction pointers
bool edk::shape::Polygon2D::updateVBOFunctions(){
    if(this->haveVBO()){
        switch(this->vboType){
        case edk::GU::vbo_XY:
            this->vboPrint = &edk::shape::Polygon2D::print_XY;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XY;
            break;
        case edk::GU::vbo_XY_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XY_NxNyNz;
            break;
        case edk::GU::vbo_XY_RGB:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGB;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XY_RGB;
            break;
        case edk::GU::vbo_XY_RGBA:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGBA;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XY_RGBA;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGB_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XY_RGB_NxNyNz;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGBA_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XY_RGBA_NxNyNz;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGB_NxNyNz_UVxUVy;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XY_RGB_NxNyNz_UVxUVy;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGBA_NxNyNz_UVxUVy;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XY_RGBA_NxNyNz_UVxUVy;
            break;
        case edk::GU::vbo_XYZ:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XYZ;
            break;
        case edk::GU::vbo_XYZ_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XYZ_NxNyNz;
            break;
        case edk::GU::vbo_XYZ_RGB:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGB;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XYZ_RGB;
            break;
        case edk::GU::vbo_XYZ_RGBA:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGBA;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XYZ_RGBA;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGB_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XYZ_RGB_NxNyNz;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGBA_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XYZ_RGBA_NxNyNz;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGB_NxNyNz_UVxUVy;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XYZ_RGB_NxNyNz_UVxUVy;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGBA_NxNyNz_UVxUVy;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XYZ_RGBA_NxNyNz_UVxUVy;
            break;
        default:
            this->vboPrint = &edk::shape::Polygon2D::print_NULL;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_NULL;
            break;
        }
        return true;
    }
    this->setVBOFunctionUpdateNULL();
    return false;
}
bool edk::shape::Polygon2D::setAutomaticallyVBOFunctions(){
    if(this->haveVBO()){
        switch(this->vboType){
        case edk::GU::vbo_XY:
            this->vboPrint = &edk::shape::Polygon2D::print_XY;
            this->vboDraw = &edk::shape::Polygon2D::draw_XY;
            break;
        case edk::GU::vbo_XY_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::draw_XY_NxNyNz;
            break;
        case edk::GU::vbo_XY_RGB:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGB;
            this->vboDraw = &edk::shape::Polygon2D::draw_XY_RGB;
            break;
        case edk::GU::vbo_XY_RGBA:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGBA;
            this->vboDraw = &edk::shape::Polygon2D::draw_XY_RGBA;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGB_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::draw_XY_RGB_NxNyNz;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGBA_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::draw_XY_RGBA_NxNyNz;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGB_NxNyNz_UVxUVy;
            this->vboDraw = &edk::shape::Polygon2D::draw_XY_RGB_NxNyNz_UVxUVy;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGBA_NxNyNz_UVxUVy;
            this->vboDraw = &edk::shape::Polygon2D::draw_XY_RGBA_NxNyNz_UVxUVy;
            break;
        case edk::GU::vbo_XYZ:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ;
            this->vboDraw = &edk::shape::Polygon2D::draw_XYZ;
            break;
        case edk::GU::vbo_XYZ_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_NxNyNz;
            break;
        case edk::GU::vbo_XYZ_RGB:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGB;
            this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_RGB;
            break;
        case edk::GU::vbo_XYZ_RGBA:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGBA;
            this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_RGBA;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGB_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_RGB_NxNyNz;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGBA_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_RGBA_NxNyNz;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGB_NxNyNz_UVxUVy;
            this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_RGB_NxNyNz_UVxUVy;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGBA_NxNyNz_UVxUVy;
            this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_RGBA_NxNyNz_UVxUVy;
            break;
        default:
            this->vboPrint = &edk::shape::Polygon2D::print_NULL;
            this->vboDraw = &edk::shape::Polygon2D::draw_NULL;
            break;
        }
        return true;
    }
    this->setVBOFunctionUpdateNULL();
    return false;
}
void edk::shape::Polygon2D::setVBOFunctionUpdateNULL(){
    this->vboPrint = &edk::shape::Polygon2D::print_NULL;
    this->vboDraw = &edk::shape::Polygon2D::drawUpdate_NULL;
}
void edk::shape::Polygon2D::setVBOFunctionNULL(){
    this->vboPrint = &edk::shape::Polygon2D::print_NULL;
    this->vboDraw = &edk::shape::Polygon2D::draw_NULL;
}
//setters to VBO
bool edk::shape::Polygon2D::setVBOVertexPosition(edk::uint32 vertex,edk::vec2f32 position){
    //set the vertex position in vertexBuffer
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        //calculate the vertex position
        vertex *= vboSizeofPolygon2D[this->vboType];
        //switch(this->vboType){
        //case edk::GU::vbo_XY:
        //    break;
        //case edk::GU::vbo_XY_NxNyNz:
        //    break;
        //case edk::GU::vbo_XY_RGB:
        //    break;
        //case edk::GU::vbo_XY_RGBA:
        //    break;
        //case edk::GU::vbo_XY_RGB_NxNyNz:
        //    break;
        //case edk::GU::vbo_XY_RGBA_NxNyNz:
        //    break;
        //case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
        //    break;
        //case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
        //    break;
        //case edk::GU::vbo_XYZ:
        //    break;
        //case edk::GU::vbo_XYZ_NxNyNz:
        //    break;
        //case edk::GU::vbo_XYZ_RGB:
        //    break;
        //case edk::GU::vbo_XYZ_RGBA:
        //    break;
        //case edk::GU::vbo_XYZ_RGB_NxNy:
        //    break;
        //case edk::GU::vbo_XYZ_RGBA_NxNy:
        //    break;
        //case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
        //    break;
        //case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
        //    break;
        //default:
        //    break;
        //}
        //set the position
        this->vertexBuffer.set(vertex,position.x);
        vertex++;
        this->vertexBuffer.set(vertex,position.y);

        //update the VBO
        this->updateVBOFunctions();

        return true;
    }
    return false;
}
bool edk::shape::Polygon2D::setVBOVertexPositionX(edk::uint32 vertex,edk::float32 x){
    //set the vertex position in vertexBuffer
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        //calculate the vertex position
        vertex *= vboSizeofPolygon2D[this->vboType];
        //switch(this->vboType){
        //case edk::GU::vbo_XY:
        //    break;
        //case edk::GU::vbo_XY_NxNyNz:
        //    break;
        //case edk::GU::vbo_XY_RGB:
        //    break;
        //case edk::GU::vbo_XY_RGBA:
        //    break;
        //case edk::GU::vbo_XY_RGB_NxNyNz:
        //    break;
        //case edk::GU::vbo_XY_RGBA_NxNyNz:
        //    break;
        //case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
        //    break;
        //case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
        //    break;
        //case edk::GU::vbo_XYZ:
        //    break;
        //case edk::GU::vbo_XYZ_NxNyNz:
        //    break;
        //case edk::GU::vbo_XYZ_RGB:
        //    break;
        //case edk::GU::vbo_XYZ_RGBA:
        //    break;
        //case edk::GU::vbo_XYZ_RGB_NxNy:
        //    break;
        //case edk::GU::vbo_XYZ_RGBA_NxNy:
        //    break;
        //case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
        //    break;
        //case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
        //    break;
        //default:
        //    break;
        //}
        //set the position
        this->vertexBuffer.set(vertex,x);

        //update the VBO
        this->updateVBOFunctions();

        return true;
    }
    return false;
}
bool edk::shape::Polygon2D::setVBOVertexPositionY(edk::uint32 vertex,edk::float32 y){
    //set the vertex position in vertexBuffer
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        //calculate the vertex position
        vertex *= vboSizeofPolygon2D[this->vboType];
        //switch(this->vboType){
        //case edk::GU::vbo_XY:
        //    break;
        //case edk::GU::vbo_XY_NxNyNz:
        //    break;
        //case edk::GU::vbo_XY_RGB:
        //    break;
        //case edk::GU::vbo_XY_RGBA:
        //    break;
        //case edk::GU::vbo_XY_RGB_NxNyNz:
        //    break;
        //case edk::GU::vbo_XY_RGBA_NxNyNz:
        //    break;
        //case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
        //    break;
        //case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
        //    break;
        //case edk::GU::vbo_XYZ:
        //    break;
        //case edk::GU::vbo_XYZ_NxNyNz:
        //    break;
        //case edk::GU::vbo_XYZ_RGB:
        //    break;
        //case edk::GU::vbo_XYZ_RGBA:
        //    break;
        //case edk::GU::vbo_XYZ_RGB_NxNy:
        //    break;
        //case edk::GU::vbo_XYZ_RGBA_NxNy:
        //    break;
        //case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
        //    break;
        //case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
        //    break;
        //default:
        //    break;
        //}
        //set the position
        vertex++;
        this->vertexBuffer.set(vertex,y);

        //update the VBO
        this->updateVBOFunctions();

        return true;
    }
    return false;
}
bool edk::shape::Polygon2D::setVBOVertexNormal(edk::uint32 vertex,edk::vec3f32 normal){
    //set the vertex position in vertexBuffer
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        //test if need change the buffer
        switch(this->vboType){
        case edk::GU::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        default:
            break;
        }

        //set the position
        this->vertexBuffer.set(vertex,normal.x);
        vertex++;
        this->vertexBuffer.set(vertex,normal.y);
        vertex++;
        this->vertexBuffer.set(vertex,normal.z);

        //update the VBO
        this->updateVBOFunctions();

        return true;
    }
    return false;
}
bool edk::shape::Polygon2D::setVBOVertexNormalX(edk::uint32 vertex,edk::float32 x){
    //set the vertex position in vertexBuffer
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        //test if need change the buffer
        switch(this->vboType){
        case edk::GU::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        default:
            break;
        }

        //set the position
        this->vertexBuffer.set(vertex,x);

        //update the VBO
        this->updateVBOFunctions();

        return true;
    }
    return false;
}
bool edk::shape::Polygon2D::setVBOVertexNormalY(edk::uint32 vertex,edk::float32 y){
    //set the vertex position in vertexBuffer
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        //test if need change the buffer
        switch(this->vboType){
        case edk::GU::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        default:
            break;
        }

        //set the position
        vertex++;
        this->vertexBuffer.set(vertex,y);

        //update the VBO
        this->updateVBOFunctions();

        return true;
    }
    return false;
}
bool edk::shape::Polygon2D::setVBOVertexNormalZ(edk::uint32 vertex,edk::float32 z){
    //set the vertex position in vertexBuffer
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        //test if need change the buffer
        switch(this->vboType){
        case edk::GU::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 7u;
            break;
        default:
            break;
        }

        //set the position
        vertex++;
        vertex++;
        this->vertexBuffer.set(vertex,z);

        //update the VBO
        this->updateVBOFunctions();

        return true;
    }
    return false;
}
bool edk::shape::Polygon2D::setVBOVertexColor(edk::uint32 vertex,edk::color4f32 color){
    //set the vertex position in vertexBuffer
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        //test if need change the buffer
        switch(this->vboType){
        case edk::GU::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 3u;
            break;
        case edk::GU::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 3u;
            break;
        case edk::GU::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 3u;
            break;
        case edk::GU::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 3u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 3u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 3u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 3u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 3u;
            break;
        case edk::GU::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 3u;
            break;
        case edk::GU::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 3u;
            break;
        case edk::GU::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 3u;
            break;
        case edk::GU::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 3u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 3u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 3u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 3u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 3u;
            break;
        default:
            break;
        }

        //set the position
        this->vertexBuffer.set(vertex,color.r);
        vertex++;
        this->vertexBuffer.set(vertex,color.g);
        vertex++;
        this->vertexBuffer.set(vertex,color.b);
        vertex++;
        this->vertexBuffer.set(vertex,color.a);

        //update the VBO
        this->updateVBOFunctions();

        return true;
    }
    return false;
}
bool edk::shape::Polygon2D::setVBOPolygonColor(edk::color4f32 color){
    //update the VBO
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        //test if need change the buffer
        edk::uint8 position;
        //test if need change the buffer
        switch(this->vboType){
        case edk::GU::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            position = 3u;
            break;
        default:
            break;
        }
        edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->vboCount;i++){
            //set the color
            this->vertexBuffer.setNoIF(position,color.r);
            this->vertexBuffer.setNoIF(position+1u,color.g);
            this->vertexBuffer.setNoIF(position+2u,color.b);
            this->vertexBuffer.setNoIF(position+3u,color.a);
            position+=increment;
        }

        //update the VBO
        this->updateVBOFunctions();

        return true;
    }
    return false;
}
bool edk::shape::Polygon2D::setVBOPolygonNormal(edk::vec3f32 normal){
    //update the VBO
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        //test if need change the buffer
        edk::uint8 position;
        //test if need change the buffer
        switch(this->vboType){
        case edk::GU::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::GU::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::GU::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::GU::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::GU::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::GU::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::GU::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::GU::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            position = 7u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            position = 7u;
            break;
        default:
            break;
        }
        edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->vboCount;i++){
            //set the color
            this->vertexBuffer.setNoIF(position,normal.x);
            this->vertexBuffer.setNoIF(position+1u,normal.y);
            this->vertexBuffer.setNoIF(position+2u,normal.z);
            position+=increment;
        }

        //update the VBO
        this->updateVBOFunctions();

        return true;
    }
    return false;
}
bool edk::shape::Polygon2D::setVBOPolygonColorR(edk::float32 r){
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        //test if need change the buffer
        edk::uint8 position;
        //test if need change the buffer
        switch(this->vboType){
        case edk::GU::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            position = 3u;
            break;
        default:
            break;
        }
        edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->vboCount;i++){
            //set the color
            this->vertexBuffer.setNoIF(position,r);
            position+=increment;
        }

        //update the VBO
        this->updateVBOFunctions();

        return true;
    }
    return false;
}
bool edk::shape::Polygon2D::setVBOPolygonColorG(edk::float32 g){
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        //test if need change the buffer
        edk::uint8 position;
        //test if need change the buffer
        switch(this->vboType){
        case edk::GU::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            position = 3u;
            break;
        default:
            break;
        }
        edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
        position++;
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->vboCount;i++){
            //set the color
            this->vertexBuffer.setNoIF(position,g);
            position+=increment;
        }

        //update the VBO
        this->updateVBOFunctions();

        return true;
    }
    return false;
}
bool edk::shape::Polygon2D::setVBOPolygonColorB(edk::float32 b){
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        //test if need change the buffer
        edk::uint8 position;
        //test if need change the buffer
        switch(this->vboType){
        case edk::GU::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            position = 3u;
            break;
        default:
            break;
        }
        edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
        position+=2u;
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->vboCount;i++){
            //set the color
            this->vertexBuffer.setNoIF(position,b);
            position+=increment;
        }

        //update the VBO
        this->updateVBOFunctions();

        return true;
    }
    return false;
}
bool edk::shape::Polygon2D::setVBOPolygonColorA(edk::float32 a){
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        //test if need change the buffer
        edk::uint8 position;
        //test if need change the buffer
        switch(this->vboType){
        case edk::GU::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            position = 3u;
            break;
        default:
            break;
        }
        edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
        position+=3u;
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->vboCount;i++){
            //set the color
            this->vertexBuffer.setNoIF(position,a);
            position+=increment;
        }

        //update the VBO
        this->updateVBOFunctions();

        return true;
    }
    return false;
}
bool edk::shape::Polygon2D::setVBOVertexUV(edk::uint32 vertex,edk::vec2f32 uv){
    //set the vertex position in vertexBuffer
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        //test if need change the buffer
        switch(this->vboType){
        case edk::GU::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        default:
            break;
        }

        //set the position
        this->vertexBuffer.set(vertex,uv.x);
        vertex++;
        this->vertexBuffer.set(vertex,uv.y);

        //update the VBO
        this->updateVBOFunctions();

        return true;
    }
    return false;
}
bool edk::shape::Polygon2D::setVBOVertexU(edk::uint32 vertex,edk::float32 u){
    //set the vertex position in vertexBuffer
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        //test if need change the buffer
        switch(this->vboType){
        case edk::GU::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        default:
            break;
        }

        //set the position
        this->vertexBuffer.set(vertex,u);
        //update the VBO
        this->updateVBOFunctions();

        return true;
    }
    return false;
}
bool edk::shape::Polygon2D::setVBOVertexV(edk::uint32 vertex,edk::float32 v){
    //set the vertex position in vertexBuffer
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        //test if need change the buffer
        switch(this->vboType){
        case edk::GU::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 9u;
            break;
        case edk::GU::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeofPolygon2D[this->vboType]) + 10u;
            break;
        default:
            break;
        }

        //set the position
        vertex++;
        this->vertexBuffer.set(vertex,v);

        //update the VBO
        this->updateVBOFunctions();

        return true;
    }
    return false;
}
//updafe the UV into the VBO
bool edk::shape::Polygon2D::updateVBOUV(){
    bool ret=false;
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        edk::uint32 size = this->vertexs.size();
        edk::shape::Vertex2DWithUV* vTemp;
        edk::uint32 vertexUV;
        edk::vec2f32 uv;
        for(edk::uint32 i=0u;i<size;i++){
            vertexUV = i;


            //set the vertex position in vertexBuffer
            //test if need change the buffer
            switch(this->vboType){
            case edk::GU::vbo_XY:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 9u;
                break;
            case edk::GU::vbo_XY_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 9u;
                break;
            case edk::GU::vbo_XY_RGB:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 9u;
                break;
            case edk::GU::vbo_XY_RGBA:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 9u;
                break;
            case edk::GU::vbo_XY_RGB_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 9u;
                break;
            case edk::GU::vbo_XY_RGBA_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 9u;
                break;
            case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 9u;
                break;
            case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 9u;
                break;
            case edk::GU::vbo_XYZ:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 10u;
                break;
            case edk::GU::vbo_XYZ_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 10u;
                break;
            case edk::GU::vbo_XYZ_RGB:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 10u;
                break;
            case edk::GU::vbo_XYZ_RGBA:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 10u;
                break;
            case edk::GU::vbo_XYZ_RGB_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 10u;
                break;
            case edk::GU::vbo_XYZ_RGBA_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 10u;
                break;
            case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 10u;
                break;
            case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 10u;
                break;
            default:
                break;
            }

            vTemp = (edk::shape::Vertex2DWithUV*)this->vertexs.getNoIF(i);
            if(vTemp->getType() != EDK_SHAPE_NOUV){
                uv = vTemp->getUV();
            }
            else{
                uv = edk::vec2f32(0.f,0.f);
            }

            //set the position
            this->vertexBuffer.set(vertexUV,uv.x);
            vertexUV++;
            this->vertexBuffer.set(vertexUV,uv.y);

            ret=true;
        }
    }
    if(ret){
        //update the VBO
        this->updateVBOFunctions();
    }
    return ret;
}
bool edk::shape::Polygon2D::updateVBOValues(){
    bool ret=false;
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        edk::uint32 size = this->vertexs.size();
        edk::shape::Vertex2DWithUV* vTemp;
        edk::uint32 vertexUV;
        edk::uint32 vertexPosition;
        edk::uint32 vertexColor;
        edk::vec2f32 uv;
        edk::vec2f32 position;
        edk::color4f32 color;
        for(edk::uint32 i=0u;i<size;i++){
            vertexPosition = vertexColor = vertexUV = i;

            switch(this->vboType){
            case edk::GU::vbo_XY:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeofPolygon2D[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeofPolygon2D[this->vboType]) + 2u;
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 9u;
                break;
            case edk::GU::vbo_XY_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeofPolygon2D[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeofPolygon2D[this->vboType]) + 2u;
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 9u;
                break;
            case edk::GU::vbo_XY_RGB:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeofPolygon2D[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeofPolygon2D[this->vboType]) + 2u;
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 9u;
                break;
            case edk::GU::vbo_XY_RGBA:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeofPolygon2D[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeofPolygon2D[this->vboType]) + 2u;
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 9u;
                break;
            case edk::GU::vbo_XY_RGB_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeofPolygon2D[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeofPolygon2D[this->vboType]) + 2u;
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 9u;
                break;
            case edk::GU::vbo_XY_RGBA_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeofPolygon2D[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeofPolygon2D[this->vboType]) + 2u;
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 9u;
                break;
            case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeofPolygon2D[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeofPolygon2D[this->vboType]) + 2u;
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 9u;
                break;
            case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeofPolygon2D[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeofPolygon2D[this->vboType]) + 2u;
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 9u;
                break;
            case edk::GU::vbo_XYZ:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeofPolygon2D[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeofPolygon2D[this->vboType]) + 3u;
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 10u;
                break;
            case edk::GU::vbo_XYZ_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeofPolygon2D[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeofPolygon2D[this->vboType]) + 3u;
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 10u;
                break;
            case edk::GU::vbo_XYZ_RGB:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeofPolygon2D[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeofPolygon2D[this->vboType]) + 3u;
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 10u;
                break;
            case edk::GU::vbo_XYZ_RGBA:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeofPolygon2D[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeofPolygon2D[this->vboType]) + 3u;
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 10u;
                break;
            case edk::GU::vbo_XYZ_RGB_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeofPolygon2D[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeofPolygon2D[this->vboType]) + 3u;
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 10u;
                break;
            case edk::GU::vbo_XYZ_RGBA_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeofPolygon2D[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeofPolygon2D[this->vboType]) + 3u;
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 10u;
                break;
            case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                //change the vertexBuffer
                this->changeVBO(edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeofPolygon2D[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeofPolygon2D[this->vboType]) + 3u;
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 10u;
                break;
            case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeofPolygon2D[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeofPolygon2D[this->vboType]) + 3u;
                vertexUV = (vertexUV * vboSizeofPolygon2D[this->vboType]) + 10u;
                break;
            default:
                break;
            }
            vTemp = (edk::shape::Vertex2DWithUV*)this->vertexs.getNoIF(i);
            if(vTemp->getType() != EDK_SHAPE_NOUV){
                uv = vTemp->getUV();
                position = vTemp->position;
                color = vTemp->color;
            }
            else{
                position = vTemp->position;
                color = vTemp->color;
                uv = edk::vec2f32(0.f,0.f);
            }
            //set the position
            this->vertexBuffer.set(vertexPosition,position.x);
            vertexPosition++;
            this->vertexBuffer.set(vertexPosition,position.y);
            //set the Color
            this->vertexBuffer.set(vertexColor,color.r);
            vertexColor++;
            this->vertexBuffer.set(vertexColor,color.g);
            vertexColor++;
            this->vertexBuffer.set(vertexColor,color.b);
            vertexColor++;
            this->vertexBuffer.set(vertexColor,color.a);
            //set the UV
            this->vertexBuffer.set(vertexUV,uv.x);
            vertexUV++;
            this->vertexBuffer.set(vertexUV,uv.y);

            ret = true;
        }
    }
    if(ret){
        //update the VBO
        this->updateVBOFunctions();
    }
    return ret;
}
//print the VBO
bool edk::shape::Polygon2D::printVBO(){
    if(this->haveVBO() && this->vertexBuffer.haveArray()){
        edk::uint32 position=0u;
        edk::uint32 increment=vboSizeofPolygon2D[this->vboType];
        //test if need change the buffer
        switch(this->vboType){
        case edk::GU::vbo_XY:
            printf("\nvbo_XY");
            break;
        case edk::GU::vbo_XY_NxNyNz:
            printf("\nvbo_XY_NxNyNz");
            break;
        case edk::GU::vbo_XY_RGB:
            printf("\nvbo_XY_RGB");
            break;
        case edk::GU::vbo_XY_RGBA:
            printf("\nvbo_XY_RGBA");
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz:
            printf("\nvbo_XY_RGB_NxNyNz");
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz:
            printf("\nvbo_XY_RGBA_NxNyNz");
            break;
        case edk::GU::vbo_XY_RGB_NxNyNz_UVxUVy:
            printf("\nvbo_XY_RGB_NxNyNz_UVxUVy");
            break;
        case edk::GU::vbo_XY_RGBA_NxNyNz_UVxUVy:
            printf("\nvbo_XY_RGBA_NxNyNz_UVxUVy");
            break;
        case edk::GU::vbo_XYZ:
            printf("\nvbo_XYZ");
            break;
        case edk::GU::vbo_XYZ_NxNyNz:
            printf("\nvbo_XYZ_NxNyNz");
            break;
        case edk::GU::vbo_XYZ_RGB:
            printf("\nvbo_XYZ_RGB");
            break;
        case edk::GU::vbo_XYZ_RGBA:
            printf("\nvbo_XYZ_RGBA");
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz:
            printf("\nvbo_XYZ_RGB_NxNyNz");
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz:
            printf("\nvbo_XYZ_RGBA_NxNyNz");
            break;
        case edk::GU::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            printf("\nvbo_XYZ_RGB_NxNyNz_UVxUVy");
            break;
        case edk::GU::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            printf("\nvbo_XYZ_RGBA_NxNyNz_UVxUVy");
            break;
        default:
            break;
        }
        for(edk::uint32 i=0u;i<this->vboCount;i++){
            printf("\n");
            for(edk::uint32 j=0u;j<increment;j++){
                printf("[%.2f]",this->vertexBuffer.get(position));
                position++;
            }
        }fflush(stdout);
        return true;
    }
    return false;
}

//Draw the polygon
void edk::shape::Polygon2D::drawVertexs(){
    //
    for(edk::uint32 i=0u;i<this->getVertexCount();i++){
        //
        if(vertexs.getNoIF(i)){
            vertexs.getNoIF(i)->draw();
        }
    }
}
void edk::shape::Polygon2D::drawVertexsWithColor(edk::color4f32 color){
    //
    for(edk::uint32 i=0u;i<this->getVertexCount();i++){
        //
        if(vertexs.getNoIF(i)){
            vertexs.getNoIF(i)->drawWithColor(color);
        }
    }
}
//update framesSize
void edk::shape::Polygon2D::updateFramesSize(){
    //
    this->framesSize = this->frames.x * this->frames.y;
}
//test if is tranforming the polygon
void edk::shape::Polygon2D::testTransform(){
    if(this->translate.x!=0.f
            ||
            this->translate.y!=0.f
            ||
            this->angle
            ||
            this->scale.width!=1.f
            ||
            this->scale.height!=1.f
            ){
        //
        this->transforming=true;
    }
    else{
        this->transforming=false;
    }
}

//draw functions
//PRINT
void edk::shape::Polygon2D::print_NULL(){
    //
    for(edk::uint32 i=0u;i<this->getVertexCount();i++){
        //
        if(vertexs.getNoIF(i)){
            vertexs.getNoIF(i)->print(i);
        }
    }
}
void edk::shape::Polygon2D::print_XY(){
    edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)
               );
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XYZ(){
    edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)
               ,this->vertexBuffer.getNoIF(position+2u)
               );
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XY_NxNyNz(){
    edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f) normal(%.2f %.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)

               ,this->vertexBuffer.getNoIF(position+2u)
               ,this->vertexBuffer.getNoIF(position+3u)
               ,this->vertexBuffer.getNoIF(position+4u)
               );
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XYZ_NxNyNz(){
    edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f %.2f) normal(%.2f %.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)
               ,this->vertexBuffer.getNoIF(position+2u)

               ,this->vertexBuffer.getNoIF(position+3u)
               ,this->vertexBuffer.getNoIF(position+4u)
               ,this->vertexBuffer.getNoIF(position+5u)
               );
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XY_RGB(){
    edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f) Color (%.2f %.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)

               ,this->vertexBuffer.getNoIF(position+2u)
               ,this->vertexBuffer.getNoIF(position+3u)
               ,this->vertexBuffer.getNoIF(position+4u)
               );
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XYZ_RGB(){
    edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f %.2f) Color (%.2f %.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)
               ,this->vertexBuffer.getNoIF(position+2u)

               ,this->vertexBuffer.getNoIF(position+3u)
               ,this->vertexBuffer.getNoIF(position+4u)
               ,this->vertexBuffer.getNoIF(position+5u)
               );
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XY_RGBA(){
    edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f) Color (%.2f %.2f %.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)

               ,this->vertexBuffer.getNoIF(position+2u)
               ,this->vertexBuffer.getNoIF(position+3u)
               ,this->vertexBuffer.getNoIF(position+4u)
               ,this->vertexBuffer.getNoIF(position+5u)
               );
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XYZ_RGBA(){
    edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f %.2f) Color (%.2f %.2f %.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)
               ,this->vertexBuffer.getNoIF(position+2u)

               ,this->vertexBuffer.getNoIF(position+3u)
               ,this->vertexBuffer.getNoIF(position+4u)
               ,this->vertexBuffer.getNoIF(position+5u)
               ,this->vertexBuffer.getNoIF(position+6u)
               );
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XY_RGB_NxNyNz(){
    edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f) Color (%.2f %.2f %.2f) normal(%.2f %.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)

               ,this->vertexBuffer.getNoIF(position+2u)
               ,this->vertexBuffer.getNoIF(position+3u)
               ,this->vertexBuffer.getNoIF(position+4u)

               ,this->vertexBuffer.getNoIF(position+5u)
               ,this->vertexBuffer.getNoIF(position+6u)
               ,this->vertexBuffer.getNoIF(position+7u)
               );
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XYZ_RGB_NxNyNz(){
    edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f %.2f) Color (%.2f %.2f %.2f) normal(%.2f %.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)
               ,this->vertexBuffer.getNoIF(position+2u)

               ,this->vertexBuffer.getNoIF(position+3u)
               ,this->vertexBuffer.getNoIF(position+4u)
               ,this->vertexBuffer.getNoIF(position+5u)

               ,this->vertexBuffer.getNoIF(position+6u)
               ,this->vertexBuffer.getNoIF(position+7u)
               ,this->vertexBuffer.getNoIF(position+8u)
               );
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XY_RGBA_NxNyNz(){
    edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f) Color (%.2f %.2f %.2f %.2f) normal(%.2f %.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)

               ,this->vertexBuffer.getNoIF(position+2u)
               ,this->vertexBuffer.getNoIF(position+3u)
               ,this->vertexBuffer.getNoIF(position+4u)
               ,this->vertexBuffer.getNoIF(position+5u)

               ,this->vertexBuffer.getNoIF(position+6u)
               ,this->vertexBuffer.getNoIF(position+7u)
               ,this->vertexBuffer.getNoIF(position+8u)
               );
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XYZ_RGBA_NxNyNz(){
    edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f %.2f) Color (%.2f %.2f %.2f %.2f) normal(%.2f %.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)
               ,this->vertexBuffer.getNoIF(position+2u)

               ,this->vertexBuffer.getNoIF(position+3u)
               ,this->vertexBuffer.getNoIF(position+4u)
               ,this->vertexBuffer.getNoIF(position+5u)
               ,this->vertexBuffer.getNoIF(position+6u)

               ,this->vertexBuffer.getNoIF(position+7u)
               ,this->vertexBuffer.getNoIF(position+8u)
               ,this->vertexBuffer.getNoIF(position+9u)
               );
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XY_RGB_NxNyNz_UVxUVy(){
    edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f) Color(%.2f %.2f %.2f) normal(%.2f %.2f %.2f) UV(%.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)

               ,this->vertexBuffer.getNoIF(position+2u)
               ,this->vertexBuffer.getNoIF(position+3u)
               ,this->vertexBuffer.getNoIF(position+4u)

               ,this->vertexBuffer.getNoIF(position+5u)
               ,this->vertexBuffer.getNoIF(position+6u)
               ,this->vertexBuffer.getNoIF(position+7u)

               ,this->vertexBuffer.getNoIF(position+8u)
               ,this->vertexBuffer.getNoIF(position+9u)
               );
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XYZ_RGB_NxNyNz_UVxUVy(){
    edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f %.2f) Color(%.2f %.2f %.2f) normal(%.2f %.2f %.2f) UV(%.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)
               ,this->vertexBuffer.getNoIF(position+2u)

               ,this->vertexBuffer.getNoIF(position+3u)
               ,this->vertexBuffer.getNoIF(position+4u)
               ,this->vertexBuffer.getNoIF(position+5u)

               ,this->vertexBuffer.getNoIF(position+6u)
               ,this->vertexBuffer.getNoIF(position+7u)
               ,this->vertexBuffer.getNoIF(position+8u)

               ,this->vertexBuffer.getNoIF(position+9u)
               ,this->vertexBuffer.getNoIF(position+10u)
               );
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XY_RGBA_NxNyNz_UVxUVy(){
    edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f) Color(%.2f %.2f %.2f %.2f) normal(%.2f %.2f %.2f) UV(%.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)

               ,this->vertexBuffer.getNoIF(position+2u)
               ,this->vertexBuffer.getNoIF(position+3u)
               ,this->vertexBuffer.getNoIF(position+4u)
               ,this->vertexBuffer.getNoIF(position+5u)

               ,this->vertexBuffer.getNoIF(position+6u)
               ,this->vertexBuffer.getNoIF(position+7u)
               ,this->vertexBuffer.getNoIF(position+8u)

               ,this->vertexBuffer.getNoIF(position+9u)
               ,this->vertexBuffer.getNoIF(position+10u)
               );
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XYZ_RGBA_NxNyNz_UVxUVy(){
    edk::uint8 increment = vboSizeofPolygon2D[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f %.2f) Color(%.2f %.2f %.2f %.2f) normal(%.2f %.2f %.2f) UV(%.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)
               ,this->vertexBuffer.getNoIF(position+2u)

               ,this->vertexBuffer.getNoIF(position+3u)
               ,this->vertexBuffer.getNoIF(position+4u)
               ,this->vertexBuffer.getNoIF(position+5u)
               ,this->vertexBuffer.getNoIF(position+6u)

               ,this->vertexBuffer.getNoIF(position+7u)
               ,this->vertexBuffer.getNoIF(position+8u)
               ,this->vertexBuffer.getNoIF(position+9u)

               ,this->vertexBuffer.getNoIF(position+10u)
               ,this->vertexBuffer.getNoIF(position+11u)
               );
        position+=increment;
    }fflush(stdout);
}
//DRAW
void edk::shape::Polygon2D::draw_NULL(edk::uint32 mode){
    /*
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable texture coord in array
    edk::GU_GLSL::guEnableClientState(GU_TEXTURE_COORD_ARRAY);
    //set the texture coor position in array
    edk::GU_GLSL::guTexCoordPointer2f32(0u);
    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(0u);
    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer3f32(0);
    edk::GU_GLSL::guColorPointer4f32(0);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer2f32(0u);
    edk::GU_GLSL::guVertexPointer3f32(0u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);
    //enable texture coord in array
    edk::GU_GLSL::guDisableClientState(GU_TEXTURE_COORD_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
*/
    edk::GU::guBegin(mode);
    this->drawVertexs();
    edk::GU::guEnd();
}
void edk::shape::Polygon2D::draw_XY(edk::uint32 mode){
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);
    //draw only the positions
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer2f32(0u,2u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
}
void edk::shape::Polygon2D::draw_XYZ(edk::uint32 mode){
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer3f32(0u,3u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
}
void edk::shape::Polygon2D::draw_XY_NxNyNz(edk::uint32 mode){
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(2u,5u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer2f32(0u,5u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
}
void edk::shape::Polygon2D::draw_XYZ_NxNyNz(edk::uint32 mode){
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(3u,6u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer3f32(0u,6u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
}
void edk::shape::Polygon2D::draw_XY_RGB(edk::uint32 mode){
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer3f32(2u,5u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer2f32(0u,5u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
}
void edk::shape::Polygon2D::draw_XYZ_RGB(edk::uint32 mode){
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer3f32(3,6u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer3f32(0u,6u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
}
void edk::shape::Polygon2D::draw_XY_RGBA(edk::uint32 mode){
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer4f32(2u,6u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer2f32(0u,6u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
}
void edk::shape::Polygon2D::draw_XYZ_RGBA(edk::uint32 mode){
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer4f32(3u,7u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer3f32(0u,7u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
}
void edk::shape::Polygon2D::draw_XY_RGB_NxNyNz(edk::uint32 mode){
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(5u,8u);
    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer3f32(2u,8u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer2f32(0u,8u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
}
void edk::shape::Polygon2D::draw_XYZ_RGB_NxNyNz(edk::uint32 mode){
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(6u,9u);
    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer3f32(3u,9u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer3f32(0u,9u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
}
void edk::shape::Polygon2D::draw_XY_RGBA_NxNyNz(edk::uint32 mode){
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(6u,9u);
    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer4f32(2u,9u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer2f32(0u,9u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
}
void edk::shape::Polygon2D::draw_XYZ_RGBA_NxNyNz(edk::uint32 mode){
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(7u,10u);
    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer4f32(3u,10u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer3f32(0u,10u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
}
void edk::shape::Polygon2D::draw_XY_RGB_NxNyNz_UVxUVy(edk::uint32 mode){
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable texture coord in array
    edk::GU_GLSL::guEnableClientState(GU_TEXTURE_COORD_ARRAY);
    //set the texture coor position in array
    edk::GU_GLSL::guTexCoordPointer2f32(8u,10u);
    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(5u,10u);
    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer3f32(2u,10u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer2f32(0u,10u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);
    //enable texture coord in array
    edk::GU_GLSL::guDisableClientState(GU_TEXTURE_COORD_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
}
void edk::shape::Polygon2D::draw_XYZ_RGB_NxNyNz_UVxUVy(edk::uint32 mode){
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable texture coord in array
    edk::GU_GLSL::guEnableClientState(GU_TEXTURE_COORD_ARRAY);
    //set the texture coor position in array
    edk::GU_GLSL::guTexCoordPointer2f32(9u,11u);
    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(6u,11u);
    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer3f32(3u,11u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer3f32(0u,11u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);
    //enable texture coord in array
    edk::GU_GLSL::guDisableClientState(GU_TEXTURE_COORD_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
}
void edk::shape::Polygon2D::draw_XY_RGBA_NxNyNz_UVxUVy(edk::uint32 mode){
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable texture coord in array
    edk::GU_GLSL::guEnableClientState(GU_TEXTURE_COORD_ARRAY);
    //set the texture coor position in array
    edk::GU_GLSL::guTexCoordPointer2f32(9u,11u);
    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(6u,11u);
    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer4f32(2u,11u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer2f32(0u,11u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);
    //enable texture coord in array
    edk::GU_GLSL::guDisableClientState(GU_TEXTURE_COORD_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
}
void edk::shape::Polygon2D::draw_XYZ_RGBA_NxNyNz_UVxUVy(edk::uint32 mode){
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable texture coord in array
    edk::GU_GLSL::guEnableClientState(GU_TEXTURE_COORD_ARRAY);
    //set the texture coor position in array
    edk::GU_GLSL::guTexCoordPointer2f32(10u,12u);
    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(7u,12u);
    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer4f32(3u,12u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer3f32(0u,12u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);
    //enable texture coord in array
    edk::GU_GLSL::guDisableClientState(GU_TEXTURE_COORD_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
}
//DRAW UPDATE
void edk::shape::Polygon2D::drawUpdate_NULL(edk::uint32 mode){
    //this->updateVBO();
    /*
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable texture coord in array
    edk::GU_GLSL::guEnableClientState(GU_TEXTURE_COORD_ARRAY);
    //set the texture coor position in array
    edk::GU_GLSL::guTexCoordPointer2f32(0u);
    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(0u);
    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer3f32(0);
    edk::GU_GLSL::guColorPointer4f32(0);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer2f32(0u);
    edk::GU_GLSL::guVertexPointer3f32(0u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);
    //enable texture coord in array
    edk::GU_GLSL::guDisableClientState(GU_TEXTURE_COORD_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
*/
    edk::GU::guBegin(mode);
    this->drawVertexs();
    edk::GU::guEnd();
    //change the drawFunction
    this->setVBOFunctionNULL();
}
void edk::shape::Polygon2D::drawUpdate_XY(edk::uint32 mode){
    this->updateVBO();
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);
    //draw only the positions
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer2f32(0u,2u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
    //change the drawFunction
    this->vboDraw = &edk::shape::Polygon2D::draw_XY;
}
void edk::shape::Polygon2D::drawUpdate_XYZ(edk::uint32 mode){
    this->updateVBO();
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer3f32(0u,3u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
    //change the drawFunction
    this->vboDraw = &edk::shape::Polygon2D::draw_XYZ;
}
void edk::shape::Polygon2D::drawUpdate_XY_NxNyNz(edk::uint32 mode){
    this->updateVBO();
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(2u,5u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer2f32(0u,5u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
    //change the drawFunction
    this->vboDraw = &edk::shape::Polygon2D::draw_XY_NxNyNz;
}
void edk::shape::Polygon2D::drawUpdate_XYZ_NxNyNz(edk::uint32 mode){
    this->updateVBO();
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(3u,6u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer3f32(0u,6u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
    //change the drawFunction
    this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_NxNyNz;
}
void edk::shape::Polygon2D::drawUpdate_XY_RGB(edk::uint32 mode){
    this->updateVBO();
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer3f32(2u,5u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer2f32(0u,5u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
    //change the drawFunction
    this->vboDraw = &edk::shape::Polygon2D::draw_XY_RGB;
}
void edk::shape::Polygon2D::drawUpdate_XYZ_RGB(edk::uint32 mode){
    this->updateVBO();
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer3f32(3,6u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer3f32(0u,6u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
    //change the drawFunction
    this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_RGB;
}
void edk::shape::Polygon2D::drawUpdate_XY_RGBA(edk::uint32 mode){
    this->updateVBO();
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer4f32(2u,6u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer2f32(0u,6u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
    //change the drawFunction
    this->vboDraw = &edk::shape::Polygon2D::draw_XY_RGBA;
}
void edk::shape::Polygon2D::drawUpdate_XYZ_RGBA(edk::uint32 mode){
    this->updateVBO();
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer4f32(3u,7u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer3f32(0u,7u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
    //change the drawFunction
    this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_RGBA;
}
void edk::shape::Polygon2D::drawUpdate_XY_RGB_NxNyNz(edk::uint32 mode){
    this->updateVBO();
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(5u,8u);
    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer3f32(2u,8u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer2f32(0u,8u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
    //change the drawFunction
    this->vboDraw = &edk::shape::Polygon2D::draw_XY_RGB_NxNyNz;
}
void edk::shape::Polygon2D::drawUpdate_XYZ_RGB_NxNyNz(edk::uint32 mode){
    this->updateVBO();
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(6u,9u);
    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer3f32(3u,9u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer3f32(0u,9u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
    //change the drawFunction
    this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_RGB_NxNyNz;
}
void edk::shape::Polygon2D::drawUpdate_XY_RGBA_NxNyNz(edk::uint32 mode){
    this->updateVBO();
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(6u,9u);
    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer4f32(2u,9u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer2f32(0u,9u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
    //change the drawFunction
    this->vboDraw = &edk::shape::Polygon2D::draw_XY_RGBA_NxNyNz;
}
void edk::shape::Polygon2D::drawUpdate_XYZ_RGBA_NxNyNz(edk::uint32 mode){
    this->updateVBO();
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(7u,10u);
    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer4f32(3u,10u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer3f32(0u,10u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
    //change the drawFunction
    this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_RGBA_NxNyNz;
}
void edk::shape::Polygon2D::drawUpdate_XY_RGB_NxNyNz_UVxUVy(edk::uint32 mode){
    this->updateVBO();
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable texture coord in array
    edk::GU_GLSL::guEnableClientState(GU_TEXTURE_COORD_ARRAY);
    //set the texture coor position in array
    edk::GU_GLSL::guTexCoordPointer2f32(8u,10u);
    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(5u,10u);
    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer3f32(2u,10u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer2f32(0u,10u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);
    //enable texture coord in array
    edk::GU_GLSL::guDisableClientState(GU_TEXTURE_COORD_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
    //change the drawFunction
    this->vboDraw = &edk::shape::Polygon2D::draw_XY_RGB_NxNyNz_UVxUVy;
}
void edk::shape::Polygon2D::drawUpdate_XYZ_RGB_NxNyNz_UVxUVy(edk::uint32 mode){
    this->updateVBO();
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable texture coord in array
    edk::GU_GLSL::guEnableClientState(GU_TEXTURE_COORD_ARRAY);
    //set the texture coor position in array
    edk::GU_GLSL::guTexCoordPointer2f32(9u,11u);
    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(6u,11u);
    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer3f32(3u,11u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer3f32(0u,11u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);
    //enable texture coord in array
    edk::GU_GLSL::guDisableClientState(GU_TEXTURE_COORD_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
    //change the drawFunction
    this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_RGB_NxNyNz_UVxUVy;
}
void edk::shape::Polygon2D::drawUpdate_XY_RGBA_NxNyNz_UVxUVy(edk::uint32 mode){
    this->updateVBO();
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable texture coord in array
    edk::GU_GLSL::guEnableClientState(GU_TEXTURE_COORD_ARRAY);
    //set the texture coor position in array
    edk::GU_GLSL::guTexCoordPointer2f32(9u,11u);
    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(6u,11u);
    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer4f32(2u,11u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer2f32(0u,11u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);
    //enable texture coord in array
    edk::GU_GLSL::guDisableClientState(GU_TEXTURE_COORD_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
    //change the drawFunction
    this->vboDraw = &edk::shape::Polygon2D::draw_XY_RGBA_NxNyNz_UVxUVy;
}
void edk::shape::Polygon2D::drawUpdate_XYZ_RGBA_NxNyNz_UVxUVy(edk::uint32 mode){
    this->updateVBO();
    edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);

    //enable texture coord in array
    edk::GU_GLSL::guEnableClientState(GU_TEXTURE_COORD_ARRAY);
    //set the texture coor position in array
    edk::GU_GLSL::guTexCoordPointer2f32(10u,12u);
    //enable normal in array
    edk::GU_GLSL::guEnableClientState(GU_NORMAL_ARRAY);
    //set the normal position in array
    edk::GU_GLSL::guNormalPointerF32(7u,12u);
    //enable color in array
    edk::GU_GLSL::guEnableClientState(GU_COLOR_ARRAY);
    //set the color position in array
    edk::GU_GLSL::guColorPointer4f32(3u,12u);
    //enable vertex in array
    edk::GU_GLSL::guEnableClientState(GU_VERTEX_ARRAY);
    //set the vertex position in array
    edk::GU_GLSL::guVertexPointer3f32(0u,12u);

    //draw the array
    edk::GU_GLSL::guDrawArrays(mode,0,this->vboCount);

    //enable vertex in array
    edk::GU_GLSL::guDisableClientState(GU_VERTEX_ARRAY);
    //enable color in array
    edk::GU_GLSL::guDisableClientState(GU_COLOR_ARRAY);
    //enable normal in array
    edk::GU_GLSL::guDisableClientState(GU_NORMAL_ARRAY);
    //enable texture coord in array
    edk::GU_GLSL::guDisableClientState(GU_TEXTURE_COORD_ARRAY);

    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);
    //change the drawFunction
    this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_RGBA_NxNyNz_UVxUVy;
}

//PUBLIC
//load the vertex
edk::shape::Vertex2D* edk::shape::Polygon2D::getVertexPointer(edk::uint32 vertex){
    //test if have the vertex
    if(vertex<this->getVertexCount()){
        //then return the vertex
        return this->vertexs.getNoIF(vertex);
    }
    //else return NULL
    return NULL;
}
edk::shape::Vertex2D* edk::shape::Polygon2D::getVertexOriginalPointer(edk::uint32 vertex){
    //test if have the vertex
    if(vertex<this->getVertexCount()){
        //then return the vertex
        return this->vertexsOriginal.getNoIF(vertex);
    }
    //else return NULL
    return NULL;
}

void edk::shape::Polygon2D::clean(){
    this->deletePolygon();
}

//create the polygon
bool edk::shape::Polygon2D::createPolygon(edk::uint32 vertexCount){
    //delete the polygon
    this->deletePolygon();
    bool ret = false;
    //test the vertexCount
    if(vertexCount >= minimumVertex){
        //create the array
        if(this->vertexsOriginal.createArray(vertexCount)){
            if(this->vertexs.createArray(vertexCount)){
                //create all the vertexs
                for(edk::uint32 i =0u;i<vertexCount;i++){
                    //
                    this->vertexs.set(i,new edk::shape::Vertex2D());
                    this->vertexsOriginal.set(i,new edk::shape::Vertex2D());
                    //Set alpha 1
                    if(this->vertexs.get(i)){
                        //set the vertex
                        this->vertexs.getNoIF(i)->color = this->polygonColor;
                    }
                    if(this->vertexsOriginal.get(i)){
                        //set the vertex
                        this->vertexsOriginal.getNoIF(i)->color = this->polygonColor;
                    }
                }
                //then return true
                ret = true;
            }
            else{
                this->vertexsOriginal.deleteArray();
            }
        }

        //create the VBO.
        if(ret){
            this->createVBO(vertexCount,edk::GU::vbo_XYZ_RGBA);
        }
    }
    return ret;
}

//test if the polygon is Counterclockwise
bool edk::shape::Polygon2D::isCounterclockwise(){
    //test the polygon size
    if(this->getVertexCount()>=3){
        //test the vertex angles
        edk::float32 angle1 = edk::Math::getAngle(this->vertexs.getNoIF(1u)->position - this->vertexs.getNoIF(0u)->position);
        edk::float32 angle2;
        edk::float32 angleTemp;
#if defined(edkCPPversion17)
        for(edk::uint32 i=2u;i<this->vertexs.size();i++){
#else
        for(register edk::uint32 i=2u;i<this->vertexs.size();i++){
#endif
            //get the next angle
            angle2 = edk::Math::getAngle(this->vertexs.getNoIF(i)->position - this->vertexs.getNoIF(0u)->position);
            angleTemp = angle2 - angle1;
            if(angleTemp>180.f || (angleTemp<0.f && angleTemp>-180.f)){
                //it's not counterClockwise
                return false;
            }
            angle1=angle2;
        }
        return true;
    }
    return false;
}

//invert the sense
bool edk::shape::Polygon2D::invertVertexSense(){
    edk::shape::Vertex2D* temp;
    if(this->getVertexCount()>=2u){
        edk::uint32 i=0u,j=this->getVertexCount()-1u,limit=this->getVertexCount()/2u;
        for(;i<limit;i++,j--){
            temp = this->vertexs.get(i);
            this->vertexs.set(i,this->vertexs.get(j));
            this->vertexs.set(j,temp);
        }
        return true;
    }
    return false;
}
bool edk::shape::Polygon2D::changeVertexSense(bool counterClockWise){
    if(counterClockWise != this->isCounterclockwise()){
        return this->invertVertexSense();
    }
    return false;
}
bool edk::shape::Polygon2D::setClockWise(){
    return this->changeVertexSense(false);
}
bool edk::shape::Polygon2D::setCounterClockWise(){
    return this->changeVertexSense(true);
}

//SETTERS
//set the position of a vertex
bool edk::shape::Polygon2D::setVertexPosition(edk::uint32 vertex,edk::vec2f32 position){
    bool ret=false;
    //load the polygon
    edk::shape::Vertex2D* vTemp = this->getVertexPointer(vertex);
    edk::shape::Vertex2D* voTemp = this->getVertexOriginalPointer(vertex);
    if(vTemp && voTemp){
        //then set the position of the vertex
        vTemp->position = position;
        voTemp->position = position;
        //return true
        ret=true;
    }

    //set the vertex position in vertexBuffer
    if(ret){
        this->setVBOVertexPosition(vertex,position);
    }
    //else return false
    return ret;
}
bool edk::shape::Polygon2D::setVertexPosition(edk::uint32 vertex,edk::float32 x,edk::float32 y){
    //
    return this->setVertexPosition(vertex,edk::vec2f32(x,y));
}
//set the color of a vertex
bool edk::shape::Polygon2D::setVertexColor(edk::uint32 vertex,edk::color4f32 color){
    bool ret=false;
    //load the polygon
    edk::shape::Vertex2D* vTemp = this->getVertexPointer(vertex);
    edk::shape::Vertex2D* voTemp = this->getVertexOriginalPointer(vertex);
    if(vTemp && voTemp){
        //then set the position of the vertex
        vTemp->color = color;
        voTemp->color = color;
        //return true
        ret=true;
    }

    //set the vertex position in vertexBuffer
    if(ret){
        this->setVBOVertexColor(vertex,color);
    }

    return ret;
}
bool edk::shape::Polygon2D::setVertexColor(edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b){
    //
    return this->setVertexColor(vertex,edk::color4f32(r,g,b,1.0f));
}
bool edk::shape::Polygon2D::setVertexColor(edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //
    return this->setVertexColor(vertex,edk::color4f32(r,g,b,a));
}
//Set polygon color
bool edk::shape::Polygon2D::setPolygonColor(edk::color4f32 color){
    bool ret = false;
    //first set the polygonColor
    this->polygonColor = edk::color4f32(color);
    if(this->getVertexCount()){
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->getVertexCount();i++){
            //set the color
            this->vertexs.getNoIF(i)->color = this->polygonColor;
            this->vertexsOriginal.getNoIF(i)->color = this->polygonColor;
        }
        //then return true
        ret = true;
    }

    //update the VBO
    if(ret){
        this->setVBOPolygonColor(color);
    }

    //else return false
    return ret;
}
bool edk::shape::Polygon2D::setPolygonColor(edk::color3f32 color){
    return this->setPolygonColor(edk::color4f32 (color.r,color.g,color.b,1.f));
}
bool edk::shape::Polygon2D::setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b){
    //
    return this->setPolygonColor(edk::color4f32 (r,g,b,1.f));
}
bool edk::shape::Polygon2D::setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //
    return this->setPolygonColor(edk::color4f32 (r,g,b,a));
}
bool edk::shape::Polygon2D::setPolygonColorR(edk::float32 r){
    bool ret=false;
    //first set the polygonColor
    this->polygonColor.r = r;
    if(this->getVertexCount()){
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->getVertexCount();i++){
            //set the color
            this->vertexs.getNoIF(i)->color.r = this->polygonColor.r;
            this->vertexsOriginal.getNoIF(i)->color.r = this->polygonColor.r;
        }
        //then return true
        ret=true;
    }

    if(ret){
        this->setVBOPolygonColorR(r);
    }
    //else return false
    return ret;
}
bool edk::shape::Polygon2D::setPolygonColorG(edk::float32 g){
    bool ret = false;
    //first set the polygonColor
    this->polygonColor.g = g;
    if(this->getVertexCount()){
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->getVertexCount();i++){
            //set the color
            this->vertexs.getNoIF(i)->color.g = this->polygonColor.g;
            this->vertexsOriginal.getNoIF(i)->color.g = this->polygonColor.g;
        }
        //then return true
        ret = true;
    }

    if(ret){
        this->setVBOPolygonColorG(g);
    }
    //else return false
    return ret;
}
bool edk::shape::Polygon2D::setPolygonColorB(edk::float32 b){
    bool ret = false;
    //first set the polygonColor
    this->polygonColor.b = b;
    if(this->getVertexCount()){
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->getVertexCount();i++){
            //set the color
            this->vertexs.getNoIF(i)->color.b = this->polygonColor.b;
            this->vertexsOriginal.getNoIF(i)->color.b = this->polygonColor.b;
        }
        //then return true
        ret = true;
    }


    if(ret){
        this->setVBOPolygonColorB(b);
    }
    //else return false
    return ret;
}
bool edk::shape::Polygon2D::setPolygonColorA(edk::float32 a){
    bool ret = false;
    //first set the polygonColor
    this->polygonColor.a = a;
    if(this->getVertexCount()){
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->getVertexCount();i++){
            //set the color
            this->vertexs.getNoIF(i)->color.a = this->polygonColor.a;
            this->vertexsOriginal.getNoIF(i)->color.a = this->polygonColor.a;
        }
        //then return true
        ret = true;
    }

    if(ret){
        this->setVBOPolygonColorA(a);
    }
    //else return false
    return ret;
}
//set the UVMap of the vertex
bool edk::shape::Polygon2D::setVertexUV(edk::uint32 vertex,edk::vec2f32 uv){
    bool ret = false;
    this->frameUsing=edk::vec2ui32(0u,0u);
    //load the polygon
    edk::shape::Vertex2DWithUV* vTemp = (edk::shape::Vertex2DWithUV*)this->getVertexPointer(vertex);
    edk::shape::Vertex2DWithUV* voTemp = (edk::shape::Vertex2DWithUV*)this->getVertexOriginalPointer(vertex);
    if(vTemp && voTemp){
        //test what type of vertex it is
        if(vTemp->getType() == EDK_SHAPE_NOUV
                || voTemp->getType() == EDK_SHAPE_NOUV
                ){
            //then delete the vTemp and create another with UV
            edk::shape::Vertex2DWithUV* uvTemp = new edk::shape::Vertex2DWithUV();
            edk::shape::Vertex2DWithUV* uvoTemp = new edk::shape::Vertex2DWithUV();
            if(uvTemp && uvoTemp){
                //copy the vTemp content to uvTemp
                uvTemp->position = vTemp->position;
                uvTemp->color = vTemp->color;
                uvoTemp->position = vTemp->position;
                uvoTemp->color = vTemp->color;

                //delete the vTemp
                delete vTemp;
                delete voTemp;
                //set vTemp the uvTemp
                vTemp=uvTemp;
                voTemp=uvoTemp;
                //set the vertex on the array
                this->vertexs.set(vertex,(edk::shape::Vertex2D*)vTemp);
                this->vertexsOriginal.set(vertex,(edk::shape::Vertex2D*)voTemp);
                //clean uvTemp
                uvTemp=NULL;
                uvoTemp=NULL;
                //set the uv
                vTemp->setUV(uv);
                voTemp->setUV(uv);
                ret = true;
            }
            else{
                //else return false
                ret = false;
            }
        }
        else if(vTemp->getType() == EDK_SHAPE_ANIMATED_UV
                && voTemp->getType() == EDK_SHAPE_ANIMATED_UV
                ){
            edk::shape::Vertex2DAnimatedUV* vTemp2 = (edk::shape::Vertex2DAnimatedUV*)vTemp;
            edk::shape::Vertex2DAnimatedUV* voTemp2 = (edk::shape::Vertex2DAnimatedUV*)voTemp;
            vTemp2->setUV(uv);
            voTemp2->setUV(uv);
            ret = true;
        }
        else{
            //set the uv
            vTemp->setUV(uv);
            voTemp->setUV(uv);
            //return true
            ret = true;
        }
    }

    //set the vertex position in vertexBuffer
    if(ret){
        this->setVBOVertexUV(vertex,uv);
    }

    //else return false
    return ret;
}
bool edk::shape::Polygon2D::setVertexUV(edk::uint32 vertex,edk::float32 x,edk::float32 y){
    //
    return this->setVertexUV(vertex,edk::vec2f32(x,y));
}
//Set the polygonFrames
bool edk::shape::Polygon2D::setPolygonUVFrames(edk::vec2ui32 frames){
    this->frameUsing=edk::vec2ui32(0u,0u);
    //test the frames
    if(frames.x && frames.y){
        //save the frames
        this->frames=frames;
        //set the frames on vertex
        for(edk::uint32 i=0u;i<this->vertexs.size();i++){
            //
            this->setVertexUVFrames(i,frames);
        }
        this->updateFramesSize();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2D::setPolygonUVFrames(edk::uint32 x,edk::uint32 y){
    //
    return this->setPolygonUVFrames(edk::vec2ui32(x,y));
}
bool edk::shape::Polygon2D::setPolygonUVFramesX(edk::uint32 x){
    //
    if(x){
        this->frames.x=x;
    }
    return this->setPolygonUVFrames(edk::vec2ui32(x,
                                                  this->frames.y
                                                  )
                                    );
}
bool edk::shape::Polygon2D::setPolygonUVFramesY(edk::uint32 y){
    //
    if(y){
        this->frames.y=y;
    }
    return this->setPolygonUVFrames(edk::vec2ui32(this->frames.x,
                                                  y
                                                  )
                                    );
}
//Set the polygon frame
void edk::shape::Polygon2D::usePolygonUVFrame(edk::vec2ui32 frame){
    bool ret=false;
    this->frameUsing=edk::vec2ui32(0u,0u);
    //set the frame in all vertexs
    for(edk::uint32 i=0u;i<this->vertexs.size();i++){
        //load the vertex
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs.get(i);
        edk::shape::Vertex2DAnimatedUV* tempO = (edk::shape::Vertex2DAnimatedUV*)this->vertexsOriginal.get(i);
        if(temp && tempO){
            //test if temp have frames
            if(temp->getType()==EDK_SHAPE_ANIMATED_UV
                    && tempO->getType()==EDK_SHAPE_ANIMATED_UV
                    ){
                //then set the frame
                temp->useUVFrame(frame);
                tempO->useUVFrame(frame);
                this->frameUsing=frame;
                ret=true;
            }
        }
    }
    if(ret){
        this->updateVBOUV();
    }
}
void edk::shape::Polygon2D::usePolygonUVFramePosition(edk::uint32 position){
    bool ret=false;
    //test if the framesX is not zero
    if(this->frames.x && this->frames.y){
        //make the UV positions
        edk::vec2ui32 UVPosition(position%this->frames.x,position/this->frames.x);
        //set the frame in AllVertexs
        for(edk::uint32 i=0u;i<this->vertexs.size();i++){
            //load the vertex
            edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs.get(i);
            edk::shape::Vertex2DAnimatedUV* tempO = (edk::shape::Vertex2DAnimatedUV*)this->vertexsOriginal.get(i);
            if(temp && tempO){
                //test if temp have frames
                if(temp->getType()==EDK_SHAPE_ANIMATED_UV
                        && tempO->getType()==EDK_SHAPE_ANIMATED_UV
                        ){
                    //then set the position
                    temp->useUVFrame(UVPosition);
                    tempO->useUVFrame(UVPosition);
                    this->frameUsing=UVPosition;
                    ret=true;
                }
            }
        }
    }
    if(ret){
        this->updateVBOUV();
    }
}
void edk::shape::Polygon2D::usePolygonUVFrameX(edk::uint32 x){
    bool ret=false;
    //set the frame in all vertexs
    for(edk::uint32 i=0u;i<this->vertexs.size();i++){
        //load the vertex
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs.get(i);
        edk::shape::Vertex2DAnimatedUV* tempO = (edk::shape::Vertex2DAnimatedUV*)this->vertexsOriginal.get(i);
        if(temp && tempO){
            //test if temp have frames
            if(temp->getType()==EDK_SHAPE_ANIMATED_UV
                    && tempO->getType()==EDK_SHAPE_ANIMATED_UV
                    ){
                //then set the frame
                temp->useUVFrameX(x);
                tempO->useUVFrameX(x);
                this->frameUsing.x = x;
                ret=true;
            }
        }
    }
    if(ret){
        this->updateVBOUV();
    }
}
void edk::shape::Polygon2D::usePolygonUVFrameY(edk::uint32 y){
    bool ret=false;
    //set the frame in all vertexs
    for(edk::uint32 i=0u;i<this->vertexs.size();i++){
        //load the vertex
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs.get(i);
        edk::shape::Vertex2DAnimatedUV* tempO = (edk::shape::Vertex2DAnimatedUV*)this->vertexsOriginal.get(i);
        if(temp && tempO){
            //test if temp have frames
            if(temp->getType()==EDK_SHAPE_ANIMATED_UV
                    && tempO->getType()==EDK_SHAPE_ANIMATED_UV
                    ){
                //then set the frame
                temp->useUVFrameY(y);
                tempO->useUVFrameY(y);
                this->frameUsing.x = y;
                ret=true;
            }
        }
    }
    if(ret){
        this->updateVBOUV();
    }
}

//clean the transformation
void edk::shape::Polygon2D::cleanTransform(){
    this->translate = edk::vec2f32(0,0);
    this->scale=edk::size2f32(1,1);
    this->angle = 0u;
    this->testTransform();
}
//Set the position of the polygon
void edk::shape::Polygon2D::setTranslate(edk::vec2f32 translate){
    this->translate = translate;
    this->testTransform();
}
void edk::shape::Polygon2D::setTranslate(edk::float32 translate){
    this->translate = translate;
    this->testTransform();
}
void edk::shape::Polygon2D::setTranslate(edk::float32 x,edk::float32 y){
    this->setTranslate(edk::vec2f32 (x,y));
}
//set the scale
void edk::shape::Polygon2D::setScale(edk::size2f32 scale){
    this->scale=scale;
    this->testTransform();
}
void edk::shape::Polygon2D::setScale(edk::float32 scale){
    this->scale=scale;
    this->testTransform();
}
void edk::shape::Polygon2D::setScale(edk::float32 width,edk::float32 height){
    this->setScale(edk::size2f32 (width,height));
}
//set the angle
void edk::shape::Polygon2D::setAngle(edk::float32 angle){
    this->angle=angle;
    this->testTransform();
}
//set physics
void edk::shape::Polygon2D::setDensity(edk::float32 density){
    this->density=density;
}
void edk::shape::Polygon2D::setFriction(edk::float32 friction){
    this->friction=friction;
}
void edk::shape::Polygon2D::setRestitution(edk::float32 restitution){
    this->restitution=restitution;
}

//function to calculate boundingBox
bool edk::shape::Polygon2D::calculateBoundingBox(edk::rectf32* rectangle,edk::vector::Matrixf32<3u,3u>* transformMat){
    if(transformMat && rectangle && this->getVertexCount()){
        //generate the boundingBox
        edk::rectf32 temp = this->generateBoundingBox(transformMat);

        if(rectangle->origin.x>temp.origin.x){
            rectangle->origin.x=temp.origin.x;
        }
        if(rectangle->origin.y>temp.origin.y){
            rectangle->origin.y=temp.origin.y;
        }
        if(rectangle->size.width<temp.size.width){
            rectangle->size.width=temp.size.width;
        }
        if(rectangle->size.height<temp.size.height){
            rectangle->size.height=temp.size.height;
        }

        return true;
    }
    return false;
}
edk::rectf32 edk::shape::Polygon2D::generateBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::rectf32 ret;
    edk::uint32 size = this->getVertexCount();
    if(size){
        //first copy the matrix
        if(this->matrixTransform.cloneFrom(transformMat)){
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->translate,&this->matrixTranslate);
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixRotate);
            edk::Math::generateScaleMatrix(this->scale,&this->matrixScale);

            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixTranslate);
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotate);
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixScale);

            //transform all the vertices
            if(this->matrixPosition.haveMatrix()){
                //transform the first vertex
                if(this->vertexs.get(0u)){
                    edk::vec2f32 vexPosition;
                    vexPosition=0.f;
                    //
                    this->matrixPosition.set(0u,0u,this->vertexs.getNoIF(0u)->position.x);
                    this->matrixPosition.set(0u,1u,this->vertexs.getNoIF(0u)->position.y);
                    this->matrixPosition.set(0u,2u,1.f);

                    //multiply the matrix
                    this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);

                    ret.origin.x = this->matrixPosition.getNoIF(0u,0u);
                    ret.origin.y = this->matrixPosition.getNoIF(0u,1u);
                    ret.size.width = ret.origin.x;
                    ret.size.height = ret.origin.y;
                    if(size==2u){
                        //process the rectangle or line
                        if(this->vertexs.get(1u)){
                            //V0x1
                            this->matrixPosition.set(0u,0u,this->vertexs.getNoIF(0u)->position.x);
                            this->matrixPosition.set(0u,1u,this->vertexs.getNoIF(1u)->position.y);
                            this->matrixPosition.set(0u,2u,1.f);

                            //multiply the matrix
                            this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);

                            vexPosition.x = this->matrixPosition.getNoIF(0u,0u);
                            vexPosition.y = this->matrixPosition.getNoIF(0u,1u);

                            if(ret.origin.x > vexPosition.x){
                                ret.origin.x = vexPosition.x;
                            }
                            if(ret.origin.y > vexPosition.y){
                                ret.origin.y = vexPosition.y;
                            }
                            if(ret.size.width < vexPosition.x){
                                ret.size.width = vexPosition.x;
                            }
                            if(ret.size.height < vexPosition.y){
                                ret.size.height = vexPosition.y;
                            }

                            //V1x0
                            this->matrixPosition.set(0u,0u,this->vertexs.getNoIF(1u)->position.x);
                            this->matrixPosition.set(0u,1u,this->vertexs.getNoIF(0u)->position.y);
                            this->matrixPosition.set(0u,2u,1.f);

                            //multiply the matrix
                            this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);

                            vexPosition.x = this->matrixPosition.getNoIF(0u,0u);
                            vexPosition.y = this->matrixPosition.getNoIF(0u,1u);

                            if(ret.origin.x > vexPosition.x){
                                ret.origin.x = vexPosition.x;
                            }
                            if(ret.origin.y > vexPosition.y){
                                ret.origin.y = vexPosition.y;
                            }
                            if(ret.size.width < vexPosition.x){
                                ret.size.width = vexPosition.x;
                            }
                            if(ret.size.height < vexPosition.y){
                                ret.size.height = vexPosition.y;
                            }

                            //V1x1
                            this->matrixPosition.set(0u,0u,this->vertexs.getNoIF(1u)->position.x);
                            this->matrixPosition.set(0u,1u,this->vertexs.getNoIF(1u)->position.y);
                            this->matrixPosition.set(0u,2u,1.f);

                            //multiply the matrix
                            this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);

                            vexPosition.x = this->matrixPosition.getNoIF(0u,0u);
                            vexPosition.y = this->matrixPosition.getNoIF(0u,1u);

                            if(ret.origin.x > vexPosition.x){
                                ret.origin.x = vexPosition.x;
                            }
                            if(ret.origin.y > vexPosition.y){
                                ret.origin.y = vexPosition.y;
                            }
                            if(ret.size.width < vexPosition.x){
                                ret.size.width = vexPosition.x;
                            }
                            if(ret.size.height < vexPosition.y){
                                ret.size.height = vexPosition.y;
                            }
                        }
                    }
                    else{
                        for(edk::uint32 i=0u;i<size;i++){
                            if(this->vertexs.get(i)){
                                this->matrixPosition.set(0u,0u,this->vertexs.getNoIF(i)->position.x);
                                this->matrixPosition.set(0u,1u,this->vertexs.getNoIF(i)->position.y);
                                this->matrixPosition.set(0u,2u,1.f);

                                //multiply the matrix
                                this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);

                                vexPosition.x = this->matrixPosition.getNoIF(0u,0u);
                                vexPosition.y = this->matrixPosition.getNoIF(0u,1u);

                                if(ret.origin.x > vexPosition.x){
                                    ret.origin.x = vexPosition.x;
                                }
                                if(ret.origin.y > vexPosition.y){
                                    ret.origin.y = vexPosition.y;
                                }
                                if(ret.size.width < vexPosition.x){
                                    ret.size.width = vexPosition.x;
                                }
                                if(ret.size.height < vexPosition.y){
                                    ret.size.height = vexPosition.y;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ret;
}
bool edk::shape::Polygon2D::calculateBoundingPoint(edk::vec2f32* point,edk::vector::Matrixf32<3u,3u>* transformMat){
    if(transformMat && point && this->getVertexCount()){
        //generate the boundingBox
        *point = this->generateBoundingPoint(transformMat);
        return true;
    }
    return false;
}
edk::vec2f32 edk::shape::Polygon2D::generateBoundingPoint(edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::vec2f32 ret;
    edk::uint32 size = this->getVertexCount();
    if(size){
        //first copy the matrix
        if(this->matrixTransform.cloneFrom(transformMat)){
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->translate,&this->matrixTranslate);
            edk::Math::generateRotateMatrixZ(this->angle,&this->matrixRotate);
            edk::Math::generateScaleMatrix(this->scale,&this->matrixScale);

            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixTranslate);
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotate);
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixScale);

            //transform all the vertices
            if(this->matrixPosition.haveMatrix()){
                //transform the point
                //
                this->matrixPosition.set(0u,0u,this->vertexs.getNoIF(0u)->position.x);
                this->matrixPosition.set(0u,1u,this->vertexs.getNoIF(0u)->position.y);
                this->matrixPosition.set(0u,2u,1.f);

                //multiply the matrix
                this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);

                ret.x = this->matrixPosition.getNoIF(0u,0u);
                ret.y = this->matrixPosition.getNoIF(0u,1u);
            }
        }
    }
    return ret;
}
bool edk::shape::Polygon2D::getWorldPolygonClone(edk::shape::Polygon2D* dest,edk::vector::Matrixf32<3u,3u>* transformMat){
    bool ret = false;
    if(dest){
        edk::uint32 size = this->getVertexCount();
        if(size){
            //first copy the matrix
            if(this->matrixTransform.cloneFrom(transformMat)){
                //generate transform matrices
                edk::Math::generateTranslateMatrix(this->translate,&this->matrixTranslate);
                edk::Math::generateRotateMatrixZ(this->angle,&this->matrixRotate);
                edk::Math::generateScaleMatrix(this->scale,&this->matrixScale);

                //multiply the matrix by
                //translate
                this->matrixTransform.multiplyThisWithMatrix(&this->matrixTranslate);
                //angle
                this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotate);
                //scale
                this->matrixTransform.multiplyThisWithMatrix(&this->matrixScale);

                //transform all the vertices
                if(this->matrixPosition.haveMatrix()){
                    //clone the polygon
                    if(dest->cloneFrom(this)){
                        //move the vertexes
                        for(edk::uint32 i=0u;i<size;i++){
                            if(vertexs.get(i)){
                                this->matrixPosition.set(0u,0u,vertexs.getNoIF(i)->position.x);
                                this->matrixPosition.set(0u,1u,vertexs.getNoIF(i)->position.y);
                                this->matrixPosition.set(0u,2u,1.f);

                                //multiply the matrix
                                this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);

                                dest->setVertexPosition(i,this->matrixPosition.getNoIF(0u,0u),this->matrixPosition.getNoIF(0u,1u));
                                ret = true;
                            }
                        }
                    }
                }
            }
        }
    }
    return ret;
}
bool edk::shape::Polygon2D::getWorldPolygonCopy(edk::shape::Polygon2D* dest,edk::vector::Matrixf32<3u,3u>* transformMat){
    bool ret=false;
    if(dest){
        edk::uint32 size = this->getVertexCount();
        if(size){
            //first copy the matrix
            if(this->matrixTransform.cloneFrom(transformMat)){
                //generate transform matrices
                edk::Math::generateTranslateMatrix(this->translate,&this->matrixTranslate);
                edk::Math::generateRotateMatrixZ(this->angle,&this->matrixRotate);
                edk::Math::generateScaleMatrix(this->scale,&this->matrixScale);

                //multiply the matrix by
                //translate
                this->matrixTransform.multiplyThisWithMatrix(&this->matrixTranslate);
                //angle
                this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotate);
                //scale
                this->matrixTransform.multiplyThisWithMatrix(&this->matrixScale);

                //transform all the vertices
                if(this->matrixPosition.haveMatrix()){
                    //clone the polygon
                    if(dest->getVertexCount() == size){
                        //move the vertexes
                        for(edk::uint32 i=0u;i<size;i++){
                            if(vertexs.get(i)){
                                this->matrixPosition.set(0u,0u,vertexs.getNoIF(i)->position.x);
                                this->matrixPosition.set(0u,1u,vertexs.getNoIF(i)->position.y);
                                this->matrixPosition.set(0u,2u,1.f);

                                //multiply the matrix
                                this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);

                                dest->setVertexPosition(i,this->matrixPosition.getNoIF(0u,0u),this->matrixPosition.getNoIF(0u,1u));
                                ret=true;
                            }
                        }
                    }
                }
            }
        }
    }
    return ret;
}

//delete the polygonVertex
void edk::shape::Polygon2D::deletePolygon(){
    //remove the animation
    this->framesRemoveAnimation();
    edk::uint32 size = this->getVertexCount();
    for(edk::uint32 i=0u;i<size;i++){
        //
        if(this->vertexs.get(i)){
            delete this->vertexs.getNoIF(i);
        }
        if(this->vertexsOriginal.get(i)){
            delete this->vertexsOriginal.getNoIF(i);
        }
    }
    this->vertexs.deleteArray();
    this->vertexsOriginal.deleteArray();

    //delete the morph
    size = this->getMorphCount();
    edk::shape::Polygon2D::Polygon2DMorph* temp = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->vertexsMorph.get(i);
        if(temp){
            delete temp;
        }
    }
    this->vertexsMorph.clean();

    //clear the vertexBuffer
    this->vertexBuffer.clean();
}
//remove the UV of one vertex
bool edk::shape::Polygon2D::removeVertexUV(edk::uint32 vertex){
    this->frameUsing=edk::vec2ui32(0u,0u);
    //find the vertex
    edk::shape::Vertex2DWithUV* uvTemp = (edk::shape::Vertex2DWithUV*)this->getVertexPointer(vertex);
    edk::shape::Vertex2DWithUV* uvoTemp = (edk::shape::Vertex2DWithUV*)this->getVertexOriginalPointer(vertex);
    if(uvTemp && uvoTemp){
        //test the ID of the vertex
        if(uvTemp->getType() == EDK_SHAPE_UV
                ||
                uvTemp->getType() == EDK_SHAPE_ANIMATED_UV
                ||
                uvoTemp->getType() == EDK_SHAPE_UV
                ||
                uvoTemp->getType() == EDK_SHAPE_ANIMATED_UV
                ){
            //then create another vertex
            edk::shape::Vertex2D* vTemp = new edk::shape::Vertex2D();
            edk::shape::Vertex2D* voTemp = new edk::shape::Vertex2D();
            if(vTemp && voTemp){
                //copy the uvTemp to vTemp
                vTemp->position = uvTemp->position;
                vTemp->color = uvTemp->color;
                voTemp->position = uvTemp->position;
                voTemp->color = uvTemp->color;

                //set the new vertex to the position
                this->vertexs.set(vertex,vTemp);
                this->vertexsOriginal.set(vertex,voTemp);
                //delete the uvTemp
                delete uvTemp;
                delete uvoTemp;
                //clean uvTemp
                uvTemp=NULL;
                uvoTemp=NULL;
                //return true
                return true;
            }
        }
    }
    //else return false
    return false;
}
//remove the UV from the polygon
void edk::shape::Polygon2D::removePolygonUV(){
    //
    for(edk::uint32 i=0u;i<this->vertexs.size();i++){
        //
        this->edk::shape::Polygon2D::removeVertexUV(i);
    }
}
//clean the UV animation in polygons
void edk::shape::Polygon2D::cleanPolygonUVAnimation(){
    //
    for(edk::uint32 i=0u;i<this->vertexs.size();i++){
        //
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs.get(i);
        edk::shape::Vertex2DAnimatedUV* tempO = (edk::shape::Vertex2DAnimatedUV*)this->vertexsOriginal.get(i);
        if(temp && tempO){
            if(temp->getType()==EDK_SHAPE_ANIMATED_UV
                    && tempO->getType()==EDK_SHAPE_ANIMATED_UV
                    ){
                //
                temp->cleanUVAnimation();
                tempO->cleanUVAnimation();
            }
        }
    }
}
//ANIMATION
//create a new animationFrames
bool edk::shape::Polygon2D::framesCreateAnimation(){
    //remove the last animationFrames
    this->framesRemoveAnimation();
    //create a new animationFrames and set it
    edk::animation::Interpolation1DGroup* temp=NULL;
    temp = new edk::animation::Interpolation1DGroup;
    if(this->framesSetAnimation(temp)){
        //return true
        return this->createAnimationFrames=true;
    }
    //else delete temp if exist
    if(temp){
        //
        delete temp;
    }
    //else return false
    return this->createAnimationFrames=false;
}
bool edk::shape::Polygon2D::framesSetAnimation(edk::animation::Interpolation1DGroup* anim){
    //test the anim
    if(anim){
        //test if the anim is iqual the animationFrame
        if(this->animationFrame == anim){
            //then return true
            return true;
        }
        //else remove the last animation
        this->framesRemoveAnimation();

        //set the anim
        anim->retainObject((edk::animation::InterpolationGroup**)&this->animationFrame);
        //test if have the new animation
        if(this->animationFrame){
            //return true
            return true;
        }
    }
    //else return false;
    return false;
}
//return the animationPointer
edk::animation::Interpolation1DGroup* edk::shape::Polygon2D::framesGetAnimation(){
    //
    return this->animationFrame;
}
//remove the animationGroup
void edk::shape::Polygon2D::framesRemoveAnimation(){
    this->createAnimationFrames=false;
    //test if have an animation
    if(this->framesHaveAnimation()){
        //remove the animation
        this->animationFrame->releaseObject((edk::animation::InterpolationGroup**)&this->animationFrame);
    }
    this->animationFrame=NULL;
}
//return true if have an animation
bool edk::shape::Polygon2D::framesHaveAnimation(){
    //
    return (this->animationFrame!=NULL);
}
//return true if this polygon create the animation
bool edk::shape::Polygon2D::framesIsAnimationCreator(){
    //
    return this->createAnimationFrames;
}


//return the vertexCount
edk::uint32 edk::shape::Polygon2D::getVertexCount(){
    //
    if(this->vertexsOriginal.size() < this->vertexs.size()){
        return this->vertexsOriginal.size();
    }
    return this->vertexs.size();
}
//return if the vertex have UV
edk::uint8 edk::shape::Polygon2D::getVertexType(edk::uint32 pos){
    //test if have the polygon
    if(pos<this->getVertexCount()){
        if(this->vertexs.get(pos)){
            return this->vertexs.getNoIF(pos)->getType();
        }
    }
    //else retun false
    return 0u;
}
//return the vertex
edk::vec2f32 edk::shape::Polygon2D::getVertexPosition(edk::uint32 pos){
    //test if have the vertex
    if(pos<this->getVertexCount()){
        if(this->vertexs.get(pos)){
            //return the vertex
            return edk::vec2f32(this->vertexs.getNoIF(pos)->position.x,this->vertexs.getNoIF(pos)->position.y);
        }
    }
    //else return a zero vertex
    return edk::vec2f32(0,0);
}
//return the vertex with all transformations
edk::vec2f32 edk::shape::Polygon2D::getVertexPositionTransformed(edk::uint32 pos){
    //test if have the vertex
    if(pos<this->getVertexCount()){
        if(this->vertexs.get(pos)){
            //apply the transformations
            edk::vec2f32 ret;
            //scale
            ret.x = this->vertexs.getNoIF(pos)->position.x * this->scale.width;
            ret.y = this->vertexs.getNoIF(pos)->position.y * this->scale.height;
            //rotate
            ret = edk::Math::rotatePlus(ret,this->angle);
            //translate
            ret.x += this->translate.x;
            ret.y += this->translate.y;
            //return the vertex
            return ret;
        }
    }
    //else return a zero vertex
    return edk::vec2f32(0,0);
}
//return the vertex color
edk::color4f32 edk::shape::Polygon2D::getVertexColor(edk::uint32 pos){

    //test if have the vertex
    if(pos<this->getVertexCount()){
        if(this->vertexs.get(pos)){
            //return the vertex
            return edk::color4f32(this->vertexs.getNoIF(pos)->color.r,this->vertexs.getNoIF(pos)->color.g,this->vertexs.getNoIF(pos)->color.b,
                                  this->vertexs.getNoIF(pos)->color.a);
        }
    }
    //else return a zero vertex
    return edk::color4f32(0,0,0,0);
}
//return the vertex UV
edk::vec2f32 edk::shape::Polygon2D::getVertexUV(edk::uint32 pos){
    //test if have the vertex
    if(pos<this->getVertexCount()){
        //get a temp
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs.get(pos);
        if(temp){
            //test if the vertex have the UV
            switch(temp->getType()){
            //
            case EDK_SHAPE_UV:
                //
                return edk::vec2f32(temp->getUV().x,temp->getUV().y);
                break;
            case EDK_SHAPE_ANIMATED_UV:
                //
                return edk::vec2f32(temp->getSaved().x,temp->getSaved().y);
                break;
            }
        }
    }
    //else return a zero vertex
    return edk::vec2f32(0,0);
}
//return the frames
edk::vec2ui32 edk::shape::Polygon2D::getFrames(){
    //
    return this->frames;
}
edk::uint32 edk::shape::Polygon2D::getFramesPosition(){
    return this->framesSize;
}
//return the frameUseds
edk::vec2ui32 edk::shape::Polygon2D::getFrameUsed(){
    return this->frameUsing;
}
edk::uint32 edk::shape::Polygon2D::getFramePositionUsed(){
    if(this->frames.x && this->frames.y){
        return (this->frames.x * this->frameUsing.y) + this->frameUsing.x;
    }
    return 0u;
}
//return the morphCount
edk::uint32 edk::shape::Polygon2D::getMorphCount(){
    return this->vertexsMorph.size();
}
//return the transform
edk::vec2f32 edk::shape::Polygon2D::getTranslate(){
    return this->translate;
}
edk::size2f32 edk::shape::Polygon2D::getScale(){
    return this->scale;
}
edk::float32 edk::shape::Polygon2D::getAngle(){
    return this->angle;
}
//return true if is transforming
bool edk::shape::Polygon2D::isTransforming(){
    return this->transforming;
}
//get Physics
edk::float32 edk::shape::Polygon2D::getDensity(){
    return this->density;
}
edk::float32 edk::shape::Polygon2D::getFriction(){
    return this->friction;
}
edk::float32 edk::shape::Polygon2D::getRestitution(){
    return this->restitution;
}

//return true if the polygon is a circle
bool edk::shape::Polygon2D::isCircle(){
    if(this->type == edk::shape::typeCircle2D){
        return true;
    }
    return false;
}
//return the circleRadius only if is a circle
edk::float32 edk::shape::Polygon2D::getCircleRadius(){
    if(this->type == edk::shape::typeCircle2D){
        return this->radius;
    }
    return 0.f;
}
//return true if it's a Rectangle
bool edk::shape::Polygon2D::isRect(){
    if(this->type == edk::shape::typeRectangle2D){
        return true;
    }
    return false;
}
//return true if it's lines
bool edk::shape::Polygon2D::isLine(){
    if(this->type == edk::shape::typeLine2D){
        return true;
    }
    return false;
}
//get line ID
edk::uint8 edk::shape::Polygon2D::getCollisionID(){
    return this->collisionID;
}

//functions for the vertexes animations
edk::uint32 edk::shape::Polygon2D::newPolygonMorph(edk::float32 percent,bool* success){
    //test if have the vertexs
    if(this->getVertexCount()){
        //create a new morph
        edk::shape::Polygon2D::Polygon2DMorph* temp = new edk::shape::Polygon2D::Polygon2DMorph(this->getVertexCount(),
                                                                                                this->polygonColor
                                                                                                );
        if(temp){
            edk::uint32 positionMorph = this->vertexsMorph.pushBack(temp);
            if(positionMorph<this->vertexsMorph.size()){
                *success=true;
                temp->percent=percent;
                return positionMorph;
            }
            delete temp;
        }
    }
    *success=false;
    return 0u;
}
bool edk::shape::Polygon2D::havePolygonMorph(edk::uint32 positionMorph){
    return this->vertexsMorph.havePos(positionMorph);
}
bool edk::shape::Polygon2D::deletePolygonMorph(edk::uint32 positionMorph){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            if(this->vertexsMorph.remove(positionMorph)){
                delete temp;
                return true;
            }
        }
    }
    return false;
}
void edk::shape::Polygon2D::cleanPolygonMorph(){
    edk::uint32 size = this->vertexsMorph.size();
    edk::shape::Polygon2D::Polygon2DMorph* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->vertexsMorph.get(i);
        if(temp){
            delete temp;
        }
    }
    this->vertexsMorph.clean();
}
void edk::shape::Polygon2D::deleteAllPolygonMorph(){
    this->cleanPolygonMorph();
}
edk::uint32 edk::shape::Polygon2D::getPolygonMorphSize(){
    return this->vertexsMorph.size();
}
//morph setters
//set the position of a vertex
bool edk::shape::Polygon2D::setPolygonMorphVertexPosition(edk::uint32 positionMorph,edk::uint32 vertex,edk::vec2f32 position){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            return temp->setVertexPosition(vertex,position);
        }
    }
    return false;
}
bool edk::shape::Polygon2D::setPolygonMorphVertexPosition(edk::uint32 positionMorph,edk::uint32 vertex,edk::float32 x,edk::float32 y){
    return this->setPolygonMorphVertexPosition(positionMorph,vertex,edk::vec2f32(x,y));
}
//set the color of a vertex
bool edk::shape::Polygon2D::setPolygonMorphVertexColor(edk::uint32 positionMorph,edk::uint32 vertex,edk::color4f32 color){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            return temp->setVertexColor(vertex,color);
        }
    }
    return false;
}
bool edk::shape::Polygon2D::setPolygonMorphVertexColor(edk::uint32 positionMorph,edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b){
    return setPolygonMorphVertexColor(positionMorph,vertex,edk::color4f32(r,g,b,1.f));
}
bool edk::shape::Polygon2D::setPolygonMorphVertexColor(edk::uint32 positionMorph,edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return setPolygonMorphVertexColor(positionMorph,vertex,edk::color4f32(r,g,b,a));
}
//Set polygon color
bool edk::shape::Polygon2D::setPolygonMorphColor(edk::uint32 positionMorph,edk::color4f32 color){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            return temp->setPolygonColor(color);
        }
    }
    return false;
}
bool edk::shape::Polygon2D::setPolygonMorphColor(edk::uint32 positionMorph,edk::color3f32 color){
    return setPolygonMorphColor(positionMorph,edk::color4f32(color.r,color.g,color.b,1.f));
}
bool edk::shape::Polygon2D::setPolygonMorphColor(edk::uint32 positionMorph,edk::float32 r,edk::float32 g,edk::float32 b){
    return setPolygonMorphColor(positionMorph,edk::color4f32(r,g,b,1.f));
}
bool edk::shape::Polygon2D::setPolygonMorphColor(edk::uint32 positionMorph,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return setPolygonMorphColor(positionMorph,edk::color4f32(r,g,b,a));
}
bool edk::shape::Polygon2D::setPolygonMorphColorR(edk::uint32 positionMorph,edk::float32 r){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            return temp->setPolygonColorR(r);
        }
    }
    return false;
}
bool edk::shape::Polygon2D::setPolygonMorphColorG(edk::uint32 positionMorph,edk::float32 g){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            return temp->setPolygonColorG(g);
        }
    }
    return false;
}
bool edk::shape::Polygon2D::setPolygonMorphColorB(edk::uint32 positionMorph,edk::float32 b){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            return temp->setPolygonColorB(b);
        }
    }
    return false;
}
bool edk::shape::Polygon2D::setPolygonMorphColorA(edk::uint32 positionMorph,edk::float32 a){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            return temp->setPolygonColorA(a);
        }
    }
    return false;
}
//set the UVMap of the vertex
bool edk::shape::Polygon2D::setPolygonMorphVertexUV(edk::uint32 positionMorph,edk::uint32 vertex,edk::vec2f32 uv){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            return temp->setVertexUV(vertex,uv);
        }
    }
    return false;
}
bool edk::shape::Polygon2D::setPolygonMorphVertexUV(edk::uint32 positionMorph,edk::uint32 vertex,edk::float32 x,edk::float32 y){
    return this->setPolygonMorphVertexUV(positionMorph,vertex,edk::vec2f32(x,y));
}
//Set the polygonFrames setting in the vertexs
bool edk::shape::Polygon2D::setPolygonMorphUVFrames(edk::uint32 positionMorph,edk::vec2ui32 frames){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            return temp->setPolygonUVFrames(frames);
        }
    }
    return false;
}
bool edk::shape::Polygon2D::setPolygonMorphUVFrames(edk::uint32 positionMorph,edk::uint32 x,edk::uint32 y){
    return this->setPolygonMorphUVFrames(positionMorph,edk::vec2ui32(x,y));
}
bool edk::shape::Polygon2D::setPolygonMorphUVFramesX(edk::uint32 positionMorph,edk::uint32 x){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            return temp->setPolygonUVFramesX(x);
        }
    }
    return false;
}
bool edk::shape::Polygon2D::setPolygonMorphUVFramesY(edk::uint32 positionMorph,edk::uint32 y){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            return temp->setPolygonUVFramesY(y);
        }
    }
    return false;
}
//Set the polygon frame
bool edk::shape::Polygon2D::usePolygonMorphUVFrame(edk::uint32 positionMorph,edk::vec2ui32 frame){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            temp->usePolygonUVFrame(frame);
            return true;
        }
    }
    return false;
}
bool edk::shape::Polygon2D::usePolygonMorphUVFramePosition(edk::uint32 positionMorph,edk::uint32 position){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            edk::vec2ui32 UVPosition(position%this->frames.x,position/this->frames.x);
            temp->usePolygonUVFrame(UVPosition);
            return true;
        }
    }
    return false;
}
bool edk::shape::Polygon2D::usePolygonMorphUVFrameX(edk::uint32 positionMorph,edk::uint32 x){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            temp->usePolygonUVFrameX(x);
            return true;
        }
    }
    return false;
}
bool edk::shape::Polygon2D::usePolygonMorphUVFrameY(edk::uint32 positionMorph,edk::uint32 y){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            temp->usePolygonUVFrameY(y);
            return true;
        }
    }
    return false;
}
edk::float32 edk::shape::Polygon2D::getPolygonMorphPercent(edk::uint32 positionMorph){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            return temp->percent;
        }
    }
    return 0.f;
}
//return the vertexCount
edk::uint32 edk::shape::Polygon2D::getPolygonMorphVertexCount(){
    return this->vertexsMorph.size();
}
//return if the vertex have UV
edk::uint8 edk::shape::Polygon2D::getPolygonMorphVertexType(edk::uint32 positionMorph){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            return temp->percent;
        }
    }
    return 0u;
}
//return the vertex
edk::vec2f32 edk::shape::Polygon2D::getPolygonMorphVertexPosition(edk::uint32 positionMorph,edk::uint32 positionVertex){
    edk::vec2f32 ret;
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            ret = temp->getVertexPosition(positionVertex);
        }
    }
    return ret;
}
//return the vertex with all transformations
edk::vec2f32 edk::shape::Polygon2D::getPolygonMorphVertexPositionTransformed(edk::uint32 positionMorph,edk::uint32 positionVertex){
    edk::vec2f32 ret;
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            ret = temp->getVertexPositionTransformed(positionVertex);
        }
    }
    return ret;
}
//return the vertex color
edk::color4f32 edk::shape::Polygon2D::getPolygonMorphVertexColor(edk::uint32 positionMorph,edk::uint32 positionVertex){
    edk::color4f32 ret;
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            ret = temp->getVertexColor(positionVertex);
        }
    }
    return ret;
}
//return the vertex UV
edk::vec2f32 edk::shape::Polygon2D::getPolygonMorphVertexUV(edk::uint32 positionMorph,edk::uint32 positionVertex){
    edk::vec2f32 ret;
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            ret = temp->getVertexUV(positionVertex);
        }
    }
    return ret;
}
//return the frames
edk::vec2ui32 edk::shape::Polygon2D::getPolygonMorphFrames(edk::uint32 positionMorph){
    edk::vec2ui32 ret;
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);
        if(temp){
            ret = temp->getFrames(0u);
        }
    }
    return ret;
}

edk::rectf32 edk::shape::Polygon2D::getRect(){
    edk::rectf32 ret;
    edk::vec2f32 position;
    edk::uint32 size = this->getVertexCount();
    if(size){
        position = this->getVertexPosition(0u);
        ret.origin.x = ret.size.width = position.x;
        ret.origin.y = ret.size.height = position.y;
        for(edk::uint32 i=0u;i<size;i++){
            position = this->getVertexPosition(i);
            if(ret.origin.x>position.x){
                ret.origin.x=position.x;
            }
            if(ret.size.width<position.x){
                ret.size.width=position.x;
            }
            if(ret.origin.y>position.y){
                ret.origin.y=position.y;
            }
            if(ret.size.height<position.y){
                ret.size.height=position.y;
            }
        }
    }
    return ret;
}

//print the polygon
void edk::shape::Polygon2D::print(){
    /*
    for(edk::uint32 i=0u;i<this->getVertexCount();i++){
        //
        if(vertexs.get(i)){
            vertexs.getNoIF(i)->print(i);
        }
    }
    */

    //printVBO
    (this->*vboPrint)();
}
//Draw the polygon
void edk::shape::Polygon2D::draw(){
    edk::GU::guPushMatrix();
    edk::GU::guTranslate2f32(this->translate);
    edk::GU::guRotateZf32(this->angle);
    edk::GU::guScale2f32(this->scale);
    /*
    edk::GU::guBegin(GU_POLYGON);
    this->drawVertexs();
    edk::GU::guEnd();
*/
    //drawVBO
    (this->*vboDraw)(GU_POLYGON);

    edk::GU::guPopMatrix();
}
//Draw the polygons with lines
void edk::shape::Polygon2D::drawWire(){
    edk::GU::guPushMatrix();
    edk::GU::guTranslate2f32(this->translate);
    edk::GU::guRotateZf32(this->angle);
    edk::GU::guScale2f32(this->scale);
    /*
    edk::GU::guBegin(GU_LINE_LOOP);
    this->drawVertexs();
    edk::GU::guEnd();
*/
    //drawVBO
    (this->*vboDraw)(GU_LINE_LOOP);

    edk::GU::guPopMatrix();
}
//Draw the polygons with lines without using matrices
void edk::shape::Polygon2D::drawWireWorld(){
    //drawVBO
    (this->*vboDraw)(GU_LINE_LOOP);
}
//draw vertexs
void edk::shape::Polygon2D::drawPolygonVertexs(edk::color4f32 color){
    edk::GU::guBegin(GL_POINTS);
    //edk::GU::guBegin(GU_LINE_LOOP);
    this->drawVertexsWithColor(color);
    edk::GU::guEnd();
    //drawVBO
    //(this->*vboDrawPolygonVertexes)(color);
}
void edk::shape::Polygon2D::drawPolygonVertexsWorld(edk::color4f32 color){
    edk::GU::guBegin(GL_POINTS);
    //edk::GU::guBegin(GU_LINE_LOOP);
    this->drawVertexsWithColor(color);
    edk::GU::guEnd();
    //drawVBO
    //(this->*vboDrawPolygonVertexes)(color);
}

//Write to XML
bool edk::shape::Polygon2D::writeToXML(edk::XML* xml,edk::uint32 polygonID){
    if(xml){
        bool ret=false;
        //create the ID string
        edk::char8* id = edk::String::int32ToStr(polygonID);
        if(id){
            edk::char8* name = edk::String::strCat((edk::char8*)"polygon_",id);
            if(name){
                //create the polygon
                if(xml->addSelectedNextChild(name)){
                    //select the name
                    if(xml->selectChild(name)){
                        ret=true;
                        edk::char8* temp = NULL;
                        //test if it's circle
                        if(this->polygonCircle || this->type==edk::shape::typeCircle2D){
                            //set the string
                            xml->setSelectedString("circle");
                            temp = edk::String::float32ToStr(this->getCircleRadius());
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"radius",temp);
                                free(temp);
                            }
                        }
                        else if(this->polygonLine || this->type==edk::shape::typeLine2D){
                            //set the string
                            xml->setSelectedString("line");
                            temp = edk::String::int32ToStr(this->getCollisionID());
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"collisionID",temp);
                                free(temp);
                            }
                        }
                        else if(this->type==edk::shape::typeRectangle2D){
                            //set the string
                            xml->setSelectedString("rectangle");
                        }
                        else{
                            //set the string
                            xml->setSelectedString("polygon");
                        }

                        edk::uint32 size = this->getVertexCount();
                        //save the vertexs
                        temp=edk::String::int32ToStr(size);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"vCount",temp);
                            free(temp);
                        }
                        //Write Vertexs
                        for(edk::uint32 i=0u;i<size;i++){
                            edk::shape::Vertex2DAnimatedUV* polyTemp = (edk::shape::Vertex2DAnimatedUV*)vertexs.get(i);
                            if(polyTemp){
                                polyTemp->writeToXML(i,xml);
                            }
                        }
                        if(xml->addSelectedNextChild("original")){
                            if(xml->selectChild("original")){
                                //write the vertexsOriginal

                                size = this->getVertexCount();
                                //save the vertexs
                                temp=edk::String::int32ToStr(size);
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"voCount",temp);
                                    free(temp);
                                }
                                //Write Vertexs
                                for(edk::uint32 i=0u;i<size;i++){
                                    edk::shape::Vertex2DAnimatedUV* polyTemp = (edk::shape::Vertex2DAnimatedUV*)vertexsOriginal.get(i);
                                    if(polyTemp){
                                        polyTemp->writeToXML(i,xml);
                                    }
                                }

                                xml->selectFather();
                            }
                        }
                        //write morphs
                        if(xml->addSelectedNextChild("morph")){
                            if(xml->selectChild("morph")){
                                size = this->vertexsMorph.size();
                                //save the morphs
                                temp=edk::String::int32ToStr(size);
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"mCount",temp);
                                    free(temp);
                                }
                                //Write morphs
                                edk::shape::Polygon2D::Polygon2DMorph* morph = NULL;
                                for(edk::uint32 i=0u;i<size;i++){
                                    morph = this->vertexsMorph.get(i);
                                    if(morph){
                                        morph->writeToXML(xml,i);
                                    }
                                }

                                xml->selectFather();
                            }
                        }
                        if(xml->addSelectedNextChild("uvFrames")){
                            if(xml->selectChild("uvFrames")){
                                //write UVFrames
                                temp = edk::String::float32ToStr(this->getFrames().x);
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"framesX",temp);
                                    free(temp);
                                }
                                temp = edk::String::float32ToStr(this->getFrames().y);
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"framesY",temp);
                                    free(temp);
                                }
                                //write selected
                                temp = edk::String::float32ToStr(this->frameUsing.x);
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"frameUsingX",temp);
                                    free(temp);
                                }
                                temp = edk::String::float32ToStr(this->frameUsing.y);
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"frameUsingY",temp);
                                    free(temp);
                                }
                                xml->selectFather();
                            }
                        }
                        //write transformations
                        if(xml->addSelectedNextChild("transformation")){
                            if(xml->selectChild("transformation")){
                                temp = edk::String::float32ToStr(this->getTranslate().x);
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"translateX",temp);
                                    free(temp);
                                }
                                temp = edk::String::float32ToStr(this->getTranslate().y);
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"translateY",temp);
                                    free(temp);
                                }
                                temp = edk::String::float32ToStr(this->getScale().width);
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"scaleW",temp);
                                    free(temp);
                                }
                                temp = edk::String::float32ToStr(this->getScale().height);
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"scaleH",temp);
                                    free(temp);
                                }
                                temp = edk::String::float32ToStr(this->getAngle());
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"angle",temp);
                                    free(temp);
                                }
                                xml->selectFather();
                            }
                        }
                        //write physics
                        if(xml->addSelectedNextChild("physics")){
                            if(xml->selectChild("physics")){
                                temp = edk::String::float32ToStr(this->getDensity());
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"density",temp);
                                    free(temp);
                                }
                                temp = edk::String::float32ToStr(this->getFriction());
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"friction",temp);
                                    free(temp);
                                }
                                temp = edk::String::float32ToStr(this->getRestitution());
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"restitution",temp);
                                    free(temp);
                                }
                                xml->selectFather();
                            }
                        }
                        //UV animations
                        if(this->animationFrame){
                            this->animationFrame->writeToXML(xml,0u);
                        }
                        xml->selectFather();
                    }
                }
                free(name);
            }
            free(id);
        }
        return ret;
    }
    return false;
}
//read from XML
bool edk::shape::Polygon2D::readFromXML(edk::XML* xml,edk::uint32 polygonID){
    if(xml){
        bool ret=false;
        //create the ID string
        edk::char8* id = edk::String::int32ToStr(polygonID);
        if(id){
            edk::char8* name = edk::String::strCat((edk::char8*)"polygon_",id);
            if(name){
                //create the polygon
                //select the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* temp;
                    //load the polygonType
                    temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);
                    if(temp){
                        //teste the type
                        if(edk::String::strCompare(temp,"circle")){
                            this->polygonCircle = true;
                            this->polygonLine = false;
                            this->radius = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("radius"));
                            this->collisionID = 0u;
                            this->type = edk::shape::typeCircle2D;
                        }
                        else if(edk::String::strCompare(temp,"line")){
                            this->polygonLine = true;
                            this->polygonCircle = false;
                            this->radius = 0.f;
                            this->collisionID = edk::String::strToInt32(xml->getSelectedAttributeValueByName("collisionID"));
                            this->type = edk::shape::typeLine2D;
                        }
                        else if(edk::String::strCompare(temp,"rectangle")){
                            this->polygonLine = false;
                            this->polygonCircle = false;
                            this->radius = 0.f;
                            this->collisionID = 0u;
                            this->type = edk::shape::typeRectangle2D;
                        }
                        else if(edk::String::strCompare(temp,"polygon")){
                            //
                            this->type = edk::shape::typePolygon2D;
                        }
                        free(temp);
                    }

                    //read the vertex count
                    edk::uint32 size = edk::String::strToInt32(xml->getSelectedAttributeValueByName("vCount"));
                    if(size){
                        this->createPolygon(size);
                        //read the vertexs
                        for(edk::uint32 i=0u;i<size;i++){
                            //read the vertex type
                            edk::uint8 type = edk::shape::Vertex2D::readTypeFromXML(i,xml);
                            switch(type){
                            case EDK_SHAPE_ANIMATED_UV:
                            case EDK_SHAPE_UV:
                            {
                                edk::shape::Vertex2DAnimatedUV temp;
                                if(temp.readFromXML(i,xml)){
                                    //set the data
                                    this->setVertexPosition(i,temp.position);
                                    this->setVertexColor(i,temp.color);
                                    this->setVertexUV(i,temp.getSaved());
                                }
                                break;
                            }
                            case EDK_SHAPE_NOUV:
                            {
                                edk::shape::Vertex2D temp;
                                if(temp.readFromXML(i,xml)){
                                    //set the data
                                    this->setVertexPosition(i,temp.position);
                                    this->setVertexColor(i,temp.color);
                                }
                                break;
                            }
                            }
                        }
                        //read the original
                        if(xml->selectChild("original")){
                            size = edk::String::strToInt32(xml->getSelectedAttributeValueByName("voCount"));
                            if(size){
                                edk::shape::Vertex2D* vTemp = NULL;
                                //read the vertexs
                                for(edk::uint32 i=0u;i<size;i++){
                                    //read the vertex type
                                    edk::uint8 type = edk::shape::Vertex2D::readTypeFromXML(i,xml);
                                    switch(type){
                                    case EDK_SHAPE_ANIMATED_UV:
                                    case EDK_SHAPE_UV:
                                    {
                                        edk::shape::Vertex2DAnimatedUV temp;
                                        vTemp = this->vertexsOriginal.get(i);
                                        edk::shape::Vertex2DAnimatedUV* uvTemp = new edk::shape::Vertex2DAnimatedUV;
                                        if(uvTemp){
                                            if(temp.readFromXML(i,xml)){
                                                //set the data
                                                uvTemp->position = temp.position;
                                                uvTemp->color = temp.color;
                                                uvTemp->setUV(temp.getUV());
                                                uvTemp->setUVFrames(temp.getUVFrames());

                                                this->vertexsOriginal.set(i,uvTemp);
                                                if(vTemp){
                                                    delete vTemp;
                                                }
                                                vTemp=NULL;
                                            }
                                            else{
                                                delete uvTemp;
                                            }
                                        }
                                        break;
                                    }
                                    case EDK_SHAPE_NOUV:
                                    {
                                        edk::shape::Vertex2D temp;
                                        vTemp = this->vertexsOriginal.get(i);
                                        if(temp.readFromXML(i,xml) && vTemp){
                                            //set the data
                                            vTemp->position = temp.position;
                                            vTemp->color = temp.color;
                                        }
                                        break;
                                    }
                                    }
                                }
                            }
                            xml->selectFather();
                        }
                        //read morph
                        if(xml->selectChild("morph")){
                            size = edk::String::strToInt32(xml->getSelectedAttributeValueByName("mCount"));
                            if(size){
                                //create the new morphs
                                edk::shape::Polygon2D::Polygon2DMorph* morph=NULL;
                                for(edk::uint32 i=0u;i<size;i++){
                                    morph = new edk::shape::Polygon2D::Polygon2DMorph(this->getVertexCount(),this->polygonColor);
                                    if(morph){
                                        //load the xml
                                        if(morph->readFromXML(xml,i)){
                                            //add the morph in to the array
                                            this->vertexsMorph.pushBack(morph);
                                        }
                                        else{
                                            delete morph;
                                            morph=NULL;
                                        }
                                    }
                                }
                            }
                            xml->selectFather();
                        }


                        //read uvFrames
                        if(xml->selectChild("uvFrames")){
                            //write UVFrames
                            edk::uint32 uvFrameX = (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("framesX"));
                            edk::uint32 uvFrameY = (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("framesY"));
                            //set uvFrames
                            this->setPolygonUVFrames(edk::vec2ui32(uvFrameX,uvFrameY));

                            //set using the frame ID
                            this->frameUsing.x = (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("frameUsingX"));
                            this->frameUsing.y = (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("frameUsingY"));

                            //set the frameUsing
                            this->usePolygonUVFrame(this->frameUsing);

                            xml->selectFather();
                        }

                        //read transformation
                        if(xml->selectChild("transformation")){
                            this->translate.x = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("translateX"));
                            this->translate.y = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("translateY"));
                            this->scale.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("scaleW"));
                            this->scale.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("scaleH"));
                            this->angle = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("angle"));
                            this->testTransform();
                            xml->selectFather();
                        }

                        //read physics
                        if(xml->selectChild("physics")){
                            this->density = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("density"));
                            this->friction = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("friction"));
                            this->restitution = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("restitution"));
                            xml->selectFather();
                        }

                        this->framesCreateAnimation();
                        //UV animations
                        if(this->animationFrame){
                            if(this->animationFrame->readFromXML(xml,0u)){
                                //set play
                                this->animationFrame->playForward();
                            }
                            else{
                                //delete the frame
                                this->framesRemoveAnimation();
                            }
                        }
                        ret=true;
                    }
                    xml->selectFather();
                }
                free(name);
            }
            free(id);
        }
        return ret;
    }
    return false;
}

bool edk::shape::Polygon2D::cloneFrom(edk::shape::Polygon2D* poly){
    //first delete the vertexs
    this->deletePolygon();
    if(poly){
        //then create a new polygon
        if(this->createPolygon(poly->getVertexCount())){
            edk::uint32 size=this->getVertexCount();
            edk::shape::Vertex2DAnimatedUV* temp = NULL;
            edk::shape::Vertex2D* vTemp = NULL;
            edk::shape::Vertex2DWithUV* uvTemp = NULL;
            edk::shape::Vertex2DAnimatedUV* uvaTemp = NULL;
            //then copy the vertex
            for(edk::uint32 i=0u;i<size;i++){
                //copy the vertex
                temp = (edk::shape::Vertex2DAnimatedUV*)vertexs.get(i);
                if(temp){
                    //this->setVertexPosition(i,poly->getVertexPosition(i));
                    temp->position = poly->getVertexPosition(i);
                    this->setVBOVertexPosition(i,temp->position);
                    //this->setVertexColor(i,poly->getVertexColor(i));
                    temp->color = poly->getVertexColor(i);
                    this->setVBOVertexColor(i,temp->color);
                    //copy the frames
                    //this->setVertexUVFrames(i,poly->getFrames());
                    //get vertexType
                    switch(poly->getVertexType(i)){
                    //
                    case EDK_SHAPE_ANIMATED_UV:
                        //
                        this->setVertexUV(i,poly->getVertexUV(i));
                        this->setVertexUVFrames(i,poly->getFrames());
                        break;
                    case EDK_SHAPE_UV:
                        //
                        this->setVertexUV(i,poly->getVertexUV(i));
                        break;
                    };
                }
                vTemp = vertexsOriginal.get(i);
                if(vTemp){
                    //get the vertex to read the values
                    temp = (edk::shape::Vertex2DAnimatedUV*)poly->vertexsOriginal.get(i);
                    //get vertexType
                    switch(temp->getType()){
                    case EDK_SHAPE_ANIMATED_UV:
                        //
                        this->setVertexUV(i,poly->getVertexUV(i));
                        this->setVertexUVFrames(i,poly->getFrames());

                        uvaTemp = new edk::shape::Vertex2DAnimatedUV;
                        if(uvaTemp){
                            //set the values
                            uvaTemp->position = temp->position;
                            uvaTemp->color = temp->color;
                            uvaTemp->setUV(temp->getUV());
                            uvaTemp->setUVFrames(temp->getUVFrames());

                            //set the vertex
                            if(this->vertexsOriginal.set(i,uvaTemp)){
                                delete vTemp;
                            }
                            else{
                                delete uvaTemp;
                            }
                        }
                        break;
                    case EDK_SHAPE_UV:
                        //
                        this->setVertexUV(i,poly->getVertexUV(i));

                        uvTemp = new edk::shape::Vertex2DWithUV;
                        if(uvTemp){
                            //set the values
                            uvTemp->position = temp->position;
                            uvTemp->color = temp->color;
                            uvTemp->setUV(temp->getUV());

                            //set the vertex
                            if(this->vertexsOriginal.set(i,uvTemp)){
                                delete vTemp;
                            }
                            else{
                                delete uvTemp;
                            }
                        }
                        break;
                    default:
                        vTemp->position = temp->position;
                        vTemp->color = temp->color;
                        break;
                    };
                }
            }

            //clone the morphs
            size = poly->vertexsMorph.size();
            edk::shape::Polygon2D::Polygon2DMorph* mTemp;
            edk::shape::Polygon2D::Polygon2DMorph* morph;
            for(edk::uint32 i=0u;i<size;i++){
                mTemp = poly->vertexsMorph.get(i);
                if(mTemp){
                    morph = new edk::shape::Polygon2D::Polygon2DMorph(0u,edk::color4f32(1.f,1.f,1.f,1.f));
                    if(morph){
                        //clone the morph
                        if(morph->cloneFrom(mTemp)){
                            //add the morph
                            if(this->vertexsMorph.pushBack(morph)){
                                delete morph;
                            }
                        }
                        else{
                            delete morph;
                        }
                    }
                }
            }
        }
        //set the polygonFrames
        this->setPolygonUVFrames(poly->getFrames());
        this->usePolygonUVFrame(poly->frameUsing);
        //set the transformations
        this->setTranslate(poly->getTranslate());
        this->setScale(poly->getScale());
        this->setAngle(poly->getAngle());
        //set physics
        this->setDensity(poly->getDensity());
        this->setFriction(poly->getFriction());
        this->setRestitution(poly->getRestitution());
        //
        this->type = poly->type;
        this->polygonCircle = poly->polygonCircle;
        this->radius=poly->radius;
        this->polygonLine = poly->polygonLine;
        this->collisionID = poly->collisionID;
        //set the animation
        this->framesSetAnimation(poly->framesGetAnimation());
        this->createAnimationFrames = poly->createAnimationFrames;
        //copy the matrices
        this->matrixTranslate.cloneFrom(&poly->matrixTranslate);
        this->matrixRotate.cloneFrom(&poly->matrixRotate);
        this->matrixScale.cloneFrom(&poly->matrixScale);
        this->matrixTransform.cloneFrom(&poly->matrixTransform);
        //
        return true;
    }
    return false;
}
