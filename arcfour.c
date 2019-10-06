#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define N 256
#define BUFF_SIZE 1024

static inline size_t input_string(uint8_t* buffer)
{
	size_t position = 0;
	uint8_t ch;
	while ((ch = getchar()) != '\n')
		buffer[position++] = ch;
	buffer[position] = '\0';
	return position;
}

static inline void print_array(uint8_t* array, size_t length)
{
	printf("[ ");
	for (size_t i = 0; i < length; ++i)
		printf("%d ", array[i]);
	printf("]\n");
}

key_scheduling_algorithm(uint8_t state[], const uint8_t key[], size_t len)
{
	size_t i, j;
	uint8_t t;

	for (i = 0; i < N; i++)
		state[i] = i;
	for (i = 0, j = 0; i < N; i++)
	{
		j = (j + state[i] + key[i % len]) % N;
		t = state[i];
		state[i] = state[j];
		state[j] = t;
	}
}

void pseudo_random_generation_algorithm(uint8_t state[], uint8_t out[], size_t len)
{
	size_t i, j, idx;
	uint8_t t;

	for (idx = 0, i = 0, j = 0; idx < len; idx++)
	{
		i = (i + 1) % N;
		j = (j + state[i]) % N;

		t = state[i];
		state[i] = state[j];
		state[j] = t;

		out[idx] = state[(state[i] + state[j]) % N];
	}
	out[idx] = '\0';
}

void arcfour(uint8_t* from, uint8_t* to, uint8_t* key)
{
	uint8_t state[N];
	size_t len1 = strlen(key);
	size_t len2 = strlen(from);
	size_t i;

	key_scheduling_algorithm(state, key, len1);
	pseudo_random_generation_algorithm(state, to, len2);

	for (i = 0; i < len2; i++)
	{
		to[i] = to[i] ^ from[i];
	}
}

main()
{
	uint8_t key[] = "key for cipher";
	uint8_t stream[BUFF_SIZE];
	uint8_t stream1[BUFF_SIZE];
	uint8_t buf[BUFF_SIZE];
	size_t length = input_string(stream);

	print_array(stream, length);
	arcfour(stream, buf, key);

	print_array(buf, length);
	arcfour(buf, stream1, key);

	print_array(stream1, length);

	system("PAUSE");
	return 0;
}

