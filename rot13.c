#include <string.h>

void rot13(char* str)
{
	int case_type, idx, len;

	for (idx = 0, len = strlen(str); idx < len; idx++)
	{
		if (str[idx] < 'A' || (str[idx] > 'Z' && str[idx] < 'a') || str[idx] > 'z')
			continue;
		if (str[idx] > 'a')
			case_type = 'a';
		else
			case_type = 'A';
		str[idx] = (str[idx] + 13) % (case_type + 26);
		if (str[idx] < 26)
			str[idx] += case_type;
	}
}
