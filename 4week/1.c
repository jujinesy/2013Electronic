//ALLOCSIZE는 1000으로 정의
#define ALLOCSIZE 1000

//정적변수로 1000크기의 문자열을 만든다
static char allocbuf[ALLOCSIZE];
//문자열 allocbuf을 가르키는 포인터를 정적변수로 선언한다.
static char *allop=allocbuf;

char *alloc(int n)
{
	//배열 크기를 넘지않는 n이 들어오면 n만큼 위치에 떨어진 배열값을 가르키는 것같다.
	if( allocbuf + ALLOCSIZE -allop >= n)
	{
		allop += n;
		return allop - n;
	}
	//n이 배열크기를 넘으면 주소값 0을 리턴
	else 
		return 0;
}

//포인터 p가 ALLOCSIZE와 allocbuf의 합보다 크면, 사용자가 입력한 p를 allop주소에 넣는다.
void afree(char *p)
{
	if (p>= allocbuf && p < allocbuf + ALLOCSIZE)
		allop = p;
}