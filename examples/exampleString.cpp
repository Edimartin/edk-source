/*
Library EDK - How to use Extensible Development Kit
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

#include "edk/String.h"

#define strFloat "123.456"
#define strInt "-321"
#define strUint "456"
#define uintStr 123456
#define intStr -987654321
#define floatStr 1234.5678
#define digits 2u
#define str1 "String1"
#define str2 "String2"
#define str3 "String3"
#define str4 "String4"
#define str5 "String5"
#define str6 "String6"
#define strFilter "12345"
#define strFilter1 "String123String321String"
#define strFilter2 "StringString54321String"
#define strFilter3 "String0String1String"
#define strFilter4 "String1String2"
#define charFilter 'g'
#define charFilterStart 't'
#define charFilterEnd 'n'
#define charFind '1'

int main(){
    edk::char8* str=NULL;
    //Convertions
    printf("\nstrToFloat32(%s) == %f \nstrToFloat64(%s) == %f \nstrToInt32(%s) == %d  \nstrToInt64(%s) == %ld "
           ,strFloat
           ,edk::String::strToFloat32(strFloat)
           ,strFloat
           ,edk::String::strToFloat32(strFloat)
           ,strInt
           ,edk::String::strToInt32(strInt)
           ,strInt
           ,edk::String::strToInt64(strInt)
           );fflush(stdout);
    //intToStr
    str = edk::String::int32ToStr(uintStr);
    if(str){
        printf("\nint32ToStr(%d) == '%s'"
               ,uintStr
               ,str
               );
        //don't forget to delete the string
        delete[] str;
    }
    str = edk::String::int32ToStr(intStr);
    if(str){
        printf("\nint32ToStr(%d) == '%s'"
               ,intStr
               ,str
               );
        //don't forget to delete the string
        delete[] str;
    }
    //floatToStr
    str = edk::String::float32ToStr(floatStr);
    if(str){
        printf("\nint32ToStr(%f) == '%s'"
               ,floatStr
               ,str
               );
        //don't forget to delete the string
        delete[] str;
    }
    str = edk::String::float32ToStr(floatStr,digits);
    if(str){
        printf("\nint32ToStr(%f,%u) == '%s'"
               ,floatStr
               ,digits
               ,str
               );
        //don't forget to delete the string
        delete[] str;
    }
    //int lenght
    edk::uint32 size = edk::String::sizeOfInt32(intStr);
    if(size){
        printf("\nInt lenght is returned in sizeOfInt32(%d) %u",intStr,size);fflush(stdout);
    }
    //Concatenate two strings
    str = edk::String::strCat(str1,str2);
    if(str){
        printf("\nStrCat(%s,%s) == '%s'",str1,str2,str);fflush(stdout);
        delete[] str;
    }
    //Concatenate multiple strings
    str = edk::String::strCatMulti(str1,str2,str3,str4,str5,str6,NULL);
    if(str){
        printf("\nStrCat(%s,%s,%s,%s,%s,%s,NULL) == '%s'",str1,str2,str3,str4,str5,str6,str);fflush(stdout);
        delete[] str;
    }
    //compare two strings
    printf("\nstrCompare(%s,%s) == %s"
           ,str1,str2
           ,edk::String::strCompare(str1,str2)?"true":"false"
           );fflush(stdout);
    printf("\nstrCompare(%s,%s) == %s"
           ,str3,str3
           ,edk::String::strCompare(str3,str3)?"true":"false"
           );fflush(stdout);
    //compare two strings removing the filter
    printf("\nstrCompare(%s,%s,%s) == %s"
           ,str1,str2,strFilter
           ,edk::String::strCompareWithFilter(str1,str2,strFilter)?"true":"false"
           );fflush(stdout);
    printf("\nstrCompare(%s,%s,%s) == %s"
           ,strFilter1,strFilter2,strFilter
           ,edk::String::strCompareWithFilter(strFilter1,strFilter2,strFilter)?"true":"false"
           );fflush(stdout);
    printf("\nstrCompare(%s,%s,%s) == %s"
           ,strFilter1,strFilter3,strFilter
           ,edk::String::strCompareWithFilter(strFilter1,strFilter3,strFilter)?"true":"false"
           );fflush(stdout);
    printf("\nstrCompare(%s,%s,%s) == %s"
           ,strFilter2,strFilter4,strFilter
           ,edk::String::strCompareWithFilter(strFilter2,strFilter4,strFilter)?"true":"false"
           );fflush(stdout);
    //StrSize
    printf("\nstrSize(%s) == %lu"
           ,str1
           ,edk::String::strSize(str1)
           );fflush(stdout);
    printf("\nstrSize(%s) == %lu"
           ,strFilter1
           ,edk::String::strSize(strFilter1)
           );fflush(stdout);
    printf("\nstrSizeWithFilter(%s,%s) == %lu"
           ,strFilter1,strFilter
           ,edk::String::strSizeWithFilter(strFilter1,strFilter)
           );fflush(stdout);
    //Cut String
    str = edk::String::strCut(str1,charFilter,false);
    if(str){
        printf("\nstrCut(%s,%c,%s) == %s"
               ,str1
               ,charFilter
               ,"false"
               ,str
               );fflush(stdout);
        delete[] str;
    }
    str = edk::String::strCut(str1,charFilter,true);
    if(str){
        printf("\nstrCut(%s,%c,%s) == %s"
               ,str1
               ,charFilter
               ,"true"
               ,str
               );fflush(stdout);
        delete[] str;
    }
    //Cut String NEXT
    str = edk::String::strCut(charFilter,str1,false);
    if(str){
        printf("\nstrCut(%c,%s,%s) == %s"
               ,charFilter
               ,str1
               ,"false"
               ,str
               );fflush(stdout);
        delete[] str;
    }
    str = edk::String::strCut(charFilter,str1,true);
    if(str){
        printf("\nstrCut(%c,%s,%s) == %s"
               ,charFilter
               ,str1
               ,"true"
               ,str
               );fflush(stdout);
        delete[] str;
    }
    //strCut inside
    str = edk::String::strCut(str1,charFilterStart,charFilterEnd,true);
    if(str){
        printf("\nstrCut(%s,%c,%c,%s) == %s"
               ,str1
               ,charFilterStart
               ,charFilterEnd
               ,"true"
               ,str
               );fflush(stdout);
        delete[] str;
    }
    str = edk::String::strCut(str1,charFilterStart,charFilterEnd,false);
    if(str){
        printf("\nstrCut(%s,%c,%c,%s) == %s"
               ,str1
               ,charFilterStart
               ,charFilterEnd
               ,"false"
               ,str
               );fflush(stdout);
        delete[] str;
    }
    edk::uint64 position = 0u;
    //test if have the char in position
    position = edk::String::stringHaveChar(str1,charFind);
    printf("\nstringHaveChar(%s,%c) == %lu (%s)"
           ,str1,charFind
           ,position
           ,position?"true":"false"
           );fflush(stdout);
    position = edk::String::stringHaveChar(str2,charFind);
    printf("\nstringHaveChar(%s,%c) == %lu (%s)"
           ,str2,charFind
           ,position
           ,position?"true":"false"
           );fflush(stdout);
    //StrCopy
    str = edk::String::strCopy(strFilter1);
    if(str){
        printf("\nstrCopy(%s) == %s"
               ,strFilter1
               ,str
               );fflush(stdout);
        delete[] str;
    }
    str = edk::String::strCopyWithFilter(strFilter1,strFilter);
    if(str){
        printf("\nstrCopyWithFilter(%s,%s) == %s"
               ,strFilter1
               ,strFilter
               ,str
               );fflush(stdout);
        delete[] str;
    }

    //test the terminal
    printf("\nPress any terminal key");fflush(stdin);
    edk::String::consoleReadKey();

    edk::String::consoleClear();

    //read a string from console
    printf("\nWrite your name and press enter\n");fflush(stdout);
    str = edk::String::consoleReadString();
    if(str){
        printf("\nYour name is '%s'"
               ,str
               );fflush(stdout);
        delete[] str;
    }

    printf("\nPress any terminal key");fflush(stdin);
    edk::String::consoleReadKey();

    edk::uint64 counter = 0u;
    while(true){
        printf("\nCounter == %lu press escape (27) to finish the software",counter);fflush(stdout);
        counter++;
        if(edk::String::consoleKeyPressed())if(edk::String::consoleReadKey()==27)break;
    }

    printf("\n\n");fflush(stdout);
    return 0;
}
