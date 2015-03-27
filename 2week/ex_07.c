#include <stdio.h>

int main()
{
	//배열 및 변수 선언
	int c, i, nwhite, nother, ndigit[10];
	//nwhite, nother 초기화
	nwhite = nother = 0;
	//배열값을 0으로 초기화
	for(i=0; i < 10; i++)
		ndigit[i]=0;
	//사용자가 엔터를 누를때까지 값을 c에 저장
	while((c = getchar()) != '\n')
	{
		switch(c)
		{
			//c값이 0~9이면, ndigit배열에 알맞는 번지수를 1 증가
			case '0' : case '1' : case '2' : case '3' :
			case '4' : case '5' : case '6' : case '7' :
			case '8' : case '9' :
				//c-'0'은 0~9사이의 값
				ndigit[c-'0']++;
					break;
				//빈공간이거나 탭이면 nwhite값 증가
				case ' ' :
				case '\t':
					nwhite++;
					break;
				//기타일경우 nother값 1증가
				default:
					nother++;
					break;
		}
	}

	printf("digts =");
	//사용자가 0~9 숫자를 몇번 입력했는지 출력
	for(i=0;i<10;i++)
		printf(" %d", ndigit[i]);
	//nwhite와 nother값을 각각 출력
	printf(", white space = %d, other = %d\n", nwhite, nother);

	return 0;
}