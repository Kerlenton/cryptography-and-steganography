#define _CRT_SECURE_NO_WARNINGS
#include "caesar.h"

static char _alpha_caesar[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static unsigned char _length_caesar = LEN_ALPHA;

static char _char_caesar(const char key, const char c)
{
	for (char *p = _alpha_caesar; *p != END_OF_STRING; p++)
		if (*p == c)
			return _alpha_caesar[(p - _alpha_caesar + key + _length_caesar) % _length_caesar];
	return c;
}

extern int set_alpha_caesar(const char *alpha)
{
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	_length_caesar = length;
	strcpy(_alpha_caesar, alpha);

	return 0;
}

extern int caesar(char *to, char *from, int key, const int mode)
{
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	key = ((key < 0) ? (_length_caesar + (key % _length_caesar)) : (key % _length_caesar)) * mode;

	while (*from != END_OF_STRING)
		*to++ = _char_caesar(key, *from++);

	*to = END_OF_STRING;

	return 0;
}

extern void print_array(char *arr)
{
	printf("[ ");

	for (char *i = arr; *i != '\0'; i++)
		printf("%c", *i);

	printf(" ]\n");
}