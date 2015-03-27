#include <stdio.h>

int main()
{
	//�迭 �� ���� ����
	int c, i, nwhite, nother, ndigit[10];
	//nwhite, nother �ʱ�ȭ
	nwhite = nother = 0;
	//�迭���� 0���� �ʱ�ȭ
	for(i=0; i < 10; i++)
		ndigit[i]=0;
	//����ڰ� ���͸� ���������� ���� c�� ����
	while((c = getchar()) != '\n')
	{
		switch(c)
		{
			//c���� 0~9�̸�, ndigit�迭�� �˸´� �������� 1 ����
			case '0' : case '1' : case '2' : case '3' :
			case '4' : case '5' : case '6' : case '7' :
			case '8' : case '9' :
				//c-'0'�� 0~9������ ��
				ndigit[c-'0']++;
					break;
				//������̰ų� ���̸� nwhite�� ����
				case ' ' :
				case '\t':
					nwhite++;
					break;
				//��Ÿ�ϰ�� nother�� 1����
				default:
					nother++;
					break;
		}
	}

	printf("digts =");
	//����ڰ� 0~9 ���ڸ� ��� �Է��ߴ��� ���
	for(i=0;i<10;i++)
		printf(" %d", ndigit[i]);
	//nwhite�� nother���� ���� ���
	printf(", white space = %d, other = %d\n", nwhite, nother);

	return 0;
}