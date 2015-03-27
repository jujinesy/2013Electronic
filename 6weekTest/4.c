#include< stdio.h>

void filecopy(FILE *ifp, FILE *ofp)
{
	int c;

	while((c= getc(ifp)) != EOF)
		putc(c, ofp);
}

int main(int argc, char *argv[])
{
	FILE *fp;
	void filecopy(FILE *, FILE *);

	if (argc == 1)
		filecopy(stdin, stdout); //�о�� ������ �Ⱦ��� ����ڰ� �Է��� ���� ���� ���
	else{
		while (--argc >0){ //�Ͼ�� ������ ������
			if((fp = fopen(*++argv, "r")) ==NULL){ //�����̸��� �ش��ϴ� ������ ������
				printf("cat : can't open %s\n", *argv); //���� ���
				getchar();
				return 1;
			}
			else {
				filecopy(fp, stdout); // �ش��ϴ� ������ ������ ���� ������ ���� ��\ǥ��
				fclose(fp);
			}
		}
	}
	printf("\n");

	getchar();
	return 0;
}