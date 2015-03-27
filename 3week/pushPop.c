#include <stdio.h>
#include <stdlib.h>

//�ٸ� ��� �ּҿ� double�� ���� �������ִ� ����ü ����/
typedef struct _node 
{ 
	double key ; 
	struct _node *next ;
} node;

node *head, *tail ;

//���� ������ ����� �ʱ�ȭ���ִ� �Լ�
void init_stack()  
{ 
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	//����� �ؽ�Ʈ�z ������ ����Ų��
	head->next = tail ;
	//������ �ؽ�Ʈ�� �ڱ��ڽ� ������ ����Ų��
	tail->next = tail ;
}

//���ڰ� �������� ���ο� ��� t������� �ؽ�Ʈ���� ����� �ؽ�Ʈ�� ����
void push(double k)   
{                                 
	node *t ;
	if ((t = (node*)malloc(sizeof(node))) == NULL)  {
		printf("\n  Out of memory ...\n");
	}
	t->key = k ;
	t->next = head->next ;
	head->next = t;
}

//�������� �־��� ���ڸ���������, ��������� �޸𸮿� ȯ����Ų��.
double pop()                                             
{
	node *t ;
	double i ;
	if (head->next == tail) {                
		printf("\n Stack underflow.\n") ;
		return 0.0;
	}
	t = head->next ;                                       
	i = t->key ;
	head -> next = t->next ;
	free(t) ;
	return i; 
}

//������ �����ҋ� ������ ���ö����� �߰� ��带 �޸𸮿� ȯ����Ų��
//����� ������ �������� �޸𸮿� ȯ����Ų��.
void clear_stack()  
{
	node *t, *s ;
	t = head->next ;
	while (t != tail) {
		s = t ;
		t  = t->next ;
		free(s) ;
	}
	head->next = tail ;
}