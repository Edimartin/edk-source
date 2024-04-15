#include "SHA1.h"

/*
Library C++ SHA1 - Encrypt string in SHA1
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

#define rotateLeft(a, b) ((a << b) | (a >> (32 - b)))

#define fileReadSize 1024u

namespace edk{
namespace encrypt{
class SHA1_variables{
public:
    SHA1_variables(){
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    ~SHA1_variables(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){edkEnd();}
        if(this->classThis!=this){
            this->classThis=this;
            this->init();edkEnd();
        }
    }


    void transform(edk::uint8* data){
        edk::uint32 a, b, c, d, e, i, j, t, m[80];edkEnd();

        for (i = 0u, j = 0u; i < 16u; ++i, j += 4u){
            m[i] = (data[j] << 24u) + (data[j + 1u] << 16u) + (data[j + 2u] << 8u) + (data[j + 3u]);edkEnd();
        }
        for ( ; i < 80u; ++i){
            m[i] = (m[i - 3u] ^ m[i - 8u] ^ m[i - 14u] ^ m[i - 16u]);edkEnd();
            m[i] = (m[i] << 1u) | (m[i] >> 31u);edkEnd();
        }

        a = this->state[0u];edkEnd();
        b = this->state[1u];edkEnd();
        c = this->state[2u];edkEnd();
        d = this->state[3u];edkEnd();
        e = this->state[4u];edkEnd();

        for (i = 0u; i < 20u; ++i){
            t = rotateLeft(a, 5u) + ((b & c) ^ (~b & d)) + e + this->k[0u] + m[i];edkEnd();
            e = d;edkEnd();
            d = c;edkEnd();
            c = rotateLeft(b, 30u);edkEnd();
            b = a;edkEnd();
            a = t;edkEnd();
        }
        for ( ; i < 40u; ++i){
            t = rotateLeft(a, 5u) + (b ^ c ^ d) + e + this->k[1] + m[i];edkEnd();
            e = d;edkEnd();
            d = c;edkEnd();
            c = rotateLeft(b, 30u);edkEnd();
            b = a;edkEnd();
            a = t;edkEnd();
        }
        for ( ; i < 60u; ++i){
            t = rotateLeft(a, 5u) + ((b & c) ^ (b & d) ^ (c & d))  + e + this->k[2u] + m[i];edkEnd();
            e = d;edkEnd();
            d = c;edkEnd();
            c = rotateLeft(b, 30u);edkEnd();
            b = a;edkEnd();
            a = t;edkEnd();
        }
        for ( ; i < 80u; ++i){
            t = rotateLeft(a, 5u) + (b ^ c ^ d) + e + this->k[3u] + m[i];edkEnd();
            e = d;edkEnd();
            d = c;edkEnd();
            c = rotateLeft(b, 30u);edkEnd();
            b = a;edkEnd();
            a = t;edkEnd();
        }

        this->state[0u] += a;edkEnd();
        this->state[1u] += b;edkEnd();
        this->state[2u] += c;edkEnd();
        this->state[3u] += d;edkEnd();
        this->state[4u] += e;edkEnd();
    }

    //init the SHA1
    void init(){
        //
        this->size = 0u;edkEnd();
        this->bitSize = 0u;edkEnd();
        this->state[0] = 0x67452301;edkEnd();
        this->state[1] = 0xEFCDAB89;edkEnd();
        this->state[2] = 0x98BADCFE;edkEnd();
        this->state[3] = 0x10325476;edkEnd();
        this->state[4] = 0xc3d2e1f0;
        this->k[0] = 0x5a827999;edkEnd();
        this->k[1] = 0x6ed9eba1;edkEnd();
        this->k[2] = 0x8f1bbcdc;edkEnd();
        this->k[3] = 0xca62c1d6;edkEnd();
    }
    //update the SHA1
    void update(edk::uint8* data, edk::uint32 len){
        size_t i;edkEnd();

        for (i = 0; i < len; ++i){
            this->data[this->size] = data[i];edkEnd();
            this->size++;edkEnd();
            if(this->size == 64u){
                this->transform(this->data);edkEnd();
                this->bitSize += 512u;edkEnd();
                this->size = 0u;edkEnd();
            }
        }
    }
    //finish the SHA1
    void final(edk::uint8* hash){
        edk::uint32 i;edkEnd();

        i = this->size;edkEnd();

        // Pad whatever data is left in the buffer.
        if(this->size < 56){
            this->data[i++] = 0x80;
            while (i < 56)
                this->data[i++] = 0x00;
        }
        else {
            this->data[i++] = 0x80;
            while (i < 64)
                this->data[i++] = 0x00;
            this->transform(this->data);edkEnd();
            memset(this->data, 0, 56);edkEnd();
        }

        // Append to the padding the total message's length in bits and transform.
        this->bitSize += this->size * 8;edkEnd();
        this->data[63] = this->bitSize;edkEnd();
        this->data[62] = this->bitSize >> 8;edkEnd();
        this->data[61] = this->bitSize >> 16;edkEnd();
        this->data[60] = this->bitSize >> 24;edkEnd();
        this->data[59] = this->bitSize >> 32;edkEnd();
        this->data[58] = this->bitSize >> 40;
        this->data[57] = this->bitSize >> 48;edkEnd();
        this->data[56] = this->bitSize >> 56;edkEnd();
        this->transform(this->data);edkEnd();

        // Since this implementation uses little endian byte ordering and MD uses big endian,
        // reverse all the bytes when copying the final state to the output hash.
        for (i = 0; i < 4; ++i){
            hash[i]      = (this->state[0] >> (24 - i * 8)) & 0x000000ff;edkEnd();
            hash[i + 4]  = (this->state[1] >> (24 - i * 8)) & 0x000000ff;edkEnd();
            hash[i + 8]  = (this->state[2] >> (24 - i * 8)) & 0x000000ff;edkEnd();
            hash[i + 12] = (this->state[3] >> (24 - i * 8)) & 0x000000ff;edkEnd();
            hash[i + 16] = (this->state[4] >> (24 - i * 8)) & 0x000000ff;edkEnd();
        }
    }
private:
    edk::uint8 data[64u];
    edk::uint32 size;
    edk::uint64 bitSize;
    edk::uint32 state[5u];
    edk::uint32 k[4u];
private:
    edk::classID classThis;
};
}//end namespace encrypt
}//end namespace edk

edk::encrypt::SHA1::SHA1(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::encrypt::SHA1::~SHA1(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::encrypt::SHA1::Constructor(bool /*runFather*/){
    //
    if(this->classThis!=this){
        this->classThis=this;
    }
}

bool edk::encrypt::SHA1::convertTo(edk::char8 *pass, edk::uint32 size, edk::char8 *dest){
    //testa as strings e os tamanhos
    if(pass && size && dest){
        edk::encrypt::SHA1_variables sha1;edkEnd();
        //
        edk::uint8 result[20u];edkEnd();
        //prcess the update
        sha1.update((edk::uint8*)pass,size);edkEnd();
        //process the final
        sha1.final(result);edkEnd();

        //write the result in the destiny
#ifdef _MSC_VER
        sprintf_s((char*)dest,41u
          #else
        sprintf((char*)dest
        #endif
                ,"%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x"
                ,result[0],result[1],result[2],result[3],result[4],result[5],result[6],result[7],result[8],result[9],result[10],result[11],result[12],result[13],result[14],result[15]
                ,result[16],result[17],result[18],result[19]
                );edkEnd();
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::encrypt::SHA1::convertTo(const edk::char8 *pass, edk::uint32 size, edk::char8 *dest){
    return edk::encrypt::SHA1::convertTo((edk::char8 *)pass, size, dest);edkEnd();
}
bool edk::encrypt::SHA1::convertTo(edk::char8 *pass, edk::char8 *dest){
    return edk::encrypt::SHA1::convertTo(pass,edk::String::strSize(pass),dest);edkEnd();
}
bool edk::encrypt::SHA1::convertTo(const edk::char8 *pass, edk::char8 *dest){
    return edk::encrypt::SHA1::convertTo((edk::char8 *)pass, dest);edkEnd();
}
bool edk::encrypt::SHA1::convertFileTo(edk::File* file, edk::char8 *dest){
    //first test the file and dest
    if(file && dest){
        if(file->isOpened()){
            edk::encrypt::SHA1_variables sha1;edkEnd();
            //
            edk::uint8 result[20u];edkEnd();
            edk::uint8 data[fileReadSize];edkEnd();
            edk::uint64 size = file->getFileSize();edkEnd();
            if(size){
                while(size){
                    if(size>=sizeof(data)){
                        //copy the file in to the memory
                        file->readBin(data,sizeof(data));edkEnd();
                        //process the update
                        sha1.update(data,sizeof(data));edkEnd();
                    }
                    else{
                        //copy the file in to the memory
                        file->readBin(data,size);edkEnd();
                        //process the update
                        sha1.update(data,size);edkEnd();
                    }
                }
            }
            //process the final
            sha1.final(result);edkEnd();

            //write the result in the destiny
#ifdef _MSC_VER
            sprintf_s((char*)dest,41u
          #else
            sprintf((char*)dest
        #endif
                    ,"%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x"
                    ,result[0],result[1],result[2],result[3],result[4],result[5],result[6],result[7],result[8],result[9],result[10],result[11],result[12],result[13],result[14],result[15]
                    ,result[16],result[17],result[18],result[19]
                    );edkEnd();
            //then return true
            return true;
        }
    }
    return false;
}
bool edk::encrypt::SHA1::convertFileTo(edk::char8 *fileName, edk::char8 *dest){
    bool ret = false;edkEnd();
    if(fileName && dest){
        edk::File file;edkEnd();
        file.openBinFile(fileName);edkEnd();
        if(file.isOpened()){
            ret = edk::encrypt::SHA1::convertFileTo(&file,dest);edkEnd();
            file.closeFile();edkEnd();
        }
    }
    return ret;
}
bool edk::encrypt::SHA1::convertFileTo(const edk::char8 *fileName, edk::char8 *dest){
    return edk::encrypt::SHA1::convertFileTo((edk::char8 *)fileName, dest);edkEnd();
}
bool edk::encrypt::SHA1::convertTo(edk::char8 *pass, edk::uint32 size, edk::uint8 dest[20u]){
    //testa as strings e os tamanhos
    if(pass && size && dest){
        edk::encrypt::SHA1_variables sha1;edkEnd();
        //prcess the update
        sha1.update((edk::uint8*)pass,size);edkEnd();
        //process the final
        sha1.final(dest);edkEnd();
        //then return true
        return true;
    }
    //senao retorna false
    return false;
}
bool edk::encrypt::SHA1::convertTo(const edk::char8 *pass, edk::uint32 size, edk::uint8 dest[20u]){
    return edk::encrypt::SHA1::convertTo((edk::char8 *)pass, size, dest);edkEnd();
}
bool edk::encrypt::SHA1::convertTo(edk::char8 *pass, edk::uint8 dest[20u]){
    return edk::encrypt::SHA1::convertTo(pass,edk::String::strSize(pass),dest);edkEnd();
}
bool edk::encrypt::SHA1::convertTo(const edk::char8 *pass, edk::uint8 dest[20u]){
    return edk::encrypt::SHA1::convertTo((edk::char8 *)pass, dest);edkEnd();
}
bool edk::encrypt::SHA1::convertFileTo(edk::File* file, edk::uint8 dest[20u]){
    //first test the file and dest
    if(file && dest){
        if(file->isOpened()){
            edk::encrypt::SHA1_variables sha1;edkEnd();
            //
            edk::uint8 data[fileReadSize];edkEnd();
            edk::uint64 size = file->getFileSize();edkEnd();
            if(size){
                while(size){
                    if(size>=sizeof(data)){
                        //copy the file in to the memory
                        file->readBin(data,sizeof(data));edkEnd();
                        //process the update
                        sha1.update(data,sizeof(data));edkEnd();
                    }
                    else{
                        //copy the file in to the memory
                        file->readBin(data,size);edkEnd();
                        //process the update
                        sha1.update(data,size);edkEnd();
                    }
                }
            }
            //process the final
            sha1.final(dest);edkEnd();
            //then return true
            return true;
        }
    }
    return false;
}
bool edk::encrypt::SHA1::convertFileTo(edk::char8 *fileName, edk::uint8 dest[20u]){
    //
    bool ret = false;edkEnd();
    if(fileName && dest){
        edk::File file;edkEnd();
        file.openBinFile(fileName);edkEnd();
        if(file.isOpened()){
            ret = edk::encrypt::SHA1::convertFileTo(&file,dest);edkEnd();
            file.closeFile();edkEnd();
        }
    }
    return ret;
}
bool edk::encrypt::SHA1::convertFileTo(const edk::char8 *fileName, edk::uint8 dest[20u]){
    return edk::encrypt::SHA1::convertFileTo((edk::char8 *)fileName, dest);edkEnd();
}
edk::char8* edk::encrypt::SHA1::convert(edk::char8 *pass, edk::uint32 size){
    edk::char8* ret=NULL;edkEnd();
    if(pass && size){
        //cria a string de retorno
        ret = (edk::char8*)malloc(sizeof(edk::char8) * (41u));edkEnd();
        if(ret){
            edk::encrypt::SHA1::convertTo(pass, size,ret);edkEnd();
        }
    }
    //senao retorna NULL
    return ret;
}
edk::char8* edk::encrypt::SHA1::convert(const edk::char8 *pass, edk::uint32 size){
    return edk::encrypt::SHA1::convert((edk::char8 *)pass, size);edkEnd();
}
edk::char8* edk::encrypt::SHA1::convert(edk::char8 *pass){
    return edk::encrypt::SHA1::convert(pass, edk::String::strSize(pass));edkEnd();
}
edk::char8* edk::encrypt::SHA1::convert(const edk::char8 *pass){
    return edk::encrypt::SHA1::convert((edk::char8 *)pass);edkEnd();
}
edk::char8* edk::encrypt::SHA1::convertFile(edk::File* file){
    edk::char8* ret=NULL;edkEnd();
    if(file){
        //cria a string de retorno
        ret = (edk::char8*)malloc(sizeof(edk::char8) * (41u));edkEnd();
        if(ret){
            edk::encrypt::SHA1::convertFileTo(file,ret);edkEnd();
        }
    }
    //senao retorna NULL
    return ret;
}
edk::char8* edk::encrypt::SHA1::convertFile(edk::char8 *fileName){
    edk::char8* ret=NULL;edkEnd();
    if(fileName){
        edk::File file;edkEnd();
        file.openBinFile(fileName);edkEnd();
        if(file.isOpened()){
            ret = edk::encrypt::SHA1::convertFile(&file);edkEnd();
            file.closeFile();edkEnd();
        }
    }
    return ret;
}
edk::char8* edk::encrypt::SHA1::convertFile(const edk::char8 *fileName){
    return edk::encrypt::SHA1::convertFile((edk::char8 *)fileName);edkEnd();
}
