#include<stdio.h>
#include<stdlib.h>

//숫자인지 연산자인지 알아보는 함수/
extern int getop(char*, int);
//숫자를 저장하기위한 스택 초기화 함수
extern void init_stack();
//숫자를 스택에 저장하는 함수
extern void push(double);
//저장한 숫자를 꺼내오는 함수
extern double pop();
//스택을 메모리에 환원하는 함수
extern void clear_stack();

int main()
{
	//숫자 와 연산자를 임시저장하는곳
	int type;
	//나누기를 위해 임시로 변수 저장하는 변수
	double op2;

	//사용자가 입력한 숫자를 문자열로 저장하는 곳
	char *s = (char*)malloc(sizeof(char));


	//스택을 쓰기위해 초기화
	init_stack();
	//예제 출력
	printf("( - 2) * (4 + 5) equals to 1 2 - 4 5 + *\n");
	//EOF(-1)이 입력될때까지 getop 호출
	while( (type = getop(s, 1)) != EOF)
	{
		switch(type)
		{

		case 48:
			//s에 저장된 문자열 숫자를 스택에 저장
			push(atof(s));
			break;
		case '+':
			//+연산자가 나오면 최근에 푸쉬된 숫자 2개를 꺼내서 더한다음 다시 푸쉬함
			push(pop() + pop());
			break;
		case '*':
			//*연산자가 나오면 최근에 푸쉬된 숫자 2개를 꺼내서 곱한다음 다시 푸쉬함
			push(pop() * pop());
			break;
		case '-':
			//-연산자가 나오면 최근에 푸쉬된 숫자 2개를 꺼내서 뺸다음 다시 푸쉬함
			push( -1*pop() + pop() );
			break;
		case '/':
			// /연산자가 나오면 최근에 푸쉬된 숫자 2개를 꺼내서 나눈다음 다시 푸쉬함
			op2 = pop();
			if(op2 != 0.0)
				push( pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n' :
			//개행이 나오면 스택에서 저장된 숫자를 꺼내서 출력한다.
			printf("\t%.8g\n", pop());
			break;
		case 0 :
			//사용자가 올바른 수식을 입력하지 않을 경우 오류를 출력함.
			printf("옳바른 수식을 입력하세요\n");
			break;
		default:
			// 기타 정해지지 않은 문자 입력시 오류 출력
			printf("error : unknown command %s\n", s);
			break;
		}
	}
	//스택 메모리 환원
	clear_stack();
	//문자열 메모리 환원
	free(s);
	return 0;
}