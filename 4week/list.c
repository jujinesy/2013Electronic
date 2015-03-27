#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����ü�� �������� char�� ���� ����ü�� ����ų�� �ִ� ���� �߰�
// �� ����ü�̸��� node�� ����
typedef struct _node 
{ 
	char *key ; 
	struct _node *next ;
} node;
//����� ������ ����
node *head, *tail ;

//������ �ʱ�ȭ �ϴ� �Լ��� ���� ���Ͽ� ��常ŭ�� �޸𸮰����� �ο��ϰ� ����� ������ ����
//������ ������ ������ ����Ű������.
void init_stack()  
{ 
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->next = tail ;
	tail->next = tail ;
}

//�����Ͱ����� ��������
void push(char *k)   
{
	//��带 �����ϰ� �޸𸮰��� �ο���.
	node *t ;
	if ((t = (node*)malloc(sizeof(node))) == NULL)  {
		printf("\n  Out of memory ...\n");
	}
	//key�� �޸� ������ �ο����ְ� ������ k�� ����Ű�� ���� �����Ѵ�.
	t->key=(char*)malloc(sizeof(char)*strlen(k)+1);
	strcpy(t->key, k);
	//��尡 ����Ű�� �븣�� ��� ���θ��� ��忡 �ִ´�.
	t->next = head->next ;
	head->next = t;
}

//���� �����Ͱ����� ���� ������ �ش���� ������.
int pop(char **input)                                             
{
	//��� ������ ����
	node *t ;
	//������ ��������� 0�� ����
	if (head->next == tail)
		return 0;
	//����� ������带 t�� ����
	t = head->next;
	//��ó�� ����� key�� ����Ű�� ���� input�� ���� 
	strncpy(*input, t->key, strlen(t->key)+1);
	//Ű�� �޸�ȯ�������� �η� �ʱ�ȭ
	t->key=NULL;
	//t->key�� �޸� �ʱ�ȭ
	free(t->key);
	head -> next = t->next ;
	free(t) ;
	//���ÿ� ���� ������ 1����
	return 1; 
}

//input�� ����Ű�� ��ã�� ã�� ���� ����
int search(char *input)
{
	//������ ��� 2������
	node *t, *s;
	int i=1;
	//��尡����Ű�� �ؽ�Ʈ�� t������
	t= head->next;
	//������ �������������� while���� ��.
	while(t != tail)
	{
		//input���� �ش����� key���� ��ġ�ϸ�,
		if(!strcmp(t->key,input))
		{
			//i�� ������Ű�� 
			i++;
			//�ش� ��带������.
			//�̶� �ش��尡 ���� t->next�� head�� �ִ´�.
			if( head == t)
			{
				head = t->next;
			// ��尡 �ƴϸ�, �ش��� ������ �ٽð˻��Ͽ�
			// �ش��� t->next���� ������� Current->next�� ����
			} else{
				node* Current = head;
				while(Current->next != t)
					Current = Current->next;
				if(Current != NULL)
				{
					Current->next = t->next;
				}
			}
			//�ش��� �޸𸮿� ȯ����.
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
//������ �������ķ� �����Ѵ�. �̶� ���������� ������.
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
//���ÿ� ���� ������ ���������� while�������� �޸� ȯ����Ų��.
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