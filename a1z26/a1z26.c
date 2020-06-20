#include "a1z26.h"
#include <stdio.h>

extern char a1z26(char *to, const char *from, const char mode)
{
	if (mode != ENCRYPT_MODE && mode != DECRYPT_MODE)
		return 1;

	char buffer[2];

	switch (mode)
	{
	case ENCRYPT_MODE:
		buffer[0] = 'A';
		buffer[1] = 'Z';
		break;
	case DECRYPT_MODE:
		buffer[0] = 1;
		buffer[1] = 26;
		break;
	}

	for (; *from != END(ENCRYPT_MODE); from++)
	{
		if (buffer[0] <= *from && *from <= buffer[1])
			*to++ = *from + (-mode * 'A') + mode;
		else
			*to++ = *from + (mode * END_OF_NUMBER);
	}

	*to = END(DECRYPT_MODE);
	return 0;
}

main()
{
	char *h = "HELLO";
	char s[50];
	char q[50];

	a1z26(s, h, ENCRYPT_MODE);

	for (char *p = s; *p != END_OF_NUMBER; p++)
	{
		printf("%d\n", *p);
	}

	a1z26(q, s, DECRYPT_MODE);
	printf("%s", q);
	printf("%d", 'A');

	system("PAUSE");
	return 0;
}