#include<stdio.h>
#include<string.h>
#include<ctype.h>

int getop(char *s,int i)
{
	//��ĭ�̳� ���� �����ϰ� ������� �Է��� ����
	while( ( *s = getchar() ) == ' ' || *s == '\t');
	//����ڰ� �Է��� ���� ���ڰ� �ƴϸ� �Է¹��� ���� ���� ����
	if(!isdigit(*s))
	{
		//���ڿ� ���� �˷��ִ� �� �߰�
		*(s+1)=NULL;
		return *s;
	} else
	{
		//����ڰ� �Է��� ���� ���ڸ� �׵ڿ� ���ڰ� ���������� �Է¹���
		while(isdigit(*(s+i++) = getchar())){}
		//����ڰ� �����ھ��� ���ڸ� �Է��ϸ� ������ ����ϱ� ���� 0����
		if( !strncmp( (s+i-1), "\n", 1) )
				return 0;
		//���ڿ� ���� �˷��ִ� �� �߰�
		*(s+--i) = NULL;
	}
	return 48;
}