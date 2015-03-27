#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str1[2001];
char str2[2001];
char temp[2001];

int main ( void )	{
	//수식을 입력및 연산을 도와줄 변수 선언
	int i, j, k, n1, n2, oper, result;
	

	while ( 1 )	{
		//숫자로 바꿀 문자열을 저장할 temp를 NULL로 초기화
		memset(temp,NULL,sizeof(NULL));

		printf("수식을 입력하세요.\n");
		//사용자가 엔터를 누를때까지 문자열을 str1에 저장
		gets ( str1 );

		for( i = 0, k =0 ; i < strlen(str1) ; i++ )
		{
			//숫자로 바뀔 문자열을 저장
			temp[k++] = str1[i];

			if( str1[i] == '+' ) {
				//+기호가 나오면, +기호 이전 문자들을 숫자로 변환. 그리고 temp를 다시사용하기 위해 NULL로 초기화. oper는 추후에 계산될 연산을 저장
				n1 = atoi(temp);
				memset(temp,NULL,sizeof(temp));
				oper = 0;
				break;
			}else if( str1[i] == '-' ) {
				//-기호가 나오면, -기호 이전 문자들을 숫자로 변환. 그리고 temp를 다시사용하기 위해 NULL로 초기화. oper는 추후에 계산될 연산을 저장
				n1 = atoi(temp);
				memset(temp,NULL,sizeof(temp));
				oper = 1;
				break;
			}else if( str1[i] == '*' ) {
				//*기호가 나오면, *기호 이전 문자들을 숫자로 변환. 그리고 temp를 다시사용하기 위해 NULL로 초기화. oper는 추후에 계산될 연산을 저장
				n1 = atoi(temp);
				memset(temp,NULL,sizeof(temp));
				oper = 2;
				break;
			}else if( str1[i] == '/' ) {
				///기호가 나오면, /기호 이전 문자들을 숫자로 변환. 그리고 temp를 다시사용하기 위해 NULL로 초기화. oper는 추후에 계산될 연산을 저장
				n1 = atoi(temp);
				memset(temp,NULL,sizeof(temp));
				oper = 3;
				break;
			}
		}
		for( j = i+1, k =0  ; j < strlen(str1) ; j++ )
		{
			//숫자로 바뀔 문자열을 저장
			temp[k++] = str1[j];


			//다음 연산자가 나오거나 =이 나오면 지금까지 저장된 문자열을 숫자로 저장. temp를 다시 사용하기위해 NULL로 초기화
			if( str1[j] == '+' || str1[j] == '-' || str1[j] == '*' || str1[j] == '/' || str1[j] == '=' ) {
				n2 = atoi(temp);
				memset(temp,NULL,sizeof(temp));
				break;
			}
		}
		// 마지막 기호가 =이 아니면 다시 입력받도록 하였음.
		if( str1[strlen(str1)-1] != '=')
			continue;
		//가장 앞에있는 숫자 연산을 하는 기능
		if(oper == 0){
			result = n1 + n2;
		}else if(oper == 1){
			result = n1 - n2;
		}else if(oper == 2){
			result = n1 * n2;
		}else if(oper == 3){
			result = n1 / n2;
		}

		printf("%d\n", result);
	}

	return 0;
}