#include<stdio.h>

char buffer[2];
int posi;

int main()
{

	FILE *fp;
	int num;
	fp = fopen("test.txt","w+f 10"); // ������ �����ϰ� fp�� ����

	fputs("1111111111", fp); //�� �ؽ�Ʈ ���Ͽ� 1111111111�� ����
	fputs("2222222222", fp); //�� �ؽ�Ʈ ���Ͽ� 2222222222�� ����

	posi = fseek(fp, 12, SEEK_SET); //������ 12��°�� ������

	fgets(buffer, 1 , fp); //12��°���ִ� 1����Ʈ�� ���ۿ� ����
	printf(" The record is %s2\n", buffer); //���� ���
	fclose(fp);
	getchar();
	return 0;
}