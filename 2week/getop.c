#include<stdio.h>
#include<ctype.h>

#define NUMBER '0'

extern int getch(void);
extern void ungetch(int);

int getop(char s[])
{
	int i, c;
	//°ÙÃ÷

	while((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = NULL;
	if(!isdigit(c) && c != '.')
		return c;
	i = 0;

	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()));

	if(c == '.')
		while(isdigit(s[++i] = c = getch()));

	s[i] = NULL;
	if(c !=EOF)
		ungetch(c);

	return NUMBER;
}