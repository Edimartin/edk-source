#include "String.h"

/*
Library C++ String - Manipulate char vectors.
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
#pragma message "            Inside String.cpp"
#endif

//write the isspace function
edk::int32 edkIsSpace(edk::int32 c){
    return (c == '\t' || c == '\n' ||
            c == '\v' || c == '\f' || c == '\r' || c == ' ' ? 1 : 0);
}

edk::int32 edkModuleInt32(edk::int32 value){
    if(value<0){
        return value*-1;
    }
    return value;
}
edk::int64 edkModuleInt64(edk::int64 value){
    if(value<0){
        return value*-1;
    }
    return value;
}
edk::float32 edkModuleFloat32(edk::float32 value){
    if(value<0.0f){
        return value*-1.0f;
    }
    return value;
}
edk::float64 edkModuleFloat64(edk::float64 value){
    if(value<0.0L){
        return value*-1.0L;
    }
    return value;
}


edk::char8* edk::String::int32ToMinusStr(edk::int32 value){

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
        str = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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
        str = (edk::char8*)malloc(sizeof(edk::char8) * (3u));
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
bool edk::String::int32ToMinusStr(edk::int32 value,edk::char8* dest){
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
        dest = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
        if(dest){
            dest[0u]='-';
            dest[size]='\0';
            //then convert the number
            for(edk::uint32 j=size;j>begin;j--){
                //
                edk::uint32 i=j-1u;
                //convert in this line
                dest[i]=(module%10)+48;
                module=module/10;
            }
            return true;
        }
    }
    else{
        //create a zero
        dest = (edk::char8*)malloc(sizeof(edk::char8) * (3u));
        if(dest){
            dest[0u]='-';
            dest[1u]='0';
            dest[2u]='\0';
            return true;
        }
    }
    return false;
}
edk::char8* edk::String::int64ToMinusStr(edk::int64 value){

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
        str = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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
        str = (edk::char8*)malloc(sizeof(edk::char8) * (3u));
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
bool edk::String::int64ToMinusStr(edk::int64 value,edk::char8* dest){
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
        if(dest){
            dest[0u]='-';
            dest[size]='\0';
            //then convert the number
            for(edk::uint32 j=size;j>begin;j--){
                //
                edk::uint32 i=j-1u;
                //convert in this line
                dest[i]=(module%10)+48;
                module=module/10;
            }
            return true;
        }
    }
    else{
        if(dest){
            dest[0u]='-';
            dest[1u]='0';
            dest[2u]='\0';
            return true;
        }
    }
    return false;
}

//copy the number to the string
bool edk::String::copyInt32ToStr(edk::int32 value,edk::char8* str,edk::int32 size){
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

bool edk::String::copyInt64ToStr(edk::int64 value,edk::char8* str,edk::int32 size){
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

edk::float32 edk::String::strToFloat32(const char *str){
    return edk::String::strToFloat32((edk::char8*)str);
}

edk::float32 edk::String::strToFloat32(edk::char8 *str){
    if(str){
        return (edk::float32)atof((const edk::char8*)str);
    }
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

edk::int64 edk::String::strToInt64(edk::char8 *str){
    if(str){
        return (edk::int64)atol((const edk::char8*)str);
    }
    return 0;
}

edk::int64 edk::String::strToInt64(const edk::char8 *str){
    return edk::String::strToInt64((edk::char8*)str);
}

edk::float64 edk::String::strToFloat64(char8 *str){
    if(str){
        return strtod ((const edk::char8*)str,NULL);
    }
    return 0.0;
}

edk::float64 edk::String::strToFloat64(const edk::char8 *str){
    return edk::String::strToFloat64((edk::char8*)str);
}

bool edk::String::strToVecInt8(edk::char8* str,edk::int8* vec,edk::uint32 size){
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

bool edk::String::strToVecInt16(edk::char8* str,edk::int16* vec,edk::uint32 size){
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

bool edk::String::strToVecInt32(edk::char8* str,edk::int32* vec,edk::uint32 size){
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

bool edk::String::strToVecInt64(edk::char8* str,edk::int64* vec,edk::uint32 size){
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

bool edk::String::strToVecUint8(edk::char8* str,edk::uint8* vec,edk::uint32 size){
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

bool edk::String::strToVecUint16(edk::char8* str,edk::uint16* vec,edk::uint32 size){
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

bool edk::String::strToVecUint32(edk::char8* str,edk::uint32* vec,edk::uint32 size){
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

bool edk::String::strToVecUint64(edk::char8* str,edk::uint64* vec,edk::uint32 size){
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

bool edk::String::strToVecfloat32(edk::char8* str,edk::float32* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = edk::String::strToFloat32(str);
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

bool edk::String::strToVecfloat64(edk::char8* str,edk::float64* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = edk::String::strToFloat64(str);
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

edk::int32 edk::String::strToInt32(edk::char8 *str){
    if(str){
        return (edk::int32)atoi((const edk::char8*)str);
    }
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

edk::int32 edk::String::strToInt32(const edk::char8 *str){
    return edk::String::strToInt32((edk::char8*)str);
}

#if defined(_WIN32) || defined(_WIN64)
//Convert String to TCHAR from Windows
TCHAR* edk::String::strToTCHAR(const edk::char8* str){
    return edk::String::strToTCHAR((edk::char8*) str);
}
TCHAR* edk::String::strToTCHAR(edk::char8* str){
    edk::int32 size = edk::String::strSize(str);
    TCHAR* ret = (TCHAR*)malloc(sizeof(TCHAR)*size+1u);
    for(int i = 0; i< size+1; i++){
        ret[i]=str[i];
    }
    return ret;
}
#endif

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
        str = (edk::char8*)malloc(sizeof(edk::char8) * (size32+1u));
        if(str){
            //copy the str
            if(edk::String::str32ToUtf8(str32,size,str)){
                //return the str
                return str;
            }
            free(str);
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
            ret = (edk::char8*)malloc(sizeof(edk::char8) * (sizeUtf+1u));
            if(ret){
                if(!edk::String::utf8ToStr(utf8,size,ret)){
                    free(ret);
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
                        else{
                            return ret;
                        }
                        break;
                    case (edk::char8)0x82:
                        utf8++;
                        if(*utf8){
                            ret++;
                        }
                        else{
                            return ret;
                        }
                        break;
                    case (edk::char8)0x84:
                        utf8++;
                        if(*utf8){
                            ret++;
                        }
                        else{
                            return ret;
                        }
                        break;
                    }
                }
                else{
                    return ret;
                }
                break;
            case (edk::char8)0xc2:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else{
                    return ret;
                }
                break;
            case (edk::char8)0xc3:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else{
                    return ret;
                }
                break;
            case (edk::char8)0xc5:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else{
                    return ret;
                }
                break;
            case (edk::char8)0xc6:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else{
                    return ret;
                }
                break;
            case (edk::char8)0xcb:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else{
                    return ret;
                }
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
                        else{
                            return ret;
                        }
                        break;
                    case (edk::char8)0x82:
                        utf8++;
                        if(*utf8){
                            ret++;
                        }
                        else{
                            return ret;
                        }
                        break;
                    case (edk::char8)0x84:
                        utf8++;
                        if(*utf8){
                            ret++;
                        }
                        else{
                            return ret;
                        }
                        break;
                    }
                }
                else{
                    return ret;
                }
                break;
            case (edk::char8)0xc2:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else{
                    return ret;
                }
                break;
            case (edk::char8)0xc3:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else{
                    return ret;
                }
                break;
            case (edk::char8)0xc5:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else{
                    return ret;
                }
                break;
            case (edk::char8)0xc6:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else{
                    return ret;
                }
                break;
            case (edk::char8)0xcb:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else{
                    return ret;
                }
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
    return edk::String::utf8WordSize((edk::char8*) utf8);
}
edk::uint32 edk::String::utf8WordSize(edk::char8 *utf8,edk::uint32* jump){
    edk::uint32 ret=0u;
    if(utf8 && jump){
        edk::char8* str = utf8;
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
                        else{
                            return ret;
                        }
                        break;
                    case (edk::char8)0x82:
                        utf8++;
                        if(*utf8){
                            ret++;
                        }
                        else{
                            return ret;
                        }
                        break;
                    case (edk::char8)0x84:
                        utf8++;
                        if(*utf8){
                            ret++;
                        }
                        else{
                            return ret;
                        }
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
                else{
                    return ret;
                }
                break;
            case (edk::char8)0xc3:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else{
                    return ret;
                }
                break;
            case (edk::char8)0xc5:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else{
                    return ret;
                }
                break;
            case (edk::char8)0xc6:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else{
                    return ret;
                }
                break;
            case (edk::char8)0xcb:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else{
                    return ret;
                }
                break;
            default:
                ret++;
                break;
            }
            utf8++;
        }
        *jump = utf8-str;
    }
    return ret;
}
edk::uint32 edk::String::utf8WordSize(const edk::char8 *utf8,edk::uint32* jump){
    return edk::String::utf8WordSize((edk::char8*) utf8,jump);
}
edk::uint32 edk::String::utf8WordSize(edk::char8 *utf8,edk::uint32 limit,edk::uint32* jump){
    edk::uint32 ret=0u;
    if(utf8 && jump){
        edk::char8* str = utf8;
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
                        else{
                            return ret;
                        }
                        break;
                    case (edk::char8)0x82:
                        utf8++;
                        if(*utf8){
                            ret++;
                        }
                        else{
                            return ret;
                        }
                        break;
                    case (edk::char8)0x84:
                        utf8++;
                        if(*utf8){
                            ret++;
                        }
                        else{
                            return ret;
                        }
                        break;
                    }
                }
                else{
                    return ret;
                }
                break;
            case (edk::char8)0xc2:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else{
                    return ret;
                }
                break;
            case (edk::char8)0xc3:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else{
                    return ret;
                }
                break;
            case (edk::char8)0xc5:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else{
                    return ret;
                }
                break;
            case (edk::char8)0xc6:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else{
                    return ret;
                }
                break;
            case (edk::char8)0xcb:
                utf8++;
                if(*utf8){
                    ret++;
                }
                else{
                    return ret;
                }
                break;
            default:
                ret++;
                break;
            }
            utf8++;
            if(ret>=limit){
                break;
            }
        }
        *jump = utf8-str;
    }
    return ret;
}
edk::uint32 edk::String::utf8WordSize(const edk::char8 *utf8,edk::uint32 limit,edk::uint32* jump){
    return edk::String::utf8WordSize((edk::char8*) utf8,limit,jump);
}
edk::uint32 edk::String::utf8LineCount(edk::char8 *utf8,edk::uint32 limit){
    edk::uint32 ret = 0u;
    if(utf8 && limit){
        edk::uint32 word=0u;
        edk::uint32 myJump=0u;
        //count the characte size in the line
        edk::uint32 size = 0u;
        bool newLine = false;
        ret++;
        bool firstLine=false;
        while(*utf8){
            //test if the size extend the limit
            if(size+1u>=limit || *utf8 == '\n' || *utf8 == 10
                    ||
                    newLine
                    ){
                if(*utf8==' '){
                    if(utf8[1u]!=' ' && utf8[1u]!=10 && utf8[1u]!='\n'){
                        utf8++;
                    }
                }
                if(*utf8=='\n' || *utf8==10){
                    utf8++;
                }
                if(firstLine){
                    ret++;
                }
                size=0u;
                newLine = false;
                firstLine=true;
                continue;
            }

            word = edk::String::utf8WordSize(utf8,&myJump);
            if(word){
                //if the next word does't fit in the line it will return the last size
                if(size+word>limit){
                    if(!size){
                        word = edk::String::utf8WordSize(utf8,limit,&myJump);
                    }
                    else{
                        //new line
                        newLine = true;
                        continue;
                    }
                }
                size+=word;
                //go to the space
                utf8+=myJump;
            }
            else{
                size++;
                utf8++;
            }
        }
        if(size){
            ret++;
        }
    }
    return ret;
}
edk::uint32 edk::String::utf8LineCount(const edk::char8 *utf8,edk::uint32 limit){
    return edk::String::utf8LineCount((edk::char8*) utf8,limit);
}
edk::uint32 edk::String::utf8LineSize(edk::char8* utf8,edk::uint32 limit){
    edk::uint32 size = 0u;
    if(utf8 && limit){
        edk::uint32 word=0u;
        edk::uint32 myJump=0u;
        while(*utf8){
            //test if the size extend the limit
            if(size+1u>=limit || *utf8 == '\n' || *utf8 == 10){
                break;
            }

            word = edk::String::utf8WordSize(utf8,&myJump);
            if(word){
                //if the next word does't fit in the line it will return the last size
                if(size+word>limit){
                    break;
                }
                size+=word;
                //go to the space
                utf8+=myJump;
            }
            else{
                size++;
                utf8++;
            }
        }
    }
    return size;
}
edk::uint32 edk::String::utf8LineSize(const edk::char8 *utf8,edk::uint32 limit){
    return edk::String::utf8LineSize((edk::char8*)utf8,limit);
}
edk::uint32 edk::String::utf8LineSize(edk::char8 *utf8,edk::uint32 limit,edk::uint32* jump){
    edk::uint32 size = 0u;
    if(utf8 && limit && jump){
        edk::uint32 word=0u;
        edk::uint32 myJump=0u;
        *jump=0u;
        while(*utf8){
            //test if the size extend the limit
            if(size+1u>=limit || *utf8 == '\n' || *utf8 == 10){
                break;
            }

            word = edk::String::utf8WordSize(utf8,&myJump);
            if(word){
                //if the next word does't fit in the line it will return the last size
                if(size+word>limit){
                    break;
                }
                size+=word;
                *jump+=myJump;
                //go to the jump
                utf8+=myJump;
            }
            else{
                size++;
                utf8++;
                *jump+=1u;
            }
        }
    }
    return size;
}
edk::uint32 edk::String::utf8LineSize(const edk::char8 *utf8,edk::uint32 limit,edk::uint32* jump){
    return edk::String::utf8LineSize((edk::char8*) utf8,limit,jump);
}
//return the position of a string where the line starts
edk::char8* edk::String::utf8LinePosition(edk::char8 *utf8,edk::uint32 limit,edk::uint32 linePosition){
    edk::char8* ret = NULL;
    if(utf8 && limit){
        edk::uint32 word=0u;
        edk::uint32 myJump=0u;
        //count the lines until the line position
        edk::uint32 count=0u;
        //count the characte size in the line
        edk::uint32 size = 0u;
        bool newLine = false;
        ret = utf8;
        while(*utf8){
            //test if the size extend the limit
            if(size+1u>=limit || *utf8 == '\n' || *utf8 == 10
                    ||
                    newLine
                    ){
                if(*utf8==' '){
                    if(utf8[1u]!=' ' && utf8[1u]!=10 && utf8[1u]!='\n'){
                        utf8++;
                    }
                }
                if(*utf8=='\n' || *utf8==10){
                    utf8++;
                }
                if(count>=linePosition){
                    break;
                }
                count++;
                size=0u;
                ret = utf8;
                newLine = false;
                if(count>=linePosition){
                    break;
                }
                continue;
            }

            word = edk::String::utf8WordSize(utf8,&myJump);
            if(word){
                //if the next word does't fit in the line it will return the last size
                if(size+word>limit){
                    if(!size){
                        word = edk::String::utf8WordSize(utf8,limit,&myJump);
                    }
                    else{
                        //new line
                        newLine = true;
                        continue;
                    }
                }
                size+=word;
                //go to the space
                utf8+=myJump;
            }
            else{
                size++;
                utf8++;
            }
        }
    }
    return ret;
}
edk::char8* edk::String::utf8LinePosition(const edk::char8 *utf8,edk::uint32 limit,edk::uint32 linePosition){
    return edk::String::utf8LinePosition((edk::char8*) utf8,limit,linePosition);
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
                    else{
                        return ret;
                    }
                    break;
                case (edk::char8)0x82:
                    utf8++;
                    if(*utf8){
                        ret++;
                    }
                    else{
                        return ret;
                    }
                    break;
                case (edk::char8)0x84:
                    utf8++;
                    if(*utf8){
                        ret++;
                    }
                    else{
                        return ret;
                    }
                    break;
                }
            }
            else{
                return ret;
            }
            break;
        case (edk::char8)0xc2:
            utf8++;
            if(*utf8){
                ret++;
            }
            else{
                return ret;
            }
            break;
        case (edk::char8)0xc3:
            utf8++;
            if(*utf8){
                ret++;
            }
            else{
                return ret;
            }
            break;
        case (edk::char8)0xc5:
            utf8++;
            if(*utf8){
                ret++;
            }
            else{
                return ret;
            }
            break;
        case (edk::char8)0xc6:
            utf8++;
            if(*utf8){
                ret++;
            }
            else{
                return ret;
            }
            break;
        case (edk::char8)0xcb:
            utf8++;
            if(*utf8){
                ret++;
            }
            else{
                return ret;
            }
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

//ASCII to UTF8
bool edk::String::asciiToUtf8(edk::char8* src,edk::char8* dest){
    if(src && dest){
        edk::uchar8 c;
        //
        while(*src){
            c = *src;
            switch(c){
            case 0xC3:
                *dest = c;
                //test if have the C2
                if(src[1u]){
                    c = src[2u];
                    if(c == 0xC2){
                        //if have the c2. Then convert the character
                        src++;
                        c = *src;
                        *dest = c | 0x40;
                    }
                }
                break;
            case 0xC2:
                src++;
                *dest = *src;
                break;
            default:
                *dest = c;
                break;
            }
            src++;
            dest++;
        }
        *dest='\0';
        return true;
    }
    return false;
}
bool edk::String::asciiToUtf8(const edk::char8* src,edk::char8* dest){
    return edk::String::asciiToUtf8((edk::char8*) src,dest);
}
edk::char8* edk::String::asciiToUtf8(edk::char8* src){
    edk::char8* ret=NULL;
    //get the size of the string
    edk::uint32 size = edk::String::asciiToUtf8Size(src);
    if(size){
        //create the string
        ret = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
        if(ret){
            //convert the ascii to utf8
            if(edk::String::asciiToUtf8(src,ret)){
                return ret;
            }
            free(ret);
        }
    }
    return NULL;
}
edk::char8* edk::String::asciiToUtf8(const edk::char8* src){
    return edk::String::asciiToUtf8((edk::char8*) src);
}
//ASCII to UTF8 Size
edk::uint32 edk::String::asciiToUtf8Size(edk::char8* src){
    edk::uint32 ret=0u;
    if(src){
        edk::uchar8 c;
        while(*src){
            c = *src;
            switch(c){
            case 0xC3:
                src++;
                //ret++;
                break;
            case 0xC2:
                src++;
                //ret++;
                break;
            }
            src++;
            ret++;
        }
    }
    return ret;
}
edk::uint32 edk::String::asciiToUtf8Size(const edk::char8* src){
    return edk::String::asciiToUtf8Size((edk::char8*) src);
}

//UTF8 to ASCII
bool edk::String::utf8ToAscii(edk::char8* src,edk::char8* dest){
    if(src && dest){
        edk::uchar8 c;
        while(*src){
            c = *src;
            //test if need getch another character
            if(c>=0xc2 && c<=0xdf){
                //read one more
                *dest=0xC3;
                dest++;
                *dest=c & 0xbf;

                dest++;
                *dest=0xC2;
                dest++;
                src++;
                *dest=*src;
            }
            else if((c>= 0xe0 && c<=0xea)
                    || c==0xed
                    || c==0xef
                    ){
                //read two more
                *dest=0xC3;
                dest++;
                *dest=c & 0xbf;

                dest++;
                *dest=0xC2;
                dest++;
                src++;
                *dest=*src;

                dest++;
                *dest=0xC2;
                dest++;
                src++;
                *dest=*src;
            }
            else if(c==0xf0 || c==0xf3 || c==0xf4){
                //read tree more
                *dest=0xC3;
                dest++;
                *dest=c & 0xbf;

                dest++;
                *dest=0xC2;
                dest++;
                src++;
                *dest=*src;

                dest++;
                *dest=0xC2;
                dest++;
                src++;
                *dest=*src;

                dest++;
                *dest=0xC2;
                dest++;
                src++;
                *dest=*src;
            }
            else{
                *dest=c;
            }
            src++;
            dest++;
        }
        *dest='\0';
        return true;
    }
    return false;
}
bool edk::String::utf8ToAscii(const edk::char8* src,edk::char8* dest){
    return edk::String::utf8ToAscii((edk::char8*) src,dest);
}
edk::char8* edk::String::utf8ToAscii(edk::char8* src){
    edk::char8* ret=NULL;
    //get the size of the string
    edk::uint32 size = edk::String::utf8ToAsciiSize(src);
    if(size){
        //create the string
        ret = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
        if(ret){
            //convert the ascii to utf8
            if(edk::String::utf8ToAscii(src,ret)){
                return ret;
            }
            free(ret);
        }
    }
    return NULL;
}
edk::char8* edk::String::utf8ToAscii(const edk::char8* src){
    return edk::String::utf8ToAscii((edk::char8*) src);
}
//UTF8 to ASCII size
edk::uint32 edk::String::utf8ToAsciiSize(edk::char8* src){
    edk::uint32 size=0u;
    if(src){
        edk::uchar8 c;
        while(*src){
            c = *src;
            //test if need getch another character
            if(c>=0xc2 && c<=0xdf){
                //read one more
                size+=3u;
                src++;
            }
            else if((c>= 0xe0 && c<=0xea)
                    || c==0xed
                    || c==0xef
                    ){
                //read two more
                size+=5u;
                src+=2u;
            }
            else if(c==0xf0 || c==0xf3 || c==0xf4){
                //read tree more
                size+=7u;
                src+=3u;
            }
            src++;
            size++;
        }
    }
    return size;
}
edk::uint32 edk::String::utf8ToAsciiSize(const edk::char8* src){
    return edk::String::utf8ToAsciiSize((edk::char8*) src);
}

edk::uint32 edk::String::int32ToStrSize(edk::int32 value){
    return edk::String::sizeOfInt32(value);
}

edk::uint32 edk::String::int64ToStrSize(edk::int64 value){
    return edk::String::sizeOfInt64(value);
}

edk::char8* edk::String::int32ToStr(edk::int32 value){
    edk::char8* str = 0u;

    //count the number
    edk::uint32 size = edk::String::sizeOfInt32(value);

    //test if the size is bigger then 0u
    if(size>0u){
        //begin
        edk::uint32 begin=0u;
        if(value>=0){
            //Positive
            str = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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
            str = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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
        str = (edk::char8*)malloc(sizeof(edk::char8) * (2u));
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

edk::char8* edk::String::int32ToStr(edk::int32 value,edk::uint32 digits){
    edk::char8* str = 0u;

    //count the number
    edk::uint32 size = edk::String::sizeOfInt32(value);

    //test if the size is bigger then 0u
    if(size>0u){
        if(size>digits){
            size=digits;
        }
        //begin
        edk::uint32 begin=0u;
        if(value>=0){
            //Positive
            str = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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
            str = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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
        str = (edk::char8*)malloc(sizeof(edk::char8) * (2u));
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

edk::char8* edk::String::int64ToStr(edk::int64 value){
    edk::char8* str = 0u;

    //count the number
    edk::uint32 size = edk::String::sizeOfInt64(value);

    //test if the size is bigger then 0u
    if(size>0u){
        //begin
        edk::uint32 begin=0u;
        if(value>=0){
            //Positive
            str = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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
            str = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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
        str = (edk::char8*)malloc(sizeof(edk::char8) * (2u));
        if(str){
            str[0u]='0';
            str[1u]='\0';
        }
        else{
            //else set NULL
            str=NULL;
        }
    }
    return str;
}

edk::char8* edk::String::int64ToStr(edk::int64 value,edk::uint32 digits){

    edk::char8* str = 0u;

    //count the number
    edk::uint32 size = edk::String::sizeOfInt64(value);

    //test if the size is bigger then 0u
    if(size>0u){
        if(size>digits){
            size=digits;
        }
        //begin
        edk::uint32 begin=0u;
        if(value>=0){
            //Positive
            str = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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
            str = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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
        str = (edk::char8*)malloc(sizeof(edk::char8) * (2u));
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

bool edk::String::int32ToStr(edk::int32 value,edk::char8* dest){
    if(dest){
        //count the number
        edk::uint32 size = edk::String::sizeOfInt32(value);

        //test if the size is bigger then 0u
        if(size>0u){
            //begin
            edk::uint32 begin=0u;
            if(value>=0){
                //Positive
                dest[size]='\0';
            }
            else{
                //Negative
                size=size+1u;
                begin=1u;
                dest[0u]='-';
                dest[size]='\0';
            }
            return edk::String::copyInt32ToStr(value,&dest[begin],size-begin);
        }
        else{
            //create a zero
            dest[0u]='0';
            dest[1u]='\0';
        }
        return true;
    }
    return false;
}

bool edk::String::int32ToStr(edk::int32 value,edk::char8* dest,edk::uint32 digits){
    if(dest){
        //count the number
        edk::uint32 size = edk::String::sizeOfInt32(value);

        //test if the size is bigger then 0u
        if(size>0u){
            if(size>digits){
                size=digits;
            }
            //begin
            edk::uint32 begin=0u;
            if(value>=0){
                //Positive
                dest[size]='\0';
            }
            else{
                //Negative
                size=size+1u;
                begin=1u;
                dest[0u]='-';
                dest[size]='\0';
            }
            return edk::String::copyInt32ToStr(value,&dest[begin],size-begin);
        }
        else{
            //create a zero
            dest[0u]='0';
            dest[1u]='\0';
        }
        return true;
    }
    return false;
}

bool edk::String::int64ToStr(edk::int64 value,edk::char8* dest){
    if(dest){
        //count the number
        edk::uint32 size = edk::String::sizeOfInt64(value);

        //test if the size is bigger then 0u
        if(size>0u){
            //begin
            edk::uint32 begin=0u;
            if(value>=0){
                //Positive
                dest[size]='\0';
            }
            else{
                //Negative
                size=size+1u;
                begin=1u;
                dest[0u]='-';
                dest[size]='\0';
            }
            return edk::String::copyInt64ToStr(value,&dest[begin],size-begin);
        }
        else{
            //create a zero
            dest[0u]='0';
            dest[1u]='\0';
        }
        return true;
    }
    return false;
}

bool edk::String::int64ToStr(edk::int64 value,edk::char8* dest,edk::uint32 digits){
    if(dest){
        //count the number
        edk::uint32 size = edk::String::sizeOfInt64(value);

        //test if the size is bigger then 0u
        if(size>0u){
            if(size>digits){
                size=digits;
            }
            //begin
            edk::uint32 begin=0u;
            if(value>=0){
                //Positive
                dest[size]='\0';
            }
            else{
                //Negative
                size=size+1u;
                begin=1u;
                dest[0u]='-';
                dest[size]='\0';
            }
            return edk::String::copyInt64ToStr(value,&dest[begin],size-begin);
        }
        else{
            //create a zero
            dest[0u]='0';
            dest[1u]='\0';
        }
        return true;
    }
    return false;
}

edk::char8* edk::String::vecInt8toStr(edk::int8* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i]){
                stringSize += 2u;
            }
            else{
                //plus the ' '
                stringSize += edk::String::sizeOfInt32(vec[i]) + 1u;
            }
            //add the signal
            if(vec[i]<0){
                stringSize++;
            }
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = (edk::char8*)malloc(sizeof(edk::char8) * (stringSize));
            if(str){
                edk::char8* temp = str;
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i]){
                        sizeTemp = 1u;
                    }
                    else{
                        sizeTemp = edk::String::sizeOfInt32(vec[i]);
                    }
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

edk::char8* edk::String::vecInt16toStr(edk::int16* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i]){
                stringSize += 2u;
            }
            else{
                //plus the ' '
                stringSize += edk::String::sizeOfInt32(vec[i]) + 1u;
            }
            //add the signal
            if(vec[i]<0){
                stringSize++;
            }
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = (edk::char8*)malloc(sizeof(edk::char8) * (stringSize));
            if(str){
                edk::char8* temp = str;
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i]){
                        sizeTemp = 1u;
                    }
                    else{
                        sizeTemp = edk::String::sizeOfInt32(vec[i]);
                    }
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

edk::char8* edk::String::vecInt32toStr(edk::int32* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i]){
                stringSize += 2u;
            }
            else{
                //plus the ' '
                stringSize += edk::String::sizeOfInt64(vec[i]) + 1u;
            }
            //add the signal
            if(vec[i]<0){
                stringSize++;
            }
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = (edk::char8*)malloc(sizeof(edk::char8) * (stringSize));
            if(str){
                edk::char8* temp = str;
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i]){
                        sizeTemp = 1u;
                    }
                    else{
                        sizeTemp = edk::String::sizeOfInt64(vec[i]);
                    }
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
edk::char8* edk::String::vecInt64toStr(edk::int64* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i]){
                stringSize += 2u;
            }
            else{
                //plus the ' '
                stringSize += edk::String::sizeOfInt64(vec[i]) + 1u;
            }
            //add the signal
            if(vec[i]<0){
                stringSize++;
            }
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = (edk::char8*)malloc(sizeof(edk::char8) * (stringSize));
            if(str){
                edk::char8* temp = str;
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i]){
                        sizeTemp = 1u;
                    }
                    else{
                        sizeTemp = edk::String::sizeOfInt64(vec[i]);
                    }
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

edk::char8* edk::String::vecUint8toStr(edk::uint8* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i]){
                stringSize += 2u;
            }
            else{
                //plus the ' '
                stringSize += edk::String::sizeOfInt32(vec[i]) + 1u;
            }
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = (edk::char8*)malloc(sizeof(edk::char8) * (stringSize));
            if(str){
                edk::char8* temp = str;
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i]){
                        sizeTemp = 1u;
                    }
                    else{
                        sizeTemp = edk::String::sizeOfInt32(vec[i]);
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

edk::char8* edk::String::vecUint16toStr(edk::uint16* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i]){
                stringSize += 2u;
            }
            else{
                //plus the ' '
                stringSize += edk::String::sizeOfInt32(vec[i]) + 1u;
            }
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = (edk::char8*)malloc(sizeof(edk::char8) * (stringSize));
            if(str){
                edk::char8* temp = str;
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i]){
                        sizeTemp = 1u;
                    }
                    else{
                        sizeTemp = edk::String::sizeOfInt32(vec[i]);
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

edk::char8* edk::String::vecUint32toStr(edk::uint32* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i]){
                stringSize += 2u;
            }
            else{
                //plus the ' '
                stringSize += edk::String::sizeOfInt64(vec[i]) + 1u;
            }
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = (edk::char8*)malloc(sizeof(edk::char8) * (stringSize));
            if(str){
                edk::char8* temp = str;
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i]){
                        sizeTemp = 1u;
                    }
                    else{
                        sizeTemp = edk::String::sizeOfInt64(vec[i]);
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
edk::char8* edk::String::vecUint64toStr(edk::uint64* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i]){
                stringSize += 2u;
            }
            else{
                //plus the ' '
                stringSize += edk::String::sizeOfInt64(vec[i]) + 1u;
            }
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = (edk::char8*)malloc(sizeof(edk::char8) * (stringSize));
            if(str){
                edk::char8* temp = str;
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i]){
                        sizeTemp = 1u;
                    }
                    else{
                        sizeTemp = edk::String::sizeOfInt64(vec[i]);
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

edk::char8* edk::String::vecfloat32toStr(edk::float32* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;
        for(edk::uint32 i=0u;i<size;i++){
            stringSize += edk::String::sizeOfFloat32(vec[i]) + 1u;
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = (edk::char8*)malloc(sizeof(edk::char8) * (stringSize));
            if(str){
                edk::char8* temp = str;
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    sizeTemp = edk::String::sizeOfFloat32(vec[i]);
                    //copy the number
                    sprintf(temp,"%.4f",vec[i]);
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

edk::char8* edk::String::vecfloat64toStr(edk::float64* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;
        for(edk::uint32 i=0u;i<size;i++){
            stringSize += edk::String::sizeOfFloat64(vec[i]) + 1u;
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = (edk::char8*)malloc(sizeof(edk::char8) * (stringSize));
            if(str){
                edk::char8* temp = str;
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;
                for(edk::uint32 i=0u;i<size;i++){
                    sizeTemp = edk::String::sizeOfFloat64(vec[i]);
                    //copy the number
                    sprintf(temp,"%.4f",vec[i]);
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

edk::uint32 edk::String::sizeOfInt32(edk::int32 value){
    //use the module of the number
    edk::int32 module = edkModuleInt32(value);

    //count the number
    edk::uint32 size = 0;
    while(module>0){
        module=module/10;
        size++;
    }
    return size;
}

edk::uint32 edk::String::sizeOfInt64(edk::int64 value){
    //use the module of the number
    edk::int64 module = edkModuleInt64(value);

    //count the number
    edk::uint32 size = 0;
    while(module>0){
        module=module/10;
        size++;
    }
    return size;
}

edk::uint32 edk::String::sizeOfFloat32(edk::float32 value){
    //use the module of the number
    edk::float64 module = edkModuleFloat32(value);

    //count the number
    edk::uint32 size = 6u;
    module=module/10.f;
    while(module>0.9999f){
        module=module/10.f;
        size++;
    }
    return size;
}

edk::uint32 edk::String::sizeOfFloat64(edk::float64 value){
    //use the module of the number
    edk::float64 module = edkModuleFloat64(value);

    //count the number
    edk::uint32 size = 6u;
    module=module/10.f;
    while(module>0.9999f){
        module=module/10.f;
        size++;
    }
    return size;
}

edk::char8* edk::String::float32ToStr(edk::float32 value){
    //first divide the value in two. After the point and before the poinf
    edk::int32 before = (edk::int32)value;
    edk::float32 after= edkModuleFloat32(value-(edk::float32)before);
    //string to return
    edk::char8* ret = NULL;
    //transform the before into a string
    edk::char8* afterStr = NULL;
    if(value<0.f){
        afterStr = edk::String::int64ToMinusStr(before);
    }
    else{
        afterStr = edk::String::int64ToStr(before);
    }
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
        beforeStr = (edk::char8*)malloc(sizeof(edk::char8) * (size+2u));
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
            free(afterStr);
            afterStr=NULL;
        }
        //delete the before
        free(beforeStr);
    }
    beforeStr=NULL;

    //return the ret
    return ret;
}

bool edk::String::float32ToStr(edk::float32 value,edk::char8* dest){
    //first divide the value in two. After the point and before the poinf
    edk::int32 before = (edk::int32)value;
    edk::float32 after= edkModuleFloat32(value-(edk::float32)before);
    bool haveTrue = false;
    if(value<0.f){
        haveTrue = edk::String::int32ToMinusStr(before,dest);
    }
    else{
        haveTrue = edk::String::int32ToStr(before,dest);
    }

    if(haveTrue){
        //get the size of the before number
        edk::uint32 size = edk::String::int32ToStrSize(before);
        if(size && after>0.0001f){
            //copy the after
            return edk::String::int32ToStr(before,&dest[size]);
        }
        else if(size){
            dest[size]='\0';
            return true;
        }
        else{
            dest[0u]='0';
            dest[1u]='\0';
            return true;
        }
    }
    return false;
}

edk::char8* edk::String::float32ToStr(edk::float32 value, edk::uint32 digits){
    //first divide the value in two. After the point and before the poinf
    edk::int32 before = (edk::int32)value;
    edk::float32 after= edkModuleFloat32(value-(edk::float32)before);
    //string to return
    edk::char8* ret = NULL;
    //transform the before into a string
    edk::char8* afterStr = NULL;
    if(value<0.f){
        afterStr = edk::String::int64ToMinusStr(before);
    }
    else{
        afterStr = edk::String::int64ToStr(before);
    }
    //now create the string of the after
    edk::char8* beforeStr = NULL;
    if(after>0.0){
        //then create the string

        //forst count the numbers after the point
        edk::uint32 size=digits;
        //create the string
        beforeStr = (edk::char8*)malloc(sizeof(edk::char8) * (size+2u));
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
            free(afterStr);
            afterStr=NULL;
        }
        //delete the before
        free(beforeStr);
    }
    beforeStr=NULL;

    //return the ret
    return ret;
}

bool edk::String::float32ToStr(edk::float32 value,edk::char8* dest,edk::uint32 digits){
    //first divide the value in two. After the point and before the poinf
    edk::int32 before = (edk::int32)value;
    edk::float32 after= edkModuleFloat32(value-(edk::float32)before);
    bool haveTrue = false;
    if(value<0.f){
        haveTrue = edk::String::int32ToMinusStr(before,dest);
    }
    else{
        haveTrue = edk::String::int32ToStr(before,dest);
    }

    if(haveTrue){
        //get the size of the before number
        edk::uint32 size = edk::String::int32ToStrSize(before);
        if(size && after>0.0001f){
            //copy the after
            return edk::String::int32ToStr(before,&dest[size],digits);
        }
        else if(size){
            dest[size]='\0';
            return true;
        }
        else{
            dest[0u]='0';
            dest[1u]='\0';
            return true;
        }
    }
    return false;
}

edk::char8* edk::String::float64ToStr(edk::float64 value, edk::uint32 digits){
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
        beforeStr = (edk::char8*)malloc(sizeof(edk::char8) * (size+2u));
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
            free(afterStr);
            afterStr=NULL;
        }
        //delete the before
        free(beforeStr);
    }
    beforeStr=NULL;

    //return the ret
    return ret;
}

bool edk::String::float64ToStr(edk::float64 value,edk::char8* dest, edk::uint32 digits){
    //first divide the value in two. After the point and before the poinf
    edk::int64 before = (edk::int32)value;
    edk::float64 after= edkModuleFloat32(value-(edk::float64)before);
    bool haveTrue = false;
    if(value<0.f){
        haveTrue = edk::String::int64ToMinusStr(before,dest);
    }
    else{
        haveTrue = edk::String::int64ToStr(before,dest);
    }

    if(haveTrue){
        //get the size of the before number
        edk::uint32 size = edk::String::int64ToStrSize(before);
        if(size && after>0.0001f){
            //copy the after
            return edk::String::int64ToStr(before,&dest[size],digits);
        }
        else if(size){
            dest[size]='\0';
            return true;
        }
        else{
            dest[0u]='0';
            dest[1u]='\0';
            return true;
        }
    }
    return false;
}

edk::char8* edk::String::uint32ToStr(edk::uint32 value){
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
        str = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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
        str = (edk::char8*)malloc(sizeof(edk::char8) * (2u));
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

edk::char8* edk::String::uint32ToStr(edk::uint32 value,edk::uint32 digits){
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
        if(size>digits){
            size=digits;
        }
        //then convert
        module = value;
        //begin
        edk::uint32 begin=0u;
        //Positive
        str = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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
        str = (edk::char8*)malloc(sizeof(edk::char8) * (2u));
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

bool edk::String::uint32ToStr(edk::uint32 value,edk::char8* dest){
    //use the module of the number
    edk::uint32 module = value;

    //count the number
    edk::uint32 size = 0;

    //first calculate the size of the string
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
        //test if alloc the str
        if(dest){
            dest[size]='\0';
            //then convert the number
            for(edk::uint32 j=size;j>begin;j--){
                //
                edk::uint32 i=j-1u;
                //convert in this line
                dest[i]=(module%10)+48;
                module=module/10;
            }
            return true;
        }
    }
    else{
        //create a zero
        if(dest){
            dest[0u]='0';
            dest[1u]='\0';
            return true;
        }
    }
    return false;
}

bool edk::String::uint32ToStr(edk::uint32 value,edk::char8* dest,edk::uint32 digits){

    //use the module of the number
    edk::uint32 module = value;

    //count the number
    edk::uint32 size = 0;

    //first calculate the size of the string
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
        if(size>digits){
            size=digits;
        }
        //then convert
        module = value;
        //begin
        edk::uint32 begin=0u;
        //test if alloc the str
        if(dest){
            dest[size]='\0';
            //then convert the number
            for(edk::uint32 j=size;j>begin;j--){
                //
                edk::uint32 i=j-1u;
                //convert in this line
                dest[i]=(module%10)+48;
                module=module/10;
            }
            return true;
        }
    }
    else{
        //create a zero
        if(dest){
            dest[0u]='0';
            dest[1u]='\0';
            return true;
        }
    }
    return false;
}

edk::char8* edk::String::uint64ToStr(edk::uint64 value){
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
        str = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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
        str = (edk::char8*)malloc(sizeof(edk::char8) * (2u));
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

edk::char8* edk::String::uint64ToStr(edk::uint64 value,edk::uint32 digits){
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
        if(size>digits){
            size=digits;
        }
        //then convert
        module = value;
        //begin
        edk::uint64 begin=0u;
        //Positive
        str = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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
        str = (edk::char8*)malloc(sizeof(edk::char8) * (2u));
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

bool edk::String::uint64ToStr(edk::uint64 value,edk::char8* dest){
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
        if(dest){
            dest[size]='\0';
            //then convert the number
            for(edk::uint64 j=size;j>begin;j--){
                //
                edk::uint64 i=j-1u;
                //convert in this line
                dest[i]=(module%10)+48;
                module=module/10;
            }
            return true;
        }
    }
    else{
        //set a zero
        if(dest){
            dest[0u]='0';
            dest[1u]='\0';
            return true;
        }
    }
    return false;
}

bool edk::String::uint64ToStr(edk::uint64 value,edk::char8* dest,edk::uint32 digits){
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
        if(size>digits){
            size=digits;
        }
        //then convert
        module = value;
        //begin
        edk::uint64 begin=0u;
        //Positive
        if(dest){
            dest[size]='\0';
            //then convert the number
            for(edk::uint64 j=size;j>begin;j--){
                //
                edk::uint64 i=j-1u;
                //convert in this line
                dest[i]=(module%10)+48;
                module=module/10;
            }
            return true;
        }
    }
    else{
        //set a zero
        if(dest){
            dest[0u]='0';
            dest[1u]='\0';
            return true;
        }
    }
    return false;
}

edk::char8* edk::String::strCat(edk::char8 *str1, edk::char8 *str2){
    //first declare a return
    edk::char8* ret=NULL;
    //test if string are alloc
    if(str1&&str2){
        //get the size of the 2 strings
        edk::uint32 size1 = edk::String::strSize(str1),size2 = edk::String::strSize(str2);
        //alloc the new string
        ret = (edk::char8*)malloc(sizeof(edk::char8) * (size1+size2+1u));
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

edk::char8* edk::String::strCat(edk::char8 *str1, const edk::char8 *str2){
    return edk::String::strCat(str1, (edk::char8*) str2);
}

edk::char8* edk::String::strCat(const edk::char8 *str1, edk::char8 *str2){
    return edk::String::strCat((edk::char8*) str1,str2);
}

edk::char8* edk::String::strCat(const edk::char8 *str1, const edk::char8 *str2){
    return edk::String::strCat((edk::char8*)str1,(edk::char8*)str2);
}

edk::char8* edk::String::strCatMulti(edk::char8 *str, ...){
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
            strTemp = va_arg(vl,edk::char8*);
            while(strTemp){
                //save the ret
                temp = ret;
                //cat the temp with the new
                if((ret = edk::String::strCat(temp,strTemp))){
                    //delete temp
                    free(temp);
                }
                else{
                    //else return temp
                    ret = temp;
                    break;
                }
                strTemp = va_arg(vl,edk::char8*);
            }
        }
    }

    //in the end return the return string
    return ret;
}

edk::char8* edk::String::strCatMulti(const edk::char8 *str, ...){
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
            strTemp = va_arg(vl,edk::char8*);
            while(strTemp){
                //save the ret
                temp = ret;
                //cat the temp with the new
                if((ret = edk::String::strCat(temp,strTemp))){
                    //delete temp
                    free(temp);
                }
                else{
                    //else return temp
                    ret = temp;
                    break;
                }
                strTemp = va_arg(vl,edk::char8*);
            }
        }
    }

    //in the end return the return string
    return ret;
}

bool edk::String::strCompare(edk::char8 *str1, edk::char8 *str2){
    //alloc the return
    if(str1 && str2){
        //then he can compare the two strings
        if(*str1 == *str2){
            while (*str1 || *str2){
                str1++;
                str2++;
                if(*str1!=*str2){
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
bool edk::String::strCompare(const edk::char8 *str1, edk::char8 *str2){
    return edk::String::strCompare((edk::char8 *)str1, (edk::char8 *)str2);
}
bool edk::String::strCompare(edk::char8 *str1, const edk::char8 *str2){
    return edk::String::strCompare((edk::char8 *)str1, (edk::char8 *)str2);
}


bool edk::String::strCompare(const edk::char8 *str1, const edk::char8 *str2){
    return edk::String::strCompare((edk::char8*)str1,(edk::char8*)str2);
}

bool edk::String::strCompareInside(edk::char8 *str1, edk::char8 *str2){
    //alloc the return
    if(str1 && str2){
        edk::char8 *str;
        //search the second string inside the first
        while(*str1){
            if(*str1 == *str2){
                str = str2;
                while(*str1 || *str){
                    if(*str1 != *str){
                        break;
                    }
                    str1++;
                    str++;
                }
                if(!*str){
                    return true;
                }
                continue;
            }
            str1++;
        }
    }
    return false;
}

bool edk::String::strCompareInside(const edk::char8 *str1, edk::char8 *str2){
    return edk::String::strCompareInside((edk::char8 *)str1, (edk::char8 *)str2);
}
bool edk::String::strCompareInside(edk::char8 *str1, const edk::char8 *str2){
    return edk::String::strCompareInside((edk::char8 *)str1, (edk::char8 *)str2);
}

bool edk::String::strCompareInside(const edk::char8 *str1, const edk::char8 *str2){
    return edk::String::strCompareInside((edk::char8*)str1,(edk::char8*)str2);
}

bool edk::String::strCompareBeggin(edk::char8 *beggin, edk::char8 *str){
    if(beggin && str){
        while(*beggin && *str){
            if(*beggin!=*str){
                return false;
            }
            beggin++;
            str++;
        }
        if(*beggin=='\0'){
            return true;
        }
    }
    return false;
}
bool edk::String::strCompareBeggin(const edk::char8 *beggin, edk::char8 *str){
    return edk::String::strCompareBeggin((edk::char8 *)beggin, (edk::char8 *)str);
}
bool edk::String::strCompareBeggin(edk::char8 *beggin, const edk::char8 *str){
    return edk::String::strCompareBeggin((edk::char8 *)beggin, (edk::char8 *)str);
}


bool edk::String::strCompareBeggin(const edk::char8 *beggin, const edk::char8 *str){
    return edk::String::strCompareBeggin((edk::char8*)beggin,(edk::char8*)str);
}

bool edk::String::strCompareEnd(edk::char8 *str, edk::char8 *end){
    if(end && str){
        //save the str1
        if(*end){
            edk::char8* save = end;
            //find the str1 inside the str2
            while(*str){
                if(*end==*str){
                    //test the string if are equal
                    while(*end && *str){
                        if(*end!=*str){
                            break;
                        }
                        end++;
                        str++;
                    }
                    //if go out it find the end
                    if(*end=='\0' && *str=='\0'){
                        return true;
                    }
                    else{
                        //else continue searching
                        end = save;
                    }
                }
                else{
                    str++;
                }
            }
        }
    }
    return false;
}
bool edk::String::strCompareEnd(const edk::char8 *str, edk::char8 *end){
    return edk::String::strCompareEnd((edk::char8 *)str, (edk::char8 *)end);
}
bool edk::String::strCompareEnd(edk::char8 *str, const edk::char8 *end){
    return edk::String::strCompareEnd((edk::char8 *)str, (edk::char8 *)end);
}


bool edk::String::strCompareEnd(const edk::char8 *str, const edk::char8 *end){
    return edk::String::strCompareEnd((edk::char8*)str,(edk::char8*)end);
}

//Compare string removing some characters with filter
bool edk::String::strCompareWithFilter(edk::char8 *str1, edk::char8 *str2,edk::char8 *filter){
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
                        if(isEqual){
                            str1++;
                        }
                        else{
                            break;
                        }
                    }
                    while(*str2){
                        isEqual = false;
                        for(edk::uint32 i=0u;i<size;i++){
                            if(*str2 == filter[i]){
                                isEqual = true;
                                break;
                            }
                        }
                        if(isEqual){
                            str2++;
                        }
                        else{
                            break;
                        }
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
                                if(isEqual){
                                    str1++;
                                }
                                else{
                                    break;
                                }
                            }
                            while(*str2){
                                isEqual = false;
                                for(edk::uint32 i=0u;i<size;i++){
                                    if(*str2 == filter[i]){
                                        isEqual = true;
                                        break;
                                    }
                                }
                                if(isEqual){
                                    str2++;
                                }
                                else{
                                    break;
                                }
                            }
                            //test if is not equal
                            if(*str1!=*str2){
                                //
                                return false;
                            }
                        }while(*str1 && *str2);
                    }
                    if(*str1 == *str2){
                        return true;
                    }
                }
            }
            return false;
        }
    }
    //else test normalCompare
    return edk::String::strCompare(str1,str2);
}
bool edk::String::strCompareWithFilter(edk::char8 *str1, edk::char8 *str2,const edk::char8 *filter){
    return edk::String::strCompareWithFilter(str1, str2,(edk::char8 *)filter);
}
bool edk::String::strCompareWithFilter(const edk::char8 *str1, const edk::char8 *str2,const edk::char8 *filter){
    return edk::String::strCompareWithFilter((edk::char8 *)str1, (edk::char8 *)str2,(edk::char8 *)filter);
}
bool edk::String::strCompareWithFilter(const edk::char8 *str1, const edk::char8 *str2,edk::char8 *filter){
    return edk::String::strCompareWithFilter((edk::char8 *)str1, (edk::char8 *)str2,filter);
}
bool edk::String::strCompareWithFilter(edk::char8 *str1, const edk::char8 *str2,const edk::char8 *filter){
    return edk::String::strCompareWithFilter(str1, (edk::char8 *)str2,(edk::char8 *)filter);
}
bool edk::String::strCompareWithFilter(edk::char8 *str1, const edk::char8 *str2,edk::char8 *filter){
    return edk::String::strCompareWithFilter(str1, (edk::char8 *)str2,filter);
}
bool edk::String::strCompareWithFilter(const edk::char8 *str1, edk::char8 *str2,const edk::char8 *filter){
    return edk::String::strCompareWithFilter((edk::char8 *)str1, str2,(edk::char8 *)filter);
}
bool edk::String::strCompareWithFilter(const edk::char8 *str1, edk::char8 *str2,edk::char8 *filter){
    return edk::String::strCompareWithFilter((edk::char8 *)str1, str2,filter);
}

//return true if a string is inside the other string
edk::char8* edk::String::strInside(edk::char8 *str, edk::char8 *compare){
    edk::char8* temp = NULL;
    if(str && compare){
        while(*str){
            //test if are equal
            if(*str == *compare){
                temp = compare;
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
                    return str;
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
edk::char8* edk::String::strInside(const edk::char8 *str, edk::char8 *compare){
    return edk::String::strInside((edk::char8 *)str, compare);
}
edk::char8* edk::String::strInside(edk::char8 *str, const edk::char8 *compare){
    return edk::String::strInside(str, (edk::char8 *)compare);
}
edk::char8* edk::String::strInside(const edk::char8 *str, const edk::char8 *compare){
    return edk::String::strInside((edk::char8 *)str, (edk::char8 *)compare);
}
edk::char8* edk::String::strHaveInside(edk::char8 *str, edk::char8 *compare){
    return edk::String::strInside(str, compare);
}
edk::char8* edk::String::strHaveInside(const edk::char8 *str, edk::char8 *compare){
    return edk::String::strInside((edk::char8 *)str, compare);
}
edk::char8* edk::String::strHaveInside(edk::char8 *str, const edk::char8 *compare){
    return edk::String::strInside(str, (edk::char8 *)compare);
}
edk::char8* edk::String::strHaveInside(const edk::char8 *str, const edk::char8 *compare){
    return edk::String::strInside((edk::char8 *)str, (edk::char8 *)compare);
}

edk::char8* edk::String::strInsideBeggin(edk::char8 *str, edk::char8 *compare){
    edk::char8* temp = NULL;
    if(str && compare){
        while(*str){
            //test if are equal
            if(*str == *compare){
                temp = compare;
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
                    return str;
                }
                if(!*str){
                    //then return NULL;
                    return NULL;
                }
            }

            break;
        }
    }
    return NULL;
}
edk::char8* edk::String::strInsideBeggin(const edk::char8 *str, edk::char8 *compare){
    return edk::String::strInsideBeggin((edk::char8 *)str, compare);
}
edk::char8* edk::String::strInsideBeggin(edk::char8 *str, const edk::char8 *compare){
    return edk::String::strInsideBeggin(str, (edk::char8 *)compare);
}
edk::char8* edk::String::strInsideBeggin(const edk::char8 *str, const edk::char8 *compare){
    return edk::String::strInsideBeggin((edk::char8 *)str, (edk::char8 *)compare);
}
edk::char8* edk::String::strHaveInsideBeggin(edk::char8 *str, edk::char8 *compare){
    return edk::String::strInsideBeggin(str, compare);
}
edk::char8* edk::String::strHaveInsideBeggin(const edk::char8 *str, edk::char8 *compare){
    return edk::String::strInsideBeggin((edk::char8 *)str, compare);
}
edk::char8* edk::String::strHaveInsideBeggin(edk::char8 *str, const edk::char8 *compare){
    return edk::String::strInsideBeggin(str, (edk::char8 *)compare);
}
edk::char8* edk::String::strHaveInsideBeggin(const edk::char8 *str, const edk::char8 *compare){
    return edk::String::strInsideBeggin((edk::char8 *)str, (edk::char8 *)compare);
}

edk::char8* edk::String::strInsideEnd(edk::char8 *str, edk::char8 *compare){
    if(str && compare){
        edk::uint32 size = edk::String::strSize(str);
        edk::uint32 sizeCompare = edk::String::strSize(compare);
        if(size>1u && sizeCompare>1u){
            if(size>=sizeCompare){
                //test the str with the compare
                edk::char8* temp = &str[size-sizeCompare];
                edk::char8* tempCompare = temp;
                for(edk::uint32 i=0u;i<sizeCompare;i++){
                    //compare if are different
                    if(*compare != *tempCompare){
                        return NULL;
                    }
                    compare++;
                    tempCompare++;
                }
                //return the temp
                return temp;
            }
        }
    }
    return NULL;
}
edk::char8* edk::String::strInsideEnd(const edk::char8 *str, edk::char8 *compare){
    return edk::String::strInsideEnd((edk::char8 *)str, compare);
}
edk::char8* edk::String::strInsideEnd(edk::char8 *str, const edk::char8 *compare){
    return edk::String::strInsideEnd(str, (edk::char8 *)compare);
}
edk::char8* edk::String::strInsideEnd(const edk::char8 *str, const edk::char8 *compare){
    return edk::String::strInsideEnd((edk::char8 *)str, (edk::char8 *)compare);
}
edk::char8* edk::String::strHaveInsideEnd(edk::char8 *str, edk::char8 *compare){
    return edk::String::strInsideEnd(str, compare);
}
edk::char8* edk::String::strHaveInsideEnd(const edk::char8 *str, edk::char8 *compare){
    return edk::String::strInsideEnd((edk::char8 *)str, compare);
}
edk::char8* edk::String::strHaveInsideEnd(edk::char8 *str, const edk::char8 *compare){
    return edk::String::strHaveInsideEnd(str, (edk::char8 *)compare);
}
edk::char8* edk::String::strHaveInsideEnd(const edk::char8 *str, const edk::char8 *compare){
    return edk::String::strHaveInsideEnd((edk::char8 *)str, (edk::char8 *)compare);
}

//return true if the first string is bigger than the second string
bool edk::String::strBiggerStr(edk::char8 *str1, edk::char8 *str2){
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
bool edk::String::strBiggerStr(const edk::char8 *str1, edk::char8 *str2){
    return edk::String::strBiggerStr((edk::char8 *)str1, str2);
}
bool edk::String::strBiggerStr(edk::char8 *str1, const edk::char8 *str2){
    return edk::String::strBiggerStr(str1, (edk::char8 *)str2);
}
bool edk::String::strBiggerStr(const edk::char8 *str1, const edk::char8 *str2){
    return edk::String::strBiggerStr((edk::char8 *)str1, (edk::char8 *)str2);
}

//JUMP
edk::char8* edk::String::strJumpTo(edk::char8* str,edk::char8* filter){
    if(str && filter){
        edk::uint32 size = edk::String::strSize(filter);
        if(size){
            while(*str){
                for(edk::uint32 i=0u;i<size;i++){
                    if(*str == filter[i]){
                        str++;
                        return str;
                    }
                }
                str++;
            }
        }
    }
    return NULL;
}
edk::char8* edk::String::strJumpTo(const edk::char8* str,edk::char8* filter){
    return edk::String::strJumpTo((edk::char8*) str,filter);
}
edk::char8* edk::String::strJumpTo(edk::char8* str,const edk::char8* filter){
    return edk::String::strJumpTo(str,(edk::char8*) filter);
}
edk::char8* edk::String::strJumpTo(const edk::char8* str,const edk::char8* filter){
    return edk::String::strJumpTo((edk::char8*) str,(edk::char8*) filter);
}
edk::char8* edk::String::strJumpToEndLine(edk::char8* str){
    return edk::String::strJumpTo(str,"\n\10\13");
}
edk::char8* edk::String::strJumpToEndLine(const edk::char8* str){
    return edk::String::strJumpTo((edk::char8*) str,"\n\10\13");
}

edk::uint64 edk::String::strSize(edk::char8 *str){
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

edk::uint64 edk::String::strSize(const edk::char8 *str){
    return edk::String::strSize((edk::char8*)str);
}

edk::uint64 edk::String::strSizeWithBackslashSpace(edk::char8 *str){
    edk::uint64 ret=0u;
    bool backslash=false;
    if(str){
        while(*str){
            //test if it's a space
            if(*str==' '){
                //test if don't have a backslash
                if(!backslash){
                    //increment the ret
                    ret++;
                }
            }
            //test if it's a backslash
            if(*str=='\\'){
                backslash=true;
            }
            else{
                backslash=false;
            }
            //increment i to continue the counting
            ret++;
            str++;
        }
    }
    return ret;
}

edk::uint64 edk::String::strSizeWithBackslashSpace(const edk::char8 *str){
    return edk::String::strSizeWithBackslashSpace((edk::char8 *)str);
}

edk::uint64 edk::String::strSizeWithFilter(edk::char8 *str,edk::char8* filter){
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
                    if(!haveFilter){
                        //increment i to continue the counting
                        i++;
                    }
                    str++;
                }
            }
        }
        else{
            return edk::String::strSize(str);
        }
    }
    else{
        return edk::String::strSize(str);
    }
    return i;
}
edk::uint64 edk::String::strSizeWithFilter(edk::char8 *str,const char *filter){
    return strSizeWithFilter(str,(edk::char8*) filter);
}
edk::uint64 edk::String::strSizeWithFilter(const edk::char8 *str,edk::char8* filter){
    return strSizeWithFilter((edk::char8 *)str,filter);
}
edk::uint64 edk::String::strSizeWithFilter(const edk::char8 *str,const edk::char8 *filter){
    return strSizeWithFilter((edk::char8 *)str,(edk::char8*) filter);
}

edk::uint64 edk::String::strSizeWithLimit(edk::char8 *str,edk::char8* limit){
    edk::uint64 i=0u;

    if(limit){
        edk::char8* temp = limit;
        while(*str){
            temp = limit;
            while(temp){
                if(*str == *temp){
                    break;
                }
                temp++;
            }
            str++;
            i++;
        }
    }
    else{
        return edk::String::strSize(str);
    }

    return i;
}
edk::uint64 edk::String::strSizeWithLimit(edk::char8 *str,const edk::char8 *limit){
    return strSizeWithLimit(str,(edk::char8*) limit);
}
edk::uint64 edk::String::strSizeWithLimit(const edk::char8 *str,edk::char8* limit){
    return strSizeWithLimit((edk::char8 *)str,limit);
}
edk::uint64 edk::String::strSizeWithLimit(const edk::char8 *str,const edk::char8 *limit){
    return strSizeWithLimit((edk::char8 *)str,(edk::char8*) limit);
}

edk::uint64 edk::String::strWordSize(edk::char8 *str){
    edk::uint64 ret=0u;
    if(str){
        while(*str){
            //test if have reach the end of the word
            if(*str=='\0' || *str==' ' || *str==9u || *str == 10u){
                break;
            }
            //increment i to continue the counting
            ret++;
            str++;
        }
    }
    return ret;
}

edk::uint64 edk::String::strWordSize(const edk::char8 *str){
    return edk::String::strWordSize((edk::char8*)str);
}

edk::uint64 edk::String::strWordSizeWithFilter(edk::char8 *str,edk::char8* filter){
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
                    if(*str=='\0' || *str==' ' || *str==9u || *str == 10u){
                        //then find the end of the string
                        break;
                    }
                    if(!haveFilter){
                        //increment i to continue the counting
                        i++;
                    }
                    str++;
                }
            }
        }
        else{
            return edk::String::strWordSize(str);
        }
    }
    else{
        return edk::String::strWordSize(str);
    }
    return i;
}
edk::uint64 edk::String::strWordSizeWithFilter(edk::char8 *str,const edk::char8 *filter){
    return strWordSizeWithFilter(str,(edk::char8*) filter);
}
edk::uint64 edk::String::strWordSizeWithFilter(const edk::char8 *str,edk::char8* filter){
    return strWordSizeWithFilter((char8 *)str,filter);
}
edk::uint64 edk::String::strWordSizeWithFilter(const edk::char8 *str,const edk::char8 *filter){
    return strWordSizeWithFilter((char8 *)str,(edk::char8*) filter);
}

edk::uint64 edk::String::strLineSize(edk::char8 *str){
    edk::uint64 ret=0u;
    if(str){
        while(*str){
            //test if have reach the end of the word
            if(*str=='\0' || *str == 10u){
                break;
            }
            //increment i to continue the counting
            ret++;
            str++;
        }
    }
    return ret;
}

edk::uint64 edk::String::strLineSize(const edk::char8 *str){
    return edk::String::strWordSize((edk::char8*)str);
}

edk::uint64 edk::String::strLineSizeWithFilter(edk::char8 *str,edk::char8* filter){
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
                    if(*str=='\0' || *str == 10u){
                        //then find the end of the string
                        break;
                    }
                    if(!haveFilter){
                        //increment i to continue the counting
                        i++;
                    }
                    str++;
                }
            }
        }
        else{
            return edk::String::strWordSize(str);
        }
    }
    else{
        return edk::String::strWordSize(str);
    }
    return i;
}
edk::uint64 edk::String::strLineSizeWithFilter(edk::char8 *str,const edk::char8 *filter){
    return strLineSizeWithFilter(str,(edk::char8*) filter);
}
edk::uint64 edk::String::strLineSizeWithFilter(const edk::char8 *str,edk::char8* filter){
    return strLineSizeWithFilter((edk::char8 *)str,filter);
}
edk::uint64 edk::String::strLineSizeWithFilter(const edk::char8 *str,const edk::char8 *filter){
    return strLineSizeWithFilter((edk::char8 *)str,(edk::char8*) filter);
}

bool edk::String::strCut(edk::char8 *str,edk::char8 *dest, edk::char8 limit, bool use){
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

bool edk::String::strCut(const edk::char8 *str,edk::char8 *dest, edk::char8 limit, bool use){
    return edk::String::strCut((edk::char8 *)str,dest, limit, use);
}

edk::char8* edk::String::strCut(edk::char8 *str, edk::char8 limit, bool use){
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
                    ret = (edk::char8*)malloc(sizeof(edk::char8) * (size+2u));
                    //incremente the size
                    size++;
                }
                else{
                    //
                    ret = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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

edk::char8* edk::String::strCut(const edk::char8 *str, edk::char8 limit, bool use){
    return edk::String::strCut((edk::char8 *)str, limit, use);
}

bool edk::String::strCut(edk::char8 limit, edk::char8 *str, edk::char8 *dest, bool use){
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

bool edk::String::strCut(edk::char8 limit, const edk::char8 *str, edk::char8 *dest, bool use){
    return edk::String::strCut(limit, (edk::char8 *)str, dest, use);
}

edk::char8* edk::String::strCut(edk::char8 limit, edk::char8 *str, bool use){
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

edk::char8* edk::String::strCut(edk::char8 limit, const edk::char8 *str, bool use){
    return edk::String::strCut(limit, (edk::char8 *)str, use);
}

bool edk::String::strCut(edk::char8 *str,edk::char8 *dest, edk::char8 start, edk::char8 end, bool use){
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

bool edk::String::strCut(const edk::char8 *str,edk::char8 *dest, edk::char8 start, edk::char8 end, bool use){
    return edk::String::strCut((edk::char8 *)str,dest, start, end, use);
}

edk::char8* edk::String::strCut(edk::char8 *str, edk::char8 start, edk::char8 end, bool use){
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
                                edk::char8* ret = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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

edk::char8* edk::String::strCut(const edk::char8 *str, edk::char8 start, edk::char8 end, bool use){
    return edk::String::strCut((edk::char8 *)str, start, end, use);
}

bool edk::String::strInvert(edk::char8 *str){
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

bool edk::String::strInvert(const edk::char8 *str){
    return edk::String::strInvert((edk::char8*)str);
}

edk::uint64 edk::String::stringHaveChar(edk::char8 *str,edk::char8 value){
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

edk::uint64 edk::String::stringHaveChar(const edk::char8 *str,edk::char8 value){
    return edk::String::stringHaveChar((edk::char8 *)str,value);
}

edk::uint64 edk::String::stringHaveChar(edk::char8 *str,edk::uint64 size,edk::char8 value){
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
edk::uint64 edk::String::stringHaveChar(const edk::char8 *str,edk::uint64 size,edk::char8 value){
    return edk::String::stringHaveChar((edk::char8 *)str,size,value);
}

bool edk::String::consoleKeyPressed(){
    return edk::ConsoleTerminal::keyPressed();
}

edk::char8 edk::String::consoleReadKey(){
    return edk::ConsoleTerminal::readKey();
}

edk::char8* edk::String::consoleReadString(){
    return edk::ConsoleTerminal::readString();
}

edk::char8* edk::String::consoleReadStringNoPrint(){
    return edk::ConsoleTerminal::readStringNoPrint();
}

edk::char8* edk::String::consoleReadPassword(){
    return edk::ConsoleTerminal::readPassword();
}

void edk::String::consoleClear(){
    edk::ConsoleTerminal::clear();
}

//return the console size
edk::size2ui32 edk::String::consoleGetSize(){
    return edk::ConsoleTerminal::getSize();
}

edk::char8* edk::String::strCopy(edk::char8 *str){
    edk::char8* strRet=NULL;

    //count the string
    edk::uint32 size = edk::String::strSize(str);
    if(size>0u){
        //alloc the string
        strRet = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
        //test if alloc de string
        if(strRet){
            strRet[size]='\0';
            //copy the string
            memcpy(strRet,str,size);
        }
        else{
            //
            strRet=0u;
        }
    }
    return strRet;
}

edk::char8* edk::String::strCopy(const edk::char8 *str){
    return edk::String::strCopy((edk::char8*)str);
}

edk::char8* edk::String::strCopyLine(edk::char8 *str){
    edk::char8* strRet=NULL;

    //count the string
    edk::uint32 size = edk::String::strLineSize(str);
    if(size>0u){
        //alloc the string
        strRet = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
        //test if alloc de string
        if(strRet){
            strRet[size]='\0';
            //copy the string
            memcpy(strRet,str,size);
        }
        else{
            //
            strRet=0u;
        }
    }
    return strRet;
}

edk::char8* edk::String::strCopyLine(const edk::char8 *str){
    return edk::String::strCopyLine((edk::char8*)str);
}

edk::char8* edk::String::strCopyWord(edk::char8 *str){
    edk::char8* strRet=NULL;

    //count the string
    edk::uint32 size = edk::String::strWordSize(str);
    if(size>0u){
        //alloc the string
        strRet = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
        //test if alloc de string
        if(strRet){
            strRet[size]='\0';
            //copy the string
            memcpy(strRet,str,size);
        }
        else{
            //
            strRet=0u;
        }
    }
    return strRet;
}

edk::char8* edk::String::strCopyWord(const edk::char8 *str){
    return edk::String::strCopyWord((edk::char8*)str);
}

edk::char8* edk::String::strCopyWithBackslashSpace(edk::char8 *str){
    edk::char8* strRet=NULL;

    //count the string
    edk::uint32 size = edk::String::strSizeWithBackslashSpace(str);
    if(size>0u){
        //alloc the string
        strRet = (edk::char8*)malloc(sizeof(edk::char8)*size+1u);
        //test if alloc de string
        if(strRet){
            strRet[size]='\0';

            //copy the characters
            edk::char8* strTemp=strRet;
            while(*str){
                //test if 's a space
                if(*str==' '){
                    //add a backslash
                    *strTemp='\\';
                    strTemp++;
                }
                //copy the character
                *strTemp=*str;

                str++;
                strTemp++;
            }
        }
        else{
            //
            strRet=0u;
        }
    }
    return strRet;
}

edk::char8* edk::String::strCopyWithBackslashSpace(const edk::char8 *str){
    return edk::String::strCopyWithBackslashSpace((edk::char8*)str);
}

//remove a filter from string
edk::char8* edk::String::strCopyWithFilter(edk::char8 *str,edk::char8 *filter){
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
                    strRet = (edk::char8*)malloc(sizeof(edk::char8) * (sizeWith+1u));
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
        else{
            return edk::String::strCopy(str);
        }
    }
    else{
        return edk::String::strCopy(str);
    }
    return strRet;
}
edk::char8* edk::String::strCopyWithFilter(const edk::char8 *str,edk::char8 *filter){
    return strCopyWithFilter((edk::char8 *)str,filter);
}
edk::char8* edk::String::strCopyWithFilter(char8 *str,const edk::char8 *filter){
    return strCopyWithFilter(str,(edk::char8 *)filter);
}
edk::char8* edk::String::strCopyWithFilter(const edk::char8 *str,const edk::char8 *filter){
    return strCopyWithFilter((edk::char8 *)str,(edk::char8 *)filter);
}

edk::char8* edk::String::clipboardRead(){
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

bool edk::String::clipboardWrite(edk::char8 *str){
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
        free(temp);
    }

    //retorna o resultado
    return ret;
}

bool edk::String::clipboardWrite(const edk::char8 *str){
    return edk::String::clipboardWrite((edk::char8*)str);
}

bool edk::String::clipboardClean(){
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
edk::char8 edk::String::filterAccent(const edk::char8* str){
    return edk::String::filterAccent((edk::char8*) str);
}
edk::char8 edk::String::filterAccent(edk::char8* str){
    //
    if(str){
        if((edk::uint8)*str==195u){
            str++;
            switch((edk::uint8)*str){
            case 128u:
                //printf("\nCrase A");
                return ((edk::uchar8)*str) + 64u;
            case 129u:
                //printf("\nAcento A");
                return ((edk::uchar8)*str) + 64u;
            case 130u:
                //printf("\nChapeu A");
                return ((edk::uchar8)*str) + 64u;
            case 131u:
                //printf("\nTio A");
                return ((edk::uchar8)*str) + 64u;
            case 132u:
                //printf("\nTrema A");
                return ((edk::uchar8)*str) + 64u;
            case 135u:
                //printf("\nCedilha Maiusculo");
                return ((edk::uchar8)*str) + 64u;
            case 136u:
                //printf("\nCrase E");
                return ((edk::uchar8)*str) + 64u;
            case 137u:
                //printf("\nAcento E");
                return ((edk::uchar8)*str) + 64u;
            case 138u:
                //printf("\nChapeu E");
                return ((edk::uchar8)*str) + 64u;
            case 139u:
                //printf("\nTrema E");
                return ((edk::uchar8)*str) + 64u;
            case 140u:
                //printf("\nCrase I");
                return ((edk::uchar8)*str) + 64u;
            case 141u:
                //printf("\nAcento I");
                return ((edk::uchar8)*str) + 64u;
            case 142u:
                //printf("\nChapeu I");
                return ((edk::uchar8)*str) + 64u;
            case 143u:
                //printf("\nTrema I");
                return ((edk::uchar8)*str) + 64u;
            case 145u:
                //printf("\nTio N");
                return ((edk::uchar8)*str) + 64u;
            case 146u:
                //printf("\nCrase O");
                return ((edk::uchar8)*str) + 64u;
            case 147u:
                //printf("\nAcento O");
                return ((edk::uchar8)*str) + 64u;
            case 148u:
                //printf("\nChapeu O");
                return ((edk::uchar8)*str) + 64u;
            case 149u:
                //printf("\nTio O");
                return ((edk::uchar8)*str) + 64u;
            case 150u:
                //printf("\nTrema O");
                return ((edk::uchar8)*str) + 64u;
            case 153u:
                //printf("\nCrase U");
                return ((edk::uchar8)*str) + 64u;
            case 154u:
                //printf("\nAcento U");
                return ((edk::uchar8)*str) + 64u;
            case 155u:
                //printf("\nChapeu U");
                return ((edk::uchar8)*str) + 64u;
            case 156u:
                //printf("\nTrema U");
                return ((edk::uchar8)*str) + 64u;
            case 157u:
                //printf("\nAcento Y");
                return ((edk::uchar8)*str) + 64u;
            case 160u:
                //printf("\nCrase a");
                return ((edk::uchar8)*str) + 64u;
            case 161u:
                //printf("\nAcento a");
                return ((edk::uchar8)*str) + 64u;
            case 162u:
                //printf("\nChapeu a");
                return ((edk::uchar8)*str) + 64u;
            case 163u:
                //printf("\nTio a");
                return ((edk::uchar8)*str) + 64u;
            case 164u:
                //printf("\nTrema a");
                return ((edk::uchar8)*str) + 64u;
            case 167u:
                //printf("\nCedilha Minusculo");
                return ((edk::uchar8)*str) + 64u;
            case 168u:
                //printf("\nCrase e");
                return ((edk::uchar8)*str) + 64u;
            case 169u:
                //printf("\nAcento e");
                return ((edk::uchar8)*str) + 64u;
            case 170u:
                //printf("\nChapeu e");
                return ((edk::uchar8)*str) + 64u;
            case 171u:
                //printf("\nTrema e");
                return ((edk::uchar8)*str) + 64u;
            case 172u:
                //printf("\nCrase i");
                return ((edk::uchar8)*str) + 64u;
            case 173u:
                //printf("\nAcento i");
                return ((edk::uchar8)*str) + 64u;
            case 174u:
                //printf("\nChapeu i");
                return ((edk::uchar8)*str) + 64u;
            case 175u:
                //printf("\ntrema i");
                return ((edk::uchar8)*str) + 64u;
            case 177u:
                //printf("\nTio n");
                return ((edk::uchar8)*str) + 64u;
            case 178u:
                //printf("\nCrase o");
                return ((edk::uchar8)*str) + 64u;
            case 179u:
                //printf("\nAcento o");
                return ((edk::uchar8)*str) + 64u;
            case 180u:
                //printf("\nChapeu o");
                return ((edk::uchar8)*str) + 64u;
            case 181u:
                //printf("\nTio o");
                return ((edk::uchar8)*str) + 64u;
            case 182u:
                //printf("\nTrema o");
                return ((edk::uchar8)*str) + 64u;
            case 185u:
                //printf("\nCrase u");
                return ((edk::uchar8)*str) + 64u;
            case 186u:
                //printf("\nAcento u");
                return ((edk::uchar8)*str) + 64u;
            case 187u:
                //printf("\nChapeu u");
                return ((edk::uchar8)*str) + 64u;
            case 188u:
                //printf("\nTrema u");
                return ((edk::uchar8)*str) + 64u;
            case 189u:
                //printf("\nAcento y");
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
        else if((edk::uint8)*str==226u){
            str++;
            if((edk::uint8)*str==128u){
                str++;
                if((edk::uint8)*str==148u){
                    //printf("\n");
                    return 45u;
                }
                else if((edk::uint8)*str==152u){
                    //printf("\nAbrir aspas simples");
                    return '\'';
                }
                else if((edk::uint8)*str==153u){
                    //printf("\nFechar aspas simples");
                    return '\'';
                }
                else if((edk::uint8)*str==156u){
                    //printf("\nAbrir aspas");
                    return '\"';
                }
                else if((edk::uint8)*str==157u){
                    //printf("\nFechar aspas");
                    return '\"';
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
                //printf("\nCrase A");
                return ((edk::uchar8)*str) + 64u;
            case 129u:
                //printf("\nAcento A");
                return ((edk::uchar8)*str) + 64u;
            case 130u:
                //printf("\nChapeu A");
                return ((edk::uchar8)*str) + 64u;
            case 131u:
                //printf("\nTio A");
                return ((edk::uchar8)*str) + 64u;
            case 132u:
                //printf("\nTrema A");
                return ((edk::uchar8)*str) + 64u;
            case 135u:
                //printf("\nCedilha Maiusculo");
                return ((edk::uchar8)*str) + 64u;
            case 136u:
                //printf("\nCrase E");
                return ((edk::uchar8)*str) + 64u;
            case 137u:
                //printf("\nAcento E");
                return ((edk::uchar8)*str) + 64u;
            case 138u:
                //printf("\nChapeu E");
                return ((edk::uchar8)*str) + 64u;
            case 139u:
                //printf("\nTrema E");
                return ((edk::uchar8)*str) + 64u;
            case 140u:
                //printf("\nCrase I");
                return ((edk::uchar8)*str) + 64u;
            case 141u:
                //printf("\nAcento I");
                return ((edk::uchar8)*str) + 64u;
            case 142u:
                //printf("\nChapeu I");
                return ((edk::uchar8)*str) + 64u;
            case 143u:
                //printf("\nTrema I");
                return ((edk::uchar8)*str) + 64u;
            case 145u:
                //printf("\nTio N");
                return ((edk::uchar8)*str) + 64u;
            case 146u:
                //printf("\nCrase O");
                return ((edk::uchar8)*str) + 64u;
            case 147u:
                //printf("\nAcento O");
                return ((edk::uchar8)*str) + 64u;
            case 148u:
                //printf("\nChapeu O");
                return ((edk::uchar8)*str) + 64u;
            case 149u:
                //printf("\nTio O");
                return ((edk::uchar8)*str) + 64u;
            case 150u:
                //printf("\nTrema O");
                return ((edk::uchar8)*str) + 64u;
            case 153u:
                //printf("\nCrase U");
                return ((edk::uchar8)*str) + 64u;
            case 154u:
                //printf("\nAcento U");
                return ((edk::uchar8)*str) + 64u;
            case 155u:
                //printf("\nChapeu U");
                return ((edk::uchar8)*str) + 64u;
            case 156u:
                //printf("\nTrema U");
                return ((edk::uchar8)*str) + 64u;
            case 157u:
                //printf("\nAcento Y");
                return ((edk::uchar8)*str) + 64u;
            case 160u:
                //printf("\nCrase a");
                return ((edk::uchar8)*str) + 64u;
            case 161u:
                //printf("\nAcento a");
                return ((edk::uchar8)*str) + 64u;
            case 162u:
                //printf("\nChapeu a");
                return ((edk::uchar8)*str) + 64u;
            case 163u:
                //printf("\nTio a");
                return ((edk::uchar8)*str) + 64u;
            case 164u:
                //printf("\nTrema a");
                return ((edk::uchar8)*str) + 64u;
            case 167u:
                //printf("\nCedilha Minusculo");
                return ((edk::uchar8)*str) + 64u;
            case 168u:
                //printf("\nCrase e");
                return ((edk::uchar8)*str) + 64u;
            case 169u:
                //printf("\nAcento e");
                return ((edk::uchar8)*str) + 64u;
            case 170u:
                //printf("\nChapeu e");
                return ((edk::uchar8)*str) + 64u;
            case 171u:
                //printf("\nTrema e");
                return ((edk::uchar8)*str) + 64u;
            case 172u:
                //printf("\nCrase i");
                return ((edk::uchar8)*str) + 64u;
            case 173u:
                //printf("\nAcento i");
                return ((edk::uchar8)*str) + 64u;
            case 174u:
                //printf("\nChapeu i");
                return ((edk::uchar8)*str) + 64u;
            case 175u:
                //printf("\ntrema i");
                return ((edk::uchar8)*str) + 64u;
            case 177u:
                //printf("\nTio n");
                return ((edk::uchar8)*str) + 64u;
            case 178u:
                //printf("\nCrase o");
                return ((edk::uchar8)*str) + 64u;
            case 179u:
                //printf("\nAcento o");
                return ((edk::uchar8)*str) + 64u;
            case 180u:
                //printf("\nChapeu o");
                return ((edk::uchar8)*str) + 64u;
            case 181u:
                //printf("\nTio o");
                return ((edk::uchar8)*str) + 64u;
            case 182u:
                //printf("\nTrema o");
                return ((edk::uchar8)*str) + 64u;
            case 185u:
                //printf("\nCrase u");
                return ((edk::uchar8)*str) + 64u;
            case 186u:
                //printf("\nAcento u");
                return ((edk::uchar8)*str) + 64u;
            case 187u:
                //printf("\nChapeu u");
                return ((edk::uchar8)*str) + 64u;
            case 188u:
                //printf("\nTrema u");
                return ((edk::uchar8)*str) + 64u;
            case 189u:
                //printf("\nAcento y");
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
        else if((edk::uint8)*str==226u){
            *jump+=1u;
            str++;
            if((edk::uint8)*str==128u){
                *jump+=1u;
                str++;
                if((edk::uint8)*str==148u){
                    //printf("\n");
                    return 45u;
                }
                else if((edk::uint8)*str==152u){
                    //printf("\nAbrir aspas simples");
                    return '\'';
                }
                else if((edk::uint8)*str==153u){
                    //printf("\nFechar aspas simples");
                    return '\'';
                }
                else if((edk::uint8)*str==156u){
                    //printf("\nAbrir aspas");
                    return '\"';
                }
                else if((edk::uint8)*str==157u){
                    //printf("\nFechar aspas");
                    return '\"';
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
            edk::char8* ret = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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
            if(size){
                size--;
            }
        }
        if(size){
            //create a new string with the size
            ret = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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
        if(*temp!='/' || *temp!='\\'){
            temp++;
        }
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
//return the folder name from a string
edk::char8* edk::String::strFolderName(edk::char8* str){
    edk::char8* ret = NULL;
    if(str){
        edk::uint32 i=0u;
        edk::uint32 lastFolder=0u;
        bool haveLast=false;
        //create a pointer to read the string
        edk::char8* temp = str;
        //go to the last '/' or '\\'
        while(*temp){
            if(*temp=='/' || *temp=='\\'){
                //find a folder
                lastFolder = i;
                haveLast=true;
            }
            temp++;
            i++;
        }

        //test if have the last folder
        if(lastFolder){
            lastFolder++;
            //create a new string with the size of the last folder
            ret = (edk::char8*)malloc(sizeof(edk::char8) * (lastFolder+1u));
            if(ret){
                ret[lastFolder]='\0';
                for(edk::uint32 j=0u;j<lastFolder;j++){
                    ret[j]=str[j];
                }
            }
        }
        else{
            if(haveLast){
                //create a new string for use "./"
                ret = (edk::char8*)malloc(sizeof(edk::char8) * (2u));
                if(ret){
                    ret[0u]='/';
                    ret[1u]='\0';
                }
            }
            else{
                //create a new string for use "./"
                ret = (edk::char8*)malloc(sizeof(edk::char8) * (3u));
                if(ret){
                    ret[0u]='.';
                    ret[1u]='/';
                    ret[2u]='\0';
                }
            }
        }
    }
    return ret;
}
edk::char8* edk::String::strFolderName(const edk::char8* str){
    return edk::String::strFolderName((edk::char8*) str);
}
bool edk::String::strFolderName(edk::char8* str,edk::char8* dest){
    if(str && dest){
        edk::uint32 i=0u;
        edk::uint32 lastFolder=0u;
        bool haveLast=false;
        //create a pointer to read the string
        edk::char8* temp = str;
        //go to the last '/' or '\\'
        while(*temp){
            if(*temp=='/' || *temp=='\\'){
                //find a folder
                lastFolder = i;
                haveLast=true;
            }
            temp++;
            i++;
        }

        //test if have the last folder
        if(lastFolder){
            lastFolder++;
            //create a new string with the size of the last folder
            dest[lastFolder]='\0';
            for(edk::uint32 j=0u;j<lastFolder;j++){
                dest[j]=str[j];
            }
            return true;
        }
        else{
            if(haveLast){
                //create a new string for use "./"
                dest[0u]='/';
                dest[1u]='\0';
                return true;
            }
            else{
                //create a new string for use "./"
                dest[0u]='.';
                dest[1u]='/';
                dest[2u]='\0';
                return true;
            }
        }
    }
    return false;
}
bool edk::String::strFolderName(const edk::char8* str,edk::char8* dest){
    return edk::String::strFolderName((edk::char8*) str,(edk::char8*) dest);
}
//return the file name from a string without extension
edk::char8* edk::String::strFileNameNoExtension(edk::char8* str){
    edk::char8* ret = NULL;
    if(str){
        //create a pointer to read the string
        edk::char8* temp = str;
        //go to the end of the string
        while(*temp){
            temp++;
        }
        //boto the last point
        edk::char8* temp2 = temp-1u;
        while(*temp2){
            //search for the last point '.'
            if(*temp2=='.'){
                //temp = temp2-1u;
                break;
            }
            temp2--;
        }
        if(temp2!=temp){
            temp = temp2;
        }

        edk::uint32 size = 0u;
        //go back counting the size of the string
        while(*temp!='/' && *temp!='\\' && temp!=str){
            temp--;
            size++;
        }
        if(*temp=='/' || *temp=='\\'){
            temp++;
            if(size){
                size--;
            }
        }
        if(size){
            //create a new string with the size
            ret = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
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
edk::char8* edk::String::strFileNameNoExtension(const edk::char8* str){
    return edk::String::strFileNameNoExtension((edk::char8*) str);
}
bool edk::String::strFileNameNoExtension(edk::char8* str,edk::char8* dest){
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
        //boto the last point
        edk::char8* temp2 = temp-1u;
        while(*temp2){
            //search for the last point '.'
            if(*temp2=='.'){
                //temp = temp2-1u;
                break;
            }
            temp2--;
        }
        if(temp2!=temp){
            temp = temp2;
        }

        //go back
        while(*temp=='/' && *temp=='\\' && temp!=str){
            temp--;
        }
        if(*temp!='/' || *temp!='\\'){
            temp++;
        }
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
bool edk::String::strFileNameNoExtension(const edk::char8* str,edk::char8* dest){
    return edk::String::strFileNameNoExtension((edk::char8*) str, dest);
}
//return the file name with the folder from a string without extension
edk::char8* edk::String::strFolderAndFileNameNoExtension(edk::char8* str){
    edk::char8* ret = NULL;
    if(str){
        //create a pointer to read the string
        edk::char8* temp = str;
        edk::uint32 size = 0u;
        //go to the end of the string
        while(*temp){
            size++;
            temp++;
        }
        //boto the last point
        edk::char8* temp2 = temp-1u;
        edk::uint32 sizeCut = 0u;
        while(*temp2){
            //search for the last point '.'
            sizeCut++;
            if(*temp2=='.'){
                break;
            }
            temp2--;
        }
        if(temp2==temp){
            sizeCut=0u;
        }
        if(size){
            if(sizeCut){
                if(sizeCut<size){
                    size-=sizeCut;
                }
            }
            //create a new string with the size
            ret = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
            if(ret){
                //set the string end
                ret[size]='\0';
                //copy the name of the file to the return
                for(edk::uint32 i = 0u;i<size;i++){
                    ret[i] = str[i];
                }
            }
        }
    }
    return ret;
}
edk::char8* edk::String::strFolderAndFileNameNoExtension(const edk::char8* str){
    return edk::String::strFolderAndFileNameNoExtension((edk::char8*) str);
}
bool edk::String::strFolderAndFileNameNoExtension(edk::char8* str,edk::char8* dest){
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
        //boto the last point
        edk::char8* temp2 = temp-1u;
        while(*temp2){
            //search for the last point '.'
            if(*temp2=='.'){
                //temp = temp2-1u;
                break;
            }
            temp2--;
        }
        if(temp2!=temp){
            temp = temp2;
        }

        //go back
        while(*temp=='/' && *temp=='\\' && temp!=str){
            temp--;
        }
        if(*temp!='/' || *temp!='\\'){
            temp++;
        }
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
bool edk::String::strFolderAndFileNameNoExtension(const edk::char8* str,edk::char8* dest){
    return edk::String::strFolderAndFileNameNoExtension((edk::char8*) str, dest);
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
    if(size % 3 != 0){
        ret += 3 - (size % 3);
    }
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

        for (i=0, j=0; i<size; i+=3, j+=4){
            v = vec[i];
            v = i+1 < size ? v << 8 | vec[i+1] : v << 8;
            v = i+2 < size ? v << 8 | vec[i+2] : v << 8;

            dest[j]   = b64chars[(v >> 18) & 0x3F];
            dest[j+1] = b64chars[(v >> 12) & 0x3F];
            if(i+1 < size){
                dest[j+2] = b64chars[(v >> 6) & 0x3F];
            } else {
                dest[j+2] = '=';
            }
            if(i+2 < size){
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

    if(vec == NULL || size == 0){
        return NULL;
    }

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

    if(str == NULL){
        return 0;
    }

    len = edk::String::strSize(str);
    ret = len / 4 * 3;

    for (i=len; i-->0; ){
        if(str[i] == '='){
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

    if(str == NULL || dest == NULL){
        return false;
    }

    len = edk::String::strSize(str);
    /*
    if(size < edk::String::base64DecodeSize(str) || len % 4 != 0){
        return false;
        }
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

    for (i=0, j=0; i<len; i+=4, j+=3){
        v = b64invs[str[i]-43];
        v = (v << 6) | b64invs[str[i+1]-43];
        v = str[i+2]=='=' ? v << 6 : (v << 6) | b64invs[str[i+2]-43];
        v = str[i+3]=='=' ? v << 6 : (v << 6) | b64invs[str[i+3]-43];

        dest[j] = (v >> 16) & 0xFF;
        if(str[i+2] != '='){
            dest[j+1] = (v >> 8) & 0xFF;
        }
        if(str[i+3] != '='){
            dest[j+2] = v & 0xFF;
        }
    }
    return true;
}
bool edk::String::base64Decode(const edk::char8* str,edk::uint8* dest){
    return edk::String::base64Decode((edk::char8*) str,dest);
}

//convert the uri to utf8 to be used by http servers
edk::uint64 edk::String::uriUnescapeSize(edk::char8* str){
    edk::uint64  ret = 0u;
    //test the string
    if(str){
        // Skip inital non encoded character
        while (*str && !edkIsSpace((edk::int32)(*str)) && (*str != '%')){
            str++;
            ret++;
        }

        while (*str && !edkIsSpace((edk::int32)(*str))){
            if(*str == '+'){
                ret++;
            }
            else if((*str == '%') && str[1] && str[2]){
                str++;
                str++;
                ret++;
            } else{
                ret++;
            }
            str++;
        }
    }
    return ret;
}
edk::uint64 edk::String::uriUnescapeSize(const edk::char8* str){
    return edk::String::uriUnescapeSize((edk::char8*) str);
}
bool edk::String::uriUnescape(edk::char8* str,edk::char8* dest){
    if(str && dest){
        edk::char8 chr = 0;

        // Skip inital non encoded character
        while (*str && !edkIsSpace((edk::int32)(*str)) && (*str != '%')){
            *dest = *str;
            str++;
            dest++;
        }

        while (*str && !edkIsSpace((edk::int32)(*str))){
            if(*str == '+'){
                chr = ' ';
            }
            else if((*str == '%') && str[1] && str[2]){
                str++;
                chr = ((*str & 0x0F) + 9 * (*str > '9')) * 16;
                str++;
                chr += ((*str & 0x0F) + 9 * (*str > '9'));
            } else{
                chr = *str;
            }
            *dest = chr;
            dest++;
            str++;
        }
        *dest = '\0';
        return true;
    }
    return false;
}
bool edk::String::uriUnescape(const edk::char8* str,edk::char8* dest){
    return uriUnescape((edk::char8*) str,dest);
}
bool edk::String::uriUnescape(edk::char8* str,const edk::char8* dest){
    return uriUnescape(str,(edk::char8*) dest);
}
bool edk::String::uriUnescape(const edk::char8* str,const edk::char8* dest){
    return uriUnescape((edk::char8*) str,(edk::char8*) dest);
}
edk::char8* edk::String::uriUnescape(edk::char8* str){
    //create the new string to ret
    edk::uint64 size = edk::String::uriUnescapeSize(str);
    if(size){
        edk::char8* ret = (edk::char8*)malloc(sizeof(edk::char8) * (size+1u));
        if(ret){
            ret[size]='\0';
            if(edk::String::uriUnescape(str,ret)){
                return ret;
            }
            free(ret);
        }
    }
    return NULL;
}
edk::char8* edk::String::uriUnescape(const edk::char8* str){
    return edk::String::uriUnescape((edk::char8*) str);
}
