#include "vigenere.h"
#include <string.h>
#include <stdio.h>

static char _alpha_vigenere[MAX_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static char _length_vigenere = LEN_ALPHA;

static _char_vigenere(const char ch, char key, const char mode)
{
	char c, *p = NULL;
	bool flag[2] = { false , false };

	for (p = _alpha_vigenere; *p != END_OF_STRING; p++)
	{
		if (*p == ch)
		{
			c = (p - _alpha_vigenere);
			flag[0] = true;
		}

		if (*p == key)
		{
			key = (p - _alpha_vigenere) * mode;
			flag[1] = true;
		}

		if (flag[0] && flag[1])
			break;
	}

	if (flag[0] && flag[1])
		return _alpha_vigenere[(c + key + _length_vigenere) % _length_vigenere];

	return ch;
}

main()
{
	char s[30];
	char t[] = "ATTACKATDAWN";
	vigenere(s, t, "LEMON", ENCRYPT_MODE);
	printf("%s", s);

	system("PAUSE");
	return 0;
}

extern char set_alpha_vigenere(const char *alpha)
{
	const unsigned int length = strlen(alpha);
	if (length >= MAX_LENGTH)
		return 1;

	_length_vigenere = (char)length;
	char *p = NULL;

	for (p = alpha; *p != END_OF_STRING; ++p)
		_alpha_vigenere[p - alpha] = *p;

	_alpha_vigenere[p - alpha] = END_OF_STRING;

	return 0;
}

extern char vigenere(char * const to, const char *from, const char *key, const char mode)
{
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	const unsigned int length = strlen(key);
	char *p = NULL;

	for (p = from; *p != END_OF_STRING; ++p)
		to[p - from] = _char_vigenere(*p, key[(p - from) % length], mode);

	to[p - from] = END_OF_STRING;

	return 0;
}