#include<stdio.h>

int main(void)
{
	int min, num, i = 0;
	while (1)
	{
		printf("�����͸� �Է��Ͻÿ�(������ �Է��ϸ� ����):");
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
	printf("�ּҰ��� %d", min);

	getchar();
	return 0;
}
