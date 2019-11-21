#include "MD5.h"

/*
Library C++ MD5 - Encrypt string in MD5
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
#warning "            Inside MD5.cpp"
#endif

edk::encrypt::MD5::MD5()
{
}
edk::encrypt::MD5::~MD5()
{
}

/*Change the MD5 algohith to the same used here
https://rosettacode.org/wiki/MD5#C
*/

typedef union uwb {
    unsigned w;
    unsigned char b[4];
} WBunion;

typedef unsigned Digest[4];

unsigned f0( unsigned abcd[] ){
    return ( abcd[1] & abcd[2]) | (~abcd[1] & abcd[3]);}

unsigned f1( unsigned abcd[] ){
    return ( abcd[3] & abcd[1]) | (~abcd[3] & abcd[2]);}

unsigned f2( unsigned abcd[] ){
    return  abcd[1] ^ abcd[2] ^ abcd[3];}

unsigned f3( unsigned abcd[] ){
    return abcd[2] ^ (abcd[1] |~ abcd[3]);}

typedef unsigned (*DgstFctn)(unsigned a[]);

unsigned *calcKs( unsigned *k)
{
    double s, pwr;
    int i;

    pwr = pow( 2, 32);
    for (i=0; i<64; i++) {
        s = fabs(sin(1+i));
        k[i] = (unsigned)( s * pwr );
    }
    return k;
}

// ROtate v Left by amt bits
unsigned rol( unsigned v, short amt )
{
    unsigned  msk1 = (1<<amt) -1;
    return ((v>>(32-amt)) & msk1) | ((v<<amt) & ~msk1);
}

unsigned *md5( char *msg, int mlen)
{
    static Digest h0 = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 };
//    static Digest h0 = { 0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210 };
    static DgstFctn ff[] = { &f0, &f1, &f2, &f3 };
    static short M[] = { 1, 5, 3, 7 };
    static short O[] = { 0, 1, 5, 0 };
    static short rot0[] = { 7,12,17,22};
    static short rot1[] = { 5, 9,14,20};
    static short rot2[] = { 4,11,16,23};
    static short rot3[] = { 6,10,15,21};
    static short *rots[] = {rot0, rot1, rot2, rot3 };
    static unsigned kspace[64];
    static unsigned *k;

    static Digest h;
    Digest abcd;
    DgstFctn fctn;
    short m, o, g;
    unsigned f;
    short *rotn;
    union {
        unsigned w[16];
        char     b[64];
    }mm;
    int os = 0;
    int grp, grps, q, p;
    unsigned char *msg2;

    if (k==NULL) k= calcKs(kspace);

    for (q=0; q<4; q++) h[q] = h0[q];   // initialize

    {
        grps  = 1 + (mlen+8)/64;
        msg2 = (unsigned char *)malloc( 64*grps);
        memcpy( msg2, msg, mlen);
        msg2[mlen] = (unsigned char)0x80;
        q = mlen + 1;
        while (q < 64*grps){ msg2[q] = 0; q++ ; }
        {
//            unsigned char t;
            WBunion u;
            u.w = 8*mlen;
//            t = u.b[0]; u.b[0] = u.b[3]; u.b[3] = t;
//            t = u.b[1]; u.b[1] = u.b[2]; u.b[2] = t;
            q -= 8;
            memcpy(msg2+q, &u.w, 4 );
        }
    }

    for (grp=0; grp<grps; grp++)
    {
        memcpy( mm.b, msg2+os, 64);
        for(q=0;q<4;q++) abcd[q] = h[q];
        for (p = 0; p<4; p++) {
            fctn = ff[p];
            rotn = rots[p];
            m = M[p]; o= O[p];
            for (q=0; q<16; q++) {
                g = (m*q + o) % 16;
                f = abcd[1] + rol( abcd[0]+ fctn(abcd) + k[q+16*p] + mm.w[g], rotn[q%4]);

                abcd[0] = abcd[3];
                abcd[3] = abcd[2];
                abcd[2] = abcd[1];
                abcd[1] = f;
            }
        }
        for (p=0; p<4; p++)
            h[p] += abcd[p];
        os += 64;
    }

    if( msg2 )
        free( msg2 );

    return h;
}
unsigned *md5File( edk::File* file)
{
    int mlen = file->getFileSize();
    static Digest h0 = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 };
//    static Digest h0 = { 0x01234567, 0x89ABCDEF, 0xFEDCBA98, 0x76543210 };
    static DgstFctn ff[] = { &f0, &f1, &f2, &f3 };
    static short M[] = { 1, 5, 3, 7 };
    static short O[] = { 0, 1, 5, 0 };
    static short rot0[] = { 7,12,17,22};
    static short rot1[] = { 5, 9,14,20};
    static short rot2[] = { 4,11,16,23};
    static short rot3[] = { 6,10,15,21};
    static short *rots[] = {rot0, rot1, rot2, rot3 };
    static unsigned kspace[64];
    static unsigned *k;

    static Digest h;
    Digest abcd;
    DgstFctn fctn;
    short m, o, g;
    unsigned f;
    short *rotn;
    union {
        unsigned w[16];
        char     b[64];
    }mm;
    int os = 0;
    int grp, grps, q, p;
    unsigned char *msg2;

    if (k==NULL) k= calcKs(kspace);

    for (q=0; q<4; q++) h[q] = h0[q];   // initialize

    {
        grps  = 1 + (mlen+8)/64;
        msg2 = (unsigned char *)malloc( 64*grps);
        //memcpy( msg2, msg, mlen);
        file->readBin(msg2,mlen);
        msg2[mlen] = (unsigned char)0x80;
        q = mlen + 1;
        while (q < 64*grps){ msg2[q] = 0; q++ ; }
        {
//            unsigned char t;
            WBunion u;
            u.w = 8*mlen;
//            t = u.b[0]; u.b[0] = u.b[3]; u.b[3] = t;
//            t = u.b[1]; u.b[1] = u.b[2]; u.b[2] = t;
            q -= 8;
            memcpy(msg2+q, &u.w, 4 );
        }
    }

    for (grp=0; grp<grps; grp++)
    {
        memcpy( mm.b, msg2+os, 64);
        for(q=0;q<4;q++) abcd[q] = h[q];
        for (p = 0; p<4; p++) {
            fctn = ff[p];
            rotn = rots[p];
            m = M[p]; o= O[p];
            for (q=0; q<16; q++) {
                g = (m*q + o) % 16;
                f = abcd[1] + rol( abcd[0]+ fctn(abcd) + k[q+16*p] + mm.w[g], rotn[q%4]);

                abcd[0] = abcd[3];
                abcd[3] = abcd[2];
                abcd[2] = abcd[1];
                abcd[1] = f;
            }
        }
        for (p=0; p<4; p++)
            h[p] += abcd[p];
        os += 64;
    }

    if( msg2 )
        free( msg2 );

    return h;
}










//processa o MD5
bool edk::encrypt::MD5::convertTo(edk::char8 *pass, edk::uint32 size, edk::char8 *dest){
    //testa as strings e os tamanhos
    if (pass && size && dest){
        //processa o MD5
        unsigned char result[16];
        //md5WikiSum((Md5uint8_t *)pass, size, result);

        unsigned *d = md5(pass, size);
        WBunion u;

        edk::uint32 i = 0u;
        for (edk::uint32 j=0;j<4; j++){
            u.w = d[j];
            for (edk::uint32 k=0;k<4;k++) {
                result[i]=u.b[k];
                i++;
            }
        }


        //escreve o resultado no destino
#ifdef _MSC_VER
        sprintf_s((char*)dest,33u
          #else
        sprintf((char*)dest
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
            unsigned char result[16];
            //md5WikiSum(file, result);

            unsigned *d = md5File(file);
            WBunion u;

            edk::uint32 i = 0u;
            for (edk::uint32 j=0;j<4; j++){
                u.w = d[j];
                for (edk::uint32 k=0;k<4;k++) {
                    result[i]=u.b[k];
                    i++;
                }
            }


            //escreve o resultado no destino
#ifdef _MSC_VER
            sprintf_s((char*)dest,33u
          #else
            sprintf((char*)dest
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
    if (fileName && dest){
        edk::File file;
        file.openBinFile(fileName);
        if (file.isOpened()){
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
    if (pass && size && dest){
        //processa o MD5
        //md5WikiSum((Md5uint8_t *)pass, size, dest);

        unsigned *d = md5(pass, size);
        WBunion u;

        edk::uint32 i = 0u;
        for (edk::uint32 j=0;j<4; j++){
            u.w = d[j];
            for (edk::uint32 k=0;k<4;k++) {
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

            unsigned *d = md5File(file);
            WBunion u;

            edk::uint32 i = 0u;
            for (edk::uint32 j=0;j<4; j++){
                u.w = d[j];
                for (edk::uint32 k=0;k<4;k++) {
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
    if (fileName && dest){
        edk::File file;
        file.openBinFile(fileName);
        if (file.isOpened()){
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
    if (pass && size){
        //cria a string de retorno
        ret = new edk::char8[33u];
        if (ret){
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
    if (file){
        //cria a string de retorno
        ret = new edk::char8[33u];
        if (ret){
            edk::encrypt::MD5::convertFileTo(file,ret);
        }
    }
    //senao retorna NULL
    return ret;
}
edk::char8* edk::encrypt::MD5::convertFile(edk::char8 *fileName){
    edk::char8* ret=NULL;
    if (fileName){
        edk::File file;
        file.openBinFile(fileName);
        if (file.isOpened()){
            ret = edk::encrypt::MD5::convertFile(&file);
            file.closeFile();
        }
    }
    return ret;
}
edk::char8* edk::encrypt::MD5::convertFile(const edk::char8 *fileName){
    return edk::encrypt::MD5::convertFile((edk::char8 *)fileName);
}
