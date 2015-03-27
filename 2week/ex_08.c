#include <stdio.h>
#include <ctype.h>

int atoi(char s[])
{
	int i, n, sign;

	//문자열 중 앞 공백을 제거하기위해 for문 돌려줌
	for(i =0; isspace(s[i]); i++);

	//부호를 정하기위해 -가 있는지 체크
	sign = (s[i] =='-') ? -1 : 1;

	//+와 -가 있다면 다음 포인터로 넘겨줌
	if (s[i] == '+' || s[i] == '-')
		i++;

	//숫자가 아닌 문자열을 만날때까지 숫자로 변환하여 n에 넣어준다
	for(n = 0; isdigit(s[i]); i++)
		//다음 숫자가 나올때마다 이전숫자에 10을 곱해가며 더해준다.
		n=10 * n + (s[i] - '0');

	//변환한 숫자에 부호를 곱해 리턴해줌
	return sign * n;
}

void main()
{
	//문자 포인터에 123을 저장
	char *str = "123";
	int ret;


	//*str문자열을 숫자로 변환
	ret = atoi(str);

	//문자열과 변환된 숫자를 출력
	printf("String = %s, Value = %d\n", str, ret);
}