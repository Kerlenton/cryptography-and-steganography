#include "enigma.h"

int left = 2;
int right = 16;
int middle = 20;

static const char rotors[5][26] = {
	{ 4, 10, 12, 5, 11, 6, 3, 16, 21, 25, 13, 19, 14, 22, 24, 7, 23, 20, 18, 15, 0, 8, 1, 17, 2, 9 },
	{ 0, 9, 3, 10, 18, 8, 17, 20, 23, 1, 11, 7, 22, 19, 12, 2, 16, 6, 25, 13, 15, 24, 5, 21, 14, 4 },
	{ 1, 3, 5, 7, 9, 11, 2, 15, 17, 19, 23, 21, 25, 13, 24, 4, 8, 22, 6, 0, 10, 12, 20, 18, 16, 14 },
	{ 4, 18, 14, 21, 15, 25, 9, 0, 24, 16, 20, 8, 17, 7, 23, 11, 13, 5, 19, 6, 10, 3, 2, 12, 22, 1 },
	{ 21, 25, 1, 17, 6, 8, 19, 24, 20, 15, 18, 3, 13, 7, 11, 23, 0, 22, 12, 9, 16, 14, 5, 4, 2, 10 },

};

static const char reflectors[2][26] = {
	{ 24, 17, 20, 7, 16, 18, 11, 3, 15, 23, 13, 6, 14, 10, 12, 8, 4, 1, 5, 25, 2, 22, 21, 9, 0, 19 },
	{ 24, 17, 20, 7, 16, 18, 11, 3, 15, 23, 13, 6, 14, 10, 12, 8, 4, 1, 5, 25, 2, 22, 21, 9, 0, 19 },
};

static void rotate(int prevrot, int prevpos, int *currpos);
static int diffrot(int next, int prev);
static int antirot(int ch, int rotor);

extern int enigma(int in, int rotor1, int rotor2, int rotor3, int reflector)
{
	int out;

	right = (right + 1) % 26;

	rotate(rotor3, right, &middle);
	rotate(rotor2, middle, &left);

	out = (in + right) % 26;
	out = rotors[rotor3][out];

	out = (out + diffrot(middle, right)) % 26;
	out = rotors[rotor2][out];

	out = (out + diffrot(left, middle)) % 26;
	out = rotors[rotor1][out];

	out = diffrot(out, left);
	out = reflectors[reflector][out];
	out = (out + left) % 26;

	out = antirot(out, rotor1);
	out = diffrot(out, diffrot(left, middle)) % 26;

	out = antirot(out, rotor2);
	out = diffrot(out, diffrot(middle, right)) % 26;

	out = antirot(out, rotor3);
	out = diffrot(out, right);

	return out;
}

extern int input_string(char buffer[])
{
	int pos = 0;
	char ch;

	while (((ch = getchar()) != '\n') && (pos < BUFF_SIZE - 1))
		buffer[pos++] = ch;

	buffer[pos] = '\0';
	return pos;
}

static void rotate(int prevrot, int prevpos, int *currpos)
{
	switch (prevrot)
	{
	case 0:
		if (prevpos == 17)
			*currpos = (*currpos + 1) % 26;
		break;
	case 1:
		if (prevpos == 5)
			*currpos = (*currpos + 1) % 26;
		break;
	case 2:
		if (prevpos == 22)
			*currpos = (*currpos + 1) % 26;
		break;
	}
}

static int diffrot(int next, int prev)
{
	if (next >= prev)
		return next - prev;
	else
		return 26 + (next - prev);
}

static int antirot(int ch, int rotor)
{
	switch (rotor)
	{
	case 0:
		for (int i = 0; i < 26; i++)
		{
			if (rotors[0][i] == ch)
				return i;
		}
		break;

	case 1:
		for (int i = 0; i < 26; i++)
		{
			if (rotors[1][i] == ch)
				return i;
		}
		break;

	case 2:
		for (int i = 0; i < 26; i++)
		{
			if (rotors[2][i] == ch)
				return i;
		}
		break;
	}
}
