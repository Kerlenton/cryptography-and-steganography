void caesar(char s[], int key, char mode)
{
	int i;
	char c;

	switch(mode)
	{
    case 'E': case 'e':
        for (i = 0; s[i] != '\0'; i++)
	{
		c = s[i];

		if (c >= 'a' && c <= 'z')
		{
			c += key;

			if (c > 122)
			{
				c -= 26;
				s[i] = c; continue;
			}
			else
				s[i] = c; continue;
		}

		if (c >= 'A' && c <= 'Z')
		{
			c += key;

			if (c > 90)
			{
				c -= 26;
				s[i] = c; continue;
			}
			else
				s[i] = c; continue;
		}

		if (c >= '0' && c <= '9')
		{
			c += key;

			if (c > 57)
			{
				c -= 10;
				s[i] = c; continue;
			}
			else
				s[i] = c; continue;
		}
	}
	s[i] = '\0'; break;
	case 'D': case 'd':
			
        for (i = 0; s[i] != '\0'; i++)
	{
		c = s[i];

		if (c >= 'a' && c <= 'z')
		{
			c -= key;

			if (c < 97)
			{
				c += 26;
				s[i] = c; continue;
			}
			else
				s[i] = c; continue;
		}

		if (c >= 'A' && c <= 'Z')
		{
			c -= key;

			if (c < 65)
			{
				c += 26;
				s[i] = c; continue;
			}
			else
				s[i] = c; continue;
		}

		if (c >= '0' && c <= '9')
		{
			c -= key;

			if (c < 48)
			{
				c += 10;
				s[i] = c; continue;
			}
			else
				s[i] = c; continue;
		}
	}
	s[i] = '\0'; break;
	}
}

