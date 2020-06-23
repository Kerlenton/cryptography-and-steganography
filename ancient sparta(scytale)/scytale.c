#include "scytale.h"
#include <stdio.h>

static char _default_char_ancient_sparta = 'Z';

static void _encrypt_ancient_sparta(char *to, const char *from, size_t strings)
{
	size_t length = strlen(from);
	size_t columns = (length - 1) / strings + 1;

	for (size_t i = 0; i < columns; ++i)
		for (size_t j = i; j < length; j += columns)
			*to++ = from[j];
	*to = END_OF_STRING;
}

static void _decrypt_ancient_sparta(char *to, const char *from, size_t strings)
{
	const size_t length = strlen(from);

	for (size_t i = 0; i < strings; ++i)
		for (size_t j = i; j < length; j += strings)
			*to++ = from[j];

	*to = END_OF_STRING;
}

extern int ancient_sparta(char *to, const char *from, size_t strings, const char mode)
{
	if (strings < 1)
		return 1;

	switch (mode)
	{
	case ENCRYPT_MODE:
		_encrypt_ancient_sparta(to, from, strings);
		break;

	case DECRYPT_MODE:
		_decrypt_ancient_sparta(to, from, strings);
		break;

	default: return 1;
	}

	return 0;
}

extern void p(char *from, size_t strings)
{
	size_t length = strlen(from);
	size_t columns = (length - 1) / strings + 1;
	size_t i = 0;
	while (i != strings * columns)
	{
		if (from[i] == '\0' || from[i] == -52)
			from[i] = _default_char_ancient_sparta;
		i++;
	}
}
