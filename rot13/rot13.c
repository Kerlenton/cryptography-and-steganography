#define _CRT_SECURE_NO_WARNINGS
#include "rot13.h"
#include <string.h>

static char _alpha_rot[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static unsigned char _length_caesar = LEN_ALPHA;

static char _char_rot13(const char ch)
{
	if (_alpha_rot[0] <= ch && ch <= _alpha_rot[_length_caesar - 1])
		return ch % _length_caesar + _alpha_rot[0];
	return ch;
}

extern int set_alpha_caesar(const char *alpha)
{
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	_length_caesar = length;
	strcpy(_alpha_rot, alpha);

	return 0;
}

extern void print_array(char *arr)
{
	printf("[ ");

	for (char *i = arr; *i != '\0'; i++)
		printf("%c", *i);

	printf(" ]\n");
}

extern void rot13(char *to, char *from)
{
	char *p = NULL;
	for (p = from; *p != END_OF_STRING; p++)
		to[p - from] = _char_rot13(*p);
	to[p - from] = END_OF_STRING;
}
