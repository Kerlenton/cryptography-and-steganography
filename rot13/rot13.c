#include "rot13.h"

#define NULL ((void*) 0)

static char _alpha_rot13[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static unsigned char _length_rot13 = LEN_ALPHA;

static char _char_rot13(const char ch)
{
	if (_alpha_rot13[0] <= ch && ch <= _alpha_rot13[_length_rot13 - 1])
		return ch % _length_rot13 + _alpha_rot13[0];
	return ch;
}

static void strcpy(char *s, char *t)
{
	while (*s++ = *t++)
		;
}

static size_t strlen(const char *str)
{
	size_t len = 0;
	while (*str++)
		len++;

	return len;
}


extern int set_alpha_rot13(const char *alpha)
{
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	_length_rot13 = length;
	strcpy(_alpha_rot13, alpha);

	return 0;
}

/*extern void print_array(char *arr)
{
	printf("[ ");

	for (char *i = arr; *i != '\0'; i++)
		printf("%c", *i);

	printf(" ]\n");
}*/

extern void rot13(char *to, char *from)
{
	char *p = NULL;
	for (p = from; *p != END_OF_STRING; p++)
		to[p - from] = _char_rot13(*p);
	to[p - from] = END_OF_STRING;
}