#include<stdio.h>

int main(void)
{
	int min, num, i = 0;
	while (1)
	{
		printf("데이터를 입력하시오(음수를 입력하면 종료):");
		scanf("%d", &num);
		if (num <= -1)
		{
			break;
		}
		else
		{
			if (!i)
			{
				min = num;
				i = i + 1;
			}
			else
			{
				if (min>num)
					min = num;
			}
		}
	}
	printf("최소값은 %d", min);

	getchar();
	return 0;
}
