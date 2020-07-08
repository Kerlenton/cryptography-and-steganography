#ifndef ATBASH_H

#define ATBASH_H

#include <string.h>
#include "cdef.h"

extern char set_alpha_atbash(const char *alpha);
extern void atbash(char *to, const char *from);

#endif