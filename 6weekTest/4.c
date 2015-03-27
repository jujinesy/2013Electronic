#include< stdio.h>

void filecopy(FILE *ifp, FILE *ofp)
{
	int c;

	while((c= getc(ifp)) != EOF)
		putc(c, ofp);
}

int main(int argc, char *argv[])
{
	FILE *fp;
	void filecopy(FILE *, FILE *);

	if (argc == 1)
		filecopy(stdin, stdout); //읽어올 파일을 안쓰면 사용자가 입력한 값을 고대로 출력
	else{
		while (--argc >0){ //일어올 파일이 있으면
			if((fp = fopen(*++argv, "r")) ==NULL){ //파일이름에 해당하는 파일이 없으면
				printf("cat : can't open %s\n", *argv); //오류 출력
				getchar();
				return 1;
			}
			else {
				filecopy(fp, stdout); // 해당하는 파일이 있으면 파일 내용을 전부 ㅂ\표시
				fclose(fp);
			}
		}
	}
	printf("\n");

	getchar();
	return 0;
}