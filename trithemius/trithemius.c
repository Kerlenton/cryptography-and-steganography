#define _CRT_SECURE_NO_WARNINGS
#include "trithemius.h"
#include <string.h>

static char _alpha_trithemius[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static unsigned char _length_trithemius = LEN_ALPHA;

static char _char_trithemius(char key, const char c, const char mode)
{
	for (char *p = _alpha_trithemius; *p != END_OF_STRING; p++)
		if (*p == c)
		{
			key = ((key < 0) ? (_length_trithemius + (key % _length_trithemius)) : (key % _length_trithemius)) * mode;
			return _alpha_trithemius[(p - _alpha_trithemius + key + _length_trithemius) % _length_trithemius];
		}
	return c;
}

static int gkey(int i)
{
	int key = 2 * i * i + 5 * i + 3;
}

extern int set_alpha_trithemius(const char *alpha)
{
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	_length_trithemius = length;
	strcpy(_alpha_trithemius, alpha);

	return 0;
}

extern int trithemius(char *to, char *from, const int mode)
{
	int i = 0;
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	while (*from != END_OF_STRING)
	{
		*to++ = _char_trithemius(gkey(i), *from++, mode);
		i++;
	}
	*to = END_OF_STRING;

	return 0;
}
