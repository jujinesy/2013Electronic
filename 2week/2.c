#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str1[2001];
char str2[2001];
char temp[2001];

int main ( void )	{
	//������ �Է¹� ������ ������ ���� ����
	int i, j, k, n1, n2, oper, result;
	

	while ( 1 )	{
		//���ڷ� �ٲ� ���ڿ��� ������ temp�� NULL�� �ʱ�ȭ
		memset(temp,NULL,sizeof(NULL));

		printf("������ �Է��ϼ���.\n");
		//����ڰ� ���͸� ���������� ���ڿ��� str1�� ����
		gets ( str1 );

		for( i = 0, k =0 ; i < strlen(str1) ; i++ )
		{
			//���ڷ� �ٲ� ���ڿ��� ����
			temp[k++] = str1[i];

			if( str1[i] == '+' ) {
				//+��ȣ�� ������, +��ȣ ���� ���ڵ��� ���ڷ� ��ȯ. �׸��� temp�� �ٽû���ϱ� ���� NULL�� �ʱ�ȭ. oper�� ���Ŀ� ���� ������ ����
				n1 = atoi(temp);
				memset(temp,NULL,sizeof(temp));
				oper = 0;
				break;
			}else if( str1[i] == '-' ) {
				//-��ȣ�� ������, -��ȣ ���� ���ڵ��� ���ڷ� ��ȯ. �׸��� temp�� �ٽû���ϱ� ���� NULL�� �ʱ�ȭ. oper�� ���Ŀ� ���� ������ ����
				n1 = atoi(temp);
				memset(temp,NULL,sizeof(temp));
				oper = 1;
				break;
			}else if( str1[i] == '*' ) {
				//*��ȣ�� ������, *��ȣ ���� ���ڵ��� ���ڷ� ��ȯ. �׸��� temp�� �ٽû���ϱ� ���� NULL�� �ʱ�ȭ. oper�� ���Ŀ� ���� ������ ����
				n1 = atoi(temp);
				memset(temp,NULL,sizeof(temp));
				oper = 2;
				break;
			}else if( str1[i] == '/' ) {
				///��ȣ�� ������, /��ȣ ���� ���ڵ��� ���ڷ� ��ȯ. �׸��� temp�� �ٽû���ϱ� ���� NULL�� �ʱ�ȭ. oper�� ���Ŀ� ���� ������ ����
				n1 = atoi(temp);
				memset(temp,NULL,sizeof(temp));
				oper = 3;
				break;
			}
		}
		for( j = i+1, k =0  ; j < strlen(str1) ; j++ )
		{
			//���ڷ� �ٲ� ���ڿ��� ����
			temp[k++] = str1[j];


			//���� �����ڰ� �����ų� =�� ������ ���ݱ��� ����� ���ڿ��� ���ڷ� ����. temp�� �ٽ� ����ϱ����� NULL�� �ʱ�ȭ
			if( str1[j] == '+' || str1[j] == '-' || str1[j] == '*' || str1[j] == '/' || str1[j] == '=' ) {
				n2 = atoi(temp);
				memset(temp,NULL,sizeof(temp));
				break;
			}
		}
		// ������ ��ȣ�� =�� �ƴϸ� �ٽ� �Է¹޵��� �Ͽ���.
		if( str1[strlen(str1)-1] != '=')
			continue;
		//���� �տ��ִ� ���� ������ �ϴ� ���
		if(oper == 0){
			result = n1 + n2;
		}else if(oper == 1){
			result = n1 - n2;
		}else if(oper == 2){
			result = n1 * n2;
		}else if(oper == 3){
			result = n1 / n2;
		}

		printf("%d\n", result);
	}

	return 0;
}