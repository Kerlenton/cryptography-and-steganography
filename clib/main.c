#include <stdio.h>
#include "vigenere.h"

int main(void)
{
	char to[25];
	vigenere(to, "ASK", "HELLO", ENCRYPT_MODE);

	printf("%s", to);

	system("PAUSE");
	return 0;
}