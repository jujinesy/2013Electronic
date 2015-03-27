#include<stdio.h>
#include<ctype.h>

//문자열을 실수형으로 바꿔주는 함수
double atof(char s[])
{
	double val, power;
	int	i, sign;

	//맨앞 공백제거
	for(i=0 ; isspace(s[i]) ; i++);
	//맨앞에 -부호가 이쓰면 sign에 -1저장
	sign = (s[i] == '-') ? -1 : 1;
	//+나 -부호가 있다면 i 값 1증가
	if(s[i] == '+' || s[i] == '-')
		i++;
	//s[i]가 숫자이면 자리수를 높여주면서 숫자를더함
	for( val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	//.을 만나면 i를 1증가
	if(s[i]== '.')
		i++;
	//s[i]가 숫자이면 자리수를 높여주면서 숫자를 더함. 동시에 소수점을 알수 있게 power도 10씩 곱해줌
	for(power = 1.0; isdigit(s[i]) ; i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	//부호와 그동안변환했던 숫자를 소수점으로 나눔
	return sign * val / power;
}

int main()
{
	double atof(char[]);
	//포인터에 123456.789문자열 저장
	char *dStr = "123456.789";

	//char형 포인터를 찍고 실수형으로 변환한 값을 찍어준다.
	printf(" str = %s\n atof value = %f\n", dStr, atof(dStr));

	//cmd창이 바로 꺼지는걸 막기위해
	getchar();
	return 0;
}