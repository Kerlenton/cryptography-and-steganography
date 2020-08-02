#ifndef MD2_H
#define MD2_H

#include <stddef.h>
#define MD2_BLOCK_SIZE 16

typedef unsigned char BYTE;         

typedef struct {
	BYTE data[16];
	BYTE state[48];
	BYTE checksum[16];
	int len;
} MD2_CTX;

void md2_init(MD2_CTX *ctx);
void md2_update(MD2_CTX *ctx, const BYTE data[], size_t len);
void md2_final(MD2_CTX *ctx, BYTE hash[]);  
size_t input_string(BYTE* buffer);

#endif