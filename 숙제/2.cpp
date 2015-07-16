#include<stdio.h>

int main()
{
	int a, b, c, i = 0;
	for (a = 1; a < 100; a++)
	{
		for (b = 1; b < 100; b++)
		{
			for (c = 1; c < 100; c++)
			{
				if (a*a + b*b == c*c)
				{
					printf("a : %d, b : %d, c : %d\n", a, b, c);
					i++;
				}
			}
		}
	}
	printf("\n\n\n¸¸Á·ÇÏ´Â »ï°¢Çü °¹¼ö´Â ÃÑ %d°³", i);

	getchar();
	return 0;
}