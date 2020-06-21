#pragma once

#define ENCRYPT_MODE  1
#define DECRYPT_MODE -1

#define END_OF_STRING  0
#define END_OF_NUMBER -128

#define LEN_ALPHA 26
#define MAX_LENGTH 127

typedef unsigned int size_t;

extern char set_alpha_atbash(const char *alpha);
extern void atbash(char *to, const char *from);