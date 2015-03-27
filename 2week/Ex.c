#include<stdio.h>
#include<stdlib.h>

#define MAXOP 100
#define NUMBER '0'

extern int getop(char []);
extern void push(double);
extern double pop(void);

int main()
{
	int type;
	double op2;
	char s[MAXOP];

	printf("1( - 2) * (4 + 5) equals to 1 2 - 4 5 + *\n");

	while( (type = getop(s)) != EOF)
	{
		switch(type)
		{
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() + pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if(op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
		case '\n' :
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error : unknown command %s\n", s);
			break;
		}
	}
	return 0;
}