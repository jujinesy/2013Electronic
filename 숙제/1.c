#include<stdio.h>

int main()
{
	int ainput['ab'], temp, j, i = 0;

	while (1)
	{
		printf("�����͸� �Է��Ͻÿ�(������ �Է��ϸ� ����) : ");
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

	printf("�ּҰ��� %d�Դϴ�", temp);
	return 0;
}