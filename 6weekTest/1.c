#include<stdio.h>

int main()
{
	FILE *f1;
	char c;
	f1 = fopen("input.txt","w"); //input.txt ������ ����

	while( (c=getchar()) !=EOF) //EOF�� ���������� input�� �����Ѵ�
		putc(c,f1); 

	fclose(f1);
	f1=fopen("input.txt", "r"); //������ �о�´�

	while( (c=getc(f1)) !=EOF) //EOF�� ���������� ���Ͽ� ���ڸ� �о ���
		printf("%c",c);

	fclose(f1);

	getchar();
	return 0;
}