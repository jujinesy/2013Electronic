#include <stdio.h>
#include <stdlib.h>

//다름 노드 주소와 double형 값을 가지고있는 구조체 선언/
typedef struct _node 
{ 
	double key ; 
	struct _node *next ;
} node;

node *head, *tail ;

//헤드와 테일을 만들고 초기화해주는 함수
void init_stack()  
{ 
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	//헤더의 넥스트틑 꼬리를 가리킨다
	head->next = tail ;
	//테일의 넥스트는 자기자신 테일을 가리킨다
	tail->next = tail ;
}

//숫자가 들어왔을때 새로운 노드 t를만들고 넥스트에는 헤더의 넥스트를 저장
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

//마지막에 넣었던 숫자를꺼내오고, 저장공간을 메모리에 환원시킨다.
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

//스택을 종료할떄 테일이 나올때까지 중간 노드를 메모리에 환원시킨후
//헤더와 테일을 마지막에 메모리에 환원시킨다.
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