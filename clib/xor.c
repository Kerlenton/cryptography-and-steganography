#include "xor.h"

extern void xor(char *to, const char key, const char *from)
{
	char *p = NULL;
	for (p = from; *p != END_OF_STRING; p++)
		to[p - from] = *p ^ key;

	to[p - from] = END_OF_STRING;
}