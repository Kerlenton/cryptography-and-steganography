#pragma once
#include <stddef.h>

#define ENCRYPT_MODE  1
#define DECRYPT_MODE -1

#define END_OF_STRING  0
#define END_OF_NUMBER -128

#define LEN_ALPHA 26
#define MAX_LENGTH 127

static char _char_trithemius(const char key, const char c, const char mode);
extern int set_alpha_trithemius(const char *alpha);
extern int trithemius(char *to, char *from, const int mode);

static void strcpy(char *s, char *t);
static size_t strlen(const char *str);