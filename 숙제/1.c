#include<stdio.h>

int main()
{
	int ainput['ab'], temp, j, i = 0;

	while (1)
	{
		printf("데이터를 입력하시오(음수를 입력하면 종료) : ");
		scanf("%d", &temp);

		if (temp != -1)
		{
			ainput[i++] = temp;
		}
		else
		{
			break;
		}

	}
	temp = ainput[0];
	for (j = 1; j < i; j++)
	{
		if (ainput[j] < temp)
			temp = ainput[j];
	}

	printf("최소값은 %d입니다", temp);
	return 0;
}