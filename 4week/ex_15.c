#include<stdio.h>

//argc에는 뛰어쓰기로 구분된 문자열의 갯수 파일이름까지 포함.
//argv에는 뛰어쓰기로 구분된 문자열이 들어가있다. 파일이름까지 포함됨.
int main(int argc, char *argv[])
{
	//argc값을 먼저 1감소시킨후 0보다 큰지 확인
	while(--argc>0)
		//argv값이 가르키는 주소값을 먼저 4바이트 증가시킨뒤 주소값 참조
		//앞으로 출력할 문자가 있으면 뛰어쓰기함.
		printf("%s%s", *++argv, (argc > 1) ? " ": "");
	//개행
	printf("\n");

	//cmd창 바로 안꺼지게 임시 로만듬.
	getchar();
	return 0;
}