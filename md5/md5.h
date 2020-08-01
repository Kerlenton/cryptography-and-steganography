#ifndef MD5_H
#define MD5_H

#include <stddef.h>

#define MD5_BLOCK_SIZE 16

typedef unsigned char BYTE;
typedef unsigned int WORD;

typedef struct
{
	BYTE data[64];
	WORD datalen;
	unsigned long long bitlen;
	WORD state[4];
} MD5_CTX;

#endif
