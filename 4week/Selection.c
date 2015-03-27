#include<stdio.h>

int main()
{
	int A[20], N, Temp, i, j;
	printf("선택정렬을 이용한 숫자 정렬\n");
	printf("총 숫자 수 : ");
	//정렬할 총 숫자수를 입력
	scanf("%d", &N);
	printf("숫자 요소 입력\n");
	for(i=1; i<=N; i++)
	{
		//숫자요소 값 입력
		scanf("\n\t\t%d", &A[i]);
	}

	//배열 순서상, 맨처음 배열 숫자보다 크기가 작으면 자리 교환함.
	for(i=1; i<=N-1; i++)
		for(j=i+1; j<=N;j++)
			if(A[i]>A[j])
			{
				Temp = A[i];
				A[i] = A[j];
				A[j] = Temp;
			}
	//정렬된 숫자를 출력
	printf("정렬된 숫자는 ...");
	for(i=1; i<=N ; i++)
		printf("\n\t\t\t%d", A[i]);
	return 0;
}