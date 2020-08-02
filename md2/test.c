#include "md2.h"

int main(void)
{
	BYTE text1[1024];
	BYTE buf[1024];
	MD2_CTX ctx;
	size_t length = input_string(text1);

	print_array(text1, length);

	md2_init(&ctx);
	md2_update(&ctx, text1, strlen(text1));
	md2_final(&ctx, buf);

	print_array(buf, 16);

	return 0;
}