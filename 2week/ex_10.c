#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trim(char s[])
{
	int n;

	//문자열뒤 공백, 탭, 줄바꿈이 있으면 문자열 갯수를 하나씩 줄여가는 과정
	for (n= strlen(s)-1; n>=0;n--)
		if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;

	//문자열 맨뒤에 \n을 넣어 문자열 끝을 알려준다
	s[n+1] = '\0';

	//문자열 갯수를 넘겨준다
	return n;
}

void main()
{
	int i, ret;
	int a[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	char b[30] = "somewhere over the rainbow\n";

	for(i=0; i<20; i++)
	{
		//배열 값중 10이 넘어가는 숫자만 continue를 써서 스킵해줌.
		if(a[i] > 10)
			continue;
		printf("a[%d] = %d\n", i, a[i]);
	}
	
	ret = 0;
	//문자열을 출력하고, 숫자 1을 출력한다
	printf("\nOriginal string = %s ret = %d\n", b, ret+1);

	//맨뒤 공백을 제거했지만 b문자열 맨뒤에 공백이 없기때문에 원본 문자열과 같다.
	ret = trim(b);
	printf("string = %s ret = %d\n", b, ret+1);
}