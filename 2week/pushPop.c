#include <stdio.h>

#define MAXUAL 100

int sp = 0;
double val[100];

void push(double f)
{
	if(sp<MAXUAL)
		val[sp++] = f;
	else
		printf("error : stack full, can`t push %d\n", f);
}

double pop(void)
{
	if(sp > 0 )
		return val[--sp];
	else
	{
		printf("error : stack empty\n");
		return 0.0;
	}
}