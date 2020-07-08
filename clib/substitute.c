#include "substitute.h"

static char _alpha_substitute[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static char _vector_substitute[MAX_LENGTH] = "~!@#$%^&*()_+=-0123456789`";

static char _char_substitute(const char *to, const char *from, const char c)
{
	for (char *p = from; *p != END_OF_STRING; p++)
		if (*p == c)
			return to[p - from];
	return c;
}

extern int set_alpha_substitute(const char *alpha)
{
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	char *p = NULL;

	for (p = alpha; *p != END_OF_STRING; p++)
		_alpha_substitute[p - alpha] = *p;

	_alpha_substitute[p - alpha] = END_OF_STRING;

	return 0;
}

extern int set_vector_substitute(const char *vector)
{
	const size_t length = strlen(vector);

	if (length >= MAX_LENGTH)
		return 1;

	char *p = NULL;

	for (p = vector; *p != END_OF_STRING; p++)
		_vector_substitute[p - vector] = *p;

	_vector_substitute[p - vector] = END_OF_STRING;

	return 0;
}

extern int substitute(char *to, char *from, const int mode)
{
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	const char *to_vector = (mode == ENCRYPT_MODE) ? _vector_substitute : _alpha_substitute;
	const char *from_vector = (mode == DECRYPT_MODE) ? _vector_substitute : _alpha_substitute;

	char *p = NULL;
	for (p = from; *p != END_OF_STRING; p++)
		to[p - from] = _char_substitute(to_vector, from_vector, *p);
	to[p - from] = END_OF_STRING;

	return 0;
}

extern void print_array_s(char *arr)
{
	printf("[ ");

	for (char *i = arr; *i != '\0'; i++)
		printf("%c", *i);

	printf(" ]\n");
}