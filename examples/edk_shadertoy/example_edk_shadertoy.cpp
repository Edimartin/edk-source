/*
Library EDK SHADERTOY - An implementation of a shadertoy like player in EDK.
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

//Include the Window
#include "edk/Window.h"
//Include the View to render Graphics
#include "edk/ViewGU2D.h"
//include the object 2D
#include "edk/Object2D.h"
//Include the argc/argv decoder
#include "edk/CommandParser.h"

//shaders
#include "edk/shd/GLSL.h"

//shader program
#define programName "shaderToyProgram"

const char *vertexShader =
        "#version 330 core\n"
        "precision mediump float;\n"
        "precision mediump int;\n"
        "layout (location = 0) in vec3 vPosition;\n"
        "layout (location = 1) in vec2 vUV;\n"
        "void main() {\n"
        "    gl_Position = vec4(vPosition, 0.0f);\n"
        "}";

const char *fragmentShaderBegin =
        "#version 330 core\n"
        "precision mediump float;\n"
        "precision mediump int;\n"
        "uniform vec3       iResolution;\n"
        "uniform float      iGlobalTime;\n"
        "uniform float      iTime;\n"
        "uniform float      iChannelTime[4];\n"
        "uniform vec4       iMouse;\n"
        "uniform vec4       iDate;\n"
        "uniform float      iSampleRate;\n"
        "uniform vec3       iChannelResolution[4];\n"
        "uniform int        iFrame;\n"
        "uniform float      iTimeDelta;\n"
        "uniform float      iFrameRate;\n"
        "struct Channel {\n"
        "   vec3    resolution;\n"
        "   float   time;\n"
        "};\n"
        "uniform Channel iChannel[4];\n";

const char *fragmentShaderEnd =
        "void main() {\n"
        "   mainImage(gl_FragColor.xyzw, gl_FragCoord.xy);\n"
        "}";

class RenderView: public edk::ViewGU2D{
public:
    RenderView(){
        this->runClose=false;
    }
    ~RenderView(){
        //clean the names
        this->names.clean();
        //clean the name
        this->shaderName.cleanName();
    }

    //get if need close the software
    bool needClose(){
        return this->runClose;
    }

    //add a name in the stack
    bool addName(edk::char8* name){
        if(name){
            //test if the image have the jpg,jpeg,JPG,JPEG or png
            if(edk::String::strCompareEnd(".jpg",name)
                    ||
                    edk::String::strCompareEnd(".jpeg",name)
                    ||
                    edk::String::strCompareEnd(".JPG",name)
                    ||
                    edk::String::strCompareEnd(".JPEG",name)
                    ||
                    edk::String::strCompareEnd(".png",name)
                    ){
                //add the name into the stack
                edk::uint32 size = this->names.size();
                this->names.pushBack(name);
                if(size<this->names.size()){
                    return true;
                }
            }
        }
        return false;
    }
    //set the shader file
    bool setShader(edk::char8* name){
        if(name){
            //test if the shaderName have the frag in the end
            if(edk::String::strCompareEnd(".frag",name)){
                //set the shader
                return this->shaderName.setName(name);
            }
            //else return false
        }
        return false;
    }
    //return true if have the shaderName
    bool haveShader(){
        return this->shaderName.haveName();
    }
    edk::char8* getShader(){
        return this->shaderName.getName();
    }

    void resize(edk::rectf32 outsideViewOrigin){
        this->frame.size = outsideViewOrigin.size;
    }
    void load(edk::rectf32){
        this->iFrame=0u;
        //
        this->shader.start();

        if(this->shaderName.haveName()){
            //create the code

            //alloc the code for textures
            edk::char8 bufferTexture[4u][sizeof("uniform sampler2D iChannel%d;\n")];

            edk::uint32 size = this->names.size();

            //load the textures
            {
                this->obj.addMesh(&this->mesh);
                edk::shape::Rectangle2D rect;
                rect.setPivoToCenter();
                this->mesh.addPolygon(rect);

                //generate the bufferTextures
                for(edk::uint8 i=0u;i<4u;i++){
                    if(i<size){
                        sprintf(bufferTexture[i], "uniform sampler2D iChannel%d;\n", i);

                        //load the texture
                        if(!this->mesh.material.loadTexture(this->names.getName(i),i)){
                            printf("\nCan't load image file '%s'",this->names.getName(i));
                            this->runClose=true;
                            break;
                        }
                    }
                    else{
                        sprintf(bufferTexture[i], "\n");
                    }
                }
            }

            if(!this->runClose){
                //load the shader file
                edk::File file;
                if(file.openTextFile(this->shaderName.getName())){
                    //load the file
                    if(file.getFileSize()){
                        edk::char8* bufferFile = new edk::char8[file.getFileSize()+1u];
                        if(bufferFile){
                            bufferFile[file.getFileSize()]='\0';
                            //read the file
                            if(file.readBin(bufferFile,file.getFileSize()) == file.getFileSize()){
                                //
                                //concat multi into the buffer
                                edk::char8* bufferShader = edk::String::strCatMulti(
                                            fragmentShaderBegin,
                                            bufferTexture[0u],
                                        bufferTexture[1u],
                                        bufferTexture[2u],
                                        bufferTexture[3u],
                                        bufferFile,
                                        "\n",
                                        fragmentShaderEnd,
                                        NULL
                                        );
                                if(bufferShader){
                                    //print the bufferShader
                                    //printf("\n\n%s\n\n",bufferShader);fflush(stdout);
                                    //load the shader
                                    if(this->shader.loadShaderFromMemory("shader.vert",(edk::uint8*)vertexShader,edk::String::strSize(vertexShader),EDK_SHADER_VERTEX)){
                                        if(this->shader.loadShaderFromMemory("shader.frag",(edk::uint8*)bufferShader,edk::String::strSize(bufferShader),EDK_SHADER_FRAGMENT)){
                                            if(this->shader.createProgram(programName)){
                                                //printf("\n%u %s %s CREATE PROGRAM",__LINE__,__FILE__,__func__);fflush(stdout);
                                            }
                                            else
                                                this->runClose=true;
                                        }
                                        else
                                            this->runClose=true;
                                    }
                                    else
                                        this->runClose=true;
                                    if(this->runClose){
                                        if(this->shader.getCompilationLog()){
                                            printf("\n%u %s %s ERROR: '%s'",__LINE__,__FILE__,__func__
                                                   ,this->shader.getCompilationLog()
                                                   );fflush(stdout);
                                            this->runClose=true;
                                        }
                                    }

                                    delete[] bufferShader;
                                }
                            }
                            else{
                                this->runClose=true;
                            }
                            delete[] bufferFile;
                        }
                    }
                }
            }
        }
        else{
            this->runClose=true;
        }
        this->obj.size = 1.f;
    }
    void unload(){
        //delete the shader
        this->shader.deleteProgram();
        this->shader.deleteShaders();

        this->obj.clean();
        this->mesh.clean();
    }
    void update(edk::WindowEvents* events){
        //
        this->clock.clockLoadLocalTime();

        this->shader.useThisShader();
        //iChannel0
        this->shader.setData1i("iChannel0",0);
        //iChannel1
        this->shader.setData1i("iChannel1",1);
        //iChannel2
        this->shader.setData1i("iChannel2",2);
        //iChannel3
        this->shader.setData1i("iChannel3",3);
        //iResolution
        this->shader.setData3f("iResolution",this->frame.size.width,this->frame.size.height,1.f);
        //iTime
        this->shader.setData1f("iTime",events->secondsGlobal);
        //iGlobalTime
        this->shader.setData1f("iGlobalTime",events->secondsGlobal);
        //iMouse
        this->shader.setData4f("iMouse"
                               ,(edk::float32)events->mousePos.x
                               ,(edk::float32)events->mousePos.y
                               ,(edk::float32)events->mousePos.x
                               ,(edk::float32)events->mousePos.y
                               );
        //iDate
        this->shader.setData4f("iDate"
                               ,(edk::float32)this->clock.clockGetYear()
                               ,(edk::float32)this->clock.clockGetMonth()
                               ,(edk::float32)this->clock.clockGetDayOfMonth()
                               ,4989.f
                               );
        //iSampleRate
        this->shader.setData1f("iSampleRate",44100.f);
        //iChannelResolution[0]
        this->shader.setData3f("iChannelResolution[0]"
                               ,(edk::float32)this->mesh.material.getTextureWidth(0u)
                               ,(edk::float32)this->mesh.material.getTextureHeight(0u)
                               ,1.f
                               );
        //iChannelResolution[1]
        this->shader.setData3f("iChannelResolution[1]"
                               ,(edk::float32)this->mesh.material.getTextureWidth(1u)
                               ,(edk::float32)this->mesh.material.getTextureHeight(1u)
                               ,1.f
                               );
        //iChannelResolution[2]
        this->shader.setData3f("iChannelResolution[2]"
                               ,(edk::float32)this->mesh.material.getTextureWidth(2u)
                               ,(edk::float32)this->mesh.material.getTextureHeight(2u)
                               ,1.f
                               );
        //iChannelResolution[3]
        this->shader.setData3f("iChannelResolution[3]"
                               ,(edk::float32)this->mesh.material.getTextureWidth(3u)
                               ,(edk::float32)this->mesh.material.getTextureHeight(3u)
                               ,1.f
                               );

        //iChannelTime[0]
        this->shader.setData1f("iChannelTime[0]",0.f);
        //iChannelTime[1]
        this->shader.setData1f("iChannelTime[1]",0.f);
        //iChannelTime[2]
        this->shader.setData1f("iChannelTime[2]",0.f);
        //iChannelTime[3]
        this->shader.setData1f("iChannelTime[3]",0.f);
        //iTimeDelta
        this->shader.setData1f("iTimeDelta",events->secondPassed);
        //iFrame
        this->shader.setData1i("iFrame",this->iFrame);
        //iFrameRate
        this->shader.setData1i("iFrameRate",0);

        //iChannel[0].resolution
        this->shader.setData3f("iChannel[0].resolution"
                               ,(edk::float32)this->mesh.material.getTextureWidth(0u)
                               ,(edk::float32)this->mesh.material.getTextureHeight(0u)
                               ,1.f
                               );
        //iChannel[1].resolution
        this->shader.setData3f("iChannel[1].resolution"
                               ,(edk::float32)this->mesh.material.getTextureWidth(1u)
                               ,(edk::float32)this->mesh.material.getTextureHeight(1u)
                               ,1.f
                               );
        //iChannel[2].resolution
        this->shader.setData3f("iChannel[2].resolution"
                               ,(edk::float32)this->mesh.material.getTextureWidth(2u)
                               ,(edk::float32)this->mesh.material.getTextureHeight(2u)
                               ,1.f
                               );
        //iChannel[3].resolution
        this->shader.setData3f("iChannel[3].resolution"
                               ,(edk::float32)this->mesh.material.getTextureWidth(3u)
                               ,(edk::float32)this->mesh.material.getTextureHeight(3u)
                               ,1.f
                               );
        //iChannel[0].time
        this->shader.setData1f("iChannel[0].time",0.f);
        //iChannel[1].time
        this->shader.setData1f("iChannel[1].time",0.f);
        //iChannel[2].time
        this->shader.setData1f("iChannel[2].time",0.f);
        //iChannel[3].time
        this->shader.setData1f("iChannel[3].time",0.f);

        this->shader.updateAllDatas();

        this->obj.draw();
        this->shader.useNoShader();
        this->iFrame++;
    }
    //render the scene in the vew
    void drawScene(edk::rectf32){
        //
        this->shader.useThisShader();

        this->shader.updateAllDatas();

        this->obj.draw();
        this->shader.useNoShader();
    }
private:
    //save if has to close the software
    bool runClose;
    //shader GLSL
    edk::shd::GLSL shader;
    //object to render the polygon
    edk::Object2D obj;
    edk::shape::Mesh2D mesh;

    //texture names
    edk::vector::StackNames names;
    //shader name
    edk::Name shaderName;


    //time
    edk::watch::Time clock;

    //frame
    edk::uint64 iFrame;
};

void printHelp(){
    printf("\n");
    printf("\nShadertoy for EDK");
    printf("\n--shader <shaderName.frag> : Set fragment shader name;");
    printf("\n--textures <image0.extension> <image1.extension> <image2.extension> <image3.extension> : Set the textures used (only open jpg/png files);");
    printf("\n");
    printf("\nExamples:");
    printf("\n");
    printf("\n");
    fflush(stdout);
}

enum CommandType{
    commandNothing=0,
    commandShader,
    commandTexture,

    commandSize
};

int main(edk::int32 argc,edk::char8* argv[]){
    //Create a view to draw the scene
    RenderView view;

    //test if the args is one
    if(argc<=1){
        //print the help
        printHelp();
        return 0;
    }
    else{
        CommandType argType = commandNothing;
        //get the args
        edk::CommandParser args;
        if(args.parseArgcArgv(argc,argv)){
            //
            edk::uint32 size = args.getCommandsSize();
            for(edk::uint32 i=0u;i<size;i++){
                //read the command type
                if(edk::String::strCompare(args.getCommandInPosition(i),"--shader")){
                    argType = commandShader;
                    continue;
                }
                else if(edk::String::strCompare(args.getCommandInPosition(i),"--textures")){
                    argType = commandTexture;
                    continue;
                }
                //test witch command are using
                switch(argType){
                case commandShader:
                    //test if aready have the shader
                    if(view.haveShader()){
                        printf("\nCan't use '%s' because the software aready have a shader '%s'"
                               ,args.getCommandInPosition(i)
                               ,view.getShader()
                               );
                    }
                    else{
                        //add the shader
                        if(!view.setShader(args.getCommandInPosition(i))){
                            printf("\nError: '%s' is not a shader (maybe you need specify the .frag extension)",args.getCommandInPosition(i));
                            printf("\n");
                            printHelp();
                            return 0;
                        }
                    }
                    break;
                case commandTexture:
                    //add the texture
                    if(!view.addName(args.getCommandInPosition(i))){
                        printf("\nError: '%s' is not an image jpg/jpeg/JPG/JPEG or png",args.getCommandInPosition(i));
                        printf("\n");
                        printHelp();
                        return 0;
                    }
                    break;
                default:
                    //default close the software
                    printf("\nError: Don't know the command '%s'",args.getCommandInPosition(i));fflush(stdout);
                    printf("\n");
                    printHelp();
                    return 0;
                }
            }
        }
        else{
            printHelp();
            return 0;
        }
    }


    edk::Window win;
    //create the window with the buttons
    win.createWindow(800,600,"EDK SHADERTOY",EDK_WINDOW_BUTTONS | EDK_WINDOW_RESIZE);
    //set the background color fo the window
    win.cleanColor = edk::color3ui8(0,0,0);

    view.backgroundColor = edk::color4f32(1,1,1,1); //set the viewColor
    view.frame.origin = edk::vec2f32(0,0);          //set the view position inside the Window View
    view.frame.size = edk::size2f32(800,600);       //set the size of the View

    //add the view in the Window
    win.addSubview(&view);

    //test if need close the software
    if(view.needClose()){
        win.closeWindow();
    }

    //Loop
    while(win.isOpened()){
        //Clean the Windows
        win.clean();
        //load the Window Events
        win.loadEvents();
        //update the Views with the events pre-loaded
        win.updateViews();

        //check if click to close de Window
        if(win.eventButtonClose()){
            //close the window
            win.closeWindow();
        }
        //test if release the ESC key
        if(win.eventGetKeyReleaseSize()){
            for(edk::uint32 i=0u;i<win.eventGetKeyReleaseSize();i++){
                if(win.eventGetKeyRelease(i) == edk::key::escape){
                    //close Window
                    win.closeWindow();
                }
            }
        }

        //for one miracle maybe it needs close the software
        if(view.needClose()){
            win.closeWindow();
        }

        //draw the View's
        win.drawView();
        //render the scene
        win.render();
    }
    //remove the view from window
    win.removeSubview(&view);
    return 0;
}
