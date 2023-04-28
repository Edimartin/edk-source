#include "SHA256.h"

/*
Library C++ SHA256 - Encrypt string in SHA256
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

#define rotateLeft(a,b) (((a) << (b)) | ((a) >> (32u-(b))))
#define rotateRight(a,b) (((a) >> (b)) | ((a) << (32u-(b))))

#define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define EP0(x) (rotateRight(x,2u) ^ rotateRight(x,13u) ^ rotateRight(x,22u))
#define EP1(x) (rotateRight(x,6u) ^ rotateRight(x,11u) ^ rotateRight(x,25u))
#define SIG0(x) (rotateRight(x,7u) ^ rotateRight(x,18u) ^ ((x) >> 3u))
#define SIG1(x) (rotateRight(x,17u) ^ rotateRight(x,19u) ^ ((x) >> 10u))

#define fileReadSize 1024u

static const edk::uint32 k[64u] = {
    0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
    0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
    0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
    0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
    0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
    0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
    0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
    0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
};

namespace edk{
namespace encrypt{
class SHA256_variables{
public:
    SHA256_variables(){
        this->init();edkEnd();
    }
    ~SHA256_variables(){}


    void transform(edk::uint8* data){
        edk::uint32 a, b, c, d, e, f, g, h, i, j, t1, t2, m[64u];edkEnd();

        for (i = 0u, j = 0u; i < 16u; ++i, j += 4u){
            m[i] = (data[j] << 24u) | (data[j + 1u] << 16u) | (data[j + 2u] << 8u) | (data[j + 3u]);edkEnd();
        }
        for ( ; i < 64u; ++i){
            m[i] = SIG1(m[i - 2u]) + m[i - 7u] + SIG0(m[i - 15u]) + m[i - 16u];edkEnd();
        }

        a = this->state[0u];edkEnd();
        b = this->state[1u];edkEnd();
        c = this->state[2u];edkEnd();
        d = this->state[3u];edkEnd();
        e = this->state[4u];edkEnd();
        f = this->state[5u];edkEnd();
        g = this->state[6u];edkEnd();
        h = this->state[7u];edkEnd();

        for (i = 0u; i < 64u; ++i){
            t1 = h + EP1(e) + CH(e,f,g) + k[i] + m[i];edkEnd();
            t2 = EP0(a) + MAJ(a,b,c);edkEnd();
            h = g;edkEnd();
            g = f;edkEnd();
            f = e;edkEnd();
            e = d + t1;edkEnd();
            d = c;edkEnd();
            c = b;edkEnd();
            b = a;edkEnd();
            a = t1 + t2;edkEnd();
        }

        this->state[0u] += a;edkEnd();
        this->state[1u] += b;edkEnd();
        this->state[2u] += c;edkEnd();
        this->state[3u] += d;edkEnd();
        this->state[4u] += e;edkEnd();
        this->state[5u] += f;edkEnd();
        this->state[6u] += g;edkEnd();
        this->state[7u] += h;edkEnd();
    }

    //init the SHA256
    void init(){
        //
        this->size = 0u;edkEnd();
        this->bitSize = 0u;edkEnd();
        this->state[0u] = 0x6a09e667;edkEnd();
        this->state[1u] = 0xbb67ae85;edkEnd();
        this->state[2u] = 0x3c6ef372;edkEnd();
        this->state[3u] = 0xa54ff53a;edkEnd();
        this->state[4u] = 0x510e527f;edkEnd();
        this->state[5u] = 0x9b05688c;edkEnd();
        this->state[6u] = 0x1f83d9ab;edkEnd();
        this->state[7u] = 0x5be0cd19;edkEnd();
    }
    //update the SHA256
    void update(edk::uint8* data, edk::uint32 len){
        edk::uint32 i;edkEnd();

        for (i = 0u; i < len; ++i){
            this->data[this->size] = data[i];edkEnd();
            this->size++;edkEnd();
            if(this->size == 64u){
                this->transform(this->data);edkEnd();
                this->bitSize += 512u;edkEnd();
                this->size = 0u;edkEnd();
            }
        }
    }
    //finish the SHA256
    void final(edk::uint8* hash){
        edk::uint32 i;edkEnd();

        i = this->size;edkEnd();

        // Pad whatever data is left in the buffer.
        if(this->size < 56u){
            this->data[i++] = 0x80;
            while (i < 56u)
                this->data[i++] = 0x00;
        }
        else {
            this->data[i++] = 0x80;
            while (i < 64u){
                this->data[i++] = 0x00;
            }
            this->transform(this->data);edkEnd();
            memset(this->data, 0, 56u);edkEnd();
        }

        // Append to the padding the total message's length in bits and transform.
        this->bitSize += this->size * 8u;edkEnd();
        this->data[63u] = this->bitSize;edkEnd();
        this->data[62u] = this->bitSize >> 8u;edkEnd();
        this->data[61u] = this->bitSize >> 16u;edkEnd();
        this->data[60u] = this->bitSize >> 24u;edkEnd();
        this->data[59u] = this->bitSize >> 32u;edkEnd();
        this->data[58u] = this->bitSize >> 40u;edkEnd();
        this->data[57u] = this->bitSize >> 48u;edkEnd();
        this->data[56u] = this->bitSize >> 56u;edkEnd();
        this->transform(this->data);edkEnd();

        // Since this implementation uses little endian byte ordering and SHA uses big endian,
        // reverse all the bytes when copying the final state to the output hash.
        for (i = 0u; i < 4u; ++i){
            hash[i]      = (this->state[0] >> (24u - i * 8u)) & 0x000000ff;edkEnd();
            hash[i + 4u]  = (this->state[1] >> (24u - i * 8u)) & 0x000000ff;edkEnd();
            hash[i + 8u]  = (this->state[2] >> (24u - i * 8u)) & 0x000000ff;edkEnd();
            hash[i + 12u] = (this->state[3] >> (24u - i * 8u)) & 0x000000ff;edkEnd();
            hash[i + 16u] = (this->state[4] >> (24u - i * 8u)) & 0x000000ff;edkEnd();
            hash[i + 20u] = (this->state[5] >> (24u - i * 8u)) & 0x000000ff;edkEnd();
            hash[i + 24u] = (this->state[6] >> (24u - i * 8u)) & 0x000000ff;edkEnd();
            hash[i + 28u] = (this->state[7] >> (24u - i * 8u)) & 0x000000ff;edkEnd();
        }
    }
private:
    edk::uint8 data[64u];
    edk::uint32 size;
    edk::uint64 bitSize;
    edk::uint32 state[8u];
};
}//end namespace encrypt
}//end namespace edk



edk::encrypt::SHA256::SHA256(){
    //
}
edk::encrypt::SHA256::~SHA256(){
    //
}

bool edk::encrypt::SHA256::convertTo(edk::char8 *pass, edk::uint32 size, edk::char8 *dest){
    //testa as strings e os tamanhos
    if(pass && size && dest){
        edk::encrypt::SHA256_variables SHA256;edkEnd();
        //
        edk::uint8 result[32u];edkEnd();
        //prcess the update
        SHA256.update((edk::uint8*)pass,size);edkEnd();
        //process the final
        SHA256.final(result);edkEnd();

        //write the result in the destiny
#ifdef _MSC_VER
        sprintf_s((edk::char8*)dest,65u
          #else
        sprintf((edk::char8*)dest
        #endif
                ,"%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x"
                "%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x"
                ,result[0],result[1],result[2],result[3],result[4],result[5],result[6],result[7],result[8],result[9],result[10],result[11],result[12],result[13],result[14],result[15]
                ,result[16],result[17],result[18],result[19],result[20],result[21],result[22],result[23],result[24],result[25],result[26],result[27],result[28],result[29],result[30]
                ,result[31]
                );edkEnd();
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::encrypt::SHA256::convertTo(const edk::char8 *pass, edk::uint32 size, edk::char8 *dest){
    return edk::encrypt::SHA256::convertTo((edk::char8 *)pass, size, dest);edkEnd();
}
bool edk::encrypt::SHA256::convertTo(edk::char8 *pass, edk::char8 *dest){
    return edk::encrypt::SHA256::convertTo(pass,edk::String::strSize(pass),dest);edkEnd();
}
bool edk::encrypt::SHA256::convertTo(const edk::char8 *pass, edk::char8 *dest){
    return edk::encrypt::SHA256::convertTo((edk::char8 *)pass, dest);edkEnd();
}
bool edk::encrypt::SHA256::convertFileTo(edk::File* file, edk::char8 *dest){
    //first test the file and dest
    if(file && dest){
        if(file->isOpened()){
            edk::encrypt::SHA256_variables SHA256;edkEnd();
            //
            edk::uint8 result[32u];edkEnd();
            edk::uint8 data[fileReadSize];edkEnd();
            edk::uint64 size = file->getFileSize();edkEnd();
            if(size){
                while(size){
                    if(size>=sizeof(data)){
                        //copy the file in to the memory
                        file->readBin(data,sizeof(data));edkEnd();
                        //process the update
                        SHA256.update(data,sizeof(data));edkEnd();
                    }
                    else{
                        //copy the file in to the memory
                        file->readBin(data,size);edkEnd();
                        //process the update
                        SHA256.update(data,size);edkEnd();
                    }
                }
            }
            //process the final
            SHA256.final(result);edkEnd();

            //write the result in the destiny
    #ifdef _MSC_VER
            sprintf_s((edk::char8*)dest,65u
              #else
            sprintf((edk::char8*)dest
            #endif
                    ,"%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x"
                    "%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x"
                    ,result[0],result[1],result[2],result[3],result[4],result[5],result[6],result[7],result[8],result[9],result[10],result[11],result[12],result[13],result[14],result[15]
                    ,result[16],result[17],result[18],result[19],result[20],result[21],result[22],result[23],result[24],result[25],result[26],result[27],result[28],result[29],result[30]
                    ,result[31]
                    );edkEnd();
            //then return true
            return true;
        }
    }
    return false;
}
bool edk::encrypt::SHA256::convertFileTo(edk::char8 *fileName, edk::char8 *dest){
    bool ret = false;edkEnd();
    if(fileName && dest){
        edk::File file;edkEnd();
        file.openBinFile(fileName);edkEnd();
        if(file.isOpened()){
            ret = edk::encrypt::SHA256::convertFileTo(&file,dest);edkEnd();
            file.closeFile();edkEnd();
        }
    }
    return ret;
}
bool edk::encrypt::SHA256::convertFileTo(const edk::char8 *fileName, edk::char8 *dest){
    return edk::encrypt::SHA256::convertFileTo((edk::char8 *)fileName, dest);edkEnd();
}
bool edk::encrypt::SHA256::convertTo(edk::char8 *pass, edk::uint32 size, edk::uint8 dest[32u]){
    //testa as strings e os tamanhos
    if(pass && size && dest){
        edk::encrypt::SHA256_variables SHA256;edkEnd();
        //prcess the update
        SHA256.update((edk::uint8*)pass,size);edkEnd();
        //process the final
        SHA256.final(dest);edkEnd();
        //then return true
        return true;
    }
    //senao retorna false
    return false;
}
bool edk::encrypt::SHA256::convertTo(const edk::char8 *pass, edk::uint32 size, edk::uint8 dest[32u]){
    return edk::encrypt::SHA256::convertTo((edk::char8 *)pass, size, dest);edkEnd();
}
bool edk::encrypt::SHA256::convertTo(edk::char8 *pass, edk::uint8 dest[32u]){
    return edk::encrypt::SHA256::convertTo(pass,edk::String::strSize(pass),dest);edkEnd();
}
bool edk::encrypt::SHA256::convertTo(const edk::char8 *pass, edk::uint8 dest[32u]){
    return edk::encrypt::SHA256::convertTo((edk::char8 *)pass, dest);edkEnd();
}
bool edk::encrypt::SHA256::convertFileTo(edk::File* file, edk::uint8 dest[32u]){
    //first test the file and dest
    if(file && dest){
        if(file->isOpened()){
            edk::encrypt::SHA256_variables SHA256;edkEnd();
            //
            edk::uint8 data[fileReadSize];edkEnd();
            edk::uint64 size = file->getFileSize();edkEnd();
            if(size){
                while(size){
                    if(size>=sizeof(data)){
                        //copy the file in to the memory
                        file->readBin(data,sizeof(data));edkEnd();
                        //process the update
                        SHA256.update(data,sizeof(data));edkEnd();
                    }
                    else{
                        //copy the file in to the memory
                        file->readBin(data,size);edkEnd();
                        //process the update
                        SHA256.update(data,size);edkEnd();
                    }
                }
            }
            //process the final
            SHA256.final(dest);edkEnd();
            //then return true
            return true;
        }
    }
    return false;
}
bool edk::encrypt::SHA256::convertFileTo(edk::char8 *fileName, edk::uint8 dest[32u]){
    //
    bool ret = false;edkEnd();
    if(fileName && dest){
        edk::File file;edkEnd();
        file.openBinFile(fileName);edkEnd();
        if(file.isOpened()){
            ret = edk::encrypt::SHA256::convertFileTo(&file,dest);edkEnd();
            file.closeFile();edkEnd();
        }
    }
    return ret;
}
bool edk::encrypt::SHA256::convertFileTo(const edk::char8 *fileName, edk::uint8 dest[32u]){
    return edk::encrypt::SHA256::convertFileTo((edk::char8 *)fileName, dest);edkEnd();
}
edk::char8* edk::encrypt::SHA256::convert(edk::char8 *pass, edk::uint32 size){
    edk::char8* ret=NULL;edkEnd();
    if(pass && size){
        //cria a string de retorno
        ret = (edk::char8*)malloc(sizeof(edk::char8) * (65u));edkEnd();
        if(ret){
            edk::encrypt::SHA256::convertTo(pass, size,ret);edkEnd();
        }
    }
    //senao retorna NULL
    return ret;
}
edk::char8* edk::encrypt::SHA256::convert(const edk::char8 *pass, edk::uint32 size){
    return edk::encrypt::SHA256::convert((edk::char8 *)pass, size);edkEnd();
}
edk::char8* edk::encrypt::SHA256::convert(edk::char8 *pass){
    return edk::encrypt::SHA256::convert(pass, edk::String::strSize(pass));edkEnd();
}
edk::char8* edk::encrypt::SHA256::convert(const edk::char8 *pass){
    return edk::encrypt::SHA256::convert((edk::char8 *)pass);edkEnd();
}
edk::char8* edk::encrypt::SHA256::convertFile(edk::File* file){
    edk::char8* ret=NULL;edkEnd();
    if(file){
        //cria a string de retorno
        ret = (edk::char8*)malloc(sizeof(edk::char8) * (65u));edkEnd();
        if(ret){
            edk::encrypt::SHA256::convertFileTo(file,ret);edkEnd();
        }
    }
    //senao retorna NULL
    return ret;
}
edk::char8* edk::encrypt::SHA256::convertFile(edk::char8 *fileName){
    edk::char8* ret=NULL;edkEnd();
    if(fileName){
        edk::File file;edkEnd();
        file.openBinFile(fileName);edkEnd();
        if(file.isOpened()){
            ret = edk::encrypt::SHA256::convertFile(&file);edkEnd();
            file.closeFile();edkEnd();
        }
    }
    return ret;
}
edk::char8* edk::encrypt::SHA256::convertFile(const edk::char8 *fileName){
    return edk::encrypt::SHA256::convertFile((edk::char8 *)fileName);edkEnd();
}
