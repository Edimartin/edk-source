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
        this->size = 0u;
        this->bitSize = 0u;
        this->state[0] = 0x67452301;
        this->state[1] = 0xEFCDAB89;
        this->state[2] = 0x98BADCFE;
        this->state[3] = 0x10325476;
        this->state[4] = 0xc3d2e1f0;
        this->k[0] = 0x5a827999;
        this->k[1] = 0x6ed9eba1;
        this->k[2] = 0x8f1bbcdc;
        this->k[3] = 0xca62c1d6;
    }
    ~SHA1_variables(){}


    void transform(edk::uint8* data){
        edk::uint32 a, b, c, d, e, i, j, t, m[80];

        for (i = 0u, j = 0u; i < 16u; ++i, j += 4u)
            m[i] = (data[j] << 24u) + (data[j + 1u] << 16u) + (data[j + 2u] << 8u) + (data[j + 3u]);
        for ( ; i < 80u; ++i) {
            m[i] = (m[i - 3u] ^ m[i - 8u] ^ m[i - 14u] ^ m[i - 16u]);
            m[i] = (m[i] << 1u) | (m[i] >> 31u);
        }

        a = this->state[0u];
        b = this->state[1u];
        c = this->state[2u];
        d = this->state[3u];
        e = this->state[4u];

        for (i = 0u; i < 20u; ++i) {
            t = rotateLeft(a, 5u) + ((b & c) ^ (~b & d)) + e + this->k[0u] + m[i];
            e = d;
            d = c;
            c = rotateLeft(b, 30u);
            b = a;
            a = t;
        }
        for ( ; i < 40u; ++i) {
            t = rotateLeft(a, 5u) + (b ^ c ^ d) + e + this->k[1] + m[i];
            e = d;
            d = c;
            c = rotateLeft(b, 30u);
            b = a;
            a = t;
        }
        for ( ; i < 60u; ++i) {
            t = rotateLeft(a, 5u) + ((b & c) ^ (b & d) ^ (c & d))  + e + this->k[2u] + m[i];
            e = d;
            d = c;
            c = rotateLeft(b, 30u);
            b = a;
            a = t;
        }
        for ( ; i < 80u; ++i) {
            t = rotateLeft(a, 5u) + (b ^ c ^ d) + e + this->k[3u] + m[i];
            e = d;
            d = c;
            c = rotateLeft(b, 30u);
            b = a;
            a = t;
        }

        this->state[0u] += a;
        this->state[1u] += b;
        this->state[2u] += c;
        this->state[3u] += d;
        this->state[4u] += e;
    }

    //init the SHA1
    void init(){
        //
        this->size = 0u;
        this->bitSize = 0u;
        this->state[0] = 0x67452301;
        this->state[1] = 0xEFCDAB89;
        this->state[2] = 0x98BADCFE;
        this->state[3] = 0x10325476;
        this->state[4] = 0xc3d2e1f0;
        this->k[0] = 0x5a827999;
        this->k[1] = 0x6ed9eba1;
        this->k[2] = 0x8f1bbcdc;
        this->k[3] = 0xca62c1d6;
    }
    //update the SHA1
    void update(edk::uint8* data, edk::uint32 len){
        size_t i;

        for (i = 0; i < len; ++i){
            this->data[this->size] = data[i];
            this->size++;
            if (this->size == 64u) {
                this->transform(this->data);
                this->bitSize += 512u;
                this->size = 0u;
            }
        }
    }
    //finish the SHA1
    void final(edk::uint8* hash){
        edk::uint32 i;

        i = this->size;

        // Pad whatever data is left in the buffer.
        if (this->size < 56) {
            this->data[i++] = 0x80;
            while (i < 56)
                this->data[i++] = 0x00;
        }
        else {
            this->data[i++] = 0x80;
            while (i < 64)
                this->data[i++] = 0x00;
            this->transform(this->data);
            memset(this->data, 0, 56);
        }

        // Append to the padding the total message's length in bits and transform.
        this->bitSize += this->size * 8;
        this->data[63] = this->bitSize;
        this->data[62] = this->bitSize >> 8;
        this->data[61] = this->bitSize >> 16;
        this->data[60] = this->bitSize >> 24;
        this->data[59] = this->bitSize >> 32;
        this->data[58] = this->bitSize >> 40;
        this->data[57] = this->bitSize >> 48;
        this->data[56] = this->bitSize >> 56;
        this->transform(this->data);

        // Since this implementation uses little endian byte ordering and MD uses big endian,
        // reverse all the bytes when copying the final state to the output hash.
        for (i = 0; i < 4; ++i) {
            hash[i]      = (this->state[0] >> (24 - i * 8)) & 0x000000ff;
            hash[i + 4]  = (this->state[1] >> (24 - i * 8)) & 0x000000ff;
            hash[i + 8]  = (this->state[2] >> (24 - i * 8)) & 0x000000ff;
            hash[i + 12] = (this->state[3] >> (24 - i * 8)) & 0x000000ff;
            hash[i + 16] = (this->state[4] >> (24 - i * 8)) & 0x000000ff;
        }
    }
private:
    edk::uint8 data[64u];
    edk::uint32 size;
    edk::uint64 bitSize;
    edk::uint32 state[5u];
    edk::uint32 k[4u];
};
}//end namespace encrypt
}//end namespace edk

edk::encrypt::SHA1::SHA1(){
    //
}
edk::encrypt::SHA1::~SHA1(){
    //
}

bool edk::encrypt::SHA1::convertTo(edk::char8 *pass, edk::uint32 size, edk::char8 *dest){
    //testa as strings e os tamanhos
    if (pass && size && dest){
        edk::encrypt::SHA1_variables sha1;
        //
        edk::uint8 result[20u];
        //prcess the update
        sha1.update((edk::uint8*)pass,size);
        //process the final
        sha1.final(result);

        //write the result in the destiny
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
    //else return false
    return false;
}
bool edk::encrypt::SHA1::convertTo(const edk::char8 *pass, edk::uint32 size, edk::char8 *dest){
    return edk::encrypt::SHA1::convertTo((edk::char8 *)pass, size, dest);
}
bool edk::encrypt::SHA1::convertTo(edk::char8 *pass, edk::char8 *dest){
    return edk::encrypt::SHA1::convertTo(pass,edk::String::strSize(pass),dest);
}
bool edk::encrypt::SHA1::convertTo(const edk::char8 *pass, edk::char8 *dest){
    return edk::encrypt::SHA1::convertTo((edk::char8 *)pass, dest);
}
bool edk::encrypt::SHA1::convertFileTo(edk::File* file, edk::char8 *dest){
    //first test the file and dest
    if(file && dest){
        if(file->isOpened()){
            edk::encrypt::SHA1_variables sha1;
            //
            edk::uint8 result[20u];
            edk::uint8 data[fileReadSize];
            edk::uint64 size = file->getFileSize();
            if(size){
                while(size){
                    if(size>=sizeof(data)){
                        //copy the file in to the memory
                        file->readBin(data,sizeof(data));
                        //process the update
                        sha1.update(data,sizeof(data));
                    }
                    else{
                        //copy the file in to the memory
                        file->readBin(data,size);
                        //process the update
                        sha1.update(data,size);
                    }
                }
            }
            //process the final
            sha1.final(result);

            //write the result in the destiny
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
bool edk::encrypt::SHA1::convertFileTo(edk::char8 *fileName, edk::char8 *dest){
    bool ret = false;
    if (fileName && dest){
        edk::File file;
        file.openBinFile(fileName);
        if (file.isOpened()){
            ret = edk::encrypt::SHA1::convertFileTo(&file,dest);
            file.closeFile();
        }
    }
    return ret;
}
bool edk::encrypt::SHA1::convertFileTo(const edk::char8 *fileName, edk::char8 *dest){
    return edk::encrypt::SHA1::convertFileTo((edk::char8 *)fileName, dest);
}
bool edk::encrypt::SHA1::convertTo(edk::char8 *pass, edk::uint32 size, edk::uint8 dest[20u]){
    //testa as strings e os tamanhos
    if (pass && size && dest){
        edk::encrypt::SHA1_variables sha1;
        //prcess the update
        sha1.update((edk::uint8*)pass,size);
        //process the final
        sha1.final(dest);
        //then return true
        return true;
    }
    //senao retorna false
    return false;
}
bool edk::encrypt::SHA1::convertTo(const edk::char8 *pass, edk::uint32 size, edk::uint8 dest[20u]){
    return edk::encrypt::SHA1::convertTo((edk::char8 *)pass, size, dest);
}
bool edk::encrypt::SHA1::convertTo(edk::char8 *pass, edk::uint8 dest[20u]){
    return edk::encrypt::SHA1::convertTo(pass,edk::String::strSize(pass),dest);
}
bool edk::encrypt::SHA1::convertTo(const edk::char8 *pass, edk::uint8 dest[20u]){
    return edk::encrypt::SHA1::convertTo((edk::char8 *)pass, dest);
}
bool edk::encrypt::SHA1::convertFileTo(edk::File* file, edk::uint8 dest[20u]){
    //first test the file and dest
    if(file && dest){
        if(file->isOpened()){
            edk::encrypt::SHA1_variables sha1;
            //
            edk::uint8 data[fileReadSize];
            edk::uint64 size = file->getFileSize();
            if(size){
                while(size){
                    if(size>=sizeof(data)){
                        //copy the file in to the memory
                        file->readBin(data,sizeof(data));
                        //process the update
                        sha1.update(data,sizeof(data));
                    }
                    else{
                        //copy the file in to the memory
                        file->readBin(data,size);
                        //process the update
                        sha1.update(data,size);
                    }
                }
            }
            //process the final
            sha1.final(dest);
            //then return true
            return true;
        }
    }
    return false;
}
bool edk::encrypt::SHA1::convertFileTo(edk::char8 *fileName, edk::uint8 dest[20u]){
    //
    bool ret = false;
    if (fileName && dest){
        edk::File file;
        file.openBinFile(fileName);
        if (file.isOpened()){
            ret = edk::encrypt::SHA1::convertFileTo(&file,dest);
            file.closeFile();
        }
    }
    return ret;
}
bool edk::encrypt::SHA1::convertFileTo(const edk::char8 *fileName, edk::uint8 dest[20u]){
    return edk::encrypt::SHA1::convertFileTo((edk::char8 *)fileName, dest);
}
edk::char8* edk::encrypt::SHA1::convert(edk::char8 *pass, edk::uint32 size){
    edk::char8* ret=NULL;
    if (pass && size){
        //cria a string de retorno
        ret = new edk::char8[41u];
        if (ret){
            edk::encrypt::SHA1::convertTo(pass, size,ret);
        }
    }
    //senao retorna NULL
    return ret;
}
edk::char8* edk::encrypt::SHA1::convert(const edk::char8 *pass, edk::uint32 size){
    return edk::encrypt::SHA1::convert((edk::char8 *)pass, size);
}
edk::char8* edk::encrypt::SHA1::convert(edk::char8 *pass){
    return edk::encrypt::SHA1::convert(pass, edk::String::strSize(pass));
}
edk::char8* edk::encrypt::SHA1::convert(const edk::char8 *pass){
    return edk::encrypt::SHA1::convert((edk::char8 *)pass);
}
edk::char8* edk::encrypt::SHA1::convertFile(edk::File* file){
    edk::char8* ret=NULL;
    if (file){
        //cria a string de retorno
        ret = new edk::char8[41u];
        if (ret){
            edk::encrypt::SHA1::convertFileTo(file,ret);
        }
    }
    //senao retorna NULL
    return ret;
}
edk::char8* edk::encrypt::SHA1::convertFile(edk::char8 *fileName){
    edk::char8* ret=NULL;
    if (fileName){
        edk::File file;
        file.openBinFile(fileName);
        if (file.isOpened()){
            ret = edk::encrypt::SHA1::convertFile(&file);
            file.closeFile();
        }
    }
    return ret;
}
edk::char8* edk::encrypt::SHA1::convertFile(const edk::char8 *fileName){
    return edk::encrypt::SHA1::convertFile((edk::char8 *)fileName);
}
