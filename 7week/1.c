#include<Windows.h>
#include<math.h>
//for���� �������� ��������
int i;

int main()
{
	//���콺 ���� �����ʹ�ư �ٲ�
	SwapMouseButton(FALSE);
	while (1)
	{
		//65536������(0~65535) ���콺�� ��ġ�� �ش��ϴ� i,i�� ��ġ �̵�
		//�̋� 0.05�ʾ� ���
		for (i; pow((double)2, 16) - 1; i++)
		{
			SetCursorPos(i, i);
			Sleep(50);
		}
		//65536������ ���콺 �̵��� ������ 0,0�� ��ġ
		SetCursorPos(0, 0);
	}
	return 0;
}