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
	for(i=1; i<=N-1; i++)
		for(j=i+1; j<=N;j++)
			if(A[i]>A[j])
			{
				Temp = A[i];
				A[i] = A[j];
				A[j] = Temp;
			}
	//���ĵ� ���ڸ� ���
	printf("���ĵ� ���ڴ� ...");
	for(i=1; i<=N ; i++)
		printf("\n\t\t\t%d", A[i]);
	return 0;
}