#include <stdio.h>

int main(void)
{
	//����, �迭 �� ���� �����͸� �����ϴ� ���� ����
	int ichar = 0, ispace = 0, inum = 0, i = 0, j = 0;
	char buffer[2], temp[2000], temp2[2000];
	FILE *tempFile;

	//���� ������ ������ fopen�� �����ϴ� �ּҸ� ����
	tempFile = fopen("input.txt", "r");
	//���� �����Ͱ� ���� ���������� �о�帰��.
	while (!feof(tempFile))
	{

		//buffer�� 2����Ʈ�� ��� �����Ѵ�. �̶� �ڿ� 1����Ʈ�� \n(null)�� ��
		fgets(buffer, 2, tempFile);

		//�������� ����ϱ����� temp������ ���ʴ�� ����
		temp[i++] = buffer[0];

		//printf("%s", buffer);

		//buffer�� ����� 1����Ʈ ���ڰ� ���ĺ� �빮�� �Ǵ� �ҹ����϶� ichar�� ����
		if ((buffer[0] >= 65 && buffer[0] <= 90) || (buffer[0] >= 97 && buffer[0] <= 122)) {
			ichar++;
			//buffer�� ����� ���ڰ� �����϶� ispace�� ����
		}
		else if (buffer[0] == 32) {
			ispace++;
			//buffer�� ����� ���ڰ� �����϶� inum�� ����
		}
		else if (buffer[0] >= 48 && buffer[0] <= 57)	{
			inum++;
		}

	}

	//���� ������ ���� �޸𸮿� ��ȯ
	fclose(tempFile);


	//temp�� ����� ���ڿ��� �������� ����ϱ����� temp2�� �ݴ�� �����Ѵ�
	i--;
	while (i + 1)
	{
		temp2[j++] = temp[i--];
	}
	//temp2 ���������� ���ڿ��� ���� �˸��� \n�� �߰�
	temp2[j] = '\0';


	//������ ����ϰ� ���ڼ� ����� ���ڼ��� ����Ѵ�.
	printf("%s", temp2);
	printf("\n\n���ڼ� : %d\n����� : %d\n���ڼ� : %d", ichar, ispace, inum);


	getchar();
	return 0;
}