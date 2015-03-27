#include<stdio.h>

char buffer[2];
int posi;

int main()
{

	FILE *fp;
	int num;
	fp = fopen("test.txt","w+f 10"); // 파일을 생성하고 fp에 저장

	fputs("1111111111", fp); //위 텍스트 파일에 1111111111을 저장
	fputs("2222222222", fp); //위 텍스트 파일에 2222222222을 저장

	posi = fseek(fp, 12, SEEK_SET); //오프셋 12번째를 가져옴

	fgets(buffer, 1 , fp); //12번째에있는 1바이트를 버퍼에 저장
	printf(" The record is %s2\n", buffer); //버퍼 출력
	fclose(fp);
	getchar();
	return 0;
}