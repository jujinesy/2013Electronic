#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	//사전식으로 정렬할 포인터형 배열에 값설정
	char *name[] = {"Harry Potter", "Rubeus Hagrid", "Barty Crouch", 
		"Ron Weasley", "Lord Voldemort", "Antonin Dolohov", 
		"Hermione Granger", "Regulus Black", "Lucius Malfoy",
		"Albus Dumbledore", "Alecto Carrow", "James Potter", 
		"Argus Filch", "Amycus Carrow", "Lily Potter"},
		//값을 바꾸기 위한 포인터 temp를 동적할당으로 설정
		*temp=(char*)malloc(sizeof(char));

	//문자열 길이 및 for문을 쓰기위한 변수 선언
	int aleng, i, j;

	// name의 배열 크기는 sizeof(name) = 120
	// name를 구성하는 인지값 크기는 sizeof(*name) = 8
	// 따라서 aleng에는 배열포인터 안에 들어가있는 갯수 15개가 나온다.
	for( i = 0, aleng = sizeof(name)/sizeof(*name) ; i < aleng ; i++)
	{
		//버블소트를 위에서부터한다.
		for( j = i + 1 ; j < aleng ; j++)
		{
			//포인터형 배열이 위에서부터 빠른알파벳이 올수있도록 문자열 비교
			if( strcmp(*(name+i), *(name+j)) > 0 )
			{
				//위 조건에 해당되면 서로 값을 바꾼다.
				temp = *(name+i);
				*(name+i) = *(name+j);
				*(name+j) = temp;
			}
		}
	}

	//정렬된 결과를 순서대로 출력한다.
	for( i=0 ; i < aleng ; i++ )
		printf("%s\n", name[i]);
	getchar();
	return 0;
}


//텍스트로 \n이 들오올떄마다 카운트
//센텐스는 .
//단어 빈도수