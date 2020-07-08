#ifndef ROT13_H

#define ROT13_H

#include "cdef.h"
#include <string.h>

extern int set_alpha_caesar(const char *alpha);
extern void print_array(char *arr);
extern void rot13(char *to, char *from);

#endif
