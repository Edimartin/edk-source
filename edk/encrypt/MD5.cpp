#include "MD5.h"

/*
Library C++ MD5 - Encrypt string in MD5
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
#pragma message "            Inside MD5.cpp"
#endif

edk::encrypt::MD5::MD5(){
    this->classThis=NULL;
    this->Constructor();
}
edk::encrypt::MD5::~MD5(){
    this->Destructor();
}

void edk::encrypt::MD5::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::encrypt::MD5::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
}

/*Change the MD5 algohith to the same used here
https://rosettacode.org/wiki/MD5#C
*/

typedef union uwb {
    edk::uint32 w;
    edk::uint8 b[4];
} WBunion;

typedef edk::uint32 Digest[4];

edk::uint32 f0( edk::uint32 abcd[] ){
    return ( abcd[1] & abcd[2]) | (~abcd[1] & abcd[3]); }

edk::uint32 f1( edk::uint32 abcd[] ){
    return ( abcd[3] & abcd[1]) | (~abcd[3] & abcd[2]); }

edk::uint32 f2( edk::uint32 abcd[] ){
    return  abcd[1] ^ abcd[2] ^ abcd[3]; }

edk::uint32 f3( edk::uint32 abcd[] ){
    return abcd[2] ^ (abcd[1] |~ abcd[3]); }

typedef edk::uint32 (*DgstFctn)(edk::uint32 a[]);

edk::uint32 *calcKs( edk::uint32 *k)
{
    double s, pwr;
    int i;

    pwr = pow( 2, 32);
    for (i=0; i<64; i++){
        s = fabs(sin(1+i));
        k[i] = (edk::uint32)( s * pwr );
    }
    return k;
}

// ROtate v Left by amt bits
edk::uint32 rol( edk::uint32 v, edk::int16 amt )
{
    edk::uint32  msk1 = (1<<amt) -1;
    return ((v>>(32-amt)) & msk1) | ((v<<amt) & ~msk1);
}

edk::uint32 *md5( edk::char8 *msg, edk::int32 mlen)
{
    static Digest h0 = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 };
    //    static Digest h0 = { 0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210 };
    static DgstFctn ff[] = { &f0, &f1, &f2, &f3 };
    static edk::int16 M[] = { 1, 5, 3, 7 };
    static edk::int16 O[] = { 0, 1, 5, 0 };
    static edk::int16 rot0[] = { 7,12,17,22};
    static edk::int16 rot1[] = { 5, 9,14,20};
    static edk::int16 rot2[] = { 4,11,16,23};
    static edk::int16 rot3[] = { 6,10,15,21};
    static edk::int16 *rots[] = {rot0, rot1, rot2, rot3 };
    static edk::uint32 kspace[64];
    static edk::uint32 *k;

    static Digest h;
    Digest abcd;
    DgstFctn fctn;
    edk::int16 m, o, g;
    edk::uint32 f;
    edk::int16 *rotn;
    union {
        edk::uint32 w[16];
        edk::char8  b[64];
    }mm;
    edk::int32 os = 0;
    edk::int32 grp, grps, q, p;
    edk::uint8 *msg2;

    if(k==NULL){
        k= calcKs(kspace);
    }

    for (q=0; q<4; q++){ h[q] = h0[q];  }  // initialize

    {
        grps  = 1 + (mlen+8)/64;
        msg2 = (edk::uint8 *)malloc( 64*grps);
        memcpy( msg2, msg, mlen);
        msg2[mlen] = (edk::uint8)0x80;
        q = mlen + 1;
        while (q < 64*grps){ msg2[q] = 0; q++ ;  }
        {
            //            edk::uint8 t;
            WBunion u;
            u.w = 8*mlen;
            //            t = u.b[0];  u.b[0] = u.b[3];  u.b[3] = t;
            //            t = u.b[1];  u.b[1] = u.b[2];  u.b[2] = t;
            q -= 8;
            memcpy(msg2+q, &u.w, 4 );
        }
    }

    for (grp=0; grp<grps; grp++)
    {
        memcpy( mm.b, msg2+os, 64);
        for(q=0;q<4;q++){ abcd[q] = h[q]; }
        for (p = 0; p<4; p++){
            fctn = ff[p];
            rotn = rots[p];
            m = M[p];  o= O[p];
            for (q=0; q<16; q++){
                g = (m*q + o) % 16;
                f = abcd[1] + rol( abcd[0]+ fctn(abcd) + k[q+16*p] + mm.w[g], rotn[q%4]);

                abcd[0] = abcd[3];
                abcd[3] = abcd[2];
                abcd[2] = abcd[1];
                abcd[1] = f;
            }
        }
        for (p=0; p<4; p++){
            h[p] += abcd[p];
        }
        os += 64;
    }

    if( msg2 ){
        free( msg2 );
    }

    return h;
}
edk::uint32 *md5File( edk::File* file)
{
    int mlen = file->getFileSize();
    static Digest h0 = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 };
    //    static Digest h0 = { 0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210 };
    static DgstFctn ff[] = { &f0, &f1, &f2, &f3 };
    static edk::int16 M[] = { 1, 5, 3, 7 };
    static edk::int16 O[] = { 0, 1, 5, 0 };
    static edk::int16 rot0[] = { 7,12,17,22};
    static edk::int16 rot1[] = { 5, 9,14,20};
    static edk::int16 rot2[] = { 4,11,16,23};
    static edk::int16 rot3[] = { 6,10,15,21};
    static edk::int16 *rots[] = {rot0, rot1, rot2, rot3 };
    static edk::uint32 kspace[64];
    static edk::uint32 *k;

    static Digest h;
    Digest abcd;
    DgstFctn fctn;
    edk::int16 m, o, g;
    edk::uint32 f;
    edk::int16 *rotn;
    union {
        edk::uint32 w[16];
        edk::char8  b[64];
    }mm;
    edk::int32 os = 0;
    edk::int32 grp, grps, q, p;
    edk::uint8 *msg2;

    if(k==NULL){
        k= calcKs(kspace);
    }

    for (q=0; q<4; q++){ h[q] = h0[q];  }  // initialize

    {
        grps  = 1 + (mlen+8)/64;
        msg2 = (edk::uint8 *)malloc( 64*grps);
        //memcpy( msg2, msg, mlen);
        file->readBin(msg2,mlen);
        msg2[mlen] = (edk::uint8)0x80;
        q = mlen + 1;
        while (q < 64*grps){ msg2[q] = 0; q++ ;  }
        {
            //            edk::uint8 t;
            WBunion u;
            u.w = 8*mlen;
            //            t = u.b[0];  u.b[0] = u.b[3];  u.b[3] = t;
            //            t = u.b[1];  u.b[1] = u.b[2];  u.b[2] = t;
            q -= 8;
            memcpy(msg2+q, &u.w, 4 );
        }
    }

    for (grp=0; grp<grps; grp++)
    {
        memcpy( mm.b, msg2+os, 64);
        for(q=0;q<4;q++){
            abcd[q] = h[q];
        }
        for (p = 0; p<4; p++){
            fctn = ff[p];
            rotn = rots[p];
            m = M[p];  o= O[p];
            for (q=0; q<16; q++){
                g = (m*q + o) % 16;
                f = abcd[1] + rol( abcd[0]+ fctn(abcd) + k[q+16*p] + mm.w[g], rotn[q%4]);

                abcd[0] = abcd[3];
                abcd[3] = abcd[2];
                abcd[2] = abcd[1];
                abcd[1] = f;
            }
        }
        for (p=0; p<4; p++){
            h[p] += abcd[p];
        }
        os += 64;
    }

    if( msg2 ){
        free( msg2 );
    }

    return h;
}










//process the MD5
bool edk::encrypt::MD5::convertTo(edk::char8 *pass, edk::uint32 size, edk::char8 *dest){
    //testa as strings e os tamanhos
    if(pass && size && dest){
        //processa o MD5
        edk::uint8 result[16];
        //md5WikiSum((Md5uint8_t *)pass, size, result);

        edk::uint32 *d = md5(pass, size);
        WBunion u;

        edk::uint32 i = 0u;
        for (edk::uint32 j=0;j<4; j++){
            u.w = d[j];
            for (edk::uint32 k=0;k<4;k++){
                result[i]=u.b[k];
                i++;
            }
        }


        //write the result in the destiny
#ifdef _MSC_VER
        sprintf_s((edk:char8*)dest,33u
          #else
        sprintf((edk::char8*)dest
        #endif
                ,"%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x"
                ,result[0],result[1],result[2],result[3],result[4],result[5],result[6],result[7],result[8],result[9],result[10],result[11],result[12],result[13],result[14],result[15]);
        //then return true
        return true;
    }
    //senao retorna false
    return false;
}
bool edk::encrypt::MD5::convertTo(const edk::char8 *pass, edk::uint32 size, edk::char8 *dest){
    return edk::encrypt::MD5::convertTo((edk::char8 *)pass, size, dest);
}
bool edk::encrypt::MD5::convertTo(edk::char8 *pass, edk::char8 *dest){
    return edk::encrypt::MD5::convertTo(pass,edk::String::strSize(pass),dest);
}
bool edk::encrypt::MD5::convertTo(const edk::char8 *pass, edk::char8 *dest){
    return edk::encrypt::MD5::convertTo((edk::char8 *)pass, dest);
}
bool edk::encrypt::MD5::convertFileTo(edk::File* file, edk::char8 *dest){
    //first test the file and dest
    if(file && dest){
        if(file->isOpened()){
            //
            //processa o MD5
            edk::uint8 result[16];
            //md5WikiSum(file, result);

            edk::uint32 *d = md5File(file);
            WBunion u;

            edk::uint32 i = 0u;
            for (edk::uint32 j=0;j<4; j++){
                u.w = d[j];
                for (edk::uint32 k=0;k<4;k++){
                    result[i]=u.b[k];
                    i++;
                }
            }


            //escreve o resultado no destino
#ifdef _MSC_VER
            sprintf_s((edk::char8*)dest,33u
          #else
            sprintf((edk::char8*)dest
        #endif
                    ,"%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x"
                    ,result[0],result[1],result[2],result[3],result[4],result[5],result[6],result[7],result[8],result[9],result[10],result[11],result[12],result[13],result[14],result[15]);
            //then return true
            return true;
        }
    }
    return false;
}
bool edk::encrypt::MD5::convertFileTo(edk::char8 *fileName, edk::char8 *dest){
    bool ret = false;
    if(fileName && dest){
        edk::File file;
        file.openBinFile(fileName);
        if(file.isOpened()){
            ret = edk::encrypt::MD5::convertFileTo(&file,dest);
            file.closeFile();
        }
    }
    return ret;
}
bool edk::encrypt::MD5::convertFileTo(const edk::char8 *fileName, edk::char8 *dest){
    return edk::encrypt::MD5::convertFileTo((edk::char8 *)fileName, dest);
}
bool edk::encrypt::MD5::convertTo(edk::char8 *pass, edk::uint32 size, edk::uint8 dest[16u]){

    //testa as strings e os tamanhos
    if(pass && size && dest){
        //processa o MD5
        //md5WikiSum((Md5uint8_t *)pass, size, dest);

        edk::uint32 *d = md5(pass, size);
        WBunion u;

        edk::uint32 i = 0u;
        for (edk::uint32 j=0;j<4; j++){
            u.w = d[j];
            for (edk::uint32 k=0;k<4;k++){
                dest[i]=u.b[k];
                i++;
            }
        }

        //then return true
        return true;
    }
    //senao retorna false
    return false;
}
bool edk::encrypt::MD5::convertTo(const edk::char8 *pass, edk::uint32 size, edk::uint8 dest[16u]){
    return edk::encrypt::MD5::convertTo((edk::char8 *)pass, size, dest);
}
bool edk::encrypt::MD5::convertTo(edk::char8 *pass, edk::uint8 dest[16u]){
    return edk::encrypt::MD5::convertTo(pass,edk::String::strSize(pass),dest);
}
bool edk::encrypt::MD5::convertTo(const edk::char8 *pass, edk::uint8 dest[16u]){
    return edk::encrypt::MD5::convertTo((edk::char8 *)pass, dest);
}
bool edk::encrypt::MD5::convertFileTo(edk::File* file, edk::uint8 dest[16u]){
    //first test the file and dest
    if(file && dest){
        if(file->isOpened()){
            //processa o MD5
            //md5WikiSum(file, dest);

            edk::uint32 *d = md5File(file);
            WBunion u;

            edk::uint32 i = 0u;
            for (edk::uint32 j=0;j<4; j++){
                u.w = d[j];
                for (edk::uint32 k=0;k<4;k++){
                    dest[i]=u.b[k];
                    i++;
                }
            }

            //then return true
            return true;
        }
    }
    return false;
}
bool edk::encrypt::MD5::convertFileTo(edk::char8 *fileName, edk::uint8 dest[16u]){
    //
    bool ret = false;
    if(fileName && dest){
        edk::File file;
        file.openBinFile(fileName);
        if(file.isOpened()){
            ret = edk::encrypt::MD5::convertFileTo(&file,dest);
            file.closeFile();
        }
    }
    return ret;
}
bool edk::encrypt::MD5::convertFileTo(const edk::char8 *fileName, edk::uint8 dest[16u]){
    return edk::encrypt::MD5::convertFileTo((edk::char8 *)fileName, dest);
}
edk::char8* edk::encrypt::MD5::convert(edk::char8 *pass, edk::uint32 size){
    edk::char8* ret=NULL;
    if(pass && size){
        //cria a string de retorno
        ret = (edk::char8*)malloc(sizeof(edk::char8) * (33u));
        if(ret){
            edk::encrypt::MD5::convertTo(pass, size,ret);
        }
    }
    //senao retorna NULL
    return ret;
}
edk::char8* edk::encrypt::MD5::convert(const edk::char8 *pass, edk::uint32 size){
    return edk::encrypt::MD5::convert((edk::char8 *)pass, size);
}
edk::char8* edk::encrypt::MD5::convert(edk::char8 *pass){
    return edk::encrypt::MD5::convert(pass, edk::String::strSize(pass));
}
edk::char8* edk::encrypt::MD5::convert(const edk::char8 *pass){
    return edk::encrypt::MD5::convert((edk::char8 *)pass);
}
edk::char8* edk::encrypt::MD5::convertFile(edk::File* file){
    edk::char8* ret=NULL;
    if(file){
        //cria a string de retorno
        ret = (edk::char8*)malloc(sizeof(edk::char8) * (33u));
        if(ret){
            edk::encrypt::MD5::convertFileTo(file,ret);
        }
    }
    //senao retorna NULL
    return ret;
}
edk::char8* edk::encrypt::MD5::convertFile(edk::char8 *fileName){
    edk::char8* ret=NULL;
    if(fileName){
        edk::File file;
        file.openBinFile(fileName);
        if(file.isOpened()){
            ret = edk::encrypt::MD5::convertFile(&file);
            file.closeFile();
        }
    }
    return ret;
}
edk::char8* edk::encrypt::MD5::convertFile(const edk::char8 *fileName){
    return edk::encrypt::MD5::convertFile((edk::char8 *)fileName);
}
