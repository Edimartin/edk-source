#include "BlocksGLSL.h"

namespace edk{
namespace shd{
enum edkTypesWord{
    funcTypeNothing=0u,
    funcTypeReturn,
    funcTypeName,
    funcTypeParamInit,
    funcTypeParamEnd,
    funcTypeInit,
    funcTypeEnd,

    funcTypeSize
};
}
}

edk::shd::BlocksGLSL::BlocksGLSL(){
    //
}
edk::shd::BlocksGLSL::~BlocksGLSL(){
    //
}
//test if it's a function command
bool edk::shd::BlocksGLSL::isFunctionLine(edk::char8* start,edk::char8* end,bool* isMain){
    if(start && end){
        edk::shd::edkTypesWord type = funcTypeReturn;
        bool startWord=false;
        while(*start && start<end){
            //
            if(edk::String::isCharEndLine(*start)
                    || *start == ' '
                    ){
                if(startWord){
                    //change the type
                    switch(type){
                    case funcTypeReturn:
                        //read the name
                        type = funcTypeName;
                        break;
                    case funcTypeName:
                        //read the params
                        type = funcTypeParamInit;
                        break;
                    case funcTypeParamInit:
                        break;
                    case funcTypeParamEnd:
                        break;
                    case funcTypeInit:
                        break;
                    case funcTypeEnd:
                        break;

                    default:
                        *isMain=false;
                        return false;
                    }
                }
                startWord=false;
            }
            else if(*start == '/'){
                if(start[1u] == '/'){
                    //go to the end of the line
                    start = edk::String::strJumpToEndLine(start);
                }
                else if(start[1u] == '*'){
                    start++;
                    while(*start){
                        start = edk::String::strJumpTo(start,"*");
                        if(start){
                            if(*start=='/'){
                                break;
                            }
                        }
                        else{
                            break;
                        }
                    }
                }
            }
            else{
                //test if are searching some type in the function name
                switch(type){
                case funcTypeName:
                    if(!startWord){
                        //test if is main
                        if(edk::String::strCompareBeggin("main(",start)
                                || edk::String::strCompareBeggin("main ",start)
                                || edk::String::strCompareBeggin("main\n",start)
                                || edk::String::strCompareBeggin("main\10",start)
                                ){
                            //
                            *isMain=true;
                        }
                    }
                    else{
                        if(*start=='('){
                            //
                            type = funcTypeParamEnd;
                        }
                    }
                    startWord=true;
                    break;
                case funcTypeParamInit:
                    if(!startWord && *start=='('){
                        type = funcTypeParamEnd;
                    }
                    else{
                        *isMain=false;
                        return false;
                    }
                    startWord=true;
                    break;
                case funcTypeParamEnd:
                    startWord=true;
                    if(*start==')'){
                        type = funcTypeInit;
                        startWord=false;
                    }
                    break;
                case funcTypeInit:
                    if(!startWord && *start=='{'){
                        return true;
                    }
                    startWord=true;
                    break;
                case funcTypeEnd:
                    startWord=true;
                    break;
                default:
                    startWord=true;
                    break;
                }
            }

            start++;
        }
        return true;
    }
    *isMain=false;
    return false;
}

//generate the code
void edk::shd::BlocksGLSL::generate(){
    this->bufferCode.clean();
    //if(!this->bufferCode.size()){
        this->bufferCode.pushToBuffer(this->bufferOctos.getPointer(),this->bufferOctos.getSize());
        this->bufferCode.pushToBuffer(this->bufferCommand.getPointer(),this->bufferCommand.getSize());
        this->bufferCode.pushToBuffer(this->bufferFunctions.getPointer(),this->bufferFunctions.getSize());
        this->bufferCode.pushToBuffer((edk::char8*)"\nvoid main(){",edk::String::strSize("\nvoid main(){"));
        this->bufferCode.pushToBuffer(this->bufferMain.getPointer(),this->bufferMain.getSize());
        this->bufferCode.pushToBuffer((edk::char8*)"\n}",edk::String::strSize("\n}"));
    //}
}

void edk::shd::BlocksGLSL::clean(){
    this->bufferOctos.clean();
    this->bufferCommand.clean();
    this->bufferFunctions.clean();
    this->bufferMain.clean();
    this->bufferCode.clean();
}

bool edk::shd::BlocksGLSL::addCode(const edk::char8* code){
    return this->addCode((edk::char8*) code);
}
bool edk::shd::BlocksGLSL::addCode(edk::char8* code){
    this->bufferCode.clean();
    if(code){
        edk::char8* start = code;
        edk::char8* temp = NULL;
        while(*code){
            switch(*code){
            case '#':
            {
                bool isIf=false;
                //test if the octothorpe is an if
                if(code[1u]=='i'){
                    if(code[2u]=='f'){
                        //it's an if
                        isIf=true;
                    }
                }
                if(isIf){
                    bool isEnd=false;
                    //find the end
                    while(*code){
                        switch(*code){
                        case '#':
                            if(code[1u]=='e'){
                                if(code[2u]=='n'){
                                    if(code[3u]=='d'){
                                        //if an end
                                        isEnd=true;
                                        break;
                                    }
                                }
                            }
                        };
                        code++;
                        if(isEnd){
                            break;
                        }
                    }

                    if(*code){
                        //search the end of line
                        code = edk::String::strJumpToEndLine(code);
                    }
                }
                else{
                    //
                    code = edk::String::strJumpToEndLine(code);
                }

                //copy the octo
                this->bufferOctos.pushToBuffer(start,code-start);
                this->bufferOctos.pushToBuffer('\n');

                start = code;
            }
                break;
            case ';':
                //command
                code++;

                temp = code-1u;
                if(*temp == ')'){
                    //
                }

                //test if it's the end if line
                while(*code){
                    if(edk::String::isCharEndLine(*code)){
                        code++;
                    }
                    else{
                        break;
                    }
                }

                //copy the octo
                this->bufferCommand.pushToBuffer(start,code-start);
                this->bufferCommand.pushToBuffer('\n');

                start = code;
                break;
            case '{':
            {
                bool isMain=false;
                bool isFunction=false;

                //start block

                code++;

                //test if is a function
                if(this->isFunctionLine(start,code,&isMain)){
                    isFunction=true;
                }
                else{
                    //block of code
                }

                if(isFunction){
                    if(isMain){
                        //IS FUNCTION MAIN
                        start = edk::String::strJumpTo(start,"{");
                        if(start){
                            start++;
                            if(start){
                                //
                                code = edk::String::strJumpTo(start,"}");

                                if(code){
                                }
                            }
                        }
                        //
                        //copy the function main
                        if(!this->bufferMain.size()){
                            this->bufferMain.pushToBuffer('\n');
                        }
                        this->bufferMain.pushToBuffer(start,code-start-1u);
                        this->bufferMain.pushToBuffer('\n');
                    }
                    else{
                        //IS FUNCTION NORMAL
                        if(start){
                            //
                            code = edk::String::strJumpTo(start,"}");

                            if(code){
                            }
                        }
                        //
                        //copy the function
                        if(!this->bufferFunctions.size()){
                            this->bufferFunctions.pushToBuffer('\n');
                        }
                        this->bufferFunctions.pushToBuffer(start,code-start);
                        this->bufferFunctions.pushToBuffer('\n');
                    }
                }
                else{
                    //IS CODE
                    if(start){
                        //
                        code = edk::String::strJumpTo(start,"}");

                        if(code){
                            //search the next valiable character
                            temp = code;
                            while(*temp){
                                if(edk::String::isCharEndLine(*temp)
                                        || *temp == ' '
                                        ){
                                    temp++;
                                }
                                else{
                                    //else test if it's a end of command
                                    if(*temp == ';'){
                                        temp++;
                                        if(temp){
                                            //set the end of command
                                            code = temp;
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                    }
                    //
                    //copy the function
                    if(!this->bufferCommand.size()){
                        this->bufferCommand.pushToBuffer('\n');
                    }
                    this->bufferCommand.pushToBuffer(start,code-start);
                    this->bufferCommand.pushToBuffer('\n');
                }
                start = code;
            }
                break;
            default:
                code++;
                break;
            }
        }
        return true;
    }
    return false;
}

//test if have the code
bool edk::shd::BlocksGLSL::haveCode(){
    if(this->bufferOctos.size()
            || this->bufferCommand.size()
            || this->bufferFunctions.size()
            || this->bufferMain.size()
            ){
        return true;
    }
    return false;
}

edk::char8* edk::shd::BlocksGLSL::getCodePointer(){
    if(this->haveCode()){
        if(!this->bufferCode.size()){
            this->generate();
        }
        return this->bufferCode.getPointer();
    }
    return NULL;
}
edk::uint64 edk::shd::BlocksGLSL::getCodeLenght(){
    if(this->haveCode()){
        if(!this->bufferCode.size()){
            this->generate();
        }
        return this->bufferCode.getSize();
    }
    return 0uL;
}

//print the code
void edk::shd::BlocksGLSL::print(){
    if(!this->bufferCode.size()){
        this->generate();
    }
    this->bufferCode.printStr();
}
