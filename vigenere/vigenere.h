#pragma once

#define ENCRYPT_MODE  1
#define DECRYPT_MODE -1

#define END_OF_STRING  0
#define END_OF_NUMBER -128

#define LEN_ALPHA 26
#define MAX_LENGTH 127

typedef struct {
	char x;
	char y;
} Point;

typedef enum {
	false,
	true
} bool;

typedef union {
	unsigned char byte;
	struct {
		unsigned char _0 : 1;
		unsigned char _1 : 1;
		unsigned char _2 : 1;
		unsigned char _3 : 1;
		unsigned char _4 : 1;
		unsigned char _5 : 1;
		unsigned char _6 : 1;
		unsigned char _7 : 1;
	} bit;
} Byte;


extern char set_alpha_vigenere(const char *alpha);
extern char vigenere(char *to, const char *from, const char *key, const char mode);