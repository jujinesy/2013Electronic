#include <string.h>
#include <stdio.h>

void reverse(char s[])
{
	int c, i, j;

	//맨앞에 있는 문자열과 맨뒤에 있는 문자열을 맞교환 해준다.
	// 맨뒤에있는 문자열수가 맨앞에있는 문자열 수보다 작을때까지
	for (i=0, j=strlen(s)-1; i<j; i++, j--)
	{
		c= s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int n, char s[])
{
	int i, sign;

	//부호가 -면 n에 -를 곱한다
	if ((sign = n) < 0)
		n = -n;
	i =0;

	//s배열에 n을 10으로 나눈 나머지에 아스키 코드값 '0'을 더해 문자로된 숫자를 저장.
	do { s[i++] = n % 10 + '0';
	} while((n/=10) > 0);

	//숫자맨뒤에 부로를 붙인다
	if(sign < 0)
		s[i++] = '-';

	//부호뒤에 문자열끝을 알리는 \n을 붙인다/
	s[i] = '\0';
	reverse(s);
}
void main()
{
	char str[20];
	int val;

	val = 123;
	//숫자를 문자로 변환한다
	itoa(val, str);

	//숫자와 변환된 문자를 출력
	printf("Value = %d, String = %s\n", val, str);
}