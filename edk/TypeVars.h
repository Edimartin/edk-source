#ifndef EDK_TYPEVARS_H
#define EDK_TYPEVARS_H

#pragma once
#include <stdio.h>
#include <typeinfo>

/*
Library C++ TypeVars - Data types used in EDK engine.
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
#pragma message "Inside TypesVars"
#endif

#ifdef printMessages
#pragma message "    Compiling TypesVars"
#endif


/*TYPES USED BY EDK ENGINE*/
namespace edk{
//#define edkSizeof(X) ((X*)0 +1)

typedef void* classID;

typedef unsigned int    typeID;

typedef unsigned char socketType;

typedef signed   char          int8;
typedef unsigned char          uint8;
typedef signed   short int     int16;
typedef unsigned short int     uint16;

typedef float                  float32;
typedef double                 float64;

typedef int                    int32;
typedef unsigned int           uint32;
#if defined(__arch64__) || defined(_LP64)
typedef signed long int        int64;
typedef unsigned long int      uint64;
#else
typedef signed long long int   int64;
typedef unsigned long long int uint64;
#endif

typedef /*signed*/   char          char8;
typedef unsigned char          uchar8;
typedef /*signed*/   short int     char16;
typedef unsigned short int     uchar16;

typedef int                    char32;
typedef unsigned int           uchar32;
#if defined(__arch64__) || defined(_LP64)
typedef signed long int        char64;
typedef unsigned long int      uchar64;
#else
typedef signed long int        char64;
typedef unsigned long long int uchar64;
#endif

}//end namespace

#include <stdarg.h>

//MARCROS

//Need a class to remove the nothing warning
namespace edk{
class NothingClass{
public:
    inline static void edk_nothing(){}
    //write to vprintf with the line, file and function names
    inline static void edk_lffprint(edk::uint32 line, const edk::char8* fileName, const edk::char8* funcName, const edk::char8* str,...){
        if(fileName && funcName && str){
            printf("\n[%06u] (%10s) %10s():",line,fileName,funcName);
            va_list args;
            va_start (args, str);
            vprintf (str, args);
            va_end (args);
            fflush(stdout);
        }
    }
};
template <class c1,class c2>
class IDs{
public:
    inline static bool equal(){
        if(typeid(c1) == typeid(c2)){
            return true;
        }
        return false;
    }
    inline static bool isEqual(){
        if(typeid(c1) == typeid(c2)){
            return true;
        }
        return false;
    }
    inline static bool areEqual(){
        if(typeid(c1) == typeid(c2)){
            return true;
        }
        return false;
    }
};
template <class typeTemplate>
class ID{
public:
    inline static void print(){
        printf("%s",typeid(typeTemplate).name());
    }
    inline static edk::char8* getStr(){
        return (edk::char8*)typeid(typeTemplate).name();
    }
    inline static bool isClass(){
        if((edk::uint8)sizeof(typeTemplate)>8u){
            return true;
        }
        else if(edk::IDs<        char                ,typeTemplate>::equal()
                ||edk::IDs<      short               ,typeTemplate>::equal()
                ||edk::IDs<      int                 ,typeTemplate>::equal()
                ||edk::IDs<      long                ,typeTemplate>::equal()
                ||edk::IDs<      long long           ,typeTemplate>::equal()
                ||edk::IDs<      unsigned char       ,typeTemplate>::equal()
                ||edk::IDs<const char*               ,typeTemplate>::equal()
                ||edk::IDs<      unsigned short      ,typeTemplate>::equal()
                ||edk::IDs<      unsigned int        ,typeTemplate>::equal()
                ||edk::IDs<      unsigned long       ,typeTemplate>::equal()
                ||edk::IDs<      unsigned long long  ,typeTemplate>::equal()
                ||edk::IDs<void*                     ,typeTemplate>::equal()
                ||edk::IDs<const unsigned short      ,typeTemplate>::equal()
                //
                ||edk::IDs<      char*               ,typeTemplate>::equal()
                ||edk::IDs<      short*              ,typeTemplate>::equal()
                ||edk::IDs<      int*                ,typeTemplate>::equal()
                ||edk::IDs<      long*               ,typeTemplate>::equal()
                ||edk::IDs<      long long*          ,typeTemplate>::equal()
                ||edk::IDs<      unsigned char*      ,typeTemplate>::equal()
                ||edk::IDs<      unsigned short*     ,typeTemplate>::equal()
                //
                ||edk::IDs<const char                ,typeTemplate>::equal()
                ||edk::IDs<const short               ,typeTemplate>::equal()
                ||edk::IDs<const int                 ,typeTemplate>::equal()
                ||edk::IDs<const long                ,typeTemplate>::equal()
                ||edk::IDs<const long long           ,typeTemplate>::equal()
                ||edk::IDs<const unsigned char       ,typeTemplate>::equal()
                //
                ||edk::IDs<const short*              ,typeTemplate>::equal()
                ||edk::IDs<const int*                ,typeTemplate>::equal()
                ||edk::IDs<const long*               ,typeTemplate>::equal()
                ||edk::IDs<const long long*          ,typeTemplate>::equal()
                ||edk::IDs<const unsigned char*      ,typeTemplate>::equal()
                ||edk::IDs<void                      ,typeTemplate>::equal()
                //
                ||edk::IDs<const unsigned short*     ,typeTemplate>::equal()
                ||edk::IDs<      unsigned int*       ,typeTemplate>::equal()
                ||edk::IDs<const unsigned int        ,typeTemplate>::equal()
                ||edk::IDs<const unsigned int*       ,typeTemplate>::equal()
                ||edk::IDs<      unsigned long*      ,typeTemplate>::equal()
                ||edk::IDs<const unsigned long       ,typeTemplate>::equal()
                ||edk::IDs<const unsigned long*      ,typeTemplate>::equal()
                ||edk::IDs<      unsigned long long* ,typeTemplate>::equal()
                ||edk::IDs<const unsigned long long  ,typeTemplate>::equal()
                ||edk::IDs<const unsigned long long* ,typeTemplate>::equal()
                ){
            return false;
        }
        return true;
    }
    template <class C>
    inline static bool equalTo(C c){
        if(typeid(typeTemplate) == typeid(c)){
            return true;
        }
        return false;
    }
};
class ID_Variable{
public:
    template <class C>
    inline static void print(C c){
        printf("%s",typeid(c).name());
    }
    template <class C>
    inline static edk::char8* getStr(C c){
        return (edk::char8*)typeid(c).name();
    }
    template <class C>
    inline static bool isClass(C c){
        if(sizeof(c)>8u){
            return true;
        }
        else if(edk::ID<        char                >::equalTo(c)
                ||edk::ID<      short               >::equalTo(c)
                ||edk::ID<      int                 >::equalTo(c)
                ||edk::ID<      long                >::equalTo(c)
                ||edk::ID<      long long           >::equalTo(c)
                ||edk::ID<      unsigned char       >::equalTo(c)
                ||edk::ID<const char*               >::equalTo(c)
                ||edk::ID<      unsigned short      >::equalTo(c)
                ||edk::ID<      unsigned int        >::equalTo(c)
                ||edk::ID<      unsigned long       >::equalTo(c)
                ||edk::ID<      unsigned long long  >::equalTo(c)
                ||edk::ID<void*                     >::equalTo(c)
                ||edk::ID<const unsigned short      >::equalTo(c)
                //
                ||edk::ID<      char*               >::equalTo(c)
                ||edk::ID<      short*              >::equalTo(c)
                ||edk::ID<      int*                >::equalTo(c)
                ||edk::ID<      long*               >::equalTo(c)
                ||edk::ID<      long long*          >::equalTo(c)
                ||edk::ID<      unsigned char*      >::equalTo(c)
                ||edk::ID<      unsigned short*     >::equalTo(c)
                //
                ||edk::ID<const char                >::equalTo(c)
                ||edk::ID<const short               >::equalTo(c)
                ||edk::ID<const int                 >::equalTo(c)
                ||edk::ID<const long                >::equalTo(c)
                ||edk::ID<const long long           >::equalTo(c)
                ||edk::ID<const unsigned char       >::equalTo(c)
                //
                ||edk::ID<const short*              >::equalTo(c)
                ||edk::ID<const int*                >::equalTo(c)
                ||edk::ID<const long*               >::equalTo(c)
                ||edk::ID<const long long*          >::equalTo(c)
                ||edk::ID<const unsigned char*      >::equalTo(c)
                ||edk::ID<void                      >::equalTo(c)
                //
                ||edk::ID<const unsigned short*     >::equalTo(c)
                ||edk::ID<      unsigned int*       >::equalTo(c)
                ||edk::ID<const unsigned int        >::equalTo(c)
                ||edk::ID<const unsigned int*       >::equalTo(c)
                ||edk::ID<      unsigned long*      >::equalTo(c)
                ||edk::ID<const unsigned long       >::equalTo(c)
                ||edk::ID<const unsigned long*      >::equalTo(c)
                ||edk::ID<      unsigned long long* >::equalTo(c)
                ||edk::ID<const unsigned long long  >::equalTo(c)
                ||edk::ID<const unsigned long long* >::equalTo(c)
                ){
            return false;
        }
        return true;
    }
    template <class C,typename T>
    inline static bool isEqual(C c,T t){
        if(typeid(c) == typeid(t)){
            return true;
        }
        return false;
    }
    template <class C,typename T>
    inline static bool arEqual(C c,T t){
        if(typeid(c) == typeid(t)){
            return true;
        }
        return false;
    }
    template <class C,typename T>
    inline static bool equal(C c,T t){
        if(typeid(c) == typeid(t)){
            return true;
        }
        return false;
    }
    template <class C,typename T>
    inline static bool equalTo(C c,T t){
        if(typeid(c) == typeid(t)){
            return true;
        }
        return false;
    }
};
class C{
public:
    C(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~C(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
        }
    }

    void Constructor(){
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
private:
    edk::classID classThis;
};
class id{
public:
    static void printAll(){
        printf("\nTypes ID's:");
        printf("\n");
        printf("\nedk::classID    ");edk::ID<classID>::print();
        printf("\nedk::typeID     ");edk::ID<typeID>::print();
        printf("\nedk::socketType ");edk::ID<socketType>::print();
        printf("\n");
        printf("\nedk::int8       ");edk::ID<int8>::print();
        printf("\nedk::int16      ");edk::ID<int16>::print();
        printf("\nedk::int32      ");edk::ID<int32>::print();
        printf("\nedk::int64      ");edk::ID<int64>::print();
        printf("\n");
        printf("\nedk::uint8      ");edk::ID<uint8>::print();
        printf("\nedk::uint16     ");edk::ID<uint16>::print();
        printf("\nedk::uint32     ");edk::ID<uint32>::print();
        printf("\nedk::uint64     ");edk::ID<uint64>::print();
        printf("\n");
        printf("\nedk::char8      ");edk::ID<char8>::print();
        printf("\nedk::char16     ");edk::ID<char16>::print();
        printf("\nedk::char32     ");edk::ID<char32>::print();
        printf("\nedk::char64     ");edk::ID<char64>::print();
        printf("\n");
        printf("\nedk::uchar8     ");edk::ID<uchar8>::print();
        printf("\nedk::uchar16    ");edk::ID<uchar16>::print();
        printf("\nedk::uchar32    ");edk::ID<uchar32>::print();
        printf("\nedk::uchar64    ");edk::ID<uchar64>::print();
        printf("\n");
        printf("\nedk::float32    ");edk::ID<float32>::print();
        printf("\nedk::float64    ");edk::ID<float64>::print();
        printf("\nTEST");
        printf("\nedk::classID ");
        fflush(stdout);
    }
};
}

#define edkPrintf(str,args...) \
    edk::NothingClass::edk_lffprint(__LINE__,__FILE__,__func__,str,##args); \
    edk::NothingClass::edk_nothing()
/*
#if defined(EDK_DEBUGGER)
#define edkEnd() printf("\n%u %s %s",__LINE__,__FILE__,__func__); \
    fflush(stdout)
#else
#define edkEnd() edk::NothingClass::edk_nothing()
#endif
*/

#endif // TYPEVARS_H
