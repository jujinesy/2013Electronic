#include<stdio.h>
int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	//�迭�� 0���� ���������� �������� ���߱����� n-1�� ����
	high = n-1;
	//���� ���� ��°���� ���� ���� ��° �� ���� ���������� ������ ����
	while(low <= high)
	{
		//�迭�� �߰����� mid�� ����
		mid = (low + high)/2;
		//ã�°� x���� mid��°�ִ� ���� Ŭ��� high�� mid-1�� ����
		if (x < v[mid])
			high = mid-1;
		//ã�°� x���� mid��°�ִ� ���� ���� ��� low�� mid+1�� ����
		else if (x > v[mid])
			low = mid +1;
		//ã�°� x�� ã������ mid�� ����
		else return mid;
	}
	//���� ��ã������ -1�� ����
	return -1;
}
void main()
{
	int array[10] = {10,21,32,43,54,56,67,78,89,90};
	int ret, fVal;
	//ã�� �� 67����
	fVal = 67;
	//ã���� 67 array�迭 ���ڼ� 10�� �ְ� ���°���� ���� ã��
	ret = binsearch(fVal, array, 10);
	//binserarch�� 6�� ������ �־��⶧����, ��°���� �����־� 7�� ����Ѵ�
	if(ret !=-1)
		printf("ã�� �� %d�� %d�� ° �ֽ��ϴ�.\n", fVal, ret+1);
	else
		printf("ã�� �� %d�� �����ϴ�.\n", fVal, ret);
	//ã���� 11 �迭�Լ��� �迭���� 10�� �ְ� binsearch�� ����
	fVal = 11;
	ret = binsearch(fVal, array, 10);
	//���� �����⶧���� else���� printf�� ��µ�.
	if(ret !=-1)
		printf("ã�� �� %d�� %d�� ° �ֽ��ϴ�.\n", fVal, ret+1);
	else
		printf("ã�� �� %d�� �����ϴ�.\n", fVal, ret);
}