/***************************************************
 * FILENAME :    stdlib.h
 * 
 * DESCRIPTION :
 * 
 * AUTHOR :
 */

#ifndef _LIBRAC3_STDLIB_H_
#define _LIBRAC3_STDLIB_H_

#include "types.h"


//--------------------------------------------------------
__LIBRAC3_INLINE__ void* malloc( unsigned long size );
__LIBRAC3_INLINE__ void free( void* ptr );

#endif // _LIBRAC3_STDLIB_H_