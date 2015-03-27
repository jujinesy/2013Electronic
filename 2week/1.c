#include <stdio.h>

int main(void)
{
	//변수, 배열 및 파일 포인터를 저장하는 변수 선언
	int ichar = 0, ispace = 0, inum = 0, i = 0, j = 0;
	char buffer[2], temp[2000], temp2[2000];
	FILE *tempFile;

	//파일 포인터 변수에 fopen이 리턴하는 주소를 저장
	tempFile = fopen("input.txt", "r");
	//파일 포인터가 끝을 만날때까지 읽어드린다.
	while (!feof(tempFile))
	{

		//buffer에 2바이트씩 끈어서 저장한다. 이때 뒤에 1바이트는 \n(null)이 들어감
		fgets(buffer, 2, tempFile);

		//역순으로 출력하기위해 temp변수에 차례대로 저장
		temp[i++] = buffer[0];

		//printf("%s", buffer);

		//buffer에 저장된 1바이트 문자가 알파벳 대문자 또는 소문자일때 ichar을 증가
		if ((buffer[0] >= 65 && buffer[0] <= 90) || (buffer[0] >= 97 && buffer[0] <= 122)) {
			ichar++;
			//buffer에 저장된 문자가 공백일때 ispace를 증가
		}
		else if (buffer[0] == 32) {
			ispace++;
			//buffer에 저장된 문자가 숫자일때 inum을 증가
		}
		else if (buffer[0] >= 48 && buffer[0] <= 57)	{
			inum++;
		}

	}

	//파일 포인터 변수 메모리에 반환
	fclose(tempFile);


	//temp에 저장된 문자열을 역순으로 출력하기위해 temp2에 반대로 저장한다
	i--;
	while (i + 1)
	{
		temp2[j++] = temp[i--];
	}
	//temp2 마지막에는 문자열의 끝을 알리는 \n을 추가
	temp2[j] = '\0';


	//역순을 출력하고 글자수 공백수 숫자수를 출력한다.
	printf("%s", temp2);
	printf("\n\n글자수 : %d\n공백수 : %d\n숫자수 : %d", ichar, ispace, inum);


	getchar();
	return 0;
}