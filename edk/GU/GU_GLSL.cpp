#include "GU_GLSL.h"

/*
Library GU_GLSL - Add shaders to the GU
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
#pragma message "            Inside GU_GLSL.cpp"
#endif

//a boolean if can still running load the texture
bool edk::GU_GLSL::canLoadShader=true;
bool edk::GU_GLSL::templateConstructNeed=true;
bool edk::GU_GLSL::initiate=false;
#if defined(_WIN32) || defined(_WIN64)
//Windows
edk::multi::MutexDisable edk::GU_GLSL::mut;
#endif
#ifdef __linux__
//LINUX
edk::multi::MutexDisable edk::GU_GLSL::mut;
#endif
edk::multi::MutexDisable edk::GU_GLSL::mutBeginEnd;

//mutex used to create the shader
edk::multi::Mutex edk::GU_GLSL::mutCreateShader;
edk::multi::Mutex edk::GU_GLSL::mutDelShader;
edk::multi::Mutex edk::GU_GLSL::mutUseShader;
edk::multi::Mutex edk::GU_GLSL::mutUseNoShader;

edk::vector::Queue<edk::GU_GLSL::ShaderClass> edk::GU_GLSL::genShaders;
edk::vector::Queue<edk::uint32> edk::GU_GLSL::delShaders;
edk::GU_GLSL::Shader_Tree edk::GU_GLSL::treeShaders;
edk::vector::Queue<edk::GU_GLSL::ShaderWriteClass> edk::GU_GLSL::genShadersWrite;
edk::GU_GLSL::ShaderWrite_Tree edk::GU_GLSL::treeShadersWrite;
edk::vector::Queue<edk::GU_GLSL::ShaderCompileClass> edk::GU_GLSL::genShadersCompile;
edk::GU_GLSL::ShaderCompile_Tree edk::GU_GLSL::treeShadersCompile;
edk::vector::Queue<edk::GU_GLSL::ShaderIVClass> edk::GU_GLSL::genShadersIV;
edk::GU_GLSL::ShaderIV_Tree edk::GU_GLSL::treeShadersIV;
edk::vector::Queue<edk::GU_GLSL::ShaderLogClass> edk::GU_GLSL::genShadersLog;
edk::GU_GLSL::ShaderLog_Tree edk::GU_GLSL::treeShadersLog;
edk::vector::Queue<edk::GU_GLSL::ProgramAttachClass> edk::GU_GLSL::genProgramsAttach;
edk::GU_GLSL::ProgramAttach_Tree edk::GU_GLSL::treeProgramsAttach;
edk::vector::Queue<edk::GU_GLSL::ProgramLinkClass> edk::GU_GLSL::genProgramsLink;
edk::GU_GLSL::ProgramLink_Tree edk::GU_GLSL::treeProgramsLink;
edk::vector::Queue<edk::GU_GLSL::ShaderUseClass> edk::GU_GLSL::useShaders;
edk::vector::Queue<edk::GU_GLSL::ShaderUseClass> edk::GU_GLSL::useNoShaders;
edk::GU_GLSL::ShaderUse_Tree edk::GU_GLSL::treeUseShaders;
edk::GU_GLSL::ShaderUse_Tree edk::GU_GLSL::treeUseNoShaders;

//construtor
edk::GU_GLSL::GU_GLSL(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
//destrutor
edk::GU_GLSL::~GU_GLSL(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::GU_GLSL::Constructor(bool /*runFather*/){
    //
    if(this->classThis!=this){
        this->classThis=this;
        if(edk::GU_GLSL::templateConstructNeed){

#if defined(_WIN32) || defined(_WIN64)
            //Windows
            edk::GU_GLSL::mut.Constructor();
#endif
#ifdef __linux__
            edk::GU_GLSL::mut.Constructor();
#endif
            edk::GU_GLSL::mutBeginEnd.Constructor();
            edk::GU_GLSL::mutCreateShader.Constructor();
            edk::GU_GLSL::mutDelShader.Constructor();
            edk::GU_GLSL::mutUseShader.Constructor();
            edk::GU_GLSL::mutUseNoShader.Constructor();
            edk::GU_GLSL::genShaders.Constructor();
            edk::GU_GLSL::delShaders.Constructor();
            edk::GU_GLSL::treeShaders.Constructor();
            edk::GU_GLSL::genShadersWrite.Constructor();
            edk::GU_GLSL::treeShadersWrite.Constructor();
            edk::GU_GLSL::genShadersCompile.Constructor();
            edk::GU_GLSL::treeShadersCompile.Constructor();
            edk::GU_GLSL::genShadersIV.Constructor();
            edk::GU_GLSL::treeShadersIV.Constructor();
            edk::GU_GLSL::genShadersLog.Constructor();
            edk::GU_GLSL::treeShadersLog.Constructor();
            edk::GU_GLSL::genProgramsAttach.Constructor();
            edk::GU_GLSL::treeProgramsAttach.Constructor();
            edk::GU_GLSL::genProgramsLink.Constructor();
            edk::GU_GLSL::treeProgramsLink.Constructor();
            edk::GU_GLSL::useShaders.Constructor();
            edk::GU_GLSL::useNoShaders.Constructor();
            edk::GU_GLSL::treeUseShaders.Constructor();
            edk::GU_GLSL::treeUseNoShaders.Constructor();
            edk::GU_GLSL::templateConstructNeed=false;
        }
    }
}

void edk::GU_GLSL::setCantCreateShaders(){
    edk::GU_GLSL::mutCreateShader.lock();
    edk::GU_GLSL::canLoadShader=false;
    edk::GU_GLSL::mutCreateShader.unlock();
}
void edk::GU_GLSL::setCanCreateShaders(){
    edk::GU_GLSL::mutCreateShader.lock();
    edk::GU_GLSL::canLoadShader=true;
    edk::GU_GLSL::mutCreateShader.unlock();
}

//start the shaderLib
edk::int32 edk::GU_GLSL::guShaderInit(){
    edk::int32 ret = GU_GLSL_OK;
    if(!edk::GU_GLSL::initiate){
        edk::GU_GLSL::mut.lock();
        if((ret = glewInit()) == GU_GLSL_OK){
            edk::GU_GLSL::initiate=true;
        }
        edk::GU_GLSL::mut.unlock();
    }
    return ret;
}
//return true if have init the glut
bool edk::GU_GLSL::guShaderInitiated(){
    return edk::GU_GLSL::initiate;
}

bool edk::GU_GLSL::guStartShader(edk::int32 shade){
    bool ret;
    switch(shade){
    case GU_GLSL_fragment_program:
        //
        edk::GU_GLSL::mut.lock();
        ret = glewGetExtension("GL_ARB_fragment_program");
        edk::GU_GLSL::mut.unlock();
        break;
    case GU_GLSL_vertex_program:
        //
        edk::GU_GLSL::mut.lock();
        ret = glewGetExtension("GL_ARB_vertex_program");
        edk::GU_GLSL::mut.unlock();
        break;
    case GU_GLSL_geometry_program:
        //
        edk::GU_GLSL::mut.lock();
        ret = glewGetExtension("GL_ARB_geometry_program");
        edk::GU_GLSL::mut.unlock();
        break;
    }
    //else return false
    return ret;
}
edk::uint32 edk::GU_GLSL::guCreateShader(edk::uint32 type){
    edk::uint32 ret = 0u;
    edk::GU_GLSL::mut.lock();
    if(edk::multi::Thread::isThisThreadMain()){
        //create the shader with the type
        ret = glCreateShader(type);
    }
    else{
        //start a new class in the tree to the mainThread load the shader
#if __x86_64__ || __ppc64__
        edk::uint64 threadID = edk::multi::Thread::getThisThreadID();
#else
        edk::uint32 threadID = edk::multi::Thread::getThisThreadID();
#endif
        if(threadID){
            //generate the ShaderClass
            edk::GU_GLSL::ShaderClass shader;
            shader.threadID = threadID;
            shader.type = type;

            edk::uint32 ret=0u;

            edk::GU_GLSL::mutCreateShader.lock();
            //add the shader in to the queue
            edk::GU_GLSL::genShaders.pushBack(shader);
            edk::GU_GLSL::mutCreateShader.unlock();

            bool run=true;
            //wait to get the shader ID
            while(run){
                edk::GU_GLSL::mutCreateShader.lock();
                //test if have some textures in the tree
                if(edk::GU_GLSL::treeShaders.size()){
                    //tes if have the texture inside the tree
                    if(edk::GU_GLSL::treeShaders.haveShaderByThread(threadID)){
                        //get the texture
                        shader = edk::GU_GLSL::treeShaders.getShaderByThread(threadID);
                        edk::GU_GLSL::treeShaders.remove(shader);
                        ret=shader.id;
                        run=false;
                    }
                }
                //test if can't load the texture
                if(!edk::GU_GLSL::canLoadShader){
                    if(ret){
                        edk::GU_GLSL::guDeleteShader(ret);
                    }
                    ret=0u;
                    run=false;
                }
                edk::GU_GLSL::mutCreateShader.unlock();

                if(run){
                    //sleep this thread
                    edk::watch::Time::sleepProcessMiliseconds(10u);
                }
            }
            return ret;
        }
    }
    edk::GU_GLSL::mut.unlock();
    return ret;
}
void edk::GU_GLSL::guDeleteShader(edk::uint32 id){
    if(edk::multi::Thread::isThisThreadMain()){
        edk::GU_GLSL::mut.lock();
        glDeleteShader(id);
        edk::GU_GLSL::mut.unlock();
    }
    else{
        //push the id
        edk::GU_GLSL::mutDelShader.lock();
        edk::GU_GLSL::delShaders.pushBack(id);
        edk::GU_GLSL::mutDelShader.unlock();
    }
}
bool edk::GU_GLSL::guShaderSource(edk::uint32 id, edk::uint8 *data,  edk::uint32 length){
    bool ret = false;
    if(edk::multi::Thread::isThisThreadMain()){
        //create the shader with the type
        if(id && data && length){
            //set the shaderSource
            edk::GU_GLSL::mut.lock();
            glShaderSource(id,  1u,  (const edk::char8**)(&data),  (const GLint*)&length);
            edk::GU_GLSL::mut.unlock();
            //return true
            ret = true;
        }
    }
    else{
        //start a new class in the tree to the mainThread load the shader
#if __x86_64__ || __ppc64__
        edk::uint64 threadID = edk::multi::Thread::getThisThreadID();
#else
        edk::uint32 threadID = edk::multi::Thread::getThisThreadID();
#endif
        if(threadID){
            //generate the ShaderClass
            edk::GU_GLSL::ShaderWriteClass shader;
            shader.threadID = threadID;
            shader.id=id;
            shader.data=data;
            shader.length=length;

            edk::GU_GLSL::mutCreateShader.lock();
            //add the shader in to the queue
            edk::GU_GLSL::genShadersWrite.pushBack(shader);
            edk::GU_GLSL::mutCreateShader.unlock();

            bool run=true;
            //wait to get the shader ID
            while(run){
                edk::GU_GLSL::mutCreateShader.lock();
                //test if have some textures in the tree
                if(edk::GU_GLSL::treeShadersWrite.size()){
                    //tes if have the texture inside the tree
                    if(edk::GU_GLSL::treeShadersWrite.haveShaderWriteByThread(threadID)){
                        //get the texture
                        shader = edk::GU_GLSL::treeShadersWrite.getShaderWriteByThread(threadID);
                        edk::GU_GLSL::treeShadersWrite.remove(shader);
                        ret=shader.success;
                        run=false;
                    }
                }
                //test if can't load the shader
                if(!edk::GU_GLSL::canLoadShader){
                    if(ret){
                        edk::GU_GLSL::guDeleteShader(shader.id);
                    }
                    ret=false;
                    run=false;
                }
                edk::GU_GLSL::mutCreateShader.unlock();
                if(run){
                    //sleep this thread
                    edk::watch::Time::sleepProcessMiliseconds(10u);
                }
            }
        }
    }
    return ret;
}
void edk::GU_GLSL::guCompileShader(edk::uint32 id){
    if(edk::multi::Thread::isThisThreadMain()){
        edk::GU_GLSL::mut.lock();
        glCompileShader(id);
        edk::GU_GLSL::mut.unlock();
    }
    else{
        //start a new class in the tree to the mainThread load the shader
#if __x86_64__ || __ppc64__
        edk::uint64 threadID = edk::multi::Thread::getThisThreadID();
#else
        edk::uint32 threadID = edk::multi::Thread::getThisThreadID();
#endif
        if(threadID){
            //generate the ShaderClass
            edk::GU_GLSL::ShaderCompileClass shader;
            shader.threadID = threadID;
            shader.id=id;

            edk::GU_GLSL::mutCreateShader.lock();
            //add the shader in to the queue
            edk::GU_GLSL::genShadersCompile.pushBack(shader);
            edk::GU_GLSL::mutCreateShader.unlock();

            bool run=true;
            //wait to get the shader ID
            while(run){
                edk::GU_GLSL::mutCreateShader.lock();
                //test if have some textures in the tree
                if(edk::GU_GLSL::treeShadersCompile.size()){
                    //tes if have the texture inside the tree
                    if(edk::GU_GLSL::treeShadersCompile.haveShaderCompileByThread(threadID)){
                        //get the texture
                        shader = edk::GU_GLSL::treeShadersCompile.getShaderCompileByThread(threadID);
                        edk::GU_GLSL::treeShadersCompile.remove(shader);
                        run=false;
                    }
                }
                //test if can't load the shader
                if(!edk::GU_GLSL::canLoadShader){
                    edk::GU_GLSL::guDeleteShader(shader.id);
                    run=false;
                }
                edk::GU_GLSL::mutCreateShader.unlock();
                if(run){
                    //sleep this thread
                    edk::watch::Time::sleepProcessMiliseconds(10u);
                }
            }
        }
    }
}
void edk::GU_GLSL::guGetShaderiv(edk::uint32 id,  edk::uint32 pname,  edk::int32 *params){
    if(edk::multi::Thread::isThisThreadMain()){
        edk::GU_GLSL::mut.lock();
        glGetShaderiv(id,  pname,  params);
        edk::GU_GLSL::mut.unlock();
    }
    else{
        //start a new class in the tree to the mainThread load the shader
#if __x86_64__ || __ppc64__
        edk::uint64 threadID = edk::multi::Thread::getThisThreadID();
#else
        edk::uint32 threadID = edk::multi::Thread::getThisThreadID();
#endif
        if(threadID){
            //generate the ShaderClass
            edk::GU_GLSL::ShaderIVClass shader;
            shader.threadID = threadID;
            shader.id=id;
            shader.pname=pname;
            shader.params=params;
            //anyelse different then GU_GLSL_PROGRAM
            shader.type=GU_GLSL_VERTEX_SHADER;

            edk::GU_GLSL::mutCreateShader.lock();
            //add the shader in to the queue
            edk::GU_GLSL::genShadersIV.pushBack(shader);
            edk::GU_GLSL::mutCreateShader.unlock();

            bool run=true;
            //wait to get the shader ID
            while(run){
                edk::GU_GLSL::mutCreateShader.lock();
                //test if have some textures in the tree
                if(edk::GU_GLSL::treeShadersIV.size()){
                    //tes if have the texture inside the tree
                    if(edk::GU_GLSL::treeShadersIV.haveShaderIVByThread(threadID)){
                        //get the texture
                        shader = edk::GU_GLSL::treeShadersIV.getShaderIVByThread(threadID);
                        edk::GU_GLSL::treeShadersIV.remove(shader);
                        run=false;
                    }
                }
                //test if can't load the shader
                if(!edk::GU_GLSL::canLoadShader){
                    edk::GU_GLSL::guDeleteShader(shader.id);
                    run=false;
                }
                edk::GU_GLSL::mutCreateShader.unlock();
                if(run){
                    //sleep this thread
                    edk::watch::Time::sleepProcessMiliseconds(10u);
                }
            }
        }
    }
}
void edk::GU_GLSL::guGetProgramiv(edk::uint32 id, edk::uint32 pname,  edk::int32 *params){
    if(edk::multi::Thread::isThisThreadMain()){
        edk::GU_GLSL::mut.lock();
        glGetProgramiv(id,  pname,  params);
        edk::GU_GLSL::mut.unlock();
    }
    else{
        //start a new class in the tree to the mainThread load the shader
#if __x86_64__ || __ppc64__
        edk::uint64 threadID = edk::multi::Thread::getThisThreadID();
#else
        edk::uint32 threadID = edk::multi::Thread::getThisThreadID();
#endif
        if(threadID){
            //generate the ShaderClass
            edk::GU_GLSL::ShaderIVClass shader;
            shader.threadID = threadID;
            shader.id=id;
            shader.pname=pname;
            shader.params=params;
            //anyelse different then GU_GLSL_PROGRAM
            shader.type=GU_GLSL_PROGRAM;

            edk::GU_GLSL::mutCreateShader.lock();
            //add the shader in to the queue
            edk::GU_GLSL::genShadersIV.pushBack(shader);
            edk::GU_GLSL::mutCreateShader.unlock();

            bool run=true;
            //wait to get the shader ID
            while(run){
                edk::GU_GLSL::mutCreateShader.lock();
                //test if have some textures in the tree
                if(edk::GU_GLSL::treeShadersIV.size()){
                    //tes if have the texture inside the tree
                    if(edk::GU_GLSL::treeShadersIV.haveShaderIVByThread(threadID)){
                        //get the texture
                        shader = edk::GU_GLSL::treeShadersIV.getShaderIVByThread(threadID);
                        edk::GU_GLSL::treeShadersIV.remove(shader);
                        run=false;
                    }
                }
                //test if can't load the shader
                if(!edk::GU_GLSL::canLoadShader){
                    edk::GU_GLSL::guDeleteShader(shader.id);
                    run=false;
                }
                edk::GU_GLSL::mutCreateShader.unlock();
                if(run){
                    //sleep this thread
                    edk::watch::Time::sleepProcessMiliseconds(10u);
                }
            }
        }
    }
}
void edk::GU_GLSL::guGetShaderInfoLog(edk::uint32 id,  edk::int32 maxLength,  edk::int32 *length,  edk::char8 *infoLog){
    if(edk::multi::Thread::isThisThreadMain()){
        edk::GU_GLSL::mut.lock();
        glGetShaderInfoLog(id,  maxLength,  length,  (GLchar*)infoLog);
        edk::GU_GLSL::mut.unlock();
    }
    else{
        //start a new class in the tree to the mainThread load the shader
#if __x86_64__ || __ppc64__
        edk::uint64 threadID = edk::multi::Thread::getThisThreadID();
#else
        edk::uint32 threadID = edk::multi::Thread::getThisThreadID();
#endif
        if(threadID){
            //generate the ShaderClass
            edk::GU_GLSL::ShaderLogClass shader;
            shader.threadID = threadID;
            shader.id=id;
            shader.maxLength=maxLength;
            shader.length=length;
            shader.infoLog=infoLog;
            //anyelse different then GU_GLSL_PROGRAM
            shader.type=GU_GLSL_VERTEX_SHADER;

            edk::GU_GLSL::mutCreateShader.lock();
            //add the shader in to the queue
            edk::GU_GLSL::genShadersLog.pushBack(shader);
            edk::GU_GLSL::mutCreateShader.unlock();

            bool run=true;
            //wait to get the shader ID
            while(run){
                edk::GU_GLSL::mutCreateShader.lock();
                //test if have some textures in the tree
                if(edk::GU_GLSL::treeShadersLog.size()){
                    //tes if have the texture inside the tree
                    if(edk::GU_GLSL::treeShadersLog.haveShaderLogByThread(threadID)){
                        //get the texture
                        shader = edk::GU_GLSL::treeShadersLog.getShaderLogByThread(threadID);
                        edk::GU_GLSL::treeShadersLog.remove(shader);
                        run=false;
                    }
                }
                //test if can't load the shader
                if(!edk::GU_GLSL::canLoadShader){
                    edk::GU_GLSL::guDeleteShader(shader.id);
                    run=false;
                }
                edk::GU_GLSL::mutCreateShader.unlock();
                if(run){
                    //sleep this thread
                    edk::watch::Time::sleepProcessMiliseconds(10u);
                }
            }
        }
    }
}
void edk::GU_GLSL::guGetProgramInfoLog(edk::uint32 id,  edk::int32 maxLength,  edk::int32 *length,  edk::char8 *infoLog){
    if(edk::multi::Thread::isThisThreadMain()){
        edk::GU_GLSL::mut.lock();
        glGetProgramInfoLog(id,  maxLength,  length,  (GLchar*)infoLog);
        edk::GU_GLSL::mut.unlock();
    }
    else{
        //start a new class in the tree to the mainThread load the shader
#if __x86_64__ || __ppc64__
        edk::uint64 threadID = edk::multi::Thread::getThisThreadID();
#else
        edk::uint32 threadID = edk::multi::Thread::getThisThreadID();
#endif
        if(threadID){
            //generate the ShaderClass
            edk::GU_GLSL::ShaderLogClass shader;
            shader.threadID = threadID;
            shader.id=id;
            shader.maxLength=maxLength;
            shader.length=length;
            shader.infoLog=infoLog;
            //anyelse different then GU_GLSL_PROGRAM
            shader.type=GU_GLSL_PROGRAM;

            edk::GU_GLSL::mutCreateShader.lock();
            //add the shader in to the queue
            edk::GU_GLSL::genShadersLog.pushBack(shader);
            edk::GU_GLSL::mutCreateShader.unlock();

            bool run=true;
            //wait to get the shader ID
            while(run){
                edk::GU_GLSL::mutCreateShader.lock();
                //test if have some textures in the tree
                if(edk::GU_GLSL::treeShadersLog.size()){
                    //tes if have the texture inside the tree
                    if(edk::GU_GLSL::treeShadersLog.haveShaderLogByThread(threadID)){
                        //get the texture
                        shader = edk::GU_GLSL::treeShadersLog.getShaderLogByThread(threadID);
                        edk::GU_GLSL::treeShadersLog.remove(shader);
                        run=false;
                    }
                }
                //test if can't load the shader
                if(!edk::GU_GLSL::canLoadShader){
                    edk::GU_GLSL::guDeleteShader(shader.id);
                    run=false;
                }
                edk::GU_GLSL::mutCreateShader.unlock();
                if(run){
                    //sleep this thread
                    edk::watch::Time::sleepProcessMiliseconds(10u);
                }
            }
        }
    }
}
//shader program
edk::uint32 edk::GU_GLSL::guCreateProgram(){
    edk::uint32 ret = 0u;
    edk::GU_GLSL::mut.lock();
    if(edk::multi::Thread::isThisThreadMain()){
        //create the shader with the type
        ret = glCreateProgram();
    }
    else{
        //start a new class in the tree to the mainThread load the shader
#if __x86_64__ || __ppc64__
        edk::uint64 threadID = edk::multi::Thread::getThisThreadID();
#else
        edk::uint32 threadID = edk::multi::Thread::getThisThreadID();
#endif
        if(threadID){
            //generate the ShaderClass
            edk::GU_GLSL::ShaderClass shader;
            shader.threadID = threadID;
            shader.type = GU_GLSL_PROGRAM;

            edk::uint32 ret=0u;

            edk::GU_GLSL::mutCreateShader.lock();
            //add the shader in to the queue
            edk::GU_GLSL::genShaders.pushBack(shader);
            edk::GU_GLSL::mutCreateShader.unlock();

            bool run=true;
            //wait to get the shader ID
            while(run){
                edk::GU_GLSL::mutCreateShader.lock();
                //test if have some textures in the tree
                if(edk::GU_GLSL::treeShaders.size()){
                    //tes if have the texture inside the tree
                    if(edk::GU_GLSL::treeShaders.haveShaderByThread(threadID)){
                        //get the texture
                        shader = edk::GU_GLSL::treeShaders.getShaderByThread(threadID);
                        edk::GU_GLSL::treeShaders.remove(shader);
                        ret=shader.id;
                        run=false;
                    }
                }
                //test if can't load the texture
                if(!edk::GU_GLSL::canLoadShader){
                    if(ret){
                        edk::GU_GLSL::guDeleteProgram(ret);
                    }
                    ret=0u;
                    run=false;
                }
                edk::GU_GLSL::mutCreateShader.unlock();
                if(run){
                    //sleep this thread
                    edk::watch::Time::sleepProcessMiliseconds(10u);
                }
            }
            return ret;
        }
    }
    edk::GU_GLSL::mut.unlock();
    return ret;
}
bool edk::GU_GLSL::guProgramUseShader(edk::uint32 id,edk::uint32 shaderId){
    bool ret=false;
    if(edk::multi::Thread::isThisThreadMain()){
        edk::GU_GLSL::mut.lock();
        glAttachShader(id,shaderId);
        edk::GU_GLSL::mut.unlock();
        ret = true;
    }
    else{
        //start a new class in the tree to the mainThread load the shader
#if __x86_64__ || __ppc64__
        edk::uint64 threadID = edk::multi::Thread::getThisThreadID();
#else
        edk::uint32 threadID = edk::multi::Thread::getThisThreadID();
#endif
        if(threadID){
            //generate the ProgramClass
            edk::GU_GLSL::ProgramAttachClass program;
            program.threadID = threadID;
            program.id=id;
            program.shaderId=shaderId;

            edk::GU_GLSL::mutCreateShader.lock();
            //add the program in to the queue
            edk::GU_GLSL::genProgramsAttach.pushBack(program);
            edk::GU_GLSL::mutCreateShader.unlock();

            bool run=true;
            //wait to get the Program ID
            while(run){
                edk::GU_GLSL::mutCreateShader.lock();
                //test if have some textures in the tree
                if(edk::GU_GLSL::treeProgramsAttach.size()){
                    //tes if have the texture inside the tree
                    if(edk::GU_GLSL::treeProgramsAttach.haveProgramAttachByThread(threadID)){
                        //get the texture
                        program = edk::GU_GLSL::treeProgramsAttach.getProgramAttachByThread(threadID);
                        edk::GU_GLSL::treeProgramsAttach.remove(program);
                        ret = program.success;
                        run=false;
                    }
                }
                //test if can't load the progam
                if(!edk::GU_GLSL::canLoadShader){
                    edk::GU_GLSL::guDeleteProgram(program.id);
                    run=false;
                }
                edk::GU_GLSL::mutCreateShader.unlock();
                if(run){
                    //sleep this thread
                    edk::watch::Time::sleepProcessMiliseconds(10u);
                }
            }
        }
    }
    return ret;
}
void edk::GU_GLSL::guProgramRemoveShader(edk::uint32 id,edk::uint32 shaderId){
    edk::GU_GLSL::mut.lock();
    glDetachShader(id,shaderId);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guDeleteProgram(edk::uint32 id){
    edk::GU_GLSL::mut.lock();
    glDeleteProgram(id);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guLinkProgram(edk::uint32 programID){
    if(edk::multi::Thread::isThisThreadMain()){
        edk::GU_GLSL::mut.lock();
        glLinkProgram(programID);
        edk::GU_GLSL::mut.unlock();
    }
    else{
        //start a new class in the tree to the mainThread load the shader
#if __x86_64__ || __ppc64__
        edk::uint64 threadID = edk::multi::Thread::getThisThreadID();
#else
        edk::uint32 threadID = edk::multi::Thread::getThisThreadID();
#endif
        if(threadID){
            //generate the ProgramClass
            edk::GU_GLSL::ProgramLinkClass program;
            program.threadID = threadID;
            program.programID=programID;

            edk::GU_GLSL::mutCreateShader.lock();
            //add the program in to the queue
            edk::GU_GLSL::genProgramsLink.pushBack(program);
            edk::GU_GLSL::mutCreateShader.unlock();

            bool run=true;
            //wait to get the Program ID
            while(run){
                edk::GU_GLSL::mutCreateShader.lock();
                //test if have some textures in the tree
                if(edk::GU_GLSL::treeProgramsLink.size()){
                    //tes if have the texture inside the tree
                    if(edk::GU_GLSL::treeProgramsLink.haveProgramLinkByThread(threadID)){
                        //get the texture
                        program = edk::GU_GLSL::treeProgramsLink.getProgramLinkByThread(threadID);
                        edk::GU_GLSL::treeProgramsLink.remove(program);
                        run=false;
                    }
                }
                //test if can't load the progam
                if(!edk::GU_GLSL::canLoadShader){
                    edk::GU_GLSL::guDeleteProgram(program.programID);
                    run=false;
                }
                edk::GU_GLSL::mutCreateShader.unlock();
                if(run){
                    //sleep this thread
                    edk::watch::Time::sleepProcessMiliseconds(10u);
                }
            }
        }
    }
}
void edk::GU_GLSL::guUseProgram(edk::uint32 programID){
    if(edk::multi::Thread::isThisThreadMain()){
        edk::GU_GLSL::mut.lock();
        glUseProgram(programID);
        edk::GU_GLSL::mut.unlock();
    }
    else{

#if __x86_64__ || __ppc64__
        edk::uint64 threadID = edk::multi::Thread::getThisThreadID();
#else
        edk::uint32 threadID = edk::multi::Thread::getThisThreadID();
#endif
        if(threadID){
            edk::GU_GLSL::ShaderUseClass shader;
            shader.id=programID;
            shader.threadID = threadID;
            //test if gonna use shader
            if(shader.id){
                edk::GU_GLSL::mutUseShader.lock();
                //add the tex in to the queue
                edk::GU_GLSL::useShaders.pushBack(shader);
                edk::GU_GLSL::mutUseShader.unlock();

                bool run=true;
                //wait to get the texture ID
                while(run){
                    edk::GU_GLSL::mutUseShader.lock();
                    //test if have some textures in the tree
                    if(edk::GU_GLSL::treeUseShaders.size()){
                        //tes if have the texture inside the tree
                        if(edk::GU_GLSL::treeUseNoShaders.haveShaderByThread(threadID)){
                            //get the texture
                            shader = edk::GU_GLSL::treeUseShaders.getShaderByThread(threadID);
                            edk::GU_GLSL::treeUseShaders.remove(shader);
                            run=false;
                        }
                    }
                    edk::GU_GLSL::mutUseShader.unlock();
                    if(run){
                        //sleep this thread
                        edk::watch::Time::sleepProcessMiliseconds(1u);
                    }
                }
            }
            //else this gonna useNo shader
            else{
                edk::GU_GLSL::mutUseNoShader.lock();
                //add the tex in to the queue
                edk::GU_GLSL::useNoShaders.pushBack(shader);
                edk::GU_GLSL::mutUseNoShader.unlock();

                bool run=true;
                //wait to get the texture ID
                while(run){
                    edk::GU_GLSL::mutUseNoShader.lock();
                    //test if have some textures in the tree
                    if(edk::GU_GLSL::treeUseNoShaders.size()){
                        //tes if have the texture inside the tree
                        if(edk::GU_GLSL::treeUseNoShaders.haveShaderByThread(threadID)){
                            //get the texture
                            shader = edk::GU_GLSL::treeUseNoShaders.getShaderByThread(threadID);
                            edk::GU_GLSL::treeUseNoShaders.remove(shader);
                            run=false;
                        }
                    }
                    edk::GU_GLSL::mutUseNoShader.unlock();
                    if(run){
                        //sleep this thread
                        edk::watch::Time::sleepProcessMiliseconds(1u);
                    }
                }
            }
        }
    }
}

void edk::GU_GLSL::guData1i32(edk::int32 id,edk::int32 d0){
    edk::GU_GLSL::mut.lock();
    glUniform1i(id,d0);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData2i32(edk::int32 id,edk::vec2i32 d){
    edk::GU_GLSL::mut.lock();
    glUniform2i(id,d.x,d.y);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData2i32(edk::int32 id,edk::int32 d0,edk::int32 d1){
    edk::GU_GLSL::mut.lock();
    glUniform2i(id,d0,d1);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData3i32(edk::int32 id,edk::vec3i32 d){
    edk::GU_GLSL::mut.lock();
    glUniform3i(id,d.x,d.y,d.z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData3i32(edk::int32 id,edk::int32 d0,edk::int32 d1,edk::int32 d2){
    edk::GU_GLSL::mut.lock();
    glUniform3i(id,d0,d1,d2);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData4i32(edk::int32 id,edk::vec4i32 d){
    edk::GU_GLSL::mut.lock();
    glUniform4i(id,d.x,d.y,d.z,d.w);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData4i32(edk::int32 id,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3){
    edk::GU_GLSL::mut.lock();
    glUniform4i(id,d0,d1,d2,d3);
    edk::GU_GLSL::mut.unlock();
}

void edk::GU_GLSL::guData1f32(edk::int32 id,edk::float32 d0){
    edk::GU_GLSL::mut.lock();
    glUniform1f(id,d0);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData2f32(edk::int32 id,edk::vec2f32 d){
    edk::GU_GLSL::mut.lock();
    glUniform2f(id,d.x,d.y);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData2f32(edk::int32 id,edk::float32 d0,edk::float32 d1){
    edk::GU_GLSL::mut.lock();
    glUniform2f(id,d0,d1);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData3f32(edk::int32 id,edk::vec3f32 d){
    edk::GU_GLSL::mut.lock();
    glUniform3f(id,d.x,d.y,d.z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData3f32(edk::int32 id,edk::float32 d0,edk::float32 d1,edk::float32 d2){
    edk::GU_GLSL::mut.lock();
    glUniform3f(id,d0,d1,d2);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData4f32(edk::int32 id,edk::vec4f32 d){
    edk::GU_GLSL::mut.lock();
    glUniform4f(id,d.x,d.y,d.z,d.w);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guData4f32(edk::int32 id,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3){
    edk::GU_GLSL::mut.lock();
    glUniform4f(id,d0,d1,d2,d3);
    edk::GU_GLSL::mut.unlock();
}

//MATRICES
void edk::GU_GLSL::guMatrix2f32(edk::int32 id,edk::float32* mat){
    edk::GU_GLSL::mut.lock();
    glUniformMatrix2fv(id,1u, false,mat);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guMatrix3f32(edk::int32 id,edk::float32* mat){
    edk::GU_GLSL::mut.lock();
    glUniformMatrix3fv(id,1u, false,mat);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guMatrix4f32(edk::int32 id,edk::float32* mat){
    edk::GU_GLSL::mut.lock();
    glUniformMatrix4fv(id,1u, false,mat);
    edk::GU_GLSL::mut.unlock();
}

bool edk::GU_GLSL::guReadTexture(edk::uint32 ID,edk::uint32 format,const edk::classID  data){
    //test the ID
    if(ID){
        edk::GU_GLSL::mut.lock();
        //Set using texture
        glBindTexture(GL_TEXTURE_2D,ID);
        //
        glGetTexImage(GL_TEXTURE_2D,
                      0u,
                      format,
                      GL_UNSIGNED_BYTE,
                      data
                      );
        //Clean use texture
        glBindTexture(GL_TEXTURE_2D, 0u);
        edk::GU_GLSL::mut.unlock();
        return true;
    }
    return false;
}
/*
void edk::GU_GLSL::guVertexData1i32(edk::int32 id,edk::int32 d0){glVertexAttrib1i(id,d0);}
void edk::GU_GLSL::guVertexData2i32(edk::int32 id,edk::vec2i32 d){glVertexAttrib2i(id,d.x,d.y);}
void edk::GU_GLSL::guVertexData2i32(edk::int32 id,edk::int32 d0,edk::int32 d1){glVertexAttrib2i(id,d0,d1);}
void edk::GU_GLSL::guVertexData3i32(edk::int32 id,edk::vec3i32 d){glVertexAttrib3i(id,d.x,d.y,d.z);}
void edk::GU_GLSL::guVertexData3i32(edk::int32 id,edk::int32 d0,edk::int32 d1,edk::int32 d2){glVertexAttrib3i(id,d0,d1,d2);}
void edk::GU_GLSL::guVertexData4i32(edk::int32 id,edk::vec4i32 d){glVertexAttrib4i(id,d.x,d.y,d.z,d.w);}
void edk::GU_GLSL::guVertexData4i32(edk::int32 id,edk::int32 d0,edk::int32 d1,edk::int32 d2,edk::int32 d3){glVertexAttrib4i(id,d0,d1,d2,d3);}
*/
void edk::GU_GLSL::guVertexData1f32(edk::int32 id,edk::float32 d0){
    edk::GU_GLSL::mut.lock();
    glVertexAttrib1f(id,d0);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexData2f32(edk::int32 id,edk::vec2f32 d){
    edk::GU_GLSL::mut.lock();
    glVertexAttrib2f(id,d.x,d.y);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexData2f32(edk::int32 id,edk::float32 d0,edk::float32 d1){
    edk::GU_GLSL::mut.lock();
    glVertexAttrib2f(id,d0,d1);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexData3f32(edk::int32 id,edk::vec3f32 d){
    edk::GU_GLSL::mut.lock();
    glVertexAttrib3f(id,d.x,d.y,d.z);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexData3f32(edk::int32 id,edk::float32 d0,edk::float32 d1,edk::float32 d2){
    edk::GU_GLSL::mut.lock();
    glVertexAttrib3f(id,d0,d1,d2);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexData4f32(edk::int32 id,edk::vec4f32 d){
    edk::GU_GLSL::mut.lock();
    glVertexAttrib4f(id,d.x,d.y,d.z,d.w);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexData4f32(edk::int32 id,edk::float32 d0,edk::float32 d1,edk::float32 d2,edk::float32 d3){
    edk::GU_GLSL::mut.lock();
    glVertexAttrib4f(id,d0,d1,d2,d3);
    edk::GU_GLSL::mut.unlock();
}

//return the data location
edk::int32 edk::GU_GLSL::guGetDataLocation(edk::uint32 program, const edk::char8 *name){
    edk::int32 ret;
    edk::GU_GLSL::mut.lock();
    ret = glGetUniformLocation(program,name);
    edk::GU_GLSL::mut.unlock();
    return ret;
}
edk::int32 edk::GU_GLSL::guGetDataLocation(edk::uint32 program, edk::char8* name){
    edk::int32 ret;
    edk::GU_GLSL::mut.lock();
    ret = glGetUniformLocation(program,(const edk::char8*)name);
    edk::GU_GLSL::mut.unlock();
    return ret;
}
//return the vertexData location
edk::int32 edk::GU_GLSL::guGetVertexDataLocation(edk::uint32 program, const edk::char8 *name){
    edk::int32 ret;
    edk::GU_GLSL::mut.lock();
    ret = glGetAttribLocation(program,name);
    edk::GU_GLSL::mut.unlock();
    return ret;
}
edk::int32 edk::GU_GLSL::guGetVertexDataLocation(edk::uint32 program, edk::char8* name){
    edk::int32 ret;
    edk::GU_GLSL::mut.lock();
    ret = glGetAttribLocation(program,(const edk::char8*)name);
    edk::GU_GLSL::mut.unlock();
    return ret;
}

//Errors
edk::char8* edk::GU_GLSL::guGetErrorString(edk::int32 error){
    edk::char8* ret;
    edk::GU_GLSL::mut.lock();
    ret = (edk::char8*)glewGetErrorString(error);
    edk::GU_GLSL::mut.unlock();
    return ret;
}
//glewGetString(GLEW_VERSION)
//edk::char8* edk::GU_GLSL::glewGetString(edk::int32 version){return (edk::char8*)glewGetString(version);}

//If it crash. Dont forget to init the shader
void edk::GU_GLSL::guActiveTexture(edk::uint32 texture){
    //if(edk::GU_GLSL::initiate){
    edk::GU_GLSL::mut.lock();
    glActiveTexture(texture);
    edk::GU_GLSL::mut.unlock();
    //}
}

//BUFFERS
//alloc Buffer
edk::uint32 edk::GU_GLSL::guAllocBuffer(edk::uint32 type){
    edk::uint32 ret = 0u;
    if(edk::GU_GLSL::guShaderInitiated() &&
            (
                type == GU_ARRAY_BUFFER
                || type == GU_ATOMIC_COUNTER_BUFFER
                || type == GU_COPY_READ_BUFFER
                || type == GU_COPY_WRITE_BUFFER
                || type == GU_DISPATCH_INDIRECT_BUFFER
                || type == GU_DRAW_INDIRECT_BUFFER
                || type == GU_ELEMENT_ARRAY_BUFFER
                || type == GU_PIXEL_PACK_BUFFER
                || type == GU_PIXEL_UNPACK_BUFFER
                || type == GU_QUERY_BUFFER
                || type == GU_SHADER_STORAGE_BUFFER
                || type == GU_TEXTURE_BUFFER
                || type == GU_TRANSFORM_FEEDBACK_BUFFER
                || type == GU_UNIFORM_BUFFER
                )
            ){
        edk::GU_GLSL::mut.lock();
        glGenBuffers(1, &ret);
        if(ret){
            glBindBuffer(type, ret);
        }
        edk::GU_GLSL::mut.unlock();
    }
    return ret;
}
//use Buffer
void edk::GU_GLSL::guUseBuffer(edk::uint32 type,edk::uint32 ID){
    edk::GU_GLSL::mut.lock();
    glBindBuffer(type, ID);
    edk::GU_GLSL::mut.unlock();
}
//do not use Buffer
void edk::GU_GLSL::guDontUseBuffer(edk::uint32 type){
    edk::GU_GLSL::mut.lock();
    glBindBuffer(type, 0u);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guDontUseAllBuffer(){
    edk::GU_GLSL::mut.lock();
    glBindBuffer(GU_FRAMEBUFFER,0u);
    glBindBuffer(GU_DRAW_FRAMEBUFFER,0u);
    glBindBuffer(GU_READ_FRAMEBUFFER,0u);
    edk::GU_GLSL::mut.unlock();
}
//map/unmap the buffer
edk::classID edk::GU_GLSL::guMapBuffer(edk::uint32 type,edk::uint32 access){
    edk::classID ret = NULL;
    edk::GU_GLSL::mut.lock();
    ret = glMapBuffer(type,access);
    edk::GU_GLSL::mut.unlock();
    return ret;
}
//unmap the buffer
void edk::GU_GLSL::guUnmapBuffer(edk::uint32 type){
    edk::GU_GLSL::mut.lock();
    glUnmapBuffer(type);
    edk::GU_GLSL::mut.unlock();
}
//delete the Buffer
void edk::GU_GLSL::guDeleteBuffer(edk::uint32 ID){
    edk::GU_GLSL::mut.lock();
    glDeleteBuffers(1u,&ID);
    edk::GU_GLSL::mut.unlock();
}
//add the buffer in to the vbo
bool edk::GU_GLSL::guBufferData(edk::uint32 type, edk::uint64 size, const edk::classID data, edk::uint32 usage){
    if(/*data && */size){
        edk::GU_GLSL::mut.lock();
        glBufferData(type, size, data,usage);
        edk::GU_GLSL::mut.unlock();
        return true;
    }
    return false;
}
void edk::GU_GLSL::guEnableClientState(edk::uint32 cap){
    edk::GU_GLSL::mut.lock();
    glEnableClientState(cap);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guDisableClientState(edk::uint32 cap){
    edk::GU_GLSL::mut.lock();
    glDisableClientState(cap);
    edk::GU_GLSL::mut.unlock();
}


//generateVertexArray
edk::uint32 edk::GU_GLSL::guAllocVertexArray(){
    edk::uint32 ret = 0u;
    if(edk::GU_GLSL::guShaderInitiated()){
        edk::GU_GLSL::mut.lock();
        glGenVertexArrays(1, &ret);
        if(ret){
            glBindVertexArray(ret);
        }
        edk::GU_GLSL::mut.unlock();
    }
    return ret;
}
void edk::GU_GLSL::guUseVertexArray(edk::uint32 ID){
    edk::GU_GLSL::mut.lock();
    glBindVertexArray(ID);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guDontUseVertexArray(){
    edk::GU_GLSL::mut.lock();
    glBindVertexArray(0u);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guDeleteVertexArray(edk::uint32 ID){
    edk::GU_GLSL::mut.lock();
    glDeleteVertexArrays(1u,&ID);
    edk::GU_GLSL::mut.unlock();
}

//Use a TextCoord from a pointer
void edk::GU_GLSL::guTexCoordPointer1i16(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(1, GL_SHORT,jump*sizeof(edk::int16),(edk::classID)(position*sizeof(edk::int16)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer2i16(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(2, GL_SHORT,jump*sizeof(edk::int16),(edk::classID)(position*sizeof(edk::int16)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer3i16(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(3, GL_SHORT,jump*sizeof(edk::int16),(edk::classID)(position*sizeof(edk::int16)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer4i16(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(4, GL_SHORT,jump*sizeof(edk::int16),(edk::classID)(position*sizeof(edk::int16)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer1i32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(1, GL_INT,jump*sizeof(edk::int32),(edk::classID)(position*sizeof(edk::int32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer2i32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(2, GL_INT,jump*sizeof(edk::int32),(edk::classID)(position*sizeof(edk::int32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer3i32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(3, GL_INT,jump*sizeof(edk::int32),(edk::classID)(position*sizeof(edk::int32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer4i32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(4, GL_INT,jump*sizeof(edk::int32),(edk::classID)(position*sizeof(edk::int32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer1f32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(1, GL_FLOAT,jump*sizeof(edk::float32),(edk::classID)(position*sizeof(edk::float32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer2f32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(2, GL_FLOAT,jump*sizeof(edk::float32),(edk::classID)(position*sizeof(edk::float32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer3f32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(3, GL_FLOAT,jump*sizeof(edk::float32),(edk::classID)(position*sizeof(edk::float32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer4f32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(4, GL_FLOAT,jump*sizeof(edk::float32),(edk::classID)(position*sizeof(edk::float32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer1f64(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(1, GL_DOUBLE,jump*sizeof(edk::float64),(edk::classID)(position*sizeof(edk::float64)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer2f64(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(2, GL_DOUBLE,jump*sizeof(edk::float64),(edk::classID)(position*sizeof(edk::float64)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer3f64(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(3, GL_DOUBLE,jump*sizeof(edk::float64),(edk::classID)(position*sizeof(edk::float64)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guTexCoordPointer4f64(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glTexCoordPointer(4, GL_DOUBLE,jump*sizeof(edk::float64),(edk::classID)(position*sizeof(edk::float64)));
    edk::GU_GLSL::mut.unlock();
}


void edk::GU_GLSL::guColorPointer3ui8(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glColorPointer(3, GL_UNSIGNED_BYTE,jump*sizeof(edk::uint8),(edk::classID)(position*sizeof(edk::uint8)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer4ui8(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glColorPointer(4, GL_UNSIGNED_BYTE,jump*sizeof(edk::uint8),(edk::classID)(position*sizeof(edk::uint8)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer3i8(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glColorPointer(3, GL_BYTE,jump*sizeof(edk::int8),(edk::classID)(position*sizeof(edk::int8)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer4i8(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glColorPointer(4, GL_BYTE,jump*sizeof(edk::int8),(edk::classID)(position*sizeof(edk::int8)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer3ui16(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glColorPointer(3, GL_UNSIGNED_SHORT,jump*sizeof(edk::uint16),(edk::classID)(position*sizeof(edk::uint16)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer4ui16(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glColorPointer(4, GL_UNSIGNED_SHORT,jump*sizeof(edk::uint16),(edk::classID)(position*sizeof(edk::uint16)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer3i16(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glColorPointer(3, GL_SHORT,jump*sizeof(edk::int16),(edk::classID)(position*sizeof(edk::int16)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer4i16(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glColorPointer(4, GL_SHORT,jump*sizeof(edk::int16),(edk::classID)(position*sizeof(edk::int16)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer3ui32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glColorPointer(3, GL_UNSIGNED_INT,jump*sizeof(edk::uint32),(edk::classID)(position*sizeof(edk::uint32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer4ui32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glColorPointer(4, GL_UNSIGNED_INT,jump*sizeof(edk::uint32),(edk::classID)(position*sizeof(edk::uint32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer3i32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glColorPointer(3, GL_INT,jump*sizeof(edk::int32),(edk::classID)(position*sizeof(edk::int32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer4i32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glColorPointer(4, GL_INT,jump*sizeof(edk::int32),(edk::classID)(position*sizeof(edk::int32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer3f32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glColorPointer(3, GL_FLOAT,jump*sizeof(edk::float32),(edk::classID)(position*sizeof(edk::float32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer4f32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glColorPointer(4, GL_FLOAT,jump*sizeof(edk::float32),(edk::classID)(position*sizeof(edk::float32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer3f64(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glColorPointer(3, GL_DOUBLE,jump*sizeof(edk::float64),(edk::classID)(position*sizeof(edk::float64)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guColorPointer4f64(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glColorPointer(4, GL_DOUBLE,jump*sizeof(edk::float64),(edk::classID)(position*sizeof(edk::float64)));
    edk::GU_GLSL::mut.unlock();
}

//use a Normal from a pointer
void edk::GU_GLSL::guNormalPointerI8(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glNormalPointer(GL_BYTE,jump*sizeof(edk::int8),(edk::classID)(position*sizeof(edk::int8)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guNormalPointerI16(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glNormalPointer(GL_SHORT,jump*sizeof(edk::int16),(edk::classID)(position*sizeof(edk::int16)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guNormalPointerI32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glNormalPointer(GL_INT,jump*sizeof(edk::int32),(edk::classID)(position*sizeof(edk::int32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guNormalPointerF32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glNormalPointer(GL_FLOAT,jump*sizeof(edk::float32),(edk::classID)(position*sizeof(edk::float32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guNormalPointerF64(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glNormalPointer(GL_DOUBLE,jump*sizeof(edk::float64),(edk::classID)(position*sizeof(edk::float64)));
    edk::GU_GLSL::mut.unlock();
}

//use a vertex from a pointer
void edk::GU_GLSL::guVertexPointer2i16(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(2, GL_SHORT,jump*sizeof(edk::int16),(edk::classID)(position*sizeof(edk::int16)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer2i32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(2, GL_INT,jump*sizeof(edk::int32),(edk::classID)(position*sizeof(edk::int32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer2f32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(2, GL_FLOAT,jump*sizeof(edk::float32),(edk::classID)(position*sizeof(edk::float32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer2f64(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(2, GL_DOUBLE,jump*sizeof(edk::float64),(edk::classID)(position*sizeof(edk::float64)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer3i16(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(3, GL_SHORT,jump*sizeof(edk::int16),(edk::classID)(position*sizeof(edk::int16)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer3i32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(3, GL_INT,jump*sizeof(edk::int32),(edk::classID)(position*sizeof(edk::int32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer3f32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(3, GL_FLOAT,jump*sizeof(edk::float32),(edk::classID)(position*sizeof(edk::float32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer3f64(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(3, GL_DOUBLE,jump*sizeof(edk::float64),(edk::classID)(position*sizeof(edk::float64)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer4i16(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(4, GL_SHORT,jump*sizeof(edk::int16),(edk::classID)(position*sizeof(edk::int16)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer4i32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(4, GL_INT,jump*sizeof(edk::int32),(edk::classID)(position*sizeof(edk::int32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer4f32(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(4, GL_FLOAT,jump*sizeof(edk::float32),(edk::classID)(position*sizeof(edk::float32)));
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guVertexPointer4f64(edk::uint64 position,edk::uint64 jump){
    edk::GU_GLSL::mut.lock();
    glVertexPointer(4, GL_DOUBLE,jump*sizeof(edk::float64),(edk::classID)(position*sizeof(edk::float64)));
    edk::GU_GLSL::mut.unlock();
}

//draw the array from a pointer
void edk::GU_GLSL::guDrawArrays(edk::uint32 mode,edk::int32 first,edk::uint64 count){
    edk::GU_GLSL::mut.lock();
    glDrawArrays(mode,first,count);
    edk::GU_GLSL::mut.unlock();
}

//Check Buffer
//edk::uint32 edk::GU_GLSL::guCheckBufferStatus(edk::uint32 type){
//    edk::uint32 ret;
//    edk::GU_GLSL::mut.lock();
//    ret = glCheckBufferStatus(type);
//    edk::GU_GLSL::mut.unlock();
//    return ret;
//}
//bool edk::GU_GLSL::guCheckBufferOK(edk::uint32 type){
//    if(edk::GU_GLSL::guCheckBufferStatus(type) == GU_FRAMEBUFFER_COMPLETE){
//        return true;
//    }
//    return false;
//}

//FRAMEBUFFERS
//alloc frameBuffer
edk::uint32 edk::GU_GLSL::guAllocFrameBuffer(edk::uint32 type){
    edk::uint32 ret = 0u;
    if(type == GU_FRAMEBUFFER || type == GU_DRAW_FRAMEBUFFER || type == GU_READ_FRAMEBUFFER){
        edk::GU_GLSL::mut.lock();
        glGenFramebuffers(1, &ret);
        if(ret){
            glBindFramebuffer(type, ret);
        }
        edk::GU_GLSL::mut.unlock();
    }
    return ret;
}
//use FrameBuffer
void edk::GU_GLSL::guUseFrameBuffer(edk::uint32 type,edk::uint32 ID){
    edk::GU_GLSL::mut.lock();
    glBindFramebuffer(type, ID);
    edk::GU_GLSL::mut.unlock();
}
//do not use FrameBuffer
void edk::GU_GLSL::guDontUseFrameBuffer(edk::uint32 type){
    edk::GU_GLSL::mut.lock();
    glBindFramebuffer(type, 0u);
    edk::GU_GLSL::mut.unlock();
}
void edk::GU_GLSL::guDontUseAllFrameBuffer(){
    edk::GU_GLSL::mut.lock();
    glBindFramebuffer(GU_FRAMEBUFFER,0u);
    glBindFramebuffer(GU_DRAW_FRAMEBUFFER,0u);
    glBindFramebuffer(GU_READ_FRAMEBUFFER,0u);
    edk::GU_GLSL::mut.unlock();
}
//delete the frameBuffer
void edk::GU_GLSL::guDeleteFrameBuffer(edk::uint32 ID){
    edk::GU_GLSL::mut.lock();
    glDeleteFramebuffers(1u,&ID);
    edk::GU_GLSL::mut.unlock();
}
//use the frameBuffer to the texture
void edk::GU_GLSL::guFrameBufferTexture(edk::uint32 target, edk::uint32 attachment, edk::uint32 texture, edk::uint32 mipmapLevel){
    edk::GU_GLSL::mut.lock();
    glFramebufferTexture(target,attachment,texture,mipmapLevel);
    edk::GU_GLSL::mut.unlock();
}
//Set list of drawBuffers
bool edk::GU_GLSL::guSetDrawBuffers(edk::uint32 size,const edk::uint32 *buffers){
    if(size && buffers){
        edk::GU_GLSL::mut.lock();
        glDrawBuffers(size,buffers);
        edk::GU_GLSL::mut.unlock();
        return true;
    }
    //else draw NONE
    edk::GU_GLSL::mut.lock();
    glDrawBuffer(GL_NONE);
    edk::GU_GLSL::mut.unlock();
    return false;
}
//set one drawBuffer
bool edk::GU_GLSL::guSetDrawBuffer(edk::uint32 buffer){
    bool ret=false;
    if(buffer){
        edk::uint32 buffers[1u] = {buffer};
        ret = edk::GU_GLSL::guSetDrawBuffers(1u,buffers);
    }
    else{
        ret = edk::GU_GLSL::guSetDrawBuffers(0u,NULL);
    }
    return ret;
}
//Check frameBuffer
edk::uint32 edk::GU_GLSL::guCheckFrameBufferStatus(edk::uint32 target){
    edk::uint32 ret;
    edk::GU_GLSL::mut.lock();
    ret = glCheckFramebufferStatus(target);
    edk::GU_GLSL::mut.unlock();
    return ret;
}
bool edk::GU_GLSL::guCheckFrameBufferOK(edk::uint32 target){
    if(edk::GU_GLSL::guCheckFrameBufferStatus(target) == GU_FRAMEBUFFER_COMPLETE){
        return true;
    }
    return false;
}



//RENDERBUFFERS
//alloc renderBuffer
edk::uint32 edk::GU_GLSL::guAllocRenderBuffer(){
    edk::uint32 ret = 0u;
    edk::GU_GLSL::mut.lock();
    glGenRenderbuffers(1, &ret);
    if(ret){
        glBindRenderbuffer(GL_RENDERBUFFER, ret);
    }
    edk::GU_GLSL::mut.unlock();
    return ret;
}
//use RenderBuffer
void edk::GU_GLSL::guUseRenderBuffer(edk::uint32 ID){
    edk::GU_GLSL::mut.lock();
    glBindRenderbuffer(GL_RENDERBUFFER, ID);
    edk::GU_GLSL::mut.unlock();
}
//do not use RenderBuffer
void edk::GU_GLSL::guDontUseRenderBuffer(){
    edk::GU_GLSL::mut.lock();
    glBindRenderbuffer(GL_RENDERBUFFER, 0u);
    edk::GU_GLSL::mut.unlock();
}
//delete the RenderBuffer
void edk::GU_GLSL::guDeleteRenderBuffer(edk::uint32 ID){
    edk::GU_GLSL::mut.lock();
    glDeleteRenderbuffers(1u,&ID);
    edk::GU_GLSL::mut.unlock();
}
//use the RenderBuffer to the texture
//void edk::GU_GLSL::guRenderBufferTexture(edk::uint32 type, edk::uint32 attachment, edk::uint32 texture, edk::uint32 mipmapLevel){
//    edk::GU_GLSL::mut.lock();
//    glRenderbufferTexture(type,attachment,texture,mipmapLevel);
//    edk::GU_GLSL::mut.unlock();
//}
//Check RenderBuffer
//edk::uint32 edk::GU_GLSL::guCheckRenderbufferStatus(edk::uint32 type){
//    edk::uint32 ret;
//    edk::GU_GLSL::mut.lock();
//    ret = glCheckRenderbufferStatus(type);
//    edk::GU_GLSL::mut.unlock();
//    return ret;
//}
//bool edk::GU_GLSL::guCheckRenderBufferOK(edk::uint32 type){
//    if(edk::GU_GLSL::guCheckRenderBufferStatus(type) == GU_FRAMEBUFFER_COMPLETE){
//        return true;
//    }
//    return false;
//}

//run function to create the shaders for other threads
bool edk::GU_GLSL::guUpdateCreateShaders(){
    bool ret=false;
    if(edk::multi::Thread::isThisThreadMain()){
        edk::uint32 size;
        //test if it's the main thread
        edk::GU_GLSL::mutUseNoShader.lock();
        size = edk::GU_GLSL::useNoShaders.size();
        if(size){
            edk::GU_GLSL::ShaderUseClass shaderID;
            for(edk::uint32 i=0u;i<size;i++){
                //get the tex
                shaderID = edk::GU_GLSL::useNoShaders.popFront();
                if(!i){
                    edk::GU_GLSL::guUseProgram(0u);

                    //add the useNoShaderTree
                    edk::GU_GLSL::treeUseNoShaders.add(shaderID);
                }
            }
            ret = true;
        }
        edk::GU_GLSL::mutUseNoShader.unlock();

        //test if it's the main thread
        edk::GU_GLSL::mutDelShader.lock();
        size = edk::GU_GLSL::delShaders.size();
        edk::GU_GLSL::mutDelShader.unlock();
        if(size){
            if(size>2u){
                size=2u;
            }
            edk::uint32 shaderID=0u;
            for(edk::uint32 i=1u;i<size;i++){
                //get the tex
                edk::GU_GLSL::mutDelShader.lock();
                shaderID = edk::GU_GLSL::delShaders.popFront();
                edk::GU_GLSL::guDeleteShader(shaderID);
                edk::GU_GLSL::mutDelShader.unlock();
            }
            ret = true;
        }

        //test if it's the main thread
        edk::GU_GLSL::mutCreateShader.lock();
        size = edk::GU_GLSL::genShaders.size();
        edk::GU_GLSL::mutCreateShader.unlock();
        if(size){
            if(size>2u){
                size=2u;
            }
            edk::GU_GLSL::ShaderClass shader;
            for(edk::uint32 i=0u;i<size;i++){
                //get the tex
                edk::GU_GLSL::mutCreateShader.lock();
                shader = edk::GU_GLSL::genShaders.popFront();
                if(!edk::GU_GLSL::canLoadShader){
                    shader.id = 0u;
                    edk::GU_GLSL::treeShaders.add(shader);
                    edk::GU_GLSL::mutCreateShader.unlock();
                    continue;
                }
                else{
                    edk::GU_GLSL::mutCreateShader.unlock();
                }
                if(shader.type == GU_GLSL_PROGRAM){
                    //load the texture
                    shader.id = edk::GU_GLSL::guCreateProgram();
                }
                else{
                    //load the texture
                    shader.id = edk::GU_GLSL::guCreateShader(shader.type);
                }
                edk::GU_GLSL::mutCreateShader.lock();
                if(!edk::GU_GLSL::canLoadShader){
                    edk::GU_GLSL::mutCreateShader.unlock();
                    edk::GU_GLSL::guDeleteShader(shader.id);
                    shader.id = 0u;
                }
                else{
                    edk::GU_GLSL::mutCreateShader.unlock();
                }

                edk::GU_GLSL::mutCreateShader.lock();
                //add the tex into the tree
                edk::GU_GLSL::treeShaders.add(shader);
                edk::GU_GLSL::mutCreateShader.unlock();
            }
            ret = true;
        }

        //test if it's the main thread
        edk::GU_GLSL::mutCreateShader.lock();
        size = edk::GU_GLSL::genShadersWrite.size();
        edk::GU_GLSL::mutCreateShader.unlock();
        if(size){
            if(size>2u){
                size=2u;
            }
            edk::GU_GLSL::ShaderWriteClass shader;
            for(edk::uint32 i=0u;i<size;i++){
                //get the tex
                edk::GU_GLSL::mutCreateShader.lock();
                shader = edk::GU_GLSL::genShadersWrite.popFront();
                if(!edk::GU_GLSL::canLoadShader){
                    shader.success=false;
                    edk::GU_GLSL::treeShadersWrite.add(shader);
                    edk::GU_GLSL::mutCreateShader.unlock();
                    continue;
                }
                else{
                    edk::GU_GLSL::mutCreateShader.unlock();
                }

                //write the shader
                shader.success = edk::GU_GLSL::guShaderSource(shader.id,shader.data,shader.length);

                edk::GU_GLSL::mutCreateShader.lock();
                if(!edk::GU_GLSL::canLoadShader){
                    edk::GU_GLSL::mutCreateShader.unlock();
                    shader.success = false;
                }
                else{
                    edk::GU_GLSL::mutCreateShader.unlock();
                }

                edk::GU_GLSL::mutCreateShader.lock();
                //add the tex into the tree
                edk::GU_GLSL::treeShadersWrite.add(shader);
                edk::GU_GLSL::mutCreateShader.unlock();
            }
            ret = true;
        }

        //test if it's the main thread
        edk::GU_GLSL::mutCreateShader.lock();
        size = edk::GU_GLSL::genShadersCompile.size();
        edk::GU_GLSL::mutCreateShader.unlock();
        if(size){
            if(size>2u){
                size=2u;
            }
            edk::GU_GLSL::ShaderCompileClass shader;
            for(edk::uint32 i=0u;i<size;i++){
                //get the tex
                edk::GU_GLSL::mutCreateShader.lock();
                shader = edk::GU_GLSL::genShadersCompile.popFront();
                if(!edk::GU_GLSL::canLoadShader){
                    edk::GU_GLSL::treeShadersCompile.add(shader);
                    edk::GU_GLSL::mutCreateShader.unlock();
                    continue;
                }
                else{
                    edk::GU_GLSL::mutCreateShader.unlock();
                }

                //write the shader
                edk::GU_GLSL::guCompileShader(shader.id);

                edk::GU_GLSL::mutCreateShader.lock();
                if(!edk::GU_GLSL::canLoadShader){
                    edk::GU_GLSL::mutCreateShader.unlock();
                }
                else{
                    edk::GU_GLSL::mutCreateShader.unlock();
                }

                edk::GU_GLSL::mutCreateShader.lock();
                //add the tex into the tree
                edk::GU_GLSL::treeShadersCompile.add(shader);
                edk::GU_GLSL::mutCreateShader.unlock();
            }
            ret = true;
        }

        //test if it's the main thread
        edk::GU_GLSL::mutCreateShader.lock();
        size = edk::GU_GLSL::genShadersIV.size();
        edk::GU_GLSL::mutCreateShader.unlock();
        if(size){
            if(size>2u){
                size=2u;
            }
            edk::GU_GLSL::ShaderIVClass shader;
            for(edk::uint32 i=0u;i<size;i++){
                //get the tex
                edk::GU_GLSL::mutCreateShader.lock();
                shader = edk::GU_GLSL::genShadersIV.popFront();
                if(!edk::GU_GLSL::canLoadShader){
                    edk::GU_GLSL::treeShadersIV.add(shader);
                    edk::GU_GLSL::mutCreateShader.unlock();
                    continue;
                }
                else{
                    edk::GU_GLSL::mutCreateShader.unlock();
                }

                if(shader.type==GU_GLSL_PROGRAM){
                    edk::GU_GLSL::guGetProgramiv(shader.id,shader.pname,shader.params);
                }
                else{
                    edk::GU_GLSL::guGetShaderiv(shader.id,shader.pname,shader.params);
                }

                edk::GU_GLSL::mutCreateShader.lock();
                if(!edk::GU_GLSL::canLoadShader){
                    edk::GU_GLSL::mutCreateShader.unlock();
                }
                else{
                    edk::GU_GLSL::mutCreateShader.unlock();
                }

                edk::GU_GLSL::mutCreateShader.lock();
                //add the tex into the tree
                edk::GU_GLSL::treeShadersIV.add(shader);
                edk::GU_GLSL::mutCreateShader.unlock();
            }
            ret = true;
        }

        //test if it's the main thread
        edk::GU_GLSL::mutCreateShader.lock();
        size = edk::GU_GLSL::genShadersLog.size();
        edk::GU_GLSL::mutCreateShader.unlock();
        if(size){
            if(size>2u){
                size=2u;
            }
            edk::GU_GLSL::ShaderLogClass shader;
            for(edk::uint32 i=0u;i<size;i++){
                //get the tex
                edk::GU_GLSL::mutCreateShader.lock();
                shader = edk::GU_GLSL::genShadersLog.popFront();
                if(!edk::GU_GLSL::canLoadShader){
                    edk::GU_GLSL::treeShadersLog.add(shader);
                    edk::GU_GLSL::mutCreateShader.unlock();
                    continue;
                }
                else{
                    edk::GU_GLSL::mutCreateShader.unlock();
                }

                if(shader.type==GU_GLSL_PROGRAM){
                    edk::GU_GLSL::guGetProgramInfoLog(shader.id,shader.maxLength,shader.length,shader.infoLog);
                }
                else{
                    edk::GU_GLSL::guGetShaderInfoLog(shader.id,shader.maxLength,shader.length,shader.infoLog);
                }

                edk::GU_GLSL::mutCreateShader.lock();
                if(!edk::GU_GLSL::canLoadShader){
                    edk::GU_GLSL::mutCreateShader.unlock();
                }
                else{
                    edk::GU_GLSL::mutCreateShader.unlock();
                }

                edk::GU_GLSL::mutCreateShader.lock();
                //add the tex into the tree
                edk::GU_GLSL::treeShadersLog.add(shader);
                edk::GU_GLSL::mutCreateShader.unlock();
            }
            ret = true;
        }

        //test if it's the main thread
        edk::GU_GLSL::mutCreateShader.lock();
        size = edk::GU_GLSL::genProgramsAttach.size();
        edk::GU_GLSL::mutCreateShader.unlock();
        if(size){
            if(size>2u){
                size=2u;
            }
            edk::GU_GLSL::ProgramAttachClass program;
            for(edk::uint32 i=0u;i<size;i++){
                //get the tex
                edk::GU_GLSL::mutCreateShader.lock();
                program = edk::GU_GLSL::genProgramsAttach.popFront();
                if(!edk::GU_GLSL::canLoadShader){
                    edk::GU_GLSL::treeProgramsAttach.add(program);
                    edk::GU_GLSL::mutCreateShader.unlock();
                    continue;
                }
                else{
                    edk::GU_GLSL::mutCreateShader.unlock();
                }

                program.success = edk::GU_GLSL::guProgramUseShader(program.id,program.shaderId);

                edk::GU_GLSL::mutCreateShader.lock();
                if(!edk::GU_GLSL::canLoadShader){
                    edk::GU_GLSL::mutCreateShader.unlock();
                }
                else{
                    edk::GU_GLSL::mutCreateShader.unlock();
                }

                edk::GU_GLSL::mutCreateShader.lock();
                //add the tex into the tree
                edk::GU_GLSL::treeProgramsAttach.add(program);
                edk::GU_GLSL::mutCreateShader.unlock();
            }
            ret = true;
        }

        //test if it's the main thread
        edk::GU_GLSL::mutCreateShader.lock();
        size = edk::GU_GLSL::genProgramsLink.size();
        edk::GU_GLSL::mutCreateShader.unlock();
        if(size){
            if(size>2u){
                size=2u;
            }
            edk::GU_GLSL::ProgramLinkClass program;
            for(edk::uint32 i=0u;i<size;i++){
                //get the tex
                edk::GU_GLSL::mutCreateShader.lock();
                program = edk::GU_GLSL::genProgramsLink.popFront();
                if(!edk::GU_GLSL::canLoadShader){
                    edk::GU_GLSL::treeProgramsLink.add(program);
                    edk::GU_GLSL::mutCreateShader.unlock();
                    continue;
                }
                else{
                    edk::GU_GLSL::mutCreateShader.unlock();
                }

                edk::GU_GLSL::guLinkProgram(program.programID);

                edk::GU_GLSL::mutCreateShader.lock();
                if(!edk::GU_GLSL::canLoadShader){
                    edk::GU_GLSL::mutCreateShader.unlock();
                }
                else{
                    edk::GU_GLSL::mutCreateShader.unlock();
                }

                edk::GU_GLSL::mutCreateShader.lock();
                //add the tex into the tree
                edk::GU_GLSL::treeProgramsLink.add(program);
                edk::GU_GLSL::mutCreateShader.unlock();
            }
            ret = true;
        }

        //test if it's the main thread
        edk::GU_GLSL::mutUseShader.lock();
        size = edk::GU_GLSL::useShaders.size();
        if(size){
            edk::GU_GLSL::ShaderUseClass shaderID;
            for(edk::uint32 i=0u;i<size;i++){
                //get the tex
                shaderID = edk::GU_GLSL::useShaders.popFront();
                if(!i){
                    edk::GU_GLSL::guUseProgram(shaderID.id);

                    //add the useShaderTree
                    edk::GU_GLSL::treeUseShaders.add(shaderID);
                }
            }
            ret = true;
        }
        edk::GU_GLSL::mutUseShader.unlock();

        //
    }
    return ret;
}

//STRING
//GL_SHADING_LANGUAGE_VERSION
//Returns a version or release number for the shading language of the form
edk::char8* edk::GU_GLSL::guGetVersion(){
    edk::char8* ret;
    edk::GU_GLSL::mut.lock();
    ret = (edk::char8*)glGetString(GL_SHADING_LANGUAGE_VERSION);
    edk::GU_GLSL::mut.unlock();
    return ret;
}
