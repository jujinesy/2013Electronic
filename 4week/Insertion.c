#include<stdio.h>

int main()
{
	int A[20], N, Temp, i, j;
	printf("���������� �̿��� ���� ����\n");
	printf("�� ���� �� : ");
	//������ �� ���ڼ��� �Է�
	scanf("%d", &N);
	printf("���� ��� �Է�\n");
	for(i=1; i<=N; i++)
	{
		//���ڿ�� �� �Է�
		scanf("\n\t\t%d", &A[i]);
	}

	//�迭 ������, ��ó�� �迭 ���ں��� ũ�Ⱑ ������ �ڸ� ��ȯ��.
	for(i=2; i<=N; i++)
	{
		Temp = A[i];
		j = i-1;
		while(Temp<A[j] && j>=1)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = Temp;
	}
	//���ĵ� ���ڸ� ���
	printf("���ĵ� ���ڴ� ...");
	for(i=1; i<=N ; i++)
		printf("\n\t\t\t%d", A[i]);
	return 0;
}