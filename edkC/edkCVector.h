#ifndef EDKVECTOR_H
#define EDKVECTOR_H

static inline void edkC_Nothing(){}

#ifdef __cplusplus
extern "C" {
#endif

#include "edkCTypes.h"
#include <stdlib.h>
#include <string.h>

#define edkVecHaveVec(temp) (temp.vec && temp.lenght)
#define edkVecHavePosition(temp,position) (edkVecHaveVec(temp) && position < temp.lenght)
#define edkVecSet(temp,position,value,success) \
    if(edkVecHavePosition(vec,position)){temp.vec[position]=value;*success = true;} \
    else{*success = false;} \
    edkC_Nothing()
#define edkVecGet(temp,position,value,success) \
    if(edkVecHavePosition(vec,position)){*value = temp.vec[position];*success = true;} \
    else{memset(value,0u,sizeof(*value));*success = false;} \
    edkC_Nothing()


//implement the code

//vector structs
//CHAR
struct STRUCT_edkVecChar8{
    edkChar8*  vec;
    edkUInt64 lenght;
};
#define edkVecChar8 struct STRUCT_edkVecChar8
struct STRUCT_edkVecChar16{
    edkChar16* vec;
    edkUInt64 lenght;
};
#define edkVecChar16 struct STRUCT_edkVecChar16
struct STRUCT_edkVecChar32{
    edkChar32* vec;
    edkUInt64 lenght;
};
#define edkVecChar32 struct STRUCT_edkVecChar32
struct STRUCT_edkVecChar64{
    edkChar64* vec;
    edkUInt64 lenght;
};
#define edkVecChar64 struct STRUCT_edkVecChar64
//UCHAR
struct STRUCT_edkVecUChar8{
    edkUChar8*  vec;
    edkUInt64 lenght;
};
#define edkVecUChar8 struct STRUCT_edkVecUChar8
struct STRUCT_edkVecUChar16{
    edkUChar16* vec;
    edkUInt64 lenght;
};
#define edkVecUChar16 struct STRUCT_edkVecUChar16
struct STRUCT_edkVecUChar32{
    edkUChar32* vec;
    edkUInt64 lenght;
};
#define edkVecUChar32 struct STRUCT_edkVecUChar32
struct STRUCT_edkVecUChar64{
    edkUChar64* vec;
    edkUInt64 lenght;
};
#define edkVecUChar64 struct STRUCT_edkVecUChar64
//INT
struct STRUCT_edkVecInt8{
    edkInt8*  vec;
    edkUInt64 lenght;
};
#define edkVecInt8 struct STRUCT_edkVecInt8
struct STRUCT_edkVecInt16{
    edkInt16* vec;
    edkUInt64 lenght;
};
#define edkVecInt16 struct STRUCT_edkVecInt16
struct STRUCT_edkVecInt32{
    edkInt32* vec;
    edkUInt64 lenght;
};
#define edkVecInt32 struct STRUCT_edkVecInt32
struct STRUCT_edkVecInt64{
    edkInt64* vec;
    edkUInt64 lenght;
};
#define edkVecInt64 struct STRUCT_edkVecInt64
//UINT
struct STRUCT_edkVecUInt8{
    edkUInt8*  vec;
    edkUInt64 lenght;
};
#define edkVecUInt8 struct STRUCT_edkVecUInt8
struct STRUCT_edkVecUInt16{
    edkUInt16* vec;
    edkUInt64 lenght;
};
#define edkVecUInt16 struct STRUCT_edkVecUInt16
struct STRUCT_edkVecUInt32{
    edkUInt32* vec;
    edkUInt64 lenght;
};
#define edkVecUInt32 struct STRUCT_edkVecUInt32
struct STRUCT_edkVecUInt64{
    edkUInt64* vec;
    edkUInt64 lenght;
};
#define edkVecUInt64 struct STRUCT_edkVecUInt64

//create the vector
//UCHAR8
edkVecUChar8 edkVecUChar8Construct();
edkVecUChar8 edkConstructVecUChar8();
edkVecUChar8* edkVecUChar8New();
edkVecUChar8* edkNewVecUChar8();
edkVecUChar8 edkVecUChar8Construct_UInt64(edkUInt64 lenght);
edkVecUChar8 edkConstructVecUChar8_UInt64(edkUInt64 lenght);
edkVecUChar8* edkVecUChar8New_UInt64(edkUInt64 lenght);
edkVecUChar8* edkNewVecUChar8_UInt64(edkUInt64 lenght);
//UCHAR16
edkVecUChar16 edkVecUChar16Construct();
edkVecUChar16 edkConstructVecUChar16();
edkVecUChar16* edkVecUChar16New();
edkVecUChar16* edkNewVecUChar16();
edkVecUChar16 edkVecUChar16Construct_UInt64(edkUInt64 lenght);
edkVecUChar16 edkConstructVecUChar16_UInt64(edkUInt64 lenght);
edkVecUChar16* edkVecUChar16New_UInt64(edkUInt64 lenght);
edkVecUChar16* edkNewVecUChar16_UInt64(edkUInt64 lenght);
//UCHAR32
edkVecUChar32 edkVecUChar32Construct();
edkVecUChar32 edkConstructVecUChar32();
edkVecUChar32* edkVecUChar32New();
edkVecUChar32* edkNewVecUChar32();
edkVecUChar32 edkVecUChar32Construct_UInt64(edkUInt64 lenght);
edkVecUChar32 edkConstructVecUChar32_UInt64(edkUInt64 lenght);
edkVecUChar32* edkVecUChar32New_UInt64(edkUInt64 lenght);
edkVecUChar32* edkNewVecUChar32_UInt64(edkUInt64 lenght);
//UCHAR64
edkVecUChar64 edkVecUChar64Construct();
edkVecUChar64 edkConstructVecUChar64();
edkVecUChar64* edkVecUChar64New();
edkVecUChar64* edkNewVecUChar64();
edkVecUChar64 edkVecUChar64Construct_UInt64(edkUInt64 lenght);
edkVecUChar64 edkConstructVecUChar64_UInt64(edkUInt64 lenght);
edkVecUChar64* edkVecUChar64New_UInt64(edkUInt64 lenght);
edkVecUChar64* edkNewVecUChar64_UInt64(edkUInt64 lenght);
//CHAR8
edkVecChar8 edkVecChar8Construct();
edkVecChar8 edkConstructVecChar8();
edkVecChar8* edkVecChar8New();
edkVecChar8* edkNewVecChar8();
edkVecChar8 edkVecChar8Construct_UInt64(edkUInt64 lenght);
edkVecChar8 edkConstructVecChar8_UInt64(edkUInt64 lenght);
edkVecChar8* edkVecChar8New_UInt64(edkUInt64 lenght);
edkVecChar8* edkNewVecChar8_UInt64(edkUInt64 lenght);
//CHAR16
edkVecChar16 edkVecChar16Construct();
edkVecChar16 edkConstructVecChar16();
edkVecChar16* edkVecChar16New();
edkVecChar16* edkNewVecChar16();
edkVecChar16 edkVecChar16Construct_UInt64(edkUInt64 lenght);
edkVecChar16 edkConstructVecChar16_UInt64(edkUInt64 lenght);
edkVecChar16* edkVecChar16New_UInt64(edkUInt64 lenght);
edkVecChar16* edkNewVecChar16_UInt64(edkUInt64 lenght);
//CHAR32
edkVecChar32 edkVecChar32Construct();
edkVecChar32 edkConstructVecChar32();
edkVecChar32* edkVecChar32New();
edkVecChar32* edkNewVecChar32();
edkVecChar32 edkVecChar32Construct_UInt64(edkUInt64 lenght);
edkVecChar32 edkConstructVecChar32_UInt64(edkUInt64 lenght);
edkVecChar32* edkVecChar32New_UInt64(edkUInt64 lenght);
edkVecChar32* edkNewVecChar32_UInt64(edkUInt64 lenght);
//CHAR64
edkVecChar64 edkVecChar64Construct();
edkVecChar64 edkConstructVecChar64();
edkVecChar64* edkVecChar64New();
edkVecChar64* edkNewVecChar64();
edkVecChar64 edkVecChar64Construct_UInt64(edkUInt64 lenght);
edkVecChar64 edkConstructVecChar64_UInt64(edkUInt64 lenght);
edkVecChar64* edkVecChar64New_UInt64(edkUInt64 lenght);
edkVecChar64* edkNewVecChar64_UInt64(edkUInt64 lenght);
//UINT8
edkVecUInt8 edkVecUInt8Construct();
edkVecUInt8 edkConstructVecUInt8();
edkVecUInt8* edkVecUInt8New();
edkVecUInt8* edkNewVecUInt8();
edkVecUInt8 edkVecUInt8Construct_UInt64(edkUInt64 lenght);
edkVecUInt8 edkConstructVecUInt8_UInt64(edkUInt64 lenght);
edkVecUInt8* edkVecUInt8New_UInt64(edkUInt64 lenght);
edkVecUInt8* edkNewVecUInt8_UInt64(edkUInt64 lenght);
//UINT16
edkVecUInt16 edkVecUInt16Construct();
edkVecUInt16 edkConstructVecUInt16();
edkVecUInt16* edkVecUInt16New();
edkVecUInt16* edkNewVecUInt16();
edkVecUInt16 edkVecUInt16Construct_UInt64(edkUInt64 lenght);
edkVecUInt16 edkConstructVecUInt16_UInt64(edkUInt64 lenght);
edkVecUInt16* edkVecUInt16New_UInt64(edkUInt64 lenght);
edkVecUInt16* edkNewVecUInt16_UInt64(edkUInt64 lenght);
//UINT32
edkVecUInt32 edkVecUInt32Construct();
edkVecUInt32 edkConstructVecUInt32();
edkVecUInt32* edkVecUInt32New();
edkVecUInt32* edkNewVecUInt32();
edkVecUInt32 edkVecUInt32Construct_UInt64(edkUInt64 lenght);
edkVecUInt32 edkConstructVecUInt32_UInt64(edkUInt64 lenght);
edkVecUInt32* edkVecUInt32New_UInt64(edkUInt64 lenght);
edkVecUInt32* edkNewVecUInt32_UInt64(edkUInt64 lenght);
//UINT64
edkVecUInt64 edkVecUInt64Construct();
edkVecUInt64 edkConstructVecUInt64();
edkVecUInt64* edkVecUInt64New();
edkVecUInt64* edkNewVecUInt64();
edkVecUInt64 edkVecUInt64Construct_UInt64(edkUInt64 lenght);
edkVecUInt64 edkConstructVecUInt64_UInt64(edkUInt64 lenght);
edkVecUInt64* edkVecUInt64New_UInt64(edkUInt64 lenght);
edkVecUInt64* edkNewVecUInt64_UInt64(edkUInt64 lenght);
//INT8
edkVecInt8 edkVecInt8Construct();
edkVecInt8 edkConstructVecInt8();
edkVecInt8* edkVecInt8New();
edkVecInt8* edkNewVecInt8();
edkVecInt8 edkVecInt8Construct_UInt64(edkUInt64 lenght);
edkVecInt8 edkConstructVecInt8_UInt64(edkUInt64 lenght);
edkVecInt8* edkVecInt8New_UInt64(edkUInt64 lenght);
edkVecInt8* edkNewVecInt8_UInt64(edkUInt64 lenght);
//INT16
edkVecInt16 edkVecInt16Construct();
edkVecInt16 edkConstructVecInt16();
edkVecInt16* edkVecInt16New();
edkVecInt16* edkNewVecInt16();
edkVecInt16 edkVecInt16Construct_UInt64(edkUInt64 lenght);
edkVecInt16 edkConstructVecInt16_UInt64(edkUInt64 lenght);
edkVecInt16* edkVecInt16New_UInt64(edkUInt64 lenght);
edkVecInt16* edkNewVecInt16_UInt64(edkUInt64 lenght);
//INT32
edkVecInt32 edkVecInt32Construct();
edkVecInt32 edkConstructVecInt32();
edkVecInt32* edkVecInt32New();
edkVecInt32* edkNewVecInt32();
edkVecInt32 edkVecInt32Construct_UInt64(edkUInt64 lenght);
edkVecInt32 edkConstructVecInt32_UInt64(edkUInt64 lenght);
edkVecInt32* edkVecInt32New_UInt64(edkUInt64 lenght);
edkVecInt32* edkNewVecInt32_UInt64(edkUInt64 lenght);
//INT64
edkVecInt64 edkVecInt64Construct();
edkVecInt64 edkConstructVecInt64();
edkVecInt64* edkVecInt64New();
edkVecInt64* edkNewVecInt64();
edkVecInt64 edkVecInt64Construct_UInt64(edkUInt64 lenght);
edkVecInt64 edkConstructVecInt64_UInt64(edkUInt64 lenght);
edkVecInt64* edkVecInt64New_UInt64(edkUInt64 lenght);
edkVecInt64* edkNewVecInt64_UInt64(edkUInt64 lenght);

//Validade the vector

//Validade the vector
//UCHAR8
bool edkHaveVecUChar8(edkVecUChar8 vec);
bool edkVecUChar8Have(edkVecUChar8 vec);
//UCHAR16
bool edkVecUChar16Have(edkVecUChar16 vec);
bool edkHaveVecUChar16(edkVecUChar16 vec);
//UCHAR32
bool edkHaveVecUChar32(edkVecUChar32 vec);
bool edkVecUChar32Have(edkVecUChar32 vec);
//UCHAR64
bool edkVecUChar64Have(edkVecUChar64 vec);
bool edkHaveVecUChar64(edkVecUChar64 vec);
//CHAR8
bool edkVecChar8Have(edkVecChar8 vec);
bool edkHaveVecChar8(edkVecChar8 vec);
//CHAR16
bool edkVecChar16Have(edkVecChar16 vec);
bool edkHaveVecChar16(edkVecChar16 vec);
//CHAR32
bool edkVecChar32Have(edkVecChar32 vec);
bool edkHaveVecChar32(edkVecChar32 vec);
//CHAR64
bool edkVecChar64Have(edkVecChar64 vec);
bool edkHaveVecChar64(edkVecChar64 vec);
//UINT8
bool edkVecUInt8Have(edkVecUInt8 vec);
bool edkHaveVecUInt8(edkVecUInt8 vec);
//UINT16
bool edkVecUInt16Have(edkVecUInt16 vec);
bool edkHaveVecUInt16(edkVecUInt16 vec);
//UINT32
bool edkVecUInt32Have(edkVecUInt32 vec);
bool edkHaveVecUInt32(edkVecUInt32 vec);
//UINT64
bool edkVecUInt64Have(edkVecUInt64 vec);
bool edkHaveVecUInt64(edkVecUInt64 vec);
//INT8
bool edkVecInt8Have(edkVecInt8 vec);
bool edkHaveVecInt8(edkVecInt8 vec);
//INT16
bool edkVecInt16Have(edkVecInt16 vec);
bool edkHaveVecInt16(edkVecInt16 vec);
//INT32
bool edkVecInt32Have(edkVecInt32 vec);
bool edkHaveVecInt32(edkVecInt32 vec);
//INT64
bool edkVecInt64Have(edkVecInt64 vec);
bool edkHaveVecInt64(edkVecInt64 vec);

//DESCONSTRUCT
//UCHAR
bool edkVecUChar8Destruct(edkVecUChar8* vec);
bool edkDestructVecUChar8(edkVecUChar8* vec);
bool edkVecUChar16Destruct(edkVecUChar16* vec);
bool edkDestructVecUChar16(edkVecUChar16* vec);
bool edkVecUChar32Destruct(edkVecUChar32* vec);
bool edkDestructVecUChar32(edkVecUChar32* vec);
bool edkVecUChar64Destruct(edkVecUChar64* vec);
bool edkDestructVecUChar64(edkVecUChar64* vec);
//CHAR
bool edkVecChar8Destruct(edkVecChar8* vec);
bool edkDestructVecChar8(edkVecChar8* vec);
bool edkVecChar16Destruct(edkVecChar16* vec);
bool edkDestructVecChar16(edkVecChar16* vec);
bool edkVecChar32Destruct(edkVecChar32* vec);
bool edkDestructVecChar32(edkVecChar32* vec);
bool edkVecChar64Destruct(edkVecChar64* vec);
bool edkDestructVecChar64(edkVecChar64* vec);
//UINT
bool edkVecUInt8Destruct(edkVecUInt8* vec);
bool edkDestructVecUInt8(edkVecUInt8* vec);
bool edkVecUInt16Destruct(edkVecUInt16* vec);
bool edkDestructVecUInt16(edkVecUInt16* vec);
bool edkVecUInt32Destruct(edkVecUInt32* vec);
bool edkDestructVecUInt32(edkVecUInt32* vec);
bool edkVecUInt64Destruct(edkVecUInt64* vec);
bool edkDestructVecUInt64(edkVecUInt64* vec);
//INT
bool edkVecInt8Destruct(edkVecInt8* vec);
bool edkDestructVecInt8(edkVecInt8* vec);
bool edkVecInt16Destruct(edkVecInt16* vec);
bool edkDestructVecInt16(edkVecInt16* vec);
bool edkVecInt32Destruct(edkVecInt32* vec);
bool edkDestructVecInt32(edkVecInt32* vec);
bool edkVecInt64Destruct(edkVecInt64* vec);
bool edkDestructVecInt64(edkVecInt64* vec);

//DELETE
//UCHAR
bool edkVecUChar8Delete(edkVecUChar8** vec);
bool edkDeleteVecUChar8(edkVecUChar8** vec);
bool edkVecUChar16Delete(edkVecUChar16** vec);
bool edkDeleteVecUChar16(edkVecUChar16** vec);
bool edkVecUChar32Delete(edkVecUChar32** vec);
bool edkDeleteVecUChar32(edkVecUChar32** vec);
bool edkVecUChar64Delete(edkVecUChar64** vec);
bool edkDeleteVecUChar64(edkVecUChar64** vec);
//CHAR
bool edkVecChar8Delete(edkVecChar8** vec);
bool edkDeleteVecChar8(edkVecChar8** vec);
bool edkVecChar16Delete(edkVecChar16** vec);
bool edkDeleteVecChar16(edkVecChar16** vec);
bool edkVecChar32Delete(edkVecChar32** vec);
bool edkDeleteVecChar32(edkVecChar32** vec);
bool edkVecChar64Delete(edkVecChar64** vec);
bool edkDeleteVecChar64(edkVecChar64** vec);
//UINT
bool edkVecUInt8Delete(edkVecUInt8** vec);
bool edkDeleteVecUInt8(edkVecUInt8** vec);
bool edkVecUInt16Delete(edkVecUInt16** vec);
bool edkDeleteVecUInt16(edkVecUInt16** vec);
bool edkVecUInt32Delete(edkVecUInt32** vec);
bool edkDeleteVecUInt32(edkVecUInt32** vec);
bool edkVecUInt64Delete(edkVecUInt64** vec);
bool edkDeleteVecUInt64(edkVecUInt64** vec);
//INT
bool edkVecInt8Delete(edkVecInt8** vec);
bool edkDeleteVecInt8(edkVecInt8** vec);
bool edkVecInt16Delete(edkVecInt16** vec);
bool edkDeleteVecInt16(edkVecInt16** vec);
bool edkVecInt32Delete(edkVecInt32** vec);
bool edkDeleteVecInt32(edkVecInt32** vec);
bool edkVecInt64Delete(edkVecInt64** vec);
bool edkDeleteVecInt64(edkVecInt64** vec);

//SETERS
//UCHAR
bool edkVecUChar8Set(edkVecUChar8 vec,edkUInt64 position,edkUChar8 value);
bool edkSetVecUChar8(edkVecUChar8 vec,edkUInt64 position,edkUChar8 value);
bool edkVecUChar16Set(edkVecUChar16 vec,edkUInt64 position,edkUChar16 value);
bool edkSetVecUChar16(edkVecUChar16 vec,edkUInt64 position,edkUChar16 value);
bool edkVecUChar32Set(edkVecUChar32 vec,edkUInt64 position,edkUChar32 value);
bool edkSetVecUChar32(edkVecUChar32 vec,edkUInt64 position,edkUChar32 value);
bool edkVecUChar64Set(edkVecUChar64 vec,edkUInt64 position,edkUChar64 value);
bool edkSetVecUChar64(edkVecUChar64 vec,edkUInt64 position,edkUChar64 value);
//CHAR
bool edkVecChar8Set(edkVecChar8 vec,edkUInt64 position,edkChar8 value);
bool edkSetVecChar8(edkVecChar8 vec,edkUInt64 position,edkChar8 value);
bool edkVecChar16Set(edkVecChar16 vec,edkUInt64 position,edkChar16 value);
bool edkSetVecChar16(edkVecChar16 vec,edkUInt64 position,edkChar16 value);
bool edkVecChar32Set(edkVecChar32 vec,edkUInt64 position,edkChar32 value);
bool edkSetVecChar32(edkVecChar32 vec,edkUInt64 position,edkChar32 value);
bool edkVecChar64Set(edkVecChar64 vec,edkUInt64 position,edkChar64 value);
bool edkSetVecChar64(edkVecChar64 vec,edkUInt64 position,edkChar64 value);
//UINT
bool edkVecUInt8Set(edkVecUInt8 vec,edkUInt64 position,edkUInt8 value);
bool edkSetVecUInt8(edkVecUInt8 vec,edkUInt64 position,edkUInt8 value);
bool edkVecUInt16Set(edkVecUInt16 vec,edkUInt64 position,edkUInt16 value);
bool edkSetVecUInt16(edkVecUInt16 vec,edkUInt64 position,edkUInt16 value);
bool edkVecUInt32Set(edkVecUInt32 vec,edkUInt64 position,edkUInt32 value);
bool edkSetVecUInt32(edkVecUInt32 vec,edkUInt64 position,edkUInt32 value);
bool edkVecUInt64Set(edkVecUInt64 vec,edkUInt64 position,edkUInt64 value);
bool edkSetVecUInt64(edkVecUInt64 vec,edkUInt64 position,edkUInt64 value);
//INT
bool edkVecInt8Set(edkVecInt8 vec,edkUInt64 position,edkInt8 value);
bool edkSetVecInt8(edkVecInt8 vec,edkUInt64 position,edkInt8 value);
bool edkVecInt16Set(edkVecInt16 vec,edkUInt64 position,edkInt16 value);
bool edkSetVecInt16(edkVecInt16 vec,edkUInt64 position,edkInt16 value);
bool edkVecInt32Set(edkVecInt32 vec,edkUInt64 position,edkInt32 value);
bool edkSetVecInt32(edkVecInt32 vec,edkUInt64 position,edkInt32 value);
bool edkVecInt64Set(edkVecInt64 vec,edkUInt64 position,edkInt64 value);
bool edkSetVecInt64(edkVecInt64 vec,edkUInt64 position,edkInt64 value);

//GETERS
//UCHAR
edkUChar8 edkVecUChar8Get(edkVecUChar8 vec,edkUInt64 position);
edkUChar8 edkGetVecUChar8(edkVecUChar8 vec,edkUInt64 position);
edkUChar16 edkVecUChar16Get(edkVecUChar16 vec,edkUInt64 position);
edkUChar16 edkGetVecUChar16(edkVecUChar16 vec,edkUInt64 position);
edkUChar32 edkVecUChar32Get(edkVecUChar32 vec,edkUInt64 position);
edkUChar32 edkGetVecUChar32(edkVecUChar32 vec,edkUInt64 position);
edkUChar64 edkVecUChar64Get(edkVecUChar64 vec,edkUInt64 position);
edkUChar64 edkGetVecUChar64(edkVecUChar64 vec,edkUInt64 position);
//CHAR
edkChar8 edkVecChar8Get(edkVecChar8 vec,edkUInt64 position);
edkChar8 edkGetVecChar8(edkVecChar8 vec,edkUInt64 position);
edkChar16 edkVecChar16Get(edkVecChar16 vec,edkUInt64 position);
edkChar16 edkGetVecChar16(edkVecChar16 vec,edkUInt64 position);
edkChar32 edkVecChar32Get(edkVecChar32 vec,edkUInt64 position);
edkChar32 edkGetVecChar32(edkVecChar32 vec,edkUInt64 position);
edkChar64 edkVecChar64Get(edkVecChar64 vec,edkUInt64 position);
edkChar64 edkGetVecChar64(edkVecChar64 vec,edkUInt64 position);
//UINT
edkUInt8 edkVecUInt8Get(edkVecUInt8 vec,edkUInt64 position);
edkUInt8 edkGetVecUInt8(edkVecUInt8 vec,edkUInt64 position);
edkUInt16 edkVecUInt16Get(edkVecUInt16 vec,edkUInt64 position);
edkUInt16 edkGetVecUInt16(edkVecUInt16 vec,edkUInt64 position);
edkUInt32 edkVecUInt32Get(edkVecUInt32 vec,edkUInt64 position);
edkUInt32 edkGetVecUInt32(edkVecUInt32 vec,edkUInt64 position);
edkUInt64 edkVecUInt64Get(edkVecUInt64 vec,edkUInt64 position);
edkUInt64 edkGetVecUInt64(edkVecUInt64 vec,edkUInt64 position);
//INT
edkInt8 edkVecInt8Get(edkVecInt8 vec,edkUInt64 position);
edkInt8 edkGetVecInt8(edkVecInt8 vec,edkUInt64 position);
edkInt16 edkVecInt16Get(edkVecInt16 vec,edkUInt64 position);
edkInt16 edkGetVecInt16(edkVecInt16 vec,edkUInt64 position);
edkInt32 edkVecInt32Get(edkVecInt32 vec,edkUInt64 position);
edkInt32 edkGetVecInt32(edkVecInt32 vec,edkUInt64 position);
edkInt64 edkVecInt64Get(edkVecInt64 vec,edkUInt64 position);
edkInt64 edkGetVecInt64(edkVecInt64 vec,edkUInt64 position);

#ifdef __cplusplus
}
#endif

#endif // EDKVECTOR_H
