#pragma once

#define ENCRYPT_MODE  1
#define DECRYPT_MODE -1

#define END_OF_STRING  0
#define END_OF_NUMBER -128

#define LEN_ALPHA 26
#define MAX_LENGTH 127

#define NULL ((void*) 0)

extern int set_alpha_caesar(const char *alpha);
extern void print_array(char *arr);
extern void rot13(char *to, char *from);
