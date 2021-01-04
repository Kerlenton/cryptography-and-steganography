#include "enigma.h"

const char alpha[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

int main(void)
{
	char buffer[BUFF_SIZE];
	int length = input_string(buffer);

	for (int i = 0; i < length; i++)
	{
		if (buffer[i] >= 'A' && buffer[i] <= 'Z')
			printf("%c", alpha[enigma(buffer[i] - 65, 2, 1, 0, 1)]);
		else
			printf("%c", buffer[i]);
	}

	return 0;
}
