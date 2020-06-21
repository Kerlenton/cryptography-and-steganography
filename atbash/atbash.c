#include "atbash.h"

static char _alpha_atbash[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static unsigned char _length_atbash = LEN_ALPHA;

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

static char _char_atbash(const char c)
{
	for (char *p = _alpha_atbash; *p != END_OF_STRING; p++)
		if (*p == c)
			return _alpha_atbash[_length_atbash - (p - _alpha_atbash) - 1];
	return c;
}

extern char set_alpha_atbash(const char *alpha)
{
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	_length_atbash = (unsigned) length;
	strcpy(_alpha_atbash, alpha);

	return 0;
}

extern void atbash(char *to, const char *from)
{
	while (*from != END_OF_STRING)
		*to++ = _char_atbash(*from++);

	*to = END_OF_STRING;
}
