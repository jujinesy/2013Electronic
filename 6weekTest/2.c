#include<stdio.h>

int main()
{
	FILE *fp, *gp;
	char buf[128];
	int i=0, total=0;
	if( (fp =fopen("input.txt", "r") ) ==NULL ) //input.txt�� ���� fp�� ����
		printf("input ������");
	else if ( (gp=fopen("data2.txt","w") ) ==NULL) // data2.txt�� ����� gp�� ����
		printf("���� data2 ������");
	else
	{
		while(i=fread(buf, 1, 128, fp)) //input���ִ� ������ 128����Ʈ ������ ����
		{
			fwrite(buf, i , 128, gp); //���� ���� data2�� ����
			total++;//�ȱ䰹�� üũ
		}
		printf("��Ż�� %d", total++); //�ȱ� ���� ���
	}
	getchar();
	return 0;
}