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

edk::uint8 vboSizeof[edk::shape::vbo_Size] = {
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
    this->vboType = edk::shape::vbo_NULL;edkEnd();
    this->vbo=0u;edkEnd();
    this->vboCount=0u;edkEnd();
    this->vertexBuffer.clean();edkEnd();
    this->canUseVBO=true;edkEnd();
    //set the vbo function pointers
    this->setVBOFunctionUpdateNULL();

    this->type = edk::shape::polygon2D;edkEnd();
    this->angle=0.f;edkEnd();
    this->radius = 1.f;edkEnd();
    //init the polygonCOlor
    this->polygonColor = edk::color4f32(1,1,1,1);edkEnd();
    this->canDeletePolygon=false;edkEnd();
    //set frames to 1
    this->frames = edk::vec2ui32(1u,1u);edkEnd();
    this->framesSize = this->frames.x*this->frames.y;edkEnd();
    this->animationFrame=NULL;edkEnd();
    this->createAnimationFrames=false;edkEnd();

    //Physics parameters
    this->density=1.f;edkEnd();
    this->friction=0.0f;edkEnd();
    this->restitution=0.0f;edkEnd();

    this->polygonLine = this->polygonCircle=false;edkEnd();
    this->collisionID=collisionAways;edkEnd();

    this->frameUsing=edk::vec2ui32(0u,0u);edkEnd();
    this->matrixPosition.createMatrix(1u,3u);edkEnd();
    this->testTransform();edkEnd();
}
edk::shape::Polygon2D::Polygon2D(edk::uint32 vertexCount){
    this->vboType = edk::shape::vbo_NULL;edkEnd();
    this->vbo=0u;edkEnd();
    this->vboCount=0u;edkEnd();
    this->vertexBuffer.clean();edkEnd();
    this->canUseVBO=true;edkEnd();
    //set the vbo function pointers
    this->setVBOFunctionUpdateNULL();
    this->angle=0.f;edkEnd();
    this->radius = 1.f;edkEnd();
    //
    this->polygonColor = edk::color4f32(0,0,0,1);edkEnd();
    this->canDeletePolygon=false;edkEnd();
    //create the vertex
    this->createPolygon(vertexCount);edkEnd();
    //set frames to 1
    this->frames = edk::vec2ui32(1u,1u);edkEnd();
    this->createAnimationFrames=false;edkEnd();

    this->frameUsing=edk::vec2ui32(0u,0u);edkEnd();
    this->testTransform();edkEnd();
}

edk::shape::Polygon2D::~Polygon2D(){
    //test if can delete the polygon
    if(this->canDeletePolygon){
        //destroy the polygon
        this->deletePolygon();edkEnd();
    }
    else{
        //set the shape to cant delete the vector
        this->vertexs.cantDeleteVector();edkEnd();
        this->vertexsOriginal.cantDeleteVector();edkEnd();
        this->vertexBuffer.cantDeleteVector();edkEnd();
    }
    //else set canDeletePolygon to true
    this->canDeletePolygon=true;edkEnd();
}

//PROTECTED
//set the vertexFrames animation
bool edk::shape::Polygon2D::setVertexUVFrames(edk::uint32 vertex,edk::vec2ui32 frames){
    //load the polygon
    edk::shape::Vertex2DAnimatedUV* vTemp = (edk::shape::Vertex2DAnimatedUV*)this->getVertexPointer(vertex);edkEnd();
    edk::shape::Vertex2DAnimatedUV* voTemp = (edk::shape::Vertex2DAnimatedUV*)this->getVertexOriginalPointer(vertex);edkEnd();
    if(vTemp && voTemp){
        //test if the vertex is not the AnimatedUV
        if(vTemp->getType() != EDK_SHAPE_ANIMATED_UV
                || voTemp->getType() != EDK_SHAPE_ANIMATED_UV
                ){
            //then delete the vTemp and create another with AnimatedUV
            edk::shape::Vertex2DAnimatedUV* uvTemp = new edk::shape::Vertex2DAnimatedUV();edkEnd();
            edk::shape::Vertex2DAnimatedUV* uvoTemp = new edk::shape::Vertex2DAnimatedUV();edkEnd();
            if(uvTemp && uvoTemp){
                //copy the vTemp content to uvTemp
                uvTemp->position = vTemp->position;edkEnd();
                uvTemp->color = vTemp->color;edkEnd();
                uvoTemp->position = voTemp->position;edkEnd();
                uvoTemp->color = voTemp->color;edkEnd();
                //test if have UV
                if(vTemp->getType()==EDK_SHAPE_UV){
                    //copy the UV
                    uvTemp->setUV(vTemp->getUV());edkEnd();
                }
                if(voTemp->getType()==EDK_SHAPE_UV){
                    //copy the UV
                    uvoTemp->setUV(voTemp->getUV());edkEnd();
                }

                //delete the vTemp
                delete vTemp;edkEnd();
                delete voTemp;edkEnd();
                //set vTemp the uvTemp
                vTemp=uvTemp;edkEnd();
                voTemp=uvoTemp;edkEnd();
                //set the vertex on the array
                this->vertexs.set(vertex,(edk::shape::Vertex2D*)vTemp);edkEnd();
                this->vertexsOriginal.set(vertex,(edk::shape::Vertex2D*)voTemp);edkEnd();
                //clean uvTemp
                uvTemp=NULL;edkEnd();
                uvoTemp=NULL;edkEnd();
            }
            else{
                //else return false
                return false;
            }
        }
        //set the frames
        vTemp->setUVFrames(frames);edkEnd();
        voTemp->setUVFrames(frames);edkEnd();

        if(false && !this->canUseVBO){
            this->canUseVBO=true;edkEnd();
            //set the NULL function into the vbo
            this->setVBOFunctionUpdateNULL();edkEnd();
        }

        this->updateVBOUV();

        //return true
        return true;
    }
    //else return false
    return false;
}

//function to create the VBO
bool edk::shape::Polygon2D::createVBO(edk::uint32 vertexCount,edk::shape::EDKVBOType type){
    //delete the last VBO
    this->deleteVBO();edkEnd();
    //
    if(this->canUseVBO && vertexCount){
        //create the new VBO
        if(type && type<edk::shape::vbo_Size){
            //create the vertexBuffer
            if(this->vertexBuffer.createArray(vertexCount * vboSizeof[type])){
                edk::uint32 increment = vboSizeof[type];
                edk::uint32 size = vertexCount * increment;
                //clean the vertexBuffer
                switch(type){
                case edk::shape::vbo_XY:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);
                    }
                    break;
                case edk::shape::vbo_XY_NxNyNz:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);

                        this->vertexBuffer.set(i+2u,0.f);
                        this->vertexBuffer.set(i+3u,0.f);
                        this->vertexBuffer.set(i+4u,1.f);
                    }
                    break;
                case edk::shape::vbo_XY_RGB:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);

                        this->vertexBuffer.set(i+2u,1.f);
                        this->vertexBuffer.set(i+3u,1.f);
                        this->vertexBuffer.set(i+4u,1.f);
                    }
                    break;
                case edk::shape::vbo_XY_RGBA:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);

                        this->vertexBuffer.set(i+2u,1.f);
                        this->vertexBuffer.set(i+3u,1.f);
                        this->vertexBuffer.set(i+4u,1.f);
                        this->vertexBuffer.set(i+5u,1.f);
                    }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz:
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
                case edk::shape::vbo_XY_RGBA_NxNyNz:
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
                case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
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
                case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
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
                case edk::shape::vbo_XYZ:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);
                        this->vertexBuffer.set(i+2u,0.f);
                    }
                    break;
                case edk::shape::vbo_XYZ_NxNyNz:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);
                        this->vertexBuffer.set(i+2u,0.f);

                        this->vertexBuffer.set(i+3u,0.f);
                        this->vertexBuffer.set(i+4u,0.f);
                        this->vertexBuffer.set(i+5u,1.f);
                    }
                    break;
                case edk::shape::vbo_XYZ_RGB:
                    for(edk::uint32 i=0u;i<size;i+=increment){
                        this->vertexBuffer.set(i,0.f);
                        this->vertexBuffer.set(i+1u,0.f);
                        this->vertexBuffer.set(i+2u,0.f);

                        this->vertexBuffer.set(i+3u,1.f);
                        this->vertexBuffer.set(i+4u,1.f);
                        this->vertexBuffer.set(i+5u,1.f);
                    }
                    break;
                case edk::shape::vbo_XYZ_RGBA:
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
                case edk::shape::vbo_XYZ_RGB_NxNyNz:
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
                case edk::shape::vbo_XYZ_RGBA_NxNyNz:
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
                case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
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
                case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
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
                this->vbo = edk::GU_GLSL::guAllocBuffer(GU_ARRAY_BUFFER);edkEnd();
                if(this->vbo){
                    if(edk::GU_GLSL::guBufferData(GU_ARRAY_BUFFER, this->vertexBuffer.getSize() * sizeof(edk::float32), this->vertexBuffer.getPointer(), GU_STATIC_DRAW)){
                        edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);edkEnd();
                        //save the type
                        this->vboType = type;edkEnd();
                        this->vboCount=vertexCount;edkEnd();

                        //update the VBO functions
                        this->setAutomaticallyVBOFunctions();

                        return true;
                    }
                    edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);edkEnd();

                    //else delete the bugger
                    edk::GU_GLSL::guDeleteBuffer(this->vbo);edkEnd();
                    this->vbo=0u;edkEnd();
                }
                //else delete the vertexBuffer
                this->vertexBuffer.clean();edkEnd();
            }
        }
    }
    return false;
}
//run the GU function to update the VBO
bool edk::shape::Polygon2D::updateVBO(){
    if(this->haveVBO() && this->vertexBuffer.getSize()){
        edk::GU_GLSL::guUseBuffer(GU_ARRAY_BUFFER,this->vbo);edkEnd();
        if(edk::GU_GLSL::guBufferData(GU_ARRAY_BUFFER, this->vertexBuffer.getSize() * sizeof(edk::float32), this->vertexBuffer.getPointer(), GU_STATIC_DRAW)){
            edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);edkEnd();
            return true;
        }
        edk::GU_GLSL::guDontUseBuffer(GU_ARRAY_BUFFER);edkEnd();
    }
    return false;
}
bool edk::shape::Polygon2D::changeVBO(edk::shape::EDKVBOType type){
    if(this->canUseVBO && type != this->vboType && type!=edk::shape::vbo_NULL && type<edk::shape::vbo_Size){
        edk::vector::Array<edk::float32> buffer;
        if(buffer.createArray(this->vboCount * vboSizeof[type])){
            edk::uint32 increment = vboSizeof[type];
            edk::uint32 size = this->vboCount*increment;
            //clean the vertexBuffer
            switch(type){
            case edk::shape::vbo_XY:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);
                }
                break;
            case edk::shape::vbo_XY_NxNyNz:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);

                    buffer.set(i+2u,0.f);
                    buffer.set(i+3u,0.f);
                    buffer.set(i+4u,1.f);
                }
                break;
            case edk::shape::vbo_XY_RGB:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);

                    buffer.set(i+2u,1.f);
                    buffer.set(i+3u,1.f);
                    buffer.set(i+4u,1.f);
                }
                break;
            case edk::shape::vbo_XY_RGBA:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);

                    buffer.set(i+2u,1.f);
                    buffer.set(i+3u,1.f);
                    buffer.set(i+4u,1.f);
                    buffer.set(i+5u,1.f);
                }
                break;
            case edk::shape::vbo_XY_RGB_NxNyNz:
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
            case edk::shape::vbo_XY_RGBA_NxNyNz:
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
            case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
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
            case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
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
            case edk::shape::vbo_XYZ:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);
                    buffer.set(i+2u,0.f);
                }
                break;
            case edk::shape::vbo_XYZ_NxNyNz:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);
                    buffer.set(i+2u,0.f);

                    buffer.set(i+3u,0.f);
                    buffer.set(i+4u,0.f);
                    buffer.set(i+5u,1.f);
                }
                break;
            case edk::shape::vbo_XYZ_RGB:
                for(edk::uint32 i=0u;i<size;i+=increment){
                    buffer.set(i,0.f);
                    buffer.set(i+1u,0.f);
                    buffer.set(i+2u,0.f);

                    buffer.set(i+3u,1.f);
                    buffer.set(i+4u,1.f);
                    buffer.set(i+5u,1.f);
                }
                break;
            case edk::shape::vbo_XYZ_RGBA:
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
            case edk::shape::vbo_XYZ_RGB_NxNyNz:
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
            case edk::shape::vbo_XYZ_RGBA_NxNyNz:
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
            case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
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
            case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
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
            case edk::shape::vbo_XY:
            {
                for(edk::uint32 i=0u;i<this->vboCount;i++){
                    buffer.set(dest,this->vertexBuffer.get(source));
                    buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                    source+=vboSizeof[this->vboType];
                    dest+=vboSizeof[type];
                }
            }
                break;
            case edk::shape::vbo_XY_NxNyNz:
            {
                switch(type){
                case edk::shape::vbo_XY:
                {
                    //vbo_XY_NxNyNz -> edk::shape::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB:
                {
                    //vbo_XY_NxNyNz -> edk::shape::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA:
                {
                    //vbo_XY_NxNyNz -> edk::shape::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz:
                {
                    //vbo_XY_NxNyNz -> edk::shape::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz:
                {
                    //vbo_XY_NxNyNz -> edk::shape::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //vbo_XY_NxNyNz -> edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //vbo_XY_NxNyNz -> edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ:
                {
                    //vbo_XY_NxNyNz -> edk::shape::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_NxNyNz:
                {
                    //vbo_XY_NxNyNz -> edk::shape::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB:
                {
                    //vbo_XY_NxNyNz -> edk::shape::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA:
                {
                    //vbo_XY_NxNyNz -> edk::shape::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz:
                {
                    //vbo_XY_NxNyNz -> edk::shape::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz:
                {
                    //vbo_XY_NxNyNz -> edk::shape::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //vbo_XY_NxNyNz -> edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //vbo_XY_NxNyNz -> edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::shape::vbo_XY_RGB:
            {
                switch(type){
                case edk::shape::vbo_XY:
                {
                    //edk::shape::vbo_XY_RGB -> edk::shape::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGB -> edk::shape::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA:
                {
                    //edk::shape::vbo_XY_RGB -> edk::shape::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGB -> edk::shape::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGB -> edk::shape::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGB -> edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGB -> edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ:
                {
                    //edk::shape::vbo_XY_RGB -> edk::shape::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGB -> edk::shape::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB:
                {
                    //edk::shape::vbo_XY_RGB -> edk::shape::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA:
                {
                    //edk::shape::vbo_XY_RGB -> edk::shape::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGB -> edk::shape::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGB -> edk::shape::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGB -> edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGB -> edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::shape::vbo_XY_RGBA:
            {
                switch(type){
                case edk::shape::vbo_XY:
                {
                    //edk::shape::vbo_XY_RGBA -> edk::shape::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGBA -> edk::shape::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB:
                {
                    //edk::shape::vbo_XY_RGBA -> edk::shape::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGBA -> edk::shape::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGBA -> edk::shape::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGBA -> edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGBA -> edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ:
                {
                    //edk::shape::vbo_XY_RGBA -> edk::shape::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGBA -> edk::shape::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB:
                {
                    //edk::shape::vbo_XY_RGBA -> edk::shape::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA:
                {
                    //edk::shape::vbo_XY_RGBA -> edk::shape::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGBA -> edk::shape::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGBA -> edk::shape::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGBA -> edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGBA -> edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::shape::vbo_XY_RGB_NxNyNz:
            {
                switch(type){
                case edk::shape::vbo_XY:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz -> edk::shape::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz -> edk::shape::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz -> edk::shape::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz -> edk::shape::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz -> edk::shape::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz -> edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz -> edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz -> edk::shape::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz -> edk::shape::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz -> edk::shape::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz -> edk::shape::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz -> edk::shape::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz -> edk::shape::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz -> edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz -> edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::shape::vbo_XY_RGBA_NxNyNz:
            {
                switch(type){
                case edk::shape::vbo_XY:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz -> edk::shape::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz -> edk::shape::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz -> edk::shape::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz -> edk::shape::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz -> edk::shape::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz -> edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz -> edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz -> edk::shape::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz -> edk::shape::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz -> edk::shape::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz -> edk::shape::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz -> edk::shape::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz -> edk::shape::vbo_XYZ_RGBA_NxNyNz
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz -> edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz -> edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
            {
                switch(type){
                case edk::shape::vbo_XY:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+7u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
            {
                switch(type){
                case edk::shape::vbo_XY:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGBA_NxNyNz
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+2u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+4u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGBA_NxNyNz
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::shape::vbo_XYZ:
            {
                switch(type){
                case edk::shape::vbo_XY:
                {
                    //edk::shape::vbo_XYZ -> edk::shape::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_NxNyNz:
                {
                    //edk::shape::vbo_XYZ -> edk::shape::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB:
                {
                    //edk::shape::vbo_XYZ -> edk::shape::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA:
                {
                    //edk::shape::vbo_XYZ -> edk::shape::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XYZ -> edk::shape::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XYZ -> edk::shape::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));


                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ -> edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ -> edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_NxNyNz:
                {
                    //edk::shape::vbo_XYZ -> edk::shape::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB:
                {
                    //edk::shape::vbo_XYZ -> edk::shape::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA:
                {
                    //edk::shape::vbo_XYZ -> edk::shape::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XYZ -> edk::shape::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XYZ -> edk::shape::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ -> edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ -> edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::shape::vbo_XYZ_NxNyNz:
            {
                switch(type){
                case edk::shape::vbo_XY:
                {
                    //edk::shape::vbo_XYZ_NxNyNz -> edk::shape::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_NxNyNz -> edk::shape::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB:
                {
                    //edk::shape::vbo_XYZ_NxNyNz -> edk::shape::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA:
                {
                    //edk::shape::vbo_XYZ_NxNyNz -> edk::shape::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_NxNyNz -> edk::shape::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_NxNyNz -> edk::shape::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_NxNyNz -> edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_NxNyNz -> edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ:
                {
                    //edk::shape::vbo_XYZ_NxNyNz -> edk::shape::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB:
                {
                    //edk::shape::vbo_XYZ_NxNyNz -> edk::shape::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA:
                {
                    //edk::shape::vbo_XYZ_NxNyNz -> edk::shape::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_NxNyNz -> edk::shape::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_NxNyNz -> edk::shape::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_NxNyNz -> edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_NxNyNz -> edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+7u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+9u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::shape::vbo_XYZ_RGB:
            {
                switch(type){
                case edk::shape::vbo_XY:
                {
                    //edk::shape::vbo_XYZ_RGB -> edk::shape::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGB -> edk::shape::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB:
                {
                    //edk::shape::vbo_XYZ_RGB -> edk::shape::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA:
                {
                    //edk::shape::vbo_XYZ_RGB -> edk::shape::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGB -> edk::shape::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGB -> edk::shape::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGB -> edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGB -> edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ:
                {
                    //edk::shape::vbo_XYZ_RGB -> edk::shape::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGB -> edk::shape::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA:
                {
                    //edk::shape::vbo_XYZ_RGB -> edk::shape::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGB -> edk::shape::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGB -> edk::shape::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));


                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGB -> edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGB -> edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::shape::vbo_XYZ_RGBA:
            {
                switch(type){
                case edk::shape::vbo_XY:
                {
                    //edk::shape::vbo_XYZ_RGBA -> edk::shape::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGBA -> edk::shape::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB:
                {
                    //edk::shape::vbo_XYZ_RGBA -> edk::shape::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA:
                {
                    //edk::shape::vbo_XYZ_RGBA -> edk::shape::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGBA -> edk::shape::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGBA -> edk::shape::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGBA -> edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGBA -> edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ:
                {
                    //edk::shape::vbo_XYZ_RGBA -> edk::shape::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGBA -> edk::shape::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB:
                {
                    //edk::shape::vbo_XYZ_RGBA -> edk::shape::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGBA -> edk::shape::vbo_XYZ_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGBA -> edk::shape::vbo_XYZ_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGBA -> edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGBA -> edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::shape::vbo_XYZ_RGB_NxNyNz:
            {
                switch(type){
                case edk::shape::vbo_XY:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz -> edk::shape::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz -> edk::shape::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz -> edk::shape::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz -> edk::shape::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz -> edk::shape::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz -> edk::shape::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz -> edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz -> edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz -> edk::shape::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz -> edk::shape::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz -> edk::shape::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz -> edk::shape::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz -> edk::shape::vbo_XYZ_RGBA_NxNyNz
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz -> edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz -> edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::shape::vbo_XYZ_RGBA_NxNyNz:
            {
                switch(type){
                case edk::shape::vbo_XY:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz -> edk::shape::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz -> edk::shape::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz -> edk::shape::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz -> edk::shape::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz -> edk::shape::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz -> edk::shape::vbo_XY_RGBA_NxNyNz
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz -> edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz -> edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz -> edk::shape::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz -> edk::shape::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz -> edk::shape::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz -> edk::shape::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz -> edk::shape::vbo_XYZ_RGB_NxNyNz
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz -> edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz -> edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            {
                switch(type){
                case edk::shape::vbo_XY:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGBA_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+8u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy
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
                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+6u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+8u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGB_NxNyNz
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGBA_NxNyNz
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                default:
                    break;
                }
            }
                break;
            case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            {
                switch(type){
                case edk::shape::vbo_XY:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XY
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XY_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+6u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGB_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));

                        buffer.set(dest+2u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+3u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+5u));

                        buffer.set(dest+5u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+7u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGBA_NxNyNz
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_NxNyNz
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+7u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+8u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+9u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGB
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGBA
                    for(edk::uint32 i=0u;i<this->vboCount;i++){
                        buffer.set(dest,this->vertexBuffer.get(source));
                        buffer.set(dest+1u,this->vertexBuffer.get(source+1u));
                        buffer.set(dest+2u,this->vertexBuffer.get(source+2u));

                        buffer.set(dest+3u,this->vertexBuffer.get(source+3u));
                        buffer.set(dest+4u,this->vertexBuffer.get(source+4u));
                        buffer.set(dest+5u,this->vertexBuffer.get(source+5u));
                        buffer.set(dest+6u,this->vertexBuffer.get(source+6u));

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGB_NxNyNz
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGBA_NxNyNz:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGBA_NxNyNz
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
                    }
                }
                    break;
                case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                {
                    //edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy -> edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy
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

                        source+=vboSizeof[this->vboType];
                        dest+=vboSizeof[type];
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
        edk::GU_GLSL::guDeleteBuffer(this->vbo);edkEnd();
        this->vbo=0u;edkEnd();
    }
    if(this->vertexBuffer.size()){
        this->vertexBuffer.deleteArray();edkEnd();
    }
    this->vboType = edk::shape::vbo_NULL;edkEnd();
    this->vboCount=0u;edkEnd();
}
bool edk::shape::Polygon2D::haveVBO(){
    return (bool)(this->canUseVBO && this->vbo);
}
//set the vboFunction pointers
bool edk::shape::Polygon2D::updateVBOFunctions(){
    if(this->haveVBO()){
        switch(this->vboType){
        case edk::shape::vbo_XY:
            this->vboPrint = &edk::shape::Polygon2D::print_XY;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XY;
            break;
        case edk::shape::vbo_XY_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XY_NxNyNz;
            break;
        case edk::shape::vbo_XY_RGB:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGB;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XY_RGB;
            break;
        case edk::shape::vbo_XY_RGBA:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGBA;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XY_RGBA;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGB_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XY_RGB_NxNyNz;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGBA_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XY_RGBA_NxNyNz;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGB_NxNyNz_UVxUVy;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XY_RGB_NxNyNz_UVxUVy;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGBA_NxNyNz_UVxUVy;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XY_RGBA_NxNyNz_UVxUVy;
            break;
        case edk::shape::vbo_XYZ:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XYZ;
            break;
        case edk::shape::vbo_XYZ_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XYZ_NxNyNz;
            break;
        case edk::shape::vbo_XYZ_RGB:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGB;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XYZ_RGB;
            break;
        case edk::shape::vbo_XYZ_RGBA:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGBA;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XYZ_RGBA;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGB_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XYZ_RGB_NxNyNz;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGBA_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XYZ_RGBA_NxNyNz;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGB_NxNyNz_UVxUVy;
            this->vboDraw = &edk::shape::Polygon2D::drawUpdate_XYZ_RGB_NxNyNz_UVxUVy;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
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
        case edk::shape::vbo_XY:
            this->vboPrint = &edk::shape::Polygon2D::print_XY;
            this->vboDraw = &edk::shape::Polygon2D::draw_XY;
            break;
        case edk::shape::vbo_XY_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::draw_XY_NxNyNz;
            break;
        case edk::shape::vbo_XY_RGB:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGB;
            this->vboDraw = &edk::shape::Polygon2D::draw_XY_RGB;
            break;
        case edk::shape::vbo_XY_RGBA:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGBA;
            this->vboDraw = &edk::shape::Polygon2D::draw_XY_RGBA;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGB_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::draw_XY_RGB_NxNyNz;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGBA_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::draw_XY_RGBA_NxNyNz;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGB_NxNyNz_UVxUVy;
            this->vboDraw = &edk::shape::Polygon2D::draw_XY_RGB_NxNyNz_UVxUVy;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
            this->vboPrint = &edk::shape::Polygon2D::print_XY_RGBA_NxNyNz_UVxUVy;
            this->vboDraw = &edk::shape::Polygon2D::draw_XY_RGBA_NxNyNz_UVxUVy;
            break;
        case edk::shape::vbo_XYZ:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ;
            this->vboDraw = &edk::shape::Polygon2D::draw_XYZ;
            break;
        case edk::shape::vbo_XYZ_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_NxNyNz;
            break;
        case edk::shape::vbo_XYZ_RGB:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGB;
            this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_RGB;
            break;
        case edk::shape::vbo_XYZ_RGBA:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGBA;
            this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_RGBA;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGB_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_RGB_NxNyNz;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGBA_NxNyNz;
            this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_RGBA_NxNyNz;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            this->vboPrint = &edk::shape::Polygon2D::print_XYZ_RGB_NxNyNz_UVxUVy;
            this->vboDraw = &edk::shape::Polygon2D::draw_XYZ_RGB_NxNyNz_UVxUVy;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
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
        vertex *= vboSizeof[this->vboType];
        //switch(this->vboType){
        //case edk::shape::vbo_XY:
        //    break;
        //case edk::shape::vbo_XY_NxNyNz:
        //    break;
        //case edk::shape::vbo_XY_RGB:
        //    break;
        //case edk::shape::vbo_XY_RGBA:
        //    break;
        //case edk::shape::vbo_XY_RGB_NxNyNz:
        //    break;
        //case edk::shape::vbo_XY_RGBA_NxNyNz:
        //    break;
        //case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
        //    break;
        //case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
        //    break;
        //case edk::shape::vbo_XYZ:
        //    break;
        //case edk::shape::vbo_XYZ_NxNyNz:
        //    break;
        //case edk::shape::vbo_XYZ_RGB:
        //    break;
        //case edk::shape::vbo_XYZ_RGBA:
        //    break;
        //case edk::shape::vbo_XYZ_RGB_NxNy:
        //    break;
        //case edk::shape::vbo_XYZ_RGBA_NxNy:
        //    break;
        //case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
        //    break;
        //case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
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
        vertex *= vboSizeof[this->vboType];
        //switch(this->vboType){
        //case edk::shape::vbo_XY:
        //    break;
        //case edk::shape::vbo_XY_NxNyNz:
        //    break;
        //case edk::shape::vbo_XY_RGB:
        //    break;
        //case edk::shape::vbo_XY_RGBA:
        //    break;
        //case edk::shape::vbo_XY_RGB_NxNyNz:
        //    break;
        //case edk::shape::vbo_XY_RGBA_NxNyNz:
        //    break;
        //case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
        //    break;
        //case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
        //    break;
        //case edk::shape::vbo_XYZ:
        //    break;
        //case edk::shape::vbo_XYZ_NxNyNz:
        //    break;
        //case edk::shape::vbo_XYZ_RGB:
        //    break;
        //case edk::shape::vbo_XYZ_RGBA:
        //    break;
        //case edk::shape::vbo_XYZ_RGB_NxNy:
        //    break;
        //case edk::shape::vbo_XYZ_RGBA_NxNy:
        //    break;
        //case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
        //    break;
        //case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
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
        vertex *= vboSizeof[this->vboType];
        //switch(this->vboType){
        //case edk::shape::vbo_XY:
        //    break;
        //case edk::shape::vbo_XY_NxNyNz:
        //    break;
        //case edk::shape::vbo_XY_RGB:
        //    break;
        //case edk::shape::vbo_XY_RGBA:
        //    break;
        //case edk::shape::vbo_XY_RGB_NxNyNz:
        //    break;
        //case edk::shape::vbo_XY_RGBA_NxNyNz:
        //    break;
        //case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
        //    break;
        //case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
        //    break;
        //case edk::shape::vbo_XYZ:
        //    break;
        //case edk::shape::vbo_XYZ_NxNyNz:
        //    break;
        //case edk::shape::vbo_XYZ_RGB:
        //    break;
        //case edk::shape::vbo_XYZ_RGBA:
        //    break;
        //case edk::shape::vbo_XYZ_RGB_NxNy:
        //    break;
        //case edk::shape::vbo_XYZ_RGBA_NxNy:
        //    break;
        //case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
        //    break;
        //case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
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
        case edk::shape::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
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
        case edk::shape::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
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
        case edk::shape::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
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
        case edk::shape::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 7u;
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
        case edk::shape::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 3u;
            break;
        case edk::shape::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 3u;
            break;
        case edk::shape::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 3u;
            break;
        case edk::shape::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 3u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 3u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 3u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 3u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 3u;
            break;
        case edk::shape::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 3u;
            break;
        case edk::shape::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 3u;
            break;
        case edk::shape::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 3u;
            break;
        case edk::shape::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 3u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 3u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 3u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 3u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 3u;
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
        case edk::shape::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            position = 3u;
            break;
        default:
            break;
        }
        edk::uint8 increment = vboSizeof[this->vboType];
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
        case edk::shape::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::shape::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::shape::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::shape::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::shape::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::shape::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::shape::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::shape::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            position = 7u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 7u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            position = 7u;
            break;
        default:
            break;
        }
        edk::uint8 increment = vboSizeof[this->vboType];
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
        case edk::shape::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            position = 3u;
            break;
        default:
            break;
        }
        edk::uint8 increment = vboSizeof[this->vboType];
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
        case edk::shape::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            position = 3u;
            break;
        default:
            break;
        }
        edk::uint8 increment = vboSizeof[this->vboType];
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
        case edk::shape::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            position = 3u;
            break;
        default:
            break;
        }
        edk::uint8 increment = vboSizeof[this->vboType];
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
        case edk::shape::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz:
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            position = 3u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            position = 3u;
            break;
        default:
            break;
        }
        edk::uint8 increment = vboSizeof[this->vboType];
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
        case edk::shape::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
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
        case edk::shape::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
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
        case edk::shape::vbo_XY:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 9u;
            break;
        case edk::shape::vbo_XYZ:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_RGB:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_RGBA:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            //change the vertexBuffer
            this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
            //calculate the vertex position
            vertex = (vertex * vboSizeof[this->vboType]) + 10u;
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
            case edk::shape::vbo_XY:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 9u;
                break;
            case edk::shape::vbo_XY_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 9u;
                break;
            case edk::shape::vbo_XY_RGB:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 9u;
                break;
            case edk::shape::vbo_XY_RGBA:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 9u;
                break;
            case edk::shape::vbo_XY_RGB_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 9u;
                break;
            case edk::shape::vbo_XY_RGBA_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 9u;
                break;
            case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 9u;
                break;
            case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 9u;
                break;
            case edk::shape::vbo_XYZ:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 10u;
                break;
            case edk::shape::vbo_XYZ_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 10u;
                break;
            case edk::shape::vbo_XYZ_RGB:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 10u;
                break;
            case edk::shape::vbo_XYZ_RGBA:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 10u;
                break;
            case edk::shape::vbo_XYZ_RGB_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 10u;
                break;
            case edk::shape::vbo_XYZ_RGBA_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 10u;
                break;
            case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 10u;
                break;
            case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                //calculate the vertex position
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 10u;
                break;
            default:
                break;
            }

            vTemp = (edk::shape::Vertex2DWithUV*)this->vertexs.get(i);edkEnd();
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
            case edk::shape::vbo_XY:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeof[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeof[this->vboType]) + 2u;
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 9u;
                break;
            case edk::shape::vbo_XY_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeof[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeof[this->vboType]) + 2u;
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 9u;
                break;
            case edk::shape::vbo_XY_RGB:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeof[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeof[this->vboType]) + 2u;
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 9u;
                break;
            case edk::shape::vbo_XY_RGBA:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeof[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeof[this->vboType]) + 2u;
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 9u;
                break;
            case edk::shape::vbo_XY_RGB_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeof[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeof[this->vboType]) + 2u;
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 9u;
                break;
            case edk::shape::vbo_XY_RGBA_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeof[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeof[this->vboType]) + 2u;
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 9u;
                break;
            case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeof[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeof[this->vboType]) + 2u;
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 9u;
                break;
            case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeof[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeof[this->vboType]) + 2u;
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 9u;
                break;
            case edk::shape::vbo_XYZ:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeof[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeof[this->vboType]) + 3u;
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 10u;
                break;
            case edk::shape::vbo_XYZ_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeof[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeof[this->vboType]) + 3u;
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 10u;
                break;
            case edk::shape::vbo_XYZ_RGB:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeof[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeof[this->vboType]) + 3u;
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 10u;
                break;
            case edk::shape::vbo_XYZ_RGBA:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeof[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeof[this->vboType]) + 3u;
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 10u;
                break;
            case edk::shape::vbo_XYZ_RGB_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeof[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeof[this->vboType]) + 3u;
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 10u;
                break;
            case edk::shape::vbo_XYZ_RGBA_NxNyNz:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeof[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeof[this->vboType]) + 3u;
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 10u;
                break;
            case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
                //change the vertexBuffer
                this->changeVBO(edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy);
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeof[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeof[this->vboType]) + 3u;
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 10u;
                break;
            case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
                //calculate the vertex position
                vertexPosition = (vertexPosition * vboSizeof[this->vboType]) + 0u;
                vertexColor = (vertexColor * vboSizeof[this->vboType]) + 3u;
                vertexUV = (vertexUV * vboSizeof[this->vboType]) + 10u;
                break;
            default:
                break;
            }
            vTemp = (edk::shape::Vertex2DWithUV*)this->vertexs.get(i);edkEnd();
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
        edk::uint32 increment=vboSizeof[this->vboType];
        //test if need change the buffer
        switch(this->vboType){
        case edk::shape::vbo_XY:
            printf("\nvbo_XY");
            break;
        case edk::shape::vbo_XY_NxNyNz:
            printf("\nvbo_XY_NxNyNz");
            break;
        case edk::shape::vbo_XY_RGB:
            printf("\nvbo_XY_RGB");
            break;
        case edk::shape::vbo_XY_RGBA:
            printf("\nvbo_XY_RGBA");
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz:
            printf("\nvbo_XY_RGB_NxNyNz");
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz:
            printf("\nvbo_XY_RGBA_NxNyNz");
            break;
        case edk::shape::vbo_XY_RGB_NxNyNz_UVxUVy:
            printf("\nvbo_XY_RGB_NxNyNz_UVxUVy");
            break;
        case edk::shape::vbo_XY_RGBA_NxNyNz_UVxUVy:
            printf("\nvbo_XY_RGBA_NxNyNz_UVxUVy");
            break;
        case edk::shape::vbo_XYZ:
            printf("\nvbo_XYZ");
            break;
        case edk::shape::vbo_XYZ_NxNyNz:
            printf("\nvbo_XYZ_NxNyNz");
            break;
        case edk::shape::vbo_XYZ_RGB:
            printf("\nvbo_XYZ_RGB");
            break;
        case edk::shape::vbo_XYZ_RGBA:
            printf("\nvbo_XYZ_RGBA");
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz:
            printf("\nvbo_XYZ_RGB_NxNyNz");
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz:
            printf("\nvbo_XYZ_RGBA_NxNyNz");
            break;
        case edk::shape::vbo_XYZ_RGB_NxNyNz_UVxUVy:
            printf("\nvbo_XYZ_RGB_NxNyNz_UVxUVy");
            break;
        case edk::shape::vbo_XYZ_RGBA_NxNyNz_UVxUVy:
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
        if(vertexs.get(i)){
            vertexs.get(i)->draw();edkEnd();
        }
    }
}
void edk::shape::Polygon2D::drawVertexsWithColor(edk::color4f32 color){
    //
    for(edk::uint32 i=0u;i<this->getVertexCount();i++){
        //
        if(vertexs.get(i)){
            vertexs.get(i)->drawWithColor(color);edkEnd();
        }
    }
}
//update framesSize
void edk::shape::Polygon2D::updateFramesSize(){
    //
    this->framesSize = this->frames.x * this->frames.y;edkEnd();
}
//test if is tranforming the polygon
void edk::shape::Polygon2D::testTransform(){
    if(this->translate.x!=0.f
            &&
            this->translate.y!=0.f
            &&
            this->angle
            &&
            this->scale.width!=1.f
            &&
            this->scale.height!=1.f
            ){
        //
        this->transforming=true;edkEnd();
    }
    this->transforming=false;edkEnd();
}

//draw functions
//PRINT
void edk::shape::Polygon2D::print_NULL(){
    //
    for(edk::uint32 i=0u;i<this->getVertexCount();i++){
        //
        if(vertexs.get(i)){
            vertexs.get(i)->print(i);edkEnd();
        }
    }
}
void edk::shape::Polygon2D::print_XY(){
    edk::uint8 increment = vboSizeof[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)
               );edkEnd();
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XYZ(){
    edk::uint8 increment = vboSizeof[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)
               ,this->vertexBuffer.getNoIF(position+2u)
               );edkEnd();
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XY_NxNyNz(){
    edk::uint8 increment = vboSizeof[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f) normal(%.2f %.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)

               ,this->vertexBuffer.getNoIF(position+2u)
               ,this->vertexBuffer.getNoIF(position+3u)
               ,this->vertexBuffer.getNoIF(position+4u)
               );edkEnd();
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XYZ_NxNyNz(){
    edk::uint8 increment = vboSizeof[this->vboType];
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
               );edkEnd();
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XY_RGB(){
    edk::uint8 increment = vboSizeof[this->vboType];
    edk::uint32 position = 0u;
    for(edk::uint32 i=0u;i<this->vboCount;i++){
        printf("\nVector [%u] position(%.2f %.2f) Color (%.2f %.2f %.2f)"
               ,i
               ,this->vertexBuffer.getNoIF(position)
               ,this->vertexBuffer.getNoIF(position+1u)

               ,this->vertexBuffer.getNoIF(position+2u)
               ,this->vertexBuffer.getNoIF(position+3u)
               ,this->vertexBuffer.getNoIF(position+4u)
               );edkEnd();
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XYZ_RGB(){
    edk::uint8 increment = vboSizeof[this->vboType];
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
               );edkEnd();
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XY_RGBA(){
    edk::uint8 increment = vboSizeof[this->vboType];
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
               );edkEnd();
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XYZ_RGBA(){
    edk::uint8 increment = vboSizeof[this->vboType];
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
               );edkEnd();
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XY_RGB_NxNyNz(){
    edk::uint8 increment = vboSizeof[this->vboType];
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
               );edkEnd();
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XYZ_RGB_NxNyNz(){
    edk::uint8 increment = vboSizeof[this->vboType];
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
               );edkEnd();
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XY_RGBA_NxNyNz(){
    edk::uint8 increment = vboSizeof[this->vboType];
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
               );edkEnd();
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XYZ_RGBA_NxNyNz(){
    edk::uint8 increment = vboSizeof[this->vboType];
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
               );edkEnd();
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XY_RGB_NxNyNz_UVxUVy(){
    edk::uint8 increment = vboSizeof[this->vboType];
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
               );edkEnd();
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XYZ_RGB_NxNyNz_UVxUVy(){
    edk::uint8 increment = vboSizeof[this->vboType];
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
               );edkEnd();
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XY_RGBA_NxNyNz_UVxUVy(){
    edk::uint8 increment = vboSizeof[this->vboType];
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
               );edkEnd();
        position+=increment;
    }fflush(stdout);
}
void edk::shape::Polygon2D::print_XYZ_RGBA_NxNyNz_UVxUVy(){
    edk::uint8 increment = vboSizeof[this->vboType];
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
               );edkEnd();
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
    edk::GU::guBegin(mode);edkEnd();
    this->drawVertexs();edkEnd();
    edk::GU::guEnd();edkEnd();
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
    edk::GU::guBegin(mode);edkEnd();
    this->drawVertexs();edkEnd();
    edk::GU::guEnd();edkEnd();
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
        return this->vertexs.get(vertex);edkEnd();
    }
    //else return NULL
    return NULL;
}
edk::shape::Vertex2D* edk::shape::Polygon2D::getVertexOriginalPointer(edk::uint32 vertex){
    //test if have the vertex
    if(vertex<this->getVertexCount()){
        //then return the vertex
        return this->vertexsOriginal.get(vertex);edkEnd();
    }
    //else return NULL
    return NULL;
}

//create the polygon
bool edk::shape::Polygon2D::createPolygon(edk::uint32 vertexCount){
    //delete the polygon
    this->deletePolygon();edkEnd();
    bool ret = false;
    //test the vertexCount
    if(vertexCount >= minimumVertex){
        //create the array
        if(this->vertexsOriginal.createArray(vertexCount)){
            if(this->vertexs.createArray(vertexCount)){
                //create all the vertexs
                for(edk::uint32 i =0u;i<vertexCount;i++){
                    //
                    this->vertexs.set(i,new edk::shape::Vertex2D());edkEnd();
                    this->vertexsOriginal.set(i,new edk::shape::Vertex2D());edkEnd();
                    //Set alpha 1
                    if(this->vertexs.get(i)){
                        //set the vertex
                        this->vertexs.get(i)->color = this->polygonColor;edkEnd();
                    }
                    if(this->vertexsOriginal.get(i)){
                        //set the vertex
                        this->vertexsOriginal.get(i)->color = this->polygonColor;edkEnd();
                    }
                }
                //set can delete the polygon in the future
                this->canDeletePolygon=true;edkEnd();

                //then return true
                ret = true;
            }
            else{
                this->vertexsOriginal.deleteArray();edkEnd();
            }
        }

        //create the VBO.
        if(ret){
            this->createVBO(vertexCount,edk::shape::vbo_XYZ_RGBA);
        }
    }
    return ret;
}

//test if the polygon is Counterclockwise
bool edk::shape::Polygon2D::isCounterclockwise(){
    //test the polygon size
    if(this->getVertexCount()>=3){
        //test the vertex angles
        edk::float32 angle1 = edk::Math::getAngle(this->vertexs.get(1u)->position - this->vertexs.get(0u)->position);edkEnd();
        edk::float32 angle2;edkEnd();
        edk::float32 angleTemp;edkEnd();
        for(register edk::uint32 i=2u;i<this->vertexs.size();i++){
            //get the next angle
            angle2 = edk::Math::getAngle(this->vertexs.get(i)->position - this->vertexs.get(0u)->position);edkEnd();
            angleTemp = angle2 - angle1;edkEnd();
            if(angleTemp>180.f || (angleTemp<0.f && angleTemp>-180.f)){
                //it's not counterClockwise
                return false;
            }
            angle1=angle2;edkEnd();
        }
        return true;
    }
    return false;
}

//SETTERS
//set the position of a vertex
bool edk::shape::Polygon2D::setVertexPosition(edk::uint32 vertex,edk::vec2f32 position){
    bool ret=false;
    //load the polygon
    edk::shape::Vertex2D* vTemp = this->getVertexPointer(vertex);edkEnd();
    edk::shape::Vertex2D* voTemp = this->getVertexOriginalPointer(vertex);edkEnd();
    if(vTemp && voTemp){
        //then set the position of the vertex
        vTemp->position = position;edkEnd();
        voTemp->position = position;edkEnd();
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
    return this->setVertexPosition(vertex,edk::vec2f32(x,y));edkEnd();
}
//set the color of a vertex
bool edk::shape::Polygon2D::setVertexColor(edk::uint32 vertex,edk::color4f32 color){
    bool ret=false;
    //load the polygon
    edk::shape::Vertex2D* vTemp = this->getVertexPointer(vertex);edkEnd();
    edk::shape::Vertex2D* voTemp = this->getVertexOriginalPointer(vertex);edkEnd();
    if(vTemp && voTemp){
        //then set the position of the vertex
        vTemp->color = color;edkEnd();
        voTemp->color = color;edkEnd();
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
    return this->setVertexColor(vertex,edk::color4f32(r,g,b,1.0f));edkEnd();
}
bool edk::shape::Polygon2D::setVertexColor(edk::uint32 vertex,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //
    return this->setVertexColor(vertex,edk::color4f32(r,g,b,a));edkEnd();
}
//Set polygon color
bool edk::shape::Polygon2D::setPolygonColor(edk::color4f32 color){
    bool ret = false;
    //first set the polygonColor
    this->polygonColor = edk::color4f32(color);edkEnd();
    if(this->getVertexCount()){
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->getVertexCount();i++){
            //set the color
            this->vertexs.get(i)->color = this->polygonColor;edkEnd();
            this->vertexsOriginal.get(i)->color = this->polygonColor;edkEnd();
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
    return this->setPolygonColor(edk::color4f32 (color.r,color.g,color.b,1.f));edkEnd();
}
bool edk::shape::Polygon2D::setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b){
    //
    return this->setPolygonColor(edk::color4f32 (r,g,b,1.f));edkEnd();
}
bool edk::shape::Polygon2D::setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //
    return this->setPolygonColor(edk::color4f32 (r,g,b,a));edkEnd();
}
bool edk::shape::Polygon2D::setPolygonColorR(edk::float32 r){
    bool ret=false;
    //first set the polygonColor
    this->polygonColor.r = r;edkEnd();
    if(this->getVertexCount()){
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->getVertexCount();i++){
            //set the color
            this->vertexs.get(i)->color.r = this->polygonColor.r;edkEnd();
            this->vertexsOriginal.get(i)->color.r = this->polygonColor.r;edkEnd();
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
    this->polygonColor.g = g;edkEnd();
    if(this->getVertexCount()){
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->getVertexCount();i++){
            //set the color
            this->vertexs.get(i)->color.g = this->polygonColor.g;edkEnd();
            this->vertexsOriginal.get(i)->color.g = this->polygonColor.g;edkEnd();
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
    this->polygonColor.b = b;edkEnd();
    if(this->getVertexCount()){
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->getVertexCount();i++){
            //set the color
            this->vertexs.get(i)->color.b = this->polygonColor.b;edkEnd();
            this->vertexsOriginal.get(i)->color.b = this->polygonColor.b;edkEnd();
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
    this->polygonColor.a = a;edkEnd();
    if(this->getVertexCount()){
        //set the color of the vertexPolygons
        for(edk::uint32 i=0u;i<this->getVertexCount();i++){
            //set the color
            this->vertexs.get(i)->color.a = this->polygonColor.a;edkEnd();
            this->vertexsOriginal.get(i)->color.a = this->polygonColor.a;edkEnd();
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
    this->frameUsing=edk::vec2ui32(0u,0u);edkEnd();
    //load the polygon
    edk::shape::Vertex2DWithUV* vTemp = (edk::shape::Vertex2DWithUV*)this->getVertexPointer(vertex);edkEnd();
    edk::shape::Vertex2DWithUV* voTemp = (edk::shape::Vertex2DWithUV*)this->getVertexOriginalPointer(vertex);edkEnd();
    if(vTemp && voTemp){
        //test what type of vertex it is
        if(vTemp->getType() == EDK_SHAPE_NOUV
                || voTemp->getType() == EDK_SHAPE_NOUV
                ){
            //then delete the vTemp and create another with UV
            edk::shape::Vertex2DWithUV* uvTemp = new edk::shape::Vertex2DWithUV();edkEnd();
            edk::shape::Vertex2DWithUV* uvoTemp = new edk::shape::Vertex2DWithUV();edkEnd();
            if(uvTemp && uvoTemp){
                //copy the vTemp content to uvTemp
                uvTemp->position = vTemp->position;edkEnd();
                uvTemp->color = vTemp->color;edkEnd();
                uvoTemp->position = vTemp->position;edkEnd();
                uvoTemp->color = vTemp->color;edkEnd();

                //delete the vTemp
                delete vTemp;edkEnd();
                delete voTemp;edkEnd();
                //set vTemp the uvTemp
                vTemp=uvTemp;edkEnd();
                voTemp=uvoTemp;edkEnd();
                //set the vertex on the array
                this->vertexs.set(vertex,(edk::shape::Vertex2D*)vTemp);edkEnd();
                this->vertexsOriginal.set(vertex,(edk::shape::Vertex2D*)voTemp);edkEnd();
                //clean uvTemp
                uvTemp=NULL;edkEnd();
                uvoTemp=NULL;edkEnd();
                //set the uv
                vTemp->setUV(uv);edkEnd();
                voTemp->setUV(uv);edkEnd();
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
            edk::shape::Vertex2DAnimatedUV* vTemp2 = (edk::shape::Vertex2DAnimatedUV*)vTemp;edkEnd();
            edk::shape::Vertex2DAnimatedUV* voTemp2 = (edk::shape::Vertex2DAnimatedUV*)voTemp;edkEnd();
            vTemp2->setUV(uv);edkEnd();
            voTemp2->setUV(uv);edkEnd();
            ret = true;
        }
        else{
            //set the uv
            vTemp->setUV(uv);edkEnd();
            voTemp->setUV(uv);edkEnd();
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
    return this->setVertexUV(vertex,edk::vec2f32(x,y));edkEnd();
}
//Set the polygonFrames
bool edk::shape::Polygon2D::setPolygonUVFrames(edk::vec2ui32 frames){
    this->frameUsing=edk::vec2ui32(0u,0u);edkEnd();
    //test the frames
    if(frames.x && frames.y){
        //save the frames
        this->frames=frames;edkEnd();
        //set the frames on vertex
        for(edk::uint32 i=0u;i<this->vertexs.size();i++){
            //
            this->setVertexUVFrames(i,frames);edkEnd();
        }
        this->updateFramesSize();edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}
bool edk::shape::Polygon2D::setPolygonUVFrames(edk::uint32 x,edk::uint32 y){
    //
    return this->setPolygonUVFrames(edk::vec2ui32(x,y));edkEnd();
}
bool edk::shape::Polygon2D::setPolygonUVFramesX(edk::uint32 x){
    //
    if(x){
        this->frames.x=x;edkEnd();
    }
    return this->setPolygonUVFrames(edk::vec2ui32(x,
                                                  this->frames.y
                                                  )
                                    );edkEnd();
}
bool edk::shape::Polygon2D::setPolygonUVFramesY(edk::uint32 y){
    //
    if(y){
        this->frames.y=y;edkEnd();
    }
    return this->setPolygonUVFrames(edk::vec2ui32(this->frames.x,
                                                  y
                                                  )
                                    );edkEnd();
}
//Set the polygon frame
void edk::shape::Polygon2D::usePolygonUVFrame(edk::vec2ui32 frame){
    bool ret=false;
    this->frameUsing=edk::vec2ui32(0u,0u);edkEnd();
    //set the frame in all vertexs
    for(edk::uint32 i=0u;i<this->vertexs.size();i++){
        //load the vertex
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs.get(i);edkEnd();
        edk::shape::Vertex2DAnimatedUV* tempO = (edk::shape::Vertex2DAnimatedUV*)this->vertexsOriginal.get(i);edkEnd();
        if(temp && tempO){
            //test if temp have frames
            if(temp->getType()==EDK_SHAPE_ANIMATED_UV
                    && tempO->getType()==EDK_SHAPE_ANIMATED_UV
                    ){
                //then set the frame
                temp->useUVFrame(frame);edkEnd();
                tempO->useUVFrame(frame);edkEnd();
                this->frameUsing=frame;edkEnd();
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
        edk::vec2ui32 UVPosition(position%this->frames.x,position/this->frames.x);edkEnd();
        //set the frame in AllVertexs
        for(edk::uint32 i=0u;i<this->vertexs.size();i++){
            //load the vertex
            edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs.get(i);edkEnd();
            edk::shape::Vertex2DAnimatedUV* tempO = (edk::shape::Vertex2DAnimatedUV*)this->vertexsOriginal.get(i);edkEnd();
            if(temp && tempO){
                //test if temp have frames
                if(temp->getType()==EDK_SHAPE_ANIMATED_UV
                        && tempO->getType()==EDK_SHAPE_ANIMATED_UV
                        ){
                    //then set the position
                    temp->useUVFrame(UVPosition);edkEnd();
                    tempO->useUVFrame(UVPosition);edkEnd();
                    this->frameUsing=UVPosition;edkEnd();
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
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs.get(i);edkEnd();
        edk::shape::Vertex2DAnimatedUV* tempO = (edk::shape::Vertex2DAnimatedUV*)this->vertexsOriginal.get(i);edkEnd();
        if(temp && tempO){
            //test if temp have frames
            if(temp->getType()==EDK_SHAPE_ANIMATED_UV
                    && tempO->getType()==EDK_SHAPE_ANIMATED_UV
                    ){
                //then set the frame
                temp->useUVFrameX(x);edkEnd();
                tempO->useUVFrameX(x);edkEnd();
                this->frameUsing.x = x;edkEnd();
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
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs.get(i);edkEnd();
        edk::shape::Vertex2DAnimatedUV* tempO = (edk::shape::Vertex2DAnimatedUV*)this->vertexsOriginal.get(i);edkEnd();
        if(temp && tempO){
            //test if temp have frames
            if(temp->getType()==EDK_SHAPE_ANIMATED_UV
                    && tempO->getType()==EDK_SHAPE_ANIMATED_UV
                    ){
                //then set the frame
                temp->useUVFrameY(y);edkEnd();
                tempO->useUVFrameY(y);edkEnd();
                this->frameUsing.x = y;edkEnd();
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
    this->translate = edk::vec2f32(0,0);edkEnd();
    this->scale=edk::size2f32(1,1);edkEnd();
    this->angle = 0u;edkEnd();
    this->testTransform();edkEnd();
}
//Set the position of the polygon
void edk::shape::Polygon2D::setTranslate(edk::vec2f32 translate){
    this->translate = translate;edkEnd();
    this->testTransform();edkEnd();
}
void edk::shape::Polygon2D::setTranslate(edk::float32 translate){
    this->translate = translate;edkEnd();
    this->testTransform();edkEnd();
}
void edk::shape::Polygon2D::setTranslate(edk::float32 x,edk::float32 y){
    this->setTranslate(edk::vec2f32 (x,y));edkEnd();
}
//set the scale
void edk::shape::Polygon2D::setScale(edk::size2f32 scale){
    this->scale=scale;edkEnd();
    this->testTransform();edkEnd();
}
void edk::shape::Polygon2D::setScale(edk::float32 scale){
    this->scale=scale;edkEnd();
    this->testTransform();edkEnd();
}
void edk::shape::Polygon2D::setScale(edk::float32 width,edk::float32 height){
    this->setScale(edk::size2f32 (width,height));edkEnd();
}
//set the angle
void edk::shape::Polygon2D::setAngle(edk::float32 angle){
    this->angle=angle;edkEnd();
    this->testTransform();edkEnd();
}
//set physics
void edk::shape::Polygon2D::setDensity(edk::float32 density){
    this->density=density;edkEnd();
}
void edk::shape::Polygon2D::setFriction(edk::float32 friction){
    this->friction=friction;edkEnd();
}
void edk::shape::Polygon2D::setRestitution(edk::float32 restitution){
    this->restitution=restitution;edkEnd();
}

//function to calculate boundingBox
bool edk::shape::Polygon2D::calculateBoundingBox(edk::rectf32* rectangle,edk::vector::Matrix<edk::float32,3,3>* transformMat){
    if(transformMat && rectangle && this->getVertexCount()){
        //generate the boundingBox
        edk::rectf32 temp = this->generateBoundingBox(transformMat);edkEnd();

        if(rectangle->origin.x>temp.origin.x){
            rectangle->origin.x=temp.origin.x;edkEnd();
        }
        if(rectangle->origin.y>temp.origin.y){
            rectangle->origin.y=temp.origin.y;edkEnd();
        }
        if(rectangle->size.width<temp.size.width){
            rectangle->size.width=temp.size.width;edkEnd();
        }
        if(rectangle->size.height<temp.size.height){
            rectangle->size.height=temp.size.height;edkEnd();
        }

        return true;
    }
    return false;
}
edk::rectf32 edk::shape::Polygon2D::generateBoundingBox(edk::vector::Matrix<edk::float32,3,3>* transformMat){
    edk::rectf32 ret;edkEnd();

    edk::uint32 size = this->getVertexCount();edkEnd();
    if(size){
        //first copy the matrix
        if(this->matrixTransform.cloneFrom(transformMat)){
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->translate,&this->matrixTranslate);edkEnd();
            edk::Math::generateRotateMatrix(this->angle,&this->matrixRotate);edkEnd();
            edk::Math::generateScaleMatrix(this->scale,&this->matrixScale);edkEnd();

            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixTranslate);edkEnd();
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotate);edkEnd();
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixScale);edkEnd();

            //transform all the vertices
            if(this->matrixPosition.haveMatrix()){
                //transform the first vertex
                if(vertexs.get(0u)){
                    edk::vec2f32 vexPosition;edkEnd();
                    //
                    this->matrixPosition.set(0u,0u,vertexs.get(0u)->position.x);edkEnd();
                    this->matrixPosition.set(0u,1u,vertexs.get(0u)->position.y);edkEnd();
                    this->matrixPosition.set(0u,2u,1.f);edkEnd();

                    //multiply the matrix
                    this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);edkEnd();

                    ret.origin.x = this->matrixPosition.get(0u,0u);edkEnd();
                    ret.origin.y = this->matrixPosition.get(0u,1u);edkEnd();
                    ret.size.width = ret.origin.x;edkEnd();
                    ret.size.height = ret.origin.y;edkEnd();
                    if(size==2u){
                        //process the rectangle or line
                        if(vertexs.get(1u)){
                            //V0x1
                            this->matrixPosition.set(0u,0u,vertexs.get(0u)->position.x);edkEnd();
                            this->matrixPosition.set(0u,1u,vertexs.get(1u)->position.y);edkEnd();
                            this->matrixPosition.set(0u,2u,1.f);edkEnd();

                            //multiply the matrix
                            this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);edkEnd();

                            vexPosition.x = this->matrixPosition.get(0u,0u);edkEnd();
                            vexPosition.y = this->matrixPosition.get(0u,1u);edkEnd();

                            if(ret.origin.x > vexPosition.x){
                                ret.origin.x = vexPosition.x;edkEnd();
                            }
                            if(ret.origin.y > vexPosition.y){
                                ret.origin.y = vexPosition.y;edkEnd();
                            }
                            if(ret.size.width < vexPosition.x){
                                ret.size.width = vexPosition.x;edkEnd();
                            }
                            if(ret.size.height < vexPosition.y){
                                ret.size.height = vexPosition.y;edkEnd();
                            }

                            //V1x0
                            this->matrixPosition.set(0u,0u,vertexs.get(1u)->position.x);edkEnd();
                            this->matrixPosition.set(0u,1u,vertexs.get(0u)->position.y);edkEnd();
                            this->matrixPosition.set(0u,2u,1.f);edkEnd();

                            //multiply the matrix
                            this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);edkEnd();

                            vexPosition.x = this->matrixPosition.get(0u,0u);edkEnd();
                            vexPosition.y = this->matrixPosition.get(0u,1u);edkEnd();

                            if(ret.origin.x > vexPosition.x){
                                ret.origin.x = vexPosition.x;edkEnd();
                            }
                            if(ret.origin.y > vexPosition.y){
                                ret.origin.y = vexPosition.y;edkEnd();
                            }
                            if(ret.size.width < vexPosition.x){
                                ret.size.width = vexPosition.x;edkEnd();
                            }
                            if(ret.size.height < vexPosition.y){
                                ret.size.height = vexPosition.y;edkEnd();
                            }

                            //V1x1
                            this->matrixPosition.set(0u,0u,vertexs.get(1u)->position.x);edkEnd();
                            this->matrixPosition.set(0u,1u,vertexs.get(1u)->position.y);edkEnd();
                            this->matrixPosition.set(0u,2u,1.f);edkEnd();

                            //multiply the matrix
                            this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);edkEnd();

                            vexPosition.x = this->matrixPosition.get(0u,0u);edkEnd();
                            vexPosition.y = this->matrixPosition.get(0u,1u);edkEnd();

                            if(ret.origin.x > vexPosition.x){
                                ret.origin.x = vexPosition.x;edkEnd();
                            }
                            if(ret.origin.y > vexPosition.y){
                                ret.origin.y = vexPosition.y;edkEnd();
                            }
                            if(ret.size.width < vexPosition.x){
                                ret.size.width = vexPosition.x;edkEnd();
                            }
                            if(ret.size.height < vexPosition.y){
                                ret.size.height = vexPosition.y;edkEnd();
                            }
                        }
                    }
                    else{
                        for(edk::uint32 i=0u;i<size;i++){
                            if(vertexs.get(i)){
                                this->matrixPosition.set(0u,0u,vertexs.get(i)->position.x);edkEnd();
                                this->matrixPosition.set(0u,1u,vertexs.get(i)->position.y);edkEnd();
                                this->matrixPosition.set(0u,2u,1.f);edkEnd();

                                //multiply the matrix
                                this->matrixPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransform);edkEnd();

                                vexPosition.x = this->matrixPosition.get(0u,0u);edkEnd();
                                vexPosition.y = this->matrixPosition.get(0u,1u);edkEnd();

                                if(ret.origin.x > vexPosition.x){
                                    ret.origin.x = vexPosition.x;edkEnd();
                                }
                                if(ret.origin.y > vexPosition.y){
                                    ret.origin.y = vexPosition.y;edkEnd();
                                }
                                if(ret.size.width < vexPosition.x){
                                    ret.size.width = vexPosition.x;edkEnd();
                                }
                                if(ret.size.height < vexPosition.y){
                                    ret.size.height = vexPosition.y;edkEnd();
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

//delete the polygonVertex
void edk::shape::Polygon2D::deletePolygon(){
    if(this->canDeletePolygon){
        //remove the animation
        this->framesRemoveAnimation();edkEnd();
        edk::uint32 size = this->getVertexCount();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            //
            if(this->vertexs.get(i)){
                delete this->vertexs.get(i);edkEnd();
            }
            if(this->vertexsOriginal.get(i)){
                delete this->vertexsOriginal.get(i);edkEnd();
            }
        }
        this->vertexs.deleteArray();edkEnd();
        this->vertexsOriginal.deleteArray();edkEnd();

        //delete the morph
        size = this->getMorphCount();edkEnd();
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

        this->canDeletePolygon=false;edkEnd();
    }
}
//remove the UV of one vertex
bool edk::shape::Polygon2D::removeVertexUV(edk::uint32 vertex){
    this->frameUsing=edk::vec2ui32(0u,0u);edkEnd();
    //find the vertex
    edk::shape::Vertex2DWithUV* uvTemp = (edk::shape::Vertex2DWithUV*)this->getVertexPointer(vertex);edkEnd();
    edk::shape::Vertex2DWithUV* uvoTemp = (edk::shape::Vertex2DWithUV*)this->getVertexOriginalPointer(vertex);edkEnd();
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
            edk::shape::Vertex2D* vTemp = new edk::shape::Vertex2D();edkEnd();
            edk::shape::Vertex2D* voTemp = new edk::shape::Vertex2D();edkEnd();
            if(vTemp && voTemp){
                //copy the uvTemp to vTemp
                vTemp->position = uvTemp->position;edkEnd();
                vTemp->color = uvTemp->color;edkEnd();
                voTemp->position = uvTemp->position;edkEnd();
                voTemp->color = uvTemp->color;edkEnd();

                //set the new vertex to the position
                this->vertexs.set(vertex,vTemp);edkEnd();
                this->vertexsOriginal.set(vertex,voTemp);edkEnd();
                //delete the uvTemp
                delete uvTemp;edkEnd();
                delete uvoTemp;edkEnd();
                //clean uvTemp
                uvTemp=NULL;edkEnd();
                uvoTemp=NULL;edkEnd();
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
        this->edk::shape::Polygon2D::removeVertexUV(i);edkEnd();
    }
}
//clean the UV animation in polygons
void edk::shape::Polygon2D::cleanPolygonUVAnimation(){
    //
    for(edk::uint32 i=0u;i<this->vertexs.size();i++){
        //
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs.get(i);edkEnd();
        edk::shape::Vertex2DAnimatedUV* tempO = (edk::shape::Vertex2DAnimatedUV*)this->vertexsOriginal.get(i);edkEnd();
        if(temp && tempO){
            if(temp->getType()==EDK_SHAPE_ANIMATED_UV
                    && tempO->getType()==EDK_SHAPE_ANIMATED_UV
                    ){
                //
                temp->cleanUVAnimation();edkEnd();
                tempO->cleanUVAnimation();edkEnd();
            }
        }
    }
}
//ANIMATION
//create a new animationFrames
bool edk::shape::Polygon2D::framesCreateAnimation(){
    //remove the last animationFrames
    this->framesRemoveAnimation();edkEnd();
    //create a new animationFrames and set it
    edk::animation::Interpolation1DGroup* temp=NULL;edkEnd();
    if(this->framesSetAnimation( (temp = new edk::animation::Interpolation1DGroup) )){
        //return true
        return this->createAnimationFrames=true;edkEnd();
    }
    //else delete temp if exist
    if(temp){
        //
        delete temp;edkEnd();
    }
    //else return false
    return this->createAnimationFrames=false;edkEnd();
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
        this->framesRemoveAnimation();edkEnd();

        //set the anim
        anim->retainObject((edk::animation::InterpolationGroup**)&this->animationFrame);edkEnd();
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
    return this->animationFrame;edkEnd();
}
//remove the animationGroup
void edk::shape::Polygon2D::framesRemoveAnimation(){
    this->createAnimationFrames=false;edkEnd();
    //test if have an animation
    if(this->framesHaveAnimation()){
        //remove the animation
        this->animationFrame->releaseObject((edk::animation::InterpolationGroup**)&this->animationFrame);edkEnd();
    }
    this->animationFrame=NULL;edkEnd();
}
//return true if have an animation
bool edk::shape::Polygon2D::framesHaveAnimation(){
    //
    return (this->animationFrame!=NULL);edkEnd();
}
//return true if this polygon create the animation
bool edk::shape::Polygon2D::framesIsAnimationCreator(){
    //
    return this->createAnimationFrames;edkEnd();
}


//return the vertexCount
edk::uint32 edk::shape::Polygon2D::getVertexCount(){
    //
    if(this->vertexsOriginal.size() < this->vertexs.size())
        return this->vertexsOriginal.size();edkEnd();
    return this->vertexs.size();edkEnd();
}
//return if the vertex have UV
edk::uint8 edk::shape::Polygon2D::getVertexType(edk::uint32 pos){
    //test if have the polygon
    if(pos<this->getVertexCount()){
        if(this->vertexs.get(pos)){
            return this->vertexs.get(pos)->getType();edkEnd();
        }
    }
    //else retun false
    return 0u;edkEnd();
}
//return the vertex
edk::vec2f32 edk::shape::Polygon2D::getVertexPosition(edk::uint32 pos){
    //test if have the vertex
    if(pos<this->getVertexCount()){
        if(this->vertexs.get(pos)){
            //return the vertex
            return edk::vec2f32(this->vertexs.get(pos)->position.x,this->vertexs.get(pos)->position.y);edkEnd();
        }
    }
    //else return a zero vertex
    return edk::vec2f32(0,0);edkEnd();
}
//return the vertex with all transformations
edk::vec2f32 edk::shape::Polygon2D::getVertexPositionTransformed(edk::uint32 pos){
    //test if have the vertex
    if(pos<this->getVertexCount()){
        if(this->vertexs.get(pos)){
            //apply the transformations
            edk::vec2f32 ret;edkEnd();
            //scale
            ret.x = this->vertexs.get(pos)->position.x * this->scale.width;edkEnd();
            ret.y = this->vertexs.get(pos)->position.y * this->scale.height;edkEnd();
            //rotate
            ret = edk::Math::rotatePlus(ret,this->angle);edkEnd();
            //translate
            ret.x += this->translate.x;edkEnd();
            ret.y += this->translate.y;edkEnd();
            //return the vertex
            return ret;
        }
    }
    //else return a zero vertex
    return edk::vec2f32(0,0);edkEnd();
}
//return the vertex color
edk::color4f32 edk::shape::Polygon2D::getVertexColor(edk::uint32 pos){

    //test if have the vertex
    if(pos<this->getVertexCount()){
        if(this->vertexs.get(pos)){
            //return the vertex
            return edk::color4f32(this->vertexs.get(pos)->color.r,this->vertexs.get(pos)->color.g,this->vertexs.get(pos)->color.b,
                                  this->vertexs.get(pos)->color.a);edkEnd();
        }
    }
    //else return a zero vertex
    return edk::color4f32(0,0,0,0);edkEnd();
}
//return the vertex UV
edk::vec2f32 edk::shape::Polygon2D::getVertexUV(edk::uint32 pos){
    //test if have the vertex
    if(pos<this->getVertexCount()){
        //get a temp
        edk::shape::Vertex2DAnimatedUV* temp = (edk::shape::Vertex2DAnimatedUV*)this->vertexs.get(pos);edkEnd();
        if(temp){
            //test if the vertex have the UV
            switch(temp->getType()){
            //
            case EDK_SHAPE_UV:
                //
                return edk::vec2f32(temp->getUV().x,temp->getUV().y);edkEnd();
                break;
            case EDK_SHAPE_ANIMATED_UV:
                //
                return edk::vec2f32(temp->getSaved().x,temp->getSaved().y);edkEnd();
                break;
            }
        }
    }
    //else return a zero vertex
    return edk::vec2f32(0,0);edkEnd();
}
//return the frames
edk::vec2ui32 edk::shape::Polygon2D::getFrames(){
    //
    return this->frames;edkEnd();
}
edk::uint32 edk::shape::Polygon2D::getFramesPosition(){
    return this->framesSize;edkEnd();
}
//return the frameUseds
edk::vec2ui32 edk::shape::Polygon2D::getFrameUsed(){
    return this->frameUsing;edkEnd();
}
edk::uint32 edk::shape::Polygon2D::getFramePositionUsed(){
    if(this->frames.x && this->frames.y){
        return (this->frames.x * this->frameUsing.y) + this->frameUsing.x;edkEnd();
    }
    return 0u;edkEnd();
}
//return the morphCount
edk::uint32 edk::shape::Polygon2D::getMorphCount(){
    return this->vertexsMorph.size();
}
//return the transform
edk::vec2f32 edk::shape::Polygon2D::getTranslate(){
    return this->translate;edkEnd();
}
edk::size2f32 edk::shape::Polygon2D::getScale(){
    return this->scale;edkEnd();
}
edk::float32 edk::shape::Polygon2D::getAngle(){
    return this->angle;edkEnd();
}
//return true if is transforming
bool edk::shape::Polygon2D::isTransforming(){
    return this->transforming;edkEnd();
}
//get Physics
edk::float32 edk::shape::Polygon2D::getDensity(){
    return this->density;edkEnd();
}
edk::float32 edk::shape::Polygon2D::getFriction(){
    return this->friction;edkEnd();
}
edk::float32 edk::shape::Polygon2D::getRestitution(){
    return this->restitution;edkEnd();
}

//return true if the polygon is a circle
bool edk::shape::Polygon2D::isCircle(){
    if(this->type == edk::shape::circle2D){
        return true;
    }
    return false;
}
//return the circleRadius only if is a circle
edk::float32 edk::shape::Polygon2D::getCircleRadius(){
    if(this->type == edk::shape::circle2D){
        return this->radius;edkEnd();
    }
    return 0.f;
}
//return true if it's a Rectangle
bool edk::shape::Polygon2D::isRect(){
    if(this->type == edk::shape::rectangle2D){
        return true;
    }
    return false;
}
//return true if it's lines
bool edk::shape::Polygon2D::isLine(){
    if(this->type == edk::shape::line2D){
        return true;
    }
    return false;
}
//get line ID
edk::uint8 edk::shape::Polygon2D::getCollisionID(){
    return this->collisionID;edkEnd();
}

//functions for the vertexes animations
edk::uint32 edk::shape::Polygon2D::newPolygonMorph(edk::float32 percent,bool* success){
    //test if have the vertexs
    if(this->getVertexCount()){
        //create a new morph
        edk::shape::Polygon2D::Polygon2DMorph* temp = new edk::shape::Polygon2D::Polygon2DMorph(this->getVertexCount(),
                                                                                                this->polygonColor
                                                                                                );edkEnd();
        if(temp){
            edk::uint32 positionMorph = this->vertexsMorph.pushBack(temp);edkEnd();
            if(positionMorph<this->vertexsMorph.size()){
                *success=true;edkEnd();
                temp->percent=percent;edkEnd();
                return positionMorph;
            }
            delete temp;edkEnd();
        }
    }
    *success=false;edkEnd();
    return 0u;
}
bool edk::shape::Polygon2D::havePolygonMorph(edk::uint32 positionMorph){
    return this->vertexsMorph.havePos(positionMorph);
}
bool edk::shape::Polygon2D::deletePolygonMorph(edk::uint32 positionMorph){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
        if(temp){
            if(this->vertexsMorph.remove(positionMorph)){
                delete temp;edkEnd();
                return true;
            }
        }
    }
    return false;
}
void edk::shape::Polygon2D::cleanPolygonMorph(){
    edk::uint32 size = this->vertexsMorph.size();edkEnd();
    edk::shape::Polygon2D::Polygon2DMorph* temp;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->vertexsMorph.get(i);edkEnd();
        if(temp){
            delete temp;edkEnd();
        }
    }
    this->vertexsMorph.clean();edkEnd();
}
void edk::shape::Polygon2D::deleteAllPolygonMorph(){
    this->cleanPolygonMorph();edkEnd();
}
edk::uint32 edk::shape::Polygon2D::getPolygonMorphSize(){
    return this->vertexsMorph.size();
}
//morph setters
//set the position of a vertex
bool edk::shape::Polygon2D::setPolygonMorphVertexPosition(edk::uint32 positionMorph,edk::uint32 vertex,edk::vec2f32 position){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
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
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
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
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
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
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
        if(temp){
            return temp->setPolygonColorR(r);
        }
    }
    return false;
}
bool edk::shape::Polygon2D::setPolygonMorphColorG(edk::uint32 positionMorph,edk::float32 g){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
        if(temp){
            return temp->setPolygonColorG(g);
        }
    }
    return false;
}
bool edk::shape::Polygon2D::setPolygonMorphColorB(edk::uint32 positionMorph,edk::float32 b){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
        if(temp){
            return temp->setPolygonColorB(b);
        }
    }
    return false;
}
bool edk::shape::Polygon2D::setPolygonMorphColorA(edk::uint32 positionMorph,edk::float32 a){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
        if(temp){
            return temp->setPolygonColorA(a);
        }
    }
    return false;
}
//set the UVMap of the vertex
bool edk::shape::Polygon2D::setPolygonMorphVertexUV(edk::uint32 positionMorph,edk::uint32 vertex,edk::vec2f32 uv){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
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
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
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
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
        if(temp){
            return temp->setPolygonUVFramesX(x);
        }
    }
    return false;
}
bool edk::shape::Polygon2D::setPolygonMorphUVFramesY(edk::uint32 positionMorph,edk::uint32 y){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
        if(temp){
            return temp->setPolygonUVFramesY(y);
        }
    }
    return false;
}
//Set the polygon frame
bool edk::shape::Polygon2D::usePolygonMorphUVFrame(edk::uint32 positionMorph,edk::vec2ui32 frame){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
        if(temp){
            temp->usePolygonUVFrame(frame);
            return true;
        }
    }
    return false;
}
bool edk::shape::Polygon2D::usePolygonMorphUVFramePosition(edk::uint32 positionMorph,edk::uint32 position){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
        if(temp){
            edk::vec2ui32 UVPosition(position%this->frames.x,position/this->frames.x);edkEnd();
            temp->usePolygonUVFrame(UVPosition);
            return true;
        }
    }
    return false;
}
bool edk::shape::Polygon2D::usePolygonMorphUVFrameX(edk::uint32 positionMorph,edk::uint32 x){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
        if(temp){
            temp->usePolygonUVFrameX(x);
            return true;
        }
    }
    return false;
}
bool edk::shape::Polygon2D::usePolygonMorphUVFrameY(edk::uint32 positionMorph,edk::uint32 y){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
        if(temp){
            temp->usePolygonUVFrameY(y);
            return true;
        }
    }
    return false;
}
edk::float32 edk::shape::Polygon2D::getPolygonMorphPercent(edk::uint32 positionMorph){
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
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
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
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
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
        if(temp){
            ret = temp->getVertexPosition(positionVertex);edkEnd();
        }
    }
    return ret;
}
//return the vertex with all transformations
edk::vec2f32 edk::shape::Polygon2D::getPolygonMorphVertexPositionTransformed(edk::uint32 positionMorph,edk::uint32 positionVertex){
    edk::vec2f32 ret;
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
        if(temp){
            ret = temp->getVertexPositionTransformed(positionVertex);edkEnd();
        }
    }
    return ret;
}
//return the vertex color
edk::color4f32 edk::shape::Polygon2D::getPolygonMorphVertexColor(edk::uint32 positionMorph,edk::uint32 positionVertex){
    edk::color4f32 ret;
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
        if(temp){
            ret = temp->getVertexColor(positionVertex);edkEnd();
        }
    }
    return ret;
}
//return the vertex UV
edk::vec2f32 edk::shape::Polygon2D::getPolygonMorphVertexUV(edk::uint32 positionMorph,edk::uint32 positionVertex){
    edk::vec2f32 ret;
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
        if(temp){
            ret = temp->getVertexUV(positionVertex);edkEnd();
        }
    }
    return ret;
}
//return the frames
edk::vec2ui32 edk::shape::Polygon2D::getPolygonMorphFrames(edk::uint32 positionMorph){
    edk::vec2ui32 ret;
    if(this->havePolygonMorph(positionMorph)){
        edk::shape::Polygon2D::Polygon2DMorph* temp = this->vertexsMorph.get(positionMorph);edkEnd();
        if(temp){
            ret = temp->getFrames(0u);edkEnd();
        }
    }
    return ret;
}

//Set to cant delete the polygon
void edk::shape::Polygon2D::cantDeletePolygon(){
    //
    this->canDeletePolygon=false;edkEnd();
    //set matrices can't delete the matrix and vector
    this->matrixPosition.cantDeleteVector();edkEnd();
    this->matrixTranslate.cantDeleteMatrix();edkEnd();
    this->matrixRotate.cantDeleteMatrix();edkEnd();
    this->matrixScale.cantDeleteMatrix();edkEnd();
    this->matrixTransform.cantDeleteMatrix();edkEnd();
}

//print the polygon
void edk::shape::Polygon2D::print(){
    /*
    for(edk::uint32 i=0u;i<this->getVertexCount();i++){
        //
        if(vertexs.get(i)){
            vertexs.get(i)->print(i);edkEnd();
        }
    }
    */

    //printVBO
    (this->*vboPrint)();
}
//Draw the polygon
void edk::shape::Polygon2D::draw(){
    edk::GU::guPushMatrix();edkEnd();
    edk::GU::guTranslate2f32(this->translate);edkEnd();
    edk::GU::guRotateZf32(this->angle);edkEnd();
    edk::GU::guScale2f32(this->scale);edkEnd();
    /*
    edk::GU::guBegin(GU_POLYGON);edkEnd();
    this->drawVertexs();edkEnd();
    edk::GU::guEnd();edkEnd();
*/
    //drawVBO
    (this->*vboDraw)(GU_POLYGON);

    edk::GU::guPopMatrix();edkEnd();
}
//Draw the polygon with lines
void edk::shape::Polygon2D::drawWire(){
    edk::GU::guPushMatrix();edkEnd();
    edk::GU::guTranslate2f32(this->translate);edkEnd();
    edk::GU::guRotateZf32(this->angle);edkEnd();
    edk::GU::guScale2f32(this->scale);edkEnd();
    /*
    edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    this->drawVertexs();edkEnd();
    edk::GU::guEnd();edkEnd();
*/
    //drawVBO
    (this->*vboDraw)(GU_LINE_LOOP);

    edk::GU::guPopMatrix();edkEnd();
}
//draw vertexs
void edk::shape::Polygon2D::drawPolygonVertexs(edk::color4f32 color){
    edk::GU::guBegin(GL_POINTS);edkEnd();
    //edk::GU::guBegin(GU_LINE_LOOP);edkEnd();
    this->drawVertexsWithColor(color);edkEnd();
    edk::GU::guEnd();edkEnd();
    //drawVBO
    //(this->*vboDrawPolygonVertexes)(color);
}

//Write to XML
bool edk::shape::Polygon2D::writeToXML(edk::XML* xml,edk::uint32 polygonID){
    if(xml){
        bool ret=false;edkEnd();
        //create the ID string
        edk::char8* id = edk::String::int32ToStr(polygonID);edkEnd();
        if(id){
            edk::char8* name = edk::String::strCat((edk::char8*)"polygon_",id);edkEnd();
            if(name){
                //create the polygon
                if(xml->addSelectedNextChild(name)){
                    //select the name
                    if(xml->selectChild(name)){
                        ret=true;edkEnd();
                        edk::char8* temp = NULL;edkEnd();
                        //test if it's circle
                        if(this->polygonCircle || this->type==edk::shape::circle2D){
                            //set the string
                            xml->setSelectedString("circle");edkEnd();
                            temp = edk::String::float32ToStr(this->getCircleRadius());edkEnd();
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"radius",temp);edkEnd();
                                free(temp);edkEnd();
                            }
                        }
                        else if(this->polygonLine || this->type==edk::shape::line2D){
                            //set the string
                            xml->setSelectedString("line");edkEnd();
                            temp = edk::String::int32ToStr(this->getCollisionID());edkEnd();
                            if(temp){
                                xml->addSelectedNextAttribute((edk::char8*)"collisionID",temp);edkEnd();
                                free(temp);edkEnd();
                            }
                        }
                        else if(this->type==edk::shape::rectangle2D){
                            //set the string
                            xml->setSelectedString("rectangle");edkEnd();
                        }
                        else{
                            //set the string
                            xml->setSelectedString("polygon");edkEnd();
                        }

                        edk::uint32 size = this->getVertexCount();edkEnd();
                        //save the vertexs
                        temp=edk::String::int32ToStr(size);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"vCount",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        //Write Vertexs
                        for(edk::uint32 i=0u;i<size;i++){
                            edk::shape::Vertex2DAnimatedUV* polyTemp = (edk::shape::Vertex2DAnimatedUV*)vertexs.get(i);edkEnd();
                            if(polyTemp){
                                polyTemp->writeToXML(i,xml);edkEnd();
                            }
                        }
                        if(xml->addSelectedNextChild("original")){
                            if(xml->selectChild("original")){
                                //write the vertexsOriginal

                                size = this->getVertexCount();edkEnd();
                                //save the vertexs
                                temp=edk::String::int32ToStr(size);edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"voCount",temp);edkEnd();
                                    free(temp);edkEnd();
                                }
                                //Write Vertexs
                                for(edk::uint32 i=0u;i<size;i++){
                                    edk::shape::Vertex2DAnimatedUV* polyTemp = (edk::shape::Vertex2DAnimatedUV*)vertexsOriginal.get(i);edkEnd();
                                    if(polyTemp){
                                        polyTemp->writeToXML(i,xml);edkEnd();
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
                                temp=edk::String::int32ToStr(size);edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"mCount",temp);edkEnd();
                                    free(temp);edkEnd();
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
                                temp = edk::String::float32ToStr(this->getFrames().x);edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"framesX",temp);edkEnd();
                                    free(temp);edkEnd();
                                }
                                temp = edk::String::float32ToStr(this->getFrames().y);edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"framesY",temp);edkEnd();
                                    free(temp);edkEnd();
                                }
                                //write selected
                                temp = edk::String::float32ToStr(this->frameUsing.x);edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"frameUsingX",temp);edkEnd();
                                    free(temp);edkEnd();
                                }
                                temp = edk::String::float32ToStr(this->frameUsing.y);edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"frameUsingY",temp);edkEnd();
                                    free(temp);edkEnd();
                                }
                                xml->selectFather();edkEnd();
                            }
                        }
                        //write transformations
                        if(xml->addSelectedNextChild("transformation")){
                            if(xml->selectChild("transformation")){
                                temp = edk::String::float32ToStr(this->getTranslate().x);edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"translateX",temp);edkEnd();
                                    free(temp);edkEnd();
                                }
                                temp = edk::String::float32ToStr(this->getTranslate().y);edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"translateY",temp);edkEnd();
                                    free(temp);edkEnd();
                                }
                                temp = edk::String::float32ToStr(this->getScale().width);edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"scaleW",temp);edkEnd();
                                    free(temp);edkEnd();
                                }
                                temp = edk::String::float32ToStr(this->getScale().height);edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"scaleH",temp);edkEnd();
                                    free(temp);edkEnd();
                                }
                                temp = edk::String::float32ToStr(this->getAngle());edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"angle",temp);edkEnd();
                                    free(temp);edkEnd();
                                }
                                xml->selectFather();edkEnd();
                            }
                        }
                        //write physics
                        if(xml->addSelectedNextChild("physics")){
                            if(xml->selectChild("physics")){
                                temp = edk::String::float32ToStr(this->getDensity());edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"density",temp);edkEnd();
                                    free(temp);edkEnd();
                                }
                                temp = edk::String::float32ToStr(this->getFriction());edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"friction",temp);edkEnd();
                                    free(temp);edkEnd();
                                }
                                temp = edk::String::float32ToStr(this->getRestitution());edkEnd();
                                if(temp){
                                    xml->addSelectedNextAttribute((edk::char8*)"restitution",temp);edkEnd();
                                    free(temp);edkEnd();
                                }
                                xml->selectFather();edkEnd();
                            }
                        }
                        //UV animations
                        if(this->animationFrame){
                            this->animationFrame->writeToXML(xml,0u);edkEnd();
                        }
                        xml->selectFather();edkEnd();
                    }
                }
                free(name);edkEnd();
            }
            free(id);edkEnd();
        }
        return ret;
    }
    return false;
}
//read from XML
bool edk::shape::Polygon2D::readFromXML(edk::XML* xml,edk::uint32 polygonID){
    if(xml){
        bool ret=false;edkEnd();
        //create the ID string
        edk::char8* id = edk::String::int32ToStr(polygonID);edkEnd();
        if(id){
            edk::char8* name = edk::String::strCat((edk::char8*)"polygon_",id);edkEnd();
            if(name){
                //create the polygon
                //select the name
                if(xml->selectChild(name)){
                    edk::char8 filter[3u] = {9u,'\n',0u};
                    edk::char8* temp;edkEnd();
                    //load the polygonType
                    temp = edk::String::strCopyWithFilter(xml->getSelectedString(),(edk::char8*)filter);edkEnd();
                    if(temp){
                        //teste the type
                        if(edk::String::strCompare(temp,"circle")){
                            this->polygonCircle = true;edkEnd();
                            this->polygonLine = false;edkEnd();
                            this->radius = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("radius"));edkEnd();
                            this->collisionID = 0u;edkEnd();
                            this->type = edk::shape::circle2D;edkEnd();
                        }
                        else if(edk::String::strCompare(temp,"line")){
                            this->polygonLine = true;edkEnd();
                            this->polygonCircle = false;edkEnd();
                            this->radius = 0.f;edkEnd();
                            this->collisionID = edk::String::strToInt32(xml->getSelectedAttributeValueByName("collisionID"));edkEnd();
                            this->type = edk::shape::line2D;edkEnd();
                        }
                        else if(edk::String::strCompare(temp,"rectangle")){
                            this->polygonLine = false;edkEnd();
                            this->polygonCircle = false;edkEnd();
                            this->radius = 0.f;edkEnd();
                            this->collisionID = 0u;edkEnd();
                            this->type = edk::shape::rectangle2D;edkEnd();
                        }
                        else if(edk::String::strCompare(temp,"polygon")){
                            //
                            this->type = edk::shape::polygon2D;edkEnd();
                        }
                        free(temp);edkEnd();
                    }

                    //read the vertex count
                    edk::uint32 size = edk::String::strToInt32(xml->getSelectedAttributeValueByName("vCount"));edkEnd();
                    if(size){
                        this->createPolygon(size);edkEnd();
                        //read the vertexs
                        for(edk::uint32 i=0u;i<size;i++){
                            //read the vertex type
                            edk::uint8 type = edk::shape::Vertex2D::readTypeFromXML(i,xml);edkEnd();
                            switch(type){
                            case EDK_SHAPE_ANIMATED_UV:
                            case EDK_SHAPE_UV:
                            {
                                edk::shape::Vertex2DAnimatedUV temp;edkEnd();
                                if(temp.readFromXML(i,xml)){
                                    //set the data
                                    this->setVertexPosition(i,temp.position);edkEnd();
                                    this->setVertexColor(i,temp.color);edkEnd();
                                    this->setVertexUV(i,temp.getSaved());edkEnd();
                                }
                                break;
                            }
                            case EDK_SHAPE_NOUV:
                            {
                                edk::shape::Vertex2D temp;edkEnd();
                                if(temp.readFromXML(i,xml)){
                                    //set the data
                                    this->setVertexPosition(i,temp.position);edkEnd();
                                    this->setVertexColor(i,temp.color);edkEnd();
                                }
                                break;
                            }
                            }
                        }
                        //read the original
                        if(xml->selectChild("original")){
                            size = edk::String::strToInt32(xml->getSelectedAttributeValueByName("voCount"));edkEnd();
                            if(size){
                                edk::shape::Vertex2D* vTemp = NULL;
                                //read the vertexs
                                for(edk::uint32 i=0u;i<size;i++){
                                    //read the vertex type
                                    edk::uint8 type = edk::shape::Vertex2D::readTypeFromXML(i,xml);edkEnd();
                                    switch(type){
                                    case EDK_SHAPE_ANIMATED_UV:
                                    case EDK_SHAPE_UV:
                                    {
                                        edk::shape::Vertex2DAnimatedUV temp;edkEnd();
                                        vTemp = this->vertexsOriginal.get(i);edkEnd();
                                        edk::shape::Vertex2DAnimatedUV* uvTemp = new edk::shape::Vertex2DAnimatedUV;edkEnd();
                                        if(uvTemp){
                                            if(temp.readFromXML(i,xml)){
                                                //set the data
                                                uvTemp->position = temp.position;edkEnd();
                                                uvTemp->color = temp.color;edkEnd();
                                                uvTemp->setUV(temp.getUV());edkEnd();
                                                uvTemp->setUVFrames(temp.getUVFrames());edkEnd();

                                                this->vertexsOriginal.set(i,uvTemp);edkEnd();
                                                if(vTemp){
                                                    delete vTemp;edkEnd();
                                                }
                                                vTemp=NULL;edkEnd();
                                            }
                                            else{
                                                delete uvTemp;
                                            }
                                        }
                                        break;
                                    }
                                    case EDK_SHAPE_NOUV:
                                    {
                                        edk::shape::Vertex2D temp;edkEnd();
                                        vTemp = this->vertexsOriginal.get(i);edkEnd();
                                        if(temp.readFromXML(i,xml) && vTemp){
                                            //set the data
                                            vTemp->position = temp.position;edkEnd();
                                            vTemp->color = temp.color;edkEnd();
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
                            size = edk::String::strToInt32(xml->getSelectedAttributeValueByName("mCount"));edkEnd();
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
                            edk::uint32 uvFrameX = (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("framesX"));edkEnd();
                            edk::uint32 uvFrameY = (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("framesY"));edkEnd();
                            //set uvFrames
                            this->setPolygonUVFrames(edk::vec2ui32(uvFrameX,uvFrameY));edkEnd();

                            //set using the frame ID
                            this->frameUsing.x = (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("frameUsingX"));edkEnd();
                            this->frameUsing.y = (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("frameUsingY"));edkEnd();

                            //set the frameUsing
                            this->usePolygonUVFrame(this->frameUsing);edkEnd();

                            xml->selectFather();edkEnd();
                        }

                        //read transformation
                        if(xml->selectChild("transformation")){
                            this->translate.x = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("translateX"));edkEnd();
                            this->translate.y = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("translateY"));edkEnd();
                            this->scale.width = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("scaleW"));edkEnd();
                            this->scale.height = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("scaleH"));edkEnd();
                            this->angle = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("angle"));edkEnd();
                            this->testTransform();edkEnd();
                            xml->selectFather();edkEnd();
                        }

                        //read physics
                        if(xml->selectChild("physics")){
                            this->density = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("density"));edkEnd();
                            this->friction = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("friction"));edkEnd();
                            this->restitution = edk::String::strToFloat32(xml->getSelectedAttributeValueByName("restitution"));edkEnd();
                            xml->selectFather();edkEnd();
                        }

                        this->framesCreateAnimation();edkEnd();
                        //UV animations
                        if(this->animationFrame){
                            if(this->animationFrame->readFromXML(xml,0u)){
                                //set play
                                this->animationFrame->playForward();edkEnd();
                            }
                            else{
                                //delete the frame
                                this->framesRemoveAnimation();edkEnd();
                            }
                        }
                        ret=true;edkEnd();
                    }
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(id);edkEnd();
        }
        return ret;
    }
    return false;
}

bool edk::shape::Polygon2D::cloneFrom(edk::shape::Polygon2D* poly){
    //first delete the vertexs
    this->deletePolygon();edkEnd();
    if(poly){
        //then create a new polygon
        if(this->createPolygon(poly->getVertexCount())){
            edk::uint32 size=this->getVertexCount();edkEnd();
            edk::shape::Vertex2DAnimatedUV* temp = NULL;
            edk::shape::Vertex2D* vTemp = NULL;
            edk::shape::Vertex2DWithUV* uvTemp = NULL;
            edk::shape::Vertex2DAnimatedUV* uvaTemp = NULL;
            //then copy the vertex
            for(edk::uint32 i=0u;i<size;i++){
                //copy the vertex
                temp = (edk::shape::Vertex2DAnimatedUV*)vertexs.get(i);edkEnd();
                if(temp){
                    //this->setVertexPosition(i,poly->getVertexPosition(i));edkEnd();
                    temp->position = poly->getVertexPosition(i);edkEnd();
                    this->setVBOVertexPosition(i,temp->position);
                    //this->setVertexColor(i,poly->getVertexColor(i));edkEnd();
                    temp->color = poly->getVertexColor(i);edkEnd();
                    this->setVBOVertexColor(i,temp->color);
                    //copy the frames
                    //this->setVertexUVFrames(i,poly->getFrames());edkEnd();
                    //get vertexType
                    switch(poly->getVertexType(i)){
                    //
                    case EDK_SHAPE_ANIMATED_UV:
                        //
                        this->setVertexUV(i,poly->getVertexUV(i));edkEnd();
                        this->setVertexUVFrames(i,poly->getFrames());edkEnd();
                        break;
                    case EDK_SHAPE_UV:
                        //
                        this->setVertexUV(i,poly->getVertexUV(i));edkEnd();
                        break;
                    };
                }
                vTemp = vertexsOriginal.get(i);edkEnd();
                if(vTemp){
                    //get the vertex to read the values
                    temp = (edk::shape::Vertex2DAnimatedUV*)poly->vertexsOriginal.get(i);edkEnd();
                    //get vertexType
                    switch(temp->getType()){
                    case EDK_SHAPE_ANIMATED_UV:
                        //
                        this->setVertexUV(i,poly->getVertexUV(i));edkEnd();
                        this->setVertexUVFrames(i,poly->getFrames());edkEnd();

                        uvaTemp = new edk::shape::Vertex2DAnimatedUV;
                        if(uvTemp){
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
                        this->setVertexUV(i,poly->getVertexUV(i));edkEnd();

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
                        vTemp->position = temp->position;edkEnd();
                        vTemp->color = temp->color;edkEnd();
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
        this->setPolygonUVFrames(poly->getFrames());edkEnd();
        this->usePolygonUVFrame(poly->frameUsing);edkEnd();
        //set the transformations
        this->setTranslate(poly->getTranslate());edkEnd();
        this->setScale(poly->getScale());edkEnd();
        this->setAngle(poly->getAngle());edkEnd();
        //set physics
        this->setDensity(poly->getDensity());edkEnd();
        this->setFriction(poly->getFriction());edkEnd();
        this->setRestitution(poly->getRestitution());edkEnd();
        //
        this->type = poly->type;edkEnd();
        this->polygonCircle = poly->polygonCircle;edkEnd();
        this->radius=poly->radius;edkEnd();
        this->polygonLine = poly->polygonLine;edkEnd();
        this->collisionID = poly->collisionID;edkEnd();
        //set the animation
        this->framesSetAnimation(poly->framesGetAnimation());edkEnd();
        this->createAnimationFrames = poly->createAnimationFrames;edkEnd();
        //copy the matrices
        this->matrixTranslate.cloneFrom(&poly->matrixTranslate);edkEnd();
        this->matrixRotate.cloneFrom(&poly->matrixRotate);edkEnd();
        this->matrixScale.cloneFrom(&poly->matrixScale);edkEnd();
        this->matrixTransform.cloneFrom(&poly->matrixTransform);edkEnd();
        //
        return true;
    }
    return false;
}
