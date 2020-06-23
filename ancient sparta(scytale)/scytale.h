#pragma once

#include <string.h>

#define ENCRYPT_MODE  1
#define DECRYPT_MODE -1

#define END_OF_STRING  0
#define END_OF_NUMBER -128

#define LEN_ALPHA 26
#define MAX_LENGTH 127

#define NULL ((void*) 0)

extern int ancient_sparta(char *to, const char *from, size_t strings, const char mode);
extern void p(char *from, size_t strings);