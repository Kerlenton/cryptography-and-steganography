#include <stdint.h>
#define BUFF_SIZE 1024

size_t strlen(char* s)
{
	size_t length = 0;

	while (*s != '\0')
	{
		s++;
		length++;
	}

	return length;
}

uint8_t power(uint8_t x, uint8_t y)
{
	if (y <= 1) return 1;
	return x * power(x, y - 1);
}

int functionS(uint8_t c)
{
	uint8_t S = power(c, 2) + power(c, 3);
	return S;
}

void trith(uint8_t* c, uint8_t mode, uint8_t* buffer)
{
	uint8_t* C;
	uint8_t i;

	switch(mode)
	{
	case 'E':
		for (i = 0; i < strlen(c); i++)
			buffer[i] = (c[i] + functionS(i)) % 255;
		break;

	case 'D':
		for (i = 0; i < strlen(c); i++)
			buffer[i] = (c[i] - functionS(i)) % 255;
		break;
	}
}
