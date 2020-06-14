#include "bacon.h"

static char _alpha_bacon[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static char _default_char_bacon[2] = { 'A', 'B' };

static char _index_char_bacon(const char ch)
{
	for (char *p = _alpha_bacon; *p != END_OF_STRING; p++)
		if (*p == ch)
			return p - _alpha_bacon;
	return ch + END_OF_NUMBER;
}

static void _encrypt_bacon(char *to, const char *from)
{
	for (; *from != END_OF_STRING; from++)
		*to++ = _index_char_bacon(*from);

	*to = END_OF_NUMBER;
}

static void _decrypt_bacon(char *to, const char *from)
{
	for (; *from != END_OF_NUMBER; from++)
	{
		if (*from < 0)
			*to++ = *from - END_OF_NUMBER;
		else
			*to++ = _alpha_bacon[*from];
	}

	*to = END_OF_STRING;
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

static int power(int x, int y)
{
	if (y <= 0) return 1;
	return x * power(x, y - 1);
}

extern int bacon(char *to, char *from, const int mode)
{
	switch (mode)
	{
	case ENCRYPT_MODE:
		_encrypt_bacon(to, from);
		break;

	case DECRYPT_MODE:
		_decrypt_bacon(to, from);
		break;

	default: return 1;
	}

	return 0;
}

extern void set_char_bacon(const char ch1, const char ch2)
{
	_default_char_bacon[0] = ch1;
	_default_char_bacon[1] = ch2;
}

extern int set_alpha_bacon(const char *alpha)
{
	if (strlen(alpha) >= MAX_LENGTH)
		return 1;
	strcpy(_alpha_bacon, alpha);

	return 0;
}

extern void print_bacon(const char * from)
{
	for (; *from != END_OF_NUMBER; ++from)
		if (*from >= 0)
		{
			Byte x = { .byte = *from };
			printf("%c%c%c%c%c%c%c%c",

				x.bit._7 ? _default_char_bacon[1] : _default_char_bacon[0],
				x.bit._6 ? _default_char_bacon[1] : _default_char_bacon[0],
				x.bit._5 ? _default_char_bacon[1] : _default_char_bacon[0],
				x.bit._4 ? _default_char_bacon[1] : _default_char_bacon[0],
				x.bit._3 ? _default_char_bacon[1] : _default_char_bacon[0],
				x.bit._2 ? _default_char_bacon[1] : _default_char_bacon[0],
				x.bit._1 ? _default_char_bacon[1] : _default_char_bacon[0],
				x.bit._0 ? _default_char_bacon[1] : _default_char_bacon[0]);
		}
		else
			putchar(*from - END_OF_NUMBER);
}

extern void translation(char *to, char *from)
{
	size_t k = 0;
	signed int byte = 7;
	for (char *i = from; *i != END_OF_STRING; i += 8)
	{
		for (char *j = i; byte >= 0; j++)
		{
			if (*j == 'B')
				k += power(2, byte);
			--byte;
		}
		*to++ = _alpha_bacon[k];
		k = 0;
		byte = 7;
	}
	*to = END_OF_STRING;
}

extern void tr(char *to, char *from)
{
	size_t k = 0;
	signed int byte = 7;
	for (char *i = from; *i != END_OF_STRING; i += 8)
	{
		for (char *j = i; byte >= 0; j++)
		{
			if (*j == 'B')
				k += power(2, byte);
			--byte;
		}
		*to++ = k;
		k = 0;
		byte = 7;
	}
	*to = END_OF_NUMBER;
}
