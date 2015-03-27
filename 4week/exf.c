#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <string.h>

//워드를 저장하기위한 스택값 초기화
extern void init_stack();
//포인터 주소를 넘겨줘서 워드를저장
extern void push(char*);
//이중포인터로 값을 받아옴
extern int pop(char **input);
//포인터로 값을 찾고 몇개 찾았는지 리턴받음
extern int search(char *input);
//스택을 사전시으로 정렬
extern void sort();
//스택사용을 종료하기 위한 함수.
extern void clear_stack();


int main()
{
	//텍스트파일을 읽기위한 파일 포인터 설정
	FILE *tempFile;
	//텍스트파일을 읽기 위한 버퍼설정 및 단어를 저장하기위한 temp 설정
	char *buffer = (char*)malloc(sizeof(char)), 
		*temp=(char*)malloc(sizeof(char));
	//단어 갯수 라인갯수, 센텐스 갯수를 저장하기위한 변수 설정
	int nWord = 0, 
		nLine  = 0, 
		nSent = 0,
		ptr = 0;

	//단어를 저장하기 위한 스택 초기화
	init_stack();
	//텍스트파일을 읽어옴
	tempFile = fopen("text_file.txt", "r");
	//텍스트 파일 끝을 만날떄까지 읽어옴
	while( !feof(tempFile) )
	{
		//텍스트파일을 2바이트씩 buffer에 저장
		fgets(buffer, 2, tempFile);
		//buffer에 저장된 값을 소문자로 변환
		buffer[0]=tolower(buffer[0]);

		//문자열이 올경우 temp에 저장하고 다음값에 문자열 끝을알리는 NULL 추가한다.
		if( buffer[0] >= 'a' && buffer[0] <= 'z') 
		{
			*(temp+ptr++) = *buffer;
			*(temp+ptr) = NULL;
		}
		// 띠어쓰기나 콤마를 만났을 경우는 단어이므로  nWord를 1증가하고 지금까지 저장된 단어가 있으면 저장함.
		if( buffer[0]==' ' || buffer[0]==',' ) 
		{
			nWord++;
			if( ptr != 0 )
			{
				push(temp);
				ptr=0;
			}
		}
		//개행을 만났을경우 nLine을 1증가시키고 지금까지 저장된 단어가있으면 저장함
		if( buffer[0]=='\n' ) 
		{
			nLine++;
			if( ptr != 0 )
			{
				push(temp);
				ptr=0;
			}
		} 
		//문장 끝을 만났을경우 nSent을 1증가시키고 지금까지 저장도니 단어가 있으면 저장함.
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
	//파일을 다읽었으으로 파일 클로즈
	fclose(tempFile);
	//지금까지 스택에 저장된 단어를 사전식으로 정렬
	sort();
	//단어수 개행수 센텐스 수를 출력함.
	printf("단어수 : %d 개행수 : %d 센텐스수 : %d\n", nWord, nLine, nSent);
	//스택에 저장된 단어가 있으면 while가 참이고 없으면 false
	while( pop(&temp) )
	{
		//꺼낸 단어를 출력하고 꺼낸단어가 몇개있는지 출력함.
		printf("%-15s : %d개\n", temp, search(temp));
	}
	//포인터를 메모리에 반환시키기위해 NULL설정
	temp=NULL;
	buffer=NULL;
	//포인터 반환
	free(temp);
	free(buffer);
	//스택 메모리 반환
	clear_stack();
	//cmd가 갑자기 꺼지는 것을 방지하기 위해 임시로 삽입.
	getchar();
	return 0;
}