#include<stdio.h>

int main()
{
	FILE *f1;
	char c;
	f1 = fopen("input.txt","w"); //input.txt 파일을 만듬

	while( (c=getchar()) !=EOF) //EOF를 만날때까지 input에 저장한다
		putc(c,f1); 

	fclose(f1);
	f1=fopen("input.txt", "r"); //파일을 읽어온다

	while( (c=getc(f1)) !=EOF) //EOF가 있을때까지 파일에 글자를 읽어서 출력
		printf("%c",c);

	fclose(f1);

	getchar();
	return 0;
}