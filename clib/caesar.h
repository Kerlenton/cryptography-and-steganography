#ifndef CAESAR_H

#define CAESAR_H

#include "cdef.h"
#include <string.h>
#include <stdio.h>

extern int set_alpha_caesar(const char *alpha);
extern int caesar(char *to, char *from, int key, const int mode);
extern void print_array(char *arr);

#endif