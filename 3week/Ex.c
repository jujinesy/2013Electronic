#include<stdio.h>
#include<stdlib.h>

//�������� ���������� �˾ƺ��� �Լ�/
extern int getop(char*, int);
//���ڸ� �����ϱ����� ���� �ʱ�ȭ �Լ�
extern void init_stack();
//���ڸ� ���ÿ� �����ϴ� �Լ�
extern void push(double);
//������ ���ڸ� �������� �Լ�
extern double pop();
//������ �޸𸮿� ȯ���ϴ� �Լ�
extern void clear_stack();

int main()
{
	//���� �� �����ڸ� �ӽ������ϴ°�
	int type;
	//�����⸦ ���� �ӽ÷� ���� �����ϴ� ����
	double op2;

	//����ڰ� �Է��� ���ڸ� ���ڿ��� �����ϴ� ��
	char *s = (char*)malloc(sizeof(char));


	//������ �������� �ʱ�ȭ
	init_stack();
	//���� ���
	printf("( - 2) * (4 + 5) equals to 1 2 - 4 5 + *\n");
	//EOF(-1)�� �Էµɶ����� getop ȣ��
	while( (type = getop(s, 1)) != EOF)
	{
		switch(type)
		{

		case 48:
			//s�� ����� ���ڿ� ���ڸ� ���ÿ� ����
			push(atof(s));
			break;
		case '+':
			//+�����ڰ� ������ �ֱٿ� Ǫ���� ���� 2���� ������ ���Ѵ��� �ٽ� Ǫ����
			push(pop() + pop());
			break;
		case '*':
			//*�����ڰ� ������ �ֱٿ� Ǫ���� ���� 2���� ������ ���Ѵ��� �ٽ� Ǫ����
			push(pop() * pop());
			break;
		case '-':
			//-�����ڰ� ������ �ֱٿ� Ǫ���� ���� 2���� ������ �A���� �ٽ� Ǫ����
			push( -1*pop() + pop() );
			break;
		case '/':
			// /�����ڰ� ������ �ֱٿ� Ǫ���� ���� 2���� ������ �������� �ٽ� Ǫ����
			op2 = pop();
			if(op2 != 0.0)
				push( pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n' :
			//������ ������ ���ÿ��� ����� ���ڸ� ������ ����Ѵ�.
			printf("\t%.8g\n", pop());
			break;
		case 0 :
			//����ڰ� �ùٸ� ������ �Է����� ���� ��� ������ �����.
			printf("�ǹٸ� ������ �Է��ϼ���\n");
			break;
		default:
			// ��Ÿ �������� ���� ���� �Է½� ���� ���
			printf("error : unknown command %s\n", s);
			break;
		}
	}
	//���� �޸� ȯ��
	clear_stack();
	//���ڿ� �޸� ȯ��
	free(s);
	return 0;
}