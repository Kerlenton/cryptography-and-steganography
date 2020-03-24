#include <stdint.h>

#define u8 uint8_t
#define u32 uint32_t
#define u64 uint64_t

void split_256_to_32bits(u8 *block256b, u32 *blocks32b)
{
	u8 *p8 = block256b;

	for (u32 *p32 = blocks32b; p32 < blocks32b + 8; p32++)
	{
		for (size_t i = 0; i < 4; i++)
		{
			*p32 = (*p32 << 8) | *(p8 + i);
		}

		p8 += 4;
	}
}

void split_64bits_to_32bits(u64 block64b, u32 block32b_1, u32 block32b_2)
{
	block32b_2 = (u32)block64b;
	block32b_1 = (u32)(block64b >> 32);
}

void split_64bits_to_8bits(u64 block64b, u8 *blocks8b)
{
	for (size_t i = 0; i < 8; i++)
	{
		blocks8b[i] = (u8)(block64b >> (7 - i) * 8);
	}
}

void split_32bits_to_8bits(u32 block32b, u8 *blocks8b)
{
	for (size_t i = 0; i < 4; i++)
	{
		blocks8b[i] = (u8)(block32b >> 24 - (i * 8));
	}
}

u64 join_32bits_to_64bits(u32 blocks32b_1, u32 blocks32b_2)
{
	u64 block64b;

	block64b = blocks32b_2;
	block64b = (block64b << 32) | blocks32b_1;

	return block64b;
}

u64 join_8bits_to_64bits(u8 *blocks8b)
{
	u64 block64b;

	for (u8 *p = blocks8b; p < blocks8b + 8; p++)
	{
		block64b = (block64b << 8) | *p;
	}

	return block64b;
}

u32 join_4bits_to_32bits(u8 *blocks4b)
{
	u32 block32b;

	for (size_t i = 0; i < 4; i++)
	{
		block32b = (block32b << 8) | blocks4b[i];
	}

	return block32b;
}
