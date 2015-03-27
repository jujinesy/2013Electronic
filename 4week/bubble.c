#include<stdio.h>

int main()
{
	int A[20], N, Temp, i, j;
	//clrscr();
	printf("버블소트를 이용한 숫자 정렬\n");
	printf("총 숫자 수 : ");
	//정렬할 총 숫자수를 입력
	scanf("%d", &N);

	printf("숫자 요소 입력\n");
	for(i=1; i<=N; i++)
	{
		//숫자요소 값 입력
		scanf("\n\t\t%d", &A[i]);
	}

	//배열 순서상, 이전숫자가 다음숫자보다 크면 자리를 바꿈.
	for(i=1; i<=N-1; i++)
		for(j=1; j<=N-i;j++)
			if(A[j]>A[j+1])
			{
				Temp = A[j];
				A[j] = A[j+1];
				A[j+1] = Temp;
			}
	//정렬된 숫자를 출력
	printf("정렬된 숫자는 ...");
	for(i=1; i<=N ; i++)
		printf("\n\t\t\t%d", A[i]);
	return 0;
}