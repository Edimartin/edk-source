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
    struct termios velho, novo;
    int x;

    tcgetattr( STDIN_FILENO, &velho );
    novo= velho;
    novo.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &novo );
    x= getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &velho );
    return x;
}

int edkKbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
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
double edkModuleFloat64(edk::float64 value){
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

edk::float32 String::strToFloat32(const char *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A7C8 begin
{
    return edk::String::strToFloat32((edk::char8*)str);
}
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A7C8 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

edk::float32 String::strToFloat32(char8 *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001818 begin
{
    if(str)
        return (edk::float32)atof((const char*)str);
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
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001818 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

int64 String::strToInt64(char8 *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A7D3 begin
{
    if(str)
        return (edk::int64)atol((const char*)str);
    return 0;
}
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A7D3 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

int64 String::strToInt64(const char *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000181C begin
{
    return edk::String::strToInt64((edk::char8*)str);
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000181C end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

double String::strToFloat64(char8 *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A7DE begin
{
    if(str)
        return strtod ((const char*)str,NULL);
    return 0.0;
}
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A7DE end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

double String::strToFloat64(const char *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000181F begin
{
    return edk::String::strToFloat64((edk::char8*)str);
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000181F end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

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

int32 String::strToInt32(char8 *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001822 begin
{
    if(str)
        return (edk::int32)atoi((const char*)str);
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
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001822 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

int32 String::strToInt32(const char *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001822 begin
{
    return edk::String::strToInt32((edk::char8*)str);
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001822 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* String::int32ToStr(int32 value)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000184D begin
{
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
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000184D end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* String::int64ToStr(int64 value)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001851 begin
{
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
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001851 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

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
        printf("\n");
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

char8* String::float32ToStr(edk::float32 value)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001854 begin
{
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
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001854 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* String::float32ToStr(edk::float32 value, int32 digits)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001857 begin
{
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
        beforeStr=edk::String::strCopy((const char*)".0");
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
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001857 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* String::float64ToStr(edk::float64 value, int32 digits)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000185B begin
{
    //first divide the value in two. After the point and before the poinf
    edk::int32 before = (edk::int32)value;
    double after= edkModuleFloat64(value-(edk::float64)before);
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
        beforeStr=edk::String::strCopy((const char*)".0");
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
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000185B end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* String::uint32ToStr(uint32 value)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000185F begin
{
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
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000185F end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

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

char8* String::strCat(char8 *str1, char8 *str2)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001862 begin
{
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
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001862 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* String::strCat(char8 *str1, const char *str2){
    return edk::String::strCat(str1, (char8*) str2);
}

char8* String::strCat(const char *str1, char8 *str2){
    return edk::String::strCat((char8*) str1,str2);
}

char8* String::strCat(const char *str1, const char *str2)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001826 begin
{
    return edk::String::strCat((edk::char8*)str1,(edk::char8*)str2);
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001826 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* String::strCatMulti(char8 *str, ...)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001866 begin
{
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
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001866 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* String::strCatMulti(const char *str, ...)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000182A begin
{
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
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000182A end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool String::strCompare(char8 *str1, char8 *str2)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A837 begin
{
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

// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A837 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool String::strCompare(const char *str1, const char *str2)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000182E begin
{
    return edk::String::strCompare((edk::char8*)str1,(edk::char8*)str2);
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000182E end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

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
                    if(*str1 && *str2){
                        if(*str1 == *str2) return true;
                    }
                }
            }
            return false;
        }
    }
    //else test normalCompare
    return edk::String::strCompare(str1,str2);
}
bool String::strCompareWithFilter(char8 *str1, char8 *str2,const char *filter){
    return strCompareWithFilter(str1, str2,(char8 *)filter);
}
bool String::strCompareWithFilter(const char *str1, const char *str2,const char *filter){
    return strCompareWithFilter((char8 *)str1, (char8 *)str2,(char8 *)filter);
}
bool String::strCompareWithFilter(const char *str1, const char *str2,char8 *filter){
    return strCompareWithFilter((char8 *)str1, (char8 *)str2,filter);
}
bool String::strCompareWithFilter(char8 *str1, const char *str2,const char *filter){
    return strCompareWithFilter(str1, (char8 *)str2,(char8 *)filter);
}
bool String::strCompareWithFilter(char8 *str1, const char *str2,char8 *filter){
    return strCompareWithFilter(str1, (char8 *)str2,filter);
}
bool String::strCompareWithFilter(const char *str1, char8 *str2,const char *filter){
    return strCompareWithFilter((char8 *)str1, str2,(char8 *)filter);
}
bool String::strCompareWithFilter(const char *str1, char8 *str2,char8 *filter){
    return strCompareWithFilter((char8 *)str1, str2,filter);
}

uint64 String::strSize(char8 *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A847 begin
{
    edk::uint64 i=0u;

    //first test the CString
    if(str){
        //then count the CString
        while(true){
            //
            if(*str=='\0'){
                //then find the end of the string
                break;
            }

            //increment i to continue the counting
            i++;
            str++;
        }
    }
    return i;
}
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A847 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

uint64 String::strSize(const char *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001832 begin
{
    return edk::String::strSize((edk::char8*)str);
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001832 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

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

char8* String::strCut(char8 *str, char8 limit, bool use)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000186A begin
{
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
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000186A end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* String::strCut(const char *str, char8 limit, bool use)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001835 begin
{
    return edk::String::strCut((edk::char8 *)str, limit, use);
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001835 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* String::strCut(char8 limit, char8 *str, bool use)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001873 begin
{
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
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001873 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* String::strCut(char8 limit, const char *str, bool use)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000183A begin
{
    return edk::String::strCut(limit, (edk::char8 *)str, use);
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000183A end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* String::strCut(char8 *str, char8 start, char8 end)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000186E begin
{
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
                        //Create the stirng
                        edk::char8* ret = new edk::char8[b-(a+1u)+1u];
                        //set the end of the string
                        if(ret){
                            //
                            ret[b-a]='\0';
                            //Then can copy the string
                            for(edk::uint32 i=0u;i<b-(a+1u);i++){
                                //copy the string
                                /*
                                printf("\nCopy %u %u"
                                       ,i
                                       ,i+a
                                       );
                                */
                                ret[i]=str[i+(a+1u)];
                            }
                            //return the ret
                            return ret;
                        }
                        else{
                            //
                            ret=NULL;
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
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000186E end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* String::strCut(const char *str, char8 start, char8 end)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000183F begin
{
    return edk::String::strCut((edk::char8 *)str, start, end);
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000183F end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool String::strInvert(char8 *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A887 begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A887 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool String::strInvert(const char *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001844 begin
{
    return edk::String::strInvert((edk::char8*)str);
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001844 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

edk::uint32 String::stringHaveChar(char8 *str,edk::char8 value){
    if(str){
        edk::uint32 count=0u;
        while(*str){
            if(*str==value){
                count++;
            }
            str++;
        }
        return count;
    }
    return 0u;
}

edk::uint32 String::stringHaveChar(const char *str,edk::char8 value){
    return edk::String::stringHaveChar((char8 *)str,value);
}

edk::uint32 String::stringHaveChar(char8 *str,edk::uint64 size,edk::char8 value){
    if(str){
        edk::uint32 count=0u;
        for(edk::uint64 i=0u;i<size;i++){
            if(str[i]==value){
                count++;
            }
        }
        return count;
    }
    return 0u;
}
edk::uint32 String::stringHaveChar(const char *str,edk::uint64 size,edk::char8 value){
    return edk::String::stringHaveChar((char8 *)str,size,value);
}

bool String::consoleKeyPressed()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A891 begin
{
    if(edkKbhit()){
        //
        return true;
    }
    return false;
}
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A891 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8 String::consoleReadKey()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A893 begin
{
    return edkGetch();
}
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A893 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* String::consoleReadString()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001879 begin
{
    return readFromTheConsole(0u);
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001879 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

void String::consoleClear()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A899 begin
{
    //cleat console using a operatin system command
#if defined(WIN32) || defined(WIN64)//Windows
    system("cls");
#elif defined(__linux__) || defined(__APPLE__) //Linux //MacOS
    printf("\033c");
#endif
}
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A899 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

//return the console size
edk::size2ui32 String::consoleGetSize(){
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    return edk::size2ui32(w.ws_row,w.ws_col);
}

char8* String::strCopy(char8 *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000187B begin
{
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
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000187B end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

char8* String::strCopy(const char *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001847 begin
{
    return edk::String::strCopy((edk::char8*)str);
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:0000000000001847 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

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

char8* String::clipboardRead()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000187E begin
{
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
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000187E end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool String::clipboardWrite(char8 *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8AD begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8AD end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool String::clipboardWrite(const char *str)
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000184A begin
{
    return edk::String::clipboardWrite((edk::char8*)str);
}
// section 127-0-1-1--6dbd80b8:13ae66a9e93:-8000:000000000000184A end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element

bool String::clipboardClean()
// don't delete the following line as it's needed to preserve source code of this autogenerated element
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8B7 begin
{
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
// section 127-0-1-1-268c1826:13ad7e2c651:-8000:000000000000A8B7 end
// don't delete the previous line as it's needed to preserve source code of this autogenerated element



//filter string accent's
edk::char8 String::filterAccent(const char* str){
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
                str--;
            }
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
edk::char8 edk::String::filterAccent(const char* str,edk::uint8* jump){
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
edk::uint32 edk::String::strSizeFilterAccent(const char* str){
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
edk::char8* edk::String::strCopyFilterAccent(const char* str){
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

} /* End of namespace edk */
