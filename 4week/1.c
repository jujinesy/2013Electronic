//ALLOCSIZE�� 1000���� ����
#define ALLOCSIZE 1000

//���������� 1000ũ���� ���ڿ��� �����
static char allocbuf[ALLOCSIZE];
//���ڿ� allocbuf�� ����Ű�� �����͸� ���������� �����Ѵ�.
static char *allop=allocbuf;

char *alloc(int n)
{
	//�迭 ũ�⸦ �����ʴ� n�� ������ n��ŭ ��ġ�� ������ �迭���� ����Ű�� �Ͱ���.
	if( allocbuf + ALLOCSIZE -allop >= n)
	{
		allop += n;
		return allop - n;
	}
	//n�� �迭ũ�⸦ ������ �ּҰ� 0�� ����
	else 
		return 0;
}

//������ p�� ALLOCSIZE�� allocbuf�� �պ��� ũ��, ����ڰ� �Է��� p�� allop�ּҿ� �ִ´�.
void afree(char *p)
{
	if (p>= allocbuf && p < allocbuf + ALLOCSIZE)
		allop = p;
}