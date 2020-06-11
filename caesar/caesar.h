#pragma once
#include <stddef.h>

#define ENCRYPT_MODE  1
#define DECRYPT_MODE -1

#define END_OF_STRING  0
#define END_OF_NUMBER -128

#define LEN_ALPHA 26
#define MAX_LENGTH 127

static char _char_caesar(const char key, const char c);

static void strcpy(char *s, char *t);
static size_t strlen(const char *str);

extern int set_alpha_caesar(const char *alpha);
extern int caesar(char *to, char *from, int key, const int mode);
extern void print_array(char *arr, size_t length);
