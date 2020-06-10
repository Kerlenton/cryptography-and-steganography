#pragma once
#include <stddef.h>

#define MAX_LENGTH 127
#define LEN_ALPHA 26
#define END_OF_STRING '\0'
#define ENCRYPT_MODE 1
#define DECRYPT_MODE -1

static char _char_caesar(const char key, const char c);
static void strcpy(char *s, char *t);
size_t strlen(const char *str);
extern int set_alpha_caesar(const char *alpha);
extern int caesar(char *to, char *from, int key, const int mode);