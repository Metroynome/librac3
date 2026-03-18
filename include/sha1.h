/***************************************************
 * FILENAME :		sha1.h
 * DESCRIPTION :
 * 		Contains SHA1 related function definitions found in UYA.
 * NOTES :
 * AUTHOR :			
 */

#ifndef _LIBRAC3_SHA1_H_
#define _LIBRAC3_SHA1_H_

/*
 * Computes the SHA1 hash of the input and stores outSize number of bytes of the hash in the output.
 */
int sha1(const void * inBuffer, int inSize, void * outBuffer, int outSize);

#endif // _LIBRAC3_SHA1_H_

