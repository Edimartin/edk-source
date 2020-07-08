#include "String.h"

/*
Library C++ String - Manipulate char vectors.
Copyright (C) 1013 Eduardo Moura Sales Martins
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
#warning "            Inside String.cpp"
#endif

#if defined (__linux__) || defined(__APPLE__)
int edkGetch(void)
{
    struct termios oldt, newt;
    int x;

    tcgetattr( STDIN_FILENO, &oldt );
    newt= oldt;
    newt.c_lflag &= ~ECHO;
    newt.c_lflag &= ~ICANON;
    newt.c_cc[VTIME]=0;
    newt.c_cc[VMIN]=1;
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    x= getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return x;
}

int edkKbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ECHO;
    newt.c_lflag &= ~ICANON;
    newt.c_cc[VTIME]=0;
    newt.c_cc[VMIN]=0;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}
#endif
#if defined(WIN32) || defined(WIN64)
#if defined(_MSC_VER)
int edkGetch(void){return _getch();}
int edkKbhit(void){return _kbhit();}
#else
int edkGetch(void){return getch();}
int edkKbhit(void){return kbhit();}
#endif
#endif

edk::int32 edkModuleInt32(edk::int32 value){
    //
    if(value<0){
        //
        return value*-1;
    }
    return value;
}
edk::int64 edkModuleInt64(edk::int64 value){
    //
    if(value<0){
        //
        return value*-1;
    }
    return value;
}
edk::float32 edkModuleFloat32(edk::float32 value){
    //
    if(value<0.0f){
        //
        return value*-1.0f;
    }
    return value;
}
edk::float64 edkModuleFloat64(edk::float64 value){
    //
    if(value<0.0L){
        //
        return value*-1.0L;
    }
    return value;
}
edk::char8* readFromTheConsole(edk::uint32 i){
    //Eu sei que os professores dizem NUNCA use isso mas se eu nao usasse eu
    //nao sei o que ei iria faser
inicio:
    //primeiro ele le a tecla do teclado e ve se e equal a enter 13
    edk::char8 c=edkGetch();
    //#endif
    //printf(" %u recebido",c);
    //Aqui ele pergunta se o edk::char8 e equal a o backspace
    if(c==8||c==127){
        if(i==0){
            //Se o i for equal a 0 ele nao pode retornar entao ele volta pro inicio do goto
            goto inicio;
        }
        //Se for equal entao ele apaga o caracter e le ele denovo;
        printf("%c %c",8,8);
        return NULL;
    }
    //depois ele gera o ponteiro para a string na memoria
    edk::char8* string;
    if(c==13||c==10){
        //Acabou a recursividade e portanto ele cria a string e retorna ela
        string = new edk::char8[i+1]; //Ele cria ela uma vez maior para adicionar o
        //caracter de parada
        string[i]='\0';
        //string[i]=c;
        return string;
    }
    else{
        //Senao ele countinua a recursividade recebendo a string como parametro
        printf("%c",c);
        string=readFromTheConsole(i+1);
        //Aqui ele pegunta se a string existe
        if(string){
            //se sim ele atribui o caracter desta etapa para a string
            string[i]=c;
            //no final ele retorna a string
            return string;
        }
        else{
            //Senao entao ele countinua lendo
            goto inicio;
        }
    }
}

namespace edk {



char8* String::int32ToMinusStr(int32 value){

    edk::char8* str = 0u;
    //use the module of the number
    edk::int32 module;

    //count the number
    edk::uint32 size = edk::String::sizeOfInt32(value);

    //test if the size is bigger then 0u
    if(size>0u){
        //then convert
        module = edkModuleInt32(value);
        //begin
        edk::uint32 begin=0u;
        //Negative
        size=size+1u;
        begin=1u;
        str = new edk::char8[size+1u];
        if(str){
            str[0u]='-';
            str[size]='\0';
        }
        else{
            //else set NULL
            str=0u;
        }
        //test if alloc the str
        if(str){
            //then convert the number
            for(edk::uint32 j=size;j>begin;j--){
                //
                edk::uint32 i=j-1u;
                //convert in this line
                str[i]=(module%10)+48;
                module=module/10;
            }
        }
    }
    else{
        //create a zero
        str = new edk::char8[3u];
        if(str){
            str[0u]='-';
            str[1u]='0';
            str[2u]='\0';
        }
        else{
            //else set NULL
            str=0u;
        }
    }
    return str;
}
char8* String::int64ToMinusStr(int64 value){

    edk::char8* str = 0u;
    //use the module of the number
    edk::int64 module;

    //count the number
    edk::uint32 size = edk::String::sizeOfInt64(value);

    //test if the size is bigger then 0u
    if(size>0u){
        //then convert
        module = edkModuleInt64(value);
        //begin
        edk::uint32 begin=0u;
        //Negative
        size=size+1u;
        begin=1u;
        str = new edk::char8[size+1u];
        if(str){
            str[0u]='-';
            str[size]='\0';
        }
        else{
            //else set NULL
            str=0u;
        }
        //test if alloc the str
        if(str){
            //then convert the number
            for(edk::uint32 j=size;j>begin;j--){
                //
                edk::uint32 i=j-1u;
                //convert in this line
                str[i]=(module%10)+48;
                module=module/10;
            }
        }
    }
    else{
        //create a zero
        str = new edk::char8[3u];
        if(str){
            str[0u]='-';
            str[1u]='0';
            str[2u]='\0';
        }
        else{
            //else set NULL
            str=0u;
        }
    }
    return str;
}

//copy the number to the string
bool String::copyInt32ToStr(edk::int32 value,edk::char8* str,int32 size){
    if(str && size){
        edk::int32 module = edkModuleInt32(value);
        for(edk::uint32 i=size;i>0u;i--){
            str[i-1u] = (module%10)+48;
            module=module/10;
        }
        return true;
    }
    return false;
}

bool String::copyInt64ToStr(edk::int64 value,edk::char8* str,int32 size){
    if(str && size){
        edk::int64 module = edkModuleInt64(value);
        for(edk::uint32 i=size;i>0u;i--){
            str[i-1u] = (module%10)+48;
            module=module/10;
        }
        return true;
    }
    return false;
}

edk::float32 String::strToFloat32(const char *str){
    return edk::String::strToFloat32((edk::char8*)str);
}

edk::float32 String::strToFloat32(char8 *str){
    if(str)
        return (edk::float32)atof((const edk::char8*)str);
    return 0.0f;
    /*
    //the return
    edk::float32 n = 0.0;
    //test if the string exist
    if(str){
        //then count the size of the string
        edk::uint32 size = edk::String::sizeOfCString(str);

        //variable to use point the characters
        edk::uint32 i=0u;

        //find the point
        edk::uint32 point=0u;
        bool havePoint=false;
        for(edk::uint32 j=size;j>0u;j--){
            //
            i=j-1u;
            if(str[i]=='.'){
                //then find the point
                point = i;
                havePoint = true;
                break;
            }
        }

        //First test if have a point
        if(havePoint){
            //Then convert the munvers after the point
            edk::float32 multiple = 0.1;
            for(edk::uint32 j=point+1u;j<size;j++){
                //test if the edk::char8 is a umber
                if(str[j]>='0'&&str[j]<='9'){
                    //then convert
                    n = n+ ((str[j]-48u)*multiple);
                }
                //then increment multiple
                multiple = multiple*0.1;
            }
        }
        else{
            //If don't have point. point receive the size
            point = size;
        }

        //then convert the numbers before the point



        //count the numbers
        edk::uint32 count=1u;
        //boolean to set minus number
        bool minus=false;

        //convert the string back
        for(edk::uint32 j=point;j>0u;j--){
            //point the string
            i=j-1u;
            //then use

            //test if the character is the first
            if(i==0u){
                //then test if is the '-'
                if(str[i]=='-'){
                    //then it's a minus number
                    minus=true;
                    //set continue
                    continue;
                }
            }

            //test if is a number
            if(str[i]>='0' && str[i]<='9'){
                //then is reading a number
                n = n + ((str[i]-48)  *  count);
            }

            //increment the count
            count=count*10u;
        }

        //test if is minus
        if(minus){
            //
            n=n*-1;
        }
    }
    return n;
    */
}

int64 String::strToInt64(char8 *str){
    if(str)
        return (edk::int64)atol((const edk::char8*)str);
    return 0;
}

int64 String::strToInt64(const char *str){
    return edk::String::strToInt64((edk::char8*)str);
}

edk::float64 String::strToFloat64(char8 *str){
    if(str)
        return strtod ((const edk::char8*)str,NULL);
    return 0.0;
}

edk::float64 String::strToFloat64(const char *str){
    return edk::String::strToFloat64((edk::char8*)str);
}

bool String::strToVecInt8(edk::char8* str,edk::int8* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = edk::String::strToInt32(str);
            i++;
            //test if get end
            if(i>=size){
                break;
            }
            else{
                //else continue with the string
                while(*str){
                    str++;
                    if(*str==' '){
                        str++;
                        break;
                    }
                }
            }
        }
        return true;
    }
    return false;
}

bool String::strToVecInt16(edk::char8* str,edk::int16* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = edk::String::strToInt32(str);
            i++;
            //test if get end
            if(i>=size){
                break;
            }
            else{
                //else continue with the string
                while(*str){
                    str++;
                    if(*str==' '){
                        str++;
                        break;
                    }
                }
            }
        }
        return true;
    }
    return false;
}

bool String::strToVecInt32(edk::char8* str,edk::int32* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = edk::String::strToInt64(str);
            i++;
            //test if get end
            if(i>=size){
                break;
            }
            else{
                //else continue with the string
                while(*str){
                    str++;
                    if(*str==' '){
                        str++;
                        break;
                    }
                }
            }
        }
        return true;
    }
    return false;
}

bool String::strToVecInt64(edk::char8* str,edk::int64* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = edk::String::strToInt64(str);
            i++;
            //test if get end
            if(i>=size){
                break;
            }
            else{
                //else continue with the string
                while(*str){
                    str++;
                    if(*str==' '){
                        str++;
                        break;
                    }
                }
            }
        }
        return true;
    }
    return false;
}

bool String::strToVecUint8(edk::char8* str,edk::uint8* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = (edk::uint8)edk::String::strToInt32(str);
            i++;
            //test if get end
            if(i>=size){
                break;
            }
            else{
                //else continue with the string
                while(*str){
                    str++;
                    if(*str==' '){
                        str++;
                        break;
                    }
                }
            }
        }
        return true;
    }
    return false;
}

bool String::strToVecUint16(edk::char8* str,edk::uint16* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = (edk::uint16)edk::String::strToInt32(str);
            i++;
            //test if get end
            if(i>=size){
                break;
            }
            else{
                //else continue with the string
                while(*str){
                    str++;
                    if(*str==' '){
                        str++;
                        break;
                    }
                }
            }
        }
        return true;
    }
    return false;
}

bool String::strToVecUint32(edk::char8* str,edk::uint32* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = edk::String::strToInt32(str);
            i++;
            //test if get end
            if(i>=size){
                break;
            }
            else{
                //else continue with the string
                while(*str){
                    str++;
                    if(*str==' '){
                        str++;
                        break;
                    }
                }
            }
        }
        return true;
    }
    return false;
}

bool String::strToVecUint64(edk::char8* str,edk::uint64* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = edk::String::strToInt64(str);
            i++;
            //test if get end
            if(i>=size){
                break;
            }
            else{
                //else continue with the string
                while(*str){
                    str++;
                    if(*str==' '){
                        str++;
                        break;
                    }
                }
            }
        }
        return true;
    }
    return false;
}

int32 String::strToInt32(char8 *str){
    if(str)
        return (edk::int32)atoi((const edk::char8*)str);
    return 0;
    /*
    //the final number to be returned
    edk::int32 n=0;

    //test if the string exist
    if(str){
        //then read the character

        //first count the string
        edk::uint32 size = edk::String::sizeOfCString(str);
        //variable to use point the characters
        edk::uint32 i=0u;
        //count the numbers
        edk::uint32 count=1u;
        //boolean to set minus number
        bool minus=false;

        //convert the string back
        for(edk::uint32 j=size;j>0u;j--){
            //point the string
            i=j-1u;
            //then use

            //test if the character is the first
            if(i==0u){
                //then test if is the '-'
                if(str[i]=='-'){
                    //then it's a minus number
                    minus=true;
                    //set continue
                    continue;
                }
            }

            //test if is a number
            if(str[i]>='0' && str[i]<='9'){
                //then is reading a number
                n = n + ((str[i]-48)  *  count);
            }

            //increment the count
            count=count*10u;
        }

        //test if is minus
        if(minus){
            //
            n=n*-1;
        }
    }
    return n;
*/
}

int32 String::strToInt32(const char *str){
    return edk::String::strToInt32((edk::char8*)str);
}

bool edk::String::str32ToUtf8(edk::char32 *str32,edk::char8* str){
    //
    return edk::String::str32ToUtf8(str32,edk::String::str32Size(str32),str);
}
//str32ToStr convert a vector with 32bit characters to a string UTF8 and return it as a new string
bool edk::String::str32ToUtf8(edk::char32 *str32,edk::uint32 size,edk::char8* str){
    if(str32 && size && str){
        //str[size]='\0';
        edk::char32 position = 0u;
        edk::char8* p = str;
        edk::char32 c = 0u;
        //copy the characters
        for(edk::uint32 i=0u;i<size;i++){
            //
            c = str32[position];
            //test if is a special character
            if(edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,1u)){
                if(edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,2u)){
                    if(edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,3u)){
                        //add the value
                        *p = (edk::uint8)edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,3u);
                        p++;
                    }
                    //add the value
                    *p = (edk::uint8)edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,2u);
                    p++;
                }
                //add the value
                *p = (edk::uint8)edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,1u);
                p++;
            }
            *p = (edk::uint8)edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,0u);
            p++;
            *p='\0';
            position++;
        }
        *p=(edk::uint8)'\0';
        return str;
    }
    return false;
}
bool edk::String::str32ToUtf8(const edk::char32 *str32,edk::char8* str){
    return edk::String::str32ToUtf8((edk::char32 *)str32,str);
}
bool edk::String::str32ToUtf8(const edk::char32 *str32,edk::uint32 size,edk::char8* str){
    return edk::String::str32ToUtf8((edk::char32 *)str32,size,str);
}
bool edk::String::str32ToUtf8(edk::char32 *str32,const edk::char8* str){
    return edk::String::str32ToUtf8(str32,(edk::char8*) str);
}
bool edk::String::str32ToUtf8(edk::char32 *str32,edk::uint32 size,const edk::char8* str){
    return edk::String::str32ToUtf8(str32,size,(edk::char8*) str);
}
bool edk::String::str32ToUtf8(const edk::char32 *str32,const edk::char8* str){
    return edk::String::str32ToUtf8((edk::char32 *)str32,(edk::char8*) str);
}
bool edk::String::str32ToUtf8(const edk::char32 *str32,edk::uint32 size,const edk::char8* str){
    return edk::String::str32ToUtf8((edk::char32 *)str32,size,(edk::char8*) str);
}
//str32ToStr convert a vector with 32bit characters to a string UTF8
edk::char8* edk::String::str32ToUtf8(edk::char32 *str32,edk::uint32 size){
    //get the string32 size
    edk::char32 size32 = edk::String::str32ToUtf8Size(str32,size);
    if(size32){
        edk::char8* str = NULL;
        str = new edk::char8[size32+1u];
        if(str){
            //copy the str
            if(edk::String::str32ToUtf8(str32,size,str)){
                //return the str
                return str;
            }
            delete[] str;
        }
    }
    return NULL;
}
edk::char8* edk::String::str32ToUtf8(const edk::char32 *str32,edk::uint32 size){
    return edk::String::str32ToUtf8((edk::char32 *)str32,size);
}
edk::char8* edk::String::str32ToUtf8(edk::char32 *str32){
    return edk::String::str32ToUtf8(str32,edk::String::str32Size(str32));
}
edk::char8* edk::String::str32ToUtf8(const edk::char32 *str32){
    return edk::String::str32ToUtf8((edk::char32 *)str32,edk::String::str32Size(str32));
}
//return the size of characters using 32 bits per character
edk::uint32 edk::String::str32Size(edk::char32 *str){
    //test the str
    edk::uint32 ret = 0u;
    if(str){
        while(*str){
            str++;
            ret++;
        }
    }
    return ret;
}
edk::uint32 edk::String::str32Size(const edk::char32 *str){
    return edk::String::str32Size((edk::char32*) str);
}
//return the size of a vector with 32bit charaters
edk::uint32 edk::String::str32ToUtf8Size(edk::char32 *str32,edk::uint32 size){
    //test the str and the size
    if(str32 && size){
        //test the bit to test if it's an 8 16 or 32 bits string
        edk::char32 ret = size;
        edk::char32 c=0u;
        for(edk::uint32 i = 0u;i<size;i++){
            //get the 32 bits character
            c = str32[i];
            if(edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,1u)){
                ret++;
                if(edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,2u)){
                    ret++;
                    if(edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,3u)){
                        ret++;
                    }
                }
            }
        }
        return ret;
    }
    return 0u;
}
edk::uint32 edk::String::str32ToUtf8Size(const edk::char32 *str32,edk::uint32 size){
    return edk::String::str32ToUtf8Size((edk::char32 *)str32,size);
}
//convert utf8 to ascii
bool edk::String::utf8ToStr(edk::char8 *utf8,edk::uint32 size,edk::char8 *str){
    if(utf8 && size && str){
        //convert the string
        for(edk::uint32 i=0u;i<size;i++){
            switch(utf8[i]){
            case (edk::char8)0xe2:
                i++;
                switch(utf8[i]){
                case (edk::char8)0x80:
                    i++;
                    switch(utf8[i]){
                    case (edk::char8)0x9a:
                        //82 00 e2 80 9a - 000 226 128 154
                        *str = (edk::char8)0x82;
                        break;
                    case (edk::char8)0x9e:
                        //84 00 e2 80 9e - 000 226 128 158
                        *str = (edk::char8)0x84;
                        break;
                    case (edk::char8)0xa6:
                        //85 00 e2 80 a6 - 000 226 128 166
                        *str = (edk::char8)0x85;
                        break;
                    case (edk::char8)0xa0:
                        //86 00 e2 80 a0 - 000 226 128 160
                        *str = (edk::char8)0x86;
                        break;
                    case (edk::char8)0xa1:
                        //87 00 e2 80 a1 - 000 226 128 161
                        *str = (edk::char8)0x87;
                        break;
                    case (edk::char8)0xb0:
                        //89 00 e2 80 b0 - 000 226 128 176
                        *str = (edk::char8)0x89;
                        break;
                    case (edk::char8)0xb9:
                        //8b 00 e2 80 b9 - 000 226 128 185
                        *str = (edk::char8)0x8b;
                        break;
                    case (edk::char8)0x98:
                        //91 00 e2 80 98 - 000 226 128 152
                        *str = (edk::char8)0x91;
                        break;
                    case (edk::char8)0x99:
                        //92 00 e2 80 99 - 000 226 128 153
                        *str = (edk::char8)0x92;
                        break;
                    case (edk::char8)0x9c:
                        //93 00 e2 80 9c - 000 226 128 156
                        *str = (edk::char8)0x9c;
                        break;
                    case (edk::char8)0x9d:
                        //94 00 e2 80 9d - 000 226 128 157
                        *str = (edk::char8)0x9d;
                        break;
                    case (edk::char8)0xa2:
                        //95 00 e2 80 a2 - 000 226 128 162
                        *str = (edk::char8)0xa2;
                        break;
                    case (edk::char8)0x93:
                        //96 00 e2 80 93 - 000 226 128 147
                        *str = (edk::char8)0x93;
                        break;
                    case (edk::char8)0x94:
                        //97 00 e2 80 94 - 000 226 128 148
                        *str = (edk::char8)0x94;
                        break;
                    case (edk::char8)0xba:
                        //9b 00 e2 80 ba - 000 226 128 186
                        *str = (edk::char8)0xba;
                        break;
                    default:
                        *str = '*';
                        break;
                    }
                    i++;
                    break;
                case (edk::char8)0x82:
                    //80 00 e2 82 ac - 000 226 130 172
                    i++;
                    if(utf8[i] == (edk::char8)0xac){
                        *str = 0x80;
                    }
                    else{
                        *str = '*';
                    }
                    i++;
                    break;
                case (edk::char8)0x84:
                    //99 00 e2 84 a2 - 000 226 132 162
                    i++;
                    if(utf8[i] == (edk::char8)0xa2){
                        *str = 0x99;
                    }
                    else{
                        *str = '*';
                    }
                    i++;
                    break;
                }
                break;
            case (edk::char8)0xc2:
                //a1 00 00 c2 a1 - 000 000 194 161
                //a2 00 00 c2 a2 - 000 000 194 162
                //a3 00 00 c2 a3 - 000 000 194 163
                //a4 00 00 c2 a4 - 000 000 194 164
                //a5 00 00 c2 a5 - 000 000 194 165
                //a6 00 00 c2 a6 - 000 000 194 166
                //a7 00 00 c2 a7 - 000 000 194 167
                //a8 00 00 c2 a8 - 000 000 194 168
                //a9 00 00 c2 a9 - 000 000 194 169
                //aa 00 00 c2 aa - 000 000 194 170
                //ab 00 00 c2 ab - 000 000 194 171
                //ac 00 00 c2 ac - 000 000 194 172
                //ae 00 00 c2 ae - 000 000 194 174
                //af 00 00 c2 af - 000 000 194 175
                //b0 00 00 c2 b0 - 000 000 194 176
                //b1 00 00 c2 b1 - 000 000 194 177
                //b2 00 00 c2 b2 - 000 000 194 178
                //b3 00 00 c2 b3 - 000 000 194 179
                //b4 00 00 c2 b4 - 000 000 194 180
                //b5 00 00 c2 b5 - 000 000 194 181
                //b6 00 00 c2 b6 - 000 000 194 182
                //b7 00 00 c2 b7 - 000 000 194 183
                //b8 00 00 c2 b8 - 000 000 194 184
                //b9 00 00 c2 b9 - 000 000 194 185
                //ba 00 00 c2 ba - 000 000 194 186
                //bb 00 00 c2 bb - 000 000 194 187
                //bc 00 00 c2 bc - 000 000 194 188
                //bd 00 00 c2 bd - 000 000 194 189
                //be 00 00 c2 be - 000 000 194 190
                //bf 00 00 c2 bf - 000 000 194 191
                i++;
                *str = utf8[i];
                break;
            case (edk::char8)0xc3:
                //c0 00 00 c3 80 - 000 000 195 128
                //c1 00 00 c3 81 - 000 000 195 129
                //c2 00 00 c3 82 - 000 000 195 130
                //c3 00 00 c3 83 - 000 000 195 131
                //c4 00 00 c3 84 - 000 000 195 132
                //c5 00 00 c3 85 - 000 000 195 133
                //c6 00 00 c3 86 - 000 000 195 134
                //c7 00 00 c3 87 - 000 000 195 135
                //c8 00 00 c3 88 - 000 000 195 136
                //c9 00 00 c3 89 - 000 000 195 137
                //ca 00 00 c3 8a - 000 000 195 138
                //cb 00 00 c3 8b - 000 000 195 139
                //cc 00 00 c3 8c - 000 000 195 140
                //cd 00 00 c3 8d - 000 000 195 141
                //ce 00 00 c3 8e - 000 000 195 142
                //cf 00 00 c3 8f - 000 000 195 143
                //d0 00 00 c3 90 - 000 000 195 144
                //d1 00 00 c3 91 - 000 000 195 145
                //d2 00 00 c3 92 - 000 000 195 146
                //d3 00 00 c3 93 - 000 000 195 147
                //d4 00 00 c3 94 - 000 000 195 148
                //d5 00 00 c3 95 - 000 000 195 149
                //d6 00 00 c3 96 - 000 000 195 150
                //d7 00 00 c3 97 - 000 000 195 151
                //d8 00 00 c3 98 - 000 000 195 152
                //d9 00 00 c3 99 - 000 000 195 153
                //da 00 00 c3 9a - 000 000 195 154
                //db 00 00 c3 9b - 000 000 195 155
                //dc 00 00 c3 9c - 000 000 195 156
                //dd 00 00 c3 9d - 000 000 195 157
                //de 00 00 c3 9e - 000 000 195 158
                //df 00 00 c3 9f - 000 000 195 159
                //e0 00 00 c3 a0 - 000 000 195 160
                //e1 00 00 c3 a1 - 000 000 195 161
                //e2 00 00 c3 a2 - 000 000 195 162
                //e3 00 00 c3 a3 - 000 000 195 163
                //e4 00 00 c3 a4 - 000 000 195 164
                //e5 00 00 c3 a5 - 000 000 195 165
                //e6 00 00 c3 a6 - 000 000 195 166
                //e7 00 00 c3 a7 - 000 000 195 167
                //e8 00 00 c3 a8 - 000 000 195 168
                //e9 00 00 c3 a9 - 000 000 195 169
                //ea 00 00 c3 aa - 000 000 195 170
                //eb 00 00 c3 ab - 000 000 195 171
                //ec 00 00 c3 ac - 000 000 195 172
                //ed 00 00 c3 ad - 000 000 195 173
                //ee 00 00 c3 ae - 000 000 195 174
                //ef 00 00 c3 af - 000 000 195 175
                //f0 00 00 c3 b0 - 000 000 195 176
                //f1 00 00 c3 b1 - 000 000 195 177
                //f2 00 00 c3 b2 - 000 000 195 178
                //f3 00 00 c3 b3 - 000 000 195 179
                //f4 00 00 c3 b4 - 000 000 195 180
                //f5 00 00 c3 b5 - 000 000 195 181
                //f6 00 00 c3 b6 - 000 000 195 182
                //f7 00 00 c3 b7 - 000 000 195 183
                //f8 00 00 c3 b8 - 000 000 195 184
                //f9 00 00 c3 b9 - 000 000 195 185
                //fa 00 00 c3 ba - 000 000 195 186
                //fb 00 00 c3 bb - 000 000 195 187
                //fc 00 00 c3 bc - 000 000 195 188
                //fd 00 00 c3 bd - 000 000 195 189
                //fe 00 00 c3 be - 000 000 195 190
                //ff 00 00 c3 bf - 000 000 195 191
                i++;
                *str = utf8[i] + 0x43;
                break;
            case (edk::char8)0xc5:
                i++;
                switch(utf8[i]){
                case (edk::char8)0xa0:
                    //8a 00 00 c5 a0 - 000 000 197 160
                    *str = 0x8a;
                    break;
                case (edk::char8)0x92:
                    //8c 00 00 c5 92 - 000 000 197 146
                    *str = 0x8c;
                    break;
                case (edk::char8)0xbd:
                    //8e 00 00 c5 bd - 000 000 197 189
                    *str = 0x8e;
                    break;
                case (edk::char8)0xa1:
                    //9a 00 00 c5 a1 - 000 000 197 161
                    *str = 0xa1;
                    break;
                case (edk::char8)0x93:
                    //9c 00 00 c5 93 - 000 000 197 147
                    *str = 0x93;
                    break;
                case (edk::char8)0xbe:
                    //9e 00 00 c5 be - 000 000 197 190
                    *str = 0xbe;
                    break;
                case (edk::char8)0xb8:
                    //9f 00 00 c5 b8 - 000 000 197 184
                    *str = 0xb8;
                    break;
                default:
                    *str = '*';
                    break;
                }
                i++;
                break;
            case (edk::char8)0xc6:
                i++;
                //83 00 00 c6 92 - 000 000 198 146
                if(utf8[i] == (edk::char8)0x92){
                    //
                    *str = (edk::char8)0x83;
                }
                i++;
                break;
            case (edk::char8)0xcb:
                i++;
                switch(utf8[i]){
                case (edk::char8)0x86:
                    //88 00 00 cb 86 - 000 000 203 134
                    *str = 0x88;
                    break;
                case (edk::char8)0x9c:
                    //98 00 00 cb 9c - 000 000 203 156
                    *str = 0x98;
                    break;
                default:
                    *str = '*';
                    break;
                }
                i++;
                break;
            default:
                *str = utf8[i];
                break;
            }
            str++;
        }
        *str = 0u;
        return true;
    }
    return false;
}
bool edk::String::utf8ToStr(const edk::char8 *utf8,edk::uint32 size,edk::char8 *str){
    return edk::String::utf8ToStr((edk::char8 *)utf8,size,str);
}
edk::char8* edk::String::utf8ToStr(edk::char8 *utf8,edk::uint32 size){
    edk::char8* ret = NULL;
    if(size){
        //get the utf8 size
        edk::uint32 sizeUtf = edk::String::utf8Size(utf8);
        if(sizeUtf){
            //create a string
            ret = new edk::char8[sizeUtf+1u];
            if(ret){
                if(!edk::String::utf8ToStr(utf8,size,ret)){
                    delete[] ret;
                    ret=NULL;
                }
            }
        }
    }
    return ret;
}
edk::char8* edk::String::utf8ToStr(const edk::char8 *utf8,edk::uint32 size){
    return edk::String::utf8ToStr((edk::char8 *)utf8,size);
}
edk::char8* edk::String::utf8ToStr(edk::char8 *utf8){
    return edk::String::utf8ToStr(utf8,edk::String::utf8Size(utf8));
}
edk::char8* edk::String::utf8ToStr(const edk::char8 *utf8){
    return edk::String::utf8ToStr((edk::char8 *)utf8);
}
//return the size of a utf8 string
edk::uint32 edk::String::utf8Size(edk::char8 *utf8){
    edk::uint32 ret=0u;
    if(utf8){
        //convert the string
        while(*utf8){
            switch(*utf8){
            case (edk::char8)0xe2:
                utf8++;
                if(*utf8){
                    switch(*utf8){
                    case (edk::char8)0x80:
                        utf8++;
                        if(*utf8){
                            ret++;
                        }
                        else return ret;
                        break;
                    case (edk::char8)0x82:
                        utf8++;
                        if(*utf8){
                            ret++;
                        }
                        else return ret;
                        break;
                    case (edk::char8)0x84:
                        utf8++;
                        if(*utf8){
                            ret++;
                        }
                        else return ret;
                        break;
                    }
                }
                else return ret;
                break;
            case (edk::char8)0xc2:
                if(*utf8){
                    ret++;
                }
                else return ret;
                break;
            case (edk::char8)0xc3:
                if(*utf8){
                    ret++;
                }
                else return ret;
                break;
            case (edk::char8)0xc5:
                if(*utf8){
                    ret++;
                }
                else return ret;
                break;
            case (edk::char8)0xc6:
                if(*utf8){
                    ret++;
                }
                else return ret;
                break;
            case (edk::char8)0xcb:
                if(*utf8){
                    ret++;
                }
                else return ret;
                break;
            default:
                ret++;
                break;
            }
            utf8++;
        }
    }
    return ret;
}
edk::uint32 edk::String::utf8Size(const edk::char8 *utf8){
    return edk::String::utf8Size((edk::char8 *)utf8);
}
edk::uint32 edk::String::utf8WordSize(edk::char8 *utf8){
    edk::uint32 ret=0u;
    if(utf8){
        //convert the string
        while(*utf8){
            //test the character
            if(*utf8==' ' || *utf8=='\n' || *utf8==10){
                break;
            }
            switch(*utf8){
            case (edk::char8)0xe2:
                utf8++;
                if(*utf8){
                    switch(*utf8){
                    case (edk::char8)0x80:
                        utf8++;
                        if(*utf8){
                            ret++;
                        }
                        else return ret;
                        break;
                    case (edk::char8)0x82:
                        utf8++;
                        if(*utf8){
                            ret++;
                        }
                        else return ret;
                        break;
                    case (edk::char8)0x84:
                        utf8++;
                        if(*utf8){
                            ret++;
                        }
                        else return ret;
                        break;
                    }
                }
                else return ret;
                break;
            case (edk::char8)0xc2:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else return ret;
                break;
            case (edk::char8)0xc3:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else return ret;
                break;
            case (edk::char8)0xc5:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else return ret;
                break;
            case (edk::char8)0xc6:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else return ret;
                break;
            case (edk::char8)0xcb:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else return ret;
                break;
            default:
                ret++;
                break;
            }
            utf8++;
        }
    }
    return ret;
}
edk::uint32 edk::String::utf8WordSize(const edk::char8 *utf8){
    return edk::String::utf8WordSize((edk::char8 *)utf8);
}
//get the size of utf8 bytes in a character
edk::uint8 edk::String::utf8Bytes(edk::char8 *utf8){
    edk::uint32 ret=0u;
    if(utf8){
        ret++;
        switch(*utf8){
        case (edk::char8)0xe2:
            utf8++;
            if(*utf8){
                switch(*utf8){
                case (edk::char8)0x80:
                    utf8++;
                    if(*utf8){
                        ret++;
                    }
                    else return ret;
                    break;
                case (edk::char8)0x82:
                    utf8++;
                    if(*utf8){
                        ret++;
                    }
                    else return ret;
                    break;
                case (edk::char8)0x84:
                    utf8++;
                    if(*utf8){
                        ret++;
                    }
                    else return ret;
                    break;
                }
            }
            else return ret;
            break;
        case (edk::char8)0xc2:
            utf8++;
            if(*utf8){
                ret++;
            }
            else return ret;
            break;
        case (edk::char8)0xc3:
            utf8++;
            if(*utf8){
                ret++;
            }
            else return ret;
            break;
        case (edk::char8)0xc5:
            utf8++;
            if(*utf8){
                ret++;
            }
            else return ret;
            break;
        case (edk::char8)0xc6:
            utf8++;
            if(*utf8){
                ret++;
            }
            else return ret;
            break;
        case (edk::char8)0xcb:
            utf8++;
            if(*utf8){
                ret++;
            }
            else return ret;
            break;
        }
    }
    return ret;
}
edk::uint8 edk::String::utf8Bytes(const edk::char8 *utf8){
    return edk::String::utf8Bytes((edk::char8 *)utf8);
}
//convert a utf8 character to uint32
edk::uint32 edk::String::utf8ToUint32(edk::char8 *utf8){
    edk::uint32 ret = 0u;
    edk::uint8 size = edk::String::utf8Bytes(utf8);
    switch(size){
    case 1u:
        ret = edk::BinaryConverter::joinBytesLittleEndian(0u,0u,0u,utf8[0u]);
        break;
    case 2u:
        ret = edk::BinaryConverter::joinBytesLittleEndian(0u,0u,utf8[0u],utf8[1u]);
        break;
    case 3u:
        ret = edk::BinaryConverter::joinBytesLittleEndian(0u,utf8[0u],utf8[1u],utf8[2u]);
        break;
    case 4u:
    default:
        if(size){
            ret = edk::BinaryConverter::joinBytesLittleEndian(utf8[0u],utf8[1u],utf8[2u],utf8[3u]);
        }
    }
    return ret;
}
edk::uint32 edk::String::utf8ToUint32(const edk::char8 *utf8){
    return edk::String::utf8ToUint32((edk::char8 *)utf8);
}

char8* String::int32ToStr(int32 value){
    edk::char8* str = 0u;

    //count the number
    edk::uint32 size = sizeOfInt32(value);

    //test if the size is bigger then 0u
    if(size>0u){
        //begin
        edk::uint32 begin=0u;
        if(value>=0){
            //Positive
            str = new edk::char8[size+1u];
            if(str){
                str[size]='\0';
            }
            else{
                //else set NULL
                str=0u;
            }
        }
        else{
            //Negative
            size=size+1u;
            begin=1u;
            str = new edk::char8[size+1u];
            if(str){
                str[0u]='-';
                str[size]='\0';
            }
            else{
                //else set NULL
                str=0u;
            }
        }
        //test if alloc the str
        if(str){
            edk::String::copyInt32ToStr(value,&str[begin],size-begin);
        }
    }
    else{
        //create a zero
        str = new edk::char8[2u];
        if(str){
            str[0u]='0';
            str[1u]='\0';
        }
        else{
            //else set NULL
            str=0u;
        }
    }
    return str;
}

char8* String::int64ToStr(int64 value){
    edk::char8* str = 0u;

    //count the number
    edk::uint32 size = edk::String::sizeOfInt64(value);

    //test if the size is bigger then 0u
    if(size>0u){
        //begin
        edk::uint32 begin=0u;
        if(value>=0){
            //Positive
            str = new edk::char8[size+1u];
            if(str){
                str[size]='\0';
            }
            else{
                //else set NULL
                str=0u;
            }
        }
        else{
            //Negative
            size=size+1u;
            begin=1u;
            str = new edk::char8[size+1u];
            if(str){
                str[0u]='-';
                str[size]='\0';
            }
            else{
                //else set NULL
                str=0u;
            }
        }
        //test if alloc the str
        if(str){
            edk::String::copyInt64ToStr(value,&str[begin],size-begin);
        }
    }
    else{
        //create a zero
        str = new edk::char8[2u];
        if(str){
            str[0u]='0';
            str[1u]='\0';
        }
        else{
            //else set NULL
            str=0u;
        }
    }
    return str;
}

char8* String::vecInt8toStr(edk::int8* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i])
                stringSize += 2u;
            else
                //plus the ' '
                stringSize += edk::String::sizeOfInt32(vec[i]) + 1u;
            //add the signal
            if(vec[i]<0)
                stringSize++;
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = new edk::char8[stringSize];
            if(str){
                edk::char8* temp = str;
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i])
                        sizeTemp = 1u;
                    else
                        sizeTemp = edk::String::sizeOfInt32(vec[i]);
                    //add the signal
                    if(vec[i]<0){
                        *temp = '-';
                        temp++;
                    }
                    //copy the number
                    edk::String::copyInt64ToStr(vec[i],temp,sizeTemp);
                    //copy the ' '
                    temp[sizeTemp] = ' ';
                    temp+=sizeTemp+1u;
                }
                str[stringSize-1u] = '\0';
                return str;
            }
        }
    }
    return NULL;
}

char8* String::vecInt16toStr(edk::int16* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i])
                stringSize += 2u;
            else
                //plus the ' '
                stringSize += edk::String::sizeOfInt32(vec[i]) + 1u;
            //add the signal
            if(vec[i]<0)
                stringSize++;
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = new edk::char8[stringSize];
            if(str){
                edk::char8* temp = str;
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i])
                        sizeTemp = 1u;
                    else
                        sizeTemp = edk::String::sizeOfInt32(vec[i]);
                    //add the signal
                    if(vec[i]<0){
                        *temp = '-';
                        temp++;
                    }
                    //copy the number
                    edk::String::copyInt64ToStr(vec[i],temp,sizeTemp);
                    //copy the ' '
                    temp[sizeTemp] = ' ';
                    temp+=sizeTemp+1u;
                }
                str[stringSize-1u] = '\0';
                return str;
            }
        }
    }
    return NULL;
}

char8* String::vecInt32toStr(edk::int32* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i])
                stringSize += 2u;
            else
                //plus the ' '
                stringSize += edk::String::sizeOfInt64(vec[i]) + 1u;
            //add the signal
            if(vec[i]<0)
                stringSize++;
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = new edk::char8[stringSize];
            if(str){
                edk::char8* temp = str;
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i])
                        sizeTemp = 1u;
                    else
                        sizeTemp = edk::String::sizeOfInt64(vec[i]);
                    //add the signal
                    if(vec[i]<0){
                        *temp = '-';
                        temp++;
                    }
                    //copy the number
                    edk::String::copyInt64ToStr(vec[i],temp,sizeTemp);
                    //copy the ' '
                    temp[sizeTemp] = ' ';
                    temp+=sizeTemp+1u;
                }
                str[stringSize-1u] = '\0';
                return str;
            }
        }
    }
    return NULL;
}
char8* String::vecInt64toStr(edk::int64* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i])
                stringSize += 2u;
            else
                //plus the ' '
                stringSize += edk::String::sizeOfInt64(vec[i]) + 1u;
            //add the signal
            if(vec[i]<0)
                stringSize++;
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = new edk::char8[stringSize];
            if(str){
                edk::char8* temp = str;
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i])
                        sizeTemp = 1u;
                    else
                        sizeTemp = edk::String::sizeOfInt64(vec[i]);
                    //add the signal
                    if(vec[i]<0){
                        *temp = '-';
                        temp++;
                    }
                    //copy the number
                    edk::String::copyInt64ToStr(vec[i],temp,sizeTemp);
                    //copy the ' '
                    temp[sizeTemp] = ' ';
                    temp+=sizeTemp+1u;
                }
                str[stringSize-1u] = '\0';
                return str;
            }
        }
    }
    return NULL;
}

char8* String::vecUint8toStr(edk::uint8* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i])
                stringSize += 2u;
            else
                //plus the ' '
                stringSize += edk::String::sizeOfInt32(vec[i]) + 1u;
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = new edk::char8[stringSize];
            if(str){
                edk::char8* temp = str;
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i])
                        sizeTemp = 1u;
                    else
                        sizeTemp = edk::String::sizeOfInt32(vec[i]);
                    //copy the number
                    edk::String::copyInt64ToStr(vec[i],temp,sizeTemp);
                    //copy the ' '
                    temp[sizeTemp] = ' ';
                    temp+=sizeTemp+1u;
                }
                str[stringSize-1u] = '\0';
                return str;
            }
        }
    }
    return NULL;
}

char8* String::vecUint16toStr(edk::uint16* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i])
                stringSize += 2u;
            else
                //plus the ' '
                stringSize += edk::String::sizeOfInt32(vec[i]) + 1u;
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = new edk::char8[stringSize];
            if(str){
                edk::char8* temp = str;
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i])
                        sizeTemp = 1u;
                    else
                        sizeTemp = edk::String::sizeOfInt32(vec[i]);
                    //copy the number
                    edk::String::copyInt64ToStr(vec[i],temp,sizeTemp);
                    //copy the ' '
                    temp[sizeTemp] = ' ';
                    temp+=sizeTemp+1u;
                }
                str[stringSize-1u] = '\0';
                return str;
            }
        }
    }
    return NULL;
}

char8* String::vecUint32toStr(edk::uint32* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i])
                stringSize += 2u;
            else
                //plus the ' '
                stringSize += edk::String::sizeOfInt64(vec[i]) + 1u;
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = new edk::char8[stringSize];
            if(str){
                edk::char8* temp = str;
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i])
                        sizeTemp = 1u;
                    else
                        sizeTemp = edk::String::sizeOfInt64(vec[i]);
                    //copy the number
                    edk::String::copyInt64ToStr(vec[i],temp,sizeTemp);
                    //copy the ' '
                    temp[sizeTemp] = ' ';
                    temp+=sizeTemp+1u;
                }
                str[stringSize-1u] = '\0';
                return str;
            }
        }
    }
    return NULL;
}
char8* String::vecUint64toStr(edk::uint64* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i])
                stringSize += 2u;
            else
                //plus the ' '
                stringSize += edk::String::sizeOfInt64(vec[i]) + 1u;
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = new edk::char8[stringSize];
            if(str){
                edk::char8* temp = str;
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i])
                        sizeTemp = 1u;
                    else
                        sizeTemp = edk::String::sizeOfInt64(vec[i]);
                    //copy the number
                    edk::String::copyInt64ToStr(vec[i],temp,sizeTemp);
                    //copy the ' '
                    temp[sizeTemp] = ' ';
                    temp+=sizeTemp+1u;
                }
                str[stringSize-1u] = '\0';
                return str;
            }
        }
    }
    return NULL;
}

edk::uint32 String::sizeOfInt32(int32 value){
    //use the module of the number
    edk::int32 module = edkModuleInt32(value);

    //count the number
    edk::uint32 size = 0;
    while(true){
        //
        if(module<=0){
            //
            break;
        }
        module=module/10;
        size++;
    }
    return size;
}

edk::uint32 String::sizeOfInt64(int64 value){
    //use the module of the number
    edk::int64 module = edkModuleInt64(value);

    //count the number
    edk::uint32 size = 0;
    while(true){
        //
        if(module<=0){
            //
            break;
        }
        module=module/10;
        size++;
    }
    return size;
}

char8* String::float32ToStr(edk::float32 value){
    //first divide the value in two. After the point and before the poinf
    edk::int32 before = (edk::int32)value;
    edk::float32 after= edkModuleFloat32(value-(edk::float32)before);
    //string to return
    edk::char8* ret = NULL;
    //transform the before into a string
    edk::char8* afterStr = NULL;
    if(value<0.f)
        afterStr = edk::String::int64ToMinusStr(before);
    else
        afterStr = edk::String::int64ToStr(before);
    //now create the string of the after
    edk::char8* beforeStr = NULL;
    if(after>0.0){
        //then create the string

        //first count the numbers after the point
        edk::uint32 size=0u;
        while(true){
            //test if number is zero
            if((after - ((edk::int32)after))==0.0f){
                //break
                break;
            }
            after=after*10.0f;
            size++;
        }
        //create the string
        beforeStr = new edk::char8[size+2u];
        //test if alloc the new srring
        after= edkModuleFloat32(value-(edk::float32)before);
        if(beforeStr){
            //put a start in the string
            beforeStr[0u]='.';
            //puth a end in the string
            beforeStr[size+1u]='\0';
            //copy the numbers
            for(edk::uint32 i=1u;i<=size;i++){
                //get the character
                after=after*10.0f;
                edk::uint32 character = (edk::int32)after;
                //remove the character from the number
                after=after-character;
                //copy the character to the strig
                beforeStr[i]=character+48;
            }
        }
    }
    else{
        //create one string .0;
        beforeStr=edk::String::strCopy(".0");
    }
    //then concatenate the two strings
    if(beforeStr){
        if(afterStr){
            //concatenate
            ret=edk::String::strCat(afterStr,beforeStr);
            //delete the afterString
            delete[] afterStr;
            afterStr=NULL;
        }
        //delete the before
        delete[] beforeStr;
    }
    beforeStr=NULL;

    //return the ret
    return ret;
}

char8* String::float32ToStr(edk::float32 value, int32 digits){
    //first divide the value in two. After the point and before the poinf
    edk::int32 before = (edk::int32)value;
    edk::float32 after= edkModuleFloat32(value-(edk::float32)before);
    //string to return
    edk::char8* ret = NULL;
    //transform the before into a string
    edk::char8* afterStr = NULL;
    if(value<0.f)
        afterStr = edk::String::int64ToMinusStr(before);
    else
        afterStr = edk::String::int64ToStr(before);
    //now create the string of the after
    edk::char8* beforeStr = NULL;
    if(after>0.0){
        //then create the string

        //forst count the numbers after the point
        edk::uint32 size=digits;
        //create the string
        beforeStr = new edk::char8[size+2u];
        //test if alloc the new srring
        after= edkModuleFloat32(value-(edk::float32)before);
        if(beforeStr){
            //put a start in the string
            beforeStr[0u]='.';
            //puth a end in the string
            beforeStr[size+1u]='\0';
            //copy the numbers
            for(edk::uint32 i=1u;i<=size;i++){
                //get the character
                after=after*10.0f;
                edk::uint32 character = (edk::int32)after;
                //remove the character from the number
                after=after-character;
                //copy the character to the strig
                beforeStr[i]=character+48;
            }
        }
    }
    else{
        //create one string .0;
        beforeStr=edk::String::strCopy((const edk::char8*)".0");
    }
    //then concatenate the two strings
    if(beforeStr){
        if(afterStr){
            //concatenate
            ret=edk::String::strCat(afterStr,beforeStr);
            //delete the afterString
            delete[] afterStr;
            afterStr=NULL;
        }
        //delete the before
        delete[] beforeStr;
    }
    beforeStr=NULL;

    //return the ret
    return ret;
}

char8* String::float64ToStr(edk::float64 value, int32 digits){
    //first divide the value in two. After the point and before the poinf
    edk::int32 before = (edk::int32)value;
    edk::float64 after= edkModuleFloat64(value-(edk::float64)before);
    //string to return
    edk::char8* ret = NULL;
    //transform the before into a string
    edk::char8* afterStr = edk::String::int32ToStr(before);
    //now create the string of the after
    edk::char8* beforeStr = NULL;
    if(after>0.0L){
        //then create the string

        //forst count the numbers after the point
        edk::uint32 size=digits;
        //create the string
        beforeStr = new edk::char8[size+2u];
        //test if alloc the new srring
        after= edkModuleFloat64(value-(edk::float32)before);
        if(beforeStr){
            //put a start in the string
            beforeStr[0u]='.';
            //puth a end in the string
            beforeStr[size+1u]='\0';
            //copy the numbers
            for(edk::uint32 i=1u;i<=size;i++){
                //get the character
                after=after*10.0f;
                edk::uint32 character = (edk::int32)after;
                //remove the character from the number
                after=after-character;
                //copy the character to the strig
                beforeStr[i]=character+48;
            }
        }
    }
    else{
        //create one string .0;
        beforeStr=edk::String::strCopy((const edk::char8*)".0");
    }
    //then concatenate the two strings
    if(beforeStr){
        if(afterStr){
            //concatenate
            ret=edk::String::strCat(afterStr,beforeStr);
            //delete the afterString
            delete[] afterStr;
            afterStr=NULL;
        }
        //delete the before
        delete[] beforeStr;
    }
    beforeStr=NULL;

    //return the ret
    return ret;
}

char8* String::uint32ToStr(uint32 value){
    edk::char8* str = NULL;
    //use the module of the number
    edk::uint32 module = value;

    //count the number
    edk::uint32 size = 0;


    while(true){
        //
        if(module<=0){
            //
            break;
        }
        module=module/10;
        size++;
    }

    //test if the size is bigger then 0u
    if(size>0u){
        //then convert
        module = value;
        //begin
        edk::uint32 begin=0u;
        //Positive
        str = new edk::char8[size+1u];
        if(str){
            str[size]='\0';
        }
        else{
            //else set NULL
            str=0u;
        }
        //test if alloc the str
        if(str){
            //then convert the number
            for(edk::uint32 j=size;j>begin;j--){
                //
                edk::uint32 i=j-1u;
                //convert in this line
                str[i]=(module%10)+48;
                module=module/10;
            }
        }
    }
    else{
        //create a zero
        str = new edk::char8[2u];
        if(str){
            str[0u]='0';
            str[1u]='\0';
        }
        else{
            //else set NULL
            str=0u;
        }
    }
    return str;
}

char8* String::uint64ToStr(uint64 value){
    edk::char8* str = NULL;
    //use the module of the number
    edk::uint64 module = value;

    //count the number
    edk::uint64 size = 0;


    while(true){
        //
        if(module<=0){
            //
            break;
        }
        module=module/10;
        size++;
    }

    //test if the size is bigger then 0u
    if(size>0u){
        //then convert
        module = value;
        //begin
        edk::uint64 begin=0u;
        //Positive
        str = new edk::char8[size+1u];
        if(str){
            str[size]='\0';
        }
        else{
            //else set NULL
            str=0u;
        }
        //test if alloc the str
        if(str){
            //then convert the number
            for(edk::uint64 j=size;j>begin;j--){
                //
                edk::uint64 i=j-1u;
                //convert in this line
                str[i]=(module%10)+48;
                module=module/10;
            }
        }
    }
    else{
        //create a zero
        str = new edk::char8[2u];
        if(str){
            str[0u]='0';
            str[1u]='\0';
        }
        else{
            //else set NULL
            str=0u;
        }
    }
    return str;
}

char8* String::strCat(char8 *str1, char8 *str2){
    //first declare a return
    edk::char8* ret=NULL;
    //test if string are alloc
    if(str1&&str2){
        //get the size of the 2 strings
        edk::uint32 size1 = edk::String::strSize(str1),size2 = edk::String::strSize(str2);
        //alloc the new string
        ret = new edk::char8[size1+size2+1u];
        //set end of the string '\0'
        ret[size1+size2]='\0';
        //copy the first string
        memcpy(ret,str1,size1);
        /*
        for(edk::uint32 i=0u;i<size1;i++){
            //
            ret[i]=str1[i];
        }
        */
        //copy the second string
        memcpy(&ret[size1],str2,size2);
        /*
        for(edk::uint32 i=size1;i<size1+size2;i++){
            //
            ret[i]=str2[i-size1];
        }
        */
    }
    //return the return string
    return ret;
}

char8* String::strCat(char8 *str1, const char *str2){
    return edk::String::strCat(str1, (char8*) str2);
}

char8* String::strCat(const char *str1, char8 *str2){
    return edk::String::strCat((char8*) str1,str2);
}

char8* String::strCat(const char *str1, const char *str2){
    return edk::String::strCat((edk::char8*)str1,(edk::char8*)str2);
}

char8* String::strCatMulti(char8 *str, ...){
    //first make a copy of the pointer transforming to a matrix
    edk::char8* strTemp=str;
    //Alloc the return
    edk::char8* ret=NULL;
    //temporary string. Will be deleted in the end of the while
    edk::char8* temp=NULL;

    va_list vl;
    va_start(vl,str);

    if(strTemp){
        //clone the str
        if((ret = edk::String::strCopy(strTemp))){
            //get the next string
            strTemp = va_arg(vl,char8*);
            while(strTemp){
                //save the ret
                temp = ret;
                //cat the temp with the new
                if((ret = edk::String::strCat(temp,strTemp))){
                    //delete temp
                    delete temp;
                }
                else{
                    //else return temp
                    ret = temp;
                    break;
                }
                strTemp = va_arg(vl,char8*);
            }
        }
    }

    //in the end return the return string
    return ret;
}

char8* String::strCatMulti(const char *str, ...){
    //first make a copy of the pointer transforming to a matrix
    edk::char8* strTemp=(edk::char8*)str;
    //Alloc the return
    edk::char8* ret=NULL;
    //temporary string. Will be deleted in the end of the while
    edk::char8* temp=NULL;

    va_list vl;
    va_start(vl,str);

    if(strTemp){
        //clone the str
        if((ret = edk::String::strCopy(strTemp))){
            //get the next string
            strTemp = va_arg(vl,char8*);
            while(strTemp){
                //save the ret
                temp = ret;
                //cat the temp with the new
                if((ret = edk::String::strCat(temp,strTemp))){
                    //delete temp
                    delete temp;
                }
                else{
                    //else return temp
                    ret = temp;
                    break;
                }
                strTemp = va_arg(vl,char8*);
            }
        }
    }

    //in the end return the return string
    return ret;
}

bool String::strCompare(char8 *str1, char8 *str2){
    //alloc the return
    if(str1 && str2){
        //then he can compare the two strings
        if (*str1 == *str2){
            while (*str1 || *str2){
                str1++;
                str2++;
                if (*str1!=*str2){
                    break;
                }
                else if(*str1=='\0'){
                    //
                    return true;
                }
            }
        }
    }
    return false;
}
bool String::strCompare(const char *str1, char8 *str2){
    return edk::String::strCompare((char8 *)str1, (char8 *)str2);
}
bool String::strCompare(char8 *str1, const char *str2){
    return edk::String::strCompare((char8 *)str1, (char8 *)str2);
}


bool String::strCompare(const char *str1, const char *str2){
    return edk::String::strCompare((edk::char8*)str1,(edk::char8*)str2);
}

//Compare string removing some characters with filter
bool String::strCompareWithFilter(char8 *str1, char8 *str2,char8 *filter){
    //test filter
    if(filter){
        //get size of the filter
        edk::uint32 size = edk::String::strSize(filter);
        if(size){
            //test the strings
            if(str1 && str2){
                bool isEqual=false;
                //test str1 and str2
                if(*str1 && *str2){
                    //test if have the filter
                    while(*str1){
                        isEqual = false;
                        for(edk::uint32 i=0u;i<size;i++){
                            if(*str1 == filter[i]){
                                isEqual = true;
                                break;
                            }
                        }
                        if(isEqual) str1++;
                        else break;
                    }
                    while(*str2){
                        isEqual = false;
                        for(edk::uint32 i=0u;i<size;i++){
                            if(*str2 == filter[i]){
                                isEqual = true;
                                break;
                            }
                        }
                        if(isEqual) str2++;
                        else break;
                    }
                    //test the second time
                    if(*str1 && *str2){
                        //then go to the loop
                        do{
                            str1++;
                            str2++;

                            //test if have filter
                            while(*str1){
                                isEqual = false;
                                for(edk::uint32 i=0u;i<size;i++){
                                    if(*str1 == filter[i]){
                                        isEqual = true;
                                        break;
                                    }
                                }
                                if(isEqual) str1++;
                                else break;
                            }
                            while(*str2){
                                isEqual = false;
                                for(edk::uint32 i=0u;i<size;i++){
                                    if(*str2 == filter[i]){
                                        isEqual = true;
                                        break;
                                    }
                                }
                                if(isEqual) str2++;
                                else break;
                            }
                            //test if is not equal
                            if(*str1!=*str2){
                                //
                                return false;
                            }
                        }while(*str1 && *str2);
                    }
                    if(*str1 == *str2) return true;
                }
            }
            return false;
        }
    }
    //else test normalCompare
    return edk::String::strCompare(str1,str2);
}
bool String::strCompareWithFilter(char8 *str1, char8 *str2,const char *filter){
    return edk::String::strCompareWithFilter(str1, str2,(char8 *)filter);
}
bool String::strCompareWithFilter(const char *str1, const char *str2,const char *filter){
    return edk::String::strCompareWithFilter((char8 *)str1, (char8 *)str2,(char8 *)filter);
}
bool String::strCompareWithFilter(const char *str1, const char *str2,char8 *filter){
    return edk::String::strCompareWithFilter((char8 *)str1, (char8 *)str2,filter);
}
bool String::strCompareWithFilter(char8 *str1, const char *str2,const char *filter){
    return edk::String::strCompareWithFilter(str1, (char8 *)str2,(char8 *)filter);
}
bool String::strCompareWithFilter(char8 *str1, const char *str2,char8 *filter){
    return edk::String::strCompareWithFilter(str1, (char8 *)str2,filter);
}
bool String::strCompareWithFilter(const char *str1, char8 *str2,const char *filter){
    return edk::String::strCompareWithFilter((char8 *)str1, str2,(char8 *)filter);
}
bool String::strCompareWithFilter(const char *str1, char8 *str2,char8 *filter){
    return edk::String::strCompareWithFilter((char8 *)str1, str2,filter);
}

//return true if a string is inside the other string
edk::char8* edk::String::strInside(char8 *str, char8 *compare){
    edk::char8* temp = NULL;
    edk::char8* ret = NULL;
    if(str && compare){
        while(*str){
            //test if are equal
            if(*str == *compare){
                temp = compare;
                ret = str;
                //test the other characters
                while(*str && *temp){
                    //increment
                    str++;
                    temp++;
                    if(*str != *temp){
                        break;
                    }
                }
                //test if reach the end
                if(!*temp){
                    //reach the end
                    return ret;
                }
                if(!*str){
                    //then return NULL;
                    return NULL;
                }
            }

            //increment
            str++;
        }
    }
    return NULL;
}
edk::char8* edk::String::strInside(const char8 *str, char8 *compare){
    return edk::String::strInside((char8 *)str, compare);
}
edk::char8* edk::String::strInside(char8 *str, const char8 *compare){
    return edk::String::strInside(str, (char8 *)compare);
}
edk::char8* edk::String::strInside(const char8 *str, const char8 *compare){
    return edk::String::strInside((char8 *)str, (char8 *)compare);
}

//return true if the first string is bigger than the second string
bool edk::String::strBiggerStr(char8 *str1, char8 *str2){
    //test the strings
    if(str1 && str2){
        //test if str1 is bigger
        while(*str1!='\0' || *str2!='\0'){
            //test if the first is bigger then second
            if(*str1>*str2){
                //the return true
                return true;
            }
            else if(*str2>*str1){
                //
                break;
            }
            //else equal increment i
            str2++;
            str1++;
        }
    }
    //else return false
    return false;
}
bool edk::String::strBiggerStr(const char8 *str1, char8 *str2){
    return edk::String::strBiggerStr((char8 *)str1, str2);
}
bool edk::String::strBiggerStr(char8 *str1, const char8 *str2){
    return edk::String::strBiggerStr(str1, (char8 *)str2);
}
bool edk::String::strBiggerStr(const char8 *str1, const char8 *str2){
    return edk::String::strBiggerStr((char8 *)str1, (char8 *)str2);
}

uint64 String::strSize(char8 *str){
    edk::uint64 ret=0u;
    if(str){
        while(*str){
            //increment i to continue the counting
            ret++;
            str++;
        }
    }
    return ret;
}

uint64 String::strSize(const char *str){
    return edk::String::strSize((edk::char8*)str);
}

uint64 String::strSizeWithFilter(char8 *str,edk::char8* filter){
    edk::uint64 i=0u;

    if(filter){
        //get the filterSize
        edk::uint64 size = edk::String::strSize(filter);
        if(size){
            if(str){
                bool haveFilter;
                while(true){
                    //test the filter
                    haveFilter = (bool)edk::String::stringHaveChar(filter,size,*str);
                    if(*str=='\0'){
                        //then find the end of the string
                        break;
                    }
                    if(!haveFilter)
                        //increment i to continue the counting
                        i++;
                    str++;
                }
            }
        }
        else return edk::String::strSize(str);
    }
    else return edk::String::strSize(str);
    return i;
}
uint64 String::strSizeWithFilter(char8 *str,const char *filter){
    return strSizeWithFilter(str,(edk::char8*) filter);
}
uint64 String::strSizeWithFilter(const char *str,edk::char8* filter){
    return strSizeWithFilter((char8 *)str,filter);
}
uint64 String::strSizeWithFilter(const char *str,const char *filter){
    return strSizeWithFilter((char8 *)str,(edk::char8*) filter);
}

uint64 String::strWordSize(char8 *str){
    edk::uint64 ret=0u;
    if(str){
        while(*str){
            //increment i to continue the counting
            ret++;
            str++;
        }
    }
    return ret;
}

uint64 String::strWordSize(const char *str){
    return edk::String::strWordSize((edk::char8*)str);
}

uint64 String::strWordSizeWithFilter(char8 *str,edk::char8* filter){
    edk::uint64 i=0u;

    if(filter){
        //get the filterSize
        edk::uint64 size = edk::String::strWordSize(filter);
        if(size){
            if(str){
                bool haveFilter;
                while(true){
                    //test the filter
                    haveFilter = (bool)edk::String::stringHaveChar(filter,size,*str);
                    if(*str=='\0' || *str==' ' || *str == 10u){
                        //then find the end of the string
                        break;
                    }
                    if(!haveFilter)
                        //increment i to continue the counting
                        i++;
                    str++;
                }
            }
        }
        else return edk::String::strWordSize(str);
    }
    else return edk::String::strWordSize(str);
    return i;
}
uint64 String::strWordSizeWithFilter(char8 *str,const char *filter){
    return strWordSizeWithFilter(str,(edk::char8*) filter);
}
uint64 String::strWordSizeWithFilter(const char *str,edk::char8* filter){
    return strWordSizeWithFilter((char8 *)str,filter);
}
uint64 String::strWordSizeWithFilter(const char *str,const char *filter){
    return strWordSizeWithFilter((char8 *)str,(edk::char8*) filter);
}

bool edk::String::strCut(char8 *str,char8 *dest, char8 limit, bool use){
    if(str && dest && limit){
        while(*str){
            //test if the str is equal the limit
            if(*str == limit){
                //test if use
                if(use){
                    //
                    *dest = limit;
                    dest++;
                }
                //
                *dest='\0';
                break;
            }
            //copy the character
            *dest = *str;
            //increment the str and the dest
            str++;
            dest++;
        }
        return true;
    }
    return false;
}

bool edk::String::strCut(const char8 *str,char8 *dest, char8 limit, bool use){
    return edk::String::strCut((char8 *)str,dest, limit, use);
}

char8* edk::String::strCut(char8 *str, char8 limit, bool use){
    //Test if the string is alloc
    if(str){
        //The new stirng
        edk::char8* ret=NULL;
        //Start the loop
        edk::uint32 size=0u;
        while(str[size]!='\0'){
            //

            //Test if find the character
            if(str[size]==limit){
                //then create a new string

                //Test if use the limit
                if(use){
                    //
                    ret = new edk::char8[size+2u];
                    //incremente the size
                    size++;
                }
                else{
                    //
                    ret = new edk::char8[size+1u];
                }
                //Set the end of the stirng
                ret[size]='\0';

                //Copy the string
                for(edk::uint32 i=0u;i<size;i++){
                    //
                    ret[i]=str[i];
                }

                //return thr string
                return ret;
            }
            //increment the count
            size++;
        }
    }
    //If he cant fint the character. Return NULL
    return NULL;
}

char8* edk::String::strCut(const char *str, char8 limit, bool use){
    return edk::String::strCut((edk::char8 *)str, limit, use);
}

bool edk::String::strCut(char8 limit, char8 *str, char8 *dest, bool use){
    if(str && dest && limit){
        while(*str){
            //test if the str is equal the limit
            if(*str == limit){
                //test if use
                if(use){
                    //
                    *dest = limit;
                    dest++;
                    str++;
                }
                while(*str){
                    //copy the character
                    *dest = *str;
                    //increment the str and the dest
                    str++;
                    dest++;
                }
                *dest='\0';
                return true;
            }
            str++;
        }
        return false;
    }
    return false;
}

bool edk::String::strCut(char8 limit, const char *str, char8 *dest, bool use){
    return edk::String::strCut(limit, (char8 *)str, dest, use);
}

char8* edk::String::strCut(char8 limit, char8 *str, bool use){
    //First test if the string exist
    if(str){
        edk::uint32 i=0u;
        //find the character
        while(str[i]!='\0'){
            //
            //Test if is equal
            if(str[i]==limit){
                //
                //Test if use
                if(use){
                    //Then copy the string
                    return edk::String::strCopy(&str[i]);
                }
                else{
                    //If don't. Then test if the next is a end of string
                    if(str[i+1u]!='\0'){
                        //Then he can copy the string
                        return edk::String::strCopy(&str[i+1u]);
                    }
                }
            }
            //increment the count
            i++;
        }
    }
    //If he cant fint the character. Return NULL
    return NULL;
}

char8* edk::String::strCut(char8 limit, const char *str, bool use){
    return edk::String::strCut(limit, (edk::char8 *)str, use);
}

bool edk::String::strCut(char8 *str,char8 *dest, char8 start, char8 end, bool use){
    if(str && dest && start && end){
        while(*str){
            //test if the str is equal the limit
            if(*str == start){
                //test if use
                if(use){
                    //
                    *dest = start;
                    dest++;
                    str++;
                }
                while(*str){
                    if(*str == end){
                        //test if use
                        if(use){
                            //
                            *dest = end;
                            dest++;
                        }
                        break;
                    }

                    //copy the character
                    *dest = *str;
                    //increment the str and the dest
                    str++;
                    dest++;
                }
                *dest='\0';
                return true;
            }
            str++;
        }
        return false;
    }
    return false;
}

bool edk::String::strCut(const char *str,char8 *dest, char8 start, char8 end, bool use){
    return edk::String::strCut((char8 *)str,dest, start, end, use);
}

char8* edk::String::strCut(char8 *str, char8 start, char8 end, bool use){
    //first test if the string exist
    if(str){
        //Find the start
        edk::uint32 a = 0u;
        while(str[a]!='\0'){
            //
            /*
            printf("\nsearch %c %u"
                   ,str[a]
                   ,a
                   );
            */
            //test if found the start
            if(str[a]==start){
                //
                //printf(" Found START");

                //search the end
                edk::uint32 b = a+1u;
                while(str[b]!='\0'){
                    //
                    /*
                    printf("\nsearch %c %u"
                           ,str[b]
                           ,b
                           );
                    */
                    //test if found the end
                    if(str[b]==end){
                        //
                        /*
                        printf(" Fount END b-a+1u == %u"
                               ,b-(a+1u)+1u
                               );
                        */
                        edk::uint32 size = b - a;
                        if(use){
                            str = &str[a];
                            size = b - a +2u;
                        }
                        else{
                            str = &str[a+1u];
                        }
                        if(size){
                            size--;
                            if(size){
                                //Create the stirng
                                edk::char8* ret = new edk::char8[size+1u];
                                //set the end of the string
                                if(ret){
                                    //
                                    ret[size]='\0';
                                    //Then can copy the string
                                    for(edk::uint32 i=0u;i<size;i++){
                                        //copy the string
                                        if(*str){
                                            ret[i]=*str;
                                        }
                                        else{
                                            ret[i]='\0';
                                            break;
                                        }
                                        str++;
                                    }
                                    //return the ret
                                    return ret;
                                }
                                else{
                                    //
                                    ret=NULL;
                                }
                            }
                        }
                        //break
                        break;
                    }
                    //increment the b count
                    b++;
                }

                //then break;
                break;
            }

            //increment a count
            a++;
        }
    }
    return NULL;
}

char8* edk::String::strCut(const char *str, char8 start, char8 end, bool use){
    return edk::String::strCut((edk::char8 *)str, start, end, use);
}

bool String::strInvert(char8 *str){
    //first count the string
    edk::uint32 size=edk::String::strSize(str);
    //test if the string have characters
    if(size){
        size--;
        //copyTheString

        if(str){
            //invert the string
            edk::char8 temp=0u;
            for(edk::uint32 i=0u;i<=(size/2u);i++){
                //invert the character
                temp = str[i];
                str[i]=str[size-i];
                str[size-i]=temp;
            }
            return true;
        }
    }
    return false;
}

bool String::strInvert(const char *str){
    return edk::String::strInvert((edk::char8*)str);
}

edk::uint64 String::stringHaveChar(char8 *str,edk::char8 value){
    if(str){
        edk::uint64 count=0u;
        while(*str){
            if(*str==value){
                count++;
                return count;
            }
            count++;
            str++;
        }
    }
    return 0u;
}

edk::uint64 String::stringHaveChar(const char *str,edk::char8 value){
    return edk::String::stringHaveChar((char8 *)str,value);
}

edk::uint64 String::stringHaveChar(char8 *str,edk::uint64 size,edk::char8 value){
    if(str){
        edk::uint32 count=0u;
        for(edk::uint64 i=0u;i<size;i++){
            if(str[i]==value){
                count++;
                return count;
            }
            count++;
        }
    }
    return 0u;
}
edk::uint64 String::stringHaveChar(const char *str,edk::uint64 size,edk::char8 value){
    return edk::String::stringHaveChar((char8 *)str,size,value);
}

bool String::consoleKeyPressed(){
    if(edkKbhit()){
        //
        return true;
    }
    return false;
}

char8 String::consoleReadKey(){
    return edkGetch();
}

char8* String::consoleReadString(){
    return readFromTheConsole(0u);
}

void String::consoleClear(){
    //cleat console using a operatin system command
#if defined(WIN32) || defined(WIN64)//Windows
    system("cls");
#elif defined(__linux__) || defined(__APPLE__) //Linux //MacOS
    printf("\033c");fflush(stdout);
#endif
}

//return the console size
edk::size2ui32 String::consoleGetSize(){
    edk::size2ui32 ret(0u,0u);
#if _WIN32 || _WIN64
#else
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    ret.width = w.ws_row;
    ret.height = w.ws_col;
#endif
    return ret;
}

char8* String::strCopy(char8 *str){
    edk::char8* strRet=NULL;

    //count the string
    edk::uint32 size = edk::String::strSize(str);
    if(size>0u){
        //alloc the string
        strRet = new edk::char8[size+1u];
        //test if alloc de string
        if(strRet){
            strRet[size]='\0';
            //copy the string
            memcpy(strRet,str,size);
            /*
            for(edk::uint32 i=0u;i<size;i++){
                //
                strRet[i]=str[i];
            }
            */
        }
        else{
            //
            strRet=0u;
        }
    }
    return strRet;
}

char8* String::strCopy(const char *str){
    return edk::String::strCopy((edk::char8*)str);
}

//remove a filter from string
edk::char8* String::strCopyWithFilter(char8 *str,char8 *filter){
    edk::char8* strRet=NULL;

    if(filter){
        //count the string
        edk::uint32 sizeFilter = edk::String::strSize(filter);
        if(sizeFilter){
            if(str){
                edk::uint32 sizeWith = edk::String::strSizeWithFilter(str,filter);
                edk::uint32 size = edk::String::strSize(str);
                if(sizeWith>0u){
                    //alloc the string
                    strRet = new edk::char8[sizeWith+1u];
                    //test if alloc de string
                    if(strRet){
                        strRet[sizeWith]='\0';
                        //copy the string
                        edk::uint32 j=0u;
                        for(edk::uint32 i=0u;i<size;i++){
                            if(!edk::String::stringHaveChar(filter,sizeFilter,str[i])){
                                //the copy the character not with the filter
                                strRet[j] = str[i];
                                j++;
                                if(j>=sizeWith){
                                    break;
                                }
                            }
                        }
                    }
                    else{
                        //
                        strRet=0u;
                    }
                }
            }
        }
        else return edk::String::strCopy(str);
    }
    else return edk::String::strCopy(str);
    return strRet;
}
edk::char8* String::strCopyWithFilter(const char *str,char8 *filter){
    return strCopyWithFilter((char8 *)str,filter);
}
edk::char8* String::strCopyWithFilter(char8 *str,const char *filter){
    return strCopyWithFilter(str,(char8 *)filter);
}
edk::char8* String::strCopyWithFilter(const char *str,const char *filter){
    return strCopyWithFilter((char8 *)str,(char8 *)filter);
}

char8* String::clipboardRead(){
    //variavel do clipboard
    edk::char8* str=NULL;

    //Codigo windows 32
#if defined(_WIN32) || defined(_WIN64)//Windows
    //abre o clipboard
    HANDLE clip;
    if(OpenClipboard(NULL)){
        //carrega o texto
        clip = GetClipboardData(CF_TEXT);

        if(clip){
            //Copia o clip
            str=strCopy((edk::char8*)clip);
            //NAO DELETAR O CLIP
        }

        //fecha o clipboard
        CloseClipboard();
    }

#elif defined(__linux__) || defined(__APPLE__)
    //codigo em linux
#endif
    //fim codigo windows 64

    return str;
}

bool String::clipboardWrite(char8 *str){
    bool ret=false;

    //copia a string se a mesma for estatica
    edk::char8* temp = strCopy(str);

    //primeiro limpa o clipboard
    edk::String::clipboardClean();

    //Codigo windows 32
#if defined(_WIN32) || defined(_WIN64)
    //abre o clipboard
    if(OpenClipboard(NULL)){
        //Escreve o texto
        if(temp){
            //pode escrever o texto
            if(SetClipboardData(CF_TEXT,(HANDLE)temp)){
                //
                ret=true;
            }
        }
        //fecha o clipboard
        CloseClipboard();
    }
    //fim codigo windows 64

#elif defined(__linux__)
    //codigo em linux


#endif


    //no final ele deleta a temp
    if(temp){
        //
        delete[] temp;
    }

    //retorna o resultado
    return ret;
}

bool String::clipboardWrite(const char *str){
    return edk::String::clipboardWrite((edk::char8*)str);
}

bool String::clipboardClean(){
    //variavel de retorno
    bool ret=false;

    //Codigo windows 32
#if defined(_WIN32) || defined(_WIN64)
    //abre o clipboard
    if(OpenClipboard(NULL)){
        //Limpa o buffer
        if(EmptyClipboard()){
            //
            ret=true;
        }

        //fecha o clipboard
        CloseClipboard();
    }
    //fim codigo windows 64

#elif __linux__
    //codigo em linux

#endif

    //senao retorna false
    return ret;
}



//filter string accent's
edk::char8 String::filterAccent(const edk::char8* str){
    return edk::String::filterAccent((edk::char8*) str);
}
edk::char8 String::filterAccent(edk::char8* str){
    //
    if(str){
        if((edk::uint8)*str==195u){
            str++;
            switch((edk::uint8)*str){
            case 128u:
                //printf("\nCrase A");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 129u:
                //printf("\nAcento A");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 130u:
                //printf("\nChapeu A");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 131u:
                //printf("\nTio A");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 132u:
                //printf("\nTrema A");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 135u:
                //printf("\nCedilha Maiusculo");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 136u:
                //printf("\nCrase E");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 137u:
                //printf("\nAcento E");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 138u:
                //printf("\nChapeu E");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 139u:
                //printf("\nTrema E");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 140u:
                //printf("\nCrase I");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 141u:
                //printf("\nAcento I");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 142u:
                //printf("\nChapeu I");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 143u:
                //printf("\nTrema I");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 145u:
                //printf("\nTio N");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 146u:
                //printf("\nCrase O");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 147u:
                //printf("\nAcento O");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 148u:
                //printf("\nChapeu O");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 149u:
                //printf("\nTio O");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 150u:
                //printf("\nTrema O");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 153u:
                //printf("\nCrase U");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 154u:
                //printf("\nAcento U");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 155u:
                //printf("\nChapeu U");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 156u:
                //printf("\nTrema U");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 157u:
                //printf("\nAcento Y");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 160u:
                //printf("\nCrase a");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 161u:
                //printf("\nAcento a");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 162u:
                //printf("\nChapeu a");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 163u:
                //printf("\nTio a");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 164u:
                //printf("\nTrema a");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 167u:
                //printf("\nCedilha Minusculo");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 168u:
                //printf("\nCrase e");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 169u:
                //printf("\nAcento e");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 170u:
                //printf("\nChapeu e");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 171u:
                //printf("\nTrema e");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 172u:
                //printf("\nCrase i");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 173u:
                //printf("\nAcento i");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 174u:
                //printf("\nChapeu i");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 175u:
                //printf("\ntrema i");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 177u:
                //printf("\nTio n");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 178u:
                //printf("\nCrase o");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 179u:
                //printf("\nAcento o");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 180u:
                //printf("\nChapeu o");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 181u:
                //printf("\nTio o");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 182u:
                //printf("\nTrema o");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 185u:
                //printf("\nCrase u");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 186u:
                //printf("\nAcento u");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 187u:
                //printf("\nChapeu u");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 188u:
                //printf("\nTrema u");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 189u:
                //printf("\nAcento y");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            }
            str--;
        }
        else if((edk::uint8)*str==225u){
            str++;
            if((edk::uint8)*str==186u){
                str++;
                if((edk::uint8)*str==189u){
                    //printf("\nTio e");
                    return 32u;
                }
                str--;
            }
            str--;
        }
        else if((edk::uint8)*str==196u){
            str++;
            if((edk::uint8)*str==169u){
                //printf("\nTio i");
                return 32u;
            }
            str--;
        }
        else if((edk::uint8)*str==197u){
            str++;
            if((edk::uint8)*str==169u){
                //printf("\nTio u");
                return 32u;
            }
            str--;
        }
        return (edk::uchar8)*str;
    }
    return 0u;
}
edk::char8 edk::String::filterAccent(const edk::char8* str,edk::uint8* jump){
    return edk::String::filterAccent((edk::char8*) str,jump);
}
edk::char8 edk::String::filterAccent(edk::char8* str,edk::uint8* jump){

    if(str && jump){
        *jump=1u;
        if((edk::uint8)*str==195u){
            *jump+=1u;
            str++;
            switch((edk::uint8)*str){
            case 128u:
                //printf("\nCrase A");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 129u:
                //printf("\nAcento A");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 130u:
                //printf("\nChapeu A");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 131u:
                //printf("\nTio A");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 132u:
                //printf("\nTrema A");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 135u:
                //printf("\nCedilha Maiusculo");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 136u:
                //printf("\nCrase E");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 137u:
                //printf("\nAcento E");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 138u:
                //printf("\nChapeu E");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 139u:
                //printf("\nTrema E");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 140u:
                //printf("\nCrase I");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 141u:
                //printf("\nAcento I");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 142u:
                //printf("\nChapeu I");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 143u:
                //printf("\nTrema I");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 145u:
                //printf("\nTio N");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 146u:
                //printf("\nCrase O");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 147u:
                //printf("\nAcento O");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 148u:
                //printf("\nChapeu O");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 149u:
                //printf("\nTio O");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 150u:
                //printf("\nTrema O");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 153u:
                //printf("\nCrase U");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 154u:
                //printf("\nAcento U");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 155u:
                //printf("\nChapeu U");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 156u:
                //printf("\nTrema U");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 157u:
                //printf("\nAcento Y");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 160u:
                //printf("\nCrase a");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 161u:
                //printf("\nAcento a");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 162u:
                //printf("\nChapeu a");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 163u:
                //printf("\nTio a");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 164u:
                //printf("\nTrema a");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 167u:
                //printf("\nCedilha Minusculo");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 168u:
                //printf("\nCrase e");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 169u:
                //printf("\nAcento e");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 170u:
                //printf("\nChapeu e");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 171u:
                //printf("\nTrema e");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 172u:
                //printf("\nCrase i");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 173u:
                //printf("\nAcento i");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 174u:
                //printf("\nChapeu i");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 175u:
                //printf("\ntrema i");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 177u:
                //printf("\nTio n");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 178u:
                //printf("\nCrase o");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 179u:
                //printf("\nAcento o");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 180u:
                //printf("\nChapeu o");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 181u:
                //printf("\nTio o");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 182u:
                //printf("\nTrema o");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 185u:
                //printf("\nCrase u");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 186u:
                //printf("\nAcento u");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 187u:
                //printf("\nChapeu u");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 188u:
                //printf("\nTrema u");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            case 189u:
                //printf("\nAcento y");fflush(stdout);
                return ((edk::uchar8)*str) + 64u;
            default:
                *jump-=1u;
                str--;
            }
        }
        else if((edk::uint8)*str==225u){
            *jump+=1u;
            str++;
            if((edk::uint8)*str==186u){
                *jump+=1u;
                str++;
                if((edk::uint8)*str==189u){
                    //printf("\nTio e");
                    return 32u;
                }
                *jump-=1u;
                str--;
            }
            *jump-=1u;
            str--;
        }
        else if((edk::uint8)*str==196u){
            *jump+=1u;
            str++;
            if((edk::uint8)*str==169u){
                //printf("\nTio i");
                return 32u;
            }
            *jump-=1u;
            str--;
        }
        else if((edk::uint8)*str==197u){
            *jump+=1u;
            str++;
            if((edk::uint8)*str==169u){
                //printf("\nTio u");
                return 32u;
            }
            *jump-=1u;
            str--;
        }
        return (edk::uchar8)*str;
    }
    return 0u;
}
edk::uint32 edk::String::strSizeFilterAccent(const edk::char8* str){
    return edk::String::strSizeFilterAccent((edk::char8*) str);
}
edk::uint32 edk::String::strSizeFilterAccent(edk::char8* str){
    edk::uint32 ret = 0u;
    edk::uint8 jump=0u;
    if(str){
        while(*str){
            jump=0u;
            //filter the character
            edk::String::filterAccent(str,&jump);
            //increment the ret
            ret++;
            //jump the string
            str+=jump;
        }
    }
    return ret;
}
//copy with filter
edk::char8* edk::String::strCopyFilterAccent(const edk::char8* str){
    return edk::String::strCopyFilterAccent((edk::char8*) str);
}
edk::char8* edk::String::strCopyFilterAccent(edk::char8* str){
    if(str){
        //get the size of the string
        edk::uint32 size = edk::String::strSizeFilterAccent(str);
        if(size){
            //create the new string
            edk::char8* ret = new edk::char8[size+1u];
            if(ret){
                ret[size] = '\0';
                edk::uint8 jump=0u;
                //copy the character with filter
                for(edk::uint32 i=0u;i<size;i++){
                    jump=0u;
                    ret[i] = edk::String::filterAccent(str,&jump);
                    //jump string
                    str+=jump;
                }
                return ret;
            }
        }
    }
    return NULL;
}

//return the file name from a string
edk::char8* edk::String::strFileName(edk::char8* str){
    edk::char8* ret = NULL;
    if(str){
        //create a pointer to read the string
        edk::char8* temp = str;
        //go to the end of the string
        while(*temp){
            temp++;
        }
        edk::uint32 size = 0u;
        //go back counting the size of the string
        while(*temp!='/' && *temp!='\\' && temp!=str){
            temp--;
            size++;
        }
        if(*temp=='/' || *temp=='\\'){
            temp++;
            if(size)
                size--;
        }
        if(size){
            //create a new string with the size
            ret = new edk::char8[size+1u];
            if(ret){
                //set the string end
                ret[size]='\0';
                //copy the name of the file to the return
                for(edk::uint32 i = 0u;i<size;i++){
                    ret[i] = temp[i];
                }
            }
        }
    }
    return ret;
}
edk::char8* edk::String::strFileName(const edk::char8* str){
    return edk::String::strFileName((edk::char8*) str);
}
bool edk::String::strFileName(edk::char8* str,edk::char8* dest){
    bool ret=false;
    if(str && dest){
        //create a pointer to read the string
        edk::char8* temp = str;
        //go to the end of the string
        while(*temp){
            temp++;
        }
        if(temp!=str){
            ret=true;
        }
        //go back
        while(*temp=='/' && *temp=='\\' && temp!=str){
            temp--;
        }
        if(*temp!='/' || *temp!='\\') temp++;
        //copy the string from the temp
        while(*temp){
            *dest = *temp;
            temp++;
            dest++;
        }
        //at the end set the dest end
        *dest=0u;
        return ret;
    }
    return ret;
}
bool edk::String::strFileName(const edk::char8* str,edk::char8* dest){
    return edk::String::strFileName((edk::char8*) str,dest);
}

//BASE64
const edk::char8 b64chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int b64invs[] = { 62, -1, -1, -1, 63, 52, 53, 54, 55, 56, 57, 58,
                  59, 60, 61, -1, -1, -1, -1, -1, -1, -1, 0, 1, 2, 3, 4, 5,
                  6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                  21, 22, 23, 24, 25, -1, -1, -1, -1, -1, -1, 26, 27, 28,
                  29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42,
                  43, 44, 45, 46, 47, 48, 49, 50, 51 };
//encode
//return the encode result size
edk::uint64 edk::String::base64EncodeSize(edk::uint64 size){
    edk::uint64 ret;

    ret = size;
    if (size % 3 != 0)
        ret += 3 - (size % 3);
    ret /= 3;
    ret *= 4;

    return ret;
}
//convert the vector to base64 receiving the pre alloc string
bool edk::String::base64Encode(edk::uint8* vec,edk::uint64 size,edk::char8* dest){
    if(vec && size){
        edk::uint64  elen;
        edk::uint64  i;
        edk::uint64  j;
        edk::uint64  v;

        elen = edk::String::base64EncodeSize(size);
        dest[elen] = '\0';

        for (i=0, j=0; i<size; i+=3, j+=4) {
            v = vec[i];
            v = i+1 < size ? v << 8 | vec[i+1] : v << 8;
            v = i+2 < size ? v << 8 | vec[i+2] : v << 8;

            dest[j]   = b64chars[(v >> 18) & 0x3F];
            dest[j+1] = b64chars[(v >> 12) & 0x3F];
            if (i+1 < size) {
                dest[j+2] = b64chars[(v >> 6) & 0x3F];
            } else {
                dest[j+2] = '=';
            }
            if (i+2 < size) {
                dest[j+3] = b64chars[v & 0x3F];
            } else {
                dest[j+3] = '=';
            }
        }

        return true;
    }
    return false;
}
bool edk::String::base64Encode(edk::char8* str,edk::uint64 size,edk::char8* dest){
    return edk::String::base64Encode((edk::uint8*) str,size,dest);
}
bool edk::String::base64Encode(const edk::char8* str,edk::uint64 size,edk::char8* dest){
    return edk::String::base64Encode((edk::uint8*) str,size,dest);
}
//convert the vector to base64 new string
edk::char8* edk::String::base64Encode(edk::uint8* vec,edk::uint64 size){
    edk::char8   *out;
    edk::uint64  elen;

    if (vec == NULL || size == 0)
        return NULL;

    elen = edk::String::base64EncodeSize(size);
    out  = (edk::char8*)malloc(elen+1);
    out[elen] = '\0';

    edk::String::base64Encode(vec,size,out);

    return out;
}
edk::char8* edk::String::base64Encode(edk::char8* str,edk::uint64 size){
    return edk::String::base64Encode((edk::uint8*) str,size);
}
edk::char8* edk::String::base64Encode(const edk::char8* str,edk::uint64 size){
    return edk::String::base64Encode((edk::uint8*) str,size);
}
//decode
//convert a base64 to a pre alloc vector
edk::uint64 edk::String::base64DecodeSize(edk::char8* str){
    edk::uint64 len;
    edk::uint64 ret;
    edk::uint64 i;

    if (str == NULL)
        return 0;

    len = edk::String::strSize(str);
    ret = len / 4 * 3;

    for (i=len; i-->0; ) {
        if (str[i] == '=') {
            ret--;
        } else {
            break;
        }
    }

    return ret;
}
bool edk::String::base64Decode(edk::char8* str,edk::uint8* dest){
    edk::uint64 len;
    edk::uint64 i;
    edk::uint64 j;
    int    v;

    if (str == NULL || dest == NULL)
        return false;

    len = edk::String::strSize(str);
    /*
    if (size < edk::String::base64DecodeSize(str) || len % 4 != 0)
        return false;
    */

    for (i=0; i<len; i++){
        //test if it's a valid character
        if((str[i] < '0' && str[i] > '9') &&
                (str[i] < 'A' && str[i] > 'Z') &&
                (str[i] < 'a' && str[i] > 'z') &&
                (str[i] != '+' || str[i] != '/' || str[i] != '=')
                ){
            return false;
        }
    }

    for (i=0, j=0; i<len; i+=4, j+=3) {
        v = b64invs[str[i]-43];
        v = (v << 6) | b64invs[str[i+1]-43];
        v = str[i+2]=='=' ? v << 6 : (v << 6) | b64invs[str[i+2]-43];
        v = str[i+3]=='=' ? v << 6 : (v << 6) | b64invs[str[i+3]-43];

        dest[j] = (v >> 16) & 0xFF;
        if (str[i+2] != '=')
            dest[j+1] = (v >> 8) & 0xFF;
        if (str[i+3] != '=')
            dest[j+2] = v & 0xFF;
    }
    return true;
}
bool edk::String::base64Decode(const edk::char8* str,edk::uint8* dest){
    return edk::String::base64Decode((edk::char8*) str,dest);
}

} /* End of namespace edk */
