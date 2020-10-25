#include <stdio.h>
#include <stdint.h>
#include <string.h>

int prob[26] = {0};
float sum = 0;
float q = 0;

void length_of_key(char *s, int t)
{
	int n = t;
	int length = strlen(s);
	
	for (int i = 0; i < n; i++)
	{

		while (t + i < length)
		{
			++prob[s[t + i] - 97];
			++q;
			t += n;
		}

		for (int j = 0; j < 26; j++)
		{
			float h = prob[j];
			sum += (h / q) * (h / q);
		}
		
		for (int k = 0; k < 26; k++)
			prob[k] = 0;

		printf("%f\n", sum);

		q = 0;
		sum = 0;
		t = 0;
		
	}
}

int main(void)
{
	char n[] = "gevcdrweviqfouhnfegbbtkeduwopawoqsrngivpoabtkrrughruwtkefiwyrfsauivbhgdnwolnyevtlgdthtkefoqnhcwirneewwheqtkepiqddngbrdbaqdkoztkewwriqthrdcwhlspalnlnilxeqchsioudxaoivmzeuewhhooogydngpkyvifswhhtkerrboqtkegudllspoimlngaqdeogylsgevcdrwevsvigndtxrhdrcwrlnhaqdseumhawevowhhrwhhouihs";
	
	for (int i = 1; i < 10; i++)
	{
		length_of_key(n, i);
		printf("\n");
	}
	system("PAUSE");
	return 0;
}
