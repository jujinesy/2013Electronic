#include<stdio.h>
#include<string.h>
#include<ctype.h>

int getop(char *s,int i)
{
	//빈칸이나 탭은 무시하고 사용자의 입력을 받음
	while( ( *s = getchar() ) == ' ' || *s == '\t');
	//사용자가 입력한 값이 숫자가 아니면 입력받은 값을 고대로 리턴
	if(!isdigit(*s))
	{
		//문자열 끝을 알려주는 널 추가
		*(s+1)=NULL;
		return *s;
	} else
	{
		//사용자가 입력한 값이 숫자면 그뒤에 숫자가 없을때까지 입력받음
		while(isdigit(*(s+i++) = getchar())){}
		//사용자가 연산자없이 숫자만 입력하면 오류를 출력하기 위해 0리턴
		if( !strncmp( (s+i-1), "\n", 1) )
				return 0;
		//문자열 끝을 알려주는 널 추가
		*(s+--i) = NULL;
	}
	return 48;
}