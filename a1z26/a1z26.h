#pragma once

#define ENCRYPT_MODE  1
#define DECRYPT_MODE -1

#define END_OF_STRING  0
#define END_OF_NUMBER -128

#define LEN_ALPHA 26
#define MAX_LENGTH 127

#define NULL ((void*) 0)
#define END(x) ((mode == x) ? END_OF_STRING : END_OF_NUMBER)

extern char a1z26(char *to, const char *from, const char mode);