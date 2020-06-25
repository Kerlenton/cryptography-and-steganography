#pragma once

#define ENCRYPT_MODE  1
#define DECRYPT_MODE -1

#define END_OF_STRING  0
#define END_OF_NUMBER -128

#define LEN_ALPHA 26
#define MAX_LENGTH 127

#define NULL ((void*) 0)

extern int set_alpha_substitute(const char *alpha);
extern int set_vector_substitute(const char *vector);
extern int substitute(char *to, char *from, const int mode);
extern void print_array(char *arr);