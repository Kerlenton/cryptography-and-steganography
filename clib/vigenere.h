#ifndef VIG_H

#define VIG_H

#include "cdef.h"
#include "types.h"
#include <string.h>

extern char set_alpha_vigenere(const char *alpha);
extern char vigenere(char *to, const char *from, const char *key, const char mode);

#endif