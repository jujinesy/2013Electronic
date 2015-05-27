#include<Windows.h>
#include<math.h>
//for문을 쓰기위한 변수선언
int i;

int main()
{
	//마우스 왼쪽 오른쪽버튼 바꿈
	SwapMouseButton(FALSE);
	while (1)
	{
		//65536번동안(0~65535) 마우스의 위치를 해당하는 i,i에 위치 이동
		//이떄 0.05초씩 대기
		for (i; pow((double)2, 16) - 1; i++)
		{
			SetCursorPos(i, i);
			Sleep(50);
		}
		//65536번동안 마우스 이동이 끝나면 0,0에 위치
		SetCursorPos(0, 0);
	}
	return 0;
}