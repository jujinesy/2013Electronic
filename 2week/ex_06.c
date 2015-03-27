#include<stdio.h>
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	//배열이 0부터 시작임으로 시작점을 맞추기위해 n-1을 해줌
	high = n-1;
	//가장 높은 번째수가 가장 낮은 번째 수 보다 작을때까지 루프를 돌음
	while(low <= high)
	{
		//배열의 중간값을 mid에 저장
		mid = (low + high)/2;
		//찾는값 x보다 mid번째있는 값이 클경우 high에 mid-1을 해줌
		if (x < v[mid])
			high = mid-1;
		//찾는값 x보다 mid번째있는 값이 작을 경우 low에 mid+1을 해줌
		else if (x > v[mid])
			low = mid +1;
		//찾는값 x를 찾았을때 mid를 리턴
		else return mid;
	}
	//값을 못찾았을때 -1을 리턴
	return -1;
}
void main()
{
	int array[10] = {10,21,32,43,54,56,67,78,89,90};
	int ret, fVal;
	//찾을 값 67선언
	fVal = 67;
	//찾을값 67 array배열 인자수 10을 넣고 몇번째인지 값을 찾음
	ret = binsearch(fVal, array, 10);
	//binserarch가 6을 리턴해 주었기때문에, 번째수를 맞춰주어 7을 출력한다
	if(ret !=-1)
		printf("찾는 값 %d가 %d번 째 있습니다.\n", fVal, ret+1);
	else
		printf("찾는 값 %d가 없습니다.\n", fVal, ret);
	//찾을값 11 배열함수명 배열갯수 10을 넣고 binsearch를 실행
	fVal = 11;
	ret = binsearch(fVal, array, 10);
	//값을 못찻기때문에 else밑의 printf가 출력됨.
	if(ret !=-1)
		printf("찾는 값 %d가 %d번 째 있습니다.\n", fVal, ret+1);
	else
		printf("찾는 값 %d가 없습니다.\n", fVal, ret);
}