#include <string.h>
#include <stdio.h>

void reverse(char s[])
{
	int c, i, j;

	//�Ǿտ� �ִ� ���ڿ��� �ǵڿ� �ִ� ���ڿ��� �±�ȯ ���ش�.
	// �ǵڿ��ִ� ���ڿ����� �Ǿտ��ִ� ���ڿ� ������ ����������
	for (i=0, j=strlen(s)-1; i<j; i++, j--)
	{
		c= s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char s[])
{
	int i, sign;

	//��ȣ�� -�� n�� -�� ���Ѵ�
	if ((sign = n) < 0)
		n = -n;
	i =0;

	//s�迭�� n�� 10���� ���� �������� �ƽ�Ű �ڵ尪 '0'�� ���� ���ڷε� ���ڸ� ����.
	do { s[i++] = n % 10 + '0';
	} while((n/=10) > 0);

	//���ڸǵڿ� �ηθ� ���δ�
	if(sign < 0)
		s[i++] = '-';

	//��ȣ�ڿ� ���ڿ����� �˸��� \n�� ���δ�/
	s[i] = '\0';
	reverse(s);
}
void main()
{
	char str[20];
	int val;

	val = 123;
	//���ڸ� ���ڷ� ��ȯ�Ѵ�
	itoa(val, str);

	//���ڿ� ��ȯ�� ���ڸ� ���
	printf("Value = %d, String = %s\n", val, str);
}