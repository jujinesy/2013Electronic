#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	//���������� ������ �������� �迭�� ������
	char *name[] = {"Harry Potter", "Rubeus Hagrid", "Barty Crouch", 
		"Ron Weasley", "Lord Voldemort", "Antonin Dolohov", 
		"Hermione Granger", "Regulus Black", "Lucius Malfoy",
		"Albus Dumbledore", "Alecto Carrow", "James Potter", 
		"Argus Filch", "Amycus Carrow", "Lily Potter"},
		//���� �ٲٱ� ���� ������ temp�� �����Ҵ����� ����
		*temp=(char*)malloc(sizeof(char));

	//���ڿ� ���� �� for���� �������� ���� ����
	int aleng, i, j;

	// name�� �迭 ũ��� sizeof(name) = 120
	// name�� �����ϴ� ������ ũ��� sizeof(*name) = 8
	// ���� aleng���� �迭������ �ȿ� ���ִ� ���� 15���� ���´�.
	for( i = 0, aleng = sizeof(name)/sizeof(*name) ; i < aleng ; i++)
	{
		//�����Ʈ�� �����������Ѵ�.
		for( j = i + 1 ; j < aleng ; j++)
		{
			//�������� �迭�� ���������� �������ĺ��� �ü��ֵ��� ���ڿ� ��
			if( strcmp(*(name+i), *(name+j)) > 0 )
			{
				//�� ���ǿ� �ش�Ǹ� ���� ���� �ٲ۴�.
				temp = *(name+i);
				*(name+i) = *(name+j);
				*(name+j) = temp;
			}
		}
	}

	//���ĵ� ����� ������� ����Ѵ�.
	for( i=0 ; i < aleng ; i++ )
		printf("%s\n", name[i]);
	getchar();
	return 0;
}


//�ؽ�Ʈ�� \n�� ����Ë����� ī��Ʈ
//���ٽ��� .
//�ܾ� �󵵼�