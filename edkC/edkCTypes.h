#ifndef EDKTYPESC_H
#define EDKTYPESC_H

#ifdef __cplusplus
extern "C" {
#endif

//VARS
//
typedef void* edkClassID;

typedef unsigned int    edkTypeID;

typedef unsigned char edkSocketType;

typedef signed   char          edkInt8;
typedef unsigned char          edkUInt8;
typedef signed   short int     edkInt16;
typedef unsigned short int     edkUInt16;

typedef float                  edkFloat32;
typedef double                 edkFloat64;

typedef int                    edkInt32;
typedef unsigned int           edkUInt32;
#if defined(__arch64__) || defined(_LP64)
typedef signed long int        edkInt64;
typedef unsigned long int      edkUInt64;
#else
typedef signed long long int   edkInt64;
typedef unsigned long long int edkUInt64;
#endif

typedef /*signed*/   char      edkChar8;
typedef unsigned char          edkUChar8;
typedef /*signed*/   short int edkChar16;
typedef unsigned short int     edkUChar16;

typedef int                    edkChar32;
typedef unsigned int           edkUChar32;
#if defined(__arch64__) || defined(_LP64)
typedef signed long int        edkChar64;
typedef unsigned long int      edkUChar64;
#else
typedef signed long int        edkChar64;
typedef unsigned long long int edkUChar64;
#endif

//BOOL
#if defined(EDK_USE_STDBOOL)
//#include <stdbool.h>
#else
//else define the bool
enum edkBool{
    edkTrue=1u,
    edkFalse=0u,

    edkBoolSize
};
#if !defined(__cplusplus)
typedef enum edkBool bool;
#define true edkTrue
#define false edkFalse
#endif
#endif

#ifdef __cplusplus
}
#endif

#endif // EDKTYPESC_H
