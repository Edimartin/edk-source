#include "edkCVector.h"


#ifdef __cplusplus
extern "C" {
#endif
//create the vector
//UCHAR8
edkVecUChar8 edkVecUChar8Construct(){
    edkVecUChar8 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecUChar8 edkConstructVecUChar8(){
    edkVecUChar8 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecUChar8* edkVecUChar8New(){
    edkVecUChar8* ret = (edkVecUChar8*)malloc(sizeof(edkVecUChar8)*1u);
    if(ret){
        *ret = edkVecUChar8Construct();
        return ret;
    }
    return NULL;
}
edkVecUChar8* edkNewVecUChar8(){
    edkVecUChar8* ret = (edkVecUChar8*)malloc(sizeof(edkVecUChar8)*1u);
    if(ret){
        *ret = edkConstructVecUChar8();
        return ret;
    }
    return NULL;
}
edkVecUChar8 edkVecUChar8Construct_UInt64(edkUInt64 lenght){
    edkVecUChar8 ret = edkVecUChar8Construct();
    if(lenght){
        //create the new vector
        ret.vec = (edkUChar8*)malloc(sizeof(edkUChar8)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecUChar8 edkConstructVecUChar8_UInt64(edkUInt64 lenght){
    edkVecUChar8 ret = edkConstructVecUChar8();
    if(lenght){
        //create the new vector
        ret.vec = (edkUChar8*)malloc(sizeof(edkUChar8)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecUChar8* edkVecUChar8New_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecUChar8* ret=edkVecUChar8New();
        if(ret){
            //create the new vector
            *ret = edkVecUChar8Construct_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
edkVecUChar8* edkNewVecUChar8_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecUChar8* ret=edkNewVecUChar8();
        if(ret){
            //create the new vector
            *ret = edkConstructVecUChar8_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
//UCHAR16
edkVecUChar16 edkVecUChar16Construct(){
    edkVecUChar16 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecUChar16 edkConstructVecUChar16(){
    edkVecUChar16 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecUChar16* edkVecUChar16New(){
    edkVecUChar16* ret = (edkVecUChar16*)malloc(sizeof(edkVecUChar16)*1u);
    if(ret){
        *ret = edkVecUChar16Construct();
        return ret;
    }
    return NULL;
}
edkVecUChar16* edkNewVecUChar16(){
    edkVecUChar16* ret = (edkVecUChar16*)malloc(sizeof(edkVecUChar16)*1u);
    if(ret){
        *ret = edkConstructVecUChar16();
        return ret;
    }
    return NULL;
}
edkVecUChar16 edkVecUChar16Construct_UInt64(edkUInt64 lenght){
    edkVecUChar16 ret = edkVecUChar16Construct();
    if(lenght){
        //create the new vector
        ret.vec = (edkUChar16*)malloc(sizeof(edkUChar16)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecUChar16 edkConstructVecUChar16_UInt64(edkUInt64 lenght){
    edkVecUChar16 ret = edkConstructVecUChar16();
    if(lenght){
        //create the new vector
        ret.vec = (edkUChar16*)malloc(sizeof(edkUChar16)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecUChar16* edkVecUChar16New_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecUChar16* ret=edkVecUChar16New();
        if(ret){
            //create the new vector
            *ret = edkVecUChar16Construct_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
edkVecUChar16* edkNewVecUChar16_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecUChar16* ret=edkNewVecUChar16();
        if(ret){
            //create the new vector
            *ret = edkConstructVecUChar16_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
//UCHAR32
edkVecUChar32 edkVecUChar32Construct(){
    edkVecUChar32 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecUChar32 edkConstructVecUChar32(){
    edkVecUChar32 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecUChar32* edkVecUChar32New(){
    edkVecUChar32* ret = (edkVecUChar32*)malloc(sizeof(edkVecUChar32)*1u);
    if(ret){
        *ret = edkVecUChar32Construct();
        return ret;
    }
    return NULL;
}
edkVecUChar32* edkNewVecUChar32(){
    edkVecUChar32* ret = (edkVecUChar32*)malloc(sizeof(edkVecUChar32)*1u);
    if(ret){
        *ret = edkConstructVecUChar32();
        return ret;
    }
    return NULL;
}
edkVecUChar32 edkVecUChar32Construct_UInt64(edkUInt64 lenght){
    edkVecUChar32 ret = edkVecUChar32Construct();
    if(lenght){
        //create the new vector
        ret.vec = (edkUChar32*)malloc(sizeof(edkUChar32)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecUChar32 edkConstructVecUChar32_UInt64(edkUInt64 lenght){
    edkVecUChar32 ret = edkConstructVecUChar32();
    if(lenght){
        //create the new vector
        ret.vec = (edkUChar32*)malloc(sizeof(edkUChar32)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecUChar32* edkVecUChar32New_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecUChar32* ret=edkVecUChar32New();
        if(ret){
            //create the new vector
            *ret = edkVecUChar32Construct_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
edkVecUChar32* edkNewVecUChar32_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecUChar32* ret=edkNewVecUChar32();
        if(ret){
            //create the new vector
            *ret = edkConstructVecUChar32_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
//UCHAR64
edkVecUChar64 edkVecUChar64Construct(){
    edkVecUChar64 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecUChar64 edkConstructVecUChar64(){
    edkVecUChar64 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecUChar64* edkVecUChar64New(){
    edkVecUChar64* ret = (edkVecUChar64*)malloc(sizeof(edkVecUChar64)*1u);
    if(ret){
        *ret = edkVecUChar64Construct();
        return ret;
    }
    return NULL;
}
edkVecUChar64* edkNewVecUChar64(){
    edkVecUChar64* ret = (edkVecUChar64*)malloc(sizeof(edkVecUChar64)*1u);
    if(ret){
        *ret = edkConstructVecUChar64();
        return ret;
    }
    return NULL;
}
edkVecUChar64 edkVecUChar64Construct_UInt64(edkUInt64 lenght){
    edkVecUChar64 ret = edkVecUChar64Construct();
    if(lenght){
        //create the new vector
        ret.vec = (edkUChar64*)malloc(sizeof(edkUChar64)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecUChar64 edkConstructVecUChar64_UInt64(edkUInt64 lenght){
    edkVecUChar64 ret = edkConstructVecUChar64();
    if(lenght){
        //create the new vector
        ret.vec = (edkUChar64*)malloc(sizeof(edkUChar64)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecUChar64* edkVecUChar64New_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecUChar64* ret=edkVecUChar64New();
        if(ret){
            //create the new vector
            *ret = edkVecUChar64Construct_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
edkVecUChar64* edkNewVecUChar64_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecUChar64* ret=edkNewVecUChar64();
        if(ret){
            //create the new vector
            *ret = edkConstructVecUChar64_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
//CHAR8
edkVecChar8 edkVecChar8Construct(){
    edkVecChar8 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecChar8 edkConstructVecChar8(){
    edkVecChar8 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecChar8* edkVecChar8New(){
    edkVecChar8* ret = (edkVecChar8*)malloc(sizeof(edkVecChar8)*1u);
    if(ret){
        *ret = edkVecChar8Construct();
        return ret;
    }
    return NULL;
}
edkVecChar8* edkNewVecChar8(){
    edkVecChar8* ret = (edkVecChar8*)malloc(sizeof(edkVecChar8)*1u);
    if(ret){
        *ret = edkConstructVecChar8();
        return ret;
    }
    return NULL;
}
edkVecChar8 edkVecChar8Construct_UInt64(edkUInt64 lenght){
    edkVecChar8 ret = edkVecChar8Construct();
    if(lenght){
        //create the new vector
        ret.vec = (edkChar8*)malloc(sizeof(edkChar8)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecChar8 edkConstructVecChar8_UInt64(edkUInt64 lenght){
    edkVecChar8 ret = edkConstructVecChar8();
    if(lenght){
        //create the new vector
        ret.vec = (edkChar8*)malloc(sizeof(edkChar8)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecChar8* edkVecChar8New_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecChar8* ret=edkVecChar8New();
        if(ret){
            //create the new vector
            *ret = edkVecChar8Construct_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
edkVecChar8* edkNewVecChar8_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecChar8* ret=edkNewVecChar8();
        if(ret){
            //create the new vector
            *ret = edkConstructVecChar8_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
//CHAR16
edkVecChar16 edkVecChar16Construct(){
    edkVecChar16 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecChar16 edkConstructVecChar16(){
    edkVecChar16 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecChar16* edkVecChar16New(){
    edkVecChar16* ret = (edkVecChar16*)malloc(sizeof(edkVecChar16)*1u);
    if(ret){
        *ret = edkVecChar16Construct();
        return ret;
    }
    return NULL;
}
edkVecChar16* edkNewVecChar16(){
    edkVecChar16* ret = (edkVecChar16*)malloc(sizeof(edkVecChar16)*1u);
    if(ret){
        *ret = edkConstructVecChar16();
        return ret;
    }
    return NULL;
}
edkVecChar16 edkVecChar16Construct_UInt64(edkUInt64 lenght){
    edkVecChar16 ret = edkVecChar16Construct();
    if(lenght){
        //create the new vector
        ret.vec = (edkChar16*)malloc(sizeof(edkChar16)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecChar16 edkConstructVecChar16_UInt64(edkUInt64 lenght){
    edkVecChar16 ret = edkConstructVecChar16();
    if(lenght){
        //create the new vector
        ret.vec = (edkChar16*)malloc(sizeof(edkChar16)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecChar16* edkVecChar16New_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecChar16* ret=edkVecChar16New();
        if(ret){
            //create the new vector
            *ret = edkVecChar16Construct_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
edkVecChar16* edkNewVecChar16_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecChar16* ret=edkNewVecChar16();
        if(ret){
            //create the new vector
            *ret = edkConstructVecChar16_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
//CHAR32
edkVecChar32 edkVecChar32Construct(){
    edkVecChar32 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecChar32 edkConstructVecChar32(){
    edkVecChar32 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecChar32* edkVecChar32New(){
    edkVecChar32* ret = (edkVecChar32*)malloc(sizeof(edkVecChar32)*1u);
    if(ret){
        *ret = edkVecChar32Construct();
        return ret;
    }
    return NULL;
}
edkVecChar32* edkNewVecChar32(){
    edkVecChar32* ret = (edkVecChar32*)malloc(sizeof(edkVecChar32)*1u);
    if(ret){
        *ret = edkConstructVecChar32();
        return ret;
    }
    return NULL;
}
edkVecChar32 edkVecChar32Construct_UInt64(edkUInt64 lenght){
    edkVecChar32 ret = edkVecChar32Construct();
    if(lenght){
        //create the new vector
        ret.vec = (edkChar32*)malloc(sizeof(edkChar32)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecChar32 edkConstructVecChar32_UInt64(edkUInt64 lenght){
    edkVecChar32 ret = edkConstructVecChar32();
    if(lenght){
        //create the new vector
        ret.vec = (edkChar32*)malloc(sizeof(edkChar32)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecChar32* edkVecChar32New_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecChar32* ret=edkVecChar32New();
        if(ret){
            //create the new vector
            *ret = edkVecChar32Construct_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
edkVecChar32* edkNewVecChar32_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecChar32* ret=edkNewVecChar32();
        if(ret){
            //create the new vector
            *ret = edkConstructVecChar32_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
//CHAR64
edkVecChar64 edkVecChar64Construct(){
    edkVecChar64 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecChar64 edkConstructVecChar64(){
    edkVecChar64 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecChar64* edkVecChar64New(){
    edkVecChar64* ret = (edkVecChar64*)malloc(sizeof(edkVecChar64)*1u);
    if(ret){
        *ret = edkVecChar64Construct();
        return ret;
    }
    return NULL;
}
edkVecChar64* edkNewVecChar64(){
    edkVecChar64* ret = (edkVecChar64*)malloc(sizeof(edkVecChar64)*1u);
    if(ret){
        *ret = edkConstructVecChar64();
        return ret;
    }
    return NULL;
}
edkVecChar64 edkVecChar64Construct_UInt64(edkUInt64 lenght){
    edkVecChar64 ret = edkVecChar64Construct();
    if(lenght){
        //create the new vector
        ret.vec = (edkChar64*)malloc(sizeof(edkChar64)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecChar64 edkConstructVecChar64_UInt64(edkUInt64 lenght){
    edkVecChar64 ret = edkConstructVecChar64();
    if(lenght){
        //create the new vector
        ret.vec = (edkChar64*)malloc(sizeof(edkChar64)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecChar64* edkVecChar64New_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecChar64* ret=edkVecChar64New();
        if(ret){
            //create the new vector
            *ret = edkVecChar64Construct_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
edkVecChar64* edkNewVecChar64_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecChar64* ret=edkNewVecChar64();
        if(ret){
            //create the new vector
            *ret = edkConstructVecChar64_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
//UINT8
edkVecUInt8 edkVecUInt8Construct(){
    edkVecUInt8 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecUInt8 edkConstructVecUInt8(){
    edkVecUInt8 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecUInt8* edkVecUInt8New(){
    edkVecUInt8* ret = (edkVecUInt8*)malloc(sizeof(edkVecUInt8)*1u);
    if(ret){
        *ret = edkVecUInt8Construct();
        return ret;
    }
    return NULL;
}
edkVecUInt8* edkNewVecUInt8(){
    edkVecUInt8* ret = (edkVecUInt8*)malloc(sizeof(edkVecUInt8)*1u);
    if(ret){
        *ret = edkConstructVecUInt8();
        return ret;
    }
    return NULL;
}
edkVecUInt8 edkVecUInt8Construct_UInt64(edkUInt64 lenght){
    edkVecUInt8 ret = edkVecUInt8Construct();
    if(lenght){
        //create the new vector
        ret.vec = (edkUInt8*)malloc(sizeof(edkUInt8)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecUInt8 edkConstructVecUInt8_UInt64(edkUInt64 lenght){
    edkVecUInt8 ret = edkConstructVecUInt8();
    if(lenght){
        //create the new vector
        ret.vec = (edkUInt8*)malloc(sizeof(edkUInt8)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecUInt8* edkVecUInt8New_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecUInt8* ret=edkVecUInt8New();
        if(ret){
            //create the new vector
            *ret = edkVecUInt8Construct_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
edkVecUInt8* edkNewVecUInt8_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecUInt8* ret=edkNewVecUInt8();
        if(ret){
            //create the new vector
            *ret = edkConstructVecUInt8_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
//UINT16
edkVecUInt16 edkVecUInt16Construct(){
    edkVecUInt16 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecUInt16 edkConstructVecUInt16(){
    edkVecUInt16 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecUInt16* edkVecUInt16New(){
    edkVecUInt16* ret = (edkVecUInt16*)malloc(sizeof(edkVecUInt16)*1u);
    if(ret){
        *ret = edkVecUInt16Construct();
        return ret;
    }
    return NULL;
}
edkVecUInt16* edkNewVecUInt16(){
    edkVecUInt16* ret = (edkVecUInt16*)malloc(sizeof(edkVecUInt16)*1u);
    if(ret){
        *ret = edkConstructVecUInt16();
        return ret;
    }
    return NULL;
}
edkVecUInt16 edkVecUInt16Construct_UInt64(edkUInt64 lenght){
    edkVecUInt16 ret = edkVecUInt16Construct();
    if(lenght){
        //create the new vector
        ret.vec = (edkUInt16*)malloc(sizeof(edkUInt16)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecUInt16 edkConstructVecUInt16_UInt64(edkUInt64 lenght){
    edkVecUInt16 ret = edkConstructVecUInt16();
    if(lenght){
        //create the new vector
        ret.vec = (edkUInt16*)malloc(sizeof(edkUInt16)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecUInt16* edkVecUInt16New_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecUInt16* ret=edkVecUInt16New();
        if(ret){
            //create the new vector
            *ret = edkVecUInt16Construct_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
edkVecUInt16* edkNewVecUInt16_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecUInt16* ret=edkNewVecUInt16();
        if(ret){
            //create the new vector
            *ret = edkConstructVecUInt16_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
//UINT32
edkVecUInt32 edkVecUInt32Construct(){
    edkVecUInt32 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecUInt32 edkConstructVecUInt32(){
    edkVecUInt32 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecUInt32* edkVecUInt32New(){
    edkVecUInt32* ret = (edkVecUInt32*)malloc(sizeof(edkVecUInt32)*1u);
    if(ret){
        *ret = edkVecUInt32Construct();
        return ret;
    }
    return NULL;
}
edkVecUInt32* edkNewVecUInt32(){
    edkVecUInt32* ret = (edkVecUInt32*)malloc(sizeof(edkVecUInt32)*1u);
    if(ret){
        *ret = edkConstructVecUInt32();
        return ret;
    }
    return NULL;
}
edkVecUInt32 edkVecUInt32Construct_UInt64(edkUInt64 lenght){
    edkVecUInt32 ret = edkVecUInt32Construct();
    if(lenght){
        //create the new vector
        ret.vec = (edkUInt32*)malloc(sizeof(edkUInt32)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecUInt32 edkConstructVecUInt32_UInt64(edkUInt64 lenght){
    edkVecUInt32 ret = edkConstructVecUInt32();
    if(lenght){
        //create the new vector
        ret.vec = (edkUInt32*)malloc(sizeof(edkUInt32)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecUInt32* edkVecUInt32New_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecUInt32* ret=edkVecUInt32New();
        if(ret){
            //create the new vector
            *ret = edkVecUInt32Construct_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
edkVecUInt32* edkNewVecUInt32_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecUInt32* ret=edkNewVecUInt32();
        if(ret){
            //create the new vector
            *ret = edkConstructVecUInt32_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
//UINT64
edkVecUInt64 edkVecUInt64Construct(){
    edkVecUInt64 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecUInt64 edkConstructVecUInt64(){
    edkVecUInt64 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecUInt64* edkVecUInt64New(){
    edkVecUInt64* ret = (edkVecUInt64*)malloc(sizeof(edkVecUInt64)*1u);
    if(ret){
        *ret = edkVecUInt64Construct();
        return ret;
    }
    return NULL;
}
edkVecUInt64* edkNewVecUInt64(){
    edkVecUInt64* ret = (edkVecUInt64*)malloc(sizeof(edkVecUInt64)*1u);
    if(ret){
        *ret = edkConstructVecUInt64();
        return ret;
    }
    return NULL;
}
edkVecUInt64 edkVecUInt64Construct_UInt64(edkUInt64 lenght){
    edkVecUInt64 ret = edkVecUInt64Construct();
    if(lenght){
        //create the new vector
        ret.vec = (edkUInt64*)malloc(sizeof(edkUInt64)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecUInt64 edkConstructVecUInt64_UInt64(edkUInt64 lenght){
    edkVecUInt64 ret = edkConstructVecUInt64();
    if(lenght){
        //create the new vector
        ret.vec = (edkUInt64*)malloc(sizeof(edkUInt64)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecUInt64* edkVecUInt64New_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecUInt64* ret=edkVecUInt64New();
        if(ret){
            //create the new vector
            *ret = edkVecUInt64Construct_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
edkVecUInt64* edkNewVecUInt64_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecUInt64* ret=edkNewVecUInt64();
        if(ret){
            //create the new vector
            *ret = edkConstructVecUInt64_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
//INT8
edkVecInt8 edkVecInt8Construct(){
    edkVecInt8 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecInt8 edkConstructVecInt8(){
    edkVecInt8 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecInt8* edkVecInt8New(){
    edkVecInt8* ret = (edkVecInt8*)malloc(sizeof(edkVecInt8)*1u);
    if(ret){
        *ret = edkVecInt8Construct();
        return ret;
    }
    return NULL;
}
edkVecInt8* edkNewVecInt8(){
    edkVecInt8* ret = (edkVecInt8*)malloc(sizeof(edkVecInt8)*1u);
    if(ret){
        *ret = edkConstructVecInt8();
        return ret;
    }
    return NULL;
}
edkVecInt8 edkVecInt8Construct_UInt64(edkUInt64 lenght){
    edkVecInt8 ret = edkVecInt8Construct();
    if(lenght){
        //create the new vector
        ret.vec = (edkInt8*)malloc(sizeof(edkInt8)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecInt8 edkConstructVecInt8_UInt64(edkUInt64 lenght){
    edkVecInt8 ret = edkConstructVecInt8();
    if(lenght){
        //create the new vector
        ret.vec = (edkInt8*)malloc(sizeof(edkInt8)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecInt8* edkVecInt8New_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecInt8* ret=edkVecInt8New();
        if(ret){
            //create the new vector
            *ret = edkVecInt8Construct_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
edkVecInt8* edkNewVecInt8_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecInt8* ret=edkNewVecInt8();
        if(ret){
            //create the new vector
            *ret = edkConstructVecInt8_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
//INT16
edkVecInt16 edkVecInt16Construct(){
    edkVecInt16 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecInt16 edkConstructVecInt16(){
    edkVecInt16 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecInt16* edkVecInt16New(){
    edkVecInt16* ret = (edkVecInt16*)malloc(sizeof(edkVecInt16)*1u);
    if(ret){
        *ret = edkVecInt16Construct();
        return ret;
    }
    return NULL;
}
edkVecInt16* edkNewVecInt16(){
    edkVecInt16* ret = (edkVecInt16*)malloc(sizeof(edkVecInt16)*1u);
    if(ret){
        *ret = edkConstructVecInt16();
        return ret;
    }
    return NULL;
}
edkVecInt16 edkVecInt16Construct_UInt64(edkUInt64 lenght){
    edkVecInt16 ret = edkVecInt16Construct();
    if(lenght){
        //create the new vector
        ret.vec = (edkInt16*)malloc(sizeof(edkInt16)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecInt16 edkConstructVecInt16_UInt64(edkUInt64 lenght){
    edkVecInt16 ret = edkConstructVecInt16();
    if(lenght){
        //create the new vector
        ret.vec = (edkInt16*)malloc(sizeof(edkInt16)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecInt16* edkVecInt16New_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecInt16* ret=edkVecInt16New();
        if(ret){
            //create the new vector
            *ret = edkVecInt16Construct_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
edkVecInt16* edkNewVecInt16_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecInt16* ret=edkNewVecInt16();
        if(ret){
            //create the new vector
            *ret = edkConstructVecInt16_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
//INT32
edkVecInt32 edkVecInt32Construct(){
    edkVecInt32 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecInt32 edkConstructVecInt32(){
    edkVecInt32 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecInt32* edkVecInt32New(){
    edkVecInt32* ret = (edkVecInt32*)malloc(sizeof(edkVecInt32)*1u);
    if(ret){
        *ret = edkVecInt32Construct();
        return ret;
    }
    return NULL;
}
edkVecInt32* edkNewVecInt32(){
    edkVecInt32* ret = (edkVecInt32*)malloc(sizeof(edkVecInt32)*1u);
    if(ret){
        *ret = edkConstructVecInt32();
        return ret;
    }
    return NULL;
}
edkVecInt32 edkVecInt32Construct_UInt64(edkUInt64 lenght){
    edkVecInt32 ret = edkVecInt32Construct();
    if(lenght){
        //create the new vector
        ret.vec = (edkInt32*)malloc(sizeof(edkInt32)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecInt32 edkConstructVecInt32_UInt64(edkUInt64 lenght){
    edkVecInt32 ret = edkConstructVecInt32();
    if(lenght){
        //create the new vector
        ret.vec = (edkInt32*)malloc(sizeof(edkInt32)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecInt32* edkVecInt32New_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecInt32* ret=edkVecInt32New();
        if(ret){
            //create the new vector
            *ret = edkVecInt32Construct_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
edkVecInt32* edkNewVecInt32_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecInt32* ret=edkNewVecInt32();
        if(ret){
            //create the new vector
            *ret = edkConstructVecInt32_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
//INT64
edkVecInt64 edkVecInt64Construct(){
    edkVecInt64 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecInt64 edkConstructVecInt64(){
    edkVecInt64 ret;
    ret.vec = NULL;
    ret.lenght=0u;
    return ret;
}
edkVecInt64* edkVecInt64New(){
    edkVecInt64* ret = (edkVecInt64*)malloc(sizeof(edkVecInt64)*1u);
    if(ret){
        *ret = edkVecInt64Construct();
        return ret;
    }
    return NULL;
}
edkVecInt64* edkNewVecInt64(){
    edkVecInt64* ret = (edkVecInt64*)malloc(sizeof(edkVecInt64)*1u);
    if(ret){
        *ret = edkConstructVecInt64();
        return ret;
    }
    return NULL;
}
edkVecInt64 edkVecInt64Construct_UInt64(edkUInt64 lenght){
    edkVecInt64 ret = edkVecInt64Construct();
    if(lenght){
        //create the new vector
        ret.vec = (edkInt64*)malloc(sizeof(edkInt64)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecInt64 edkConstructVecInt64_UInt64(edkUInt64 lenght){
    edkVecInt64 ret = edkConstructVecInt64();
    if(lenght){
        //create the new vector
        ret.vec = (edkInt64*)malloc(sizeof(edkInt64)*lenght);
        if(ret.vec){
            ret.lenght=lenght;
        }
        else{
            ret.vec = NULL;
            ret.lenght=0u;
        }
    }
    else{
        ret.vec = NULL;
        ret.lenght=0u;
    }
    return ret;
}
edkVecInt64* edkVecInt64New_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecInt64* ret=edkVecInt64New();
        if(ret){
            //create the new vector
            *ret = edkVecInt64Construct_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}
edkVecInt64* edkNewVecInt64_UInt64(edkUInt64 lenght){
    if(lenght){
        edkVecInt64* ret=edkNewVecInt64();
        if(ret){
            //create the new vector
            *ret = edkConstructVecInt64_UInt64(lenght);
            return ret;
        }
    }
    return NULL;
}

//Validade the vector
//UCHAR8
bool edkHaveVecUChar8(edkVecUChar8 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
bool edkVecUChar8Have(edkVecUChar8 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
//UCHAR16
bool edkVecUChar16Have(edkVecUChar16 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
bool edkHaveVecUChar16(edkVecUChar16 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
//UCHAR32
bool edkHaveVecUChar32(edkVecUChar32 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
bool edkVecUChar32Have(edkVecUChar32 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
//UCHAR64
bool edkVecUChar64Have(edkVecUChar64 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
bool edkHaveVecUChar64(edkVecUChar64 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
//CHAR8
bool edkVecChar8Have(edkVecChar8 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
bool edkHaveVecChar8(edkVecChar8 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
//CHAR16
bool edkVecChar16Have(edkVecChar16 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
bool edkHaveVecChar16(edkVecChar16 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
//CHAR32
bool edkVecChar32Have(edkVecChar32 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
bool edkHaveVecChar32(edkVecChar32 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
//CHAR64
bool edkVecChar64Have(edkVecChar64 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
bool edkHaveVecChar64(edkVecChar64 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
//UINT8
bool edkVecUInt8Have(edkVecUInt8 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
bool edkHaveVecUInt8(edkVecUInt8 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
//UINT16
bool edkVecUInt16Have(edkVecUInt16 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
bool edkHaveVecUInt16(edkVecUInt16 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
//UINT32
bool edkVecUInt32Have(edkVecUInt32 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
bool edkHaveVecUInt32(edkVecUInt32 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
//UINT64
bool edkVecUInt64Have(edkVecUInt64 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
bool edkHaveVecUInt64(edkVecUInt64 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
//INT8
bool edkVecInt8Have(edkVecInt8 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
bool edkHaveVecInt8(edkVecInt8 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
//INT16
bool edkVecInt16Have(edkVecInt16 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
bool edkHaveVecInt16(edkVecInt16 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
//INT32
bool edkVecInt32Have(edkVecInt32 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
bool edkHaveVecInt32(edkVecInt32 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
//INT64
bool edkVecInt64Have(edkVecInt64 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}
bool edkHaveVecInt64(edkVecInt64 vec){
    if(edkVecHaveVec(vec)) return true;
    return false;
}

//DESCONSTRUCT
//UCHAR
bool edkVecUChar8Destruct(edkVecUChar8* vec){
    if(vec){
        if(edkVecUChar8Have(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkDestructVecUChar8(edkVecUChar8* vec){
    if(vec){
        if(edkHaveVecUChar8(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkVecUChar16Destruct(edkVecUChar16* vec){
    if(vec){
        if(edkVecUChar16Have(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkDestructVecUChar16(edkVecUChar16* vec){
    if(vec){
        if(edkHaveVecUChar16(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkVecUChar32Destruct(edkVecUChar32* vec){
    if(vec){
        if(edkVecUChar32Have(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkDestructVecUChar32(edkVecUChar32* vec){
    if(vec){
        if(edkHaveVecUChar32(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkVecUChar64Destruct(edkVecUChar64* vec){
    if(vec){
        if(edkVecUChar64Have(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkDestructVecUChar64(edkVecUChar64* vec){
    if(vec){
        if(edkHaveVecUChar64(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
//CHAR
bool edkVecChar8Destruct(edkVecChar8* vec){
    if(vec){
        if(edkVecChar8Have(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkDestructVecChar8(edkVecChar8* vec){
    if(vec){
        if(edkHaveVecChar8(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkVecChar16Destruct(edkVecChar16* vec){
    if(vec){
        if(edkVecChar16Have(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkDestructVecChar16(edkVecChar16* vec){
    if(vec){
        if(edkHaveVecChar16(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkVecChar32Destruct(edkVecChar32* vec){
    if(vec){
        if(edkVecChar32Have(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkDestructVecChar32(edkVecChar32* vec){
    if(vec){
        if(edkHaveVecChar32(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkVecChar64Destruct(edkVecChar64* vec){
    if(vec){
        if(edkVecChar64Have(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkDestructVecChar64(edkVecChar64* vec){
    if(vec){
        if(edkHaveVecChar64(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
//UINT
bool edkVecUInt8Destruct(edkVecUInt8* vec){
    if(vec){
        if(edkVecUInt8Have(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkDestructVecUInt8(edkVecUInt8* vec){
    if(vec){
        if(edkHaveVecUInt8(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkVecUInt16Destruct(edkVecUInt16* vec){
    if(vec){
        if(edkVecUInt16Have(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkDestructVecUInt16(edkVecUInt16* vec){
    if(vec){
        if(edkHaveVecUInt16(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkVecUInt32Destruct(edkVecUInt32* vec){
    if(vec){
        if(edkVecUInt32Have(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkDestructVecUInt32(edkVecUInt32* vec){
    if(vec){
        if(edkHaveVecUInt32(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkVecUInt64Destruct(edkVecUInt64* vec){
    if(vec){
        if(edkVecUInt64Have(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkDestructVecUInt64(edkVecUInt64* vec){
    if(vec){
        if(edkHaveVecUInt64(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
//INT
bool edkVecInt8Destruct(edkVecInt8* vec){
    if(vec){
        if(edkVecInt8Have(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkDestructVecInt8(edkVecInt8* vec){
    if(vec){
        if(edkHaveVecInt8(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkVecInt16Destruct(edkVecInt16* vec){
    if(vec){
        if(edkVecInt16Have(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkDestructVecInt16(edkVecInt16* vec){
    if(vec){
        if(edkHaveVecInt16(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkVecInt32Destruct(edkVecInt32* vec){
    if(vec){
        if(edkVecInt32Have(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkDestructVecInt32(edkVecInt32* vec){
    if(vec){
        if(edkHaveVecInt32(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkVecInt64Destruct(edkVecInt64* vec){
    if(vec){
        if(edkVecInt64Have(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}
bool edkDestructVecInt64(edkVecInt64* vec){
    if(vec){
        if(edkHaveVecInt64(*vec)){
            //delete the vector inide the vec
            free(vec->vec);
            vec->lenght=0u;
            return true;
        }
    }
    return false;
}

//DELETE
//UCHAR
bool edkVecUChar8Delete(edkVecUChar8** vec){
    if(vec){
        return edkVecUChar8Destruct(*vec);
    }
    return false;
}
bool edkDeleteVecUChar8(edkVecUChar8** vec){
    if(vec){
        return edkDestructVecUChar8(*vec);
    }
    return false;
}
bool edkVecUChar16Delete(edkVecUChar16** vec){
    if(vec){
        return edkVecUChar16Destruct(*vec);
    }
    return false;
}
bool edkDeleteVecUChar16(edkVecUChar16** vec){
    if(vec){
        return edkDestructVecUChar16(*vec);
    }
    return false;
}
bool edkVecUChar32Delete(edkVecUChar32** vec){
    if(vec){
        return edkVecUChar32Destruct(*vec);
    }
    return false;
}
bool edkDeleteVecUChar32(edkVecUChar32** vec){
    if(vec){
        return edkDestructVecUChar32(*vec);
    }
    return false;
}
bool edkVecUChar64Delete(edkVecUChar64** vec){
    if(vec){
        return edkVecUChar64Destruct(*vec);
    }
    return false;
}
bool edkDeleteVecUChar64(edkVecUChar64** vec){
    if(vec){
        return edkDestructVecUChar64(*vec);
    }
    return false;
}
//CHAR
bool edkVecChar8Delete(edkVecChar8** vec){
    if(vec){
        return edkVecChar8Destruct(*vec);
    }
    return false;
}
bool edkDeleteVecChar8(edkVecChar8** vec){
    if(vec){
        return edkDestructVecChar8(*vec);
    }
    return false;
}
bool edkVecChar16Delete(edkVecChar16** vec){
    if(vec){
        return edkVecChar16Destruct(*vec);
    }
    return false;
}
bool edkDeleteVecChar16(edkVecChar16** vec){
    if(vec){
        return edkDestructVecChar16(*vec);
    }
    return false;
}
bool edkVecChar32Delete(edkVecChar32** vec){
    if(vec){
        return edkVecChar32Destruct(*vec);
    }
    return false;
}
bool edkDeleteVecChar32(edkVecChar32** vec){
    if(vec){
        return edkDestructVecChar32(*vec);
    }
    return false;
}
bool edkVecChar64Delete(edkVecChar64** vec){
    if(vec){
        return edkVecChar64Destruct(*vec);
    }
    return false;
}
bool edkDeleteVecChar64(edkVecChar64** vec){
    if(vec){
        return edkDestructVecChar64(*vec);
    }
    return false;
}
//UINT
bool edkVecUInt8Delete(edkVecUInt8** vec){
    if(vec){
        return edkVecUInt8Destruct(*vec);
    }
    return false;
}
bool edkDeleteVecUInt8(edkVecUInt8** vec){
    if(vec){
        return edkDestructVecUInt8(*vec);
    }
    return false;
}
bool edkVecUInt16Delete(edkVecUInt16** vec){
    if(vec){
        return edkVecUInt16Destruct(*vec);
    }
    return false;
}
bool edkDeleteVecUInt16(edkVecUInt16** vec){
    if(vec){
        return edkDestructVecUInt16(*vec);
    }
    return false;
}
bool edkVecUInt32Delete(edkVecUInt32** vec){
    if(vec){
        return edkVecUInt32Destruct(*vec);
    }
    return false;
}
bool edkDeleteVecUInt32(edkVecUInt32** vec){
    if(vec){
        return edkDestructVecUInt32(*vec);
    }
    return false;
}
bool edkVecUInt64Delete(edkVecUInt64** vec){
    if(vec){
        return edkVecUInt64Destruct(*vec);
    }
    return false;
}
bool edkDeleteVecUInt64(edkVecUInt64** vec){
    if(vec){
        return edkDestructVecUInt64(*vec);
    }
    return false;
}
//INT
bool edkVecInt8Delete(edkVecInt8** vec){
    if(vec){
        return edkVecInt8Destruct(*vec);
    }
    return false;
}
bool edkDeleteVecInt8(edkVecInt8** vec){
    if(vec){
        return edkDestructVecInt8(*vec);
    }
    return false;
}
bool edkVecInt16Delete(edkVecInt16** vec){
    if(vec){
        return edkVecInt16Destruct(*vec);
    }
    return false;
}
bool edkDeleteVecInt16(edkVecInt16** vec){
    if(vec){
        return edkDestructVecInt16(*vec);
    }
    return false;
}
bool edkVecInt32Delete(edkVecInt32** vec){
    if(vec){
        return edkVecInt32Destruct(*vec);
    }
    return false;
}
bool edkDeleteVecInt32(edkVecInt32** vec){
    if(vec){
        return edkDestructVecInt32(*vec);
    }
    return false;
}
bool edkVecInt64Delete(edkVecInt64** vec){
    if(vec){
        return edkVecInt64Destruct(*vec);
    }
    return false;
}
bool edkDeleteVecInt64(edkVecInt64** vec){
    if(vec){
        return edkDestructVecInt64(*vec);
    }
    return false;
}

//SETERS
//UCHAR
bool edkVecUChar8Set(edkVecUChar8 vec,edkUInt64 position,edkUChar8 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkSetVecUChar8(edkVecUChar8 vec,edkUInt64 position,edkUChar8 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkVecUChar16Set(edkVecUChar16 vec,edkUInt64 position,edkUChar16 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkSetVecUChar16(edkVecUChar16 vec,edkUInt64 position,edkUChar16 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkVecUChar32Set(edkVecUChar32 vec,edkUInt64 position,edkUChar32 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkSetVecUChar32(edkVecUChar32 vec,edkUInt64 position,edkUChar32 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkVecUChar64Set(edkVecUChar64 vec,edkUInt64 position,edkUChar64 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkSetVecUChar64(edkVecUChar64 vec,edkUInt64 position,edkUChar64 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
//CHAR
bool edkVecChar8Set(edkVecChar8 vec,edkUInt64 position,edkChar8 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkSetVecChar8(edkVecChar8 vec,edkUInt64 position,edkChar8 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkVecChar16Set(edkVecChar16 vec,edkUInt64 position,edkChar16 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkSetVecChar16(edkVecChar16 vec,edkUInt64 position,edkChar16 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkVecChar32Set(edkVecChar32 vec,edkUInt64 position,edkChar32 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkSetVecChar32(edkVecChar32 vec,edkUInt64 position,edkChar32 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkVecChar64Set(edkVecChar64 vec,edkUInt64 position,edkChar64 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkSetVecChar64(edkVecChar64 vec,edkUInt64 position,edkChar64 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
//UINT
bool edkVecUInt8Set(edkVecUInt8 vec,edkUInt64 position,edkUInt8 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkSetVecUInt8(edkVecUInt8 vec,edkUInt64 position,edkUInt8 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkVecUInt16Set(edkVecUInt16 vec,edkUInt64 position,edkUInt16 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkSetVecUInt16(edkVecUInt16 vec,edkUInt64 position,edkUInt16 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkVecUInt32Set(edkVecUInt32 vec,edkUInt64 position,edkUInt32 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkSetVecUInt32(edkVecUInt32 vec,edkUInt64 position,edkUInt32 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkVecUInt64Set(edkVecUInt64 vec,edkUInt64 position,edkUInt64 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkSetVecUInt64(edkVecUInt64 vec,edkUInt64 position,edkUInt64 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
//INT
bool edkVecInt8Set(edkVecInt8 vec,edkUInt64 position,edkInt8 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkSetVecInt8(edkVecInt8 vec,edkUInt64 position,edkInt8 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkVecInt16Set(edkVecInt16 vec,edkUInt64 position,edkInt16 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkSetVecInt16(edkVecInt16 vec,edkUInt64 position,edkInt16 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkVecInt32Set(edkVecInt32 vec,edkUInt64 position,edkInt32 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkSetVecInt32(edkVecInt32 vec,edkUInt64 position,edkInt32 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkVecInt64Set(edkVecInt64 vec,edkUInt64 position,edkInt64 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}
bool edkSetVecInt64(edkVecInt64 vec,edkUInt64 position,edkInt64 value){
    bool ret;
    edkVecSet(vec,position,value,&ret);
    return ret;
}

//GETERS
//UCHAR
edkUChar8 edkVecUChar8Get(edkVecUChar8 vec,edkUInt64 position){
    edkUChar8 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkUChar8 edkGetVecUChar8(edkVecUChar8 vec,edkUInt64 position){
    edkUChar8 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkUChar16 edkVecUChar16Get(edkVecUChar16 vec,edkUInt64 position){
    edkUChar16 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkUChar16 edkGetVecUChar16(edkVecUChar16 vec,edkUInt64 position){
    edkUChar16 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkUChar32 edkVecUChar32Get(edkVecUChar32 vec,edkUInt64 position){
    edkUChar32 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkUChar32 edkGetVecUChar32(edkVecUChar32 vec,edkUInt64 position){
    edkUChar32 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkUChar64 edkVecUChar64Get(edkVecUChar64 vec,edkUInt64 position){
    edkUChar64 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkUChar64 edkGetVecUChar64(edkVecUChar64 vec,edkUInt64 position){
    edkUChar64 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
//CHAR
edkChar8 edkVecChar8Get(edkVecChar8 vec,edkUInt64 position){
    edkChar8 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkChar8 edkGetVecChar8(edkVecChar8 vec,edkUInt64 position){
    edkChar8 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkChar16 edkVecChar16Get(edkVecChar16 vec,edkUInt64 position){
    edkChar16 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkChar16 edkGetVecChar16(edkVecChar16 vec,edkUInt64 position){
    edkChar16 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkChar32 edkVecChar32Get(edkVecChar32 vec,edkUInt64 position){
    edkChar32 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkChar32 edkGetVecChar32(edkVecChar32 vec,edkUInt64 position){
    edkChar32 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkChar64 edkVecChar64Get(edkVecChar64 vec,edkUInt64 position){
    edkChar64 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkChar64 edkGetVecChar64(edkVecChar64 vec,edkUInt64 position){
    edkChar64 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
//UINT
edkUInt8 edkVecUInt8Get(edkVecUInt8 vec,edkUInt64 position){
    edkUInt8 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkUInt8 edkGetVecUInt8(edkVecUInt8 vec,edkUInt64 position){
    edkUInt8 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkUInt16 edkVecUInt16Get(edkVecUInt16 vec,edkUInt64 position){
    edkUInt16 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkUInt16 edkGetVecUInt16(edkVecUInt16 vec,edkUInt64 position){
    edkUInt16 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkUInt32 edkVecUInt32Get(edkVecUInt32 vec,edkUInt64 position){
    edkUInt32 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkUInt32 edkGetVecUInt32(edkVecUInt32 vec,edkUInt64 position){
    edkUInt32 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkUInt64 edkVecUInt64Get(edkVecUInt64 vec,edkUInt64 position){
    edkUInt64 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkUInt64 edkGetVecUInt64(edkVecUInt64 vec,edkUInt64 position){
    edkUInt64 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
//INT
edkInt8 edkVecInt8Get(edkVecInt8 vec,edkUInt64 position){
    edkInt8 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkInt8 edkGetVecInt8(edkVecInt8 vec,edkUInt64 position){
    edkInt8 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkInt16 edkVecInt16Get(edkVecInt16 vec,edkUInt64 position){
    edkInt16 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkInt16 edkGetVecInt16(edkVecInt16 vec,edkUInt64 position){
    edkInt16 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkInt32 edkVecInt32Get(edkVecInt32 vec,edkUInt64 position){
    edkInt32 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkInt32 edkGetVecInt32(edkVecInt32 vec,edkUInt64 position){
    edkInt32 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkInt64 edkVecInt64Get(edkVecInt64 vec,edkUInt64 position){
    edkInt64 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}
edkInt64 edkGetVecInt64(edkVecInt64 vec,edkUInt64 position){
    edkInt64 ret;
    bool success;
    edkVecGet(vec,position,&ret,&success);
    if(success)
        return ret;
    memset(&ret,0u,sizeof(ret));
    return success;
}

#ifdef __cplusplus
}
#endif
