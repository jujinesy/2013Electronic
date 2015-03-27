#include <stdio.h>
#include <ctype.h>

int atoi(char s[])
{
	int i, n, sign;

	//���ڿ� �� �� ������ �����ϱ����� for�� ������
	for(i =0; isspace(s[i]); i++);

	//��ȣ�� ���ϱ����� -�� �ִ��� üũ
	sign = (s[i] =='-') ? -1 : 1;

	//+�� -�� �ִٸ� ���� �����ͷ� �Ѱ���
	if (s[i] == '+' || s[i] == '-')
		i++;

	//���ڰ� �ƴ� ���ڿ��� ���������� ���ڷ� ��ȯ�Ͽ� n�� �־��ش�
	for(n = 0; isdigit(s[i]); i++)
		//���� ���ڰ� ���ö����� �������ڿ� 10�� ���ذ��� �����ش�.
		n=10 * n + (s[i] - '0');

	//��ȯ�� ���ڿ� ��ȣ�� ���� ��������
	return sign * n;
}

void main()
{
	//���� �����Ϳ� 123�� ����
	char *str = "123";
	int ret;


	//*str���ڿ��� ���ڷ� ��ȯ
	ret = atoi(str);

	//���ڿ��� ��ȯ�� ���ڸ� ���
	printf("String = %s, Value = %d\n", str, ret);
}