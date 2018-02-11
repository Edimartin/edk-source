#include "File.h"

/*
Library File - Read and Write Files using C ANSI
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#ifdef printMessages
#warning "            Inside File.cpp"
#endif

namespace edk {

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
edk::char8* File::readStringFromTheFile(FILE* arq,edk::char8 limit,edk::uint32 count,bool use){
    //First read the next character
    edk::char8 temp = '\0';

    //string return
    edk::char8* ret = NULL;

    //test if have the end of the file
    if(feof(arq)){
        //then create the simple string
        edk::char8* str = new edk::char8[count+1u];
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
            str = new edk::char8[count+2u];
            if(str){
                //
                str[count+1u]='\0';
                str[count]=limit;
            }
        }
        else{
            //Copy just the end character
            str = new edk::char8[count+1u];
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
edk::char8* File::readStringFromTheFile(FILE* arq,edk::char8* limits,edk::uint32 count,bool use){

    //First read the next character
    edk::char8 temp = '\0';

    //string return
    edk::char8* ret = NULL;

    //test if have the end of the file
    if(feof(arq)){
        //then create the simple string
        edk::char8* str = new edk::char8[count+1u];
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
            str = new edk::char8[count+2u];
            if(str){
                //
                str[count+1u]='\0';
                str[count]=temp;
            }
        }
        else{
            //Copy just the end character
            str = new edk::char8[count+1u];
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
edk::char8* File::readStringFromTheBinFile(FILE* arq,edk::char8 limit,edk::uint32 count,bool use){
    //First read the next character
    edk::char8 temp = '\0';

    //string return
    edk::char8* ret = NULL;

    //test if have the end of the file
    if(feof(arq)){
        //then create the simple string
        edk::char8* str = new edk::char8[count+1u];
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
            str = new edk::char8[count+2u];
            if(str){
                //
                str[count+1u]='\0';
                str[count]=limit;
            }
        }
        else{
            //Copy just the end character
            str = new edk::char8[count+1u];
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
edk::char8* File::readStringFromTheBinFile(FILE* arq,edk::char8* limits,edk::uint32 count,bool use){

    //First read the next character
    edk::char8 temp = '\0';

    //string return
    edk::char8* ret = NULL;

    //test if have the end of the file
    if(feof(arq)){
        //then create the simple string
        edk::char8* str = new edk::char8[count+1u];
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
            str = new edk::char8[count+2u];
            if(str){
                //
                str[count+1u]='\0';
                str[count]=temp;
            }
        }
        else{
            //Copy just the end character
            str = new edk::char8[count+1u];
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






File::File(){
    //clean the atributes
    this->arq=NULL;
    this->name=NULL;
    this->size=0u;
}

File::~File(){
    //close the file
    this->closeFile();
}

uint64 File::getFileSize(){
    if(!this->size){
        //load fileSize
        edk::uint64 position = this->getSeek64();
        this->seekEnd();
        this->size = this->getSeek64();
        this->seekStart(position);
    }
    return this->size;
}

bool File::openTextFile(char8 *name){
    //Close the file
    this->closeFile();

    //Then open the file in your compiler
    if((const char*)name){

        #ifdef _WIN32
            //Windows 32
            #ifdef _MSC_VER
                //Visual C
                fopen_s(&arq,name,"r");
            #endif
            #ifdef __GNUC__
                #ifdef __cplusplus
                    //G++
                    arq=fopen((const char*)name,"r");
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
                    arq=fopen((const char*)name,"r");
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
                    arq=fopen((const char*)name,"r");
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
                    arq=fopen((const char*)name,"r");
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

bool File::openTextFile(const char *name){
    return this->openTextFile((edk::char8*)name);
}

bool File::openBinFile(char8 *name){
    //Close the file
    this->closeFile();

    //Then open the file in your compiler
    if((const char*)name){

        #ifdef _WIN32
            //Windows 32
            #ifdef _MSC_VER
                //Visual C
                fopen_s(&arq,name,"rb");
            #endif
            #ifdef __GNUC__
                #ifdef __cplusplus
                    //G++
                    arq=fopen((const char*)name,"rb");
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
                    arq=fopen((const char*)name,"rb");
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
                    arq=fopen((const char*)name,"rb");
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
                    arq=fopen((const char*)name,"rb");
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

bool File::openBinFile(const char *name){
    return this->openBinFile((edk::char8*)name);
}

bool File::openEndTextFile(char8 *name){
    //Close the file
    this->closeFile();

    //Then open the file in your compiler
    if((const char*)name){

        #ifdef _WIN32
            //Windows 32
            #ifdef _MSC_VER
                //Visual C
                fopen_s(&arq,name,"a");
            #endif
            #ifdef __GNUC__
                #ifdef __cplusplus
                    //G++
                    arq=fopen((const char*)name,"a");
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
                    arq=fopen((const char*)name,"a");
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
                    arq=fopen((const char*)name,"a");
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
                    arq=fopen((const char*)name,"a");
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

bool File::openEndTextFile(const char *name){
    return this->openEndTextFile((edk::char8 *)name);
}

bool File::openEndBinFile(char8 *name){
    //Close the file
    this->closeFile();

    //Then open the file in your compiler
    if((const char*)name){

        #ifdef _WIN32
            //Windows 32
            #ifdef _MSC_VER
                //Visual C
                fopen_s(&arq,name,"ab");
            #endif
            #ifdef __GNUC__
                #ifdef __cplusplus
                    //G++
                    arq=fopen((const char*)name,"ab");
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
                    arq=fopen((const char*)name,"ab");
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
                    arq=fopen((const char*)name,"ab");
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
                    arq=fopen((const char*)name,"ab");
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

bool File::openEndBinFile(const char *name){
    return this->openEndBinFile((edk::char8*)name);
}

//PIPE
bool File::openPipe(char8 *name){
    //Close the file
    this->closeFile();

    //Then open the file in your compiler
    if((const char*)name){

        #ifdef _WIN32
            //Windows 32
            #ifdef _MSC_VER
                //Visual C
                popen_s(&arq,name,"r");
            #endif
            #ifdef __GNUC__
                #ifdef __cplusplus
                    //G++
                    arq=popen((const char*)name,"r");
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
                    arq=popen((const char*)name,"r");
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
                    arq=popen((const char*)name,"r");
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
                    arq=popen((const char*)name,"r");
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
bool File::openPipe(const char *name){
    return this->openPipe((char8 *)name);
}

void File::closeFile(){
    //Test if the file is opened
    if(this->isOpened()){
        //Then close the file
        fclose(this->arq);
    }
    //clean the atributes
    this->arq=NULL;
    this->size=0u;

    //Delete the name if the name exist
    if(this->name){
        //
        delete[] this->name;
    }
    this->name=NULL;
}

bool File::deleteFile(char8 *name){
    //To delete the file we use the Remove
    if((const char*)name){
        //
        if( remove( (const char*)name ) != 0 ){
            //Remove the file
            return true;
        }
    }
    return false;
}

bool File::deleteFile(const char *name){
    return deleteFile((edk::char8 *)name);
}

bool File::deleteFile(){
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
            delete[] tempName;
        }
        tempName=NULL;
        //return the function deleteFile response
        return ret;
    }
    return false;
}

bool File::renameFile(char8 *oldName, char8 *newName){
    //Test if the names is valid
    if(oldName && newName){
        //Then try rename the file
        if ( rename( (const char*)oldName , (const char*)newName ) == 0 )
            //Return true because he rename the file
            return true;
    }
    //else return false
    return false;
}

bool File::renameFile(const char *oldName, const char *newName){
    return renameFile((edk::char8 *)oldName, (edk::char8 *)newName);
}

bool File::createFile(char8 *name){
   //Use a file
   FILE *tempArq=NULL;

   //test the name of the file
   if((const char*)name){
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
                    tempArq=fopen((const char*)name,"wb");
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
                    tempArq=fopen((const char*)name,"wb");
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
                    tempArq=fopen((const char*)name,"wb");
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
                    tempArq=fopen((const char*)name,"wb");
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

bool File::createFile(const char *name){
    return createFile((edk::char8 *)name);
}

bool File::createAndOpenTextFile(char8 *name){
    //First he create the file
    if(edk::File::createFile(name)){
        //Then open the file
        return this->openEndTextFile(name);
    }
    //Else return false;
    return false;
}

bool File::createAndOpenTextFile(const char *name){
    return createAndOpenTextFile((edk::char8 *)name);
}

bool File::createAndOpenBinFile(char8 *name){
    //First he create the file
    if(edk::File::createFile(name)){
        //Then open the file
        return this->openEndBinFile(name);
    }
    //Else return false;
    return false;
}

bool File::createAndOpenBinFile(const char *name){
    return createAndOpenBinFile((edk::char8 *)name);
}

//PIPE
bool File::createAndOpenPipe(char8* name){
    //Close the file
    this->closeFile();

    //Then open the file in your compiler
    if((const char*)name){

        #ifdef _WIN32
            //Windows 32
            #ifdef _MSC_VER
                //Visual C
                popen_s(&arq,name,"w");
            #endif
            #ifdef __GNUC__
                #ifdef __cplusplus
                    //G++
                    arq=popen((const char*)name,"w");
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
                    arq=popen((const char*)name,"w");
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
                    arq=popen((const char*)name,"w");
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
                    arq=popen((const char*)name,"w");
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
bool File::createAndOpenPipe(const char* name){
    return this->createAndOpenPipe((char8*) name);
}

bool File::fileExist(char8 *name){
    //create a tempFile
    FILE *tempArq=NULL;
    //Test the name
    if((const char*)name){
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
                    tempArq=fopen((const char*)name,"r");
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
                    tempArq=fopen((const char*)name,"r");
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
                    tempArq=fopen((const char*)name,"r");
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
                    tempArq=fopen((const char*)name,"r");
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

bool File::fileExist(const char *name){
    return fileExist((edk::char8 *)name);
}

bool File::readEnd(){
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
bool File::endOfFile(){
    return this->readEnd();
}

bool File::writeText(char8 c){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%c",c);
        //return true
        return true;
    }
    return false;
}

bool File::writeText(char8 *str){
    //Test if the file is opened and if the string is true
    if(this->isOpened() && str){
        //Then write in the file
        fprintf(this->arq,"%s",str);
        //return true
        return true;
    }
    return false;
}

bool File::writeText(const char *str){
    return writeText((edk::char8 *)str);
}

bool File::writeText(int32 n){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%d",n);
        //return true
        return true;
    }
    return false;
}

bool File::writeText(uint32 n){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%u",n);
        //return true
        return true;
    }
    return false;
}

bool File::writeText(edk::float32 f){
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%f",f);
        //return true
        return true;
    }
    return false;
}

bool File::writeBin(classID w, edk::uint32 size){
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

bool File::writeBin(char8 c){
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

bool File::writeBin(char8 *str){
    //test if the file is opened and if the str is true and the size is >1u
    if(this->isOpened() && str){
        //
        fwrite(str,sizeof(edk::char8),strlen((const char*)str),this->arq);
        fwrite(str,sizeof(edk::char8),edk::String::strSize(str),this->arq);
        //return true
        return true;
    }
    //else return false
    return false;
}

bool File::writeBin(const char *str){
    return writeBin((edk::char8 *)str);
}

bool File::writeBin(int32 n){
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

bool File::writeBin(int32 *n){
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

bool File::writeBin(uint32 n){
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

bool File::writeBin(uint32 *n){
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

bool File::writeBin(edk::float32 f){
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

bool File::writeBin(edk::float32* f){
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

bool File::writeBin(int64 n){
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

bool File::writeBin(int64 *n){
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

char8 File::readTextChar(){
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

char8* File::readTextString(edk::uint32 limit, bool use){
    return this->readTextString((char8) limit, use);
}
char8* File::readTextString(edk::uint64 limit, bool use){
    return this->readTextString((char8) limit, use);
}
char8* File::readTextString(edk::uint8 limit, bool use){
    return this->readTextString((char8) limit, use);
}

char8* File::readTextString(char8 limit, bool use){
    //test if the file os opened
    if(this->isOpened()){
        //read the string
        return this->readStringFromTheFile(this->arq,limit,0u,use);
    }
    //else return NULL
    return NULL;
}

char8* File::readTextString(char8 *limits, bool use){
    //test if the file os opened
    if(this->isOpened()&&limits){
        //read the string
        return this->readStringFromTheFile(this->arq,limits,0u,use);
    }
    //else return NULL
    return NULL;
}

char8* File::readTextString(const edk::char8 *limits, bool use){
    return this->readTextString((edk::char8 *)limits, use);
}

//read to a string
bool File::readTextString(char8 *str,edk::uint64 size){
    //test the string
    if(str && size){
        if(this->readBin(str,size)){
            return true;
        }
    }
    return false;
}

int32 File::readTextInt(){
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

uint32 File::readTextUInt(){
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

edk::float32 File::readTextFloat(){
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

classID File::readBin(uint64 size){
    //create the return
    void* ret=NULL;
    //test if the file is opened and the size is >1u
    if(this->isOpened() && size){
        //alloc the return
        ret=malloc(size);
        if(ret){
            //fread(ret,size,1u,this->arq);
            this->readBin(ret,size);
            return ret;
        }
    }
    return ret;
}

bool File::readBin(classID vec,uint64 size){
    if(size && vec){
        fread(vec,size,1u,this->arq);
        return true;
    }
    return false;
}

char8 File::readBinChar(){
    //read the size
    edk::char8* temp = (edk::char8*)this->readBin(sizeof(edk::char8));
    //create the edk::char8
    edk::char8 c = '\0';
    if(temp){
        //copy the edk::char8
        c = *temp;

        //delete temp
        delete[] temp;
    }
    temp=NULL;

    //return the edk::char8
    return c;
}

char8* File::readBinString(char64 size){
    //create the string
    edk::char8* temp = (edk::char8*)this->readBin(sizeof(edk::char8)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}

char8* File::readBinString(char8 limit, bool use){
    //test if the file os opened
    if(this->isOpened()){
        //read the string
        return this->readStringFromTheBinFile(this->arq,limit,0u,use);
    }
    //else return NULL
    return NULL;
}

char8* File::readBinString(char8 *limits, bool use){
    //test if the file os opened
    if(this->isOpened()){
        //read the string
        return this->readStringFromTheBinFile(this->arq,limits,0u,use);
    }
    //else return NULL
    return NULL;
}

char8* File::readBinString(const char *limits, bool use){
    return this->readBinString((char8 *)limits,use);
}

//read to a string
bool File::readBinString(char8 *str,edk::uint64 size){
    if(str && size){
        if(this->readBin(str,size)){
            return true;
        }
    }
    return false;
}

int32 File::readBinInt32(){
    //read the size
    edk::int32* temp = (edk::int32*)this->readBin(sizeof(edk::int32));
    //create the edk::char8
    edk::int32 n = 0u;
    if(temp){
        //copy the edk::char8
        n = *temp;

        //delete temp
        delete temp;
    }
    temp=NULL;

    //return the edk::char8
    return n;
}

int32* File::readBinInt32(int64 size){
    //create the string
    edk::int32* temp = (edk::int32*)this->readBin(sizeof(edk::int32)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}

uint32 File::readBinUInt32(){
    //read the size
    edk::uint32* temp = (edk::uint32*)this->readBin(sizeof(edk::uint32));
    //create the edk::char8
    edk::uint32 n = 0u;
    if(temp){
        //copy the edk::char8
        n = *temp;

        //delete temp
        delete temp;
    }
    temp=NULL;

    //return the edk::char8
    return n;
}

uint32* File::readBinUint32(uint64 size){
    //create the string
    edk::uint32* temp = (edk::uint32*)this->readBin(sizeof(edk::uint32)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}

edk::float32 File::readBinFloat(){
    //read the size
    edk::float32* temp = (edk::float32*)this->readBin(sizeof(edk::float32));
    //create the edk::char8
    edk::float32 n = 0u;
    if(temp){
        //copy the edk::char8
        n = *temp;

        //delete temp
        delete temp;
    }
    temp=NULL;

    //return the edk::char8
    return n;
}

edk::float32* File::readBinFloat(int64 size){
    //create the string
    edk::float32* temp = (edk::float32*)this->readBin(sizeof(edk::float32)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}

int64 File::readBinLongInt(){
    //read the size
    edk::int64* temp = (edk::int64*)this->readBin(sizeof(edk::int64));
    //create the edk::char8
    edk::int64 n = 0u;
    if(temp){
        //copy the edk::char8
        n = *temp;

        //delete temp
        delete temp;
    }
    temp=NULL;

    //return the edk::char8
    return n;
}

int64* File::readBinLongInt(int64 size){
    //create the string
    edk::int64* temp = (edk::int64*)this->readBin(sizeof(edk::int64)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}

char8* File::getName(){
    return this->name;
}

//SEEK the file
bool File::seek(edk::uint32 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseek(this->arq,bytes,SEEK_CUR);
        //return true
        return true;
    }
    return false;
}
bool File::seek(edk::uint64 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseeko64(this->arq,bytes,SEEK_CUR);
        //return true
        return true;
    }
    return false;
}
bool File::seek(edk::int32 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseek(this->arq,bytes,SEEK_CUR);
        //return true
        return true;
    }
    return false;
}
bool File::seek(edk::int64 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseeko64(this->arq,bytes,SEEK_CUR);
        //return true
        return true;
    }
    return false;
}
bool File::seekStart(){
    //test if the file is opened
    if(this->isOpened()){
        fseek(this->arq,0,SEEK_SET);
        //return true
        return true;
    }
    return false;
}
bool File::seekStart(edk::uint32 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseek(this->arq,bytes,SEEK_SET);
        //return true
        return true;
    }
    return false;
}
bool File::seekStart(edk::uint64 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseeko64(this->arq,bytes,SEEK_SET);
        //return true
        return true;
    }
    return false;
}
bool File::seekEnd(){
    //test if the file is opened
    if(this->isOpened()){
        fseek(this->arq,0,SEEK_END);
        //return true
        return true;
    }
    return false;
}
bool File::seekEnd(edk::int32 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseek(this->arq,bytes,SEEK_END);
        //return true
        return true;
    }
    return false;
}
bool File::seekEnd(edk::int64 bytes){
    //test if the file is opened
    if(this->isOpened()){
        fseeko64(this->arq,bytes,SEEK_END);
        //return true
        return true;
    }
    return false;
}
//return this current position
edk::uint32 File::getSeek32(){
    return ftell(this->arq);
}
edk::uint64 File::getSeek64(){
    return ftello64(this->arq);
}

//flush the file
bool File::flush(){
    if(this->isOpened()){
        fflush(this->arq);
        return true;
    }
    return false;
}

bool File::isOpened(){
    //Test if have the ponter of the file
    if(this->arq){
        //return true
        return true;
    }
    //else return false
    return false;
}

} /* End of namespace edk */
