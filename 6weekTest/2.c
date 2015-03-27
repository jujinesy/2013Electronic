#include<stdio.h>

int main()
{
	FILE *fp, *gp;
	char buf[128];
	int i=0, total=0;
	if( (fp =fopen("input.txt", "r") ) ==NULL ) //input.txt를 열어 fp에 저장
		printf("input 못열음");
	else if ( (gp=fopen("data2.txt","w") ) ==NULL) // data2.txt를 만들어 gp에 저장
		printf("에러 data2 못열음");
	else
	{
		while(i=fread(buf, 1, 128, fp)) //input에있는 내용을 128바이트 단위로 읽음
		{
			fwrite(buf, i , 128, gp); //읽은 값을 data2에 저장
			total++;//옴긴갯수 체크
		}
		printf("토탈은 %d", total++); //옴긴 갯수 출력
	}
	getchar();
	return 0;
}