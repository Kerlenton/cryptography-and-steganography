#pragma once

#define ENCRYPT_MODE  1
#define DECRYPT_MODE -1

#define END_OF_STRING  0
#define END_OF_NUMBER -128

#define LEN_ALPHA 26
#define MAX_LENGTH 127

typedef union
{
	unsigned char byte;
	struct
	{
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

typedef enum {
	false,
	true
} bool;

typedef unsigned int  size_t;

extern int bacon(char *to, char *from, const int mode);
extern void set_char_bacon(const char ch1, const char ch2);
extern int set_alpha_bacon(const char *alpha);
extern void print_bacon(const char * from);
extern void translation(char *to, char *from);
extern void tr(char *to, char *from);
