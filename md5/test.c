#include "md5.h"
#include <string.h>

int main(void)
{
	BYTE text2[] = "abc";

	BYTE buf[16];

	MD5_CTX ctx;

	md5_init(&ctx);
	md5_update(&ctx, text2, strlen(text2));
	md5_final(&ctx, buf);

	return 0;
}
