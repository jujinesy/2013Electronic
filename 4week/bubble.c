#include<stdio.h>

int main()
{
	int A[20], N, Temp, i, j;
	//clrscr();
	printf("�����Ʈ�� �̿��� ���� ����\n");
	printf("�� ���� �� : ");
	//������ �� ���ڼ��� �Է�
	scanf("%d", &N);

	printf("���� ��� �Է�\n");
	for(i=1; i<=N; i++)
	{
		//���ڿ�� �� �Է�
		scanf("\n\t\t%d", &A[i]);
	}

	//�迭 ������, �������ڰ� �������ں��� ũ�� �ڸ��� �ٲ�.
	for(i=1; i<=N-1; i++)
		for(j=1; j<=N-i;j++)
			if(A[j]>A[j+1])
			{
				Temp = A[j];
				A[j] = A[j+1];
				A[j+1] = Temp;
			}
	//���ĵ� ���ڸ� ���
	printf("���ĵ� ���ڴ� ...");
	for(i=1; i<=N ; i++)
		printf("\n\t\t\t%d", A[i]);
	return 0;
}