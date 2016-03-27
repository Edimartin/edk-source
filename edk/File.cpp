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






File::File()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8BA begin
{
    //clean the atributes
    this->arq=NULL;
    this->name=NULL;
    this->size=0u;
}
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8BA end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

File::~File()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8C0 begin
{
    //close the file
    this->closeFile();
}
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8C0 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

uint64 File::getFileSize()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8C4 begin
{
    if(!this->size){
        //load fileSize
        edk::uint64 position = this->getSeek64();
        this->seekEnd();
        this->size = this->getSeek64();
        this->seekStart(position);
    }
    return this->size;
}
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8C4 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::openTextFile(char8 *name)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8C6 begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8C6 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::openTextFile(const char *name)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B39 begin
{
    return this->openTextFile((edk::char8*)name);
}
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B39 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::openBinFile(char8 *name)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8D0 begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8D0 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::openBinFile(const char *name)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B3D begin
{
    return this->openBinFile((edk::char8*)name);
}
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B3D end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::openEndTextFile(char8 *name)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8DA begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8DA end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::openEndTextFile(const char *name)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B40 begin
{
    return this->openEndTextFile((edk::char8 *)name);
}
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B40 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::openEndBinFile(char8 *name)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8E4 begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8E4 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::openEndBinFile(const char *name)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B43 begin
{
    return this->openEndBinFile((edk::char8*)name);
}
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B43 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

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

void File::closeFile()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8EE begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8EE end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::deleteFile(char8 *name)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8F0 begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8F0 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::deleteFile(const char *name)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B46 begin
{
    return deleteFile((edk::char8 *)name);
}
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B46 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::deleteFile()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8FA begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8FA end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::renameFile(char8 *oldName, char8 *newName)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8FC begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8FC end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::renameFile(const char *oldName, const char *newName)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B49 begin
{
    return renameFile((edk::char8 *)oldName, (edk::char8 *)newName);
}
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B49 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::createFile(char8 *name)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A90C begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A90C end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::createFile(const char *name)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B4D begin
{
    return createFile((edk::char8 *)name);
}
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B4D end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::createAndOpenTextFile(char8 *name)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A916 begin
{
    //First he create the file
    if(edk::File::createFile(name)){
        //Then open the file
        return this->openEndTextFile(name);
    }
    //Else return false;
    return false;
}
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A916 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::createAndOpenTextFile(const char *name)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B50 begin
{
    return createAndOpenTextFile((edk::char8 *)name);
}
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B50 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::createAndOpenBinFile(char8 *name)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A920 begin
{
    //First he create the file
    if(edk::File::createFile(name)){
        //Then open the file
        return this->openEndBinFile(name);
    }
    //Else return false;
    return false;
}
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A920 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::createAndOpenBinFile(const char *name)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B53 begin
{
    return createAndOpenBinFile((edk::char8 *)name);
}
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B53 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

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

bool File::fileExist(char8 *name)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A92A begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A92A end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::fileExist(const char *name)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B56 begin
{
    return fileExist((edk::char8 *)name);
}
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B56 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::readEnd()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A934 begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A934 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::writeText(char8 c)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A936 begin
{
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%c",c);
        //return true
        return true;
    }
    return false;
}
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A936 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::writeText(char8 *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A939 begin
{
    //Test if the file is opened and if the string is true
    if(this->isOpened() && str){
        //Then write in the file
        fprintf(this->arq,"%s",str);
        //return true
        return true;
    }
    return false;
}
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A939 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::writeText(const char *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B59 begin
{
    return writeText((edk::char8 *)str);
}
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000001B59 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::writeText(int32 n)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A943 begin
{
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%d",n);
        //return true
        return true;
    }
    return false;
}
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A943 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::writeText(uint32 n)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A943 begin
{
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%u",n);
        //return true
        return true;
    }
    return false;
}
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A943 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::writeText(edk::float32 f)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A946 begin
{
    //Test if the file is opened
    if(this->isOpened()){
        //Then write in the file
        fprintf(this->arq,"%f",f);
        //return true
        return true;
    }
    return false;
}
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A946 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::writeBin(classID w, edk::uint32 size)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A949 begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A949 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::writeBin(char8 c)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A94E begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A94E end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::writeBin(char8 *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A951 begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A951 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::writeBin(const char *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000003411 begin
{
    return writeBin((edk::char8 *)str);
}
// section 127-0-1-1-52b8ce26:13adc1c3b1d:-8000:0000000000003411 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::writeBin(int32 n)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A95B begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A95B end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::writeBin(int32 *n)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A95B begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A95B end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::writeBin(uint32 n)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A95B begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A95B end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::writeBin(uint32 *n)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A95B begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A95B end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::writeBin(edk::float32 f)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A96B begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A96B end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::writeBin(float* f)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A96B begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A96B end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::writeBin(int64 n)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A95B begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A95B end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::writeBin(int64 *n)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A95B begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A95B end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8 File::readTextChar()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A97B begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A97B end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* File::readTextString(edk::uint32 limit, bool use){
    return this->readTextString((char8) limit, use);
}
char8* File::readTextString(edk::uint64 limit, bool use){
    return this->readTextString((char8) limit, use);
}
char8* File::readTextString(edk::uint8 limit, bool use){
    return this->readTextString((char8) limit, use);
}

char8* File::readTextString(char8 limit, bool use)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001880 begin
{
    //test if the file os opened
    if(this->isOpened()){
        //read the string
        return this->readStringFromTheFile(this->arq,limit,0u,use);
    }
    //else return NULL
    return NULL;
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001880 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* File::readTextString(char8 *limits, bool use)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001882 begin
{
    //test if the file os opened
    if(this->isOpened()&&limits){
        //read the string
        return this->readStringFromTheFile(this->arq,limits,0u,use);
    }
    //else return NULL
    return NULL;
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001882 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* File::readTextString(const char *limits, bool use)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-7454915a:13ae553cc03:-8000:000000000000181A begin
{
    return this->readTextString((edk::char8 *)limits, use);
}
// section 127-0-1-1-7454915a:13ae553cc03:-8000:000000000000181A end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

int32 File::readTextInt()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A98B begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A98B end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

uint32 File::readTextUInt()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A98D begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A98D end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

edk::float32 File::readTextFloat()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A98F begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A98F end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

classID File::readBin(uint64 size)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001897 begin
{
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
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001897 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool File::readBin(classID vec,uint64 size){
    if(size && vec){
        fread(vec,size,1u,this->arq);
        return true;
    }
    return false;
}

char8 File::readBinChar()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A996 begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A996 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* File::readBinString(char64 size)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001888 begin
{
    //create the string
    edk::char8* temp = (edk::char8*)this->readBin(sizeof(edk::char8)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001888 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

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

int32 File::readBinInt32()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A99D begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A99D end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

int32* File::readBinInt32(int64 size)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001891 begin
{
    //create the string
    edk::int32* temp = (edk::int32*)this->readBin(sizeof(edk::int32)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001891 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

uint32 File::readBinUInt32()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A9A4 begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A9A4 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

uint32* File::readBinUint32(uint64 size)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000188B begin
{
    //create the string
    edk::uint32* temp = (edk::uint32*)this->readBin(sizeof(edk::uint32)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000188B end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

edk::float32 File::readBinFloat()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A9AB begin
{
    //read the size
    float* temp = (float*)this->readBin(sizeof(edk::float32));
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A9AB end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

float* File::readBinFloat(int64 size)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000188E begin
{
    //create the string
    float* temp = (float*)this->readBin(sizeof(edk::float32)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000188E end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

int64 File::readBinLongInt()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A9B2 begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A9B2 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

int64* File::readBinLongInt(int64 size)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001894 begin
{
    //create the string
    edk::int64* temp = (edk::int64*)this->readBin(sizeof(edk::int64)*size);
    if(temp){
        //return the string
        return temp;
    }
    //else return NULL
    return NULL;
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001894 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* File::getName()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A9B9 begin
{
    /*
    //test if have the file opened
    if(this->isOpened()){
        //then test if have the name
        if(this->name){
            //then return the name
            return this->name;
        }
    }
    //else return NULL
    return NULL;
    */
    return this->name;
}
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A9B9 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

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

bool File::isOpened()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A9BD begin
{
    //Test if have the ponter of the file
    if(this->arq){
        //return true
        return true;
    }
    //else return false
    return false;
}
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A9BD end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

} /* End of namespace edk */
