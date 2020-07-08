#ifndef BACON_H
#define BACON_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "cdef.h"
#include "types.h"

extern int bacon(char *to, char *from, const int mode);
extern void set_char_bacon(const char ch1, const char ch2);
extern int set_alpha_bacon(const char *alpha);
extern void print_bacon(const char * from);
extern void translation(char *to, char *from);
extern void tr(char *to, char *from);

#endif 