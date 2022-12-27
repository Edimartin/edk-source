#include "File.h"

/*
Library File - Read and Write Files using C ANSI
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
#warning "            Inside File.cpp"
#endif



//Just to save the defines to test witch define is used
#ifdef _WIN32
//Windows 32
#ifdef _MSC_VER
#endif//endif _MSC_VER

#ifdef __GNUC__
//MinGW
#ifdef __cplusplus
//G++
#else
//GCC
#endif//endif __cpluscplus
#endif//endif __GNUC__
#endif//endif _WIN32
#ifdef _WIN64
//Windows 64
#ifdef _MSC_VER
#endif//endif _MSC_VER
#ifdef __GNUC__
#ifdef __cplusplus
//G++
#else
//GCC
#endif//endif __cplusplus
#endif//endif__GNUC__
#endif//endif _WIN64
#ifdef __linux__
//LINUX
#ifdef __GNUC__
#ifdef __cplusplus
//G++
#else
//GCC
#endif//endif __cplusplus
#endif//endif __GNUC__
#endif//endif __linux__
#ifdef __APPLE__
//MACOS
#ifdef __GNUC__
#ifdef __cplusplus
//G++
#else
//GCC
#endif//endif __cplusplus
#endif//endif __GNUC__
#endif//endif __APPLE__



//Test if the edk::char8 is equal to some characters
bool testLimits(edk::char8 c,edk::char8* limits){
    //
    if(limits){
        edk::uint32 i=0u;
        while(limits[i]!='\0'){
            //
            if(limits[i]==c){
                //
                return true;
            }
            i++;edkEnd();
        }
    }
    return false;
}

//Read the string from the file
edk::char8* edk::File::readStringFromTheFile(FILE* arq,edk::char8 limit,edk::uint32 count,bool use){
    //First read the next character
    edk::char8 temp = '\0';edkEnd();

    //string return
    edk::char8* ret = NULL;edkEnd();

    //test if have the end of the file
    if(feof(arq)){
        //then create the simple string
        edk::char8* str = new edk::char8[count+1u];edkEnd();
        //copy the end character '\0'
        if(str){
            //
            str[count]='\0';edkEnd();
        }
        //return the string
        return str;edkEnd();
    }

#ifdef _WIN32
    //Windows 32
#ifdef _MSC_VER
    //Visual C
    fscanf_s(arq,"%c",&temp);edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
    //G++
    fscanf(arq,"%c",&temp);edkEnd();
#else
    //GCC
#endif
#endif
#endif
#ifdef _WIN64
    //Windows 64
#ifdef _MSC_VER
    //Visual C
    fscanf_s(arq,"%c",&temp);edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
    //G++
    fscanf(arq,"%c",&temp);edkEnd();
#else
    //GCC
#endif
#endif
#endif
#ifdef __linux__
    //LINUX
#ifdef __GNUC__
#ifdef __cplusplus
    //G++
    fscanf(arq,"%c",&temp);edkEnd();
#else
    //GCC
#endif
#endif
#endif
#ifdef __APPLE__
    //MACOS
#ifdef __GNUC__
#ifdef __cplusplus
    //G++
    fscanf(arq,"%c",&temp);edkEnd();
#else
    //GCC
#endif
#endif
#endif
    //test if read the end character or the end of the file

    if(feof(arq) || temp==limit || temp=='\0'){
        //have the end of the read

        //alloc the new string
        edk::char8* str = NULL;edkEnd();
        //test if use the limit character
        if(use && temp!='\0'){
            //Copy the end and the limit character
            str = new edk::char8[count+2u];edkEnd();
            if(str){
                //
                str[count+1u]='\0';edkEnd();
                str[count]=limit;edkEnd();
            }
        }
        else{
            //Copy just the end character
            str = new edk::char8[count+1u];edkEnd();
            if(str){
                //
                str[count]='\0';edkEnd();
            }
        }
        //return the string
        return str;edkEnd();
    }
    else{
        //keep trying
        ret = this->readStringFromTheFile(arq,limit,count+1u,use);edkEnd();

        //Test if the ret is alloc
        if(ret){
            //then copy the character readed (temp)
            ret[count]=temp;edkEnd();
        }
    }
    //return the ret string
    return ret;
}
edk::char8* edk::File::readStringFromTheFile(FILE* arq,edk::char8* limits,edk::uint32 count,bool use){

    //First read the next character
    edk::char8 temp = '\0';edkEnd();

    //string return
    edk::char8* ret = NULL;edkEnd();

    //test if have the end of the file
    if(feof(arq)){
        //then create the simple string
        edk::char8* str = new edk::char8[count+1u];edkEnd();
        //copy the end character '\0'
        if(str){
            //
            str[count]='\0';edkEnd();
        }
        //return the string
        return str;edkEnd();
    }

#ifdef _WIN32
    //Windows 32
#ifdef _MSC_VER
    //Visual C
    fscanf_s(arq,"%c",&temp);edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
    //G++
    fscanf(arq,"%c",&temp);edkEnd();
#else
    //GCC
#endif
#endif
#endif
#ifdef _WIN64
    //Windows 64
#ifdef _MSC_VER
    //Visual C
    fscanf_s(arq,"%c",&temp);edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
    //G++
    fscanf(arq,"%c",&temp);edkEnd();
#else
    //GCC
#endif
#endif
#endif
#ifdef __linux__
    //LINUX
#ifdef __GNUC__
#ifdef __cplusplus
    //G++
    fscanf(arq,"%c",&temp);edkEnd();
#else
    //GCC
#endif
#endif
#endif
#ifdef __APPLE__
    //MACOS
#ifdef __GNUC__
#ifdef __cplusplus
    //G++
    fscanf(arq,"%c",&temp);edkEnd();
#else
    //GCC
#endif
#endif
#endif
    //test if read the end character or the end of the file

    if(feof(arq) || testLimits(temp,limits) || temp=='\0'){
        //have the end of the read

        //alloc the new string
        edk::char8* str = NULL;edkEnd();
        //test if use the limit character
        if(use && temp!='\0'){
            //Copy the end and the limit character
            str = new edk::char8[count+2u];edkEnd();
            if(str){
                //
                str[count+1u]='\0';edkEnd();
                str[count]=temp;edkEnd();
            }
        }
        else{
            //Copy just the end character
            str = new edk::char8[count+1u];edkEnd();
            if(str){
                //
                str[count]='\0';edkEnd();
            }
        }
        //return the string
        return str;edkEnd();
    }
    else{
        //keep trying
        ret = this->readStringFromTheFile(arq,limits,count+1u,use);edkEnd();

        //Test if the ret is alloc
        if(ret){
            //then copy the character readed (temp)
            ret[count]=temp;edkEnd();
        }
    }
    //return the ret string
    return ret;
}
edk::char8* edk::File::readStringFromTheBinFile(FILE* arq,edk::char8 limit,edk::uint32 count,bool use){
    //First read the next character
    edk::char8 temp = '\0';edkEnd();

    //string return
    edk::char8* ret = NULL;edkEnd();

    //test if have the end of the file
    if(feof(arq)){
        //then create the simple string
        edk::char8* str = new edk::char8[count+1u];edkEnd();
        //copy the end character '\0'
        if(str){
            //
            str[count]='\0';edkEnd();
        }
        //return the string
        return str;edkEnd();
    }

    fread(&temp,1u,1u,this->arq);edkEnd();
    //test if read the end character or the end of the file

    if(feof(arq) || temp==limit || temp=='\0'){
        //have the end of the read

        //alloc the new string
        edk::char8* str = NULL;edkEnd();
        //test if use the limit character
        if(use && temp!='\0'){
            //Copy the end and the limit character
            str = new edk::char8[count+2u];edkEnd();
            if(str){
                //
                str[count+1u]='\0';edkEnd();
                str[count]=limit;edkEnd();
            }
        }
        else{
            //Copy just the end character
            str = new edk::char8[count+1u];edkEnd();
            if(str){
                //
                str[count]='\0';edkEnd();
            }
        }
        //return the string
        return str;edkEnd();
    }
    else{
        //keep trying
        ret = this->readStringFromTheBinFile(arq,limit,count+1u,use);edkEnd();

        //Test if the ret is alloc
        if(ret){
            //then copy the character readed (temp)
            ret[count]=temp;edkEnd();
        }
    }
    //return the ret string
    return ret;
}
edk::char8* edk::File::readStringFromTheBinFile(FILE* arq,edk::char8* limits,edk::uint32 count,bool use){

    //First read the next character
    edk::char8 temp = '\0';edkEnd();

    //string return
    edk::char8* ret = NULL;edkEnd();

    //test if have the end of the file
    if(feof(arq)){
        //then create the simple string
        edk::char8* str = new edk::char8[count+1u];edkEnd();
        //copy the end character '\0'
        if(str){
            //
            str[count]='\0';edkEnd();
        }
        //return the string
        return str;edkEnd();
    }

    fread(&temp,1u,1u,this->arq);edkEnd();

    //test if read the end character or the end of the file
    if(feof(arq) || testLimits(temp,limits) || temp=='\0'){
        //have the end of the read

        //alloc the new string
        edk::char8* str = NULL;edkEnd();
        //test if use the limit character
        if(use && temp!='\0'){
            //Copy the end and the limit character
            str = new edk::char8[count+2u];edkEnd();
            if(str){
                //
                str[count+1u]='\0';edkEnd();
                str[count]=temp;edkEnd();
            }
        }
        else{
            //Copy just the end character
            str = new edk::char8[count+1u];edkEnd();
            if(str){
                //
                str[count]='\0';edkEnd();
            }
        }
        //return the string
        return str;edkEnd();
    }
    else{
        //keep trying
        ret = this->readStringFromTheBinFile(arq,limits,count+1u,use);edkEnd();

        //Test if the ret is alloc
        if(ret){
            //then copy the character readed (temp)
            ret[count]=temp;edkEnd();
        }
    }
    //return the ret string
    return ret;
}






edk::File::File(){
    //clean the atributes
    this->arq=NULL;edkEnd();
    this->name=NULL;edkEnd();
    this->size=0u;
}

edk::File::~File(){
    //close the file
    this->closeFile();edkEnd();
}

edk::uint64 edk::File::getFileSize(){
    if(this->isOpened()){
        //if(!this->size){
        //load fileSize
        edk::uint64 position = this->getSeek64();edkEnd();
        this->seekEnd();edkEnd();
        this->size = this->getSeek64();edkEnd();
        this->seekStart(position);edkEnd();
        //}
        return this->size;edkEnd();
    }
    return 0u;edkEnd();
}

bool edk::File::openTextFile(edk::char8 *name){
    //Close the file
    this->closeFile();edkEnd();

    //Then open the file in your compiler
    if((const edk::char8*)name && edk::File::isFile(name)){

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fopen_s(&arq,name,"r");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"r");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fopen_s(&arq,name,"r");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"r");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __linux__
        //LINUX
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"r");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __APPLE__
        //MACOS
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"r");edkEnd();
#else
        //GCC
#endif
#endif
#endif
        //Test if open the file
        if(this->isOpened()){
            //then copy the things of the file

            //The size of the file
            fseek ( this->arq , 0 , SEEK_END );edkEnd();
            //this->size = ftell(this->arq);edkEnd();
            //Come back to the start
            fseek ( arq , 0 , SEEK_SET );edkEnd();

            //Copy the name of the file
            this->name = edk::String::strCopy(name);edkEnd();

            //return true
            return true;
        }
        else{
            //Else he can't open the file
            arq=NULL;edkEnd();
        }
    }
    return false;
}

bool edk::File::openTextFile(const edk::char8 *name){
    return this->openTextFile((edk::char8*)name);edkEnd();
}

bool edk::File::openBinFile(edk::char8 *name){
    //Close the file
    this->closeFile();edkEnd();

    //Then open the file in your compiler
    if((const edk::char8*)name && edk::File::isFile(name)){

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fopen_s(&arq,name,"rb");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"rb");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fopen_s(&arq,name,"rb");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"rb");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __linux__
        //LINUX
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"rb");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __APPLE__
        //MACOS
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"rb");edkEnd();
#else
        //GCC
#endif
#endif
#endif
        //Test if open the file
        if(this->isOpened()){
            //then copy the things of the file

            //The size of the file
            fseek ( this->arq , 0 , SEEK_END );edkEnd();
            //this->size = ftell(this->arq);edkEnd();
            //Come back to the start
            fseek ( arq , 0 , SEEK_SET );edkEnd();

            //Copy the name of the file
            this->name = edk::String::strCopy(name);edkEnd();

            //return true
            return true;
        }
        else{
            //Else he can't open the file
            arq=NULL;edkEnd();
        }
    }
    return false;
}

bool edk::File::openBinFile(const edk::char8 *name){
    return this->openBinFile((edk::char8*)name);edkEnd();
}

bool edk::File::openEndTextFile(edk::char8 *name){
    //Close the file
    this->closeFile();edkEnd();

    //Then open the file in your compiler
    if((const edk::char8*)name && edk::File::isFile(name)){

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fopen_s(&arq,name,"a");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"a");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fopen_s(&arq,name,"a");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"a");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __linux__
        //LINUX
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"a");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __APPLE__
        //MACOS
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"a");edkEnd();
#else
        //GCC
#endif
#endif
#endif
        //Test if open the file
        if(this->isOpened()){
            //then copy the things of the file

            //The size of the file
            fseek ( this->arq , 0 , SEEK_END );edkEnd();
            //this->size = ftell(this->arq);edkEnd();
            //Come back to the start
            //fseek ( arq , 0 , SEEK_SET );edkEnd();

            //Copy the name of the file
            this->name = edk::String::strCopy(name);edkEnd();

            //return true
            return true;
        }
        else{
            //Else he can't open the file
            arq=NULL;edkEnd();
        }
    }
    return false;
}

bool edk::File::openEndTextFile(const edk::char8 *name){
    return this->openEndTextFile((edk::char8 *)name);edkEnd();
}

bool edk::File::openEndBinFile(edk::char8 *name){
    //Close the file
    this->closeFile();edkEnd();

    //Then open the file in your compiler
    if((const edk::char8*)name && edk::File::isFile(name)){

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fopen_s(&arq,name,"ab");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"ab");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fopen_s(&arq,name,"ab");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"ab");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __linux__
        //LINUX
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"ab");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __APPLE__
        //MACOS
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"ab");edkEnd();
#else
        //GCC
#endif
#endif
#endif
        //Test if open the file
        if(this->isOpened()){
            //then copy the things of the file

            //The size of the file
            fseek ( this->arq , 0 , SEEK_END );edkEnd();
            //this->size = ftell(this->arq);edkEnd();
            //Come back to the start
            //fseek ( arq , 0 , SEEK_SET );edkEnd();

            //Copy the name of the file
            this->name = edk::String::strCopy(name);edkEnd();

            //return true
            return true;
        }
        else{
            //Else he can't open the file
            arq=NULL;edkEnd();
        }
    }
    return false;
}

bool edk::File::openEndBinFile(const edk::char8 *name){
    return this->openEndBinFile((edk::char8*)name);edkEnd();
}

//PIPE
bool edk::File::openPipe(edk::char8 *name){
    //Close the file
    this->closeFile();edkEnd();

    //Then open the file in your compiler
    if((const edk::char8*)name){

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        popen_s(&arq,name,"r");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=popen((const edk::char8*)name,"r");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        popen_s(&arq,name,"r");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=popen((const edk::char8*)name,"r");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __linux__
        //LINUX
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=popen((const edk::char8*)name,"r");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __APPLE__
        //MACOS
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=popen((const edk::char8*)name,"r");edkEnd();
#else
        //GCC
#endif
#endif
#endif
        //Test if open the file
        if(this->isOpened()){
            //then copy the things of the file

            //The size of the file
            fseek ( this->arq , 0 , SEEK_END );edkEnd();
            //this->size = ftell(this->arq);edkEnd();
            //Come back to the start
            //fseek ( arq , 0 , SEEK_SET );edkEnd();

            //Copy the name of the file
            this->name = edk::String::strCopy(name);edkEnd();

            //return true
            return true;
        }
        else{
            //Else he can't open the file
            arq=NULL;edkEnd();
        }
    }
    return false;
}
bool edk::File::openPipe(const edk::char8 *name){
    return this->openPipe((edk::char8 *)name);edkEnd();
}

void edk::File::closeFile(){
    //Test if the file is opened
    if(this->isOpened()){
        //Then close the file
        fclose(this->arq);edkEnd();
    }
    //clean the atributes
    this->arq=NULL;edkEnd();
    this->size=0u;

    //Delete the name if the name exist
    if(this->name){
        //
        delete[] this->name;edkEnd();
    }
    this->name=NULL;edkEnd();
}

bool edk::File::deleteFile(edk::char8 *name){
    //To delete the file we use the Remove
    if((const edk::char8*)name){
        //
        if( remove( (const edk::char8*)name ) != 0 ){
            //Remove the file
            return true;
        }
    }
    return false;
}

bool edk::File::deleteFile(const edk::char8 *name){
    return deleteFile((edk::char8 *)name);edkEnd();
}

bool edk::File::deleteFile(){
    //Test if the file is opened
    if(this->isOpened()){
        //copy the name of the file
        edk::char8* tempName =NULL;edkEnd();
        if(this->name){
            tempName = edk::String::strCopy(this->name);edkEnd();
        }
        //create a return
        bool ret=false;edkEnd();
        //Close the file
        this->closeFile();edkEnd();
        //Test if copy the name
        if(tempName){
            //Then try remove the file
            ret=edk::File::deleteFile(tempName);edkEnd();

            //delete the tempName
            delete[] tempName;edkEnd();
        }
        tempName=NULL;edkEnd();
        //return the function deleteFile response
        return ret;
    }
    return false;
}

bool edk::File::renameFile(edk::char8 *oldName, edk::char8 *newName){
    //Test if the names is valid
    if(oldName && newName){
        //Then try rename the file
        if( rename( (const edk::char8*)oldName , (const edk::char8*)newName ) == 0 ){
            //Return true because he rename the file
            return true;
        }
    }
    //else return false
    return false;
}

bool edk::File::renameFile(const edk::char8 *oldName, const edk::char8 *newName){
    return renameFile((edk::char8 *)oldName, (edk::char8 *)newName);edkEnd();
}

bool edk::File::createFile(edk::char8 *name){
    //Use a file
    FILE *tempArq=NULL;edkEnd();

    //test the name of the file
    if((const edk::char8*)name){
        //Create the file
#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fopen_s(&tempArq,name,"wb");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        tempArq=fopen((const edk::char8*)name,"wb");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fopen_s(&tempArq,name,"wb");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        tempArq=fopen((const edk::char8*)name,"wb");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __linux__
        //LINUX
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        tempArq=fopen((const edk::char8*)name,"wb");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __APPLE__
        //MACOS
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        tempArq=fopen((const edk::char8*)name,"wb");edkEnd();
#else
        //GCC
#endif
#endif
#endif

        //Test if create the file
        if(tempArq){
            //close the file
            fclose(tempArq);edkEnd();
            //clean the tempArq
            tempArq=NULL;edkEnd();
            //return true
            return true;
        }
    }
    //Else return false
    return false;
}

bool edk::File::createFile(const edk::char8 *name){
    return createFile((edk::char8 *)name);edkEnd();
}

//return true if is a file
bool edk::File::isFile(edk::char8 *name){
    if(name){
        struct stat path_stat;edkEnd();
        stat(name, &path_stat);edkEnd();
        return S_ISREG(path_stat.st_mode);edkEnd();
    }
    return false;
}
bool edk::File::isFile(const edk::char8* name){
    //
    return edk::File::isFile((edk::char8*)name);edkEnd();
}

bool edk::File::createAndOpenTextFile(edk::char8 *name){
    //Close the file
    this->closeFile();edkEnd();

    //Then open the file in your compiler
    if((const edk::char8*)name){

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fopen_s(&this->arq,name,"w");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        this->arq=fopen((const edk::char8*)name,"w");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fopen_s(&this->arq,name,"w");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        this->arq=fopen((const edk::char8*)name,"w");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __linux__
        //LINUX
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        this->arq=fopen((const edk::char8*)name,"w");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __APPLE__
        //MACOS
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        this->arq=fopen((const edk::char8*)name,"w");edkEnd();
#else
        //GCC
#endif
#endif
#endif
        //Test if open the file
        if(this->isOpened()){
            //Copy the name of the file
            this->name = edk::String::strCopy(name);edkEnd();

            //return true
            return true;
        }
        else{
            //Else he can't open the file
            this->arq=NULL;edkEnd();
        }
    }
    return false;
}

bool edk::File::createAndOpenTextFile(const edk::char8 *name){
    return createAndOpenTextFile((edk::char8 *)name);edkEnd();
}

bool edk::File::createAndOpenBinFile(edk::char8 *name){
    //Close the file
    this->closeFile();edkEnd();

    //Then open the file in your compiler
    if((const edk::char8*)name){

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fopen_s(&this->arq,name,"wb");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        this->arq=fopen((const edk::char8*)name,"wb");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fopen_s(&this->arq,name,"wb");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        this->arq=fopen((const edk::char8*)name,"wb");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __linux__
        //LINUX
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        this->arq=fopen((const edk::char8*)name,"wb");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __APPLE__
        //MACOS
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        this->arq=fopen((const edk::char8*)name,"wb");edkEnd();
#else
        //GCC
#endif
#endif
#endif
        //Test if open the file
        if(this->isOpened()){
            //Copy the name of the file
            this->name = edk::String::strCopy(name);edkEnd();

            //return true
            return true;
        }
        else{
            //Else he can't open the file
            this->arq=NULL;edkEnd();
        }
    }
    return false;
}

bool edk::File::createAndOpenBinFile(const edk::char8 *name){
    return createAndOpenBinFile((edk::char8 *)name);edkEnd();
}

//PIPE
bool edk::File::createAndOpenPipe(edk::char8* name){
    //Close the file
    this->closeFile();edkEnd();

    //Then open the file in your compiler
    if((const edk::char8*)name){

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        popen_s(&arq,name,"w");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=popen((const edk::char8*)name,"w");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        popen_s(&arq,name,"ab");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=popen((const edk::char8*)name,"w");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __linux__
        //LINUX
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=popen((const edk::char8*)name,"w");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __APPLE__
        //MACOS
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=popen((const edk::char8*)name,"w");edkEnd();
#else
        //GCC
#endif
#endif
#endif
        //Test if open the file
        if(this->isOpened()){
            //then copy the things of the file

            //The size of the file
            fseek ( this->arq , 0 , SEEK_END );edkEnd();
            //this->size = ftell(this->arq);edkEnd();
            //Come back to the start
            //fseek ( arq , 0 , SEEK_SET );edkEnd();

            //Copy the name of the file
            this->name = edk::String::strCopy(name);edkEnd();

            //return true
            return true;
        }
        else{
            //Else he can't open the file
            arq=NULL;edkEnd();
        }
    }
    return false;
}
bool edk::File::createAndOpenPipe(const edk::char8* name){
    return this->createAndOpenPipe((edk::char8*) name);edkEnd();
}

bool edk::File::fileExist(edk::char8 *name){
    //create a tempFile
    FILE *tempArq=NULL;edkEnd();
    //Test the name
    if((const edk::char8*)name){
        //Try open the file

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fopen_s(&tempArq,name,"r");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        tempArq=fopen((const edk::char8*)name,"r");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fopen_s(&tempArq,name,"r");edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        tempArq=fopen((const edk::char8*)name,"r");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __linux__
        //LINUX
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        tempArq=fopen((const edk::char8*)name,"r");edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __APPLE__
        //MACOS
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        tempArq=fopen((const edk::char8*)name,"r");edkEnd();
#else
        //GCC
#endif
#endif
#endif

        //Test if open the file
        if(tempArq){
            //then the file Exist
            //close the file
            fclose(tempArq);edkEnd();
            //return true
            return true;
        }
    }
    return false;
}

bool edk::File::fileExist(const edk::char8 *name){
    return fileExist((edk::char8 *)name);edkEnd();
}

bool edk::File::readEnd(){
    //Test if the file reading get the end of the file

    //Test if the file is opened
    if(this->isOpened()){
        //Test if go to the endo if the file
        if(feof(this->arq)){
            //return true;
            return true;
        }
    }
    //Else return false
    return false;
}
bool edk::File::endOfFile(){
    return this->readEnd();edkEnd();
}

bool edk::File::writeText(edk::char8 c){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%c",c);edkEnd();
        //return true
        return true;
    }
    return false;
}

bool edk::File::writeText(edk::char8 *str){
    //Test if the file is opened and if the string is true
    if(this->isOpened() && str){
        //Then write in the file
        edk::int32 ret = fprintf(this->arq,"%s",str);edkEnd();
        if(ret>=0){
            return true;
        }
    }
    return false;
}

bool edk::File::writeText(const edk::char8 *str){
    return writeText((edk::char8 *)str);edkEnd();
}

bool edk::File::writeText(edk::int8 n){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%d",n);edkEnd();
        //return true
        return true;
    }
    return false;
}

bool edk::File::writeText(edk::uint8 n){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%u",n);edkEnd();
        //return true
        return true;
    }
    return false;
}

bool edk::File::writeText(edk::int16 n){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%d",n);edkEnd();
        //return true
        return true;
    }
    return false;
}

bool edk::File::writeText(edk::uint16 n){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%u",n);edkEnd();
        //return true
        return true;
    }
    return false;
}

bool edk::File::writeText(edk::int32 n){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%d",n);edkEnd();
        //return true
        return true;
    }
    return false;
}

bool edk::File::writeText(edk::uint32 n){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%u",n);edkEnd();
        //return true
        return true;
    }
    return false;
}

bool edk::File::writeText(edk::int64 n){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file

#if defined(_WIN32) || defined(_WIN64)
        //Windows 32 and 64
#ifdef _MSC_VER
#endif//endif _MSC_VER
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fprintf(this->arq,"%I64d",n);edkEnd();
#else
        //GCC
#endif//endif __cplusplus
#endif//endif__GNUC__
#endif//endif _WIN64
#ifdef __linux__
        //LINUX
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fprintf(this->arq,"%ld",n);edkEnd();
#else
        //GCC
#endif//endif __cplusplus
#endif//endif __GNUC__
#endif//endif __linux__
#ifdef __APPLE__
        //MACOS
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fprintf(this->arq,"%lld",n);edkEnd();
#else
        //GCC
#endif//endif __cplusplus
#endif//endif __GNUC__
#endif//endif __APPLE__
        //return true
        return true;
    }
    return false;
}

bool edk::File::writeText(edk::uint64 n){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
#if defined(_WIN32) || defined(_WIN64)
        //Windows 32 and 64
#ifdef _MSC_VER
#endif//endif _MSC_VER
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fprintf(this->arq,"%I64u",n);edkEnd();
#else
        //GCC
#endif//endif __cplusplus
#endif//endif__GNUC__
#endif//endif _WIN64
#ifdef __linux__
        //LINUX
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fprintf(this->arq,"%lu",n);edkEnd();
#else
        //GCC
#endif//endif __cplusplus
#endif//endif __GNUC__
#endif//endif __linux__
#ifdef __APPLE__
        //MACOS
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fprintf(this->arq,"%llu",n);edkEnd();
#else
        //GCC
#endif//endif __cplusplus
#endif//endif __GNUC__
#endif//endif __APPLE__
        //return true
        return true;
    }
    return false;
}

bool edk::File::writeText(edk::float32 f){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%f",f);edkEnd();
        //return true
        return true;
    }
    return false;
}

bool edk::File::writeText(edk::float32 f,edk::uint8 digits){
    bool ret = false;edkEnd();
    //Test if the file is opened
    if(this->isOpened()){
        edk::char8* strDigits = edk::String::uint32ToStr(digits);edkEnd();
        if(strDigits){
            edk::char8* str = edk::String::strCatMulti("%.",strDigits,"f",NULL);edkEnd();
            if(str){
                //Then write in the file
                fprintf(this->arq,str,f);edkEnd();
                ret = true;edkEnd();
                delete[] str;edkEnd();
            }
            delete[] strDigits;edkEnd();
        }
    }
    return ret;
}

bool edk::File::writeText(edk::float64 f){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%lf",f);edkEnd();
        //return true
        return true;
    }
    return false;
}

bool edk::File::writeText(edk::float64 f,edk::uint8 digits){
    bool ret = false;edkEnd();
    //Test if the file is opened
    if(this->isOpened()){
        edk::char8* strDigits = edk::String::uint32ToStr(digits);edkEnd();
        if(strDigits){
            edk::char8* str = edk::String::strCatMulti("%.",strDigits,"lf",NULL);edkEnd();
            if(str){
                //Then write in the file
                fprintf(this->arq,str,f);edkEnd();
                ret = true;edkEnd();
                delete[] str;edkEnd();
            }
            delete[] strDigits;edkEnd();
        }
    }
    return ret;
}

bool edk::File::writeBin(edk::classID w, edk::uint32 size){
    //test if the file is opened and if the w is true and the size is >1u
    if(this->isOpened() && w && size){
        //
        fwrite(w,size,1u,this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::char8 c){
    //test if the file is opened
    if(this->isOpened()){
        //
        fwrite(&c,sizeof(edk::char8),1u,this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::char8 *str){
    //test if the file is opened and if the str is true and the size is >1u
    if(this->isOpened() && str){
        //
        fwrite(str,sizeof(edk::char8),edk::String::strSize(str),this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(const edk::char8 *str){
    return writeBin((edk::char8 *)str);edkEnd();
}

bool edk::File::writeBin(edk::int8 n){
    //test if the file is opened
    if(this->isOpened()){
        //
        fwrite(&n,sizeof(edk::int8),1u,this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::int8 *n){
    //test if the file is opened and if the n is true and the size is >1u
    if(this->isOpened() && n){
        //
        fwrite(n,sizeof(edk::int8),sizeof(n),this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::uint8 n){
    //test if the file is opened
    if(this->isOpened()){
        //
        fwrite(&n,sizeof(edk::uint8),1u,this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::uint8 *n){
    //test if the file is opened and if the n is true and the size is >1u
    if(this->isOpened() && n){
        //
        fwrite(n,sizeof(edk::uint8),sizeof(n),this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::int16 n){
    //test if the file is opened
    if(this->isOpened()){
        //
        fwrite(&n,sizeof(edk::int16),1u,this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::int16 *n){
    //test if the file is opened and if the n is true and the size is >1u
    if(this->isOpened() && n){
        //
        fwrite(n,sizeof(edk::int16),sizeof(n),this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::uint16 n){
    //test if the file is opened
    if(this->isOpened()){
        //
        fwrite(&n,sizeof(edk::uint16),1u,this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::uint16 *n){
    //test if the file is opened and if the n is true and the size is >1u
    if(this->isOpened() && n){
        //
        fwrite(n,sizeof(edk::uint16),sizeof(n),this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::int32 n){
    //test if the file is opened
    if(this->isOpened()){
        //
        fwrite(&n,sizeof(edk::int32),1u,this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::int32 *n){
    //test if the file is opened and if the n is true and the size is >1u
    if(this->isOpened() && n){
        //
        fwrite(n,sizeof(edk::int32),sizeof(n),this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::uint32 n){
    //test if the file is opened
    if(this->isOpened()){
        //
        fwrite(&n,sizeof(edk::uint32),1u,this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::uint32 *n){
    //test if the file is opened and if the n is true and the size is >1u
    if(this->isOpened() && n){
        //
        fwrite(n,sizeof(edk::uint32),sizeof(n),this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::float32 f){
    //test if the file is opened
    if(this->isOpened()){
        //
        fwrite(&f,sizeof(edk::float32),1u,this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::float32* f){
    //test if the file is opened and if the n is true and the size is >1u
    if(this->isOpened() && f){
        //
        fwrite(f,sizeof(edk::float32),sizeof(f),this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::uint64 n){
    //test if the file is opened
    if(this->isOpened()){
        //
        fwrite(&n,sizeof(edk::uint64),1u,this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::uint64 *n){
    //test if the file is opened and if the n is true and the size is >1u
    if(this->isOpened() && n){
        //
        fwrite(n,sizeof(edk::uint64),sizeof(n),this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::int64 n){
    //test if the file is opened
    if(this->isOpened()){
        //
        fwrite(&n,sizeof(edk::int64),1u,this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::int64 *n){
    //test if the file is opened and if the n is true and the size is >1u
    if(this->isOpened() && n){
        //
        fwrite(n,sizeof(edk::int64),sizeof(n),this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::float64 f){
    //test if the file is opened
    if(this->isOpened()){
        //
        fwrite(&f,sizeof(edk::float64),1u,this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(edk::float64 *f){
    //test if the file is opened and if the n is true and the size is >1u
    if(this->isOpened() && f){
        //
        fwrite(f,sizeof(edk::float64),sizeof(f),this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(bool b){
    //test if the file is opened
    if(this->isOpened()){
        //
        fwrite(&b,sizeof(bool),1u,this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(bool *b){
    //test if the file is opened and if the n is true and the size is >1u
    if(this->isOpened() && b){
        //
        fwrite(b,sizeof(bool),sizeof(b),this->arq);edkEnd();
        //return true
        return true;
    }
    //else return false
    return false;
}

edk::char8 edk::File::readTextChar(){
    //create the text
    edk::char8 c=0u;
    //Test if the file is openned
    if(this->isOpened()){
        //read the edk::char8

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fscanf_s(this->arq,"%c",&c);edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%c",&c);edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fscanf_s(this->arq,"%c",&c);edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%c",&c);edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __linux__
        //LINUX
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%c",&c);edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __APPLE__
        //MACOS
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%c",&c);edkEnd();
#else
        //GCC
#endif
#endif
#endif
    }
    //else return false
    return c;edkEnd();
}

edk::char8* edk::File::readTextString(edk::uint32 limit, bool use){
    return this->readTextString((edk::char8) limit, use);edkEnd();
}
edk::char8* edk::File::readTextString(edk::uint64 limit, bool use){
    return this->readTextString((edk::char8) limit, use);edkEnd();
}
edk::char8* edk::File::readTextString(edk::uint8 limit, bool use){
    return this->readTextString((edk::char8) limit, use);edkEnd();
}

edk::char8* edk::File::readTextString(edk::char8 limit, bool use){
    //test if the file os opened
    if(this->isOpened()){
        //read the string
        return this->readStringFromTheFile(this->arq,limit,0u,use);edkEnd();
    }
    //else return NULL
    return NULL;
}

edk::char8* edk::File::readTextString(edk::char8 *limits, bool use){
    //test if the file os opened
    if(this->isOpened()&&limits){
        //read the string
        return this->readStringFromTheFile(this->arq,limits,0u,use);edkEnd();
    }
    //else return NULL
    return NULL;
}

edk::char8* edk::File::readTextString(const edk::char8 *limits, bool use){
    return this->readTextString((edk::char8 *)limits, use);edkEnd();
}

//read to a string
bool edk::File::readTextString(edk::char8 *str,edk::uint64 size){
    //test the string
    if(str && size){
        if(this->readBin(str,size)){
            return true;
        }
    }
    return false;
}

edk::int32 edk::File::readTextInt(){
    //create the edk::int32
    edk::int32 n=0u;
    //Test if the file is openned
    if(this->isOpened()){
        //read the edk::char8

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fscanf_s(this->arq,"%d",&n);edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%d",&n);edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fscanf_s(this->arq,"%d",&n);edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%d",&n);edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __linux__
        //LINUX
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%d",&n);edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __APPLE__
        //MACOS
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%d",&n);edkEnd();
#else
        //GCC
#endif
#endif
#endif
    }
    //else return false
    return n;edkEnd();
}

edk::uint32 edk::File::readTextUInt(){
    //create the edk::uint32
    edk::int32 n=0u;
    //Test if the file is openned
    if(this->isOpened()){
        //read the edk::char8

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fscanf_s(this->arq,"%u",&n);edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%u",&n);edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fscanf_s(this->arq,"%u",&n);edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%u",&n);edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __linux__
        //LINUX
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%u",&n);edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __APPLE__
        //MACOS
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%u",&n);edkEnd();
#else
        //GCC
#endif
#endif
#endif
    }
    //else return false
    return n;edkEnd();
}

edk::float32 edk::File::readTextFloat(){
    //create the edk::uint32
    edk::float32 f=0.0;
    //Test if the file is openned
    if(this->isOpened()){
        //read the edk::char8

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fscanf_s(this->arq,"%f",&f);edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%f",&f);edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fscanf_s(this->arq,"%f",&f);edkEnd();
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%f",&f);edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __linux__
        //LINUX
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%f",&f);edkEnd();
#else
        //GCC
#endif
#endif
#endif
#ifdef __APPLE__
        //MACOS
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%f",&f);edkEnd();
#else
        //GCC
#endif
#endif
#endif
    }
    //else return false
    return f;edkEnd();
}

edk::classID edk::File::readBin(edk::uint64 size){
    //create the return
    void* ret=NULL;edkEnd();
    //test if the file is opened and the size is >1u
    if(this->isOpened() && size){
        //alloc the return
        ret=malloc(size);edkEnd();
        if(ret){
            //fread(ret,1u,size,this->arq);edkEnd();
            this->readBin(ret,size);edkEnd();
            return ret;
        }
    }
    return ret;
}

edk::uint64 edk::File::readBin(edk::classID vec,uint64 size){
    edk::uint64 ret = 0u;edkEnd();
    if(size && vec){
        ret = fread(vec,1u,size,this->arq);edkEnd();
    }
    return ret;
}

edk::char8 edk::File::readBinChar(){
    //read the size
    edk::char8* temp = (edk::char8*)this->readBin(sizeof(edk::char8));edkEnd();
    //create the edk::char8
    edk::char8 c = '\0';edkEnd();
    if(temp){
        //copy the edk::char8
        c = *temp;edkEnd();

        //delete temp
        delete[] temp;edkEnd();
    }
    temp=NULL;edkEnd();

    //return the edk::char8
    return c;edkEnd();
}

edk::char8* edk::File::readBinString(char64 size){
    //create the string
    edk::char8* temp = (edk::char8*)this->readBin(sizeof(edk::char8)*size);edkEnd();
    if(temp){
        //return the string
        return temp;edkEnd();
    }
    //else return NULL
    return NULL;
}

edk::char8* edk::File::readBinString(edk::char8 limit, bool use){
    //test if the file os opened
    if(this->isOpened()){
        //read the string
        return this->readStringFromTheBinFile(this->arq,limit,0u,use);edkEnd();
    }
    //else return NULL
    return NULL;
}

edk::char8* edk::File::readBinString(edk::char8 *limits, bool use){
    //test if the file os opened
    if(this->isOpened()){
        //read the string
        return this->readStringFromTheBinFile(this->arq,limits,0u,use);edkEnd();
    }
    //else return NULL
    return NULL;
}

edk::char8* edk::File::readBinString(const edk::char8 *limits, bool use){
    return this->readBinString((edk::char8 *)limits,use);edkEnd();
}

//read to a string
edk::uint64 edk::File::readBinString(edk::char8 *str,edk::uint64 size){
    edk::uint64 ret=0u;
    if(str && size){
        ret = this->readBin(str,size);edkEnd();
    }
    return ret;
}

edk::int8 edk::File::readBinInt8(){
    //read the size
    edk::int8* temp = (edk::int8*)this->readBin(sizeof(edk::int8));edkEnd();
    //create the edk::char8
    edk::int8 n = 0u;edkEnd();
    if(temp){
        //copy the edk::char8
        n = *temp;edkEnd();

        //delete temp
        delete[] temp;edkEnd();
    }
    temp=NULL;edkEnd();

    //return the edk::char8
    return n;edkEnd();
}

edk::int8* edk::File::readBinInt8(edk::int64 size){
    //create the string
    edk::int8* temp = (edk::int8*)this->readBin(sizeof(edk::int8)*size);edkEnd();
    if(temp){
        //return the string
        return temp;edkEnd();
    }
    //else return NULL
    return NULL;
}

edk::uint8 edk::File::readBinUInt8(){
    //read the size
    edk::uint8* temp = (edk::uint8*)this->readBin(sizeof(edk::uint8));edkEnd();
    //create the edk::char8
    edk::uint8 n = 0u;edkEnd();
    if(temp){
        //copy the edk::char8
        n = *temp;edkEnd();

        //delete temp
        delete[] temp;edkEnd();
    }
    temp=NULL;edkEnd();

    //return the edk::char8
    return n;edkEnd();
}

edk::uint8* edk::File::readBinUint8(edk::uint64 size){
    //create the string
    edk::uint8* temp = (edk::uint8*)this->readBin(sizeof(edk::uint8)*size);edkEnd();
    if(temp){
        //return the string
        return temp;edkEnd();
    }
    //else return NULL
    return NULL;
}

edk::int16 edk::File::readBinInt16(){
    //read the size
    edk::int16* temp = (edk::int16*)this->readBin(sizeof(edk::int16));edkEnd();
    //create the edk::char8
    edk::int16 n = 0u;edkEnd();
    if(temp){
        //copy the edk::char8
        n = *temp;edkEnd();

        //delete temp
        delete[] temp;edkEnd();
    }
    temp=NULL;edkEnd();

    //return the edk::char8
    return n;edkEnd();
}

edk::int16* edk::File::readBinInt16(edk::int16 size){
    //create the string
    edk::int16* temp = (edk::int16*)this->readBin(sizeof(edk::int16)*size);edkEnd();
    if(temp){
        //return the string
        return temp;edkEnd();
    }
    //else return NULL
    return NULL;
}

edk::uint16 edk::File::readBinUInt16(){
    //read the size
    edk::uint16* temp = (edk::uint16*)this->readBin(sizeof(edk::uint16));edkEnd();
    //create the edk::char8
    edk::uint16 n = 0u;edkEnd();
    if(temp){
        //copy the edk::char8
        n = *temp;edkEnd();

        //delete temp
        delete[] temp;edkEnd();
    }
    temp=NULL;edkEnd();

    //return the edk::char8
    return n;edkEnd();
}

edk::uint16* edk::File::readBinUint16(edk::uint16 size){
    //create the string
    edk::uint16* temp = (edk::uint16*)this->readBin(sizeof(edk::uint16)*size);edkEnd();
    if(temp){
        //return the string
        return temp;edkEnd();
    }
    //else return NULL
    return NULL;
}

edk::int32 edk::File::readBinInt32(){
    //read the size
    edk::int32* temp = (edk::int32*)this->readBin(sizeof(edk::int32));edkEnd();
    //create the edk::char8
    edk::int32 n = 0u;edkEnd();
    if(temp){
        //copy the edk::char8
        n = *temp;edkEnd();

        //delete temp
        delete[] temp;edkEnd();
    }
    temp=NULL;edkEnd();

    //return the edk::char8
    return n;edkEnd();
}

edk::int32* edk::File::readBinInt32(edk::int64 size){
    //create the string
    edk::int32* temp = (edk::int32*)this->readBin(sizeof(edk::int32)*size);edkEnd();
    if(temp){
        //return the string
        return temp;edkEnd();
    }
    //else return NULL
    return NULL;
}

edk::uint32 edk::File::readBinUInt32(){
    //read the size
    edk::uint32* temp = (edk::uint32*)this->readBin(sizeof(edk::uint32));edkEnd();
    //create the edk::char8
    edk::uint32 n = 0u;edkEnd();
    if(temp){
        //copy the edk::char8
        n = *temp;edkEnd();

        //delete temp
        delete[] temp;edkEnd();
    }
    temp=NULL;edkEnd();

    //return the edk::char8
    return n;edkEnd();
}

edk::uint32* edk::File::readBinUint32(edk::uint64 size){
    //create the string
    edk::uint32* temp = (edk::uint32*)this->readBin(sizeof(edk::uint32)*size);edkEnd();
    if(temp){
        //return the string
        return temp;edkEnd();
    }
    //else return NULL
    return NULL;
}

edk::int64 edk::File::readBinInt64(){
    //read the size
    edk::int64* temp = (edk::int64*)this->readBin(sizeof(edk::int64));edkEnd();
    //create the edk::char8
    edk::int64 n = 0u;edkEnd();
    if(temp){
        //copy the edk::char8
        n = *temp;edkEnd();

        //delete temp
        delete[] temp;edkEnd();
    }
    temp=NULL;edkEnd();

    //return the edk::char8
    return n;edkEnd();
}

edk::int64* edk::File::readBinInt64(edk::int64 size){
    //create the string
    edk::int64* temp = (edk::int64*)this->readBin(sizeof(edk::int64)*size);edkEnd();
    if(temp){
        //return the string
        return temp;edkEnd();
    }
    //else return NULL
    return NULL;
}

edk::uint64 edk::File::readBinUInt64(){
    //read the size
    edk::uint64* temp = (edk::uint64*)this->readBin(sizeof(edk::uint64));edkEnd();
    //create the edk::char8
    edk::uint64 n = 0u;edkEnd();
    if(temp){
        //copy the edk::char8
        n = *temp;edkEnd();

        //delete temp
        delete[] temp;edkEnd();
    }
    temp=NULL;edkEnd();

    //return the edk::char8
    return n;edkEnd();
}

edk::uint64* edk::File::readBinUint64(edk::uint64 size){
    //create the string
    edk::uint64* temp = (edk::uint64*)this->readBin(sizeof(edk::uint64)*size);edkEnd();
    if(temp){
        //return the string
        return temp;edkEnd();
    }
    //else return NULL
    return NULL;
}

edk::float32 edk::File::readBinFloat(){
    //read the size
    edk::float32* temp = (edk::float32*)this->readBin(sizeof(edk::float32));edkEnd();
    //create the edk::char8
    edk::float32 n = 0u;edkEnd();
    if(temp){
        //copy the edk::char8
        n = *temp;edkEnd();

        //delete temp
        delete[] temp;edkEnd();
    }
    temp=NULL;edkEnd();

    //return the edk::char8
    return n;edkEnd();
}

edk::float32* edk::File::readBinFloat(edk::int64 size){
    //create the string
    edk::float32* temp = (edk::float32*)this->readBin(sizeof(edk::float32)*size);edkEnd();
    if(temp){
        //return the string
        return temp;edkEnd();
    }
    //else return NULL
    return NULL;
}

edk::int64 edk::File::readBinLongInt(){
    //read the size
    edk::int64* temp = (edk::int64*)this->readBin(sizeof(edk::int64));edkEnd();
    //create the edk::char8
    edk::int64 n = 0u;edkEnd();
    if(temp){
        //copy the edk::char8
        n = *temp;edkEnd();

        //delete temp
        delete[] temp;edkEnd();
    }
    temp=NULL;edkEnd();

    //return the edk::char8
    return n;edkEnd();
}

edk::int64* edk::File::readBinLongInt(edk::int64 size){
    //create the string
    edk::int64* temp = (edk::int64*)this->readBin(sizeof(edk::int64)*size);edkEnd();
    if(temp){
        //return the string
        return temp;edkEnd();
    }
    //else return NULL
    return NULL;
}

edk::char8* edk::File::getName(){
    return this->name;edkEnd();
}

//SEEK the file
bool edk::File::seek(edk::uint32 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseek(this->arq,bytes,SEEK_CUR);edkEnd();
        //return true
        return true;
    }
    return false;
}
bool edk::File::seek(edk::uint64 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseeko64(this->arq,bytes,SEEK_CUR);edkEnd();
        //return true
        return true;
    }
    return false;
}
bool edk::File::seek(edk::int32 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseek(this->arq,bytes,SEEK_CUR);edkEnd();
        //return true
        return true;
    }
    return false;
}
bool edk::File::seek(edk::int64 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseeko64(this->arq,bytes,SEEK_CUR);edkEnd();
        //return true
        return true;
    }
    return false;
}
bool edk::File::seekStart(){
    //test if the file is opened
    if(this->isOpened()){
        fseek(this->arq,0,SEEK_SET);edkEnd();
        //return true
        return true;
    }
    return false;
}
bool edk::File::seekStart64(){
    //test if the file is opened
    if(this->isOpened()){
        fseeko64(this->arq,0,SEEK_SET);edkEnd();
        //return true
        return true;
    }
    return false;
}
bool edk::File::seekStart(edk::uint32 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseek(this->arq,bytes,SEEK_SET);edkEnd();
        //return true
        return true;
    }
    return false;
}
bool edk::File::seekStart(edk::uint64 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseeko64(this->arq,bytes,SEEK_SET);edkEnd();
        //return true
        return true;
    }
    return false;
}
bool edk::File::seekEnd(){
    //test if the file is opened
    if(this->isOpened()){
        fseek(this->arq,0,SEEK_END);edkEnd();
        //return true
        return true;
    }
    return false;
}
bool edk::File::seekEnd64(){
    //test if the file is opened
    if(this->isOpened()){
        fseeko64(this->arq,0,SEEK_END);edkEnd();
        //return true
        return true;
    }
    return false;
}
bool edk::File::seekEnd(edk::int32 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseek(this->arq,bytes,SEEK_END);edkEnd();
        //return true
        return true;
    }
    return false;
}
bool edk::File::seekEnd(edk::int64 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseeko64(this->arq,bytes,SEEK_END);edkEnd();
        //return true
        return true;
    }
    return false;
}
//return this current position
edk::uint32 edk::File::getSeek32(){
    return ftell(this->arq);edkEnd();
}
edk::uint64 edk::File::getSeek64(){
    return ftello64(this->arq);edkEnd();
}

//flush the file
bool edk::File::flush(){
    if(this->isOpened()){
        edk::int32 ret = fflush(this->arq);edkEnd();
        if(ret<0){ return false;}
        return true;
    }
    return false;
}

bool edk::File::isOpened(){
    //Test if have the ponter of the file
    if(this->arq){
        //return true
        return true;
    }
    //else return false
    return false;
}


edk::FileStream::FileStream(){
    this->arq=-1;edkEnd();
}
edk::FileStream::~FileStream(){
    this->closeFileStream();edkEnd();
}

bool edk::FileStream::openFileStream(edk::char8* name){
    //close the stream
    this->closeFileStream();edkEnd();
    if(name){
        this->arq = open(name, O_RDONLY);edkEnd();
        if(this->arq>=0){
            this->name.setName(name);edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::FileStream::openFileStream(const edk::char8* name){
    return this->openFileStream((edk::char8*) name);edkEnd();
}
void edk::FileStream::closeFileStream(){
    if(this->isOpened()){
        close(this->arq);edkEnd();
        this->arq=-1;edkEnd();
        this->name.cleanName();edkEnd();
    }
}
bool edk::FileStream::openFileStreamNonBlock(edk::char8* name){
    //close the stream
    this->closeFileStream();edkEnd();
    if(name){
#ifdef _WIN32
        this->arq = _open(name, O_RDONLY | FIONBIO);edkEnd();
#endif
#ifdef _WIN64
        this->arq = _open(name, O_RDONLY | FIONBIO);edkEnd();
#endif
#ifdef __linux__
        this->arq = open(name, O_RDONLY | O_NONBLOCK);edkEnd();
#endif
#ifdef __APPLE__
        this->arq = open(name, O_RDONLY | O_NONBLOCK);edkEnd();
#endif
        if(this->arq>=0){
            this->name.setName(name);edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::FileStream::openFileStreamNonBlock(const edk::char8* name){
    return this->openFileStreamNonBlock((edk::char8*) name);edkEnd();
}

edk::int64 edk::FileStream::readVec(edk::classID vec,uint64 size){
    edk::int64 ret=0;
    if(this->isOpened()){
        //
        ret = read(this->arq, vec, size);edkEnd();
        //test if the file is closed
        if(ret<0){
            if(errno!=EWOULDBLOCK){
                //file is closed
                this->closeFileStream();edkEnd();
            }
        }
    }
    return ret;
}
edk::int64 edk::FileStream::readVec(edk::classID vec,edk::uint32 size){
    edk::int32 ret=0;
    if(this->isOpened()){
        //
        ret = read(this->arq, vec, size);edkEnd();
        //test if the file is closed
        if(ret<0){
            if(errno!=EWOULDBLOCK){
                //file is closed
                this->closeFileStream();edkEnd();
            }
        }
    }
    return ret;
}
edk::char8 edk::FileStream::readChar8(){
    edk::char8 ret=0;
    this->readVec(&ret,sizeof(ret));edkEnd();
    return ret;
}
edk::uchar8 edk::FileStream::readUChar8(){
    edk::uchar8 ret=0;
    this->readVec(&ret,sizeof(ret));edkEnd();
    return ret;
}
edk::int8 edk::FileStream::readInt8(){
    edk::int8 ret=0;
    this->readVec(&ret,sizeof(ret));edkEnd();
    return ret;
}
edk::uint8 edk::FileStream::readUInt8(){
    edk::uint8 ret=0;
    this->readVec(&ret,sizeof(ret));edkEnd();
    return ret;
}
edk::int16 edk::FileStream::readInt16(){
    edk::int16 ret=0;
    this->readVec(&ret,sizeof(ret));edkEnd();
    return ret;
}
edk::uint16 edk::FileStream::readUInt16(){
    edk::uint16 ret=0;
    this->readVec(&ret,sizeof(ret));edkEnd();
    return ret;
}
edk::int32 edk::FileStream::readInt32(){
    edk::int32 ret=0;
    this->readVec(&ret,sizeof(ret));edkEnd();
    return ret;
}
edk::uint32 edk::FileStream::readUInt32(){
    edk::uint32 ret=0;
    this->readVec(&ret,sizeof(ret));edkEnd();
    return ret;
}
edk::float32 edk::FileStream::readFloat32(){
    edk::float32 ret=0;
    this->readVec(&ret,sizeof(ret));edkEnd();
    return ret;
}
edk::float64 edk::FileStream::readFloat64(){
    edk::float64 ret=0;
    this->readVec(&ret,sizeof(ret));edkEnd();
    return ret;
}

edk::int32 edk::FileStream::ioControl(edk::uint32
                                      #ifdef _WIN32
                                      #endif
                                      #ifdef _WIN64
                                      #endif
                                      #ifdef __linux__
                                      __request
                                      #endif
                                      #ifdef __APPLE__
                                      __request
                                      #endif
                                      ,void* value
                                      ){
    edk::int32 ret = -1;edkEnd();
    if(this->isOpened()){
        if(value){
#ifdef _WIN32

#endif
#ifdef _WIN64

#endif
#ifdef __linux__
            ret = ioctl(this->arq,__request,value);edkEnd();
#endif
#ifdef __APPLE__
            ret = ioctl(this->arq,__request,value);edkEnd();
#endif
        }
    }
    return ret;
}

edk::char8* edk::FileStream::getName(){
    return this->name.getName();edkEnd();
}

bool edk::FileStream::isOpened(){
    if(this->arq>=0){
        return true;
    }
    return false;
}
