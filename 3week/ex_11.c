#include<stdio.h>
#include<ctype.h>

//���ڿ��� �Ǽ������� �ٲ��ִ� �Լ�
double atof(char s[])
{
	double val, power;
	int	i, sign;

	//�Ǿ� ��������
	for(i=0 ; isspace(s[i]) ; i++);
	//�Ǿտ� -��ȣ�� �̾��� sign�� -1����
	sign = (s[i] == '-') ? -1 : 1;
	//+�� -��ȣ�� �ִٸ� i �� 1����
	if(s[i] == '+' || s[i] == '-')
		i++;
	//s[i]�� �����̸� �ڸ����� �����ָ鼭 ���ڸ�����
	for( val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	//.�� ������ i�� 1����
	if(s[i]== '.')
		i++;
	//s[i]�� �����̸� �ڸ����� �����ָ鼭 ���ڸ� ����. ���ÿ� �Ҽ����� �˼� �ְ� power�� 10�� ������
	for(power = 1.0; isdigit(s[i]) ; i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	//��ȣ�� �׵��Ⱥ�ȯ�ߴ� ���ڸ� �Ҽ������� ����
	return sign * val / power;
}

int main()
{
	double atof(char[]);
	//�����Ϳ� 123456.789���ڿ� ����
	char *dStr = "123456.789";

	//char�� �����͸� ��� �Ǽ������� ��ȯ�� ���� ����ش�.
	printf(" str = %s\n atof value = %f\n", dStr, atof(dStr));

	//cmdâ�� �ٷ� �����°� ��������
	getchar();
	return 0;
}