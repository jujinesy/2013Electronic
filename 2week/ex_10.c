#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trim(char s[])
{
	int n;

	//���ڿ��� ����, ��, �ٹٲ��� ������ ���ڿ� ������ �ϳ��� �ٿ����� ����
	for (n= strlen(s)-1; n>=0;n--)
		if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;

	//���ڿ� �ǵڿ� \n�� �־� ���ڿ� ���� �˷��ش�
	s[n+1] = '\0';

	//���ڿ� ������ �Ѱ��ش�
	return n;
}

void main()
{
	int i, ret;
	int a[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	char b[30] = "somewhere over the rainbow\n";

	for(i=0; i<20; i++)
	{
		//�迭 ���� 10�� �Ѿ�� ���ڸ� continue�� �Ἥ ��ŵ����.
		if(a[i] > 10)
			continue;
		printf("a[%d] = %d\n", i, a[i]);
	}
	
	ret = 0;
	//���ڿ��� ����ϰ�, ���� 1�� ����Ѵ�
	printf("\nOriginal string = %s ret = %d\n", b, ret+1);

	//�ǵ� ������ ���������� b���ڿ� �ǵڿ� ������ ���⶧���� ���� ���ڿ��� ����.
	ret = trim(b);
	printf("string = %s ret = %d\n", b, ret+1);
}