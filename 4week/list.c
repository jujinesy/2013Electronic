#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//구조체에 포인터형 char와 다음 구조체를 가르킬수 있는 변수 추가
// 또 구조체이름을 node로 정의
typedef struct _node 
{ 
	char *key ; 
	struct _node *next ;
} node;
//헤더와 테일을 선언
node *head, *tail ;

//스택을 초기화 하는 함수로 헤드와 테일에 노드만큼의 메모리공간을 부여하고 헤드의 다음은 테일
//테일의 다음은 테일을 가르키도록함.
void init_stack()  
{ 
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->next = tail ;
	tail->next = tail ;
}

//포인터값으로 변수저장
void push(char *k)   
{
	//노드를 선언하고 메모리공간 부여함.
	node *t ;
	if ((t = (node*)malloc(sizeof(node))) == NULL)  {
		printf("\n  Out of memory ...\n");
	}
	//key에 메모리 공간을 부여해주고 포인터 k가 가르키는 값을 저장한다.
	t->key=(char*)malloc(sizeof(char)*strlen(k)+1);
	strcpy(t->key, k);
	//헤드가 가르키는 노르를 방금 새로만든 노드에 넣는다.
	t->next = head->next ;
	head->next = t;
}

//이중 포인터값으로 값을 뺴내고 해당노드는 삭제함.
int pop(char **input)                                             
{
	//노드 포인터 생성
	node *t ;
	//스택이 비어있으면 0을 리턴
	if (head->next == tail)
		return 0;
	//헤드의 다음노드를 t로 설정
	t = head->next;
	//맨처음 노드의 key가 가르키는 값을 input로 복사 
	strncpy(*input, t->key, strlen(t->key)+1);
	//키를 메모리환원을위해 널로 초기화
	t->key=NULL;
	//t->key를 메모리 초기화
	free(t->key);
	head -> next = t->next ;
	free(t) ;
	//스택에 값이 있으면 1리턴
	return 1; 
}

//input이 가르키는 값찾고 찾은 값을 리턴
int search(char *input)
{
	//포인터 노드 2개선언
	node *t, *s;
	int i=1;
	//헤드가가르키는 넥스트를 t에저장
	t= head->next;
	//스택의 끝을만날때까지 while문을 돔.
	while(t != tail)
	{
		//input값과 해당노드의 key값이 일치하면,
		if(!strcmp(t->key,input))
		{
			//i를 증가시키고 
			i++;
			//해당 노드를삭제함.
			//이때 해당노드가 헤드면 t->next를 head에 넣는다.
			if( head == t)
			{
				head = t->next;
			// 헤드가 아니면, 해당노드 전까지 다시검색하여
			// 해당노드 t->next값을 이전노드 Current->next에 저장
			} else{
				node* Current = head;
				while(Current->next != t)
					Current = Current->next;
				if(Current != NULL)
				{
					Current->next = t->next;
				}
			}
			//해당노드 메모리에 환원함.
			s = t ;
			t  = t->next ;
			free(s) ;
		} else
		{
			t  = t->next;
		}		
	}
	return i;
}
//스택을 버블정렬로 정렬한다. 이때 사전식으로 정렬함.
void sort()
{
	node *i, *j;
	char *temp=(char*)malloc(sizeof(char));
	for( i = head->next ; i != tail ; i=i->next )
	{
		for( j = i->next ; j != tail ;  j=j->next )
		{
			if( strcmp(i->key, j->key) > 0 )
			{
				temp = i->key;
				i->key = j->key;
				j->key = temp;
			}
		}
	}
}
//스택에 헤드와 테일이 있을때까지 while문을돌아 메모리 환원시킨다.
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