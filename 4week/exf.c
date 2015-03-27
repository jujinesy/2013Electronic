#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <string.h>

//���带 �����ϱ����� ���ð� �ʱ�ȭ
extern void init_stack();
//������ �ּҸ� �Ѱ��༭ ���带����
extern void push(char*);
//���������ͷ� ���� �޾ƿ�
extern int pop(char **input);
//�����ͷ� ���� ã�� � ã�Ҵ��� ���Ϲ���
extern int search(char *input);
//������ ���������� ����
extern void sort();
//���û���� �����ϱ� ���� �Լ�.
extern void clear_stack();


int main()
{
	//�ؽ�Ʈ������ �б����� ���� ������ ����
	FILE *tempFile;
	//�ؽ�Ʈ������ �б� ���� ���ۼ��� �� �ܾ �����ϱ����� temp ����
	char *buffer = (char*)malloc(sizeof(char)), 
		*temp=(char*)malloc(sizeof(char));
	//�ܾ� ���� ���ΰ���, ���ٽ� ������ �����ϱ����� ���� ����
	int nWord = 0, 
		nLine  = 0, 
		nSent = 0,
		ptr = 0;

	//�ܾ �����ϱ� ���� ���� �ʱ�ȭ
	init_stack();
	//�ؽ�Ʈ������ �о��
	tempFile = fopen("text_file.txt", "r");
	//�ؽ�Ʈ ���� ���� ���������� �о��
	while( !feof(tempFile) )
	{
		//�ؽ�Ʈ������ 2����Ʈ�� buffer�� ����
		fgets(buffer, 2, tempFile);
		//buffer�� ����� ���� �ҹ��ڷ� ��ȯ
		buffer[0]=tolower(buffer[0]);

		//���ڿ��� �ð�� temp�� �����ϰ� �������� ���ڿ� �����˸��� NULL �߰��Ѵ�.
		if( buffer[0] >= 'a' && buffer[0] <= 'z') 
		{
			*(temp+ptr++) = *buffer;
			*(temp+ptr) = NULL;
		}
		// ���⳪ �޸��� ������ ���� �ܾ��̹Ƿ�  nWord�� 1�����ϰ� ���ݱ��� ����� �ܾ ������ ������.
		if( buffer[0]==' ' || buffer[0]==',' ) 
		{
			nWord++;
			if( ptr != 0 )
			{
				push(temp);
				ptr=0;
			}
		}
		//������ ��������� nLine�� 1������Ű�� ���ݱ��� ����� �ܾ������ ������
		if( buffer[0]=='\n' ) 
		{
			nLine++;
			if( ptr != 0 )
			{
				push(temp);
				ptr=0;
			}
		} 
		//���� ���� ��������� nSent�� 1������Ű�� ���ݱ��� ���嵵�� �ܾ ������ ������.
		if( buffer[0] == '.' || buffer[0] == '?' || buffer[0] == '!'  )	 
		{
			nSent++;
			if( ptr != 0 )
			{
				push(temp);
				ptr=0;
			}
		}
	}
	//������ ���о������� ���� Ŭ����
	fclose(tempFile);
	//���ݱ��� ���ÿ� ����� �ܾ ���������� ����
	sort();
	//�ܾ�� ����� ���ٽ� ���� �����.
	printf("�ܾ�� : %d ����� : %d ���ٽ��� : %d\n", nWord, nLine, nSent);
	//���ÿ� ����� �ܾ ������ while�� ���̰� ������ false
	while( pop(&temp) )
	{
		//���� �ܾ ����ϰ� �����ܾ ��ִ��� �����.
		printf("%-15s : %d��\n", temp, search(temp));
	}
	//�����͸� �޸𸮿� ��ȯ��Ű������ NULL����
	temp=NULL;
	buffer=NULL;
	//������ ��ȯ
	free(temp);
	free(buffer);
	//���� �޸� ��ȯ
	clear_stack();
	//cmd�� ���ڱ� ������ ���� �����ϱ� ���� �ӽ÷� ����.
	getchar();
	return 0;
}