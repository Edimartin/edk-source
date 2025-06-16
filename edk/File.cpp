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
#pragma message "            Inside File.cpp"
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
            i++;
        }
    }
    return false;
}

//Read the string from the file
edk::char8* edk::File::readStringFromTheFile(FILE* arq,edk::char8 limit,edk::uint32 count,bool use){
    //First read the next character
    edk::char8 temp = '\0';

    //string return
    edk::char8* ret = NULL;

    //test if have the end of the file
    if(feof(arq)){
        //then create the simple string
        edk::char8* str = (edk::char8*)malloc(sizeof(edk::char8) * (count+1u));
        //copy the end character '\0'
        if(str){
            //
            str[count]='\0';
        }
        //return the string
        return str;
    }

#ifdef _WIN32
    //Windows 32
#ifdef _MSC_VER
    //Visual C
    fscanf_s(arq,"%c",&temp);
#endif
#ifdef __GNUC__
#ifdef __cplusplus
    //G++
    fscanf(arq,"%c",&temp);
#else
    //GCC
#endif
#endif
#endif
#ifdef _WIN64
    //Windows 64
#ifdef _MSC_VER
    //Visual C
    fscanf_s(arq,"%c",&temp);
#endif
#ifdef __GNUC__
#ifdef __cplusplus
    //G++
    fscanf(arq,"%c",&temp);
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
    fscanf(arq,"%c",&temp);
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
    fscanf(arq,"%c",&temp);
#else
    //GCC
#endif
#endif
#endif
    //test if read the end character or the end of the file

    if(feof(arq) || temp==limit || temp=='\0'){
        //have the end of the read

        //alloc the new string
        edk::char8* str = NULL;
        //test if use the limit character
        if(use && temp!='\0'){
            //Copy the end and the limit character
            str = (edk::char8*)malloc(sizeof(edk::char8) * (count+2u));
            if(str){
                //
                str[count+1u]='\0';
                str[count]=limit;
            }
        }
        else{
            //Copy just the end character
            str = (edk::char8*)malloc(sizeof(edk::char8) * (count+1u));
            if(str){
                //
                str[count]='\0';
            }
        }
        //return the string
        return str;
    }
    else{
        //keep trying
        ret = this->readStringFromTheFile(arq,limit,count+1u,use);

        //Test if the ret is alloc
        if(ret){
            //then copy the character readed (temp)
            ret[count]=temp;
        }
    }
    //return the ret string
    return ret;
}
edk::char8* edk::File::readStringFromTheFile(FILE* arq,edk::char8* limits,edk::uint32 count,bool use){

    //First read the next character
    edk::char8 temp = '\0';

    //string return
    edk::char8* ret = NULL;

    //test if have the end of the file
    if(feof(arq)){
        //then create the simple string
        edk::char8* str = (edk::char8*)malloc(sizeof(edk::char8) * (count+1u));
        //copy the end character '\0'
        if(str){
            //
            str[count]='\0';
        }
        //return the string
        return str;
    }

#ifdef _WIN32
    //Windows 32
#ifdef _MSC_VER
    //Visual C
    fscanf_s(arq,"%c",&temp);
#endif
#ifdef __GNUC__
#ifdef __cplusplus
    //G++
    fscanf(arq,"%c",&temp);
#else
    //GCC
#endif
#endif
#endif
#ifdef _WIN64
    //Windows 64
#ifdef _MSC_VER
    //Visual C
    fscanf_s(arq,"%c",&temp);
#endif
#ifdef __GNUC__
#ifdef __cplusplus
    //G++
    fscanf(arq,"%c",&temp);
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
    fscanf(arq,"%c",&temp);
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
    fscanf(arq,"%c",&temp);
#else
    //GCC
#endif
#endif
#endif
    //test if read the end character or the end of the file

    if(feof(arq) || testLimits(temp,limits) || temp=='\0'){
        //have the end of the read

        //alloc the new string
        edk::char8* str = NULL;
        //test if use the limit character
        if(use && temp!='\0'){
            //Copy the end and the limit character
            str = (edk::char8*)malloc(sizeof(edk::char8) * (count+2u));
            if(str){
                //
                str[count+1u]='\0';
                str[count]=temp;
            }
        }
        else{
            //Copy just the end character
            str = (edk::char8*)malloc(sizeof(edk::char8) * (count+1u));
            if(str){
                //
                str[count]='\0';
            }
        }
        //return the string
        return str;
    }
    else{
        //keep trying
        ret = this->readStringFromTheFile(arq,limits,count+1u,use);

        //Test if the ret is alloc
        if(ret){
            //then copy the character readed (temp)
            ret[count]=temp;
        }
    }
    //return the ret string
    return ret;
}
edk::char8* edk::File::readStringFromTheBinFile(FILE* arq,edk::char8 limit,edk::uint32 count,bool use){
    //First read the next character
    edk::char8 temp = '\0';

    //string return
    edk::char8* ret = NULL;

    //test if have the end of the file
    if(feof(arq)){
        //then create the simple string
        edk::char8* str = (edk::char8*)malloc(sizeof(edk::char8) * (count+1u));
        //copy the end character '\0'
        if(str){
            //
            str[count]='\0';
        }
        //return the string
        return str;
    }

    fread(&temp,1u,1u,this->arq);
    //test if read the end character or the end of the file

    if(feof(arq) || temp==limit || temp=='\0'){
        //have the end of the read

        //alloc the new string
        edk::char8* str = NULL;
        //test if use the limit character
        if(use && temp!='\0'){
            //Copy the end and the limit character
            str = (edk::char8*)malloc(sizeof(edk::char8) * (count+2u));
            if(str){
                //
                str[count+1u]='\0';
                str[count]=limit;
            }
        }
        else{
            //Copy just the end character
            str = (edk::char8*)malloc(sizeof(edk::char8) * (count+1u));
            if(str){
                //
                str[count]='\0';
            }
        }
        //return the string
        return str;
    }
    else{
        //keep trying
        ret = this->readStringFromTheBinFile(arq,limit,count+1u,use);

        //Test if the ret is alloc
        if(ret){
            //then copy the character readed (temp)
            ret[count]=temp;
        }
    }
    //return the ret string
    return ret;
}
edk::char8* edk::File::readStringFromTheBinFile(FILE* arq,edk::char8* limits,edk::uint32 count,bool use){

    //First read the next character
    edk::char8 temp = '\0';

    //string return
    edk::char8* ret = NULL;

    //test if have the end of the file
    if(feof(arq)){
        //then create the simple string
        edk::char8* str = (edk::char8*)malloc(sizeof(edk::char8) * (count+1u));
        //copy the end character '\0'
        if(str){
            //
            str[count]='\0';
        }
        //return the string
        return str;
    }

    fread(&temp,1u,1u,this->arq);

    //test if read the end character or the end of the file
    if(feof(arq) || testLimits(temp,limits) || temp=='\0'){
        //have the end of the read

        //alloc the new string
        edk::char8* str = NULL;
        //test if use the limit character
        if(use && temp!='\0'){
            //Copy the end and the limit character
            str = (edk::char8*)malloc(sizeof(edk::char8) * (count+2u));
            if(str){
                //
                str[count+1u]='\0';
                str[count]=temp;
            }
        }
        else{
            //Copy just the end character
            str = (edk::char8*)malloc(sizeof(edk::char8) * (count+1u));
            if(str){
                //
                str[count]='\0';
            }
        }
        //return the string
        return str;
    }
    else{
        //keep trying
        ret = this->readStringFromTheBinFile(arq,limits,count+1u,use);

        //Test if the ret is alloc
        if(ret){
            //then copy the character readed (temp)
            ret[count]=temp;
        }
    }
    //return the ret string
    return ret;
}






edk::File::File(){
    this->classThis=NULL;
    this->Constructor();
}

edk::File::~File(){
    this->Destructor();
}

void edk::File::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;
        //clean the atributes
        this->arq=NULL;
        this->name=NULL;
        this->size=0u;
    }
}
void edk::File::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        //close the file
        this->closeFile();
    }
}

edk::uint64 edk::File::getFileSize(){
    if(this->isOpened()){
        //if(!this->size){
        //load fileSize
        edk::uint64 position = this->getSeek64();
        this->seekEnd();
        this->size = this->getSeek64();
        this->seekStart(position);
        //}
        return this->size;
    }
    return 0u;
}

bool edk::File::openTextFile(edk::char8 *name){
    //Close the file
    this->closeFile();

    //Then open the file in your compiler
    if((const edk::char8*)name && edk::File::isFile(name)){

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fopen_s(&arq,name,"r");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"r");
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fopen_s(&arq,name,"r");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"r");
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
        arq=fopen((const edk::char8*)name,"r");
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
        arq=fopen((const edk::char8*)name,"r");
#else
        //GCC
#endif
#endif
#endif
        //Test if open the file
        if(this->isOpened()){
            //then copy the things of the file

            //The size of the file
            fseek ( this->arq , 0 , SEEK_END );
            //this->size = ftell(this->arq);
            //Come back to the start
            fseek ( arq , 0 , SEEK_SET );

            //Copy the name of the file
            this->name = edk::String::strCopy(name);

            //return true
            return true;
        }
        else{
            //Else he can't open the file
            arq=NULL;
        }
    }
    return false;
}

bool edk::File::openTextFile(const edk::char8 *name){
    return this->openTextFile((edk::char8*)name);
}

bool edk::File::openBinFile(edk::char8 *name){
    //Close the file
    this->closeFile();

    //Then open the file in your compiler
    if((const edk::char8*)name && edk::File::isFile(name)){

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fopen_s(&arq,name,"rb");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"rb");
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fopen_s(&arq,name,"rb");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"rb");
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
        arq=fopen((const edk::char8*)name,"rb");
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
        arq=fopen((const edk::char8*)name,"rb");
#else
        //GCC
#endif
#endif
#endif
        //Test if open the file
        if(this->isOpened()){
            //then copy the things of the file

            //The size of the file
            fseek ( this->arq , 0 , SEEK_END );
            //this->size = ftell(this->arq);
            //Come back to the start
            fseek ( arq , 0 , SEEK_SET );

            //Copy the name of the file
            this->name = edk::String::strCopy(name);

            //return true
            return true;
        }
        else{
            //Else he can't open the file
            arq=NULL;
        }
    }
    return false;
}

bool edk::File::openBinFile(const edk::char8 *name){
    return this->openBinFile((edk::char8*)name);
}

bool edk::File::openEndTextFile(edk::char8 *name){
    //Close the file
    this->closeFile();

    //Then open the file in your compiler
    if((const edk::char8*)name && edk::File::isFile(name)){

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fopen_s(&arq,name,"a");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"a");
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fopen_s(&arq,name,"a");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"a");
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
        arq=fopen((const edk::char8*)name,"a");
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
        arq=fopen((const edk::char8*)name,"a");
#else
        //GCC
#endif
#endif
#endif
        //Test if open the file
        if(this->isOpened()){
            //then copy the things of the file

            //The size of the file
            fseek ( this->arq , 0 , SEEK_END );
            //this->size = ftell(this->arq);
            //Come back to the start
            //fseek ( arq , 0 , SEEK_SET );

            //Copy the name of the file
            this->name = edk::String::strCopy(name);

            //return true
            return true;
        }
        else{
            //Else he can't open the file
            arq=NULL;
        }
    }
    return false;
}

bool edk::File::openEndTextFile(const edk::char8 *name){
    return this->openEndTextFile((edk::char8 *)name);
}

bool edk::File::openEndBinFile(edk::char8 *name){
    //Close the file
    this->closeFile();

    //Then open the file in your compiler
    if((const edk::char8*)name && edk::File::isFile(name)){

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fopen_s(&arq,name,"ab");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"ab");
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fopen_s(&arq,name,"ab");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=fopen((const edk::char8*)name,"ab");
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
        arq=fopen((const edk::char8*)name,"ab");
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
        arq=fopen((const edk::char8*)name,"ab");
#else
        //GCC
#endif
#endif
#endif
        //Test if open the file
        if(this->isOpened()){
            //then copy the things of the file

            //The size of the file
            fseek ( this->arq , 0 , SEEK_END );
            //this->size = ftell(this->arq);
            //Come back to the start
            //fseek ( arq , 0 , SEEK_SET );

            //Copy the name of the file
            this->name = edk::String::strCopy(name);

            //return true
            return true;
        }
        else{
            //Else he can't open the file
            arq=NULL;
        }
    }
    return false;
}

bool edk::File::openEndBinFile(const edk::char8 *name){
    return this->openEndBinFile((edk::char8*)name);
}

//PIPE
bool edk::File::openPipe(edk::char8 *name){
    //Close the file
    this->closeFile();

    //Then open the file in your compiler
    if((const edk::char8*)name){

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        popen_s(&arq,name,"r");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=popen((const edk::char8*)name,"r");
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        popen_s(&arq,name,"r");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=popen((const edk::char8*)name,"r");
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
        arq=popen((const edk::char8*)name,"r");
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
        arq=popen((const edk::char8*)name,"r");
#else
        //GCC
#endif
#endif
#endif
        //Test if open the file
        if(this->isOpened()){
            //then copy the things of the file

            //The size of the file
            fseek ( this->arq , 0 , SEEK_END );
            //this->size = ftell(this->arq);
            //Come back to the start
            //fseek ( arq , 0 , SEEK_SET );

            //Copy the name of the file
            this->name = edk::String::strCopy(name);

            //return true
            return true;
        }
        else{
            //Else he can't open the file
            arq=NULL;
        }
    }
    return false;
}
bool edk::File::openPipe(const edk::char8 *name){
    return this->openPipe((edk::char8 *)name);
}

void edk::File::closeFile(){
    //Test if the file is opened
    if(this->isOpened()){
        this->flush();
        //Then close the file
        fclose(this->arq);
    }
    //clean the atributes
    this->arq=NULL;
    this->size=0u;

    //Delete the name if the name exist
    if(this->name){
        //
        free(this->name);
    }
    this->name=NULL;
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
    return deleteFile((edk::char8 *)name);
}

bool edk::File::deleteFile(){
    //Test if the file is opened
    if(this->isOpened()){
        //copy the name of the file
        edk::char8* tempName =NULL;
        if(this->name){
            tempName = edk::String::strCopy(this->name);
        }
        //create a return
        bool ret=false;
        //Close the file
        this->closeFile();
        //Test if copy the name
        if(tempName){
            //Then try remove the file
            ret=edk::File::deleteFile(tempName);

            //delete the tempName
            free (tempName);
        }
        tempName=NULL;
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
    return renameFile((edk::char8 *)oldName, (edk::char8 *)newName);
}

bool edk::File::createFile(edk::char8 *name){
    //Use a file
    FILE *tempArq=NULL;

    //test the name of the file
    if((const edk::char8*)name){
        //Create the file
#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fopen_s(&tempArq,name,"wb");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        tempArq=fopen((const edk::char8*)name,"wb");
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fopen_s(&tempArq,name,"wb");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        tempArq=fopen((const edk::char8*)name,"wb");
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
        tempArq=fopen((const edk::char8*)name,"wb");
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
        tempArq=fopen((const edk::char8*)name,"wb");
#else
        //GCC
#endif
#endif
#endif

        //Test if create the file
        if(tempArq){
            //close the file
            fclose(tempArq);
            //clean the tempArq
            tempArq=NULL;
            //return true
            return true;
        }
    }
    //Else return false
    return false;
}

bool edk::File::createFile(const edk::char8 *name){
    return createFile((edk::char8 *)name);
}

//return true if is a file
bool edk::File::isFile(edk::char8 *name){
    if(name){
        struct stat path_stat;
        stat(name, &path_stat);
        return S_ISREG(path_stat.st_mode);
    }
    return false;
}
bool edk::File::isFile(const edk::char8* name){
    //
    return edk::File::isFile((edk::char8*)name);
}

//return the size of a file
edk::uint64 edk::File::fileSize(edk::char8 *name){
    edk::uint64 size=0u;
    edk::File file;
    if(file.openBinFile(name)){
        size = file.getFileSize();
    }
    return size;
}
edk::uint64 edk::File::fileSize(const edk::char8 *name){
    return edk::File::fileSize((edk::char8 *)name);
}

//return the lines size of a file
edk::uint64 edk::File::fileLinesSize(edk::char8 *name){
    edk::uint64 size=0u;
    edk::File file;
    if(file.openBinFile(name)){
        edk::char8 str[1024u+1u];
        edk::uint16 limit = sizeof(str)-1u;
        edk::uint16 readed;
        while(!file.endOfFile()){
            readed = file.readBin(str,limit);
            for(edk::uint16 i=0u;i<readed;i++){
                if(str[i]=='\n' || str[i]==10 || str[i]==13){
                    size++;
                }
            }
        }
    }
    return size;
}
edk::uint64 edk::File::fileLinesSize(const edk::char8 *name){
    return edk::File::fileSize((edk::char8 *)name);
}

bool edk::File::createAndOpenTextFile(edk::char8 *name){
    //Close the file
    this->closeFile();

    //Then open the file in your compiler
    if((const edk::char8*)name){

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fopen_s(&this->arq,name,"w");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        this->arq=fopen((const edk::char8*)name,"w");
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fopen_s(&this->arq,name,"w");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        this->arq=fopen((const edk::char8*)name,"w");
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
        this->arq=fopen((const edk::char8*)name,"w");
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
        this->arq=fopen((const edk::char8*)name,"w");
#else
        //GCC
#endif
#endif
#endif
        //Test if open the file
        if(this->isOpened()){
            //Copy the name of the file
            this->name = edk::String::strCopy(name);

            //return true
            return true;
        }
        else{
            //Else he can't open the file
            this->arq=NULL;
        }
    }
    return false;
}

bool edk::File::createAndOpenTextFile(const edk::char8 *name){
    return createAndOpenTextFile((edk::char8 *)name);
}

bool edk::File::createAndOpenBinFile(edk::char8 *name){
    //Close the file
    this->closeFile();

    //Then open the file in your compiler
    if((const edk::char8*)name){

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fopen_s(&this->arq,name,"wb");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        this->arq=fopen((const edk::char8*)name,"wb");
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fopen_s(&this->arq,name,"wb");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        this->arq=fopen((const edk::char8*)name,"wb");
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
        this->arq=fopen((const edk::char8*)name,"wb");
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
        this->arq=fopen((const edk::char8*)name,"wb");
#else
        //GCC
#endif
#endif
#endif
        //Test if open the file
        if(this->isOpened()){
            //Copy the name of the file
            this->name = edk::String::strCopy(name);

            //return true
            return true;
        }
        else{
            //Else he can't open the file
            this->arq=NULL;
        }
    }
    return false;
}

bool edk::File::createAndOpenBinFile(const edk::char8 *name){
    return createAndOpenBinFile((edk::char8 *)name);
}

//PIPE
bool edk::File::createAndOpenPipe(edk::char8* name){
    //Close the file
    this->closeFile();

    //Then open the file in your compiler
    if((const edk::char8*)name){

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        popen_s(&arq,name,"w");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=popen((const edk::char8*)name,"w");
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        popen_s(&arq,name,"ab");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        arq=popen((const edk::char8*)name,"w");
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
        arq=popen((const edk::char8*)name,"w");
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
        arq=popen((const edk::char8*)name,"w");
#else
        //GCC
#endif
#endif
#endif
        //Test if open the file
        if(this->isOpened()){
            //then copy the things of the file

            //The size of the file
            fseek ( this->arq , 0 , SEEK_END );
            //this->size = ftell(this->arq);
            //Come back to the start
            //fseek ( arq , 0 , SEEK_SET );

            //Copy the name of the file
            this->name = edk::String::strCopy(name);

            //return true
            return true;
        }
        else{
            //Else he can't open the file
            arq=NULL;
        }
    }
    return false;
}
bool edk::File::createAndOpenPipe(const edk::char8* name){
    return this->createAndOpenPipe((edk::char8*) name);
}

bool edk::File::fileExist(edk::char8 *name){
    //create a tempFile
    FILE *tempArq=NULL;
    //Test the name
    if((const edk::char8*)name){
        //Try open the file

#ifdef _WIN32
        //Windows 32
#ifdef _MSC_VER
        //Visual C
        fopen_s(&tempArq,name,"r");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        tempArq=fopen((const edk::char8*)name,"r");
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fopen_s(&tempArq,name,"r");
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        tempArq=fopen((const edk::char8*)name,"r");
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
        tempArq=fopen((const edk::char8*)name,"r");
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
        tempArq=fopen((const edk::char8*)name,"r");
#else
        //GCC
#endif
#endif
#endif

        //Test if open the file
        if(tempArq){
            //then the file Exist
            //close the file
            fclose(tempArq);
            //return true
            return true;
        }
    }
    return false;
}

bool edk::File::fileExist(const edk::char8 *name){
    return fileExist((edk::char8 *)name);
}

//test if the folder exist in the computer
bool edk::File::folderExist(edk::char8 *name){
    if(name){
        struct stat path_stat;
        stat(name, &path_stat);
        return S_ISDIR(path_stat.st_mode);
    }
    return false;
}
bool edk::File::folderExist(const edk::char8* name){
    return edk::File::folderExist((edk::char8*) name);
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
    return this->readEnd();
}

bool edk::File::writeText(edk::char8 c){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%c",c);
        //return true
        return true;
    }
    return false;
}

bool edk::File::writeText(edk::char8 *str){
    //Test if the file is opened and if the string is true
    if(this->isOpened() && str){
        //Then write in the file
        edk::int32 ret = fprintf(this->arq,"%s",str);
        if(ret>=0){
            return true;
        }
    }
    return false;
}

bool edk::File::writeText(const edk::char8 *str){
    return writeText((edk::char8 *)str);
}

bool edk::File::writeText(edk::int8 n){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%d",n);
        //return true
        return true;
    }
    return false;
}

bool edk::File::writeText(edk::uint8 n){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%u",n);
        //return true
        return true;
    }
    return false;
}

bool edk::File::writeText(edk::int16 n){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%d",n);
        //return true
        return true;
    }
    return false;
}

bool edk::File::writeText(edk::uint16 n){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%u",n);
        //return true
        return true;
    }
    return false;
}

bool edk::File::writeText(edk::int32 n){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%d",n);
        //return true
        return true;
    }
    return false;
}

bool edk::File::writeText(edk::uint32 n){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%u",n);
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
        fprintf(this->arq,"%I64d",n);
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
        fprintf(this->arq,"%ld",n);
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
        fprintf(this->arq,"%lld",n);
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
        fprintf(this->arq,"%I64u",n);
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
        fprintf(this->arq,"%lu",n);
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
        fprintf(this->arq,"%llu",n);
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
        fprintf(this->arq,"%f",f);
        //return true
        return true;
    }
    return false;
}

bool edk::File::writeText(edk::float32 f,edk::uint8 digits){
    bool ret = false;
    //Test if the file is opened
    if(this->isOpened()){
        edk::char8* strDigits = edk::String::uint32ToStr(digits);
        if(strDigits){
            edk::char8* str = edk::String::strCatMulti("%.",strDigits,"f",NULL);
            if(str){
                //Then write in the file
                fprintf(this->arq,str,f);
                ret = true;
                free(str);
            }
            free(strDigits);
        }
    }
    return ret;
}

bool edk::File::writeText(edk::float64 f){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%lf",f);
        //return true
        return true;
    }
    return false;
}

bool edk::File::writeText(edk::float64 f,edk::uint8 digits){
    bool ret = false;
    //Test if the file is opened
    if(this->isOpened()){
        edk::char8* strDigits = edk::String::uint32ToStr(digits);
        if(strDigits){
            edk::char8* str = edk::String::strCatMulti("%.",strDigits,"lf",NULL);
            if(str){
                //Then write in the file
                fprintf(this->arq,str,f);
                ret = true;
                free(str);
            }
            free(strDigits);
        }
    }
    return ret;
}

bool edk::File::writeBin(edk::classID w, edk::uint32 size){
    //test if the file is opened and if the w is true and the size is >1u
    if(this->isOpened() && w && size){
        //
        fwrite(w,size,1u,this->arq);
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
        fwrite(&c,sizeof(edk::char8),1u,this->arq);
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
        fwrite(str,sizeof(edk::char8),edk::String::strSize(str),this->arq);
        //return true
        return true;
    }
    //else return false
    return false;
}

bool edk::File::writeBin(const edk::char8 *str){
    return writeBin((edk::char8 *)str);
}

bool edk::File::writeBin(edk::int8 n){
    //test if the file is opened
    if(this->isOpened()){
        //
        fwrite(&n,sizeof(edk::int8),1u,this->arq);
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
        fwrite(n,sizeof(edk::int8),sizeof(n),this->arq);
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
        fwrite(&n,sizeof(edk::uint8),1u,this->arq);
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
        fwrite(n,sizeof(edk::uint8),sizeof(n),this->arq);
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
        fwrite(&n,sizeof(edk::int16),1u,this->arq);
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
        fwrite(n,sizeof(edk::int16),sizeof(n),this->arq);
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
        fwrite(&n,sizeof(edk::uint16),1u,this->arq);
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
        fwrite(n,sizeof(edk::uint16),sizeof(n),this->arq);
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
        fwrite(&n,sizeof(edk::int32),1u,this->arq);
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
        fwrite(n,sizeof(edk::int32),sizeof(n),this->arq);
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
        fwrite(&n,sizeof(edk::uint32),1u,this->arq);
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
        fwrite(n,sizeof(edk::uint32),sizeof(n),this->arq);
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
        fwrite(&f,sizeof(edk::float32),1u,this->arq);
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
        fwrite(f,sizeof(edk::float32),sizeof(f),this->arq);
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
        fwrite(&n,sizeof(edk::uint64),1u,this->arq);
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
        fwrite(n,sizeof(edk::uint64),sizeof(n),this->arq);
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
        fwrite(&n,sizeof(edk::int64),1u,this->arq);
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
        fwrite(n,sizeof(edk::int64),sizeof(n),this->arq);
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
        fwrite(&f,sizeof(edk::float64),1u,this->arq);
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
        fwrite(f,sizeof(edk::float64),sizeof(f),this->arq);
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
        fwrite(&b,sizeof(bool),1u,this->arq);
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
        fwrite(b,sizeof(bool),sizeof(b),this->arq);
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
        fscanf_s(this->arq,"%c",&c);
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%c",&c);
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fscanf_s(this->arq,"%c",&c);
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%c",&c);
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
        fscanf(this->arq,"%c",&c);
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
        fscanf(this->arq,"%c",&c);
#else
        //GCC
#endif
#endif
#endif
    }
    //else return false
    return c;
}

edk::char8* edk::File::readTextString(edk::uint32 limit, bool use){
    return this->readTextString((edk::char8) limit, use);
}
edk::char8* edk::File::readTextString(edk::uint64 limit, bool use){
    return this->readTextString((edk::char8) limit, use);
}
edk::char8* edk::File::readTextString(edk::uint8 limit, bool use){
    return this->readTextString((edk::char8) limit, use);
}

edk::char8* edk::File::readTextString(edk::char8 limit, bool use){
    //test if the file os opened
    if(this->isOpened()){
        //read the string
        return this->readStringFromTheFile(this->arq,limit,0u,use);
    }
    //else return NULL
    return NULL;
}

edk::char8* edk::File::readTextString(edk::char8 *limits, bool use){
    //test if the file os opened
    if(this->isOpened()&&limits){
        //read the string
        return this->readStringFromTheFile(this->arq,limits,0u,use);
    }
    //else return NULL
    return NULL;
}

edk::char8* edk::File::readTextString(const edk::char8 *limits, bool use){
    return this->readTextString((edk::char8 *)limits, use);
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
        fscanf_s(this->arq,"%d",&n);
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%d",&n);
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fscanf_s(this->arq,"%d",&n);
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%d",&n);
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
        fscanf(this->arq,"%d",&n);
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
        fscanf(this->arq,"%d",&n);
#else
        //GCC
#endif
#endif
#endif
    }
    //else return false
    return n;
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
        fscanf_s(this->arq,"%u",&n);
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%u",&n);
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fscanf_s(this->arq,"%u",&n);
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%u",&n);
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
        fscanf(this->arq,"%u",&n);
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
        fscanf(this->arq,"%u",&n);
#else
        //GCC
#endif
#endif
#endif
    }
    //else return false
    return n;
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
        fscanf_s(this->arq,"%f",&f);
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%f",&f);
#else
        //GCC
#endif
#endif
#endif
#ifdef _WIN64
        //Windows 64
#ifdef _MSC_VER
        //Visual C
        fscanf_s(this->arq,"%f",&f);
#endif
#ifdef __GNUC__
#ifdef __cplusplus
        //G++
        fscanf(this->arq,"%f",&f);
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
        fscanf(this->arq,"%f",&f);
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
        fscanf(this->arq,"%f",&f);
#else
        //GCC
#endif
#endif
#endif
    }
    //else return false
    return f;
}

edk::classID edk::File::readBin(edk::uint64 size){
    //create the return
    void* ret=NULL;
    //test if the file is opened and the size is >1u
    if(this->isOpened() && size){
        //alloc the return
        ret=malloc(size);
        if(ret){
            //fread(ret,1u,size,this->arq);
            this->readBin(ret,size);
            return ret;
        }
    }
    return ret;
}

edk::uint64 edk::File::readBin(edk::classID vec,uint64 size){
    edk::uint64 ret = 0u;
    if(size && vec){
        ret = fread(vec,1u,size,this->arq);
    }
    return ret;
}

edk::char8 edk::File::readBinChar(){
    //read the size
    edk::char8* temp = (edk::char8*)this->readBin(sizeof(edk::char8));
    //create the edk::char8
    edk::char8 c = '\0';
    if(temp){
        //copy the edk::char8
        c = *temp;

        //delete temp
        free(temp);
    }
    temp=NULL;

    //return the edk::char8
    return c;
}

edk::char8* edk::File::readBinString(char64 size){
    //create the string
    edk::char8* temp = (edk::char8*)this->readBin(sizeof(edk::char8)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}

edk::char8* edk::File::readBinString(edk::char8 limit, bool use){
    //test if the file os opened
    if(this->isOpened()){
        //read the string
        return this->readStringFromTheBinFile(this->arq,limit,0u,use);
    }
    //else return NULL
    return NULL;
}

edk::char8* edk::File::readBinString(edk::char8 *limits, bool use){
    //test if the file os opened
    if(this->isOpened()){
        //read the string
        return this->readStringFromTheBinFile(this->arq,limits,0u,use);
    }
    //else return NULL
    return NULL;
}

edk::char8* edk::File::readBinString(const edk::char8 *limits, bool use){
    return this->readBinString((edk::char8 *)limits,use);
}

//read to a string
edk::uint64 edk::File::readBinString(edk::char8 *str,edk::uint64 size){
    edk::uint64 ret=0u;
    if(str && size){
        ret = this->readBin(str,size);
    }
    return ret;
}

edk::int8 edk::File::readBinInt8(){
    //read the size
    edk::int8* temp = (edk::int8*)this->readBin(sizeof(edk::int8));
    //create the edk::char8
    edk::int8 n = 0u;
    if(temp){
        //copy the edk::char8
        n = *temp;

        //delete temp
        free(temp);
    }
    temp=NULL;

    //return the edk::char8
    return n;
}

edk::int8* edk::File::readBinInt8(edk::int64 size){
    //create the string
    edk::int8* temp = (edk::int8*)this->readBin(sizeof(edk::int8)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}

edk::uint8 edk::File::readBinUInt8(){
    //read the size
    edk::uint8* temp = (edk::uint8*)this->readBin(sizeof(edk::uint8));
    //create the edk::char8
    edk::uint8 n = 0u;
    if(temp){
        //copy the edk::char8
        n = *temp;

        //delete temp
        free(temp);
    }
    temp=NULL;

    //return the edk::char8
    return n;
}

edk::uint8* edk::File::readBinUint8(edk::uint64 size){
    //create the string
    edk::uint8* temp = (edk::uint8*)this->readBin(sizeof(edk::uint8)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}

edk::int16 edk::File::readBinInt16(){
    //read the size
    edk::int16* temp = (edk::int16*)this->readBin(sizeof(edk::int16));
    //create the edk::char8
    edk::int16 n = 0u;
    if(temp){
        //copy the edk::char8
        n = *temp;

        //delete temp
        free(temp);
    }
    temp=NULL;

    //return the edk::char8
    return n;
}

edk::int16* edk::File::readBinInt16(edk::int16 size){
    //create the string
    edk::int16* temp = (edk::int16*)this->readBin(sizeof(edk::int16)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}

edk::uint16 edk::File::readBinUInt16(){
    //read the size
    edk::uint16* temp = (edk::uint16*)this->readBin(sizeof(edk::uint16));
    //create the edk::char8
    edk::uint16 n = 0u;
    if(temp){
        //copy the edk::char8
        n = *temp;

        //delete temp
        free(temp);
    }
    temp=NULL;

    //return the edk::char8
    return n;
}

edk::uint16* edk::File::readBinUint16(edk::uint16 size){
    //create the string
    edk::uint16* temp = (edk::uint16*)this->readBin(sizeof(edk::uint16)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}

edk::int32 edk::File::readBinInt32(){
    //read the size
    edk::int32* temp = (edk::int32*)this->readBin(sizeof(edk::int32));
    //create the edk::char8
    edk::int32 n = 0u;
    if(temp){
        //copy the edk::char8
        n = *temp;

        //delete temp
        free(temp);
    }
    temp=NULL;

    //return the edk::char8
    return n;
}

edk::int32* edk::File::readBinInt32(edk::int64 size){
    //create the string
    edk::int32* temp = (edk::int32*)this->readBin(sizeof(edk::int32)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}

edk::uint32 edk::File::readBinUInt32(){
    //read the size
    edk::uint32* temp = (edk::uint32*)this->readBin(sizeof(edk::uint32));
    //create the edk::char8
    edk::uint32 n = 0u;
    if(temp){
        //copy the edk::char8
        n = *temp;

        //delete temp
        free(temp);
    }
    temp=NULL;

    //return the edk::char8
    return n;
}

edk::uint32* edk::File::readBinUint32(edk::uint64 size){
    //create the string
    edk::uint32* temp = (edk::uint32*)this->readBin(sizeof(edk::uint32)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}

edk::int64 edk::File::readBinInt64(){
    //read the size
    edk::int64* temp = (edk::int64*)this->readBin(sizeof(edk::int64));
    //create the edk::char8
    edk::int64 n = 0u;
    if(temp){
        //copy the edk::char8
        n = *temp;

        //delete temp
        free(temp);
    }
    temp=NULL;

    //return the edk::char8
    return n;
}

edk::int64* edk::File::readBinInt64(edk::int64 size){
    //create the string
    edk::int64* temp = (edk::int64*)this->readBin(sizeof(edk::int64)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}

edk::uint64 edk::File::readBinUInt64(){
    //read the size
    edk::uint64* temp = (edk::uint64*)this->readBin(sizeof(edk::uint64));
    //create the edk::char8
    edk::uint64 n = 0u;
    if(temp){
        //copy the edk::char8
        n = *temp;

        //delete temp
        free(temp);
    }
    temp=NULL;

    //return the edk::char8
    return n;
}

edk::uint64* edk::File::readBinUint64(edk::uint64 size){
    //create the string
    edk::uint64* temp = (edk::uint64*)this->readBin(sizeof(edk::uint64)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}

edk::float32 edk::File::readBinFloat(){
    //read the size
    edk::float32* temp = (edk::float32*)this->readBin(sizeof(edk::float32));
    //create the edk::char8
    edk::float32 n = 0u;
    if(temp){
        //copy the edk::char8
        n = *temp;

        //delete temp
        free(temp);
    }
    temp=NULL;

    //return the edk::char8
    return n;
}

edk::float32* edk::File::readBinFloat(edk::int64 size){
    //create the string
    edk::float32* temp = (edk::float32*)this->readBin(sizeof(edk::float32)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}

edk::int64 edk::File::readBinLongInt(){
    //read the size
    edk::int64* temp = (edk::int64*)this->readBin(sizeof(edk::int64));
    //create the edk::char8
    edk::int64 n = 0u;
    if(temp){
        //copy the edk::char8
        n = *temp;

        //delete temp
        free(temp);
    }
    temp=NULL;

    //return the edk::char8
    return n;
}

edk::int64* edk::File::readBinLongInt(edk::int64 size){
    //create the string
    edk::int64* temp = (edk::int64*)this->readBin(sizeof(edk::int64)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}

edk::char8* edk::File::getName(){
    return this->name;
}

//SEEK the file
bool edk::File::seek(edk::uint32 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseek(this->arq,bytes,SEEK_CUR);
        //return true
        return true;
    }
    return false;
}
bool edk::File::seek(edk::uint64 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseeko64(this->arq,bytes,SEEK_CUR);
        //return true
        return true;
    }
    return false;
}
bool edk::File::seek(edk::int32 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseek(this->arq,bytes,SEEK_CUR);
        //return true
        return true;
    }
    return false;
}
bool edk::File::seek(edk::int64 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseeko64(this->arq,bytes,SEEK_CUR);
        //return true
        return true;
    }
    return false;
}
bool edk::File::seekStart(){
    //test if the file is opened
    if(this->isOpened()){
        fseek(this->arq,0,SEEK_SET);
        //return true
        return true;
    }
    return false;
}
bool edk::File::seekStart64(){
    //test if the file is opened
    if(this->isOpened()){
        fseeko64(this->arq,0,SEEK_SET);
        //return true
        return true;
    }
    return false;
}
bool edk::File::seekStart(edk::uint32 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseek(this->arq,bytes,SEEK_SET);
        //return true
        return true;
    }
    return false;
}
bool edk::File::seekStart(edk::uint64 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseeko64(this->arq,bytes,SEEK_SET);
        //return true
        return true;
    }
    return false;
}
bool edk::File::seekEnd(){
    //test if the file is opened
    if(this->isOpened()){
        fseek(this->arq,0,SEEK_END);
        //return true
        return true;
    }
    return false;
}
bool edk::File::seekEnd64(){
    //test if the file is opened
    if(this->isOpened()){
        fseeko64(this->arq,0,SEEK_END);
        //return true
        return true;
    }
    return false;
}
bool edk::File::seekEnd(edk::int32 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseek(this->arq,bytes,SEEK_END);
        //return true
        return true;
    }
    return false;
}
bool edk::File::seekEnd(edk::int64 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseeko64(this->arq,bytes,SEEK_END);
        //return true
        return true;
    }
    return false;
}
//return this current position
edk::uint32 edk::File::getSeek32(){
    return ftell(this->arq);
}
edk::uint64 edk::File::getSeek64(){
    return ftello64(this->arq);
}

//flush the file
bool edk::File::flush(){
    if(this->isOpened()){
#ifdef _WIN32
        _commit(_fileno(this->arq));
#endif
#ifdef _WIN64
        _commit(_fileno(this->arq));
#endif
#ifdef __linux__
#endif
#ifdef __APPLE__
#endif
        edk::int32 ret = fflush(this->arq);
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
    this->classThis=NULL;
    this->Constructor();
}
edk::FileStream::~FileStream(){
    this->Destructor();
}

void edk::FileStream::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        this->name.Constructor();

        this->arq=-1;
    }
}
void edk::FileStream::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->closeFileStream();
        this->name.Destructor();
    }
}

bool edk::FileStream::openFileStream(edk::char8* name){
    //close the stream
    this->closeFileStream();
    if(name){
        this->arq = open(name, O_RDONLY);
        if(this->arq>=0){
            this->name.setName(name);
            return true;
        }
    }
    return false;
}
bool edk::FileStream::openFileStream(const edk::char8* name){
    return this->openFileStream((edk::char8*) name);
}
void edk::FileStream::closeFileStream(){
    if(this->isOpened()){
        close(this->arq);
        this->arq=-1;
        this->name.cleanName();
    }
}
bool edk::FileStream::openFileStreamNonBlock(edk::char8* name){
    //close the stream
    this->closeFileStream();
    if(name){
#ifdef _WIN32
        this->arq = _open(name, O_RDONLY | FIONBIO);
#endif
#ifdef _WIN64
        this->arq = _open(name, O_RDONLY | FIONBIO);
#endif
#ifdef __linux__
        this->arq = open(name, O_RDONLY | O_NONBLOCK);
#endif
#ifdef __APPLE__
        this->arq = open(name, O_RDONLY | O_NONBLOCK);
#endif
        if(this->arq>=0){
            this->name.setName(name);
            return true;
        }
    }
    return false;
}
bool edk::FileStream::openFileStreamNonBlock(const edk::char8* name){
    return this->openFileStreamNonBlock((edk::char8*) name);
}

edk::int64 edk::FileStream::readVec(edk::classID vec,uint64 size){
    edk::int64 ret=0;
    if(this->isOpened()){
        //
        ret = read(this->arq, vec, size);
        //test if the file is closed
        if(ret<0){
            if(errno!=EWOULDBLOCK){
                //file is closed
                this->closeFileStream();
            }
        }
    }
    return ret;
}
edk::int64 edk::FileStream::readVec(edk::classID vec,edk::uint32 size){
    edk::int32 ret=0;
    if(this->isOpened()){
        //
        ret = read(this->arq, vec, size);
        //test if the file is closed
        if(ret<0){
            if(errno!=EWOULDBLOCK){
                //file is closed
                this->closeFileStream();
            }
        }
    }
    return ret;
}
edk::char8 edk::FileStream::readChar8(){
    edk::char8 ret=0;
    this->readVec(&ret,sizeof(ret));
    return ret;
}
edk::uchar8 edk::FileStream::readUChar8(){
    edk::uchar8 ret=0;
    this->readVec(&ret,sizeof(ret));
    return ret;
}
edk::int8 edk::FileStream::readInt8(){
    edk::int8 ret=0;
    this->readVec(&ret,sizeof(ret));
    return ret;
}
edk::uint8 edk::FileStream::readUInt8(){
    edk::uint8 ret=0;
    this->readVec(&ret,sizeof(ret));
    return ret;
}
edk::int16 edk::FileStream::readInt16(){
    edk::int16 ret=0;
    this->readVec(&ret,sizeof(ret));
    return ret;
}
edk::uint16 edk::FileStream::readUInt16(){
    edk::uint16 ret=0;
    this->readVec(&ret,sizeof(ret));
    return ret;
}
edk::int32 edk::FileStream::readInt32(){
    edk::int32 ret=0;
    this->readVec(&ret,sizeof(ret));
    return ret;
}
edk::uint32 edk::FileStream::readUInt32(){
    edk::uint32 ret=0;
    this->readVec(&ret,sizeof(ret));
    return ret;
}
edk::float32 edk::FileStream::readFloat32(){
    edk::float32 ret=0;
    this->readVec(&ret,sizeof(ret));
    return ret;
}
edk::float64 edk::FileStream::readFloat64(){
    edk::float64 ret=0;
    this->readVec(&ret,sizeof(ret));
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
    edk::int32 ret = -1;
    if(this->isOpened()){
        if(value){
#ifdef _WIN32

#endif
#ifdef _WIN64

#endif
#ifdef __linux__
            ret = ioctl(this->arq,__request,value);
#endif
#ifdef __APPLE__
            ret = ioctl(this->arq,__request,value);
#endif
        }
    }
    return ret;
}

edk::char8* edk::FileStream::getName(){
    return this->name.getName();
}

bool edk::FileStream::isOpened(){
    if(this->arq>=0){
        return true;
    }
    return false;
}
