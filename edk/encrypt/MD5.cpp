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

typedef unsigned int Md5uint32_t;
typedef unsigned char Md5uint8_t;
// Constants are the integer part of the sines of integers (in radians) * 2^32.
const Md5uint32_t k[64] = {
0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee ,
0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501 ,
0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be ,
0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821 ,
0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa ,
0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8 ,
0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed ,
0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a ,
0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c ,
0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70 ,
0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05 ,
0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665 ,
0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039 ,
0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1 ,
0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1 ,
0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391 };

// r specifies the per-round shift amounts
const Md5uint32_t r[] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
                      5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
                      4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
                      6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

// leftrotate function definition
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

void to_bytes(Md5uint32_t val, Md5uint8_t *bytes)
{
    bytes[0] = (Md5uint8_t) val;
    bytes[1] = (Md5uint8_t) (val >> 8);
    bytes[2] = (Md5uint8_t) (val >> 16);
    bytes[3] = (Md5uint8_t) (val >> 24);
}

Md5uint32_t to_int32(const Md5uint8_t *bytes)
{
    return (Md5uint32_t) bytes[0]
        | ((Md5uint32_t) bytes[1] << 8)
        | ((Md5uint32_t) bytes[2] << 16)
        | ((Md5uint32_t) bytes[3] << 24);
}

void md5Wiki(const Md5uint8_t *initial_msg, size_t initial_len, Md5uint8_t *digest) {

    // These vars will contain the hash
    Md5uint32_t h0, h1, h2, h3;

    // Message (to prepare)
    Md5uint8_t *msg = NULL;

    size_t new_len, offset;
    Md5uint32_t w[16];
    Md5uint32_t a, b, c, d, i, f, g, temp;

    // Initialize variables - simple count in nibbles:
    h0 = 0x67452301;
    h1 = 0xefcdab89;
    h2 = 0x98badcfe;
    h3 = 0x10325476;

    //Pre-processing:
    //append "1" bit to message
    //append "0" bits until message length in bits ≡ 448 (mod 512)
    //append length mod (2^64) to message

    for (new_len = initial_len + 1; new_len % (512/8) != 448/8; new_len++)
        ;
#ifdef __cplusplus
    msg = new Md5uint8_t[new_len + 8];
#else
    msg = (Md5uint8_t*)malloc(new_len + 8);
#endif
    memcpy(msg, initial_msg, initial_len);
    msg[initial_len] = 0x80; // append the "1" bit; most significant bit is "first"
    for (offset = initial_len + 1; offset < new_len; offset++)
        msg[offset] = 0; // append "0" bits

    // append the len in bits at the end of the buffer.
    to_bytes(initial_len*8, msg + new_len);
    // initial_len>>29 == initial_len*8>>32, but avoids overflow.
    to_bytes(initial_len>>29, msg + new_len + 4);

    // Process the message in successive 512-bit chunks:
    //for each 512-bit chunk of message:
    for(offset=0; offset<new_len; offset += (512/8)) {

        // break chunk into sixteen 32-bit words w[j], 0 ≤ j ≤ 15
        for (i = 0; i < 16; i++)
            w[i] = to_int32(msg + offset + i*4);

        // Initialize hash value for this chunk:
        a = h0;
        b = h1;
        c = h2;
        d = h3;

        // Main loop:
        for(i = 0; i<64; i++) {

            if (i < 16) {
                f = (b & c) | ((~b) & d);
                g = i;
            } else if (i < 32) {
                f = (d & b) | ((~d) & c);
                g = (5*i + 1) % 16;
            } else if (i < 48) {
                f = b ^ c ^ d;
                g = (3*i + 5) % 16;
            } else {
                f = c ^ (b | (~d));
                g = (7*i) % 16;
            }

            temp = d;
            d = c;
            c = b;
            b = b + LEFTROTATE((a + f + k[i] + w[g]), r[i]);
            a = temp;

        }

        // Add this chunk's hash to result so far:
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;

    }

    // cleanup
#ifdef __cplusplus
    delete msg;
#else
    free(msg);
#endif

    //var char digest[16] := h0 append h1 append h2 append h3 //(Output is in little-endian)
    to_bytes(h0, digest);
    to_bytes(h1, digest + 4);
    to_bytes(h2, digest + 8);
    to_bytes(h3, digest + 12);
}

//processa o MD5
bool edk::encrypt::MD5::convertTo(edk::char8 *pass, edk::uint32 size, edk::char8 *dest){
    //testa as strings e os tamanhos
    if (pass && size && dest){
        //processa o MD5
        unsigned char result[16];
        md5Wiki((Md5uint8_t *)pass, size, result);
        //escreve o resultado no destino
#ifdef _MSC_VER
        sprintf_s((char*)dest,33u
#else
        sprintf((char*)dest
#endif
        ,"%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x"
        ,result[0],result[1],result[2],result[3],result[4],result[5],result[6],result[7],result[8],result[9],result[10],result[11],result[12],result[13],result[14],result[15]);
    }
    //senao retorna false
    return false;
}
bool edk::encrypt::MD5::convertTo(const char *pass, edk::uint32 size, edk::char8 *dest){
    return edk::encrypt::MD5::convertTo((edk::char8 *)pass, size, dest);
}
bool edk::encrypt::MD5::convertTo(edk::char8 *pass, edk::char8 *dest){
    return edk::encrypt::MD5::convertTo(pass,edk::String::strSize(pass),dest);
}
bool edk::encrypt::MD5::convertTo(const char *pass, edk::char8 *dest){
    return edk::encrypt::MD5::convertTo((edk::char8 *)pass, dest);
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
edk::char8* edk::encrypt::MD5::convert(const char *pass, edk::uint32 size){
    return edk::encrypt::MD5::convert((edk::char8 *)pass, size);
}
edk::char8* edk::encrypt::MD5::convert(edk::char8 *pass){
    return edk::encrypt::MD5::convert(pass, edk::String::strSize(pass));
}
edk::char8* edk::encrypt::MD5::convert(const char *pass){
    return edk::encrypt::MD5::convert((edk::char8 *)pass);
}