#ifndef SUBS_H

#define SUBS_H

#include "cdef.h"
#include <string.h>

extern int set_alpha_substitute(const char *alpha);
extern int set_vector_substitute(const char *vector);
extern int substitute(char *to, char *from, const int mode);
extern void print_array(char *arr);

#endif