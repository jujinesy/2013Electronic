#include<stdio.h>

//argc에는 뛰어쓰기로 구분된 문자열의 갯수 파일이름까지 포함.
//argv에는 뛰어쓰기로 구분된 문자열이 들어가있다. 파일이름까지 포함됨.
int main(int argc, char *argv[])
{
	int i;

	//문자열의 갯수가 넘지 않을때까지 문자열을 찍기 반복한.
	for(i = 1; i< argc; i++)
		//문자열을 출력하고 다음문자가 있으면 뛰어쓰기 출력.
		printf("%s%s", argv[i], (i<argc -1 ) ? " " : "");

	//개행
	printf("\n");

	//cmd가 바로 종료 되지 않도록 임시로 넣음
	getchar();
	return 0;
}